#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
}

SINGLE_BATTLE_TEST("Substitute creates a Substitute at the cost of 1/4 users maximum HP")
{
    s16 maxHP = 0;
    s16 costHP = 0;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        maxHP = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        HP_BAR(player, captureDamage: &costHP);
        MESSAGE("Wobbuffet put in a substitute!");
    }THEN {
        EXPECT_EQ(maxHP / 4, costHP);
    }
}

SINGLE_BATTLE_TEST("Substitute fails if the user doesn't have enough HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        MESSAGE("But it does not have enough HP left to make a substitute!");
    }
}

SINGLE_BATTLE_TEST("Substitute's HP cost can trigger a berry")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(300); Item(ITEM_SITRUS_BERRY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
    }
}

SINGLE_BATTLE_TEST("Substitute's HP cost doesn't trigger effects that trigger on damage taken")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Wobbuffet put in a substitute!");
        NOT MESSAGE("Wobbuffet's Air Balloon popped!");
    }
}

TO_DO_BATTLE_TEST("Baton Pass passes Substitutes");
