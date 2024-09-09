#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Restore HP Item effects do not miss timing")
{
    u16 item;

    PARAMETRIZE { item = ITEM_BERRY_JUICE; }
    PARAMETRIZE { item = ITEM_ORAN_BERRY; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_BERRY_JUICE].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { MaxHP(100); HP(51); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        MESSAGE("A sea of fire enveloped the opposing team!");
        MESSAGE("The opposing Foe Wynaut was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("The opposing Foe Wobbuffet was hurt by the sea of fire!");
    }
}
