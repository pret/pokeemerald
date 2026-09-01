#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Intrepid Sword raises Attack by one stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zacian's Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Intrepid Sword raises Attack by one stage every time it switches in (Gen8)")
{
    GIVEN {
        WITH_CONFIG(B_INTREPID_SWORD, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zacian's Attack rose!");
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zacian's Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Intrepid Sword raises Attack by one stage only once per battle (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(B_INTREPID_SWORD, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zacian's Attack rose!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Zacian's Attack rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Intrepid Sword activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zacian's Attack rose!");
    }
}

SINGLE_BATTLE_TEST("Intrepid Sword and Dauntless Shield both can be Skill Swapped and active their effects on the Skill Swap user")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zacian's Attack rose!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        ABILITY_POPUP(player, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose!");

        ABILITY_POPUP(opponent, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zamazenta's Defense rose!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        ABILITY_POPUP(player, ABILITY_DAUNTLESS_SHIELD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense rose!");
    }
}

SINGLE_BATTLE_TEST("Intrepid Sword and Dauntless Shield do not proc at max stage (Skill Swap)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DAUNTLESS_SHIELD);
            ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        }
    }
}

SINGLE_BATTLE_TEST("Intrepid Sword and Dauntless Shield do not proc at max stage (Baton Pass)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZAMAZENTA) { Ability(ABILITY_DAUNTLESS_SHIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_IRON_DEFENSE); MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_BATON_PASS); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DAUNTLESS_SHIELD);
            ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        }
    }
}
