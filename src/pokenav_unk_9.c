#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "window.h"

struct PokenavSub9
{
    u32 (*unk0)(struct PokenavSub9*);
    u32 loopedTaskId;
    u8 filler[0xC];
    u32 unk14;
    u32 unk18;
    struct PokenavSub18 *unk1C;
};

u32 sub_81CFA68(struct PokenavSub9 *structPtr);
u32 sub_81CFA88(struct PokenavSub9 *structPtr);
u32 sub_81CFB08(struct PokenavSub9 *structPtr);
u32 sub_81CFB10(struct PokenavSub9 *structPtr);
u32 sub_81CFB8C(void);
u32 sub_81CFC2C(void);
u32 sub_81CFC40(void);
u32 sub_81CFB74(s32 state);
u32 sub_81CFFFC(s32 state);
u32 sub_81D0074(s32 state);
u32 sub_81D00EC(s32 state);
u32 sub_81D0164(s32 state);
u32 sub_81D01DC(s32 state);
u32 sub_81D021C(s32 state);

u32 (*const gUnknown_086235D8[])(void) =
{
    sub_81CFB8C,
    sub_81CFC2C,
    sub_81CFC40
};

const u16 gUnknown_086235E4[] = INCBIN_U16("graphics/pokenav/ui_ribbons.gbapal");
const u32 gUnknown_08623604[] = INCBIN_U32("graphics/pokenav/ui_ribbons.4bpp.lz");
const u32 gUnknown_086236CC[] = INCBIN_U32("graphics/pokenav/ui_ribbons.bin.lz");
const u16 gUnknown_08623790[] = INCBIN_U16("graphics/pokenav/8623790.gbapal");

const struct BgTemplate gUnknown_086237B0 =
{
    .bg = 1,
    .charBaseIndex = 1,
    .mapBaseIndex = 0x06,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 2,
    .baseTile = 0
};

const struct BgTemplate gUnknown_086237B4 =
{
    .bg = 2,
    .charBaseIndex = 2,
    .mapBaseIndex = 0x07,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 3,
    .baseTile = 0
};

const LoopedTask gUnknown_086237B8[] =
{
    NULL,
    sub_81CFFFC,
    sub_81D0074,
    sub_81D00EC,
    sub_81D0164,
    sub_81D01DC,
    sub_81D021C
};

const struct WindowTemplate gUnknown_086237D4 =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

const u8 gUnknown_086237DC[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086237E8[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
const u8 gUnknown_086237F4[] = _("{UNK_SPACER}");

bool32 sub_81CF9BC(void)
{
    struct PokenavSub9 *structPtr = AllocSubstruct(9, sizeof(struct PokenavSub9));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unk1C = AllocSubstruct(18, sizeof(struct PokenavSub18));
    if (structPtr->unk1C == NULL)
        return FALSE;

    structPtr->unk0 = sub_81CFA68;
    structPtr->loopedTaskId = CreateLoopedTask(sub_81CFB74, 1);
    structPtr->unk14 = 0;
    return TRUE;
}

bool32 sub_81CFA04(void)
{
    struct PokenavSub9 *structPtr = AllocSubstruct(9, sizeof(struct PokenavSub9));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unk1C = GetSubstructPtr(18);
    structPtr->unk0 = sub_81CFA88;
    structPtr->unk14 = 1;
    return TRUE;
}

u32 sub_81CFA34(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(9);
    return structPtr->unk0(structPtr);
}

void sub_81CFA48(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(9);
    if (!structPtr->unk18)
        FreePokenavSubstruct(18);
    FreePokenavSubstruct(9);
}

u32 sub_81CFA68(struct PokenavSub9 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->unk0 = sub_81CFA88;
    return 0;
}

u32 sub_81CFA88(struct PokenavSub9 *structPtr)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return 1;
    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return 2;
    if (gMain.newKeys & DPAD_LEFT)
        return 3;
    if (gMain.newKeys & DPAD_RIGHT)
        return 4;
    if (gMain.newKeys & B_BUTTON)
    {
        structPtr->unk18 = 0;
        structPtr->unk0 = sub_81CFB08;
        return 5;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        structPtr->unk1C->unk2 = GetSelectedMatchCall();
        structPtr->unk18 = 1;
        structPtr->unk0 = sub_81CFB10;
        return 6;
    }
    return 0;
}

u32 sub_81CFB08(struct PokenavSub9 *structPtr)
{
    return 0x186a5;
}

u32 sub_81CFB10(struct PokenavSub9 *structPtr)
{
    return 0x186ad;
}

u32 sub_81CFB18(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(9);
    return structPtr->unk14;
}
