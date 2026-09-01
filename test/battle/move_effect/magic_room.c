#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
}

DOUBLE_BATTLE_TEST("Magic Room prevents item hold effects")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_BERRY_JUICE].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);

        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(60); Item(ITEM_BERRY_JUICE); }
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(60); Item(ITEM_BERRY_JUICE); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(60); Item(ITEM_BERRY_JUICE); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(60); Item(ITEM_BERRY_JUICE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MAGIC_ROOM); }
        TURN {
            MOVE(playerLeft, MOVE_DRAGON_RAGE, target: opponentLeft);
            MOVE(opponentLeft, MOVE_DRAGON_RAGE, target: playerLeft);
            MOVE(playerRight, MOVE_DRAGON_RAGE, target: opponentRight);
            MOVE(opponentRight, MOVE_DRAGON_RAGE, target: playerRight);
        }
        TURN { MOVE(playerLeft, MOVE_MAGIC_ROOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_ROOM, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_ROOM, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Magic Room: An item that can activate will activate once Magic Room is over")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_ROOM); MOVE(opponent, MOVE_GROWL); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Turn 3
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Turn 4
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // Turn 5
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);

        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        }

        MESSAGE("Magic Room wore off, and held items' effects returned to normal!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Magic Room (Move Effect) test titles")
