#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TERA_STARSTORM) == EFFECT_TERA_STARSTORM);
}

SINGLE_BATTLE_TEST("Tera Starstorm changes from Normal-type to Stellar-type if used by Terapagos-Stellar")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_TERA_STARSTORM) == TYPE_NORMAL);
        PLAYER(SPECIES_TERAPAGOS_STELLAR);
        OPPONENT(SPECIES_MISDREAVUS);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_STARSTORM); }
    } SCENE {
        MESSAGE("Terapagos used Tera Starstorm!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_STARSTORM, player);
        HP_BAR(opponent);
        NOT { MESSAGE("It doesn't affect the opposing Misdreavus…"); }
    }
}

DOUBLE_BATTLE_TEST("Tera Starstorm targets both opponents in a double battle if used by Terapagos-Stellar")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_TERA_STARSTORM) == TARGET_SELECTED);
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

SINGLE_BATTLE_TEST("Tera Starstorm becomes a physical move if the user is Terapagos-Stellar, is Terastallized, and has a higher Attack stat")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_COUNTER) == EFFECT_REFLECT_DAMAGE);
        ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_COUNTER) == (1u << DAMAGE_CATEGORY_PHYSICAL));
        ASSUME(GetMoveEffect(MOVE_MIRROR_COAT) == EFFECT_REFLECT_DAMAGE);
        ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_MIRROR_COAT) == (1u << DAMAGE_CATEGORY_SPECIAL));
        ASSUME(GetMoveCategory(MOVE_TERA_STARSTORM) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_TERAPAGOS_STELLAR) { Attack(100); SpAttack(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); SpDefense(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_STARSTORM); MOVE(opponent, MOVE_MIRROR_COAT); }
        TURN { MOVE(player, MOVE_TERA_STARSTORM, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_COUNTER); }
    } SCENE {
        MESSAGE("Terapagos used Tera Starstorm!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_STARSTORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponent);
        HP_BAR(player);
        MESSAGE("Terapagos used Tera Starstorm!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_STARSTORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Tera Starstorm remains Normal-type if used by Pokemon other than Terapagos")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_TERA_STARSTORM) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_MISDREAVUS, 0) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_MISDREAVUS);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_STARSTORM, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Wobbuffet used Tera Starstorm!");
        MESSAGE("It doesn't affect the opposing Misdreavus…");
    }
}
