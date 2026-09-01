#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_APICOT_BERRY].holdEffect == HOLD_EFFECT_SP_DEFENSE_UP);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
}

SINGLE_BATTLE_TEST("Apicot Berry raises the holder's Sp. Def by one stage when HP drops to 1/4 or below")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_APICOT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_SCRATCH) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
                MESSAGE("The Apicot Berry boosted Wobbuffet's Sp. Def!");
            }
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("The Apicot Berry boosted Wobbuffet's Sp. Def!");
        }
    } THEN {
        if (move == MOVE_DRAGON_RAGE)
            EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Apicot Berry raises Sp. Def by one stage when HP drops to 1/2 or below if holder has Gluttony")
{
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { MaxHP(80); HP(80); Ability(ABILITY_GLUTTONY); Item(ITEM_APICOT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("The Apicot Berry boosted Bellsprout's Sp. Def!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Apicot Berry raises Sp. Def by one stage when HP drops to 1/4 or below if holder has Ripen")
{
    GIVEN {
        PLAYER(SPECIES_APPLIN) { MaxHP(160); HP(80); Ability(ABILITY_RIPEN); Item(ITEM_APICOT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("The Apicot Berry sharply boosted Applin's Sp. Def!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
    }
}
