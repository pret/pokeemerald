#include "global.h"
#include "battle.h"
#include "battle_factory_screen.h"
#include "battle_factory.h"
#include "sprite.h"
#include "event_data.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "text.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "alloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "string_util.h"
#include "international_string_util.h"
#include "window.h"
#include "data.h"
#include "decompress.h"
#include "pokemon_summary_screen.h"
#include "sound.h"
#include "pokedex.h"
#include "util.h"
#include "trainer_pokemon_sprites.h"
#include "constants/battle_frontier.h"
#include "constants/songs.h"
#include "constants/rgb.h"

// Select_ refers to the first Pokemon selection screen where you choose 3 Pokemon.
// Swap_   refers to the consecutive selection screen where you can keep your Pokemon or swap one with beaten trainer's.

#define MENU_SUMMARY 0
#define MENU_RENT 1
#define MENU_DESELECT 1
#define MENU_OTHERS 2
#define MENU_OPTIONS_COUNT 3

#define SELECTABLE_MONS_COUNT 6

#define TAG_PAL_BALL_GREY 0x64
#define TAG_PAL_BALL_SELECTED 0x65
#define TAG_PAL_66 0x66
#define TAG_PAL_67 0x67

#define TAG_TILE_64 0x64
#define TAG_TILE_65 0x65
#define TAG_TILE_66 0x66
#define TAG_TILE_67 0x67
#define TAG_TILE_68 0x68
#define TAG_TILE_69 0x69
#define TAG_TILE_6A 0x6A
#define TAG_TILE_6B 0x6B
#define TAG_TILE_6C 0x6C
#define TAG_TILE_6D 0x6D

struct FactorySelecteableMon
{
    u16 monSetId;
    u16 spriteId;
    u8 selectedId; // 0 - not selected, 1 - first pokemon, 2 - second pokemon, 3 - third pokemon
    struct Pokemon monData;
};

struct UnkFactoryStruct
{
    u8 field0;
    u8 field1;
};

struct FactorySelectMonsStruct
{
    u8 menuCursorPos;
    u8 menuCursor1SpriteId;
    u8 menuCursor2SpriteId;
    u8 cursorPos;
    u8 cursorSpriteId;
    u8 selectingMonsState;
    bool8 fromSummaryScreen;
    u8 yesNoCursorPos;
    u8 unused8;
    struct FactorySelecteableMon mons[SELECTABLE_MONS_COUNT];
    struct UnkFactoryStruct unk294[3];
    bool8 unk2A0;
    u8 fadeSpeciesNameTaskId;
    bool8 unk2A2;
    u16 unk2A4;
    bool8 unk2A6;
    u8 unk2A7;
    u8 unk2A8;
    u8 unk2A9;
};

// 'Action' refers to the 3 Selectable mons, Cancel, Pknm for swap windows.
#define ACTIONS_PLAYER_SCREEN 0
#define ACTIONS_ENEMY_SCREEN 1

struct SwapActionIdAndFunc
{
    u8 id;
    void (*func)(u8 taskId);
};

struct FactorySwapMonsStruct
{
    u8 menuCursorPos;
    u8 menuCursor1SpriteId;
    u8 menuCursor2SpriteId;
    u8 cursorPos;
    u8 cursorSpriteId;
    u8 ballSpriteIds[3];
    u8 unk8[2][3];
    u8 unkE[2][2];
    u8 playerMonId;
    u8 enemyMonId;
    bool8 inEnemyScreen;
    bool8 fromSummaryScreen;
    u8 yesNoCursorPos;
    u8 actionsCount;
    const struct SwapActionIdAndFunc *actionsData;
    u8 unused1C[4];
    bool8 monSwapped;
    u8 fadeSpeciesNameTaskId;
    bool8 unk22;
    u16 unk24;
    bool8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    struct UnkFactoryStruct unk2C;
    bool8 unk30;
};

extern const u32 gUnknown_085B18AC[];

// This file's functions.
static void sub_819A44C(struct Sprite *sprite);
static void CB2_InitSelectScreen(void);
static void Select_SetWinRegs(s16 mWin0H, s16 nWin0H, s16 mWin0V, s16 nWin0V);
static void Select_InitMonsData(void);
static void Select_InitAllSprites(void);
static void Select_ShowSummaryMonSprite(void);
static void Select_PrintSelectMonString(void);
static void Select_PrintMonSpecies(void);
static void Select_PrintMonCategory(void);
static void Select_PrintRentalPkmnString(void);
static void Select_CopyMonsToPlayerParty(void);
static void sub_819C4B4(void);
static void Select_ShowYesNoOptions(void);
static void sub_819C568(void);
static void Select_ShowMenuOptions(void);
static void Select_PrintMenuOptions(void);
static void Select_PrintYesNoOptions(void);
static void Task_SelectFadeSpeciesName(u8 taskId);
static void sub_819C1D0(u8 taskId);
static void Task_HandleSelectionScreenChooseMons(u8 taskId);
static void Task_HandleSelectionScreenMenu(u8 taskId);
static void CreateFrontierFactorySelectableMons(u8 firstMonId);
static void CreateTentFactorySelectableMons(u8 firstMonId);
static void Select_SetBallSpritePaletteNum(u8 id);
static void sub_819F444(struct UnkFactoryStruct arg0, bool8 *arg1);
static void sub_819B958(u8 windowId);
static void sub_819F2B4(u8 *arg0, bool8 *arg1, bool8 swapScreen);
static void sub_819F3F8(struct UnkFactoryStruct arg0, bool8 *arg1, bool8 swapScreen);
static u8 Select_RunMenuOptionFunc(void);
static u8 sub_819BC9C(void);
static u8 Select_OptionSummary(void);
static u8 Select_OptionOthers(void);
static u8 Select_OptionRentDeselect(void);
static bool32 Select_AreSpeciesValid(u16 monSetId);
static void Swap_DestroyAllSprites(void);
static void Swap_ShowYesNoOptions(void);
static void sub_819E8EC(void);
static void sub_819EAC0(void);
static void Swap_UpdateYesNoCursorPosition(s8 direction);
static void Swap_UpdateMenuCursorPosition(s8 direction);
static void sub_819EA64(u8 windowId);
static void sub_819D770(u8 taskId);
static void Task_HandleSwapScreenChooseMons(u8 taskId);
static void sub_819D588(u8 taskId);
static void sub_819F7B4(u8 taskId);
static void Swap_PrintOnInfoWindow(const u8 *str);
static void Swap_ShowMenuOptions(void);
static void Swap_PrintMenuOptions(void);
static void Swap_PrintYesNoOptions(void);
static void Swap_PrintMonSpecies(void);
static void Swap_PrintMonSpecies2(void);
static void Swap_PrintMonSpecies3(void);
static void Swap_PrintMonCategory(void);
static void Swap_InitAllSprites(void);
static void Swap_PrintPkmnSwap(void);
static void sub_819EADC(void);
static void sub_819EAF8(void);
static void CB2_InitSwapScreen(void);
static void Swap_ShowSummaryMonSprite(void);
static void Swap_UpdateActionCursorPosition(s8 direction);
static void Swap_UpdateBallCursorPosition(s8 direction);
static void Swap_RunMenuOptionFunc(u8 taskId);
static void sub_819F0CC(u8 taskId);
static void sub_819F114(u8 taskId);
static void sub_819F134(u8 taskId);
static void Swap_RunActionFunc(u8 taskId);
static void sub_819F69C(u8 taskId);
static void Task_SwapCantHaveSameMons(u8 taskId);
static void Swap_ShowMonSprite(void);
static void Swap_PrintActionStrings(void);
static void Swap_PrintActionStrings2(void);
static void Swap_PrintOneActionString(u8 which);
static void Swap_InitActions(u8 id);
static void sub_819E838(u8 arg0);
static bool8 Swap_AlreadyHasSameSpecies(u8 monId);
static void sub_819F600(struct Sprite *sprite);
static void Swap_ActionMon(u8 taskId);
static void Swap_ActionCancel(u8 taskId);
static void Swap_ActionPkmnForSwap(u8 taskId);

// Ewram variables
static EWRAM_DATA u8 *sSelectMenuTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSelectMonCardBgTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSelectMenuTilemapBuffer = NULL;
static EWRAM_DATA u8 *sSelectMonCardBgTilemapBuffer = NULL;
static EWRAM_DATA struct Pokemon *sFactorySelectMons = NULL;
static EWRAM_DATA u8 *sSwapMenuTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSwapMonCardBgTilesetBuffer = NULL;
static EWRAM_DATA u8 *sSwapMenuTilemapBuffer = NULL;
static EWRAM_DATA u8 *sSwapMonCardBgTilemapBuffer = NULL;

// IWRAM bss
static IWRAM_DATA struct FactorySelectMonsStruct *sFactorySelectScreen;
static IWRAM_DATA void (*sSwap_CurrentTableFunc)(u8 taskId);
static IWRAM_DATA struct FactorySwapMonsStruct *sFactorySwapScreen;

// IWRAM common
u8 (*gUnknown_030062E8)(void);

// Const rom data.
static const u16 gUnknown_0860F13C[] = INCBIN_U16("graphics/unknown/unknown_60F13C.gbapal");
static const u16 gUnknown_0860F15C[] = INCBIN_U16("graphics/unknown/unknown_60F15C.gbapal");
static const u16 gUnknown_0860F17C[] = INCBIN_U16("graphics/unknown/unknown_60F17C.gbapal");
static const u8 gUnknown_0860F1BC[] = INCBIN_U8("graphics/unknown/unknown_60F1BC.4bpp");
static const u8 gUnknown_0860F3BC[] = INCBIN_U8("graphics/unknown/unknown_60F3BC.4bpp");
static const u8 gUnknown_0860F43C[] = INCBIN_U8("graphics/unknown/unknown_60F43C.4bpp");
static const u8 gUnknown_0860F53C[] = INCBIN_U8("graphics/unknown/unknown_60F53C.4bpp");
static const u8 gUnknown_0860F63C[] = INCBIN_U8("graphics/unknown/unknown_60F63C.4bpp");
static const u8 gUnknown_0860F6BC[] = INCBIN_U8("graphics/unknown/unknown_60F6BC.4bpp");
static const u8 gUnknown_0860F7BC[] = INCBIN_U8("graphics/unknown/unknown_60F7BC.4bpp");
static const u8 gUnknown_0860F83C[] = INCBIN_U8("graphics/unknown/unknown_60F83C.4bpp");
static const u8 gUnknown_0860F93C[] = INCBIN_U8("graphics/unknown/unknown_60F93C.4bpp");
static const u8 gUnknown_0860FA3C[] = INCBIN_U8("graphics/unknown/unknown_60FA3C.4bpp");
static const u8 gUnknown_0861023C[] = INCBIN_U8("graphics/unknown/unknown_61023C.bin");
static const u8 gUnknown_0861033C[] = INCBIN_U8("graphics/unknown/unknown_61033C.4bpp");
static const u16 gUnknown_0861039C[] = INCBIN_U16("graphics/unknown/unknown_61039C.gbapal");

static const struct SpriteSheet gUnknown_086103BC[] =
{
    {gUnknown_0860F3BC, sizeof(gUnknown_0860F3BC), TAG_TILE_65},
    {gUnknown_0860F43C, sizeof(gUnknown_0860F43C), TAG_TILE_66},
    {gUnknown_0860F53C, sizeof(gUnknown_0860F53C), TAG_TILE_67},
    {gUnknown_0860FA3C, sizeof(gUnknown_0860FA3C), TAG_TILE_6D},
    {},
};

static const struct CompressedSpriteSheet gUnknown_086103E4[] =
{
    {gUnknown_085B18AC, 0x800, TAG_TILE_64},
    {},
};

static const struct SpritePalette gUnknown_086103F4[] =
{
    {gUnknown_0860F13C, TAG_PAL_BALL_GREY},
    {gUnknown_0860F15C, TAG_PAL_BALL_SELECTED},
    {gUnknown_0860F17C, TAG_PAL_66},
    {gUnknown_0861039C, TAG_PAL_67},
    {},
};

u8 static (* const sSelect_MenuOptionFuncs[])(void) =
{
    [MENU_SUMMARY] = Select_OptionSummary,
    [MENU_RENT] /*Or Deselect*/ = Select_OptionRentDeselect,
    [MENU_OTHERS] = Select_OptionOthers
};

static const struct BgTemplate sSelect_BgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct WindowTemplate sSelect_WindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0001,
    },
    {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 11,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x0019,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 15,
        .width = 20,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x002f,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 14,
        .width = 8,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x006b,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 14,
        .width = 8,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x009b,
    },
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 0,
        .width = 15,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x00bb,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u16 gUnknown_0861046C[] = INCBIN_U16("graphics/unknown/unknown_61046C.gbapal");

static const u8 gUnknown_08610476[] = {0x00, 0x02, 0x00};
static const u8 gUnknown_08610479[] = {0x00, 0x04, 0x00};

static const struct OamData gUnknown_0861047C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_08610484 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_0861048C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_08610494 =
{
    .y = 0,
    .affineMode = 3,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 1,
};

static const union AnimCmd gUnknown_0861049C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_086104A4[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_086104AC[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_086104B4[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd * const gUnknown_086104FC[] =
{
    gUnknown_0861049C,
};

static const union AnimCmd * const gUnknown_08610500[] =
{
    gUnknown_086104A4,
};

static const union AnimCmd * const gUnknown_08610504[] =
{
    gUnknown_086104AC,
    gUnknown_086104B4,
};

static const union AffineAnimCmd gUnknown_0861050C[] =
{
    AFFINEANIMCMD_FRAME(5, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(16, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(32, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(64, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(128, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(256, 5, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_0861056C[] =
{
    AFFINEANIMCMD_FRAME(128, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(64, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(32, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(16, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(5, 5, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_086105BC[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd * const gUnknown_086105CC[] =
{
    gUnknown_0861050C,
    gUnknown_0861056C,
    gUnknown_086105BC,
};

static const struct SpriteTemplate gUnknown_086105D8 =
{
    .tileTag = TAG_TILE_64,
    .paletteTag = TAG_PAL_BALL_GREY,
    .oam = &gUnknown_0861047C,
    .anims = gUnknown_08610504,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_819A44C
};

static const struct SpriteTemplate gUnknown_086105F0 =
{
    .tileTag = TAG_TILE_65,
    .paletteTag = TAG_PAL_66,
    .oam = &gUnknown_08610484,
    .anims = gUnknown_086104FC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_08610608 =
{
    .tileTag = TAG_TILE_66,
    .paletteTag = TAG_PAL_66,
    .oam = &gUnknown_0861048C,
    .anims = gUnknown_086104FC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_08610620 =
{
    .tileTag = TAG_TILE_67,
    .paletteTag = TAG_PAL_66,
    .oam = &gUnknown_0861048C,
    .anims = gUnknown_086104FC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_08610638 =
{
    .tileTag = TAG_TILE_6D,
    .paletteTag = TAG_PAL_67,
    .oam = &gUnknown_08610494,
    .anims = gUnknown_08610500,
    .images = NULL,
    .affineAnims = gUnknown_086105CC,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet gUnknown_08610650[] =
{
    {gUnknown_0860F3BC, sizeof(gUnknown_0860F3BC), TAG_TILE_65},
    {gUnknown_0860F43C, sizeof(gUnknown_0860F43C), TAG_TILE_66},
    {gUnknown_0860F53C, sizeof(gUnknown_0860F53C), TAG_TILE_67},
    {gUnknown_0860F63C, sizeof(gUnknown_0860F63C), TAG_TILE_68},
    {gUnknown_0860F6BC, sizeof(gUnknown_0860F6BC), TAG_TILE_69},
    {gUnknown_0860F7BC, 0x100, TAG_TILE_6A},
    {gUnknown_0860F83C, sizeof(gUnknown_0860F83C), TAG_TILE_6B},
    {gUnknown_0860F93C, sizeof(gUnknown_0860F93C), TAG_TILE_6C},
    {gUnknown_0860FA3C, sizeof(gUnknown_0860FA3C), TAG_TILE_6D},
    {},
};

static const struct CompressedSpriteSheet gUnknown_086106A0[] =
{
    {gUnknown_085B18AC, 0x800, TAG_TILE_64},
    {},
};

static const struct SpritePalette gUnknown_086106B0[] =
{
    {gUnknown_0860F13C, TAG_PAL_BALL_GREY},
    {gUnknown_0860F15C, TAG_PAL_BALL_SELECTED},
    {gUnknown_0860F17C, TAG_PAL_66},
    {gUnknown_0861039C, TAG_PAL_67},
    {},
};

static const struct OamData gUnknown_086106D8 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_086106E0 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_086106E8 =
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
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_086106F0 =
{
    .y = 0,
    .affineMode = 3,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 1,
};

static const union AnimCmd gUnknown_086106F8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_08610700[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_08610708[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_08610710[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd * const gUnknown_08610758[] =
{
    gUnknown_086106F8,
};

static const union AnimCmd * const gUnknown_0861075C[] =
{
    gUnknown_08610700,
};

static const union AnimCmd * const gUnknown_08610760[] =
{
    gUnknown_08610708,
    gUnknown_08610710,
};

static const union AffineAnimCmd gUnknown_08610768[] =
{
    AFFINEANIMCMD_FRAME(5, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(16, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(32, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(64, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(128, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(256, 5, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_086107C8[] =
{
    AFFINEANIMCMD_FRAME(128, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(64, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(32, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(16, 5, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(5, 5, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_08610818[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd * const gUnknown_08610828[] =
{
    gUnknown_08610768,
    gUnknown_086107C8,
    gUnknown_08610818,
};

static const struct SpriteTemplate gUnknown_08610834 =
{
    .tileTag = TAG_TILE_64,
    .paletteTag = TAG_PAL_BALL_GREY,
    .oam = &gUnknown_086106D8,
    .anims = gUnknown_08610760,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_819A44C
};

static const struct SpriteTemplate gUnknown_0861084C =
{
    .tileTag = TAG_TILE_65,
    .paletteTag = TAG_PAL_66,
    .oam = &gUnknown_086106E0,
    .anims = gUnknown_08610758,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_08610864 =
{
    .tileTag = TAG_TILE_66,
    .paletteTag = TAG_PAL_66,
    .oam = &gUnknown_086106E8,
    .anims = gUnknown_08610758,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_0861087C =
{
    .tileTag = TAG_TILE_67,
    .paletteTag = TAG_PAL_66,
    .oam = &gUnknown_086106E8,
    .anims = gUnknown_08610758,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate gUnknown_08610894 =
{
    .tileTag = TAG_TILE_6D,
    .paletteTag = TAG_PAL_67,
    .oam = &gUnknown_086106F0,
    .anims = gUnknown_0861075C,
    .images = NULL,
    .affineAnims = gUnknown_08610828,
    .callback = SpriteCallbackDummy
};

void static (* const sSwap_MenuOptionFuncs[])(u8 taskId) =
{
    sub_819F114,
    sub_819F0CC,
    sub_819F134,
};

static const struct BgTemplate sSwap_BgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct WindowTemplate sSwap_WindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0001,
    },
    {
        .bg = 2,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 11,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x0019,
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 15,
        .width = 20,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x002f,
    },
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 14,
        .width = 9,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x006b,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 14,
        .width = 8,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x00a1,
    },
    {
        .bg = 2,
        .tilemapLeft = 21,
        .tilemapTop = 15,
        .width = 9,
        .height = 5,
        .paletteNum = 14,
        .baseBlock = 0x006b,
    },
    {
        .bg = 2,
        .tilemapLeft = 10,
        .tilemapTop = 2,
        .width = 4,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x00c1,
    },
    {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 11,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x00c9,
    },
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 0,
        .width = 15,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x00df,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u16 gUnknown_08610918[] = {RGB_BLACK, RGB_BLACK, RGB_WHITE, RGB_BLACK, RGB_RED}; // Palette.
static const u8 gUnknown_08610922[] = {0x0, 0x02, 0x0};
static const u8 gUnknown_08610925[] = {0x0, 0x04, 0x0};

static const struct SwapActionIdAndFunc sSwap_PlayerScreenActions[] =
{
    {1, Swap_ActionMon},
    {1, Swap_ActionMon},
    {1, Swap_ActionMon},
    {3, Swap_ActionCancel},
};

static const struct SwapActionIdAndFunc sSwap_EnemyScreenActions[] =
{
    {1, Swap_ActionMon},
    {1, Swap_ActionMon},
    {1, Swap_ActionMon},
    {2, Swap_ActionPkmnForSwap},
    {3, Swap_ActionCancel},
};

// gfx
extern const u8 gFrontierFactorySelectMenu_Gfx[];
extern const u8 gFrontierFactorySelectMenu_Tilemap[];
extern const u16 gFrontierFactorySelectMenu_Pal[];

// text
extern const u8 gText_RentalPkmn2[];
extern const u8 gText_SelectFirstPkmn[];
extern const u8 gText_SelectSecondPkmn[];
extern const u8 gText_SelectThirdPkmn[];
extern const u8 gText_TheseThreePkmnOkay[];
extern const u8 gText_CantSelectSamePkmn[];
extern const u8 gText_Summary[];
extern const u8 gText_Rechoose[];
extern const u8 gText_Deselect[];
extern const u8 gText_Rent[];
extern const u8 gText_Others2[];
extern const u8 gText_Yes2[];
extern const u8 gText_Yes3[];
extern const u8 gText_No2[];
extern const u8 gText_No3[];
extern const u8 gText_QuitSwapping[];
extern const u8 gText_AcceptThisPkmn[];
extern const u8 gText_SelectPkmnToAccept[];
extern const u8 gText_SelectPkmnToSwap[];
extern const u8 gText_PkmnSwap[];
extern const u8 gText_Swap[];
extern const u8 gText_Summary2[];
extern const u8 gText_PkmnForSwap[];
extern const u8 gText_SamePkmnInPartyAlready[];
extern const u8 gText_Cancel3[];

// code
static void sub_819A44C(struct Sprite *sprite)
{
    if (sprite->oam.paletteNum == IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED))
    {
        if (sprite->animEnded)
        {
            if (sprite->data[0] != 0)
            {
                sprite->data[0]--;
            }
            else if (Random() % 5 == 0)
            {
                StartSpriteAnim(sprite, 0);
                sprite->data[0] = 32;
            }
            else
            {
                StartSpriteAnim(sprite, 1);
            }
        }
        else
        {
            StartSpriteAnimIfDifferent(sprite, 1);
        }
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
    }
}

static void Select_CB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void Select_VblankCb(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void DoBattleFactorySelectScreen(void)
{
    sFactorySelectScreen = NULL;
    SetMainCallback2(CB2_InitSelectScreen);
}

static void CB2_InitSelectScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        if (sFactorySelectMons != NULL)
            FREE_AND_SET_NULL(sFactorySelectMons);
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSelect_BgTemplates, ARRAY_COUNT(sSelect_BgTemplates));
        InitWindows(sSelect_WindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        sSelectMenuTilesetBuffer = Alloc(0x440);
        sSelectMonCardBgTilesetBuffer = AllocZeroed(0x440);
        sSelectMenuTilemapBuffer = Alloc(0x800);
        sSelectMonCardBgTilemapBuffer = AllocZeroed(0x800);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        CpuCopy16(gFrontierFactorySelectMenu_Gfx, sSelectMenuTilesetBuffer, 0x440);
        CpuCopy16(gUnknown_0861033C, sSelectMonCardBgTilesetBuffer, 0x60);
        LoadBgTiles(1, sSelectMenuTilesetBuffer, 0x440, 0);
        LoadBgTiles(3, sSelectMonCardBgTilesetBuffer, 0x60, 0);
        CpuCopy16(gFrontierFactorySelectMenu_Tilemap, sSelectMenuTilemapBuffer, 0x800);
        LoadBgTilemap(1, sSelectMenuTilemapBuffer, 0x800, 0);
        LoadPalette(gFrontierFactorySelectMenu_Pal, 0, 0x40);
        LoadPalette(gUnknown_0861046C, 0xF0, 8);
        LoadPalette(gUnknown_0861046C, 0xE0, 10);
        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
            gPlttBufferUnfaded[228] = sFactorySelectScreen->unk2A4;
        LoadPalette(gUnknown_0861039C, 0x20, 4);
        gMain.state++;
        break;
    case 3:
        SetBgTilemapBuffer(3, sSelectMonCardBgTilemapBuffer);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C, 11, 4, 8, 8);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C,  2, 4, 8, 8);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C, 20, 4, 8, 8);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        LoadSpritePalettes(gUnknown_086103F4);
        LoadSpriteSheets(gUnknown_086103BC);
        LoadCompressedSpriteSheet(gUnknown_086103E4);
        ShowBg(0);
        ShowBg(1);
        SetVBlankCallback(Select_VblankCb);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_1D_MAP);
        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
        {
            Select_SetWinRegs(88, 152, 32, 96);
            ShowBg(3);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        }
        else
        {
            HideBg(3);
        }
        gMain.state++;
        break;
    case 5:
        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
            sFactorySelectScreen->cursorPos = gLastViewedMonIndex;
        Select_InitMonsData();
        Select_InitAllSprites();
        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
            Select_ShowSummaryMonSprite();
        gMain.state++;
        break;
    case 6:
        Select_PrintSelectMonString();
        PutWindowTilemap(2);
        gMain.state++;
        break;
    case 7:
        Select_PrintMonCategory();
        PutWindowTilemap(5);
        gMain.state++;
        break;
    case 8:
        Select_PrintMonSpecies();
        PutWindowTilemap(1);
        gMain.state++;
        break;
    case 9:
        Select_PrintRentalPkmnString();
        PutWindowTilemap(0);
        gMain.state++;
        break;
    case 10:
        sFactorySelectScreen->fadeSpeciesNameTaskId = CreateTask(Task_SelectFadeSpeciesName, 0);
        if (!sFactorySelectScreen->fromSummaryScreen)
        {
            gTasks[sFactorySelectScreen->fadeSpeciesNameTaskId].data[0] = 0;
            taskId = CreateTask(Task_HandleSelectionScreenChooseMons, 0);
            gTasks[taskId].data[0] = 0;
        }
        else
        {
            gTasks[sFactorySelectScreen->fadeSpeciesNameTaskId].data[0] = 1;
            sFactorySelectScreen->unk2A2 = FALSE;
            taskId = CreateTask(Task_HandleSelectionScreenMenu, 0);
            gTasks[taskId].data[0] = 13;
        }
        SetMainCallback2(Select_CB2);
        break;
    }
}

static void Select_InitMonsData(void)
{
    u8 i;

    if (sFactorySelectScreen != NULL)
        return;

    sFactorySelectScreen = AllocZeroed(sizeof(*sFactorySelectScreen));
    sFactorySelectScreen->cursorPos = 0;
    sFactorySelectScreen->selectingMonsState = 1;
    sFactorySelectScreen->fromSummaryScreen = FALSE;
    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
        sFactorySelectScreen->mons[i].selectedId = 0;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        CreateFrontierFactorySelectableMons(0);
    else
        CreateTentFactorySelectableMons(0);
}

static void Select_InitAllSprites(void)
{
    u8 i, cursorPos;
    s16 x;

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        sFactorySelectScreen->mons[i].spriteId = CreateSprite(&gUnknown_086105D8, (35 * i) + 32, 64, 1);
        gSprites[sFactorySelectScreen->mons[i].spriteId].data[0] = 0;
        Select_SetBallSpritePaletteNum(i);
    }
    cursorPos = sFactorySelectScreen->cursorPos;
    x = gSprites[sFactorySelectScreen->mons[cursorPos].spriteId].pos1.x;
    sFactorySelectScreen->cursorSpriteId = CreateSprite(&gUnknown_086105F0, x, 88, 0);
    sFactorySelectScreen->menuCursor1SpriteId = CreateSprite(&gUnknown_08610608, 176, 112, 0);
    sFactorySelectScreen->menuCursor2SpriteId = CreateSprite(&gUnknown_08610620, 176, 144, 0);

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = TRUE;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = TRUE;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySelectScreen->menuCursor1SpriteId].centerToCornerVecY = 0;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].centerToCornerVecY = 0;
}

static void Select_DestroyAllSprites(void)
{
    u8 i;

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
        DestroySprite(&gSprites[sFactorySelectScreen->mons[i].spriteId]);

    DestroySprite(&gSprites[sFactorySelectScreen->cursorSpriteId]);
    DestroySprite(&gSprites[sFactorySelectScreen->menuCursor1SpriteId]);
    DestroySprite(&gSprites[sFactorySelectScreen->menuCursor2SpriteId]);
}

static void Select_UpdateBallCursorPosition(s8 direction)
{
    u8 cursorPos;
    if (direction > 0) // Move cursor right.
    {
        if (sFactorySelectScreen->cursorPos != SELECTABLE_MONS_COUNT - 1)
            sFactorySelectScreen->cursorPos++;
        else
            sFactorySelectScreen->cursorPos = 0;
    }
    else // Move cursor left.
    {
        if (sFactorySelectScreen->cursorPos != 0)
            sFactorySelectScreen->cursorPos--;
        else
            sFactorySelectScreen->cursorPos = SELECTABLE_MONS_COUNT - 1;
    }

    cursorPos = sFactorySelectScreen->cursorPos;
    gSprites[sFactorySelectScreen->cursorSpriteId].pos1.x = gSprites[sFactorySelectScreen->mons[cursorPos].spriteId].pos1.x;
}

static void Select_UpdateMenuCursorPosition(s8 direction)
{
    if (direction > 0) // Move cursor down.
    {
        if (sFactorySelectScreen->menuCursorPos != MENU_OPTIONS_COUNT - 1)
            sFactorySelectScreen->menuCursorPos++;
        else
            sFactorySelectScreen->menuCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (sFactorySelectScreen->menuCursorPos != 0)
            sFactorySelectScreen->menuCursorPos--;
        else
            sFactorySelectScreen->menuCursorPos = MENU_OPTIONS_COUNT - 1;
    }

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.y = (sFactorySelectScreen->menuCursorPos * 16) + 112;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.y = (sFactorySelectScreen->menuCursorPos * 16) + 112;
}

static void Select_UpdateYesNoCursorPosition(s8 direction)
{
    if (direction > 0) // Move cursor down.
    {
        if (sFactorySelectScreen->yesNoCursorPos != 1)
            sFactorySelectScreen->yesNoCursorPos++;
        else
            sFactorySelectScreen->yesNoCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (sFactorySelectScreen->yesNoCursorPos != 0)
            sFactorySelectScreen->yesNoCursorPos--;
        else
            sFactorySelectScreen->yesNoCursorPos = 1;
    }

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.y = (sFactorySelectScreen->yesNoCursorPos * 16) + 112;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.y = (sFactorySelectScreen->yesNoCursorPos * 16) + 112;
}

static void Select_HandleMonSelectionChange(void)
{
    u8 i, paletteNum;
    u8 cursorPos = sFactorySelectScreen->cursorPos;
    if (sFactorySelectScreen->mons[cursorPos].selectedId) // Deselect a mon.
    {
        paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_GREY);
        if (sFactorySelectScreen->selectingMonsState == 3 && sFactorySelectScreen->mons[cursorPos].selectedId == 1)
        {
            for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
            {
                if (sFactorySelectScreen->mons[i].selectedId == 2)
                    break;
            }
            if (i == SELECTABLE_MONS_COUNT)
                return;
            else
                sFactorySelectScreen->mons[i].selectedId = 1;
        }
        sFactorySelectScreen->mons[cursorPos].selectedId = 0;
        sFactorySelectScreen->selectingMonsState--;
    }
    else // Select a mon.
    {
        paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED);
        sFactorySelectScreen->mons[cursorPos].selectedId = sFactorySelectScreen->selectingMonsState;
        sFactorySelectScreen->selectingMonsState++;
    }

    gSprites[sFactorySelectScreen->mons[cursorPos].spriteId].oam.paletteNum = paletteNum;
}

static void Select_SetBallSpritePaletteNum(u8 id)
{
    u8 palNum;

    if (sFactorySelectScreen->mons[id].selectedId)
        palNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED);
    else
        palNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_GREY);

    gSprites[sFactorySelectScreen->mons[id].spriteId].oam.paletteNum = palNum;
}

static void Task_FromSelectScreenToSummaryScreen(u8 taskId)
{
    u8 i;
    u8 currMonId;

    switch (gTasks[taskId].data[0])
    {
    case 6:
        gPlttBufferUnfaded[228] = gPlttBufferFaded[228];
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].data[0] = 7;
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            DestroyTask(sFactorySelectScreen->fadeSpeciesNameTaskId);
            sub_819F444(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0);
            Select_DestroyAllSprites();
            FREE_AND_SET_NULL(sSelectMenuTilesetBuffer);
            FREE_AND_SET_NULL(sSelectMonCardBgTilesetBuffer);
            FREE_AND_SET_NULL(sSelectMenuTilemapBuffer);
            FREE_AND_SET_NULL(sSelectMonCardBgTilemapBuffer);
            FreeAllWindowBuffers();
            gTasks[taskId].data[0] = 8;
        }
        break;
    case 8:
        sFactorySelectScreen->unk2A4 = gPlttBufferUnfaded[228];
        DestroyTask(taskId);
        sFactorySelectScreen->fromSummaryScreen = TRUE;
        currMonId = sFactorySelectScreen->cursorPos;
        sFactorySelectMons = AllocZeroed(sizeof(struct Pokemon) * SELECTABLE_MONS_COUNT);
        for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
            sFactorySelectMons[i] = sFactorySelectScreen->mons[i].monData;
        ShowPokemonSummaryScreen(1, sFactorySelectMons, currMonId, SELECTABLE_MONS_COUNT - 1, CB2_InitSelectScreen);
        break;
    }
}

static void Task_CloseSelectionScreen(u8 taskId)
{
    if (sFactorySelectScreen->unk2A0 != TRUE)
    {
        switch (gTasks[taskId].data[0])
        {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0]++;
            break;
        case 1:
            if (!UpdatePaletteFade())
            {
                Select_CopyMonsToPlayerParty();
                DestroyTask(sFactorySelectScreen->fadeSpeciesNameTaskId);
                Select_DestroyAllSprites();
                FREE_AND_SET_NULL(sSelectMenuTilesetBuffer);
                FREE_AND_SET_NULL(sSelectMenuTilemapBuffer);
                FREE_AND_SET_NULL(sSelectMonCardBgTilemapBuffer);
                FREE_AND_SET_NULL(sFactorySelectScreen);
                FreeAllWindowBuffers();
                SetMainCallback2(CB2_ReturnToFieldContinueScript);
                DestroyTask(taskId);
            }
            break;
        }
    }
}

static void Task_HandleSelectionScreenYesNo(u8 taskId)
{
    if (sFactorySelectScreen->unk2A0 != TRUE)
    {
        switch (gTasks[taskId].data[0])
        {
        case 10:
            sub_819C4B4();
            gTasks[taskId].data[0] = 4;
            break;
        case 4:
            Select_ShowYesNoOptions();
            gTasks[taskId].data[0] = 5;
            break;
        case 5:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                if (sFactorySelectScreen->yesNoCursorPos == 0)
                {
                    sub_819C568();
                    gTasks[taskId].data[0] = 0;
                    gTasks[taskId].func = Task_CloseSelectionScreen;
                }
                else
                {
                    sub_819B958(4);
                    sub_819BC9C();
                    sFactorySelectScreen->unk2A2 = TRUE;
                    gTasks[taskId].data[0] = 1;
                    gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                sub_819B958(4);
                sub_819BC9C();
                sFactorySelectScreen->unk2A2 = TRUE;
                gTasks[taskId].data[0] = 1;
                gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_UP)
            {
                PlaySE(SE_SELECT);
                Select_UpdateYesNoCursorPosition(-1);
            }
            else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
            {
                PlaySE(SE_SELECT);
                Select_UpdateYesNoCursorPosition(1);
            }
            break;
        }
    }
}

static void Task_HandleSelectionScreenMenu(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 2:
        if (!sFactorySelectScreen->fromSummaryScreen)
            sub_819F2B4(&sFactorySelectScreen->unk294[1].field1, &sFactorySelectScreen->unk2A0, FALSE);
        gTasks[taskId].data[0] = 9;
        break;
    case 9:
        if (sFactorySelectScreen->unk2A0 != TRUE)
        {
            Select_ShowMenuOptions();
            sFactorySelectScreen->fromSummaryScreen = FALSE;
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 3:
        if (gMain.newKeys & A_BUTTON)
        {
            u8 retVal;
            PlaySE(SE_SELECT);
            retVal = Select_RunMenuOptionFunc();
            if (retVal == 1)
            {
                sFactorySelectScreen->unk2A2 = TRUE;
                gTasks[taskId].data[0] = 1;
                gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
            }
            else if (retVal == 2)
            {
                gTasks[taskId].data[0] = 10;
                gTasks[taskId].func = Task_HandleSelectionScreenYesNo;
            }
            else if (retVal == 3)
            {
                gTasks[taskId].data[0] = 11;
                gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
            }
            else
            {
                gTasks[taskId].data[0] = 6;
                gTasks[taskId].func = Task_FromSelectScreenToSummaryScreen;
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, FALSE);
            sub_819B958(3);
            sFactorySelectScreen->unk2A2 = TRUE;
            gTasks[taskId].data[0] = 1;
            gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
        }
        else if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            Select_UpdateMenuCursorPosition(-1);
        }
        else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            Select_UpdateMenuCursorPosition(1);
        }
        break;
    case 12:
        if (!gPaletteFade.active)
        {
            if (sFactorySelectScreen->fromSummaryScreen == TRUE)
            {
                gPlttBufferFaded[228] = sFactorySelectScreen->unk2A4;
                gPlttBufferUnfaded[228] = gPlttBufferUnfaded[244];
            }
            sFactorySelectScreen->fromSummaryScreen = FALSE;
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 13:
        Select_ShowMenuOptions();
        gTasks[taskId].data[0] = 12;
        break;
    }
}

static void Task_HandleSelectionScreenChooseMons(u8 taskId)
{
    if (sFactorySelectScreen->unk2A0 != TRUE)
    {
        switch (gTasks[taskId].data[0])
        {
        case 0:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].data[0] = 1;
                sFactorySelectScreen->unk2A2 = TRUE;
            }
            break;
        case 1:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                sFactorySelectScreen->unk2A2 = FALSE;
                gTasks[taskId].data[0] = 2;
                gTasks[taskId].func = Task_HandleSelectionScreenMenu;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
            {
                PlaySE(SE_SELECT);
                Select_UpdateBallCursorPosition(-1);
                Select_PrintMonCategory();
                Select_PrintMonSpecies();
            }
            else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
            {
                PlaySE(SE_SELECT);
                Select_UpdateBallCursorPosition(1);
                Select_PrintMonCategory();
                Select_PrintMonSpecies();
            }
            break;
        case 11:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, FALSE);
                Select_PrintSelectMonString();
                sFactorySelectScreen->unk2A2 = TRUE;
                gTasks[taskId].data[0] = 1;
            }
            break;
        }
    }
}

static void CreateFrontierFactorySelectableMons(u8 firstMonId)
{
    u8 i, j = 0;
    u8 ivs = 0;
    u8 level = 0;
    u8 happiness = 0;
    u32 otId = 0;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
    u8 var_28 = 0;

    gFacilityTrainerMons = gBattleFrontierMons;
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        level = 100;
    else
        level = 50;

    var_28 = GetNumPastRentalsRank(battleMode, lvlMode);
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        u16 monSetId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
        sFactorySelectScreen->mons[i + firstMonId].monSetId = monSetId;
        if (i < var_28)
            ivs = GetFactoryMonFixedIV(challengeNum + 1, 0);
        else
            ivs = GetFactoryMonFixedIV(challengeNum, 0);
        CreateMonWithEVSpreadNatureOTID(&sFactorySelectScreen->mons[i + firstMonId].monData,
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             ivs,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);
        happiness = 0;
        for (j = 0; j < MAX_MON_MOVES; j++)
            SetMonMoveAvoidReturn(&sFactorySelectScreen->mons[i + firstMonId].monData, gFacilityTrainerMons[monSetId].moves[j], j);
        SetMonData(&sFactorySelectScreen->mons[i + firstMonId].monData, MON_DATA_FRIENDSHIP, &happiness);
        SetMonData(&sFactorySelectScreen->mons[i + firstMonId].monData, MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
    }
}

static void CreateTentFactorySelectableMons(u8 firstMonId)
{
    u8 i, j;
    u8 ivs = 0;
    u8 level = 30;
    u8 happiness = 0;
    u32 otId = 0;

    gFacilityTrainerMons = gSlateportBattleTentMons;
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        u16 monSetId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
        sFactorySelectScreen->mons[i + firstMonId].monSetId = monSetId;
        CreateMonWithEVSpreadNatureOTID(&sFactorySelectScreen->mons[i + firstMonId].monData,
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             ivs,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);
        happiness = 0;
        for (j = 0; j < MAX_MON_MOVES; j++)
            SetMonMoveAvoidReturn(&sFactorySelectScreen->mons[i + firstMonId].monData, gFacilityTrainerMons[monSetId].moves[j], j);
        SetMonData(&sFactorySelectScreen->mons[i + firstMonId].monData, MON_DATA_FRIENDSHIP, &happiness);
        SetMonData(&sFactorySelectScreen->mons[i + firstMonId].monData, MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
    }
}

static void Select_CopyMonsToPlayerParty(void)
{
    u8 i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < SELECTABLE_MONS_COUNT; j++)
        {
            if (sFactorySelectScreen->mons[j].selectedId == i + 1)
            {
                gPlayerParty[i] = sFactorySelectScreen->mons[j].monData;
                gSaveBlock2Ptr->frontier.rentalMons[i].monId = sFactorySelectScreen->mons[j].monSetId;
                gSaveBlock2Ptr->frontier.rentalMons[i].personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY, NULL);
                gSaveBlock2Ptr->frontier.rentalMons[i].abilityBit = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ABILITY_NUM, NULL);
                gSaveBlock2Ptr->frontier.rentalMons[i].ivs = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ATK_IV, NULL);
                break;
            }
        }
    }
    CalculatePlayerPartyCount();
}

static void Select_ShowMenuOptions(void)
{
    if (!sFactorySelectScreen->fromSummaryScreen)
        sFactorySelectScreen->menuCursorPos = 0;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.x = 176;
    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.y = (sFactorySelectScreen->menuCursorPos * 16) + 112;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.x = 208;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.y = (sFactorySelectScreen->menuCursorPos * 16) + 112;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = FALSE;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = FALSE;

    Select_PrintMenuOptions();
}

static void Select_ShowYesNoOptions(void)
{
    sFactorySelectScreen->yesNoCursorPos = 0;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.x = 176;
    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.y = 112;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.x = 208;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.y = 112;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = FALSE;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = FALSE;

    Select_PrintYesNoOptions();
}

static void sub_819B958(u8 windowId)
{
    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = TRUE;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = TRUE;
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    CopyWindowToVram(windowId, 2);
    ClearWindowTilemap(windowId);
}

static void Select_PrintRentalPkmnString(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    AddTextPrinterParameterized(0, 1, gText_RentalPkmn2, 2, 1, 0, NULL);
    CopyWindowToVram(0, 3);
}

static void Select_PrintMonSpecies(void)
{
    u16 species;
    u8 x;
    u8 monId = sFactorySelectScreen->cursorPos;

    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    species = GetMonData(&sFactorySelectScreen->mons[monId].monData, MON_DATA_SPECIES, NULL);
    StringCopy(gStringVar4, gSpeciesNames[species]);
    x = GetStringRightAlignXOffset(1, gStringVar4, 86);
    AddTextPrinterParameterized3(1, 1, x, 1, gUnknown_08610479, 0, gStringVar4);
    CopyWindowToVram(1, 2);
}

static void Select_PrintSelectMonString(void)
{
    const u8 *str = NULL;

    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    if (sFactorySelectScreen->selectingMonsState == 1)
        str = gText_SelectFirstPkmn;
    else if (sFactorySelectScreen->selectingMonsState == 2)
        str = gText_SelectSecondPkmn;
    else if (sFactorySelectScreen->selectingMonsState == 3)
        str = gText_SelectThirdPkmn;
    else
        str = gText_TheseThreePkmnOkay;

    AddTextPrinterParameterized(2, 1, str, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

static void Select_PrintCantSelectSameMon(void)
{
    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    AddTextPrinterParameterized(2, 1, gText_CantSelectSamePkmn, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

static void Select_PrintMenuOptions(void)
{
    u8 selectedId = sFactorySelectScreen->mons[sFactorySelectScreen->cursorPos].selectedId;

    PutWindowTilemap(3);
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    AddTextPrinterParameterized3(3, 1, 7, 1, gUnknown_08610476, 0, gText_Summary);
    if (selectedId != 0)
        AddTextPrinterParameterized3(3, 1, 7, 17, gUnknown_08610476, 0, gText_Deselect);
    else
        AddTextPrinterParameterized3(3, 1, 7, 17, gUnknown_08610476, 0, gText_Rent);

    AddTextPrinterParameterized3(3, 1, 7, 33, gUnknown_08610476, 0, gText_Others2);
    CopyWindowToVram(3, 3);
}

static void Select_PrintYesNoOptions(void)
{
    PutWindowTilemap(4);
    FillWindowPixelBuffer(4, PIXEL_FILL(0));
    AddTextPrinterParameterized3(4, 1, 7, 1, gUnknown_08610476, 0, gText_Yes2);
    AddTextPrinterParameterized3(4, 1, 7, 17, gUnknown_08610476, 0, gText_No2);
    CopyWindowToVram(4, 3);
}

static u8 Select_RunMenuOptionFunc(void)
{
    gUnknown_030062E8 = sSelect_MenuOptionFuncs[sFactorySelectScreen->menuCursorPos];
    return gUnknown_030062E8();
}

static u8 Select_OptionRentDeselect(void)
{
    u8 selectedId = sFactorySelectScreen->mons[sFactorySelectScreen->cursorPos].selectedId;
    u16 monSetId  = sFactorySelectScreen->mons[sFactorySelectScreen->cursorPos].monSetId;
    if (selectedId == 0 && !Select_AreSpeciesValid(monSetId))
    {
        Select_PrintCantSelectSameMon();
        sub_819B958(3);
        return 3;
    }
    else
    {
        sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, FALSE);
        Select_HandleMonSelectionChange();
        Select_PrintSelectMonString();
        sub_819B958(3);
        if (sFactorySelectScreen->selectingMonsState > 3)
            return 2;
        else
            return 1;
    }
}

static u8 sub_819BC9C(void)
{
    sub_819C568();
    Select_HandleMonSelectionChange();
    Select_PrintSelectMonString();
    sub_819B958(3);
    if (sFactorySelectScreen->selectingMonsState > 3)
        return 2;
    else
        return 1;
}

static u8 Select_OptionSummary(void)
{
    return 0;
}

static u8 Select_OptionOthers(void)
{
    sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, FALSE);
    sub_819B958(3);
    return 1;
}

static void Select_PrintMonCategory(void)
{
    u16 species;
    u8 text[30];
    u8 x;
    u8 monId = sFactorySelectScreen->cursorPos;
    if (monId < SELECTABLE_MONS_COUNT)
    {
        PutWindowTilemap(5);
        FillWindowPixelBuffer(5, PIXEL_FILL(0));
        species = GetMonData(&sFactorySelectScreen->mons[monId].monData, MON_DATA_SPECIES, NULL);
        CopyMonCategoryText(SpeciesToNationalPokedexNum(species), text);
        x = GetStringRightAlignXOffset(1, text, 0x76);
        AddTextPrinterParameterized(5, 1, text, x, 1, 0, NULL);
        CopyWindowToVram(5, 2);
    }
}

static void Summary_ShowMonSprite(void)
{
    u8 monId = sFactorySelectScreen->cursorPos;
    struct Pokemon *mon = &sFactorySelectScreen->mons[monId].monData;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    sFactorySelectScreen->unk294[1].field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 88, 32, 15, 0xFFFF);
    gSprites[sFactorySelectScreen->unk294[1].field0].centerToCornerVecX = 0;
    gSprites[sFactorySelectScreen->unk294[1].field0].centerToCornerVecY = 0;

    sFactorySelectScreen->unk2A0 = FALSE;
}

static void sub_819BE20(bool8 arg0)
{
    sFactorySelectScreen->unk2A0 = arg0;
}

static void Select_ShowSummaryMonSprite(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality, otId;

    sFactorySelectScreen->unk294[1].field1 = CreateSprite(&gUnknown_08610638, 120, 64, 1);
    StartSpriteAffineAnim(&gSprites[sFactorySelectScreen->unk294[1].field1], 2);

    mon = &sFactorySelectScreen->mons[sFactorySelectScreen->cursorPos].monData;
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    sFactorySelectScreen->unk294[1].field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 88, 32, 15, 0xFFFF);
    gSprites[sFactorySelectScreen->unk294[1].field0].centerToCornerVecX = 0;
    gSprites[sFactorySelectScreen->unk294[1].field0].centerToCornerVecY = 0;

    gSprites[sFactorySelectScreen->unk294[1].field1].invisible = TRUE;
}

static void Select_ShowChosenMonsSprites(void)
{
    u8 i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < SELECTABLE_MONS_COUNT; j++)
        {
            if (sFactorySelectScreen->mons[j].selectedId == i + 1)
            {
                struct Pokemon *mon = &sFactorySelectScreen->mons[j].monData;
                u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
                u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
                u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

                sFactorySelectScreen->unk294[i].field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, (i * 72) + 16, 32, i + 13, 0xFFFF);
                gSprites[sFactorySelectScreen->unk294[i].field0].centerToCornerVecX = 0;
                gSprites[sFactorySelectScreen->unk294[i].field0].centerToCornerVecY = 0;
                break;
            }
        }
    }
    sFactorySelectScreen->unk2A0 = FALSE;
}

static void sub_819C040(struct Sprite *sprite)
{
    u8 taskId;

    if (sprite->affineAnimEnded
        && gSprites[sFactorySelectScreen->unk294[0].field1].affineAnimEnded
        && gSprites[sFactorySelectScreen->unk294[2].field1].affineAnimEnded)
    {
        sprite->invisible = TRUE;
        gSprites[sFactorySelectScreen->unk294[0].field1].invisible = TRUE;
        gSprites[sFactorySelectScreen->unk294[2].field1].invisible = TRUE;

        taskId = CreateTask(sub_819C1D0, 1);
        gTasks[taskId].func(taskId);

        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_819C100(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded
        && gSprites[sFactorySelectScreen->unk294[0].field1].affineAnimEnded
        && gSprites[sFactorySelectScreen->unk294[2].field1].affineAnimEnded)
    {
        FreeOamMatrix(sprite->oam.matrixNum);
        FreeOamMatrix(gSprites[sFactorySelectScreen->unk294[0].field1].oam.matrixNum);
        FreeOamMatrix(gSprites[sFactorySelectScreen->unk294[2].field1].oam.matrixNum);

        sFactorySelectScreen->unk2A0 = FALSE;

        DestroySprite(&gSprites[sFactorySelectScreen->unk294[0].field1]);
        DestroySprite(&gSprites[sFactorySelectScreen->unk294[2].field1]);
        DestroySprite(sprite);
    }
}

static void sub_819C1D0(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        task->data[3] = 16;
        task->data[24] = 224; // BUG: writing outside the array's bounds.
        task->data[5] = 64;
        task->data[8] = 65;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[24]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
        break;
    case 1:
        ShowBg(3);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        break;
    case 2:
        task->data[5] -= 4;
        task->data[8] += 4;
        if (task->data[5] <= 32 || task->data[8] >= 96)
        {
            task->data[5] = 32;
            task->data[8] = 96;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        if (task->data[5] != 32)
            return;
        break;
    default:
        DestroyTask(taskId);
        Select_ShowChosenMonsSprites();
        return;
    }
    task->data[0]++;
}

static void sub_819C2D4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    default:
        HideBg(3);
        gSprites[sFactorySelectScreen->unk294[1].field1].invisible = FALSE;
        gSprites[sFactorySelectScreen->unk294[1].field1].callback = sub_819C100;
        gSprites[sFactorySelectScreen->unk294[0].field1].invisible = FALSE;
        gSprites[sFactorySelectScreen->unk294[0].field1].callback = SpriteCallbackDummy;
        gSprites[sFactorySelectScreen->unk294[2].field1].invisible = FALSE;
        gSprites[sFactorySelectScreen->unk294[2].field1].callback = SpriteCallbackDummy;
        StartSpriteAffineAnim(&gSprites[sFactorySelectScreen->unk294[1].field1], 1);
        StartSpriteAffineAnim(&gSprites[sFactorySelectScreen->unk294[0].field1], 1);
        StartSpriteAffineAnim(&gSprites[sFactorySelectScreen->unk294[2].field1], 1);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
        break;
    case 0:
        task->data[3] = 16;
        task->data[24] = 224; // BUG: writing outside the array's bounds.
        task->data[5] = 32;
        task->data[8] = 96;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[24]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
        task->data[0]++;
        break;
    case 1:
        task->data[5] += 4;
        task->data[8] -= 4;
        if (task->data[5] >= 64 || task->data[8] <= 65)
        {
            task->data[5] = 64;
            task->data[8] = 65;
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        if (task->data[5] == 64)
            task->data[0]++;
        break;
    }
}

static void sub_819C4B4(void)
{
    sFactorySelectScreen->unk294[1].field1 = CreateSprite(&gUnknown_08610638, 120, 64, 1);
    sFactorySelectScreen->unk294[0].field1 = CreateSprite(&gUnknown_08610638,  44, 64, 1);
    sFactorySelectScreen->unk294[2].field1 = CreateSprite(&gUnknown_08610638, 196, 64, 1);

    gSprites[sFactorySelectScreen->unk294[1].field1].callback = sub_819C040;
    gSprites[sFactorySelectScreen->unk294[0].field1].callback = SpriteCallbackDummy;
    gSprites[sFactorySelectScreen->unk294[2].field1].callback = SpriteCallbackDummy;

    sFactorySelectScreen->unk2A0 = TRUE;
}

static void sub_819C568(void)
{
    u8 taskId;

    FreeAndDestroyMonPicSprite(sFactorySelectScreen->unk294[0].field0);
    FreeAndDestroyMonPicSprite(sFactorySelectScreen->unk294[1].field0);
    FreeAndDestroyMonPicSprite(sFactorySelectScreen->unk294[2].field0);

    taskId = CreateTask(sub_819C2D4, 1);
    gTasks[taskId].func(taskId);

    sFactorySelectScreen->unk2A0 = TRUE;
}

static void Select_SetWinRegs(s16 mWin0H, s16 nWin0H, s16 mWin0V, s16 nWin0V)
{
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(mWin0H, nWin0H));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(mWin0V, nWin0V));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
}

static bool32 Select_AreSpeciesValid(u16 monSetId)
{
    u8 i, j;
    u32 species = gFacilityTrainerMons[monSetId].species;
    u8 selectState = sFactorySelectScreen->selectingMonsState;

    for (i = 1; i < selectState; i++)
    {
        for (j = 0; j < SELECTABLE_MONS_COUNT; j++)
        {
            if (sFactorySelectScreen->mons[j].selectedId == i)
            {
                if (gFacilityTrainerMons[sFactorySelectScreen->mons[j].monSetId].species == species)
                    return FALSE;

                break;
            }
        }
    }

    return TRUE;
}

static void Task_SelectFadeSpeciesName(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        sFactorySelectScreen->unk2A7 = 0;
        sFactorySelectScreen->unk2A8 = 0;
        sFactorySelectScreen->unk2A6 = TRUE;
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (sFactorySelectScreen->unk2A2)
        {
            if (sFactorySelectScreen->unk2A9)
            {
                gTasks[taskId].data[0] = 2;
            }
            else
            {
                sFactorySelectScreen->unk2A7++;
                if (sFactorySelectScreen->unk2A7 > 6)
                {
                    sFactorySelectScreen->unk2A7 = 0;
                    if (!sFactorySelectScreen->unk2A6)
                        sFactorySelectScreen->unk2A8--;
                    else
                        sFactorySelectScreen->unk2A8++;
                }
                BlendPalettes(0x4000, sFactorySelectScreen->unk2A8, 0);
                if (sFactorySelectScreen->unk2A8 > 5)
                {
                    sFactorySelectScreen->unk2A6 = FALSE;
                }
                else if (sFactorySelectScreen->unk2A8 == 0)
                {
                    gTasks[taskId].data[0] = 2;
                    sFactorySelectScreen->unk2A6 = TRUE;
                }
            }
        }
        break;
    case 2:
        if (sFactorySelectScreen->unk2A9 > 14)
        {
            sFactorySelectScreen->unk2A9 = 0;
            gTasks[taskId].data[0] = 1;
        }
        else
        {
            sFactorySelectScreen->unk2A9++;
        }
        break;
    }
}

// Swap Screen's section begins here.

static void Swap_CB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void Swap_VblankCb(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CopySwappedMonData(void)
{
    u8 happiness;

    gPlayerParty[sFactorySwapScreen->playerMonId] = gEnemyParty[sFactorySwapScreen->enemyMonId];
    happiness = 0;
    SetMonData(&gPlayerParty[sFactorySwapScreen->playerMonId], MON_DATA_FRIENDSHIP, &happiness);
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].monId = gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->enemyMonId + 3].monId;
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].ivs = gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->enemyMonId + 3].ivs;
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].personality = GetMonData(&gEnemyParty[sFactorySwapScreen->enemyMonId], MON_DATA_PERSONALITY, NULL);
    gSaveBlock2Ptr->frontier.rentalMons[sFactorySwapScreen->playerMonId].abilityBit = GetBoxMonData(&gEnemyParty[sFactorySwapScreen->enemyMonId].box, MON_DATA_ABILITY_NUM, NULL);
}

static void Task_FromSwapScreenToSummaryScreen(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].data[0] = 7;
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            DestroyTask(sFactorySwapScreen->fadeSpeciesNameTaskId);
            sub_819F444(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30);
            Swap_DestroyAllSprites();
            FREE_AND_SET_NULL(sSwapMenuTilesetBuffer);
            FREE_AND_SET_NULL(sSwapMonCardBgTilesetBuffer);
            FREE_AND_SET_NULL(sSwapMenuTilemapBuffer);
            FREE_AND_SET_NULL(sSwapMonCardBgTilemapBuffer);
            FreeAllWindowBuffers();
            gTasks[taskId].data[0] = 8;
        }
        break;
    case 8:
        DestroyTask(taskId);
        sFactorySwapScreen->fromSummaryScreen = TRUE;
        sFactorySwapScreen->unk24 = gPlttBufferUnfaded[244];
        ShowPokemonSummaryScreen(0, gPlayerParty, sFactorySwapScreen->cursorPos, 3 - 1, CB2_InitSwapScreen);
        break;
    }
}

static void Task_CloseSwapScreen(u8 taskId)
{
    if (sFactorySwapScreen->unk30 != TRUE)
    {
        switch (gTasks[taskId].data[0])
        {
        case 0:
            if (sFactorySwapScreen->monSwapped == TRUE)
            {
                gTasks[taskId].data[0]++;
                gSpecialVar_Result = 0;
            }
            else
            {
                gTasks[taskId].data[0] = 2;
                gSpecialVar_Result = 1;
            }
            break;
        case 1:
            if (sFactorySwapScreen->monSwapped == TRUE)
            {
                sFactorySwapScreen->enemyMonId = sFactorySwapScreen->cursorPos;
                CopySwappedMonData();
            }
            gTasks[taskId].data[0]++;
            break;
        case 2:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0]++;
            break;
        case 3:
            if (!UpdatePaletteFade())
            {
                DestroyTask(sFactorySwapScreen->fadeSpeciesNameTaskId);
                Swap_DestroyAllSprites();
                FREE_AND_SET_NULL(sSwapMenuTilesetBuffer);
                FREE_AND_SET_NULL(sSwapMonCardBgTilesetBuffer);
                FREE_AND_SET_NULL(sSwapMenuTilemapBuffer);
                FREE_AND_SET_NULL(sSwapMonCardBgTilemapBuffer);
                FREE_AND_SET_NULL(sFactorySwapScreen);
                FreeAllWindowBuffers();
                SetMainCallback2(CB2_ReturnToFieldContinueScript);
                DestroyTask(taskId);
            }
            break;
        }
    }
}

static void Task_HandleSwapScreenYesNo(u8 taskId)
{
    u16 loPtr, hiPtr;

    if (sFactorySwapScreen->unk30 != TRUE)
    {
        switch (gTasks[taskId].data[0])
        {
        case 4:
            Swap_ShowYesNoOptions();
            gTasks[taskId].data[0] = 5;
            break;
        case 5:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                if (sFactorySwapScreen->yesNoCursorPos == 0)
                {
                    gTasks[taskId].data[1] = 1;
                    hiPtr = gTasks[taskId].data[6];
                    loPtr = gTasks[taskId].data[7];
                    gTasks[taskId].func = (void*)((hiPtr << 16) | loPtr);
                }
                else
                {
                    gTasks[taskId].data[1] = 0;
                    sub_819EA64(4);
                    hiPtr = gTasks[taskId].data[6];
                    loPtr = gTasks[taskId].data[7];
                    gTasks[taskId].func = (void*)((hiPtr << 16) | loPtr);
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                gTasks[taskId].data[1] = 0;
                sub_819EA64(4);
                hiPtr = gTasks[taskId].data[6];
                loPtr = gTasks[taskId].data[7];
                gTasks[taskId].func = (void*)((hiPtr << 16) | loPtr);
            }
            else if (gMain.newAndRepeatedKeys & DPAD_UP)
            {
                PlaySE(SE_SELECT);
                Swap_UpdateYesNoCursorPosition(-1);
            }
            else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
            {
                PlaySE(SE_SELECT);
                Swap_UpdateYesNoCursorPosition(1);
            }
            break;
        }
    }
}

static void sub_819CBDC(u8 taskId)
{
    if (gTasks[taskId].data[1] == 1)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = Task_CloseSwapScreen;
    }
    else
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[6] = (u32)(Task_HandleSwapScreenChooseMons) >> 16;
        gTasks[taskId].data[7] = (u32)(Task_HandleSwapScreenChooseMons);
        gTasks[taskId].data[5] = 1;
        gTasks[taskId].func = sub_819D770;
    }
}

static void sub_819CC24(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        Swap_PrintOnInfoWindow(gText_QuitSwapping);
        sFactorySwapScreen->monSwapped = FALSE;
        gTasks[taskId].data[0] = 4;
        gTasks[taskId].data[6] = (u32)(sub_819CBDC) >> 16;
        gTasks[taskId].data[7] = (u32)(sub_819CBDC);
        gTasks[taskId].func = Task_HandleSwapScreenYesNo;
    }
}

static void sub_819CC74(u8 taskId)
{
    sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, TRUE);
    if (gTasks[taskId].data[1] == 1)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = Task_CloseSwapScreen;
    }
    else
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[6] = (u32)(Task_HandleSwapScreenChooseMons) >> 16;
        gTasks[taskId].data[7] = (u32)(Task_HandleSwapScreenChooseMons);
        gTasks[taskId].data[5] = 1;
        gTasks[taskId].func = sub_819D770;
    }
}

static void sub_819CCD4(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        sub_819F2B4(&sFactorySwapScreen->unk2C.field1, &sFactorySwapScreen->unk30, TRUE);
        Swap_PrintOnInfoWindow(gText_AcceptThisPkmn);
        sFactorySwapScreen->monSwapped = TRUE;
        gTasks[taskId].data[0] = 4;
        gTasks[taskId].data[6] = (u32)(sub_819CC74) >> 16;
        gTasks[taskId].data[7] = (u32)(sub_819CC74);
        gTasks[taskId].func = Task_HandleSwapScreenYesNo;
    }
}

static void Task_HandleSwapScreenMenu(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 2:
        if (!sFactorySwapScreen->fromSummaryScreen)
            sub_819F2B4(&sFactorySwapScreen->unk2C.field1, &sFactorySwapScreen->unk30, TRUE);
        gTasks[taskId].data[0] = 9;
        break;
    case 9:
        if (sFactorySwapScreen->unk30 != TRUE)
        {
            Swap_ShowMenuOptions();
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 3:
        if (sFactorySwapScreen->unk30 != TRUE)
        {
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                Swap_RunMenuOptionFunc(taskId);
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, TRUE);
                sub_819EA64(3);
                gTasks[taskId].data[0] = 0;
                gTasks[taskId].data[6] = (u32)(Task_HandleSwapScreenChooseMons) >> 16;
                gTasks[taskId].data[7] = (u32)(Task_HandleSwapScreenChooseMons);
                gTasks[taskId].data[5] = 1;
                gTasks[taskId].func = sub_819D770;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_UP)
            {
                Swap_UpdateMenuCursorPosition(-1);
            }
            else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
            {
                Swap_UpdateMenuCursorPosition(1);
            }
        }
        break;
    }
}

static void Task_HandleSwapScreenChooseMons(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (!gPaletteFade.active)
        {
            sFactorySwapScreen->unk22 = TRUE;
            gTasks[taskId].data[0] = 1;
        }
        break;
    case 1:
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sFactorySwapScreen->unk22 = FALSE;
            Swap_PrintMonSpecies2();
            sub_819EAC0();
            Swap_RunActionFunc(taskId);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sFactorySwapScreen->unk22 = FALSE;
            Swap_PrintMonSpecies2();
            sub_819EAC0();
            gTasks[taskId].data[6] = (u32)(sub_819CC24) >> 16;
            gTasks[taskId].data[7] = (u32)(sub_819CC24);
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].func = sub_819D588;
        }
        else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        {
            Swap_UpdateBallCursorPosition(-1);
            Swap_PrintMonCategory();
            Swap_PrintMonSpecies();
        }
        else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        {
            Swap_UpdateBallCursorPosition(1);
            Swap_PrintMonCategory();
            Swap_PrintMonSpecies();
        }
        else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            Swap_UpdateActionCursorPosition(1);
            Swap_PrintMonCategory();
            Swap_PrintMonSpecies();
        }
        else if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            Swap_UpdateActionCursorPosition(-1);
            Swap_PrintMonCategory();
            Swap_PrintMonSpecies();
        }
        break;
    }
}

static void Task_SwapFadeSpeciesName(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        sFactorySwapScreen->unk27 = 0;
        sFactorySwapScreen->unk28 = 0;
        sFactorySwapScreen->unk26 = TRUE;
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (sFactorySwapScreen->unk22)
        {
            if (sFactorySwapScreen->unk29)
            {
                gTasks[taskId].data[0] = 2;
            }
            else
            {
                sFactorySwapScreen->unk27++;
                if (sFactorySwapScreen->unk27 > 6)
                {
                    sFactorySwapScreen->unk27 = 0;
                    if (!sFactorySwapScreen->unk26)
                        sFactorySwapScreen->unk28--;
                    else
                        sFactorySwapScreen->unk28++;
                }
                BlendPalettes(0x4000, sFactorySwapScreen->unk28, 0);
                if (sFactorySwapScreen->unk28 > 5)
                {
                    sFactorySwapScreen->unk26 = FALSE;
                }
                else if (sFactorySwapScreen->unk28 == 0)
                {
                    gTasks[taskId].data[0] = 2;
                    sFactorySwapScreen->unk26 = TRUE;
                }
            }
        }
        break;
    case 2:
        if (sFactorySwapScreen->unk29 > 14)
        {
            sFactorySwapScreen->unk29 = 0;
            gTasks[taskId].data[0] = 1;
        }
        else
        {
            sFactorySwapScreen->unk29++;
        }
        break;
    }
}

static void Task_SwapFadeSpeciesName2(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        sFactorySwapScreen->unk27 = 0;
        gTasks[taskId].data[4] = 0;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        LoadPalette(&gPlttBufferUnfaded[0xF0], 0xE0, 0xA);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (sFactorySwapScreen->unk28 > 15)
        {
            gTasks[taskId].data[4] = 1;
            gTasks[taskId].data[0]++;
        }
        sFactorySwapScreen->unk27++;
        if (sFactorySwapScreen->unk27 > 3)
        {
            sFactorySwapScreen->unk27 = 0;
            gPlttBufferUnfaded[244] = gPlttBufferFaded[228];
            sFactorySwapScreen->unk28++;
        }
        BlendPalettes(0x4000, sFactorySwapScreen->unk28, 0);
        break;
    }
}

static void sub_819D12C(u8 taskId)
{
    s8 i;
    u8 var_2C;
    bool8 destroyTask;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        var_2C = 0;
        for (i = 2; i >= 0; i--)
        {
            if (i != 2)
            {
                u8 posX = var_2C - gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x;
                if (posX == 16 || gTasks[taskId].data[i + 2] == 1)
                {
                    var_2C = gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x;
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x += 10;
                }
                else if (posX > 16)
                {
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x = gSprites[sFactorySwapScreen->ballSpriteIds[i + 1]].pos1.x - 48;
                }
            }
            else
            {
                var_2C = gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x;
                gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x += 10;
            }

            if (gTasks[taskId].data[i + 1] == 1)
            {
                if (gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x > (i * 48) + 72)
                {
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x = (i * 48) + 72;
                    destroyTask = TRUE;
                }
                else if (gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x == (i * 48) + 72)
                {
                    destroyTask = TRUE;
                }
                else
                {
                    destroyTask = FALSE;
                }
            }
            else
            {
                destroyTask = FALSE;
            }

            if (gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x - 16 > 240)
            {
                var_2C = gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x;
                gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x = -16;
                if (sFactorySwapScreen->inEnemyScreen == TRUE)
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].oam.paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED);
                else
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].oam.paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_GREY);

                gTasks[taskId].data[i + 1] = 1;
            }
        }
        if (destroyTask == TRUE)
            DestroyTask(taskId);
        break;
    }
}

static void sub_819D324(u8 taskId)
{
    u8 i, j;
    s32 posX = 0;
    s8 r4 = gTasks[taskId].data[3];
    bool8 r1;
    s16 currPosX;
    u8 taskId2;

    if (gTasks[taskId].data[2] == 1)
        r4 *= -1;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        currPosX = gSprites[sFactorySwapScreen->unk8[0][0]].pos1.x;
        if (!gTasks[taskId].data[2])
        {
            if (currPosX + r4 < 240)
            {
                r1 = TRUE;
            }
            else
            {
                r1 = FALSE;
                posX = 240;
            }
        }
        else
        {
            if (currPosX + r4 > 160)
            {
                r1 = TRUE;
            }
            else
            {
                r1 = FALSE;
                posX = 160;
            }
        }

        if (r1 == TRUE)
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 2; j++)
                    gSprites[sFactorySwapScreen->unk8[j][i]].pos1.x += r4;
            }
        }
        else
        {
            for (j = 0; j < 2; j++)
            {
                gSprites[sFactorySwapScreen->unk8[j][0]].pos1.x = posX;
                gSprites[sFactorySwapScreen->unk8[j][1]].pos1.x = posX + 16;
                gSprites[sFactorySwapScreen->unk8[j][2]].pos1.x = posX + 48;
            }
            taskId2 = gTasks[taskId].data[1];
            gTasks[taskId2].data[3] = 1;
            DestroyTask(taskId);
        }
        break;
    case 1:
        currPosX = gSprites[sFactorySwapScreen->unkE[0][0]].pos1.x;
        if (!gTasks[taskId].data[2])
        {
            if (currPosX + r4 < 240)
            {
                r1 = TRUE;
            }
            else
            {
                r1 = FALSE;
                posX = 240;
            }
        }
        else
        {
            if (currPosX + r4 > 192)
            {
                r1 = TRUE;
            }
            else
            {
                r1 = FALSE;
                posX = 192;
            }
        }

        if (r1 == TRUE)
        {
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                    gSprites[sFactorySwapScreen->unkE[j][i]].pos1.x += r4;
            }
        }
        else
        {
            for (j = 0; j < 2; j++)
            {
                gSprites[sFactorySwapScreen->unkE[j][0]].pos1.x = posX;
                gSprites[sFactorySwapScreen->unkE[j][1]].pos1.x = posX + 16;
            }
            taskId2 = gTasks[taskId].data[1];
            gTasks[taskId2].data[4] = 1;
            DestroyTask(taskId);
        }
        break;
    }
}

static void sub_819D588(u8 taskId)
{
    u8 anotherTaskId;
    u16 loPtr, hiPtr;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        LoadPalette(gUnknown_08610918, 0xE0, sizeof(gUnknown_08610918));
        Swap_PrintActionStrings();
        PutWindowTilemap(5);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        sub_819EA64(3);
        gTasks[taskId].data[0]++;
        break;
    case 2:
        BeginNormalPaletteFade(0x4000, 0, 0, 0x10, gUnknown_0860F13C[37]);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            FillWindowPixelBuffer(5, PIXEL_FILL(0));
            CopyWindowToVram(5, 2);
            if (sFactorySwapScreen->inEnemyScreen == TRUE)
            {
                anotherTaskId = CreateTask(sub_819D324, 0);
                gTasks[taskId].data[3] = 0;
                gTasks[anotherTaskId].data[1] = taskId;
                gTasks[anotherTaskId].data[0] = 0;
                gTasks[anotherTaskId].data[2] = 0;
                gTasks[anotherTaskId].data[3] = 6;
                gTasks[taskId].data[2] = 5;
                gTasks[taskId].data[0]++;
            }
            else
            {
                anotherTaskId = CreateTask(sub_819D324, 0);
                gTasks[taskId].data[3] = 1;
                gTasks[taskId].data[4] = 0;
                gTasks[anotherTaskId].data[1] = taskId;
                gTasks[anotherTaskId].data[0] = 1;
                gTasks[anotherTaskId].data[2] = 0;
                gTasks[anotherTaskId].data[3] = 6;
                gTasks[taskId].data[0] += 2;
            }
        }
        break;
    case 4:
        if (gTasks[taskId].data[2] == 0)
        {
            anotherTaskId = CreateTask(sub_819D324, 0);
            gTasks[taskId].data[4] = 0;
            gTasks[anotherTaskId].data[1] = taskId;
            gTasks[anotherTaskId].data[0] = 1;
            gTasks[anotherTaskId].data[2] = 0;
            gTasks[anotherTaskId].data[3] = 6;
            gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[2]--;
        }
        break;
    case 5:
        if (gTasks[taskId].data[3] == 1 && gTasks[taskId].data[4] == 1)
        {
            gTasks[taskId].data[0] = gTasks[taskId].data[5];
            loPtr = gTasks[taskId].data[6];
            hiPtr = gTasks[taskId].data[7];
            gTasks[taskId].func = (void *)((loPtr << 0x10) | (hiPtr));
        }
        break;
    }
}

static void sub_819D770(u8 taskId)
{
    u8 anotherTaskId;
    u16 loPtr, hiPtr;
    if (sFactorySwapScreen->unk30 == TRUE)
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (sFactorySwapScreen->inEnemyScreen == TRUE)
        {
            anotherTaskId = CreateTask(sub_819D324, 0);
            gTasks[taskId].data[3] = 0;
            gTasks[anotherTaskId].data[1] = taskId;
            gTasks[anotherTaskId].data[0] = 0;
            gTasks[anotherTaskId].data[2] = 1;
            gTasks[anotherTaskId].data[3] = 6;
            gTasks[taskId].data[2] = 10;
            gTasks[taskId].data[0]++;
        }
        else
        {
            anotherTaskId = CreateTask(sub_819D324, 0);
            gTasks[taskId].data[3] = 1;
            gTasks[taskId].data[4] = 0;
            gTasks[anotherTaskId].data[1] = taskId;
            gTasks[anotherTaskId].data[0] = 1;
            gTasks[anotherTaskId].data[2] = 1;
            gTasks[anotherTaskId].data[3] = 6;
            gTasks[taskId].data[0] += 2;
        }
        break;
    case 1:
        if (gTasks[taskId].data[2] == 0)
        {
            anotherTaskId = CreateTask(sub_819D324, 0);
            gTasks[taskId].data[4] = 0;
            gTasks[anotherTaskId].data[1] = taskId;
            gTasks[anotherTaskId].data[0] = 1;
            gTasks[anotherTaskId].data[2] = 1;
            gTasks[anotherTaskId].data[3] = 6;
            gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[2]--;
        }
        break;
    case 2:
        if (gTasks[taskId].data[3] == 1 && gTasks[taskId].data[4] == 1)
        {
            gPlttBufferFaded[226] = gUnknown_0860F13C[37];
            Swap_PrintActionStrings();
            PutWindowTilemap(5);
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        BeginNormalPaletteFade(0x4000, 0, 0x10, 0, gUnknown_0860F13C[37]);
        gTasks[taskId].data[0]++;
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            Swap_PrintOneActionString(0);
            gTasks[taskId].data[0]++;
        }
        break;
    case 5:
        Swap_PrintOneActionString(1);
        PutWindowTilemap(3);
        gTasks[taskId].data[0]++;
        break;
    case 6:
        FillWindowPixelBuffer(5, PIXEL_FILL(0));
        CopyWindowToVram(5, 2);
        gTasks[taskId].data[0]++;
        break;
    case 7:
        if (!sFactorySwapScreen->inEnemyScreen)
            Swap_PrintOnInfoWindow(gText_SelectPkmnToSwap);
        else
            Swap_PrintOnInfoWindow(gText_SelectPkmnToAccept);
        if (sFactorySwapScreen->cursorPos < 3)
            gSprites[sFactorySwapScreen->cursorSpriteId].invisible = FALSE;
        Swap_PrintMonCategory();
        gTasks[taskId].data[0]++;
        break;
    case 8:
        Swap_PrintMonSpecies3();
        sub_819EADC();
        sFactorySwapScreen->unk22 = TRUE;
        gTasks[taskId].data[0] = gTasks[taskId].data[5];
        loPtr = gTasks[taskId].data[6];
        hiPtr = gTasks[taskId].data[7];
        gTasks[taskId].func = (void *)((loPtr << 0x10) | (hiPtr));
        break;
    }
}

static void sub_819D9EC(u8 taskId)
{
    u8 i;
    if (sFactorySwapScreen->unk30 == TRUE)
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        Swap_PrintMonSpecies3();
        gTasks[taskId].data[0]++;
        break;
    case 1:
        sub_819EADC();
        gSprites[sFactorySwapScreen->cursorSpriteId].invisible = TRUE;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        CreateTask(sub_819D12C, 0);
        gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].func = Task_SwapFadeSpeciesName2;
        gTasks[taskId].data[0]++;
        break;
    case 3:
        if (!FuncIsActiveTask(sub_819D12C) && gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].data[4] == 1)
        {
            sub_819EAC0();
            if (!sFactorySwapScreen->inEnemyScreen)
            {
                Swap_InitActions(ACTIONS_ENEMY_SCREEN);
            }
            else
            {
                Swap_InitActions(ACTIONS_PLAYER_SCREEN);
                for (i = 0; i < 3; i++)
                    gSprites[sFactorySwapScreen->unk8[1][i]].invisible = TRUE;
            }
            gSprites[sFactorySwapScreen->cursorSpriteId].pos1.x = gSprites[sFactorySwapScreen->ballSpriteIds[sFactorySwapScreen->cursorPos]].pos1.x;
            gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].func = Task_SwapFadeSpeciesName;
            sFactorySwapScreen->unk27 = 0;
            sFactorySwapScreen->unk28 = 6;
            sFactorySwapScreen->unk26 = FALSE;
            gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].data[0] = 1;
            gTasks[taskId].data[0]++;
        }
        break;
    case 4:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[6] = (u32)(Task_HandleSwapScreenChooseMons) >> 0x10;
        gTasks[taskId].data[7] = (u32)(Task_HandleSwapScreenChooseMons);
        gTasks[taskId].data[5] = 1;
        gTasks[taskId].func = sub_819D770;
        break;
    }
}

static void Swap_InitStruct(void)
{
    if (sFactorySwapScreen == NULL)
    {
        sFactorySwapScreen = AllocZeroed(sizeof(*sFactorySwapScreen));
        sFactorySwapScreen->cursorPos = 0;
        sFactorySwapScreen->unk30 = FALSE;
        sFactorySwapScreen->fromSummaryScreen = FALSE;
    }
}

void DoBattleFactorySwapScreen(void)
{
    sFactorySwapScreen = NULL;
    SetMainCallback2(CB2_InitSwapScreen);
}

static void CB2_InitSwapScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sSwap_BgTemplates, ARRAY_COUNT(sSwap_BgTemplates));
        InitWindows(sSwap_WindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        sSwapMenuTilesetBuffer = Alloc(0x440);
        sSwapMonCardBgTilesetBuffer = AllocZeroed(0x440);
        sSwapMenuTilemapBuffer = Alloc(0x800);
        sSwapMonCardBgTilemapBuffer = AllocZeroed(0x800);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        ResetAllPicSprites();
        CpuCopy16(gFrontierFactorySelectMenu_Gfx, sSwapMenuTilesetBuffer, 0x440);
        CpuCopy16(gUnknown_0861033C, sSwapMonCardBgTilesetBuffer, 0x60);
        LoadBgTiles(1, sSwapMenuTilesetBuffer, 0x440, 0);
        LoadBgTiles(3, sSwapMonCardBgTilesetBuffer, 0x60, 0);
        CpuCopy16(gFrontierFactorySelectMenu_Tilemap, sSwapMenuTilemapBuffer, 0x800);
        LoadBgTilemap(1, sSwapMenuTilemapBuffer, 0x800, 0);
        LoadPalette(gFrontierFactorySelectMenu_Pal, 0, 0x40);
        LoadPalette(gUnknown_08610918, 0xF0, sizeof(gUnknown_08610918));
        LoadPalette(gUnknown_08610918, 0xE0, sizeof(gUnknown_08610918));
        LoadPalette(gUnknown_0861039C, 0x20, 4);
        gMain.state++;
        break;
    case 3:
        SetBgTilemapBuffer(3, sSwapMonCardBgTilemapBuffer);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C, 11, 4, 8, 8);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        LoadSpritePalettes(gUnknown_086106B0);
        LoadSpriteSheets(gUnknown_08610650);
        LoadCompressedSpriteSheet(gUnknown_086106A0);
        SetVBlankCallback(Swap_VblankCb);
        gMain.state++;
        break;
    case 5:
        if (sFactorySwapScreen->fromSummaryScreen == TRUE)
            sFactorySwapScreen->cursorPos = gLastViewedMonIndex;
        gMain.state++;
        break;
    case 6:
        Swap_InitStruct();
        Swap_InitAllSprites();
        if (sFactorySwapScreen->fromSummaryScreen == TRUE)
            Swap_ShowSummaryMonSprite();
        Swap_InitActions(ACTIONS_PLAYER_SCREEN);
        gMain.state++;
        break;
    case 7:
        Swap_PrintOnInfoWindow(gText_SelectPkmnToSwap);
        PutWindowTilemap(2);
        gMain.state++;
        break;
    case 8:
        Swap_PrintMonCategory();
        PutWindowTilemap(8);
        gMain.state++;
        break;
    case 9:
        if (!sFactorySwapScreen->fromSummaryScreen)
            Swap_PrintMonSpecies();
        PutWindowTilemap(1);
        gMain.state++;
        break;
    case 10:
        Swap_PrintPkmnSwap();
        PutWindowTilemap(0);
        gMain.state++;
        break;
    case 11:
        gMain.state++;
        break;
    case 12:
        if (sFactorySwapScreen->fromSummaryScreen)
            Swap_PrintMonSpecies2();
        gMain.state++;
        break;
    case 13:
        Swap_PrintActionStrings2();
        PutWindowTilemap(3);
        gMain.state++;
        break;
    case 14:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        if (sFactorySwapScreen->fromSummaryScreen == TRUE)
        {
            ShowBg(3);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        }
        else
        {
            HideBg(3);
        }
        gMain.state++;
        break;
    case 15:
        sFactorySwapScreen->fadeSpeciesNameTaskId = CreateTask(Task_SwapFadeSpeciesName, 0);
        if (!sFactorySwapScreen->fromSummaryScreen)
        {
            gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].data[0] = 0;
            taskId = CreateTask(Task_HandleSwapScreenChooseMons, 0);
            gTasks[taskId].data[0] = 0;
        }
        else
        {
            sub_819EAF8();
            gTasks[sFactorySwapScreen->fadeSpeciesNameTaskId].data[0] = 1;
            sFactorySwapScreen->unk22 = FALSE;
            taskId = CreateTask(Task_HandleSwapScreenMenu, 0);
            gTasks[taskId].data[0] = 2;
        }
        SetMainCallback2(Swap_CB2);
        break;
    }
}

static void Swap_InitAllSprites(void)
{
    u8 i;
    u8 x;
    struct SpriteTemplate spriteTemplate;

    spriteTemplate = gUnknown_08610834;
    spriteTemplate.paletteTag = TAG_PAL_BALL_SELECTED;

    for (i = 0; i < 3; i++)
    {
        sFactorySwapScreen->ballSpriteIds[i] = CreateSprite(&spriteTemplate, (48 * i) + 72, 64, 1);
        gSprites[sFactorySwapScreen->ballSpriteIds[i]].data[0] = 0;
    }
    sFactorySwapScreen->cursorSpriteId = CreateSprite(&gUnknown_0861084C, gSprites[sFactorySwapScreen->ballSpriteIds[sFactorySwapScreen->cursorPos]].pos1.x, 88, 0);
    sFactorySwapScreen->menuCursor1SpriteId = CreateSprite(&gUnknown_08610864, 176, 112, 0);
    sFactorySwapScreen->menuCursor2SpriteId = CreateSprite(&gUnknown_0861087C, 176, 144, 0);
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = TRUE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = TRUE;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].centerToCornerVecY = 0;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].centerToCornerVecY = 0;

    if (sFactorySwapScreen->fromSummaryScreen == TRUE)
        x = 240;
    else
        x = 192;

    spriteTemplate = gUnknown_0861084C;
    spriteTemplate.tileTag = TAG_TILE_68;
    sFactorySwapScreen->unk8[0][0] = CreateSprite(&spriteTemplate, 240, 120, 10);

    spriteTemplate = gUnknown_08610864;
    spriteTemplate.tileTag = TAG_TILE_69;
    sFactorySwapScreen->unk8[0][1] = CreateSprite(&spriteTemplate, 256, 120, 10);
    sFactorySwapScreen->unk8[0][2] = CreateSprite(&spriteTemplate, 288, 120, 10);

    spriteTemplate = gUnknown_0861084C;
    spriteTemplate.tileTag = TAG_TILE_6A;
    sFactorySwapScreen->unk8[1][0] = CreateSprite(&spriteTemplate, 240, 120, 1);

    spriteTemplate = gUnknown_08610864;
    spriteTemplate.tileTag = TAG_TILE_6B;
    sFactorySwapScreen->unk8[1][1] = CreateSprite(&spriteTemplate, 256, 120, 1);
    spriteTemplate.tileTag = TAG_TILE_6C;
    sFactorySwapScreen->unk8[1][2] = CreateSprite(&spriteTemplate, 288, 120, 1);

    spriteTemplate = gUnknown_0861084C;
    spriteTemplate.tileTag = TAG_TILE_68;
    sFactorySwapScreen->unkE[0][0] = CreateSprite(&spriteTemplate, x, 144, 10);

    spriteTemplate = gUnknown_08610864;
    spriteTemplate.tileTag = TAG_TILE_69;
    sFactorySwapScreen->unkE[0][1] = CreateSprite(&spriteTemplate, x + 16, 144, 10);

    spriteTemplate = gUnknown_0861084C;
    spriteTemplate.tileTag = TAG_TILE_6A;
    sFactorySwapScreen->unkE[1][0] = CreateSprite(&spriteTemplate, x, 144, 1);

    spriteTemplate = gUnknown_08610864;
    spriteTemplate.tileTag = TAG_TILE_6C;
    sFactorySwapScreen->unkE[1][1] = CreateSprite(&spriteTemplate, x + 16, 144, 1);

    for (i = 0; i < 2; i++)
    {
        gSprites[sFactorySwapScreen->unk8[i][0]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->unk8[i][0]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->unk8[i][1]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->unk8[i][1]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->unk8[i][2]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->unk8[i][2]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->unkE[i][0]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->unkE[i][0]].centerToCornerVecY = 0;
        gSprites[sFactorySwapScreen->unkE[i][1]].centerToCornerVecX = 0;
        gSprites[sFactorySwapScreen->unkE[i][1]].centerToCornerVecY = 0;

        gSprites[sFactorySwapScreen->unk8[i][0]].invisible = TRUE;
        gSprites[sFactorySwapScreen->unk8[i][1]].invisible = TRUE;
        gSprites[sFactorySwapScreen->unk8[i][2]].invisible = TRUE;
        gSprites[sFactorySwapScreen->unkE[i][0]].invisible = TRUE;
        gSprites[sFactorySwapScreen->unkE[i][1]].invisible = TRUE;
    }

    gSprites[sFactorySwapScreen->unkE[0][0]].invisible = FALSE;
    gSprites[sFactorySwapScreen->unkE[0][1]].invisible = FALSE;
    gSprites[sFactorySwapScreen->unk8[0][0]].invisible = FALSE;
    gSprites[sFactorySwapScreen->unk8[0][1]].invisible = FALSE;
    gSprites[sFactorySwapScreen->unk8[0][2]].invisible = FALSE;
}

static void Swap_DestroyAllSprites(void)
{
    u8 i, j;

    for (i = 0; i < 3; i++)
        DestroySprite(&gSprites[sFactorySwapScreen->ballSpriteIds[i]]);
    DestroySprite(&gSprites[sFactorySwapScreen->cursorSpriteId]);
    DestroySprite(&gSprites[sFactorySwapScreen->menuCursor1SpriteId]);
    DestroySprite(&gSprites[sFactorySwapScreen->menuCursor2SpriteId]);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
            DestroySprite(&gSprites[sFactorySwapScreen->unk8[i][j]]);
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            DestroySprite(&gSprites[sFactorySwapScreen->unkE[i][j]]);
    }
}

static void Swap_HandleActionCursorChange(u8 cursorId)
{
    if (cursorId < 3)
    {
        gSprites[sFactorySwapScreen->cursorSpriteId].invisible = FALSE;
        sub_819E8EC();
        gSprites[sFactorySwapScreen->cursorSpriteId].pos1.x = gSprites[sFactorySwapScreen->ballSpriteIds[cursorId]].pos1.x;
    }
    else
    {
        gSprites[sFactorySwapScreen->cursorSpriteId].invisible = TRUE;
        sub_819E838(sFactorySwapScreen->actionsData[cursorId].id);
    }
}

static void Swap_UpdateBallCursorPosition(s8 direction)
{
    u8 cursorPos;
    PlaySE(SE_SELECT);
    if (direction > 0) // Move cursor right.
    {
        if (sFactorySwapScreen->cursorPos + 1 != sFactorySwapScreen->actionsCount)
            sFactorySwapScreen->cursorPos++;
        else
            sFactorySwapScreen->cursorPos = 0;
    }
    else // Move cursor left.
    {
        if (sFactorySwapScreen->cursorPos != 0)
            sFactorySwapScreen->cursorPos--;
        else
            sFactorySwapScreen->cursorPos = sFactorySwapScreen->actionsCount - 1;
    }

    cursorPos = sFactorySwapScreen->cursorPos;
    Swap_HandleActionCursorChange(cursorPos);
}

static void Swap_UpdateActionCursorPosition(s8 direction)
{
    u8 cursorPos;
    PlaySE(SE_SELECT);
    if (direction > 0) // Move cursor down.
    {
        if (sFactorySwapScreen->cursorPos < 3)
            sFactorySwapScreen->cursorPos = 3;
        else if (sFactorySwapScreen->cursorPos + 1 != sFactorySwapScreen->actionsCount)
            sFactorySwapScreen->cursorPos++;
        else
            sFactorySwapScreen->cursorPos = 0;
    }
    else // Move cursor up.
    {
        if (sFactorySwapScreen->cursorPos < 3)
            sFactorySwapScreen->cursorPos = sFactorySwapScreen->actionsCount - 1;
        else if (sFactorySwapScreen->cursorPos != 0)
            sFactorySwapScreen->cursorPos--;
        else
            sFactorySwapScreen->cursorPos = sFactorySwapScreen->actionsCount - 1;
    }

    cursorPos = sFactorySwapScreen->cursorPos;
    Swap_HandleActionCursorChange(cursorPos);
}

static void Swap_UpdateYesNoCursorPosition(s8 direction)
{
    if (direction > 0) // Move cursor down.
    {
        if (sFactorySwapScreen->yesNoCursorPos != 1)
            sFactorySwapScreen->yesNoCursorPos++;
        else
            sFactorySwapScreen->yesNoCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (sFactorySwapScreen->yesNoCursorPos != 0)
            sFactorySwapScreen->yesNoCursorPos--;
        else
            sFactorySwapScreen->yesNoCursorPos = 1;
    }

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].pos1.y = (sFactorySwapScreen->yesNoCursorPos * 16) + 112;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].pos1.y = (sFactorySwapScreen->yesNoCursorPos * 16) + 112;
}

static void Swap_UpdateMenuCursorPosition(s8 direction)
{
    PlaySE(SE_SELECT);
    if (direction > 0) // Move cursor down.
    {
        if (sFactorySwapScreen->menuCursorPos != MENU_OPTIONS_COUNT - 1)
            sFactorySwapScreen->menuCursorPos++;
        else
            sFactorySwapScreen->menuCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (sFactorySwapScreen->menuCursorPos != 0)
            sFactorySwapScreen->menuCursorPos--;
        else
            sFactorySwapScreen->menuCursorPos = MENU_OPTIONS_COUNT - 1;
    }

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].pos1.y = (sFactorySwapScreen->menuCursorPos * 16) + 112;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].pos1.y = (sFactorySwapScreen->menuCursorPos * 16) + 112;
}

static void sub_819E838(u8 arg0)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (arg0 == 2)
        {
            gSprites[sFactorySwapScreen->unk8[1][i]].invisible = FALSE;
            if (i < 2)
                gSprites[sFactorySwapScreen->unkE[1][i]].invisible = TRUE;
        }
        else if (arg0 == 3)
        {
            if (i < 2)
                gSprites[sFactorySwapScreen->unkE[1][i]].invisible = FALSE;
            gSprites[sFactorySwapScreen->unk8[1][i]].invisible = TRUE;
        }
    }
}

static void sub_819E8EC(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        gSprites[sFactorySwapScreen->unk8[1][i]].invisible = TRUE;
        if (i < 2)
            gSprites[sFactorySwapScreen->unkE[1][i]].invisible = TRUE;
    }
}

static void Swap_ShowMenuOptions(void)
{
    if (sFactorySwapScreen->fromSummaryScreen == TRUE)
        sFactorySwapScreen->fromSummaryScreen = FALSE;
    else
        sFactorySwapScreen->menuCursorPos = 0;

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].pos1.x = 176;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].pos1.y = (sFactorySwapScreen->menuCursorPos * 16) + 112;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].pos1.x = 208;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].pos1.y = (sFactorySwapScreen->menuCursorPos * 16) + 112;

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = FALSE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = FALSE;

    Swap_PrintMenuOptions();
}

static void Swap_ShowYesNoOptions(void)
{
    sFactorySwapScreen->yesNoCursorPos = 0;

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].pos1.x = 176;
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].pos1.y = 112;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].pos1.x = 208;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].pos1.y = 112;

    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = FALSE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = FALSE;

    Swap_PrintYesNoOptions();
}

static void sub_819EA64(u8 windowId)
{
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = TRUE;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = TRUE;
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    CopyWindowToVram(windowId, 2);
    ClearWindowTilemap(windowId);
}

static void sub_819EAC0(void)
{
    PutWindowTilemap(1);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    CopyWindowToVram(1, 2);
}

static void sub_819EADC(void)
{
    PutWindowTilemap(7);
    FillWindowPixelBuffer(7, PIXEL_FILL(0));
    CopyWindowToVram(7, 2);
}

static void sub_819EAF8(void)
{
    sub_819EAC0();
    PutWindowTilemap(5);
    FillWindowPixelBuffer(5, PIXEL_FILL(0));
    CopyWindowToVram(5, 2);
}

static void Swap_PrintPkmnSwap(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, 1, gText_PkmnSwap, 2, 1, 0, NULL);
    CopyWindowToVram(0, 3);
}

static void Swap_PrintMonSpecies(void)
{
    u16 species;
    u8 x;

    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    if (sFactorySwapScreen->cursorPos > 2)
    {
        CopyWindowToVram(1, 2);
    }
    else
    {
        u8 monId = sFactorySwapScreen->cursorPos;
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, NULL);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, NULL);
        StringCopy(gStringVar4, gSpeciesNames[species]);
        x = GetStringRightAlignXOffset(1, gStringVar4, 86);
        AddTextPrinterParameterized3(1, 1, x, 1, gUnknown_08610925, 0, gStringVar4);
        CopyWindowToVram(1, 3);
    }
}

static void Swap_PrintOnInfoWindow(const u8 *str)
{
    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    AddTextPrinterParameterized(2, 1, str, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

static void Swap_PrintMenuOptions(void)
{
    PutWindowTilemap(3);
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    AddTextPrinterParameterized3(3, 1, 15,  1, gUnknown_08610922, 0, gText_Summary2);
    AddTextPrinterParameterized3(3, 1, 15, 17, gUnknown_08610922, 0, gText_Swap);
    AddTextPrinterParameterized3(3, 1, 15, 33, gUnknown_08610922, 0, gText_Rechoose);
    CopyWindowToVram(3, 3);
}

static void Swap_PrintYesNoOptions(void)
{
    PutWindowTilemap(4);
    FillWindowPixelBuffer(4, PIXEL_FILL(0));
    AddTextPrinterParameterized3(4, 1, 7, 1,  gUnknown_08610922, 0, gText_Yes3);
    AddTextPrinterParameterized3(4, 1, 7, 17, gUnknown_08610922, 0, gText_No3);
    CopyWindowToVram(4, 3);
}

static void Swap_PrintActionString(const u8 *str, u32 y, u32 windowId)
{
    s32 x = GetStringRightAlignXOffset(0, str, 0x46);
    AddTextPrinterParameterized3(windowId, 0, x, y, gUnknown_08610922, 0, str);
}

static void Swap_PrintActionStrings(void)
{
    FillWindowPixelBuffer(5, PIXEL_FILL(0));
    switch (sFactorySwapScreen->inEnemyScreen)
    {
    case TRUE:
        Swap_PrintActionString(gText_PkmnForSwap, 0, 5);
    case FALSE:
        Swap_PrintActionString(gText_Cancel3, 24, 5);
        break;
    }
    CopyWindowToVram(5, 3);
}

static void Swap_PrintActionStrings2(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    switch (sFactorySwapScreen->inEnemyScreen)
    {
    case TRUE:
        Swap_PrintActionString(gText_PkmnForSwap, 8, 3);
    case FALSE:
        Swap_PrintActionString(gText_Cancel3, 32, 3);
        break;
    }
    CopyWindowToVram(3, 3);
}

static void Swap_PrintOneActionString(u8 which)
{
    switch (which)
    {
    case 0:
        if (sFactorySwapScreen->inEnemyScreen == TRUE)
            Swap_PrintActionString(gText_PkmnForSwap, 8, 3);
        break;
    case 1:
        Swap_PrintActionString(gText_Cancel3, 32, 3);
        break;
    }
    CopyWindowToVram(3, 3);
}

static void Swap_PrintMonSpecies2(void)
{
    u16 species;
    u8 x;
    u16 pal[5];

    CpuCopy16(gUnknown_08610918, pal, 8);
    if (!sFactorySwapScreen->fromSummaryScreen)
        pal[4] = gPlttBufferFaded[228];
    else
        pal[4] = sFactorySwapScreen->unk24;
    LoadPalette(pal, 0xF0, 0xA);

    PutWindowTilemap(7);
    FillWindowPixelBuffer(7, PIXEL_FILL(0));
    if (sFactorySwapScreen->cursorPos > 2)
    {
        CopyWindowToVram(7, 3);
    }
    else
    {
        u8 monId = sFactorySwapScreen->cursorPos;
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, NULL);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, NULL);
        StringCopy(gStringVar4, gSpeciesNames[species]);
        x = GetStringRightAlignXOffset(1, gStringVar4, 86);
        AddTextPrinterParameterized3(7, 1, x, 1, gUnknown_08610925, 0, gStringVar4);
        CopyWindowToVram(7, 3);
    }
}

static void Swap_PrintMonSpecies3(void)
{
    u16 species;
    u8 x;

    LoadPalette(gUnknown_08610918, 0xE0, sizeof(gUnknown_08610918));
    CpuCopy16(gPlttBufferUnfaded + 240, gPlttBufferFaded + 224, 10);

    if (sFactorySwapScreen->cursorPos > 2)
    {
        CopyWindowToVram(1, 2);
    }
    else
    {
        u8 monId = sFactorySwapScreen->cursorPos;
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, NULL);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, NULL);
        StringCopy(gStringVar4, gSpeciesNames[species]);
        x = GetStringRightAlignXOffset(1, gStringVar4, 86);
        AddTextPrinterParameterized3(1, 1, x, 1, gUnknown_08610925, 0, gStringVar4);
        CopyWindowToVram(1, 3);
    }
}

static void Swap_PrintMonCategory(void)
{
    u16 species;
    u8 text[30];
    u8 x;
    u8 monId = sFactorySwapScreen->cursorPos;

    FillWindowPixelBuffer(8, PIXEL_FILL(0));
    if (monId > 2)
    {
        CopyWindowToVram(8, 2);
    }
    else
    {
        PutWindowTilemap(8);
        if (!sFactorySwapScreen->inEnemyScreen)
            species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES, NULL);
        else
            species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, NULL);
        CopyMonCategoryText(SpeciesToNationalPokedexNum(species), text);
        x = GetStringRightAlignXOffset(1, text, 0x76);
        AddTextPrinterParameterized(8, 1, text, x, 1, 0, NULL);
        CopyWindowToVram(8, 2);
    }
}

static void Swap_InitActions(u8 id)
{
    if (sFactorySwapScreen->fromSummaryScreen != TRUE)
    {
        switch (id)
        {
        case ACTIONS_PLAYER_SCREEN:
            sFactorySwapScreen->inEnemyScreen = FALSE;
            sFactorySwapScreen->cursorPos = 0;
            sFactorySwapScreen->actionsCount = ARRAY_COUNT(sSwap_PlayerScreenActions);
            sFactorySwapScreen->actionsData = sSwap_PlayerScreenActions;
            break;
        case ACTIONS_ENEMY_SCREEN:
            sFactorySwapScreen->inEnemyScreen = TRUE;
            sFactorySwapScreen->cursorPos = 0;
            sFactorySwapScreen->actionsCount = ARRAY_COUNT(sSwap_EnemyScreenActions);
            sFactorySwapScreen->actionsData = sSwap_EnemyScreenActions;
            break;
        }
    }
}

static void Swap_RunMenuOptionFunc(u8 taskId)
{
    sSwap_CurrentTableFunc = sSwap_MenuOptionFuncs[sFactorySwapScreen->menuCursorPos];
    sSwap_CurrentTableFunc(taskId);
}

static void sub_819F0CC(u8 taskId)
{
    sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, TRUE);
    sFactorySwapScreen->playerMonId = sFactorySwapScreen->cursorPos;
    sub_819EA64(3);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = sub_819D9EC;
}

static void sub_819F114(u8 taskId)
{
    gTasks[taskId].data[0] = 6;
    gTasks[taskId].func = Task_FromSwapScreenToSummaryScreen;
}

static void sub_819F134(u8 taskId)
{
    sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, TRUE);
    sub_819EA64(3);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[6] = (u32)(Task_HandleSwapScreenChooseMons) >> 0x10;
    gTasks[taskId].data[7] = (u32)(Task_HandleSwapScreenChooseMons);
    gTasks[taskId].data[5] = 1;
    gTasks[taskId].func = sub_819D770;
}

static void Swap_RunActionFunc(u8 taskId)
{
    sSwap_CurrentTableFunc = sFactorySwapScreen->actionsData[sFactorySwapScreen->cursorPos].func;
    sSwap_CurrentTableFunc(taskId);
}

static void Swap_ActionCancel(u8 taskId)
{
    gTasks[taskId].data[6] = (u32)(sub_819CC24) >> 0x10;
    gTasks[taskId].data[7] = (u32)(sub_819CC24);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].func = sub_819D588;
}

static void Swap_ActionPkmnForSwap(u8 taskId)
{
    gTasks[taskId].data[6] = (u32)(sub_819D9EC) >> 0x10;
    gTasks[taskId].data[7] = (u32)(sub_819D9EC);
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = sub_819D588;
}

static void Swap_ActionMon(u8 taskId)
{
    if (!sFactorySwapScreen->inEnemyScreen)
    {
        gTasks[taskId].data[6] = (u32)(Task_HandleSwapScreenMenu) >> 0x10;
        gTasks[taskId].data[7] = (u32)(Task_HandleSwapScreenMenu);
        gTasks[taskId].data[5] = 2;
    }
    else if (Swap_AlreadyHasSameSpecies(sFactorySwapScreen->cursorPos) == TRUE)
    {
        sub_819F2B4(&sFactorySwapScreen->unk2C.field1, &sFactorySwapScreen->unk30, TRUE);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[5] = 1;
        gTasks[taskId].func = Task_SwapCantHaveSameMons;
        return;
    }
    else
    {
        gTasks[taskId].data[6] = (u32)(sub_819CCD4) >> 0x10;
        gTasks[taskId].data[7] = (u32)(sub_819CCD4);
        gTasks[taskId].data[5] = 0;
    }
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = sub_819D588;
}

static void sub_819F2B4(u8 *arg0, bool8 *arg1, bool8 swapScreen)
{
    *arg0 = CreateSprite(&gUnknown_08610894, 120, 64, 1);
    gSprites[*arg0].callback = sub_819F600;
    gSprites[*arg0].data[7] = swapScreen;
    *arg1 = TRUE;
}

static void Swap_ShowSummaryMonSprite(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality, otId;

    sFactorySwapScreen->unk2C.field1 = CreateSprite(&gUnknown_08610894, 120, 64, 1);
    StartSpriteAffineAnim(&gSprites[sFactorySwapScreen->unk2C.field1], 2);

    mon = &gPlayerParty[sFactorySwapScreen->cursorPos];
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    sFactorySwapScreen->unk2C.field0 = CreateMonPicSprite_HandleDeoxys(species, personality, otId, TRUE, 88, 32, 15, 0xFFFF); // BUG: otId and personality should be switched.
    gSprites[sFactorySwapScreen->unk2C.field0].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->unk2C.field0].centerToCornerVecY = 0;

    gSprites[sFactorySwapScreen->unk2C.field1].invisible = TRUE;
}

static void sub_819F3F8(struct UnkFactoryStruct arg0, bool8 *arg1, bool8 swapScreen)
{
    u8 taskId;

    FreeAndDestroyMonPicSprite(arg0.field0);
    taskId = CreateTask(sub_819F7B4, 1);
    gTasks[taskId].data[7] = swapScreen;
    gTasks[taskId].data[6] = arg0.field1;
    gTasks[taskId].func(taskId);
    *arg1 = TRUE;
}

static void sub_819F444(struct UnkFactoryStruct arg0, bool8 *arg1)
{
    FreeAndDestroyMonPicSprite(arg0.field0);
    FreeOamMatrix(gSprites[arg0.field1].oam.matrixNum);
    DestroySprite(&gSprites[arg0.field1]);
    *arg1 = FALSE;
}

static void Task_SwapCantHaveSameMons(u8 taskId)
{
    if (sFactorySwapScreen->unk30 == TRUE)
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        Swap_PrintOnInfoWindow(gText_SamePkmnInPartyAlready);
        sFactorySwapScreen->monSwapped = FALSE;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, TRUE);
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        if (sFactorySwapScreen->unk30 != TRUE)
        {
            FillWindowPixelBuffer(5, PIXEL_FILL(0));
            CopyWindowToVram(5, 2);
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        Swap_PrintOnInfoWindow(gText_SelectPkmnToAccept);
        gTasks[taskId].data[0]++;
        break;
    case 4:
        Swap_PrintMonSpecies3();
        sub_819EADC();
        sFactorySwapScreen->unk22 = TRUE;
        gTasks[taskId].data[0] = gTasks[taskId].data[5];
        gTasks[taskId].func = Task_HandleSwapScreenChooseMons;
        break;
    }
}

static bool8 Swap_AlreadyHasSameSpecies(u8 monId)
{
    u8 i;
    u16 species = GetMonData(&gEnemyParty[monId], MON_DATA_SPECIES, NULL);

    for (i = 0; i < 3; i++)
    {
        if (i != sFactorySwapScreen->playerMonId && (u16)(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL)) == species)
            return TRUE;
    }
    return FALSE;
}

static void sub_819F600(struct Sprite *sprite)
{
    u8 taskId;

    if (sprite->affineAnimEnded)
    {
        sprite->invisible = TRUE;
        taskId = CreateTask(sub_819F69C, 1);
        gTasks[taskId].data[7] = sprite->data[7];
        gTasks[taskId].func(taskId);
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_819F654(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        FreeOamMatrix(sprite->oam.matrixNum);
        if (sprite->data[7] == TRUE)
            sFactorySwapScreen->unk30 = FALSE;
        else
            sub_819BE20(FALSE);
        DestroySprite(sprite);
    }
}

static void sub_819F69C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        task->data[3] = 88;
        task->data[24] = 152; // BUG: writing outside the array's bounds.
        task->data[5] = 64;
        task->data[8] = 65;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[24]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
        break;
    case 1:
        ShowBg(3);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG3 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        break;
    case 2:
        task->data[5] -= 4;
        task->data[8] += 4;
        if (task->data[5] <= 32 || task->data[8] >= 96)
        {
            task->data[5] = 32;
            task->data[8] = 96;
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        if (task->data[5] != 32)
            return;
        break;
    default:
        DestroyTask(taskId);
        // UB: Should not use the task after it has been deleted.
        if (gTasks[taskId].data[7] == TRUE)
            Swap_ShowMonSprite();
        else
            Summary_ShowMonSprite();
        return;
    }
    task->data[0]++;
}

static void sub_819F7B4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    default:
        HideBg(3);
        gSprites[task->data[6]].data[7] = task->data[7];
        gSprites[task->data[6]].invisible = FALSE;
        gSprites[task->data[6]].callback = sub_819F654;
        StartSpriteAffineAnim(&gSprites[task->data[6]], 1);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
        break;
    case 0:
        task->data[3] = 88;
        task->data[24] = 152; // BUG: writing outside the array's bounds.
        task->data[5] = 32;
        task->data[8] = 96;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[24]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR | WINOUT_WIN01_OBJ);
        task->data[0]++;
        break;
    case 1:
        task->data[5] += 4;
        task->data[8] -= 4;
        if (task->data[5] >= 64 || task->data[8] <= 65)
        {
            task->data[5] = 64;
            task->data[8] = 65;
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[8]));
        if (task->data[5] == 64)
            task->data[0]++;
        break;
    }
}

static void Swap_ShowMonSprite(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality, otId;

    if (!sFactorySwapScreen->inEnemyScreen)
        mon = &gPlayerParty[sFactorySwapScreen->cursorPos];
    else
        mon = &gEnemyParty[sFactorySwapScreen->cursorPos];

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    sFactorySwapScreen->unk2C.field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 88, 32, 15, 0xFFFF);
    gSprites[sFactorySwapScreen->unk2C.field0].centerToCornerVecX = 0;
    gSprites[sFactorySwapScreen->unk2C.field0].centerToCornerVecY = 0;

    sFactorySwapScreen->unk30 = FALSE;
}
