#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
}

SINGLE_BATTLE_TEST("Sword of Ruin reduces Defense", s16 damage)
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_SWORD_OF_RUIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_SWORD_OF_RUIN) {
            ABILITY_POPUP(player, ABILITY_SWORD_OF_RUIN);
            MESSAGE("Wobbuffet's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.33), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Sword of Ruin does not reduce Defense if opposing mon has the same ability", s16 damage)
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_SWORD_OF_RUIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SWORD_OF_RUIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_SWORD_OF_RUIN) {
            ABILITY_POPUP(player, ABILITY_SWORD_OF_RUIN);
            MESSAGE("Wobbuffet's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
