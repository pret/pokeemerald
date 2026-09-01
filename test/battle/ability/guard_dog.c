#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Guard Dog raises Attack when intimidated", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INTIMIDATE; }
    PARAMETRIZE { ability = ABILITY_SHED_SKIN; }
    GIVEN {
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (ability == ABILITY_INTIMIDATE)
        {
            ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
            ABILITY_POPUP(player, ABILITY_GUARD_DOG);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Okidogi's Attack rose!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Guard Dog raises Attack before Adrenaline Orb when Intimidated")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ADRENALINE_ORB].holdEffect == HOLD_EFFECT_ADRENALINE_ORB);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); Item(ITEM_ADRENALINE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ABILITY_GUARD_DOG);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Okidogi's Attack rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Guard Dog still raises Attack against Intimidate when holding Clear Amulet")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); Item(ITEM_CLEAR_AMULET); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ABILITY_GUARD_DOG);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Okidogi's Attack rose!");
        NOT MESSAGE("The effects of the Clear Amulet held by Okidogi prevents its stats from being lowered!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Guard Dog does not activate if Intimidate is blocked by Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_GUARD_DOG);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Okidogi's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Guard Dog does not activate if Intimidate is blocked by Mist")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIST) == EFFECT_MIST);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIST); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, player);
        MESSAGE("Okidogi surrounds itself with a protective mist!");
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_GUARD_DOG);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Okidogi's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Guard Dog does not activate if Intimidate cannot lower Attack at minimum stage")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_GUARD_DOG);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Okidogi's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], MIN_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Guard Dog does not activate if Intimidate is blocked by Flower Veil")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FORESTS_CURSE) == EFFECT_THIRD_TYPE);
        ASSUME(GetMoveArgType(MOVE_FORESTS_CURSE) == TYPE_GRASS);
        PLAYER(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); Speed(40); }
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FORESTS_CURSE, target: playerRight); }
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FORESTS_CURSE, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_FLOWER_VEIL);
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_GUARD_DOG);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Okidogi's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(playerRight->types[2], TYPE_GRASS);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Guard Dog activates before Flower Veil if it has higher unmodified Speed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FORESTS_CURSE) == EFFECT_THIRD_TYPE);
        ASSUME(GetMoveArgType(MOVE_FORESTS_CURSE) == TYPE_GRASS);
        PLAYER(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); Speed(30); }
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); Speed(40); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FORESTS_CURSE, target: playerRight); }
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FORESTS_CURSE, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_GUARD_DOG);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Okidogi's Attack rose!");
        NOT ABILITY_POPUP(playerLeft, ABILITY_FLOWER_VEIL);
    } THEN {
        EXPECT_EQ(playerRight->types[2], TYPE_GRASS);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}
