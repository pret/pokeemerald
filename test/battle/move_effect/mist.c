#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mist prevents stat reductions from opposing moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIST) == EFFECT_MIST);
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIST); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, player);
        MESSAGE("Wobbuffet surrounds itself with a protective mist!");
        MESSAGE("The opposing Wobbuffet used Growl!");
        MESSAGE("Wobbuffet is protected by the mist!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mist's protection considers Contrary") // Eg. If a move would reduce stats due to Contrary, it will be protected by Mist.
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIST) == EFFECT_MIST);
        ASSUME(GetMoveEffect(MOVE_SWAGGER) == EFFECT_SWAGGER);
        PLAYER(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIST); MOVE(opponent, MOVE_SWAGGER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, player);
        MESSAGE("Snivy surrounds itself with a protective mist!");
        MESSAGE("The opposing Wobbuffet used Swagger!");
        MESSAGE("Snivy is protected by the mist!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("Snivy became confused!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}
