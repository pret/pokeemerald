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
#include "trainer_pokemon_sprites.h"
#include "constants/battle_frontier.h"
#include "constants/songs.h"

#define MENU_SUMMARY 0
#define MENU_RENT 1
#define MENU_DESELECT 1
#define MENU_OTHERS 2
#define MENU_OPTIONS_COUNT 3

#define SELECTABLE_MONS_COUNT 6
#define TAG_PAL_BALL_GREY 0x64
#define TAG_PAL_BALL_SELECTED 0x65

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
    u8 unk8;
    u8 unk9;
    struct FactorySelecteableMon mons[SELECTABLE_MONS_COUNT];
    u32 unk294;
    struct UnkFactoryStruct unk298;
    u32 unk29C;
    u8 unk2A0;
    u8 unk2A1;
    u8 unk2A2;
    u8 unk2A3;
    u16 unk2A4;
    u16 unk2A6;
    u16 unk2A8;
    u16 unk2AA;
};

extern struct FactorySelectMonsStruct *gUnknown_0300127C;
extern u8 (*gUnknown_030062E8)(void);
extern u8 gUnknown_0203CF20;

extern const u16 gBattleFrontierHeldItems[];
extern const struct FacilityMon gBattleFrontierMons[];
extern const struct FacilityMon gSlateportBattleTentMons[];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];

extern void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 move, u8 moveSlot);

// This file's functions.
void sub_819A514(void);
void sub_819C5D0(u16 mWin0H, u16 nWin0H, u16 mWin0V, u16 nWin0V);
void sub_819A9AC(void);
void sub_819AA18(void);
void sub_819BE34(void);
void PrintSelectMonString(void);
void PrintMonSpecies(void);
void PrintMonCategory(void);
void sub_819B9E8(void);
void PrintRentalPkmnString(void);
void CopySelectedMonsToPlayerParty(void);
void sub_819C4B4(void);
void sub_819B8D4(void);
void sub_819C568(void);
void sub_819B844(void);
void PrintSelectableMenuOptions(void);
void PrintSelectableYesNo(void);
void sub_819C69C(u8 taskId);
void Task_HandleSelectionScreenChooseMons(u8 taskId);
void Task_HandleSelectionScreenMenu(u8 taskId);
void CreateFrontierFactorySelectableMons(u8 firstMonId);
void CreateTentFactorySelectableMons(u8 firstMonId);
void SetBallSpritePaletteNum(u8 id);
void sub_819F444(struct UnkFactoryStruct arg0, u8 *arg1);
void sub_819B958(u8 windowId);
void sub_819F2B4(u8 *arg0, u8 *arg1, u8 arg2);
void sub_819F3F8(struct UnkFactoryStruct arg0, u8 *arg1, u8 arg2);
u8 sub_819BC04(void);
u8 sub_819BC9C(void);
u8 sub_81A6F70(u8 battleMode, u8 lvlMode);
u8 sub_81A6CA8(u8 arg0, u8 arg1);
bool32 sub_819C634(u16 monSetId);

// Ewram variables
EWRAM_DATA u8 *gUnknown_0203CE2C = NULL;
EWRAM_DATA u8 *gUnknown_0203CE30 = NULL;
EWRAM_DATA u8 *gUnknown_0203CE34 = NULL;
EWRAM_DATA u8 *gUnknown_0203CE38 = NULL;
static EWRAM_DATA struct Pokemon *sFactorySelectMons = NULL;

// Const rom data.
extern const struct BgTemplate gUnknown_08610428[3];
extern const struct WindowTemplate gUnknown_08610434[];
extern const u8 gUnknown_0861033C[];
extern const u8 gUnknown_0861023C[];
extern const u16 gUnknown_0861046C[];
extern const u16 gUnknown_0861039C[];
extern const struct SpritePalette gUnknown_086103F4[];
extern const struct SpriteSheet gUnknown_086103BC[];
extern const struct CompressedSpriteSheet gUnknown_086103E4[];
extern const struct SpriteTemplate gUnknown_086105D8;

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

void sub_819A4C8(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

void sub_819A4E4(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_819A4F8(void)
{
    gUnknown_0300127C = NULL;
    SetMainCallback2(sub_819A514);
}

void sub_819A514(void)
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
        if (gUnknown_0300127C->fromSummaryScreen == TRUE)
            gPlttBufferUnfaded[228] = gUnknown_0300127C->unk2A4;
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
        SetVBlankCallback(sub_819A4E4);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_1D_MAP);
        if (gUnknown_0300127C->fromSummaryScreen == TRUE)
        {
            sub_819C5D0(88, 152, 32, 96);
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
        if (gUnknown_0300127C->fromSummaryScreen == TRUE)
            gUnknown_0300127C->cursorPos = gUnknown_0203CF20;
        sub_819A9AC();
        sub_819AA18();
        if (gUnknown_0300127C->fromSummaryScreen == TRUE)
            sub_819BE34();
        gMain.state++;
        break;
    case 6:
        PrintSelectMonString();
        PutWindowTilemap(2);
        gMain.state++;
        break;
    case 7:
        PrintMonCategory();
        PutWindowTilemap(5);
        gMain.state++;
        break;
    case 8:
        PrintMonSpecies();
        PutWindowTilemap(1);
        gMain.state++;
        break;
    case 9:
        PrintRentalPkmnString();
        PutWindowTilemap(0);
        gMain.state++;
        break;
    case 10:
        gUnknown_0300127C->unk2A1 = CreateTask(sub_819C69C, 0);
        if (!gUnknown_0300127C->fromSummaryScreen)
        {
            gTasks[gUnknown_0300127C->unk2A1].data[0] = 0;
            taskId = CreateTask(Task_HandleSelectionScreenChooseMons, 0);
            gTasks[taskId].data[0] = 0;
        }
        else
        {
            gTasks[gUnknown_0300127C->unk2A1].data[0] = 1;
            gUnknown_0300127C->unk2A2 = 0;
            taskId = CreateTask(Task_HandleSelectionScreenMenu, 0);
            gTasks[taskId].data[0] = 13;
        }
        SetMainCallback2(sub_819A4C8);
        break;
    }
}

void sub_819A9AC(void)
{
    u8 i;

    if (gUnknown_0300127C != NULL)
        return;

    gUnknown_0300127C = AllocZeroed(sizeof(*gUnknown_0300127C));
    gUnknown_0300127C->cursorPos = 0;
    gUnknown_0300127C->selectingMonsState = 1;
    gUnknown_0300127C->fromSummaryScreen = FALSE;
    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
        gUnknown_0300127C->mons[i].selectedId = 0;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        CreateFrontierFactorySelectableMons(0);
    else
        CreateTentFactorySelectableMons(0);
}

extern const struct SpriteTemplate gUnknown_086105F0;
extern const struct SpriteTemplate gUnknown_08610608;
extern const struct SpriteTemplate gUnknown_08610620;

void sub_819AA18(void)
{
    u8 i, cursorPos;
    s16 x;

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
    {
        gUnknown_0300127C->mons[i].spriteId = CreateSprite(&gUnknown_086105D8, (35 * i) + 32, 64, 1);
        gSprites[gUnknown_0300127C->mons[i].spriteId].data[0] = 0;
        SetBallSpritePaletteNum(i);
    }
    cursorPos = gUnknown_0300127C->cursorPos;
    x = gSprites[gUnknown_0300127C->mons[cursorPos].spriteId].pos1.x;
    gUnknown_0300127C->cursorSpriteId = CreateSprite(&gUnknown_086105F0, x, 88, 0);
    gUnknown_0300127C->menuCursor1SpriteId = CreateSprite(&gUnknown_08610608, 176, 112, 0);
    gUnknown_0300127C->menuCursor2SpriteId = CreateSprite(&gUnknown_08610620, 176, 144, 0);

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].invisible = 1;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].invisible = 1;

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].centerToCornerVecX = 0;
    gSprites[gUnknown_0300127C->menuCursor1SpriteId].centerToCornerVecY = 0;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].centerToCornerVecX = 0;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].centerToCornerVecY = 0;
}

void sub_819AB40(void)
{
    u8 i;

    for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
        DestroySprite(&gSprites[gUnknown_0300127C->mons[i].spriteId]);

    DestroySprite(&gSprites[gUnknown_0300127C->cursorSpriteId]);
    DestroySprite(&gSprites[gUnknown_0300127C->menuCursor1SpriteId]);
    DestroySprite(&gSprites[gUnknown_0300127C->menuCursor2SpriteId]);
}

void UpdateBallCursorPosition(s8 direction)
{
    u8 cursorPos;
    if (direction > 0) // Move cursor right.
    {
        if (gUnknown_0300127C->cursorPos != SELECTABLE_MONS_COUNT - 1)
            gUnknown_0300127C->cursorPos++;
        else
            gUnknown_0300127C->cursorPos = 0;
    }
    else // Move cursor left.
    {
        if (gUnknown_0300127C->cursorPos != 0)
            gUnknown_0300127C->cursorPos--;
        else
            gUnknown_0300127C->cursorPos = SELECTABLE_MONS_COUNT - 1;
    }

    cursorPos = gUnknown_0300127C->cursorPos;
    gSprites[gUnknown_0300127C->cursorSpriteId].pos1.x = gSprites[gUnknown_0300127C->mons[cursorPos].spriteId].pos1.x;
}

void UpdateMenuCursorPosition(s8 direction)
{
    if (direction > 0) // Move cursor down.
    {
        if (gUnknown_0300127C->menuCursorPos != MENU_OPTIONS_COUNT - 1)
            gUnknown_0300127C->menuCursorPos++;
        else
            gUnknown_0300127C->menuCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (gUnknown_0300127C->menuCursorPos != 0)
            gUnknown_0300127C->menuCursorPos--;
        else
            gUnknown_0300127C->menuCursorPos = MENU_OPTIONS_COUNT - 1;
    }

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].pos1.y = (gUnknown_0300127C->menuCursorPos * 16) + 112;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].pos1.y = (gUnknown_0300127C->menuCursorPos * 16) + 112;
}

void UpdateYesNoCursorPosition(s8 direction)
{
    if (direction > 0) // Move cursor down.
    {
        if (gUnknown_0300127C->yesNoCursorPos != 1)
            gUnknown_0300127C->yesNoCursorPos++;
        else
            gUnknown_0300127C->yesNoCursorPos = 0;
    }
    else // Move cursor up.
    {
        if (gUnknown_0300127C->yesNoCursorPos != 0)
            gUnknown_0300127C->yesNoCursorPos--;
        else
            gUnknown_0300127C->yesNoCursorPos = 1;
    }

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].pos1.y = (gUnknown_0300127C->yesNoCursorPos * 16) + 112;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].pos1.y = (gUnknown_0300127C->yesNoCursorPos * 16) + 112;
}

void HandleMonSelectionChange(void)
{
    u8 i, paletteNum;
    u8 cursorPos = gUnknown_0300127C->cursorPos;
    if (gUnknown_0300127C->mons[cursorPos].selectedId) // Deselect a mon.
    {
        paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_GREY);
        if (gUnknown_0300127C->selectingMonsState == 3 && gUnknown_0300127C->mons[cursorPos].selectedId == 1)
        {
            for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
            {
                if (gUnknown_0300127C->mons[i].selectedId == 2)
                    break;
            }
            if (i == SELECTABLE_MONS_COUNT)
                return;
            else
                gUnknown_0300127C->mons[i].selectedId = 1;
        }
        gUnknown_0300127C->mons[cursorPos].selectedId = 0;
        gUnknown_0300127C->selectingMonsState--;
    }
    else // Select a mon.
    {
        paletteNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED);
        gUnknown_0300127C->mons[cursorPos].selectedId = gUnknown_0300127C->selectingMonsState;
        gUnknown_0300127C->selectingMonsState++;
    }

    gSprites[gUnknown_0300127C->mons[cursorPos].spriteId].oam.paletteNum = paletteNum;
}

void SetBallSpritePaletteNum(u8 id)
{
    u8 palNum;

    if (gUnknown_0300127C->mons[id].selectedId)
        palNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_SELECTED);
    else
        palNum = IndexOfSpritePaletteTag(TAG_PAL_BALL_GREY);

    gSprites[gUnknown_0300127C->mons[id].spriteId].oam.paletteNum = palNum;
}

void Task_FromSelectScreenToSummaryScreen(u8 taskId)
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
            DestroyTask(gUnknown_0300127C->unk2A1);
            sub_819F444(gUnknown_0300127C->unk298, &gUnknown_0300127C->unk2A0);
            sub_819AB40();
            FREE_AND_SET_NULL(gUnknown_0203CE2C);
            FREE_AND_SET_NULL(gUnknown_0203CE30);
            FREE_AND_SET_NULL(gUnknown_0203CE34);
            FREE_AND_SET_NULL(gUnknown_0203CE38);
            FreeAllWindowBuffers();
            gTasks[taskId].data[0] = 8;
        }
        break;
    case 8:
        gUnknown_0300127C->unk2A4 = gPlttBufferUnfaded[228];
        DestroyTask(taskId);
        gUnknown_0300127C->fromSummaryScreen = TRUE;
        currMonId = gUnknown_0300127C->cursorPos;
        sFactorySelectMons = AllocZeroed(sizeof(struct Pokemon) * SELECTABLE_MONS_COUNT);
        for (i = 0; i < SELECTABLE_MONS_COUNT; i++)
            sFactorySelectMons[i] = gUnknown_0300127C->mons[i].monData;
        ShowPokemonSummaryScreen(1, sFactorySelectMons, currMonId, SELECTABLE_MONS_COUNT - 1, sub_819A514);
        break;
    }
}

void Task_CloseSelectionScreen(u8 taskId)
{
    if (gUnknown_0300127C->unk2A0 != 1)
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
                CopySelectedMonsToPlayerParty();
                DestroyTask(gUnknown_0300127C->unk2A1);
                sub_819AB40();
                FREE_AND_SET_NULL(gUnknown_0203CE2C);
                FREE_AND_SET_NULL(gUnknown_0203CE34);
                FREE_AND_SET_NULL(gUnknown_0203CE38);
                FREE_AND_SET_NULL(gUnknown_0300127C);
                FreeAllWindowBuffers();
                SetMainCallback2(CB2_ReturnToFieldContinueScript);
                DestroyTask(taskId);
            }
            break;
        }
    }
}

void Task_HandleSelectionScreenYesNo(u8 taskId)
{
    if (gUnknown_0300127C->unk2A0 != 1)
    {
        switch (gTasks[taskId].data[0])
        {
        case 10:
            sub_819C4B4();
            gTasks[taskId].data[0] = 4;
            break;
        case 4:
            sub_819B8D4();
            gTasks[taskId].data[0] = 5;
            break;
        case 5:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                if (gUnknown_0300127C->yesNoCursorPos == 0)
                {
                    sub_819C568();
                    gTasks[taskId].data[0] = 0;
                    gTasks[taskId].func = Task_CloseSelectionScreen;
                }
                else
                {
                    sub_819B958(4);
                    sub_819BC9C();
                    gUnknown_0300127C->unk2A2 = 1;
                    gTasks[taskId].data[0] = 1;
                    gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                PlaySE(SE_SELECT);
                sub_819B958(4);
                sub_819BC9C();
                gUnknown_0300127C->unk2A2 = 1;
                gTasks[taskId].data[0] = 1;
                gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_UP)
            {
                PlaySE(SE_SELECT);
                UpdateYesNoCursorPosition(-1);
            }
            else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
            {
                PlaySE(SE_SELECT);
                UpdateYesNoCursorPosition(1);
            }
            break;
        }
    }
}

void Task_HandleSelectionScreenMenu(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 2:
        if (!gUnknown_0300127C->fromSummaryScreen)
            sub_819F2B4(&gUnknown_0300127C->unk298.field1, &gUnknown_0300127C->unk2A0, 0);
        gTasks[taskId].data[0] = 9;
        break;
    case 9:
        if (gUnknown_0300127C->unk2A0 != 1)
        {
            sub_819B844();
            gUnknown_0300127C->fromSummaryScreen = FALSE;
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 3:
        if (gMain.newKeys & A_BUTTON)
        {
            u8 retVal;
            PlaySE(SE_SELECT);
            retVal = sub_819BC04();
            if (retVal == 1)
            {
                gUnknown_0300127C->unk2A2 = 1;
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
            sub_819F3F8(gUnknown_0300127C->unk298, &gUnknown_0300127C->unk2A0, 0);
            sub_819B958(3);
            gUnknown_0300127C->unk2A2 = 1;
            gTasks[taskId].data[0] = 1;
            gTasks[taskId].func = Task_HandleSelectionScreenChooseMons;
        }
        else if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            UpdateMenuCursorPosition(-1);
        }
        else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            UpdateMenuCursorPosition(1);
        }
        break;
    case 12:
        if (!gPaletteFade.active)
        {
            if (gUnknown_0300127C->fromSummaryScreen == TRUE)
            {
                gPlttBufferFaded[228] = gUnknown_0300127C->unk2A4;
                gPlttBufferUnfaded[228] = gPlttBufferUnfaded[244];
            }
            gUnknown_0300127C->fromSummaryScreen = FALSE;
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 13:
        sub_819B844();
        gTasks[taskId].data[0] = 12;
        break;
    }
}

void Task_HandleSelectionScreenChooseMons(u8 taskId)
{
    if (gUnknown_0300127C->unk2A0 != 1)
    {
        switch (gTasks[taskId].data[0])
        {
        case 0:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].data[0] = 1;
                gUnknown_0300127C->unk2A2 = 1;
            }
            break;
        case 1:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                gUnknown_0300127C->unk2A2 = 0;
                gTasks[taskId].data[0] = 2;
                gTasks[taskId].func = Task_HandleSelectionScreenMenu;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
            {
                PlaySE(SE_SELECT);
                UpdateBallCursorPosition(-1);
                PrintMonCategory();
                PrintMonSpecies();
            }
            else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
            {
                PlaySE(SE_SELECT);
                UpdateBallCursorPosition(1);
                PrintMonCategory();
                PrintMonSpecies();
            }
            break;
        case 11:
            if (gMain.newKeys & A_BUTTON)
            {
                PlaySE(SE_SELECT);
                sub_819F3F8(gUnknown_0300127C->unk298, &gUnknown_0300127C->unk2A0, 0);
                PrintSelectMonString();
                gUnknown_0300127C->unk2A2 = 1;
                gTasks[taskId].data[0] = 1;
            }
            break;
        }
    }
}

void CreateFrontierFactorySelectableMons(u8 firstMonId)
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
        gUnknown_0300127C->mons[i + firstMonId].monSetId = monSetId;
        if (i < var_28)
            ivs = sub_81A6CA8(var_2C + 1, 0);
        else
            ivs = sub_81A6CA8(var_2C, 0);
        CreateMonWithEVSpreadPersonalityOTID(&gUnknown_0300127C->mons[i + firstMonId].monData,
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             ivs,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);
        happiness = 0;
        for (j = 0; j < 4; j++)
            SetMonMoveAvoidReturn(&gUnknown_0300127C->mons[i + firstMonId].monData, gFacilityTrainerMons[monSetId].moves[j], j);
        SetMonData(&gUnknown_0300127C->mons[i + firstMonId].monData, MON_DATA_FRIENDSHIP, &happiness);
        SetMonData(&gUnknown_0300127C->mons[i + firstMonId].monData, MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
    }
}

void CreateTentFactorySelectableMons(u8 firstMonId)
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
        gUnknown_0300127C->mons[i + firstMonId].monSetId = monSetId;
        CreateMonWithEVSpreadPersonalityOTID(&gUnknown_0300127C->mons[i + firstMonId].monData,
                                             gFacilityTrainerMons[monSetId].species,
                                             level,
                                             gFacilityTrainerMons[monSetId].nature,
                                             ivs,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);
        happiness = 0;
        for (j = 0; j < 4; j++)
            SetMonMoveAvoidReturn(&gUnknown_0300127C->mons[i + firstMonId].monData, gFacilityTrainerMons[monSetId].moves[j], j);
        SetMonData(&gUnknown_0300127C->mons[i + firstMonId].monData, MON_DATA_FRIENDSHIP, &happiness);
        SetMonData(&gUnknown_0300127C->mons[i + firstMonId].monData, MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
    }
}

void CopySelectedMonsToPlayerParty(void)
{
    u8 i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < SELECTABLE_MONS_COUNT; j++)
        {
            if (gUnknown_0300127C->mons[j].selectedId == i + 1)
            {
                gPlayerParty[i] = gUnknown_0300127C->mons[j].monData;
                gSaveBlock2Ptr->frontier.field_E70[i].monId = gUnknown_0300127C->mons[j].monSetId;
                gSaveBlock2Ptr->frontier.field_E70[i].personality = GetMonData(&gPlayerParty[i].box, MON_DATA_PERSONALITY, NULL);
                gSaveBlock2Ptr->frontier.field_E70[i].abilityBit = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ALT_ABILITY, NULL);
                gSaveBlock2Ptr->frontier.field_E70[i].ivs = GetBoxMonData(&gPlayerParty[i].box, MON_DATA_ATK_IV, NULL);
                break;
            }
        }
    }
    CalculatePlayerPartyCount();
}

void sub_819B844(void)
{
    if (!gUnknown_0300127C->fromSummaryScreen)
        gUnknown_0300127C->menuCursorPos = 0;

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].pos1.x = 176;
    gSprites[gUnknown_0300127C->menuCursor1SpriteId].pos1.y = (gUnknown_0300127C->menuCursorPos * 16) + 112;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].pos1.x = 208;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].pos1.y = (gUnknown_0300127C->menuCursorPos * 16) + 112;

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].invisible = 0;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].invisible = 0;

    PrintSelectableMenuOptions();
}

void sub_819B8D4(void)
{
    gUnknown_0300127C->yesNoCursorPos = 0;

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].pos1.x = 176;
    gSprites[gUnknown_0300127C->menuCursor1SpriteId].pos1.y = 112;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].pos1.x = 208;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].pos1.y = 112;

    gSprites[gUnknown_0300127C->menuCursor1SpriteId].invisible = 0;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].invisible = 0;

    PrintSelectableYesNo();
}

void sub_819B958(u8 windowId)
{
    gSprites[gUnknown_0300127C->menuCursor1SpriteId].invisible = 1;
    gSprites[gUnknown_0300127C->menuCursor2SpriteId].invisible = 1;
    FillWindowPixelBuffer(windowId, 0);
    CopyWindowToVram(windowId, 2);
    ClearWindowTilemap(windowId);
}

void PrintRentalPkmnString(void)
{
    FillWindowPixelBuffer(0, 0);
    PrintTextOnWindow(0, 1, gText_RentalPkmn2, 2, 1, 0, NULL);
    CopyWindowToVram(0, 3);
}

extern const u8 gUnknown_08610479[];
extern const u8 gUnknown_08610476[];

void PrintMonSpecies(void)
{
    u16 species;
    u8 x;
    u8 monId = gUnknown_0300127C->cursorPos;

    FillWindowPixelBuffer(1, 0);
    species = GetMonData(&gUnknown_0300127C->mons[monId].monData, MON_DATA_SPECIES, NULL);
    StringCopy(gStringVar4, gSpeciesNames[species]);
    x = GetStringRightAlignXOffset(1, gStringVar4, 86);
    AddTextPrinterParameterized3(1, 1, x, 1, gUnknown_08610479, 0, gStringVar4);
    CopyWindowToVram(1, 2);
}

void PrintSelectMonString(void)
{
    const u8 *str = NULL;

    FillWindowPixelBuffer(2, 0);
    if (gUnknown_0300127C->selectingMonsState == 1)
        str = gText_SelectFirstPkmn;
    else if (gUnknown_0300127C->selectingMonsState == 2)
        str = gText_SelectSecondPkmn;
    else if (gUnknown_0300127C->selectingMonsState == 3)
        str = gText_SelectThirdPkmn;
    else
        str = gText_TheseThreePkmnOkay;

    PrintTextOnWindow(2, 1, str, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

void PrintCantSelectSameMon(void)
{
    FillWindowPixelBuffer(2, 0);
    PrintTextOnWindow(2, 1, gText_CantSelectSamePkmn, 2, 5, 0, NULL);
    CopyWindowToVram(2, 2);
}

void PrintSelectableMenuOptions(void)
{
    u8 selectedId = gUnknown_0300127C->mons[gUnknown_0300127C->cursorPos].selectedId;

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

void PrintSelectableYesNo(void)
{
    PutWindowTilemap(4);
    FillWindowPixelBuffer(4, 0);
    AddTextPrinterParameterized3(4, 1, 7, 1, gUnknown_08610476, 0, gText_Yes2);
    AddTextPrinterParameterized3(4, 1, 7, 17, gUnknown_08610476, 0, gText_No2);
    CopyWindowToVram(4, 3);
}

extern u8 (* const gUnknown_0861041C[])(void);

u8 sub_819BC04(void)
{
    gUnknown_030062E8 = gUnknown_0861041C[gUnknown_0300127C->menuCursorPos];
    return gUnknown_030062E8();
}

u8 sub_819BC30(void)
{
    u8 selectedId = gUnknown_0300127C->mons[gUnknown_0300127C->cursorPos].selectedId;
    u16 monSetId  = gUnknown_0300127C->mons[gUnknown_0300127C->cursorPos].monSetId;
    if (selectedId == 0 && !sub_819C634(monSetId))
    {
        PrintCantSelectSameMon();
        sub_819B958(3);
        return 3;
    }
    else
    {
        sub_819F3F8(gUnknown_0300127C->unk298, &gUnknown_0300127C->unk2A0, 0);
        HandleMonSelectionChange();
        PrintSelectMonString();
        sub_819B958(3);
        if (gUnknown_0300127C->selectingMonsState > 3)
            return 2;
        else
            return 1;
    }
}

u8 sub_819BC9C(void)
{
    sub_819C568();
    HandleMonSelectionChange();
    PrintSelectMonString();
    sub_819B958(3);
    if (gUnknown_0300127C->selectingMonsState > 3)
        return 2;
    else
        return 1;
}

u8 sub_819BCCC(void)
{
    return 0;
}

u8 sub_819BCD0(void)
{
    sub_819F3F8(gUnknown_0300127C->unk298, &gUnknown_0300127C->unk2A0, 0);
    sub_819B958(3);
    return 1;
}

void PrintMonCategory(void)
{
    u16 species;
    u8 text[30];
    u8 x;
    u8 monId = gUnknown_0300127C->cursorPos;
    if (monId < SELECTABLE_MONS_COUNT)
    {
        PutWindowTilemap(5);
        FillWindowPixelBuffer(5, 0);
        species = GetMonData(&gUnknown_0300127C->mons[monId].monData, MON_DATA_SPECIES, NULL);
        CopyMonCategoryText(SpeciesToNationalPokedexNum(species), text);
        x = GetStringRightAlignXOffset(1, text, 0x76);
        PrintTextOnWindow(5, 1, text, x, 1, 0, NULL);
        CopyWindowToVram(5, 2);
    }
}

void sub_819BD70(void)
{
    u8 monId = gUnknown_0300127C->cursorPos;
    struct Pokemon *mon = &gUnknown_0300127C->mons[monId].monData;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    gUnknown_0300127C->unk298.field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 88, 32, 15, 0xFFFF);
    gSprites[gUnknown_0300127C->unk298.field0].centerToCornerVecX = 0;
    gSprites[gUnknown_0300127C->unk298.field0].centerToCornerVecY = 0;

    gUnknown_0300127C->unk2A0 = 0;
}

extern const struct SpriteTemplate gUnknown_08610638;

void sub_819BE20(u8 arg0)
{
    gUnknown_0300127C->unk2A0 = arg0;
}

void sub_819BE34(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality, otId;

    gUnknown_0300127C->unk298.field1 = CreateSprite(&gUnknown_08610638, 120, 64, 1);
    StartSpriteAffineAnim(&gSprites[gUnknown_0300127C->unk298.field1], 2);

    mon = &gUnknown_0300127C->mons[gUnknown_0300127C->cursorPos].monData;
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

    gUnknown_0300127C->unk298.field0 = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 88, 32, 15, 0xFFFF);
    gSprites[gUnknown_0300127C->unk298.field0].centerToCornerVecX = 0;
    gSprites[gUnknown_0300127C->unk298.field0].centerToCornerVecY = 0;

    gSprites[gUnknown_0300127C->unk298.field1].invisible = 1;
}
