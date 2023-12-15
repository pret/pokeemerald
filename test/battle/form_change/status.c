#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shaymin-Sky reverts to Shaymin-Land when frozen or frostbitten")
{
    ASSUME(gBattleMoves[MOVE_POWDER_SNOW].effect == ((B_USE_FROSTBITE == TRUE) ? EFFECT_FROSTBITE_HIT : EFFECT_FREEZE_HIT));
    GIVEN {
        PLAYER(SPECIES_SHAYMIN_SKY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER_SNOW); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_SHAYMIN_LAND);
    }
}
