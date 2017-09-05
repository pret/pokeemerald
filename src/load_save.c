#include "global.h"
#include "gba/flash_internal.h"
#include "load_save.h"
#include "main.h"
#include "pokemon.h"
#include "rng.h"
#include "malloc.h"

extern u8 gPlayerPartyCount;
extern struct PokemonStorage* gPokemonStoragePtr;
extern void* gUnknown_0203CF5C;
extern u8 gHeap[0x1C000];

extern bool16 IdentifyFlash(void);
extern void SetBagItemsPointers(void);
extern void SetDecorationInventoriesPointers(void);
extern void InitHeap(void *heapStart, u32 heapSize);

void ApplyNewEncyprtionKeyToAllEncryptedData(u32 encryptionKey);

#define SAVEBLOCK_MOVE_RANGE    128

EWRAM_DATA struct SaveBlock2 gSaveblock2 = {0};
EWRAM_DATA u8 gSaveblock2_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct SaveBlock1 gSaveblock1 = {0};
EWRAM_DATA u8 gSaveblock1_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct PokemonStorage gPokemonStorage = {0};
EWRAM_DATA u8 gSaveblock3_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

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

struct SaveBlocksInOne
{
    struct SaveBlock2 sav2;
    struct SaveBlock1 sav1;
    struct PokemonStorage sav3;
};
/*
void MoveSaveBlocks_ResetHeap(void)
{
    void *vblankCB, *hblankCB;
    u32 encryptionKey;
    struct SaveBlocksInOne* copiedSavs;

    // save interrupt functions and turn them off
    vblankCB = gMain.vblankCallback;
    hblankCB = gMain.hblankCallback;
    gMain.vblankCallback = NULL;
    gMain.hblankCallback = NULL;
    gUnknown_0203CF5C = NULL;

    copiedSavs = (void*)(gHeap);

    // copy saveblocks' content
    copiedSavs->sav2 = *gSaveBlock2Ptr;
    copiedSavs->sav1 = *gSaveBlock1Ptr;
    copiedSavs->sav3 = *gPokemonStoragePtr;

    // change saveblocks' pointers
    // argument is a sum of the individual trainerId bytes
    SetSaveBlocksPointers(copiedSavs->sav2.playerTrainerId[0] + copiedSavs->sav2.playerTrainerId[1] + copiedSavs->sav2.playerTrainerId[2] + copiedSavs->sav2.playerTrainerId[3]);

    // restore saveblock data since the pointers changed
    *gSaveBlock2Ptr = copiedSavs->sav2;
    *gSaveBlock1Ptr = copiedSavs->sav1;
    *gPokemonStoragePtr = copiedSavs->sav3;

    // heap was destroyed in the copying process, so reset it
    InitHeap(gHeap, sizeof(gHeap));

    // restore interrupt functions
    gMain.hblankCallback = hblankCB;
    gMain.vblankCallback = vblankCB;

    // create a new encryption key
    encryptionKey = (Random() << 0x10) + (Random());
    ApplyNewEncyprtionKeyToAllEncryptedData(encryptionKey);
    gSaveBlock2Ptr->encryptionKey = encryptionKey;
}*/
