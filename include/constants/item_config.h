#ifndef GUARD_CONSTANTS_ITEM_CONFIG_H
#define GUARD_CONSTANTS_ITEM_CONFIG_H

#include "constants/expansion_branches.h"

#ifndef GEN_3
#define GEN_3 0
#define GEN_4 1
#define GEN_5 2
#define GEN_6 3
#define GEN_7 4
#define GEN_8 5
#endif

// Item config
#define I_SHINY_CHARM_REROLLS   3       // Amount of re-rolls if the player has the Shiny Charm. Set to 0 to disable Shiny Charm's effects.
#define I_KEY_FOSSILS           GEN_7   // In Gen4+, all Gen 3 fossils became regular items.
#define I_KEY_ESCAPE_ROPE       GEN_7   // In Gen8, Escape Rope became a Key Item. Keep in mind, this will make it free to buy in marts.
#define I_LEGACY_HEALING_ITEMS  GEN_7   // In Gen7+, certain healing items recover less HP than they used to.

// Ball config
#define I_LURE_BALL_MODIFIER    GEN_7   // In Gen7+, Lure Ball's catch multiplier is x5 instead of x3.
#define I_NET_BALL_MODIFIER     GEN_7   // In Gen7+, Net Ball's catch multiplier is x5 instead of x3.
#define I_REPEAT_BALL_MODIFIER  GEN_7   // In Gen7+, Repeat Ball's catch multiplier is x3.5 instead of x3.
#define I_DUSK_BALL_MODIFIER    GEN_7   // In Gen7+, Dusk Ball's catch multiplier is x3 instead of x3.5.
#define I_QUICK_BALL_MODIFIER   GEN_7   // In Gen5+, Quick Ball's catch multiplier is x5 instead of x4.
#define I_DREAM_BALL_MODIFIER   GEN_8   // In Gen8+, Dream Ball's catch multiplier is x4 when the target is asleep.
#define I_TIMER_BALL_MODIFIER   GEN_7   // In Gen5+, Timer Ball's effectiveness increases by x0.3 per turn instead of x0.1
#define I_DIVE_BALL_MODIFIER    GEN_7   // In Gen4+, Dive Ball's effectiveness increases by when Surfing or Fishing.
#define I_HEAVY_BALL_MODIFIER   GEN_7   // In Gen7+, Heavy Ball's ranges change. See Cmd_handleballthrow.
#define I_NEST_BALL_MODIFIER    GEN_7   // Nest Ball's formula varies depending on the Gen. See Cmd_handleballthrow.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
