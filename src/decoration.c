
// Includes
#include "global.h"
#include "malloc.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script.h"
#include "task.h"
#include "main.h"
#include "palette.h"
#include "songs.h"
#include "overworld.h"
#include "field_weather.h"
#include "field_player_avatar.h"
#include "field_camera.h"
#include "list_menu.h"
#include "menu_helpers.h"
#include "new_menu_helpers.h"
#include "menu_indicators.h"
#include "sound.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_scripts.h"
#include "player_pc.h"
#include "strings.h"

// Static type declarations

struct UnkStruct_0203A18C {
    struct ListMenuItem unk_000[41];
    u8 unk_148[41][24];
    u8 unk_520;
    u8 unk_521;
    u8 unk_522;
};

// Static RAM declarations

extern EWRAM_DATA u8 *gUnknown_0203A14C;
extern EWRAM_DATA u8 gUnknown_0203A150;
extern EWRAM_DATA u8 gUnknown_0203A151;
extern EWRAM_DATA u8 gUnknown_0203A152[16];
extern EWRAM_DATA u8 gUnknown_0203A162[12];
extern EWRAM_DATA u16 gUnknown_0203A16E;
extern EWRAM_DATA u16 gUnknown_0203A170;
extern EWRAM_DATA u8 gUnknown_0203A172;
extern EWRAM_DATA u8 gUnknown_0203A173;
extern EWRAM_DATA struct DecoPCPointers gUnknown_0203A17C;
extern EWRAM_DATA u8 gUnknown_0203A188[4];
extern EWRAM_DATA struct UnkStruct_0203A18C *gUnknown_0203A18C;

// Static ROM declarations

void sub_8126B80(u8 taskId);
void sub_8126C08(void);
void sub_8126DA4(u8 taskId);
void sub_8126D6C(u8 taskId);
void sub_8126DCC(u8 taskId);
void sub_8126DFC(u8 taskId);
void sub_8126E8C(u8 taskId);
void sub_8126F68(u8 winid, u8 decorCat, u8 x, u8 y, bool8 flag, u8 speed);
void sub_8127058(u8 *str, bool8 flag);
void sub_8127088(u8 taskId);
void sub_81270E8(u8 taskId);
void sub_8127180(u8 taskId);
void sub_812719C(u8 taskId);
void sub_81271CC(u8 taskId);
void sub_8127268(u8 taskId);
void sub_8127454(u8 *dest, u16 decorId);
void sub_8127620(u8 taskId);
void sub_812764C(u8 taskId);
void sub_8127744(u32 a0);
void sub_81277A8(void);
bool8 sub_81277BC(u8 idx);
bool8 sub_81277E8(u8 idx);
bool8 sub_81299AC(u8 taskId);
void sub_81279B4(u8 taskId);
void sub_8129ABC(u8 taskId);
void sub_8133E1C(u8 taskId);
void sub_812759C(u8 taskId);
void sub_8127718(u8 decorCat);

// .rodata

extern const struct WindowTemplate gUnknown_085A6B90[4];
extern const u8 *const gUnknown_085A6B28[];
extern const struct MenuAction gUnknown_085A6B48[];
extern const u8 *const gUnknown_085A6B68[];
extern void (*const gUnknown_085A6B78[][2])(u8 taskId);
extern const u16 gUnknown_085A6BB0[];
extern const struct ListMenuTemplate gUnknown_085A6BD0;
extern const u8 gUnknown_085A72E4[];
extern const u8 gUnknown_085A72EC[];

// .text

void sub_8126968(void)
{
    if (gUnknown_0203A173 < 8)
    {
        gUnknown_0203A14C = gDecorationInventories[gUnknown_0203A173].items;
    }
    if (gUnknown_0203A17C.isPlayerRoom == FALSE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    }
    if (gUnknown_0203A17C.isPlayerRoom == TRUE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    }
}

u8 sub_81269D4(u8 idx)
{
    u8 *winidx;
    struct WindowTemplate template;

    winidx = &gUnknown_0203A188[idx];
    if (idx == 0)
    {
        template = gUnknown_085A6B90[0];
        template.width = GetMaxWidthInMenuTable(gUnknown_085A6B48, 4);
        if (template.width > 18)
        {
            template.width = 18;
        }
        *winidx = AddWindow(&template);
    }
    else
    {
        *winidx = AddWindow(&gUnknown_085A6B90[idx]);
    }
    SetWindowBorderStyle(*winidx, 0, 0x214, 0xe);
    schedule_bg_copy_tilemap_to_vram(0);
    return *winidx;
}

void sub_8126A58(u8 idx)
{
    sub_8198070(gUnknown_0203A188[idx], FALSE);
    ClearWindowTilemap(gUnknown_0203A188[idx]);
    RemoveWindow(gUnknown_0203A188[idx]);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_8126A88(void)
{
    u8 idx;

    idx = sub_81269D4(0);
    PrintMenuTable(idx, 4, gUnknown_085A6B48);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(idx, 4, gUnknown_0203A150);
}

void sub_8126ABC(void)
{
    gUnknown_0203A150 = 0;
    ScriptContext2_Enable();
    sub_8126A88();
    sub_8126C08();
}

void sub_8126AD8(u8 taskId)
{
    sub_8126ABC();
    gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
    gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    gUnknown_0203A17C.size = sizeof(gSaveBlock1Ptr->secretBases[0].decorations);
    gUnknown_0203A17C.isPlayerRoom = FALSE;
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126B2C(u8 taskId)
{
    sub_8126ABC();
    gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
    gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    gUnknown_0203A17C.size = sizeof(gSaveBlock1Ptr->playerRoomDecor);
    gUnknown_0203A17C.isPlayerRoom = TRUE;
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126B80(u8 taskId)
{
    u8 menuPos;

    if (!gPaletteFade.active)
    {
        menuPos = GetMenuCursorPos();
        switch (ProcessMenuInput())
        {
            default:
                PlaySE(SE_SELECT);
                gUnknown_085A6B48[gUnknown_0203A150].func.void_u8(taskId);
                break;
            case -2:
                gUnknown_0203A150 = GetMenuCursorPos();
                if ((s8)menuPos != gUnknown_0203A150)
                {
                    sub_8126C08();
                }
                break;
            case -1:
                PlaySE(SE_SELECT);
                sub_8126D6C(taskId);
                break;
        }
    }
}

void sub_8126C08(void)
{
    FillWindowPixelBuffer(0, 0x11);
    AddTextPrinterParametrized(0, 1, gUnknown_085A6B68[gUnknown_0203A150], 0, 0, 2, 1, 3);
}

void sub_8126C48(u8 taskId)
{
    if (CountDecorations() == 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        gTasks[taskId].data[11] = 0;
        gUnknown_0203A173 = DECORCAT_DESK;
        sub_8126DCC(taskId);
    }
}

void sub_8126CA4(u8 taskId)
{
    if (!sub_81299AC(taskId))
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorationsInUse);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        sub_8126A58(0);
        sub_8197434(0, 0);
        fade_screen(1, 0);
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_8129ABC;
    }
}

void sub_8126D10(u8 taskId)
{
    if (CountDecorations() == 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        gTasks[taskId].data[11] = 1;
        gUnknown_0203A173 = DECORCAT_DESK;
        sub_8126DCC(taskId);
    }
}

void sub_8126D6C(u8 taskId)
{
    sub_8126A58(0);
    if (!gUnknown_0203A17C.isPlayerRoom)
    {
        ScriptContext1_SetupScript(gUnknown_0823B4E8);
        DestroyTask(taskId);
    }
    else
    {
        sub_816B060(taskId);
    }
}

void sub_8126DA4(u8 taskId)
{
    sub_8126C08();
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126DCC(u8 taskId)
{
    LoadPalette(gUnknown_085A6BB0, 0xd0, 0x20);
    sub_8197434(0, 0);
    sub_8126A58(0);
    sub_8126DFC(taskId);
}

void sub_8126DFC(u8 taskId)
{
    u8 winIdx;

    winIdx = sub_81269D4(1);
    sub_8126E8C(taskId);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(winIdx, 9, gUnknown_0203A173);
    gTasks[taskId].func = sub_8127088;
}

void sub_8126E44(u8 taskId)
{
    FillWindowPixelBuffer(gUnknown_0203A188[1], 0x11);
    sub_8126E8C(taskId);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gUnknown_0203A188[1], 9, gUnknown_0203A173);
    gTasks[taskId].func = sub_8127088;
}

void sub_8126E8C(u8 taskId)
{
    s16 *data;
    u8 r5;
    bool8 r8;
    u8 i;
    bool8 fl;

    data = gTasks[taskId].data;
    r5 = gUnknown_0203A188[1];
    fl = gUnknown_0203A17C.isPlayerRoom;
    r8 = FALSE;
    if (fl == TRUE && data[11] == 0)
    {
        r8 = TRUE;
    }
    for (i = 0; i < 8; i ++)
    {
        if (r8 == TRUE && i != DECORCAT_DOLL && i != DECORCAT_CUSHION)
        {
            sub_8126F68(r5, i, 8, i << 4, TRUE, 0xFF);
        }
        else
        {
            sub_8126F68(r5, i, 8, i << 4, FALSE, 0xFF);
        }
    }
    PrintTextOnWindow(r5, 1, gTasks[taskId].data[11] == 2 ? gText_Exit : gText_Cancel, 8, (i << 4) + 1, 0, 0);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_8126F68(u8 winid, u8 decorCat, u8 x, u8 y, bool8 flag, u8 speed)
{
    u8 width;
    u8 *strbuf;

    width = x == 8 ? 0x68 : 0x60;
    y ++;
    sub_8127058(gStringVar4, flag);
    strbuf = StringLength(gStringVar4) + gStringVar4;
    StringCopy(strbuf, gUnknown_085A6B28[decorCat]);
    PrintTextOnWindow(winid, 1, gStringVar4, x, y, speed, NULL);
    strbuf = ConvertIntToDecimalStringN(strbuf, CountDecorationCategoryN(decorCat), STR_CONV_MODE_RIGHT_ALIGN, 2);
    *strbuf++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(strbuf, gDecorationInventories[decorCat].size, STR_CONV_MODE_RIGHT_ALIGN, 2);
    x = GetStringRightAlignXOffset(1, gStringVar4, width);
    PrintTextOnWindow(winid, 1, gStringVar4, x, y, speed, NULL);
}

void sub_8127058(u8 *str, bool8 flag)
{
    StringCopy(str, gText_Color161Shadow161);
    if (flag == TRUE)
    {
        str[2] = 0x04; // RED
        str[5] = 0x05; // LIGHT_RED
    }
    else
    {
        str[2] = 0x02; // DARK_GREY
        str[5] = 0x03; // LIGHT_GREY
    }
}

void sub_8127088(u8 taskId)
{
    s8 input;

    if (!gPaletteFade.active)
    {
        input = ProcessMenuInput();
        switch (input)
        {
            case -1:
            case 8:
                PlaySE(SE_SELECT);
                sub_812719C(taskId);
                break;
            case -2:
                break;
            default:
                PlaySE(SE_SELECT);
                gUnknown_0203A173 = input;
                sub_81270E8(taskId);
                break;
        }
    }
}

void sub_81270E8(u8 taskId)
{
    gUnknown_0203A151 = CountDecorationCategoryN(gUnknown_0203A173);
    if (gUnknown_0203A151 != 0)
    {
        CondenseDecorationCategoryN(gUnknown_0203A173);
        gUnknown_0203A14C = gDecorationInventories[gUnknown_0203A173].items;
        sub_81279B4(taskId);
        gUnknown_0203A170 = 0;
        gUnknown_0203A16E = 0;
        gTasks[taskId].func = sub_8127620;
    }
    else
    {
        sub_8126A58(1);
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127180);
    }
}

void sub_8127180(u8 taskId)
{
    sub_8197434(0, 0);
    sub_8126DFC(taskId);
}

void sub_812719C(u8 taskId)
{
    if (gTasks[taskId].data[11] != 2)
    {
        sub_81271CC(taskId);
    }
    else
    {
        sub_8127268(taskId);
    }
}

void sub_81271CC(u8 taskId)
{
    sub_8126A58(1);
    sub_8126A88();
    sub_81973C4(0, 0);
    sub_8126C08();
    gTasks[taskId].func = sub_8126B80;
}

void sub_8127208(u8 taskId)
{
    LoadPalette(gUnknown_085A6BB0, 0xd0, 0x20);
    sub_8197434(0, 0);
    gTasks[taskId].data[11] = 2;
    gUnknown_0203A173 = DECORCAT_DESK;
    sub_8126DFC(taskId);
}

void sub_8127250(u8 *dest, u8 decorCat)
{
    StringCopy(dest, gUnknown_085A6B28[decorCat]);
}

void sub_8127268(u8 taskId)
{
    sub_8126A58(1);
    sub_8133E1C(taskId);
}

void sub_8127284(void)
{
    gUnknown_0203A18C->unk_520 = gUnknown_0203A151 + 1;
    if (gUnknown_0203A18C->unk_520 > 8)
    {
        gUnknown_0203A18C->unk_521 = 8;
    }
    else
    {
        gUnknown_0203A18C->unk_521 = gUnknown_0203A18C->unk_520;
    }
}

void sub_81272C8(void)
{
    sub_812225C(&gUnknown_0203A170, &gUnknown_0203A16E, gUnknown_0203A18C->unk_521, gUnknown_0203A18C->unk_520);
}

void sub_81272F8(void)
{
    sub_8122298(&gUnknown_0203A170, &gUnknown_0203A16E, gUnknown_0203A18C->unk_521, gUnknown_0203A18C->unk_520, 8);
}

void sub_8127330(u8 taskId)
{
    s16 *data;
    u16 i;

    data = gTasks[taskId].data;
    if ((gUnknown_0203A173 < DECORCAT_DOLL || gUnknown_0203A173 > DECORCAT_CUSHION) && gUnknown_0203A17C.isPlayerRoom == TRUE && data[11] == 0)
    {
        sub_8127058(gStringVar1, TRUE);
    }
    else
    {
        sub_8127058(gStringVar1, FALSE);
    }
    for (i = 0; i < gUnknown_0203A18C->unk_520 - 1; i ++)
    {
        sub_8127454(gUnknown_0203A18C->unk_148[i], gUnknown_0203A14C[i]);
        gUnknown_0203A18C->unk_000[i].unk_00 = gUnknown_0203A18C->unk_148[i];
        gUnknown_0203A18C->unk_000[i].unk_04 = i;
    }
    StringCopy(gUnknown_0203A18C->unk_148[i], gText_Cancel);
    gUnknown_0203A18C->unk_000[i].unk_00 = gUnknown_0203A18C->unk_148[i];
    gUnknown_0203A18C->unk_000[i].unk_04 = -2;
    gUnknown_03006310 = gUnknown_085A6BD0;
    gUnknown_03006310.unk_10 = gUnknown_0203A188[1];
    gUnknown_03006310.unk_0c = gUnknown_0203A18C->unk_520;
    gUnknown_03006310.unk_00 = gUnknown_0203A18C->unk_000;
    gUnknown_03006310.unk_0e = gUnknown_0203A18C->unk_521;
}

void sub_8127454(u8 *dest, u16 decorId)
{
    StringCopy(dest, gStringVar1);
    StringAppend(dest, gDecorations[decorId].name);
}

void sub_8127480(u32 a0, bool8 flag)
{
    if (flag != TRUE)
    {
        PlaySE(SE_SELECT);
    }
    sub_8127744(a0);
}

void sub_81274A0(u8 a0, s32 a1, u8 a2)
{
    if (a1 != -2)
    {
        if (sub_81277BC(a1 + 1) == TRUE)
        {
            blit_move_info_icon(a0, 0x18, 0x5c, a2 + 2);
        }
        else if (sub_81277E8(a1 + 1) == TRUE)
        {
            blit_move_info_icon(a0, 0x19, 0x5c, a2 + 2);
        }
    }
}

void sub_8127500(void)
{
    if (gUnknown_0203A18C->unk_522 == 0xFF)
    {
        gUnknown_0203A18C->unk_522 = AddScrollIndicatorArrowPairParametrized(0x02, 0x3c, 0x0c, 0x94, gUnknown_0203A18C->unk_520 - gUnknown_0203A18C->unk_521, 0x6e, 0x6e, &gUnknown_0203A170);
    }
}

void sub_8127554(void)
{
    if (gUnknown_0203A18C->unk_522 != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gUnknown_0203A18C->unk_522);
        gUnknown_0203A18C->unk_522 = 0xFF;
    }
}

void sub_8127580(u8 taskId)
{
    sub_81269D4(1);
    sub_812759C(taskId);
}

void sub_812759C(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    sub_81269D4(3);
    sub_8127718(gUnknown_0203A173);
    gUnknown_0203A18C = calloc(1, sizeof(struct UnkStruct_0203A18C));
    gUnknown_0203A18C->unk_522 = 0xFF;
    sub_8127284();
    sub_81272C8();
    sub_81272F8();
    sub_8127330(taskId);
    data[13] = ListMenuInit(&gUnknown_03006310, gUnknown_0203A170, gUnknown_0203A16E);
    sub_8127500();
}

void sub_8127620(u8 taskId)
{
    sub_812759C(taskId);
    gTasks[taskId].func = sub_812764C;
}

void sub_812764C(u8 taskId)
{
    s16 *data;
    s32 input;

    data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        input = ListMenuHandleInput(data[13]);
        get_coro_args_x18_x1A(data[13], &gUnknown_0203A170, &gUnknown_0203A16E);
        switch (input)
        {
            case -1:
                break;
            case -2:
                PlaySE(SE_SELECT);
                gUnknown_085A6B78[data[11]][1](taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                gUnknown_0203A172 = input;
                sub_8127554();
                sub_81AE6C8(data[13], &gUnknown_0203A170, &gUnknown_0203A16E);
                sub_8126A58(1);
                sub_81277A8();
                free(gUnknown_0203A18C);
                gUnknown_085A6B78[data[11]][0](taskId);
                break;
        }
    }
}

void sub_8127718(u8 decorCat)
{
    sub_8126F68(sub_81269D4(2), decorCat, 0, 0, 0, 0);
}

void sub_8127744(u32 a0)
{
    u8 winidx;
    const u8 *txt;

    winidx = gUnknown_0203A188[3];
    FillWindowPixelBuffer(winidx, 0x11);
    if (a0 >= gUnknown_0203A151)
    {
        txt = gText_GoBackPrevMenu;
    }
    else
    {
        txt = gDecorations[gUnknown_0203A14C[a0]].description;
    }
    PrintTextOnWindow(winidx, 1, txt, 0, 1, 0, 0);
}

void sub_81277A8(void)
{
    sub_8126A58(3);
    sub_8126A58(2);
}

bool8 sub_81277BC(u8 idx)
{
    u8 i;

    for (i = 0; i < 16; i ++)
    {
        if (gUnknown_0203A152[i] == idx)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_81277E8(u8 idx)
{
    u8 i;

    for (i = 0; i < 12; i ++)
    {
        if (gUnknown_0203A162[i] == idx)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_8127814(u8 taskId)
{
    u16 i;
    u16 j;
    u16 k;
    u16 cnt;

    cnt = 0;
    memset(gUnknown_0203A152, 0, 16);
    memset(gUnknown_0203A162, 0, 12);
    for (i = 0; i < 16; i ++)
    {
        if (gSaveBlock1Ptr->secretBases[0].decorations[i] != DECOR_NONE)
        {
            for (j = 0; j < gDecorationInventories[gUnknown_0203A173].size; j ++)
            {
                if (gUnknown_0203A14C[j] == gSaveBlock1Ptr->secretBases[0].decorations[i])
                {
                    for (k = 0; k < cnt && gUnknown_0203A152[k] != j + 1; k ++);
                    if (k == cnt)
                    {
                        gUnknown_0203A152[cnt] = j + 1;
                        cnt ++;
                        break;
                    }
                }
            }
        }
    }
    cnt = 0;
    for (i = 0; i < 12; i ++)
    {
        if (gSaveBlock1Ptr->playerRoomDecor[i] != DECOR_NONE)
        {
            for (j = 0; j < gDecorationInventories[gUnknown_0203A173].size; j ++)
            {
                if (gUnknown_0203A14C[j] == gSaveBlock1Ptr->playerRoomDecor[i] && sub_81277BC(j + 1) != TRUE)
                {
                    for (k = 0; k < cnt && gUnknown_0203A162[k] != j + 1; k ++);
                    if (k == cnt)
                    {
                        gUnknown_0203A162[cnt] = j + 1;
                        cnt ++;
                        break;
                    }
                }
            }
        }
    }
}

void sub_81279B4(u8 taskId)
{
    sub_8127814(taskId);
}

bool8 sub_81279C4(void)
{
    u16 i;
    for (i = 0; i < 16; i ++)
    {
        if (gUnknown_0203A152[i] == gUnknown_0203A170 + gUnknown_0203A16E + 1)
        {
            return FALSE;
        }
        if (i < 12 && gUnknown_0203A162[i] == gUnknown_0203A170 + gUnknown_0203A16E + 1)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_8127A14(u8 taskId)
{
    sub_81269D4(1);
    sub_8127620(taskId);
}

void sub_8127A30(u8 taskId)
{
    sub_8197434(0, 0);
    gTasks[taskId].func = sub_8127A14;
}

void sub_8127A5C(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        sub_8197434(0, 0);
        sub_81269D4(1);
        sub_8127620(taskId);
    }
}

void sub_8127A8C(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    sub_8127554();
    sub_81277A8();
    sub_81AE6C8(data[13], NULL, NULL);
    free(gUnknown_0203A18C);
    sub_8126E44(taskId);
}

void sub_8127ACC(u8 taskId)
{
    gTasks[taskId].data[3] = gSaveBlock1Ptr->pos.x;
    gTasks[taskId].data[4] = gSaveBlock1Ptr->pos.y;
    PlayerGetDestCoords(&gTasks[taskId].data[0], &gTasks[taskId].data[1]);
}

void sub_8127B04(u8 taskId)
{
    DrawWholeMapView();
    Overworld_SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, gTasks[taskId].data[3], gTasks[taskId].data[4]);
    warp_in();
}

u16 sub_8127B54(u8 decor, u8 a1)
{
    u16 resp;

    resp = -1;
    switch (decor)
    {
        case DECOR_STAND:
            resp = gUnknown_085A72E4[a1] << 12;
            return resp;
        case DECOR_SLIDE:
            resp = gUnknown_085A72EC[a1] << 12;
            return resp;
        default:
            return resp;
    }
}
