#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
}

SINGLE_BATTLE_TEST("Gastro Acid fails if target has a banned ability")
{
    enum Species species;
    enum Ability ability;

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
    // Needs confirmation since those abilities can be suppressed by Neutralizing Gas
    // PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; }
    // PARAMETRIZE { species = SPECIES_WALKING_WAKE; ability = ABILITY_PROTOSYNTHESIS; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }

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

SINGLE_BATTLE_TEST("Gastro Acid immediately ends Neutralizing Gas and reactivates suppressed abilities")
{
    GIVEN {
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, player);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(player, ABILITY_DROUGHT);
    }
}

SINGLE_BATTLE_TEST("Baton Pass passes Gastro Acid's effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHIMECHO) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Baton Pass removes Gastro Acid if its ability cannot be surpressed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
    }
}
