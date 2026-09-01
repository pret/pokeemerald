#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta if used successfully")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

SINGLE_BATTLE_TEST("Relic Song does not transform Pokemon other than Meloetta")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
            MESSAGE("Wobbuffet transformed!");
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta twice if used successfully")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_ARIA);
    }
}

SINGLE_BATTLE_TEST("Relic Song transformation activates after target faints")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_GOSSIFLEUR) { HP(1); Ability(ABILITY_COTTON_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_COTTON_DOWN);
        MESSAGE("Meloetta's Speed fell!");
        MESSAGE("The opposing Gossifleur fainted!");
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

DOUBLE_BATTLE_TEST("Relic Song transforms once Meloetta in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

SINGLE_BATTLE_TEST("Relic Song loses the form-changing effect with Sheer Force")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        NOT MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_ARIA);
    }
}

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta after Magician was activated")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
        MESSAGE("Meloetta stole the opposing Delphox's Potion!");
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta before taking Life Orb damage")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_LIFE_ORB) == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_MELOETTA_ARIA) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}
