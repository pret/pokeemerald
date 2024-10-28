#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_ROLE_PLAY].effect == EFFECT_ROLE_PLAY);
}

SINGLE_BATTLE_TEST("Role Play copies target's ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
    }WHEN {
        TURN { MOVE(player, MOVE_ROLE_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, player);
        ABILITY_POPUP(player, ABILITY_TELEPATHY);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_BLAZE);
        EXPECT_EQ(opponent->ability, ABILITY_BLAZE);
    } 
}

DOUBLE_BATTLE_TEST("Role Play copies target's current ability even if it changed during that turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); }
        OPPONENT(SPECIES_SQUIRTLE) { Ability(ABILITY_TORRENT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROLE_PLAY, target: opponentLeft); MOVE(opponentRight, MOVE_ROLE_PLAY, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_TELEPATHY);
        if (MOVE_ROLE_PLAY == MOVE_DOODLE)
            ABILITY_POPUP(playerRight, ABILITY_BLAZE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, opponentRight);
        ABILITY_POPUP(opponentRight, ABILITY_TORRENT);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_OVERGROW); // Already has ability (Doodle)
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_OVERGROW);
        if (MOVE_ROLE_PLAY == MOVE_DOODLE)
            EXPECT_EQ(playerRight->ability, ABILITY_OVERGROW);
        EXPECT_EQ(opponentLeft->ability, ABILITY_OVERGROW);
        EXPECT_EQ(opponentRight->ability, ABILITY_OVERGROW);
    }
}

SINGLE_BATTLE_TEST("Role Play and Doodle fail if target's ability can't be copied'")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_SHEDINJA; ability = ABILITY_WONDER_GUARD; }
    PARAMETRIZE { species = SPECIES_CASTFORM; ability = ABILITY_FORECAST; }
    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_CHERRIM; ability = ABILITY_FLOWER_GIFT; }
    PARAMETRIZE { species = SPECIES_ZORUA; ability = ABILITY_ILLUSION; }
    PARAMETRIZE { species = SPECIES_DARMANITAN; ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MUK_ALOLA; ability = ABILITY_POWER_OF_ALCHEMY; }
    PARAMETRIZE { species = SPECIES_PASSIMIAN; ability = ABILITY_RECEIVER; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_KOFFING; ability = ABILITY_NEUTRALIZING_GAS; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_COMMANDER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROLE_PLAY); }
        TURN { MOVE(player, MOVE_DOODLE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, player);
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Role Play fails if user's ability can't be suppressed")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_DARMANITAN; ability = ABILITY_ZEN_MODE; }
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
        TURN { MOVE(opponent, MOVE_ROLE_PLAY); }
        TURN { MOVE(opponent, MOVE_DOODLE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, opponent);
        MESSAGE("But it failed!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, opponent);
        MESSAGE("But it failed!");
    }
}
