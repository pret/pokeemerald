#include "global.h"
#include "test/battle.h"

static const u16 sMoveItemTable[][18] =
{
    { TYPE_NORMAL,   MOVE_SCRATCH,         ITEM_SILK_SCARF },
    { TYPE_FIGHTING, MOVE_KARATE_CHOP,     ITEM_BLACK_BELT },
    { TYPE_FLYING,   MOVE_WING_ATTACK,     ITEM_SHARP_BEAK },
    { TYPE_POISON,   MOVE_POISON_STING,    ITEM_POISON_BARB },
    { TYPE_GROUND,   MOVE_MUD_SHOT,        ITEM_SOFT_SAND },
    { TYPE_ROCK,     MOVE_ROCK_THROW,      ITEM_HARD_STONE },
    { TYPE_BUG,      MOVE_BUG_BITE,        ITEM_SILVER_POWDER },
    { TYPE_GHOST,    MOVE_SHADOW_PUNCH,    ITEM_SPELL_TAG },
    { TYPE_STEEL,    MOVE_METAL_CLAW,      ITEM_METAL_COAT },
    { TYPE_FIRE,     MOVE_EMBER,           ITEM_CHARCOAL },
    { TYPE_WATER,    MOVE_WATER_GUN,       ITEM_MYSTIC_WATER },
    { TYPE_GRASS,    MOVE_VINE_WHIP,       ITEM_MIRACLE_SEED },
    { TYPE_ELECTRIC, MOVE_THUNDER_SHOCK,   ITEM_MAGNET },
    { TYPE_PSYCHIC,  MOVE_CONFUSION,       ITEM_TWISTED_SPOON },
    { TYPE_ICE,      MOVE_AURORA_BEAM,     ITEM_NEVER_MELT_ICE },
    { TYPE_DRAGON,   MOVE_DRAGON_BREATH,   ITEM_DRAGON_FANG },
    { TYPE_DARK,     MOVE_BITE,            ITEM_BLACK_GLASSES },
    { TYPE_FAIRY,    MOVE_DISARMING_VOICE, ITEM_FAIRY_FEATHER },
};

SINGLE_BATTLE_TEST("Type-enhancing items increase the base power of moves by 20%", s16 damage)
{
    enum Move move = MOVE_NONE;
    enum Item item = ITEM_NONE;
    enum Type type = TYPE_NONE;

    for (u32 j = 0; j < ARRAY_COUNT(sMoveItemTable); j++) {
        PARAMETRIZE { type = sMoveItemTable[j][0]; move = sMoveItemTable[j][1]; item = ITEM_NONE; }
        PARAMETRIZE { type = sMoveItemTable[j][0]; move = sMoveItemTable[j][1]; item = sMoveItemTable[j][2]; }
    }

    GIVEN {
        ASSUME(GetMovePower(move) > 0);
        if (item != ITEM_NONE) {
            ASSUME(GetItemHoldEffect(item) == HOLD_EFFECT_TYPE_POWER);
            ASSUME(GetItemSecondaryId(item) == type);
        }
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < ARRAY_COUNT(sMoveItemTable); j++) {
            if (I_TYPE_BOOST_POWER >= GEN_4)
                EXPECT_MUL_EQ(results[j*2].damage, Q_4_12(1.2), results[(j*2)+1].damage);
            else
                EXPECT_MUL_EQ(results[j*2].damage, Q_4_12(1.1), results[(j*2)+1].damage);
        }
    }
}

SINGLE_BATTLE_TEST("Type-enhancing items do not increase the power of Struggle", s16 damage)
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_SILK_SCARF; }

    GIVEN {
        if (item != ITEM_NONE) {
            ASSUME(GetItemHoldEffect(item) == HOLD_EFFECT_TYPE_POWER);
            ASSUME(GetItemSecondaryId(item) == GetMoveType(MOVE_STRUGGLE));
        }
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
