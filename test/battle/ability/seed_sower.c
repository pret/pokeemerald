#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Seed Sower sets up Grassy Terrain when hit by an attack")
{
    GIVEN {
        PLAYER(SPECIES_ARBOLIVA) { Ability(ABILITY_SEED_SOWER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Tackle!");
        HP_BAR(player);
        ABILITY_POPUP(player);
        MESSAGE("Grass grew to cover the battlefield!");
    }
}

#define ABILITY_PARAM(n)(abilities[n] = (k == n) ? ABILITY_SEED_SOWER : ABILITY_HARVEST)
#define MOVE_HIT(target, position)                      \
{                                                       \
    HP_BAR(target);                                     \
    if (abilities[position] == ABILITY_SEED_SOWER) {    \
        ABILITY_POPUP(target);                          \
        MESSAGE("Grass grew to cover the battlefield!");\
    }                                                   \
}

DOUBLE_BATTLE_TEST("Multi-target moves hit correct battlers after Seed Sower is triggered") // #2796
{
    u32 j, k, l;
    u16 usedMove = MOVE_NONE;
    static const u16 moves[] = {MOVE_HYPER_VOICE, MOVE_SURF};
    u16 abilities[MAX_BATTLERS_COUNT] = {0};
    u8 attacker = 0;

    for (j = 0; j < ARRAY_COUNT(moves); j++)
    {
        for (k = 0; k < MAX_BATTLERS_COUNT; k++)
        {
            for (l = 0; l < MAX_BATTLERS_COUNT; l++)
            {
                if (k == l)
                    continue; // No tests needed when attacker has Seed Sower
                if ((k & BIT_SIDE) == (l & BIT_SIDE) && moves[j] == MOVE_HYPER_VOICE)
                    continue; // No tests needed when partners has Seed Sower and Hyper Voice is used.
                PARAMETRIZE { attacker = l; usedMove = moves[j]; ABILITY_PARAM(0); ABILITY_PARAM(1); ABILITY_PARAM(2); ABILITY_PARAM(3); }
            }
        }
    }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].target == MOVE_TARGET_BOTH);
        ASSUME(gMovesInfo[MOVE_SURF].target == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_ARBOLIVA) { Ability(abilities[B_POSITION_PLAYER_LEFT]); }
        PLAYER(SPECIES_ARBOLIVA) { Ability(abilities[B_POSITION_PLAYER_RIGHT]); }
        OPPONENT(SPECIES_ARBOLIVA) { Ability(abilities[B_POSITION_OPPONENT_LEFT]); }
        OPPONENT(SPECIES_ARBOLIVA) { Ability(abilities[B_POSITION_OPPONENT_RIGHT]); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, (attacker == B_POSITION_OPPONENT_LEFT) ? usedMove : MOVE_CELEBRATE);
            MOVE(opponentRight, (attacker == B_POSITION_OPPONENT_RIGHT) ? usedMove : MOVE_CELEBRATE);
            MOVE(playerLeft, (attacker == B_POSITION_PLAYER_LEFT) ? usedMove : MOVE_CELEBRATE);
            MOVE(playerRight, (attacker == B_POSITION_PLAYER_RIGHT) ? usedMove : MOVE_CELEBRATE);
        }
    } SCENE {
        // ANIMATION(ANIM_TYPE_MOVE, usedMove);
        if (usedMove == MOVE_HYPER_VOICE) {
            if ((attacker & BIT_SIDE) == B_SIDE_OPPONENT) {
                if (attacker == B_POSITION_OPPONENT_LEFT) {
                    MOVE_HIT(playerLeft, B_POSITION_PLAYER_LEFT);
                    MOVE_HIT(playerRight, B_POSITION_PLAYER_RIGHT);
                } else {
                    MOVE_HIT(playerRight, B_POSITION_PLAYER_RIGHT);
                    MOVE_HIT(playerLeft, B_POSITION_PLAYER_LEFT);
                }
                NONE_OF {
                    HP_BAR(opponentLeft);
                    HP_BAR(opponentRight);
                }
            } else {
                if (attacker == B_POSITION_PLAYER_LEFT) {
                    MOVE_HIT(opponentLeft, B_POSITION_OPPONENT_LEFT);
                    MOVE_HIT(opponentRight, B_POSITION_OPPONENT_RIGHT);
                } else {
                    MOVE_HIT(opponentRight, B_POSITION_OPPONENT_RIGHT);
                    MOVE_HIT(opponentLeft, B_POSITION_OPPONENT_LEFT);
                }
                NONE_OF {
                    HP_BAR(playerLeft);
                    HP_BAR(playerRight);
                }
            }
        } else { // SURF
            switch (attacker) {
            case B_POSITION_PLAYER_LEFT:
                MOVE_HIT(opponentLeft, B_POSITION_OPPONENT_LEFT);
                MOVE_HIT(playerRight, B_POSITION_PLAYER_RIGHT);
                MOVE_HIT(opponentRight, B_POSITION_OPPONENT_RIGHT);
                NOT HP_BAR(playerLeft);
                break;
            case B_POSITION_OPPONENT_LEFT:
                MOVE_HIT(playerLeft, B_POSITION_PLAYER_LEFT);
                MOVE_HIT(playerRight, B_POSITION_PLAYER_RIGHT);
                MOVE_HIT(opponentRight, B_POSITION_OPPONENT_RIGHT);
                NOT HP_BAR(opponentLeft);
                break;
            case B_POSITION_PLAYER_RIGHT:
                MOVE_HIT(playerLeft, B_POSITION_PLAYER_LEFT);
                MOVE_HIT(opponentLeft, B_POSITION_OPPONENT_LEFT);
                MOVE_HIT(opponentRight, B_POSITION_OPPONENT_RIGHT);
                NOT HP_BAR(playerRight);
                break;
            case B_POSITION_OPPONENT_RIGHT:
                MOVE_HIT(playerLeft, B_POSITION_PLAYER_LEFT);
                MOVE_HIT(opponentLeft, B_POSITION_OPPONENT_LEFT);
                MOVE_HIT(playerRight, B_POSITION_PLAYER_RIGHT);
                NOT HP_BAR(opponentRight);
                break;
            }
        }
    }
}

#undef ABILITY_PARAM
#undef MOVE_HIT
