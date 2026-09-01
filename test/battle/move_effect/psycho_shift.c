#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Psycho Shift burn is blocked by Substitute unless the user has Infiltrator")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY;  }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_PSYCHO_SHIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        if (ability == ABILITY_INFILTRATOR)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
            STATUS_ICON(opponent, burn: TRUE);
            STATUS_ICON(player, none: TRUE);
        }
        else
        {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
                STATUS_ICON(opponent, burn: TRUE);
            }
        }
    } THEN {
        if (ability == ABILITY_INFILTRATOR)
        {
            EXPECT_EQ(player->status1, STATUS1_NONE);
            EXPECT_EQ(opponent->status1, STATUS1_BURN);
        }
        else
        {
            EXPECT_EQ(player->status1, STATUS1_BURN);
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
        }
    }
}

SINGLE_BATTLE_TEST("Psycho Shift burn is blocked by Safeguard unless the user has Infiltrator")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY;  }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
        PLAYER(SPECIES_DRAGAPULT) { Ability(ability); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAFEGUARD); MOVE(player, MOVE_PSYCHO_SHIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, opponent);
        if (ability == ABILITY_INFILTRATOR)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
            STATUS_ICON(opponent, burn: TRUE);
            STATUS_ICON(player, none: TRUE);
        }
        else
        {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
                STATUS_ICON(opponent, burn: TRUE);
            }
        }
    } THEN {
        if (ability == ABILITY_INFILTRATOR)
        {
            EXPECT_EQ(player->status1, STATUS1_NONE);
            EXPECT_EQ(opponent->status1, STATUS1_BURN);
        }
        else
        {
            EXPECT_EQ(player->status1, STATUS1_BURN);
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
        }
    }
}

SINGLE_BATTLE_TEST("Psycho Shift triggers Synchronize before curing the user (Gen5+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHO_SHIFT) == EFFECT_PSYCHO_SHIFT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_ABRA) { Ability(ABILITY_SYNCHRONIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHO_SHIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHO_SHIFT, player);
        STATUS_ICON(opponent, burn: TRUE);
        ABILITY_POPUP(opponent, ABILITY_SYNCHRONIZE);
        STATUS_ICON(player, none: TRUE);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(opponent->status1, STATUS1_BURN);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Psycho Shift (Move Effect) test titles")
