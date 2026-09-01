#ifndef GUARD_POKEDEX_PLUS_HGSS_H
#define GUARD_POKEDEX_PLUS_HGSS_H

bool32 TryInitWindows_HGSS(void);
bool32 TryOpenPokedexPage_HGSS(u8, u8);
bool32 TryLoadPokedexBgPalette_HGSS(bool8 isSearchResults);
bool32 TryCreateMonListEntry_HGSS(u8 position, u16 b, u16 ignored);
bool32 TryMoveMonForInfoScreen_HGSS(struct Sprite *sprite);
bool32 Task_TryLoadInfoScreen_HGSS(u8);
bool32 TryHandleInfoScreenInput_HGSS(u8 taskId);
bool32 TryLoadAreaScreen_HGSS(u8 taskId);
bool32 TrySwitchScreensFromAreaScreen_HGSS(u8 taskId);
void Task_DisplayCaughtMonDexPageHGSS(u8);
bool32 TryLoadCryScreen_HGSS(u8 taskId);
bool32 TrySwitchScreensFromCryScreen_HGSS(u8 taskId);
bool32 TryLoadSizeScreen_HGSS(u8 taskId);
bool32 TryLoadPlayArrowPalette_HGSS(bool8 cryPlaying);
bool32 TryLoadSearchMenu_HGSS(u8 taskId);
void HandleDestroyStatBars_HGSS(void);
void HandleDestroyStatBarsBg_HGSS(void);
void HandleCreateStatBars_HGSS(void);
void HandleCreateStatBarsDPAD_HGSS(void);
void HandleCaughtMonPageTypeIcons_HGSS(void);
bool32 TryHandleCaughtMonPageFlicker_HGSS(u8 taskId);

#endif // GUARD_POKEDEX_PLUS_HGSS_H
