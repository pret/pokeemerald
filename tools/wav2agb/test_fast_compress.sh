#!/bin/sh

for l in $(seq 1 8)
do
    echo lookahead="$l":
    wav2agb "$1" -c -l "$l" --verbose
    echo lookahead="$l" fast:
    wav2agb "$1" -f -l "$l" --verbose
done
