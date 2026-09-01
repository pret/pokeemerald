#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Accuracy controls the proportion of misses")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_DYNAMIC_PUNCH; }
    PARAMETRIZE { move = MOVE_THUNDER; }
    PARAMETRIZE { move = MOVE_HYDRO_PUMP; }
    PARAMETRIZE { move = MOVE_RAZOR_LEAF; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    ASSUME(0 < GetMoveAccuracy(move) && GetMoveAccuracy(move) <= 100);
    PASSES_RANDOMLY(GetMoveAccuracy(move), 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}

SINGLE_BATTLE_TEST("AdditionalEffect.chance controls the proportion of secondary effects")
{
    enum Move move;
    u32 chance;
    PARAMETRIZE { move = MOVE_THUNDER_SHOCK; chance = 10; }
    PARAMETRIZE { move = MOVE_DISCHARGE; chance = 30; }
    PARAMETRIZE { move = MOVE_NUZZLE; chance = 100; }
    ASSUME(MoveHasAdditionalEffect(move, MOVE_EFFECT_PARALYSIS) == TRUE);
    PASSES_RANDOMLY(chance, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Turn order is determined by priority")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) > GetMovePriority(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Turn order is determined by Speed if priority ties")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
    }
}

SINGLE_BATTLE_TEST("Turn order is determined randomly if priority and Speed tie [singles]")
{
    PASSES_RANDOMLY(1, 2, RNG_SPEED_TIE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
    }
}

DOUBLE_BATTLE_TEST("Turn order is determined randomly if priority and Speed tie [doubles]", u32 permutations)
{
    PARAMETRIZE {} // Hack to make permutations legal.
    PASSES_RANDOMLY(24, 24, RNG_SPEED_TIE);

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENDEAVOR) == EFFECT_ENDEAVOR);
        ASSUME(GetMoveEffect(MOVE_LIFE_DEW) == EFFECT_LIFE_DEW);
        ASSUME(GetMoveEffect(MOVE_CRUSH_GRIP) == EFFECT_POWER_BASED_ON_TARGET_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(480); HP(360); Defense(100); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(100); Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ENDEAVOR, target: opponentLeft); MOVE(playerRight, MOVE_LIFE_DEW); MOVE(opponentLeft, MOVE_CRUSH_GRIP, target: playerLeft, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); MOVE(opponentRight, MOVE_SUPER_FANG, target: playerLeft); }
    } THEN {
        //  This tests for unique combinatins of HP values depending on which order the moves are executed in
        //  The unique outcomes arise from the specific attacks and HP, Def, and Atk values chosen
        //  The switch is then set up in such a way that the only way for this test to pass exactly one is for each HP combination to occur exactly once
#define HP_PAIR(a, b) ((a) * 1000 + (b))
        switch (HP_PAIR(playerLeft->hp, opponentLeft->hp))
        {
        case HP_PAIR(188, 360): results[i].permutations += 1 << 0; break;
        case HP_PAIR(189, 360): results[i].permutations += 1 << 1; break;
        case HP_PAIR(261, 360): results[i].permutations += 1 << 2; break;
        case HP_PAIR(235, 360): results[i].permutations += 1 << 3; break;
        case HP_PAIR(262, 360): results[i].permutations += 1 << 4; break;
        case HP_PAIR(202, 360): results[i].permutations += 1 << 5; break;
        case HP_PAIR(189, 378): results[i].permutations += 1 << 6; break;
        case HP_PAIR(189, 189): results[i].permutations += 1 << 7; break;
        case HP_PAIR(189, 480): results[i].permutations += 1 << 8; break;
        case HP_PAIR(188, 480): results[i].permutations += 1 << 9; break;
        case HP_PAIR(188, 240): results[i].permutations += 1 << 10; break;
        case HP_PAIR(188, 188): results[i].permutations += 1 << 11; break;
        case HP_PAIR(262, 262): results[i].permutations += 1 << 12; break;
        case HP_PAIR(262, 142): results[i].permutations += 1 << 13; break;
        case HP_PAIR(202, 403): results[i].permutations += 1 << 14; break;
        case HP_PAIR(202, 202): results[i].permutations += 1 << 15; break;
        case HP_PAIR(262, 283): results[i].permutations += 1 << 16; break;
        case HP_PAIR(202, 283): results[i].permutations += 1 << 17; break;
        case HP_PAIR(235, 180): results[i].permutations += 1 << 18; break;
        case HP_PAIR(261, 180): results[i].permutations += 1 << 19; break;
        case HP_PAIR(235, 235): results[i].permutations += 1 << 20; break;
        case HP_PAIR(235, 300): results[i].permutations += 1 << 21; break;
        case HP_PAIR(261, 141): results[i].permutations += 1 << 22; break;
        case HP_PAIR(261, 261): results[i].permutations += 1 << 23; break;
        }
#undef HP_PAIR
    } FINALLY {
        EXPECT_EQ(results[i].permutations, (1 << 24) - 1);
    }
}

SINGLE_BATTLE_TEST("Critical hits deal 100% (Gen 1-5) or 50% (Gen 6+) more damage", s16 damage)
{
    bool32 criticalHit;
    u32 genConfig;
    PARAMETRIZE { criticalHit = FALSE; genConfig = GEN_5; }
    PARAMETRIZE { criticalHit = TRUE;  genConfig = GEN_5; }
    PARAMETRIZE { criticalHit = TRUE;  genConfig = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_CRIT_MULTIPLIER, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: criticalHit); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Critical hits do not ignore positive stat stages", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HOWL; }
    PARAMETRIZE { move = MOVE_TAIL_WHIP; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_LT(results[0].damage, results[i].damage);
    }
}

SINGLE_BATTLE_TEST("Critical hits ignore negative stat stages", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HARDEN; }
    PARAMETRIZE { move = MOVE_GROWL; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i > 0)
            EXPECT_EQ(results[0].damage, results[i].damage);
    }
}

DOUBLE_BATTLE_TEST("Moves fail if they target the partner but they faint before the move could have been used")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); MOVE(playerLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
    }
}

MULTI_BATTLE_TEST("Ally switch fails when used by either side in a multibattle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ALLY_SWITCH); MOVE(opponentLeft, MOVE_ALLY_SWITCH); MOVE(opponentRight, MOVE_ALLY_SWITCH); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft); ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerRight); ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, opponentLeft); ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, opponentRight); }
    }
}

TWO_VS_ONE_BATTLE_TEST("Ally switch can only be used by the opponent in a 2v1 battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(playerRight, MOVE_ALLY_SWITCH); MOVE(opponentLeft, MOVE_ALLY_SWITCH); }
    } SCENE {
        { ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, opponentLeft); }
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft); ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerRight); }
    }
}

ONE_VS_TWO_BATTLE_TEST("Ally switch can only be used by the player in a 1v2 battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ALLY_SWITCH); MOVE(opponentLeft, MOVE_ALLY_SWITCH); MOVE(opponentRight, MOVE_ALLY_SWITCH); }
    } SCENE {
        { ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, playerLeft); }
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, opponentLeft); ANIMATION(ANIM_TYPE_MOVE, MOVE_ALLY_SWITCH, opponentRight); }
    }
}

DOUBLE_BATTLE_TEST("Moves do not fail if an alive partner is the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Moves fail if they target into a Pokémon that was fainted by the previous move")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_HYPER_VOICE);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
            SEND_OUT(opponentLeft, 2);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Moves that target the field are not going to fail if one mon fainted by the previous move")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); MOVE(playerLeft, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
    }
}
