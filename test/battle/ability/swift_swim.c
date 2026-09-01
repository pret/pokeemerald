#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Swift Swim doubles speed if it's raining")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_SWIFT_SWIM); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Swift Swim doesn't double speed if Cloud Nine/Air Lock is on the field")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GOLDUCK; ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_SWIFT_SWIM); Speed(100); }
        OPPONENT(species) { Speed(199); Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Swift Swim doesn't double speed if they have an Utility Umbrella")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_SWIFT_SWIM); Speed(100); Item(ITEM_UTILITY_UMBRELLA); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
