#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_KEE_BERRY].holdEffect == HOLD_EFFECT_KEE_BERRY);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Kee Berry raises the holder's Defense by one stage when hit by a physical move")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_SCRATCH; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_KEE_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_SCRATCH) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
            MESSAGE("The Kee Berry boosted the opposing Wobbuffet's Defense!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
                MESSAGE("The Kee Berry boosted the opposing Wobbuffet's Defense!");
            }
        }
    } THEN {
        if (move == MOVE_SCRATCH)
            EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Kee Berry raises the holder's Defense by two stages with Ripen when hit by a physical move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_APPLIN) { Item(ITEM_KEE_BERRY); Ability(ABILITY_RIPEN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        MESSAGE("The Kee Berry sharply boosted the opposing Applin's Defense!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Kee Berry doesn't trigger if the item hold user used a physical move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_KEE_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("The Kee Berry boosted Wobbuffet's Defense!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Kee Berry doesn't trigger if partner was hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_KEE_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
    } THEN {
        EXPECT(opponentRight->item == ITEM_KEE_BERRY);
    }
}

SINGLE_BATTLE_TEST("Kee Berry doesn't trigger if the move was boosted by Sheer Force")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_KEE_BERRY); }
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        HP_BAR(player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}