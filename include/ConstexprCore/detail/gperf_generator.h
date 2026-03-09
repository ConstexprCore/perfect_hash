#ifndef CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H
#define CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H

#include <array>
#include <string_view>
#include <cstddef>

namespace ConstexprCore::detail {

static constexpr std::size_t MAX_POSITIONS = 16;
static constexpr std::size_t LAST_CHAR = std::size_t(-1);

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
        std::size_t budget = 50000;
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

    auto char_frequency = [&](std::size_t ch) -> std::size_t {
        if (ch >= 256) return 0;
        std::size_t freq = 0;
        for (std::size_t k = 0; k < N; ++k) {
            for (std::size_t p = 0; p < num_positions; ++p) {
                if (char_at(keys[k], positions[p]) == ch) {
                    ++freq;
                    break;
                }
            }
        }
        return freq;
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

    std::size_t max_iterations = M * 2000;
    if (max_iterations < 5000) max_iterations = 5000;

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
    static constexpr std::size_t MAX_TABLE_SIZE = N + N / 2 + 1;
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

// Recursive template: try M, M+1, ..., MaxM until one succeeds.
// Note: each `if constexpr` branch instantiates the next template, so this
// produces up to (MaxM - N) instantiations. Only one branch executes at
// runtime. This is acceptable for practical key set sizes.
template <std::size_t N, std::size_t M, std::size_t MaxM>
consteval phf_result<N> compute_phf_impl(
    const std::array<std::string_view, N>& keys)
{
    phf_result<N> result{};
    if (try_compute_phf<N, M>(keys, result)) {
        return result;
    }

    if constexpr (M + 1 <= MaxM) {
        return compute_phf_impl<N, M + 1, MaxM>(keys);
    } else {
        throw "Failed to find a valid table size for perfect hash (tried up to 1.5x key count)";
    }
}

// Compute PHF for the given keys, trying table sizes from N up to ~1.5*N.
// Returns a phf_result containing all computed data (no recomputation needed).
template <std::size_t N>
consteval phf_result<N> compute_phf(const std::array<std::string_view, N>& keys) {
    constexpr std::size_t MaxM = N + N / 2 + 1;
    return compute_phf_impl<N, N, MaxM>(keys);
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_GPERF_GENERATOR_H
