#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_BEAK_BLAST) == EFFECT_BEAK_BLAST);
}

DOUBLE_BATTLE_TEST("Beak Blast's charging message is shown before other moves are used")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BEAK_BLAST, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, playerLeft);
        MESSAGE("Wynaut started heating up its beak!");

        MESSAGE("Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);

        MESSAGE("Wynaut used Beak Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, playerLeft);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Beak Blast burns all who make contact with the Pokémon")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerLeft, MOVE_BEAK_BLAST, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, playerLeft);
        MESSAGE("Wynaut started heating up its beak!");

        MESSAGE("Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);

        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentLeft);
        MESSAGE("The opposing Wobbuffet was burned!");
        STATUS_ICON(opponentLeft, burn: TRUE);

        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
        MESSAGE("The opposing Wobbuffet was burned!");
        STATUS_ICON(opponentRight, burn: TRUE);

        MESSAGE("Wynaut used Beak Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, playerLeft);
        HP_BAR(opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Beak Blast burns only when contact moves are used")
{
    enum Move move;
    bool32 burn;
    PARAMETRIZE { move = MOVE_SCRATCH; burn = TRUE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; burn = FALSE; }
    PARAMETRIZE { move = MOVE_LEER; burn = FALSE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_WATER_GUN));
        ASSUME(!MoveMakesContact(MOVE_LEER));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_BEAK_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, player);
        MESSAGE("Wobbuffet started heating up its beak!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);

        if (burn) {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
            MESSAGE("The opposing Wobbuffet was burned!");
            STATUS_ICON(opponent, burn: TRUE);
        }
        else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
                MESSAGE("The opposing Wobbuffet was burned!");
                STATUS_ICON(opponent, burn: TRUE);
            }
        }

        MESSAGE("Wobbuffet used Beak Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Beak Blast doesn't burn when charging a two turn move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_BOUNCE; }
    PARAMETRIZE { move = MOVE_DIG; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_BOUNCE));
        ASSUME(MoveMakesContact(MOVE_DIG));
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_BOUNCE)].twoTurnEffect);
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_DIG)].twoTurnEffect);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_BEAK_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, player);
        MESSAGE("Wobbuffet started heating up its beak!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);

        NONE_OF {
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
            MESSAGE("The opposing Wobbuffet was burned!");
            STATUS_ICON(opponent, burn: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Beak Blast doesn't burn fire types")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_ARCANINE].types[0] == TYPE_FIRE || gSpeciesInfo[SPECIES_ARCANINE].types[1] == TYPE_FIRE);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_ARCANINE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_BEAK_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT STATUS_ICON(player, burn: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponent);
    }
}

SINGLE_BATTLE_TEST("Beak Blast doesn't burn after being used")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_COUNTER) < GetMovePriority(MOVE_BEAK_BLAST));
        ASSUME(MoveMakesContact(MOVE_COUNTER));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BEAK_BLAST); MOVE(player, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponent);
        NOT STATUS_ICON(player, burn: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Beak Blast doesn't burn if the target is protected by Mat Block")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MAT_BLOCK) == EFFECT_MAT_BLOCK);
        ASSUME(GetMoveProtectMethod(MOVE_MAT_BLOCK) == PROTECT_MAT_BLOCK);
        ASSUME(MoveMakesContact(MOVE_POUND));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_MAT_BLOCK);
            MOVE(opponentLeft, MOVE_BEAK_BLAST, target: playerLeft);
            MOVE(playerLeft, MOVE_POUND, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAT_BLOCK, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
            STATUS_ICON(playerLeft, STATUS1_BURN);
        }
    }
}

DOUBLE_BATTLE_TEST("Beak Blast doesn't burn if the target is protected by Quick Guard")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_QUICK_GUARD) == EFFECT_PROTECT);
        ASSUME(GetMoveProtectMethod(MOVE_QUICK_GUARD) == PROTECT_QUICK_GUARD);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) > 0);
        ASSUME(MoveMakesContact(MOVE_QUICK_ATTACK));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BEAK_BLAST, target: playerLeft);
               MOVE(opponentRight, MOVE_QUICK_GUARD);
               MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_GUARD, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerLeft);
            STATUS_ICON(playerLeft, STATUS1_BURN);
        }
    }
}

SINGLE_BATTLE_TEST("Beak Blast doesn't burn even if the target fails to connect its contact move")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        PLAYER(SPECIES_URSHIFU) {};
        OPPONENT(SPECIES_TOUCANNON) {};
    } WHEN {
        TURN { MOVE(opponent, MOVE_BEAK_BLAST); MOVE(player, MOVE_UPPER_HAND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponent);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        NONE_OF {
            MESSAGE("Urshifu was burned!");
            STATUS_ICON(player, STATUS1_BURN);
        }
    }
}

SINGLE_BATTLE_TEST("Beak Blast burns even if the target has Unseen Fist")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        ASSUME(MoveMakesContact(MOVE_SURGING_STRIKES));
        PLAYER(SPECIES_URSHIFU_RAPID_STRIKE) { Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_TOUCANNON) {};
    } WHEN {
        TURN { MOVE(opponent, MOVE_BEAK_BLAST); MOVE(player, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponent);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        MESSAGE("Urshifu was burned!");
    }
}

SINGLE_BATTLE_TEST("Beak Blast takes effect after HP drain effects and before abilities")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        ASSUME(MoveMakesContact(MOVE_DRAIN_PUNCH));
        PLAYER(SPECIES_URSHIFU_RAPID_STRIKE) { HP(1); }
        OPPONENT(SPECIES_GARCHOMP) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_BEAK_BLAST); MOVE(player, MOVE_DRAIN_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponent);
        MESSAGE("The opposing Garchomp started heating up its beak!");
        MESSAGE("The opposing Garchomp had its energy drained!");
        MESSAGE("Urshifu was burned!");
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
    }
}

SINGLE_BATTLE_TEST("Beak Blast's charging message is shown regardless if it would've missed")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        ASSUME(MoveMakesContact(MOVE_POUND));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); }
        OPPONENT(SPECIES_TOUCANNON) {};
    } WHEN {
        TURN { MOVE(opponent, MOVE_BEAK_BLAST, hit: FALSE); MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponent);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        MESSAGE("Wobbuffet was burned!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponent);
        MESSAGE("Wobbuffet avoided the attack!");
    }
}

SINGLE_BATTLE_TEST("Beak Blast still shows its charged state when Encored into a different move")
{
    GIVEN {
        WITH_CONFIG(B_MOVE_EFFECTS_BEFORE_MOVES, GEN_CHAMPIONS);
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_TOUCANNON) { Speed(1); }
    } WHEN {
        TURN {}
        TURN { MOVE(player, MOVE_ENCORE); MOVE(opponent, MOVE_BEAK_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponent);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        MESSAGE("The opposing Toucannon used Celebrate!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponent);
    }
}

DOUBLE_BATTLE_TEST("Beak Blast fails when Encored into it from a different move (Gen9-)")
{
    GIVEN {
        WITH_CONFIG(B_MOVE_EFFECTS_BEFORE_MOVES, GEN_9);
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_TOUCANNON) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BEAK_BLAST, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_ENCORE, target: opponentLeft); MOVE(opponentLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponentLeft);
            MESSAGE("The opposing Toucannon started heating up its beak!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Beak Blast connects when Encored into it (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_MOVE_EFFECTS_BEFORE_MOVES, GEN_CHAMPIONS);
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_TOUCANNON) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BEAK_BLAST, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_ENCORE, target: opponentLeft); MOVE(opponentLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponentLeft);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        MESSAGE("The opposing Toucannon used Beak Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Beak Blast doesn't repeat its charging animation when Encored into it")
{
    GIVEN {
        WITH_CONFIG(B_MOVE_EFFECTS_BEFORE_MOVES, GEN_CHAMPIONS);
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_TOUCANNON) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_BEAK_BLAST, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_ENCORE, target: opponentLeft); MOVE(opponentLeft, MOVE_BEAK_BLAST, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponentLeft);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, playerLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponentLeft);
        MESSAGE("The opposing Toucannon used Beak Blast!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Beak Blast is blocked by Bulletproof but not to the burn it causes")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_BEAK_BLAST) < 0);
        ASSUME(MoveMakesContact(MOVE_POUND));
        PLAYER(SPECIES_CHESNAUGHT) { Ability(ABILITY_BULLETPROOF); }
        OPPONENT(SPECIES_TOUCANNON) {};
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); MOVE(opponent, MOVE_BEAK_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_BEAK_BLAST_SETUP, opponent);
        MESSAGE("The opposing Toucannon started heating up its beak!");
        MESSAGE("Chesnaught was burned!");
        STATUS_ICON(player, STATUS1_BURN);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAK_BLAST, opponent);
        ABILITY_POPUP(player, ABILITY_BULLETPROOF);
        MESSAGE("It doesn't affect Chesnaught…");
    }
}
