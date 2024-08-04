#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dusk Mane Necrozma can Ultra Burst holding Ultranecrozium Z")
{
    GIVEN {
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
    } SCENE {
        MESSAGE("Bright light is about to burst out of Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, player);
        MESSAGE("Necrozma regained its true power through Ultra Burst!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_NECROZMA_ULTRA);
    }
}

DOUBLE_BATTLE_TEST("Ultra Burst's order is determined by Speed - opponent faster")
{
    GIVEN {
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_NECROZMA_DAWN_WINGS) { Item(ITEM_ULTRANECROZIUM_Z); Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
    } SCENE {
        MESSAGE("Bright light is about to burst out of Foe Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, opponentLeft);
        MESSAGE("Foe Necrozma regained its true power through Ultra Burst!");
        MESSAGE("Bright light is about to burst out of Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, playerLeft);
        MESSAGE("Necrozma regained its true power through Ultra Burst!");
    }
}

DOUBLE_BATTLE_TEST("Ultra Burst's order is determined by Speed - player faster")
{
    GIVEN {
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_NECROZMA_DAWN_WINGS) { Item(ITEM_ULTRANECROZIUM_Z); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
    } SCENE {
        MESSAGE("Bright light is about to burst out of Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, playerLeft);
        MESSAGE("Necrozma regained its true power through Ultra Burst!");
        MESSAGE("Bright light is about to burst out of Foe Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, opponentLeft);
        MESSAGE("Foe Necrozma regained its true power through Ultra Burst!");
    }
}

SINGLE_BATTLE_TEST("Ultra Burst affects turn order")
{
    GIVEN {
        ASSUME(B_MEGA_EVO_TURN_ORDER >= GEN_7);
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); Speed(105); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(106); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
    } SCENE {
        MESSAGE("Necrozma used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } THEN {
        ASSUME(player->speed == 263);
    }
}

DOUBLE_BATTLE_TEST("Ultra Burst happens after switching, but before Focus Punch-like Moves")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FOCUS_PUNCH].effect == EFFECT_FOCUS_PUNCH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponentRight, 2); MOVE(playerRight, MOVE_FOCUS_PUNCH, gimmick: GIMMICK_ULTRA_BURST, target: opponentLeft); MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); }
        TURN {}
    } SCENE {
        MESSAGE("2 withdrew Wobbuffet!");
        MESSAGE("2 sent out Wobbuffet!");

        MESSAGE("Bright light is about to burst out of Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, playerRight);
        MESSAGE("Necrozma regained its true power through Ultra Burst!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerRight);
        MESSAGE("Necrozma is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        MESSAGE("Wobbuffet is tightening its focus!");
    }
}

SINGLE_BATTLE_TEST("Ultra Burst and Mega Evolution can happen on the same turn")
{
    GIVEN {
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); Speed(3); }
        OPPONENT(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Bright light is about to burst out of Necrozma!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, player);
        MESSAGE("Necrozma regained its true power through Ultra Burst!");

        MESSAGE("Foe Gardevoir's Gardevoirite is reacting to 2's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("Foe Gardevoir has Mega Evolved into Mega Gardevoir!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_NECROZMA_ULTRA);
        EXPECT_EQ(opponent->species, SPECIES_GARDEVOIR_MEGA);
    }
}
