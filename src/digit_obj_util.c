#include "global.h"
#include "digit_obj_util.h"
#include "malloc.h"
#include "decompress.h"
#include "main.h"
#include "battle_main.h"

struct DigitPrinter
{
    bool8 isActive;
    u8 firstOamId;
    u8 strConvMode;
    u8 oamCount;
    u8 palTagIndex;
    u8 size;
    u8 shape;
    u8 priority;
    u8 xDelta;
    u8 tilesPerImage;
    u16 tileStart;
    s16 x;
    s16 y;
    u16 tileTag;
    u16 palTag;
    u32 pow10;
    s32 lastPrinted;
};

struct DigitPrinterAlloc
{
    u32 count;
    struct DigitPrinter *array;
};

// this file's functions
static u8 GetFirstOamId(u8 oamCount);
static void CopyWorkToOam(struct DigitPrinter *objWork);
static void DrawNumObjsLeadingZeros(struct DigitPrinter *objWork, s32 num, bool32 sign);
static void DrawNumObjsMinusInFront(struct DigitPrinter *objWork, s32 num, bool32 sign);
static void DrawNumObjsMinusInBack(struct DigitPrinter *objWork, s32 num, bool32 sign);
static bool32 SharesTileWithAnyActive(u32 id);
static bool32 SharesPalWithAnyActive(u32 id);

// ewram
static EWRAM_DATA struct DigitPrinterAlloc *sOamWork = {0};

// const rom data
static const u8 sTilesPerImage[4][4] =
{
    [ST_OAM_SQUARE]      = {
        [ST_OAM_SIZE_0] = 0x01, // SPRITE_SIZE_8x8
        [ST_OAM_SIZE_1] = 0x04, // SPRITE_SIZE_16x16
        [ST_OAM_SIZE_2] = 0x10, // SPRITE_SIZE_32x32
        [ST_OAM_SIZE_3] = 0x40  // SPRITE_SIZE_64x64
    },
    [ST_OAM_H_RECTANGLE] = {
        [ST_OAM_SIZE_0] = 0x02, // SPRITE_SIZE_16x8
        [ST_OAM_SIZE_1] = 0x04, // SPRITE_SIZE_32x8
        [ST_OAM_SIZE_2] = 0x08, // SPRITE_SIZE_32x16
        [ST_OAM_SIZE_3] = 0x20  // SPRITE_SIZE_64x32
    },
    [ST_OAM_V_RECTANGLE] = {
        [ST_OAM_SIZE_0] = 0x02, // SPRITE_SIZE_8x16
        [ST_OAM_SIZE_1] = 0x04, // SPRITE_SIZE_8x32
        [ST_OAM_SIZE_2] = 0x08, // SPRITE_SIZE_16x32
        [ST_OAM_SIZE_3] = 0x20  // SPRITE_SIZE_32x64
    }
};

// code
bool32 DigitObjUtil_Init(u32 count)
{
    u32 i;

    if (sOamWork != NULL)
        DigitObjUtil_Free();

    sOamWork = Alloc(sizeof(*sOamWork));
    if (sOamWork == NULL)
        return FALSE;

    sOamWork->array = Alloc(sizeof(struct DigitPrinter) * count);
    if (sOamWork->array == NULL)
    {
        Free(sOamWork);
        return FALSE;
    }

    sOamWork->count = count;
    for (i = 0; i < count; i++)
    {
        sOamWork->array[i].isActive = FALSE;
        sOamWork->array[i].firstOamId = 0xFF;
    }

    return TRUE;
}

void DigitObjUtil_Free(void)
{
    if (sOamWork != NULL)
    {
        if (sOamWork->array != NULL)
        {
            u32 i;

            for (i = 0; i < sOamWork->count; i++)
                DigitObjUtil_DeletePrinter(i);

            Free(sOamWork->array);
        }

        FREE_AND_SET_NULL(sOamWork);
    }
}

bool32 DigitObjUtil_CreatePrinter(u32 id, s32 num, const struct DigitObjUtilTemplate *template)
{
    u32 i;

    if (sOamWork == NULL)
        return FALSE;
    if (sOamWork->array[id].isActive)
        return FALSE;

    sOamWork->array[id].firstOamId = GetFirstOamId(template->oamCount);
    if (sOamWork->array[id].firstOamId == 0xFF)
        return FALSE;

    sOamWork->array[id].tileStart = GetSpriteTileStartByTag(template->spriteSheet->tag);
    if (sOamWork->array[id].tileStart == 0xFFFF)
    {
        if (template->spriteSheet->size != 0)
        {
            sOamWork->array[id].tileStart = LoadSpriteSheet(template->spriteSheet);
        }
        else
        {
            struct CompressedSpriteSheet compSpriteSheet;

            compSpriteSheet = *(struct CompressedSpriteSheet*)(template->spriteSheet);
            compSpriteSheet.size = GetDecompressedDataSize(template->spriteSheet->data);
            sOamWork->array[id].tileStart = LoadCompressedSpriteSheet(&compSpriteSheet);
        }

        if (sOamWork->array[id].tileStart == 0xFFFF)
            return FALSE;
    }

    sOamWork->array[id].palTagIndex = IndexOfSpritePaletteTag(template->spritePal->tag);
    if (sOamWork->array[id].palTagIndex == 0xFF)
        sOamWork->array[id].palTagIndex = LoadSpritePalette(template->spritePal);

    sOamWork->array[id].strConvMode = template->strConvMode;
    sOamWork->array[id].oamCount = template->oamCount;
    sOamWork->array[id].x = template->x;
    sOamWork->array[id].y = template->y;
    sOamWork->array[id].shape = template->shape;
    sOamWork->array[id].size = template->size;
    sOamWork->array[id].priority = template->priority;
    sOamWork->array[id].xDelta = template->xDelta;
    sOamWork->array[id].tilesPerImage = GetTilesPerImage(template->shape, template->size);
    sOamWork->array[id].tileTag = template->spriteSheet->tag;
    sOamWork->array[id].palTag = template->spritePal->tag;
    sOamWork->array[id].isActive = TRUE;

    // Decimal left shift
    sOamWork->array[id].pow10 = 1;
    for (i = 1; i < template->oamCount; i++)
        sOamWork->array[id].pow10 *= 10;

    CopyWorkToOam(&sOamWork->array[id]);
    DigitObjUtil_PrintNumOn(id, num);

    return TRUE;
}

static void CopyWorkToOam(struct DigitPrinter *objWork)
{
    u32 i;
    u32 oamId = objWork->firstOamId;
    u32 x = objWork->x;
    u32 oamCount = objWork->oamCount + 1;

    CpuFill16(0, &gMain.oamBuffer[oamId], sizeof(struct OamData) * oamCount);
    for (i = 0, oamId = objWork->firstOamId; i < oamCount; i++, oamId++)
    {
        gMain.oamBuffer[oamId].y = objWork->y;
        gMain.oamBuffer[oamId].x = x;
        gMain.oamBuffer[oamId].shape = objWork->shape;
        gMain.oamBuffer[oamId].size = objWork->size;
        gMain.oamBuffer[oamId].tileNum = objWork->tileStart;
        gMain.oamBuffer[oamId].priority = objWork->priority;
        gMain.oamBuffer[oamId].paletteNum = objWork->palTagIndex;

        x += objWork->xDelta;
    }

    oamId--;
    gMain.oamBuffer[oamId].x = objWork->x - objWork->xDelta;
    gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
    gMain.oamBuffer[oamId].tileNum = objWork->tileStart + (objWork->tilesPerImage * 10);
}

void DigitObjUtil_PrintNumOn(u32 id, s32 num)
{
    bool32 sign;

    if (sOamWork == NULL)
        return;
    if (!sOamWork->array[id].isActive)
        return;

    sOamWork->array[id].lastPrinted = num;
    if (num < 0)
    {
        sign = TRUE;
        num *= -1;
    }
    else
    {
        sign = FALSE;
    }

    switch (sOamWork->array[id].strConvMode)
    {
    case 0:
    default:
        DrawNumObjsLeadingZeros(&sOamWork->array[id], num, sign);
        break;
    case 1:
        DrawNumObjsMinusInFront(&sOamWork->array[id], num, sign);
        break;
    case 2:
        DrawNumObjsMinusInBack(&sOamWork->array[id], num, sign);
        break;
    }
}

static void DrawNumObjsLeadingZeros(struct DigitPrinter *objWork, s32 num, bool32 sign)
{
    u32 pow10 = objWork->pow10;
    u32 oamId = objWork->firstOamId;

    while (pow10 != 0)
    {
        u32 digit = num / pow10;
        num -= (digit * pow10);
        pow10 /= 10;

        gMain.oamBuffer[oamId].tileNum = (digit * objWork->tilesPerImage) + objWork->tileStart;
        oamId++;
    }

    if (sign)
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_OFF;
    else
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
}

static void DrawNumObjsMinusInFront(struct DigitPrinter *objWork, s32 num, bool32 sign)
{
    u32 pow10 = objWork->pow10;
    static int oamId;
    static int curDigit;
    static int firstDigit;

    oamId = objWork->firstOamId;
    curDigit = 0;
    firstDigit = -1;

    while (pow10 != 0)
    {
        u32 digit = num / pow10;
        num -= (digit * pow10);
        pow10 /= 10;

        if (digit != 0 || firstDigit != -1 || pow10 == 0)
        {
            gMain.oamBuffer[oamId].tileNum = (digit * objWork->tilesPerImage) + objWork->tileStart;
            gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_OFF;

            if (firstDigit == -1)
                firstDigit = curDigit;
        }
        else
        {
            gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
        }

        oamId++;
        curDigit++;
    }

    if (sign)
    {
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_OFF;
        gMain.oamBuffer[oamId].x = objWork->x + ((firstDigit - 1) * objWork->xDelta);
    }
    else
    {
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
    }
}

static void DrawNumObjsMinusInBack(struct DigitPrinter *objWork, s32 num, bool32 sign)
{
    u32 pow10 = objWork->pow10;
    u32 oamId = objWork->firstOamId;
    bool32 printingDigits = FALSE;
    s32 nsprites = 0;

    while (pow10 != 0)
    {
        u32 digit = num / pow10;
        num -= (digit * pow10);
        pow10 /= 10;

        if (digit != 0 || printingDigits || pow10 == 0)
        {
            printingDigits = TRUE;
            gMain.oamBuffer[oamId].tileNum = (digit * objWork->tilesPerImage) + objWork->tileStart;
            gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_OFF;

            oamId++;
            nsprites++;
        }
    }

    while (nsprites < objWork->oamCount)
    {
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
        oamId++;
        nsprites++;
    }

    if (sign)
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_OFF;
    else
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
}

void DigitObjUtil_DeletePrinter(u32 id)
{
    s32 oamId, oamCount, i;

    if (sOamWork == NULL)
        return;
    if (!sOamWork->array[id].isActive)
        return;

    oamCount = sOamWork->array[id].oamCount + 1;
    oamId = sOamWork->array[id].firstOamId;

    for (i = 0; i < oamCount; i++, oamId++)
        gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;

    if (!SharesTileWithAnyActive(id))
        FreeSpriteTilesByTag(sOamWork->array[id].tileTag);
    if (!SharesPalWithAnyActive(id))
        FreeSpritePaletteByTag(sOamWork->array[id].palTag);

    sOamWork->array[id].isActive = FALSE;
}

void DigitObjUtil_HideOrShow(u32 id, bool32 hide)
{
    s32 oamId, oamCount, i;

    if (sOamWork == NULL)
        return;
    if (!sOamWork->array[id].isActive)
        return;

    oamCount = sOamWork->array[id].oamCount + 1;
    oamId = sOamWork->array[id].firstOamId;
    if (hide)
    {
        for (i = 0; i < oamCount; i++, oamId++)
            gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_ERASE;
    }
    else
    {
        for (i = 0; i < oamCount; i++, oamId++)
            gMain.oamBuffer[oamId].affineMode = ST_OAM_AFFINE_OFF;

        DigitObjUtil_PrintNumOn(id, sOamWork->array[id].lastPrinted);
    }
}

static u8 GetFirstOamId(u8 oamCount)
{
    u32 i;
    u16 firstOamId = 64;

    for (i = 0; i < sOamWork->count; i++)
    {
        if (!sOamWork->array[i].isActive)
        {
            if (sOamWork->array[i].firstOamId != 0xFF && sOamWork->array[i].oamCount <= oamCount)
                return sOamWork->array[i].firstOamId;
        }
        else
        {
            firstOamId += 1 + sOamWork->array[i].oamCount;
        }
    }

    if (firstOamId + oamCount + 1 > 128)
        return 0xFF;
    else
        return firstOamId;
}

static bool32 SharesTileWithAnyActive(u32 id)
{
    u32 i;

    for (i = 0; i < sOamWork->count; i++)
    {
        if (sOamWork->array[i].isActive && i != id
            && sOamWork->array[i].tileTag == sOamWork->array[id].tileTag)
        {
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 SharesPalWithAnyActive(u32 id)
{
    u32 i;

    for (i = 0; i < sOamWork->count; i++)
    {
        if (sOamWork->array[i].isActive && i != id
            && sOamWork->array[i].palTag == sOamWork->array[id].palTag)
        {
            return TRUE;
        }
    }

    return FALSE;
}

u8 GetTilesPerImage(u32 shape, u32 size)
{
    return sTilesPerImage[shape][size];
}
