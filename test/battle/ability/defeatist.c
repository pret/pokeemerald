#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_ECHOED_VOICE].category == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Defeatist halves Attack when HP <= 50%", s16 damage)
{
    u32 hp;
    PARAMETRIZE { hp = 400; }
    PARAMETRIZE { hp = 200; }
    GIVEN {
        PLAYER(SPECIES_ARCHEN) { Ability(ABILITY_DEFEATIST); HP(hp), MaxHP(400);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Defeatist halves Special Attack when HP <= 50%", s16 damage)
{
    u32 hp;
    PARAMETRIZE { hp = 400; }
    PARAMETRIZE { hp = 200; }
    GIVEN {
        PLAYER(SPECIES_ARCHEN) { Ability(ABILITY_DEFEATIST); HP(hp), MaxHP(400);}
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}
