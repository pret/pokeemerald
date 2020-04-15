#include "global.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "pokenav.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/songs.h"

struct PokenavSub13
{
    u8 filler0[0x8];
    struct PokenavSub18 *field_8;
    u16 field_C;
    u16 field_E;
    u16 field_10;
    u16 field_12;
    u32 field_14[25];
    u32 field_78[8];
    u32 (*field_98)(struct PokenavSub13 *structPtr);
};

struct PokenavSub14
{
    u32 (*field_0)(void);
    u32 loopedTaskId;
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
    u16 field_10;
    struct Sprite *field_14;
    u32 filler;
    u8 tilemapBuffers[2][BG_SCREEN_SIZE];
};

static u32 gUnknown_030012C0;
static u32 gUnknown_030012C4;

void sub_81D0E84(struct PokenavSub14 *structPtr);
void sub_81D0FF0(struct PokenavSub14 *structPtr);
void sub_81D10D0(struct PokenavSub14 *structPtr);
void sub_81D1500(struct PokenavSub14 *structPtr);
void sub_81D0EFC(struct PokenavSub14 *structPtr);
void sub_81D1148(struct PokenavSub14 *structPtr);
void sub_81D10A4(struct PokenavSub14 *structPtr);
void sub_81D1178(struct PokenavSub14 *structPtr);
void sub_81D11D8(struct PokenavSub14 *structPtr);
void sub_81D11FC(struct PokenavSub14 *structPtr);
void sub_81D0E60(struct PokenavSub14 *structPtr);
void sub_81D1448(struct PokenavSub14 *structPtr);
void sub_81D13FC(struct PokenavSub14 *structPtr);
void sub_81D0FCC(struct PokenavSub14 *structPtr);
void sub_81D12D8(struct PokenavSub14 *structPtr);
bool32 sub_81D1524(struct PokenavSub14 *structPtr);
bool32 sub_81D1234(struct PokenavSub14 *structPtr);
void sub_81D0814(struct PokenavSub13 *structPtr);
u32 sub_81D0548(struct PokenavSub13 *structPtr);
u32 sub_81D04C4(struct PokenavSub13 *structPtr);
u32 sub_81D05D4(struct PokenavSub13 *structPtr);
bool32 sub_81D05DC(struct PokenavSub13 *structPtr);
bool32 sub_81D0688(struct PokenavSub13 *structPtr);
bool32 sub_81D0664(struct PokenavSub13 *structPtr);
bool32 sub_81D061C(struct PokenavSub13 *structPtr);
bool32 sub_81D0688(struct PokenavSub13 *structPtr);
bool32 sub_81D0A58(void);
u32 sub_81D06C4(void);
u32 sub_81D06D4(void);
u16 sub_81D1184(s32 unused0, s32 unused1);
void sub_81D1258(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3);
void sub_81D1284(struct Sprite *sprite);
void sub_81D1350(void);
void sub_81D13BC(u16 *dst, u32 id);
void sub_81D1370(u32 arg0, u32 id);
void sub_81D1538(struct Sprite *sprite);
u32 sub_81D0A6C(s32 state);
u32 sub_81D0C84(s32 state);
u32 sub_81D0D2C(s32 state);
u32 sub_81D0D8C(s32 state);
u32 sub_81D0E00(s32 state);
u32 sub_81D0C54(s32 state);

struct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} static  const gUnknown_086237F8[] =
{
    {1, 1, 0, 0},
    {3, 4, 1, 0},
    {3, 4, 5, 0},
    {3, 4, 9, 0},
    {3, 4, 13, 0},
    {3, 4, 17, 0},
    {1, 1, 21, 0},
    {1, 1, 22, 0},
    {1, 1, 23, 0},
    {1, 1, 24, 0},
    {1, 1, 25, 1},
    {1, 1, 26, 1},
    {1, 1, 27, 1},
    {1, 1, 28, 1},
    {1, 1, 29, 1},
    {1, 1, 30, 1},
    {1, 1, 31, 1}
};

#include "data/text/ribbon_descriptions.h"
#include "data/text/gift_ribbon_descriptions.h"

static const u16 gUnknown_08623FF8[] = INCBIN_U16("graphics/pokenav/ribbons_icon1.gbapal");
static const u16 gUnknown_08624018[] = INCBIN_U16("graphics/pokenav/ribbons_icon2.gbapal");
static const u16 gUnknown_08624038[] = INCBIN_U16("graphics/pokenav/ribbons_icon3.gbapal");
static const u16 gUnknown_08624058[] = INCBIN_U16("graphics/pokenav/ribbons_icon4.gbapal");
static const u16 gUnknown_08624078[] = INCBIN_U16("graphics/pokenav/ribbons_icon5.gbapal");
static const u16 gUnknown_08624098[] = INCBIN_U16("graphics/pokenav/8624098.gbapal");
static const u32 sRibbonIconsSmall_Gfx[] = INCBIN_U32("graphics/pokenav/ribbons_icon.4bpp.lz");
static const u32 sRibbonIconsBig_Gfx[] = INCBIN_U32("graphics/pokenav/ribbons_icon_big.4bpp.lz");

static const struct BgTemplate gUnknown_08624B98[] =
{
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x07,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

static const LoopedTask gUnknown_08624BA0[] =
{
    NULL,
    sub_81D0C84,
    sub_81D0D2C,
    sub_81D0D8C,
    sub_81D0E00,
    sub_81D0C54
};

// code
bool32 PokenavCallback_Init_13(void)
{
    struct PokenavSub13 *structPtr = AllocSubstruct(13, sizeof(struct PokenavSub13));
    if (structPtr == NULL)
        return FALSE;

    structPtr->field_8 = GetSubstructPtr(18);
    if (structPtr->field_8 == NULL)
        return FALSE;

    sub_81D0814(structPtr);
    structPtr->field_98 = sub_81D04C4;
    gKeyRepeatContinueDelay = 3;
    gKeyRepeatStartDelay = 10;
    return TRUE;
}

u32 sub_81D04A0(void)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    return structPtr->field_98(structPtr);
}

void sub_81D04B8(void)
{
    FreePokenavSubstruct(13);
}

u32 sub_81D04C4(struct PokenavSub13 *structPtr)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP && structPtr->field_8->unk2 != 0)
    {
        structPtr->field_8->unk2--;
        structPtr->field_C = 0;
        sub_81D0814(structPtr);
        return 1;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN && structPtr->field_8->unk2 < structPtr->field_8->unk0 - 1)
    {
        structPtr->field_8->unk2++;
        structPtr->field_C = 0;
        sub_81D0814(structPtr);
        return 1;
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        structPtr->field_98 = sub_81D0548;
        return 2;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        structPtr->field_98 = sub_81D05D4;
        return 5;
    }
    return 0;
}

u32 sub_81D0548(struct PokenavSub13 *structPtr)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP && sub_81D05DC(structPtr))
        return 3;
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN && sub_81D061C(structPtr))
        return 3;
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT && sub_81D0664(structPtr))
        return 3;
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT && sub_81D0688(structPtr))
        return 3;
    else if (gMain.newKeys & B_BUTTON)
    {
        structPtr->field_98 = sub_81D04C4;
        return 4;
    }
    return 0;
}

u32 sub_81D05D4(struct PokenavSub13 *structPtr)
{
    return POKENAV_MENU_E;
}

bool32 sub_81D05DC(struct PokenavSub13 *structPtr)
{
    if (structPtr->field_C < 25)
    {
        if (structPtr->field_C <= 8)
            return FALSE;

        structPtr->field_C -= 9;
        return TRUE;
    }
    if (structPtr->field_10 != 0)
    {
        u32 var = structPtr->field_C - 27;
        structPtr->field_C = var + structPtr->field_E;
        if (structPtr->field_C >= structPtr->field_10)
            structPtr->field_C = structPtr->field_10 - 1;
        return TRUE;
    }
    return FALSE;
}

bool32 sub_81D061C(struct PokenavSub13 *structPtr)
{
    if (structPtr->field_C >= 25)
        return FALSE;
    if (structPtr->field_C < structPtr->field_E)
    {
        structPtr->field_C += 9;
        if (structPtr->field_C >= structPtr->field_10)
            structPtr->field_C = structPtr->field_10 - 1;
        return TRUE;
    }
    if (structPtr->field_12 != 0)
    {
        int var = structPtr->field_C - structPtr->field_E;
        if (var >= structPtr->field_12)
            var = structPtr->field_12 - 1;

        structPtr->field_C = var + 27;
        return TRUE;
    }
    return FALSE;
}

bool32 sub_81D0664(struct PokenavSub13 *structPtr)
{
    u16 var = structPtr->field_C % 9;
    if (var != 0)
    {
        structPtr->field_C--;
        return TRUE;
    }

    return FALSE;
}

bool32 sub_81D0688(struct PokenavSub13 *structPtr)
{
    int r1 = structPtr->field_C % 9;

    if (r1 >= 8)
        return FALSE;

    if (structPtr->field_C <= 26)
    {
        if (structPtr->field_C < structPtr->field_10 - 1)
        {
            structPtr->field_C++;
            return TRUE;
        }
    }
    else
    {
        if (r1 < structPtr->field_12 - 1)
        {
            structPtr->field_C++;
            return TRUE;
        }
    }
    return FALSE;
}

u32 sub_81D06C4(void)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    return structPtr->field_8->unk2;
}

u32 sub_81D06D4(void)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    return structPtr->field_8->unk0;
}

static void GetCurrMonInfo1(u8 *nick, u8 *level, u8 *gender)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    struct PokenavSub18 *mons = structPtr->field_8;
    struct PokenavMonList *monInfo = &mons->unk4[mons->unk2];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
    {
        struct Pokemon *mon = &gPlayerParty[monInfo->monId];
        GetMonData(mon, MON_DATA_NICKNAME, nick);
        *level = GetLevelFromMonExp(mon);
        *gender = GetMonGender(mon);
    }
    else
    {
        struct BoxPokemon *boxMon = GetBoxedMonPtr(monInfo->boxId, monInfo->monId);
        *gender = GetBoxMonGender(boxMon);
        *level = GetLevelFromBoxMonExp(boxMon);
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, nick);
    }
    StringGetEnd10(nick);
}

static void GetCurrMonInfo2(u16 *species, u32 *personality, u32 *otId)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    struct PokenavSub18 *mons = structPtr->field_8;
    struct PokenavMonList *monInfo = &mons->unk4[mons->unk2];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
    {
        struct Pokemon *mon = &gPlayerParty[monInfo->monId];
        *species = GetMonData(mon, MON_DATA_SPECIES);
        *personality = GetMonData(mon, MON_DATA_PERSONALITY);
        *otId = GetMonData(mon, MON_DATA_OT_ID);
    }
    else
    {
        struct BoxPokemon *boxMon = GetBoxedMonPtr(monInfo->boxId, monInfo->monId);
        *species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
        *personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
        *otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
    }
}

static u32 GetCurrMonRibbonCount(void)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    struct PokenavSub18 *mons = structPtr->field_8;
    struct PokenavMonList *monInfo = &mons->unk4[mons->unk2];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
        return GetMonData(&gPlayerParty[monInfo->monId], MON_DATA_RIBBON_COUNT);
    else
        return GetBoxMonDataAt(monInfo->boxId, monInfo->monId, MON_DATA_RIBBON_COUNT);
}

void sub_81D0814(struct PokenavSub13 *structPtr)
{
    u32 ribbons;
    s32 i, j;
    struct PokenavSub18 *mons = structPtr->field_8;
    struct PokenavMonList *monInfo = &mons->unk4[mons->unk2];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
        ribbons = GetMonData(&gPlayerParty[monInfo->monId], MON_DATA_RIBBONS);
    else
        ribbons = GetBoxMonDataAt(monInfo->boxId, monInfo->monId, MON_DATA_RIBBONS);

    structPtr->field_10 = 0;
    structPtr->field_12 = 0;
    for (i = 0; i < ARRAY_COUNT(gUnknown_086237F8); i++)
    {
        s32 r4 = ((1 << gUnknown_086237F8[i].unk0) - 1) & ribbons;
        if (gUnknown_086237F8[i].unk3 == 0)
        {
            for (j = 0; j < r4; j++)
                structPtr->field_14[structPtr->field_10++] = gUnknown_086237F8[i].unk2 + j;
        }
        else
        {
            for (j = 0; j < r4; j++)
                structPtr->field_78[structPtr->field_12++] = gUnknown_086237F8[i].unk2 + j;
        }
        ribbons >>= gUnknown_086237F8[i].unk0;
    }

    if (structPtr->field_10 != 0)
    {
        structPtr->field_E = ((structPtr->field_10 - 1) / 9) * 9;
        structPtr->field_C = 0;
    }
    else
    {
        structPtr->field_E = 0;
        structPtr->field_C = 27;
    }
}

u32 *sub_81D0914(u32 *arg0)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    *arg0 = structPtr->field_10;
    return structPtr->field_14;
}

u32 *sub_81D092C(u32 *arg0)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    *arg0 = structPtr->field_12;
    return structPtr->field_78;
}

u16 sub_81D0944(void)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    return structPtr->field_C;
}

u32 sub_81D0954(void)
{
    struct PokenavSub13 *structPtr = GetSubstructPtr(13);
    int var = structPtr->field_C;
    if (var <= 24)
        return structPtr->field_14[var];
    else
        return structPtr->field_78[var - 27];
}

bool32 sub_81D0978(void)
{
    struct PokenavSub14 *structPtr = AllocSubstruct(14, sizeof(struct PokenavSub14));
    if (structPtr == NULL)
        return FALSE;

    structPtr->loopedTaskId = CreateLoopedTask(sub_81D0A6C, 1);
    structPtr->field_0 = sub_81D0A58;
    return TRUE;
}

void sub_81D09B0(s32 id)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    structPtr->loopedTaskId = CreateLoopedTask(gUnknown_08624BA0[id], 1);
    structPtr->field_0 = sub_81D0A58;
}

u32 sub_81D09E0(void)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    return structPtr->field_0();
}

void sub_81D09F4(void)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    RemoveWindow(structPtr->field_A);
    RemoveWindow(structPtr->field_8);
    RemoveWindow(structPtr->field_C);
    RemoveWindow(structPtr->field_E);
    sub_81D1178(structPtr);
    FreeSpriteTilesByTag(9);
    FreeSpritePaletteByTag(0xF);
    FreeSpritePaletteByTag(0x10);
    FreeSpritePaletteByTag(0x11);
    FreeSpritePaletteByTag(0x12);
    FreeSpritePaletteByTag(0x13);
    FreeSpriteOamMatrix(structPtr->field_14);
    DestroySprite(structPtr->field_14);
    FreePokenavSubstruct(14);
}

bool32 sub_81D0A58(void)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    return IsLoopedTaskActive(structPtr->loopedTaskId);
}

u32 sub_81D0A6C(s32 state)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    switch (state)
    {
    case 0:
        InitBgTemplates(gUnknown_08624B98, ARRAY_COUNT(gUnknown_08624B98));
        decompress_and_copy_tile_data_to_vram(2, gUnknown_08DDE030, 0, 0, 0);
        SetBgTilemapBuffer(2, structPtr->tilemapBuffers[0]);
        CopyToBgTilemapBuffer(2, gUnknown_08DDE12C, 0, 0);
        CopyPaletteIntoBufferUnfaded(gUnknown_08DDE010, 0x10, 0x20);
        CopyBgTilemapBufferToVram(2);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!free_temp_tile_data_buffers_if_possible())
        {
            sub_8199DF0(1, 0, 0, 1);
            decompress_and_copy_tile_data_to_vram(1, sRibbonIconsSmall_Gfx, 0, 1, 0);
            SetBgTilemapBuffer(1, structPtr->tilemapBuffers[1]);
            FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
            CopyPaletteIntoBufferUnfaded(gUnknown_08623FF8, 0x20, 0xA0);
            CopyPaletteIntoBufferUnfaded(gUnknown_08624098, 0xA0, 0x20);
            CopyBgTilemapBufferToVram(1);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (!free_temp_tile_data_buffers_if_possible())
        {
            sub_81D0E60(structPtr);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (!free_temp_tile_data_buffers_if_possible())
        {
            sub_81D0FCC(structPtr);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 4:
        if (!free_temp_tile_data_buffers_if_possible())
        {
            sub_81D10A4(structPtr);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CopyBgTilemapBufferToVram(2);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_81D1148(structPtr);
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 7:
        sub_81D12D8(structPtr);
        PrintHelpBarText(HELPBAR_RIBBONS_LIST);
        return LT_INC_AND_PAUSE;
    case 8:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_81D13FC(structPtr);
            ChangeBgX(1, 0, 0);
            ChangeBgY(1, 0, 0);
            ChangeBgX(2, 0, 0);
            ChangeBgY(2, 0, 0);
            ShowBg(1);
            ShowBg(2);
            HideBg(3);
            PokenavFadeScreen(1);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 9:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        return LT_FINISH;
    }
    return LT_FINISH;
}

u32 sub_81D0C54(s32 state)
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
        return LT_FINISH;
    }
    return LT_FINISH;
}

u32 sub_81D0C84(s32 state)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81D11D8(structPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!sub_81D1234(structPtr))
        {
            sub_81D0FF0(structPtr);
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 2:
        sub_81D12D8(structPtr);
        return LT_INC_AND_CONTINUE;
    case 3:
        sub_81D10D0(structPtr);
        return LT_INC_AND_CONTINUE;
    case 4:
        sub_81D0E84(structPtr);
        return LT_INC_AND_CONTINUE;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_81D11FC(structPtr);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 6:
        if (sub_81D1234(structPtr))
            return LT_PAUSE;
        return LT_FINISH;
    }
    return LT_FINISH;
}

u32 sub_81D0D2C(s32 state)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81D1448(structPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!sub_81D1524(structPtr))
        {
            sub_81D0EFC(structPtr);
            PrintHelpBarText(HELPBAR_RIBBONS_CHECK);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
    }
    return LT_FINISH;
}

u32 sub_81D0D8C(s32 state)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81D1500(structPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!sub_81D1524(structPtr))
        {
            sub_81D1448(structPtr);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (!sub_81D1524(structPtr))
        {
            sub_81D0EFC(structPtr);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
    }
    return LT_FINISH;
}

u32 sub_81D0E00(s32 state)
{
    struct PokenavSub14 *structPtr = GetSubstructPtr(14);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81D1500(structPtr);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!sub_81D1524(structPtr))
        {
            sub_81D0E84(structPtr);
            PrintHelpBarText(HELPBAR_RIBBONS_LIST);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
    }
    return LT_FINISH;
}

static const struct WindowTemplate gUnknown_08624BB8 =
{
    .bg = 2,
    .tilemapLeft = 12,
    .tilemapTop = 13,
    .width = 16,
    .height = 4,
    .paletteNum = 1,
    .baseBlock = 0x14,
};

void sub_81D0E60(struct PokenavSub14 *structPtr)
{
    structPtr->field_A = AddWindow(&gUnknown_08624BB8);
    PutWindowTilemap(structPtr->field_A);
    sub_81D0E84(structPtr);
}

void sub_81D0E84(struct PokenavSub14 *structPtr)
{
    u8 color[] = {TEXT_COLOR_RED, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};

    ConvertIntToDecimalStringN(gStringVar1, GetCurrMonRibbonCount(), STR_CONV_MODE_LEFT_ALIGN, 2);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_RibbonsF700);
    FillWindowPixelBuffer(structPtr->field_A, PIXEL_FILL(4));
    AddTextPrinterParameterized3(structPtr->field_A, 1, 0, 1, color, -1, gStringVar4);
    CopyWindowToVram(structPtr->field_A, 2);
}

void sub_81D0EFC(struct PokenavSub14 *structPtr)
{
    s32 i;
    u32 ribbonId = sub_81D0954();
    u8 color[] = {TEXT_COLOR_RED, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};

    FillWindowPixelBuffer(structPtr->field_A, PIXEL_FILL(4));
    if (ribbonId < 25)
    {
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(structPtr->field_A, 1, 0, (i * 16) + 1, color, -1, gRibbonDescriptionPointers[ribbonId][i]);
    }
    else
    {
        ribbonId = gSaveBlock1Ptr->giftRibbons[ribbonId - 25];
        if (ribbonId == 0)
            return;

        ribbonId--;
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(structPtr->field_A, 1, 0, (i * 16) + 1, color, -1, gGiftRibbonDescriptionPointers[ribbonId][i]);
    }

    CopyWindowToVram(structPtr->field_A, 2);
}

static const struct WindowTemplate gUnknown_08624BC4 =
{
    .bg = 2,
    .tilemapLeft = 14,
    .tilemapTop = 1,
    .width = 13,
    .height = 2,
    .paletteNum = 10,
    .baseBlock = 0x54,
};

void sub_81D0FCC(struct PokenavSub14 *structPtr)
{
    structPtr->field_8 = AddWindow(&gUnknown_08624BC4);
    PutWindowTilemap(structPtr->field_8);
    sub_81D0FF0(structPtr);
}

static const u8 sMaleIconString[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_RED}{WHITE}{GREEN}♂{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sFemaleIconString[] = _("{COLOR_HIGHLIGHT_SHADOW}{LIGHT_GREEN}{WHITE}{BLUE}♀{COLOR_HIGHLIGHT_SHADOW}{DARK_GREY}{WHITE}{LIGHT_GREY}");
static const u8 sGenderlessIconString[] = _("{UNK_SPACER}");

void sub_81D0FF0(struct PokenavSub14 *structPtr)
{
    const u8 *genderTxt;
    u8 *txtPtr;
    u8 level, gender;
    u16 windowId = structPtr->field_8;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    GetCurrMonInfo1(gStringVar3, &level, &gender);
    AddTextPrinterParameterized(windowId, 1, gStringVar3, 0, 1, TEXT_SPEED_FF, NULL);
    switch (gender)
    {
    case MON_MALE:
        genderTxt = sMaleIconString;
        break;
    case MON_FEMALE:
        genderTxt = sFemaleIconString;
        break;
    default:
        genderTxt = sGenderlessIconString;
        break;
    }

    txtPtr = StringCopy(gStringVar1, genderTxt);
    *(txtPtr++) = CHAR_SLASH;
    *(txtPtr++) = CHAR_SPECIAL_F9;
    *(txtPtr++) = CHAR_LV_2;
    ConvertIntToDecimalStringN(txtPtr, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, 1, gStringVar1, 60, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(windowId, 2);
}

static const struct WindowTemplate gUnknown_08624BE8[] =
{
    {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 5,
        .width = 7,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 0x6E,
    },
    {},
};

void sub_81D10A4(struct PokenavSub14 *structPtr)
{
    structPtr->field_C = AddWindow(gUnknown_08624BE8);
    FillWindowPixelBuffer(structPtr->field_C, PIXEL_FILL(1));
    PutWindowTilemap(structPtr->field_C);
    sub_81D10D0(structPtr);
}

void sub_81D10D0(struct PokenavSub14 *structPtr)
{
    s32 x;
    u8 *txtPtr;
    u32 id = sub_81D06C4() + 1;
    u32 count = sub_81D06D4();

    txtPtr = ConvertIntToDecimalStringN(gStringVar1, id, STR_CONV_MODE_RIGHT_ALIGN, 3);
    *(txtPtr++) = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, count, STR_CONV_MODE_RIGHT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 56);
    AddTextPrinterParameterized(structPtr->field_C, 1, gStringVar1, x, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(structPtr->field_C, 2);
}

void sub_81D1148(struct PokenavSub14 *structPtr)
{
    u16 species;
    u32 personality, otId;

    GetCurrMonInfo2(&species, &personality, &otId);
    ResetAllPicSprites();
    structPtr->field_10 = sub_81D1184(40, 104);
    sub_81C7990(15, 0);
}

void sub_81D1178(struct PokenavSub14 *structPtr)
{
    FreeAndDestroyMonPicSprite(structPtr->field_10);
}

u16 sub_81D1184(s32 unused0, s32 unused1)
{
    u16 species, spriteId;
    u32 personality, otId;

    GetCurrMonInfo2(&species, &personality, &otId);
    spriteId = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, 40, 104, 15, 0xFFFF);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

void sub_81D11D8(struct PokenavSub14 *structPtr)
{
    sub_81D1258(&gSprites[structPtr->field_10], 40, -32, 6);
}

void sub_81D11FC(struct PokenavSub14 *structPtr)
{
    FreeAndDestroyMonPicSprite(structPtr->field_10);
    structPtr->field_10 = sub_81D1184(-32, 104);
    sub_81D1258(&gSprites[structPtr->field_10], -32, 40, 6);
}

bool32 sub_81D1234(struct PokenavSub14 *structPtr)
{
    return (gSprites[structPtr->field_10].callback != SpriteCallbackDummy);
}

void sub_81D1258(struct Sprite *sprite, s32 arg1, s32 arg2, s32 arg3)
{
    u32 var = arg2 - arg1;

    sprite->pos1.x = arg1;
    sprite->data[0] = arg1 << 4;
    sprite->data[1] = (var << 4) / arg3;
    sprite->data[2] = arg3;
    sprite->data[3] = arg2;

    sprite->callback = sub_81D1284;
}

void sub_81D1284(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
    {
        sprite->data[2]--;
        sprite->data[0] += sprite->data[1];
        sprite->pos1.x = sprite->data[0] >> 4;
        if (sprite->pos1.x <= -32)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->pos1.x = sprite->data[3];
        sprite->callback = SpriteCallbackDummy;
    }
}

void sub_81D12D8(struct PokenavSub14 *structPtr)
{
    u32 *ptr;

    sub_81D1350();

    ptr = sub_81D0914(&gUnknown_030012C0);
    for (gUnknown_030012C4 = 0; gUnknown_030012C4 < gUnknown_030012C0; gUnknown_030012C4++)
        sub_81D1370(gUnknown_030012C4, *(ptr++));

    ptr = sub_81D092C(&gUnknown_030012C0);
    for (gUnknown_030012C4 = 0; gUnknown_030012C4 < gUnknown_030012C0; gUnknown_030012C4++)
        sub_81D1370(gUnknown_030012C4 + 27, *(ptr++));

    CopyBgTilemapBufferToVram(1);
}

void sub_81D1350(void)
{
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
}

void sub_81D1370(u32 arg0, u32 id)
{
    u16 bgData[4];
    u32 destX = (arg0 % 9) * 2 + 11;
    u32 destY = (arg0 / 9) * 2 + 4;

    sub_81D13BC(bgData, id);
    CopyToBgTilemapBufferRect(1, bgData, destX, destY, 2, 2);
}

struct
{
    u16 var0;
    u16 var2;
} static const gUnknown_08624BF8[] =
{
    {0, 0},
    {1, 0},
    {2, 0},
    {3, 0},
    {4, 0},
    {1, 1},
    {2, 1},
    {3, 1},
    {4, 1},
    {1, 2},
    {2, 2},
    {3, 2},
    {4, 2},
    {1, 3},
    {2, 3},
    {3, 3},
    {4, 3},
    {1, 4},
    {2, 4},
    {3, 4},
    {4, 4},
    {5, 0},
    {6, 0},
    {7, 1},
    {8, 2},
    {9, 1},
    {9, 3},
    {9, 4},
    {10, 3},
    {10, 4},
    {11, 0},
    {11, 1},
};

void sub_81D13BC(u16 *dst, u32 id)
{
    u16 r3 = gUnknown_08624BF8[id].var2 + 2;
    u16 r1 = (gUnknown_08624BF8[id].var0 * 2) + 1;

    dst[0] = r1 | (r3 << 12);
    dst[1] = r1 | (r3 << 12) |0x400;
    dst[2] = (r1 + 1) | (r3 << 12);
    dst[3] = (r1 + 1) | (r3 << 12) | 0x400;
}

static const struct CompressedSpriteSheet gUnknown_08624C78 =
{
    sRibbonIconsBig_Gfx, 0x1800, 9
};

static const struct SpritePalette gUnknown_08624C80[] =
{
    {gUnknown_08623FF8, 15},
    {gUnknown_08624018, 16},
    {gUnknown_08624038, 17},
    {gUnknown_08624058, 18},
    {gUnknown_08624078, 19},
    {},
};

static const struct OamData sOamData_8624CB0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sSpriteAffineAnim_8624CB8[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8624CC8[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(32, 32, 0, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_8624CE0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-32, -32, 0, 4),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_8624CF8[] =
{
    sSpriteAffineAnim_8624CB8,
    sSpriteAffineAnim_8624CC8,
    sSpriteAffineAnim_8624CE0
};

static const struct SpriteTemplate gUnknown_08624D04 =
{
    .tileTag = 9,
    .paletteTag = 15,
    .oam = &sOamData_8624CB0,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_8624CF8,
    .callback = SpriteCallbackDummy,
};

void sub_81D13FC(struct PokenavSub14 *structPtr)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08624C78);
    Pokenav_AllocAndLoadPalettes(gUnknown_08624C80);

    spriteId = CreateSprite(&gUnknown_08624D04, 0, 0, 0);
    structPtr->field_14 = &gSprites[spriteId];
    structPtr->field_14->invisible = TRUE;
}

void sub_81D1448(struct PokenavSub14 *structPtr)
{
    u32 ribbonId;
    s32 r4 = sub_81D0944();
    s32 r5 = (r4 % 9) * 16 + 96;
    s32 r0 = (r4 / 9) * 16 + 40;

    structPtr->field_14->pos1.x = r5;
    structPtr->field_14->pos1.y = r0;

    ribbonId = sub_81D0954();
    structPtr->field_14->oam.tileNum = (gUnknown_08624BF8[ribbonId].var0 * 16) + GetSpriteTileStartByTag(9);
    structPtr->field_14->oam.paletteNum = IndexOfSpritePaletteTag(gUnknown_08624BF8[ribbonId].var2 + 15);

    StartSpriteAffineAnim(structPtr->field_14, 1);
    structPtr->field_14->invisible = FALSE;
    structPtr->field_14->data[0] = 0;
    structPtr->field_14->callback = sub_81D1538;
}

void sub_81D1500(struct PokenavSub14 *structPtr)
{
    structPtr->field_14->data[0] = 1;
    StartSpriteAffineAnim(structPtr->field_14, 2);
    structPtr->field_14->callback = sub_81D1538;
}

bool32 sub_81D1524(struct PokenavSub14 *structPtr)
{
    return (structPtr->field_14->callback != SpriteCallbackDummy);
}

void sub_81D1538(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sprite->invisible = sprite->data[0];
        sprite->callback = SpriteCallbackDummy;
    }
}
