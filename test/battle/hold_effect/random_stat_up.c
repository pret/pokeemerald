#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_STARF_BERRY].holdEffect == HOLD_EFFECT_RANDOM_STAT_UP);
}

TO_DO_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages when the holder's HP drop to 1/4 or below")
TO_DO_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by two stages when the holder's HP drop to 1/2 or below if it has Gluttony")
TO_DO_BATTLE_TEST("Starf Berry randomly raises the holder's Attack, Defense, Sp. Atk, Sp. Def, or Speed by four stages when the holder's HP drop to 1/4 or below if it has Riped")
