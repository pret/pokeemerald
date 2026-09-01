#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Revive restores a fainted battler's HP to half")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(200); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVE, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored.");
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Max Revive restores a fainted battler's HP fully")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(200); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_MAX_REVIVE, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored.");
    } THEN {
        EXPECT_EQ(player->hp, 200);
    }
}

SINGLE_BATTLE_TEST("Revival Herb restores a fainted battler's HP fully")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVAL_HERB].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(200); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVAL_HERB, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored.");
    } THEN {
        EXPECT_EQ(player->hp, 200);
    }
}

SINGLE_BATTLE_TEST("Max Honey restores a fainted battler's HP fully")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_HONEY].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(200); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_MAX_HONEY, partyIndex: 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        MESSAGE("Wynaut had its HP restored.");
    } THEN {
        EXPECT_EQ(player->hp, 200);
    }
}

// Note: this test is oddly specific with implicit moves/speeds, because I had errors/invalids without them.
DOUBLE_BATTLE_TEST("Revive works for a partner in a double battle")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WYNAUT) { HP(1); MaxHP(200); Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(4); }
        OPPONENT(SPECIES_ABRA) { Speed(3); }
        OPPONENT(SPECIES_KADABRA) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_PSYCHIC, target:playerLeft); } // Wynaut faints
        TURN { USE_ITEM(playerRight, ITEM_REVIVE, partyIndex: 0); MOVE(opponentRight, MOVE_PSYCHIC, target:playerRight); } // Wynaut gets revived, Wobb faints
        // Wynaut is functionally back
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target:playerLeft); }
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target:playerLeft); }
        TURN { MOVE(opponentRight, MOVE_EXPLOSION); } // Everyone dies, the test can finish.
    } SCENE {
        MESSAGE("Wynaut fainted!");
        MESSAGE("You used Revive!");
        // Switch-in animation
        MESSAGE("Wobbuffet fainted!");
        HP_BAR(playerLeft);
        HP_BAR(playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Revive can trigger switch-in abilities")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
        TURN { USE_ITEM(playerRight, ITEM_REVIVE, partyIndex: 0); SKIP_TURN(playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Revive does reset abilities")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_WORRY_SEED, target: playerLeft); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
        TURN { USE_ITEM(playerRight, ITEM_REVIVE, partyIndex: 0); SKIP_TURN(playerLeft); MOVE(opponentRight, MOVE_SPORE, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Revive does not grant a mon its pre-death status condition")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_SLEEP); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
        TURN { USE_ITEM(playerLeft, ITEM_REVIVE, partyIndex: 1); SKIP_TURN(playerRight); }
    } THEN {
        EXPECT_EQ(opponentRight->status1, 0);
    }
}

DOUBLE_BATTLE_TEST("Revive does not grant a mon its pre-death stat change")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SWORDS_DANCE); MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
        TURN { USE_ITEM(playerLeft, ITEM_REVIVE, partyIndex: 1); SKIP_TURN(playerRight); }
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Revive does not grant a mon its pre-death types")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_MAX_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        ASSUME(GetMoveEffect(MOVE_REFLECT_TYPE) == EFFECT_REFLECT_TYPE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POOCHYENA);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_REFLECT_TYPE, target: opponentRight); MOVE(opponentLeft, MOVE_PSYSHOCK, target: playerRight); MOVE(opponentRight, MOVE_SCRATCH, target: playerRight); }
        TURN { USE_ITEM(playerLeft, ITEM_MAX_REVIVE, partyIndex: 1); SKIP_TURN(playerRight); MOVE(opponentLeft, MOVE_PSYCHIC, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, opponentLeft);
    } THEN {
        EXPECT_LT(playerRight->hp, playerRight->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Revive force revived pokemon to replace absent battler immediately", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_INTIMIDATE; }
    PARAMETRIZE { ability = ABILITY_SHED_SKIN; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ARBOK) { Ability(ability); HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
        TURN { USE_ITEM(playerRight, ITEM_REVIVE, partyIndex: 2); SKIP_TURN(playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        if (ability == ABILITY_INTIMIDATE)
        {
            ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Revive keeps Mimikyu Busted forms and Eiscue Noice in their current forms")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_MIMIKYU_BUSTED;       ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_BUSTED_TOTEM; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_EISCUE_NOICE;         ability = ABILITY_ICE_FACE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        ASSUME(GetMoveCategory(MOVE_CRUNCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(species) { HP(1); Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CRUNCH); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVE, partyIndex: 0); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CRUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, opponent);
        NOT ABILITY_POPUP(player, ability);
        HP_BAR(player);
    }
}

TO_DO_BATTLE_TEST("Revive won't restore a battler's HP if it hasn't fainted")
