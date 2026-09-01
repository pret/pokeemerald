#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_MULTI_BATTLE_TEST("AI will only explode and kill everything on the field with Risky or Will Suicide (multi)")
{
    ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
    ASSUME(IsExplosionMove(MOVE_EXPLOSION));

    u32 aiFlags;
    struct BattlePokemon *battler = NULL;
    struct BattlePokemon *partner = NULL;

    PARAMETRIZE { aiFlags = 0; battler = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { aiFlags = 0; battler = opponentRight; partner = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentRight; partner = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentRight; partner = opponentLeft; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(battler, aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT_A(SPECIES_VOLTORB) { Moves(MOVE_EXPLOSION, MOVE_HYPER_VOICE); HP(1); }
        OPPONENT_B(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_HYPER_VOICE); HP(1); }
    } WHEN {
        if (aiFlags == 0)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_HYPER_VOICE); EXPECT_MOVE(opponentRight, MOVE_HYPER_VOICE); }
        else
            TURN { EXPECT_MOVE(partner, MOVE_HYPER_VOICE); EXPECT_MOVE(battler, MOVE_EXPLOSION); }
    }
}

AI_ONE_VS_TWO_BATTLE_TEST("AI will only explode and kill everything on the field with Risky or Will Suicide (1v2)")
{
    ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
    ASSUME(IsExplosionMove(MOVE_EXPLOSION));

    u32 aiFlags;
    struct BattlePokemon *battler = NULL;
    struct BattlePokemon *partner = NULL;

    PARAMETRIZE { aiFlags = 0; battler = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { aiFlags = 0; battler = opponentRight; partner = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentRight; partner = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentRight; partner = opponentLeft; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(battler, aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT_A(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); HP(1); }
        OPPONENT_B(SPECIES_VOLTORB) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); HP(1); }
    } WHEN {
        if (aiFlags == 0)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_ELECTRO_BALL, target: playerLeft); EXPECT_MOVE(opponentRight, MOVE_ELECTRO_BALL, target: playerLeft); }
        else
            TURN { EXPECT_MOVE(partner, MOVE_ELECTRO_BALL, target: playerLeft); EXPECT_MOVE(battler, MOVE_EXPLOSION); }
    }
}

// Used to test EXPECT_MOVE only on partner
AI_MULTI_BATTLE_TEST("AI partner makes sensible move selections in battle (multi)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_HAUNTER);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL, MOVE_AURA_SPHERE); }
        OPPONENT_A(SPECIES_RATTATA) { Moves(MOVE_CELEBRATE); HP(1); }
        OPPONENT_B(SPECIES_KANGASKHAN) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AURA_SPHERE, target:opponentRight); EXPECT_MOVE(playerRight, MOVE_AURA_SPHERE, target:opponentLeft); }
    }
}

// Used to test EXPECT_MOVE only on partner
AI_TWO_VS_ONE_BATTLE_TEST("AI partner makes sensible move selections in battle (2v1)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_HAUNTER);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL, MOVE_AURA_SPHERE); }
        OPPONENT_A(SPECIES_RATTATA) { Moves(MOVE_CELEBRATE); HP(1); }
        OPPONENT_A(SPECIES_KANGASKHAN) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AURA_SPHERE, target:opponentRight); EXPECT_MOVE(playerRight, MOVE_AURA_SPHERE, target:opponentLeft); }
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("Battler 3 has Battler 1 AI flags set correctly (2v1)")
{
    ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
    ASSUME(IsExplosionMove(MOVE_EXPLOSION));

    u32 aiFlags;
    struct BattlePokemon *battler = NULL;

    PARAMETRIZE { aiFlags = 0; battler = opponentLeft; }
    PARAMETRIZE { aiFlags = 0; battler = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentRight; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(battler, aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT_A(SPECIES_VOLTORB) { Moves(MOVE_EXPLOSION, MOVE_HYPER_VOICE); HP(1); }
        OPPONENT_A(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_HYPER_VOICE); HP(1); }
    } WHEN {
        TURN {
            if (aiFlags == 0 || battler == opponentRight) {
                NOT_EXPECT_MOVE(opponentLeft, MOVE_EXPLOSION);
                NOT_EXPECT_MOVE(opponentRight, MOVE_EXPLOSION);
            }
            else {
                NOT_EXPECT_MOVE(opponentLeft, MOVE_HYPER_VOICE);
                NOT_EXPECT_MOVE(opponentRight, MOVE_HYPER_VOICE);
            }
        }
    }
}

AI_MULTI_BATTLE_TEST("Partner will not steal your pokemon when running out")
{

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WYNAUT) { Moves(MOVE_MEMENTO); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_MEMENTO, target:opponentLeft); }
        TURN {}
    } THEN {
        EXPECT_EQ(IsBattlerAlive(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)), FALSE);
    }
}

AI_MULTI_BATTLE_TEST("Partner will not steal your pokemon to delay using their ace")
{

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(playerRight, AI_FLAG_ACE_POKEMON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WYNAUT) { Moves(MOVE_MEMENTO); }
        PARTNER(SPECIES_METAGROSS) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_MEMENTO, target:opponentLeft); }
        TURN {}
    } THEN {
        EXPECT_EQ(SPECIES_METAGROSS, playerRight->species);
    }
}

AI_MULTI_BATTLE_TEST("AI opponents do not steal their partner pokemon in multi battle to delay using their ace")
{

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(opponentLeft, AI_FLAG_ACE_POKEMON);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); HP(1); }
        OPPONENT_A(SPECIES_VENUSAUR) { Moves(MOVE_GIGA_DRAIN); }
        OPPONENT_B(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
    } THEN {
        EXPECT_EQ(SPECIES_VENUSAUR, opponentLeft->species);
    }
}

AI_MULTI_BATTLE_TEST("AI opponents do not steal their partner pokemon in multi battle when forced out")
{
    enum Item item;
    enum Move move;
    PARAMETRIZE { item = ITEM_EJECT_BUTTON; move = MOVE_TACKLE; }
    PARAMETRIZE { item = ITEM_EJECT_PACK; move = MOVE_TAIL_WHIP; }
    PARAMETRIZE { item = ITEM_NONE; move = MOVE_ROAR; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(opponentLeft, AI_FLAG_ACE_POKEMON);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); Item(item); }
        OPPONENT_A(SPECIES_VENUSAUR) { Moves(MOVE_GIGA_DRAIN); }
        OPPONENT_B(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
    } THEN {
        EXPECT_EQ(SPECIES_VENUSAUR, opponentLeft->species);
    }
}

AI_MULTI_BATTLE_TEST("AI opponents do not steal their partner pokemon in multi battle when forced out 2")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(opponentLeft, AI_FLAG_ACE_POKEMON);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_GOLISOPOD) { Moves(MOVE_CELEBRATE); HP(101); MaxHP(200); Ability(ABILITY_EMERGENCY_EXIT); }
        OPPONENT_A(SPECIES_VENUSAUR) { Moves(MOVE_GIGA_DRAIN); }
        OPPONENT_B(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
    } THEN {
        EXPECT_EQ(SPECIES_VENUSAUR, opponentLeft->species);
    }
}

AI_MULTI_BATTLE_TEST("Pollen Puff: AI correctly scores moves with EFFECT_HIT_ENEMY_HEAL_ALLY as damaging opponents but not allies")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        ASSUME(GetMoveEffect(MOVE_POLLEN_PUFF) == EFFECT_HIT_ENEMY_HEAL_ALLY);
        // Speed tie so all think they are faster
        PLAYER(SPECIES_WOBBUFFET)     { Speed(1); HP(50); Moves(MOVE_POLLEN_PUFF, MOVE_CELEBRATE); }
        PARTNER(SPECIES_WOBBUFFET)    { Speed(1); HP(50); Moves(MOVE_POLLEN_PUFF);                 }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(1); HP(50); Moves(MOVE_POLLEN_PUFF);                 }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); HP(50); Moves(MOVE_POLLEN_PUFF);                 }
    } WHEN {
        TURN {
            // Targeting ally
            SCORE_EQ_VAL(opponentLeft,  MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + WEAK_EFFECT, target:opponentRight);
            SCORE_EQ_VAL(playerRight,   MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + WEAK_EFFECT, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + WEAK_EFFECT, target:opponentLeft);

            // Targeting opponent
            SCORE_EQ_VAL(opponentLeft,  MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:playerLeft);
            SCORE_EQ_VAL(opponentLeft,  MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:playerRight);
            SCORE_EQ_VAL(playerRight,   MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:opponentLeft);
            SCORE_EQ_VAL(playerRight,   MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:opponentRight);
            SCORE_EQ_VAL(opponentRight, MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:playerLeft);
            SCORE_EQ_VAL(opponentRight, MOVE_POLLEN_PUFF, AI_SCORE_DEFAULT + BEST_DAMAGE_MOVE + FAST_KILL, target:playerRight);
        }
    }
}

AI_MULTI_BATTLE_TEST("Battler 2 has AI flags set correctly (multi)")
{
    ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
    ASSUME(IsExplosionMove(MOVE_EXPLOSION));

    u32 aiFlags;

    PARAMETRIZE { aiFlags = 0; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(playerRight, aiFlags);
        PLAYER(SPECIES_VOLTORB) { Moves(MOVE_CELEBRATE); HP(1); }
        PARTNER(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); HP(1); }
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
        if (aiFlags == 0)
            TURN { EXPECT_MOVE(playerRight, MOVE_ELECTRO_BALL); }
        else
            TURN { EXPECT_MOVE(playerRight, MOVE_EXPLOSION); }
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("Battler 2 has AI flags set correctly (2v1)")
{
    ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
    ASSUME(IsExplosionMove(MOVE_EXPLOSION));

    u32 aiFlags;

    PARAMETRIZE { aiFlags = 0; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(playerRight, aiFlags);
        PLAYER(SPECIES_VOLTORB) { Moves(MOVE_CELEBRATE); HP(1); }
        PARTNER(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); HP(1); }
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
        if (aiFlags == 0)
            TURN { EXPECT_MOVE(playerRight, MOVE_ELECTRO_BALL, target: opponentLeft); }
        else
            TURN { EXPECT_MOVE(playerRight, MOVE_EXPLOSION, target: opponentLeft); }
    }
}

AI_MULTI_BATTLE_TEST("AI will not switch thinking all moves are bad when one opponent has fainted (multi)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_AGGRON) { Moves(MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_BODY_PRESS); }
        PARTNER(SPECIES_AGGRON) { Moves(MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_BODY_PRESS); }
        OPPONENT_A(SPECIES_GASTLY) { HP(1); Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_CAMERUPT) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_CAMERUPT) { Moves(MOVE_CELEBRATE); }
        TIE_BREAK_TARGET(TARGET_TIE_HI, 0);
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_THUNDERBOLT, target:opponentLeft); }
        TURN { EXPECT_MOVE(playerRight, MOVE_BODY_PRESS, target:opponentRight); }
    }
}
