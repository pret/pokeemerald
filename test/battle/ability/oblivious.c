#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Oblivious prevents Infatuation")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OBLIVIOUS); Gender(MON_MALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ATTRACT); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_OBLIVIOUS);
        NONE_OF { ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_INFATUATION, player); }
        MESSAGE("It doesn't affect Slowpoke…");
    }
}

SINGLE_BATTLE_TEST("Oblivious prevents Captivate")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CAPTIVATE) == EFFECT_CAPTIVATE);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OBLIVIOUS); Gender(MON_MALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CAPTIVATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_OBLIVIOUS);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
        MESSAGE("It doesn't affect Slowpoke…");
    }
}

SINGLE_BATTLE_TEST("Oblivious prevents Taunt (Gen6+)")
{
    u32 gen = 0;
    PARAMETRIZE { gen = GEN_5; }
    PARAMETRIZE { gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_OBLIVIOUS_TAUNT, gen);
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OBLIVIOUS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); }
        TURN { MOVE(player, MOVE_SPORE, allowed: gen == GEN_6); }
    } SCENE {
        if (gen == GEN_6) {
            NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponent); }
            ABILITY_POPUP(player, ABILITY_OBLIVIOUS);
            MESSAGE("It doesn't affect Slowpoke…");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponent);
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_OBLIVIOUS);
                MESSAGE("It doesn't affect Slowpoke…");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Oblivious doesn't prevent Intimidate (Gen3-7)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_7);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OBLIVIOUS); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_OBLIVIOUS);
            MESSAGE("Slowpoke's Attack was not lowered!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slowpoke's Attack fell!");
    }
}

SINGLE_BATTLE_TEST("Oblivious prevents Intimidate (Gen8+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_8);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OBLIVIOUS); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ABILITY_OBLIVIOUS);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
        MESSAGE("Slowpoke's Attack was not lowered!");
    }
}

SINGLE_BATTLE_TEST("Oblivious cured infatuation should not persist toxic counter after switching")
{
    s16 firstTick, secondTick, postSwitchTick;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_MALE); Status1(STATUS1_TOXIC_POISON); MaxHP(160); HP(160); Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Speed(90); }
        OPPONENT(SPECIES_SLOWPOKE) { Gender(MON_FEMALE); Ability(ABILITY_OBLIVIOUS); Speed(80); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ATTRACT); }
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &firstTick);
        HP_BAR(player, captureDamage: &secondTick);
        HP_BAR(player, captureDamage: &postSwitchTick);
    } THEN {
        EXPECT_EQ(firstTick, 10);
        EXPECT_EQ(secondTick, 20);
        EXPECT_EQ(postSwitchTick, 10);
    }
}

DOUBLE_BATTLE_TEST("Oblivious cures infatuation and Taunt")
{
    GIVEN {
        WITH_CONFIG(B_OBLIVIOUS_TAUNT, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OBLIVIOUS); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Gender(MON_FEMALE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE);
               MOVE(opponentLeft, MOVE_TAUNT, target: playerLeft);
               MOVE(opponentRight, MOVE_ATTRACT, target: playerLeft);
               MOVE(playerRight, MOVE_SKILL_SWAP, target: playerLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_OBLIVIOUS);
        MESSAGE("Wobbuffet got over its infatuation!");
        ABILITY_POPUP(playerLeft, ABILITY_OBLIVIOUS);
        MESSAGE("Wobbuffet shook off the taunt!");
    }
}
