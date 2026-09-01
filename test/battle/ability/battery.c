#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Battery increases Sp. Attack damage of allies by ~30%")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_CHARJABUG) { Speed(1); Ability(ABILITY_BATTERY); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_SHOCK_WAVE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_CELEBRATE, MOVE_GASTRO_ACID); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SHOCK_WAVE, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_GASTRO_ACID, target: playerLeft); MOVE(playerRight, MOVE_SHOCK_WAVE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], UQ_4_12(1.3), damage[0]);
    }

}

DOUBLE_BATTLE_TEST("Battery does not increase its own Sp. Attack damage")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_CHARJABUG) { Speed(1); Ability(ABILITY_BATTERY); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_CELEBRATE, MOVE_GASTRO_ACID); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHOCK_WAVE, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_GASTRO_ACID, target: playerLeft); MOVE(playerLeft, MOVE_SHOCK_WAVE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHOCK_WAVE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}
