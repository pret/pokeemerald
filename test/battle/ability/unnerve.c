#include "global.h"
#include "test/battle.h"

// Remember to add a PARAMETRIZE for As One in the following tests:
SINGLE_BATTLE_TEST("Unnerve prevents opposing Pokémon from eating their own berries")
{
    u16 mon;
    enum Ability ability;
    PARAMETRIZE { mon = SPECIES_JOLTIK, ability = ABILITY_UNNERVE; }
    PARAMETRIZE { mon = SPECIES_CALYREX_ICE, ability = ABILITY_AS_ONE_ICE_RIDER; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RAWST_BERRY].holdEffect == HOLD_EFFECT_CURE_BRN);
        PLAYER(mon) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RAWST_BERRY); Status1(STATUS1_BURN); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ability);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Unnerve doesn't prevent opposing Pokémon from using Natural Gift")
{
    u16 mon;
    enum Ability ability;
    PARAMETRIZE { mon = SPECIES_JOLTIK, ability = ABILITY_UNNERVE; }
    PARAMETRIZE { mon = SPECIES_CALYREX_ICE, ability = ABILITY_AS_ONE_ICE_RIDER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        PLAYER(mon) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_NATURAL_GIFT); }
    } SCENE {
        ABILITY_POPUP(player, ability);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Unnerve prints the correct string (player)")
{
    u16 mon;
    enum Ability ability;
    PARAMETRIZE { mon = SPECIES_JOLTIK, ability = ABILITY_UNNERVE; }
    PARAMETRIZE { mon = SPECIES_CALYREX_ICE, ability = ABILITY_AS_ONE_ICE_RIDER; }
    GIVEN {
        PLAYER(mon) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ability);
        MESSAGE("The opposing side is too nervous to eat Berries!");
    }
}

SINGLE_BATTLE_TEST("Unnerve prints the correct string (opponent)")
{
    u16 mon;
    enum Ability ability;
    PARAMETRIZE { mon = SPECIES_JOLTIK, ability = ABILITY_UNNERVE; }
    PARAMETRIZE { mon = SPECIES_CALYREX_ICE, ability = ABILITY_AS_ONE_ICE_RIDER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(mon) { Ability(ability); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        MESSAGE("Your side is too nervous to eat Berries!");
    }
}

SINGLE_BATTLE_TEST("Unnerve activates only once per switch-in")
{
    u16 mon;
    enum Ability ability;
    PARAMETRIZE { mon = SPECIES_JOLTIK, ability = ABILITY_UNNERVE; }
    PARAMETRIZE { mon = SPECIES_CALYREX_ICE, ability = ABILITY_AS_ONE_ICE_RIDER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(mon) { Ability(ability); }
        OPPONENT(mon) { Ability(ability); }
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        NOT ABILITY_POPUP(opponent, ability);
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(opponent, ability);

    }
}

DOUBLE_BATTLE_TEST("Unnerve stops applying on death but applies on revive")
{
    u16 mon;
    enum Ability ability;
    PARAMETRIZE { mon = SPECIES_JOLTIK, ability = ABILITY_UNNERVE; }
    PARAMETRIZE { mon = SPECIES_CALYREX_ICE, ability = ABILITY_AS_ONE_ICE_RIDER; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RAWST_BERRY].holdEffect == HOLD_EFFECT_CURE_BRN);
        ASSUME(gItemsInfo[ITEM_REVIVE].battleUsage == EFFECT_ITEM_REVIVE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(mon) { Ability(ability); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RAWST_BERRY); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_RAWST_BERRY); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
        TURN {  USE_ITEM(playerLeft, ITEM_REVIVE, partyIndex: 1); SKIP_TURN(playerRight); MOVE(opponentLeft, MOVE_WILL_O_WISP, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
    }

}

SINGLE_BATTLE_TEST("Unnerve activates before other switch in abilities regardless of Speed")
{
    u32 speed = 0;

    PARAMETRIZE { speed = 50; }
    PARAMETRIZE { speed = 150; }

    GIVEN {
        PLAYER(SPECIES_PINSIR) { Speed(100); Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_JOLTIK) { Speed(speed); Ability(ABILITY_UNNERVE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_UNNERVE);
        ABILITY_POPUP(player, ABILITY_MOLD_BREAKER);
    }
}
