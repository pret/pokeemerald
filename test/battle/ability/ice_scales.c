#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ice Scales halves the damage from special moves", s16 damage)
{
    u32 move;
    u16 ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; move = MOVE_PSYCHIC; }
    PARAMETRIZE { ability = ABILITY_ICE_SCALES; move = MOVE_PSYCHIC; }
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; move = MOVE_PSYSHOCK; }
    PARAMETRIZE { ability = ABILITY_ICE_SCALES; move = MOVE_PSYSHOCK; }
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; move = MOVE_TACKLE; }
    PARAMETRIZE { ability = ABILITY_ICE_SCALES; move = MOVE_TACKLE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_PSYCHIC].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_PSYSHOCK].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_PSYSHOCK].effect == EFFECT_PSYSHOCK);
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FROSMOTH) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage); // Ice Scales halves the damage of Psychic
        EXPECT_MUL_EQ(results[2].damage, UQ_4_12(0.5), results[3].damage); // Ice Scales halves the damage of Psyshock, even if it targets Defense
        EXPECT_EQ(results[4].damage, results[5].damage); // Ice Scales doesn't affect the damage of physical moves
    }
}
