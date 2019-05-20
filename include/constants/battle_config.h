#ifndef GUARD_CONSTANTS_BATTLE_CONFIG_H
#define GUARD_CONSTANTS_BATTLE_CONFIG_H

// Species with peculiar battle effects. Remove them if they're properly placed in constant/species.h
#define SPECIES_DIALGA 0
#define SPECIES_PALKIA 0
#define SPECIES_GIRATINA 0
#define SPECIES_CHERRIM 0
#define SPECIES_ARCEUS 0
#define SPECIES_SILVALLY 0
#define SPECIES_GENESECT 0

// Items with peculiar battle effects. Remove them if they're properly placed in constant/items.h
#define ITEM_GRISEOUS_ORB 0
#define ITEM_OCCA_BERRY 204
#define ITEM_PASSHO_BERRY 205
#define ITEM_WACAN_BERRY 206
#define ITEM_RINDO_BERRY 207
#define ITEM_YACHE_BERRY 208
#define ITEM_CHOPLE_BERRY 177
#define ITEM_KEBIA_BERRY 178
#define ITEM_SHUCA_BERRY 179
#define ITEM_COBA_BERRY 180
#define ITEM_PAYAPA_BERRY 181
#define ITEM_TANGA_BERRY 182
#define ITEM_CHARTI_BERRY 183
#define ITEM_KASIB_BERRY 184
#define ITEM_HABAN_BERRY 185
#define ITEM_COLBUR_BERRY 186
#define ITEM_BABIRI_BERRY 187
#define ITEM_CHILAN_BERRY 188
#define ITEM_ROSELI_BERRY 189
#define ITEM_MICLE_BERRY 197
#define ITEM_CUSTAP_BERRY 199
#define ITEM_JABOCA_BERRY 200
#define ITEM_ROWAP_BERRY 201
#define ITEM_KEE_BERRY 202
#define ITEM_MARANGA_BERRY 203

#define GEN_3 0
#define GEN_4 1
#define GEN_5 2
#define GEN_6 3
#define GEN_7 4

#define B_CRIT_CHANCE               GEN_6 // Chances of a critical hit landing. See atk04_critcalc.
#define B_FELL_STINGER_STAT_RAISE   GEN_6 // Gen6 Atk+2, Gen7 Atk+3.
#define B_ABILITY_WEATHER           GEN_6 // Up to gen5 - weather induced by abilities such as Drought or Drizzle lasted till the battle's end or weather change by a move. From Gen6 onwards, weather caused by abilities lasts the same amount of turns as induced from a move.
#define B_GALE_WINGS                GEN_6 // Gen7 requires full hp.
#define B_SOUND_SUBSTITUTE          GEN_6 // Starting from gen6 sound moves bypass Substitute.
#define B_EXP_CATCH                 GEN_6 // Starting from gen6, pokemon get experience from catching.
#define B_ABILITY_POP_UP            GEN_6 // Starting from gen5, the pokemon abilities are displayed in a pop-up, when they activate in battle.

#define B_FAST_INTRO                TRUE // If set to TRUE, battle intro texts print at the same time as animation of a pokemon, as opposing to waiting for the animation to end.

#endif // GUARD_CONSTANTS_BATTLE_CONFIG_H
