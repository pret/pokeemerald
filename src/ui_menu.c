#include "global.h"
#include "ui_menu.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "pokemon_icon.h"
#include "pokedex.h"
#include "trainer_pokemon_sprites.h"
#include "field_effect.h"

/*
 * 
 */
 
//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u8 mode;
    u8 monIconSpriteId;
    u16 speciesID;
    u16 selectedStat;
    u16 selectorSpriteId;
    u16 selector_x;
    u16 selector_y;
    u32 editingStat;
    u16 normalTotal;
    u16 evTotal;
    u16 ivTotal;
};

enum WindowIds
{
    WINDOW_1,
    WINDOW_2,
    WINDOW_3,
    WINDOW_4,
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);
static void Task_MenuEditingStat(u8 taskId);
static void SampleUi_DrawMonIcon(u16 dexNum);
static void PrintMonStats(void);
static void SelectorCallback(struct Sprite *sprite);

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 10,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    [WINDOW_2] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 11,   // position from left (per 8 pixels)
        .tilemapTop = 2,    // position from top (per 8 pixels)
        .width = 18,        // width (per 8 pixels)
        .height = 17,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1 + 23,     // tile start in VRAM
    },
    [WINDOW_3] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 11,    // position from top (per 8 pixels)
        .width = 7,        // width (per 8 pixels)
        .height = 9,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1 + 23 + 102 + 204,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[] = INCBIN_U32("graphics/ui_menu/background_tileset.4bpp.lz");
static const u32 sMenuTilemap[] = INCBIN_U32("graphics/ui_menu/background_tileset.bin.lz");
static const u16 sMenuPalette[] = INCBIN_U16("graphics/ui_menu/background_pal.gbapal");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

#define TAG_SELECTOR 30004

static const u16 sSelector_Pal[] = INCBIN_U16("graphics/ui_menu/selector.gbapal");
static const u32 sSelector_Gfx[] = INCBIN_U32("graphics/ui_menu/selector.4bpp.lz");

static const struct OamData sOamData_Selector =
{
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_Selector =
{
    .data = sSelector_Gfx,
    .size = 32*32*4/2,
    .tag = TAG_SELECTOR,
};

static const struct SpritePalette sSpritePal_Selector =
{
    .data = sSelector_Pal,
    .tag = TAG_SELECTOR
};

static const union AnimCmd sSpriteAnim_Selector0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(48, 10),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Selector1[] =
{
    ANIMCMD_FRAME(32, 32),
    ANIMCMD_FRAME(32, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Selector2[] =
{
    ANIMCMD_FRAME(16, 32),
    ANIMCMD_FRAME(16, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Selector3[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Selector[] =
{
    sSpriteAnim_Selector0,
    sSpriteAnim_Selector1,
    sSpriteAnim_Selector2,
    sSpriteAnim_Selector3,
};

static const struct SpriteTemplate sSpriteTemplate_Selector =
{
    .tileTag = TAG_SELECTOR,
    .paletteTag = TAG_SELECTOR,
    .oam = &sOamData_Selector,
    .anims = sSpriteAnimTable_Selector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SelectorCallback
};

// code
static u8 CreateSelector()
{
    if (sMenuDataPtr->selectorSpriteId == 0xFF)
        sMenuDataPtr->selectorSpriteId = CreateSprite(&sSpriteTemplate_Selector, 188, 30, 0);

    gSprites[sMenuDataPtr->selectorSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 0);
    DebugPrintf("Sprite ID: %d", sMenuDataPtr->selectorSpriteId);
    return sMenuDataPtr->selectorSpriteId;
}

static void DestroySelector(void)
{
    if (sMenuDataPtr->selectorSpriteId != 0xFF)
        DestroySprite(&gSprites[sMenuDataPtr->selectorSpriteId]);
    sMenuDataPtr->selectorSpriteId = 0xFF;
}


//==========FUNCTIONS==========//
// UI loader template
void Task_OpenMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Menu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Menu_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;
    sMenuDataPtr->selectorSpriteId = 0xFF;
    
    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        sMenuDataPtr->speciesID = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        LoadCompressedSpriteSheet(&sSpriteSheet_Selector);
        LoadSpritePalette(&sSpritePal_Selector);
        SampleUi_DrawMonIcon(sMenuDataPtr->speciesID);
        gMain.state++;
        break;
    case 5:
        Menu_InitWindows();
        PrintToWindow(WINDOW_1, FONT_WHITE);
        PrintMonStats();
        CreateSelector();
        gMain.state++;
        break;
    case 6:
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    DestroySelector();
    FreeResourcesAndDestroySprite(&gSprites[sMenuDataPtr->monIconSpriteId], sMenuDataPtr->monIconSpriteId);
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sMenuTilemap, sBg1TilemapBuffer);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sMenuPalette, 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

#define MON_ICON_X     32 + 8
#define MON_ICON_Y     32 + 24
static void SampleUi_DrawMonIcon(u16 dexNum)
{
    u16 speciesId = dexNum;
    sMenuDataPtr->monIconSpriteId = CreateMonPicSprite_HandleDeoxys(speciesId, 0, 0x8000, TRUE, MON_ICON_X, MON_ICON_Y, 0, gMonPaletteTable[speciesId].tag);

    gSprites[sMenuDataPtr->monIconSpriteId].oam.priority = 0;
}

static void Menu_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_1, 0);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    
    ScheduleBgCopyTilemapToVram(2);
}

#define DISTANCE_BETWEEN_STATS_Y 16
#define SECOND_COLUMN ((8 * 4))
#define THIRD_COLUMN ((8 * 8))
#define STARTING_X 12 + 48
#define STARTING_Y 6 + 20

struct MonPrintData {
    u16 x;
    u16 y;
};

static const struct MonPrintData StatPrintData[] =
{
    [MON_DATA_MAX_HP] = {STARTING_X, STARTING_Y},
    [MON_DATA_HP_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y},
    [MON_DATA_HP_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y},

    [MON_DATA_ATK] = {STARTING_X, STARTING_Y + DISTANCE_BETWEEN_STATS_Y},
    [MON_DATA_ATK_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + DISTANCE_BETWEEN_STATS_Y},
    [MON_DATA_ATK_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + DISTANCE_BETWEEN_STATS_Y},

    [MON_DATA_DEF] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2)},
    [MON_DATA_DEF_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2)},
    [MON_DATA_DEF_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2)},

    [MON_DATA_SPATK] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3)},
    [MON_DATA_SPATK_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3)},
    [MON_DATA_SPATK_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3)},

    [MON_DATA_SPDEF] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4)},
    [MON_DATA_SPDEF_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4)},
    [MON_DATA_SPDEF_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4)},

    [MON_DATA_SPEED] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5)},
    [MON_DATA_SPEED_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5)},
    [MON_DATA_SPEED_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5)},
};

static const u16 statsToPrintActual[] = {
        MON_DATA_MAX_HP, MON_DATA_ATK, MON_DATA_DEF, MON_DATA_SPEED, MON_DATA_SPATK, MON_DATA_SPDEF,
};

static const u16 statsToPrintEVs[] = {
        MON_DATA_HP_EV, MON_DATA_ATK_EV, MON_DATA_DEF_EV, MON_DATA_SPEED_EV, MON_DATA_SPATK_EV, MON_DATA_SPDEF_EV,
};

static const u16 statsToPrintIVs[] = {
        MON_DATA_HP_IV, MON_DATA_ATK_IV, MON_DATA_DEF_IV, MON_DATA_SPEED_IV, MON_DATA_SPATK_IV, MON_DATA_SPDEF_IV,
};


static const u8 sGenderColors[2][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED}
};

static const u8 sText_MenuTitle[] = _("Stat Editor");
static const u8 sText_MenuHP[] = _("HP");
static const u8 sText_MenuAttack[] = _("Attack");
static const u8 sText_MenuSpAttack[] = _("Sp. Atk");
static const u8 sText_MenuDefense[] = _("Defense");
static const u8 sText_MenuSpDefense[] = _("Sp. Def");
static const u8 sText_MenuSpeed[] = _("Speed");
static const u8 sText_MenuTotal[] = _("Total");
static const u8 sText_MenuStat[] = _("Stat");
static const u8 sText_MenuActual[] = _("Actual");
static const u8 sText_MenuEV[] = _("EV");
static const u8 sText_MenuIV[] = _("IV");
static const u8 sText_MonLevel[]         = _("Lv.{CLEAR 1}{STR_VAR_1}");
static void PrintMonStats()
{
    u8 x = 68;
    u8 y = 6;
    u8 i;
    u16 currentStat;
    u16 nature;
    u8 text[2];
    u16 level = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
    u16 personality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
    u16 gender = GetGenderFromSpeciesAndPersonality(sMenuDataPtr->speciesID, personality);

    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WINDOW_3, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    sMenuDataPtr->normalTotal = 0;
    sMenuDataPtr->evTotal = 0;
    sMenuDataPtr->ivTotal = 0;

    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 18, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuStat);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, STARTING_X - 6, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuActual);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, STARTING_X + SECOND_COLUMN + 4, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuEV);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, STARTING_X + THIRD_COLUMN + 5, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuIV);

    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 24, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 0), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuHP);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 12, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 1), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuAttack);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 12, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuSpAttack);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 10, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuDefense);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 12, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuSpDefense);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 16, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuSpeed);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 16, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuTotal);

    // Print Mon Stats
    for(i = 0; i < 6; i++)
    {
        currentStat = GetMonData(&gPlayerParty[0], statsToPrintActual[i]);
        sMenuDataPtr->normalTotal += currentStat;
        DebugPrintf("Stat: %d", currentStat);
        ConvertIntToDecimalStringN(gStringVar2, currentStat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(WINDOW_2, 1, StatPrintData[statsToPrintActual[i]].x, StatPrintData[statsToPrintActual[i]].y, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);
    }

    for(i = 0; i < 6; i++)
    {
        currentStat = GetMonData(&gPlayerParty[0], statsToPrintEVs[i]);
        sMenuDataPtr->evTotal += currentStat;
        DebugPrintf("Stat: %d", currentStat);
        ConvertIntToDecimalStringN(gStringVar2, currentStat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(WINDOW_2, 1, StatPrintData[statsToPrintEVs[i]].x, StatPrintData[statsToPrintEVs[i]].y, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);
    }

    for(i = 0; i < 6; i++)
    {
        currentStat = GetMonData(&gPlayerParty[0], statsToPrintIVs[i]);
        sMenuDataPtr->ivTotal += currentStat;
        DebugPrintf("Stat: %d", currentStat);
        ConvertIntToDecimalStringN(gStringVar2, currentStat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(WINDOW_2, 1, StatPrintData[statsToPrintIVs[i]].x, StatPrintData[statsToPrintIVs[i]].y, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);
    }

    // Calc Totals
    ConvertIntToDecimalStringN(gStringVar2, sMenuDataPtr->normalTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized4(WINDOW_2, 1, STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    ConvertIntToDecimalStringN(gStringVar2, sMenuDataPtr->evTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized4(WINDOW_2, 1, STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    ConvertIntToDecimalStringN(gStringVar2, sMenuDataPtr->ivTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized4(WINDOW_2, 1, STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);


    // Print ability / nature / name / level / gender

    StringCopy(gStringVar2, gSpeciesNames[sMenuDataPtr->speciesID]);
    AddTextPrinterParameterized4(WINDOW_3, FONT_NARROW, 4, 2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    ConvertIntToDecimalStringN(gStringVar1, level, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar2, sText_MonLevel);
    AddTextPrinterParameterized4(WINDOW_3, FONT_SMALL_NARROW, 4, 18, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, gStringVar2);

    StringCopy(text, gText_MaleSymbol);
    if (gender != MON_GENDERLESS)
    {
        if (gender == MON_FEMALE)
            StringCopy(text, gText_FemaleSymbol);
        else
            StringCopy(text, gText_MaleSymbol);
        AddTextPrinterParameterized4(WINDOW_3, FONT_NORMAL, 41 + 8, 19, 0, 0, sGenderColors[(gender == MON_FEMALE)], TEXT_SKIP_DRAW, text);
    }

    nature = GetNature(&gPlayerParty[0]);
    StringCopy(gStringVar2, gNatureNamePointers[nature]);
    AddTextPrinterParameterized4(WINDOW_3, FONT_SMALL_NARROW, 4, 50, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    StringCopy(gStringVar2, gAbilityNames[gSpeciesInfo[sMenuDataPtr->speciesID].abilities[GetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM)]]);
    AddTextPrinterParameterized4(WINDOW_3, FONT_SMALL_NARROW, 4, 34, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    PutWindowTilemap(WINDOW_3);
    CopyWindowToVram(WINDOW_3, 3);

    PutWindowTilemap(WINDOW_2);
    CopyWindowToVram(WINDOW_2, 3);
}

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    u8 x = 1;
    u8 y = 0;
    
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WINDOW_1, FONT_NORMAL, x, y, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuTitle);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}


struct SpriteCordsStruct {
    u8 x;
    u8 y;
};

static void SelectorCallback(struct Sprite *sprite)
{
    
    struct SpriteCordsStruct spriteCords[6][2] = {
        {{188, 30 + 20}, {220, 30 + 20}},
        {{188, 46 + 20}, {220, 46 + 20}},
        {{188, 62 + 20}, {220, 62 + 20}},
        {{188, 78 + 20}, {220, 78 + 20}},
        {{188, 94 + 20}, {220, 94 + 20}},
        {{188, 110 + 20}, {220, 110 + 20}}, // Thanks Jaizu
    };

    sMenuDataPtr->selectedStat = sMenuDataPtr->selector_x + (sMenuDataPtr->selector_y * 2);

    sprite->x = spriteCords[sMenuDataPtr->selector_y][sMenuDataPtr->selector_x].x;
    sprite->y = spriteCords[sMenuDataPtr->selector_y][sMenuDataPtr->selector_x].y;

    DebugPrintf("%d", sMenuDataPtr->selectedStat);
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static const u16 selectedStatToStatEnum[] = {
        MON_DATA_HP_EV, MON_DATA_HP_IV, MON_DATA_ATK_EV, MON_DATA_ATK_IV, MON_DATA_DEF_EV, MON_DATA_DEF_IV,
        MON_DATA_SPATK_EV, MON_DATA_SPATK_IV, MON_DATA_SPDEF_EV, MON_DATA_SPDEF_IV, MON_DATA_SPEED_EV, MON_DATA_SPEED_IV,
};



/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        sMenuDataPtr->editingStat = GetMonData(&gPlayerParty[0], selectedStatToStatEnum[sMenuDataPtr->selectedStat]);
        StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 3);
        gTasks[taskId].func = Task_MenuEditingStat;
        return;
    }
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }
    if (JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT))
    {
        if(sMenuDataPtr->selector_x == 0)
            sMenuDataPtr->selector_x = 1;
        else
            sMenuDataPtr->selector_x = 0; 
    }
    if (JOY_NEW(DPAD_UP))
    {
        if (sMenuDataPtr->selector_y == 0)
            sMenuDataPtr->selector_y = 5;
        else
            sMenuDataPtr->selector_y--;
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        if (sMenuDataPtr->selector_y == 5)
            sMenuDataPtr->selector_y = 0;
        else
            sMenuDataPtr->selector_y++;
    }

}

static void ChangeAndUpdateStat()
{
    SetMonData(&gPlayerParty[0], selectedStatToStatEnum[sMenuDataPtr->selectedStat], &(sMenuDataPtr->editingStat));
    CalculateMonStats(&gPlayerParty[0]);
    PrintMonStats();
}

static void Task_MenuEditingStat(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_MenuMain;
        StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 0);
        return;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if(sMenuDataPtr->selector_x == 0)
        {
            if(sMenuDataPtr->editingStat == 0)
            {
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 1);
                return;
            }

            sMenuDataPtr->editingStat--;
            if((sMenuDataPtr->editingStat == 0))
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 1);
            else
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 3);
    
            ChangeAndUpdateStat();
        }
        else
        {
            if((sMenuDataPtr->editingStat == 0))
            {
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 1);
                return;
            }

            sMenuDataPtr->editingStat--;
            if((sMenuDataPtr->editingStat == 0))
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 1);
            else
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 3);

            ChangeAndUpdateStat();
        }
        
    }
    if (JOY_NEW(DPAD_RIGHT))
    {
        if(sMenuDataPtr->selector_x == 0)
        {
            if((sMenuDataPtr->editingStat == 255) || (sMenuDataPtr->evTotal == 510))
            {
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);
                return;
            }

            sMenuDataPtr->editingStat++;
            if((sMenuDataPtr->editingStat == 255))
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);
            else
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 3);
    
            ChangeAndUpdateStat();

        }
        else
        {
            if(sMenuDataPtr->editingStat == 31)
            {
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);
                return;
            }

            sMenuDataPtr->editingStat++;
            if((sMenuDataPtr->editingStat == 31))
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);
            else
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 3);
    
            ChangeAndUpdateStat();
        }
        
    }

    if (JOY_NEW(DPAD_UP))
    {
        if(sMenuDataPtr->selector_x == 0)
        {
            if((sMenuDataPtr->editingStat == 255) || (sMenuDataPtr->evTotal == 510))
            {
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);
                return;
            }

            if (510 - sMenuDataPtr->evTotal < 255)
                sMenuDataPtr->editingStat += 510 - sMenuDataPtr->evTotal;
            else
                sMenuDataPtr->editingStat = 255;
    
            StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);    
            ChangeAndUpdateStat();

        }
        else
        {
            if(sMenuDataPtr->editingStat == 31)
            {
                StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);
                return;
            }

            sMenuDataPtr->editingStat = 31;
            StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 2);    
    
            ChangeAndUpdateStat();
        }
        
    }

    if (JOY_NEW(DPAD_DOWN))
    {

        if((sMenuDataPtr->editingStat == 0))
        {
            StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 1);
            return;
        }
        
        sMenuDataPtr->editingStat = 0;
        StartSpriteAnim(&gSprites[sMenuDataPtr->selectorSpriteId], 1);  
        ChangeAndUpdateStat(); 
    }

}


