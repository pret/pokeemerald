#ifndef GUARD_LOAD_SAVE_H
#define GUARD_LOAD_SAVE_H

#include "pokemon_storage_system.h"
#include "save.h"

#define SAVEBLOCK_MOVE_RANGE    128

/**
 * These structs are to prevent them from being reordered on newer or modern
 * toolchains. If this is not done, the ClearSav functions will end up erasing
 * the wrong memory leading to various glitches.
 */
struct SaveBlock2ASLR {
    struct SaveBlock2 block;
    u8 aslr[SAVEBLOCK_MOVE_RANGE];
};

struct SaveBlock1ASLR {
    struct SaveBlock1 block;
    u8 aslr[SAVEBLOCK_MOVE_RANGE];
};

struct PokemonStorageASLR {
    struct PokemonStorage block;
    u8 aslr[SAVEBLOCK_MOVE_RANGE];
};

extern struct SaveBlock1ASLR gSaveblock1;
extern struct SaveBlock2ASLR gSaveblock2;
extern struct SaveBlock3 gSaveblock3;
extern struct PokemonStorageASLR gPokemonStorage;

extern bool32 gFlashMemoryPresent;
extern struct SaveBlock1 *gSaveBlock1Ptr;
extern struct SaveBlock2 *gSaveBlock2Ptr;
extern struct PokemonStorage *gPokemonStoragePtr;

void CheckForFlashMemory(void);
void ClearSav3(void);
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
