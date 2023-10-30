#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_LANSAT_BERRY].holdEffect == HOLD_EFFECT_CRITICAL_UP);
    ASSUME(gBattleMoves[MOVE_DRAGON_RAGE].effect == EFFECT_DRAGON_RAGE);
}

SINGLE_BATTLE_TEST("Lansat Berry raises the holder's critical-hit-ratio by two stages when HP drops to 1/4 or below")
{
    u32 move;

    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_LANSAT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_TACKLE) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Wobbuffet used Lansat Berry to get pumped!");
            }
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet used Lansat Berry to get pumped!");
        }
    }
}

SINGLE_BATTLE_TEST("Lansat Berry raises the holder's critical-hit-ratio by two stages when HP drops to 1/2 or below")
{
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { MaxHP(80); HP(80); Ability(ABILITY_GLUTTONY); Item(ITEM_LANSAT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Bellsprout used Lansat Berry to get pumped!");
    }
}

SINGLE_BATTLE_TEST("Lansat Berry raises the holder's critical-hit-ratio by two stages")
{
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].highCritRatio == FALSE);
        ASSUME(B_CRIT_CHANCE >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_LANSAT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet used Lansat Berry to get pumped!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        MESSAGE("A critical hit!");
    }
}
