#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Drizzle summons rain", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_DRIZZLE; }
    PARAMETRIZE { ability = ABILITY_DAMP; }

    GIVEN {
        PLAYER(SPECIES_POLITOED) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BUBBLE); }
    } SCENE {
        if (ability == ABILITY_DRIZZLE) {
            ABILITY_POPUP(player, ABILITY_DRIZZLE);
            MESSAGE("It started to rain!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Drizzle sets up rain for 5 turns (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        PLAYER(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRIZZLE);
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("The rain stopped.");
    }
}

SINGLE_BATTLE_TEST("Drizzle sets up rain for 8 turns with Damp Rock (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        ASSUME(gItemsInfo[ITEM_DAMP_ROCK].holdEffect == HOLD_EFFECT_DAMP_ROCK);
        PLAYER(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); Item(ITEM_DAMP_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRIZZLE);
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("The rain stopped.");
    }
}

SINGLE_BATTLE_TEST("Drizzle sets up permanent rain (Gen3-5)")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_3);
        PLAYER(SPECIES_POLITOED) { Ability(ABILITY_DRIZZLE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DRIZZLE);
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        MESSAGE("Rain continues to fall.");
        NOT MESSAGE("The rain stopped.");
    }
}
