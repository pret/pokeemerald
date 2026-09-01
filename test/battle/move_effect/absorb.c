#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Absorb recovers 50% of the damage dealt")
{
    s16 damage;
    s16 healed;
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-0.5), healed);
    }
}

// The animation makes the recording freeze. Changing it fixes it
SINGLE_BATTLE_TEST("Absorb fails if Heal Block applies")
{
    GIVEN {
        ASSUME(B_HEAL_BLOCKING >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_ABSORB); }
    } SCENE {
        MESSAGE("Wobbuffet was prevented from healing!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
            HP_BAR(opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Matcha Gatcha restores HP before applying burn to target")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_ABSORB));
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_BURN));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MATCHA_GOTCHA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MATCHA_GOTCHA, player);
        HP_BAR(opponent);
        HP_BAR(player); // recovery
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
        STATUS_ICON(opponent, burn: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Matcha Gatcha recovers 50% of the damage dealt from both targets")
{
    s16 damageLeft;
    s16 damageRight;
    s16 healedLeft;
    s16 healedRight;

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_PIKACHU) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STARYU);
        OPPONENT(SPECIES_STARYU);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MATCHA_GOTCHA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MATCHA_GOTCHA, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damageLeft);
        HP_BAR(opponentRight, captureDamage: &damageRight);
        HP_BAR(playerLeft, captureDamage: &healedLeft);
        HP_BAR(playerLeft, captureDamage: &healedRight);
    } THEN {
        EXPECT_MUL_EQ(damageLeft, Q_4_12(-0.5), healedLeft);
        EXPECT_MUL_EQ(damageRight, Q_4_12(-0.5), healedRight);
    }
}

SINGLE_BATTLE_TEST("Draining Kiss recovers 75% of the damage dealt")
{
    s16 damage;
    s16 healed;
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_DRAINING_KISS, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAINING_KISS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAINING_KISS, player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-0.75), healed);
    }
}

SINGLE_BATTLE_TEST("Absorb does not drain any HP if user flinched")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
            MESSAGE("The opposing Wobbuffet had its energy drained!");
        }
    }
}

SINGLE_BATTLE_TEST("Absorb recovers 50% of the damage dealt to a Substitute")
{
    u16 damage;
    s16 healing;
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, opponent);
        SUB_HIT(player, captureDamage: &damage);
        HP_BAR(opponent, captureDamage: &healing);
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(-0.5), healing);
    }
}

SINGLE_BATTLE_TEST("Absorb does not drain any HP if user does 0 damage")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        NOT MESSAGE("The opposing Wobbuffet had its energy drained!");
    }
}

SINGLE_BATTLE_TEST("Absorb does not drain any HP if the move is blocked by Disguise")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
    } THEN {
        EXPECT_EQ(player->hp, 1);
    }
}

DOUBLE_BATTLE_TEST("Spread Move: Heals the correct amount from all Pokemon")
{
    s16 damage[3];
    s16 healed[3];

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_PARABOLIC_CHARGE, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_RAICHU) { HP(1); }
        PLAYER(SPECIES_SQUIRTLE);
        OPPONENT(SPECIES_SQUIRTLE);
        OPPONENT(SPECIES_SQUIRTLE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PARABOLIC_CHARGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARABOLIC_CHARGE, playerLeft);

        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(playerRight, captureDamage: &damage[1]);
        HP_BAR(opponentRight, captureDamage: &damage[2]);

        HP_BAR(playerLeft, captureDamage: &healed[0]);
        HP_BAR(playerLeft, captureDamage: &healed[1]);
        HP_BAR(playerLeft, captureDamage: &healed[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(-0.5), healed[0]);
        EXPECT_MUL_EQ(damage[1], Q_4_12(-0.5), healed[1]);
        EXPECT_MUL_EQ(damage[2], Q_4_12(-0.5), healed[2]);
    }
}


SINGLE_BATTLE_TEST("Absorb does not play the draining message at full HP in Gen5+")
{
    u32 genConfig = 0;

    PARAMETRIZE { genConfig = GEN_4; }
    PARAMETRIZE { genConfig = GEN_5; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        WITH_CONFIG(B_ABSORB_MESSAGE, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        if (genConfig < GEN_5)
            MESSAGE("The opposing Wobbuffet had its energy drained!");
        else
            NOT MESSAGE("The opposing Wobbuffet had its energy drained!");
    }
}
