#ifndef GUARD_CONFIG_DEBUG_H
#define GUARD_CONFIG_DEBUG_H

// Overworld Debug
#define DEBUG_OVERWORLD_MENU            TRUE                // Enables a overworld debug menu for changing flags, variables, giving pokemon and more, accessed by holding R and pressing START while in the overworld by default.
#define DEBUG_OVERWORLD_HELD_KEYS       (R_BUTTON)          // The keys required to be held to open the debug menu.
#define DEBUG_OVERWORLD_TRIGGER_EVENT   pressedStartButton  // The event that opens the menu when holding the key(s) defined in DEBUG_OVERWORLD_HELD_KEYS.
#define DEBUG_OVERWORLD_IN_MENU         FALSE               // Replaces the overworld debug menu button combination with a start menu entry (above Pokédex).

// Debug Flags
// To use the following debug features, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define DEBUG_FLAG_NO_COLLISION         0       // If this flag is set, the debug function in the Utility submenu to disable player collision can be used.

// Battle Debug Menu
#define DEBUG_BATTLE_MENU               TRUE    // If set to TRUE, enables a debug menu to use in battles by pressing the Select button.

// Pokémon Debug
#define DEBUG_POKEMON_MENU              TRUE    // Enables a debug menu for pokemon sprites and icons, accessed by pressing SELECT in the summary screen.

#endif // GUARD_CONFIG_DEBUG_H
