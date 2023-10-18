#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clear Body prevents intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TACKLE); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
        ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
        MESSAGE("Foe Beldum's Clear Body prevents stat loss!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

TO_DO_BATTLE_TEST("Clear Body prevents stat stage reduction from moves"); // Growl, Leer, Confide, Fake Tears, Scary Face, Sweet Scent, Sand Attack (Attack, Defense, Sp. Attack, Sp. Defense, Speed, Evasion, Accuracy
TO_DO_BATTLE_TEST("Clear Body prevents Sticky Web");
TO_DO_BATTLE_TEST("Clear Body doesn't prevent stat stage reduction from moves used by the user"); // e.g. Superpower
TO_DO_BATTLE_TEST("Clear Body doesn't prevent Speed reduction from Iron Ball");
TO_DO_BATTLE_TEST("Clear Body doesn't prevent Speed reduction from paralysis");
TO_DO_BATTLE_TEST("Clear Body doesn't prevent Attack reduction from burn");
TO_DO_BATTLE_TEST("Clear Body doesn't prevent receiving negative stat changes from Baton Pass");
TO_DO_BATTLE_TEST("Clear Body doesn't prevent Topsy-Turvy");
TO_DO_BATTLE_TEST("Clear Body doesn't prevent Spectral Thief from resetting positive stat changes");
TO_DO_BATTLE_TEST("Clear Body is ignored by Mold Breaker");
