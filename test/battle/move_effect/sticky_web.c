#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_STICKY_WEB].effect == EFFECT_STICKY_WEB);
}

SINGLE_BATTLE_TEST("Sticky Web lowers Speed by 1 on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        MESSAGE("A sticky web spreads out on the ground around the opposing team!");
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("Foe Wynaut was caught in a Sticky Web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wynaut's Speed fell!");
    }
}

SINGLE_BATTLE_TEST("Sticky Web can only be set up 1 time")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { MOVE(player, MOVE_STICKY_WEB); }
    } SCENE {
        MESSAGE("Wobbuffet used Sticky Web!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        MESSAGE("A sticky web spreads out on the ground around the opposing team!");

        MESSAGE("Wobbuffet used Sticky Web!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        MESSAGE("But it failed!");
    }
}


DOUBLE_BATTLE_TEST("Sticky Web lowers Speed by 1 in a double battle after Explosion fainting both mons")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET) {Speed(5);}
        PLAYER(SPECIES_WOBBUFFET) {HP(1500); Speed(10);}
        PLAYER(SPECIES_WOBBUFFET) {Speed(10);}
        OPPONENT(SPECIES_WOBBUFFET) {HP(1); Speed(1);}
        OPPONENT(SPECIES_WOBBUFFET) {HP(1); Speed(1);}
        OPPONENT(SPECIES_WYNAUT) {Speed(10);}
        OPPONENT(SPECIES_ALAKAZAM) {Speed(100);}
    } WHEN {
        TURN { MOVE(playerRight, MOVE_STICKY_WEB); MOVE(playerLeft, MOVE_EXPLOSION); SEND_OUT(playerLeft, 2); SEND_OUT(opponentLeft, 2); SEND_OUT(opponentRight, 3); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, playerRight);
        MESSAGE("A sticky web spreads out on the ground around the opposing team!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        MESSAGE("2 sent out Wynaut!");
        MESSAGE("2 sent out Alakazam!");
        MESSAGE("Foe Alakazam was caught in a Sticky Web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Alakazam's Speed fell!");
        MESSAGE("Foe Wynaut was caught in a Sticky Web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wynaut's Speed fell!");
    }
}

SINGLE_BATTLE_TEST("Sticky Web raises Speed by 1 for a Pokemon with Contrary")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SHUCKLE) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, player);
        MESSAGE("A sticky web spreads out on the ground around the opposing team!");
        MESSAGE("2 sent out Shuckle!");
        MESSAGE("Foe Shuckle was caught in a Sticky Web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Shuckle's Speed rose!");
    }
}

#define BATTLER_OPPONENT (opponentSetUpper == 0 ? opponentLeft : opponentRight)
#define BATTLER_PLAYER (playerSetUpper == 0 ? playerLeft : playerRight)

DOUBLE_BATTLE_TEST("Sticky Web has correct interactions with Mirror Armor - the battler which set up Sticky Web has its Speed lowered instead")
{
    u8 playerSetUpper, opponentSetUpper; // 0 left, 1 right

    PARAMETRIZE {playerSetUpper = 0; opponentSetUpper = 0; }
    PARAMETRIZE {playerSetUpper = 0; opponentSetUpper = 1; }
    PARAMETRIZE {playerSetUpper = 1; opponentSetUpper = 0; }
    PARAMETRIZE {playerSetUpper = 1; opponentSetUpper = 1; }

    GIVEN {
        PLAYER(SPECIES_SQUIRTLE);
        PLAYER(SPECIES_CHARMANDER);
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); Item(ITEM_IRON_BALL); } // Iron Ball, so that flying type Corviknight is affected by Sticky Web.
        OPPONENT(SPECIES_CATERPIE);
        OPPONENT(SPECIES_WEEDLE);
    } WHEN {
        TURN { MOVE(BATTLER_OPPONENT, MOVE_STICKY_WEB); }
        TURN { MOVE(BATTLER_PLAYER, MOVE_STICKY_WEB); }
        TURN { SWITCH(playerRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, BATTLER_OPPONENT);
        MESSAGE("A sticky web spreads out on the ground around your team!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, BATTLER_PLAYER);
        MESSAGE("A sticky web spreads out on the ground around the opposing team!");

        SEND_IN_MESSAGE("Corviknight");
        MESSAGE("Corviknight was caught in a Sticky Web!");
        ABILITY_POPUP(playerRight, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, BATTLER_OPPONENT);
        if (opponentSetUpper == 0) {
            MESSAGE("Foe Caterpie's Speed fell!");
            NONE_OF {
                MESSAGE("Foe Caterpie was caught in a Sticky Web!");
            }
        } else {
            MESSAGE("Foe Weedle's Speed fell!");
            NONE_OF {
                MESSAGE("Foe Weedle was caught in a Sticky Web!");
            }
        }
    }
}

#undef BATTLER_OPPONENT
#undef BATTLER_PLAYER

DOUBLE_BATTLE_TEST("Sticky Web has correct interactions with Mirror Armor - no one has their Speed lowered if the set upper switched")
{
    u16 speedPlayer, speedOpponent;

    // We need to make sure Sticky Web user saves for both sides, so it doesn't matter who sets it first.
    PARAMETRIZE { speedPlayer = 5; speedOpponent = 10; }
    PARAMETRIZE { speedPlayer = 10; speedOpponent = 5; }

    GIVEN {
        PLAYER(SPECIES_SQUIRTLE) { Speed(speedPlayer); }
        PLAYER(SPECIES_CHARMANDER) { Speed(speedPlayer); }
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); Item(ITEM_IRON_BALL); Speed(speedOpponent); } // Iron Ball, so that flying type Corviknight is affected by Sticky Web.
        OPPONENT(SPECIES_CATERPIE) { Speed(speedOpponent); }
        OPPONENT(SPECIES_WEEDLE) { Speed(speedOpponent); }
        OPPONENT(SPECIES_PIDGEY) { Speed(speedOpponent); } // Flying type,so not affected by Sticky Web.
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STICKY_WEB); MOVE(playerRight, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponentLeft, 2); }
        TURN { SWITCH(playerRight, 2); }
    } SCENE {
        if (speedPlayer > speedOpponent) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, playerRight);
            MESSAGE("A sticky web spreads out on the ground around the opposing team!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentLeft);
            MESSAGE("A sticky web spreads out on the ground around your team!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentLeft);
            MESSAGE("A sticky web spreads out on the ground around your team!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, playerRight);
            MESSAGE("A sticky web spreads out on the ground around the opposing team!");
        }

        SEND_IN_MESSAGE("Corviknight");
        MESSAGE("Corviknight was caught in a Sticky Web!");
        ABILITY_POPUP(playerRight, ABILITY_MIRROR_ARMOR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Sticky Web has correct interactions with Mirror Armor - no one has their Speed lowered if the set upper fainted")
{
    bool8 hasReplacement;

    // We need to make sure Sticky Web user saves for both sides, so it doesn't matter who sets it first.
    PARAMETRIZE {hasReplacement = TRUE;}
    PARAMETRIZE {hasReplacement = FALSE;}

    GIVEN {
        ASSUME(gMovesInfo[MOVE_MEMENTO].effect == EFFECT_MEMENTO);
        PLAYER(SPECIES_SQUIRTLE) {Speed(5); }
        PLAYER(SPECIES_CHARMANDER) {Speed(5); }
        PLAYER(SPECIES_CORVIKNIGHT) {Ability(ABILITY_MIRROR_ARMOR); Item(ITEM_IRON_BALL); Speed(5); } // Iron Ball, so that flying type Corviknight is affected by Sticky Web.
        OPPONENT(SPECIES_CATERPIE) {Speed(7); }
        OPPONENT(SPECIES_WEEDLE) {Speed(7); }
        if (hasReplacement) {
            OPPONENT(SPECIES_PIDGEY) {Speed(7); }
        }

    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STICKY_WEB); }
        if (hasReplacement) {
            TURN { MOVE(opponentLeft, MOVE_MEMENTO, target:playerLeft); SEND_OUT(opponentLeft, 2); }
        } else {
            TURN { MOVE(opponentLeft, MOVE_MEMENTO, target:playerLeft);}
        }
        TURN { SWITCH(playerRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentLeft);
        MESSAGE("A sticky web spreads out on the ground around your team!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponentLeft);
        MESSAGE("Foe Caterpie fainted!");
        if (hasReplacement) {
            MESSAGE("2 sent out Pidgey!");
        }

        SEND_IN_MESSAGE("Corviknight");
        MESSAGE("Corviknight was caught in a Sticky Web!");
        ABILITY_POPUP(playerRight, ABILITY_MIRROR_ARMOR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    } THEN {
        if (hasReplacement) {
            EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        }
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}
SINGLE_BATTLE_TEST("Sticky Web is placed on the correct side after Explosion")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); MOVE(opponent, MOVE_STICKY_WEB); SEND_OUT(player, 1);}
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        MESSAGE("Wobbuffet fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        MESSAGE("A sticky web spreads out on the ground around your team!");
   }
}

SINGLE_BATTLE_TEST("Sticky Web is placed on the correct side after Memento")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MEMENTO); MOVE(opponent, MOVE_STICKY_WEB); SEND_OUT(player, 1); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, player);
        MESSAGE("Wobbuffet fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        MESSAGE("A sticky web spreads out on the ground around your team!");
    }
}
