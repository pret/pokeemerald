#include "global.h"
#include "frontier_util.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "field_specials.h"
#include "battle.h"
#include "script_pokemon_util_80F87D8.h"
#include "main.h"
#include "window.h"
#include "menu.h"
#include "text.h"
#include "battle_records.h"
#include "international_string_util.h"
#include "string_util.h"
#include "new_game.h"
#include "link.h"
#include "tv.h"
#include "apprentice.h"
#include "pokedex.h"
#include "recorded_battle.h"
#include "data2.h"
#include "record_mixing.h"
#include "strings.h"
#include "malloc.h"
#include "constants/battle_frontier.h"
#include "constants/trainers.h"
#include "constants/species.h"
#include "constants/game_stat.h"
#include "constants/moves.h"

extern u8 gUnknown_0203CEF8[];

extern void (* const gUnknown_08611C18[])(void);
extern const u16 gUnknown_08611BFC[][2];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];
extern const struct WindowTemplate gUnknown_08611C74;
extern const struct WindowTemplate gUnknown_08611C7C;
extern const struct WindowTemplate gUnknown_08611C84;
extern const u8 gUnknown_086118B4[29][7][4];
extern const u16 gUnknown_08611C9A[];
extern const u8 *const gUnknown_08611D08[];
extern const u8 *const gUnknown_08611CB0[][2];
extern const u8 *const gUnknown_08611D00[];

extern void sub_81B8558(void);

// This file's functions.
u8 sub_81A3B30(u8 facility);
static void ShowTowerResultsWindow(u8);
static void ShowDomeResultsWindow(u8);
static void ShowPalaceResultsWindow(u8);
static void ShowPikeResultsWindow(void);
static void ShowFactoryResultsWindow(u8);
static void ShowArenaResultsWindow(void);
static void ShowPyramidResultsWindow(void);
static void ShowLinkContestResultsWindow(void);
u8 sub_81A3610(void);
void sub_81A51A8(u8);
void sub_81A5030(u8);

// const rom data
const u8 gUnknown_08611550[][4] =
{
    [FRONTIER_FACILITY_TOWER]   = {0x23, 0x46, 0x23, 0x01},
	[FRONTIER_FACILITY_DOME]    = {0x04, 0x09, 0x05, 0x00},
	[FRONTIER_FACILITY_PALACE]  = {0x15, 0x2a, 0x15, 0x01},
	[FRONTIER_FACILITY_ARENA]   = {0x1c, 0x38, 0x1c, 0x01},
	[FRONTIER_FACILITY_FACTORY] = {0x15, 0x2a, 0x15, 0x01},
	[FRONTIER_FACILITY_PIKE]    = {0x1c, 0x8c, 0x38, 0x01},
	[FRONTIER_FACILITY_PYRAMID] = {0x15, 0x46, 0x23, 0x00},
};

// code
void sub_81A1780(void)
{
    gUnknown_08611C18[gSpecialVar_0x8004]();
}

void sub_81A17A0(void)
{
    VarSet(VAR_TEMP_0, 0xFF);
    switch (gSaveBlock2Ptr->frontier.field_CA8)
    {
    case 0:
        break;
    case 1:
        sub_813A878(0);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 4:
        sub_813A878(0);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 3:
        sub_813A878(1);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 2:
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    }
}

void sub_81A1830(void)
{
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 currSymbol = sub_81A3B30(facility);
    if (currSymbol == 2)
        currSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA8;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA9_a;
        break;
    case 5:
        gSpecialVar_Result = gBattleOutcome;
        gBattleOutcome = 0;
        break;
    case 6:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA9_b;
        break;
    case 7:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D00 & gUnknown_08611BFC[facility][currSymbol];
        break;
    }
}

void sub_81A1968(void)
{
    s32 i;
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 currSymbol = sub_81A3B30(facility);
    if (currSymbol == 2)
        currSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
	case 0:
        gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_0x8006;
        break;
    case 2:
        gSaveBlock2Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_CA9_a = gSpecialVar_0x8006;
        break;
    case 4:
        for (i = 0; i < 4; i++)
            gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gUnknown_0203CEF8[i];
        break;
    case 6:
        gSaveBlock2Ptr->frontier.field_CA9_b = gSpecialVar_0x8006;
        break;
    case 7:
        gSaveBlock2Ptr->frontier.field_D00 |= gUnknown_08611BFC[facility][currSymbol];
        break;
    }
}

void sub_81A1AD4(void)
{
    s32 i;

    sub_81B8558();
    for (i = 0; i < gSpecialVar_0x8005; i++)
        gUnknown_0203CEF8[i] = gSaveBlock2Ptr->frontier.selectedPartyMons[i];
    ReducePlayerPartyToThree();
}

void sub_81A1B1C(void)
{
    DoSoftReset();
}

void sub_81A1B28(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

void sub_81A1B38(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
            gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
    }
}

void sub_81A1B98(void)
{
    if (gSpecialVar_0x8006 > 3)
        gSpecialVar_0x8006 = 0;
    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_FACILITY_TOWER:
        ShowTowerResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_DOME:
        ShowDomeResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_PALACE:
        ShowPalaceResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_PIKE:
        ShowPikeResultsWindow();
        break;
    case FRONTIER_FACILITY_FACTORY:
        ShowFactoryResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_ARENA:
        ShowArenaResultsWindow();
        break;
    case FRONTIER_FACILITY_PYRAMID:
        ShowPyramidResultsWindow();
        break;
    case 7:
        ShowLinkContestResultsWindow();
        break;
    }
}

static bool8 sub_81A1C24(u32 flags)
{
    if (gSaveBlock2Ptr->frontier.field_CDC & flags)
        return TRUE;
    else
        return FALSE;
}

static void sub_81A1C4C(const u8 *str, s32 y)
{
    s32 x = GetStringCenterAlignXOffset(1, str, 0xE0);
    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, y, TEXT_SPEED_FF, NULL);
}

static void PrintHyphens(s32 y)
{
    s32 i;
    u8 text[37];

    for (i = 0; i < 36; i++)
        text[i] = CHAR_HYPHEN;
    text[i] = EOS;

    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, 1, text, 4, y, TEXT_SPEED_FF, NULL);
}

// Battle Tower records.
static void TowerPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void TowerPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode];
    TowerPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 TowerGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void TowerPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = TowerGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(2);
        else
            isCurrent = sub_81A1C24(1);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x8000);
        else
            isCurrent = sub_81A1C24(0x4000);
        break;
    case FRONTIER_MODE_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x20000);
        else
            isCurrent = sub_81A1C24(0x10000);
        break;
    case FRONTIER_MODE_LINK_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x80000);
        else
            isCurrent = sub_81A1C24(0x40000);
        break;
    }

    if (isCurrent == TRUE)
        TowerPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        TowerPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowTowerResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_DOUBLES)
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_MULTIS)
        StringExpandPlaceholders(gStringVar4, gText_MultiBattleRoomResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_LinkMultiBattleRoomResults);

    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 132, 49);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 132, 65);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 97);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Dome records.
static u16 DomeGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PrintTwoStrings(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str1, x1, y, TEXT_SPEED_FF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void DomePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = DomeGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(8);
        else
            isCurrent = sub_81A1C24(4);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x200000);
        else
            isCurrent = sub_81A1C24(0x100000);
        break;
    }

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_ClearStreak, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_ClearStreak, winStreak, x1, x2, y);
}

static void ShowDomeResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleTourneyResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleTourneyResults);

    sub_81A1C4C(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 64, 121, 33);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_50], 64, 121, 49);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_50], 64, 112, 65);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 64, 121, 97);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_OPEN], 64, 121, 113);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_OPEN], 64, 112, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Palace records.
static void PalacePrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void PalacePrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode];
    PalacePrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PalaceGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PalacePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PalaceGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x20);
        else
            isCurrent = sub_81A1C24(0x10);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x800000);
        else
            isCurrent = sub_81A1C24(0x400000);
    }

    if (isCurrent == TRUE)
        PalacePrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PalacePrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPalaceResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleHallResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleHallResults);

    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 131, 49);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 131, 65);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 97);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Pike records.
static u16 PikeGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PikePrintCleared(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str1, x1, y, TEXT_SPEED_FF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void PikePrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PikeGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x800);
    else
        isCurrent = sub_81A1C24(0x400);

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_RoomsCleared, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_RoomsCleared, winStreak, x1, x2, y);
}

static void ShowPikeResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    StringExpandPlaceholders(gStringVar4, gText_BattleChoiceResults);
    sub_81A1C4C(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 114, 33);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_50], 64, 114, 49);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_50], 64, 114, 65);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 114, 97);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_OPEN], 64, 114, 113);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_OPEN], 64, 114, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Arena records.
static void ArenaPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_KOsInARow);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void ArenaPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode];
    ArenaPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 ArenaGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void ArenaPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = ArenaGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x80);
    else
        isCurrent = sub_81A1C24(0x40);

    if (isCurrent == TRUE)
        ArenaPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        ArenaPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowArenaResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    PrintHyphens(10);
    StringExpandPlaceholders(gStringVar4, gText_SetKOTourneyResults);
    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 72, 126, 49);
    ArenaPrintRecordStreak(FRONTIER_LVL_50, 72, 126, 65);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 72, 126, 97);
    ArenaPrintRecordStreak(FRONTIER_LVL_OPEN, 72, 126, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Factory records.
static void FactoryPrintStreak(const u8 *str, u16 num1, u16 num2, u8 x1, u8 x2, u8 x3, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num1 > 9999)
        num1 = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num1, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);

    ConvertIntToDecimalStringN(gStringVar1, num2, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TimesVar1);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x3, y, TEXT_SPEED_FF, NULL);
}

static void FactoryPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    u16 num1 = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode];
    u16 num2 = gSaveBlock2Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode];
    FactoryPrintStreak(gText_Record, num1, num2, x1, x2, x3, y);
}

static u16 FactoryGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static u16 FactoryGetRentsCount(u8 battleMode, u8 lvlMode)
{
    u16 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
    if (rents > 9999)
        return 9999;
    else
        return rents;
}

static void FactoryPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = FactoryGetWinStreak(battleMode, lvlMode);
    u16 rents = FactoryGetRentsCount(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x200);
        else
            isCurrent = sub_81A1C24(0x100);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x2000000);
        else
            isCurrent = sub_81A1C24(0x1000000);
        break;
    }

    if (isCurrent == TRUE)
        FactoryPrintStreak(gText_Current, winStreak, rents, x1, x2, x3, y);
    else
        FactoryPrintStreak(gText_Prev, winStreak, rents, x1, x2, x3, y);
}

static void ShowFactoryResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapSingleResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapDoubleResults);

    sub_81A1C4C(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_RentalSwap, 152, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 49);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 65);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 113);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Pyramid records.
static void PyramidPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_FloorsCleared);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void PyramidPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode];
    PyramidPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PyramidGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PyramidPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PyramidGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x2000);
    else
        isCurrent = sub_81A1C24(0x1000);

    if (isCurrent == TRUE)
        PyramidPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PyramidPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPyramidResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    StringExpandPlaceholders(gStringVar4, gText_BattleQuestResults);
    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 111, 49);
    PyramidPrintRecordStreak(FRONTIER_LVL_50, 64, 111, 65);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 111, 97);
    PyramidPrintRecordStreak(FRONTIER_LVL_OPEN, 64, 111, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Link contest records. Why is it in this file?
static void ShowLinkContestResultsWindow(void)
{
    const u8 *str;
    s32 i, j;
    s32 x;

    gRecordsWindowId = AddWindow(&gUnknown_08611C7C);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);

    StringExpandPlaceholders(gStringVar4, gText_LinkContestResults);
    x = GetStringCenterAlignXOffset(1, gStringVar4, 0xD0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x, 1, TEXT_SPEED_FF, NULL);

    str = gText_1st;
    x = GetStringRightAlignXOffset(1, str, 0x26) + 50;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    str = gText_2nd;
    x = GetStringRightAlignXOffset(1, str, 0x26) + 88;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    str = gText_3rd;
    x = GetStringRightAlignXOffset(1, str, 0x26) + 126;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    str = gText_4th;
    x = GetStringRightAlignXOffset(1, str, 0x26) + 164;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    x = 6;
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Cool, x, 41, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Beauty, x, 57, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Cute, x, 73, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Smart, x, 89, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Tough, x, 105, TEXT_SPEED_FF, NULL);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            ConvertIntToDecimalStringN(gStringVar4, gSaveBlock2Ptr->contestLinkResults[i][j], STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, (j * 38) + 64, (i * 16) + 41, TEXT_SPEED_FF, NULL);
        }
    }

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

void sub_81A31FC(void)
{
    u8 text[32];
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            if (battleMode == FRONTIER_MODE_LINK_MULTIS)
            {
                StringCopy(text, gLinkPlayers[gBattleScripting.multiplayerId ^ 1].name);
                StripExtCtrlCodes(text);
                StringCopy(gSaveBlock2Ptr->frontier.field_EE1[lvlMode], text);
                WriteUnalignedWord(gLinkPlayers[gBattleScripting.multiplayerId ^ 1].trainerId, gSaveBlock2Ptr->frontier.field_EF1[lvlMode]);
            }
            if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                switch (battleMode)
                {
                case FRONTIER_MODE_SINGLES:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 1);
                    break;
                case FRONTIER_MODE_DOUBLES:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 2);
                    break;
                case FRONTIER_MODE_MULTIS:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 3);
                    break;
                case FRONTIER_MODE_LINK_MULTIS:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 4);
                    break;
                }
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode], 5);
                else
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode], 6);
            }
        }
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], 11);
                else
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], 12);
            }
        }
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 1
                && sub_80EE818())
            {
                sub_80EE8C8(gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode], 10);
            }
        }
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
            gSaveBlock2Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], 7);
                else
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], 8);
            }
        }
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pikeRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.pikeRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] > 1
                && sub_80EE818())
            {
                sub_80EE8C8(gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode], 9);
            }
        }
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > 1
                && sub_80EE818())
            {
                sub_80EE8C8(gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode], 13);
            }
        }
        break;
    }
}

void sub_81A35EC(void)
{
    VarGet(VAR_FRONTIER_FACILITY); // Unused return value.
    gSpecialVar_Result = sub_81A3610();
}

u8 sub_81A3610(void)
{
    s32 ret = 0;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 val = GetCurrentFacilityWinStreak();
    s32 r5 = val + gUnknown_08611550[facility][3];
    s32 symbolsCount;

    if (battleMode != FRONTIER_MODE_SINGLES)
        return 0;

    symbolsCount = sub_81A3B30(facility);
    switch (symbolsCount)
    {
    case 0:
    case 1:
        if (r5 == gUnknown_08611550[facility][symbolsCount])
            ret = symbolsCount + 1;
        break;
    case 2:
    default:
        if (r5 == gUnknown_08611550[facility][0])
            ret = 3;
        else if (r5 == gUnknown_08611550[facility][1])
            ret = 4;
        else if (r5 > gUnknown_08611550[facility][1] && (r5 - gUnknown_08611550[facility][1]) % gUnknown_08611550[facility][2] == 0)
            ret = 4;
        break;
    }

    return ret;
}

void CopyFrontierTrainerText(u8 whichText, u16 trainerId)
{
    switch (whichText)
    {
    case FRONTIER_BEFORE_TEXT:
        if (trainerId == TRAINER_EREADER)
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.greeting);
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
            sub_81A51A8(0);
        else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].greeting);
        else
            CopyFriendsApprenticeChallengeText(trainerId - TRAINER_RECORD_MIXING_APPRENTICE);
        break;
    case FRONTIER_PLAYER_LOST_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerLost);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            sub_81A51A8(0);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
        {
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechWin);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(sub_81864E0());
            else
                FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].speechWon);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(sub_81864E0());
            else
                FrontierSpeechToString(gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].easyChatWords);
        }
        break;
    case FRONTIER_PLAYER_WON_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerWon);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            sub_81A51A8(1);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
        {
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechLose);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(sub_81864E0());
            else
                FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].speechLost);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            {
                trainerId = sub_81864A8();
                FrontierSpeechToString(gApprentices[trainerId].easyChatWords);
            }
            else
            {
                trainerId = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id;
                FrontierSpeechToString(gApprentices[trainerId].easyChatWords);
            }
        }
        break;
    }
}

void sub_81A3908(void)
{
    s32 battleMode, lvlMode;

    gSaveBlock2Ptr->frontier.field_CDC = 0;
    for (battleMode = 0; battleMode < 4; battleMode++)
    {
        for (lvlMode = 0; lvlMode < 2; lvlMode++)
        {
            gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] = 0;
            if (battleMode < FRONTIER_MODE_MULTIS)
            {
                gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] = 0;
                gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] = 0;
                gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
            }
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = 0;
                gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] = 0;
                gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = 0;
            }
        }
    }
    if (gSaveBlock2Ptr->frontier.field_CA8 != 0)
        gSaveBlock2Ptr->frontier.field_CA8 = 1;
}

u32 GetCurrentFacilityWinStreak(void)
{
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        return gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_DOME:
        return gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_PALACE:
        return gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_ARENA:
        return gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
    case FRONTIER_FACILITY_FACTORY:
        return gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_PIKE:
        return gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    case FRONTIER_FACILITY_PYRAMID:
        return gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
    default:
        return 0;
    }
}

void sub_81A3ACC(void)
{
    s32 i;

    for (i = 0; i < 20; i++)
        gSaveBlock2Ptr->frontier.field_CB4[i] |= 0xFFFF;
}

void sub_81A3B00(void)
{
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

u8 sub_81A3B30(u8 facility)
{
    return FlagGet(FLAG_SYS_TOWER_SILVER + facility * 2)
         + FlagGet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

void sub_81A3B64(void)
{
    s32 challengeNum = 0;
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 points;

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_DOME:
        challengeNum = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
        break;
    case FRONTIER_FACILITY_PALACE:
        challengeNum = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_ARENA:
        challengeNum = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_FACTORY:
        challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_PIKE:
        challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / 14;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        challengeNum = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7;
        break;
    }

    if (challengeNum != 0)
        challengeNum--;
    if (challengeNum > ARRAY_COUNT(gUnknown_086118B4))
        challengeNum = ARRAY_COUNT(gUnknown_086118B4);

    points = gUnknown_086118B4[challengeNum][facility][battleMode];
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        points += 10;
    gSaveBlock2Ptr->frontier.battlePoints += points;
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN, 2);
    if (gSaveBlock2Ptr->frontier.battlePoints > 9999)
        gSaveBlock2Ptr->frontier.battlePoints = 9999;

    points = gSaveBlock2Ptr->frontier.field_EBA;
    points += gUnknown_086118B4[challengeNum][facility][battleMode];
    sub_80EED60(gUnknown_086118B4[challengeNum][facility][battleMode]);
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
    {
        points += 10;
        sub_80EED60(10);
    }
    if (points > 0xFFFF)
        points = 0xFFFF;
    gSaveBlock2Ptr->frontier.field_EBA = points;
}

void sub_81A3D30(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    gSpecialVar_Result = sub_81A3B30(facility);
}

void sub_81A3D58(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    if (sub_81A3B30(facility) == 0)
        FlagSet(FLAG_SYS_TOWER_SILVER + facility * 2);
    else
        FlagSet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

void sub_81A3DA0(void)
{
    if (gBattleTypeFlags & gSpecialVar_0x8005)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 sub_81A3DD0(u16 species, u8 arg1, s32 arg2)
{
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        arg1++;
        switch (arg1)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            if (arg2 == arg1)
                StringAppend(gStringVar1, gText_SpaceAndSpace);
            else if (arg2 > arg1)
                StringAppend(gStringVar1, gText_CommaSpace);
            break;
        case 2:
            if (arg1 == arg2)
                StringAppend(gStringVar1, gText_SpaceAndSpace);
            else
                StringAppend(gStringVar1, gText_CommaSpace);
            StringAppend(gStringVar1, gText_NewLine);
            break;
        default:
            if (arg1 == arg2)
                StringAppend(gStringVar1, gText_SpaceAndSpace);
            else
                StringAppend(gStringVar1, gText_CommaSpace);
            StringAppend(gStringVar1, gText_ScrollTextUp);
            break;
        }
        StringAppend(gStringVar1, gSpeciesNames[species]);
    }

    return arg1;
}

static void AppendIfValid(u16 species, u16 heldItem, u16 hp, u8 lvlMode, u8 monLevel, u16 *speciesArray, u16 *itemsArray, u8 *count)
{
    s32 i = 0;

    if (species == SPECIES_EGG || species == SPECIES_NONE)
        return;

    for (i = 0; gUnknown_08611C9A[i] != 0xFFFF && gUnknown_08611C9A[i] != species; i++)
        ;

    if (gUnknown_08611C9A[i] != 0xFFFF)
        return;
    if (lvlMode == FRONTIER_LVL_50 && monLevel > 50)
        return;

    for (i = 0; i < *count && speciesArray[i] != species; i++)
        ;
    if (i != *count)
        return;

    if (heldItem != 0)
    {
        for (i = 0; i < *count && itemsArray[i] != heldItem; i++)
            ;
        if (i != *count)
            return;
    }

    speciesArray[*count] = species;
    itemsArray[*count] = heldItem;
    (*count)++;
}

void sub_81A3FD4(void)
{
    u16 speciesArray[6];
    u16 itemArray[6];
    s32 monId = 0;
    s32 toChoose = 0;
    u8 count = 0;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 monIdLooper;

    switch (battleMode)
    {
    case FRONTIER_MODE_SINGLES:
        toChoose = 3;
        break;
    case FRONTIER_MODE_MULTIS:
    case FRONTIER_MODE_LINK_MULTIS:
        toChoose = 2;
        break;
    case FRONTIER_MODE_DOUBLES:
        if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_TOWER)
            toChoose = 4;
        else
            toChoose = 3;
        break;
    }

    monIdLooper = 0;
    do
    {
        monId = monIdLooper;
        count = 0;
        do
        {
            u16 species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES2);
            u16 heldItem = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
            u8 level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
            u16 hp = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
            if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_PYRAMID)
            {
                if (heldItem == 0)
                    AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &count);
            }
            else
            {
                AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &count);
            }
            monId++;
            if (monId >= PARTY_SIZE)
                monId = 0;
        } while (monId != monIdLooper);

        monIdLooper++;
    } while (monIdLooper < PARTY_SIZE && count < toChoose);

    if (count < toChoose)
    {
        s32 i;
        s32 caughtBannedMons = 0;
        s32 species = gUnknown_08611C9A[0];
        for (i = 0; species != 0xFFFF; i++, species = gUnknown_08611C9A[i])
        {
            if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                caughtBannedMons++;
        }
        gStringVar1[0] = EOS;
        gSpecialVar_0x8004 = 1;
        count = 0;
        for (i = 0; gUnknown_08611C9A[i] != 0xFFFF; i++)
            count = sub_81A3DD0(gUnknown_08611C9A[i], count, caughtBannedMons);

        if (count == 0)
        {
            StringAppend(gStringVar1, gText_Space2);
            StringAppend(gStringVar1, gText_Are);
        }
        else
        {
            if (count & 1)
                StringAppend(gStringVar1, gText_ScrollTextUp);
            else
                StringAppend(gStringVar1, gText_Space2);
            StringAppend(gStringVar1, gText_Are2);
        }
    }
    else
    {
        gSpecialVar_0x8004 = 0;
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_Result;
    }
}

void sub_81A4224(void)
{
    ValidateEReaderTrainer();
}

void sub_81A4230(void)
{
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] < 9999)
        {
            gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode]++;
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                SetGameStat(GAME_STAT_BATTLE_TOWER_BEST_STREAK, gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode]);
                gSaveBlock2Ptr->frontier.field_D02 = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode]++;
        if (gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode]++;
        break;
    }
}

void sub_81A43A8(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->frontier.selectedPartyMons[i] != 0)
        {
            u16 item = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_HELD_ITEM, NULL);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

void sub_81A4410(void)
{
    gSpecialVar_Result = MoveRecordedBattleToSaveData();
    gSaveBlock2Ptr->frontier.field_CA9_b = 1;
}

void sub_81A443C(void)
{
    switch (gSpecialVar_0x8005)
    {
    case 0:
        GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
        break;
    case 1:
        GetFrontierTrainerName(gStringVar2, gTrainerBattleOpponent_A);
        break;
    }
}

void sub_81A447C(void)
{
    u8 i, j, k;

    for (i = 0; i < 4; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
        {
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    if (GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_MOVE1 + k, NULL)
                        == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL))
                        break;
                }
                if (k == 4)
                    SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, j);
            }
            gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
        }
    }
}

void sub_81A457C(void)
{
    sub_81A5030(VarGet(VAR_FRONTIER_FACILITY));
}

// Battle Frontier Ranking Hall records.
static void Print1PRecord(s32 position, s32 x, s32 y, struct RankingHall1P *hallRecord, s32 hallFacilityId)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    hallRecord->name[PLAYER_NAME_LENGTH] = EOS;
    if (hallRecord->winStreak)
    {
        TVShowConvertInternationalString(text, hallRecord->name, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, (x + 2) * 8, (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
        winStreak = hallRecord->winStreak;
        if (winStreak > 9999)
            winStreak = 9999;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gUnknown_08611D08[hallFacilityId]);
        AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, GetStringRightAlignXOffset(1, gUnknown_08611D08[hallFacilityId], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    }
}

static void Print2PRecord(s32 position, s32 x, s32 y, struct RankingHall2P *hallRecord)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    if (hallRecord->winStreak)
    {
        hallRecord->name1[PLAYER_NAME_LENGTH] = EOS;
        hallRecord->name2[PLAYER_NAME_LENGTH] = EOS;
        TVShowConvertInternationalString(text, hallRecord->name1, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, (x + 2) * 8, (8 * (y + 5 * position - 1)) + 1, TEXT_SPEED_FF, NULL);
        if (IsStringJapanese(hallRecord->name2))
            TVShowConvertInternationalString(text, hallRecord->name2, LANGUAGE_JAPANESE);
        else
            StringCopy(text, hallRecord->name2);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, (x + 4) * 8, (8 * (y + 5 * position + 1)) + 1, TEXT_SPEED_FF, NULL);

        winStreak = hallRecord->winStreak;
        if (winStreak > 9999)
            winStreak = 9999;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gUnknown_08611D08[9]);
        AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, GetStringRightAlignXOffset(1, gUnknown_08611D08[9], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    }
}

static void Fill1PRecords(struct RankingHall1P *dst, s32 hallFacilityId, s32 lvlMode)
{
    s32 i, j;
    struct RankingHall1P record1P[4];
    struct PlayerHallRecords *playerHallRecords = calloc(1, sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < 3; i++)
        record1P[i] = gSaveBlock2Ptr->hallRecords1P[hallFacilityId][lvlMode][i];

    record1P[3] = playerHallRecords->onePlayer[hallFacilityId][lvlMode];

    for (i = 0; i < 3; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < 4; j++)
        {
            if (record1P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record1P[j].winStreak;
            }
        }
        if (record1P[3].winStreak >= highestWinStreak)
            highestId = 3;

        dst[i] = record1P[highestId];
        record1P[highestId].winStreak = 0;
    }

    free(playerHallRecords);
}

static void Fill2PRecords(struct RankingHall2P *dst, s32 lvlMode)
{
    s32 i, j;
    struct RankingHall2P record2P[4];
    struct PlayerHallRecords *playerHallRecords = calloc(1, sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < 3; i++)
        record2P[i] = gSaveBlock2Ptr->hallRecords2P[lvlMode][i];

    record2P[3] = playerHallRecords->twoPlayers[lvlMode];

    for (i = 0; i < 3; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < 3; j++)
        {
            if (record2P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record2P[j].winStreak;
            }
        }
        if (record2P[3].winStreak >= highestWinStreak)
            highestId = 3;

        dst[i] = record2P[highestId];
        record2P[highestId].winStreak = 0;
    }

    free(playerHallRecords);
}

static void PrintHallRecords(s32 hallFacilityId, s32 lvlMode)
{
    s32 i;
    s32 x;
    struct RankingHall1P records1P[3];
    struct RankingHall2P records2P[3];

    StringCopy(gStringVar1, gUnknown_08611CB0[hallFacilityId][0]);
    StringExpandPlaceholders(gStringVar4, gUnknown_08611CB0[hallFacilityId][1]);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
    x = GetStringRightAlignXOffset(1, gUnknown_08611D00[lvlMode], 0xD0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gUnknown_08611D00[lvlMode], x, 1, TEXT_SPEED_FF, NULL);
    if (hallFacilityId == HALL_FACILITIES_COUNT)
    {
        gSaveBlock2Ptr->frontier.field_EE1[0][PLAYER_NAME_LENGTH] = EOS;
        gSaveBlock2Ptr->frontier.field_EE1[1][PLAYER_NAME_LENGTH] = EOS;
        Fill2PRecords(records2P, lvlMode);
        for (i = 0; i < 3; i++)
            Print2PRecord(i, 1, 4, &records2P[i]);
    }
    else
    {
        Fill1PRecords(records1P, hallFacilityId, lvlMode);
        for (i = 0; i < 3; i++)
            Print1PRecord(i, 1, 4, &records1P[i], hallFacilityId);
    }
}

void ShowRankingHallRecordsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C84);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_50);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

void ScrollRankingHallRecordsWindow(void)
{
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_OPEN);
    CopyWindowToVram(gRecordsWindowId, 2);
}
