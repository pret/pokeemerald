#!/usr/bin/env python3

"""
Usage: python3 make_teaching_types.py OUTPUT_FILE

Build a primary store of "teaching-types" for each enabled species in the repository as an
input for make_teachables.py.
"""

import glob
import json
import pathlib
import re
import sys

CONFIG_ENABLED_PAT = re.compile(r"^#define P_LEARNSET_HELPER_TEACHABLE\s+(?P<cfg_val>[^ ]*)", flags=re.MULTILINE)

TEACHING_TYPE_PAT =  re.compile(r"\s*\.teachingType\s*=\s*(?P<teaching_type>[A-Z_]+),")
LEARNSET_PAT = re.compile(r"\s*\.teachableLearnset\s*=\s*s(?P<name>\w+?)TeachableLearnset")
PREPROC_START_PAT = re.compile(r"^#if(def)?\s+\w+", flags=re.MULTILINE)
PREPROC_END_PAT = re.compile(r"^#endif\s*(//\s*\w+)?", flags=re.MULTILINE)

def enabled() -> bool:
    """
    Check if the user has explicitly enabled this opt-in helper.
    """
    with open("./include/config/pokemon.h", "r") as cfg_pokemon_fp:
        cfg_pokemon = cfg_pokemon_fp.read()
        cfg_defined = CONFIG_ENABLED_PAT.search(cfg_pokemon)
        return cfg_defined is not None and cfg_defined.group("cfg_val") in ("TRUE", "1")

def is_valid_preprocessor(line: str) -> bool:
    match = re.match(PREPROC_START_PAT, line)
    if match:
        return True
    match = re.match(PREPROC_END_PAT, line)
    if match:
        return True
    return False

def extract_repo_species_data() -> list:
    species_data = []
    pokemon_list = []
    teaching_type = "DEFAULT_LEARNING"
    file_list = sorted(glob.glob("src/data/pokemon/species_info/*_families.h"))
    file_list.append("./src/data/pokemon/species_info.h")
    for families_fname in file_list:
        with open(families_fname, "r") as family_fp:
            species_lines = family_fp.readlines()
        is_last_line_preprocessor = False
        for line in species_lines:
            if is_valid_preprocessor(line):
                is_last_line_preprocessor = True
                if line.startswith("#endif") and (isinstance(species_data[-1], str) and species_data[-1].startswith("#if")):
                    del species_data[-1]
                else:
                    species_data.append(line)
                continue

            match = re.match(LEARNSET_PAT, line)
            if match:
                if match.group("name") == "None":
                    continue
                if match.group("name") not in pokemon_list:
                    if not is_last_line_preprocessor:
                        species_data.append("\n")
                    is_last_line_preprocessor = False
                    species_data.append({"name": match.group("name"), "teaching_type": teaching_type})
                    pokemon_list.append(match.group("name"))
                teaching_type = "DEFAULT_LEARNING"
                continue
            match = re.match(TEACHING_TYPE_PAT, line)
            if match:
                teaching_type = match.group("teaching_type")
    return species_data

def add_whitesspaces(parsed_list) -> list:
    for i, item in enumerate(parsed_list):
        if i == 0:
            continue
        if not isinstance(item, str):
            continue
        if item.startswith("#if"):
            if not isinstance(parsed_list[i - 1], str):
                parsed_list[i] = "\n" + item
            elif parsed_list[i - 1].startswith("#endif"):
                parsed_list[i] = "\n" + item
    return parsed_list


def dump_output(file, data):
    with open(file, "w") as fp:
        fp.write(data)

def main():
    if not enabled():
        quit()

    if len(sys.argv) < 2:
        print("Missing required arguments", file=sys.stderr)
        print(__doc__, file=sys.stderr)
        quit(1)

    OUTPUT_FILE = pathlib.Path(sys.argv[1])

    assert OUTPUT_FILE.parent.exists(), f"parent of {OUTPUT_FILE=} does not exist"

    teaching_types_list = extract_repo_species_data()
    teaching_types_list = add_whitesspaces(teaching_types_list)
    new_teaching_types = json.dumps(teaching_types_list, indent=2)
    old_teaching_types = ""
    if OUTPUT_FILE.exists() and OUTPUT_FILE.is_file():
        with open(OUTPUT_FILE, "r") as fp:
            old_teaching_types = fp.read()

    dump_output(OUTPUT_FILE, new_teaching_types)

    if new_teaching_types != old_teaching_types:
        pathlib.Path("./tools/learnset_helpers/make_teachables.py").touch()


if __name__ == "__main__":
    main()
