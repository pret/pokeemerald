#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    int i;
    for (i = 0; i < NUM_ABILITY_SLOTS; i++) {
        ASSUME(GetSpeciesAbility(SPECIES_KADABRA, i) != ABILITY_QUARK_DRIVE);
        ASSUME(GetSpeciesAbility(SPECIES_ALAKAZAM, i) != ABILITY_ELECTRIC_SURGE);
    }
}

SINGLE_BATTLE_TEST("Forced abilities activate on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_ALAKAZAM);
        PLAYER(SPECIES_KADABRA) { Ability(ABILITY_QUARK_DRIVE); SpAttack(400); }
        OPPONENT(SPECIES_ARON);
        OPPONENT(SPECIES_ALAKAZAM) { Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Kadabra's Quark Drive!");
        MESSAGE("Kadabra's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Setting level doesn't overwrite set stats")
{
    u32 level = 0;

    PARAMETRIZE { level = 1; }
    PARAMETRIZE { level = 10; }
    PARAMETRIZE { level = 50; }
    PARAMETRIZE { level = 99; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(5); MaxHP(10); Attack(10); Defense(10); Speed(10); SpAttack(10); SpDefense(10); Level(level); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 5);
        EXPECT_EQ(player->maxHP, 10);
        EXPECT_EQ(player->attack, 10);
        EXPECT_EQ(player->defense, 10);
        EXPECT_EQ(player->speed, 10);
        EXPECT_EQ(player->spAttack, 10);
        EXPECT_EQ(player->spDefense, 10);
    }
}

SINGLE_BATTLE_TEST("Changing forms doesn't overwrite set stats (not HP)")
{
    GIVEN {
        PLAYER(SPECIES_DIANCIE) { Attack(10); Defense(10); Speed(10); SpAttack(10); SpDefense(10); Item(ITEM_DIANCITE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
    } THEN {
        EXPECT_EQ(player->attack, 10);
        EXPECT_EQ(player->defense, 10);
        EXPECT_EQ(player->speed, 10);
        EXPECT_EQ(player->spAttack, 10);
        EXPECT_EQ(player->spDefense, 10);
    }
}

SINGLE_BATTLE_TEST("Changing forms doesn't overwrite set stats (HP)")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS) { HP(5); MaxHP(10); TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 5);
        EXPECT_EQ(player->maxHP, 10);
    }
}

MULTI_BATTLE_TEST("Multi Battle Tests register partner's status1")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WILL_O_WISP, target: playerRight); }
    } SCENE {
        STATUS_ICON(playerRight, STATUS1_BURN);
    }
}
