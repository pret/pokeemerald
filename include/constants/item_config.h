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
#define P_REPEAT_BALL_MODIFIER  GEN_7   // In Gen7+, Net Ball's catch multiplier is x3.5 instead of x3.
#define P_TIMER_BALL_MODIFIER   GEN_7   // In Gen5+, Timer Ball's effectiveness increases by x0.3 per turn instead of x0.1
#define P_DIVE_BALL_MODIFIER    GEN_3   // In Gen4+, Dive Ball's effectiveness increases by when Surfing or Fishing.
#define P_DUSK_BALL_MODIFIER    GEN_7   // In Gen7+, Net Ball's catch multiplier is x3 instead of x3.5.
#define P_QUICK_BALL_MODIFIER   GEN_7   // In Gen5+, Quick Ball's catch multiplier is x5 instead of x4.
#define P_DREAM_BALL_MODIFIER   GEN_8   // In Gen8+, Dream Ball's catch multiplier is x4 when the target is asleep.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
