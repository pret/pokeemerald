#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Guard Dog raises Attack when intimidated", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_INTIMIDATE; }
    PARAMETRIZE { ability = ABILITY_SHED_SKIN; }
    GIVEN {
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_INTIMIDATE)
        {
            ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
            ABILITY_POPUP(player, ABILITY_GUARD_DOG);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Okidogi's Attack rose!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}
