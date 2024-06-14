#include "global.h"
#include "ui_outfits.h"
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
#include "region_map.h"
#include "pokedex.h"
#include "title_screen.h"
#include "main_menu.h"
#include "option_menu.h"
#include "mystery_event_menu.h"
#include "mystery_gift_menu.h"
#include "link.h"

/*
 * 
 */
 
//==========DEFINES==========//
struct OutfitsMenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u16 iconBoxSpriteIds[6];
    u16 iconMonSpriteIds[6];
    u16 mugshotSpriteId[12];
    u8 sSelectedOption;
};

enum WindowIds
{
    WINDOW_HEADER,
    WINDOW_MIDDLE,
};

enum {
    STATE_BRENDAN,
    STATE_MAY,
    STATE_RED,
    STATE_LEAF,

    STATE_LUCAS,
    STATE_DAWN,
    STATE_ETHAN,
    STATE_LYRA,

    STATE_STEVEN,
    STATE_CYNTHIA,
    STATE_OAK,
    STATE_PHOEBE
};

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};

enum
{
    HAS_NO_SAVED_GAME,  //NEW GAME, OPTION
    HAS_SAVED_GAME,     //CONTINUE, NEW GAME, OPTION
    HAS_MYSTERY_GIFT,   //CONTINUE, NEW GAME, MYSTERY GIFT, OPTION
    HAS_MYSTERY_EVENTS, //CONTINUE, NEW GAME, MYSTERY GIFT, MYSTERY EVENTS, OPTION
};

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

//==========EWRAM==========//
static EWRAM_DATA struct OutfitsMenuResources *sOutfitsMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 sSelectedOption = {0};
static EWRAM_DATA u8 menuType = {0};

//==========STATIC=DEFINES==========//
static void OutfitsMenu_RunSetup(void);
static bool8 OutfitsMenu_DoGfxSetup(void);
static bool8 OutfitsMenu_InitBgs(void);
static void OutfitsMenu_FadeAndBail(void);
static bool8 OutfitsMenu_LoadGraphics(void);
static void OutfitsMenu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void Task_OutfitsMenuWaitFadeIn(u8 taskId);
static void Task_OutfitsMenuMain(u8 taskId);
static void OutfitsMenu_InitializeGPUWindows(void);

static void CreateMugshot();
static void DestroyMugshot();
static void CreateIconShadow();
static void DestroyIconShadow();
static u32 GetHPEggCyclePercent(u32 partyIndex);
static void CreatePartyMonIcons();
static void DestroyMonIcons();


//==========Background and Window Data==========//
static const struct BgTemplate sOutfitsMenuBgTemplates[] =
{
    {
        .bg = 0,                // Text Background
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    }, 
    {
        .bg = 1,                // Main Background
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,                // Scroll Background
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .priority = 2
    }
};

static const struct WindowTemplate sOutfitsMenuWindowTemplates[] = 
{
    [WINDOW_HEADER] = // Prints the Map and Playtime
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 10,  // position from left (per 8 pixels)
        .tilemapTop = 1,    // position from top (per 8 pixels)
        .width = 18,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 0,    // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },

    [WINDOW_MIDDLE] = // Prints the name, dex number, and badges
    {
        .bg = 0,                   // which bg to print text on
        .tilemapLeft = 8,          // position from left (per 8 pixels)
        .tilemapTop = 4,           // position from top (per 8 pixels)
        .width = 18,               // width (per 8 pixels)
        .height = 7,               // height (per 8 pixels)
        .paletteNum = 0,           // palette index to use for text
        .baseBlock = 1 + (18 * 2), // tile start in VRAM
    },
    DUMMY_WIN_TEMPLATE
};

//  Positions of Hardware/GPU Windows
//       that highlight and hide sections of the Bg
struct HighlightWindowCoords {
    u8 left;
    u8 right;
};

struct HWWindowPosition {
    struct HighlightWindowCoords winh;
    struct HighlightWindowCoords winv;
};

static const struct HWWindowPosition HWinCoords[12] = 
{
    [STATE_BRENDAN]        = {{0, 60},    {0, 56},},
    [STATE_MAY]            = {{60, 120},   {0, 56},},
    [STATE_RED]            = {{120, 180}, {0, 56},},
    [STATE_LEAF]           = {{180, 240},   {0, 56},},

    [STATE_LUCAS]           = {{0, 60},      {56, 107},},
    [STATE_DAWN]            = {{60, 120},    {56, 107},},
    [STATE_ETHAN]           = {{120, 180},   {56, 107},},
    [STATE_LYRA]            = {{180, 240},   {56, 107},},

    [STATE_STEVEN]          = {{0, 60},      {107, 160},},
    [STATE_CYNTHIA]         = {{60, 120},    {107, 160},},
    [STATE_OAK]             = {{120, 180},   {107, 160},},
    [STATE_PHOEBE]          = {{180, 240},   {107, 160}},
};


//
//  Graphic and Tilemap Pointers for Bgs and Mughsots
//
static const u32 sMainBgTiles[] = INCBIN_U32("graphics/ui_outfits/main_tiles.4bpp.lz");
static const u32 sMainBgTilemap[] = INCBIN_U32("graphics/ui_outfits/main_tiles.bin.lz");
static const u16 sMainBgPalette[] = INCBIN_U16("graphics/ui_outfits/main_tiles.gbapal");

static const u32 sMainBgTilesFem[] = INCBIN_U32("graphics/ui_outfits/main_tiles_fem.4bpp.lz");
static const u32 sMainBgTilemapFem[] = INCBIN_U32("graphics/ui_outfits/main_tiles_fem.bin.lz");
static const u16 sMainBgPaletteFem[] = INCBIN_U16("graphics/ui_outfits/main_tiles_fem.gbapal");

static const u32 sScrollBgTiles[] = INCBIN_U32("graphics/ui_outfits/scroll_tiles.4bpp.lz");
static const u32 sScrollBgTilemap[] = INCBIN_U32("graphics/ui_outfits/scroll_tiles.bin.lz");
static const u16 sScrollBgPalette[] = INCBIN_U16("graphics/ui_outfits/scroll_tiles.gbapal");

static const u16 sIconBox_Pal[] = INCBIN_U16("graphics/ui_outfits/icon_shadow.gbapal");
static const u32 sIconBox_Gfx[] = INCBIN_U32("graphics/ui_outfits/icon_shadow.4bpp.lz");

static const u16 sIconBox_PalFem[] = INCBIN_U16("graphics/ui_outfits/icon_shadow_fem.gbapal");
static const u32 sIconBox_GfxFem[] = INCBIN_U32("graphics/ui_outfits/icon_shadow_fem.4bpp.lz");

static const u16 sBrendanMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/brendan_mugshot.gbapal");
static const u32 sBrendanMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/brendan_mugshot.4bpp.lz");
static const u16 sMayMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/may_mugshot.gbapal");
static const u32 sMayMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/may_mugshot.4bpp.lz");

static const u16 sRedMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/red_mugshot.gbapal");
static const u32 sRedMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/red_mugshot.4bpp.lz");
static const u16 sLeafMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/leaf_mugshot.gbapal");
static const u32 sLeafMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/leaf_mugshot.4bpp.lz");

static const u16 sLucasMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/lucas_mugshot.gbapal");
static const u32 sLucasMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/lucas_mugshot.4bpp.lz");
static const u16 sDawnMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/dawn_mugshot.gbapal");
static const u32 sDawnMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/dawn_mugshot.4bpp.lz");

static const u16 sStevenMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/steven.gbapal");
static const u32 sStevenMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/steven.4bpp.lz");
static const u16 sCynthiaMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/cynthia.gbapal");
static const u32 sCynthiaMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/cynthia.4bpp.lz");

static const u16 sOakMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/oak.gbapal");
static const u32 sOakMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/oak.4bpp.lz");
static const u16 sPhoebeMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/phoebe.gbapal");
static const u32 sPhoebeMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/phoebe.4bpp.lz");

static const u16 sEthanMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/ethan.gbapal");
static const u32 sEthanMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/ethan.4bpp.lz");
static const u16 sLyraMugshot_Pal[] = INCBIN_U16("graphics/ui_outfits/lyra.gbapal");
static const u32 sLyraMugshot_Gfx[] = INCBIN_U32("graphics/ui_outfits/lyra.4bpp.lz");

//
//  Sprite Data for Mugshots and Icon Shadows 
//
#define TAG_MUGSHOT_BRENDAN 30012
#define TAG_MUGSHOT_MAY 30013
#define TAG_MUGSHOT_RED 30014
#define TAG_MUGSHOT_LEAF 30015

#define TAG_MUGSHOT_LUCAS 30016
#define TAG_MUGSHOT_DAWN 30017
#define TAG_MUGSHOT_ETHAN 30018
#define TAG_MUGSHOT_LYRA 30019

#define TAG_MUGSHOT_STEVEN 30020
#define TAG_MUGSHOT_CYNTHIA 30021
#define TAG_MUGSHOT_OAK 30022
#define TAG_MUGSHOT_PHOEBE 30023

#define TAG_ICON_BOX 30006
static const struct OamData sOamData_Mugshot =
{
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 1,
};

static const union AnimCmd sSpriteAnim_Mugshot[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Mugshot[] =
{
    sSpriteAnim_Mugshot,
};

static const struct CompressedSpriteSheet sSpriteSheet_BrendanMugshot =
{
    .data = sBrendanMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_BRENDAN,
};

static const struct SpritePalette sSpritePal_BrendanMugshot =
{
    .data = sBrendanMugshot_Pal,
    .tag = TAG_MUGSHOT_BRENDAN,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotBrendan =
{
    .tileTag = TAG_MUGSHOT_BRENDAN,
    .paletteTag = TAG_MUGSHOT_BRENDAN,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_MayMugshot =
{
    .data = sMayMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_MAY,
};

static const struct SpritePalette sSpritePal_MayMugshot =
{
    .data = sMayMugshot_Pal,
    .tag = TAG_MUGSHOT_MAY,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotMay =
{
    .tileTag = TAG_MUGSHOT_MAY,
    .paletteTag = TAG_MUGSHOT_MAY,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_RedMugshot =
{
    .data = sRedMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_RED,
};

static const struct SpritePalette sSpritePal_RedMugshot =
{
    .data = sRedMugshot_Pal,
    .tag = TAG_MUGSHOT_RED,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotRed =
{
    .tileTag = TAG_MUGSHOT_RED,
    .paletteTag = TAG_MUGSHOT_RED,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_LeafMugshot =
{
    .data = sLeafMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_LEAF,
};

static const struct SpritePalette sSpritePal_LeafMugshot =
{
    .data = sLeafMugshot_Pal,
    .tag = TAG_MUGSHOT_LEAF,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotLeaf =
{
    .tileTag = TAG_MUGSHOT_LEAF,
    .paletteTag = TAG_MUGSHOT_LEAF,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_LucasMugshot =
{
    .data = sLucasMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_LUCAS,
};

static const struct SpritePalette sSpritePal_LucasMugshot =
{
    .data = sLucasMugshot_Pal,
    .tag = TAG_MUGSHOT_LUCAS,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotLucas =
{
    .tileTag = TAG_MUGSHOT_LUCAS,
    .paletteTag = TAG_MUGSHOT_LUCAS,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_DawnMugshot =
{
    .data = sDawnMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_DAWN
};

static const struct SpritePalette sSpritePal_DawnMugshot =
{
    .data = sDawnMugshot_Pal,
    .tag = TAG_MUGSHOT_DAWN,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotDawn =
{
    .tileTag = TAG_MUGSHOT_DAWN,
    .paletteTag = TAG_MUGSHOT_DAWN,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_StevenMugshot =
{
    .data = sStevenMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_STEVEN,
};

static const struct SpritePalette sSpritePal_StevenMugshot =
{
    .data = sStevenMugshot_Pal,
    .tag = TAG_MUGSHOT_STEVEN,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotSteven =
{
    .tileTag = TAG_MUGSHOT_STEVEN,
    .paletteTag = TAG_MUGSHOT_STEVEN,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_CynthiaMugshot =
{
    .data = sCynthiaMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_CYNTHIA,
};

static const struct SpritePalette sSpritePal_CynthiaMugshot =
{
    .data = sCynthiaMugshot_Pal,
    .tag = TAG_MUGSHOT_CYNTHIA,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotCynthia =
{
    .tileTag = TAG_MUGSHOT_CYNTHIA,
    .paletteTag = TAG_MUGSHOT_CYNTHIA,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_OakMugshot =
{
    .data = sOakMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_OAK,
};

static const struct SpritePalette sSpritePal_OakMugshot =
{
    .data = sOakMugshot_Pal,
    .tag = TAG_MUGSHOT_OAK,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotOak =
{
    .tileTag = TAG_MUGSHOT_OAK,
    .paletteTag = TAG_MUGSHOT_OAK,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_PhoebeMugshot =
{
    .data = sPhoebeMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_PHOEBE,
};

static const struct SpritePalette sSpritePal_PhoebeMugshot =
{
    .data = sPhoebeMugshot_Pal,
    .tag = TAG_MUGSHOT_PHOEBE,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotPhoebe =
{
    .tileTag = TAG_MUGSHOT_PHOEBE,
    .paletteTag = TAG_MUGSHOT_PHOEBE,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_EthanMugshot =
{
    .data = sEthanMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_ETHAN,
};

static const struct SpritePalette sSpritePal_EthanMugshot =
{
    .data = sEthanMugshot_Pal,
    .tag = TAG_MUGSHOT_ETHAN,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotEthan =
{
    .tileTag = TAG_MUGSHOT_ETHAN,
    .paletteTag = TAG_MUGSHOT_ETHAN,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_LyraMugshot =
{
    .data = sLyraMugshot_Gfx,
    .size = 64*64*1/2,
    .tag = TAG_MUGSHOT_LYRA,
};

static const struct SpritePalette sSpritePal_LyraMugshot =
{
    .data = sLyraMugshot_Pal,
    .tag = TAG_MUGSHOT_LYRA,
};

static const struct SpriteTemplate sSpriteTemplate_MugshotLyra =
{
    .tileTag = TAG_MUGSHOT_LYRA,
    .paletteTag = TAG_MUGSHOT_LYRA,
    .oam = &sOamData_Mugshot,
    .anims = sSpriteAnimTable_Mugshot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};


static const struct OamData sOamData_IconBox =
{
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 1,
};

static const struct CompressedSpriteSheet sSpriteSheet_IconBox =
{
    .data = sIconBox_Gfx,
    .size = 32*32*1/2,
    .tag = TAG_ICON_BOX,
};

static const struct CompressedSpriteSheet sSpriteSheet_IconBoxFem =
{
    .data = sIconBox_GfxFem,
    .size = 32*32*1/2,
    .tag = TAG_ICON_BOX,
};

static const struct SpritePalette sSpritePal_IconBox =
{
    .data = sIconBox_Pal,
    .tag = TAG_ICON_BOX
};

static const struct SpritePalette sSpritePal_IconBoxFem =
{
    .data = sIconBox_PalFem,
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

//==========UI Initialization from Ghoulslash's UI Shell Branch==========//
void Task_OpenOutfitsMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {   
        CleanupOverworldWindowsAndTilemaps();
        OutfitsMenu_Init(CB2_InitTitleScreen); // if need to bail go to title screen
        DestroyTask(taskId);
    }
}

//
//  Setup Menu Functions
//
void OutfitsMenu_Init(MainCallback callback)
{
    u32 i = 0;
    if ((sOutfitsMenuDataPtr = AllocZeroed(sizeof(struct OutfitsMenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sOutfitsMenuDataPtr->gfxLoadState = 0;
    sOutfitsMenuDataPtr->savedCallback = callback;
    sSelectedOption = (gSaveBlock2Ptr->playerGender) + (gSaveBlock2Ptr->playerGfxType * 2);

    switch(gSaveBlock2Ptr->playerGender)
    {
        case MALE:
            switch(gSaveBlock2Ptr->playerGfxType)
            {
                case 0:
                    sSelectedOption = STATE_BRENDAN;
                    break;
                case 1:
                    sSelectedOption = STATE_RED;
                    break;
                case 2:
                    sSelectedOption = STATE_LUCAS;
                    break;
                case 3:
                    sSelectedOption = STATE_STEVEN;
                    break;
                case 4:
                    sSelectedOption = STATE_OAK;
                    break;
                case 5:
                    sSelectedOption = STATE_ETHAN;
                    break;
            }
            break;
        case FEMALE:
            switch(gSaveBlock2Ptr->playerGfxType)
            {
                case 0:
                    sSelectedOption = STATE_MAY;
                    break;
                case 1:
                    sSelectedOption = STATE_LEAF;
                    break;
                case 2:
                    sSelectedOption = STATE_DAWN;
                    break;
                case 3:
                    sSelectedOption = STATE_CYNTHIA;
                    break;
                case 4:
                    sSelectedOption = STATE_PHOEBE;
                    break;
                case 5:
                    sSelectedOption = STATE_LYRA;
                    break;
            }
            break;
    }

    for(i = 0; i < 12; i++)
    {
        sOutfitsMenuDataPtr->mugshotSpriteId[i] = SPRITE_NONE;
    }
    
    SetMainCallback2(OutfitsMenu_RunSetup);
}

static void OutfitsMenu_RunSetup(void)
{
    while (1)
    {
        if (OutfitsMenu_DoGfxSetup() == TRUE)
            break;
    }
}

static void OutfitsMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void OutfitsMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgY(2, 128, BG_COORD_SUB); // This controls the scrolling of the scroll bg, remove it to stop scrolling
}

//
//  Quit Out Functions
//
static void OutfitsMenu_FreeResources(void)
{
    try_free(sOutfitsMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    try_free(sBg2TilemapBuffer);
    FreeAllWindowBuffers();
    DestroyMugshot();
    DestroyIconShadow();
    DestroyMonIcons();
    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
}

static void Task_OutfitsMenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sOutfitsMenuDataPtr->savedCallback);
        OutfitsMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static void OutfitsMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_OutfitsMenuWaitFadeAndBail, 0);
    SetVBlankCallback(OutfitsMenu_VBlankCB);
    SetMainCallback2(OutfitsMenu_MainCB);
}

static void Task_OutfitsMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OutfitsMenuMain;
}

static void Task_OutfitsMenuTurnOff(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetMainCallback2(sOutfitsMenuDataPtr->savedCallback);
        OutfitsMenu_FreeResources();
        DestroyTask(taskId);
    }
}


//
//  Load Graphics Functions
//
static bool8 OutfitsMenu_DoGfxSetup(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
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
        OutfitsMenu_InitializeGPUWindows();
        gMain.state++;
        break;
    case 2:
        if (OutfitsMenu_InitBgs())
        {
            sOutfitsMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            OutfitsMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (OutfitsMenu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        OutfitsMenu_InitWindows();
        gMain.state++;
        break;
    case 5: // Here is where the sprites are drawn and text is printed
        CreateMugshot();
        CreateTask(Task_OutfitsMenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(OutfitsMenu_VBlankCB);
        SetMainCallback2(OutfitsMenu_MainCB);
        return TRUE;
    }
    return FALSE;
}

static bool8 OutfitsMenu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sOutfitsMenuBgTemplates, NELEMS(sOutfitsMenuBgTemplates));

    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    memset(sBg1TilemapBuffer, 0, 0x800);
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    sBg2TilemapBuffer = Alloc(0x800);
    if (sBg2TilemapBuffer == NULL)
        return FALSE;
    memset(sBg2TilemapBuffer, 0, 0x800);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(2);

    ShowBg(0);
    ShowBg(2);
    return TRUE;
}

static void OutfitsMenu_InitializeGPUWindows(void) // This function creates the windows that highlight an option and cover mystery options when not enabled
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP); // Turn on Windows 0 and 1 and Enable Sprites
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(HWinCoords[sSelectedOption].winh.left, HWinCoords[sSelectedOption].winh.right));  // Set Window 0 width/height Which defines the not darkened space
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(HWinCoords[sSelectedOption].winv.left, HWinCoords[sSelectedOption].winv.right));
    switch(menuType)
    {
            case HAS_SAVED_GAME:    // The three Window 1 states either block out the mystery buttons both, just the mystery event, or nothing. 
                SetGpuReg(REG_OFFSET_WIN1H,  WIN_RANGE(HWinCoords[STATE_DAWN].winh.left, HWinCoords[STATE_DAWN].winh.right));
                SetGpuReg(REG_OFFSET_WIN1V,  WIN_RANGE(HWinCoords[STATE_DAWN].winv.left, HWinCoords[STATE_DAWN].winv.right));
                break;   
            case HAS_MYSTERY_GIFT:
                SetGpuReg(REG_OFFSET_WIN1H,  WIN_RANGE(HWinCoords[STATE_LUCAS].winh.left, HWinCoords[STATE_LUCAS].winh.right));
                SetGpuReg(REG_OFFSET_WIN1V,  WIN_RANGE(HWinCoords[STATE_LUCAS].winv.left, HWinCoords[STATE_LUCAS].winv.right));
                break;
        }

    SetGpuReg(REG_OFFSET_WININ, (WININ_WIN1_BG0 | WININ_WIN1_BG2) | (WININ_WIN0_BG_ALL | WININ_WIN0_OBJ)); // Set Win 0 Active everywhere, Win 1 active on everything except bg 1 
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL);                                                                     // where the main tiles are so the window hides whats behind it
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_OBJ);   // Set Darken Effect on things not in the window on bg 0, 1, and sprite layer
    SetGpuReg(REG_OFFSET_BLDY, 7);  // Set Level of Darken effect, can be changed 0-16
}

static void MoveHWindowsWithInput(void) // Update GPU windows after selection is changed
{
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(HWinCoords[sSelectedOption].winh.left, HWinCoords[sSelectedOption].winh.right));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(HWinCoords[sSelectedOption].winv.left, HWinCoords[sSelectedOption].winv.right));
}

static bool8 OutfitsMenu_LoadGraphics(void) // Load all the tilesets, tilemaps, spritesheets, and palettes
{
    switch (sOutfitsMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        sOutfitsMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            sOutfitsMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sScrollBgTiles, 0, 0, 0);
        sOutfitsMenuDataPtr->gfxLoadState++;
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sScrollBgTilemap, sBg2TilemapBuffer);
            sOutfitsMenuDataPtr->gfxLoadState++;
        }
        break;
    case 4:
    {
        LoadCompressedSpriteSheet(&sSpriteSheet_RedMugshot);
        LoadSpritePalette(&sSpritePal_RedMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_LucasMugshot);
        LoadSpritePalette(&sSpritePal_LucasMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_StevenMugshot);
        LoadSpritePalette(&sSpritePal_StevenMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_OakMugshot);
        LoadSpritePalette(&sSpritePal_OakMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_EthanMugshot);
        LoadSpritePalette(&sSpritePal_EthanMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_BrendanMugshot);
        LoadSpritePalette(&sSpritePal_BrendanMugshot);

        LoadCompressedSpriteSheet(&sSpriteSheet_LeafMugshot);
        LoadSpritePalette(&sSpritePal_LeafMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_DawnMugshot);
        LoadSpritePalette(&sSpritePal_DawnMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_CynthiaMugshot);
        LoadSpritePalette(&sSpritePal_CynthiaMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_PhoebeMugshot);
        LoadSpritePalette(&sSpritePal_PhoebeMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_LyraMugshot);
        LoadSpritePalette(&sSpritePal_LyraMugshot);
        LoadCompressedSpriteSheet(&sSpriteSheet_MayMugshot);
        LoadSpritePalette(&sSpritePal_MayMugshot);

        LoadPalette(sScrollBgPalette, 16, 32);
    }
        sOutfitsMenuDataPtr->gfxLoadState++;
        break;
    default:
        sOutfitsMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void OutfitsMenu_InitWindows(void) // Init Text Windows
{
    InitWindows(sOutfitsMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_HEADER, 0);
    PutWindowTilemap(WINDOW_HEADER);
    CopyWindowToVram(WINDOW_HEADER, 3);

    FillWindowPixelBuffer(WINDOW_MIDDLE, 0);
    PutWindowTilemap(WINDOW_MIDDLE);
    CopyWindowToVram(WINDOW_MIDDLE, 3);
}


/*    Sprite Creation Functions     */

//
//      Mugshot Functions
//
#define MUGSHOT_X_1 30
#define MUGSHOT_X_2 90
#define MUGSHOT_X_3 150
#define MUGSHOT_X_4 210

#define MUGSHOT_Y_1 32
#define MUGSHOT_Y_2 86
#define MUGSHOT_Y_3 138

static void CreateMugshot()
{
    sOutfitsMenuDataPtr->mugshotSpriteId[0] = CreateSprite(&sSpriteTemplate_MugshotBrendan, MUGSHOT_X_1, MUGSHOT_Y_1, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[1] = CreateSprite(&sSpriteTemplate_MugshotMay,     MUGSHOT_X_2, MUGSHOT_Y_1, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[2] = CreateSprite(&sSpriteTemplate_MugshotRed,     MUGSHOT_X_3, MUGSHOT_Y_1, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[3] = CreateSprite(&sSpriteTemplate_MugshotLeaf,    MUGSHOT_X_4, MUGSHOT_Y_1, 1);

    sOutfitsMenuDataPtr->mugshotSpriteId[4] = CreateSprite(&sSpriteTemplate_MugshotLucas, MUGSHOT_X_1, MUGSHOT_Y_2, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[5] = CreateSprite(&sSpriteTemplate_MugshotDawn,  MUGSHOT_X_2, MUGSHOT_Y_2, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[6] = CreateSprite(&sSpriteTemplate_MugshotEthan, MUGSHOT_X_3, MUGSHOT_Y_2, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[7] = CreateSprite(&sSpriteTemplate_MugshotLyra,  MUGSHOT_X_4, MUGSHOT_Y_2, 1);

    sOutfitsMenuDataPtr->mugshotSpriteId[8] = CreateSprite(&sSpriteTemplate_MugshotSteven,  MUGSHOT_X_1, MUGSHOT_Y_3, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[9] = CreateSprite(&sSpriteTemplate_MugshotCynthia, MUGSHOT_X_2, MUGSHOT_Y_3, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[10] = CreateSprite(&sSpriteTemplate_MugshotOak,     MUGSHOT_X_3, MUGSHOT_Y_3, 1);
    sOutfitsMenuDataPtr->mugshotSpriteId[11] = CreateSprite(&sSpriteTemplate_MugshotPhoebe,  MUGSHOT_X_4, MUGSHOT_Y_3, 1);
    return;
}

static void DestroyMugshot()
{
    for(u8 i = 0; i < 12; i++)
    {
        DestroySprite(&gSprites[sOutfitsMenuDataPtr->mugshotSpriteId[i]]);
        sOutfitsMenuDataPtr->mugshotSpriteId[i] = SPRITE_NONE;
    }
    
}

//
//  Create Mon Icon and Shadow Sprites
//
static void CreateIconShadow()
{

}

static void DestroyIconShadow()
{

}

static void CreatePartyMonIcons()
{

}

static void DestroyMonIcons()
{

}


//
//  Print The Text For Dex Num, Badges, Name, Playtime, Location
//
static const u8 sText_DexNum[] = _("Dex {STR_VAR_1}");
static const u8 sText_Badges[] = _("Badges {STR_VAR_1}");
static void PrintToWindow(u8 windowId, u8 colorIdx)
{

}


//
//  Main Input Control Task
//
static void Task_OutfitsMenuMain(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON) || JOY_NEW(START_BUTTON)) 
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        switch(sSelectedOption)
        {
                case STATE_BRENDAN:
                    gSaveBlock2Ptr->playerGender = MALE;
                    gSaveBlock2Ptr->playerGfxType = 0;
                    break;
                case STATE_MAY:
                    gSaveBlock2Ptr->playerGender = FEMALE;
                    gSaveBlock2Ptr->playerGfxType = 0;
                    break;
                case STATE_RED:
                    gSaveBlock2Ptr->playerGender = MALE;
                    gSaveBlock2Ptr->playerGfxType = 1;
                    break;
                case STATE_LEAF:
                    gSaveBlock2Ptr->playerGender = FEMALE;
                    gSaveBlock2Ptr->playerGfxType = 1;
                    break;
                case STATE_LUCAS:
                    gSaveBlock2Ptr->playerGender = MALE;
                    gSaveBlock2Ptr->playerGfxType = 2;
                    break;
                case STATE_DAWN:
                    gSaveBlock2Ptr->playerGender = FEMALE;
                    gSaveBlock2Ptr->playerGfxType = 2;
                    break;
                case STATE_STEVEN:
                    gSaveBlock2Ptr->playerGender = MALE;
                    gSaveBlock2Ptr->playerGfxType = 3;
                    break;
                case STATE_CYNTHIA:
                    gSaveBlock2Ptr->playerGender = FEMALE;
                    gSaveBlock2Ptr->playerGfxType = 3;
                    break;
                case STATE_OAK:
                    gSaveBlock2Ptr->playerGender = MALE;
                    gSaveBlock2Ptr->playerGfxType = 4;
                    break;
                case STATE_PHOEBE:
                    gSaveBlock2Ptr->playerGender = FEMALE;
                    gSaveBlock2Ptr->playerGfxType = 4;
                    break;
                case STATE_ETHAN:
                    gSaveBlock2Ptr->playerGender = MALE;
                    gSaveBlock2Ptr->playerGfxType = 5;
                    break;
                case STATE_LYRA:
                    gSaveBlock2Ptr->playerGender = FEMALE;
                    gSaveBlock2Ptr->playerGfxType = 5;
                    break;
        }
        gTasks[taskId].func = Task_OutfitsMenuTurnOff;
    }

    if(JOY_NEW(DPAD_DOWN)) // Handle DPad directions, kinda bad way to do it with each case handled individually but its whatever
    {
        if(sSelectedOption >= STATE_STEVEN)
            sSelectedOption -= 8;
        else
            sSelectedOption += 4;
        MoveHWindowsWithInput();
    }

    if(JOY_NEW(DPAD_UP))
    {
        if(sSelectedOption <= STATE_LEAF)
            sSelectedOption += 8;
        else
            sSelectedOption -= 4;
        MoveHWindowsWithInput();
    }

    if(JOY_NEW(DPAD_LEFT))
    {
        if((sSelectedOption == STATE_BRENDAN) || (sSelectedOption == STATE_LUCAS) || (sSelectedOption == STATE_STEVEN))
            sSelectedOption += 3;
        else
            sSelectedOption -= 1;
        MoveHWindowsWithInput();
    }

    if(JOY_NEW(DPAD_RIGHT))
    {
        if((sSelectedOption == STATE_LEAF) || (sSelectedOption == STATE_LYRA) || (sSelectedOption == STATE_PHOEBE))
            sSelectedOption -= 3;
        else 
            sSelectedOption += 1;
        MoveHWindowsWithInput();
    }
}
