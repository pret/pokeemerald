#include "global.h"
#include "hall_of_fame.h"
#include "main.h"
#include "palette.h"
#include "overworld.h"
#include "script.h"
#include "script_menu.h"
#include "task.h"
#include "constants/rgb.h"

static void ReshowPCMenuAfterHallOfFamePC(void);
static void Task_WaitForPaletteFade(u8);

void AccessHallOfFamePC(void)
{
    SetMainCallback2(CB2_DoHallOfFamePC);
    ScriptContext2_Enable();
}

void ReturnFromHallOfFamePC(void)
{
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = ReshowPCMenuAfterHallOfFamePC;
}

static void ReshowPCMenuAfterHallOfFamePC(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    ScriptMenu_CreatePCMultichoice();
    ScriptMenu_DisplayPCStartupPrompt();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    CreateTask(Task_WaitForPaletteFade, 10);
}

static void Task_WaitForPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
        DestroyTask(taskId);
}
