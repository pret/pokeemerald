#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Conversion 2 randomly changes the type of the user to a type that resists the last move that hit the user (Gen 3-4)");
TO_DO_BATTLE_TEST("Conversion 2 randomly changes the type of the user to a type that resists the last move used by the target (Gen 5+)");
TO_DO_BATTLE_TEST("Conversion 2's type change considers the type of moves called by other moves");
TO_DO_BATTLE_TEST("Conversion 2's type change considers dynamic type moves"); // Eg. Weather Ball
TO_DO_BATTLE_TEST("Conversion 2's type change considers move types changed by Normalize and Electrify");
TO_DO_BATTLE_TEST("Conversion 2's type change considers move types changed by Normalize");
TO_DO_BATTLE_TEST("Conversion 2's type change considers Struggle to be Normal type (Gen 3-4)");
TO_DO_BATTLE_TEST("Conversion 2 fails if the move used is of typeless damage (Gen 5+)");
TO_DO_BATTLE_TEST("Conversion 2's type change considers status moves (Gen 5+)");
TO_DO_BATTLE_TEST("Conversion 2's type change considers Inverse Battles");
TO_DO_BATTLE_TEST("Conversion 2 fails if the move used is Stellar Type");
