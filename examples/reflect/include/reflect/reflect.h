#ifndef CONSTEXPRCORE_REFLECT_H
#define CONSTEXPRCORE_REFLECT_H

#include <ConstexprCore/perfect_hash.h>
#include <array>
#include <iostream>
#include <meta>
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

    // Index-based access (useful when multiple fields share a type)
    template <std::size_t I>
    const auto& get() const { return std::get<I>(data); }

    template <std::size_t I>
    auto& get() { return std::get<I>(data); }

    friend bool operator==(const field_value&, const field_value&) = default;
};

// ============================================================================
// detail — compile-time metadata per struct type
// ============================================================================

namespace detail {

// Per-type reflection metadata. Computed once at compile time via constexpr statics.
// Builds a perfect_hash_set from reflected field names for O(1) runtime lookup.
template <typename T>
struct type_meta {
    static constexpr auto members = std::meta::nonstatic_data_members_of(^^T);
    static constexpr std::size_t N = members.size();

    static consteval auto compute_names() {
        std::array<std::string_view, N> result{};
        for (std::size_t i = 0; i < N; ++i)
            result[i] = std::meta::identifier_of(members[i]);
        return result;
    }

    static constexpr auto names = compute_names();
    static constexpr auto set = ConstexprCore::make_perfect_set_from_array(names);
};

// Build field_value_t<T>: a field_value<Type0, Type1, ...> from reflected member types.
template <typename T>
consteval auto make_field_value_type() {
    return std::meta::substitute(
        ^^field_value,
        []<std::size_t... Is>(std::index_sequence<Is...>) {
            return std::vector<std::meta::info>{
                std::meta::type_of(type_meta<T>::members[Is])...
            };
        }(std::make_index_sequence<type_meta<T>::N>{})
    );
}

template <typename T>
using field_value_t = [:make_field_value_type<T>():];

// Fold-expression dispatch: maps runtime index to compile-time field splice.
// Short-circuit || ensures only one branch executes.
template <typename T, typename F, std::size_t... Is>
decltype(auto) dispatch_visit(const T& obj, std::size_t idx, F&& f,
                               std::index_sequence<Is...>) {
    constexpr auto members = std::meta::nonstatic_data_members_of(^^T);
    bool found = false;
    (([&]() -> bool {
        if (idx == Is) {
            f(obj.[:members[Is]:]);
            found = true;
            return true;
        }
        return false;
    }()) || ...);
    if (!found) throw std::runtime_error("Field index out of range");
}

// Mutable dispatch variant.
template <typename T, typename F, std::size_t... Is>
decltype(auto) dispatch_visit_mut(T& obj, std::size_t idx, F&& f,
                                   std::index_sequence<Is...>) {
    constexpr auto members = std::meta::nonstatic_data_members_of(^^T);
    bool found = false;
    (([&]() -> bool {
        if (idx == Is) {
            f(obj.[:members[Is]:]);
            found = true;
            return true;
        }
        return false;
    }()) || ...);
    if (!found) throw std::runtime_error("Field index out of range");
}

// Build getter table for reflect_get (returns field_value_t<T>).
template <typename T, std::size_t... Is>
constexpr auto make_getter_table(std::index_sequence<Is...>) {
    constexpr auto members = std::meta::nonstatic_data_members_of(^^T);
    using V = field_value_t<T>;
    using fn_t = V(*)(const T&);
    return std::array<fn_t, sizeof...(Is)>{
        +[](const T& o) -> V {
            return V{std::variant_alternative_t<Is, typename V::variant_type>{o.[:members[Is]:]}};
        }...
    };
}

} // namespace detail

// ============================================================================
// Public API
// ============================================================================

// Returns field names in declaration order.
template <typename T>
constexpr auto reflect_keys() {
    return detail::type_meta<T>::names;
}

// Returns the number of fields.
template <typename T>
constexpr std::size_t reflect_size() {
    return detail::type_meta<T>::N;
}

// Get field by name. Returns field_value<FieldTypes...> (printable, type-safe).
// Throws std::runtime_error if field_name is not found.
template <typename T>
auto reflect_get(const T& obj, std::string_view field_name) -> detail::field_value_t<T> {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error(
        "Unknown field: " + std::string(field_name));

    detail::field_value_t<T> result;
    detail::dispatch_visit(obj, *idx, [&](const auto& val) {
        result.data = val;
    }, std::make_index_sequence<Meta::N>{});
    return result;
}

// Set field by name. Value must be convertible to the field's type.
// Throws std::runtime_error if field_name is not found.
template <typename T, typename V>
void reflect_set(T& obj, std::string_view field_name, V&& value) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error(
        "Unknown field: " + std::string(field_name));

    detail::dispatch_visit_mut(obj, *idx, [&](auto& field) {
        using FieldType = std::remove_reference_t<decltype(field)>;
        if constexpr (std::is_assignable_v<FieldType&, V&&>)
            field = std::forward<V>(value);
        else
            throw std::runtime_error("Type mismatch for field: " + std::string(field_name));
    }, std::make_index_sequence<Meta::N>{});
}

// Visit a single field by name with a generic callable (zero overhead).
// Throws std::runtime_error if field_name is not found.
template <typename T, typename F>
void reflect_visit(const T& obj, std::string_view field_name, F&& visitor) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error(
        "Unknown field: " + std::string(field_name));

    detail::dispatch_visit(obj, *idx, std::forward<F>(visitor),
                           std::make_index_sequence<Meta::N>{});
}

// Mutable visit.
template <typename T, typename F>
void reflect_visit(T& obj, std::string_view field_name, F&& visitor) {
    using Meta = detail::type_meta<T>;
    auto idx = Meta::set.index_of(field_name);
    if (!idx) throw std::runtime_error(
        "Unknown field: " + std::string(field_name));

    detail::dispatch_visit_mut(obj, *idx, std::forward<F>(visitor),
                               std::make_index_sequence<Meta::N>{});
}

// Iterate all fields. Visitor receives (std::string_view name, const auto& value).
template <typename T, typename F>
void reflect_for_each(const T& obj, F&& visitor) {
    constexpr auto members = std::meta::nonstatic_data_members_of(^^T);
    constexpr auto names = detail::type_meta<T>::names;

    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        (visitor(names[Is], obj.[:members[Is]:]), ...);
    }(std::make_index_sequence<detail::type_meta<T>::N>{});
}

// Mutable for_each.
template <typename T, typename F>
void reflect_for_each(T& obj, F&& visitor) {
    constexpr auto members = std::meta::nonstatic_data_members_of(^^T);
    constexpr auto names = detail::type_meta<T>::names;

    [&]<std::size_t... Is>(std::index_sequence<Is...>) {
        (visitor(names[Is], obj.[:members[Is]:]), ...);
    }(std::make_index_sequence<detail::type_meta<T>::N>{});
}

// Check if a struct has a field with the given name (O(1) via perfect hash).
template <typename T>
bool reflect_has(std::string_view field_name) {
    return detail::type_meta<T>::set.contains(field_name);
}

} // namespace ConstexprCore::reflect

#endif // CONSTEXPRCORE_REFLECT_H
