#ifndef GUARD_LOAD_SAVE_H
#define GUARD_LOAD_SAVE_H

extern bool32 gFlashMemoryPresent;
extern struct SaveBlock2 gSaveblock2;
extern struct PokemonStorage gPokemonStorage;

void ClearSav2(void);
void ClearSav1(void);
void CheckForFlashMemory(void);
void MoveSaveBlocks_ResetHeap(void);
bool32 GetSecretBase2Field_9(void);
void ClearSecretBase2Field_9(void);
void SetSecretBase2Field_9(void);
void SetSecretBase2Field_9_AndHideBG(void);
void ClearSecretBase2Field_9_2(void);
void SavePlayerParty(void);
void LoadPlayerParty(void);
void SaveSerializedGame(void);
void LoadSerializedGame(void);
void LoadPlayerBag(void);
void SavePlayerBag(void);
void SetSaveBlocksPointers(u16);
void sub_8076D5C(void);
void sav2_gender2_inplace_and_xFE(void);

#endif // GUARD_LOAD_SAVE_H
