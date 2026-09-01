#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Purifying Salt halves damage from Ghost-type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STURDY; }
    PARAMETRIZE { ability = ABILITY_PURIFYING_SALT; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GARGANACL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Purifying Salt halves damage from dynamic Ghost-type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STURDY; }
    PARAMETRIZE { ability = ABILITY_PURIFYING_SALT; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_GARGANACL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Purifying Salt makes Rest fail")
{
    GIVEN {
        PLAYER(SPECIES_GARGANACL) { Ability(ABILITY_PURIFYING_SALT); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NONE_OF {
            MESSAGE("Garganacl slept and restored its HP!");
        }
    }
}

SINGLE_BATTLE_TEST("Purifying Salt grants immunity to status effects")
{
    enum Move move;
    u16 status;
    PARAMETRIZE { move = MOVE_WILL_O_WISP; status = STATUS1_BURN; }
    PARAMETRIZE { move = MOVE_HYPNOSIS; status = STATUS1_SLEEP; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; status = STATUS1_PARALYSIS; }
    PARAMETRIZE { move = MOVE_TOXIC; status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { move = MOVE_POWDER_SNOW; status = STATUS1_FREEZE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(GetMoveEffect(MOVE_HYPNOSIS) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_HYPNOSIS) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(MoveHasAdditionalEffect(MOVE_POWDER_SNOW, MOVE_EFFECT_FREEZE_OR_FROSTBITE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PURIFYING_SALT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        if (move != MOVE_POWDER_SNOW) {
            NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
            ABILITY_POPUP(player, ABILITY_PURIFYING_SALT);
            MESSAGE("It doesn't affect Wobbuffet…");
            NOT STATUS_ICON(player, status);
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_PURIFYING_SALT);
                STATUS_ICON(player, status);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Purifying Salt user can't be poisoned by Toxic Spikes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GARGANACL) { Ability(ABILITY_PURIFYING_SALT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        SEND_IN_MESSAGE("Garganacl");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Purifying Salt doesn't prevent Pokémon from being poisoned by Toxic Spikes on switch-in if forced in by phazing with Mold Breaker")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GARGANACL) { Ability(ABILITY_PURIFYING_SALT); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        STATUS_ICON(player, STATUS1_POISON);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Purifying Salt protects from secondary effect burn")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_EMBER, MOVE_EFFECT_BURN));
        PLAYER(SPECIES_GARGANACL) { Ability(ABILITY_PURIFYING_SALT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        NOT STATUS_ICON(player, STATUS1_BURN);
    }
}
