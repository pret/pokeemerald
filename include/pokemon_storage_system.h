#ifndef GUARD_POKEMON_STORAGE_SYSTEM_H
#define GUARD_POKEMON_STORAGE_SYSTEM_H

#define TOTAL_BOXES_COUNT       14
#define IN_BOX_ROWS             5 // Number of rows, 6 Pokémon per row
#define IN_BOX_COLUMNS          6 // Number of columns, 5 Pokémon per column
#define IN_BOX_COUNT            (IN_BOX_ROWS * IN_BOX_COLUMNS)
#define BOX_NAME_LENGTH         8
#define MAX_FUSION_STORAGE      4

/*
            COLUMNS
ROWS        0   1   2   3   4   5
            6   7   8   9   10  11
            12  13  14  15  16  17
            18  19  20  21  22  23
            24  25  26  27  28  29
*/

struct PokemonStorage
{
    /*0x0000*/ u8 currentBox;
    /*0x0001*/ struct BoxPokemon boxes[TOTAL_BOXES_COUNT][IN_BOX_COUNT];
    /*0x8344*/ u8 boxNames[TOTAL_BOXES_COUNT][BOX_NAME_LENGTH + 1];
    /*0x83C2*/ u8 boxWallpapers[TOTAL_BOXES_COUNT];
    /*0x8432*/ struct Pokemon fusions[MAX_FUSION_STORAGE];
};

extern struct PokemonStorage *gPokemonStoragePtr;

void DrawTextWindowAndBufferTiles(const u8 *string, void *dst, u8 zero1, u8 zero2, s32 bytesToBuffer);
u8 CountMonsInBox(u8 boxId);
s16 GetFirstFreeBoxSpot(u8 boxId);
u8 CountPartyAliveNonEggMonsExcept(u8 slotToIgnore);
u16 CountPartyAliveNonEggMons_IgnoreVar0x8004Slot(void);
u8 CountPartyMons(void);
u8 *StringCopyAndFillWithSpaces(u8 *dst, const u8 *src, u16 n);
void ShowPokemonStorageSystemPC(void);
void ResetPokemonStorageSystem(void);
s16 CompactPartySlots(void);
u8 StorageGetCurrentBox(void);
u32 GetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request);
void SetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, const void *value);
u32 GetCurrentBoxMonData(u8 boxPosition, s32 request);
void SetCurrentBoxMonData(u8 boxPosition, s32 request, const void *value);
void GetBoxMonNickAt(u8 boxId, u8 boxPosition, u8 *dst);
u32 GetBoxMonLevelAt(u8 boxId, u8 boxPosition);
void SetBoxMonNickAt(u8 boxId, u8 boxPosition, const u8 *nick);
u32 GetAndCopyBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, void *dst);
void SetBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *src);
void CopyBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *dst);
void CreateBoxMonAt(u8 boxId, u8 boxPosition, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 personality, u8 otIDType, u32 otID);
void ZeroBoxMonAt(u8 boxId, u8 boxPosition);
void BoxMonAtToMon(u8 boxId, u8 boxPosition, struct Pokemon *dst);
struct BoxPokemon *GetBoxedMonPtr(u8 boxId, u8 boxPosition);
u8 *GetBoxNamePtr(u8 boxId);
s16 AdvanceStorageMonIndex(struct BoxPokemon *boxMons, u8 currIndex, u8 maxIndex, u8 mode);
bool8 CheckFreePokemonStorageSpace(void);
bool32 CheckBoxMonSanityAt(u32 boxId, u32 boxPosition);
u32 CountStorageNonEggMons(void);
u32 CountAllStorageMons(void);
bool32 AnyStorageMonWithMove(u16 moveId);

void ResetWaldaWallpaper(void);
void SetWaldaWallpaperLockedOrUnlocked(bool32 unlocked);
bool32 IsWaldaWallpaperUnlocked(void);
u32 GetWaldaWallpaperPatternId(void);
void SetWaldaWallpaperPatternId(u8 id);
u32 GetWaldaWallpaperIconId(void);
void SetWaldaWallpaperIconId(u8 id);
u16 *GetWaldaWallpaperColorsPtr(void);
void SetWaldaWallpaperColors(u16 color1, u16 color2);
u8 *GetWaldaPhrasePtr(void);
void SetWaldaPhrase(const u8 *src);
bool32 IsWaldaPhraseEmpty(void);

void EnterPokeStorage(u8 boxOption);

#endif // GUARD_POKEMON_STORAGE_SYSTEM_H
