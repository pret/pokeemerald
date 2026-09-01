#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Static inflicts paralysis on contact")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_STATIC); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(opponent, ABILITY_STATIC);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
            MESSAGE("Wobbuffet is paralyzed, so it may be unable to move!");
            STATUS_ICON(player, paralysis: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_STATIC);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
                MESSAGE("Wobbuffet is paralyzed, so it may be unable to move!");
                STATUS_ICON(player, paralysis: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Static triggers 1/3 times (Gen3) or 30% (Gen4+) of the time")
{
    u32 config, passes, trials;
    PARAMETRIZE { config = GEN_3; passes = 1; trials = 3; }  // 33.3%
    PARAMETRIZE { config = GEN_4; passes = 3; trials = 10; } // 30%
    PASSES_RANDOMLY(passes, trials, RNG_STATIC);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, config);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_STATIC); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_STATIC);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, player);
        MESSAGE("Wobbuffet is paralyzed, so it may be unable to move!");
        STATUS_ICON(player, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Static triggers even if attacker is under substitute")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_TACKLE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_STATIC); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_STATIC);
        STATUS_ICON(player, paralysis: TRUE);
    }
}
