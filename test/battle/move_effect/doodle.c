#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_DOODLE].effect == EFFECT_DOODLE);
}

DOUBLE_BATTLE_TEST("Doodle gives the target's ability to user and ally")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft);  }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        MESSAGE("Wynaut copied Foe Torchic's Blaze!");
        MESSAGE("Wynaut copied Foe Torchic's Blaze!");
    } THEN {
        EXPECT(playerLeft->ability == ABILITY_BLAZE);
        EXPECT(playerRight->ability == ABILITY_BLAZE);
    }
}

DOUBLE_BATTLE_TEST("Doodle can't copy a banned ability")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft);  }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
            MESSAGE("Wynaut copied Foe Great Tusk's Protosynthesis!");
            MESSAGE("Wynaut copied Foe Great Tusk's Protosynthesis!");
        }
    } THEN {
        EXPECT(playerLeft->ability != ABILITY_PROTOSYNTHESIS);
        EXPECT(playerRight->ability != ABILITY_PROTOSYNTHESIS);
    }
}

DOUBLE_BATTLE_TEST("Doodle fails if user has a banned Ability")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft);  }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(playerLeft->ability == ABILITY_GULP_MISSILE);
        EXPECT(playerRight->ability == ABILITY_SHADOW_TAG);
    }
}

DOUBLE_BATTLE_TEST("Doodle fails if partner has a banned Ability")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_SHADOW_TAG); }
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft);  }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, playerLeft);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(playerLeft->ability == ABILITY_SHADOW_TAG);
        EXPECT(playerRight->ability == ABILITY_GULP_MISSILE);
    }
}

DOUBLE_BATTLE_TEST("Doodle fails if ally's ability can't be suppressed")
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
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DOODLE, target: playerLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DOODLE, opponentLeft);
        MESSAGE("But it failed!");
    }
}
