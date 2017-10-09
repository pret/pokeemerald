#include "global.h"
#include "util.h"
#include "sprite.h"

const u32 gBitTable[] =
{
    1 << 0,
    1 << 1,
    1 << 2,
    1 << 3,
    1 << 4,
    1 << 5,
    1 << 6,
    1 << 7,
    1 << 8,
    1 << 9,
    1 << 10,
    1 << 11,
    1 << 12,
    1 << 13,
    1 << 14,
    1 << 15,
    1 << 16,
    1 << 17,
    1 << 18,
    1 << 19,
    1 << 20,
    1 << 21,
    1 << 22,
    1 << 23,
    1 << 24,
    1 << 25,
    1 << 26,
    1 << 27,
    1 << 28,
    1 << 29,
    1 << 30,
    1 << 31,
};

static const struct SpriteTemplate sInvisibleSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 sSpriteDimensions[3][4][2] =
{
    // square
    {
        {1, 1},
        {2, 2},
        {4, 4},
        {8, 8},
    },

    // horizontal rectangle
    {
        {2, 1},
        {4, 1},
        {4, 2},
        {8, 4},
    },

    // vertical rectangle
    {
        {1, 2},
        {1, 4},
        {2, 4},
        {4, 8},
    },
};

static const u16 sCrc16Table[] =
{
    0x0000, 0x1189, 0x2312, 0x329B, 0x4624, 0x57AD, 0x6536, 0x74BF,
    0x8C48, 0x9DC1, 0xAF5A, 0xBED3, 0xCA6C, 0xDBE5, 0xE97E, 0xF8F7,
    0x1081, 0x0108, 0x3393, 0x221A, 0x56A5, 0x472C, 0x75B7, 0x643E,
    0x9CC9, 0x8D40, 0xBFDB, 0xAE52, 0xDAED, 0xCB64, 0xF9FF, 0xE876,
    0x2102, 0x308B, 0x0210, 0x1399, 0x6726, 0x76AF, 0x4434, 0x55BD,
    0xAD4A, 0xBCC3, 0x8E58, 0x9FD1, 0xEB6E, 0xFAE7, 0xC87C, 0xD9F5,
    0x3183, 0x200A, 0x1291, 0x0318, 0x77A7, 0x662E, 0x54B5, 0x453C,
    0xBDCB, 0xAC42, 0x9ED9, 0x8F50, 0xFBEF, 0xEA66, 0xD8FD, 0xC974,
    0x4204, 0x538D, 0x6116, 0x709F, 0x0420, 0x15A9, 0x2732, 0x36BB,
    0xCE4C, 0xDFC5, 0xED5E, 0xFCD7, 0x8868, 0x99E1, 0xAB7A, 0xBAF3,
    0x5285, 0x430C, 0x7197, 0x601E, 0x14A1, 0x0528, 0x37B3, 0x263A,
    0xDECD, 0xCF44, 0xFDDF, 0xEC56, 0x98E9, 0x8960, 0xBBFB, 0xAA72,
    0x6306, 0x728F, 0x4014, 0x519D, 0x2522, 0x34AB, 0x0630, 0x17B9,
    0xEF4E, 0xFEC7, 0xCC5C, 0xDDD5, 0xA96A, 0xB8E3, 0x8A78, 0x9BF1,
    0x7387, 0x620E, 0x5095, 0x411C, 0x35A3, 0x242A, 0x16B1, 0x0738,
    0xFFCF, 0xEE46, 0xDCDD, 0xCD54, 0xB9EB, 0xA862, 0x9AF9, 0x8B70,
    0x8408, 0x9581, 0xA71A, 0xB693, 0xC22C, 0xD3A5, 0xE13E, 0xF0B7,
    0x0840, 0x19C9, 0x2B52, 0x3ADB, 0x4E64, 0x5FED, 0x6D76, 0x7CFF,
    0x9489, 0x8500, 0xB79B, 0xA612, 0xD2AD, 0xC324, 0xF1BF, 0xE036,
    0x18C1, 0x0948, 0x3BD3, 0x2A5A, 0x5EE5, 0x4F6C, 0x7DF7, 0x6C7E,
    0xA50A, 0xB483, 0x8618, 0x9791, 0xE32E, 0xF2A7, 0xC03C, 0xD1B5,
    0x2942, 0x38CB, 0x0A50, 0x1BD9, 0x6F66, 0x7EEF, 0x4C74, 0x5DFD,
    0xB58B, 0xA402, 0x9699, 0x8710, 0xF3AF, 0xE226, 0xD0BD, 0xC134,
    0x39C3, 0x284A, 0x1AD1, 0x0B58, 0x7FE7, 0x6E6E, 0x5CF5, 0x4D7C,
    0xC60C, 0xD785, 0xE51E, 0xF497, 0x8028, 0x91A1, 0xA33A, 0xB2B3,
    0x4A44, 0x5BCD, 0x6956, 0x78DF, 0x0C60, 0x1DE9, 0x2F72, 0x3EFB,
    0xD68D, 0xC704, 0xF59F, 0xE416, 0x90A9, 0x8120, 0xB3BB, 0xA232,
    0x5AC5, 0x4B4C, 0x79D7, 0x685E, 0x1CE1, 0x0D68, 0x3FF3, 0x2E7A,
    0xE70E, 0xF687, 0xC41C, 0xD595, 0xA12A, 0xB0A3, 0x8238, 0x93B1,
    0x6B46, 0x7ACF, 0x4854, 0x59DD, 0x2D62, 0x3CEB, 0x0E70, 0x1FF9,
    0xF78F, 0xE606, 0xD49D, 0xC514, 0xB1AB, 0xA022, 0x92B9, 0x8330,
    0x7BC7, 0x6A4E, 0x58D5, 0x495C, 0x3DE3, 0x2C6A, 0x1EF1, 0x0F78,
};

const u8 gMiscBlank_Gfx[] = INCBIN_U8("graphics/interface/blank.4bpp");

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *))
{
    u8 sprite = CreateSprite(&sInvisibleSpriteTemplate, 248, 168, 14);
    gSprites[sprite].invisible = TRUE;
    gSprites[sprite].callback = callback;
    return sprite;
}

void StoreWordInTwoHalfwords(u16 *h, u32 w)
{
    h[0] = (u16)(w);
    h[1] = (u16)(w >> 16);
}

void LoadWordFromTwoHalfwords(u16 *h, u32 *w)
{
    *w = h[0] | (s16)h[1] << 16;
}

void SetBgAffineStruct(struct BgAffineSrcData *src, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha)
{
    src->texX = texX;
    src->texY = texY;
    src->scrX = scrX;
    src->scrY = scrY;
    src->sx = sx;
    src->sy = sy;
    src->alpha = alpha;
}

void DoBgAffineSet(struct BgAffineDstData *dest, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha)
{
    struct BgAffineSrcData src;

    SetBgAffineStruct(&src, texX, texY, scrX, scrY, sx, sy, alpha);
    BgAffineSet(&src, dest, 1);
}

#ifdef NONMATCHING

// Functionally equivalent.
// Only the two yflip loops don't match.
void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output)
{
    u8 x, y;
    s8 i, j;
    u8 xflip[32];
    u8 h = sSpriteDimensions[shape][size][1];
    u8 w = sSpriteDimensions[shape][size][0];

    for (y = 0; y < h; y++)
    {
        int filler = 32 - w;

        for (x = 0; x < w; x++)
        {
            int tile = (*tilemap & 0x3ff) * 32;
            int attr = *tilemap & 0xc00;

            if (attr == 0)
            {
                void *src = tiles + tile;
                void *dest = output;
                int length = 32;
                DmaCopy32(3, src, dest, length);
            }
            else if (attr == 0x800)  // yflip
            {
                for (i = 0; i < 8; i++)
                {
                    void *src = tiles;
                    void *dest = output;
                    int length = 4;
                    // this is likely wrong, but makes it closer to matching
                    src += tile + (7 - i) * 4;
                    dest += i * 4;
                    DmaCopy32(3, src, dest, length);
                }
            }
            else  // xflip
            {
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        u8 i2 = i * 4;
                        xflip[i2 + (3-j)] = (tiles[tile + i2 + j] & 0xf) << 4;
                        xflip[i2 + (3-j)] |= tiles[tile + i2 + j] >> 4;
                    }
                }
                if (*tilemap & 0x800)  // yflip
                {
                    for (i = 0; i < 8; i++)
                    {
                        void *src = xflip + (7-i) * 4;
                        void *dest = output + i*4;
                        int length = 4;
                        DmaCopy32(3, src, dest, length);
                    }
                }
                else
                {
                    void *src = xflip;
                    void *dest = output;
                    int length = 32;
                    DmaCopy32(3, src, dest, length);
                }
            }
            tilemap++;
            output += 32;
        }
        tilemap += filler;
    }
}

#else
__attribute__((naked)) void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output)
{
    asm("\n\
        .syntax unified\n\
        push {r4-r7,lr}\n\
        mov r7, r10\n\
        mov r6, r9\n\
        mov r5, r8\n\
        push {r5-r7}\n\
        sub sp, 0x38\n\
        str r2, [sp, 0x20]\n\
        adds r4, r3, 0\n\
        ldr r7, [sp, 0x58]\n\
        lsls r0, 24\n\
        lsls r1, 24\n\
        ldr r2, =sSpriteDimensions\n\
        lsrs r1, 23\n\
        lsrs r0, 21\n\
        adds r1, r0\n\
        adds r0, r2, 0x1\n\
        adds r0, r1, r0\n\
        ldrb r0, [r0]\n\
        str r0, [sp, 0x24]\n\
        adds r1, r2\n\
        ldrb r1, [r1]\n\
        str r1, [sp, 0x28]\n\
        movs r0, 0\n\
        b _0806F88C\n\
        .pool\n\
    _0806F740:\n\
        movs r5, 0\n\
        adds r0, 0x1\n\
        str r0, [sp, 0x30]\n\
        b _0806F874\n\
    _0806F748:\n\
        ldrh r0, [r4]\n\
        ldr r2, =0x000003ff\n\
        adds r1, r2, 0\n\
        ands r1, r0\n\
        lsls r1, 5\n\
        mov r8, r1\n\
        movs r2, 0xC0\n\
        lsls r2, 4\n\
        adds r1, r2, 0\n\
        ands r1, r0\n\
        mov r2, sp\n\
        strh r0, [r2, 0x34]\n\
        cmp r1, 0\n\
        bne _0806F788\n\
        ldr r0, [sp, 0x20]\n\
        add r0, r8\n\
        adds r1, r7, 0\n\
        ldr r2, =0x04000008\n\
        bl CpuSet\n\
        adds r4, 0x2\n\
        str r4, [sp, 0x2C]\n\
        adds r7, 0x20\n\
        mov r10, r7\n\
        adds r5, 0x1\n\
        mov r9, r5\n\
        b _0806F86A\n\
        .pool\n\
    _0806F788:\n\
        movs r0, 0x80\n\
        lsls r0, 4\n\
        cmp r1, r0\n\
        bne _0806F7CC\n\
        movs r1, 0\n\
        adds r4, 0x2\n\
        str r4, [sp, 0x2C]\n\
        movs r2, 0x20\n\
        adds r2, r7\n\
        mov r10, r2\n\
        adds r5, 0x1\n\
        mov r9, r5\n\
    _0806F7A0:\n\
        lsls r4, r1, 24\n\
        asrs r4, 24\n\
        movs r0, 0x7\n\
        subs r0, r4\n\
        lsls r0, 2\n\
        add r0, r8\n\
        ldr r1, [sp, 0x20]\n\
        adds r0, r1, r0\n\
        lsls r1, r4, 2\n\
        adds r1, r7, r1\n\
        ldr r2, =0x04000001\n\
        bl CpuSet\n\
        adds r4, 0x1\n\
        lsls r4, 24\n\
        lsrs r1, r4, 24\n\
        asrs r4, 24\n\
        cmp r4, 0x7\n\
        ble _0806F7A0\n\
        b _0806F86A\n\
        .pool\n\
    _0806F7CC:\n\
        movs r1, 0\n\
        adds r4, 0x2\n\
        str r4, [sp, 0x2C]\n\
        movs r2, 0x20\n\
        adds r2, r7\n\
        mov r10, r2\n\
        adds r5, 0x1\n\
        mov r9, r5\n\
        movs r0, 0xF\n\
        mov r12, r0\n\
    _0806F7E0:\n\
        movs r2, 0\n\
        lsls r4, r1, 24\n\
        lsls r0, r4, 2\n\
        lsrs r0, 24\n\
        adds r6, r0, 0x3\n\
        mov r1, r8\n\
        adds r5, r1, r0\n\
    _0806F7EE:\n\
        lsls r1, r2, 24\n\
        asrs r1, 24\n\
        subs r0, r6, r1\n\
        mov r2, sp\n\
        adds r3, r2, r0\n\
        adds r0, r5, r1\n\
        ldr r2, [sp, 0x20]\n\
        adds r0, r2, r0\n\
        ldrb r2, [r0]\n\
        mov r0, r12\n\
        ands r0, r2\n\
        lsls r0, 4\n\
        lsrs r2, 4\n\
        orrs r0, r2\n\
        strb r0, [r3]\n\
        adds r1, 0x1\n\
        lsls r1, 24\n\
        lsrs r2, r1, 24\n\
        asrs r1, 24\n\
        cmp r1, 0x3\n\
        ble _0806F7EE\n\
        movs r1, 0x80\n\
        lsls r1, 17\n\
        adds r0, r4, r1\n\
        lsrs r1, r0, 24\n\
        asrs r0, 24\n\
        cmp r0, 0x7\n\
        ble _0806F7E0\n\
        mov r2, sp\n\
        ldrh r0, [r2, 0x34]\n\
        movs r2, 0x80\n\
        lsls r2, 4\n\
        ands r0, r2\n\
        cmp r0, 0\n\
        beq _0806F860\n\
        movs r1, 0\n\
    _0806F836:\n\
        lsls r4, r1, 24\n\
        asrs r4, 24\n\
        movs r0, 0x7\n\
        subs r0, r4\n\
        lsls r0, 2\n\
        add r0, sp\n\
        lsls r1, r4, 2\n\
        adds r1, r7, r1\n\
        ldr r2, =0x04000001\n\
        bl CpuSet\n\
        adds r4, 0x1\n\
        lsls r4, 24\n\
        lsrs r1, r4, 24\n\
        asrs r4, 24\n\
        cmp r4, 0x7\n\
        ble _0806F836\n\
        b _0806F86A\n\
        .pool\n\
    _0806F860:\n\
        mov r0, sp\n\
        adds r1, r7, 0\n\
        ldr r2, =0x04000008\n\
        bl CpuSet\n\
    _0806F86A:\n\
        ldr r4, [sp, 0x2C]\n\
        mov r7, r10\n\
        mov r1, r9\n\
        lsls r0, r1, 24\n\
        lsrs r5, r0, 24\n\
    _0806F874:\n\
        ldr r2, [sp, 0x28]\n\
        cmp r5, r2\n\
        bcs _0806F87C\n\
        b _0806F748\n\
    _0806F87C:\n\
        movs r0, 0x20\n\
        ldr r1, [sp, 0x28]\n\
        subs r0, r1\n\
        lsls r0, 1\n\
        adds r4, r0\n\
        ldr r2, [sp, 0x30]\n\
        lsls r0, r2, 24\n\
        lsrs r0, 24\n\
    _0806F88C:\n\
        ldr r1, [sp, 0x24]\n\
        cmp r0, r1\n\
        bcs _0806F894\n\
        b _0806F740\n\
    _0806F894:\n\
        add sp, 0x38\n\
        pop {r3-r5}\n\
        mov r8, r3\n\
        mov r9, r4\n\
        mov r10, r5\n\
        pop {r4-r7}\n\
        pop {r0}\n\
        bx r0\n\
        .pool\n\
        .syntax divided");
}

#endif // NONMATCHING

int CountTrailingZeroBits(u32 value)
{
    u8 i;

    for (i = 0; i < 32; i++)
    {
        if ((value & 1) == 0)
            value >>= 1;
        else
            return i;
    }
    return 0;
}

u16 CalcCRC16(u8 *data, s32 length)
{
    u16 i, j;
    u16 crc = 0x1121;

    for (i = 0; i < length; i++)
    {
        crc ^= data[i];
        for (j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8408;
            else
                crc >>= 1;
        }
    }
    return ~crc;
}

u16 CalcCRC16WithTable(u8 *data, u32 length)
{
    u16 i;
    u16 crc = 0x1121;
    u8 byte;

    for (i = 0; i < length; i++)
    {
        byte = crc >> 8;
        crc ^= data[i];
        crc = byte ^ sCrc16Table[(u8)crc];
    }
    return ~crc;
}

u32 CalcByteArraySum(const u8* data, u32 length)
{
    u32 sum, i;
    for (sum = 0, i = 0; i < length; i++)
        sum += data[i];
    return sum;
}
