#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hyper Cutter prevents intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TACKLE); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
        ABILITY_POPUP(opponent, ABILITY_HYPER_CUTTER);
        MESSAGE("Foe Krabby's Attack was not lowered!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

TO_DO_BATTLE_TEST("Hyper Cutter prevents Attack stage reduction from moves"); // Growl
TO_DO_BATTLE_TEST("Hyper Cutter doesn't prevent Attack stage reduction from moves used by the user"); // e.g. Superpower
TO_DO_BATTLE_TEST("Hyper Cutter doesn't prevent Attack reduction from burn");
TO_DO_BATTLE_TEST("Hyper Cutter doesn't prevent receiving negative Attack stage changes from Baton Pass");
TO_DO_BATTLE_TEST("Hyper Cutter doesn't prevent Topsy-Turvy");
TO_DO_BATTLE_TEST("Hyper Cutter doesn't prevent Spectral Thief from resetting positive Attack stage changes");
TO_DO_BATTLE_TEST("Hyper Cutter is ignored by Mold Breaker");
