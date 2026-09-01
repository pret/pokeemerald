#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fire Mane increases Fire-type move damage", s16 damage[2])
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_FLAME_CHARGE; }
    PARAMETRIZE { move = MOVE_FLAMETHROWER; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_FLAME_CHARGE) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_FLAMETHROWER) == TYPE_FIRE);
        ASSUME(GetMoveCategory(MOVE_FLAME_CHARGE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_FLAMETHROWER) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_PYROAR) { Item(ITEM_PYROARITE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage[1]);
    } FINALLY {
        EXPECT_EQ(results[0].damage[0], results[0].damage[1]); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[1].damage[1], Q_4_12(1.5), results[1].damage[0]); // Flame Charge should be affected
        EXPECT_MUL_EQ(results[2].damage[1], Q_4_12(1.5), results[2].damage[0]); // Flamethrower should be affected
    }
}
