#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SKILL_SWAP].effect == EFFECT_SKILL_SWAP);
}

SINGLE_BATTLE_TEST("Skill Swap swaps user and target's abilities")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
    }WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        ABILITY_POPUP(player, ABILITY_TELEPATHY);
        ABILITY_POPUP(opponent, ABILITY_BLAZE);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_BLAZE);
        EXPECT_EQ(opponent->ability, ABILITY_TELEPATHY);
    } 
}

DOUBLE_BATTLE_TEST("Skill Swap only swaps user's ability with target's ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); }
        OPPONENT(SPECIES_SQUIRTLE) { Ability(ABILITY_TORRENT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SKILL_SWAP, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_TELEPATHY);
        ABILITY_POPUP(opponentLeft, ABILITY_OVERGROW);
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_OVERGROW);
        EXPECT_EQ(playerRight->ability, ABILITY_BLAZE);
        EXPECT_EQ(opponentLeft->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(opponentRight->ability, ABILITY_TORRENT);
    }
}

DOUBLE_BATTLE_TEST("Skill Swap doesn't display ability popups when swapping with an ally")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); }
        OPPONENT(SPECIES_SQUIRTLE) { Ability(ABILITY_TORRENT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SKILL_SWAP, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_TELEPATHY);
            ABILITY_POPUP(playerRight, ABILITY_BLAZE);
        }
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_BLAZE);
        EXPECT_EQ(playerRight->ability, ABILITY_TELEPATHY);
    }
}

SINGLE_BATTLE_TEST("Skill Swap fails if user or target has an ability that can't be swapped")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_SHEDINJA; ability = ABILITY_WONDER_GUARD; }
    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_ZORUA; ability = ABILITY_ILLUSION; }
    PARAMETRIZE { species = SPECIES_DARMANITAN; ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_KOFFING; ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { species = SPECIES_MORPEKO; ability = ABILITY_HUNGER_SWITCH; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_COMMANDER; }
    PARAMETRIZE { species = SPECIES_GREAT_TUSK; ability = ABILITY_PROTOSYNTHESIS; }
    PARAMETRIZE { species = SPECIES_IRON_TREADS; ability = ABILITY_QUARK_DRIVE; }
    PARAMETRIZE { species = SPECIES_OGERPON_TEAL_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_TEAL_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE_MASK_TERA; ability = ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK; }
    PARAMETRIZE { species = SPECIES_TERAPAGOS_TERASTAL; ability = ABILITY_TERA_SHELL; }
    PARAMETRIZE { species = SPECIES_TERAPAGOS_STELLAR; ability = ABILITY_TERAFORM_ZERO; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        MESSAGE("But it failed!");
    }
}
