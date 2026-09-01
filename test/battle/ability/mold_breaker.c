#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mold Breaker cancels damage reduction from Ice Scales", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_FROSMOTH) { Ability(ABILITY_ICE_SCALES); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(0.5), results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Mold Breaker will deactivate if user faints")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_STEEL_BEAM; }
    PARAMETRIZE { move = MOVE_POUND; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STEEL_BEAM) == EFFECT_MAX_HP_50_RECOIL);
        PLAYER(SPECIES_PINSIR) { HP(1); Ability(ABILITY_MOLD_BREAKER); }
        PLAYER(SPECIES_ALTARIA) { Ability(ABILITY_COTTON_DOWN); }
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, move, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_COTTON_DOWN);
        if (move == MOVE_STEEL_BEAM)
            ABILITY_POPUP(opponentLeft, ABILITY_CLEAR_BODY);
        else
            NOT ABILITY_POPUP(opponentLeft, ABILITY_CLEAR_BODY);
    }
}

TO_DO_BATTLE_TEST("TODO: Write more Mold Breaker (Ability) test titles")
