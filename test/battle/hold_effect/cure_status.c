#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
}

SINGLE_BATTLE_TEST("Pecha and Lum Berries cure poison")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_POWDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, poison: FALSE);
    }
}

SINGLE_BATTLE_TEST("Pecha and Lum Berries cure bad poison")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, badPoison: FALSE);
    }
}

SINGLE_BATTLE_TEST("Rawst and Lum Berries cure burn")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_RAWST_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_RAWST_BERRY].holdEffect == HOLD_EFFECT_CURE_BRN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
        STATUS_ICON(opponent, burn: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, burn: FALSE);
    }
}

SINGLE_BATTLE_TEST("Aspear and Lum Berries cure freeze or frostbite")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ASPEAR_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_ASPEAR_BERRY].holdEffect == HOLD_EFFECT_CURE_FRZ);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_ICE_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_PUNCH, player);
        ANIMATION(ANIM_TYPE_STATUS, (B_USE_FROSTBITE ? B_ANIM_STATUS_FRB : B_ANIM_STATUS_FRZ), opponent);
        FREEZE_OR_FROSTBURN_STATUS(opponent, TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        FREEZE_OR_FROSTBURN_STATUS(opponent, FALSE);
    }
}

SINGLE_BATTLE_TEST("Chesto and Lum Berries cure sleep")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_CHESTO_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPNOSIS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPNOSIS, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, sleep: FALSE);
    }
}

SINGLE_BATTLE_TEST("Chesto Berry cures sleep when Yawn takes effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_CHESTO_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_YAWN); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
        STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        STATUS_ICON(player, sleep: FALSE);
    }
}

SINGLE_BATTLE_TEST("Chesto and Lum Berries don't trigger if the holder has Comatose")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_CHESTO_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); Item(item); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    } THEN {
        EXPECT_EQ(opponent->item, item);
    }
}

SINGLE_BATTLE_TEST("Cheri and Lum Berries cure paralysis")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_CHERI_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHERI_BERRY].holdEffect == HOLD_EFFECT_CURE_PAR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, paralysis: FALSE);
    }
}

SINGLE_BATTLE_TEST("Perism and Lum Berries cure confusion")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PERSIM_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_PERSIM_BERRY].holdEffect == HOLD_EFFECT_CURE_CONFUSION);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    }
}

SINGLE_BATTLE_TEST("Berry hold effect cures status if a Pokémon enters a battle")
{
    u16 status;
    enum Item item;

    PARAMETRIZE { status = STATUS1_BURN; item = ITEM_RAWST_BERRY; }
    PARAMETRIZE { status = STATUS1_FREEZE; item = ITEM_ASPEAR_BERRY; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; item = ITEM_CHERI_BERRY; }
    PARAMETRIZE { status = STATUS1_POISON; item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { status = STATUS1_SLEEP; item = ITEM_CHESTO_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_RAWST_BERRY].holdEffect == HOLD_EFFECT_CURE_BRN);
        ASSUME(gItemsInfo[ITEM_ASPEAR_BERRY].holdEffect == HOLD_EFFECT_CURE_FRZ);
        ASSUME(gItemsInfo[ITEM_CHERI_BERRY].holdEffect == HOLD_EFFECT_CURE_PAR);
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        ASSUME(gItemsInfo[ITEM_CHESTO_BERRY].holdEffect == HOLD_EFFECT_CURE_SLP);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); Item(ITEM_LUM_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); Item(item); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    }
}

SINGLE_BATTLE_TEST("Opponent Pokemon can be further poisoned with Toxic spikes after a status healing hold effect was previously used")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic Spikes!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        // 1st switch-in
        MESSAGE("2 sent out Wynaut!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        if (item == ITEM_PECHA_BERRY) {
            MESSAGE("The opposing Wynaut's Pecha Berry cured its poison!");
        } else {
            MESSAGE("The opposing Wynaut's Lum Berry cured its poison!");
        }
        STATUS_ICON(opponent, poison: FALSE);
        // 2nd switch-in
        MESSAGE("2 sent out Wobbuffet!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    }
}

// Basically same as above, but with the sides reversed.
SINGLE_BATTLE_TEST("Player Pokemon can be further poisoned with Toxic spikes after a status healing hold effect was previously used")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PECHA_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_PECHA_BERRY].holdEffect == HOLD_EFFECT_CURE_PSN);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Toxic Spikes!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, opponent);
        MESSAGE("Toxic spikes were scattered on the ground all around your side!");
        // 1st switch-in
        SEND_IN_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        if (item == ITEM_PECHA_BERRY) {
            MESSAGE("Wobbuffet's Pecha Berry cured its poison!");
        } else {
            MESSAGE("Wobbuffet's Lum Berry cured its poison!");
        }
        STATUS_ICON(player, poison: FALSE);
        // 2nd switch-in
        SEND_IN_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, player);
        STATUS_ICON(player, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Lum Berry correctly cures all battlers if multiple fainted the previous turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CATERPIE) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); Status1(STATUS1_BURN); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION);
               SEND_OUT(opponentRight, 3);
               SEND_OUT(opponentLeft, 2);
               SEND_OUT(playerRight, 3);
               SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->status1, STATUS1_NONE);
        EXPECT_EQ(playerRight->status1, STATUS1_NONE);
        EXPECT_EQ(opponentLeft->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Lum Berry properly cures a battler affected by only confusion")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, 0)); }
        TURN { MOVE(opponent, MOVE_SWITCHEROO); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("Wobbuffet's Lum Berry snapped it out of its confusion!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT(player->volatiles.confusionTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Lum Berry properly cures a battler affected by a non-volatiles status and confusion")
{
    u32 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_FROZEN, 0)); }
        TURN { MOVE(opponent, MOVE_SWITCHEROO); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Wobbuffet's Lum Berry cured its burn!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Wobbuffet's Lum Berry defrosted it!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Wobbuffet's Lum Berry cured its paralysis!");
                break;
            case STATUS1_POISON:
                MESSAGE("Wobbuffet's Lum Berry cured its poison!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Wobbuffet's Lum Berry cured its poison!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("Wobbuffet's Lum Berry woke it up!");
                break;
        }
        MESSAGE("Wobbuffet's Lum Berry snapped it out of its confusion!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT(player->volatiles.confusionTimer == 0);
    }
}
