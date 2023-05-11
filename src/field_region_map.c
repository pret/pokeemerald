#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "region_map.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"

/*
 *  This is the type of map shown when interacting with the metatiles for
 *  a wall-mounted Region Map (on the wall of the Pokemon Centers near the PC)
 *  It does not zoom, and pressing A or B closes the map
 *
 *  For the region map in the pokenav, see pokenav_region_map.c
 *  For the region map in the pokedex, see pokdex_area_screen.c/pokedex_area_region_map.c
 *  For the fly map, and utility functions all of the maps use, see region_map.c
 */

enum {
    WIN_MAPSEC_NAME,
    WIN_TITLE,
};

enum {
    TAG_PLAYER_ICON,
    TAG_CURSOR,
};

static EWRAM_DATA struct {
    MainCallback callback;
    u32 unused;
    struct RegionMap regionMap;
    u16 state;
} *sFieldRegionMapHandler = NULL;

static void MCB2_InitRegionMapRegisters(void);
static void VBCB_FieldUpdateRegionMap(void);
static void MCB2_FieldUpdateRegionMap(void);
static void FieldUpdateRegionMap(void);
static void PrintRegionMapSecName(void);

static const struct BgTemplate sFieldRegionMapBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 2,
        .baseTile = 0
    }
};

static const struct WindowTemplate sFieldRegionMapWindowTemplates[] =
{
    [WIN_MAPSEC_NAME] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 17,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 1,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 25
    },
    DUMMY_WIN_TEMPLATE
};

void FieldInitRegionMap(MainCallback callback)
{
    SetVBlankCallback(NULL);
    sFieldRegionMapHandler = Alloc(sizeof(*sFieldRegionMapHandler));
    sFieldRegionMapHandler->state = 0;
    sFieldRegionMapHandler->callback = callback;
    SetMainCallback2(MCB2_InitRegionMapRegisters);
}

static void MCB2_InitRegionMapRegisters(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sFieldRegionMapBgTemplates, ARRAY_COUNT(sFieldRegionMapBgTemplates));
    InitWindows(sFieldRegionMapWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x27, BG_PLTT_ID(13));
    ClearScheduledBgCopiesToVram();
    SetMainCallback2(MCB2_FieldUpdateRegionMap);
    SetVBlankCallback(VBCB_FieldUpdateRegionMap);
}

static void VBCB_FieldUpdateRegionMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MCB2_FieldUpdateRegionMap(void)
{
    FieldUpdateRegionMap();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    DoScheduledBgTilemapCopiesToVram();
}

static void FieldUpdateRegionMap(void)
{
    u8 offset;

    switch (sFieldRegionMapHandler->state)
    {
        case 0:
            InitRegionMap(&sFieldRegionMapHandler->regionMap, FALSE);
            CreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
            CreateRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
            sFieldRegionMapHandler->state++;
            break;
        case 1:
            DrawStdFrameWithCustomTileAndPalette(WIN_TITLE, FALSE, 0x27, 0xd);
            offset = GetStringCenterAlignXOffset(FONT_NORMAL, gText_Hoenn, 0x38);
            AddTextPrinterParameterized(WIN_TITLE, FONT_NORMAL, gText_Hoenn, offset, 1, 0, NULL);
            ScheduleBgCopyTilemapToVram(0);
            DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 0x27, 0xd);
            PrintRegionMapSecName();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            sFieldRegionMapHandler->state++;
            break;
        case 2:
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(2);
            sFieldRegionMapHandler->state++;
            break;
        case 3:
            if (!gPaletteFade.active)
            {
                sFieldRegionMapHandler->state++;
            }
            break;
        case 4:
            switch (DoRegionMapInputCallback())
            {
                case MAP_INPUT_MOVE_END:
                    PrintRegionMapSecName();
                    break;
                case MAP_INPUT_A_BUTTON:
                case MAP_INPUT_B_BUTTON:
                    sFieldRegionMapHandler->state++;
                    break;
            }
            break;
        case 5:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sFieldRegionMapHandler->state++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                FreeRegionMapIconResources();
                SetMainCallback2(sFieldRegionMapHandler->callback);
                TRY_FREE_AND_SET_NULL(sFieldRegionMapHandler);
                FreeAllWindowBuffers();
            }
            break;
    }
}

static void PrintRegionMapSecName(void)
{
    if (sFieldRegionMapHandler->regionMap.mapSecType != MAPSECTYPE_NONE)
    {
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        AddTextPrinterParameterized(WIN_MAPSEC_NAME, FONT_NORMAL, sFieldRegionMapHandler->regionMap.mapSecName, 0, 1, 0, NULL);
        ScheduleBgCopyTilemapToVram(WIN_MAPSEC_NAME);
    }
    else
    {
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        CopyWindowToVram(WIN_MAPSEC_NAME, COPYWIN_FULL);
    }
}
