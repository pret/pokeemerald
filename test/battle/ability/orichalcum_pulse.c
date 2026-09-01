#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Orichalcum Pulse sets up sun for 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        MESSAGE("The sunlight turned harsh!");
        MESSAGE("Koraidon turned the sunlight harsh, sending its ancient pulse into a frenzy!");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight faded.");
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse sets up sun for 8 turns with Heat Rock")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_HEAT_ROCK].holdEffect == HOLD_EFFECT_HEAT_ROCK);
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); Item(ITEM_HEAT_ROCK); }
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
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        MESSAGE("The sunlight turned harsh!");
        MESSAGE("Koraidon turned the sunlight harsh, sending its ancient pulse into a frenzy!");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight is strong.");
        MESSAGE("The sunlight faded.");
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse activates when entering battle in sun")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        MESSAGE("Koraidon basked in the sunlight, sending its ancient pulse into a frenzy!");
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse triggers Protosynthesis before announcing its attack boost")
{
    GIVEN {
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); }
        OPPONENT(SPECIES_WALKING_WAKE) { Ability(ABILITY_PROTOSYNTHESIS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        MESSAGE("The sunlight turned harsh!");
        ABILITY_POPUP(opponent, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated the opposing Walking Wake's Protosynthesis!");
        MESSAGE("The opposing Walking Wake's Sp. Atk was heightened!");
        MESSAGE("Koraidon turned the sunlight harsh, sending its ancient pulse into a frenzy!");
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse boosts physical moves by 33% in sun", s16 damage)
{
    u16 setupMove;
    PARAMETRIZE { setupMove = MOVE_CELEBRATE; }
    PARAMETRIZE { setupMove = MOVE_RAIN_DANCE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, setupMove); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.3333), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse boost applies even if the target holds Utility Umbrella", s16 damage)
{
    enum Item targetItem;
    PARAMETRIZE { targetItem = ITEM_NONE; }
    PARAMETRIZE { targetItem = ITEM_UTILITY_UMBRELLA; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(targetItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse does not boost physical moves if holder has Utility Umbrella", s16 damage)
{
    enum Item holdItem;
    PARAMETRIZE { holdItem = ITEM_NONE; }
    PARAMETRIZE { holdItem = ITEM_UTILITY_UMBRELLA; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); Item(holdItem); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.3333), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Orichalcum Pulse activates when entering battle in sun (Overworld Sun)")
{
    SetStartingStatus(STARTING_STATUS_WEATHER_SUN);

    GIVEN {
        WITH_CONFIG(B_OVERWORLD_WEATHER_OVERRIDE, GEN_9);
        PLAYER(SPECIES_KORAIDON) { Ability(ABILITY_ORICHALCUM_PULSE); }
        OPPONENT(SPECIES_WOBBUFFET) {};
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ORICHALCUM_PULSE);
        NOT MESSAGE("But it failed!");
        MESSAGE("Koraidon basked in the sunlight, sending its ancient pulse into a frenzy!");
    } THEN {
        ResetStartingStatuses();
    }
}
