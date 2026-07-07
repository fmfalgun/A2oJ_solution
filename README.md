# A2oJ_solution

- Competitive-programming / DSA solutions, one problem (or one improvement) per branch and PR, even solo.
- Layout: `Codeforces_Rating_1300/codes/<name>.cpp` (source), `binary/<name>` (compiled output), `input/<name>.in` (sample input), `output/<name>.out` (expected output).
- One-time local setup after cloning: `git config core.hooksPath .githooks`.

---

## Git workflow

- Start from an up-to-date master: `git checkout master && git pull`.
- Branch per unit of work, named after the problem: `git checkout -b problem/<slug>`.
- Write the solution in `Codeforces_Rating_1300/codes/<name>.cpp`.
- Add a sample I/O pair for it: `Codeforces_Rating_1300/input/<name>.in` and `output/<name>.out`.
- Add at least one comment stating your approach or any assumption the algorithm makes.
- Compile and self-test before staging: `g++ -O2 -std=c++17 codes/<name>.cpp -o binary/<name> && ./binary/<name> < input/<name>.in`.
- Review your own diff before staging: `git diff`.
- Stage only what you touched: `git add <files>`.
- Commit with a message naming the problem and the approach, not a date or "done".
  - Example: `git commit -m "Shooshuns and sequence: two-pointer approach, O(n)"`.
  - The commit-msg hook (see below) will reject vague messages automatically.
- Push the branch: `git push -u origin problem/<slug>`.
- Open a PR on GitHub — CI runs the checks below and must pass before merging.
- Merge once CI is green, then delete the branch from GitHub's merge screen.
  - Squash and merge — default choice; collapses messy in-progress commits (attempt/fix/final) into one clean commit.
  - Rebase and merge — use instead when the branch already has multiple separate, already-clean commits worth preserving individually.
  - Create a merge commit — skip this; it only adds merge-commit noise with no concurrent branches to reconcile.
- Sync back locally: `git checkout master && git pull && git branch -d problem/<slug> && git fetch --prune`.

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

## Never do this

- Never commit compiled binaries by hand outside `binary/` — extension-less build artifacts or `.exe`/`.o` files sitting next to a `.cpp` elsewhere are a sign the layout convention was skipped.
- Never force-push over shared history on `master`.
