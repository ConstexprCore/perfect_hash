#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <reflect/reflect.h>
#include <string>

using namespace ConstexprCore::reflect;

// === Test structs ===

struct Simple {
    int x;
};

struct Person {
    std::string name;
    int age;
    double height;
};

struct AllSameType {
    int a;
    int b;
    int c;
};

struct ManyFields {
    int f1; int f2; int f3; int f4; int f5;
    int f6; int f7; int f8; int f9; int f10;
};

// === Tests ===

TEST_CASE("reflect_keys returns field names in declaration order") {
    constexpr auto keys = reflect_keys<Person>();
    REQUIRE(keys.size() == 3);
    CHECK(keys[0] == "name");
    CHECK(keys[1] == "age");
    CHECK(keys[2] == "height");
}

TEST_CASE("reflect_size returns number of fields") {
    CHECK(reflect_size<Simple>() == 1);
    CHECK(reflect_size<Person>() == 3);
    CHECK(reflect_size<ManyFields>() == 10);
}

TEST_CASE("reflect_get returns correct values") {
    Person p{"Alice", 30, 1.70};

    auto name = reflect_get(p, "name");
    CHECK(name.as<std::string>() == "Alice");

    auto age = reflect_get(p, "age");
    CHECK(age.as<int>() == 30);

    auto height = reflect_get(p, "height");
    CHECK(height.as<double>() == doctest::Approx(1.70));
}

TEST_CASE("reflect_get is printable") {
    Person p{"Bob", 42, 1.85};
    std::ostringstream os;
    os << reflect_get(p, "name");
    CHECK(os.str() == "Bob");
}

TEST_CASE("reflect_get throws on unknown field") {
    Person p{"Bob", 42, 1.85};
    CHECK_THROWS_AS(reflect_get(p, "email"), std::runtime_error);
    CHECK_THROWS_AS(reflect_get(p, ""), std::runtime_error);
}

TEST_CASE("reflect_set modifies the field") {
    Person p{"Bob", 42, 1.85};

    reflect_set(p, "age", 43);
    CHECK(p.age == 43);

    reflect_set(p, "name", std::string("Alice"));
    CHECK(p.name == "Alice");

    reflect_set(p, "height", 1.90);
    CHECK(p.height == doctest::Approx(1.90));
}

TEST_CASE("reflect_set throws on unknown field") {
    Person p{"Bob", 42, 1.85};
    CHECK_THROWS_AS(reflect_set(p, "email", 0), std::runtime_error);
}

TEST_CASE("reflect_visit calls visitor with correct value") {
    Person p{"Bob", 42, 1.85};

    int captured_age = 0;
    reflect_visit(p, "age", [&](const auto& val) {
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(val)>, int>)
            captured_age = val;
    });
    CHECK(captured_age == 42);
}

TEST_CASE("reflect_visit throws on unknown field") {
    Person p{"Bob", 42, 1.85};
    CHECK_THROWS_AS(
        reflect_visit(p, "unknown", [](const auto&) {}),
        std::runtime_error
    );
}

TEST_CASE("reflect_for_each iterates all fields") {
    Person p{"Bob", 42, 1.85};

    std::vector<std::string> names;
    reflect_for_each(p, [&](std::string_view name, const auto&) {
        names.emplace_back(name);
    });

    REQUIRE(names.size() == 3);
    CHECK(names[0] == "name");
    CHECK(names[1] == "age");
    CHECK(names[2] == "height");
}

TEST_CASE("reflect_has checks field existence") {
    CHECK(reflect_has<Person>("name") == true);
    CHECK(reflect_has<Person>("age") == true);
    CHECK(reflect_has<Person>("email") == false);
    CHECK(reflect_has<Person>("") == false);
}

TEST_CASE("single-field struct") {
    Simple s{99};
    CHECK(reflect_get(s, "x").as<int>() == 99);
    reflect_set(s, "x", 100);
    CHECK(s.x == 100);
}

TEST_CASE("all-same-type struct") {
    AllSameType obj{1, 2, 3};
    // With duplicate types in variant, use index-based access
    auto val_a = reflect_get(obj, "a");
    auto val_c = reflect_get(obj, "c");
    CHECK(val_a.get<0>() == 1);
    CHECK(val_c.get<2>() == 3);
}

TEST_CASE("many fields struct") {
    ManyFields m{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // All fields are int, so use index-based get<I>() not type-based as<int>()
    CHECK(reflect_get(m, "f1").get<0>() == 10);
    CHECK(reflect_get(m, "f10").get<9>() == 100);
    CHECK(reflect_size<ManyFields>() == 10);
}

TEST_CASE("mutable reflect_for_each") {
    Person p{"Bob", 42, 1.85};
    reflect_for_each(p, [](std::string_view name, auto& val) {
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(val)>, int>)
            val = 0;
    });
    CHECK(p.age == 0);
}
