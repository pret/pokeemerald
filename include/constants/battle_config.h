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
#define SPECIES_AEGISLASH 0
#define SPECIES_AEGISLASH_BLADE 10000
#define SPECIES_MIMIKYU 0
#define SPECIES_MIMIKYU_BUSTED 10001
#define SPECIES_DARMANITAN 0
#define SPECIES_DARMANITAN_ZEN 10002
#define SPECIES_MINIOR_CORE 0
#define SPECIES_MINIOR 10003
#define SPECIES_WISHIWASHI 0
#define SPECIES_WISHIWASHI_SCHOOL 10004
#define SPECIES_ZYGARDE 0 // 50%
#define SPECIES_ZYGARDE_10 10005 // 10 %
#define SPECIES_ZYGARDE_COMPLETE 10006 // 100 %

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
#define GEN_8 5

// Calculation settings
#define B_CRIT_CHANCE               GEN_6 // Chances of a critical hit landing. See CalcCritChanceStage.
#define B_CRIT_MULTIPLIER           GEN_6 // In Gen6+, critical hits multiply damage by 1.5 instead of 2.
#define B_EXP_CATCH                 GEN_6 // In Gen6+, Pokémon get experience from catching.
#define B_TRAINER_EXP_MULTIPLIER    GEN_6 // In Gen7+, trainer battles no longer give a 1.5 multiplier to exp gain.
#define B_BURN_DAMAGE               GEN_6 // In Gen7+, burn damage is 1/16th of max HP instead of 1/8th.
#define B_PARALYSIS_SPEED           GEN_6 // In Gen7+, speed is decreased by 50% instead of 75%.
#define B_TERRAIN_TYPE_BOOST        GEN_6 // In Gen8+, speed is boosted by 30% instead of 50%.
#define B_BINDING_DAMAGE            GEN_6 // In Gen6+, binding damage is 1/8 of max HP instead of 1/16. (With Binding Band, 1/6 and 1/8 respectively.)
#define B_CONFUSION_SELF_DMG_CHANCE GEN_6 // In Gen7+, confusion has a 33.3% of self-damage, instead of 50%.
#define B_MULTI_HIT_CHANCE          GEN_6 // In Gen5+, multi-hit moves have different %. See Cmd_setmultihitcounter for values.
#define B_RECOIL_IF_MISS_DMG        GEN_6 // In Gen5+, Jump Kick and Hi Jump Kick will always do half of the user's max HP when missing.
#define B_PSYWAVE_DMG               GEN_6 // Psywave's damage formula. See Cmd_psywavedamageeffect.

// Move settings
#define B_FELL_STINGER_STAT_RAISE   GEN_6 // In Gen7+, it raises Atk by 3 stages instead of 2 if it causes the target to faint.
#define B_SOUND_SUBSTITUTE          GEN_6 // In Gen6+, sound moves bypass Substitute.
#define B_TOXIC_NEVER_MISS          GEN_6 // In Gen6+, if Toxic is used by a Poison type, it will never miss.
#define B_PAYBACK_SWITCH_BOOST      GEN_6 // In Gen5+, if the opponent switches out, Payback's damage will no longer be doubled.
#define B_KINGS_SHIELD_LOWER_ATK    GEN_6 // In Gen7+, it lowers Atk by 1 stage instead of 2 of oponents that hit it.
#define B_BINDING_TURNS             GEN_6 // In Gen5+, binding moves last for 4-5 turns instead of 2-5 turns. (With Grip Claw, 7 and 5 turns respectively.)
#define B_UPROAR_TURNS              GEN_6 // In Gen5+, Uproar lasts for 3 turns instead of 2-5 turns.
#define B_DISABLE_TURNS             GEN_6 // Disable's turns. See Cmd_disablelastusedattack.
#define B_INCINERATE_GEMS           GEN_6 // In Gen6+, Incinerate can destroy Gems.
#define B_MINIMIZE_DMG_ACC          GEN_6 // In Gen6+, moves that causes double damage to minimized Pokémon will also skip accuracy checks.

// Ability settings
#define B_ABILITY_POP_UP            GEN_6 // In Gen5+, the Pokémon abilities are displayed in a pop-up, when they activate in battle.
#define B_ABILITY_WEATHER           GEN_6 // In Gen5+, weather caused by abilities lasts the same amount of turns as induced from a move. Before, they lasted till the battle's end or weather change by a move.
#define B_GALE_WINGS                GEN_6 // In Gen7+ requires full HP to trigger.
#define B_STANCE_CHANGE_FAIL        GEN_7 // In Gen7+, Aegislash's form change does not happen, if the Pokémon cannot use a move, because of confusion, paralysis, etc. In gen6, the form change occurs despite not being able to move.
#define B_GHOSTS_ESCAPE             GEN_6 // In Gen6+, ghosts can escape even when blocked by abilities such as Shadow Tag.
#define B_MOODY_ACC_EVASION         GEN_6 // In Gen8+, Moody CANNOT raise Accuray and Evasion any more.
#define B_FLASH_FIRE_FROZEN         GEN_6 // In Gen5+, Flash Fire can trigger even when frozen, when it couldn't before.
#define B_SYNCHRONIZE_NATURE        GEN_6 // In Gen8+, if the Pokémon with Synchronize is leading the party, it's 100% guaranteed that wild Pokémon will have the same ability, as opposed to 50% previously.

// Item settings
#define B_HP_BERRIES                GEN_6 // In Gen4+, berries which restore hp activate immediately after hp drops to half. In gen3, the effect occurs at the end of the turn.
#define B_BERRIES_INSTANT           GEN_6 // In Gen4+, most berries activate on battle start/switch-in if applicable. In gen3, they only activate either at the move end or turn end.

// Other
#define B_FLAG_INVERSE_BATTLE       0     // If this flag is set, the battle's type effectiveness are inversed. For example, fire is super effective against water. 0 disables the feature.
#define B_FAST_INTRO                TRUE  // If set to TRUE, battle intro texts print at the same time as animation of a Pokémon, as opposing to waiting for the animation to end.
#define B_SHOW_TARGETS              TRUE  // If set to TRUE, all available targets, for moves hitting 2 or 3 Pokémon, will be shown before selecting a move.
#define B_SLEEP_TURNS               GEN_6 // In Gen5+, sleep lasts for 1-3 turns instead of 2-5 turns.
#define B_PARALYZE_ELECTRIC         GEN_6 // In Gen6+, Electric type Pokémon can't be paralyzed.
#define B_POWDER_GRASS              GEN_6 // In Gen6+, Grass type Pokémon are immune to powder and spore moves.

// Animation Settings
#define NEW_SWORD_PARTICLE              TRUE    // update swords dance particle
#define NEW_LEECH_SEED_PARTICLE         TRUE    //update leech seed's animation particle
#define NEW_HORN_ATTACK_PARTICLE        TRUE    //update horn attack's horn
#define NEW_LEAF_PARTICLE               TRUE    // update leaf particle
#define NEW_EMBER_PARTICLES             TRUE    //updates ember fire particle
#define NEW_MEAN_LOOK_PARTICLE          TRUE    //update mean look eye
#define NEW_TEETH_PARTICLE              TRUE    //update bite/crunch teeth particle
#define NEW_HANDS_FEET_PARTICLE         TRUE    //update chop/kick/punch particles
#define NEW_SPIKES_PARTICLE             TRUE    //update spikes particle
#define NEW_FLY_BUBBLE_PARTICLE         TRUE    //update fly 'bubble' particle
#define NEW_CURSE_NAIL_PARTICLE         TRUE    //updates curse nail
#define NEW_BATON_PASS_BALL_PARTICLE    TRUE    //update baton pass pokeball sprite
#define NEW_MORNING_SUN_STAR_PARTICLE   TRUE    //updates morning sun star particles
#define NEW_IMPACT_PALETTE              TRUE    //updates the basic 'hit' particle
#define NEW_SURF_PARTICLE_PALETTE       TRUE    //updates the surf wave palette

#endif // GUARD_CONSTANTS_BATTLE_CONFIG_H
