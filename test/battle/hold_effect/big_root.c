#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_BIG_ROOT].holdEffect == HOLD_EFFECT_BIG_ROOT);
}

SINGLE_BATTLE_TEST("Big Root increases healing from absorbing moves", s16 damage, s16 heal)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BIG_ROOT; }

    GIVEN {
        PLAYER(SPECIES_XURKITREE) { HP(200); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
        HP_BAR(player, captureDamage: &results[i].heal);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Damage is unaffected
        EXPECT_MUL_EQ(results[0].heal, Q_4_12(1.3), results[1].heal);
    }
}

SINGLE_BATTLE_TEST("Big Root increases the damage restored from Leech Seed, Ingrain and Aqua Ring", s16 heal, s16 damage)
{
    enum Item item;
    enum Move move;

    PARAMETRIZE { item = ITEM_NONE;     move = MOVE_LEECH_SEED; }
    PARAMETRIZE { item = ITEM_BIG_ROOT; move = MOVE_LEECH_SEED; }
    PARAMETRIZE { item = ITEM_NONE;     move = MOVE_INGRAIN;    }
    PARAMETRIZE { item = ITEM_BIG_ROOT; move = MOVE_INGRAIN;    }
    PARAMETRIZE { item = ITEM_NONE;     move = MOVE_AQUA_RING;  }
    PARAMETRIZE { item = ITEM_BIG_ROOT; move = MOVE_AQUA_RING;  }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (move == MOVE_LEECH_SEED)
            HP_BAR(opponent, captureDamage: &results[i].damage);
        HP_BAR(player, captureDamage: &results[i].heal);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Damage is unaffected
        EXPECT_MUL_EQ(results[0].heal, Q_4_12(1.3), results[1].heal);
        EXPECT_MUL_EQ(results[2].heal, Q_4_12(1.3), results[3].heal);
        EXPECT_MUL_EQ(results[4].heal, Q_4_12(1.3), results[5].heal);
    }
}

SINGLE_BATTLE_TEST("Big Root increases damage from absorbing Liquid Ooze", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BIG_ROOT; }

    GIVEN {
        PLAYER(SPECIES_XURKITREE) { HP(200); Item(item); }
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}
