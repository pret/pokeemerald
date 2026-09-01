#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Color Change changes the type of a Pokemon being hit by a move if the type of the move and the Pokemon are different")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_PSYCHIC && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_PSYWAVE) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYWAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYWAVE, player);
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("The opposing Kecleon's type changed to Psychic!");
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type when hit by a move that's the same type as itself")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) == TYPE_NORMAL || GetSpeciesType(SPECIES_KECLEON, 1) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("The opposing Kecleon's Color Change made it the Normal type!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type of a dual-type Pokemon when hit by a move that shares its primary type")
{
    GIVEN {
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
        OPPONENT(SPECIES_SLOWBRO);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("The opposing Slowbro's Color Change made it the Psychic type!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type of a dual-type Pokemon when hit by a move that shares its secondary type")
{
    GIVEN {
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
        OPPONENT(SPECIES_SLOWBRO);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("The opposing Slowbro's Color Change made it the Psychic type!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change changes the user to Electric type if hit by a move while the opponent is under the effect of Electrify")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("The opposing Kecleon's type changed to Electric!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type when a Pokemon is hit by Future Sight")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Kecleon took the Future Sight attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("The opposing Kecleon's type changed to Psychic!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type when a Pokemon is hit by Doom Desire")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOOM_DESIRE); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOOM_DESIRE, player);
        MESSAGE("The opposing Kecleon took the Doom Desire attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("The opposing Kecleon's type changed to Steel!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type to Electric when a Pokemon is hit by a forseen attack under the effect of Electrify")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN { MOVE(opponent, MOVE_ELECTRIFY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Kecleon took the Future Sight attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("The opposing Kecleon's type changed to Electric!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type to Normal when a Pokemon is hit by a forseen attack under the effect of Normalize")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NORMALIZE); }
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { MOVE(player, MOVE_SOAK); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("Wobbuffet used Soak!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, player);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        MESSAGE("The opposing Kecleon took the Future Sight attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("The opposing Kecleon's type changed to Normal!");
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type to Normal when a Pokemon is hit by Struggle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SOAK); }
        TURN { MOVE(player, MOVE_STRUGGLE); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, player);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("The opposing Kecleon's type changed to Normal!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change does not activate if move is boosted by Sheer Force (Gen9)")
{
    GIVEN {
        WITH_CONFIG(B_SHEER_FORCE_AGAINST_ABILITIES, GEN_9);
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        NOT ABILITY_POPUP(player, ABILITY_COLOR_CHANGE);
    }
}

SINGLE_BATTLE_TEST("Color Change does activate if move is boosted by Sheer Force (Champions)")
{
    KNOWN_FAILING;
    GIVEN {
        WITH_CONFIG(B_SHEER_FORCE_AGAINST_ABILITIES, GEN_CHAMPIONS);
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_COLOR_CHANGE); }
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        ABILITY_POPUP(player, ABILITY_COLOR_CHANGE);
    }
}
