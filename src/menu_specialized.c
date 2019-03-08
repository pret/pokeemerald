#include "global.h"
#include "alloc.h"
#include "battle_main.h"
#include "contest_effect.h"
#include "gpu_regs.h"
#include "menu.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_specialized.h"
#include "move_relearner.h"
#include "palette.h"
#include "player_pc.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "gba/io_reg.h"

EWRAM_DATA static u8 sUnknown_0203CF48[3] = {0};
EWRAM_DATA static struct ListMenuItem *sUnknown_0203CF4C = NULL;

static void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void sub_81D24A4(struct UnknownStruct_81D1ED4 *a0);
static void sub_81D2634(struct UnknownStruct_81D1ED4 *a0);
static void MoveRelearnerCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void nullsub_79(void);

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
    .unused9 = 0
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
    u32 i;
    struct ListMenuItem **v1;
    v1 = &sUnknown_0203CF4C;
    *v1 = Alloc(count * sizeof(struct ListMenuItem) + sizeof(struct ListMenuItem));
    
    if (sUnknown_0203CF4C == NULL)
        return FALSE;
    
    for (i = 0; i < ARRAY_COUNT(sUnknown_0203CF48); i = (u8)(i + 1))
    {
        sUnknown_0203CF48[i] |= 0xFF;
    }

    return TRUE;
}

u8 sub_81D1C84(u8 a0)
{
    struct WindowTemplate template;

    u8 windowId = sUnknown_0203CF48[a0];
    if (windowId == 0xFF)
    {
        if (a0 == 2)
        {
            u32 v1;
            u32 v2;
            s32 v3;

            template = sUnknown_086253E8[2];
            v3 = GetMaxWidthInMenuTable(&gMailboxMailOptions[0], 4);
            template.width = v3;
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
    u8 j;
    u8 i;
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

NAKED
void sub_81D1F84(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 arg1[4][5], struct UnknownSubStruct_81D1ED4 arg2[4][5])
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x8\n\
	mov r8, r0\n\
	str r1, [sp]\n\
	mov r9, r2\n\
	movs r7, 0\n\
_081D1F98:\n\
	lsls r4, r7, 2\n\
	ldr r1, [sp]\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	lsls r5, r1, 8\n\
	mov r2, r9\n\
	adds r0, r4, r2\n\
	ldrh r0, [r0]\n\
	subs r0, r1\n\
	lsls r0, 8\n\
	movs r1, 0xA\n\
	bl __divsi3\n\
	adds r6, r0, 0\n\
	movs r3, 0\n\
	adds r7, 0x1\n\
	mov r10, r7\n\
	mov r12, r4\n\
_081D1FBC:\n\
	lsls r0, r3, 2\n\
	adds r0, r3\n\
	lsls r0, 2\n\
	add r0, r12\n\
	add r0, r8\n\
	asrs r2, r5, 8\n\
	asrs r1, r5, 7\n\
	movs r7, 0x1\n\
	ands r1, r7\n\
	adds r2, r1\n\
	adds r0, 0x64\n\
	strh r2, [r0]\n\
	adds r5, r6\n\
	adds r0, r3, 0x1\n\
	lsls r0, 16\n\
	lsrs r3, r0, 16\n\
	cmp r3, 0x8\n\
	bls _081D1FBC\n\
	lsls r0, r3, 2\n\
	adds r0, r3\n\
	lsls r0, 2\n\
	adds r0, r4, r0\n\
	add r0, r8\n\
	mov r1, r9\n\
	adds r2, r4, r1\n\
	ldrh r1, [r2]\n\
	adds r0, 0x64\n\
	strh r1, [r0]\n\
	ldr r7, [sp]\n\
	adds r0, r4, r7\n\
	ldrh r1, [r0, 0x2]\n\
	lsls r5, r1, 8\n\
	ldrh r0, [r2, 0x2]\n\
	subs r0, r1\n\
	lsls r0, 8\n\
	movs r1, 0xA\n\
	bl __divsi3\n\
	adds r6, r0, 0\n\
	movs r3, 0\n\
	str r4, [sp, 0x4]\n\
	movs r0, 0x1\n\
	mov r12, r0\n\
_081D2012:\n\
	lsls r0, r3, 2\n\
	adds r0, r3\n\
	lsls r0, 2\n\
	ldr r1, [sp, 0x4]\n\
	adds r0, r1, r0\n\
	add r0, r8\n\
	asrs r2, r5, 8\n\
	asrs r1, r5, 7\n\
	mov r7, r12\n\
	ands r1, r7\n\
	adds r2, r1\n\
	adds r0, 0x66\n\
	strh r2, [r0]\n\
	adds r5, r6\n\
	adds r0, r3, 0x1\n\
	lsls r0, 16\n\
	lsrs r3, r0, 16\n\
	cmp r3, 0x8\n\
	bls _081D2012\n\
	lsls r0, r3, 2\n\
	adds r0, r3\n\
	lsls r0, 2\n\
	adds r0, r4, r0\n\
	add r0, r8\n\
	mov r2, r9\n\
	adds r1, r4, r2\n\
	ldrh r1, [r1, 0x2]\n\
	adds r0, 0x66\n\
	strh r1, [r0]\n\
	mov r7, r10\n\
	lsls r0, r7, 16\n\
	lsrs r7, r0, 16\n\
	cmp r7, 0x4\n\
	bls _081D1F98\n\
	ldr r1, =0x00000352\n\
	add r1, r8\n\
	movs r0, 0\n\
	strh r0, [r1]\n\
	add sp, 0x8\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided");
}

bool32 sub_81D2074(struct UnknownStruct_81D1ED4 *a0)
{
    if (a0->unk352 < 10)
    {
        sub_81D2230(a0);
        return ++a0->unk352 != 10;
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

NAKED
void sub_81D2108(struct UnknownStruct_81D1ED4 *arg0)
{
    // Three of the additions are in the wrong order.
#ifdef NONMATCHING
    u16 i;
    u32 v3;
    u32 v4;
    u16 *scanBuffer1;
    u16 *scanBuffer2;
    u32 scanBufferWidth;
    u32 mask;
    u16 *unkBuff1;
    u16 *unkBuff2;
    u16 *unkBuff3;
    u16 *unkBuff4;

    if (arg0->unk354 == 0)
        return;
    
    sub_81D24A4(arg0);
    sub_81D2634(arg0);

    i = 0;
    scanBuffer1 = gScanlineEffectRegBuffers[0];
    scanBufferWidth = ARRAY_COUNT(gScanlineEffectRegBuffers[0]);
    scanBuffer2 = scanBuffer1 + scanBufferWidth;

    // This function accesses the arrays "manually", where every other entry
    // is just handled differently, rather than a pairwise struct.
    unkBuff1 = (u16*)&arg0->unk13C[0].unk0;
    mask = 0xFFFF;
    unkBuff2 = (u16*)&arg0->unk13C[0].unk2;
    unkBuff3 = (u16*)&arg0->unk248[0].unk0;
    unkBuff4 = (u16*)&arg0->unk248[0].unk2;

    for (; i < 0x42; i++)
    {
        u32 offset1;
        register u32 offset2 asm("r2");
        u32 offset3;

        offset1 = (i + 0x37) * 2;
        offset2 = i + 0x37;
        scanBuffer2[offset1] = (scanBuffer1[offset1] = (unkBuff1[i * 2] << 8) | unkBuff2[i * 2]) & mask;

        offset3 = offset2 * 2 + 1;
        scanBuffer2[offset3] = (scanBuffer1[offset3] = (unkBuff3[i * 2] << 8) | unkBuff4[i * 2]) & mask;
    }

    arg0->unk354 = 0;
#else
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x10\n\
	adds r6, r0, 0\n\
	movs r1, 0xD5\n\
	lsls r1, 2\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _081D21BE\n\
	adds r0, r6, 0\n\
	bl sub_81D24A4\n\
	adds r0, r6, 0\n\
	bl sub_81D2634\n\
	movs r7, 0\n\
	ldr r5, =gScanlineEffectRegBuffers\n\
	mov r12, r5\n\
	movs r0, 0xF0\n\
	lsls r0, 3\n\
	add r0, r12\n\
	mov r9, r0\n\
	movs r1, 0xA0\n\
	lsls r1, 1\n\
	adds r1, r6, r1\n\
	str r1, [sp]\n\
	ldr r5, =0x0000ffff\n\
	mov r8, r5\n\
	movs r0, 0xA1\n\
	lsls r0, 1\n\
	adds r0, r6, r0\n\
	str r0, [sp, 0x4]\n\
	movs r1, 0x92\n\
	lsls r1, 2\n\
	adds r1, r6, r1\n\
	str r1, [sp, 0x8]\n\
	ldr r5, =0x0000024a\n\
	adds r5, r6\n\
	mov r10, r5\n\
_081D215E:\n\
	adds r2, r7, 0\n\
	adds r2, 0x37\n\
	lsls r3, r2, 2\n\
	mov r0, r9\n\
	adds r0, r3, r0\n\
	str r0, [sp, 0xC]\n\
	add r3, r12\n\
	lsls r4, r7, 2\n\
	ldr r1, [sp]\n\
	adds r0, r1, r4\n\
	ldrh r0, [r0]\n\
	lsls r0, 8\n\
	ldr r5, [sp, 0x4]\n\
	adds r1, r5, r4\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	mov r1, r8\n\
	ands r0, r1\n\
	ldr r5, [sp, 0xC]\n\
	strh r0, [r5]\n\
	lsls r2, 1\n\
	adds r2, 0x1\n\
	lsls r2, 1\n\
	mov r0, r9\n\
	adds r3, r2, r0\n\
	add r2, r12\n\
	ldr r1, [sp, 0x8]\n\
	adds r0, r1, r4\n\
	ldrh r0, [r0]\n\
	lsls r0, 8\n\
	add r4, r10\n\
	ldrh r1, [r4]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	mov r5, r8\n\
	ands r0, r5\n\
	strh r0, [r3]\n\
	adds r0, r7, 0x1\n\
	lsls r0, 16\n\
	lsrs r7, r0, 16\n\
	cmp r7, 0x41\n\
	bls _081D215E\n\
	movs r0, 0xD5\n\
	lsls r0, 2\n\
	adds r1, r6, r0\n\
	movs r0, 0\n\
	strb r0, [r1]\n\
_081D21BE:\n\
	add sp, 0x10\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided");
#endif
}

void sub_81D21DC(u8 bg)
{
    u8 flags;

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
    {
        arg0->unk12C[i] = arg0->unk64[arg0->unk352][i];
    }
    arg0->unk354 = 1;
}

NAKED
static void sub_81D2278(void *a0, void *a1, u16 *a2, u16 *a3, u8 a38, u32 a3C)
{
#ifdef NONMATCHING
    // a0 => sp0
    // a1 => r6
    // a2 => r5
    // a3 => sp4
    // a38 => r9
    // a3C => r7
    u32 v1; // r10
    u32 v2; // sp8
    u32 v3; // spC
    u32 v4;
    u32 v5;
    u16 v6; // r8
    u32 v7;
    u32 v8; // sp10

    v3 = 0;

    // v4 => r4
    // v5 => r0
    // v7 => r1
    if (a2[1] < a3[1])
    {
        v1 = a2[1];
        v5 = a3[1];
        v7 = a2[0];
        v4 = v7 << 10;
        v2 = a3[0];
    }
    else
    {
        v5 = a2[1];
        v1 = a3[1];
        v7 = a3[0];
        v4 = v7 << 10;
        v2 = a2[0];
    }

    v6 = v5 - v1;
    if (v6 != 0)
    {
        v3 = (v2 - v7) / v6;
    }
    v6++;

    if (a3C == 0)
    {
        v8 = 
    }
#else
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x18\n\
	str r0, [sp]\n\
	adds r6, r1, 0\n\
	adds r5, r2, 0\n\
	str r3, [sp, 0x4]\n\
	ldr r0, [sp, 0x38]\n\
	ldr r7, [sp, 0x3C]\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	movs r0, 0\n\
	str r0, [sp, 0xC]\n\
	ldrh r0, [r5, 0x2]\n\
	ldrh r1, [r3, 0x2]\n\
	cmp r0, r1\n\
	bcs _081D22B2\n\
	adds r2, r0, 0\n\
	mov r10, r2\n\
	ldrh r0, [r3, 0x2]\n\
	ldrh r1, [r5]\n\
	lsls r4, r1, 10\n\
	ldrh r3, [r3]\n\
	str r3, [sp, 0x8]\n\
	b _081D22C6\n\
_081D22B2:\n\
	ldrh r0, [r5, 0x2]\n\
	ldr r1, [sp, 0x4]\n\
	ldrh r1, [r1, 0x2]\n\
	mov r10, r1\n\
	ldr r2, [sp, 0x4]\n\
	ldrh r1, [r2]\n\
	lsls r4, r1, 10\n\
	ldrh r3, [r5]\n\
	str r3, [sp, 0x8]\n\
	mov r2, r10\n\
_081D22C6:\n\
	subs r0, r2\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	mov r8, r0\n\
	cmp r0, 0\n\
	beq _081D22DE\n\
	subs r0, r3, r1\n\
	lsls r0, 10\n\
	mov r1, r8\n\
	bl __divsi3\n\
	str r0, [sp, 0xC]\n\
_081D22DE:\n\
	mov r0, r8\n\
	adds r0, 0x1\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	mov r8, r0\n\
	cmp r7, 0\n\
	bne _081D2328\n\
	mov r0, r10\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r6, r0\n\
	movs r5, 0\n\
	mov r3, r9\n\
	lsls r3, 1\n\
	mov r12, r3\n\
	ldr r0, [sp, 0x8]\n\
	add r0, r9\n\
	str r0, [sp, 0x10]\n\
	cmp r7, r8\n\
	bcs _081D23B6\n\
	movs r7, 0x1\n\
_081D2308:\n\
	adds r2, r3, r6\n\
	asrs r1, r4, 10\n\
	asrs r0, r4, 9\n\
	ands r0, r7\n\
	adds r1, r0\n\
	add r1, r9\n\
	strh r1, [r2]\n\
	ldr r1, [sp, 0xC]\n\
	adds r4, r1\n\
	adds r6, 0x4\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	cmp r5, r8\n\
	bcc _081D2308\n\
	b _081D23B6\n\
_081D2328:\n\
	ldr r2, [sp, 0xC]\n\
	cmp r2, 0\n\
	ble _081D23C0\n\
	mov r0, r10\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r7, r0\n\
	movs r5, 0\n\
	mov r3, r9\n\
	lsls r3, 1\n\
	mov r12, r3\n\
	ldr r0, [sp, 0x8]\n\
	add r0, r9\n\
	str r0, [sp, 0x10]\n\
	cmp r5, r8\n\
	bcs _081D237A\n\
	ldr r0, =0x00026bff\n\
	cmp r4, r0\n\
	bgt _081D237A\n\
	mov r1, r12\n\
	str r1, [sp, 0x14]\n\
_081D2352:\n\
	ldr r3, [sp, 0x14]\n\
	adds r2, r3, r7\n\
	asrs r1, r4, 10\n\
	asrs r0, r4, 9\n\
	movs r3, 0x1\n\
	ands r0, r3\n\
	adds r1, r0\n\
	add r1, r9\n\
	strh r1, [r2]\n\
	ldr r0, [sp, 0xC]\n\
	adds r4, r0\n\
	adds r7, 0x4\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	cmp r5, r8\n\
	bcs _081D237A\n\
	ldr r1, =0x00026bff\n\
	cmp r4, r1\n\
	ble _081D2352\n\
_081D237A:\n\
	mov r2, r10\n\
	adds r1, r2, r5\n\
	ldr r3, [sp]\n\
	movs r2, 0xD4\n\
	lsls r2, 2\n\
	adds r0, r3, r2\n\
	strh r1, [r0]\n\
	ldrh r0, [r0]\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r6, r0\n\
	cmp r5, r8\n\
	bcs _081D23B6\n\
	mov r3, r12\n\
	movs r7, 0x1\n\
_081D2398:\n\
	adds r2, r3, r6\n\
	asrs r1, r4, 10\n\
	asrs r0, r4, 9\n\
	ands r0, r7\n\
	adds r1, r0\n\
	add r1, r9\n\
	strh r1, [r2]\n\
	ldr r0, [sp, 0xC]\n\
	adds r4, r0\n\
	adds r6, 0x4\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	cmp r5, r8\n\
	bcc _081D2398\n\
_081D23B6:\n\
	subs r0, r6, 0x4\n\
	b _081D248C\n\
	.pool\n\
_081D23C0:\n\
	ldr r1, [sp, 0xC]\n\
	cmp r1, 0\n\
	bge _081D2464\n\
	mov r0, r10\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r6, r0\n\
	movs r5, 0\n\
	mov r2, r9\n\
	lsls r2, 1\n\
	mov r12, r2\n\
	ldr r3, [sp, 0x8]\n\
	add r3, r9\n\
	str r3, [sp, 0x10]\n\
	cmp r5, r8\n\
	bcs _081D241E\n\
	adds r3, r2, r6\n\
	asrs r1, r4, 10\n\
	asrs r0, r4, 9\n\
	movs r2, 0x1\n\
	ands r0, r2\n\
	adds r1, r0\n\
	add r1, r9\n\
	strh r1, [r3]\n\
	b _081D2414\n\
_081D23F2:\n\
	ldr r0, [sp, 0xC]\n\
	adds r4, r0\n\
	adds r6, 0x4\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	cmp r5, r8\n\
	bcs _081D241E\n\
	mov r1, r12\n\
	adds r3, r1, r6\n\
	asrs r2, r4, 10\n\
	asrs r0, r4, 9\n\
	movs r1, 0x1\n\
	ands r0, r1\n\
	adds r2, r0\n\
	add r2, r9\n\
	strh r2, [r3]\n\
_081D2414:\n\
	ldr r0, =0x00026bff\n\
	cmp r4, r0\n\
	bgt _081D23F2\n\
	movs r0, 0x9B\n\
	strh r0, [r3]\n\
_081D241E:\n\
	mov r2, r10\n\
	adds r1, r2, r5\n\
	ldr r3, [sp]\n\
	movs r2, 0xD4\n\
	lsls r2, 2\n\
	adds r0, r3, r2\n\
	strh r1, [r0]\n\
	ldrh r0, [r0]\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r7, r0\n\
	cmp r5, r8\n\
	bcs _081D245A\n\
	mov r3, r12\n\
	movs r6, 0x1\n\
_081D243C:\n\
	adds r2, r3, r7\n\
	asrs r1, r4, 10\n\
	asrs r0, r4, 9\n\
	ands r0, r6\n\
	adds r1, r0\n\
	add r1, r9\n\
	strh r1, [r2]\n\
	ldr r0, [sp, 0xC]\n\
	adds r4, r0\n\
	adds r7, 0x4\n\
	adds r0, r5, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	cmp r5, r8\n\
	bcc _081D243C\n\
_081D245A:\n\
	subs r0, r7, 0x4\n\
	b _081D248C\n\
	.pool\n\
_081D2464:\n\
	ldr r1, [sp]\n\
	movs r2, 0xD4\n\
	lsls r2, 2\n\
	adds r0, r1, r2\n\
	mov r3, r10\n\
	strh r3, [r0]\n\
	mov r0, r10\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r6, r0\n\
	adds r7, r0\n\
	ldrh r0, [r5]\n\
	adds r0, 0x1\n\
	strh r0, [r6, 0x2]\n\
	ldr r1, [sp, 0x4]\n\
	ldrh r0, [r1]\n\
	strh r0, [r7]\n\
	movs r0, 0x9B\n\
	strh r0, [r7, 0x2]\n\
	b _081D2494\n\
_081D248C:\n\
	add r0, r12\n\
	mov r2, sp\n\
	ldrh r2, [r2, 0x10]\n\
	strh r2, [r0]\n\
_081D2494:\n\
	add sp, 0x18\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided");
#endif
}

NAKED
static void sub_81D24A4(struct UnknownStruct_81D1ED4 *a0)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	sub sp, 0x8\n\
	adds r4, r0, 0\n\
	movs r0, 0x97\n\
	lsls r0, 1\n\
	adds r2, r4, r0\n\
	movs r3, 0x99\n\
	lsls r3, 1\n\
	adds r1, r4, r3\n\
	ldrh r0, [r2]\n\
	ldrh r3, [r1]\n\
	cmp r0, r3\n\
	bcs _081D24E0\n\
	adds r7, r0, 0\n\
	movs r0, 0xA0\n\
	lsls r0, 1\n\
	adds r1, r4, r0\n\
	movs r3, 0x96\n\
	lsls r3, 1\n\
	adds r2, r4, r3\n\
	subs r0, 0x10\n\
	adds r3, r4, r0\n\
	movs r0, 0x1\n\
	str r0, [sp]\n\
	movs r0, 0\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	bl sub_81D2278\n\
	b _081D2500\n\
_081D24E0:\n\
	ldrh r7, [r1]\n\
	movs r2, 0xA0\n\
	lsls r2, 1\n\
	adds r1, r4, r2\n\
	movs r3, 0x98\n\
	lsls r3, 1\n\
	adds r2, r4, r3\n\
	movs r0, 0x96\n\
	lsls r0, 1\n\
	adds r3, r4, r0\n\
	movs r0, 0\n\
	str r0, [sp]\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	bl sub_81D2278\n\
_081D2500:\n\
	movs r1, 0xA0\n\
	lsls r1, 1\n\
	adds r5, r4, r1\n\
	movs r3, 0x98\n\
	lsls r3, 1\n\
	adds r2, r4, r3\n\
	movs r0, 0x9A\n\
	lsls r0, 1\n\
	adds r6, r4, r0\n\
	movs r0, 0x1\n\
	str r0, [sp]\n\
	movs r0, 0\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	adds r1, r5, 0\n\
	adds r3, r6, 0\n\
	bl sub_81D2278\n\
	movs r2, 0\n\
	movs r1, 0x9B\n\
	lsls r1, 1\n\
	adds r0, r4, r1\n\
	movs r3, 0x9D\n\
	lsls r3, 1\n\
	adds r1, r4, r3\n\
	ldrh r0, [r0]\n\
	ldrh r1, [r1]\n\
	cmp r0, r1\n\
	bhi _081D253C\n\
	movs r2, 0x1\n\
_081D253C:\n\
	movs r0, 0x9C\n\
	lsls r0, 1\n\
	adds r3, r4, r0\n\
	str r2, [sp]\n\
	movs r1, 0x92\n\
	lsls r1, 2\n\
	adds r0, r4, r1\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	adds r1, r5, 0\n\
	adds r2, r6, 0\n\
	bl sub_81D2278\n\
	movs r2, 0x38\n\
	cmp r2, r7\n\
	bcs _081D257E\n\
	adds r6, r5, 0\n\
	movs r3, 0\n\
	movs r0, 0xA1\n\
	lsls r0, 1\n\
	adds r5, r4, r0\n\
_081D2566:\n\
	adds r0, r2, 0\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r1, r6, r0\n\
	strh r3, [r1]\n\
	adds r0, r5, r0\n\
	strh r3, [r0]\n\
	adds r0, r2, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	cmp r2, r7\n\
	bcc _081D2566\n\
_081D257E:\n\
	movs r1, 0x97\n\
	lsls r1, 1\n\
	adds r0, r4, r1\n\
	ldrh r2, [r0]\n\
	movs r3, 0xD4\n\
	lsls r3, 2\n\
	adds r0, r4, r3\n\
	ldrh r1, [r0]\n\
	cmp r2, r1\n\
	bhi _081D25B2\n\
	movs r1, 0xA0\n\
	lsls r1, 1\n\
	adds r3, r4, r1\n\
	movs r5, 0x9B\n\
	adds r1, r0, 0\n\
_081D259C:\n\
	adds r0, r2, 0\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r0, r3, r0\n\
	strh r5, [r0]\n\
	adds r0, r2, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	ldrh r0, [r1]\n\
	cmp r2, r0\n\
	bls _081D259C\n\
_081D25B2:\n\
	movs r2, 0x9B\n\
	lsls r2, 1\n\
	adds r1, r4, r2\n\
	movs r3, 0xD4\n\
	lsls r3, 2\n\
	adds r0, r4, r3\n\
	ldrh r0, [r0]\n\
	ldrh r1, [r1]\n\
	cmp r0, r1\n\
	bcs _081D25C8\n\
	adds r0, r1, 0\n\
_081D25C8:\n\
	adds r0, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	cmp r2, 0x79\n\
	bhi _081D25F8\n\
	movs r0, 0xA0\n\
	lsls r0, 1\n\
	adds r6, r4, r0\n\
	movs r3, 0\n\
	movs r1, 0xA1\n\
	lsls r1, 1\n\
	adds r5, r4, r1\n\
_081D25E0:\n\
	adds r0, r2, 0\n\
	subs r0, 0x38\n\
	lsls r0, 2\n\
	adds r1, r6, r0\n\
	strh r3, [r1]\n\
	adds r0, r5, r0\n\
	strh r3, [r0]\n\
	adds r0, r2, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	cmp r2, 0x79\n\
	bls _081D25E0\n\
_081D25F8:\n\
	movs r2, 0x38\n\
	movs r3, 0xA0\n\
	lsls r3, 1\n\
	adds r5, r4, r3\n\
	movs r0, 0xA1\n\
	lsls r0, 1\n\
	adds r4, r0\n\
	movs r6, 0x9B\n\
_081D2608:\n\
	adds r0, r2, 0\n\
	subs r0, 0x38\n\
	lsls r1, r0, 2\n\
	adds r3, r5, r1\n\
	ldrh r0, [r3]\n\
	cmp r0, 0\n\
	bne _081D2620\n\
	adds r0, r4, r1\n\
	ldrh r0, [r0]\n\
	cmp r0, 0\n\
	beq _081D2620\n\
	strh r6, [r3]\n\
_081D2620:\n\
	adds r0, r2, 0x1\n\
	lsls r0, 16\n\
	lsrs r2, r0, 16\n\
	cmp r2, 0x79\n\
	bls _081D2608\n\
	add sp, 0x8\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided");
}

NAKED
static void sub_81D2634(struct UnknownStruct_81D1ED4 *a0)
{
    asm(".syntax unified\n\
	push {r4-r6,lr}\n\
	sub sp, 0x8\n\
	adds r4, r0, 0\n\
	movs r0, 0x97\n\
	lsls r0, 1\n\
	adds r2, r4, r0\n\
	movs r3, 0x9F\n\
	lsls r3, 1\n\
	adds r1, r4, r3\n\
	ldrh r0, [r2]\n\
	ldrh r5, [r1]\n\
	cmp r0, r5\n\
	bcs _081D266E\n\
	adds r6, r0, 0\n\
	movs r0, 0x92\n\
	lsls r0, 2\n\
	adds r1, r4, r0\n\
	subs r3, 0x12\n\
	adds r2, r4, r3\n\
	movs r5, 0x9E\n\
	lsls r5, 1\n\
	adds r3, r4, r5\n\
	movs r0, 0\n\
	str r0, [sp]\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	bl sub_81D2278\n\
	b _081D2690\n\
_081D266E:\n\
	ldrh r6, [r1]\n\
	movs r0, 0x92\n\
	lsls r0, 2\n\
	adds r1, r4, r0\n\
	movs r3, 0x9E\n\
	lsls r3, 1\n\
	adds r2, r4, r3\n\
	movs r5, 0x96\n\
	lsls r5, 1\n\
	adds r3, r4, r5\n\
	movs r0, 0x1\n\
	str r0, [sp]\n\
	movs r0, 0\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	bl sub_81D2278\n\
_081D2690:\n\
	movs r0, 0x92\n\
	lsls r0, 2\n\
	adds r5, r4, r0\n\
	movs r1, 0x9E\n\
	lsls r1, 1\n\
	adds r2, r4, r1\n\
	movs r0, 0x9C\n\
	lsls r0, 1\n\
	adds r3, r4, r0\n\
	movs r0, 0\n\
	str r0, [sp]\n\
	str r0, [sp, 0x4]\n\
	adds r0, r4, 0\n\
	adds r1, r5, 0\n\
	bl sub_81D2278\n\
	cmp r6, 0x38\n\
	ble _081D26C8\n\
	movs r0, 0\n\
	adds r1, r5, 0\n\
	adds r2, r6, 0\n\
	subs r2, 0x38\n\
_081D26BC:\n\
	strh r0, [r1]\n\
	strh r0, [r1, 0x2]\n\
	adds r1, 0x4\n\
	subs r2, 0x1\n\
	cmp r2, 0\n\
	bne _081D26BC\n\
_081D26C8:\n\
	movs r1, 0x97\n\
	lsls r1, 1\n\
	adds r0, r4, r1\n\
	ldrh r2, [r0]\n\
	movs r3, 0xD4\n\
	lsls r3, 2\n\
	adds r0, r4, r3\n\
	ldrh r5, [r0]\n\
	cmp r2, r5\n\
	bgt _081D26F6\n\
	movs r3, 0x9B\n\
	adds r1, r0, 0\n\
	lsls r0, r2, 2\n\
	movs r5, 0xB5\n\
	lsls r5, 1\n\
	adds r0, r5\n\
	adds r0, r4\n\
_081D26EA:\n\
	strh r3, [r0]\n\
	adds r0, 0x4\n\
	adds r2, 0x1\n\
	ldrh r5, [r1]\n\
	cmp r2, r5\n\
	ble _081D26EA\n\
_081D26F6:\n\
	movs r1, 0x9D\n\
	lsls r1, 1\n\
	adds r0, r4, r1\n\
	ldrh r0, [r0]\n\
	adds r1, r0, 0x1\n\
	movs r2, 0xD4\n\
	lsls r2, 2\n\
	adds r0, r4, r2\n\
	ldrh r0, [r0]\n\
	cmp r0, r1\n\
	bge _081D270E\n\
	adds r0, r1, 0\n\
_081D270E:\n\
	adds r2, r0, 0\n\
	cmp r2, 0x79\n\
	bgt _081D272C\n\
	movs r1, 0\n\
	lsls r0, r2, 2\n\
	movs r3, 0xB4\n\
	lsls r3, 1\n\
	adds r0, r3\n\
	adds r0, r4\n\
_081D2720:\n\
	strh r1, [r0]\n\
	strh r1, [r0, 0x2]\n\
	adds r0, 0x4\n\
	adds r2, 0x1\n\
	cmp r2, 0x79\n\
	ble _081D2720\n\
_081D272C:\n\
	movs r3, 0\n\
	movs r5, 0x92\n\
	lsls r5, 2\n\
	adds r1, r4, r5\n\
	movs r2, 0x41\n\
_081D2736:\n\
	ldrh r0, [r1]\n\
	ldrh r4, [r1, 0x2]\n\
	cmp r0, r4\n\
	bcc _081D2742\n\
	strh r3, [r1, 0x2]\n\
	strh r3, [r1]\n\
_081D2742:\n\
	adds r1, 0x4\n\
	subs r2, 0x1\n\
	cmp r2, 0\n\
	bge _081D2736\n\
	add sp, 0x8\n\
	pop {r4-r6}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided");
}

NAKED
void sub_81D2754(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 *arg1)
{
    // There are some register-renaming issues here. The cause of the problem seems to be that
    // GCC tries to save sUnknown_08625410 in a register, instead of loading the constant repeatedly.
    // But this is one too many things to keep track of, so GCC is forced to use the stack.
#ifdef NONMATCHING
    u8* v1;
    u8 v2;
    u8 v3;
    s8 v4;
    u16 v5;

    v1 = arg0->unk0[0];
    v2 = sUnknown_08625410[*v1];
    v1++;
    arg1[0].unk0 = 0x9B;
    arg1[0].unk2 = 0x5B - v2;
    for (v3 = 0x40, v4 = 0, v5 = 1; v5 < 5; v5++)
    {
        v3 += 0x33;
        v4--;
        if (v4 < 0)
        {
            v4 = 4;
        }
        if (v4 == 2)
        {
            v3++;
        }

        v2 = sUnknown_08625410[*v1];
        v1++;
        arg1[v4].unk0 = ((gSineTable[v3 + 0x40] * v2) >> 8) + 0x9B;
        arg1[v4].unk2 = ((gSineTable[v3] * v2) >> 8) - 0x5B;
        if (v4 <= 2 && (v2 != 0x20 || v4 != 2))
        {
            arg1[v4].unk0 = arg1[v4].unk0 + 1;
        }
    }
#else
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	adds r6, r0, 0\n\
	mov r8, r1\n\
	ldr r1, =sUnknown_08625410\n\
	ldrb r0, [r6]\n\
	adds r0, r1\n\
	ldrb r2, [r0]\n\
	adds r6, 0x1\n\
	movs r0, 0x9B\n\
	mov r3, r8\n\
	strh r0, [r3]\n\
	movs r0, 0x5B\n\
	subs r0, r2\n\
	strh r0, [r3, 0x2]\n\
	movs r7, 0x40\n\
	movs r0, 0\n\
	mov r12, r0\n\
	movs r2, 0x1\n\
	mov r9, r2\n\
	ldr r3, =gSineTable\n\
	mov r10, r3\n\
_081D2786:\n\
	adds r0, r7, 0\n\
	adds r0, 0x33\n\
	lsls r0, 24\n\
	lsrs r7, r0, 24\n\
	mov r1, r12\n\
	lsls r0, r1, 24\n\
	movs r2, 0xFF\n\
	lsls r2, 24\n\
	adds r0, r2\n\
	lsrs r3, r0, 24\n\
	mov r12, r3\n\
	cmp r0, 0\n\
	bge _081D27A4\n\
	movs r0, 0x4\n\
	mov r12, r0\n\
_081D27A4:\n\
	mov r1, r12\n\
	lsls r0, r1, 24\n\
	asrs r4, r0, 24\n\
	cmp r4, 0x2\n\
	bne _081D27B4\n\
	adds r0, r7, 0x1\n\
	lsls r0, 24\n\
	lsrs r7, r0, 24\n\
_081D27B4:\n\
	ldrb r0, [r6]\n\
	ldr r2, =sUnknown_08625410\n\
	adds r0, r2\n\
	ldrb r2, [r0]\n\
	adds r6, 0x1\n\
	lsls r0, r4, 2\n\
	mov r1, r8\n\
	adds r3, r0, r1\n\
	adds r0, r7, 0\n\
	adds r0, 0x40\n\
	lsls r0, 1\n\
	add r0, r10\n\
	movs r1, 0\n\
	ldrsh r0, [r0, r1]\n\
	muls r0, r2\n\
	asrs r5, r0, 8\n\
	adds r0, r5, 0\n\
	adds r0, 0x9B\n\
	strh r0, [r3]\n\
	lsls r0, r7, 1\n\
	add r0, r10\n\
	movs r1, 0\n\
	ldrsh r0, [r0, r1]\n\
	adds r1, r2, 0\n\
	muls r1, r0\n\
	asrs r1, 8\n\
	movs r0, 0x5B\n\
	subs r0, r1\n\
	strh r0, [r3, 0x2]\n\
	cmp r4, 0x2\n\
	bgt _081D2800\n\
	cmp r2, 0x20\n\
	bne _081D27FA\n\
	cmp r4, 0x2\n\
	beq _081D2800\n\
_081D27FA:\n\
	adds r0, r5, 0\n\
	adds r0, 0x9C\n\
	strh r0, [r3]\n\
_081D2800:\n\
	mov r0, r9\n\
	adds r0, 0x1\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	mov r9, r0\n\
	cmp r0, 0x4\n\
	bls _081D2786\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided");
#endif
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

NAKED
static void MoveRelearnerLoadBattleMoveDescription(u32 chosenMove)
{
    // Two small issues, and a few renamed registers.
#ifdef NONMATCHING
    u8 offset;
    s32 width;
    const struct BattleMove *move;
    u8 buffer[0x20];
    const u8 *labelStr;

    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    labelStr = gText_MoveRelearnerBattleMoves;
    offset = GetStringCenterAlignXOffset(1, labelStr, 0x80);
    AddTextPrinterParameterized(0, 1, labelStr, offset, 1, TEXT_SPEED_FF, NULL);

    labelStr = gText_MoveRelearnerPP;
    AddTextPrinterParameterized(0, 1, labelStr, 4, 0x29, TEXT_SPEED_FF, NULL);

    labelStr = gText_MoveRelearnerPower;
    offset = GetStringRightAlignXOffset(1, labelStr, 0x6A);
    AddTextPrinterParameterized(0, 1, labelStr, offset, 0x19, TEXT_SPEED_FF, NULL);

    labelStr = gText_MoveRelearnerAccuracy;
    offset = GetStringRightAlignXOffset(1, labelStr, 0x6A);
    AddTextPrinterParameterized(0, 1, labelStr, offset, 0x29, TEXT_SPEED_FF, NULL);
    if (chosenMove == LIST_CANCEL)
    {
        CopyWindowToVram(0, 2);
        return;
    }
    move = &gBattleMoves[chosenMove];
    labelStr = gTypeNames[move->type];
    // GCC tries to be smart, and preserves the same 0x19 from above for this.
    // The original asm just loads the constant 0x19 twice.
    AddTextPrinterParameterized(0, 1, labelStr, 4, 0x19, TEXT_SPEED_FF, NULL);

    // GCC tries to generate this as:
    //   add r4, r0, 0
    //   add r4, r4, 4
    // But the original asm is:
    //   add r4, r0, 4
    width = 4 + GetStringWidth(1, gText_MoveRelearnerPP, 0);

    ConvertIntToDecimalStringN(buffer, move->pp, 0, 2);
    AddTextPrinterParameterized(0, 1, buffer, width, 0x29, TEXT_SPEED_FF, NULL);
    

    if (move->power < 2)
    {
        labelStr = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->power, 0, 3);
        labelStr = buffer;
    }
    AddTextPrinterParameterized(0, 1, labelStr, 0x6A, 0x19, TEXT_SPEED_FF, NULL);

    if (move->accuracy == 0)
    {
        labelStr = gText_ThreeDashes;
    }
    else
    {
        ConvertIntToDecimalStringN(buffer, move->accuracy, 0, 3);
        labelStr = buffer;
    }
    AddTextPrinterParameterized(0, 1, labelStr, 0x6A, 0x29, TEXT_SPEED_FF, NULL);
    labelStr = gMoveDescriptionPointers[chosenMove - 1];
    AddTextPrinterParameterized(0, 7, labelStr, 0, 0x41, 0, NULL);
#else
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x2C\n\
	mov r9, r0\n\
	movs r0, 0\n\
	movs r1, 0x11\n\
	bl FillWindowPixelBuffer\n\
	ldr r5, =gText_MoveRelearnerBattleMoves\n\
	movs r0, 0x1\n\
	adds r1, r5, 0\n\
	movs r2, 0x80\n\
	bl GetStringCenterAlignXOffset\n\
	adds r4, r0, 0\n\
	lsls r3, r4, 24\n\
	lsrs r3, 24\n\
	movs r0, 0x1\n\
	str r0, [sp]\n\
	movs r0, 0xFF\n\
	mov r8, r0\n\
	str r0, [sp, 0x4]\n\
	movs r7, 0\n\
	str r7, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	bl AddTextPrinterParameterized\n\
	ldr r5, =gText_MoveRelearnerPP\n\
	movs r1, 0x29\n\
	mov r10, r1\n\
	str r1, [sp]\n\
	mov r0, r8\n\
	str r0, [sp, 0x4]\n\
	str r7, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	movs r3, 0x4\n\
	bl AddTextPrinterParameterized\n\
	ldr r5, =gText_MoveRelearnerPower\n\
	movs r0, 0x1\n\
	adds r1, r5, 0\n\
	movs r2, 0x6A\n\
	bl GetStringRightAlignXOffset\n\
	adds r4, r0, 0\n\
	lsls r3, r4, 24\n\
	lsrs r3, 24\n\
	movs r1, 0x19\n\
	str r1, [sp]\n\
	mov r0, r8\n\
	str r0, [sp, 0x4]\n\
	str r7, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	bl AddTextPrinterParameterized\n\
	ldr r5, =gText_MoveRelearnerAccuracy\n\
	movs r0, 0x1\n\
	adds r1, r5, 0\n\
	movs r2, 0x6A\n\
	bl GetStringRightAlignXOffset\n\
	adds r4, r0, 0\n\
	lsls r3, r4, 24\n\
	lsrs r3, 24\n\
	mov r1, r10\n\
	str r1, [sp]\n\
	mov r0, r8\n\
	str r0, [sp, 0x4]\n\
	str r7, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	bl AddTextPrinterParameterized\n\
	movs r0, 0x2\n\
	negs r0, r0\n\
	cmp r9, r0\n\
	bne _081D29C4\n\
	movs r0, 0\n\
	movs r1, 0x2\n\
	bl CopyWindowToVram\n\
	b _081D2AB6\n\
	.pool\n\
_081D29C4:\n\
	mov r1, r9\n\
	lsls r0, r1, 1\n\
	add r0, r9\n\
	lsls r0, 2\n\
	ldr r1, =gBattleMoves\n\
	adds r6, r0, r1\n\
	ldrb r1, [r6, 0x2]\n\
	lsls r0, r1, 3\n\
	subs r0, r1\n\
	ldr r1, =gTypeNames\n\
	adds r5, r0, r1\n\
	movs r0, 0x19\n\
	str r0, [sp]\n\
	mov r1, r8\n\
	str r1, [sp, 0x4]\n\
	str r7, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	movs r3, 0x4\n\
	bl AddTextPrinterParameterized\n\
	ldr r1, =gText_MoveRelearnerPP\n\
	movs r0, 0x1\n\
	movs r2, 0\n\
	bl GetStringWidth\n\
	adds r4, r0, 0x4\n\
	ldrb r1, [r6, 0x4]\n\
	add r0, sp, 0xC\n\
	movs r2, 0\n\
	movs r3, 0x2\n\
	bl ConvertIntToDecimalStringN\n\
	lsls r3, r4, 24\n\
	lsrs r3, 24\n\
	mov r0, r10\n\
	str r0, [sp]\n\
	mov r1, r8\n\
	str r1, [sp, 0x4]\n\
	str r7, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	add r2, sp, 0xC\n\
	bl AddTextPrinterParameterized\n\
	ldrb r0, [r6, 0x1]\n\
	cmp r0, 0x1\n\
	bhi _081D2A3C\n\
	ldr r5, =gText_ThreeDashes\n\
	b _081D2A4A\n\
	.pool\n\
_081D2A3C:\n\
	ldrb r1, [r6, 0x1]\n\
	add r0, sp, 0xC\n\
	movs r2, 0\n\
	movs r3, 0x3\n\
	bl ConvertIntToDecimalStringN\n\
	add r5, sp, 0xC\n\
_081D2A4A:\n\
	movs r0, 0x19\n\
	str r0, [sp]\n\
	movs r0, 0xFF\n\
	str r0, [sp, 0x4]\n\
	movs r0, 0\n\
	str r0, [sp, 0x8]\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	movs r3, 0x6A\n\
	bl AddTextPrinterParameterized\n\
	ldrb r0, [r6, 0x3]\n\
	cmp r0, 0\n\
	bne _081D2A70\n\
	ldr r5, =gText_ThreeDashes\n\
	b _081D2A7E\n\
	.pool\n\
_081D2A70:\n\
	ldrb r1, [r6, 0x3]\n\
	add r0, sp, 0xC\n\
	movs r2, 0\n\
	movs r3, 0x3\n\
	bl ConvertIntToDecimalStringN\n\
	add r5, sp, 0xC\n\
_081D2A7E:\n\
	movs r0, 0x29\n\
	str r0, [sp]\n\
	movs r0, 0xFF\n\
	str r0, [sp, 0x4]\n\
	movs r4, 0\n\
	str r4, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	movs r3, 0x6A\n\
	bl AddTextPrinterParameterized\n\
	ldr r1, =gMoveDescriptionPointers\n\
	mov r0, r9\n\
	subs r0, 0x1\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldr r5, [r0]\n\
	movs r0, 0x41\n\
	str r0, [sp]\n\
	str r4, [sp, 0x4]\n\
	str r4, [sp, 0x8]\n\
	movs r0, 0\n\
	movs r1, 0x7\n\
	adds r2, r5, 0\n\
	movs r3, 0\n\
	bl AddTextPrinterParameterized\n\
_081D2AB6:\n\
	add sp, 0x2C\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided");
#endif
}

NAKED
static void MoveRelearnerMenuLoadContestMoveDescription(u32 chosenMove)
{
#ifdef NONMATCHING
    //u8 offset;
    const u8 *labelStr;
    const struct ContestMove *move;
    u8 category;
    const u8 **temp;

    MoveRelearnerShowHideHearts(chosenMove);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    labelStr = gText_MoveRelearnerContestMovesTitle;
    // GCC compiles these as:
    //   add r3, r0, 0
    //   lsls r3, r3, 24
    //   lsrs r3, r3, 24
    // But in the original asm:
    //   lsls r3, r0, 24
    //   lsrs r3, r3, 24
    //offset = GetStringCenterAlignXOffset(1, labelStr, 0x80);
    AddTextPrinterParameterized(1, 1, labelStr, GetStringCenterAlignXOffset(1, labelStr, 0x80), 1, TEXT_SPEED_FF, NULL);

    labelStr = gText_MoveRelearnerAppeal;
    //offset = GetStringRightAlignXOffset(1, labelStr, 0x5C);
    AddTextPrinterParameterized(1, 1, labelStr, GetStringCenterAlignXOffset(1, labelStr, 0x5C), 0x19, TEXT_SPEED_FF, NULL);

    labelStr = gText_MoveRelearnerJam;
    //offset = GetStringRightAlignXOffset(1, labelStr, 0x5C);
    AddTextPrinterParameterized(1, 1, labelStr, GetStringCenterAlignXOffset(1, labelStr, 0x5C), 0x29, TEXT_SPEED_FF, NULL);

    if (chosenMove == MENU_NOTHING_CHOSEN)
    {
        CopyWindowToVram(1, 2);
        return;
    }

    move = &gContestMoves[chosenMove];
    temp = (const u8**)gContestMoveTypeTextPointers;
    category = move->contestCategory;
    labelStr = temp[category];
    AddTextPrinterParameterized(1, 1, labelStr, 4, 0x19, TEXT_SPEED_FF, NULL);

    labelStr = gContestEffectDescriptionPointers[move->effect];
    AddTextPrinterParameterized(1, 1, labelStr, 0, 0x41, TEXT_SPEED_FF, NULL);

    CopyWindowToVram(1, 2);
#else
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0xC\n\
	adds r4, r0, 0\n\
	bl MoveRelearnerShowHideHearts\n\
	movs r0, 0x1\n\
	movs r1, 0x11\n\
	bl FillWindowPixelBuffer\n\
	ldr r5, =gText_MoveRelearnerContestMovesTitle\n\
	movs r0, 0x1\n\
	adds r1, r5, 0\n\
	movs r2, 0x80\n\
	bl GetStringCenterAlignXOffset\n\
	lsls r3, r0, 24\n\
	lsrs r3, 24\n\
	movs r0, 0x1\n\
	str r0, [sp]\n\
	movs r7, 0xFF\n\
	str r7, [sp, 0x4]\n\
	movs r6, 0\n\
	str r6, [sp, 0x8]\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	bl AddTextPrinterParameterized\n\
	ldr r5, =gText_MoveRelearnerAppeal\n\
	movs r0, 0x1\n\
	adds r1, r5, 0\n\
	movs r2, 0x5C\n\
	bl GetStringRightAlignXOffset\n\
	lsls r3, r0, 24\n\
	lsrs r3, 24\n\
	movs r0, 0x19\n\
	mov r8, r0\n\
	str r0, [sp]\n\
	str r7, [sp, 0x4]\n\
	str r6, [sp, 0x8]\n\
	movs r0, 0x1\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	bl AddTextPrinterParameterized\n\
	ldr r5, =gText_MoveRelearnerJam\n\
	movs r0, 0x1\n\
	adds r1, r5, 0\n\
	movs r2, 0x5C\n\
	bl GetStringRightAlignXOffset\n\
	lsls r3, r0, 24\n\
	lsrs r3, 24\n\
	movs r0, 0x29\n\
	str r0, [sp]\n\
	str r7, [sp, 0x4]\n\
	str r6, [sp, 0x8]\n\
	movs r0, 0x1\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	bl AddTextPrinterParameterized\n\
	movs r0, 0x2\n\
	negs r0, r0\n\
	cmp r4, r0\n\
	bne _081D2B6C\n\
	movs r0, 0x1\n\
	movs r1, 0x2\n\
	bl CopyWindowToVram\n\
	b _081D2BB8\n\
	.pool\n\
_081D2B6C:\n\
	lsls r4, 3\n\
	ldr r0, =gContestMoves\n\
	adds r4, r0\n\
	ldr r1, =gContestMoveTypeTextPointers\n\
	ldrb r0, [r4, 0x1]\n\
	lsls r0, 29\n\
	lsrs r0, 27\n\
	adds r0, r1\n\
	ldr r5, [r0]\n\
	mov r0, r8\n\
	str r0, [sp]\n\
	str r7, [sp, 0x4]\n\
	str r6, [sp, 0x8]\n\
	movs r0, 0x1\n\
	movs r1, 0x1\n\
	adds r2, r5, 0\n\
	movs r3, 0x4\n\
	bl AddTextPrinterParameterized\n\
	ldr r1, =gContestEffectDescriptionPointers\n\
	ldrb r0, [r4]\n\
	lsls r0, 2\n\
	adds r0, r1\n\
	ldr r5, [r0]\n\
	movs r0, 0x41\n\
	str r0, [sp]\n\
	str r7, [sp, 0x4]\n\
	str r6, [sp, 0x8]\n\
	movs r0, 0x1\n\
	movs r1, 0x7\n\
	adds r2, r5, 0\n\
	movs r3, 0\n\
	bl AddTextPrinterParameterized\n\
	movs r0, 0x1\n\
	movs r1, 0x2\n\
	bl CopyWindowToVram\n\
_081D2BB8:\n\
	add sp, 0xC\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided");
#endif
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