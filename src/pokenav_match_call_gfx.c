#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "international_string_util.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "region_map.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/game_stat.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"

#define GFXTAG_CURSOR 7
#define GFXTAG_TRAINER_PIC 8
#define PALTAG_CURSOR 12
#define PALTAG_TRAINER_PIC 13

struct Pokenav_MatchCallGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopTaskId;
    u8 filler8[6];
    bool8 skipHangUpSE;
    bool8 newRematchRequest;
    u16 locWindowId;
    u16 infoBoxWindowId;
    u16 msgBoxWindowId;
    s16 pageDelta;
    u8 unused18;
    u8 unused19;
    u16 trainerPicPalOffset;
    struct Sprite *optionsCursorSprite;
    struct Sprite *trainerPicSprite;
    u8 bgTilemapBuffer1[BG_SCREEN_SIZE];
    u8 unusedTilemapBuffer[BG_SCREEN_SIZE];
    u8 bgTilemapBuffer2[BG_SCREEN_SIZE];
    u8 *trainerPicGfxPtr;
    u8 trainerPicGfx[TRAINER_PIC_SIZE];
    u8 trainerPicPal[0x20];
};

static bool32 GetCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenMatchCall(s32);
static void CreateMatchCallList(void);
static void DestroyMatchCallList(void);
static void FreeMatchCallSprites(void);
static void LoadCallWindowAndFade(struct Pokenav_MatchCallGfx *);
static void DrawMatchCallLeftColumnWindows(struct Pokenav_MatchCallGfx *);
static void UpdateMatchCallInfoBox(struct Pokenav_MatchCallGfx *);
static void PrintMatchCallLocation(struct Pokenav_MatchCallGfx *, int);
static void AllocMatchCallSprites(void);
static void SetPokeballIconsFlashing(bool32);
static void PrintMatchCallSelectionOptions(struct Pokenav_MatchCallGfx *);
static bool32 ShowOptionsCursor(struct Pokenav_MatchCallGfx *);
static void UpdateCursorGfxPos(struct Pokenav_MatchCallGfx *, int);
static bool32 IsDma3ManagerBusyWithBgCopy1(struct Pokenav_MatchCallGfx *);
static void UpdateWindowsReturnToTrainerList(struct Pokenav_MatchCallGfx *);
static void DrawMsgBoxForMatchCallMsg(struct Pokenav_MatchCallGfx *);
static bool32 IsDma3ManagerBusyWithBgCopy2(struct Pokenav_MatchCallGfx *);
static void PrintCallingDots(struct Pokenav_MatchCallGfx *);
static bool32 WaitForCallingDotsText(struct Pokenav_MatchCallGfx *);
static void PrintMatchCallMessage(struct Pokenav_MatchCallGfx *);
static bool32 WaitForMatchCallMessageText(struct Pokenav_MatchCallGfx *);
static void DrawMsgBoxForCloseByMsg(struct Pokenav_MatchCallGfx *);
static void PrintTrainerIsCloseBy(struct Pokenav_MatchCallGfx *);
static bool32 WaitForTrainerIsCloseByText(struct Pokenav_MatchCallGfx *);
static void EraseCallMessageBox(struct Pokenav_MatchCallGfx *);
static bool32 WaitForCallMessageBoxErase(struct Pokenav_MatchCallGfx *);
static void UpdateWindowsToShowCheckPage(struct Pokenav_MatchCallGfx *);
static void LoadCheckPageTrainerPic(struct Pokenav_MatchCallGfx *);
static bool32 WaitForTrainerPic(struct Pokenav_MatchCallGfx *);
static void TrainerPicSlideOffscreen(struct Pokenav_MatchCallGfx *);
static void Task_FlashPokeballIcons(u8);
static void TryDrawRematchPokeballIcon(u16, u32, u32);
static void PrintNumberRegisteredLabel(u16);
static void PrintNumberRegistered(u16);
static void PrintNumberOfBattlesLabel(u16);
static void PrintNumberOfBattles(u16);
static void PrintMatchCallInfoLabel(u16, const u8 *, int);
static void PrintMatchCallInfoNumber(u16, const u8 *, int);
static void CreateOptionsCursorSprite(struct Pokenav_MatchCallGfx *, int);
static void CloseMatchCallSelectOptionsWindow(struct Pokenav_MatchCallGfx *);
static struct Sprite *CreateTrainerPicSprite(void);
static void SpriteCB_TrainerPicSlideOnscreen(struct Sprite *);
static void SpriteCB_TrainerPicSlideOffscreen(struct Sprite *);
static void SpriteCB_OptionsCursor(struct Sprite *);
static u32 MatchCallListCursorDown(s32);
static u32 MatchCallListCursorUp(s32);
static u32 MatchCallListPageDown(s32);
static u32 MatchCallListPageUp(s32);
static u32 SelectMatchCallEntry(s32);
static u32 MoveMatchCallOptionsCursor(s32);
static u32 CancelMatchCallSelection(s32);
static u32 DoMatchCallMessage(s32);
static u32 DoTrainerCloseByMessage(s32);
static u32 CloseMatchCallMessage(s32);
static u32 ShowCheckPage(s32);
static u32 ShowCheckPageUp(s32);
static u32 ShowCheckPageDown(s32);
static u32 ExitCheckPage(s32);
static u32 ExitMatchCall(s32);

static const u16 sMatchCallUI_Pal[] = INCBIN_U16("graphics/pokenav/match_call/ui.gbapal");
static const u32 sMatchCallUI_Gfx[] = INCBIN_U32("graphics/pokenav/match_call/ui.4bpp.lz");
static const u32 sMatchCallUI_Tilemap[] = INCBIN_U32("graphics/pokenav/match_call/ui.bin.lz");
static const u16 sOptionsCursor_Pal[] = INCBIN_U16("graphics/pokenav/match_call/options_cursor.gbapal");
static const u32 sOptionsCursor_Gfx[] = INCBIN_U32("graphics/pokenav/match_call/options_cursor.4bpp.lz");
static const u16 sCallWindow_Pal[] = INCBIN_U16("graphics/pokenav/match_call/call_window.gbapal");
static const u16 sListWindow_Pal[] = INCBIN_U16("graphics/pokenav/match_call/list_window.gbapal");
static const u16 sPokeball_Pal[] = INCBIN_U16("graphics/pokenav/match_call/pokeball.gbapal");
static const u32 sPokeball_Gfx[] = INCBIN_U32("graphics/pokenav/match_call/pokeball.4bpp.lz");

static const struct BgTemplate sMatchCallBgTemplates[3] =
{
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x80
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x07,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const LoopedTask sMatchCallLoopTaskFuncs[] =
{
    [POKENAV_MC_FUNC_NONE]                = NULL,
    [POKENAV_MC_FUNC_DOWN]                = MatchCallListCursorDown,
    [POKENAV_MC_FUNC_UP]                  = MatchCallListCursorUp,
    [POKENAV_MC_FUNC_PG_DOWN]             = MatchCallListPageDown,
    [POKENAV_MC_FUNC_PG_UP]               = MatchCallListPageUp,
    [POKENAV_MC_FUNC_SELECT]              = SelectMatchCallEntry,
    [POKENAV_MC_FUNC_MOVE_OPTIONS_CURSOR] = MoveMatchCallOptionsCursor,
    [POKENAV_MC_FUNC_CANCEL]              = CancelMatchCallSelection,
    [POKENAV_MC_FUNC_CALL_MSG]            = DoMatchCallMessage,
    [POKENAV_MC_FUNC_NEARBY_MSG]          = DoTrainerCloseByMessage,
    [POKENAV_MC_FUNC_EXIT_CALL]           = CloseMatchCallMessage,
    [POKENAV_MC_FUNC_SHOW_CHECK_PAGE]     = ShowCheckPage,
    [POKENAV_MC_FUNC_CHECK_PAGE_UP]       = ShowCheckPageUp,
    [POKENAV_MC_FUNC_CHECK_PAGE_DOWN]     = ShowCheckPageDown,
    [POKENAV_MC_FUNC_EXIT_CHECK_PAGE]     = ExitCheckPage,
    [POKENAV_MC_FUNC_EXIT]                = ExitMatchCall
};

static const struct WindowTemplate sMatchCallLocationWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 0,
    .tilemapTop = 5,
    .width = 11,
    .height = 2,
    .paletteNum = 2,
    .baseBlock = 16
};

static const struct WindowTemplate sMatchCallInfoBoxWindowTemplate =
{
    .bg = 2,
    .tilemapLeft = 0,
    .tilemapTop = 9,
    .width = 11,
    .height = 8,
    .paletteNum = 2,
    .baseBlock = 38
};

static const u8 *const sMatchCallOptionTexts[MATCH_CALL_OPTION_COUNT] =
{
    [MATCH_CALL_OPTION_CALL]   = gText_Call,
    [MATCH_CALL_OPTION_CHECK]  = gText_Check,
    [MATCH_CALL_OPTION_CANCEL] = gText_Cancel6
};

// The series of 5 dots that appear when someone is called with Match Call
static const u8 sText_CallingDots[] = _("·{PAUSE 4}·{PAUSE 4}·{PAUSE 4}·{PAUSE 4}·\p");

static const struct WindowTemplate sCallMsgBoxWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 12,
    .width = 28,
    .height = 4,
    .paletteNum = 1,
    .baseBlock = 10
};

static const struct CompressedSpriteSheet sOptionsCursorSpriteSheets[1] =
{
    {sOptionsCursor_Gfx, 0x40, GFXTAG_CURSOR}
};

static const struct SpritePalette sOptionsCursorSpritePalettes[2] =
{
    {sOptionsCursor_Pal, PALTAG_CURSOR}
};

static const struct OamData sOptionsCursorOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sOptionsCursorSpriteTemplate =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .oam = &sOptionsCursorOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_OptionsCursor,
};

static const struct OamData sTrainerPicOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sTrainerPicSpriteTemplate =
{
    .tileTag = GFXTAG_TRAINER_PIC,
    .paletteTag = PALTAG_TRAINER_PIC,
    .oam = &sTrainerPicOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

bool32 OpenMatchCall(void)
{
    struct Pokenav_MatchCallGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN, sizeof(struct Pokenav_MatchCallGfx));
    if (!gfx)
        return FALSE;

    gfx->unused19 = 0;
    gfx->loopTaskId = CreateLoopedTask(LoopedTask_OpenMatchCall, 1);
    gfx->isTaskActiveCB = GetCurrentLoopedTaskActive;
    return TRUE;
}

void CreateMatchCallLoopedTask(s32 index)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    gfx->loopTaskId = CreateLoopedTask(sMatchCallLoopTaskFuncs[index], 1);
    gfx->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsMatchCallLoopedTaskActive(void)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    return gfx->isTaskActiveCB();
}

void FreeMatchCallSubstruct2(void)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    FreeMatchCallSprites();
    DestroyMatchCallList();
    RemoveWindow(gfx->infoBoxWindowId);
    RemoveWindow(gfx->locWindowId);
    RemoveWindow(gfx->msgBoxWindowId);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    return IsLoopedTaskActive(gfx->loopTaskId);
}

static u32 LoopedTask_OpenMatchCall(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        InitBgTemplates(sMatchCallBgTemplates, ARRAY_COUNT(sMatchCallBgTemplates));
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        DecompressAndCopyTileDataToVram(2, sMatchCallUI_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(2, gfx->bgTilemapBuffer2);
        CopyToBgTilemapBuffer(2, sMatchCallUI_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(sMatchCallUI_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(2);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        BgDmaFill(1, 0, 0, 1);
        SetBgTilemapBuffer(1, gfx->bgTilemapBuffer1);
        FillBgTilemapBufferRect_Palette0(1, 0x1000, 0, 0, 32, 20);
        CopyPaletteIntoBufferUnfaded(sCallWindow_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        LoadCallWindowAndFade(gfx);
        DecompressAndCopyTileDataToVram(3, sPokeball_Gfx, 0, 0, 0);
        CopyPaletteIntoBufferUnfaded(sListWindow_Pal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
        CopyPaletteIntoBufferUnfaded(sPokeball_Pal, BG_PLTT_ID(5), PLTT_SIZE_4BPP);
        return LT_INC_AND_PAUSE;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() || !IsMatchCallListInitFinished())
            return LT_PAUSE;

        CreateMatchCallList();
        return LT_INC_AND_PAUSE;
    case 4:
        if (IsCreatePokenavListTaskActive())
            return LT_PAUSE;

        DrawMatchCallLeftColumnWindows(gfx);
        return LT_INC_AND_PAUSE;
    case 5:
        UpdateMatchCallInfoBox(gfx);
        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 6:
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ShowBg(2);
        ShowBg(3);
        ShowBg(1);
        AllocMatchCallSprites();
        LoadLeftHeaderGfxForIndex(3);
        ShowLeftHeaderGfx(POKENAV_GFX_MATCH_CALL_MENU, TRUE, FALSE);
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        return LT_INC_AND_PAUSE;
    case 7:
        if (IsPaletteFadeActive() || AreLeftHeaderSpritesMoving())
            return LT_PAUSE;

        SetPokeballIconsFlashing(TRUE);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

static u32 MatchCallListCursorDown(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        switch (PokenavList_MoveCursorDown())
        {
        case 0:
            break;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            // fall through
        default:
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 MatchCallListCursorUp(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        switch (PokenavList_MoveCursorUp())
        {
        case 0:
            break;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            // fall through
        default:
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 MatchCallListPageDown(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        switch (PokenavList_PageDown())
        {
        case 0:
            break;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            // fall through
        default:
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 MatchCallListPageUp(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        switch (PokenavList_PageUp())
        {
        case 0:
            break;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            // fall through
        default:
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(gfx, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 SelectMatchCallEntry(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintMatchCallSelectionOptions(gfx);
        PrintHelpBarText(HELPBAR_MC_CALL_MENU);
        return LT_INC_AND_PAUSE;
    case 1:
        if (ShowOptionsCursor(gfx))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 MoveMatchCallOptionsCursor(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx;
    u16 cursorPos;

    PlaySE(SE_SELECT);
    gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    cursorPos = GetMatchCallOptionCursorPos();
    UpdateCursorGfxPos(gfx, cursorPos);
    return LT_FINISH;
}

static u32 CancelMatchCallSelection(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        UpdateWindowsReturnToTrainerList(gfx);
        PrintHelpBarText(HELPBAR_MC_TRAINER_LIST);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy1(gfx))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 DoMatchCallMessage(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        PokenavList_ToggleVerticalArrows(TRUE);
        DrawMsgBoxForMatchCallMsg(gfx);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy2(gfx))
            return LT_PAUSE;

        PrintCallingDots(gfx);
        PlaySE(SE_POKENAV_CALL);
        gfx->skipHangUpSE = FALSE;
        return LT_INC_AND_PAUSE;
    case 2:
        if (WaitForCallingDotsText(gfx))
            return LT_PAUSE;

        PrintMatchCallMessage(gfx);
        return LT_INC_AND_PAUSE;
    case 3:
        if (WaitForMatchCallMessageText(gfx))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 DoTrainerCloseByMessage(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        DrawMsgBoxForCloseByMsg(gfx);
        PokenavList_ToggleVerticalArrows(TRUE);
        gfx->skipHangUpSE = TRUE;
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy2(gfx))
            return LT_PAUSE;

        PrintTrainerIsCloseBy(gfx);
        return LT_INC_AND_PAUSE;
    case 2:
        if (WaitForTrainerIsCloseByText(gfx))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 CloseMatchCallMessage(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    u32 result = LT_INC_AND_PAUSE;

    switch (state)
    {
    case 0:
        if (!gfx->skipHangUpSE)
            PlaySE(SE_POKENAV_HANG_UP);

        PlaySE(SE_SELECT);
        break;
    case 1:
        EraseCallMessageBox(gfx);
        break;
    case 2:
        if (WaitForCallMessageBoxErase(gfx))
            result = LT_PAUSE;
        break;
    case 3:
        UpdateWindowsReturnToTrainerList(gfx);
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy1(gfx))
            result = LT_PAUSE;

        PrintHelpBarText(HELPBAR_MC_TRAINER_LIST);
        break;
    case 5:
        if (WaitForHelpBar())
        {
            result = LT_PAUSE;
        }
        else
        {
            if (gfx->newRematchRequest)
            {
                // This call was a new rematch request,
                // add the Pokéball icon to their entry
                PokenavList_DrawCurrentItemIcon();
                result = LT_INC_AND_CONTINUE;
            }
            else
            {
                PokenavList_ToggleVerticalArrows(FALSE);
                result = LT_FINISH;
            }
        }
        break;
    case 6:
        if (IsDma3ManagerBusyWithBgCopy())
        {
            result = LT_PAUSE;
        }
        else
        {
            PokenavList_ToggleVerticalArrows(FALSE);
            result = LT_FINISH;
        }
        break;
    }

    return result;
}

static u32 ShowCheckPage(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavList_EraseListForCheckPage();
        UpdateWindowsToShowCheckPage(gfx);
        return LT_INC_AND_PAUSE;
    case 1:
        if (PokenavList_IsTaskActive() || IsDma3ManagerBusyWithBgCopy1(gfx))
            return LT_PAUSE;

        PrintHelpBarText(HELPBAR_MC_CHECK_PAGE);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintCheckPageInfo(0);
        LoadCheckPageTrainerPic(gfx);
        return LT_INC_AND_PAUSE;
    case 3:
        if (PokenavList_IsTaskActive() || WaitForTrainerPic(gfx) || WaitForHelpBar())
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 ShowCheckPageDown(s32 state)
{
    int topId;
    int delta;
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        topId = PokenavList_GetTopIndex();
        delta = GetIndexDeltaOfNextCheckPageDown(topId);
        if (delta)
        {
            PlaySE(SE_SELECT);
            gfx->pageDelta = delta;
            TrainerPicSlideOffscreen(gfx);
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (WaitForTrainerPic(gfx))
            return LT_PAUSE;

        PrintMatchCallLocation(gfx, gfx->pageDelta);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintCheckPageInfo(gfx->pageDelta);
        return LT_INC_AND_PAUSE;
    case 3:
        LoadCheckPageTrainerPic(gfx);
        return LT_INC_AND_PAUSE;
    case 4:
        if (PokenavList_IsTaskActive() || WaitForTrainerPic(gfx))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 ExitCheckPage(s32 state)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        TrainerPicSlideOffscreen(gfx);
        PokenavList_ReshowListFromCheckPage();
        return LT_INC_AND_PAUSE;
    case 1:
        if (PokenavList_IsTaskActive() || WaitForTrainerPic(gfx))
            return LT_PAUSE;

        PrintHelpBarText(HELPBAR_MC_TRAINER_LIST);
        UpdateMatchCallInfoBox(gfx);
        return LT_INC_AND_PAUSE;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 ShowCheckPageUp(s32 state)
{
    int topId;
    int delta;
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (state)
    {
    case 0:
        topId = PokenavList_GetTopIndex();
        delta = GetIndexDeltaOfNextCheckPageUp(topId);
        if (delta)
        {
            PlaySE(SE_SELECT);
            gfx->pageDelta = delta;
            TrainerPicSlideOffscreen(gfx);
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (WaitForTrainerPic(gfx))
            return LT_PAUSE;

        PrintMatchCallLocation(gfx, gfx->pageDelta);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintCheckPageInfo(gfx->pageDelta);
        return LT_INC_AND_PAUSE;
    case 3:
        LoadCheckPageTrainerPic(gfx);
        return LT_INC_AND_PAUSE;
    case 4:
        if (PokenavList_IsTaskActive() || WaitForTrainerPic(gfx))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

static u32 ExitMatchCall(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        SetPokeballIconsFlashing(FALSE);
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive() || MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;

        SetLeftHeaderSpritesInvisibility();
        break;
    }

    return LT_FINISH;
}

static void CreateMatchCallList(void)
{
    struct PokenavListTemplate template;
    template.list = (struct PokenavListItem *)GetMatchCallList();
    template.count = GetNumberRegistered();
    template.itemSize = sizeof(struct PokenavListItem);
    template.startIndex = 0;
    template.item_X = 13;
    template.windowWidth = 16;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 3;
    template.fontId = FONT_NARROW;
    template.bufferItemFunc = (PokenavListBufferItemFunc)BufferMatchCallNameAndDesc;
    template.iconDrawFunc = TryDrawRematchPokeballIcon;
    CreatePokenavList(&sMatchCallBgTemplates[2], &template, 2);
    CreateTask(Task_FlashPokeballIcons, 7);
}

static void DestroyMatchCallList(void)
{
    DestroyPokenavList();
    DestroyTask(FindTaskIdByFunc(Task_FlashPokeballIcons));
}

#define tSinIdx data[0]
#define tSinVal data[1]
#define tActive data[15]

static void SetPokeballIconsFlashing(bool32 active)
{
    u8 taskId = FindTaskIdByFunc(Task_FlashPokeballIcons);
    if (taskId != TASK_NONE)
        gTasks[taskId].tActive = active;
}

static void Task_FlashPokeballIcons(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (tActive)
    {
        tSinIdx += 4;
        tSinIdx &= 0x7F;
        tSinVal = gSineTable[tSinIdx] >> 4;
        PokenavCopyPalette(sPokeball_Pal, &sPokeball_Pal[0x10], 0x10, 0x10, tSinVal, &gPlttBufferUnfaded[0x50]);
        if (!gPaletteFade.active)
            CpuCopy32(&gPlttBufferUnfaded[0x50], &gPlttBufferFaded[0x50], 0x20);
    }
}

#undef tSinIdx
#undef tSinVal
#undef tActive

enum {
    POKEBALL_ICON_TOP = 0x5000,
    POKEBALL_ICON_BOTTOM,
    POKEBALL_ICON_EMPTY,
};

static void TryDrawRematchPokeballIcon(u16 windowId, u32 rematchId, u32 tileOffset)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u16 *tilemap = GetBgTilemapBuffer(bg);
    tilemap += tileOffset * 64 + 0x1D;
    if (ShouldDrawRematchPokeballIcon(rematchId))
    {
        tilemap[0] = POKEBALL_ICON_TOP;
        tilemap[0x20] = POKEBALL_ICON_BOTTOM;
    }
    else
    {
        tilemap[0] = POKEBALL_ICON_EMPTY;
        tilemap[0x20] = POKEBALL_ICON_EMPTY;
    }
}

void ClearRematchPokeballIcon(u16 windowId, u32 tileOffset)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u16 *tilemap = GetBgTilemapBuffer(bg);
    tilemap += tileOffset * 64 + 0x1D;
    tilemap[0] = POKEBALL_ICON_EMPTY;
    tilemap[0x20] = POKEBALL_ICON_EMPTY;
}

static void DrawMatchCallLeftColumnWindows(struct Pokenav_MatchCallGfx *gfx)
{
    gfx->locWindowId = AddWindow(&sMatchCallLocationWindowTemplate);
    gfx->infoBoxWindowId = AddWindow(&sMatchCallInfoBoxWindowTemplate);
    FillWindowPixelBuffer(gfx->locWindowId, PIXEL_FILL(1));
    PutWindowTilemap(gfx->locWindowId);
    FillWindowPixelBuffer(gfx->infoBoxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(gfx->infoBoxWindowId);
    CopyWindowToVram(gfx->locWindowId, COPYWIN_MAP);
}

static void UpdateMatchCallInfoBox(struct Pokenav_MatchCallGfx *gfx)
{
    FillWindowPixelBuffer(gfx->infoBoxWindowId, PIXEL_FILL(1));
    PrintNumberRegisteredLabel(gfx->infoBoxWindowId);
    PrintNumberRegistered(gfx->infoBoxWindowId);
    PrintNumberOfBattlesLabel(gfx->infoBoxWindowId);
    PrintNumberOfBattles(gfx->infoBoxWindowId);
    CopyWindowToVram(gfx->infoBoxWindowId, COPYWIN_GFX);
}

static void PrintNumberRegisteredLabel(u16 windowId)
{
    PrintMatchCallInfoLabel(windowId, gText_NumberRegistered, 0);
}

static void PrintNumberRegistered(u16 windowId)
{
    u8 str[3];
    ConvertIntToDecimalStringN(str, GetNumberRegistered(), STR_CONV_MODE_LEFT_ALIGN, 3);
    PrintMatchCallInfoNumber(windowId, str, 1);
}

static void PrintNumberOfBattlesLabel(u16 windowId)
{
    PrintMatchCallInfoLabel(windowId, gText_NumberOfBattles, 2);
}

static void PrintNumberOfBattles(u16 windowId)
{
    u8 str[5];
    int numTrainerBattles = GetGameStat(GAME_STAT_TRAINER_BATTLES);
    if (numTrainerBattles > 99999)
        numTrainerBattles = 99999;

    ConvertIntToDecimalStringN(str, numTrainerBattles, STR_CONV_MODE_LEFT_ALIGN, 5);
    PrintMatchCallInfoNumber(windowId, str, 3);
}

static void PrintMatchCallInfoLabel(u16 windowId, const u8 *str, int top)
{
    int y = top * 16 + 1;
    AddTextPrinterParameterized(windowId, FONT_NARROW, str, 2, y, TEXT_SKIP_DRAW, NULL);
}

static void PrintMatchCallInfoNumber(u16 windowId, const u8 *str, int top)
{
    int x = GetStringRightAlignXOffset(FONT_NARROW, str, 86);
    int y = top * 16 + 1;
    AddTextPrinterParameterized(windowId, FONT_NARROW, str, x, y, TEXT_SKIP_DRAW, NULL);
}

static void PrintMatchCallLocation(struct Pokenav_MatchCallGfx *gfx, int delta)
{
    u8 mapName[32];
    int x;
    int index = PokenavList_GetSelectedIndex() + delta;
    int mapSec = GetMatchCallMapSec(index);
    if (mapSec != MAPSEC_NONE)
        GetMapName(mapName, mapSec, 0);
    else
        StringCopy(mapName, gText_Unknown);

    x = GetStringCenterAlignXOffset(FONT_NARROW, mapName, 88);
    FillWindowPixelBuffer(gfx->locWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(gfx->locWindowId, FONT_NARROW, mapName, x, 1, 0, NULL);
}

static void PrintMatchCallSelectionOptions(struct Pokenav_MatchCallGfx *gfx)
{
    u32 i;

    FillWindowPixelBuffer(gfx->infoBoxWindowId, PIXEL_FILL(1));
    for (i = 0; i < MATCH_CALL_OPTION_COUNT; i++)
    {
        int optionText = GetMatchCallOptionId(i);
        if (optionText == MATCH_CALL_OPTION_COUNT)
            break;

        AddTextPrinterParameterized(gfx->infoBoxWindowId, FONT_NARROW, sMatchCallOptionTexts[optionText], 16, i * 16 + 1, TEXT_SKIP_DRAW, NULL);
    }

    CopyWindowToVram(gfx->infoBoxWindowId, COPYWIN_GFX);
}

static bool32 ShowOptionsCursor(struct Pokenav_MatchCallGfx *gfx)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        CreateOptionsCursorSprite(gfx, GetMatchCallOptionCursorPos());
        return FALSE;
    }

    return TRUE;
}

static void UpdateWindowsReturnToTrainerList(struct Pokenav_MatchCallGfx *gfx)
{
    CloseMatchCallSelectOptionsWindow(gfx);
    UpdateMatchCallInfoBox(gfx);
}

static bool32 IsDma3ManagerBusyWithBgCopy1(struct Pokenav_MatchCallGfx *gfx)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void UpdateWindowsToShowCheckPage(struct Pokenav_MatchCallGfx *gfx)
{
    CloseMatchCallSelectOptionsWindow(gfx);
    FillWindowPixelBuffer(gfx->infoBoxWindowId, PIXEL_FILL(1));
    CopyWindowToVram(gfx->infoBoxWindowId, COPYWIN_GFX);
}

static void LoadCallWindowAndFade(struct Pokenav_MatchCallGfx *gfx)
{
    gfx->msgBoxWindowId = AddWindow(&sCallMsgBoxWindowTemplate);
    LoadMatchCallWindowGfx(gfx->msgBoxWindowId, 1, 4);
    FadeToBlackExceptPrimary();
}

static void DrawMsgBoxForMatchCallMsg(struct Pokenav_MatchCallGfx *gfx)
{
    struct Sprite *sprite;
    LoadMatchCallWindowGfx(gfx->msgBoxWindowId, 1, 4);
    DrawMatchCallTextBoxBorder(gfx->msgBoxWindowId, 1, 4);
    FillWindowPixelBuffer(gfx->msgBoxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(gfx->msgBoxWindowId);
    CopyWindowToVram(gfx->msgBoxWindowId, COPYWIN_FULL);
    sprite = GetSpinningPokenavSprite();
    sprite->x = 24;
    sprite->y = 112;
    sprite->y2 = 0;
}

static void DrawMsgBoxForCloseByMsg(struct Pokenav_MatchCallGfx *gfx)
{
    LoadUserWindowBorderGfx(gfx->msgBoxWindowId, 1, BG_PLTT_ID(4));
    DrawTextBorderOuter(gfx->msgBoxWindowId, 1, 4);
    FillWindowPixelBuffer(gfx->msgBoxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(gfx->msgBoxWindowId);
    CopyWindowToVram(gfx->msgBoxWindowId, COPYWIN_FULL);
}

static bool32 IsDma3ManagerBusyWithBgCopy2(struct Pokenav_MatchCallGfx *gfx)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void PrintCallingDots(struct Pokenav_MatchCallGfx *gfx)
{
    AddTextPrinterParameterized(gfx->msgBoxWindowId, FONT_NORMAL, sText_CallingDots, 32, 1, 1, NULL);
}

static bool32 WaitForCallingDotsText(struct Pokenav_MatchCallGfx *gfx)
{
    RunTextPrinters();
    return IsTextPrinterActive(gfx->msgBoxWindowId);
}

static void PrintTrainerIsCloseBy(struct Pokenav_MatchCallGfx *gfx)
{
    AddTextPrinterParameterized(gfx->msgBoxWindowId, FONT_NORMAL, gText_TrainerCloseBy, 0, 1, 1, NULL);
}

static bool32 WaitForTrainerIsCloseByText(struct Pokenav_MatchCallGfx *gfx)
{
    RunTextPrinters();
    return IsTextPrinterActive(gfx->msgBoxWindowId);
}

static void PrintMatchCallMessage(struct Pokenav_MatchCallGfx *gfx)
{
    int index = PokenavList_GetSelectedIndex();
    const u8 *str = GetMatchCallMessageText(index, &gfx->newRematchRequest);
    u8 speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized(gfx->msgBoxWindowId, FONT_NORMAL, str, 32, 1, speed, NULL);
}

static bool32 WaitForMatchCallMessageText(struct Pokenav_MatchCallGfx *gfx)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = TRUE;
    else
        gTextFlags.canABSpeedUpPrint = FALSE;

    RunTextPrinters();
    return IsTextPrinterActive(gfx->msgBoxWindowId);
}

static void EraseCallMessageBox(struct Pokenav_MatchCallGfx *gfx)
{
    HideSpinningPokenavSprite();
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
    CopyBgTilemapBufferToVram(1);
}

static bool32 WaitForCallMessageBoxErase(struct Pokenav_MatchCallGfx *gfx)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void AllocMatchCallSprites(void)
{
    int i;
    u8 paletteNum;
    struct SpriteSheet spriteSheet;
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);

    // Load options cursor gfx
    for (i = 0; i < ARRAY_COUNT(sOptionsCursorSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sOptionsCursorSpriteSheets[i]);
    Pokenav_AllocAndLoadPalettes(sOptionsCursorSpritePalettes);
    gfx->optionsCursorSprite = NULL;

    // Load trainer pic gfx
    spriteSheet.data = gfx->trainerPicGfx;
    spriteSheet.size = sizeof(gfx->trainerPicGfx);
    spriteSheet.tag = GFXTAG_TRAINER_PIC;
    gfx->trainerPicGfxPtr = (u8 *)OBJ_VRAM0 + LoadSpriteSheet(&spriteSheet) * 0x20;
    paletteNum = AllocSpritePalette(PALTAG_TRAINER_PIC);
    gfx->trainerPicPalOffset = OBJ_PLTT_ID(paletteNum);
    gfx->trainerPicSprite = CreateTrainerPicSprite();
    gfx->trainerPicSprite->invisible = TRUE;
}

static void FreeMatchCallSprites(void)
{
    struct Pokenav_MatchCallGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    if (gfx->optionsCursorSprite)
        DestroySprite(gfx->optionsCursorSprite);
    if (gfx->trainerPicSprite)
        DestroySprite(gfx->trainerPicSprite);

    FreeSpriteTilesByTag(GFXTAG_TRAINER_PIC);
    FreeSpriteTilesByTag(GFXTAG_CURSOR);
    FreeSpritePaletteByTag(PALTAG_CURSOR);
    FreeSpritePaletteByTag(PALTAG_TRAINER_PIC);
}

static void CreateOptionsCursorSprite(struct Pokenav_MatchCallGfx *gfx, int top)
{
    if (!gfx->optionsCursorSprite)
    {
        u8 spriteId = CreateSprite(&sOptionsCursorSpriteTemplate, 4, 80, 5);
        gfx->optionsCursorSprite = &gSprites[spriteId];
        UpdateCursorGfxPos(gfx, top);
    }
}

static void CloseMatchCallSelectOptionsWindow(struct Pokenav_MatchCallGfx *gfx)
{
    DestroySprite(gfx->optionsCursorSprite);
    gfx->optionsCursorSprite = NULL;
}

static void UpdateCursorGfxPos(struct Pokenav_MatchCallGfx *gfx, int top)
{
    gfx->optionsCursorSprite->y2 = top * 16;
}

static void SpriteCB_OptionsCursor(struct Sprite *sprite)
{
    if (++sprite->data[0] > 3)
    {
        sprite->data[0] = 0;
        sprite->x2 = (sprite->x2 + 1) & 7;
    }
}

static struct Sprite *CreateTrainerPicSprite(void)
{
    u8 spriteId = CreateSprite(&sTrainerPicSpriteTemplate, 44, 104, 6);
    return &gSprites[spriteId];
}

static void LoadCheckPageTrainerPic(struct Pokenav_MatchCallGfx *gfx)
{
    u16 cursor;
    int trainerPic = GetMatchCallTrainerPic(PokenavList_GetSelectedIndex());
    if (trainerPic >= 0)
    {
        DecompressPicFromTable(&gTrainerFrontPicTable[trainerPic], gfx->trainerPicGfx, SPECIES_NONE);
        LZ77UnCompWram(gTrainerFrontPicPaletteTable[trainerPic].data, gfx->trainerPicPal);
        cursor = RequestDma3Copy(gfx->trainerPicGfx, gfx->trainerPicGfxPtr, sizeof(gfx->trainerPicGfx), 1);
        LoadPalette(gfx->trainerPicPal, gfx->trainerPicPalOffset, sizeof(gfx->trainerPicPal));
        gfx->trainerPicSprite->data[0] = 0;
        gfx->trainerPicSprite->data[7] = cursor;
        gfx->trainerPicSprite->callback = SpriteCB_TrainerPicSlideOnscreen;
    }
}

static void TrainerPicSlideOffscreen(struct Pokenav_MatchCallGfx *gfx)
{
    gfx->trainerPicSprite->callback = SpriteCB_TrainerPicSlideOffscreen;
}

static bool32 WaitForTrainerPic(struct Pokenav_MatchCallGfx *gfx)
{
    return gfx->trainerPicSprite->callback != SpriteCallbackDummy;
}

static void SpriteCB_TrainerPicSlideOnscreen(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (CheckForSpaceForDma3Request(sprite->data[7]) != -1)
        {
            sprite->x2 = -80;
            sprite->invisible = FALSE;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->x2 += 8;
        if (sprite->x2 >= 0)
        {
            sprite->x2 = 0;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void SpriteCB_TrainerPicSlideOffscreen(struct Sprite *sprite)
{
    sprite->x2 -= 8;
    if (sprite->x2 <= -80)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}
