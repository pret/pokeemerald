import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Read battle_frontier_trainer_mons.h and extract the party information
for file in glob.glob('./src/data/battle_frontier/battle_frontier_trainer_mons.h'):
    with open(file, 'r') as f:
        source_content = f.read()

# Extract party info from battle_frontier_trainer_mons.h
source_pattern = re.compile(r'gBattleFrontierTrainerMons_(.*)\[\]\s*=\s*\n\{\n\s*(FRONTIER.*)')
source_data = {}
for match in source_pattern.findall(source_content):
    if len(match) == 2:
        trainer_name, party_group = match
        source_data[trainer_name] = (party_group)

# Read battle_frontier_trainers.h content
for file in glob.glob('./src/data/battle_frontier/battle_frontier_trainers.h'):
    with open(file, 'r') as f:
        destination_content = f.read()

# Modify battle_frontier_trainers.h content
def add_party_data(match):
    trainer_name = match.group(1)
    if trainer_name in source_data:
        party_group = source_data[trainer_name]
        print(f"Updating {trainer_name}: adding {party_group}")
        return f'(const u16[]){{{party_group}}}'
    else:
        return match.group(0)

destination_pattern = re.compile(r'gBattleFrontierTrainerMons_(.*)')
modified_content = destination_pattern.sub(add_party_data, destination_content)

# Write the modified content back to battle_frontier_trainers.h
for file in glob.glob('./src/data/battle_frontier/battle_frontier_trainers.h'):
    with open(file, 'w') as f:
        f.write(modified_content)
        print("battle_frontier_trainers.h has been updated")
