#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_DREAM_EATER) == EFFECT_DREAM_EATER);
}

SINGLE_BATTLE_TEST("Dream Eater recovers 50% of the damage dealt")
{
    s16 damage;
    s16 healed;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(player, MOVE_DREAM_EATER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DREAM_EATER, player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-1.0/2.0), healed);
    }
}

SINGLE_BATTLE_TEST("Dream Eater fails on awake targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DREAM_EATER); }
    } SCENE {
        MESSAGE("Wobbuffet used Dream Eater!");
        MESSAGE("It doesn't affect the opposing Wobbuffet…");
    }
}

SINGLE_BATTLE_TEST("Dream Eater fails if Heal Block applies")
{
    GIVEN {
        ASSUME(B_HEAL_BLOCKING >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_DREAM_EATER); }
    } SCENE {
        MESSAGE("Wobbuffet was prevented from healing!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DREAM_EATER, player);
            HP_BAR(opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Dream Eater works on targets with Comatose")
{
    s16 damage;
    s16 healed;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DREAM_EATER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DREAM_EATER, player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-1.0/2.0), healed);
    }
}

SINGLE_BATTLE_TEST("Dream Eater fails if the target is behind a Substitute (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_DREAM_EATER_SUBSTITUTE, GEN_4);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(!MoveIgnoresSubstitute(MOVE_DREAM_EATER));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_YAWN); MOVE(player, MOVE_SUBSTITUTE); }
        TURN {}
        TURN { MOVE(opponent, MOVE_DREAM_EATER); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Dream Eater!");
        MESSAGE("It doesn't affect Wobbuffet…");
    }
}

SINGLE_BATTLE_TEST("Dream Eater works if the target is behind a Substitute (Gen 5+)")
{
    u16 damage;
    s16 healed;
    GIVEN {
        WITH_CONFIG(B_DREAM_EATER_SUBSTITUTE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(!MoveIgnoresSubstitute(MOVE_DREAM_EATER));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_YAWN); MOVE(player, MOVE_SUBSTITUTE); }
        TURN {}
        TURN { MOVE(opponent, MOVE_DREAM_EATER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DREAM_EATER, opponent);
        SUB_HIT(player, captureDamage: &damage);
        HP_BAR(opponent, captureDamage: &healed);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-1.0/2.0), healed);
    }
}
