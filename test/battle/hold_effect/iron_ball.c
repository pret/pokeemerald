#include "global.h"
#include "test/battle.h"

ASSUMPTIONS{
    ASSUME(gItemsInfo[ITEM_IRON_BALL].holdEffect == HOLD_EFFECT_IRON_BALL);
}

SINGLE_BATTLE_TEST("Ground-type moves do neutral damage to non-grounded Flying types holding Iron Ball regardless of other typings (Gen5+)")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_IRON_BALL, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY) { Item(ITEM_IRON_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        if (config >= GEN_5) {
            NONE_OF {
                MESSAGE("It's super effective!");
            }
        } else {
            MESSAGE("It's super effective!");
        }
    }
}
