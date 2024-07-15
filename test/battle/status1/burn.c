#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Burn deals 1/16th damage per turn")
{
    u32 j;
    GIVEN {
        ASSUME(B_BURN_DAMAGE >= GEN_LATEST);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (j = 0; j < 4; j++)
            HP_BAR(player, damage: maxHP / 16);
    }
}

SINGLE_BATTLE_TEST("Burn reduces Attack by 50%", s16 damage)
{
    bool32 burned;
    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { if (burned) Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

AI_SINGLE_BATTLE_TEST("AI avoids Will-o-Wisp when it can not burn target")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_BUIZEL; ability = ABILITY_WATER_VEIL; }
    PARAMETRIZE { species = SPECIES_DEWPIDER; ability = ABILITY_WATER_BUBBLE; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_ARCTIBAX; ability = ABILITY_THERMAL_EXCHANGE; }
    PARAMETRIZE { species = SPECIES_NACLI; ability = ABILITY_PURIFYING_SALT; }
    PARAMETRIZE { species = SPECIES_CHARMANDER; ability = ABILITY_BLAZE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_WILL_O_WISP); }
    } WHEN {
        TURN { SCORE_EQ(opponent, MOVE_CELEBRATE, MOVE_WILL_O_WISP); } // Both get -10
    }
}
