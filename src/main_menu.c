#include "global.h"
#include "trainer_pokemon_sprites.h"
#include "bg.h"
#include "constants/flags.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "list_menu.h"
#include "mystery_event_menu.h"
#include "naming_screen.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon_3.h"
#include "random.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "window.h"

// Static type declarations

// Static RAM declarations

static EWRAM_DATA u8 gUnknown_02022D04 = 0;
static EWRAM_DATA u16 sCurrItemAndOptionMenuCheck = 0;

static IWRAM_DATA u8 gUnknown_03000DD0;

// Static ROM declarations

u32 InitMainMenu(bool8);
void Task_MainMenuCheckSaveFile(u8);
void Task_MainMenuCheckBattery(u8);
void Task_WaitForSaveFileErrorWindow(u8);
void CreateMainMenuErrorWindow(const u8*);
static void ClearMainMenuWindowTilemap(const struct WindowTemplate*);
void Task_DisplayMainMenu(u8);
void Task_WaitForBatteryDryErrorWindow(u8);
void fmt_savegame(void);
void HighlightSelectedMainMenuItem(u8, u8, s16);
void Task_HandleMainMenuInput(u8);
void Task_HandleMainMenuAPressed(u8);
void Task_HandleMainMenuBPressed(u8);
void task_new_game_prof_birch_speech_1(u8);
void Task_DisplayMainMenuInvalidActionError(u8);
void AddBirchSpeechObjects(u8);
void task_new_game_prof_birch_speech_2(u8);
void sub_8031BAC(u8, u8);
void sub_8031D34(u8, u8);
void task_new_game_prof_birch_speech_3(u8);
void unknown_rbox_to_vram(u8, u8);
void sub_8032318(u8);
void task_new_game_prof_birch_speech_4(u8);
void task_new_game_prof_birch_speech_5(u8);
void sub_80323A0(struct TextSubPrinter *printer, u16 a);
void task_new_game_prof_birch_speech_6(u8);
void sub_8030B14(u8);
void task_new_game_prof_birch_speech_7(u8);
void sub_8031ACC(u8, u8);
void sub_8031C88(u8, u8);
void task_new_game_prof_birch_speech_8(u8);
void task_new_game_prof_birch_speech_9(u8);
void task_new_game_prof_birch_speech_10(u8);
void task_new_game_prof_birch_speech_11(u8);
void LoadMainMenuWindowFrameTiles(u8, u16);
void DrawMainMenuWindowBorder(const struct WindowTemplate*, u16);
void Task_HighlightSelectedMainMenuItem(u8);
void task_new_game_prof_birch_speech_12(u8);
void task_new_game_prof_birch_speech_13(u8);
void sub_8031D74(void);
s8 sub_8031DB4(void);
void sub_80322E0(u8, u8);
void task_new_game_prof_birch_speech_14(u8);
void sub_8030ED4(u8);
void sub_8030F7C(u8);
void task_new_game_prof_birch_speech_15(u8);
void task_new_game_prof_birch_speech_16(u8);
void task_new_game_prof_birch_speech_17(u8);
void new_game_prof_birch_speech_part2_start(void);
void set_default_player_name(u8);
void task_new_game_prof_birch_speech_part2_3(u8);
void task_new_game_prof_birch_speech_part2_4(u8);
void sub_80323CC(u8, u8, u16, u16, u8, u8);
void task_new_game_prof_birch_speech_part2_5(u8);
void task_new_game_prof_birch_speech_part2_6(u8);
void task_new_game_prof_birch_speech_part2_7(u8);
void task_new_game_prof_birch_speech_part2_8(u8);
void task_new_game_prof_birch_speech_part2_9(u8);
void sub_80318D8(struct Sprite*);
void task_new_game_prof_birch_speech_part2_10(u8);
void task_new_game_prof_birch_speech_part2_11(u8);
void task_new_game_prof_birch_speech_part2_12(u8);
void nullsub_11();
void task_new_game_prof_birch_speech_part2_1(u8);
void fmt_time(void);
void fmt_pokedex(void);
void fmt_player(void);
void fmt_badges(void);
void sub_8032474(u8, u8, u8, u8, u8, u8);

// .rodata

const u16 gUnknown_082FECFC[][16] = {
    INCBIN_U16("graphics/birch_speech/bg0.gbapal"),
    INCBIN_U16("graphics/birch_speech/bg1.gbapal")
};

const u8 gBirchIntroShadowGfx[] = INCBIN_U8("graphics/birch_speech/shadow.4bpp.lz");
const u8 gUnknown_082FEEF0[] = INCBIN_U8("graphics/birch_speech/map.bin.lz");
const u16 gUnknown_082FF018[] = INCBIN_U16("graphics/birch_speech/bg2.gbapal");
const u16 gUnknown_082FF028[] = {0, 0, 0, 0, 0, 0, 0, 0};

#define MENU_LEFT 2
#define MENU_TOP_WIN0 1
#define MENU_TOP_WIN1 5
#define MENU_TOP_WIN2 1
#define MENU_TOP_WIN3 9
#define MENU_TOP_WIN4 13
#define MENU_TOP_WIN5 17
#define MENU_TOP_WIN6 21
#define MENU_WIDTH 26
#define MENU_HEIGHT_WIN0 2
#define MENU_HEIGHT_WIN1 2
#define MENU_HEIGHT_WIN2 6
#define MENU_HEIGHT_WIN3 2
#define MENU_HEIGHT_WIN4 2
#define MENU_HEIGHT_WIN5 2
#define MENU_HEIGHT_WIN6 2

#define MENU_LEFT_ERROR 2
#define MENU_TOP_ERROR 15
#define MENU_WIDTH_ERROR 26
#define MENU_HEIGHT_ERROR 4

#define MENU_SHADOW_PADDING 1

#define MENU_WIN_HCOORDS WIN_RANGE(((MENU_LEFT - 1) * 8) + MENU_SHADOW_PADDING, (MENU_LEFT + MENU_WIDTH + 1) * 8 - MENU_SHADOW_PADDING)
#define MENU_WIN_VCOORDS(n) WIN_RANGE(((MENU_TOP_WIN##n - 1) * 8) + MENU_SHADOW_PADDING, (MENU_TOP_WIN##n + MENU_HEIGHT_WIN##n + 1) * 8 - MENU_SHADOW_PADDING)
#define MENU_SCROLL_SHIFT WIN_RANGE(32, 32)

const struct WindowTemplate sWindowTemplates_MainMenu[] =
{
    // No saved game
    // NEW GAME
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN0,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN0,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // OPTIONS
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN1,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN1,
        .paletteNum = 15,
        .baseBlock = 0x35
    },
    // Has saved game
    // CONTINUE
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN2,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // NEW GAME
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN3,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN3,
        .paletteNum = 15,
        .baseBlock = 0x9D
    },
    // OPTION / MYSTERY GIFT
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN4,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN4,
        .paletteNum = 15,
        .baseBlock = 0xD1
    },
    // OPTION / MYSTERY EVENTS
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN5,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN5,
        .paletteNum = 15,
        .baseBlock = 0x105
    },
    // OPTION
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN6,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN6,
        .paletteNum = 15,
        .baseBlock = 0x139
    },
    // Error message window
    {
        .priority = 0,
        .tilemapLeft = MENU_LEFT_ERROR,
        .tilemapTop = MENU_TOP_ERROR,
        .width = MENU_WIDTH_ERROR,
        .height = MENU_HEIGHT_ERROR,
        .paletteNum = 15,
        .baseBlock = 0x16D
    },
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_082FF080[] =
{
    {
        .priority = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .priority = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    {
        .priority = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x85
    },
    DUMMY_WIN_TEMPLATE
};

const u16 gMainMenuBgPal[] = INCBIN_U16("graphics/misc/main_menu_bg.gbapal");
const u16 gMainMenuTextPal[] = INCBIN_U16("graphics/misc/main_menu_text.gbapal");

const u8 gTextColor_Headers[] = {10, 11, 12};
const u8 gUnknown_082FF0E3[] = {10, 1, 12};

const struct BgTemplate gUnknown_082FF0E8[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

const struct BgTemplate gUnknown_082FF0F0 = {
    .bg = 0,
    .charBaseIndex = 3,
    .mapBaseIndex = 30,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0
};

const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu = {2, 0x78, 8, 3, 0x78, 0x98, 3, 4, 1, 1, 0};

const union AffineAnimCmd gUnknown_082FF104[] = {
    AFFINEANIMCMD_FRAME(-2, -2, 0, 0x30),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd *const gUnknown_082FF114 = gUnknown_082FF104;

const struct MenuAction gUnknown_082FF118[] = {
    {gText_BirchBoy, NULL},
    {gText_BirchGirl, NULL}
};

const u8 *const gMalePresetNames[] = {
    gText_DefaultNameStu,
	gText_DefaultNameMilton,
	gText_DefaultNameTom,
	gText_DefaultNameKenny,
	gText_DefaultNameReid,
	gText_DefaultNameJude,
	gText_DefaultNameJaxson,
	gText_DefaultNameEaston,
	gText_DefaultNameWalker,
	gText_DefaultNameTeru,
	gText_DefaultNameJohnny,
	gText_DefaultNameBrett,
	gText_DefaultNameSeth,
	gText_DefaultNameTerry,
	gText_DefaultNameCasey,
	gText_DefaultNameDarren,
	gText_DefaultNameLandon,
	gText_DefaultNameCollin,
	gText_DefaultNameStanley,
	gText_DefaultNameQuincy
};

const u8 *const gFemalePresetNames[] = {
    gText_DefaultNameKimmy,
    gText_DefaultNameTiara,
    gText_DefaultNameBella,
    gText_DefaultNameJayla,
    gText_DefaultNameAllie,
    gText_DefaultNameLianna,
    gText_DefaultNameSara,
    gText_DefaultNameMonica,
    gText_DefaultNameCamila,
    gText_DefaultNameAubree,
    gText_DefaultNameRuthie,
    gText_DefaultNameHazel,
    gText_DefaultNameNadine,
    gText_DefaultNameTanja,
    gText_DefaultNameYasmin,
    gText_DefaultNameNicola,
    gText_DefaultNameLillie,
    gText_DefaultNameTerra,
    gText_DefaultNameLucy,
    gText_DefaultNameHalie
};

// .text

enum
{
    HAS_NO_SAVED_GAME,  //NEW GAME, OPTION
    HAS_SAVED_GAME,     //CONTINUE, NEW GAME, OPTION
    HAS_MYSTERY_GIFT,   //CONTINUE, NEW GAME, MYSTERY GIFT, OPTION
    HAS_MYSTERY_EVENTS, //CONTINUE, NEW GAME, MYSTERY GIFT, MYSTERY EVENTS, OPTION
};

enum {
    ACTION_NEW_GAME,
    ACTION_CONTINUE,
    ACTION_OPTION,
    ACTION_MYSTERY_GIFT,
    ACTION_MYSTERY_EVENTS,
    ACTION_UNKNOWN, // TODO: change when rom_8011DC0 decompiled
    ACTION_INVALID
};

#define MAIN_MENU_BORDER_TILE   0x1D5

void CB2_MainMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void VBlankCB_MainMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitMainMenu(void)
{
    InitMainMenu(FALSE);
}

void CB2_ReinitMainMenu(void)
{
    InitMainMenu(TRUE);
}

u32 InitMainMenu(bool8 returningFromOptionsMenu)
{
    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);

    ResetPaletteFade();
    LoadPalette(gMainMenuBgPal, 0, 32);
    LoadPalette(gMainMenuTextPal, 0xF0, 32);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    if (returningFromOptionsMenu)
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0x0000); // fade to black
    else
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0xFFFF); // fade to white
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_082FF0E8, ARRAY_COUNT(gUnknown_082FF0E8));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    InitWindows(sWindowTemplates_MainMenu);
    DeactivateAllTextPrinters();
    LoadMainMenuWindowFrameTiles(0, MAIN_MENU_BORDER_TILE);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    HideBg(1);
    CreateTask(Task_MainMenuCheckSaveFile, 0);

    return 0;
}

#define tMenuType data[0]
#define tCurrItem data[1]
#define tItemCount data[12]
#define tScrollArrowTaskId data[13]
#define tIsScrolled data[14]
#define tWirelessAdapterConnected data[15]

#define tArrowTaskIsScrolled data[15]   // For scroll indicator arrow task

void Task_MainMenuCheckSaveFile(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);

        if (IsWirelessAdapterConnected())
            tWirelessAdapterConnected = TRUE;
        switch (gSaveFileStatus)
        {
            case 1:
                tMenuType = HAS_SAVED_GAME;
                if (IsMysteryGiftEnabled())
                    tMenuType++;
                gTasks[taskId].func = Task_MainMenuCheckBattery;
                break;
            case 2:
                CreateMainMenuErrorWindow(gText_SaveFileErased);
                tMenuType = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                break;
            case 0xFF:
                CreateMainMenuErrorWindow(gText_SaveFileCorrupted);
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                tMenuType = HAS_SAVED_GAME;
                if (IsMysteryGiftEnabled() == TRUE)
                    tMenuType++;
                break;
            case 0:
            default:
                tMenuType = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_MainMenuCheckBattery;
                break;
            case 4:
                CreateMainMenuErrorWindow(gJPText_No1MSubCircuit);
                gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                break;
        }
        if (sCurrItemAndOptionMenuCheck & 0x8000)   // are we returning from the options menu?
        {
            switch (tMenuType)  // if so, highlight the OPTIONS item
            {
                case HAS_NO_SAVED_GAME:
                case HAS_SAVED_GAME:
                    sCurrItemAndOptionMenuCheck = tMenuType + 1;
                    break;
                case HAS_MYSTERY_GIFT:
                    sCurrItemAndOptionMenuCheck = 3;
                    break;
                case HAS_MYSTERY_EVENTS:
                    sCurrItemAndOptionMenuCheck = 4;
                    break;
            }
        }
        sCurrItemAndOptionMenuCheck &= 0x7FFF;  // turn off the "returning from options menu" flag
        tCurrItem = sCurrItemAndOptionMenuCheck;
        tItemCount = tMenuType + 2;
    }
}

void Task_WaitForSaveFileErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (gMain.newKeys & A_BUTTON))
    {
        ClearWindowTilemap(7);
        ClearMainMenuWindowTilemap(&sWindowTemplates_MainMenu[7]);
        gTasks[taskId].func = Task_MainMenuCheckBattery;
    }
}

void Task_MainMenuCheckBattery(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);

        if (!(RtcGetErrorStatus() & RTC_ERR_FLAG_MASK))
        {
            gTasks[taskId].func = Task_DisplayMainMenu;
        }
        else
        {
            CreateMainMenuErrorWindow(gText_BatteryRunDry);
            gTasks[taskId].func = Task_WaitForBatteryDryErrorWindow;
        }
    }
}

void Task_WaitForBatteryDryErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (gMain.newKeys & A_BUTTON))
    {
        ClearWindowTilemap(7);
        ClearMainMenuWindowTilemap(&sWindowTemplates_MainMenu[7]);
        gTasks[taskId].func = Task_DisplayMainMenu;
    }
}

void Task_DisplayMainMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16 palette;

    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);

        palette = RGB_BLACK;
        LoadPalette(&palette, 254, 2);

        palette = RGB_WHITE;
        LoadPalette(&palette, 250, 2);

        palette = RGB(12, 12, 12);
        LoadPalette(&palette, 251, 2);

        palette = RGB(26, 26, 25);
        LoadPalette(&palette, 252, 2);

        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            palette = RGB(4, 16, 31);
            LoadPalette(&palette, 241, 2);
        }
        else
        {
            palette = RGB(31, 3, 21);
            LoadPalette(&palette, 241, 2);
        }

        switch (gTasks[taskId].tMenuType)
        {
            case HAS_NO_SAVED_GAME:
            default:
                FillWindowPixelBuffer(0, 0xAA);
                FillWindowPixelBuffer(1, 0xAA);
                AddTextPrinterParameterized3(0, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(1, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuOption);
                PutWindowTilemap(0);
                PutWindowTilemap(1);
                CopyWindowToVram(0, 2);
                CopyWindowToVram(1, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[0], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[1], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_SAVED_GAME:
                FillWindowPixelBuffer(2, 0xAA);
                FillWindowPixelBuffer(3, 0xAA);
                FillWindowPixelBuffer(4, 0xAA);
                AddTextPrinterParameterized3(2, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuContinue);
                AddTextPrinterParameterized3(3, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(4, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuOption);
                fmt_savegame();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_MYSTERY_GIFT:
                FillWindowPixelBuffer(2, 0xAA);
                FillWindowPixelBuffer(3, 0xAA);
                FillWindowPixelBuffer(4, 0xAA);
                FillWindowPixelBuffer(5, 0xAA);
                AddTextPrinterParameterized3(2, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuContinue);
                AddTextPrinterParameterized3(3, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(4, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuMysteryGift);
                AddTextPrinterParameterized3(5, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuOption);
                fmt_savegame();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                CopyWindowToVram(5, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[5], MAIN_MENU_BORDER_TILE);
                break;
            case HAS_MYSTERY_EVENTS:
                FillWindowPixelBuffer(2, 0xAA);
                FillWindowPixelBuffer(3, 0xAA);
                FillWindowPixelBuffer(4, 0xAA);
                FillWindowPixelBuffer(5, 0xAA);
                FillWindowPixelBuffer(6, 0xAA);
                AddTextPrinterParameterized3(2, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuContinue);
                AddTextPrinterParameterized3(3, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuNewGame);
                AddTextPrinterParameterized3(4, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuMysteryGift2);
                AddTextPrinterParameterized3(5, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuMysteryEvents);
                AddTextPrinterParameterized3(6, 1, 0, 1, gTextColor_Headers, -1, gText_MainMenuOption);
                fmt_savegame();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                PutWindowTilemap(6);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                CopyWindowToVram(5, 2);
                CopyWindowToVram(6, 2);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[2], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[3], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[4], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[5], MAIN_MENU_BORDER_TILE);
                DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[6], MAIN_MENU_BORDER_TILE);
                tScrollArrowTaskId = AddScrollIndicatorArrowPair(&sScrollArrowsTemplate_MainMenu, &sCurrItemAndOptionMenuCheck);
                gTasks[tScrollArrowTaskId].func = Task_ScrollIndicatorArrowPairOnMainMenu;
                if (sCurrItemAndOptionMenuCheck == 4)
                {
                    ChangeBgY(0, 0x2000, 1);
                    ChangeBgY(1, 0x2000, 1);
                    tIsScrolled = TRUE;
                    gTasks[tScrollArrowTaskId].tArrowTaskIsScrolled = TRUE;
                }
                break;
        }
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
    }
}

void Task_HighlightSelectedMainMenuItem(u8 taskId)
{
    HighlightSelectedMainMenuItem(gTasks[taskId].tMenuType, gTasks[taskId].tCurrItem, gTasks[taskId].tIsScrolled);
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

bool8 HandleMainMenuInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        IsWirelessAdapterConnected();   // why bother calling this here? debug? Task_HandleMainMenuAPressed will check too
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_HandleMainMenuAPressed;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_WHITEALPHA);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
        gTasks[taskId].func = Task_HandleMainMenuBPressed;
    }
    else if ((gMain.newKeys & DPAD_UP) && tCurrItem > 0)
    {
        if (tMenuType == HAS_MYSTERY_EVENTS && tIsScrolled == TRUE && tCurrItem == 1)
        {
            ChangeBgY(0, 0x2000, 2);
            ChangeBgY(1, 0x2000, 2);
            gTasks[tScrollArrowTaskId].tArrowTaskIsScrolled = tIsScrolled = FALSE;
        }
        tCurrItem--;
        sCurrItemAndOptionMenuCheck = tCurrItem;
        return TRUE;
    }
    else if ((gMain.newKeys & DPAD_DOWN) && tCurrItem < tItemCount - 1)
    {
        if (tMenuType == HAS_MYSTERY_EVENTS && tCurrItem == 3 && tIsScrolled == FALSE)
        {
            ChangeBgY(0, 0x2000, 1);
            ChangeBgY(1, 0x2000, 1);
            gTasks[tScrollArrowTaskId].tArrowTaskIsScrolled = tIsScrolled = TRUE;
        }
        tCurrItem++;
        sCurrItemAndOptionMenuCheck = tCurrItem;
        return TRUE;
    }
    return FALSE;
}

void Task_HandleMainMenuInput(u8 taskId)
{
    if (HandleMainMenuInput(taskId))
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
}

void Task_HandleMainMenuAPressed(u8 taskId)
{
    bool8 wirelessAdapterConnected;
    u8 action;

    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tMenuType == HAS_MYSTERY_EVENTS)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollArrowTaskId);
        sub_819746C(0, 1);
        sub_819746C(1, 1);
        sub_819746C(2, 1);
        sub_819746C(3, 1);
        sub_819746C(4, 1);
        sub_819746C(5, 1);
        sub_819746C(6, 1);
        sub_819746C(7, 1);
        wirelessAdapterConnected = IsWirelessAdapterConnected();
        switch (gTasks[taskId].tMenuType)
        {
            case HAS_NO_SAVED_GAME:
            default:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_NEW_GAME;
                        break;
                    case 1:
                        action = ACTION_OPTION;
                        break;
                }
                break;
            case HAS_SAVED_GAME:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_CONTINUE;
                        break;
                    case 1:
                        action = ACTION_NEW_GAME;
                        break;
                    case 2:
                        action = ACTION_OPTION;
                        break;
                }
                break;
            case HAS_MYSTERY_GIFT:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_CONTINUE;
                        break;
                    case 1:
                        action = ACTION_NEW_GAME;
                        break;
                    case 2:
                        action = ACTION_MYSTERY_GIFT;
                        if (!wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                        }
                        break;
                    case 3:
                        action = ACTION_OPTION;
                        break;
                }
                break;
            case HAS_MYSTERY_EVENTS:
                switch (gTasks[taskId].tCurrItem)
                {
                    case 0:
                    default:
                        action = ACTION_CONTINUE;
                        break;
                    case 1:
                        action = ACTION_NEW_GAME;
                        break;
                    case 2:
                        if (gTasks[taskId].tWirelessAdapterConnected)
                        {
                            action = ACTION_MYSTERY_GIFT;
                            if (!wirelessAdapterConnected)
                            {
                                action = ACTION_INVALID;
                                gTasks[taskId].tMenuType = HAS_NO_SAVED_GAME;
                            }
                        }
                        else if (wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_SAVED_GAME;
                        }
                        else
                        {
                            action = ACTION_UNKNOWN;
                        }
                        break;
                    case 3:
                        if (wirelessAdapterConnected)
                        {
                            action = ACTION_INVALID;
                            gTasks[taskId].tMenuType = HAS_MYSTERY_GIFT;
                        }
                        else
                        {
                            action = ACTION_MYSTERY_EVENTS;
                        }
                        break;
                    case 4:
                        action = ACTION_OPTION;
                        break;
                }
                break;
        }
        ChangeBgY(0, 0, 0);
        ChangeBgY(1, 0, 0);
        switch (action)
        {
            case ACTION_NEW_GAME:
            default:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                gTasks[taskId].func = task_new_game_prof_birch_speech_1;
                break;
            case ACTION_CONTINUE:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                SetMainCallback2(CB2_ContinueSavedGame);
                DestroyTask(taskId);
                break;
            case ACTION_OPTION:
                gMain.savedCallback = CB2_ReinitMainMenu;
                SetMainCallback2(CB2_InitOptionMenu);
                DestroyTask(taskId);
                break;
            case ACTION_MYSTERY_GIFT:
                SetMainCallback2(c2_mystery_gift);
                DestroyTask(taskId);
                break;
            case ACTION_MYSTERY_EVENTS:
                SetMainCallback2(CB2_InitMysteryEventMenu);
                DestroyTask(taskId);
                break;
            case ACTION_UNKNOWN:
                SetMainCallback2(sub_801867C);
                DestroyTask(taskId);
                break;
            case ACTION_INVALID:
                gTasks[taskId].tCurrItem = 0;
                gTasks[taskId].func = Task_DisplayMainMenuInvalidActionError;
                gPlttBufferUnfaded[0xF1] = RGB_WHITE;
                gPlttBufferFaded[0xF1] = RGB_WHITE;
                SetGpuReg(REG_OFFSET_BG2HOFS, 0);
                SetGpuReg(REG_OFFSET_BG2VOFS, 0);
                SetGpuReg(REG_OFFSET_BG1HOFS, 0);
                SetGpuReg(REG_OFFSET_BG1VOFS, 0);
                SetGpuReg(REG_OFFSET_BG0HOFS, 0);
                SetGpuReg(REG_OFFSET_BG0VOFS, 0);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
                return;
        }
        FreeAllWindowBuffers();
        if (action != ACTION_OPTION)
            sCurrItemAndOptionMenuCheck = 0;
        else
            sCurrItemAndOptionMenuCheck |= 0x8000;  // entering the options menu
    }
}

void Task_HandleMainMenuBPressed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tMenuType == 3)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tScrollArrowTaskId);
        sCurrItemAndOptionMenuCheck = 0;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitTitleScreen);
        DestroyTask(taskId);
    }
}

void Task_DisplayMainMenuInvalidActionError(u8 taskId)
{
    switch (gTasks[taskId].tCurrItem)
    {
        case 0:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
            switch (gTasks[taskId].tMenuType)
            {
                case 0:
                    CreateMainMenuErrorWindow(gText_WirelessNotConnected);
                    break;
                case 1:
                    CreateMainMenuErrorWindow(gText_MysteryGiftCantUse);
                    break;
                case 2:
                    CreateMainMenuErrorWindow(gText_MysteryEventsCantUse);
                    break;
            }
            gTasks[taskId].tCurrItem++;
            break;
        case 1:
            if (!gPaletteFade.active)
                gTasks[taskId].tCurrItem++;
            break;
        case 2:
            RunTextPrinters();
            if (!IsTextPrinterActive(7))
                gTasks[taskId].tCurrItem++;
            break;
        case 3:
            if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_HandleMainMenuBPressed;
            }
    }
}

#undef tMenuType
#undef tCurrItem
#undef tItemCount
#undef tScrollArrowTaskId
#undef tIsScrolled
#undef tWirelessAdapterConnected

#undef tArrowTaskIsScrolled

void HighlightSelectedMainMenuItem(u8 menuType, u8 selectedMenuItem, s16 isScrolled)
{
    SetGpuReg(REG_OFFSET_WIN0H, MENU_WIN_HCOORDS);

    switch (menuType)
    {
        case HAS_NO_SAVED_GAME:
        default:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(0));
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(1));
                    break;
            }
            break;
        case HAS_SAVED_GAME:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(2));
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3));
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4));
                    break;
            }
            break;
        case HAS_MYSTERY_GIFT:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(2));
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3));
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4));
                    break;
                case 3:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5));
                    break;
            }
            break;
        case HAS_MYSTERY_EVENTS:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(2));
                    break;
                case 1:
                    if (isScrolled)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(3));
                    break;
                case 2:
                    if (isScrolled)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(4));
                    break;
                case 3:
                    if (isScrolled)
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5) - MENU_SCROLL_SHIFT);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(5));
                    break;
                case 4:
                    SetGpuReg(REG_OFFSET_WIN0V, MENU_WIN_VCOORDS(6) - MENU_SCROLL_SHIFT);
                    break;
            }
            break;
    }
}

void task_new_game_prof_birch_speech_1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgFromTemplate(&gUnknown_082FF0F0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    LZ77UnCompVram(gBirchIntroShadowGfx, (void*)VRAM);
    LZ77UnCompVram(gUnknown_082FEEF0, (void*)(VRAM + 0x3800));
    LoadPalette(gUnknown_082FECFC, 0, 64);
    LoadPalette(gUnknown_082FF028, 1, 16);
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddBirchSpeechObjects(taskId);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
    gTasks[taskId].data[4] = 0;
    gTasks[taskId].func = task_new_game_prof_birch_speech_2;
    gTasks[taskId].data[2] = 0xFF;
    gTasks[taskId].data[3] = 0xFF;
    gTasks[taskId].data[7] = 0xD8;
    PlayBGM(MUS_DOORO_X4);
    ShowBg(0);
    ShowBg(1);
}

void task_new_game_prof_birch_speech_2(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[7])
    {
        gTasks[taskId].data[7]--;
    }
    else
    {
        spriteId = gTasks[taskId].data[8];
        gSprites[spriteId].pos1.x = 0x88;
        gSprites[spriteId].pos1.y = 0x3C;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = 1;
        sub_8031BAC(taskId, 10);
        sub_8031D34(taskId, 20);
        gTasks[taskId].data[7] = 0x50;
        gTasks[taskId].func = task_new_game_prof_birch_speech_3;
    }
}

void task_new_game_prof_birch_speech_3(u8 taskId)
{
    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[8]].oam.objMode = 0;
        if (gTasks[taskId].data[7])
        {
            gTasks[taskId].data[7]--;
        }
        else
        {
            InitWindows(gUnknown_082FF080);
            LoadMainMenuWindowFrameTiles(0, 0xF3);
            LoadMessageBoxGfx(0, 0xFC,  0xF0);
            unknown_rbox_to_vram(0, 1);
            PutWindowTilemap(0);
            CopyWindowToVram(0, 2);
            sub_8032318(0);
            StringExpandPlaceholders(gStringVar4, gText_Birch_Welcome);
            AddTextPrinterForMessage(1);
            gTasks[taskId].func = task_new_game_prof_birch_speech_4;
        }
    }
}

void task_new_game_prof_birch_speech_4(u8 taskId)
{
    if (!gPaletteFade.active && !sub_8197224())
    {
        gTasks[taskId].func = task_new_game_prof_birch_speech_5;
        StringExpandPlaceholders(gStringVar4, gText_ThisIsAPokemon);
        AddTextPrinterWithCallbackForMessage(1, sub_80323A0);
        gUnknown_03000DD0 = taskId;
    }
}

void task_new_game_prof_birch_speech_5(u8 taskId)
{
    if (!sub_8197224())
    {
        StringExpandPlaceholders(gStringVar4, gText_Birch_MainSpeech);
        AddTextPrinterForMessage(1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_6;
    }
}

void sub_8030A70(u8 taskId)
{
    u8 spriteId = gTasks[gUnknown_03000DD0].data[9];

    gSprites[spriteId].pos1.x = 0x64;
    gSprites[spriteId].pos1.y = 0x4B;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].data[0] = 0;

    CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 0x70, 0x3A, 0, 0, 0x20, 0xFFFF, SPECIES_LOTAD);
    gTasks[taskId].func = sub_8030B14;
    gTasks[gUnknown_03000DD0].data[7] = 0;
}

void sub_8030B14(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Sprite *sprite = &gSprites[gTasks[gUnknown_03000DD0].data[9]];

    switch (data[0])
    {
        case 0:
            if (sprite->callback == SpriteCallbackDummy)
            {
                sprite->oam.affineMode = 0;
                goto _08030B98_inc_data0;
            }
            break;
        case 1:
            if (gTasks[gUnknown_03000DD0].data[7] >= 0x60)
            {
                DestroyTask(taskId);
                if (gTasks[gUnknown_03000DD0].data[7] < 0x4000)
                    gTasks[gUnknown_03000DD0].data[7]++;
            }
            break;
        _08030B98_inc_data0:
        default:
            data[0]++;
            if (gTasks[gUnknown_03000DD0].data[7] < 0x4000)
                gTasks[gUnknown_03000DD0].data[7]++;
            break;
    }
}

void task_new_game_prof_birch_speech_6(u8 taskId)
{
    if (!sub_8197224())
    {
        gUnknown_02022D04 = 0;
        StringExpandPlaceholders(gStringVar4, gText_Birch_AndYouAre);
        AddTextPrinterForMessage(1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_7;
    }
}

void task_new_game_prof_birch_speech_7(u8 taskId)
{
    if (!sub_8197224())
    {
        gSprites[gTasks[taskId].data[8]].oam.objMode = 1;
        gSprites[gTasks[taskId].data[9]].oam.objMode = 1;
        sub_8031ACC(taskId, 2);
        sub_8031C88(taskId, 1);
        gTasks[taskId].data[7] = 0x40;
        gTasks[taskId].func = task_new_game_prof_birch_speech_8;
    }
}

void task_new_game_prof_birch_speech_8(u8 taskId)
{
    if (gTasks[taskId].data[4] != -60)
    {
        gTasks[taskId].data[4] -= 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].data[4]);
    }
    else
    {
        gTasks[taskId].data[4] = -60;
        gTasks[taskId].func = task_new_game_prof_birch_speech_9;
    }
}

void task_new_game_prof_birch_speech_9(u8 taskId)
{
    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[8]].invisible = TRUE;
        gSprites[gTasks[taskId].data[9]].invisible = TRUE;
        if (gTasks[taskId].data[7])
        {
            gTasks[taskId].data[7]--;
        }
        else
        {
            u8 spriteId = gTasks[taskId].data[10];

            gSprites[spriteId].pos1.x = 0xB4;
            gSprites[spriteId].pos1.y = 0x3C;
            gSprites[spriteId].invisible = FALSE;
            gSprites[spriteId].oam.objMode = 1;
            gTasks[taskId].data[2] = spriteId;
            gTasks[taskId].data[6] = 0;
            sub_8031BAC(taskId, 2);
            sub_8031D34(taskId, 1);
            gTasks[taskId].func = task_new_game_prof_birch_speech_10;
        }
    }
}

void task_new_game_prof_birch_speech_10(u8 taskId)
{
    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[2]].oam.objMode = 0;
        gTasks[taskId].func = task_new_game_prof_birch_speech_11;
    }
}

void task_new_game_prof_birch_speech_11(u8 taskId)
{
    sub_8032318(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_BoyOrGirl);
    AddTextPrinterForMessage(1);
    gTasks[taskId].func = task_new_game_prof_birch_speech_12;
}

void task_new_game_prof_birch_speech_12(u8 taskId)
{
    if (!sub_8197224())
    {
        sub_8031D74();
        gTasks[taskId].func = task_new_game_prof_birch_speech_13;
    }
}

void task_new_game_prof_birch_speech_13(u8 taskId)
{
    int gender = sub_8031DB4();
    int r3;

    switch (gender)
    {
        case MALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            sub_80322E0(1, 1);
            gTasks[taskId].func = task_new_game_prof_birch_speech_14;
            break;
        case FEMALE:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = gender;
            sub_80322E0(1, 1);
            gTasks[taskId].func = task_new_game_prof_birch_speech_14;
            break;
    }
    r3 = GetMenuCursorPos();
    if (r3 != gTasks[taskId].data[6])
    {
        gTasks[taskId].data[6] = r3;
        gSprites[gTasks[taskId].data[2]].oam.objMode = 1;
        sub_8031ACC(taskId, 0);
        gTasks[taskId].func = sub_8030ED4;
    }
}

void sub_8030ED4(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[2];
    if (gTasks[taskId].data[5] == 0)
    {
        gSprites[spriteId].pos1.x += 4;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].data[6])
            spriteId = gTasks[taskId].data[11];
        else
            spriteId = gTasks[taskId].data[10];
        gSprites[spriteId].pos1.x = 0xF0;
        gSprites[spriteId].pos1.y = 0x3C;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].data[2] = spriteId;
        gSprites[spriteId].oam.objMode = 1;
        sub_8031BAC(taskId, 0);
        gTasks[taskId].func = sub_8030F7C;
    }
}

void sub_8030F7C(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[2];

    if (gSprites[spriteId].pos1.x > 0xB4)
    {
        gSprites[spriteId].pos1.x -= 4;
    }
    else
    {
        gSprites[spriteId].pos1.x = 0xB4;
        if (gTasks[taskId].data[5])
        {
            gSprites[spriteId].oam.objMode = 0;
            gTasks[taskId].func = task_new_game_prof_birch_speech_13;
        }
    }
}

void task_new_game_prof_birch_speech_14(u8 taskId)
{
    sub_8032318(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_WhatsYourName);
    AddTextPrinterForMessage(1);
    gTasks[taskId].func = task_new_game_prof_birch_speech_15;
}

void task_new_game_prof_birch_speech_15(u8 taskId)
{
    if (!sub_8197224())
        gTasks[taskId].func = task_new_game_prof_birch_speech_16;
}

void task_new_game_prof_birch_speech_16(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = task_new_game_prof_birch_speech_17;
    }
}

void task_new_game_prof_birch_speech_17(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[9]);
        set_default_player_name(Random() % 20);
        DestroyTask(taskId);
        DoNamingScreen(0, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, new_game_prof_birch_speech_part2_start);
    }
}

void task_new_game_prof_birch_speech_part2_2(u8 taskId)
{
    sub_8032318(0);
    StringExpandPlaceholders(gStringVar4, gText_Birch_SoItsPlayer);
    AddTextPrinterForMessage(1);
    gTasks[taskId].func = task_new_game_prof_birch_speech_part2_3;
}

void task_new_game_prof_birch_speech_part2_3(u8 taskId)
{
    if (!sub_8197224())
    {
        sub_80323CC(2, 1, 0xF3, 0xDF, 2, 15);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_4;
    }
}

void task_new_game_prof_birch_speech_part2_4(u8 taskId)
{
    switch (Menu_ProcessInputNoWrap_())
    {
        case 0:
            PlaySE(SE_SELECT);
            gSprites[gTasks[taskId].data[2]].oam.objMode = 1;
            sub_8031ACC(taskId, 2);
            sub_8031C88(taskId, 1);
            gTasks[taskId].func = task_new_game_prof_birch_speech_part2_5;
            break;
        case -1:
        case 1:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = task_new_game_prof_birch_speech_11;
    }
}

void task_new_game_prof_birch_speech_part2_5(u8 taskId)
{
    if (gTasks[taskId].data[4])
    {
        gTasks[taskId].data[4] += 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].data[4]);
    }
    else
    {
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_6;
    }
}

void task_new_game_prof_birch_speech_part2_6(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[10]].invisible = TRUE;
        gSprites[gTasks[taskId].data[11]].invisible = TRUE;
        spriteId = gTasks[taskId].data[8];
        gSprites[spriteId].pos1.x = 0x88;
        gSprites[spriteId].pos1.y = 0x3C;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = 1;
        spriteId = gTasks[taskId].data[9];
        gSprites[spriteId].pos1.x = 0x64;
        gSprites[spriteId].pos1.y = 0x4B;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = 1;
        sub_8031BAC(taskId, 2);
        sub_8031D34(taskId, 1);
        sub_8032318(0);
        StringExpandPlaceholders(gStringVar4, gText_Birch_YourePlayer);
        AddTextPrinterForMessage(1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_7;
    }
}

void task_new_game_prof_birch_speech_part2_7(u8 taskId)
{
    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[8]].oam.objMode = 0;
        gSprites[gTasks[taskId].data[9]].oam.objMode = 0;
        if (!sub_8197224())
        {
            gSprites[gTasks[taskId].data[8]].oam.objMode = 1;
            gSprites[gTasks[taskId].data[9]].oam.objMode = 1;
            sub_8031ACC(taskId, 2);
            sub_8031C88(taskId, 1);
            gTasks[taskId].data[7] = 64;
            gTasks[taskId].func = task_new_game_prof_birch_speech_part2_8;
        }
    }
}

void task_new_game_prof_birch_speech_part2_8(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[8]].invisible = TRUE;
        gSprites[gTasks[taskId].data[9]].invisible = TRUE;
        if (gTasks[taskId].data[7])
        {
            gTasks[taskId].data[7]--;
            return;
        }
        if (gSaveBlock2Ptr->playerGender != MALE)
            spriteId = gTasks[taskId].data[11];
        else
            spriteId = gTasks[taskId].data[10];
        gSprites[spriteId].pos1.x = 0x78;
        gSprites[spriteId].pos1.y = 0x3C;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = 1;
        gTasks[taskId].data[2] = spriteId;
        sub_8031BAC(taskId, 2);
        sub_8031D34(taskId, 1);
        StringExpandPlaceholders(gStringVar4, gText_Birch_AreYouReady);
        AddTextPrinterForMessage(1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_9;
    }
}

void task_new_game_prof_birch_speech_part2_9(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[5])
    {
        gSprites[gTasks[taskId].data[2]].oam.objMode = 0;
        if (!sub_8197224())
        {
            spriteId = gTasks[taskId].data[2];
            gSprites[spriteId].oam.affineMode = 1;
            gSprites[spriteId].affineAnims = &gUnknown_082FF114;
            InitSpriteAffineAnim(&gSprites[spriteId]);
            StartSpriteAffineAnim(&gSprites[spriteId], 0);
            gSprites[spriteId].callback = sub_80318D8;
            BeginNormalPaletteFade(0x0000FFFF, 0, 0, 16, RGB_BLACK);
            FadeOutBGM(4);
            gTasks[taskId].func = task_new_game_prof_birch_speech_part2_10;
        }
    }
}

void task_new_game_prof_birch_speech_part2_10(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[2];

    if (gSprites[spriteId].affineAnimEnded)
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_11;
}

void task_new_game_prof_birch_speech_part2_11(u8 taskId)
{
    u8 spriteId;

    if (!gPaletteFade.active)
    {
        spriteId = gTasks[taskId].data[2];
        gSprites[spriteId].callback = nullsub_11;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        BeginNormalPaletteFade(0xFFFF0000, 0, 0, 16, RGB_WHITEALPHA);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_12;
    }
}

void task_new_game_prof_birch_speech_part2_12(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].data[9]);
        ResetAllPicSprites();
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
    }
}

void new_game_prof_birch_speech_part2_start(void)
{
    u8 taskId;
    u8 spriteId;
    u16 savedIme;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, gUnknown_082FF0E8, 2);
    InitBgFromTemplate(&gUnknown_082FF0F0);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    LZ77UnCompVram(gBirchIntroShadowGfx, (u8*)VRAM);
    LZ77UnCompVram(gUnknown_082FEEF0, (u8*)(VRAM + 0x3800));
    LoadPalette(gUnknown_082FECFC, 0, 64);
    LoadPalette(&gUnknown_082FF018[1], 1, 16);
    ResetTasks();
    taskId = CreateTask(task_new_game_prof_birch_speech_part2_1, 0);
    gTasks[taskId].data[7] = 5;
    gTasks[taskId].data[4] = -60;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddBirchSpeechObjects(taskId);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        gTasks[taskId].data[6] = FEMALE;
        spriteId = gTasks[taskId].data[11];
    }
    else
    {
        gTasks[taskId].data[6] = MALE;
        spriteId = gTasks[taskId].data[10];
    }
    gSprites[spriteId].pos1.x = 0xB4;
    gSprites[spriteId].pos1.y = 0x3C;
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].data[2] = spriteId;
    SetGpuReg(REG_OFFSET_BG1HOFS, -60);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    ShowBg(0);
    ShowBg(1);
    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= 1;
    REG_IME = savedIme;
    SetVBlankCallback(VBlankCB_MainMenu);
    SetMainCallback2(CB2_MainMenu);
    InitWindows(gUnknown_082FF080);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, 0xFC, 0xF0);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

void nullsub_11(struct Sprite *sprite)
{
}

void sub_80318D8(struct Sprite *sprite)
{
    u32 y;

    y = (sprite->pos1.y << 16) + sprite->data[0] + 0xC000;
    sprite->pos1.y = y >> 16;
    sprite->data[0] = y;
}

u8 sub_80318F4(u8 a, u8 b)
{
    return CreatePicSprite2(SPECIES_LOTAD, 8, 0, 1, a, b, 14, -1);
}

void AddBirchSpeechObjects(u8 taskId)
{
    u8 spriteId = AddNewGameBirchObject(0x88, 0x3C, 1);
    u8 spriteId2;
    u8 spriteId3;
    u8 spriteId4;

    gSprites[spriteId].callback = nullsub_11;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].invisible = TRUE;
    gTasks[taskId].data[8] = spriteId;
    spriteId2 = sub_80318F4(100, 0x4B);
    gSprites[spriteId2].callback = nullsub_11;
    gSprites[spriteId2].oam.priority = 0;
    gSprites[spriteId2].invisible = TRUE;
    gTasks[taskId].data[9] = spriteId2;
    spriteId3 = CreateTrainerSprite(FacilityClassToPicIndex(0x3C), 0x78, 0x3C, 0, gDecompressionBuffer);
    gSprites[spriteId3].callback = nullsub_11;
    gSprites[spriteId3].invisible = TRUE;
    gSprites[spriteId3].oam.priority = 0;
    gTasks[taskId].data[10] = spriteId3;
    spriteId4 = CreateTrainerSprite(FacilityClassToPicIndex(0x3F), 0x78, 0x3C, 0, &gDecompressionBuffer[0x800]);
    gSprites[spriteId4].callback = nullsub_11;
    gSprites[spriteId4].invisible = TRUE;
    gSprites[spriteId4].oam.priority = 0;
    gTasks[taskId].data[11] = spriteId4;
}

void sub_8031A5C(u8 taskId)
{
    int alpha;

    if (gTasks[taskId].data[1] == 0)
    {
        gTasks[gTasks[taskId].data[0]].data[5] = 1;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].data[4])
    {
        gTasks[taskId].data[4]--;
    }
    else
    {
        gTasks[taskId].data[4] = gTasks[taskId].data[3];
        gTasks[taskId].data[1]--;
        gTasks[taskId].data[2]++;
        alpha = gTasks[taskId].data[2] << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].data[1] + alpha);
    }
}

void sub_8031ACC(u8 taskId, u8 a)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].data[5] = 0;
    taskId2 = CreateTask(sub_8031A5C, 0);
    gTasks[taskId2].data[0] = taskId;
    gTasks[taskId2].data[1] = 16;
    gTasks[taskId2].data[2] = 0;
    gTasks[taskId2].data[3] = a;
    gTasks[taskId2].data[4] = a;
}

void sub_8031B3C(u8 taskId)
{
    int alpha;

    if (gTasks[taskId].data[1] == 16)
    {
        gTasks[gTasks[taskId].data[0]].data[5] = 1;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].data[4])
    {
        gTasks[taskId].data[4]--;
    }
    else
    {
        gTasks[taskId].data[4] = gTasks[taskId].data[3];
        gTasks[taskId].data[1]++;
        gTasks[taskId].data[2]--;
        alpha = gTasks[taskId].data[2] << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].data[1] + alpha);
    }
}

void sub_8031BAC(u8 taskId, u8 a)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].data[5] = 0;
    taskId2 = CreateTask(sub_8031B3C, 0);
    gTasks[taskId2].data[0] = taskId;
    gTasks[taskId2].data[1] = 0;
    gTasks[taskId2].data[2] = 16;
    gTasks[taskId2].data[3] = a;
    gTasks[taskId2].data[4] = a;
}

void sub_8031C1C(u8 taskId)
{
    if (gTasks[taskId].data[2])
    {
        gTasks[taskId].data[2]--;
    }
    else if (gTasks[taskId].data[1] == 8)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].data[4])
    {
        gTasks[taskId].data[4]--;
    }
    else
    {
        gTasks[taskId].data[4] = gTasks[taskId].data[3];
        gTasks[taskId].data[1]++;
        LoadPalette(&gUnknown_082FF018[gTasks[taskId].data[1]], 1, 16);
    }
}

void sub_8031C88(u8 taskId, u8 a)
{
    u8 taskId2;

    taskId2 = CreateTask(sub_8031C1C, 0);
    gTasks[taskId2].data[0] = taskId;
    gTasks[taskId2].data[1] = 0;
    gTasks[taskId2].data[2] = 8;
    gTasks[taskId2].data[3] = a;
    gTasks[taskId2].data[4] = a;
}

void sub_8031CC8(u8 taskId)
{
    if (gTasks[taskId].data[2])
    {
        gTasks[taskId].data[2]--;
    }
    else if (gTasks[taskId].data[1] == 0)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].data[4])
    {
        gTasks[taskId].data[4]--;
    }
    else
    {
        gTasks[taskId].data[4] = gTasks[taskId].data[3];
        gTasks[taskId].data[1]--;
        LoadPalette(&gUnknown_082FF018[gTasks[taskId].data[1]], 1, 16);
    }
}

void sub_8031D34(u8 taskId, u8 a)
{
    u8 taskId2;

    taskId2 = CreateTask(sub_8031CC8, 0);
    gTasks[taskId2].data[0] = taskId;
    gTasks[taskId2].data[1] = 8;
    gTasks[taskId2].data[2] = 8;
    gTasks[taskId2].data[3] = a;
    gTasks[taskId2].data[4] = a;
}

void sub_8031D74(void)
{
    DrawMainMenuWindowBorder(&gUnknown_082FF080[1], 0xF3);
    FillWindowPixelBuffer(1, 17);
    PrintMenuTable(1, 2, gUnknown_082FF118);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}

s8 sub_8031DB4(void)
{
    return Menu_ProcessInputNoWrapAround();
}

void set_default_player_name(u8 nameId)
{
    const u8* name;
    u8 i;

    if (gSaveBlock2Ptr->playerGender == MALE)
        name = gMalePresetNames[nameId];
    else
        name = gFemalePresetNames[nameId];
    for (i = 0; i < 7; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];
    gSaveBlock2Ptr->playerName[7] = 0xFF;
}

void CreateMainMenuErrorWindow(const u8* str)
{
    FillWindowPixelBuffer(7, 17);
    AddTextPrinterParameterized(7, 1, str, 0, 1, 2, 0);
    PutWindowTilemap(7);
    CopyWindowToVram(7, 2);
    DrawMainMenuWindowBorder(&sWindowTemplates_MainMenu[7], MAIN_MENU_BORDER_TILE);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(9, 231));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(113, 159));
}

void fmt_savegame(void)
{
    fmt_time();
    fmt_pokedex();
    fmt_player();
    fmt_badges();
}

void fmt_time(void)
{
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuPlayer);
    AddTextPrinterParameterized3(2, 1, 0, 17, gUnknown_082FF0E3, -1, gStringVar4);
    AddTextPrinterParameterized3(2, 1, GetStringRightAlignXOffset(1, gSaveBlock2Ptr->playerName, 100), 17, gUnknown_082FF0E3, -1, gSaveBlock2Ptr->playerName);
}

void fmt_player(void)
{
    u8 str[0x20];
    u8* ptr;

    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuTime);
    AddTextPrinterParameterized3(2, 1, 0x6C, 17, gUnknown_082FF0E3, -1, gStringVar4);
    ptr = ConvertIntToDecimalStringN(str, gSaveBlock2Ptr->playTimeHours, 0, 3);
    *ptr = 0xF0;
    ConvertIntToDecimalStringN(ptr + 1, gSaveBlock2Ptr->playTimeMinutes, 2, 2);
    AddTextPrinterParameterized3(2, 1, GetStringRightAlignXOffset(1, str, 0xD0), 17, gUnknown_082FF0E3, -1, str);
}

void fmt_pokedex(void)
{
    u8 str[0x20];
    u16 dexCount;

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        if (IsNationalPokedexEnabled())
            dexCount = GetNationalPokedexCount(1);
        else
            dexCount = GetHoennPokedexCount(1);
        StringExpandPlaceholders(gStringVar4, gText_ContinueMenuPokedex);
        AddTextPrinterParameterized3(2, 1, 0, 33, gUnknown_082FF0E3, -1, gStringVar4);
        ConvertIntToDecimalStringN(str, dexCount, 0, 3);
        AddTextPrinterParameterized3(2, 1, GetStringRightAlignXOffset(1, str, 100), 33, gUnknown_082FF0E3, -1, str);
    }
}

void fmt_badges(void)
{
    u8 str[0x20];
    u8 badgeCount = 0;
    u32 i;

    for (i = FLAG_BADGE01_GET; i <= FLAG_BADGE08_GET; i++)
    {
        if (FlagGet(i))
            badgeCount++;
    }
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuBadges);
    AddTextPrinterParameterized3(2, 1, 0x6C, 33, gUnknown_082FF0E3, -1, gStringVar4);
    ConvertIntToDecimalStringN(str, badgeCount, 2, 1);
    AddTextPrinterParameterized3(2, 1, GetStringRightAlignXOffset(1, str, 0xD0), 33, gUnknown_082FF0E3, -1, str);
}

void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 32, 32);
}

void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
{
    u16 r9 = 1 + baseTileNum;
    u16 r10 = 2 + baseTileNum;
    u16 sp18 = 3 + baseTileNum;
    u16 spC = 5 + baseTileNum;
    u16 sp10 = 6 + baseTileNum;
    u16 sp14 = 7 + baseTileNum;
    u16 r6 = 8 + baseTileNum;

    FillBgTilemapBufferRect(template->priority, baseTileNum, template->tilemapLeft - 1, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->priority, r9, template->tilemapLeft, template->tilemapTop - 1, template->width, 1, 2);
    FillBgTilemapBufferRect(template->priority, r10, template->tilemapLeft + template->width, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->priority, sp18, template->tilemapLeft - 1, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->priority, spC, template->tilemapLeft + template->width, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->priority, sp10, template->tilemapLeft - 1, template->tilemapTop + template->height, 1, 1, 2);
    FillBgTilemapBufferRect(template->priority, sp14, template->tilemapLeft, template->tilemapTop + template->height, template->width, 1, 2);
    FillBgTilemapBufferRect(template->priority, r6, template->tilemapLeft + template->width, template->tilemapTop + template->height, 1, 1, 2);
    CopyBgTilemapBufferToVram(template->priority);
}

static void ClearMainMenuWindowTilemap(const struct WindowTemplate *template)
{
    FillBgTilemapBufferRect(template->priority, 0, template->tilemapLeft - 1, template->tilemapTop - 1, template->tilemapLeft + template->width + 1, template->tilemapTop + template->height + 1, 2);
    CopyBgTilemapBufferToVram(template->priority);
}

void sub_8032298(u8 a, u8 b, u8 c, u8 d, u8 e, u8 unused)
{
    FillBgTilemapBufferRect(a, 0, b + 0xFF, c + 0xFF, d + 2, e + 2, 2);
}

void sub_80322E0(u8 windowId, u8 a)
{
    CallWindowFunction(windowId, sub_8032298);
    FillWindowPixelBuffer(windowId, 0x11);
    ClearWindowTilemap(windowId);
    if (a == 1)
        CopyWindowToVram(windowId, 3);
}

void sub_8032318(u8 a)
{
    u8 fontAttribute = GetFontAttribute(1, FONTATTR_COLOR_BACKGROUND);
    u8 fontAttribute2 = GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);
    u8 fontAttribute3 = GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT);
    u8 windowAttribute = GetWindowAttribute(a, WINDOW_WIDTH);
    u8 windowAttribute2 = GetWindowAttribute(a, WINDOW_HEIGHT);

    FillWindowPixelRect(a, fontAttribute, 0, 0, fontAttribute2 * windowAttribute, fontAttribute3 * windowAttribute2);
    CopyWindowToVram(a, 2);
}

void sub_80323A0(struct TextSubPrinter *printer, u16 a)
{
    if (*(printer->current_text_offset - 2) == 8 && gUnknown_02022D04 == 0)
    {
        gUnknown_02022D04 = 1;
        CreateTask(sub_8030A70, 0);
    }
}

void sub_80323CC(u8 a, u8 b, u16 c, u16 d, u8 e, u8 f)
{
    struct WindowTemplate sp;

    sp = CreateWindowTemplate(0, a + 1, b + 1, 5, 4, f, d);
    CreateYesNoMenu(&sp, c, e, 0);
}

void unknown_rbox_to_vram(u8 windowId, u8 a)
{
    CallWindowFunction(windowId, sub_8032474);
    FillWindowPixelBuffer(windowId, 17);
    PutWindowTilemap(windowId);
    if (a == 1)
        CopyWindowToVram(windowId, 3);
}

void sub_8032474 (u8 a, u8 b, u8 c, u8 d, u8 e, u8 f)
{
    FillBgTilemapBufferRect(a, 0xFD,  b-2,   c-1, 1,   1, f);
    FillBgTilemapBufferRect(a, 0xFF,  b-1,   c-1, 1,   1, f);
    FillBgTilemapBufferRect(a, 0x100, b,     c-1, d,   1, f);
    FillBgTilemapBufferRect(a, 0x101, b+d-1, c-1, 1,   1, f);
    FillBgTilemapBufferRect(a, 0x102, b+d,   c-1, 1,   1, f);
    FillBgTilemapBufferRect(a, 0x103, b-2,   c,   1,   5, f);
    FillBgTilemapBufferRect(a, 0x105, b-1,   c,   d+1, 5, f);
    FillBgTilemapBufferRect(a, 0x106, b+d,   c,   1,   5, f);
    FillBgTilemapBufferRect(a, BG_TILE_V_FLIP(0xFD), b-2,   c+e, 1,   1, f);
    FillBgTilemapBufferRect(a, BG_TILE_V_FLIP(0xFF), b-1,   c+e, 1,   1, f);
    FillBgTilemapBufferRect(a, BG_TILE_V_FLIP(0x100), b,     c+e, d-1, 1, f);
    FillBgTilemapBufferRect(a, BG_TILE_V_FLIP(0x101), b+d-1, c+e, 1,   1, f);
    FillBgTilemapBufferRect(a, BG_TILE_V_FLIP(0x102), b+d,   c+e, 1,   1, f);
}

void task_new_game_prof_birch_speech_part2_1(u8 taskId)
{
    if (gTasks[taskId].data[7]-- <= 0)
    {
        unknown_rbox_to_vram(0, 1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_2;
    }
}
