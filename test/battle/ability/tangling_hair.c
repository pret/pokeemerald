#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SCRATCH) == EFFECT_HIT);
    ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
    ASSUME(MoveMakesContact(MOVE_SCRATCH) == TRUE);
}

SINGLE_BATTLE_TEST("Tangling Hair drops opposing mon's speed if ability user got hit by a contact move")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SWIFT) == FALSE);
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_SCRATCH) {
            ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wynaut's Speed fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Tangling Hair does not cause Rocky Helmet miss activation")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ROCKY_HELMET].holdEffect == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); Item(ITEM_ROCKY_HELMET); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wynaut's Speed fell!");
        MESSAGE("The opposing Wynaut was hurt by Dugtrio's Rocky Helmet!");
    }
}

SINGLE_BATTLE_TEST("Tangling Hair Speed stat drop triggers defiant and keeps original attacker/target")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); Item(ITEM_ROCKY_HELMET); }
        OPPONENT(SPECIES_PAWNIARD) { Ability(ABILITY_DEFIANT); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Pawniard's Speed fell!");
        ABILITY_POPUP(opponent, ABILITY_DEFIANT);
        MESSAGE("The opposing Pawniard's Attack rose sharply!");
        MESSAGE("The opposing Pawniard was hurt by Dugtrio's Rocky Helmet!");
    }
}

SINGLE_BATTLE_TEST("Tangling Hair does not activate on confusion damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, TRUE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Tangling Hair does not trigger on Clear Body")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
    }
}

SINGLE_BATTLE_TEST("Tangling Hair will trigger if move is boosted by Sheer Force")
{
    ASSUME(MoveIsAffectedBySheerForce(MOVE_POISON_JAB));
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_POISON_JAB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_JAB, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
    }
}
