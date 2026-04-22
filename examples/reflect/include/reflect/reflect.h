#ifndef CONSTEXPRCORE_REFLECT_H
#define CONSTEXPRCORE_REFLECT_H

#include <version>

// technically, we should rely on version and __cpp_reflection
#define CONSTEXPRCORE_HAS_REFLECTION 1

#ifndef CONSTEXPRCORE_HAS_REFLECTION
#if defined(__cpp_reflection) && __cpp_reflection >= 201902L
#define CONSTEXPRCORE_HAS_REFLECTION 1
#endif 
#endif // CONSTEXPRCORE_HAS_REFLECTION

#if CONSTEXPRCORE_HAS_REFLECTION
#if __has_include(<meta>)
#include <meta>
#else
#include <experimental/meta>
#endif

// ── Compiler compatibility ──────────────────────────────────────────────────
//
// The P2996 standard (R13, adopted into C++26) specifies:
//   - ^^T as the reflection operator
//   - nonstatic_data_members_of(^^T, access_context) with mandatory access_context
//   - access_context::current() captures the caller's access rights
//
// The two current implementations diverge:
//
//   GCC 16 trunk: matches R13 — ^^T, requires access_context::current().
//                 Only public members are accessible from outside the class.
//
//   Bloomberg Clang (P2996 fork, based on an earlier revision):
//                 Uses ^T (single caret) and nonstatic_data_members_of(^T)
//                 without access_context. More permissive — returns all
//                 members regardless of access. Will converge to ^^ once
//                 Bloomberg updates to the final P2996 revision.
//
#if defined(__GNUC__) && !defined(__clang__)
#define CONSTEXPRCORE_REFLECT_OF(T) (^^T)
#define CONSTEXPRCORE_NSDM_OF(T)    std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::current())
#else
#define CONSTEXPRCORE_REFLECT_OF(T) (^T)
#define CONSTEXPRCORE_NSDM_OF(T)    std::meta::nonstatic_data_members_of(^T)
#endif

#include <ConstexprCore/perfect_hash.h>
#include <array>
#include <iosfwd>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <type_traits>
#include <utility>
#include <variant>

namespace ConstexprCore::reflect {

// ============================================================================
// field_value — ergonomic wrapper around std::variant for reflected field values.
// Supports direct printing (std::cout << val) and typed extraction (val.as<T>()).
// ============================================================================

template <typename... Ts>
struct field_value {
    using variant_type = std::variant<Ts...>;
    variant_type data;

    // Printing: std::cout << reflect_get(obj, "name");
    // Defined inline as a hidden friend (found only via ADL).
    friend auto& operator<<(auto& os, const field_value& fv) {
        std::visit([&](const auto& v) { os << v; }, fv.data);
        return os;
    }

    // Type-based extraction. Only safe when no two fields share a type.
    // Prefer get<I>() (index-based) when the struct has duplicate field types.
    template <typename U>
    const U& as() const { return std::get<U>(data); }

    template <typename U>
    U& as() { return std::get<U>(data); }

    // Index-based extraction (always safe, works with duplicate types).
    template <std::size_t I>
    const auto& get() const { return std::get<I>(data); }

    template <std::size_t I>
    auto& get() { return std::get<I>(data); }

    friend bool operator==(const field_value&, const field_value&) = default;
};

// ============================================================================
// detail
// ============================================================================

namespace detail {

// nonstatic_data_members_of is called twice per type:
//   1. field_count<T>() — to discover N (needed as a template parameter)
//   2. cache_members<T, N>() — to store the member infos in a fixed-size array
// This is unavoidable: N must be a compile-time constant before std::array<info, N>
// can be instantiated, but N itself comes from reflecting T. After these two calls,
// all other operations (name extraction, PHF construction, dispatch) derive from
// the cached array with zero additional reflection calls.

template <typename T>
consteval std::size_t field_count() {
    return CONSTEXPRCORE_NSDM_OF(T).size();
}

template <typename T, std::size_t N>
consteval auto cache_members() {
    auto vec = CONSTEXPRCORE_NSDM_OF(T);
    std::array<std::meta::info, N> result{};
    for (std::size_t i = 0; i < N; ++i)
        result[i] = vec[i];
    return result;
}

// Derive field names from the cached member array (no additional reflection call).
template <std::size_t N>
consteval auto extract_names(const std::array<std::meta::info, N>& members) {
    std::array<std::string_view, N> result{};
    for (std::size_t i = 0; i < N; ++i)
        result[i] = std::meta::identifier_of(members[i]);
    return result;
}

template <std::size_t N>
consteval std::size_t max_name_len(const std::array<std::string_view, N>& names) {
    std::size_t m = 1;
    for (auto& n : names) if (n.size() > m) m = n.size();
    return m;
}

// Per-type reflection metadata. After the two bootstrap calls (field_count + cache_members),
// everything else derives from the cached members_ array with no further reflection calls.
template <typename T>
struct type_meta {
    static constexpr std::size_t N = field_count<T>();
    static constexpr auto members_ = cache_members<T, N>();
    static constexpr auto names = extract_names(members_);
    static constexpr auto phf = ConstexprCore::compute_phf(names);
    static constexpr std::size_t TS = phf.table_size;
    static constexpr std::size_t MKL = max_name_len(names);
    static constexpr auto set =
        ConstexprCore::make_perfect_set_from_phf<N, TS, MKL>(names, phf);
};

// Build field_value type from cached member types (no extra reflection call).
template <typename T>
consteval std::meta::info make_field_value_type() {
    constexpr auto& members = type_meta<T>::members_;
    std::vector<std::meta::info> types;
    for (auto m : members)
        types.push_back(std::meta::type_of(m));
    return std::meta::substitute(CONSTEXPRCORE_REFLECT_OF(field_value), types);
}

template <typename T>
using field_value_t = [:make_field_value_type<T>():];

// Fold-expression dispatch: runtime index → compile-time field splice.
// Uses cached members_ to avoid per-index reflection calls.
template <typename T, typename F, std::size_t... Is>
void dispatch(auto&& obj, std::size_t idx, F&& f,
              std::index_sequence<Is...>) {
    (([&]() -> bool {
        if (idx == Is) {
            constexpr auto mem = type_meta<T>::members_[Is];
            f(obj.[:mem:]);
            return true;
        }
        return false;
    }()) || ...);
}

// Recursive value-producing dispatch: returns V directly from the matched
// branch so NRVO can construct the result in the caller's storage. Avoids
// the std::optional<V> + std::move round-trip that a fold expression would
// require (each std::optional operation adds a variant move + destruction,
// doubling the cost when V contains types with non-trivial destructors like
// std::string).
[[noreturn, gnu::cold, gnu::noinline]]
inline void throw_unknown_field(std::string_view name) {
    throw std::runtime_error("Unknown field: " + std::string(name));
}

// Count fields whose type equals U. Consumed by get_attribute<U>(obj)
// to diagnose "no match" vs "ambiguous" at compile time.
template <typename T, typename U>
consteval std::size_t count_type_matches() {
    constexpr auto& members = type_meta<T>::members_;
    std::size_t count = 0;
    for (std::size_t i = 0; i < type_meta<T>::N; ++i)
        if (std::meta::type_of(members[i]) == CONSTEXPRCORE_REFLECT_OF(U)) ++count;
    return count;
}

// Precondition: count_type_matches<T, U>() == 1.
template <typename T, typename U>
consteval std::size_t find_unique_type_index() {
    constexpr auto& members = type_meta<T>::members_;
    for (std::size_t i = 0; i < type_meta<T>::N; ++i)
        if (std::meta::type_of(members[i]) == CONSTEXPRCORE_REFLECT_OF(U)) return i;
    return type_meta<T>::N;
}

// Indices into type_meta<T>::members_ for fields whose type is U, in source order.
template <typename T, typename U>
consteval auto u_field_indices() {
    constexpr std::size_t K = count_type_matches<T, U>();
    std::array<std::size_t, K> result{};
    std::size_t j = 0;
    for (std::size_t i = 0; i < type_meta<T>::N; ++i) {
        if (std::meta::type_of(type_meta<T>::members_[i]) == CONSTEXPRCORE_REFLECT_OF(U)) {
            result[j++] = i;
        }
    }
    return result;
}

template <typename T, typename U, std::size_t... Js>
consteval auto u_names_impl(std::index_sequence<Js...>) {
    constexpr auto indices = u_field_indices<T, U>();
    return std::array<std::string_view, sizeof...(Js)>{
        type_meta<T>::names[indices[Js]]...
    };
}

template <typename T, typename U, std::size_t... Js>
consteval auto u_ptrs_impl(std::index_sequence<Js...>) {
    constexpr auto indices = u_field_indices<T, U>();
    return std::array<U T::*, sizeof...(Js)>{
        (&[:type_meta<T>::members_[indices[Js]]:])...
    };
}

// Per-(T, U) metadata: PHF over the names of U-typed fields of T, plus a
// pointer-to-member table in matching order. Turns runtime dispatch into
// one indexed load + one indirect member access — no branch chain.
template <typename T, typename U>
struct u_meta {
    static constexpr std::size_t K = count_type_matches<T, U>();
    static constexpr auto names = u_names_impl<T, U>(std::make_index_sequence<K>{});
    static constexpr auto phf   = ConstexprCore::compute_phf(names);
    static constexpr std::size_t TS  = phf.table_size;
    static constexpr std::size_t MKL = max_name_len(names);
    static constexpr auto set =
        ConstexprCore::make_perfect_set_from_phf<K, TS, MKL>(names, phf);
    static constexpr auto ptrs =
        u_ptrs_impl<T, U>(std::make_index_sequence<K>{});
};

template <typename T, typename V, std::size_t I>
V get_value(const T& obj, std::size_t idx) {
    using Meta = type_meta<T>;
    if constexpr (I >= Meta::N) {
        // Unreachable: idx is always < N because index_of validated it.
        __builtin_unreachable();
    } else {
        constexpr auto mem = Meta::members_[I];
        if (idx == I) {
            return V{typename V::variant_type(std::in_place_index<I>, obj.[:mem:])};
        }
        return get_value<T, V, I + 1>(obj, idx);
    }
}

} // namespace detail

// ============================================================================
// Public API
//
// Future extension: a tag_invoke-style customization point (as used in
// simdjson's reflection-based deserialization) could allow users to override
// reflect_get/reflect_set for types that need custom construction or
// conversion logic. For now, the automatic reflection path handles all
// aggregate types with public fields.
// ============================================================================

template <typename T>
constexpr auto reflect_keys() {
    return detail::type_meta<T>::names;
}

template <typename T>
constexpr std::size_t reflect_size() {
    return detail::type_meta<T>::N;
}

template <typename T>
auto reflect_get(const T& obj, std::string_view field_name) {
    using Meta = detail::type_meta<T>;
    using V = detail::field_value_t<T>;
    auto idx = Meta::set.index_of(field_name);
    if  (idx) [[likely]]   {
        return detail::get_value<T, V, 0>(obj, *idx);
    }
    detail::throw_unknown_field(field_name);
}

template <typename T, typename V>
void reflect_set(T& obj, std::string_view field_name, V&& value) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error("Unknown field: " + std::string(field_name));

    detail::dispatch<T>(obj, *idx, [&](auto& field) {
        using FieldType = std::remove_reference_t<decltype(field)>;
        if constexpr (std::is_assignable_v<FieldType&, V&&>)
            field = std::forward<V>(value);
        else
            throw std::runtime_error("Type mismatch for field: " + std::string(field_name));
    }, std::make_index_sequence<Meta::N>{});
}

template <typename T, typename F>
void reflect_visit(const T& obj, std::string_view field_name, F&& visitor) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error("Unknown field: " + std::string(field_name));
    detail::dispatch<T>(obj, *idx, std::forward<F>(visitor),
                        std::make_index_sequence<Meta::N>{});
}

template <typename T, typename F>
void reflect_visit(T& obj, std::string_view field_name, F&& visitor) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error("Unknown field: " + std::string(field_name));
    detail::dispatch<T>(obj, *idx, std::forward<F>(visitor),
                        std::make_index_sequence<Meta::N>{});
}

template <typename T, typename F>
void reflect_for_each(const T& obj, F&& visitor) {
    using Meta = detail::type_meta<T>;
    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        ((visitor(Meta::names[Is], obj.[:Meta::members_[Is]:])), ...);
    }(std::make_index_sequence<Meta::N>{});
}

template <typename T, typename F>
void reflect_for_each(T& obj, F&& visitor) {
    using Meta = detail::type_meta<T>;
    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        ((visitor(Meta::names[Is], obj.[:Meta::members_[Is]:])), ...);
    }(std::make_index_sequence<Meta::N>{});
}

template <typename T>
bool reflect_has(std::string_view field_name) {
    return detail::type_meta<T>::set.contains(field_name);
}


// Name-based typed field access. Dispatch is a PHF over only the U-typed
// fields of T, followed by a single indexed pointer-to-member load — no
// branch chain, no mispredict penalty on random keys. Throws if the name
// is unknown in T or names a field of a different type (both cases look
// the same to the U-subset PHF). Ill-formed at compile time if T has no
// field of type U at all.
template <typename U, typename T>
constexprcore_really_inline U& get_attribute(T& obj, std::string_view field_name) {
    static_assert(detail::count_type_matches<T, U>() > 0,
                  "get_attribute: T has no field of this type");
    using UM = detail::u_meta<T, U>;
    auto idx = UM::set.index_of(field_name);
    if (idx) [[likely]] {
        return obj.*UM::ptrs[*idx];
    }
    detail::throw_unknown_field(field_name);
}

template <typename U, typename T>
constexprcore_really_inline const U& get_attribute(const T& obj, std::string_view field_name) {
    static_assert(detail::count_type_matches<T, U>() > 0,
                  "get_attribute: T has no field of this type");
    using UM = detail::u_meta<T, U>;
    auto idx = UM::set.index_of(field_name);
    if (idx) [[likely]] {
        return obj.*UM::ptrs[*idx];
    }
    detail::throw_unknown_field(field_name);
}

} // namespace ConstexprCore::reflect

#endif // CONSTEXPRCORE_HAS_REFLECTION

#endif // CONSTEXPRCORE_REFLECT_H
