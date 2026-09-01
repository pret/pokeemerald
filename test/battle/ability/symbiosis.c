#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Symbiosis transfers its item to an ally after it consumes an item")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(gItemsInfo[ITEM_ROOM_SERVICE].holdEffect == HOLD_EFFECT_ROOM_SERVICE);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ROOM_SERVICE); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_KIRLIA);
        OPPONENT(SPECIES_SHUCKLE);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TRICK_ROOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        // symbiosis triggers
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        MESSAGE("Oranguru shared its Toxic Orb with Wobbuffet!");
        // end of turn, wobb gets poisoned
        MESSAGE("Wobbuffet was badly poisoned!");
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis triggers after partners berry eaten from bug bite")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_BUG_BITE, MOVE_EFFECT_BUG_BITE));
        ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].holdEffect == HOLD_EFFECT_ATTACK_UP);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_STARAVIA);
        OPPONENT(SPECIES_SHUCKLE);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BUG_BITE, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        // symbiosis triggers
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        MESSAGE("Oranguru shared its Toxic Orb with Wobbuffet!");
        // end of turn, wobb gets poisoned
        MESSAGE("Wobbuffet was badly poisoned!");
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis triggers after partner bestows its item")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BESTOW) == EFFECT_BESTOW);
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(ITEM_FLAME_ORB); }
        PLAYER(SPECIES_ORANGURU) { Speed(75); Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_STARAVIA) { Speed(50); }
        OPPONENT(SPECIES_SHUCKLE) { Speed(25); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BESTOW, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BESTOW, playerLeft);
        MESSAGE("The opposing Staravia received Flame Orb from Wobbuffet!");
        // symbiosis triggers
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        MESSAGE("Oranguru shared its Toxic Orb with Wobbuffet!");
        // end of turn, wobb gets poisoned
        MESSAGE("Wobbuffet was badly poisoned!");
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
        // staravia gets burned
        MESSAGE("The opposing Staravia was burned!");
        STATUS_ICON(opponentLeft, STATUS1_BURN);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
        EXPECT_EQ(opponentLeft->item, ITEM_FLAME_ORB);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis triggers after partner flings its item")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(ITEM_FLAME_ORB); }
        PLAYER(SPECIES_ORANGURU) { Speed(75); Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_STARAVIA) { Speed(50); }
        OPPONENT(SPECIES_SHUCKLE) { Speed(25); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLING, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, playerLeft);
        MESSAGE("The opposing Staravia was burned!");
        STATUS_ICON(opponentLeft, STATUS1_BURN);
        // symbiosis triggers
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        MESSAGE("Oranguru shared its Toxic Orb with Wobbuffet!");
        // end of turn, wobb gets poisoned
        MESSAGE("Wobbuffet was badly poisoned!");
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis transfers its item to an ally after it consumes a weakness berry")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHILAN_BERRY); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("A spread move does not consume items received through Symbiosis as resistance Berries")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetItemHoldEffect(ITEM_SHUCA_BERRY) == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(GetItemHoldEffectParam(ITEM_SHUCA_BERRY) == TYPE_GROUND);
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_POTION); }
        PLAYER(SPECIES_PIKACHU) { Item(ITEM_SHUCA_BERRY); }
        OPPONENT(SPECIES_PIKACHU) { Item(ITEM_SHUCA_BERRY); }
        OPPONENT(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_SYMBIOSIS);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_SYMBIOSIS);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, playerRight);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_NONE);
        EXPECT_EQ(playerRight->item, ITEM_POTION);
        EXPECT_EQ(opponentLeft->item, ITEM_POTION);
        EXPECT_EQ(opponentRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis transfers its item after Gem consumption and move execution (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_SYMBIOSIS_GEMS, GEN_7);
        ASSUME(GetItemHoldEffect(ITEM_NORMAL_GEM) == HOLD_EFFECT_GEMS);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("The Normal Gem strengthened Wobbuffet's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis transfers its item after Gem consumption, but before move execution (Gen6)")
{
    GIVEN {
        WITH_CONFIG(B_SYMBIOSIS_GEMS, GEN_6);
        ASSUME(GetItemHoldEffect(ITEM_NORMAL_GEM) == HOLD_EFFECT_GEMS);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_TOXIC_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("The Normal Gem strengthened Wobbuffet's power!");
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        STATUS_ICON(playerLeft, STATUS1_TOXIC_POISON);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_TOXIC_ORB);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis does not transfer its item after an ally's Eject Button activates")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_POTION); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet is switched out with the Eject Button!");
        NOT ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
    } THEN {
        EXPECT_EQ(playerRight->item, ITEM_POTION);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis does not transfer its item after an ally's Eject Pack activates")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_POTION); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CHARM, target: playerLeft); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        NOT ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
    } THEN {
        EXPECT_EQ(playerRight->item, ITEM_POTION);
    }
}

DOUBLE_BATTLE_TEST("Symbiosis triggers after an ally's Cheek Pouch activates")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        PLAYER(SPECIES_DEDENNE) { Ability(ABILITY_CHEEK_POUCH); MaxHP(60); HP(31); Item(ITEM_ORAN_BERRY); }
        PLAYER(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SUPER_FANG, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, playerLeft);
        HP_BAR(playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_CHEEK_POUCH);
        HP_BAR(playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_SYMBIOSIS);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_POTION);
        EXPECT_EQ(playerRight->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Opposing Symbiosis ignores the player's stolen-item record")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(GetItemHoldEffect(ITEM_ROOM_SERVICE) == HOLD_EFFECT_ROOM_SERVICE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LEFTOVERS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROOM_SERVICE); }
        OPPONENT(SPECIES_ORANGURU) { Ability(ABILITY_SYMBIOSIS); Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_KNOCK_OFF, target: playerLeft); }
        TURN { MOVE(playerRight, MOVE_TRICK_ROOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_SYMBIOSIS);
    } THEN {
        EXPECT_EQ(opponentLeft->item, ITEM_POTION);
        EXPECT_EQ(opponentRight->item, ITEM_NONE);
    }
}
