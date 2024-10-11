#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shaymin-Sky reverts to Shaymin-Land when frozen or frostbitten")
{
    u32 move;

    PARAMETRIZE { move = MOVE_POWDER_SNOW; }
    PARAMETRIZE { move = MOVE_EMBER; }
    PARAMETRIZE { move = MOVE_THUNDERSHOCK; }
    PARAMETRIZE { move = MOVE_POISON_STING; }
    PARAMETRIZE { move = MOVE_POISON_FANG; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POWDER_SNOW, MOVE_EFFECT_FREEZE_OR_FROSTBITE));
        ASSUME(MoveHasAdditionalEffect(MOVE_EMBER, MOVE_EFFECT_BURN));
        ASSUME(MoveHasAdditionalEffect(MOVE_THUNDERSHOCK, MOVE_EFFECT_PARALYSIS));
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON));
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_FANG, MOVE_EFFECT_TOXIC));
        PLAYER(SPECIES_SHAYMIN_SKY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_POWDER_SNOW) {
            FREEZE_OR_FROSTBURN_STATUS(player, TRUE);
            NOT HP_BAR(player); // Regression caused by Mimikyu form change
            MESSAGE("Shaymin transformed!");
        } else {
            NOT MESSAGE("Shaymin transformed!");
        }
    } THEN {
        if (move == MOVE_POWDER_SNOW)
            EXPECT_EQ(player->species, SPECIES_SHAYMIN_LAND);
        else
            EXPECT_EQ(player->species, SPECIES_SHAYMIN_SKY);

    }
}
