#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Infiltrator bypasses the opponent's Light Screen/Reflect/Aurora Veil", s16 damage)
{
    enum Move screenMove, attackingMove;
    enum Ability ability;

    PARAMETRIZE { screenMove = MOVE_LIGHT_SCREEN; attackingMove = MOVE_WATER_GUN; ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { screenMove = MOVE_LIGHT_SCREEN; attackingMove = MOVE_WATER_GUN; ability = ABILITY_CLEAR_BODY;  }
    PARAMETRIZE { screenMove = MOVE_REFLECT;      attackingMove = MOVE_SCRATCH;   ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { screenMove = MOVE_REFLECT;      attackingMove = MOVE_SCRATCH;   ability = ABILITY_CLEAR_BODY;  }
    PARAMETRIZE { screenMove = MOVE_AURORA_VEIL;  attackingMove = MOVE_WATER_GUN; ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { screenMove = MOVE_AURORA_VEIL;  attackingMove = MOVE_WATER_GUN; ability = ABILITY_CLEAR_BODY;  }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LIGHT_SCREEN) == EFFECT_LIGHT_SCREEN);
        ASSUME(GetMoveEffect(MOVE_REFLECT) == EFFECT_REFLECT);
        ASSUME(GetMoveEffect(MOVE_AURORA_VEIL) == EFFECT_AURORA_VEIL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        OPPONENT(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
    } WHEN {
        TURN { MOVE(opponent, screenMove); MOVE(player, attackingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, screenMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, attackingMove, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, UQ_4_12(0.5), results[3].damage);
        EXPECT_MUL_EQ(results[4].damage, UQ_4_12(0.5), results[5].damage);
    }
}

DOUBLE_BATTLE_TEST("Infiltrator doesn't bypass an ally's Light Screen/Reflect/Aurora Veil", s16 damage)
{
    enum Move screenMove, attackingMove;
    enum Ability ability;

    PARAMETRIZE { screenMove = MOVE_LIGHT_SCREEN; attackingMove = MOVE_WATER_GUN; ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { screenMove = MOVE_LIGHT_SCREEN; attackingMove = MOVE_WATER_GUN; ability = ABILITY_CLEAR_BODY;  }
    PARAMETRIZE { screenMove = MOVE_REFLECT;      attackingMove = MOVE_SCRATCH;   ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { screenMove = MOVE_REFLECT;      attackingMove = MOVE_SCRATCH;   ability = ABILITY_CLEAR_BODY;  }
    PARAMETRIZE { screenMove = MOVE_AURORA_VEIL;  attackingMove = MOVE_WATER_GUN; ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { screenMove = MOVE_AURORA_VEIL;  attackingMove = MOVE_WATER_GUN; ability = ABILITY_CLEAR_BODY;  }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LIGHT_SCREEN) == EFFECT_LIGHT_SCREEN);
        ASSUME(GetMoveEffect(MOVE_REFLECT) == EFFECT_REFLECT);
        ASSUME(GetMoveEffect(MOVE_AURORA_VEIL) == EFFECT_AURORA_VEIL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, screenMove); MOVE(playerLeft, attackingMove, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, screenMove, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, attackingMove, playerLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_EQ(results[4].damage, results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Infiltrator bypasses the opponent's Mist")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIST) == EFFECT_MIST);
        ASSUME_STAT_CHANGE(MOVE_SCREECH, defense: -2);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); MOVE(player, MOVE_SCREECH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponent);
        if (ability == ABILITY_INFILTRATOR)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
    }
}

DOUBLE_BATTLE_TEST("Infiltrator doesn't bypass an ally's Mist")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIST) == EFFECT_MIST);
        ASSUME_STAT_CHANGE(MOVE_SCREECH, defense: -2);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ABILITY_INFILTRATOR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_MIST); MOVE(playerLeft, MOVE_SCREECH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Infiltrator bypasses the opponent's Safeguard")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAFEGUARD); MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, opponent);
        if (ability == ABILITY_INFILTRATOR)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
    }
}

DOUBLE_BATTLE_TEST("Infiltrator doesn't bypass an ally's Safeguard - Thunder Wave")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ABILITY_INFILTRATOR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SAFEGUARD); MOVE(playerLeft, MOVE_THUNDER_WAVE, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Infiltrator doesn't bypass an ally's Safeguard - Confuse")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ABILITY_INFILTRATOR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SAFEGUARD); MOVE(playerLeft, MOVE_CONFUSE_RAY, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Infiltrator bypasses the opponent's Substitute (Gen 6+)")
{
    enum Ability ability; u32 config;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; config = GEN_6; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; config = GEN_6; }

    GIVEN {
        WITH_CONFIG(B_INFILTRATOR_SUBSTITUTE, config);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(!MoveIgnoresSubstitute(MOVE_SCRATCH));
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        if (ability == ABILITY_INFILTRATOR && config >= GEN_6) {
            NOT SUB_HIT(opponent);
        } else {
            SUB_HIT(opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Infiltrator bypasses an ally's Substitute (Gen 6+)")
{
    enum Ability ability; u32 config;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; config = GEN_5; }
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; config = GEN_6; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; config = GEN_6; }

    GIVEN {
        WITH_CONFIG(B_INFILTRATOR_SUBSTITUTE, config);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(!MoveIgnoresSubstitute(MOVE_SCRATCH));
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SUBSTITUTE); MOVE(playerLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerRight);
        if (ability == ABILITY_INFILTRATOR && config == GEN_6) {
            NOT SUB_HIT(playerRight);
        } else {
            SUB_HIT(playerRight);
        }
    }
}

SINGLE_BATTLE_TEST("Infiltrator doesn't ignore a battler's Substitute when using Transform or Sky Drop")
{
    enum Ability ability; enum Move move;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY;  move = MOVE_TRANSFORM; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; move = MOVE_TRANSFORM; }
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY;  move = MOVE_SKY_DROP;  }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; move = MOVE_SKY_DROP;  }

    GIVEN {
        WITH_CONFIG(B_INFILTRATOR_SUBSTITUTE, GEN_6);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
    }
}
