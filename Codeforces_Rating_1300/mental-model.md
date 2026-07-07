# Mental Model

A running checklist of patterns recognized across solved problems, grouped by
category. One section per pattern — append to the matching section when a new
problem reinforces it, add a new section when a genuinely new pattern shows
up. This file is the checklist to scan *before* coding a new problem: check
whether it matches a category below before reaching for arrays/loops by
default.

Each entry links back to its full write-up in `notes/` for the deeper
reasoning.

---

## Small, fixed numeric bounds → enumerate by hand

- A tiny fixed range in the constraints (e.g. values `≤ 7`) is a signal that
  the state space is small enough to enumerate by hand, not an incidental
  detail — the intended solution usually depends on it.
- Separate what's structurally possible (a fixed fact about the problem,
  independent of input — derive once, on paper, hardcode it) from what's in
  this specific input (depends on the given data).
- If the problem's rules don't reference position or order, stop thinking in
  arrays — collapse to a frequency count instead.
- When several fixed categories share overlapping ingredients, find the
  ingredient unique to one category first — it's the anchor. Solve outward
  from there (same idea as Sudoku constraint propagation): pin down what's
  forced, then use it to resolve what's shared.
- Constructing an answer and validating it against all constraints are two
  separate steps — don't skip validation just because construction "worked
  out" (check for negatives, unused/forbidden elements, totals matching input).
- Reference: [`notes/xenia-and-divisors.md`](notes/xenia-and-divisors.md)
