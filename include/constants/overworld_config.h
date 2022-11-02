#ifndef GUARD_CONSTANTS_OVERWORLD_CONFIG_H
#define GUARD_CONSTANTS_OVERWORLD_CONFIG_H

// Movement config
#define OW_RUNNING_INDOORS      GEN_LATEST  // In Gen4+, players are allowed to run indoors.

// Overworld flags
#define OW_FLAG_NO_ENCOUNTER             0  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE           0  // If this flag is set, trainers will not battle the player unless they're talked to.

// Debug options
#define DEBUG_SYSTEM_ENABLE         TRUE               // Enables a overworld debug menu for changing flags, variables, giving pokemon and more, accessed by holding R and pressing START while in the overworld by default.
#define DEBUG_SYSTEM_HELD_KEYS      (R_BUTTON)         // The keys required to be held to open the debug menu.
#define DEBUG_SYSTEM_TRIGGER_EVENT  pressedStartButton // The event that opens the menu when holding the key(s) defined in DEBUG_SYSTEM_HELD_KEYS.
#define DEBUG_SYSTEM_IN_MENU        FALSE              // Replaces the overworld debug menu button combination with a start menu entry (above Pokédex).

// Replace the used flags with others or disable with a 0
#define DEBUG_FLAG_NO_COLLISION             0   // If this flag is set, the debug function in the Utility submenu to disable player collision can be used.

#endif // GUARD_CONSTANTS_OVERWORLD_CONFIG_H
