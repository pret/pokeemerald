#include "global.h"
#include "pokenav.h"
#include "bg.h"
#include "menu.h"
#include "window.h"
#include "sound.h"
#include "dynamic_placeholder_text_util.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "constants/songs.h"

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

struct PokenavSub8
{
    bool32 (*callback)(void);
    u32 ltid;
    u16 winid;
    bool32 unkC;
    u8 buff[BG_SCREEN_SIZE];
}; // size: 0x810

static u32 sub_81CF010(struct PokenavSub7 *structPtr);
static u32 sub_81CF030(struct PokenavSub7 *structPtr);
static u32 sub_81CF0B8(struct PokenavSub7 *structPtr);
static u32 sub_81CF0B0(struct PokenavSub7 *structPtr);
static u32 sub_81CF11C(s32 state);
static u32 sub_81CF134(s32 state);
static u32 sub_81CF1C4(s32 state);
static u32 sub_81CF1D8(s32 state);
static u32 sub_81CF278(s32 state);
static u32 sub_81CF578(s32 state);
static u32 sub_81CF5F0(s32 state);
static u32 sub_81CF668(s32 state);
static u32 sub_81CF6E0(s32 state);
static u32 sub_81CF758(s32 state);
static u32 sub_81CF798(s32 state);
static void sub_81CF2C4(struct PokenavSub7 *structPtr, struct PokenavMonList *item);
static bool32 sub_81CF3E4(void);
static u32 sub_81CF418(s32 state);
static void sub_81CF7C8(struct PokenavSub8 *);
static void sub_81CF7F4(struct PokenavSub8 *);
static void sub_81CF88C(void);
static void sub_81CF8E4(struct PokenavMonList *, u8 *);

static const u32 gUnknown_086233A0[] = {0x16, 0x17, 0x18, 0x21, 0x2F};

static const LoopedTask gUnknown_086233B4[] =
{
    sub_81CF134,
    sub_81CF1C4,
    sub_81CF1D8,
    sub_81CF278
};

static const u16 gUnknown_086233C4[] = INCBIN_U16("graphics/pokenav/condition_search2.gbapal");
static const u32 gUnknown_086233E4[] = INCBIN_U32("graphics/pokenav/condition_search2.4bpp.lz");
static const u32 gUnknown_086234AC[] = INCBIN_U32("graphics/pokenav/condition_search2.bin.lz");
static const u16 gUnknown_08623570[] = INCBIN_U16("graphics/pokenav/8623570.gbapal");

static const struct BgTemplate gUnknown_08623590[] =
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

static const LoopedTask gUnknown_08623598[] = 
{
    NULL,
    sub_81CF578,
    sub_81CF5F0,
    sub_81CF668,
    sub_81CF6E0,
    sub_81CF758,
    sub_81CF798
};

static const struct WindowTemplate gUnknown_086235B4 = 
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

bool32 PokenavCallback_Init_8(void)
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
    structPtr->unk14 = gUnknown_086233A0[GetSelectedConditionSearch()];
    return TRUE;
}

bool32 PokenavCallback_Init_10(void)
{
    struct PokenavSub7 *structPtr = AllocSubstruct(7, sizeof(struct PokenavSub7));
    if (structPtr == NULL)
        return FALSE;

    structPtr->unkPtr = GetSubstructPtr(18);
    structPtr->unk0 = sub_81CF030;
    structPtr->unk18 = 1;
    structPtr->unk14 = gUnknown_086233A0[GetSelectedConditionSearch()];
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

static bool32 sub_81CF010(struct PokenavSub7 *structPtr)
{
    if (!IsLoopedTaskActive(structPtr->loopedTaskId))
        structPtr->unk0 = sub_81CF030;
    return FALSE;
}

static u32 sub_81CF030(struct PokenavSub7 *structPtr)
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

static u32 sub_81CF0B0(struct PokenavSub7 *structPtr)
{
    return POKENAV_CONDITION_SEARCH_MENU;
}

static u32 sub_81CF0B8(struct PokenavSub7 *structPtr)
{
    return POKENAV_MENU_9;
}

static u32 sub_81CF0C0(void)
{
    struct PokenavSub7 *structPtr = GetSubstructPtr(7);
    return structPtr->unk18;
}

static struct PokenavMonList * sub_81CF0D0(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
    return ptr->unkPtr->unk4;
}

static u16 sub_81CF0E0(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
    return ptr->unkPtr->unk0;
}

static s32 sub_81CF0F0(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
    s32 i = GetSelectedMatchCall();
    return ptr->unkPtr->unk4[i].data;
}

static u16 sub_81CF10C(void)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
    return ptr->unkPtr->unk2;
}

static u32 sub_81CF11C(s32 state)
{
    return gUnknown_086233B4[state](state);
}

static u32 sub_81CF134(s32 state)
{
    s32 i;
    struct PokenavMonList item;
    struct PokenavSub7 * ptr = GetSubstructPtr(7);

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
            item.data = GetMonData(pokemon, ptr->unk14);
            sub_81CF2C4(ptr, &item);
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 sub_81CF1C4(s32 state)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
    ptr->unk10 = 0;
    ptr->unkC = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 sub_81CF1D8(s32 state)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
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
                item.data = GetBoxMonDataAt(boxId, monId, ptr->unk14);
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

static u32 sub_81CF278(s32 state)
{
    struct PokenavSub7 * ptr = GetSubstructPtr(7);
    s32 r6 = ptr->unkPtr->unk0;
    s32 r4 = ptr->unkPtr->unk4[0].data;
    s32 i;
    ptr->unkPtr->unk4[0].data = 1;
    for (i = 1; i < r6; i++)
    {
        if (ptr->unkPtr->unk4[i].data == r4)
        {
            ptr->unkPtr->unk4[i].data = ptr->unkPtr->unk4[i - 1].data;
        }
        else
        {
            r4 = ptr->unkPtr->unk4[i].data;
            ptr->unkPtr->unk4[i].data = i + 1;
        }
    }
    ptr->unk18 = 1;
    return LT_FINISH;
}

static void sub_81CF2C4(struct PokenavSub7 *structPtr, struct PokenavMonList *item)
{
    u32 left = 0;
    u32 right = structPtr->unkPtr->unk0;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > structPtr->unkPtr->unk4[insertionIdx].data)
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
    struct PokenavSub8 * unk = GetSubstructPtr(8);
    unk->ltid = CreateLoopedTask(gUnknown_08623598[idx], 1);
    unk->callback = sub_81CF3E4;
}

bool32 sub_81CF3D0(void)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
    return unk->callback();
}

bool32 sub_81CF3E4(void)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
    return IsLoopedTaskActive(unk->ltid);
}

void sub_81CF3F8(void)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
    sub_81C8234();
    RemoveWindow(unk->winid);
    FreePokenavSubstruct(8);
}

static u32 sub_81CF418(s32 state)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
    switch (state)
    {
    case 0:
        InitBgTemplates(gUnknown_08623590, NELEMS(gUnknown_08623590));
        decompress_and_copy_tile_data_to_vram(1, gUnknown_086233E4, 0, 0, 0);
        SetBgTilemapBuffer(1, unk->buff);
        CopyToBgTilemapBuffer(1, gUnknown_086234AC, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(gUnknown_086233C4, 0x10, 0x20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        if (!sub_81CF0C0())
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(gUnknown_08623570, 0x20, 0x20);
        sub_81CF88C();
        return LT_INC_AND_PAUSE;
    case 3:
        if (sub_81C8224())
            return LT_PAUSE;
        sub_81CF7C8(unk);
        PrintHelpBarText(HELPBAR_CONDITION_MON_LIST);
        return LT_INC_AND_PAUSE;
    case 4:
        if (free_temp_tile_data_buffers_if_possible())
            return LT_PAUSE;
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ShowBg(1);
        ShowBg(2);
        HideBg(3);
        if (!unk->unkC)
        {
            u8 r4 = GetSelectedConditionSearch() + POKENAV_MENUITEM_CONDITION_SEARCH_COOL;
            LoadLeftHeaderGfxForIndex(r4);
            sub_81C7FA0(r4, 1, 0);
            sub_81C7FA0(1, 1, 0);
        }
        PokenavFadeScreen(1);
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

static u32 sub_81CF578(s32 state)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
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
        sub_81CF7F4(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81CF5F0(s32 state)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
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
        sub_81CF7F4(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81CF668(s32 state)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
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
        sub_81CF7F4(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81CF6E0(s32 state)
{
    struct PokenavSub8 * unk = GetSubstructPtr(8);
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
        sub_81CF7F4(unk);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 sub_81CF758(s32 state)
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

static u32 sub_81CF798(s32 state)
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

static void sub_81CF7C8(struct PokenavSub8 * ptr)
{
    ptr->winid = AddWindow(&gUnknown_086235B4);
    PutWindowTilemap(ptr->winid);
    CopyWindowToVram(ptr->winid, 1);
    sub_81CF7F4(ptr);
}

static void sub_81CF7F4(struct PokenavSub8 * ptr)
{
    s32 r7 = sub_81CF0F0();
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    *gStringVar1 = EOS;
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar2, gText_NumberF700);
    AddTextPrinterParameterized(ptr->winid, 1, gStringVar2, 4, 1, 0xFF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, r7, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(ptr->winid, 1, gStringVar1, 34, 1, 0xFF, NULL);
    CopyWindowToVram(ptr->winid, 2);
}

static void sub_81CF88C(void)
{
    struct PokenavListTemplate template;
    template.list.monList = sub_81CF0D0();
    template.unk4 = sub_81CF0E0();
    template.unk8 = 4;
    template.unk6 = sub_81CF10C();
    template.unk9 = 13;
    template.unkA = 17;
    template.unkB = 1;
    template.unkC = 8;
    template.unkD = 2;
    template.unkE = 1;
    template.listFunc.unk10_1 = sub_81CF8E4;
    template.unk14 = NULL;
    sub_81C81D4(&gUnknown_08623590[1], &template, 0);
}

static void sub_81CF8E4(struct PokenavMonList * item, u8 * dest)
{
    u8 gender;
    u8 level;
    u8 * s;
    const u8 * genderStr;

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
    sub_81DB494(dest, 1, gStringVar1, 40);
}
