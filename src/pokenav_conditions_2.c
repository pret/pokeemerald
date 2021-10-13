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

u32 LoopedTask_TransitionMons(s32);
u32 LoopedTask_ExitPartyConditionMenu(s32);
u32 LoopedTask_MoveCursorNoTransition(s32);
u32 LoopedTask_SlideMonOut(s32);
u32 LoopedTask_OpenMonMarkingsWindow(s32);
u32 LoopedTask_CloseMonMarkingsWindow(s32);

BSS_DATA u8 gUnknown_030012BC;

const u16 gConditionGraphData_Pal[] = INCBIN_U16("graphics/pokenav/condition/graph_data.gbapal");
const u16 gConditionText_Pal[] = INCBIN_U16("graphics/pokenav/condition/text.gbapal");
const u32 gUnknown_08623228[] = INCBIN_U32("graphics/pokenav/8623228.4bpp.lz");
const u32 sConditionGraph_Tilemap[] = INCBIN_U32("graphics/pokenav/862323C.bin.lz");
const u16 sConditionGraphMonMarkingsPal[] = INCBIN_U16("graphics/pokenav/8623338.gbapal");

const struct BgTemplate sPartyConditionBgTemplates[3] =
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

const struct WindowTemplate sMonNameGenderWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 1,
    .width = 13,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 2
};

const struct WindowTemplate sConditionGraphListIdWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x36
};

const struct WindowTemplate sUnusedWindowTemplate1 =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 0x1C,
    .width = 5,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

const struct WindowTemplate sUnusedWindowTemplate2 =
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 0x1C,
    .width = 3,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x44
};

const LoopedTask sPartyConditionLoopedTaskFuncs[] =
{
    [PARTY_CONDITION_FUNC_NONE]           = NULL,
    [PARTY_CONDITION_FUNC_SLIDE_MON_IN]   = LoopedTask_TransitionMons,
    [PARTY_CONDITION_FUNC_RETURN]         = LoopedTask_ExitPartyConditionMenu,
    [PARTY_CONDITION_FUNC_NO_TRANSITION]  = LoopedTask_MoveCursorNoTransition,
    [PARTY_CONDITION_FUNC_SLIDE_MON_OUT]  = LoopedTask_SlideMonOut,
    [PARTY_CONDITION_FUNC_ADD_MARKINGS]   = LoopedTask_OpenMonMarkingsWindow,
    [PARTY_CONDITION_FUNC_CLOSE_MARKINGS] = LoopedTask_CloseMonMarkingsWindow
};

struct Pokenav7Struct
{
    u32 loopedTaskId;
    u8 tilemapBuffers[3][BG_SCREEN_SIZE];
    u8 filler[2];
    u8 partyPokeballSpriteIds[10];
    u32 (*callback)(void);
    s16 monTransitionX;
    u8 monPicSpriteId;
    u16 monPalIndex;
    u16 monGfxTileStart;
    void *unk181C;
    u8 nameGenderWindowId;
    u8 listIndexWindowId;
    u8 unusedWindowId1;
    u8 unusedWindowId2;
    struct MonMarkingsMenu monMarks;
    struct Sprite *monMarksSprite;
    struct Sprite *conditionSparkleSprites[MAX_CONDITION_SPARKLES];
    u8 windowModeState;
    u8 filler2[0x38ac - 0x2909];
};

extern s8 GetMonMarkIndex(void); // This function's declaration here is s8 vs. u8 in pokenav_conditions_1.c

u32 LoopedTask_OpenPartyConditionGraph(s32 state);
u32 GetPartyConditionLoopedTaskActive(void);
void CreateConditionMonPic(u8 var);
void CreateMonMarkingsOrPokeballIndicators(void);
void CopyUnusedConditionWindowsToVram(void);
bool32 UpdateConditionGraphWindows(u8 a0, u16 a1, bool8 a2);
void sub_81CEE44(void);
void DoConditionGraphTransition(void);
void sub_81CEEC8(void);
void sub_81CEE68(void);
void ToggleBg2(bool8 showBg);

// code
bool32 OpenPartyConditionMenu(void)
{
    struct Pokenav7Struct *structPtr = AllocSubstruct(POKENAV_SUBSTRUCT_MON_MARK_MENU, sizeof(struct Pokenav7Struct));

    if (structPtr == NULL)
        return FALSE;

    structPtr->monPicSpriteId = SPRITE_NONE;
    structPtr->loopedTaskId = CreateLoopedTask(LoopedTask_OpenPartyConditionGraph, 1);
    structPtr->callback = GetPartyConditionLoopedTaskActive;
    structPtr->windowModeState = 0;
    return TRUE;
}

void CreatePartyConditionLoopedTask(s32 id)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);
    structPtr->loopedTaskId = CreateLoopedTask(sPartyConditionLoopedTaskFuncs[id], 1);
    structPtr->callback = GetPartyConditionLoopedTaskActive;
}

u32 IsPartyConditionLoopedTaskActive(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);
    return structPtr->callback();
}

u32 GetPartyConditionLoopedTaskActive(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);
    return IsLoopedTaskActive(structPtr->loopedTaskId);
}

u32 LoopedTask_OpenPartyConditionGraph(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    switch (state)
    {
    case 0:
        if (LoadPartyConditionMenuGfx() != TRUE)
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 1:
        InitBgTemplates(sPartyConditionBgTemplates, ARRAY_COUNT(sPartyConditionBgTemplates));
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        DecompressAndCopyTileDataToVram(3, gPokenavCondition_Gfx, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(2, gUnknown_08623228, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 3:
         if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        LZ77UnCompVram(gPokenavCondition_Tilemap, structPtr->tilemapBuffers[0]);
        SetBgTilemapBuffer(3, structPtr->tilemapBuffers[0]);
        if (IsConditionMenuSearchMode() == TRUE)
            CopyToBgTilemapBufferRect(3, gPokenavOptions_Tilemap, 0, 5, 9, 4);

        CopyBgTilemapBufferToVram(3);
        CopyPaletteIntoBufferUnfaded(gPokenavCondition_Pal, 0x10, 0x20);
        CopyPaletteIntoBufferUnfaded(gConditionText_Pal, 0xF0, 0x20);
        structPtr->monTransitionX = -80;
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        LZ77UnCompVram(sConditionGraph_Tilemap, structPtr->tilemapBuffers[2]);
        SetBgTilemapBuffer(2, structPtr->tilemapBuffers[2]);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(gConditionGraphData_Pal, 0x30, 0x20);
        SetConditionGraphIOWindows(2);
        return LT_INC_AND_PAUSE;
    case 5:
        sub_8199DF0(1, 0, 0, 1);
        sub_8199DF0(1, 17, 1, 1);
        CpuFill32(0, structPtr->tilemapBuffers[1], BG_SCREEN_SIZE);
        SetBgTilemapBuffer(1, structPtr->tilemapBuffers[1]);
        return LT_INC_AND_PAUSE;
    case 6:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        structPtr->nameGenderWindowId = AddWindow(&sMonNameGenderWindowTemplate);
        if (IsConditionMenuSearchMode() == TRUE)
        {
            structPtr->listIndexWindowId = AddWindow(&sConditionGraphListIdWindowTemplate);
            structPtr->unusedWindowId1 = AddWindow(&sUnusedWindowTemplate1);
            structPtr->unusedWindowId2 = AddWindow(&sUnusedWindowTemplate2);
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
        UpdateConditionGraphWindows(0, GetMonMarkIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 11:
        UpdateConditionGraphWindows(1, GetMonMarkIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 12:
        UpdateConditionGraphWindows(2, GetMonMarkIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 13:
        if (UpdateConditionGraphWindows(3, GetMonMarkIndex(), TRUE) != TRUE)
            return LT_PAUSE;
        PutWindowTilemap(structPtr->nameGenderWindowId);
        if (IsConditionMenuSearchMode() == TRUE)
        {
            PutWindowTilemap(structPtr->listIndexWindowId);
            PutWindowTilemap(structPtr->unusedWindowId1);
            PutWindowTilemap(structPtr->unusedWindowId2);
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
        PokenavFadeScreen(1);
        if (!IsConditionMenuSearchMode())
        {
            LoadLeftHeaderGfxForIndex(POKENAV_GFX_PARTY_MENU);
            ShowLeftHeaderGfx(POKENAV_GFX_CONDITION_MENU, TRUE, 0);
            ShowLeftHeaderGfx(POKENAV_GFX_PARTY_MENU, TRUE, 0);
        }
        return LT_INC_AND_PAUSE;
    case 16:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (!IsConditionMenuSearchMode() && AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        SetVBlankCallback_(sub_81CEE44);
        return LT_INC_AND_PAUSE;
    case 17:
        DoConditionGraphTransition();
        InitConditionGraphState(GetConditionGraphDataPtr());
        return LT_INC_AND_PAUSE;
    case 18:
        if (SetupConditionGraphScanlineParams(GetConditionGraphDataPtr()))
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 19:
        ToggleBg2(TRUE);
        return LT_INC_AND_PAUSE;
    case 20:
        if (!TryUpdateConditionMonTransitionOn(GetConditionGraphDataPtr(), &structPtr->monTransitionX))
        {
            ResetConditionSparkleSprites(structPtr->conditionSparkleSprites);
            if (IsConditionMenuSearchMode() == TRUE || GetConditionGraphCurrentMonIndex() != GetMonListCount())
                CreateConditionSparkleSprites(structPtr->conditionSparkleSprites, structPtr->monPicSpriteId, GetMonSheen());

            return LT_FINISH;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

u32 LoopedTask_ExitPartyConditionMenu(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    switch (state)
    {
    case 0:
        sub_81CEEC8();
        DestroyConditionSparkleSprites(structPtr->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 1:
        if (TryUpdateConditionMonTransitionOff(GetConditionGraphDataPtr(), &structPtr->monTransitionX))
            return 2;
        ToggleBg2(FALSE);
        return LT_INC_AND_CONTINUE;
    case 2:
        PokenavFadeScreen(0);
        if (!IsConditionMenuSearchMode())
            SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive() || MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        FreeConditionSparkles(structPtr->conditionSparkleSprites);
        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

u32 LoopedTask_TransitionMons(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);
    struct ConditionGraph *unkPtr = GetConditionGraphDataPtr();

    switch (state)
    {
    case 0:
        SetConditionGraphData(0);
        return LT_INC_AND_CONTINUE;
    case 1:
        SetConditionGraphData(1);
        return LT_INC_AND_CONTINUE;
    case 2:
        SetConditionGraphData(2);
        DestroyConditionSparkleSprites(structPtr->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 3:
        TransitionConditionGraph(unkPtr);
        return LT_INC_AND_CONTINUE;
    case 4:
        if (!MoveConditionMonOffscreen(&structPtr->monTransitionX))
        {
            CreateConditionMonPic(GetMonMarkIndex());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 5:
        UpdateConditionGraphWindows(0, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphWindows(1, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        UpdateConditionGraphWindows(2, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 8:
        if (UpdateConditionGraphWindows(3, GetMonMarkIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 9:
        unkPtr = GetConditionGraphDataPtr();
        if (!TryUpdateConditionMonTransitionOn(unkPtr, &structPtr->monTransitionX))
        {
            ResetConditionSparkleSprites(structPtr->conditionSparkleSprites);
            if (IsConditionMenuSearchMode() != TRUE && GetConditionGraphCurrentMonIndex() == GetMonListCount())
                return LT_INC_AND_CONTINUE;

            CreateConditionSparkleSprites(structPtr->conditionSparkleSprites, structPtr->monPicSpriteId, GetMonSheen());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

u32 LoopedTask_MoveCursorNoTransition(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    switch (state)
    {
    case 0:
        SetConditionGraphData(0);
        return LT_INC_AND_CONTINUE;
    case 1:
        SetConditionGraphData(1);
        return LT_INC_AND_CONTINUE;
    case 2:
        SetConditionGraphData(2);
        return LT_INC_AND_CONTINUE;
    case 3:
        CreateConditionMonPic(GetMonMarkIndex());
        return LT_INC_AND_CONTINUE;
    case 4:
        UpdateConditionGraphWindows(0, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 5:
        UpdateConditionGraphWindows(1, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphWindows(2, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        if (UpdateConditionGraphWindows(3, GetMonMarkIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 8:
        if (!TryUpdateConditionMonTransitionOn(GetConditionGraphDataPtr(), &structPtr->monTransitionX))
        {
            ResetConditionSparkleSprites(structPtr->conditionSparkleSprites);
            CreateConditionSparkleSprites(structPtr->conditionSparkleSprites, structPtr->monPicSpriteId, GetMonSheen());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

u32 LoopedTask_SlideMonOut(s32 state)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    switch (state)
    {
    case 0:
        SetConditionGraphData(0);
        return LT_INC_AND_CONTINUE;
    case 1:
        SetConditionGraphData(1);
        return LT_INC_AND_CONTINUE;
    case 2:
        SetConditionGraphData(2);
        DestroyConditionSparkleSprites(structPtr->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 3:
        if (!TryUpdateConditionMonTransitionOff(GetConditionGraphDataPtr(), &structPtr->monTransitionX))
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 4:
        UpdateConditionGraphWindows(0, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 5:
        UpdateConditionGraphWindows(1, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphWindows(2, GetMonMarkIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        if (UpdateConditionGraphWindows(3, GetMonMarkIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    }

    return LT_FINISH;
}

u32 LoopedTask_OpenMonMarkingsWindow(s32 state)
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

u32 LoopedTask_CloseMonMarkingsWindow(s32 state)
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

bool32 UpdateConditionGraphWindows(u8 mode, u16 bufferIndex, bool8 winMode)
{
    u8 text[32];
    const u8 *str;
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    switch (mode)
    {
    case 0:
        FillWindowPixelBuffer(structPtr->nameGenderWindowId, 0);
        if (IsConditionMenuSearchMode() == TRUE)
            FillWindowPixelBuffer(structPtr->listIndexWindowId, 0);
        break;
    case 1:
        if (GetConditionGraphCurrentMonIndex() != GetMonListCount() - 1 || IsConditionMenuSearchMode() == TRUE)
        {
            str = GetConditionMonNameBuffer(bufferIndex);
            AddTextPrinterParameterized(structPtr->nameGenderWindowId, 1, str, 0, 1, 0, NULL);
        }
        break;
    case 2:
        if (IsConditionMenuSearchMode() == TRUE)
        {
            str = GetConditionMonLocationBuffer(bufferIndex);
            AddTextPrinterParameterized(structPtr->nameGenderWindowId, 1, str, 0, 17, 0, NULL);
            text[0] = EXT_CTRL_CODE_BEGIN;
            text[1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
            text[2] = TEXT_COLOR_BLUE;
            text[3] = TEXT_COLOR_TRANSPARENT;
            text[4] = TEXT_COLOR_LIGHT_BLUE;
            StringCopy(text + 5, gText_Number2);
            AddTextPrinterParameterized(structPtr->listIndexWindowId, 1, text, 4, 1, 0, NULL);
            ConvertIntToDecimalStringN(text + 5, GetConditionMonDataBuffer(), STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(structPtr->listIndexWindowId, 1, text, 28, 1, 0, NULL);
        }
        break;
    case 3:
        switch (structPtr->windowModeState)
        {
        case 0:
            if (winMode)
                CopyWindowToVram(structPtr->nameGenderWindowId, 3);
            else
                CopyWindowToVram(structPtr->nameGenderWindowId, 2);

            if (IsConditionMenuSearchMode() == TRUE)
            {
                structPtr->windowModeState++;
                return FALSE;
            }
            else
            {
                structPtr->windowModeState = 0;
                return TRUE;
            }
        case 1:
            if (winMode)
                CopyWindowToVram(structPtr->listIndexWindowId, 3);
            else
                CopyWindowToVram(structPtr->listIndexWindowId, 2);

            structPtr->windowModeState = 0;
            return TRUE;
        }
    }

    return FALSE;
}

void CopyUnusedConditionWindowsToVram(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    CopyWindowToVram(structPtr->unusedWindowId1, 3);
    CopyWindowToVram(structPtr->unusedWindowId2, 3);
}

void sub_81CE964(struct Sprite *sprite)
{
    if (sprite->data[0] == GetConditionGraphCurrentMonIndex())
        StartSpriteAnim(sprite, 0);
    else
        StartSpriteAnim(sprite, 1);
}

void HighlightCurrentPartyIndexPokeball(struct Sprite *sprite)
{
    if (GetConditionGraphCurrentMonIndex() == GetMonListCount() - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(0x65);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(0x66);
}

void MonMarkingsCallback(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, TryGetMonMarkId());
}

void CreateMonMarkingsOrPokeballIndicators(void)
{
    struct SpriteSheet sprSheets[4];
    struct SpriteTemplate sprTemplate;
    struct SpritePalette sprPals[3];
    struct SpriteSheet sprSheet;
    struct Sprite *sprite;
    u16 i, spriteId;
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    LoadConditionSelectionIcons(sprSheets, &sprTemplate, sprPals);
    if (IsConditionMenuSearchMode() == TRUE)
    {
        structPtr->monMarks.baseTileTag = 0x6A;
        structPtr->monMarks.basePaletteTag = 0x6A;
        InitMonMarkingsMenu(&structPtr->monMarks);
        BufferMonMarkingsMenuTiles();
        sprite = CreateMonMarkingAllCombosSprite(0x69, 0x69, sConditionGraphMonMarkingsPal);
        sprite->oam.priority = 3;
        sprite->x = 192;
        sprite->y = 32;
        sprite->callback = MonMarkingsCallback;
        structPtr->monMarksSprite = sprite;
        PokenavFillPalette(IndexOfSpritePaletteTag(0x69), 0);
    }
    else
    {
        // party mode -> add pokeballs on right hand side
        LoadSpriteSheets(sprSheets);
        Pokenav_AllocAndLoadPalettes(sprPals);
        for (i = 0; i < GetMonListCount() - 1; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 226, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                structPtr->partyPokeballSpriteIds[i] = spriteId;
                gSprites[spriteId].data[0] = i;
                gSprites[spriteId].callback = sub_81CE964;
            }
            else
            {
                structPtr->partyPokeballSpriteIds[i] = SPRITE_NONE;
            }
        }

        sprTemplate.tileTag = 0x67;
        sprTemplate.callback = SpriteCallbackDummy;
        for (; i < 6; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 230, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                structPtr->partyPokeballSpriteIds[i] = spriteId;
                gSprites[spriteId].oam.size = 0;
            }
            else
            {
                structPtr->partyPokeballSpriteIds[i] = SPRITE_NONE;
            }
        }

        sprTemplate.tileTag = 0x66;
        sprTemplate.callback = HighlightCurrentPartyIndexPokeball;
        spriteId = CreateSprite(&sprTemplate, 222, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            structPtr->partyPokeballSpriteIds[i] = spriteId;
            gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
            gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
        }
        else
        {
            structPtr->partyPokeballSpriteIds[i] = SPRITE_NONE;
        }
    }

    LoadConditionSparkle(&sprSheet, &sprPals[0]);
    LoadSpriteSheet(&sprSheet);
    sprPals[1].data = NULL;
    Pokenav_AllocAndLoadPalettes(sprPals);
}

void sub_81CEBF4(struct Pokenav7Struct *structPtr)
{
    u8 i;

    if (IsConditionMenuSearchMode() == TRUE)
    {
        DestroySprite(structPtr->monMarksSprite);
        FreeSpriteTilesByTag(0x6A);
        FreeSpriteTilesByTag(0x69);
        FreeSpritePaletteByTag(0x6A);
        FreeSpritePaletteByTag(0x69);
    }
    else
    {
        for (i = 0; i < 7; i++)
            DestroySprite(&gSprites[structPtr->partyPokeballSpriteIds[i]]);

        FreeSpriteTilesByTag(0x65);
        FreeSpriteTilesByTag(0x66);
        FreeSpriteTilesByTag(0x67);
        FreeSpritePaletteByTag(0x65);
        FreeSpritePaletteByTag(0x66);
    }

    if (structPtr->monPicSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[structPtr->monPicSpriteId]);
        FreeSpriteTilesByTag(0x64);
        FreeSpritePaletteByTag(0x64);
    }
}

void FreePartyConditionSubstruct2(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    RemoveWindow(structPtr->nameGenderWindowId);
    if (IsConditionMenuSearchMode() == TRUE)
    {
        RemoveWindow(structPtr->listIndexWindowId);
        RemoveWindow(structPtr->unusedWindowId1);
        RemoveWindow(structPtr->unusedWindowId2);
    }
    else
    {
        SetLeftHeaderSpritesInvisibility();
    }

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    sub_81CEBF4(structPtr);
    sub_81CEE68();
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_MARK_MENU);
}

void MonPicGfxSpriteCallback(struct Sprite *sprite)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);
    sprite->x = structPtr->monTransitionX + 38;
}

void CreateConditionMonPic(u8 id)
{
    struct SpriteTemplate sprTemplate;
    struct SpriteSheet sprSheet;
    struct SpritePalette sprPal;
    u8 spriteId;
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    if (structPtr->monPicSpriteId == SPRITE_NONE)
    {
        LoadConditionMonPicTemplate(&sprSheet, &sprTemplate, &sprPal);
        sprSheet.data = GetConditionMonPicGfx(id);
        sprPal.data = GetConditionMonPal(id);
        structPtr->monPalIndex = LoadSpritePalette(&sprPal);
        structPtr->monGfxTileStart = LoadSpriteSheet(&sprSheet);
        spriteId = CreateSprite(&sprTemplate, 38, 104, 0);
        structPtr->monPicSpriteId = spriteId;
        if (spriteId == MAX_SPRITES)
        {
            FreeSpriteTilesByTag(0x64);
            FreeSpritePaletteByTag(0x64);
            structPtr->monPicSpriteId = SPRITE_NONE;
        }
        else
        {
            structPtr->monPicSpriteId = spriteId;
            gSprites[structPtr->monPicSpriteId].callback = MonPicGfxSpriteCallback;
            structPtr->unk181C = (void*)(VRAM) + 0x10000 + (structPtr->monGfxTileStart * 32);
            structPtr->monPalIndex = (structPtr->monPalIndex * 16) + 0x100;
        }
    }
    else
    {
        DmaCopy16Defvars(3, GetConditionMonPicGfx(id), structPtr->unk181C, MON_PIC_SIZE);
        LoadPalette(GetConditionMonPal(id), structPtr->monPalIndex, 0x20);
    }
}

void sub_81CEE44(void)
{
    struct ConditionGraph *unk = GetConditionGraphDataPtr();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_81D2108(unk);
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_81CEE68(void)
{
    SetPokenavVBlankCallback();
}

void ToggleBg2(bool8 showBg)
{
    if (showBg)
        ShowBg(2);
    else
        HideBg(2);
}

void DoConditionGraphTransition(void)
{
    struct ConditionGraph *conditionPtr = GetConditionGraphDataPtr();
    u8 id = GetMonMarkIndex();

    gUnknown_030012BC = id;
    sub_81D1F84(conditionPtr, conditionPtr->unk14[3], conditionPtr->unk14[id]);
    TransitionConditionGraph(conditionPtr);
}

void sub_81CEEC8(void)
{
    struct ConditionGraph *conditionPtr = GetConditionGraphDataPtr();

    if (IsConditionMenuSearchMode() || GetConditionGraphCurrentMonIndex() != GetMonListCount() - 1)
        sub_81D1F84(conditionPtr, conditionPtr->unk14[GetMonMarkIndex()], conditionPtr->unk14[3]);
}

u8 GetMonMarkingsData(void)
{
    struct Pokenav7Struct *structPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_MARK_MENU);

    if (IsConditionMenuSearchMode() == 1)
        return structPtr->monMarks.markings;
    else
        return 0;
}
