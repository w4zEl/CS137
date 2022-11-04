#!/usr/bin/bash
name="${1%.c}"
out="$(mktemp)"
gcc -Wall -pedantic -std=c11 "$name.c" "${name}_main.c" -o "$out"
"$out"
rm "$out"
