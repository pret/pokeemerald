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
#define I_HEALTH_RECOVERY       GEN_7   // In Gen7+, certain healing items recover a different amount of HP than they used to.
#define I_SITRUS_BERRY_HEAL     GEN_7   // In Gen4+, Sitrus Berry was changed from healing 30 HP to healing 25% of Max HP.
#define I_VITAMIN_EV_CAP        GEN_8   // In Gen8, the Vitamins no longer have a cap of 100 EV per stat.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
