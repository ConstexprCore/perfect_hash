#ifndef CONSTEXPRCORE_REFLECT_H
#define CONSTEXPRCORE_REFLECT_H

// C++26 reflection guard: skip this header entirely if the compiler
// doesn't support reflection, so including it is a no-op rather than
// a hard compile error.
#if __has_include(<meta>)
#include <meta>
#define CONSTEXPRCORE_HAS_REFLECTION 1
#elif __has_include(<experimental/meta>)
#include <experimental/meta>
#define CONSTEXPRCORE_HAS_REFLECTION 1
#else
#define CONSTEXPRCORE_HAS_REFLECTION 0
#endif

#if CONSTEXPRCORE_HAS_REFLECTION

// ── Compiler compatibility ──────────────────────────────────────────────────
// Bloomberg Clang P2996 fork: ^T (single caret), no access_context arg
// GCC 16 trunk (P2996):       ^^T (double caret), requires access_context::current()
#if defined(__GNUC__) && !defined(__clang__)
// GCC trunk
#define CONSTEXPRCORE_REFLECT_OF(T) (^^T)
#define CONSTEXPRCORE_NSDM_OF(T)    std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::current())
#else
// Bloomberg Clang P2996 fork
#define CONSTEXPRCORE_REFLECT_OF(T) (^T)
#define CONSTEXPRCORE_NSDM_OF(T)    std::meta::nonstatic_data_members_of(^T)
#endif

#include <ConstexprCore/perfect_hash.h>
#include <array>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <variant>

namespace ConstexprCore::reflect {

// ============================================================================
// field_value — ergonomic wrapper around std::variant for reflected field values.
// Supports direct printing (std::cout << val) and typed extraction (val.as<T>()).
// ============================================================================

template <typename... Ts>
struct field_value {
    std::variant<Ts...> data;

    friend std::ostream& operator<<(std::ostream& os, const field_value& fv) {
        std::visit([&](const auto& v) { os << v; }, fv.data);
        return os;
    }

    template <typename U>
    const U& as() const { return std::get<U>(data); }

    template <typename U>
    U& as() { return std::get<U>(data); }

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

// Enumerate members exactly once per type. All other helpers derive from this.
template <typename T>
consteval std::size_t field_count() {
    return CONSTEXPRCORE_NSDM_OF(T).size();
}

// Cached member list: called once per type, result stored in type_meta::members_.
// All index-based access goes through this cached array instead of re-calling
// nonstatic_data_members_of.
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

// Per-type reflection metadata. nonstatic_data_members_of is called exactly once
// (in cache_members); everything else derives from the cached array.
template <typename T>
struct type_meta {
    static constexpr std::size_t N = field_count<T>();
    static constexpr auto members_ = cache_members<T, N>();
    static constexpr auto names = extract_names(members_);
    static constexpr auto phf = ConstexprCore::detail::compute_phf<N>(names);
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

} // namespace detail

// ============================================================================
// Public API
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
    if (!idx) throw std::runtime_error("Unknown field: " + std::string(field_name));

    // Use index-based variant emplace to handle duplicate field types correctly.
    V result;
    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        (([&]() -> bool {
            if (*idx == Is) {
                constexpr auto mem = Meta::members_[Is];
                result.data.template emplace<Is>(obj.[:mem:]);
                return true;
            }
            return false;
        }()) || ...);
    }(std::make_index_sequence<Meta::N>{});
    return result;
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

} // namespace ConstexprCore::reflect

#endif // CONSTEXPRCORE_HAS_REFLECTION

#endif // CONSTEXPRCORE_REFLECT_H
