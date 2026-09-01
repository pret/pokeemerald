#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_RETURN) == EFFECT_RETURN);
}

SINGLE_BATTLE_TEST("Return's power increases the higher friendship of the user is", s16 damage)
{
    u32 friendship;
    PARAMETRIZE { friendship = 0; }
    PARAMETRIZE { friendship = 100; }
    PARAMETRIZE { friendship = 200; }
    PARAMETRIZE { friendship = 255; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Friendship(friendship); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RETURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RETURN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_GT(results[i].damage, results[i-1].damage);
    }
}

TO_DO_BATTLE_TEST("Return does 0 damage at min Friendship (Gen2)")

SINGLE_BATTLE_TEST("Return does 1 damage at min Friendship (Gen3+)")
{
    s16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Friendship(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RETURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RETURN, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 1);
    }
}
