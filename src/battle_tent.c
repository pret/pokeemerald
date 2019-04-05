#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory_screen.h"
#include "frontier_util.h"
#include "string_util.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/species.h"

// This file's functions.
static void sub_81B99D4(void);
static void sub_81B9A28(void);
static void sub_81B9A44(void);
static void sub_81B9A60(void);
static void sub_81B9A90(void);
static void sub_81B9ABC(void);
static void sub_81B9B00(void);
static void sub_81B9B28(void);
static void sub_81B9BA0(void);
static void sub_81B9BF4(void);
static void sub_81B9C10(void);
static void sub_81B9C2C(void);
static void sub_81B9C70(void);
static void sub_81B9C98(void);
static void sub_81B9CF0(void);
static void sub_81B9D28(void);
static void sub_81B9D7C(void);
static void sub_81B9D98(void);
static void sub_81B9DB4(void);
static void sub_81B9DF8(void);
static void sub_81B9E20(void);
static void sub_81B9E78(void);
static void sub_81B9E88(void);
static void sub_81BA040(void);
static void sub_81B9EC0(void);

// IWRAM bss
static IWRAM_DATA u16 sRandMonSetId;

// const rom data
void static (*const gUnknown_086160B4[])(void) =
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

void static (*const gUnknown_086160D8[])(void) =
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

void static (*const gUnknown_086160F8[])(void) =
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

static void sub_81B99D4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void sub_81B9A28(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6A;
}

static void sub_81B9A44(void)
{
    gSaveBlock2Ptr->frontier.field_E6A = gSpecialVar_0x8006;
}

static void sub_81B9A60(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) / 64;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void sub_81B9A90(void)
{
    if (gTrainerBattleOpponent_A < 300)
        FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static void sub_81B9ABC(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

static void sub_81B9B00(void)
{
    gSaveBlock2Ptr->frontier.field_E6A = sVerdanturfTentRewards[Random() % ARRAY_COUNT(sVerdanturfTentRewards)];
}

static void sub_81B9B28(void)
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

static void sub_81B9BA0(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void sub_81B9BF4(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6C;
}

static void sub_81B9C10(void)
{
    gSaveBlock2Ptr->frontier.field_E6C = gSpecialVar_0x8006;
}

static void sub_81B9C2C(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

static void sub_81B9C70(void)
{
    gSaveBlock2Ptr->frontier.field_E6C = sFallarborTentRewards[Random() % ARRAY_COUNT(sFallarborTentRewards)];
}

static void sub_81B9C98(void)
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

static void sub_81B9CF0(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void sub_81B9D08(void)
{
    gUnknown_086160F8[gSpecialVar_0x8004]();
}

static void sub_81B9D28(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void sub_81B9D7C(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6E;
}

static void sub_81B9D98(void)
{
    gSaveBlock2Ptr->frontier.field_E6E = gSpecialVar_0x8006;
}

static void sub_81B9DB4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

static void sub_81B9DF8(void)
{
    gSaveBlock2Ptr->frontier.field_E6E = sSlateportTentRewards[Random() % ARRAY_COUNT(sSlateportTentRewards)];
}

static void sub_81B9E20(void)
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

static void sub_81B9E78(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void sub_81B9E88(void)
{
    DoBattleFactorySwapScreen();
}

bool8 InSlateportBattleTent(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
           && (gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_CORRIDOR || gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_BATTLE_ROOM);
}

static void sub_81B9EC0(void)
{
    s32 i, j;
    u8 firstMonId;
    u16 monSetId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    firstMonId = 0;
    gFacilityTrainers = gSlateportBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gSlateportBattleTentMons;
    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        // Cannot have two pokemon of the same species.
        monSetId = Random() % 70;
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            u16 monId = monIds[j];
            if (monIds[j] == monSetId)
                break;
            if (species[j] == gFacilityTrainerMons[monSetId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monSetId].species;
                else
                    break;
            }
        }
        if (j != i + firstMonId)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < i + firstMonId; j++)
        {
            if (heldItems[j] != 0 && heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
            {
                if (gFacilityTrainerMons[monSetId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != i + firstMonId)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monSetId;
        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId];
        monIds[i] = monSetId;
        i++;
    }
}

static void sub_81BA040(void)
{
    u16 trainerId;
    s32 i, j, k;
    register const u16 *monSets asm("r9"); // Fix me. Compiler insists on moving that variable into stack.
    u16 species[3];
    u16 heldItems[3];
    s32 setsCount = 0;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    gFacilityTrainerMons = gSlateportBattleTentMons;

    while (1)
    {
        do
        {
            trainerId = Random() % 30;
            for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
            {
                if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                    break;
            }
        } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

        gTrainerBattleOpponent_A = trainerId;
        while (gFacilityTrainers[gTrainerBattleOpponent_A].monSets[setsCount] != 0xFFFF)
            setsCount++;
        if (setsCount > 8)
            break;
        setsCount = 0;
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 2)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;

    monSets = gFacilityTrainers[gTrainerBattleOpponent_A].monSets;
    i = 0;
    while (i != 3)
    {
        sRandMonSetId = monSets[Random() % setsCount];
        for (j = 0; j < 6; j++)
        {
            if (gFacilityTrainerMons[sRandMonSetId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != 6)
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[sRandMonSetId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != 0 && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonSetId].itemTableId])
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[sRandMonSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonSetId].itemTableId];
        gUnknown_03006298[i] = sRandMonSetId;
        i++;
    }
}
