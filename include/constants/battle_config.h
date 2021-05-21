#ifndef GUARD_CONSTANTS_BATTLE_CONFIG_H
#define GUARD_CONSTANTS_BATTLE_CONFIG_H

// Species with peculiar battle effects.
#ifndef POKEMON_EXPANSION
    #define SPECIES_DIALGA                  0
    #define SPECIES_PALKIA                  0
    #define SPECIES_GIRATINA                0
    #define SPECIES_CHERRIM                 0
    #define SPECIES_ARCEUS                  0
    #define SPECIES_SILVALLY                0
    #define SPECIES_GENESECT                0
    #define SPECIES_AEGISLASH               0
    #define SPECIES_AEGISLASH_BLADE         10000
    #define SPECIES_MIMIKYU                 0
    #define SPECIES_MIMIKYU_BUSTED          10001
    #define SPECIES_DARMANITAN              0
    #define SPECIES_DARMANITAN_ZEN_MODE     10002
    #define SPECIES_MINIOR_CORE_RED         0
    #define SPECIES_MINIOR                  10003
    #define SPECIES_MINIOR_CORE_BLUE        0
    #define SPECIES_MINIOR_METEOR_BLUE      10004
    #define SPECIES_MINIOR_CORE_GREEN       0
    #define SPECIES_MINIOR_METEOR_GREEN     10005
    #define SPECIES_MINIOR_CORE_INDIGO      0
    #define SPECIES_MINIOR_METEOR_INDIGO    10006
    #define SPECIES_MINIOR_CORE_ORANGE      0
    #define SPECIES_MINIOR_METEOR_ORANGE    10007
    #define SPECIES_MINIOR_CORE_VIOLET      0
    #define SPECIES_MINIOR_METEOR_VIOLET    10008
    #define SPECIES_MINIOR_CORE_YELLOW      0
    #define SPECIES_MINIOR_METEOR_YELLOW    10009
    #define SPECIES_WISHIWASHI              0
    #define SPECIES_WISHIWASHI_SCHOOL       10010
    #define SPECIES_ZYGARDE                 0     // 50%
    #define SPECIES_ZYGARDE_10              10011 // 10 %
    #define SPECIES_ZYGARDE_COMPLETE        10012 // 100 %
#endif

// Items with peculiar battle effects.
#ifndef ITEM_EXPANSION
    #define ITEM_CHOPLE_BERRY   177
    #define ITEM_KEBIA_BERRY    178
    #define ITEM_SHUCA_BERRY    179
    #define ITEM_COBA_BERRY     180
    #define ITEM_PAYAPA_BERRY   181
    #define ITEM_TANGA_BERRY    182
    #define ITEM_CHARTI_BERRY   183
    #define ITEM_KASIB_BERRY    184
    #define ITEM_HABAN_BERRY    185
    #define ITEM_COLBUR_BERRY   186
    #define ITEM_BABIRI_BERRY   187
    #define ITEM_CHILAN_BERRY   188
    #define ITEM_ROSELI_BERRY   189
    #define ITEM_MICLE_BERRY    197
    #define ITEM_CUSTAP_BERRY   199
    #define ITEM_JABOCA_BERRY   200
    #define ITEM_ROWAP_BERRY    201
    #define ITEM_KEE_BERRY      202
    #define ITEM_MARANGA_BERRY  203
    #define ITEM_OCCA_BERRY     204
    #define ITEM_PASSHO_BERRY   205
    #define ITEM_WACAN_BERRY    206
    #define ITEM_RINDO_BERRY    207
    #define ITEM_YACHE_BERRY    208
    #define ITEM_GRISEOUS_ORB   369
#endif

#ifndef GEN_3
    #define GEN_3 0
    #define GEN_4 1
    #define GEN_5 2
    #define GEN_6 3
    #define GEN_7 4
    #define GEN_8 5
#endif

// Calculation settings
#define B_CRIT_CHANCE               GEN_6 // Chances of a critical hit landing. See CalcCritChanceStage.
#define B_CRIT_MULTIPLIER           GEN_6 // In Gen6+, critical hits multiply damage by 1.5 instead of 2.
#define B_EXP_CATCH                 GEN_6 // In Gen6+, Pokémon get experience from catching.
#define B_TRAINER_EXP_MULTIPLIER    GEN_6 // In Gen7+, trainer battles no longer give a 1.5 multiplier to exp gain.
#define B_SPLIT_EXP                 GEN_5 // In Gen6+, all participating mon get full experience.
#define B_SCALED_EXP                GEN_6 // In Gen5 and Gen7+, experience is weighted by level difference.
#define B_BURN_DAMAGE               GEN_6 // In Gen7+, burn damage is 1/16th of max HP instead of 1/8th.
#define B_PARALYSIS_SPEED           GEN_6 // In Gen7+, speed is decreased by 50% instead of 75%.
#define B_TERRAIN_TYPE_BOOST        GEN_6 // In Gen8+, damage is boosted by 30% instead of 50%.
#define B_BINDING_DAMAGE            GEN_6 // In Gen6+, binding damage is 1/8 of max HP instead of 1/16. (With Binding Band, 1/6 and 1/8 respectively.)
#define B_CONFUSION_SELF_DMG_CHANCE GEN_6 // In Gen7+, confusion has a 33.3% of self-damage, instead of 50%.
#define B_MULTI_HIT_CHANCE          GEN_6 // In Gen5+, multi-hit moves have different %. See Cmd_setmultihitcounter for values.
#define B_RECOIL_IF_MISS_DMG        GEN_6 // In Gen5+, Jump Kick and Hi Jump Kick will always do half of the user's max HP when missing.
#define B_PSYWAVE_DMG               GEN_6 // Psywave's damage formula. See Cmd_psywavedamageeffect.
#define B_BADGE_BOOST               GEN_6 // In Gen4+, Gym Badges no longer boost a Pokémon's stats

// Move data settings
#define B_UPDATED_MOVE_DATA         GEN_7 // Updates move data in gBattleMoves, including Power, Accuracy, PP, stat changes, targets, chances of secondary effects, etc.
#define B_PHYSICAL_SPECIAL_SPLIT    GEN_6 // In Gen3, the move's type determines if it will do physical or special damage. The split icon in the summary will reflect this.
#define B_FELL_STINGER_STAT_RAISE   GEN_6 // In Gen7+, it raises Atk by 3 stages instead of 2 if it causes the target to faint.
#define B_KINGS_SHIELD_LOWER_ATK    GEN_6 // In Gen7+, it lowers Atk by 1 stage instead of 2 of oponents that hit it.
#define B_SPEED_BUFFING_RAPID_SPIN  GEN_8 // In Gen8, Rapid Spin raises the user's Speed by 1 stage.
#define B_WATER_SHURIKEN_SPLIT      GEN_8 // In Gen7, Water Shuriken was changed from Physical to Special.

// Other move settings
#define B_SOUND_SUBSTITUTE          GEN_6 // In Gen6+, sound moves bypass Substitute.
#define B_TOXIC_NEVER_MISS          GEN_6 // In Gen6+, if Toxic is used by a Poison type, it will never miss.
#define B_PAYBACK_SWITCH_BOOST      GEN_6 // In Gen5+, if the opponent switches out, Payback's damage will no longer be doubled.
#define B_BINDING_TURNS             GEN_6 // In Gen5+, binding moves last for 4-5 turns instead of 2-5 turns. (With Grip Claw, 7 and 5 turns respectively.)
#define B_UPROAR_TURNS              GEN_6 // In Gen5+, Uproar lasts for 3 turns instead of 2-5 turns.
#define B_DISABLE_TURNS             GEN_6 // Disable's turns. See Cmd_disablelastusedattack.
#define B_INCINERATE_GEMS           GEN_6 // In Gen6+, Incinerate can destroy Gems.
#define B_MINIMIZE_DMG_ACC          GEN_6 // In Gen6+, moves that causes double damage to minimized Pokémon will also skip accuracy checks.
#define B_PP_REDUCED_BY_SPITE       GEN_6 // In Gen4+, Spite reduces the foe's last move's PP by 4, instead of 2 to 5.
#define B_CAN_SPITE_FAIL            GEN_6 // In Gen4+, Spite can no longer fail if the foe's last move only has 1 remaining PP.
#define B_CRASH_IF_TARGET_IMMUNE    GEN_6 // In Gen4+, The user of Jump Kick or Hi Jump Kick will "keep going and crash" if it attacks a target that is immune to the move.
#define B_TAILWIND_TIMER            GEN_5 // In Gen5+, Tailwind lasts 4 turns instead of 3.
#define B_MEMENTO_FAIL              GEN_4 // In Gen4+, memento fails if there is no target or if the target is protected or behind substitute. But not if atk/sp.atk are at -6

// Ability settings
#define B_ABILITY_WEATHER           GEN_6 // In Gen6+, ability-induced weather lasts 5 turns. Before, it lasted until the battle ended or until it was changed by a move.
#define B_GALE_WINGS                GEN_6 // In Gen7+ requires full HP to trigger.
#define B_STANCE_CHANGE_FAIL        GEN_7 // In Gen7+, Stance Change fails if the Pokémon is unable to use a move because of confusion, paralysis, etc. In Gen6, it doesn't.
#define B_GHOSTS_ESCAPE             GEN_6 // In Gen6+, ghosts can escape even when blocked by abilities such as Shadow Tag.
#define B_MOODY_ACC_EVASION         GEN_6 // In Gen8+, Moody CANNOT raise Accuray and Evasion any more.
#define B_FLASH_FIRE_FROZEN         GEN_6 // In Gen5+, Flash Fire can trigger even when frozen, when it couldn't before.
#define B_SYNCHRONIZE_NATURE        GEN_6 // In Gen8+, if the Pokémon with Synchronize is leading the party, it's 100% guaranteed that wild Pokémon will have the same ability, as opposed to 50% previously.
#define B_UPDATED_INTIMIDATE        GEN_8 // In Gen8, Intimidate doesn't work on opponents with the Inner Focus, Scrappy, Own Tempo or Oblivious abilities.

// Item settings
#define B_HP_BERRIES                GEN_6 // In Gen4+, berries which restore hp activate immediately after hp drops to half. In gen3, the effect occurs at the end of the turn.
#define B_BERRIES_INSTANT           GEN_6 // In Gen4+, most berries activate on battle start/switch-in if applicable. In gen3, they only activate either at the move end or turn end.
#define B_X_ITEMS_BUFF              GEN_7 // In Gen7+, the X Items raise a stat by 2 stages instead of 1.

// Flag settings
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define B_FLAG_INVERSE_BATTLE       0     // If this flag is set, the battle's type effectiveness are inversed. For example, fire is super effective against water.
#define B_FLAG_FORCE_DOUBLE_WILD    0     // If this flag is set, all land and surfing wild battles will be double battles.

// Var Settings
// To use the following features in scripting, replace the 0s with the var ID you're assigning it to.
// Eg: Replace with VAR_UNUSED_0x40F7 so you can use VAR_TERRAIN for that feature.
#define VAR_TERRAIN                 0     // If this var has a value, assigning a STATUS_FIELD_xx_TERRAIN to it before battle causes the battle to start with that terrain active

// Interface settings
#define B_ABILITY_POP_UP            TRUE  // In Gen5+, the Pokémon abilities are displayed in a pop-up, when they activate in battle.
#define B_FAST_INTRO                TRUE  // If set to TRUE, battle intro texts print at the same time as animation of a Pokémon, as opposing to waiting for the animation to end.
#define B_SHOW_TARGETS              TRUE  // If set to TRUE, all available targets, for moves hitting 2 or 3 Pokémon, will be shown before selecting a move.
#define B_SHOW_SPLIT_ICON           TRUE  // If set to TRUE, it will show an icon in the summary showing the move's category split.

// Critical Capture
#define B_CRITICAL_CAPTURE          TRUE  // If set to TRUE, Critical Capture will be enabled.
#define B_CATCHING_CHARM_BOOST      20    // % boost in Critical Capture odds if player has the Catching Charm.

// Other
#define B_DOUBLE_WILD_CHANCE        0     // % chance of encountering two Pokémon in a Wild Encounter.
#define B_SLEEP_TURNS               GEN_6 // In Gen5+, sleep lasts for 1-3 turns instead of 2-5 turns.
#define B_PARALYZE_ELECTRIC         GEN_6 // In Gen6+, Electric-type Pokémon can't be paralyzed.
#define B_POWDER_GRASS              GEN_6 // In Gen6+, Grass-type Pokémon are immune to powder and spore moves.
#define B_STEEL_RESISTANCES         GEN_6 // In Gen6+, Steel-type Pokémon are no longer resistant to Dark and Ghost moves.
#define B_THUNDERSTORM_TERRAIN      TRUE  // If TRUE, overworld Thunderstorm generates Rain and Electric Terrain as in Gen 8.

// Animation Settings
#define B_NEW_SWORD_PARTICLE            FALSE    // If set to TRUE, it updates Swords Dance's particle.
#define B_NEW_LEECH_SEED_PARTICLE       FALSE    // If set to TRUE, it updates Leech Seed's animation particle.
#define B_NEW_HORN_ATTACK_PARTICLE      FALSE    // If set to TRUE, it updates Horn Attack's horn particle.
#define B_NEW_LEAF_PARTICLE             FALSE    // If set to TRUE, it updates leaf particle.
#define B_NEW_EMBER_PARTICLES           FALSE    // If set to TRUE, it updates Ember's fire particle.
#define B_NEW_MEAN_LOOK_PARTICLE        FALSE    // If set to TRUE, it updates Mean Look's eye particle.
#define B_NEW_TEETH_PARTICLE            FALSE    // If set to TRUE, it updates Bite/Crunch teeth particle.
#define B_NEW_HANDS_FEET_PARTICLE       FALSE    // If set to TRUE, it updates chop/kick/punch particles.
#define B_NEW_SPIKES_PARTICLE           FALSE    // If set to TRUE, it updates Spikes particle.
#define B_NEW_FLY_BUBBLE_PARTICLE       FALSE    // If set to TRUE, it updates Fly's 'bubble' particle.
#define B_NEW_CURSE_NAIL_PARTICLE       FALSE    // If set to TRUE, it updates Curse's nail.
#define B_NEW_BATON_PASS_BALL_PARTICLE  FALSE    // If set to TRUE, it updates Baton Pass' Poké Ball sprite.
#define B_NEW_MORNING_SUN_STAR_PARTICLE FALSE    // If set to TRUE, it updates Morning Sun's star particles.
#define B_NEW_IMPACT_PALETTE            FALSE    // If set to TRUE, it updates the basic 'hit' palette.
#define B_NEW_SURF_PARTICLE_PALETTE     FALSE    // If set to TRUE, it updates Surf's wave palette.

#define B_HIDE_HEALTHBOXES_DURING_ANIMS TRUE    // If set to TRUE, hides healthboxes during move animations.
#define B_TERRAIN_BG_CHANGE             TRUE    // If set to TRUE, terrain moves permanently change the default battle background until the effect fades.
#define B_ENABLE_DEBUG                  TRUE    // If set to TRUE, enables a debug menu to use in battles by pressing the Select button.

#endif // GUARD_CONSTANTS_BATTLE_CONFIG_H
