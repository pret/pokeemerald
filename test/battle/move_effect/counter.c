#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Counter will do twice as much damage received from the opponent");
TO_DO_BATTLE_TEST("Counter cannot affect ally Pokémon");
TO_DO_BATTLE_TEST("Counter hits the last opponent that hit the user"); //Doubles

// Gen 1
TO_DO_BATTLE_TEST("Counter can only counter Normal and Fighting-type moves (Gen 1)");
TO_DO_BATTLE_TEST("Counter can hit ghost-type Pokémon (Gen 1)");
TO_DO_BATTLE_TEST("Counter can return damage dealt to a substitute (Gen 1)");

// Gen 2-3
TO_DO_BATTLE_TEST("Counter can counter Hidden Power regardless of type (Gen 2-3)");

// Gen 2+
TO_DO_BATTLE_TEST("Counter can only counter physical moves (Gen 2+)");
TO_DO_BATTLE_TEST("Counter cannot hit ghost-type Pokémon (Gen 2+)");
TO_DO_BATTLE_TEST("Counter cannot return damage dealt to a substitute (Gen 2+)");

// Triple Battles required to test
//TO_DO_BATTLE_TEST("Counter can hit non-adjacent opponents if they were the last Pokémon to hit the user");
