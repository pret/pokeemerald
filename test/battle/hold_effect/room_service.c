#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ROOM_SERVICE].holdEffect == HOLD_EFFECT_ROOM_SERVICE);
}

SINGLE_BATTLE_TEST("Room Serive decreases the holder's seep by one stage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ROOM_SERVICE); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK_ROOM); }
        TURN { MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        HP_BAR(opponent);
        MESSAGE("2 sent out Wynaut!");
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}
