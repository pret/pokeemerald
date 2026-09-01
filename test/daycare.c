#include "global.h"
#include "config_changes.h"
#include "daycare.h"
#include "event_data.h"
#include "item.h"
#include "malloc.h"
#include "party_menu.h"
#include "regions.h"
#include "constants/pokeball.h"
#include "test/overworld_script.h"
#include "test/test.h"

// We don't run the StoreSelectedPokemonInDaycare special because it relies on calling the
// party select screen and the GetCursorSelectionMonId function, so we store directly to the struct.
#define STORE_IN_DAYCARE_AND_GET_EGG()                                          \
    StorePokemonInDaycare(&gParties[B_TRAINER_PLAYER][0], &gSaveBlock1Ptr->daycare.mons[0]);  \
    StorePokemonInDaycare(&gParties[B_TRAINER_PLAYER][0], &gSaveBlock1Ptr->daycare.mons[1]);  \
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

TEST("(Daycare) Pokémon generate Eggs of the lowest member of the evolutionary family")
{
    ASSUME(P_FAMILY_PIKACHU == TRUE);
    ASSUME(P_GEN_2_CROSS_EVOS == TRUE);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100, gender=MON_MALE;
        givemon SPECIES_PIKACHU, 100, gender=MON_FEMALE;
    );
    STORE_IN_DAYCARE_AND_GET_EGG();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_PICHU);
}

TEST("(Daycare) Pokémon offspring species is based off the mother's species")
{
    u32 offspring = 0;
    ASSUME(P_FAMILY_PIKACHU == TRUE);
    ASSUME(P_GEN_2_CROSS_EVOS == TRUE);
    ASSUME(P_FAMILY_RIOLU == TRUE);

    ZeroPlayerPartyMons();
    PARAMETRIZE { offspring = SPECIES_RIOLU; RUN_OVERWORLD_SCRIPT(givemon SPECIES_PIKACHU, 100, gender=MON_MALE;   givemon SPECIES_LUCARIO, 100, gender=MON_FEMALE, item=ITEM_NONE;     ); }
    PARAMETRIZE { offspring = SPECIES_PICHU; RUN_OVERWORLD_SCRIPT(givemon SPECIES_PIKACHU, 100, gender=MON_FEMALE; givemon SPECIES_LUCARIO, 100, gender=MON_MALE;); }
    STORE_IN_DAYCARE_AND_GET_EGG();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), offspring);
}

TEST("(Daycare) Pokémon can breed with Ditto if they don't belong to the Ditto or No Eggs Discovered group")
{
    u32 j = 0;
    enum Species parentSpecies = 0;

    ZeroPlayerPartyMons();
    for (j = 1; j < NUM_SPECIES; j++)
    {
        if (IsSpeciesEnabled(j))
            PARAMETRIZE { parentSpecies = j; }
    }
    VarSet(VAR_TEMP_C, parentSpecies);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_DITTO, 100; givemon VAR_TEMP_C, 100;
    );
    STORE_IN_DAYCARE_AND_GET_EGG();

    if (gSpeciesInfo[parentSpecies].eggGroups[0] != EGG_GROUP_NO_EGGS_DISCOVERED
     && gSpeciesInfo[parentSpecies].eggGroups[0] != EGG_GROUP_DITTO)
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_NONE);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("(Daycare) Shellos' form is always based on the mother's form")
{
    u32 offspring = 0;
    ASSUME(P_FAMILY_MEOWTH == TRUE);
    ASSUME(P_ALOLAN_FORMS == TRUE);
    ASSUME(P_GALARIAN_FORMS == TRUE);

    ZeroPlayerPartyMons();
    PARAMETRIZE { offspring = SPECIES_SHELLOS_WEST; RUN_OVERWORLD_SCRIPT(givemon SPECIES_SHELLOS_EAST, 1, gender=MON_MALE; givemon SPECIES_SHELLOS_WEST, 1, gender=MON_FEMALE, item=ITEM_NONE;     ); }
    PARAMETRIZE { offspring = SPECIES_SHELLOS_WEST; RUN_OVERWORLD_SCRIPT(givemon SPECIES_SHELLOS_EAST, 1, gender=MON_MALE, item=ITEM_EVERSTONE; givemon SPECIES_SHELLOS_WEST, 1, gender=MON_FEMALE, item=ITEM_NONE;     ); }
    PARAMETRIZE { offspring = SPECIES_SHELLOS_WEST; RUN_OVERWORLD_SCRIPT(givemon SPECIES_SHELLOS_EAST, 1, gender=MON_MALE; givemon SPECIES_SHELLOS_WEST, 1, gender=MON_FEMALE, item=ITEM_EVERSTONE;); }
    PARAMETRIZE { offspring = SPECIES_SHELLOS_EAST; RUN_OVERWORLD_SCRIPT(givemon SPECIES_SHELLOS_WEST, 1, gender=MON_MALE; givemon SPECIES_SHELLOS_EAST, 1, gender=MON_FEMALE, item=ITEM_NONE;     ); }
    PARAMETRIZE { offspring = SPECIES_SHELLOS_EAST; RUN_OVERWORLD_SCRIPT(givemon SPECIES_SHELLOS_WEST, 1, gender=MON_MALE, item=ITEM_EVERSTONE; givemon SPECIES_SHELLOS_EAST, 1, gender=MON_FEMALE, item=ITEM_NONE;     ); }
    PARAMETRIZE { offspring = SPECIES_SHELLOS_EAST; RUN_OVERWORLD_SCRIPT(givemon SPECIES_SHELLOS_WEST, 1, gender=MON_MALE; givemon SPECIES_SHELLOS_EAST, 1, gender=MON_FEMALE, item=ITEM_EVERSTONE;); }
    STORE_IN_DAYCARE_AND_GET_EGG();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), offspring);
}

TEST("(Daycare) Pokémon with regional forms give the correct offspring")
{
    enum Region region;
    enum Species offspring, species1, species2;
    enum Item item1, item2;

    ZeroPlayerPartyMons();

    region = GetCurrentRegion();
    if (region == REGION_ALOLA) {
        PARAMETRIZE { offspring=SPECIES_MEOWTH_ALOLA;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_ALOLA;  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_ALOLA;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_ALOLA;  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_ALOLA;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_ALOLA;  species1=SPECIES_DIGLETT;       item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_DIGLETT;       item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_PERRSERKER;    item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN;       item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_PERRSERKER;    item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN;       item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_PERSIAN_ALOLA; item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN;       item2=ITEM_EVERSTONE; }
    } else if (region == REGION_GALAR) {
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_ALOLA;  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_ALOLA;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_ALOLA;  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_DIGLETT;       item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_DIGLETT;       item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR;  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_PERRSERKER;    item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN;       item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_PERRSERKER;    item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN;       item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_PERSIAN_ALOLA; item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN;       item2=ITEM_EVERSTONE; }
    } else {
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_ALOLA,  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_ALOLA;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_ALOLA,  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR,  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_MEOWTH;        item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR,  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_DIGLETT;       item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR,  item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_DIGLETT;       item1=ITEM_NONE;      species2=SPECIES_MEOWTH_GALAR,  item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH_GALAR;  species1=SPECIES_PERRSERKER;    item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN,       item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_PERRSERKER;    item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN,       item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_MEOWTH;        species1=SPECIES_PERSIAN_ALOLA; item1=ITEM_EVERSTONE; species2=SPECIES_PERSIAN,       item2=ITEM_EVERSTONE; }
    }

    if (region == REGION_HISUI) {
        PARAMETRIZE { offspring=SPECIES_SNEASEL_HISUI; species1=SPECIES_SNEASEL;       item1=ITEM_NONE;      species2=SPECIES_SNEASEL_HISUI, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_SNEASEL;       species1=SPECIES_SNEASEL;       item1=ITEM_EVERSTONE; species2=SPECIES_SNEASEL_HISUI, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_SNEASEL_HISUI; species1=SPECIES_SNEASEL;       item1=ITEM_NONE;      species2=SPECIES_SNEASEL_HISUI, item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_SNEASEL;       species1=SPECIES_SNEASLER;      item1=ITEM_EVERSTONE; species2=SPECIES_WEAVILE,       item2=ITEM_EVERSTONE; }
    } else {
        PARAMETRIZE { offspring=SPECIES_SNEASEL;       species1=SPECIES_SNEASEL;       item1=ITEM_NONE;      species2=SPECIES_SNEASEL_HISUI, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_SNEASEL;       species1=SPECIES_SNEASEL;       item1=ITEM_EVERSTONE; species2=SPECIES_SNEASEL_HISUI, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_SNEASEL_HISUI; species1=SPECIES_SNEASEL;       item1=ITEM_NONE;      species2=SPECIES_SNEASEL_HISUI, item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_SNEASEL;       species1=SPECIES_SNEASLER;      item1=ITEM_EVERSTONE; species2=SPECIES_WEAVILE,       item2=ITEM_EVERSTONE; }
    }

    if (region == REGION_PALDEA) {
        PARAMETRIZE { offspring=SPECIES_WOOPER_PALDEA; species1=SPECIES_WOOPER;        item1=ITEM_NONE;      species2=SPECIES_WOOPER_PALDEA, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_WOOPER;        species1=SPECIES_WOOPER;        item1=ITEM_EVERSTONE; species2=SPECIES_WOOPER_PALDEA, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_WOOPER_PALDEA; species1=SPECIES_WOOPER;        item1=ITEM_NONE;      species2=SPECIES_WOOPER_PALDEA, item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_WOOPER;        species1=SPECIES_CLODSIRE;      item1=ITEM_EVERSTONE; species2=SPECIES_QUAGSIRE,      item2=ITEM_EVERSTONE; }
    } else {
        PARAMETRIZE { offspring=SPECIES_WOOPER;        species1=SPECIES_WOOPER;        item1=ITEM_NONE;      species2=SPECIES_WOOPER_PALDEA, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_WOOPER;        species1=SPECIES_WOOPER;        item1=ITEM_EVERSTONE; species2=SPECIES_WOOPER_PALDEA, item2=ITEM_NONE;      }
        PARAMETRIZE { offspring=SPECIES_WOOPER_PALDEA; species1=SPECIES_WOOPER;        item1=ITEM_NONE;      species2=SPECIES_WOOPER_PALDEA, item2=ITEM_EVERSTONE; }
        PARAMETRIZE { offspring=SPECIES_WOOPER;        species1=SPECIES_CLODSIRE;      item1=ITEM_EVERSTONE; species2=SPECIES_QUAGSIRE,      item2=ITEM_EVERSTONE; }
    }
    ASSUME(IsSpeciesEnabled(species1) == TRUE);
    ASSUME(IsSpeciesEnabled(species2) == TRUE);
    ASSUME(IsSpeciesEnabled(offspring) == TRUE);

    VarSet(VAR_0x8000, species1);
    VarSet(VAR_0x8001, item1);
    VarSet(VAR_0x8002, species2);
    VarSet(VAR_0x8003, item2);

    RUN_OVERWORLD_SCRIPT(givemon VAR_0x8000, 1, gender=MON_MALE,   item=VAR_0x8001;);
    RUN_OVERWORLD_SCRIPT(givemon VAR_0x8002, 1, gender=MON_FEMALE, item=VAR_0x8003;);

    STORE_IN_DAYCARE_AND_GET_EGG();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), offspring);
}

TEST("(Daycare) Pokémon can teach egg moves to their daycare partner (Gen 8)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_CURSE));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_INGRAIN));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_NATURE_POWER));

    u32 slot  = 0;
    PARAMETRIZE { slot = 0; }
    PARAMETRIZE { slot = 1; }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_8);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_TACKLE, move2=MOVE_NONE, move3=MOVE_NONE, move4=MOVE_NONE;
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_CURSE, move2=MOVE_INGRAIN, move3=MOVE_NATURE_POWER, move4=MOVE_PETAL_DANCE;
    );
    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = slot;
    TakePokemonFromDaycare();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1), MOVE_TACKLE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE2), MOVE_CURSE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE3), MOVE_INGRAIN);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_NATURE_POWER);
}

TEST("(Daycare) Pokémon don't learn move from their daycare partner if they lack empty move slot (Gen 8)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_CURSE));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_INGRAIN));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_NATURE_POWER));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_PETAL_DANCE));

    u32 slot  = 0;
    PARAMETRIZE { slot = 0; }
    PARAMETRIZE { slot = 1; }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_8);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_TACKLE, move2=MOVE_GROWL, move3=MOVE_VINE_WHIP, move4=MOVE_GROWTH;
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_CURSE, move2=MOVE_INGRAIN, move3=MOVE_NATURE_POWER, move4=MOVE_PETAL_DANCE;
    );
    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = slot;
    TakePokemonFromDaycare();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1), MOVE_TACKLE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE2), MOVE_GROWL);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE3), MOVE_VINE_WHIP);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_GROWTH);
}


TEST("(Daycare) Only Pokémon with the same base species can share egg moves (Gen 8)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_SCATTERBUG, MOVE_RAGE_POWDER));
    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_8);

    enum Species teacherSpecies = SPECIES_NONE;
    PARAMETRIZE { teacherSpecies = SPECIES_VIVILLON_SUN; }
    PARAMETRIZE { teacherSpecies = SPECIES_AMOONGUSS; }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = teacherSpecies;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_VIVILLON_POLAR, 100, move4=MOVE_NONE;
        givemon VAR_0x8000, 100, move1=MOVE_RAGE_POWDER;
    );

    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();
    TakePokemonFromDaycare();

    if (teacherSpecies == SPECIES_VIVILLON_SUN)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_RAGE_POWDER);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_NONE);
}

TEST("(Daycare) Pokémon can teach egg moves to their daycare partner (Gen 9)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_CURSE));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_INGRAIN));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_NATURE_POWER));

    u32 slot  = 0;
    PARAMETRIZE { slot = 0; }
    PARAMETRIZE { slot = 1; }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_9);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_TACKLE, move2=MOVE_NONE, move3=MOVE_NONE, move4=MOVE_NONE, item=ITEM_MIRROR_HERB;
        givemon SPECIES_VENUSAUR, 100, move1=MOVE_CURSE, move2=MOVE_INGRAIN, move3=MOVE_NATURE_POWER, move4=MOVE_PETAL_DANCE;
    );
    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = slot;
    TakePokemonFromDaycare();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1), MOVE_TACKLE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE2), MOVE_CURSE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE3), MOVE_INGRAIN);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_NATURE_POWER);
}

TEST("(Daycare) Pokémon need to hold a mirror herb to learn move in daycare (Gen 9)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_CURSE));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_INGRAIN));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_NATURE_POWER));

    enum Item heldItem  = ITEM_NONE;
    PARAMETRIZE { heldItem = ITEM_MIRROR_HERB; }
    PARAMETRIZE { heldItem = ITEM_NONE; }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_9);
    gSpecialVar_0x8000 = heldItem;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, move4=MOVE_NONE, item=VAR_0x8000;
        givemon SPECIES_VENUSAUR, 100, move1=MOVE_CURSE, move2=MOVE_INGRAIN, move3=MOVE_NATURE_POWER, move4=MOVE_PETAL_DANCE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();
    TakePokemonFromDaycare();
    if (heldItem == ITEM_MIRROR_HERB)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_CURSE);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_NONE);
}

TEST("(Daycare) Pokémon can't learn through egg move transfer a move they already know (Gen 9)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_CURSE));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_INGRAIN));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_NATURE_POWER));

    enum Move knownMove1 = 0;
    enum Move knownMove2 = 0;
    enum Move knownMove3 = 0;
    enum Move expectedMove = 0;
    PARAMETRIZE { knownMove1 = MOVE_TACKLE; knownMove2 = MOVE_GROWL; knownMove3 = MOVE_VINE_WHIP; expectedMove = MOVE_CURSE; }
    PARAMETRIZE { knownMove1 = MOVE_CURSE; knownMove2 = MOVE_GROWL; knownMove3 = MOVE_VINE_WHIP; expectedMove = MOVE_INGRAIN; }
    PARAMETRIZE { knownMove1 = MOVE_CURSE; knownMove2 = MOVE_INGRAIN; knownMove3 = MOVE_VINE_WHIP; expectedMove = MOVE_NATURE_POWER; }
    PARAMETRIZE { knownMove1 = MOVE_CURSE; knownMove2 = MOVE_INGRAIN; knownMove3 = MOVE_NATURE_POWER; expectedMove = MOVE_NONE; }


    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_9);
    gSpecialVar_0x8001 = knownMove1;
    gSpecialVar_0x8002 = knownMove2;
    gSpecialVar_0x8003 = knownMove3;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, move1=VAR_0x8001, move2=VAR_0x8002, move3=VAR_0x8003, move4=MOVE_NONE, item=ITEM_MIRROR_HERB;
        givemon SPECIES_VENUSAUR, 100, move1=MOVE_CURSE, move2=MOVE_INGRAIN, move3=MOVE_NATURE_POWER, move4=MOVE_TACKLE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();
    TakePokemonFromDaycare();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), expectedMove);
}

TEST("(Daycare) Pokémon don't learn move from their daycare partner if they lack empty move slot (Gen 9)")
{
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_CURSE));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_INGRAIN));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_NATURE_POWER));
    ASSUME(SpeciesHasEggMove(SPECIES_BULBASAUR, MOVE_PETAL_DANCE));

    u32 slot  = 0;
    PARAMETRIZE { slot = 0; }
    PARAMETRIZE { slot = 1; }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SetConfig(CONFIG_EGG_MOVE_TRANSFER, GEN_9);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_TACKLE, move2=MOVE_GROWL, move3=MOVE_VINE_WHIP, move4=MOVE_GROWTH, item=ITEM_MIRROR_HERB;
        givemon SPECIES_BULBASAUR, 100, move1=MOVE_CURSE, move2=MOVE_INGRAIN, move3=MOVE_NATURE_POWER, move4=MOVE_PETAL_DANCE;
    );
    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = slot;
    TakePokemonFromDaycare();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1), MOVE_TACKLE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE2), MOVE_GROWL);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE3), MOVE_VINE_WHIP);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE4), MOVE_GROWTH);
}

TEST("GetChildNature always returns a random nature (gen 2)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_2);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, nature=NATURE_LONELY, item=ITEM_EVERSTONE;
        givemon SPECIES_DITTO, 100, nature=NATURE_LONELY, item=ITEM_EVERSTONE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_RANDOM);
}

TEST("GetChildNature returns the mom or ditto nature if it's holding an everstone")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_3);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    u32 nature = 0;
    for (u32 j = 0; j < NUM_NATURES; j++)
    {
        PARAMETRIZE { species = SPECIES_DITTO; gender = MON_GENDERLESS; nature = j; }
        PARAMETRIZE { species = SPECIES_BULBASAUR; gender = MON_FEMALE; nature = j; }
    }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = species;
    gSpecialVar_0x8001 = gender;
    gSpecialVar_0x8002 = nature;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, nature=NATURE_HARDY;
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=VAR_0x8002, item=ITEM_EVERSTONE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), nature);
}

TEST("GetChildNature doesn't pass a parent's nature if the RNG check fails (gen 3-4)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, FALSE);

    u32 gen = 0;
    u32 nature = 0;
    for (u32 j = 0; j < NUM_NATURES; j++)
    {
        PARAMETRIZE { gen = GEN_3; nature = j; }
        PARAMETRIZE { gen = GEN_4; nature = j; }
    }
    SetConfig(CONFIG_NATURE_INHERITANCE, gen);
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8002 = nature;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, nature=NATURE_HARDY;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, nature=VAR_0x8002, item=ITEM_EVERSTONE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_RANDOM);
}

TEST("GetChildNature returns the ditto nature if both ditto and a female are holding an everstone (gen 3)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_3);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    u32 slot  = 0;
    PARAMETRIZE { slot = 0; }
    PARAMETRIZE { slot = 1; }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, nature=NATURE_HARDY, item=ITEM_EVERSTONE;
        givemon SPECIES_DITTO, 100, nature=NATURE_LONELY, item=ITEM_EVERSTONE;
    );
    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_LONELY);
}

TEST("GetChildNature doesn't let a female pokemon pass its nature if a ditto is there (gen 3)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_3);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    u32 slot  = 0;
    PARAMETRIZE { slot = 0; }
    PARAMETRIZE { slot = 1; }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, nature=NATURE_HARDY, item=ITEM_EVERSTONE;
        givemon SPECIES_DITTO, 100, nature=NATURE_LONELY;
    );
    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_RANDOM);
}

TEST("GetChildNature returns a random nature when no parent is holding an everstone")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_3);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    PARAMETRIZE { species = SPECIES_DITTO; gender = MON_GENDERLESS; }
    PARAMETRIZE { species = SPECIES_BULBASAUR; gender = MON_FEMALE; }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = species;
    gSpecialVar_0x8001 = gender;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, nature=NATURE_LONELY;
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=NATURE_LONELY;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_RANDOM);
}

TEST("GetChildNature returns a random nature when the father is the one holding the Everstone (gen 3)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_3);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    PARAMETRIZE { species = SPECIES_DITTO; gender = MON_GENDERLESS; }
    PARAMETRIZE { species = SPECIES_BULBASAUR; gender = MON_FEMALE; }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = species;
    gSpecialVar_0x8001 = gender;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, nature=NATURE_LONELY, item=ITEM_EVERSTONE;
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=NATURE_HARDY;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_RANDOM);
}

TEST("GetChildNature returns the father's nature if it is holding an Everstone (gen 4+)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_4);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    u32 nature = 0;
    for (u32 j = 0; j < NUM_NATURES; j++)
    {
        PARAMETRIZE { species = SPECIES_DITTO; gender = MON_GENDERLESS; nature = j; }
        PARAMETRIZE { species = SPECIES_BULBASAUR; gender = MON_FEMALE; nature = j; }
    }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = species;
    gSpecialVar_0x8001 = gender;
    gSpecialVar_0x8002 = nature;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, nature=VAR_0x8002, item=ITEM_EVERSTONE;
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=NATURE_HARDY;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), nature);
}

TEST("GetChildNature returns nature of the first pokemon holding an everstone passing its everstone check (gen 4)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_4);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, TRUE);

    const u32 options[3][2] = {
        {SPECIES_DITTO, MON_GENDERLESS},
        {SPECIES_BULBASAUR, MON_FEMALE},
        {SPECIES_BULBASAUR, MON_MALE}
    };
    enum Species species0 = SPECIES_NONE;
    u32 gender0 = 0;
    enum Species species1 = SPECIES_NONE;
    u32 gender1 = 0;
    u32 randomParent = 0;
    for (u32 j = 0; j < 3; j++)
    {
        for (u32 k = 0; k < 3; k++)
        {
            if (k == j)
                continue;
            PARAMETRIZE { species0 = options[j][0]; gender0 = options[j][1]; species1 = options[k][0]; gender1 = options[k][1]; randomParent = 1; }
            PARAMETRIZE { species0 = options[j][0]; gender0 = options[j][1]; species1 = options[k][0]; gender1 = options[k][1]; randomParent = 0; }
        }
    }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SET_RNG(RNG_DAYCARE_PICK_NATURE_PARENT, randomParent);
    gSpecialVar_0x8000 = species0;
    gSpecialVar_0x8001 = gender0;
    gSpecialVar_0x8002 = species1;
    gSpecialVar_0x8003 = gender1;
    RUN_OVERWORLD_SCRIPT(
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=NATURE_LONELY, item=ITEM_EVERSTONE;
        givemon VAR_0x8002, 100, gender=VAR_0x8003, nature=NATURE_HARDY, item=ITEM_EVERSTONE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_LONELY);
}

TEST("GetChildNature returns nature of any pokemon holding an everstone without an RNG check (gen 5+)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_5);
    SET_RNG(RNG_DAYCARE_NATURE_INHERITANCE, FALSE);

    const u32 options[3][2] = {
        {SPECIES_DITTO, MON_GENDERLESS},
        {SPECIES_BULBASAUR, MON_FEMALE},
        {SPECIES_BULBASAUR, MON_MALE}
    };
    enum Species species0 = SPECIES_NONE;
    u32 gender0 = 0;
    enum Species species1 = SPECIES_NONE;
    u32 gender1 = 0;
    u32 nature = 0;
    for (u32 j = 0; j < 3; j++)
    {
        for (u32 k = 0; k < 3; k++)
        {
            if (k == j)
                continue;
            for (u32 l = 0; l < NUM_NATURES; l++)
            {
                PARAMETRIZE { species0 = options[j][0]; gender0 = options[j][1]; species1 = options[k][0]; gender1 = options[k][1]; nature = l; }
            }
        }
    }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = species0;
    gSpecialVar_0x8001 = gender0;
    gSpecialVar_0x8002 = species1;
    gSpecialVar_0x8003 = gender1;
    gSpecialVar_0x8004 = nature;
    RUN_OVERWORLD_SCRIPT(
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=VAR_0x8004, item=ITEM_EVERSTONE;
        givemon VAR_0x8002, 100, gender=VAR_0x8003, nature=NATURE_LONELY;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), nature);
}

TEST("GetChildNature returns the nature of a random parent if they are both holding an everstone (gen 5+)")
{
    ASSUME(GetItemHoldEffect(ITEM_EVERSTONE) == HOLD_EFFECT_PREVENT_EVOLVE);
    SetConfig(CONFIG_NATURE_INHERITANCE, GEN_5);

    const u32 options[3][2] = {
        {SPECIES_DITTO, MON_GENDERLESS},
        {SPECIES_BULBASAUR, MON_FEMALE},
        {SPECIES_BULBASAUR, MON_MALE}
    };
    enum Species species0 = SPECIES_NONE;
    u32 gender0 = 0;
    enum Species species1 = SPECIES_NONE;
    u32 gender1 = 0;
    u32 randomParent = 0;
    for (u32 j = 0; j < 3; j++)
    {
        for (u32 k = 0; k < 3; k++)
        {
            if (k == j)
                continue;
            PARAMETRIZE { species0 = options[j][0]; gender0 = options[j][1]; species1 = options[k][0]; gender1 = options[k][1]; randomParent = 1; }
            PARAMETRIZE { species0 = options[j][0]; gender0 = options[j][1]; species1 = options[k][0]; gender1 = options[k][1]; randomParent = 0; }
        }
    }
    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    SET_RNG(RNG_DAYCARE_PICK_NATURE_PARENT, randomParent);
    gSpecialVar_0x8000 = species0;
    gSpecialVar_0x8001 = gender0;
    gSpecialVar_0x8002 = species1;
    gSpecialVar_0x8003 = gender1;
    RUN_OVERWORLD_SCRIPT(
        givemon VAR_0x8000, 100, gender=VAR_0x8001, nature=NATURE_LONELY, item=ITEM_EVERSTONE;
        givemon VAR_0x8002, 100, gender=VAR_0x8003, nature=NATURE_HARDY, item=ITEM_EVERSTONE;
    );
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    if (randomParent)
        EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_HARDY);
    else
        EXPECT_EQ(GetChildNature(&gSaveBlock1Ptr->daycare), NATURE_LONELY);
}

TEST("InheritIVs will pass 3 random stats from the parents to the egg")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_BULBASAUR, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);

    u32 rngIv = 0;
    u32 j;
    for (j = 0; j < 720; j++)
    {
        PARAMETRIZE { rngIv = j; }
    }
    SET_RNG(RNG_DAYCARE_INHERITED_STATS, rngIv);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31;
    );

    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    InheritIVs(&egg, &gSaveBlock1Ptr->daycare);
    u32 passedIvCount = 0;
    for (j = 0; j < NUM_STATS; j++)
    {
        if (GetMonData(&egg, MON_DATA_HP_IV + j) == 31)
            passedIvCount++;
    }

    EXPECT_EQ(passedIvCount, 3);
}

TEST("InheritIVs will pass 5 random stats from the parents to the egg if one parent is holding a destiny knot")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_BULBASAUR, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);

    u32 j;
    u32 rngIv = 0;
    u32 slot = 0;
    for (j = 0; j < 720; j++)
    {
        PARAMETRIZE { rngIv = j; slot = 1; }
        PARAMETRIZE { rngIv = j; slot = 0; }
    }
    SET_RNG(RNG_DAYCARE_INHERITED_STATS, rngIv);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, item=ITEM_DESTINY_KNOT;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();

    InheritIVs(&egg, &gSaveBlock1Ptr->daycare);
    u32 passedIvCount = 0;
    for (j = 0; j < NUM_STATS; j++)
    {
        if (GetMonData(&egg, MON_DATA_HP_IV + j) == 31)
            passedIvCount++;
    }

    EXPECT_EQ(passedIvCount, 5);
}

TEST("InheritIVs does not pass more stats when a power item is equipped")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_BULBASAUR, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);

    u32 j;
    u32 rngIv = 0;
    enum Item item0 = ITEM_NONE;
    enum Item item1 = ITEM_NONE;
    for (j = 0; j < 720; j++)
    {
        for (enum Item k = ITEM_POWER_WEIGHT; k <= ITEM_POWER_ANKLET; k++)
        {
            PARAMETRIZE { rngIv = j; item0 = k; item1 = ITEM_NONE; }
            PARAMETRIZE { rngIv = j; item0 = k; item1 = ITEM_DESTINY_KNOT; }
            PARAMETRIZE { rngIv = j; item0 = k; item1 = ITEM_POWER_WEIGHT; }
        }
    }
    SET_RNG(RNG_DAYCARE_INHERITED_STATS, rngIv);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    gSpecialVar_0x8000 = item0;
    gSpecialVar_0x8001 = item1;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, item=VAR_0x8000;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, item=VAR_0x8001;
    );

    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    InheritIVs(&egg, &gSaveBlock1Ptr->daycare);
    u32 passedIvCount = 0;
    for (j = 0; j < NUM_STATS; j++)
    {
        if (GetMonData(&egg, MON_DATA_HP_IV + j) == 31)
            passedIvCount++;
    }

    if (item1 == ITEM_DESTINY_KNOT)
        EXPECT_EQ(passedIvCount, 5);
    else
        EXPECT_EQ(passedIvCount, 3);
}

TEST("InheritIVs will always pass the preferred stat from the parent holding the parent item")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_BULBASAUR, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);
    SET_RNG(RNG_DAYCARE_PICK_IVS_PARENT, 31);

    u32 j;
    u32 rngIv = 0;
    enum Item item0 = ITEM_NONE;
    enum Stat powerStat = 0;
    for (j = 0; j < 720; j++)
    {
        for (enum Item k = ITEM_POWER_WEIGHT; k <= ITEM_POWER_ANKLET; k++)
        {
            PARAMETRIZE { rngIv = j; item0 = k; powerStat = GetItemSecondaryId(k); }
        }
    }

    SET_RNG(RNG_DAYCARE_INHERITED_STATS, rngIv);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    gSpecialVar_0x8000 = item0;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, hpIv=0, atkIv=0, defIv=0, speedIv=0, spAtkIv=0, spDefIv=0, item=VAR_0x8000;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, hpIv=1, atkIv=1, defIv=1, speedIv=1, spAtkIv=1, spDefIv=1;
    );

    u32 value = 31;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP_IV + powerStat, &value);
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    InheritIVs(&egg, &gSaveBlock1Ptr->daycare);
    u32 passedValues = 0;
    for (j = 0; j < NUM_STATS; j++)
    {
        value = GetMonData(&egg, MON_DATA_HP_IV + j);
        if (j == powerStat)
            EXPECT_EQ(value, 31);
        else if (value == 1)
            passedValues++;
        else
            EXPECT_EQ(value, 0);
    }
    EXPECT_EQ(passedValues, 2);
}

TEST("InheritIVs pick one parent at random to pass its power stat if two power items are equipped")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_BULBASAUR, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);

    enum Item item0 = ITEM_NONE;
    enum Item item1 = ITEM_NONE;
    u32 parent = 0;
    for (enum Item j = ITEM_POWER_WEIGHT; j <= ITEM_POWER_ANKLET; j++)
    {
        for (enum Item k = ITEM_POWER_WEIGHT; k <= ITEM_POWER_ANKLET; k++)
        {
            PARAMETRIZE { item0 = j; item1 = k; parent = 0; }
            PARAMETRIZE { item0 = j; item1 = k; parent = 1; }
        }
    }
    SET_RNG(RNG_DAYCARE_PICK_IVS_PARENT, parent);
    enum Stat powerStat0 = GetItemSecondaryId(item0);
    enum Stat powerStat1 = GetItemSecondaryId(item1);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    gSpecialVar_0x8000 = item0;
    gSpecialVar_0x8001 = item1;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, hpIv=0, atkIv=0, defIv=0, speedIv=0, spAtkIv=0, spDefIv=0, item=VAR_0x8000;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, hpIv=0, atkIv=0, defIv=0, speedIv=0, spAtkIv=0, spDefIv=0, item=VAR_0x8001;
    );

    u32 value = 31;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP_IV + powerStat0, &value);
    value = 30;
    SetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_HP_IV + powerStat1, &value);
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    InheritIVs(&egg, &gSaveBlock1Ptr->daycare);
    if (parent == 0)
        EXPECT_EQ(GetMonData(&egg, MON_DATA_HP_IV + powerStat0), 31);
    else
        EXPECT_EQ(GetMonData(&egg, MON_DATA_HP_IV + powerStat1), 30);
}

TEST("InheritPokeball doesn't do anything, all eggs are born in Pokeball (gen5-)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_5);

    enum PokeBall ball = 0;
    for (enum PokeBall j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        PARAMETRIZE { ball = j; }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, ball=VAR_0x8000;
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, ball=VAR_0x8000;
    );
    STORE_IN_DAYCARE_AND_GET_EGG();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
}

TEST("InheritPokeball make eggs inherit their mother ball unless it's a 'forbidden' ball (gen6)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_6);

    enum PokeBall ball0 = 0;
    enum PokeBall ball1 = 0;
    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    u32 slot = 0;
    for (enum PokeBall j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        for (enum PokeBall k = BALL_STRANGE; j < POKEBALL_COUNT; j++)
        {
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_BULBASAUR; gender = MON_MALE; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_DITTO; gender = MON_GENDERLESS; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_BULBASAUR; gender = MON_MALE; slot = 1; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_DITTO; gender = MON_GENDERLESS; slot = 1; }
        }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball0;
    gSpecialVar_0x8001 = ball1;
    gSpecialVar_0x8002 = species;
    gSpecialVar_0x8003 = gender;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, ball=VAR_0x8000;
        givemon VAR_0x8002, 100, gender=VAR_0x8003, ball=VAR_0x8001;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    if (ball0 == BALL_STRANGE || ball0 == BALL_MASTER || ball0 == BALL_CHERISH)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), ball0);
}

TEST("InheritPokeball give eggs born from a male and a ditto a pokeball (gen6)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_6);

    enum PokeBall ball0 = 0;
    u32 slot = 0;
    for (enum PokeBall j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        PARAMETRIZE { ball0 = j; slot = 0; }
        PARAMETRIZE { ball0 = j; slot = 1; }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball0;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, ball=VAR_0x8000;
        givemon SPECIES_DITTO, 100, gender=MON_GENDERLESS, ball=VAR_0x8000;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
}

TEST("InheritPokeball give eggs born from a male and a ditto a pokeball (gen6)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_6);

    enum PokeBall ball0 = 0;
    u32 slot = 0;
    for (enum PokeBall j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        PARAMETRIZE { ball0 = j; slot = 0; }
        PARAMETRIZE { ball0 = j; slot = 1; }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball0;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_MALE, ball=VAR_0x8000;
        givemon SPECIES_DITTO, 100, gender=MON_GENDERLESS, ball=VAR_0x8000;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
}

TEST("InheritPokeball give the non-ditto ball to pokemon born from a ditto and another parent (gen7+)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_7);

    enum PokeBall ball0 = 0;
    enum PokeBall ball1 = 0;
    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    u32 slot = 0;
    for (enum PokeBall j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        for (enum PokeBall k = BALL_STRANGE; k < POKEBALL_COUNT; k++)
        {
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_BULBASAUR; gender = MON_MALE; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_MAGNEMITE; gender = MON_GENDERLESS; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_BULBASAUR; gender = MON_FEMALE; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_BULBASAUR; gender = MON_MALE; slot = 1; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_MAGNEMITE; gender = MON_GENDERLESS; slot = 1; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_BULBASAUR; gender = MON_FEMALE; slot = 1; }
        }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball0;
    gSpecialVar_0x8001 = ball1;
    gSpecialVar_0x8002 = species;
    gSpecialVar_0x8003 = gender;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_DITTO, 100, ball=VAR_0x8000;
        givemon VAR_0x8002, 100, gender=VAR_0x8003, ball=VAR_0x8001;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    if (ball1 == BALL_STRANGE || ball1 == BALL_MASTER || ball1 == BALL_CHERISH)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), ball1);
}

TEST("InheritPokeball give the mother ball to pokemon born two different non-ditto species (gen7+)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_7);

    enum PokeBall ball0 = 0;
    enum PokeBall ball1 = 0;
    enum Species species = SPECIES_NONE;
    u32 slot = 0;
    for (enum PokeBall j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        for (enum PokeBall k = BALL_STRANGE; j < POKEBALL_COUNT; j++)
        {
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_IVYSAUR; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_SLOWBRO; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_ODDISH; slot = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_IVYSAUR; slot = 1; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_SLOWBRO; slot = 1; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_ODDISH; slot = 1; }
        }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball0;
    gSpecialVar_0x8001 = ball1;
    gSpecialVar_0x8002 = species;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_BULBASAUR, 100, gender=MON_FEMALE, ball=VAR_0x8000;
        givemon VAR_0x8002, 100, gender=MON_MALE, ball=VAR_0x8001;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    if (ball0 == BALL_STRANGE || ball0 == BALL_MASTER || ball0 == BALL_CHERISH)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), ball0);
}

TEST("InheritPokeball give a parent ball at random to pokemon born from parents of the same species (gen7+)")
{
    SetConfig(CONFIG_BALL_INHERITANCE, GEN_7);

    enum PokeBall ball0 = 0;
    enum PokeBall ball1 = 0;
    enum Species species = SPECIES_NONE;
    u32 randomParent = 0;
    for (u32 j = BALL_STRANGE; j < POKEBALL_COUNT; j++)
    {
        for (u32 k = BALL_STRANGE; j < POKEBALL_COUNT; j++)
        {
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_VULPIX; randomParent = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_VULPIX_ALOLA; randomParent = 0; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_VULPIX; randomParent = 1; }
            PARAMETRIZE { ball0 = j; ball1 = k; species = SPECIES_VULPIX_ALOLA; randomParent = 1; }
        }
    }
    SET_RNG(RNG_DAYCARE_PICK_BALL_PARENT, randomParent);

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));

    gSpecialVar_0x8000 = ball0;
    gSpecialVar_0x8001 = ball1;
    gSpecialVar_0x8002 = species;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_VULPIX, 100, gender=MON_FEMALE, ball=VAR_0x8000;
        givemon VAR_0x8002, 100, gender=MON_MALE, ball=VAR_0x8001;
    );

    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    u32 expectedBall;
    if (randomParent)
        expectedBall = ball1;
    else
        expectedBall = ball0;
    if (expectedBall == BALL_STRANGE || expectedBall == BALL_MASTER || expectedBall == BALL_CHERISH)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), BALL_POKE);
    else
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKEBALL), expectedBall);
}

TEST("InheritAbility doesn't do anything, ability is chosen randomly (gen4-)")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_ABRA, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);
    u32 value = 3;
    SetMonData(&egg, MON_DATA_ABILITY_NUM, &value);

    SetConfig(CONFIG_ABILITY_INHERITANCE, GEN_4);
    SET_RNG(RNG_DAYCARE_ABILITY_INHERITANCE, TRUE);
    u32 abilityNum0 = 0;
    u32 abilityNum1 = 0;
    for (u32 j = 0; j < 3; j++)
    {
        for (u32 k = 0; k < 3; k++)
        {
            PARAMETRIZE { abilityNum0 = j; abilityNum1 = k; }
        }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    gSpecialVar_0x8000 = abilityNum0;
    gSpecialVar_0x8001 = abilityNum1;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_ABRA, 100, gender=MON_MALE, abilityNum=VAR_0x8000;
        givemon SPECIES_ABRA, 100, gender=MON_FEMALE, abilityNum=VAR_0x8001;
    );

    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    InheritAbility(&egg, &gSaveBlock1Ptr->daycare);
    EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 3);
}

TEST("InheritAbility copy the ability of the mother if the dad is not a ditto (gen5)")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_ABRA, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);
    u32 value = 3;
    SetMonData(&egg, MON_DATA_ABILITY_NUM, &value);

    SetConfig(CONFIG_ABILITY_INHERITANCE, GEN_5);
    SET_RNG(RNG_DAYCARE_ABILITY_INHERITANCE, TRUE);
    u32 abilityNum0 = 0;
    u32 abilityNum1 = 0;
    enum Species species = SPECIES_NONE;
    u32 gender = 0;
    u32 slot = 0;
    for (u32 j = 0; j < 3; j++)
    {
        u32 k;
        if (j == 0)
            k = 1;
        else
            k = 0;
        PARAMETRIZE { abilityNum0 = j; abilityNum1 = k; species = SPECIES_ABRA; gender = MON_MALE; slot = 0; }
        PARAMETRIZE { abilityNum0 = j; abilityNum1 = k; species = SPECIES_DITTO; gender = MON_GENDERLESS; slot = 0; }
        PARAMETRIZE { abilityNum0 = j; abilityNum1 = k; species = SPECIES_ABRA; gender = MON_MALE; slot = 1; }
        PARAMETRIZE { abilityNum0 = j; abilityNum1 = k; species = SPECIES_DITTO; gender = MON_GENDERLESS; slot = 1; }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    gSpecialVar_0x8000 = abilityNum0;
    gSpecialVar_0x8001 = abilityNum1;
    gSpecialVar_0x8002 = species;
    gSpecialVar_0x8003 = gender;
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_ABRA, 100, gender=MON_FEMALE, abilityNum=VAR_0x8000;
        givemon VAR_0x8002, 100, gender=VAR_0x8003, abilityNum=VAR_0x8001;
    );

    gSpecialVar_0x8004 = slot;
    StoreSelectedPokemonInDaycare();
    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();

    InheritAbility(&egg, &gSaveBlock1Ptr->daycare);
    if (species == SPECIES_ABRA)
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), abilityNum0);
    else
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 3);
}

TEST("InheritAbility copy the ability of the mother or non-ditto parent (gen6+)")
{
    struct Pokemon egg;
    CreateMonWithIVs(&egg, SPECIES_ABRA, 1, Random32(), OTID_STRUCT_PLAYER_ID, 0);
    u32 value = 3;
    SetMonData(&egg, MON_DATA_ABILITY_NUM, &value);

    SetConfig(CONFIG_ABILITY_INHERITANCE, GEN_6);
    SET_RNG(RNG_DAYCARE_ABILITY_INHERITANCE, TRUE);
    const u32 options[3][2] = {
        {SPECIES_DITTO, MON_GENDERLESS},
        {SPECIES_ABRA, MON_FEMALE},
        {SPECIES_ABRA, MON_MALE}
    };
    enum Species species0 = SPECIES_NONE;
    u32 gender0 = 0;
    enum Species species1 = SPECIES_NONE;
    u32 gender1 = 0;
    for (u32 j = 0; j < 3; j++)
    {
        for (u32 k = 0; k < 3; k++)
        {
            if (k == j)
                continue;
            PARAMETRIZE { species0 = options[j][0]; gender0 = options[j][1]; species1 = options[k][0]; gender1 = options[k][1]; }
        }
    }

    ZeroPlayerPartyMons();
    memset(&gSaveBlock1Ptr->daycare, 0, sizeof(gSaveBlock1Ptr->daycare));
    gSpecialVar_0x8000 = 0;
    gSpecialVar_0x8001 = 1;
    gSpecialVar_0x8002 = species0;
    gSpecialVar_0x8003 = gender0;
    gSpecialVar_0x8004 = species1;
    gSpecialVar_0x8005 = gender1;
    RUN_OVERWORLD_SCRIPT(
        givemon VAR_0x8002, 100, gender=VAR_0x8003, abilityNum=VAR_0x8000;
        givemon VAR_0x8004, 100, gender=VAR_0x8005, abilityNum=VAR_0x8001;
    );

    gSpecialVar_0x8004 = 0;
    StoreSelectedPokemonInDaycare();
    StoreSelectedPokemonInDaycare();

    InheritAbility(&egg, &gSaveBlock1Ptr->daycare);
    if (gender0 == MON_FEMALE)
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 0);
    else if (gender1 == MON_FEMALE)
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 1);
    else if (species0 == SPECIES_ABRA)
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 0);
    else if (species1 == SPECIES_ABRA)
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 1);
    else
        EXPECT_EQ(GetMonData(&egg, MON_DATA_ABILITY_NUM), 3);
}
