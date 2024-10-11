#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_POWDER].effect == EFFECT_POWDER);
    ASSUME(gMovesInfo[MOVE_POWDER].powderMove == TRUE);
    ASSUME(gMovesInfo[MOVE_EMBER].type == TYPE_FIRE);
}


SINGLE_BATTLE_TEST("Powder blocks the target's Fire type moves and deals 25% of maximum HP to target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_MUL_EQ(player->maxHP, UQ_4_12(0.75), player->hp);
    }
}

SINGLE_BATTLE_TEST("Powder blocks the target's Fire type moves and consumes PP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(player->pp[0], gMovesInfo[MOVE_EMBER].pp - 1);
    }
}

SINGLE_BATTLE_TEST("Powder only blocks the target's Fire type moves on the same turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->maxHP, player->hp);
    }
}

SINGLE_BATTLE_TEST("Powder doesn't damage target if it has Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_ALAKAZAM) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(player->maxHP, player->hp);
    }
}

SINGLE_BATTLE_TEST("Powder doesn't damage target under heavy rain")
{
    GIVEN {
        ASSUME(B_POWDER_RAIN >= GEN_7);
        PLAYER(SPECIES_KYOGRE_PRIMAL) { Ability(ABILITY_PRIMORDIAL_SEA); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(player->maxHP, player->hp);
    }
}

DOUBLE_BATTLE_TEST("Powder blocks the target's Fire type moves even if it doesn't target Powder user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(playerLeft, MOVE_EMBER, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerLeft);
            HP_BAR(opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Powder fails if target is already affected by Powder")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(opponentLeft, MOVE_POWDER, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Powder fails if the target is Grass type")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_VENUSAUR].types[0] == TYPE_GRASS || gSpeciesInfo[SPECIES_VENUSAUR].types[1] == TYPE_GRASS);
        PLAYER(SPECIES_VENUSAUR);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Powder fails if the target has Overcoat")
{
    GIVEN {
        PLAYER(SPECIES_FORRETRESS) { Ability(ABILITY_OVERCOAT); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Powder still blocks the target's Fire type moves even if it was given Grass type")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FORESTS_CURSE].effect == EFFECT_THIRD_TYPE);
        ASSUME(gMovesInfo[MOVE_FORESTS_CURSE].argument == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TREVENANT);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(opponentLeft, MOVE_FORESTS_CURSE, target: playerLeft); MOVE(playerLeft, MOVE_EMBER, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FORESTS_CURSE, opponentLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerLeft);
            HP_BAR(opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Powder still blocks the target's Fire type moves even if it was given Overcoat")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_DOODLE].effect == EFFECT_DOODLE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FORRETRESS) { Ability(ABILITY_OVERCOAT); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(playerRight, MOVE_DOODLE, target: opponentLeft); MOVE(playerLeft, MOVE_EMBER, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerLeft);
            HP_BAR(opponentLeft);
        }
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_OVERCOAT);
    }
}

SINGLE_BATTLE_TEST("Powder prevents Protean from changing its user to Fire type")
{
    GIVEN {
        PLAYER(SPECIES_GRENINJA) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_PROTEAN);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Powder doesn't prevent a Fire move from thawing its user out")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FLAME_WHEEL].thawsUser);
        ASSUME(gMovesInfo[MOVE_FLAME_WHEEL].type == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_FLAME_WHEEL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        MESSAGE("Wobbuffet was defrosted by Flame Wheel!");
        STATUS_ICON(player, none: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_WHEEL, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Powder doesn't consume Berry from Fire type Natural Gift but prevents using the move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_NATURAL_GIFT].effect == EFFECT_NATURAL_GIFT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHERI_BERRY); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(player->item, ITEM_CHERI_BERRY);
    }
}

DOUBLE_BATTLE_TEST("Powder damages a target using Shell Trap even if it wasn't hit by a Physical move")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_EMBER; }
    PARAMETRIZE { move = MOVE_TICKLE;}
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SHELL_TRAP].effect == EFFECT_SHELL_TRAP);
        ASSUME(gMovesInfo[MOVE_SHELL_TRAP].type == TYPE_FIRE);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_EMBER].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_TICKLE].category == DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_TICKLE].effect == EFFECT_TICKLE);
        PLAYER(SPECIES_TURTONATOR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHELL_TRAP); MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(opponentLeft, move, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SHELL_TRAP_SETUP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        if (move != MOVE_TICKLE)
            HP_BAR(playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_TRAP, playerLeft);
            HP_BAR(opponentLeft);
            HP_BAR(opponentRight);
        }
        HP_BAR(playerLeft);
    }
}
