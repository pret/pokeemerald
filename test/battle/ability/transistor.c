#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Transistor increases Electric-type move damage", s16 damage)
{
    u32 move;
    u16 ability;

    PARAMETRIZE { move = MOVE_TACKLE; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_TACKLE; ability = ABILITY_TRANSISTOR; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_WILD_CHARGE; ability = ABILITY_TRANSISTOR; }
    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; ability = ABILITY_TRANSISTOR; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].type != TYPE_ELECTRIC);
        ASSUME(gBattleMoves[MOVE_WILD_CHARGE].type == TYPE_ELECTRIC);
        ASSUME(gBattleMoves[MOVE_THUNDER_SHOCK].type == TYPE_ELECTRIC);
        ASSUME(gBattleMoves[MOVE_WILD_CHARGE].split == SPLIT_PHYSICAL);
        ASSUME(gBattleMoves[MOVE_THUNDER_SHOCK].split == SPLIT_SPECIAL);
        PLAYER(SPECIES_REGIELEKI) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Tackle should be unaffected
    #if B_TRANSISTOR_BOOST >= GEN_9
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(5325 / 4096), results[3].damage); // Wild Charge should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(5325 / 4096), results[5].damage); // Thunder Shock should be affected
    #else
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Wild Charge should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Thunder Shock should be affected
    #endif
    }
}
