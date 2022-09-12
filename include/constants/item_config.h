#ifndef GUARD_CONSTANTS_ITEM_CONFIG_H
#define GUARD_CONSTANTS_ITEM_CONFIG_H

// Item config
#define I_SHINY_CHARM_REROLLS   3           // Amount of re-rolls if the player has the Shiny Charm. Set to 0 to disable Shiny Charm's effects.
#define I_KEY_FOSSILS           GEN_LATEST  // In Gen4+, all Gen 3 fossils became regular items.
#define I_KEY_ESCAPE_ROPE       GEN_LATEST  // In Gen8, Escape Rope became a Key Item. Keep in mind, this will make it free to buy in marts.
#define I_HEALTH_RECOVERY       GEN_LATEST  // In Gen7+, certain healing items recover a different amount of HP than they used to.
#define I_SITRUS_BERRY_HEAL     GEN_LATEST  // In Gen4+, Sitrus Berry was changed from healing 30 HP to healing 25% of Max HP.
#define I_VITAMIN_EV_CAP        GEN_LATEST  // In Gen8, the Vitamins no longer have a cap of 100 EV per stat.

// Var settings
// To use the following features, replace the 0s with the var ID you're assigning it to.
// Eg: Replace with VAR_UNUSED_0x40F7 so you can use I_VAR_LAST_REPEL_LURE_USED for that feature.
#define I_VAR_LAST_REPEL_LURE_USED  0     // If this var has been assigned, B2W2's Repel prompt will trigger once it runs out. It also applies to Lures.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
