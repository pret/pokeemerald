#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_LANSAT_BERRY].holdEffect == HOLD_EFFECT_CRITICAL_UP);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
}

SINGLE_BATTLE_TEST("Lansat Berry raises the holder's critical-hit-ratio by two stages when HP drops to 1/4 or below")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_LANSAT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_SCRATCH) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
                MESSAGE("Wobbuffet used the Lansat Berry to get pumped!");
            }
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("Wobbuffet used the Lansat Berry to get pumped!");
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
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("Bellsprout used the Lansat Berry to get pumped!");
    }
}

SINGLE_BATTLE_TEST("Lansat Berry raises the holder's critical-hit-ratio by 2 stages")
{
    u32 genConfig = 0, chance;
    for (u32 j = GEN_1; j <= GEN_5; j++)
        PARAMETRIZE { genConfig = j; chance = 4; } // 25%
    for (u32 j = GEN_6; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; chance = 2; } // 50%
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetMoveCriticalHitStage(MOVE_SCRATCH) == 0);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_LANSAT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("Wobbuffet used the Lansat Berry to get pumped!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}
