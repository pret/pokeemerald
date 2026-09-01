#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ME_FIRST) == EFFECT_ME_FIRST);
}

SINGLE_BATTLE_TEST("Me First copies the move from the target and increases it's power by 1.5", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_ME_FIRST; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Me First fails if target uses a status move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ME_FIRST); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        MESSAGE("Wobbuffet used Me First!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Me First fails if target moves first")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_ME_FIRST); }
    } SCENE {
        MESSAGE("Wobbuffet used Me First!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Me First: If a Consecutively Executed Move is copied, the boost only applies to the first hit")
{
    s16 dmg[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_ME_FIRST); MOVE(opponent, MOVE_OUTRAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ME_FIRST, player);
        HP_BAR(opponent, captureDamage: &dmg[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OUTRAGE, player);
        HP_BAR(opponent, captureDamage: &dmg[1]);
    } THEN {
        EXPECT_MUL_EQ(dmg[1], Q_4_12(1.5), dmg[0]);
    }
}

SINGLE_BATTLE_TEST("Me First can be selected if users holds Assault Vest")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Item(ITEM_ASSAULT_VEST); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_ME_FIRST); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ME_FIRST, player);
    }
}

SINGLE_BATTLE_TEST("Me First can be selected under Taunt in Gen5+")
{
    u32 gen = 0;

    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_TAUNT_ME_FIRST, gen);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_ME_FIRST, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_TAUNT, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TAUNT); }
        if (gen >= GEN_5) {
            TURN { MOVE(player, MOVE_ME_FIRST); MOVE(opponent, MOVE_TACKLE); }
        } else {
            TURN {
                MOVE(player, MOVE_ME_FIRST, allowed: FALSE);
                MOVE(player, MOVE_TACKLE);
                MOVE(opponent, MOVE_TACKLE);
            }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponent);
        if (gen >= GEN_5)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ME_FIRST, player);
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Me First deducts power points from itself, not the copied move")
{
    ASSUME(GetMovePP(MOVE_ME_FIRST) == 20);
    ASSUME(GetMovePP(MOVE_POUND) == 35);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_ME_FIRST); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_ME_FIRST); MOVE(opponent, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ME_FIRST, player);
    } THEN {
        EXPECT_EQ(opponent->pp[0], 34);
        EXPECT_EQ(player->pp[0], 19);
    }
}

// TO_DO_BATTLE_TEST: Not everything has been tested
