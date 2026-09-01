#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
}

SINGLE_BATTLE_TEST("Spikes damage on switch in")
{
    u32 layers;
    u32 divisor;
    PARAMETRIZE { layers = 1; divisor = 8; }
    PARAMETRIZE { layers = 2; divisor = 6; }
    PARAMETRIZE { layers = 3; divisor = 4; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        u32 count;
        for (count = 0; count < layers; ++count) {
            TURN { MOVE(player, MOVE_SPIKES); }
        }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        u32 count;
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        for (count = 0; count < layers; ++count) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
            MESSAGE("Spikes were scattered on the ground all around the opposing side!");
        }
        MESSAGE("2 sent out Wynaut!");
        HP_BAR(opponent, damage: maxHP / divisor);
        MESSAGE("The opposing Wynaut was hurt by the spikes!");
    }
}

SINGLE_BATTLE_TEST("Spikes fails after 3 layers")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
        MESSAGE("Spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
        MESSAGE("Spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
        MESSAGE("Spikes were scattered on the ground all around the opposing side!");
        MESSAGE("Wobbuffet used Spikes!");
        MESSAGE("But it failed!");
        MESSAGE("2 sent out Wynaut!");
        HP_BAR(opponent, damage: maxHP / 4);
        MESSAGE("The opposing Wynaut was hurt by the spikes!");
    }
}

SINGLE_BATTLE_TEST("Spikes damage on subsequent switch ins")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        s32 maxHP0 = GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP);
        s32 maxHP1 = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        MESSAGE("2 sent out Wynaut!");
        HP_BAR(opponent, damage: maxHP1 / 8);
        MESSAGE("The opposing Wynaut was hurt by the spikes!");
        MESSAGE("2 sent out Wobbuffet!");
        HP_BAR(opponent, damage: maxHP0 / 8);
        MESSAGE("The opposing Wobbuffet was hurt by the spikes!");
    }
}

SINGLE_BATTLE_TEST("Spikes do not damage airborne Pokemon")
{
    enum Species species = SPECIES_WOBBUFFET;
    enum Item item = ITEM_NONE;
    enum Move move1 = MOVE_CELEBRATE;
    enum Move move2 = MOVE_CELEBRATE;
    bool32 airborne;

    ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
    PARAMETRIZE { species = SPECIES_PIDGEY; airborne = TRUE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; move1 = MOVE_INGRAIN; airborne = FALSE; }

    ASSUME(GetSpeciesAbility(SPECIES_UNOWN, 0) == ABILITY_LEVITATE);
    PARAMETRIZE { species = SPECIES_UNOWN; airborne = TRUE; }
    PARAMETRIZE { species = SPECIES_UNOWN; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_UNOWN; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { species = SPECIES_UNOWN; move1 = MOVE_INGRAIN; airborne = FALSE; }

    PARAMETRIZE { move1 = MOVE_MAGNET_RISE; airborne = TRUE; }
    PARAMETRIZE { move1 = MOVE_MAGNET_RISE; item = ITEM_IRON_BALL; airborne = FALSE; }
    PARAMETRIZE { move1 = MOVE_MAGNET_RISE; move2 = MOVE_GRAVITY; airborne = FALSE; }
    // Magnet Rise fails under Gravity.
    // Magnet Rise fails under Ingrain and vice-versa.

    PARAMETRIZE { item = ITEM_AIR_BALLOON; airborne = TRUE; }
    PARAMETRIZE { item = ITEM_AIR_BALLOON; move1 = MOVE_GRAVITY; airborne = FALSE; }
    PARAMETRIZE { item = ITEM_AIR_BALLOON; move1 = MOVE_INGRAIN; airborne = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(species) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKES); MOVE(opponent, move1); }
        TURN { MOVE(opponent, move2); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        if (airborne) {
            NOT HP_BAR(opponent, damage: maxHP / 8);
        } else {
            HP_BAR(opponent, damage: maxHP / 8);
        }
    }
}

SINGLE_BATTLE_TEST("Toxic Spikes: Only three layers can be set up")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_SPIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_SPIKES);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);
        u32 spikesAmount = gSideTimers[0].spikesAmount;
        EXPECT_EQ(spikesAmount, 3);
    }
}
