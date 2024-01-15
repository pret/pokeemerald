#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "rtc.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_BLACK
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBgs(void);

// add additional themes here
static const u8 sMapPopUpTilesPrimary_Black[] = INCBIN_U8("graphics/map_popup/black_primary.4bpp");
static const u8 sMapPopUpTilesSecondary_Black[] = INCBIN_U8("graphics/map_popup/black_secondary.4bpp");
static const u16 sMapPopUpTilesPalette_Black[16] = INCBIN_U16("graphics/map_popup/black.gbapal");

static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping[] =
{
    [MAPSEC_LITTLEROOT_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_OLDALE_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_DEWFORD_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_LAVARIDGE_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_FALLARBOR_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_VERDANTURF_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_PACIFIDLOG_TOWN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_PETALBURG_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SLATEPORT_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MAUVILLE_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_RUSTBORO_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_FORTREE_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_LILYCOVE_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MOSSDEEP_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SOOTOPOLIS_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_EVER_GRANDE_CITY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_101] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_102] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_103] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_104] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_105] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_106] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_107] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_108] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_109] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_110] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_111] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_112] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_113] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_114] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_115] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_116] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_117] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_118] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_119] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_120] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_121] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_122] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_123] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_124] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_125] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_126] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_127] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_128] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_129] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_130] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_131] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_132] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_133] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ROUTE_134] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_124] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_126] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_127] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_128] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_SOOTOPOLIS] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_GRANITE_CAVE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MT_CHIMNEY] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_PETALBURG_WOODS] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_RUSTURF_TUNNEL] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ABANDONED_SHIP] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_NEW_MAUVILLE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_METEOR_FALLS] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_METEOR_FALLS2] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MT_PYRE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_AQUA_HIDEOUT_OLD] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SHOAL_CAVE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MIRAGE_ISLAND] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_CAVE_OF_ORIGIN] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_FIERY_PATH] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_FIERY_PATH2] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_JAGGED_PASS] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_JAGGED_PASS2] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SEALED_CHAMBER] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_SEALED_CHAMBER] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SCORCHED_SLAB] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ISLAND_CAVE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_DESERT_RUINS] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ANCIENT_TOMB] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_INSIDE_OF_TRUCK] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SKY_PILLAR] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_AQUA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MAGMA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MIRAGE_TOWER - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_BIRTH_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_FARAWAY_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ARTISAN_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_TERRA_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_105 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_125 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_UNDERWATER_129 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_DESERT_UNDERPASS - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_ALTERING_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_NAVEL_ROCK - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
    [MAPSEC_TRAINER_HILL - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BLACK,
};

static const u8 sText_PyramidFloor1[] = _("PYRAMID FLOOR 1");
static const u8 sText_PyramidFloor2[] = _("PYRAMID FLOOR 2");
static const u8 sText_PyramidFloor3[] = _("PYRAMID FLOOR 3");
static const u8 sText_PyramidFloor4[] = _("PYRAMID FLOOR 4");
static const u8 sText_PyramidFloor5[] = _("PYRAMID FLOOR 5");
static const u8 sText_PyramidFloor6[] = _("PYRAMID FLOOR 6");
static const u8 sText_PyramidFloor7[] = _("PYRAMID FLOOR 7");
static const u8 sText_Pyramid[] = _("PYRAMID");

static const u8 * const sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    sText_PyramidFloor1,
    sText_PyramidFloor2,
    sText_PyramidFloor3,
    sText_PyramidFloor4,
    sText_PyramidFloor5,
    sText_PyramidFloor6,
    sText_PyramidFloor7,
    sText_Pyramid,
};

static bool8 UNUSED StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

// States and data defines for Task_MapNamePopUpWindow
enum {
    STATE_SLIDE_IN,
    STATE_WAIT,
    STATE_SLIDE_OUT,
    STATE_UNUSED,
    STATE_ERASE,
    STATE_END,
    STATE_PRINT, // For some reason the first state is numerically last.
};

#define POPUP_OFFSCREEN_Y  24
#define POPUP_SLIDE_SPEED  2

#define tState         data[0]
#define tOnscreenTimer data[1]
#define tYOffset       data[2]
#define tIncomingPopUp data[3]
#define tPrintTimer    data[4]

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            // New pop up window
            gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 100);

            if (MAPPOPUP_ALPHA_BLEND)
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);

            gTasks[gPopupTaskId].tState = STATE_PRINT;
            gTasks[gPopupTaskId].tYOffset = POPUP_OFFSCREEN_Y;
        }
        else
        {
            // There's already a pop up window running.
            // Hurry the old pop up offscreen so the new one can appear.
            if (gTasks[gPopupTaskId].tState != STATE_SLIDE_OUT)
                gTasks[gPopupTaskId].tState = STATE_SLIDE_OUT;
            gTasks[gPopupTaskId].tIncomingPopUp = TRUE;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_PRINT:
        // Wait, then create and print the pop up window
        if (++task->tPrintTimer > 30)
        {
            task->tState = STATE_SLIDE_IN;
            task->tPrintTimer = 0;
            ShowMapNamePopUpWindow();
            EnableInterrupts(INTR_FLAG_HBLANK);
            SetHBlankCallback(HBlankCB_DoublePopupWindow);
        }
        break;
    case STATE_SLIDE_IN:
        // Slide the window onscreen.
        task->tYOffset -= POPUP_SLIDE_SPEED;
        if (task->tYOffset <= 0 )
        {
            task->tYOffset = 0;
            task->tState = STATE_WAIT;
            gTasks[gPopupTaskId].tOnscreenTimer = 0;
        }
        break;
    case STATE_WAIT:
        // Wait while the window is fully onscreen.
        if (++task->tOnscreenTimer > 120)
        {
            task->tOnscreenTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;
    case STATE_SLIDE_OUT:
        // Slide the window offscreen.
        task->tYOffset += POPUP_SLIDE_SPEED;
        if (task->tYOffset >= POPUP_OFFSCREEN_Y)
        {
            task->tYOffset = POPUP_OFFSCREEN_Y;
            if (task->tIncomingPopUp)
            {
                // A new pop up window is incoming,
                // return to the first state to show it.
                task->tState = STATE_PRINT;
                task->tPrintTimer = 0;
                task->tIncomingPopUp = FALSE;
            }
            else
            {
                task->tState = STATE_ERASE;
                return;
            }
        }
        break;
    case STATE_ERASE:
        ClearStdWindowAndFrame(GetPrimaryPopUpWindowId(), TRUE);
        ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        task->tState = STATE_END;
        break;
    case STATE_END:
        HideMapNamePopUpWindow();
        return;
    }
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        ClearStdWindowAndFrame(GetPrimaryPopUpWindowId(), TRUE);
        ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        RemovePrimaryPopUpWindow();
        RemoveSecondaryPopUpWindow();
        DisableInterrupts(INTR_FLAG_HBLANK);
        SetHBlankCallback(NULL);
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);

        if (MAPPOPUP_ALPHA_BLEND)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 10));
        }

        DestroyTask(gPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 mapNameX, timeX, mapNameY, timeY, primaryPopUpWindowId, secondaryPopUpWindowId;
    const u8 *mapDisplayHeaderSource;

    mapNameX = 8;
    mapNameY = 2;
    timeX = 5;
    timeY = 8;

    if (MAPPOPUP_ALPHA_BLEND)
        SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR);

    primaryPopUpWindowId = AddPrimaryPopUpWindow();
    secondaryPopUpWindowId = AddSecondaryPopUpWindow();

    LoadMapNamePopUpWindowBgs();

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }

    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;

    AddTextPrinterParameterized(primaryPopUpWindowId, FONT_SHORT, mapDisplayHeader, mapNameX, mapNameY, TEXT_SKIP_DRAW, NULL);
    FormatDecimalTimeWithoutSeconds(withoutPrefixPtr, gLocalTime.hours, gLocalTime.minutes, MAPPOPUP_24_HOUR_TIME);
    AddTextPrinterParameterized(secondaryPopUpWindowId, FONT_SMALL, mapDisplayHeader, GetStringRightAlignXOffset(FONT_SMALL, mapDisplayHeader, DISPLAY_WIDTH) - timeX, timeY, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(primaryPopUpWindowId, COPYWIN_FULL);
    CopyWindowToVram(secondaryPopUpWindowId, COPYWIN_FULL);
}

static void LoadMapNamePopUpWindowBgs(void)
{
    u8 popupThemeId;
    u8 primaryPopUpWindowId = GetPrimaryPopUpWindowId();
    u8 secondaryPopUpWindowId = GetSecondaryPopUpWindowId();
    u16 regionMapSectionId = gMapHeader.regionMapSectionId;

    if (regionMapSectionId >= KANTO_MAPSEC_START)
    {
        if (regionMapSectionId > KANTO_MAPSEC_END)
            regionMapSectionId -= KANTO_MAPSEC_COUNT;
        else
            regionMapSectionId = 0; // Discard kanto region sections;
    }
    popupThemeId = sRegionMapSectionId_To_PopUpThemeIdMapping[regionMapSectionId];

    switch (popupThemeId) {
        case MAPPOPUP_THEME_BLACK:
            LoadPalette(sMapPopUpTilesPalette_Black, BG_PLTT_ID(14), sizeof(sMapPopUpTilesPalette_Black));
            CopyToWindowPixelBuffer(primaryPopUpWindowId, sMapPopUpTilesPrimary_Black, sizeof(sMapPopUpTilesPrimary_Black), 0);
            CopyToWindowPixelBuffer(secondaryPopUpWindowId, sMapPopUpTilesSecondary_Black, sizeof(sMapPopUpTilesSecondary_Black), 0);
            break;
        // add additional themes here
        default:
            LoadPalette(sMapPopUpTilesPalette_Black, BG_PLTT_ID(14), sizeof(sMapPopUpTilesPalette_Black));
            CopyToWindowPixelBuffer(primaryPopUpWindowId, sMapPopUpTilesPrimary_Black, sizeof(sMapPopUpTilesPrimary_Black), 0);
            CopyToWindowPixelBuffer(secondaryPopUpWindowId, sMapPopUpTilesSecondary_Black, sizeof(sMapPopUpTilesSecondary_Black), 0);
            break;
    }

    PutWindowTilemap(primaryPopUpWindowId);
    PutWindowTilemap(secondaryPopUpWindowId);
}
