#ifndef GUARD_POKEMON_STORAGE_SYSTEM_H
#define GUARD_POKEMON_STORAGE_SYSTEM_H

#define TOTAL_BOXES_COUNT       14
#define IN_BOX_COUNT            30

u8* GetBoxNamePtr(u8 boxNumber);
struct BoxPokemon *GetBoxedMonPtr(u8, u8);
void SetBoxMonNickFromAnyBox(u8, u8, u8 *);
void CompactPartySlots(void);
u32 GetBoxMonDataFromAnyBox(u8 boxId, u8 monPosition, u32 request);
bool8 CheckFreePokemonStorageSpace(void);
u8 StorageGetCurrentBox(void);

#endif // GUARD_POKEMON_STORAGE_SYSTEM_H
