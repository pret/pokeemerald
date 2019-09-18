#include "global.h"
#include "main.h"
#include "event_data.h"
#include "field_effect.h"
#include "field_specials.h"
#include "item.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/script_menu.h"
#include "constants/songs.h"

#include "data/script_menu.h"

EWRAM_DATA u8 gUnknown_02039F90 = 0;

static u8 gUnknown_03001124[ARRAY_COUNT(gSSTidalDestinations)];
static u32 filler_0300112c;

static void Task_HandleMultichoiceInput(u8);
static void Task_HandleYesNoInput(u8);
static void Task_HandleMultichoiceGridInput(u8);
static void DrawMultichoiceMenu(u8, u8, u8, bool8, u8);
static void sub_80E1FBC(u8, u8, u8, u8);
static void sub_80E2A94(u8);
static void CreatePCMenu(void);
static void sub_80E2578(void);
static bool8 IsPicboxClosed(void);
static void CreateStartMenu(void);
static void sub_80E2CC4(u8, u8, u8, u8);

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, 0);
        return TRUE;
    }
}

bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, defaultChoice);
        return TRUE;
    }
}

// Unused
static u16 sub_80E1EB8(const u8 *str)
{
    u16 length = 0;

    while (*str != EOS)
    {
        if (*str == PLACEHOLDER_BEGIN)
        {
            str++;
            if (*str == 1)
            {
                length += StringLength(gSaveBlock2Ptr->playerName);
                str++;
            }
        }
        else
        {
            str++;
            length++;
        }
    }

    return length;
}

static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 cursorPos)
{
    int i;
    u8 windowId;
    u8 count = gMultichoiceLists[multichoiceId].count;
    const struct MenuAction *actions = gMultichoiceLists[multichoiceId].list;
    int width = 0;
    u8 newWidth;

    for (i = 0; i < count; i++)
    {
        width = display_text_and_get_width(actions[i].text, width);
    }

    newWidth = convert_pixel_width_to_tile_width(width);
    left = sub_80E2D5C(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    PrintMenuTable(windowId, count, actions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, cursorPos);
    schedule_bg_copy_tilemap_to_vram(0);
    sub_80E1FBC(ignoreBPress, count, windowId, multichoiceId);
}

#define tLeft           data[0]
#define tTop            data[1]
#define tRight          data[2]
#define tBottom         data[3]
#define tIgnoreBPress   data[4]
#define tDoWrap         data[5]
#define tWindowId       data[6]
#define tMultichoiceId  data[7]

static void sub_80E1FBC(u8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId)
{
    u8 i;
    u8 taskId;
    gUnknown_02039F90 = 2;

    for (i = 0; i < ARRAY_COUNT(gUnknown_0858BB68); i++)
    {
        if (gUnknown_0858BB68[i] == multichoiceId)
        {
            gUnknown_02039F90 = 12;
        }
    }

    taskId = CreateTask(Task_HandleMultichoiceInput, 80);

    gTasks[taskId].tIgnoreBPress = ignoreBPress;

    if (count > 3)
        gTasks[taskId].tDoWrap = TRUE;
    else
        gTasks[taskId].tDoWrap = FALSE;

    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;

    sub_80E2A94(multichoiceId);
}

static void Task_HandleMultichoiceInput(u8 taskId)
{
    s8 selection;
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if (gUnknown_02039F90)
        {
            gUnknown_02039F90--;
        }
        else
        {
            if (!tDoWrap)
                selection = Menu_ProcessInputNoWrap();
            else
                selection = Menu_ProcessInput();

            if (gMain.newKeys & (DPAD_UP | DPAD_DOWN))
            {
                sub_80E2A94(tMultichoiceId);
            }

            if (selection != MENU_NOTHING_CHOSEN)
            {
                if (selection == MENU_B_PRESSED)
                {
                    if (tIgnoreBPress)
                        return;
                    PlaySE(SE_SELECT);
                    gSpecialVar_Result = MULTICHOICE_B;
                }
                else
                {
                    gSpecialVar_Result = selection;
                }
                ClearToTransparentAndRemoveWindow(tWindowId);
                DestroyTask(taskId);
                EnableBothScriptContexts();
            }
        }
    }
}

bool8 ScriptMenu_YesNo(u8 left, u8 top)
{
    u8 taskId;

    if (FuncIsActiveTask(Task_HandleYesNoInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DisplayYesNoMenuDefaultYes();
        taskId = CreateTask(Task_HandleYesNoInput, 0x50);
        return TRUE;
    }
}

// Unused
bool8 IsScriptActive(void)
{
    if (gSpecialVar_Result == 0xFF)
        return FALSE;
    else
        return TRUE;
}

static void Task_HandleYesNoInput(u8 taskId)
{
    if (gTasks[taskId].tRight < 5)
    {
        gTasks[taskId].tRight++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0;
        break;
    case 0:
        gSpecialVar_Result = 1;
        break;
    }

    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 columnCount)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceGridInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 rowCount, newWidth;
        int i, width;

        gSpecialVar_Result = 0xFF;
        width = 0;

        for (i = 0; i < gMultichoiceLists[multichoiceId].count; i++)
        {
            width = display_text_and_get_width(gMultichoiceLists[multichoiceId].list[i].text, width);
        }

        newWidth = convert_pixel_width_to_tile_width(width);

        left = sub_80E2D5C(left, columnCount * newWidth);
        rowCount = gMultichoiceLists[multichoiceId].count / columnCount;

        taskId = CreateTask(Task_HandleMultichoiceGridInput, 80);

        gTasks[taskId].tIgnoreBPress = ignoreBPress;
        gTasks[taskId].tWindowId = CreateWindowFromRect(left, top, columnCount * newWidth, rowCount * 2);
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 0);
        PrintMenuGridTable(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, gMultichoiceLists[multichoiceId].list);
        sub_8199944(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, 0);
        CopyWindowToVram(gTasks[taskId].tWindowId, 3);
        return TRUE;
    }
}

static void Task_HandleMultichoiceGridInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 selection = Menu_ProcessInputGridLayout();

    switch (selection)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tIgnoreBPress)
            return;
        PlaySE(SE_SELECT);
        gSpecialVar_Result = MULTICHOICE_B;
        break;
    default:
        gSpecialVar_Result = selection;
        break;
    }

    ClearToTransparentAndRemoveWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

#undef tWindowId

bool16 ScrSpecial_CreatePCMenu(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreatePCMenu();
        return TRUE;
    }
}

static void CreatePCMenu(void)
{
    u8 y = 8;
    u32 pixelWidth = 0;
    u8 width;
    u8 numChoices;
    u8 windowId;
    int i;

    for (i = 0; i < ARRAY_COUNT(sPCNameStrings); i++)
    {
        pixelWidth = display_text_and_get_width(sPCNameStrings[i], pixelWidth);
    }

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        pixelWidth = display_text_and_get_width(gText_HallOfFame, pixelWidth);
    }

    width = convert_pixel_width_to_tile_width(pixelWidth);

    if (FlagGet(FLAG_SYS_GAME_CLEAR)) // player has cleared game?
    {
        numChoices = 4;
        windowId = CreateWindowFromRect(0, 0, width, 8);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_HallOfFame, y, 33, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 49, TEXT_SPEED_FF, NULL);
    }
    else
    {
        numChoices = 3;
        windowId = CreateWindowFromRect(0, 0, width, 6);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 33, TEXT_SPEED_FF, NULL);
    }

    if (FlagGet(FLAG_SYS_PC_LANETTE)) // player met lanette?
        AddTextPrinterParameterized(windowId, 1, gText_LanettesPC, y, 1, TEXT_SPEED_FF, NULL);
    else
        AddTextPrinterParameterized(windowId, 1, gText_SomeonesPC, y, 1, TEXT_SPEED_FF, NULL);

    StringExpandPlaceholders(gStringVar4, gText_PlayersPC);
    PrintPlayerNameOnWindow(windowId, gStringVar4, y, 17);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, numChoices, 0);
    CopyWindowToVram(windowId, 3);
    sub_80E1FBC(FALSE, numChoices, windowId, 1);
}

void ScriptMenu_DisplayPCStartupPrompt(void)
{
    sub_819786C(0, TRUE);
    AddTextPrinterParameterized2(0, 1, gText_WhichPCShouldBeAccessed, 0, NULL, 2, 1, 3);
}

bool8 sub_80E2548(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        sub_80E2578();
        return TRUE;
    }
}

static void sub_80E2578(void)
{
    u8 temp = 0;
    u8 count;
    u32 pixelWidth;
    u8 width;
    u8 windowId;
    u8 i;
    u32 j;

    for (i = 0; i < ARRAY_COUNT(gUnknown_03001124); i++)
    {
        gUnknown_03001124[i] = 0xFF;
    }

    GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);

    if (gSpecialVar_0x8004 == 0)
    {
        gUnknown_03001124[temp] = 0;
        temp++;
        if (FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
        {
            gUnknown_03001124[temp] = 1;
            temp++;
        }
    }

    if (CheckBagHasItem(ITEM_EON_TICKET, 1) == TRUE && FlagGet(FLAG_SYS_HAS_EON_TICKET) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 2;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_EON_TICKET) == FALSE)
        {
            gUnknown_03001124[temp] = 2;
            temp++;
            FlagSet(FLAG_HAS_EON_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_NAVEL_ROCK) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 3;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_MYSTIC_TICKET) == FALSE)
        {
            gUnknown_03001124[temp] = 3;
            temp++;
            FlagSet(FLAG_HAS_MYSTIC_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_AURORA_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_BIRTH_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 4;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_AURORA_TICKET) == FALSE)
        {
            gUnknown_03001124[temp] = 4;
            temp++;
            FlagSet(FLAG_HAS_AURORA_TICKET);
        }
    }

    if (CheckBagHasItem(ITEM_OLD_SEA_MAP, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_FARAWAY_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[temp] = 5;
            temp++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_HAS_OLD_SEA_MAP) == FALSE)
        {
            gUnknown_03001124[temp] = 5;
            temp++;
            FlagSet(FLAG_HAS_OLD_SEA_MAP);
        }
    }

    gUnknown_03001124[temp] = 6;
    temp++;

    if (gSpecialVar_0x8004 == 0 && FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
    {
        count = temp;
    }

    count = temp;
    if (count == 7)
    {
        gSpecialVar_0x8004 = SCROLL_MULTI_SS_TIDAL_DESTINATION;
        ShowScrollableMultichoice();
    }
    else
    {
        pixelWidth = 0;

        for (j = 0; j < ARRAY_COUNT(gSSTidalDestinations); j++)
        {
            u8 test = gUnknown_03001124[j];
            if (test != 0xFF)
            {
                pixelWidth = display_text_and_get_width(gSSTidalDestinations[test], pixelWidth);
            }
        }

        width = convert_pixel_width_to_tile_width(pixelWidth);
        windowId = CreateWindowFromRect(28 - width, (6 - count) * 2, width, count * 2);
        SetStandardWindowBorderStyle(windowId, 0);

        for (temp = 0, i = 0; i < ARRAY_COUNT(gSSTidalDestinations); i++)
        {
            if (gUnknown_03001124[i] != 0xFF)
            {
                AddTextPrinterParameterized(windowId, 1, gSSTidalDestinations[gUnknown_03001124[i]], 8, temp * 16 + 1, TEXT_SPEED_FF, NULL);
                temp++;
            }
        }

        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, count - 1);
        CopyWindowToVram(windowId, 3);
        sub_80E1FBC(FALSE, count, windowId, 8);
    }
}

void sub_80E2878(void)
{
    if (gSpecialVar_Result != MULTICHOICE_B)
    {
        gSpecialVar_Result = gUnknown_03001124[gSpecialVar_Result];
    }
}

#define tState       data[0]
#define tMonSpecies  data[1]
#define tMonSpriteId data[2]
#define tWindowX     data[3]
#define tWindowY     data[4]
#define tWindowId    data[5]

static void Task_PokemonPicWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
        task->tState++;
        break;
    case 3:
        ClearToTransparentAndRemoveWindow(task->tWindowId);
        DestroyTask(taskId);
        break;
    }
}

bool8 ScriptMenu_ShowPokemonPic(u16 species, u8 x, u8 y)
{
    u8 taskId;
    u8 spriteId;

    if (FindTaskIdByFunc(Task_PokemonPicWindow) != 0xFF)
    {
        return FALSE;
    }
    else
    {
        spriteId = CreateMonSprite_PicBox(species, x * 8 + 40, y * 8 + 40, 0);
        taskId = CreateTask(Task_PokemonPicWindow, 0x50);
        gTasks[taskId].tWindowId = CreateWindowFromRect(x, y, 8, 8);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tMonSpecies = species;
        gTasks[taskId].tMonSpriteId = spriteId;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 1);
        schedule_bg_copy_tilemap_to_vram(0);
        return TRUE;
    }
}

bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PokemonPicWindow);

    if (taskId == 0xFF)
        return NULL;
    gTasks[taskId].tState++;
    return IsPicboxClosed;
}

static bool8 IsPicboxClosed(void)
{
    if (FindTaskIdByFunc(Task_PokemonPicWindow) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

#undef tState
#undef tMonSpecies
#undef tMonSpriteId
#undef tWindowX
#undef tWindowY
#undef tWindowId

u8 CreateWindowFromRect(u8 x, u8 y, u8 width, u8 height)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, width, height, 15, 100);
    u8 windowId = AddWindow(&template);
    PutWindowTilemap(windowId);
    return windowId;
}

void ClearToTransparentAndRemoveWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void sub_80E2A94(u8 multichoiceId)
{
    switch (multichoiceId)
    {
    case 77:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBAC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 76:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BB9C[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 78:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBBC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 79:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBCC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 75:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBEC[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case 74:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_0858BBE0[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    }
}

bool16 sp106_CreateStartMenu(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }

    gSpecialVar_Result = 0xFF;
    CreateStartMenu();
    return TRUE;
}

static void CreateStartMenu(void)
{
    u8 windowId = CreateWindowFromRect(21, 0, 7, 18);
    SetStandardWindowBorderStyle(windowId, 0);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokedex, 8, 9, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokemon, 8, 25, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionBag, 8, 41, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokenav, 8, 57, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gSaveBlock2Ptr->playerName, 8, 73, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionSave, 8, 89, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionOption, 8, 105, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionExit, 8, 121, TEXT_SPEED_FF, NULL);
    sub_81983AC(windowId, 1, 0, 9, 16, 8, 0);
    sub_80E2CC4(0, 8, windowId, 86);
    CopyWindowToVram(windowId, 3);
}

#define tWindowId       data[6]

static void sub_80E2CC4(bool8 ignoreBPress, u8 unused, u8 windowId, u8 multichoiceId)
{
    u8 taskId;
    gUnknown_02039F90 = 2;
    taskId = CreateTask(Task_HandleMultichoiceInput, 80);
    gTasks[taskId].tIgnoreBPress = ignoreBPress;
    gTasks[taskId].tDoWrap = 0;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;
}

#undef tLeft
#undef tTop
#undef tRight
#undef tBottom
#undef tIgnoreBPress
#undef tDoWrap
#undef tWindowId
#undef tMultichoiceId

static int display_text_and_get_width_internal(const u8 *str)
{
    u8 temp[64];
    StringExpandPlaceholders(temp, str);
    return GetStringWidth(1, temp, 0);
}

int display_text_and_get_width(const u8 *str, int prevMaxWidth)
{
    int len = display_text_and_get_width_internal(str);
    if (len < prevMaxWidth)
    {
        len = prevMaxWidth;
    }
    return len;
}

int convert_pixel_width_to_tile_width(int width)
{
    return (((width + 9) / 8) + 1) > 28 ? 28 : (((width + 9) / 8) + 1);
}

int sub_80E2D5C(int a0, int a1)
{
    int ret = a0;

    if (a0 + a1 > 28)
    {
        if (28 - a1 < 0)
        {
            ret = 0;
        }
        else
        {
            ret = 28 - a1;
        }
    }
    else
    {
        ret = a0;
    }

    return ret;
}
