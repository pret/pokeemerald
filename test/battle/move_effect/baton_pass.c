#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
}

// This softlocked the game before.
SINGLE_BATTLE_TEST("Baton Pass used after Memento works correctly")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { MOVE(player, MOVE_MEMENTO); SEND_OUT(player, 1); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } SCENE {
        MESSAGE("Wobbuffet used Memento!");
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Foe Wynaut used Baton Pass!");
        MESSAGE("2 sent out Caterpie!");
        MESSAGE("Go! Wobbuffet!");
    }
}

TO_DO_BATTLE_TEST("Baton Pass switches out the user");
TO_DO_BATTLE_TEST("Baton Pass fails if there's no valid party Pokémon left");
TO_DO_BATTLE_TEST("Baton Pass passes both positive and negative stat changes");
TO_DO_BATTLE_TEST("AI doesn't choose Baton Pass if the Ace Pokémon is the last one available to switch in");
TO_DO_BATTLE_TEST("Baton Pass doesn't pass non-volatile status conditions"); // Status1
TO_DO_BATTLE_TEST("Baton Pass doesn't pass infatuation");
TO_DO_BATTLE_TEST("Baton Pass doesn't pass type changes");
TO_DO_BATTLE_TEST("Baton Pass doesn't pass ability changes");

//
// Move these to the corresponding effect files.
//
TO_DO_BATTLE_TEST("Baton Pass passes confusion status");                                                    // test/battle/status2/confusion.c

TO_DO_BATTLE_TEST("Baton Pass passes Cursed status");                                                       // test/battle/move_effect/curse.c
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Disable's effect");                                              // test/battle/move_effect/disable.c
TO_DO_BATTLE_TEST("Baton Pass passes Dragon Cheer's effect");                                               // test/battle/move_effect/dragon_cheer.c
TO_DO_BATTLE_TEST("Baton Pass passes Fairy lock's escape prevention effect");                               // test/battle/move_effect/fairy_lock.c
TO_DO_BATTLE_TEST("Baton Pass passes Focus Energy's effect");                                               // test/battle/move_effect/focus_energy.c
TO_DO_BATTLE_TEST("Baton Pass passes Heal Block's effect");                                                 // test/battle/move_effect/heal_block.c
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Imprison's effect");                                             // test/battle/move_effect/imprison.c
TO_DO_BATTLE_TEST("Baton Pass passes Ingrain's effect");                                                    // test/battle/move_effect/ingrain.c
TO_DO_BATTLE_TEST("Baton Pass passes Magnet Rise's effect");                                                // test/battle/move_effect/magnet_rise.c
TO_DO_BATTLE_TEST("Baton Pass passes escape prevention primary effect if it's used by the target");         // test/battle/move_effect/mean_look.c (Spider Web, Mean Look, Block)
TO_DO_BATTLE_TEST("Baton Pass doesn't pass escape prevention primary effects if it's used by the user");    // test/battle/move_effect/mean_look.c (Spider Web, Mean Look, Block)
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Mimic's learnt move");                                           // test/battle/move_effect/mimic.c
TO_DO_BATTLE_TEST("Baton Pass passes Minimize's evasion but not the weakness to stomping moves");           // test/battle/move_effect/minimize.c
TO_DO_BATTLE_TEST("Baton Pass passes No Retreat's escape prevention effect");                               // test/battle/move_effect/no_retreat.c
TO_DO_BATTLE_TEST("Baton Pass passes Octolock's escape prevention effect");                                 // test/battle/move_effect/octolock.c
TO_DO_BATTLE_TEST("Baton Pass passes Perish Song's effect");                                                // test/battle/move_effect/perish_song.c
TO_DO_BATTLE_TEST("Baton Pass passes Power Trick's effect");                                                // test/battle/move_effect/power_trick.c
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Rollout's multiplier");                                          // test/battle/move_effect/rollout.c
TO_DO_BATTLE_TEST("Baton Pass passes Sappy Seed's effect");                                                 // test/battle/move_effect/sappy_seed.c
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Transformations");                                               // test/battle/move_effect/transform.c
TO_DO_BATTLE_TEST("Baton Pass doesn't pass Yawn's effect");                                                 // test/battle/move_effect/yawn.c

TO_DO_BATTLE_TEST("Baton Pass passes Core Enforcer's effect");                                              // test/battle/move_effect_secondary/core_enforcer.c
TO_DO_BATTLE_TEST("Baton Pass passes escape prevention secondary effect");                                  // test/battle/move_effect_secondary/prevent_escape.c (Thousand Waves, Spirit Shackle, Anchor Shot)
TO_DO_BATTLE_TEST("Baton Pass doesn't pass escape prevention secondary effect if it's used by the user");   // test/battle/move_effect_secondary/prevent_escape.c (Thousand Waves, Spirit Shackle, Anchor Shot)

// Unconfirmed by Bulbapedia, should be tested in-game:
// - Nightmare
// - Encore
// - Spotlight
// - Taunt
// - Throat Chop
// - Torment
// - Splinters
// - Power Boost
// - Power Drop
// - Guard Boost
