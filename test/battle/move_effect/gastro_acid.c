#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_GASTRO_ACID].effect == EFFECT_GASTRO_ACID);
}

SINGLE_BATTLE_TEST("Gastro Acid fails if target has a banned ability")
{
    u32 species, ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI; ability = ABILITY_COMMANDER; }
    // Needs confirmation since those abilities can be surpressed by Neutralizing Gas
    // PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; }
    // PARAMETRIZE { species = SPECIES_WALKING_WAKE; ability = ABILITY_PROTOSYNTHESIS; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW_RIDER; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE_RIDER; ability = ABILITY_AS_ONE_ICE_RIDER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, player);
        MESSAGE("But it failed!");
    }
}

TO_DO_BATTLE_TEST("Baton Pass passes Gastro Acid's effect");
TO_DO_BATTLE_TEST("Baton Pass removes Gastro Acid if its ability cannot be surpressed");
