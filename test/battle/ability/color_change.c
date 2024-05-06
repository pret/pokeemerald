#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Color Change changes the type of a Pokemon being hit by a move if the type of the move and the Pokemon are different")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("Foe Wobbuffet's Color Change made it the Normal type!");
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type when hit by a move that's the same type as itself")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("Foe Wobbuffet's Color Change made it the Normal type!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type of a dual-type Pokemon when hit by a move that shares its primary type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_XATU) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("Foe Xatu's Color Change made it the Psychic type!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change does not change the type of a dual-type Pokemon when hit by a move that shares its secondary type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWBRO) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
            MESSAGE("Foe Slowbro's Color Change made it the Psychic type!");
        }
    }
}

SINGLE_BATTLE_TEST("Color Change changes the user to Electric type if hit by a move while the opponent is under the effect of Electrify")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_PSYCHO_CUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_CUT, player);
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("Foe Wobbuffet's Color Change made it the Electr type!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type when a Pokemon is hit by Future Sight")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("Foe Snorlax took the Future Sight attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("Foe Snorlax's Color Change made it the Psychc type!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type when a Pokemon is hit by Doom Desire")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOOM_DESIRE); }
        TURN { }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOOM_DESIRE, player);
        MESSAGE("Foe Wobbuffet took the Doom Desire attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("Foe Wobbuffet's Color Change made it the Steel type!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type to Electric when a Pokemon is hit by a forseen attack under the effect of Electrify")
{
    KNOWN_FAILING; // #4471.
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BLASTOISE) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { }
        TURN { MOVE(opponent, MOVE_ELECTRIFY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("Foe Blastoise took the Future Sight attack!");
        MESSAGE("It's super effective!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("Foe Blastoise's Color Change made it the Electr type!");
    }
}

SINGLE_BATTLE_TEST("Color Change changes the type to Normal when a Pokemon is hit by a forseen attack under the effect of Normalize")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NORMALIZE); }
        OPPONENT(SPECIES_BLASTOISE) { Ability(ABILITY_COLOR_CHANGE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("Foe Blastoise took the Future Sight attack!");
        ABILITY_POPUP(opponent, ABILITY_COLOR_CHANGE);
        MESSAGE("Foe Blastoise's Color Change made it the Normal type!");
    }
}
