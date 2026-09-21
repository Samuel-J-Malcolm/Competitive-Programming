# Topic-based organization plan for the competitive programming library

This repository should be organized by the actual algorithmic idea used in each solution, not by contest or filename style. The current layout mixes source-specific folders (`Kattis`, `CSES`, `topics`) with inconsistent names and duplicate files, which makes it harder to revisit solutions by concept.

## Findings from the code itself

The problem classification below is based on reading the implementations, not only on file names.

- [CSES/graph/Building_Roads.cpp](../CSES/graph/Building_Roads.cpp) is a graph connectivity problem using BFS/DFS to assign connected components.
- [CSES/graph/Message_Route.cpp](../CSES/graph/Message_Route.cpp) is also a graph problem: it builds an adjacency list and finds a path from node 1 to node n.
- [topics/graphs/quantumsuperposition.cpp](../topics/graphs/quantumsuperposition.cpp) is a graph/path-length problem and belongs alongside other graph algorithms, even though it is a Kattis problem and its name is not conventional.
- [topics/strings/1272C.cpp](../topics/strings/1272C.cpp) is a string/substring counting problem, which matches the string topic bucket.

These examples confirm the real rule: folder placement should follow the algorithmic concept of the implementation, and the repo should normalize names and duplicates accordingly.

## Problems in the current structure

1. Mixed source and topic organization
   - `Kattis` is currently empty, while many Kattis-style tasks are mixed into `topics/*`.
   - `topics/` contains both broad conceptual folders and ad hoc source-like buckets such as `basic`, `misc`, and `single_sweep`.

2. Generic bucket names hide actual content
   - `basic` contains a mix of easy implementation tasks, graphs, and formulas.
   - `misc` mixes unrelated problems such as simulation, combinatorics, and advanced contest tasks.
   - `single_sweep` is a valid technique bucket, but it does not match the rest of the repo’s naming scheme.

3. Duplicate and inconsistent naming
   - There are duplicate variants such as `Message_Route.cpp` vs `MessageRoute.cpp` and `Round_Trip.cpp` vs `RoundTrip.cpp`.
   - Some files use lowercase, underscores, spaces, and different casing in the same conceptual area.

4. Topic-first organization is missing
   - A person searching for a graph, DP, string, greedy, or number theory pattern should not need to inspect contest names or duplicates.

## Recommended structure

A cleaner layout is to organize by algorithmic concept first, with source metadata kept in each file header.

### Canonical high-level tree

```text
problems/
  archives/
    legacy_duplicates/
    old_names/
  topics/
    graph/
    strings/
    dynamic_programming/
    greedy/
    number_theory/
    data_structures/
    sorting/
    math/
    implementation/
    misc/
```

### Rule for placement

Each solution should be classified by the dominant technique used in the implementation:

- Graph: BFS, DFS, shortest path, connectivity, trees
- Strings: substring logic, pattern matching, character counting, palindrome/ASCII logic
- DP: state optimization, memoization, shortest path on DAGs, knapsack-style decisions
- Greedy: local-optimal choices and sorting-based construction
- Math/number theory: modular arithmetic, prime tests, combinatorics, divisibility
- Data structures: Fenwick, segment tree, ordered set, map, queue, stack, trie
- Sorting: ordering, buckets, pair comparisons, stable sort
- Implementation: simulation, simple brute force, geometry, edge-case handling

## Migration plan

### Phase 1: audit and classify every file

- Read each .cpp source and tag it by problem type from its actual logic.
- Avoid moving files purely by their names.
- Keep a spreadsheet or markdown table with: source, file name, expected topic, evidence from code.

### Phase 2: normalize names and remove duplicates

- Standardize to a single naming convention, e.g. `problem_name.cpp`.
- Resolve duplicates by keeping the best version and moving older copies into `archives/legacy_duplicates/`.
- Preserve the original source link in the top comment block.

### Phase 3: build the topic-based folder layout

- Create consistent directories under `topics/` or `problems/`.
- Move solutions into the relevant topic bucket.
- Do not keep `Kattis` and `CSES` as source-labeled partitions, make the topic bucket the primary navigation path.

### Phase 4: add index documentation

- Add a root `README.md` section listing the canonical topic folders.
- Add a short topic README in each folder describing the common patterns and links to sample files.
- Record which files are from Kattis, CSES, or custom contest sources.

### Phase 5: validation

- Rebuild all C++ files after moves to ensure no broken references or compile issues.
- Check for duplicate names and outdated problem links.
- Keep metadata consistent (`Link`, `Platform`, `Topic`, `Difficulty`).

## Suggested implementation priority

1. `graphs/` and `strings/` first, because they already contain the clearest real examples.
2. `dp/`, `greedy/`, `math/`, and `sorting/` next.
3. `basic/`, `misc/`, and `single_sweep/` last, because they are the mixed buckets and need a more careful split.

## Outcome

This will make the repository easier to use for training: a person can look up a topic (graph, strings, DP, greedy, number theory) and immediately find the relevant implementations without needing to know where each file originally came from.

The repository’s value is not in the source name, but in the underlying technique. The folder layout should reflect that.
