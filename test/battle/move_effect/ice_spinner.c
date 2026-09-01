#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ICE_SPINNER) == EFFECT_ICE_SPINNER);
}

SINGLE_BATTLE_TEST("Ice Spinner and Steel Roller remove a terrain from field")
{
    u32 j;
    static const enum Move terrainMoves[] =
    {
        MOVE_ELECTRIC_TERRAIN,
        MOVE_PSYCHIC_TERRAIN,
        MOVE_GRASSY_TERRAIN,
        MOVE_MISTY_TERRAIN,
    };

    enum Move terrainMove = MOVE_NONE;
    enum Move removeTerrainMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(terrainMoves); j++)
    {
        PARAMETRIZE { removeTerrainMove = MOVE_STEEL_ROLLER; terrainMove = terrainMoves[j]; }
        PARAMETRIZE { removeTerrainMove = MOVE_ICE_SPINNER; terrainMove =  terrainMoves[j]; }
    }

    GIVEN {
        ASSUME(GetMoveEffect(terrainMove) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_ELECTRIC_TERRAIN) == B_TERRAIN_ELECTRIC);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        ASSUME(GetMoveTerrainType(MOVE_MISTY_TERRAIN) == B_TERRAIN_MISTY);
        ASSUME(GetMoveEffect(MOVE_STEEL_ROLLER) == EFFECT_STEEL_ROLLER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, terrainMove); MOVE(player, removeTerrainMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, terrainMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, removeTerrainMove, player);
        switch (terrainMove)
        {
        case MOVE_ELECTRIC_TERRAIN:
            MESSAGE("The electricity disappeared from the battlefield.");
            break;
        case MOVE_PSYCHIC_TERRAIN:
            MESSAGE("The weirdness disappeared from the battlefield!");
            break;
        case MOVE_GRASSY_TERRAIN:
            MESSAGE("The grass disappeared from the battlefield.");
            break;
        case MOVE_MISTY_TERRAIN:
            MESSAGE("The mist disappeared from the battlefield.");
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Ice Spinner fails to remove terrain if user faints during attack execution (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_ICE_SPINNER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_SPINNER, opponent);
        NOT MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Ice Spinner removes terrain if user faints during attack execution (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_CHAMPIONS);
        PLAYER(SPECIES_SHARPEDO) { Ability(ABILITY_ROUGH_SKIN); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_ICE_SPINNER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_SPINNER, opponent);
        MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Ice Spinner will not be remove Terrain if user is switched out due to Red Card")
{
    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_ICE_SPINNER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_SPINNER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        NOT MESSAGE("The electricity disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Ice Spinner doesn't fail if there is no terrain on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ICE_SPINNER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_SPINNER, player);
        NONE_OF {
            MESSAGE("But it failed!");
            MESSAGE("Mist swirled around the battlefield!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("Ice Spinner can be chosen by AI regardless if there is a terrain or not")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_NONE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ICE_SPINNER, MOVE_ICE_SHARD); }
    } WHEN {
        if (move == MOVE_ELECTRIC_TERRAIN) {
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); EXPECT_MOVE(opponent, MOVE_ICE_SPINNER); }
            TURN { EXPECT_MOVE(opponent, MOVE_ICE_SPINNER); }
        } else {
            TURN { EXPECT_MOVE(opponent, MOVE_ICE_SPINNER); }
        }
    }
}

SINGLE_BATTLE_TEST("Ice Spinner will remove terrain if target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_ICE_SPINNER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_SPINNER, opponent);
        SUB_HIT(player);
        NOT HP_BAR(player);
    }
}
