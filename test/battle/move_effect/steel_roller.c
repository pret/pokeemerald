#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_STEEL_ROLLER) == EFFECT_STEEL_ROLLER);
}

// Covered in ice_spinner.c
// SINGLE_BATTLE_TEST("Ice Spinner and Steel Roller remove a terrain from field")

SINGLE_BATTLE_TEST("Steel Roller removes Terrain even if user faints during attack execution")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_STEEL_ROLLER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_ROLLER, opponent);
        MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Steel Roller removes Terrain if user is switched out due to Red Card")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_STEEL_ROLLER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_ROLLER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Steel Roller will fail if there is no Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEEL_ROLLER); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_ROLLER, opponent);
        MESSAGE("The opposing Wobbuffet used Steel Roller!");
        MESSAGE("But it failed!");
    }
}

AI_SINGLE_BATTLE_TEST("Steel Roller wont be chosen by AI if there is no terrain on the field")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_NONE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_STEEL_ROLLER, MOVE_ICE_SHARD); }
    } WHEN {
        if (move == MOVE_ELECTRIC_TERRAIN) {
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); EXPECT_MOVE(opponent, MOVE_ICE_SHARD); }
            TURN { EXPECT_MOVE(opponent, MOVE_STEEL_ROLLER); }
        } else {
            TURN { EXPECT_MOVE(opponent, MOVE_ICE_SHARD); }
        }
    }
}

SINGLE_BATTLE_TEST("Steel Roller will remove terrain if target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_STEEL_ROLLER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_ROLLER, opponent);
        NOT HP_BAR(player);
    }
}
