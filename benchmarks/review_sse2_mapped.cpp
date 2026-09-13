// Focused dynamic SIMD benchmark; the review measured this as x86-64 under
// Rosetta, not on native x86 hardware. Pass an iteration count as argv[1].
#include <ConstexprCore/detail/simd16.h>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <vector>

struct alignas(64) query {
    std::array<char, 64> input{};
    std::array<char, 64> stored{};
    std::size_t len{};
};

template <std::size_t MaxLen, class F>
void measure(const char* label, std::size_t iterations, F function) {
    std::vector<query> inputs(256);
    std::mt19937_64 random(42);
    for (std::size_t i = 0; i < inputs.size(); ++i) {
        auto& q = inputs[i];
        q.len = 1 + random() % MaxLen;
        for (std::size_t j = 0; j < q.input.size(); ++j)
            q.input[j] = static_cast<char>(random());
        for (std::size_t j = 0; j < q.len; ++j) q.stored[j] = q.input[j];
        if (i & 1) q.stored[0] ^= 0x55;
    }
    std::uint64_t sum = 0;
    for (std::size_t i = 0; i < 100000; ++i) sum += function(inputs[i & 255]);
    const auto start = std::chrono::steady_clock::now();
    for (std::size_t i = 0; i < iterations; ++i) sum += function(inputs[i & 255]);
    const auto stop = std::chrono::steady_clock::now();
    const double ns = std::chrono::duration<double, std::nano>(stop - start).count();
    std::printf("%s %.6f ns/op checksum=%llu\n", label, ns / iterations,
                static_cast<unsigned long long>(sum));
}

int main(int argc, char** argv) {
    const std::size_t iterations = argc > 1 ? std::strtoull(argv[1], nullptr, 10) : 20000000;
    measure<16>("load16", iterations, [](const query& q) {
        const auto c = ConstexprCore::detail::load_chunk16(q.input.data(), q.len);
        return ConstexprCore::detail::lane0(c) ^ ConstexprCore::detail::lane1(c);
    });
    measure<32>("compare32", iterations, [](const query& q) {
        return ConstexprCore::detail::compare_chunks<32>(q.input.data(), q.len, q.stored.data());
    });
    measure<64>("compare64", iterations, [](const query& q) {
        return ConstexprCore::detail::compare_chunks<64>(q.input.data(), q.len, q.stored.data());
    });
}
