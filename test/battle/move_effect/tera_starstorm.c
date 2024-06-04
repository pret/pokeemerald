#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TERA_STARSTORM].effect == EFFECT_TERA_STARSTORM);
}

SINGLE_BATTLE_TEST("Tera Starstorm changes from Normal-type to Stellar-type if used by Terapagos-Stellar")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TERA_STARSTORM].type == TYPE_NORMAL);
        PLAYER(SPECIES_TERAPAGOS_STELLAR);
        OPPONENT(SPECIES_MISDREAVUS);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_STARSTORM); }
    } SCENE {
        MESSAGE("Terapagos used Tera Starstorm!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_STARSTORM, player);
        HP_BAR(opponent);
        NOT { MESSAGE("It doesn't affect Foe Misdreavus…"); }
    }
}

DOUBLE_BATTLE_TEST("Tera Starstorm targets both opponents in a double battle if used by Terapagos-Stellar")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TERA_STARSTORM].target == MOVE_TARGET_SELECTED);
        PLAYER(SPECIES_TERAPAGOS_STELLAR);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TERA_STARSTORM, target:opponentLeft); }
    } SCENE {
        MESSAGE("Terapagos used Tera Starstorm!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_STARSTORM, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

SINGLE_BATTLE_TEST("Tera Starstorm becomes a physical move if the user is Terapagos-Stellar, is Terastallized, and has a higher Attack stat", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = FALSE; }
    PARAMETRIZE { tera = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TERA_STARSTORM].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_TERAPAGOS_STELLAR) { Attack(100); SpAttack(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_STARSTORM, tera: tera); }
    } SCENE {
        MESSAGE("Terapagos used Tera Starstorm!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_STARSTORM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.5), results[1].damage);
    }
}
