#ifndef GUARD_MAP_NAME_POPUP_H
#define GUARD_MAP_NAME_POPUP_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void HideMapNamePopUpWindow(void);
void ShowMapNamePopup(void);
u8 *GetPopUpMapName(u8 *dest, const struct MapHeader *mapHeader);

#define MAP_POPUP_STRING_BUFFER_LENGTH 27
#define MAP_POPUP_PREFIX_BUFFER_LENGTH 6

#endif //GUARD_MAP_NAME_POPUP_H
