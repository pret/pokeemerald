#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gSpeciesInfo[SPECIES_BISHARP].evolutions[0].params->condition == IF_DEFEAT_X_WITH_ITEMS);
    ASSUME(gSpeciesInfo[SPECIES_BISHARP].evolutions[0].params->arg1 == SPECIES_BISHARP);
    ASSUME(gSpeciesInfo[SPECIES_BISHARP].evolutions[0].params->arg2 == ITEM_LEADERS_CREST);
}

WILD_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing a Bisharp that holds Leader's Crest increases tracker")
{
    GIVEN {
        PLAYER(SPECIES_BISHARP);
        OPPONENT(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 1);
    }
}

// To be replaced with WILD_DOUBLE_BATTLE_TEST when that is made possible (also see TryUpdateEvolutionTracker)
DOUBLE_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing multiple Bisharps holding Leader's Crest increases tracker multiple times")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_LAVA_PLUME) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_BISHARP);
        PLAYER(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
        OPPONENT(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LAVA_PLUME); }
    } SCENE {
        HP_BAR(opponentLeft, hp: 0);
        HP_BAR(playerRight, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 2);
    }
}

WILD_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing a Bisharp that doesn't hold Leader's Crest doesn't increase tracker")
{
    GIVEN {
        PLAYER(SPECIES_BISHARP);
        OPPONENT(SPECIES_BISHARP) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 0);
    }
}

WILD_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing a non-Bisharp that holds Leader's Crest doesn't increase tracker")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_PAWNIARD; }
    GIVEN {
        PLAYER(SPECIES_BISHARP);
        OPPONENT(species) { Item(ITEM_LEADERS_CREST); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 0);
    }
}

WILD_BATTLE_TEST("Evolution Tracker: Pawniard KO-ing a Bisharp that holds Leader's Crest doesn't increase tracker")
{
    GIVEN {
        PLAYER(SPECIES_PAWNIARD);
        OPPONENT(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 0);
    }
}

WILD_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing eligible battler from contact effects doesn't increase tracker")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_ROCKY_HELMET) == HOLD_EFFECT_ROCKY_HELMET);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_BISHARP) { Item(ITEM_ROCKY_HELMET); }
        OPPONENT(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 0);
    }
}

WILD_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing eligible battler with passive damage doesn't increase tracker")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
        PLAYER(SPECIES_BISHARP);
        OPPONENT(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 0);
    }
}

// To be replaced with WILD_DOUBLE_BATTLE_TEST when that is made possible (also see TryUpdateEvolutionTracker)
DOUBLE_BATTLE_TEST("Evolution Tracker: Bisharp KO-ing eligible battler with bursting flames doesn't increase tracker")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_FLAME_BURST, MOVE_EFFECT_FLAME_BURST));
        PLAYER(SPECIES_BISHARP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BISHARP) { Item(ITEM_LEADERS_CREST); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLAME_BURST, target: opponentRight); }
    } SCENE {
        HP_BAR(opponentLeft, hp: 0);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EVOLUTION_TRACKER), 0);
    }
}
