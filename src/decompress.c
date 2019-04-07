#include "global.h"
#include "alloc.h"
#include "data.h"
#include "decompress.h"
#include "pokemon.h"
#include "text.h"
#include "constants/species.h"

EWRAM_DATA ALIGNED(4) u8 gDecompressionBuffer[0x4000] = {0};

static void DuplicateDeoxysTiles(void *pointer, s32 species);

void LZDecompressWram(const u32 *src, void *dest)
{
    LZ77UnCompWram(src, dest);
}

void LZDecompressVram(const u32 *src, void *dest)
{
    LZ77UnCompVram(src, dest);
}

u16 LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src)
{
    struct SpriteSheet dest;

    LZ77UnCompWram(src->data, gDecompressionBuffer);
    dest.data = gDecompressionBuffer;
    dest.size = src->size;
    dest.tag = src->tag;
    return LoadSpriteSheet(&dest);
}

void LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer)
{
    struct SpriteSheet dest;

    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;
    LoadSpriteSheet(&dest);
}

void LoadCompressedSpritePalette(const struct CompressedSpritePalette *src)
{
    struct SpritePalette dest;

    LZ77UnCompWram(src->data, gDecompressionBuffer);
    dest.data = (void*) gDecompressionBuffer;
    dest.tag = src->tag;
    LoadSpritePalette(&dest);
}

void LoadCompressedSpritePaletteOverrideBuffer(const struct CompressedSpritePalette *a, void *buffer)
{
    struct SpritePalette dest;

    LZ77UnCompWram(a->data, buffer);
    dest.data = buffer;
    dest.tag = a->tag;
    LoadSpritePalette(&dest);
}

void DecompressPicFromTable(const struct CompressedSpriteSheet *src, void* buffer, s32 species)
{
    if (species > NUM_SPECIES)
        LZ77UnCompWram(gMonFrontPicTable[0].data, buffer);
    else
        LZ77UnCompWram(src->data, buffer);
    DuplicateDeoxysTiles(buffer, species);
}

void HandleLoadSpecialPokePic(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality)
{
    bool8 isFrontPic;

    if (src == &gMonFrontPicTable[species])
        isFrontPic = TRUE; // frontPic
    else
        isFrontPic = FALSE; // backPic

    LoadSpecialPokePic_2(src, dest, species, personality, isFrontPic);
}

void LoadSpecialPokePic(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic)
{
    if (species == SPECIES_UNOWN)
    {
        u32 id = GetUnownSpeciesId(personality);

        if (!isFrontPic)
            LZ77UnCompWram(gMonBackPicTable[id].data, dest);
        else
            LZ77UnCompWram(gMonFrontPicTable[id].data, dest);
    }
    else if (species > NUM_SPECIES) // is species unknown? draw the ? icon
        LZ77UnCompWram(gMonFrontPicTable[0].data, dest);
    else
        LZ77UnCompWram(src->data, dest);

    DuplicateDeoxysTiles(dest, species);
    DrawSpindaSpots(species, personality, dest, isFrontPic);
}

void Unused_LZDecompressWramIndirect(const void **src, void *dest)
{
    LZ77UnCompWram(*src, dest);
}

// This one (unused) function is really challenging, won't even try to decompile it.
NAKED
void sub_803471C()
{
    asm(".syntax unified\n\
        push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x24\n\
    mov r9, r0\n\
    str r1, [sp]\n\
    str r2, [sp, 0x4]\n\
    adds r5, r3, 0\n\
    movs r0, 0x1\n\
    mov r1, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0803473C\n\
    b _080348D4\n\
_0803473C:\n\
    asrs r0, r1, 1\n\
    adds r0, 0x4\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    str r0, [sp, 0x8]\n\
    movs r0, 0\n\
    ldr r2, [sp]\n\
    cmp r0, r2\n\
    blt _08034750\n\
    b _08034964\n\
_08034750:\n\
    movs r4, 0x8\n\
    subs r1, r4, r1\n\
    str r1, [sp, 0x10]\n\
_08034756:\n\
    movs r7, 0\n\
    adds r0, 0x1\n\
    str r0, [sp, 0x14]\n\
    ldr r0, [sp, 0x10]\n\
    cmp r7, r0\n\
    bge _080347D2\n\
    ldr r1, [sp, 0x8]\n\
    lsls r1, 8\n\
    str r1, [sp, 0x18]\n\
    movs r2, 0\n\
    mov r10, r2\n\
    mov r0, r9\n\
    movs r4, 0x8\n\
    subs r0, r4, r0\n\
    str r0, [sp, 0xC]\n\
_08034774:\n\
    movs r3, 0\n\
    asrs r0, r7, 1\n\
    adds r1, r7, 0\n\
    movs r2, 0x1\n\
    ands r1, r2\n\
    str r1, [sp, 0x20]\n\
    lsls r0, 8\n\
    mov r8, r0\n\
    mov r12, r5\n\
_08034786:\n\
    lsls r1, r3, 5\n\
    ldr r4, [sp, 0x18]\n\
    adds r0, r5, r4\n\
    adds r0, r1\n\
    mov r1, r8\n\
    adds r2, r0, r1\n\
    mov r1, r12\n\
    add r1, r8\n\
    movs r6, 0xF\n\
_08034798:\n\
    ldr r4, [sp, 0x20]\n\
    cmp r4, 0\n\
    bne _080347A8\n\
    strb r4, [r1]\n\
    add r4, sp, 0x20\n\
    ldrb r4, [r4]\n\
    strb r4, [r2, 0x10]\n\
    b _080347B6\n\
_080347A8:\n\
    mov r0, r10\n\
    strb r0, [r1, 0x10]\n\
    movs r4, 0x80\n\
    lsls r4, 1\n\
    adds r4, r2, r4\n\
    str r4, [sp, 0x1C]\n\
    strb r0, [r4]\n\
_080347B6:\n\
    adds r2, 0x1\n\
    adds r1, 0x1\n\
    subs r6, 0x1\n\
    cmp r6, 0\n\
    bge _08034798\n\
    movs r0, 0x20\n\
    add r12, r0\n\
    adds r3, 0x1\n\
    cmp r3, 0x7\n\
    ble _08034786\n\
    adds r7, 0x1\n\
    ldr r1, [sp, 0xC]\n\
    cmp r7, r1\n\
    blt _08034774\n\
_080347D2:\n\
    movs r7, 0\n\
    movs r2, 0\n\
_080347D6:\n\
    movs r6, 0\n\
    adds r4, r7, 0x1\n\
    mov r8, r4\n\
    lsls r4, r7, 5\n\
_080347DE:\n\
    adds r0, r6, 0x1\n\
    mov r10, r0\n\
    lsls r1, r6, 8\n\
    adds r0, r1, 0\n\
    adds r0, 0xC0\n\
    adds r0, r5, r0\n\
    adds r0, r4\n\
    adds r1, r5, r1\n\
    adds r1, r4\n\
    movs r3, 0x1F\n\
_080347F2:\n\
    strb r2, [r1]\n\
    strb r2, [r0]\n\
    adds r0, 0x1\n\
    adds r1, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _080347F2\n\
    mov r6, r10\n\
    cmp r6, 0x7\n\
    ble _080347DE\n\
    mov r7, r8\n\
    cmp r7, 0x1\n\
    ble _080347D6\n\
    mov r1, r9\n\
    cmp r1, 0x5\n\
    bne _08034818\n\
    movs r2, 0x90\n\
    lsls r2, 1\n\
    adds r5, r2\n\
_08034818:\n\
    movs r7, 0\n\
    cmp r7, r9\n\
    bge _080348AE\n\
_0803481E:\n\
    movs r3, 0\n\
    adds r7, 0x1\n\
    mov r8, r7\n\
    cmp r3, r9\n\
    bge _0803488E\n\
_08034828:\n\
    adds r3, 0x1\n\
    mov r10, r3\n\
    ldr r4, [sp, 0x4]\n\
    adds r4, 0x20\n\
    adds r7, r5, 0\n\
    adds r7, 0x20\n\
    movs r0, 0x12\n\
    adds r0, r5\n\
    mov r12, r0\n\
    ldr r2, [sp, 0x4]\n\
    adds r3, r5, 0\n\
    movs r6, 0x3\n\
_08034840:\n\
    ldrb r0, [r2]\n\
    mov r1, r12\n\
    strb r0, [r1]\n\
    ldrb r0, [r2, 0x1]\n\
    strb r0, [r1, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    strb r0, [r1, 0x1E]\n\
    ldrb r0, [r2, 0x3]\n\
    strb r0, [r1, 0x1F]\n\
    movs r0, 0x81\n\
    lsls r0, 1\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x10]\n\
    strb r0, [r1]\n\
    ldr r0, =0x00000103\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x11]\n\
    strb r0, [r1]\n\
    movs r0, 0x90\n\
    lsls r0, 1\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x12]\n\
    strb r0, [r1]\n\
    ldr r0, =0x00000121\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x13]\n\
    strb r0, [r1]\n\
    movs r1, 0x4\n\
    add r12, r1\n\
    adds r2, 0x4\n\
    adds r3, 0x4\n\
    subs r6, 0x1\n\
    cmp r6, 0\n\
    bge _08034840\n\
    str r4, [sp, 0x4]\n\
    adds r5, r7, 0\n\
    mov r3, r10\n\
    cmp r3, r9\n\
    blt _08034828\n\
_0803488E:\n\
    mov r2, r9\n\
    cmp r2, 0x7\n\
    bne _080348A0\n\
    adds r5, 0x20\n\
    b _080348A8\n\
    .pool\n\
_080348A0:\n\
    mov r4, r9\n\
    cmp r4, 0x5\n\
    bne _080348A8\n\
    adds r5, 0x60\n\
_080348A8:\n\
    mov r7, r8\n\
    cmp r7, r9\n\
    blt _0803481E\n\
_080348AE:\n\
    mov r0, r9\n\
    cmp r0, 0x7\n\
    bne _080348BC\n\
    movs r1, 0x80\n\
    lsls r1, 1\n\
    adds r5, r1\n\
    b _080348C8\n\
_080348BC:\n\
    mov r2, r9\n\
    cmp r2, 0x5\n\
    bne _080348C8\n\
    movs r4, 0xF0\n\
    lsls r4, 1\n\
    adds r5, r4\n\
_080348C8:\n\
    ldr r0, [sp, 0x14]\n\
    ldr r1, [sp]\n\
    cmp r0, r1\n\
    bge _080348D2\n\
    b _08034756\n\
_080348D2:\n\
    b _08034964\n\
_080348D4:\n\
    movs r6, 0\n\
    ldr r2, [sp]\n\
    cmp r6, r2\n\
    bge _08034964\n\
_080348DC:\n\
    adds r6, 0x1\n\
    mov r10, r6\n\
    mov r4, r9\n\
    cmp r4, 0x6\n\
    bne _080348F4\n\
    movs r0, 0\n\
    movs r3, 0xFF\n\
_080348EA:\n\
    strb r0, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _080348EA\n\
_080348F4:\n\
    movs r7, 0\n\
    cmp r7, r9\n\
    bge _08034948\n\
_080348FA:\n\
    adds r7, 0x1\n\
    mov r8, r7\n\
    mov r1, r9\n\
    lsls r0, r1, 5\n\
    cmp r1, 0x6\n\
    bne _08034914\n\
    movs r1, 0\n\
    movs r3, 0x1F\n\
_0803490A:\n\
    strb r1, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0803490A\n\
_08034914:\n\
    adds r1, r0, 0\n\
    cmp r1, 0\n\
    ble _0803492E\n\
    adds r3, r1, 0\n\
_0803491C:\n\
    ldr r2, [sp, 0x4]\n\
    ldrb r0, [r2]\n\
    strb r0, [r5]\n\
    adds r2, 0x1\n\
    str r2, [sp, 0x4]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bne _0803491C\n\
_0803492E:\n\
    mov r4, r9\n\
    cmp r4, 0x6\n\
    bne _08034942\n\
    movs r0, 0\n\
    movs r3, 0x1F\n\
_08034938:\n\
    strb r0, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _08034938\n\
_08034942:\n\
    mov r7, r8\n\
    cmp r7, r9\n\
    blt _080348FA\n\
_08034948:\n\
    mov r0, r9\n\
    cmp r0, 0x6\n\
    bne _0803495C\n\
    movs r0, 0\n\
    movs r3, 0xFF\n\
_08034952:\n\
    strb r0, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _08034952\n\
_0803495C:\n\
    mov r6, r10\n\
    ldr r1, [sp]\n\
    cmp r6, r1\n\
    blt _080348DC\n\
_08034964:\n\
    add sp, 0x24\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
        .syntax divided");
}

u32 GetDecompressedDataSize(const u32 *ptr)
{
    const u8 *ptr8 = (const u8 *)ptr;
    return (ptr8[3] << 16) | (ptr8[2] << 8) | (ptr8[1]);
}

bool8 LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet* src)
{
    struct SpriteSheet dest;
    void* buffer;

    buffer = AllocZeroed(*((u32*)(&src->data[0])) >> 8);
    LZ77UnCompWram(src->data, buffer);

    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;

    LoadSpriteSheet(&dest);
    Free(buffer);
    return FALSE;
}

bool8 LoadCompressedSpritePaletteUsingHeap(const struct CompressedSpritePalette *src)
{
    struct SpritePalette dest;
    void* buffer;

    buffer = AllocZeroed(*((u32*)(&src->data[0])) >> 8);
    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.tag = src->tag;

    LoadSpritePalette(&dest);
    Free(buffer);
    return FALSE;
}

void DecompressPicFromTable_2(const struct CompressedSpriteSheet *src, void* buffer, s32 species) // a copy of DecompressPicFromTable
{
    if (species > NUM_SPECIES)
        LZ77UnCompWram(gMonFrontPicTable[0].data, buffer);
    else
        LZ77UnCompWram(src->data, buffer);
    DuplicateDeoxysTiles(buffer, species);
}

void LoadSpecialPokePic_2(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic) // a copy of LoadSpecialPokePic
{
    if (species == SPECIES_UNOWN)
    {
        u32 id = GetUnownSpeciesId(personality);

        if (!isFrontPic)
            LZ77UnCompWram(gMonBackPicTable[id].data, dest);
        else
            LZ77UnCompWram(gMonFrontPicTable[id].data, dest);
    }
    else if (species > NUM_SPECIES) // is species unknown? draw the ? icon
        LZ77UnCompWram(gMonFrontPicTable[0].data, dest);
    else
        LZ77UnCompWram(src->data, dest);

    DuplicateDeoxysTiles(dest, species);
    DrawSpindaSpots(species, personality, dest, isFrontPic);
}

void HandleLoadSpecialPokePic_2(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality) // a copy of HandleLoadSpecialPokePic
{
    bool8 isFrontPic;

    if (src == &gMonFrontPicTable[species])
        isFrontPic = TRUE; // frontPic
    else
        isFrontPic = FALSE; // backPic

    LoadSpecialPokePic_2(src, dest, species, personality, isFrontPic);
}

void DecompressPicFromTable_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void* buffer, s32 species)
{
    if (species > NUM_SPECIES)
        LZ77UnCompWram(gMonFrontPicTable[0].data, buffer);
    else
        LZ77UnCompWram(src->data, buffer);
}

void HandleLoadSpecialPokePic_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality)
{
    bool8 isFrontPic;

    if (src == &gMonFrontPicTable[species])
        isFrontPic = TRUE; // frontPic
    else
        isFrontPic = FALSE; // backPic

    LoadSpecialPokePic_DontHandleDeoxys(src, dest, species, personality, isFrontPic);
}

void LoadSpecialPokePic_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic)
{
    if (species == SPECIES_UNOWN)
    {
        u32 id = GetUnownSpeciesId(personality);

        if (!isFrontPic)
            LZ77UnCompWram(gMonBackPicTable[id].data, dest);
        else
            LZ77UnCompWram(gMonFrontPicTable[id].data, dest);
    }
    else if (species > NUM_SPECIES) // is species unknown? draw the ? icon
        LZ77UnCompWram(gMonFrontPicTable[0].data, dest);
    else
        LZ77UnCompWram(src->data, dest);

    DrawSpindaSpots(species, personality, dest, isFrontPic);
}

static void DuplicateDeoxysTiles(void *pointer, s32 species)
{
    if (species == SPECIES_DEOXYS)
        CpuCopy32(pointer + 0x800, pointer, 0x800);
}
