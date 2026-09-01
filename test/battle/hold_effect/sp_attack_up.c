#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_PETAYA_BERRY].holdEffect == HOLD_EFFECT_SP_ATTACK_UP);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
}

SINGLE_BATTLE_TEST("Petaya Berry raises the holder's Sp. Atk by one stage when HP drops to 1/4 or below")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(160); HP(80); Item(ITEM_PETAYA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_SCRATCH) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
                MESSAGE("The Petaya Berry boosted Wobbuffet's Sp. Atk!");
            }
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
            MESSAGE("The Petaya Berry boosted Wobbuffet's Sp. Atk!");
        }
    } THEN {
        if (move == MOVE_DRAGON_RAGE)
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Petaya Berry raises Sp. Atk by one stage when HP drops to 1/2 or below if holder has Gluttony")
{
    GIVEN {
        PLAYER(SPECIES_BELLSPROUT) { MaxHP(80); HP(80); Ability(ABILITY_GLUTTONY); Item(ITEM_PETAYA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("The Petaya Berry boosted Bellsprout's Sp. Atk!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Petaya Berry raises Sp. Atk by one stage when HP drops to 1/4 or below if holder has Ripen")
{
    GIVEN {
        PLAYER(SPECIES_APPLIN) { MaxHP(160); HP(80); Ability(ABILITY_RIPEN); Item(ITEM_PETAYA_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
        MESSAGE("The Petaya Berry sharply boosted Applin's Sp. Atk!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
    }
}
