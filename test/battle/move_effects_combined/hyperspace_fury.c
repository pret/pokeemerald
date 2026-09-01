#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HYPERSPACE_FURY) == EFFECT_HYPERSPACE_FURY);
    ASSUME(MoveHasAdditionalEffect(MOVE_HYPERSPACE_FURY, MOVE_EFFECT_FEINT));
    ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_HYPERSPACE_FURY, self: TRUE, defense: -1);
    ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
}

SINGLE_BATTLE_TEST("Hyperspace Fury fails if used by a Pokémon other than Hoopa Unbound")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_HOOPA_CONFINED; }
    PARAMETRIZE { species = SPECIES_HOOPA_UNBOUND; }

    GIVEN {
        PLAYER(species);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        switch (species)
        {
        case SPECIES_HOOPA_UNBOUND:
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            break;
        case SPECIES_HOOPA_CONFINED:
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            MESSAGE("But Hoopa can't use it the way it is now!");
            break;
        case SPECIES_WOBBUFFET:
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            MESSAGE("But Wobbuffet can't use the move!");
            break;
        default:
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
            break;
        }
    }
}

DOUBLE_BATTLE_TEST("Hyperspace Fury hits the target through Protect and breaks it")
{
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGIROCK);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PROTECT); MOVE(playerLeft, MOVE_HYPERSPACE_FURY, target: opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Hyperspace Fury lowers the user's Defense by 1 stage after hitting the target")
{
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Hyperspace Fury breaks protection and lowers the user's Defense by 1 stage")
{
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGIROCK);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PROTECT); MOVE(playerLeft, MOVE_HYPERSPACE_FURY, target: opponentLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPERSPACE_FURY, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}
