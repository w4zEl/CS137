#!/usr/bin/bash
root="${1:-.}"
printf "Executing all tests in $root\n\n"
find "$root" -name '*.c' -exec ./run_tests.sh {} \; -exec echo \;
