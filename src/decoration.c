
// Includes
#include "global.h"
#include "decompress.h"
#include "malloc.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script.h"
#include "task.h"
#include "main.h"
#include "palette.h"
#include "songs.h"
#include "overworld.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "field_weather.h"
#include "field_player_avatar.h"
#include "field_camera.h"
#include "field_screen.h"
#include "field_map_obj.h"
#include "list_menu.h"
#include "menu_helpers.h"
#include "new_menu_helpers.h"
#include "menu_indicators.h"
#include "sound.h"
#include "event_scripts.h"
#include "event_data.h"
#include "region_map.h"
#include "player_pc.h"
#include "strings.h"
#include "tv.h"
#include "secret_base.h"
#include "tilesets.h"
#include "item_icon.h"
#include "decoration_inventory.h"
#include "decoration.h"

// Static type declarations

struct UnkStruct_0203A18C {
    struct ListMenuItem unk_000[41];
    u8 unk_148[41][24];
    u8 unk_520;
    u8 unk_521;
    u8 unk_522;
};

struct UnkStruct_0203A190 {
    /*0x000; 0x0203a190*/ const struct Decoration *decoration;
    /*0x004; 0x0203a194*/ u16 tiles[0x40];
    /*0x084; 0x0203a214*/ u8 image[0x800];
    /*0x884; 0x0203aa14*/ u16 palette[16];
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
extern EWRAM_DATA struct UnkStruct_0203A190 gUnknown_0203A190;
extern EWRAM_DATA u16 gUnknown_0203AA34;
extern EWRAM_DATA u16 gUnknown_0203AA36;
extern EWRAM_DATA u8 gUnknown_0203AA38;
extern EWRAM_DATA u8 gUnknown_0203AA39;
extern EWRAM_DATA u8 gUnknown_0203AA3A;
extern EWRAM_DATA struct OamData gUnknown_0203AA3C;
extern EWRAM_DATA struct {
    u8 idx;
    u8 width;
    u8 height;
    u16 flagId;
} gUnknown_0203AA44[];
extern EWRAM_DATA u8 gUnknown_0203AAC4;

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
void sub_81279B4(u8 taskId);
void sub_812759C(u8 taskId);
void sub_8127718(u8 decorCat);
void sub_8128060(u8 taskId);
void ConfigureCameraObjectForPlacingDecoration(struct UnkStruct_0203A190 *data, u8 decor);
void SetUpPlacingDecorationPlayerAvatar(u8 taskId, struct UnkStruct_0203A190 *data);
void sub_812826C(u8 taskId);
void sub_8128950(u8 taskId);
void sub_81289D0(u8 taskId);
void sub_8128AAC(u8 taskId);
void sub_8128B80(u8 taskId);
void sub_8128BBC(u8 taskId);
void c1_overworld_prev_quest(u8 taskId);
void sub_8128CD4(void);
void sub_8128DE0(void);
void sub_8128FD8(u8 taskId);
void sub_8129020(u8 taskId);
void sub_81292D0(struct Sprite *sprite);
void sub_81292E8(struct Sprite *sprite);
u8 gpu_pal_decompress_alloc_tag_and_upload(struct UnkStruct_0203A190 *data, u8 decor);
const void *GetDecorationIconPicOrPalette(u16 decor, u8 mode);
bool8 sub_81299AC(u8 taskId);
void sub_8129ABC(u8 taskId);
void sub_8129B34(u8 taskId);
void sub_8129C74(u8 taskId);
void sub_8129D64(u8 taskId);
void sub_812A0E8(u8 taskId);
void sub_812A1A0(u8 taskId);
void sub_812A1F0(u8 taskId);
void sub_812A36C(struct Sprite *sprite);
void sub_812A39C(void);
void sub_812A3C8(void);
void sub_8133E1C(u8 taskId);

// .rodata

extern const struct WindowTemplate gUnknown_085A6B90[4];
extern const u8 *const gUnknown_085A6B28[];
extern const struct MenuAction gUnknown_085A6B48[];
extern const u8 *const gUnknown_085A6B68[];
extern void (*const gUnknown_085A6B78[][2])(u8 taskId);
extern const u16 gUnknown_085A6BB0[];
extern const struct ListMenuTemplate gUnknown_085A6BD0;
extern const void *const gUnknown_085A6BE8[][2];
extern const struct SpriteTemplate gUnknown_085A72A4;
extern const struct YesNoFuncTable gUnknown_085A72C4;
extern const struct YesNoFuncTable gUnknown_085A72CC;
extern const struct YesNoFuncTable gUnknown_085A72D4[];
extern const u8 gUnknown_085A72E4[];
extern const u8 gUnknown_085A72EC[];
extern const struct {
    const u8 *tiles;
    const u8 *y;
    const u8 *x;
    u8 size;
} gUnknown_085A71B0[];
extern const struct {
    u8 shape;
    u8 size;
    u8 x;
    u8 y;
} gUnknown_085A7250[];
extern const struct SpriteTemplate gUnknown_085A728C;
extern const struct SpritePalette gUnknown_085A72BC;
extern const u16 gUnknown_085A72F4[];
extern const struct SpriteTemplate gUnknown_085A7404;

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

void sub_8127B90(u16 mapX, u16 mapY, u8 decWidth, u8 decHeight, u16 decor)
{
    u16 i;
    u16 j;
    u16 behavior;
    u16 flags;
    u16 v0;
    u16 v1;
    s16 decLeft;
    s16 decBottom;

    for (i = 0; i < decHeight; i ++)
    {
        decBottom = mapY - decHeight + 1 + i;
        for (j = 0; j < decWidth; j ++)
        {
            decLeft = mapX + j;
            behavior = GetBehaviorByMetatileId(0x200 + gDecorations[decor].tiles[i * decWidth + j]);
            if (MetatileBehavior_IsMB_B9(behavior) == TRUE || (gDecorations[decor].permission != DECORPERM_PASS_FLOOR && (behavior >> 12)))
            {
                flags = 0xc00;
            }
            else
            {
                flags = 0x000;
            }
            if (gDecorations[decor].permission != DECORPERM_NA_WALL && MetatileBehavior_IsMB_B7(MapGridGetMetatileBehaviorAt(decLeft, decBottom)) == TRUE)
            {
                v0 = 1;
            }
            else
            {
                v0 = 0;
            }
            v1 = sub_8127B54(gDecorations[decor].id, i * decWidth + j);
            if (v1 != 0xFFFF)
            {
                MapGridSetMetatileEntryAt(decLeft, decBottom, (gDecorations[decor].tiles[i * decWidth + j] + (0x200 | v0)) | flags | v1);
            }
            else
            {
                MapGridSetMetatileIdAt(decLeft, decBottom, (gDecorations[decor].tiles[i * decWidth + j] + (0x200 | v0)) | flags);
            }
        }
    }
}

void sub_8127D38(u16 mapX, u16 mapY, u16 decor)
{
    switch (gDecorations[decor].shape)
    {
        case DECORSHAPE_1x1:
            sub_8127B90(mapX, mapY, 1, 1, decor);
            break;
        case DECORSHAPE_2x1:
            sub_8127B90(mapX, mapY, 2, 1, decor);
            break;
        case DECORSHAPE_3x1: // unused
            sub_8127B90(mapX, mapY, 3, 1, decor);
            break;
        case DECORSHAPE_4x2:
            sub_8127B90(mapX, mapY, 4, 2, decor);
            break;
        case DECORSHAPE_2x2:
            sub_8127B90(mapX, mapY, 2, 2, decor);
            break;
        case DECORSHAPE_1x2:
            sub_8127B90(mapX, mapY, 1, 2, decor);
            break;
        case DECORSHAPE_1x3: // unused
            sub_8127B90(mapX, mapY, 1, 3, decor);
            break;
        case DECORSHAPE_2x4:
            sub_8127B90(mapX, mapY, 2, 4, decor);
            break;
        case DECORSHAPE_3x3:
            sub_8127B90(mapX, mapY, 3, 3, decor);
            break;
        case DECORSHAPE_3x2:
            sub_8127B90(mapX, mapY, 3, 2, decor);
            break;
    }
}

void sub_8127E18(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < 14; i ++)
    {
        if (FlagGet(0xAE + i) == TRUE)
        {
            FlagClear(0xAE + i);
            for (j = 0; j < gMapHeader.events->mapObjectCount; j ++)
            {
                if (gMapHeader.events->mapObjects[j].flagId == 0xAE + i)
                {
                    break;
                }
            }
            VarSet(0x3F20 + gMapHeader.events->mapObjects[j].graphicsId, gUnknown_0203A190.decoration->tiles[0]);
            gSpecialVar_0x8005 = gMapHeader.events->mapObjects[j].localId;
            gSpecialVar_0x8006 = gUnknown_0203AA34;
            gSpecialVar_0x8007 = gUnknown_0203AA36;
            show_sprite(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            sub_808EBA8(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
            sub_808F254(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            break;
        }
    }
}

bool8 sub_8127F38(void)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] == DECOR_NONE)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_8127F68(u8 taskId)
{
    if (gUnknown_0203A17C.isPlayerRoom == TRUE && gUnknown_0203A173 != DECORCAT_DOLL && gUnknown_0203A173 != DECORCAT_CUSHION)
    {
        StringExpandPlaceholders(gStringVar4, gText_CantPlaceInRoom);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
    }
    else if (sub_81279C4() == TRUE)
    {
        if (sub_8127F38() == TRUE)
        {
            fade_screen(1, 0);
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].func = sub_8128060;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gUnknown_0203A17C.size, STR_CONV_MODE_RIGHT_ALIGN, 2);
            if (gUnknown_0203A17C.isPlayerRoom == FALSE) {
                StringExpandPlaceholders(gStringVar4, gText_NoMoreDecorations);
            }
            else
            {
                StringExpandPlaceholders(gStringVar4, gText_NoMoreDecorations2);
            }
            DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
        }
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gText_InUseAlready);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
    }
}

void sub_8128060(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_8127ACC(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            gPaletteFade.bufferTransferDisabled = TRUE;
            ConfigureCameraObjectForPlacingDecoration(&gUnknown_0203A190, gUnknown_0203A14C[gUnknown_0203A172]);
            sub_812826C(taskId);
            SetUpPlacingDecorationPlayerAvatar(taskId, &gUnknown_0203A190);
            pal_fill_black();
            gPaletteFade.bufferTransferDisabled = FALSE;
            gTasks[taskId].data[2] = 2;
            break;
        case 2:
            if (sub_80ABDFC() == TRUE)
            {
                gTasks[taskId].data[12] = 0;
                sub_8128FD8(taskId);
            }
            break;
    }
}

void ConfigureCameraObjectForPlacingDecoration(struct UnkStruct_0203A190 *data, u8 decor)
{
    gUnknown_0203AA38 = gSprites[gUnknown_03005DD0.unk4].data0;
    gUnknown_03005DD0.unk4 = gpu_pal_decompress_alloc_tag_and_upload(data, decor);
    gSprites[gUnknown_03005DD0.unk4].oam.priority = 1;
    gSprites[gUnknown_03005DD0.unk4].callback = sub_81292D0;
    gSprites[gUnknown_03005DD0.unk4].pos1.x = gUnknown_085A7250[data->decoration->shape].x;
    gSprites[gUnknown_03005DD0.unk4].pos1.y = gUnknown_085A7250[data->decoration->shape].y;
}

void SetUpPlacingDecorationPlayerAvatar(u8 taskId, struct UnkStruct_0203A190 *data)
{
    u8 v0;

    v0 = 16 * (u8)gTasks[taskId].data[5] + gUnknown_085A7250[data->decoration->shape].x - 8 * ((u8)gTasks[taskId].data[5] - 1);
    if (data->decoration->shape == DECORSHAPE_3x1 || data->decoration->shape == DECORSHAPE_3x3 || data->decoration->shape == DECORSHAPE_3x2)
    {
        v0 -= 8;
    }
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        gUnknown_0203AA39 = AddPseudoFieldObject(0xC1, SpriteCallbackDummy, v0, 0x48, 0);
    }
    else
    {
        gUnknown_0203AA39 = AddPseudoFieldObject(0xC2, SpriteCallbackDummy, v0, 0x48, 0);
    }
    gSprites[gUnknown_0203AA39].oam.priority = 1;
    DestroySprite(&gSprites[gUnknown_0203AA38]);
    gUnknown_0203AA38 = gUnknown_03005DD0.unk4;
}

void sub_812826C(u8 taskId)
{
    switch (gDecorations[gUnknown_0203A14C[gUnknown_0203A172]].shape)
    {
        case DECORSHAPE_1x1:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_2x1:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_3x1:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_4x2:
            gTasks[taskId].data[5] = 4;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_2x2:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_1x2:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_1x3:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 3;
            gTasks[taskId].data[1]++;
            break;
        case DECORSHAPE_2x4:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 4;
            break;
        case DECORSHAPE_3x3:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 3;
            break;
        case DECORSHAPE_3x2:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 2;
            break;
    }
}

void sub_81283BC(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[gUnknown_0203AA38].data7 = 1;
    gSprites[gUnknown_0203AA39].data7 = 1;
    sub_8128DE0();
    sub_8128950(taskId);
}

void sub_8128414(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[gUnknown_0203AA38].data7 = 1;
    gSprites[gUnknown_0203AA39].data7 = 1;
    sub_8128DE0();
    StringExpandPlaceholders(gStringVar4, gText_CancelDecorating);
    DisplayItemMessageOnField(taskId, gStringVar4, sub_8128B80);
}

bool8 sub_8128484(u8 behaviorAt, u16 behaviorBy)
{
    if (MetatileBehavior_IsMB_B3(behaviorAt) != TRUE || behaviorBy != 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_81284AC(u8 taskId, s16 x, s16 y, u16 decor)
{
    if (x == gTasks[taskId].data[3] + 7 && y == gTasks[taskId].data[4] + 7 && decor != DECOR_NONE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_81284F4(u16 behaviorAt, const struct Decoration *decoration)
{
    if (MetatileBehavior_IsMB_B3(behaviorAt) != TRUE)
    {
        if (decoration->id == DECOR_SOLID_BOARD && MetatileBehavior_IsMB_C2(behaviorAt) == TRUE)
        {
            return TRUE;
        }
        if (MetatileBehavior_IsNormal(behaviorAt))
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_812853C(u8 taskId, const struct Decoration *decoration)
{
    u8 i;
    u8 j;
    u8 behaviorAt;
    u16 behaviorBy;
    u8 mapY;
    u8 mapX;
    s16 curY;
    s16 curX;
    mapY = gTasks[taskId].data[6];
    mapX = gTasks[taskId].data[5];

    switch (decoration->permission)
    {
        case DECORPERM_SOLID_FLOOR:
        case DECORPERM_PASS_FLOOR:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    behaviorBy = GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]) & 0xf000;
                    if (!sub_81284F4(behaviorAt, decoration))
                    {
                        return FALSE;
                    }
                    if (!sub_81284AC(taskId, curX, curY, behaviorBy))
                    {
                        return FALSE;
                    }
                    behaviorAt = GetFieldObjectIdByXYZ(curX, curY, 0);
                    if (behaviorAt != 0 && behaviorAt != 16)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case DECORPERM_BEHIND_FLOOR:
            for (i=0; i<mapY-1; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    behaviorBy = GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]) & 0xf000;
                    if (!MetatileBehavior_IsNormal(behaviorAt) && !sub_8128484(behaviorAt, behaviorBy))
                    {
                        return FALSE;
                    }
                    if (!sub_81284AC(taskId, curX, curY, behaviorBy))
                    {
                        return FALSE;
                    }
                    if (GetFieldObjectIdByXYZ(curX, curY, 0) != 16)
                    {
                        return FALSE;
                    }
                }
            }
            curY = gTasks[taskId].data[1] - mapY + 1;
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                behaviorBy = GetBehaviorByMetatileId(0x200 + decoration->tiles[j]) & 0xf000;
                if (!MetatileBehavior_IsNormal(behaviorAt) && !MetatileBehavior_IsMB_B7(behaviorAt))
                {
                    return FALSE;
                }
                if (!sub_81284AC(taskId, curX, curY, behaviorBy))
                {
                    return FALSE;
                }
                behaviorAt = GetFieldObjectIdByXYZ(curX, curY, 0);
                if (behaviorAt != 0 && behaviorAt != 16)
                {
                    return FALSE;
                }
            }
            break;
        case DECORPERM_NA_WALL:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    if (!MetatileBehavior_IsMB_B7(MapGridGetMetatileBehaviorAt(curX, curY)))
                    {
                        return FALSE;
                    }
                    if (MapGridGetMetatileIdAt(curX, curY + 1) == 0x28c)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case DECORPERM_SOLID_MAT:
            curY = gTasks[taskId].data[1];
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                if (decoration->shape == DECORSHAPE_1x2)
                {
                    if (!MetatileBehavior_IsMB_C3(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                else if (!MetatileBehavior_IsMB_B5(behaviorAt))
                {
                    if (!MetatileBehavior_IsMB_C3(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                if (GetFieldObjectIdByXYZ(curX, curY, 0) != 16)
                {
                    return FALSE;
                }
            }
            break;
    }
    return TRUE;
}

void sub_8128950(u8 taskId)
{
    if (sub_812853C(taskId, &gDecorations[gUnknown_0203A14C[gUnknown_0203A172]]) == TRUE)
    {
        StringExpandPlaceholders(gStringVar4, gText_PlaceItHere);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_81289D0);
    }
    else
    {
        PlaySE(SE_HAZURE);
        StringExpandPlaceholders(gStringVar4, gText_CantBePlacedHere);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8129020);
    }
}

void sub_81289D0(u8 taskId)
{
    sub_8197930();
    sub_8121F68(taskId, &gUnknown_085A72C4);
}

void sub_81289F0(u8 taskId)
{
    sub_8197434(0, 0);
    sub_8128AAC(taskId);
    if (gDecorations[gUnknown_0203A14C[gUnknown_0203A172]].permission != DECORPERM_SOLID_MAT)
    {
        sub_8127D38(gTasks[taskId].data[0], gTasks[taskId].data[1], gUnknown_0203A14C[gUnknown_0203A172]);
    }
    else
    {
        gUnknown_0203AA34 = gTasks[taskId].data[0] - 7;
        gUnknown_0203AA36 = gTasks[taskId].data[1] - 7;
        ScriptContext1_SetupScript(gUnknown_08275D1F);
    }
    gSprites[gUnknown_0203AA38].pos1.y += 2;
    if (gMapHeader.regionMapSectionId == REGION_MAP_SECRET_BASE)
    {
        TV_PutSecretBaseVisitOnTheAir();
    }
    sub_8128BBC(taskId);
}

void sub_8128AAC(u8 taskId)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] == DECOR_NONE)
        {
            gUnknown_0203A17C.items[i] = gUnknown_0203A14C[gUnknown_0203A172];
            gUnknown_0203A17C.pos[i] = ((gTasks[taskId].data[0] - 7) << 4) + (gTasks[taskId].data[1] - 7);
            break;
        }
    }
    if (!gUnknown_0203A17C.isPlayerRoom)
    {
        for (i = 0; i < 16; i ++)
        {
            if (gUnknown_0203A152[i] == 0)
            {
                gUnknown_0203A152[i] = gUnknown_0203A172 + 1;
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < 12; i ++)
        {
            if (gUnknown_0203A162[i] == 0)
            {
                gUnknown_0203A162[i] = gUnknown_0203A172 + 1;
                break;
            }
        }
    }
}

void sub_8128B80(u8 taskId)
{
    sub_8197930();
    sub_8121F68(taskId, &gUnknown_085A72CC);
}

void sub_8128BA0(u8 taskId)
{
    sub_8197434(0, 0);
    sub_8128BBC(taskId);
}

void sub_8128BBC(u8 taskId)
{
    fade_screen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = c1_overworld_prev_quest;
}

void c1_overworld_prev_quest(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            ScriptContext2_Enable();
            if (!gPaletteFade.active)
            {
                sub_8127B04(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_812A3C8();
            FreeSpritePaletteByTag(0xbe5);
            gFieldCallback = sub_8128CD4;
            SetMainCallback2(c2_exit_to_overworld_2_switch);
            DestroyTask(taskId);
            break;
    }
}

void sub_8128C64(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            sub_80E9578();
            data[2] ++;
            break;
        case 1:
            ScriptContext1_SetupScript(gUnknown_08275D0C);
            data[2] ++;
            break;
        case 2:
            ScriptContext2_Enable();
            data[2] ++;
            break;
        case 3:
            if (sub_80ABDFC() == TRUE)
            {
                gTasks[taskId].func = sub_812764C;
            }
            break;
    }
}

void sub_8128CD4(void)
{
    u8 taskId;

    ScriptContext2_Enable();
    pal_fill_black();
    taskId = CreateTask(sub_8128C64, 8);
    sub_8127580(taskId);
    gTasks[taskId].data[2] = 0;
}

bool8 sub_8128D10(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (gUnknown_0203AA3A == DIR_SOUTH && data[1] - data[6] - 6 < 0)
    {
        data[1] ++;
        return FALSE;
    }
    if (gUnknown_0203AA3A == DIR_NORTH && data[1] - 7 >= gMapHeader.mapData->height)
    {
        data[1] --;
        return FALSE;
    }
    if (gUnknown_0203AA3A == DIR_WEST && data[0] - 7 < 0)
    {
        data[0] ++;
        return FALSE;
    }
    if (gUnknown_0203AA3A == DIR_EAST && data[0] + data[5] - 8 >= gMapHeader.mapData->width)
    {
        data[0] --;
        return FALSE;
    }
    return TRUE;
}

bool8 sub_8128DB4(void)
{
    u16 heldKeys;

    heldKeys = gMain.heldKeys & 0x0F0;
    if (heldKeys != DPAD_UP && heldKeys != DPAD_DOWN && heldKeys != DPAD_LEFT && heldKeys != DPAD_RIGHT)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_8128DE0(void)
{
    gUnknown_0203AA3A = 0;
    gSprites[gUnknown_0203AA38].data2 = 0;
    gSprites[gUnknown_0203AA38].data3 = 0;
}

void sub_8128E18(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (!gSprites[gUnknown_0203AA38].data4)
    {
        if (data[10] == 1)
        {
            gUnknown_085A72D4[data[12]].yesFunc(taskId);
            return;
        } else if (data[10] == 2)
        {
            gUnknown_085A72D4[data[12]].noFunc(taskId);
            return;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_UP)
        {
            gUnknown_0203AA3A = DIR_SOUTH;
            gSprites[gUnknown_0203AA38].data2 =  0;
            gSprites[gUnknown_0203AA38].data3 = -2;
            data[1]--;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_DOWN)
        {
            gUnknown_0203AA3A = DIR_NORTH;
            gSprites[gUnknown_0203AA38].data2 =  0;
            gSprites[gUnknown_0203AA38].data3 =  2;
            data[1]++;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_LEFT)
        {
            gUnknown_0203AA3A = DIR_WEST;
            gSprites[gUnknown_0203AA38].data2 = -2;
            gSprites[gUnknown_0203AA38].data3 =  0;
            data[0]--;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_RIGHT)
        {
            gUnknown_0203AA3A = DIR_EAST;
            gSprites[gUnknown_0203AA38].data2 =  2;
            gSprites[gUnknown_0203AA38].data3 =  0;
            data[0]++;
        }
        if (!sub_8128DB4() || !sub_8128D10(taskId))
        {
            sub_8128DE0();
        }
    }
    if (gUnknown_0203AA3A)
    {
        gSprites[gUnknown_0203AA38].data4++;
        gSprites[gUnknown_0203AA38].data4 &= 7;
    }
    if (!data[10])
    {
        if (gMain.newKeys & A_BUTTON)
        {
            data[10] = A_BUTTON;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            data[10] = B_BUTTON;
        }
    }
}

void sub_8128FD8(u8 taskId)
{
    sub_8197434(0, 1);
    gSprites[gUnknown_0203AA38].data7 = 0;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8128E18;
}

void sub_8129020(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        sub_8128FD8(taskId);
    }
}

void sub_8129048(struct UnkStruct_0203A190 *data)
{
    CpuFill16(0, data, sizeof(*data));
}

void sub_8129068(u16 *dest, u16 pal)
{
    CpuFastCopy(&((u16 *)gTilesetPointer_SecretBase->palettes)[pal << 4], dest, 32);
}

void sub_8129088(u8 *dest, u16 tile)
{
    u8 buffer[32];
    u16 mode;
    u16 i;

    mode = tile >> 10;
    if (tile != 0)
    {
        tile &= 0x03FF;
    }
    CpuFastCopy(&((u8 *)gTilesetPointer_SecretBase->tiles)[tile << 5], buffer, 32);
    switch (mode)
    {
        case 0:
            CpuFastCopy(buffer, dest, 32);
            break;
        case 1:
            for (i = 0; i < 8; i ++)
            {
                dest[4 * i] = (buffer[4 * (i + 1) - 1] >> 4) + ((buffer[4 * (i + 1) - 1] & 0x0F) << 4);
                dest[4 * i + 1] = (buffer[4 * (i + 1) - 2] >> 4) + ((buffer[4 * (i + 1) - 2] & 0x0F) << 4);
                dest[4 * i + 2] = (buffer[4 * (i + 1) - 3] >> 4) + ((buffer[4 * (i + 1) - 3] & 0x0F) << 4);
                dest[4 * i + 3] = (buffer[4 * (i + 1) - 4] >> 4) + ((buffer[4 * (i + 1) - 4] & 0x0F) << 4);
            }
            break;
        case 2:
            for (i = 0; i < 8; i ++)
            {
                dest[4 * i] = buffer[4 * (7 - i)];
                dest[4 * i + 1] = buffer[4 * (7 - i) + 1];
                dest[4 * i + 2] = buffer[4 * (7 - i) + 2];
                dest[4 * i + 3] = buffer[4 * (7 - i) + 3];
            }
            break;
        case 3:
            for (i = 0; i < 32; i ++)
            {
                dest[i] = (buffer[31 - i] >> 4) + ((buffer[31 - i] & 0x0F) << 4);
            }
            break;
    }
}

void sub_81291A4(struct UnkStruct_0203A190 *data)
{
    u16 i;
    for (i = 0; i < 64; i ++)
    {
        sub_8129088(&data->image[i * 32], data->tiles[i]);
    }
}

u16 sub_81291CC(u16 tile)
{
    return ((u16 *)gTilesetPointer_SecretBaseRedCave->metatiles)[tile] & 0xFFF;
}

void sub_81291E8(struct UnkStruct_0203A190 *data)
{
    u8 i;
    u8 shape;

    shape = data->decoration->shape;
    for (i = 0; i < gUnknown_085A71B0[shape].size; i ++)
    {
        data->tiles[gUnknown_085A71B0[shape].tiles[i]] = sub_81291CC(data->decoration->tiles[gUnknown_085A71B0[shape].y[i]] * 8 + gUnknown_085A71B0[shape].x[i]);
    }
}

void sub_812925C(u8 decoShape)
{
    gUnknown_0203AA3C.y = 0;
    gUnknown_0203AA3C.affineMode = ST_OAM_AFFINE_OFF;
    gUnknown_0203AA3C.objMode = ST_OAM_OBJ_NORMAL;
    gUnknown_0203AA3C.mosaic = 0;
    gUnknown_0203AA3C.bpp = ST_OAM_4BPP;
    gUnknown_0203AA3C.shape = gUnknown_085A7250[decoShape].shape;
    gUnknown_0203AA3C.x = 0;
    gUnknown_0203AA3C.matrixNum = 0;
    gUnknown_0203AA3C.size = gUnknown_085A7250[decoShape].size;
    gUnknown_0203AA3C.tileNum = 0;
    gUnknown_0203AA3C.priority = 0;
    gUnknown_0203AA3C.paletteNum = 0;
}

void sub_81292D0(struct Sprite *sprite)
{
    sprite->data2 = 0;
    sprite->data3 = 0;
    sprite->data4 = 0;
    sprite->data5 = 0;
    sprite->data6 = 0;
    sprite->data7 = 0;
    sprite->callback = sub_81292E8;
}

void sub_81292E8(struct Sprite *sprite)
{
    if (sprite->data7 == 0)
    {
        if (sprite->data6 < 15)
        {
            sprite->invisible = FALSE;
        }
        else
        {
            sprite->invisible = TRUE;
        }
        sprite->data6 ++;
        sprite->data6 &= 0x1F;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

u8 gpu_pal_decompress_alloc_tag_and_upload(struct UnkStruct_0203A190 *data, u8 decor)
{
    sub_8129048(data);
    data->decoration = &gDecorations[decor];
    if (data->decoration->permission == DECORPERM_SOLID_MAT)
    {
        return AddPseudoFieldObject(data->decoration->tiles[0], SpriteCallbackDummy, 0, 0, 1);
    }
    FreeSpritePaletteByTag(0xBE5);
    sub_81291E8(data);
    sub_812925C(data->decoration->shape);
    sub_81291A4(data);
    sub_8129068(data->palette, ((u16 *)gTilesetPointer_SecretBaseRedCave->metatiles)[(data->decoration->tiles[0] * 8) + 7] >> 12);
    LoadSpritePalette(&gUnknown_085A72BC);
    return CreateSprite(&gUnknown_085A728C, 0, 0, 0);
}

u8 AddDecorationIconObjectFromIconTable(u16 tilesTag, u16 paletteTag, u8 decor)
{
    struct SpriteSheet sheet;
    struct CompressedSpritePalette palette;
    struct SpriteTemplate *template;
    u8 spriteId;

    if (!AllocItemIconTemporaryBuffers())
    {
        return MAX_SPRITES;
    }
    LZDecompressWram(GetDecorationIconPicOrPalette(decor, 0), gUnknown_0203CEBC);
    CopyItemIconPicTo4x4Buffer(gUnknown_0203CEBC, gUnknown_0203CEC0);
    sheet.data = gUnknown_0203CEC0;
    sheet.size = 0x200;
    sheet.tag = tilesTag;
    LoadSpriteSheet(&sheet);
    palette.data = GetDecorationIconPicOrPalette(decor, 1);
    palette.tag = paletteTag;
    LoadCompressedObjectPalette(&palette);
    template = malloc(sizeof(struct SpriteTemplate));
    *template = gUnknown_08614FF4;
    template->tileTag = tilesTag;
    template->paletteTag = paletteTag;
    spriteId = CreateSprite(template, 0, 0, 0);
    FreeItemIconTemporaryBuffers();
    free(template);
    return spriteId;
}

const void *GetDecorationIconPicOrPalette(u16 decor, u8 mode)
{
    if (decor > 120)
    {
        decor = DECOR_NONE;
    }
    return gUnknown_085A6BE8[decor][mode];
}

u8 AddDecorationIconObjectFromFieldObject(u16 tilesTag, u16 paletteTag, u8 decor)
{
    u8 spriteId;
    struct SpriteSheet sheet;
    struct SpritePalette palette;
    struct SpriteTemplate *template;

    sub_8129048(&gUnknown_0203A190);
    gUnknown_0203A190.decoration = &gDecorations[decor];
    if (gUnknown_0203A190.decoration->permission != DECORPERM_SOLID_MAT)
    {
        sub_81291E8(&gUnknown_0203A190);
        sub_812925C(gUnknown_0203A190.decoration->shape);
        sub_81291A4(&gUnknown_0203A190);
        sub_8129068(gUnknown_0203A190.palette, ((u16 *)gTilesetPointer_SecretBaseRedCave->metatiles)[(gUnknown_0203A190.decoration->tiles[0] * 8) + 7] >> 12);
        sheet.data = gUnknown_0203A190.image;
        sheet.size = gUnknown_085A72F4[gUnknown_0203A190.decoration->shape] << 5;
        sheet.tag = tilesTag;
        LoadSpriteSheet(&sheet);
        palette.data = gUnknown_0203A190.palette;
        palette.tag = paletteTag;
        LoadSpritePalette(&palette);
        template = Alloc(sizeof(struct SpriteTemplate));
        *template = gUnknown_085A72A4;
        template->tileTag = tilesTag;
        template->paletteTag = paletteTag;
        spriteId = CreateSprite(template, 0, 0, 0);
        free(template);
    }
    else
    {
        spriteId = AddPseudoFieldObject(gUnknown_0203A190.decoration->tiles[0], SpriteCallbackDummy, 0, 0, 1);
    }
    return spriteId;
}

u8 AddDecorationIconObject(u8 decor, s16 x, s16 y, u8 priority, u16 tilesTag, u16 paletteTag)
{
    u8 spriteId;

    if (decor > 120)
    {
        spriteId = AddDecorationIconObjectFromIconTable(tilesTag, paletteTag, DECOR_NONE);
        if (spriteId == MAX_SPRITES)
        {
            return MAX_SPRITES;
        }
        gSprites[spriteId].pos2.x = x + 4;
        gSprites[spriteId].pos2.y = y + 4;
    }
    else if (gUnknown_085A6BE8[decor][0] == NULL)
    {
        spriteId = AddDecorationIconObjectFromFieldObject(tilesTag, paletteTag, decor);
        if (spriteId == MAX_SPRITES)
        {
            return MAX_SPRITES;
        }
        gSprites[spriteId].pos2.x = x;
        if (decor == DECOR_SILVER_SHIELD || decor == DECOR_GOLD_SHIELD)
        {
            gSprites[spriteId].pos2.y = y - 4;
        }
        else
        {
            gSprites[spriteId].pos2.y = y;
        }
    }
    else
    {
        spriteId = AddDecorationIconObjectFromIconTable(tilesTag, paletteTag, decor);
        if (spriteId == MAX_SPRITES)
        {
            return MAX_SPRITES;
        }
        gSprites[spriteId].pos2.x = x + 4;
        gSprites[spriteId].pos2.y = y + 4;
    }
    gSprites[spriteId].oam.priority = priority;
    return spriteId;
}

void sub_81296EC(u8 idx)
{
    gUnknown_0203A17C.items[idx] = 0;
    gUnknown_0203A17C.pos[idx] = 0;
}

void sub_8129708(void)
{
    u16 i;

    gSpecialVar_0x8005 = 0;
    gScriptResult = 0;
    if (gSpecialVar_0x8004 == gUnknown_0203AAC4)
    {
        gScriptResult = 1;
    }
    else if (gDecorations[gUnknown_0203A17C.items[gUnknown_0203AA44[gSpecialVar_0x8004].idx]].permission == DECORPERM_SOLID_MAT)
    {
        gSpecialVar_0x8005 = gUnknown_0203AA44[gSpecialVar_0x8004].flagId;
        sub_81296EC(gUnknown_0203AA44[gSpecialVar_0x8004].idx);
        for (i = 0; i < gMapHeader.events->mapObjectCount; i ++)
        {
            if (gMapHeader.events->mapObjects[i].flagId == gSpecialVar_0x8005)
            {
                gSpecialVar_0x8006 = gMapHeader.events->mapObjects[i].localId;
                break;
            }
        }
    }
}

void sub_81297AC(void)
{
    u8 i;

    for (i = 0; i < gMapHeader.events->mapObjectCount; i ++)
    {
        if (gMapHeader.events->mapObjects[i].flagId == gSpecialVar_0x8004)
        {
            gSpecialVar_0x8005 = gMapHeader.events->mapObjects[i].localId;
            break;
        }
    }
}

void sub_81297F8(void)
{
    u8 i;
    u8 y;
    u8 x;
    int posX;
    int posY;
    u8 perm;

    for (i = 0; i < gUnknown_0203AAC4; i ++)
    {
        perm = gDecorations[gUnknown_0203A17C.items[gUnknown_0203AA44[i].idx]].permission;
        posX = gUnknown_0203A17C.pos[gUnknown_0203AA44[i].idx] >> 4;
        posY = gUnknown_0203A17C.pos[gUnknown_0203AA44[i].idx] & 0x0F;
        if (perm != DECORPERM_SOLID_MAT)
        {
            for (y = 0; y < gUnknown_0203AA44[i].height; y ++)
            {
                for (x = 0; x < gUnknown_0203AA44[i].width; x ++)
                {
                    MapGridSetMetatileEntryAt(posX + 7 + x, posY + 7 - y, gMapHeader.mapData->map[posX + x + gMapHeader.mapData->width * (posY - y)] | 0x3000);
                }
            }
            sub_81296EC(gUnknown_0203AA44[i].idx);
        }
    }
}

void sub_81298EC(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            sub_81297F8();
            gTasks[taskId].data[2] = 1;
            break;
        case 1:
            if (!gPaletteFade.active) {
                DrawWholeMapView();
                ScriptContext1_SetupScript(gUnknown_08275D2E);
                sub_8197434(0, 1);
                gTasks[taskId].data[2] = 2;
            }
            break;
        case 2:
            ScriptContext2_Enable();
            sub_8127814(taskId);
            pal_fill_black();
            gTasks[taskId].data[2] = 3;
            break;
        case 3:
            if (sub_80ABDFC() == TRUE)
            {
                StringExpandPlaceholders(gStringVar4, gText_DecorationReturnedToPC);
                DisplayItemMessageOnField(taskId, gStringVar4, sub_8129D64);
                if (gMapHeader.regionMapSectionId == REGION_MAP_SECRET_BASE)
                {
                    TV_PutSecretBaseVisitOnTheAir();
                }
            }
            break;
    }
}


bool8 sub_81299AC(u8 taskId)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] != DECOR_NONE)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void SetUpPuttingAwayDecorationPlayerAvatar(void)
{
    player_get_direction_lower_nybble();
    gUnknown_0203AA38 = gSprites[gUnknown_03005DD0.unk4].data0;
    sub_812A39C();
    gUnknown_03005DD0.unk4 = CreateSprite(&gUnknown_085A7404, 0x78, 0x50, 0);
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        gUnknown_0203AA39 = AddPseudoFieldObject(0xC1, SpriteCallbackDummy, 0x88, 0x48, 0);
    }
    else
    {
        gUnknown_0203AA39 = AddPseudoFieldObject(0xC2, SpriteCallbackDummy, 0x88, 0x48, 0);
    }
    gSprites[gUnknown_0203AA39].oam.priority = 1;
    DestroySprite(&gSprites[gUnknown_0203AA38]);
    gUnknown_0203AA38 = gUnknown_03005DD0.unk4;
    gSprites[gUnknown_0203AA38].oam.priority = 1;
}

void sub_8129ABC(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_8127ACC(taskId);
                data[2] = 1;
                data[6] = 1;
                data[5] = 1;
            }
            break;
        case 1:
            SetUpPuttingAwayDecorationPlayerAvatar();
            pal_fill_black();
            data[2] = 2;
            break;
        case 2:
            if (sub_80ABDFC() == TRUE)
            {
                data[12] = 1;
                sub_8129B34(taskId);
            }
            break;
    }
}

void sub_8129B34(u8 taskId)
{
    sub_8197434(0, 1);
    gSprites[gUnknown_0203AA38].data7 = 0;
    gSprites[gUnknown_0203AA38].invisible = FALSE;
    gSprites[gUnknown_0203AA38].callback = sub_812A36C;
    gSprites[gUnknown_0203AA39].pos1.x = 0x88;
    gSprites[gUnknown_0203AA39].pos1.y = 0x48;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8128E18;
}

void sub_8129BCC(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_8128DE0();
    sub_8129C74(taskId);
}

void sub_8129BF8(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_8128DE0();
    gSprites[gUnknown_0203AA38].invisible = FALSE;
    gSprites[gUnknown_0203AA38].callback = SpriteCallbackDummy;
    StringExpandPlaceholders(gStringVar4, gText_StopPuttingAwayDecorations);
    DisplayItemMessageOnField(taskId, gStringVar4, sub_812A1F0);
}

void sub_8129C74(u8 taskId)
{
    s16 *data;
    u8 behavior;

    sub_812A0E8(taskId);
    if (gUnknown_0203AAC4 != 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_ReturnDecorationToPC);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_812A1A0);
    }
    else
    {
        data = gTasks[taskId].data;
        behavior = MapGridGetMetatileBehaviorAt(data[0], data[1]);
        if (MetatileBehavior_IsSecretBasePC(behavior) == TRUE || MetatileBehavior_IsMB_C5(behavior) == TRUE)
        {
            gSprites[gUnknown_0203AA38].invisible = FALSE;
            gSprites[gUnknown_0203AA38].callback = SpriteCallbackDummy;
            StringExpandPlaceholders(gStringVar4, gText_StopPuttingAwayDecorations);
            DisplayItemMessageOnField(taskId, gStringVar4, sub_812A1F0);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_NoDecorationHere);
            DisplayItemMessageOnField(taskId, gStringVar4, sub_8129D64);
        }
    }
}
