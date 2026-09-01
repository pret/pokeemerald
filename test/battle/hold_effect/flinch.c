#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_KINGS_ROCK].holdEffect == HOLD_EFFECT_FLINCH);
}

SINGLE_BATTLE_TEST("Kings Rock holder will flinch the target 10% of the time")
{
    PASSES_RANDOMLY(10, 100, RNG_HOLD_EFFECT_FLINCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_KINGS_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}

SINGLE_BATTLE_TEST("Kings Rock does not increase flinch chance of a move that has the flinch effect")
{
    PASSES_RANDOMLY(30, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_HEADBUTT, MOVE_EFFECT_FLINCH));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_KINGS_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEADBUTT, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}

DOUBLE_BATTLE_TEST("Kings Rock flinch chance boosted by Serene Grace does not stack with rainbow")
{
    PASSES_RANDOMLY(20, 100, RNG_HOLD_EFFECT_FLINCH);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WATER_PLEDGE) == EFFECT_PLEDGE);
        ASSUME(GetMoveEffect(MOVE_FIRE_PLEDGE) == EFFECT_PLEDGE);
        PLAYER(SPECIES_TOGEPI) { Speed(4); Ability(ABILITY_SERENE_GRACE); Item(ITEM_KINGS_ROCK); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN
        {
            MOVE(playerLeft, MOVE_WATER_PLEDGE, target : opponentLeft);
            MOVE(playerRight, MOVE_FIRE_PLEDGE, target : opponentRight);
        }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}
