#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_MICLE_BERRY].holdEffect == HOLD_EFFECT_MICLE_BERRY);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
}

SINGLE_BATTLE_TEST("Micle Berry raises the holder's accuracy by 1.2 when HP drops to 1/4 or below")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_MICLE_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_SCRATCH) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
                MESSAGE("Wobbuffet boosted the accuracy of its next move using Micle Berry!");
            }
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("Wobbuffet boosted the accuracy of its next move using Micle Berry!");
        }
    }
}

SINGLE_BATTLE_TEST("Micle Berry raises the holder's accuracy by 1.2 when HP drops to 1/2 or below")
{
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { MaxHP(80); HP(80); Ability(ABILITY_GLUTTONY); Item(ITEM_MICLE_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("Bellsprout boosted the accuracy of its next move using Micle Berry!");
    }
}

SINGLE_BATTLE_TEST("Micle Berry raises the holder's accuracy by 1.2")
{
    PASSES_RANDOMLY(24, 25, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SUBMISSION) == 80);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_MICLE_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); MOVE(player, MOVE_SUBMISSION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("Wobbuffet boosted the accuracy of its next move using Micle Berry!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBMISSION, player);
    }
}

SINGLE_BATTLE_TEST("Micle Berry increases the accuracy of the next used move across turns")
{
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_ROCK_SLIDE) == 90);
        PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(26); Item(ITEM_MICLE_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, player);
    }
}

SINGLE_BATTLE_TEST("Micle Berry increases the accuracy of the next used move the same turn the berry was triggered")
{
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_ROCK_SLIDE) == 90);
        PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(26); Item(ITEM_MICLE_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, player);
    }
}
