import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Read contest.c and extract the party information
for file in glob.glob('./src/contest.c'):
    with open(file, 'r') as f:
        source_content = f.read()

# Extract party info from contest.c
source_pattern = re.compile(r'(\[CONTEST_EFFECT_.*\])\s*=\s(COMPOUND_STRING.*),')
source_data = {}
for match in source_pattern.findall(source_content):
    if len(match) == 2:
        contest_effect, effect_description = match
        source_data[contest_effect] = (effect_description)

# Read contest_moves.h content
for file in glob.glob('./src/data/contest_moves.h'):
    with open(file, 'r') as f:
        destination_content = f.read()

# Modify contest_moves.h content
def add_description(match):
    contest_effect = match.group(1)
    if contest_effect in source_data:
        effect_description = source_data[contest_effect]
        print(f"Updating {contest_effect}: adding {effect_description}")
        return f"{match.group(0)}\n        .description = {effect_description},"
    else:
        return match.group(0)

destination_pattern = re.compile(r'(\[CONTEST_EFFECT_.*\]) =\s*\n\s*{')
modified_content = destination_pattern.sub(add_description, destination_content)

# Write the modified content back to contest_moves.h
for file in glob.glob('./src/data/contest_moves.h'):
    with open(file, 'w') as f:
        f.write(modified_content)
        print("contest_moves.h has been updated")
