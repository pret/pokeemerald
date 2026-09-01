#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Minior Core doesn't transform into Minior Meteor on switch-in if it has 1/2 or less health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); HP(50); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_CORE);
    }
}

SINGLE_BATTLE_TEST("Minior Core transforms into Minior Meteor on switch-in if it has more than 1/2 health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); HP(51); MaxHP(101); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}

SINGLE_BATTLE_TEST("Minior Core transforms into Minior Meteor on battle start if it has more than 1/2 health")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); HP(51); MaxHP(101); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}

SINGLE_BATTLE_TEST("Shields Down protects Minior Meteor from status conditions")
{
    enum Species species;
    u32 hp;
    PARAMETRIZE { species = SPECIES_MINIOR_METEOR; hp = 300; }
    PARAMETRIZE { species = SPECIES_MINIOR_CORE; hp = 100; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ABILITY_SHIELDS_DOWN); HP(hp); MaxHP(300); }
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        if (species == SPECIES_MINIOR_METEOR)
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
    } THEN {
        if (species == SPECIES_MINIOR_METEOR)
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
        else
            EXPECT(opponent->status1 & STATUS1_BURN);
    }
}

WILD_BATTLE_TEST("Wild Minior appear in Meteor form without transforming")// To be replaced with WILD_DOUBLE_BATTLE_TEST when that is made possible.
{
    GIVEN {
        PLAYER(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); }
        OPPONENT(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
	    ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
        EXPECT_EQ(player->species, SPECIES_MINIOR_METEOR);
    }
}

SINGLE_BATTLE_TEST("Trainers' Minior appear in Core form")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) 
        OPPONENT(SPECIES_MINIOR_METEOR) { Ability(ABILITY_SHIELDS_DOWN); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SHIELDS_DOWN);
	ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->species, SPECIES_MINIOR_METEOR);
    }
}

