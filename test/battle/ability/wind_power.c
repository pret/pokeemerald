#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_NUZZLE) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_NUZZLE) == TYPE_ELECTRIC);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
    ASSUME(!IsWindMove(MOVE_SCRATCH));
    ASSUME(GetMoveCategory(MOVE_AIR_CUTTER) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveTarget(MOVE_AIR_CUTTER) == TARGET_BOTH);
    ASSUME(IsWindMove(MOVE_AIR_CUTTER));
    ASSUME(GetMoveCategory(MOVE_PETAL_BLIZZARD) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveTarget(MOVE_PETAL_BLIZZARD) == TARGET_FOES_AND_ALLY);
    ASSUME(IsWindMove(MOVE_PETAL_BLIZZARD));
}

SINGLE_BATTLE_TEST("Wind Power sets up Charge for player when hit by a wind move")
{
    s16 dmgBefore, dmgAfter;
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_AIR_CUTTER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(10); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(5); } // Limber, so it doesn't get paralyzed.
    } WHEN {
        TURN { MOVE(player, MOVE_NUZZLE), MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_NUZZLE), MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        HP_BAR(opponent, captureDamage: &dmgBefore);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(player, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        HP_BAR(opponent, captureDamage: &dmgAfter);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(player, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        }
    }
    THEN {
        if (move == MOVE_AIR_CUTTER) {
            EXPECT_MUL_EQ(dmgBefore, Q_4_12(2.0), dmgAfter);
        }
        else {
            EXPECT_EQ(dmgAfter, dmgBefore);
        }
    }
}

SINGLE_BATTLE_TEST("Wind Power sets up Charge for opponent when hit by a wind move")
{
    s16 dmgBefore, dmgAfter;
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_AIR_CUTTER; }

    GIVEN {
        PLAYER(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(5); } // Limber, so it doesn't get paralyzed.
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_NUZZLE), MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_NUZZLE), MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, opponent);
        HP_BAR(player, captureDamage: &dmgBefore);

        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(opponent, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged the opposing Wattrel with power!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, opponent);
        HP_BAR(player, captureDamage: &dmgAfter);

        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(opponent, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged the opposing Wattrel with power!");
        }
    }
    THEN {
        if (move == MOVE_AIR_CUTTER) {
            EXPECT_MUL_EQ(dmgBefore, Q_4_12(2.0), dmgAfter);
        }
        else {
            EXPECT_EQ(dmgAfter, dmgBefore);
        }
    }
}

SINGLE_BATTLE_TEST("Wind Power sets up Charge for only one attack when hit by a wind move")
{
    s16 dmgCharged, dmgAfter;
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_AIR_CUTTER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(5); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(10); } // Limber, so it doesn't get paralyzed.
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_NUZZLE); }
        TURN { MOVE(player, MOVE_NUZZLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(player, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        HP_BAR(opponent, captureDamage: &dmgCharged);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        HP_BAR(opponent, captureDamage: &dmgAfter);
    }
    THEN {
        if (move == MOVE_AIR_CUTTER) {
            EXPECT_MUL_EQ(dmgAfter, Q_4_12(2.0), dmgCharged);
        }
        else {
            EXPECT_EQ(dmgAfter, dmgCharged);
        }
    }
}

DOUBLE_BATTLE_TEST("Wind Power activates correctly for every battler with the ability when hit by a 2/3 target move")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_NONE, abilityRight = ABILITY_WIND_POWER; }
    PARAMETRIZE { abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_NONE; }
    PARAMETRIZE { abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_WIND_POWER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(20); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_AIR_CUTTER); MOVE(opponentRight, MOVE_AIR_CUTTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AIR_CUTTER, opponentLeft);

        HP_BAR(playerLeft);
        if (abilityLeft == ABILITY_WIND_POWER) {
            ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        }
        HP_BAR(playerRight);
        if (abilityRight == ABILITY_WIND_POWER) {
            ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        }
        NONE_OF {
            HP_BAR(opponentLeft);
            HP_BAR(opponentRight);
        }
    }
    THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Wind Power activates correctly for every battler with the ability when hit by a 3 target move")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_NONE, abilityRight = ABILITY_WIND_POWER; }
    PARAMETRIZE { abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_NONE; }
    PARAMETRIZE { abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_WIND_POWER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(20); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PETAL_BLIZZARD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_BLIZZARD, opponentLeft);

        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        HP_BAR(opponentRight);
        NOT HP_BAR(opponentLeft);
        if (abilityLeft == ABILITY_WIND_POWER) {
            ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Petal Blizzard charged Wattrel with power!");
        }
        if (abilityRight == ABILITY_WIND_POWER) {
            ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Petal Blizzard charged Wattrel with power!");
        }
    }
    THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_NE(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Wind Power activates correctly when Tailwind is used")
{
    bool8 opponentSide;

    PARAMETRIZE { opponentSide = TRUE; }
    PARAMETRIZE { opponentSide = FALSE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(5); }
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(20); }
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(15); }
    } WHEN {
        TURN { MOVE((opponentSide == TRUE) ? opponentLeft : playerLeft, MOVE_TAILWIND); }
    } SCENE {
        if (opponentSide) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);

            ABILITY_POPUP(opponentLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged the opposing Wattrel with power!");

            ABILITY_POPUP(opponentRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged the opposing Wattrel with power!");
        }
        else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, playerLeft);

            ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Wattrel with power!");

            ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Wattrel with power!");
        }
    }
}

SINGLE_BATTLE_TEST("Wind Power displays its message before fainting when triggered")
{
    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_AIR_CUTTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AIR_CUTTER, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_WIND_POWER);
        MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        MESSAGE("Wattrel fainted!");
    }
}

DOUBLE_BATTLE_TEST("Tailwind does not trigger Wind Power on an absent ally battler")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
        TURN { MOVE(playerLeft, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight);
        MESSAGE("Wattrel fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Wattrel with power!");
        }
    }
}
