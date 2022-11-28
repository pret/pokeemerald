#include "global.h"
#include "bg.h"
#include "window.h"
#include "pokenav.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "menu.h"
#include "menu_specialized.h"
#include "mon_markings.h"
#include "palette.h"
#include "pokenav.h"
#include "scanline_effect.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"

static u32 LoopedTask_TransitionMons(s32);
static u32 LoopedTask_ExitConditionGraphMenu(s32);
static u32 LoopedTask_MoveCursorNoTransition(s32);
static u32 LoopedTask_SlideMonOut(s32);
static u32 LoopedTask_OpenMonMarkingsWindow(s32);
static u32 LoopedTask_CloseMonMarkingsWindow(s32);

static u8 sInitialLoadId; // Never read

const u16 gConditionGraphData_Pal[] = INCBIN_U16("graphics/pokenav/condition/graph_data.gbapal");
const u16 gConditionText_Pal[] = INCBIN_U16("graphics/pokenav/condition/text.gbapal");
static const u32 sConditionGraphData_Gfx[] = INCBIN_U32("graphics/pokenav/condition/graph_data.4bpp.lz");
static const u32 sConditionGraphData_Tilemap[] = INCBIN_U32("graphics/pokenav/condition/graph_data.bin.lz");
static const u16 sMonMarkings_Pal[] = INCBIN_U16("graphics/pokenav/condition/mon_markings.gbapal");

static const struct BgTemplate sMenuBgTemplates[3] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1D,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1E,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sMonNameGenderWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 1,
    .width = 13,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 2
};

static const struct WindowTemplate sListIndexWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x36
};

static const struct WindowTemplate sUnusedWindowTemplate1 =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 0x1C,
    .width = 5,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

static const struct WindowTemplate sUnusedWindowTemplate2 =
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 0x1C,
    .width = 3,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

static const LoopedTask sLoopedTaskFuncs[] =
{
    [CONDITION_FUNC_NONE]           = NULL,
    [CONDITION_FUNC_SLIDE_MON_IN]   = LoopedTask_TransitionMons,
    [CONDITION_FUNC_RETURN]         = LoopedTask_ExitConditionGraphMenu,
    [CONDITION_FUNC_NO_TRANSITION]  = LoopedTask_MoveCursorNoTransition,
    [CONDITION_FUNC_SLIDE_MON_OUT]  = LoopedTask_SlideMonOut,
    [CONDITION_FUNC_ADD_MARKINGS]   = LoopedTask_OpenMonMarkingsWindow,
    [CONDITION_FUNC_CLOSE_MARKINGS] = LoopedTask_CloseMonMarkingsWindow
};

struct Pokenav_ConditionMenuGfx
{
    u32 loopedTaskId;
    u8 tilemapBuffers[3][BG_SCREEN_SIZE];
    u8 filler[2];
    u8 partyPokeballSpriteIds[PARTY_SIZE + 1];
    u32 (*callback)(void);
    s16 monTransitionX;
    u8 monPicSpriteId;
    u16 monPalIndex;
    u16 monGfxTileStart;
    void *monGfxPtr;
    u8 nameGenderWindowId;
    u8 listIndexWindowId;
    u8 unusedWindowId1;
    u8 unusedWindowId2;
    struct MonMarkingsMenu marksMenu;
    struct Sprite *monMarksSprite;
    struct Sprite *conditionSparkleSprites[MAX_CONDITION_SPARKLES];
    u8 windowModeState;
    u8 filler2[0xFA3];
};

extern s8 GetConditionGraphMenuCurrentLoadIndex(void); // This function's declaration here is s8 vs. u8 in pokenav_conditions.c

static u32 LoopedTask_OpenConditionGraphMenu(s32);
static u32 GetConditionGraphMenuLoopedTaskActive(void);
static void CreateConditionMonPic(u8);
static void CreateMonMarkingsOrPokeballIndicators(void);
static void CopyUnusedConditionWindowsToVram(void);
static bool32 UpdateConditionGraphMenuWindows(u8, u16, bool8);
static void VBlankCB_PokenavConditionGraph(void);
static void DoConditionGraphEnterTransition(void);
static void DoConditionGraphExitTransition(void);
static void SetExitVBlank(void);
static void ToggleGraphData(bool8);

bool32 OpenConditionGraphMenu(void)
{
    struct Pokenav_ConditionMenuGfx *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX, sizeof(struct Pokenav_ConditionMenuGfx));

    if (menu == NULL)
        return FALSE;

    menu->monPicSpriteId = SPRITE_NONE;
    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenConditionGraphMenu, 1);
    menu->callback = GetConditionGraphMenuLoopedTaskActive;
    menu->windowModeState = 0;
    return TRUE;
}

void CreateConditionGraphMenuLoopedTask(s32 id)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    menu->loopedTaskId = CreateLoopedTask(sLoopedTaskFuncs[id], 1);
    menu->callback = GetConditionGraphMenuLoopedTaskActive;
}

u32 IsConditionGraphMenuLoopedTaskActive(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    return menu->callback();
}

static u32 GetConditionGraphMenuLoopedTaskActive(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    return IsLoopedTaskActive(menu->loopedTaskId);
}

static u32 LoopedTask_OpenConditionGraphMenu(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        if (LoadConditionGraphMenuGfx() != TRUE)
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 1:
        InitBgTemplates(sMenuBgTemplates, ARRAY_COUNT(sMenuBgTemplates));
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        DecompressAndCopyTileDataToVram(3, gPokenavCondition_Gfx, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(2, sConditionGraphData_Gfx, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 3:
         if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        LZ77UnCompVram(gPokenavCondition_Tilemap, menu->tilemapBuffers[0]);
        SetBgTilemapBuffer(3, menu->tilemapBuffers[0]);
        if (IsConditionMenuSearchMode() == TRUE)
            CopyToBgTilemapBufferRect(3, gPokenavOptions_Tilemap, 0, 5, 9, 4);

        CopyBgTilemapBufferToVram(3);
        CopyPaletteIntoBufferUnfaded(gPokenavCondition_Pal, 0x10, 0x20);
        CopyPaletteIntoBufferUnfaded(gConditionText_Pal, 0xF0, 0x20);
        menu->monTransitionX = -80;
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        LZ77UnCompVram(sConditionGraphData_Tilemap, menu->tilemapBuffers[2]);
        SetBgTilemapBuffer(2, menu->tilemapBuffers[2]);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(gConditionGraphData_Pal, 0x30, 0x20);
        ConditionGraph_InitWindow(2);
        return LT_INC_AND_PAUSE;
    case 5:
        BgDmaFill(1, 0, 0, 1);
        BgDmaFill(1, 17, 1, 1);
        CpuFill32(0, menu->tilemapBuffers[1], BG_SCREEN_SIZE);
        SetBgTilemapBuffer(1, menu->tilemapBuffers[1]);
        return LT_INC_AND_PAUSE;
    case 6:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        menu->nameGenderWindowId = AddWindow(&sMonNameGenderWindowTemplate);
        if (IsConditionMenuSearchMode() == TRUE)
        {
            menu->listIndexWindowId = AddWindow(&sListIndexWindowTemplate);
            menu->unusedWindowId1 = AddWindow(&sUnusedWindowTemplate1);
            menu->unusedWindowId2 = AddWindow(&sUnusedWindowTemplate2);
        }
        DeactivateAllTextPrinters();
        return LT_INC_AND_PAUSE;
    case 7:
        CreateConditionMonPic(0);
        return LT_INC_AND_PAUSE;
    case 8:
        CreateMonMarkingsOrPokeballIndicators();
        return LT_INC_AND_PAUSE;
    case 9:
        if (IsConditionMenuSearchMode() == TRUE)
            CopyUnusedConditionWindowsToVram();
        return LT_INC_AND_PAUSE;
    case 10:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 11:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 12:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 13:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), TRUE) != TRUE)
            return LT_PAUSE;
        PutWindowTilemap(menu->nameGenderWindowId);
        if (IsConditionMenuSearchMode() == TRUE)
        {
            PutWindowTilemap(menu->listIndexWindowId);
            PutWindowTilemap(menu->unusedWindowId1);
            PutWindowTilemap(menu->unusedWindowId2);
        }
        return LT_INC_AND_PAUSE;
    case 14:
        ShowBg(1);
        HideBg(2);
        ShowBg(3);
        if (IsConditionMenuSearchMode() == TRUE)
            PrintHelpBarText(HELPBAR_CONDITION_MON_STATUS);
        return LT_INC_AND_PAUSE;
    case 15:
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        if (!IsConditionMenuSearchMode())
        {
            LoadLeftHeaderGfxForIndex(POKENAV_GFX_PARTY_MENU);
            ShowLeftHeaderGfx(POKENAV_GFX_CONDITION_MENU, TRUE, FALSE);
            ShowLeftHeaderGfx(POKENAV_GFX_PARTY_MENU, TRUE, FALSE);
        }
        return LT_INC_AND_PAUSE;
    case 16:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (!IsConditionMenuSearchMode() && AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        SetVBlankCallback_(VBlankCB_PokenavConditionGraph);
        return LT_INC_AND_PAUSE;
    case 17:
        DoConditionGraphEnterTransition();
        ConditionGraph_InitResetScanline(GetConditionGraphPtr());
        return LT_INC_AND_PAUSE;
    case 18:
        if (ConditionGraph_ResetScanline(GetConditionGraphPtr()))
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 19:
        ToggleGraphData(TRUE);
        return LT_INC_AND_PAUSE;
    case 20:
        if (!ConditionMenu_UpdateMonEnter(GetConditionGraphPtr(), &menu->monTransitionX))
        {
            ResetConditionSparkleSprites(menu->conditionSparkleSprites);
            if (IsConditionMenuSearchMode() == TRUE || GetConditionGraphCurrentListIndex() != GetMonListCount())
                CreateConditionSparkleSprites(menu->conditionSparkleSprites, menu->monPicSpriteId, GetNumConditionMonSparkles());

            return LT_FINISH;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_ExitConditionGraphMenu(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        DoConditionGraphExitTransition();
        DestroyConditionSparkleSprites(menu->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 1:
        if (ConditionMenu_UpdateMonExit(GetConditionGraphPtr(), &menu->monTransitionX))
            return 2;
        ToggleGraphData(FALSE);
        return LT_INC_AND_CONTINUE;
    case 2:
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        if (!IsConditionMenuSearchMode())
            SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive() || MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        FreeConditionSparkles(menu->conditionSparkleSprites);
        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_TransitionMons(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    struct ConditionGraph *graph = GetConditionGraphPtr();

    switch (state)
    {
    case 0:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_INFO);
        return LT_INC_AND_CONTINUE;
    case 1:
        LoadNextConditionMenuMonData(CONDITION_LOAD_GRAPH);
        return LT_INC_AND_CONTINUE;
    case 2:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_PIC);
        DestroyConditionSparkleSprites(menu->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 3:
        ConditionGraph_TryUpdate(graph);
        return LT_INC_AND_CONTINUE;
    case 4:
        if (!MoveConditionMonOffscreen(&menu->monTransitionX))
        {
            CreateConditionMonPic(GetConditionGraphMenuCurrentLoadIndex());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 5:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 8:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 9:
        graph = GetConditionGraphPtr();
        if (!ConditionMenu_UpdateMonEnter(graph, &menu->monTransitionX))
        {
            ResetConditionSparkleSprites(menu->conditionSparkleSprites);
            if (IsConditionMenuSearchMode() != TRUE && GetConditionGraphCurrentListIndex() == GetMonListCount())
                return LT_INC_AND_CONTINUE;

            CreateConditionSparkleSprites(menu->conditionSparkleSprites, menu->monPicSpriteId, GetNumConditionMonSparkles());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_MoveCursorNoTransition(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_INFO);
        return LT_INC_AND_CONTINUE;
    case 1:
        LoadNextConditionMenuMonData(CONDITION_LOAD_GRAPH);
        return LT_INC_AND_CONTINUE;
    case 2:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_PIC);
        return LT_INC_AND_CONTINUE;
    case 3:
        CreateConditionMonPic(GetConditionGraphMenuCurrentLoadIndex());
        return LT_INC_AND_CONTINUE;
    case 4:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 5:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 8:
        if (!ConditionMenu_UpdateMonEnter(GetConditionGraphPtr(), &menu->monTransitionX))
        {
            ResetConditionSparkleSprites(menu->conditionSparkleSprites);
            CreateConditionSparkleSprites(menu->conditionSparkleSprites, menu->monPicSpriteId, GetNumConditionMonSparkles());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_SlideMonOut(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_INFO);
        return LT_INC_AND_CONTINUE;
    case 1:
        LoadNextConditionMenuMonData(CONDITION_LOAD_GRAPH);
        return LT_INC_AND_CONTINUE;
    case 2:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_PIC);
        DestroyConditionSparkleSprites(menu->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 3:
        if (!ConditionMenu_UpdateMonExit(GetConditionGraphPtr(), &menu->monTransitionX))
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 4:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 5:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_OpenMonMarkingsWindow(s32 state)
{
    switch (state)
    {
    case 0:
        OpenMonMarkingsMenu(TryGetMonMarkId(), 176, 32);
        return LT_INC_AND_CONTINUE;
    case 1:
        PrintHelpBarText(HELPBAR_CONDITION_MARKINGS);
        return LT_INC_AND_CONTINUE;
    case 2:
        if (WaitForHelpBar() == TRUE)
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_CloseMonMarkingsWindow(s32 state)
{
    switch (state)
    {
    case 0:
        FreeMonMarkingsMenu();
        return LT_INC_AND_CONTINUE;
    case 1:
        PrintHelpBarText(HELPBAR_CONDITION_MON_STATUS);
        return LT_INC_AND_CONTINUE;
    case 2:
        if (WaitForHelpBar() == TRUE)
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static u8 *UnusedPrintNumberString(u8 *dst, u16 num)
{
    u8 *txtPtr = ConvertIntToDecimalStringN(dst, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    txtPtr = StringCopy(txtPtr, gText_Number2);

    return txtPtr;
}

static bool32 UpdateConditionGraphMenuWindows(u8 mode, u16 bufferIndex, bool8 winMode)
{
    u8 text[32];
    const u8 *str;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (mode)
    {
    case 0:
        FillWindowPixelBuffer(menu->nameGenderWindowId, 0);
        if (IsConditionMenuSearchMode() == TRUE)
            FillWindowPixelBuffer(menu->listIndexWindowId, 0);
        break;
    case 1:
        if (GetConditionGraphCurrentListIndex() != GetMonListCount() - 1 || IsConditionMenuSearchMode() == TRUE)
        {
            str = GetConditionMonNameText(bufferIndex);
            AddTextPrinterParameterized(menu->nameGenderWindowId, FONT_NORMAL, str, 0, 1, 0, NULL);
        }
        break;
    case 2:
        if (IsConditionMenuSearchMode() == TRUE)
        {
            str = GetConditionMonLocationText(bufferIndex);
            AddTextPrinterParameterized(menu->nameGenderWindowId, FONT_NORMAL, str, 0, 17, 0, NULL);
            text[0] = EXT_CTRL_CODE_BEGIN;
            text[1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
            text[2] = TEXT_COLOR_BLUE;
            text[3] = TEXT_COLOR_TRANSPARENT;
            text[4] = TEXT_COLOR_LIGHT_BLUE;
            StringCopy(&text[5], gText_Number2);
            AddTextPrinterParameterized(menu->listIndexWindowId, FONT_NORMAL, text, 4, 1, 0, NULL);
            ConvertIntToDecimalStringN(&text[5], GetConditionMonDataBuffer(), STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(menu->listIndexWindowId, FONT_NORMAL, text, 28, 1, 0, NULL);
        }
        break;
    case 3:
        switch (menu->windowModeState)
        {
        case 0:
            if (winMode)
                CopyWindowToVram(menu->nameGenderWindowId, COPYWIN_FULL);
            else
                CopyWindowToVram(menu->nameGenderWindowId, COPYWIN_GFX);

            if (IsConditionMenuSearchMode() == TRUE)
            {
                menu->windowModeState++;
                return FALSE;
            }
            else
            {
                menu->windowModeState = 0;
                return TRUE;
            }
        case 1:
            if (winMode)
                CopyWindowToVram(menu->listIndexWindowId, COPYWIN_FULL);
            else
                CopyWindowToVram(menu->listIndexWindowId, COPYWIN_GFX);

            menu->windowModeState = 0;
            return TRUE;
        }
    }

    return FALSE;
}

static void CopyUnusedConditionWindowsToVram(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    CopyWindowToVram(menu->unusedWindowId1, COPYWIN_FULL);
    CopyWindowToVram(menu->unusedWindowId2, COPYWIN_FULL);
}

static void SpriteCB_PartyPokeball(struct Sprite *sprite)
{
    if (sprite->data[0] == GetConditionGraphCurrentListIndex())
        StartSpriteAnim(sprite, CONDITION_ICON_SELECTED);
    else
        StartSpriteAnim(sprite, CONDITION_ICON_UNSELECTED);
}

void HighlightCurrentPartyIndexPokeball(struct Sprite *sprite)
{
    if (GetConditionGraphCurrentListIndex() == GetMonListCount() - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(TAG_CONDITION_BALL);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(TAG_CONDITION_CANCEL);
}

void MonMarkingsCallback(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, TryGetMonMarkId());
}

static void CreateMonMarkingsOrPokeballIndicators(void)
{
    struct SpriteSheet sprSheets[4];
    struct SpriteTemplate sprTemplate;
    struct SpritePalette sprPals[3];
    struct SpriteSheet sprSheet;
    struct Sprite *sprite;
    u16 i, spriteId;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    LoadConditionSelectionIcons(sprSheets, &sprTemplate, sprPals);
    if (IsConditionMenuSearchMode() == TRUE)
    {
        // Search Mode, load markings menu
        menu->marksMenu.baseTileTag = TAG_CONDITION_MARKINGS_MENU;
        menu->marksMenu.basePaletteTag = TAG_CONDITION_MARKINGS_MENU;
        InitMonMarkingsMenu(&menu->marksMenu);
        BufferMonMarkingsMenuTiles();
        sprite = CreateMonMarkingAllCombosSprite(TAG_CONDITION_MON_MARKINGS, TAG_CONDITION_MON_MARKINGS, sMonMarkings_Pal);
        sprite->oam.priority = 3;
        sprite->x = 192;
        sprite->y = 32;
        sprite->callback = MonMarkingsCallback;
        menu->monMarksSprite = sprite;
        PokenavFillPalette(IndexOfSpritePaletteTag(TAG_CONDITION_MON_MARKINGS), 0);
    }
    else
    {
        // Party Mode, load Pokéball selection icons
        LoadSpriteSheets(sprSheets);
        Pokenav_AllocAndLoadPalettes(sprPals);

        // Add icons for occupied slots
        for (i = 0; i < GetMonListCount() - 1; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 226, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                menu->partyPokeballSpriteIds[i] = spriteId;
                gSprites[spriteId].data[0] = i;
                gSprites[spriteId].callback = SpriteCB_PartyPokeball;
            }
            else
            {
                menu->partyPokeballSpriteIds[i] = SPRITE_NONE;
            }
        }

        // Add icons for empty slots
        sprTemplate.tileTag = TAG_CONDITION_BALL_PLACEHOLDER;
        sprTemplate.callback = SpriteCallbackDummy;
        for (; i < PARTY_SIZE; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 230, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                menu->partyPokeballSpriteIds[i] = spriteId;
                gSprites[spriteId].oam.size = 0;
            }
            else
            {
                menu->partyPokeballSpriteIds[i] = SPRITE_NONE;
            }
        }

        // Add cancel icon
        sprTemplate.tileTag = TAG_CONDITION_CANCEL;
        sprTemplate.callback = HighlightCurrentPartyIndexPokeball;
        spriteId = CreateSprite(&sprTemplate, 222, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            menu->partyPokeballSpriteIds[i] = spriteId;
            gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
            gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
        }
        else
        {
            menu->partyPokeballSpriteIds[i] = SPRITE_NONE;
        }
    }

    LoadConditionSparkle(&sprSheet, &sprPals[0]);
    LoadSpriteSheet(&sprSheet);
    sprPals[1].data = NULL;
    Pokenav_AllocAndLoadPalettes(sprPals);
}

static void FreeConditionMenuGfx(struct Pokenav_ConditionMenuGfx *menu)
{
    u8 i;

    if (IsConditionMenuSearchMode() == TRUE)
    {
        DestroySprite(menu->monMarksSprite);
        FreeSpriteTilesByTag(TAG_CONDITION_MARKINGS_MENU);
        FreeSpriteTilesByTag(TAG_CONDITION_MON_MARKINGS);
        FreeSpritePaletteByTag(TAG_CONDITION_MARKINGS_MENU);
        FreeSpritePaletteByTag(TAG_CONDITION_MON_MARKINGS);
    }
    else
    {
        for (i = 0; i < PARTY_SIZE + 1; i++)
            DestroySprite(&gSprites[menu->partyPokeballSpriteIds[i]]);

        FreeSpriteTilesByTag(TAG_CONDITION_BALL);
        FreeSpriteTilesByTag(TAG_CONDITION_CANCEL);
        FreeSpriteTilesByTag(TAG_CONDITION_BALL_PLACEHOLDER);
        FreeSpritePaletteByTag(TAG_CONDITION_BALL);
        FreeSpritePaletteByTag(TAG_CONDITION_CANCEL);
    }

    if (menu->monPicSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[menu->monPicSpriteId]);
        FreeSpriteTilesByTag(TAG_CONDITION_MON);
        FreeSpritePaletteByTag(TAG_CONDITION_MON);
    }
}

void FreeConditionGraphMenuSubstruct2(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    RemoveWindow(menu->nameGenderWindowId);
    if (IsConditionMenuSearchMode() == TRUE)
    {
        RemoveWindow(menu->listIndexWindowId);
        RemoveWindow(menu->unusedWindowId1);
        RemoveWindow(menu->unusedWindowId2);
    }
    else
    {
        SetLeftHeaderSpritesInvisibility();
    }

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    FreeConditionMenuGfx(menu);
    SetExitVBlank();
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
}

void MonPicGfxSpriteCallback(struct Sprite *sprite)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    sprite->x = menu->monTransitionX + 38;
}

static void CreateConditionMonPic(u8 id)
{
    struct SpriteTemplate sprTemplate;
    struct SpriteSheet sprSheet;
    struct SpritePalette sprPal;
    u8 spriteId;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    if (menu->monPicSpriteId == SPRITE_NONE)
    {
        LoadConditionMonPicTemplate(&sprSheet, &sprTemplate, &sprPal);
        sprSheet.data = GetConditionMonPicGfx(id);
        sprPal.data = GetConditionMonPal(id);
        menu->monPalIndex = LoadSpritePalette(&sprPal);
        menu->monGfxTileStart = LoadSpriteSheet(&sprSheet);
        spriteId = CreateSprite(&sprTemplate, 38, 104, 0);
        menu->monPicSpriteId = spriteId;
        if (spriteId == MAX_SPRITES)
        {
            FreeSpriteTilesByTag(TAG_CONDITION_MON);
            FreeSpritePaletteByTag(TAG_CONDITION_MON);
            menu->monPicSpriteId = SPRITE_NONE;
        }
        else
        {
            menu->monPicSpriteId = spriteId;
            gSprites[menu->monPicSpriteId].callback = MonPicGfxSpriteCallback;
            menu->monGfxPtr = (void *)VRAM + BG_VRAM_SIZE + (menu->monGfxTileStart * 32);
            menu->monPalIndex = (menu->monPalIndex * 16) + 0x100;
        }
    }
    else
    {
        DmaCopy16Defvars(3, GetConditionMonPicGfx(id), menu->monGfxPtr, MON_PIC_SIZE);
        LoadPalette(GetConditionMonPal(id), menu->monPalIndex, 0x20);
    }
}

static void VBlankCB_PokenavConditionGraph(void)
{
    struct ConditionGraph *graph = GetConditionGraphPtr();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ConditionGraph_Draw(graph);
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void SetExitVBlank(void)
{
    SetPokenavVBlankCallback();
}

static void ToggleGraphData(bool8 showBg)
{
    if (showBg)
        ShowBg(2);
    else
        HideBg(2);
}

static void DoConditionGraphEnterTransition(void)
{
    struct ConditionGraph *graph = GetConditionGraphPtr();
    u8 id = GetConditionGraphMenuCurrentLoadIndex();

    sInitialLoadId = id;
    ConditionGraph_SetNewPositions(graph, graph->savedPositions[CONDITION_GRAPH_LOAD_MAX - 1], graph->savedPositions[id]);
    ConditionGraph_TryUpdate(graph);
}

// Transition the graph back to empty before exiting.
// This is skipped if the player is in party mode and the cursor
// is on Cancel, in which case the graph is already empty.
static void DoConditionGraphExitTransition(void)
{
    struct ConditionGraph *graph = GetConditionGraphPtr();

    if (IsConditionMenuSearchMode() || GetConditionGraphCurrentListIndex() != GetMonListCount() - 1)
        ConditionGraph_SetNewPositions(graph, graph->savedPositions[GetConditionGraphMenuCurrentLoadIndex()], graph->savedPositions[CONDITION_GRAPH_LOAD_MAX - 1]);
}

u8 GetMonMarkingsData(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    if (IsConditionMenuSearchMode() == 1)
        return menu->marksMenu.markings;
    else
        return 0;
}
