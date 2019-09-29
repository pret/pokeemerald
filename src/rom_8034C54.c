#include "global.h"
#include "rom_8034C54.h"
#include "malloc.h"
#include "decompress.h"
#include "main.h"
#include "battle_main.h"

struct UnkStruct2
{
    bool8 isActive;
    u8 firstOamId;
    u8 field_2;
    u8 oamCount;
    u8 palTagIndex;
    u8 size;
    u8 shape;
    u8 priority;
    u8 xDelta;
    u8 field_9;
    u16 tileStart;
    s16 x;
    s16 y;
    u16 tileTag;
    u16 palTag;
    u32 field_14;
    s32 field_18;
};

struct UnkStruct1
{
    u32 count;
    struct UnkStruct2 *array;
};

// this file's functions
static u8 sub_8035518(u8 arg0);;
static void sub_8034EFC(struct UnkStruct2 *arg0);
static void sub_80350B0(struct UnkStruct2 *arg0, s32 arg1, bool32 arg2);
static void sub_8035164(struct UnkStruct2 *arg0, s32 arg1, bool32 arg2);
static void sub_80352C0(struct UnkStruct2 *arg0, s32 arg1, bool32 arg2);
static bool32 SharesTileWithAnyActive(u32 id);
static bool32 SharesPalWithAnyActive(u32 id);
static void sub_8035648(void);

// iwram
static s32 gUnknown_03000DD4;
static s32 gUnknown_03000DD8;
static s32 gUnknown_03000DDC;

// ewram
static EWRAM_DATA struct UnkStruct1 *gUnknown_02022E10 = {0};

// const rom data
static const u8 gUnknown_082FF1C8[][4] =
{
    {0x01, 0x04, 0x10, 0x40},
    {0x02, 0x04, 0x08, 0x20},
    {0x02, 0x04, 0x08, 0x20},
    {0x00, 0x00, 0x00, 0x00}
};

// code
bool32 sub_8034C54(u32 count)
{
    u32 i;

    if (gUnknown_02022E10 != NULL)
        sub_8034CC8();

    gUnknown_02022E10 = Alloc(sizeof(*gUnknown_02022E10));
    if (gUnknown_02022E10 == NULL)
        return FALSE;

    gUnknown_02022E10->array = Alloc(sizeof(struct UnkStruct2) * count);
    if (gUnknown_02022E10->array == NULL)
    {
        Free(gUnknown_02022E10);
        return FALSE;
    }

    gUnknown_02022E10->count = count;
    for (i = 0; i < count; i++)
    {
        gUnknown_02022E10->array[i].isActive = FALSE;
        gUnknown_02022E10->array[i].firstOamId = 0xFF;
    }

    return TRUE;
}

void sub_8034CC8(void)
{
    if (gUnknown_02022E10 != NULL)
    {
        if (gUnknown_02022E10->array != NULL)
        {
            u32 i;

            for (i = 0; i < gUnknown_02022E10->count; i++)
                sub_80353DC(i);

            Free(gUnknown_02022E10->array);
        }

        FREE_AND_SET_NULL(gUnknown_02022E10);
    }
}

bool32 sub_8034D14(u32 id, s32 arg1, const struct UnkStruct3 *arg2)
{
    u32 i;

    if (gUnknown_02022E10 == NULL)
        return FALSE;
    if (gUnknown_02022E10->array[id].isActive)
        return FALSE;

    gUnknown_02022E10->array[id].firstOamId = sub_8035518(arg2->field_1);
    if (gUnknown_02022E10->array[id].firstOamId == 0xFF)
        return FALSE;

    gUnknown_02022E10->array[id].tileStart = GetSpriteTileStartByTag(arg2->spriteSheet->tag);
    if (gUnknown_02022E10->array[id].tileStart == 0xFFFF)
    {
        if (arg2->spriteSheet->size != 0)
        {
            gUnknown_02022E10->array[id].tileStart = LoadSpriteSheet(arg2->spriteSheet);
        }
        else
        {
            struct CompressedSpriteSheet compSpriteSheet;

            compSpriteSheet = *(struct CompressedSpriteSheet*)(arg2->spriteSheet);
            compSpriteSheet.size = GetDecompressedDataSize(arg2->spriteSheet->data);
            gUnknown_02022E10->array[id].tileStart = LoadCompressedSpriteSheet(&compSpriteSheet);
        }

        if (gUnknown_02022E10->array[id].tileStart == 0xFFFF)
            return FALSE;
    }

    gUnknown_02022E10->array[id].palTagIndex = IndexOfSpritePaletteTag(arg2->spritePal->tag);
    if (gUnknown_02022E10->array[id].palTagIndex == 0xFF)
        gUnknown_02022E10->array[id].palTagIndex = LoadSpritePalette(arg2->spritePal);

    gUnknown_02022E10->array[id].field_2 = arg2->field_0_0;
    gUnknown_02022E10->array[id].oamCount = arg2->field_1;
    gUnknown_02022E10->array[id].x = arg2->x;
    gUnknown_02022E10->array[id].y = arg2->y;
    gUnknown_02022E10->array[id].shape = arg2->shape;
    gUnknown_02022E10->array[id].size = arg2->size;
    gUnknown_02022E10->array[id].priority = arg2->priority;
    gUnknown_02022E10->array[id].xDelta = arg2->xDelta;
    gUnknown_02022E10->array[id].field_9 = sub_80355F8(arg2->shape, arg2->size);
    gUnknown_02022E10->array[id].tileTag = arg2->spriteSheet->tag;
    gUnknown_02022E10->array[id].palTag = arg2->spritePal->tag;
    gUnknown_02022E10->array[id].isActive = TRUE;
    gUnknown_02022E10->array[id].field_14 = 1;

    for (i = 1; i < arg2->field_1; i++)
        gUnknown_02022E10->array[id].field_14 *= 10;

    sub_8034EFC(&gUnknown_02022E10->array[id]);
    sub_8035044(id, arg1);

    return TRUE;
}

static void sub_8034EFC(struct UnkStruct2 *arg0)
{
    u32 i;
    u32 oamId = arg0->firstOamId;
    u32 x = arg0->x;
    u32 oamCount = arg0->oamCount + 1;

    CpuFill16(0, &gMain.oamBuffer[oamId], sizeof(struct OamData) * oamCount);
    for (i = 0, oamId = arg0->firstOamId; i < oamCount; i++, oamId++)
    {
        gMain.oamBuffer[oamId].y = arg0->y;
        gMain.oamBuffer[oamId].x = x;
        gMain.oamBuffer[oamId].shape = arg0->shape;
        gMain.oamBuffer[oamId].size = arg0->size;
        gMain.oamBuffer[oamId].tileNum = arg0->tileStart;
        gMain.oamBuffer[oamId].priority = arg0->priority;
        gMain.oamBuffer[oamId].paletteNum = arg0->palTagIndex;

        x += arg0->xDelta;
    }

    oamId--;
    gMain.oamBuffer[oamId].x = arg0->x - arg0->xDelta;
    gMain.oamBuffer[oamId].affineMode = 2;
    gMain.oamBuffer[oamId].tileNum = arg0->tileStart + (arg0->field_9 * 10);
}

void sub_8035044(u32 id, s32 arg1)
{
    bool32 r2;

    if (gUnknown_02022E10 == NULL)
        return;
    if (!gUnknown_02022E10->array[id].isActive)
        return;

    gUnknown_02022E10->array[id].field_18 = arg1;
    if (arg1 < 0)
    {
        r2 = TRUE;
        arg1 *= -1;
    }
    else
    {
        r2 = FALSE;
    }

    switch (gUnknown_02022E10->array[id].field_2)
    {
    case 0:
    default:
        sub_80350B0(&gUnknown_02022E10->array[id], arg1, r2);
        break;
    case 1:
        sub_8035164(&gUnknown_02022E10->array[id], arg1, r2);
        break;
    case 2:
        sub_80352C0(&gUnknown_02022E10->array[id], arg1, r2);
        break;
    }
}

static void sub_80350B0(struct UnkStruct2 *arg0, s32 arg1, bool32 arg2)
{
    u32 r5 = arg0->field_14;
    u32 oamId = arg0->firstOamId;

    while (r5 != 0)
    {
        u32 r4 = arg1 / r5;
        arg1 -= (r4 * r5);
        r5 /= 10;

        gMain.oamBuffer[oamId].tileNum = (r4 * arg0->field_9) + arg0->tileStart;
        oamId++;
    }

    if (arg2)
        gMain.oamBuffer[oamId].affineMode = 0;
    else
        gMain.oamBuffer[oamId].affineMode = 2;
}

static void sub_8035164(struct UnkStruct2 *arg0, s32 arg1, bool32 arg2)
{
    u32 r5 = arg0->field_14;
    gUnknown_03000DD4 = arg0->firstOamId;
    gUnknown_03000DD8 = 0;
    gUnknown_03000DDC = -1;

    while (r5 != 0)
    {
        u32 r4 = arg1 / r5;
        arg1 -= (r4 * r5);
        r5 /= 10;

        if (r4 != 0 || gUnknown_03000DDC != -1 || r5 == 0)
        {
            gMain.oamBuffer[gUnknown_03000DD4].tileNum = (r4 * arg0->field_9) + arg0->tileStart;
            gMain.oamBuffer[gUnknown_03000DD4].affineMode = 0;

            if (gUnknown_03000DDC == -1)
                gUnknown_03000DDC = gUnknown_03000DD8;
        }
        else
        {
            gMain.oamBuffer[gUnknown_03000DD4].affineMode = 2;
        }

        gUnknown_03000DD4++;
        gUnknown_03000DD8++;
    }

    if (arg2)
    {
        gMain.oamBuffer[gUnknown_03000DD4].affineMode = 0;
        gMain.oamBuffer[gUnknown_03000DD4].x = arg0->x + ((gUnknown_03000DDC - 1) * arg0->xDelta);
    }
    else
    {
        gMain.oamBuffer[gUnknown_03000DD4].affineMode = 2;
    }
}

static void sub_80352C0(struct UnkStruct2 *arg0, s32 arg1, bool32 arg2)
{
    u32 r5 = arg0->field_14;
    u32 oamId = arg0->firstOamId;
    u32 var_28 = 0;
    s32 r9 = 0;

    while (r5 != 0)
    {
        u32 r4 = arg1 / r5;
        arg1 -= (r4 * r5);
        r5 /= 10;

        if (r4 != 0 || var_28 != 0 || r5 == 0)
        {
            var_28 = 1;
            gMain.oamBuffer[oamId].tileNum = (r4 * arg0->field_9) + arg0->tileStart;
            gMain.oamBuffer[oamId].affineMode = 0;

            oamId++;
            r9++;
        }
    }

    while (r9 < arg0->oamCount)
    {
        gMain.oamBuffer[oamId].affineMode = 2;
        oamId++;
        r9++;
    }

    if (arg2)
        gMain.oamBuffer[oamId].affineMode = 0;
    else
        gMain.oamBuffer[oamId].affineMode = 2;
}

void sub_80353DC(u32 id)
{
    s32 oamId, oamCount, i;

    if (gUnknown_02022E10 == NULL)
        return;
    if (!gUnknown_02022E10->array[id].isActive)
        return;

    oamCount = gUnknown_02022E10->array[id].oamCount + 1;
    oamId = gUnknown_02022E10->array[id].firstOamId;

    for (i = 0; i < oamCount; i++, oamId++)
        gMain.oamBuffer[oamId].affineMode = 2;

    if (!SharesTileWithAnyActive(id))
        FreeSpriteTilesByTag(gUnknown_02022E10->array[id].tileTag);
    if (!SharesPalWithAnyActive(id))
        FreeSpritePaletteByTag(gUnknown_02022E10->array[id].palTag);

    gUnknown_02022E10->array[id].isActive = FALSE;
}

void sub_803547C(u32 id, bool32 arg1)
{
    s32 oamId, oamCount, i;

    if (gUnknown_02022E10 == NULL)
        return;
    if (!gUnknown_02022E10->array[id].isActive)
        return;

    oamCount = gUnknown_02022E10->array[id].oamCount + 1;
    oamId = gUnknown_02022E10->array[id].firstOamId;
    if (arg1)
    {
        for (i = 0; i < oamCount; i++, oamId++)
            gMain.oamBuffer[oamId].affineMode = 2;
    }
    else
    {
        for (i = 0; i < oamCount; i++, oamId++)
            gMain.oamBuffer[oamId].affineMode = 0;

        sub_8035044(id, gUnknown_02022E10->array[id].field_18);
    }
}

static u8 sub_8035518(u8 arg0)
{
    u32 i;
    u16 oamCount = 64;

    for (i = 0; i < gUnknown_02022E10->count; i++)
    {
        if (!gUnknown_02022E10->array[i].isActive)
        {
            if (gUnknown_02022E10->array[i].firstOamId != 0xFF && gUnknown_02022E10->array[i].oamCount <= arg0)
                return gUnknown_02022E10->array[i].firstOamId;
        }
        else
        {
            oamCount += 1 + gUnknown_02022E10->array[i].oamCount;
        }
    }

    if (oamCount + arg0 + 1 > 128)
        return 0xFF;
    else
        return oamCount;
}

static bool32 SharesTileWithAnyActive(u32 id)
{
    u32 i;

    for (i = 0; i < gUnknown_02022E10->count; i++)
    {
        if (gUnknown_02022E10->array[i].isActive && i != id
            && gUnknown_02022E10->array[i].tileTag == gUnknown_02022E10->array[id].tileTag)
        {
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 SharesPalWithAnyActive(u32 id)
{
    u32 i;

    for (i = 0; i < gUnknown_02022E10->count; i++)
    {
        if (gUnknown_02022E10->array[i].isActive && i != id
            && gUnknown_02022E10->array[i].palTag == gUnknown_02022E10->array[id].palTag)
        {
            return TRUE;
        }
    }

    return FALSE;
}

u8 sub_80355F8(u32 shape, u32 size)
{
    return gUnknown_082FF1C8[shape][size];
}

static void sub_8035608(void)
{
    u8 spriteId;

    ResetSpriteData();
    spriteId = CreateSprite(&gUnknown_0831AC88, 0, 0, 0);
    gSprites[spriteId].invisible = TRUE;
    SetMainCallback2(sub_8035648);
}

static void sub_8035648(void)
{
    AnimateSprites();
    BuildOamBuffer();
}
