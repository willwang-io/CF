#!/usr/bin/env bash

src="$1"

if [[ ! -f "$src" ]]; then
  echo "source file not found: $src"
  exit 1
fi

if ! command -v icdiff >/dev/null 2>&1; then
  echo "icdiff not found. Install it with:"
  echo "  brew install icdiff"
  exit 1
fi

problem="${src%.cpp}"

mkdir -p .bin .actual

exe="./.bin/${problem}"
samples_dir="./samples"

g++ -std=c++23 -O2 -Wall -Wextra "$src" -o "$exe" || exit 1

i=1
while [[ -f "${samples_dir}/${problem}.in${i}" ]]; do
  input="${samples_dir}/${problem}.in${i}"
  expected="${samples_dir}/${problem}.out${i}"
  actual="./.actual/${problem}.actual${i}"

  if [[ ! -f "$expected" ]]; then
    echo "expected output not found: $expected"
    exit 1
  fi

  echo "== Sample ${i} =="

  "$exe" < "$input" > "$actual"

  if icdiff --line-numbers --cols=120 "$expected" "$actual"; then
    echo "OK"
  else
    echo "WA"
    echo "Input:    $input"
    echo "Expected: $expected"
    echo "Actual:   $actual"
    exit 1
  fi

  i=$((i + 1))
done

if [[ "$i" -eq 1 ]]; then
  echo "no samples found for $problem"
  echo "expected files like: samples/${problem}.in1"
  exit 1
fi

echo "All samples passed."