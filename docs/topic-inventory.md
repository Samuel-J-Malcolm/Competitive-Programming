# Current topic inventory

This inventory records the current source tree before any moves. Counts are based on `.cpp` files under `Kattis`, `CSES`, and `topics` on 2026-09-22.

## Scope snapshot

- Total C++ sources: 152
- `Kattis`: 0 C++ sources
- `CSES/graph`: 8 C++ sources
- `topics/algorithms`: 5 C++ sources
- `topics/basic`: 28 C++ sources
- `topics/dp`: 6 C++ sources
- `topics/games`: 2 C++ sources
- `topics/graphs`: 7 C++ sources
- `topics/greedy`: 34 C++ sources
- `topics/math`: 20 C++ sources
- `topics/misc`: 4 C++ sources
- `topics/queries`: 2 C++ sources
- `topics/single_sweep`: 8 C++ sources
- `topics/sorting`: 3 C++ sources
- `topics/strings`: 25 C++ sources

The current directory counts show why `basic`, `misc`, and `single_sweep` need an implementation-level audit before they are renamed or split.

## First migration batch: CSES graph solutions

All eight files in `CSES/graph` are graph solutions based on their source code and problem links. The first migration should compare the duplicate pairs before retaining one canonical file:

| Canonical problem | Current files | Code-level topic |
|---|---|---|
| Building Teams | `BuildingTeams.cpp`, `Building_Teams.cpp` | Graph bipartite checking / BFS or DFS coloring |
| Message Route | `MessageRoute.cpp`, `Message_Route.cpp` | Unweighted graph BFS and path reconstruction |
| Round Trip | `RoundTrip.cpp`, `Round_Trip.cpp` | Undirected graph cycle detection |
| Building Roads | `Building_Roads.cpp` | Connected components and representative edges |
| Monsters | `Monsters.cpp` | Grid BFS with danger-time constraints |

Before deleting or archiving any duplicate, compare the complete implementations and compile the retained version. A filename match alone is not enough because the variants may contain different fixes or metadata.

## Duplicate-name groups detected

Case-insensitive, underscore-insensitive filename matching found these groups across the requested roots:

- `BuildingTeams`: `CSES/graph/BuildingTeams.cpp`, `CSES/graph/Building_Teams.cpp`
- `MessageRoute`: `CSES/graph/MessageRoute.cpp`, `CSES/graph/Message_Route.cpp`
- `RoundTrip`: `CSES/graph/RoundTrip.cpp`, `CSES/graph/Round_Trip.cpp`
- `1692F`: present in `topics/greedy/brute_force/` and `topics/strings/`
- `1692G`: present in `topics/single_sweep/` and `topics/strings/`
- `1692H`: present in `topics/misc/` and `topics/strings/`
- `1790E`: present in `topics/algorithms/bit_manipulation/` and `topics/strings/`
- `1881C`: present in `topics/greedy/constructive/` and `topics/strings/`

The numeric duplicate groups require source-code comparison because Codeforces identifiers can legitimately appear in different local copies or represent an accidental duplicate. They should not be removed automatically.

## Proposed first move sequence

1. Compare each CSES duplicate pair line by line.
2. Compile both variants with `g++-13` and retain the version with the correct behavior and complete metadata.
3. Move only confirmed duplicate copies to `archives/legacy_duplicates/cses_graph/` in a separate change.
4. Move the retained graph solutions into the canonical graph topic directory only after the duplicate decision is reviewed.
5. Repeat the same evidence-based process for `topics/strings`, `topics/greedy`, and `topics/single_sweep`.

No source files are moved by this inventory change; it establishes the evidence needed to make each later move reversible and reviewable.
