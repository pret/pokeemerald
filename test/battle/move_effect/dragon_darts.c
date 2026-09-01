#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
}

SINGLE_BATTLE_TEST("Dragon Darts strikes twice")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_DARTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, player);
        NOT MESSAGE("The Pokémon was hit 2 time(s)!");
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes each opponent once in a double battle")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *secondaryTarget = NULL;
    PARAMETRIZE { chosenTarget = opponentLeft; secondaryTarget = opponentRight; }
    PARAMETRIZE { chosenTarget = opponentRight; secondaryTarget = opponentLeft; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(chosenTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(secondaryTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes the other opponent twice if one target protects")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *secondaryTarget = NULL;
    PARAMETRIZE { chosenTarget = opponentLeft; secondaryTarget = opponentRight; }
    PARAMETRIZE { chosenTarget = opponentRight; secondaryTarget = opponentLeft; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(chosenTarget, MOVE_PROTECT); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, chosenTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(secondaryTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(secondaryTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes an opponent twice if the other one is Fairy-type")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    enum Species speciesLeft, speciesRight;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; speciesLeft = SPECIES_FIDOUGH;   speciesRight = SPECIES_WOBBUFFET; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentRight; speciesLeft = SPECIES_FIDOUGH;   speciesRight = SPECIES_WOBBUFFET; }
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentLeft;  speciesLeft = SPECIES_WOBBUFFET; speciesRight = SPECIES_FIDOUGH; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft;  speciesLeft = SPECIES_WOBBUFFET; speciesRight = SPECIES_FIDOUGH; }

    GIVEN {
        ASSUME(IsSpeciesOfType(SPECIES_FIDOUGH, TYPE_FAIRY ));
        ASSUME(GetMoveType(MOVE_DRAGON_DARTS) == TYPE_DRAGON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(speciesLeft);
        OPPONENT(speciesRight);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes an opponent twice if electrified and the other one has Volt Absorb")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    enum Ability abilityLeft, abilityRight;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentLeft;  abilityLeft = ABILITY_WATER_ABSORB; abilityRight = ABILITY_VOLT_ABSORB; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft;  abilityLeft = ABILITY_WATER_ABSORB; abilityRight = ABILITY_VOLT_ABSORB; }
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; abilityLeft = ABILITY_VOLT_ABSORB;  abilityRight = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentRight; abilityLeft = ABILITY_VOLT_ABSORB;  abilityRight = ABILITY_WATER_ABSORB; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LANTURN) { Ability(abilityLeft); }
        OPPONENT(SPECIES_LANTURN) { Ability(abilityRight); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes an opponent twice if electrified and the other one has Motor Drive")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    enum Ability abilityLeft, abilityRight;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentLeft;  abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_MOTOR_DRIVE; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft;  abilityLeft = ABILITY_VITAL_SPIRIT; abilityRight = ABILITY_MOTOR_DRIVE; }
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; abilityLeft = ABILITY_MOTOR_DRIVE;  abilityRight = ABILITY_VITAL_SPIRIT; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentRight; abilityLeft = ABILITY_MOTOR_DRIVE;  abilityRight = ABILITY_VITAL_SPIRIT; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(abilityLeft); }
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(abilityRight); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes an opponent twice if the other one is in a semi-invulnerable turn")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(chosenTarget, MOVE_FLY, target: playerLeft); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, chosenTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts is not effected by Wide Guard")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WIDE_GUARD); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes an opponent twice if the other one is fainted")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    u32 hpLeft, hpRight;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; hpLeft = 1; hpRight = 101; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft;  hpLeft = 101; hpRight = 1; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hpLeft); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(hpRight); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SONIC_BOOM, target: chosenTarget); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts checks the unchosen target for accuracy")
{
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_DRAGON_DARTS) == 100);
        ASSUME(GetItemHoldEffect(ITEM_BRIGHT_POWDER) == HOLD_EFFECT_EVASION_UP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
    } THEN {
        EXPECT_LT(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes the other opponent twice if the chosen target misses")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    enum Item itemLeft, itemRight;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; itemLeft = ITEM_BRIGHT_POWDER;  itemRight = ITEM_NONE; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft;  itemLeft = ITEM_NONE;           itemRight = ITEM_BRIGHT_POWDER; }

    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_DRAGON_DARTS) == 100);
        ASSUME(GetItemHoldEffect(ITEM_BRIGHT_POWDER) == HOLD_EFFECT_EVASION_UP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(itemLeft); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(itemRight); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts strikes will be both redirected to Follow Me user")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOLLOW_ME); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts fails to strike any target if under a Fairy-type follow me user")
{
    GIVEN {
        ASSUME(IsSpeciesOfType(SPECIES_FIDOUGH, TYPE_FAIRY ));
        ASSUME(GetMoveType(MOVE_DRAGON_DARTS) == TYPE_DRAGON);
        ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FIDOUGH);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOLLOW_ME); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts fails to strike the second target if first target fainted and Follow Me was active")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOLLOW_ME); MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts can be absorbed by both opponents and hit neither")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); };
        OPPONENT(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); };
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft);
            MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Dragon Darts always prints effectiveness message after every hit")
{
    // The messages are possibly incorrect if they should print the target
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CUFANT);
        OPPONENT(SPECIES_DRATINI);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("It's not very effective…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("It's super effective!");
    }
}
