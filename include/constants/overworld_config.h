#ifndef GUARD_CONSTANTS_OVERWORLD_CONFIG_H
#define GUARD_CONSTANTS_OVERWORLD_CONFIG_H

// Debug options
#define DEBUG_SYSTEM_ENABLE         TRUE    // Enables a overworld debug menu for changing flags, variables, giving pokemon and more, accessed by pressing R plus START.
#define DEBUG_SYSTEM_IN_MENU        FALSE   // Replaces the overworld debug menu button combination with a start menu entry (replaces the exit entry).

// Replace the used flags with others or disable with a 0
#define DEBUG_FLAG_NO_COLLISION             0   // If this flag is set, the debug function in the Utility submenu to disable player collision can be used.
#define DEBUG_FLAG_NO_ENCOUNTER             0   // If this flag is set, the debug function in the Utility submenu to disable wild encounters can be used.
#define DEBUG_FLAG_NO_TRAINER_SEE           0   // If this flag is set, the debug function in the Utility submenu to disable battles with trainer can be used.
#define DEBUG_FLAG_PC_FROM_DEBUG_MENU       0   // If this flag is set, the debug function in debug menu to access the player PC works.

#endif // GUARD_CONSTANTS_OVERWORLD_CONFIG_H
