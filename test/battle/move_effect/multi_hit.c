#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_BULLET_SEED].effect == EFFECT_MULTI_HIT);
}

SINGLE_BATTLE_TEST("Multi hit Moves hit the maximum amount with Skill Link")
{
    PASSES_RANDOMLY(100, 100, RNG_HITS);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SKILL_LINK); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 5 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit twice 35% of the time")
{
    PASSES_RANDOMLY(35, 100, RNG_HITS);

    GIVEN {
        ASSUME(B_MULTI_HIT_CHANCE >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 2 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit thrice 35% of the time")
{
    PASSES_RANDOMLY(35, 100, RNG_HITS);

    GIVEN {
        ASSUME(B_MULTI_HIT_CHANCE >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 3 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit four times 15% of the time")
{
    PASSES_RANDOMLY(15, 100, RNG_HITS);

    GIVEN {
        ASSUME(B_MULTI_HIT_CHANCE >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 4 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit five times 15% of the time")
{
    PASSES_RANDOMLY(15, 100, RNG_HITS);

    GIVEN {
        ASSUME(B_MULTI_HIT_CHANCE >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 5 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit at least four times with Loaded Dice")
{
    PASSES_RANDOMLY(50, 100, RNG_LOADED_DICE);

    GIVEN {
        ASSUME(gItemsInfo[ITEM_LOADED_DICE].holdEffect == HOLD_EFFECT_LOADED_DICE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LOADED_DICE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 4 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit five times 50 Percent of the time with Loaded Dice")
{
    PASSES_RANDOMLY(50, 100, RNG_LOADED_DICE);

    GIVEN {
        ASSUME(gItemsInfo[ITEM_LOADED_DICE].holdEffect == HOLD_EFFECT_LOADED_DICE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LOADED_DICE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("Hit 5 time(s)!");
    }
}

SINGLE_BATTLE_TEST("Scale Shot decreases defense and increases speed after final hit")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCALE_SHOT].effect == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCALE_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("Hit 5 time(s)!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Endure does not prevent multiple hits and stat changes occur at the end of the turn")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCALE_SHOT].effect == EFFECT_MULTI_HIT);
        ASSUME(gMovesInfo[MOVE_ENDURE].effect == EFFECT_ENDURE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_SCALE_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("Hit 5 time(s)!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Scale Shot decreases defense and increases speed after the 4th hit of Loaded Dice")
{
    PASSES_RANDOMLY(50, 100, RNG_LOADED_DICE);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCALE_SHOT].effect == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LOADED_DICE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCALE_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("Hit 4 time(s)!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Scale Shot decreases defense and increases speed after killing opposing with less then 4 hits")
{
    u32 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_LOADED_DICE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCALE_SHOT].effect == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_BAGON) { Item(item); }
        OPPONENT(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCALE_SHOT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("Foe Slugma fainted!");
        MESSAGE("Hit 3 time(s)!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Bagon's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Bagon's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Multi Hit moves will not disrupt Destiny Bond flag")
{
    u32 hp;
    PARAMETRIZE { hp = 11; }
    PARAMETRIZE { hp = 55; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(55); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); MOVE(opponent, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, opponent);
        if (hp == 55)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, opponent);
        }
        MESSAGE("Wobbuffet took Foe Wobbuffet with it!");
        MESSAGE("Foe Wobbuffet fainted!");
    }
}
