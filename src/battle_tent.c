#include "global.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_frontier_2.h"
#include "random.h"
#include "item.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"

extern const struct BattleFrontierTrainer gSlateportBattleTentTrainers[];
extern const struct FacilityMon gSlateportBattleTentMons[];
extern const u16 gBattleFrontierHeldItems[];

// This file's functions.
void sub_81B99D4(void);
void sub_81B9A28(void);
void sub_81B9A44(void);
void sub_81B9A60(void);
void sub_81B9A90(void);
void sub_81B9ABC(void);
void sub_81B9B00(void);
void sub_81B9B28(void);
void sub_81B9BA0(void);
void sub_81B9BF4(void);
void sub_81B9C10(void);
void sub_81B9C2C(void);
void sub_81B9C70(void);
void sub_81B9C98(void);
void sub_81B9CF0(void);
void sub_81B9D28(void);
void sub_81B9D7C(void);
void sub_81B9D98(void);
void sub_81B9DB4(void);
void sub_81B9DF8(void);
void sub_81B9E20(void);
void sub_81B9E78(void);
void sub_81B9E88(void);
void sub_81BA040(void);
void sub_81B9EC0(void);

// const rom data
void (*const gUnknown_086160B4[])(void) =
{
    sub_81B99D4,
    sub_81B9A28,
    sub_81B9A44,
    sub_81B9A60,
    sub_81B9A90,
    sub_81B9ABC,
    sub_81B9B00,
    sub_81B9B28
};

static const u16 sVerdanturfTentRewards[] = {ITEM_NEST_BALL};

void (*const gUnknown_086160D8[])(void) =
{
    sub_81B9BA0,
    sub_81B9BF4,
    sub_81B9C10,
    sub_81B9C2C,
    sub_81B9C70,
    sub_81B9C98,
    sub_81B9CF0
};

static const u16 sFallarborTentRewards[] = {ITEM_HYPER_POTION};

void (*const gUnknown_086160F8[])(void) =
{
    sub_81B9D28,
    sub_81B9D7C,
    sub_81B9D98,
    sub_81B9DB4,
    sub_81B9DF8,
    sub_81B9E20,
    sub_81B9E78,
    sub_81B9E88,
    sub_81BA040,
    sub_81B9EC0
};

static const u16 sSlateportTentRewards[] = {ITEM_FULL_HEAL};

// code
void sub_81B99B4(void)
{
    gUnknown_086160B4[gSpecialVar_0x8004]();
}

void sub_81B99D4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9A28(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6A;
}

void sub_81B9A44(void)
{
    gSaveBlock2Ptr->frontier.field_E6A = gSpecialVar_0x8006;
}

void sub_81B9A60(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) / 64;
    sub_8162614(gTrainerBattleOpponent_A, 0);
}

void sub_81B9A90(void)
{
    if (gTrainerBattleOpponent_A < 300)
        ConvertBattleFrontierTrainerSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

void sub_81B9ABC(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

void sub_81B9B00(void)
{
    gSaveBlock2Ptr->frontier.field_E6A = sVerdanturfTentRewards[Random() % ARRAY_COUNT(sVerdanturfTentRewards)];
}

void sub_81B9B28(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E6A, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E6A, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E6A = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void sub_81B9B80(void)
{
    gUnknown_086160D8[gSpecialVar_0x8004]();
}

void sub_81B9BA0(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9BF4(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6C;
}

void sub_81B9C10(void)
{
    gSaveBlock2Ptr->frontier.field_E6C = gSpecialVar_0x8006;
}

void sub_81B9C2C(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

void sub_81B9C70(void)
{
    gSaveBlock2Ptr->frontier.field_E6C = sFallarborTentRewards[Random() % ARRAY_COUNT(sFallarborTentRewards)];
}

void sub_81B9C98(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E6C, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E6C, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E6C = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void sub_81B9CF0(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void sub_81B9D08(void)
{
    gUnknown_086160F8[gSpecialVar_0x8004]();
}

void sub_81B9D28(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9D7C(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6E;
}

void sub_81B9D98(void)
{
    gSaveBlock2Ptr->frontier.field_E6E = gSpecialVar_0x8006;
}

void sub_81B9DB4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

void sub_81B9DF8(void)
{
    gSaveBlock2Ptr->frontier.field_E6E = sSlateportTentRewards[Random() % ARRAY_COUNT(sSlateportTentRewards)];
}

void sub_81B9E20(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E6E, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E6E, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E6E = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void sub_81B9E78(void)
{
    ZeroPlayerPartyMons();
    sub_819A4F8();
}

void sub_81B9E88(void)
{
    sub_819DC00();
}

bool8 sub_81B9E94(void)
{
    return (gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
            && ((gMapHeader.mapLayoutId == 385) | (gMapHeader.mapLayoutId == 386)));
}

// This function was written very...oddly.
/*
void sub_81B9EC0(void)
{
    s32 i, j;
    u16 currMonId, currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    s32 var;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gSlateportBattleTentMons;

    currSpecies = 0;
    i = 0;
    while (i != PARTY_SIZE)
    {
        // Cannot have two pokemon of the same species.
        currMonId = Random() % 70;
        j = 0;
        var = 0 + i;
        while (j < var && monIds[j] != currMonId)
        {
            if (species[j] == gFacilityTrainerMons[currMonId].species)
            {
                if (currSpecies == 0)
                    currSpecies = gFacilityTrainerMons[currMonId].species;
                else
                    break;
            }
            j++;
        }
        if (j != var)
            continue;

        // Cannot have two same held items.
        for (j = 0; j < var; j++)
        {
            if (heldItems[j] == 0)
                continue;
            if (heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[currMonId].itemTableId])
            {
                if (gFacilityTrainerMons[currMonId].species == currSpecies)
                    currSpecies = 0;
                else
                    break;
            }
        }
        if (j != var)
            continue;

        gSaveBlock2Ptr->frontier.field_E70[var].monId = currMonId;
        species[var] = gFacilityTrainerMons[currMonId].species;
        heldItems[var] = gBattleFrontierHeldItems[gFacilityTrainerMons[currMonId].itemTableId];
        monIds[var] = currMonId;
        i++;
    }
}
*/
