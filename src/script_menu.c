#include "global.h"
#include "main.h"
#include "event_data.h"
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
#include "constants/items.h"
#include "constants/songs.h"

struct MultichoiceListStruct
{
    const struct MenuAction *list;
    u8 count;
};

extern const struct MultichoiceListStruct gMultichoiceLists[];
extern const u8 gUnknown_0858BB68[];
extern const u8 *sPCNameStrings[4];
extern const u8 *gUnknown_0858BB80[7];

extern EWRAM_DATA u8 gUnknown_02039F90;

IWRAM_DATA u8 gUnknown_03001124[7];
IWRAM_DATA u32 filler_0300112c;

/*static*/ void Task_HandleMultichoiceInput(u8);
/*static*/ void Task_HandleYesNoInput(u8);
/*static*/ void Task_HandleMultichoiceGridInput(u8);
/*static*/ void DrawMultichoiceMenu(u8, u8, u8, bool8, u8);
/*static*/ void sub_80E1FBC(u8, u8, u8, u8);
/*static*/ void sub_80E2A94(u8);
/*static*/ void CreatePCMenu(void);
/*static*/ void sub_80E2578(void);

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

/*static*/ u16 sub_80E1EB8(const u8 *str)
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

/*static*/ void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 cursorPos)
{
    int i;
    u8 right;
    u8 bottom;
    u8 windowId;
    u8 count = gMultichoiceLists[multichoiceId].count;
    const struct MenuAction *actions = gMultichoiceLists[multichoiceId].list;
    const struct MenuAction *action;
    int width = 0;
    u8 newWidth;
    
    // Must be a fakematch because come on, seriously
    if (width < count)
    {
        action = &actions[0];
        i = count;
        do
        {
            width = display_text_and_get_width(action->text, width);
            action++;
            i--;
        } while (i != 0);
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

/*static*/ void sub_80E1FBC(u8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId)
{
    u8 i;
    u8 taskId;
    gUnknown_02039F90 = 2;

    for (i = 0; i < 6; i++)
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

/*static*/ void Task_HandleMultichoiceInput(u8 taskId)
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

            if (selection != -2)
            {
                if (selection == -1)
                {
                    if (tIgnoreBPress)
                        return;
                    PlaySE(SE_SELECT);
                    gSpecialVar_Result = 127;
                }
                else
                {
                    gSpecialVar_Result = selection;
                }
                sub_80E2A78(tWindowId);
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
        DisplayYesNoMenu();
        taskId = CreateTask(Task_HandleYesNoInput, 0x50);
        return TRUE;
    }
}

// unused
bool8 IsScriptActive(void)
{
    if (gSpecialVar_Result == 0xFF)
        return FALSE;
    else
        return TRUE;
}

/*static*/ void Task_HandleYesNoInput(u8 taskId)
{
    u8 left, top;

    if (gTasks[taskId].tRight < 5)
    {
        gTasks[taskId].tRight++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case -2:
        return;
    case -1:
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

#ifdef NONMATCHING
bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 columnCount)
{
    u8 bottom = 0;

    if (FuncIsActiveTask(Task_HandleMultichoiceGridInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 unk2;
        int width;
        int i;
        u8 newWidth;

        gSpecialVar_Result = 0xFF;
        width = 0;
        i = 0;

        if (width < gMultichoiceLists[multichoiceId].count)
        {
            do
            {
                width = display_text_and_get_width(gMultichoiceLists[multichoiceId].list[i].text, width);
                i++;
            } while (i < gMultichoiceLists[multichoiceId].count);
        }

        newWidth = convert_pixel_width_to_tile_width(width);

        left = sub_80E2D5C(left, columnCount * newWidth);
        unk2 = gMultichoiceLists[multichoiceId].count / columnCount;

        taskId = CreateTask(Task_HandleMultichoiceGridInput, 80);

        gTasks[taskId].tIgnoreBPress = ignoreBPress;
        gTasks[taskId].tWindowId = CreateWindowFromRect(left, top, columnCount * newWidth, unk2 * 2);
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 0);
        sub_81997AC(gTasks[taskId].tWindowId, newWidth * 8, columnCount, unk2, gMultichoiceLists[multichoiceId].list);
        sub_8199944(gTasks[taskId].tWindowId, newWidth * 8, columnCount, unk2, 0);
        CopyWindowToVram(gTasks[taskId].tWindowId, 3);
        return TRUE;
    }
}
#else
NAKED
bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 columnCount)
{
    asm_unified("	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x10\n\
	ldr r4, [sp, 0x30]\n\
	lsls r0, 24\n\
	lsrs r7, r0, 24\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	str r1, [sp, 0x4]\n\
	lsls r2, 24\n\
	lsrs r5, r2, 24\n\
	lsls r3, 24\n\
	lsrs r3, 24\n\
	str r3, [sp, 0x8]\n\
	lsls r4, 24\n\
	lsrs r4, 24\n\
	mov r10, r4\n\
	ldr r0, =Task_HandleMultichoiceGridInput\n\
	bl FuncIsActiveTask\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bne _080E2210\n\
	movs r0, 0\n\
	b _080E22E8\n\
	.pool\n\
_080E2210:\n\
	ldr r0, =gSpecialVar_Result\n\
	movs r1, 0xFF\n\
	strh r1, [r0]\n\
	movs r2, 0\n\
	movs r6, 0\n\
	ldr r1, =gMultichoiceLists\n\
	lsls r5, 3\n\
	adds r0, r5, r1\n\
	str r5, [sp, 0xC]\n\
	ldrb r0, [r0, 0x4]\n\
	cmp r2, r0\n\
	bge _080E2246\n\
	mov r8, r1\n\
_080E222A:\n\
	mov r0, r8\n\
	adds r4, r5, r0\n\
	ldr r1, [r4]\n\
	lsls r0, r6, 3\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	adds r1, r2, 0\n\
	bl display_text_and_get_width\n\
	adds r2, r0, 0\n\
	adds r6, 0x1\n\
	ldrb r4, [r4, 0x4]\n\
	cmp r6, r4\n\
	blt _080E222A\n\
_080E2246:\n\
	adds r0, r2, 0\n\
	bl convert_pixel_width_to_tile_width\n\
	adds r5, r0, 0\n\
	lsls r5, 24\n\
	lsrs r5, 24\n\
	mov r1, r10\n\
	muls r1, r5\n\
	mov r8, r1\n\
	adds r0, r7, 0\n\
	bl sub_80E2D5C\n\
	lsls r0, 24\n\
	lsrs r7, r0, 24\n\
	ldr r2, =gMultichoiceLists\n\
	mov r9, r2\n\
	ldr r0, [sp, 0xC]\n\
	add r9, r0\n\
	mov r1, r9\n\
	ldrb r0, [r1, 0x4]\n\
	mov r1, r10\n\
	bl __udivsi3\n\
	adds r6, r0, 0\n\
	lsls r6, 24\n\
	lsrs r6, 24\n\
	ldr r0, =Task_HandleMultichoiceGridInput\n\
	movs r1, 0x50\n\
	bl CreateTask\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	ldr r1, =gTasks\n\
	lsls r4, r0, 2\n\
	adds r4, r0\n\
	lsls r4, 3\n\
	adds r4, r1\n\
	mov r2, sp\n\
	ldrh r2, [r2, 0x8]\n\
	strh r2, [r4, 0x10]\n\
	mov r0, r8\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	lsls r3, r6, 25\n\
	lsrs r3, 24\n\
	adds r0, r7, 0\n\
	ldr r1, [sp, 0x4]\n\
	mov r2, r8\n\
	bl CreateWindowFromRect\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	strh r0, [r4, 0x14]\n\
	movs r1, 0\n\
	bl SetStandardWindowBorderStyle\n\
	ldrb r0, [r4, 0x14]\n\
	lsls r5, 27\n\
	lsrs r5, 24\n\
	mov r2, r9\n\
	ldr r1, [r2]\n\
	str r1, [sp]\n\
	adds r1, r5, 0\n\
	mov r2, r10\n\
	adds r3, r6, 0\n\
	bl sub_81997AC\n\
	ldrb r0, [r4, 0x14]\n\
	movs r1, 0\n\
	str r1, [sp]\n\
	adds r1, r5, 0\n\
	mov r2, r10\n\
	adds r3, r6, 0\n\
	bl sub_8199944\n\
	ldrb r0, [r4, 0x14]\n\
	movs r1, 0x3\n\
	bl CopyWindowToVram\n\
	movs r0, 0x1\n\
_080E22E8:\n\
	add sp, 0x10\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
	.pool");
}
#endif

/*static*/ void Task_HandleMultichoiceGridInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 selection = Menu_ProcessInputGridLayout();

    if (selection != -2)
    {
        if (selection == -1)
        {
            if (tIgnoreBPress)
                return;
            PlaySE(SE_SELECT);
            gSpecialVar_Result = 0x7F;
        }
        else
        {
            gSpecialVar_Result = selection;
        }
        sub_80E2A78(tWindowId);
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

#undef tLeft
#undef tTop
#undef tRight
#undef tBottom
#undef tIgnoreBPress
#undef tDoWrap
#undef tWindowId
#undef tMultichoiceId

bool8 ScrSpecial_CreatePCMenu(void)
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

/*static*/ void CreatePCMenu(void)
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

/*static*/ void sub_80E2578(void)
{
    u8 unk = 0;
    u8 count;
    u32 pixelWidth;
    u8 width;
    u8 windowId;
    u8 i;
    u8 y;
    u32 j;

    for (i = 0; i < ARRAY_COUNT(gUnknown_03001124); i++)
    {
        gUnknown_03001124[i] |= 0xFF;
    }

    GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);

    if (gSpecialVar_0x8004 == 0)
    {
        gUnknown_03001124[unk] = 0;
        unk++;
        if (FlagGet(FLAG_0x1D0) == TRUE)
        {
            gUnknown_03001124[unk] = 1;
            unk++;
        }
    }

    if (CheckBagHasItem(ITEM_EON_TICKET, 1) == TRUE && FlagGet(FLAG_SYS_HAS_EON_TICKET) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[unk] = 2;
            unk++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_0x1AE) == FALSE)
        {
            gUnknown_03001124[unk] = 2;
            unk++;
            FlagSet(FLAG_0x1AE);
        }
    }

    if (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1) == TRUE && FlagGet(FLAG_0x8E0) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[unk] = 3;
            unk++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_0x1DB) == FALSE)
        {
            gUnknown_03001124[unk] = 3;
            unk++;
            FlagSet(FLAG_0x1DB);
        }
    }

    if (CheckBagHasItem(ITEM_AURORA_TICKET, 1) == TRUE && FlagGet(FLAG_0x8D5) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[unk] = 4;
            unk++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_0x1AF) == FALSE)
        {
            gUnknown_03001124[unk] = 4;
            unk++;
            FlagSet(FLAG_0x1AF);
        }
    }

    if (CheckBagHasItem(ITEM_OLD_SEA_MAP, 1) == TRUE && FlagGet(FLAG_0x8D6) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            gUnknown_03001124[unk] = 5;
            unk++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_0x1B0) == FALSE)
        {
            gUnknown_03001124[unk] = 5;
            unk++;
            FlagSet(FLAG_0x1B0);
        }
    }

    gUnknown_03001124[unk] = 6;
    unk++;

    if (gSpecialVar_0x8004 == 0 && FlagGet(FLAG_0x1D0) == TRUE)
    {
        count = unk;
    }

    count = unk;
    if (count == 7)
    {
        gSpecialVar_0x8004 = 11;
        sub_813A128();
    }
    else
    {
        pixelWidth = 0;

        for (j = 0; j < ARRAY_COUNT(gUnknown_0858BB80); j++)
        {
            u8 test = gUnknown_03001124[j];
            if (test != 0xFF)
            {
                pixelWidth = display_text_and_get_width(gUnknown_0858BB80[test], pixelWidth);
            }
        }

        width = convert_pixel_width_to_tile_width(pixelWidth);
        windowId = CreateWindowFromRect(28 - width, (6 - count) * 2, width, count * 2);
        SetStandardWindowBorderStyle(windowId, 0);
        
        for (y = 0, i = 0; i < ARRAY_COUNT(gUnknown_0858BB80); i++)
        {
            if (gUnknown_03001124[i] != 0xFF)
            {
                AddTextPrinterParameterized(windowId, 1, gUnknown_0858BB80[gUnknown_03001124[i]], 8, y * 16 + 1, TEXT_SPEED_FF, NULL);
                y++;
            }
        }

        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, count - 1);
        CopyWindowToVram(windowId, 3);
        sub_80E1FBC(FALSE, count, windowId, 8);
    }
}
