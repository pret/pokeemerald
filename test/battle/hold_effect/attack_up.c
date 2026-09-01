#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].holdEffect == HOLD_EFFECT_ATTACK_UP);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
}

SINGLE_BATTLE_TEST("Liechi Berry raises the holder's Attack by one stage when HP drops to 1/4 or below")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_SCRATCH) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
                MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
            }
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
        }
    } THEN {
        if (move == MOVE_DRAGON_RAGE)
            EXPECT_EQ(player->statStages[STAT_ATK], 7);
    }
}

SINGLE_BATTLE_TEST("Liechi Berry raises Attack by one stage when HP drops to 1/2 or below if holder has Gluttony")
{
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { MaxHP(80); HP(80); Ability(ABILITY_GLUTTONY); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("The Liechi Berry boosted Bellsprout's Attack!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Liechi Berry raises Attack by one stage when HP drops to 1/4 or below if holder has Ripen")
{
    GIVEN {
        PLAYER(SPECIES_APPLIN) { MaxHP(160); HP(80); Ability(ABILITY_RIPEN); Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("The Liechi Berry sharply boosted Applin's Attack!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}
