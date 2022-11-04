#!/usr/bin/bash
if [ "$#" != 1 -a "$#" != 2 ]; then 
	echo "Usage: run_tests program.c [testsDir]"
	exit 1
fi
prog="$1"
testsDir="${2:-"$(dirname "$1")/$(basename "$1" .c)_tests"}"
tmp="$(mktemp)"
GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'
echo "Compiling $prog"
gcc "$prog" -o "$tmp"
shopt -s nullglob
echo "Executing tests (in directory $testsDir)"
echo "----------------"
for inputFile in "$testsDir/"*.in
do
	ran=1
	printf "Test case $(basename "$inputFile" .in): "
	if diff --strip-trailing-cr "$testsDir/$(basename "$inputFile" .in).out" <("$tmp" < "$inputFile")
	then
		printf "${GREEN}Passed.${RESET}\n"
	else
		printf "${RED}Failed.${RESET}\n"
	fi
done
if [ -z $ran ]; then
	echo "Warning: No tests found!"
fi
rm "$tmp"
