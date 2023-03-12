#include "global.h"
#include "test_battle.h"

// DYNAMAX FEATURES
/*
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamax increases HP and max HP by 1.5x")
{
    GIVEN { // TODO: Dynamax level
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET)
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    }
}
*/
/*
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamax expires after three turns.")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET)
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); } // 1st max move
        TURN { MOVE(player, MOVE_TACKLE); } // 2nd max move
        TURN { MOVE(player, MOVE_TACKLE); } // 3rd max move
    } SCENE {
        int i;
        for (i = 0; i < DYNAMAX_TURNS; ++i) {
            MESSAGE("Wobbuffet used Max Strike!");
            MESSAGE("Foe Wobbuffet used Celebrate!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } FINALLY {
        EXPECT_EQ(player->hp, 80)
        EXPECT_EQ(player->maxHP, 100)
    }
}
*/

// MAX MOVE EFFECTS
SINGLE_BATTLE_TEST("(DYNAMAX) Max Strike lowers single opponent's speed")
{
    GIVEN {
        // Fails?: ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_TACKLE) == MOVE_MAX_STRIKE);
        ASSUME(gBattleMoves[MOVE_MAX_STRIKE].argument == MAX_EFFECT_LOWER_SPEED);
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        // turn 1
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) Max Strike lowers both opponents' speed")
{
    GIVEN {
        // Fails? ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_TACKLE) == MOVE_MAX_STRIKE);
        ASSUME(gBattleMoves[MOVE_MAX_STRIKE].argument == MAX_EFFECT_LOWER_SPEED);
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(79); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(99); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft, dynamax: TRUE); \
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); \
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); \
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
    } SCENE {
        // turn 1
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wobbuffet's speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wobbuffet's speed fell!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Tackle!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Flare sets up sunlight.")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_FLARE].argument == MAX_EFFECT_SUN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Flare!");
        MESSAGE("The sunlight got bright!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SUN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Overgrowth sets up Grassy Terrain.")
{
    KNOWN_FAILING
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_OVERGROWTH].argument == MAX_EFFECT_GRASSY_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(256); HP(128); }
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(256); HP(128); }
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Max Overgrowth!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        //HP_BAR(player, damage: -player->maxHP / 16);
    }
}
