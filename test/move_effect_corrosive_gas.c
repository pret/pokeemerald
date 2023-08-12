#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_CORROSIVE_GAS].effect == EFFECT_CORROSIVE_GAS);
}

SINGLE_BATTLE_TEST("Corrosive Gas destroys the target's item or fails if the target has no item")
{
    u16 item;

    PARAMETRIZE {item = ITEM_NONE; }
    PARAMETRIZE {item = ITEM_POTION; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) {Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_CORROSIVE_GAS); }
    } SCENE {
        MESSAGE("Wobbuffet used CorrosiveGas!");
        if (item == ITEM_POTION) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CORROSIVE_GAS, player);
            MESSAGE("Wobbuffet corroded Foe Wobbuffet's Potion!");
        }
        else {
            MESSAGE("It had no effect on Foe Wobbuffet!");
        }
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Corrosive Gas doesn't destroy the item of a Pokemon with the Sticky Hold ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MUK) {Item(ITEM_POISON_BARB); Ability(ABILITY_STICKY_HOLD); }
    } WHEN {
        TURN { MOVE(player, MOVE_CORROSIVE_GAS); }
    } SCENE {
        MESSAGE("Wobbuffet used CorrosiveGas!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORROSIVE_GAS, player);
        NOT MESSAGE("Wobbuffet corroded Foe Wobbuffet's Potion!");
        ABILITY_POPUP(opponent, ABILITY_STICKY_HOLD);
        MESSAGE("Foe Muk's Sticky Hold made CorrosiveGas ineffective!");
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_POISON_BARB);
    }
}

SINGLE_BATTLE_TEST("Items lost to Corrosive Gas cannot be restored by Recycle")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_RECYCLE].effect == EFFECT_RECYCLE);
        PLAYER(SPECIES_WOBBUFFET) {Speed(15); }
        OPPONENT(SPECIES_WOBBUFFET) {Item(ITEM_ORAN_BERRY); Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_CORROSIVE_GAS); MOVE(opponent, MOVE_RECYCLE); }
    } SCENE {
        MESSAGE("Wobbuffet used CorrosiveGas!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORROSIVE_GAS, player);
        MESSAGE("Wobbuffet corroded Foe Wobbuffet's Oran Berry!");
        MESSAGE("Foe Wobbuffet used Recycle!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Corrosive Gas destroys foes and ally's items if they have one")
{
    // Check it affects all targets in all possible configurations.
    u32 j, k, l;
    u16 itemOpponentLeft, itemOpponentRight, itemPlayerLeft;

    for (j = 0; j < 2; j++) {
        for (k = 0; k < 2; k++) {
             for (l = 0; l < 2; l++) {
                PARAMETRIZE {itemOpponentLeft = (j & 1) ? ITEM_ORAN_BERRY : ITEM_NONE;
                             itemOpponentRight = (k & 1) ? ITEM_CHESTO_BERRY : ITEM_NONE;
                             itemPlayerLeft = (l & 1) ? ITEM_CHERI_BERRY : ITEM_NONE; }
             }
        }
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {Item(itemPlayerLeft);}
        PLAYER(SPECIES_WYNAUT) {Item(ITEM_SITRUS_BERRY);}
        OPPONENT(SPECIES_ABRA) {Item(itemOpponentLeft);}
        OPPONENT(SPECIES_KADABRA) {Item(itemOpponentRight);}
    } WHEN {
        TURN { MOVE(playerRight, MOVE_CORROSIVE_GAS); }
    } SCENE {
        MESSAGE("Wynaut used CorrosiveGas!");
        if (itemPlayerLeft == ITEM_CHERI_BERRY) {
            MESSAGE("Wynaut corroded Wobbuffet's Cheri Berry!");
        } else {
            MESSAGE("It had no effect on Wobbuffet!");
        }
        if (itemOpponentLeft == ITEM_ORAN_BERRY) {
            MESSAGE("Wynaut corroded Foe Abra's Oran Berry!");
        } else {
            MESSAGE("It had no effect on Foe Abra!");
        }
        if (itemOpponentRight == ITEM_CHESTO_BERRY) {
            MESSAGE("Wynaut corroded Foe Kadabra's Chesto Berry!");
        } else {
            MESSAGE("It had no effect on Foe Kadabra!");
        }

    } THEN {
        EXPECT_EQ(playerRight->item, ITEM_SITRUS_BERRY); // Attacker doesn't lose its item.
        EXPECT_EQ(playerLeft->item, ITEM_NONE);
        EXPECT_EQ(opponentLeft->item, ITEM_NONE);
        EXPECT_EQ(opponentRight->item, ITEM_NONE);
    }
}
