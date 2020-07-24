#include "global.h"
#include "gpu_regs.h"
#include "bg.h"
#include "malloc.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "battle.h"
#include "battle_anim.h"
#include "contest.h"
#include "contest_link.h"
#include "data.h"
#include "decompress.h"
#include "graphics.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "new_game.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "scanline_effect.h"
#include "util.h"
#include "contest_util.h"
#include "dma3.h"
#include "battle_message.h"
#include "event_scripts.h"
#include "event_data.h"
#include "strings.h"
#include "contest_effect.h"
#include "contest_link.h"
#include "script_pokemon_util_80F87D8.h"
#include "international_string_util.h"
#include "data.h"
#include "constants/rgb.h"
#include "contest_ai.h"

// This file's functions.
static void LoadContestPalettes(void);
static void Task_StartContestWaitFade(u8 taskId);
static void Task_TryStartLinkContest(u8 taskId);
static void Task_CommunicateMonIdxs(u8 taskId);
static void Task_EndCommunicateMonIdxs(u8 taskId);
static void sub_80D7DE8(u8 taskId);
static bool8 SetupContestGraphics(u8 *stateVar);
static void sub_80D80C8(u8 taskId);
static void sub_80D8108(u8 taskId);
static void VBlankCB_Contest(void);
static void CB2_ContestMain(void);
static void Task_DisplayAppealNumberText(u8 taskId);
static void Task_TryShowMoveSelectScreen(u8 taskId);
static void Task_ShowMoveSelectScreen(u8 taskId);
static void Task_HandleMoveSelectInput(u8 taskId);
static void DrawMoveSelectArrow(s8);
static void EraseMoveSelectArrow(s8);
static void Task_SelectedMove(u8 taskId);
static void Task_EndCommunicateMoveSelections(u8 taskId);
static void Task_HideMoveSelectScreen(u8 taskId);
static void Task_HideApplauseMeterForAppealStart(u8 taskId);
static void Task_WaitHideApplauseMeterForAppealStart(u8 taskId);
static void sub_80D8A88(u8 taskId);
static void Task_DoAppeals(u8 taskId);
static void sub_80DA110(u8);
static void sub_80DA134(struct Sprite *);
static void sub_80DA164(struct Sprite *);
static void sub_80DA198(u8);
static void sub_80DA25C(u8);
static void sub_80DA28C(u8);
static void sub_80DA31C(u8);
static void sub_80DA348(u8);
static void sub_80DA38C(u8);
static void sub_80DA3CC(u8);
static void sub_80DA464(u8);
static void sub_80DA49C(u8);
static void sub_80DA4CC(u8);
static void sub_80DA51C(u8);
static void sub_80DA5B4(u8);
static void Task_EndAppeals(u8);
static void Task_WaitForOutOfTimeMsg(u8);
static void Task_CoverAppealPanelForEnd(u8);
static void Task_TryCommunicateFinalStandings(u8);
static void Task_CommunicateFinalStandings(u8);
static void Task_EndCommunicateFinalStandings(u8);
static void Task_ContestReturnToField(u8);
static void FieldCB_ContestReturnToField(void);
static bool8 sub_80DA8A4(void);
static void PrintContestantTrainerName(u8);
static void PrintContestantTrainerNameWithColor(u8 a0, u8 a1);
static void PrintContestantMonName(u8);
static void PrintContestantMonNameWithColor(u8, u8);
static u8 sub_80DB0C4(void);
static u8 sub_80DB120(void);
static u8 CreateContestantSprite(u16, u32, u32, u32);
static void PrintContestMoveDescription(u16);
static u16 SanitizeSpecies(u16);
static void ContestClearGeneralTextWindow(void);
static u16 GetChosenMove(u8);
static void GetAllChosenMoves(void);
static void ContestPrintLinkStandby(void);
static void FillContestantWindowBgs(void);
static void CreateSliderHeartSprites(void);
static void SetBottomSliderHeartsInvisibility(bool8);
static void CreateNextTurnSprites(void);
static void CreateApplauseMeterSprite(void);
static void sub_80DC5E8(void);
static void sub_80DC7EC(void);
static void ContestDebugDoPrint(void);
static void DrawContestantWindows(void);
static void ApplyNextTurnOrder(void);
static void StartMoveApplauseMeterOnscreen(void);
static void TryMoveApplauseMeterOffscreen(void);
static void sub_80DE224(void);
static void sub_80DE350(void);
static void sub_80DE424(u8);
static void AnimateSliderHearts(u8);
static void sub_80DEA20(void);
static void Contest_StartTextPrinter(const u8 *, u32);
static void ContestBG_FillBoxWithIncrementingTile(u8, u16, u8, u8, u8, u8, u8, s16);
static bool32 Contest_RunTextPrinters(void);
static void Contest_SetBgCopyFlags(u32 flagIndex);
static void CalculateFinalScores(void);
static void sub_80DD080(u8);
static void sub_80DE9DC(u8);
static void sub_80DCBE8(u8, u8);
static u8 sub_80DC9EC(u8);
static u16 SanitizeMove(u16);
static void sub_80DE864(u8);
static void SelectContestMoveBankTarget(u16);
static void sub_80DE9B0(u8);
static void sub_80DC674(u8);
static void sub_80DE12C(void);
static void sub_80DD45C(u8, u8);
static void sub_80DD720(u8);
static void sub_80DE008(bool8);
static u8 sub_80DC028(s16, s16, u8);
static bool8 sub_80DB5B8(u8, u8);
static bool8 sub_80DB798(u8);
static void sub_80DB884(void);
static void sub_80DC9B4(u8);
static void sub_80DDED0(s8, s8);
static void ShowAndUpdateApplauseMeter(s8 unused);
static void sub_80DDE0C(void);
static void UpdateApplauseMeter(void);
static void RankContestants(void);
static void SetAttentionLevels(void);
static void UpdateHeartSliders(void);
static bool8 SlidersDoneUpdating(void);
static void ContestBG_FillBoxWithTile(u8, u16, u8, u8, u8, u8, u8);
static void Contest_PrintTextToBg0WindowStd(u32, const u8 *);
static s16 GetContestantRound2Points(u8);
static void DetermineFinalStandings(void);
static bool8 sub_80DBF30(s32, s32, struct UnknownContestStruct6 *);
static void sub_80DC0F4(u8);
static void SpriteCB_UpdateHeartSlider(struct Sprite *);
static void sub_80DC728(u8);
static void sub_80DC6A4(u8);
static void sub_80DC8D0(u8);
static void sub_80DC81C(u8);
static void sub_80DC87C(u8);
static void sub_80DCC84(struct Sprite *);
static void sub_80DCCD8(struct Sprite *sprite);
static u8 StartApplauseOverflowAnimation(void);
static void Task_ApplauseOverflowAnimation(u8);
static void Task_MoveApplauseMeterOnscreen(u8);
static void Task_MoveApplauseMeterOffscreen(u8);
static void Task_ShowAndUpdateApplauseMeter(u8);
static void sub_80DDE30(u8);
static void sub_80DDF80(u8);
static const u8 *GetTurnOrderNumberGfx(u8);
static void sub_80DE464(u8);
static void sub_80DE4A8(u8);
static void sub_80DE5F4(u8);
static void sub_80DE65C(u8);
static void Task_WaitForSliderHeartAnim(u8);
static void sub_80DEA5C(void);
static void sub_80DF250(void);
static void sub_80DF4F8(void);
static void sub_80DF080(u8);
static void ContestDebugPrintBitStrings(void);
static void StripPlayerNameForLinkContest(u8 *);
static void StripMonNameForLinkContest(u8 *, s32);
static void SwapMoveDescAndContestTilemaps(void);

// An index into a palette where the text color for each contestant is stored.
// Contestant 0 will use palette color 10, contestant 1 will use color 11, etc.
#define CONTESTANT_TEXT_COLOR_START 10

enum
{
// The "{Pokemon Name} / {Trainer Name}" windows.
    CONTEST_WINDOW_CONTESTANT0_NAME,
    CONTEST_WINDOW_CONTESTANT1_NAME,
    CONTEST_WINDOW_CONTESTANT2_NAME,
    CONTEST_WINDOW_CONTESTANT3_NAME,
    CONTEST_WINDOW_GENERAL_TEXT,
    // The available moves, from top to bottom
    CONTEST_WINDOW_MOVE0,
    CONTEST_WINDOW_MOVE1,
    CONTEST_WINDOW_MOVE2,
    CONTEST_WINDOW_MOVE3,
    // The small "/" character between the move category and the
    // appeal/jam display
    CONTEST_WINDOW_SLASH,
    CONTEST_WINDOW_MOVE_DESCRIPTION
};

#define MOVE_WINDOWS_START CONTEST_WINDOW_MOVE0

#define TAG_CONTEST_SYMBOLS_PAL 0xABE0

#define TAG_JUDGE_SYMBOLS_GFX 0xABE0
#define TAG_FACES_GFX 0xABE1
#define TAG_APPLAUSE_METER 0xABE2

#define TAG_SLIDER_HEART 0x4E20

#define TAG_NEXT_TURN_PAL   0x4E22
#define TAG_NEXT_TURN_1_GFX 0x4E22
#define TAG_NEXT_TURN_2_GFX 0x4E23
#define TAG_NEXT_TURN_3_GFX 0x4E24
#define TAG_NEXT_TURN_4_GFX 0x4E25

enum {
    SLIDER_HEART_ANIM_NORMAL,
    SLIDER_HEART_ANIM_DISAPPEAR,
    SLIDER_HEART_ANIM_APPEAR,
};

// EWRAM vars.
EWRAM_DATA struct ContestPokemon gContestMons[CONTESTANT_COUNT] = {0};
EWRAM_DATA s16 gContestMonRound1Points[CONTESTANT_COUNT] = {0}; // "Round 1" points are based on condition
EWRAM_DATA s16 gContestMonTotalPoints[CONTESTANT_COUNT] = {0}; // Round 1 points + Round 2 points
EWRAM_DATA s16 gContestMonAppealPointTotals[CONTESTANT_COUNT] = {0};
EWRAM_DATA s16 gContestMonRound2Points[CONTESTANT_COUNT] = {0}; // "Round 2" points are just appeal points * 2
EWRAM_DATA u8 gContestFinalStandings[CONTESTANT_COUNT] = {0};
EWRAM_DATA u8 gContestMonPartyIndex = 0;
EWRAM_DATA u8 gContestPlayerMonIndex = 0;
EWRAM_DATA u8 gContestantTurnOrder[CONTESTANT_COUNT] = {0};
EWRAM_DATA u8 gLinkContestFlags = 0;
// Bit 0: Is a link contest
// Bit 1: Link contest uses wireless adapter
EWRAM_DATA u8 gUnknown_02039F2B = 0;
EWRAM_DATA u16 gSpecialVar_ContestCategory = 0;
EWRAM_DATA u16 gSpecialVar_ContestRank = 0;
EWRAM_DATA u8 gNumLinkContestPlayers = 0;
EWRAM_DATA u8 gHighestRibbonRank = 0;
EWRAM_DATA struct ContestResources *gContestResources = NULL;
EWRAM_DATA u8 sContestBgCopyFlags = 0;
EWRAM_DATA struct ContestWinner gCurContestWinner = {0};
EWRAM_DATA bool8 gUnknown_02039F5C = 0;
EWRAM_DATA u8 gUnknown_02039F5D = 0;

// IWRAM common vars.
u32 gContestRngValue;

extern const u8 gText_LinkStandby4[];
extern const u8 gText_BDot[];
extern const u8 gText_CDot[];
extern void (*const gContestEffectFuncs[])(void);

static const u8 sSliderHeartYPositions[CONTESTANT_COUNT] =
{
    36, 76, 116, 156
};

// The "Next Turn" sprites cover up the slider, so the y positions are the same as above
static const u8 sNextTurnSpriteYPositions[CONTESTANT_COUNT] =
{
    36, 76, 116, 156
};

static const struct SpriteSheet sSpriteSheet_SliderHeart =
{
    .data = gContestSliderHeart_Gfx,
    .size = 0x20,
    .tag = TAG_SLIDER_HEART
};

static const struct OamData sOam_SliderHeart =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sAffineAnim_SliderHeart_Normal[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_SliderHeart_SpinDisappear[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-10, -10, -20, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_SliderHeart_SpinAppear[] =
{
    AFFINEANIMCMD_FRAME(56, 56, 0, 0),
    AFFINEANIMCMD_FRAME(10, 10, 20, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd* const sAffineAnims_SliderHeart[] =
{
    [SLIDER_HEART_ANIM_NORMAL]    = sAffineAnim_SliderHeart_Normal,
    [SLIDER_HEART_ANIM_DISAPPEAR] = sAffineAnim_SliderHeart_SpinDisappear,
    [SLIDER_HEART_ANIM_APPEAR]    = sAffineAnim_SliderHeart_SpinAppear
};

static const struct SpriteTemplate sSpriteTemplate_SliderHeart =
{
    .tileTag = TAG_SLIDER_HEART,
    .paletteTag = TAG_CONTEST_SYMBOLS_PAL,
    .oam = &sOam_SliderHeart,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_SliderHeart,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_NextTurn[CONTESTANT_COUNT] =
{
    {
        .data = gContestNextTurnGfx,
        .size = 0x100,
        .tag = TAG_NEXT_TURN_1_GFX
    },
    {
        .data = gContestNextTurnGfx,
        .size = 0x100,
        .tag = TAG_NEXT_TURN_2_GFX
    },
    {
        .data = gContestNextTurnGfx,
        .size = 0x100,
        .tag = TAG_NEXT_TURN_3_GFX
    },
    {
        .data = gContestNextTurnGfx,
        .size = 0x100,
        .tag = TAG_NEXT_TURN_4_GFX
    }
};

static const struct SpritePalette sSpritePalette_NextTurn =
{
    .data = gContestPal,
    .tag = TAG_NEXT_TURN_PAL
};

static const struct OamData sOam_NextTurn =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct SpriteTemplate sSpriteTemplates_NextTurn[CONTESTANT_COUNT] =
{
    {
        .tileTag = TAG_NEXT_TURN_1_GFX,
        .paletteTag = TAG_NEXT_TURN_PAL,
        .oam = &sOam_NextTurn,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_NEXT_TURN_2_GFX,
        .paletteTag = TAG_NEXT_TURN_PAL,
        .oam = &sOam_NextTurn,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_NEXT_TURN_3_GFX,
        .paletteTag = TAG_NEXT_TURN_PAL,
        .oam = &sOam_NextTurn,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_NEXT_TURN_4_GFX,
        .paletteTag = TAG_NEXT_TURN_PAL,
        .oam = &sOam_NextTurn,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    }
};

static const struct Subsprite sSubsprites_NextTurn[] =
{
    {
        .x = -28,
        .y = -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 0
    },
    {
        .x = 4,
        .y = -4,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 0
    }
};

static const struct SubspriteTable sSubspriteTable_NextTurn[] =
{
    {
        .subspriteCount = ARRAY_COUNT(sSubsprites_NextTurn),
        .subsprites = sSubsprites_NextTurn
    }
};

// Unused
static const struct CompressedSpriteSheet sSpriteSheet_Faces =
{
    .data = gContestFaces_Gfx,
    .size = 0x180,
    .tag = TAG_FACES_GFX
};

static const struct OamData sOam_Faces =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

// Unused
static const struct SpriteTemplate sSpriteTemplate_Faces =
{
    .tileTag = TAG_FACES_GFX,
    .paletteTag = TAG_CONTEST_SYMBOLS_PAL,
    .oam = &sOam_Faces,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sApplauseMeterSpriteSheet =
{
    .data = gContestApplauseGfx,
    .size = 0x400,
    .tag = TAG_APPLAUSE_METER
};

static const struct SpritePalette sApplauseMeterPalette =
{
    .data = gContestPal,
    .tag = TAG_APPLAUSE_METER
};

static const struct OamData sApplauseMeterOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteTemplate sApplauseMeterSpriteTemplate =
{
    .tileTag = TAG_APPLAUSE_METER,
    .paletteTag = TAG_APPLAUSE_METER,
    .oam = &sApplauseMeterOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct OamData gOamData_8587BE0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 2,
};

const struct SpriteTemplate gSpriteTemplate_8587BE8 =
{
    .tileTag = 0x4E21,
    .paletteTag = 0x4E21,
    .oam = &gOamData_8587BE0,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct CompressedSpriteSheet gUnknown_08587C00 =
{
    .data = gContestJudgeGfx,
    .size = 0x800,
    .tag = 0x4E21
};

static const struct CompressedSpriteSheet sSpriteSheet_JudgeSymbols =
{
    .data = gContestJudgeSymbolsGfx,
    .size = 0x380,
    .tag = TAG_JUDGE_SYMBOLS_GFX
};

const struct CompressedSpritePalette gUnknown_08587C10 =
{
    .data = gContest3Pal,
    .tag = TAG_CONTEST_SYMBOLS_PAL
};

const struct SpriteTemplate gSpriteTemplate_8587C18 =
{
    .tileTag = TAG_JUDGE_SYMBOLS_GFX,
    .paletteTag = TAG_CONTEST_SYMBOLS_PAL,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const u16 gUnknown_08587C30[] = INCBIN_U16("graphics/unknown/unknown_587C30.gbapal");

#include "data/contest_text_tables.h"

static const struct BgTemplate sContestBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x18,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1E,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x1C,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x1A,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sContestWindowTemplates[] =
{
    [CONTEST_WINDOW_CONTESTANT0_NAME] = {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 12,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x200
    },
    [CONTEST_WINDOW_CONTESTANT1_NAME] = {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 5,
        .width = 12,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x218
    },
    [CONTEST_WINDOW_CONTESTANT2_NAME] = {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 10,
        .width = 12,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x230
    },
    [CONTEST_WINDOW_CONTESTANT3_NAME] = {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 15,
        .width = 12,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x248
    },
    [CONTEST_WINDOW_GENERAL_TEXT] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 17,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x260
    },
    [CONTEST_WINDOW_MOVE0] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 31,
        .width = 9,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x2A4
    },
    [CONTEST_WINDOW_MOVE1] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 33,
        .width = 9,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x2B6
    },
    [CONTEST_WINDOW_MOVE2] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 35,
        .width = 9,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x2C8
    },
    [CONTEST_WINDOW_MOVE3] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 37,
        .width = 9,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x2DA
    },
    [CONTEST_WINDOW_SLASH] = {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 31,
        .width = 1,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x2EC
    },
    [CONTEST_WINDOW_MOVE_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 35,
        .width = 18,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x2EE
    },
    DUMMY_WIN_TEMPLATE
};

#include "data/contest_opponents.h"

static const struct CompressedSpriteSheet sUnknown_08589904[] =
{
    {
        .data = gBlankGfxCompressed,
        .size = 0x1000,
        .tag = 0x80E8
    },
    {
        .data = gBlankGfxCompressed,
        .size = 0x1000,
        .tag = 0x80E9
    },
    {
        .data = gBlankGfxCompressed,
        .size = 0x1000,
        .tag = 0x80EA
    },
    {
        .data = gBlankGfxCompressed,
        .size = 0x1000,
        .tag = 0x80EB
    }
};

// Yup this is super dangerous but that's how it is here
static const struct SpritePalette sUnknown_08589924[] =
{
    {
        .data = (u16*)(gHeap + 0x1A0A4),
        .tag = 0x80E8
    },
    {
        .data = (u16*)(gHeap + 0x1A0C4),
        .tag = 0x80E9
    },
    {
        .data = (u16*)(gHeap + 0x1A0E4),
        .tag = 0x80EA
    },
    {
        .data = (u16*)(gHeap + 0x1A104),
        .tag = 0x80EB
    }
};

const struct OamData gOamData_8589944 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

const union AffineAnimCmd gSpriteAffineAnim_858994C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd gSpriteAffineAnim_858995C[] =
{
    AFFINEANIMCMD_FRAME(3, 3, 0, 15),
    AFFINEANIMCMD_FRAME(-3, -3, 0, 15),
    AFFINEANIMCMD_FRAME(3, 3, 0, 15),
    AFFINEANIMCMD_FRAME(-3, -3, 0, 15),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd *const gSpriteAffineAnimTable_8589984[] =
{
    gSpriteAffineAnim_858994C,
    gSpriteAffineAnim_858995C
};

const struct SpriteTemplate gSpriteTemplate_858998C[] =
{
    {
        .tileTag = 0x80E8,
        .paletteTag = 0x80E8,
        .oam = &gOamData_8589944,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gSpriteAffineAnimTable_8589984,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = 0x80E9,
        .paletteTag = 0x80E9,
        .oam = &gOamData_8589944,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gSpriteAffineAnimTable_8589984,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = 0x80EA,
        .paletteTag = 0x80EA,
        .oam = &gOamData_8589944,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gSpriteAffineAnimTable_8589984,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = 0x80EB,
        .paletteTag = 0x80EB,
        .oam = &gOamData_8589944,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gSpriteAffineAnimTable_8589984,
        .callback = SpriteCallbackDummy
    }
};

const s8 gContestExcitementTable[][5] =
{
    { 1,  0, -1, -1,  0},
    { 0,  1,  0, -1, -1},
    {-1,  0,  1,  0, -1},
    {-1, -1,  0,  1,  0},
    { 0, -1, -1,  0,  1}
};

static void TaskDummy1(u8 taskId)
{
}

void ResetLinkContestBoolean(void)
{
    gLinkContestFlags = 0;
}

static void SetupContestGpuRegs(void)
{
    u16 savedIme;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG0 | WINOUT_WINOBJ_BG1 | WINOUT_WINOBJ_BG2 | WINOUT_WINOBJ_BG3 | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
}

void LoadContestBgAfterMoveAnim(void)
{
    s32 i;

    LZDecompressVram(gContestMiscGfx, (void *)VRAM);
    LZDecompressVram(gContestAudienceGfx, (void *)(BG_SCREEN_ADDR(4)));
    CopyToBgTilemapBuffer(3, gOldContestGfx, 0, 0);
    CopyBgTilemapBufferToVram(3);
    LoadCompressedPalette(gOldContestPalette, 0, 0x200);
    LoadContestPalettes();
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        u32 contestantWindowId = MOVE_WINDOWS_START + i;

        LoadPalette(eUnknownHeap1A004.cachedWindowPalettes[contestantWindowId], 16 * (MOVE_WINDOWS_START + gContestantTurnOrder[i]), sizeof((eUnknownHeap1A004.cachedWindowPalettes[contestantWindowId])));
    }
}

static void InitContestInfoBgs(void)
{
    s32 i;

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sContestBgTemplates, ARRAY_COUNT(sContestBgTemplates));
    SetBgAttribute(3, BG_ATTR_WRAPAROUND, 1);
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        SetBgTilemapBuffer(i, gContestResources->contestBgTilemaps[i]);
    }
}

static void InitContestWindows(void)
{
    InitWindows(sContestWindowTemplates);
    DeactivateAllTextPrinters();
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        gTextFlags.canABSpeedUpPrint = FALSE;
    }
    else
    {
        gTextFlags.canABSpeedUpPrint = TRUE;
    }
}

static void LoadContestPalettes(void)
{
    s32 i;

    LoadPalette(gUnknown_08587C30, 0xf0, 0x20);
    FillPalette(RGB_BLACK, 0, 2);
    for (i = 10; i < 14; i++)
        LoadPalette(gPlttBufferUnfaded + 241, 240 + i, 2);
    FillPalette(RGB(31, 17, 31), 0xF3, 2);
}

static void InitContestResources(void)
{
    s32 i;

    eContest = (struct Contest){};
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContest.unused2[i] = 0xFF;
    }
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i] = (struct ContestantStatus){};
    }
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i].ranking = 0;
        eContestantStatus[i].effectStringId = CONTEST_STRING_NONE;
        eContestantStatus[i].effectStringId2 = CONTEST_STRING_NONE;
    }
    eContestResources8 = (struct UnknownContestStruct7){};
    eContestAI = (struct ContestAIInfo){};
    *gContestResources->field_10 = (struct UnknownContestStruct5){};
    memset(gContestResources->field_14, 0, CONTESTANT_COUNT * sizeof(struct UnknownContestStruct4));
    
    if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
        SortContestants(FALSE);
    
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i].nextTurnOrder = 0xFF;
        eContest.prevTurnOrder[i] = gContestantTurnOrder[i];
    }
    // Calling this here while all the nextTurnOrder values are 0xFF will actually
    // just reverse the turn order.
    ApplyNextTurnOrder();
    memset(gContestResources->field_1c, 0, sizeof(*gContestResources->field_1c) * CONTESTANT_COUNT);
}

static void AllocContestResources(void)
{
    gContestResources = AllocZeroed(sizeof(struct ContestResources));
    gContestResources->contest = AllocZeroed(sizeof(struct Contest));
    gContestResources->status = AllocZeroed(sizeof(struct ContestantStatus) * CONTESTANT_COUNT);
    gContestResources->field_8 = AllocZeroed(sizeof(struct UnknownContestStruct7));
    gContestResources->aiData = AllocZeroed(sizeof(struct ContestAIInfo));
    gContestResources->field_10 = AllocZeroed(sizeof(struct UnknownContestStruct5) * CONTESTANT_COUNT);
    gContestResources->field_14 = AllocZeroed(sizeof(struct UnknownContestStruct4) * CONTESTANT_COUNT);
    gContestResources->field_18 = AllocZeroed(sizeof(struct ContestStruct_field_18));
    gContestResources->field_1c = AllocZeroed(sizeof(struct ContestResourcesField1C) * CONTESTANT_COUNT);
    gContestResources->field_20 = AllocZeroed(sizeof(struct ContestResourcesField20));
    gContestResources->contestBgTilemaps[0] = AllocZeroed(0x1000);
    gContestResources->contestBgTilemaps[1] = AllocZeroed(0x1000);
    gContestResources->contestBgTilemaps[2] = AllocZeroed(0x1000);
    gContestResources->contestBgTilemaps[3] = AllocZeroed(0x1000);
    gContestResources->field_34 = AllocZeroed(0x800);
    gContestResources->field_38 = AllocZeroed(0x800);
    gContestResources->field_3c = AllocZeroed(0x2000);
    gUnknown_0202305C = gContestResources->field_3c;
    gUnknown_02023060 = gContestResources->contestBgTilemaps[1];
}

static void FreeContestResources(void)
{
    FREE_AND_SET_NULL(gContestResources->contest);
    FREE_AND_SET_NULL(gContestResources->status);
    FREE_AND_SET_NULL(gContestResources->field_8);
    FREE_AND_SET_NULL(gContestResources->aiData);
    FREE_AND_SET_NULL(gContestResources->field_10);
    FREE_AND_SET_NULL(gContestResources->field_14);
    FREE_AND_SET_NULL(gContestResources->field_18);
    FREE_AND_SET_NULL(gContestResources->field_1c);
    FREE_AND_SET_NULL(gContestResources->field_20);
    FREE_AND_SET_NULL(gContestResources->contestBgTilemaps[0]);
    FREE_AND_SET_NULL(gContestResources->contestBgTilemaps[1]);
    FREE_AND_SET_NULL(gContestResources->contestBgTilemaps[2]);
    FREE_AND_SET_NULL(gContestResources->contestBgTilemaps[3]);
    FREE_AND_SET_NULL(gContestResources->field_34);
    FREE_AND_SET_NULL(gContestResources->field_38);
    FREE_AND_SET_NULL(gContestResources->field_3c);
    FREE_AND_SET_NULL(gContestResources);
    gUnknown_0202305C = NULL;
    gUnknown_02023060 = NULL;
}

void CB2_StartContest(void)
{
    switch (gMain.state)
    {
    case 0:
        sContestBgCopyFlags = 0;
        AllocContestResources();
        AllocateMonSpritesGfx();
        FREE_AND_SET_NULL(gMonSpritesGfxPtr->firstDecompressed);
        gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(0x4000);
        SetVBlankCallback(NULL);
        InitContestInfoBgs();
        InitContestWindows();
        SetupContestGpuRegs();
        ScanlineEffect_Clear();
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        eContestDebugMode = CONTEST_DEBUG_MODE_OFF;
        ClearBattleMonForms();
        InitContestResources();
        gMain.state++;
        break;
    case 1:
        gMain.state++;
        break;
    case 2:
        if (SetupContestGraphics(&eContest.contestSetupState))
        {
            eContest.contestSetupState = 0;
            gMain.state++;
        }
        break;
    case 3:
        sub_80DE224();
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        BeginFastPaletteFade(2);
        gPaletteFade.bufferTransferDisabled = FALSE;
        SetVBlankCallback(VBlankCB_Contest);
        eContest.mainTaskId = CreateTask(Task_StartContestWaitFade, 10);
        SetMainCallback2(CB2_ContestMain);
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(8, 8);
        }
        break;
    }
}

static void Task_StartContestWaitFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = Task_TryStartLinkContest;
    }
}

static void Task_TryStartLinkContest(u8 taskId)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        {
            switch (gTasks[taskId].data[0])
            {
            case 0:
                ContestPrintLinkStandby();
                gTasks[taskId].data[0]++;
                // fallthrough
            case 1:
                if (IsLinkTaskFinished())
                {
                    sub_800ADF8();
                    gTasks[taskId].data[0]++;
                }
                return;
            case 2:
                if (IsLinkTaskFinished() != TRUE)
                    return;
                gTasks[taskId].data[0]++;
                break;
            }
        }

        if (!gPaletteFade.active)
        {
            gPaletteFade.bufferTransferDisabled = FALSE;
            if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS))
                ContestPrintLinkStandby();
            CreateTask(Task_CommunicateMonIdxs, 0);
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = TaskDummy1;
        }
    }
    else
    {
        gTasks[taskId].func = sub_80D80C8;
    }
}

static void Task_CommunicateMonIdxs(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateMonIdxs, Task_EndCommunicateMonIdxs);
}

static void Task_EndCommunicateMonIdxs(u8 taskId)
{
    gTasks[taskId].data[0] = 1;
    gTasks[taskId].func = sub_80D7DE8;
}

static void sub_80D7DE8(u8 taskId)
{
    // data[0] always 1 here
    gTasks[taskId].data[0]--;
    if (gTasks[taskId].data[0] <= 0)
    {
        GetMultiplayerId();  // unused return value
        DestroyTask(taskId);
        gTasks[eContest.mainTaskId].func = sub_80D80C8;
        gRngValue = gContestRngValue;
    }
}

static bool8 SetupContestGraphics(u8 *stateVar)
{
    u16 tempPalette1[16];
    u16 tempPalette2[16];

    switch (*stateVar)
    {
    case 0:
        gPaletteFade.bufferTransferDisabled = TRUE;
        RequestDma3Fill(0, (void *)VRAM, 0x8000, 1);
        RequestDma3Fill(0, (void *)VRAM + 0x8000, 0x8000, 1);
        RequestDma3Fill(0, (void *)VRAM + 0x10000, 0x8000, 1);
        break;
    case 1:
        LZDecompressVram(gContestMiscGfx, (void *)VRAM);
        break;
    case 2:
        LZDecompressVram(gContestAudienceGfx, (void *)(BG_SCREEN_ADDR(4)));
        DmaCopyLarge32(3, (void *)(BG_SCREEN_ADDR(4)), eUnzippedContestAudienceGfx, 0x2000, 0x1000);
        break;
    case 3:
        CopyToBgTilemapBuffer(3, gOldContestGfx, 0, 0);
        CopyBgTilemapBufferToVram(3);
        break;
    case 4:
        CopyToBgTilemapBuffer(2, gUnknown_08C17170, 0, 0);
        CopyBgTilemapBufferToVram(2);
        // This is a bug, and copies random junk. savedJunk is never read.
        DmaCopy32Defvars(3, gContestResources->contestBgTilemaps[2], eUnknownHeap1A004.savedJunk, sizeof(eUnknownHeap1A004.savedJunk));
        break;
    case 5:
        LoadCompressedPalette(gOldContestPalette, 0, 0x200);
        CpuCopy32(gPlttBufferUnfaded + 128, tempPalette1, 16 * sizeof(u16));
        CpuCopy32(gPlttBufferUnfaded + (MOVE_WINDOWS_START + gContestPlayerMonIndex) * 16, tempPalette2, 16 * sizeof(u16));
        CpuCopy32(tempPalette2, gPlttBufferUnfaded + 128, 16 * sizeof(u16));
        CpuCopy32(tempPalette1, gPlttBufferUnfaded + (MOVE_WINDOWS_START + gContestPlayerMonIndex) * 16, 16 * sizeof(u16));
        DmaCopy32Defvars(3, gPlttBufferUnfaded, eUnknownHeap1A004.cachedWindowPalettes, sizeof(eUnknownHeap1A004.cachedWindowPalettes));
        LoadContestPalettes();
        break;
    case 6:
        DrawContestantWindows();
        FillContestantWindowBgs();
        SwapMoveDescAndContestTilemaps();
        eContest.unk19216 = sub_80DB120();
        CreateSliderHeartSprites();
        CreateNextTurnSprites();
        CreateApplauseMeterSprite();
        sub_80DC5E8();
        sub_80DC7EC();
        gBattlerPositions[0] = B_POSITION_PLAYER_LEFT;
        gBattlerPositions[1] = B_POSITION_OPPONENT_LEFT;
        gBattlerPositions[2] = B_POSITION_OPPONENT_RIGHT;
        gBattlerPositions[3] = B_POSITION_PLAYER_RIGHT;
        gBattleTypeFlags = 0;
        gBattlerAttacker = 2;
        gBattlerTarget = 3;
        gBattlerSpriteIds[gBattlerAttacker] = sub_80DB0C4();
        sub_80DEA20();
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        ShowBg(3);
        ShowBg(2);
        ShowBg(0);
        ShowBg(1);
        break;
    default:
        *stateVar = 0;
        return TRUE;
    }

    (*stateVar)++;
    return FALSE;
}

static void sub_80D80C8(u8 taskId)
{
    gPaletteFade.bufferTransferDisabled = FALSE;
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = sub_80D8108;
    }
}

static void sub_80D8108(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gTasks[taskId].data[1]++ <= 60)
            break;
        gTasks[taskId].data[1] = 0;
        PlaySE12WithPanning(SE_C_MAKU_U, 0);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        *(s16*)&gBattle_BG1_Y += 7;
        if ((s16)gBattle_BG1_Y <= 160)
            break;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        sub_80DE350();
        gTasks[taskId].data[0]++;
        break;
    case 3:
    {
        u16 bg0Cnt = GetGpuReg(REG_OFFSET_BG0CNT);
        u16 bg2Cnt = GetGpuReg(REG_OFFSET_BG2CNT);
        ((struct BgCnt *)&bg0Cnt)->priority = 0;
        ((struct BgCnt *)&bg2Cnt)->priority = 0;
        SetGpuReg(REG_OFFSET_BG0CNT, bg0Cnt);
        SetGpuReg(REG_OFFSET_BG2CNT, bg2Cnt);
        StartMoveApplauseMeterOnscreen();
        gTasks[taskId].data[0]++;
        break;
    }
    case 4:
    default:
        if (eContest.applauseMeterIsMoving)
            break;
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = Task_DisplayAppealNumberText;
        break;
    }
}

static void CB2_ContestMain(void)
{
    s32 i;

    AnimateSprites();
    RunTasks();
    BuildOamBuffer();
    UpdatePaletteFade();

    for (i = 0; i < 4; i++)
    {
        if ((sContestBgCopyFlags >> i) & 1)
            CopyBgTilemapBufferToVram(i);
    }
    sContestBgCopyFlags = 0;
}

static void VBlankCB_Contest(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void Task_DisplayAppealNumberText(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gBattle_BG0_Y = 0;
        gBattle_BG2_Y = 0;
        ContestDebugDoPrint();
        DmaCopy32Defvars(3, gPlttBufferUnfaded, eUnknownHeap1A004.unk18204, PLTT_BUFFER_SIZE * 2);
        ConvertIntToDecimalStringN(gStringVar1, eContest.appealNumber + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
        if (!Contest_IsMonsTurnDisabled(gContestPlayerMonIndex))
            StringCopy(gDisplayedStringBattle, gText_AppealNumWhichMoveWillBePlayed);
        else
            StringCopy(gDisplayedStringBattle, gText_AppealNumButItCantParticipate);
        ContestClearGeneralTextWindow();
        StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
        Contest_StartTextPrinter(gStringVar4, TRUE);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!Contest_RunTextPrinters())
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = Task_TryShowMoveSelectScreen;
        }
    }
}

static void Task_TryShowMoveSelectScreen(u8 taskId)
{
    // Wait for button press to show move select screen
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys == B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (!Contest_IsMonsTurnDisabled(gContestPlayerMonIndex))
        {
            SetBottomSliderHeartsInvisibility(TRUE);
            gTasks[taskId].func = Task_ShowMoveSelectScreen;
        }
        else
        {
            // Skip move selection (selected move will be MOVE_NONE)
            gTasks[taskId].func = Task_SelectedMove;
        }
    }
}

static void Task_ShowMoveSelectScreen(u8 taskId)
{
    u8 i;
    u8 moveName[32];

    gBattle_BG0_Y = 160;
    gBattle_BG2_Y = 160;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 move = gContestMons[gContestPlayerMonIndex].moves[i];
        u8 *moveNameBuffer = moveName;

        if (eContestantStatus[gContestPlayerMonIndex].prevMove != MOVE_NONE
            && sub_80DE1E8(gContestPlayerMonIndex)
            && AreMovesContestCombo(eContestantStatus[gContestPlayerMonIndex].prevMove, move) != 0
            && eContestantStatus[gContestPlayerMonIndex].hasJudgesAttention)
        {
            moveNameBuffer = StringCopy(moveName, gText_ColorLightShadowDarkGrey);
        }
        else if (move != MOVE_NONE
                 && eContestantStatus[gContestPlayerMonIndex].prevMove == move
                 && gContestMoves[move].effect != CONTEST_EFFECT_REPETITION_NOT_BORING)
        {
            // Gray the text because it is a repeated move
            moveNameBuffer = StringCopy(moveName, gText_ColorBlue);
        }
        moveNameBuffer = StringCopy(moveNameBuffer, gMoveNames[move]);

        FillWindowPixelBuffer(i + MOVE_WINDOWS_START, PIXEL_FILL(0));
        Contest_PrintTextToBg0WindowAt(i + MOVE_WINDOWS_START, moveName, 5, 1, 7);
    }

    DrawMoveSelectArrow(eContest.playerMoveChoice);
    PrintContestMoveDescription(gContestMons[gContestPlayerMonIndex].moves[eContest.playerMoveChoice]);
    gTasks[taskId].func = Task_HandleMoveSelectInput;
}

static void Task_HandleMoveSelectInput(u8 taskId)
{
    u8 numMoves = 0;
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[gContestPlayerMonIndex].moves[i] != MOVE_NONE)
            numMoves++;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_SelectedMove;
    }
    else
    {
        switch (gMain.newAndRepeatedKeys)
        {
        case B_BUTTON:
            // Cancel move selection
            PlaySE(SE_SELECT);
            SetBottomSliderHeartsInvisibility(FALSE);
            ConvertIntToDecimalStringN(gStringVar1, eContest.appealNumber + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
            if (!Contest_IsMonsTurnDisabled(gContestPlayerMonIndex))
                StringCopy(gDisplayedStringBattle, gText_AppealNumWhichMoveWillBePlayed);
            else
                StringCopy(gDisplayedStringBattle, gText_AppealNumButItCantParticipate);
            ContestClearGeneralTextWindow();
            StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
            Contest_StartTextPrinter(gStringVar4, 0);
            gBattle_BG0_Y = 0;
            gBattle_BG2_Y = 0;
            gTasks[taskId].func = Task_TryShowMoveSelectScreen;
            break;
        case DPAD_LEFT:
        case DPAD_RIGHT:
            break;
        case DPAD_UP:
            EraseMoveSelectArrow(eContest.playerMoveChoice);
            if (eContest.playerMoveChoice == 0)
                eContest.playerMoveChoice = numMoves - 1;
            else
                eContest.playerMoveChoice--;
            DrawMoveSelectArrow(eContest.playerMoveChoice);
            PrintContestMoveDescription(gContestMons[gContestPlayerMonIndex].moves[eContest.playerMoveChoice]);
            if (numMoves > 1)
                PlaySE(SE_SELECT);
            break;
        case DPAD_DOWN:
            EraseMoveSelectArrow(eContest.playerMoveChoice);
            if (eContest.playerMoveChoice == numMoves - 1)
                eContest.playerMoveChoice = 0;
            else
                eContest.playerMoveChoice++;
            DrawMoveSelectArrow(eContest.playerMoveChoice);
            PrintContestMoveDescription(gContestMons[gContestPlayerMonIndex].moves[eContest.playerMoveChoice]);
            if (numMoves > 1)
                PlaySE(SE_SELECT);
            break;
        }
    }
}

static void DrawMoveSelectArrow(s8 moveIndex)
{
    ContestBG_FillBoxWithIncrementingTile(2, 55, 0, 31 + moveIndex * 2, 2, 2, 17, 1);
}

static void EraseMoveSelectArrow(s8 moveIndex)
{
    ContestBG_FillBoxWithIncrementingTile(2, 11, 0, 31 + moveIndex * 2, 2, 1, 17, 1);
    ContestBG_FillBoxWithIncrementingTile(2, 11, 0, 32 + moveIndex * 2, 2, 1, 17, 1);
}

static void Task_SelectedMove(u8 taskId)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        u16 move = GetChosenMove(gContestPlayerMonIndex);
        u8 taskId2;

        eContestantStatus[gContestPlayerMonIndex].currMove = move;
        taskId2 = CreateTask(Task_LinkContest_CommunicateMoveSelections, 0);
        SetTaskFuncWithFollowupFunc(taskId2, Task_LinkContest_CommunicateMoveSelections, Task_EndCommunicateMoveSelections);
        gTasks[taskId].func = TaskDummy1;
        ContestPrintLinkStandby();
        SetBottomSliderHeartsInvisibility(FALSE);
    }
    else
    {
        GetAllChosenMoves();
        gTasks[taskId].func = Task_HideMoveSelectScreen;
    }
}

static void Task_EndCommunicateMoveSelections(u8 taskId)
{
    DestroyTask(taskId);
    gTasks[eContest.mainTaskId].func = Task_HideMoveSelectScreen;
}

static void Task_HideMoveSelectScreen(u8 taskId)
{
    s32 i;

    ContestClearGeneralTextWindow();
    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    SetBottomSliderHeartsInvisibility(FALSE);

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        FillWindowPixelBuffer(MOVE_WINDOWS_START + i, PIXEL_FILL(0));
        PutWindowTilemap(MOVE_WINDOWS_START + i);
        CopyWindowToVram(MOVE_WINDOWS_START + i, 2);
    }
    Contest_SetBgCopyFlags(0);
    // This seems to be a bug; it should have just copied PLTT_BUFFER_SIZE.
    DmaCopy32Defvars(3, gPlttBufferFaded, eUnknownHeap1A004.unk18604, PLTT_BUFFER_SIZE * 2);
    LoadPalette(eUnknownHeap1A004.unk18204, 0, PLTT_BUFFER_SIZE * 2);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = Task_HideApplauseMeterForAppealStart;
}

static void Task_HideApplauseMeterForAppealStart(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 2)
    {
        gTasks[taskId].data[0] = 0;
        if (++gTasks[taskId].data[1] == 2)
        {
            TryMoveApplauseMeterOffscreen();
            AnimateSliderHearts(SLIDER_HEART_ANIM_DISAPPEAR);
            gTasks[taskId].func = Task_WaitHideApplauseMeterForAppealStart;
        }
    }
}

static void Task_WaitHideApplauseMeterForAppealStart(u8 taskId)
{
    if (!eContest.applauseMeterIsMoving && !eContest.sliderHeartsAnimating)
        gTasks[taskId].func = sub_80D8A88;
}

static void sub_80D8A88(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 19)
    {
        eContest.turnNumber = 0;
        eContest.unk1921C = gRngValue;
        if ((gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK) && sub_80DA8A4())
        {
            s32 i;

            for (i = 0; i + gNumLinkContestPlayers < CONTESTANT_COUNT; i++)
            {
                eContestantStatus[gNumLinkContestPlayers + i].currMove = GetChosenMove(gNumLinkContestPlayers + i);
            }
        }
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = Task_DoAppeals;
    }
}

#define tState data[0]

static void Task_DoAppeals(u8 taskId)
{
    u8 spriteId;
    s32 i;
    u8 r6 = eContest.currentContestant;
    s8 r3;

    switch (gTasks[taskId].tState)
    {
    case 0:
        ContestDebugDoPrint();
        for (i = 0; eContest.turnNumber != gContestResources->field_8->turnOrder[i]; i++)
            ;
        eContest.currentContestant = i;
        r6 = eContest.currentContestant;
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            u8 taskId2;

            eContest.unk1920B_2 = 1;
            if (sub_80DA8A4())
                sub_80DD080(eContest.currentContestant);
            taskId2 = CreateTask(sub_80FCC88, 0);
            SetTaskFuncWithFollowupFunc(taskId2, sub_80FCC88, sub_80DA110);
            ContestPrintLinkStandby();
            gTasks[taskId].tState = 1;
        }
        else
        {
            sub_80DD080(eContest.currentContestant);
            gTasks[taskId].tState = 2;
        }
        return;
    case 1:
        if (!eContest.unk1920B_2)
            gTasks[taskId].tState = 2;
        return;
    case 2:
        sub_80DF080(r6);
        ContestDebugPrintBitStrings();
        if (eContestantStatus[r6].numTurnsSkipped != 0
            || eContestantStatus[r6].noMoreTurns)
        {
            gTasks[taskId].tState = 31;
        }
        else
        {
            ContestClearGeneralTextWindow();
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 3;
        }
        return;
    case 3:
        for (i = 0; i < CONTESTANT_COUNT; i++)
            gBattleMonForms[i] = 0;
        memset(gContestResources->field_18, 0, sizeof(*gContestResources->field_18));
        sub_80DE9DC(eContest.currentContestant);
        spriteId = CreateContestantSprite(
            gContestMons[eContest.currentContestant].species,
            gContestMons[eContest.currentContestant].otId,
            gContestMons[eContest.currentContestant].personality,
            eContest.currentContestant);
        gSprites[spriteId].pos2.x = 120;
        gSprites[spriteId].callback = sub_80DA134;
        gTasks[taskId].data[2] = spriteId;
        gBattlerSpriteIds[gBattlerAttacker] = spriteId;
        sub_80DCBE8(sub_80DC9EC(eContest.currentContestant), FALSE);
        gTasks[taskId].tState = 4;
        return;
    case 4:
        spriteId = gTasks[taskId].data[2];
        if (gSprites[spriteId].callback == SpriteCallbackDummy)
        {
            if (!gContestResources->field_14[r6].unk2_1)
                gTasks[taskId].tState = 5;
        }
        return;
    case 5:
        if (eContestantStatus[r6].nervous)
        {
            gTasks[taskId].tState = 33;
        }
        else
        {
            ContestClearGeneralTextWindow();
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            if (eContestantStatus[r6].currMove < MOVES_COUNT)
                StringCopy(gStringVar2, gMoveNames[eContestantStatus[r6].currMove]);
            else
                StringCopy(gStringVar2, sInvalidContestMoveNames[eContestantStatus[r6].moveCategory]);
            StringExpandPlaceholders(gStringVar4, gText_MonAppealedWithMove);
            Contest_StartTextPrinter(gStringVar4, 1);
            gTasks[taskId].tState = 6;
        }
        return;
    case 6:
        if (!Contest_RunTextPrinters())
        {
            eContest.unk1925E = 0;
            gTasks[taskId].tState = 7;
        }
        return;
    case 7:
        {
            u16 move = SanitizeMove(eContestantStatus[eContest.currentContestant].currMove);

            sub_80DE864(eContest.currentContestant);
            sub_80DE9DC(eContest.currentContestant);
            SelectContestMoveBankTarget(move);
            DoMoveAnim(move);
            gTasks[taskId].tState = 8;
        }
        return;
    case 8:
        gAnimScriptCallback();
        if (!gAnimScriptActive)
        {
            sub_80DE9B0(r6);
            if (eContest.unk1925E != 0)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].tState = 9;
            }
            else
            {
                if (!eContestantStatus[r6].hasJudgesAttention)
                    sub_80DC674(r6);
                sub_80DE12C();
                gTasks[taskId].tState = 23;
            }
        }
        return;
    case 9:
        if (gTasks[taskId].data[10]++ > 30)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 7;
        }
        return;
    case 23:
        gTasks[taskId].data[1] = 0;
        if (eContestantStatus[r6].effectStringId != CONTEST_STRING_NONE)
        {
            sub_80DD45C(r6, eContestantStatus[r6].effectStringId);
            eContestantStatus[r6].effectStringId = CONTEST_STRING_NONE;
            gTasks[taskId].tState = 24;
        }
        else
        {
            if (eContestantStatus[r6].effectStringId2 != CONTEST_STRING_NONE)
            {
                for (i = 0; i < CONTESTANT_COUNT; i++)
                {
                    if (i != r6 && eContestantStatus[i].effectStringId != CONTEST_STRING_NONE)
                        break;
                }
                if (i == 4)
                {
                    sub_80DD45C(r6, eContestantStatus[r6].effectStringId2);
                    eContestantStatus[r6].effectStringId2 = CONTEST_STRING_NONE;
                    gTasks[taskId].tState = 24;
                }
                else
                {
                    gTasks[taskId].tState = 48;
                }
            }
            else
            {
                gTasks[taskId].tState = 48;
            }
        }
        return;
    case 24:
        if (!Contest_RunTextPrinters())
            gTasks[taskId].tState = 23;
        return;
    case 48:
        if (eContestantStatus[r6].turnOrderModAction == 1)
        {
            sub_80DD720(5);
        }
        else if (eContestantStatus[r6].turnOrderModAction == 2)
        {
            sub_80DD720(6);
        }
        else if (eContestantStatus[r6].turnOrderModAction == 3)
        {
            sub_80DD720(7);
        }
        else
        {
            gTasks[taskId].tState = 47;
            return;
        }
        gTasks[taskId].tState = 49;
        return;
    case 49:
        if (!eContest.unk1920A_4)
            gTasks[taskId].tState = 47;
        return;
    case 47:
        sub_80DE008(TRUE);
        gTasks[taskId].tState = 12;
        return;
    case 12:
        sub_80DC028(0, eContestantStatus[r6].appeal2, r6);
        gTasks[taskId].tState = 13;
        return;
    case 13:
        if (!gContestResources->field_14[eContest.currentContestant].unk2_2)
            gTasks[taskId].tState = 35;
        return;
    case 35:
        if (eContestantStatus[r6].conditionMod == 1)
            sub_80DD720(8);
        gTasks[taskId].tState = 36;
        return;
    case 36:
        if (!eContest.unk1920A_4)
            gTasks[taskId].tState = 37;
        return;
    case 37:
        if (sub_80DB5B8(r6, 1))
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 38;
        }
        else
        {
            gTasks[taskId].tState = 50;
        }
        return;
    case 38:
        if (++gTasks[taskId].data[10] > 20)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 50;
        }
        return;
    case 50:
        if (sub_80DB798(r6))
            PlaySE(SE_C_PASI);
        gTasks[taskId].tState = 25;
        return;
    case 25:
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].tState = 26;
        return;
    case 26:
        {
            s32 r2 = 0;

            r3 = 0;
            for (i = gTasks[taskId].data[1]; i < CONTESTANT_COUNT; i++)
            {
                r3 = 0;
                for (r2 = 0; r2 < CONTESTANT_COUNT; r2++)
                {
                    if (r2 != r6 && gContestantTurnOrder[r2] == i
                        && eContestantStatus[r2].effectStringId != CONTEST_STRING_NONE)
                    {
                        r3 = 1;
                        break;
                    }
                }
                if (r3 != 0)
                    break;
            }
            if (r3)
            {
                gTasks[taskId].data[1] = gContestantTurnOrder[r2];
                sub_80DD45C(r2, eContestantStatus[r2].effectStringId);
                eContestantStatus[r2].effectStringId = CONTEST_STRING_NONE;
                gTasks[taskId].tState = 27;
            }
            else
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].tState = 51;
                sub_80DB884();
            }
        }
        return;
    case 27:
        if (!Contest_RunTextPrinters())
            gTasks[taskId].tState = 28;
        return;
    case 28:
        for (i = 0; gTasks[taskId].data[1] != gContestantTurnOrder[i]; i++)
            ;
        sub_80DC028(eContestantStatus[i].appeal2 + eContestantStatus[i].jam, -eContestantStatus[i].jam, i);
        gTasks[taskId].tState = 29;
        return;
    case 29:
        for (i = 0; gTasks[taskId].data[1] != gContestantTurnOrder[i]; i++)
            ;
        if (!gContestResources->field_14[i].unk2_2)
            gTasks[taskId].tState = 39;
        return;
    case 39:
        for (i = 0; gTasks[taskId].data[1] != gContestantTurnOrder[i]; i++)
            ;
        if (sub_80DB5B8(i, 1))
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 40;
        }
        else
        {
            gTasks[taskId].tState = 30;
        }
        return;
    case 40:
        if (++gTasks[taskId].data[10] > 20)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 30;
        }
        return;
    case 30:
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            if (gContestantTurnOrder[i] == gTasks[taskId].data[1])
                break;
        }
        if (sub_80DB798(i))
            PlaySE(SE_C_PASI);
        else
            PlaySE(SE_C_SYU);
        if (eContestantStatus[i].judgesAttentionWasRemoved)
        {
            sub_80DC674(i);
            eContestantStatus[i].judgesAttentionWasRemoved = 0;
        }
        gTasks[taskId].data[1]++;
        gTasks[taskId].tState = 26;
        return;
    case 51:
        if (gTasks[taskId].data[10]++ > 9)
        {
            gTasks[taskId].data[10] = 0;
            if (eContestantStatus[r6].numTurnsSkipped != 0
                || eContestantStatus[r6].turnSkipped)
            {
                ContestClearGeneralTextWindow();
                StringCopy(gStringVar1, gContestMons[r6].nickname);
                StringExpandPlaceholders(gStringVar4, gText_MonCantAppealNextTurn);
                Contest_StartTextPrinter(gStringVar4, 1);
            }
            gTasks[taskId].tState = 52;
        }
        return;
    case 52:
        if (!Contest_RunTextPrinters())
        {
            if (!eContestantStatus[r6].unk15_6)
                gTasks[taskId].tState = 17;
            else
                gTasks[taskId].tState = 14;
        }
        return;
    case 14:
        r3 = eContestantStatus[r6].unk16;
        if (eContestantStatus[r6].unk16 != 0)
        {
            ContestClearGeneralTextWindow();
            if (r3 == 1)
                Contest_StartTextPrinter(gText_AppealComboWentOverWell, TRUE);
            else if (r3 == 2)
                Contest_StartTextPrinter(gText_AppealComboWentOverVeryWell, TRUE);
            else
                Contest_StartTextPrinter(gText_AppealComboWentOverExcellently, TRUE);
            sub_80DD720(3);
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 45;
        }
        else
        {
            ContestClearGeneralTextWindow();
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            StringExpandPlaceholders(gStringVar4, gText_JudgeLookedAtMonExpectantly);
            Contest_StartTextPrinter(gStringVar4, 1);
            sub_80DD720(2);
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 45;
        }
        return;
    case 45:
        if (!eContest.unk1920A_4)
        {
            sub_80DC9B4(eContest.currentContestant);
            gTasks[taskId].tState = 15;
        }
        return;
    case 15:
        if (!Contest_RunTextPrinters())
        {
            if (++gTasks[taskId].data[10] > 50)
            {
                if (!eContestantStatus[r6].hasJudgesAttention)
                {
                    sub_80DC028(
                        eContestantStatus[r6].appeal2,
                        eContestantStatus[r6].unk17,
                        r6);
                    eContestantStatus[r6].appeal2 += eContestantStatus[r6].unk17;
                }
                gTasks[taskId].tState = 16;
            }
        }
        return;
    case 16:
        if (!gContestResources->field_14[r6].unk2_2)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 17;
        }
        return;
    case 17:
        if (eContestantStatus[r6].repeatedMove)
        {
            ContestClearGeneralTextWindow();
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            StringExpandPlaceholders(gStringVar4, gText_RepeatedAppeal);
            Contest_StartTextPrinter(gStringVar4, TRUE);
            gTasks[taskId].data[10] = 0;
            sub_80DD720(0);
            gTasks[taskId].tState = 46;
        }
        else
        {
            gTasks[taskId].tState = 41;
        }
        return;
    case 46:
        if (!eContest.unk1920A_4)
            gTasks[taskId].tState = 19;
        return;
    case 19:
        if (!Contest_RunTextPrinters())
        {
            sub_80DC028(eContestantStatus[r6].appeal2, -eContestantStatus[r6].unk18, r6);
            eContestantStatus[r6].appeal2 -= eContestantStatus[r6].unk18;
            gTasks[taskId].tState = 18;
        }
        return;
    case 18:
        ContestDebugDoPrint();
        if (!gContestResources->field_14[r6].unk2_2)
        {
            gTasks[taskId].data[10] = 0;
            ContestClearGeneralTextWindow();
            gTasks[taskId].tState = 41;
        }
        return;
    case 41:
        if (gContestResources->field_10->excitementFrozen && r6 != gContestResources->field_10->excitementFreezer)
        {
            gTasks[taskId].tState = 57;
        }
        else
        {
            r3 = gContestResources->field_10->bits_0;
            if (eContestantStatus[r6].overrideCategoryExcitementMod)
            {
                r3 = 1;
                StringCopy(gStringVar3, gMoveNames[eContestantStatus[r6].currMove]);
            }
            else
            {
                StringCopy(gStringVar3, sContestConditions[gContestMoves[eContestantStatus[r6].currMove].contestCategory]);
            }
            if (r3 > 0)
            {
                if (eContestantStatus[r6].repeatedMove)
                    r3 = 0;
            }
            ContestClearGeneralTextWindow();
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            eContest.applauseLevel += r3;
            if (eContest.applauseLevel < 0)
                eContest.applauseLevel = 0;
            if (r3 == 0)
            {
                gTasks[taskId].tState = 55;
            }
            else
            {
                if (r3 < 0)
                    StringExpandPlaceholders(gStringVar4, gText_MonsXDidntGoOverWell);
                else if (r3 > 0 && eContest.applauseLevel <= 4)
                    StringExpandPlaceholders(gStringVar4, gText_MonsXWentOverGreat);
                else
                    StringExpandPlaceholders(gStringVar4, gText_MonsXGotTheCrowdGoing);
                Contest_StartTextPrinter(gStringVar4, 1);
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[11] = 0;
                if (r3 < 0)
                    gTasks[taskId].tState = 53;
                else
                    gTasks[taskId].tState = 54;
            }
        }
        return;
    case 53:
        switch (gTasks[taskId].data[10])
        {
        case 0:
            sub_80DDED0(-1, 1);
            PlayFanfare(MUS_ME_ZANNEN);
            gTasks[taskId].data[10]++;
            break;
        case 1:
            if (!eContest.unk1920B_0 && !Contest_RunTextPrinters())
            {
                ShowAndUpdateApplauseMeter(-1);
                gTasks[taskId].data[10]++;
            }
            break;
        case 2:
            if (!eContest.isShowingApplauseMeter)
            {
                if (gTasks[taskId].data[11]++ > 29)
                {
                    gTasks[taskId].data[11] = 0;
                    sub_80DDED0(-1, -1);
                    gTasks[taskId].data[10]++;
                }
            }
            break;
        case 3:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[11] = 0;
                gTasks[taskId].tState = 43;
            }
            break;
        }
        return;
    case 54:
        switch (gTasks[taskId].data[10])
        {
        case 0:
            if (!Contest_RunTextPrinters())
            {
                sub_80DDED0(1, 1);
                gTasks[taskId].data[10]++;
            }
            break;
        case 1:
            if (!eContest.unk1920B_0)
            {
                sub_80DDE0C();
                PlaySE(SE_W227B);
                ShowAndUpdateApplauseMeter(1);
                gTasks[taskId].data[10]++;
            }
            break;
        case 2:
            if (!eContest.isShowingApplauseMeter)
            {
                if (gTasks[taskId].data[11]++ > 29)
                {
                    gTasks[taskId].data[11] = 0;
                    sub_80DC028(eContestantStatus[r6].appeal2, gContestResources->field_10->unk2, r6);
                    eContestantStatus[r6].appeal2 += gContestResources->field_10->unk2;
                    gTasks[taskId].data[10]++;
                }
            }
            break;
        case 3:
            if (!gContestResources->field_14[r6].unk2_2)
            {
                if (!eContest.unk1920A_7)
                {
                    sub_80DDED0(1, -1);
                    gTasks[taskId].data[10]++;
                }
            }
            break;
        case 4:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[11] = 0;
                gTasks[taskId].tState = 43;
            }
            break;
        }
        return;
    case 43:
        if (!gContestResources->field_14[r6].unk2_2)
        {
            ContestClearGeneralTextWindow();
            gTasks[taskId].tState = 55;
        }
        return;
    case 57:
        ContestClearGeneralTextWindow();
        StringCopy(gStringVar3, gContestMons[gContestResources->field_10->excitementFreezer].nickname);
        StringCopy(gStringVar1, gContestMons[r6].nickname);
        StringCopy(gStringVar2, gMoveNames[eContestantStatus[r6].currMove]);
        StringExpandPlaceholders(gStringVar4, gText_CrowdContinuesToWatchMon);
        Contest_StartTextPrinter(gStringVar4, TRUE);
        gTasks[taskId].tState = 58;
        return;
    case 58:
        if (!Contest_RunTextPrinters())
        {
            ContestClearGeneralTextWindow();
            StringExpandPlaceholders(gStringVar4, gText_MonsMoveIsIgnored);
            Contest_StartTextPrinter(gStringVar4, TRUE);
            gTasks[taskId].tState = 59;
        }
        return;
    case 59:
        if (!Contest_RunTextPrinters())
        {
            ContestClearGeneralTextWindow();
            gTasks[taskId].tState = 55;
        }
        return;
    case 33:
        if (eContestantStatus[r6].hasJudgesAttention)
            eContestantStatus[r6].hasJudgesAttention = 0;
        sub_80DC9B4(r6);
        StringCopy(gStringVar1, gContestMons[r6].nickname);
        StringCopy(gStringVar2, gMoveNames[eContestantStatus[r6].currMove]);
        StringExpandPlaceholders(gStringVar4, gText_MonWasTooNervousToMove);
        Contest_StartTextPrinter(gStringVar4, TRUE);
        gTasks[taskId].tState = 34;
        return;
    case 34:
        if (!Contest_RunTextPrinters())
            gTasks[taskId].tState = 55;
        return;
    case 55:
        TryMoveApplauseMeterOffscreen();
        gTasks[taskId].tState = 56;
        return;
    case 56:
        if (!eContest.applauseMeterIsMoving)
        {
            if (eContest.applauseLevel > 4)
            {
                eContest.applauseLevel = 0;
                UpdateApplauseMeter();
            }
            gTasks[taskId].tState = 10;
        }
        return;
    case 10:
        spriteId = gTasks[taskId].data[2];
        gSprites[spriteId].callback = sub_80DA164;
        gTasks[taskId].tState = 11;
        return;
    case 11:
        spriteId = gTasks[taskId].data[2];
        if (gSprites[spriteId].invisible)
        {
            FreeSpriteOamMatrix(&gSprites[spriteId]);
            DestroySprite(&gSprites[spriteId]);
            gTasks[taskId].tState = 20;
        }
        return;
    case 20:
        gTasks[taskId].data[10] = 0;
        gTasks[taskId].tState = 21;
        return;
    case 31:
        ContestClearGeneralTextWindow();
        StringCopy(gStringVar1, gContestMons[r6].nickname);
        StringExpandPlaceholders(gStringVar4, gText_MonWasWatchingOthers);
        Contest_StartTextPrinter(gStringVar4, TRUE);
        gTasks[taskId].tState = 32;
        return;
    case 32:
        if (!Contest_RunTextPrinters())
            gTasks[taskId].tState = 21;
        return;
    case 21:
        if (++gTasks[taskId].data[10] > 29)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].tState = 22;
        }
        return;
    case 22:
        if (++eContest.turnNumber == CONTESTANT_COUNT)
        {
            gTasks[taskId].tState = 0;
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].func = sub_80DA198;
        }
        else
        {
            gTasks[taskId].tState = 0;
        }
        return;
    }
}

static void sub_80DA110(u8 taskId)
{
    eContest.unk1920B_2 = 0;
    DestroyTask(taskId);
}

static void sub_80DA134(struct Sprite *sprite)
{
    if (sprite->pos2.x != 0)
    {
        sprite->pos2.x -= 2;
    }
    else
    {
        if (++sprite->data[0] == 31)
        {
            sprite->data[0] = 0;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

static void sub_80DA164(struct Sprite *sprite)
{
    sprite->pos2.x -= 6;
    if (sprite->pos1.x + sprite->pos2.x < -32)
    {
        sprite->callback = SpriteCallbackDummy;
        sprite->invisible = TRUE;
    }
}

static void sub_80DA198(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            u8 taskId2;

            eContest.unk1920B_2 = 1;
            if (sub_80DA8A4())
            {
                RankContestants();
                SetAttentionLevels();
            }
            taskId2 = CreateTask(sub_80FCC88, 0);
            SetTaskFuncWithFollowupFunc(taskId2, sub_80FCC88, sub_80DA110);
            ContestPrintLinkStandby();
            gTasks[taskId].data[0] = 1;
        }
        else
        {
            RankContestants();
            SetAttentionLevels();
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 1:
        if (!eContest.unk1920B_2)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DA25C;
        break;
    }
}

static void sub_80DA25C(u8 taskId)
{
    sub_80DE008(FALSE);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_80DA28C;
}

static void sub_80DA28C(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (++gTasks[taskId].data[1] > 20)
        {
            AnimateSliderHearts(SLIDER_HEART_ANIM_APPEAR);
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (!eContest.sliderHeartsAnimating)
        {
            if (++gTasks[taskId].data[1] > 20)
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[0]++;
            }
        }
        break;
    case 2:
        UpdateHeartSliders();
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = sub_80DA31C;
        break;
    }
}

static void sub_80DA31C(u8 taskId)
{
    if (SlidersDoneUpdating())
        gTasks[taskId].func = sub_80DA348;
}

static void sub_80DA348(u8 taskId)
{
    DmaCopy32Defvars(3, eUnknownHeap1A004.unk18204, gPlttBufferUnfaded, PLTT_BUFFER_SIZE * 2);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 2;
    gTasks[taskId].func = sub_80DA38C;
}

static void sub_80DA38C(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 2)
    {
        gTasks[taskId].data[0] = 0;
        if (--gTasks[taskId].data[1] == 0)
            gTasks[taskId].func = sub_80DA3CC;
    }
}

static void sub_80DA3CC(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        u8 attention = eContestantStatus[gContestPlayerMonIndex].attentionLevel;

        ContestClearGeneralTextWindow();
        StringCopy(gStringVar1, gContestMons[gContestPlayerMonIndex].nickname);
        StringExpandPlaceholders(gStringVar4, sRoundResultTexts[attention]);
        Contest_StartTextPrinter(gStringVar4, TRUE);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!Contest_RunTextPrinters())
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = sub_80DA464;
            ContestDebugDoPrint();
        }
    }
}

static void sub_80DA464(u8 taskId)
{
    if (gTasks[taskId].data[0]++ > 29)
    {
        gTasks[taskId].data[0] = 0;
        UpdateHeartSliders();
        gTasks[taskId].func = sub_80DA49C;
    }
}

static void sub_80DA49C(u8 taskId)
{
    if (SlidersDoneUpdating())
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DA4CC;
    }
}

static void sub_80DA4CC(u8 taskId)
{
    sub_80DE224();
    gTasks[taskId].func = sub_80DE424;
}

static void sub_80DA4F4(u8 taskId)
{
    sub_80DE350();
    gTasks[taskId].func = sub_80DA51C;
}

static void sub_80DA51C(u8 taskId)
{
    vu16 sp0 = GetGpuReg(REG_OFFSET_BG0CNT);
    vu16 sp2 = GetGpuReg(REG_OFFSET_BG2CNT);
    ((vBgCnt *)&sp0)->priority = 0;
    ((vBgCnt *)&sp2)->priority = 0;
    SetGpuReg(REG_OFFSET_BG0CNT, sp0);
    SetGpuReg(REG_OFFSET_BG2CNT, sp2);
    eContest.appealNumber++;
    if (eContest.appealNumber == CONTEST_NUM_APPEALS)
    {
        gTasks[taskId].func = Task_EndAppeals;
    }
    else
    {
        StartMoveApplauseMeterOnscreen();
        gTasks[taskId].func = sub_80DA5B4;
    }
}

static void sub_80DA5B4(u8 taskId)
{
    if (!eContest.applauseMeterIsMoving)
        gTasks[taskId].func = Task_DisplayAppealNumberText;
}

static void Task_EndAppeals(u8 taskId)
{
    s32 i;

    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    for (i = 0; i < CONTESTANT_COUNT; i++)
        gContestMonAppealPointTotals[i] = eContestantStatus[i].pointTotal;
    CalculateFinalScores();
    ContestClearGeneralTextWindow();
    if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
        BravoTrainerPokemonProfile_BeforeInterview1(eContestantStatus[gContestPlayerMonIndex].prevMove);
    else
    {
        sub_80DF250();
        sub_80DF4F8();
        ContestDebugPrintBitStrings();
    }
    gContestRngValue = gRngValue;
    StringExpandPlaceholders(gStringVar4, gText_AllOutOfAppealTime);
    Contest_StartTextPrinter(gStringVar4, TRUE);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = Task_WaitForOutOfTimeMsg;
}

static void Task_WaitForOutOfTimeMsg(u8 taskId)
{
    if (!Contest_RunTextPrinters())
    {
        sub_80DE224();
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 160;
        PlaySE12WithPanning(SE_C_MAKU_D, 0);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = Task_CoverAppealPanelForEnd;
    }
}

static void Task_CoverAppealPanelForEnd(u8 taskId)
{
    gBattle_BG1_Y -= 7;
    if ((s16)gBattle_BG1_Y < 0)
        gBattle_BG1_Y = 0;
    if (gBattle_BG1_Y == 0)
    {
        gTasks[taskId].func = Task_TryCommunicateFinalStandings;
        gTasks[taskId].data[0] = 0;
    }
}

static void Task_TryCommunicateFinalStandings(u8 taskId)
{
    if (gTasks[taskId].data[0]++ >= 50)
    {
        gTasks[taskId].data[0] = 0;
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            gTasks[taskId].func = Task_CommunicateFinalStandings;
        }
        else
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_ContestReturnToField;
        }
    }
}

static void Task_CommunicateFinalStandings(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_LinkContest_CommunicateFinalStandings, 0);

    SetTaskFuncWithFollowupFunc(taskId2, Task_LinkContest_CommunicateFinalStandings, Task_EndCommunicateFinalStandings);
    gTasks[taskId].func = TaskDummy1;
    ContestPrintLinkStandby();
    SetBottomSliderHeartsInvisibility(FALSE);
}

static void Task_EndCommunicateFinalStandings(u8 taskId)
{
    DestroyTask(taskId);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[eContest.mainTaskId].func = Task_ContestReturnToField;
}

static void Task_ContestReturnToField(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        gFieldCallback = FieldCB_ContestReturnToField;
        FreeAllWindowBuffers();
        FreeContestResources();
        FreeMonSpritesGfx();
        SetMainCallback2(CB2_ReturnToField);
    }
}

static void FieldCB_ContestReturnToField(void)
{
    ScriptContext2_Disable();
    EnableBothScriptContexts();
}

static void TryPutPlayerLast(void)
{
    if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
        gContestPlayerMonIndex = CONTESTANT_COUNT - 1;
}

static bool8 sub_80DA8A4(void)
{
    if (gContestPlayerMonIndex == gUnknown_02039F2B)
        return TRUE;
    return FALSE;
}

void CreateContestMonFromParty(u8 partyIndex)
{
    u8 name[20];
    u16 heldItem;
    s16 cool;
    s16 beauty;
    s16 cute;
    s16 smart;
    s16 tough;

    StringCopy(name, gSaveBlock2Ptr->playerName);
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        StripPlayerNameForLinkContest(name);
    }
    memcpy(gContestMons[gContestPlayerMonIndex].trainerName, name, 8);
    if (gSaveBlock2Ptr->playerGender == MALE)
        gContestMons[gContestPlayerMonIndex].trainerGfxId = OBJ_EVENT_GFX_LINK_BRENDAN;
    else
        gContestMons[gContestPlayerMonIndex].trainerGfxId = OBJ_EVENT_GFX_LINK_MAY;
    gContestMons[gContestPlayerMonIndex].aiChecks = 0;
    gContestMons[gContestPlayerMonIndex].highestRank = 0;
    gContestMons[gContestPlayerMonIndex].species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, name);
    StringGetEnd10(name);
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        StripMonNameForLinkContest(name, GetMonData(&gPlayerParty[partyIndex], MON_DATA_LANGUAGE));
    }
    memcpy(gContestMons[gContestPlayerMonIndex].nickname, name, POKEMON_NAME_LENGTH + 1);
    StringCopy(gContestMons[gContestPlayerMonIndex].nickname, name);
    gContestMons[gContestPlayerMonIndex].cool = GetMonData(&gPlayerParty[partyIndex], MON_DATA_COOL);
    gContestMons[gContestPlayerMonIndex].beauty = GetMonData(&gPlayerParty[partyIndex], MON_DATA_BEAUTY);
    gContestMons[gContestPlayerMonIndex].cute = GetMonData(&gPlayerParty[partyIndex], MON_DATA_CUTE);
    gContestMons[gContestPlayerMonIndex].smart = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SMART);
    gContestMons[gContestPlayerMonIndex].tough = GetMonData(&gPlayerParty[partyIndex], MON_DATA_TOUGH);
    gContestMons[gContestPlayerMonIndex].sheen = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SHEEN);
    gContestMons[gContestPlayerMonIndex].moves[0] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE1);
    gContestMons[gContestPlayerMonIndex].moves[1] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE2);
    gContestMons[gContestPlayerMonIndex].moves[2] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE3);
    gContestMons[gContestPlayerMonIndex].moves[3] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE4);
    gContestMons[gContestPlayerMonIndex].personality = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PERSONALITY);
    gContestMons[gContestPlayerMonIndex].otId = GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_ID);

    heldItem = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HELD_ITEM);
    cool   = gContestMons[gContestPlayerMonIndex].cool;
    beauty = gContestMons[gContestPlayerMonIndex].beauty;
    cute   = gContestMons[gContestPlayerMonIndex].cute;
    smart  = gContestMons[gContestPlayerMonIndex].smart;
    tough  = gContestMons[gContestPlayerMonIndex].tough;
    if      (heldItem == ITEM_RED_SCARF)
        cool += 20;
    else if (heldItem == ITEM_BLUE_SCARF)
        beauty += 20;
    else if (heldItem == ITEM_PINK_SCARF)
        cute += 20;
    else if (heldItem == ITEM_GREEN_SCARF)
        smart += 20;
    else if (heldItem == ITEM_YELLOW_SCARF)
        tough += 20;
    if (cool > 255)
        cool = 255;
    if (beauty > 255)
        beauty = 255;
    if (cute > 255)
        cute = 255;
    if (smart > 255)
        smart = 255;
    if (tough > 255)
        tough = 255;
    gContestMons[gContestPlayerMonIndex].cool = cool;
    gContestMons[gContestPlayerMonIndex].beauty = beauty;
    gContestMons[gContestPlayerMonIndex].cute = cute;
    gContestMons[gContestPlayerMonIndex].smart = smart;
    gContestMons[gContestPlayerMonIndex].tough = tough;
}

void SetContestants(u8 contestType, u8 rank)
{
    s32 i;
    u8 opponentsCount = 0;
    u8 opponents[100];
    bool8 allowPostgameContestants = FALSE;
    const u8 * filter;

    TryPutPlayerLast();

    if (FlagGet(FLAG_SYS_GAME_CLEAR) && !(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
        allowPostgameContestants = TRUE;

    // Find all suitable opponents
    filter = gPostgameContestOpponentFilter;
    for (i = 0; i < ARRAY_COUNT(gContestOpponents); i++)
    {
        if (rank == gContestOpponents[i].whichRank)
        {
            if (allowPostgameContestants == TRUE)
            {
                if (filter[i] == CONTEST_FILTER_NO_POSTGAME)
                    continue;
            }
            else
            {
                if (filter[i] == CONTEST_FILTER_ONLY_POSTGAME)
                    continue;
            }
            if      (contestType == CONTEST_CATEGORY_COOL && gContestOpponents[i].aiPool_Cool)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_BEAUTY && gContestOpponents[i].aiPool_Beauty)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_CUTE && gContestOpponents[i].aiPool_Cute)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_SMART && gContestOpponents[i].aiPool_Smart)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_TOUGH && gContestOpponents[i].aiPool_Tough)
                opponents[opponentsCount++] = i;
        }
    }
    opponents[opponentsCount] = 0xFF;

    // Choose three random opponents from the list
    for (i = 0; i < CONTESTANT_COUNT - 1; i++)
    {
        u16 rnd = Random() % opponentsCount;
        s32 j;

        gContestMons[i] = gContestOpponents[opponents[rnd]];
        for (j = rnd; opponents[j] != 0xFF; j++)
            opponents[j] = opponents[j + 1];
        opponentsCount--;
    }

    CreateContestMonFromParty(gContestMonPartyIndex);
}

void SetLinkAIContestants(u8 contestType, u8 rank, bool32 isPostgame)
{
    s32 i, j;
    u8 opponentsCount = 0;
    u8 opponents[100];

    if (gNumLinkContestPlayers == CONTESTANT_COUNT)
        return;

    // Find all suitable AI opponents
    for (i = 0; i < ARRAY_COUNT(gContestOpponents); i++)
    {
        if (rank != gContestOpponents[i].whichRank)
            continue;

        if (isPostgame == TRUE)
        {
            if (gPostgameContestOpponentFilter[i] == CONTEST_FILTER_NO_POSTGAME)
                continue;
        }
        else
        {
            if (gPostgameContestOpponentFilter[i] == CONTEST_FILTER_ONLY_POSTGAME)
                continue;
        }
        if ((contestType == CONTEST_CATEGORY_COOL && gContestOpponents[i].aiPool_Cool)
            || (contestType == CONTEST_CATEGORY_BEAUTY && gContestOpponents[i].aiPool_Beauty)
            || (contestType == CONTEST_CATEGORY_CUTE && gContestOpponents[i].aiPool_Cute)
            || (contestType == CONTEST_CATEGORY_SMART && gContestOpponents[i].aiPool_Smart)
            || (contestType == CONTEST_CATEGORY_TOUGH && gContestOpponents[i].aiPool_Tough))
            opponents[opponentsCount++] = i;
    }
    opponents[opponentsCount] = 0xFF;

    // Fill remaining contestant slots with random AI opponents from the list
    for (i = 0; i < CONTESTANT_COUNT - gNumLinkContestPlayers; i++)
    {
        u16 rnd = GetContestRand() % opponentsCount;

        gContestMons[gNumLinkContestPlayers + i] = gContestOpponents[opponents[rnd]];
        StripPlayerNameForLinkContest(gContestMons[gNumLinkContestPlayers + i].trainerName);
        StripMonNameForLinkContest(gContestMons[gNumLinkContestPlayers + i].nickname, GAME_LANGUAGE);
        for (j = rnd; opponents[j] != 0xFF; j++)
            opponents[j] = opponents[j + 1];
        opponentsCount--;
    }
}

u8 GetContestEntryEligibility(struct Pokemon *pkmn)
{
    u8 ribbon;
    u8 eligibility;

    if (GetMonData(pkmn, MON_DATA_IS_EGG))
        return CANT_ENTER_CONTEST_EGG;
    if (GetMonData(pkmn, MON_DATA_HP) == 0)
        return CANT_ENTER_CONTEST_FAINTED;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        ribbon = GetMonData(pkmn, MON_DATA_COOL_RIBBON);
        break;
    case CONTEST_CATEGORY_BEAUTY:
        ribbon = GetMonData(pkmn, MON_DATA_BEAUTY_RIBBON);
        break;
    case CONTEST_CATEGORY_CUTE:
        ribbon = GetMonData(pkmn, MON_DATA_CUTE_RIBBON);
        break;
    case CONTEST_CATEGORY_SMART:
        ribbon = GetMonData(pkmn, MON_DATA_SMART_RIBBON);
        break;
    case CONTEST_CATEGORY_TOUGH:
        ribbon = GetMonData(pkmn, MON_DATA_TOUGH_RIBBON);
        break;
    default:
        return CANT_ENTER_CONTEST;
    }

    // Couldn't get this to match any other way.
    // Returns 2, 1, or 0 respectively if ribbon's rank is above, equal, or below
    // the current contest rank.
    if (ribbon > gSpecialVar_ContestRank)
        eligibility = CAN_ENTER_CONTEST_HIGH_RANK;
    else if (ribbon >= gSpecialVar_ContestRank)
        eligibility = CAN_ENTER_CONTEST_EQUAL_RANK;
    else
        eligibility = CANT_ENTER_CONTEST;
    return eligibility;
}

static void DrawContestantWindowText(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        FillWindowPixelBuffer(gContestantTurnOrder[i], PIXEL_FILL(0));
        PrintContestantTrainerName(i);
        PrintContestantMonName(i);
    }
}

static u8 *Contest_CopyStringWithColor(const u8 *string, u8 color)
{
    u8 * ptr = StringCopy(gDisplayedStringBattle, gText_ColorTransparent);
    ptr[-1] = color; // Overwrites the "{COLOR TRANSPARENT}" part of the string.
    ptr = StringCopy(ptr, string);

    return ptr;
}

static void PrintContestantTrainerName(u8 contestant)
{
    PrintContestantTrainerNameWithColor(contestant, contestant + CONTESTANT_TEXT_COLOR_START);
}

static void PrintContestantTrainerNameWithColor(u8 contestant, u8 color)
{
    u8 buffer[32];
    s32 offset;

    StringCopy(buffer, gText_Slash);
    StringAppend(buffer, gContestMons[contestant].trainerName);
    Contest_CopyStringWithColor(buffer, color);
    offset = GetStringRightAlignXOffset(7, gDisplayedStringBattle, 0x60);
    if (offset > 55)
        offset = 55;
    Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[contestant], gDisplayedStringBattle, offset, 1, 7);
}

static void PrintContestantMonName(u8 contestant)
{
    PrintContestantMonNameWithColor(contestant, contestant + CONTESTANT_TEXT_COLOR_START);
}

static void PrintContestantMonNameWithColor(u8 contestant, u8 color)
{
    Contest_CopyStringWithColor(gContestMons[contestant].nickname, color);
    Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[contestant], gDisplayedStringBattle, 5, 1, 7);
}

static u16 sub_80DAFE0(u8 who, u8 contestCategory)
{
    u8 statMain;
    u8 statSub1;
    u8 statSub2;

    switch (contestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        statMain = gContestMons[who].cool;
        statSub1 = gContestMons[who].tough;
        statSub2 = gContestMons[who].beauty;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        statMain = gContestMons[who].beauty;
        statSub1 = gContestMons[who].cool;
        statSub2 = gContestMons[who].cute;
        break;
    case CONTEST_CATEGORY_CUTE:
        statMain = gContestMons[who].cute;
        statSub1 = gContestMons[who].beauty;
        statSub2 = gContestMons[who].smart;
        break;
    case CONTEST_CATEGORY_SMART:
        statMain = gContestMons[who].smart;
        statSub1 = gContestMons[who].cute;
        statSub2 = gContestMons[who].tough;
        break;
    case CONTEST_CATEGORY_TOUGH:
    default:
        statMain = gContestMons[who].tough;
        statSub1 = gContestMons[who].smart;
        statSub2 = gContestMons[who].cool;
        break;
    }
    return statMain + (statSub1 + statSub2 + gContestMons[who].sheen) / 2;
}

void sub_80DB09C(u8 contestCategory)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        gContestMonRound1Points[i] = sub_80DAFE0(i, contestCategory);
}

static u8 sub_80DB0C4(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08587C00);
    LoadCompressedPalette(gContest2Pal, 0x110, 32);
    spriteId = CreateSprite(&gSpriteTemplate_8587BE8, 112, 36, 30);
    gSprites[spriteId].oam.paletteNum = 1;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    return spriteId;
}

static u8 sub_80DB120(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&sSpriteSheet_JudgeSymbols);
    LoadCompressedSpritePalette(&gUnknown_08587C10);
    spriteId = CreateSprite(&gSpriteTemplate_8587C18, 96, 10, 29);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].data[0] = gSprites[spriteId].oam.tileNum;
    return spriteId;
}

static u8 CreateContestantSprite(u16 species, u32 otId, u32 personality, u32 index)
{
    u8 spriteId;
    species = SanitizeSpecies(species);

    if (index == gContestPlayerMonIndex)
        HandleLoadSpecialPokePic_2(gMonBackPicTable + species, gMonSpritesGfxPtr->sprites[0], species, personality);
    else
        HandleLoadSpecialPokePic_DontHandleDeoxys(gMonBackPicTable + species, gMonSpritesGfxPtr->sprites[0], species, personality);

    LoadCompressedPalette(GetMonSpritePalFromSpeciesAndPersonality(species, otId, personality), 0x120, 0x20);
    SetMultiuseSpriteTemplateToPokemon(species, 0);

    spriteId = CreateSprite(&gMultiuseSpriteTemplate, 0x70, GetBattlerSpriteFinal_Y(2, species, FALSE), 30);
    gSprites[spriteId].oam.paletteNum = 2;
    gSprites[spriteId].oam.priority = 2;
    gSprites[spriteId].subpriority = GetBattlerSpriteSubpriority(2);
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].data[0] = gSprites[spriteId].oam.paletteNum;
    gSprites[spriteId].data[2] = species;
    if (IsSpeciesNotUnown(species))
        gSprites[spriteId].affineAnims = gUnknown_082FF6C0;
    else
        gSprites[spriteId].affineAnims = gUnknown_082FF694;
    StartSpriteAffineAnim(gSprites + spriteId, 0);

    return spriteId;
}

bool8 IsSpeciesNotUnown(u16 species)
{
    if (species == SPECIES_UNOWN)
        return FALSE;
    else
        return TRUE;
}

// The contestant info windows and general-purpose text box are drawn on one half, while
// the moves and move description windows are drawn on another screen. Only the first 32 * 20
// tiles are actually drawn on screen.
static void SwapMoveDescAndContestTilemaps(void)
{
    CpuCopy16(gContestResources->contestBgTilemaps[0], gContestResources->contestBgTilemaps[0] + 0x500, 32 * 20);
    CpuCopy16(gContestResources->contestBgTilemaps[2], gContestResources->contestBgTilemaps[2] + 0x500, 32 * 20);
}

static u16 sub_80DB2EC(u16 a0, u8 a1)
{
    u16 var;

    switch (gContestEffects[gContestMoves[a0].effect].effectType)
    {
    case 0:
    case 1:
    case 8:
        var = 0x9082;
        break;
    case 2:
    case 3:
        var = 0x9088;
        break;
    default:
        var = 0x9086;
        break;
    }
    var += 0x9000 + (a1 << 12);
    return var;
}

static void PrintContestMoveDescription(u16 a)
{
    u8 category;
    u16 categoryTile;
    u8 numHearts;

    // The contest category icon is implemented as a 5x2 group of tiles.
    category = gContestMoves[a].contestCategory;
    if      (category == CONTEST_CATEGORY_COOL)
        categoryTile = 0x4040;
    else if (category == CONTEST_CATEGORY_BEAUTY)
        categoryTile = 0x4045;
    else if (category == CONTEST_CATEGORY_CUTE)
        categoryTile = 0x404A;
    else if (category == CONTEST_CATEGORY_SMART)
        categoryTile = 0x406A;
    else
        categoryTile = 0x408A;

    ContestBG_FillBoxWithIncrementingTile(0, categoryTile,        0x0b, 0x1f, 0x05, 0x01, 0x11, 0x01);
    ContestBG_FillBoxWithIncrementingTile(0, categoryTile + 0x10, 0x0b, 0x20, 0x05, 0x01, 0x11, 0x01);

    if (gContestEffects[gContestMoves[a].effect].appeal == 0xFF)
        numHearts = 0;
    else
        numHearts = gContestEffects[gContestMoves[a].effect].appeal / 10;
    if (numHearts > 8)
        numHearts = 8;
    // Filled-in hearts
    ContestBG_FillBoxWithTile(0, 0x5035, 0x15, 0x1f, 0x08,      0x01, 0x11);
    // Empty hearts
    ContestBG_FillBoxWithTile(0, 0x5012, 0x15, 0x1f, numHearts, 0x01, 0x11);

    if (gContestEffects[gContestMoves[a].effect].jam == 0xFF)
        numHearts = 0;
    else
        numHearts = gContestEffects[gContestMoves[a].effect].jam / 10;
    if (numHearts > 8)
        numHearts = 8;
    // Filled-in hearts
    ContestBG_FillBoxWithTile(0, 0x5036, 0x15, 0x20, 0x08,      0x01, 0x11);
    // Empty hearts
    ContestBG_FillBoxWithTile(0, 0x5014, 0x15, 0x20, numHearts, 0x01, 0x11);

    FillWindowPixelBuffer(CONTEST_WINDOW_MOVE_DESCRIPTION, PIXEL_FILL(0));
    Contest_PrintTextToBg0WindowStd(CONTEST_WINDOW_MOVE_DESCRIPTION, gContestEffectDescriptionPointers[gContestMoves[a].effect]);
    Contest_PrintTextToBg0WindowStd(CONTEST_WINDOW_SLASH, gText_Slash);
}

static void sub_80DB4E0(u16 move, u8 b)
{
    u8 r7 = gContestantTurnOrder[b] * 5 + 2;

    if (!Contest_IsMonsTurnDisabled(b) && move != MOVE_NONE)
    {
        u16 tile = sub_80DB2EC(move, b);

        ContestBG_FillBoxWithIncrementingTile(0, tile,      20, r7,     2, 1, 17, 1);
        ContestBG_FillBoxWithIncrementingTile(0, tile + 16, 20, r7 + 1, 2, 1, 17, 1);
    }
    else
    {
        ContestBG_FillBoxWithTile(0, 0, 20, r7, 2, 2, 17);
    }
}

static void sub_80DB584(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        sub_80DB4E0(eContestantStatus[i].currMove, i);
}

static u16 sub_80DB5B0(void)
{
    return 0x2034;
}

static bool8 sub_80DB5B8(u8 contestantIdx, bool8 resetMod)
{
    u8 r6;
    s32 r4;

    if (eContestantStatus[contestantIdx].conditionMod == 0)
        return FALSE;
    r6 = gContestantTurnOrder[contestantIdx] * 5 + 2;
    r4 = eContestantStatus[contestantIdx].condition / 10;
    if (eContestantStatus[contestantIdx].conditionMod == 1)
    {
        ContestBG_FillBoxWithTile(0, sub_80DB5B0(), 19, r6, 1, r4, 17);
        if (resetMod)
        {
            PlaySE(SE_EXPMAX);
            eContestantStatus[contestantIdx].conditionMod = 0;
        }
    }
    else
    {
        ContestBG_FillBoxWithTile(0, 0, 19, r6 + r4, 1, 3 - r4, 17);
        if (resetMod)
        {
            PlaySE(SE_FU_ZAKU2);
            eContestantStatus[contestantIdx].conditionMod = 0;
        }
    }
    return TRUE;
}

static void sub_80DB69C(void)
{
    s32 i;
    s32 r6;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        u8 r4 = gContestantTurnOrder[i] * 5 + 2;
        u16 r5 = sub_80DB5B0();

        r6 = eContestantStatus[i].condition / 10;
        ContestBG_FillBoxWithTile(0, r5, 19, r4,      1, r6,     17);
        ContestBG_FillBoxWithTile(0,  0, 19, r4 + r6, 1, 3 - r6, 17);
    }
}

static u16 sub_80DB748(u8 status)
{
    u16 var = 0;

    switch (status)
    {
    case 0:
        var = 0x80;
        break;
    case 1:
        var = 0x84;
        break;
    case 2:
        var = 0x86;
        break;
    case 3:
        var = 0x88;
        break;
    case 4:
        var = 0x82;
        break;
    }
    var += 0x9000;
    return var;
}

static bool8 sub_80DB798(u8 a)
{
    bool8 r9 = TRUE;
    u16 r8 = 0;
    u8 r7 = gContestantTurnOrder[a] * 5 + 2;

    if (eContestantStatus[a].resistant || eContestantStatus[a].immune || eContestantStatus[a].jamSafetyCount != 0 || eContestantStatus[a].jamReduction != 0)
        r8 = sub_80DB748(0);
    else if (eContestantStatus[a].nervous)
        r8 = sub_80DB748(1);
    else if (eContestantStatus[a].numTurnsSkipped != 0 || eContestantStatus[a].noMoreTurns)
        r8 = sub_80DB748(2);
    else
        r9 = FALSE;
    if (r9)
    {
        ContestBG_FillBoxWithIncrementingTile(0, r8,      20, r7,     2, 1, 17, 1);
        ContestBG_FillBoxWithIncrementingTile(0, r8 + 16, 20, r7 + 1, 2, 1, 17, 1);
    }
    else
    {
        ContestBG_FillBoxWithTile(0, 0, 20, r7, 2, 2, 17);
    }
    return r9;
}

static void sub_80DB884(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        sub_80DB798(i);
}

static void ContestClearGeneralTextWindow(void)
{
    FillWindowPixelBuffer(CONTEST_WINDOW_GENERAL_TEXT, PIXEL_FILL(0));
    CopyWindowToVram(CONTEST_WINDOW_GENERAL_TEXT, 2);
    Contest_SetBgCopyFlags(0);
}

static u16 GetChosenMove(u8 contestant)
{
    if (Contest_IsMonsTurnDisabled(contestant))
        return MOVE_NONE;
    if (contestant == gContestPlayerMonIndex)
    {
        return gContestMons[contestant].moves[eContest.playerMoveChoice];
    }
    else
    {
        u8 moveChoice;

        ContestAI_ResetAI(contestant);
        moveChoice = ContestAI_GetActionToUse();
        return gContestMons[contestant].moves[moveChoice];
    }
}

static void GetAllChosenMoves(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        eContestantStatus[i].currMove = GetChosenMove(i);
}

static void RankContestants(void)
{
    s32 i;
    s32 j;
    s16 arr[CONTESTANT_COUNT];

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i].pointTotal += eContestantStatus[i].appeal2;
        arr[i] = eContestantStatus[i].pointTotal;
    }

    // Sort the point totals using bubble-sort.
    for (i = 0; i < 3; i++)
    {
        for (j = 3; j > i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                u16 temp = arr[j];

                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    // For each contestant, find the best rank with their point total.
    // Normally, each point total is different, and this will output the
    // rankings as expected. However, if two pokemon are tied, then they
    // both get the best rank for that point total.
    //
    // For example if the point totals are [100, 80, 80, 50], the ranks will
    // be [1, 2, 2, 4]. The pokemon with a point total of 80 stop looking
    // when they see the first 80 in the array, so they both share the '2'
    // rank.
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        for (j = 0; j < CONTESTANT_COUNT; j++)
        {
            if (eContestantStatus[i].pointTotal == arr[j])
            {
                eContestantStatus[i].ranking = j;
                break;
            }
        }
    }
    SortContestants(TRUE);
    ApplyNextTurnOrder();
}

static void SetAttentionLevels(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        u8 attentionLevel;

        if (eContestantStatus[i].currMove == MOVE_NONE)
            attentionLevel = 5;
        else if (eContestantStatus[i].appeal2 <= 0)
            attentionLevel = 0;
        else if (eContestantStatus[i].appeal2 < 30)
            attentionLevel = 1;
        else if (eContestantStatus[i].appeal2 < 60)
            attentionLevel = 2;
        else if (eContestantStatus[i].appeal2 < 80)
            attentionLevel = 3;
        else
            attentionLevel = 4;

        eContestantStatus[i].attentionLevel = attentionLevel;
    }
}

static bool8 ContestantCanUseTurn(u8 contestant)
{
    if (eContestantStatus[contestant].numTurnsSkipped != 0 || eContestantStatus[contestant].noMoreTurns)
        return FALSE;
    else
        return TRUE;
}

static void sub_80DBAA0(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i].appeal2 = 0;
        eContestantStatus[i].appeal1 = 0;
        eContestantStatus[i].jamSafetyCount = 0;
        if (eContestantStatus[i].numTurnsSkipped > 0)
            eContestantStatus[i].numTurnsSkipped--;
        eContestantStatus[i].jam = 0;
        eContestantStatus[i].resistant = 0;
        eContestantStatus[i].jamReduction = 0;
        eContestantStatus[i].immune = 0;
        eContestantStatus[i].moreEasilyStartled = 0;
        eContestantStatus[i].usedRepeatableMove = 0;
        eContestantStatus[i].nervous = FALSE;
        eContestantStatus[i].effectStringId = CONTEST_STRING_NONE;
        eContestantStatus[i].effectStringId2 = CONTEST_STRING_NONE;
        eContestantStatus[i].conditionMod = 0;
        eContestantStatus[i].repeatedPrevMove = eContestantStatus[i].repeatedMove;
        eContestantStatus[i].repeatedMove = FALSE;
        eContestantStatus[i].turnOrderModAction = 0;
        eContestantStatus[i].appealTripleCondition = 0;
        if (eContestantStatus[i].turnSkipped)
        {
            eContestantStatus[i].numTurnsSkipped = 1;
            eContestantStatus[i].turnSkipped = 0;
        }
        if (eContestantStatus[i].exploded)
        {
            eContestantStatus[i].noMoreTurns = TRUE;
            eContestantStatus[i].exploded = FALSE;
        }
        eContestantStatus[i].overrideCategoryExcitementMod = 0;
    }
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i].prevMove = eContestantStatus[i].currMove;
        eContest.moveHistory[eContest.appealNumber][i] = eContestantStatus[i].currMove;
        eContest.excitementHistory[eContest.appealNumber][i] = Contest_GetMoveExcitement(eContestantStatus[i].currMove);
        eContestantStatus[i].currMove = MOVE_NONE;
    }
    eContestResources10.excitementFrozen = 0;
}

bool8 Contest_IsMonsTurnDisabled(u8 contestant)
{
    if (eContestantStatus[contestant].numTurnsSkipped != 0 || eContestantStatus[contestant].noMoreTurns)
        return TRUE;
    else
        return FALSE;
}

static void CalculateTotalPointsForContestant(u8 contestant)
{
    gContestMonRound2Points[contestant] = GetContestantRound2Points(contestant);
    gContestMonTotalPoints[contestant] = gContestMonRound1Points[contestant] + gContestMonRound2Points[contestant];
}

static void CalculateFinalScores(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        CalculateTotalPointsForContestant(i);
    DetermineFinalStandings();
}

static s16 GetContestantRound2Points(u8 contestant)
{
    return gContestMonAppealPointTotals[contestant] * 2;
}

static void DetermineFinalStandings(void)
{
    u16 randomOrdering[CONTESTANT_COUNT] = {0};
    struct UnknownContestStruct6 sp8[CONTESTANT_COUNT];
    s32 i;
    s32 j;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        s32 r2;

        randomOrdering[i] = Random();
        for (r2 = 0; r2 < i; r2++)
        {
            if (randomOrdering[i] == randomOrdering[r2])
            {
                i--;
                break;
            }
        }
    }

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        sp8[i].unk0 = gContestMonTotalPoints[i];
        sp8[i].unk4 = gContestMonRound1Points[i];
        sp8[i].unk8 = randomOrdering[i];
        sp8[i].unkC = i;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 3; j > i; j--)
        {
            if (sub_80DBF30(j - 1, j, sp8))
            {
                struct UnknownContestStruct6 temp;

                temp.unk0 = sp8[j - 1].unk0;
                temp.unk4 = sp8[j - 1].unk4;
                temp.unk8 = sp8[j - 1].unk8;
                temp.unkC = sp8[j - 1].unkC;

                sp8[j - 1].unk0 = sp8[j].unk0;
                sp8[j - 1].unk4 = sp8[j].unk4;
                sp8[j - 1].unk8 = sp8[j].unk8;
                sp8[j - 1].unkC = sp8[j].unkC;

                sp8[j].unk0 = temp.unk0;
                sp8[j].unk4 = temp.unk4;
                sp8[j].unk8 = temp.unk8;
                sp8[j].unkC = temp.unkC;
            }
        }
    }

    for (i = 0; i < CONTESTANT_COUNT; i++)
        gContestFinalStandings[sp8[i].unkC] = i;
}

void SaveLinkContestResults(void)
{
    if ((gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
    {
        gSaveBlock2Ptr->contestLinkResults[gSpecialVar_ContestCategory][gContestFinalStandings[gContestPlayerMonIndex]] =
        ((gSaveBlock2Ptr->contestLinkResults[gSpecialVar_ContestCategory][gContestFinalStandings[gContestPlayerMonIndex]] + 1) > 9999) ? 9999 :
        (gSaveBlock2Ptr->contestLinkResults[gSpecialVar_ContestCategory][gContestFinalStandings[gContestPlayerMonIndex]] + 1);

    }
}

static bool8 sub_80DBF30(s32 a, s32 b, struct UnknownContestStruct6 *c)
{
    bool8 retVal;

    if (c[a].unk0 < c[b].unk0)
        retVal = TRUE;
    else if (c[a].unk0 > c[b].unk0)
        retVal = FALSE;
    else if (c[a].unk4 < c[b].unk4)
        retVal = TRUE;
    else if (c[a].unk4 > c[b].unk4)
        retVal = FALSE;
    else if (c[a].unk8 < c[b].unk8)
        retVal = TRUE;
    else
        retVal = FALSE;
    return retVal;
}

static void ContestPrintLinkStandby(void)
{
    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    ContestClearGeneralTextWindow();
    Contest_StartTextPrinter(gText_LinkStandby4, 0);
}

static void FillContestantWindowBgs(void)
{
    int i;

    for(i = 0; i < CONTESTANT_COUNT; i++)
    {
        ContestBG_FillBoxWithTile(0, 0, 0x16, 2 + i * 5, 8, 2, 0x11);
    }
}

static u16 sub_80DBFC8(u8 a)
{
    u16 var;

    if (a == 0)
        var = 0x5011;
    else if (a == 1)
        var = 0x6011;
    else if (a == 2)
        var = 0x7011;
    else
        var = 0x8011;
    return var + 1;
}

static s8 sub_80DBFFC(s16 a)
{
    s8 retVal = a / 10;

    if (retVal > 16)
        retVal = 16;
    else if (retVal < -16)
        retVal = -16;
    return retVal;
}

static u8 sub_80DC028(s16 a, s16 b, u8 c)
{
    u8 taskId;
    s8 r4;
    s8 r5;

    gContestResources->field_14[c].unk2_2 = 1;
    taskId = CreateTask(sub_80DC0F4, 20);
    r4 = sub_80DBFFC(a);
    r5 = sub_80DBFFC(a + b) - r4;
    sub_80DBFC8(c);  // unused return value
    gTasks[taskId].data[0] = abs(r4);
    gTasks[taskId].data[1] = r5;
    if (r4 > 0 || (r4 == 0 && r5 > 0))
        gTasks[taskId].data[2] = 1;
    else
        gTasks[taskId].data[2] = -1;
    gTasks[taskId].data[3] = c;
    return taskId;
}

static void sub_80DC0F4(u8 taskId)
{
    u8 r7 = gTasks[taskId].data[3];
    s16 r3 = gTasks[taskId].data[0];
    s16 r1 = gTasks[taskId].data[1];

    if (++gTasks[taskId].data[10] > 14)
    {
        u16 r6;
        u8 r5;
        u8 r10;
        u8 r11;

        gTasks[taskId].data[10] = 0;
        if (gTasks[taskId].data[1] == 0)
        {
            DestroyTask(taskId);
            gContestResources->field_14[r7].unk2_2 = 0;
            return;
        }
        else if (r3 == 0)
        {
            if (r1 < 0)
            {
                r6 = sub_80DBFC8(r7) + 2;
                gTasks[taskId].data[1]++;
            }
            else
            {
                r6 = sub_80DBFC8(r7);
                gTasks[taskId].data[1]--;
            }
            r5 = gTasks[taskId].data[0]++;
        }
        else
        {
            if (gTasks[taskId].data[2] < 0)
            {
                if (r1 < 0)
                {
                    r5 = gTasks[taskId].data[0]++;
                    gTasks[taskId].data[1]++;
                    r6 = sub_80DBFC8(r7) + 2;
                }
                else
                {
                    r5 = --gTasks[taskId].data[0];
                    r6 = 0;
                    gTasks[taskId].data[1]--;
                }
            }
            else
            {
                if (r1 < 0)
                {
                    r5 = --gTasks[taskId].data[0];
                    r6 = 0;
                    gTasks[taskId].data[1]++;
                }
                else
                {
                    r5 = gTasks[taskId].data[0]++;
                    gTasks[taskId].data[1]--;
                    r6 = sub_80DBFC8(r7);
                }
            }
        }
        r10 = r5;
        r11 = 0;

        if (r5 > 7)
        {
            r11 = 1;
            r5-= 8;
        }
        ContestBG_FillBoxWithTile(0, r6, r5 + 22, gContestantTurnOrder[r7] * 5 + 2 + r11,  1, 1, 17);
        if (r1 > 0)
        {
            PlaySE(SE_C_GAJI);
            m4aMPlayImmInit(&gMPlayInfo_SE1);
            m4aMPlayPitchControl(&gMPlayInfo_SE1, 0xFFFF, r10 * 256);
        }
        else
        {
            PlaySE(SE_BOO);
        }

        if (!r11 && !r5 && !r6)
            gTasks[taskId].data[2] = -gTasks[taskId].data[2];
    }
}

static void CreateSliderHeartSprites(void)
{
    s32 i;

    LoadSpriteSheet(&sSpriteSheet_SliderHeart);
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        u8 y = sSliderHeartYPositions[gContestantTurnOrder[i]];

        gContestResources->field_14[i].sliderHeartSpriteId = CreateSprite(&sSpriteTemplate_SliderHeart, 180, y, 1);
    }
}

#define sContestant data[0]
#define sTargetX    data[1]
#define sMoveX      data[2]

static void UpdateHeartSlider(u8 contestant)
{
    u8 spriteId;
    s16 slideTarget;

    gContestResources->field_14[contestant].sliderUpdating = TRUE;
    spriteId = gContestResources->field_14[contestant].sliderHeartSpriteId;
    slideTarget = eContestantStatus[contestant].pointTotal / 10 * 2;
    if (slideTarget > 56)
        slideTarget = 56;
    else if (slideTarget < 0)
        slideTarget = 0;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].sContestant = contestant;
    gSprites[spriteId].sTargetX = slideTarget;
    if (gSprites[spriteId].sTargetX > gSprites[spriteId].pos2.x)
        gSprites[spriteId].sMoveX = 1;
    else
        gSprites[spriteId].sMoveX = -1;
    gSprites[spriteId].callback = SpriteCB_UpdateHeartSlider;
}

static void UpdateHeartSliders(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        UpdateHeartSlider(i);
}

static bool8 SlidersDoneUpdating(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (gContestResources->field_14[i].sliderUpdating)
            break;
    }
    if (i == CONTESTANT_COUNT)
        return TRUE;
    else
        return FALSE;
}

static void SpriteCB_UpdateHeartSlider(struct Sprite *sprite)
{
    if (sprite->pos2.x == sprite->sTargetX)
    {
        gContestResources->field_14[sprite->sContestant].sliderUpdating = FALSE;
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        sprite->pos2.x += sprite->sMoveX;
    }
}

#undef sContestant
#undef sTargetX
#undef sMoveX

// Y positions change as the contestants change order
static void UpdateSliderHeartSpriteYPositions(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        gSprites[gContestResources->field_14[i].sliderHeartSpriteId].pos1.y = sSliderHeartYPositions[gContestantTurnOrder[i]];
}

// Used to hide (or subsequently reshow) the bottom two slider hearts that get hidden by text windows by moving them offscreen
static void SetBottomSliderHeartsInvisibility(bool8 invisible)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        // The contestants that go 3rd and 4th should be moved
        if (gContestantTurnOrder[i] > 1)
        {
            if (!invisible)
                gSprites[gContestResources->field_14[i].sliderHeartSpriteId].pos1.x = 180;
            else
                gSprites[gContestResources->field_14[i].sliderHeartSpriteId].pos1.x = 256;
        }
    }
}

static void CreateNextTurnSprites(void)
{
    s32 i;

    LoadSpritePalette(&sSpritePalette_NextTurn);
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        LoadCompressedSpriteSheet(&sSpriteSheet_NextTurn[i]);
        gContestResources->field_14[i].nextTurnSpriteId = CreateSprite(&sSpriteTemplates_NextTurn[i],
                                                           204,
                                                           sNextTurnSpriteYPositions[gContestantTurnOrder[i]],
                                                           0);
        SetSubspriteTables(&gSprites[gContestResources->field_14[i].nextTurnSpriteId], sSubspriteTable_NextTurn);
        gSprites[gContestResources->field_14[i].nextTurnSpriteId].invisible = TRUE;
    }
}

static void CreateApplauseMeterSprite(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&sApplauseMeterSpriteSheet);
    LoadSpritePalette(&sApplauseMeterPalette);
    spriteId = CreateSprite(&sApplauseMeterSpriteTemplate, 30, 44, 1);
    gSprites[spriteId].invisible = TRUE;
    eContest.applauseMeterSpriteId = spriteId;
}

static void sub_80DC5E8(void)
{
    u8 i;
    u8 taskId = CreateTask(sub_80DC728, 30);

    eContest.unk19211 = taskId;
    for (i = 0; i < CONTESTANT_COUNT; i++)
        gTasks[taskId].data[i * 4] = 0xFF;
}

static void sub_80DC630(u8 a)
{
    gTasks[eContest.unk19211].data[a * 4 + 0] = 0;
    gTasks[eContest.unk19211].data[a * 4 + 1] = 0;
}

static void sub_80DC674(u8 a)
{
    u8 taskId = CreateTask(sub_80DC6A4, 31);

    gTasks[taskId].data[0] = a;
}

static void sub_80DC6A4(u8 taskId)
{
    u8 r4 = gTasks[taskId].data[0];

    if (gTasks[eContest.unk19211].data[r4 * 4 + 0] == 0
     || gTasks[eContest.unk19211].data[r4 * 4 + 0] == 0xFF)
    {
        gTasks[eContest.unk19211].data[r4 * 4 + 0] = 0xFF;
        gTasks[eContest.unk19211].data[r4 * 4 + 1] = 0;
        BlendPalette((eContest.prevTurnOrder[r4] + MOVE_WINDOWS_START) * 16 + 6, 2, 0, RGB(31, 31, 18));
        DestroyTask(taskId);
    }
}

static void sub_80DC728(u8 taskId)
{
    u8 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        u8 r3 = i * 4;

        if (gTasks[taskId].data[r3 + 0] != 0xFF)
        {
            if (gTasks[taskId].data[r3 + 1] == 0)
                gTasks[taskId].data[r3 + 0]++;
            else
                gTasks[taskId].data[r3 + 0]--;

            if (gTasks[taskId].data[r3 + 0] == 16
             || gTasks[taskId].data[r3 + 0] == 0)
                gTasks[taskId].data[r3 + 1] ^= 1;

            BlendPalette(
              (eContest.prevTurnOrder[i] + MOVE_WINDOWS_START) * 16 + 6,
              2,
              gTasks[taskId].data[r3 + 0],
              RGB(31, 31, 18));
        }
    }
}

static void sub_80DC7EC(void)
{
    s32 i;

    eContest.unk19212 = CreateTask(sub_80DC8D0, 30);
    for (i = 0; i < CONTESTANT_COUNT; i++)
        sub_80DC81C(i);
}

static void sub_80DC81C(u8 contestant)
{
    gTasks[eContest.unk19212].data[contestant * 4 + 0] = 0xFF;
    gTasks[eContest.unk19212].data[contestant * 4 + 1] = 0;
}

static void sub_80DC864(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        sub_80DC87C(i);
}

static void sub_80DC87C(u8 contestant)
{
    u32 windowId1;
    u32 windowId2;

    sub_80DC81C(contestant);

    windowId1 = contestant + MOVE_WINDOWS_START;
    DmaCopy16Defvars(3,
                     gPlttBufferUnfaded + windowId1 * 16 + 10,
                     gPlttBufferFaded   + windowId1 * 16 + 10,
                     2);
    windowId2 = (contestant + MOVE_WINDOWS_START) * 16 + 12 + contestant;
    DmaCopy16Defvars(3,
                     gPlttBufferUnfaded + windowId2,
                     gPlttBufferFaded + windowId2,
                     2);
}

static void sub_80DC8D0(u8 taskId)
{
    u8 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        u8 r3 = i * 4;

        if (gTasks[taskId].data[r3 + 0] != 0xFF)
        {
            if (++gTasks[taskId].data[r3 + 2] > 2)
            {
                gTasks[taskId].data[r3 + 2] = 0;

                if (gTasks[taskId].data[r3 + 1] == 0)
                    gTasks[taskId].data[r3 + 0]++;
                else
                    gTasks[taskId].data[r3 + 0]--;

                if (gTasks[taskId].data[r3 + 0] == 16
                 || gTasks[taskId].data[r3 + 0] == 0)
                    gTasks[taskId].data[r3 + 1] ^= 1;

                BlendPalette((i + MOVE_WINDOWS_START) * 16 + 10, 1, gTasks[taskId].data[r3 + 0], RGB(31, 31, 18));
                BlendPalette((i + MOVE_WINDOWS_START) * 16 + 12 + i, 1, gTasks[taskId].data[r3 + 0], RGB(31, 31, 18));
            }
        }
    }
}

static void sub_80DC9B4(u8 contestant)
{
    if (eContestantStatus[contestant].hasJudgesAttention)
        sub_80DC630(contestant);
    else
        sub_80DC674(contestant);
}

static u8 sub_80DC9EC(u8 contestant)
{
    u8 spriteId1, spriteId2;
    u8 x = gContestantTurnOrder[contestant] * 40 + 32;

    LoadCompressedSpriteSheet(&sUnknown_08589904[contestant]);
    LoadSpritePalette(&sUnknown_08589924[contestant]);
    spriteId1 = CreateSprite(&gSpriteTemplate_858998C[contestant], 184, x, 29);
    spriteId2 = CreateSprite(&gSpriteTemplate_858998C[contestant], 248, x, 29);
    gSprites[spriteId2].oam.tileNum += 64;

    CopySpriteTiles(0,
                    3,
                    (void *)VRAM,
                    (u16 *)(BG_SCREEN_ADDR(28) + gContestantTurnOrder[contestant] * 5 * 64 + 0x26),
                    gContestResources->field_34);

    CopySpriteTiles(0,
                    3, (void *)VRAM,
                    (u16 *)(BG_SCREEN_ADDR(28) + gContestantTurnOrder[contestant] * 5 * 64 + 0x36),
                    gContestResources->field_38);

    CpuFill32(0, gContestResources->field_34 + 0x500, 0x300);
    CpuFill32(0, gContestResources->field_38 + 0x500, 0x300);

    RequestDma3Copy(gContestResources->field_34,
                    (u8 *)(VRAM + 0x10000 + gSprites[spriteId1].oam.tileNum * 32),
                    0x800,
                    1);

    RequestDma3Copy(gContestResources->field_38,
                    (u8 *)(VRAM + 0x10000 + gSprites[spriteId2].oam.tileNum * 32),
                    0x800,
                    1);

    gSprites[spriteId1].data[0] = spriteId2;
    gSprites[spriteId2].data[0] = spriteId1;

    gSprites[spriteId1].data[1] = contestant;
    gSprites[spriteId2].data[1] = contestant;

    return spriteId1;
}

static void sub_80DCB78(u8 spriteId)
{
    u8 spriteId2 = gSprites[spriteId].data[0];

    FreeSpriteOamMatrix(&gSprites[spriteId2]);
    DestroySprite(&gSprites[spriteId2]);
    DestroySpriteAndFreeResources(&gSprites[spriteId]);
}

static void sub_80DCBB4(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 9));
}

static void sub_80DCBD0(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
}

static void sub_80DCBE8(u8 a, bool8 b)
{
    u8 r5;

    sub_80DCBB4();
    gContestResources->field_14[gSprites[a].data[1]].unk2_1 = 1;
    r5 = gSprites[a].data[0];
    StartSpriteAffineAnim(&gSprites[a], 1);
    StartSpriteAffineAnim(&gSprites[r5], 1);
    gSprites[a].callback = sub_80DCC84;
    gSprites[r5].callback = SpriteCallbackDummy;
    if (b == FALSE)
        PlaySE(SE_C_PIKON);
    else
        PlaySE(SE_PC_LOGIN);
}

static void sub_80DCC84(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        u8 r1 = sprite->data[0];

        if (gSprites[r1].affineAnimEnded)
        {
            sprite->invisible = TRUE;
            gSprites[r1].invisible = TRUE;
            sprite->callback = sub_80DCCD8;
        }
    }
}

static void sub_80DCCD8(struct Sprite *sprite)
{
    gContestResources->field_14[sprite->data[1]].unk2_1 = 0;
    sub_80DCB78(sprite->data[0]);
    sub_80DCBD0();
}

// Unused.
static void ContestDebugTogglePointTotal(void)
{
    if(eContestDebugMode == CONTEST_DEBUG_MODE_PRINT_POINT_TOTAL)
        eContestDebugMode = CONTEST_DEBUG_MODE_OFF;
    else
        eContestDebugMode = CONTEST_DEBUG_MODE_PRINT_POINT_TOTAL;

    if(eContestDebugMode == CONTEST_DEBUG_MODE_OFF)
    {
        DrawContestantWindowText();
        SwapMoveDescAndContestTilemaps();
    }
    else
    {
        ContestDebugDoPrint();
    }
}

static void ContestDebugDoPrint(void)
{
    u8 i;
    s16 value;
    u8 *txtPtr;
    u8 text[8];

    if (!gEnableContestDebugging)
        return;

    switch (eContestDebugMode)
    {
    case CONTEST_DEBUG_MODE_OFF:
        break;
    case CONTEST_DEBUG_MODE_PRINT_UNK_C:
    case CONTEST_DEBUG_MODE_PRINT_UNK_D:
        ContestDebugPrintBitStrings();
        break;
    // The only other possible value is 1, which is only set by ContestDebugTogglePointTotal.
    //
    // case CONTEST_DEBUG_MODE_PRINT_POINT_TOTAL:
    default:
        for (i = 0; i < CONTESTANT_COUNT; i++)
            FillWindowPixelBuffer(i, PIXEL_FILL(0));
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            value = eContestantStatus[i].pointTotal;
            txtPtr = text;
            if (eContestantStatus[i].pointTotal < 0)
            {
                value *= -1;
                txtPtr = StringCopy(txtPtr, gText_OneDash);
            }
            ConvertIntToDecimalStringN(txtPtr, value, STR_CONV_MODE_LEFT_ALIGN, 4);
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text, 55, 1, 7);
        }
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            value = eContestantStatus[i].appeal2;
            txtPtr = text;
            if (eContestantStatus[i].appeal2 < 0)
            {
                value *= -1;
                txtPtr = StringCopy(txtPtr, gText_OneDash);
            }
            ConvertIntToDecimalStringN(txtPtr, value, STR_CONV_MODE_LEFT_ALIGN, 4);
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text, 5, 1, 7);
        }
        SwapMoveDescAndContestTilemaps();
        break;
    }
}

void SortContestants(bool8 useRanking)
{
    u8 scratch[CONTESTANT_COUNT];
    u16 randomOrdering[CONTESTANT_COUNT] = {0};
    s32 i;
    s32 v3;

    // Generate a unique random number for each contestant.
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        s32 j;
        randomOrdering[i] = Random();

        // Loop through all the numbers generated so far.
        for (j = 0; j < i; j++)
        {
            if (randomOrdering[i] == randomOrdering[j])
            {
                // This number isn't unique; try generating again.
                i--;
                break;
            }
        }
    }

    if (!useRanking)
    {
        // Order based on the results of the Conditions round using Insertion Sort.
        // Use the randomOrdering to break ties.
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            // Append this contestant to the list.
            gContestantTurnOrder[i] = i;

            // Determine where the contestant should be ordered.
            for (v3 = 0; v3 < i; v3++)
            {
                if (gContestMonRound1Points[gContestantTurnOrder[v3]] < gContestMonRound1Points[i]
                 || (gContestMonRound1Points[gContestantTurnOrder[v3]] == gContestMonRound1Points[i] && randomOrdering[gContestantTurnOrder[v3]] < randomOrdering[i]))
                {
                    // Shift everything larger up to make room.
                    s32 j;
                    for (j = i; j > v3; j--)
                        gContestantTurnOrder[j] = gContestantTurnOrder[j - 1];
                        
                    // Insert into the new spot.
                    gContestantTurnOrder[v3] = i;
                    break;
                }
            }

            // This is redundant.
            // Perhaps GF switched from true insertion sort to in-place insertion sort, and forgot to
            // remove this check?
            if (v3 == i)
                gContestantTurnOrder[i] = i;
        }

        // Invert gContestantTurnOrder; above, it was a list of contestant IDs. Now it's a list of turn orderings.
        // 
        // For example, if contestant 3 had the first turn, then `gContestantTurnOrder[1] = 3`. The turn is the index,
        // the contestant is the data. After inverting the list, `gContestantTurnOrder[3] = 1`. The contestant is the index,
        // and the turn is the data.
        memcpy(scratch, gContestantTurnOrder, sizeof(scratch));
        for (i = 0; i < CONTESTANT_COUNT; i++)
            gContestantTurnOrder[scratch[i]] = i;
    }
    else
    {
        // Order contestants based on their ranking.
        // If contestants have tied ranking, fill in the next available slot.
        //
        // Note that ranking is calculated so that shared places still take up a ranking
        // space. A ranking like [1, 2, 2, 3] is not possible; it would be [1, 2, 2, 4]
        // instead.
        memset(scratch, 0xFF, sizeof(scratch));
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            u8 j = eContestantStatus[i].ranking;

            while (1)
            {
                u8 *ptr = &scratch[j];
                if (*ptr == 0xFF)
                {
                    *ptr = i;
                    gContestantTurnOrder[i] = j;
                    break;
                }
                j++;
            }
        }

        // Randomize the order of contestants with tied rankings using Selection Sort.
        // 
        // Look through the array for tied ranks, and use randomOrdering to break the tie.
        // This ensures that contestants with the same rank will be randomly ordered. This
        // uses an in-place slection sort, which involves a lot of extra swapping.
        for (i = 0; i < CONTESTANT_COUNT - 1; i++)
        {
            for (v3 = CONTESTANT_COUNT - 1; v3 > i; v3--)
            {
                if (eContestantStatus[v3 - 1].ranking == eContestantStatus[v3].ranking
                 && gContestantTurnOrder[v3 - 1] < gContestantTurnOrder[v3]
                 && randomOrdering[v3 - 1] < randomOrdering[v3])
                {
                    u8 temp = gContestantTurnOrder[v3];
                    gContestantTurnOrder[v3] = gContestantTurnOrder[v3 - 1];
                    gContestantTurnOrder[v3 - 1] = temp;
                }
            }
        }
    }
}

static void DrawContestantWindows(void)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        s32 windowId = i + MOVE_WINDOWS_START;
        LoadPalette(eUnknownHeap1A004.cachedWindowPalettes[windowId], (gContestantTurnOrder[i] + MOVE_WINDOWS_START) * 16, sizeof(eUnknownHeap1A004.cachedWindowPalettes[0]));
    }
    DrawContestantWindowText();
}

static void sub_80DD080(u8 contestant)
{
    u16 move;
    u8 effect;
    u8 rnd;
    bool8 r8;
    s32 i;

    eContestantStatus[contestant].appeal2 = 0;
    eContestantStatus[contestant].appeal1 = 0;
    r8 = ContestantCanUseTurn(contestant);
    if (!r8)
        return;

    move = eContestantStatus[contestant].currMove;
    effect = gContestMoves[move].effect;

    eContestantStatus[contestant].moveCategory = gContestMoves[eContestantStatus[contestant].currMove].contestCategory;
    if (eContestantStatus[contestant].currMove == eContestantStatus[contestant].prevMove && eContestantStatus[contestant].currMove != MOVE_NONE)
    {
        eContestantStatus[contestant].repeatedMove = TRUE;
        eContestantStatus[contestant].moveRepeatCount++;
    }
    else
    {
        eContestantStatus[contestant].moveRepeatCount = 0;
    }
    eContestantStatus[contestant].appeal1 = gContestEffects[effect].appeal;
    eContestantStatus[contestant].appeal2 = eContestantStatus[contestant].appeal1;
    eContestResources8.jam = gContestEffects[effect].jam;
    eContestResources8.jam2 = eContestResources8.jam;

    eContestResources8.contestant = contestant;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestantStatus[i].jam = 0;
        eContestResources8.unnervedPokes[i] = 0;
    }

    if (eContestantStatus[contestant].hasJudgesAttention
        && !AreMovesContestCombo(eContestantStatus[contestant].prevMove, eContestantStatus[contestant].currMove))
        eContestantStatus[contestant].hasJudgesAttention = 0;

    gContestEffectFuncs[effect]();

    if (eContestantStatus[contestant].conditionMod == 1)
        eContestantStatus[contestant].appeal2 += eContestantStatus[contestant].condition - 10;
    else if (eContestantStatus[contestant].appealTripleCondition)
        eContestantStatus[contestant].appeal2 += eContestantStatus[contestant].condition * 3;
    else
        eContestantStatus[contestant].appeal2 += eContestantStatus[contestant].condition;

    eContestantStatus[contestant].unk16 = 0;
    eContestantStatus[contestant].unk15_6 = FALSE;
    if (sub_80DE1E8(contestant))
    {
        bool8 usedCombo = AreMovesContestCombo(eContestantStatus[contestant].prevMove, eContestantStatus[contestant].currMove);

        if (usedCombo && eContestantStatus[contestant].hasJudgesAttention)
        {
            eContestantStatus[contestant].unk16 = usedCombo;
            eContestantStatus[contestant].unk15_6 = TRUE;
            eContestantStatus[contestant].hasJudgesAttention = 0;
            eContestantStatus[contestant].unk17 = eContestantStatus[contestant].appeal1 * eContestantStatus[contestant].unk16;
            eContestantStatus[contestant].unk15_3 = TRUE;
        }
        else
        {
            if (gContestMoves[eContestantStatus[contestant].currMove].comboStarterId != 0)
            {
                eContestantStatus[contestant].hasJudgesAttention = 1;
                eContestantStatus[contestant].unk15_6 = TRUE;
            }
            else
            {
                eContestantStatus[contestant].hasJudgesAttention = 0;
            }
        }
    }
    if (eContestantStatus[contestant].repeatedMove)
        eContestantStatus[contestant].unk18 = (eContestantStatus[contestant].moveRepeatCount + 1) * 10;

    if (eContestantStatus[contestant].nervous)
    {
        eContestantStatus[contestant].hasJudgesAttention = 0;
        eContestantStatus[contestant].appeal2 = 0;
        eContestantStatus[contestant].appeal1 = 0;
    }
    eContestResources10.bits_0 = Contest_GetMoveExcitement(eContestantStatus[contestant].currMove);
    if (eContestantStatus[contestant].overrideCategoryExcitementMod)
        eContestResources10.bits_0 = 1;

    if (eContestResources10.bits_0 > 0)
    {
        if (eContest.applauseLevel + eContestResources10.bits_0 > 4)
            eContestResources10.unk2 = 60;
        else
            eContestResources10.unk2 = 10;
    }
    else
    {
        eContestResources10.unk2 = 0;
    }

    rnd = Random() % (CONTESTANT_COUNT - 1);
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (i != contestant)
        {
            if (rnd == 0)
                break;
            rnd--;
        }
    }
    eContestantStatus[contestant].unk1B = i;
}

void SetContestantEffectStringID(u8 a, u8 b)
{
    eContestantStatus[a].effectStringId = b;
}

void SetContestantEffectStringID2(u8 a, u8 b)
{
    eContestantStatus[a].effectStringId2 = b;
}

void SetStartledString(u8 contestant, u8 jam)
{
    if      (jam >= 60)
        SetContestantEffectStringID(contestant, CONTEST_STRING_TRIPPED_OVER);
    else if (jam >= 40)
        SetContestantEffectStringID(contestant, CONTEST_STRING_LEAPT_UP);
    else if (jam >= 30)
        SetContestantEffectStringID(contestant, CONTEST_STRING_UTTER_CRY);
    else if (jam >= 20)
        SetContestantEffectStringID(contestant, CONTEST_STRING_TURNED_BACK);
    else if (jam >= 10)
        SetContestantEffectStringID(contestant, CONTEST_STRING_LOOKED_DOWN);
}

static void sub_80DD45C(u8 contestant, u8 stringId)
{
    StringCopy(gStringVar1, gContestMons[contestant].nickname);
    StringCopy(gStringVar2, gMoveNames[eContestantStatus[contestant].currMove]);
    if      (gContestMoves[eContestantStatus[eContestResources8.contestant].currMove].contestCategory == CONTEST_CATEGORY_COOL)
        StringCopy(gStringVar3, gText_Contest_Shyness);
    else if (gContestMoves[eContestantStatus[eContestResources8.contestant].currMove].contestCategory == CONTEST_CATEGORY_BEAUTY)
        StringCopy(gStringVar3, gText_Contest_Anxiety);
    else if (gContestMoves[eContestantStatus[eContestResources8.contestant].currMove].contestCategory == CONTEST_CATEGORY_CUTE)
        StringCopy(gStringVar3, gText_Contest_Laziness);
    else if (gContestMoves[eContestantStatus[eContestResources8.contestant].currMove].contestCategory == CONTEST_CATEGORY_SMART)
        StringCopy(gStringVar3, gText_Contest_Hesitancy);
    else
        StringCopy(gStringVar3, gText_Contest_Fear);
    StringExpandPlaceholders(gStringVar4, sAppealResultTexts[stringId]);
    ContestClearGeneralTextWindow();
    Contest_StartTextPrinter(gStringVar4, 1);
}

void MakeContestantNervous(u8 p)
{
    eContestantStatus[p].nervous = TRUE;
    eContestantStatus[p].currMove = MOVE_NONE;
}

// This function calculates the new turn order for the next round. The
// algorithm first checks for explicit turn assignments in the
// ContestantStatus::nextTurnOrder field of each contestant. The remaining
// turns are assigned such that the turn order will reverse.
//
// For example, if no pokemon have a defined nextTurnOrder, then the 4th
// will become 1st, the 3rd will become 2nd, etc.
//
// Note: This function assumes that multiple pokemon cannot have the same
// nextTurnOrder value.
static void ApplyNextTurnOrder(void)
{
    u8 nextContestant = 0;
    s32 i;
    s32 j;
    u8 newTurnOrder[CONTESTANT_COUNT];
    bool8 isContestantOrdered[CONTESTANT_COUNT];

    // Copy the current turn order.
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        newTurnOrder[i] = gContestantTurnOrder[i];
        isContestantOrdered[i] = FALSE;
    }

    // For each turn, assign a contestant to that turn.
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        // Look for explicit turn assignments.
        for (j = 0; j < CONTESTANT_COUNT; j++)
        {
            if (eContestantStatus[j].nextTurnOrder == i)
            {
                newTurnOrder[j] = i;
                isContestantOrdered[j] = TRUE;
                break;
            }
        }

        if (j == CONTESTANT_COUNT)
        {
            // No contestant was assigned to this turn. Look for the unassigned contestant
            // with the highest turn order.
            //
            // First, look for the first unassigned contestant.
            for (j = 0; j < CONTESTANT_COUNT; j++)
            {
                if (!isContestantOrdered[j] && eContestantStatus[j].nextTurnOrder == 0xFF)
                {
                    nextContestant = j;
                    j++;
                    break;
                }
            }

            // Then, look for a better candidate, with a higher turn order.
            for (; j < CONTESTANT_COUNT; j++)
            {
                if (!isContestantOrdered[j] && eContestantStatus[j].nextTurnOrder == 0xFF
                 && gContestantTurnOrder[nextContestant] > gContestantTurnOrder[j])
                    nextContestant = j;
            }

            // Assign the contestant to this turn.
            newTurnOrder[nextContestant] = i;
            isContestantOrdered[nextContestant] = TRUE;
        }
    }

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        eContestResources8.turnOrder[i] = newTurnOrder[i];
        eContestantStatus[i].nextTurnOrder = 0xFF;
        eContestantStatus[i].turnOrderMod = 0;
        gContestantTurnOrder[i] = newTurnOrder[i];
    }
}

static void sub_80DD6DC(struct Sprite *sprite)
{
    if (sprite->data[1]++ > 84)
    {
        sprite->data[1] = 0;
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
        eContest.unk1920A_4 = 0;
    }
}

static void sub_80DD720(u8 a)
{
    u8 spriteId = eContest.unk19216;

    switch (a)
    {
    case 0:
    case 1:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0];
        PlaySE(SE_HAZURE);
        break;
    case 2:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 4;
        PlaySE(SE_SEIKAI);
        break;
    case 3:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 8;
        PlaySE(SE_SEIKAI);
        break;
    case 4:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 12;
        PlaySE(SE_TK_WARPIN);
        break;
    case 5:  // exactly the same as case 4
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 12;
        PlaySE(SE_TK_WARPIN);
        break;
    case 6:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 16;
        PlaySE(SE_TK_WARPIN);
        break;
    case 8:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 24;
        PlaySE(SE_W215);
        break;
    case 7:
    default:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 20;
        PlaySE(SE_TK_WARPIN);
        break;
    }
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].callback = sub_80DD6DC;
    eContest.unk1920A_4 = 1;
}

static void UpdateApplauseMeter(void)
{
    s32 i;

    for (i = 0; i < APPLAUSE_METER_SIZE; i++)
    {
        const u8 *src;

        if (i < eContest.applauseLevel)
            src = &gContestApplauseMeterGfx[64];
        else
            src = gContestApplauseMeterGfx;
        CpuCopy32(src, (void *)(VRAM + 0x10000 + (gSprites[eContest.applauseMeterSpriteId].oam.tileNum + 17 + i) * 32), 32);
        CpuCopy32(src + 32, (void *)(VRAM + 0x10000 + (gSprites[eContest.applauseMeterSpriteId].oam.tileNum + 25 + i) * 32), 32);

        if (eContest.applauseLevel > 4)
            StartApplauseOverflowAnimation();
    }
}

s8 Contest_GetMoveExcitement(u16 move)
{
    return gContestExcitementTable[gSpecialVar_ContestCategory][gContestMoves[move].contestCategory];
}

static u8 StartApplauseOverflowAnimation(void)
{
    u8 taskId = CreateTask(Task_ApplauseOverflowAnimation, 10);

    gTasks[taskId].data[1] = 1;
    gTasks[taskId].data[2] = IndexOfSpritePaletteTag(TAG_APPLAUSE_METER);
    return taskId;
}

static void Task_ApplauseOverflowAnimation(u8 taskId)
{
    // Skip every other frame.
    if (++gTasks[taskId].data[0] == 1)
    {
        gTasks[taskId].data[0] = 0;
        
        // Alternate between normal colors and white.
        if (gTasks[taskId].data[3] == 0)
            gTasks[taskId].data[4]++;
        else
            gTasks[taskId].data[4]--;
        
        BlendPalette(264 + gTasks[taskId].data[2] * 16, 1, gTasks[taskId].data[4], RGB_WHITE);

        // At the maximum or minimum blending, switch directions.
        if (gTasks[taskId].data[4] == 0 || gTasks[taskId].data[4] == 16)
        {
            gTasks[taskId].data[3] ^= 1;

            // Continue the animation until the applause meter is cleared.
            if (eContest.applauseLevel < 5)
            {
                BlendPalette(264 + gTasks[taskId].data[2] * 16, 1, 0, RGB_RED);
                DestroyTask(taskId);
            }
        }
    }
}

static void StartMoveApplauseMeterOnscreen(void)
{
    CreateTask(Task_MoveApplauseMeterOnscreen, 10);
    gSprites[eContest.applauseMeterSpriteId].pos2.x = -70;
    gSprites[eContest.applauseMeterSpriteId].invisible = FALSE;
    eContest.applauseMeterIsMoving = TRUE;
}

static void Task_MoveApplauseMeterOnscreen(u8 taskId)
{
    struct Sprite *sprite = &gSprites[eContest.applauseMeterSpriteId];

    gTasks[taskId].data[10] += 1664;
    sprite->pos2.x += gTasks[taskId].data[10] >> 8;
    gTasks[taskId].data[10] = gTasks[taskId].data[10] & 0xFF;
    if (sprite->pos2.x > 0)
        sprite->pos2.x = 0;
    if (sprite->pos2.x == 0)
    {
        eContest.applauseMeterIsMoving = FALSE;
        DestroyTask(taskId);
    }
}

static void TryMoveApplauseMeterOffscreen(void)
{
    if (gSprites[eContest.applauseMeterSpriteId].invisible == TRUE)
    {
        eContest.applauseMeterIsMoving = FALSE;
    }
    else
    {
        CreateTask(Task_MoveApplauseMeterOffscreen, 10);
        gSprites[eContest.applauseMeterSpriteId].pos2.x = 0;
        eContest.applauseMeterIsMoving = TRUE;
    }
}

static void Task_MoveApplauseMeterOffscreen(u8 taskId)
{
    struct Sprite *sprite = &gSprites[eContest.applauseMeterSpriteId];

    gTasks[taskId].data[10] += 1664;
    sprite->pos2.x -= gTasks[taskId].data[10] >> 8;
    gTasks[taskId].data[10] = gTasks[taskId].data[10] & 0xFF;
    if (sprite->pos2.x < -70)
        sprite->pos2.x = -70;
    if (sprite->pos2.x == -70)
    {
        sprite->invisible = TRUE;
        eContest.applauseMeterIsMoving = FALSE;
        DestroyTask(taskId);
    }
}

static void ShowAndUpdateApplauseMeter(s8 unused)
{
    u8 taskId = CreateTask(Task_ShowAndUpdateApplauseMeter, 5);

    gTasks[taskId].data[0] = unused;
    eContest.isShowingApplauseMeter = TRUE;
}

static void Task_ShowAndUpdateApplauseMeter(u8 taskId)
{
    switch (gTasks[taskId].data[10])
    {
    case 0:
        StartMoveApplauseMeterOnscreen();
        gTasks[taskId].data[10]++;
        break;
    case 1:
        if (!eContest.applauseMeterIsMoving)
        {
            gTasks[taskId].data[10]++;
        }
        break;
    case 2:
        if (gTasks[taskId].data[11]++ > 20)
        {
            gTasks[taskId].data[11] = 0;
            UpdateApplauseMeter();
            eContest.isShowingApplauseMeter = FALSE;
            DestroyTask(taskId);
        }
        break;
    }
}

// Unused.
static void HideApplauseMeterNoAnim(void)
{
    gSprites[eContest.applauseMeterSpriteId].pos2.x = 0;
    gSprites[eContest.applauseMeterSpriteId].invisible = FALSE;
}

// Unused.
static void ShowApplauseMeterNoAnim(void)
{
    gSprites[eContest.applauseMeterSpriteId].invisible = TRUE;
}

static void sub_80DDE0C(void)
{
    CreateTask(sub_80DDE30, 15);
    eContest.unk1920A_7 = 1;
}

static void sub_80DDE30(u8 taskId)
{
    if (gTasks[taskId].data[10]++ > 6)
    {
        gTasks[taskId].data[10] = 0;
        if (gTasks[taskId].data[11] == 0)
        {
            RequestDma3Copy(eUnknownHeap19000, (void *)(BG_SCREEN_ADDR(4)), 0x1000, 1);
        }
        else
        {
            RequestDma3Copy(eUnzippedContestAudienceGfx, (void *)(BG_SCREEN_ADDR(4)), 0x1000, 1);
            gTasks[taskId].data[12]++;
        }

        gTasks[taskId].data[11] ^= 1;

        if (gTasks[taskId].data[12] == 9)
        {
            eContest.unk1920A_7 = 0;
            DestroyTask(taskId);
        }
    }
}

#define tBlendColor data[0]
#define tBlendCoeff data[1]

static void sub_80DDED0(s8 a, s8 b)
{
    u8 taskId = CreateTask(sub_80DDF80, 10);
    u16 blendColor;
    u8 blendCoeff;
    u8 r3;

    if (a > 0)
    {
        blendColor = RGB(30, 27, 8);
        if (b > 0)
        {
            blendCoeff = 0;
            r3 = eContest.applauseLevel * 3;
        }
        else
        {
            blendCoeff = eContest.applauseLevel * 3;
            r3 = 0;
        }
    }
    else
    {
        blendColor = 0;
        if (b > 0)
        {
            blendCoeff = 0;
            r3 = 12;
        }
        else
        {
            blendCoeff = 12;
            r3 = 0;
        }
    }
    gTasks[taskId].tBlendColor = blendColor;
    gTasks[taskId].tBlendCoeff = blendCoeff;
    gTasks[taskId].data[2] = b;
    gTasks[taskId].data[3] = r3;
    eContest.unk1920B_0 = 0;
}

static void sub_80DDF80(u8 taskId)
{
    if (gTasks[taskId].data[10]++ >= 0)
    {
        gTasks[taskId].data[10] = 0;
        if (gTasks[taskId].data[2] > 0)
            gTasks[taskId].tBlendCoeff++;
        else
            gTasks[taskId].tBlendCoeff--;
        BlendPalette(17, 1, gTasks[taskId].tBlendCoeff, gTasks[taskId].tBlendColor);
        BlendPalette(26, 1, gTasks[taskId].tBlendCoeff, gTasks[taskId].tBlendColor);
        if (gTasks[taskId].tBlendCoeff == gTasks[taskId].data[3])
        {
            DestroyTask(taskId);
            eContest.unk1920B_0 = 0;
        }
    }
}

#undef tBlendColor
#undef tBlendCoeff

static void sub_80DE008(bool8 a)
{
    s32 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (eContestantStatus[i].turnOrderMod != 0 && a)
        {
            CpuCopy32(GetTurnOrderNumberGfx(i), (void *)(VRAM + 0x10000 + (gSprites[gContestResources->field_14[i].nextTurnSpriteId].oam.tileNum + 6) * 32), 32);
            gSprites[gContestResources->field_14[i].nextTurnSpriteId].pos1.y = sNextTurnSpriteYPositions[gContestantTurnOrder[i]];
            gSprites[gContestResources->field_14[i].nextTurnSpriteId].invisible = FALSE;
        }
        else
        {
            gSprites[gContestResources->field_14[i].nextTurnSpriteId].invisible = TRUE;
        }
    }
}

static const u8 *GetTurnOrderNumberGfx(u8 contestant)
{
    if (eContestantStatus[contestant].turnOrderMod != 1)
        return gContestNextTurnRandomGfx;
    else
        return gContestNextTurnNumbersGfx + eContestantStatus[contestant].nextTurnOrder * 32;
}

static void sub_80DE12C(void)
{
    s32 i = 0;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (eContestResources8.unnervedPokes[i] != 0 && !Contest_IsMonsTurnDisabled(i))
        {
            u32 r6 = gContestantTurnOrder[i] * 5 + 2;
            u16 var = sub_80DB748(3);

            ContestBG_FillBoxWithIncrementingTile(0, var, 20, r6, 2, 1, 17, 1);
            var += 16;
            ContestBG_FillBoxWithIncrementingTile(0, var, 20, r6 + 1, 2, 1, 17, 1);
            PlaySE(SE_C_PASI);
        }
    }
}

bool8 sub_80DE1E8(u8 contestant)
{
    if (eContestantStatus[contestant].repeatedMove || eContestantStatus[contestant].nervous)
        return FALSE;
    else
        return TRUE;
}

static void sub_80DE224(void)
{
    s32 i;
    u16 bg0Cnt, bg1Cnt, bg2Cnt;

    bg1Cnt = GetGpuReg(REG_OFFSET_BG1CNT);
    ((vBgCnt *)&bg1Cnt)->priority = 0;
    ((vBgCnt *)&bg1Cnt)->screenSize = 2;
    ((vBgCnt *)&bg1Cnt)->areaOverflowMode = 0;
    ((vBgCnt *)&bg1Cnt)->charBaseBlock = 0;

    SetGpuReg(REG_OFFSET_BG1CNT, bg1Cnt);

    bg0Cnt = GetGpuReg(REG_OFFSET_BG0CNT);
    bg2Cnt = GetGpuReg(REG_OFFSET_BG2CNT);
    ((vBgCnt *)&bg0Cnt)->priority = 1;
    ((vBgCnt *)&bg2Cnt)->priority = 1;

    SetGpuReg(REG_OFFSET_BG0CNT, bg0Cnt);
    SetGpuReg(REG_OFFSET_BG2CNT, bg2Cnt);

    gBattle_BG1_X = DISPLAY_WIDTH;
    gBattle_BG1_Y = DISPLAY_HEIGHT;
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

    CpuFill32(0, gContestResources->contestBgTilemaps[1], 0x1000);

    CopyToBgTilemapBuffer(1, gUnknown_08C17980, 0, 0);
    Contest_SetBgCopyFlags(1);

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        gSprites[gContestResources->field_14[i].sliderHeartSpriteId].oam.priority = 1;
        gSprites[gContestResources->field_14[i].nextTurnSpriteId].oam.priority = 1;
    }
}

static void sub_80DE350(void)
{
    s32 i;
    u16 bg1Cnt;

    RequestDma3Fill(0,(void *)(BG_CHAR_ADDR(2)), 0x2000, 1);
    CpuFill32(0, gContestResources->contestBgTilemaps[1], 0x1000);
    Contest_SetBgCopyFlags(1);
    bg1Cnt = GetGpuReg(REG_OFFSET_BG1CNT);
    ((vBgCnt *) &bg1Cnt)->priority = 1;
    ((vBgCnt *) &bg1Cnt)->screenSize = 0;
    ((vBgCnt *) &bg1Cnt)->areaOverflowMode = 0;
    ((vBgCnt *) &bg1Cnt)->charBaseBlock = 2;

    SetGpuReg(REG_OFFSET_BG1CNT, bg1Cnt);

    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        gSprites[gContestResources->field_14[i].sliderHeartSpriteId].oam.priority = 0;
        gSprites[gContestResources->field_14[i].nextTurnSpriteId].oam.priority = 0;
    }
}

static void sub_80DE424(u8 taskId)
{
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = DISPLAY_HEIGHT;
    PlaySE12WithPanning(SE_C_MAKU_D, 0);
    gTasks[taskId].func = sub_80DE464;
}

static void sub_80DE464(u8 taskId)
{
    if ((s16)(gBattle_BG1_Y -= 7) < 0)
        gBattle_BG1_Y = 0;
    if (gBattle_BG1_Y == 0)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_80DE4A8;
    }
}

static void sub_80DE4A8(u8 taskId)
{
    s32 i;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        for (i = 0; i < CONTESTANT_COUNT; i++)
            eContest.prevTurnOrder[i] = gContestantTurnOrder[i];
        FillContestantWindowBgs();
        sub_80DC864();
        sub_80DB69C();
        DrawContestantWindows();
        sub_80DE008(TRUE);
        UpdateSliderHeartSpriteYPositions();
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            u8 taskId2;

            eContest.unk1920B_2 = 1;
            if (sub_80DA8A4())
                sub_80DBAA0();
            taskId2 = CreateTask(sub_80FCC88, 0);
            SetTaskFuncWithFollowupFunc(taskId2, sub_80FCC88, sub_80DA110);
            ContestPrintLinkStandby();
            gTasks[taskId].data[0] = 2;
        }
        else
        {
            sub_80DBAA0();
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 2:
        if (!eContest.unk1920B_2)
            gTasks[taskId].data[0] = 3;
        break;
    case 3:
        sub_80DB884();
        SwapMoveDescAndContestTilemaps();
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DE5F4;
        break;
    }
}

static void sub_80DE5C0(u8 taskId)
{
    if ((s16)(gBattle_BG1_Y += 7) > DISPLAY_HEIGHT)
        gTasks[taskId].func = sub_80DA4F4;
}

static void sub_80DE5F4(u8 taskId)
{
    if (gTasks[taskId].data[2] < 10)
    {
        gTasks[taskId].data[2]++;
    }
    else
    {
        if (gTasks[taskId].data[1] == 0)
        {
            if (gTasks[taskId].data[0] == 16)
                gTasks[taskId].data[1]++;
            else
                gTasks[taskId].data[0]++;
        }
        else
        {
            if (gTasks[taskId].data[0] == 0)
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[2] = 0;
                gTasks[taskId].func = sub_80DE65C;
            }
            else
            {
                gTasks[taskId].data[0]--;
            }
        }
    }
}

static void sub_80DE65C(u8 taskId)
{
    if (gTasks[taskId].data[2] < 10)
    {
        gTasks[taskId].data[2]++;
    }
    else
    {
        gTasks[taskId].data[2] = 0;
        PlaySE12WithPanning(SE_C_MAKU_U, 0);
        gTasks[taskId].func = sub_80DE5C0;
    }
}

#define tAnimId data[0]

static void AnimateSliderHearts(u8 animId)
{
    s32 i;
    u8 taskId;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        gSprites[gContestResources->field_14[i].sliderHeartSpriteId].oam.matrixNum = AllocOamMatrix();
        gSprites[gContestResources->field_14[i].sliderHeartSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        StartSpriteAffineAnim(&gSprites[gContestResources->field_14[i].sliderHeartSpriteId], animId);
        if (animId == SLIDER_HEART_ANIM_APPEAR)
        {
            AnimateSprite(&gSprites[gContestResources->field_14[i].sliderHeartSpriteId]);
            gSprites[gContestResources->field_14[i].sliderHeartSpriteId].invisible = FALSE;
        }
    }
    taskId = CreateTask(Task_WaitForSliderHeartAnim, 5);
    gTasks[taskId].tAnimId = animId;
    eContest.sliderHeartsAnimating = TRUE;
}

static void Task_WaitForSliderHeartAnim(u8 taskId)
{
    s32 i;

    if (gSprites[gContestResources->field_14[0].sliderHeartSpriteId].affineAnimEnded)
    {
        if ((u8)gTasks[taskId].tAnimId == SLIDER_HEART_ANIM_DISAPPEAR)
        {
            for (i = 0; i < CONTESTANT_COUNT; i++)
                gSprites[gContestResources->field_14[i].sliderHeartSpriteId].invisible = TRUE;
        }
        for (i = 0; i < CONTESTANT_COUNT; i++)
            FreeSpriteOamMatrix(&gSprites[gContestResources->field_14[i].sliderHeartSpriteId]);
        eContest.sliderHeartsAnimating = FALSE;
        DestroyTask(taskId);
    }
}

#undef tAnimId

static u16 SanitizeMove(u16 move)
{
    if (move >= MOVES_COUNT)
        move = MOVE_POUND;
    return move;
}

static u16 SanitizeSpecies(u16 species)
{
    if (species >= NUM_SPECIES)
        species = SPECIES_NONE;
    return species;
}

static void sub_80DE864(u8 a)
{
    s32 i;
    u16 move = SanitizeMove(eContestantStatus[a].currMove);
    u16 species = SanitizeSpecies(gContestMons[a].species);
    u8 r5_2;

    memset(&gContestResources->field_18->species, 0, 20);
    ClearBattleAnimationVars();
    for (i = 0; i < CONTESTANT_COUNT; i++)
        gBattleMonForms[i] = 0;
    switch (move)
    {
    case MOVE_CURSE:
        if (gBaseStats[species].type1 == TYPE_GHOST || gBaseStats[species].type2 == TYPE_GHOST)
            gAnimMoveTurn = 0;
        else
            gAnimMoveTurn = 1;
        break;
    case MOVE_TRANSFORM:
    case MOVE_ROLE_PLAY:
        r5_2 = eContestantStatus[a].unk1B;
        gContestResources->field_18->unk2 = SanitizeSpecies(gContestMons[r5_2].species);
        gContestResources->field_18->unk10 = gContestMons[r5_2].personality;
        gContestResources->field_18->unk4_0 = 1;
        break;
    case MOVE_RETURN:
        gAnimFriendship = MAX_FRIENDSHIP;
        break;
    case MOVE_FRUSTRATION:
        gAnimFriendship = 0;
        break;
    case MOVE_SOLAR_BEAM:
    case MOVE_RAZOR_WIND:
    case MOVE_SKULL_BASH:
    case MOVE_SKY_ATTACK:
        if (eContest.unk1925E == 0)
        {
            eContest.unk1925E = 2;
            gAnimMoveTurn = 0;
        }
        else
        {
            gAnimMoveTurn = 1;
        }
        break;
    }
    sub_80DEA5C();
}

static void sub_80DE9B0(u8 unused)
{
    memset(gContestResources->field_18, 0, sizeof(struct ContestStruct_field_18));
    if (eContest.unk1925E != 0)
        eContest.unk1925E--;
}

static void sub_80DE9DC(u8 contestant)
{
    gContestResources->field_18->unk5 = contestant;
    gContestResources->field_18->species = SanitizeSpecies(gContestMons[contestant].species);
    gContestResources->field_18->unk8 = gContestMons[contestant].personality;
    gContestResources->field_18->unkC = gContestMons[contestant].otId;
}

static void sub_80DEA20(void)
{
    gBattlerSpriteIds[3] = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    InitSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattlerTarget]]);
    sub_80DEA5C();
}

static void sub_80DEA5C(void)
{
    struct Sprite *sprite = &gSprites[gBattlerSpriteIds[3]];

    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    sprite->pos1.x = GetBattlerSpriteCoord(3, 0);
    sprite->pos1.y = GetBattlerSpriteCoord(3, 1);
    sprite->invisible = TRUE;
}

static void SelectContestMoveBankTarget(u16 move)
{
    switch (gBattleMoves[move].target)
    {
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_USER:
        gBattlerTarget = 2;
        break;
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
    default:
        gBattlerTarget = 3;
        break;
    }
}

static void Contest_PrintTextToBg0WindowStd(u32 a, const u8 *b)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = b;
    printerTemplate.windowId = a;
    printerTemplate.fontId = 1;
    printerTemplate.x = 0;
    printerTemplate.y = 1;
    printerTemplate.currentX = 0;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 15;
    printerTemplate.bgColor = 0;
    printerTemplate.shadowColor = 8;

    AddTextPrinter(&printerTemplate, 0, 0);
    PutWindowTilemap(a);
    Contest_SetBgCopyFlags(0);
}

void Contest_PrintTextToBg0WindowAt(u32 windowId, u8 *currChar, s32 x, s32 y, s32 fontId)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = currChar;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 15;
    printerTemplate.bgColor = 0;
    printerTemplate.shadowColor = 8;

    AddTextPrinter(&printerTemplate, 0, 0);
    PutWindowTilemap(windowId);
    Contest_SetBgCopyFlags(0);
}

static void Contest_StartTextPrinter(const u8 *currChar, bool32 b)
{
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    printerTemplate.currentChar = currChar;
    printerTemplate.windowId = 4;
    printerTemplate.fontId = 1;
    printerTemplate.x = 0;
    printerTemplate.y = 1;
    printerTemplate.currentX = 0;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 1;
    printerTemplate.bgColor = 0;
    printerTemplate.shadowColor = 8;

    if (!b)
    {
        AddTextPrinter(&printerTemplate, 0, 0);
    }
    else
    {
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
            speed = 4;
        else
            speed = GetPlayerTextSpeedDelay();
        AddTextPrinter(&printerTemplate, speed, 0);
    }

    PutWindowTilemap(4);
    Contest_SetBgCopyFlags(0);
}

static void ContestBG_FillBoxWithIncrementingTile(u8 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot, s16 tileNumData)
{
    WriteSequenceToBgTilemapBuffer(bg, firstTileNum, x, y, width, height, paletteSlot, tileNumData);
    Contest_SetBgCopyFlags(bg);
}

static void ContestBG_FillBoxWithTile(u8 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot)
{
    ContestBG_FillBoxWithIncrementingTile(bg, firstTileNum, x, y, width, height, paletteSlot, 0);
}

static bool32 Contest_RunTextPrinters(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(4);
}

static void Contest_SetBgCopyFlags(u32 flagIndex)
{
    sContestBgCopyFlags |= 1 << flagIndex;
}

void ResetContestLinkResults(void)
{
    s32 i;
    s32 j;

    for(i = 0; i < CONTEST_CATEGORIES_COUNT; i++)
        for(j = 0; j < CONTESTANT_COUNT; j++)
            gSaveBlock2Ptr->contestLinkResults[i][j] = 0;
}

bool8 sub_80DEDA8(u8 rank)
{
    s32 i;
    u8 r7 = Random() % 3;

    for (i = 0; i < CONTESTANT_COUNT - 1; i++)
    {
        if (gContestFinalStandings[i] == 0)
            break;
    }
    if (rank == 0xFF && i != gContestPlayerMonIndex)
        return FALSE;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        r7 += 0;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        r7 += 3;
        break;
    case CONTEST_CATEGORY_CUTE:
        r7 += 6;
        break;
    case CONTEST_CATEGORY_SMART:
        r7 += 9;
        break;
    case CONTEST_CATEGORY_TOUGH:
        r7 += 12;
        break;
    }
    if (rank != 0xFE)
    {
        u8 id = sub_80DEFA8(rank, 1);

        gSaveBlock1Ptr->contestWinners[id].personality = gContestMons[i].personality;
        gSaveBlock1Ptr->contestWinners[id].species = gContestMons[i].species;
        gSaveBlock1Ptr->contestWinners[id].trainerId = gContestMons[i].otId;
        StringCopy(gSaveBlock1Ptr->contestWinners[id].monName, gContestMons[i].nickname);
        StringCopy(gSaveBlock1Ptr->contestWinners[id].trainerName, gContestMons[i].trainerName);
        if(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
            gSaveBlock1Ptr->contestWinners[id].contestRank = CONTEST_RANK_LINK;
        else
            gSaveBlock1Ptr->contestWinners[id].contestRank = gSpecialVar_ContestRank;

        if (rank != 0xFF)
            gSaveBlock1Ptr->contestWinners[id].contestCategory = gSpecialVar_ContestCategory;
        else
            gSaveBlock1Ptr->contestWinners[id].contestCategory = r7;
    }
    else
    {
        gCurContestWinner.personality = gContestMons[i].personality;
        gCurContestWinner.trainerId = gContestMons[i].otId;
        gCurContestWinner.species = gContestMons[i].species;
        StringCopy(gCurContestWinner.monName, gContestMons[i].nickname);
        StringCopy(gCurContestWinner.trainerName, gContestMons[i].trainerName);
        gCurContestWinner.contestCategory = r7;
    }
    return TRUE;
}

u8 sub_80DEFA8(u8 rank, u8 b)
{
    s32 i;

    switch (rank)
    {
    case CONTEST_RANK_NORMAL:
    case CONTEST_RANK_SUPER:
    case CONTEST_RANK_HYPER:
    case CONTEST_RANK_MASTER:
        if (b != 0)
        {
            for (i = NUM_CONTEST_HALL_WINNERS - 1; i >= 1; i--)
                memcpy(&gSaveBlock1Ptr->contestWinners[i], &gSaveBlock1Ptr->contestWinners[i - 1], sizeof(struct ContestWinner));
        }
        return 0;
    default:
        switch (gSpecialVar_ContestCategory)
        {
        case CONTEST_CATEGORY_COOL:
            return CONTEST_WINNER_MUSEUM_COOL - 1;
        case CONTEST_CATEGORY_BEAUTY:
            return CONTEST_WINNER_MUSEUM_BEAUTY - 1;
        case CONTEST_CATEGORY_CUTE:
            return CONTEST_WINNER_MUSEUM_CUTE - 1;
        case CONTEST_CATEGORY_SMART:
            return CONTEST_WINNER_MUSEUM_SMART - 1;
        case CONTEST_CATEGORY_TOUGH:
        default:
            return CONTEST_WINNER_MUSEUM_TOUGH - 1;
        }
    }
}

void ClearContestWinnerPicsInContestHall(void)
{
    s32 i;

    for (i = 0; i < 8; i++)
        gSaveBlock1Ptr->contestWinners[i] = gUnknown_08587FA4[i];
}

// The functions below are probably related to Contests in TV.
static void sub_80DF080(u8 contestant)
{
    s32 i;

    if (!gContestResources->field_10->excitementFrozen
        && gContestResources->field_10->bits_0 > 0
        && !eContestantStatus[contestant].repeatedMove)
    {
        gContestResources->field_1c[contestant].unkC |= 1;
        gContestResources->field_1c[contestant].unkE_2 = 1;
    }

    if (eContestantStatus[contestant].nervous)
        gContestResources->field_1c[contestant].unkC |= 2;

    if (!gContestResources->field_10->excitementFrozen
        && gContestResources->field_10->bits_0 != 0
        && gContestResources->field_10->unk2 == 60)
    {
        gContestResources->field_1c[contestant].unkC |= 4;
    }

    if (eContestantStatus[contestant].unk15_6
        && eContestantStatus[contestant].unk16 != 0)
    {
        gContestResources->field_1c[contestant].unkC |= 8;
    }

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (i != contestant && eContestantStatus[i].jam != 0)
        {
            gContestResources->field_1c[contestant].unkC |= 0x10;
            gContestResources->field_1c[i].unkC |= 0x40;
        }
    }

    if (eContestantStatus[contestant].numTurnsSkipped != 0
        || eContestantStatus[contestant].noMoreTurns)
    {
        gContestResources->field_1c[contestant].unkC |= 0x20;
    }
    else if (!eContestantStatus[contestant].nervous)
    {
        gContestResources->field_1c[contestant].unkC |= 0x80;
        gContestResources->field_1c[contestant].unkE_1 = 1;
        gContestResources->field_1c[contestant].unk0[eContest.appealNumber] = eContestantStatus[contestant].currMove;
    }

    if (eContestantStatus[contestant].repeatedMove)
        gContestResources->field_1c[contestant].unkD |= 2;

    if (eContest.applauseLevel == 4
        && !gContestResources->field_10->excitementFrozen
        && gContestResources->field_10->bits_0 < 0)
    {
        gContestResources->field_1c[contestant].unkD |= 0x20;
    }
}

static void sub_80DF250(void)
{
    u8 r1;
    s32 i, j;
    bool32 r12, r8;
    u16 sp0[6];
    u8 spC[6];
    u16 sp14[5];
    u8 var_38;
    u8 r3;
    u8 count;

    r1 = 0;
    var_38 = 0;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (gContestFinalStandings[i] == 0)
            var_38 = i;
        else if (gContestFinalStandings[i] == 3)
            r1 = i;
    }

    gContestResources->field_1c[r1].unkD |= 1;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (i != var_38 && gContestMonTotalPoints[var_38] - gContestMonTotalPoints[i] <= 50)
            gContestResources->field_1c[i].unkD |= 4;

        if (!gContestResources->field_1c[i].unkE_2)
            gContestResources->field_1c[i].unkD |= 8;

        for (j = 0; j < CONTESTANT_COUNT; j++)
        {
            if (gContestMonRound1Points[i] < gContestMonRound1Points[j])
                break;
        }
        if (j == 4 && gContestFinalStandings[i] != 0)
            gContestResources->field_1c[i].unkD |= 0x10;

        r12 = FALSE;
        r8 = FALSE;
        for (j = 0; j < CONTESTANT_COUNT; j++)
        {
            if (gContestMonRound1Points[i] > gContestMonRound1Points[j])
                r12 = TRUE;
            if (gContestMonRound2Points[i] > gContestMonRound2Points[j])
                r8 = TRUE;
        }
        if (!r12 && !r8)
            gContestResources->field_1c[i].unkD |= 0x40;

        if (!gContestResources->field_1c[i].unkE_1)
            gContestResources->field_1c[i].unkD |= 0x80;
    }

    for (i = 0; i < 5; i++)
    {
        sp0[i] = 0;
        spC[i] = 0;
    }
    sp0[5] = 0xFFFF;
    spC[5] = 0;

    for (i = 0; i < 5; i++)
    {
        if (gContestResources->field_1c[var_38].unk0[i] != 0)
        {
            for (j = 0; j < 5; j++)
            {
                if (gContestResources->field_1c[var_38].unk0[i] != sp0[j])
                {
                    if (sp0[j] == 0)
                    {
                        sp0[j] = gContestResources->field_1c[var_38].unk0[i];
                        spC[j]++;
                    }
                }
                else
                {
                    spC[j]++;
                }
            }
        }
    }

    sp14[0] = sp0[0];
    r3 = spC[0];
    count = 0;
    for (i = 1; sp0[i] != 0xFFFF; i++)
    {
        if (r3 < spC[i])
        {
            sp14[0] = sp0[i];
            r3 = spC[i];
            count = 1;
        }
        else if (r3 == spC[i])
        {
            sp14[count] = sp0[i];
            count++;
        }
    }

    gContestResources->field_1c[var_38].unkA = sp14[Random() % count];
}

static void sub_80DF4F8(void)
{
    s32 i;
    u32 bits;
    u8 r7;
    u8 r9, r10;
    u8 count;
    u8 r5;
    u8 r2;
    u16 var;
    u8 r4;
    u8 r6;
    u8 sp0[4];

    if (gContestFinalStandings[gContestPlayerMonIndex] != 0)
        return;

    r7 = 0;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (gContestFinalStandings[i] == 0)
            r7 = i;
    }

    r9 = 0;
    r10 = 0;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (gContestMonRound1Points[r7] < gContestMonRound1Points[i])
            r9++;
        if (gContestMonRound2Points[r7] < gContestMonRound2Points[i])
            r10++;
    }

    bits = gContestResources->field_1c[r7].unkC;
    count = 0;
    for (i = 0; i < 8; bits >>= 1, i++)
    {
        if (bits & 1)
            count++;
    }

    r5 = Random() % count;
    bits = gContestResources->field_1c[r7].unkC;
    count = 0;
    r2 = 0;
    for (i = 0; i < 8; bits >>= 1, r2++, i++)
    {
        if (!(bits & 1))
            continue;
        if (r5 == count)
            break;
        count++;
    }

    var = 1 << r2;
    if (r7 == 0)
    {
        sp0[0] = 1;
        r4 = gContestResources->field_1c[1].unkD;
        i = 2;
    }
    else
    {
        sp0[0] = 0;
        r4 = gContestResources->field_1c[0].unkD;
        i = 1;
    }

    r5 = 1;
    for (; i < CONTESTANT_COUNT; i++)
    {
        if (i != r7)
        {
            if (r4 < gContestResources->field_1c[i].unkD)
            {
                sp0[0] = i;
                r4 = gContestResources->field_1c[i].unkD;
                r5 = 1;
            }
            else if (r4 == gContestResources->field_1c[i].unkD)
            {
                sp0[r5] = i;
                r5++;
            }
        }
    }

    r6 = sp0[Random() % r5];
    r2 = 0x80;
    for (i = 0; i < 8; r2 >>= 1, i++)
    {
        r4 = gContestResources->field_1c[r6].unkD & r2;
        if (r4)
            break;
    }

    ContestLiveUpdates_BeforeInterview_1(r9);
    ContestLiveUpdates_BeforeInterview_2(r10);
    ContestLiveUpdates_BeforeInterview_3(var);
    ContestLiveUpdates_BeforeInterview_4(gContestResources->field_1c[r7].unkA);
    ContestLiveUpdates_BeforeInterview_5(r4, r6);
}

// Unused
void ContestDebugToggleBitfields(bool8 showUnkD)
{
    if (eContestDebugMode == CONTEST_DEBUG_MODE_OFF)
    {
        if (!showUnkD)
            eContestDebugMode = CONTEST_DEBUG_MODE_PRINT_UNK_C;
        else
            eContestDebugMode = CONTEST_DEBUG_MODE_PRINT_UNK_D;
    }
    else
    {
        eContestDebugMode = CONTEST_DEBUG_MODE_OFF;
    }

    if (eContestDebugMode == CONTEST_DEBUG_MODE_OFF)
    {
        DrawContestantWindowText();
        SwapMoveDescAndContestTilemaps();
    }
    else
    {
        ContestDebugPrintBitStrings();
    }
}

static void ContestDebugPrintBitStrings(void)
{
    u8 i;
    s8 j;
    u8 text1[20];
    u8 text2[20];
    u8 *txtPtr;
    u32 bits;

    if (!gEnableContestDebugging)
        return;
    
    if (eContestDebugMode != CONTEST_DEBUG_MODE_PRINT_UNK_C && eContestDebugMode != CONTEST_DEBUG_MODE_PRINT_UNK_D)
        return;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));

    if (eContestDebugMode == CONTEST_DEBUG_MODE_PRINT_UNK_C)
    {
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            txtPtr = StringCopy(text1, gText_CDot);
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text1, 5, 1, 7);
            bits = gContestResources->field_1c[i].unkC;
            for (j = 7; j > -1; j--) // Weird loop.
            {
                txtPtr = ConvertIntToDecimalStringN(txtPtr, bits & 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                bits >>= 1;
            }

            for (j = 0; j < 5; j++)
                text2[j] = text1[j];

            text2[j] = EOS;
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text2, 5, 1, 7);
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text1 + j, 55, 1, 7);
        }
    }
    else
    {
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            StringCopy(text1, gText_BDot);
            bits = gContestResources->field_1c[i].unkD;
            txtPtr = &text1[2];
            for (j = 7; j > -1; j--) // Weird loop.
            {
                txtPtr = ConvertIntToDecimalStringN(txtPtr, bits & 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                bits >>= 1;
            }

            for (j = 0; j < 5; j++)
                text2[j] = text1[j];

            text2[j] = EOS;
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text2, 5, 1, 7);
            Contest_PrintTextToBg0WindowAt(gContestantTurnOrder[i], text1 + j, 55, 1, 7);
        }
    }
    SwapMoveDescAndContestTilemaps();
}

static u8 GetMonNicknameLanguage(u8 *nickname)
{
    u8 ret = GAME_LANGUAGE;

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
        return LANGUAGE_ENGLISH;

    if (StringLength(nickname) < PLAYER_NAME_LENGTH - 1)
    {
        while (*nickname != EOS)
        {
            if ((*nickname >= CHAR_A && *nickname <= CHAR_z)
                || (*nickname >= CHAR_0 && *nickname <= CHAR_9)
                || *nickname == CHAR_SPACE
                || *nickname == CHAR_PERIOD
                || *nickname == CHAR_COMMA
                || *nickname == CHAR_EXCL_MARK
                || *nickname == CHAR_QUESTION_MARK
                || *nickname == CHAR_MALE
                || *nickname == CHAR_FEMALE
                || *nickname == CHAR_SLASH
                || *nickname == CHAR_HYPHEN
                || *nickname == CHAR_ELLIPSIS
                || *nickname == CHAR_DBL_QUOT_LEFT
                || *nickname == CHAR_DBL_QUOT_RIGHT
                || *nickname == CHAR_SGL_QUOT_LEFT
                || *nickname == CHAR_DBL_QUOT_LEFT) // Most likely a typo, CHAR_SGL_QUOT_RIGHT should be here instead.
            {
                nickname++;
            }
            else
            {
                ret = LANGUAGE_JAPANESE;
                break;
            }
        }
    }

    return ret;
}

static void StripPlayerNameForLinkContest(u8 *playerName)
{
    u8 chr = playerName[5];

    playerName[5] = EOS;
    playerName[PLAYER_NAME_LENGTH] = chr;
}

static void StripMonNameForLinkContest(u8 *monName, s32 language)
{
    u8 chr;

    StripExtCtrlCodes(monName);
    if (language == LANGUAGE_JAPANESE)
    {
        monName[5] = EOS;
        monName[POKEMON_NAME_LENGTH] = EXT_CTRL_CODE_BEGIN;
    }
    else
    {
        chr = monName[5];
        monName[5] = EOS;
        monName[POKEMON_NAME_LENGTH] = chr;
    }
}

void StripPlayerAndMonNamesForLinkContest(struct ContestPokemon *mon, s32 language)
{
    u8 *name = mon->nickname;

    if (language == LANGUAGE_JAPANESE)
    {
        ConvertInternationalString(name, GetMonNicknameLanguage(name));
    }
    else if (name[POKEMON_NAME_LENGTH] == EXT_CTRL_CODE_BEGIN)
    {
        ConvertInternationalString(name, LANGUAGE_JAPANESE);
    }
    else
    {
        name[5] = name[POKEMON_NAME_LENGTH];
        name[POKEMON_NAME_LENGTH] = EOS;
    }

    name = mon->trainerName;
    if (language == LANGUAGE_JAPANESE)
    {
        name[PLAYER_NAME_LENGTH] = EOS;
        name[6] = name[4];
        name[5] = name[3];
        name[4] = name[2];
        name[3] = name[1];
        name[2] = mon->trainerName[0];
        name[1] = EXT_CTRL_CODE_JPN;
        name[0] = EXT_CTRL_CODE_BEGIN;
    }
    else
    {
        name[5] = name[PLAYER_NAME_LENGTH];
        name[PLAYER_NAME_LENGTH] = EOS;
    }
}


