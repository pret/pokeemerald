#include "global.h"
#include "string_util.h"
#include "test/test.h"
#include "constants/form_change_types.h"

TEST("Form species ID tables are shared between all forms")
{
    u32 i;
    u32 species = SPECIES_NONE;
    const u16 *formSpeciesIdTable;

    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formSpeciesIdTable)
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }

    formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    for (i = 0; formSpeciesIdTable[i] != FORM_SPECIES_END; i++)
    {
        u32 formSpeciesId = formSpeciesIdTable[i];
        EXPECT_EQ(gSpeciesInfo[formSpeciesId].formSpeciesIdTable, formSpeciesIdTable);
    }
}

TEST("Form change tables contain only forms in the form species ID table")
{
    u32 i, j;
    u32 species = SPECIES_NONE;
    const struct FormChange *formChangeTable;
    const u16 *formSpeciesIdTable;

    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formChangeTable)
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }

    formChangeTable = gSpeciesInfo[species].formChangeTable;
    formSpeciesIdTable = gSpeciesInfo[species].formSpeciesIdTable;
    EXPECT(formSpeciesIdTable);

    for (i = 0; formChangeTable[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChangeTable[i].targetSpecies == SPECIES_NONE)
            continue;
        for (j = 0; formSpeciesIdTable[j] != FORM_SPECIES_END; j++)
        {
            if (formChangeTable[i].targetSpecies == formSpeciesIdTable[j])
            {
                break;
            }
        }
        EXPECT(formSpeciesIdTable[j] != FORM_SPECIES_END);
    }
}

TEST("Form change targets have the appropriate species flags")
{
    u32 i;
    u32 species = SPECIES_NONE;
    const struct FormChange *formChangeTable;

    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (gSpeciesInfo[i].formChangeTable)
        {
            PARAMETRIZE_LABEL("%S", gSpeciesInfo[i].speciesName) { species = i; }
        }
    }

    formChangeTable = gSpeciesInfo[species].formChangeTable;
    for (i = 0; formChangeTable[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        const struct SpeciesInfo *targetSpeciesInfo = &gSpeciesInfo[formChangeTable[i].targetSpecies];
        switch (formChangeTable[i].method)
        {
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM:
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE:
            EXPECT(targetSpeciesInfo->isMegaEvolution);
            break;
        case FORM_CHANGE_BATTLE_PRIMAL_REVERSION:
            EXPECT(targetSpeciesInfo->isPrimalReversion);
            break;
        case FORM_CHANGE_BATTLE_ULTRA_BURST:
            EXPECT(targetSpeciesInfo->isUltraBurst);
            break;
        case FORM_CHANGE_BATTLE_GIGANTAMAX:
            EXPECT(targetSpeciesInfo->isGigantamax);
            break;
       }
    }
}

TEST("No species has two evolutions that use the evolution tracker")
{
    u32 i;
    u32 species = SPECIES_NONE;
    u32 evolutionTrackerEvolutions;
    bool32 hasGenderBasedRecoil;
    const struct Evolution *evolutions;

    for (i = 0; i < NUM_SPECIES; i++)
    {
        if (GetSpeciesEvolutions(i) != NULL) PARAMETRIZE { species = i; }
    }

    evolutionTrackerEvolutions = 0;
    hasGenderBasedRecoil = FALSE;
    evolutions = GetSpeciesEvolutions(species);

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (evolutions[i].method == EVO_USE_MOVE_TWENTY_TIMES
         || evolutions[i].method == EVO_DEFEAT_THREE_WITH_ITEM
        )
            evolutionTrackerEvolutions++;

        if (evolutions[i].method == EVO_RECOIL_DAMAGE_MALE
         || evolutions[i].method == EVO_RECOIL_DAMAGE_FEMALE)
        {
            // Special handling for these since they can be combined as the evolution tracker field is used for the same purpose
            if (!hasGenderBasedRecoil)
            {
                hasGenderBasedRecoil = TRUE;
                evolutionTrackerEvolutions++;
            }
        }
    }

    EXPECT(evolutionTrackerEvolutions < 2);
}

extern const u8 gFallbackPokedexText[];

TEST("Every species has a description")
{
    u32 i;
    u32 species = SPECIES_NONE;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
            PARAMETRIZE { species = i; }
    }

    EXPECT_NE(StringCompare(GetSpeciesPokedexDescription(species), gFallbackPokedexText), 0);
}
