#ifndef GUARD_CONFIG_ITEM_H
#define GUARD_CONFIG_ITEM_H

// Item config
#define I_SHINY_CHARM_ADDITIONAL_ROLLS  2           // The amount of additional Shiny rolls if the player has the Shiny Charm. Set it to 0 to disable the Shiny Charm's effects.
#define I_KEY_FOSSILS                   GEN_LATEST  // In Gen4+, fossils are no longer Key Items.
#define I_KEY_ESCAPE_ROPE               GEN_LATEST  // In Gen8+, the Escape Rope is a Key Item. Keep in mind that this will make it free to buy in Marts.
#define I_HEALTH_RECOVERY               GEN_LATEST  // In Gen7+, certain healing items recover a different amount of HP than they did previously.
#define I_SITRUS_BERRY_HEAL             GEN_LATEST  // In Gen4+, Sitrus Berries heal 30 HP instead of 25% of max HP.
#define I_VITAMIN_EV_CAP                GEN_LATEST  // In Gen8+, Vitamins no longer have a cap of 100 EVs per stat.
#define I_BERRY_EV_JUMP                 GEN_LATEST  // In Gen4 only, EV-lowering Berries lower a stat's EVs to 100 if they are above 100.
#define I_GRISEOUS_ORB_FORM_CHANGE      GEN_LATEST  // In Gen9+, the Griseous Orb no longer changes Giratina's form when held.
#define I_GEM_BOOST_POWER               GEN_LATEST  // In Gen6+, the power multiplier of Gems is 1.3x instead of 1.5x.
#define I_USE_EVO_HELD_ITEMS_FROM_BAG   FALSE       // If set to TRUE, items such as the Electirizer can be used from the bag to evolve a Pokémon like in PLA.
#define I_TYPE_BOOST_POWER              GEN_LATEST  // In Gen4+, type-enhancing held items increase the power of moves by 1.2x instead of 1.1x (1.05x in the case of Sea Incense).
#define I_SELL_VALUE_FRACTION           GEN_LATEST  // In Gen9+, items sell for 1/4 of their value instead of 1/2.
#define I_PRICE                         GEN_LATEST  // Some items have varied in value across generations. See src/data/items.h for values.
#define I_BERRY_PRICE                   GEN_7       // In Gen8+, the value of Berries increased since they can no longer be planted.
#define I_POWER_ITEM_BOOST              GEN_LATEST  // In Gen7+, Pokémon holding Power items gain 8 extra EVs instead of 4.
#define I_PREMIER_BALL_BONUS            GEN_LATEST  // In LGPE onwards (Gen8+ here), the player is given a Premier Ball for every 10 Poké Balls of any type in the same purchase. Previously, this only applied to regular Poké Balls and only 1 could be obtained per purchase.
#define I_ROTOM_CATALOG_THUNDER_SHOCK   GEN_LATEST  // In Gen9+, changing Rotom to its base form will teach it Thunder Shock even if it knows another move.
#define I_REPEL_INCLUDE_FAINTED         GEN_LATEST  // In Gen1 and Gen6+, Repels use the level of the first party member to check which wild Pokémon to prevent encounters with, even if that member is fainted. In Gens2-5, they use the level of the first non-fainted Pokémon.
#define I_LAX_INCENSE_BOOST             GEN_LATEST  // In Gen4+, Lax Incense lowers accuracy by 10% instead of 5%.

// TM config
#define I_REUSABLE_TMS          FALSE       // In Gens5-8, TMs are reusable. Setting this to TRUE will make all vanilla TMs reusable, though they can also be cherry-picked by setting their importance to 1.

// Exp. Share config
// To use this feature, replace the 0 with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define I_EXP_SHARE_FLAG        0           // If this flag is set, every Pokémon in the party will gain experience, regardless if they participated in the battle or not.
#define I_EXP_SHARE_ITEM        GEN_5       // In Gen6+, the Exp. Share is a Key item that toggles the effect described above.

// Repel/Lure config
// These two settings are both independent and complementary.
#define VAR_LAST_REPEL_LURE_USED    0       // If this var has been assigned, the last Repel/Lure used will be saved and the player will be prompted with the vanilla repel YES/NO option, unless I_REPEL_LURE_MENU is set to TRUE.
#define I_REPEL_LURE_MENU           TRUE    // If set to TRUE, the player is able to choose which Repel/Lure to use once the previous one runs out. Cursor position is saved by VAR_LAST_REPEL_LURE_USED if not 0.

// Vs. Seeker
#define I_VS_SEEKER_CHARGING        0                     // If this flag is assigned, the Vs. Seeker functionality will be enabled. When the player has the Vs. Seeker, Match Call rematch functions will stop working. Documentation for the Vs. Seeker can be found in docs/tutorials/vs_seeker.md.
#define I_SHOW_NO_ID_TRAINER        DISABLED_ON_RELEASE   // If TRUE, object events with a trainer type but no visible trainer id will be shown with a question mark. You may want to add vsseeker_rematchid TRAINER_ID as the top of the script to let the VS seeker know what reaction it's supposed to show.

// ORAS Dowsing Machine
#define I_ORAS_DOWSING_FLAG         0       // Replace 0 with an unused flag to enable the Dowsing Machine mechanic from ORAS.
#define I_ORAS_DOWSING_SOUNDS       TRUE    // If set to TRUE, the Dowsing Machine will make sounds based on how far away the hidden item is.
#define I_ORAS_DOWSING_COLOR_PAL    15      // The color within the palette that will change based on proximity to the item.

// Color values for the ORAS dowsing distances/anims
#define I_ORAS_DOWSING_COLOR_NONE   RGB_GRAY
#define I_ORAS_DOWSING_COLOR_SLOW   RGB2GBA(56, 120, 255)
#define I_ORAS_DOWSING_COLOR_NORMAL RGB2GBA(24, 216, 24)
#define I_ORAS_DOWSING_COLOR_FAST   RGB2GBA(255, 255, 40)
#define I_ORAS_DOWSING_COLOR_FASTER RGB_RED

#endif // GUARD_CONFIG_ITEM_H
