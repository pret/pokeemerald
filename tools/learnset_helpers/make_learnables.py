#!/usr/bin/env python3

"""
Usage: python3 make_learnables.py INPUTS_DIR OUTPUT_FILE

Build a primary store of learnable moves for each species based on input documents. This script
is meant to be run to generate a pre-processed store of data that should not change very much;
thus, it can safely be pre-computed in order to speed up incremental builds for end-users.
"""

from functools import reduce

import json
import pathlib
import sys


def from_single(fname: pathlib.Path) -> dict[str, set[str]]:
    with open(fname, "r") as fp:
        return {
            species: set([level_up["Move"] for level_up in by_method["LevelMoves"]])
            | set([move for move in by_method["TMMoves"]])
            | set([move for move in by_method["EggMoves"]])
            | set([move for move in by_method["TutorMoves"]])
            for species, by_method in json.load(fp).items()
        }


def from_batch(dir: pathlib.Path) -> dict[str, set[str]]:
    return reduce(
        lambda acc, single: {
            species: acc.get(species, set()) | single.get(species, set())
            for species in acc.keys() | single.keys()
        },
        map(from_single, dir.glob("*.json")),
        {},
    )


def main():
    if len(sys.argv) < 3:
        print("Missing required arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    INPUTS_DIR = pathlib.Path(sys.argv[1])
    OUTPUT_FILE = pathlib.Path(sys.argv[2])

    assert INPUTS_DIR.exists(), f"{INPUTS_DIR=} does not exist"
    assert INPUTS_DIR.is_dir(), f"{INPUTS_DIR=} is not a directory"
    assert OUTPUT_FILE.parent.exists(), f"parent of {OUTPUT_FILE=} does not exist"

    batch = {
        species: list(sorted(learnables))
        for species, learnables in from_batch(INPUTS_DIR).items()
    }
    with open(OUTPUT_FILE, "w") as fp:
        json.dump(batch, fp, indent=2)


if __name__ == "__main__":
    main()
