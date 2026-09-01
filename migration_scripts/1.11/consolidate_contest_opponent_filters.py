import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Read contest_opponents.h
for file in glob.glob('./src/data/contest_opponents.h'):
    with open(file, 'r') as f:
        source_content = f.read()

# Extract party info from contest_opponents.h
source_pattern = re.compile(r'(\[CONTEST_OPPONENT_.*\])\s*=\s(CONTEST_FILTER_.*)*')
source_data = {}
for match in source_pattern.findall(source_content):
    if len(match) == 2:
        trainer_name, contest_filter = match
        source_data[trainer_name] = (contest_filter)

# Read contest_opponents.h content
for file in glob.glob('./src/data/contest_opponents.h'):
    with open(file, 'r') as f:
        destination_content = f.read()

# Modify contest_opponents.h content
def add_filter_data(match):
    trainer_name = match.group(1)
    if trainer_name in source_data:
        contest_filter = source_data[trainer_name]
        print(f"Updating {trainer_name}: adding {contest_filter}")
        return f'{match.group(0)}\n        .filter = {contest_filter}'
    else:
        return match.group(0)

destination_pattern = re.compile(r'(\[CONTEST_OPPONENT_[A-Z_0-9]+\])\s*=\s*{')
modified_content = destination_pattern.sub(add_filter_data, destination_content)

# Write the modified content back to contest_opponents.h
for file in glob.glob('./src/data/contest_opponents.h'):
    with open(file, 'w') as f:
        f.write(modified_content)
        print("contest_opponents.h has been updated")
