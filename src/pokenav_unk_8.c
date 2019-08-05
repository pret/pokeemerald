#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "window.h"

struct PokenavSub7
{
    u32 (*unk0)(struct PokenavSub7 *);
    u32 loopedTaskId;
    u8 fill1[4];
    s32 unkC;
    s32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    struct PokenavSub18 *unkPtr;
};

u32 sub_81CF010(struct PokenavSub7 *structPtr);
u32 sub_81CF030(struct PokenavSub7 *structPtr);
u32 sub_81CF0B8(struct PokenavSub7 *structPtr);
u32 sub_81CF0B0(struct PokenavSub7 *structPtr);
u32 sub_81CF11C(s32 state);
u32 sub_81CF134(s32 state);
u32 sub_81CF1C4(s32 state);
u32 sub_81CF1D8(s32 state);
u32 sub_81CF278(s32 state);
u32 sub_81CF578(s32 state);
u32 sub_81CF5F0(s32 state);
u32 sub_81CF668(s32 state);
u32 sub_81CF6E0(s32 state);
u32 sub_81CF758(s32 state);
u32 sub_81CF798(s32 state);
void sub_81CF2C4(struct PokenavSub7 *structPtr, struct PokenavMonList *item);

const u32 gUnknown_086233A0[] = {0x16, 0x17, 0x18, 0x21, 0x2F};

const LoopedTask gUnknown_086233B4[] =
{
    sub_81CF134,
    sub_81CF1C4,
    sub_81CF1D8,
    sub_81CF278
};

const u16 gUnknown_086233C4[] = INCBIN_U16("graphics/pokenav/condition_search2.gbapal");
const u32 gUnknown_086233E4[] = INCBIN_U32("graphics/pokenav/condition_search2.4bpp.lz");
const u32 gUnknown_086234AC[] = INCBIN_U32("graphics/pokenav/condition_search2.bin.lz");
const u16 gUnknown_08623570[] = INCBIN_U16("graphics/pokenav/8623570.gbapal");

const struct BgTemplate gUnknown_08623590 = 
{
    .bg = 1,
    .charBaseIndex = 1,
    .mapBaseIndex = 0x06,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 2,
    .baseTile = 0
};

const struct BgTemplate gUnknown_08623594 = 
{
    .bg = 2,
    .charBaseIndex = 2,
    .mapBaseIndex = 0x07,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 3,
    .baseTile = 0
};

const LoopedTask gUnknown_08623598[] = 
{
    NULL,
    sub_81CF578,
    sub_81CF5F0,
    sub_81CF668,
    sub_81CF6E0,
    sub_81CF758,
    sub_81CF798
};

const struct WindowTemplate gUnknown_086235B4 = 
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

const u8 gUnknown_086235BC[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086235C8[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086235D4[] = _("{UNK_SPACER}");

bool32 sub_81CEF3C(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(7, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unkPtr = AllocSubstruct(18, sizeof(struct PokenavSub18));
    if (structPtr->unkPtr == NULL)
        return FALSE;

    structPtr->unk0 = sub_81CF010;
    structPtr->loopedTaskId = CreateLoopedTask(sub_81CF11C, 1);
    structPtr->unk18 = 0;
    structPtr->unk14 = gUnknown_086233A0[sub_81C76AC()];
    return TRUE;
}

bool32 sub_81CEF98(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(7, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unkPtr = GetSubstructPtr(18);
    structPtr->unk0 = sub_81CF030;
    structPtr->unk18 = 1;
    structPtr->unk14 = gUnknown_086233A0[sub_81C76AC()];
    return TRUE;
}

u32 sub_81CEFDC(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    return structPtr->unk0(structPtr);
}

void sub_81CEFF0(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    if (structPtr->unk1C == 0)
        FreePokenavSubstruct(18);
    FreePokenavSubstruct(7);
}

bool32 sub_81CF010(struct PokenavSub7 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->unk0 = sub_81CF030;
    return FALSE;
}

u32 sub_81CF030(struct PokenavSub7 *structPtr)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return 1;
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return 2;
    else if (gMain.newKeys & DPAD_LEFT)
        return 3;
    else if (gMain.newKeys & DPAD_RIGHT)
        return 4;
    else if (gMain.newKeys & B_BUTTON)
    {
        structPtr->unk1C = 0;
        structPtr->unk0 = sub_81CF0B0;
        return 5;
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        structPtr->unkPtr->unk2 = GetSelectedMatchCall();
        structPtr->unk1C = 1;
        structPtr->unk0 = sub_81CF0B8;
        return 6;
    }
    else
        return 0;
}

u32 sub_81CF0B0(struct PokenavSub7 *structPtr)
{
    return 0x186A3;
}

u32 sub_81CF0B8(struct PokenavSub7 *structPtr)
{
    return 0x186A9;
}

u32 sub_81CF0C0(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    return structPtr->unk18;
}

struct PokenavMonList * sub_81CF0D0(void)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    return ptr->unkPtr->unk4;
}

u16 sub_81CF0E0(void)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    return ptr->unkPtr->unk0;
}

u16 sub_81CF0F0(void)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    s32 i = GetSelectedMatchCall();
    return ptr->unkPtr->unk4[i].unk6;
}

u16 sub_81CF10C(void)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    return ptr->unkPtr->unk2;
}

u32 sub_81CF11C(s32 state)
{
    return gUnknown_086233B4[state](state);
}

u32 sub_81CF134(s32 state)
{
    s32 i;
    struct PokenavMonList item;
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);

    ptr->unkPtr->unk0 = 0;
    ptr->unkPtr->unk2 = 0;
    item.boxId = 14;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon * pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG))
        {
            item.monId = i;
            item.unk6 = GetMonData(pokemon, ptr->unk14);
            sub_81CF2C4(ptr, &item);
        }
    }

    return LT_INC_AND_CONTINUE;
}

u32 sub_81CF1C4(s32 state)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    ptr->unk10 = 0;
    ptr->unkC = 0;
    return LT_INC_AND_CONTINUE;
}

u32 sub_81CF1D8(s32 state)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    s32 boxId = ptr->unkC;
    s32 monId = ptr->unk10;
    s32 boxCount = 0;
    struct PokenavMonList item;

    while (boxId < TOTAL_BOXES_COUNT)
    {
        while (monId < IN_BOX_COUNT)
        {
            if (CheckBoxMonSanityAt(boxId, monId))
            {
                item.boxId = boxId;
                item.monId = monId;
                item.unk6 = GetBoxMonDataAt(boxId, monId, ptr->unk14);
                sub_81CF2C4(ptr, &item);
            }
            boxCount++;
            monId++;
            if (boxCount > 14)
            {
                ptr->unkC = boxId;
                ptr->unk10 = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    return LT_INC_AND_CONTINUE;
}

u32 sub_81CF278(s32 state)
{
    struct PokenavSub7 * ptr = (struct PokenavSub7 *)GetSubstructPtr(7);
    s32 r6 = ptr->unkPtr->unk0;
    s32 r4 = ptr->unkPtr->unk4[0].unk6;
    s32 i;
    ptr->unkPtr->unk4[0].unk6 = 1;
    for (i = 1; i < r6; i++)
    {
        if (ptr->unkPtr->unk4[i].unk6 == r4)
        {
            ptr->unkPtr->unk4[i].unk6 = ptr->unkPtr->unk4[i - 1].unk6;
        }
        else
        {
            r4 = ptr->unkPtr->unk4[i].unk6;
            ptr->unkPtr->unk4[i].unk6 = i + 1;
        }
    }
    ptr->unk18 = 1;
    return LT_FINISH;
}

void sub_81CF2C4(struct PokenavSub7 *structPtr, struct PokenavMonList *item)
{
    u32 left = 0;
    u32 right = structPtr->unkPtr->unk0;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->unk6 > structPtr->unkPtr->unk4[insertionIdx].unk6)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = structPtr->unkPtr->unk0; right > insertionIdx; right--)
        structPtr->unkPtr->unk4[right] = structPtr->unkPtr->unk4[right - 1];
    structPtr->unkPtr->unk4[insertionIdx] = *item;
    structPtr->unkPtr->unk0++;
}

// PokenavSub8

struct PokenavSub8
{
    bool32 (*callback)(void);
    u32 ltid;
    u8 winid;
    bool32 unkC;
    u16 buff[0x400];
}; // size: 0x810

bool32 sub_81CF3E4(void);
u32 sub_81CF418(s32 state);

bool32 sub_81CF330(void)
{
    struct PokenavSub8 * unk = AllocSubstruct(8, sizeof(struct PokenavSub8));
    if (unk == NULL)
        return FALSE;
    unk->ltid = CreateLoopedTask(sub_81CF418, 1);
    unk->callback = sub_81CF3E4;
    unk->unkC = FALSE;
    return TRUE;
}

bool32 sub_81CF368(void)
{
    struct PokenavSub8 * unk = AllocSubstruct(8, sizeof(struct PokenavSub8));
    if (unk == NULL)
        return FALSE;
    unk->ltid = CreateLoopedTask(sub_81CF418, 1);
    unk->callback = sub_81CF3E4;
    unk->unkC = TRUE;
    return TRUE;
}

void sub_81CF3A0(s32 idx)
{
    struct PokenavSub8 * unk = (struct PokenavSub8 *)GetSubstructPtr(8);
    unk->ltid = CreateLoopedTask(gUnknown_08623598[idx], 1);
    unk->callback = sub_81CF3E4;
}

bool32 sub_81CF3D0(void)
{
    struct PokenavSub8 * unk = (struct PokenavSub8 *)GetSubstructPtr(8);
    return unk->callback();
}

bool32 sub_81CF3E4(void)
{
    struct PokenavSub8 * unk = (struct PokenavSub8 *)GetSubstructPtr(8);
    return IsLoopedTaskActive(unk->ltid);
}

void sub_81CF3F8(void)
{
    struct PokenavSub8 * unk = (struct PokenavSub8 *)GetSubstructPtr(8);
    sub_81C8234();
    RemoveWindow(unk->winid);
    FreePokenavSubstruct(8);
}
