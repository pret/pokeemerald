#include "global.h"
#include "palette.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "malloc.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "international_string_util.h"
#include "constants/songs.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "constants/rgb.h"
#include "trainer_pokemon_sprites.h"
#include "starter_choose.h"
#include "decompress.h"
#include "intro_credits_graphics.h"
#include "sound.h"
#include "trig.h"
#include "graphics.h"
#include "pokedex.h"
#include "event_data.h"
#include "random.h"

#define COLOR_DARK_GREEN RGB(7, 11, 6)
#define COLOR_LIGHT_GREEN RGB(13, 20, 12)

#define TAG_MON_BG 1001

// Positions for the Pokémon images
enum {
    POS_LEFT,
    POS_CENTER,
    POS_RIGHT,
};

#define tPlayerSpriteId data[5]
#define tRivalSpriteId  data[6]

enum
{
    TDA_0 = 0,
    TDA_TASK_C_ID = 1,
    TDA_TASK_E_ID = 2,
    TDA_TASK_D_ID = 3,
    TDA_4 = 4,
    TDA_PLAYER_CYCLIST = 5,
    TDA_RIVAL_CYCLIST = 6,
    TDA_7 = 7, // Has something to do with the bike scene
    TDA_11 = 11, // Gets set depending on whether the bike or the grass scene should be shown
    TDA_12 = 12,
    TDA_13 = 13,
    TDA_14 = 14,
    TDA_TASK_B_ID = 15,

    // Appears to be responsible for text
    TDB_0 = 0,
    TDB_TASK_A_ID = 1,
    TDB_CURRENT_PAGE = 2,
    TDB_3 = 3,

    TDC_0 = 0,
    TDC_1 = 1,
    TDC_2 = 2,
    TDC_3 = 3,
    TDC_4 = 4,
    TDC_5 = 5,

    TDD_STATE = 0,
    TDD_TASK_A_ID = 1,
    TDD_2 = 2,
    TDD_3 = 3,

    TDE_0 = 0,
    TDE_1 = 1,
    TDE_TASK_A_ID = 2,
};

#define NUM_MON_SLIDES 71
struct CreditsData
{
    u16 monToShow[NUM_MON_SLIDES]; // List of Pokemon species ids that will show during the credits
    u16 imgCounter; //how many mon images have been shown
    u16 nextImgPos; //if the next image spawns left/center/right
    u16 currShownMon; //index into monToShow
    u16 numMonToShow; //number of pokemon to show, always NUM_MON_SLIDES after determine function
    u16 caughtMonIds[NATIONAL_DEX_COUNT]; //temporary location to hold a condensed array of all caught pokemon
    u16 numCaughtMon; //count of filled spaces in caughtMonIds
    u16 unused[7];
};

struct CreditsEntry
{
    u8 unk; // Never read
    bool8 isTitle;
    const u8 *text;
};

static EWRAM_DATA s16 sUnkVar = 0; // Never read, only set to 0
static EWRAM_DATA u16 sSavedTaskId = 0;
EWRAM_DATA bool8 gHasHallOfFameRecords = 0;
static EWRAM_DATA bool8 sUsedSpeedUp = 0; // Never read
static EWRAM_DATA struct CreditsData *sCreditsData = {0};

static const u16 sCredits_Pal[] = INCBIN_U16("graphics/credits/credits.gbapal");
static const u32 sCreditsCopyrightEnd_Gfx[] = INCBIN_U32("graphics/credits/the_end_copyright.4bpp.lz");

static void SpriteCB_CreditsMonBg(struct Sprite *);
static void Task_WaitPaletteFade(u8);
static void Task_ProgressCreditTasks(u8);
static void sub_8175808(u8);
static void c2_080C9BFC(u8);
static void Task_CreditsLoadGrassScene(u8);
static void sub_81758A4(u8);
static void Task_CreditsTheEnd1(u8);
static void Task_CreditsTheEnd2(u8);
static void Task_CreditsTheEnd3(u8);
static void Task_CreditsTheEnd4(u8);
static void Task_CreditsTheEnd5(u8);
static void Task_CreditsTheEnd6(u8);
static void Task_CreditsSoftReset(u8);
static void ResetGpuAndVram(void);
static void sub_8175DA0(u8);
static u8 CheckChangeScene(u8, u8);
static void sub_81760FC(u8);
static void sub_817651C(u8);
static void sub_817624C(u8);
static bool8 sub_8176AB0(u8 data, u8);
static void ResetCreditsTasks(u8);
static void LoadTheEndScreen(u16, u16, u16);
static void DrawTheEnd(u16, u16);
static void SpriteCB_PlayerCyclist(struct Sprite *);
static void SpriteCB_RivalCyclist(struct Sprite *);
static u8 CreateCreditsMonSprite(u16, s16, s16, u16);
static void DeterminePokemonToShow(void);

static const u8 sTheEnd_LetterMap_T[] =
{
    0,    1, 0,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
    0xFF, 1, 0xFF,
};

static const u8 sTheEnd_LetterMap_H[] =
{
    1, 0xFF, 1,
    1, 0xFF, 1,
    1, 2,    1,
    1, 0xFF, 1,
    1, 0xFF, 1,
};

static const u8 sTheEnd_LetterMap_E[] =
{
    1, 0, 0,
    1, 0xFF, 0xFF,
    1, 2,    2,
    1, 0xFF, 0xFF,
    1, 0x80, 0x80,
};

static const u8 sTheEnd_LetterMap_N[] =
{
    1, 3, 1,
    1, 4, 1,
    1, 5, 1,
    1, 0xC4, 1,
    1, 0xC3, 1,
};

static const u8 sTheEnd_LetterMap_D[] =
{
    1, 6, 7,
    1, 8, 9,
    1, 0xFF, 1,
    1, 0x88, 0x89,
    1, 0x86, 0x87,
};

#include "data/credits.h"

static const struct BgTemplate sBackgroundTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};
static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 9,
        .width = 30,
        .height = 12,
        .paletteNum = 8,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE,
};
static const u8 sMonSpritePos[][2] =
{
    {104, 36},
    {120, 36},
    {136, 36},
};

static const union AnimCmd sAnim_Player_Slow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Player_Fast[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Player_LookBack[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_FRAME(384, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Player_LookForward[] =
{
    ANIMCMD_FRAME(384, 30),
    ANIMCMD_FRAME(320, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_FRAME(256, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Player[] =
{
    sAnim_Player_Slow,
    sAnim_Player_Fast,
    sAnim_Player_LookBack,
    sAnim_Player_LookForward,
};

static const union AnimCmd sAnim_Rival_Slow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Rival_Fast[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_Rival_Still[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Rival[] =
{
    sAnim_Rival_Slow,
    sAnim_Rival_Fast,
    sAnim_Rival_Still,
};

#define MONBG_OFFSET (0x800 * 3)
static const struct SpriteSheet sSpriteSheet_MonBg[] = {
    { gDecompressionBuffer, MONBG_OFFSET, TAG_MON_BG },
    {},
};
static const struct SpritePalette sSpritePalette_MonBg[] = {
    { (const u16 *)&gDecompressionBuffer[MONBG_OFFSET], TAG_MON_BG },
    {},
};

static const struct OamData sOamData_MonBg =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_MonBg_Yellow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonBg_Red[] =
{
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonBg_Blue[] =
{
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_MonBg[] =
{
    [POS_LEFT]   = sAnim_MonBg_Yellow,
    [POS_CENTER] = sAnim_MonBg_Red,
    [POS_RIGHT]  = sAnim_MonBg_Blue,
};

static const struct SpriteTemplate sSpriteTemplate_CreditsMonBg =
{
    .tileTag = TAG_MON_BG,
    .paletteTag = TAG_MON_BG,
    .oam = &sOamData_MonBg,
    .anims = sAnims_MonBg,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CreditsMonBg,
};

static void VBlankCB_Credits(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_Credits(void)
{
    RunTasks();
    AnimateSprites();

    if ((JOY_HELD(B_BUTTON))
     && gHasHallOfFameRecords
     && gTasks[sSavedTaskId].func == Task_ProgressCreditTasks)
    {
        // Speed up credits
        VBlankCB_Credits();
        RunTasks();
        AnimateSprites();
        sUsedSpeedUp = TRUE;
    }
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void InitCreditsBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
    LoadPalette(sCredits_Pal, 0x80, 64);
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
    ShowBg(0);
}

static void sub_81755A4(void)
{
    void *ptr;
    FreeAllWindowBuffers();
    ptr = GetBgTilemapBuffer(0);
    if (ptr)
        Free(ptr);
}

static void PrintCreditsText(const u8 *string, u8 y, bool8 isTitle)
{
    u8 x;
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;

    if (isTitle == TRUE)
    {
        color[1] = TEXT_COLOR_LIGHT_GREY;
        color[2] = TEXT_COLOR_RED;
    }
    else
    {
        color[1] = TEXT_COLOR_WHITE;
        color[2] = TEXT_COLOR_DARK_GREY;
    }

    x = GetStringCenterAlignXOffsetWithLetterSpacing(1, string, DISPLAY_WIDTH, 1);
    AddTextPrinterParameterized4(0, 1, x, y, 1, 0, color, -1, string);
}

void CB2_StartCreditsSequence(void)
{
    u8 taskIdA;
    s16 taskIdC;
    u8 taskIdB;

    ResetGpuAndVram();
    SetVBlankCallback(NULL);
    InitHeap(gHeap, HEAP_SIZE);
    ResetPaletteFade();
    ResetTasks();
    InitCreditsBgsAndWindows();

    taskIdA = CreateTask(Task_WaitPaletteFade, 0);

    gTasks[taskIdA].data[TDA_4] = 0;
    gTasks[taskIdA].data[TDA_7] = 0;
    gTasks[taskIdA].data[TDA_11] = 0;
    gTasks[taskIdA].data[TDA_13] = 1;

    while (TRUE)
    {
        if (sub_8176AB0(0, taskIdA))
            break;
    }

    taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
    gTasks[taskIdC].data[TDC_0] = 40;

    SetGpuReg(REG_OFFSET_BG0VOFS, 0xFFFC);

    taskIdB = CreateTask(sub_8175DA0, 0);

    gTasks[taskIdB].data[TDB_TASK_A_ID] = taskIdA;
    gTasks[taskIdA].data[TDA_TASK_B_ID] = taskIdB;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_Credits);
    m4aSongNumStart(MUS_CREDITS);
    SetMainCallback2(CB2_Credits);
    sUsedSpeedUp = FALSE;
    sCreditsData = AllocZeroed(sizeof(struct CreditsData));

    DeterminePokemonToShow();

    sCreditsData->imgCounter = 0;
    sCreditsData->nextImgPos = POS_LEFT;
    sCreditsData->currShownMon = 0;

    sSavedTaskId = taskIdA;
}

static void Task_WaitPaletteFade(u8 taskIdA)
{
    if (!gPaletteFade.active)
        gTasks[taskIdA].func = Task_ProgressCreditTasks;
}

static void Task_ProgressCreditTasks(u8 taskIdA)
{
    u16 data1;

    if (gTasks[taskIdA].data[TDA_4])
    {
        s16 taskIdC;

        taskIdC = gTasks[taskIdA].data[TDA_TASK_C_ID];
        gTasks[taskIdC].data[TDC_0] = 30;

        gTasks[taskIdA].data[TDA_12] = 0x100;
        gTasks[taskIdA].func = Task_CreditsTheEnd1;
        return;
    }

    sUnkVar = 0;
    data1 = gTasks[taskIdA].data[TDA_11];

    if (gTasks[taskIdA].data[TDA_11] == 1)
    {
        gTasks[taskIdA].data[TDA_13] = data1;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskIdA].func = sub_8175808;
    }
    else if (gTasks[taskIdA].data[TDA_11] == 2)
    {
        gTasks[taskIdA].data[TDA_13] = data1;
        gTasks[taskIdA].data[TDA_11] = 0;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskIdA].func = sub_81758A4;
    }
}

static void sub_8175808(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetCreditsTasks(taskIdA);
        gTasks[taskIdA].func = c2_080C9BFC;
    }
}

static void c2_080C9BFC(u8 taskIdA)
{
    SetVBlankCallback(NULL);

    if (sub_8176AB0(gTasks[taskIdA].data[TDA_7], taskIdA))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Credits);
        gTasks[taskIdA].func = Task_WaitPaletteFade;
    }
}

static void sub_81758A4(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetCreditsTasks(taskIdA);
        gTasks[taskIdA].func = Task_CreditsLoadGrassScene;
    }
}

static void Task_CreditsLoadGrassScene(u8 taskIdA)
{
    switch (gMain.state)
    {
    default:
    case 0:
    {
        u16 i;
        u16 *temp;

        ResetSpriteData();
        ResetAllPicSprites();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
        LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));
        LoadPalette(gBirchBagGrassPal[0] + 1, 1, 31 * 2);

        for (i = 0; i < 0x800; i++)
            gDecompressionBuffer[i] = 0x11;
        for (i = 0; i < 0x800; i++)
            (gDecompressionBuffer + 0x800)[i] = 0x22;
        for (i = 0; i < 0x800; i++)
            (gDecompressionBuffer + 0x800 * 2)[i] = 0x33;

        temp = (u16 *)(&gDecompressionBuffer[MONBG_OFFSET]);
        temp[0] = RGB_BLACK;
        temp[1] = RGB(31, 31, 20); // light yellow
        temp[2] = RGB(31, 20, 20); // light red
        temp[3] = RGB(20, 20, 31); // light blue

        LoadSpriteSheet(sSpriteSheet_MonBg);
        LoadSpritePalette(sSpritePalette_MonBg);

        gMain.state++;
        break;
    }
    case 1:
        gTasks[taskIdA].data[TDA_TASK_D_ID] = CreateTask(sub_81760FC, 0);
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_STATE] = 1;
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_TASK_A_ID] = taskIdA;
        gTasks[gTasks[taskIdA].data[TDA_TASK_D_ID]].data[TDD_2] = gTasks[taskIdA].data[TDA_7];

        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 32);
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG0_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);

        gMain.state = 0;
        gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_NORMAL;
        gTasks[taskIdA].func = Task_WaitPaletteFade;
        break;
    }
}

static void Task_CreditsTheEnd1(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_12])
    {
        gTasks[taskIdA].data[TDA_12]--;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 12, 0, 16, RGB_BLACK);
    gTasks[taskIdA].func = Task_CreditsTheEnd2;
}

static void Task_CreditsTheEnd2(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        ResetCreditsTasks(taskIdA);
        gTasks[taskIdA].func = Task_CreditsTheEnd3;
    }
}

#define tDelay data[0]

static void Task_CreditsTheEnd3(u8 taskIdA)
{
    ResetGpuAndVram();
    ResetPaletteFade();
    LoadTheEndScreen(0, 0x3800, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(PALETTES_ALL, 8, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON);

    gTasks[taskIdA].tDelay = 235; //set this to 215 to actually show "THE END" in time to the last song beat
    gTasks[taskIdA].func = Task_CreditsTheEnd4;
}

static void Task_CreditsTheEnd4(u8 taskIdA)
{
    if (gTasks[taskIdA].tDelay)
    {
        gTasks[taskIdA].tDelay--;
        return;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 6, 0, 16, RGB_BLACK);
    gTasks[taskIdA].func = Task_CreditsTheEnd5;
}

static void Task_CreditsTheEnd5(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        DrawTheEnd(0x3800, 0);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0, RGB_BLACK);
        gTasks[taskIdA].tDelay = 7200;
        gTasks[taskIdA].func = Task_CreditsTheEnd6;
    }
}

static void Task_CreditsTheEnd6(u8 taskIdA)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskIdA].tDelay == 0 || gMain.newKeys)
        {
            FadeOutBGM(4);
            BeginNormalPaletteFade(PALETTES_ALL, 8, 0, 16, RGB_WHITEALPHA);
            gTasks[taskIdA].func = Task_CreditsSoftReset;
            return;
        }

        if (gTasks[taskIdA].tDelay == 7144)
            FadeOutBGM(8);

        if (gTasks[taskIdA].tDelay == 6840)
            m4aSongNumStart(MUS_END);

        gTasks[taskIdA].tDelay--;
    }
}

#undef tDelay

static void Task_CreditsSoftReset(u8 taskIdA)
{
    if (!gPaletteFade.active)
        SoftReset(RESET_ALL);
}

static void ResetGpuAndVram(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
}

static void sub_8175DA0(u8 taskIdB)
{
    int i;

    switch (gTasks[taskIdB].data[TDB_0])
    {
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    default:
        if (!gPaletteFade.active)
        {
            gTasks[taskIdB].data[TDB_0] = 1;
            gTasks[taskIdB].data[TDB_3] = 0x48;
            gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 0;
            sUnkVar = 0;
        }
        return;
    case 1:
        if (gTasks[taskIdB].data[TDB_3] != 0)
        {
            gTasks[taskIdB].data[TDB_3]--;
            return;
        }
        gTasks[taskIdB].data[TDB_0]++;
        return;
    case 2:
        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].func == Task_ProgressCreditTasks)
        {
            if (gTasks[taskIdB].data[TDB_CURRENT_PAGE] < PAGE_COUNT)
            {
                for (i = 0; i < ENTRIES_PER_PAGE; i++)
                    PrintCreditsText(
                        sCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->text,
                         5 + i * 16, 
                         sCreditsEntryPointerTable[gTasks[taskIdB].data[TDB_CURRENT_PAGE]][i]->isTitle);

                CopyWindowToVram(0, 2);

                gTasks[taskIdB].data[TDB_CURRENT_PAGE]++;
                gTasks[taskIdB].data[TDB_0]++;

                gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 1;

                if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_13] == 1)
                    BeginNormalPaletteFade(0x00000300, 0, 16, 0, COLOR_LIGHT_GREEN);
                else
                    BeginNormalPaletteFade(0x00000300, 0, 16, 0, COLOR_DARK_GREEN);
                return;
            }
            gTasks[taskIdB].data[TDB_0] = 10;
            return;
        }
        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_14] = 0;
        return;
    case 3:
        if (!gPaletteFade.active)
        {
            gTasks[taskIdB].data[TDB_3] = 0x73;
            gTasks[taskIdB].data[TDB_0]++;
        }
        return;
    case 4:
        if (gTasks[taskIdB].data[TDB_3] != 0)
        {
            gTasks[taskIdB].data[TDB_3]--;
            return;
        }

        if (CheckChangeScene((u8)gTasks[taskIdB].data[TDB_CURRENT_PAGE], (u8)gTasks[taskIdB].data[TDB_TASK_A_ID]))
        {
            gTasks[taskIdB].data[TDB_0]++;
            return;
        }
        gTasks[taskIdB].data[TDB_0]++;
        if (gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_13] == 1)
            BeginNormalPaletteFade(0x00000300, 0, 0, 16, COLOR_LIGHT_GREEN);
        else
            BeginNormalPaletteFade(0x00000300, 0, 0, 16, COLOR_DARK_GREEN);
        return;
    case 5:
        if (!gPaletteFade.active)
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(0));
            CopyWindowToVram(0, 2);
            gTasks[taskIdB].data[TDB_0] = 2;
        }
        return;
    case 10:
        gTasks[gTasks[taskIdB].data[TDB_TASK_A_ID]].data[TDA_4] = 1;
        DestroyTask(taskIdB);
        sub_81755A4();
        FREE_AND_SET_NULL(sCreditsData);
        return;
    }
}

static u8 CheckChangeScene(u8 page, u8 taskIdA)
{
    // Starts with bike + ocean + morning

    if (page == 6)
    {
        // Pokémon interlude
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 12)
    {
        // Bike + ocean + sunset
        gTasks[taskIdA].data[TDA_7] = 1;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == 18)
    {
        // Pokémon interlude
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 24)
    {
        // Bike + forest + sunset
        gTasks[taskIdA].data[TDA_7] = 2;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == 30)
    {
        // Pokémon interlude
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 36)
    {
        // Bike + forest + sunset
        gTasks[taskIdA].data[TDA_7] = 3;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (page == 42)
    {
        // Pokémon interlude
        gTasks[taskIdA].data[TDA_11] = 2;
    }

    if (page == 48)
    {
        // Bike + town + night
        gTasks[taskIdA].data[TDA_7] = 4;
        gTasks[taskIdA].data[TDA_11] = 1;
    }

    if (gTasks[taskIdA].data[TDA_11] != 0)
    {
        // Returns true if changed?
        return TRUE;
    }

    return FALSE;
}

static void sub_81760FC(u8 taskIdD)
{
    u8 r2;

    switch (gTasks[taskIdD].data[TDD_STATE])
    {
    case 0:
        break;
    case 1:
        if (sCreditsData->nextImgPos == POS_LEFT && gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].data[TDA_14] == 0)
            break;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 2:
        if (sCreditsData->imgCounter == NUM_MON_SLIDES || gTasks[gTasks[taskIdD].data[TDD_TASK_A_ID]].func != Task_ProgressCreditTasks)
            break;
        r2 = CreateCreditsMonSprite(sCreditsData->monToShow[sCreditsData->currShownMon], 
                                    sMonSpritePos[sCreditsData->nextImgPos][0], 
                                    sMonSpritePos[sCreditsData->nextImgPos][1], 
                                    sCreditsData->nextImgPos);
        if (sCreditsData->currShownMon < sCreditsData->numMonToShow - 1)
        {
            sCreditsData->currShownMon++;
            gSprites[r2].data[3] = 50;
        }
        else
        {
            sCreditsData->currShownMon = 0;
            gSprites[r2].data[3] = 512;
        }
        sCreditsData->imgCounter++;

        if (sCreditsData->nextImgPos == POS_RIGHT)
            sCreditsData->nextImgPos = POS_LEFT;
        else
            sCreditsData->nextImgPos++;

        gTasks[taskIdD].data[TDD_3] = 50;
        gTasks[taskIdD].data[TDD_STATE]++;
        break;
    case 3:
        if (gTasks[taskIdD].data[TDD_3] != 0)
            gTasks[taskIdD].data[TDD_3]--;
        else
            gTasks[taskIdD].data[TDD_STATE] = 1;
        break;
    }
}

static void sub_817624C(u8 taskIdC)
{
    switch (gTasks[taskIdC].data[TDC_0])
    {
    case 0:
        gIntroCredits_MovingSceneryVOffset = Sin((gTasks[taskIdC].data[TDC_5] >> 1) & 0x7F, 12);
        gTasks[taskIdC].data[TDC_5]++;
        break;
    case 1:
        if (gIntroCredits_MovingSceneryVOffset != 0)
        {
            gIntroCredits_MovingSceneryVOffset = Sin((gTasks[taskIdC].data[TDC_5] >> 1) & 0x7F, 12);
            gTasks[taskIdC].data[TDC_5]++;
        }
        else
        {
            gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 2;
            gTasks[taskIdC].data[TDC_5] = 0;
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 2:
        if (gTasks[taskIdC].data[TDC_5] < 64)
        {
            gTasks[taskIdC].data[TDC_5]++;
            gIntroCredits_MovingSceneryVOffset = Sin(gTasks[taskIdC].data[TDC_5] & 0x7F, 20);
        }
        else
        {
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 3:
        gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 3;
        gSprites[gTasks[taskIdC].data[TDC_3]].data[0] = 1;
        gTasks[taskIdC].data[TDC_4] = 120;
        gTasks[taskIdC].data[TDC_0]++;
        break;
    case 4:
        if (gTasks[taskIdC].data[TDC_4] != 0)
        {
            gTasks[taskIdC].data[TDC_4]--;
        }
        else
        {
            gTasks[taskIdC].data[TDC_5] = 64;
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 5:
        if (gTasks[taskIdC].data[TDC_5] > 0)
        {
            gTasks[taskIdC].data[TDC_5]--;
            gIntroCredits_MovingSceneryVOffset = Sin(gTasks[taskIdC].data[TDC_5] & 0x7F, 20);
        }
        else
        {
            gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 1;
            gTasks[taskIdC].data[TDC_0]++;
        }
        break;
    case 6:
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 10:
        gSprites[gTasks[taskIdC].data[TDC_3]].data[0] = 2;
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 20:
        gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 4;
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 30:
        gSprites[gTasks[taskIdC].data[TDC_2]].data[0] = 5;
        gSprites[gTasks[taskIdC].data[TDC_3]].data[0] = 3;
        gTasks[taskIdC].data[TDC_0] = 50;
        break;
    case 50:
        gTasks[taskIdC].data[TDC_0] = 0;
        break;
    }
}

static void sub_817651C(u8 taskIdE)
{
    s16 taskIdC;

    switch (gTasks[taskIdE].data[TDE_0])
    {
    default:
    case 0:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {

            if (gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_B_ID]].data[TDB_CURRENT_PAGE] == 2)
            {
                gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID]].data[TDC_0] = 20;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
        }
        CycleSceneryPalette(0);
        break;
    case 1:
        CycleSceneryPalette(0);
        break;
    case 2:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {
            taskIdC = gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID];

            // Floor to multiple of 128
            if ((gTasks[taskIdC].data[TDC_5] & -128) == 640)
            {
                gTasks[taskIdC].data[TDC_0] = 1;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
        }
        CycleSceneryPalette(1);
        break;
    case 3:
        if (gTasks[taskIdE].data[TDE_1] != 0x7FFF)
        {

            if (gTasks[taskIdE].data[TDE_1] == 0x248)
            {
                gTasks[gTasks[gTasks[taskIdE].data[TDE_TASK_A_ID]].data[TDA_TASK_C_ID]].data[TDC_0] = 10;
                gTasks[taskIdE].data[TDE_1] = 0x7FFF;
            }
            else
            {
                gTasks[taskIdE].data[TDE_1]++;
            }
        }
        CycleSceneryPalette(1);
        break;
    case 4:
        CycleSceneryPalette(2);
        break;
    }
}

static void InitCreditsSceneGfx(u8 scene, u8 taskIdA)
{
    switch (scene)
    {
    case 0:
        gSprites[gTasks[taskIdA].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.x = 272;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.x = 272;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskIdA].tRivalSpriteId].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(0, 0x2000, 0x20, 8);
        break;
    case 1:
        gSprites[gTasks[taskIdA].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.x = 120;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.x = 272;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskIdA].tRivalSpriteId].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(0, 0x2000, 0x20, 8);
        break;
    case 2:
        gSprites[gTasks[taskIdA].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.x = 120;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.x = 272;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskIdA].tRivalSpriteId].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(1, 0x2000, 0x200, 8);
        break;
    case 3:
        gSprites[gTasks[taskIdA].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.x = 120;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.x = -32;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskIdA].tRivalSpriteId].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(1, 0x2000, 0x200, 8);
        break;
    case 4:
        gSprites[gTasks[taskIdA].tPlayerSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tRivalSpriteId].invisible = FALSE;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.x = 88;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.x = 152;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tRivalSpriteId].pos1.y = 46;
        gSprites[gTasks[taskIdA].tPlayerSpriteId].data[0] = 0;
        gSprites[gTasks[taskIdA].tRivalSpriteId].data[0] = 0;
        gTasks[taskIdA].data[TDA_0] = CreateBicycleBgAnimationTask(2, 0x2000, 0x200, 8);
        break;
    }

    gTasks[taskIdA].data[TDA_TASK_E_ID] = CreateTask(sub_817651C, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_0] = scene;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_1] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_E_ID]].data[TDE_TASK_A_ID] = taskIdA;

    gTasks[taskIdA].data[TDA_TASK_C_ID] = CreateTask(sub_817624C, 0);
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_0] = 0;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_1] = taskIdA;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_2] = gTasks[taskIdA].tPlayerSpriteId;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_3] = gTasks[taskIdA].tRivalSpriteId;
    gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_4] = 0;

    if (scene == 2)
        gTasks[gTasks[taskIdA].data[TDA_TASK_C_ID]].data[TDC_5] = 0x45;
}

static bool8 sub_8176AB0(u8 scene, u8 taskIdA)
{
    u8 spriteId;

    switch (gMain.state)
    {
    default:
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 8);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state = 1;
        break;
    case 1:
        gIntroCredits_MovingSceneryVBase = 34;
        gIntroCredits_MovingSceneryVOffset = 0;
        LoadCreditsSceneGraphics(scene);
        gMain.state++;
        break;
    case 2:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBrendan);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsRivalMay);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBicycle);
            LoadSpritePalettes(gSpritePalettes_Credits);

            spriteId = CreateIntroBrendanSprite(120, 46);
            gTasks[taskIdA].tPlayerSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_PlayerCyclist;
            gSprites[spriteId].anims = sAnims_Player;

            spriteId = CreateIntroMaySprite(272, 46);
            gTasks[taskIdA].tRivalSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_RivalCyclist;
            gSprites[spriteId].anims = sAnims_Rival;
        }
        else
        {
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsMay);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsRivalBrendan);
            LoadCompressedSpriteSheet(gSpriteSheet_CreditsBicycle);
            LoadSpritePalettes(gSpritePalettes_Credits);

            spriteId = CreateIntroMaySprite(120, 46);
            gTasks[taskIdA].tPlayerSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_PlayerCyclist;
            gSprites[spriteId].anims = sAnims_Player;

            spriteId = CreateIntroBrendanSprite(272, 46);
            gTasks[taskIdA].tRivalSpriteId = spriteId;
            gSprites[spriteId].callback = SpriteCB_RivalCyclist;
            gSprites[spriteId].anims = sAnims_Rival;
        };
        gMain.state++;
        break;
    case 3:
        InitCreditsSceneGfx(scene, taskIdA);
        SetCreditsSceneBgCnt(scene);
        gMain.state = 0;
        return TRUE;
    }
    return FALSE;
}

static void ResetCreditsTasks(u8 taskIdA)
{
    if (gTasks[taskIdA].data[TDA_0] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_0]);
        gTasks[taskIdA].data[TDA_0] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_C_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_C_ID]);
        gTasks[taskIdA].data[TDA_TASK_C_ID] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_E_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_E_ID]);
        gTasks[taskIdA].data[TDA_TASK_E_ID] = 0;
    }

    if (gTasks[taskIdA].data[TDA_TASK_D_ID] != 0)
    {
        DestroyTask(gTasks[taskIdA].data[TDA_TASK_D_ID]);
        gTasks[taskIdA].data[TDA_TASK_D_ID] = 0;
    }

    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_DESTROY;
}

static void LoadTheEndScreen(u16 arg0, u16 arg1, u16 palOffset)
{
    u16 baseTile;
    u16 i;

    LZ77UnCompVram(sCreditsCopyrightEnd_Gfx, (void *)(VRAM + arg0));
    LoadPalette(gIntroCopyright_Pal, palOffset, sizeof(gIntroCopyright_Pal));

    baseTile = (palOffset / 16) << 12;

    for (i = 0; i < 32 * 32; i++)
        ((u16 *) (VRAM + arg1))[i] = baseTile + 1;
}

static u16 GetLetterMapTile(u8 baseTiles)
{
    u16 out = (baseTiles & 0x3F) + 80;

    if (baseTiles == 0xFF)
        return 1;

    if (baseTiles & (1 << 7))
        out |= 1 << 11;
    if (baseTiles & (1 << 6))
        out |= 1 << 10;

    return out;
}

static void DrawLetterMapTiles(const u8 baseTiles[], u8 baseX, u8 baseY, u16 offset, u16 palette)
{
    u8 y, x;
    const u16 tileOffset = (palette / 16) << 12;

    for (y = 0; y < 5; y++)
    {
        for (x = 0; x < 3; x++)
            ((u16 *) (VRAM + offset + (baseY + y) * 64))[baseX + x] = tileOffset + GetLetterMapTile(baseTiles[y * 3 + x]);
    }
}

static void DrawTheEnd(u16 offset, u16 palette)
{
    u16 pos;
    u16 baseTile = (palette / 16) << 12;

    for (pos = 0; pos < 32 * 32; pos++)
        ((u16 *) (VRAM + offset))[pos] = baseTile + 1;

    DrawLetterMapTiles(sTheEnd_LetterMap_T, 3, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_H, 7, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_E, 11, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_E, 16, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_N, 20, 7, offset, palette);
    DrawLetterMapTiles(sTheEnd_LetterMap_D, 24, 7, offset, palette);
}

#define sState data[0]

static void SpriteCB_PlayerCyclist(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->sState)
    {
    case 0:
        StartSpriteAnimIfDifferent(sprite, 0);
        break;
    case 1:
        StartSpriteAnimIfDifferent(sprite, 1);
        if (sprite->pos1.x > -32)
            sprite->pos1.x--;
        break;
    case 2:
        StartSpriteAnimIfDifferent(sprite, 2);
        break;
    case 3:
        StartSpriteAnimIfDifferent(sprite, 3);
        break;
    case 4:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > 120)
            sprite->pos1.x--;
        break;
    case 5:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > -32)
            sprite->pos1.x--;
        break;
    }
}

static void SpriteCB_RivalCyclist(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        DestroySprite(sprite);
        return;
    }

    switch (sprite->sState)
    {
    case 0:
        sprite->pos2.y = 0;
        StartSpriteAnimIfDifferent(sprite, 0);
        break;
    case 1:
        if (sprite->pos1.x > 200)
            StartSpriteAnimIfDifferent(sprite, 1);
        else
            StartSpriteAnimIfDifferent(sprite, 2);
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 2;
        sprite->pos2.y = -gIntroCredits_MovingSceneryVOffset;
        break;
    case 2:
        sprite->data[7]++;
        StartSpriteAnimIfDifferent(sprite, 0);
        if ((sprite->data[7] & 3) == 0)
            sprite->pos1.x++;
        break;
    case 3:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (sprite->pos1.x > -32)
            sprite->pos1.x--;
        break;
    }
}

#define sPosition data[1]
#define sSpriteId data[6]

static void SpriteCB_CreditsMon(struct Sprite *sprite)
{
    if (gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        FreeAndDestroyMonPicSprite(sprite->sSpriteId);
        return;
    }

    sprite->data[7]++;
    switch (sprite->sState)
    {
    case 0:
    default:
        sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        sprite->oam.matrixNum = sprite->data[1];
        sprite->data[2] = 16;
        SetOamMatrix(sprite->data[1], 0x10000 / sprite->data[2], 0, 0, 0x10000 / sprite->data[2]);
        sprite->invisible = FALSE;
        sprite->sState = 1;
        break;
    case 1:
        if (sprite->data[2] < 256)
        {
            sprite->data[2] += 8;
            SetOamMatrix(sprite->data[1], 0x10000 / sprite->data[2], 0, 0, 0x10000 / sprite->data[2]);
        }
        else
        {
            sprite->sState++;
        }
        switch (sprite->sPosition)
        {
        case POS_LEFT + 1:
            if ((sprite->data[7] & 3) == 0)
                sprite->pos1.y++;
            sprite->pos1.x -= 2;
            break;
        case POS_CENTER + 1:
            break;
        case POS_RIGHT + 1:
            if ((sprite->data[7] & 3) == 0)
                sprite->pos1.y++;
            sprite->pos1.x += 2;
            break;
        }
        break;
    case 2:
        if (sprite->data[3] != 0)
        {
            sprite->data[3]--;
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
            sprite->oam.objMode = ST_OAM_OBJ_BLEND;
            sprite->data[3] = 16;
            sprite->sState++;
        }
        break;
    case 3:
        if (sprite->data[3] != 0)
        {
            int data3;

            sprite->data[3]--;

            data3 = 16 - sprite->data[3];
            SetGpuReg(REG_OFFSET_BLDALPHA, (data3 << 8) + sprite->data[3]);
        }
        else
        {
            sprite->invisible = TRUE;
            sprite->sState = 9;
        }
        break;
    case 9:
        sprite->sState++;
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        FreeAndDestroyMonPicSprite(sprite->data[6]);
        break;
    }
}

#define sMonSpriteId data[0]

static u8 CreateCreditsMonSprite(u16 nationalDexNum, s16 x, s16 y, u16 position)
{
    u8 monSpriteId;
    u8 bgSpriteId;

    monSpriteId = CreateMonSpriteFromNationalDexNumber(nationalDexNum, x, y, position);
    gSprites[monSpriteId].oam.priority = 1;
    gSprites[monSpriteId].sPosition = position + 1;
    gSprites[monSpriteId].invisible = TRUE;
    gSprites[monSpriteId].callback = SpriteCB_CreditsMon;
    gSprites[monSpriteId].sSpriteId = monSpriteId;

    bgSpriteId = CreateSprite(&sSpriteTemplate_CreditsMonBg, gSprites[monSpriteId].pos1.x, gSprites[monSpriteId].pos1.y, 1);
    gSprites[bgSpriteId].sMonSpriteId = monSpriteId;

    StartSpriteAnimIfDifferent(&gSprites[bgSpriteId], position);

    return monSpriteId;
}

static void SpriteCB_CreditsMonBg(struct Sprite *sprite)
{
    if (gSprites[sprite->sMonSpriteId].data[0] == 10 
     || gIntroCredits_MovingSceneryState != INTROCRED_SCENERY_NORMAL)
    {
        DestroySprite(sprite);
        return;
    }

    // Copy sprite data from the associated Pokémon
    sprite->invisible = gSprites[sprite->sMonSpriteId].invisible;
    sprite->oam.objMode = gSprites[sprite->sMonSpriteId].oam.objMode;
    sprite->oam.affineMode = gSprites[sprite->sMonSpriteId].oam.affineMode;
    sprite->oam.matrixNum = gSprites[sprite->sMonSpriteId].oam.matrixNum;
    sprite->pos1.x = gSprites[sprite->sMonSpriteId].pos1.x;
    sprite->pos1.y = gSprites[sprite->sMonSpriteId].pos1.y;
}

static void DeterminePokemonToShow(void)
{
    u16 starter = SpeciesToNationalPokedexNum(GetStarterPokemon(VarGet(VAR_STARTER_MON)));
    u16 page;
    u16 dexNum;
    u16 j;
    
    // Go through the Pokedex, and anything that has gotten caught we put into our massive array.
    // This basically packs all of the caught pokemon into the front of the array
    for (dexNum = 1, j = 0; dexNum < NATIONAL_DEX_COUNT; dexNum++)
    {
        if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
        {
            sCreditsData->caughtMonIds[j] = dexNum;
            j++;
        }
    }

    // Fill the rest of the array with zeroes
    for (dexNum = j; dexNum < NATIONAL_DEX_COUNT; dexNum++)
        sCreditsData->caughtMonIds[dexNum] = NATIONAL_DEX_NONE;

    // Cap the number of pokemon we care about to NUM_MON_SLIDES, the max we show in the credits scene (-1 for the starter)
    sCreditsData->numCaughtMon = j;
    if (sCreditsData->numCaughtMon < NUM_MON_SLIDES)
        sCreditsData->numMonToShow = j;
    else
        sCreditsData->numMonToShow = NUM_MON_SLIDES;

    // Loop through our list of caught pokemon and select randomly from it to fill the images to show
    j = 0;
    do
    {
        // Select a random mon, insert into array
        page = Random() % sCreditsData->numCaughtMon;
        sCreditsData->monToShow[j] = sCreditsData->caughtMonIds[page];
        
        // Remove the select mon from the array, and condense array entries
        j++;
        sCreditsData->caughtMonIds[page] = 0;
        sCreditsData->numCaughtMon--;
        if (page != sCreditsData->numCaughtMon)
        {
            // Instead of looping through and moving everything down, just take from the end. Order doesn't matter after all.
            sCreditsData->caughtMonIds[page] = sCreditsData->caughtMonIds[sCreditsData->numCaughtMon];
            sCreditsData->caughtMonIds[sCreditsData->numCaughtMon] = 0;
        }
    }
    while (sCreditsData->numCaughtMon != 0 && j < NUM_MON_SLIDES);

    // If we don't have enough pokemon in the dex to fill everything, copy the selected mon into the end of the array, so it loops
    if (sCreditsData->numMonToShow < NUM_MON_SLIDES)
    {
        for (j = sCreditsData->numMonToShow, page = 0; j < NUM_MON_SLIDES; j++)
        {
            sCreditsData->monToShow[j] = sCreditsData->monToShow[page];

            page++;
            if (page == sCreditsData->numMonToShow)
                page = 0;
        }
        // Ensure the last pokemon is our starter
        sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
    }
    else
    {
        // Check to see if our starter has already appeared in this list, break if it has
        for (dexNum = 0; sCreditsData->monToShow[dexNum] != starter && dexNum < NUM_MON_SLIDES; dexNum++);

        // If it has, swap it with the last pokemon, to ensure our starter is the last image
        if (dexNum < sCreditsData->numMonToShow - 1)
        {
            sCreditsData->monToShow[dexNum] = sCreditsData->monToShow[NUM_MON_SLIDES-1];
            sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
        }
        else
        {
            // Ensure the last pokemon is our starter
            sCreditsData->monToShow[NUM_MON_SLIDES - 1] = starter;
        }
    }
    sCreditsData->numMonToShow = NUM_MON_SLIDES;
}
