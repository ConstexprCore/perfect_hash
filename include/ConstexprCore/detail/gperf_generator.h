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

// Non-throwing variant: returns true on success, false on failure.
// M is the table size (number of hash slots). Defaults to N (minimal PHF).
// When M > N, the hash is non-minimal: some slots remain empty (sentinel = N).
template <std::size_t N, std::size_t M = N>
consteval bool try_generate_gperf(
    const std::array<std::string_view, N>& keys,
    std::array<std::size_t, 256>& asso_values,
    std::size_t& num_positions,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::array<std::size_t, M>& slot_to_key)
{
    // Phase 1: Position selection (use M as modulus since hash computes % M)
    num_positions = select_positions<N>(keys, positions, M);

    // Compute the hash value for a given key using the current association values and positions.
    auto compute = [&](std::string_view key) -> std::size_t {
        std::size_t h = key.size();
        for (std::size_t i = 0; i < num_positions; ++i) {
            std::size_t pos = positions[i];
            std::size_t ch = char_at(key, pos);
            if (ch < 256) {
                h += asso_values[ch];
            }
        }
        return h % M;
    };

    // Pre-compute character frequencies ONCE (not per-collision).
    // This was previously O(N * positions) per collision — a major bottleneck.
    std::array<std::size_t, 256> char_freq{};
    for (std::size_t k = 0; k < N; ++k) {
        for (std::size_t p = 0; p < num_positions; ++p) {
            std::size_t ch = char_at(keys[k], positions[p]);
            if (ch < 256) { ++char_freq[ch]; }
        }
    }
    auto char_frequency = [&](std::size_t ch) -> std::size_t {
        return (ch < 256) ? char_freq[ch] : 0;
    };

    std::size_t jump_values[12];
    std::size_t num_jumps = 0;
    auto make_odd = [](std::size_t v) -> std::size_t { return v | 1; };

    jump_values[num_jumps++] = make_odd(M / 3 > 0 ? M / 3 : 1);
    jump_values[num_jumps++] = 1;
    jump_values[num_jumps++] = 3;
    jump_values[num_jumps++] = 5;
    jump_values[num_jumps++] = 7;
    jump_values[num_jumps++] = make_odd(M / 2 > 0 ? M / 2 : 1);
    jump_values[num_jumps++] = make_odd(M > 1 ? M - 1 : 1);
    jump_values[num_jumps++] = make_odd(M / 4 > 0 ? M / 4 : 1);
    jump_values[num_jumps++] = 9;
    jump_values[num_jumps++] = 11;
    jump_values[num_jumps++] = 13;
    jump_values[num_jumps++] = make_odd(M > 0 ? M : 1);

    // Reduced iteration budget from M*2000 to M*500 to keep consteval
    // compile times bounded. With power-of-2 table doubling, failing fast
    // on tight tables and retrying with 2x space is more efficient than
    // exhaustively searching a tight table.
    std::size_t max_iterations = M * 500;
    if (max_iterations < 2000) max_iterations = 2000;

    for (std::size_t ji = 0; ji < num_jumps; ++ji) {
        std::size_t jump = jump_values[ji];
        for (std::size_t i = 0; i < 256; ++i) asso_values[i] = 0;

        bool solved = false;
        for (std::size_t iter = 0; iter < max_iterations; ++iter) {
            bool has_collision = false;
            std::size_t col_a = 0, col_b = 0;

            std::array<std::size_t, M> slot_owner{};
            for (std::size_t s = 0; s < M; ++s) slot_owner[s] = N;

            for (std::size_t k = 0; k < N; ++k) {
                std::size_t h = compute(keys[k]);
                if (slot_owner[h] != N) {
                    col_a = slot_owner[h];
                    col_b = k;
                    has_collision = true;
                    break;
                }
                slot_owner[h] = k;
            }

            if (!has_collision) {
                solved = true;
                break;
            }

            std::size_t diff_pos = LAST_CHAR;
            for (std::size_t p = 0; p < num_positions; ++p) {
                std::size_t ca = char_at(keys[col_a], positions[p]);
                std::size_t cb = char_at(keys[col_b], positions[p]);
                if (ca != cb && (ca < 256 || cb < 256)) {
                    diff_pos = positions[p];
                    break;
                }
            }

            std::size_t ch_a = char_at(keys[col_a], diff_pos);
            std::size_t ch_b = char_at(keys[col_b], diff_pos);

            std::size_t bump_char;
            if (ch_a >= 256) {
                bump_char = ch_b;
            } else if (ch_b >= 256) {
                bump_char = ch_a;
            } else {
                bump_char = (char_frequency(ch_a) <= char_frequency(ch_b)) ? ch_a : ch_b;
            }

            if (bump_char < 256) {
                asso_values[bump_char] += jump;
            }
        }

        if (solved) {
            // Verify that the computed hash function produces a perfect hash: no collisions and all keys are assigned to unique slots.
            for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
            for (std::size_t i = 0; i < N; ++i) {
                std::size_t slot = compute(keys[i]);
                if (slot_to_key[slot] != N) return false;
                slot_to_key[slot] = i;
            }
            std::size_t filled = 0;
            for (std::size_t i = 0; i < M; ++i) {
                if (slot_to_key[i] != N) ++filled;
            }
            if (filled != N) return false;
            return true;
        }
    }

    return false;
}

// Throwing wrapper around try_generate_gperf.
template <std::size_t N, std::size_t M = N>
consteval void generate_gperf(
    const std::array<std::string_view, N>& keys,
    std::array<std::size_t, 256>& asso_values,
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
    std::array<std::size_t, 256> asso_values{};
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

    std::array<std::size_t, 256> asso{};
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
    std::array<std::size_t, 256>& asso_values,
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
        for (std::size_t i = 0; i < 256; ++i) asso_values[i] = 0;
        for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
        for (std::size_t i = 0; i < N; ++i) {
            std::size_t slot = keys[i].size() % M;
            if (slot_to_key[slot] != N) return false; // collision
            slot_to_key[slot] = i;
        }
        return true;
    }

    // Hash-and-Displace using a combined bucket key.
    //
    // To distinguish keys that share the same character at position[0] and
    // the same length (e.g., "case" and "char"), we use a COMBINED bucket key:
    //
    //   bucket = (char_at(key, pos[0]) * 17 + char_at(key, pos[1]) * 3 + key.size()) & 0xFF
    //
    // This maps each key to a bucket in [0, 255]. We store the displacement
    // in asso_values[bucket_index]. The runtime hash becomes:
    //
    //   h = asso_values[bucket_hash(key)] % M
    //
    // This requires compute_hash to know about the bucket hash mode.
    // We signal it by setting num_positions = 0 and positions[0] = LAST_CHAR+1
    // (a special sentinel), with the bucket hash parameters stored in positions[1..].
    //
    // ACTUALLY: The simplest compatible approach is to store a FLAT mapping
    // from key to slot in asso_values. Since N <= 255 and we have 256 entries,
    // we can map each key's "signature" (a single-byte hash) to its target slot.
    //
    // Runtime hash: h = asso_values[(key[pos0] + key[pos1] + key.size()) & 0xFF] % M
    //
    // This is NOT the standard gperf form. We need to modify compute_hash.
    // Let's use a clean approach: set num_positions to a sentinel value (e.g., 255)
    // to signal "H&D mode", then store the hash parameters.

    for (std::size_t i = 0; i < 256; ++i) asso_values[i] = 0;

    // Use position 0 (first char) and LAST_CHAR (last char) for the bucket hash.
    // These provide the best discrimination for typical key sets (identifiers,
    // tickers, keywords) where first and last characters vary the most.
    std::size_t pos0 = 0;
    std::size_t pos1 = LAST_CHAR;

    // Set num_positions = 0xFF to signal H&D mode to compute_hash.
    // Store the actual positions in positions[0] and positions[1].
    // compute_hash will detect num_positions == 0xFF and use:
    //   bucket = (char_at(key, pos[0]) + char_at(key, pos[1]) + key.size()) & 0xFF
    //   slot = asso_values[bucket] % M
    num_positions = 0xFF; // sentinel for H&D mode
    positions[0] = pos0;
    positions[1] = pos1;

    // Compute bucket for each key
    auto bucket_of = [&](std::string_view key) -> std::size_t {
        std::size_t c0 = char_at(key, pos0);
        std::size_t c1 = char_at(key, pos1);
        if (c0 >= 256) c0 = 0;
        if (c1 >= 256) c1 = 0;
        return (c0 + c1 * 3 + key.size() * 17) & 0xFF;
    };

    // Group by bucket
    std::array<std::size_t, N> key_bucket{};
    for (std::size_t i = 0; i < N; ++i)
        key_bucket[i] = bucket_of(keys[i]);

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

    // Initialize slots
    for (std::size_t i = 0; i < M; ++i) slot_to_key[i] = N;
    for (std::size_t i = 0; i < 256; ++i) asso_values[i] = 0;

    // For each bucket (largest first), find a displacement value d such that
    // (base_hash[key] + d) % M lands all keys on empty slots.
    for (std::size_t b = 0; b < num_buckets; ++b) {
        std::size_t ch = buckets[b].ch;

        // Collect key indices in this bucket
        std::array<std::size_t, N> bucket_keys{};
        std::size_t bk_count = 0;
        for (std::size_t i = 0; i < N; ++i) {
            if (key_bucket[i] == ch) bucket_keys[bk_count++] = i;
        }

        // Try displacement values d = 0, 1, ..., M*2-1.
        // H&D hash: slot = (d + key.size()*31 + key[0]) % M
        // The per-key contribution (key.size()*31 + key[0]) ensures keys
        // in the same bucket get different base offsets.
        bool placed = false;

        for (std::size_t d = 0; d < 255; ++d) {
            bool ok = true;
            std::array<std::size_t, N> bucket_slots{};
            for (std::size_t k = 0; k < bk_count; ++k) {
                auto& key = keys[bucket_keys[k]];
                // Per-key hash: polynomial of first 4 bytes. Used during
                // generation to find displacement values. Must match compute_hash.
                std::size_t kc = key.size();
                for (std::size_t ci = 0; ci < key.size() && ci < 4; ++ci)
                    kc = kc * 31 + static_cast<unsigned char>(key[ci]);
                std::size_t slot = (d + kc) % M;
                if (slot_to_key[slot] != N) { ok = false; break; }
                for (std::size_t k2 = 0; k2 < k; ++k2) {
                    if (bucket_slots[k2] == slot) { ok = false; break; }
                }
                if (!ok) break;
                bucket_slots[k] = slot;
            }

            if (ok) {
                asso_values[ch] = d;
                for (std::size_t k = 0; k < bk_count; ++k) {
                    slot_to_key[bucket_slots[k]] = bucket_keys[k];
                }
                placed = true;
                break;
            }
        }

        if (!placed) return false; // Could not place this bucket
    }

    // Verify all N keys are placed
    std::size_t filled = 0;
    for (std::size_t i = 0; i < M; ++i)
        if (slot_to_key[i] != N) ++filled;
    return filled == N;
}

// Try Hash-and-Displace for a specific table size M.
template <std::size_t N, std::size_t M>
consteval bool try_compute_phf_hd(
    const std::array<std::string_view, N>& keys,
    phf_result<N>& result)
{
    static_assert(M <= phf_result<N>::MAX_TABLE_SIZE, "Table size M exceeds maximum");

    std::array<std::size_t, 256> asso{};
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
// Uses Hash-and-Displace for N > 8 (fast consteval), gperf-style for N <= 8
// (produces tighter tables for small sets).
template <std::size_t N>
consteval phf_result<N> compute_phf(const std::array<std::string_view, N>& keys) {
    constexpr std::size_t StartM = next_power_of_2(N);
    if constexpr (N <= 15) {
        return compute_phf_po2<N, StartM>(keys);
    } else {
        return compute_phf_hd_po2<N, StartM>(keys);
    }
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H
