#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "menu.h"
#include "window.h"
#include "sound.h"
#include "string_util.h"
#include "international_string_util.h"
#include "constants/songs.h"

struct PokenavSub9
{
    u32 (*unk0)(struct PokenavSub9*);
    u32 loopedTaskId;
    u16 winid;
    s32 unkC;
    s32 unk10;
    u32 unk14;
    u32 unk18;
    struct PokenavSub18 *unk1C;
};

struct PokenavSub10
{
    bool32 (*callback)(void);
    u32 ltid;
    u16 winid;
    bool32 unkC;
    u8 buff[BG_SCREEN_SIZE];
};

static u32 sub_81CFA68(struct PokenavSub9 *structPtr);
static u32 sub_81CFA88(struct PokenavSub9 *structPtr);
static u32 sub_81CFB08(struct PokenavSub9 *structPtr);
static u32 sub_81CFB10(struct PokenavSub9 *structPtr);
static u32 sub_81CFB8C(s32 state);
static u32 sub_81CFC2C(s32 state);
static u32 sub_81CFC40(s32 state);
static u32 sub_81CFB74(s32 state);
static void sub_81CFCEC(struct PokenavSub9 *structPtr, struct PokenavMonList *item);
static u32 sub_81CFEB8(s32 state);
static bool32 sub_81CFE84(void);
static u32 sub_81CFFFC(s32 state);
static u32 sub_81D0074(s32 state);
static u32 sub_81D00EC(s32 state);
static u32 sub_81D0164(s32 state);
static u32 sub_81D01DC(s32 state);
static u32 sub_81D021C(s32 state);
static void sub_81D02B0(s32 windowId, s32 val1, s32 val2);
static void sub_81D024C(struct PokenavSub10 *ptr);
static void sub_81D0288(struct PokenavSub10 *ptr);
static void sub_81D0304(void);
static void BufferRibbonMonInfoText(struct PokenavMonList *, u8 *);

static const LoopedTask gUnknown_086235D8[] =
{
    sub_81CFB8C,
    sub_81CFC2C,
    sub_81CFC40
};

static const u16 gUnknown_086235E4[] = INCBIN_U16("graphics/pokenav/ui_ribbons.gbapal");
static const u32 gUnknown_08623604[] = INCBIN_U32("graphics/pokenav/ui_ribbons.4bpp.lz");
static const u32 gUnknown_086236CC[] = INCBIN_U32("graphics/pokenav/ui_ribbons.bin.lz");
static const u16 gUnknown_08623790[] = INCBIN_U16("graphics/pokenav/8623790.gbapal");

static const struct BgTemplate gUnknown_086237B0[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x07,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const LoopedTask gUnknown_086237B8[] =
{
    NULL,
    sub_81CFFFC,
    sub_81D0074,
    sub_81D00EC,
    sub_81D0164,
    sub_81D01DC,
    sub_81D021C
};

static const struct WindowTemplate gUnknown_086237D4 =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

static const u8 sText_MaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sText_FemaleSymbol[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sText_NoGenderSymbol[] = _("{UNK_SPACER}");

bool32 PokenavCallback_Init_12(void)
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

bool32 PokenavCallback_Init_14(void)
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

static u32 sub_81CFA68(struct PokenavSub9 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->unk0 = sub_81CFA88;
    return 0;
}

static u32 sub_81CFA88(struct PokenavSub9 *structPtr)
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

static u32 sub_81CFB08(struct PokenavSub9 *structPtr)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_RIBBONS;
}

static u32 sub_81CFB10(struct PokenavSub9 *structPtr)
{
    return POKENAV_MENU_D;
}

static u32 sub_81CFB18(void)
{
    struct PokenavSub9 *structPtr = GetSubstructPtr(9);
    return structPtr->unk14;
}

static struct PokenavMonList * sub_81CFB28(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(9);
    return ptr->unk1C->unk4;
}

static s32 sub_81CFB38(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(9);
    return ptr->unk1C->unk0;
}

static s32 sub_81CFB48(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(9);
    s32 idx = GetSelectedMatchCall();
    return ptr->unk1C->unk4[idx].data;
}

static s32 sub_81CFB64(void)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(9);
    return ptr->unk1C->unk2;
}

static u32 sub_81CFB74(s32 state)
{
    return gUnknown_086235D8[state](state);
}

static u32 sub_81CFB8C(s32 state)
{
    s32 i;
    struct PokenavMonList item;
    struct PokenavSub9 * ptr = GetSubstructPtr(9);

    ptr->unk1C->unk0 = 0;
    ptr->unk1C->unk2 = 0;
    item.boxId = TOTAL_BOXES_COUNT;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon * pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG) && !GetMonData(pokemon, MON_DATA_SANITY_IS_BAD_EGG))
        {
            u32 ribbonCount = GetMonData(pokemon, MON_DATA_RIBBON_COUNT);
            if (ribbonCount != 0)
            {
                item.monId = i;
                item.data = ribbonCount;
                sub_81CFCEC(ptr, &item);
            }
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 sub_81CFC2C(s32 state)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(9);
    ptr->unk10 = 0;
    ptr->unkC = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 sub_81CFC40(s32 state)
{
    struct PokenavSub9 * ptr = GetSubstructPtr(9);
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
                u32 ribbonCount = GetBoxMonDataAt(boxId, monId, MON_DATA_RIBBON_COUNT);
                if (ribbonCount != 0)
                {
                    item.boxId = boxId;
                    item.monId = monId;
                    item.data = ribbonCount;
                    sub_81CFCEC(ptr, &item);
                }
            }
            boxCount++;
            monId++;
            if (boxCount > TOTAL_BOXES_COUNT)
            {
                ptr->unkC = boxId;
                ptr->unk10 = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    ptr->unk14 = 1;
    return LT_FINISH;
}

static void sub_81CFCEC(struct PokenavSub9 *structPtr, struct PokenavMonList *item)
{
    u32 left = 0;
    u32 right = structPtr->unk1C->unk0;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > structPtr->unk1C->unk4[insertionIdx].data)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = structPtr->unk1C->unk0; right > insertionIdx; right--)
        structPtr->unk1C->unk4[right] = structPtr->unk1C->unk4[right - 1];
    structPtr->unk1C->unk4[insertionIdx] = *item;
    structPtr->unk1C->unk0++;
}

static bool32 sub_81CFD58(void)
{
    s32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon * mon = &gPlayerParty[i];
        if (!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES))
            continue;
        if (GetMonData(mon, MON_DATA_SANITY_IS_EGG))
            continue;
        if (GetMonData(mon, MON_DATA_RIBBONS))
            return TRUE;
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (!CheckBoxMonSanityAt(i, j))
                continue;
            if (GetBoxMonDataAt(i, j, MON_DATA_RIBBONS))
                return TRUE;
        }
    }

    return FALSE;
}

bool32 sub_81CFDD0(void)
{
    struct PokenavSub10 * ptr = AllocSubstruct(10, sizeof(struct PokenavSub10));
    if (ptr == NULL)
        return FALSE;
    ptr->ltid = CreateLoopedTask(sub_81CFEB8, 1);
    ptr->callback = sub_81CFE84;
    ptr->unkC = FALSE;
    return TRUE;
}

bool32 sub_81CFE08(void)
{
    struct PokenavSub10 * ptr = AllocSubstruct(10, sizeof(struct PokenavSub10));
    if (ptr == NULL)
        return FALSE;
    ptr->ltid = CreateLoopedTask(sub_81CFEB8, 1);
    ptr->callback = sub_81CFE84;
    ptr->unkC = TRUE;
    return TRUE;
}

void sub_81CFE40(s32 idx)
{
    struct PokenavSub10 * ptr = GetSubstructPtr(10);
    ptr->ltid = CreateLoopedTask(gUnknown_086237B8[idx], 1);
    ptr->callback = sub_81CFE84;
}

bool32 sub_81CFE70(void)
{
    struct PokenavSub10 * ptr = GetSubstructPtr(10);
    return ptr->callback();
}

bool32 sub_81CFE84(void)
{
    struct PokenavSub10 * ptr = GetSubstructPtr(10);
    return IsLoopedTaskActive(ptr->ltid);
}

void sub_81CFE98(void)
{
    struct PokenavSub10 * ptr = GetSubstructPtr(10);
    sub_81C8234();
    RemoveWindow(ptr->winid);
    FreePokenavSubstruct(10);
}

static u32 sub_81CFEB8(s32 state)
{
    struct PokenavSub10 * unk = GetSubstructPtr(10);
    switch (state)
    {
    case 0:
        InitBgTemplates(gUnknown_086237B0, NELEMS(gUnknown_086237B0));
        decompress_and_copy_tile_data_to_vram(1, gUnknown_08623604, 0, 0, 0);
        SetBgTilemapBuffer(1, unk->buff);
        CopyToBgTilemapBuffer(1, gUnknown_086236CC, 0, 0);
        CopyPaletteIntoBufferUnfaded(gUnknown_086235E4, 0x10, 0x20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        if (!sub_81CFB18())
            return LT_PAUSE;
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ShowBg(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(gUnknown_08623790, 0x20, 0x20);
        sub_81D0304();
        return LT_INC_AND_PAUSE;
    case 3:
        if (sub_81C8224())
            return LT_PAUSE;
        sub_81D024C(unk);
        return LT_INC_AND_PAUSE;
    case 4:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        ShowBg(2);
        HideBg(3);
        PrintHelpBarText(HELPBAR_RIBBONS_MON_LIST);
        PokenavFadeScreen(1);
        if (!unk->unkC)
        {
            LoadLeftHeaderGfxForIndex(2);
            sub_81C7FA0(2, 1, 0);
        }
        return LT_INC_AND_PAUSE;
    case 5:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (sub_81C8010())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81CFFFC(s32 state)
{
    struct PokenavSub10 * unk = GetSubstructPtr(10);
    switch (state)
    {
    case 0:
        switch (MatchCall_MoveCursorUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (sub_81C8630())
            return LT_PAUSE;
        // fallthrough
    case 2:
        sub_81D0288(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81D0074(s32 state)
{
    struct PokenavSub10 * unk = GetSubstructPtr(10);
    switch (state)
    {
    case 0:
        switch (MatchCall_MoveCursorDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (sub_81C8630())
            return LT_PAUSE;
        // fallthrough
    case 2:
        sub_81D0288(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81D00EC(s32 state)
{
    struct PokenavSub10 * unk = GetSubstructPtr(10);
    switch (state)
    {
    case 0:
        switch (MatchCall_PageUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (sub_81C8630())
            return LT_PAUSE;
        // fallthrough
    case 2:
        sub_81D0288(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81D0164(s32 state)
{
    struct PokenavSub10 * unk = GetSubstructPtr(10);
    switch (state)
    {
    case 0:
        switch (MatchCall_PageDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            PlaySE(SE_SELECT);
            return LT_SET_STATE(2);
        case 2:
            PlaySE(SE_SELECT);
            break;
        }
        return LT_INC_AND_PAUSE;
    case 1:
        if (sub_81C8630())
            return LT_PAUSE;
        // fallthrough
    case 2:
        sub_81D0288(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81D01DC(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(0);
        sub_81C78A0();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        sub_81C7FDC();
        break;
    }
    return LT_FINISH;
}

static u32 sub_81D021C(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(0);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static void sub_81D024C(struct PokenavSub10 * ptr)
{
    s32 r2;
    ptr->winid = AddWindow(&gUnknown_086237D4);
    PutWindowTilemap(ptr->winid);
    r2 = sub_81CFB38();
    sub_81D02B0(ptr->winid, 0, r2);
    CopyWindowToVram(ptr->winid, 1);
    sub_81D0288(ptr);
}

static void sub_81D0288(struct PokenavSub10 * ptr)
{
    s32 r4 = GetSelectedMatchCall();
    s32 r2 = sub_81CFB38();
    sub_81D02B0(ptr->winid, r4 + 1, r2);
    CopyWindowToVram(ptr->winid, 2);
}

static void sub_81D02B0(s32 windowId, s32 val1, s32 val2)
{
    u8 strbuf[16];
    u32 x;

    u8 * ptr = strbuf;
    ptr = ConvertIntToDecimalStringN(ptr, val1, STR_CONV_MODE_RIGHT_ALIGN, 3);
    *ptr++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(ptr, val2, STR_CONV_MODE_RIGHT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, strbuf, 56);
    AddTextPrinterParameterized(windowId, 1, strbuf, x, 1, 0xFF, NULL);
}

static void sub_81D0304(void)
{
    struct PokenavListTemplate template;
    template.list.monList = sub_81CFB28();
    template.unk4 = sub_81CFB38();
    template.unk8 = 4;
    template.unk6 = sub_81CFB64();
    template.unk9 = 13;
    template.unkA = 17;
    template.unkB = 1;
    template.unkC = 8;
    template.unkD = 2;
    template.unkE = 1;
    template.listFunc.unk10_1 = BufferRibbonMonInfoText;
    template.unk14 = NULL;
    sub_81C81D4(&gUnknown_086237B0[1], &template, 0);
}

// Buffers the "Nickname gender/level" text for the ribbon mon list
static void BufferRibbonMonInfoText(struct PokenavMonList * item0, u8 * dest)
{
    u8 gender;
    u8 level;
    u8 * s;
    const u8 * genderStr;
    struct PokenavMonList * item = item0;

    // Mon is in party
    if (item->boxId == TOTAL_BOXES_COUNT)
    {
        struct Pokemon * mon = &gPlayerParty[item->monId];
        gender = GetMonGender(mon);
        level = GetLevelFromMonExp(mon);
        GetMonData(mon, MON_DATA_NICKNAME, gStringVar3);
    }
    // Mon is in PC
    else
    {
        struct BoxPokemon * mon = GetBoxedMonPtr(item->boxId, item->monId);
        gender = GetBoxMonGender(mon);
        level = GetLevelFromBoxMonExp(mon);
        GetBoxMonData(mon, MON_DATA_NICKNAME, gStringVar3);
    }

    StringGetEnd10(gStringVar3);
    dest = sub_81DB494(dest, 1, gStringVar3, 60);
    switch (gender)
    {
    default:
        genderStr = sText_NoGenderSymbol;
        break;
    case MON_MALE:
        genderStr = sText_MaleSymbol;
        break;
    case MON_FEMALE:
        genderStr = sText_FemaleSymbol;
        break;
    }

    s = StringCopy(gStringVar1, genderStr);
    *s++ = CHAR_SLASH;
    *s++ = CHAR_SPECIAL_F9;
    *s++ = CHAR_LV_2;
    ConvertIntToDecimalStringN(s, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    dest = sub_81DB494(dest, 1, gStringVar1, 54);
    ConvertIntToDecimalStringN(dest, item->data, STR_CONV_MODE_RIGHT_ALIGN, 2);
}
