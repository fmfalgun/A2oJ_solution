#!/usr/bin/env bash
# Compiles each given .cpp and, if a matching input/<n>.in + output/<n>.out
# pair exists, splits them on "---" delimiters into individual test cases and runs
# each one, diffing against the corresponding expected block.
#
# Test-case format for .in and .out files:
#   Separate multiple test cases with a line containing exactly "---".
#   A single test case (no delimiter) continues to work unchanged.
#
# Usage: run-tests.sh [-t N] file.cpp [file.cpp ...]
#   no flag : run every test case, print a pass/fail summary.
#   -t N    : run only test case N (1-based). Everything the program prints
#             (stdout + stderr) is shown for debugging; only its LAST non-empty
#             line is compared against the last line of expected chunk N.
#
# Summary line printed per file: X/Y test cases passed.
# Exit code: non-zero if any file fails to compile or any test case fails.
#
# Expects the standard layout: <problem-set>/codes/<n>.cpp
#                               <problem-set>/input/<n>.in
#                               <problem-set>/output/<n>.out
#                               <problem-set>/binary/<n>      (compiled output, written here)
#
# CHANGED (layout): the binary/ line above is new. Binaries are no longer written
# to a temp dir; they are saved in the repo under <problem-set>/binary/.
#
# CHANGED (nesting): <problem-set> may now sit at ANY depth, and files may be
# nested below codes/ (e.g. codes/div2/a.cpp). The subfolder structure under
# codes/ is mirrored under input/, output/ and binary/:
#     X/codes/div2/a.cpp -> X/input/div2/a.in, X/output/div2/a.out, X/binary/div2/a
# Flat files behave exactly as before (codes/a.cpp -> input/a.in, ...).
set -uo pipefail

DELIM="---"

# Split a file on lines equal to $DELIM and write each chunk to numbered temp
# files under $tmpdir with the given prefix. Prints the number of chunks.
split_on_delim() {
  local src="$1" tmpdir="$2" prefix="$3"
  local chunk=0 chunk_file
  chunk_file="$tmpdir/${prefix}_${chunk}.chunk"
  > "$chunk_file"
  while IFS= read -r line || [[ -n "$line" ]]; do
    if [[ "$line" == "$DELIM" ]]; then
      chunk=$(( chunk + 1 ))
      chunk_file="$tmpdir/${prefix}_${chunk}.chunk"
      > "$chunk_file"
    else
      printf '%s\n' "$line" >> "$chunk_file"
    fi
  done < "$src"
  echo $(( chunk + 1 ))
}

only=""
if [[ "${1:-}" == "-t" ]]; then
  only="${2:-}"
  if ! [[ "$only" =~ ^[1-9][0-9]*$ ]]; then
    echo "usage: $0 [-t N] file.cpp [file.cpp ...]   (N = 1-based test case number)" >&2
    exit 2
  fi
  shift 2
fi

fail=0
# tmp is still used for compile logs and split test-case chunks (scratch data
# that should NOT live in the repo). Only the compiled binary moved out of it.
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

for f in "$@"; do
  [ -f "$f" ] || continue

  # ── Resolve paths relative to the file's own location ─────────────────────
  # CHANGED: previously
  #     name=$(basename "$f" .cpp)
  #     problem_set=$(dirname "$(dirname "$f")")
  #     in_file="$problem_set/input/$name.in"
  #     out_file="$problem_set/output/$name.out"
  #     bin="$tmp/$name"
  # That assumed the file is exactly <problem-set>/codes/<n>.cpp, so any extra
  # nesting below codes/ pointed at the wrong directory. Now we anchor on the
  # "codes" directory name instead, so depth does not matter.

  # Normalize relative paths so "codes/a.cpp" (no leading ./) also matches the
  # "*/codes/*" pattern below. Absolute and ./-prefixed paths are left alone.
  case "$f" in
    /*|./*) p="$f" ;;
    *)      p="./$f" ;;
  esac

  # Refuse files that are not under a codes/ directory rather than guessing.
  case "$p" in
    */codes/*.cpp) ;;
    *)
      echo "$f: not under a <problem-set>/codes/ directory - cannot locate input/output/binary"
      fail=1
      continue
      ;;
  esac

  # Everything before the first "/codes/" is the problem set, at any depth.
  # (%% and # both cut at the FIRST "/codes/", so the two stay consistent.)
  problem_set="${p%%/codes/*}"
  rel="${p#*/codes/}"                 # path inside codes/, e.g. div2/a.cpp or a.cpp
  rel="${rel%.cpp}"                   # e.g. div2/a or a

  # CHANGED: "name" is now only used for temp-file names ($tmp/...), so slashes
  # are flattened to "__" (div2/a -> div2__a). Real paths below keep the slashes.
  name="${rel//\//__}"

  # CHANGED: I/O paths mirror the subfolders under codes/ via $rel.
  in_file="$problem_set/input/$rel.in"
  out_file="$problem_set/output/$rel.out"

  # CHANGED: binary goes into the repo's binary/ dir (was "$tmp/$name").
  bin="$problem_set/binary/$rel"
  mkdir -p "$(dirname "$bin")"        # CHANGED: create binary/ (and subfolders) if missing

  # ── Compile ────────────────────────────────────────────────────────────────
  # Compile log stays in $tmp: it is scratch output, not something to commit.
  if ! g++ -O2 -std=c++17 -o "$bin" "$f" 2>"$tmp/$name.compile.log"; then
    echo "$f: FAILED to compile"
    cat "$tmp/$name.compile.log"
    fail=1
    continue
  fi

  # ── Check I/O pair exists ──────────────────────────────────────────────────
  if [ ! -f "$in_file" ] || [ ! -f "$out_file" ]; then
    # CHANGED: message shows the real resolved paths (includes subfolders).
    echo "$f: no $in_file + $out_file found - add a sample I/O pair for new problems"
    fail=1
    continue
  fi

  # ── Split into test-case chunks ────────────────────────────────────────────
  n_in=$(split_on_delim  "$in_file"  "$tmp" "${name}_in")
  n_out=$(split_on_delim "$out_file" "$tmp" "${name}_out")

  if [[ "$n_in" -ne "$n_out" ]]; then
    echo "$f: mismatch — $n_in input chunk(s) but $n_out output chunk(s) in I/O files"
    fail=1
    continue
  fi

  # ── Single test case mode: show all output, compare only the last line ────
  if [[ -n "$only" ]]; then
    if (( only > n_in )); then
      echo "$f: test case $only does not exist ($n_in available)"
      fail=1
      continue
    fi
    in_chunk="$tmp/${name}_in_$(( only - 1 )).chunk"
    out_chunk="$tmp/${name}_out_$(( only - 1 )).chunk"

    echo "── $f: test case $only output (stderr + stdout) ──"
    "$bin" < "$in_chunk" 2>&1 | tee "$tmp/$name.actual"
    echo "── end of output ──"

    # Last non-empty line of each side, trailing whitespace trimmed
    actual=$(sed 's/[[:space:]]*$//' "$tmp/$name.actual" | grep -v '^$' | tail -n 1)
    expected=$(sed 's/[[:space:]]*$//' "$out_chunk" | grep -v '^$' | tail -n 1)

    if [[ "$actual" == "$expected" ]]; then
      echo "$f: test case $only PASSED (last line: $actual)"
    else
      echo "$f: test case $only FAILED"
      echo "  expected last line: $expected"
      echo "  actual last line:   $actual"
      fail=1
    fi
    continue
  fi

  # ── Run each test case ────────────────────────────────────────────────────
  total="$n_in"
  passed=0

  for (( i=0; i<total; i++ )); do
    in_chunk="$tmp/${name}_in_${i}.chunk"
    out_chunk="$tmp/${name}_out_${i}.chunk"

    actual=$("$bin" < "$in_chunk" 2>/dev/null)
    expected=$(cat "$out_chunk")

    # Trim trailing blank lines from both sides for a stable comparison
    actual=$(printf '%s' "$actual" | sed 's/[[:space:]]*$//')
    expected=$(printf '%s' "$expected" | sed 's/[[:space:]]*$//')

    if [[ "$actual" == "$expected" ]]; then
      passed=$(( passed + 1 ))
    else
      echo "$f: test case $(( i + 1 )) FAILED"
      echo "  expected: $expected"
      echo "  actual:   $actual"
      fail=1
    fi
  done

  echo "$f: $passed/$total test case(s) passed"
done

exit $fail
