#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_FURY_CUTTER) == TYPE_BUG);
    ASSUME(GetMoveCategory(MOVE_FURY_CUTTER) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_FEINT_ATTACK) == TYPE_DARK);
    ASSUME(GetMoveCategory(MOVE_FEINT_ATTACK) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_SHADOW_PUNCH) == TYPE_GHOST);
    ASSUME(GetMoveCategory(MOVE_SHADOW_PUNCH) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
}

SINGLE_BATTLE_TEST("Rattled boosts speed by 1 when hit by Bug, Dark or Ghost type move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_FURY_CUTTER; }
    PARAMETRIZE { move = MOVE_FEINT_ATTACK; }
    PARAMETRIZE { move = MOVE_SHADOW_PUNCH; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(42) ; }
        OPPONENT(SPECIES_SUDOWOODO) { Speed(40); Ability(ABILITY_RATTLED); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move != MOVE_SCRATCH) {
            ABILITY_POPUP(opponent, ABILITY_RATTLED);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Sudowoodo's Speed rose!");
        }
        MESSAGE("The opposing Sudowoodo used Celebrate!");
        // Sudowoodo is now faster
        if (move != MOVE_SCRATCH){
            MESSAGE("The opposing Sudowoodo used Celebrate!");
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            HP_BAR(opponent);
            ABILITY_POPUP(opponent, ABILITY_RATTLED);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Sudowoodo's Speed rose!");
        }
        else {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            HP_BAR(opponent);
            MESSAGE("The opposing Sudowoodo used Celebrate!");
        }
    }
}

SINGLE_BATTLE_TEST("Rattled does not boost speed by 1 when affected by Intimidate (Gen5-7)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_7);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SUDOWOODO) { Ability(ABILITY_RATTLED); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Sudowoodo's Attack fell!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_RATTLED);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Sudowoodo's Speed rose!");
        }
    }
}

SINGLE_BATTLE_TEST("Rattled boosts speed by 1 when affected by Intimidate (Gen8+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_8);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_SUDOWOODO) { Ability(ABILITY_RATTLED); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Sudowoodo's Attack fell!");
        ABILITY_POPUP(opponent, ABILITY_RATTLED);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Sudowoodo's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Rattled triggers correctly when hit by U-Turn") // Specific test here, because of #3124
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveType(MOVE_U_TURN) == TYPE_BUG);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_SUDOWOODO) { Ability(ABILITY_RATTLED); }
        OPPONENT(SPECIES_SUDOWOODO);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet used U-turn!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_RATTLED);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Sudowoodo's Speed rose!");
        SEND_IN_MESSAGE("Wynaut");
    }
}
