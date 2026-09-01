#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveAdditionalEffectById(MOVE_ORDER_UP, 0)->moveEffect == MOVE_EFFECT_ORDER_UP);
}

DOUBLE_BATTLE_TEST("Order Up increases a stat based on Tatsugiri's form")
{
    enum Species species = SPECIES_NONE;
    PARAMETRIZE { species = SPECIES_TATSUGIRI_CURLY; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI_DROOPY; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI_STRETCHY; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_HAZE); MOVE(playerRight, MOVE_ORDER_UP, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponentRight); // Remove previous stat boosts
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ORDER_UP, playerRight);
        switch (species)
        {
        case SPECIES_TATSUGIRI_CURLY:
            MESSAGE("Dondozo's Attack rose!");
            break;
        case SPECIES_TATSUGIRI_DROOPY:
            MESSAGE("Dondozo's Defense rose!");
            break;
        case SPECIES_TATSUGIRI_STRETCHY:
            MESSAGE("Dondozo's Speed rose!");
            break;
        default:
            break;
        }
    } THEN {
        switch (species)
        {
        case SPECIES_TATSUGIRI_CURLY:
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
            break;
        case SPECIES_TATSUGIRI_DROOPY:
            EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
            break;
        case SPECIES_TATSUGIRI_STRETCHY:
            EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
            break;
        default:
            break;
        }
    }
}

DOUBLE_BATTLE_TEST("Order Up increases a stat based on Tatsugiri's form even if Tatsugiri fainted inside Dondozo")
{
    enum Species species = SPECIES_NONE;
    PARAMETRIZE { species = SPECIES_TATSUGIRI_CURLY; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI_DROOPY; }
    PARAMETRIZE { species = SPECIES_TATSUGIRI_STRETCHY; }

    GIVEN {
        PLAYER(species) { HP(1); Status1(STATUS1_POISON); Ability(ABILITY_COMMANDER); }
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN {}
        TURN { MOVE(opponentRight, MOVE_HAZE); MOVE(playerRight, MOVE_ORDER_UP, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_COMMANDER);
        MESSAGE("Tatsugiri was swallowed by Dondozo and became Dondozo's commander!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Tatsugiri was hurt by its poisoning!");
        MESSAGE("Tatsugiri fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, opponentRight); // Remove previous stat boosts
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ORDER_UP, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        switch (species)
        {
        case SPECIES_TATSUGIRI_CURLY:
            MESSAGE("Dondozo's Attack rose!");
            break;
        case SPECIES_TATSUGIRI_DROOPY:
            MESSAGE("Dondozo's Defense rose!");
            break;
        case SPECIES_TATSUGIRI_STRETCHY:
            MESSAGE("Dondozo's Speed rose!");
            break;
        default:
            break;
        }
    } THEN {
        switch (species)
        {
        case SPECIES_TATSUGIRI_CURLY:
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
            break;
        case SPECIES_TATSUGIRI_DROOPY:
            EXPECT_EQ(playerRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
            break;
        case SPECIES_TATSUGIRI_STRETCHY:
            EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
            break;
        default:
            break;
        }
    }
}

DOUBLE_BATTLE_TEST("Order up does not boosts any stats if Dondozo is not affected by Commander")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DONDOZO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ORDER_UP, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
   }
}

DOUBLE_BATTLE_TEST("Order Up is boosted by Sheer Force without removing the stat boosting effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENTRAINMENT) == EFFECT_ENTRAINMENT);
        PLAYER(SPECIES_DONDOZO) { Speed(10); }
        PLAYER(SPECIES_TATSUGIRI_CURLY) { Speed(9); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_TAUROS) { Speed(21); Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ENTRAINMENT, target: playerLeft); MOVE(playerLeft, MOVE_ORDER_UP, target: opponentLeft); }
    } SCENE {
        MESSAGE("The opposing Tauros used Entrainment!");
        MESSAGE("Dondozo acquired Sheer Force!");
        MESSAGE("Dondozo used Order Up!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
    }
}
DOUBLE_BATTLE_TEST("Order Up is always boosted by Sheer Force", s16 damage)
{
    enum Move move;
    enum Ability ability;
    PARAMETRIZE(move = MOVE_CELEBRATE, ability = ABILITY_STORM_DRAIN);
    PARAMETRIZE(move = MOVE_ENTRAINMENT, ability = ABILITY_STORM_DRAIN);
    PARAMETRIZE(move = MOVE_ENTRAINMENT, ability = ABILITY_COMMANDER);

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAZE) == EFFECT_HAZE);
        ASSUME(GetMoveEffect(MOVE_ENTRAINMENT) == EFFECT_ENTRAINMENT);
        PLAYER(SPECIES_DONDOZO) { Speed(10); }
        PLAYER(SPECIES_TATSUGIRI_CURLY) { Speed(9); Ability(ability); }
        OPPONENT(SPECIES_TAUROS) { Speed(21); Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(22); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_HAZE);
               MOVE(opponentLeft, move, target: playerLeft);
               MOVE(playerLeft, MOVE_ORDER_UP, target: opponentRight); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Haze!");
        if (move == MOVE_ENTRAINMENT)
        {
            MESSAGE("The opposing Tauros used Entrainment!");
            MESSAGE("Dondozo acquired Sheer Force!");
        }
        MESSAGE("Dondozo used Order Up!");
        HP_BAR(opponentRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.3), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.3), results[2].damage);
    }
}
