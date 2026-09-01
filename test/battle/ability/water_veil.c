#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Water Veil (Ability) test titles")

SINGLE_BATTLE_TEST("Water Veil lets Rawst and Lum Berries cure Mold Breaker burns first")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_RAWST_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(gItemsInfo[ITEM_RAWST_BERRY].holdEffect == HOLD_EFFECT_CURE_BRN);
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_BUIZEL) { Ability(ABILITY_WATER_VEIL); Item(item); }
        OPPONENT(SPECIES_VELUZA) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, opponent);
        STATUS_ICON(player, burn: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        STATUS_ICON(player, burn: FALSE);
        NOT ABILITY_POPUP(player, ABILITY_WATER_VEIL);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}
