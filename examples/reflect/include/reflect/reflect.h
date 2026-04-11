#ifndef CONSTEXPRCORE_REFLECT_H
#define CONSTEXPRCORE_REFLECT_H

#include <ConstexprCore/perfect_hash.h>
#include <array>
#include <iostream>
#if __has_include(<meta>)
#include <meta>
#else
#include <experimental/meta>
#endif
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

// Count nonstatic data members of T.
template <typename T>
consteval std::size_t field_count() {
    return std::meta::nonstatic_data_members_of(^T).size();
}

// Get the i-th nonstatic data member reflection.
template <typename T>
consteval std::meta::info field_at(std::size_t i) {
    return std::meta::nonstatic_data_members_of(^T)[i];
}

// Build array of field names.
template <typename T, std::size_t N>
consteval auto compute_names() {
    auto members = std::meta::nonstatic_data_members_of(^T);
    std::array<std::string_view, N> result{};
    for (std::size_t i = 0; i < N; ++i)
        result[i] = std::meta::identifier_of(members[i]);
    return result;
}

// Compute PHF data from reflected field names.
template <typename T, std::size_t N>
consteval auto compute_field_phf() {
    auto names = compute_names<T, N>();
    return ConstexprCore::detail::compute_phf<N>(names);
}

template <typename T, std::size_t N>
consteval std::size_t max_field_name_len() {
    auto names = compute_names<T, N>();
    std::size_t m = 1;
    for (auto& n : names) if (n.size() > m) m = n.size();
    return m;
}

// Per-type metadata: field names + perfect hash set.
template <typename T>
struct type_meta {
    static constexpr std::size_t N = field_count<T>();
    static constexpr auto names = compute_names<T, N>();
    static constexpr auto phf = compute_field_phf<T, N>();
    static constexpr std::size_t TS = phf.table_size;
    static constexpr std::size_t MKL = max_field_name_len<T, N>();
    static constexpr auto set =
        ConstexprCore::make_perfect_set_from_phf<N, TS, MKL>(names, phf);
};

// Build field_value type from reflected member types.
template <typename T>
consteval std::meta::info make_field_value_type() {
    auto members = std::meta::nonstatic_data_members_of(^T);
    std::vector<std::meta::info> types;
    for (auto m : members)
        types.push_back(std::meta::type_of(m));
    return std::meta::substitute(^field_value, types);
}

template <typename T>
using field_value_t = [:make_field_value_type<T>():];

// Fold-expression dispatch: runtime index → compile-time field splice.
template <typename T, typename F, std::size_t... Is>
void dispatch_const(const T& obj, std::size_t idx, F&& f,
                    std::index_sequence<Is...>) {
    (([&]() -> bool {
        if (idx == Is) {
            constexpr auto mem = field_at<T>(Is);
            f(obj.[:mem:]);
            return true;
        }
        return false;
    }()) || ...);
}

template <typename T, typename F, std::size_t... Is>
void dispatch_mut(T& obj, std::size_t idx, F&& f,
                  std::index_sequence<Is...>) {
    (([&]() -> bool {
        if (idx == Is) {
            constexpr auto mem = field_at<T>(Is);
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
auto reflect_get(const T& obj, std::string_view field_name) -> detail::field_value_t<T> {
    using Meta = detail::type_meta<T>;
    using V = detail::field_value_t<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error("Unknown field: " + std::string(field_name));

    // Use index-based variant construction to handle duplicate types correctly.
    V result;
    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        (([&]() -> bool {
            if (*idx == Is) {
                constexpr auto mem = detail::field_at<T>(Is);
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

    detail::dispatch_mut(obj, *idx, [&](auto& field) {
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
    detail::dispatch_const(obj, *idx, std::forward<F>(visitor),
                           std::make_index_sequence<Meta::N>{});
}

template <typename T, typename F>
void reflect_visit(T& obj, std::string_view field_name, F&& visitor) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error("Unknown field: " + std::string(field_name));
    detail::dispatch_mut(obj, *idx, std::forward<F>(visitor),
                         std::make_index_sequence<Meta::N>{});
}

template <typename T, typename F>
void reflect_for_each(const T& obj, F&& visitor) {
    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        ((visitor(detail::type_meta<T>::names[Is],
                  obj.[:detail::field_at<T>(Is):])), ...);
    }(std::make_index_sequence<detail::type_meta<T>::N>{});
}

template <typename T, typename F>
void reflect_for_each(T& obj, F&& visitor) {
    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        ((visitor(detail::type_meta<T>::names[Is],
                  obj.[:detail::field_at<T>(Is):])), ...);
    }(std::make_index_sequence<detail::type_meta<T>::N>{});
}

template <typename T>
bool reflect_has(std::string_view field_name) {
    return detail::type_meta<T>::set.contains(field_name);
}

} // namespace ConstexprCore::reflect

#endif // CONSTEXPRCORE_REFLECT_H
