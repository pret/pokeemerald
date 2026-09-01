#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(IsMultiHitMove(MOVE_BULLET_SEED));
}

SINGLE_BATTLE_TEST("Multi hit Moves hit the maximum amount with Skill Link")
{
    PASSES_RANDOMLY(100, 100, RNG_HITS);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SKILL_LINK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("The Pokémon was hit 5 times!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit twice 37.5/35% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 3;  trials = 8; }
    PARAMETRIZE { genConfig = GEN_5; passes = 7; trials = 20; }
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("The Pokémon was hit 2 times!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit thrice 37.5/35% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 3; trials = 8; }
    PARAMETRIZE { genConfig = GEN_5; passes = 7; trials = 20; }
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("The Pokémon was hit 3 times!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit four times 12.5/15% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 1; trials = 8; }
    PARAMETRIZE { genConfig = GEN_5; passes = 3; trials = 20; }
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLET_SEED, player);
        MESSAGE("The Pokémon was hit 4 times!");
    }
}

SINGLE_BATTLE_TEST("Multi hit Moves hit five times 12.5/15% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 1; trials = 8; }
    PARAMETRIZE { genConfig = GEN_5; passes = 3; trials = 20; }
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
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
        MESSAGE("The Pokémon was hit 5 times!");
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
        MESSAGE("The Pokémon was hit 4 times!");
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
        MESSAGE("The Pokémon was hit 5 times!");
    }
}

SINGLE_BATTLE_TEST("Scale Shot decreases defense and increases speed after final hit")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_SCALE_SHOT));
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
        MESSAGE("The Pokémon was hit 5 times!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Scale Shot is immune to Fairy types and will end the move correctly")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_SCALE_SHOT));
        ASSUME(GetMoveType(MOVE_SCALE_SHOT) == TYPE_DRAGON);
        ASSUME(GetSpeciesType(SPECIES_FIDOUGH, 0) == TYPE_FAIRY || GetSpeciesType(SPECIES_FIDOUGH, 1) == TYPE_FAIRY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FIDOUGH) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCALE_SHOT); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("It doesn't affect the opposing Fidough…");
    }
}

DOUBLE_BATTLE_TEST("Scale Shot does not corrupt the next turn move used")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_SCALE_SHOT));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCALE_SHOT, target: opponentRight); SWITCH(playerLeft, 2); SEND_OUT(opponentRight, 2); }
        TURN { MOVE(playerRight, MOVE_BULLDOZE); MOVE(playerLeft, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(opponentLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, playerRight);
        HP_BAR(opponentRight);
        MESSAGE("The Pokémon was hit 1 time!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, playerRight);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

SINGLE_BATTLE_TEST("Scale Shot decreases defense and increases speed after the 4th hit of Loaded Dice")
{
    PASSES_RANDOMLY(50, 100, RNG_LOADED_DICE);
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_SCALE_SHOT));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LOADED_DICE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCALE_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("The Pokémon was hit 4 times!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

SINGLE_BATTLE_TEST("Scale Shot decreases defense and increases speed after killing opposing with less then 4 hits")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_LOADED_DICE; }

    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_SCALE_SHOT));
        PLAYER(SPECIES_BAGON) { Item(item); }
        OPPONENT(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCALE_SHOT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("The opposing Slugma fainted!");
        MESSAGE("The Pokémon was hit 3 times!");
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
        MESSAGE("Wobbuffet took its attacker down with it!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}
