#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
}

SINGLE_BATTLE_TEST("Belly Drum cuts the user's HP in half")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        HP_BAR(player, hp: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Belly Drum maximizes the user's Attack stat", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet cut its own HP and maximized its Attack!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Belly Drum fails if user's current HP is half or less than half its maximum")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(50); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Belly Drum fails if the user's Attack is already at +6")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose sharply!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose sharply!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack rose sharply!");

        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Belly Drum's HP cost doesn't trigger effects that trigger on damage taken")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        MESSAGE("Wobbuffet cut its own HP and maximized its Attack!");
        NOT MESSAGE("Wobbuffet's Air Balloon popped!");
    }
}

SINGLE_BATTLE_TEST("Belly Drum minimizes the user's Attack stat with Contrary", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet cut its own HP and maximized its Attack!");  // Message unaffected by Contrary
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(4), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Belly Drum maximizes the user's Attack stat, even when below 0", s16 damage)
{
    bool32 raiseAttack;
    PARAMETRIZE { raiseAttack = FALSE; }
    PARAMETRIZE { raiseAttack = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (raiseAttack) TURN { MOVE(opponent, MOVE_GROWL); MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (raiseAttack) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet cut its own HP and maximized its Attack!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (raiseAttack) EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 6);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Belly Drum fails if the user's Attack is already at +6, even with Contrary")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        PLAYER(SPECIES_SERPERIOR) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Serperior's Attack rose sharply!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Serperior's Attack rose sharply!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Serperior's Attack rose sharply!");

        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Belly Drum deducts HP if the user has Contrary and is at -6")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_SERPERIOR) { Ability(ABILITY_CONTRARY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Serperior's Attack harshly fell!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Serperior's Attack harshly fell!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Serperior's Attack harshly fell!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        HP_BAR(player, hp: maxHP / 2);
        MESSAGE("Serperior cut its own HP and maximized its Attack!");
    }
}
