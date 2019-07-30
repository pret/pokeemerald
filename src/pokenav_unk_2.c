#include "global.h"
#include "alloc.h"
#include "decompress.h"
#include "bg.h"
#include "menu.h"
#include "window.h"
#include "pokenav.h"
#include "graphics.h"
#include "sound.h"
#include "constants/songs.h"

// Match Call

struct Pokenav2Struct
{
    bool32 (*callback)(void);
    u32 loopedTaskId;
    u8 field_008;
    u8 field_009;
    u8 field_00a;
    u8 field_00b;
    u8 field_00c;
    u8 field_00d;
    bool32 field_010[6];
    u8 filler_028[4];
    struct Sprite * field_02c[6][4];
    u8 field_08c[0x800];
};

struct Pokenav2Struct * sub_81C9958(void);
bool32 sub_81C99FC(void);
u32 sub_81C9A10(int state);
u32 sub_81C9C6C(int state);
u32 sub_81C9CA8(int state);
u32 sub_81C9D44(int state);
u32 sub_81C9DD8(int state);
u32 sub_81C9E58(int state);
u32 sub_81C9EC8(int state);
u32 sub_81C9EF8(int state);
u32 sub_81C9F28(int state);
void sub_81C9FC4(void);
void sub_81C9FEC(void);
void sub_81CA02C(void);
void sub_81CA094(void);
void sub_81CA0C8(void);
void sub_81CA0EC(const u16 *const * a0, s32 a1, s32 a2);
void sub_81CA20C(void);
void sub_81CA278(void);
void sub_81CA35C(struct Sprite ** sprites, s32 a1, s32 a2, s32 a3);
void sub_81CA3B4(struct Sprite ** sprites);
void sub_81CA448(struct Sprite ** sprites, s32 a1);
void sub_81CA474(struct Sprite * sprite);
void sub_81CA2DC(void);
bool32 sub_81CA324(void);
void sub_81CA640(void);
void sub_81CA698(void);
void sub_81CA6E0(void);
void sub_81CA714(void);
void sub_81CA770(void);
bool32 sub_81CA7C4(void);
void sub_81CA7D4(void);
void sub_81CA7F4(void);
void sub_81CA818(void);
void sub_81CA850(void);
void sub_81CA864(void);
bool32 sub_81CA89C(void);
void titlescreen_0(void);
void sub_81CA994(void);
void sub_81CA9C8(void);
void sub_81CA9D8(void);
void sub_81CAA3C(void);

const u16 gUnknown_0861FC78[] = INCBIN_U16("graphics/pokenav/bg.gbapal");
const u32 gUnknown_0861FC98[] = INCBIN_U32("graphics/pokenav/bg.4bpp.lz");
const u32 gUnknown_0861FCAC[] = INCBIN_U32("graphics/pokenav/bg.bin.lz");
const u16 gUnknown_0861FD4C[] = INCBIN_U16("graphics/pokenav/outline.gbapal");
const u32 gUnknown_0861FD6C[] = INCBIN_U32("graphics/pokenav/outline.4bpp.lz");
const u32 gUnknown_0861FFF4[] = INCBIN_U32("graphics/pokenav/outline_map.bin.lz");
const u16 gUnknown_08620104[] = INCBIN_U16("graphics/pokenav/blue_light.gbapal");
const u32 gUnknown_08620124[] = INCBIN_U32("graphics/pokenav/blue_light.4bpp.lz");

const struct BgTemplate gUnknown_08620194[] = {
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

const LoopedTask gUnknown_086201A0[] = {
    NULL,
    sub_81C9C6C,
    sub_81C9CA8,
    sub_81C9D44,
    sub_81C9DD8,
    sub_81C9E58,
    sub_81C9EC8,
    sub_81C9EF8,
    sub_81C9F28
};

const struct CompressedSpriteSheet gUnknown_086201C4[] = {
    {gPokenavOptions_Gfx, 0x3400, 0x0003},
    {gUnknown_08620124,   0x0100, 0x0001}
};

const struct SpritePalette gUnknown_086201D4[] = {
    {gPokenavOptions_Pal + 0x00, 4},
    {gPokenavOptions_Pal + 0x10, 5},
    {gPokenavOptions_Pal + 0x20, 6},
    {gPokenavOptions_Pal + 0x30, 7},
    {gPokenavOptions_Pal + 0x40, 8},
    {gUnknown_08620104, 3},
    {NULL, 0}
};

struct UnkStruct_08620240
{
    u16 field_0;
    u16 field_2;
    const u16 *field_4[6];
};

extern const struct UnkStruct_08620240 gUnknown_08620240[];

extern const struct SpriteTemplate gUnknown_0862034C;

bool32 sub_81C98D4(void)
{
    s32 i;

    for (i = 0; i < 78; i++)
    {
        if (sub_81CB0C8(i) == gMapHeader.regionMapSectionId
         && sub_81CAE08(i)
         && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    return FALSE;
}

bool32 sub_81C9924(void)
{
    struct Pokenav2Struct * unk = sub_81C9958();

    if (unk == NULL)
        return FALSE;
    
    unk->field_00d = 0;
    return TRUE;
}

bool32 sub_81C9940(void)
{
    struct Pokenav2Struct * unk = sub_81C9958();

    if (unk == NULL)
        return FALSE;

    unk->field_00d = 1;
    return TRUE;
}

struct Pokenav2Struct * sub_81C9958(void)
{
    struct Pokenav2Struct * unk = AllocSubstruct(2, sizeof(struct Pokenav2Struct));

    if (unk != NULL)
    {
        unk->field_00c = 0;
        unk->loopedTaskId = CreateLoopedTask(sub_81C9A10, 1);
        unk->callback = sub_81C99FC;
    }

    return unk;
}


void sub_81C9990(s32 ltIdx)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    unk->loopedTaskId = CreateLoopedTask(gUnknown_086201A0[ltIdx], 1);
    unk->callback = sub_81C99FC;
}

bool32 sub_81C99C0(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    return unk->callback();
}

void sub_81C99D4(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    sub_81CA7F4();
    RemoveWindow(unk->field_008);
    sub_81C9FEC();
    sub_81CA994();
    FreePokenavSubstruct(2);
}

bool32 sub_81C99FC(void)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    return IsLoopedTaskActive(unk->loopedTaskId);
}

u32 sub_81C9A10(int state)
{
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    switch (state)
    {
    case 0:
        InitBgTemplates(gUnknown_08620194, ARRAY_COUNT(gUnknown_08620194));
        decompress_and_copy_tile_data_to_vram(1, gPokenavMessageBox_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(1, unk->field_08c);
        CopyToBgTilemapBuffer(1, gPokenavMessageBox_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(gPokenavMessageBox_Pal, 0x10, 0x20);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        return 0;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return 2;
        decompress_and_copy_tile_data_to_vram(2, gUnknown_0861FD6C, 0, 0, 0);
        decompress_and_copy_tile_data_to_vram(2, gUnknown_0861FFF4, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(gUnknown_0861FD4C, 0x20, 0x20);
        return 0;
    case 2:
        if (free_temp_tile_data_buffers_if_possible())
            return 2;
        decompress_and_copy_tile_data_to_vram(3, gUnknown_0861FC98, 0, 0, 0);
        decompress_and_copy_tile_data_to_vram(3, gUnknown_0861FCAC, 0, 0, 1);
        CopyPaletteIntoBufferUnfaded(gUnknown_0861FC78, 0x30, 0x20);
        if (sub_81C9894() == 3 || sub_81C9894() == 4)
            sub_81CA850();
        return 0;
    case 3:
        if (free_temp_tile_data_buffers_if_possible())
            return 2;
        sub_81CA6E0();
        sub_81CA7D4();
        return 1;
    case 4:
        sub_81C9FC4();
        return 1;
    case 5:
        sub_81CA714();
        sub_81CA02C();
        sub_81CA640();
        sub_81CA0C8();
        return 0;
    case 6:
        if (sub_81CA7C4())
            return 2;
        return 1;
    case 7:
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        if (unk->field_00d)
            sub_81C7AC0(1);
        else
        {
            PlaySE(SE_PN_ON);
            sub_81C7AC0(3);
        }
        switch (sub_81C9894())
        {
        case 4:
            LoadLeftHeaderGfxForIndex(7);
            // fallthrough
        case 3:
            LoadLeftHeaderGfxForIndex(1);
            break;
        default:
            LoadLeftHeaderGfxForIndex(0);
            break;
        }
        return 0;
    case 8:
        if (IsPaletteFadeActive())
            return 2;
        switch (sub_81C9894())
        {
        case 4:
            sub_81C7FA0(7, FALSE, FALSE);
            // fallthrough
        case 3:
            sub_81C7FA0(1, FALSE, FALSE);
            break;
        default:
            sub_81C7FA0(0, FALSE, FALSE);
            break;
        }
        sub_81CA20C();
        titlescreen_0();
        return 1;
    case 9:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81C9C6C(int state)
{
    switch (state)
    {
    case 0:
        sub_81CAA3C();
        sub_81CA278();
        sub_81CA714();
        PlaySE(SE_SELECT);
        return 0;
    case 1:
        if (sub_81CA324())
            return 2;
        if (sub_81CA7C4())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81C9CA8(int state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        sub_81C7FC4(0, 0);
        PlaySE(SE_SELECT);
        return 0;
    case 1:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        sub_81CA0C8();
        LoadLeftHeaderGfxForIndex(1);
        return 0;
    case 2:
        sub_81CA20C();
        sub_81C7FA0(1, FALSE, FALSE);
        sub_81CA818();
        sub_81CA714();
        return 0;
    case 3:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        if (sub_81CA89C())
            return 2;
        if (sub_81CA7C4())
            return 2;
        sub_81CA9D8();
        break;
    }
    return 4;
}

u32 sub_81C9D44(int state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        sub_81C7FC4(1, 0);
        return 0;
    case 1:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        sub_81CA0C8();
        LoadLeftHeaderGfxForIndex(0);
        return 0;
    case 2:
        sub_81CA20C();
        sub_81C7FA0(0, FALSE, FALSE);
        sub_81CA864();
        sub_81CA714();
        return 0;
    case 3:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        if (sub_81CA89C())
            return 2;
        if (sub_81CA7C4())
            return 2;
        sub_81CA9D8();
        break;
    }
    return 4;
}

u32 sub_81C9DD8(int state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        PlaySE(SE_SELECT);
        return 0;
    case 1:
        if (sub_81CA324())
            return 2;
        LoadLeftHeaderGfxForIndex(7);
        sub_81CA0C8();
        return 0;
    case 2:
        sub_81CA20C();
        sub_81C7FA0(7, FALSE, FALSE);
        sub_81CA714();
        return 0;
    case 3:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        if (sub_81CA89C())
            return 2;
        sub_81CA9D8();
        break;
    }
    return 4;
}

u32 sub_81C9E58(int state)
{
    switch (state)
    {
    case 0:
        sub_81CA9C8();
        sub_81CA2DC();
        sub_81C7FC4(7, 0);
        return 0;
    case 1:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        sub_81CA0C8();
        return 0;
    case 2:
        sub_81CA20C();
        sub_81CA714();
        return 0;
    case 3:
        if (sub_81CA324())
            return 2;
        if (sub_81CA89C())
            return 2;
        sub_81CA9D8();
        break;
    }
    return 4;
}

u32 sub_81C9EC8(int state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_HAZURE);
        sub_81CA770();
        return 0;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81C9EF8(int state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        sub_81CA714();
        return 0;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return 2;
        break;
    }
    return 4;
}

u32 sub_81C9F28(int state)
{
    switch (state)
    {
    case 0:
        sub_81C7BA4(sub_81C98C4());
        return 0;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy_())
            return 2;
        sub_81C7880();
        sub_81CA9C8();
        sub_81CA2DC();
        switch (sub_81C9894())
        {
        case 4:
            sub_81C7FC4(7, FALSE);
            // fallthrough
        case 3:
            sub_81C7FC4(1, FALSE);
            break;
        default:
            sub_81C7FC4(0, FALSE);
            break;
        }
        PlaySE(SE_SELECT);
        return 0;
    case 2:
        if (sub_81CA324())
            return 2;
        if (sub_81C8010())
            return 2;
        sub_81C7AC0(0);
        return 0;
    case 3:
        if (IsPaletteFadeActive())
            return 2;
        break;
    }
    return 4;
}

void sub_81C9FC4(void)
{
    u32 i;

    for (i = 0; i < 2; i++)
        LoadCompressedSpriteSheet(&gUnknown_086201C4[i]);
    Pokenav_AllocAndLoadPalettes(gUnknown_086201D4);
}

void sub_81C9FEC(void)
{
    FreeSpriteTilesByTag(3);
    FreeSpriteTilesByTag(1);
    FreeSpritePaletteByTag(4);
    FreeSpritePaletteByTag(5);
    FreeSpritePaletteByTag(6);
    FreeSpritePaletteByTag(7);
    FreeSpritePaletteByTag(8);
    FreeSpritePaletteByTag(3);
    sub_81CA094();
    sub_81CA698();
}

void sub_81CA02C(void)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            u8 spriteId = CreateSprite(&gUnknown_0862034C, 0x8c, 20 * i + 40, 3);
            unk->field_02c[i][j] = &gSprites[spriteId];
            gSprites[spriteId].pos2.x = 32 * j;
        }
    }
}

void sub_81CA094(void)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            FreeSpriteOamMatrix(unk->field_02c[i][j]);
            DestroySprite(unk->field_02c[i][j]);
        }
    }
}

void sub_81CA0C8(void)
{
    s32 r0 = sub_81C9894();
    sub_81CA0EC(gUnknown_08620240[r0].field_4, gUnknown_08620240[r0].field_0, gUnknown_08620240[r0].field_2);
}

void sub_81CA0EC(const u16 *const *a0, s32 a1, s32 a2)
{
    s32 i, j;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    s32 sp04 = GetSpriteTileStartByTag(3);

    for (i = 0; i < 6; i++)
    {
        if (*a0 != NULL)
        {
            for (j = 0; j < 4; j++)
            {
                unk->field_02c[i][j]->oam.tileNum = (*a0)[0] + sp04 + 8 * j;
                unk->field_02c[i][j]->oam.paletteNum = IndexOfSpritePaletteTag((*a0)[1] + 4);
                unk->field_02c[i][j]->invisible = TRUE;
                unk->field_02c[i][j]->pos1.y = a1;
                unk->field_02c[i][j]->pos1.x = 0x8c;
                unk->field_02c[i][j]->pos2.x = 32 * j;
            }
            unk->field_010[i] = TRUE;
        }
        else
        {
            for (j = 0; j < 4; j++)
            {
                unk->field_02c[i][j]->invisible = TRUE;
            }
            unk->field_010[i] = FALSE;
        }
        a0++;
        a1 += a2;
    }
}

void sub_81CA20C(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    s32 r8 = sub_81C98A4();
    s32 r7 = 0;
    s32 r2;

    for (i = 0; i < 6; i++)
    {
        if (unk->field_010[i])
        {
            if (r7++ == r8)
            {
                r2 = 0x82;
                unk->field_00b = i;
            }
            else
                r2 = 0x8c;
            sub_81CA35C(unk->field_02c[i], 0x100, r2, 0xC);
            sub_81CA448(unk->field_02c[i], 0);
        }
        else
            sub_81CA448(unk->field_02c[i], 1);
    }
}

void sub_81CA278(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);
    s32 r3 = sub_81C98A4();
    s32 r5;

    for (i = 0, r5 = 0; i < 6; i++)
    {
        if (unk->field_010[i])
        {
            if (r5 == r3)
            {
                r5 = i;
                break;
            }
            r5++;
        }
    }

    sub_81CA35C(unk->field_02c[unk->field_00b], 0x82, 0x8c, 0x4);
    sub_81CA35C(unk->field_02c[r5], 0x8c, 0x82, 0x4);
    unk->field_00b = r5;
}

void sub_81CA2DC(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < 6; i++)
    {
        if (unk->field_010[i])
        {
            if (unk->field_00b != i)
                sub_81CA35C(unk->field_02c[i], 0x8C, 0x100, 0x8);
            else
                sub_81CA3B4(unk->field_02c[i]);
        }
    }
}

bool32 sub_81CA324(void)
{
    s32 i;
    struct Pokenav2Struct * unk = GetSubstructPtr(2);

    for (i = 0; i < 6; i++)
    {
        if (unk->field_02c[i][0]->callback != SpriteCallbackDummy)
            return TRUE;
    }

    if (unk->field_00c)
        return TRUE;

    return FALSE;
}

void sub_81CA35C(struct Sprite ** sprites, s32 a1, s32 a2, s32 a3)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        sprites[i]->pos1.x = a1;
        sprites[i]->data[0] = a3;
        sprites[i]->data[1] = 16 * (a2 - a1) / a3;
        sprites[i]->data[2] = 16 * a1;
        sprites[i]->data[7] = a2;
        sprites[i]->callback = sub_81CA474;
    }
}
