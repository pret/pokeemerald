#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_RELIC_SONG, MOVE_EFFECT_SLEEP) == TRUE);
}

SINGLE_BATTLE_TEST("Relic Song has a 10% chance to put the target to sleep")
{
    PASSES_RANDOMLY(10, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Relic Song is prevented by Soundproof")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SOUNDPROOF);
        MESSAGE("It doesn't affect the opposing Voltorb…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Relic Song will become a Water-type move when used by a Pokémon with the Ability Liquid Voice")
{
    GIVEN {
        PLAYER(SPECIES_VULPIX);
        OPPONENT(SPECIES_POPPLIO) { Ability(ABILITY_LIQUID_VOICE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, opponent);
        HP_BAR(player);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Relic Song is blocked by Throat Chop")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THROAT_CHOP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, opponent);
        HP_BAR(player);
        MESSAGE("The effects of Throat Chop prevent Wobbuffet from using certain moves!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
    }
}
