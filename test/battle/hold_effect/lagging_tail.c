#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_LAGGING_TAIL].holdEffect == HOLD_EFFECT_LAGGING_TAIL);
}

DOUBLE_BATTLE_TEST("Lagging Tail priority bracket will not change if the item is removed is changed mid-turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(ITEM_LAGGING_TAIL); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Item(ITEM_BERRY_JUICE); }
        OPPONENT(SPECIES_WYNAUT) { Speed(20); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TRICK, target: playerLeft); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);

        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft); // Now last because of Tricking Lagging Tail onto itself
    }
}
