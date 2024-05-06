#include "global.h"
#include "test/battle.h"

// Technically also covers Skill Swap and Doodle since both moves use the same command as Role Play
ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_ROLE_PLAY].effect == EFFECT_ROLE_PLAY);
}

SINGLE_BATTLE_TEST("Role Play fails if target has a banned ability")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_SHEDINJA; ability = ABILITY_WONDER_GUARD; }
    PARAMETRIZE { species = SPECIES_CASTFORM; ability = ABILITY_FORECAST; }
    PARAMETRIZE { species = SPECIES_CHERRIM; ability = ABILITY_FLOWER_GIFT; }
    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_ZORUA; ability = ABILITY_ILLUSION; }
    PARAMETRIZE { species = SPECIES_DARMANITAN; ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { species = SPECIES_DITTO; ability = ABILITY_IMPOSTER; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MUK_ALOLAN; ability = ABILITY_POWER_OF_ALCHEMY; }
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
        TURN { MOVE(player,MOVE_ROLE_PLAY); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Role Play fails if user has a banned ability")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_DARMANITAN; ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_COMMANDER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent,MOVE_ROLE_PLAY); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, opponent);
        MESSAGE("But it failed!");
    }
}
