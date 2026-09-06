#include <cstddef>
#include <cstdio>

extern "C" bool wide_lto_member(const char* p, std::size_t len);
extern "C" int classic_lto_lookup(const char* p, std::size_t len);

int main() {
    const bool wide = wide_lto_member("short", 5);
    const bool empty = wide_lto_member(nullptr, 0);
    const bool miss = wide_lto_member("shor", 4);
    const int ok = classic_lto_lookup("OK", 2);
    const int missing = classic_lto_lookup("Not Found", 9);
    const int error = classic_lto_lookup("Internal Server Error", 21);
    std::printf("short=%d empty=%d miss=%d OK=%d NotFound=%d Error=%d\n",
                wide, empty, miss, ok, missing, error);
    return wide && empty && !miss && ok == 200 && missing == 404 && error == 500 ? 0 : 1;
}
