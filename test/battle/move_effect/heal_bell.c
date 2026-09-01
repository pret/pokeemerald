#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_HEAL_BELL) == EFFECT_HEAL_BELL);
    ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_SPARKLY_SWIRL, MOVE_EFFECT_AROMATHERAPY));
}

DOUBLE_BATTLE_TEST("Sparkly Swirl cures the entire party")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPARKLY_SWIRL, target: opponentLeft); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); }
    } SCENE {
        int i;

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLY_SWIRL, playerLeft);
        STATUS_ICON(playerLeft, none: TRUE);
        STATUS_ICON(playerRight, none: TRUE);
        NOT MESSAGE("Wobbuffet was hurt by its poisoning!");
        for (i = 0; i < PARTY_SIZE; i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_STATUS), STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Heal Bell/Aromatherapy cures the entire party of the user from primary status effects")
{
    u32 j, move, status;
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_SLEEP; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_SLEEP; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_POISON; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_POISON; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_BURN; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_BURN; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_FREEZE; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_FREEZE; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_PARALYSIS; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_PARALYSIS; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { move = MOVE_HEAL_BELL;    status = STATUS1_FROSTBITE; }
    PARAMETRIZE { move = MOVE_AROMATHERAPY; status = STATUS1_FROSTBITE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
        PLAYER(SPECIES_WOBBUFFET) {
            if (status != STATUS1_SLEEP && status != STATUS1_FREEZE)
                Status1(status);
        }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, move, target: playerLeft, WITH_RNG(RNG_PARALYSIS, FALSE)); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        switch(status)
        {
        case STATUS1_SLEEP:
            STATUS_ICON(playerLeft, sleep: FALSE);
            STATUS_ICON(playerRight, sleep: FALSE);
            break;
        case STATUS1_POISON:
            STATUS_ICON(playerLeft, poison: FALSE);
            STATUS_ICON(playerRight, poison: FALSE);
            break;
        case STATUS1_BURN:
            STATUS_ICON(playerLeft, burn: FALSE);
            STATUS_ICON(playerRight, burn: FALSE);
            break;
        case STATUS1_PARALYSIS:
            STATUS_ICON(playerLeft, paralysis: FALSE);
            STATUS_ICON(playerRight, paralysis: FALSE);
            break;
        case STATUS1_TOXIC_POISON:
            STATUS_ICON(playerLeft, badPoison: FALSE);
            STATUS_ICON(playerRight, badPoison: FALSE);
            break;
        case STATUS1_FROSTBITE:
            STATUS_ICON(playerLeft, frostbite: FALSE);
            STATUS_ICON(playerRight, frostbite: FALSE);
            break;
        }
        for (j = 0; j < PARTY_SIZE; j++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_STATUS), STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("Heal Bell does not cure Soundproof partners (Gen 4, Gen 6+)")
{
    enum Ability ability;
    u32 config;

    PARAMETRIZE { ability = ABILITY_SCRAPPY;    config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_6; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_HEAL_BELL));
        WITH_CONFIG(B_HEAL_BELL_SOUNDPROOF, config);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_EXPLOUD) { Ability(ability); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HEAL_BELL, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, playerLeft);
        if (ability == ABILITY_SOUNDPROOF && config != GEN_5) {
            MESSAGE("Exploud was hurt by its poisoning!");
        } else {
            NOT MESSAGE("Exploud was hurt by its poisoning!");
        }
    }
}

SINGLE_BATTLE_TEST("Heal Bell cures inactive Soundproof Pokemon (Gen5+)")
{
    u32 config;
    enum Ability ability;

    PARAMETRIZE { config = GEN_4, ability = ABILITY_SCRAPPY; }
    PARAMETRIZE { config = GEN_4, ability = ABILITY_SOUNDPROOF; }
    PARAMETRIZE { config = GEN_5, ability = ABILITY_SOUNDPROOF; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_HEAL_BELL));
        WITH_CONFIG(B_HEAL_BELL_SOUNDPROOF, config);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_EXPLOUD) { Ability(ability); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_HEAL_BELL, target: player); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, player);
        SEND_IN_MESSAGE("Exploud");
        if (ability == ABILITY_SCRAPPY || config >= GEN_5) {
            NOT MESSAGE("Exploud was hurt by its poisoning!");
        } else {
            MESSAGE("Exploud was hurt by its poisoning!");
        }
    }
}


SINGLE_BATTLE_TEST("Heal Bell cures a Soundproof user (Gen5, Gen8+)")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    PARAMETRIZE { config = GEN_6; }
    PARAMETRIZE { config = GEN_8; }
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HEAL_BELL));
        WITH_CONFIG(B_HEAL_BELL_SOUNDPROOF, config);
        PLAYER(SPECIES_EXPLOUD) { Ability(ABILITY_SOUNDPROOF); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_HEAL_BELL, target: player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, player);
        if (config == GEN_5 || config >= GEN_8) {
            NOT MESSAGE("Exploud was hurt by its poisoning!");
        } else {
            MESSAGE("Exploud was hurt by its poisoning!");
        }
    }
}

DOUBLE_BATTLE_TEST("Aromatherapy cure Soundproof battlers regardless of config")
{
    enum Ability ability;
    u32 config;

    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_6; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; config = GEN_8; }

    GIVEN {
        ASSUME(!IsSoundMove(MOVE_AROMATHERAPY));
        WITH_CONFIG(B_HEAL_BELL_SOUNDPROOF, config);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_EXPLOUD) { Ability(ability); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AROMATHERAPY, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATHERAPY, playerLeft);
        NONE_OF {
            MESSAGE("Exploud was hurt by its poisoning!");
            MESSAGE("Wobbuffet was hurt by its poisoning!");
        }
    }
}

SINGLE_BATTLE_TEST("Aromatherapy cures inactive Soundproof Pokemon regardless of config")
{
    u32 config;
    enum Ability ability;

    PARAMETRIZE { config = GEN_4, ability = ABILITY_SOUNDPROOF; }
    PARAMETRIZE { config = GEN_5, ability = ABILITY_SOUNDPROOF; }

    GIVEN {
        ASSUME(!IsSoundMove(MOVE_AROMATHERAPY));
        WITH_CONFIG(B_HEAL_BELL_SOUNDPROOF, config);
        PLAYER(SPECIES_WOBBUFFET) { }
        PLAYER(SPECIES_EXPLOUD) { Ability(ability); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_AROMATHERAPY, target: player); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATHERAPY, player);
        SEND_IN_MESSAGE("Exploud");
        NOT MESSAGE("Exploud was hurt by its poisoning!");
    }
}

DOUBLE_BATTLE_TEST("Aromatherapy will be blocked on ally by Sap Sipper but not user")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_AROMATHERAPY) == TYPE_GRASS);
        PLAYER(SPECIES_MARILL) { Ability(ABILITY_SAP_SIPPER); }
        PLAYER(SPECIES_MARILL) { Ability(ABILITY_SAP_SIPPER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AROMATHERAPY); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_SAP_SIPPER);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Marill's Attack rose!");
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}
