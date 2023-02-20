#include "global.h"
#include "test_battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
}

SINGLE_BATTLE_TEST("Download raises Attack if enemy has greater Atk than Sp.Atk", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TRACE; }
    PARAMETRIZE { ability = ABILITY_DOWNLOAD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PORYGON) { Ability(ability); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_DOWNLOAD)
        {
            ABILITY_POPUP(opponent, ABILITY_DOWNLOAD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
