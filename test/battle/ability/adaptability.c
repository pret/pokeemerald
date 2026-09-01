#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Adaptability increases same-type attack bonus from x1.5 to x2", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_ADAPTABILITY; }
    GIVEN {
        PLAYER(SPECIES_CRAWDAUNT) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        MESSAGE("Crawdaunt used Water Gun!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from 1.5x STAB to 2.0x STAB is a 1.33x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.33), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into a different type with Adaptability gives 2.0x STAB", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_CRAWDAUNT) { Ability(ABILITY_ADAPTABILITY); TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT, gimmick: tera); }
    } SCENE {
        MESSAGE("Crawdaunt used Headbutt!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from no STAB to 2.0x STAB is a 2.0x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Terastallizing into the same type with Adaptability gives 2.25x STAB", s16 damage)
{
    bool32 tera;
    PARAMETRIZE { tera = GIMMICK_NONE; }
    PARAMETRIZE { tera = GIMMICK_TERA; }
    GIVEN {
        PLAYER(SPECIES_CRAWDAUNT) { Ability(ABILITY_ADAPTABILITY); TeraType(TYPE_WATER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_PULSE, gimmick: tera); }
    } SCENE {
        MESSAGE("Crawdaunt used Water Pulse!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PULSE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // The jump from 2x STAB to 2.25x STAB is a 1.125x boost.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.125), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Adaptability does not increase non-Tera base STAB beyond 1.5x", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_GUST; }
    PARAMETRIZE { move = MOVE_WATER_GUN; }
    GIVEN {
        PLAYER(SPECIES_CRAWDAUNT) { Ability(ABILITY_ADAPTABILITY); TeraType(TYPE_NORMAL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // With Adaptability, non-Tera base type should still be 1.5x STAB (not 2.0x).
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(TERA) Adaptability does not affect Stellar-type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_HYPER_CUTTER; }
    PARAMETRIZE { ability = ABILITY_ADAPTABILITY; }
    GIVEN {
        PLAYER(SPECIES_CRAWDAUNT) { Ability(ability); TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
