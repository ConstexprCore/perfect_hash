#ifndef CONSTEXPRCORE_DETAIL_PHF_GENERATOR_H
#define CONSTEXPRCORE_DETAIL_PHF_GENERATOR_H

#include <ConstexprCore/detail/seeded_hash.h>
#include <ConstexprCore/detail/seed_or_index.h>
#include <array>
#include <string_view>
#include <cstddef>

namespace ConstexprCore::detail {

template <std::size_t N>
consteval void generate_phf(
    const std::array<std::string_view, N>& keys,
    std::size_t& seed0,
    std::array<seed_or_index, N>& G,
    std::array<std::size_t, N>& slots)
{
    // slots[slot] = index into original keys array (declaration order)
    // G[bucket] = seed_or_index telling how to find the slot for keys in that bucket

    // Step 1: Find a primary seed that distributes keys into buckets.
    // We want no single bucket to be excessively large.
    // Try seeds 0..999.
    struct bucket_entry {
        std::size_t key_indices[N]{};
        std::size_t count{0};
    };

    bool found_seed0 = false;
    for (std::size_t try_seed = 0; try_seed < 1000; ++try_seed) {
        std::array<bucket_entry, N> buckets{};
        bool ok = true;
        for (std::size_t i = 0; i < N; ++i) {
            std::size_t b = seeded_fnv1a(keys[i], try_seed) % N;
            buckets[b].key_indices[buckets[b].count] = i;
            buckets[b].count++;
            // If any bucket has too many keys, skip this seed
            if (buckets[b].count > (N < 4 ? N : N / 2 + 2)) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        seed0 = try_seed;
        found_seed0 = true;
        break;
    }

    if (!found_seed0) throw "Failed to find primary seed for perfect hash";

    // Step 2: Distribute keys into buckets using selected seed0
    struct bucket_info {
        std::size_t key_indices[N]{};
        std::size_t count{0};
        std::size_t bucket_id{0};
    };

    std::array<bucket_info, N> buckets{};
    for (std::size_t i = 0; i < N; ++i) {
        buckets[i].bucket_id = i;
    }
    for (std::size_t i = 0; i < N; ++i) {
        std::size_t b = seeded_fnv1a(keys[i], seed0) % N;
        buckets[b].key_indices[buckets[b].count] = i;
        buckets[b].count++;
    }

    // Step 3: Sort buckets by size descending (bubble sort)
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = i + 1; j < N; ++j) {
            if (buckets[j].count > buckets[i].count) {
                auto tmp = buckets[i];
                buckets[i] = buckets[j];
                buckets[j] = tmp;
            }
        }
    }

    // Track which slots are occupied
    std::array<bool, N> occupied{};
    for (std::size_t i = 0; i < N; ++i) {
        occupied[i] = false;
        slots[i] = N; // sentinel
    }

    // Initialize G
    for (std::size_t i = 0; i < N; ++i) {
        G[i] = seed_or_index{0};
    }

    // Step 4: Process multi-key buckets (count >= 2)
    for (std::size_t bi = 0; bi < N; ++bi) {
        if (buckets[bi].count < 2) break; // sorted, so no more multi-key buckets

        bool found_d = false;
        for (std::size_t d = 1; d <= 100000; ++d) {
            // Try displacement seed d
            std::array<std::size_t, N> trial_slots{};
            std::size_t trial_count = 0;
            bool collision = false;

            for (std::size_t ki = 0; ki < buckets[bi].count; ++ki) {
                std::size_t key_idx = buckets[bi].key_indices[ki];
                std::size_t slot = seeded_fnv1a(keys[key_idx], static_cast<std::size_t>(d)) % N;

                if (occupied[slot]) {
                    collision = true;
                    break;
                }

                // Check for collision within this trial
                bool dup = false;
                for (std::size_t t = 0; t < trial_count; ++t) {
                    if (trial_slots[t] == slot) {
                        dup = true;
                        break;
                    }
                }
                if (dup) {
                    collision = true;
                    break;
                }

                trial_slots[trial_count++] = slot;
            }

            if (!collision) {
                // Accept this displacement seed
                for (std::size_t ki = 0; ki < buckets[bi].count; ++ki) {
                    std::size_t key_idx = buckets[bi].key_indices[ki];
                    std::size_t slot = trial_slots[ki];
                    occupied[slot] = true;
                    slots[slot] = key_idx;
                }
                G[buckets[bi].bucket_id] = seed_or_index::make_seed(d);
                found_d = true;
                break;
            }
        }

        if (!found_d) throw "Failed to find displacement seed for bucket";
    }

    // Step 5: Process single-key buckets (count == 1)
    for (std::size_t bi = 0; bi < N; ++bi) {
        if (buckets[bi].count != 1) continue;

        std::size_t key_idx = buckets[bi].key_indices[0];

        // Find first free slot
        for (std::size_t slot = 0; slot < N; ++slot) {
            if (!occupied[slot]) {
                occupied[slot] = true;
                slots[slot] = key_idx;
                G[buckets[bi].bucket_id] = seed_or_index::make_index(slot);
                break;
            }
        }
    }

    // Step 6: Validate all slots are filled
    for (std::size_t i = 0; i < N; ++i) {
        if (!occupied[i]) throw "Not all slots filled in perfect hash generation";
    }
}

} // namespace ConstexprCore::detail

#endif // CONSTEXPRCORE_DETAIL_PHF_GENERATOR_H
