#ifndef GUARD_MAP_NAME_POPUP_H
#define GUARD_MAP_NAME_POPUP_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void HideMapNamePopUpWindow(void);
void ShowMapNamePopup(void);

#define MAP_POPUP_TIME_NONE         0                       // don't show the time
#define MAP_POPUP_TIME_12_HR        1                       // use 12 hour (AM/PM) time
#define MAP_POPUP_TIME_24_HR        2                       // use 24 hour time

#define MAP_POPUP_TIME_MODE         MAP_POPUP_TIME_NONE     // determines what type of time is shown
#define MAPPOPUP_ALPHA_BLEND        TRUE                    // enables alpha blending/transparency for the pop-ups

#endif //GUARD_MAP_NAME_POPUP_H
