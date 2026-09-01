#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hadron Engine creates Electric Terrain when entering the battle")
{
    GIVEN {
        PLAYER(SPECIES_MIRAIDON) { Ability(ABILITY_HADRON_ENGINE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_HADRON_ENGINE);
        MESSAGE("Miraidon turned the ground into Electric Terrain, energizing its futuristic engine!");
    }
}

SINGLE_BATTLE_TEST("Hadron Engine activates when entering battle on Electric Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIRAIDON) { Ability(ABILITY_HADRON_ENGINE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_HADRON_ENGINE);
        MESSAGE("Miraidon used the Electric Terrain to energize its futuristic engine!");
    }
}

SINGLE_BATTLE_TEST("Hadron Engine announces Electric Terrain before triggering Quark Drive")
{
    GIVEN {
        PLAYER(SPECIES_MIRAIDON) { Ability(ABILITY_HADRON_ENGINE); }
        OPPONENT(SPECIES_IRON_BUNDLE) { Ability(ABILITY_QUARK_DRIVE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_HADRON_ENGINE);
        MESSAGE("Miraidon turned the ground into Electric Terrain, energizing its futuristic engine!");
        ABILITY_POPUP(opponent, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated the opposing Iron Bundle's Quark Drive!");
        MESSAGE("The opposing Iron Bundle's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Hadron Engine boosts the Pokemon's Special Attack on Electric Terrain even if not grounded", s16 damage)
{
    bool32 overrideTerrain, airBalloon;

    PARAMETRIZE { airBalloon = FALSE; overrideTerrain = TRUE; }
    PARAMETRIZE { airBalloon = FALSE; overrideTerrain = FALSE; }
    PARAMETRIZE { airBalloon = TRUE;  overrideTerrain = TRUE; }
    PARAMETRIZE { airBalloon = TRUE;  overrideTerrain = FALSE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        ASSUME(GetMoveCategory(MOVE_POWER_GEM) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_MIRAIDON) { Ability(ABILITY_HADRON_ENGINE); Item(airBalloon ? ITEM_AIR_BALLOON : ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (overrideTerrain)
            TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(player, MOVE_POWER_GEM); }
    } SCENE {
        if (overrideTerrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_GEM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3333), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.3333), results[3].damage);
    }
}
