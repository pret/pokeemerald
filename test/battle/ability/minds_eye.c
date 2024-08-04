#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mind's Eye allows to hit Ghost-type Pokémon with Normal- and Fighting-type moves")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MINDS_EYE); };
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
    }
}

// No current official way to test this, effect based on Smogon's NatDex format.
SINGLE_BATTLE_TEST("Mind's Eye doesn't bypass a Ghost-type's Wonder Guard")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SCRAPPY); };
        OPPONENT(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); };
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            HP_BAR(opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_WONDER_GUARD);
        MESSAGE("Foe Shedinja avoided damage with Wonder Guard!");
    }
}

//// AI TESTS ////

AI_SINGLE_BATTLE_TEST("AI doesn't use accuracy-lowering moves if it knows that the foe has Mind's Eye")
{
    u32 abilityAI = ABILITY_NONE, moveAI = MOVE_NONE, j = 0;

    for (j = MOVE_NONE + 1; j < MOVES_COUNT; j++)
    {
        if (gMovesInfo[j].effect == EFFECT_ACCURACY_DOWN || gMovesInfo[j].effect == EFFECT_ACCURACY_DOWN_2) {
            PARAMETRIZE { moveAI = j; abilityAI = ABILITY_SWIFT_SWIM; }
            PARAMETRIZE { moveAI = j; abilityAI = ABILITY_MOLD_BREAKER; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MINDS_EYE); }
        OPPONENT(SPECIES_BASCULEGION) { Moves(MOVE_CELEBRATE, moveAI); Ability(abilityAI); }
    } WHEN {
            TURN { MOVE(player, MOVE_TACKLE); }
            TURN { MOVE(player, MOVE_TACKLE);
                   if (abilityAI == ABILITY_MOLD_BREAKER) { SCORE_GT(opponent, moveAI, MOVE_CELEBRATE); }
                   else { SCORE_EQ(opponent, moveAI, MOVE_CELEBRATE); }
                }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        if (abilityAI == ABILITY_MOLD_BREAKER) { ANIMATION(ANIM_TYPE_MOVE, moveAI, opponent); }
    }
}
