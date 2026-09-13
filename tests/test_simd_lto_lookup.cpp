#include <ConstexprCore/perfect_hash.h>

namespace {

inline constexpr std::array<std::string_view, 3> keys{
    std::string_view{}, "short", "a key spanning more than two sixteen-byte chunks"};
inline constexpr auto wide_table = ConstexprCore::make_wide_perfect_index_map<keys>();
inline constexpr auto classic_table = ConstexprCore::make_perfect_map<
    ConstexprCore::kv<"OK", 200>, ConstexprCore::kv<"Not Found", 404>,
    ConstexprCore::kv<"Internal Server Error", 500>>();

} // namespace

// The caller is a separate translation unit: only link-time optimization
// discovers that its inputs are objects shorter than a complete SIMD load.
extern "C" bool wide_lto_member(const char* p, std::size_t len) {
    return wide_table.contains(std::string_view(p, len));
}

extern "C" int classic_lto_lookup(const char* p, std::size_t len) {
    return classic_table.lookup(std::string_view(p, len)).value_or(-1);
}
