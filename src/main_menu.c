
// Includes
#include "global.h"
#include "battle_dome_cards.h"
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
#include "menu_indicators.h"
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

EWRAM_DATA u8 gUnknown_02022D04 = 0;
EWRAM_DATA u16 gUnknown_02022D06 = 0;

IWRAM_DATA u8 gUnknown_03000DD0;

// Static ROM declarations

u32 InitMainMenu(bool8);
void Task_MainMenuCheckSaveFile(u8);
void Task_MainMenuCheckBattery(u8);
void Task_WaitForSaveFileErrorWindow(u8);
void CreateMainMenuErrorWindow(const u8*);
void sub_8032250(const struct WindowTemplate*);
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

const struct WindowTemplate gUnknown_082FF038[] = {
    {0, 2, 1, 26, 2, 15, 1},
    {0, 2, 5, 26, 2, 15, 0x35}
};

const struct WindowTemplate gUnknown_082FF048[] = {
    {0, 2, 1, 26, 6, 15, 1},
    {0, 2, 9, 26, 2, 15, 0x9D},
    {0, 2, 13, 26, 2, 15, 0xD1},
    {0, 2, 17, 26, 2, 15, 0x105},
    {0, 2, 21, 26, 2, 15, 0x139}
};

const struct WindowTemplate gUnknown_082FF070[] = {
    {0, 2, 15, 26, 4, 15, 0x16D},
    {0xFF, 0, 0, 0, 0, 0, 0}
};

const struct WindowTemplate gUnknown_082FF080[] = {
    {0, 2, 15, 27, 4, 15, 1},
    {0, 3, 5, 6, 4, 15, 0x6D},
    {0, 3, 2, 9, 10, 15, 0x85},
    {0xFF, 0, 0, 0, 0, 0, 0}
};

const u16 gMainMenuBgPal[] = INCBIN_U16("graphics/misc/main_menu_bg.gbapal");
const u16 gMainMenuTextPal[] = INCBIN_U16("graphics/misc/main_menu_text.gbapal");

const u8 gUnknown_082FF0E0[] = {10, 11, 12};
const u8 gUnknown_082FF0E3[] = {10, 1, 12};

const struct BgTemplate gUnknown_082FF0E8[] = {
    {0, 2, 30, 0, 0, 0, 0},
    {1, 0, 7, 0, 0, 3, 0}
};

const struct BgTemplate gUnknown_082FF0F0 = {0, 3, 30, 0, 0, 0, 0};

const struct ArrowStruct gUnknown_082FF0F4 = {2, 0x78, 8, 3, 0x78, 0x98, 3, 4, 1, 1, 0};

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
    HAS_MYSTERY_GIFT,   //CONTINUE, NEW GAME, MYSTERY EVENTS, OPTION
    HAS_MYSTERY_EVENTS,
};

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

u32 InitMainMenu(bool8 affects_palette_maybe)
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
    if (affects_palette_maybe)
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0x0000); // fade to black
    else
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0xFFFF); // fade to white
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_082FF0E8, 2);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    InitWindows(gUnknown_082FF038);
    DeactivateAllTextPrinters();
    LoadMainMenuWindowFrameTiles(0, 0x1D5);
    
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

void Task_MainMenuCheckSaveFile(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 17);
        SetGpuReg(REG_OFFSET_WINOUT, 0x31);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);
        
        if (sub_80093CC())
            data[15] = 1;
        switch (gSaveFileStatus)
        {
            case 1:
                data[0] = HAS_SAVED_GAME;
                if (IsMysteryGiftEnabled())
                    data[0]++;
                gTasks[taskId].func = Task_MainMenuCheckBattery;
                break;
            case 2:
                CreateMainMenuErrorWindow(gText_SaveFileErased);
                data[0] = 0;
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                break;
            case 0xFF:
                CreateMainMenuErrorWindow(gText_SaveFileCorrupted);
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                data[0] = HAS_SAVED_GAME;
                if (IsMysteryGiftEnabled() == TRUE)
                    data[0]++;
                break;
            case 0:
            default:
                data[0] = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_MainMenuCheckBattery;
                break;
            case 4:
                CreateMainMenuErrorWindow(gJPText_No1MSubCircuit);
                gTasks[taskId].data[0] = HAS_NO_SAVED_GAME;
                gTasks[taskId].func = Task_WaitForSaveFileErrorWindow;
                break;
        }
        if (gUnknown_02022D06 & 0x8000)
        {
            switch (data[0])
            {
                case HAS_NO_SAVED_GAME:
                case HAS_SAVED_GAME:
                    gUnknown_02022D06 = data[0] + 1;
                    break;
                case HAS_MYSTERY_GIFT:
                    gUnknown_02022D06 = 3;
                    break;
                case 3:
                    gUnknown_02022D06 = 4;
                    break;
            }
        }
        gUnknown_02022D06 &= 0x7FFF;
        data[1] = gUnknown_02022D06;
        data[12] = data[0] + 2;
    }
}

void Task_WaitForSaveFileErrorWindow(u8 taskId)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(7) && (gMain.newKeys & A_BUTTON))
    {
        ClearWindowTilemap(7);
        sub_8032250(gUnknown_082FF070);
        gTasks[taskId].func = Task_MainMenuCheckBattery;
    }
}

void Task_MainMenuCheckBattery(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 17);
        SetGpuReg(REG_OFFSET_WINOUT, 0x31);
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
        sub_8032250(gUnknown_082FF070);
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
        SetGpuReg(REG_OFFSET_WININ, 17);
        SetGpuReg(REG_OFFSET_WINOUT, 0x31);
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
        
        
        
        switch (gTasks[taskId].data[0])
        {
            case HAS_NO_SAVED_GAME:
            default:
                FillWindowPixelBuffer(0, 0xAA);
                FillWindowPixelBuffer(1, 0xAA);
                box_print(0, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(1, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuOption);
                PutWindowTilemap(0);
                PutWindowTilemap(1);
                CopyWindowToVram(0, 2);
                CopyWindowToVram(1, 2);
                DrawMainMenuWindowBorder(gUnknown_082FF038, 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF038[1], 0x1D5);
                break;
            case HAS_SAVED_GAME:
                FillWindowPixelBuffer(2, 0xAA);
                FillWindowPixelBuffer(3, 0xAA);
                FillWindowPixelBuffer(4, 0xAA);
                box_print(2, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuContinue);
                box_print(3, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(4, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuOption);
                fmt_savegame();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                DrawMainMenuWindowBorder(gUnknown_082FF048, 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[1], 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[2], 0x1D5);
                break;
            case HAS_MYSTERY_GIFT:
                FillWindowPixelBuffer(2, 0xAA);
                FillWindowPixelBuffer(3, 0xAA);
                FillWindowPixelBuffer(4, 0xAA);
                FillWindowPixelBuffer(5, 0xAA);
                box_print(2, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuContinue);
                box_print(3, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(4, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuMysteryGift);
                box_print(5, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuOption);
                fmt_savegame();
                PutWindowTilemap(2);
                PutWindowTilemap(3);
                PutWindowTilemap(4);
                PutWindowTilemap(5);
                CopyWindowToVram(2, 2);
                CopyWindowToVram(3, 2);
                CopyWindowToVram(4, 2);
                CopyWindowToVram(5, 2);
                DrawMainMenuWindowBorder(gUnknown_082FF048, 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[1], 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[2], 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[3], 0x1D5);
                break;
            case HAS_MYSTERY_EVENTS:
                FillWindowPixelBuffer(2, 0xAA);
                FillWindowPixelBuffer(3, 0xAA);
                FillWindowPixelBuffer(4, 0xAA);
                FillWindowPixelBuffer(5, 0xAA);
                FillWindowPixelBuffer(6, 0xAA);
                box_print(2, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuContinue);
                box_print(3, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(4, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuMysteryGift2);
                box_print(5, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuMysteryEvents);
                box_print(6, 1, 0, 1, gUnknown_082FF0E0, -1, gText_MainMenuOption);
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
                DrawMainMenuWindowBorder(gUnknown_082FF048, 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[1], 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[2], 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[3], 0x1D5);
                DrawMainMenuWindowBorder(&gUnknown_082FF048[4], 0x1D5);
                data[13] = AddScrollIndicatorArrowPair(&gUnknown_082FF0F4, &gUnknown_02022D06);
                gTasks[data[13]].func = Task_ScrollIndicatorArrowPairOnMainMenu;
                if (gUnknown_02022D06 == 4)
                {
                    ChangeBgY(0, 0x2000, 1);
                    ChangeBgY(1, 0x2000, 1);
                    data[14] = 1;
                    gTasks[data[13]].data[15] = 1;
                }
                break;
        }
        gTasks[taskId].func = Task_HighlightSelectedMainMenuItem;
    }
}

void Task_HighlightSelectedMainMenuItem(u8 taskId)
{
    HighlightSelectedMainMenuItem(gTasks[taskId].data[0], gTasks[taskId].data[1], gTasks[taskId].data[14]);
    gTasks[taskId].func = Task_HandleMainMenuInput;
}

bool8 HandleMainMenuInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        sub_80093CC();
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0x0000);
        gTasks[taskId].func = Task_HandleMainMenuAPressed;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0xFFFF);
        SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
        SetGpuReg(REG_OFFSET_WIN0V, 0xA0);
        gTasks[taskId].func = Task_HandleMainMenuBPressed;
    }
    else if ((gMain.newKeys & DPAD_UP) && data[1] > 0)
    {
        if (data[0] == 3 && data[14] == 1 && data[1] == 1)
        {
            ChangeBgY(0, 0x2000, 2);
            ChangeBgY(1, 0x2000, 2);
            gTasks[data[13]].data[15] = data[14] = 0;
        }
        data[1]--;
        gUnknown_02022D06 = data[1];
        return TRUE;
    }
    else if ((gMain.newKeys & DPAD_DOWN) && data[1] < data[12] - 1)
    {
        if (data[0] == 3 && data[1] == 3 && data[14] == 0)
        {
            ChangeBgY(0, 0x2000, 1);
            ChangeBgY(1, 0x2000, 1);
            gTasks[data[13]].data[15] = data[14] = 1;
        }
        data[1]++;
        gUnknown_02022D06 = data[1];
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
    bool8 r2;
    u8 action;
    
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].data[0] == 3)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].data[13]);
        sub_819746C(0, 1);
        sub_819746C(1, 1);
        sub_819746C(2, 1);
        sub_819746C(3, 1);
        sub_819746C(4, 1);
        sub_819746C(5, 1);
        sub_819746C(6, 1);
        sub_819746C(7, 1);
        r2 = sub_80093CC();
        switch (gTasks[taskId].data[0])
        {
            case HAS_NO_SAVED_GAME:
            default:
                switch (gTasks[taskId].data[1])
                {
                    case 0:
                    default:
                        action = 0;
                        break;
                    case 1:
                        action = 2;
                        break;
                }
                break;
            case HAS_SAVED_GAME:
                switch (gTasks[taskId].data[1])
                {
                    case 0:
                    default:
                        action = 1;
                        break;
                    case 1:
                        action = 0;
                        break;
                    case 2:
                        action = 2;
                        break;
                }
                break;
            case HAS_MYSTERY_GIFT:
                switch (gTasks[taskId].data[1])
                {
                    case 0:
                    default:
                        action = 1;
                        break;
                    case 1:
                        action = 0;
                        break;
                    case 2:
                        action = 3;
                        if (r2 == FALSE)
                        {
                            action = 6;
                            gTasks[taskId].data[0] = 0;
                        }
                        break;
                    case 3:
                        action = 2;
                        break;
                }
                break;
            case HAS_MYSTERY_EVENTS:
                switch (gTasks[taskId].data[1])
                {
                    case 0:
                    default:
                        action = 1;
                        break;
                    case 1:
                        action = 0;
                        break;
                    case 2:
                        if (gTasks[taskId].data[15])
                        {
                            action = 3;
                            if (r2 == FALSE)
                            {
                                action = 6;
                                gTasks[taskId].data[0] = 0;
                            }
                        }
                        else if (r2)
                        {
                            action = 6;
                            gTasks[taskId].data[0] = 1;
                        }
                        else
                        {
                            action = 5;
                        }
                        break;
                    case 3:
                        if (r2)
                        {
                            action = 6;
                            gTasks[taskId].data[0] = 2;
                        }
                        else
                        {
                            action = 4;
                        }
                        break;
                    case 4:
                        action = 2;
                        break;
                }
                break;
        }
        ChangeBgY(0, 0, 0);
        ChangeBgY(1, 0, 0);
        switch (action)
        {
            case 0:
            default:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                gTasks[taskId].func = task_new_game_prof_birch_speech_1;
                break;
            case 1:
                gPlttBufferUnfaded[0] = RGB_BLACK;
                gPlttBufferFaded[0] = RGB_BLACK;
                SetMainCallback2(sub_8086230);
                DestroyTask(taskId);
                break;
            case 2:
                gMain.savedCallback = CB2_ReinitMainMenu;
                SetMainCallback2(CB2_InitOptionMenu);
                DestroyTask(taskId);
                break;
            case 3:
                SetMainCallback2(c2_mystery_gift);
                DestroyTask(taskId);
                break;
            case 4:
                SetMainCallback2(CB2_InitMysteryEventMenu);
                DestroyTask(taskId);
                break;
            case 5:
                SetMainCallback2(sub_801867C);
                DestroyTask(taskId);
                break;
            case 6:
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].func = Task_DisplayMainMenuInvalidActionError;
                gPlttBufferUnfaded[0xF1] = RGB_WHITE;
                gPlttBufferFaded[0xF1] = RGB_WHITE;
                SetGpuReg(REG_OFFSET_BG2HOFS, 0);
                SetGpuReg(REG_OFFSET_BG2VOFS, 0);
                SetGpuReg(REG_OFFSET_BG1HOFS, 0);
                SetGpuReg(REG_OFFSET_BG1VOFS, 0);
                SetGpuReg(REG_OFFSET_BG0HOFS, 0);
                SetGpuReg(REG_OFFSET_BG0VOFS, 0);
                BeginNormalPaletteFade(-1, 0, 16, 0, 0);
                return;
        }
        FreeAllWindowBuffers();
        if (action != 2)
            gUnknown_02022D06 = 0;
        else
            gUnknown_02022D06 |= 0x8000;
    }
}

void Task_HandleMainMenuBPressed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].data[0] == 3)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].data[13]);
        gUnknown_02022D06 = 0;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitTitleScreen);
        DestroyTask(taskId);
    }
}

void Task_DisplayMainMenuInvalidActionError(u8 taskId)
{
    switch (gTasks[taskId].data[1])
    {
        case 0:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
            switch (gTasks[taskId].data[0])
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
            gTasks[taskId].data[1]++;
            break;
        case 1:
            if (!gPaletteFade.active)
                gTasks[taskId].data[1]++;
            break;
        case 2:
            RunTextPrinters();
            if (!IsTextPrinterActive(7))
                gTasks[taskId].data[1]++;
            break;
        case 3:
            if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(-1, 0, 0, 16, 0);
                gTasks[taskId].func = Task_HandleMainMenuBPressed;
            }
    }
}

void HighlightSelectedMainMenuItem(u8 menuType, u8 selectedMenuItem, s16 a)
{
    SetGpuReg(REG_OFFSET_WIN0H, 0x9E7);
    
    switch (menuType)
    {
        case HAS_NO_SAVED_GAME:
        default:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x11F);
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x213F);
                    break;
            }
            break;
        case HAS_SAVED_GAME:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x13F);
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    break;
            }
            break;
        case HAS_MYSTERY_GIFT:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x13F);
                    break;
                case 1:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    break;
                case 2:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    break;
                case 3:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x819F);
                    break;
            }
            break;
        case HAS_MYSTERY_EVENTS:
            switch (selectedMenuItem)
            {
                case 0:
                default:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x13F);
                    break;
                case 1:
                    if (a)
                        SetGpuReg(REG_OFFSET_WIN0V, 0x213F);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    break;
                case 2:
                    if (a)
                        SetGpuReg(REG_OFFSET_WIN0V, 0x415F);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    break;
                case 3:
                    if (a)
                        SetGpuReg(REG_OFFSET_WIN0V, 0x617F);
                    else
                        SetGpuReg(REG_OFFSET_WIN0V, 0x819F);
                    break;
                case 4:
                    SetGpuReg(REG_OFFSET_WIN0V, 0x819F);
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
    dp13_810BB8C();
    AddBirchSpeechObjects(taskId);
    BeginNormalPaletteFade(-1, 0, 16, 0, 0);
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
        gSprites[spriteId].invisible = 0;
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
            copy_textbox_border_tile_patterns_to_vram(0, 0xFC,  0xF0);
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
    gSprites[spriteId].invisible = 0;
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
        gSprites[gTasks[taskId].data[8]].invisible = 1;
        gSprites[gTasks[taskId].data[9]].invisible = 1;
        if (gTasks[taskId].data[7])
        {
            gTasks[taskId].data[7]--;
        }
        else
        {
            u8 spriteId = gTasks[taskId].data[10];
            
            gSprites[spriteId].pos1.x = 0xB4;
            gSprites[spriteId].pos1.y = 0x3C;
            gSprites[spriteId].invisible = 0;
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
        gSprites[spriteId].invisible = 1;
        if (gTasks[taskId].data[6])
            spriteId = gTasks[taskId].data[11];
        else
            spriteId = gTasks[taskId].data[10];
        gSprites[spriteId].pos1.x = 0xF0;
        gSprites[spriteId].pos1.y = 0x3C;
        gSprites[spriteId].invisible = 0;
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
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gTasks[taskId].func = task_new_game_prof_birch_speech_17;
    }
}

void task_new_game_prof_birch_speech_17(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        sub_818D820(gTasks[taskId].data[9]);
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
    switch (ProcessMenuInputNoWrap_())
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
        gSprites[gTasks[taskId].data[10]].invisible = 1;
        gSprites[gTasks[taskId].data[11]].invisible = 1;
        spriteId = gTasks[taskId].data[8];
        gSprites[spriteId].pos1.x = 0x88;
        gSprites[spriteId].pos1.y = 0x3C;
        gSprites[spriteId].invisible = 0;
        gSprites[spriteId].oam.objMode = 1;
        spriteId = gTasks[taskId].data[9];
        gSprites[spriteId].pos1.x = 0x64;
        gSprites[spriteId].pos1.y = 0x4B;
        gSprites[spriteId].invisible = 0;
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
        gSprites[gTasks[taskId].data[8]].invisible = 1;
        gSprites[gTasks[taskId].data[9]].invisible = 1;
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
        gSprites[spriteId].invisible = 0;
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
            BeginNormalPaletteFade(0xFFFF, 0, 0, 16, 0);
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
        BeginNormalPaletteFade(-0x10000, 0, 0, 16, -1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_12;
    }
}

void task_new_game_prof_birch_speech_part2_12(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        sub_818D820(gTasks[taskId].data[9]);
        dp13_810BB8C();
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
    dp13_810BB8C();
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
    gSprites[spriteId].invisible = 0;
    gTasks[taskId].data[2] = spriteId;
    SetGpuReg(REG_OFFSET_BG1HOFS, -60);
    BeginNormalPaletteFade(-1, 0, 16, 0, 0);
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
    copy_textbox_border_tile_patterns_to_vram(0, 0xFC, 0xF0);
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
    return sub_818D3E4(SPECIES_LOTAD, 8, 0, 1, a, b, 14, -1);
}

void AddBirchSpeechObjects(u8 taskId)
{
    u8 spriteId = AddNewGameBirchObject(0x88, 0x3C, 1);
    u8 spriteId2;
    u8 spriteId3;
    u8 spriteId4;
    
    gSprites[spriteId].callback = nullsub_11;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].invisible = 1;
    gTasks[taskId].data[8] = spriteId;
    spriteId2 = sub_80318F4(100, 0x4B);
    gSprites[spriteId2].callback = nullsub_11;
    gSprites[spriteId2].oam.priority = 0;
    gSprites[spriteId2].invisible = 1;
    gTasks[taskId].data[9] = spriteId2;
    spriteId3 = CreateTrainerSprite(FacilityClassToPicIndex(0x3C), 0x78, 0x3C, 0, gDecompressionBuffer);
    gSprites[spriteId3].callback = nullsub_11;
    gSprites[spriteId3].invisible = 1;
    gSprites[spriteId3].oam.priority = 0;
    gTasks[taskId].data[10] = spriteId3;
    spriteId4 = CreateTrainerSprite(FacilityClassToPicIndex(0x3F), 0x78, 0x3C, 0, &gDecompressionBuffer[0x800]);
    gSprites[spriteId4].callback = nullsub_11;
    gSprites[spriteId4].invisible = 1;
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
    return ProcessMenuInputNoWrapAround();
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
    PrintTextOnWindow(7, 1, str, 0, 1, 2, 0);
    PutWindowTilemap(7);
    CopyWindowToVram(7, 2);
    DrawMainMenuWindowBorder(gUnknown_082FF070, 0x1D5);
    SetGpuReg(REG_OFFSET_WIN0H, 0x9E7);
    SetGpuReg(REG_OFFSET_WIN0V, 0x719F);
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
    box_print(2, 1, 0, 17, gUnknown_082FF0E3, -1, gStringVar4);
    box_print(2, 1, GetStringRightAlignXOffset(1, gSaveBlock2Ptr->playerName, 100), 17, gUnknown_082FF0E3, -1, gSaveBlock2Ptr->playerName);
}

void fmt_player(void)
{
    u8 str[0x20];
    u8* ptr;
    
    StringExpandPlaceholders(gStringVar4, gText_ContinueMenuTime);
    box_print(2, 1, 0x6C, 17, gUnknown_082FF0E3, -1, gStringVar4);
    ptr = ConvertIntToDecimalStringN(str, gSaveBlock2Ptr->playTimeHours, 0, 3);
    *ptr = 0xF0;
    ConvertIntToDecimalStringN(ptr + 1, gSaveBlock2Ptr->playTimeMinutes, 2, 2);
    box_print(2, 1, GetStringRightAlignXOffset(1, str, 0xD0), 17, gUnknown_082FF0E3, -1, str);
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
        box_print(2, 1, 0, 33, gUnknown_082FF0E3, -1, gStringVar4);
        ConvertIntToDecimalStringN(str, dexCount, 0, 3);
        box_print(2, 1, GetStringRightAlignXOffset(1, str, 100), 33, gUnknown_082FF0E3, -1, str);
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
    box_print(2, 1, 0x6C, 33, gUnknown_082FF0E3, -1, gStringVar4);
    ConvertIntToDecimalStringN(str, badgeCount, 2, 1);
    box_print(2, 1, GetStringRightAlignXOffset(1, str, 0xD0), 33, gUnknown_082FF0E3, -1, str);
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

void sub_8032250(const struct WindowTemplate *template)
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
    FillWindowPixelBuffer(windowId, 17);
    ClearWindowTilemap(windowId);
    if (a == 1)
        CopyWindowToVram(windowId, 3);
}

void sub_8032318(u8 a)
{
    u8 fontAttribute = GetFontAttribute(1, 6);
    u8 fontAttribute2 = GetFontAttribute(1, 0);
    u8 fontAttribute3 = GetFontAttribute(1, 1);
    u8 windowAttribute = GetWindowAttribute(a, 3);
    u8 windowAttribute2 = GetWindowAttribute(a, 4);
    
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
    struct WindowTemplate sp2;
    
    sp = sub_8198A50(0, a + 1, b + 1, 5, 4, f, d);
    sp2 = sp;
    CreateYesNoMenu(&sp2, c, e, 0);
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
    FillBgTilemapBufferRect(a, 0x8FD, b-2,   c+e, 1,   1, f);
    FillBgTilemapBufferRect(a, 0x8FF, b-1,   c+e, 1,   1, f);
    FillBgTilemapBufferRect(a, 0x900, b,     c+e, d-1, 1, f);
    FillBgTilemapBufferRect(a, 0x901, b+d-1, c+e, 1,   1, f);
    FillBgTilemapBufferRect(a, 0x902, b+d,   c+e, 1,   1, f);
}

void task_new_game_prof_birch_speech_part2_1(u8 taskId)
{
    if (gTasks[taskId].data[7]-- <= 0)
    {
        unknown_rbox_to_vram(0, 1);
        gTasks[taskId].func = task_new_game_prof_birch_speech_part2_2;
    }
}
