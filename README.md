# A2oJ_solution

- Competitive-programming / DSA solutions, one problem (or one improvement) per branch and PR, even solo.
- Layout: `Codeforces_Rating_1300/codes/<name>.cpp` (source), `binary/<name>` (compiled output), `input/<name>.in` (sample input), `output/<name>.out` (expected output), `mental-model.md` (pattern checklist), `notes/<name>.md` (per-problem deep-dive).
- One-time local setup after cloning: `git config core.hooksPath .githooks`.

---

## Git workflow

- Start from an up-to-date master: `git checkout master && git pull`.
- Branch per unit of work, named per the convention below: `git checkout -b <type>/<slug>`.
- Write the solution in `Codeforces_Rating_1300/codes/<name>.cpp`.
- Add a sample I/O pair for it: `Codeforces_Rating_1300/input/<name>.in` and `output/<name>.out`.
- Add at least one comment stating your approach or any assumption the algorithm makes.
- If the problem taught you something worth keeping, capture it (see "Mental model & notes" below) — optional, not every problem needs it.
- Compile and self-test before staging: `g++ -O2 -std=c++17 codes/<name>.cpp -o binary/<name> && ./binary/<name> < input/<name>.in`.
- Review your own diff before staging: `git diff`.
- Stage only what you touched: `git add <files>`.
- Commit with a message naming the problem and the approach, not a date or "done".
  - Example: `git commit -m "Shooshuns and sequence: two-pointer approach, O(n)"`.
  - The commit-msg hook (see below) will reject vague messages automatically.
- Push the branch: `git push -u origin <type>/<slug>`.
- Open a PR on GitHub — CI runs the checks below and must pass before merging.
- Merge once CI is green, then delete the branch from GitHub's merge screen.
  - Squash and merge — default choice; collapses messy in-progress commits (attempt/fix/final) into one clean commit.
  - Rebase and merge — use instead when the branch already has multiple separate, already-clean commits worth preserving individually.
  - Create a merge commit — skip this; it only adds merge-commit noise with no concurrent branches to reconcile.
- Sync back locally: `git checkout master && git pull && git branch -d <type>/<slug> && git fetch --prune`.

---

## Branch naming convention

Format: `<type>/<short-kebab-slug>`. Derived from [Conventional Commits](https://www.conventionalcommits.org)'s type vocabulary — this repo renames its one dominant type, `feat`, to `problem`, since every unit of real work here is solving one problem.

| Type | Use for | Simple example |
|------|---------|-----------------|
| `problem` | Solving a new problem (this repo's `feat`) | `problem/sum-of-two-numbers` |
| `fix` | Fixing a bug in an already-solved solution | `fix/dragons-off-by-one` |
| `docs` | Documentation only, no code change | `docs/readme-worked-example` |
| `chore` | Maintenance/tooling/repo housekeeping | `chore/remove-shower-line-exe` |
| `refactor` | Restructuring a solution's code, same output | `refactor/split-helpful-maths-into-functions` |
| `test` | Adding/improving a sample I/O pair only | `test/add-edge-case-for-dragons` |
| `ci` | Changes to `.github/workflows/` or `scripts/` themselves | `ci/add-magic-number-check` |
| `perf` | Optimizing an existing solution, same output | `perf/optimize-k-string-loop` |
| `build` | Rarely needed here — no package manager/build system beyond `g++` directly | *(skip unless one actually comes up)* |

- One type per branch — a branch mixing `problem` work with unrelated `chore` cleanup should be two branches instead.
- If in doubt between `problem`/`fix`: `problem` solves something new, `fix` corrects a solution that already existed but was wrong.

### One example per type

The push/PR/CI/merge/sync steps are identical for every type — see the full sequence in "Worked example" below. What actually differs per type is just what you touch and what the commit says:

```bash
# problem - solving a new problem (full 11-step walkthrough is the next section)
git checkout -b problem/sum-of-two-numbers

# fix - correcting an already-solved solution
git checkout -b fix/dragons-off-by-one
# edit Codeforces_Rating_1300/codes/Dragons.cpp, fix the bug
./scripts/run-tests.sh Codeforces_Rating_1300/codes/Dragons.cpp
git commit -m "Dragons: fix off-by-one in weak-dragon check"

# docs - documentation only, no code touched
git checkout -b docs/branch-type-examples
# edit README.md only
git commit -m "Add a compact worked example for each branch type"

# chore - maintenance/tooling, not user-facing
git checkout -b chore/add-gitignore
# add a .gitignore covering stray build artifacts outside binary/
git commit -m "Add .gitignore for compiled binaries left outside binary/"

# refactor - restructure a solution, same output
git checkout -b refactor/split-helpful-maths-into-functions
# split codes/helpful_maths.cpp's main() into read_input/solve/print_result
./scripts/run-tests.sh Codeforces_Rating_1300/codes/helpful_maths.cpp
git commit -m "Helpful maths: split into read/solve/print functions, same output"

# test - sample I/O only, no logic touched
git checkout -b test/add-edge-case-for-dragons
# add input/Dragons_min.in + output/Dragons_min.out for the n=1 edge case
git commit -m "Dragons: add n=1 edge case sample"

# ci - the automation itself
git checkout -b ci/add-line-length-check
# edit scripts/ or .github/workflows/ci.yml
git commit -m "Add a max-line-length check to CI"

# perf - optimize an existing solution, same output
git checkout -b perf/optimize-k-string-loop
# rewrite the inner loop in codes/k_string.cpp for lower complexity
./scripts/run-tests.sh Codeforces_Rating_1300/codes/k_string.cpp
git commit -m "K string: two-pointer scan instead of nested loop, same output"
```

---

## Worked example: one problem, start to finish

A deliberately trivial problem ("read two ints, print their sum") used purely to show the exact commands in order — the algorithm doesn't matter here, the sequence does.

```bash
# 1. Start from an up-to-date master
git checkout master
git pull

# 2. Branch, named after the problem
git checkout -b problem/sum-of-two-numbers

# 3. Write the solution at Codeforces_Rating_1300/codes/sum_of_two_numbers.cpp:
#      #include <iostream>
#      using namespace std;
#      int main() {
#          // reads two ints, prints their sum - no assumptions beyond int range
#          int a, b;
#          cin >> a >> b;
#          cout << a + b;
#          return 0;
#      }

# 4. Add the sample I/O pair, copied straight from the problem statement
echo "2 3" > Codeforces_Rating_1300/input/sum_of_two_numbers.in
printf '5' > Codeforces_Rating_1300/output/sum_of_two_numbers.out

# 5. Compile and self-test
g++ -O2 -std=c++17 Codeforces_Rating_1300/codes/sum_of_two_numbers.cpp \
    -o Codeforces_Rating_1300/binary/sum_of_two_numbers
./Codeforces_Rating_1300/binary/sum_of_two_numbers < Codeforces_Rating_1300/input/sum_of_two_numbers.in
# -> prints 5, matches output/sum_of_two_numbers.out

# 6. Run the same checks CI will run, before committing anything
./scripts/check-comments.sh Codeforces_Rating_1300/codes/sum_of_two_numbers.cpp
./scripts/check-magic-numbers.sh Codeforces_Rating_1300/codes/sum_of_two_numbers.cpp
./scripts/run-tests.sh Codeforces_Rating_1300/codes/sum_of_two_numbers.cpp

# 7. Review the diff, stage, commit
git diff
git add Codeforces_Rating_1300/codes/sum_of_two_numbers.cpp \
        Codeforces_Rating_1300/input/sum_of_two_numbers.in \
        Codeforces_Rating_1300/output/sum_of_two_numbers.out
git commit -m "Sum of two numbers: direct read-and-add, no edge cases"
# -> the commit-msg hook runs automatically here and passes

# 8. Push the branch
git push -u origin problem/sum-of-two-numbers

# 9. Open the PR (or use the URL GitHub printed after the push)
gh pr create --title "Sum of two numbers" --body "Trivial read-and-add solution."
# -> CI now runs check-comments / check-magic-numbers / run-tests / check-commit-msg
#    against just this one changed file - must go green before the merge button unlocks

# 10. Merge once CI is green - one clean commit here, so squash and merge is fine

# 11. Sync back locally
git checkout master
git pull
git branch -d problem/sum-of-two-numbers
git fetch --prune
```

---

## Automated checks (new/changed files only — old solutions are grandfathered)

- **Comment presence** — `scripts/check-comments.sh` fails if a file has zero comments.
- **Magic numbers** — `scripts/check-magic-numbers.sh` flags bare sentinel literals (`9999`, `1e9`, etc.) not backed by a named `const`/`#define`.
  - Silence a false positive by adding `// magic-ok` on that line.
- **Compile + sample test** — `scripts/run-tests.sh` compiles the file and diffs its output against `input/<name>.in`/`output/<name>.out`; fails if either is missing for a new file.
- **Commit message** — `scripts/check-commit-msg.sh` rejects pure dates, `Auto-commit` placeholders, bare `problem N`, and anything under 12 characters.
- These run twice: locally via the `.githooks/pre-push` + `.githooks/commit-msg` hooks, and again in `.github/workflows/ci.yml` on every PR — the PR check is the one that actually blocks a bad merge.
- Only files changed in the diff are checked, so the 58 pre-existing solutions are never retroactively blocked.

---

## Code-quality checklist (self-review at PR time — not machine-checkable)

- **Single responsibility** — once a solution is more than ~20 lines, split input parsing, the algorithm, and output formatting into separate functions instead of one long `main()`.
- **Comments explain *why*, not *what*** — a note on the approach ("two-pointer since array is sorted") beats restating the code in English; the automated check only confirms a comment exists, not that it's a good one.
- **State your assumptions correctly** — if the algorithm assumes sorted input, non-negative values, no duplicates, etc., say so; the automated check can't judge whether the stated assumption is actually true.
- **DRY** — if you paste the same helper (fast I/O template, binary search, GCD, etc.) into a third file, promote it to a shared header instead of a fourth copy.
- **Consistent naming** — pick one convention (`snake_case` or `camelCase`) and stick to it across the file.

---

## Mental model & notes (per problem-set directory)

- **`mental-model.md`** — one file per problem-set directory (e.g. `Codeforces_Rating_1300/mental-model.md`), sectioned by *pattern/category* (e.g. "Small, fixed numeric bounds"), not by problem.
  - A checklist to scan *before* coding a new problem, to recognize which pattern it matches.
  - Append to an existing section when a new problem reinforces that pattern; add a new section only for a genuinely new pattern.
  - Each entry links to the fuller write-up in `notes/` that it was distilled from.
- **`notes/<name>.md`** — one file per problem, matching the `<name>` used in `codes/`/`input/`/`output/`.
  - The full-depth write-up: what made the problem hard, the reasoning step by step, where the thinking initially stalled, a reusable checklist for that problem family.
  - Not machine-checked and not required for every problem — write one when the problem taught something worth remembering, skip it for routine ones.
  - This is where AI-discussion/search content and in-depth reasoning gets logged for later reference, so it doesn't need to be re-derived from scratch next time a similar problem shows up.
- Neither file is linted or gated by CI — they're reflection tools, reviewed the same informal way as any other markdown.

---

## Never do this

- Never commit compiled binaries by hand outside `binary/` — extension-less build artifacts or `.exe`/`.o` files sitting next to a `.cpp` elsewhere are a sign the layout convention was skipped.
- Never force-push over shared history on `master`.
