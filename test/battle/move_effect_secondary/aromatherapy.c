#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffectSelf(MOVE_SPARKLY_SWIRL, MOVE_EFFECT_AROMATHERAPY));
}

DOUBLE_BATTLE_TEST("Sparkly Swirl cures the entire party of the user from primary status effects")
{
    u32 j;
    u32 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {
            if (status != STATUS1_SLEEP && status != STATUS1_FREEZE)
                Status1(status);
        }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPARKLY_SWIRL, target: opponentLeft, WITH_RNG(RNG_PARALYSIS, FALSE)); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); }
    } SCENE {
        MESSAGE("Wobbuffet used Sparkly Swirl!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLY_SWIRL, playerLeft);
        switch(status)
        {
        case STATUS1_SLEEP:
            STATUS_ICON(playerLeft, sleep: FALSE);
            STATUS_ICON(playerRight, sleep: FALSE);
            break;
        case STATUS1_POISON:
            STATUS_ICON(playerLeft, poison: FALSE);
            STATUS_ICON(playerRight, poison: FALSE);
            break;
        case STATUS1_BURN:
            STATUS_ICON(playerLeft, burn: FALSE);
            STATUS_ICON(playerRight, burn: FALSE);
            break;
        case STATUS1_PARALYSIS:
            STATUS_ICON(playerLeft, paralysis: FALSE);
            STATUS_ICON(playerRight, paralysis: FALSE);
            break;
        case STATUS1_TOXIC_POISON:
            STATUS_ICON(playerLeft, badPoison: FALSE);
            STATUS_ICON(playerRight, badPoison: FALSE);
            break;
        case STATUS1_FROSTBITE:
            STATUS_ICON(playerLeft, frostbite: FALSE);
            STATUS_ICON(playerRight, frostbite: FALSE);
            break;
        }
    } THEN {
        for (j = 0; j < PARTY_SIZE; j++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_STATUS), STATUS1_NONE);
    }
}
