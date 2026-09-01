#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_POWDER) == EFFECT_POWDER);
    ASSUME(IsPowderMove(MOVE_POWDER));
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
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
        EXPECT_EQ(player->pp[0], GetMovePP(MOVE_EMBER) - 1);
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

SINGLE_BATTLE_TEST("Powder damages the target under heavy rain (Gen 6)")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_STATUS_HEAVY_RAIN, GEN_6);
        PLAYER(SPECIES_KYOGRE_PRIMAL) { Ability(ABILITY_PRIMORDIAL_SEA); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(player);
    } THEN {
        EXPECT_LT(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Powder doesn't damage target under heavy rain (Gen 7+)")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_STATUS_HEAVY_RAIN, GEN_7);
        PLAYER(SPECIES_KYOGRE_PRIMAL) { Ability(ABILITY_PRIMORDIAL_SEA); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(player);
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

SINGLE_BATTLE_TEST("Powder fails if the target is Grass type (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, GEN_6);
        ASSUME(GetSpeciesType(SPECIES_VENUSAUR, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_VENUSAUR, 1) == TYPE_GRASS);
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

SINGLE_BATTLE_TEST("Powder fails if the target has Overcoat (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_OVERCOAT, GEN_6);
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
        ASSUME(GetMoveEffect(MOVE_FORESTS_CURSE) == EFFECT_THIRD_TYPE);
        ASSUME(GetMoveArgType(MOVE_FORESTS_CURSE) == TYPE_GRASS);
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
        ASSUME(GetMoveEffect(MOVE_DOODLE) == EFFECT_DOODLE);
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

SINGLE_BATTLE_TEST("Powder prevents Protean/Libero from changing its user to Fire type")
{
    enum Ability ability;
    enum Species species;
    PARAMETRIZE { ability = ABILITY_PROTEAN; species = SPECIES_GRENINJA; }
    PARAMETRIZE { ability = ABILITY_LIBERO;  species = SPECIES_RABOOT; }
    GIVEN {
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ability);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Powder doesn't prevent a Fire move from thawing its user out")
{
    GIVEN {
        ASSUME(MoveThawsUser(MOVE_FLAME_WHEEL));
        ASSUME(GetMoveType(MOVE_FLAME_WHEEL) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_FLAME_WHEEL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        MESSAGE("Wobbuffet's Flame Wheel melted the ice!");
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
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
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
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_EMBER; }
    PARAMETRIZE { move = MOVE_TICKLE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SHELL_TRAP) == EFFECT_SHELL_TRAP);
        ASSUME(GetMoveType(MOVE_SHELL_TRAP) == TYPE_FIRE);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_EMBER) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_TICKLE) == DAMAGE_CATEGORY_STATUS);
        ASSUME_STAT_CHANGE(MOVE_TICKLE, attack: -1, defense: -1);
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
