#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Chlorophyll doubles speed if it's sunny")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Ability(ABILITY_CHLOROPHYLL); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Chlorophyll doesn't double speed if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Ability(ABILITY_CHLOROPHYLL); Speed(100); }
        OPPONENT(SPECIES_GOLDUCK) { Speed(199); Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SUNNY_DAY); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Chlorophyll doesn't double speed if they have an Utility Umbrella")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        PLAYER(SPECIES_VENUSAUR) { Ability(ABILITY_CHLOROPHYLL); Speed(100); Item(ITEM_UTILITY_UMBRELLA); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(199); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SUNNY_DAY); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
