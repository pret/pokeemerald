#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Analytic increases the power of moves by 30% if it's the last one that uses its move");
TO_DO_BATTLE_TEST("Analytic takes into account modifications to speeed an priority (Gen 5-8)");       //Eg. Paralysis, Power Weight, Stall
TO_DO_BATTLE_TEST("Analytic does not take into account modifications to speeed an priority (Gen 8)"); //Eg. Paralysis, Power Weight, Stall
TO_DO_BATTLE_TEST("Analytic takes into account the turn order of what fainted Pokémon would've moved");

// Triple Battles needed to test
//TO_DO_BATTLE_TEST("If the Pokémon with Analytic is targeting a Pokémon in a flank position that chooses to switch with its ally in the middle, its move's power will always be normal when it attacks the Pokémon that is shifted into the flank position");
//TO_DO_BATTLE_TEST("If the Pokémon with Analytic targets a Pokémon in the middle whose ally on a flank chooses to shift into the middle position, its move's power still depends on whether the Pokémon that was in the middle (and is now on a flank) has acted when the Pokémon with Analytic uses its move");
