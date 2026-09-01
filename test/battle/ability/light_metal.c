#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Light Metal and Heavy Metal affect the power of Low Kick", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_LIGHT_METAL; } //  10.0 - 24.9 kg  (40 power)
    PARAMETRIZE { ability = ABILITY_STALWART;    } //  25.0 - 49.9 kg  (60 power)
    PARAMETRIZE { ability = ABILITY_HEAVY_METAL; } //  50.0 - 99.9 kg  (80 power)

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        ASSUME(GetMoveArgType(MOVE_SOAK) == TYPE_WATER);
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DURALUDON) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SOAK); } // To remove super-effectiveness, as it was messing with calculations.
        TURN { MOVE(player, MOVE_LOW_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        // Calc 20 power increase, with the first iteration being 40 power
        if (i != 0)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12((i * 0.5) + 1), results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Autotomize applies before Light Metal and Heavy Metal when determining Heat Crash power", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STALWART;    } // 40.0kg -> 0.1kg after Autotomize, ratio 1/1 => 40 BP
    PARAMETRIZE { ability = ABILITY_LIGHT_METAL; } // 40.0kg -> 0.1kg after Autotomize, then halved (min 0.1kg), ratio 1/1 => 40 BP
    PARAMETRIZE { ability = ABILITY_HEAVY_METAL; } // 40.0kg -> 0.1kg after Autotomize, then doubled to 0.2kg, ratio 2/1 => 60 BP

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AUTOTOMIZE) == EFFECT_AUTOTOMIZE);
        ASSUME(GetMoveEffect(MOVE_HEAT_CRASH) == EFFECT_HEAT_CRASH);
        ASSUME(GetSpeciesWeight(SPECIES_DURALUDON) == 400);
        ASSUME(GetSpeciesWeight(SPECIES_GASTLY) == 1);
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_DURALUDON) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_AUTOTOMIZE); }
        TURN { MOVE(opponent, MOVE_HEAT_CRASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAT_CRASH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } THEN {
        if (ability == ABILITY_HEAVY_METAL)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[i].damage);
        else
            EXPECT_EQ(results[0].damage, results[i].damage);
    }
}

WILD_BATTLE_TEST("Light Metal doesn't affect Heavy Ball's multiplier", u32 catchingChance)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_TECHNICIAN;  }
    PARAMETRIZE { ability = ABILITY_LIGHT_METAL; }

    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_SCIZOR) == 1180);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCIZOR) { Ability(ability); }
    } WHEN {
        TURN { USE_ITEM(player, ITEM_HEAVY_BALL); }
    } SCENE {
        CATCHING_CHANCE(&results[i].catchingChance);
    } FINALLY {
        EXPECT_EQ(results[0].catchingChance, results[1].catchingChance);
    }
}

WILD_BATTLE_TEST("Heavy Metal doesn't affect Heavy Ball's multiplier", u32 catchingChance)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_HEATPROOF;   }
    PARAMETRIZE { ability = ABILITY_HEAVY_METAL; }

    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_BRONZONG) == 1870);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRONZONG) { Ability(ability); }
    } WHEN {
        TURN { USE_ITEM(player, ITEM_HEAVY_BALL); }
    } SCENE {
        CATCHING_CHANCE(&results[i].catchingChance);
    } FINALLY {
        EXPECT_EQ(results[0].catchingChance, results[1].catchingChance);
    }
}
