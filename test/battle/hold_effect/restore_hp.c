#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Restore HP Item effects do not miss timing (Berries)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ORAN_BERRY; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_BERRY_JUICE].holdEffect == HOLD_EFFECT_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { MaxHP(100); HP(51); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        MESSAGE("A sea of fire enveloped the opposing side!");
        MESSAGE("The opposing Wynaut was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        MESSAGE("The opposing Wobbuffet was hurt by the sea of fire!");
    }
}

DOUBLE_BATTLE_TEST("Restore HP Item effects do not miss timing (Held Items)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_BERRY_JUICE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_BERRY_JUICE].holdEffect == HOLD_EFFECT_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { MaxHP(100); HP(51); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        MESSAGE("A sea of fire enveloped the opposing side!");
        MESSAGE("The opposing Wynaut was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("The opposing Wobbuffet was hurt by the sea of fire!");
    }
}

DOUBLE_BATTLE_TEST("Restore HP Item effects do not miss timing after a recoil move (Berries)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ORAN_BERRY; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; }

    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_TAKE_DOWN) == 25);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { MaxHP(100); HP(51); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_TAKE_DOWN, target: playerLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Restore HP Item effects do not miss timing after a recoil move (Held Items)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_BERRY_JUICE; }

    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_TAKE_DOWN) == 25);
        ASSUME(gItemsInfo[ITEM_BERRY_JUICE].holdEffect == HOLD_EFFECT_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { MaxHP(100); HP(51); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_TAKE_DOWN, target: playerLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
    }
}

SINGLE_BATTLE_TEST("Sitrus Berry restores HP immediately after Leech Seed damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(80); HP(41); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEECH_SEED); }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, player);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Healing berry animates on the correct battler at battle start")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(400); Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN {  }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    }
}

SINGLE_BATTLE_TEST("Sitrus Berry restores HP before Shields Down form change")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_MINIOR_CORE) {
            Ability(ABILITY_SHIELDS_DOWN); HP(53); MaxHP(101); Item(ITEM_SITRUS_BERRY);
        }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent); // Scratch
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        }
        HP_BAR(opponent); // Heal
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}
