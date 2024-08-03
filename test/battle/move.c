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

DOUBLE_BATTLE_TEST("Turn order is determined randomly if priority and Speed tie [doubles]")
{
    struct BattlePokemon *order[4] = { NULL, NULL, NULL, NULL };
    u32 a, b, c, d;

    // TODO: Test all of these in a single PASSES_RANDOMLY pass rather
    // than 24 PARAMETRIZEd passes.
    PARAMETRIZE { a = 0; b = 1; c = 2; d = 3; }
    PARAMETRIZE { a = 0; b = 1; c = 3; d = 2; }
    PARAMETRIZE { a = 0; b = 2; c = 1; d = 3; }
    PARAMETRIZE { a = 0; b = 2; c = 3; d = 1; }
    PARAMETRIZE { a = 0; b = 3; c = 1; d = 2; }
    PARAMETRIZE { a = 0; b = 3; c = 2; d = 1; }
    PARAMETRIZE { a = 1; b = 0; c = 2; d = 3; }
    PARAMETRIZE { a = 1; b = 0; c = 3; d = 2; }
    PARAMETRIZE { a = 1; b = 2; c = 0; d = 3; }
    PARAMETRIZE { a = 1; b = 2; c = 3; d = 0; }
    PARAMETRIZE { a = 1; b = 3; c = 0; d = 2; }
    PARAMETRIZE { a = 1; b = 3; c = 2; d = 0; }
    PARAMETRIZE { a = 2; b = 0; c = 1; d = 3; }
    PARAMETRIZE { a = 2; b = 0; c = 3; d = 1; }
    PARAMETRIZE { a = 2; b = 1; c = 0; d = 3; }
    PARAMETRIZE { a = 2; b = 1; c = 3; d = 0; }
    PARAMETRIZE { a = 2; b = 3; c = 0; d = 1; }
    PARAMETRIZE { a = 2; b = 3; c = 1; d = 0; }
    PARAMETRIZE { a = 3; b = 0; c = 1; d = 2; }
    PARAMETRIZE { a = 3; b = 0; c = 2; d = 1; }
    PARAMETRIZE { a = 3; b = 1; c = 0; d = 2; }
    PARAMETRIZE { a = 3; b = 1; c = 2; d = 0; }
    PARAMETRIZE { a = 3; b = 2; c = 0; d = 1; }
    PARAMETRIZE { a = 3; b = 2; c = 1; d = 0; }

    order[a] = playerLeft;
    order[b] = playerRight;
    order[c] = opponentLeft;
    order[d] = opponentRight;

    PASSES_RANDOMLY(1, 24, RNG_SPEED_TIE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPLASH); MOVE(playerRight, MOVE_SPLASH); MOVE(opponentLeft, MOVE_SPLASH); MOVE(opponentRight, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, order[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, order[1]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, order[2]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, order[3]);
    }
}

SINGLE_BATTLE_TEST("Critical hits occur at a 1/24 rate")
{
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    PASSES_RANDOMLY(1, 24, RNG_CRITICAL_HIT);
    GIVEN {
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
    ASSUME(B_CRIT_CHANCE >= GEN_7);
    ASSUME(gMovesInfo[MOVE_SLASH].criticalHitStage == 1);
    PASSES_RANDOMLY(1, 8, RNG_CRITICAL_HIT);
    GIVEN {
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
