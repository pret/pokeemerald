# If you have extra members in 'TrainerMon':
# 1. Add a regular expression which matches that member (e.g. 'shadow_definition').
# 2. Match that regular expression in 'convert' and write into 'attributes' with the key that 'trainerproc' should parse.
# 3. Add the key used in 'attributes' to 'pokemon_attribute_order'.
# 4. Update 'trainerproc.c' to parse the new key.

import re
import sys

is_blank = re.compile(r'^[ \t]*(//.*)?$')

begin_party_definition   = re.compile(r'struct TrainerMon (\w+)\[\] =')
end_party_definition     = re.compile(r'^};')
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
nature_definition        = re.compile(r'\.nature = NATURE_(\w+)')

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

def convert_parties(in_path, in_h):
    party_identifier = None
    party = None
    pokemon = None
    parties = {}

    for line_no, line in enumerate(in_h, 1):
        try:
            line = line[:-1]
            if m := begin_party_definition.search(line):
                if party:
                    raise Exception(f"unexpected start of party")
                [identifier] = m.groups()
                party_identifier = identifier
                party = []
            elif end_party_definition.search(line):
                if not party:
                    raise Exception(f"unexpected end of party")
                parties[party_identifier] = party
                party = None
            elif begin_pokemon_definition.search(line):
                if pokemon:
                    raise Exception(f"unexpected start of Pokemon")
                pokemon = Pokemon()
            elif end_pokemon_definition.search(line):
                if not pokemon:
                    raise Exception(f"unexpected end of Pokemon")
                else:
                    party.append(pokemon)
                    pokemon = None
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
                else:
                    raise Exception(f"unknown gender: '{gender_}'")
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
                else:
                    raise Exception(f"unknown isShiny: '{shiny}'")
            elif m := ivs_definition.search(line):
                [hp, attack, defense, speed, special_attack, special_defense] = [stat.strip() for stat in m.groups()]
                stats = {"HP": hp, "Atk": attack, "Def": defense, "SpA": special_attack, "SpD": special_defense, "Spe": speed}
                pokemon.attributes['IVs'] = ' / '.join(f"{value} {key}" for key, value in stats.items())
            elif m := evs_definition.search(line):
                [hp, attack, defense, speed, special_attack, special_defense] = [stat.strip() for stat in m.groups()]
                stats = {"HP": hp, "Atk": attack, "Def": defense, "SpA": special_attack, "SpD": special_defense, "Spe": speed}
                pokemon.attributes['EVs'] = ' / '.join(f"{value} {key}" for key, value in stats.items() if value != '0')
            elif m := moves_definition.search(line):
                [moves_] = m.groups()
                pokemon.moves = [move.replace("_", " ").title() for move in move_definition.findall(moves_) if move != "NONE"]
            elif m := nature_definition.search(line):
                [nature_] = m.groups()
                pokemon.nature = nature_.replace("_", " ").title()
            elif is_blank.search(line):
                pass
            else:
                raise Exception(f"could not parse '{line.strip()}'")
        except Exception as e:
            print(f"{in_path}:{line_no}: {e}")
    return parties

is_trainer_skip = re.compile(r'(const struct Trainer gTrainers\[\] = \{)|(^    \{$)|(\.partySize =)|(\.party = NULL)|(\.mugshotEnabled = TRUE)|(\};)')

begin_trainer_definition           = re.compile(r'    \[(TRAINER_\w+)\] =')
end_trainer_definition             = re.compile(r'    }')
trainer_class_definition           = re.compile(r'\.trainerClass = TRAINER_CLASS_(\w+)')
encounter_music_gender_definition  = re.compile(r'\.encounterMusic_gender = (F_TRAINER_FEMALE \| )?TRAINER_ENCOUNTER_MUSIC_(\w+)')
trainer_pic_definition             = re.compile(r'\.trainerPic = TRAINER_PIC_(\w+)')
trainer_name_definition            = re.compile(r'\.trainerName = _\("([^"]*)"\)')
trainer_items_definition           = re.compile(r'\.items = \{([^}]*)\}')
trainer_item_definition            = re.compile(r'ITEM_(\w+)')
trainer_double_battle_definition   = re.compile(r'\.doubleBattle = (\w+)')
trainer_ai_flags_definition        = re.compile(r'\.aiFlags = (.*)')
trainer_ai_flag_definition         = re.compile(r'AI_FLAG_(\w+)')
trainer_party_definition           = re.compile(r'\.party = TRAINER_PARTY\((\w+)\)')
trainer_mugshot_definition         = re.compile(r'\.mugshotColor = MUGSHOT_COLOR_(\w+)')
trainer_starting_status_definition = re.compile(r'\.startingStatus = STARTING_STATUS_(\w+)')

class_fixups = {
    "Rs": "RS",
}

pic_fixups = {
    "Rs": "RS",
}

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

def convert_trainers(in_path, in_h, parties, out_party):
    newlines = 0
    trainer = None
    for line_no, line in enumerate(in_h, 1):
        try:
            line = line[:-1]
            if m := begin_trainer_definition.search(line):
                if trainer:
                    raise Exception(f"unexpected start of trainer")
                [id_] = m.groups()
                trainer = Trainer(id_)
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
                if double_battle == 'TRUE':
                    trainer.double_battle = "Yes"
                elif double_battle == 'FALSE':
                    trainer.double_battle = "No"
                else:
                    raise Exception(f"unknown doubleBattle: '{double_battle}'")
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
                [party] = m.groups()
                trainer.party = parties[party]
            elif end_trainer_definition.search(line):
                if not trainer:
                    raise Exception(f"unexpected end of trainer")
                while newlines > 0:
                    out_party.write(f"\n")
                    newlines -= 1
                newlines = 1
                out_party.write(f"=== {trainer.id} ===\n")
                out_party.write(f"Name: {trainer.name}\n")
                out_party.write(f"Class: {trainer.class_}\n")
                out_party.write(f"Pic: {trainer.pic}\n")
                out_party.write(f"Gender: {trainer.gender}\n")
                out_party.write(f"Music: {trainer.encounter_music}\n")
                if trainer.items:
                    out_party.write(f"Items: {trainer.items}\n")
                out_party.write(f"Double Battle: {trainer.double_battle}\n")
                if trainer.ai_flags:
                    out_party.write(f"AI: {trainer.ai_flags}\n")
                if trainer.mugshot:
                    out_party.write(f"Mugshot: {trainer.mugshot}\n")
                if trainer.starting_status:
                    out_party.write(f"Starting Status: {trainer.starting_status}\n")
                if trainer.party:
                    for i, pokemon in enumerate(trainer.party):
                        out_party.write(f"\n")
                        if pokemon.nickname:
                            out_party.write(f"{pokemon.nickname} ({pokemon.species})")
                        else:
                            out_party.write(f"{pokemon.species}")
                        if pokemon.gender:
                            out_party.write(f" ({pokemon.gender})")
                        if pokemon.item and pokemon.item != 'None':
                            out_party.write(f" @ {pokemon.item}")
                        out_party.write(f"\n")
                        if pokemon.nature:
                            out_party.write(f"{pokemon.nature} Nature\n")
                        for key in pokemon_attribute_order:
                            if key in pokemon.attributes:
                                out_party.write(f"{key}: {pokemon.attributes[key]}\n")
                        for move in pokemon.moves:
                            out_party.write(f"- {move}\n")
                trainer = None
            elif is_blank.search(line) or is_trainer_skip.search(line):
                pass
            else:
                raise Exception(f"could not parse '{line.strip()}'")
        except Exception as e:
            print(f"{in_path}:{line_no}: {e}")

if __name__ == '__main__':
    try:
        [argv0, trainers_in_path, parties_in_path, out_path] = sys.argv
    except:
        print(f"usage: python3 {sys.argv[0]} <trainers.h> <trainer_parties.h> <out>")
    else:
        with open(trainers_in_path, "r") as trainers_in_h, open(parties_in_path, "r") as parties_in_h, open(out_path, "w") as out_party:
            parties = convert_parties(parties_in_path, parties_in_h)
            trainers = convert_trainers(trainers_in_path, trainers_in_h, parties, out_party)
