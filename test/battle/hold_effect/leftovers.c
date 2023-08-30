#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    gItems[ITEM_LEFTOVERS].holdEffect == HOLD_EFFECT_LEFTOVERS;
}

SINGLE_BATTLE_TEST("Leftovers recovers 1/16th HP at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); Item(ITEM_LEFTOVERS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet's Leftovers restored its HP a little!");
        HP_BAR(player, damage: -maxHP / 16);
    }
}

SINGLE_BATTLE_TEST("Leftovers does nothing if max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LEFTOVERS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet's Leftovers restored its HP a little!");
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Leftovers does nothing if Heal Block applies")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); Item(ITEM_LEFTOVERS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet's Leftovers restored its HP a little!");
            HP_BAR(player);
        }
    }
}
