#ifndef GUARD_CONFIG_DEXNAV_H
#define GUARD_CONFIG_DEXNAV_H

#define DEXNAV_ENABLED                FALSE  // Whether or not DexNav is enabled. If TRUE, flags/vars below must all be non-zero
#define USE_DEXNAV_SEARCH_LEVELS      FALSE  /* WARNING: POSSIBLY EXCEEDS SAVEBLOCK SPACE! REQUIRES 1 BYTE PER SPECIES */

// Flag/var defines
#define DN_FLAG_SEARCHING             0 // Searching for mon
#define DN_FLAG_DEXNAV_GET            0 // DexNav shows in start menu
#define DN_FLAG_DETECTOR_MODE         0 // Allow player to find hidden mons
#define DN_VAR_SPECIES                0 // Registered DexNav species
#define DN_VAR_STEP_COUNTER           0 // Steps for finding hidden Pokémon

// Search parameters
#define DEXNAV_TIMEOUT                  15  // 15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY              4   // Tile amount
#define CREEPING_PROXIMITY              2
#define MAX_PROXIMITY                   20

#define DEXNAV_CHAIN_MAX                100 // maximum chain value

// hidden Pokémon options - an approximation of values due to lack of available data
#define HIDDEN_MON_STEP_COUNT       100  // Look for hidden Pokémon every x steps
#define HIDDEN_MON_SEARCH_RATE      25   // x% chance of finding hidden Pokémon every x steps
#define HIDDEN_MON_PROBABILTY       15   // x% chance of finding hidden mon compared to regular encounter data

//// SEARCH PROBABILITIES
// See https://bulbapedia.bulbagarden.net/wiki/DexNav#Benefits
// Chance of encountering egg move at search levels
#define SEARCHLEVEL0_MOVECHANCE         0
#define SEARCHLEVEL5_MOVECHANCE         21
#define SEARCHLEVEL10_MOVECHANCE        46
#define SEARCHLEVEL25_MOVECHANCE        58
#define SEARCHLEVEL50_MOVECHANCE        63
#define SEARCHLEVEL100_MOVECHANCE       83
// Chance of encountering Hidden Abilities at search levels
#define SEARCHLEVEL0_ABILITYCHANCE      0
#define SEARCHLEVEL5_ABILITYCHANCE      0
#define SEARCHLEVEL10_ABILITYCHANCE     5
#define SEARCHLEVEL25_ABILITYCHANCE     15
#define SEARCHLEVEL50_ABILITYCHANCE     20
#define SEARCHLEVEL100_ABILITYCHANCE    23
// Chance of encountering held item
#define SEARCHLEVEL0_ITEM               0
#define SEARCHLEVEL5_ITEM               0
#define SEARCHLEVEL10_ITEM              1
#define SEARCHLEVEL25_ITEM              7
#define SEARCHLEVEL50_ITEM              6
#define SEARCHLEVEL100_ITEM             12
// Chance of encountering one star potential
#define SEARCHLEVEL0_ONESTAR            0
#define SEARCHLEVEL5_ONESTAR            14
#define SEARCHLEVEL10_ONESTAR           17
#define SEARCHLEVEL25_ONESTAR           17
#define SEARCHLEVEL50_ONESTAR           15
#define SEARCHLEVEL100_ONESTAR          8
// Chance of encountering two star potential
#define SEARCHLEVEL0_TWOSTAR            0
#define SEARCHLEVEL5_TWOSTAR            1
#define SEARCHLEVEL10_TWOSTAR           9
#define SEARCHLEVEL25_TWOSTAR           16
#define SEARCHLEVEL50_TWOSTAR           17
#define SEARCHLEVEL100_TWOSTAR          24
// Chance of encountering three star potential
#define SEARCHLEVEL0_THREESTAR          0
#define SEARCHLEVEL5_THREESTAR          0
#define SEARCHLEVEL10_THREESTAR         1
#define SEARCHLEVEL25_THREESTAR         7
#define SEARCHLEVEL50_THREESTAR         6
#define SEARCHLEVEL100_THREESTAR        12

#endif // GUARD_CONFIG_DEXNAV_H
