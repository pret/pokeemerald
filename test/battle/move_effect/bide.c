#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_BIDE) == EFFECT_BIDE);
}

SINGLE_BATTLE_TEST("Bide deals twice the taken damage over two turns")
{
    s16 damage1;
    s16 damage2;
    s16 bideDamage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BIDE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &damage1);
        NOT MESSAGE("Wobbuffet used Bide!");
        MESSAGE("Wobbuffet is storing energy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &damage2);
        NOT MESSAGE("Wobbuffet used Bide!");
        MESSAGE("Wobbuffet unleashed its energy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        HP_BAR(opponent, captureDamage: &bideDamage);
    } THEN {
        EXPECT_EQ(bideDamage, 2 * (damage1 + damage2));
    }
}

SINGLE_BATTLE_TEST("Bide fails if no damage has been dealt to the user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BIDE); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Wobbuffet is storing energy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Wobbuffet unleashed its energy!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
            HP_BAR(opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Bide hits the last Pokémon that attacked the user, even allies")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BIDE); MOVE(playerRight, MOVE_POUND, target: playerLeft); }
        TURN { SKIP_TURN(playerLeft); MOVE(playerRight, MOVE_POUND, target: playerLeft); }
        TURN { SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerLeft);
        HP_BAR(playerRight);
    }
}

SINGLE_BATTLE_TEST("Bide is blocked by Dazzling when it unleashes the attack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRUXISH) { Ability(ABILITY_DAZZLING); }
    } WHEN {
        TURN { MOVE(player, MOVE_BIDE); MOVE(opponent, MOVE_POUND); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_POUND); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet is storing energy!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet unleashed its energy!");
        ABILITY_POPUP(opponent, ABILITY_DAZZLING);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
            HP_BAR(opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Bide is blocked by partner Dazzling")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRUXISH) { Ability(ABILITY_DAZZLING); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BIDE); MOVE(opponentLeft, MOVE_POUND, target: playerLeft); }
        TURN { SKIP_TURN(playerLeft); MOVE(opponentLeft, MOVE_POUND, target: playerLeft); }
        TURN { SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        MESSAGE("Wobbuffet unleashed its energy!");
        ABILITY_POPUP(opponentRight, ABILITY_DAZZLING);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerLeft);
            HP_BAR(opponentLeft);
        }
    }
}

SINGLE_BATTLE_TEST("Bide fails if 0 total damage was dealt to the user by a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BIDE); MOVE(opponent, MOVE_FALSE_SWIPE); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_FALSE_SWIPE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet unleashed its energy!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Bide doesn't deal back damage taken by user's Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_BIDE); MOVE(opponent, MOVE_POUND); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_POUND); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        MESSAGE("Wobbuffet unleashed its energy!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Bide doesn't deal damage through protect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BIDE); MOVE(opponent, MOVE_POUND); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_POUND); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_PROTECT); }
        TURN {MOVE(opponent, MOVE_CELEBRATE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        MESSAGE("Wobbuffet unleashed its energy!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, player);
            HP_BAR(opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

TO_DO_BATTLE_TEST("Bide has +1 priority on following turns if called via a different move");

