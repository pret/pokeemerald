*Full credits and thank you to CancerFairy for writing this guide!*

### Note: This guide was written for version 1.8.0. Most stuff still applies to 1.7.x versions and earlier, with the following exceptions:
- Battle and Contest move data are separated in `src/data/battle_moves.h` and `src/data/contest_moves.h`
- `additionalEffects` doesn't exist, instead being handled by a combination of `secondaryEffectChance` and unique `EFFECT_xxx`s.
- There's no `include/constants/battle_move_effects.h`, so data specific to certain effects is handled in other places.
- Move names are handled in `gMoveNames`.

# Adding/editing moves
This guide is here to give you a breakdown of how moves work, how to edit existing ones, and how to add your own.

## Contents:
1. [Key files and definitions](#key-files-and-definitions)
    - [Header files](#header-files)
    - [C files](#c-files)
    - [Script files](#script-files)
2. [Editing a move](#editing-a-move)
3. [Adding a new move](#adding-a-new-move)

## Key files and definitions
Before beginning the process, it's important to familiarise yourself with the important files that control moves. There are three categories of files - header(.h) files, which contain static information about a move, .c files which contains functions in C that determine how the move behaves, and script files (.s or .inc) that actually "run" the move - i.e. determine the sequence of events you see on screen when you execute the move.

## Header files
### src/data/moves_info.h
This is the place where the bulk of move information is stored, including name, base power, typing, PP, contest information etc.

Let's look at an example:
```c
[MOVE_THUNDER_SHOCK] =
{
    .name = HANDLE_EXPANDED_MOVE_NAME("ThunderShock", "Thunder Shock"),
    .description = COMPOUND_STRING(
        "An electrical attack that\n"
        "may paralyze the foe."),
    .effect = EFFECT_HIT,
    .power = 40,
    .type = TYPE_ELECTRIC,
    .accuracy = 100,
    .pp = 30,
    .target = MOVE_TARGET_SELECTED,
    .priority = 0,
    .category = DAMAGE_CATEGORY_SPECIAL,
    .sheerForceBoost = TRUE,
    .additionalEffects = ADDITIONAL_EFFECTS({
        .moveEffect = MOVE_EFFECT_PARALYSIS,
        .chance = 10,
    }),
    .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
    .contestCategory = CONTEST_CATEGORY_COOL,
    .contestComboStarterId = 0,
    .contestComboMoves = {COMBO_STARTER_CHARGE},
},
```
The `HANDLE_EXPANDED_MOVE_NAME` allows the usage of a name of extended character length, so long as the `B_EXPANDED_MOVE_NAMES` is set to `TRUE`, whereas by default it's limited in Gen 3 to 12 characters. Most of the fields here are obvious, but the two important ones for determining what a move actually *does* are `effect` and `additionalEffects`.

The `effect` represents how the move actually works when called in battle - it can be a two turn move, or a move that only works if the target is holding an item, for example. How each effect works is pretty much unique, but the way a move of a particular effect is executed is defined by a script [`data/battle_scripts_1.s`](#databattle_scripts_1s), and any *variable* characteristics such as typing or power are defined in either [`src/battle_script_commands.c`](#srcbattle_script_commandsc) or [`src/battle_util.c`](#srcbattle_utilc), depending on the effect. The vast majority of non-status moves are simply `EFFECT_HIT`, in that they deal damage and apply `additionalEffects` (if defined).

The `additionalEffects` field represents effects that are applied at the `setadditionaleffects` stage of the move script (for most moves, see `BattleScript_Hit_RetFromAtkAnimation`). These are effects that can be encapsulated by any of the `MOVE_EFFECT_X` defined in [`include/constants/battle.h`](#includeconstantsbattleh) and encoded under `SetMoveEffect` in [`src/battle_script_commands.c`](#srcbattle_script_commandsc). These can vary from applying a status, such as `MOVE_EFFECT_PARALYSIS`, or lowering/raising stats etc. The move effect could target the user by setting `self = TRUE`, such as Overheat lowering the user's own Sp. Atk. What's more, definining a `chance`, such as for Thunder Shock, not only limits the effect to applying only `chance`% of the time, but it also turns it into a *secondary effect.* This difference is important because secondary effects are nullified by Sheer Force (which in turn will boost the move's power) and they are blocked by Shield Dust. These two limitations do not apply to *primary effects* which do not a chance field defined and by definition will *always* happen when the move is executed.

### src/data/battle_move_effects.h
Effects are listed here along with the `battleScript` that governs each one. Said scripts are defined in [`data/battle_scripts_1.s`](#databattle_scripts_1s). The indices/names of the effects (e.g. `EFFECT_FIRST_TURN_ONLY`) are enums defined in [`include/constants/battle_move_effects.h`](#includeconstantsbattle_move_effectsh).

### include/battle_scripts.h
Contains references to scripts [`data/battle_scripts_1.s`](#databattle_scripts_1s), allowing them to be referenced in C. Any new scripts must be added here.

### include/constants/battle_move_effects.h
Simply an enum list of possible effects for moves. Any new effects would be added here, with a definition for them (including defining a script) would then also be added to [`src/data/battle_move_effects.h`](#srcdatabattle_move_effectsh).

### include/constants/battle_string_ids.h
All strings that can be printed in battle have an id that is defined here. The actual message itself would then be defined and assigned to this id in [`src/data/battle_message.c`](#srcbattle_messagec).

### include/constants/battle.h
A whole range of constants defining battle variables, such as statuses, weather, and move effects.

### include/constants/moves.h
Where moves are defined (and nothing else).

**Note:** When adding custom moves, you should add them between the moves from the latest generation and the z moves, then adjust `MOVES_COUNT` accordingly.  Adding a move after `MOVES_COUNT` that is neither a Max Move or a Z Move will result in that move's name not being printed when it is used, instead a generic message will be printed.

## C files
### src/battle_script_commands.c
This is where a lot of the commands referred to in scripts are defined. For example, the `jumpifnotfirstturn` command above is defined by the function `Cmd_jumpifnotfirstturn` and you can see how it works in C. It's possible that any move editing or updating you have in mind can be done with existing commands, but if you wanted to add a new function that could be called in a script above, this is where you would define it.

### src/battle_util.c
This contains a lot of the "utility" functions used to determine things like a move's dynamic typing or power. It's also where damage calculation takes place, and a lot of that will naturally take a move's effect into account. For example, a move with the effect `EFFECT_SOLAR_BEAM` would have its damage halved in sandstorm. If you wanted to add a move with an effect which gave it variable BP or typing, this is the file you would encode that effect.

### src/battle_message.c
Contains string defines and functions that print messages during the battle. If you wish to add or edit a move's string, then this is where you would do so.

### src/battle_main.c
Contains more fundamental functions that control the flow of the battle. Functions here determine move order, dynamic typing, animations, priority, speed calculations and more.

## Script files
### data/battle_scripts_1.s
Each move's effect is governed by a script defined here. For a simple example, let's look at the script for Fake Out/First Impression:

```
BattleScript_EffectFirstTurnOnly::
	attackcanceler
	jumpifnotfirstturn BattleScript_FailedFromAtkString
	goto BattleScript_EffectHit
```

`attackcanceler` is a command that covers all the cases that could cause a move to fail before it's even attempted (e.g. paralysis). And as we can tell from the commands, if it's not the first turn, we go to `BattleScript_FailedFromAtkString` which evidently causes us to print the `attackstring` ("POKEMON used MOVE") then fail ("But it failed!"). Otherwise, we go to the generic "hit" effect which is the same script for moves that just deal damage and nothing else.

This is the most advanced part of the ROM. There are dozens upon dozens of commands and hundreds of scripts so this guide would go on forever if I were to go into more detail. To learn how these scripts work, it's best to look at a few examples of moves you know.

### asm/macros/battle_script.inc
The "link" between [`data/battle_scripts_1.s`](#databattle_scripts_1s) and [`src/battle_script_commands.c`](#srcbattle_script_commandsc). Each command is represented by a hex byte which represents its index in the `gBattleScriptingCommandsTable` array at the top of [`src/battle_script_commands.c`](#srcbattle_script_commandsc). However, this file also contains macros which perform combinations of other commands, or just calculations in assembly. In addition to commands, it is also possible to call functions in [`src/battle_script_commands.c`](#srcbattle_script_commandsc) using the `various` (now gradually being deprecated) and the `callnative` functionality. The `various` macros will point to a case under the `Cmd_various` function in [`src/battle_script_commands.c`](#srcbattle_script_commandsc), whereas `callnative` will let you directly call a function in [`src/battle_script_commands.c`](#srcbattle_script_commandsc) by name.

### data/battle_anim_scripts.s
This is the place where move animations are defined. The array at the top, `gBattleAnims_Moves`, is in move index order and determines which animation goes with which move.

## Editing a move
### Basic information
To edit a move's basic information, you need only edit the relevant fields in [`src/data/battle_moves.h`](#srcdatamoves_infoh). This will let you change a move's:
- name
- description
- power
- accuracy
- type
- category
- target
- pp
- recoil percentage
- flags
- Z-move effect (for status moves) or overwritting its calculated power (for damaging moves)

### Changing a move's main effect
To change the main effect of a move to an existing effect, you need only change its `effect` field to one of the options in [`src/data/battle_move_effects.h`](#srcdatabattle_move_effectsh). If you wish to keep the effect but simply modify how it works, you can modify how it plays out on screen by editing its entry in [`data/battle_scripts_1.s`](#databattle_scripts_1s) and any relevant functions in [`src/battle_script_commands.c`](#srcbattle_script_commandsc). To change how a move's dynamic power, accuracy and are calculated, then you need to modify the following functions:

- For power: `CalcMoveBasePowerAfterModifiers` in [`src/battle_util.c`](#srcbattle_utilc)
- For accuracy: `AccuracyCalcHelper` in [`src/battle_script_commands.c`](#srcbattle_script_commandsc)
- For type: `SetTypeBeforeUsingMove` in [`src/battle_main.c`](#srcbattle_mainc)

Note: A generic function for calculating category does not currently exist - Photon Geyser's script in [`data/battle_scripts_1.s`](#databattle_scripts_1s) uses a special `callnative` function `BS_SetPhotonGeyserCategory`.

### Changing a move's additional effects
If you look at the example [here](#srcdatamoves_infoh), you can see that Thunder Shock has an additional effects array that contains a single move effect `MOVE_EFFECT_PARALYSIS` with a 10% chance of applying. Thanks to this field, you can add and remove primary and secondary effects (so long as they are defined by a `MOVE_EFFECT`) to a move without having to change its effect or script. You can also make an effect apply to the attacker rather than the target (for, say, a stat boost) with `.self = TRUE` and you can set the probability to whatever you want with the `chance` field.

All additional effects with a defined chance (even 100%) are treated as "secondary effects". This means that they are nullified by Sheer Force, blocked by Shield Dust or the Covert Cloak, and have their chance modified by Serene Grace. Additional effects without a chance field (effectively setting it to 0) are treated as "primary effects", which means that they cannot be blocked by the aforementioned items and abilities and their chance to occur cannot be modified; they will *always* happen.

Each move can have up to 15 additional effects, allowing you to construct monstrosities like this:
```
[MOVE_POUND] =
{
    .name = COMPOUND_STRING("Pound"),
    .description = COMPOUND_STRING(
        "Pounds the foe with\n"
        "forelegs or tail."),
    .effect = EFFECT_HIT,
    .power = 40,
    .type = TYPE_NORMAL,
    .accuracy = 100,
    .pp = 35,
    .target = MOVE_TARGET_SELECTED,
    .priority = 0,
    .category = DAMAGE_CATEGORY_PHYSICAL,
    .additionalEffects = ADDITIONAL_EFFECTS({
        .moveEffect = MOVE_EFFECT_PARALYSIS,
        .chance = 10,
    },{
        .moveEffect = MOVE_EFFECT_CONFUSION,
        .chance = 100,
    },{
        .moveEffect = MOVE_EFFECT_FLINCH,
        .chance = 30,
    },{
        .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
        .chance = 40,
        .self = TRUE,
    },{
        .moveEffect = MOVE_EFFECT_RAPID_SPIN,
    },{
        .moveEffect = MOVE_EFFECT_DEF_MINUS_2,
        .chance = 50,
    }),
    .makesContact = TRUE,
    .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
    .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
    .contestCategory = CONTEST_CATEGORY_TOUGH,
    .contestComboStarterId = COMBO_STARTER_POUND,
    .contestComboMoves = {0}
},
```

**Note: at the moment, additional effects can only be used by damaging moves, not by status moves.**

## Adding a new move
To add a new move, you need to create an entry in three locations:

- a define in [`include/constants/moves.h`](#includeconstantsmovesh)
- an info entry in [`src/data/battle_moves.h`](#srcdatamoves_infoh)
- an animation entry in [data/battle_anim_scripts.s](#databattle_anim_scriptss)

And that's it! You can use an existing animation or effect for your move - or you can add your own, but I'll leave figuring that out to you.

