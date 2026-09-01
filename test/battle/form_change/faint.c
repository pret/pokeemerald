#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aegislash reverts to Shield Form upon fainting (start as Shield)")
{
    GIVEN {
        PLAYER(SPECIES_AEGISLASH_SHIELD) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GUST); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponent);
        HP_BAR(player);
        MESSAGE("Aegislash fainted!");
        SEND_IN_MESSAGE("Wobbuffet");
        SWITCH_OUT_MESSAGE("Wobbuffet")
        SEND_IN_MESSAGE("Aegislash");
    } THEN {
        // We do not check gParties[B_TRAINER_PLAYER] data to avoid triggering FORM_CHANGE_END_BATTLE.
        EXPECT_EQ(player->species, SPECIES_AEGISLASH_SHIELD);
    }
}

SINGLE_BATTLE_TEST("Aegislash reverts to Shield Form upon fainting (start as Blade)")
{
    GIVEN {
        PLAYER(SPECIES_AEGISLASH_BLADE) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GUST); SEND_OUT(player, 1); }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponent);
        HP_BAR(player);
        MESSAGE("Aegislash fainted!");
        SEND_IN_MESSAGE("Wobbuffet");
        SWITCH_OUT_MESSAGE("Wobbuffet")
        SEND_IN_MESSAGE("Aegislash");
    } THEN {
        // We do not check gParties[B_TRAINER_PLAYER] data to avoid triggering FORM_CHANGE_END_BATTLE.
        EXPECT_EQ(player->species, SPECIES_AEGISLASH_SHIELD);
    }
}

DOUBLE_BATTLE_TEST("Causing a Forecast or Flower Gift Pokémon to faint should not cause a message") // issue 7795
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_CASTFORM; }
    PARAMETRIZE { species = SPECIES_CHERRIM; }
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VULPIX) { Ability(ABILITY_DROUGHT); }
        OPPONENT(species) { HP(1); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_GYRO_BALL, target: opponentRight); }
    } SCENE {
        if (species == SPECIES_CASTFORM) {
            MESSAGE("The opposing Castform fainted!");
            NOT MESSAGE("The opposing Castform transformed!");
        } else {
            MESSAGE("The opposing Cherrim fainted!");
            NOT MESSAGE("The opposing Cherrim transformed!");
        }
    }
}

SINGLE_BATTLE_TEST("Ogerpon reverts to the correct form upon fainting after terastallizing")
{
    enum Species species;
    enum Item item;
    PARAMETRIZE { species = SPECIES_OGERPON_TEAL;        item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING;  item = ITEM_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME; item = ITEM_HEARTHFLAME_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE; item = ITEM_CORNERSTONE_MASK; }
    GIVEN {
        PLAYER(species) { HP(1); Item(item); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Terapagos reverts to the correct form upon fainting after terastallizing")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_NORMAL) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_MEMENTO, gimmick: GIMMICK_TERA);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_TERAPAGOS_TERASTAL); // Not Normal form due to Tera Shift
    }
}
