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

struct Pokenav4Struct
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopTaskId;
    u8 filler8[0x6];
    u8 unkE;
    u8 unkF;
    u16 locWindowId;
    u16 infoBoxWindowId;
    u16 msgBoxWindowId;
    s16 unk16;
    u8 unused18;
    u8 unused19;
    u16 unk1A;
    struct Sprite *optionsCursorSprite;
    struct Sprite *trainerPicSprite;
    u8 unk24[0x800];
    u8 unk824[0x800];
    u8 unk1024[0x800];
    u8 *unk1824;
    u8 unk1828[0x800];
    u8 unk2028[0x20];
};

static bool32 GetCurrentLoopedTaskActive(void);
static u32 LoopedTask_OpenMatchCall(s32);
static void InitMatchCallPokenavListMenuTemplate(void);
static void sub_81CBC1C(void);
static void RemoveMatchCallSprites(void);
static void sub_81CC034(struct Pokenav4Struct *);
static void DrawMatchCallLeftColumnWindows(struct Pokenav4Struct *);
static void UpdateMatchCallInfoBox(struct Pokenav4Struct *);
static void PrintMatchCallLocation(struct Pokenav4Struct *, int);
static void sub_81CC214(void);
static void sub_81CBC38(int);
static void PrintMatchCallSelectionOptions(struct Pokenav4Struct *);
static bool32 sub_81CBFC4(struct Pokenav4Struct *);
static void UpdateCursorGfxPos(struct Pokenav4Struct *, int);
static bool32 IsDma3ManagerBusyWithBgCopy1(struct Pokenav4Struct *);
static void UpdateWindowsReturnToTrainerList(struct Pokenav4Struct *);
static void DrawMsgBoxForMatchCallMsg(struct Pokenav4Struct *);
static bool32 IsDma3ManagerBusyWithBgCopy2(struct Pokenav4Struct *);
static void PrintCallingDots(struct Pokenav4Struct *);
static bool32 WaitForCallingDotsText(struct Pokenav4Struct *);
static void PrintMatchCallMessage(struct Pokenav4Struct *);
static bool32 WaitForMatchCallMessageText(struct Pokenav4Struct *);
static void DrawMsgBoxForCloseByMsg(struct Pokenav4Struct *);
static void PrintTrainerIsCloseBy(struct Pokenav4Struct *);
static bool32 WaitForTrainerIsCloseByText(struct Pokenav4Struct *);
static void DrawSpinningPokenavForCall(struct Pokenav4Struct *);
static bool32 WaitForSpinningPokenav(struct Pokenav4Struct *);
static void UpdateWindowsToShowCheckPage(struct Pokenav4Struct *);
static void LoadCheckPageTrainerPic(struct Pokenav4Struct *);
static bool32 WaitForTrainerPic(struct Pokenav4Struct *);
static void TrainerPicSlideOffscreen(struct Pokenav4Struct *);
static void sub_81CBC64(u8 taskId);
static void TryDrawRematchPokeballIcon(u16 windowId, u32, u32);
static void PrintNumberRegisteredLabel(u16 windowId);
static void PrintNumberRegistered(u16 windowId);
static void PrintNumberOfBattlesLabel(u16 windowId);
static void PrintNumberOfBattles(u16 windowId);
static void PrintMatchCallInfoLabel(u16 windowId, const u8 *str, int top);
static void PrintMatchCallInfoNumber(u16 windowId, const u8 *str, int top);
static void sub_81CC2F0(struct Pokenav4Struct *, int);
static void CloseMatchCallSelectOptionsWindow(struct Pokenav4Struct *);
static struct Sprite *CreateTrainerPicSprite(void);
static void SpriteCB_TrainerPicSlideOnscreen(struct Sprite *sprite);
static void SpriteCB_TrainerPicSlideOffscreen(struct Sprite *sprite);
void SpriteCB_OptionsCursor(struct Sprite *sprite);
u32 MatchCallListCursorDown(s32);
u32 MatchCallListCursorUp(s32);
u32 MatchCallListPageDown(s32);
u32 MatchCallListPageUp(s32);
u32 SelectMatchCallEntry(s32);
u32 MoveMatchCallOptionsCursor(s32);
static u32 CancelMatchCallSelection(s32);
u32 DoMatchCallMessage(s32);
u32 DoTrainerCloseByMessage(s32);
u32 sub_81CB888(s32);
u32 ShowCheckPage(s32);
u32 ShowCheckPageUp(s32);
u32 ShowCheckPageDown(s32);
u32 ExitCheckPage(s32);
u32 ExitMatchCall(s32);

static const u16 sMatchCallUI_Pal[] = INCBIN_U16("graphics/pokenav/ui_matchcall.gbapal");
static const u32 sMatchCallUI_Gfx[] = INCBIN_U32("graphics/pokenav/ui_matchcall.4bpp.lz");
static const u32 sMatchCallUI_Tilemap[] = INCBIN_U32("graphics/pokenav/ui_matchcall.bin.lz");
static const u16 gUnknown_08622698[] = INCBIN_U16("graphics/pokenav/arrow2.gbapal");
static const u32 gUnknown_086226B8[] = INCBIN_U32("graphics/pokenav/arrow2.4bpp.lz");
static const u16 gUnknown_086226E0[] = INCBIN_U16("graphics/pokenav/86226E0.gbapal");
static const u16 gUnknown_08622700[] = INCBIN_U16("graphics/pokenav/8622700.gbapal");
static const u16 gUnknown_08622720[] = INCBIN_U16("graphics/pokenav/pokeball_matchcall.gbapal");
static const u32 gUnknown_08622760[] = INCBIN_U32("graphics/pokenav/pokeball_matchcall.4bpp.lz");

const struct BgTemplate sMatchCallBgTemplates[3] = 
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
    [POKENAV_MC_FUNC_10]                  = sub_81CB888,
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
static const u8 sText_CallingDots[] = _("·{PAUSE 0x04}·{PAUSE 0x04}·{PAUSE 0x04}·{PAUSE 0x04}·\p");

static const struct WindowTemplate sCallMsgBoxWindowTemplate = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 12,
    .width = 0x1C,
    .height = 0x04,
    .paletteNum = 1,
    .baseBlock = 10
};

const struct CompressedSpriteSheet gUnknown_08622810[1] = 
{
    {gUnknown_086226B8, 0x40, 7}
};

const struct SpritePalette gUnknown_08622818[2] = 
{
    {gUnknown_08622698, 12}
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
    .tileTag = 7,
    .paletteTag = 12,
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
    .tileTag = 8,
    .paletteTag = 13,
    .oam = &sTrainerPicOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

bool32 OpenMatchCall(void)
{
    struct Pokenav4Struct *state = AllocSubstruct(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN, sizeof(struct Pokenav4Struct));
    if (!state)
        return FALSE;

    state->unused19 = 0;
    state->loopTaskId = CreateLoopedTask(LoopedTask_OpenMatchCall, 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
    return TRUE;
}

void CreateMatchCallLoopedTask(s32 index)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    state->loopTaskId = CreateLoopedTask(sMatchCallLoopTaskFuncs[index], 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsMatchCallLoopedTaskActive(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    return state->isTaskActiveCB();
}

void FreeMatchCallSubstruct2(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    RemoveMatchCallSprites();
    sub_81CBC1C();
    RemoveWindow(state->infoBoxWindowId);
    RemoveWindow(state->locWindowId);
    RemoveWindow(state->msgBoxWindowId);
    FreePokenavSubstruct(6);
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    return IsLoopedTaskActive(state->loopTaskId);
}

static u32 LoopedTask_OpenMatchCall(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        InitBgTemplates(sMatchCallBgTemplates, ARRAY_COUNT(sMatchCallBgTemplates));
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        DecompressAndCopyTileDataToVram(2, sMatchCallUI_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(2, state->unk1024);
        CopyToBgTilemapBuffer(2, sMatchCallUI_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(sMatchCallUI_Pal, 0x20, 0x20);
        CopyBgTilemapBufferToVram(2);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        sub_8199DF0(1, 0, 0, 1);
        SetBgTilemapBuffer(1, state->unk24);
        FillBgTilemapBufferRect_Palette0(1, 0x1000, 0, 0, 32, 20);
        CopyPaletteIntoBufferUnfaded(gUnknown_086226E0, 0x10, 0x20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;

        sub_81CC034(state);
        DecompressAndCopyTileDataToVram(3, gUnknown_08622760, 0, 0, 0);
        CopyPaletteIntoBufferUnfaded(gUnknown_08622700, 0x30, 0x20);
        CopyPaletteIntoBufferUnfaded(gUnknown_08622720, 0x50, 0x20);
        return LT_INC_AND_PAUSE;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() || !sub_81CAE28())
            return LT_PAUSE;

        InitMatchCallPokenavListMenuTemplate();
        return LT_INC_AND_PAUSE;
    case 4:
        if (sub_81C8224())
            return LT_PAUSE;

        DrawMatchCallLeftColumnWindows(state);
        return LT_INC_AND_PAUSE;
    case 5:
        UpdateMatchCallInfoBox(state);
        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 6:
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ShowBg(2);
        ShowBg(3);
        ShowBg(1);
        sub_81CC214();
        LoadLeftHeaderGfxForIndex(3);
        ShowLeftHeaderGfx(POKENAV_GFX_MATCH_CALL_MENU, 1, 0);
        PokenavFadeScreen(1);
        return LT_INC_AND_PAUSE;
    case 7:
        if (IsPaletteFadeActive() || AreLeftHeaderSpritesMoving())
            return LT_PAUSE;

        sub_81CBC38(1);
        return LT_FINISH;
    default:
        return LT_FINISH;
    }
}

u32 MatchCallListCursorDown(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_MoveCursorDown())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

u32 MatchCallListCursorUp(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_MoveCursorUp())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

u32 MatchCallListPageDown(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_PageDown())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

u32 MatchCallListPageUp(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        switch (MatchCall_PageUp())
        {
            case 0:
                break;
            case 1:
                PlaySE(SE_SELECT);
                return 7;
            case 2:
                PlaySE(SE_SELECT);
                // fall through
            default:
                return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (IsMonListLoopedTaskActive())
            return LT_PAUSE;

        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintMatchCallLocation(state, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

u32 SelectMatchCallEntry(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintMatchCallSelectionOptions(state);
        PrintHelpBarText(HELPBAR_MC_CALL_MENU);
        return LT_INC_AND_PAUSE;
    case 1:
        if (sub_81CBFC4(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 MoveMatchCallOptionsCursor(s32 taskState)
{
    struct Pokenav4Struct *state;
    u16 cursorPos;

    PlaySE(SE_SELECT);
    state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    cursorPos = GetMatchCallOptionCursorPos();
    UpdateCursorGfxPos(state, cursorPos);
    return LT_FINISH;
}

u32 CancelMatchCallSelection(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        UpdateWindowsReturnToTrainerList(state);
        PrintHelpBarText(HELPBAR_MC_TRAINER_LIST);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy1(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 DoMatchCallMessage(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        ToggleMatchCallVerticalArrows(TRUE);
        DrawMsgBoxForMatchCallMsg(state);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy2(state))
            return LT_PAUSE;

        PrintCallingDots(state);
        PlaySE(SE_POKENAV_CALL);
        state->unkE = 0;
        return LT_INC_AND_PAUSE;
    case 2:
        if (WaitForCallingDotsText(state))
            return LT_PAUSE;

        PrintMatchCallMessage(state);
        return LT_INC_AND_PAUSE;
    case 3:
        if (WaitForMatchCallMessageText(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 DoTrainerCloseByMessage(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        DrawMsgBoxForCloseByMsg(state);
        ToggleMatchCallVerticalArrows(TRUE);
        state->unkE = 1;
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy2(state))
            return LT_PAUSE;

        PrintTrainerIsCloseBy(state);
        return LT_INC_AND_PAUSE;
    case 2:
        if (WaitForTrainerIsCloseByText(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 sub_81CB888(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    u32 result = LT_INC_AND_PAUSE;

    switch (taskState)
    {
    case 0:
        if (!state->unkE)
            PlaySE(SE_POKENAV_HANG_UP);

        PlaySE(SE_SELECT);
        break;
    case 1:
        DrawSpinningPokenavForCall(state);
        break;
    case 2:
        if (WaitForSpinningPokenav(state))
            result = LT_PAUSE;
        break;
    case 3:
        UpdateWindowsReturnToTrainerList(state);
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy1(state))
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
            if (state->unkF)
            {
                sub_81C8838();
                result = LT_INC_AND_CONTINUE;
            }
            else
            {
                ToggleMatchCallVerticalArrows(FALSE);
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
            ToggleMatchCallVerticalArrows(FALSE);
            result = LT_FINISH;
        }
        break;
    }

    return result;
}

u32 ShowCheckPage(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81C877C();
        UpdateWindowsToShowCheckPage(state);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsMatchCallListTaskActive() || IsDma3ManagerBusyWithBgCopy1(state))
            return LT_PAUSE;

        PrintHelpBarText(HELPBAR_MC_CHECK_PAGE);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintCheckPageInfo(0);
        LoadCheckPageTrainerPic(state);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsMatchCallListTaskActive() || WaitForTrainerPic(state) || WaitForHelpBar())
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 ShowCheckPageDown(s32 taskState)
{
    int topId;
    int delta;
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        topId = GetMatchCallListTopIndex();
        delta = GetIndexDeltaOfNextCheckPageDown(topId);
        if (delta)
        {
            PlaySE(SE_SELECT);
            state->unk16 = delta;
            TrainerPicSlideOffscreen(state);
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (WaitForTrainerPic(state))
            return LT_PAUSE;

        PrintMatchCallLocation(state, state->unk16);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintCheckPageInfo(state->unk16);
        return LT_INC_AND_PAUSE;
    case 3:
        LoadCheckPageTrainerPic(state);
        return LT_INC_AND_PAUSE;
    case 4:
        if (IsMatchCallListTaskActive() || WaitForTrainerPic(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 ExitCheckPage(s32 taskState)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        TrainerPicSlideOffscreen(state);
        sub_81C87F0();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsMatchCallListTaskActive() || WaitForTrainerPic(state))
            return LT_PAUSE;

        PrintHelpBarText(HELPBAR_MC_TRAINER_LIST);
        UpdateMatchCallInfoBox(state);
        return LT_INC_AND_PAUSE;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 ShowCheckPageUp(s32 taskState)
{
    int topId;
    int delta;
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    switch (taskState)
    {
    case 0:
        topId = GetMatchCallListTopIndex();
        delta = GetIndexDeltaOfNextCheckPageUp(topId);
        if (delta)
        {
            PlaySE(SE_SELECT);
            state->unk16 = delta;
            TrainerPicSlideOffscreen(state);
            return LT_INC_AND_PAUSE;
        }
        break;
    case 1:
        if (WaitForTrainerPic(state))
            return LT_PAUSE;

        PrintMatchCallLocation(state, state->unk16);
        return LT_INC_AND_PAUSE;
    case 2:
        PrintCheckPageInfo(state->unk16);
        return LT_INC_AND_PAUSE;
    case 3:
        LoadCheckPageTrainerPic(state);
        return LT_INC_AND_PAUSE;
    case 4:
        if (IsMatchCallListTaskActive() || WaitForTrainerPic(state))
            return LT_PAUSE;
        break;
    }

    return LT_FINISH;
}

u32 ExitMatchCall(s32 taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CBC38(0);
        PokenavFadeScreen(0);
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

static void InitMatchCallPokenavListMenuTemplate(void)
{
    struct PokenavListTemplate template;
    template.list.matchCallEntries = sub_81CAE94();
    template.count = GetNumberRegistered();
    template.unk8 = 4;
    template.unk6 = 0;
    template.item_X = 13;
    template.windowWidth = 16;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 3;
    template.fontId = 7;
    template.listFunc.unk10_2 = BufferMatchCallNameAndDesc;
    template.unk14 = TryDrawRematchPokeballIcon;
    sub_81C81D4(&sMatchCallBgTemplates[2], &template, 2);
    CreateTask(sub_81CBC64, 7);
}

static void sub_81CBC1C(void)
{
    sub_81C8234();
    DestroyTask(FindTaskIdByFunc(sub_81CBC64));
}

static void sub_81CBC38(int arg0)
{
    u8 taskId = FindTaskIdByFunc(sub_81CBC64);
    if (taskId != 0xFF)
        gTasks[taskId].data[15] = arg0;
}

static void sub_81CBC64(u8 taskId)
{
    s16 *taskData = gTasks[taskId].data;
    if (taskData[15])
    {
        taskData[0] += 4;
        taskData[0] &= 0x7F;
        taskData[1] = gSineTable[taskData[0]] >> 4;
        PokenavCopyPalette(gUnknown_08622720, gUnknown_08622720 + 0x10, 0x10, 0x10, taskData[1], gPlttBufferUnfaded + 0x50);
        if (!gPaletteFade.active)
            CpuCopy32(gPlttBufferUnfaded + 0x50, gPlttBufferFaded + 0x50, 0x20);
    }
}

static void TryDrawRematchPokeballIcon(u16 windowId, u32 rematchId, u32 arg2)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u16 *tilemap = GetBgTilemapBuffer(bg);
    tilemap += arg2 * 0x40 + 0x1D;
    if (ShouldDrawRematchPokeballIcon(rematchId))
    {
        tilemap[0] = 0x5000;
        tilemap[0x20] = 0x5001;
    }
    else
    {
        tilemap[0] = 0x5002;
        tilemap[0x20] = 0x5002;
    }
}

void ClearRematchPokeballIcon(u16 windowId, u32 arg0)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u16 *tilemap = GetBgTilemapBuffer(bg);
    tilemap += arg0 * 0x40 + 0x1D;
    tilemap[0] = 0x5002;
    tilemap[0x20] = 0x5002;
}

static void DrawMatchCallLeftColumnWindows(struct Pokenav4Struct *state)
{
    state->locWindowId = AddWindow(&sMatchCallLocationWindowTemplate);
    state->infoBoxWindowId = AddWindow(&sMatchCallInfoBoxWindowTemplate);
    FillWindowPixelBuffer(state->locWindowId, PIXEL_FILL(1));
    PutWindowTilemap(state->locWindowId);
    FillWindowPixelBuffer(state->infoBoxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(state->infoBoxWindowId);
    CopyWindowToVram(state->locWindowId, 1);
}

static void UpdateMatchCallInfoBox(struct Pokenav4Struct *state)
{
    FillWindowPixelBuffer(state->infoBoxWindowId, PIXEL_FILL(1));
    PrintNumberRegisteredLabel(state->infoBoxWindowId);
    PrintNumberRegistered(state->infoBoxWindowId);
    PrintNumberOfBattlesLabel(state->infoBoxWindowId);
    PrintNumberOfBattles(state->infoBoxWindowId);
    CopyWindowToVram(state->infoBoxWindowId, 2);
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
    AddTextPrinterParameterized(windowId, 7, str, 2, y, TEXT_SPEED_FF, NULL);
}

static void PrintMatchCallInfoNumber(u16 windowId, const u8 *str, int top)
{
    int x = GetStringRightAlignXOffset(7, str, 86);
    int y = top * 16 + 1;
    AddTextPrinterParameterized(windowId, 7, str, x, y, TEXT_SPEED_FF, NULL);
}

static void PrintMatchCallLocation(struct Pokenav4Struct *state, int arg1)
{
    u8 mapName[32];
    int x;
    int index = GetSelectedPokenavListIndex() + arg1;
    int mapSec = GetMatchCallMapSec(index);
    if (mapSec != MAPSEC_NONE)
        GetMapName(mapName, mapSec, 0);
    else
        StringCopy(mapName, gText_Unknown);
    
    x = GetStringCenterAlignXOffset(7, mapName, 88);
    FillWindowPixelBuffer(state->locWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(state->locWindowId, 7, mapName, x, 1, 0, NULL);
}

static void PrintMatchCallSelectionOptions(struct Pokenav4Struct *state)
{
    u32 i;

    FillWindowPixelBuffer(state->infoBoxWindowId, PIXEL_FILL(1));
    for (i = 0; i < MATCH_CALL_OPTION_COUNT; i++)
    {
        int optionText = GetMatchCallOptionId(i);
        if (optionText == MATCH_CALL_OPTION_COUNT)
            break;

        AddTextPrinterParameterized(state->infoBoxWindowId, 7, sMatchCallOptionTexts[optionText], 16, i * 16 + 1, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(state->infoBoxWindowId, 2);
}

static bool32 sub_81CBFC4(struct Pokenav4Struct *state)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        sub_81CC2F0(state, GetMatchCallOptionCursorPos());
        return FALSE;
    }

    return TRUE;
}

static void UpdateWindowsReturnToTrainerList(struct Pokenav4Struct *state)
{
    CloseMatchCallSelectOptionsWindow(state);
    UpdateMatchCallInfoBox(state);
}

static bool32 IsDma3ManagerBusyWithBgCopy1(struct Pokenav4Struct *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void UpdateWindowsToShowCheckPage(struct Pokenav4Struct *state)
{
    CloseMatchCallSelectOptionsWindow(state);
    FillWindowPixelBuffer(state->infoBoxWindowId, PIXEL_FILL(1));
    CopyWindowToVram(state->infoBoxWindowId, 2);
}

static void sub_81CC034(struct Pokenav4Struct *state)
{
    state->msgBoxWindowId = AddWindow(&sCallMsgBoxWindowTemplate);
    sub_8197184(state->msgBoxWindowId, 1, 4);
    sub_81C7B40();
}

static void DrawMsgBoxForMatchCallMsg(struct Pokenav4Struct *state)
{
    struct Sprite *sprite;
    sub_8197184(state->msgBoxWindowId, 1, 4);
    sub_81971C4(state->msgBoxWindowId, 1, 4);
    FillWindowPixelBuffer(state->msgBoxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(state->msgBoxWindowId);
    CopyWindowToVram(state->msgBoxWindowId, 3);
    sprite = PauseSpinningPokenavSprite();
    sprite->pos1.x = 24;
    sprite->pos1.y = 112;
    sprite->pos2.y = 0;
}

static void DrawMsgBoxForCloseByMsg(struct Pokenav4Struct *state)
{
    LoadUserWindowBorderGfx(state->msgBoxWindowId, 1, 0x40);
    DrawTextBorderOuter(state->msgBoxWindowId, 1, 4);
    FillWindowPixelBuffer(state->msgBoxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(state->msgBoxWindowId);
    CopyWindowToVram(state->msgBoxWindowId, 3);
}

static bool32 IsDma3ManagerBusyWithBgCopy2(struct Pokenav4Struct *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void PrintCallingDots(struct Pokenav4Struct *state)
{
    AddTextPrinterParameterized(state->msgBoxWindowId, 1, sText_CallingDots, 32, 1, 1, NULL);
}

static bool32 WaitForCallingDotsText(struct Pokenav4Struct *state)
{
    RunTextPrinters();
    return IsTextPrinterActive(state->msgBoxWindowId);
}

static void PrintTrainerIsCloseBy(struct Pokenav4Struct *state)
{
    AddTextPrinterParameterized(state->msgBoxWindowId, 1, gText_TrainerCloseBy, 0, 1, 1, NULL);
}

static bool32 WaitForTrainerIsCloseByText(struct Pokenav4Struct *state)
{
    RunTextPrinters();
    return IsTextPrinterActive(state->msgBoxWindowId);
}

static void PrintMatchCallMessage(struct Pokenav4Struct *state)
{
    int index = GetSelectedPokenavListIndex();
    const u8 *str = GetMatchCallMessageText(index, &state->unkF);
    u8 speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized(state->msgBoxWindowId, 1, str, 32, 1, speed, NULL);
}

static bool32 WaitForMatchCallMessageText(struct Pokenav4Struct *state)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = 1;
    else
        gTextFlags.canABSpeedUpPrint = 0;

    RunTextPrinters();
    return IsTextPrinterActive(state->msgBoxWindowId);
}

static void DrawSpinningPokenavForCall(struct Pokenav4Struct *state)
{
    ResumeSpinningPokenavSprite();
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
    CopyBgTilemapBufferToVram(1);
}

static bool32 WaitForSpinningPokenav(struct Pokenav4Struct *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

static void sub_81CC214(void)
{
    int i;
    u8 paletteNum;
    struct SpriteSheet spriteSheet;
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);

    for (i = 0; i < ARRAY_COUNT(gUnknown_08622810); i++)
        LoadCompressedSpriteSheet(&gUnknown_08622810[i]);

    Pokenav_AllocAndLoadPalettes(gUnknown_08622818);
    state->optionsCursorSprite = NULL;
    spriteSheet.data = state->unk1828;
    spriteSheet.size = 0x800;
    spriteSheet.tag = 8;
    state->unk1824 = (u8 *)OBJ_VRAM0 + LoadSpriteSheet(&spriteSheet) * 0x20;
    paletteNum = AllocSpritePalette(13);
    state->unk1A = 0x100 + paletteNum * 0x10;
    state->trainerPicSprite = CreateTrainerPicSprite();
    state->trainerPicSprite->invisible = TRUE;
}

static void RemoveMatchCallSprites(void)
{
    struct Pokenav4Struct *state = GetSubstructPtr(POKENAV_SUBSTRUCT_MATCH_CALL_OPEN);
    if (state->optionsCursorSprite)
        DestroySprite(state->optionsCursorSprite);
    if (state->trainerPicSprite)
        DestroySprite(state->trainerPicSprite);

    FreeSpriteTilesByTag(8);
    FreeSpriteTilesByTag(7);
    FreeSpritePaletteByTag(12);
    FreeSpritePaletteByTag(13);
}

static void sub_81CC2F0(struct Pokenav4Struct *state, int top)
{
    if (!state->optionsCursorSprite)
    {
        u8 spriteId = CreateSprite(&sOptionsCursorSpriteTemplate, 4, 80, 5);
        state->optionsCursorSprite = &gSprites[spriteId];
        UpdateCursorGfxPos(state, top);
    }
}

static void CloseMatchCallSelectOptionsWindow(struct Pokenav4Struct *state)
{
    DestroySprite(state->optionsCursorSprite);
    state->optionsCursorSprite = NULL;
}

static void UpdateCursorGfxPos(struct Pokenav4Struct *state, int top)
{
    state->optionsCursorSprite->pos2.y = top * 16;
}

void SpriteCB_OptionsCursor(struct Sprite *sprite)
{
    if (++sprite->data[0] > 3)
    {
        sprite->data[0] = 0;
        sprite->pos2.x = (sprite->pos2.x + 1) & 0x7;
    }
}

static struct Sprite *CreateTrainerPicSprite(void)
{
    u8 spriteId = CreateSprite(&sTrainerPicSpriteTemplate, 44, 104, 6);
    return &gSprites[spriteId];
}

static void LoadCheckPageTrainerPic(struct Pokenav4Struct *state)
{
    u16 cursor;
    int trainerPic = GetMatchCallTrainerPic(GetSelectedPokenavListIndex());
    if (trainerPic >= 0)
    {
        DecompressPicFromTable(&gTrainerFrontPicTable[trainerPic], state->unk1828, SPECIES_NONE);
        LZ77UnCompWram(gTrainerFrontPicPaletteTable[trainerPic].data, state->unk2028);
        cursor = RequestDma3Copy(state->unk1828, state->unk1824, 0x800, 1);
        LoadPalette(state->unk2028, state->unk1A, 0x20);
        state->trainerPicSprite->data[0] = 0;
        state->trainerPicSprite->data[7] = cursor;
        state->trainerPicSprite->callback = SpriteCB_TrainerPicSlideOnscreen;
    }
}

static void TrainerPicSlideOffscreen(struct Pokenav4Struct *state)
{
    state->trainerPicSprite->callback = SpriteCB_TrainerPicSlideOffscreen;
}

static bool32 WaitForTrainerPic(struct Pokenav4Struct *state)
{
    return state->trainerPicSprite->callback != SpriteCallbackDummy;
}

static void SpriteCB_TrainerPicSlideOnscreen(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (CheckForSpaceForDma3Request(sprite->data[7]) != -1)
        {
            sprite->pos2.x = -80;
            sprite->invisible = FALSE;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->pos2.x += 8;
        if (sprite->pos2.x >= 0)
        {
            sprite->pos2.x = 0;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void SpriteCB_TrainerPicSlideOffscreen(struct Sprite *sprite)
{
    sprite->pos2.x -= 8;
    if (sprite->pos2.x <= -80)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}
