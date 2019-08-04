#include "global.h"
#include "alloc.h"
#include "battle_main.h"
#include "contest_effect.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "menu.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_specialized.h"
#include "move_relearner.h"
#include "palette.h"
#include "player_pc.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "gba/io_reg.h"

extern const struct CompressedSpriteSheet gMonFrontPicTable[];

EWRAM_DATA static u8 sUnknown_0203CF48[3] = {0};
EWRAM_DATA static struct ListMenuItem *sUnknown_0203CF4C = NULL;

static void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void sub_81D24A4(struct UnknownStruct_81D1ED4 *a0);
static void sub_81D2634(struct UnknownStruct_81D1ED4 *a0);
static void MoveRelearnerCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void nullsub_79(void);
static void sub_81D3408(struct Sprite *sprite);
static void sub_81D3564(struct Sprite *sprite);
static void sub_81D35E8(struct Sprite *sprite);

static const struct WindowTemplate sUnknown_086253E8[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x8
    },
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 1,
        .width = 8,
        .height = 18,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 11,
        .height = 8,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    }
};

static const u8 sUnknown_08625400[] =
{
    1, 2, 3
};

static const u8 sEmptyItemName[] = _("");

static const struct ScanlineEffectParams sUnknown_08625404 =
{
    .dmaDest = (void*)REG_ADDR_WIN0H,
    .dmaControl = SCANLINE_EFFECT_DMACNT_32BIT,
    .initState = 1,
};

static const u8 sUnknown_08625410[] =
{
    4,
    5,
    6,
    7,
    8,
    9, 9,
    10, 10,
    0xB, 0xB,
    0xC, 0xC,
    0xD, 0xD,
    0xD, 0xD,
    0xE, 0xE, 0xE, 0xE,
    0xF, 0xF, 0xF, 0xF,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
    0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15,
    0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A,
    0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
    0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
    0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D,
    0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x23
};


static const struct WindowTemplate sMoveRelearnerWindowTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 16,
        .height = 12,
        .paletteNum = 0xF,
        .baseBlock = 0xA
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 16,
        .height = 12,
        .paletteNum = 0xF,
        .baseBlock = 0xCA
    },
    {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 1,
        .width = 10,
        .height = 12,
        .paletteNum = 0xF,
        .baseBlock = 0x18A
    },
    {
        .bg = 1,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x202
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 8,
        .width = 5,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 0x25A
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sMoveRelearnerYesNoMenuTemplate =
{
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 8,
    .width = 5,
    .height = 4,
    .paletteNum = 0xF,
    .baseBlock = 0x25A
};


static const struct ListMenuTemplate sMoveRelearnerMovesListTemplate =
{
    .items = NULL,
    .moveCursorFunc = MoveRelearnerCursorCallback,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 2,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

bool8 sub_81D1C44(u8 count)
{
    u8 i;

    sUnknown_0203CF4C = Alloc(count * sizeof(*sUnknown_0203CF4C) + sizeof(*sUnknown_0203CF4C));
    if (sUnknown_0203CF4C == NULL)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sUnknown_0203CF48); i++)
        sUnknown_0203CF48[i] = 0xFF;

    return TRUE;
}

u8 sub_81D1C84(u8 a0)
{
    if (sUnknown_0203CF48[a0] == 0xFF)
    {
        if (a0 == 2)
        {
            struct WindowTemplate template = sUnknown_086253E8[2];
            template.width = GetMaxWidthInMenuTable(&gMailboxMailOptions[0], 4);
            sUnknown_0203CF48[2] = AddWindow(&template);
        }
        else
        {
            sUnknown_0203CF48[a0] = AddWindow(&sUnknown_086253E8[a0]);
        }
        SetStandardWindowBorderStyle(sUnknown_0203CF48[a0], 0);
    }
    return sUnknown_0203CF48[a0];
}

void sub_81D1D04(u8 a0)
{
    ClearStdWindowAndFrameToTransparent(sUnknown_0203CF48[a0], 0);
    ClearWindowTilemap(sUnknown_0203CF48[a0]);
    RemoveWindow(sUnknown_0203CF48[a0]);
    sUnknown_0203CF48[a0] = 0xFF;
}

static u8 sub_81D1D34(u8 a0)
{
    return sUnknown_0203CF48[a0];
}

static void sub_81D1D44(u8 windowId, s32 itemId, u8 y)
{
    u8 buffer[30];
    u16 length;

    if (itemId == LIST_CANCEL)
        return;

    StringCopy(buffer, gSaveBlock1Ptr->mail[6 + itemId].playerName);
    sub_81DB52C(buffer);
    length = StringLength(buffer);
    if (length <= 5)
        ConvertInternationalString(buffer, LANGUAGE_JAPANESE);
    AddTextPrinterParameterized4(windowId, 1, 8, y, 0, 0, sUnknown_08625400, -1, buffer);
}

u8 sub_81D1DC0(struct PlayerPCItemPageStruct *page)
{
    u16 i;
    for (i = 0; i < page->count; i++)
    {
        sUnknown_0203CF4C[i].name = sEmptyItemName;
        sUnknown_0203CF4C[i].id = i;
    }

    sUnknown_0203CF4C[i].name = gText_Cancel2;
    sUnknown_0203CF4C[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate.items = sUnknown_0203CF4C;
    gMultiuseListMenuTemplate.totalItems = page->count + 1;
    gMultiuseListMenuTemplate.windowId = sUnknown_0203CF48[1];
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.maxShowed = 8;
    gMultiuseListMenuTemplate.upText_Y = 9;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 1;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = sub_81D1E7C;
    gMultiuseListMenuTemplate.itemPrintFunc = sub_81D1D44;
    gMultiuseListMenuTemplate.fontId = 1;
    gMultiuseListMenuTemplate.cursorKind = 0;
    gMultiuseListMenuTemplate.lettersSpacing = 0;
    gMultiuseListMenuTemplate.itemVerticalPadding = 0;
    gMultiuseListMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    return ListMenuInit(&gMultiuseListMenuTemplate, page->itemsAbove, page->cursorPos);
}

static void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
}

void sub_81D1E90(struct PlayerPCItemPageStruct *page)
{
    page->scrollIndicatorId = AddScrollIndicatorArrowPairParameterized(2, 0xC8, 12, 0x94, page->count - page->pageItems + 1, 0x6E, 0x6E, &page->itemsAbove);
}

void sub_81D1EC0(void)
{
    Free(sUnknown_0203CF4C);
}

void sub_81D1ED4(struct UnknownStruct_81D1ED4 *a0)
{
    u8 i, j;

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 10; i++)
        {
            a0->unk64[i][j].unk0 = 0;
            a0->unk64[i][j].unk2 = 0;
        }
        for (i = 0; i < 4; i++)
        {
            a0->unk0[i][j] = 0;
            a0->unk14[i][j].unk0 = 0x9B;
            a0->unk14[i][j].unk2 = 0x5B;
        }

        a0->unk12C[j].unk0 = 0;
        a0->unk12C[j].unk2 = 0;
    }

    a0->unk354 = 0;
    a0->unk352 = 0;
}

void sub_81D1F84(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 *arg1, struct UnknownSubStruct_81D1ED4 *arg2)
{
    u16 i, j;
    s32 r5, r6;

    for (i = 0; i < 5; i++)
    {
        r5 = arg1[i].unk0 << 8;
        r6 = ((arg2[i].unk0 - arg1[i].unk0) << 8) / 10;
        for (j = 0; j < 9; j++)
        {
            arg0->unk64[j][i].unk0 = (r5 >> 8) + ((r5 >> 7) & 1);
            r5 += r6;
        }
        arg0->unk64[j][i].unk0 = arg2[i].unk0;

        r5 = arg1[i].unk2 << 8;
        r6 = ((arg2[i].unk2 - arg1[i].unk2) << 8) / 10;
        for (j = 0; j < 9; j++)
        {
            arg0->unk64[j][i].unk2 = (r5 >> 8) + ((r5 >> 7) & 1);
            r5 += r6;
        }
        arg0->unk64[j][i].unk2 = arg2[i].unk2;
    }

    arg0->unk352 = 0;
}

bool32 sub_81D2074(struct UnknownStruct_81D1ED4 *a0)
{
    if (a0->unk352 < 10)
    {
        sub_81D2230(a0);
        return (++a0->unk352 != 10);
    }
    else
    {
        return FALSE;
    }
}

void sub_81D20AC(struct UnknownStruct_81D1ED4 *a0)
{
    a0->unk355 = 0;
}

bool8 sub_81D20BC(struct UnknownStruct_81D1ED4 *arg0)
{
    struct ScanlineEffectParams params;

    switch (arg0->unk355)
    {
    case 0:
        ScanlineEffect_Clear();
        arg0->unk355++;
        return TRUE;
    case 1:
        params = sUnknown_08625404;
        ScanlineEffect_SetParams(params);
        arg0->unk355++;
        return FALSE;
    default:
        return FALSE;
    }
}

void sub_81D2108(struct UnknownStruct_81D1ED4 *arg0)
{
    u16 i;

    if (arg0->unk354 == 0)
        return;

    sub_81D24A4(arg0);
    sub_81D2634(arg0);

    for (i = 0; i < 66; i++)
    {
        gScanlineEffectRegBuffers[1][(i + 55) * 2]     = gScanlineEffectRegBuffers[0][(i + 55) * 2]     = (arg0->unk140[i][0] << 8) | (arg0->unk140[i][1]);
        gScanlineEffectRegBuffers[1][(i + 55) * 2 + 1] = gScanlineEffectRegBuffers[0][(i + 55) * 2 + 1] = (arg0->unk248[i][0] << 8) | (arg0->unk248[i][1]);
    }

    arg0->unk354 = 0;
}

void sub_81D21DC(u8 bg)
{
    u32 flags;

    if (bg > 3)
        bg = 0;

    // Unset the WINOUT flag for the bg.
    flags = (WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ) & ~(1 << bg);

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 0xF0));
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE(0, 0x9B));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0x38, 0x79));
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(0x38, 0x79));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, flags);
}

void sub_81D2230(struct UnknownStruct_81D1ED4 *arg0)
{
    u16 i;
    for (i = 0; i < 5; i++)
        arg0->unk12C[i] = arg0->unk64[arg0->unk352][i];

    arg0->unk354 = 1;
}

static void sub_81D2278(struct UnknownStruct_81D1ED4 *arg0, u16 *arg1, struct UnknownSubStruct_81D1ED4 *arg2, struct UnknownSubStruct_81D1ED4 *arg3, u8 arg4, u16 *arg5)
{
    u16 i, r8, r10, r0, var_30;
    u16 *ptr;
    s32 r4, var_2C;

    var_2C = 0;
    if (arg2->unk2 < arg3->unk2)
    {
        r10 = arg2->unk2;
        r0 = arg3->unk2;
        r4 = arg2->unk0 << 10;
        var_30 = arg3->unk0;
        r8 = r0 - r10;
        if (r8 != 0)
            var_2C = ((var_30 - arg2->unk0) << 10) / r8;
    }
    else
    {
        r0 = arg2->unk2;
        r10 = arg3->unk2;
        r4 = arg3->unk0 << 10;
        var_30 = arg2->unk0;
        r8 = r0 - r10;
        if (r8 != 0)
            var_2C = ((var_30 - arg3->unk0) << 10) / r8;
    }

    r8++;
    if (arg5 == NULL)
    {
        arg1 += (r10 - 56) * 2;
        for (i = 0; i < r8; i++)
        {
            arg1[arg4] = (r4 >> 10) + ((r4 >> 9) & 1) + arg4;
            r4 += var_2C;
            arg1 += 2;
        }

        ptr = arg1 - 2;
    }
    else if (var_2C > 0)
    {
        arg5 += (r10 - 56) * 2;
        // Less readable than the other loops, but it has to be written this way to match.
        for (i = 0; i < r8; arg5[arg4] = (r4 >> 10) + ((r4 >> 9) & 1) + arg4, r4 += var_2C, arg5 += 2, i++)
        {
            if (r4 >= (155 << 10))
                break;
        }

        arg0->unk350 = r10 + i;
        arg1 += (arg0->unk350 - 56) * 2;
        for (; i < r8; i++)
        {
            arg1[arg4] = (r4 >> 10) + ((r4 >> 9) & 1) + arg4;
            r4 += var_2C;
            arg1 += 2;
        }

        ptr = arg1 - 2;
    }
    else if (var_2C < 0)
    {
        arg1 += (r10 - 56) * 2;
        for (i = 0; i < r8; i++)
        {
            arg1[arg4] = (r4 >> 10) + ((r4 >> 9) & 1) + arg4;
            if (r4 < (155 << 10))
            {
                arg1[arg4] = 155;
                break;
            }
            r4 += var_2C;
            arg1 += 2;
        }

        arg0->unk350 = r10 + i;
        arg5 += (arg0->unk350 - 56) * 2;
        for (; i < r8; i++)
        {
            arg5[arg4] = (r4 >> 10) + ((r4 >> 9) & 1) + arg4;
            r4 += var_2C;
            arg5 += 2;
        }

        ptr = arg5 - 2;
    }
    else
    {
        arg0->unk350 = r10;
        arg1 += (r10 - 56) * 2;
        arg5 += (r10 - 56) * 2;
        arg1[1] = arg2->unk0 + 1;
        arg5[0] = arg3->unk0;
        arg5[1] = 155;
        return;
    }

    ptr[arg4] = arg4 + var_30;
}

static void sub_81D24A4(struct UnknownStruct_81D1ED4 *arg0)
{
    u16 i, r6, varMax;

    if (arg0->unk12C[0].unk2 < arg0->unk12C[1].unk2)
    {
        r6 = arg0->unk12C[0].unk2;
        sub_81D2278(arg0, arg0->unk140[0], &arg0->unk12C[0], &arg0->unk12C[1], 1, NULL);
    }
    else
    {
        r6 = arg0->unk12C[1].unk2;
        sub_81D2278(arg0, arg0->unk140[0], &arg0->unk12C[1], &arg0->unk12C[0], 0, NULL);
    }

    sub_81D2278(arg0, arg0->unk140[0], &arg0->unk12C[1], &arg0->unk12C[2], 1, NULL);

    i = (arg0->unk12C[2].unk2 <= arg0->unk12C[3].unk2);
    sub_81D2278(arg0, arg0->unk140[0], &arg0->unk12C[2], &arg0->unk12C[3], i, arg0->unk248[0]);
    for (i = 56; i < r6; i++)
    {
        arg0->unk140[i - 56][0] = 0;
        arg0->unk140[i - 56][1] = 0;
    }

    for (i = arg0->unk12C[0].unk2; i <= arg0->unk350; i++)
        arg0->unk140[i - 56][0] = 155;

    varMax = max(arg0->unk350, arg0->unk12C[2].unk2);
    for (i = varMax + 1; i < 122; i++)
    {
        arg0->unk140[i - 56][0] = 0;
        arg0->unk140[i - 56][1] = 0;
    }

    for (i = 56; i < 122; i++)
    {
        if (arg0->unk140[i - 56][0] == 0 && arg0->unk140[i - 56][1] != 0)
            arg0->unk140[i - 56][0] = 155;
    }
}

static void sub_81D2634(struct UnknownStruct_81D1ED4 *arg0)
{
    s32 i, r6, varMax;

    if (arg0->unk12C[0].unk2 < arg0->unk12C[4].unk2)
    {
        r6 = arg0->unk12C[0].unk2;
        sub_81D2278(arg0, arg0->unk248[0], &arg0->unk12C[0], &arg0->unk12C[4], 0, NULL);
    }
    else
    {
        r6 = arg0->unk12C[4].unk2;
        sub_81D2278(arg0, arg0->unk248[0], &arg0->unk12C[4], &arg0->unk12C[0], 1, NULL);
    }

    sub_81D2278(arg0, arg0->unk248[0], &arg0->unk12C[4], &arg0->unk12C[3], 0, NULL);

    for (i = 56; i < r6; i++)
    {
        arg0->unk140[i + 10][0] = 0;
        arg0->unk140[i + 10][1] = 0;
    }

    for (i = arg0->unk12C[0].unk2; i <= arg0->unk350; i++)
        arg0->unk140[i + 10][1] = 155;

    varMax = max(arg0->unk350, arg0->unk12C[3].unk2 + 1);
    for (i = varMax; i < 122; i++)
    {
        arg0->unk140[i + 10][0] = 0;
        arg0->unk140[i + 10][1] = 0;
    }

    for (i = 0; i < 66; i++)
    {
        if (arg0->unk248[i][0] >= arg0->unk248[i][1])
        {
            arg0->unk248[i][1] = 0;
            arg0->unk248[i][0] = 0;
        }
    }
}

void sub_81D2754(u8 *arg0, struct UnknownSubStruct_81D1ED4 *arg1)
{
    u8 r2, r7;
    s8 r12;
    u16 i;

    r2 = sUnknown_08625410[*(arg0++)];
    arg1->unk0 = 155;
    arg1->unk2 = 91 - r2;

    r7 = 64;
    r12 = 0;
    for (i = 1; i < 5; i++)
    {
        r7 += 51;
        if (--r12 < 0)
            r12 = 4;

        if (r12 == 2)
            r7++;

        r2 = sUnknown_08625410[*(arg0++)];
        arg1[r12].unk0 = 155 + ((r2 * gSineTable[64 + r7]) >> 8);
        arg1[r12].unk2 = 91  - ((r2 * gSineTable[r7]) >> 8);

        if (r12 < 3 && (r2 != 32 || r12 != 2))
            arg1[r12].unk0 = 156 + ((r2 * gSineTable[64 + r7]) >> 8);
    }
}

void InitMoveRelearnerWindows(bool8 useContextWindow)
{
    u8 i;

    InitWindows(sMoveRelearnerWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, 0xE0);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);

    for (i = 0; i < 5; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(1));
    }

    if (!useContextWindow)
    {
        PutWindowTilemap(0);
        DrawStdFrameWithCustomTileAndPalette(0, 0, 0x1, 0xE);
    }
    else
    {
        PutWindowTilemap(1);
        DrawStdFrameWithCustomTileAndPalette(1, 0, 1, 0xE);
    }
    PutWindowTilemap(2);
    PutWindowTilemap(3);
    DrawStdFrameWithCustomTileAndPalette(2, 0, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(3, 0, 1, 0xE);
    nullsub_79();
    schedule_bg_copy_tilemap_to_vram(1);
}

static void nullsub_79(void)
{

}

u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices)
{
    gMultiuseListMenuTemplate = sMoveRelearnerMovesListTemplate;
    gMultiuseListMenuTemplate.totalItems = numChoices;
    gMultiuseListMenuTemplate.items = items;

    if (numChoices < 6)
    {
        gMultiuseListMenuTemplate.maxShowed = numChoices;
    }
    else
    {
        gMultiuseListMenuTemplate.maxShowed = 6;
    }
    return gMultiuseListMenuTemplate.maxShowed;
}

static void MoveRelearnerLoadBattleMoveDescription(u32 chosenMove)
{
    s32 x;
    const struct BattleMove *move;
    u8 buffer[0x20];
    const u8 *str;

    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    str = gText_MoveRelearnerBattleMoves;
    x = GetStringCenterAlignXOffset(1, str, 0x80);
    AddTextPrinterParameterized(0, 1, str, x, 1, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerPP;
    AddTextPrinterParameterized(0, 1, str, 4, 0x29, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerPower;
    x = GetStringRightAlignXOffset(1, str, 0x6A);
    AddTextPrinterParameterized(0, 1, str, x, 0x19, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerAccuracy;
    x = GetStringRightAlignXOffset(1, str, 0x6A);
    AddTextPrinterParameterized(0, 1, str, x, 0x29, TEXT_SPEED_FF, NULL);
    if (chosenMove == LIST_CANCEL)
    {
        CopyWindowToVram(0, 2);
        return;
    }
    move = &gBattleMoves[chosenMove];
    str = gTypeNames[move->type];
    AddTextPrinterParameterized(0, 1, str, 4, 0x19, TEXT_SPEED_FF, NULL);

    x = 4 + GetStringWidth(1, gText_MoveRelearnerPP, 0);
    ConvertIntToDecimalStringN(buffer, move->pp, 0, 2);
    AddTextPrinterParameterized(0, 1, buffer, x, 0x29, TEXT_SPEED_FF, NULL);

    if (move->power < 2)
    {
        str = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->power, 0, 3);
        str = buffer;
    }
    AddTextPrinterParameterized(0, 1, str, 0x6A, 0x19, TEXT_SPEED_FF, NULL);

    if (move->accuracy == 0)
    {
        str = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->accuracy, 0, 3);
        str = buffer;
    }
    AddTextPrinterParameterized(0, 1, str, 0x6A, 0x29, TEXT_SPEED_FF, NULL);

    str = gMoveDescriptionPointers[chosenMove - 1];
    AddTextPrinterParameterized(0, 7, str, 0, 0x41, 0, NULL);
}

static void MoveRelearnerMenuLoadContestMoveDescription(u32 chosenMove)
{
    s32 x;
    const u8 *str;
    const struct ContestMove *move;

    MoveRelearnerShowHideHearts(chosenMove);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    str = gText_MoveRelearnerContestMovesTitle;
    x = GetStringCenterAlignXOffset(1, str, 0x80);
    AddTextPrinterParameterized(1, 1, str, x, 1, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerAppeal;
    x = GetStringRightAlignXOffset(1, str, 0x5C);
    AddTextPrinterParameterized(1, 1, str, x, 0x19, TEXT_SPEED_FF, NULL);

    str = gText_MoveRelearnerJam;
    x = GetStringRightAlignXOffset(1, str, 0x5C);
    AddTextPrinterParameterized(1, 1, str, x, 0x29, TEXT_SPEED_FF, NULL);

    if (chosenMove == MENU_NOTHING_CHOSEN)
    {
        CopyWindowToVram(1, 2);
        return;
    }

    move = &gContestMoves[chosenMove];
    str = gContestMoveTypeTextPointers[move->contestCategory];
    AddTextPrinterParameterized(1, 1, str, 4, 0x19, TEXT_SPEED_FF, NULL);

    str = gContestEffectDescriptionPointers[move->effect];
    AddTextPrinterParameterized(1, 7, str, 0, 0x41, TEXT_SPEED_FF, NULL);

    CopyWindowToVram(1, 2);
}

static void MoveRelearnerCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
    MoveRelearnerLoadBattleMoveDescription(itemIndex);
    MoveRelearnerMenuLoadContestMoveDescription(itemIndex);
}

void MoveRelearnerPrintText(u8 *str)
{
    u8 speed;

    FillWindowPixelBuffer(3, PIXEL_FILL(1));
    gTextFlags.canABSpeedUpPrint = TRUE;
    speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized2(3, 1, str, speed, NULL, TEXT_COLOR_DARK_GREY, TEXT_COLOR_WHITE, 3);
}

bool16 MoveRelearnerRunTextPrinters(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(3);
}

void MoveRelearnerCreateYesNoMenu(void)
{
    CreateYesNoMenu(&sMoveRelearnerYesNoMenuTemplate, 1, 0xE, 0);
}

s32 GetBoxOrPartyMonData(u16 boxId, u16 monId, s32 request, u8 *dst)
{
    s32 ret;

    if (boxId == TOTAL_BOXES_COUNT) // Party mon.
    {
        if (request == MON_DATA_NICKNAME || request == MON_DATA_OT_NAME)
            ret = GetMonData(&gPlayerParty[monId], request, dst);
        else
            ret = GetMonData(&gPlayerParty[monId], request);
    }
    else
    {
        if (request == MON_DATA_NICKNAME || request == MON_DATA_OT_NAME)
            ret = GetAndCopyBoxMonDataAt(boxId, monId, request, dst);
        else
            ret = GetBoxMonDataAt(boxId, monId, request);
    }

    return ret;
}

static u8 *sub_81D2CD0(u8 *dst, u16 boxId, u16 monId)
{
    u16 species, level, gender;
    struct BoxPokemon *boxMon;
    u8 *str;

    *(dst++) = EXT_CTRL_CODE_BEGIN;
    *(dst++) = 4;
    *(dst++) = 8;
    *(dst++) = 0;
    *(dst++) = 9;
    if (GetBoxOrPartyMonData(boxId, monId, MON_DATA_IS_EGG, NULL))
    {
        return StringCopyPadded(dst, gText_EggNickname, 0, 12);
    }
    else
    {
        GetBoxOrPartyMonData(boxId, monId, MON_DATA_NICKNAME, dst);
        StringGetEnd10(dst);
        species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES, NULL);
        if (boxId == TOTAL_BOXES_COUNT) // Party mon.
        {
            level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
            gender = GetMonGender(&gPlayerParty[monId]);
        }
        else
        {
            // Needed to match, feel free to remove.
            boxId++;boxId--;
            monId++;monId--;

            boxMon = GetBoxedMonPtr(boxId, monId);
            gender = GetBoxMonGender(boxMon);
            level = GetLevelFromBoxMonExp(boxMon);
        }

        if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && !StringCompare(dst, gSpeciesNames[species]))
            gender = MON_GENDERLESS;

        for (str = dst; *str != EOS; str++)
            ;

        *(str++) = EXT_CTRL_CODE_BEGIN;
        *(str++) = 0x12;
        *(str++) = 0x3C;

        switch (gender)
        {
        default:
            *(str++) = CHAR_SPACE;
            break;
        case MON_MALE:
            *(str++) = EXT_CTRL_CODE_BEGIN;
            *(str++) = EXT_CTRL_CODE_COLOR;
            *(str++) = 4;
            *(str++) = EXT_CTRL_CODE_BEGIN;
            *(str++) = 3;
            *(str++) = 5;
            *(str++) = CHAR_MALE;
            break;
        case MON_FEMALE:
            *(str++) = EXT_CTRL_CODE_BEGIN;
            *(str++) = EXT_CTRL_CODE_COLOR;
            *(str++) = 6;
            *(str++) = EXT_CTRL_CODE_BEGIN;
            *(str++) = 3;
            *(str++) = 7;
            *(str++) = CHAR_FEMALE;
            break;
        }

        *(str++) = EXT_CTRL_CODE_BEGIN;
        *(str++) = 4;
        *(str++) = 8;
        *(str++) = 0;
        *(str++) = 9;
        *(str++) = CHAR_SLASH;
        *(str++) = CHAR_SPECIAL_F9;
        *(str++) = 5;
        str = ConvertIntToDecimalStringN(str, level, STR_CONV_MODE_LEFT_ALIGN, 3);
        *(str++) = CHAR_SPACE;
        *str = EOS;

        return str;
    }
}

static u8 *sub_81D2E7C(u8 *dst, const u8 *src, s16 n)
{
    while (*src != EOS)
    {
        *(dst++) = *(src++);
        n--;
    }
    while (n-- > 0)
        *(dst++) = CHAR_SPACE;

    *dst = EOS;
    return dst;
}

void sub_81D2ED4(u8 *dst, u8 *nameDst, u16 boxId, u16 monId, u16 arg5, u16 arg6, bool8 arg7)
{
    u16 i;

    if (!arg7)
        arg6--;

    if (arg5 != arg6)
    {
        sub_81D2CD0(nameDst, boxId, monId);
        dst[0] = EXT_CTRL_CODE_BEGIN;
        dst[1] = 4;
        dst[2] = 8;
        dst[3] = 0;
        dst[4] = 9;
        if (boxId == TOTAL_BOXES_COUNT) // Party mon.
        {
            sub_81D2E7C(dst + 5, gText_InParty, 8);
        }
        else
        {
            boxId++;boxId--; // Again...Someone fix this maybe?
            sub_81D2E7C(dst + 5, GetBoxNamePtr(boxId), 8);
        }
    }
    else
    {
        for (i = 0; i < 12; i++)
            nameDst[i] = CHAR_SPACE;
        nameDst[i] = EOS;
        for (i = 0; i < 8; i++)
            dst[i] = CHAR_SPACE;
        dst[i] = EOS;
    }
}

void sub_81D2F78(struct UnknownStruct_81D1ED4 *arg0, u8 *sheen, u16 boxId, u16 monId, u16 arg5, u16 id, u16 arg7, bool8 arg8)
{
    u16 i;

    if (!arg8)
        arg7--;

    if (arg5 != arg7)
    {
        arg0->unk0[id][0] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        arg0->unk0[id][1] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        arg0->unk0[id][2] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        arg0->unk0[id][3] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        arg0->unk0[id][4] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);

        sheen[id] = (GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL) != 0xFF)
                 ? GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL) / 29u
                 : 9;

        sub_81D2754(arg0->unk0[id], arg0->unk14[id]);
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            arg0->unk0[id][i] = 0;
            arg0->unk14[id][i].unk0 = 155;
            arg0->unk14[id][i].unk2 = 91;
        }
    }
}

void sub_81D3094(void *tilesDst, void *palDst, u16 boxId, u16 monId, u16 arg5, u16 arg6, bool8 arg7)
{
    if (!arg7)
        arg6--;

    if (arg5 != arg6)
    {
        u16 species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES2, NULL);
        u32 trainerId = GetBoxOrPartyMonData(boxId, monId, MON_DATA_OT_ID, NULL);
        u32 personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);

        LoadSpecialPokePic(&gMonFrontPicTable[species], tilesDst, species, personality, TRUE);
        LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, trainerId, personality), palDst);
    }
}

bool8 sub_81D312C(s16 *var)
{
    *var += 24;
    if (*var > 0)
        *var = 0;

    return (*var != 0);
}

bool8 sub_81D3150(s16 *var)
{
    *var -= 24;
    if (*var < -80)
        *var = -80;

    return (*var != -80);
}

bool8 sub_81D3178(struct UnknownStruct_81D1ED4 *arg0, s16 *arg1)
{
    bool8 var1 = sub_81D2074(arg0);
    bool8 var2 = sub_81D312C(arg1);

    return ((var1 != 0) || (var2 != 0));
}

bool8 sub_81D31A4(struct UnknownStruct_81D1ED4 *arg0, s16 *arg1)
{
    bool8 var1 = sub_81D2074(arg0);
    bool8 var2 = sub_81D3150(arg1);

    return ((var1 != 0) || (var2 != 0));
}

static const u32 gUnknown_08625560[] = INCBIN_U32("graphics/pokenav/pokeball.4bpp");
static const u32 gUnknown_08625660[] = INCBIN_U32("graphics/pokenav/pokeball_placeholder.4bpp");
static const u16 gUnknown_08625680[] = INCBIN_U16("graphics/pokenav/sparkle.gbapal");
static const u32 gUnknown_086256A0[] = INCBIN_U32("graphics/pokenav/sparkle.4bpp");

static const struct OamData sOamData_8625A20 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_8625A28 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_8625A30[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8625A38[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8625A40[] =
{
    sSpriteAnim_8625A30,
    sSpriteAnim_8625A38
};

void sub_81D31D0(struct SpriteSheet *sheet, struct SpriteTemplate *template, struct SpritePalette *pal)
{
    struct SpriteSheet dataSheet = {NULL, 0x800, 100};

    struct SpriteTemplate dataTemplate =
    {
        .tileTag = 100,
        .paletteTag = 100,
        .oam = &sOamData_8625A20,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    struct SpritePalette dataPal = {NULL, 100};

    *sheet = dataSheet;
    *template = dataTemplate;
    *pal = dataPal;
}

void sub_81D321C(struct SpriteSheet *sheets, struct SpriteTemplate * template, struct SpritePalette *pals)
{
    u8 i;

    struct SpriteSheet dataSheets[] =
    {
        {gUnknown_08625560, 0x100, 101},
        {gUnknown_08625660, 0x20, 103},
        {gPokenavConditionCancel_Gfx, 0x100, 102},
        {},
    };

    struct SpritePalette dataPals[] =
    {
        {gPokenavConditionCancel_Pal, 101},
        {gPokenavConditionCancel_Pal + 16, 102},
        {},
    };

    struct SpriteTemplate dataTemplate =
    {
        .tileTag = 101,
        .paletteTag = 101,
        .oam = &sOamData_8625A28,
        .anims = sSpriteAnimTable_8625A40,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    for (i = 0; i < ARRAY_COUNT(dataSheets); i++)
        *(sheets++) = dataSheets[i];

    *template = dataTemplate;

    for (i = 0; i < ARRAY_COUNT(dataPals); i++)
        *(pals++) = dataPals[i];
}

void sub_81D32B0(struct SpriteSheet *sheet, struct SpritePalette *pal)
{
    struct SpriteSheet dataSheet = {gUnknown_086256A0, 0x380, 104};
    struct SpritePalette dataPal = {gUnknown_08625680, 104};

    *sheet = dataSheet;
    *pal = dataPal;
}

static void sub_81D32D4(struct Sprite *sprite)
{
    if (++sprite->data[1] > 60)
    {
        sprite->data[1] = 0;
        sub_81D3408(sprite);
    }
}

static void sub_81D32F4(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->data[1] = 0;
        sprite->callback = sub_81D32D4;
    }
}

static const struct OamData sOamData_8625AD0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .priority = 0,
};

static const union AnimCmd sSpriteAnim_8625AD8[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(20, 5),
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8625AF8[] =
{
    sSpriteAnim_8625AD8,
    sSpriteAnim_8625AD8 + 2,
};

// unused
static const union AnimCmd *const sSpriteAnimTable_8625B00[] =
{
    sSpriteAnim_8625AD8 + 4,
    sSpriteAnim_8625AD8 + 6,
};

// unused
static const union AnimCmd *const sSpriteAnimTable_8625B08[] =
{
    sSpriteAnim_8625AD8 + 8,
    sSpriteAnim_8625AD8 + 10,
};

// unused
static const union AnimCmd *const *const sUnknown_08625B10 = sSpriteAnimTable_8625B08;

const struct SpriteTemplate gUnknown_08625B14 =
{
    .tileTag = 104,
    .paletteTag = 104,
    .oam = &sOamData_8625AD0,
    .anims = sSpriteAnimTable_8625AF8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81D3564,
};

static const s16 gUnknown_08625B2C[][2] =
{
    {0,   -35},
    {20,  -28},
    {33,  -10},
    {33,   10},
    {20,   28},
    {0,    35},
    {-20,  28},
    {-33,  10},
    {-33, -10},
    {-20, -28},
};

void sub_81D3314(struct Sprite *sprite)
{
    struct Sprite *sprite2 = &gSprites[sprite->data[4]];

    if (sprite2 != NULL)
    {
        sprite->pos1.x = sprite2->pos1.x + sprite2->pos2.x + gUnknown_08625B2C[sprite->data[0]][0];
        sprite->pos1.y = sprite2->pos1.y + sprite2->pos2.y + gUnknown_08625B2C[sprite->data[0]][1];
    }
    else
    {
        sprite->pos1.x = gUnknown_08625B2C[sprite->data[0]][0] + 40;
        sprite->pos1.y = gUnknown_08625B2C[sprite->data[0]][1] + 104;
    }
}

void sub_81D338C(u8 arg0, u8 arg1, struct Sprite **sprites)
{
    u16 i;

    for (i = 0; i < 10; i++)
    {
        if (sprites[i] != NULL)
        {
            sprites[i]->data[0] = i;
            sprites[i]->data[1] = (i * 16) + 1;
            sprites[i]->data[2] = arg0;
            sprites[i]->data[3] = i;
            if (arg1 == 0 || arg0 != 9)
            {
                sprites[i]->callback = sub_81D3564;
            }
            else
            {
                sub_81D3314(sprites[i]);
                sub_81D35E8(sprites[i]);
                sprites[i]->callback = sub_81D32F4;
                sprites[i]->invisible = FALSE;
            }
        }
    }
}

static void sub_81D3408(struct Sprite *sprite)
{
    u16 i;
    u8 id = sprite->data[5];

    for (i = 0; i < sprite->data[2] + 1; i++)
    {
        gSprites[id].data[1] = (gSprites[id].data[0] * 16) + 1;
        gSprites[id].callback = sub_81D3564;
        id = gSprites[id].data[5];
    }
}

void sub_81D3464(struct Sprite **sprites)
{
    u8 i;

    for (i = 0; i < 10; i++)
        sprites[i] = NULL;
}

void sub_81D3480(struct Sprite **sprites, u8 arg1, u8 arg2)
{
    u16 i, spriteId, firstSpriteId = 0;
    u8 count = arg2;

    for (i = 0; i < count + 1; i++)
    {
        spriteId = CreateSprite(&gUnknown_08625B14, 0, 0, 0);
        if (spriteId != MAX_SPRITES)
        {
            sprites[i] = &gSprites[spriteId];
            sprites[i]->invisible = TRUE;
            sprites[i]->data[4] = arg1;
            if (i != 0)
                sprites[i - 1]->data[5] = spriteId;
            else
                firstSpriteId = spriteId;
        }
        else
        {
            break;
        }
    }

    sprites[count]->data[5] = firstSpriteId;
    sub_81D338C(count, 1, sprites);
}

void sub_81D3520(struct Sprite **sprites)
{
    u16 i;

    for (i = 0; i < 10; i++)
    {
        if (sprites[i] != NULL)
        {
            DestroySprite(sprites[i]);
            sprites[i] = NULL;
        }
        else
        {
            break;
        }
    }
}

void sub_81D354C(struct Sprite **sprites)
{
    sub_81D3520(sprites);
    FreeSpriteTilesByTag(104);
    FreeSpritePaletteByTag(104);
}

static void sub_81D3564(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        if (--sprite->data[1] != 0)
            return;

        SeekSpriteAnim(sprite, 0);
        sprite->invisible = FALSE;
    }

    sub_81D3314(sprite);
    if (sprite->animEnded)
    {
        sprite->invisible = TRUE;
        if (sprite->data[3] == sprite->data[2])
        {
            if (sprite->data[3] == 9)
            {
                sub_81D35E8(sprite);
                sprite->callback = sub_81D32F4;
            }
            else
            {
                sprite->callback = sub_81D32D4;
            }
        }
        else
        {
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

static void sub_81D35E8(struct Sprite *sprite)
{
    u8 i, id = sprite->data[5];

    for (i = 0; i < sprite->data[2] + 1; i++)
    {
        SeekSpriteAnim(&gSprites[id], 0);
        gSprites[id].invisible = FALSE;
        id = gSprites[id].data[5];
    }
}

static const u8 *const sLvlUpStatStrings[] =
{
    gUnknown_085EEA46,
    gUnknown_085EEA4E,
    gUnknown_085EEA55,
    gUnknown_085EEA63,
    gUnknown_085EEA6B,
    gUnknown_085EEA5D
};

void DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr)
{
    u16 i, x;
    s16 statsDiff[NUM_STATS];
    u8 text[12];
    u8 color[3];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(bgClr));

    statsDiff[0] = statsAfter[STAT_HP]    - statsBefore[STAT_HP];
    statsDiff[1] = statsAfter[STAT_ATK]   - statsBefore[STAT_ATK];
    statsDiff[2] = statsAfter[STAT_DEF]   - statsBefore[STAT_DEF];
    statsDiff[3] = statsAfter[STAT_SPATK] - statsBefore[STAT_SPATK];
    statsDiff[4] = statsAfter[STAT_SPDEF] - statsBefore[STAT_SPDEF];
    statsDiff[5] = statsAfter[STAT_SPEED] - statsBefore[STAT_SPEED];

    color[0] = bgClr;
    color[1] = fgClr;
    color[2] = shadowClr;

    for (i = 0; i < NUM_STATS; i++)
    {

        AddTextPrinterParameterized3(windowId,
                                     1,
                                     0,
                                     15 * i,
                                     color,
                                     -1,
                                     sLvlUpStatStrings[i]);

        StringCopy(text, (statsDiff[i] >= 0) ? gText_UnkCtrlF904 : gText_Dash);
        AddTextPrinterParameterized3(windowId,
                                     1,
                                     56,
                                     15 * i,
                                     color,
                                     -1,
                                     text);
        if (abs(statsDiff[i]) <= 9)
            x = 18;
        else
            x = 12;

        ConvertIntToDecimalStringN(text, abs(statsDiff[i]), STR_CONV_MODE_LEFT_ALIGN, 2);
        AddTextPrinterParameterized3(windowId,
                                     1,
                                     56 + x,
                                     15 * i,
                                     color,
                                     -1,
                                     text);
    }
}

void DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr)
{
    u16 i, numDigits, x;
    s16 stats[NUM_STATS];
    u8 text[12];
    u8 color[3];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(bgClr));

    stats[0] = currStats[STAT_HP];
    stats[1] = currStats[STAT_ATK];
    stats[2] = currStats[STAT_DEF];
    stats[3] = currStats[STAT_SPATK];
    stats[4] = currStats[STAT_SPDEF];
    stats[5] = currStats[STAT_SPEED];

    color[0] = bgClr;
    color[1] = fgClr;
    color[2] = shadowClr;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (stats[i] > 99)
            numDigits = 3;
        else if (stats[i] > 9)
            numDigits = 2;
        else
            numDigits = 1;

        ConvertIntToDecimalStringN(text, stats[i], STR_CONV_MODE_LEFT_ALIGN, numDigits);
        x = 6 * (4 - numDigits);

        AddTextPrinterParameterized3(windowId,
                                     1,
                                     0,
                                     15 * i,
                                     color,
                                     -1,
                                     sLvlUpStatStrings[i]);

        AddTextPrinterParameterized3(windowId,
                                     1,
                                     56 + x,
                                     15 * i,
                                     color,
                                     -1,
                                     text);
    }
}

void GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats)
{
    currStats[STAT_HP]    = GetMonData(mon, MON_DATA_MAX_HP);
    currStats[STAT_ATK]   = GetMonData(mon, MON_DATA_ATK);
    currStats[STAT_DEF]   = GetMonData(mon, MON_DATA_DEF);
    currStats[STAT_SPEED] = GetMonData(mon, MON_DATA_SPEED);
    currStats[STAT_SPATK] = GetMonData(mon, MON_DATA_SPATK);
    currStats[STAT_SPDEF] = GetMonData(mon, MON_DATA_SPDEF);
}
