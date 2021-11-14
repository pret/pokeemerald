#ifndef GUARD_LOAD_SAVE_H
#define GUARD_LOAD_SAVE_H

#include "pokemon_storage_system.h"

#define SAVEBLOCK_MOVE_RANGE    128

/**
 * These structs are to prevent them from being reordered on newer or modern
 * toolchains. If this is not done, the ClearSav functions will end up erasing
 * the wrong memory leading to various glitches.
 */
struct SaveBlock2DMA {
    struct SaveBlock2 block;
    u8 dma[SAVEBLOCK_MOVE_RANGE];
};

struct SaveBlock1DMA {
    struct SaveBlock1 block;
    u8 dma[SAVEBLOCK_MOVE_RANGE];
};

struct PokemonStorageDMA {
    struct PokemonStorage block;
    u8 dma[SAVEBLOCK_MOVE_RANGE];
};

extern struct SaveBlock1DMA gSaveblock1;
extern struct SaveBlock2DMA gSaveblock2;
extern struct PokemonStorageDMA gPokemonStorage;

extern bool32 gFlashMemoryPresent;
extern struct SaveBlock1 *gSaveBlock1Ptr;
extern struct SaveBlock2 *gSaveBlock2Ptr;
extern struct PokemonStorage *gPokemonStoragePtr;

void CheckForFlashMemory(void);
void ClearSav2(void);
void ClearSav1(void);
void SetSaveBlocksPointers(u16 offset);
void MoveSaveBlocks_ResetHeap(void);
u32 UseContinueGameWarp(void);
void ClearContinueGameWarpStatus(void);
void SetContinueGameWarpStatus(void);
void SetContinueGameWarpStatusToDynamicWarp(void);
void ClearContinueGameWarpStatus2(void);
void SavePlayerParty(void);
void LoadPlayerParty(void);
void SaveObjectEvents(void);
void LoadObjectEvents(void);
void CopyPartyAndObjectsToSave(void);
void CopyPartyAndObjectsFromSave(void);
void LoadPlayerBag(void);
void SavePlayerBag(void);
void ApplyNewEncryptionKeyToHword(u16 *hWord, u32 newKey);
void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey);

#endif // GUARD_LOAD_SAVE_H
