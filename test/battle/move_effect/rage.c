#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rage sets the Rage volatile status on the user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
    }
}

SINGLE_BATTLE_TEST("Rage's volatile causes Attack to rise by 1 when hit by a damaging move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's rage is building!");
    }
}

SINGLE_BATTLE_TEST("Rage volatile is cleared when using a different move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        NOT MESSAGE("Wobbuffet's rage is building!");
    }
}

SINGLE_BATTLE_TEST("Rage does not build Attack from status moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
        NOT MESSAGE("Wobbuffet's rage is building!");
    }
}

SINGLE_BATTLE_TEST("Rage builds Attack multiple times when hit multiple times")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
    }
}

SINGLE_BATTLE_TEST("Rage volatile persists when using Rage again")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
    }
}

SINGLE_BATTLE_TEST("Rage does not build Attack when user's Attack is at max stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        NOT MESSAGE("Wobbuffet's rage is building!");
    }
}

SINGLE_BATTLE_TEST("Rage volatile behavior on Protect depends on generation")
{
    u32 config;
    PARAMETRIZE { config = GEN_3; }
    PARAMETRIZE { config = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_RAGE_BUILDS, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_RAGE); }
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_RAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        if (config == GEN_3) {
            MESSAGE("Wobbuffet's rage is building!");
        } else {
            NOT MESSAGE("Wobbuffet's rage is building!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
    }
}

SINGLE_BATTLE_TEST("Rage volatile behavior on miss depends on generation")
{
    u32 config;
    // PARAMETRIZE { config = GEN_3; }
    PARAMETRIZE { config = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_RAGE_BUILDS, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_RAGE, hit: FALSE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Wobbuffet's rage is building!");
        MESSAGE("The opposing Wobbuffet avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        if (config == GEN_3) {
            MESSAGE("Wobbuffet's rage is building!");
        } else {
            NOT MESSAGE("Wobbuffet's rage is building!");
        }
    }
}
