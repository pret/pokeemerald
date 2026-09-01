#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Toxic Debris sets Toxic Spikes on the opposing side if hit by a physical attack")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }

    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        if (move == MOVE_SCRATCH) {
            ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
                MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Toxic Debris does not activate if two layers of Toxic Spikes are already up")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        }
    }
}

SINGLE_BATTLE_TEST("Toxic Debris does not activate when a Substitute is hit")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        }
    }
}

SINGLE_BATTLE_TEST("Toxic Debris activates on each hit of a multi-hit move")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FURY_SWIPES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
    }
}

SINGLE_BATTLE_TEST("Toxic Debris activates if user faints after physical hit")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { HP(1); Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        MESSAGE("Glimmora fainted!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon is popped after Toxic Debris activates")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        MESSAGE("Glimmora's Air Balloon popped!");
    }
}

DOUBLE_BATTLE_TEST("Toxic Debris sets Toxic Spikes on the opposing side even when hit by an ally")
{
    struct BattlePokemon *user = NULL;

    PARAMETRIZE{ user = opponentLeft; }
    PARAMETRIZE{ user = opponentRight; }
    PARAMETRIZE{ user = playerRight; }
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        PLAYER(SPECIES_WYNAUT) { }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { }
    } WHEN {
        TURN { MOVE(user, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
    }
}

DOUBLE_BATTLE_TEST("Toxic Debris does not activate if two layers of Toxic Spikes are already up on the opposing side of the field")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC_SPIKES), MOVE(playerRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        }
    }
}
