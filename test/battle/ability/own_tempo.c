#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Own Tempo doesn't prevent Intimidate (Gen3-7)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_7);
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
            MESSAGE("The opposing Slowpoke's Attack was not lowered!");
        }
    }
}

SINGLE_BATTLE_TEST("Own Tempo prevents Intimidate but no other stat down changes (Gen8+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_8);
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("The opposing Slowpoke's Attack was not lowered!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
            MESSAGE("The opposing Slowpoke's Attack was not lowered!");
        }
    }
}

SINGLE_BATTLE_TEST("Own Tempo prevents confusion from moves by the opponent")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("The opposing Slowpoke cannot be confused!");
    }
}

SINGLE_BATTLE_TEST("Own Tempo prevents confusion from moves by the user")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_PETAL_DANCE, MOVE_EFFECT_THRASH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        NONE_OF { MESSAGE("The opposing Slowpoke became confused due to fatigue!"); }
    }
}

SINGLE_BATTLE_TEST("Mold Breaker ignores Own Tempo")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        NOT MESSAGE("The opposing Slowpoke's Own Tempo prevents confusion!");
    }
}

SINGLE_BATTLE_TEST("Mold Breaker does not prevent Own Tempo from curing confusion right after")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("The opposing Slowpoke became confused!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("The opposing Slowpoke snapped out of its confusion!");
    }
}

SINGLE_BATTLE_TEST("Own Tempo cures confusion if it's obtained via Skill Swap")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
        TURN { MOVE(player, MOVE_SKILL_SWAP);
               MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("The opposing Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("The opposing Wobbuffet snapped out of its confusion!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Own Tempo prevents confusion from items")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_BERSERK_GENE].holdEffect == HOLD_EFFECT_BERSERK_GENE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); Item(ITEM_BERSERK_GENE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Own Tempo cured confusion should not persist toxic counter after switching")
{
    s16 firstTick, secondTick, postSwitchTick;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_TOXIC_POISON); MaxHP(160); HP(160); Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Speed(90); }
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); Speed(80); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, FALSE)); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        HP_BAR(player, captureDamage: &firstTick);
        HP_BAR(player, captureDamage: &secondTick);
        HP_BAR(player, captureDamage: &postSwitchTick);
    } THEN {
        EXPECT_EQ(firstTick, 10);
        EXPECT_EQ(secondTick, 20);
        EXPECT_EQ(postSwitchTick, 10);
    }
}
