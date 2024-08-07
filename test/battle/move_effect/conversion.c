#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Conversion changes the user's types to the target's current types (Gen 1)");
TO_DO_BATTLE_TEST("Conversion changes the user's types randomly to one of the user's move (Gen 2-5)");
TO_DO_BATTLE_TEST("Conversion ignores moves that share types with the user (Gen 2-5)");
TO_DO_BATTLE_TEST("Conversion fails if all the user's moves share types with the user (Gen 2-5)");
TO_DO_BATTLE_TEST("Conversion changes the user's types to the one in the user's first slot (Gen 6+)");
TO_DO_BATTLE_TEST("Conversion can read the user's first move slot even if that move cannot be selected (Gen 6+)"); //Eg. Disable
TO_DO_BATTLE_TEST("Conversion can change the user's types to Conversion's type");
