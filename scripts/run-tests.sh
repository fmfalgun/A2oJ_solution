#!/usr/bin/env bash
# Compiles each given .cpp and, if a matching input/<name>.in + output/<name>.out
# pair exists, splits them on "---" delimiters into individual test cases and runs
# each one, diffing against the corresponding expected block.
#
# Test-case format for .in and .out files:
#   Separate multiple test cases with a line containing exactly "---".
#   A single test case (no delimiter) continues to work unchanged.
#
# Summary line printed per file: X/Y test cases passed.
# Exit code: non-zero if any file fails to compile or any test case fails.
#
# Expects the standard layout: <problem-set>/codes/<name>.cpp
#                               <problem-set>/input/<name>.in
#                               <problem-set>/output/<name>.out
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

fail=0
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

for f in "$@"; do
  [ -f "$f" ] || continue
  name=$(basename "$f" .cpp)
  problem_set=$(dirname "$(dirname "$f")")
  in_file="$problem_set/input/$name.in"
  out_file="$problem_set/output/$name.out"
  bin="$tmp/$name"

  # ── Compile ────────────────────────────────────────────────────────────────
  if ! g++ -O2 -std=c++17 -o "$bin" "$f" 2>"$tmp/$name.compile.log"; then
    echo "$f: FAILED to compile"
    cat "$tmp/$name.compile.log"
    fail=1
    continue
  fi

  # ── Check I/O pair exists ──────────────────────────────────────────────────
  if [ ! -f "$in_file" ] || [ ! -f "$out_file" ]; then
    echo "$f: no input/$name.in + output/$name.out found - add a sample I/O pair for new problems"
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
