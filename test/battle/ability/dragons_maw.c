#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dragon's Maw increases Dragon-type move damage", s16 damage)
{
    u32 move;
    u16 ability;

    PARAMETRIZE { move = MOVE_TACKLE; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_TACKLE; ability = ABILITY_DRAGONS_MAW; }
    PARAMETRIZE { move = MOVE_DRAGON_CLAW; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_DRAGON_CLAW; ability = ABILITY_DRAGONS_MAW; }
    PARAMETRIZE { move = MOVE_DRAGON_BREATH; ability = ABILITY_KLUTZ; }
    PARAMETRIZE { move = MOVE_DRAGON_BREATH; ability = ABILITY_DRAGONS_MAW; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].type != TYPE_DRAGON);
        ASSUME(gBattleMoves[MOVE_DRAGON_CLAW].type == TYPE_DRAGON);
        ASSUME(gBattleMoves[MOVE_DRAGON_BREATH].type == TYPE_DRAGON);
        ASSUME(gBattleMoves[MOVE_DRAGON_CLAW].split == SPLIT_PHYSICAL);
        ASSUME(gBattleMoves[MOVE_DRAGON_BREATH].split == SPLIT_SPECIAL);
        PLAYER(SPECIES_REGIDRAGO) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Tackle should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Dragon Claw should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Dragon Breath should be affected
    }
}
