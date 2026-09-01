#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_BRICK_BREAK, MOVE_EFFECT_BREAK_SCREEN));
    ASSUME(MoveHasAdditionalEffect(MOVE_PSYCHIC_FANGS, MOVE_EFFECT_BREAK_SCREEN));
    ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_SNOWSCAPE) == BATTLE_WEATHER_SNOW);
    ASSUME(GetMoveEffect(MOVE_LIGHT_SCREEN) == EFFECT_LIGHT_SCREEN);
    ASSUME(GetMoveEffect(MOVE_REFLECT) == EFFECT_REFLECT);
    ASSUME(GetMoveEffect(MOVE_AURORA_VEIL) == EFFECT_AURORA_VEIL);
}

SINGLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull remove Light Screen, Reflect and Aurora Veil from the target's side of the field")
{
    enum Move move;
    u32 breakingMove;

    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNOWSCAPE); }
        TURN { MOVE(opponent, move); MOVE(player, breakingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, breakingMove, player);
        switch (move)
        {
            case MOVE_REFLECT:
                MESSAGE("The opposing side's Reflect wore off!");
                break;
            case MOVE_LIGHT_SCREEN:
                MESSAGE("The opposing side's Light Screen wore off!");
                break;
            default:
                MESSAGE("The opposing side's Aurora Veil wore off!");
                break;
        }
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull don't remove Light Screen, Reflect and Aurora Veil if the target is immune")
{
    enum Move move;
    u32 breakingMove;

    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SABLEYE);
    } WHEN {
        TURN { MOVE(player, MOVE_SNOWSCAPE); }
        TURN { MOVE(opponent, move); MOVE(player, breakingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, breakingMove, player);
            switch (move)
            {
                case MOVE_REFLECT:
                    MESSAGE("The opposing side's Reflect wore off!");
                    break;
                case MOVE_LIGHT_SCREEN:
                    MESSAGE("The opposing side's Light Screen wore off!");
                    break;
                default:
                    MESSAGE("The opposing side's Aurora Veil wore off!");
                    break;
            }
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull don't remove Light Screen, Reflect and Aurora Veil if the target Protected")
{
    enum Move move;
    u32 breakingMove;

    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNOWSCAPE); MOVE(opponent, move); }
        TURN { MOVE(player, breakingMove); MOVE(opponent, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, breakingMove, player);
            switch (move)
            {
                case MOVE_REFLECT:
                    MESSAGE("The opposing side's Reflect wore off!");
                    break;
                case MOVE_LIGHT_SCREEN:
                    MESSAGE("The opposing side's Light Screen wore off!");
                    break;
                default:
                    MESSAGE("The opposing side's Aurora Veil wore off!");
                    break;
            }
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull don't remove Light Screen, Reflect and Aurora Veil if it misses")
{
    enum Move move;
    u32 breakingMove;

    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SNOWSCAPE); MOVE(opponent, move); }
        TURN { MOVE(player, breakingMove, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, breakingMove, player);
            switch (move)
            {
                case MOVE_REFLECT:
                    MESSAGE("The opposing side's Reflect wore off!");
                    break;
                case MOVE_LIGHT_SCREEN:
                    MESSAGE("The opposing side's Light Screen wore off!");
                    break;
                default:
                    MESSAGE("The opposing side's Aurora Veil wore off!");
                    break;
            }
            HP_BAR(opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull can remove Light Screen, Reflect and Aurora Veil on users side")
{
    enum Move move;
    u32 breakingMove;

    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_REFLECT;      breakingMove = MOVE_RAGING_BULL; }
    PARAMETRIZE { move = MOVE_AURORA_VEIL;  breakingMove = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SNOWSCAPE);
            MOVE(playerLeft, move);
            MOVE(playerRight, breakingMove, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, breakingMove, playerRight);
        switch (move)
        {
            case MOVE_REFLECT:
                MESSAGE("Your side's Reflect wore off!");
                break;
            case MOVE_LIGHT_SCREEN:
                MESSAGE("Your side's Light Screen wore off!");
                break;
            default:
                MESSAGE("Your side's Aurora Veil wore off!");
                break;
        }
        HP_BAR(playerLeft);
    }
}

SINGLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull can remove screens when the target is behind a Substitute")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REFLECT); }
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("Your side's Reflect wore off!");
        SUB_HIT(player);
    }
}

SINGLE_BATTLE_TEST("Brick Break, Psychic Fangs, and Raging Bull remove screens in the following order - Reflect, Light Screen, Aurora Veil")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_BRICK_BREAK; }
    PARAMETRIZE { move = MOVE_PSYCHIC_FANGS; }
    PARAMETRIZE { move = MOVE_RAGING_BULL; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NINETALES_ALOLA) Ability(ABILITY_SNOW_WARNING);
    } WHEN {
        TURN { MOVE(opponent, MOVE_REFLECT); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_LIGHT_SCREEN); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_AURORA_VEIL); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURORA_VEIL, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("The opposing side's Reflect wore off!");
        MESSAGE("The opposing side's Light Screen wore off!");
        MESSAGE("The opposing side's Aurora Veil wore off!");
    }
}
