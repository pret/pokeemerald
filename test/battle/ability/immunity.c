#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Immunity prevents Poison Sting poison")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Immunity prevents Toxic bad poison")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        MESSAGE("Wobbuffet used Toxic!");
        ABILITY_POPUP(opponent, ABILITY_IMMUNITY);
        MESSAGE("It doesn't affect the opposing Snorlax…");
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Immunity prevents Toxic Spikes poison")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Immunity doesn't prevent Pokémon from being poisoned by Toxic Spikes on switch-in if forced in by phazing with Mold Breaker, but it cures it immediately")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_IMMUNITY); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        STATUS_ICON(player, STATUS1_POISON);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Immunity cures existing poison on turn 0")
{
    GIVEN {
        PLAYER(SPECIES_ZANGOOSE) {
            Ability(ABILITY_IMMUNITY);
            Status1(STATUS1_POISON);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } SCENE {
        ABILITY_POPUP(player, ABILITY_IMMUNITY);
        TURN { MOVE(player, MOVE_SPLASH); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}
