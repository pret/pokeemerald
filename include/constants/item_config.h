#ifndef GUARD_CONSTANTS_ITEM_CONFIG_H
#define GUARD_CONSTANTS_ITEM_CONFIG_H

// Item config
#define I_SHINY_CHARM_REROLLS   3           // Amount of re-rolls if the player has the Shiny Charm. Set to 0 to disable Shiny Charm's effects.
#define I_KEY_FOSSILS           GEN_LATEST  // In Gen4+, all Gen 3 fossils became regular items.
#define I_KEY_ESCAPE_ROPE       GEN_LATEST  // In Gen8, Escape Rope became a Key Item. Keep in mind, this will make it free to buy in marts.
#define I_HEALTH_RECOVERY       GEN_LATEST  // In Gen7+, certain healing items recover a different amount of HP than they used to.
#define I_SITRUS_BERRY_HEAL     GEN_LATEST  // In Gen4+, Sitrus Berry was changed from healing 30 HP to healing 25% of Max HP.
#define I_VITAMIN_EV_CAP        GEN_LATEST  // In Gen8, the Vitamins no longer have a cap of 100 EV per stat.

// Repel/Lure config
// These two settings are both independent and complementary.
#define VAR_LAST_REPEL_LURE_USED    0       // If this var has been assigned, last Repel/Lure used will be saved and the player will get prompted with the vanilla repel YES/NO option, unless I_REPEL_LURE_MENU is set to TRUE.
#define I_REPEL_LURE_MENU           TRUE    // If TRUE, the player is able to choose which Repel/Lure to use once the previous one runs out. Cursor position is saved by VAR_LAST_REPEL_LURE_USED if not 0.

#endif // GUARD_CONSTANTS_ITEM_CONFIG_H
