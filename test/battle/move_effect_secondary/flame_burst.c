#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAdditionalEffectById(MOVE_FLAME_BURST, 0)->moveEffect == MOVE_EFFECT_FLAME_BURST);
}

//  Flame Burst AoE is supposed to hit through Substitute
DOUBLE_BATTLE_TEST("Flame Burst Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SUBSTITUTE); MOVE(playerRight, MOVE_FLAME_BURST, target: opponentRight); }
    } SCENE {
        MESSAGE("The bursting flames hit the opposing Wynaut!");
        NOT MESSAGE("The substitute took damage for the opposing Wynaut!");
    }
}

DOUBLE_BATTLE_TEST("Flame Burst doesn't crash, opponent to player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FLAME_BURST, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_BURST, opponentRight);
        HP_BAR(playerRight);
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Flame Burst doesn't crash, player to opponent")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLAME_BURST, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_BURST, playerLeft);
        HP_BAR(opponentRight);
        MESSAGE("The opposing Wynaut fainted!");
    }
}
