#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME_STAT_CHANGE(MOVE_SPICY_EXTRACT, attack: +2, defense: -2);
}

SINGLE_BATTLE_TEST("Spicy Extract raises target's Attack by 2 stages and lowers target's Defense by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack rose sharply!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense harshly fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Spicy Extract is prevented by target's ability if it's Attack stat is maxed out")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_LIGHT_METAL; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Wobbuffet used Spicy Extract!");
        if (ability == ABILITY_CLEAR_BODY) {
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            MESSAGE("The opposing Beldum's stats were not lowered!");
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            }
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Spicy Extract Defense loss is prevented by Big Pecks")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Pidgey's Attack rose sharply!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Defense harshly fell!");
        }
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("The opposing Pidgey's Defense was not lowered!");
    }
}

SINGLE_BATTLE_TEST("Spicy Extract bypasses accuracy checks")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        NOT MESSAGE("The opposing Wobbuffet avoided the attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack rose sharply!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense harshly fell!");
    }
}

SINGLE_BATTLE_TEST("Spicy Extract will fail if target is in a semi-invulnerability state")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DIVE); MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Dive!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, opponent);
        MESSAGE("Wobbuffet used Spicy Extract!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        MESSAGE("The opposing Wobbuffet avoided the attack!");
    }
}

SINGLE_BATTLE_TEST("Spicy Extract stat changes will be inverted by Contrary")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Attack harshly fell!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Defense rose sharply!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Spicy Extract against Clear Amulet and Contrary raises Defense only")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Attack harshly fell!");
        }
        MESSAGE("The effects of the Clear Amulet held by the opposing Snivy prevents its stats from being lowered!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Defense rose sharply!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}
