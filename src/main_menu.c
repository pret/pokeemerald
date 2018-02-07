
// Includes
#include "global.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "menu_indicators.h"
#include "new_menu_helpers.h"
#include "palette.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

// Static type declarations

// Static RAM declarations


IWRAM_DATA u8 gUnknown_03000DD0;

// Static ROM declarations

// .rodata

// .text

enum
{
    HAS_NO_SAVED_GAME,  //NEW GAME, OPTION
    HAS_SAVED_GAME,     //CONTINUE, NEW GAME, OPTION
    HAS_MYSTERY_GIFT,   //CONTINUE, NEW GAME, MYSTERY EVENTS, OPTION
    HAS_MYSTERY_EVENTS,
};

struct ArrowStruct {
    u8 unk0[6];
    u16 unk6[5];
};

extern u16 gMainMenuBgPal[];
extern u16 gMainMenuTextPal[];
extern struct BgTemplate gUnknown_082FF0E8[];
extern struct WindowTemplate gUnknown_082FF038[];
extern u8 gText_SaveFileErased[];
extern u8 gText_SaveFileCorrupted[];
extern u8 gJPText_No1MSubCircuit[];
extern u16 gUnknown_02022D06;
extern struct WindowTemplate gUnknown_082FF070[];
extern u8 gText_BatteryRunDry[];
extern struct TextColor gUnknown_082FF0E0;
extern u8 gText_MainMenuNewGame[];
extern struct WindowTemplate gUnknown_082FF048[];
extern struct ArrowStruct gUnknown_082FF0F4;
extern u8 gText_MainMenuOption[];
extern u8 gText_MainMenuContinue[];
extern u8 gText_MainMenuMysteryGift2[];
extern u8 gText_MainMenuMysteryEvents[];
extern u8 gText_MainMenuMysteryGift[];
extern u8 gText_WirelessNotConnected[];
extern u8 gText_MysteryGiftCantUse[];
extern u8 gText_MysteryEventsCantUse[];
extern struct BgTemplate gUnknown_082FF0F0;
extern u8 gBirchIntroShadowGfx[];
extern u8 gUnknown_082FEEF0[];
extern u16 gUnknown_082FECFC[];
extern u16 gUnknown_082FF028[];
extern struct WindowTemplate gUnknown_082FF080[];
extern u8 gUnknown_082C897B[];

u32 InitMainMenu(bool8);
void Task_MainMenuCheckSaveFile(u8);
void Task_MainMenuCheckBattery(u8);
void Task_WaitForSaveFileErrorWindow(u8);
void CreateMainMenuErrorWindow(u8*);
void sub_8032250(struct WindowTemplate*);
void Task_DisplayMainMenu(u8);
void Task_WaitForBatteryDryErrorWindow(u8);
void fmt_savegame(void);
u8 AddScrollIndicatorArrowPair(struct ArrowStruct*, u16*);
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

extern void LoadMainMenuWindowFrameTiles(u8, u16);
extern bool8 sub_80093CC(void);
extern void Task_ScrollIndicatorArrowPairOnMainMenu(u8);
extern void Task_HighlightSelectedMainMenuItem(u8);
extern void DrawMainMenuWindowBorder(struct WindowTemplate*, u16);
extern void sub_819746C(u8, u8);
extern void sub_8086230(void);
extern void CB2_InitOptionMenu(void);
extern void c2_mystery_gift(void);
extern void CB2_InitMysteryEventMenu(void);
extern void sub_801867C(void);
extern void c2_title_screen_1(void);
extern void dp13_810BB8C(void);

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
    SetGpuReg(REG_OFFSET_DISPCNT, 0x3040);
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
        SetGpuReg(REG_OFFSET_BLDCNT, 0xC1);
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
        SetGpuReg(REG_OFFSET_BLDCNT, 0xC1);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 7);
        
        if (!(RtcGetErrorStatus() & RTC_ERR_FLAG_MASK))
            gTasks[taskId].func = Task_DisplayMainMenu;
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
        SetGpuReg(REG_OFFSET_BLDCNT, 0xC1);
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
                box_print(0, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(1, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuOption);
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
                box_print(2, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuContinue);
                box_print(3, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(4, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuOption);
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
                box_print(2, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuContinue);
                box_print(3, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(4, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuMysteryGift);
                box_print(5, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuOption);
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
                box_print(2, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuContinue);
                box_print(3, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuNewGame);
                box_print(4, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuMysteryGift2);
                box_print(5, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuMysteryEvents);
                box_print(6, 1, 0, 1, &gUnknown_082FF0E0, -1, gText_MainMenuOption);
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
                            action = 5;
                        break;
                    case 3:
                        if (r2)
                        {
                            action = 6;
                            gTasks[taskId].data[0] = 2;
                        }
                        else
                            action = 4;
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
        SetMainCallback2(c2_title_screen_1);
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
    SetGpuReg(REG_OFFSET_DISPCNT, 0x1040);
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
        gTasks[taskId].data[7]--;
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
            gTasks[taskId].data[7]--;
        else
        {
            InitWindows(gUnknown_082FF080);
            LoadMainMenuWindowFrameTiles(0, 0xF3);
            copy_textbox_border_tile_patterns_to_vram(0, 0xFC,  0xF0);
            unknown_rbox_to_vram(0, 1);
            PutWindowTilemap(0);
            CopyWindowToVram(0, 2);
            sub_8032318(0);
            StringExpandPlaceholders(gStringVar4, gUnknown_082C897B);
            AddTextPrinterForMessage(1);
            gTasks[taskId].func = task_new_game_prof_birch_speech_4;
        }
    }
}
