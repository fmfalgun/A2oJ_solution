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
- Merge via squash once CI is green, then delete the branch from GitHub's merge screen.
- Sync back locally: `git checkout master && git pull && git branch -d problem/<slug> && git fetch --prune`.

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
