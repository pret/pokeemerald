#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI gets baited by Protect Switch tactics") // This behavior is to be fixed.
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_STUNFISK);
        PLAYER(SPECIES_PELIPPER);
        OPPONENT(SPECIES_DARKRAI) { Moves(MOVE_TACKLE, MOVE_PECK, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_SCIZOR) { Moves(MOVE_HYPER_BEAM, MOVE_FACADE, MOVE_GIGA_IMPACT, MOVE_EXTREME_SPEED); }
    } WHEN {

        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); } // E-quake
        TURN { SWITCH(player, 1);           EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); } // E-quake
        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); } // T-Bolt
        TURN { SWITCH(player, 0);           EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); } // T-Bolt
        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); } // E-quake
        TURN { SWITCH(player, 1);           EXPECT_MOVE(opponent, MOVE_EARTHQUAKE);} // E-quake
        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); } // T-Bolt
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers Bubble over Water Gun if it's slower")
{
    u32 speedPlayer, speedAi;

    PARAMETRIZE { speedPlayer = 200; speedAi = 10; }
    PARAMETRIZE { speedPlayer = 10; speedAi = 200; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SCIZOR) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_WATER_GUN, MOVE_BUBBLE); Speed(speedAi); }
    } WHEN {
        if (speedPlayer > speedAi)
        {
            TURN { SCORE_GT(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); }
            TURN { SCORE_GT(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); }
        }
        else
        {
            TURN { SCORE_EQ(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); }
            TURN { SCORE_EQ(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers Water Gun over Bubble if it knows that foe has Contrary")
{
    u32 abilityAI;

    PARAMETRIZE { abilityAI = ABILITY_MOXIE; }
    PARAMETRIZE { abilityAI = ABILITY_MOLD_BREAKER; } // Mold Breaker ignores Contrary.

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SHUCKLE) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_PINSIR) { Moves(MOVE_WATER_GUN, MOVE_BUBBLE); Ability(abilityAI); }
    } WHEN {
            TURN { MOVE(player, MOVE_DEFENSE_CURL); }
            TURN { MOVE(player, MOVE_DEFENSE_CURL);
                   if (abilityAI == ABILITY_MOLD_BREAKER) { SCORE_EQ(opponent, MOVE_WATER_GUN, MOVE_BUBBLE); }
                   else { SCORE_GT(opponent, MOVE_WATER_GUN, MOVE_BUBBLE); }}
    } SCENE {
        MESSAGE("Shuckle's Defense fell!"); // Contrary activates
    } THEN {
        EXPECT(gBattleResources->aiData->abilities[B_POSITION_PLAYER_LEFT] == ABILITY_CONTRARY);
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers moves with better accuracy, but only if they both require the same number of hits to ko")
{
    u16 move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    u16 hp, expectedMove, turns, abilityAtk, expectedMove2;

    abilityAtk = ABILITY_NONE;
    expectedMove2 = MOVE_NONE;

    // Here it's a simple test, both Slam and Strength deal the same damage, but Strength always hits, whereas Slam often misses.
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_TACKLE; hp = 490; expectedMove = MOVE_STRENGTH; turns = 4; }
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_TACKLE; hp = 365; expectedMove = MOVE_STRENGTH; turns = 3; }
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_TACKLE; hp = 245; expectedMove = MOVE_STRENGTH; turns = 2; }
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_TACKLE; hp = 125; expectedMove = MOVE_STRENGTH; turns = 1; }
    // Mega Kick deals more damage, but can miss more often. Here, AI should choose Mega Kick if it can faint target in less number of turns than Strength. Otherwise, it should use Strength.
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_TACKLE; hp = 170; expectedMove = MOVE_MEGA_KICK; turns = 1; }
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_TACKLE; hp = 245; expectedMove = MOVE_STRENGTH; turns = 2; }
    // Swift always hits and Guts has accuracy of 100%. Hustle lowers accuracy of all physical moves.
    PARAMETRIZE { abilityAtk = ABILITY_HUSTLE; move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_TACKLE; hp = 5; expectedMove = MOVE_SWIFT; turns = 1; }
    PARAMETRIZE { abilityAtk = ABILITY_HUSTLE; move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_GUST; move4 = MOVE_TACKLE; hp = 5; expectedMove = MOVE_GUST; turns = 1; }
    // Mega Kick and Slam both have lower accuracy. Gust and Tackle both have 100, so AI can choose either of them.
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_SLAM; move3 = MOVE_TACKLE; move4 = MOVE_GUST; hp = 5; expectedMove = MOVE_GUST; expectedMove2 = MOVE_TACKLE; turns = 1; }
    // All moves hit with No guard ability
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_GUST; hp = 5; expectedMove = MOVE_MEGA_KICK; expectedMove2 = MOVE_GUST; turns = 1; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); }
        PLAYER(SPECIES_WOBBUFFET);
        ASSUME(gBattleMoves[MOVE_SWIFT].accuracy == 0);
        ASSUME(gBattleMoves[MOVE_SLAM].power == gBattleMoves[MOVE_STRENGTH].power);
        ASSUME(gBattleMoves[MOVE_MEGA_KICK].power > gBattleMoves[MOVE_STRENGTH].power);
        ASSUME(gBattleMoves[MOVE_SLAM].accuracy < gBattleMoves[MOVE_STRENGTH].accuracy);
        ASSUME(gBattleMoves[MOVE_MEGA_KICK].accuracy < gBattleMoves[MOVE_STRENGTH].accuracy);
        ASSUME(gBattleMoves[MOVE_TACKLE].accuracy == 100);
        ASSUME(gBattleMoves[MOVE_GUST].accuracy == 100);
        OPPONENT(SPECIES_EXPLOUD) { Moves(move1, move2, move3, move4); Ability(abilityAtk); SpAttack(50); } // Low Sp.Atk, so Swift deals less damage than Strength.
    } WHEN {
            switch (turns)
            {
            case 1:
                if (expectedMove2 != MOVE_NONE) {
                    TURN { EXPECT_MOVES(opponent, expectedMove, expectedMove2); SEND_OUT(player, 1); }
                }
                else {
                    TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                }
                break;
            case 2:
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                break;
            case 3:
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                break;
            case 4:
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                break;
            }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers moves which deal more damage instead of moves which are super-effective but deal less damage")
{
    u8 turns = 0;
    u16 move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    u16 expectedMove, abilityAtk, abilityDef, expectedMove2;

    abilityAtk = ABILITY_NONE;
    expectedMove2 = MOVE_NONE;

    // Scald and Poison Jab take 3 hits, Waterfall takes 2.
    PARAMETRIZE { move1 = MOVE_WATERFALL; move2 = MOVE_SCALD; move3 = MOVE_POISON_JAB; move4 = MOVE_WATER_GUN; expectedMove = MOVE_WATERFALL; turns = 2; }
    // Poison Jab takes 3 hits, Water gun 5. Immunity so there's no poison chip damage.
    PARAMETRIZE { move1 = MOVE_POISON_JAB; move2 = MOVE_WATER_GUN; expectedMove = MOVE_POISON_JAB; abilityDef = ABILITY_IMMUNITY; turns = 3; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_TYPHLOSION) { Ability(abilityDef); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDOQUEEN) { Moves(move1, move2, move3, move4); Ability(abilityAtk); }
    } WHEN {
            switch (turns)
            {
            case 2:
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                break;
            case 3:
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); }
                TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                break;
            }
    } SCENE {
        MESSAGE("Typhlosion fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers Earthquake over Drill Run if both require the same number of hits to ko")
{
    // Drill Run has less accuracy than E-quake, but can score a higher crit. However the chance is too small, so AI should ignore it.
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_TYPHLOSION);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_EARTHQUAKE, MOVE_DRILL_RUN); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); SEND_OUT(player, 1); }
    }
    SCENE {
        MESSAGE("Typhlosion fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI chooses the safest option to faint the target, taking into account accuracy and move effect")
{
    u16 move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    u16 expectedMove, abilityAtk = ABILITY_NONE, abilityDef;
    u16 expectedMove2 = MOVE_NONE;

    // Psychic is not very effective, but always hits. Solarbeam requires a charging turn, Double Edge has recoil and Focus Blast can miss;
    PARAMETRIZE { abilityAtk = ABILITY_STURDY; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE; expectedMove = MOVE_PSYCHIC; }
    // Same as above, but ai mon has rock head ability, so it can use Double Edge without taking recoil damage. Psychic can also lower Special Defense,
    // but because it faints the target it doesn't matter.
    PARAMETRIZE { abilityAtk = ABILITY_ROCK_HEAD; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE;
                  expectedMove = MOVE_PSYCHIC; expectedMove2 = MOVE_DOUBLE_EDGE; }
    // This time it's Solarbeam + Psychic, because the weather is sunny.
    PARAMETRIZE { abilityAtk = ABILITY_DROUGHT; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE;
                  expectedMove = MOVE_PSYCHIC; expectedMove2 = MOVE_SOLAR_BEAM; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(5); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GEODUDE) { Moves(move1, move2, move3, move4); Ability(abilityAtk); }
    } WHEN {
        TURN {  if (expectedMove2 == MOVE_NONE) { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                else {EXPECT_MOVES(opponent, expectedMove, expectedMove2); SCORE_EQ(opponent, expectedMove, expectedMove2); SEND_OUT(player, 1);}
             }
    }
    SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use ground type attacks against flying type Pokemon unless Gravity is in effect")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_CROBAT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDOQUEEN) { Moves(MOVE_EARTHQUAKE, MOVE_TACKLE, MOVE_POISON_STING, MOVE_GUST); }
    } WHEN {
            TURN { NOT_EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
            TURN { MOVE(player, MOVE_GRAVITY); NOT_EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
            TURN { EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Gravity intensified!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will not switch in a Pokemon which is slower and gets 1HKOed after fainting")
{
    bool32 alakazamFaster;
    u32 speedAlakazm;

    KNOWN_FAILING;

    PARAMETRIZE{ speedAlakazm = 200; alakazamFaster = FALSE; }
    PARAMETRIZE{ speedAlakazm = 400; alakazamFaster = TRUE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_WEAVILE) { Speed(300); Ability(ABILITY_SHADOW_TAG); } // Weavile has Shadow Tag, so AI can't switch on the first turn, but has to do it after fainting.
        OPPONENT(SPECIES_KADABRA) { Speed(200); Moves(MOVE_PSYCHIC, MOVE_DISABLE, MOVE_TAUNT, MOVE_CALM_MIND); }
        OPPONENT(SPECIES_ALAKAZAM) { Speed(speedAlakazm); Moves(MOVE_FOCUS_BLAST, MOVE_PSYCHIC); } // Alakazam has a move which OHKOes Weavile, but it doesn't matter if he's getting KO-ed first.
        OPPONENT(SPECIES_BLASTOISE) { Speed(200); Moves(MOVE_BUBBLE_BEAM, MOVE_WATER_GUN, MOVE_LEER, MOVE_STRENGTH); } // Can't OHKO, but survives a hit from Weavile's Night Slash.
    } WHEN {
            TURN { MOVE(player, MOVE_NIGHT_SLASH) ; EXPECT_SEND_OUT(opponent, alakazamFaster ? 1 : 2); }
    } SCENE {
        MESSAGE("Foe Kadabra fainted!");
        if (alakazamFaster) {
            MESSAGE("{PKMN} TRAINER LEAF sent out Alakazam!");
        } else {
            MESSAGE("{PKMN} TRAINER LEAF sent out Blastoise!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI switches if Perish Song is about to kill")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) {Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_CROBAT) {Moves(MOVE_TACKLE); }
    } WHEN {
            TURN { MOVE(player, MOVE_PERISH_SONG); }
            TURN { ; }
            TURN { ; }
            TURN { EXPECT_SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("{PKMN} TRAINER LEAF sent out Crobat!");
    }
}

AI_DOUBLE_BATTLE_TEST("AI won't use a Weather changing move if partner already chose such move")
{
    u32 j, k;
    static const u16 weatherMoves[] = {MOVE_SUNNY_DAY, MOVE_HAIL, MOVE_RAIN_DANCE, MOVE_SANDSTORM, MOVE_SNOWSCAPE};
    u16 weatherMoveLeft, weatherMoveRight;

    for (j = 0; j < ARRAY_COUNT(weatherMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(weatherMoves); k++)
        {
            PARAMETRIZE { weatherMoveLeft = weatherMoves[j]; weatherMoveRight = weatherMoves[k]; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(weatherMoveLeft); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, weatherMoveRight); }
    } WHEN {
            TURN {  NOT_EXPECT_MOVE(opponentRight, weatherMoveRight);
                    SCORE_LT_VAL(opponentRight, weatherMoveRight, AI_SCORE_DEFAULT, target:playerLeft);
                    SCORE_LT_VAL(opponentRight, weatherMoveRight, AI_SCORE_DEFAULT, target:playerRight);
                    SCORE_LT_VAL(opponentRight, weatherMoveRight, AI_SCORE_DEFAULT, target:opponentLeft);
                 }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not use Helping Hand if partner does not have any damage moves")
{
    u16 move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;

    PARAMETRIZE{ move1 = MOVE_LEER; move2 = MOVE_TOXIC; }
    PARAMETRIZE{ move1 = MOVE_HELPING_HAND; move2 = MOVE_PROTECT; }
    PARAMETRIZE{ move1 = MOVE_ACUPRESSURE; move2 = MOVE_DOUBLE_TEAM; move3 = MOVE_TOXIC; move4 = MOVE_PROTECT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HELPING_HAND, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move1, move2, move3, move4); }
    } WHEN {
            TURN {  NOT_EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND);
                    SCORE_LT_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:playerLeft);
                    SCORE_LT_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:playerRight);
                    SCORE_LT_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:opponentLeft);
                 }
    } SCENE {
        NOT MESSAGE("Foe Wobbuffet used Helping Hand!");
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not use a status move if partner already chose Helping Hand")
{
    s32 j;
    u32 statusMove;

    for (j = MOVE_NONE + 1; j < MOVES_COUNT; j++)
    {
        if (gBattleMoves[j].split == SPLIT_STATUS) {
            PARAMETRIZE{ statusMove = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HELPING_HAND); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, statusMove); }
    } WHEN {
            TURN {  NOT_EXPECT_MOVE(opponentRight, statusMove);
                    SCORE_LT_VAL(opponentRight, statusMove, AI_SCORE_DEFAULT, target:playerLeft);
                    SCORE_LT_VAL(opponentRight, statusMove, AI_SCORE_DEFAULT, target:playerRight);
                    SCORE_LT_VAL(opponentRight, statusMove, AI_SCORE_DEFAULT, target:opponentLeft);
                 }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Helping Hand!");
    }
}

AI_SINGLE_BATTLE_TEST("AI without any flags chooses moves at random - singles")
{
    GIVEN {
        AI_FLAGS(0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDOQUEEN) { Moves(MOVE_SPLASH, MOVE_EXPLOSION, MOVE_RAGE, MOVE_HELPING_HAND); }
    } WHEN {
            TURN { EXPECT_MOVES(opponent, MOVE_SPLASH, MOVE_EXPLOSION, MOVE_RAGE, MOVE_HELPING_HAND);
                   SCORE_EQ_VAL(opponent, MOVE_SPLASH, AI_SCORE_DEFAULT);
                   SCORE_EQ_VAL(opponent, MOVE_EXPLOSION, AI_SCORE_DEFAULT);
                   SCORE_EQ_VAL(opponent, MOVE_RAGE, AI_SCORE_DEFAULT);
                   SCORE_EQ_VAL(opponent, MOVE_HELPING_HAND, AI_SCORE_DEFAULT);
                }
    }
}

AI_DOUBLE_BATTLE_TEST("AI without any flags chooses moves at random - doubles")
{
    GIVEN {
        AI_FLAGS(0);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDOQUEEN) { Moves(MOVE_SPLASH, MOVE_EXPLOSION, MOVE_RAGE, MOVE_HELPING_HAND); }
        OPPONENT(SPECIES_NIDOQUEEN) { Moves(MOVE_SPLASH, MOVE_EXPLOSION, MOVE_RAGE, MOVE_HELPING_HAND); }
    } WHEN {
            TURN { EXPECT_MOVES(opponentLeft, MOVE_SPLASH, MOVE_EXPLOSION, MOVE_RAGE, MOVE_HELPING_HAND);
                   EXPECT_MOVES(opponentRight, MOVE_SPLASH, MOVE_EXPLOSION, MOVE_RAGE, MOVE_HELPING_HAND);
                   SCORE_EQ_VAL(opponentLeft, MOVE_SPLASH, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentLeft, MOVE_EXPLOSION, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentLeft, MOVE_RAGE, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentRight, MOVE_SPLASH, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentRight, MOVE_EXPLOSION, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentRight, MOVE_RAGE, AI_SCORE_DEFAULT, target:playerLeft);
                   SCORE_EQ_VAL(opponentRight, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:playerLeft);
                }
    }
}
