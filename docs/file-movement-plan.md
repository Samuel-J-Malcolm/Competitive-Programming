# Per-file movement plan

This is the executed movement map for every C++ file under the former `Kattis`, `CSES`, and `topics` roots. Each file was inspected individually and classified by the implementation's dominant technique. The moves preserve source content and metadata while separating canonical solutions, review items, and duplicate archives.

## Destination policy

- Proposed canonical destinations are relative to a future `problems/` root.
- Source platform is preserved in the file header, not in the primary directory path.
- Duplicate candidates move to `problems/archives/legacy_duplicates/` only after a line-by-line comparison and independent compilation.
- Incomplete or unsafe files move to `problems/review/` first, not into the canonical solved-topic tree.
- The original filename is retained during the first move. Renaming is a separate, reviewable change.

## CSES graph

| Current file | Proposed destination | Action |
|---|---|---|
| `CSES/graph/BuildingTeams.cpp` | `problems/archives/legacy_duplicates/cses_graph/BuildingTeams.cpp` | Archive after retaining linked underscore variant |
| `CSES/graph/Building_Teams.cpp` | `problems/graph/bipartite/Building_Teams.cpp` | Retain linked implementation |
| `CSES/graph/Building_Roads.cpp` | `problems/graph/connectivity/Building_Roads.cpp` | Canonical graph placement |
| `CSES/graph/MessageRoute.cpp` | `problems/archives/legacy_duplicates/cses_graph/MessageRoute.cpp` | Archive after retaining linked underscore variant |
| `CSES/graph/Message_Route.cpp` | `problems/graph/shortest_path/Message_Route.cpp` | Retain linked implementation |
| `CSES/graph/RoundTrip.cpp` | `problems/archives/legacy_duplicates/cses_graph/RoundTrip.cpp` | Archive after retaining linked underscore variant |
| `CSES/graph/Round_Trip.cpp` | `problems/graph/cycles/Round_Trip.cpp` | Retain linked implementation |
| `CSES/graph/Monsters.cpp` | `problems/review/graph/grid_bfs/Monsters.cpp` | Review unusual monster-distance logic before canonical move |

`Kattis/` currently contains no C++ files and requires no movement in this batch.

## topics/algorithms

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/algorithms/2232C1.cpp` | `problems/greedy/optimization/2232C1.cpp` | Move after confirming capacity-choice logic |
| `topics/algorithms/2236B.cpp` | `problems/bit_manipulation/xor/2236B.cpp` | Move by implementation |
| `topics/algorithms/abc469d.cpp` | `problems/math/combinatorics/abc469d.cpp` | Move by interval-counting logic |
| `topics/algorithms/bit_manipulation/1790E.cpp` | `problems/bit_manipulation/construction/1790E.cpp` | Compare with strings copy |
| `topics/algorithms/bit_manipulation/2245C.cpp` | `problems/bit_manipulation/construction/2245C.cpp` | Move by bitwise construction |

## topics/basic

| Current file | Proposed destination |
|---|---|
| `topics/basic/2241A.cpp` | `problems/math/divisibility/2241A.cpp` |
| `topics/basic/2241B.cpp` | `problems/implementation/string_construction/2241B.cpp` |
| `topics/basic/2252A.cpp` | `problems/math/frequency_count/2252A.cpp` |
| `topics/basic/2253A.cpp` | `problems/math/number_theory/primality/2253A.cpp` |
| `topics/basic/A.cpp` | `problems/greedy/run_processing/A.cpp` |
| `topics/basic/Adding_Dice.cpp` | `problems/implementation/Adding_Dice.cpp` |
| `topics/basic/Average_Permutation.cpp` | `problems/constructive/Average_Permutation.cpp` |
| `topics/basic/Average_Survival.cpp` | `problems/implementation/frequency/Average_Survival.cpp` |
| `topics/basic/B.cpp` | `problems/greedy/prefix_sum/B.cpp` |
| `topics/basic/Bishop_Moves.cpp` | `problems/math/geometry/Bishop_Moves.cpp` |
| `topics/basic/Bus_Rows.cpp` | `problems/math/indexing/Bus_Rows.cpp` |
| `topics/basic/Carrot_Collection.cpp` | `problems/greedy/prefix_sum/Carrot_Collection.cpp` |
| `topics/basic/Dividing_by_2.cpp` | `problems/greedy/number_operations/Dividing_by_2.cpp` |
| `topics/basic/Jumping_Cost.cpp` | `problems/dp/array/Jumping_Cost.cpp` |
| `topics/basic/Pass.cpp` | `problems/implementation/counting/Pass.cpp` |
| `topics/basic/Passing_Chain.cpp` | `problems/math/modular_arithmetic/Passing_Chain.cpp` |
| `topics/basic/Presentation.cpp` | `problems/math/arithmetic/Presentation.cpp` |
| `topics/basic/Subscription_Cost.cpp` | `problems/math/formulas/Subscription_Cost.cpp` |
| `topics/basic/Swap_Small.cpp` | `problems/constructive/Swap_Small.cpp` |
| `topics/basic/Teleport_Home.cpp` | `problems/math/intervals/Teleport_Home.cpp` |
| `topics/basic/The_Cooler_Dilemma_2.cpp` | `problems/greedy/frequency/The_Cooler_Dilemma_2.cpp` |
| `topics/basic/abc467a.cpp` | `problems/math/inequality/abc467a.cpp` |
| `topics/basic/abc467b.cpp` | `problems/implementation/abc467b.cpp` |
| `topics/basic/abc467c.cpp` | `problems/implementation/modular_simulation/abc467c.cpp` |
| `topics/basic/abc468a.cpp` | `problems/review/implementation/abc468a.cpp` |
| `topics/basic/abc469a.cpp` | `problems/math/arithmetic/abc469a.cpp` |
| `topics/basic/abc470a.cpp` | `problems/implementation/fizz_buzz/abc470a.cpp` |
| `topics/basic/abc470b.cpp` | `problems/implementation/simulation/abc470b.cpp` |

`abc468a.cpp` is held for review because the implementation accesses `v[i - 1]` when `i == 0`.

## topics/dp

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/dp/binary_search/706B.cpp` | `problems/data_structures/binary_search/706B.cpp` | Move by actual search implementation |
| `topics/dp/binary_search/1794C.cpp` | `problems/dp/binary_search/1794C.cpp` | Keep as DP/search variant |
| `topics/dp/other/Subsequence_1.cpp` | `problems/dp/sequences/Subsequence_1.cpp` | Move by sequence state |
| `topics/dp/other/Subsequence_2.cpp` | `problems/review/dp/Subsequence_2.cpp` | Empty solver; do not classify as complete |
| `topics/dp/other/2230D.cpp` | `problems/dp/sequence_counting/2230D.cpp` | Move after normal compile check |
| `topics/dp/other/2237C.cpp` | `problems/review/greedy/2237C.cpp` | Review mutation loop for termination |

## topics/games

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/games/1931E.cpp` | `problems/games/greedy/1931E.cpp` | Move by game strategy |
| `topics/games/869A.cpp` | `problems/review/games/869A.cpp` | Review because only half the input appears to be processed |

## topics/graphs

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/graphs/Grouping/Group_Formation.cpp` | `problems/graph/connectivity/Group_Formation.cpp` | Move by component traversal |
| `topics/graphs/Grouping/Counting_Rooms.cpp` | `problems/review/graph/grid_components/Counting_Rooms.cpp` | Review blocked-cell/component accounting |
| `topics/graphs/trees/1857D.cpp` | `problems/greedy/array_extrema/1857D.cpp` | Move by implementation; not a tree algorithm |
| `topics/graphs/trees/1843C.cpp` | `problems/math/recurrence/1843C.cpp` | Move by recurrence; not a tree traversal |
| `topics/graphs/abc470d.cpp` | `problems/review/graph/permutations/abc470d.cpp` | Incomplete: reads cycles but produces no output |
| `topics/graphs/dfs/Labyrinth.cpp` | `problems/graph/grid_bfs/Labyrinth.cpp` | Move by actual BFS |
| `topics/graphs/quantumsuperposition.cpp` | `problems/graph/path_length/quantumsuperposition.cpp` | Move by Kattis graph/path-length logic |

## topics/greedy

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/greedy/constructive/1844D.cpp` | `problems/constructive/periodic_strings/1844D.cpp` | Move by construction |
| `topics/greedy/constructive/1881C.cpp` | `problems/greedy/matrix_rotation/1881C.cpp` | Retain canonical copy |
| `topics/greedy/constructive/1980C.cpp` | `problems/greedy/array_replacement/1980C.cpp` | Move by greedy replacement |
| `topics/greedy/constructive/2200D.cpp` | `problems/constructive/array_transformation/2200D.cpp` | Move by construction |
| `topics/greedy/constructive/2202B.cpp` | `problems/greedy/string_balance/2202B.cpp` | Move by string balance logic |
| `topics/greedy/constructive/2218C.cpp` | `problems/constructive/sequence_generation/2218C.cpp` | Move by construction |
| `topics/greedy/constructive/2224C.cpp` | `problems/constructive/array_generation/2224C.cpp` | Move by construction |
| `topics/greedy/constructive/2228A.cpp` | `problems/greedy/frequency/2228A.cpp` | Move by frequency logic |
| `topics/greedy/constructive/2234C.cpp` | `problems/greedy/circular_array/2234C.cpp` | Move by circular-array logic |
| `topics/greedy/constructive/1660E.cpp` | `problems/greedy/matrix_rotation/1660E.cpp` | Move by matrix rotation |
| `topics/greedy/sortings/1876A.cpp` | `problems/greedy/sorting/minimum_cost/1876A.cpp` | Move by sorted cost selection |
| `topics/greedy/sortings/2224B.cpp` | `problems/greedy/sorting/mex/2224B.cpp` | Move by sorting/mex logic |
| `topics/greedy/sortings/Make_Distinct.cpp` | `problems/greedy/sorting/coordinate_adjustment/Make_Distinct.cpp` | Move by sorted adjustment |
| `topics/greedy/prefix_sum/1927D.cpp` | `problems/arrays/run_boundaries/1927D.cpp` | Move by run-boundary scan |
| `topics/greedy/prefix_sum/2242B.cpp` | `problems/prefix_sum/segment_detection/2242B.cpp` | Move by prefix/suffix detection |
| `topics/greedy/prefix_sum/D.cpp` | `problems/prefix_sum/weighted_positions/D.cpp` | Move after problem metadata review |
| `topics/greedy/combinatorics/abc468c.cpp` | `problems/combinatorics/permutation_rank/abc468c.cpp` | Move by permutation counting |
| `topics/greedy/combinatorics/1879C.cpp` | `problems/combinatorics/run_lengths/1879C.cpp` | Move by run-length combinatorics |
| `topics/greedy/misc/1914D.cpp` | `problems/greedy/top_k_selection/1914D.cpp` | Move by top-k selection |
| `topics/greedy/misc/1915E.cpp` | `problems/prefix_sum/repeated_sum/1915E.cpp` | Move by repeated-prefix logic |
| `topics/greedy/misc/2208C.cpp` | `problems/dp/optimization/2208C.cpp` | Move by optimization state, not greedy bucket |
| `topics/greedy/misc/2228B.cpp` | `problems/greedy/circular_distance/2228B.cpp` | Move by circular distance |
| `topics/greedy/misc/2252C.cpp` | `problems/greedy/danger_threshold/2252C.cpp` | Move by threshold logic |
| `topics/greedy/misc/2253B.cpp` | `problems/greedy/run_counting/2253B.cpp` | Move by run counting |
| `topics/greedy/misc/2254E.cpp` | `problems/greedy/ordered_selection/2254E.cpp` | Move by ordered selection |
| `topics/greedy/brute_force/25A.cpp` | `problems/implementation/parity/25A.cpp` | Move by parity scan |
| `topics/greedy/brute_force/875A.cpp` | `problems/brute_force/digit_sum/875A.cpp` | Move by digit-sum search |
| `topics/greedy/brute_force/1692F.cpp` | `problems/brute_force/modular_frequency/1692F.cpp` | Retain canonical copy |
| `topics/greedy/brute_force/1919C.cpp` | `problems/greedy/two_state_sequence/1919C.cpp` | Move by two-state greedy |
| `topics/greedy/brute_force/2117E.cpp` | `problems/arrays/nearest_conflict/2117E.cpp` | Move by nearest-conflict scan |
| `topics/greedy/brute_force/2224A.cpp` | `problems/brute_force/array_reduction/2224A.cpp` | Move by operation search |
| `topics/greedy/brute_force/2236C.cpp` | `problems/brute_force/operation_search/2236C.cpp` | Move by operation search |
| `topics/greedy/brute_force/2237B.cpp` | `problems/greedy/sequence_matching/2237B.cpp` | Move by sequence matching |
| `topics/greedy/brute_force/2252D.cpp` | `problems/greedy/local_adjustment/2252D.cpp` | Move by local adjustment |

## topics/math

| Current file | Proposed destination |
|---|---|
| `topics/math/implementation/1846E1.cpp` | `problems/math/geometric_series/1846E1.cpp` |
| `topics/math/implementation/1883C.cpp` | `problems/math/modular_arithmetic/1883C.cpp` |
| `topics/math/implementation/2230B.cpp` | `problems/math/prefix_balance/2230B.cpp` |
| `topics/math/implementation/2233A.cpp` | `problems/math/counting/2233A.cpp` |
| `topics/math/implementation/2233B.cpp` | `problems/constructive/2233B.cpp` |
| `topics/math/implementation/Chocolate_Game.cpp` | `problems/math/parity/Chocolate_Game.cpp` |
| `topics/math/number_theory/1360D.cpp` | `problems/math/number_theory/divisors/1360D.cpp` |
| `topics/math/number_theory/1881D.cpp` | `problems/math/number_theory/prime_factors/1881D.cpp` |
| `topics/math/number_theory/1909B.cpp` | `problems/math/number_theory/gcd_powers/1909B.cpp` |
| `topics/math/number_theory/1931D.cpp` | `problems/math/modular_pairs/1931D.cpp` |
| `topics/math/number_theory/2200E.cpp` | `problems/games/number_theory/2200E.cpp` |
| `topics/math/number_theory/2218D.cpp` | `problems/math/constructive/2218D.cpp` |
| `topics/math/number_theory/2236A.cpp` | `problems/math/range_counting/2236A.cpp` |
| `topics/math/number_theory/2238D.cpp` | `problems/math/prime_factorization/2238D.cpp` |
| `topics/math/number_theory/2246C.cpp` | `problems/combinatorics/frequency/2246C.cpp` |
| `topics/math/number_theory/Make_Multiple.cpp` | `problems/math/gcd/Make_Multiple.cpp` |
| `topics/math/number_theory/C.cpp` | `problems/games/prime_factors/C.cpp` |
| `topics/math/number_theory/abc468e.cpp` | `problems/review/math/modular_inverses/abc468e.cpp` |
| `topics/math/construction/1794B.cpp` | `problems/math/constructive/divisibility/1794B.cpp` |
| `topics/math/construction/2117D.cpp` | `problems/math/constructive/linear_transform/2117D.cpp` |

`abc468e.cpp` requires formula validation before it is treated as a canonical solved solution.

## topics/sorting

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/sorting/Apartments.cpp` | `problems/greedy/sorting/two_pointer_matching/Apartments.cpp` | Review debug-style output first |
| `topics/sorting/distinct_numbers.cpp` | `problems/data_structures/set/distinct_numbers.cpp` | Move by set usage |
| `topics/sorting/2247D1.cpp` | `problems/sorting/group_ordering/2247D1.cpp` | Move by ordering logic |

## topics/strings

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/strings/2125A.cpp` | `problems/strings/reordering/2125A.cpp` | Move by character reordering |
| `topics/strings/2200C.cpp` | `problems/strings/reduction/2200C.cpp` | Move by string reduction |
| `topics/strings/1881C.cpp` | `problems/archives/legacy_duplicates/1881C/strings.cpp` | Archive identical copy |
| `topics/strings/brackets/2233C.cpp` | `problems/strings/brackets/2233C.cpp` | Move by bracket parsing |
| `topics/strings/abc468b.cpp` | `problems/review/strings/coverage/abc468b.cpp` | Definite compile issue: `ll(n);` |
| `topics/strings/Binary_Split.cpp` | `problems/strings/binary_split/Binary_Split.cpp` | Move by split logic |
| `topics/strings/Binary_Split_Hard.cpp` | `problems/strings/binary_split/Binary_Split_Hard.cpp` | Keep beside easy variant |
| `topics/strings/2207A.cpp` | `problems/strings/binary_palindrome/2207A.cpp` | Move by palindrome logic |
| `topics/strings/520B.cpp` | `problems/greedy/shortest_operations/520B.cpp` | Move by operation strategy |
| `topics/strings/1272C.cpp` | `problems/strings/substrings/1272C.cpp` | Move by substring counting |
| `topics/strings/2242A.cpp` | `problems/strings/counting/2242A.cpp` | Move by character counting |
| `topics/strings/A.cpp` | `problems/strings/distinct_prefixes/A.cpp` | Move by prefix logic |
| `topics/strings/1692F.cpp` | `problems/archives/legacy_duplicates/1692F/strings.cpp` | Archive identical copy |
| `topics/strings/1917B.cpp` | `problems/strings/binary_split/1917B.cpp` | Move by split logic |
| `topics/strings/abc468d.cpp` | `problems/strings/palindromic_substrings/abc468d.cpp` | Move by palindrome logic |
| `topics/strings/1794A.cpp` | `problems/strings/reconstruction/1794A.cpp` | Move by reconstruction |
| `topics/strings/b.CPP` | `problems/math/perfect_square/b.CPP` | Normalize extension in later rename pass |
| `topics/strings/1913B.cpp` | `problems/strings/binary_split/1913B.cpp` | Move by split logic |
| `topics/strings/1692H.cpp` | `problems/strings/frequency_subarray/1692H.cpp` | Retain canonical copy |
| `topics/strings/1790E.cpp` | `problems/archives/legacy_duplicates/1790E/strings.cpp` | Archive identical copy |
| `topics/strings/abc469b.cpp` | `problems/strings/run_counting/abc469b.cpp` | Move by run counting |
| `topics/strings/C.cpp` | `problems/strings/binary_split/C.cpp` | Move by split logic |
| `topics/strings/2252B.cpp` | `problems/strings/binary_balance/2252B.cpp` | Move by binary balance |
| `topics/strings/1692G.cpp` | `problems/archives/legacy_duplicates/1692G/strings.cpp` | Archive identical copy |
| `topics/strings/D.cpp` | `problems/review/math/geometry/D.cpp` | Review quadratic-form context before move |

## topics/misc

| Current file | Proposed destination | Action |
|---|---|---|
| `topics/misc/1028G.cpp` | `problems/greedy/top_two_tracking/1028G.cpp` | Move by top-two tracking |
| `topics/misc/1692H.cpp` | `problems/archives/legacy_duplicates/1692H/misc.cpp` | Archive identical copy |
| `topics/misc/2252E.cpp` | `problems/review/incomplete/2252E.cpp` | Empty solver |
| `topics/misc/2253C.cpp` | `problems/review/incomplete/2253C.cpp` | Empty solver |

## topics/queries

| Current file | Proposed destination |
|---|---|
| `topics/queries/abc470c.cpp` | `problems/queries/dynamic_multiset_xor/abc470c.cpp` |
| `topics/queries/E.cpp` | `problems/queries/binary_search/E.cpp` |

## topics/single_sweep

| Current file | Proposed destination |
|---|---|
| `topics/single_sweep/1692G.cpp` | `problems/arrays/adjacent_growth/1692G.cpp` | Retain canonical copy |
| `topics/single_sweep/2051E.cpp` | `problems/greedy/sweep_line/2051E.cpp` |
| `topics/single_sweep/2237A.cpp` | `problems/greedy/prefix_minimum/2237A.cpp` |
| `topics/single_sweep/2240C.cpp` | `problems/bit_manipulation/xor/2240C.cpp` |
| `topics/single_sweep/2241C.cpp` | `problems/greedy/array_transfer/2241C.cpp` |
| `topics/single_sweep/2241D.cpp` | `problems/greedy/array_transfer/2241D.cpp` |
| `topics/single_sweep/2242C.cpp` | `problems/greedy/run_lengths/2242C.cpp` |
| `topics/single_sweep/abc469c.cpp` | `problems/greedy/simulation/abc469c.cpp` |

## Execution status

1. Completed: freeze the source tree and inventory all 152 source paths.
2. Completed: compare the CSES underscore/non-underscore pairs.
3. Completed: compare the duplicate Codeforces-number families (`1692F`, `1692G`, `1692H`, `1790E`, and `1881C`).
4. Completed: move canonical files while preserving their original names and metadata.
5. Completed: move incomplete or unsafe files into `problems/review/` and duplicate copies into `problems/archives/legacy_duplicates/`.
6. In progress: compile every migrated C++ source and record pre-existing source failures separately from move errors.
7. Pending: normalize names and extensions in a separate follow-up change.

## Review blockers before movement

- Confirm whether duplicate files are byte-identical or merely solve the same problem.
- Repair or explicitly quarantine incomplete files before publishing the canonical tree.
- Resolve the `abc468b.cpp` compile error and inspect the flagged out-of-bounds/debug-output cases.
- Decide whether the future root should be `problems/` or a renamed existing `topics/` tree before executing path changes.

This staged approach keeps the movement auditable: every source has a proposed destination, every duplicate has a comparison rule, and every known risk is prevented from silently entering the canonical topic tree.
