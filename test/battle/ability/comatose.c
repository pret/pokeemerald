#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Comatose prevents status-inducing moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISONPOWDER; }
    PARAMETRIZE { move = MOVE_SLEEP_POWDER; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; }

    GIVEN {
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        MESSAGE("Komala is drowsing!");

        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ABILITY_POPUP(player, ABILITY_COMATOSE);
        MESSAGE("It doesn't affect Komala…");
    }
}

SINGLE_BATTLE_TEST("Comatose may be suppressed if Pokémon transformed into a Pokémon with Comatose ability and was under the effects of Gastro Acid")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POISONPOWDER; }
    PARAMETRIZE { move = MOVE_SLEEP_POWDER; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; }

    GIVEN {
        // FIXME: Explicit moves currently required here because Ditto
        // expects to find Celebrate in slot 1 during the second turn
        // (after transforming).
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); Speed(30); Moves(MOVE_CELEBRATE, MOVE_GASTRO_ACID, move); }
        OPPONENT(SPECIES_DITTO) { Speed(20); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, move); }
    } SCENE {
        MESSAGE("Komala is drowsing!");
        MESSAGE("Komala used Gastro Acid!");
        MESSAGE("The opposing Ditto used Transform!");
        MESSAGE("The opposing Ditto transformed into Komala!");

        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_POISONPOWDER)      { STATUS_ICON(opponent, poison: TRUE); }
        else if (move == MOVE_TOXIC)        { STATUS_ICON(opponent, badPoison: TRUE); }
        else if (move == MOVE_THUNDER_WAVE) { STATUS_ICON(opponent, paralysis: TRUE); }
        else if (move == MOVE_SLEEP_POWDER) { STATUS_ICON(opponent, sleep: TRUE); }
    }
}

SINGLE_BATTLE_TEST("Comatose Pokémon doesn't get poisoned by Toxic Spikes on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        NOT STATUS_ICON(player, STATUS1_POISON);
        ABILITY_POPUP(player, ABILITY_COMATOSE);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Comatose Pokémon don't get poisoned by Toxic Spikes on switch-in if forced in by phazing with Mold Breaker")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        NOT STATUS_ICON(player, STATUS1_POISON);
        ABILITY_POPUP(player, ABILITY_COMATOSE);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Comatose makes Rest fail")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_EQ(player->hp, 1);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Comatose isn't affected by Mold Breaker, Turboblaze or Teravolt")
{
    enum Ability ability;
    enum Species species;

    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; species = SPECIES_PINSIR; }
    PARAMETRIZE { ability = ABILITY_TURBOBLAZE; species = SPECIES_RESHIRAM; }
    PARAMETRIZE { ability = ABILITY_TERAVOLT; species = SPECIES_ZEKROM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
        ABILITY_POPUP(player, ABILITY_COMATOSE);
        MESSAGE("It doesn't affect Komala…");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Comatose isn't affected by Poison Touch + Sunsteel Strike")
{
    GIVEN {
        ASSUME(MoveIgnoresTargetAbility(MOVE_SUNSTEEL_STRIKE));
        ASSUME(MoveMakesContact(MOVE_SUNSTEEL_STRIKE));
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        OPPONENT(SPECIES_CROAGUNK) { Ability(ABILITY_POISON_TOUCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNSTEEL_STRIKE, WITH_RNG(RNG_POISON_TOUCH, 1)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNSTEEL_STRIKE, opponent);
        HP_BAR(player);
        NOT STATUS_ICON(player, poison: TRUE);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

WILD_BATTLE_TEST("Comatose boosts Dream Ball's multiplier")
{
    enum Ability ability;
    enum Species species;
    bool32 shouldCatch;
    const u16 rng = 50000;

    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; shouldCatch = TRUE; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; shouldCatch = FALSE; }

    GIVEN {
        ASSUME(B_DREAM_BALL_MODIFIER >= GEN_8);
        ASSUME(gSpeciesInfo[species].catchRate == 45);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); MaxHP(100); HP(1); }
    } WHEN {
        TURN { USE_ITEM(player, ITEM_DREAM_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, rng)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        if (shouldCatch)
            EXPECT_EQ(gBattleResults.caughtMonSpecies, species);
        else
            EXPECT_EQ(gBattleResults.caughtMonSpecies, SPECIES_NONE);
    }
}
