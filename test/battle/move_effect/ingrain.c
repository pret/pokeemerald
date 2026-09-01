#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_INGRAIN) == EFFECT_INGRAIN);
}

SINGLE_BATTLE_TEST("Ingrain fails if already rooted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        MESSAGE("Wobbuffet planted its roots!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Ingrain restores 1/16th HP at the end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
    } THEN {
        EXPECT_EQ(player->hp, 58);
    }
}

SINGLE_BATTLE_TEST("Ingrain restores 30% more HP when holding Big Root")
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
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
    } THEN {
        EXPECT_EQ(player->hp, expectedHp);
    }
}

SINGLE_BATTLE_TEST("Ingrain can be used under Heal Block but will not heal the user")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(128); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
    } THEN {
        EXPECT_EQ(player->hp, 50);
    }
}

SINGLE_BATTLE_TEST("Ingrain prevents regular switching out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
    } THEN {
        u32 battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        EXPECT_EQ(CanBattlerEscape(battler), FALSE);
    }
}

SINGLE_BATTLE_TEST("Ingrain does not prevent switching out with Flip Turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLIP_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_INGRAIN, MOVE_FLIP_TURN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_FLIP_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLIP_TURN, player);
        HP_BAR(opponent);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Ingrain's effect is passed by Baton Pass")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_INGRAIN, MOVE_BATON_PASS); }
        PLAYER(SPECIES_WYNAUT) { HP(50); MaxHP(128); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->hp, 58);
    }
}

TO_DO_BATTLE_TEST("Red Card and forced switch moves (Roar/Whirlwind) cannot force out a rooted Pokémon");
