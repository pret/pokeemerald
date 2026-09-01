#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GRAVITY) == EFFECT_GRAVITY);
}

TO_DO_BATTLE_TEST("Gravity causes certain moves to fail") // Fly, Jump Kick, High Jump Kick, Splash, Bounce, Magnet Rise, Telekinesis, Sky Drop, Flying Press, Floaty Fall
TO_DO_BATTLE_TEST("Gravity increases accuracy of all moves by 5/3 (~1.67)")
TO_DO_BATTLE_TEST("Gravity causes all battlers to become grounded")

DOUBLE_BATTLE_TEST("Gravity cancels Fly and Sky Drop if they are in the air")
{
    u8 visibility;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WYNAUT) { Speed(90); }
        OPPONENT(SPECIES_PIDGEY) { Speed(50); }
        OPPONENT(SPECIES_ROOKIDEE) { Speed(45); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SKY_DROP, target: playerRight); MOVE(opponentRight, MOVE_FLY, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_GRAVITY); SKIP_TURN(opponentRight); SKIP_TURN(opponentLeft); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Pidgey used Sky Drop!");
        MESSAGE("The opposing Pidgey took Wynaut into the sky!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft);
        MESSAGE("The opposing Rookidee used Fly!");
        MESSAGE("The opposing Rookidee flew up high!");
        // turn 2
        MESSAGE("Wobbuffet used Gravity!");
        MESSAGE("Gravity intensified!");
        MESSAGE("The opposing Pidgey fell from the sky due to the gravity!");
        MESSAGE("The opposing Rookidee fell from the sky due to the gravity!");
        MESSAGE("The opposing Pidgey can't use Sky Drop because of gravity!");
        MESSAGE("The opposing Rookidee can't use Fly because of gravity!");
    } THEN {
        // all battlers should be visible. assign to var first because expect_eq not working with bitfield address
        visibility = gBattleSpritesDataPtr->battlerData[0].invisible;
        EXPECT_EQ(visibility, 0);
        visibility = gBattleSpritesDataPtr->battlerData[1].invisible;
        EXPECT_EQ(visibility, 0);
        visibility = gBattleSpritesDataPtr->battlerData[2].invisible;
        EXPECT_EQ(visibility, 0);
        visibility = gBattleSpritesDataPtr->battlerData[3].invisible;
        EXPECT_EQ(visibility, 0);
        // ensure moveend properly recorded
        EXPECT_EQ(gLastMoves[0], MOVE_GRAVITY);
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Gravity")
{
    enum Move move;
    enum Item friendItem, foeItem;
    u64 aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT;

    PARAMETRIZE { move = MOVE_THUNDER; friendItem = ITEM_NONE; foeItem = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_HEADBUTT; friendItem = ITEM_AIR_BALLOON; foeItem = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_HEADBUTT; friendItem = ITEM_AIR_BALLOON; foeItem = ITEM_AIR_BALLOON; }
    PARAMETRIZE { move = MOVE_HEADBUTT; friendItem = ITEM_NONE; foeItem = ITEM_AIR_BALLOON; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  move = MOVE_THUNDER; friendItem = ITEM_NONE; foeItem = ITEM_NONE; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  move = MOVE_HEADBUTT; friendItem = ITEM_AIR_BALLOON; foeItem = ITEM_NONE; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  move = MOVE_HEADBUTT; friendItem = ITEM_AIR_BALLOON; foeItem = ITEM_AIR_BALLOON; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  move = MOVE_HEADBUTT; friendItem = ITEM_NONE; foeItem = ITEM_AIR_BALLOON; }

    GIVEN {
        AI_FLAGS(aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { Item(foeItem); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_GRAVITY, MOVE_HEADBUTT, MOVE_TAUNT); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_EARTH_POWER); Item(friendItem); }
    } WHEN {
    if (move == MOVE_THUNDER || (foeItem == ITEM_AIR_BALLOON && friendItem != ITEM_AIR_BALLOON))
        TURN { EXPECT_MOVE(opponentLeft, MOVE_GRAVITY); }
    else
        TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_GRAVITY); }
    }
}
