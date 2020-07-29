#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "coins.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "roulette.h"
#include "roulette_util.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "tv.h"
#include "window.h"
#include "constants/coins.h"
#include "constants/rgb.h"
#include "constants/roulette.h"
#include "constants/species.h"
#include "constants/songs.h"

#define BALLS_PER_ROUND 6

#define NUM_BOARD_COLORS 3 // Grid rows
#define NUM_BOARD_POKES  4 // Grid columns
#define NUM_ROULETTE_SLOTS (NUM_BOARD_COLORS * NUM_BOARD_POKES)

// IDs for grid selections when betting
#define SELECTION_NONE      0
#define COL_WYNAUT          1
#define COL_AZURILL         2
#define COL_SKITTY          3
#define COL_MAKUHITA        4
#define ROW_ORANGE          (COL_MAKUHITA + 1)
#define SQU_ORANGE_WYNAUT   (ROW_ORANGE + COL_WYNAUT)
#define SQU_ORANGE_AZURILL  (ROW_ORANGE + COL_AZURILL)
#define SQU_ORANGE_SKITTY   (ROW_ORANGE + COL_SKITTY)
#define SQU_ORANGE_MAKUHITA (ROW_ORANGE + COL_MAKUHITA)
#define ROW_GREEN           (SQU_ORANGE_MAKUHITA + 1)
#define SQU_GREEN_WYNAUT    (ROW_GREEN + COL_WYNAUT)
#define SQU_GREEN_AZURILL   (ROW_GREEN + COL_AZURILL)
#define SQU_GREEN_SKITTY    (ROW_GREEN + COL_SKITTY)
#define SQU_GREEN_MAKUHITA  (ROW_GREEN + COL_MAKUHITA)
#define ROW_PURPLE          (SQU_GREEN_MAKUHITA + 1)
#define SQU_PURPLE_WYNAUT   (ROW_PURPLE + COL_WYNAUT)
#define SQU_PURPLE_AZURILL  (ROW_PURPLE + COL_AZURILL)
#define SQU_PURPLE_SKITTY   (ROW_PURPLE + COL_SKITTY)
#define SQU_PURPLE_MAKUHITA (ROW_PURPLE + COL_MAKUHITA)
#define NUM_GRID_SELECTIONS SQU_PURPLE_MAKUHITA

#define GET_COL(selectionId)((selectionId) % (NUM_BOARD_POKES + 1))
#define GET_ROW(selectionId)((selectionId) / (NUM_BOARD_POKES + 1) * (NUM_BOARD_POKES + 1))

// Flags for the above selections, used to set which spaces have been hit or bet on
#define F_WYNAUT_COL      (1 << COL_WYNAUT)
#define F_AZURILL_COL     (1 << COL_AZURILL)
#define F_SKITTY_COL      (1 << COL_SKITTY)
#define F_MAKUHITA_COL    (1 << COL_MAKUHITA)
#define F_ORANGE_ROW      (1 << ROW_ORANGE)
#define F_ORANGE_WYNAUT   (1 << SQU_ORANGE_WYNAUT)
#define F_ORANGE_AZURILL  (1 << SQU_ORANGE_AZURILL)
#define F_ORANGE_SKITTY   (1 << SQU_ORANGE_SKITTY)
#define F_ORANGE_MAKUHITA (1 << SQU_ORANGE_MAKUHITA)
#define F_GREEN_ROW       (1 << ROW_GREEN)
#define F_GREEN_WYNAUT    (1 << SQU_GREEN_WYNAUT)
#define F_GREEN_AZURILL   (1 << SQU_GREEN_AZURILL)
#define F_GREEN_SKITTY    (1 << SQU_GREEN_SKITTY)
#define F_GREEN_MAKUHITA  (1 << SQU_GREEN_MAKUHITA)
#define F_PURPLE_ROW      (1 << ROW_PURPLE)
#define F_PURPLE_WYNAUT   (1 << SQU_PURPLE_WYNAUT)
#define F_PURPLE_AZURILL  (1 << SQU_PURPLE_AZURILL)
#define F_PURPLE_SKITTY   (1 << SQU_PURPLE_SKITTY)
#define F_PURPLE_MAKUHITA (1 << SQU_PURPLE_MAKUHITA)

#define MAX_MULTIPLIER 12

#define PALTAG_SHADOW 1
#define PALTAG_BALL 2
#define PALTAG_BALL_COUNTER 3
#define PALTAG_INTERFACE 5
#define PALTAG_SHROOMISH 6
#define PALTAG_TAILLOW   7
#define PALTAG_GRID_ICONS 8
#define PALTAG_WYNAUT    9
#define PALTAG_AZURILL   10
#define PALTAG_SKITTY    11
#define PALTAG_MAKUHITA  12

#define GFXTAG_BOARD_ICONS 0
#define GFXTAG_HEADERS 4
#define GFXTAG_GRID_ICONS 5
#define GFXTAG_BOARD_CENTER 6
#define GFXTAG_CREDIT 7
#define GFXTAG_CREDIT_DIGIT 8
#define GFXTAG_MULTIPLIER 9
#define GFXTAG_BALL_COUNTER 10
#define GFXTAG_CURSOR 11
#define GFXTAG_BALL 12
#define GFXTAG_SHROOMISH_TAILLOW 13
#define GFXTAG_SHADOW 14

// 2 different Roulette tables with 2 different rates (normal vs service day special)
// & 1 gets which table, >> 7 gets if ROULETTE_SPECIAL_RATE is set 
#define GET_TABLE_ID(var)(((var) & 1) + (((var) >> 7) * 2))

#define HAS_SHROOMISH  (1 << 0)
#define HAS_TAILLOW    (1 << 1)

enum {
    SPR_BALL_1,
    SPR_BALL_2,
    SPR_BALL_3,
    SPR_BALL_4,
    SPR_BALL_5,
    SPR_BALL_6,
    SPR_6,
    SPR_BOARD_ICON_ORANGE_WYNAUT,
    SPR_BOARD_ICON_GREEN_AZURILL,
    SPR_BOARD_ICON_PURPLE_SKITTY,
    SPR_BOARD_ICON_ORANGE_MAKUHITA,
    SPR_BOARD_ICON_GREEN_WYNAUT,
    SPR_BOARD_ICON_PURPLE_AZURILL,
    SPR_BOARD_ICON_ORANGE_SKITTY,
    SPR_BOARD_ICON_GREEN_MAKUHITA,
    SPR_BOARD_ICON_PURPLE_WYNAUT,
    SPR_BOARD_ICON_ORANGE_AZURILL,
    SPR_BOARD_ICON_GREEN_SKITTY,
    SPR_BOARD_ICON_PURPLE_MAKUHITA,
    SPR_19,
    SPR_CREDIT,
    SPR_CREDIT_DIG_1,
    SPR_CREDIT_DIG_10,
    SPR_CREDIT_DIG_100,
    SPR_CREDIT_DIG_1000,
    SPR_MULTIPLIER,
    SPR_BALL_COUNTER_1,
    SPR_BALL_COUNTER_2,
    SPR_BALL_COUNTER_3,
    SPR_GRID_ICON_ORANGE_WYNAUT,
    SPR_GRID_ICON_2,
    SPR_GRID_ICON_3,
    SPR_GRID_ICON_4,
    SPR_GRID_ICON_5,
    SPR_GRID_ICON_6,
    SPR_GRID_ICON_7,
    SPR_GRID_ICON_8,
    SPR_GRID_ICON_9,
    SPR_GRID_ICON_10,
    SPR_GRID_ICON_11,
    SPR_GRID_ICON_12,
    SPR_POKE_HEADER_1,
    SPR_POKE_HEADER_2,
    SPR_POKE_HEADER_3,
    SPR_POKE_HEADER_4,
    SPR_COLOR_HEADER_1,
    SPR_COLOR_HEADER_2,
    SPR_COLOR_HEADER_3,
    SPR_WIN_SLOT_CURSOR,
    SPR_GRID_BALL_1,
    SPR_GRID_BALL_2,
    SPR_GRID_BALL_3,
    SPR_GRID_BALL_4,
    SPR_GRID_BALL_5,
    SPR_GRID_BALL_6,
    SPR_CLEAR_MON, // Shroomish/Taillow
    SPR_CLEAR_MON_SHADOW_1,
    SPR_CLEAR_MON_SHADOW_2,
    SPR_58,
    SPR_59,
    SPR_60,
    SPR_61,
    SPR_62,
    SPR_63,
};

// Start points for sprite IDs that are looped over
#define SPR_BOARD_ICONS SPR_BOARD_ICON_ORANGE_WYNAUT
#define SPR_GRID_ICONS SPR_GRID_ICON_ORANGE_WYNAUT

struct StructgUnknown_083F8DF4
{
    u8 var00;
    u8 var01;
    u8 var02;
    u8 var03;
    u8 var04;
    u8 filler_05[3];
    u16 var08;
    u16 var0A;
    u16 var0C;
    u8 filler_0E[2];
    u16 var10;
    u16 var12;
    u16 var14;
    u8 filler_16[2];
    u16 var18;
    u16 var1A;
    float var1C;
};

struct GridSelection
{
    u8 var00;
    u8 baseMultiplier:4;
    u8 column:4; // Never read
    u8 row;      // Never read
    u8 x;
    u8 y;
    u8 var05;    // Never read
    u8 var06;
    u32 flag;
    u32 inSelectionFlags;
    u16 var10;
};

struct RouletteSlot
{
    u8 id1; // Never read
    u8 id2; // Never read
    u8 gridSquare;
    u32 flag;
};

static EWRAM_DATA struct Roulette
{
    u8 var00;
    u8 var01;
    u8 partySpeciesFlags;
    bool8 useTaillow:5;
    bool8 var03_5:1;
    bool8 var03_6:1;
    bool8 var03_7:1;
    u8 tableId:2;
    u8 var04_2:5;
    bool8 isSpecialRate:1;
    u32 hitFlags;
    u8 hitSquares[BALLS_PER_ROUND];
    u8 pokeHits[NUM_BOARD_POKES];
    u8 colorHits[NUM_BOARD_COLORS];
    u8 minBet;
    u8 curBallNum:4; // Never actually gets incremented
    u8 unk:4; // Never read
    u8 betSelection[BALLS_PER_ROUND]; // Because curBallNum is used as the only index, only the first element is ever used (prev bet selections are never needed)
    u8 var21;
    u8 var22;
    u8 var23;
    s16 var24;
    s16 var26;
    s16 var28;
    s16 var2A;
    struct OamMatrix var2C;
    u16 var34;
    struct Sprite *var38;
    u8 spriteIds[MAX_SPRITES]; // Sprite IDs
    u8 var7C;
    u8 var7D;
    u8 var7E;
    u8 var7F;
    s16 var80;
    s16 var82;
    u16 var84;
    u16 var86;
    float var88;
    float var8C;
    float var90;
    float var94;
    float var98;
    float var9C;
    float varA0;
    u8 varA4;
    u8 varA5;
    u8 v51[2];
    u16 taskWaitDelay;
    u16 taskWaitKey;
    TaskFunc nextTask;
    u8 v46[4];
    TaskFunc varB4;
    struct UnkStruct0 varB8;
    u16 tilemapBuffers[7][0x400];
    u16 *unk_397C;
} *sRoulette = NULL;

static EWRAM_DATA u8 sTextWindowId = 0;

static void Task_SpinBoard(u8);
static void Task_StartPlaying(u8);
static void Task_ContinuePlaying(u8);
static void Task_StopPlaying(u8);
static void Task_SelectFirstEmptySquare(u8);
static void Task_HandleBetGridInput(u8);
static void Task_SlideGridOffscreen(u8);
static void Task_RollBall(u8);
static void Task_EndBallRoll(u8);
static void Task_RecordBallHit(u8);
static void Task_SlideGridOnscreen(u8);
static void sub_8141778(u8);
static void Task_PrintSpinResult(u8);
static void Task_PrintPayout(u8);
static void Task_EndTurn(u8);
static void Task_TryPrintEndTurnMsg(u8);
static void Task_ClearBoard(u8);
static void ExitRoulette(u8);
static void Task_ExitRoulette(u8);
static void StartTaskAfterDelayOrInput(u8, TaskFunc, u16, u16);
static void sub_8141FF4(u8);
static void ResetHits(void);
static void Task_AcceptMinBet(u8);
static void Task_DeclineMinBet(u8);
static u8 RecordHit(u8, u8);
static bool8 IsHitInBetSelection(u8, u8);
static void FlashSelectionOnWheel(u8);
static void DrawGridBackground(u8);
static u8 GetMultiplier(u8);
static void sub_8142814(void);
static void LoadOrFreeMiscSpritePalettesAndSheets(u8);
static void CreateGridSprites(void);
static void ShowHideGridIcons(bool8, u8);
static void CreateGridBallSprites(void);
static void ShowHideGridBalls(bool8, u8);
static void ShowHideWinSlotCursor(u8);
static void CreateBoardIconSprites(void);
static void SpriteCB_BoardIcon(struct Sprite *);
static void CreateInterfaceSprites(void);
static void SetCreditDigits(u16);
static void SetMultiplierSprite(u8);
static void SetBallCounterNumLeft(u8);
static void SpriteCB_GridSquare(struct Sprite *);
static void CreateBoardCenterSprite(void);
static void SpriteCB_BoardCenter(struct Sprite *);
static void CreateBoardBallSprites(void);
static void HideBoardBalls(void);
static void sub_81446AC(struct Sprite *);
static void CreateShroomishSprite(struct Sprite *);
static void CreateTaillowSprite(struct Sprite *);
static void sub_8144A24(struct Sprite *);
static void sub_8144E60(struct Sprite *);
static void SpriteCB_Taillow(struct Sprite *);

extern const u8 Roulette_Text_ControlsInstruction[];
extern const u8 Roulette_Text_KeepPlaying[];
extern const u8 Roulette_Text_Jackpot[];
extern const u8 Roulette_Text_ItsAHit[];
extern const u8 Roulette_Text_NothingDoing[];
extern const u8 Roulette_Text_YouveWonXCoins[];
extern const u8 Roulette_Text_BoardWillBeCleared[];
extern const u8 Roulette_Text_CoinCaseIsFull[];
extern const u8 Roulette_Text_NoCoinsLeft[];
extern const u8 Roulette_Text_PlayMinimumWagerIsX[];
extern const u8 Roulette_Text_SpecialRateTable[];
extern const u8 Roulette_Text_NotEnoughCoins[];

static const u16 gUnknown_085B5BFC[] = INCBIN_U16("graphics/roulette/85B5BFC.gbapal");
static const u32 gUnknown_085B5DFC[] = INCBIN_U32("graphics/roulette/85B5DFC.bin.lz");
static const u32 sWheel_Tilemap[] = INCBIN_U32("graphics/roulette/wheel_map.bin.lz");
static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 4,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 6,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 2,
        .baseTile = 0
    }
};
static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xC5
    },
    // BUG: Array not terminated properly
    //DUMMY_WIN_TEMPLATE
};

// var00, sprite id offset (from 7)?
static const struct GridSelection sGridSelections[NUM_GRID_SELECTIONS + 1] =
{
    [SELECTION_NONE] = {
        .var00 = 0xFF,
        .baseMultiplier = 0,
        .column = 0,
        .row = 0,
        .x = 7,
        .y = 7,
        .var05 = 0,
        .var06 = 0,
        .flag = 0,
        .inSelectionFlags = 0,
        .var10 = 0x0,
    },
    [COL_WYNAUT] = {
        .var00 = 12,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 1,
        .row = 0,
        .x = 17,
        .y = 7,
        .var05 = 0,
        .var06 = 0,
        .flag = F_WYNAUT_COL,
        .inSelectionFlags = F_WYNAUT_COL | F_ORANGE_WYNAUT | F_GREEN_WYNAUT | F_PURPLE_WYNAUT,
        .var10 = 0xE000,
    },
    [COL_AZURILL] = {
        .var00 = 13,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 2,
        .row = 0,
        .x = 20,
        .y = 7,
        .var05 = 0,
        .var06 = 0,
        .flag = F_AZURILL_COL,
        .inSelectionFlags = F_AZURILL_COL | F_ORANGE_AZURILL | F_GREEN_AZURILL | F_PURPLE_AZURILL,
        .var10 = 0xE000,
    },
    [COL_SKITTY] = {
        .var00 = 14,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 3,
        .row = 0,
        .x = 23,
        .y = 7,
        .var05 = 0,
        .var06 = 0,
        .flag = F_SKITTY_COL,
        .inSelectionFlags = F_SKITTY_COL | F_ORANGE_SKITTY | F_GREEN_SKITTY | F_PURPLE_SKITTY,
        .var10 = 0xE000,
    },
    [COL_MAKUHITA] = {
        .var00 = 15,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 4,
        .row = 0,
        .x = 26,
        .y = 7,
        .var05 = 0,
        .var06 = 0,
        .flag = F_MAKUHITA_COL,
        .inSelectionFlags = F_MAKUHITA_COL | F_ORANGE_MAKUHITA | F_GREEN_MAKUHITA | F_PURPLE_MAKUHITA,
        .var10 = 0xE000,
    },
    [ROW_ORANGE] = {
        .var00 = 16,
        .baseMultiplier = NUM_BOARD_COLORS,
        .column = 0,
        .row = 1,
        .x = 14,
        .y = 10,
        .var05 = 0,
        .var06 = 12,
        .flag = F_ORANGE_ROW,
        .inSelectionFlags = F_ORANGE_ROW | F_ORANGE_WYNAUT | F_ORANGE_AZURILL | F_ORANGE_SKITTY | F_ORANGE_MAKUHITA,
        .var10 = 0x249,
    },
    [SQU_ORANGE_WYNAUT] = {
        .var00 = 0,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 1,
        .row = 1,
        .x = 17,
        .y = 10,
        .var05 = 3,
        .var06 = 3,
        .flag = F_ORANGE_WYNAUT,
        .inSelectionFlags = F_ORANGE_WYNAUT,
        .var10 = 0x2001,
    },
    [SQU_ORANGE_AZURILL] = {
        .var00 = 9,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 2,
        .row = 1,
        .x = 20,
        .y = 10,
        .var05 = 3,
        .var06 = 3,
        .flag = F_ORANGE_AZURILL,
        .inSelectionFlags = F_ORANGE_AZURILL,
        .var10 = 0x2200,
    },
    [SQU_ORANGE_SKITTY] = {
        .var00 = 6,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 3,
        .row = 1,
        .x = 23,
        .y = 10,
        .var05 = 3,
        .var06 = 3,
        .flag = F_ORANGE_SKITTY,
        .inSelectionFlags = F_ORANGE_SKITTY,
        .var10 = 0x2040,
    },
    [SQU_ORANGE_MAKUHITA] = {
        .var00 = 3,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 4,
        .row = 1,
        .x = 26,
        .y = 10,
        .var05 = 3,
        .var06 = 3,
        .flag = F_ORANGE_MAKUHITA,
        .inSelectionFlags = F_ORANGE_MAKUHITA,
        .var10 = 0x2008,
    },
    [ROW_GREEN] = {
        .var00 = 17,
        .baseMultiplier = NUM_BOARD_COLORS,
        .column = 0,
        .row = 2,
        .x = 14,
        .y = 13,
        .var05 = 3,
        .var06 = 15,
        .flag = F_GREEN_ROW,
        .inSelectionFlags = F_GREEN_ROW | F_GREEN_WYNAUT | F_GREEN_AZURILL | F_GREEN_SKITTY | F_GREEN_MAKUHITA,
        .var10 = 0x492,
    },
    [SQU_GREEN_WYNAUT] = {
        .var00 = 4,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 1,
        .row = 2,
        .x = 17,
        .y = 13,
        .var05 = 6,
        .var06 = 6,
        .flag = F_GREEN_WYNAUT,
        .inSelectionFlags = F_GREEN_WYNAUT,
        .var10 = 0x2010,
    },
    [SQU_GREEN_AZURILL] = {
        .var00 = 1,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 2,
        .row = 2,
        .x = 20,
        .y = 13,
        .var05 = 6,
        .var06 = 6,
        .flag = F_GREEN_AZURILL,
        .inSelectionFlags = F_GREEN_AZURILL,
        .var10 = 0x2002,
    },
    [SQU_GREEN_SKITTY] = {
        .var00 = 10,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 3,
        .row = 2,
        .x = 23,
        .y = 13,
        .var05 = 6,
        .var06 = 6,
        .flag = F_GREEN_SKITTY,
        .inSelectionFlags = F_GREEN_SKITTY,
        .var10 = 0x2400,
    },
    [SQU_GREEN_MAKUHITA] = {
        .var00 = 7,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 4,
        .row = 2,
        .x = 26,
        .y = 13,
        .var05 = 6,
        .var06 = 6,
        .flag = F_GREEN_MAKUHITA,
        .inSelectionFlags = F_GREEN_MAKUHITA,
        .var10 = 0x2080,
    },
    [ROW_PURPLE] = {
        .var00 = 18,
        .baseMultiplier = NUM_BOARD_COLORS,
        .column = 0,
        .row = 3,
        .x = 14,
        .y = 16,
        .var05 = 6,
        .var06 = 18,
        .flag = F_PURPLE_ROW,
        .inSelectionFlags = F_PURPLE_ROW | F_PURPLE_WYNAUT | F_PURPLE_AZURILL | F_PURPLE_SKITTY | F_PURPLE_MAKUHITA,
        .var10 = 0x924,
    },
    [SQU_PURPLE_WYNAUT] = {
        .var00 = 8,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 1,
        .row = 3,
        .x = 17,
        .y = 16,
        .var05 = 9,
        .var06 = 9,
        .flag = F_PURPLE_WYNAUT,
        .inSelectionFlags = F_PURPLE_WYNAUT,
        .var10 = 0x2100,
    },
    [SQU_PURPLE_AZURILL] = {
        .var00 = 5,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 2,
        .row = 3,
        .x = 20,
        .y = 16,
        .var05 = 9,
        .var06 = 9,
        .flag = F_PURPLE_AZURILL,
        .inSelectionFlags = F_PURPLE_AZURILL,
        .var10 = 0x2020,
    },
    [SQU_PURPLE_SKITTY] = {
        .var00 = 2,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 3,
        .row = 3,
        .x = 23,
        .y = 16,
        .var05 = 9,
        .var06 = 9,
        .flag = F_PURPLE_SKITTY,
        .inSelectionFlags = F_PURPLE_SKITTY,
        .var10 = 0x2004,
    },
    [SQU_PURPLE_MAKUHITA] = {
        .var00 = 11,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 4,
        .row = 3,
        .x = 26,
        .y = 16,
        .var05 = 9,
        .var06 = 9,
        .flag = F_PURPLE_MAKUHITA,
        .inSelectionFlags = F_PURPLE_MAKUHITA,
        .var10 = 0x2800,
    },
};

static const struct RouletteSlot sRouletteSlots[] =
{
    {
        .id1 = 0,
        .id2 = 1,
        .gridSquare = SQU_ORANGE_WYNAUT,
        .flag = F_ORANGE_WYNAUT,
    },
    {
        .id1 = 1,
        .id2 = 3,
        .gridSquare = SQU_GREEN_AZURILL,
        .flag = F_GREEN_AZURILL,
    },
    {
        .id1 = 2,
        .id2 = 5,
        .gridSquare = SQU_PURPLE_SKITTY,
        .flag = F_PURPLE_SKITTY,
    },
    {
        .id1 = 3,
        .id2 = 7,
        .gridSquare = SQU_ORANGE_MAKUHITA,
        .flag = F_ORANGE_MAKUHITA,
    },
    {
        .id1 = 4,
        .id2 = 9,
        .gridSquare = SQU_GREEN_WYNAUT,
        .flag = F_GREEN_WYNAUT,
    },
    {
        .id1 = 5,
        .id2 = 11,
        .gridSquare = SQU_PURPLE_AZURILL,
        .flag = F_PURPLE_AZURILL,
    },
    {
        .id1 = 6,
        .id2 = 13,
        .gridSquare = SQU_ORANGE_SKITTY,
        .flag = F_ORANGE_SKITTY,
    },
    {
        .id1 = 7,
        .id2 = 15,
        .gridSquare = SQU_GREEN_MAKUHITA,
        .flag = F_GREEN_MAKUHITA,
    },
    {
        .id1 = 8,
        .id2 = 17,
        .gridSquare = SQU_PURPLE_WYNAUT,
        .flag = F_PURPLE_WYNAUT,
    },
    {
        .id1 = 9,
        .id2 = 19,
        .gridSquare = SQU_ORANGE_AZURILL,
        .flag = F_ORANGE_AZURILL,
    },
    {
        .id1 = 10,
        .id2 = 21,
        .gridSquare = SQU_GREEN_SKITTY,
        .flag = F_GREEN_SKITTY,
    },
    {
        .id1 = 11,
        .id2 = 23,
        .gridSquare = SQU_PURPLE_MAKUHITA,
        .flag = F_PURPLE_MAKUHITA,
    },
};
static const u8 sTableMinBets[] = {1, 3, 1, 6};

static const struct StructgUnknown_083F8DF4 gUnknown_085B6348[] =
{
    {
        .var00 = 1,
        .var01 = 60,
        .var02 = 30,
        .var03 = 1,
        .var04 = 1,
        .var08 = 45,
        .var0A = 30,
        .var0C = 1,
        .var10 = 75,
        .var12 = 27,
        .var14 = 24,
        .var18 = 10,
        .var1A = 360,
        .var1C = -0.5f
    },
    {
        .var00 = 3,
        .var01 = 30,
        .var02 = 15,
        .var03 = 1,
        .var04 = 0,
        .var08 = 75,
        .var0A = 60,
        .var0C = 2,
        .var10 = 0,
        .var12 = 54,
        .var14 = 48,
        .var18 = 10,
        .var1A = 270,
        .var1C = -1.0f
    }
};

static const struct UnkStruct1 gUnknown_085B6388[] =
{
    {
        .var00 = 0x8000,
        .var02 = 0x0005,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x000A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0015,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0055,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x005A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0065,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0075,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x007A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0085,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x0095,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x009A,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x8000,
        .var02 = 0x00A5,
        .var04 = 1,
        .var05 = 1,
        .var06 = 0xFF,
        .var07_0 = 8,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x77D6,
        .var02 = 0x0028,
        .var04 = 2,
        .var05 = 10,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = -2,
        .var07_7 = 0
    },
};

static const struct UnkStruct1 gUnknown_085B63F0[] =
{
    {
        .var00 = 0x53FF,
        .var02 = 0x0101,
        .var04 = 5,
        .var05 = 30,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x7FFB,
        .var02 = 0x0106,
        .var04 = 5,
        .var05 = 30,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = -2,
        .var07_7 = 0
    },
    {
        .var00 = 0x7F7F,
        .var02 = 0x010B,
        .var04 = 5,
        .var05 = 30,
        .var06 = 0xFF,
        .var07_0 = 14,
        .var07_5 = -2,
        .var07_7 = 0
    }
};

static const struct YesNoFuncTable sYesNoTable_AcceptMinBet =
{
    Task_AcceptMinBet,
    Task_DeclineMinBet
};

static const struct YesNoFuncTable sYesNoTable_KeepPlaying =
{
    Task_ContinuePlaying,
    Task_StopPlaying
};

static void CB2_Roulette(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	if (sRoulette->varB8.var00)
	   task_tutorial_controls_fadein(&sRoulette->varB8);
}

static void VBlankCB_Roulette(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_8142814();
    SetGpuReg(REG_OFFSET_BG1HOFS, 0x200 - sRoulette->var26);
    if (sRoulette->var01)
        SetGpuReg(REG_OFFSET_BLDALPHA, sRoulette->var34);
    if (sRoulette->var2A != 0)
    {
        DmaCopy16(3, &sRoulette->tilemapBuffers[2][0xE0], (void *)BG_SCREEN_ADDR(4) + 0x1C0, 0x340);
        sRoulette->var2A = 0;
    }
    switch (sRoulette->var28)
    {
    case 1:
        SetBgAttribute(0, BG_ATTR_CHARBASEINDEX, 0);
        ShowBg(0);
        DmaCopy16(3, &sRoulette->tilemapBuffers[0][0xE0], (void *)BG_SCREEN_ADDR(31) + 0x1C0, 0x340);
        sRoulette->var28 = 2;
        break;
    case 2:
        DmaCopy16(3, &sRoulette->tilemapBuffers[0][0xE0], (void *)BG_SCREEN_ADDR(31) + 0x1C0, 0x340);
        break;
    case 0xFF:
        SetBgAttribute(0, BG_ATTR_CHARBASEINDEX, 2);
        ShowBg(0);
        DmaFill16(3, 0, (void *)BG_SCREEN_ADDR(31) + 0x1C0, 0x340);
        sRoulette->var28 = 0;
    case 0:
        break;
    }
}

static void InitRouletteBgAndWindows(void)
{
    u32 size = 0;

    sRoulette = AllocZeroed(sizeof(*sRoulette));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(0, sRoulette->tilemapBuffers[0]);
    SetBgTilemapBuffer(1, sRoulette->tilemapBuffers[2]);
    SetBgTilemapBuffer(2, sRoulette->tilemapBuffers[6]);
    InitWindows(sWindowTemplates);
    InitTextBoxGfxAndPrinters();
    sTextWindowId = 0;
    sRoulette->unk_397C = malloc_and_decompress(gUnknown_085B5DFC, &size);
}

static void FreeRoulette(void)
{
    FREE_AND_SET_NULL(sRoulette->unk_397C);
    FreeAllWindowBuffers();
    UnsetBgTilemapBuffer(0);
    UnsetBgTilemapBuffer(1);
    UnsetBgTilemapBuffer(2);
    ResetBgsAndClearDma3BusyFlags(0);
    memset(sRoulette, 0, sizeof(*sRoulette));
    FREE_AND_SET_NULL(sRoulette);
}

static void sub_8140470(void)
{
    u8 i;
    u16 arr[3] = {RGB(24, 4, 10), RGB(10, 19, 6), RGB(24, 4, 10)}; // the third is never used ?

    sRoulette->tableId = (gSpecialVar_0x8004 & 1);

    if (gSpecialVar_0x8004 & ROULETTE_SPECIAL_RATE)
        sRoulette->isSpecialRate = TRUE;

    sRoulette->var22 = gUnknown_085B6348[sRoulette->tableId].var03;
    sRoulette->var23 = gUnknown_085B6348[sRoulette->tableId].var04;
    sRoulette->minBet = sTableMinBets[sRoulette->tableId + sRoulette->isSpecialRate * 2];
    sRoulette->unk = 1;

    if (sRoulette->minBet == 1)
        gPlttBufferUnfaded[0] = gPlttBufferUnfaded[0x51] = gPlttBufferFaded[0] = gPlttBufferFaded[0x51] = arr[0];
    else
        gPlttBufferUnfaded[0] = gPlttBufferUnfaded[0x51] = gPlttBufferFaded[0] = gPlttBufferFaded[0x51] = arr[1];

    sub_8151678(&sRoulette->varB8);

    for (i = 0; i < 13; i++)
    {
        sub_815168C(&sRoulette->varB8, i, &gUnknown_085B6388[i]);
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        switch (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2))
        {
        case SPECIES_SHROOMISH:
            sRoulette->partySpeciesFlags |= HAS_SHROOMISH;
            break;
        case SPECIES_TAILLOW:
            sRoulette->partySpeciesFlags |= HAS_TAILLOW;
            break;
        }
    }
    RtcCalcLocalTime();
}

// Task data for the roulette game tasks, starting with Task_StartPlaying
#define tMultiplier      data[2]
#define tSelectionId     data[4]
#define tWonBet          data[5]
#define tBallNum         data[6]
#define tConsecutiveWins data[11]
#define tWinningSquare   data[12]
#define tCoins           data[13]

static void CB2_LoadRoulette(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ResetAllBgsCoordinates();
        break;
    case 1:
        InitRouletteBgAndWindows();
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE |
                                     BLDCNT_TGT2_BG2 |
                                     BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(10, 6));
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ResetTempTileDataBuffers();
        break;
    case 3:
        LoadPalette(&gUnknown_085B5BFC, 0, 0x1C0);
        DecompressAndCopyTileDataToVram(1, gRouletteMenu_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(2, gRouletteWheel_Gfx, 0, 0, 0);
        break;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return;

        sub_8140470();
        CopyToBgTilemapBuffer(2, sWheel_Tilemap, 0, 0);
        break;
    case 5:
        LoadOrFreeMiscSpritePalettesAndSheets(FALSE);
        CreateBoardBallSprites();
        CreateBoardCenterSprite();
        CreateInterfaceSprites();
        CreateGridSprites();
        CreateGridBallSprites();
        CreateBoardIconSprites();
        break;
    case 6:
        AnimateSprites();
        BuildOamBuffer();
        SetCreditDigits(GetCoins());
        SetBallCounterNumLeft(BALLS_PER_ROUND);
        SetMultiplierSprite(SELECTION_NONE);
        DrawGridBackground(SELECTION_NONE);
        DrawStdWindowFrame(sTextWindowId, FALSE);
        AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_ControlsInstruction, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(sTextWindowId, 3);
        gSpriteCoordOffsetX = -60;
        gSpriteCoordOffsetY = 0;
        break;
    case 7:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_OBJ_ON);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        break;
    case 8:
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Roulette);
        BeginHardwarePaletteFade(0xFF, 0, 16, 0, 1);
        taskId = sRoulette->varA4 = CreateTask(Task_StartPlaying, 0);
        gTasks[taskId].tBallNum = BALLS_PER_ROUND;
        gTasks[taskId].tCoins = GetCoins();
        AlertTVThatPlayerPlayedRoulette(GetCoins());
        sRoulette->varA5 = CreateTask(Task_SpinBoard, 1);
        SetMainCallback2(CB2_Roulette);
        return;
    }
    gMain.state++;
}

static void Task_SpinBoard(u8 taskId)
{
    s16 sin;
    s16 cos;

    if (sRoulette->var21++ == sRoulette->var23)
    {
        sRoulette->var21 = 0;
        if ((sRoulette->var24 -= sRoulette->var22) < 0)
            sRoulette->var24 = 360 - sRoulette->var22;
    }
    sin = Sin2(sRoulette->var24);
    cos = Cos2(sRoulette->var24);
    sin = sin / 16;
    sRoulette->var2C.a = sRoulette->var2C.d = cos / 16;
    sRoulette->var2C.b =  sin;
    sRoulette->var2C.c = -sin;
}

static void Task_StartPlaying(u8 taskId)
{
    if (UpdatePaletteFade() == 0)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_NONE |
                                     BLDCNT_TGT2_BG2 |
                                     BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        gTasks[taskId].tBallNum = 0;
        sub_8141FF4(taskId);
        ResetHits();
        HideBoardBalls();
        DrawGridBackground(SELECTION_NONE);
        SetBallCounterNumLeft(BALLS_PER_ROUND);
        StartTaskAfterDelayOrInput(taskId, Task_ContinuePlaying, 0xFFFF, A_BUTTON | B_BUTTON);
    }
}

static void Task_AskKeepPlaying(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    DrawStdWindowFrame(sTextWindowId, 0);
    AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_KeepPlaying, 0, 1, TEXT_SPEED_FF, 0);
    CopyWindowToVram(sTextWindowId, 3);
    DoYesNoFuncWithChoice(taskId, &sYesNoTable_KeepPlaying);
}

static void Task_ContinuePlaying(u8 taskId)
{
    ClearStdWindowAndFrame(0, TRUE);
    gTasks[taskId].func = Task_SelectFirstEmptySquare;
}

static void Task_StopPlaying(u8 taskId)
{
    DestroyTask(sRoulette->varA5);
    ExitRoulette(taskId);
}

static void UpdateGridSelectionRect(u8 selectionId)
{
    u8 temp0, temp1;
    switch (selectionId)
    {
    case SELECTION_NONE:
        ClearGridSelectionRect(&sRoulette->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        break;
    case COL_WYNAUT:
    case COL_AZURILL:
    case COL_SKITTY:
    case COL_MAKUHITA:
        temp0 = (selectionId * 3 + 14);
        ClearGridSelectionRect(&sRoulette->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        SetGridSelectionRect(&sRoulette->tilemapBuffers[0][0], &sRoulette->unk_397C[281], temp0, 7, 3, 13);
        break;
    case ROW_ORANGE:
    case ROW_GREEN:
    case ROW_PURPLE:
        temp1 = ((selectionId - 1) / 5 * 3 + 10);
        ClearGridSelectionRect(&sRoulette->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        SetGridSelectionRect(&sRoulette->tilemapBuffers[0][0], &sRoulette->unk_397C[320], 14, temp1, 16, 3);
        break;
    // Individual square
    default:
        temp0 = GET_COL(selectionId) * 3 + 14;
        temp1 = ((selectionId - 1) / 5 * 3 + 7);
        ClearGridSelectionRect(&sRoulette->tilemapBuffers[0][0], 0, 14, 7, 16, 13);
        SetGridSelectionRect(&sRoulette->tilemapBuffers[0][0], &sRoulette->unk_397C[272], temp0, temp1, 3, 3);
        break;
    }
}

static void UpdateGridSelection(u8 taskId)
{
    SetMultiplierSprite(gTasks[taskId].tSelectionId);
    UpdateGridSelectionRect(gTasks[taskId].tSelectionId);
}

static void Task_StartHandleBetGridInput(u8 taskId)
{
    sRoulette->var28 = 1;
    UpdateGridSelectionRect(gTasks[taskId].tSelectionId);
    sRoulette->var23 = 2;
    sRoulette->var21 = 0;
    gTasks[taskId].func = Task_HandleBetGridInput;
}

static void Task_SelectFirstEmptySquare(u8 taskId)
{
    s16 i;

    if (sRoulette->hitFlags & F_ORANGE_ROW)
    {
        // If the whole orange row is filled, get first in green row
        for (i = SQU_GREEN_WYNAUT; i < SQU_GREEN_MAKUHITA; i++)
        {
            if (!(sRoulette->hitFlags & sGridSelections[i].flag))
                break;
        }
    }
    else
    {
        // Otherwise get first in orange row
        // With only 6 balls both rows can't be filled, no need to check purple row
        for (i = SQU_ORANGE_WYNAUT; i <= SQU_ORANGE_MAKUHITA; i++) // <= is accidental, but it will never get that far
        {
            if (!(sRoulette->hitFlags & sGridSelections[i].flag))
                break;
        }
    }
    gTasks[taskId].tSelectionId = i;
    sub_8141FF4(taskId);
    DrawGridBackground(gTasks[taskId].tSelectionId);
    SetMultiplierSprite(gTasks[taskId].tSelectionId);
    FlashSelectionOnWheel(gTasks[taskId].tSelectionId);
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = Task_StartHandleBetGridInput;
}

static bool8 CanMoveSelectionInDir(s16 *selectionId, u8 dir)
{
    s8 temp1 = 0;
    s8 temp = 0;
    s8 moveOffsets[4] = {-5, 5, -1, 1};
    s8 originalSelection = *selectionId;

    switch (dir)
    {
    case 0: // UP
    case 1: // DOWN
        temp1 = GET_COL(*selectionId);
        temp = temp1 + ROW_PURPLE;
        if (temp1 == SELECTION_NONE)
            temp1 = 5;
        break;
    case 2: // LEFT
    case 3: // RIGHT
        temp1 = GET_ROW(*selectionId);
        temp = temp1 + COL_MAKUHITA;
        if (temp1 == SELECTION_NONE)
            temp1 = 1;
        break;
    }

    *selectionId += moveOffsets[dir];

    if (*selectionId < temp1)
        *selectionId = temp;

    if (*selectionId > temp)
        *selectionId = temp1;

    if (*selectionId != originalSelection)
        return TRUE;

    return FALSE;
}

static void ProcessBetGridInput(u8 taskId)
{
    u8 z = 0;
    bool8 dirPressed = FALSE;
    if ((!(JOY_NEW(DPAD_UP))    || ((dirPressed = TRUE), CanMoveSelectionInDir(&gTasks[taskId].tSelectionId, 0)))
     && (!(JOY_NEW(DPAD_DOWN))  || ((dirPressed = TRUE), CanMoveSelectionInDir(&gTasks[taskId].tSelectionId, 1)))
     && (!(JOY_NEW(DPAD_LEFT))  || ((dirPressed = TRUE), CanMoveSelectionInDir(&gTasks[taskId].tSelectionId, 2)))
     && (!(JOY_NEW(DPAD_RIGHT)) || ((dirPressed = TRUE), CanMoveSelectionInDir(&gTasks[taskId].tSelectionId, 3)))
     && (dirPressed))
    {
        u8 i;
        DrawGridBackground(gTasks[taskId].tSelectionId);
        UpdateGridSelection(taskId);
        gTasks[taskId].data[1] = z;
        PlaySE(SE_SELECT);
        sub_8151A9C(&sRoulette->varB8, 0xFFFF);
        sRoulette->varB8.var04[13].var00_7 = sRoulette->varB8.var04[14].var00_7 = sRoulette->varB8.var04[15].var00_7 = 0;
        FlashSelectionOnWheel(gTasks[taskId].tSelectionId);
        for (i = 0; i < NUM_BOARD_POKES; i++)
        {
            gSprites[sRoulette->spriteIds[i + SPR_POKE_HEADER_1]].oam.tileNum =
            gSprites[sRoulette->spriteIds[i + SPR_POKE_HEADER_1]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[i + SPR_POKE_HEADER_1]].anims)->type;
        }
        if ((u16)(gTasks[taskId].tSelectionId - 1) < 4 && !(sRoulette->hitFlags & sGridSelections[gTasks[taskId].tSelectionId].flag) )
        {
            z = gTasks[taskId].tSelectionId - 1;
            gSprites[sRoulette->spriteIds[z + SPR_POKE_HEADER_1]].oam.tileNum =
            gSprites[sRoulette->spriteIds[z + SPR_POKE_HEADER_1]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[z + SPR_POKE_HEADER_1]].anims + 1)->type;
        }
    }
}

static void sub_8140F6C(u8 r0)
{
    IncrementDailyRouletteUses();
    sRoulette->var28 = 0xFF;
    if (sRoulette->minBet == 1)
        sRoulette->var23 = 1;
    else
        sRoulette->var23 = 0;
    sRoulette->var21 = 0;
    gTasks[r0].data[1] = 32;
    gTasks[r0].func = Task_SlideGridOffscreen;
}

static void Task_PlaceBet(u8 taskId)
{
    sRoulette->betSelection[sRoulette->curBallNum] = gTasks[taskId].tSelectionId;
    gTasks[taskId].tMultiplier = GetMultiplier(sRoulette->betSelection[sRoulette->curBallNum]);
    SetMultiplierSprite(sRoulette->betSelection[sRoulette->curBallNum]);
    if ((gTasks[taskId].tCoins -= sRoulette->minBet) < 0)
        gTasks[taskId].tCoins = 0;
    SetCreditDigits(gTasks[taskId].tCoins);
    gTasks[taskId].func = sub_8140F6C;
}

static void Task_HandleBetGridInput(u8 taskId)
{
    ProcessBetGridInput(taskId);

    // Flash selection rect
    switch (gTasks[taskId].data[1])
    {
    case 0:
        UpdateGridSelectionRect(gTasks[taskId].tSelectionId);
        gTasks[taskId].data[1]++;
        break;
    case 30:
        UpdateGridSelectionRect(SELECTION_NONE);
        gTasks[taskId].data[1]++;
        break;
    case 59:
        gTasks[taskId].data[1] = 0;
        break;
    default:
        gTasks[taskId].data[1]++;
    }

    if (JOY_NEW(A_BUTTON))
    {
        if ((sRoulette->hitFlags & sGridSelections[gTasks[taskId].tSelectionId].flag))
        {
            // Ball has already landed on this space
            PlaySE(SE_BOO);
        }
        else
        {
            m4aSongNumStart(SE_REGI);
            gTasks[taskId].func = Task_PlaceBet;
        }
    }
}

static void Task_SlideGridOffscreen(u8 taskId)
{
    if (gTasks[taskId].data[1]-- > 0)
    {
        if (gTasks[taskId].data[1] > 2)
            gSpriteCoordOffsetX += 2;
        if ((sRoulette->var26 += 4) == 104)
            gSprites[sRoulette->spriteIds[SPR_MULTIPLIER]].callback = &SpriteCallbackDummy;
    }
    else
    {
        ShowHideGridIcons(TRUE, -1);
        ShowHideGridBalls(TRUE, -1);
        gTasks[taskId].func = Task_RollBall;
        gTasks[taskId].data[1] = 0;
    }
}

static u8 sub_814118C(u16 r0, u16 r1)
{
    switch (sRoulette->partySpeciesFlags)
    {
    case HAS_SHROOMISH:
    case HAS_TAILLOW:
        // one of the two is in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 10)
        {
            if (r0 < 12 || (r1 & 1))
                return gUnknown_085B6348[sRoulette->tableId].var02 / 2;
            else
                return 1;
        }
        else if (!(r1 & 0x3)) 
        {
            return gUnknown_085B6348[sRoulette->tableId].var02 / 2;
        }
        else 
        {
            return gUnknown_085B6348[sRoulette->tableId].var02;
        }
        break;
    case HAS_SHROOMISH | HAS_TAILLOW:
        // both are in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 11)
        {
            if (r0 < 6 || (r1 & 1))
                return gUnknown_085B6348[sRoulette->tableId].var02 / 2;
            else
                return 1;
        }
        else if ((r1 & 1) && r0 > 6) 
        {
            return gUnknown_085B6348[sRoulette->tableId].var02 / 4;
        }
        else 
        {
            return gUnknown_085B6348[sRoulette->tableId].var02 / 2;
        }
        break;
    case 0:
    default:
        // neither is in party
        if (gLocalTime.hours > 3 && gLocalTime.hours < 10)
        {
            if (!(r1 & 3))
                return 1;
            else
                return gUnknown_085B6348[sRoulette->tableId].var02 / 2;
        }
        else if (!(r1 & 3))
        {
            if (r0 > 12)
                return gUnknown_085B6348[sRoulette->tableId].var02 / 2;
            else
                return gUnknown_085B6348[sRoulette->tableId].var02;
        }
        else if (r1 & 0x8000)
        {
            if (r0 > 12)
                return gUnknown_085B6348[sRoulette->tableId].var02;
            else
                return gUnknown_085B6348[sRoulette->tableId].var01;
        }
        else
        {
            return gUnknown_085B6348[sRoulette->tableId].var01 * 2;
        }
        break;
    }
}

static void Task_RollBall(u8 taskId)
{
    u8 randf;
    s8 randfinal;
    s8 r5;
    u16 g = 0;
    u16 rand;
    u16 randmod;
    u16 angles[4] = {0, 180, 90, 270}; // angles in 90 degree steps

    rand = Random();
    randmod = rand % 100;
    sRoulette->var7C = gTasks[taskId].tBallNum;
    sRoulette->var7D = sRoulette->var7E = sRoulette->var7F = g;
    randf = sub_814118C(gTasks[taskId].data[8], rand);
    randfinal = (rand % randf) - (randf / 2);

    if (gLocalTime.hours < 13)
        r5 = 0;
    else
        r5 = 1;

    if (randmod < 80)
        r5 *= 2;
    else
        r5 = (1 - r5) * 2;

    sRoulette->var80 = g = gUnknown_085B6348[sRoulette->tableId].var1A + randfinal;

    g = S16TOPOSFLOAT(g) / 5.0f;
    sRoulette->var82 = g * 3;
    sRoulette->var86 = sRoulette->var84 = g;

    sRoulette->var88 = S16TOPOSFLOAT(angles[(rand & 1) + r5]);
    sRoulette->var8C = S16TOPOSFLOAT(gUnknown_085B6348[sRoulette->tableId].var18);
    sRoulette->var90 = ((sRoulette->var8C * 0.5f) - sRoulette->var8C) / S16TOPOSFLOAT(sRoulette->var82);
    sRoulette->var94 = 68.0f;
    sRoulette->var9C = 0.0f;
    sRoulette->var98 = -(8.0f / S16TOPOSFLOAT(sRoulette->var82));
    sRoulette->varA0 = 36.0f;
    gTasks[taskId].func = Task_EndBallRoll;
}

static void Task_EndBallRoll(u8 taskId)
{
    u8 index;
    sRoulette->var03_7 = TRUE;
    index = sRoulette->spriteIds[sRoulette->var7C];
    sRoulette->var38 = &gSprites[index];
    sRoulette->var38->callback = sub_81446AC;
    gTasks[taskId].tBallNum++;
    gTasks[taskId].data[8]++;
    SetBallCounterNumLeft(BALLS_PER_ROUND - gTasks[taskId].tBallNum);
    m4aSongNumStart(SE_TAMAKORO);
    gTasks[taskId].func = Task_RecordBallHit;
}

static void Task_RecordBallHit(u8 taskId)
{
    if (sRoulette->var7D)
    {
        if (sRoulette->var03_5)
        {
            if (sRoulette->var03_6)
            {
                sRoulette->var03_6 = FALSE;
                sRoulette->var03_5 = FALSE;
            }
        }
        else
        {
            if (!gTasks[taskId].data[1])
            {
                bool8 temp = IsHitInBetSelection(RecordHit(taskId, sRoulette->var7E), sRoulette->betSelection[sRoulette->curBallNum]);
                gTasks[taskId].tWonBet = temp;
                if (temp == TRUE)
                    sub_8151A48(&sRoulette->varB8, 0x1000);
            }
            if (gTasks[taskId].data[1] <= 60)
            {
                if (JOY_NEW(A_BUTTON))
                    gTasks[taskId].data[1] = 60;
                gTasks[taskId].data[1]++;
            }
            else
            {
                DrawGridBackground(sRoulette->betSelection[sRoulette->curBallNum]);
                ShowHideGridIcons(FALSE, gTasks[taskId].tWinningSquare);
                ShowHideGridBalls(FALSE, gTasks[taskId].tBallNum - 1);
                gTasks[taskId].data[1] = 32;
                gTasks[taskId].func = Task_SlideGridOnscreen;
            }
        }
    }
}

static void Task_SlideGridOnscreen(u8 taskId)
{
    if (gTasks[taskId].data[1]-- > 0)
    {
        if (gTasks[taskId].data[1] > 2)
            gSpriteCoordOffsetX -= 2;
        if ((sRoulette->var26 -= 4) == 104)
            gSprites[sRoulette->spriteIds[SPR_MULTIPLIER]].callback = SpriteCB_GridSquare;
    }
    else
    {
        ShowHideWinSlotCursor(gTasks[taskId].tWinningSquare);
        if (gTasks[taskId].tWonBet == TRUE)
            gTasks[taskId].data[1] = 121;
        else
            gTasks[taskId].data[1] = 61;
        gTasks[taskId].func = sub_8141778;
    }
}

static void sub_8141778(u8 taskId)
{
    if (gTasks[taskId].data[1]-- > 1)
    {
        switch (gTasks[taskId].data[1] % 16)
        {
        case 8:
            ShowHideGridIcons(FALSE, -1);
            ShowHideGridBalls(FALSE, -1);
            break;
        case 0:
            ShowHideGridIcons(FALSE, gTasks[taskId].tWinningSquare);
            ShowHideGridBalls(FALSE, gTasks[taskId].tBallNum - 1);
            break;
        }
    }
    else
    {
        StartTaskAfterDelayOrInput(taskId, Task_PrintSpinResult, 30, 0);
    }
}

static void Task_TryIncrementWins(u8 taskId)
{
    switch (gTasks[taskId].tWonBet)
    {
    case TRUE:
    case 2: // never happens
        if (IsFanfareTaskInactive())
        {
            u32 wins = GetGameStat(GAME_STAT_CONSECUTIVE_ROULETTE_WINS);
            if (wins < ++gTasks[taskId].tConsecutiveWins)
                SetGameStat(GAME_STAT_CONSECUTIVE_ROULETTE_WINS, gTasks[taskId].tConsecutiveWins);
            StartTaskAfterDelayOrInput(taskId, Task_PrintPayout, 0xFFFF, A_BUTTON | B_BUTTON);
        }
        break;
    case FALSE:
    default:
        if (!IsSEPlaying())
        {
            gTasks[taskId].tConsecutiveWins = 0;
            StartTaskAfterDelayOrInput(taskId, Task_EndTurn, 0xFFFF, A_BUTTON | B_BUTTON);
        }
        break;
    }
}

static void Task_PrintSpinResult(u8 taskId)
{
    switch (gTasks[taskId].tWonBet)
    {
    case TRUE:
    case 2: // never happens
        if (gTasks[taskId].tMultiplier == MAX_MULTIPLIER)
        {
            PlayFanfare(MUS_ME_B_BIG);
            DrawStdWindowFrame(sTextWindowId, FALSE);
            AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_Jackpot, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(sTextWindowId, 3);
        }
        else
        {
            PlayFanfare(MUS_ME_B_SMALL);
            DrawStdWindowFrame(sTextWindowId, FALSE);
            AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_ItsAHit, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(sTextWindowId, 3);
        }
        break;
    case FALSE:
    default:
        m4aSongNumStart(SE_HAZURE);
        DrawStdWindowFrame(sTextWindowId, FALSE);
        AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_NothingDoing, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(sTextWindowId, 3);
        break;
    }
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = Task_TryIncrementWins;
}

#define tPayout data[1]

static void Task_GivePayout(u8 taskId)
{
    switch (gTasks[taskId].data[7])
    {
    case 0:
        gTasks[taskId].tCoins++;
        m4aSongNumStart(SE_PIN);
        SetCreditDigits(gTasks[taskId].tCoins);
        if (gTasks[taskId].tCoins >= MAX_COINS)
        {
            gTasks[taskId].tPayout = 0;
        }
        else
        {
            gTasks[taskId].tPayout--;
            gTasks[taskId].data[7]++;
        }
        break;
    case 3:
        m4aSongNumStop(SE_PIN);
        gTasks[taskId].data[7] = 0;
        break;
    default:
        gTasks[taskId].data[7]++;
        break;
    }
    if (gTasks[taskId].tPayout == 0)
        StartTaskAfterDelayOrInput(taskId, Task_EndTurn, 0xFFFF, A_BUTTON | B_BUTTON);
}

static void Task_PrintPayout(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, (sRoulette->minBet * gTasks[taskId].tMultiplier), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, Roulette_Text_YouveWonXCoins);
    DrawStdWindowFrame(sTextWindowId, FALSE);
    AddTextPrinterParameterized(sTextWindowId, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(sTextWindowId, 3);
    gTasks[taskId].tPayout = (sRoulette->minBet * gTasks[taskId].tMultiplier);
    gTasks[taskId].data[7] = 0;
    gTasks[taskId].func = Task_GivePayout;
}

#undef tPayout

static void Task_EndTurn(u8 taskId)
{
    sub_8151A9C(&sRoulette->varB8, 0xFFFF);
    sRoulette->varB8.var04[13].var00_7 = sRoulette->varB8.var04[14].var00_7 = sRoulette->varB8.var04[15].var00_7 = 0;
    gSprites[sRoulette->spriteIds[SPR_BOARD_ICONS + sGridSelections[gTasks[taskId].tWinningSquare].var00]].invisible = TRUE;
    gTasks[taskId].func = Task_TryPrintEndTurnMsg;
}

static void Task_TryPrintEndTurnMsg(u8 taskId)
{
    u8 i = 0;
    gTasks[taskId].tSelectionId = i;
    sRoulette->betSelection[sRoulette->curBallNum] = SELECTION_NONE;
    DrawGridBackground(SELECTION_NONE);
    gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].invisible = TRUE;
    for (i = 0; i < NUM_BOARD_POKES; i++)
    {
        gSprites[sRoulette->spriteIds[i + SPR_POKE_HEADER_1]].oam.tileNum =
            gSprites[sRoulette->spriteIds[i + SPR_POKE_HEADER_1]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[i + SPR_POKE_HEADER_1]].anims)->type;
    }
    if (gTasks[taskId].tCoins >= sRoulette->minBet)
    {
        if (gTasks[taskId].tBallNum == BALLS_PER_ROUND)
        {
            // Reached Ball 6, clear board
            DrawStdWindowFrame(sTextWindowId, FALSE);
            AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_BoardWillBeCleared, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(sTextWindowId, 3);
            StartTaskAfterDelayOrInput(taskId, Task_ClearBoard, 0xFFFF, A_BUTTON | B_BUTTON);
        }
        else if (gTasks[taskId].tCoins == MAX_COINS)
        {
            // Player maxed out coins
            DrawStdWindowFrame(sTextWindowId, FALSE);
            AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_CoinCaseIsFull, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(sTextWindowId, 3);
            StartTaskAfterDelayOrInput(taskId, Task_AskKeepPlaying, 0xFFFF, A_BUTTON | B_BUTTON);
        }
        else
        {
            // No special msg, ask to continue
            gTasks[taskId].func = Task_AskKeepPlaying;
        }
    }
    else
    {
        // Player out of coins
        DrawStdWindowFrame(sTextWindowId, FALSE);
        AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_NoCoinsLeft, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(sTextWindowId, 3);
        StartTaskAfterDelayOrInput(taskId, Task_StopPlaying, 60, A_BUTTON | B_BUTTON);
    }
}

static void Task_ClearBoard(u8 taskId)
{
    u8 i = 0;

    gTasks[taskId].tBallNum = 0;
    sub_8141FF4(taskId);
    ResetHits();
    HideBoardBalls();
    DrawGridBackground(SELECTION_NONE);
    SetBallCounterNumLeft(BALLS_PER_ROUND);

    for (i = 0; i < NUM_ROULETTE_SLOTS; i++)
    {
        gSprites[sRoulette->spriteIds[i + SPR_BOARD_ICONS]].invisible = FALSE;
    }

    if (gTasks[taskId].tCoins == MAX_COINS)
    {
        DrawStdWindowFrame(sTextWindowId, FALSE);
        AddTextPrinterParameterized(sTextWindowId, 1, Roulette_Text_CoinCaseIsFull, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(sTextWindowId, 3);
        StartTaskAfterDelayOrInput(taskId, Task_AskKeepPlaying, 0xFFFF, A_BUTTON | B_BUTTON);
    }
    else
    {
        gTasks[taskId].func = Task_AskKeepPlaying;
    }
}

static void ExitRoulette(u8 taskId)
{
    sub_8151A9C(&sRoulette->varB8, 0xFFFF);
    sub_8151678(&sRoulette->varB8);
    SetCoins(gTasks[taskId].tCoins);
    if (GetCoins() < sRoulette->minBet)
        gSpecialVar_0x8004 = TRUE;
    else
        gSpecialVar_0x8004 = FALSE;
    AlertTVOfNewCoinTotal(GetCoins());
    BeginHardwarePaletteFade(0xFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_ExitRoulette;
}

static void Task_ExitRoulette(u8 taskId)
{
    if (UpdatePaletteFade() == 0)
    {
        SetVBlankCallback(NULL);
        gSpriteCoordOffsetX = gSpriteCoordOffsetY = 0;
        ResetVramOamAndBgCntRegs();
        ResetAllBgsCoordinates();
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        FreeRoulette();
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void Task_WaitForNextTask(u8 taskId)
{
    if (sRoulette->taskWaitDelay == 0 || JOY_NEW(sRoulette->taskWaitKey))
    {
        gTasks[taskId].func = sRoulette->nextTask;
        if (sRoulette->taskWaitKey > 0)
            PlaySE(SE_SELECT);
        sRoulette->nextTask = NULL;
        sRoulette->taskWaitKey = 0;
        sRoulette->taskWaitDelay = 0;
    }
    if (sRoulette->taskWaitDelay != 0xFFFF)
        sRoulette->taskWaitDelay--;
}

static void StartTaskAfterDelayOrInput(u8 taskId, TaskFunc task, u16 delay, u16 key)
{
    sRoulette->varB4 = gTasks[taskId].func;
    if (task == NULL)
        task = sRoulette->varB4;
    sRoulette->nextTask = task;
    sRoulette->taskWaitDelay = delay;
    if (delay == 0xFFFF && key == 0)
        sRoulette->taskWaitKey = 0xFFFF;
    else
        sRoulette->taskWaitKey = key;
    gTasks[taskId].func = Task_WaitForNextTask;
}

static void sub_8141FF4(u8 taskId)
{
    u8 i = 0;
    sRoulette->var00 = i;
    sRoulette->var03_7 = FALSE;
    sRoulette->var03_5 = FALSE;
    sRoulette->var03_6 = FALSE;
    sRoulette->useTaillow = FALSE;

    for (i = 0; i < BALLS_PER_ROUND; i++)
        sRoulette->betSelection[i] = SELECTION_NONE;

    sRoulette->curBallNum = 0;
    gTasks[taskId].data[1] = 0;
}

static void ResetHits(void)
{
    u8 i;
    sRoulette->hitFlags = 0;

    for (i = 0; i < BALLS_PER_ROUND; i++)
        sRoulette->hitSquares[i] = 0;

    for (i = 0; i < NUM_BOARD_POKES; i++)
        sRoulette->pokeHits[i] = 0;

    for (i = 0; i < NUM_BOARD_COLORS; i++)
        sRoulette->colorHits[i] = 0;

    ShowHideGridBalls(TRUE, -1);
}

static u8 RecordHit(u8 taskId, u8 slotId)
{
    u8 i, j;
    u32 columnFlags[NUM_BOARD_POKES] = {
        F_WYNAUT_COL | F_ORANGE_WYNAUT | F_GREEN_WYNAUT | F_PURPLE_WYNAUT, 
        F_AZURILL_COL | F_ORANGE_AZURILL | F_GREEN_AZURILL | F_PURPLE_AZURILL, 
        F_SKITTY_COL | F_ORANGE_SKITTY | F_GREEN_SKITTY | F_PURPLE_SKITTY, 
        F_MAKUHITA_COL | F_ORANGE_MAKUHITA | F_GREEN_MAKUHITA | F_PURPLE_MAKUHITA
    };
    u32 rowFlags[NUM_BOARD_COLORS] = {
        F_ORANGE_ROW | F_ORANGE_WYNAUT | F_ORANGE_AZURILL | F_ORANGE_SKITTY | F_ORANGE_MAKUHITA, 
        F_GREEN_ROW | F_GREEN_WYNAUT | F_GREEN_AZURILL | F_GREEN_SKITTY | F_GREEN_MAKUHITA, 
        F_PURPLE_ROW | F_PURPLE_WYNAUT | F_PURPLE_AZURILL | F_PURPLE_SKITTY | F_PURPLE_MAKUHITA
    };

    if (slotId >= NUM_ROULETTE_SLOTS)
        return 0;

    sRoulette->hitSquares[gTasks[taskId].tBallNum - 1] = sRouletteSlots[slotId].gridSquare;
    gTasks[taskId].tWinningSquare = sRouletteSlots[slotId].gridSquare;
    sRoulette->hitFlags |= sRouletteSlots[slotId].flag;
    for (i = 0; i < NUM_BOARD_POKES; i++)
    {
        if (sRouletteSlots[slotId].flag & columnFlags[i])
            sRoulette->pokeHits[i]++;
        // If hit every color of a poke, set column completed
        if (sRoulette->pokeHits[i] >= NUM_BOARD_COLORS)
            sRoulette->hitFlags |= columnFlags[i];
    }
    for (j = 0; j < NUM_BOARD_COLORS; j++)
    {
        if (sRouletteSlots[slotId].flag & rowFlags[j])
            sRoulette->colorHits[j]++;
        // If hit every poke of a color, set row completed
        if (sRoulette->colorHits[j] >= NUM_BOARD_POKES)
            sRoulette->hitFlags |= rowFlags[j];
    }
    return sRouletteSlots[slotId].gridSquare;
}

static bool8 IsHitInBetSelection(u8 gridSquare, u8 betSelection)
{
    u8 hit = gridSquare;
    if (--gridSquare < NUM_GRID_SELECTIONS)
    {
        switch (betSelection)
        {
        case SELECTION_NONE:
            return 3; // should never happen, player must place bet
        case COL_WYNAUT:
        case COL_AZURILL:
        case COL_SKITTY:
        case COL_MAKUHITA:
            if (hit == betSelection + ROW_ORANGE 
             || hit == betSelection + ROW_GREEN 
             || hit == betSelection + ROW_PURPLE)
                return TRUE;
            break;
        case ROW_ORANGE:
        case ROW_GREEN:
        case ROW_PURPLE:
            if (hit >= (betSelection + COL_WYNAUT) 
             && hit <= (betSelection + COL_MAKUHITA))
                return TRUE;
            break;
        // Individual square
        default:
            if (hit == betSelection)
                return TRUE;
        }
    }
    return FALSE;
}

static void FlashSelectionOnWheel(u8 selectionId)
{
    u16 var0 = 0;
    u8 var2;
    u16 var3;
    u8 i;

    switch (selectionId)
    {
    case ROW_ORANGE:
    case ROW_GREEN:
    case ROW_PURPLE:
        for (i = (selectionId + 1); i < (selectionId + 5); i++)
        {
            if (!(sRoulette->hitFlags & sGridSelections[i].flag))
                var0 |= sGridSelections[i].var10;
        }
        sub_8151A48(&sRoulette->varB8, var0 &= 0xDFFF);
        break;
    default:
    {
        struct UnkStruct1 var1[3];
        memcpy(var1, gUnknown_085B63F0, sizeof(var1));
        if (selectionId >= COL_WYNAUT && selectionId <= COL_MAKUHITA)
            var2 = 3;
        else
            var2 = 1;

        var3 = selectionId / 5 - 1;
        switch (GET_COL(selectionId))
        {
        // The specific color of the poke it references doesn't matter, because the icons themelves all share a palette
        // So it just uses the first sprite ID of each
        case COL_WYNAUT:
            var3 = gSprites[sRoulette->spriteIds[SPR_BOARD_ICON_ORANGE_WYNAUT]].oam.paletteNum * 16;
            break;
        case COL_AZURILL:
            var3 = gSprites[sRoulette->spriteIds[SPR_BOARD_ICON_GREEN_AZURILL]].oam.paletteNum * 16;
            break;
        case COL_SKITTY:
            var3 = gSprites[sRoulette->spriteIds[SPR_BOARD_ICON_PURPLE_SKITTY]].oam.paletteNum * 16;
            break;
        case COL_MAKUHITA:
            var3 = gSprites[sRoulette->spriteIds[SPR_BOARD_ICON_ORANGE_MAKUHITA]].oam.paletteNum * 16;
            break;
        }
        if (var2 == 1)
        {
            if (!(sRoulette->hitFlags & sGridSelections[selectionId].flag))
            {
                var1[selectionId / 5 - 1].var02 += var3;
                sub_815168C(&sRoulette->varB8, 13, &var1[selectionId / 5 - 1]);
            }
            else
            {
                break;
            }
        }
        else
        {
            for (i = 0; i < 3; i++)
            {
                u8 var4 = i * 5 + selectionId + 5;
                if (!(sRoulette->hitFlags & sGridSelections[var4].flag))
                {
                    var1[var4 / 5 - 1].var02 += var3;
                    sub_815168C(&sRoulette->varB8, i + 13, &var1[var4 / 5 - 1]);
                    if (var2 == 3)
                        var0 = sGridSelections[var4].var10;
                    var2--;
                }
            }
            if (var2 != 2)
                var0 = 0;
        }
        sub_8151A48(&sRoulette->varB8, var0 |= sGridSelections[selectionId].var10);
        break;
    }
    }
}

static void DrawGridBackground(u8 selectionId)
{
    vu8 i;
    vu8 z;
    vu16 var1;
    vu16 var2;
    vu8 var0;
    u8 v[5];
    u8 l;
    sRoulette->var2A = 1;
    ShowHideGridIcons(FALSE, 0);
    SetGridSelectionRect(sRoulette->tilemapBuffers[2], sRoulette->unk_397C, 14, 7, 16, 13);
    switch (selectionId)
    {
    case SELECTION_NONE:
        return;
    case COL_WYNAUT:
    case COL_AZURILL:
    case COL_SKITTY:
    case COL_MAKUHITA:
        l = 4;
        for (i = 0; i < l; i++)
        {
            v[i] = i * 5 + selectionId;
        }
        break;
    case ROW_ORANGE:
    case ROW_GREEN:
    case ROW_PURPLE:
        l = 5;
        for (i = 0; i < l; i++)
        {
            v[i] = i + selectionId;
        }
        break;
    // Individual square
    default:
        l = 1;
        v[0] = selectionId;
    }
    for (i = 0; i < l; i++)
    {
        var0 = sGridSelections[v[i]].var06;
        var1 = sGridSelections[v[i]].x;
        for (z = 0; z < 3; z++)
        {
            var2 = (sGridSelections[v[i]].y + z) * 32;
            sRoulette->tilemapBuffers[2][var1 + var2 + 0] = sRoulette->unk_397C[(var0 + z) * 3 + 208];
            sRoulette->tilemapBuffers[2][var1 + var2 + 1] = sRoulette->unk_397C[(var0 + z) * 3 + 209];
            sRoulette->tilemapBuffers[2][var1 + var2 + 2] = sRoulette->unk_397C[(var0 + z) * 3 + 210];
        }
    }
}

static u8 GetMultiplier(u8 selectionId)
{
    u8 multipliers[5] = {0, 3, 4, 6, 12};

    if (selectionId > NUM_GRID_SELECTIONS)
        selectionId = 0;

    switch (sGridSelections[selectionId].baseMultiplier)
    {
    case NUM_BOARD_COLORS:
        selectionId = selectionId / 5 - 1;
        // If already hit all pokes of this color, multiplier is 0
        if (sRoulette->colorHits[selectionId] >= NUM_BOARD_POKES)
            return 0;
        return multipliers[sRoulette->colorHits[selectionId] + 1];
    case NUM_BOARD_POKES:
        selectionId--;
        // If already hit all colors of this poke, multiplier is 0
        if (sRoulette->pokeHits[selectionId] >= NUM_BOARD_COLORS)
            return 0;
        return multipliers[sRoulette->pokeHits[selectionId] + 2];
    case NUM_ROULETTE_SLOTS:
        // If square has been hit already, multiplier is 0
        if (sRoulette->hitFlags & sGridSelections[selectionId].flag)
            return 0;
        return multipliers[4];
    }
    return 0;
}

static void sub_8142814(void)
{
    s32 x1;
    s32 x2;
    SetGpuReg(REG_OFFSET_BG2PA, sRoulette->var2C.a);
    SetGpuReg(REG_OFFSET_BG2PB, sRoulette->var2C.b);
    SetGpuReg(REG_OFFSET_BG2PC, sRoulette->var2C.c);
    SetGpuReg(REG_OFFSET_BG2PD, sRoulette->var2C.d);
    x1 = 0x7400 - sRoulette->var2C.a * (gSpriteCoordOffsetX + 116)
                - sRoulette->var2C.b * (gSpriteCoordOffsetY + 80);
    x2 = 0x5400 - sRoulette->var2C.c * (gSpriteCoordOffsetX + 116)
                - sRoulette->var2C.d * (gSpriteCoordOffsetY + 80);
    SetGpuReg(REG_OFFSET_BG2X_L, x1);
    SetGpuReg(REG_OFFSET_BG2X_H, (x1 & 0x0fff0000) >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, x2);
    SetGpuReg(REG_OFFSET_BG2Y_H, (x2 & 0x0fff0000) >> 16);
}

static const u8 sFiller[3] = {};
static const u16 sShadow_Pal[] = INCBIN_U16("graphics/roulette/shadow.gbapal");
static const u16 sBall_Pal[] = INCBIN_U16("graphics/roulette/ball.gbapal");
static const u16 sBallCounter_Pal[] = INCBIN_U16("graphics/roulette/ball_counter.gbapal");
static const u16 sCursor_Pal[] = INCBIN_U16("graphics/roulette/cursor.gbapal");
static const u16 sCredit_Pal[] = INCBIN_U16("graphics/roulette/credit.gbapal");
static const u16 sShroomish_Pal[] = INCBIN_U16("graphics/roulette/shroomish.gbapal");
static const u16 sTaillow_Pal[] = INCBIN_U16("graphics/roulette/tailow.gbapal");
static const u16 sGridIcons_Pal[] = INCBIN_U16("graphics/roulette/grid_icons.gbapal");
static const u16 sWynaut_Pal[] = INCBIN_U16("graphics/roulette/wynaut.gbapal");
static const u16 sAzurill_Pal[] = INCBIN_U16("graphics/roulette/azurill.gbapal");
static const u16 sSkitty_Pal[] = INCBIN_U16("graphics/roulette/skitty.gbapal");
static const u16 sMakuhita_Pal[] = INCBIN_U16("graphics/roulette/makuhita.gbapal");
static const u16 sUnused1_Pal[] = INCBIN_U16("graphics/roulette/unused_1.gbapal");
static const u16 sUnused2_Pal[] = INCBIN_U16("graphics/roulette/unused_2.gbapal");
static const u16 sUnused3_Pal[] = INCBIN_U16("graphics/roulette/unused_3.gbapal");
static const u16 sUnused4_Pal[] = INCBIN_U16("graphics/roulette/unused_4.gbapal");
static const u32 sBall_Gfx[] = INCBIN_U32("graphics/roulette/ball.4bpp.lz");
static const u32 sBallCounter_Gfx[] = INCBIN_U32("graphics/roulette/ball_counter.4bpp.lz");
static const u32 sShroomishTaillow_Gfx[] = INCBIN_U32("graphics/roulette/roulette_tilt.4bpp.lz");
static const u32 sGridIcons_Gfx[] = INCBIN_U32("graphics/roulette/grid_icons.4bpp.lz");
static const u32 sBoardIcons_Gfx[] = INCBIN_U32("graphics/roulette/board_icons.4bpp.lz");
static const u32 sShadow_Gfx[] = INCBIN_U32("graphics/roulette/shadow.4bpp.lz");
static const u32 sCursor_Gfx[] = INCBIN_U32("graphics/roulette/cursor.4bpp.lz");

static const struct SpritePalette sSpritePalettes[] =
{
    { .data = sShadow_Pal,      .tag = PALTAG_SHADOW },
    { .data = sBall_Pal,        .tag = PALTAG_BALL },
    { .data = sBallCounter_Pal, .tag = PALTAG_BALL_COUNTER },
    { .data = sCursor_Pal,      .tag = 4 },
    { .data = sCredit_Pal,      .tag = PALTAG_INTERFACE },
    { .data = sShroomish_Pal,   .tag = PALTAG_SHROOMISH },
    { .data = sTaillow_Pal,     .tag = PALTAG_TAILLOW },
    { .data = sGridIcons_Pal,   .tag = PALTAG_GRID_ICONS },
    { .data = sWynaut_Pal,      .tag = PALTAG_WYNAUT },
    { .data = sAzurill_Pal,     .tag = PALTAG_AZURILL },
    { .data = sSkitty_Pal,      .tag = PALTAG_SKITTY },
    { .data = sMakuhita_Pal,    .tag = PALTAG_MAKUHITA },
    {}
};

static const struct OamData gOamData_85B73EC =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct OamData sOam_GridIcon =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const struct OamData sOam_BoardIcon =
{
    .y = 60,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 2,
};

static const union AnimCmd sAffineAnim_Unused1[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAffineAnims_Unused1[] =
{
    sAffineAnim_Unused1
};

static const union AffineAnimCmd sAffineAnim_Unused2[] =
{
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Unused2[] =
{
    sAffineAnim_Unused2
};

static const struct CompressedSpriteSheet sSpriteSheet_BoardIcons =
{
    .data = sBoardIcons_Gfx,
    .size = 0xC00,
    .tag = GFXTAG_BOARD_ICONS
};

static const union AnimCmd sAnim_BoardIcons[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_FRAME(72, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(40, 0),
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_FRAME(56, 0),
    ANIMCMD_FRAME(88, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnim_BoardIcon_OrangeWynaut[] =
{
    &sAnim_BoardIcons[0]
};

static const union AnimCmd *const sAnim_BoardIcon_GreenAzurill[] =
{
    &sAnim_BoardIcons[1]
};

static const union AnimCmd *const sAnim_BoardIcon_PurpleSkitty[] =
{
    &sAnim_BoardIcons[2]
};

static const union AnimCmd *const sAnim_BoardIcon_OrangeMakuhita[] =
{
    &sAnim_BoardIcons[3]
};

static const union AnimCmd *const sAnim_BoardIcon_GreenWynaut[] =
{
    &sAnim_BoardIcons[4]
};

static const union AnimCmd *const sAnim_BoardIcon_PurpleAzurill[] =
{
    &sAnim_BoardIcons[5]
};

static const union AnimCmd *const sAnim_BoardIcon_OrangeSkitty[] =
{
    &sAnim_BoardIcons[6]
};

static const union AnimCmd *const sAnim_BoardIcon_GreenMakuhita[] =
{
    &sAnim_BoardIcons[7]
};

static const union AnimCmd *const sAnim_BoardIcon_PurpleWynaut[] =
{
    &sAnim_BoardIcons[8]
};

static const union AnimCmd *const sAnim_BoardIcon_OrangeAzurill[] =
{
    &sAnim_BoardIcons[9]
};

static const union AnimCmd *const sAnim_BoardIcon_GreenSkitty[] =
{
    &sAnim_BoardIcons[10]
};

static const union AnimCmd *const sAnim_BoardIcon_PurpleMakuhita[] =
{
    &sAnim_BoardIcons[11]
};

static const struct CompressedSpriteSheet sSpriteSheet_Headers =
{
    .data = gRouletteHeaders_Gfx,
    .size = 0x1600,
    .tag = GFXTAG_HEADERS
};

static const struct CompressedSpriteSheet sSpriteSheet_PokeIcons =
{
    .data = sGridIcons_Gfx,
    .size = 0x400,
    .tag = GFXTAG_GRID_ICONS
};

static const union AnimCmd sAnim_Headers[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_FRAME(112, 0),
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_FRAME(144, 0),
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_GridIcons[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnim_WynautHeader[] =
{
    &sAnim_Headers[0]
};

static const union AnimCmd *const sAnim_AzurillHeader[] =
{
    &sAnim_Headers[2]
};

static const union AnimCmd *const sAnim_SkittyHeader[] =
{
    &sAnim_Headers[4]
};

static const union AnimCmd *const sAnim_MakuhitaHeader[] =
{
    &sAnim_Headers[6]
};

static const union AnimCmd *const sAnim_OrangeHeader[] =
{
    &sAnim_Headers[8]
};

static const union AnimCmd *const sAnim_GreenHeader[] =
{
    &sAnim_Headers[9]
};

static const union AnimCmd *const sAnim_PurpleHeader[] =
{
    &sAnim_Headers[10]
};

static const union AnimCmd *const sAnim_GridIcon_Wynaut[] =
{
    &sAnim_GridIcons[0]
};

static const union AnimCmd *const sAnim_GridIcon_Azurill[] =
{
    &sAnim_GridIcons[1]
};

static const union AnimCmd *const sAnim_GridIcon_Skitty[] =
{
    &sAnim_GridIcons[2]
};

static const union AnimCmd *const sAnim_GridIcon_Makuhita[] =
{
    &sAnim_GridIcons[3]
};

static const struct SpriteTemplate sSpriteTemplates_PokeHeaders[NUM_BOARD_POKES] =
{
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_WynautHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_AzurillHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_SkittyHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_MakuhitaHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    }
};

static const struct SpriteTemplate sSpriteTemplates_ColorHeaders[NUM_BOARD_COLORS] =
{
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_OrangeHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_GreenHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &gOamData_85B73EC,
        .anims = sAnim_PurpleHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    }
};

static const struct SpriteTemplate sSpriteTemplate_GridIcons[NUM_BOARD_POKES] =
{
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Wynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Azurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Skitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    },
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Makuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_GridSquare
    }
};

// Board icons are listed clockwise starting from 1 oclock on the roulette board (with pokeball upside right)
// They go Wynaut -> Azurill -> Skitty -> Makuhita, and Orange -> Green -> Purple
static const struct SpriteTemplate sSpriteTemplates_BoardIcons[NUM_ROULETTE_SLOTS] =
{
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_WYNAUT,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_OrangeWynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_AZURILL,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_GreenAzurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_SKITTY,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_PurpleSkitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_MAKUHITA,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_OrangeMakuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_WYNAUT,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_GreenWynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_AZURILL,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_PurpleAzurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_SKITTY,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_OrangeSkitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_MAKUHITA,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_GreenMakuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_WYNAUT,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_PurpleWynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_AZURILL,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_OrangeAzurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_SKITTY,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_GreenSkitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    },
    {
        .tileTag = GFXTAG_BOARD_ICONS,
        .paletteTag = PALTAG_MAKUHITA,
        .oam = &sOam_BoardIcon,
        .anims = sAnim_BoardIcon_PurpleMakuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_BoardIcon
    }
};

static const struct OamData sOam_Credit =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1,
};

static const struct OamData sOam_CreditDigit =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 1,
};

static const struct OamData sOam_Multiplier =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1,
};

static const struct OamData sOam_BallCounter =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x8),
    .size = SPRITE_SIZE(16x8),
    .priority = 1,
};

static const struct CompressedSpriteSheet sSpriteSheets_Interface[] =
{
    {
        .data = gRouletteCredit_Gfx,
        .size = 0x400,
        .tag = GFXTAG_CREDIT
    },
    {
        .data = gRouletteNumbers_Gfx,
        .size = 0x280,
        .tag = GFXTAG_CREDIT_DIGIT
    },
    {
        .data = gRouletteMultiplier_Gfx,
        .size = 0x500,
        .tag = GFXTAG_MULTIPLIER
    },
    {
        .data = sBallCounter_Gfx,
        .size = 0x140,
        .tag = GFXTAG_BALL_COUNTER
    },
    {
        .data = sCursor_Gfx,
        .size = 0x200,
        .tag = GFXTAG_CURSOR
    },
    {}
};

static const union AnimCmd gSpriteAnim_85B7780[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(10, 0),
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_FRAME(14, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(18, 0),
    // BUG: Animation not terminated properly
    //ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B77A8[] =
{
    gSpriteAnim_85B7780
};

static const union AnimCmd sAnim_Multiplier[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Multiplier[] =
{
    sAnim_Multiplier
};

static const union AnimCmd sAnim_BallCounter[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_BallCounter[] =
{
    sAnim_BallCounter
};

static const struct SpriteTemplate sSpriteTemplate_Credit =
{
    .tileTag = GFXTAG_CREDIT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Credit,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_CreditDigit =
{
    .tileTag = GFXTAG_CREDIT_DIGIT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_CreditDigit,
    .anims = gSpriteAnimTable_85B77A8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Multiplier =
{
    .tileTag = GFXTAG_MULTIPLIER,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Multiplier,
    .anims = sAnims_Multiplier,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GridSquare
};

static const struct SpriteTemplate sSpriteTemplate_BallCounter =
{
    .tileTag = GFXTAG_BALL_COUNTER,
    .paletteTag = PALTAG_BALL_COUNTER,
    .oam = &sOam_BallCounter,
    .anims = sAnims_BallCounter,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

// NOTE: This cursor is only used to identify the winning square on the grid
static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &gOamData_85B73EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_Ball =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_Ball = {
    .data = sBall_Gfx,
    .size = 0x200,
    .tag = GFXTAG_BALL
};

static const union AnimCmd gSpriteAnim_85B786C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B7880[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(8, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B7894[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(4, 15),
    ANIMCMD_FRAME(8, 15),
    ANIMCMD_FRAME(4, 15),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B78A8[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78BC[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78D4[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78E8[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B78F0[] =
{
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Ball[] =
{
    gSpriteAnim_85B786C,
    gSpriteAnim_85B7880,
    gSpriteAnim_85B7894,
    gSpriteAnim_85B78A8,
    gSpriteAnim_85B78F0,
    gSpriteAnim_85B78BC,
    gSpriteAnim_85B78D4,
    gSpriteAnim_85B78D4,
    gSpriteAnim_85B78E8
};

static const struct SpriteTemplate sSpriteTemplate_Ball =
{
    .tileTag = GFXTAG_BALL,
    .paletteTag = PALTAG_BALL,
    .oam = &sOam_Ball,
    .anims = sAnims_Ball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_BoardCenter =
{
    .y = 81,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_BoardCenter =
{
    .data = gRouletteCenter_Gfx,
    .size = 0x800,
    .tag = GFXTAG_BOARD_CENTER
};

static const struct SpriteTemplate sSpriteTemplate_BoardCenter =
{
    .tileTag = GFXTAG_BOARD_CENTER,
    .paletteTag = PALTAG_BALL,
    .oam = &sOam_BoardCenter,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_BoardCenter
};

static const struct OamData sOam_Shroomish =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const struct OamData sOam_Taillow =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_ShroomishTaillow =
{
    .data = sShroomishTaillow_Gfx,
    .size = 0xE00,
    .tag = GFXTAG_SHROOMISH_TAILLOW
};

static const union AnimCmd sAnim_Shroomish[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_JUMP(2)
};

static const union AnimCmd gSpriteAnim_85B799C[] =
{
    ANIMCMD_FRAME(80, 10),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B79A4[] =
{
    ANIMCMD_FRAME(80, 10, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B79AC[] =
{
    ANIMCMD_FRAME(80, 20),
    ANIMCMD_FRAME(96, 20),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B79B8[] =
{
    ANIMCMD_FRAME(80, 20, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 20, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B79C4[] =
{
    ANIMCMD_FRAME(80, 10),
    ANIMCMD_FRAME(96, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd gSpriteAnim_85B79D0[] =
{
    ANIMCMD_FRAME(80, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 10, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Shroomish[] =
{
    sAnim_Shroomish
};

static const union AnimCmd *const sAnims_Taillow[] =
{
    gSpriteAnim_85B799C,
    gSpriteAnim_85B79A4,
    gSpriteAnim_85B79AC,
    gSpriteAnim_85B79B8,
    gSpriteAnim_85B79C4,
    gSpriteAnim_85B79D0
};

static const struct SpriteTemplate sSpriteTemplate_Shroomish =
{
    .tileTag = GFXTAG_SHROOMISH_TAILLOW,
    .paletteTag = PALTAG_SHROOMISH,
    .oam = &sOam_Shroomish,
    .anims = sAnims_Shroomish,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Taillow =
{
    .tileTag = GFXTAG_SHROOMISH_TAILLOW,
    .paletteTag = PALTAG_TAILLOW,
    .oam = &sOam_Taillow,
    .anims = sAnims_Taillow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Taillow
};

static const struct OamData gOamData_85B7A28 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const struct OamData gOamData_85B7A30 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

static const struct OamData sOam_TaillowShadow =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_Shadow =
{
    .data = sShadow_Gfx,
    .size = 0x180,
    .tag = GFXTAG_SHADOW
};

static const union AffineAnimCmd gSpriteAffineAnim_85B7A48[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(2,    2,    0, 60),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_TaillowShadow[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-2,    0x0,   0, 15),
    AFFINEANIMCMD_FRAME(-1,    -2,    0, 15),
    AFFINEANIMCMD_FRAME(-1,    -5,    0, 24),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_85B7A88[] =
{
    gSpriteAffineAnim_85B7A48
};

static const union AffineAnimCmd *const sAffineAnims_TaillowShadow[] =
{
    sAffineAnim_TaillowShadow
};

static const union AffineAnimCmd gSpriteAffineAnim_85B7A90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_85B7AA0[] =
{
    gSpriteAffineAnim_85B7A90
};

static const union AnimCmd gSpriteAnim_85B7AA4[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_85B7AAC[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_85B7AB4[] =
{
    gSpriteAnim_85B7AA4
};

static const union AnimCmd *const gSpriteAnimTable_85B7AB8[] =
{
    gSpriteAnim_85B7AAC
};

static const struct SpriteTemplate sSpriteTemplate_ShroomishShadow[] =
{
    {
        .tileTag = GFXTAG_SHADOW,
        .paletteTag = PALTAG_SHADOW,
        .oam = &gOamData_85B7A28,
        .anims = gSpriteAnimTable_85B7AB4,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = GFXTAG_SHADOW,
        .paletteTag = PALTAG_SHADOW,
        .oam = &gOamData_85B7A30,
        .anims = gSpriteAnimTable_85B7AB8,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_8144E60
    }
};

static const struct SpriteTemplate sSpriteTemplate_TaillowShadow =
{
    .tileTag = GFXTAG_SHADOW,
    .paletteTag = PALTAG_SHADOW,
    .oam = &sOam_TaillowShadow,
    .anims = gSpriteAnimTable_85B7AB8,
    .images = NULL,
    .affineAnims = sAffineAnims_TaillowShadow,
    .callback = SpriteCB_Taillow
};

static void Task_ShowMinBetYesNo(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    DoYesNoFuncWithChoice(taskId, &sYesNoTable_AcceptMinBet);
}

static void Task_FadeToRouletteGame(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        SetMainCallback2(CB2_LoadRoulette);
        DestroyTask(taskId);
    }
}

static void Task_AcceptMinBet(u8 taskId)
{
    ClearStdWindowAndFrame(0, TRUE);
    HideCoinsWindow();
    FreeAllWindowBuffers();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gPaletteFade.delayCounter = gPaletteFade.multipurpose2;
    UpdatePaletteFade();
    gTasks[taskId].func = Task_FadeToRouletteGame;
}

static void Task_DeclineMinBet(u8 taskId)
{
    ClearStdWindowAndFrame(0, FALSE);
    HideCoinsWindow();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

static void Task_NotEnoughForMinBet(u8 taskId)
{
    gTasks[taskId].data[0]++;
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        gSpecialVar_0x8004 = 1;
        HideCoinsWindow();
        ClearStdWindowAndFrame(0, TRUE);
        ScriptContext2_Disable();
        DestroyTask(taskId);
    }
}

static void Task_PrintMinBet(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        u32 minBet = sTableMinBets[GET_TABLE_ID(gSpecialVar_0x8004)];
        ConvertIntToDecimalStringN(gStringVar1, minBet, STR_CONV_MODE_LEADING_ZEROS, 1);
        StringExpandPlaceholders(gStringVar4, Roulette_Text_PlayMinimumWagerIsX);
        DrawStdWindowFrame(0, FALSE);
        AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = Task_ShowMinBetYesNo;
    }
}

static void Task_PrintRouletteEntryMsg(u8 taskId)
{
    s32 minBet;
    PrintCoinsString(gTasks[taskId].tCoins);
    minBet = sTableMinBets[GET_TABLE_ID(gSpecialVar_0x8004)];
    ConvertIntToDecimalStringN(gStringVar1, minBet, STR_CONV_MODE_LEADING_ZEROS, 1);
    
    if (gTasks[taskId].tCoins >= minBet)
    {
        if ((gSpecialVar_0x8004 & ROULETTE_SPECIAL_RATE) && (gSpecialVar_0x8004 & 1))
        {
            // Special rate for Game Corner service day (only at second table)
            DrawStdWindowFrame(0, FALSE);
            AddTextPrinterParameterized(0, 1, Roulette_Text_SpecialRateTable, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = Task_PrintMinBet;
        }
        else
        {
            // Print minimum bet
            StringExpandPlaceholders(gStringVar4, Roulette_Text_PlayMinimumWagerIsX);
            DrawStdWindowFrame(0, FALSE);
            AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
            CopyWindowToVram(0, 3);
            gTasks[taskId].func = Task_ShowMinBetYesNo;
        }
    }
    else
    {
        // Not enough for minimum bet
        StringExpandPlaceholders(gStringVar4, Roulette_Text_NotEnoughCoins);
        DrawStdWindowFrame(0, FALSE);
        AddTextPrinterParameterized(0, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = Task_NotEnoughForMinBet;
        gTasks[taskId].tCoins = 0;
        gTasks[taskId].data[0] = 0;
    }
}

void PlayRoulette(void)
{
    u8 taskId;

    ScriptContext2_Enable();
    ShowCoinsWindow(GetCoins(), 1, 1);
    taskId = CreateTask(Task_PrintRouletteEntryMsg, 0);
    gTasks[taskId].tCoins = GetCoins();
}

static void LoadOrFreeMiscSpritePalettesAndSheets(bool8 free)
{
    if (!free)
    {
        FreeAllSpritePalettes();
        LoadSpritePalettes(sSpritePalettes);
        LoadCompressedSpriteSheet(&sSpriteSheet_Ball);
        LoadCompressedSpriteSheet(&sSpriteSheet_ShroomishTaillow);
        LoadCompressedSpriteSheet(&sSpriteSheet_Shadow);
    }
    else
    {
        // Unused
        FreeSpriteTilesByTag(GFXTAG_SHADOW);
        FreeSpriteTilesByTag(GFXTAG_SHROOMISH_TAILLOW);
        FreeSpriteTilesByTag(GFXTAG_BALL);
        FreeAllSpritePalettes();
    }
}

static u8 CreateBoardIconSprite(const struct SpriteTemplate *r0, u8 r1, u16 *r2)
{
    u16 temp;
    u8 spriteId = CreateSprite(r0, 116, 80, r0->oam->y);
    gSprites[spriteId].data[0] = *r2;
    gSprites[spriteId].data[1] = r1;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].affineAnimPaused = TRUE;
    temp = *r2;
    *r2 += 30;
    if (*r2 >= 360)
        *r2 = temp - 330;
    return spriteId;
}

static void CreateGridSprites(void)
{
    u8 i, j;
    u8 spriteId;
    struct SpriteSheet s;
    LZ77UnCompWram(sSpriteSheet_Headers.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = sSpriteSheet_Headers.size;
    s.tag  = sSpriteSheet_Headers.tag;
    LoadSpriteSheet(&s);
    LZ77UnCompWram(sSpriteSheet_PokeIcons.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = sSpriteSheet_PokeIcons.size;
    s.tag  = sSpriteSheet_PokeIcons.tag;
    LoadSpriteSheet(&s);
    for (i = 0; i < NUM_BOARD_COLORS; i++)
    {
        u8 o = i * 24;
        for (j = 0; j < NUM_BOARD_POKES; j++)
        {
            spriteId = sRoulette->spriteIds[(i * NUM_BOARD_POKES) + SPR_GRID_ICONS + j] = CreateSprite(&sSpriteTemplate_GridIcons[j], (j * 24) + 148, o + 92, 30);
            gSprites[spriteId].animPaused = TRUE;
            o += 24;
            if (o >= 72)
                o = 0;
        }
    }
    for (i = 0; i < ARRAY_COUNT(sSpriteTemplates_PokeHeaders); i++)
    {
        spriteId = sRoulette->spriteIds[i + SPR_POKE_HEADER_1] = CreateSprite(&sSpriteTemplates_PokeHeaders[i], (i * 24) + 148, 70, 30);
        gSprites[spriteId].animPaused = TRUE;
    }
    for (i = 0; i < ARRAY_COUNT(sSpriteTemplates_ColorHeaders); i++)
    {
        spriteId = sRoulette->spriteIds[i + SPR_COLOR_HEADER_1] = CreateSprite(&sSpriteTemplates_ColorHeaders[i], 126, (i * 24) + 92, 30);
        gSprites[spriteId].animPaused = TRUE;
    }
}

// Unused
static void DestroyGridSprites(void)
{
    u8 i;
    for (i = 0; i < NUM_ROULETTE_SLOTS; i++)
    {
        DestroySprite(&gSprites[sRoulette->spriteIds[i + SPR_GRID_ICONS]]);
    }
}

static void ShowHideGridIcons(bool8 hideAll, u8 hideSquare)
{
    u8 i;
    switch (hideAll)
    {
    case TRUE:
        // Hide grid icons and headers
        for (i = 0; i < NUM_GRID_SELECTIONS; i++)
        {
            gSprites[sRoulette->spriteIds[i + SPR_GRID_ICONS]].invisible = TRUE;
        }
        break;
    case FALSE:
        for (i = 0; i < NUM_ROULETTE_SLOTS; i++)
        {
            if (!(sRoulette->hitFlags & sRouletteSlots[i].flag))
                gSprites[sRoulette->spriteIds[i + SPR_GRID_ICONS]].invisible = FALSE;
            else if (sRouletteSlots[i].gridSquare != hideSquare)
                gSprites[sRoulette->spriteIds[i + SPR_GRID_ICONS]].invisible = TRUE;
            else
                gSprites[sRoulette->spriteIds[i + SPR_GRID_ICONS]].invisible = FALSE;
        }
        // Always show grid headers
        for (; i < NUM_GRID_SELECTIONS; i++)
        {
            gSprites[sRoulette->spriteIds[i + SPR_GRID_ICONS]].invisible = FALSE;
        }
        break;
    }
}

static void CreateGridBallSprites(void)
{
    u8 i;
    for (i = 0; i < BALLS_PER_ROUND; i++)
    {
        sRoulette->spriteIds[i + SPR_GRID_BALL_1] = CreateSprite(&sSpriteTemplate_Ball, 116, 20, 10);
        gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].invisible = TRUE;
        gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].data[0] = 1;
        gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].callback = SpriteCB_GridSquare;
        gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].oam.priority = 1;
        StartSpriteAnim(&gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]], 8);
    }
}

static void ShowHideGridBalls(bool8 hideAll, u8 hideBallId)
{
    u8 i = 0;
    if (hideAll)
    {
        for (; i < BALLS_PER_ROUND; i++)
        {
            gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].invisible = TRUE;
        }
    }
    else
    {
        for (; i < BALLS_PER_ROUND; i++)
        {
            if (!sRoulette->hitSquares[i] || i == hideBallId)
            {
                gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].invisible = TRUE;
            }
            else
            {
                gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].invisible = FALSE;
                gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].pos1.x = (sGridSelections[sRoulette->hitSquares[i]].x + 1) * 8 + 4;
                gSprites[sRoulette->spriteIds[i + SPR_GRID_BALL_1]].pos1.y = (sGridSelections[sRoulette->hitSquares[i]].y + 1) * 8 + 3;
            }
        }
    }
}

static void ShowHideWinSlotCursor(u8 selectionId)
{
    if (selectionId == 0)
    {
        gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].invisible = TRUE;
    }
    else
    {
        gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].invisible = FALSE;
        gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].pos1.x = (sGridSelections[selectionId].x + 2) * 8;
        gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].pos1.y = (sGridSelections[selectionId].y + 2) * 8;
    }
}

static void CreateBoardIconSprites(void)
{
    u8 i, j;
    u16 k;
    struct SpriteSheet s;

    LZ77UnCompWram(sSpriteSheet_BoardIcons.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = sSpriteSheet_BoardIcons.size;
    s.tag  = sSpriteSheet_BoardIcons.tag;
    LoadSpriteSheet(&s);

    k = 15;
    for (i = 0; i < NUM_BOARD_COLORS; i++)
    {
        for (j = 0; j < NUM_BOARD_POKES; j++)
        {
            u8 spriteId;
            spriteId = sRoulette->spriteIds[(i * NUM_BOARD_POKES) + SPR_BOARD_ICONS + j] = CreateBoardIconSprite(&sSpriteTemplates_BoardIcons[i * NUM_BOARD_POKES + j], 40, &k);
            gSprites[spriteId].animPaused = TRUE;
            gSprites[spriteId].affineAnimPaused = TRUE;
        }
    }
}

static void SpriteCB_BoardIcon(struct Sprite *sprite)
{
    s16 cos;
    s16 sin;
    u32 matrixNum;
    s16 angle = sRoulette->var24 + sprite->data[0];
    if (angle >= 360)
        angle -= 360;
    sin = Sin2(angle);
    cos = Cos2(angle);
    sprite->pos2.x =  sin * sprite->data[1] >> 12;
    sprite->pos2.y = -cos * sprite->data[1] >> 12;
    matrixNum = sprite->oam.matrixNum;
    sin /= 16;
    gOamMatrices[matrixNum].d = cos /= 16;
    gOamMatrices[matrixNum].a = cos;
    gOamMatrices[matrixNum].b = sin;
    gOamMatrices[matrixNum].c = -sin;
}

static void CreateInterfaceSprites(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSpriteSheets_Interface) - 1; i++)
    {
        struct SpriteSheet s;
        LZ77UnCompWram(sSpriteSheets_Interface[i].data, gDecompressionBuffer);
        s.data = gDecompressionBuffer;
        s.size = sSpriteSheets_Interface[i].size;
        s.tag  = sSpriteSheets_Interface[i].tag;
        LoadSpriteSheet(&s);
    }
    sRoulette->spriteIds[SPR_CREDIT] = CreateSprite(&sSpriteTemplate_Credit, 208, 16, 4);
    gSprites[sRoulette->spriteIds[SPR_CREDIT]].animPaused = TRUE;
    for (i = 0; i < MAX_COIN_DIGITS; i++)
    {
        sRoulette->spriteIds[i + SPR_CREDIT_DIG_1] = CreateSprite(&sSpriteTemplate_CreditDigit, i * 8 + 196, 24, 0);
        gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].invisible = TRUE;
        gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].animPaused = TRUE;
    }
    sRoulette->spriteIds[SPR_MULTIPLIER] = CreateSprite(&sSpriteTemplate_Multiplier, 120, 68, 4);
    gSprites[sRoulette->spriteIds[SPR_MULTIPLIER]].animPaused = TRUE;
    for (i = 0; i < BALLS_PER_ROUND / 2; i++)
    {
        // Each ball counter sprite has 2 balls
        sRoulette->spriteIds[i + SPR_BALL_COUNTER_1] = CreateSprite(&sSpriteTemplate_BallCounter, i * 16 + 192, 36, 4);
        gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].invisible = TRUE;
        gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].animPaused = TRUE;
    }
    sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR] = CreateSprite(&sSpriteTemplate_Cursor, 152, 96, 9);
    gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].oam.priority = 1;
    gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].animPaused = TRUE;
    gSprites[sRoulette->spriteIds[SPR_WIN_SLOT_CURSOR]].invisible = TRUE;
}

static void SetCreditDigits(u16 r0)
{
    u8 i;
    u16 d = 1000;
    bool8 v = FALSE;
    for (i = 0; i < MAX_COIN_DIGITS; i++)
    {
        u8 t = r0 / d;
        gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].invisible = TRUE;
        if (t > 0 || v || i == MAX_COIN_DIGITS - 1)
        {
            gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].invisible = FALSE;
            gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].oam.tileNum =
                gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].sheetTileStart
                + (*gSprites[sRoulette->spriteIds[i + SPR_CREDIT_DIG_1]].anims + t)->type;
            v = TRUE;
        }
        r0 = r0 % d;
        d = d / 10;
    }
}

// Identical to GetMultiplier but with different data array
static u8 GetMultiplierAnimId(u8 selectionId)
{
    u8 animIds[5] = {0, 1, 2, 3, 4};

    if (selectionId > NUM_GRID_SELECTIONS)
        selectionId = 0;

    switch (sGridSelections[selectionId].baseMultiplier)
    {
    case NUM_BOARD_COLORS:
        selectionId = selectionId / 5 - 1;
        if (sRoulette->colorHits[selectionId] > 3)
            return 0;
        return animIds[sRoulette->colorHits[selectionId] + 1];
    case NUM_BOARD_POKES:
        selectionId--;
        if (sRoulette->pokeHits[selectionId] > 2)
            return 0;
        return animIds[sRoulette->pokeHits[selectionId] + 2];
    case NUM_ROULETTE_SLOTS:
        if (sRoulette->hitFlags & sGridSelections[selectionId].flag)
            return 0;
        return animIds[4];
    }
    return 0;
}

static void SetMultiplierSprite(u8 selectionId)
{
    struct Sprite *s = &gSprites[sRoulette->spriteIds[SPR_MULTIPLIER]];
    s->animCmdIndex = GetMultiplierAnimId(selectionId);
    s->oam.tileNum = s->sheetTileStart + (*s->anims + s->animCmdIndex)->type;
}

static void SetBallCounterNumLeft(u8 numBalls)
{
    u8 i;
    u8 t = 0;
    if (sRoulette->minBet == 1)
        t = 2;
    switch (numBalls)
    {
    case 6:
        for (i = 0; i < BALLS_PER_ROUND / 2; i++)
        {
            gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].invisible = FALSE;
            gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].oam.tileNum =
                gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].sheetTileStart
                + (*gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].anims)->type;
        }
        break;
    case 5:
        gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_3]].oam.tileNum =
            gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_3]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_3]].anims + t + 1)->type;
        break;
    case 4:
        gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_3]].oam.tileNum =
            gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_3]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_3]].anims + t + 2)->type;
        break;
    case 3:
        gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_2]].oam.tileNum =
            gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_2]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_2]].anims + t + 1)->type;
        break;
    case 2:
        gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_2]].oam.tileNum =
            gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_2]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_2]].anims + t + 2)->type;
        break;
    case 1:
        gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_1]].oam.tileNum =
            gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_1]].sheetTileStart
            + (*gSprites[sRoulette->spriteIds[SPR_BALL_COUNTER_1]].anims + t + 1)->type;
        break;
    case 0:
    default:
        for (i = 0; i < BALLS_PER_ROUND / 2; i++)
        {
            gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].oam.tileNum =
                gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].sheetTileStart
                + (*gSprites[sRoulette->spriteIds[i + SPR_BALL_COUNTER_1]].anims + t + 2)->type;
        }
    }
}

static void SpriteCB_GridSquare(struct Sprite *sprite)
{
    sprite->pos2.x = sRoulette->var26;
}

static void CreateBoardCenterSprite(void)
{
    u8 spriteId;
    struct SpriteSheet s;
    LZ77UnCompWram(sSpriteSheet_BoardCenter.data, gDecompressionBuffer);
    s.data = gDecompressionBuffer;
    s.size = sSpriteSheet_BoardCenter.size;
    s.tag = sSpriteSheet_BoardCenter.tag;
    LoadSpriteSheet(&s);
    spriteId = CreateSprite(&sSpriteTemplate_BoardCenter, 116, 80, 81);
    gSprites[spriteId].data[0] = sRoulette->var24;
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].affineAnimPaused = TRUE;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
}

static void SpriteCB_BoardCenter(struct Sprite *sprite)
{
    u32 t = sprite->oam.matrixNum;
    struct OamMatrix *m = &gOamMatrices[0];
    m[t].d = sRoulette->var2C.a;
    m[t].a = sRoulette->var2C.a;
    m[t].b = sRoulette->var2C.b;
    m[t].c = sRoulette->var2C.c;
}

static void CreateBoardBallSprites(void)
{
    u8 i;
    for (i = 0; i < BALLS_PER_ROUND; i++)
    {
        sRoulette->spriteIds[i] = CreateSprite(&sSpriteTemplate_Ball, 116, 80, 57 - i);
        if (sRoulette->spriteIds[i] != MAX_SPRITES)
        {
            gSprites[sRoulette->spriteIds[i]].invisible = TRUE;
            gSprites[sRoulette->spriteIds[i]].coordOffsetEnabled = TRUE;
        }
    }
}

static void HideBoardBalls(void)
{
    u8 t = sRoulette->spriteIds[SPR_BALL_1];
    u8 i;
    for (i = 0; i < BALLS_PER_ROUND; i++)
    {
        u8 j;
        gSprites[t].invisible = TRUE;
        gSprites[t].callback = &SpriteCallbackDummy;
        StartSpriteAnim(&gSprites[t], 0);
        for (j = 0; j < 8; j++)
        {
            gSprites[t].data[j] = 0;
        }
        t++;
    }
}

static s16 sub_8143AC8(struct Sprite *sprite)
{
    if (sRoulette->var24 > sprite->data[3])
    {
        sprite->data[6] = 360 - sRoulette->var24 + sprite->data[3];
        if (sprite->data[6] >= 360)
            sprite->data[6] -= 360;
    }
    else
    {
        sprite->data[6] = sprite->data[3] - sRoulette->var24;
    }

    return sprite->data[6];
}

static u8 sub_8143B14(struct Sprite *sprite)
{
    sRoulette->var7E = sub_8143AC8(sprite) / 30.0f;
    return sRoulette->var7E;
}

static s16 sub_8143B48(struct Sprite *sprite)
{
    s16 t = sub_8143AC8(sprite) % 30;
    u16 z;
    if (t == 14)
    {
        z = 0;
        return sprite->data[2] = z;
    }
    else if (t > 13)
    {
        z = 43 - t;
        return sprite->data[2] = z;
    }
    else
    {
        z = 14 - t;
        return sprite->data[2] = z;
    }
}

static void sub_8143B84(struct Sprite *sprite)
{
    s16 sin, cos;

    sRoulette->var8C += sRoulette->var90;
    sRoulette->var88 += sRoulette->var8C;

    if (sRoulette->var88 >= 360)
        sRoulette->var88 -= 360.0f;
    else if (sRoulette->var88 < 0.0f)
        sRoulette->var88 += 360.0f;

    sprite->data[3] = sRoulette->var88;
    sRoulette->var98 += sRoulette->var9C;
    sRoulette->var94 += sRoulette->var98;
    sprite->data[4] = sRoulette->var94;
    sin = Sin2(sprite->data[3]);
    cos = Cos2(sprite->data[3]);
    sprite->pos2.x =  sin * sprite->data[4] >> 12;
    sprite->pos2.y = -cos * sprite->data[4] >> 12;
    if (IsSEPlaying())
    {
        m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, sprite->pos2.x);
        m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, sprite->pos2.x);
    }
}

static void sub_8143C90(struct Sprite *sprite)
{
    s16 sin, cos;
    sprite->data[3] = sRoulette->var24 + sprite->data[6];
    if (sprite->data[3] >= 360)
        sprite->data[3] -= 360;
    sin = Sin2(sprite->data[3]);
    cos = Cos2(sprite->data[3]);
    sprite->pos2.x =  sin * sprite->data[4] >> 12;
    sprite->pos2.y = -cos * sprite->data[4] >> 12;
    sprite->pos2.y += gSpriteCoordOffsetY;
}

static void sub_8143CFC(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    sprite->data[2]++;
    if (sprite->data[4] < -132 || sprite->data[4] > 80)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;

    if (sprite->data[2] >= 30)
    {
        if (!sprite->data[0])
        {
            if (sRoulette->var94 <= sRoulette->varA0 - 2.0f)
            {
                sRoulette->var7D = 0xFF;
                sRoulette->var03_7 = FALSE;
                StartSpriteAnim(sprite, sprite->animCmdIndex + 0x3);
                sub_8143B14(sprite);
                sprite->data[4] = 30;
                sub_8143AC8(sprite);
                sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
                sprite->callback = sub_8143C90;
                m4aSongNumStartOrChange(SE_HASHI);
                sRoulette->var9C = sRoulette->var98 = 0.0f;
                sRoulette->var8C = -1.0f;
            }
        }
        else
        {
            if (sRoulette->var94 >= sRoulette->varA0 - 2.0f)
            {
                sRoulette->var7D = 0xFF;
                sRoulette->var03_7 = FALSE;
                StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
                sub_8143B14(sprite);
                sprite->data[4] = 30;
                sub_8143AC8(sprite);
                sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
                sprite->callback = sub_8143C90;
                m4aSongNumStartOrChange(SE_HASHI);
                sRoulette->var9C = sRoulette->var98 = 0.0f;
                sRoulette->var8C = -1.0f;
            }
        }
    }
}

static void SpriteCB_Shroomish(struct Sprite *sprite)
{
    float f0, f1, f2;
    sub_8143B84(sprite);

    switch (sprite->data[3])
    {
    case 0:
        if (sprite->data[0] != 1)
        {
            f0 = sprite->data[7];
            f1 = (f0 * gUnknown_085B6348[sRoulette->tableId].var01 + (gUnknown_085B6348[sRoulette->tableId].var02 - 1));
            f2 = (f0 / gUnknown_085B6348[sRoulette->tableId].var0C);
        }
        else
        {
            return;
        }
        break;
    case 180:
        if (sprite->data[0] != 0)
        {
            f0 = sprite->data[7];
            f1 = (f0 * gUnknown_085B6348[sRoulette->tableId].var01 + (gUnknown_085B6348[sRoulette->tableId].var02 - 1));
            f2 = -(f0 / gUnknown_085B6348[sRoulette->tableId].var0C);
        }
        else
        {
            return;
        }
        break;
    default:
        return;
    }
    sRoulette->varA0 = sRoulette->var94;
    sRoulette->var98 = f2;
    sRoulette->var9C = -((f2 * 2.0f) / f1 + (2.0f / (f1 * f1)));
    sRoulette->var8C = 0.0f;
    sprite->animPaused = FALSE;
    sprite->animNum = 0;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->callback = sub_8143CFC;
    sprite->data[2] = 0;
}

static void sub_8143FA4(struct Sprite *sprite)
{
    sprite->pos2.y = (s16)(sprite->data[2] * 0.05f * sprite->data[2]) - 45;
    sprite->data[2]++;
    if (sprite->data[2] > 29 && sprite->pos2.y >= 0)
    {
        sRoulette->var7D = 0xFF;
        sRoulette->var03_7 = FALSE;
        StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
        sub_8143B14(sprite);
        sprite->data[4] = 30;
        sub_8143AC8(sprite);
        sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
        sprite->callback = sub_8143C90;
        m4aSongNumStartOrChange(SE_HASHI);
        sRoulette->var03_6 = TRUE;
    }
}

static void sub_8144050(struct Sprite *sprite)
{
    if (sprite->data[2]++ < 45)
    {
        sprite->pos2.y--;
        if (sprite->data[2] == 45)
        {
            if (gSprites[sRoulette->spriteIds[SPR_CLEAR_MON]].animCmdIndex == 1)
                sprite->pos2.y++;
        }
    }
    else
    {
        if (sprite->data[2] < sprite->data[7])
        {
            if (gSprites[sRoulette->spriteIds[SPR_CLEAR_MON]].animDelayCounter == 0)
            {
                if (gSprites[sRoulette->spriteIds[SPR_CLEAR_MON]].animCmdIndex == 1)
                    sprite->pos2.y++;
                else
                    sprite->pos2.y--;
            }
        }
        else
        {
            sprite->animPaused = FALSE;
            sprite->animNum = 1;
            sprite->animBeginning = TRUE;
            sprite->animEnded = FALSE;
            sprite->data[2] = 0;
            sprite->callback = sub_8143FA4;
            m4aSongNumStart(SE_NAGERU);
        }
    }
}

static void sub_8144128(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    switch (sprite->data[3])
    {
    case 90:
        if (sprite->data[0] != 1)
        {
            sprite->callback  = &sub_8144050;
            sprite->data[2] = 0;
        }
        break;
    case 270:
        if (sprite->data[0] != 0)
        {
            sprite->callback  = &sub_8144050;
            sprite->data[2] = 0;
        }
        break;
    }
}

static void CreateClearSpeciesSprite(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    switch (sRoulette->useTaillow)
    {
    default:
    case FALSE:
        CreateShroomishSprite(sprite);
        sprite->callback = SpriteCB_Shroomish;
        break;
    case TRUE:
        CreateTaillowSprite(sprite);
        sprite->callback = sub_8144128;
        break;
    }
}

static void prev_quest_read_x24_hm_usage(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (sprite->data[2]-- == 16)
        sRoulette->var98 *= -1.0f;
    if (sprite->data[2] == 0)
    {
        if (!sprite->data[0])
        {
            sRoulette->var7D = 0xFF;
            sRoulette->var03_7 = FALSE;
            StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
            sub_8143B14(sprite);
            sprite->data[4] = 30;
            sub_8143AC8(sprite);
            sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
            sprite->callback = sub_8143C90;
            m4aSongNumStartOrChange(SE_HASHI);
        }
        else
        {
            sprite->animPaused = TRUE;
            m4aSongNumStart(SE_KON);
            sub_8144A24(sprite);
        }
    }
}

static void sub_8144264(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    sprite->data[2] = 0;
    sub_8143B14(sprite);
    if (!(sRouletteSlots[sRoulette->var7E].flag & sRoulette->hitFlags))
    {
        sRoulette->var7D = 0xFF;
        sRoulette->var03_7 = FALSE;
        StartSpriteAnim(sprite, sprite->animCmdIndex + 3);
        sub_8143B14(sprite);
        sprite->data[4] = 30;
        sub_8143AC8(sprite);
        sprite->data[6] = (sprite->data[6] / 30) * 30 + 15;
        sprite->callback = sub_8143C90;
        m4aSongNumStartOrChange(SE_HASHI);
    }
    else
    {
        u8 slotId;
        u32 z;
        m4aSongNumStart(SE_KON);
        z = Random() & 1;
        if (z)
        {
            sRoulette->var8C = 0.0f;
            sRoulette->var7F = slotId = (sRoulette->var7E + 1) % NUM_ROULETTE_SLOTS;
        }
        else
        {
            float temp;
            sRoulette->var8C = (temp = gUnknown_085B6348[sRoulette->tableId].var1C) * 2.0f;
            slotId = (sRoulette->var7E + NUM_ROULETTE_SLOTS - 1) % NUM_ROULETTE_SLOTS;
            sRoulette->var7F = sRoulette->var7E;
        }
        if (sRouletteSlots[slotId].flag & sRoulette->hitFlags)
        {
            sprite->data[0] = 1;
            sprite->data[2] = gUnknown_085B6348[sRoulette->tableId].var02;
        }
        else
        {
            sprite->data[0] = sRouletteSlots[slotId].flag & sRoulette->hitFlags;
            if (sRoulette->tableId)
            {
                sprite->data[2] = gUnknown_085B6348[sRoulette->tableId].var01;
            }
            else
            {
                sprite->data[2] = gUnknown_085B6348[sRoulette->tableId].var02;
                if (z)
                    sRoulette->var8C = 0.5f;
                else
                    sRoulette->var8C = -1.5f;
            }
        }
        sRoulette->var98 = 0.085f;
        sprite->callback = prev_quest_read_x24_hm_usage;
        sprite->data[1] = 5;
    }
}

static void sub_8144410(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (sRoulette->var8C > 0.5f)
        return;

    sub_8143B14(sprite);
    if (!sub_8143B48(sprite))
    {
        sRoulette->var90 = 0.0f;
        sRoulette->var8C -= (float)(gUnknown_085B6348[sRoulette->tableId].var03)
            / (gUnknown_085B6348[sRoulette->tableId].var04 + 1);
        sprite->data[1] = 4;
        sprite->callback = sub_8144264;
    }
    else
    {
        if (sRoulette->var90 != 0.0f)
        {
            if (sRoulette->var8C < 0.0f)
            {
                sRoulette->var90 = 0.0f;
                sRoulette->var8C = 0.0f;
                sRoulette->var98 /= 1.2;
            }
        }
    }
}

static void sub_8144514(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (sRoulette->var94 > 40.f)
        return;

    sRoulette->var98 = -(4.0f / (float)(sRoulette->var86));
    sRoulette->var90 = -(sRoulette->var8C / (float)(sRoulette->var86));
    sprite->animNum = 2;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->data[1] = 3;
    sprite->callback = sub_8144410;
}

static void sub_81445D8(struct Sprite *sprite)
{
    sub_8143B84(sprite);
    if (sRoulette->var94 > 60.0f)
        return;

    m4aSongNumStartOrChange(SE_TAMAKORO_E);
    sRoulette->var98 = -(20.0f / (float)(sRoulette->var84));
    sRoulette->var90 = ((1.0f - sRoulette->var8C) / (float)(sRoulette->var84));
    sprite->animNum = 1;
    sprite->animBeginning = TRUE;
    sprite->animEnded = FALSE;
    sprite->data[1] = 2;
    sprite->callback = sub_8144514;
}

static void sub_81446AC(struct Sprite *sprite)
{
    sprite->data[1] = 1;
    sprite->data[2] = 0;
    sub_8143B84(sprite);
    sprite->invisible = FALSE;
    sprite->callback = sub_81445D8;
}

static void CreateShroomishSprite(struct Sprite *sprite)
{
    u16 t;
    u8 i;
    s16 s[2][2] = {
        {116, 44},
        {116, 112}
    };
    struct Roulette *p;

    t = sprite->data[7] - 2;
    p = sRoulette;  // why???
    sRoulette->spriteIds[SPR_CLEAR_MON] = CreateSprite(&sSpriteTemplate_Shroomish, 36, -12, 50);
    sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1] = CreateSprite(&sSpriteTemplate_ShroomishShadow[0], s[sprite->data[0]][0], s[sprite->data[0]][1], 59);
    sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_2] = CreateSprite(&sSpriteTemplate_ShroomishShadow[1], 36, 140, 51);
    gSprites[sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_2]].oam.objMode = ST_OAM_OBJ_BLEND;
    for (i = 0; i < 3; i++)
    {
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].coordOffsetEnabled = FALSE;
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].invisible = TRUE;
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].animPaused = TRUE;
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].affineAnimPaused = TRUE;
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].data[4] = sRoulette->spriteIds[SPR_CLEAR_MON];
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].data[5] = sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1];
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].data[6] = sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_2];
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].data[2] = t;
        gSprites[sRoulette->spriteIds[i + SPR_CLEAR_MON]].data[3] = (sprite->data[7] * gUnknown_085B6348[sRoulette->tableId].var01) +
                                                                (gUnknown_085B6348[sRoulette->tableId].var02 + 0xFFFF);
    }
    gSprites[sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1]].coordOffsetEnabled = TRUE;
    sRoulette->var38 = sprite;
}

static void CreateTaillowSprite(struct Sprite *sprite)
{
    u8 i = 0;
    s16 t;
    s16 s[2][2] = {
        {256, 84},
        {-16, 84}
    };

    t = sprite->data[7] - 2;
    sRoulette->spriteIds[SPR_CLEAR_MON] = CreateSprite(&sSpriteTemplate_Taillow, s[sprite->data[0]][0], s[sprite->data[0]][1], 50);
    StartSpriteAnim(&gSprites[sRoulette->spriteIds[SPR_CLEAR_MON]], sprite->data[0]);
    sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1] = CreateSprite(&sSpriteTemplate_TaillowShadow, s[sprite->data[0]][0], s[sprite->data[0]][1], 51);
    gSprites[sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1]].affineAnimPaused = TRUE;
    gSprites[sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1]].animPaused = TRUE;
    sprite->data[7] = (t * gUnknown_085B6348[sRoulette->tableId].var01) + (gUnknown_085B6348[sRoulette->tableId].var10 + 45);
    for (; i < 2; i++)
    {
        gSprites[sRoulette->spriteIds[SPR_CLEAR_MON + i]].data[4] = sRoulette->spriteIds[SPR_CLEAR_MON];
        gSprites[sRoulette->spriteIds[SPR_CLEAR_MON + i]].data[5] = sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1];
        gSprites[sRoulette->spriteIds[SPR_CLEAR_MON + i]].data[6] = sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1];
        gSprites[sRoulette->spriteIds[SPR_CLEAR_MON + i]].data[2] = t;
        gSprites[sRoulette->spriteIds[SPR_CLEAR_MON + i]].data[3] = sprite->data[7] - 45;
    }
    sRoulette->var38 = sprite;
}

static void sub_8144A24(struct Sprite *sprite)
{
    u8 z;
    u16 o;
    u8 h = 0;
    u8 j = 5;
    u8 p = 0;
    u8 i = 0;
    u8 val;
    u8 s[10] = {};
    u16 rand = Random();

    sRoulette->var7D = 1;
    sRoulette->var03_5 = TRUE;
    sRoulette->var03_6 = FALSE;
    sRoulette->var7E = 0xFF;
    sRoulette->var88 = sprite->data[3];
    sRoulette->var98 = 0.0f;
    sRoulette->var8C = gUnknown_085B6348[sRoulette->tableId].var1C;

    o = (sRoulette->tableId * 30 + 33) + (1 - sRoulette->useTaillow) * 15;
    for (i = 0; i < 4; i++)
    {
        if (o < sprite->data[3] && sprite->data[3] <= o + 90)
        {
            sprite->data[0] = i / 2;
            sRoulette->useTaillow = i % 2;
            break;
        }
        if (i == 3)
        {
            sprite->data[0] = 1;
            sRoulette->useTaillow = TRUE;
            break;
        }
        o += 90;
    }

    if (sRoulette->useTaillow)
    {
        if (sprite->data[0])
            PlayCry1(SPECIES_TAILLOW, -63);
        else
            PlayCry1(SPECIES_TAILLOW, 63);
    }
    else
    {
        PlayCry1(SPECIES_SHROOMISH, -63);
    }

    val = 2;
    z = (sRoulette->var7F + 2) % 12;

    if (sRoulette->useTaillow == TRUE && sRoulette->tableId == 1)
        j += 6;
    else
        j += val;

    for (i = val; i < j; i++)
    {
        if (!(sRoulette->hitFlags & sRouletteSlots[z].flag))
        {
            s[h++] = i;
            if (p == 0 && (sRouletteSlots[z].flag & sGridSelections[sRoulette->betSelection[sRoulette->curBallNum]].inSelectionFlags))
                p = i;
        }
        z = (z + 1) % 12;
    }

    if ((sRoulette->useTaillow + 1) & sRoulette->partySpeciesFlags)
    {
        if (p && (rand & 0xFF) < 0xc0)
            sprite->data[7] = p;
        else
            sprite->data[7] = s[rand % h];
    }
    else
    {
        sprite->data[7] = s[rand % h];
    }

    sprite->callback = CreateClearSpeciesSprite;
}

static const u16 gUnknown_085B7B1A[] = {
    0x907,
    0x808,
    0x709,
    0x60A,
    0x50B,
    0x40C,
    0x30D,
    0x20E,
    0x10F,
    0x010,
};

static void sub_8144C70(struct Sprite *sprite)
{
    if (sprite->data[1]++ >= sprite->data[3])
    {
	    sprite->pos1.x -= 2;
        if (sprite->pos1.x < -16)
        {
            if (!sRoulette->var03_6)
                sRoulette->var03_6 = TRUE;
            DestroySprite(sprite);
            sRoulette->var01 = 0;
            sRoulette->var34 = gUnknown_085B7B1A[0];
        }
    }
}

static void sub_8144CD0(struct Sprite *sprite)
{
    int p;
    u16 t[][4] = {
        {-1, 0, 1, 0},
        {-2, 0, 2, 0},
        {-3, 0, 3, 0},
    };

    if (sprite->data[1]++ < sprite->data[3])
    {
        if (sprite->data[1] & 1)
        {
            gSpriteCoordOffsetY = t[sprite->data[2] / 2][sprite->data[7]];
            p = sprite->data[7] + 1;
            sprite->data[7] = p - ((p / 4) * 4);
        }
        sprite->invisible ^= 1;
    }
    else
    {
        gSpriteCoordOffsetY = 0;
        gSprites[sRoulette->spriteIds[SPR_CLEAR_MON]].animPaused = FALSE;
        DestroySprite(sprite);
    }
}

static void sub_8144D94(struct Sprite *sprite)
{
    float t;
    sprite->data[1]++;
    t = sprite->data[1];
    sprite->pos2.y = t * 0.039f * t;
    sRoulette->var34 = gUnknown_085B7B1A[(sRoulette->var01 - 1) / 2];
    if (sRoulette->var01 < 19)
        sRoulette->var01++;
    if (sprite->data[1] > 60)
    {
        sprite->data[1] = 0;
        sprite->callback = sub_8144C70;
        gSprites[sprite->data[6]].callback  = sub_8144C70;
        gSprites[sprite->data[6]].data[1] = -2;
        gSprites[sprite->data[5]].invisible = FALSE;
        gSprites[sprite->data[5]].callback  = sub_8144CD0;
        m4aSongNumStart(SE_W070);
    }
}

static void sub_8144E60(struct Sprite *sprite)
{
    if (sprite->data[7] == 0)
    {
        if (sRoulette->var38->data[0] == 0)
        {
            if (sRoulette->var38->data[3] != gUnknown_085B6348[sRoulette->tableId].var08)
                return;
        }
        else
        {
            if (sRoulette->var38->data[3] != gUnknown_085B6348[sRoulette->tableId].var08 + 180)
                return;
        }

        sprite->invisible = FALSE;
        sprite->data[7]++;
        m4aSongNumStart(SE_RU_HYUU);
        sRoulette->var01 = 1;
        sRoulette->var34 = gUnknown_085B7B1A[0];
    }
    else
    {
        sRoulette->var34 = gUnknown_085B7B1A[(sRoulette->var01 - 1) / 2];
        if (sRoulette->var01 < 19)
            sRoulette->var01++;

        if (sRoulette->var38->data[0] == 0)
        {
            if (sRoulette->var38->data[3] != gUnknown_085B6348[sRoulette->tableId].var0A)
                return;
        }
        else
        {
            if (sRoulette->var38->data[3] != gUnknown_085B6348[sRoulette->tableId].var0A + 180)
                return;
        }

        gSprites[sprite->data[4]].callback  = sub_8144D94;
        gSprites[sprite->data[4]].invisible = FALSE;
        sprite->callback  = &SpriteCallbackDummy;
        sprite->data[7] = 0;
    }
}

static void sub_8144F94(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
}

static void sub_8144FB0(struct Sprite *sprite)
{
    if (sprite->pos1.y > -16)
    {
        sprite->pos1.y--;
    }
    else
    {
        sprite->callback = SpriteCallbackDummy;
        sprite->invisible = TRUE;
        sprite->animPaused = TRUE;
        m4aSongNumStop(SE_BASABASA);
        DestroySprite(sprite);
        FreeOamMatrix(gSprites[sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1]].oam.matrixNum);
        DestroySprite(&gSprites[sRoulette->spriteIds[SPR_CLEAR_MON_SHADOW_1]]);
    }
}

static void sub_8145030(struct Sprite *sprite)
{
    if (sprite->data[1] >= 0)
    {
        sprite->data[1]--;
        sprite->pos1.y--;
        if (sprite->data[1] == 0 && sprite->animCmdIndex == 1)
            sprite->pos2.y++;
    }
    else
    {
        if (sprite->data[3] >= 0)
        {
            sprite->data[3]--;
            if (sprite->animDelayCounter == 0)
            {
                if (sprite->animCmdIndex == 1)
                    sprite->pos2.y++;
                else
                    sprite->pos2.y--;
            }
        }
        else
        {
            m4aSongNumStart(SE_RU_HYUU);
            StartSpriteAnim(sprite, sRoulette->var38->data[0] + 4);
            sprite->callback = sub_8144FB0;
            gSprites[sprite->data[6]].affineAnimPaused = FALSE;
        }
    }
}

static void sub_81450D8(struct Sprite *sprite)
{
    s8 t[2] = {-1, 1};
    s8 z[][2] = {
        {2, 0},
        {2, 0},
        {2, -1},
        {2, -1},
        {2, -1},
        {2, -1},
        {2, -2},
        {2, -2},
    };

    if (sprite->data[1]-- > 7)
    {
        sprite->pos1.x += t[sRoulette->var38->data[0]] * 2;
        if (IsSEPlaying())
        {
            s8 pan = -((116 - sprite->pos1.x) / 2);
            m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
            m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
        }
    }
    else
    {
        if (sprite->data[1] >= 0)
        {
            sprite->pos1.x += t[sRoulette->var38->data[0]] * z[7 - sprite->data[1]][0];
            sprite->pos1.y += z[7 - sprite->data[1]][1];
        }
        else
        {
            m4aSongNumStartOrChange(SE_BASABASA);
            if (sRoulette->var38->data[0] == 0)
                PlayCry1(SPECIES_TAILLOW, 63);
            else
                PlayCry1(SPECIES_TAILLOW, -63);
            StartSpriteAnim(sprite, sRoulette->var38->data[0] + 2);
            sprite->data[1] = 45;
            sprite->callback = sub_8145030;
        }
    }
}

static void sub_8145218(struct Sprite *sprite)
{
    s8 t[2] = {-1, 1};

    if (sprite->data[1]-- >= 0)
    {
        sprite->pos1.x += t[sRoulette->var38->data[0]] * 2;
        gSprites[sprite->data[6]].invisible ^= 1;
    }
    else
    {
        sprite->callback = sub_8144F94;
    }
}

static void SpriteCB_Taillow(struct Sprite *sprite)
{
    if (sRoulette->var38->data[0] == 0)
    {
        if (sRoulette->var38->data[3] == gUnknown_085B6348[sRoulette->tableId].var12 + 90)
        {
            gSprites[sprite->data[6]].data[1] = 52;
            gSprites[sprite->data[4]].data[1] = 52;
        }
        else
        {
            return;
        }
    }
    else
    {
        if (sRoulette->var38->data[3] == gUnknown_085B6348[sRoulette->tableId].var14 + 270)
        {
            gSprites[sprite->data[6]].data[1] = 46;
            gSprites[sprite->data[4]].data[1] = 46;
        }
        else
        {
            return;
        }
    }
    gSprites[sprite->data[6]].callback = sub_8145218;
    gSprites[sprite->data[4]].callback = sub_81450D8;
    m4aSongNumStart(SE_RU_HYUU);
}
