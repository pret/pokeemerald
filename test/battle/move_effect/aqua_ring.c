#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_AQUA_RING) == EFFECT_AQUA_RING);
}

SINGLE_BATTLE_TEST("Aqua Ring fails if already active")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AQUA_RING); }
        TURN { MOVE(player, MOVE_AQUA_RING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_RING, player);
        MESSAGE("Wobbuffet surrounded itself with a veil of water!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_RING, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Aqua Ring recovers 1/16th HP at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AQUA_RING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_RING, player);
    } THEN {
        EXPECT(player->hp == 58);
    }
}

SINGLE_BATTLE_TEST("Aqua Ring restores 30% more HP when holding Big Root")
{
    enum Item item;
    u16 expectedHp;
    PARAMETRIZE { item = ITEM_NONE; expectedHp = 58; }
    PARAMETRIZE { item = ITEM_BIG_ROOT; expectedHp = 60; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_BIG_ROOT].holdEffect == HOLD_EFFECT_BIG_ROOT);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AQUA_RING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_RING, player);
    } THEN {
        EXPECT_EQ(player->hp, expectedHp);
    }
}

SINGLE_BATTLE_TEST("Aqua Ring can be used under Heal Block but will not heal the user")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_AQUA_RING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_RING, player);
    } THEN {
        EXPECT(player->hp == 50);
    }
}

SINGLE_BATTLE_TEST("Aqua Ring's effect is passed by Baton Pass")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AQUA_RING); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_RING, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT(player->hp == 58);
    }
}
