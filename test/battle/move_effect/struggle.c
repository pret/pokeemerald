#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Struggle deals recoil 1/4 of damage dealt (Gen 2-3)")

SINGLE_BATTLE_TEST("Struggle deals recoil 1/4 of user's hp (Gen 4+)")
{
    ASSUME(GetMoveEffect(MOVE_STRUGGLE) == EFFECT_STRUGGLE);

    s16 recoil;
    u32 atkStat = 0;
    u32 hpStat = 0;

    PARAMETRIZE { atkStat = 100; hpStat = 200; }
    PARAMETRIZE { atkStat = 50; hpStat = 200; }
    PARAMETRIZE { atkStat = 100; hpStat = 300; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(hpStat); HP(hpStat); Attack(atkStat); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(player, captureDamage: &recoil);
    } THEN {
        EXPECT_MUL_EQ(hpStat, Q_4_12(0.25), recoil);
    }
}

SINGLE_BATTLE_TEST("Struggle can hit ghost types")
{
    ASSUME(GetSpeciesType(SPECIES_DRIFBLIM, 0) == TYPE_GHOST);

    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DRIFBLIM);
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_NE(0, damage);
    }
}

SINGLE_BATTLE_TEST("Struggle does not receive normal-type STAB")
{
    // Compare with Cut, which does receive normal-type STAB
    ASSUME(GetSpeciesType(SPECIES_ZANGOOSE, 0) == GetMoveType(MOVE_STRUGGLE));
    ASSUME(GetMovePower(MOVE_CUT) == GetMovePower(MOVE_STRUGGLE));
    ASSUME(GetMoveCategory(MOVE_CUT) == GetMoveCategory(MOVE_STRUGGLE));
    ASSUME(GetMoveType(MOVE_CUT) == GetMoveType(MOVE_STRUGGLE));

    s16 cutDamage;
    s16 struggleDamage;

    GIVEN {
        PLAYER(SPECIES_ZANGOOSE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CUT); }
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CUT, player);
        HP_BAR(opponent, captureDamage: &cutDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent, captureDamage: &struggleDamage);
    } THEN {
        EXPECT_MUL_EQ(struggleDamage, Q_4_12(1.5), cutDamage);
    }
}

SINGLE_BATTLE_TEST("Struggle recoil is subject to standard rounding (Gen 5+)")
{
    ASSUME(GetMoveEffect(MOVE_STRUGGLE) == EFFECT_STRUGGLE);

    s16 recoil;
    u32 hpStat = 0;

    PARAMETRIZE { hpStat = 200; }
    PARAMETRIZE { hpStat = 201; }
    PARAMETRIZE { hpStat = 202; }
    PARAMETRIZE { hpStat = 203; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(hpStat); HP(hpStat); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(player, captureDamage: &recoil);
    } THEN {
        switch (hpStat)
        {
            case 200:
                EXPECT_EQ(player->hp, 150);
                break;
            case 201:
            case 202:
                EXPECT_EQ(player->hp, 151);
                break;
            case 203:
                EXPECT_EQ(player->hp, 152);
                break;
        }
    }
}
