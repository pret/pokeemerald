#include "global.h"
#include "alloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"
#include "field_weather.h"
#include "palette.h"
#include "pokemon_storage_system.h"
#include "sound.h"
#include "constants/songs.h"
#include "window.h"
#include "gpu_regs.h"
#include "bg.h"
#include "menu.h"
#include "graphics.h"
#include "dma3.h"
#include "gba/macro.h"
#include "decompress.h"
#include "strings.h"
#include "constants/rgb.h"

enum
{
    MODE_NORMAL, // Chosen from Start menu.
    MODE_FORCE_CALL_1, // Used for the script's special. Has to choose Match Call and make a call.
    MODE_FORCE_CALL_2, // Set after making a call, has to exit Pokenav.
};

enum
{
    NAVMENU_CB_UNK_0,
    NAVMENU_CB_UNK_1,
    NAVMENU_CB_UNK_2,
    NAVMENU_CB_UNK_3,
    NAVMENU_CB_UNK_4,
    NAVMENU_CB_UNK_5,
    NAVMENU_CB_UNK_6
};

enum
{
    NAVGEAR_GFX_MAIN_MENU,
    NAVGEAR_GFX_CONDITION_MENU,
    NAVGEAR_GFX_RIBBONS_MENU,
    NAVGEAR_GFX_MATCH_CALL_MENU,
    
    // One of these is for the zoomed-in map, and the other is for the
    // zoomed-out map. Don't know which is which yet.
    NAVGEAR_GFX_MAP_MENU_UNK0,
    NAVGEAR_GFX_MAP_MENU_UNK1,

    NAVGEAR_GFX_PARTY_MENU,
    NAVGEAR_GFX_SEARCH_MENU,
    NAVGEAR_GFX_COOL_MENU,
    NAVGEAR_GFX_BEAUTY_MENU,
    NAVGEAR_GFX_CUTE_MENU,
    NAVGEAR_GFX_SMART_MENU,
    NAVGEAR_GFX_TOUGH_MENU,

    NAVGEAR_GFX_MENUS_END
};

#define NAVGEAR_GFX_SUBMENUS_START NAVGEAR_GFX_PARTY_MENU

// Return values of LoopedTask functions.
#define LT_INC_AND_PAUSE 0
#define LT_INC_AND_CONTINUE 1
#define LT_PAUSE 2
#define LT_CONTINUE 3
#define LT_FINISH 4
#define LT_SET_STATE(newState) (newState + 5)

#define LOOPED_TASK_DECODE_STATE(action) (action - 5)

#define LOOPED_TASK_ID(primary, secondary) (((secondary) << 16) |(primary))
#define LOOPED_TASK_PRIMARY_ID(taskId) (taskId & 0xFFFF)
#define LOOPED_TASK_SECONDARY_ID(taskId) (taskId >> 16)

#define UNKNOWN_OFFSET 100000

typedef u32 (*LoopedTask)(s32 state);

struct UnknownSubSubStruct_0203CF40 {
    u8 bg;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fontId;
    u16 unk6;
    u16 windowId;
    u16 unkA;
    u16 unkC;
    u16 unkE;
};

struct MatchCallWindowState {
    // The index of the element at the top of the window.
    u16 windowTopIndex;
    u16 listLength;
    u16 unk4;
    // The index of the cursor, relative to the top of the window.
    u16 selectedIndexOffset;
    u16 visibleEntries;
    u16 unkA;
    u32 unkC;
    u32 unk10;
};

// Generally at index 0.
struct PokenavMainMenuResources
{
    void (*unk0)(u32);
    u32 (*unk4)(void);
    u32 unk8;
    u32 currentTaskId;
    u32 unk10;
    u32 unk14;
    struct Sprite *spinningNavgear;
    struct Sprite *leftHeaderSprites[2];
    struct Sprite *submenuLeftHeaderSprites[2];
    u8 tilemapBuffer[0x800];
};

struct UnknownInnerStruct_81C81D4
{
    struct UnknownSubSubStruct_0203CF40 unk0;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    s32 unk20;
    s32 unk24;
    u32 unk28;
    s32 unk2C;
    u32 unk30;
    void (*unk34)(u32, u8*);
    void (*unk38)(u16, u32, u32);
    struct Sprite *rightArrow;
    struct Sprite *upArrow;
    struct Sprite *downArrow;
    u8 unkTextBuffer[0x40];
};

// Generally at index 0x11 (17)
struct UnknownSubStruct_81C81D4
{
    struct UnknownInnerStruct_81C81D4 unk0;
    u8 tilemapBuffer[0x800];
    struct MatchCallWindowState unk888;
    u32 unk89C;
    u32 unk8A0;
};

#define SUBSTRUCT_COUNT 19

struct PokenavResources
{
    u32 (*currentMenuCb1)(void);
    u32 currentMenuIndex;
    u16 mode;
    u16 fieldA;
    bool32 hasAnyRibbons;
    void *field10[SUBSTRUCT_COUNT];
};

// This struct uses a 32bit tag, and doesn't have a size field.
// Needed to match LoadLeftHeaderGfxForSubMenu.
struct CompressedSpriteSheetNoSize
{
    const u32 *data;  // LZ77 compressed palette data
    u32 tag;
};

struct MatchCallListTemplate
{
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    void (*unk10)(u32, u8 *a1);
    void (*unk14)(u16 a0, u32 a1, u32 a2);
};

extern u32 sub_81C9430(void);
extern void sub_81CAADC(void);
extern u32 sub_81C99D4(void);
extern void InitHoenMapHeaderSprites(void);
extern u32 sub_81C9298(void);
extern u32 sub_81C941C(void);
extern u32 sub_81C9924(void);
extern u32 sub_81C99C0(void);
extern u32 sub_81C9990(void);
extern u32 sub_81C9940(void);
extern u32 sub_81C9338(void);
extern u32 sub_81C9368(void);
extern u32 sub_81C92CC(void);
extern u32 sub_81C9304(void);
extern u32 sub_81CC4D4(void);
extern u32 sub_81CC554(void);
extern u32 sub_81CC5F4(void);
extern u32 sub_81CC62C(void);
extern u32 sub_81CC65C(void);
extern u32 sub_81CC524(void);
extern u32 sub_81CC670(void);
extern u32 sub_81CCFD8(void);
extern u32 sub_81CD070(void);
extern u32 sub_81CDDD4(void);
extern u32 sub_81CDE2C(void);
extern u32 sub_81CDE64(void);
extern u32 sub_81CD1C0(void);
extern u32 sub_81CECA0(void);
extern u32 sub_81CEF3C(void);
extern u32 sub_81CEFDC(void);
extern u32 sub_81CF330(void);
extern u32 sub_81CF3A0(void);
extern u32 sub_81CF3D0(void);
extern u32 sub_81CEFF0(void);
extern u32 sub_81CF3F8(void);
extern u32 sub_81CD024(void);
extern u32 sub_81CEF98(void);
extern u32 sub_81CF368(void);
extern u32 sub_81CAAE8(void);
extern u32 sub_81CAB24(void);
extern u32 sub_81CB260(void);
extern u32 sub_81CB29C(void);
extern u32 sub_81CB2CC(void);
extern u32 sub_81CAB38(void);
extern u32 sub_81CB2E0(void);
extern u32 sub_81CF9BC(void);
extern u32 sub_81CFA34(void);
extern u32 sub_81CFDD0(void);
extern u32 sub_81CFE40(void);
extern u32 sub_81CFE70(void);
extern u32 sub_81CFA48(void);
extern u32 sub_81CFE98(void);
extern u32 sub_81D0450(void);
extern u32 sub_81D04A0(void);
extern u32 sub_81D0978(void);
extern u32 sub_81D09B0(void);
extern u32 sub_81D09E0(void);
extern u32 sub_81D04B8(void);
extern u32 sub_81D09F4(void);
extern u32 sub_81CFA04(void);
extern u32 sub_81CFE08(void);
extern void SpriteCB_SpinningNavgear(struct Sprite* sprite);
extern void sub_81CBD48(u16 windowId, u32 a1);
extern u8 *sub_81CAFD8(u16 a0, u32 a1);
extern void sub_81DB620(u32 windowId, u32 a1, u32 a2, u32 a3, u32 a4);

u32 sub_81C91AC(struct UnknownInnerStruct_81C81D4 *a0, const struct BgTemplate *a1, struct MatchCallListTemplate *a2, s32 a3);
void sub_81C9160(struct MatchCallWindowState *a0, struct MatchCallListTemplate *a1);
void SpriteCB_MatchCallUpArrow(struct Sprite *sprite);
void SpriteCB_MatchCallDownArrow(struct Sprite *sprite);
void SpriteCB_MatchCallRightArrow(struct Sprite *sprite);
void ToggleMatchCallArrows(struct UnknownInnerStruct_81C81D4 *a0, u32 a1);
void sub_81C8FE0(struct UnknownInnerStruct_81C81D4 *a0);
void sub_81C8EF8(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C8ED0(void);
void sub_81C8E54(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1, u32 a2);
void PrintMatchCallFieldNames(struct UnknownInnerStruct_81C81D4 *a0, u32 a1);
void sub_81C8D4C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C8CB4(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C8B70(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1, u32 a2);
u32 LoopedTask_sub_81C8A28(s32 a0);
u32 LoopedTask_sub_81C8958(s32 a0);
u32 LoopedTask_sub_81C8870(s32 a0);
u32 LoopedTask_sub_81C85A0(s32 a0);
void sub_81C8568(s32 a0, struct UnknownInnerStruct_81C81D4 *a1);
u32 LoopedTask_sub_81C83F0(s32 a0);
bool32 sub_81C83E0(void);
void sub_81C83AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct UnknownInnerStruct_81C81D4 *a5);
void sub_81C837C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1);
void sub_81C835C(struct UnknownSubSubStruct_0203CF40 *a0);
void sub_81C82E4(struct UnknownSubStruct_81C81D4 *a0);
u32 LoopedTask_sub_81C8254(s32 a0);
u32 LoopedTask_ScrollMenuHeaderUp(s32 a0);
bool32 SetActivePokenavMenu(u32 a0);
bool32 InitPokenavMainMenu(void);
static bool32 AnyMonHasRibbon(void);
u32 sub_81C75E0(void);
u32 sub_81C75D4(void);
u32 PokenavMainMenuLoopedTaskIsActive(void);
u32 sub_81C786C(void);
u32 LoopedTask_InitPokenavMenu(s32 a0);
u32 LoopedTask_ScrollMenuHeaderDown(s32 a0);
bool32 WaitForPokenavShutdownFade(void);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 a1, u32 a2);
void sub_81C7834(void *func1, void *func2);
static void InitPokenavResources(struct PokenavResources *a0);
void FreePokenavSubstruct(u32 index);
void sub_81C7850(u32 a0);
void sub_81C7BF8(u32 a0);
void Task_RunLoopedTask_LinkMode(u8 a0);
void Task_RunLoopedTask(u8 taskId);
void sub_81C742C(u8 taskId);
void ShutdownPokenav(void);
static void InitKeys_(void);
static void FreePokenavResources(void);
static void VBlankCB_Pokenav(void);
static void CB2_Pokenav(void);
void InitPokenavMainMenuResources(void);
void sub_81C72BC(void);
void sub_81C7B74(void);
void CleanupPokenavMainMenuResources(void);
void LoadLeftHeaderGfxForSubMenu(u32 arg0);
void LoadLeftHeaderGfxForMenu(u32 arg0);
void HideLeftHeaderSubmenuSprites(bool32 arg0);
void HideLeftHeaderSprites(bool32 arg0);
void ShowLeftHeaderSprites(u32 arg0, bool32 arg1);
void ShowLeftHeaderSubmenuSprites(u32 arg0, bool32 arg1);
void MoveLeftHeader(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3);
void SpriteCB_MoveLeftHeader(struct Sprite *sprite);

// Const rom data.
u32 (*const PokenavMenuCallbacks[15][7])(void) =
{
    {
        sub_81C9298,
        sub_81C941C,
        sub_81C9924,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9298,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9338,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9368,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C92CC,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81C9304,
        sub_81C941C,
        sub_81C9940,
        sub_81C9990,
        sub_81C99C0,
        sub_81C9430,
        sub_81C99D4,
    },
    {
        sub_81CC4D4,
        sub_81CC554,
        sub_81CC5F4,
        sub_81CC62C,
        sub_81CC65C,
        sub_81CC524,
        sub_81CC670,
    },
    {
        sub_81CCFD8,
        sub_81CD070,
        sub_81CDDD4,
        sub_81CDE2C,
        sub_81CDE64,
        sub_81CD1C0,
        sub_81CECA0,
    },
    {
        sub_81CEF3C,
        sub_81CEFDC,
        sub_81CF330,
        sub_81CF3A0,
        sub_81CF3D0,
        sub_81CEFF0,
        sub_81CF3F8,
    },
    {
        sub_81CD024,
        sub_81CD070,
        sub_81CDDD4,
        sub_81CDE2C,
        sub_81CDE64,
        sub_81CD1C0,
        sub_81CECA0,
    },
    {
        sub_81CEF98,
        sub_81CEFDC,
        sub_81CF368,
        sub_81CF3A0,
        sub_81CF3D0,
        sub_81CEFF0,
        sub_81CF3F8,
    },
    {
        sub_81CAAE8,
        sub_81CAB24,
        sub_81CB260,
        sub_81CB29C,
        sub_81CB2CC,
        sub_81CAB38,
        sub_81CB2E0,
    },
    {
        sub_81CF9BC,
        sub_81CFA34,
        sub_81CFDD0,
        sub_81CFE40,
        sub_81CFE70,
        sub_81CFA48,
        sub_81CFE98,
    },
    {
        sub_81D0450,
        sub_81D04A0,
        sub_81D0978,
        sub_81D09B0,
        sub_81D09E0,
        sub_81D04B8,
        sub_81D09F4,
    },
    {
        sub_81CFA04,
        sub_81CFA34,
        sub_81CFE08,
        sub_81CFE40,
        sub_81CFE70,
        sub_81CFA48,
        sub_81CFE98,
    },
};

const u16 gSpinningNavgearPaletteData[] = INCBIN_U16("graphics/pokenav/icon2.gbapal");
const u32 gSpinningNavgearGfx[] = INCBIN_U32("graphics/pokenav/icon2.4bpp.lz");
const u32 gUnused_SpinningNavgearGfx2[] = INCBIN_U32("graphics/pokenav/icon2_unused.4bpp.lz");

const struct BgTemplate gPokenavMainMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    }
};

const struct WindowTemplate gUnknown_0861FA08[2] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 22,
        .width = 16,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x36,
    },
    {
        .bg = 0xFF,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 0,
        .height = 0,
        .paletteNum = 0,
        .baseBlock = 0,
    },
};

const u8 *const (sMenuButtonReminders[12]) =
{
    gText_Navgear_ClearButtonList,
    gText_NavgearMap_ZoomedOutButtons,
    gText_NavgearMap_ZoomedInButtons,
    gText_NavgearCondition_MonListButtons,
    gText_NavgearCondition_MonStatusButtons,
    gText_NavgearCondition_MarkingButtons,
    gText_NavgearMatchCall_TrainerListButtons,
    gText_NavgearMatchCall_CallMenuButtons,
    gText_NavgearMatchCall_CheckTrainerButtons,
    gText_NavgearRibbons_MonListButtons,
    gText_NavgearRibbons_RibbonListButtons,
    gText_NavgearRibbons_RibbonCheckButtons,
};

const u8 gMenuButtonReminderColor[4] =
{
    4, 1, 2, 0
};

static const struct CompressedSpriteSheet gSpinningNavgearSpriteSheet[] =
{
    {
        .data = gSpinningNavgearGfx,
        .size = 0x1000,
        .tag = 0,
    }
};

static const struct SpritePalette gSpinningNavgearPalette[] =
{
    {
        .data = gSpinningNavgearPaletteData,
        .tag = 0,
    },
    {}
};

static const struct CompressedSpriteSheet sPokenavHoenMapLeftHeaderSpriteSheet =
{
    .data = gPokenavLeftHeaderHoennMap_Gfx,
    .size = 0xC00,
    .tag = 2
};

static const struct CompressedSpriteSheet sPokenavMenuLeftHeaderSpriteSheets[] =
{
    [NAVGEAR_GFX_MAIN_MENU] = {
        .data = gPokenavLeftHeaderMainMenu_Gfx,
        .size = 0x20,
        .tag = 3
    },
    [NAVGEAR_GFX_CONDITION_MENU] = {
        .data = gPokenavLeftHeaderCondition_Gfx,
        .size = 0x20,
        .tag = 1
    },
    [NAVGEAR_GFX_RIBBONS_MENU] = {
        .data = gPokenavLeftHeaderRibbons_Gfx,
        .size = 0x20,
        .tag = 2
    },
    [NAVGEAR_GFX_MATCH_CALL_MENU] = {
        .data = gPokenavLeftHeaderMatchCall_Gfx,
        .size = 0x20,
        .tag = 4
    },
    [NAVGEAR_GFX_MAP_MENU_UNK0] = {
        .data = gPokenavLeftHeaderHoennMap_Gfx,
        .size = 0x20,
        .tag = 0
    },
    [NAVGEAR_GFX_MAP_MENU_UNK1] = {
        .data = gPokenavLeftHeaderHoennMap_Gfx,
        .size = 0x40,
        .tag = 0
    }
};

static const struct CompressedSpriteSheetNoSize sPokenavSubMenuLeftHeaderSpriteSheets[] =
{
    [NAVGEAR_GFX_PARTY_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderParty_Gfx,
        .tag = 1
    },
    [NAVGEAR_GFX_SEARCH_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderSearch_Gfx,
        .tag = 1
    },
    [NAVGEAR_GFX_COOL_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderCool_Gfx,
        .tag = 4
    },
    [NAVGEAR_GFX_BEAUTY_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderBeauty_Gfx,
        .tag = 1
    },
    [NAVGEAR_GFX_CUTE_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderCute_Gfx,
        .tag = 2
    },
    [NAVGEAR_GFX_SMART_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderSmart_Gfx,
        .tag = 0
    },
    [NAVGEAR_GFX_TOUGH_MENU - NAVGEAR_GFX_SUBMENUS_START] = {
        .data = gPokenavLeftHeaderTough_Gfx,
        .tag = 0
    }
};

static const struct OamData sSpinningNavgearSpriteOam =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0, // FIXME: Use SPRITE_SHAPE
    .x = 0,
    .matrixNum = 0,
    .size = 2, // FIXME: Use SPRITE_SIZE
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpinningNavgearAnims[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(48, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(80, 8),
    ANIMCMD_FRAME(96, 8),
    ANIMCMD_FRAME(112, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpinningNavgearAnimTable[] =
{
    sSpinningNavgearAnims
};

static const struct SpriteTemplate sSpinningNavgearSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sSpinningNavgearSpriteOam,
    .anims = sSpinningNavgearAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SpinningNavgear
};

static const struct OamData sPokenavLeftHeaderHoenMapSpriteOam =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sUnknown_0861FB24 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct SpriteTemplate sPokenavLeftHeaderHoenMapSpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 1,
    .oam = &sPokenavLeftHeaderHoenMapSpriteOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sUnknown_0861FB44 =
{
    .tileTag = 2,
    .paletteTag = 2,
    .oam = &sUnknown_0861FB24,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u16 sMatchcallArrowPaletteData[] = INCBIN_U16("graphics/pokenav/arrows_matchcall.gbapal");
static const u32 sMatchcallArrowSpriteSheetData[] = INCBIN_U32("graphics/pokenav/arrows_matchcall.4bpp.lz");

static const u8 sPokenavColors_0861FBE4[] =
{
    0, 2, 5
};

static const u8 *const sMatchCallFieldNames[] =
{
    gText_NavgearMatchCall_Strategy,
    gText_NavgearMatchCall_TrainerPokemon,
    gText_NavgearMatchCall_SelfIntroduction
};

static const u8 sMatchCallFieldColors[] =
{
    1, 4, 5
};

static const u8 sUnknown_0861FBF7[] =
{
    2, 4, 6, 7, 0
};

static const struct CompressedSpriteSheet sMatchcallArrowSpriteSheet[] =
{
    {
        .data = sMatchcallArrowSpriteSheetData,
        .size = 192,
        .tag = 0xA
    }
};

static const struct SpritePalette sMatchcallArrowPalette[] =
{
    {
        .data = sMatchcallArrowPaletteData,
        .tag = 0x14
    },
    {}
};

static const struct OamData sMatchCallRightArrowSpriteOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = 2, //SPRITE_SHAPE(16x8),
    .x = 0,
    .size = 0, //SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0
};

static const struct SpriteTemplate sMatchCallRightArrowSprite =
{
    .tileTag = 0xA,
    .paletteTag = 0x14,
    .oam = &sMatchCallRightArrowSpriteOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MatchCallRightArrow
};

static const struct OamData sMatchCallUpDownArrowSpriteOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = 1, //SPRITE_SHAPE(8x16),
    .x = 0,
    .size = 0, //SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0
};

static const struct SpriteTemplate sMatchCallUpDownArrowSprite =
{
    .tileTag = 0xA,
    .paletteTag = 0x14,
    .oam = &sMatchCallUpDownArrowSpriteOam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

EWRAM_DATA u8 gNextLoopedTaskId = 0;
EWRAM_DATA struct PokenavResources *gPokenavResources = NULL;
EWRAM_DATA u32 gUnknown_0203CF44 = 0;

// code
u32 CreateLoopedTask(LoopedTask loopedTask, u32 priority)
{
    u16 taskId;

    if (!IsUpdateLinkStateCBActive())
        taskId = CreateTask(Task_RunLoopedTask, priority);
    else
        taskId = CreateTask(Task_RunLoopedTask_LinkMode, priority);

    SetWordTaskArg(taskId, 1, (u32)loopedTask);

    gTasks[taskId].data[3] = gNextLoopedTaskId;
    return LOOPED_TASK_ID(taskId, gNextLoopedTaskId++);
}

bool32 IsLoopedTaskActive(u32 taskId)
{
    u32 primaryId = LOOPED_TASK_PRIMARY_ID(taskId);
    u32 secondaryId = LOOPED_TASK_SECONDARY_ID(taskId);

    if (gTasks[primaryId].isActive
        && (gTasks[primaryId].func == Task_RunLoopedTask || gTasks[primaryId].func == Task_RunLoopedTask_LinkMode)
        && gTasks[primaryId].data[3] == secondaryId)
        return TRUE;
    else
        return FALSE;
}

bool32 FuncIsActiveLoopedTask(LoopedTask func)
{
    s32 i;
    for (i = 0; i < NUM_TASKS; i++)
    {
        if (gTasks[i].isActive
            && (gTasks[i].func == Task_RunLoopedTask || gTasks[i].func == Task_RunLoopedTask_LinkMode)
            && (LoopedTask)GetWordTaskArg(i, 1) == func)
            return TRUE;
    }
    return FALSE;
}

void Task_RunLoopedTask(u8 taskId)
{
    LoopedTask loopedTask = (LoopedTask)GetWordTaskArg(taskId, 1);
    s16 *state = &gTasks[taskId].data[0];
    bool32 exitLoop = FALSE;

    while (!exitLoop)
    {
        u32 action = loopedTask(*state);
        switch (action)
        {
        case LT_INC_AND_CONTINUE:
            (*state)++;
            break;
        case LT_INC_AND_PAUSE:
            (*state)++;
            return;
        case LT_FINISH:
            DestroyTask(taskId);
            return;
        // case LT_SET_STATE:
        default:
            *state = LOOPED_TASK_DECODE_STATE(action);
            break;
        case LT_CONTINUE:
            break;
        case LT_PAUSE:
            return;
        }
    }
}

// Every "Continue" action pauses instead.
void Task_RunLoopedTask_LinkMode(u8 taskId)
{
    LoopedTask task;
    s16 *state;
    u32 action;

    if (sub_8087598())
        return;
    
    task = (LoopedTask)GetWordTaskArg(taskId, 1);
    state = &gTasks[taskId].data[0];
    action = task(*state);
    switch (action)
    {
    case LT_INC_AND_PAUSE:
    case LT_INC_AND_CONTINUE:
        (*state)++;
        break;
    case LT_FINISH:
        DestroyTask(taskId);
        break;
    // case: LT_SET_STATE:
    default:
        *state = LOOPED_TASK_DECODE_STATE(action);
        break;
    case LT_PAUSE:
    case LT_CONTINUE:
        break;
    }
}

void CB2_InitPokeNav(void)
{
    gPokenavResources = Alloc(sizeof(*gPokenavResources));
    if (gPokenavResources == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
    else
    {
        InitPokenavResources(gPokenavResources);
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(CB2_Pokenav);
        SetVBlankCallback(VBlankCB_Pokenav);
    }
}

void sub_81C72A4(void)
{
    SetMainCallback2(sub_81C72BC);
    FadeScreen(1, 0);
}

void sub_81C72BC(void)
{
    UpdatePaletteFade();
    if (gPaletteFade.active)
        return;

    gPokenavResources = Alloc(sizeof(*gPokenavResources));
    if (gPokenavResources == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else
    {
        InitPokenavResources(gPokenavResources);
        gPokenavResources->mode = MODE_FORCE_CALL_1;
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(CB2_Pokenav);
        SetVBlankCallback(VBlankCB_Pokenav);
    }
}

static void FreePokenavResources(void)
{
    s32 i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        FreePokenavSubstruct(i);

    FREE_AND_SET_NULL(gPokenavResources);
    InitKeys();
}

static void InitPokenavResources(struct PokenavResources *a0)
{
    s32 i;

    for (i = 0; i < SUBSTRUCT_COUNT; i++)
        a0->field10[i] = NULL;

    a0->mode = MODE_NORMAL;
    a0->currentMenuIndex = 0;
    a0->hasAnyRibbons = AnyMonHasRibbon();
    a0->currentMenuCb1 = NULL;
}

static bool32 AnyMonHasRibbon(void)
{
    s32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i],  MON_DATA_SANITY_HAS_SPECIES)
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_RIBBON_COUNT) != 0)
        {
            return TRUE;
        }
    }

    for (j = 0; j < TOTAL_BOXES_COUNT; j++)
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (CheckBoxMonSanityAt(j, i)
                && GetBoxMonDataAt(j, i, MON_DATA_RIBBON_COUNT) != 0)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static void CB2_Pokenav(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Pokenav(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void sub_81C742C(u8 taskId)
{
    u32 v1;
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        InitPokenavMainMenu();
        data[0] = 1;
        break;
    case 1:
        // Wait for LoopedTask_InitPokenavMenu to finish
        if (PokenavMainMenuLoopedTaskIsActive())
            break;
        SetActivePokenavMenu(0 + UNKNOWN_OFFSET);
        data[0] = 4;
        break;
    case 2:
        if (sub_81C786C())
            break;
        data[0] = 3;
    case 3:
        v1 = sub_81C75E0();
        if (v1 == -1)
        {
            ShutdownPokenav();
            data[0] = 5;
        }
        else if (v1 >= UNKNOWN_OFFSET)
        {
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex][NAVMENU_CB_UNK_6]();
            PokenavMenuCallbacks[gPokenavResources->currentMenuIndex][NAVMENU_CB_UNK_5]();
            if (SetActivePokenavMenu(v1))
            {
                data[0] = 4;
            }
            else
            {
                ShutdownPokenav();
                data[0] = 5;
            }
        }
        else if (v1 != 0)
        {
            sub_81C7850(v1);
            if (sub_81C786C())
                data[0] = 2;
        }
        break;
    case 4:
        if (!sub_81C75D4())
            data[0] = 3;
        break;
    case 5:
        if (!WaitForPokenavShutdownFade())
        {
            bool32 calledFromScript = (gPokenavResources->mode != MODE_NORMAL);

            sub_81C9430();
            FreePokenavResources();
            if (calledFromScript)
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            else
                SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        break;
    }
}

bool32 SetActivePokenavMenu(u32 indexWithOffset)
{
    u32 index = indexWithOffset - UNKNOWN_OFFSET;

    InitKeys_();
    if (!PokenavMenuCallbacks[index][NAVMENU_CB_UNK_0]())
        return FALSE;
    if (!PokenavMenuCallbacks[index][NAVMENU_CB_UNK_2]())
        return FALSE;

    sub_81C7834(PokenavMenuCallbacks[index][NAVMENU_CB_UNK_3], PokenavMenuCallbacks[index][NAVMENU_CB_UNK_4]);
    gPokenavResources->currentMenuCb1 = PokenavMenuCallbacks[index][NAVMENU_CB_UNK_1];
    gPokenavResources->currentMenuIndex = index;
    return TRUE;
}

u32 sub_81C75D4(void)
{
    return sub_81C786C();
}

u32 sub_81C75E0(void)
{
    return gPokenavResources->currentMenuCb1();
}

static void InitKeys_(void)
{
    InitKeys();
}

void SetVBlankCallback_(IntrCallback callback)
{
    SetVBlankCallback(callback);
}

void SetPokenavVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_Pokenav);
}

void *AllocSubstruct(u32 index, u32 size)
{
    return gPokenavResources->field10[index] = Alloc(size);
}

void *GetSubstructPtr(u32 index)
{
    return gPokenavResources->field10[index];
}

void FreePokenavSubstruct(u32 index)
{
    if (gPokenavResources->field10[index] != NULL)
        FREE_AND_SET_NULL(gPokenavResources->field10[index]);
}

u16 GetPokenavMode(void)
{
    return gPokenavResources->mode;
}

void SetPokenavMode(u16 mode)
{
    gPokenavResources->mode = mode;
}

void sub_81C7694(u32 a0)
{
    u32 value = a0;

    if (value > 4)
        value = 0;
    gPokenavResources->fieldA = value;
}

u16 sub_81C76AC(void)
{
    return gPokenavResources->fieldA;
}

bool32 CanViewRibbonsMenu(void)
{
    return gPokenavResources->hasAnyRibbons;
}

bool32 InitPokenavMainMenu(void)
{
    struct PokenavMainMenuResources *structPtr;
    
    structPtr = AllocSubstruct(0, sizeof(struct PokenavMainMenuResources));
    if (structPtr == NULL)
        return FALSE;

    ResetSpriteData();
    FreeAllSpritePalettes();
    structPtr->currentTaskId = CreateLoopedTask(LoopedTask_InitPokenavMenu, 1);
    return TRUE;
}

u32 PokenavMainMenuLoopedTaskIsActive(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    return IsLoopedTaskActive(structPtr->currentTaskId);
}

void ShutdownPokenav(void)
{
    PlaySE(SE_PN_OFF);
    sub_81CAADC();
    BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
}

bool32 WaitForPokenavShutdownFade(void)
{
    if (!gPaletteFade.active)
    {
        sub_81C99D4();
        CleanupPokenavMainMenuResources();
        FreeAllWindowBuffers();
        return FALSE;
    }

    return TRUE;
}

u32 LoopedTask_InitPokenavMenu(s32 a0)
{
    struct PokenavMainMenuResources *structPtr;

    switch (a0)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        FreeAllWindowBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gPokenavMainMenuBgTemplates, ARRAY_COUNT(gPokenavMainMenuBgTemplates));
        ResetBgPositions();
        reset_temp_tile_data_buffers();
        return LT_INC_AND_CONTINUE;
    case 1:
        structPtr = GetSubstructPtr(0);
        decompress_and_copy_tile_data_to_vram(0, &gPokenavHeader_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(0, structPtr->tilemapBuffer);
        CopyToBgTilemapBuffer(0, &gPokenavHeader_Tilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(gPokenavHeader_Pal, 0, 0x20);
        CopyBgTilemapBufferToVram(0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;

        sub_81C7B74();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;

        InitPokenavMainMenuResources();
        InitHoenMapHeaderSprites();
        ShowBg(0);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

void sub_81C7834(void *func1, void *func2) // Fix types later.
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->unk0 = func1;
    structPtr->unk4 = func2;
    structPtr->unk8 = 0;
}

void sub_81C7850(u32 a0)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->unk8 = 0;
    structPtr->unk0(a0);
}

u32 sub_81C786C(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    return structPtr->unk4();
}

void sub_81C7880(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->currentTaskId = CreateLoopedTask(LoopedTask_ScrollMenuHeaderDown, 4);
}

void sub_81C78A0(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    structPtr->currentTaskId = CreateLoopedTask(LoopedTask_ScrollMenuHeaderUp, 4);
}

bool32 MainMenuLoopedTaskIsBusy(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);
    return IsLoopedTaskActive(structPtr->currentTaskId);
}

u32 LoopedTask_ScrollMenuHeaderDown(s32 a0)
{
    switch (a0)
    {
    default:
        return LT_FINISH;
    case 1:
        return LT_INC_AND_PAUSE;
    case 0:
        return LT_INC_AND_PAUSE;
    case 2:
        if (ChangeBgY(0, 384, 1) >= 0x2000u)
        {
            ChangeBgY(0, 0x2000, 0);
            return LT_FINISH;
        }

        return LT_PAUSE;
    }
}

u32 LoopedTask_ScrollMenuHeaderUp(s32 a0)
{
    if (ChangeBgY(0, 384, 2) <= 0)
    {
        ChangeBgY(0, 0, 0);
        return 4;
    }
    return 2;
}

void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size)
{
    CpuCopy16(palette, gPlttBufferUnfaded + bufferOffset, size);
}

void Pokenav_AllocAndLoadPalettes(const struct SpritePalette *palettes)
{
    const struct SpritePalette *current;
    u32 index;

    for (current = palettes; current->data != NULL; current++)
    {
        index = AllocSpritePalette(current->tag);
        if (index == 0xFF)
        {
            break;
        }
        else
        {
            index = (index * 16) + 0x100;
            CopyPaletteIntoBufferUnfaded(current->data, index, 0x20);
        }
    }
}

void sub_81C7990(u32 a0, u16 a1)
{
    CpuFill16(a1, gPlttBufferFaded + 0x100 + (a0 * 16), 16 * sizeof(u16));
}

__attribute__((naked))
void sub_81C79BC(u16 *a0, u16 *a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0xC\n\
    str r0, [sp]\n\
    str r1, [sp, 0x4]\n\
    mov r10, r2\n\
    str r3, [sp, 0x8]\n\
    ldr r0, [sp, 0x2C]\n\
    cmp r0, 0\n\
    bne _081C79E4\n\
    ldr r2, =0x001fffff\n\
    mov r1, r10\n\
    ands r2, r1\n\
    ldr r0, [sp]\n\
    b _081C79F4\n\
    .pool\n\
_081C79E4:\n\
    ldr r2, [sp, 0x2C]\n\
    ldr r0, [sp, 0x8]\n\
    cmp r2, r0\n\
    blt _081C7A00\n\
    ldr r2, =0x001fffff\n\
    mov r1, r10\n\
    ands r2, r1\n\
    ldr r0, [sp, 0x4]\n\
_081C79F4:\n\
    ldr r1, [sp, 0x30]\n\
    bl CpuSet\n\
    b _081C7AAE\n\
    .pool\n\
_081C7A00:\n\
    movs r2, 0x1\n\
    negs r2, r2\n\
    add r10, r2\n\
    b _081C7AA6\n\
_081C7A08:\n\
    ldr r1, [sp]\n\
    ldrh r0, [r1]\n\
    movs r2, 0x1F\n\
    mov r9, r2\n\
    mov r1, r9\n\
    ands r1, r0\n\
    mov r9, r1\n\
    lsls r0, 16\n\
    lsrs r2, r0, 21\n\
    movs r1, 0x1F\n\
    ands r1, r2\n\
    mov r8, r1\n\
    lsrs r7, r0, 26\n\
    movs r2, 0x1F\n\
    ands r7, r2\n\
    ldr r0, [sp, 0x4]\n\
    ldrh r4, [r0]\n\
    movs r0, 0x1F\n\
    ands r0, r4\n\
    mov r1, r9\n\
    subs r0, r1\n\
    lsls r0, 8\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r2, [sp, 0x2C]\n\
    adds r6, r0, 0\n\
    muls r6, r2\n\
    asrs r6, 8\n\
    lsls r4, 16\n\
    lsrs r0, r4, 21\n\
    movs r1, 0x1F\n\
    ands r0, r1\n\
    mov r2, r8\n\
    subs r0, r2\n\
    lsls r0, 8\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r1, [sp, 0x2C]\n\
    adds r5, r0, 0\n\
    muls r5, r1\n\
    asrs r5, 8\n\
    lsrs r4, 26\n\
    movs r2, 0x1F\n\
    ands r4, r2\n\
    subs r4, r7\n\
    lsls r4, 8\n\
    adds r0, r4, 0\n\
    ldr r1, [sp, 0x8]\n\
    bl __divsi3\n\
    ldr r1, [sp, 0x2C]\n\
    muls r0, r1\n\
    asrs r0, 8\n\
    add r6, r9\n\
    movs r2, 0x1F\n\
    ands r6, r2\n\
    add r5, r8\n\
    ands r5, r2\n\
    adds r0, r7, r0\n\
    ands r0, r2\n\
    lsls r0, 10\n\
    lsls r5, 5\n\
    orrs r0, r5\n\
    orrs r0, r6\n\
    ldr r1, [sp, 0x30]\n\
    strh r0, [r1]\n\
    ldr r2, [sp]\n\
    adds r2, 0x2\n\
    str r2, [sp]\n\
    ldr r0, [sp, 0x4]\n\
    adds r0, 0x2\n\
    str r0, [sp, 0x4]\n\
    adds r1, 0x2\n\
    str r1, [sp, 0x30]\n\
    movs r1, 0x1\n\
    negs r1, r1\n\
    add r10, r1\n\
_081C7AA6:\n\
    movs r0, 0x1\n\
    negs r0, r0\n\
    cmp r10, r0\n\
    bne _081C7A08\n\
_081C7AAE:\n\
    add sp, 0xC\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided");
}

void sub_81C7AC0(s32 a0)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    switch (a0)
    {
    case 0:
        BeginNormalPaletteFade(structPtr->unk14, -2, 0, 16, RGB_BLACK);
        break;
    case 1:
        BeginNormalPaletteFade(structPtr->unk14, -2, 16, 0, RGB_BLACK);
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, -2, 16, 0, RGB_BLACK);
        break;
    }
}

bool32 IsPaletteFadeActive(void)
{
    return gPaletteFade.active;
}

void sub_81C7B40(void)
{
    BlendPalettes(0xFFFEFFFE, 16, RGB_BLACK);
}

void InitBgTemplates(const struct BgTemplate *templates, s32 count)
{
    s32 i;

    for (i = 0; i < count; i++)
        InitBgFromTemplate(templates++);
}

void sub_81C7B74(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    InitWindows(&gUnknown_0861FA08[0]);
    structPtr->unk10 = 0;
    sub_81C7BF8(structPtr->unk10);
    PutWindowTilemap(structPtr->unk10);
    CopyWindowToVram(structPtr->unk10, 3); // TODO: Use a defined constant here.
}

void sub_81C7BA4(u32 a0)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    sub_81C7BF8(structPtr->unk10);
    AddTextPrinterParameterized3(structPtr->unk10, 1, 0, 1, gMenuButtonReminderColor, 0, sMenuButtonReminders[a0]);
}

bool32 IsDma3ManagerBusyWithBgCopy_(void)
{
    return IsDma3ManagerBusyWithBgCopy();
}

void sub_81C7BF8(u32 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(4));
    FillWindowPixelRect(windowId, PIXEL_FILL(5), 0, 0, 0x80, 1);
}

void InitPokenavMainMenuResources(void)
{
    s32 i;
    u8 spriteId;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    for (i = 0; i < ARRAY_COUNT(gSpinningNavgearSpriteSheet); i++)
        LoadCompressedSpriteSheet(&gSpinningNavgearSpriteSheet[i]);

    Pokenav_AllocAndLoadPalettes(gSpinningNavgearPalette);
    structPtr->unk14 = ~1 & ~(0x10000 << IndexOfSpritePaletteTag(0));
    spriteId = CreateSprite(&sSpinningNavgearSpriteTemplate, 220, 12, 0);
    structPtr->spinningNavgear = &gSprites[spriteId];
}

void CleanupPokenavMainMenuResources(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    DestroySprite(structPtr->spinningNavgear);
    FreeSpriteTilesByTag(0);
    FreeSpritePaletteByTag(0);
}

void SpriteCB_SpinningNavgear(struct Sprite *sprite)
{
    // If the background starts scrolling, follow it.
    sprite->pos2.y = (GetBgY(0) / 256u) * -1;
}

struct Sprite *PauseSpinningNavgearSprite(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    structPtr->spinningNavgear->callback = SpriteCallbackDummy;
    return structPtr->spinningNavgear;
}

void ResumeSpinningNavgearSprite(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    structPtr->spinningNavgear->pos1.x = 220;
    structPtr->spinningNavgear->pos1.y = 12;
    structPtr->spinningNavgear->callback = SpriteCB_SpinningNavgear;
    structPtr->spinningNavgear->invisible = FALSE;
    structPtr->spinningNavgear->oam.priority = 0;
    structPtr->spinningNavgear->subpriority = 0;
}

void InitHoenMapHeaderSprites(void)
{
    s32 i, spriteId;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    LoadCompressedSpriteSheet(&sPokenavHoenMapLeftHeaderSpriteSheet);
    AllocSpritePalette(1);
    AllocSpritePalette(2);
    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        spriteId = CreateSprite(&sPokenavLeftHeaderHoenMapSpriteTemplate, 0, 0, 1);
        structPtr->leftHeaderSprites[i] = &gSprites[spriteId];
        structPtr->leftHeaderSprites[i]->invisible = TRUE;
        structPtr->leftHeaderSprites[i]->pos2.x = i * 64;

        spriteId = CreateSprite(&sUnknown_0861FB44, 0, 0, 2);
        structPtr->submenuLeftHeaderSprites[i] = &gSprites[spriteId];
        structPtr->submenuLeftHeaderSprites[i]->invisible = TRUE;
        structPtr->submenuLeftHeaderSprites[i]->pos2.x = i * 32;
        structPtr->submenuLeftHeaderSprites[i]->pos2.y = 18;
        structPtr->submenuLeftHeaderSprites[i]->oam.tileNum += (i * 8) + 64;
    }
}

void LoadLeftHeaderGfxForIndex(u32 arg0)
{
    if (arg0 < NAVGEAR_GFX_SUBMENUS_START)
        LoadLeftHeaderGfxForMenu(arg0);
    else
        LoadLeftHeaderGfxForSubMenu(arg0 - NAVGEAR_GFX_SUBMENUS_START);
}

void sub_81C7E14(u32 arg0)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (arg0 == 4)
        structPtr->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 32;
    else
        structPtr->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + 64;
}

void LoadLeftHeaderGfxForMenu(u32 index)
{
    struct PokenavMainMenuResources *structPtr;
    u32 size, tag;

    if (index >= NAVGEAR_GFX_SUBMENUS_START)
        return;

    structPtr = GetSubstructPtr(0);
    tag = sPokenavMenuLeftHeaderSpriteSheets[index].tag;
    size = GetDecompressedDataSize(sPokenavMenuLeftHeaderSpriteSheets[index].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(1) * 16) + 0x100, 0x20);
    LZ77UnCompWram(sPokenavMenuLeftHeaderSpriteSheets[index].data, gDecompressionBuffer);
    RequestDma3Copy(gDecompressionBuffer, (void *)VRAM + 0x10000 + (GetSpriteTileStartByTag(2) * 32), size, 1);
    structPtr->leftHeaderSprites[1]->oam.tileNum = GetSpriteTileStartByTag(2) + sPokenavMenuLeftHeaderSpriteSheets[index].size;

    if (index == NAVGEAR_GFX_MAP_MENU_UNK0 || index == NAVGEAR_GFX_MAP_MENU_UNK1)
        structPtr->leftHeaderSprites[1]->pos2.x = 56;
    else
        structPtr->leftHeaderSprites[1]->pos2.x = 64;
}

void LoadLeftHeaderGfxForSubMenu(u32 arg0)
{
    u32 size, tag;

    if (arg0 >= NAVGEAR_GFX_MENUS_END - NAVGEAR_GFX_SUBMENUS_START)
        return;

    tag = sPokenavSubMenuLeftHeaderSpriteSheets[arg0].tag;
    size = GetDecompressedDataSize(sPokenavSubMenuLeftHeaderSpriteSheets[arg0].data);
    LoadPalette(&gPokenavLeftHeader_Pal[tag * 16], (IndexOfSpritePaletteTag(2) * 16) + 0x100, 0x20);
    LZ77UnCompWram(sPokenavSubMenuLeftHeaderSpriteSheets[arg0].data, &gDecompressionBuffer[0x1000]);
    RequestDma3Copy(&gDecompressionBuffer[0x1000], (void *)VRAM + 0x10800 + (GetSpriteTileStartByTag(2) * 32), size, 1);
}

void sub_81C7FA0(u32 arg0, bool32 arg1, bool32 arg2)
{
    u32 var;

    if (!arg1)
        var = 0x30;
    else
        var = 0x10;

    if (arg0 < 6)
        ShowLeftHeaderSprites(var, arg2);
    else
        ShowLeftHeaderSubmenuSprites(var, arg2);
}

void sub_81C7FC4(u32 arg0, bool32 arg1)
{
    if (arg0 < 6)
        HideLeftHeaderSprites(arg1);
    else
        HideLeftHeaderSubmenuSprites(arg1);
}

void sub_81C7FDC(void)
{
    s32 i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        structPtr->leftHeaderSprites[i]->invisible = TRUE;
        structPtr->submenuLeftHeaderSprites[i]->invisible = TRUE;
    }
}

bool32 sub_81C8010(void)
{
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (structPtr->leftHeaderSprites[0]->callback == SpriteCallbackDummy && structPtr->submenuLeftHeaderSprites[0]->callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

void ShowLeftHeaderSprites(u32 startY, bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = -96, end = 32;
    else
        start = 256, end = 160;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        structPtr->leftHeaderSprites[i]->pos1.y = startY;
        MoveLeftHeader(structPtr->leftHeaderSprites[i], start, end, 12);
    }
}

void ShowLeftHeaderSubmenuSprites(u32 startY, bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = -96, end = 16;
    else
        start = 256, end = 192;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->submenuLeftHeaderSprites); i++)
    {
        structPtr->submenuLeftHeaderSprites[i]->pos1.y = startY;
        MoveLeftHeader(structPtr->submenuLeftHeaderSprites[i], start, end, 12);
    }
}

void HideLeftHeaderSprites(bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = 32, end = -96;
    else
        start = 192, end = 256;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->leftHeaderSprites); i++)
    {
        MoveLeftHeader(structPtr->leftHeaderSprites[i], start, end, 12);
    }
}

void HideLeftHeaderSubmenuSprites(bool32 isOnRightSide)
{
    s32 start, end, i;
    struct PokenavMainMenuResources *structPtr = GetSubstructPtr(0);

    if (!isOnRightSide)
        start = 16, end = -96;
    else
        start = 192, end = 256;

    for (i = 0; i < (s32)ARRAY_COUNT(structPtr->submenuLeftHeaderSprites); i++)
    {
        MoveLeftHeader(structPtr->submenuLeftHeaderSprites[i], start, end, 12);
    }
}

void MoveLeftHeader(struct Sprite *sprite, s32 startX, s32 endX, s32 duration)
{
    sprite->pos1.x = startX;
    sprite->data[0] = startX * 16;
    sprite->data[1] = (endX - startX) * 16 / duration;
    sprite->data[2] = duration;
    sprite->data[7] = endX;
    sprite->callback = SpriteCB_MoveLeftHeader;
}

void SpriteCB_MoveLeftHeader(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
    {
        sprite->data[2]--;
        sprite->data[0] += sprite->data[1];
        sprite->pos1.x = sprite->data[0] >> 4;
        if (sprite->pos1.x < -16 || sprite->pos1.x > 256)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->pos1.x = sprite->data[7];
        sprite->callback = SpriteCallbackDummy;
    }
}

bool32 sub_81C81D4(const struct BgTemplate *arg0, struct MatchCallListTemplate *arg1, s32 arg2)
{
    u32 v1;
    struct UnknownSubStruct_81C81D4 *structPtr;
    
    structPtr = AllocSubstruct(0x11, sizeof(struct UnknownSubStruct_81C81D4));

    if (structPtr == NULL)
        return FALSE;
    
    sub_81C9160(&structPtr->unk888, arg1);

    v1 = sub_81C91AC(&structPtr->unk0, arg0, arg1, arg2);
    if (v1 == 0)
        return FALSE;
    
    CreateLoopedTask(LoopedTask_sub_81C8254, 6);
    return TRUE;
}

bool32 sub_81C8224(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_sub_81C8254);
}

void sub_81C8234(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;

    structPtr = GetSubstructPtr(0x11);
    sub_81C8FE0(&structPtr->unk0);
    RemoveWindow(structPtr->unk0.unk0.windowId);
    FreePokenavSubstruct(0x11);
}

u32 LoopedTask_sub_81C8254(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;

    if (IsDma3ManagerBusyWithBgCopy())
        return 2;
    
    structPtr = GetSubstructPtr(0x11);

    switch (a0)
    {
        case 0:
            sub_81C82E4(structPtr);
            return 0;
        case 1:
            sub_81C835C(&structPtr->unk0.unk0);
            return 0;
        case 2:
            sub_81C837C(&structPtr->unk888, &structPtr->unk0);
            return 0;
        case 3:
            if (sub_81C83E0())
            {
                return 2;
            }
            else
            {
                sub_81C8ED0();
                return 1;
            }
        case 4:
            sub_81C8EF8(&structPtr->unk888, &structPtr->unk0);
            return 4;
        default:
            return 4;
    }
}

void sub_81C82E4(struct UnknownSubStruct_81C81D4 *a0)
{
    u16 v1 = (a0->unk0.unk0.unk1 << 12) | a0->unk0.unk0.unk6;
    // TODO: When #553 is merged, use a PALETTE_NUM_TO_FILL_VALUE(1) macro here...
    sub_8199DF0(a0->unk0.unk0.bg, 0x11, a0->unk0.unk0.unk6, 1);
    // ...and PALETTE_NUM_TO_FILL_VALUE(4) here.
    sub_8199DF0(a0->unk0.unk0.bg, 0x44, a0->unk0.unk0.unk6 + 1, 1);
    SetBgTilemapBuffer(a0->unk0.unk0.bg, a0->tilemapBuffer);
    FillBgTilemapBufferRect_Palette0(a0->unk0.unk0.bg, v1, 0, 0, 32, 32);
    ChangeBgY(a0->unk0.unk0.bg, 0, 0);
    ChangeBgX(a0->unk0.unk0.bg, 0, 0);
    ChangeBgY(a0->unk0.unk0.bg, a0->unk0.unk0.unk3 << 11, 2);
    CopyBgTilemapBufferToVram(a0->unk0.unk0.bg);
}

void sub_81C835C(struct UnknownSubSubStruct_0203CF40 *a0)
{
    FillWindowPixelBuffer(a0->windowId, PIXEL_FILL(1));
    PutWindowTilemap(a0->windowId);
    CopyWindowToVram(a0->windowId, 1);
}

void sub_81C837C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    s32 v1;
    s32 v2;

    // TODO: Clean this up.
    v1 = a0->listLength - a0->windowTopIndex;
    v2 = a0->visibleEntries;
    if (v1 > a0->visibleEntries)
        v1 = v2;
    sub_81C83AC(a0->unk10, a0->windowTopIndex, v1, a0->unkC, 0, a1);
}

void sub_81C83AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct UnknownInnerStruct_81C81D4 *a5)
{
    if (a2 == 0)
        return;

    a5->unk1C = a0 + a1 * a3;
    a5->unk18 = a3;
    a5->unk0.unkC = 0;
    a5->unk0.unkE = a2;
    a5->unk14 = a1;
    a5->unk10 = a4;
    CreateLoopedTask(LoopedTask_sub_81C83F0, 5);
}

bool32 sub_81C83E0(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_sub_81C83F0);
}

u32 LoopedTask_sub_81C83F0(s32 a0)
{
    struct UnknownInnerStruct_81C81D4 *structPtr;
    u32 v1;

    structPtr = &((struct UnknownSubStruct_81C81D4*)GetSubstructPtr(0x11))->unk0;
    switch (a0)
    {
    case 0:
        v1 = (structPtr->unk0.unkA + structPtr->unk0.unkC + structPtr->unk10) & 0xF;
        structPtr->unk34(structPtr->unk1C, structPtr->unkTextBuffer);
        if (structPtr->unk38 != NULL)
            // Accessing unk0.windowId as if it were a u16...?
            // It's accessed as a u8 again in the very next line...
            structPtr->unk38(*(u16*)(&structPtr->unk0.windowId), structPtr->unk14, v1);
        
        AddTextPrinterParameterized(structPtr->unk0.windowId, structPtr->unk0.fontId, structPtr->unkTextBuffer, 8, (v1 << 4) + 1, 255, NULL);
        
        if (++structPtr->unk0.unkC >= structPtr->unk0.unkE)
        {
            if (structPtr->unk38 != NULL)
                CopyWindowToVram(structPtr->unk0.windowId, 3);
            else
                CopyWindowToVram(structPtr->unk0.windowId, 2);
            return 0;
        }
        else
        {
            structPtr->unk1C += structPtr->unk18;
            structPtr->unk14++;
            return 3;
        }
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        else
            return 4;
    default:
        return 4;
    }
}

bool32 ShouldShowUpArrow(void)
{
    u16 v1;
    s32 v2;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);

    return structPtr->unk888.windowTopIndex != 0;
}

bool32 ShouldShowDownArrow(void)
{
    struct MatchCallWindowState *subPtr;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    subPtr = &structPtr->unk888;
    
    return subPtr->windowTopIndex + subPtr->visibleEntries < subPtr->listLength;
}


#ifdef NONMATCHING
// This has some register renaming issues (r4, r5, and r6 are all switched around), and
// for some reason it's creating two copies of subPtr->unk0.
// TODO: Now I know why it's making two copies - one of them is UnknownInnerStruct_81C81D4.
void MatchCall_MoveWindow(s32 a0, bool32 a1)
{
    s32 v1;
    struct MatchCallWindowState *subPtr;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    subPtr = &structPtr->unk888;

    if (a0 < 0)
    {
        // This is where the issue is. subPtr->windowTopIndex is being stored in r1 and then copied to
        // r2... and then r2 is read for the if statement, r1 is read for the function call,
        // and then both are clobbered as expected. Between those two uses, no writes to r1/r2
        // happen; it doesn't need to be duplicated/moved at all.
        if (subPtr->windowTopIndex + a0 < 0)
            v1 = -1 * subPtr->windowTopIndex;
        else
            v1 = a0;
        if (a1)
            sub_81C83AC(subPtr->unk10, subPtr->windowTopIndex + v1, v1 * -1, subPtr->unkC, v1, structPtr);
    }
    else if (a1)
    {
        
        gUnknown_0203CF44 = subPtr->windowTopIndex + subPtr->visibleEntries;
        if ((s32)(gUnknown_0203CF44) + a0 >= (s32)subPtr->listLength)
            v1 = subPtr->listLength - gUnknown_0203CF44;
        else
            v1 = a0;
        
        sub_81C83AC(subPtr->unk10, gUnknown_0203CF44, v1, subPtr->unkC, subPtr->visibleEntries, structPtr);
        // Needed to prevent GCC from combining the two sub_81C83AC calls.
        asm("");
    }
    else
    {
        v1 = a0;
    }
    
    sub_81C8568(v1, structPtr);
    subPtr->windowTopIndex++;
}
#else
NAKED
void MatchCall_MoveWindow(s32 a0, bool32 a1)
{
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	sub sp, 0x8\n\
	adds r6, r0, 0\n\
	adds r4, r1, 0\n\
	movs r0, 0x11\n\
	bl GetSubstructPtr\n\
	adds r7, r0, 0\n\
	ldr r0, =0x00000888\n\
	adds r5, r7, r0\n\
	cmp r6, 0\n\
	bge _081C8524\n\
	ldrh r1, [r5]\n\
	adds r0, r1, r6\n\
	cmp r0, 0\n\
	bge _081C850A\n\
	negs r6, r1\n\
_081C850A:\n\
	cmp r4, 0\n\
	beq _081C854E\n\
	ldr r0, [r5, 0x10]\n\
	adds r1, r6\n\
	negs r2, r6\n\
	ldr r3, [r5, 0xC]\n\
	str r6, [sp]\n\
	str r7, [sp, 0x4]\n\
	bl sub_81C83AC\n\
	b _081C854E\n\
	.pool\n\
_081C8524:\n\
	cmp r4, 0\n\
	beq _081C854E\n\
	ldr r2, =gUnknown_0203CF44\n\
	ldrh r1, [r5]\n\
	ldrh r0, [r5, 0x8]\n\
	adds r4, r1, r0\n\
	str r4, [r2]\n\
	adds r0, r4, r6\n\
	ldrh r1, [r5, 0x2]\n\
	cmp r0, r1\n\
	blt _081C853C\n\
	subs r6, r1, r4\n\
_081C853C:\n\
	ldr r0, [r5, 0x10]\n\
	ldr r3, [r5, 0xC]\n\
	ldrh r1, [r5, 0x8]\n\
	str r1, [sp]\n\
	str r7, [sp, 0x4]\n\
	adds r1, r4, 0\n\
	adds r2, r6, 0\n\
	bl sub_81C83AC\n\
_081C854E:\n\
	adds r0, r6, 0\n\
	adds r1, r7, 0\n\
	bl sub_81C8568\n\
	ldrh r0, [r5]\n\
	adds r0, r6\n\
	strh r0, [r5]\n\
	add sp, 0x8\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided");
}
#endif

void sub_81C8568(s32 a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    a1->unk20 = GetBgY(a1->unk0.bg);
    a1->unk24 = a1->unk20 + (a0 << 12);
    if (a0 > 0)
        a1->unk30 = 1;
    else
        a1->unk30 = 2;
    a1->unk2C = a0;
    a1->unk28 = CreateLoopedTask(LoopedTask_sub_81C85A0, 6);
}

u32 LoopedTask_sub_81C85A0(s32 a0)
{
    s32 y;
    s32 v1;
    bool32 flag;
    struct UnknownInnerStruct_81C81D4 *structPtr;
    structPtr = &((struct UnknownSubStruct_81C81D4 *)GetSubstructPtr(0x11))->unk0;
    
    switch (a0)
    {
    case 0:
        if (sub_81C83E0() == FALSE)
            return 1;
        else
            return 2;
    case 1:
        flag = FALSE;
        y = GetBgY(structPtr->unk0.bg);
        v1 = ChangeBgY(structPtr->unk0.bg, 0x1000, structPtr->unk30);
        if (structPtr->unk30 == 2)
        {
            if ((y > structPtr->unk24 || y <= structPtr->unk20) && v1 <= structPtr->unk24)
            {
                flag = TRUE;
            }
        }
        else
        {
            if ((y < structPtr->unk24 || y >= structPtr->unk20) && v1 >= structPtr->unk24)
            {
                flag = TRUE;
            }
        }
        if (flag)
        {
            structPtr->unk0.unkA = (structPtr->unk0.unkA + structPtr->unk2C) & 0xF;
            ChangeBgY(structPtr->unk0.bg, structPtr->unk24, 0);
            return 4;
        }
        else
        {
            return 2;
        }
    default:
        return 4;
    }
}

bool32 sub_81C8630(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    return IsLoopedTaskActive(structPtr->unk0.unk28);
}

struct MatchCallWindowState *GetMatchCallWindowStruct(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    return &structPtr->unk888;
}

u32 MatchCall_MoveCursorUp(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    if (structPtr->selectedIndexOffset != 0)
    {
        structPtr->selectedIndexOffset--;
        return 1;
    }
    else
    {
        if (ShouldShowUpArrow())
        {
            MatchCall_MoveWindow(-1, TRUE);
            return 2;
        }
        else
        {
            return 0;
        }
    }
}

u32 MatchCall_MoveCursorDown(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    if (structPtr->windowTopIndex + structPtr->selectedIndexOffset < structPtr->listLength - 1)
    {
        if (structPtr->selectedIndexOffset < structPtr->visibleEntries - 1)
        {
            structPtr->selectedIndexOffset++;
            return 1;
        }
        else if (!ShouldShowDownArrow())
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    MatchCall_MoveWindow(1, TRUE);
    return 2;
}

u32 MatchCall_PageUp(void)
{
    struct MatchCallWindowState *structPtr;
    s32 scroll;
    
    structPtr = GetMatchCallWindowStruct();
    if (ShouldShowUpArrow())
    {
        if (structPtr->windowTopIndex >= structPtr->visibleEntries)
            scroll = structPtr->visibleEntries;
        else
            scroll = structPtr->windowTopIndex;
        MatchCall_MoveWindow(scroll * -1, TRUE);
        return 2;
    }
    else if (structPtr->selectedIndexOffset != 0)
    {
        structPtr->selectedIndexOffset = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

u32 MatchCall_PageDown(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    if (ShouldShowDownArrow())
    {
        s32 scroll;
        s32 windowBottomIndex;
        s32 v3;
        windowBottomIndex = structPtr->windowTopIndex + structPtr->visibleEntries;
        scroll = structPtr->unk4 - structPtr->windowTopIndex;
        if (windowBottomIndex <= structPtr->unk4)
            scroll = structPtr->visibleEntries;
        MatchCall_MoveWindow(scroll, TRUE);
        return 2;
    }
    else
    {
        s32 cursor;
        s32 lastVisibleIndex;
        if (structPtr->listLength >= structPtr->visibleEntries)
        {
            cursor = structPtr->selectedIndexOffset;
            lastVisibleIndex = structPtr->visibleEntries;
        }
        else
        {
            cursor = structPtr->selectedIndexOffset;
            lastVisibleIndex = structPtr->listLength;
        }
        lastVisibleIndex -= 1;
        if (cursor >= lastVisibleIndex)
        {
            return 0;
        }
        else
        {
            structPtr->selectedIndexOffset = lastVisibleIndex;
            return 1;
        }
    }
}

u32 GetSelectedMatchCall(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();

    return structPtr->windowTopIndex + structPtr->selectedIndexOffset;
}

u32 GetMatchCallListTopIndex(void)
{
    struct MatchCallWindowState *structPtr;
    structPtr = GetMatchCallWindowStruct();
    
    return structPtr->windowTopIndex;
}

void sub_81C877C(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8870, 6);
}

void sub_81C87AC(u16 a0)
{
    u16 temp;
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    temp = structPtr->unk888.windowTopIndex;
    temp += a0;
    structPtr->unk888.windowTopIndex = temp;
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8958, 6);
}

void sub_81C87F0(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    structPtr->unk89C = 0;
    structPtr->unk8A0 = CreateLoopedTask(LoopedTask_sub_81C8A28, 6);
}

bool32 sub_81C8820(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    return IsLoopedTaskActive(structPtr->unk8A0);
}

void sub_81C8838(void)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    struct MatchCallWindowState *subStr;
    structPtr = GetSubstructPtr(0x11);
    subStr = &structPtr->unk888;
    structPtr->unk0.unk38(structPtr->unk0.unk0.windowId, subStr->windowTopIndex + subStr->selectedIndexOffset, (structPtr->unk0.unk0.unkA + subStr->selectedIndexOffset) & 0xF);
    CopyWindowToVram(structPtr->unk0.unk0.windowId, 1);
}

u32 LoopedTask_sub_81C8870(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    u16 v1;
    u32 v2;

    // Needed to fix a register renaming issue.
    register u16* temp asm("r1");
    structPtr = GetSubstructPtr(0x11);

    switch (a0)
    {
    case 0:
        ToggleMatchCallArrows(&structPtr->unk0, 1);
        // fall-through
    case 1:
        if (structPtr->unk89C != structPtr->unk888.selectedIndexOffset)
            sub_81C8B70(&structPtr->unk0.unk0, structPtr->unk89C, 1);
        
        structPtr->unk89C++;
        return 0;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        
        if (structPtr->unk89C != structPtr->unk888.visibleEntries)
            return 6;
        
        if (structPtr->unk888.selectedIndexOffset != 0)
            sub_81C8B70(&structPtr->unk0.unk0, structPtr->unk89C, structPtr->unk888.selectedIndexOffset);
        
        return 0;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        temp = &structPtr->unk888.selectedIndexOffset;
        v1 = *temp;
        if (v1 == 0)
            return 4;
        
        MatchCall_MoveWindow(v1, FALSE);
        return 0;
    case 4:
         v2 = sub_81C8630();
         if (v2)
            return 2;

        structPtr->unk888.selectedIndexOffset = v2;
        return 4;
    default:
        return 4;
    }
}

u32 LoopedTask_sub_81C8958(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    if (IsDma3ManagerBusyWithBgCopy())
        return 2;
    
    switch (a0)
    {
    case 0:
        sub_81C8CB4(&structPtr->unk888, &structPtr->unk0);
        break;
    case 1:
        PrintMatchCallFieldNames(&structPtr->unk0, 0);
        break;
    case 2:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 0);
        break;
    case 3:
        PrintMatchCallFieldNames(&structPtr->unk0, 1);
        break;
    case 4:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 1);
        break;
    case 5:
        PrintMatchCallFieldNames(&structPtr->unk0, 2);
        break;
    case 6:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 2);
        break;
    case 7:
        sub_81C8E54(&structPtr->unk888, &structPtr->unk0, 3);
        break;
    default:
        return 4;
    }
    return 0;
}

u32 LoopedTask_sub_81C8A28(s32 a0)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    struct MatchCallWindowState *subPtr888;
    register struct UnknownInnerStruct_81C81D4 *subPtr0 asm("r2");
    s32 v4;

    if (IsDma3ManagerBusyWithBgCopy())
    {
        return 2;
    }
    
    structPtr = GetSubstructPtr(0x11);
    subPtr888 = &structPtr->unk888;
    subPtr0 = &structPtr->unk0;

    switch (a0)
    {
    default:
        return 4;
    case 0:
        sub_81C8D4C(subPtr888, subPtr0);
        return 0;
    case 1:
    {
        s32 v1;
        s32 v2;
        u32 *v3;
        register s32 v4 asm("r5");

        v3 = &structPtr->unk89C;
        v1 = *v3 + 1;
        *v3 = v1;
        if (v1 < structPtr->unk888.visibleEntries)
        {
            sub_81C8B70(&subPtr0->unk0, v1, 1);
            return 2;
        }

        *v3 = 0;
        if (subPtr888->listLength <= subPtr888->visibleEntries)
        {
            register u32 temp asm("r0");
            temp = subPtr888->windowTopIndex;
            if (temp == 0)
                return 9;
            v2 = temp;
        }
        else
        {
            register s32 temp asm("r1");
            v2 = subPtr888->windowTopIndex + subPtr888->visibleEntries;
            temp = (s32)subPtr888->listLength;
            if (v2 <= temp)
                return 9;
            v2 -= temp;
        }
        v4 = v2 * -1;
        sub_81C8B70(&subPtr0->unk0, v4, v2);
        subPtr888->selectedIndexOffset = v2;
        *v3 = v4;
        return 0;
    }
    case 2:
        MatchCall_MoveWindow(structPtr->unk89C, FALSE);
        return 0;
    case 3:
        if (sub_81C8630())
            return 2;
        
        structPtr->unk89C = 0;
        return 1;
    case 4:
        sub_81C83AC(subPtr888->unk10, subPtr888->windowTopIndex + structPtr->unk89C, 1, subPtr888->unkC, structPtr->unk89C, &structPtr->unk0);
        return 0;
    case 5:
        if (sub_81C83E0())
            return 2;
        
        v4 = ++structPtr->unk89C;
        if (v4 >= subPtr888->listLength || v4 >= subPtr888->visibleEntries)
            return 1;
        return 9;
    case 6:
        ToggleMatchCallArrows(subPtr0, 0);
        return 4;
    }
}

void sub_81C8B70(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1, u32 a2)
{
    u8 *v1;
    u32 v2;

    v1 = (u8*)GetWindowAttribute(a0->windowId, WINDOW_TILE_DATA);
    v2 = a0->unk4 * 64;

    a1 = (a0->unkA + a1) & 0xF;
    if ((s32)(a1 + a2) <= 16)
    {
        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, a2 * v2);
        CopyWindowToVram(a0->windowId, 2);
    }
    else
    {
        u32 v3;
        u32 v4;

        v3 = 16 - a1;
        v4 = a2 - v3;

        CpuFastFill8(PIXEL_FILL(1), v1 + a1 * v2, v3 * v2);
        CpuFastFill8(PIXEL_FILL(1), v1, v4 * v2);
        CopyWindowToVram(a0->windowId, 2);
    }

    a2 -= 1;
    for (a2; a2 != -1; a1 = (a1 + 1) & 0xF, a2--)
    {
        sub_81CBD48(a0->windowId, a1);
    }

    CopyWindowToVram(a0->windowId, 1);
}

void sub_81C8C64(struct UnknownSubSubStruct_0203CF40 *a0, u32 a1)
{
    u16 *v1;
    register u32 v2 asm("r0");
    u32 v3;

    v1 = (u16*)GetBgTilemapBuffer(GetWindowAttribute(a0->windowId, WINDOW_BG));

    v1 = &v1[(a0->unkA << 6) + a0->unk2 - 1];

    if (a1 != 0)
    {
        v2 = a0->unk1 << 12;
        v3 = a0->unk6 + 1;
    }
    else
    {
        v2 = a0->unk1 << 12;
        v3 = a0->unk6;
    }
    {
        register u16 v5 asm("r1");
        register u32 v6 asm("r0");
        v6 = (v3 | v2);
        v6 = v6 << 16;
        v5 = v6 >> 16;
        v1[0] = v5;
        v1[0x20] = v5;
    }
}

void sub_81C8CB4(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    u8 colors[3];


    memcpy(colors, sPokenavColors_0861FBE4, ARRAY_COUNT(sPokenavColors_0861FBE4));

    a1->unk34(a0->unk10 + a0->unkC * a0->windowTopIndex, a1->unkTextBuffer);
    a1->unk38(a1->unk0.windowId, a0->windowTopIndex, a1->unk0.unkA);
    FillWindowPixelRect(a1->unk0.windowId, PIXEL_FILL(4), 0, a1->unk0.unkA * 16, a1->unk0.unk4 * 8, 16);
    AddTextPrinterParameterized3(a1->unk0.windowId, a1->unk0.fontId, 8, (a1->unk0.unkA * 16) + 1, colors, TEXT_SPEED_FF, a1->unkTextBuffer);
    sub_81C8C64(&a1->unk0, 1);
    CopyWindowRectToVram(a1->unk0.windowId, 3, 0, a1->unk0.unkA * 2, a1->unk0.unk4, 2);
}

void sub_81C8D4C(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    a1->unk34(a0->unk10 + a0->unkC * a0->windowTopIndex, a1->unkTextBuffer);
    FillWindowPixelRect(a1->unk0.windowId, PIXEL_FILL(1), 0, a1->unk0.unkA * 16, a1->unk0.unk4 * 8, 16);
    AddTextPrinterParameterized(a1->unk0.windowId, a1->unk0.fontId, a1->unkTextBuffer, 8, a1->unk0.unkA * 16 + 1, TEXT_SPEED_FF, NULL);
    sub_81C8C64(&a1->unk0, 0);
    CopyWindowToVram(a1->unk0.windowId, 3);
}

void PrintMatchCallFieldNames(struct UnknownInnerStruct_81C81D4 *a0, u32 fieldId)
{
    const u8 *fieldNames[3];
    u8 colors[3];
    u32 r4;
    u32 r5;
    u32 tmp;
    u32 one;

    memcpy(fieldNames, sMatchCallFieldNames, sizeof(sMatchCallFieldNames));
    memcpy(colors, sMatchCallFieldColors, sizeof(sMatchCallFieldColors));

    r4 = a0->unk0.unkA;
    tmp = fieldId * 2 + 1;
    r4 += tmp;
    r4 &= 0xF;
    FillWindowPixelRect(a0->unk0.windowId, PIXEL_FILL(1), 0, r4 << 4, a0->unk0.unk4, 16);
    
    // This is a fake match. It should be this:
    // AddTextPrinterParameterized3(a0->unk0.windowId, 7, 2, r4 << 4 + 1, colors, TEXT_SPEED_FF, fieldNames[fieldId]);
    // But the original GCC does some clever reuse of the `1` constant that the current GCC doesn't.
    one = 1;
    AddTextPrinterParameterized3(a0->unk0.windowId, 7, 2, (r4 << 4) + one, colors, one - 2, fieldNames[fieldId]);
    CopyWindowRectToVram(a0->unk0.windowId, 2, 0, r4 << 1, a0->unk0.unk4, 2);
}

void sub_81C8E54(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1, u32 a2)
{
    const u8 *str;
    u32 r6;

    r6 = (a1->unk0.unkA + sUnknown_0861FBF7[a2]) & 0xF;

    str = sub_81CAFD8(a0->windowTopIndex, a2);
    if (str != NULL) {
        sub_81DB620(a1->unk0.windowId, 1, r6 * 2, a1->unk0.unk4 - 1, 2);
        AddTextPrinterParameterized(a1->unk0.windowId, 7, str, 2, (r6 << 4) + 1, TEXT_SPEED_FF, NULL);
        CopyWindowRectToVram(a1->unk0.windowId, 2, 0, r6 * 2, a1->unk0.unk4, 2);
    }
}

void sub_81C8ED0(void)
{
    u32 i;
    const struct CompressedSpriteSheet *ptr;
    
    for (i = 0, ptr = sMatchcallArrowSpriteSheet; i < ARRAY_COUNT(sMatchcallArrowSpriteSheet); ptr++, i++)
    {
        LoadCompressedSpriteSheet(ptr);
    }
    Pokenav_AllocAndLoadPalettes(sMatchcallArrowPalette);
}

void sub_81C8EF8(struct MatchCallWindowState *a0, struct UnknownInnerStruct_81C81D4 *a1)
{
    register u32 spriteId asm("r3");
    s16 temp;

    spriteId = (u8)CreateSprite(&sMatchCallRightArrowSprite, a1->unk0.unk2 * 8 + 3, (a1->unk0.unk3 + 1) * 8, 7);
    a1->rightArrow = &gSprites[spriteId];

    temp = a1->unk0.unk2 * 8 + (a1->unk0.unk4 - 1) * 4;
    spriteId = (u8)CreateSprite(&sMatchCallUpDownArrowSprite, temp, a1->unk0.unk3 * 8 + a0->visibleEntries * 16, 7);
    a1->downArrow = &gSprites[spriteId];
    a1->downArrow->oam.tileNum += 2;
    a1->downArrow->callback = SpriteCB_MatchCallDownArrow;

    spriteId = (u8)CreateSprite(&sMatchCallUpDownArrowSprite, temp, a1->unk0.unk3 * 8, 7);
    a1->upArrow = &gSprites[spriteId];
    a1->upArrow->oam.tileNum += 4;
    a1->upArrow->callback = SpriteCB_MatchCallUpArrow;
}

void sub_81C8FE0(struct UnknownInnerStruct_81C81D4 *a0)
{
    DestroySprite(a0->rightArrow);
    DestroySprite(a0->upArrow);
    DestroySprite(a0->downArrow);
    FreeSpriteTilesByTag(0xA);
    FreeSpritePaletteByTag(0x14);
}

void ToggleMatchCallArrows(struct UnknownInnerStruct_81C81D4 *a0, bool32 shouldHide)
{
    if (shouldHide)
    {
        a0->rightArrow->callback = SpriteCallbackDummy;
        a0->upArrow->callback = SpriteCallbackDummy;
        a0->downArrow->callback = SpriteCallbackDummy;
    }
    else
    {
        a0->rightArrow->callback = SpriteCB_MatchCallRightArrow;
        a0->upArrow->callback = SpriteCB_MatchCallUpArrow;
        a0->downArrow->callback = SpriteCB_MatchCallDownArrow;
    }
    a0->rightArrow->invisible = shouldHide;
    a0->upArrow->invisible = shouldHide;
    a0->downArrow->invisible = shouldHide;
}

void SpriteCB_MatchCallRightArrow(struct Sprite *sprite)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    sprite->pos2.y = structPtr->unk888.selectedIndexOffset << 4;
}

void SpriteCB_MatchCallDownArrow(struct Sprite *sprite)
{
    if (sprite->data[7] == 0 && ShouldShowDownArrow())
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;
    
    if (++sprite->data[0] > 3)
    {
        s16 offset;

        sprite->data[0] = 0;
        offset = (sprite->data[1] + 1) & 7;
        sprite->data[1] = offset;
        sprite->pos2.y = offset;
    }
}

void SpriteCB_MatchCallUpArrow(struct Sprite *sprite)
{
    if (sprite->data[7] == 0 && ShouldShowUpArrow())
        sprite->invisible = FALSE;
    else
        sprite->invisible = TRUE;
    
    if (++sprite->data[0] > 3)
    {
        s16 offset;

        sprite->data[0] = 0;
        offset = (sprite->data[1] + 1) & 7;
        sprite->data[1] = offset;
        sprite->pos2.y = -1 * offset;
    }
}

void ToggleMatchCallVerticalArrows(bool32 shouldHide)
{
    struct UnknownSubStruct_81C81D4 *structPtr;
    structPtr = GetSubstructPtr(0x11);
    structPtr->unk0.upArrow->data[7] = shouldHide;
    structPtr->unk0.downArrow->data[7] = shouldHide;
}

void sub_81C9160(struct MatchCallWindowState *a0, struct MatchCallListTemplate *a1)
{
    u32 unused1 = a0->unk10 = a1->unk0;
    u32 v0 = a1->unk6;
    u32 zero = 0;
    u32 unused2 = a0->windowTopIndex = v0;
    u32 v1 = a0->listLength = a1->unk4;

    a0->unkC = a1->unk8;
    a0->visibleEntries = a1->unkC;
    if (a0->visibleEntries >= (u16)v1)
    {
        a0->windowTopIndex = 0;
        a0->unk4 = 0;
        a0->selectedIndexOffset = v0; 
    }
    else
    {
        s32 v2;
        a0->unk4 = a0->listLength - a0->visibleEntries;
        v2 = a0->windowTopIndex + a0->visibleEntries;
        if (v2 > a0->listLength) {
            a0->selectedIndexOffset = v2 - a0->listLength;
            a0->windowTopIndex = v0 - a0->selectedIndexOffset;
        }
        else
        {
            a0->selectedIndexOffset = 0;
        }
    }
}

u32 sub_81C91AC(struct UnknownInnerStruct_81C81D4 *a0, const struct BgTemplate *a1, struct MatchCallListTemplate *a2, s32 a3)
{
    register u32 raw_bg asm("r4") = ((a1->bg) << 30);
    u8 bg = raw_bg >> 30;
    u32 unknown = 0;
    struct WindowTemplate window;
    u8 bg_again;

    a0->unk0.bg = bg;
    a0->unk0.unk6 = a3;
    a0->unk34 = a2->unk10;
    a0->unk38 = a2->unk14;
    a0->unk0.unk1 = a2->unkD;
    a0->unk0.unk2 = a2->unk9;
    a0->unk0.unk3 = a2->unkB;
    a0->unk0.unk4 = a2->unkA;
    a0->unk0.fontId = a2->unkE;
    
    window.bg = raw_bg >> 30;
    window.tilemapLeft = a2->unk9;
    window.tilemapTop = 0;
    window.width = a2->unkA;
    window.height = 32;
    window.paletteNum = a2->unkD;
    window.baseBlock = a3 + 2;

    a0->unk0.windowId = AddWindow(&window);
    if (a0->unk0.windowId == 0xFF)
    {
        return 0;
    }
    else
    {
        a0->unk0.unkA = unknown;
        a0->rightArrow = NULL;
        a0->upArrow = NULL;
        a0->downArrow = NULL;
        return 1;
    }
}