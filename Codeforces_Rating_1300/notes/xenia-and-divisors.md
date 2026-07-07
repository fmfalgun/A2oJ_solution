# Codeforces 342A — Xenia and Divisors

Problem: https://codeforces.com/problemset/problem/342/A
Solution: [`codes/xenia-and-divisors.cpp`](../codes/xenia-and-divisors.cpp)
Mental-model category: [Small, fixed numeric bounds → enumerate by hand](../mental-model.md#small-fixed-numeric-bounds--enumerate-by-hand)

## 1. Why this problem felt harder than it should

The instinct that failed here wasn't a coding instinct — it was a
**modeling** instinct. The code (arrays, loops, counters) was never the hard
part. The hard part was realizing that this problem is not really about
processing a sequence at all — it's a **counting/combinatorics** problem
disguised as a sequence problem. That reframing is the whole difficulty, and
it's a common trap in problems with small numeric bounds.

## 2. The approach, step by step

### Step 1 — Notice the bound, and ask "what does this bound *imply*?"

The constraint said every value is in `[1, 7]`. The habit to build: whenever
you see a **tiny fixed range** in the constraints, treat it as a signal that
the *state space is small enough to enumerate by hand*, not as an incidental
detail. A bound of `≤ 7` isn't there for flavor — it's there because the
intended solution depends on it.

**Mental model:** *"Small constant bound → the problem probably reduces to a
finite, precomputable structure."*

### Step 2 — Separate "what's structurally possible" from "what's in this input"

Two very different questions got tangled together at first:
- *What triples `(a,b,c)` with `a<b<c`, `a|b`, `b|c` can exist at all, given
  values ≤ 7?* — this is a **fixed fact about the problem**, independent of
  any specific input.
- *How many of each triple do I need for this specific input?* — this
  depends entirely on the given sequence.

The first question was solved once, by hand, through direct enumeration
(trying every `a`, then every valid `b`, then every valid `c`). That gave
exactly three shapes: `(1,2,4)`, `(1,2,6)`, `(1,3,6)`. This should be
hardcoded — no runtime search needed for something that doesn't change across
inputs.

**Mental model:** *"If a structural fact doesn't depend on the input, don't
compute it at runtime — derive it once, on paper, and bake it into the
code."*

### Step 3 — Convert the sequence into counts, not positions

The original array (`sq[]`) preserves order and position, but this problem
doesn't care about order or position at all — it only cares about **how
many** of each value exist. That's the cue to collapse the array into a
frequency table (`cnt[1..7]`).

**Mental model:** *"If the problem's rules don't reference position or order,
stop thinking in arrays — think in frequency counts."*

### Step 4 — Find the numbers that are "structurally forced"

With only three triple shapes on the table, the next move was to check each
number (1 through 7) against all three shapes and ask: *does this number
appear in more than one shape, or exactly one, or none?*
- Numbers in **exactly one** shape (here, `3` and `4`) directly fix that
  shape's count — no ambiguity, no choice.
- Numbers in **zero** shapes (here, `5` and `7`) immediately invalidate the
  input if they appear at all.
- Numbers in **multiple** shapes (`1`, `2`, `6`) can only be resolved *after*
  the forced counts are known — by subtraction.

This is essentially solving a small system of equations by substitution, but
it only becomes visible once you tabulate "which shape(s) contain which
number."

**Mental model:** *"When several fixed categories share overlapping
ingredients, find the ingredient unique to one category first — it's your
anchor. Solve outward from there, like Sudoku: pin down what's forced, then
use it to resolve what's shared."*

### Step 5 — Validate, don't just construct

Deriving `comb[1]`, `comb[2]`, `comb[3]` doesn't guarantee they're consistent
with the *rest* of the input. A separate validation pass is needed:
- Every number not appearing in any triple must have count zero.
- Every derived count must be non-negative (a negative count means the input
  demanded more of something than was available).
- Every number's total usage across all triples must match its actual count
  in the input.

**Mental model:** *"Constructing an answer and validating that the answer is
consistent with all the constraints are two separate steps — don't skip the
second one just because the first one 'worked out.'"*

### Step 6 — Output construction is bookkeeping, not logic

By the time output is reached, all real thinking is done — this step is just
"print `comb[i]` copies of shape `i`." The one bug that showed up here
(`comb[2]` vs. `comb[3]` in the wrong loop bound) was purely a
copy-paste/attention slip, not a conceptual gap — worth noting as its own
category of error.

## 3. Why the thinking stalled initially

A few likely reasons, based on how the reasoning unfolded:
- **Jumping straight to code structure** (arrays, loops) before doing the
  by-hand combinatorial enumeration. The array-based instinct is usually
  right for sequence problems, but this problem's real substance lived in a
  small enumerated set, not in sequence manipulation.
- **Not immediately exploiting the small bound.** The bound `≤ 7` is the
  single biggest hint in the whole problem, and it's easy to read constraints
  passively (as just an upper limit for array sizing) rather than actively
  (as a promise that the solution space is enumerable).
- **The "unique ingredient" trick** (Step 4) isn't something that comes up in
  every problem, so it doesn't always fire as an instinct — it's closer to a
  puzzle-solving heuristic (similar to constraint propagation in Sudoku) than
  a standard algorithmic pattern like two-pointers or DP.

None of this reflects a gap in coding ability — the C++ mechanics were all
correct once the model was right. It reflects a gap in **problem-modeling
instinct** for this specific flavor of problem, which is exactly the kind of
thing that gets faster with repetition on similar problems.

## 4. A reusable checklist for this problem family

Use this whenever a problem has **small, fixed numeric bounds** (values or
counts capped at some small constant):

1. **Is the bound small enough to enumerate by hand?** If yes, do that
   enumeration on paper *before* writing any code.
2. **Does order/position matter, or only quantity?** If only quantity
   matters, collapse to a frequency array immediately.
3. **Are there a finite number of valid "shapes" or "patterns"?** List them
   all explicitly, and hardcode them.
4. **For each shape, which elements are shared vs. unique?** Elements unique
   to one shape are your anchors — solve those first.
5. **After deriving all quantities, validate independently** — check for
   negative values, unused/forbidden elements, and totals matching the input.
6. **Keep output/construction separate from logic** — treat it as a final
   bookkeeping pass, and double check loop bounds reference the right
   variable.

## 5. One-line summary to remember

> Small bounds are an invitation to enumerate by hand; frequency counts over
> raw sequences when order doesn't matter; solve for what's uniquely forced
> before solving for what's shared; and always validate after constructing.
