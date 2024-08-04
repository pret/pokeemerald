#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_BELCH].effect == EFFECT_BELCH);
    ASSUME(gMovesInfo[MOVE_MUD_SHOT].type == TYPE_GROUND);
    ASSUME(gItemsInfo[ITEM_SHUCA_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
    ASSUME(gItemsInfo[ITEM_SHUCA_BERRY].holdEffectParam == TYPE_GROUND);
    ASSUME(gItemsInfo[ITEM_SHUCA_BERRY].pocket == POCKET_BERRIES);
    ASSUME(gItemsInfo[ITEM_ORAN_BERRY].pocket == POCKET_BERRIES);
}

AI_SINGLE_BATTLE_TEST("AI: Belch has nonzero score after eating a berry")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_BAYLEEF) { Level(18); Moves(MOVE_MUD_SHOT, MOVE_TACKLE); }
        OPPONENT(SPECIES_PIKACHU) { Level(15); Item(ITEM_SHUCA_BERRY); Moves(MOVE_BELCH, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MUD_SHOT); EXPECT_MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_BELCH);}
    } SCENE {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Belch cannot be used if the user has not eaten a berry")
{
    u16 item = 0;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_ORAN_BERRY; }
    GIVEN {
        PLAYER(SPECIES_SKWOVET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item == ITEM_NONE)
            TURN { MOVE(player, MOVE_BELCH, allowed: FALSE); MOVE(player, MOVE_CELEBRATE); }
        else {
            TURN { MOVE(player, MOVE_STUFF_CHEEKS); }
            TURN { MOVE(player, MOVE_BELCH); }
            TURN { MOVE(player, MOVE_BELCH); }
        }
    } SCENE {
        if (item == ITEM_NONE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
        else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STUFF_CHEEKS, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELCH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELCH, player);
        }
    }
}

TO_DO_BATTLE_TEST("Belch can still be used after switching out");
TO_DO_BATTLE_TEST("Belch can still be used after fainting");
TO_DO_BATTLE_TEST("Belch can still be used after restoring the consumed berry");
