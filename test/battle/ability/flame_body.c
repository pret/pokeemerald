#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flame Body inflicts burn on contact")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_FLAME_BODY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
            MESSAGE("Wobbuffet was burned!");
            STATUS_ICON(player, burn: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
                MESSAGE("Wobbuffet was burned!");
                STATUS_ICON(player, burn: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Flame Body triggers 1/3 times (Gen3) or 30% (Gen 4+) of the time")
{
    u32 config, passes, trials;
    PARAMETRIZE { config = GEN_3; passes = 1; trials = 3; }  // 33.3%
    PARAMETRIZE { config = GEN_4; passes = 3; trials = 10; } // 30%
    PASSES_RANDOMLY(passes, trials, RNG_FLAME_BODY);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, config);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_FLAME_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_FLAME_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        MESSAGE("Wobbuffet was burned!");
        STATUS_ICON(player, burn: TRUE);
    }
}
