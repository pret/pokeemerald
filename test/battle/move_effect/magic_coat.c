#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
}

SINGLE_BATTLE_TEST("Magic Coat prints the correct message when bouncing back a move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPORE); }
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("Zigzagoon bounced the Spore back!");
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("Zigzagoon bounced the Spore back!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Magic Coat fails if user moves last")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_MAGIC_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
    }
}

DOUBLE_BATTLE_TEST("Magic Coat fails when the only slower battler is a fainted ally")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_MAGIC_COAT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Wynaut fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Magic Coat reflects hazards regardless of the user's position")
{
    struct BattlePokemon *coatUser = NULL;
    PARAMETRIZE { coatUser = playerLeft; }
    PARAMETRIZE { coatUser = playerRight; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(coatUser, MOVE_MAGIC_COAT); MOVE(opponentRight, MOVE_STEALTH_ROCK); MOVE(opponentLeft, MOVE_SPIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, coatUser);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponentLeft);
        }
    } THEN {
        EXPECT(!IsHazardOnSide(B_SIDE_PLAYER, HAZARDS_STEALTH_ROCK));
        EXPECT(!IsHazardOnSide(B_SIDE_PLAYER, HAZARDS_SPIKES));
        EXPECT(IsHazardOnSide(B_SIDE_OPPONENT, HAZARDS_STEALTH_ROCK));
        EXPECT(IsHazardOnSide(B_SIDE_OPPONENT, HAZARDS_SPIKES));
    }
}

DOUBLE_BATTLE_TEST("Magic Coat activates on the fastest opposing mon for hazard setting moves (raw speed)")
{
    u32 speedPlayerLeft = 0;
    u32 speedPlayerRight = 0;
    PARAMETRIZE { speedPlayerLeft = 2; speedPlayerRight = 1; }
    PARAMETRIZE { speedPlayerLeft = 1; speedPlayerRight = 2; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayerLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedPlayerRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(4); }
    } WHEN {
        TURN {
            if (speedPlayerRight == 2) {
                MOVE(playerRight, MOVE_MAGIC_COAT);
                MOVE(playerLeft, MOVE_MAGIC_COAT);
            } else {
                MOVE(playerLeft, MOVE_MAGIC_COAT);
                MOVE(playerRight, MOVE_MAGIC_COAT);
            }
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_STEALTH_ROCK);
        }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentRight);
        if (speedPlayerRight == 2) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, playerRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, playerRight);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, playerLeft);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, playerRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, playerLeft);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, playerRight);
        }
    }
}

SINGLE_BATTLE_TEST("Magic Coat reflection doesn't activate Protean/Libero")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GRENINJA; ability = ABILITY_PROTEAN; }
    PARAMETRIZE { species = SPECIES_CINDERACE; ability = ABILITY_LIBERO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        ASSUME(GetMoveType(MOVE_MAGIC_COAT) == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_SPIKES) != TYPE_PSYCHIC);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPIKES); }
    } SCENE {
        ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        ONE_OF {
            MESSAGE("Greninja bounced the Spikes back!");
            MESSAGE("Cinderace bounced the Spikes back!");
        }
        NOT ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_PSYCHIC);
        EXPECT_EQ(player->types[1], TYPE_PSYCHIC);
    }
}
