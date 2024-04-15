#ifndef GUARD_CONFIG_MAP_POPUP_H
#define GUARD_CONFIG_MAP_POPUP_H

// General map pop-up config
#define MAP_POPUP_GENERATION        GEN_3   // Different generations display location names in overworld pop-ups differently
                                            // only current other choice is GEN_5, all others will default to gen 3 pop-ups

// Gen 5 specific pop-up config
// Constants
#define MAP_POPUP_BW_TIME_NONE      0   // don't show the time
#define MAP_POPUP_BW_TIME_12_HR     1   // use 12 hour (AM/PM) time
#define MAP_POPUP_BW_TIME_24_HR     2   // use 24 hour time

#define MAP_POPUP_BW_COLOR_BLACK    0
#define MAP_POPUP_BW_COLOR_WHITE    1

// Configuration
#define MAP_POPUP_BW_COLOR          MAP_POPUP_BW_COLOR_BLACK    // Black 2 and White 2 use different colors for their map pop-ups           
#define MAP_POPUP_BW_TIME_MODE      MAP_POPUP_BW_TIME_NONE      // determines what type of time is shown
#define MAP_POPUP_BW_ALPHA_BLEND    FALSE                       // enables alpha blending/transparency for the pop-ups
                                                                // mostly intended to be used with the black color option

#endif // GUARD_CONFIG_MAP_POPUP_H