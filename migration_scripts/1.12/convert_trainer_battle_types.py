import re
import os

def trainer_battle_types(data):
    data = re.sub(re.escape("Double Battle: No"), "Battle Type: Singles", data)
    data = re.sub(re.escape("Double Battle: Yes"), "Battle Type: Doubles", data)

    return data

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

with open('src/data/trainers.party', 'r') as file:
    data = file.read()
with open('src/data/trainers.party', 'w') as file:
    file.write(trainer_battle_types(data))
