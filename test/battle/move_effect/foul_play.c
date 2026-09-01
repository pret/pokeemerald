#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOUL_PLAY) == EFFECT_FOUL_PLAY);
}

SINGLE_BATTLE_TEST("Foul Play uses the target's Attack stat and stat stages of target", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HIGH_HORSEPOWER; }
    PARAMETRIZE { move = MOVE_FOUL_PLAY; }

    GIVEN {
        ASSUME(GetMovePower(MOVE_HIGH_HORSEPOWER) == GetMovePower(MOVE_FOUL_PLAY));
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_SHELLDER);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Foul Play uses the user's attack modifiers - Held Item")
TO_DO_BATTLE_TEST("Foul Play uses the user's attack modifiers - Ability")
TO_DO_BATTLE_TEST("Foul Play uses the user's attack modifiers - Burn")
