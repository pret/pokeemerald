#ifndef GUARD_CONSTANTS_SOUND_H
#define GUARD_CONSTANTS_SOUND_H

#define FANFARE_LEVEL_UP             0
#define FANFARE_OBTAIN_ITEM          1
#define FANFARE_EVOLVED              2
#define FANFARE_OBTAIN_TMHM          3
#define FANFARE_HEAL                 4
#define FANFARE_OBTAIN_BADGE         5
#define FANFARE_MOVE_DELETED         6
#define FANFARE_OBTAIN_BERRY         7
#define FANFARE_AWAKEN_LEGEND        8
#define FANFARE_SLOTS_JACKPOT        9
#define FANFARE_SLOTS_WIN           10
#define FANFARE_TOO_BAD             11
#define FANFARE_RG_POKE_FLUTE       12
#define FANFARE_RG_OBTAIN_KEY_ITEM  13
#define FANFARE_RG_DEX_RATING       14
#define FANFARE_OBTAIN_B_POINTS     15
#define FANFARE_OBTAIN_SYMBOL       16
#define FANFARE_REGISTER_MATCH_CALL 17

#define CRY_MODE_NORMAL        0 // Default
#define CRY_MODE_DOUBLES       1 // Shortened cry for double battles
#define CRY_MODE_ENCOUNTER     2 // Used when starting a static encounter, or when a Pokémon is "aggressive"
#define CRY_MODE_HIGH_PITCH    3 // Highest pitch mode, used exclusively by the move Howl
#define CRY_MODE_ECHO_START    4 // For 1st half of cry used by the move Hyper Voice. Played in reverse
#define CRY_MODE_FAINT         5 // Used when a Pokémon faints
#define CRY_MODE_ECHO_END      6 // For 2nd half of cry used by the move Hyper Voice
#define CRY_MODE_ROAR_1        7 // For 1st cry used by the move Roar
#define CRY_MODE_ROAR_2        8 // For 2nd cry used by the move Roar
#define CRY_MODE_GROWL_1       9 // For 1st cry used by the move Growl. Played in reverse
#define CRY_MODE_GROWL_2      10 // For 2nd cry used by the move Growl
#define CRY_MODE_WEAK         11 // Used when a Pokémon is unhealthy
#define CRY_MODE_WEAK_DOUBLES 12 // Equivalent to CRY_MODE_DOUBLES for CRY_MODE_WEAK
#define CRY_MODE_DYNAMAX      13 // Used during Dynamax

// Given to SoundTask_PlayDoubleCry to determine which cry mode to use. Values are arbitrary
#define DOUBLE_CRY_ROAR  2
#define DOUBLE_CRY_GROWL 255

#define CRY_PRIORITY_NORMAL 10
#define CRY_PRIORITY_AMBIENT 1

// Cry volume was changed from 125 in R/S to 120 for FRLG/Em, but was (accidentally?) not updated outside of sound.c
#define CRY_VOLUME    120
#define CRY_VOLUME_RS 125

#endif // GUARD_CONSTANTS_SOUND_H
