#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sand Spit sets up sandstorm for 5 turns when hit")
{
    GIVEN {
        PLAYER(SPECIES_SANDACONDA) { Ability(ABILITY_SAND_SPIT); }
        OPPONENT(SPECIES_LANDORUS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_SAND_SPIT);
        MESSAGE("A sandstorm kicked up!");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm subsided.");
    }
}

SINGLE_BATTLE_TEST("Sand Spit sets up sandstorm for 8 turns when hit with Smooth Rock")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SMOOTH_ROCK].holdEffect == HOLD_EFFECT_SMOOTH_ROCK);
        PLAYER(SPECIES_SANDACONDA) { Ability(ABILITY_SAND_SPIT); Item(ITEM_SMOOTH_ROCK); }
        OPPONENT(SPECIES_LANDORUS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_SAND_SPIT);
        MESSAGE("A sandstorm kicked up!");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm subsided.");
    }
}

SINGLE_BATTLE_TEST("Sand Spit triggers even if the user is knocked out by the hit")
{
    GIVEN {
        PLAYER(SPECIES_SANDACONDA) { Ability(ABILITY_SAND_SPIT); HP(1); }
        PLAYER(SPECIES_LANDORUS);
        OPPONENT(SPECIES_LANDORUS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_SAND_SPIT);
        MESSAGE("A sandstorm kicked up!");
        MESSAGE("The sandstorm is raging.");
        MESSAGE("The sandstorm is raging.");
    }
}

SINGLE_BATTLE_TEST("Sand Spit fails if overworld weather is present (Gen9)")
{
    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        WITH_CONFIG(B_OVERWORLD_WEATHER_OVERRIDE, GEN_9);
        PLAYER(SPECIES_SANDACONDA) { Ability(ABILITY_SAND_SPIT); }
        OPPONENT(SPECIES_LANDORUS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_SAND_SPIT);
        NONE_OF {
            MESSAGE("A sandstorm kicked up!");
            MESSAGE("The sandstorm is raging.");
        }
    } THEN {
        ResetStartingStatuses();
    }
}
