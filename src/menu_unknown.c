#include "global.h"
#include "alloc.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_unknown.h"
#include "player_pc.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "window.h"
#include "constants/songs.h"
#include "scanline_effect.h"

#define WINDOW_UNK_0 0
#define WINDOW_UNK_1 1
#define WINDOW_UNK_2 2

EWRAM_DATA static u8 sUnknown_0203CF48[3] = {0};
EWRAM_DATA static struct ListMenuItem *sUnknown_0203CF4C = NULL;

void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list);

static const struct WindowTemplate sUnknown_086253E8[] =
{
    [WINDOW_UNK_0] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x8
    },
    [WINDOW_UNK_1] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 1,
        .width = 8,
        .height = 18,
        .paletteNum = 0xF,
        .baseBlock = 0x18
    },
    [WINDOW_UNK_2] = {
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
        if (a0 == WINDOW_UNK_2)
        {
            u32 v1;
            u32 v2;
            s32 v3;

            template = sUnknown_086253E8[WINDOW_UNK_2];
            v3 = GetMaxWidthInMenuTable(&gMailboxMailOptions[0], 4);
            template.width = v3;
            sUnknown_0203CF48[WINDOW_UNK_2] = AddWindow(&template);
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
    sub_8198070(sUnknown_0203CF48[a0], 0);
    ClearWindowTilemap(sUnknown_0203CF48[a0]);
    RemoveWindow(sUnknown_0203CF48[a0]);
    sUnknown_0203CF48[a0] = 0xFF;
}

u8 sub_81D1D34(u8 a0)
{
    return sUnknown_0203CF48[a0];
}

void sub_81D1D44(u8 windowId, s32 itemId, u8 y)
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

void sub_81D1E7C(s32 itemIndex, bool8 onInit, struct ListMenu *list)
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
    /*
    u16 j;
    u16 i;
    s16 v1;
    s16 v2;
    for (j = 0; j < 5; j++)
    {
        v1 = arg1[0][j].unk0;
        v2 = (arg2[0][j].unk0 - v1) / 10;

        for (i = 0; i < 9; i++)
        {
            arg0->unk64[i][j].unk0 = v1 + ((v1 << 1) & 1);
        }

        for (i = 0; i < 9; i++)
        {

        }
    }
    */
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