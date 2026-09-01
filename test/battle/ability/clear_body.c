#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;
    enum Species species;
    enum Ability ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal's stats were not lowered!");
        else
            MESSAGE("The opposing Metang's stats were not lowered!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent stat stage reduction from moves")
{
    enum Move move = MOVE_NONE;
    u32 j;
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    static const u16 statReductionMoves[] = {
        MOVE_GROWL,
        MOVE_LEER,
        MOVE_CONFIDE,
        MOVE_FAKE_TEARS,
        MOVE_SCARY_FACE,
        MOVE_SWEET_SCENT,
        MOVE_SAND_ATTACK,
    };
    for (j = 0; j < ARRAY_COUNT(statReductionMoves); j++)
        {
            PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; move = statReductionMoves[j]; }
            PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; move = statReductionMoves[j]; }
            PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; move = statReductionMoves[j]; }
        }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        ASSUME_STAT_CHANGE(MOVE_CONFIDE, spAtk: -1);
        ASSUME_STAT_CHANGE(MOVE_FAKE_TEARS, spDef: -2);
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        ASSUME_STAT_CHANGE(MOVE_SWEET_SCENT, evasion: B_UPDATED_MOVE_DATA >= GEN_6 ? -2 : -1);
        ASSUME_STAT_CHANGE(MOVE_SAND_ATTACK, accuracy: -1);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal's stats were not lowered!");
        else
            MESSAGE("The opposing Metang's stats were not lowered!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent Sticky Web effect on switchin")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal's stats were not lowered!");
        else
            MESSAGE("The opposing Metang's stats were not lowered!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent stat stage reduction from moves used by the user")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_SUPERPOWER, self: TRUE, attack: -1, defense: -1);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPERPOWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPERPOWER, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ability);
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
            MESSAGE("The opposing Torkoal's stats were not lowered!");
            MESSAGE("The opposing Metang's stats were not lowered!");
        }
    }
}

SINGLE_BATTLE_TEST("Mold Breaker, Teravolt, and Turboblaze ignore Clear Body and White Smoke, but not Full Metal Body")
{
    u32 j, k;
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    enum Ability breakerAbility = ABILITY_NONE;
    enum Move move = MOVE_NONE;
    static const u16 breakerAbilities[] = {
        ABILITY_MOLD_BREAKER,
        ABILITY_TERAVOLT,
        ABILITY_TURBOBLAZE,
    };
    static const u16 statReductionMoves[] = {
        MOVE_GROWL,
        MOVE_LEER,
        MOVE_CONFIDE,
        MOVE_FAKE_TEARS,
        MOVE_SCARY_FACE,
        MOVE_SWEET_SCENT,
        MOVE_SAND_ATTACK,
    };

    for (j = 0; j < ARRAY_COUNT(statReductionMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(breakerAbilities); k++)
        {
            PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
            PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
            PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
        }
    }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        ASSUME_STAT_CHANGE(MOVE_CONFIDE, spAtk: -1);
        ASSUME_STAT_CHANGE(MOVE_FAKE_TEARS, spDef: -2);
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        ASSUME_STAT_CHANGE(MOVE_SWEET_SCENT, evasion: B_UPDATED_MOVE_DATA >= GEN_6 ? -2 : -1);
        ASSUME_STAT_CHANGE(MOVE_SAND_ATTACK, accuracy: -1);
        PLAYER(SPECIES_WOBBUFFET) { Ability(breakerAbility); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY){ // Full Metal Body can't be ignored by breaker abilities
            NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
            ABILITY_POPUP(opponent, ability);
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            NONE_OF {
                ABILITY_POPUP(opponent, ability);
                MESSAGE("The opposing Solgaleo's stats were not lowered!");
                MESSAGE("The opposing Torkoal's stats were not lowered!");
                MESSAGE("The opposing Metang's stats were not lowered!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Speed reduction from Iron Ball")
{
    u32 j;
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    enum Item heldItem = ITEM_NONE;
    static const enum Item heldItems[] = {
        ITEM_NONE,
        ITEM_IRON_BALL,
    };
    for (j = 0; j < ARRAY_COUNT(heldItems); j++)
    {
        PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; heldItem = heldItems[j]; }
        PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; heldItem = heldItems[j]; }
        PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; heldItem = heldItems[j]; }
    }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_IRON_BALL].holdEffect == HOLD_EFFECT_IRON_BALL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(species) { Speed(6); Ability(ability); Item(heldItem); }
    } WHEN {
        TURN {}
    } SCENE {
        NOT ABILITY_POPUP(opponent, ability);
        if (heldItem == ITEM_IRON_BALL) {
            MESSAGE("Wobbuffet used Celebrate!");
            if (ability == ABILITY_FULL_METAL_BODY)
                MESSAGE("The opposing Solgaleo used Celebrate!");
            else if (ability == ABILITY_WHITE_SMOKE)
                MESSAGE("The opposing Torkoal used Celebrate!");
            else
                MESSAGE("The opposing Metang used Celebrate!");
        } else {
            if (ability == ABILITY_FULL_METAL_BODY)
                MESSAGE("The opposing Solgaleo used Celebrate!");
            else if (ability == ABILITY_WHITE_SMOKE)
                MESSAGE("The opposing Torkoal used Celebrate!");
            else
                MESSAGE("The opposing Metang used Celebrate!");
            MESSAGE("Wobbuffet used Celebrate!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Speed reduction from paralysis")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal used Celebrate!");
        else
            MESSAGE("The opposing Metang used Celebrate!");
        MESSAGE("Wobbuffet used Thunder Wave!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        NOT ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet used Thunder Wave!");
        ONE_OF {
            MESSAGE("The opposing Metang used Celebrate!");
            MESSAGE("The opposing Metang couldn't move because it's paralyzed!");
            MESSAGE("The opposing Solgaleo used Celebrate!");
            MESSAGE("The opposing Solgaleo couldn't move because it's paralyzed!");
            MESSAGE("The opposing Torkoal used Celebrate!");
            MESSAGE("The opposing Torkoal couldn't move because it's paralyzed!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Attack reduction from burn", s16 damage)
{
    bool32 burned = FALSE;
    enum Species species;
    enum Ability ability;
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; burned = FALSE; }
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; burned = TRUE; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; burned = FALSE; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; burned = TRUE; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; burned = FALSE; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ability);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent receiving negative stat changes from Baton Pass")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        MESSAGE("Wobbuffet used Scary Face!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal used Celebrate!");
        else
            MESSAGE("The opposing Metang used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Topsy-Turvy")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOPSY_TURVY) == EFFECT_TOPSY_TURVY);
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        MESSAGE("Wobbuffet used Topsy-Turvy!");
        NOT ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        if (ability == ABILITY_FULL_METAL_BODY) {
            MESSAGE("The opposing Solgaleo used Celebrate!");
            MESSAGE("The opposing Solgaleo used Celebrate!");
        }
        else if (ability == ABILITY_WHITE_SMOKE) {
            MESSAGE("The opposing Torkoal used Celebrate!");
            MESSAGE("The opposing Torkoal used Celebrate!");
        }
        else {
            MESSAGE("The opposing Metang used Celebrate!");
            MESSAGE("The opposing Metang used Celebrate!");
        }
        MESSAGE("Wobbuffet used Scary Face!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ABILITY_POPUP(opponent, ability);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Spectral Thief from resetting positive stat changes")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SPECTRAL_THIEF, MOVE_EFFECT_STEAL_STATS));
        ASSUME_STAT_CHANGE(MOVE_AGILITY, speed: +2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(species) { Speed(5); Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_SPECTRAL_THIEF); }
        TURN {}
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo used Agility!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal used Agility!");
        else
            MESSAGE("The opposing Metang used Agility!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, opponent);
        MESSAGE("Wobbuffet used Celebrate!");
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal used Celebrate!");
        else
            MESSAGE("The opposing Metang used Celebrate!");
        MESSAGE("Wobbuffet used Spectral Thief!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
        NOT ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet used Celebrate!");
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("The opposing Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("The opposing Torkoal used Celebrate!");
        else
            MESSAGE("The opposing Metang used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke protect from Protect's secondary effects")
{
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;

    static const enum Move moves[] = {
        MOVE_SPIKY_SHIELD,
        MOVE_KINGS_SHIELD,
        MOVE_SILK_TRAP,
        MOVE_OBSTRUCT,
    };

    for (u32 j = 0; j < ARRAY_COUNT(moves); j++)
    {
        PARAMETRIZE{ move = moves[j]; species = SPECIES_METANG;   ability = ABILITY_CLEAR_BODY; }
        PARAMETRIZE{ move = moves[j]; species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
        PARAMETRIZE{ move = moves[j]; species = SPECIES_TORKOAL;  ability = ABILITY_WHITE_SMOKE; }
    }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            if (move == MOVE_KINGS_SHIELD) {
                MESSAGE("Wobbuffet's Attack fell!");
            } else if (move == MOVE_SILK_TRAP) {
                MESSAGE("Wobbuffet's Speed fell!");
            } else if (move == MOVE_OBSTRUCT) {
                MESSAGE("Wobbuffet's Defense harshly fell!");
            }
        }
    }
}
