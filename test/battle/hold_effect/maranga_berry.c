#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_MARANGA_BERRY].holdEffect == HOLD_EFFECT_MARANGA_BERRY);
}

SINGLE_BATTLE_TEST("Maranga Berry raises the holder's Sp. Def by one stage when hit by a special move")
{
    u16 move = MOVE_NONE;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_SWIFT].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_MARANGA_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_SWIFT) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("Using Maranga Berry, the Sp. Def of Foe Wobbuffet rose!");
        }
        else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
                MESSAGE("Using Maranga Berry, the Sp. Def of Foe Wobbuffet rose!");
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
        ASSUME(gMovesInfo[MOVE_SWIFT].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_APPLIN) { Item(ITEM_MARANGA_BERRY); Ability(ABILITY_RIPEN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("Using Maranga Berry, the Sp. Def of Foe Applin sharply rose!");
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
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Using Maranga Berry, the Sp. Def of Applin sharply rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}
