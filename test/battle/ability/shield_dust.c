#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Shield Dust blocks secondary effects")
{
    u16 move;
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
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_ROCK_TOMB, MOVE_EFFECT_SPD_MINUS_1, 100) == TRUE);
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
            MESSAGE("Foe Vivillon is paralyzed! It may be unable to move!");
            MESSAGE("Foe Vivillon was burned!");
            MESSAGE("Foe Vivillon was poisoned!");
            MESSAGE("Foe Vivillon flinched!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Vivillon was prevented from healing!");
        }
    } THEN { // Can't find good way to test trapping
        EXPECT(!(opponent->status2 & STATUS2_ESCAPE_PREVENTION));
    }
}

SINGLE_BATTLE_TEST("Shield Dust does not block primary effects")
{
    u16 move;
    PARAMETRIZE { move = MOVE_INFESTATION; }
    PARAMETRIZE { move = MOVE_THOUSAND_ARROWS; }
    PARAMETRIZE { move = MOVE_JAW_LOCK; }
    PARAMETRIZE { move = MOVE_PAY_DAY; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_INFESTATION, MOVE_EFFECT_WRAP, 0) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_THOUSAND_ARROWS, MOVE_EFFECT_SMACK_DOWN, 0) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_JAW_LOCK, MOVE_EFFECT_TRAP_BOTH, 0) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_PAY_DAY, MOVE_EFFECT_PAYDAY, 0) == TRUE);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_SMACK_DOWN, MOVE_EFFECT_SMACK_DOWN, 0) == TRUE);
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
                MESSAGE("Foe Vivillon has been afflicted with an infestation by Wobbuffet!");
                break;
            case MOVE_THOUSAND_ARROWS:
                MESSAGE("Foe Vivillon fell straight down!");
                break;
            case MOVE_JAW_LOCK:
                MESSAGE("Neither Pokémon can run away!");
                break;
            case MOVE_PAY_DAY:
                MESSAGE("Coins scattered everywhere!");
                break;
        }
    } THEN { // Can't find good way to test trapping
        if (move == MOVE_JAW_LOCK) {
            EXPECT(opponent->status2 & STATUS2_ESCAPE_PREVENTION);
            EXPECT(player->status2 & STATUS2_ESCAPE_PREVENTION);
        }
    }
}

SINGLE_BATTLE_TEST("Shield Dust does not block self-targeting effects, primary or secondary")
{
    u16 move;
    PARAMETRIZE { move = MOVE_POWER_UP_PUNCH; }
    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_LEAF_STORM; }
    PARAMETRIZE { move = MOVE_METEOR_ASSAULT; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_POWER_UP_PUNCH, MOVE_EFFECT_ATK_PLUS_1) == TRUE);
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_RAPID_SPIN, MOVE_EFFECT_RAPID_SPIN) == TRUE);
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_LEAF_STORM, MOVE_EFFECT_SP_ATK_TWO_DOWN) == TRUE);
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
            case MOVE_RAPID_SPIN:
            case MOVE_LEAF_STORM:
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
                break;
            case MOVE_METEOR_ASSAULT: // second turn
                MESSAGE("Wobbuffet must recharge!");
                break;
        }
    }
}

DOUBLE_BATTLE_TEST("Shield Dust does not block Sparkling Aria in doubles")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPARKLING_ARIA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPARKLING_ARIA, playerLeft);
        MESSAGE("Foe Vivillion's burn was healed.");
        STATUS_ICON(opponentLeft, burn: TRUE);
    }
}
