#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_SWIFT].category == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Toxic Debris sets Toxic Spikes on the opposing side if hit by a physical attack")
{
    u32 move;

    PARAMETRIZE { move = MOVE_TACKLE;}
    PARAMETRIZE { move = MOVE_SWIFT;}

    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        if (move == MOVE_TACKLE) {
            ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
                MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
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
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        }
    }
}

SINGLE_BATTLE_TEST("If a Substitute is hit, Toxic Debris does not set Toxic Spikes")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
            MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        }
    }
}

SINGLE_BATTLE_TEST("Each hit of a Multi Hit move activates Toxic Debris")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FURY_SWIPES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
    }
}

SINGLE_BATTLE_TEST("Toxic Debris activates if user faints after physical hit")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { HP(1); Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Glimmora fainted!");
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon is popped after Toxic Debris activates")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Poison Spikes were scattered all around the opposing team's feet!");
        MESSAGE("Glimmora's Air Balloon popped!");
    }
}
