#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_THUNDERBOLT].power != 0);
    ASSUME(gMovesInfo[MOVE_THUNDERBOLT].type == TYPE_ELECTRIC);
    ASSUME(gMovesInfo[MOVE_TACKLE].power != 0);
    ASSUME(gMovesInfo[MOVE_AIR_CUTTER].power != 0);
    ASSUME(gMovesInfo[MOVE_AIR_CUTTER].target == MOVE_TARGET_BOTH);
    ASSUME(gMovesInfo[MOVE_AIR_CUTTER].windMove == TRUE);
    ASSUME(gMovesInfo[MOVE_PETAL_BLIZZARD].power != 0);
    ASSUME(gMovesInfo[MOVE_PETAL_BLIZZARD].target == MOVE_TARGET_FOES_AND_ALLY);
    ASSUME(gMovesInfo[MOVE_PETAL_BLIZZARD].windMove == TRUE);
    ASSUME(gMovesInfo[MOVE_TACKLE].windMove == FALSE);
}

SINGLE_BATTLE_TEST("Wind Power sets up Charge for player when hit by a wind move")
{
    s16 dmgBefore, dmgAfter;
    u16 move;

    PARAMETRIZE {move = MOVE_TACKLE; }
    PARAMETRIZE {move = MOVE_AIR_CUTTER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) {Ability(ABILITY_LIMBER); Speed(5) ;} // Limber, so it doesn't get paralyzed.
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT), MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_THUNDERBOLT), MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &dmgBefore);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(player, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Wattrel with power!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
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
    u16 move;

    PARAMETRIZE {move = MOVE_TACKLE; }
    PARAMETRIZE {move = MOVE_AIR_CUTTER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {Ability(ABILITY_LIMBER); Speed(5) ;} // Limber, so it doesn't get paralyzed.
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDERBOLT), MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_THUNDERBOLT), MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, opponent);
        HP_BAR(player, captureDamage: &dmgBefore);

        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(opponent, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Foe Wattrel with power!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, opponent);
        HP_BAR(player, captureDamage: &dmgAfter);

        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_AIR_CUTTER) {
            ABILITY_POPUP(opponent, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Air Cutter charged Foe Wattrel with power!");
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

DOUBLE_BATTLE_TEST("Wind Power activates correctly for every battler with the ability when hit by a 2/3 target move")
{
    u16 abilityLeft, abilityRight;

    PARAMETRIZE {abilityLeft = ABILITY_NONE, abilityRight = ABILITY_WIND_POWER;}
    PARAMETRIZE {abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_NONE; }
    PARAMETRIZE {abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_WIND_POWER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_AIR_CUTTER); MOVE(opponentRight, MOVE_AIR_CUTTER);}
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
    u16 abilityLeft, abilityRight;

    PARAMETRIZE {abilityLeft = ABILITY_NONE, abilityRight = ABILITY_WIND_POWER; }
    PARAMETRIZE {abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_NONE; }
    PARAMETRIZE {abilityLeft = ABILITY_WIND_POWER, abilityRight = ABILITY_WIND_POWER; }

    GIVEN {
        PLAYER(SPECIES_WATTREL) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PETAL_BLIZZARD);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_BLIZZARD, opponentLeft);

        HP_BAR(playerLeft);
        if (abilityLeft == ABILITY_WIND_POWER) {
            ABILITY_POPUP(playerLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by PetalBlizzrd charged Wattrel with power!");
        }
        HP_BAR(playerRight);
        if (abilityRight == ABILITY_WIND_POWER) {
            ABILITY_POPUP(playerRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by PetalBlizzrd charged Wattrel with power!");
        }
        HP_BAR(opponentRight);
        NOT HP_BAR(opponentLeft);
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

    PARAMETRIZE {opponentSide = TRUE;}
    PARAMETRIZE {opponentSide = FALSE;}

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TAILWIND].effect == EFFECT_TAILWIND);
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(10); }
        PLAYER(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(5); }
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(20); }
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_WIND_POWER); Speed(15); }
    } WHEN {
        TURN { MOVE((opponentSide == TRUE) ? opponentLeft : playerLeft, MOVE_TAILWIND);}
    } SCENE {
        if (opponentSide) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);

            ABILITY_POPUP(opponentLeft, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Foe Wattrel with power!");

            ABILITY_POPUP(opponentRight, ABILITY_WIND_POWER);
            MESSAGE("Being hit by Tailwind charged Foe Wattrel with power!");
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
