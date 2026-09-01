#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Primal Reversion happens for Groudon only when holding Red Orb")
{
    enum Item heldItem;
    PARAMETRIZE { heldItem = ITEM_NONE; }
    PARAMETRIZE { heldItem = ITEM_RED_ORB; }
    PARAMETRIZE { heldItem = ITEM_BLUE_ORB; }
    GIVEN {
        PLAYER(SPECIES_GROUDON) { Item(heldItem); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        if (heldItem == ITEM_RED_ORB) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
            MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
        }
        else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
                MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
            }
        }
    } THEN {
        if (heldItem == ITEM_RED_ORB) {
            EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
        }
        else {
            EXPECT_EQ(player->species, SPECIES_GROUDON);
        }
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens for Kyogre only when holding Blue Orb")
{
    enum Item heldItem;
    PARAMETRIZE { heldItem = ITEM_NONE; }
    PARAMETRIZE { heldItem = ITEM_RED_ORB; }
    PARAMETRIZE { heldItem = ITEM_BLUE_ORB; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KYOGRE) { Item(heldItem); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (heldItem == ITEM_BLUE_ORB) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponent);
            MESSAGE("The opposing Kyogre's Primal Reversion! It reverted to its primal state!");
        }
        else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponent);
                MESSAGE("The opposing Kyogre's Primal Reversion! It reverted to its primal state!");
            }
        }
    } THEN {
        if (heldItem == ITEM_BLUE_ORB) {
            EXPECT_EQ(opponent->species, SPECIES_KYOGRE_PRIMAL);
        }
        else {
            EXPECT_EQ(opponent->species, SPECIES_KYOGRE);
        }
    }
}

DOUBLE_BATTLE_TEST("Primal Reversion's order is determined by Speed - opponent faster")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); Speed(5); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(15); }
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(10); }
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); Speed(20); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentRight);
        MESSAGE("The opposing Kyogre's Primal Reversion! It reverted to its primal state!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, playerRight);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentLeft);
        MESSAGE("The opposing Groudon's Primal Reversion! It reverted to its primal state!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, playerLeft);
        MESSAGE("Kyogre's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_KYOGRE_PRIMAL);
        EXPECT_EQ(opponentLeft->species, SPECIES_GROUDON_PRIMAL);
        EXPECT_EQ(opponentRight->species, SPECIES_KYOGRE_PRIMAL);
        EXPECT_EQ(playerRight->species, SPECIES_GROUDON_PRIMAL);
    }
}

DOUBLE_BATTLE_TEST("Primal Reversion's order is determined by Speed - player faster")
{
    GIVEN {
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); Speed(20); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(30); }
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(10); }
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); Speed(2); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, playerRight);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, playerLeft);
        MESSAGE("Kyogre's Primal Reversion! It reverted to its primal state!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentLeft);
        MESSAGE("The opposing Groudon's Primal Reversion! It reverted to its primal state!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentRight);
        MESSAGE("The opposing Kyogre's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_KYOGRE_PRIMAL);
        EXPECT_EQ(opponentLeft->species, SPECIES_GROUDON_PRIMAL);
        EXPECT_EQ(opponentRight->species, SPECIES_KYOGRE_PRIMAL);
        EXPECT_EQ(playerRight->species, SPECIES_GROUDON_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens after a mon is sent out after a mon is fainted")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens after a mon is switched in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens after a switch-in caused by Eject Button")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet is switched out with the Eject Button!");
        SEND_IN_MESSAGE("Groudon");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens after a switch-in caused by Red Card")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("Groudon was dragged out!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens after the entry hazards damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPIKES); }
        TURN { MOVE(opponent, MOVE_SPIKES); SWITCH(player, 1); }
    } SCENE {
        SEND_IN_MESSAGE("Groudon");
        HP_BAR(player);
        MESSAGE("Groudon was hurt by the spikes!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion happens immediately if it was brought in by U-turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
        MESSAGE("Groudon's Primal Reversion! It reverted to its primal state!");
        MESSAGE("2 sent out Wynaut!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_GROUDON_PRIMAL);
    }
}


DOUBLE_BATTLE_TEST("Primal Reversion triggers for multiple battlers if multiple fainted the previous turn")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CATERPIE) { HP(1); }
        PLAYER(SPECIES_RESHIRAM);
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE);
               SEND_OUT(opponentRight, 3);
               SEND_OUT(opponentLeft, 2);
               SEND_OUT(playerRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_PRIMORDIAL_SEA);
        ABILITY_POPUP(opponentRight, ABILITY_DESOLATE_LAND);
    }
}

DOUBLE_BATTLE_TEST("Primal Reversion triggers for all battlers if multiple fainted the previous turn")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CATERPIE) { HP(1); }
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION);
               SEND_OUT(opponentRight, 3);
               SEND_OUT(opponentLeft, 2);
               SEND_OUT(playerRight, 3);
               SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_PRIMORDIAL_SEA);
        ABILITY_POPUP(playerRight, ABILITY_DESOLATE_LAND);
        ABILITY_POPUP(opponentLeft, ABILITY_PRIMORDIAL_SEA);
        ABILITY_POPUP(opponentRight, ABILITY_DESOLATE_LAND);
    }
}

DOUBLE_BATTLE_TEST("Primal Reversion and other switch-in effects trigger for all battlers if multiple fainted the previous turn")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_CATERPIE) { Speed(8); HP(1); }
        PLAYER(SPECIES_SCRAFTY) { Speed(100); Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_RESHIRAM) { Speed(90); }
        OPPONENT(SPECIES_CATERPIE) { Speed(9); HP(1); }
        OPPONENT(SPECIES_CATERPIE) { Speed(7); HP(1); }
        OPPONENT(SPECIES_KYOGRE) { Speed(80); Item(ITEM_BLUE_ORB); }
        OPPONENT(SPECIES_GROUDON) { Speed(70); Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STICKY_WEB);
               MOVE(opponentLeft, MOVE_SPIKES);
               MOVE(playerRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(playerLeft, MOVE_EXPLOSION);
               SEND_OUT(opponentRight, 3);
               SEND_OUT(opponentLeft, 2);
               SEND_OUT(playerRight, 3);
               SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ABILITY_POPUP(playerRight, ABILITY_TURBOBLAZE);
        ABILITY_POPUP(opponentLeft, ABILITY_PRIMORDIAL_SEA);
        ABILITY_POPUP(opponentRight, ABILITY_DESOLATE_LAND);
    } THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_EQ(opponentLeft->status1, STATUS1_POISON);
        EXPECT_EQ(opponentRight->status1, STATUS1_POISON);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion is reverted upon battle end")
{
    enum Species species;
    enum Item item;
    PARAMETRIZE { species = SPECIES_GROUDON; item = ITEM_RED_ORB; }
    PARAMETRIZE { species = SPECIES_KYOGRE;  item = ITEM_BLUE_ORB; }
    GIVEN {
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), species);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion is NOT reverted upon fainting")
{
    enum Species species, targetSpecies;
    enum Item item;
    PARAMETRIZE { species = SPECIES_GROUDON; item = ITEM_RED_ORB;  targetSpecies = SPECIES_GROUDON_PRIMAL; }
    PARAMETRIZE { species = SPECIES_KYOGRE;  item = ITEM_BLUE_ORB; targetSpecies = SPECIES_KYOGRE_PRIMAL;  }
    GIVEN {
        PLAYER(species) { HP(1); Item(item); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_CELEBRATE);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, targetSpecies);
    }
}
