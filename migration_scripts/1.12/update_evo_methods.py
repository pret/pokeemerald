import re
import os


METHOD = 0
CONDTION = 1
SPECIES = 2


def convert_methods(data):
    new_data = ""
    pattern = r'\{([^{}]+)\}'

    # make sure we're in the right directory before anything else
    if not os.path.exists("Makefile"):
        print("Please run this script from the project's root folder.")
        quit()

    for line in data:
        if "EVO_FRIENDSHIP," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}", line)
        elif "EVO_FRIENDSHIP_DAY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD}, {IF_NOT_TIME, TIME_NIGHT})}", line)
        elif "EVO_FRIENDSHIP_NIGHT," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD}, {IF_TIME, TIME_NIGHT})}", line)
        elif "EVO_TRADE_ITEM," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_TRADE, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_HOLD_ITEM, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_LEVEL_ATK_GT_DEF," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_ATK_GT_DEF})}", line)
        elif "EVO_LEVEL_ATK_EQ_DEF," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_ATK_EQ_DEF})}", line)
        elif "EVO_LEVEL_ATK_LT_DEF," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_ATK_LT_DEF})}", line)
        elif "EVO_LEVEL_SILCOON," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_PID_UPPER_MODULO_10_GT, 5})}", line)
        elif "EVO_LEVEL_CASCOON," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_PID_UPPER_MODULO_10_LT, 5})}", line)
        elif "EVO_LEVEL_NINJASK," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}', line)
        # elif "EVO_LEVEL_SHEDINJA," in line:
        #     match = re.search(pattern, line)
        #     members = match.group(1).split(",")
            # new_data = new_data = re.sub(pattern, " ", line)
        elif "EVO_BEAUTY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_MIN_BEAUTY, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_LEVEL_FEMALE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_GENDER, MON_FEMALE})}", line)
        elif "EVO_LEVEL_MALE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_GENDER, MON_MALE})}", line)
        elif "EVO_LEVEL_NIGHT," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_TIME, TIME_NIGHT})}", line)
        elif "EVO_LEVEL_DAY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_NOT_TIME, TIME_NIGHT})}", line)
        elif "EVO_LEVEL_DUSK," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_TIME, TIME_EVENING})}", line)
        elif "EVO_ITEM_HOLD_DAY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_NOT_TIME, TIME_NIGHT}, {IF_HOLD_ITEM, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_ITEM_HOLD_NIGHT," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_TIME, TIME_NIGHT}, {IF_HOLD_ITEM, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_MOVE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_KNOWS_MOVE, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_FRIENDSHIP_MOVE_TYPE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD}, {IF_KNOWS_MOVE_TYPE, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_MAPSEC," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_IN_MAPSEC, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_ITEM_MALE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_ITEM, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_GENDER, MON_MALE})}", line)
        elif "EVO_ITEM_FEMALE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_ITEM, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_GENDER, MON_FEMALE})}", line)
        elif "EVO_LEVEL_RAIN," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_WEATHER, WEATHER_RAIN})}", line)
        elif "EVO_LEVEL_FOG," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_WEATHER, WEATHER_FOG})}", line)
        elif "EVO_SPECIFIC_MON_IN_PARTY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_SPECIES_IN_PARTY, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_LEVEL_DARK_TYPE_MON_IN_PARTY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_TYPE_IN_PARTY, TYPE_DARK})}", line)
        elif "EVO_TRADE_SPECIFIC_MON," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_TRADE, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_TRADE_PARTNER_SPECIES, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_SPECIFIC_MAP," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_IN_MAP, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_LEVEL_NATURE_AMPED," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_AMPED_NATURE})}", line)
        elif "EVO_LEVEL_NATURE_LOW_KEY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_LOW_KEY_NATURE})}", line)
        elif "EVO_CRITICAL_HITS," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_BATTLE_END, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_CRITICAL_HITS_GE, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_SCRIPT_TRIGGER_DMG," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_SCRIPT_TRIGGER, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_CURRENT_DAMAGE_GE, " + f'{members[CONDTION].strip()}' + "})}", line)
        elif "EVO_DARK_SCROLL," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_SCRIPT_TRIGGER, " + f'0, {members[SPECIES].strip()}' + "}", line)
        elif "EVO_WATER_SCROLL," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_SCRIPT_TRIGGER, " + f'1, {members[SPECIES].strip()}' + "}", line)
        elif "EVO_ITEM_NIGHT," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_ITEM, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_TIME, TIME_NIGHT})}", line)
        elif "EVO_ITEM_DAY," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_ITEM, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_NOT_TIME, TIME_NIGHT})}", line)
        elif "EVO_MOVE_TWO_SEGMENT," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_KNOWS_MOVE, " + f'{members[CONDTION].strip()}' + "}, {IF_PID_MODULO_100_LT, 100})}", line)
        elif "EVO_MOVE_THREE_SEGMENT," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_KNOWS_MOVE, " + f'{members[CONDTION].strip()}' + "}, {IF_PID_MODULO_100_LT, 1})}", line)
        elif "EVO_LEVEL_FAMILY_OF_THREE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_PID_MODULO_100_EQ, 0})}", line)
        elif "EVO_LEVEL_FAMILY_OF_FOUR," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'{members[CONDTION].strip()}, {members[SPECIES].strip()}' + ", CONDITIONS({IF_PID_MODULO_100_GT, 0})}", line)
        elif "EVO_USE_MOVE_TWENTY_TIMES," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_USED_MOVE_X_TIMES, " + f'{members[CONDTION].strip()}' + ", 20})}", line)
        elif "EVO_RECOIL_DAMAGE_MALE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_RECOIL_DAMAGE_GE, " + f'{members[CONDTION].strip()}' + "}, {IF_GENDER, MON_MALE})}", line)
        elif "EVO_RECOIL_DAMAGE_FEMALE," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_RECOIL_DAMAGE_GE, " + f'{members[CONDTION].strip()}' + "}, {IF_GENDER, MON_FEMALE})}", line)
        elif "EVO_ITEM_COUNT_999," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_BAG_ITEM_COUNT, " + f'{members[CONDTION].strip()}' + ", 999})}", line)
        elif "EVO_DEFEAT_THREE_WITH_ITEM," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_DEFEAT_X_WITH_ITEMS, " + "SPECIES_BISHARP, ITEM_LEADERS_CREST, 3})}", line)
        elif "EVO_OVERWORLD_STEPS," in line:
            match = re.search(pattern, line)
            members = match.group(1).split(",")
            new_data = new_data + re.sub(pattern, "{EVO_LEVEL, " + f'0, {members[SPECIES].strip()}' + ", CONDITIONS({IF_MIN_OVERWORLD_STEPS, 1000})}", line)
        else:
            new_data = new_data + line

    return new_data


species_files = [
    "gen_1_families.h",
    "gen_2_families.h",
    "gen_3_families.h",
    "gen_4_families.h",
    "gen_5_families.h",
    "gen_6_families.h",
    "gen_7_families.h",
    "gen_8_families.h",
    "gen_9_families.h",
]

PATH = "src/data/pokemon/species_info/"

for source in species_files:
    with open(PATH + source, 'r') as file:
        data = file.readlines()

    with open(PATH + source, 'w') as file:
        file.write(convert_methods(data))
