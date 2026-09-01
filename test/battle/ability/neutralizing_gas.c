#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Neutralizing Gas activates on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents opponent's switch-in ability from activating")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_ZEKROM) { Ability(ABILITY_TERAVOLT); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_TERAVOLT);
            MESSAGE("The opposing Zekrom is radiating a bursting aura!");
        }
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas prevents ally's switch-in ability from activating")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_ZEKROM) { Ability(ABILITY_TERAVOLT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_TERAVOLT);
            MESSAGE("Zekrom is radiating a bursting aura!");
        }
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ignores all battlers' ability effects")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_WATER_ABSORB); }
        OPPONENT(SPECIES_BELLIBOLT) { Ability(ABILITY_ELECTROMORPHOSIS); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF); MOVE(playerRight, MOVE_SURF); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_TELEPATHY);
            ABILITY_POPUP(opponentLeft, ABILITY_WATER_ABSORB);
            ABILITY_POPUP(opponentRight, ABILITY_ELECTROMORPHOSIS);
        }
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerRight);
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_WATER_ABSORB);
            ABILITY_POPUP(opponentRight, ABILITY_ELECTROMORPHOSIS);
        }
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from attacker's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        OPPONENT(SPECIES_AZUMARILL) { Ability(ABILITY_HUGE_POWER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from target's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH) == TRUE);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        OPPONENT(SPECIES_BEWEAR) { Ability(ABILITY_FLUFFY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from target's ally's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CLEFAIRY) { Ability(ABILITY_FRIEND_GUARD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas ignores multipliers from ally's ability", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WEEZING) { Ability(ability); }
        PLAYER(SPECIES_WO_CHIEN) { Ability(ABILITY_TABLETS_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas leaving the field allows abilities to activate in turn order")
{
    u32 speedPlayerRight, speedOppLeft, speedOppRight;
    PARAMETRIZE { speedPlayerRight = 5; speedOppLeft = 3; speedOppRight = 2; }
    PARAMETRIZE { speedPlayerRight = 3; speedOppLeft = 5; speedOppRight = 2; }
    PARAMETRIZE { speedPlayerRight = 2; speedOppLeft = 3; speedOppRight = 5; }
    PARAMETRIZE { speedPlayerRight = 3; speedOppLeft = 2; speedOppRight = 5; }
    PARAMETRIZE { speedPlayerRight = 2; speedOppLeft = 5; speedOppRight = 3; }
    PARAMETRIZE { speedPlayerRight = 5; speedOppLeft = 2; speedOppRight = 3; }
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(4); }
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); Speed(speedPlayerRight); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); Speed(speedOppLeft); }
        OPPONENT(SPECIES_ZEKROM) { Ability(ABILITY_TERAVOLT); Speed(speedOppRight); }
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        if (speedPlayerRight > speedOppLeft)
        {
            if (speedPlayerRight > speedOppRight) {
                ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                if (speedOppRight > speedOppLeft) {
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                    ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                } else {
                    ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                }
            } else {
                ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
            }

        } else {
            if (speedOppLeft > speedOppRight) {
                ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                if (speedOppRight > speedPlayerRight) {
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                    ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                } else {
                    ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
                    ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                }
            } else {
                ABILITY_POPUP(opponentRight, ABILITY_TERAVOLT);
                ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
                ABILITY_POPUP(playerRight, ABILITY_INTREPID_SWORD);
            }
        }
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents Insomnia from blocking Rest")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); HP(1); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_INSOMNIA);
        // ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        // STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents Trace from copying it")
{
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TRACE);
            ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        }
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas prevents Contrary inverting stat boosts")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        PLAYER(SPECIES_INKAY) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_GT(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_LT(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting the field does not activate abilities that were not suppressed by it again")
{
    enum Species species;
    enum Ability ability;
    // These are the only abilities that could immediately activate again
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }

    GIVEN {
        ASSUME(gAbilitiesInfo[ability].cantBeSuppressed);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ability);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ability);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting the field does not activate Imposter even if it did not activate before")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_IMPOSTER);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ABILITY_IMPOSTER);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting the field does not activate Air Lock/Cloud Nine but their effects are kept")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GOLDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_LUDICOLO) { Ability(ABILITY_RAIN_DISH); }
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_AIR_LOCK);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ABILITY_AIR_LOCK);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        NOT ABILITY_POPUP(opponent, ABILITY_RAIN_DISH);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas only displays exiting message for the last user leaving the field")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT MESSAGE("The effects of the neutralizing gas wore off!");
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas is active for the duration of a Spread Move even if Neutralizing Gas is no longer on the field")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_ORIGIN_PULSE) == TARGET_BOTH);
        PLAYER(SPECIES_WEEZING) { HP(1); Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_GOLEM) { Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_BASCULEGION) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ORIGIN_PULSE); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ORIGIN_PULSE, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("Weezing fainted!");
        MESSAGE("Golem fainted!");
        NOT ABILITY_POPUP(playerRight, ABILITY_STURDY);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas is active until the last Dragon Darts hit even if Neutralizing Gas is no longer on the field")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        PLAYER(SPECIES_WEEZING) { HP(1); Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_GOLEM) { HP(2); MaxHP(2); Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_BASCULEGION) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DRAGON_DARTS, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Weezing fainted!");
        HP_BAR(playerRight);
        NOT MESSAGE("Golem fainted!");
        ABILITY_POPUP(playerRight, ABILITY_STURDY);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas doesn't reactivate Beads of Ruin after Chi-Yu faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(2); }
        OPPONENT(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); HP(1); Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The opposing Chi-Yu fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NONE_OF {
            ABILITY_POPUP(opponentRight, ABILITY_BEADS_OF_RUIN);
            MESSAGE("The opposing Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        }
        MESSAGE("The opposing Weezing fainted!");
    }
}
