#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shield Dust blocks secondary effects")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_NUZZLE; }
    PARAMETRIZE { move = MOVE_INFERNO; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }
    PARAMETRIZE { move = MOVE_FAKE_OUT; }
    PARAMETRIZE { move = MOVE_ROCK_TOMB; }
    PARAMETRIZE { move = MOVE_SPIRIT_SHACKLE; }
    PARAMETRIZE { move = MOVE_PSYCHIC_NOISE; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_NUZZLE, MOVE_EFFECT_PARALYSIS, 100) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_INFERNO, MOVE_EFFECT_BURN, 100) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON, 100) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_ROCK_TOMB, MOVE_EFFECT_STAT_MINUS, 100) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_SPIRIT_SHACKLE, MOVE_EFFECT_PREVENT_ESCAPE, 100) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_PSYCHIC_NOISE, MOVE_EFFECT_PSYCHIC_NOISE, 100) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        NONE_OF {
            MESSAGE("The opposing Vivillon is paralyzed, so it may be unable to move!");
            MESSAGE("The opposing Vivillon was burned!");
            MESSAGE("The opposing Vivillon was poisoned!");
            MESSAGE("The opposing Vivillon flinched and couldn't move!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Vivillon was prevented from healing!");
        }
    } THEN { // Can't find good way to test trapping
        EXPECT(!opponent->volatiles.escapePrevention);
    }
}

SINGLE_BATTLE_TEST("Shield Dust does not block primary effects")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_INFESTATION; }
    PARAMETRIZE { move = MOVE_THOUSAND_ARROWS; }
    PARAMETRIZE { move = MOVE_JAW_LOCK; }
    PARAMETRIZE { move = MOVE_PAY_DAY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THOUSAND_ARROWS) == EFFECT_SMACK_DOWN);
        ASSUME(GetMoveEffect(MOVE_SMACK_DOWN) == EFFECT_SMACK_DOWN);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_INFESTATION, MOVE_EFFECT_WRAP, 0) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_JAW_LOCK, MOVE_EFFECT_TRAP_BOTH, 0) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_PAY_DAY, MOVE_EFFECT_PAYDAY, 0) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        switch (move)
        {
            case MOVE_INFESTATION:
                MESSAGE("The opposing Vivillon has been afflicted with an infestation by Wobbuffet!");
                break;
            case MOVE_THOUSAND_ARROWS:
                MESSAGE("The opposing Vivillon fell straight down!");
                break;
            case MOVE_JAW_LOCK:
                MESSAGE("Neither Pokémon can run away!");
                break;
            case MOVE_PAY_DAY:
                MESSAGE("Coins were scattered everywhere!");
                break;
            default:
                break;
        }
    } THEN { // Can't find good way to test trapping
        if (move == MOVE_JAW_LOCK) {
            EXPECT(opponent->volatiles.escapePrevention);
            EXPECT(player->volatiles.escapePrevention);
        }
    }
}

SINGLE_BATTLE_TEST("Shield Dust does not block self-targeting effects, primary or secondary")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_POWER_UP_PUNCH; }
    PARAMETRIZE { move = MOVE_FLAME_CHARGE; }
    PARAMETRIZE { move = MOVE_LEAF_STORM; }
    PARAMETRIZE { move = MOVE_METEOR_ASSAULT; }

    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_FLAME_CHARGE, self: TRUE, speed: 1);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_POWER_UP_PUNCH, self: TRUE, attack: 1);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_LEAF_STORM, self: TRUE, spAtk: -2);
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_METEOR_ASSAULT, MOVE_EFFECT_RECHARGE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, move); }
        if (move == MOVE_METEOR_ASSAULT) {
            TURN { SKIP_TURN(player); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        switch (move)
        {
            case MOVE_POWER_UP_PUNCH:
            case MOVE_FLAME_CHARGE:
            case MOVE_LEAF_STORM:
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
                break;
            case MOVE_METEOR_ASSAULT: // second turn
                MESSAGE("Wobbuffet must recharge!");
                break;
            default:
                break;
        }
    }
}

DOUBLE_BATTLE_TEST("Shield Dust does or does not block Sparkling Aria depending on number of targets hit")
{
    enum Move moveToUse;
    PARAMETRIZE { moveToUse = MOVE_FINAL_GAMBIT; }
    PARAMETRIZE { moveToUse = MOVE_SCRATCH; }
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, moveToUse, target: opponentRight); MOVE(playerLeft, MOVE_SPARKLING_ARIA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLING_ARIA, playerLeft);
        if (moveToUse == MOVE_SCRATCH) {
            MESSAGE("The opposing Vivillon's burn was cured!");
            STATUS_ICON(opponentLeft, none: TRUE);
        } else {
            NONE_OF {
                MESSAGE("The opposing Vivillon's burn was cured!");
                STATUS_ICON(opponentLeft, none: TRUE);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Shield Dust blocks Sparkling Aria if all other targets avoid getting hit by")
{
    GIVEN {
        PLAYER(SPECIES_PRIMARINA);
        PLAYER(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WYNAUT) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FLY, target:playerLeft); MOVE(opponentRight, MOVE_PROTECT); MOVE(playerRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_SPARKLING_ARIA); }
    } SCENE {
        NOT MESSAGE("Vivillon's burn was cured!");
    }
}

SINGLE_BATTLE_TEST("Shield Dust blocks Sparkling Aria in singles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPARKLING_ARIA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLING_ARIA, player);
        NONE_OF {
            MESSAGE("The opposing Vivillon's burn was cured!");
            STATUS_ICON(opponent, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Shield Dust does not prevent ability stat changes")
{
    GIVEN {
        PLAYER(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
        OPPONENT(SPECIES_ELDEGOSS) { Ability(ABILITY_COTTON_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Vivillon's Speed fell!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will score secondary effects against shield dust correctly")
{
    AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
    GIVEN {
        PLAYER(SPECIES_DUSTOX){ Ability(ABILITY_SHIELD_DUST); Moves(MOVE_GUST); }
        OPPONENT(SPECIES_SUNFLORA){ Ability(ABILITY_EARLY_BIRD); Moves(MOVE_MYSTICAL_FIRE, MOVE_FIERY_DANCE); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_GUST);
            EXPECT_MOVE(opponent, MOVE_FIERY_DANCE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI will score secondary effects against shield dust correctly when it has Mold Breaker")
{
    AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
    GIVEN {
        PLAYER(SPECIES_DUSTOX){ Ability(ABILITY_SHIELD_DUST); Moves(MOVE_GUST); }
        OPPONENT(SPECIES_SUNFLORA){ Ability(ABILITY_MOLD_BREAKER); Moves(MOVE_MYSTICAL_FIRE, MOVE_FIERY_DANCE); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_GUST);
            EXPECT_MOVE(opponent, MOVE_MYSTICAL_FIRE);
        }
    }
}
