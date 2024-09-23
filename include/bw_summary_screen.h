#ifndef GUARD_BW_SUMMARY_SCREEN_H
#define GUARD_BW_SUMMARY_SCREEN_H

#include "main.h"

// turn on and off the bw summary screen
#define BW_SUMMARY_SCREEN                           TRUE

// constants
#define BW_MAX_MOVE_DESCRIPTION_LENGTH              60      // this only needs to be updated if you use auto-formatting
#define BW_IV_EV_HIDDEN                             0       // don't show IVs and EVs
#define BW_IV_EV_GRADED                             1       // show graded values for IVs and EVs
#define BW_IV_EV_PRECISE                            2       // show precise values for IVs and EVs
#define BW_SUMMARY_MON_IDLE_ANIMS_FRAMES            300     // number of frames between each idle anim IF BW_SUMMARY_MON_IDLE_ANIMS is true.
                                                            // for reference, Emerald runs at 60FPS by default

// configs
#define BW_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS    TRUE                // automatically formats move descriptions to fit the new box size. disable if you want to format them manually
#define BW_SUMMARY_NATURE_COLORS                    TRUE                // color stats increased or reduced by nature, red = boosted, blue = reduced
#define BW_SUMMARY_NATURE_ARROWS                    FALSE               // arrows to show stats increased or reduced by nature
#define BW_SUMMARY_CATEGORY_ICONS                   TRUE                // determines whether category (split) icons are shown or not
#define BW_SUMMARY_IV_EV_DISPLAY                    BW_IV_EV_HIDDEN     // determines how to show IVs and EVs
#define BW_SUMMARY_DECAP                            FALSE               // indicates if summary screen-specific strings should be decapitalized
#define BW_SUMMARY_SHOW_FRIENDSHIP                  FALSE               // show a heart that fills up to indicate friendship value
#define BW_SUMMARY_BW_STATUS_ICONS                  TRUE                // use Gen 5 style status icons instead of the default ones.
#define BW_SUMMARY_BW_TYPE_ICONS                    TRUE                // use Gen 5 style type icons instead of the default ones.
                                                                        // out of the box the vanilla icons don't fit well, this is mostly a compatibility
                                                                        // option for people who already use custom icons everywhere else
#define BW_SUMMARY_SCROLLING_BG                     TRUE                // enables scrolling animated background
#define BW_SUMMARY_BG_BLEND                         TRUE                // enables alpha blending for the main UI (semi-transparency)
#define BW_SUMMARY_MON_IDLE_ANIMS                   TRUE                // loops the mon animations regularly as an "idle" anim
#define BW_SUMMARY_MON_SHADOWS                      TRUE                // displays a shadow for the mon sprite
#define BW_SUMMARY_SHOW_TERA_TYPE                   FALSE               // show tera type icons

/* Info for users

General tilemap setup
BG3 - scrolling grid background (or not scrolling if you turned the config off) 
BG2 - main UI overlayed on scrolling BG
BG1 - pop in move effect windows
BG0 - text windows

Mosaic effect used when transitioning between screens and actvating
effect windows is controlled by tMosaicStrength in the relevant
task functions.

BG scrolling speed can be modified by altering the value parameter
of the ChangeBgX and ChangeBgY functions in VBlank()

Main UI and shadow transparency levels can be adjusted by changing the
value written to the alpha blend register in this line in bw_summary_screen.c:

static void InitBGs(void)
...
SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(14, 6));
...
}

*/

/* ravetodo in future updates

- hidden power
- extended move desc window
- ribbons

*/

void ShowPokemonSummaryScreen_BW(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void ShowSelectMovePokemonSummaryScreen_BW(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove);
void ShowPokemonSummaryScreenHandleDeoxys_BW(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
u8 GetMoveSlotToReplace_BW(void);
void SummaryScreen_SetAnimDelayTaskId_BW(u8 taskId);
void SummaryScreen_SetShadowAnimDelayTaskId_BW(u8 taskId);

// The Pokémon Summary Screen can operate in different modes. Certain features,
// such as move re-ordering, are available in the different modes.
enum PokemonSummaryScreenMode_BW
{
    BW_SUMMARY_MODE_NORMAL,
    BW_SUMMARY_MODE_LOCK_MOVES,
    BW_SUMMARY_MODE_BOX,
    BW_SUMMARY_MODE_SELECT_MOVE,
};

#endif // GUARD_BW_SUMMARY_SCREEN_H
