#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Point inflicts poison on contact")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDORAN_M) { Ability(ABILITY_POISON_POINT); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN {}
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            MESSAGE("Wobbuffet was poisoned!");
            STATUS_ICON(player, poison: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
                MESSAGE("Wobbuffet was poisoned!");
                STATUS_ICON(player, poison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Poison Point triggers 1/3 times (Gen3) or 30% (Gen 4+) of the time")
{
    u32 config, passes, trials;
    PARAMETRIZE { config = GEN_3; passes = 1; trials = 3; }  // 33.3%
    PARAMETRIZE { config = GEN_4; passes = 3; trials = 10; } // 30%
    PASSES_RANDOMLY(passes, trials, RNG_POISON_POINT);
    GIVEN {
        WITH_CONFIG(B_ABILITY_TRIGGER_CHANCE, config);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDORAN_M) { Ability(ABILITY_POISON_POINT); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        MESSAGE("Wobbuffet was poisoned!");
        STATUS_ICON(player, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Poison Point will not poison Poison-Type targets with corrosion")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_TACKLE));
        PLAYER(SPECIES_SALANDIT) { Ability(ABILITY_CORROSION); }
        OPPONENT(SPECIES_NIDORAN_M) { Ability(ABILITY_POISON_POINT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN {}
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_POISON_POINT);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
            MESSAGE("Salandit was poisoned!");
            STATUS_ICON(player, poison: TRUE);
        }
    }
}
