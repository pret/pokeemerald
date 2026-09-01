#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Octolock decreases Defense and Sp. Def by at the end of the turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("The opposing Wobbuffet can no longer escape because of Octolock!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense fell!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Sp. Def fell!");
    }
}

SINGLE_BATTLE_TEST("Octolock reduction is prevented by Clear Body, White Smoke and Full Metal Body")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BELDUM; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        if (species == SPECIES_BELDUM)
        {
            MESSAGE("The opposing Beldum can no longer escape because of Octolock!");
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            MESSAGE("The opposing Beldum's stats were not lowered!");
            NONE_OF {
                MESSAGE("The opposing Beldum's Defense fell!");
                MESSAGE("The opposing Beldum's Sp. Def fell!");
            }
        }
        else if (species == SPECIES_TORKOAL)
        {
            MESSAGE("The opposing Torkoal can no longer escape because of Octolock!");
            ABILITY_POPUP(opponent, ABILITY_WHITE_SMOKE);
            MESSAGE("The opposing Torkoal's stats were not lowered!");
            NONE_OF {
                MESSAGE("The opposing Torkoal's Defense fell!");
                MESSAGE("The opposing Torkoal's Sp. Def fell!");
            }
        }
        else if (species == SPECIES_SOLGALEO)
        {
            MESSAGE("The opposing Solgaleo can no longer escape because of Octolock!");
            ABILITY_POPUP(opponent, ABILITY_FULL_METAL_BODY);
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
            NONE_OF {
                MESSAGE("The opposing Solgaleo's Defense fell!");
                MESSAGE("The opposing Solgaleo's Sp. Def fell!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Octolock Defense reduction is prevented by Big Pecks")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("The opposing Pidgey can no longer escape because of Octolock!");
        NOT MESSAGE("The opposing Pidgey's Defense fell!");
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("The opposing Pidgey's Defense was not lowered!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Pidgey's Sp. Def fell!");
    }
}

SINGLE_BATTLE_TEST("Octolock reduction is prevented by Clear Amulet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("The opposing Wobbuffet can no longer escape because of Octolock!");
        MESSAGE("The effects of the Clear Amulet held by the opposing Wobbuffet prevents its stats from being lowered!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Defense fell!");
            MESSAGE("The opposing Wobbuffet's Sp. Def fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Octolock will not decrease Defense and Sp. Def further then minus six")
{
    u8 j;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
        for (j = 0; j < 6; j++)
            TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        for (j = 0; j < 5; j++) {
            MESSAGE("The opposing Wobbuffet's Defense fell!");
            MESSAGE("The opposing Wobbuffet's Sp. Def fell!");
        }
        MESSAGE("The opposing Wobbuffet's Defense won't go any lower!");
        MESSAGE("The opposing Wobbuffet's Sp. Def won't go any lower!");
        NONE_OF {
            MESSAGE("The opposing Wobbuffet's Defense fell!");
            MESSAGE("The opposing Wobbuffet's Sp. Def fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Octolock ends after user that set the lock switches out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("The opposing Wobbuffet can no longer escape because of Octolock!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense fell!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Sp. Def fell!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Defense fell!");
            MESSAGE("The opposing Wobbuffet's Sp. Def fell!");
        }

    }
}

SINGLE_BATTLE_TEST("Octolock stat drops are not reflected by Mirror Armor")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("The opposing Corviknight can no longer escape because of Octolock!");
        NOT ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Corviknight's Defense fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Octolock stat drop is prevented by Mist")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); }
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Octolock stat drop is prevented by Flower Veil")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CHIKORITA, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_CHIKORITA, 1) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_CHIKORITA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_OCTOLOCK, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}
