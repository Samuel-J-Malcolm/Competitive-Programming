# Topic-based organization plan for the competitive programming library

This repository should be organized by the actual algorithmic idea used in each solution, not by contest or filename style. The current layout mixes source-specific folders (`Kattis`, `CSES`, `topics`) with inconsistent names and duplicate files, which makes it harder to revisit solutions by concept.

## Findings from the code itself

The problem classification below is based on reading the implementations, not only on file names.

- [CSES/graph/Building_Roads.cpp](../CSES/graph/Building_Roads.cpp) is a graph connectivity problem using BFS/DFS to assign connected components.
- [CSES/graph/Message_Route.cpp](../CSES/graph/Message_Route.cpp) is also a graph problem: it builds an adjacency list and finds a path from node 1 to node n.
- [topics/graphs/quantumsuperposition.cpp](../topics/graphs/quantumsuperposition.cpp) is a graph/path-length problem and belongs alongside other graph algorithms, even though it is a Kattis problem and its name is not conventional.
- [topics/strings/1272C.cpp](../topics/strings/1272C.cpp) is a string/substring counting problem, which matches the string topic bucket.
- The current `topics/basic` directory is not a true category; it contains many small tasks such as [topics/basic/Bus_Rows.cpp](../topics/basic/Bus_Rows.cpp), [topics/basic/Teleport_Home.cpp](../topics/basic/Teleport_Home.cpp), and [topics/basic/Passing_Chain.cpp](../topics/basic/Passing_Chain.cpp), which are implementation-heavy and should be split by technique rather than left under one generic bucket.
- The current `topics/misc` directory is similarly mixed and includes unrelated or contest-specific files such as [topics/misc/1028G.cpp](../topics/misc/1028G.cpp), [topics/misc/1692H.cpp](../topics/misc/1692H.cpp), and [topics/misc/A_Forked.py](../topics/misc/A_Forked.py), which do not form a coherent canonical topic.
- The current `topics/single_sweep` directory contains files like [topics/single_sweep/1692G.cpp](../topics/single_sweep/1692G.cpp), [topics/single_sweep/2241C.cpp](../topics/single_sweep/2241C.cpp), and [topics/single_sweep/abc469c.cpp](../topics/single_sweep/abc469c.cpp), which are better grouped under algorithmic techniques or more specific categories than a generic one-off folder.

These examples confirm the real rule: folder placement should follow the algorithmic concept of the implementation, and the repo should normalize names and duplicates accordingly.

## Concrete category mapping from the current repo

The following examples illustrate how the current repository should be reclassified:

- Graph / connectivity / shortest path: [CSES/graph/Building_Roads.cpp](../CSES/graph/Building_Roads.cpp), [CSES/graph/Message_Route.cpp](../CSES/graph/Message_Route.cpp), [topics/graphs/abc470d.cpp](../topics/graphs/abc470d.cpp), [topics/graphs/quantumsuperposition.cpp](../topics/graphs/quantumsuperposition.cpp)
- Strings / counting / substring logic: [topics/strings/1272C.cpp](../topics/strings/1272C.cpp), [topics/strings/1692F.cpp](../topics/strings/1692F.cpp), [topics/strings/1790E.cpp](../topics/strings/1790E.cpp), [topics/strings/2125A.cpp](../topics/strings/2125A.cpp)
- Sorting / ordering / pair logic: [topics/sorting/2247D1.cpp](../topics/sorting/2247D1.cpp), [topics/sorting/Apartments.cpp](../topics/sorting/Apartments.cpp), [topics/sorting/distinct_numbers.cpp](../topics/sorting/distinct_numbers.cpp)
- Implementation / easy contest tasks: [topics/basic/Adding_Dice.cpp](../topics/basic/Adding_Dice.cpp), [topics/basic/Swap_Small.cpp](../topics/basic/Swap_Small.cpp), [topics/basic/Dividing_by_2.cpp](../topics/basic/Dividing_by_2.cpp)
- Greedy / construction / optimization: files in the current `topics/greedy` folders should remain grouped together, but the generic labels should be normalized and the naming pattern should match the actual solution concept.

This classification makes the same point as the repo-wide audit: source origin (`Kattis`, `CSES`, `topics`) is not a reliable organization key, while the actual algorithmic technique is.

The current file counts and the first proposed migration batch are recorded in
[docs/topic-inventory.md](topic-inventory.md). That inventory deliberately
separates evidence gathering from file moves so duplicate solutions can be
compared and compiled before anything is archived.

The complete per-file destination map is recorded in
[docs/file-movement-plan.md](file-movement-plan.md). It covers all 152 current
C++ sources and marks duplicate, incomplete, and review-needed files so they
are not moved into the canonical tree without a separate decision.

## Concrete migration map for the current repo

The repo can be moved in a controlled sequence without losing any problem solutions:

- `CSES/graph/` should remain under a graph-focused bucket, but the folder name should be normalized to a topic-first structure such as `topics/graph/` or `problems/graph/` rather than being defined by source.
- `topics/graphs/` should be treated as the canonical graph folder for all graph problems, regardless of whether the original source was Kattis, CSES, or a custom contest.
- `topics/strings/` should become a canonical string-processing bucket and absorb related tasks currently spread across `basic`, `misc`, and miscellaneous contest-only files.
- `topics/sorting/` is already close to a concept bucket and should be retained as a sorting-focused directory, with names normalized to consistent `problem_name.cpp` format.
- `topics/basic/` should be split into meaningful subcategories such as implementation, easy cases, and simple brute force, rather than left as a catch-all bucket.
- `topics/misc/` should be reviewed carefully and either split into valid topic buckets or archived if the file is only a one-off contest dump.
- `topics/single_sweep/` should be reorganized into a proper algorithmic grouping (for example, prefix/suffix or monotonic sweep technique) rather than a generic folder name.
- `topics/algorithms/` and `topics/greedy/` should be preserved as conceptual collections, but each file should be checked against the technique actually used by the code and not just by the filename.

## Execution checklist

1. Sort every file by the real algorithm it uses, not by the platform it came from.
2. Move duplicates into `archives/legacy_duplicates/` and keep the best implementation.
3. Rename files to a single consistent pattern, ideally `problem_name.cpp`.
4. Keep metadata headers (`Link`, `Platform`, `Topic`) intact when moving files.
5. Recompile the sources after the move to confirm the folder migration did not break any solution.

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
