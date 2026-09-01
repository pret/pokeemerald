#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SONIC_BOOM) == EFFECT_FIXED_HP_DAMAGE);
}

SINGLE_BATTLE_TEST("Sonic Boom deals fixed damage", s16 damage)
{
    u16 mon;
    PARAMETRIZE { mon = SPECIES_RATTATA; }
    PARAMETRIZE { mon = SPECIES_ARON; }

    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_SONIC_BOOM) == 20);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(mon);
    } WHEN {
        TURN { MOVE(player, MOVE_SONIC_BOOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT(results[0].damage == 20);
        EXPECT(results[1].damage == 20);
    }
}

TO_DO_BATTLE_TEST("Sonic Boom affects ghost types (Gen1)")

SINGLE_BATTLE_TEST("Sonic Boom doesn't affect ghost types (Gen2+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_SONIC_BOOM); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, player);
        MESSAGE("It doesn't affect the opposing Gastly…");
    }
}
