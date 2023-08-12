#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
}

SINGLE_BATTLE_TEST("Tablets of Ruin reduces Attack", s16 damage)
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_TABLETS_OF_RUIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_TABLETS_OF_RUIN) {
            ABILITY_POPUP(player, ABILITY_TABLETS_OF_RUIN);
            MESSAGE("Wobbuffet's Tablets of Ruin weakened the Attack of all surrounding Pokémon!");
        }
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.75), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Tablets of Ruin does not reduce Attack if an opposing mon has the same ability", s16 damage)
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_TABLETS_OF_RUIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TABLETS_OF_RUIN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_TABLETS_OF_RUIN) {
            ABILITY_POPUP(player, ABILITY_TABLETS_OF_RUIN);
            MESSAGE("Wobbuffet's Tablets of Ruin weakened the Attack of all surrounding Pokémon!");
        }
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
