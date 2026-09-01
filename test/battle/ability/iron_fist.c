#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Iron Fist increases the power of punching moves by 20%", s16 damage)
{
    enum Move move;
    enum Ability ability;
    PARAMETRIZE { move = MOVE_BULLET_PUNCH; ability = ABILITY_IRON_FIST; }
    PARAMETRIZE { move = MOVE_BULLET_PUNCH; ability = ABILITY_BLAZE; }
    PARAMETRIZE { move = MOVE_SCRATCH;      ability = ABILITY_IRON_FIST; }
    PARAMETRIZE { move = MOVE_SCRATCH;      ability = ABILITY_BLAZE; }

    GIVEN {
        ASSUME(IsPunchingMove(MOVE_BULLET_PUNCH));
        ASSUME(!IsPunchingMove(MOVE_SCRATCH));
        ASSUME(GetMovePower(MOVE_BULLET_PUNCH) == GetMovePower(MOVE_SCRATCH));
        PLAYER(SPECIES_CHIMCHAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.2), results[0].damage); // Iron Fist affects punching moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Iron Fist does not affect non-punching moves
    }
}
