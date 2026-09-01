#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_MARANGA_BERRY].holdEffect == HOLD_EFFECT_MARANGA_BERRY);
}

SINGLE_BATTLE_TEST("Maranga Berry raises the holder's Sp. Def by one stage when hit by a special move")
{
    enum Move move = MOVE_NONE;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_MARANGA_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_SWIFT) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
            MESSAGE("The Maranga Berry boosted the opposing Wobbuffet's Sp. Def!");
        }
        else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
                MESSAGE("The Maranga Berry boosted the opposing Wobbuffet's Sp. Def!");
            }
        }
    } THEN {
        if (move == MOVE_SWIFT)
            EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Maranga Berry raises the holder's Sp. Def by two stages with Ripen when hit by a special move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_APPLIN) { Item(ITEM_MARANGA_BERRY); Ability(ABILITY_RIPEN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        MESSAGE("The Maranga Berry sharply boosted the opposing Applin's Sp. Def!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Maranga Berry doesn't trigger if the item hold user used a special move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MARANGA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("The Maranga Berry sharply boosted the opposing Applin's Sp. Def!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Maranga Berry doesn't trigger if partner was hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_MARANGA_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
    } THEN {
        EXPECT(opponentRight->item == ITEM_MARANGA_BERRY);
    }
}

SINGLE_BATTLE_TEST("Maranga Berry doesn't trigger if the move was boosted by Sheer Force")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MARANGA_BERRY); }
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FIRE_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PUNCH, opponent);
        HP_BAR(player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}
