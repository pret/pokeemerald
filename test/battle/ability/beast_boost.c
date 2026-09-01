#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Beast Boost boosts the most proficient stat when knocking out a target")
{
    u8 stats[] = {1, 1, 1, 1, 1};
    PARAMETRIZE { stats[0] = 255; }
    PARAMETRIZE { stats[1] = 255; }
    PARAMETRIZE { stats[2] = 255; }
    PARAMETRIZE { stats[3] = 255; }
    PARAMETRIZE { stats[4] = 255; }
    GIVEN {
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(stats[0]); Defense(stats[1]); SpAttack(stats[2]); SpDefense(stats[3]); Speed(stats[4]); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        enum Stat expectedStat = STAT_ATK;

        switch (i) {
        case 1:
            expectedStat = STAT_DEF;
            break;
        case 2:
            expectedStat = STAT_SPATK;
            break;
        case 3:
            expectedStat = STAT_SPDEF;
            break;
        case 4:
            expectedStat = STAT_SPEED;
            break;
        }

        EXPECT_EQ(player->statStages[expectedStat], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost doesn't trigger if user is fainted")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DESTINY_BOND) == EFFECT_DESTINY_BOND);
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KARTANA) { Ability(ABILITY_BEAST_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_BEAST_BOOST);
        SEND_IN_MESSAGE("Wynaut");
        MESSAGE("2 sent out Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Beast Boost prioritizes stats in the case of a tie in the following order: Atk, Def, Sp.Atk, Sp.Def, Speed")
{
    u8 stats[] = {1, 1, 1, 1, 1};

    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; stats[1] = 255; stats[0] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; stats[1] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; }
    GIVEN {
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(stats[0]); Defense(stats[1]); SpAttack(stats[2]); SpDefense(stats[3]); Speed(stats[4]); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        enum Stat expectedStat = STAT_ATK;

        switch (i) {
        case 1:
            expectedStat = STAT_DEF;
            break;
        case 2:
            expectedStat = STAT_SPATK;
            break;
        case 3:
            expectedStat = STAT_SPDEF;
            break;
        }

        EXPECT_EQ(player->statStages[expectedStat], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost considers Power Split")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POWER_SPLIT) == EFFECT_POWER_SPLIT);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(200); Defense(30); SpAttack(50); SpDefense(30); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Attack(10); SpAttack(250); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_SPLIT); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_SPLIT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost considers Guard Split")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARD_SPLIT) == EFFECT_GUARD_SPLIT);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(80); Defense(20); SpAttack(70); SpDefense(10); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Defense(200); SpDefense(30); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUARD_SPLIT); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARD_SPLIT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost considers Power Trick")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POWER_TRICK) == EFFECT_POWER_TRICK);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(40); Defense(200); SpAttack(60); SpDefense(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_TRICK); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_TRICK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost considers Wonder Room")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
        ASSUME(GetMovePower(MOVE_SCRATCH) > 0);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(100); Defense(50); SpAttack(70); SpDefense(200); Speed(120); Moves(MOVE_SPLASH, MOVE_EXTREME_SPEED); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(200); Moves(MOVE_WONDER_ROOM, MOVE_SPLASH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WONDER_ROOM); MOVE(player, MOVE_SPLASH); }
        TURN { MOVE(player, MOVE_EXTREME_SPEED); MOVE(opponent, MOVE_SPLASH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WONDER_ROOM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTREME_SPEED, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost considers Speed Swap")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPEED_SWAP) == EFFECT_SPEED_SWAP);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(60); Defense(60); SpAttack(70); SpDefense(60); Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SPEED_SWAP); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPEED_SWAP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost doesn't consider stat stages")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Attack(100); Defense(60); SpAttack(150); SpDefense(60); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost doesn't consider held items")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Item(ITEM_CHOICE_BAND); Attack(120); Defense(60); SpAttack(150); SpDefense(60); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Beast Boost doesn't consider status condition reductions")
{
    GIVEN {
        PLAYER(SPECIES_NIHILEGO) { Ability(ABILITY_BEAST_BOOST); Status1(STATUS1_BURN); Attack(150); Defense(60); SpAttack(100); SpDefense(60); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(player, ABILITY_BEAST_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}
