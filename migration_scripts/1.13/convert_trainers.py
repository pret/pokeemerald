import re
import sys
import os

is_blank = re.compile(r'^[ \t]*(//.*)?$')

begin_party_definition   = re.compile(r'struct TrainerMon (\w+)\[\] =')
end_party_definition     = re.compile(r'^        },')
begin_pokemon_definition = re.compile(r'^    { *$')
end_pokemon_definition   = re.compile(r'^    },? *$')
level_definition         = re.compile(r'\.lvl = (\d+)')
species_definition       = re.compile(r'\.species = SPECIES_(\w+)')
gender_definition        = re.compile(r'\.gender = TRAINER_MON_(\w+)')
nickname_definition      = re.compile(r'\.nickname = COMPOUND_STRING\("([^"]+)"\)')
item_definition          = re.compile(r'\.heldItem = ITEM_(\w+)')
ball_definition          = re.compile(r'\.ball = ITEM_(\w+)')
ability_definition       = re.compile(r'\.ability = ABILITY_(\w+)')
friendship_definition    = re.compile(r'\.friendship = (\d+)')
shiny_definition         = re.compile(r'\.isShiny = (\w+)')
ivs_definition           = re.compile(r'\.iv = TRAINER_PARTY_IVS\(([0-9 ]+),([0-9 ]+),([0-9 ]+),([0-9 ]+),([0-9 ]+),([0-9 ]+)\)')
evs_definition           = re.compile(r'\.ev = TRAINER_PARTY_EVS\(([0-9 ]+),([0-9 ]+),([0-9 ]+),([0-9 ]+),([0-9 ]+),([0-9 ]+)\)')
moves_definition         = re.compile(r'\.moves = \{([^}]+)\}')
move_definition          = re.compile(r'MOVE_(\w+)')
nature_definition        = re.compile(r'NATURE_(\w+)')

is_trainer_skip = re.compile(r'(const struct Trainer gTrainers\[\] = \{)|(^    \{$)|(\.partySize =)|(\.party = NULL)|(\.mugshotEnabled = TRUE)|(\};)')

trainer_normal_definition          = re.compile(r'    \[DIFFICULTY_NORMAL\]\[(TRAINER_\w+)\] =')
trainer_easy_definition            = re.compile(r'    \[DIFFICULTY_EASY\]\[(TRAINER_\w+)\] =')
trainer_hard_definition            = re.compile(r'    \[DIFFICULTY_HARD\]\[(TRAINER_\w+)\] =')
end_pokemon_definition             = re.compile(r'            },')
trainer_class_definition           = re.compile(r'\.trainerClass = TRAINER_CLASS_(\w+)')
encounter_music_gender_definition  = re.compile(r'\.encounterMusic_gender = (F_TRAINER_FEMALE \| )?TRAINER_ENCOUNTER_MUSIC_(\w+)')
encounter_music_definition         = re.compile(r'TRAINER_ENCOUNTER_MUSIC_(\w+)')
trainer_pic_definition             = re.compile(r'\.trainerPic = TRAINER_PIC_(\w+)')
trainer_name_definition            = re.compile(r'\.trainerName = _\("([^"]*)"\)')
trainer_items_definition           = re.compile(r'\.items = \{([^}]*)\}')
trainer_item_definition            = re.compile(r'ITEM_(\w+)')
trainer_double_battle_definition   = re.compile(r'\.battleType = (\w+)')
trainer_ai_flags_definition        = re.compile(r'\.aiFlags = (.*)')
trainer_ai_flag_definition         = re.compile(r'AI_FLAG_(\w+)')
trainer_party_definition           = re.compile(r'\.party = ')
trainer_mugshot_definition         = re.compile(r'\.mugshotColor = MUGSHOT_COLOR_(\w+)')
trainer_starting_status_definition = re.compile(r'\.startingStatus = STARTING_STATUS_(\w+)')

# NOTE: These are just for aesthetics, the Pokemon would still compile
# without them.
species_replacements = {
    "CHIEN_PAO": "Chien-Pao",
    "CHI_YU": "Chi-Yu",
    "HAKAMO_O": "Hakamo-o",
    "HO_OH": "Ho-Oh",
    "JANGMO_O": "Jangmo-o",
    "KOMMO_O": "Kommo-o",
    "PORYGON_Z": "Porygon-Z",
    "ROTOM_": "Rotom-",
    "TING_LU": "Ting-Lu",
    "TYPE_NULL": "Type: Null",
    "WO_CHIEN": "Wo-Chien",

    "_ALOLAN": "-Alola",
    "_AQUA_BREED": "-Aqua",
    "_BATTLE_BOND": "-Bond",
    "_BLAZE_BREED": "-Blaze",
    "_CAP": "",
    "_CLOAK": "",
    "_COMBAT_BREED": "-Combat",
    "_CROWED_SHIELD": "-Crowned",
    "_CROWED_SWORD": "-Crowned",
    "_DRIVE": "",
    "_EAST_SEA": "-East",
    "_FAMILY_OF_FOUR": "-Four",
    "_FEMALE": "-F",
    "_FLOWER": "",
    "_GALARIAN": "-Galar",
    "_GIGANTAMAX": "-Gmax",
    "_HISUIAN": "-Hisui",
    "_ICE_RIDER": "-Ice",
    "_NOICE_FACE": "-Noice",
    "_ORIGIN": "-Origin",
    "_ORIGINAL_COLOR": "-Original",
    "_PALDEAN": "-Paldea",
    "_PLUMAGE": "",
    "_POKE_BALL": "-Pokeball",
    "_SHADOW_RIDER": "-Shadow",
    "_STRIKE_STYLE": "-Style",
    "_TOTEM": "-Totem",
    "_ZEN_MODE": "-Zen",
}

class_fixups = {
    "Rs": "RS",
}

pic_fixups = {
    "Rs": "RS",
}

pokemon_attribute_order = ['Level', 'Ability', 'IVs', 'EVs', 'Happiness', 'Shiny', 'Ball']

class Pokemon:
    def __init__(self):
        self.nickname = None
        self.species = None
        self.gender = None
        self.item = None
        self.nature = None
        self.attributes = {}
        self.attributes['IVs'] = "0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe"
        self.moves = []


class Trainer:
    def __init__(self, id_):
        self.id = id_
        self.class_ = None
        self.encounter_music = None
        self.gender = None
        self.pic = None
        self.name = None
        self.items = []
        self.double_battle = None
        self.ai_flags = None
        self.mugshot = None
        self.starting_status = None
        self.party = None
        self.difficulty = None


def write_tutorial(output):
    output.write('/*\n')
    output.write('Trainers and their parties defined with Competetive Syntax.\n')
    output.write('Compatible with Pokemon Showdown exports.\n')
    output.write('https://github.com/smogon/pokemon-showdown/blob/master/sim/TEAMS.md\n')
    output.write('\n')
    output.write('A trainer specification starts with "=== TRAINER_XXXX ==="\n')
    output.write('and includes everything until the next line that starts with "==="\n')
    output.write('or the file ends.\n')
    output.write('\n')
    output.write('A blank line is required between the trainer and their Pokemon\n')
    output.write('and between their Pokemon.\n')
    output.write('TRAINER_XXXX is how the trainer is referred to within code.\n')
    output.write('Fields with description and/or example of usage\n')
    output.write('Required fields for trainers:\n')
    output.write('    - Name\n')
    output.write('    - Pic\n')
    output.write('Optional (but still recommended) fields for trainers:\n')
    output.write('    - Class (if not specified, PkMn Trainer will be used)\n')
    output.write('    - Gender (Male/Female, affects random gender weights of party if not specified)\n')
    output.write('    - Music\n')
    output.write('    - Items (Some Item / Another Item / Third Item)\n')
    output.write('            (Can also be specified with ITEM_SOME_ITEM)\n')
    output.write('    - Battle Type (Singles / Doubles, defaults to Singles)\n')
    output.write('    - AI (Ai Flag / Another Flag / Third Flag / ...\n')
    output.write('          see "constants/battle_ai.h" for all flags)\n')
    output.write('    - Mugshot (enable Mugshots during battle transition\n')
    output.write('               set to one of Purple, Green, Pink, Blue or Yellow)\n')
    output.write('    - Starting Status (see include/constants/battle.h for values)\n')
    output.write('\n')
    output.write('Pokemon are then specified using the Showdown Export format.\n')
    output.write("If a field is not specified, it will use it's default value.\n")
    output.write("\n")
    output.write('Required fields for Pokemon:\n')
    output.write('    - Species (Either as SPECIES_ABRA or Abra)\n')
    output.write('      This line also specifies Gender, Nickname and Held item.\n')
    output.write('      Alfred (Abra) (M) @ Eviolite\n')
    output.write('      Roberta (SPECIES_ABRA) (F) @ ITEM_CHOICE_SPECS\n')
    output.write('      Both lines are valid. Gender (M) or (F) must use a capital letter.\n')
    output.write('      Nickname length is limited to 10 characters using standard letters.\n')
    output.write("      With narrow font it's increased to 12. Longer strings will be silently shortened.\n")
    output.write('\n')
    output.write('Optional fields for Pokemon:\n')
    output.write('    - Level (Number between 1 and 100, defaults to 100)\n')
    output.write('    - Ability (Ability Name or ABILITY_ABILITY_NAME)\n')
    output.write('    - IVs (0 HP / 1 Atk / 2 Def / 3 SpA / 4 SpD / 5 Spe, defaults to all 31)\n')
    output.write('          (Order does not matter)\n')
    output.write('    - EVs (252 HP / 128 Spe / 48 Def, defaults to all 0, is not capped at 512 total)\n')
    output.write('          (Order does not matter)\n')
    output.write('    - Ball (Poke Ball or ITEM_POKE_BALL, defaults to Poke Ball)\n')
    output.write('    - Happiness (Number between 1 and 255)\n')
    output.write('    - Nature (Rash or NATURE_RASH, defaults to Hardy)\n')
    output.write('    - Shiny (Yes/No, defaults to No)\n')
    output.write('    - Dynamax Level (Number between 0 and 10, default 10, also sets "shouldDynamax" to True)\n')
    output.write('    - Gigantamax (Yes/No, sets to Gigantamax factor)\n')
    output.write('                 (doesn\'t do anything to Pokemon without a Gigantamax form, also sets "shouldDynamax" to True)\n')
    output.write('    - Tera Type (Set to a Type, either Fire or TYPE_FIRE, also sets "shouldTerastal" to True)\n')
    output.write('Moves are defined with a - (dash) followed by a single space, then the move name.\n')
    output.write('Either "- Tackle" or "- MOVE_TACKLE" works. One move per line.\n')
    output.write('Moves have to be the last lines of a Pokemon.\n')
    output.write('If no moves are specified, the Pokemon will use the last 4 moves it learns\n')
    output.write('through levelup at its level.\n')
    output.write("\n")
    output.write('Default IVs and Level can be changed in the "main" function of tools/trainerproc/main.c\n')
    output.write("\n")
    output.write('This file is processed with a custom preprocessor.\n')
    output.write('*/\n')
    output.write("\n")
    output.write('/*\n')
    output.write('Comments can be added as C comment blocks\n')
    output.write('// cannot be used as comments\n')
    output.write('*/\n')
    output.write("\n")
    output.write('/*Comments can also be on a single line*/\n')
    output.write("\n")
    output.write("\n")



def write_to_file(trainer, output):
    output.write(f'=== {trainer.id} ===\n')
    output.write(f'Name: {trainer.name}\n')
    output.write(f'Class: {trainer.class_}\n')
    output.write(f'Pic: {trainer.pic}\n')
    output.write(f'Gender: {trainer.gender}\n')
    output.write(f'Music: {trainer.encounter_music}\n')
    if len(trainer.items) > 0:
        output.write(f'Items: {trainer.items}\n')
    output.write(f'Battle Type: {trainer.double_battle}\n')
    if trainer.ai_flags is not None:
        output.write(f'AI: {trainer.ai_flags}\n')
    if trainer.mugshot:
        output.write(f'Mugshot: {trainer.mugshot}\n')
    if trainer.difficulty is not None:
        output.write(f'Difficulty: {trainer.difficulty}\n')

    output.write(f'\n')

    for pokemon in trainer.party:
        if pokemon.species is None:
            continue
        if pokemon.item is not None:
            output.write(f'{pokemon.species} @ {pokemon.item}\n')
        else:
            output.write(f'{pokemon.species}\n')
        # for key in pokemon.attributes:
        for key in pokemon_attribute_order:
            if key in pokemon.attributes:
                output.write(f'{key}: {pokemon.attributes[key]}\n')
        if pokemon.nature:
            output.write(f'Nature: {pokemon.nature}\n')
        for move in pokemon.moves:
            output.write(f'- {move}\n')
        output.write(f'\n')


def parse_trainers(content, output):
    newlines = 0
    trainer = None
    pokemon = None
    party = []
    moves = []

    write_tutorial(output)

    for line_no, line in enumerate(content, 1):
        try:
            line = line[:-1]

            # Trainer defition
            if m := trainer_normal_definition.search(line):
                if trainer is not None:
                    trainer.party = party
                    write_to_file(trainer, output)
                trainer = None
                party = []
                [id_] = m.groups()
                trainer = Trainer(id_)
                trainer.difficulty = None
                trainer.gender = 'Male'
            elif m := trainer_easy_definition.search(line):
                if trainer is not None:
                    trainer.party = party
                    write_to_file(trainer, output)
                trainer = None
                party = []
                [id_] = m.groups()
                trainer = Trainer(id_)
                trainer.difficulty = "Easy"
                trainer.gender = 'Male'
            elif m := trainer_hard_definition.search(line):
                if trainer is not None:
                    trainer.party = party
                    write_to_file(trainer, output)
                trainer = None
                party = []
                [id_] = m.groups()
                trainer = Trainer(id_)
                trainer.difficulty = "Hard"
                trainer.gender = 'Male'
            elif m := trainer_class_definition.search(line):
                [class_] = m.groups()
                class_ = class_.replace("_", " ").title()
                for match, replacement in class_fixups.items():
                    class_ = class_.replace(match, replacement)
                trainer.class_ = class_
            elif m := encounter_music_gender_definition.search(line):
                [is_female, music] = m.groups()
                trainer.gender = 'Female' if is_female else 'Male'
                trainer.encounter_music = music.replace("_", " ").title()
            elif m := encounter_music_definition.search(line):
                [music] = m.groups()
                trainer.encounter_music = music.replace("_", " ").title()
            elif "F_TRAINER_FEMALE" in line:
                trainer.gender = 'Female'
            elif m := trainer_pic_definition.search(line):
                [pic] = m.groups()
                pic = pic.replace("_", " ").title()
                for match, replacement in pic_fixups.items():
                    pic = pic.replace(match, replacement)
                trainer.pic = pic
            elif m := trainer_name_definition.search(line):
                [name] = m.groups()
                trainer.name = name
            elif m := trainer_items_definition.search(line):
                [items] = m.groups()
                trainer.items = " / ".join(item.replace("_", " ").title() for item in trainer_item_definition.findall(items) if item != "NONE")
            elif m := trainer_double_battle_definition.search(line):
                [double_battle] = m.groups()
                if double_battle == 'TRAINER_BATTLE_TYPE_DOUBLES':
                    trainer.double_battle = "Doubles"
                elif double_battle == 'TRAINER_BATTLE_TYPE_SINGLES':
                    trainer.double_battle = "Singles"
            elif m := trainer_ai_flags_definition.search(line):
                [ai_flags] = m.groups()
                trainer.ai_flags = " / ".join(ai_flag.replace("_", " ").title() for ai_flag in trainer_ai_flag_definition.findall(ai_flags))
            elif m := trainer_mugshot_definition.search(line):
                [color] = m.groups()
                trainer.mugshot = color.title()
            elif m := trainer_starting_status_definition.search(line):
                [starting_status] = m.groups()
                trainer.starting_status = starting_status.replace("_", " ").title()
            elif m := trainer_party_definition.search(line):
                pokemon = Pokemon()

            # Party mons
            elif end_pokemon_definition.search(line):
                party.append(pokemon)
                pokemon = Pokemon()
            elif m := level_definition.search(line):
                [level] = m.groups()
                pokemon.attributes['Level'] = level
            elif m := species_definition.search(line):
                [species_] = m.groups()
                for match, replacement in species_replacements.items():
                    species_ = species_.replace(match, replacement)
                pokemon.species = species_.replace("_", " ").title()
            elif m := gender_definition.search(line):
                [gender_] = m.groups()
                if gender_ == 'MALE':
                    pokemon.gender = 'M'
                elif gender_ == 'FEMALE':
                    pokemon.gender = 'F'
            elif m := nickname_definition.search(line):
                [nickname] = m.groups()
                pokemon.nickname = nickname
            elif m := item_definition.search(line):
                [item_] = m.groups()
                pokemon.item = item_.replace("_", " ").title()
            elif m := ball_definition.search(line):
                [ball] = m.groups()
                pokemon.attributes['Ball'] = ball.replace("_", " ").title()
            elif m := ability_definition.search(line):
                [ability] = m.groups()
                pokemon.attributes['Ability'] = ability.replace("_", " ").title()
            elif m := friendship_definition.search(line):
                [friendship] = m.groups()
                pokemon.attributes['Happiness'] = friendship
            elif m := shiny_definition.search(line):
                [shiny] = m.groups()
                if shiny == 'TRUE':
                    pokemon.attributes['Shiny'] = 'Yes'
                elif shiny == 'FALSE':
                    pokemon.attributes['Shiny'] = 'No'
            elif m := ivs_definition.search(line):
                [hp, attack, defense, speed, special_attack, special_defense] = [stat.strip() for stat in m.groups()]
                stats = {"HP": hp, "Atk": attack, "Def": defense, "SpA": special_attack, "SpD": special_defense, "Spe": speed}
                pokemon.attributes['IVs'] = ' / '.join(f"{value} {key}" for key, value in stats.items())
            elif m := evs_definition.search(line):
                [hp, attack, defense, speed, special_attack, special_defense] = [stat.strip() for stat in m.groups()]
                stats = {"HP": hp, "Atk": attack, "Def": defense, "SpA": special_attack, "SpD": special_defense, "Spe": speed}
                pokemon.attributes['EVs'] = ' / '.join(f"{value} {key}" for key, value in stats.items() if value != '0')
            elif m := move_definition.search(line):
                [move] = m.groups()
                pokemon.moves.append(move.replace("_", " ").title())
            elif m := nature_definition.search(line):
                [nature] = m.groups()
                pokemon.nature = nature.replace("_", " ").title()

        except Exception as e:
            print(f"{line_no}: {e}")

if __name__ == '__main__':
    try:
        [argv0, trainers_in_path, out_path] = sys.argv
    except:
        print(f"usage: python3 {sys.argv[0]} <trainers.h> <out>")
        print("trainers.h path: src/data/trainers.h")
        print("trainers.party output path: src/data/trainers.party")
    else:
        with open(trainers_in_path, "r") as source, open(out_path, 'w') as output:
            parse_trainers(source, output)
