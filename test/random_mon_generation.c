#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "pokemon.h"
#include "random_mon_generation.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokeball.h"
#include "constants/species.h"
#include "constants/vars.h"

#define TEST_SPECIES_GENERATOR_FILTERED_POOL 0
#define TEST_SPECIES_GENERATOR_MYTHICAL_FILTER 1
#define TEST_SPECIES_GENERATOR_BST_FILTER 2
#define TEST_SPECIES_GENERATOR_NO_ARG_FILTER 3
#define TEST_SPECIES_GENERATOR_FORM_FILTER 4

#define TEST_ITEM_GENERATOR_SINGLE_ITEM 0
#define TEST_ITEM_GENERATOR_FILTERED_POOL 1
#define TEST_ITEM_GENERATOR_NONE_POOL 2
#define TEST_ITEM_GENERATOR_HARD_BANNED_POOL 3
#define TEST_ITEM_GENERATOR_HELD_ITEM_FILTER 4

static enum Item GetRandomItemForTest(u32 optionId)
{
    const struct FilterFuncArgs filterFuncArgs = {0};

    return GetRandomItem(optionId, &filterFuncArgs);
}

TEST("Random mon generation filters species from a small pool")
{
    const struct FilterFuncArgs filterFuncArgs = {FILTER_FUNC_ARG_NONE, FILTER_FUNC_ARG_NONE};
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_FILTERED_POOL, &filterFuncArgs);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
}

TEST("Random mon generation rejects disallowed mythical species")
{
    const struct FilterFuncArgs filterFuncArgs = {FILTER_FUNC_ARG_NONE, FILTER_FUNC_ARG_NONE};
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_MYTHICAL_FILTER, &filterFuncArgs);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
}

TEST("Random mon generation allows species within BST vars")
{
    const struct FilterFuncArgs filterFuncArgs = {400, 10};
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_BST_FILTER, &filterFuncArgs);

    EXPECT_EQ(species, SPECIES_WOBBUFFET);
}

TEST("Random mon generation rejects species outside BST vars")
{
    const struct FilterFuncArgs filterFuncArgs = {600, 10};
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_BST_FILTER, &filterFuncArgs);

    EXPECT_EQ(species, SPECIES_MEW);
}

TEST("Random mon generation allows filter funcs with no args")
{
    const struct FilterFuncArgs filterFuncArgs = {FILTER_FUNC_ARG_NONE, FILTER_FUNC_ARG_NONE};
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_NO_ARG_FILTER, &filterFuncArgs);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
}

TEST("Random mon generation resolves variant forms before applying filter funcs")
{
    const struct FilterFuncArgs filterFuncArgs = {FILTER_FUNC_ARG_NONE, FILTER_FUNC_ARG_NONE};
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_FORM_FILTER, &filterFuncArgs);

    EXPECT_EQ(species, SPECIES_ROTOM_HEAT);
}

TEST("Random mon generation resolves held item from a pool")
{
    enum Item item = GetRandomItemForTest(TEST_ITEM_GENERATOR_SINGLE_ITEM);

    EXPECT_EQ(item, ITEM_LEFTOVERS);
}

TEST("Random mon generation filters banned hold effects from a small pool")
{
    enum Item item = GetRandomItemForTest(TEST_ITEM_GENERATOR_FILTERED_POOL);

    EXPECT_EQ(item, ITEM_LUM_BERRY);
}

TEST("Random mon generation allows ITEM_NONE in an explicit item pool")
{
    enum Item item = GetRandomItemForTest(TEST_ITEM_GENERATOR_NONE_POOL);

    EXPECT_EQ(item, ITEM_NONE);
}

TEST("Random mon generation forbids key items and zero-price TMs/HMs")
{
    enum Item item = GetRandomItemForTest(TEST_ITEM_GENERATOR_HARD_BANNED_POOL);

    EXPECT_EQ(item, ITEM_LEFTOVERS);
}

TEST("Random mon generation supports held item filter funcs")
{
    enum Item item = GetRandomItemForTest(TEST_ITEM_GENERATOR_HELD_ITEM_FILTER);

    EXPECT_EQ(item, ITEM_LEFTOVERS);
}

TEST("ResolveMoves resolves teachable moves")
{
    enum Species species = SPECIES_CHARIZARD;
    u16 moves[MAX_MON_MOVES] = {MOVE_RANDOM_TEACHABLE, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};
    enum Move finalMoves[MAX_MON_MOVES];

    ResolveMoves(species, 100, moves, finalMoves);

    EXPECT_NE(finalMoves[0], MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(finalMoves[0], MOVE_NONE);
}

TEST("Random mon generation commands set vars for createmon")
{
    ZeroPlayerPartyMons();

    RUN_OVERWORLD_SCRIPT(
        getrandomspecies VAR_0x8000, TEST_SPECIES_GENERATOR_FILTERED_POOL;
        getrandomitem VAR_0x8001, TEST_ITEM_GENERATOR_SINGLE_ITEM;
        createmon 1, 0, VAR_0x8000, 50, item=VAR_0x8001, ball=BALL_MASTER, move1=MOVE_RANDOM_TEACHABLE, move2=MOVE_DEFAULT;
    );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES), SPECIES_CHARIZARD);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEVEL), 50);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_POKEBALL), BALL_MASTER);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_MOVE1), MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_MOVE1), MOVE_NONE);
}

TEST("Random mon generation command forwards filter args")
{
    RUN_OVERWORLD_SCRIPT(
        getrandomspecies VAR_0x8000, TEST_SPECIES_GENERATOR_BST_FILTER, arg1=400, arg2=10;
    );

    EXPECT_EQ(VarGet(VAR_0x8000), SPECIES_WOBBUFFET);
}
