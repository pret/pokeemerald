#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Accuracy controls the proportion of misses")
{
    u32 move;
    PARAMETRIZE { move = MOVE_DYNAMIC_PUNCH; }
    PARAMETRIZE { move = MOVE_THUNDER; }
    PARAMETRIZE { move = MOVE_HYDRO_PUMP; }
    PARAMETRIZE { move = MOVE_RAZOR_LEAF; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    ASSUME(0 < gMovesInfo[move].accuracy && gMovesInfo[move].accuracy <= 100);
    PASSES_RANDOMLY(gMovesInfo[move].accuracy, 100, RNG_ACCURACY);
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
    u32 move, chance;
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
        ASSUME(gMovesInfo[MOVE_QUICK_ATTACK].priority > gMovesInfo[MOVE_TACKLE].priority);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
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
        ASSUME(gMovesInfo[MOVE_ENDEAVOR].effect == EFFECT_ENDEAVOR);
        ASSUME(gMovesInfo[MOVE_LIFE_DEW].effect == EFFECT_JUNGLE_HEALING);
        ASSUME(gMovesInfo[MOVE_CRUSH_GRIP].effect == EFFECT_VARY_POWER_BASED_ON_HP);
        ASSUME(gMovesInfo[MOVE_SUPER_FANG].effect == EFFECT_SUPER_FANG);
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

SINGLE_BATTLE_TEST("Critical hits occur at a 1/24 rate")
{
    PASSES_RANDOMLY(1, 24, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(B_CRIT_CHANCE >= GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Slash's critical hits occur at a 1/8 rate")
{
    PASSES_RANDOMLY(1, 8, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(B_CRIT_CHANCE >= GEN_7);
        ASSUME(gMovesInfo[MOVE_SLASH].criticalHitStage == 1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLASH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Critical hits deal 50% more damage", s16 damage)
{
    bool32 criticalHit;
    PARAMETRIZE { criticalHit = FALSE; }
    PARAMETRIZE { criticalHit = TRUE; }
    GIVEN {
        ASSUME(B_CRIT_MULTIPLIER >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: criticalHit); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Critical hits do not ignore positive stat stages", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HOWL; }
    PARAMETRIZE { move = MOVE_TAIL_WHIP; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCRATCH].category == DAMAGE_CATEGORY_PHYSICAL);
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
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_HARDEN; }
    PARAMETRIZE { move = MOVE_GROWL; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCRATCH].category == DAMAGE_CATEGORY_PHYSICAL);
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
