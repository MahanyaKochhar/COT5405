##  Greedy Algorithm for Set Cover
**Goal:** Cover all elements using as few sets as possible.

### Greedy Step
At each iteration:
- Pick the set that covers the largest number of uncovered elements.

### Algorithm
1. Let U = set of covered elements (initially empty).
2. While U is not the full universe:
   * For each set S in the family, compute how many new elements it covers (|S \ U|).
   * Pick S* = the set maximizing |S \ U|.
   * Add S* to the solution.
   * Add these elements to U (U ← U ∪ S*).
3. Return the selected sets.

### Intuition
* Each step: pick the most "efficient covering move."
* Like grabbing the biggest chunk of work each time.

### Why this algorithm?
* It's **simple**.
* It's **fast** (O(nm) or so).
* It has a known **approximation guarantee**:
  - Greedy Set Cover gives a solution of size ≤ (ln n + 1) × optimal.
  - This is one of the classic results in approximation algorithms.

##  How does this connect to RMP?

**Set Cover is a special case of Role Mining:**
* Universe elements ↔ permissions.
* Sets ↔ roles.
* One user ↔ must cover all permissions.
* Asking for ≤ k sets ↔ ≤ k roles.

### This means:
Any technique for Set Cover (including greedy) naturally motivates approaches for RMP.

In the RMP paper, they reason similarly:
* Because RMP generalizes Set Cover or Set Basis Problem, we can borrow greedy ideas.

1. Prove RMP is NP-complete via reduction from Set Cover.
2. Since Set Cover is NP-complete, we know optimal solutions are unlikely to be found quickly.
3. Set Cover has a well-studied greedy algorithm with performance guarantees.
4. Therefore, greedy design for RMP can be inspired by the greedy Set Cover algorithm, but RMP's broader structure requires more specialized heuristics.
