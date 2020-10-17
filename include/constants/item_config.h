#ifndef GUARD_CONSTANTS_ITEM_CONFIG_H
#define GUARD_CONSTANTS_ITEM_CONFIG_H

// Used by other branches to communicate with each other.
#define ITEM_EXPANSION

#ifndef GEN_3
#define GEN_3 0
#define GEN_4 1
#define GEN_5 2
#define GEN_6 3
#define GEN_7 4
#define GEN_8 5
#endif

// Item config
#define P_KEY_FOSSILS           GEN_7   // In Gen4+, all Gen 3 fossils became regular items.
#define P_KEY_ESCAPE_ROPE       GEN_7   // In Gen8, Escape Rope became a Key Item.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
