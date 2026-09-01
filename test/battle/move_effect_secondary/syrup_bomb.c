#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
}

SINGLE_BATTLE_TEST("Syrup Bomb covers the foe in sticky syrup for 3 turns")
{
    u8 j;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Wobbuffet's Speed fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup isn't applied again if the target is already covered")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        NOT MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
    }
}

SINGLE_BATTLE_TEST("Syrup Bomb is prevented by Bulletproof")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHESPIN) { Ability(ABILITY_BULLETPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_BULLETPROOF);
        MESSAGE("It doesn't affect the opposing Chespin…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup speed reduction is prevented by Clear Body, White Smoke or Full Metal Body")
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
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        if (species == SPECIES_BELDUM)
        {
            MESSAGE("The opposing Beldum got covered in sticky candy syrup!");
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Beldum's stats were not lowered!");
            NONE_OF {
                MESSAGE("The opposing Beldum's Speed fell!");
            }
        }
        else if (species == SPECIES_TORKOAL)
        {
            MESSAGE("The opposing Torkoal got covered in sticky candy syrup!");
            ABILITY_POPUP(opponent, ABILITY_WHITE_SMOKE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Torkoal's stats were not lowered!");
            NONE_OF {
                MESSAGE("The opposing Torkoal's Speed fell!");
            }
        }
        else if (species == SPECIES_SOLGALEO)
        {
            MESSAGE("The opposing Solgaleo got covered in sticky candy syrup!");
            ABILITY_POPUP(opponent, ABILITY_FULL_METAL_BODY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Solgaleo's stats were not lowered!");
            NONE_OF {
                MESSAGE("The opposing Solgaleo's Speed fell!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup speed reduction is prevented by Clear Amulet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        MESSAGE("The effects of the Clear Amulet held by the opposing Wobbuffet prevents its stats from being lowered!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Wobbuffet's Speed fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky syrup will not decrease speed further then minus six")
{
    u8 j;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 3; j++)
            TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN {}
    } SCENE {
        for (j = 0; j < 3; j++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("The opposing Wobbuffet's Speed won't go any lower!");
        NONE_OF {
            MESSAGE("The opposing Wobbuffet's Speed fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup is removed when the user switches out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Wobbuffet's Speed fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup is removed when the user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB);
               MOVE(opponent, MOVE_SCRATCH);
               SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet fainted!");
        SEND_IN_MESSAGE("Wynaut");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("The opposing Wobbuffet's Speed fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup is not reflected by Mirror Armor")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Corviknight got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup stat drop is prevented by Mist")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); }
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet got covered in sticky candy syrup!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Sticky Syrup stat drop is prevented by Flower Veil")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CHIKORITA, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_CHIKORITA, 1) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_CHIKORITA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SYRUP_BOMB, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponentRight);
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

