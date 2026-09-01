#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOCUS_PUNCH) == EFFECT_FOCUS_PUNCH);
}

SINGLE_BATTLE_TEST("Focus Punch activates only if not damaged")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_SCRATCH; activate = FALSE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; activate = FALSE; }
    PARAMETRIZE { move = MOVE_LEER; activate = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);

        if (activate) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("Wobbuffet lost its focus and couldn't move!");
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
                HP_BAR(opponent);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Focus Punch activation is based on Speed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_FOCUS_PUNCH, target: playerLeft); MOVE(playerRight, MOVE_FOCUS_PUNCH, target: opponentLeft); MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); MOVE(opponentLeft, MOVE_FOCUS_PUNCH, target: playerLeft); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, opponentRight);
        MESSAGE("The opposing Wynaut is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerRight);
        MESSAGE("Wynaut is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        MESSAGE("Wobbuffet is tightening its focus!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, opponentLeft);
        MESSAGE("The opposing Wobbuffet is tightening its focus!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, opponentRight);
        HP_BAR(playerLeft);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerRight);
        HP_BAR(opponentLeft);

        MESSAGE("Wobbuffet lost its focus and couldn't move!");
        MESSAGE("The opposing Wobbuffet lost its focus and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Focus Punch activates when Focus Band/Focus Sash blocks OHKO move")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_FOCUS_BAND; }
    PARAMETRIZE { item = ITEM_FOCUS_SASH; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); };
        OPPONENT(SPECIES_WOBBUFFET) {};
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_FISSURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, opponent);

        if (item) {
            MESSAGE("Wobbuffet used Focus Punch!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("Wobbuffet fainted!");
            NONE_OF {
                MESSAGE("Wobbuffet used Focus Punch!");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
                HP_BAR(opponent);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Focus Punch activates when Disguise block a OHKO move (Gen8+)")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_WATER_GUN; activate = FALSE; }
    PARAMETRIZE { move = MOVE_FISSURE; activate = TRUE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_8);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET) {};
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Mimikyu is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);

        if (activate) {
            MESSAGE("Mimikyu used Focus Punch!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("Mimikyu lost its focus and couldn't move!");
            NONE_OF {
                MESSAGE("Mimikyu used Focus Punch!");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
                HP_BAR(opponent);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Focus Punch does not activate when Focus Band/Focus Sash/Sturdy prevent getting one-shot by an attack")
{
    enum Item item;
    enum Ability ability;
    PARAMETRIZE { item = ITEM_NONE; ability = ABILITY_STURDY; }
    PARAMETRIZE { item = ITEM_FOCUS_BAND; ability = ABILITY_SHADOW_TAG; }
    PARAMETRIZE { item = ITEM_FOCUS_SASH; ability = ABILITY_SHADOW_TAG; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); Ability(ability); MaxHP(100); HP(100); };
        OPPONENT(SPECIES_WOBBUFFET) {};
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        MESSAGE("Wobbuffet lost its focus and couldn't move!");
        NONE_OF {
            MESSAGE("Wobbuffet used Focus Punch!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(player->hp, 1);
    }
}

SINGLE_BATTLE_TEST("Focus Punch activates when the user's Substitute is hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet used Focus Punch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Focus Punch uses PP when losing focus (Gen 3-4)")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_SCRATCH; activate = FALSE; }
    PARAMETRIZE { move = MOVE_LEER; activate = TRUE; }
    GIVEN {
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) {MovesWithPP({MOVE_FOCUS_PUNCH, 1});};
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (activate)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
    } THEN {
        EXPECT_EQ(player->pp[0], 0);
    }
}

SINGLE_BATTLE_TEST("Focus Punch doesn't use PP when losing focus (Gen 5+)")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_SCRATCH; activate = FALSE; }
    PARAMETRIZE { move = MOVE_LEER; activate = TRUE; }
    GIVEN {
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) {MovesWithPP({MOVE_FOCUS_PUNCH, 1});};
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (activate)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
    } THEN {
        if (activate)
            EXPECT_EQ(player->pp[0], 0);
        else
            EXPECT_EQ(player->pp[0], 1);
    }
}

SINGLE_BATTLE_TEST("Focus Punch failing occurs after flinching (Gen 3-4)")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH) == TRUE);
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_3);
        PLAYER(SPECIES_WOBBUFFET) {MovesWithPP({MOVE_FOCUS_PUNCH, 1});};
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_FAKE_OUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        MESSAGE("Wobbuffet flinched and couldn't move!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
    }
}

SINGLE_BATTLE_TEST("Focus Punch failing occurs before flinching (Gen 5+)")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH) == TRUE);
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) {MovesWithPP({MOVE_FOCUS_PUNCH, 1});};
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); MOVE(opponent, MOVE_FAKE_OUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        MESSAGE("Wobbuffet lost its focus and couldn't move!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
    }
}

TO_DO_BATTLE_TEST("Focus Punch activates when the user is hit by a status move");
TO_DO_BATTLE_TEST("Focus Punch losing focus is considered as the last move used (Gen 3-4)"); //Eg. Encore
TO_DO_BATTLE_TEST("Focus Punch losing focus is not considered as the last move used (Gen 5+)"); //Eg. Encore
TO_DO_BATTLE_TEST("Focus Punch's initial message is not considered as using the move for Zoom Lens");
TO_DO_BATTLE_TEST("Focus Punch will use the selected move's priority when being Encored into Focus Punch");

SINGLE_BATTLE_TEST("Focus Punch's initial message is not shown if the user selected a different move and was Encored into using Focus Punch (Gen9-)")
{
    GIVEN {
        WITH_CONFIG(B_MOVE_EFFECTS_BEFORE_MOVES, GEN_9);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_FOCUS_PUNCH); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
            MESSAGE("Wobbuffet is tightening its focus!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
            MESSAGE("Wobbuffet is tightening its focus!");
        }
    }
}

SINGLE_BATTLE_TEST("Focus Punch's initial message is shown if the user selected a different move and was Encored into using Focus Punch (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_MOVE_EFFECTS_BEFORE_MOVES, GEN_CHAMPIONS);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_FOCUS_PUNCH); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
            MESSAGE("Wobbuffet is tightening its focus!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, player);
        MESSAGE("Wobbuffet is tightening its focus!");
    }
}

DOUBLE_BATTLE_TEST("Focus Punch will lose focus if damaged when used by selecting a different move and being Encored (Gen 3-4)")
{
    GIVEN {
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_3);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); }
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
               MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft);
               MOVE(playerLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerLeft);
        HP_BAR(opponentLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        }
        MESSAGE("Wobbuffet lost its focus and couldn't move!");
    }
}

DOUBLE_BATTLE_TEST("Focus Punch will NOT lose focus if damaged when used by selecting a different move and being Encored (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_7);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); }
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
               MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft);
               MOVE(playerLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerLeft);
        HP_BAR(opponentLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
            MESSAGE("Wobbuffet lost its focus and couldn't move!");
        }
    }
}

DOUBLE_BATTLE_TEST("Focus Punch will lose focus if damaged when encored into a different move and selected Focus Punch (Gen 5-6)")
{
    GIVEN {
        WITH_CONFIG(B_FOCUS_PUNCH_FAILURE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
        TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
               MOVE(opponentLeft, MOVE_ENCORE, target: playerLeft);
               MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_PUNCH, playerLeft);
        }
        MESSAGE("Wobbuffet lost its focus and couldn't move!");
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use Focus Punch if it predicts a damaging move")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_MAGNEZONE) { Moves(MOVE_THUNDER_WAVE, MOVE_FLASH_CANNON, MOVE_DISCHARGE, MOVE_TRI_ATTACK); }
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_FOCUS_PUNCH, MOVE_SEED_BOMB); }
    } WHEN {
        TURN { MOVE(player, MOVE_DISCHARGE); EXPECT_MOVE(opponent, MOVE_FOCUS_PUNCH); }
        TURN { MOVE(player, MOVE_DISCHARGE); EXPECT_MOVE(opponent, MOVE_SEED_BOMB); }
    }
}

AI_SINGLE_BATTLE_TEST("AI will Incapacitate -> Substitute -> Focus Punch if able")
{
    GIVEN {
        PASSES_RANDOMLY(GetConfig(B_PARALYSIS_CHANCE) >= GEN_CHAMPIONS ? 7 : 6, 8, RNG_PARALYSIS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_MAGNEZONE) { Moves(MOVE_THUNDER_WAVE, MOVE_FLASH_CANNON, MOVE_DISCHARGE, MOVE_TRI_ATTACK); }
        OPPONENT(SPECIES_BRELOOM) { Moves(MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_SEED_BOMB); }
    } WHEN {
        TURN { MOVE(player, MOVE_DISCHARGE); EXPECT_MOVE(opponent, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_DISCHARGE); EXPECT_MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_DISCHARGE); EXPECT_MOVE(opponent, MOVE_FOCUS_PUNCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use status moves if the player's best attacking move is Focus Punch")
{
    PASSES_RANDOMLY(STATUS_MOVE_FOCUS_PUNCH_CHANCE, 100, RNG_AI_STATUS_FOCUS_PUNCH);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOCUS_PUNCH) == EFFECT_FOCUS_PUNCH);
        ASSUME(GetMoveCategory(MOVE_SWORDS_DANCE) == DAMAGE_CATEGORY_STATUS);
        // If Clefable is Normal-type, it will always use Play Rough.
        ASSUME(GetSpeciesType(SPECIES_CLEFABLE, 0) == TYPE_FAIRY);
        ASSUME(GetSpeciesType(SPECIES_CLEFABLE, 1) == TYPE_FAIRY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SNORLAX) { Moves(MOVE_FOCUS_PUNCH, MOVE_POUND); }
        OPPONENT(SPECIES_CLEFABLE) { Moves(MOVE_PLAY_ROUGH, MOVE_SWORDS_DANCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_PUNCH); EXPECT_MOVE(opponent, MOVE_PLAY_ROUGH); }
    }
}
