#ifndef CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H
#define CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H

#include <array>
#include <string_view>
#include <cstddef>

namespace ConstexprCore::detail {

constexpr std::size_t next_power_of_2(std::size_t n) {
    if (n == 0) return 1;
    std::size_t p = 1;
    while (p < n) p <<= 1;
    return p;
}

static constexpr std::size_t MAX_POSITIONS = 16;
static constexpr std::size_t LAST_CHAR = std::size_t(-1);

// Round up to next power of two
consteval std::size_t next_power_of_two(std::size_t n) {
    if (n == 0) return 1;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n++;
    return n;
}

// Check if a number is a power of two
consteval bool is_power_of_two(std::size_t n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Returns the character at a given position (LAST_CHAR means last character),
// or 256 as a sentinel if out of bounds.
constexpr std::size_t char_at(std::string_view key, std::size_t pos) {
    if (pos == LAST_CHAR) {
        if (key.empty()) return 256;
        return static_cast<unsigned char>(key[key.size() - 1]);
    }
    if (pos >= key.size()) return 256;
    return static_cast<unsigned char>(key[pos]);
}

// Check whether a set of positions distinguishes all key pairs that could collide.
// Two keys can only be distinguished by asso_values if at least one position
// yields different characters. Keys with different length % modulus are inherently
// separated by the length term in the hash, so they don't need position coverage.
template <std::size_t N>
consteval bool positions_distinguish(
    const std::array<std::string_view, N>& keys,
    const std::size_t* positions,
    std::size_t num_positions,
    std::size_t modulus)
{
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i].size() % modulus != keys[j].size() % modulus) continue;
            // Same length mod modulus — at least one position must differ
            bool distinguished = false;
            for (std::size_t p = 0; p < num_positions; ++p) {
                if (char_at(keys[i], positions[p]) != char_at(keys[j], positions[p])) {
                    distinguished = true;
                    break;
                }
            }
            if (!distinguished) return false;
        }
    }
    return true;
}

// Like positions_distinguish but returns the count of undistinguished pairs.
template <std::size_t N>
consteval std::size_t count_undistinguished_pairs(
    const std::array<std::string_view, N>& keys,
    const std::size_t* positions,
    std::size_t num_positions,
    std::size_t modulus)
{
    std::size_t count = 0;
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (keys[i].size() % modulus != keys[j].size() % modulus) continue;
            bool distinguished = false;
            for (std::size_t p = 0; p < num_positions; ++p) {
                if (char_at(keys[i], positions[p]) != char_at(keys[j], positions[p])) {
                    distinguished = true;
                    break;
                }
            }
            if (!distinguished) ++count;
        }
    }
    return count;
}

// Compute discriminating power: number of distinct (length % modulus, char_at(key, pos)) pairs.
template <std::size_t N>
consteval std::size_t discriminating_power(
    const std::array<std::string_view, N>& keys,
    std::size_t pos,
    std::size_t modulus)
{
    // Store (length % modulus, char) pairs and count distinct ones
    struct pair { std::size_t len_mod; std::size_t ch; };
    std::array<pair, N> pairs{};
    for (std::size_t i = 0; i < N; ++i) {
        pairs[i] = {keys[i].size() % modulus, char_at(keys[i], pos)};
    }
    std::size_t count = 0;
    for (std::size_t i = 0; i < N; ++i) {
        bool dup = false;
        for (std::size_t j = 0; j < i; ++j) {
            if (pairs[i].len_mod == pairs[j].len_mod && pairs[i].ch == pairs[j].ch) {
                dup = true;
                break;
            }
        }
        if (!dup) ++count;
    }
    return count;
}

// Find the maximum key length to know what positions to consider.
template <std::size_t N>
consteval std::size_t max_key_length(const std::array<std::string_view, N>& keys) {
    std::size_t m = 0;
    for (std::size_t i = 0; i < N; ++i) {
        if (keys[i].size() > m) m = keys[i].size();
    }
    return m;
}

// Backtracking search for a minimal set of positions that distinguishes all pairs.
// Uses iterative DFS with an explicit stack and a budget to bound compile-time cost.
// Returns true if a solution was found (written into positions/num_positions_out).
template <std::size_t N>
consteval bool backtracking_search(
    const std::array<std::string_view, N>& keys,
    const std::size_t* candidates,
    std::size_t num_candidates,
    std::size_t* positions,
    std::size_t& num_positions_out,
    std::size_t& budget,
    std::size_t modulus)
{
    constexpr std::size_t MAX_DEPTH = 8;
    // Limit candidate breadth to keep search manageable
    std::size_t breadth = num_candidates < 20 ? num_candidates : 20;

    struct frame {
        std::size_t depth;
        std::size_t next_ci;
        std::size_t parent_count;
    };

    std::array<frame, MAX_DEPTH + 1> stack{};
    std::size_t sp = 0;

    // Initial undistinguished count (no positions selected)
    std::size_t initial_count = count_undistinguished_pairs<N>(keys, positions, 0, modulus);
    if (budget > 0) --budget;
    if (initial_count == 0) {
        num_positions_out = 0;
        return true;
    }

    stack[0] = {0, 0, initial_count};

    while (budget > 0) {
        if (sp > MAX_DEPTH) {
            // Can't go deeper, shouldn't happen but guard
            if (sp == 0) break;
            --sp;
            ++stack[sp].next_ci;
            continue;
        }

        auto& f = stack[sp];

        if (f.next_ci >= breadth) {
            // Exhausted candidates at this depth — backtrack
            if (sp == 0) break;
            --sp;
            ++stack[sp].next_ci;
            continue;
        }

        positions[sp] = candidates[f.next_ci];
        --budget;
        std::size_t new_count = count_undistinguished_pairs<N>(keys, positions, sp + 1, modulus);

        if (new_count == 0) {
            num_positions_out = sp + 1;
            return true;
        }

        if (new_count < f.parent_count && sp + 1 < MAX_DEPTH) {
            // Collision count decreased — go deeper
            stack[sp + 1] = {sp + 1, f.next_ci + 1, new_count};
            ++sp;
        } else {
            // No improvement or at max depth — try next candidate
            ++f.next_ci;
        }
    }

    return false;
}

// Phase 1: Select character positions that distinguish all potentially-colliding pairs.
template <std::size_t N>
consteval std::size_t select_positions(
    const std::array<std::string_view, N>& keys,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::size_t modulus)
{
    // Strategy 1: Empty set — works if all keys have distinct lengths.
    if (positions_distinguish<N>(keys, positions.data(), 0, modulus)) {
        return 0;
    }

    // Compute max key length for candidate positions
    std::size_t max_len = max_key_length(keys);

    // Build candidate positions: 0..max_len-1, plus LAST_CHAR
    // We'll rank them by discriminating power.
    constexpr std::size_t MAX_CANDIDATES = 256;
    std::array<std::size_t, MAX_CANDIDATES> candidates{};
    std::array<std::size_t, MAX_CANDIDATES> powers{};
    std::size_t num_candidates = 0;

    // Don't consider positions >= max_len since they yield LAST_CHAR and are redundant.
    for (std::size_t p = 0; p < max_len && num_candidates < MAX_CANDIDATES - 1; ++p) {
        candidates[num_candidates] = p;
        powers[num_candidates] = discriminating_power(keys, p, modulus);
        ++num_candidates;
    }
    // Add LAST_CHAR
    if (num_candidates < MAX_CANDIDATES) {
        candidates[num_candidates] = LAST_CHAR;
        powers[num_candidates] = discriminating_power(keys, LAST_CHAR, modulus);
        ++num_candidates;
    }

    // Sort candidates by power descending (bubble sort, fine for consteval)
    for (std::size_t i = 0; i < num_candidates; ++i) {
        for (std::size_t j = i + 1; j < num_candidates; ++j) {
            if (powers[j] > powers[i]) {
                auto tc = candidates[i]; candidates[i] = candidates[j]; candidates[j] = tc;
                auto tp = powers[i]; powers[i] = powers[j]; powers[j] = tp;
            }
        }
    }

    // Strategy 2: Single best position
    positions[0] = candidates[0];
    if (positions_distinguish<N>(keys, positions.data(), 1, modulus)) {
        return 1;
    }

    // Strategy 3: {0, LAST_CHAR}
    positions[0] = 0;
    positions[1] = LAST_CHAR;
    if (positions_distinguish<N>(keys, positions.data(), 2, modulus)) {
        return 2;
    }

    // Strategy 4: Backtracking search over top candidates
    {
        // Magic constant: caps the number of count_undistinguished_pairs
        // evaluations to keep compile times bounded. Could be tuned with
        // benchmarking or exposed as a user-configurable template parameter.
        std::size_t budget = 5000;
        std::size_t num_found = 0;
        if (backtracking_search<N>(keys, candidates.data(), num_candidates,
                                   positions.data(), num_found, budget, modulus)) {
            return num_found;
        }
    }

    // Strategy 5 (fallback): Greedily add positions until all pairs distinguished
    std::size_t num_pos = 0;
    for (std::size_t ci = 0; ci < num_candidates && num_pos < MAX_POSITIONS; ++ci) {
        // Check if this candidate is already selected
        bool already = false;
        for (std::size_t p = 0; p < num_pos; ++p) {
            if (positions[p] == candidates[ci]) { already = true; break; }
        }
        if (already) continue;

        positions[num_pos] = candidates[ci];
        ++num_pos;

        if (positions_distinguish<N>(keys, positions.data(), num_pos, modulus)) {
            return num_pos;
        }
    }

    throw "Failed to find distinguishing positions for perfect hash";
}

// Partition-based asso_values search, inspired by GNU gperf.
//
// Instead of a collision-bump loop (which cycles for large N), this algorithm
// determines asso_values one (position, character) symbol at a time and never
// changes a value once set.  The correctness invariant is maintained via
// equivalence classes: two keywords whose remaining undetermined symbols are
// identical must already have distinct partial hashes (mod M), because no
// future determination can separate them.
//
// Complexity: O(num_symbols * search_range * N) where num_symbols is the
// number of unique (position, character) pairs (~alphabet_size * positions),
// search_range is typically O(M), and N is the keyword count.  In practice
// this is far faster than the collision-bump approach for large N because
// each symbol's search space is small and independent.
//
// M is the table size (number of hash slots). Defaults to N (minimal PHF).
// When M > N, the hash is non-minimal: some slots remain empty (sentinel = N).
template <std::size_t N, std::size_t M = N>
consteval bool try_generate_gperf(
    const std::array<std::string_view, N>& keys,
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS>& asso_values,
    std::size_t& num_positions,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::array<std::size_t, M>& slot_to_key)
{
    // Phase 1: Position selection (use M as modulus since hash computes % M)
    num_positions = select_positions<N>(keys, positions, M);

    // Initialize all asso_values to 0.
    for (std::size_t p = 0; p < MAX_POSITIONS; ++p)
        for (std::size_t c = 0; c < 256; ++c)
            asso_values[p][c] = 0;

    // If lengths alone distinguish all keys, no asso_values needed.
    if (num_positions == 0) {
        for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
        for (std::size_t i = 0; i < N; ++i) {
            std::size_t slot = keys[i].size() % M;
            if (slot_to_key[slot] != N) return false;
            slot_to_key[slot] = i;
        }
        return true;
    }

    // Phase 2: Pre-compute each keyword's character at each selected position.
    std::array<std::array<std::size_t, MAX_POSITIONS>, N> kchars{};
    for (std::size_t k = 0; k < N; ++k)
        for (std::size_t p = 0; p < num_positions; ++p)
            kchars[k][p] = char_at(keys[k], positions[p]);

    // Phase 3: Enumerate unique (position, character) symbols and their
    // frequencies.  These are the "variables" we need to assign values to.
    struct sym_t { std::size_t pos; std::size_t ch; std::size_t freq; };
    constexpr std::size_t MAX_SYMS = MAX_POSITIONS * 256;
    std::array<sym_t, MAX_SYMS> syms{};
    std::size_t nsyms = 0;

    for (std::size_t p = 0; p < num_positions; ++p) {
        std::array<std::size_t, 256> freq{};
        for (std::size_t k = 0; k < N; ++k) {
            std::size_t c = kchars[k][p];
            if (c < 256) freq[c]++;
        }
        for (std::size_t c = 0; c < 256; ++c)
            if (freq[c] > 0)
                syms[nsyms++] = {p, c, freq[c]};
    }

    // Sort symbols by decreasing frequency.  High-frequency symbols affect
    // more keywords, so determining them first (when the partition is coarsest
    // and we have the most freedom) produces smaller asso_values.
    for (std::size_t i = 0; i < nsyms; ++i)
        for (std::size_t j = i + 1; j < nsyms; ++j)
            if (syms[j].freq > syms[i].freq) {
                auto tmp = syms[i]; syms[i] = syms[j]; syms[j] = tmp;
            }

    // Phase 4: Determine asso_values one symbol at a time.
    //
    // For each symbol (p, c) we:
    //   1. Compute equivalence classes: keywords grouped by their set of
    //      undetermined symbols (after marking (p,c) as determined).
    //   2. Try values v = 0, 1, ... for asso_values[p][c].
    //   3. Accept the first v where, within every equivalence class,
    //      all partial hashes (mod M) are distinct.

    // Track which (pos, char) pairs have been determined.
    std::array<std::array<bool, 256>, MAX_POSITIONS> determined{};

    // Partial hash for each keyword (sum of key length + determined asso_values).
    std::array<std::size_t, N> phash{};
    for (std::size_t k = 0; k < N; ++k)
        phash[k] = keys[k].size();

    // Equivalence class machinery: signatures and sorted order.
    //
    // We maintain sig[k] = XOR over all *undetermined* symbols (p, kchars[k][p])
    // of a per-symbol salt value.  When a symbol (sp, sc) is marked determined
    // we XOR salt[sp][sc] out of the signature of every matching key — this is
    // O(matching keys) instead of recomputing all N signatures from scratch
    // with a num_positions-wide inner loop (the previous hot path blew the
    // constexpr ops limit for N ~ 100).
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS> salt{};
    {
        std::size_t s = 0x9e3779b97f4a7c15ULL;
        for (std::size_t p = 0; p < num_positions; ++p) {
            for (std::size_t c = 0; c < 256; ++c) {
                s = s * 6364136223846793005ULL + 1442695040888963407ULL;
                salt[p][c] = s;
            }
        }
    }

    std::array<std::size_t, N> sig{};
    for (std::size_t k = 0; k < N; ++k) {
        std::size_t s = 0;
        for (std::size_t p = 0; p < num_positions; ++p) {
            std::size_t c = kchars[k][p];
            if (c < 256) s ^= salt[p][c];
        }
        sig[k] = s;
    }
    std::array<std::size_t, N> order{};
    for (std::size_t k = 0; k < N; ++k) order[k] = k;

    // Collision detection via generation counter (avoids clearing a size-M
    // array for every equivalence class check).
    std::array<std::size_t, M> slot_gen{};
    std::size_t gen = 0;

    // Search limit for each symbol's asso_value.
    std::size_t search_limit = next_power_of_2(M);
    if (search_limit < 32) search_limit = 32;

    for (std::size_t si = 0; si < nsyms; ++si) {
        std::size_t sp = syms[si].pos;
        std::size_t sc = syms[si].ch;

        // Mark (sp, sc) as determined *for signature purposes*: XOR its salt
        // out of the signature of every key whose char at position sp is sc.
        // After this step, sig[k] reflects the set of undetermined symbols
        // minus (sp, sc), which is exactly what the equivalence-class
        // invariant requires for the current iteration.
        std::size_t sp_salt = salt[sp][sc];
        for (std::size_t k = 0; k < N; ++k) {
            if (kchars[k][sp] == sc) sig[k] ^= sp_salt;
        }

        // Sort order[] by sig[] using insertion sort.  We keep order[] sorted
        // between iterations; since only a handful of signatures change per
        // iteration, insertion sort runs in ~O(N) on this near-sorted input
        // (vs. the O(N^2) bubble sort that blew the constexpr ops limit).
        for (std::size_t i = 1; i < N; ++i) {
            std::size_t x = order[i];
            std::size_t xs = sig[x];
            std::size_t j = i;
            while (j > 0 && sig[order[j - 1]] > xs) {
                order[j] = order[j - 1];
                --j;
            }
            order[j] = x;
        }

        // Try values for asso_values[sp][sc].
        bool found = false;
        for (std::size_t v = 0; v < search_limit && !found; ++v) {
            bool collision = false;

            // Scan equivalence classes (consecutive blocks with equal sig).
            std::size_t ci = 0;
            while (ci < N && !collision) {
                std::size_t class_sig = sig[order[ci]];
                std::size_t cj = ci;
                while (cj < N && sig[order[cj]] == class_sig) ++cj;

                // Only check classes with more than one member.
                if (cj - ci > 1) {
                    ++gen;
                    for (std::size_t x = ci; x < cj; ++x) {
                        std::size_t k = order[x];
                        std::size_t h = phash[k];
                        if (kchars[k][sp] == sc) h += v;
                        h %= M;
                        if (slot_gen[h] == gen) {
                            collision = true;
                            break;
                        }
                        slot_gen[h] = gen;
                    }
                }
                ci = cj;
            }

            if (!collision) {
                asso_values[sp][sc] = v;
                for (std::size_t k = 0; k < N; ++k)
                    if (kchars[k][sp] == sc) phash[k] += v;
                found = true;
            }
        }

        if (!found) return false;
        determined[sp][sc] = true;
    }

    // Phase 5: Build slot_to_key from final hash values.
    for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
    for (std::size_t i = 0; i < N; ++i) {
        std::size_t slot = phash[i] % M;
        if (slot_to_key[slot] != N) return false;
        slot_to_key[slot] = i;
    }
    std::size_t filled = 0;
    for (std::size_t i = 0; i < M; ++i)
        if (slot_to_key[i] != N) ++filled;
    return filled == N;
}

// Throwing wrapper around try_generate_gperf.
template <std::size_t N, std::size_t M = N>
consteval void generate_gperf(
    const std::array<std::string_view, N>& keys,
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS>& asso_values,
    std::size_t& num_positions,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::array<std::size_t, M>& slot_to_key)
{
    if (!try_generate_gperf<N, M>(keys, asso_values, num_positions, positions, slot_to_key)) {
        throw "Failed to find asso_values for perfect hash";
    }
}

// Result of PHF computation, carrying all data needed to construct a
// perfect_hash_set/map without recomputing. Uses a max-sized slot_to_key
// array so the same struct type works for any table size up to MaxM.
template <std::size_t N>
struct phf_result {
    // Allow up to 8x the minimum table size. Sparser tables are much easier
    // to solve (fewer collisions) which dramatically reduces consteval time.
    static constexpr std::size_t MAX_TABLE_SIZE = next_power_of_2(N) * 8;
    std::size_t table_size{};
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS> asso_values{};
    std::size_t num_positions{};
    std::array<std::size_t, MAX_POSITIONS> positions{};
    std::array<std::size_t, MAX_TABLE_SIZE> slot_to_key{};
};

// Try a specific table size M. On success, fills result and returns true.
template <std::size_t N, std::size_t M>
consteval bool try_compute_phf(
    const std::array<std::string_view, N>& keys,
    phf_result<N>& result)
{
    static_assert(M <= phf_result<N>::MAX_TABLE_SIZE, "Table size M exceeds maximum");

    std::array<std::array<std::size_t, 256>, MAX_POSITIONS> asso{};
    std::size_t npos{};
    std::array<std::size_t, MAX_POSITIONS> pos{};
    std::array<std::size_t, M> s2k{};

    if (try_generate_gperf<N, M>(keys, asso, npos, pos, s2k)) {
        result.table_size = M;
        result.asso_values = asso;
        result.num_positions = npos;
        result.positions = pos;
        for (std::size_t i = 0; i < M; ++i) result.slot_to_key[i] = s2k[i];
        // Fill remaining slots with sentinel
        for (std::size_t i = M; i < phf_result<N>::MAX_TABLE_SIZE; ++i)
            result.slot_to_key[i] = N;
        return true;
    }
    return false;
}

// Power-of-2 table size search: tries next_power_of_2(N), then 2x that, etc.
// Only 2-3 template instantiations instead of up to N/2 with linear search.
// Power-of-2 sizes let the compiler optimize h % TableSize to h & (TableSize-1).
template <std::size_t N, std::size_t M>
consteval phf_result<N> compute_phf_po2(
    const std::array<std::string_view, N>& keys)
{
    static_assert(M <= phf_result<N>::MAX_TABLE_SIZE, "Table size M exceeds maximum");

    phf_result<N> result{};
    if (try_compute_phf<N, M>(keys, result)) {
        return result;
    }

    constexpr std::size_t NextM = M * 2;
    if constexpr (NextM <= phf_result<N>::MAX_TABLE_SIZE) {
        return compute_phf_po2<N, NextM>(keys);
    } else {
        throw "Failed to find a valid power-of-2 table size for perfect hash";
    }
}

// Try gperf with power-of-2 sizes up to MaxM.  Returns true on success.
template <std::size_t N, std::size_t M, std::size_t MaxM>
consteval bool try_gperf_po2(
    const std::array<std::string_view, N>& keys,
    phf_result<N>& result)
{
    if (try_compute_phf<N, M>(keys, result))
        return true;
    constexpr std::size_t NextM = M * 2;
    if constexpr (NextM <= MaxM) {
        return try_gperf_po2<N, NextM, MaxM>(keys, result);
    }
    return false;
}

// Bucket hash for Hash-and-Displace: combines first char, last char, and length.
// Must match between generator (consteval) and runtime (compute_hash).
constexpr std::size_t hd_bucket_hash(std::string_view key) {
    std::size_t c0 = key.empty() ? 0 : static_cast<unsigned char>(key[0]);
    std::size_t c1 = key.empty() ? 0 : static_cast<unsigned char>(key[key.size() - 1]);
    return (c0 + c1 * 3 + key.size() * 17) & 0xFF;
}

// Per-key hash for Hash-and-Displace: polynomial of first N bytes + length.
// Two variants: 2-byte (lighter, fewer instructions) and 4-byte (stronger mixing).
// The generator tries 2-byte first; if it can't find a valid PHF, falls back to 4-byte.
// Must match between generator (consteval) and runtime (compute_hash).

constexpr std::size_t hd_safe_char(const char* p, std::size_t len, std::size_t idx) {
    std::size_t has = static_cast<std::size_t>(idx < len);
    std::size_t si = idx & (0-has);
    return static_cast<unsigned char>(p[si]) & (0-has);
}

constexpr std::size_t hd_key_hash_2(std::string_view key) {
    std::size_t kc = key.size();
    kc = kc * 31 + static_cast<unsigned char>(key[0]);
    kc = kc * 31 + hd_safe_char(key.data(), key.size(), 1);
    return kc;
}

constexpr std::size_t hd_key_hash_4(std::string_view key) {
    std::size_t kc = key.size();
    kc = kc * 31 + static_cast<unsigned char>(key[0]);
    kc = kc * 31 + hd_safe_char(key.data(), key.size(), 1);
    kc = kc * 31 + hd_safe_char(key.data(), key.size(), 2);
    kc = kc * 31 + hd_safe_char(key.data(), key.size(), 3);
    return kc;
}

// Legacy name for backward compatibility (4-byte variant).
constexpr std::size_t hd_key_hash(std::string_view key) { return hd_key_hash_4(key); }

// HD_HASH_2BYTE flag: stored in positions_[2] by the generator when the
// 2-byte key hash was sufficient. Runtime compute_hash checks this to
// select the lighter hash variant.
static constexpr std::size_t HD_HASH_2BYTE_FLAG = 2;
static constexpr std::size_t HD_HASH_4BYTE_FLAG = 4;


// ============================================================================
// Hash-and-Displace generator: O(N) expected time, consteval-friendly.
//
// Instead of the gperf-style collision-and-bump (which does millions of
// iterations), this algorithm:
//   1. Selects distinguishing positions (same as gperf)
//   2. Groups keys by their hash contribution from position chars
//   3. Processes groups largest-first, finding a displacement value for
//      each group such that all keys land on empty slots
//
// The displacement is stored in asso_values[], so the runtime hash function
// is identical: h = key.size() + SUM(asso_values[key[pos_i]]) % M
//
// For the displacement to work, we use position 0 as the "bucket selector"
// and find asso_values[key[pos_0]] that places each bucket's keys into
// empty slots considering the other positions' contributions.
// ============================================================================

template <std::size_t N, std::size_t M>
consteval bool try_hash_and_displace(
    const std::array<std::string_view, N>& keys,
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS>& asso_values,
    std::size_t& num_positions,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::array<std::size_t, M>& slot_to_key)
{
    // Phase 1: Position selection (reuse existing logic)
    num_positions = select_positions<N>(keys, positions, M);

    // Phase 2: Group keys by the character at the first selected position.
    // This character's asso_value will be the "displacement" for the group.
    // If num_positions == 0 (lengths alone distinguish), use a simpler path.
    if (num_positions == 0) {
        // Lengths alone distinguish — just assign slots by length % M
        for (std::size_t i = 0; i < 256; ++i) asso_values[0][i] = 0;
        for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
        for (std::size_t i = 0; i < N; ++i) {
            std::size_t slot = keys[i].size() % M;
            if (slot_to_key[slot] != N) return false; // collision
            slot_to_key[slot] = i;
        }
        return true;
    }

    // Bucket hash: combine first char + last char + length into a byte index.
    // Each unique bucket gets a displacement value stored in asso_values[bucket].
    // Signal H&D mode to compute_hash via num_positions = 0xFF sentinel.
    for (std::size_t i = 0; i < 256; ++i) asso_values[0][i] = 0;

    // Use position 0 (first char) and LAST_CHAR (last char) for the bucket hash.
    // These provide the best discrimination for typical key sets (identifiers,
    // tickers, keywords) where first and last characters vary the most.
    std::size_t pos0 = 0;
    std::size_t pos1 = LAST_CHAR;

    // Set num_positions = 0xFF to signal H&D mode to compute_hash.
    // Store the actual positions in positions[0] and positions[1].
    // positions[2] stores the key hash variant flag (2-byte or 4-byte).
    num_positions = 0xFF; // sentinel for H&D mode
    positions[0] = pos0;
    positions[1] = pos1;

    // Group by bucket
    std::array<std::size_t, N> key_bucket{};
    for (std::size_t i = 0; i < N; ++i)
        key_bucket[i] = hd_bucket_hash(keys[i]);

    // Find all unique buckets and count keys per bucket.
    struct bucket_info { std::size_t ch; std::size_t count; };
    std::array<bucket_info, N> buckets{};
    std::size_t num_buckets = 0;
    for (std::size_t i = 0; i < N; ++i) {
        std::size_t bk = key_bucket[i];
        bool found = false;
        for (std::size_t b = 0; b < num_buckets; ++b) {
            if (buckets[b].ch == bk) { ++buckets[b].count; found = true; break; }
        }
        if (!found) { buckets[num_buckets++] = {bk, 1}; }
    }

    // Sort buckets by count descending (bubble sort, fine for consteval).
    for (std::size_t i = 0; i < num_buckets; ++i) {
        for (std::size_t j = i + 1; j < num_buckets; ++j) {
            if (buckets[j].count > buckets[i].count) {
                auto tmp = buckets[i]; buckets[i] = buckets[j]; buckets[j] = tmp;
            }
        }
    }

    // Helper: try H&D placement with a given key hash function.
    auto try_placement = [&](auto key_hash_fn) -> bool {
        for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
        for (std::size_t i = 0; i < 256; ++i) asso_values[0][i] = 0;

        for (std::size_t b = 0; b < num_buckets; ++b) {
            std::size_t ch = buckets[b].ch;
            std::array<std::size_t, N> bucket_keys{};
            std::size_t bk_count = 0;
            for (std::size_t i = 0; i < N; ++i)
                if (key_bucket[i] == ch) bucket_keys[bk_count++] = i;

            bool placed = false;
            std::size_t max_d = M < 255 ? M : 255;
            for (std::size_t d = 0; d < max_d; ++d) {
                bool ok = true;
                std::array<std::size_t, N> bucket_slots{};
                for (std::size_t k = 0; k < bk_count; ++k) {
                    std::size_t slot = (d + key_hash_fn(keys[bucket_keys[k]])) % M;
                    if (slot_to_key[slot] != N) { ok = false; break; }
                    for (std::size_t k2 = 0; k2 < k; ++k2) {
                        if (bucket_slots[k2] == slot) { ok = false; break; }
                    }
                    if (!ok) break;
                    bucket_slots[k] = slot;
                }
                if (ok) {
                    asso_values[0][ch] = d;
                    for (std::size_t k = 0; k < bk_count; ++k)
                        slot_to_key[bucket_slots[k]] = bucket_keys[k];
                    placed = true;
                    break;
                }
            }
            if (!placed) return false;
        }
        std::size_t filled = 0;
        for (std::size_t i = 0; i < M; ++i)
            if (slot_to_key[i] != N) ++filled;
        return filled == N;
    };

    // Try 2-byte key hash first (lighter runtime: 2 rounds instead of 4).
    if (try_placement([](std::string_view k) { return hd_key_hash_2(k); })) {
        positions[2] = HD_HASH_2BYTE_FLAG;
        return true;
    }

    // Fall back to 4-byte key hash (stronger mixing).
    if (try_placement([](std::string_view k) { return hd_key_hash_4(k); })) {
        positions[2] = HD_HASH_4BYTE_FLAG;
        return true;
    }

    return false;
}

// Try Hash-and-Displace for a specific table size M.
template <std::size_t N, std::size_t M>
consteval bool try_compute_phf_hd(
    const std::array<std::string_view, N>& keys,
    phf_result<N>& result)
{
    static_assert(M <= phf_result<N>::MAX_TABLE_SIZE, "Table size M exceeds maximum");

    std::array<std::array<std::size_t, 256>, MAX_POSITIONS> asso{};
    std::size_t npos{};
    std::array<std::size_t, MAX_POSITIONS> pos{};
    std::array<std::size_t, M> s2k{};

    if (try_hash_and_displace<N, M>(keys, asso, npos, pos, s2k)) {
        result.table_size = M;
        result.asso_values = asso;
        result.num_positions = npos;
        result.positions = pos;
        for (std::size_t i = 0; i < M; ++i) result.slot_to_key[i] = s2k[i];
        for (std::size_t i = M; i < phf_result<N>::MAX_TABLE_SIZE; ++i)
            result.slot_to_key[i] = N;
        return true;
    }
    return false;
}

// Power-of-2 search using Hash-and-Displace.
template <std::size_t N, std::size_t M>
consteval phf_result<N> compute_phf_hd_po2(
    const std::array<std::string_view, N>& keys)
{
    static_assert(M <= phf_result<N>::MAX_TABLE_SIZE, "Table size M exceeds maximum");

    phf_result<N> result{};
    if (try_compute_phf_hd<N, M>(keys, result)) {
        return result;
    }

    constexpr std::size_t NextM = M * 2;
    if constexpr (NextM <= phf_result<N>::MAX_TABLE_SIZE) {
        return compute_phf_hd_po2<N, NextM>(keys);
    } else {
        throw "Hash-and-Displace: failed to find valid table size";
    }
}

// Compute PHF for the given keys.
// Strategy: try the partition-based gperf algorithm first (produces smaller,
// faster hash functions), capped at table size 256 to stay within uint8_t.
// Falls back to Hash-and-Displace for large N or if gperf cannot find a
// solution at the available table sizes.
template <std::size_t N>
consteval phf_result<N> compute_phf(const std::array<std::string_view, N>& keys) {
    constexpr std::size_t StartM = next_power_of_2(N);
    // The runtime perfect_hash_set uses uint8_t for asso_values (reduced
    // mod TableSize, so 0..TableSize-1 fits whenever TableSize <= 256) and
    // slot_to_key entries are key indices (< N <= 255).  Cap gperf attempts
    // at 256 (the largest power of 2 that fits).
    constexpr std::size_t GPERF_MAX_TABLE =
        phf_result<N>::MAX_TABLE_SIZE < 256 ? phf_result<N>::MAX_TABLE_SIZE : 256;
    if constexpr (StartM <= GPERF_MAX_TABLE) {
        phf_result<N> result{};
        if (try_gperf_po2<N, StartM, GPERF_MAX_TABLE>(keys, result))
            return result;
    }
    // Fall back to Hash-and-Displace.
    return compute_phf_hd_po2<N, StartM>(keys);
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H
