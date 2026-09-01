#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Lightning Rod absorbs Electric-type moves and increases the Sp. Attack")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, config);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (config >= GEN_5) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
                HP_BAR(opponent);
            };
            ABILITY_POPUP(opponent, ABILITY_LIGHTNING_ROD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Raichu's Sp. Atk rose!");
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_LIGHTNING_ROD);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                MESSAGE("The opposing Raichu's Sp. Atk rose!");
            };
            ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
            HP_BAR(opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        if (config >= GEN_5) {
            EXPECT_EQ(gBattleHistory->abilities[1], ABILITY_LIGHTNING_ROD); // Check if the correct ability has been recorded
        } else {
            EXPECT_EQ(gBattleHistory->abilities[1], ABILITY_NONE);
        }
    }
}

DOUBLE_BATTLE_TEST("Lightning Rod forces single-target Electric-type moves to target the Pokémon with this Ability.")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, config);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_THUNDERBOLT, target: opponentRight);
            MOVE(playerRight, MOVE_THUNDERBOLT, target: opponentRight);
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        if (config >= GEN_5) {
            NONE_OF {
                HP_BAR(opponentLeft);
                HP_BAR(opponentRight);
            };
            ABILITY_POPUP(opponentLeft, ABILITY_LIGHTNING_ROD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Raichu's Sp. Atk rose!");
            ABILITY_POPUP(opponentLeft, ABILITY_LIGHTNING_ROD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Raichu's Sp. Atk rose!");
        } else {
            NONE_OF {
                HP_BAR(opponentRight);
            };
            ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, playerLeft);
            HP_BAR(opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, playerRight);
            HP_BAR(opponentLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Lightning Rod redirects an ally's attack")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_THUNDERBOLT, target: playerLeft); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Thunderbolt!");
        if (B_REDIRECT_ABILITY_ALLIES >= GEN_4)
        {
            NOT HP_BAR(playerLeft);
            ABILITY_POPUP(opponentLeft, ABILITY_LIGHTNING_ROD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Raichu's Sp. Atk rose!");
        }
        else
        {
            HP_BAR(playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Lightning Rod absorbs moves that targets all battlers but does not redirect (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        NOT HP_BAR(opponentRight);
        ABILITY_POPUP(opponentRight, ABILITY_LIGHTNING_ROD);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Lightning Rod doesn't activate if user has fainted")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SPARK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU) { HP(1); Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POUND, target: opponentRight); MOVE(playerRight, MOVE_SPARK, target: opponentLeft); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Raichu's Lightning Rod took the attack");
            ABILITY_POPUP(opponentRight, ABILITY_LIGHTNING_ROD);
        }
    }
}
