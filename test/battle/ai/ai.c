#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI prefers Bubble over Water Gun if it's slower")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_WATER_GUN) == GetMovePower(MOVE_BUBBLE));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SCIZOR) { Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_WATER_GUN, MOVE_BUBBLE); Speed(10); }
    } WHEN {
        TURN { SCORE_GT(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); }
        TURN { SCORE_GT(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers Water Gun over Bubble if it knows that foe has Contrary")
{
    enum Ability abilityAI;

    PARAMETRIZE { abilityAI = ABILITY_MOXIE; }
    PARAMETRIZE { abilityAI = ABILITY_MOLD_BREAKER; } // Mold Breaker ignores Contrary.
    GIVEN {
        ASSUME(GetMovePower(MOVE_BUBBLE) == GetMovePower(MOVE_WATER_GUN));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SHUCKLE) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_PINSIR) { Moves(MOVE_WATER_GUN, MOVE_BUBBLE); Ability(abilityAI); }
    } WHEN {
            TURN { MOVE(player, MOVE_DEFENSE_CURL); }
            TURN { MOVE(player, MOVE_DEFENSE_CURL);
                   if (abilityAI == ABILITY_MOLD_BREAKER) { SCORE_GT(opponent, MOVE_BUBBLE, MOVE_WATER_GUN); } // Bubble is a plus effect if contrary is ignored
                   else { SCORE_GT(opponent, MOVE_WATER_GUN, MOVE_BUBBLE); }}
    } SCENE {
        MESSAGE("Shuckle's Defense fell!"); // Contrary activates
    } THEN {
        EXPECT(gAiLogicData->abilities[B_POSITION_PLAYER_LEFT] == ABILITY_CONTRARY);
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers moves with better accuracy, but only if they both require the same number of hits to ko")
{
    enum Move move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    enum Move expectedMove, expectedMove2;
    u16 hp, turns;
    enum Ability abilityAtk;

    abilityAtk = ABILITY_NONE;
    expectedMove2 = MOVE_NONE;

    // Here it's a simple test, both Slam and Strength deal the same damage, but Strength always hits, whereas Slam often misses.
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SCRATCH; hp = 490; expectedMove = MOVE_STRENGTH; turns = 4; }
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_SCRATCH; hp = 365; expectedMove = MOVE_STRENGTH; turns = 3; }
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_SCRATCH; hp = 245; expectedMove = MOVE_STRENGTH; turns = 2; }
    PARAMETRIZE { move1 = MOVE_SLAM; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_SCRATCH; hp = 125; expectedMove = MOVE_STRENGTH; turns = 1; }
    // Mega Kick deals more damage, but can miss more often. Here, AI should choose Mega Kick if it can faint target in less number of turns than Strength. Otherwise, it should use Strength.
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_SCRATCH; hp = 170; expectedMove = MOVE_MEGA_KICK; turns = 1; }
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_SCRATCH; hp = 245; expectedMove = MOVE_STRENGTH; turns = 2; }
    // Swift always hits and Guts has accuracy of 100%. Hustle lowers accuracy of all physical moves.
    PARAMETRIZE { abilityAtk = ABILITY_HUSTLE; move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_SWIFT; move4 = MOVE_SCRATCH; hp = 5; expectedMove = MOVE_SWIFT; turns = 1; }
    PARAMETRIZE { abilityAtk = ABILITY_HUSTLE; move1 = MOVE_MEGA_KICK; move2 = MOVE_STRENGTH; move3 = MOVE_GUST; move4 = MOVE_SCRATCH; hp = 5; expectedMove = MOVE_GUST; turns = 1; }
    // Mega Kick and Slam both have lower accuracy. Gust and Scratch both have 100, so AI can choose either of them.
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_SLAM; move3 = MOVE_SCRATCH; move4 = MOVE_GUST; hp = 5; expectedMove = MOVE_GUST; expectedMove2 = MOVE_SCRATCH; turns = 1; }
    // All moves hit with No guard ability
    PARAMETRIZE { move1 = MOVE_MEGA_KICK; move2 = MOVE_GUST; hp = 5; expectedMove = MOVE_MEGA_KICK; expectedMove2 = MOVE_GUST; turns = 1; }
    // Tests to compare move that always hits and a beneficial effect. A move with higher acc should be chosen in this case.
    PARAMETRIZE { move1 = MOVE_SHOCK_WAVE; move2 = MOVE_ICY_WIND; hp = 5; expectedMove = MOVE_SHOCK_WAVE; turns = 1; }
    PARAMETRIZE { move1 = MOVE_SHOCK_WAVE; move2 = MOVE_ICY_WIND; move3 = MOVE_THUNDERBOLT; hp = 5; expectedMove = MOVE_SHOCK_WAVE; expectedMove2 = MOVE_THUNDERBOLT; turns = 1; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); }
        PLAYER(SPECIES_WOBBUFFET);
        ASSUME(GetMoveAccuracy(MOVE_SWIFT) == 0);
        ASSUME(GetMovePower(MOVE_SLAM) == GetMovePower(MOVE_STRENGTH));
        ASSUME(GetMovePower(MOVE_MEGA_KICK) > GetMovePower(MOVE_STRENGTH));
        ASSUME(GetMoveAccuracy(MOVE_SLAM) < GetMoveAccuracy(MOVE_STRENGTH));
        ASSUME(GetMoveAccuracy(MOVE_MEGA_KICK) < GetMoveAccuracy(MOVE_STRENGTH));
        ASSUME(GetMoveAccuracy(MOVE_SCRATCH) == 100);
        ASSUME(GetMoveAccuracy(MOVE_GUST) == 100);
        ASSUME(GetMoveAccuracy(MOVE_SHOCK_WAVE) == 0);
        ASSUME(GetMoveAccuracy(MOVE_THUNDERBOLT) == 100);
        ASSUME(GetMoveAccuracy(MOVE_ICY_WIND) != 100);
        ASSUME(GetMoveCategory(MOVE_SLAM) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_STRENGTH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_MEGA_KICK) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SHOCK_WAVE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_ICY_WIND) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_THUNDERBOLT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
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
    enum Move move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    enum Move expectedMove;
    enum Ability abilityAtk, abilityDef;

    abilityAtk = ABILITY_NONE;

    // Scald and Poison Jab take 3 hits, Waterfall takes 2.
    PARAMETRIZE { move1 = MOVE_WATERFALL; move2 = MOVE_SCALD; move3 = MOVE_POISON_JAB; move4 = MOVE_WATER_GUN; expectedMove = MOVE_WATERFALL; turns = 2; }
    // Poison Jab takes 3 hits, Water gun 5. Immunity so there's no poison chip damage.
    PARAMETRIZE { move1 = MOVE_POISON_JAB; move2 = MOVE_WATER_GUN; expectedMove = MOVE_POISON_JAB; abilityDef = ABILITY_IMMUNITY; turns = 3; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATERFALL) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SCALD) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_POISON_JAB) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetSpeciesBaseAttack(SPECIES_NIDOQUEEN) == 92); // Gen 5's 82 Base Attack causes the test to fail
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
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL); // Added because Geodude has to KO Typhlosion
        ASSUME(GetMoveCategory(MOVE_DRILL_RUN) == DAMAGE_CATEGORY_PHYSICAL);  // Added because Geodude has to KO Typhlosion
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

AI_SINGLE_BATTLE_TEST("AI prefers a weaker move over one with a downside effect if both require the same number of hits to ko")
{
    enum Move move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    enum Move expectedMove;
    u16 hp, turns;

    // Both moves require the same number of turns but Flamethrower will be chosen over Overheat (powerful effect)
    PARAMETRIZE { move1 = MOVE_OVERHEAT; move2 = MOVE_FLAMETHROWER; hp = 320; expectedMove = MOVE_FLAMETHROWER; turns = 2; }
    // Overheat kill in least amount of turns
    PARAMETRIZE { move1 = MOVE_OVERHEAT; move2 = MOVE_FLAMETHROWER; hp = 250; expectedMove = MOVE_OVERHEAT; turns = 1; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_FLAMETHROWER) == DAMAGE_CATEGORY_SPECIAL); // Added because Typhlosion has to KO Wobbuffet
        ASSUME(GetMoveCategory(MOVE_OVERHEAT) == DAMAGE_CATEGORY_SPECIAL);     // Added because Typhlosion has to KO Wobbuffet
        // With Gen 5 data, it chooses Overheat instead
        ASSUME(GetMovePower(MOVE_FLAMETHROWER) == 90); // In Gen 5, it's 95
        ASSUME(GetMovePower(MOVE_OVERHEAT) == 130); // In Gen 5, it's 140.
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TYPHLOSION) { Moves(move1, move2, move3, move4); }
    } WHEN {
        switch (turns)
        {
        case 1:
            TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
            break;
        case 2:
            TURN { EXPECT_MOVE(opponent, expectedMove); }
            TURN { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
            break;
        }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI prefers moves with the best possible score, chosen randomly if tied")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(5); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_THUNDERBOLT, MOVE_SLUDGE_BOMB, MOVE_TAKE_DOWN); }
    } WHEN {
        TURN { EXPECT_MOVES(opponent, MOVE_THUNDERBOLT, MOVE_SLUDGE_BOMB); SEND_OUT(player, 1); }
    }
    SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI can choose a status move that boosts the attack by two (singles)")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_STRENGTH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_HORN_ATTACK) == DAMAGE_CATEGORY_PHYSICAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(277); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KANGASKHAN) { Moves(MOVE_STRENGTH, MOVE_HORN_ATTACK, MOVE_SWORDS_DANCE); }
    } WHEN {
        TURN { EXPECT_MOVES(opponent, MOVE_STRENGTH, MOVE_SWORDS_DANCE); }
        TURN { EXPECT_MOVE(opponent, MOVE_STRENGTH); SEND_OUT(player, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI chooses the safest option to faint the target, taking into account accuracy and move effect")
{
    enum Move move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;
    enum Move expectedMove, expectedMove2 = MOVE_NONE;
    enum Ability abilityAtk = ABILITY_NONE;
    enum Item holdItemAtk = ITEM_NONE;

    // Psychic is not very effective, but always hits. Solarbeam requires a charging turn, Double Edge has recoil and Focus Blast can miss;
    PARAMETRIZE { abilityAtk = ABILITY_STURDY; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE; expectedMove = MOVE_PSYCHIC; }
    // Same as above, but ai mon has rock head ability, so it can use Double Edge without taking recoil damage. Psychic can also lower Special Defense,
    // but because it faints the target it doesn't matter.
    PARAMETRIZE { abilityAtk = ABILITY_ROCK_HEAD; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE;
                  expectedMove = MOVE_PSYCHIC; expectedMove2 = MOVE_DOUBLE_EDGE; }
    // This time it's Solarbeam + Psychic, because the weather is sunny.
    PARAMETRIZE { abilityAtk = ABILITY_DROUGHT; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE;
                  expectedMove = MOVE_PSYCHIC; expectedMove2 = MOVE_SOLAR_BEAM; }
    // Psychic and Solar Beam are chosen because user is holding Power Herb
    PARAMETRIZE { abilityAtk = ABILITY_STURDY; holdItemAtk = ITEM_POWER_HERB; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SOLAR_BEAM; move3 = MOVE_PSYCHIC; move4 = MOVE_DOUBLE_EDGE;
                  expectedMove = MOVE_PSYCHIC; expectedMove2 = MOVE_SOLAR_BEAM; }
    // Skull Bash is chosen because it's the most accurate and is holding Power Herb
    PARAMETRIZE { abilityAtk = ABILITY_STURDY; holdItemAtk = ITEM_POWER_HERB; move1 = MOVE_FOCUS_BLAST; move2 = MOVE_SKULL_BASH; move3 = MOVE_SLAM; move4 = MOVE_DOUBLE_EDGE;
                  expectedMove = MOVE_SKULL_BASH; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(5); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GEODUDE) { Moves(move1, move2, move3, move4); Ability(abilityAtk); Item(holdItemAtk); }
    } WHEN {
        TURN {  if (expectedMove2 == MOVE_NONE) { EXPECT_MOVE(opponent, expectedMove); SEND_OUT(player, 1); }
                else { EXPECT_MOVES(opponent, expectedMove, expectedMove2); SCORE_EQ(opponent, expectedMove, expectedMove2); SEND_OUT(player, 1); }
             }
    }
    SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI scores KOs with two turn moves correctly, considering Power Herb")
{
    enum Item aiItem;

    PARAMETRIZE { aiItem = ITEM_POWER_HERB; }
    PARAMETRIZE { aiItem= ITEM_NONE; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_POWER_HERB) == HOLD_EFFECT_POWER_HERB);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE); HP(5); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_FOCUS_BLAST, MOVE_SKULL_BASH, MOVE_FIERY_DANCE, MOVE_CRABHAMMER); Item(aiItem); }
    } WHEN {
        TURN { aiItem == ITEM_POWER_HERB ? EXPECT_MOVE(opponent, MOVE_SKULL_BASH) : SCORE_EQ(opponent, MOVE_FIERY_DANCE, MOVE_SKULL_BASH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use Solar Beam if there is no Sun up or the user is not holding Power Herb")
{
    enum Ability abilityAtk = ABILITY_NONE;
    enum Item holdItemAtk = ITEM_NONE;

    PARAMETRIZE { abilityAtk = ABILITY_DROUGHT; }
    PARAMETRIZE { holdItemAtk = ITEM_POWER_HERB; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SOLAR_BEAM) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_GRASS_PLEDGE) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMovePower(MOVE_GRASS_PLEDGE) == 80); // Gen 5's 50 power causes the test to fail
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(211); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TYPHLOSION) { Moves(MOVE_SOLAR_BEAM, MOVE_GRASS_PLEDGE); Ability(abilityAtk); Item(holdItemAtk); }
    } WHEN {
        if (abilityAtk == ABILITY_DROUGHT) {
            TURN { EXPECT_MOVES(opponent, MOVE_SOLAR_BEAM, MOVE_GRASS_PLEDGE); }
            TURN { EXPECT_MOVES(opponent, MOVE_SOLAR_BEAM, MOVE_GRASS_PLEDGE); SEND_OUT(player, 1); }
        } else if (holdItemAtk == ITEM_POWER_HERB) {
            TURN { EXPECT_MOVES(opponent, MOVE_SOLAR_BEAM, MOVE_GRASS_PLEDGE); MOVE(player, MOVE_KNOCK_OFF); }
            TURN { EXPECT_MOVE(opponent, MOVE_GRASS_PLEDGE); SEND_OUT(player, 1); }
        } else {
            TURN { EXPECT_MOVE(opponent, MOVE_GRASS_PLEDGE); }
            TURN { EXPECT_MOVE(opponent, MOVE_GRASS_PLEDGE); SEND_OUT(player, 1); }
        }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use ground type attacks against flying type Pokemon unless Gravity is in effect")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL); // Otherwise, it doesn't KO Crobat
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_CROBAT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NIDOQUEEN) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH, MOVE_POISON_STING, MOVE_GUST); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { MOVE(player, MOVE_GRAVITY); NOT_EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Gravity intensified!");
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

AI_SINGLE_BATTLE_TEST("AI will choose either Rock Tomb or Bulldoze if Stat drop effect will activate and they kill with the same number of hits")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(46); Speed(20); }
        PLAYER(SPECIES_WYNAUT) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_BULLDOZE, MOVE_ROCK_TOMB); }
    } WHEN {
            TURN { EXPECT_MOVES(opponent, MOVE_BULLDOZE, MOVE_ROCK_TOMB); }
            TURN { EXPECT_MOVES(opponent, MOVE_BULLDOZE, MOVE_ROCK_TOMB); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("First Impression is preferred on the first turn of the species if it's the best dmg move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FIRST_IMPRESSION) == EFFECT_FIRST_TURN_ONLY);
        ASSUME(GetMovePower(MOVE_FIRST_IMPRESSION) == 90);
        ASSUME(GetMovePower(MOVE_LUNGE) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_KANGASKHAN);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FIRST_IMPRESSION, MOVE_LUNGE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_FIRST_IMPRESSION); }
        TURN { EXPECT_MOVE(opponent, MOVE_LUNGE); }
    }
}

AI_SINGLE_BATTLE_TEST("First Impression is not chosen if it's blocked by certain abilities")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FIRST_IMPRESSION) == EFFECT_FIRST_TURN_ONLY);
        ASSUME(GetMovePower(MOVE_FIRST_IMPRESSION) == 90);
        ASSUME(GetMovePower(MOVE_LUNGE) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FIRST_IMPRESSION, MOVE_LUNGE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_LUNGE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will not choose Burn Up if the user lost the Fire typing")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BURN_UP) == EFFECT_FAIL_IF_NOT_ARG_TYPE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CYNDAQUIL) { Moves(MOVE_BURN_UP, MOVE_EXTRASENSORY, MOVE_FLAMETHROWER); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_BURN_UP); }
        TURN { EXPECT_MOVE(opponent, MOVE_FLAMETHROWER); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will only choose Surf 1/3 times if the opposing mon has Volt Absorb")
{
    PASSES_RANDOMLY(1, 3, RNG_AI_ABILITY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_LANTURN) { Moves(MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_SURF); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SURF); }
        TURN { EXPECT_MOVE(opponent, MOVE_SURF); }
    } SCENE {
        MESSAGE("The opposing Lanturn used Surf!");
        MESSAGE("The opposing Lanturn used Surf!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose Thunderbolt then Surf 2/3 times if the opposing mon has Volt Absorb")
{
    PASSES_RANDOMLY(2, 3, RNG_AI_ABILITY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_LANTURN) { Moves(MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_SURF); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); }
        TURN { EXPECT_MOVE(opponent, MOVE_SURF); }
    } SCENE {
        MESSAGE("The opposing Lanturn used Thunderbolt!");
        MESSAGE("The opposing Lanturn used Surf!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose Scratch over Power-up Punch with Contrary")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SUCTION_CUPS; }
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) == 40);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMovePower(MOVE_POWER_UP_PUNCH) == 40);
        ASSUME(GetMoveType(MOVE_POWER_UP_PUNCH) == TYPE_FIGHTING);
        ASSUME(GetSpeciesType(SPECIES_SQUIRTLE, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_SQUIRTLE, 1) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SQUIRTLE) { };
        OPPONENT(SPECIES_MALAMAR) { Ability(ability); Moves(MOVE_SCRATCH, MOVE_POWER_UP_PUNCH); }
    } WHEN {
        TURN {
            if (ability != ABILITY_CONTRARY)
                EXPECT_MOVE(opponent, MOVE_POWER_UP_PUNCH);
            else
                EXPECT_MOVE(opponent, MOVE_SCRATCH);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI will choose Superpower over Outrage with Contrary")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SUCTION_CUPS; }
    PARAMETRIZE { ability = ABILITY_CONTRARY; }
    GIVEN {
        ASSUME(GetMovePower(MOVE_SUPERPOWER) == 120);
        ASSUME(GetMoveType(MOVE_SUPERPOWER) == TYPE_FIGHTING);
        ASSUME(GetMovePower(MOVE_OUTRAGE) == 120);
        ASSUME(GetMoveType(MOVE_OUTRAGE) == TYPE_DRAGON);
        ASSUME(GetSpeciesType(SPECIES_SQUIRTLE, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_SQUIRTLE, 1) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SQUIRTLE) { };
        OPPONENT(SPECIES_MALAMAR) { Ability(ability); Moves(MOVE_OUTRAGE, MOVE_SUPERPOWER); }
    } WHEN {
        TURN {
            if (ability != ABILITY_CONTRARY)
                EXPECT_MOVE(opponent, MOVE_OUTRAGE);
            else
                EXPECT_MOVE(opponent, MOVE_SUPERPOWER);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI calculates guaranteed criticals and detects critical immunity")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SWIFT_SWIM; }
    PARAMETRIZE { ability = ABILITY_SHELL_ARMOR; }

    GIVEN {
        ASSUME(MoveAlwaysCrits(MOVE_STORM_THROW));
        ASSUME(GetMovePower(MOVE_STORM_THROW) == 60);
        ASSUME(GetMovePower(MOVE_BRICK_BREAK) == 75);
        ASSUME(GetMoveType(MOVE_STORM_THROW) == GetMoveType(MOVE_BRICK_BREAK));
        ASSUME(GetMoveCategory(MOVE_STORM_THROW) == GetMoveCategory(MOVE_BRICK_BREAK));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_OMASTAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_STORM_THROW, MOVE_BRICK_BREAK); }
    } WHEN {
        if (ability == ABILITY_SHELL_ARMOR)
            TURN { EXPECT_MOVE(opponent, MOVE_BRICK_BREAK); }
        else
            TURN { EXPECT_MOVE(opponent, MOVE_STORM_THROW); }
    }
}

AI_SINGLE_BATTLE_TEST("AI avoids contact moves against rocky helmet")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_ROCKY_HELMET; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_BRANCH_POKE));
        ASSUME(!MoveMakesContact(MOVE_LEAFAGE));
        ASSUME(GetMovePower(MOVE_BRANCH_POKE) == GetMovePower(MOVE_LEAFAGE));
        ASSUME(GetMoveType(MOVE_BRANCH_POKE) == GetMoveType(MOVE_LEAFAGE));
        ASSUME(GetMoveCategory(MOVE_BRANCH_POKE) == GetMoveCategory(MOVE_LEAFAGE));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_BRANCH_POKE, MOVE_LEAFAGE); }
    } WHEN {
        if (item == ITEM_ROCKY_HELMET)
            TURN { EXPECT_MOVE(opponent, MOVE_LEAFAGE); }
        else
            TURN { EXPECT_MOVES(opponent, MOVE_LEAFAGE, MOVE_BRANCH_POKE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses a guaranteed KO move instead of the move with the highest expected damage")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    GIVEN {
        ASSUME(GetMoveCriticalHitStage(MOVE_SLASH) == 1);
        ASSUME(GetMovePower(MOVE_SLASH) == 70);
        ASSUME(GetMovePower(MOVE_STRENGTH) == 80);
        ASSUME(GetMoveType(MOVE_SLASH) == GetMoveType(MOVE_STRENGTH));
        ASSUME(GetMoveCategory(MOVE_SLASH) == GetMoveCategory(MOVE_STRENGTH));
        AI_FLAGS(flags);
        PLAYER(SPECIES_WOBBUFFET) { HP(225); }
        OPPONENT(SPECIES_ABSOL) { Ability(ABILITY_SUPER_LUCK); Moves(MOVE_SLASH, MOVE_STRENGTH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SLASH); }
        if (flags & AI_FLAG_TRY_TO_FAINT)
            TURN { EXPECT_MOVE(opponent, MOVE_STRENGTH); }
        else
            TURN { EXPECT_MOVE(opponent, MOVE_SLASH); }
    } SCENE {
        if (flags & AI_FLAG_TRY_TO_FAINT)
            MESSAGE("Wobbuffet fainted!");
        else
            NOT MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI stays choice locked into moves in spite of the player's ability disabling them")
{
    u32 playerMon, aiMove;
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_DAZZLING;          playerMon = SPECIES_BRUXISH;       aiMove = MOVE_QUICK_ATTACK; }
    PARAMETRIZE { ability = ABILITY_QUEENLY_MAJESTY;   playerMon = SPECIES_TSAREENA;      aiMove = MOVE_QUICK_ATTACK; }
    PARAMETRIZE { ability = ABILITY_ARMOR_TAIL;        playerMon = SPECIES_FARIGIRAF;     aiMove = MOVE_QUICK_ATTACK; }
    PARAMETRIZE { ability = ABILITY_SOUNDPROOF;        playerMon = SPECIES_EXPLOUD;       aiMove = MOVE_BOOMBURST; }
    PARAMETRIZE { ability = ABILITY_BULLETPROOF;       playerMon = SPECIES_CHESNAUGHT;    aiMove = MOVE_BULLET_SEED; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        ASSUME(IsSoundMove(MOVE_BOOMBURST));
        ASSUME(IsBallisticMove(MOVE_BULLET_SEED));
        ASSUME(GetMoveCategory(MOVE_TAIL_WHIP) == DAMAGE_CATEGORY_STATUS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(playerMon) { Ability(ability); }
        OPPONENT(SPECIES_SMEARGLE) { Item(ITEM_CHOICE_BAND); Moves(aiMove, MOVE_SCRATCH); }
    } WHEN {
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, aiMove); }
        TURN { EXPECT_MOVE(opponent, aiMove); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use Sucker Punch if it expects a status move a percentage of the time")
{
    PASSES_RANDOMLY(SUCKER_PUNCH_CHANCE, 100, RNG_AI_SUCKER_PUNCH);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUCKER_PUNCH) == EFFECT_SUCKER_PUNCH);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_GROWL, MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SUCKER_PUNCH, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SUCKER_PUNCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use thawing moves if target is frozen unless it is super effective or it has no other options")
{
    u32 aiFlags = 0; u32 status = 0; u32 aiMove = 0;
    PARAMETRIZE { status = STATUS1_FREEZE;      aiMove = MOVE_SCALD;    aiFlags = 0; }
    PARAMETRIZE { status = STATUS1_FREEZE;      aiMove = MOVE_SCALD;    aiFlags = AI_FLAG_CHECK_BAD_MOVE; }
    PARAMETRIZE { status = STATUS1_FROSTBITE;   aiMove = MOVE_SCALD;    aiFlags = 0; }
    PARAMETRIZE { status = STATUS1_FROSTBITE;   aiMove = MOVE_SCALD;    aiFlags = AI_FLAG_CHECK_BAD_MOVE; }
    PARAMETRIZE { status = STATUS1_FREEZE;      aiMove = MOVE_EMBER;    aiFlags = 0; }
    PARAMETRIZE { status = STATUS1_FREEZE;      aiMove = MOVE_EMBER;    aiFlags = AI_FLAG_CHECK_BAD_MOVE; }
    PARAMETRIZE { status = STATUS1_FROSTBITE;   aiMove = MOVE_EMBER;    aiFlags = 0; }
    PARAMETRIZE { status = STATUS1_FROSTBITE;   aiMove = MOVE_EMBER;    aiFlags = AI_FLAG_CHECK_BAD_MOVE; }

    GIVEN {
        WITH_CONFIG(B_HIT_THAW, GEN_6); // In Gen 5, moves that thawed the user didn't thaw the target
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveCategory(MOVE_TACKLE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(MoveThawsUser(MOVE_SCALD) == TRUE);
        AI_FLAGS(aiFlags | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); Status1(status); }
        OPPONENT(SPECIES_VULPIX) { Moves(MOVE_TACKLE, aiMove); }
    } WHEN {
        if (aiFlags == AI_FLAG_CHECK_BAD_MOVE)
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
        else
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, aiMove); }
    }
}

AI_SINGLE_BATTLE_TEST("AI score for Mean Look will be decreased if target can escape")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_BULBASAUR) { Item(ITEM_SHED_SHELL); }
        OPPONENT(SPECIES_BULBASAUR) { Moves(MOVE_TACKLE, MOVE_MEAN_LOOK); }
    } WHEN {
        TURN { SCORE_EQ_VAL(opponent, MOVE_MEAN_LOOK, 90); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI considers Focus Sash when determining if it should switch out")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_BEAUTIFLY) { Speed(10); Moves(MOVE_AIR_SLASH); }
        OPPONENT(SPECIES_CACNEA) { Speed(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_COMBUSKEN) { Speed(1); Moves(MOVE_FLAMETHROWER); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_CROBAT) { Speed(11); Moves(MOVE_SLUDGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_AIR_SLASH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_AIR_SLASH); EXPECT_MOVE(opponent, MOVE_FLAMETHROWER); }
    }
}

AI_SINGLE_BATTLE_TEST("AI sees popped Air Balloon")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_AIR_BALLOON) == HOLD_EFFECT_AIR_BALLOON);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_TORCHIC) { Item(ITEM_AIR_BALLOON); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_SCRATCH, MOVE_EARTHQUAKE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI sees popped Air Balloon after Air Balloon mon switches out and back in")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_AIR_BALLOON) == HOLD_EFFECT_AIR_BALLOON);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_TORCHIC) { Item(ITEM_AIR_BALLOON); Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_TORCHIC) { Item(ITEM_AIR_BALLOON); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_SCRATCH, MOVE_EARTHQUAKE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { SWITCH(player, 0); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); SEND_OUT(player, 1); }
    }
}

SINGLE_BATTLE_TEST("AI correctly records used moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_GROWL, MOVE_FLOWER_TRICK, MOVE_TORCH_SONG); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_RAGE_FIST, MOVE_PSYCHIC, MOVE_SCRATCH, MOVE_EARTHQUAKE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE);       MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { MOVE(player, MOVE_FLOWER_TRICK); MOVE(opponent, MOVE_SCRATCH);    }
        TURN { MOVE(player, MOVE_TORCH_SONG);   MOVE(opponent, MOVE_PSYCHIC);    }
        TURN { MOVE(player, MOVE_GROWL);        MOVE(opponent, MOVE_RAGE_FIST);  }
    } THEN {
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][0], MOVE_TACKLE);
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][1], MOVE_GROWL);
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][2], MOVE_FLOWER_TRICK);
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_PLAYER_LEFT][3], MOVE_TORCH_SONG);

        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_OPPONENT_LEFT][0], MOVE_RAGE_FIST);
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_OPPONENT_LEFT][1], MOVE_PSYCHIC);
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_OPPONENT_LEFT][2], MOVE_SCRATCH);
        EXPECT_EQ(gBattleHistory->usedMoves[B_POSITION_OPPONENT_LEFT][3], MOVE_EARTHQUAKE);
    }
}

AI_SINGLE_BATTLE_TEST("AI won't boost stats against opponent with Unaware")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_QUAGSIRE) { Ability(ABILITY_UNAWARE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_BODY_SLAM, MOVE_SWORDS_DANCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_BODY_SLAM); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use status moves against opponents that would benefit")
{
    enum Move aiMove;
    PARAMETRIZE { aiMove = MOVE_WILL_O_WISP; }
    PARAMETRIZE { aiMove = MOVE_TOXIC; }
    PARAMETRIZE { aiMove = MOVE_THUNDER_WAVE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SWELLOW) { Ability(ABILITY_GUTS); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, aiMove); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI sees that Primal weather can block a move by type")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_HYDRO_PUMP) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_BLASTOISE) { Moves(MOVE_HYDRO_PUMP, MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_POUND); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI sees opposing drain ability")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_RAZOR_LEAF) != TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_METAL_CLAW) != TYPE_ELECTRIC);
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_KRABBY) { Ability(ABILITY_VOLT_ABSORB); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_MAGNETON) { Moves(MOVE_THUNDERBOLT, MOVE_RAZOR_LEAF); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_THUNDERBOLT, MOVE_METAL_CLAW); }
    } WHEN {
        TURN {
            NOT_EXPECT_MOVE(opponentLeft, MOVE_THUNDERBOLT);
            NOT_EXPECT_MOVE(opponentRight, MOVE_THUNDERBOLT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will not set up Weather if it wont have any affect")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { ability = ABILITY_DAMP; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAIN_DANCE) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_RAIN_DANCE) == BATTLE_WEATHER_RAIN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_GOLDUCK) { Ability(ability); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_KABUTOPS) { Ability(ABILITY_SWIFT_SWIM); Moves(MOVE_RAIN_DANCE, MOVE_POUND); }
    } WHEN {
        if (ability == ABILITY_CLOUD_NINE)
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_POUND); }
        else
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_RAIN_DANCE); }
    }
}

AI_SINGLE_BATTLE_TEST("Move scoring comparison properly awards bonus point to best OHKO move")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_THUNDER, MOVE_EFFECT_PARALYSIS));
        ASSUME(GetMoveAdditionalEffectCount(MOVE_WATER_SPOUT) == 0);
        ASSUME(GetMoveAdditionalEffectCount(MOVE_WATER_GUN) == 0);
        ASSUME(GetMoveAdditionalEffectCount(MOVE_ORIGIN_PULSE) == 0);
        ASSUME(GetMoveAccuracy(MOVE_WATER_SPOUT) > GetMoveAccuracy(MOVE_THUNDER));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_WAILORD) { Level(50); }
        OPPONENT(SPECIES_WAILORD) { Moves(MOVE_THUNDER, MOVE_WATER_SPOUT, MOVE_WATER_GUN, MOVE_SURF); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_WATER_SPOUT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will stop setting up at +4")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE, MOVE_IRON_DEFENSE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_IRON_DEFENSE); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_IRON_DEFENSE); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("Move scoring comparison properly awards bonus point to best OHKO move")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_THUNDER, MOVE_EFFECT_PARALYSIS));
        ASSUME(GetMoveAdditionalEffectCount(MOVE_WATER_SPOUT) == 0);
        ASSUME(GetMoveAdditionalEffectCount(MOVE_WATER_GUN) == 0);
        ASSUME(GetMoveAdditionalEffectCount(MOVE_ORIGIN_PULSE) == 0);
        ASSUME(GetMoveAccuracy(MOVE_WATER_SPOUT) > GetMoveAccuracy(MOVE_THUNDER));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_WAILORD) { Level(50); }
        OPPONENT(SPECIES_WAILORD) { Moves(MOVE_THUNDER, MOVE_WATER_SPOUT, MOVE_WATER_GUN, MOVE_SURF); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_WATER_SPOUT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will see Magnitude damage")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAGNITUDE) == EFFECT_MAGNITUDE);
        ASSUME(GetMoveType(MOVE_MAGNITUDE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_GEODUDE) { Level(15); Moves(MOVE_DEFENSE_CURL, MOVE_MAGNITUDE); }
        OPPONENT(SPECIES_TYRUNT) { Level(13); Moves(MOVE_BITE, MOVE_THUNDER_FANG, MOVE_ROCK_TOMB); }
        OPPONENT(SPECIES_ZUBAT) { Level(14); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MAGNITUDE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will prefer resisted move over failing move")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, GEN_6);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_ROSELIA) { Moves(MOVE_ABSORB); }
        OPPONENT(SPECIES_GLOOM) { Moves(MOVE_MEGA_DRAIN, MOVE_STUN_SPORE, MOVE_LEECH_SEED, MOVE_SYNTHESIS); }
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); EXPECT_MOVE(opponent, MOVE_MEGA_DRAIN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't setup if it can KO through Sturdy effect")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SKARMORY) { Ability(ABILITY_STURDY); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_MOLTRES) { Moves(MOVE_FIRE_BLAST, MOVE_AGILITY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_FIRE_BLAST); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't setup if otherwise good scenario is changed by the presence of priority")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_FLOATZEL) { Speed(2); Moves(MOVE_AQUA_JET, MOVE_SURF); }
        OPPONENT(SPECIES_DONPHAN) { Speed(5); Moves(MOVE_BULK_UP, MOVE_EARTHQUAKE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will use Recovery move if it outheals your damage and outspeeds")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SHOULD_RECOVER);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_LINOONE) { Speed(2); Moves(MOVE_HEADBUTT); }
        OPPONENT(SPECIES_GASTRODON) { Speed(5); Moves(MOVE_SCALD, MOVE_RECOVER); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT); EXPECT_MOVE(opponent, MOVE_RECOVER); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will use recovery move if it outheals your damage and is outsped")
{
    enum Move aiMove = MOVE_NONE;
    PASSES_RANDOMLY(100, 100, RNG_AI_SHOULD_RECOVER);
    PARAMETRIZE{ aiMove = MOVE_RECOVER; }
    PARAMETRIZE{ aiMove = MOVE_STRENGTH_SAP; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_LINOONE) { Speed(5); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_GASTRODON) { Speed(2); Moves(MOVE_SCALD, aiMove); HP(200); MaxHP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, aiMove); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will use recovery move if is in no immediate danger beneath an HP threshold")
{
    PASSES_RANDOMLY(SHOULD_RECOVER_CHANCE, 100, RNG_AI_SHOULD_RECOVER);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_LINOONE) { Speed(2); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_GASTRODON) { Speed(5); Moves(MOVE_SCALD, MOVE_RECOVER); HP(200); MaxHP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_RECOVER); }
    }
}

AI_SINGLE_BATTLE_TEST("AI has a chance to prioritize last chance priority damage over slow KO")
{
    PASSES_RANDOMLY(PRIORITIZE_LAST_CHANCE_CHANCE, 100, RNG_AI_PRIORITIZE_LAST_CHANCE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_CAMERUPT) { Speed(2); Moves(MOVE_FLAMETHROWER, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_FLOATZEL) { Level(85); Speed(1); HP(1); Moves(MOVE_WAVE_CRASH, MOVE_AQUA_JET); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_AQUA_JET); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI won't be confused by player's previous priority moves when evaluating KOs")
{
    PASSES_RANDOMLY(100, 100);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_BEAUTIFLY) { Speed(1); Moves(MOVE_DETECT, MOVE_SCRATCH); }
        PLAYER(SPECIES_MASQUERAIN) { Speed(10); Moves(MOVE_DETECT, MOVE_SCRATCH); }
        OPPONENT(SPECIES_CRADILY) { Speed(5); Moves(MOVE_POWER_GEM); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(4); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DETECT); MOVE(playerRight, MOVE_DETECT); EXPECT_MOVE(opponentLeft, MOVE_POWER_GEM, target:playerLeft); EXPECT_MOVE(opponentRight, MOVE_CELEBRATE); }
        TURN { MOVE(playerLeft, MOVE_DETECT); MOVE(playerRight, MOVE_DETECT); EXPECT_MOVE(opponentLeft, MOVE_POWER_GEM, target:playerLeft); EXPECT_MOVE(opponentRight, MOVE_CELEBRATE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will see 2HKOs through resist berries")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { HP(117); Moves(MOVE_CELEBRATE); Item(ITEM_CHOPLE_BERRY); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_JUMP_KICK, MOVE_HEADBUTT); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_JUMP_KICK); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will prioritize a regular OHKO over a berry-ignoring OHKO")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { HP(75); Moves(MOVE_CELEBRATE); Item(ITEM_CHOPLE_BERRY); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_BOOMBURST, MOVE_VITAL_THROW); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVES(opponent, MOVE_BOOMBURST, MOVE_VITAL_THROW); }
        SCORE_GT(opponent, MOVE_BOOMBURST, MOVE_VITAL_THROW);
    }
}

AI_SINGLE_BATTLE_TEST("AI will not prioritize a regular OHKO over a berry-reduced OHKO")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { HP(1); Moves(MOVE_CELEBRATE); Item(ITEM_CHOPLE_BERRY); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH, MOVE_KARATE_CHOP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVES(opponent, MOVE_SCRATCH, MOVE_KARATE_CHOP); }
        SCORE_EQ(opponent, MOVE_SCRATCH, MOVE_KARATE_CHOP);
    }
}

AI_SINGLE_BATTLE_TEST("AI won't increase its stats if it's about to fall asleep due to Yawn")
{
    enum Move aiMove;
    PARAMETRIZE { aiMove = MOVE_CELEBRATE; }
    PARAMETRIZE { aiMove = MOVE_SWORDS_DANCE; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_YAWN, MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(aiMove, MOVE_SCRATCH); }
    } WHEN {
        if (aiMove == MOVE_CELEBRATE)
            TURN { MOVE(player, MOVE_YAWN); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        else
            TURN { MOVE(player, MOVE_YAWN); EXPECT_MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will consider using Explosion inversely proportional to its missing HP")
{
    u32 monHP; u32 passesChance;
    PARAMETRIZE { monHP = 20; passesChance = EXPLOSION_MINIMUM_CHANCE; }
    PARAMETRIZE { monHP = 1; passesChance = EXPLOSION_MAXIMUM_CHANCE; }
    PASSES_RANDOMLY(passesChance, 100, RNG_AI_CONSIDER_EXPLOSION);
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        ASSUME(EXPLOSION_LOWER_HP_THRESHOLD == 10);
        ASSUME(EXPLOSION_HIGHER_HP_THRESHOLD == 90);
        ASSUME(LAST_MON_PREFERS_NOT_SACRIFICE == FALSE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { Level(5); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(5); HP(monHP); MaxHP(20); Moves(MOVE_SCRATCH, MOVE_EXPLOSION); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_EXPLOSION); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will prioritize non-self-sacrificing moves if they have the same hits to KO")
{
    enum Move selfSacrificeMove;
    PARAMETRIZE { selfSacrificeMove = MOVE_EXPLOSION; }
    PARAMETRIZE { selfSacrificeMove = MOVE_FINAL_GAMBIT; }
    PASSES_RANDOMLY(100, 100, RNG_AI_CONSIDER_EXPLOSION);
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
        ASSUME(EXPLOSION_LOWER_HP_THRESHOLD == 10);
        ASSUME(EXPLOSION_HIGHER_HP_THRESHOLD == 90);
        ASSUME(LAST_MON_PREFERS_NOT_SACRIFICE == FALSE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { Level(5); HP(1); Speed(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(5); HP(1); MaxHP(20); Speed(2); Moves(MOVE_SCRATCH, selfSacrificeMove); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will consider using Final Gambit if it expects to KO and outspeeds")
{
    u32 aiOmniscientFlag;
    PARAMETRIZE { aiOmniscientFlag = AI_FLAG_OMNISCIENT; }
    PARAMETRIZE { aiOmniscientFlag = 0 ;}
    PASSES_RANDOMLY(FINAL_GAMBIT_CHANCE, 100, RNG_AI_FINAL_GAMBIT);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
        ASSUME(LAST_MON_PREFERS_NOT_SACRIFICE == FALSE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiOmniscientFlag);
        PLAYER(SPECIES_ZIGZAGOON) { Level(5); MaxHP(20); Speed(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(5); MaxHP(20); Speed(2); Moves(MOVE_SCRATCH, MOVE_FINAL_GAMBIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_FINAL_GAMBIT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI's Explosion scoring handles multiple move effects and the Explosion defense config")
{
    u32 genConfig; u32 passesChance;
    PARAMETRIZE { genConfig = GEN_5; passesChance = 0; }
    PARAMETRIZE { genConfig = GEN_4; passesChance = EXPLOSION_MAXIMUM_CHANCE; }
    PASSES_RANDOMLY(passesChance, 100, RNG_AI_CONSIDER_EXPLOSION);
    GIVEN {
        WITH_CONFIG(B_EXPLOSION_DEFENSE, genConfig);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_CLOYSTER) { Level(44); HP(68); Moves(MOVE_DETECT, MOVE_RAZOR_SHELL, MOVE_ICICLE_SPEAR, MOVE_ICE_SHARD); }
        OPPONENT(SPECIES_GLALIE_MEGA) { Level(44); HP(1); Ability(ABILITY_REFRIGERATE); Friendship(MAX_FRIENDSHIP); Moves(MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_CRUNCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_DETECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI won't be confused by player's one-shot-priority moves (ie. Fake Out, Detect) when comparing speed")
{
    PASSES_RANDOMLY(100, 100);
    GIVEN {
        ASSUME(GetMovePriority(MOVE_DETECT) > GetMovePriority(MOVE_AQUA_JET));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_COMBUSKEN) { Level(20); HP(1); Ability(ABILITY_SPEED_BOOST); Item(ITEM_BRIGHT_POWDER); Moves(MOVE_DETECT, MOVE_DOUBLE_KICK); }
        PLAYER(SPECIES_QUILAVA) { Level(20); Ability(ABILITY_ADAPTABILITY); Item(ITEM_ORAN_BERRY); Moves(MOVE_MUD_SHOT, MOVE_INCINERATE); }
        OPPONENT(SPECIES_PARAS) { Level(16); Ability(ABILITY_DRY_SKIN); Item(ITEM_QUICK_CLAW); Moves(MOVE_SLEEP_POWDER, MOVE_BUG_BITE, MOVE_AERIAL_ACE, MOVE_POISON_FANG); }
        OPPONENT(SPECIES_BUIZEL) { Level(16); Ability(ABILITY_SWIFT_SWIM); Item(ITEM_DAMP_ROCK); Moves(MOVE_RAIN_DANCE, MOVE_HELPING_HAND, MOVE_ICE_FANG, MOVE_AQUA_JET); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DETECT); MOVE(playerRight, MOVE_INCINERATE, target:opponentLeft); EXPECT_MOVE(opponentRight, MOVE_AQUA_JET, target:playerLeft); }
    }
}

TEST("AI hits to KO damage rounding works correctly")
{
    EXPECT_EQ(GetNoOfHitsToKO(4, 12), 3);
    EXPECT_EQ(GetNoOfHitsToKO(16, 50), 4);
}

AI_SINGLE_BATTLE_TEST("AI is encouraged to use pivot moves if it outspeeds and should switch")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(2); HP(3); MaxHP(5); Moves(MOVE_U_TURN, MOVE_STRENGTH); }
        OPPONENT(SPECIES_METAGROSS) { Speed(2); Moves(MOVE_METEOR_MASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); EXPECT_MOVE(opponent, MOVE_U_TURN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI is encouraged to use pivot moves if it is outsped, survives a hit, and should switch")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_MACHAMP) { Speed(2); Moves(MOVE_DRAGON_RAGE, MOVE_GROWL); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); MaxHP(41); Moves(MOVE_U_TURN, MOVE_STRENGTH); }
        OPPONENT(SPECIES_METAGROSS) { Speed(2); Moves(MOVE_METEOR_MASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); EXPECT_MOVE(opponent, MOVE_U_TURN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI is encouraged to use pivot moves if the target has a Sash or Multiscale effect and the AI has a good switchin")
{
    PASSES_RANDOMLY(SHOULD_PIVOT_BREAK_SASH_CHANCE, 100, RNG_AI_SHOULD_PIVOT_BREAK_SASH);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Item(ITEM_FOCUS_SASH); Moves(MOVE_GROWL); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_U_TURN, MOVE_STRENGTH); }
        OPPONENT(SPECIES_METAGROSS) { Moves(MOVE_METEOR_MASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); EXPECT_MOVE(opponent, MOVE_U_TURN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI is encouraged to use pivot moves if it benefits from Regenerator and has a good switchin")
{
    PASSES_RANDOMLY(100, 100);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_DRAGON_RAGE, MOVE_GROWL); }
        OPPONENT(SPECIES_TANGELA) { Speed(2); HP(30); MaxHP(100); Ability(ABILITY_REGENERATOR); Moves(MOVE_U_TURN, MOVE_MAGICAL_LEAF); }
        OPPONENT(SPECIES_METAGROSS) { Speed(2); Moves(MOVE_METEOR_MASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); EXPECT_MOVE(opponent, MOVE_U_TURN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI is discouraged from using pivot moves if it has no good switchin and does not KO")
{
    PASSES_RANDOMLY(100, 100);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(2); HP(3); MaxHP(5); Moves(MOVE_U_TURN, MOVE_STRENGTH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Level(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); EXPECT_MOVE(opponent, MOVE_STRENGTH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will try to withstand hit with absorbing move")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); HP(39); Moves(MOVE_ENERGY_BALL, MOVE_GIGA_DRAIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); EXPECT_MOVE(opponent, MOVE_GIGA_DRAIN); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will not try to withstand hit with absorbing move if it will still be KO'd")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); MaxHP(40); HP(39); Moves(MOVE_ENERGY_BALL, MOVE_GIGA_DRAIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); EXPECT_MOVE(opponent, MOVE_ENERGY_BALL); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI can use Acupressure on its ally")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ACUPRESSURE); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentRight, MOVE_SCRATCH, target:playerRight);
            EXPECT_MOVE(opponentLeft, MOVE_ACUPRESSURE, target:opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentLeft);
    }
}

AI_SINGLE_BATTLE_TEST("AI's comparison of damaging moves correctly reads moveset indexes for effects")
{
    enum Move move = MOVE_NONE;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_DUAL_CHOP; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_RAPIDASH_GALAR){ Level(64); HP(1); Nature(NATURE_TIMID); Moves(MOVE_TACKLE);}
        OPPONENT(SPECIES_HAXORUS){ Level(64); Nature(NATURE_JOLLY); Ability(ABILITY_MOLD_BREAKER); Moves(move, MOVE_EARTHQUAKE, MOVE_POISON_JAB); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_TACKLE);
            if (move == MOVE_TACKLE)
                SCORE_EQ_VAL(opponent, MOVE_TACKLE, 104);
            else if (move == MOVE_DUAL_CHOP)
                SCORE_EQ_VAL(opponent, MOVE_DUAL_CHOP, 60);
            SCORE_EQ_VAL(opponent, MOVE_EARTHQUAKE, 104);
            SCORE_EQ_VAL(opponent, MOVE_POISON_JAB, 105);
        }
    }
}

AI_SINGLE_BATTLE_TEST("Bolt Beak damage will be correctly seen by AI (singles)")
{
    u32 playerSpeed, aiSpeed;

    PARAMETRIZE { playerSpeed = 20; aiSpeed = 10; }
    PARAMETRIZE { playerSpeed = 10; aiSpeed = 20; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_STARMIE) { Speed(playerSpeed); Moves(MOVE_PROTECT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZAPDOS) { Speed(aiSpeed); Moves(MOVE_BOLT_BEAK, MOVE_THUNDER); }
    } WHEN {
        if (playerSpeed > aiSpeed) {
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_THUNDER); }
            TURN { EXPECT_MOVE(opponent, MOVE_THUNDER); }
        } else {
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_BOLT_BEAK); }
            TURN { EXPECT_MOVE(opponent, MOVE_BOLT_BEAK); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Bolt Beak damage will be correctly seen by AI (doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_PROTECT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_PROTECT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZAPDOS)  { Speed(2); Moves(MOVE_BOLT_BEAK, MOVE_THUNDER); }
        OPPONENT(SPECIES_ZAPDOS)  { Speed(4); Moves(MOVE_BOLT_BEAK, MOVE_THUNDER); }
        TIE_BREAK_TARGET(TARGET_TIE_HI, 0);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            MOVE(playerRight, MOVE_PROTECT);
            SCORE_EQ_VAL(opponentLeft,  MOVE_BOLT_BEAK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft,  MOVE_BOLT_BEAK, AI_SCORE_DEFAULT,                    target:playerRight);
            SCORE_EQ_VAL(opponentLeft,  MOVE_THUNDER,   AI_SCORE_DEFAULT,                    target:playerLeft);
            SCORE_EQ_VAL(opponentLeft,  MOVE_THUNDER,   AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_BOLT_BEAK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_BOLT_BEAK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_THUNDER,   AI_SCORE_DEFAULT,                    target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_THUNDER,   AI_SCORE_DEFAULT,                    target:playerRight);
            EXPECT_MOVE(opponentLeft,   MOVE_THUNDER,   target:playerRight);
            EXPECT_MOVE(opponentRight,  MOVE_BOLT_BEAK, target:playerRight);
        }
        TURN {
            SCORE_EQ_VAL(opponentLeft,  MOVE_BOLT_BEAK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft,  MOVE_BOLT_BEAK, AI_SCORE_DEFAULT,                    target:playerRight);
            SCORE_EQ_VAL(opponentLeft,  MOVE_THUNDER,   AI_SCORE_DEFAULT,                    target:playerLeft);
            SCORE_EQ_VAL(opponentLeft,  MOVE_THUNDER,   AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_BOLT_BEAK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_BOLT_BEAK, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target:playerRight);
            SCORE_EQ_VAL(opponentRight, MOVE_THUNDER,   AI_SCORE_DEFAULT,                    target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_THUNDER,   AI_SCORE_DEFAULT,                    target:playerRight);
            EXPECT_MOVE(opponentLeft,   MOVE_THUNDER,   target:playerRight);
            EXPECT_MOVE(opponentRight,  MOVE_BOLT_BEAK, target:playerRight);
        }
    }
}

AI_MULTI_BATTLE_TEST("AI does not target itself with selected moves in doubles (TARGET_SELECTED)")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SCORE_TIE_DOUBLES_TARGET);

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_FLAMETHROWER) == TARGET_SELECTED);
        AI_FLAGS(0);
        TIE_BREAK_TARGET(TARGET_TIE_CHOSEN, i % 3);
        PLAYER(SPECIES_TURTONATOR) { Speed(4); }
        PARTNER(SPECIES_TURTONATOR) { Speed(2); Moves(MOVE_FLAMETHROWER); }
        OPPONENT_A(SPECIES_TURTONATOR) { Speed(3); Moves(MOVE_FLAMETHROWER); }
        OPPONENT_B(SPECIES_TURTONATOR) { Speed(1); Moves(MOVE_FLAMETHROWER); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_FLAMETHROWER);
            EXPECT_MOVE(playerRight, MOVE_FLAMETHROWER);
            EXPECT_MOVE(opponentRight, MOVE_FLAMETHROWER);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAMETHROWER, opponentLeft);
        NOT HP_BAR(opponentLeft);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAMETHROWER, playerRight);
        NOT HP_BAR(playerRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAMETHROWER, opponentRight);
        NOT HP_BAR(opponentRight);
    }
}

AI_MULTI_BATTLE_TEST("AI does not target itself with selected moves in doubles (TARGET_FOES_AND_ALLY)")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SCORE_TIE_DOUBLES_TARGET);

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_LAVA_PLUME) == TARGET_FOES_AND_ALLY);
        AI_FLAGS(0);
        TIE_BREAK_TARGET(TARGET_TIE_CHOSEN, i % 3);
        PLAYER(SPECIES_TURTONATOR) { Speed(4); }
        PARTNER(SPECIES_TURTONATOR) { Speed(2); Moves(MOVE_LAVA_PLUME); }
        OPPONENT_A(SPECIES_TURTONATOR) { Speed(3); Moves(MOVE_LAVA_PLUME); }
        OPPONENT_B(SPECIES_TURTONATOR) { Speed(1); Moves(MOVE_LAVA_PLUME); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_LAVA_PLUME);
            EXPECT_MOVE(playerRight, MOVE_LAVA_PLUME);
            EXPECT_MOVE(opponentRight, MOVE_LAVA_PLUME);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LAVA_PLUME, opponentLeft);
        NOT HP_BAR(opponentLeft);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_LAVA_PLUME, playerRight);
        NOT HP_BAR(playerRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_LAVA_PLUME, opponentRight);
        NOT HP_BAR(opponentRight);
    }
}

AI_MULTI_BATTLE_TEST("AI does not target itself with selected moves in doubles (TARGET_BOTH)")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SCORE_TIE_DOUBLES_TARGET);

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HEAT_WAVE) == TARGET_BOTH);
        AI_FLAGS(0);
        TIE_BREAK_TARGET(TARGET_TIE_CHOSEN, i % 3);
        PLAYER(SPECIES_TURTONATOR) { Speed(4); }
        PARTNER(SPECIES_TURTONATOR) { Speed(2); Moves(MOVE_HEAT_WAVE); }
        OPPONENT_A(SPECIES_TURTONATOR) { Speed(3); Moves(MOVE_HEAT_WAVE); }
        OPPONENT_B(SPECIES_TURTONATOR) { Speed(1); Moves(MOVE_HEAT_WAVE); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_HEAT_WAVE);
            EXPECT_MOVE(playerRight, MOVE_HEAT_WAVE);
            EXPECT_MOVE(opponentRight, MOVE_HEAT_WAVE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAT_WAVE, opponentLeft);
        NOT HP_BAR(opponentLeft);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAT_WAVE, playerRight);
        NOT HP_BAR(playerRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAT_WAVE, opponentRight);
        NOT HP_BAR(opponentRight);
    }
}

AI_DOUBLE_BATTLE_TEST("AI does not switch in into invalid Pokemon")
{
    u64 flags = 0;

    PARAMETRIZE { flags = (AI_FLAG_ACE_POKEMON | AI_FLAG_SMART_TRAINER); }
    PARAMETRIZE { flags = AI_FLAG_ACE_POKEMON; }

    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Level(1); }
        OPPONENT(SPECIES_WYNAUT) { Level(1); }
        OPPONENT(SPECIES_HAPPINY) { Level(1); }
        OPPONENT(SPECIES_CHANSEY) { Level(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
        TURN { }
    }
}

AI_SINGLE_BATTLE_TEST("AI scores fixed damage moves correctly")
{
    enum Move move = MOVE_NONE;
    s32 hp = 400;

    ASSUME(GetMoveEffect(MOVE_SONIC_BOOM) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_SONIC_BOOM) == 20);
    ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);

    PARAMETRIZE { move = MOVE_SONIC_BOOM, hp = 20; }
    PARAMETRIZE { move = MOVE_SONIC_BOOM, hp = 60; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE, hp = 40; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE, hp = 60; }

    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_SCRATCH); MaxHP(hp); HP(hp); Defense(999); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Moves(MOVE_SCRATCH, move); }
    } WHEN {
        if (hp == 60)
        {
            TURN {
                EXPECT_MOVE(opponent, move);
                SCORE_EQ_VAL(opponent, MOVE_SCRATCH, AI_SCORE_DEFAULT);
                SCORE_EQ_VAL(opponent, move, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE);
            }
        }
        else
        {
            TURN {
                EXPECT_MOVE(opponent, move);
                SCORE_EQ_VAL(opponent, MOVE_SCRATCH, AI_SCORE_DEFAULT);
                SCORE_EQ_VAL(opponent, move, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL);
            }
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI calcs critical hit damage when a crit stage 3+ (Gen 6+)")
{
    enum Item item = ITEM_NONE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_SCOPE_LENS; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        WITH_CONFIG(B_CRIT_CHANCE, GEN_6);
        PLAYER(SPECIES_SHEDINJA);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FOCUS_ENERGY, MOVE_FROST_BREATH, MOVE_FREEZE_DRY); Item(item); }
    } WHEN {
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_FOCUS_ENERGY); }
        TURN {
            if (item == ITEM_SCOPE_LENS)
            {
                EXPECT_MOVE(opponent, MOVE_FREEZE_DRY);
            }
            else
            {
                EXPECT_MOVE(opponent, MOVE_FROST_BREATH);
            }
        }
    } 
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_ABILITY_OMNISCIENCE: AI knows the player's ability")
{
    u64 aiFlags;
    u32 passChance;
    PARAMETRIZE { passChance = 1; aiFlags = 0; }
    PARAMETRIZE { passChance = 3; aiFlags = AI_FLAG_ABILITY_OMNISCIENCE; }
    PASSES_RANDOMLY(passChance, 3, RNG_AI_ABILITY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiFlags);
        PLAYER(SPECIES_BRONZONG) { Ability(ABILITY_LEVITATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_SANDSLASH) { Moves(MOVE_EARTHQUAKE, MOVE_TACKLE); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponent, MOVE_TACKLE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_ITEM_OMNISCIENCE: AI knows the player's item")
{
    u64 aiFlags;
    PARAMETRIZE { aiFlags = 0; }
    PARAMETRIZE { aiFlags = AI_FLAG_ITEM_OMNISCIENCE; }
    GIVEN {
        ASSUME(IsPowderMove(MOVE_SPORE) == TRUE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiFlags);
        PLAYER(SPECIES_GULPIN) { Item(ITEM_SAFETY_GOGGLES); }
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_TACKLE); }
    } WHEN {
        if (aiFlags == AI_FLAG_ITEM_OMNISCIENCE)
            TURN { EXPECT_MOVE(opponent, MOVE_TACKLE); }
        else
            TURN { EXPECT_MOVE(opponent, MOVE_SPORE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_MOVE_OMNISCIENCE: AI knows the player's moves")
{
    u64 aiFlag = 0;
    PARAMETRIZE { aiFlag = 0; }
    PARAMETRIZE { aiFlag = AI_FLAG_MOVE_OMNISCIENCE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_FLAMETHROWER) == TYPE_FIRE);
        ASSUME(IsSpeciesOfType(SPECIES_TYPHLOSION, TYPE_FIRE));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | aiFlag);
        PLAYER(SPECIES_TYPHLOSION) { Speed(5); Moves(MOVE_TACKLE, MOVE_FLAMETHROWER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_TACKLE); Level(1); }
        OPPONENT(SPECIES_SCIZOR) { Speed(4); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_BLISSEY) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        if (aiFlag == AI_FLAG_MOVE_OMNISCIENCE)
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
        else
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will prefer not using recoil moves that will KO its own mon")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DOUBLE_EDGE) == EFFECT_RECOIL);
        ASSUME(GetMoveAccuracy(MOVE_STONE_EDGE) < 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { HP(50); Speed(1); Moves(MOVE_TACKLE, MOVE_PROTECT); }
        PLAYER(SPECIES_ZIGZAGOON) { Speed(1); } 
        OPPONENT(SPECIES_SANDSLASH) { Moves(MOVE_STONE_EDGE, MOVE_DOUBLE_EDGE); HP(1); MaxHP(100); Speed(2); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_STONE_EDGE); MOVE(player, MOVE_PROTECT); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI sees Dragon Darts damage correctly depending on the number of present targets")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_DRAGON_DARTS) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        ASSUME(GetMovePower(MOVE_DRAGON_DARTS) == 50);
        ASSUME(GetMoveCategory(MOVE_DRAGON_CLAW) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMovePower(MOVE_DRAGON_CLAW) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_DRATINI) { Speed(4); Moves(MOVE_PROTECT, MOVE_CELEBRATE); Level(60); }
        PLAYER(SPECIES_DRATINI) { Speed(3); Moves(MOVE_MEMENTO, MOVE_CELEBRATE); Level(60); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_DARTS, MOVE_DRAGON_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        TIE_BREAK_SCORE(RNG_AI_SCORE_TIE_DOUBLES_MOVE, SCORE_TIE_LO, 0);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_PROTECT);
            MOVE(playerRight, MOVE_MEMENTO, target: opponentRight);
            EXPECT_MOVE(opponentLeft, MOVE_DRAGON_CLAW);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_CLAW, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + SLOW_KILL, target: playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_CLAW, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + SLOW_KILL, target: playerRight);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_DARTS, AI_SCORE_DEFAULT, target: playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_DARTS, AI_SCORE_DEFAULT, target: playerRight);
        }
        TURN {
            EXPECT_MOVES(opponentLeft, MOVE_DRAGON_DARTS);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_DARTS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + SLOW_KILL, target: playerLeft);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_CLAW, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + SLOW_KILL, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI sees Dragon Darts damage redirecting if one target is immune")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_WIGGLYTUFF, ability = ABILITY_CONTRARY; }
    PARAMETRIZE { species = SPECIES_SHEDINJA, ability = ABILITY_WONDER_GUARD; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_DRAGON_DARTS) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        ASSUME(GetMovePower(MOVE_DRAGON_DARTS) == 50);
        ASSUME(GetMoveType(MOVE_FIRE_PUNCH) == TYPE_FIRE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(species) { Speed(4); Ability(ability); }
        PLAYER(SPECIES_DRATINI) { Speed(3); Level(60); } // Only 2 hit KOs at L60
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_DRAGON_DARTS, MOVE_FIRE_PUNCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
        TIE_BREAK_TARGET(TARGET_TIE_HI, 0);
        TIE_BREAK_SCORE(RNG_AI_SCORE_TIE_DOUBLES_MOVE, SCORE_TIE_LO, 0);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_DRAGON_DARTS);
            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_DARTS, AI_SCORE_DEFAULT + NO_DAMAGE_OR_FAILS + NO_DAMAGE_OR_FAILS, target: playerLeft); // for some reason this is getting 60 instead of 80

            if (species == SPECIES_SHEDINJA)
                SCORE_EQ_VAL(opponentLeft, MOVE_FIRE_PUNCH, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + SLOW_KILL, target: playerLeft);
            else
                SCORE_EQ_VAL(opponentLeft, MOVE_FIRE_PUNCH, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE, target: playerLeft);

            SCORE_EQ_VAL(opponentLeft, MOVE_DRAGON_DARTS, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + SLOW_KILL, target: playerRight);
            SCORE_EQ_VAL(opponentLeft, MOVE_FIRE_PUNCH, AI_SCORE_DEFAULT, target: playerRight);
        }
    }
}

TO_DO_BATTLE_TEST("AI doesn't see stomping tantrum as boosted for switch AI if its last move before fainting failed");
