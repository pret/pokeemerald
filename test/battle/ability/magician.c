#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Magician gets self-damage recoil after stealing Life Orb")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // 1st turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
        MESSAGE("Delphox stole the opposing Wobbuffet's Life Orb!");
        HP_BAR(player);
        MESSAGE("Delphox lost some of its HP!");
        // 2nd turn - Life Orb recoil happens now
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(player);
        MESSAGE("Delphox lost some of its HP!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_LIFE_ORB);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Magician prioritizes opponents over allies among valid targets by speed")
{
    u32 playerRightSpeed = 0;
    u32 opponentLeftSpeed = 0;
    u32 opponentRightSpeed = 0;
    enum Item expectedItem = ITEM_NONE;

    PARAMETRIZE { playerRightSpeed = 4; opponentLeftSpeed = 2; opponentRightSpeed = 3; expectedItem = ITEM_ULTRA_BALL; }
    PARAMETRIZE { playerRightSpeed = 3; opponentLeftSpeed = 4; opponentRightSpeed = 2; expectedItem = ITEM_GREAT_BALL; }
    PARAMETRIZE { playerRightSpeed = 2; opponentLeftSpeed = 3; opponentRightSpeed = 4; expectedItem = ITEM_ULTRA_BALL; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_DELPHOX) { Speed(1); Ability(ABILITY_MAGICIAN); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(playerRightSpeed); Item(ITEM_POKE_BALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(opponentLeftSpeed); Item(ITEM_GREAT_BALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(opponentRightSpeed); Item(ITEM_ULTRA_BALL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(playerLeft->item, expectedItem);
    }
}

DOUBLE_BATTLE_TEST("Magician follows Trick Room order when choosing between foe targets")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        PLAYER(SPECIES_DELPHOX) { Speed(3); Ability(ABILITY_MAGICIAN); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Item(ITEM_GREAT_BALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_ULTRA_BALL); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TRICK_ROOM); }
        TURN { MOVE(playerLeft, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_MAGICIAN);
    } THEN {
        // Under Trick Room, the slower foe should be chosen first.
        EXPECT_EQ(playerLeft->item, ITEM_ULTRA_BALL);
    }
}

DOUBLE_BATTLE_TEST("Magician can steal from ally if no opponent is a valid target")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_DELPHOX) { Speed(1); Ability(ABILITY_MAGICIAN); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_POKE_BALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_POKE_BALL);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Magician is blocked by Sticky Hold unless the target faints")
{
    bool32 stickyHoldTargetFaints = FALSE;

    PARAMETRIZE { stickyHoldTargetFaints = FALSE; }
    PARAMETRIZE { stickyHoldTargetFaints = TRUE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_DELPHOX) { Speed(1); Ability(ABILITY_MAGICIAN); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_POKE_BALL); }
        OPPONENT(SPECIES_MUK) { Speed(4); HP(stickyHoldTargetFaints ? 1 : 600); Ability(ABILITY_STICKY_HOLD); Item(ITEM_GREAT_BALL); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); Item(ITEM_ULTRA_BALL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        if (stickyHoldTargetFaints)
            ABILITY_POPUP(playerLeft, ABILITY_MAGICIAN);
        else
            NOT ABILITY_POPUP(playerLeft, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(playerLeft->item, stickyHoldTargetFaints ? ITEM_GREAT_BALL : ITEM_NONE);
        EXPECT_EQ(playerRight->item, ITEM_POKE_BALL);
        EXPECT_EQ(opponentLeft->item, stickyHoldTargetFaints ? ITEM_NONE : ITEM_GREAT_BALL);
        EXPECT_EQ(opponentRight->item, ITEM_ULTRA_BALL);
    }
}

SINGLE_BATTLE_TEST("Magician does not activate with Fling")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); Item(ITEM_PECHA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POKE_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        NOT ABILITY_POPUP(player, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_POKE_BALL);
    }
}

SINGLE_BATTLE_TEST("Magician does not activate with Natural Gift")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); Item(ITEM_PECHA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POKE_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
        NOT ABILITY_POPUP(player, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_POKE_BALL);
    }
}

SINGLE_BATTLE_TEST("Magician does not activate with Future Sight or Doom Desire")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POKE_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        NOT ABILITY_POPUP(player, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_POKE_BALL);
    }
}

SINGLE_BATTLE_TEST("Magician activates after the last hit of a multi-hit move")
{
    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_DOUBLE_KICK) == 2);
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POKE_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(player->item, ITEM_POKE_BALL);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Magician steals before switching with U-turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POKE_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Magician does not activate if user faints from Rocky Helmet recoil")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ROCKY_HELMET].holdEffect == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_DELPHOX) { HP(1); Ability(ABILITY_MAGICIAN); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(player);
        NOT ABILITY_POPUP(player, ABILITY_MAGICIAN);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_ROCKY_HELMET);
    }
}

SINGLE_BATTLE_TEST("Magician allows activation of stolen Throat Spray")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_THROAT_SPRAY) == HOLD_EFFECT_THROAT_SPRAY);
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
        MESSAGE("Delphox stole the opposing Wobbuffet's Throat Spray!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_NONE);
        EXPECT_GT(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}
