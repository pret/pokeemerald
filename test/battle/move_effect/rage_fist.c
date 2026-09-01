#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_RAGE_FIST) == EFFECT_RAGE_FIST);
    ASSUME(GetMovePower(MOVE_RAGE_FIST) == 50);
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased by 50 if the user takes damage")
{
    u8 turns;
    s16 timesGotHit[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        for (turns = 0; turns < 2; turns++) {
            TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_SCRATCH); }
        }
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
            HP_BAR(opponent, captureDamage: &timesGotHit[turns]);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased by each multi hit")
{
    u8 turns;
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_BULLET_SEED));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        for (turns = 0; turns < 2; turns++) {
            TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_BULLET_SEED); }
        }
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
            HP_BAR(opponent, captureDamage: &timesGotHit[turns]);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, opponent);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(6.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is not increased by a confusion hit")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN {}
        TURN { MOVE(player, MOVE_RAGE_FIST, WITH_RNG(RNG_CONFUSION, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("It hurt itself in its confusion!");
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_EQ(timesGotHit[0], timesGotHit[1]);
    }
}

DOUBLE_BATTLE_TEST("Rage Fist maximum base power is 350")
{
    u16 turns;
    s16 timesGotHit[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_REGIROCK);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (turns = 1; turns <= 3; turns++) {
            TURN {
                if (turns == 1)
                    MOVE(playerLeft, MOVE_RAGE_FIST, target: opponentLeft);

                MOVE(playerRight, MOVE_SCRATCH, target: playerLeft);
                MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
                MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
            }
        }
        TURN { MOVE(playerLeft, MOVE_RAGE_FIST, target: opponentLeft); }
    } SCENE {
        for (turns = 1; turns <= 3; turns++) {
            if (turns == 1) {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, playerLeft);
                HP_BAR(opponentLeft, captureDamage: &timesGotHit[0]);
            }
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
            HP_BAR(playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
            HP_BAR(playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
            HP_BAR(playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(7.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist hit counter does not wrap after 32 hits")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POPULATION_BOMB) == EFFECT_POPULATION_BOMB);
        ASSUME(GetMoveStrikeCount(MOVE_POPULATION_BOMB) == 10);
        ASSUME(GetMoveStrikeCount(MOVE_DOUBLE_HIT) == 2);
        PLAYER(SPECIES_WOBBUFFET) { HP(9999); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(9999); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_POPULATION_BOMB); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
        TURN { MOVE(opponent, MOVE_POPULATION_BOMB); }
        TURN { MOVE(opponent, MOVE_POPULATION_BOMB); }
        TURN { MOVE(opponent, MOVE_DOUBLE_HIT); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is not increased if a substitute was hit")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(GetMoveCategory(MOVE_CRUNCH) == DAMAGE_CATEGORY_PHYSICAL); // Substitute doesn't fade otherwise
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); }
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_CRUNCH); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, opponent);
        MESSAGE("The substitute took damage for Wobbuffet!");
        MESSAGE("Wobbuffet's substitute faded!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_EQ(timesGotHit[0], timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is not lost if user switches out (Gen9)")
{
    s16 timesGotHit[2];

    GIVEN {
        WITH_CONFIG(B_RAGE_FIST, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        SWITCH_OUT_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is lost if user switches out (Champions)")
{
    s16 timesGotHit[2];

    GIVEN {
        WITH_CONFIG(B_RAGE_FIST, GEN_CHAMPIONS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        SWITCH_OUT_MESSAGE("Wobbuffet");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        SWITCH_OUT_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(1.0), timesGotHit[0]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased by 50 even if a damaging move does no damage - False Swipe")
{
    u8 turns;
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        for (turns = 0; turns < 2; turns++) {
            TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_FALSE_SWIPE); }
        }
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
            HP_BAR(opponent, captureDamage: &timesGotHit[turns]);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased by 50 even if a damaging move does no damage - Endure")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        ASSUME(GetMoveEffect(MOVE_ENDURE) == EFFECT_ENDURE);
        PLAYER(SPECIES_WOBBUFFET) { HP(2); }
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_FALSE_SWIPE); }
        TURN { MOVE(player, MOVE_ENDURE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(3.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is not increased if move had no affect")
{
    u8 turns;
    s16 timesGotHit[2];

    GIVEN {
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        for (turns = 0; turns < 2; turns++) {
            TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_SCRATCH); }
        }
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
            HP_BAR(opponent, captureDamage: &timesGotHit[turns]);
            MESSAGE("The opposing Regirock used Scratch!");
            MESSAGE("It doesn't affect Gastly…");
        }
    } THEN {
        EXPECT_EQ(timesGotHit[0], timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased if Disguise breaks (Gen7)")
{
    s16 timesGotHit[2];
    enum Species species = SPECIES_NONE;

    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }

    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_7);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_ROCK_THROW); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased if Disguise breaks (Gen8+)")
{
    s16 timesGotHit[2];
    enum Species species = SPECIES_NONE;

    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }

    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_8);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_ROCK_THROW); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist number of hits is copied by Transform")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_REGIROCK) { Moves(MOVE_RAGE_FIST, MOVE_CELEBRATE); }
    } WHEN {
            TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_CELEBRATE); }
            TURN { MOVE(player, MOVE_TRANSFORM); MOVE(opponent, MOVE_CELEBRATE); }
            TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist base power is increased by 50 if user was hit and forces out")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_REGIROCK);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAGE_FIST); MOVE(player, MOVE_DRAGON_TAIL); }
        TURN { SWITCH(opponent, 0); }
        TURN { MOVE(opponent, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, opponent);
        HP_BAR(player, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, opponent);
        HP_BAR(player, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist doesn't get increased power if Substitute is hit")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAGE_FIST); }
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, opponent);
        HP_BAR(player, captureDamage: &timesGotHit[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, opponent);
        HP_BAR(player, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_EQ(timesGotHit[0], timesGotHit[1]);
    }
}

SINGLE_BATTLE_TEST("Rage Fist counter will be updated correctly after absorb move")
{
    s16 timesGotHit[2];

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_GIGA_DRAIN, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAGE_FIST); MOVE(opponent, MOVE_GIGA_DRAIN); }
        TURN { MOVE(player, MOVE_RAGE_FIST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_GIGA_DRAIN, opponent);
        HP_BAR(player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_FIST, player);
        HP_BAR(opponent, captureDamage: &timesGotHit[1]);
    } THEN {
        EXPECT_MUL_EQ(timesGotHit[0], Q_4_12(2.0), timesGotHit[1]);
    }
}
