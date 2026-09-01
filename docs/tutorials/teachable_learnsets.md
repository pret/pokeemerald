### Note: This guide was written for version 1.14.0, it doesn't apply to earlier versions of expansions. This guide also assumes you are using the default P_LEARNSET_HELPER_TEACHABLE config (TRUE)

# Generating and editing teachable learnsets

## Basics:
When you `make`, a file will be generated in `src/data/pokemon/teachable_learnsets.h` containing the learnsets of your Pokemon. The generated learnset of a pokemon is based on 3 things, its potential moveset defined in `src/data/pokemon/all_learnables.json`, the teaching type of the species defined in the species data files, and the TMs and tutors available in your game. We will explain each of these one by one. 

### Table of Contents:

1. [Potential Teachables]
2. [Teaching Types]
    - [Default Learnset]
    - [TM Illiterate]
    - [All Teachables]
3. [Available Moves]
    - [TMs/Hms]
    - [Tutors from scripts]
    - [Extra Tutors]

## Potential Teachables

The potential moveset of each pokemon is defined in `src/data/pokemon/all_learnables.json`. If you don't have the file yet, a version will be generated automatically after you run `make`. 
On its first creation, the file is based on the list of moves a pokemon can learn in official Pokemon games. Those lists are found in `tools/learnset_helpers/porymoves_files`, if a Pokemon learned a move in any way in the game (from level-up, egg move, tm or tutor), it will be added to its teachable learnset. You can delete some of the files mix-and-match from different games list. This is justa  tool to help you quickly generate a vanilla-ish etachable learnset.
After `src/data/pokemon/all_learnables.json` has been created, this file will NEVER be modified by running `make` so you don't have to worry abour your changes being reverted. However you can choose to remake the file by using a different set of game move list by running `make clean-teachables` and then running `make` again.

## Teaching Types

In addition to their teachable learnset described in `src/data/pokemon/all_learnables.json`, Pokemon will be able to learn additional moves based on their teaching types defined in their species data (found in `species/data/pokemon/species_info/gen_X_families.h` for vanilla Pokemon and `species/data/pokemon/species_info.h` for fakemons). There are currently three teaching types in Expansion: Default Learning, TM Illiterate and All Teahcables

### Default Learning

This is the default one, so if a species don't have a teaching type defined in its species data, it will will default to this. If you want to explicitly make a species this way, then add `.teachingType = DEFAULT_LEARNING` to the species data.
Default Learning mean in addtion to the moves described in its additional moveset, the Pokemon will be able to learn the universal moves (like Tera Blast or Hidden Power). Universal moves are listed in `src/data/pokemon/special_movesets.json` (there are multiple lists in the file, make sure to edit the one named "universalMoves")

### TM Illiterate

`.teachingType = TM_ILLITERATE`
TM Illiterate mean a pokemon will only learn move from its potential moveset and not any universal moves. If the config `P_TM_LITERACY` is set to GEN_5 or lower. Universal moves will be removed from the pokemon potential learnset.

### All Teachables

`.teachingType = ALL_TEACHABLES`
All Teachables mean a pokemon will be able to learn every teachable move that are present in your game whether tutor or TM similarly to Mew in official games. If you want a TM or a Tutor move to not be accesible to All Teachables pokemon, you can add it to the signature teachables list in `src/data/pokemon/special_movesets.json` (there are multiple lists in the file, make sure to edit the one named "signatureTeachables")

So, for example, if you a remove a TM from your game, the move associated with that TM will be removed from the teachable elarnset of your pokemon.

## Available Moves

The teachable learnset is based on the potential moveset and the universal moves as described in the sections above but it will only be conposed of moves that are available in your game. Let's see how the code detects the moves that are available.

### TMs/Hms

The script detects the TMs and HMs available in your game based on the list in `include/constants/tms_hms.h`. If you add a new TM, the pokemon with that move in their potential moveset will receive that move in their teachable learnset. And if you remove a TM, the move will be deleted from your pokemon's teachable learnsets.

### Tutors from scripts

The script look for tutors moves in your script files, wether map scripts `/data/maps/*/scripts.inc` or other function scripts `/data/scripts/*.inc`. It looks for the pattern used for move tutors in vanilla emerald `setvar VAR_0x8005, MOVE_*`. So try to add move tutors this way if you want them to be properl detected.

### Extra Tutors

If you somehow add a move that can be learned in new custom ways that don't fit with the previous patterns, you can add the move to the extra tutors list in `src/data/pokemon/special_movesets.json` (there are multiple lists in the file, make sure to edit the one named "extraTutors"). This shouldn't be necessary for most users and if you use this list, remember you will need to add/remove moves from this list and the code that teaches moves.

