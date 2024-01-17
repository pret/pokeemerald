#include "global.h"
#include "test/battle.h"

// Please add Utility Umbrella interactions with move, item and ability effects on their respective files.
ASSUMPTIONS
{
    ASSUME(gItems[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
    ASSUME(gBattleMoves[MOVE_EMBER].type == TYPE_FIRE);
    ASSUME(gBattleMoves[MOVE_WATER_GUN].type == TYPE_WATER);
}

SINGLE_BATTLE_TEST("Utility Umbrella blocks Sun damage modifiers", s16 damage)
{
    u16 setupMove, attackingMove, heldItem;
    PARAMETRIZE { setupMove = MOVE_SUNNY_DAY; attackingMove = MOVE_EMBER;     heldItem = ITEM_UTILITY_UMBRELLA; }
    PARAMETRIZE { setupMove = MOVE_SUNNY_DAY; attackingMove = MOVE_EMBER;     heldItem = ITEM_NONE; }
    PARAMETRIZE { setupMove = MOVE_SUNNY_DAY; attackingMove = MOVE_WATER_GUN; heldItem = ITEM_UTILITY_UMBRELLA; }
    PARAMETRIZE { setupMove = MOVE_SUNNY_DAY; attackingMove = MOVE_WATER_GUN; heldItem = ITEM_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(heldItem); };
    } WHEN {
        TURN { MOVE(opponent, setupMove); }
        TURN { MOVE(player, attackingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, attackingMove, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.5), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Utility Umbrella blocks Rain damage modifiers", s16 damage)
{
    u16 setupMove, attackingMove, heldItem;
    PARAMETRIZE { setupMove = MOVE_RAIN_DANCE; attackingMove = MOVE_EMBER;     heldItem = ITEM_UTILITY_UMBRELLA; }
    PARAMETRIZE { setupMove = MOVE_RAIN_DANCE; attackingMove = MOVE_EMBER;     heldItem = ITEM_NONE; }
    PARAMETRIZE { setupMove = MOVE_RAIN_DANCE; attackingMove = MOVE_WATER_GUN; heldItem = ITEM_UTILITY_UMBRELLA; }
    PARAMETRIZE { setupMove = MOVE_RAIN_DANCE; attackingMove = MOVE_WATER_GUN; heldItem = ITEM_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(heldItem); };
    } WHEN {
        TURN { MOVE(opponent, setupMove); }
        TURN { MOVE(player, attackingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, attackingMove, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}
