#include "global.h"
#include "battle_pyramid_bag.h"
#include "event_data.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "save.h"
#include "fieldmap.h"
#include "palette.h"
#include "field_message_box.h"
#include "random.h"
#include "item.h"
#include "util.h"
#include "sound.h"
#include "task.h"
#include "start_menu.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"

extern void door_upload_tiles(void);

#define PICKUP_ITEMS_SET_COUNT 20

struct Struct_08613650
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6[10];
};

extern const u16 gBattleFrontierHeldItems[];
extern const struct FacilityMon gBattleFrontierMons[];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];

// This file's functions.
void sub_81AAA7C(u8 lvlMode);
u8 sub_81AA9E4(void);
u16 sub_81A9AA8(u8);
u8 sub_81A9998(s32 *, u8, u8);
u8 sub_81AAA40(void);
bool8 InBattlePyramid(void);
void sub_81A97DC(u8 taskId);

// Const rom data.
extern void (* const gUnknown_08613EE0[])(void);
extern const struct Struct_08613650 gUnknown_08613650[];
extern const u16 sPickupItemsLvl50[PICKUP_ITEMS_SET_COUNT][10];
extern const u16 sPickupItemsLvlOpen[PICKUP_ITEMS_SET_COUNT][10];
extern const u8 gUnknown_08613ABC[63][2];
extern const u8 gUnknown_08613B3A[];
extern const u16 gUnknown_08613F34[9];
extern const u16 gUnknown_08613F28[6];

// code
void sub_81A8E7C(void)
{
    gUnknown_08613EE0[gSpecialVar_0x8004]();
}

void sub_81A8E9C(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
    else
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;

    if (!isCurrent)
    {
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = 0;
        sub_81AAA7C(lvlMode);
    }

    sub_81C4EEC();
    gTrainerBattleOpponent_A = 0;
    gBattleOutcome = 0;
}

void sub_81A8F38(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E18;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50];
        break;
    case 4:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN];
        break;
    case 5:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;
        break;
    case 6:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
        break;
    }
}

void sub_81A9048(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E18 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x2000;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x2000);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x1000;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x1000);
        }
        break;
    case 7:
        gSaveBlock2Ptr->frontier.field_E2A = gSpecialVar_0x8006;
        break;
    }
}

void sub_81A9134(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    save_serialize_map();
    TrySavingData(SAVE_LINK);
}

void sub_81A917C(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.field_E18 = gUnknown_08613F34[Random() % ARRAY_COUNT(gUnknown_08613F34)];
    else
        gSaveBlock2Ptr->frontier.field_E18 = gUnknown_08613F28[Random() % ARRAY_COUNT(gUnknown_08613F28)];
}

void sub_81A91FC(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E18, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E18, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E18 = 0;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void sub_81A9254(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gSaveBlock2Ptr->frontier.field_E22[i] = Random();

    gSaveBlock2Ptr->frontier.field_E2A = 0;
}

void sub_81A9290(void)
{
    s32 i;
    s32 r7;
    s32 rand;
    u8 id;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 floor = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
    u32 setId = (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7) % PICKUP_ITEMS_SET_COUNT;

    if (setId >= PICKUP_ITEMS_SET_COUNT)
        setId = PICKUP_ITEMS_SET_COUNT - 1;

    id = sub_81AA9E4();
    r7 = (gSpecialVar_LastTalked - gUnknown_08613650[id].unk1) - 1;
    rand = gSaveBlock2Ptr->frontier.field_E22[r7 / 2];
    SeedRng2(rand);

    for (i = 0; i < r7 + 1; i++)
        rand = Random2() % 100;

    for (i = gUnknown_08613B3A[floor]; i < ARRAY_COUNT(gUnknown_08613ABC); i++)
    {
        if (rand < gUnknown_08613ABC[i][0])
            break;
    }

    if (lvlMode != FRONTIER_LVL_50)
        gSpecialVar_0x8000 = sPickupItemsLvlOpen[setId][gUnknown_08613ABC[i][1]];
    else
        gSpecialVar_0x8000 = sPickupItemsLvl50[setId][gUnknown_08613ABC[i][1]];

    gSpecialVar_0x8001 = 1;
}

void sub_81A93C8(void)
{
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    s32 i = 0;

    for (;;)
    {
        if (events[i].localId == gSpecialVar_LastTalked)
        {
            events[i].x = 0x7FFF;
            events[i].y = 0x7FFF;
            break;
        }
        i++;
        if (events[i].localId == 0)
            break;
    }
}

void sub_81A9414(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

extern const u8 gUnknown_08613C1C[50][2];
extern const u8 gUnknown_08613ED8[];
extern const u8 *const *const *const gUnknown_08613EC0[];

void sub_81A9424(void)
{
    s32 i;
    s32 var_24;
    u8 id;
    s32 class = 0;
    s32 r7 = 0;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    u16 trainerId = sub_81A9AA8(gEventObjects[gSelectedEventObject].localId);

    for (i = 0; i < ARRAY_COUNT(gUnknown_08613C1C); i++)
    {
        if (gUnknown_08613C1C[i][0] == gFacilityTrainers[trainerId].facilityClass)
        {
            class = gUnknown_08613C1C[i][1];
            break;
        }
    }

    var_24 = gUnknown_08613ED8[gEventObjects[gSelectedEventObject].localId - 1];
    i = 0;
    while (!i)
    {
        switch (var_24)
        {
        case 0:
            r7 = sub_81A9998(&var_24, 8, 0);
            i = 1;
            break;
        case 1:
            for (i = 0; i < sub_81AAA40(); i++)
            {
                if (events[i].graphicsId == EVENT_OBJ_GFX_ITEM_BALL && events[i].x != 0x7FFF && events[i].y != 0x7FFF)
                    r7++;
            }
            i = 1;
            break;
        case 2:
            id = sub_81AA9E4();
            r7 = gUnknown_08613650[id].unk1;
            for (i = 0; i < 8; i++)
            {
                if (gBitTable[i] & gSaveBlock2Ptr->frontier.field_E2A)
                    r7--;
            }
            i = 1;
            break;
        case 3:
            sub_81A9998(&var_24, 8, 2);
            break;
        case 4:
            sub_81A9998(&var_24, 8, 1);
            break;
        case 5:
            sub_81A9998(&var_24, 16, 2);
            break;
        case 6:
            sub_81A9998(&var_24, 16, 1);
            break;
        case 7:
            sub_81A9998(&var_24, 24, 2);
            break;
        case 8:
            sub_81A9998(&var_24, 24, 1);
            break;
        }
    }
    ShowFieldMessage(gUnknown_08613EC0[class][var_24][r7]);
}

void sub_81A9618(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] < 999)
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode]++;
    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
        gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
}

void sub_81A966C(void)
{
    gSpecialVar_Result = InBattlePyramid();
}

void sub_81A9684(void)
{
    switch (gSpecialVar_0x8006)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E68 = gSpecialVar_0x8005;
        break;
    case 1:
        switch (gSpecialVar_Result)
        {
        case 0:
            if (!gPaletteFade.active)
            {
                if (gSaveBlock2Ptr->frontier.field_E68 >= 120)
                    gSaveBlock2Ptr->frontier.field_E68 = 120;
                else
                    PlaySE(gSpecialVar_0x8007);
                gSpecialVar_Result++;
            }
            break;
        case 1:
            if (gSpecialVar_0x8005 != 0)
            {
                gSpecialVar_0x8005--;
                gSaveBlock2Ptr->frontier.field_E68++;
                if (gSaveBlock2Ptr->frontier.field_E68 > 120)
                {
                    gSaveBlock2Ptr->frontier.field_E68 = 120;
                    gSpecialVar_Result++;
                }
                door_upload_tiles();
            }
            else
            {
                gSpecialVar_Result = 2;
            }
            break;
        case 2:
        default:
            break;
        }
        break;
    }
}

void sub_81A975C(void)
{
    s32 i, j;
    u16 item = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.selectedPartyMons[j] != 0 && gSaveBlock2Ptr->frontier.selectedPartyMons[j] - 1 == i)
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

void sub_81A97C8(void)
{
    CreateTask(sub_81A97DC, 0);
}

extern const u16 gUnknown_08D856C8[][16];

void sub_81A97DC(u8 taskId)
{
    if (gPaletteFade.active)
    {
        CpuCopy16(gUnknown_08D856C8[gSaveBlock2Ptr->frontier.curChallengeBattleNum], &gPlttBufferUnfaded[96], 32);
        DestroyTask(taskId);
    }
}

void sub_81A9828(void)
{
    sub_809FDD4();
}
