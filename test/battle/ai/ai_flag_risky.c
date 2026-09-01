#include "global.h"
#include "test/battle.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_RISKY: AI will blindly Mirror Coat against special attackers")
{
    u32 aiRiskyFlag = 0;

    PARAMETRIZE { aiRiskyFlag = 0; }
    PARAMETRIZE { aiRiskyFlag = AI_FLAG_RISKY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIRROR_COAT) == EFFECT_REFLECT_DAMAGE);
        ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_MIRROR_COAT) == (1u << DAMAGE_CATEGORY_SPECIAL));
        ASSUME(GetSpeciesBaseSpAttack(SPECIES_GROVYLE) == 85);
        ASSUME(GetSpeciesBaseAttack(SPECIES_GROVYLE) == 65);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiRiskyFlag);
        PLAYER(SPECIES_GROVYLE) { Level(20); Moves(MOVE_ENERGY_BALL); }
        OPPONENT(SPECIES_CASTFORM) { Level(20); Moves(MOVE_SCRATCH, MOVE_MIRROR_COAT); }
    } WHEN {
            TURN { MOVE(player, MOVE_ENERGY_BALL) ; EXPECT_MOVE(opponent, aiRiskyFlag ? MOVE_MIRROR_COAT : MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RISKY: AI will blindly Counter against physical attackers")
{
    u32 aiRiskyFlag = 0;

    PARAMETRIZE { aiRiskyFlag = 0; }
    PARAMETRIZE { aiRiskyFlag = AI_FLAG_RISKY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_COUNTER) == EFFECT_REFLECT_DAMAGE);
        ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_COUNTER) == (1u << DAMAGE_CATEGORY_PHYSICAL));
        ASSUME(GetSpeciesBaseAttack(SPECIES_MARSHTOMP) == 85);
        ASSUME(GetSpeciesBaseSpAttack(SPECIES_MARSHTOMP) == 60);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiRiskyFlag);
        PLAYER(SPECIES_MARSHTOMP) { Level(20); Moves(MOVE_WATERFALL); }
        OPPONENT(SPECIES_CASTFORM) { Level(20); Moves(MOVE_SCRATCH, MOVE_COUNTER); }
    } WHEN {
            TURN { MOVE(player, MOVE_WATERFALL) ; EXPECT_MOVE(opponent, aiRiskyFlag ? MOVE_COUNTER : MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RISKY: AI will prioritize Revenge if slower")
{
    u32 aiRiskyFlag = 0;

    PARAMETRIZE { aiRiskyFlag = 0; }
    PARAMETRIZE { aiRiskyFlag = AI_FLAG_RISKY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REVENGE) == EFFECT_REVENGE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiRiskyFlag);
        PLAYER(SPECIES_GROVYLE) { Level(20); Speed(4); Moves(MOVE_ENERGY_BALL); }
        OPPONENT(SPECIES_CASTFORM) { Level(19); Speed(3); Moves(MOVE_SCRATCH, MOVE_REVENGE); }
    } WHEN {
            TURN { MOVE(player, MOVE_ENERGY_BALL) ; EXPECT_MOVE(opponent, aiRiskyFlag ? MOVE_REVENGE : MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RISKY: Mid-battle switches prioritize offensive options")
{
    u32 aiRiskyFlag = 0;

    PARAMETRIZE { aiRiskyFlag = 0; }
    PARAMETRIZE { aiRiskyFlag = AI_FLAG_RISKY; }

    GIVEN {
        ASSUME(P_UPDATED_STATS >= GEN_7); // Swellow's 50 Sp.Atk in Gen 6 instead of the current 75 causes the AI to switch to Electrode
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT | aiRiskyFlag);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_NONE); Speed(4); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_HEADBUTT); Speed(4); SpDefense(60); } // Mid battle, AI sends out Aron
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Moves(MOVE_CHARGE_BEAM); Speed(6); Ability(ABILITY_STATIC); }
    } WHEN {
        TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SWITCH(opponent, aiRiskyFlag? 2 : 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RISKY | AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE: AI prefers high damage moves at the expense of accuracy regardless of KO thresholds")
{
    u32 aiRiskyFlag = 0;

    PARAMETRIZE { aiRiskyFlag = 0; }
    PARAMETRIZE { aiRiskyFlag = AI_FLAG_RISKY; }
    PARAMETRIZE { aiRiskyFlag = AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiRiskyFlag);
        PLAYER(SPECIES_PSYDUCK) { Level(5); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_CASTFORM) { Level(20); Moves(MOVE_THUNDER, MOVE_THUNDERBOLT); }
    } WHEN {
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, aiRiskyFlag ? MOVE_THUNDER : MOVE_THUNDERBOLT); }
    }
}
