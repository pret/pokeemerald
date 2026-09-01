#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
}

SINGLE_BATTLE_TEST("Instruct causes the target to use its last used move again")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_INSTRUCT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, opponent);
        MESSAGE("Wobbuffet followed the opposing Wynaut's instructions!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if target hasn't made a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if move is banned by Instruct")
{
    GIVEN {
        ASSUME(IsMoveInstructBanned(MOVE_BIDE));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_BIDE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_BIDE); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BIDE, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
    }
}

TO_DO_BATTLE_TEST("Instruct fails if target is in the middle of Bide");

DOUBLE_BATTLE_TEST("Instruct fails if target is preparing Focus Punch, Beak Blast or Shell Trap")
{
    enum Move move;
    u32 Anim;
    PARAMETRIZE { move = MOVE_FOCUS_PUNCH; Anim = B_ANIM_FOCUS_PUNCH_SETUP; }
    PARAMETRIZE { move = MOVE_BEAK_BLAST; Anim = B_ANIM_BEAK_BLAST_SETUP; }
    PARAMETRIZE { move = MOVE_SHELL_TRAP; Anim = B_ANIM_SHELL_TRAP_SETUP; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOCUS_PUNCH) == EFFECT_FOCUS_PUNCH);
        ASSUME(GetMoveEffect(MOVE_BEAK_BLAST) == EFFECT_BEAK_BLAST);
        ASSUME(GetMoveEffect(MOVE_SHELL_TRAP) == EFFECT_SHELL_TRAP);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_INSTRUCT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_POUND, move); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_POUND, target: opponentLeft); }
        TURN {
            if (move == MOVE_SHELL_TRAP)
                MOVE(playerRight, move);
            else
                MOVE(playerRight, move, target: opponentLeft);
            MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, Anim, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if target is picked up by Sky Drop even if one of the battlers has No Guard")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_INSTRUCT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_MACHAMP) { Speed(2); Ability(ABILITY_NO_GUARD); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_SKY_DROP, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_SKY_DROP, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called move targets the target of the move picked on its last use")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft);
        NOT HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct doesn't bypass sleep")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(opponentLeft, MOVE_SPORE, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        MESSAGE("Wobbuffet is fast asleep.");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if target doesn't know the last move it used")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DRAGON_DANCE); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Instruct fails if the instructed move's PP is depleted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); Moves(MOVE_INSTRUCT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); MovesWithPP({MOVE_SCRATCH, 1}, {MOVE_CELEBRATE, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        }
    } THEN {
        EXPECT_EQ(playerRight->pp[0], 0);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called move fails if it can only be used on the first turn but consumes PP")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FAKE_OUT) == EFFECT_FIRST_TURN_ONLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FAKE_OUT, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->pp[3], GetMovePP(MOVE_FAKE_OUT) - 2);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called move doesn't fail if tormented")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TORMENT, target: playerRight); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called status moves don't fail if holding Assault Vest")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ASSAULT_VEST].holdEffect == HOLD_EFFECT_ASSAULT_VEST);
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_TRICK); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ASSAULT_VEST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TRICK, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called status move fails if taunted")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_GROWL); MOVE(opponentLeft, MOVE_TAUNT, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    } THEN {
        EXPECT_EQ(playerRight->pp[3], GetMovePP(MOVE_GROWL) - 1);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called moves fail if disabled")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DISABLE) == EFFECT_DISABLE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(opponentLeft, MOVE_DISABLE, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->pp[0], GetMovePP(MOVE_SCRATCH) - 1);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called moves keep their priority")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, MOVE_POUND, MOVE_SCRATCH, MOVE_QUICK_ATTACK); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft); MOVE(opponentLeft, MOVE_PSYCHIC_TERRAIN, target: playerRight); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Instructed move will be redirected and absorbed by Lightning Rod if it turns into an Electric Type move")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = opponentLeft; }
    PARAMETRIZE { moveTarget = opponentRight; }
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_LIGHTNING_ROD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: moveTarget);
            MOVE(opponentLeft, MOVE_PLASMA_FISTS, target: playerLeft);
            MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft);
            MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_LIGHTNING_ROD);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Instructed move will be redirected by Follow Me after instructed target loses Stalwart")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = opponentLeft; }
    PARAMETRIZE { moveTarget = opponentRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        PLAYER(SPECIES_DURALUDON) { Ability(ABILITY_STALWART); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: moveTarget);
            MOVE(opponentLeft, MOVE_FOLLOW_ME);
            MOVE(opponentRight, MOVE_SKILL_SWAP, target: playerLeft);
            MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(moveTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Instructed move will be redirected by Rage Powder after instructed target loses Grass typing")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = opponentLeft; }
    PARAMETRIZE { moveTarget = opponentRight; }
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, GEN_6);
        ASSUME(GetMoveEffect(MOVE_RAGE_POWDER) == EFFECT_FOLLOW_ME);
        ASSUME(IsPowderMove(MOVE_RAGE_POWDER) == TRUE);
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        PLAYER(SPECIES_TREECKO);
        PLAYER(SPECIES_SCEPTILE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: moveTarget);
            MOVE(opponentLeft, MOVE_RAGE_POWDER);
            MOVE(opponentRight, MOVE_SOAK, target: playerLeft);
            MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAGE_POWDER, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(moveTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, opponentRight);
        MESSAGE("Treecko transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Instruct message references the correct battlers")
{
    GIVEN {
        PLAYER(SPECIES_TREECKO);
        PLAYER(SPECIES_SCEPTILE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
            MOVE(opponentLeft, MOVE_DRAGON_DARTS, target:playerLeft);
            MOVE(opponentRight, MOVE_INSTRUCT, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        MESSAGE("The opposing Wynaut used Instruct!");
        NONE_OF {
            MESSAGE("Sceptile followed the opposing Wobbuffet's instructions!");
        }
        MESSAGE("Sceptile followed the opposing Wynaut's instructions!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
    }
}
