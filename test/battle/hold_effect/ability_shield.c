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
