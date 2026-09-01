#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ADRENALINE_ORB].holdEffect == HOLD_EFFECT_ADRENALINE_ORB);
}

SINGLE_BATTLE_TEST("Adrenaline Orb raises Speed by one stage if Intimidated")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ADRENALINE_ORB); }
    } WHEN {
        TURN {  }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Speed rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Adrenaline Orb drops speed by one stage if user has Contrary")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SPINDA) { Ability(ABILITY_CONTRARY); Item(ITEM_ADRENALINE_ORB); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Spinda's Attack rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Spinda's Speed fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Adrenaline Orb activates after Defiant")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); Item(ITEM_ADRENALINE_ORB); }
    } WHEN {
        TURN {  }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ABILITY_POPUP(opponent, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Mankey's Attack rose sharply!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Mankey's Speed rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Adrenaline Orb doesn't activate if attack doesn't drop")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_INCINEROAR) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MIN_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}
