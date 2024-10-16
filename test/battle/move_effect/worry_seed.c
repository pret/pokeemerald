#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_WORRY_SEED].effect == EFFECT_WORRY_SEED);
}

SINGLE_BATTLE_TEST("Worry Seed replaces target's ability with Insomnia")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
    }WHEN {
        TURN { MOVE(player, MOVE_WORRY_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        ABILITY_POPUP(opponent, ABILITY_BLAZE);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_INSOMNIA);
    } 
}

DOUBLE_BATTLE_TEST("Worry Seed fails if the target already has Insomnia")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); }
        OPPONENT(SPECIES_SQUIRTLE) { Ability(ABILITY_TORRENT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WORRY_SEED, target: opponentLeft); MOVE(playerRight, MOVE_WORRY_SEED, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_OVERGROW);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, playerRight);
            ABILITY_POPUP(opponentLeft, ABILITY_INSOMNIA);
        }
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_INSOMNIA);
    }
}

SINGLE_BATTLE_TEST("Worry Seed fails if target has an ability that can't be overwritten")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_COMMANDER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_WORRY_SEED); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        MESSAGE("But it failed!");
    }
}
