#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_BODY_PRESS].effect == EFFECT_BODY_PRESS);
    ASSUME(gMovesInfo[MOVE_BODY_PRESS].category == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Body Press uses physical defense stat of target", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_DRILL_PECK; }
    PARAMETRIZE { move = MOVE_BODY_PRESS; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_DRILL_PECK].power == gMovesInfo[MOVE_BODY_PRESS].power);
        ASSUME(gMovesInfo[MOVE_CHARM].effect == EFFECT_ATTACK_DOWN_2);
        PLAYER(SPECIES_MEW);
        OPPONENT(SPECIES_SHELLDER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press's damage depends on the user's base Defense instead of its base Attack", s16 damage)
{
    u32 def, atk;
    PARAMETRIZE { def = 150; atk = 179; } // Atk is higher
    PARAMETRIZE { atk = 150; def = 179; } // Atk is lower
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Attack(atk); Defense(def); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press's damage depends on the user's Defense and not Attack stat stages", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { move = MOVE_SWORDS_DANCE; }
    PARAMETRIZE { move = MOVE_CELEBRATE; } // Nothing, stats are default
    GIVEN {
        ASSUME(gMovesInfo[MOVE_IRON_DEFENSE].effect == EFFECT_DEFENSE_UP_2);
        ASSUME(gMovesInfo[MOVE_SWORDS_DANCE].effect == EFFECT_ATTACK_UP_2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Attack(150); Defense(150); }
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
        EXPECT_EQ(results[1].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press uses Defense Stat even in Wonder Room", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_WONDER_ROOM; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_WONDER_ROOM].effect == EFFECT_WONDER_ROOM);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(50); Defense(150); }
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Body Press uses Special Defense stat Stages in Wonder Room", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_IRON_DEFENSE; }
    PARAMETRIZE { move = MOVE_AMNESIA; }
    PARAMETRIZE { move = MOVE_CELEBRATE; } // Nothing, stats are default
    GIVEN {
        ASSUME(gMovesInfo[MOVE_IRON_DEFENSE].effect == EFFECT_DEFENSE_UP_2);
        ASSUME(gMovesInfo[MOVE_AMNESIA].effect == EFFECT_SPECIAL_DEFENSE_UP_2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(150); Defense(150); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_WONDER_ROOM); }
        TURN { MOVE(opponent, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

// Could be split into multiple tests or maybe to separate files based on the modifier?
TO_DO_BATTLE_TEST("Body Press's damage is influenced by all other Attack modifiers that are not stat stages");
TO_DO_BATTLE_TEST("Body Press's damage is NOT influenced by any other Defense besides stat stages");

// Unconfirmed by Bulbapedia:
// - Defeatist interaction
