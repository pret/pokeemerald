#include "global.h"
#include "battle_records.h"
#include "bg.h"
#include "window.h"
#include "link.h"
#include "battle.h"
#include "overworld.h"
#include "text.h"
#include "text_window.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "main.h"
#include "scanline_effect.h"
#include "international_string_util.h"
#include "sound.h"
#include "constants/songs.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "constants/game_stat.h"

extern void PrintOnTrainerHillRecordsWindow(void); // pokenav.s

// this file's functions
static void sub_813C5EC(u8 taskId);
static void sub_813C62C(u8 taskId);
static void sub_813C664(u8 taskId);
static void sub_813C6A8(u8 windowId);
static void sub_813C91C(void);

// EWRAM variables
EWRAM_DATA u8 gRecordsWindowId = 0;
EWRAM_DATA static u8 *sUnknown_0203AB78 = NULL;

// const rom data
const u32 gUnknown_085B3484[] = INCBIN_U32("graphics/unknown/unknown_5B3484.4bpp");
const u16 gUnknown_085B3544[] = INCBIN_U16("graphics/unknown/unknown_5B3484.gbapal");
const u32 gUnknown_085B3564[] = INCBIN_U32("graphics/unknown/unknown_5B3564.bin");

const struct BgTemplate gUnknown_085B3D64[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct WindowTemplate gUnknown_085B3D6C[] =
{
    {0x0, 0x2, 0x1, 0x1A, 0x12, 0xF, 0x14},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_085B3D7C = {0x0, 0x2, 0x1, 0x1A, 0x11, 0xF, 0x1};

const u8 gUnknown_085B3D84[] = _("-------");
const u8 gUnknown_085B3D8C[] = _("----");

// code
static void ClearLinkBattleRecord(struct LinkBattleRecord *record)
{
    CpuFill16(0, record, sizeof(struct LinkBattleRecord));
    record->name[0] = EOS;
    record->trainerId = 0;
    record->wins = 0;
    record->losses = 0;
    record->draws = 0;
}

static void ClearLinkBattleRecords(struct LinkBattleRecord *records)
{
    s32 i;
    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
    {
        ClearLinkBattleRecord(records + i);
    }
    SetGameStat(GAME_STAT_LINK_BATTLE_WINS, 0);
    SetGameStat(GAME_STAT_LINK_BATTLE_LOSSES, 0);
    SetGameStat(GAME_STAT_LINK_BATTLE_DRAWS, 0);
}

static s32 GetLinkBattleRecordTotalBattles(struct LinkBattleRecord *record)
{
    return record->wins + record->losses + record->draws;
}

static s32 FindLinkBattleRecord(struct LinkBattleRecord *records, const u8 *name, u16 trainerId)
{
    s32 i;

    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
    {
        if (!StringCompareN(records[i].name, name, OT_NAME_LENGTH) && records[i].trainerId == trainerId)
            return i;
    }

    return LINK_B_RECORDS_COUNT;
}

static void SortLinkBattleRecords(struct LinkBattleRecords *records)
{
    s32 i, j;

    for (i = LINK_B_RECORDS_COUNT - 1; i > 0; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            s32 totalBattlesI = GetLinkBattleRecordTotalBattles(&records->entries[i]);
            s32 totalBattlesJ = GetLinkBattleRecordTotalBattles(&records->entries[j]);

            if (totalBattlesI > totalBattlesJ)
            {
                struct LinkBattleRecord temp1;
                u8 temp2;

                temp1 = records->entries[i];
                records->entries[i] = records->entries[j];
                records->entries[j] = temp1;

                temp2 = records->languages[i];
                records->languages[i] = records->languages[j];
                records->languages[j] = temp2;
            }
        }
    }
}

static void UpdateLinkBattleRecord(struct LinkBattleRecord *record, s32 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_WON:
        record->wins++;
        if (record->wins > 9999)
            record->wins = 9999;
        break;
    case B_OUTCOME_LOST:
        record->losses++;
        if (record->losses > 9999)
            record->losses = 9999;
        break;
    case B_OUTCOME_DREW:
        record->draws++;
        if (record->draws > 9999)
            record->draws = 9999;
        break;
    }
}

static void UpdateLinkBattleGameStats(s32 battleOutcome)
{
    u8 stat;

    switch (battleOutcome)
    {
    case B_OUTCOME_WON:
        stat = GAME_STAT_LINK_BATTLE_WINS;
        break;
    case B_OUTCOME_LOST:
        stat = GAME_STAT_LINK_BATTLE_LOSSES;
        break;
    case B_OUTCOME_DREW:
        stat = GAME_STAT_LINK_BATTLE_DRAWS;
        break;
    default:
        return;
    }

    if (GetGameStat(stat) < 9999)
        IncrementGameStat(stat);
}

static void UpdateLinkBattleRecords(struct LinkBattleRecords *records, const u8 *name, u16 trainerId, s32 battleOutcome, u8 battlerId)
{
    s32 index;

    UpdateLinkBattleGameStats(battleOutcome);
    SortLinkBattleRecords(records);
    index = FindLinkBattleRecord(records->entries, name, trainerId);
    if (index == LINK_B_RECORDS_COUNT)
    {
        index = LINK_B_RECORDS_COUNT - 1;
        ClearLinkBattleRecord(&records->entries[index]);
        StringCopyN(records->entries[index].name, name, OT_NAME_LENGTH);
        records->entries[index].trainerId = trainerId;
        records->languages[index] = gLinkPlayers[battlerId].language;
    }
    UpdateLinkBattleRecord(&records->entries[index], battleOutcome);
    SortLinkBattleRecords(records);
}

void ClearPlayerLinkBattleRecords(void)
{
    ClearLinkBattleRecords(gSaveBlock1Ptr->linkBattleRecords.entries);
}

static void IncTrainerCardWins(s32 battlerId)
{
    u16 *wins = &gTrainerCards[battlerId].linkBattleWins;
    (*wins)++;
    if (*wins > 9999)
        *wins = 9999;
}

static void IncTrainerCardLosses(s32 battlerId)
{
    u16 *losses = &gTrainerCards[battlerId].linkBattleLosses;
    (*losses)++;
    if (*losses > 9999)
        *losses = 9999;
}

static void UpdateTrainerCardWinsLosses(s32 battlerId)
{
    switch (gBattleOutcome)
    {
    case B_OUTCOME_WON:
        IncTrainerCardWins(BATTLE_OPPOSITE(battlerId));
        IncTrainerCardLosses(battlerId);
        break;
    case B_OUTCOME_LOST:
        IncTrainerCardLosses(BATTLE_OPPOSITE(battlerId));
        IncTrainerCardWins(battlerId);
        break;
    }
}

void UpdatePlayerLinkBattleRecords(s32 battlerId)
{
    if (InUnionRoom() != TRUE)
    {
        UpdateTrainerCardWinsLosses(battlerId);
        UpdateLinkBattleRecords(
            &gSaveBlock1Ptr->linkBattleRecords,
            gTrainerCards[battlerId].playerName,
            gTrainerCards[battlerId].trainerId,
            gBattleOutcome,
            battlerId);
    }
}

static void PrintLinkBattleWinsLossesDraws(struct LinkBattleRecord *records)
{
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_LINK_BATTLE_WINS), STR_CONV_MODE_LEFT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_LINK_BATTLE_LOSSES), STR_CONV_MODE_LEFT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar3, GetGameStat(GAME_STAT_LINK_BATTLE_DRAWS), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TotalRecordWLD);

    x = GetStringCenterAlignXOffset(1, gStringVar4, 0xD0);
    PrintTextOnWindow(gRecordsWindowId, 1, gStringVar4, x, 0x11, 0, NULL);
}

static void PrintLinkBattleRecord(struct LinkBattleRecord *record, u8 y, s32 language)
{
    if (record->wins == 0 && record->losses == 0 && record->draws == 0)
    {
        // empty slot
        PrintTextOnWindow(gRecordsWindowId, 1, gUnknown_085B3D84,   8, (y * 8) + 1, 0, NULL);
        PrintTextOnWindow(gRecordsWindowId, 1, gUnknown_085B3D8C,  80, (y * 8) + 1, 0, NULL);
        PrintTextOnWindow(gRecordsWindowId, 1, gUnknown_085B3D8C, 128, (y * 8) + 1, 0, NULL);
        PrintTextOnWindow(gRecordsWindowId, 1, gUnknown_085B3D8C, 176, (y * 8) + 1, 0, NULL);
    }
    else
    {
        StringFillWithTerminator(gStringVar1, 8);
        StringCopyN(gStringVar1, record->name, 7);
        ConvertInternationalString(gStringVar1, language);

        PrintTextOnWindow(gRecordsWindowId, 1, gStringVar1, 8, (y * 8) + 1, 0, NULL);

        ConvertIntToDecimalStringN(gStringVar1, record->wins, STR_CONV_MODE_RIGHT_ALIGN, 4);
        PrintTextOnWindow(gRecordsWindowId, 1, gStringVar1,  80, (y * 8) + 1, 0, NULL);

        ConvertIntToDecimalStringN(gStringVar1, record->losses, STR_CONV_MODE_RIGHT_ALIGN, 4);
        PrintTextOnWindow(gRecordsWindowId, 1, gStringVar1, 128, (y * 8) + 1, 0, NULL);

        ConvertIntToDecimalStringN(gStringVar1, record->draws, STR_CONV_MODE_RIGHT_ALIGN, 4);
        PrintTextOnWindow(gRecordsWindowId, 1, gStringVar1, 176, (y * 8) + 1, 0, NULL);
    }
}

void ShowLinkBattleRecords(void)
{
    s32 i, x;

    gRecordsWindowId = AddWindow(&gUnknown_085B3D7C);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    StringExpandPlaceholders(gStringVar4, gText_PlayersBattleResults);

    x = GetStringCenterAlignXOffset(1, gStringVar4, 208);
    PrintTextOnWindow(gRecordsWindowId, 1, gStringVar4, x, 1, 0, NULL);
    PrintLinkBattleWinsLossesDraws(gSaveBlock1Ptr->linkBattleRecords.entries);

    StringExpandPlaceholders(gStringVar4, gText_WinLoseDraw);
    PrintTextOnWindow(gRecordsWindowId, 1, gStringVar4, 0, 41, 0, NULL);

    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
    {
        PrintLinkBattleRecord(&gSaveBlock1Ptr->linkBattleRecords.entries[i], 7 + (i * 2), gSaveBlock1Ptr->linkBattleRecords.languages[i]);
    }

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

void RemoveRecordsWindow(void)
{
    sub_819746C(gRecordsWindowId, FALSE);
    RemoveWindow(gRecordsWindowId);
}

static void sub_813C5BC(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = sub_813C5EC;
}

static void sub_813C5EC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        task->func = sub_813C62C;
    }
}

static void sub_813C62C(u8 taskId)
{
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    gTasks[taskId].func = sub_813C664;
}

static void sub_813C664(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
        Free(sUnknown_0203AB78);
        sub_813C6A8(0);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
    }
}

static void sub_813C6A8(u8 windowId)
{
    FillWindowPixelBuffer(windowId, 0);
    ClearWindowTilemap(windowId);
    CopyWindowToVram(windowId, 2);
    RemoveWindow(windowId);
}

static void sub_813C6D4(void)
{
    DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void sub_813C80C(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void ResetBgCoordinates(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static void sub_813C880(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_1D_MAP);
}

static void sub_813C890(u8 bgId)
{
    LoadBgTiles(bgId, gUnknown_085B3484, sizeof(gUnknown_085B3484), 0);
    CopyToBgTilemapBufferRect(bgId, gUnknown_085B3564, 0, 0, 0x20, 0x20);
    LoadPalette(gUnknown_085B3544, 0, 0x20);
}

static void sub_813C8D8(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_813C8EC(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void ShowTrainerHillRecords(void)
{
    SetVBlankCallback(NULL);
    SetMainCallback2(sub_813C91C);
}

static void sub_813C91C(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        sub_813C6D4();
        gMain.state++;
        break;
    case 1:
        sub_813C80C();
        gMain.state++;
        break;
    case 2:
        sUnknown_0203AB78 = AllocZeroed(0x800);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_085B3D64, ARRAY_COUNT(gUnknown_085B3D64));
        SetBgTilemapBuffer(3, sUnknown_0203AB78);
        ResetBgCoordinates();
        gMain.state++;
        break;
    case 3:
        sub_813C890(3);
        LoadPalette(stdpal_get(0), 0xF0, 0x20);
        gMain.state++;
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy() != TRUE)
        {
            ShowBg(0);
            ShowBg(3);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
        }
        break;
    case 5:
        InitWindows(gUnknown_085B3D6C);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        gMain.state++;
        break;
    case 7:
        sub_813C880();
        SetVBlankCallback(sub_813C8D8);
        PrintOnTrainerHillRecordsWindow();
        CreateTask(sub_813C5BC, 8);
        SetMainCallback2(sub_813C8EC);
        gMain.state = 0;
        break;
    }
}
