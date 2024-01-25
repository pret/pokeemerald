#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_STEEL_BEAM].effect == EFFECT_MAX_HP_50_RECOIL);
}

SINGLE_BATTLE_TEST("Steel Beam causes the user to take damage equal to half of its maximum HP")
{
    s16 recoilDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(opponent);
        HP_BAR(player, captureDamage: &recoilDamage);
    } THEN {
        EXPECT_EQ(player->maxHP / 2, recoilDamage);
    }
}

SINGLE_BATTLE_TEST("Steel Beam hp loss is prevented by Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_CLEFAIRY) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STEEL_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEEL_BEAM, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}
