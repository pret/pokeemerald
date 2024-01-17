#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Harvest has a 50% chance to restore a Berry at the end of the turn");
TO_DO_BATTLE_TEST("Harvest always restores a Berry in Sunlight");
TO_DO_BATTLE_TEST("Harvest restores a Berry even after being switched out and back in");
TO_DO_BATTLE_TEST("Harvest restores a Berry consumed by Fling");
TO_DO_BATTLE_TEST("Harvest restores a Berry consumed by Natural Gift");
TO_DO_BATTLE_TEST("Harvest only works once per turn"); // Check for berries that are consumed immediately, like Pecha Berry
TO_DO_BATTLE_TEST("Harvest doesn't restore a Berry when destroyed by Incinerate");
TO_DO_BATTLE_TEST("Harvest doesn't restore a Berry when knocked off by Knock Off");
TO_DO_BATTLE_TEST("Harvest doesn't restore a Berry when eaten by Bug Bite/Pluck");
TO_DO_BATTLE_TEST("Harvest doesn't restore a Berry that's collected via Pickup");
TO_DO_BATTLE_TEST("Harvest order is affected by speed");
TO_DO_BATTLE_TEST("Harvest doesn't restore a Berry when transfered to another Pokémon");
TO_DO_BATTLE_TEST("Harvest can restore a Berry that was transferred from another Pokémon");
TO_DO_BATTLE_TEST("Harvest can only restore the newest berry consumed that was transferred from another Pokémon instead of its original Berry");
