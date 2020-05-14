#include "global.h"
#include "rom_81520A8.h"
#include "malloc.h"
#include "main.h"
#include "digit_obj_util.h"

static EWRAM_DATA struct
{
    u8 count;
    struct UnkStruct_81520A8 *unk4;
} *sUnknown_0203ABB8 = NULL;

void sub_81520A8(void *dest, u16 value, u8 left, u8 top, u8 width, u8 height) // Unused.
{
    u8 i;
    u8 j;
    u8 x;
    u8 y;

    for (i = 0, y = top; i < height; i++)
    {
        for (x = left, j = 0; j < width; j++)
        {
            *(u16 *)((dest) + (y * 64 + x * 2)) = value;
            x = (x + 1) % 32;
        }
        y = (y + 1) % 32;
    }
}

void sub_8152134(void *dest, const u16 *src, u8 left, u8 top, u8 width, u8 height) // Unused.
{
    u8 i;
    u8 j;
    u8 x;
    u8 y;
    const u16 *_src;

    for (i = 0, _src = src, y = top; i < height; i++)
    {
        for (x = left, j = 0; j < width; j++)
        {
            *(u16 *)((dest) + (y * 64 + x * 2)) = *(_src++);
            x = (x + 1) % 32;
        }
        y = (y + 1) % 32;
    }
}

bool32 sub_81521C0(u8 count)
{
    u8 i = 0;

    if (count == 0)
        return FALSE;
    if (count > 64)
        count = 64;

    sUnknown_0203ABB8 = AllocZeroed(sizeof(*sUnknown_0203ABB8));
    if (sUnknown_0203ABB8 == NULL)
        return FALSE;
    sUnknown_0203ABB8->unk4 = AllocZeroed(count * sizeof(struct UnkStruct_81520A8));
    if (sUnknown_0203ABB8->unk4 == NULL)
    {
        FREE_AND_SET_NULL(sUnknown_0203ABB8);
        return FALSE;
    }

    sUnknown_0203ABB8->count = count;
    for (i = 0; i < count; i++)
    {
        memcpy(&sUnknown_0203ABB8->unk4[i].oam, &gDummyOamData, sizeof(struct OamData));
        sUnknown_0203ABB8->unk4[i].unk19_2 = TRUE;
    }

    return TRUE;
}

bool32 sub_8152254(void)
{
    u8 i = 0;

    if (sUnknown_0203ABB8 == NULL)
        return FALSE;

    for (i = 0; i < sUnknown_0203ABB8->count; i++)
        memcpy(&gMain.oamBuffer[i + 64], &gDummyOamData, sizeof(struct OamData));

    memset(sUnknown_0203ABB8->unk4, 0, sUnknown_0203ABB8->count * sizeof(struct UnkStruct_81520A8));
    FREE_AND_SET_NULL(sUnknown_0203ABB8->unk4);
    memset(sUnknown_0203ABB8, 0, sizeof(*sUnknown_0203ABB8));
    FREE_AND_SET_NULL(sUnknown_0203ABB8);

    return TRUE;
}

bool32 sub_81522D4(void)
{
    u8 i = 0;

    if (sUnknown_0203ABB8 == NULL || sUnknown_0203ABB8->unk4 == NULL)
        return FALSE;

    for (i = 0; i < sUnknown_0203ABB8->count; i++)
    {
        if (sUnknown_0203ABB8->unk4[i].unk19_0 && sUnknown_0203ABB8->unk4[i].unk19_1)
        {
            if (sUnknown_0203ABB8->unk4[i].callback != NULL)
                sUnknown_0203ABB8->unk4[i].callback(&sUnknown_0203ABB8->unk4[i]);

            if (sUnknown_0203ABB8->unk4[i].unk19_2)
            {
                memcpy(&gMain.oamBuffer[i + 64], &gDummyOamData, sizeof(struct OamData));
            }
            else
            {
                sUnknown_0203ABB8->unk4[i].oam.y = sUnknown_0203ABB8->unk4[i].y + sUnknown_0203ABB8->unk4[i].yDelta;
                sUnknown_0203ABB8->unk4[i].oam.x = sUnknown_0203ABB8->unk4[i].x + sUnknown_0203ABB8->unk4[i].xDelta;
                sUnknown_0203ABB8->unk4[i].oam.priority = sUnknown_0203ABB8->unk4[i].priority;
                sUnknown_0203ABB8->unk4[i].oam.tileNum = sUnknown_0203ABB8->unk4[i].tileNum;
                memcpy(&gMain.oamBuffer[i + 64], &sUnknown_0203ABB8->unk4[i], sizeof(struct OamData));
            }
        }
    }

    return TRUE;
}

static bool32 sub_81523F4(struct UnkStruct_81520A8 *structPtr, u8 arg1)
{
    u16 tileStart;

    if (structPtr == NULL)
        return FALSE;

    tileStart = GetSpriteTileStartByTag(structPtr->tileTag);
    if (tileStart == 0xFFFF)
        return FALSE;

    structPtr->unk18 = arg1;
    structPtr->tileNum = (GetTilesPerImage(structPtr->oam.shape, structPtr->oam.size) * arg1) + tileStart;
    return TRUE;
}

u8 sub_8152438(u8 id, void (*func)(struct UnkStruct_81520A8 *))
{
    if (sUnknown_0203ABB8 == NULL || id >= sUnknown_0203ABB8->count)
        return 0xFF;
    else if (!sUnknown_0203ABB8->unk4[id].unk19_0)
        return 0xFF;

    sUnknown_0203ABB8->unk4[id].callback = func;
    return id;
}

u8 sub_8152474(u8 id, u8 dataArrayId, s16 dataValue)
{
    if (sUnknown_0203ABB8 == NULL || id >= sUnknown_0203ABB8->count)
        return 0xFF;
    else if (!sUnknown_0203ABB8->unk4[id].unk19_0 || dataArrayId >= ARRAY_COUNT(sUnknown_0203ABB8->unk4[id].data))
        return 0xFF;

    sUnknown_0203ABB8->unk4[id].data[dataArrayId] = dataValue;
    return id;
}

u8 sub_81524C4(const struct OamData *oam, u16 tileTag, u16 palTag, s16 x, s16 y, u8 arg5, u8 priority)
{
    struct UnkStruct_81520A8 *structPtr = NULL;
    u8 i;

    if (sUnknown_0203ABB8 == NULL || oam == NULL)
        return 0xFF;

    for (i = 0; i < sUnknown_0203ABB8->count; i++)
    {
        if (!sUnknown_0203ABB8->unk4[i].unk19_0)
        {
            structPtr = &sUnknown_0203ABB8->unk4[i];
            memset(structPtr, 0, sizeof(*structPtr));
            structPtr->id = i;
            structPtr->unk19_0 = TRUE;
            structPtr->unk19_1 = TRUE;
            break;
        }
    }

    if (structPtr == NULL)
        return 0xFF;

    memcpy(&structPtr->oam, oam, sizeof(*oam));
    structPtr->tileTag = tileTag;
    structPtr->palTag = palTag;
    structPtr->x = x;
    structPtr->y = y;
    structPtr->oam.paletteNum = IndexOfSpritePaletteTag(palTag);
    if (priority < 4)
    {
        structPtr->priority = priority;
        structPtr->oam.priority = priority;
    }
    sub_81523F4(structPtr, arg5);

    return structPtr->id;
}

u8 sub_81525D0(u8 id)
{
    if (sUnknown_0203ABB8 == NULL || !sUnknown_0203ABB8->unk4[id].unk19_0)
        return 0xFF;

    memset(&sUnknown_0203ABB8->unk4[id], 0, sizeof(struct UnkStruct_81520A8));
    sUnknown_0203ABB8->unk4[id].oam.y = 160;
    sUnknown_0203ABB8->unk4[id].oam.x = 240;
    sUnknown_0203ABB8->unk4[id].unk19_2 = TRUE;
    memcpy(&gMain.oamBuffer[id + 64], &gDummyOamData, sizeof(struct OamData));
    return id;
}
