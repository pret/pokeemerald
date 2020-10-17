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
#define P_SHINY_CHARM_REROLLS   3       // Amount of re-rolls if the player has the Shiny Charm. Set to 0 to disable Shiny Charm's effects.
#define P_KEY_FOSSILS           GEN_7   // In Gen4+, all Gen 3 fossils became regular items.
#define P_KEY_ESCAPE_ROPE       GEN_7   // In Gen8, Escape Rope became a Key Item.

// Ball config
#define P_LURE_BALL_MODIFIER    GEN_7   // In Gen7+, Lure Ball's catch multiplier is x5 instead of x3.
#define P_HEAVY_BALL_MODIFIER   GEN_7   // In Gen7+, Heavy Ball's ranges change. See Cmd_handleballthrow.
#define P_NET_BALL_MODIFIER     GEN_7   // In Gen7+, Net Ball's catch multiplier is x5 instead of x3.
#define P_NEST_BALL_MODIFIER    GEN_7   // Nest Ball's formula varies depending on the Gen. See Cmd_handleballthrow.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
