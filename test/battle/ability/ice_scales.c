#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ice Scales halves the damage from special moves", s16 damage)
{
    enum Move move;
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; move = MOVE_PSYCHIC; }
    PARAMETRIZE { ability = ABILITY_ICE_SCALES; move = MOVE_PSYCHIC; }
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; move = MOVE_PSYSHOCK; }
    PARAMETRIZE { ability = ABILITY_ICE_SCALES; move = MOVE_PSYSHOCK; }
    PARAMETRIZE { ability = ABILITY_SHIELD_DUST; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_ICE_SCALES; move = MOVE_SCRATCH; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_PSYSHOCK) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_PSYSHOCK) == EFFECT_PSYSHOCK);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
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
