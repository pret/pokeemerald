#include "global.h"
#include "test/battle.h"

static const u16 sMoveItemTable[][4] =
{
    { TYPE_NORMAL,   MOVE_SCRATCH,         ITEM_CHILAN_BERRY, SPECIES_WOBBUFFET },
    { TYPE_FIGHTING, MOVE_KARATE_CHOP,     ITEM_CHOPLE_BERRY, SPECIES_RAMPARDOS },
    { TYPE_FLYING,   MOVE_WING_ATTACK,     ITEM_COBA_BERRY,   SPECIES_HARIYAMA },
    { TYPE_POISON,   MOVE_POISON_STING,    ITEM_KEBIA_BERRY,  SPECIES_GOGOAT },
    { TYPE_GROUND,   MOVE_MUD_SHOT,        ITEM_SHUCA_BERRY,  SPECIES_RAMPARDOS },
    { TYPE_ROCK,     MOVE_ROCK_THROW,      ITEM_CHARTI_BERRY, SPECIES_CORVISQUIRE },
    { TYPE_BUG,      MOVE_BUG_BITE,        ITEM_TANGA_BERRY,  SPECIES_WOBBUFFET },
    { TYPE_GHOST,    MOVE_SHADOW_PUNCH,    ITEM_KASIB_BERRY,  SPECIES_WOBBUFFET },
    { TYPE_STEEL,    MOVE_METAL_CLAW,      ITEM_BABIRI_BERRY, SPECIES_RAMPARDOS },
    { TYPE_FIRE,     MOVE_EMBER,           ITEM_OCCA_BERRY,   SPECIES_GOGOAT },
    { TYPE_WATER,    MOVE_WATER_GUN,       ITEM_PASSHO_BERRY, SPECIES_RAMPARDOS },
    { TYPE_GRASS,    MOVE_VINE_WHIP,       ITEM_RINDO_BERRY,  SPECIES_RAMPARDOS },
    { TYPE_ELECTRIC, MOVE_THUNDER_SHOCK,   ITEM_WACAN_BERRY,  SPECIES_CORVISQUIRE },
    { TYPE_PSYCHIC,  MOVE_CONFUSION,       ITEM_PAYAPA_BERRY, SPECIES_HARIYAMA },
    { TYPE_ICE,      MOVE_AURORA_BEAM,     ITEM_YACHE_BERRY,  SPECIES_DRAGONAIR },
    { TYPE_DRAGON,   MOVE_DRAGON_BREATH,   ITEM_HABAN_BERRY,  SPECIES_DRAGONAIR },
    { TYPE_DARK,     MOVE_BITE,            ITEM_COLBUR_BERRY, SPECIES_WOBBUFFET },
    { TYPE_FAIRY,    MOVE_DISARMING_VOICE, ITEM_ROSELI_BERRY, SPECIES_DRAGONAIR },
};

SINGLE_BATTLE_TEST("Weakness berries decrease the base power of moves by half", s16 damage)
{
    enum Move move = MOVE_NONE;
    enum Item item = ITEM_NONE;
    u32 defender = 0;
    enum Type type = TYPE_NONE;

    for (u32 j = 0; j < ARRAY_COUNT(sMoveItemTable); j++)
    {
        PARAMETRIZE { type = sMoveItemTable[j][0]; move = sMoveItemTable[j][1]; defender = sMoveItemTable[j][3]; item = ITEM_NONE; }
        PARAMETRIZE { type = sMoveItemTable[j][0]; move = sMoveItemTable[j][1]; defender = sMoveItemTable[j][3]; item = sMoveItemTable[j][2]; }
    }

    GIVEN {
        ASSUME(GetMovePower(move) > 0);
        ASSUME(GetMoveType(move) == type);
        ASSUME(GetSpeciesType(defender, 0) == GetSpeciesType(defender, 1));
        if (type != TYPE_NORMAL) {
            ASSUME(gTypeEffectivenessTable[type][GetSpeciesType(defender, 0)] > UQ_4_12(1.0));
        }
        if (item != ITEM_NONE) {
            ASSUME(GetItemHoldEffect(item) == HOLD_EFFECT_RESIST_BERRY);
            ASSUME(GetItemHoldEffectParam(item) == type);
        }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(defender) { Item(item); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (item != ITEM_NONE) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < ARRAY_COUNT(sMoveItemTable); j++) {
            EXPECT_MUL_EQ(results[j*2].damage, Q_4_12(0.5), results[(j*2)+1].damage); // no resist berry damage * 0.5 = resist berry damage
        }
    }
}

SINGLE_BATTLE_TEST("Weakness berries do not activate unless a move is super effective", s16 damage)
{
    enum Move move = MOVE_NONE;
    enum Item item = ITEM_NONE;
    enum Species defender = SPECIES_NONE;
    enum Type type = TYPE_NONE;

    for (u32 j = 0; j < ARRAY_COUNT(sMoveItemTable); j++)
    {
        if (TYPE_NORMAL == type)
        {
            // ITEM_CHILAN_BERRY activates without a weakness
        }
        else if (TYPE_FAIRY == type)
        {
            PARAMETRIZE { type = sMoveItemTable[j][0]; move = sMoveItemTable[j][1]; item = sMoveItemTable[j][2]; defender = SPECIES_WOBBUFFET; }
        }
        else
        {
            PARAMETRIZE { type = sMoveItemTable[j][0]; move = sMoveItemTable[j][1]; item = sMoveItemTable[j][2]; defender = SPECIES_SABLEYE; }
        }
    }

    GIVEN {
        ASSUME(GetMovePower(move) > 0);
        ASSUME(uq4_12_multiply(gTypeEffectivenessTable[type][GetSpeciesType(defender, 0)],
                gTypeEffectivenessTable[type][GetSpeciesType(defender, 1)]) <= UQ_4_12(1.0));
        ASSUME(GetItemHoldEffect(item) == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(GetItemHoldEffectParam(item) == type);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(defender) { Item(item); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

SINGLE_BATTLE_TEST("Weakness berries do not decrease the power of Struggle", s16 damage)
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHILAN_BERRY; }

    GIVEN {
        if (item != ITEM_NONE) {
            ASSUME(GetItemHoldEffect(item) == HOLD_EFFECT_RESIST_BERRY);
            ASSUME(GetItemHoldEffectParam(item) == TYPE_NORMAL);
        }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The Chilan Berry weakened the damage to the opposing Wobbuffet!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Weakness berries do not activate if Disguise blocks the damage")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_BABIRI_BERRY) == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(GetItemHoldEffectParam(ITEM_BABIRI_BERRY) == TYPE_STEEL);
        ASSUME(GetMoveType(MOVE_METAL_CLAW) == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MIMIKYU) { Item(ITEM_BABIRI_BERRY); Ability(ABILITY_DISGUISE); }
    } WHEN {
        TURN { MOVE(player, MOVE_METAL_CLAW); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The Babiri Berry weakened the damage to the opposing Mimikyu!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_CLAW, player);
    }
}
