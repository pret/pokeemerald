#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Power Construct (Ability) test titles")

SINGLE_BATTLE_TEST("Power Construct switches Zygarde's form when HP is below half")
{
    enum Species baseSpecies;
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_10_POWER_CONSTRUCT; }
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_50_POWER_CONSTRUCT; }

    GIVEN {
        PLAYER(baseSpecies)
        {
            Ability(ABILITY_POWER_CONSTRUCT);
            HP((GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2) + 1);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("You sense the presence of many!");
        ABILITY_POPUP(player, ABILITY_POWER_CONSTRUCT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_POWER_CONSTRUCT, player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_ZYGARDE_COMPLETE);
    }
}

WILD_BATTLE_TEST("Power Construct Zygarde reverts to its original form upon catching")
{
    enum Species baseSpecies;
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_10_POWER_CONSTRUCT; }
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_50_POWER_CONSTRUCT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(baseSpecies)
        {
            Ability(ABILITY_POWER_CONSTRUCT);
            HP((GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP) / 2) + 1);
        }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { USE_ITEM(player, ITEM_MASTER_BALL); }
    } SCENE {
        // Turn 1
        MESSAGE("You sense the presence of many!");
        ABILITY_POPUP(opponent, ABILITY_POWER_CONSTRUCT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_POWER_CONSTRUCT, opponent);

        // Turn 2
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_SPECIES), baseSpecies);
    }
}

SINGLE_BATTLE_TEST("Power Construct does not switch Zygarde's form if end-turn healing brings it above half HP")
{
    enum Species baseSpecies;
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_10_POWER_CONSTRUCT; }
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_50_POWER_CONSTRUCT; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_LEFTOVERS].holdEffect == HOLD_EFFECT_LEFTOVERS);
        PLAYER(baseSpecies)
        {
            Ability(ABILITY_POWER_CONSTRUCT);
            MaxHP(160);
            HP(78);
            Item(ITEM_LEFTOVERS);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        HP_BAR(player, damage: -10);
        NONE_OF {
            MESSAGE("You sense the presence of many!");
            ABILITY_POPUP(player, ABILITY_POWER_CONSTRUCT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_POWER_CONSTRUCT, player);
        }
    } THEN {
        EXPECT_EQ(player->species, baseSpecies);
        EXPECT_EQ(player->hp, 88);
    }
}

SINGLE_BATTLE_TEST("Power Construct does not switch Zygarde's form if end-turn damage makes it faint")
{
    enum Species baseSpecies;
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_10_POWER_CONSTRUCT; }
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_50_POWER_CONSTRUCT; }

    GIVEN {
        PLAYER(baseSpecies)
        {
            Ability(ABILITY_POWER_CONSTRUCT);
            HP(1);
            Status1(STATUS1_POISON);
        }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SEND_OUT(player, 1); }
    } SCENE {
        HP_BAR(player);
        NONE_OF {
            MESSAGE("You sense the presence of many!");
            ABILITY_POPUP(player, ABILITY_POWER_CONSTRUCT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_POWER_CONSTRUCT, player);
        }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), baseSpecies);
    }
}
