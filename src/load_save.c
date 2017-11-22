#include "global.h"
#include "gba/flash_internal.h"
#include "load_save.h"
#include "main.h"
#include "pokemon.h"
#include "rng.h"

extern void* gUnknown_0203CF5C;

extern bool16 IdentifyFlash(void);
extern void SetBagItemsPointers(void);
extern void SetDecorationInventoriesPointers(void);

void ApplyNewEncyprtionKeyToAllEncryptedData(u32 encryptionKey);

#define SAVEBLOCK_MOVE_RANGE    128

EWRAM_DATA struct SaveBlock2 gSaveblock2 = {0};
EWRAM_DATA u8 gSaveblock2_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct SaveBlock1 gSaveblock1 = {0};
EWRAM_DATA u8 gSaveblock1_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct PokemonStorage gPokemonStorage = {0};
EWRAM_DATA u8 gSaveblock3_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

extern void InitHeap(void *pointer, u32 size);

void CheckForFlashMemory(void)
{
    if (!IdentifyFlash())
    {
        gFlashMemoryPresent = TRUE;
        InitFlashTimer();
    }
    else
        gFlashMemoryPresent = FALSE;
}

void ClearSav2(void)
{
    CpuFill16(0, &gSaveblock2, sizeof(struct SaveBlock2) + sizeof(gSaveblock2_DMA));
}

void ClearSav1(void)
{
    CpuFill16(0, &gSaveblock1, sizeof(struct SaveBlock1) + sizeof(gSaveblock1_DMA));
}

void SetSaveBlocksPointers(u16 offset)
{
    struct SaveBlock1** sav1_LocalVar = &gSaveBlock1Ptr;

    offset = (offset + Random()) & (SAVEBLOCK_MOVE_RANGE - 4);

    gSaveBlock2Ptr = (void*)(&gSaveblock2) + offset;
    *sav1_LocalVar = (void*)(&gSaveblock1) + offset;
    gPokemonStoragePtr = (void*)(&gPokemonStorage) + offset;

    SetBagItemsPointers();
    SetDecorationInventoriesPointers();
}

// stuff i used to try and match MoveSaveBlocks_ResetHeap
struct SaveBlocksInOne
{
    struct SaveBlock2 sav2;
    struct SaveBlock1 sav1;
    struct PokemonStorage sav3;
};

extern struct SaveBlocksInOne gHeap;

#define ewram_addr 0x02000000 // oh no...
#define ewram_addr2 0x02000f2c
#define ewram_addr3 0x02004cb4

#define eSaveBlockCopy            (*(struct SaveBlocksInOne *)(ewram_addr + 0x0))
#define eSaveBlock2Copy           (*(struct SaveBlock2 *)((void*)(ewram_addr + 0x0)))
#define eSaveBlock1Copy           (*(struct SaveBlock1 *)((void*)(ewram_addr + sizeof(struct SaveBlock2))))
#define eSaveBlock3Copy           (*(struct PokemonStorage *)((void*)(ewram_addr + sizeof(struct SaveBlock2) + sizeof(struct SaveBlock1))))

#ifdef NONMATCHING // this is one devil of a motherfucker
/*
    The reason MoveSaveBlocks_ResetHeap mismatches is due to incorrect memcpys. Various
    things have been tried, such as: direct struct copys, ewram casts, use of defining
    the addresses manually, using memcpy anyway, delayed allocation of pointers at
    the start of function, as seen above and below. Scope declaration has been used to try and
    reproduce the correct macro thought to be used, but nothing has worked. It is worth
    noting that at this point that the compiler will delay the allocation of the save block
    pointers at the beginningto be allocated later: which might matter for matching this.
    Due to loading shared ewram heap areas directly, it is very likely emerald used ewram
    defines for this function, but there is no known example of a matching define.
    In addition, dead code might be present in the form of a runtime variable used
    to fix the address of the save blocks. This has been tested and is shown to affect
    the registers as well.
*/
void MoveSaveBlocks_ResetHeap(void)
{
    void *vblankCB, *hblankCB;
    u32 encryptionKey;
    struct SaveBlock1 **sav1Copy = &gSaveBlock1Ptr; // r10;

    // save interrupt functions and turn them off
    vblankCB = gMain.vblankCallback;
    hblankCB = gMain.hblankCallback;
    gMain.vblankCallback = NULL;
    gMain.hblankCallback = NULL;
    gUnknown_0203CF5C = NULL;

    // backup the saves.
    eSaveBlock1Copy = **sav1Copy;
    eSaveBlock2Copy = *gSaveBlock2Ptr;
    eSaveBlock3Copy = *gPokemonStoragePtr;

    // change saveblocks' pointers
    // argument is a sum of the individual trainerId bytes
    SetSaveBlocksPointers(eSaveBlock2Copy.playerTrainerId[0] + eSaveBlock2Copy.playerTrainerId[1] + eSaveBlock2Copy.playerTrainerId[2] + eSaveBlock2Copy.playerTrainerId[3]);

    // restore saveblock data since the pointers changed
    **sav1Copy = eSaveBlock1Copy;
    *gSaveBlock2Ptr = eSaveBlock2Copy;
    *gPokemonStoragePtr = eSaveBlock3Copy;

    // heap was destroyed in the copying process, so reset it
    InitHeap((void*)(0x02000000), 0x1C000);

    // restore interrupt functions
    gMain.hblankCallback = hblankCB;
    gMain.vblankCallback = vblankCB;

    // create a new encryption key
    encryptionKey = (Random() << 0x10) + (Random());
    ApplyNewEncyprtionKeyToAllEncryptedData(encryptionKey);
    gSaveBlock2Ptr->encryptionKey = encryptionKey;
}
#else
__attribute__((naked))
void MoveSaveBlocks_ResetHeap(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x8\n\
    ldr r5, =gMain\n\
    ldr r0, [r5, 0xC]\n\
    str r0, [sp]\n\
    ldr r1, [r5, 0x10]\n\
    str r1, [sp, 0x4]\n\
    movs r0, 0\n\
    str r0, [r5, 0xC]\n\
    str r0, [r5, 0x10]\n\
    ldr r1, =gUnknown_0203CF5C\n\
    str r0, [r1]\n\
    ldr r4, =0x02000000\n\
    ldr r0, =gSaveBlock2Ptr\n\
    ldr r1, [r0]\n\
    ldr r6, =0x00000f2c\n\
    adds r0, r4, 0\n\
    adds r2, r6, 0\n\
    bl memcpy\n\
    ldr r1, =gSaveBlock1Ptr\n\
    mov r10, r1\n\
    ldr r1, [r1]\n\
    ldr r7, =0x00003d88\n\
    ldr r0, =0x02000f2c\n\
    adds r2, r7, 0\n\
    bl memcpy\n\
    ldr r0, =gPokemonStoragePtr\n\
    mov r8, r0\n\
    ldr r1, [r0]\n\
    ldr r0, =0x000083d0\n\
    mov r9, r0\n\
    ldr r0, =0x02004cb4\n\
    mov r2, r9\n\
    bl memcpy\n\
    ldrb r1, [r4, 0xA]\n\
    ldrb r0, [r4, 0xB]\n\
    adds r1, r0\n\
    ldrb r0, [r4, 0xC]\n\
    adds r1, r0\n\
    ldrb r0, [r4, 0xD]\n\
    adds r0, r1\n\
    bl SetSaveBlocksPointers\n\
    ldr r1, =gSaveBlock2Ptr\n\
    ldr r0, [r1]\n\
    adds r1, r4, 0\n\
    adds r2, r6, 0\n\
    bl memcpy\n\
    mov r1, r10\n\
    ldr r0, [r1]\n\
    ldr r1, =0x02000f2c\n\
    adds r2, r7, 0\n\
    bl memcpy\n\
    mov r1, r8\n\
    ldr r0, [r1]\n\
    ldr r1, =0x02004cb4\n\
    mov r2, r9\n\
    bl memcpy\n\
    movs r1, 0xE0\n\
    lsls r1, 9\n\
    adds r0, r4, 0\n\
    bl InitHeap\n\
    ldr r0, [sp, 0x4]\n\
    str r0, [r5, 0x10]\n\
    ldr r1, [sp]\n\
    str r1, [r5, 0xC]\n\
    bl Random\n\
    adds r4, r0, 0\n\
    bl Random\n\
    lsls r4, 16\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    adds r4, r0\n\
    adds r0, r4, 0\n\
    bl ApplyNewEncyprtionKeyToAllEncryptedData\n\
    ldr r1, =gSaveBlock2Ptr\n\
    ldr r0, [r1]\n\
    adds r0, 0xAC\n\
    str r4, [r0]\n\
    add sp, 0x8\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");
}
#endif
