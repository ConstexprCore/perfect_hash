#include <reflect/reflect.h>
#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    double height;
};

struct Point {
    double x;
    double y;
    double z;
};

int main() {
    using namespace ConstexprCore::reflect;

    // === Person example ===
    Person p{"Bob", 42, 1.85};

    // Get field names
    std::cout << "Person fields:";
    constexpr auto keys = reflect_keys<Person>();
    for (auto k : keys) std::cout << " " << k;
    std::cout << "\n\n";

    // Access by runtime string — just like obj["name"] in JavaScript
    std::string key = "name";
    std::cout << "p[\"" << key << "\"] = " << reflect_get(p, key) << "\n";
    std::cout << "p[\"age\"]    = " << reflect_get(p, "age") << "\n";
    std::cout << "p[\"height\"] = " << reflect_get(p, "height") << "\n\n";

    // Set by name
    reflect_set(p, "age", 43);
    std::cout << "After reflect_set(p, \"age\", 43):\n";
    std::cout << "p[\"age\"] = " << reflect_get(p, "age") << "\n\n";

    // Visit with generic lambda (zero overhead)
    std::cout << "reflect_visit:\n";
    reflect_visit(p, "name", [](const auto& val) {
        std::cout << "  name is: " << val << "\n";
    });

    // Iterate all fields
    std::cout << "\nreflect_for_each:\n";
    reflect_for_each(p, [](std::string_view name, const auto& val) {
        std::cout << "  " << name << " = " << val << "\n";
    });

    // Check field existence
    std::cout << "\nreflect_has<Person>(\"name\")   = " << reflect_has<Person>("name") << "\n";
    std::cout << "reflect_has<Person>(\"email\")  = " << reflect_has<Person>("email") << "\n";

    // === Point example ===
    std::cout << "\n--- Point ---\n";
    Point pt{1.0, 2.5, -3.7};
    reflect_for_each(pt, [](std::string_view name, const auto& val) {
        std::cout << name << " = " << val << "\n";
    });

    return 0;
}
