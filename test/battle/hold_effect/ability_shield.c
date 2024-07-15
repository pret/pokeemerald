#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
}

SINGLE_BATTLE_TEST("Ability Shield prevents Neutralizing Gas")
{
    u32 item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); Item(item); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing Gas filled the area!");
        if (item == ITEM_ABILITY_SHIELD) {
            ABILITY_POPUP(player, ABILITY_DROUGHT);
            MESSAGE("Torkoal's Drought intensified the sun's rays!");
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_DROUGHT);
                MESSAGE("Torkoal's Drought intensified the sun's rays!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Mold Breaker")
{
    u32 item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); Item(item); }
        OPPONENT(SPECIES_TINKATON) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GIGATON_HAMMER); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                MESSAGE("Shedinja fainted!");
            }
        } else {
            MESSAGE("Shedinja fainted!");
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Mycelium Might")
{
    u32 item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_VIGOROTH) { Ability(ABILITY_VITAL_SPIRIT); Item(item); }
        OPPONENT(SPECIES_TOEDSCOOL) { Ability(ABILITY_MYCELIUM_MIGHT); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_SPORE); }
    } SCENE {
        
        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
                STATUS_ICON(player, sleep: TRUE);
            }
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            STATUS_ICON(player, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Sunsteel Strike")
{
    u32 item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNSTEEL_STRIKE); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                MESSAGE("Shedinja fainted!");
            }
        } else {
            MESSAGE("Shedinja fainted!");
        }
    }
}
