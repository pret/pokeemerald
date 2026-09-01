#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
    ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
}

SINGLE_BATTLE_TEST("Heatproof halves damage from fire type moves")
{
    s16 damage[2];
    GIVEN {
        PLAYER (SPECIES_WOBBUFFET);
        OPPONENT (SPECIES_BRONZONG) { Ability(ABILITY_HEATPROOF); }
    }
    WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_WORRY_SEED); }
        TURN { MOVE(player, MOVE_EMBER); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        EXPECT_MUL_EQ(damage[0], Q_4_12(2), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Heatproof halves the damage done by burn from 1/8th to 1/16th (Gen1-6) or 1/16th to 1/32nd (Gen 7+)")
{
    u32 config, burnRate;

    PARAMETRIZE { config = GEN_7; burnRate = 32; }
    PARAMETRIZE { config = GEN_6; burnRate = 16; }

    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, config);
        PLAYER (SPECIES_BRONZONG) { Ability(ABILITY_HEATPROOF); Status1(STATUS1_BURN); }
        OPPONENT (SPECIES_WOBBUFFET);
    }
    WHEN {
        TURN {}
    }
    SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        HP_BAR(player, damage: maxHP / burnRate);
    }
}
