#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_RAPID_SPIN));
    ASSUME(MoveMakesContact(MOVE_MORTAL_SPIN));
    ASSUME(GetMoveEffect(MOVE_RAPID_SPIN) == EFFECT_RAPID_SPIN);
    ASSUME(GetMoveEffect(MOVE_MORTAL_SPIN) == EFFECT_RAPID_SPIN);
}

SINGLE_BATTLE_TEST("Rapid Spin activates after Toxic Debris")
{
    GIVEN {
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("The toxic spikes disappeared from the ground around the opposing side!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin blows away Wrap, hazards and raises Speed (Gen 8+)")
{
    GIVEN {
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_RAPID_SPIN, self: TRUE, speed: 1);
        #endif
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);
    #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    #endif
        MESSAGE("Wobbuffet was freed from Wrap!");
        MESSAGE("The pointed stones disappeared from your side!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin: Mortal Spin blows away Wrap, hazards and poisons foe")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, player);
        MESSAGE("The opposing Wobbuffet was poisoned!");
        STATUS_ICON(opponent, poison: TRUE);
        MESSAGE("Wobbuffet was freed from Wrap!");
        MESSAGE("The pointed stones disappeared from your side!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin blows away all hazards")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_SPIKES); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);

        MESSAGE("The spikes disappeared from the ground around your side!");
        MESSAGE("The sticky web has disappeared from the ground on your side!");
        MESSAGE("The toxic spikes disappeared from the ground around your side!");
        MESSAGE("The pointed stones disappeared from your side!");
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);
    }
}

TO_DO_BATTLE_TEST("Rapid Spin blows away Wrap, hazards, but doesn't raise Speed when Sheer Force boosted (Gen 8)");

SINGLE_BATTLE_TEST("Rapid Spin doesn't blow away Wrap, hazards or raise Speed when Sheer Force boosted (Gen 9+)")
{
    GIVEN {
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_RAPID_SPIN, self: TRUE, speed: 1);
        #endif
        PLAYER(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);
        NONE_OF {
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Tauros's Speed rose!");
        #endif
            MESSAGE("Tauros was freed from Wrap!");
            MESSAGE("The pointed stones disappeared from your side!");
        }
    }
}

SINGLE_BATTLE_TEST("Rapid Spin and Mortal Spin will remove hazards if the target is behind a Substitute")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); }
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, move); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        SUB_HIT(player);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Rapid Spin and Mortal Spin remove Leech Seed")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEECH_SEED); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("Wobbuffet was freed from Leech Seed!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin and Mortal Spin don't remove hazards if the user faints (Gen9)")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }

    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_9);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_GARCHOMP) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        NONE_OF {
            MESSAGE("The pointed stones disappeared from around your team!");
        }
    }
}

SINGLE_BATTLE_TEST("Rapid Spin and Mortal Spin remove hazards even if the user faints (Champions)")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }

    GIVEN {
        WITH_CONFIG(B_FAINT_MOVE_EFFECT_TIMING, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_GARCHOMP) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        MESSAGE("The pointed stones disappeared from your side!");
    }
}
