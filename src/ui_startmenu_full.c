#include "global.h"
#include "ui_startmenu_full.h"
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
#include "battle_pyramid.h"
#include "region_map.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "rtc.h"
#include "pokedex.h"
#include "trainer_card.h"
#include "pokenav.h"
#include "option_menu.h"
#include "link.h"
#include "frontier_pass.h"
#include "start_menu.h"

/*
    Full Screen Start Menu

    This UI was coded by Archie with Graphics by Mudskip.
    Some of the code for the HP Bars was also borrowed from PSFs hack written by Rioluwott

*/

// This config unlocks the ability to switch between 24-hours clock and
// 12-hours clock.
// User need to set this toggle with an unused scripting flag such as
// FLAG_UNUSED_0x020 replacing the 0 to be able to use the clock modes.
#define FLAG_CLOCK_MODE 0

struct StartMenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u16 cursorSpriteId;
    u16 iconBoxSpriteIds[6];
    u16 iconMonSpriteIds[6];
    u16 iconStatusSpriteIds[6];
    u16 selector_x;
    u16 selector_y;
    u16 selectedMenu;
    u16 greyMenuBoxIds[3];
};

enum WindowIds
{
    WINDOW_HP_BARS,
    WINDOW_TOP_BAR,
    WINDOW_BOTTOM_BAR,
};

enum StartMenuBoxes
{
    START_MENU_POKEDEX,
    START_MENU_PARTY,
    START_MENU_BAG,
    START_MENU_CARD,
    START_MENU_MAP,
    START_MENU_OPTIONS,
};

//==========EWRAM==========//
static EWRAM_DATA struct StartMenuResources *sStartMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 gSelectedMenu = 0; // holds the position of the menu so that it persists in memory, 
                                        // when you go into something like the bag and leave your cursor is still on the bag

//==========STATIC=DEFINES==========//
static void StartMenuFull_RunSetup(void);
static bool8 StartMenuFull_DoGfxSetup(void);
static bool8 StartMenuFull_InitBgs(void);
static void StartMenuFull_FadeAndBail(void);
static bool8 StartMenuFull_LoadGraphics(void);
static void StartMenuFull_InitWindows(void);
static void Task_StartMenuFullWaitFadeIn(u8 taskId);
static void Task_StartMenuFullMain(u8 taskId);
static u32 GetHPEggCyclePercent(u32 partyIndex);
static void PrintMapNameAndTime(void);
static void CursorCallback(struct Sprite *sprite);

//==========CONST=DATA==========//
static const struct BgTemplate sStartMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows used for text loading and hp bar blitting
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    },
    {
        .bg = 1,    // this bg loads the main tilemap with the header, footer, and menu options
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .priority = 1
    },
    {
        .bg = 2,    // this bg loads the scrolling bg
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .priority = 2
    }
};

static const struct WindowTemplate sStartMenuWindowTemplates[] =
{
    [WINDOW_HP_BARS] = // Window ID the HP bars are blitted to
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 3,    // position from top (per 8 pixels)
        .width = 9,        // width (per 8 pixels)
        .height = 15,        // height (per 8 pixels)
        .paletteNum = 2,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },

    [WINDOW_TOP_BAR] = //Window ID for the Time and Map name
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 0,   // palette index to use for text
        .baseBlock = 1 + (9 * 15),     // tile start in VRAM
    },

    [WINDOW_BOTTOM_BAR] = // Window ID for the save confirmation box
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 18,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 0,   // palette index to use for text
        .baseBlock = 1 + (9 * 15) + (30 * 2),     // tile start in VRAM
    },
};


//
//  Graphics Pointers to Tilemaps, Tilesets, Spritesheets, Palettes
//

// Main Background
static const u32 sStartMenuTiles[] = INCBIN_U32("graphics/ui_startmenu_full/menu_tiles.4bpp.lz");
static const u16 sStartMenuPalette[] = INCBIN_U16("graphics/ui_startmenu_full/menu.gbapal");

//#if (FLAG_CLOCK_MODE != 0)
//static const u32 sStartMenuTilemap[] = INCBIN_U32("graphics/ui_startmenu_full/menu_tilemap_alt.bin.lz");
//#else
static const u32 sStartMenuTilemap[] = INCBIN_U32("graphics/ui_startmenu_full/menu_tilemap.bin.lz");
//#endif

// Alternate Main Background for Female Player
static const u32 sStartMenuTilesAlt[] = INCBIN_U32("graphics/ui_startmenu_full/menu_tiles_alt.4bpp.lz");
static const u16 sStartMenuPaletteAlt[] = INCBIN_U16("graphics/ui_startmenu_full/menu_alt.gbapal");

// Scrolling Background
static const u32 sScrollBgTiles[] = INCBIN_U32("graphics/ui_startmenu_full/scroll_tiles.4bpp.lz");
static const u32 sScrollBgTilemap[] = INCBIN_U32("graphics/ui_startmenu_full/scroll_tilemap.bin.lz");
static const u16 sScrollBgPalette[] = INCBIN_U16("graphics/ui_startmenu_full/scroll_tiles.gbapal");

// Cursor and IconBox
static const u16 sCursor_Pal[] = INCBIN_U16("graphics/ui_startmenu_full/cursor.gbapal");
static const u32 sCursor_Gfx[] = INCBIN_U32("graphics/ui_startmenu_full/cursor.4bpp.lz");
static const u16 sCursor_PalAlt[] = INCBIN_U16("graphics/ui_startmenu_full/cursor_alt.gbapal");

static const u16 sIconBox_Pal[] = INCBIN_U16("graphics/ui_startmenu_full/icon_box.gbapal");
static const u32 sIconBox_Gfx[] = INCBIN_U32("graphics/ui_startmenu_full/icon_box.4bpp.lz");

//HP Bar
static const u8 sHPBar_100_Percent_Gfx[]  = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_100_Percent_Gfx.4bpp");
static const u8 sHPBar_90_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_90_Percent_Gfx.4bpp");
static const u8 sHPBar_80_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_80_Percent_Gfx.4bpp");
static const u8 sHPBar_70_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_70_Percent_Gfx.4bpp");
static const u8 sHPBar_60_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_60_Percent_Gfx.4bpp");
static const u8 sHPBar_50_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_50_Percent_Gfx.4bpp");
static const u8 sHPBar_40_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_40_Percent_Gfx.4bpp");
static const u8 sHPBar_30_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_30_Percent_Gfx.4bpp");
static const u8 sHPBar_20_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_20_Percent_Gfx.4bpp");
static const u8 sHPBar_10_Percent_Gfx[]   = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_10_Percent_Gfx.4bpp");
static const u8 sHPBar_0_Percent_Gfx[]    = INCBIN_U8("graphics/ui_startmenu_full/sHPBar_0_Percent_Gfx.4bpp");
static const u16 sHP_Pal[] = INCBIN_U16("graphics/ui_startmenu_full/hpbar_pal.gbapal");
static const u16 sHP_PalAlt[] = INCBIN_U16("graphics/ui_startmenu_full/hpbar_pal_alt.gbapal");

// greyed buttons
static const u32 sGreyMenuButtonMap_Gfx[] = INCBIN_U32("graphics/ui_startmenu_full/map_dark_sprite.4bpp.lz");
static const u32 sGreyMenuButtonDex_Gfx[] = INCBIN_U32("graphics/ui_startmenu_full/dex_dark_sprite.4bpp.lz");
static const u32 sGreyMenuButtonParty_Gfx[] = INCBIN_U32("graphics/ui_startmenu_full/party_dark_sprite.4bpp.lz");
static const u16 sGreyMenuButton_Pal[] = INCBIN_U16("graphics/ui_startmenu_full/menu_dark.gbapal");


//
//  Sprite Data for Cursor, IconBox, GreyedBoxes, and Statuses
//
#define TAG_CURSOR 30004
#define TAG_ICON_BOX 30006
#define TAG_HPBAR   30008
#define TAG_STATUS_ICONS 30009

static const struct OamData sOamData_Cursor =
{
    .size = SPRITE_SIZE(64x32),
    .shape = SPRITE_SHAPE(64x32),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_Cursor =
{
    .data = sCursor_Gfx,
    .size = 64*32*4/2,
    .tag = TAG_CURSOR,
};

static const struct SpritePalette sSpritePal_Cursor =
{
    .data = sCursor_Pal,
    .tag = TAG_CURSOR
};

static const union AnimCmd sSpriteAnim_Cursor0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Cursor[] =
{
    sSpriteAnim_Cursor0,
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &sOamData_Cursor,
    .anims = sSpriteAnimTable_Cursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CursorCallback
};


static const struct OamData sOamData_IconBox =
{
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_IconBox =
{
    .data = sIconBox_Gfx,
    .size = 32*32*4/2,
    .tag = TAG_ICON_BOX,
};

static const struct SpritePalette sSpritePal_IconBox =
{
    .data = sIconBox_Pal,
    .tag = TAG_ICON_BOX
};

static const union AnimCmd sSpriteAnim_IconBox0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_IconBox[] =
{
    sSpriteAnim_IconBox0,
};

static const struct SpriteTemplate sSpriteTemplate_IconBox =
{
    .tileTag = TAG_ICON_BOX,
    .paletteTag = TAG_ICON_BOX,
    .oam = &sOamData_IconBox,
    .anims = sSpriteAnimTable_IconBox,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_StatusPoison[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusParalyzed[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusSleep[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusFrozen[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusBurn[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusPokerus[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatusFaint[] =
{
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Blank[] =
{
    ANIMCMD_FRAME(28, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteTemplate_StatusCondition[] =
{
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_Blank
};

static const struct CompressedSpriteSheet sSpriteSheet_StatusIcons =
{
    gStatusGfx_Icons, 0x400, TAG_STATUS_ICONS
};

static const struct CompressedSpritePalette sSpritePalette_StatusIcons =
{
    gStatusPal_Icons, TAG_STATUS_ICONS
};

static const struct SpriteTemplate sSpriteTemplate_StatusIcons =
{
    .tileTag = TAG_STATUS_ICONS,
    .paletteTag = TAG_STATUS_ICONS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteTemplate_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

#define TAG_GREY_ICON 20001
#define TAG_GREY_ICON_MAP 20003
#define TAG_GREY_ICON_DEX 20005
#define TAG_GREY_ICON_PARTY 20007

static const struct OamData sOamData_GreyMenuButton =
{
    .size = SPRITE_SIZE(64x32),
    .shape = SPRITE_SHAPE(64x32),
    .priority = 1,
};

static const struct CompressedSpriteSheet sSpriteSheet_GreyMenuButtonMap =
{
    .data = sGreyMenuButtonMap_Gfx,
    .size = 64*32*4/2,
    .tag = TAG_GREY_ICON_MAP,
};

static const struct CompressedSpriteSheet sSpriteSheet_GreyMenuButtonParty =
{
    .data = sGreyMenuButtonParty_Gfx,
    .size = 64*32*4/2,
    .tag = TAG_GREY_ICON_PARTY,
};

static const struct CompressedSpriteSheet sSpriteSheet_GreyMenuButtonDex =
{
    .data = sGreyMenuButtonDex_Gfx,
    .size = 64*32*4/2,
    .tag = TAG_GREY_ICON_DEX,
};

static const struct SpritePalette sSpritePal_GreyMenuButton =
{
    .data = sGreyMenuButton_Pal,
    .tag = TAG_GREY_ICON
};

static const union AnimCmd sSpriteAnim_GreyMenuButton0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_GreyMenuButton[] =
{
    sSpriteAnim_GreyMenuButton0,
};

static const struct SpriteTemplate sSpriteTemplate_GreyMenuButtonMap =
{
    .tileTag = TAG_GREY_ICON_MAP,
    .paletteTag = TAG_GREY_ICON,
    .oam = &sOamData_GreyMenuButton,
    .anims = sSpriteAnimTable_GreyMenuButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_GreyMenuButtonDex =
{
    .tileTag = TAG_GREY_ICON_DEX,
    .paletteTag = TAG_GREY_ICON,
    .oam = &sOamData_GreyMenuButton,
    .anims = sSpriteAnimTable_GreyMenuButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_GreyMenuButtonParty =
{
    .tileTag = TAG_GREY_ICON_PARTY,
    .paletteTag = TAG_GREY_ICON,
    .oam = &sOamData_GreyMenuButton,
    .anims = sSpriteAnimTable_GreyMenuButton,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};


//
//  Begin Sprite Loading Functions
//

//
//      Cursor Creation and Callback 
//
#define CURSOR_LEFT_COL_X 128
#define CURSOR_RIGHT_COL_X 128 + 64 + 8
#define CURSOR_TOP_ROW_Y 40
#define CURSOR_MID_ROW_Y 40 + 40
#define CURSOR_BTM_ROW_Y 40 + 80

static void CreateCursor()
{
    if (sStartMenuDataPtr->cursorSpriteId == SPRITE_NONE)
        sStartMenuDataPtr->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor, CURSOR_LEFT_COL_X, CURSOR_TOP_ROW_Y, 0);

    CursorCallback(&gSprites[sStartMenuDataPtr->cursorSpriteId]);
    
    gSprites[sStartMenuDataPtr->cursorSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sStartMenuDataPtr->cursorSpriteId], 0);
    return;
}

static void DestroyCursor()
{
    if (sStartMenuDataPtr->cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sStartMenuDataPtr->cursorSpriteId]);
    sStartMenuDataPtr->cursorSpriteId = SPRITE_NONE;
}

struct SpriteCordsStruct {
    u8 x;
    u8 y;
};

static void CursorCallback(struct Sprite *sprite) // Sprite callback for the cursor that updates the position every frame when the input control code updates
{
    struct SpriteCordsStruct spriteCords[3][2] = {
        {{CURSOR_LEFT_COL_X, CURSOR_TOP_ROW_Y}, {CURSOR_RIGHT_COL_X, CURSOR_TOP_ROW_Y}},
        {{CURSOR_LEFT_COL_X, CURSOR_MID_ROW_Y}, {CURSOR_RIGHT_COL_X, CURSOR_MID_ROW_Y}},
        {{CURSOR_LEFT_COL_X, CURSOR_BTM_ROW_Y}, {CURSOR_RIGHT_COL_X, CURSOR_BTM_ROW_Y}},
    };

    gSelectedMenu = sStartMenuDataPtr->selector_x + (sStartMenuDataPtr->selector_y * 2);

    sprite->x = spriteCords[sStartMenuDataPtr->selector_y][sStartMenuDataPtr->selector_x].x;
    sprite->y = spriteCords[sStartMenuDataPtr->selector_y][sStartMenuDataPtr->selector_x].y;

    DebugPrintf("%d", sStartMenuDataPtr->selectedStat);
}

static void InitCursorInPlace()
{
    if(gSelectedMenu % 2)
        sStartMenuDataPtr->selector_x = 1;
    else
        sStartMenuDataPtr->selector_x = 0;

    if(gSelectedMenu <= 1)
        sStartMenuDataPtr->selector_y = 0;
    else if (gSelectedMenu > 1 && gSelectedMenu <= 3)
        sStartMenuDataPtr->selector_y = 1;
    else
        sStartMenuDataPtr->selector_y = 2;
}


//
//  Create Icon Box Sprites Behin the Icons
//
#define ICON_BOX_1_START_X          24
#define ICON_BOX_1_START_Y          40
#define ICON_BOX_X_DIFFERENCE       40
#define ICON_BOX_Y_DIFFERENCE       40
static void CreateIconBox()
{
    u8 i = 0;

    sStartMenuDataPtr->iconBoxSpriteIds[0] = CreateSprite(&sSpriteTemplate_IconBox, ICON_BOX_1_START_X, ICON_BOX_1_START_Y, 2);
    sStartMenuDataPtr->iconBoxSpriteIds[1] = CreateSprite(&sSpriteTemplate_IconBox, ICON_BOX_1_START_X + ICON_BOX_X_DIFFERENCE, ICON_BOX_1_START_Y, 2);

    sStartMenuDataPtr->iconBoxSpriteIds[2] = CreateSprite(&sSpriteTemplate_IconBox, ICON_BOX_1_START_X, ICON_BOX_1_START_Y + (ICON_BOX_X_DIFFERENCE * 1), 2);
    sStartMenuDataPtr->iconBoxSpriteIds[3] = CreateSprite(&sSpriteTemplate_IconBox, ICON_BOX_1_START_X + ICON_BOX_X_DIFFERENCE, ICON_BOX_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 1), 2);

    sStartMenuDataPtr->iconBoxSpriteIds[4] = CreateSprite(&sSpriteTemplate_IconBox, ICON_BOX_1_START_X, ICON_BOX_1_START_Y + (ICON_BOX_X_DIFFERENCE * 2), 2);
    sStartMenuDataPtr->iconBoxSpriteIds[5] = CreateSprite(&sSpriteTemplate_IconBox, ICON_BOX_1_START_X + ICON_BOX_X_DIFFERENCE, ICON_BOX_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 2), 2);

    for(i = 0; i < 6; i++)
    {
        gSprites[sStartMenuDataPtr->iconBoxSpriteIds[i]].invisible = FALSE;
        gSprites[sStartMenuDataPtr->iconBoxSpriteIds[i]].oam.objMode = ST_OAM_OBJ_BLEND;
        StartSpriteAnim(&gSprites[sStartMenuDataPtr->iconBoxSpriteIds[i]], 0);
        gSprites[sStartMenuDataPtr->iconBoxSpriteIds[i]].oam.priority = 2;
    }

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 11));

    return;
}

static void DestroyIconBoxs()
{
    u8 i = 0;
    for(i = 0; i < 6; i++)
    {
        DestroySprite(&gSprites[sStartMenuDataPtr->iconBoxSpriteIds[i]]);
        sStartMenuDataPtr->iconBoxSpriteIds[i] = SPRITE_NONE;
    }
}

static void CreatePartyMonIcons()
{
    u8 i = 0;
    s16 x = ICON_BOX_1_START_X;
    s16 y = ICON_BOX_1_START_Y;
    struct Pokemon *mon;
    LoadMonIconPalettes();
    for(i = 0; i < gPlayerPartyCount; i++)
    {   
        switch (i) // choose position for each icon
        {
            case 0:
                x = ICON_BOX_1_START_X;
                y = ICON_BOX_1_START_Y;
                break;
            case 1:
                x = ICON_BOX_1_START_X + ICON_BOX_X_DIFFERENCE;
                y = ICON_BOX_1_START_Y;
                break;
            case 2:
                x = ICON_BOX_1_START_X;
                y = ICON_BOX_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 1);
                break;
            case 3:
                x = ICON_BOX_1_START_X + ICON_BOX_X_DIFFERENCE;
                y = ICON_BOX_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 1);
                break;
            case 4:
                x = ICON_BOX_1_START_X;
                y = ICON_BOX_1_START_Y + (ICON_BOX_X_DIFFERENCE * 2);
                break;
            case 5:
                x = ICON_BOX_1_START_X + ICON_BOX_X_DIFFERENCE;
                y = ICON_BOX_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 2);
                break;
        }

#ifdef POKEMON_EXPANSION
            sStartMenuDataPtr->iconMonSpriteIds[i] = CreateMonIcon(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG), SpriteCB_MonIcon, x, y, 0, GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY));
#else
            sStartMenuDataPtr->iconMonSpriteIds[i] = CreateMonIcon(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG), SpriteCB_MonIcon, x, y, 0, GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY), FALSE);
#endif

        gSprites[sStartMenuDataPtr->iconMonSpriteIds[i]].oam.priority = 0;

        if (GetHPEggCyclePercent(i) == 0)
        {
            gSprites[sStartMenuDataPtr->iconMonSpriteIds[i]].callback = SpriteCallbackDummy;
        }

    }
}

static void DestroyMonIcons()
{
    u8 i = 0;
    for(i = 0; i < 6; i++)
    {
        DestroySprite(&gSprites[sStartMenuDataPtr->iconMonSpriteIds[i]]);
        sStartMenuDataPtr->iconMonSpriteIds[i] = SPRITE_NONE;
    }
}


//
// Begin Health Bar Functions Credits: Rioluwott in PSFs hack
//
static const u8 *GetBarGfx(u32 percent)
{
    u32 modifiedPercent = percent / 10;

    const u8 *sHPBar_Fill_Gfx[] = {
        sHPBar_0_Percent_Gfx,
        sHPBar_10_Percent_Gfx,
        sHPBar_20_Percent_Gfx,
        sHPBar_30_Percent_Gfx,
        sHPBar_40_Percent_Gfx,
        sHPBar_50_Percent_Gfx,
        sHPBar_60_Percent_Gfx,
        sHPBar_70_Percent_Gfx,
        sHPBar_80_Percent_Gfx,
        sHPBar_90_Percent_Gfx,
        sHPBar_100_Percent_Gfx,
    };

    if (percent == 0)
        return sHPBar_Fill_Gfx[percent];

    if (modifiedPercent == 0)
        return sHPBar_Fill_Gfx[1];

    return sHPBar_Fill_Gfx[modifiedPercent];
}

static bool32 IsMonNotEmpty(u32 partyIndex)
{
    return (GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE);
}

static u32 GetHPEggCyclePercent(u32 partyIndex)
{
    struct Pokemon *mon = &gPlayerParty[partyIndex];
    if (!GetMonData(mon, MON_DATA_IS_EGG))
        return ((GetMonData(mon, MON_DATA_HP)) * 100 / (GetMonData(mon,MON_DATA_MAX_HP)));
    else
        return ((GetMonData(mon, MON_DATA_FRIENDSHIP)) * 100 / (gSpeciesInfo[GetMonData(mon,MON_DATA_SPECIES)].eggCycles));
}

#define HP_BAR_X_START  0
#define HP_BAR_Y_START  30

static void StartMenu_DisplayHP(void)
{
    u32 i;
    u32 y = 1;
    s32 x = -4;

    FillWindowPixelBuffer(WINDOW_HP_BARS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    for(i = 0; i < PARTY_SIZE; i++) // choose position for each hp bar
    {
        switch (i)
        {   
            case 0:
                x = HP_BAR_X_START;
                y = HP_BAR_Y_START;
                break;
            case 1:
                x = HP_BAR_X_START + ICON_BOX_X_DIFFERENCE;
                y = HP_BAR_Y_START;
                break;
            case 2:
                x = HP_BAR_X_START;
                y = HP_BAR_Y_START + (ICON_BOX_Y_DIFFERENCE * 1);
                break;
            case 3:
                x = HP_BAR_X_START + ICON_BOX_X_DIFFERENCE;
                y = HP_BAR_Y_START + (ICON_BOX_Y_DIFFERENCE * 1);
                break;
            case 4:
                x = HP_BAR_X_START;
                y = HP_BAR_Y_START + (ICON_BOX_X_DIFFERENCE * 2);
                break;
            case 5:
                x = HP_BAR_X_START + ICON_BOX_X_DIFFERENCE;
                y = HP_BAR_Y_START + (ICON_BOX_Y_DIFFERENCE * 2);
                break;
        }

        if(!IsMonNotEmpty(i))
            continue;

        BlitBitmapToWindow(WINDOW_HP_BARS, GetBarGfx(GetHPEggCyclePercent(i)), x, y, 32, 8);
    }

    CopyWindowToVram(WINDOW_HP_BARS, COPYWIN_GFX);
}


//
//  Create Greyed Out Versions of the Icons When You Don't Have Sys Flags Set
//
static void CreateGreyedMenuBoxes()
{
    if(!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        if (sStartMenuDataPtr->greyMenuBoxIds[0] == SPRITE_NONE)
            sStartMenuDataPtr->greyMenuBoxIds[0] = CreateSprite(&sSpriteTemplate_GreyMenuButtonDex, CURSOR_LEFT_COL_X, CURSOR_TOP_ROW_Y, 1);
        gSprites[sStartMenuDataPtr->greyMenuBoxIds[0]].invisible = FALSE;
        StartSpriteAnim(&gSprites[sStartMenuDataPtr->greyMenuBoxIds[0]], 0);
    }
    
    if(!FlagGet(FLAG_SYS_POKEMON_GET))
    {
        if (sStartMenuDataPtr->greyMenuBoxIds[1] == SPRITE_NONE)
            sStartMenuDataPtr->greyMenuBoxIds[1] = CreateSprite(&sSpriteTemplate_GreyMenuButtonParty, CURSOR_RIGHT_COL_X, CURSOR_TOP_ROW_Y, 1);
        gSprites[sStartMenuDataPtr->greyMenuBoxIds[1]].invisible = FALSE;
        StartSpriteAnim(&gSprites[sStartMenuDataPtr->greyMenuBoxIds[1]], 0);
    }

    if(!FlagGet(FLAG_SYS_POKENAV_GET))
    {
        if (sStartMenuDataPtr->greyMenuBoxIds[2] == SPRITE_NONE)
            sStartMenuDataPtr->greyMenuBoxIds[2] = CreateSprite(&sSpriteTemplate_GreyMenuButtonMap, CURSOR_LEFT_COL_X, CURSOR_BTM_ROW_Y, 1);
        gSprites[sStartMenuDataPtr->greyMenuBoxIds[2]].invisible = FALSE;
        StartSpriteAnim(&gSprites[sStartMenuDataPtr->greyMenuBoxIds[2]], 0);
    }
    
    return;
}

static void DestroyGreyMenuBoxes()
{
    u8 i = 0;
    for(i = 0; i < 3; i++)
    {
        DestroySprite(&gSprites[sStartMenuDataPtr->greyMenuBoxIds[i]]);
        sStartMenuDataPtr->greyMenuBoxIds[i] = SPRITE_NONE;
    }
}


//
//  Begin Status Code Ripped From Vanilla
//
#define AILMENT_NONE  0
#define AILMENT_PSN   1
#define AILMENT_PRZ   2
#define AILMENT_SLP   3
#define AILMENT_FRZ   4
#define AILMENT_BRN   5
#define AILMENT_PKRS  6
#define AILMENT_FNT   7

#define ICON_STATUS_1_START_X  24
#define ICON_STATUS_1_START_Y  29

static void CreatePartyMonStatuses()
{
    u8 i = 0;
    s16 x = ICON_STATUS_1_START_X;
    s16 y = ICON_STATUS_1_START_Y;
    u8 status;

    for(i = 0; i < gPlayerPartyCount; i++)
    {   
        switch (i)
        {
            case 0:
                x = ICON_STATUS_1_START_X;
                y = ICON_STATUS_1_START_Y;
                break;
            case 1:
                x = ICON_STATUS_1_START_X + ICON_BOX_X_DIFFERENCE;
                y = ICON_STATUS_1_START_Y;
                break;
            case 2:
                x = ICON_STATUS_1_START_X;
                y = ICON_STATUS_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 1);
                break;
            case 3:
                x = ICON_STATUS_1_START_X + ICON_BOX_X_DIFFERENCE;
                y = ICON_STATUS_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 1);
                break;
            case 4:
                x = ICON_STATUS_1_START_X;
                y = ICON_STATUS_1_START_Y + (ICON_BOX_X_DIFFERENCE * 2);
                break;
            case 5:
                x = ICON_STATUS_1_START_X + ICON_BOX_X_DIFFERENCE;
                y = ICON_STATUS_1_START_Y + (ICON_BOX_Y_DIFFERENCE * 2);
                break;
        }

        sStartMenuDataPtr->iconStatusSpriteIds[i] = CreateSprite(&sSpriteTemplate_StatusIcons, x, y, 0);

        status = GetMonAilment(&gPlayerParty[i]);
        switch (status)
        {
            case AILMENT_NONE:
            case AILMENT_PKRS:
                gSprites[sStartMenuDataPtr->iconStatusSpriteIds[i]].invisible = TRUE;
                break;
            default:
                StartSpriteAnim(&gSprites[sStartMenuDataPtr->iconStatusSpriteIds[i]], status - 1);
                gSprites[sStartMenuDataPtr->iconStatusSpriteIds[i]].invisible = FALSE;
                break;
        }
        gSprites[sStartMenuDataPtr->iconStatusSpriteIds[i]].oam.priority = 0;
    }
}

static void DestroyStatusSprites()
{
    u8 i = 0;
    for(i = 0; i < 6; i++)
    {
        DestroySprite(&gSprites[sStartMenuDataPtr->iconStatusSpriteIds[i]]);
        sStartMenuDataPtr->iconStatusSpriteIds[i] = SPRITE_NONE;
    }
}


//==========FUNCTIONS==========//
// These next few functions are from the Ghoulslash UI Shell, they are the basic functions to init a brand new UI
void Task_OpenStartMenuFullScreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        StartMenuFull_Init(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void StartMenuFull_Init(MainCallback callback)
{
    u32 i = 0;
    if ((sStartMenuDataPtr = AllocZeroed(sizeof(struct StartMenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    // Make Sure Sprites are Empty on Reload
    sStartMenuDataPtr->gfxLoadState = 0;
    sStartMenuDataPtr->savedCallback = callback;
    sStartMenuDataPtr->cursorSpriteId = SPRITE_NONE;

    for(i= 0; i < 6; i++)
    {
        sStartMenuDataPtr->iconBoxSpriteIds[i] = SPRITE_NONE;
        sStartMenuDataPtr->iconMonSpriteIds[i] = SPRITE_NONE;
    }
    for(i= 0; i < 3; i++)
    {
        sStartMenuDataPtr->greyMenuBoxIds[i] = SPRITE_NONE;
    }
    InitCursorInPlace();
    
    SetMainCallback2(StartMenuFull_RunSetup);
}

static void StartMenuFull_RunSetup(void)
{
    while (1)
    {
        if (StartMenuFull_DoGfxSetup() == TRUE)
            break;
    }
}

static void StartMenuFull_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void StartMenuFull_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgY(2, 128, BG_COORD_SUB); // controls the background scrolling
}

static bool8 StartMenuFull_DoGfxSetup(void) // base UI loader from Ghouls UI Shell branch, does the important hardware stuff to setup a UI
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        ResetVramOamAndBgCntRegs();
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
        if (StartMenuFull_InitBgs())
        {
            sStartMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            StartMenuFull_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (StartMenuFull_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        StartMenuFull_InitWindows();
        gMain.state++;
        break;
    case 5:
        PrintMapNameAndTime(); // print all sprites
        CreateGreyedMenuBoxes();
        CreateIconBox();
        CreateCursor();
        CreatePartyMonIcons();
        StartMenu_DisplayHP();
        CreatePartyMonStatuses();
        gMain.state++;
        break;
    case 6:
        CreateTask(Task_StartMenuFullWaitFadeIn, 0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(StartMenuFull_VBlankCB);
        SetMainCallback2(StartMenuFull_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void StartMenuFull_FreeResources(void) // Clear Everything if Leaving
{
    try_free(sStartMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    try_free(sBg2TilemapBuffer);
    DestroyCursor();
    DestroyIconBoxs();
    DestroyMonIcons();
    DestroyStatusSprites();
    DestroyGreyMenuBoxes();
    FreeAllWindowBuffers();    
}

static void Task_StartMenuFullWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sStartMenuDataPtr->savedCallback);
        StartMenuFull_FreeResources();
        DestroyTask(taskId);
    }
}

static void StartMenuFull_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_StartMenuFullWaitFadeAndBail, 0);
    SetVBlankCallback(StartMenuFull_VBlankCB);
    SetMainCallback2(StartMenuFull_MainCB);
}

static void Task_StartMenuFullWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_StartMenuFullMain;
}

static void Task_StartMenuFullTurnOff(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sStartMenuDataPtr->savedCallback);
        StartMenuFull_FreeResources();
        DestroyTask(taskId);
    }
}


static bool8 StartMenuFull_InitBgs(void) // This function sets the bg tilemap buffers for each bg and initializes them, shows them, and turns sprites on
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    memset(sBg1TilemapBuffer, 0, 0x800);

    sBg2TilemapBuffer = Alloc(0x800);
    if (sBg2TilemapBuffer == NULL)
        return FALSE;
    memset(sBg2TilemapBuffer, 0, 0x800);
    
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sStartMenuBgTemplates, NELEMS(sStartMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 StartMenuFull_LoadGraphics(void) // Load the Tilesets, Tilemaps, Spritesheets, and Palettes for Everything
{
    switch (sStartMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        if (gSaveBlock2Ptr->playerGender == FEMALE)
        {
            DecompressAndCopyTileDataToVram(1, sStartMenuTilesAlt, 0, 0, 0);
        }
        else
        {
            DecompressAndCopyTileDataToVram(1, sStartMenuTiles, 0, 0, 0);
        }
        DecompressAndCopyTileDataToVram(2, sScrollBgTiles, 0, 0, 0);
        sStartMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sStartMenuTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sScrollBgTilemap, sBg2TilemapBuffer);
            sStartMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
    {
        struct SpritePalette cursorPal = {sSpritePal_Cursor.data, sSpritePal_Cursor.tag};
        if (gSaveBlock2Ptr->playerGender == FEMALE)
        {
            LoadPalette(sStartMenuPaletteAlt, 0, 16);
            LoadPalette(sHP_PalAlt, 32, 16);
            cursorPal.data = sCursor_PalAlt;
        }
        else
        {
            LoadPalette(sStartMenuPalette, 0, 16);
            LoadPalette(sHP_Pal, 32, 16);
        }
        LoadPalette(sScrollBgPalette, 16, 16);

        LoadCompressedSpriteSheet(&sSpriteSheet_IconBox);
        LoadSpritePalette(&sSpritePal_IconBox);
        LoadCompressedSpriteSheet(&sSpriteSheet_Cursor);
        LoadSpritePalette(&cursorPal);
        LoadCompressedSpriteSheet(&sSpriteSheet_StatusIcons);
        LoadCompressedSpritePalette(&sSpritePalette_StatusIcons);

        LoadCompressedSpriteSheet(&sSpriteSheet_GreyMenuButtonMap);
        LoadCompressedSpriteSheet(&sSpriteSheet_GreyMenuButtonDex);
        LoadCompressedSpriteSheet(&sSpriteSheet_GreyMenuButtonParty);
        LoadSpritePalette(&sSpritePal_GreyMenuButton);
        sStartMenuDataPtr->gfxLoadState++;
        break;
    }
    default:
        sStartMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void StartMenuFull_InitWindows(void)
{
    InitWindows(sStartMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_HP_BARS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_HP_BARS);
    CopyWindowToVram(WINDOW_HP_BARS, COPYWIN_FULL);

    FillWindowPixelBuffer(WINDOW_TOP_BAR, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_TOP_BAR);
    CopyWindowToVram(WINDOW_TOP_BAR, COPYWIN_FULL);

    FillWindowPixelBuffer(WINDOW_BOTTOM_BAR, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_BOTTOM_BAR);
    CopyWindowToVram(WINDOW_BOTTOM_BAR, COPYWIN_FULL);
    
    ScheduleBgCopyTilemapToVram(2);
}


//
//  Confirm Save Dialogue Printer
//
static const u8 sText_ConfirmSave[] = _("Confirm Save and Return to Overworld?");
static const u8 sA_ButtonGfx[]         = INCBIN_U8("graphics/ui_startmenu_full/a_button.4bpp");
static void PrintSaveConfirmToWindow()
{
    const u8 *str = sText_ConfirmSave;
    u8 sConfirmTextColors[] = {TEXT_COLOR_TRANSPARENT, 2, 3};
    u8 x = 24;
    u8 y = 0;
    
    FillWindowPixelBuffer(WINDOW_BOTTOM_BAR, PIXEL_FILL(5));
    BlitBitmapToWindow(WINDOW_BOTTOM_BAR, sA_ButtonGfx, 12, 5, 8, 8);
    AddTextPrinterParameterized4(WINDOW_BOTTOM_BAR, 1, x, y, 0, 0, sConfirmTextColors, 0xFF, str);
    PutWindowTilemap(WINDOW_BOTTOM_BAR);
    CopyWindowToVram(WINDOW_BOTTOM_BAR, COPYWIN_FULL);
}


//
//  Print Time, Location, Day of Week and Time Indicator
//
static const u8 sText_Sunday[] = _("Sun.");
static const u8 sText_Monday[] = _("Mon.");
static const u8 sText_Tuesday[] = _("Tues.");
static const u8 sText_Wednesday[] = _("Wed.");
static const u8 sText_Thursday[] = _("Thurs.");
static const u8 sText_Friday[] = _("Fri.");
static const u8 sText_Saturday[] = _("Sat.");
static const u8 * const sDayOfWeekStrings[7] =
{
    sText_Sunday,
    sText_Monday,
    sText_Tuesday,
    sText_Wednesday,
    sText_Thursday,
    sText_Friday,
    sText_Saturday,
};

static const u8 sText_AM[] = _("AM");
static const u8 sText_PM[] = _("PM");

static void PrintMapNameAndTime(void) //this code is ripped froom different parts of pokeemerald and is a mess because of that, but it all works
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8 *str, *suffix = NULL;
    u8 sTimeTextColors[] = {TEXT_COLOR_TRANSPARENT, 2, 3};

    u16 hours;
    u16 minutes;
    u16 dayOfWeek;
    s32 width;
    u32 y, totalWidth;

    FillWindowPixelBuffer(WINDOW_TOP_BAR, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    withoutPrefixPtr = &(mapDisplayHeader[3]);
    GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    x = GetStringRightAlignXOffset(FONT_NARROW, withoutPrefixPtr, 80);
    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    AddTextPrinterParameterized(WINDOW_TOP_BAR, FONT_NARROW, mapDisplayHeader, x + 152, 1, TEXT_SKIP_DRAW, NULL); // Print Map Name

    RtcCalcLocalTime();

    hours = gLocalTime.hours;

#if (FLAG_CLOCK_MODE != 0)
    if (FlagGet(FLAG_CLOCK_MODE)) // true: 12-hours, false: 24-hours
    {
        if (gLocalTime.hours < 12)
        {
            hours = (gLocalTime.hours == 0) ? 12 : gLocalTime.hours;
            suffix = sText_AM;
        }
        else if (gLocalTime.hours == 12)
        {
            hours = 12;
            if (suffix == sText_AM)
                suffix = sText_PM;
        }
        else
        {
            hours = gLocalTime.hours - 12;
            suffix = sText_PM;
        }
    }
#endif

    minutes = gLocalTime.minutes;
    dayOfWeek = gLocalTime.days % 7;
    if (hours > 999)
        hours = 999;
    if (minutes > 59)
        minutes = 59;
    width = GetStringWidth(FONT_NORMAL, gText_Colon2, 0);
    x = 64;
    y = 1;

    if(dayOfWeek == 2) // adjust x position if dayofweek Thurs/Tues because the words are longer
        x += 8;
    if(dayOfWeek == 4)
        x += 12;

    totalWidth = width + 30;
    x -= totalWidth;

    str = sDayOfWeekStrings[dayOfWeek];

    AddTextPrinterParameterized3(WINDOW_TOP_BAR, FONT_NORMAL, 10, y, sTimeTextColors, TEXT_SKIP_DRAW, str); //print dayof week
    ConvertIntToDecimalStringN(gStringVar4, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized3(WINDOW_TOP_BAR, FONT_NORMAL, x, y, sTimeTextColors, TEXT_SKIP_DRAW, gStringVar4); //these three print the time, you can put the colon to only print half the time to flash it if you want
    x += 18;
    AddTextPrinterParameterized3(WINDOW_TOP_BAR, FONT_NORMAL, x, y, sTimeTextColors, TEXT_SKIP_DRAW, gText_Colon2);
    x += width;
    ConvertIntToDecimalStringN(gStringVar4, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WINDOW_TOP_BAR, FONT_NORMAL, x, y, sTimeTextColors, TEXT_SKIP_DRAW, gStringVar4);

#if (FLAG_CLOCK_MODE != 0)
    if (suffix != NULL)
    {
        width = GetStringWidth(FONT_NORMAL, gStringVar4, 0) + 3; // CHAR_SPACE is 3 pixels wide
        x += width;
        StringExpandPlaceholders(gStringVar4, suffix);
        AddTextPrinterParameterized3(WINDOW_TOP_BAR, FONT_NORMAL, x, y, sTimeTextColors, TEXT_SKIP_DRAW, gStringVar4);
    }
#endif

    PutWindowTilemap(WINDOW_TOP_BAR);
    CopyWindowToVram(WINDOW_TOP_BAR, COPYWIN_FULL);
}


//
//  Exit Start Menu Functions 
//  These functions take you to the other menus
//
void Task_OpenPokedexFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StartMenuFull_FreeResources();
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);
        DestroyTask(taskId);
    }
}

void Task_OpenPokemonPartyFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StartMenuFull_FreeResources();
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu);
    }
}

void Task_OpenBagFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StartMenuFull_FreeResources();
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu);
    }
}

void Task_OpenTrainerCardFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000) // cleared vram because for some reason I was having issues with this
        StartMenuFull_FreeResources();
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();

        if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFullScreenStartMenu);
        else
            ShowPlayerTrainerCard(CB2_ReturnToFullScreenStartMenu);
    }
}

void Task_OpenPokenavStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StartMenuFull_FreeResources();
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitPokeNav);
    }
}

void Task_OpenOptionsMenuStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StartMenuFull_FreeResources();
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); 
        gMain.savedCallback = CB2_ReturnToFullScreenStartMenu;
    }
}

void Task_ReturnToFieldOnSave(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StartMenuFull_FreeResources();
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_ReturnToField); 
    }
}


//
//  Handle save Confirmation and then Leave to Overworld for Saving 
//
# define sFrameToSecondTimer data[6]
void Task_HandleSaveConfirmation(u8 taskId)
{
    if(JOY_NEW(A_BUTTON)) //confirm and leave
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ReturnToFieldOnSave;
        gFieldCallback = SaveStartCallback_FullStartMenu;
        return;
    }
    if(JOY_NEW(B_BUTTON)) // back to normal Menu Control
    {
        PlaySE(SE_SELECT);
        FillWindowPixelBuffer(WINDOW_BOTTOM_BAR, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        PutWindowTilemap(WINDOW_BOTTOM_BAR);
        CopyWindowToVram(WINDOW_BOTTOM_BAR, COPYWIN_FULL);
        gTasks[taskId].func = Task_StartMenuFullMain;
        return;
    }
    if(gTasks[taskId].sFrameToSecondTimer >= 60) // every 60 frames update the time
    {
        PrintMapNameAndTime();
        gTasks[taskId].sFrameToSecondTimer = 0;
    }
    gTasks[taskId].sFrameToSecondTimer++;
}



//
//  Main Control Function, Grid UI Control
//
static void Task_StartMenuFullMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartMenuFullTurnOff;
    }
    if (JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT)) // these change the position of the selector, the actual x/y of the sprite is handled in its callback CursorCallback
    {
        if(sStartMenuDataPtr->selector_x == 0)
            sStartMenuDataPtr->selector_x = 1;
        else
            sStartMenuDataPtr->selector_x = 0; 
    }
    if (JOY_NEW(DPAD_UP))
    {
        if (sStartMenuDataPtr->selector_y == 0)
            sStartMenuDataPtr->selector_y = 2;
        else
            sStartMenuDataPtr->selector_y--;
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        if (sStartMenuDataPtr->selector_y == 2)
            sStartMenuDataPtr->selector_y = 0;
        else
            sStartMenuDataPtr->selector_y++;
    }
    if (JOY_NEW(A_BUTTON)) //when A is pressed, load the Task for the Menu the cursor is on, for some they require a flag to be set
    {
        switch(gSelectedMenu)
        {
            case START_MENU_BAG:
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_OpenBagFromStartMenu;
                break;
            case START_MENU_POKEDEX:
                if(FlagGet(FLAG_SYS_POKEDEX_GET))
                {
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenPokedexFromStartMenu;
                }
                else
                {
                    PlaySE(SE_BOO);
                }
                break;
            case START_MENU_PARTY:
                if(FlagGet(FLAG_SYS_POKEMON_GET))
                {
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenPokemonPartyFromStartMenu;
                }
                else
                {
                    PlaySE(SE_BOO);
                }
                break;
            case START_MENU_MAP:
                if(FlagGet(FLAG_SYS_POKENAV_GET))
                {
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenPokenavStartMenu;
                }
                else{
                    PlaySE(SE_BOO);
                }
                break;
            case START_MENU_CARD:
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_OpenTrainerCardFromStartMenu;
                break;
            case START_MENU_OPTIONS:
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_OpenOptionsMenuStartMenu;
                break;
        }
    }

    if(JOY_NEW(START_BUTTON)) // If start button pressed go to Save Confirmation Control Task
    {
        PrintSaveConfirmToWindow();
        gTasks[taskId].func = Task_HandleSaveConfirmation;
    }

#if (FLAG_CLOCK_MODE != 0)
    if (JOY_NEW(SELECT_BUTTON)) // switch between clock modes
    {
        if (FlagGet(FLAG_CLOCK_MODE))
            FlagClear(FLAG_CLOCK_MODE);
        else
            FlagSet(FLAG_CLOCK_MODE);

        PrintMapNameAndTime();
        PlaySE(SE_SUCCESS);
    }
#endif

    if(gTasks[taskId].sFrameToSecondTimer >= 60) // every 60 frames update the time
    {
        PrintMapNameAndTime();
        gTasks[taskId].sFrameToSecondTimer = 0;
    }
    gTasks[taskId].sFrameToSecondTimer++;

}
