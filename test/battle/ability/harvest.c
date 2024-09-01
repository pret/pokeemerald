#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
    ASSUME(I_SITRUS_BERRY_HEAL >= GEN_4);
    ASSUME(gMovesInfo[MOVE_SUNNY_DAY].effect == EFFECT_SUNNY_DAY);
}

SINGLE_BATTLE_TEST("Harvest has a 50% chance to restore a Berry at the end of the turn")
{
    PASSES_RANDOMLY(1, 2, RNG_HARVEST);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Harvest always restores a Berry in Sunlight")
{
    PASSES_RANDOMLY(1, 1, RNG_HARVEST);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Harvest doesn't always restore a Berry if Cloud Nine/Air Lock is on the field")
{
    PASSES_RANDOMLY(1, 2, RNG_HARVEST);
    GIVEN {
        PLAYER(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Harvest restores a Berry even after being switched out and back in")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_PARTING_SHOT].effect == EFFECT_PARTING_SHOT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Harvest restores a Berry consumed by Fling")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FLING].effect == EFFECT_FLING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, opponent);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Harvest restores a Berry consumed by Natural Gift")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_NATURAL_GIFT].effect == EFFECT_NATURAL_GIFT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_NATURAL_GIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, opponent);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_SITRUS_BERRY);
    }
}

TO_DO_BATTLE_TEST("Harvest only works once per turn"); // Check for berries that are consumed immediately, like Pecha Berry

SINGLE_BATTLE_TEST("Harvest doesn't restore a Berry when destroyed by Incinerate")
{
    PASSES_RANDOMLY(1, 1, RNG_HARVEST);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_INCINERATE, MOVE_EFFECT_INCINERATE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Harvest doesn't restore a Berry when knocked off by Knock Off")
{
    PASSES_RANDOMLY(1, 1, RNG_HARVEST);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_KNOCK_OFF, MOVE_EFFECT_KNOCK_OFF));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Harvest doesn't restore a Berry when eaten by Bug Bite/Pluck")
{
    PASSES_RANDOMLY(1, 1, RNG_HARVEST);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_BUG_BITE, MOVE_EFFECT_BUG_BITE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Harvest doesn't restore a Berry that's collected via Pickup")
{
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Speed(50); Ability(ABILITY_PICKUP); }
        OPPONENT(SPECIES_EXEGGUTOR) { Speed(10); Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ABILITY_POPUP(player, ABILITY_PICKUP);
        MESSAGE("Zigzagoon found one Sitrus Berry!");
        NOT ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(player->item, ITEM_SITRUS_BERRY);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Harvest order is affected by speed")
{
    GIVEN {
        PLAYER(SPECIES_EXEGGUTOR) { Speed(2); Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_EXEGGUTOR) { Speed(10); Ability(ABILITY_HARVEST); MaxHP(500); HP(251); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_BULLDOZE); MOVE(playerLeft, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_HARVEST);
        ABILITY_POPUP(playerLeft, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponentLeft->item, ITEM_SITRUS_BERRY);
        EXPECT_EQ(playerLeft->item, ITEM_SITRUS_BERRY);
    }
}

SINGLE_BATTLE_TEST("Harvest doesn't restore a Berry when transfered to another Pokémon")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TRICK].effect == EFFECT_TRICK);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); Item(ITEM_SITRUS_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_TRICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_HARVEST);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Harvest can restore a Berry that was transferred from another Pokémon")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TRICK].effect == EFFECT_TRICK);
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); HP(100); MaxHP(500); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT_GT(opponent->hp, opponent->maxHP / 2); // eats 2 Sitrus
    }
}

SINGLE_BATTLE_TEST("Harvest can only restore the newest berry consumed that was transferred from another Pokémon instead of its original Berry")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TRICK].effect == EFFECT_TRICK);
        ASSUME(gItemsInfo[ITEM_APICOT_BERRY].holdEffect == HOLD_EFFECT_SP_DEFENSE_UP);
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_EXEGGUTOR) { Ability(ABILITY_HARVEST); HP(100); MaxHP(500); Item(ITEM_APICOT_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ABILITY_POPUP(opponent, ABILITY_HARVEST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT_GT(opponent->hp, opponent->maxHP / 2); // eats 2 Sitrus
    }
}
