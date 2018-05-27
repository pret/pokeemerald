#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "main.h"

struct UnkStruct3
{
    u8 field_0_0:2;
    u8 shape:2;
    u8 size:2;
    u8 priority:2;
    u8 field_1;
    u8 xDelta;
    u8 field_3;
    s16 x;
    s16 y;
    const struct SpriteSheet *spriteSheet;
    const struct SpritePalette *spritePal;
};

struct UnkStruct2
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
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
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
};

struct UnkStruct1
{
    u32 count;
    struct UnkStruct2 *field_4;
};

IWRAM_DATA u32 gUnknown_03000DD4;
IWRAM_DATA u32 gUnknown_03000DD8;
IWRAM_DATA u32 gUnknown_03000DDC;

extern struct UnkStruct1 *gUnknown_02022E10;

// this file's functions
void sub_8034CC8(void);
void sub_80353DC(u32 id);
u8 sub_8035518(u8 arg0);
u8 sub_80355F8(u32 arg0, u32 arg1);
void sub_8034EFC(struct UnkStruct2 *arg0);
void sub_8035044(u32 id, u32 arg1);

// code
bool32 sub_8034C54(u32 count)
{
    u32 i;

    if (gUnknown_02022E10 != NULL)
        sub_8034CC8();

    gUnknown_02022E10 = Alloc(sizeof(*gUnknown_02022E10));
    if (gUnknown_02022E10 == NULL)
        return FALSE;

    gUnknown_02022E10->field_4 = Alloc(sizeof(struct UnkStruct2) * count);
    if (gUnknown_02022E10->field_4 == NULL)
    {
        Free(gUnknown_02022E10);
        return FALSE;
    }

    gUnknown_02022E10->count = count;
    for (i = 0; i < count; i++)
    {
        gUnknown_02022E10->field_4[i].field_0 = 0;
        gUnknown_02022E10->field_4[i].field_1 |= 0xFF;
    }

    return TRUE;
}

void sub_8034CC8(void)
{
    if (gUnknown_02022E10 != NULL)
    {
        if (gUnknown_02022E10->field_4 != NULL)
        {
            u32 i;

            for (i = 0; i < gUnknown_02022E10->count; i++)
                sub_80353DC(i);

            Free(gUnknown_02022E10->field_4);
        }

        FREE_AND_SET_NULL(gUnknown_02022E10);
    }
}

bool32 sub_8034D14(u32 id, u32 arg1, const struct UnkStruct3 *arg2)
{
    u32 i;

    if (gUnknown_02022E10 == NULL)
        return FALSE;
    if (gUnknown_02022E10->field_4[id].field_0 != 0)
        return FALSE;

    gUnknown_02022E10->field_4[id].field_1 = sub_8035518(arg2->field_1);
    if (gUnknown_02022E10->field_4[id].field_1 == 0xFF)
        return FALSE;

    gUnknown_02022E10->field_4[id].tileStart = GetSpriteTileStartByTag(arg2->spriteSheet->tag);
    if (gUnknown_02022E10->field_4[id].tileStart == 0xFFFF)
    {
        if (arg2->spriteSheet->size != 0)
        {
            gUnknown_02022E10->field_4[id].tileStart = LoadSpriteSheet(arg2->spriteSheet);
        }
        else
        {
            struct CompressedSpriteSheet compSpriteSheet;

            compSpriteSheet = *(struct CompressedSpriteSheet*)(arg2->spriteSheet);
            compSpriteSheet.size = GetDecompressedDataSize(arg2->spriteSheet->data);
            gUnknown_02022E10->field_4[id].tileStart = LoadCompressedObjectPic(&compSpriteSheet);
        }

        if (gUnknown_02022E10->field_4[id].tileStart == 0xFFFF)
            return FALSE;
    }

    gUnknown_02022E10->field_4[id].palTagIndex = IndexOfSpritePaletteTag(arg2->spritePal->tag);
    if (gUnknown_02022E10->field_4[id].palTagIndex == 0xFF)
        gUnknown_02022E10->field_4[id].palTagIndex = LoadSpritePalette(arg2->spritePal);

    gUnknown_02022E10->field_4[id].field_2 = arg2->field_0_0;
    gUnknown_02022E10->field_4[id].field_3 = arg2->field_1;
    gUnknown_02022E10->field_4[id].x = arg2->x;
    gUnknown_02022E10->field_4[id].y = arg2->y;
    gUnknown_02022E10->field_4[id].shape = arg2->shape;
    gUnknown_02022E10->field_4[id].size = arg2->size;
    gUnknown_02022E10->field_4[id].priority = arg2->priority;
    gUnknown_02022E10->field_4[id].xDelta = arg2->xDelta;
    gUnknown_02022E10->field_4[id].field_9 = sub_80355F8(arg2->shape, arg2->size);
    gUnknown_02022E10->field_4[id].tileTag = arg2->spriteSheet->tag;
    gUnknown_02022E10->field_4[id].palTag = arg2->spritePal->tag;
    gUnknown_02022E10->field_4[id].field_0 = 1;
    gUnknown_02022E10->field_4[id].field_14 = 1;

    for (i = 1; i < arg2->field_1; i++)
        gUnknown_02022E10->field_4[id].field_14 *= 10;

    sub_8034EFC(&gUnknown_02022E10->field_4[id]);
    sub_8035044(id, arg1);

    return TRUE;
}

void sub_8034EFC(struct UnkStruct2 *arg0)
{
    u32 i;
    u32 r5 = arg0->field_1;
    u32 x = arg0->x;
    u32 r8 = arg0->field_3 + 1;

    CpuFill16(0, &gMain.oamBuffer[r5], sizeof(struct OamData) * r8);
    for (i = 0, r5 = arg0->field_1; i < r8; i++, r5++)
    {
        gMain.oamBuffer[r5].y = arg0->y;
        gMain.oamBuffer[r5].x = x;
        gMain.oamBuffer[r5].shape = arg0->shape;
        gMain.oamBuffer[r5].size = arg0->size;
        gMain.oamBuffer[r5].tileNum = arg0->tileStart;
        gMain.oamBuffer[r5].priority = arg0->priority;
        gMain.oamBuffer[r5].paletteNum = arg0->palTagIndex;

        x += arg0->xDelta;
    }

    r5--;
    gMain.oamBuffer[r5].x = arg0->x - arg0->xDelta;
    gMain.oamBuffer[r5].affineMode = 2;
    gMain.oamBuffer[r5].tileNum = arg0->tileStart + (arg0->field_9 * 10);
}
