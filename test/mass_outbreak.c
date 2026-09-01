#include "global.h"
#include "event_data.h"
#include "mass_outbreak.h"
#include "test/overworld_script.h"
#include "test/test.h"

TEST("startoutbreak sets a static outbreak when called with only one argument")
{
    ASSUME(OUTBREAK_COUNT >= 1);
    ZeroMassOutbreak();

    gSpecialVar_0x8000 = 0;
    RUN_OVERWORLD_SCRIPT(
        setstaticoutbreak VAR_0x8000;
    );

    struct MassOutbreak outbreak = GetStaticOutbreak(0);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, outbreak.species);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(outbreak.location));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(outbreak.location));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, outbreak.level);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[i], outbreak.moves[i]);
    }
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, outbreak.probability);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, outbreak.duration);
}

TEST("startoutbreak can set a dynamic outbreak")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
    );

    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_BULBASAUR);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 2);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_SCRATCH);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_CELEBRATE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_FLAMETHROWER);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[3], MOVE_PSYCHIC);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 4);
}

TEST("startoutbreak can set a dynamic outbreak (vars)")
{
    ZeroMassOutbreak();

    VarSet(VAR_0x8000, SPECIES_BULBASAUR);
    VarSet(VAR_0x8001, 2);
    VarSet(VAR_0x8002, MOVE_SCRATCH);
    VarSet(VAR_0x8003, MOVE_CELEBRATE);
    VarSet(VAR_0x8004, MOVE_FLAMETHROWER);
    VarSet(VAR_0x8005, MOVE_PSYCHIC);
    VarSet(VAR_0x8006, 3);
    VarSet(VAR_0x8007, 4);
    VarSet(VAR_0x8008, MAP_OLDALE_TOWN);
    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=VAR_0x8000, level=VAR_0x8001, move1=VAR_0x8002, move2=VAR_0x8003, move3=VAR_0x8004, move4=VAR_0x8005, probability=VAR_0x8006, daysLeft=VAR_0x8007, map=VAR_0x8008;
    );

    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_BULBASAUR);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 2);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_SCRATCH);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_CELEBRATE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_FLAMETHROWER);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[3], MOVE_PSYCHIC);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 4);
}

TEST("editoutbreak doesn't touch unset arguments")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
        editoutbreak;
    );

    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_BULBASAUR);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_OLDALE_TOWN));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 2);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_SCRATCH);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_CELEBRATE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_FLAMETHROWER);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[3], MOVE_PSYCHIC);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 4);
}

TEST("checkhasactiveoutbreak sets the outbreak status to VAR_RESULT")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        checkhasactiveoutbreak;
    );

    EXPECT_EQ(gSpecialVar_Result, FALSE);

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
        checkhasactiveoutbreak;
    );
    EXPECT_EQ(gSpecialVar_Result, TRUE);
}

TEST("clearactiveoutbreak disables active outbreak")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
    );

    EXPECT_EQ(IsMassOutbreakActive(), TRUE);

    RUN_OVERWORLD_SCRIPT(
        clearactiveoutbreak;
    );

    EXPECT_EQ(IsMassOutbreakActive(), FALSE);
}

TEST("getmassoutbreakdata")
{
    ZeroMassOutbreak();

    RUN_OVERWORLD_SCRIPT(
        startoutbreak species=SPECIES_BULBASAUR, level=2, move1=MOVE_SCRATCH, move2=MOVE_CELEBRATE, move3=MOVE_FLAMETHROWER, move4=MOVE_PSYCHIC, probability=3, daysLeft=4, map=MAP_OLDALE_TOWN;
        getmassoutbreakdata VAR_0x8000, OUTBREAK_DATA_SPECIES;
        getmassoutbreakdata VAR_0x8001, OUTBREAK_DATA_MOVE1;
        getmassoutbreakdata VAR_0x8002, OUTBREAK_DATA_MOVE2;
        getmassoutbreakdata VAR_0x8003, OUTBREAK_DATA_MOVE3;
        getmassoutbreakdata VAR_0x8004, OUTBREAK_DATA_MOVE4;
        getmassoutbreakdata VAR_0x8005, OUTBREAK_DATA_LEVEL;
        getmassoutbreakdata VAR_0x8006, OUTBREAK_DATA_PROBABILITY;
        getmassoutbreakdata VAR_0x8007, OUTBREAK_DATA_DAYS_LEFT;
        getmassoutbreakdata VAR_0x8008, OUTBREAK_DATA_MAP;
    );

    EXPECT_EQ(gSpecialVar_0x8000, SPECIES_BULBASAUR);
    EXPECT_EQ(gSpecialVar_0x8001, MOVE_SCRATCH);
    EXPECT_EQ(gSpecialVar_0x8002, MOVE_CELEBRATE);
    EXPECT_EQ(gSpecialVar_0x8003, MOVE_FLAMETHROWER);
    EXPECT_EQ(gSpecialVar_0x8004, MOVE_PSYCHIC);
    EXPECT_EQ(gSpecialVar_0x8005, 2);
    EXPECT_EQ(gSpecialVar_0x8006, 3);
    EXPECT_EQ(gSpecialVar_0x8007, 4);
    EXPECT_EQ(gSpecialVar_0x8008, MAP_OLDALE_TOWN);
}

