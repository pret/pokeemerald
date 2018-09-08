#include "global.h"
#include "sprite.h"
#include "event_data.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "text.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "string_util.h"
#include "international_string_util.h"
#include "window.h"
#include "data2.h"
#include "decompress.h"
#include "pokemon_summary_screen.h"
#include "sound.h"
#include "pokedex.h"
#include "blend_palette.h"
#include "trainer_pokemon_sprites.h"
#include "constants/battle_frontier.h"
#include "constants/songs.h"

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
    u8 unk2A0;
    u8 palBlendTaskId;
    bool8 unk2A2;
    u16 unk2A4;
    bool8 unk2A6;
    u8 unk2A7;
    u8 unk2A8;
    u8 unk2A9;
};

// 'Action' refers to the Cancel, Pknm for swap windows.

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
    u8 unk12;
    u8 unk13;
    u8 actionsState;
    bool8 fromSummaryScreen;
    u8 yesNoCursorPos;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 palBlendTaskId;
    u8 unk22;
    u8 unk23;
    u16 unk24;
    bool8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    struct UnkFactoryStruct unk2C;
    u8 unk30;
};

extern u8 (*gUnknown_030062E8)(void);
extern u8 gUnknown_0203CF20;

extern const u16 gBattleFrontierHeldItems[];
extern const struct FacilityMon gBattleFrontierMons[];
extern const struct FacilityMon gSlateportBattleTentMons[];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];
extern const u8 gUnknown_085B18AC[];

extern void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 move, u8 moveSlot);

// This file's functions.
static void CB2_InitSelectScreen(void);
static void Select_SetWinRegs(s16 mWin0H, s16 nWin0H, s16 mWin0V, s16 nWin0V);
static void Select_InitMonsData(void);
static void Select_InitAllSprites(void);
static void Select_ShowCheckedMonSprite(void);
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
static void Task_SelectBlendPalette(u8 taskId);
static void sub_819C1D0(u8 taskId);
static void Task_HandleSelectionScreenChooseMons(u8 taskId);
static void Task_HandleSelectionScreenMenu(u8 taskId);
static void CreateFrontierFactorySelectableMons(u8 firstMonId);
static void CreateTentFactorySelectableMons(u8 firstMonId);
static void Select_SetBallSpritePaletteNum(u8 id);
void sub_819F444(struct UnkFactoryStruct arg0, u8 *arg1);
static void sub_819B958(u8 windowId);
void sub_819F2B4(u8 *arg0, u8 *arg1, u8 arg2);
void sub_819F3F8(struct UnkFactoryStruct arg0, u8 *arg1, u8 arg2);
static u8 Select_RunMenuOptionFunc(void);
static u8 sub_819BC9C(void);
static u8 Select_OptionSummary(void);
static u8 Select_OptionOthers(void);
static u8 Select_OptionRentDeselect(void);
u8 sub_81A6F70(u8 battleMode, u8 lvlMode);
u8 sub_81A6CA8(u8 arg0, u8 arg1);
static bool32 Select_AreSpeciesValid(u16 monSetId);
void sub_819E538(void);
void sub_819E9E0(void);
void sub_819EAC0(void);
void Swap_UpdateYesNoCursorPosition(s8 direction);
void Swap_UpdateMenuCursorPosition(s8 direction);
void sub_819EA64(u8 windowId);
void sub_819D770(u8 taskId);
void Task_HandleSwapScreenChooseMons(u8 taskId);
void sub_819D588(u8 taskId);
void Swap_PrintOnInfoWindow(const u8 *str);
void Swap_ShowMenuOptions(void);
void Swap_PrintMonSpecies(void);
void Swap_PrintMonSpecies2(void);
void Swap_PrintMonSpecies3(void);
void Swap_PrintMonCategory(void);
void Swap_InitAllSprites(void);
void Swap_PrintPkmnSwap(void);
void sub_819EADC(void);
void sub_819EAF8(void);
void CB2_InitSwapScreen(void);
void Swap_ShowSummaryMonSprite(void);
void Swap_UpdateActionCursorPosition(s8 direction);
void Swap_UpdateBallCursorPosition(s8 direction);
void Swap_RunMenuOptionFunc(u8 taskId);
void sub_819F184(u8 taskId);
void Swap_PrintActionStrings(void);
void Swap_PrintActionStrings2(void);
void Swap_PrintActionStrings3(u8 field);
void sub_819F048(u8 field);

// Ewram variables
EWRAM_DATA u8 *gUnknown_0203CE2C = NULL;
EWRAM_DATA u8 *gUnknown_0203CE30 = NULL;
EWRAM_DATA u8 *gUnknown_0203CE34 = NULL;
EWRAM_DATA u8 *gUnknown_0203CE38 = NULL;
static EWRAM_DATA struct Pokemon *sFactorySelectMons = NULL;
extern u8 *gUnknown_0203CE40;
extern u8 *gUnknown_0203CE44;
extern u8 *gUnknown_0203CE48;
extern u8 *gUnknown_0203CE4C;

// IWRAM bss
IWRAM_DATA struct FactorySelectMonsStruct *sFactorySelectScreen;
IWRAM_DATA u8 (*gUnknown_03001280)(void);
IWRAM_DATA struct FactorySwapMonsStruct *sFactorySwapScreen;

// Const rom data.
const u16 gUnknown_0860F13C[] = INCBIN_U16("graphics/unknown/unknown_60F13C.gbapal");
const u16 gUnknown_0860F15C[] = INCBIN_U16("graphics/unknown/unknown_60F15C.gbapal");
const u16 gUnknown_0860F17C[] = INCBIN_U16("graphics/unknown/unknown_60F17C.gbapal");
const u8 gUnknown_0860F1BC[] = INCBIN_U8("graphics/unknown/unknown_60F1BC.4bpp");
const u8 gUnknown_0860F3BC[] = INCBIN_U8("graphics/unknown/unknown_60F3BC.4bpp");
const u8 gUnknown_0860F43C[] = INCBIN_U8("graphics/unknown/unknown_60F43C.4bpp");
const u8 gUnknown_0860F53C[] = INCBIN_U8("graphics/unknown/unknown_60F53C.4bpp");
const u8 gUnknown_0860F63C[] = INCBIN_U8("graphics/unknown/unknown_60F63C.4bpp");
const u8 gUnknown_0860F6BC[] = INCBIN_U8("graphics/unknown/unknown_60F6BC.4bpp");
const u8 gUnknown_0860F7BC[] = INCBIN_U8("graphics/unknown/unknown_60F7BC.4bpp");
const u8 gUnknown_0860F83C[] = INCBIN_U8("graphics/unknown/unknown_60F83C.4bpp");
const u8 gUnknown_0860F93C[] = INCBIN_U8("graphics/unknown/unknown_60F93C.4bpp");
const u8 gUnknown_0860FA3C[] = INCBIN_U8("graphics/unknown/unknown_60FA3C.4bpp");
const u8 gUnknown_0861023C[] = INCBIN_U8("graphics/unknown/unknown_61023C.bin");
const u8 gUnknown_0861033C[] = INCBIN_U8("graphics/unknown/unknown_61033C.4bpp");
const u16 gUnknown_0861039C[] = INCBIN_U16("graphics/unknown/unknown_61039C.gbapal");

const struct SpriteSheet gUnknown_086103BC[] =
{
    {gUnknown_0860F3BC, sizeof(gUnknown_0860F3BC), TAG_TILE_65},
    {gUnknown_0860F43C, sizeof(gUnknown_0860F43C), TAG_TILE_66},
    {gUnknown_0860F53C, sizeof(gUnknown_0860F53C), TAG_TILE_67},
    {gUnknown_0860FA3C, sizeof(gUnknown_0860FA3C), TAG_TILE_6D},
    {},
};

const struct CompressedSpriteSheet gUnknown_086103E4[] =
{
    {gUnknown_085B18AC, 0x800, TAG_TILE_64},
    {},
};

const struct SpritePalette gUnknown_086103F4[] =
{
    {gUnknown_0860F13C, TAG_PAL_BALL_GREY},
    {gUnknown_0860F15C, TAG_PAL_BALL_SELECTED},
    {gUnknown_0860F17C, TAG_PAL_66},
    {gUnknown_0861039C, TAG_PAL_67},
    {},
};

u8 (* const sSelect_MenuOptionFuncs[])(void) =
{
    [MENU_SUMMARY] = Select_OptionSummary,
    [MENU_RENT] /*Or Deselect*/ = Select_OptionRentDeselect,
    [MENU_OTHERS] = Select_OptionOthers
};

extern const struct BgTemplate gUnknown_08610428[3];
extern const struct BgTemplate gUnknown_086108B8[4];
extern const struct WindowTemplate gUnknown_08610434[];
extern const struct WindowTemplate gUnknown_086108C8[];
extern const u16 gUnknown_0861046C[];
extern const u16 gUnknown_08610918[];
extern const struct SpriteTemplate gUnknown_086105D8;
extern const struct SpriteTemplate gUnknown_086105F0;
extern const struct SpriteTemplate gUnknown_08610608;
extern const struct SpriteTemplate gUnknown_08610620;
extern const struct SpriteTemplate gUnknown_08610638;
extern const u8 gUnknown_08610479[];
extern const u8 gUnknown_08610476[];
extern const struct SpritePalette gUnknown_086106B0[];
extern const struct SpriteSheet gUnknown_08610650[];
extern const struct CompressedSpriteSheet gUnknown_086106A0[];

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
extern const u8 gText_Deselect[];
extern const u8 gText_Rent[];
extern const u8 gText_Others2[];
extern const u8 gText_Yes2[];
extern const u8 gText_No2[];
extern const u8 gText_QuitSwapping[];
extern const u8 gText_AcceptThisPkmn[];
extern const u8 gText_SelectPkmnToAccept[];
extern const u8 gText_SelectPkmnToSwap[];

// code
void sub_819A44C(struct Sprite *sprite)
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

void sub_819A4F8(void)
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
        InitBgsFromTemplates(0, gUnknown_08610428, ARRAY_COUNT(gUnknown_08610428));
        InitWindows(gUnknown_08610434);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        gUnknown_0203CE2C = Alloc(0x440);
        gUnknown_0203CE30 = AllocZeroed(0x440);
        gUnknown_0203CE34 = Alloc(0x800);
        gUnknown_0203CE38 = AllocZeroed(0x800);
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
        CpuCopy16(gFrontierFactorySelectMenu_Gfx, gUnknown_0203CE2C, 0x440);
        CpuCopy16(gUnknown_0861033C, gUnknown_0203CE30, 0x60);
        LoadBgTiles(1, gUnknown_0203CE2C, 0x440, 0);
        LoadBgTiles(3, gUnknown_0203CE30, 0x60, 0);
        CpuCopy16(gFrontierFactorySelectMenu_Tilemap, gUnknown_0203CE34, 0x800);
        LoadBgTilemap(1, gUnknown_0203CE34, 0x800, 0);
        LoadPalette(gFrontierFactorySelectMenu_Pal, 0, 0x40);
        LoadPalette(gUnknown_0861046C, 0xF0, 8);
        LoadPalette(gUnknown_0861046C, 0xE0, 10);
        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
            gPlttBufferUnfaded[228] = sFactorySelectScreen->unk2A4;
        LoadPalette(gUnknown_0861039C, 0x20, 4);
        gMain.state++;
        break;
    case 3:
        SetBgTilemapBuffer(3, gUnknown_0203CE38);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C, 11, 4, 8, 8);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C,  2, 4, 8, 8);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C, 20, 4, 8, 8);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        LoadSpritePalettes(gUnknown_086103F4);
        LoadSpriteSheets(gUnknown_086103BC);
        LoadCompressedObjectPic(gUnknown_086103E4);
        ShowBg(0);
        ShowBg(1);
        SetVBlankCallback(Select_VblankCb);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
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
            sFactorySelectScreen->cursorPos = gUnknown_0203CF20;
        Select_InitMonsData();
        Select_InitAllSprites();
        if (sFactorySelectScreen->fromSummaryScreen == TRUE)
            Select_ShowCheckedMonSprite();
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
        sFactorySelectScreen->palBlendTaskId = CreateTask(Task_SelectBlendPalette, 0);
        if (!sFactorySelectScreen->fromSummaryScreen)
        {
            gTasks[sFactorySelectScreen->palBlendTaskId].data[0] = 0;
            taskId = CreateTask(Task_HandleSelectionScreenChooseMons, 0);
            gTasks[taskId].data[0] = 0;
        }
        else
        {
            gTasks[sFactorySelectScreen->palBlendTaskId].data[0] = 1;
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

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = 1;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = 1;

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
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
        gTasks[taskId].data[0] = 7;
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            DestroyTask(sFactorySelectScreen->palBlendTaskId);
            sub_819F444(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0);
            Select_DestroyAllSprites();
            FREE_AND_SET_NULL(gUnknown_0203CE2C);
            FREE_AND_SET_NULL(gUnknown_0203CE30);
            FREE_AND_SET_NULL(gUnknown_0203CE34);
            FREE_AND_SET_NULL(gUnknown_0203CE38);
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
    if (sFactorySelectScreen->unk2A0 != 1)
    {
        switch (gTasks[taskId].data[0])
        {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
            gTasks[taskId].data[0]++;
            break;
        case 1:
            if (!UpdatePaletteFade())
            {
                Select_CopyMonsToPlayerParty();
                DestroyTask(sFactorySelectScreen->palBlendTaskId);
                Select_DestroyAllSprites();
                FREE_AND_SET_NULL(gUnknown_0203CE2C);
                FREE_AND_SET_NULL(gUnknown_0203CE34);
                FREE_AND_SET_NULL(gUnknown_0203CE38);
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
    if (sFactorySelectScreen->unk2A0 != 1)
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
            sub_819F2B4(&sFactorySelectScreen->unk294[1].field1, &sFactorySelectScreen->unk2A0, 0);
        gTasks[taskId].data[0] = 9;
        break;
    case 9:
        if (sFactorySelectScreen->unk2A0 != 1)
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
            sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, 0);
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
    if (sFactorySelectScreen->unk2A0 != 1)
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
                sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, 0);
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
    u8 var_2C = gSaveBlock2Ptr->frontier.field_DE2[battleMode][lvlMode] / 7;
    u8 var_28 = 0;

    gFacilityTrainerMons = gBattleFrontierMons;
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        level = 100;
    else
        level = 50;

    var_28 = sub_81A6F70(battleMode, lvlMode);
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        u16 monSetId = gSaveBlock2Ptr->frontier.field_E70[i].monId;
        sFactorySelectScreen->mons[i + firstMonId].monSetId = monSetId;
        if (i < var_28)
            ivs = sub_81A6CA8(var_2C + 1, 0);
        else
            ivs = sub_81A6CA8(var_2C, 0);
        CreateMonWithEVSpreadPersonalityOTID(&sFactorySelectScreen->mons[i + firstMonId].monData,
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             ivs,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);
        happiness = 0;
        for (j = 0; j < 4; j++)
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
        u16 monSetId = gSaveBlock2Ptr->frontier.field_E70[i].monId;
        sFactorySelectScreen->mons[i + firstMonId].monSetId = monSetId;
        CreateMonWithEVSpreadPersonalityOTID(&sFactorySelectScreen->mons[i + firstMonId].monData,
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             ivs,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);
        happiness = 0;
        for (j = 0; j < 4; j++)
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
                gSaveBlock2Ptr->frontier.field_E70[i].monId = sFactorySelectScreen->mons[j].monSetId;
                gSaveBlock2Ptr->frontier.field_E70[i].personality = GetMonData(&gPlayerParty[i].box, MON_DATA_PERSONALITY, NULL);
                gSaveBlock2Ptr->frontier.field_E70[i].abilityBit = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ALT_ABILITY, NULL);
                gSaveBlock2Ptr->frontier.field_E70[i].ivs = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ATK_IV, NULL);
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

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = 0;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = 0;

    Select_PrintMenuOptions();
}

static void Select_ShowYesNoOptions(void)
{
    sFactorySelectScreen->yesNoCursorPos = 0;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.x = 176;
    gSprites[sFactorySelectScreen->menuCursor1SpriteId].pos1.y = 112;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.x = 208;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].pos1.y = 112;

    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = 0;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = 0;

    Select_PrintYesNoOptions();
}

static void sub_819B958(u8 windowId)
{
    gSprites[sFactorySelectScreen->menuCursor1SpriteId].invisible = 1;
    gSprites[sFactorySelectScreen->menuCursor2SpriteId].invisible = 1;
    FillWindowPixelBuffer(windowId, 0);
    CopyWindowToVram(windowId, 2);
    ClearWindowTilemap(windowId);
}

static void Select_PrintRentalPkmnString(void)
{
    FillWindowPixelBuffer(0, 0);
    PrintTextOnWindow(0, 1, gText_RentalPkmn2, 2, 1, 0, NULL);
    CopyWindowToVram(0, 3);
}

static void Select_PrintMonSpecies(void)
{
    u16 species;
    u8 x;
    u8 monId = sFactorySelectScreen->cursorPos;

    FillWindowPixelBuffer(1, 0);
    species = GetMonData(&sFactorySelectScreen->mons[monId].monData, MON_DATA_SPECIES, NULL);
    StringCopy(gStringVar4, gSpeciesNames[species]);
    x = GetStringRightAlignXOffset(1, gStringVar4, 86);
    AddTextPrinterParameterized3(1, 1, x, 1, gUnknown_08610479, 0, gStringVar4);
    CopyWindowToVram(1, 2);
}

static void Select_PrintSelectMonString(void)
{
    const u8 *str = NULL;

    FillWindowPixelBuffer(2, 0);
    if (sFactorySelectScreen->selectingMonsState == 1)
        str = gText_SelectFirstPkmn;
    else if (sFactorySelectScreen->selectingMonsState == 2)
        str = gText_SelectSecondPkmn;
    else if (sFactorySelectScreen->selectingMonsState == 3)
        str = gText_SelectThirdPkmn;
    else
        str = gText_TheseThreePkmnOkay;

    PrintTextOnWindow(2, 1, str, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

static void Select_PrintCantSelectSameMon(void)
{
    FillWindowPixelBuffer(2, 0);
    PrintTextOnWindow(2, 1, gText_CantSelectSamePkmn, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

static void Select_PrintMenuOptions(void)
{
    u8 selectedId = sFactorySelectScreen->mons[sFactorySelectScreen->cursorPos].selectedId;

    PutWindowTilemap(3);
    FillWindowPixelBuffer(3, 0);
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
    FillWindowPixelBuffer(4, 0);
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
        sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, 0);
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
    sub_819F3F8(sFactorySelectScreen->unk294[1], &sFactorySelectScreen->unk2A0, 0);
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
        FillWindowPixelBuffer(5, 0);
        species = GetMonData(&sFactorySelectScreen->mons[monId].monData, MON_DATA_SPECIES, NULL);
        CopyMonCategoryText(SpeciesToNationalPokedexNum(species), text);
        x = GetStringRightAlignXOffset(1, text, 0x76);
        PrintTextOnWindow(5, 1, text, x, 1, 0, NULL);
        CopyWindowToVram(5, 2);
    }
}

void sub_819BD70(void)
{
    u8 monId = sFactorySelectScreen->cursorPos;
    struct Pokemon *mon = &sFactorySelectScreen->mons[monId].monData;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    sFactorySelectScreen->unk294[1].field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 88, 32, 15, 0xFFFF);
    gSprites[sFactorySelectScreen->unk294[1].field0].centerToCornerVecX = 0;
    gSprites[sFactorySelectScreen->unk294[1].field0].centerToCornerVecY = 0;

    sFactorySelectScreen->unk2A0 = 0;
}

void sub_819BE20(u8 arg0)
{
    sFactorySelectScreen->unk2A0 = arg0;
}

static void Select_ShowCheckedMonSprite(void)
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

    gSprites[sFactorySelectScreen->unk294[1].field1].invisible = 1;
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
    sFactorySelectScreen->unk2A0 = 0;
}

static void sub_819C040(struct Sprite *sprite)
{
    u8 taskId;

    if (sprite->affineAnimEnded
        && gSprites[sFactorySelectScreen->unk294[0].field1].affineAnimEnded
        && gSprites[sFactorySelectScreen->unk294[2].field1].affineAnimEnded)
    {
        sprite->invisible = 1;
        gSprites[sFactorySelectScreen->unk294[0].field1].invisible = 1;
        gSprites[sFactorySelectScreen->unk294[2].field1].invisible = 1;

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

        sFactorySelectScreen->unk2A0 = 0;

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
        SetGpuReg(REG_OFFSET_WIN0H, WINHV_COORDS(task->data[3], task->data[24]));
        SetGpuReg(REG_OFFSET_WIN0V, WINHV_COORDS(task->data[5], task->data[8]));
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
        SetGpuReg(REG_OFFSET_WIN0V, WINHV_COORDS(task->data[5], task->data[8]));
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
        gSprites[sFactorySelectScreen->unk294[1].field1].invisible = 0;
        gSprites[sFactorySelectScreen->unk294[1].field1].callback = sub_819C100;
        gSprites[sFactorySelectScreen->unk294[0].field1].invisible = 0;
        gSprites[sFactorySelectScreen->unk294[0].field1].callback = SpriteCallbackDummy;
        gSprites[sFactorySelectScreen->unk294[2].field1].invisible = 0;
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
        SetGpuReg(REG_OFFSET_WIN0H, WINHV_COORDS(task->data[3], task->data[24]));
        SetGpuReg(REG_OFFSET_WIN0V, WINHV_COORDS(task->data[5], task->data[8]));
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
        SetGpuReg(REG_OFFSET_WIN0V, WINHV_COORDS(task->data[5], task->data[8]));
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

    sFactorySelectScreen->unk2A0 = 1;
}

static void sub_819C568(void)
{
    u8 taskId;

    FreeAndDestroyMonPicSprite(sFactorySelectScreen->unk294[0].field0);
    FreeAndDestroyMonPicSprite(sFactorySelectScreen->unk294[1].field0);
    FreeAndDestroyMonPicSprite(sFactorySelectScreen->unk294[2].field0);

    taskId = CreateTask(sub_819C2D4, 1);
    gTasks[taskId].func(taskId);

    sFactorySelectScreen->unk2A0 = 1;
}

static void Select_SetWinRegs(s16 mWin0H, s16 nWin0H, s16 mWin0V, s16 nWin0V)
{
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WIN0H, WINHV_COORDS(mWin0H, nWin0H));
    SetGpuReg(REG_OFFSET_WIN0V, WINHV_COORDS(mWin0V, nWin0V));
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

static void Task_SelectBlendPalette(u8 taskId)
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

void Swap_CB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

void Swap_VblankCb(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_819C810(void)
{
    u8 happiness;

    gPlayerParty[sFactorySwapScreen->unk12] = gEnemyParty[sFactorySwapScreen->unk13];
    happiness = 0;
    SetMonData(&gPlayerParty[sFactorySwapScreen->unk12], MON_DATA_FRIENDSHIP, &happiness);
    gSaveBlock2Ptr->frontier.field_E70[sFactorySwapScreen->unk12].monId = gSaveBlock2Ptr->frontier.field_E70[sFactorySwapScreen->unk13 + 3].monId;
    gSaveBlock2Ptr->frontier.field_E70[sFactorySwapScreen->unk12].ivs = gSaveBlock2Ptr->frontier.field_E70[sFactorySwapScreen->unk13 + 3].ivs;
    gSaveBlock2Ptr->frontier.field_E70[sFactorySwapScreen->unk12].personality = GetMonData(&gEnemyParty[sFactorySwapScreen->unk13], MON_DATA_PERSONALITY, NULL);
    gSaveBlock2Ptr->frontier.field_E70[sFactorySwapScreen->unk12].abilityBit = GetBoxMonData(&gEnemyParty[sFactorySwapScreen->unk13].box, MON_DATA_ALT_ABILITY, NULL);
}

void sub_819C90C(u8 taskId) // Task_FromSelectScreenToSummaryScreen
{
    switch (gTasks[taskId].data[0])
    {
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
        gTasks[taskId].data[0] = 7;
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            DestroyTask(sFactorySwapScreen->palBlendTaskId);
            sub_819F444(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30);
            sub_819E538();
            FREE_AND_SET_NULL(gUnknown_0203CE40);
            FREE_AND_SET_NULL(gUnknown_0203CE44);
            FREE_AND_SET_NULL(gUnknown_0203CE48);
            FREE_AND_SET_NULL(gUnknown_0203CE4C);
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

void sub_819CA08(u8 taskId) // Task_CloseSelectionScreen
{
    if (sFactorySwapScreen->unk30 != 1)
    {
        switch (gTasks[taskId].data[0])
        {
        case 0:
            if (sFactorySwapScreen->unk20 == 1)
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
            if (sFactorySwapScreen->unk20 == 1)
            {
                sFactorySwapScreen->unk13 = sFactorySwapScreen->cursorPos;
                sub_819C810();
            }
            gTasks[taskId].data[0]++;
            break;
        case 2:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
            gTasks[taskId].data[0]++;
            break;
        case 3:
            if (!UpdatePaletteFade())
            {
                DestroyTask(sFactorySwapScreen->palBlendTaskId);
                sub_819E538();
                FREE_AND_SET_NULL(gUnknown_0203CE40);
                FREE_AND_SET_NULL(gUnknown_0203CE44);
                FREE_AND_SET_NULL(gUnknown_0203CE48);
                FREE_AND_SET_NULL(gUnknown_0203CE4C);
                FREE_AND_SET_NULL(sFactorySwapScreen);
                FreeAllWindowBuffers();
                SetMainCallback2(CB2_ReturnToFieldContinueScript);
                DestroyTask(taskId);
            }
            break;
        }
    }
}

void Task_HandleSwapScreenYesNo(u8 taskId)
{
    u16 loPtr, hiPtr;

    if (sFactorySwapScreen->unk30 != 1)
    {
        switch (gTasks[taskId].data[0])
        {
        case 4:
            sub_819E9E0();
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

void sub_819CBDC(u8 taskId)
{
    if (gTasks[taskId].data[1] == 1)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_819CA08;
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

void sub_819CC24(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        Swap_PrintOnInfoWindow(gText_QuitSwapping);
        sFactorySwapScreen->unk20 = 0;
        gTasks[taskId].data[0] = 4;
        gTasks[taskId].data[6] = (u32)(sub_819CBDC) >> 16;
        gTasks[taskId].data[7] = (u32)(sub_819CBDC);
        gTasks[taskId].func = Task_HandleSwapScreenYesNo;
    }
}

void sub_819CC74(u8 taskId)
{
    sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, 1);
    if (gTasks[taskId].data[1] == 1)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_819CA08;
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

void sub_819CCD4(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        sub_819F2B4(&sFactorySwapScreen->unk2C.field1, &sFactorySwapScreen->unk30, 1);
        Swap_PrintOnInfoWindow(gText_AcceptThisPkmn);
        sFactorySwapScreen->unk20 = 1;
        gTasks[taskId].data[0] = 4;
        gTasks[taskId].data[6] = (u32)(sub_819CC74) >> 16;
        gTasks[taskId].data[7] = (u32)(sub_819CC74);
        gTasks[taskId].func = Task_HandleSwapScreenYesNo;
    }
}

void Task_HandleSwapScreenMenu(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 2:
        if (!sFactorySwapScreen->fromSummaryScreen)
            sub_819F2B4(&sFactorySwapScreen->unk2C.field1, &sFactorySwapScreen->unk30, 1);
        gTasks[taskId].data[0] = 9;
        break;
    case 9:
        if (sFactorySwapScreen->unk30 != 1)
        {
            Swap_ShowMenuOptions();
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 3:
        if (sFactorySwapScreen->unk30 != 1)
        {
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                Swap_RunMenuOptionFunc(taskId);
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                sub_819F3F8(sFactorySwapScreen->unk2C, &sFactorySwapScreen->unk30, 1);
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

void Task_HandleSwapScreenChooseMons(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (!gPaletteFade.active)
        {
            sFactorySwapScreen->unk22 = 1;
            gTasks[taskId].data[0] = 1;
        }
        break;
    case 1:
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sFactorySwapScreen->unk22 = 0;
            Swap_PrintMonSpecies2();
            sub_819EAC0();
            sub_819F184(taskId);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sFactorySwapScreen->unk22 = 0;
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

void Task_SwapBlendPalette(u8 taskId)
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

void Task_SwapBlendPalette2(u8 taskId)
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

void sub_819D12C(u8 taskId)
{
    s8 i;
    u8 var_2C;
    bool8 r7;

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
                    r7 = TRUE;
                }
                else if (gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x == (i * 48) + 72)
                {
                    r7 = TRUE;
                }
                else
                {
                    r7 = FALSE;
                }
            }
            else
            {
                r7 = FALSE;
            }

            if (gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x - 16 > 240)
            {
                var_2C = gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x;
                gSprites[sFactorySwapScreen->ballSpriteIds[i]].pos1.x = -16;
                if (sFactorySwapScreen->actionsState == 1)
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].oam.paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED);
                else
                    gSprites[sFactorySwapScreen->ballSpriteIds[i]].oam.paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_GREY);

                gTasks[taskId].data[i + 1] = 1;
            }
        }
        if (r7 == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void sub_819D324(u8 taskId)
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

void sub_819D588(u8 taskId)
{
    u8 anotherTaskId;
    u16 loPtr, hiPtr;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        LoadPalette(gUnknown_08610918, 0xE0, 0xA);
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
            FillWindowPixelBuffer(5, 0);
            CopyWindowToVram(5, 2);
            if (sFactorySwapScreen->actionsState == 1)
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

void sub_819D770(u8 taskId)
{
    u8 anotherTaskId;
    u16 loPtr, hiPtr;
    if (sFactorySwapScreen->unk30 == 1)
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (sFactorySwapScreen->actionsState == 1)
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
            Swap_PrintActionStrings3(0);
            gTasks[taskId].data[0]++;
        }
        break;
    case 5:
        Swap_PrintActionStrings3(1);
        PutWindowTilemap(3);
        gTasks[taskId].data[0]++;
        break;
    case 6:
        FillWindowPixelBuffer(5, 0);
        CopyWindowToVram(5, 2);
        gTasks[taskId].data[0]++;
        break;
    case 7:
        if (sFactorySwapScreen->actionsState == 0)
            Swap_PrintOnInfoWindow(gText_SelectPkmnToSwap);
        else
            Swap_PrintOnInfoWindow(gText_SelectPkmnToAccept);
        if (sFactorySwapScreen->cursorPos < 3)
            gSprites[sFactorySwapScreen->cursorSpriteId].invisible = 0;
        Swap_PrintMonCategory();
        gTasks[taskId].data[0]++;
        break;
    case 8:
        Swap_PrintMonSpecies3();
        sub_819EADC();
        sFactorySwapScreen->unk22 = 1;
        gTasks[taskId].data[0] = gTasks[taskId].data[5];
        loPtr = gTasks[taskId].data[6];
        hiPtr = gTasks[taskId].data[7];
        gTasks[taskId].func = (void *)((loPtr << 0x10) | (hiPtr));
        break;
    }
}

void sub_819D9EC(u8 taskId)
{
    u8 i;
    if (sFactorySwapScreen->unk30 == 1)
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        Swap_PrintMonSpecies3();
        gTasks[taskId].data[0]++;
        break;
    case 1:
        sub_819EADC();
        gSprites[sFactorySwapScreen->cursorSpriteId].invisible = 1;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        CreateTask(sub_819D12C, 0);
        gTasks[sFactorySwapScreen->palBlendTaskId].func = Task_SwapBlendPalette2;
        gTasks[taskId].data[0]++;
        break;
    case 3:
        if (!FuncIsActiveTask(sub_819D12C) && gTasks[sFactorySwapScreen->palBlendTaskId].data[4] == 1)
        {
            sub_819EAC0();
            if (sFactorySwapScreen->actionsState == 0)
            {
                sub_819F048(1);
            }
            else
            {
                sub_819F048(0);
                for (i = 0; i < 3; i++)
                    gSprites[sFactorySwapScreen->unk8[1][i]].invisible = 1;
            }
            gSprites[sFactorySwapScreen->cursorSpriteId].pos1.x = gSprites[sFactorySwapScreen->ballSpriteIds[sFactorySwapScreen->cursorPos]].pos1.x;
            gTasks[sFactorySwapScreen->palBlendTaskId].func = Task_SwapBlendPalette;
            sFactorySwapScreen->unk27 = 0;
            sFactorySwapScreen->unk28 = 6;
            sFactorySwapScreen->unk26 = FALSE;
            gTasks[sFactorySwapScreen->palBlendTaskId].data[0] = 1;
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

void Swap_InitStruct(void)
{
    if (sFactorySwapScreen == NULL)
    {
        sFactorySwapScreen = AllocZeroed(sizeof(*sFactorySwapScreen));
        sFactorySwapScreen->cursorPos = 0;
        sFactorySwapScreen->unk30 = 0;
        sFactorySwapScreen->fromSummaryScreen = FALSE;
    }
}

void sub_819DC00(void)
{
    sFactorySwapScreen = NULL;
    SetMainCallback2(CB2_InitSwapScreen);
}

void CB2_InitSwapScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_086108B8, ARRAY_COUNT(gUnknown_086108B8));
        InitWindows(gUnknown_086108C8);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 1:
        gUnknown_0203CE40 = Alloc(0x440);
        gUnknown_0203CE44 = AllocZeroed(0x440);
        gUnknown_0203CE48 = Alloc(0x800);
        gUnknown_0203CE4C = AllocZeroed(0x800);
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
        CpuCopy16(gFrontierFactorySelectMenu_Gfx, gUnknown_0203CE40, 0x440);
        CpuCopy16(gUnknown_0861033C, gUnknown_0203CE44, 0x60);
        LoadBgTiles(1, gUnknown_0203CE40, 0x440, 0);
        LoadBgTiles(3, gUnknown_0203CE44, 0x60, 0);
        CpuCopy16(gFrontierFactorySelectMenu_Tilemap, gUnknown_0203CE48, 0x800);
        LoadBgTilemap(1, gUnknown_0203CE48, 0x800, 0);
        LoadPalette(gFrontierFactorySelectMenu_Pal, 0, 0x40);
        LoadPalette(gUnknown_08610918, 0xF0, 10);
        LoadPalette(gUnknown_08610918, 0xE0, 10);
        LoadPalette(gUnknown_0861039C, 0x20, 4);
        gMain.state++;
        break;
    case 3:
        SetBgTilemapBuffer(3, gUnknown_0203CE4C);
        CopyToBgTilemapBufferRect(3, gUnknown_0861023C, 11, 4, 8, 8);
        CopyBgTilemapBufferToVram(3);
        gMain.state++;
        break;
    case 4:
        LoadSpritePalettes(gUnknown_086106B0);
        LoadSpriteSheets(gUnknown_08610650);
        LoadCompressedObjectPic(gUnknown_086106A0);
        SetVBlankCallback(Swap_VblankCb);
        gMain.state++;
        break;
    case 5:
        if (sFactorySwapScreen->fromSummaryScreen == TRUE)
            sFactorySwapScreen->cursorPos = gUnknown_0203CF20;
        gMain.state++;
        break;
    case 6:
        Swap_InitStruct();
        Swap_InitAllSprites();
        if (sFactorySwapScreen->fromSummaryScreen == TRUE)
            Swap_ShowSummaryMonSprite();
        sub_819F048(0);
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
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
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
        sFactorySwapScreen->palBlendTaskId = CreateTask(Task_SwapBlendPalette, 0);
        if (!sFactorySwapScreen->fromSummaryScreen)
        {
            gTasks[sFactorySwapScreen->palBlendTaskId].data[0] = 0;
            taskId = CreateTask(Task_HandleSwapScreenChooseMons, 0);
            gTasks[taskId].data[0] = 0;
        }
        else
        {
            sub_819EAF8();
            gTasks[sFactorySwapScreen->palBlendTaskId].data[0] = 1;
            sFactorySwapScreen->unk22 = FALSE;
            taskId = CreateTask(Task_HandleSwapScreenMenu, 0);
            gTasks[taskId].data[0] = 2;
        }
        SetMainCallback2(Swap_CB2);
        break;
    }
}

extern const struct SpriteTemplate gUnknown_08610834;
extern const struct SpriteTemplate gUnknown_0861084C;
extern const struct SpriteTemplate gUnknown_08610864;
extern const struct SpriteTemplate gUnknown_0861087C;

void Swap_InitAllSprites(void)
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
    gSprites[sFactorySwapScreen->menuCursor1SpriteId].invisible = 1;
    gSprites[sFactorySwapScreen->menuCursor2SpriteId].invisible = 1;
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

        gSprites[sFactorySwapScreen->unk8[i][0]].invisible = 1;
        gSprites[sFactorySwapScreen->unk8[i][1]].invisible = 1;
        gSprites[sFactorySwapScreen->unk8[i][2]].invisible = 1;
        gSprites[sFactorySwapScreen->unkE[i][0]].invisible = 1;
        gSprites[sFactorySwapScreen->unkE[i][1]].invisible = 1;
    }

    gSprites[sFactorySwapScreen->unkE[0][0]].invisible = 0;
    gSprites[sFactorySwapScreen->unkE[0][1]].invisible = 0;
    gSprites[sFactorySwapScreen->unk8[0][0]].invisible = 0;
    gSprites[sFactorySwapScreen->unk8[0][1]].invisible = 0;
    gSprites[sFactorySwapScreen->unk8[0][2]].invisible = 0;
}
