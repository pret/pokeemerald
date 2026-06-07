#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include <limits.h>
#include "config.h" // we need to define config before gba headers as print stuff needs the functions nulled before defines.
#include "gba/gba.h"
#include "gametypes.h"
#include "constants/global.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/species.h"
#include "constants/pokedex.h"
#include "constants/berry.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/easy_chat.h"
#include "constants/trainer_hill.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

#if MODERN
#define asm __asm__
#endif

/// IDE support
#if defined(__APPLE__) || defined(__CYGWIN__) || defined(__INTELLISENSE__)
// We define these when using certain IDEs to fool preproc
#define _(x)        {x}
#define __(x)       {x}
#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

// GameFreak used a macro called "NELEMS", as evidenced by
// AgbAssert calls.
#define NELEMS(arr) (sizeof(arr)/sizeof(*(arr)))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) << 8))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((int)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((int)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((int)((n) >> 8))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

#if MODERN
#define abs(x) (((x) < 0) ? -(x) : (x))
#endif

// Used in cases where division by 0 can occur in the retail version.
// Avoids invalid opcodes on some emulators, and the otherwise UB.
#ifdef UBFIX
#define SAFE_DIV(a, b) (((b) != 0) ? (a) / (b) : 0)
#else
#define SAFE_DIV(a, b) ((a) / (b))
#endif

// The below macro does a%n, but (to match) will switch to a&(n-1) if n is a power of 2.
// There are cases where GF does a&(n-1) where we would really like to have a%n, because
// if n is changed to a value that isn't a power of 2 then a&(n-1) is unlikely to work as
// intended, and a%n for powers of 2 isn't always optimized to use &.
#define MOD(a, n) (((n) & ((n)-1)) ? ((a) % (n)) : ((a) & ((n)-1)))

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

// There are many quirks in the source code which have overarching behavioral differences from
// a number of other files. For example, diploma.c seems to declare rodata before each use while
// other files declare out of order and must be at the beginning. There are also a number of
// macros which differ from one file to the next due to the method of obtaining the result, such
// as these below. Because of this, there is a theory (Two Team Theory) that states that these
// programming projects had more than 1 "programming team" which utilized different macros for
// each of the files that were worked on.
#define T1_READ_8(ptr)  ((ptr)[0])
#define T1_READ_16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define T1_READ_32(ptr) ((ptr)[0] | ((ptr)[1] << 8) | ((ptr)[2] << 16) | ((ptr)[3] << 24))
#define T1_READ_PTR(ptr) (u8 *) T1_READ_32(ptr)

// T2_READ_8 is a duplicate to remain consistent with each group.
#define T2_READ_8(ptr)  ((ptr)[0])
#define T2_READ_16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define T2_READ_32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define T2_READ_PTR(ptr) (void *) T2_READ_32(ptr)

#define PACK(data, shift, mask)   ( ((data) << (shift)) & (mask) )
#define UNPACK(data, shift, mask) ( ((data) & (mask)) >> (shift) )

// Macros for checking the joypad
#define TEST_BUTTON(field, button) ((field) & (button))
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)
#define JOY_HELD_RAW(button) TEST_BUTTON(gMain.heldKeysRaw, button)
#define JOY_REPEAT(button) TEST_BUTTON(gMain.newAndRepeatedKeys, button)

#define S16TOPOSFLOAT(val)   \
({                           \
    s16 v = (val);           \
    float f = (float)v;      \
    if(v < 0) f += 65536.0f; \
    f;                       \
})

#define DIV_ROUND_UP(val, roundBy) (((val) / (roundBy)) + (((val) % (roundBy)) ? 1 : 0))

#define ROUND_BITS_TO_BYTES(numBits) DIV_ROUND_UP(numBits, 8)

// NUM_DEX_FLAG_BYTES allocates more flags than it needs to, as NUM_SPECIES includes the "old unown"
// values that don't appear in the Pokédex. NATIONAL_DEX_COUNT does not include these values.
#define NUM_DEX_FLAG_BYTES ROUND_BITS_TO_BYTES(NUM_SPECIES)
#define NUM_FLAG_BYTES ROUND_BITS_TO_BYTES(FLAGS_COUNT)
#define NUM_TRENDY_SAYING_BYTES ROUND_BITS_TO_BYTES(NUM_TRENDY_SAYINGS)

// This returns the number of arguments passed to it (up to 8).
#define NARG_8(...) NARG_8_(_, ##__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define NARG_8_(_, a, b, c, d, e, f, g, h, N, ...) N

#define CAT(a, b) CAT_(a, b)
#define CAT_(a, b) a ## b

// This produces an error at compile-time if expr is zero.
// It looks like file.c:line: size of array `id' is negative
#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];

struct Coords8
{
    s8 x;
    s8 y;
};

struct UCoords8
{
    u8 x;
    u8 y;
};

struct Coords16
{
    s16 x;
    s16 y;
};

struct UCoords16
{
    u16 x;
    u16 y;
};

struct Coords32
{
    s32 x;
    s32 y;
};

struct UCoords32
{
    u32 x;
    u32 y;
};

struct Time
{
    s16 days;
    s8 hours;
    s8 minutes;
    s8 seconds;
};

struct Pokedex
{
    u8 order;
    u8 mode;
    u8 nationalMagic; // must equal 0xDA in order to have National mode
    u8 unknown2;
    u32 unownPersonality; // set when you first see Unown
    u32 spindaPersonality; // set when you first see Spinda
    u32 unknown3;
    u8 owned[NUM_DEX_FLAG_BYTES];
    u8 seen[NUM_DEX_FLAG_BYTES];
};

struct PokemonJumpRecords
{
    u16 jumpsInRow;
    u16 unused1; // Set to 0, never read
    u16 excellentsInRow;
    u16 gamesWithMaxPlayers;
    u32 unused2; // Set to 0, never read
    u32 bestJumpScore;
};

struct BerryPickingResults
{
    u32 bestScore;
    u16 berriesPicked;
    u16 berriesPickedInRow;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
};

struct PyramidBag
{
    u16 itemId[FRONTIER_LVL_MODE_COUNT][PYRAMID_BAG_ITEMS_COUNT];
    u8 quantity[FRONTIER_LVL_MODE_COUNT][PYRAMID_BAG_ITEMS_COUNT];
};

struct BerryCrush
{
    u16 pressingSpeeds[4]; // For the record with each possible group size, 2-5 players
    u32 berryPowderAmount;
    u32 unk;
};

struct ApprenticeMon
{
    u16 species;
    u16 moves[MAX_MON_MOVES];
    u16 item;
};

// This is for past players Apprentices or Apprentices received via Record Mix.
// For the current Apprentice, see struct PlayersApprentice
struct Apprentice
{
    u8 id:5;
    u8 lvlMode:2;
    //u8 padding1:1;
    u8 numQuestions;
    u8 number;
    //u8 padding2;
    struct ApprenticeMon party[MULTI_PARTY_SIZE];
    u16 speechWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    u8 playerId[TRAINER_ID_LENGTH];
    u8 playerName[PLAYER_NAME_LENGTH];
    u8 language;
    u32 checksum;
};

struct BattleTowerPokemon
{
    u16 species;
    u16 heldItem;
    u16 moves[MAX_MON_MOVES];
    u8 level;
    u8 ppBonuses;
    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;
    u8 spAttackEV;
    u8 spDefenseEV;
    u32 otId;
    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 speedIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 gap:1;
    u32 abilityNum:1;
    u32 personality;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 friendship;
};

struct EmeraldBattleTowerRecord
{
    u8 lvlMode; // 0 = level 50, 1 = level 100
    u8 facilityClass;
    u16 winStreak;
    u8 name[PLAYER_NAME_LENGTH + 1];
    u8 trainerId[TRAINER_ID_LENGTH];
    u16 greeting[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct BattleTowerPokemon party[MAX_FRONTIER_PARTY_SIZE];
    u8 language;
    //u8 padding[3];
    u32 checksum;
};

struct BattleTowerInterview
{
    u16 playerSpecies;
    u16 opponentSpecies;
    u8 opponentName[PLAYER_NAME_LENGTH + 1];
    u8 opponentMonNickname[POKEMON_NAME_LENGTH + 1];
    u8 opponentLanguage;
};

struct BattleTowerEReaderTrainer
{
    u8 unk0;
    u8 facilityClass;
    u16 winStreak;
    u8 name[PLAYER_NAME_LENGTH + 1];
    u8 trainerId[TRAINER_ID_LENGTH];
    u16 greeting[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 farewellPlayerLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 farewellPlayerWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct BattleTowerPokemon party[FRONTIER_PARTY_SIZE];
    u32 checksum;
};

// For displaying party information on the player's Battle Dome tourney page
struct DomeMonData
{
    u16 moves[MAX_MON_MOVES];
    u8 evs[NUM_STATS];
    u8 nature;
    //u8 padding;
};

struct RentalMon
{
    u16 monId;
    //u8 padding1[2];
    u32 personality;
    u8 ivs;
    u8 abilityNum;
    //u8 padding2[2];
};

struct BattleDomeTrainer
{
    u16 trainerId:10;
    u16 isEliminated:1;
    u16 eliminatedAt:2;
    u16 forfeited:3;
};

#define DOME_TOURNAMENT_TRAINERS_COUNT 16
#define BATTLE_TOWER_RECORD_COUNT 5

struct BattleFrontier
{
    struct EmeraldBattleTowerRecord towerPlayer;
    struct EmeraldBattleTowerRecord towerRecords[BATTLE_TOWER_RECORD_COUNT]; // From record mixing.
    struct BattleTowerInterview towerInterview;
    struct BattleTowerEReaderTrainer ereaderTrainer;
    u8 challengeStatus;
    u8 lvlMode:2;
    u8 challengePaused:1;
    u8 disableRecordBattle:1;
    //u8 padding1:4;
    u16 selectedPartyMons[MAX_FRONTIER_PARTY_SIZE];
    u16 curChallengeBattleNum; // Battle number / room number (Pike) / floor number (Pyramid)
    u16 trainerIds[20];
    u32 winStreakActiveFlags;
    u16 towerWinStreaks[4][FRONTIER_LVL_MODE_COUNT];
    u16 towerRecordWinStreaks[4][FRONTIER_LVL_MODE_COUNT];
    u16 battledBrainFlags;
    u16 towerSinglesStreak; // Never read
    u16 towerNumWins; // Increments to MAX_STREAK but never read otherwise
    u8 towerBattleOutcome;
    u8 towerLvlMode;
    u8 domeAttemptedSingles50:1;
    u8 domeAttemptedSinglesOpen:1;
    u8 domeHasWonSingles50:1;
    u8 domeHasWonSinglesOpen:1;
    u8 domeAttemptedDoubles50:1;
    u8 domeAttemptedDoublesOpen:1;
    u8 domeHasWonDoubles50:1;
    u8 domeHasWonDoublesOpen:1;
    u8 domeUnused;
    u8 domeLvlMode;
    u8 domeBattleMode;
    u16 domeWinStreaks[2][FRONTIER_LVL_MODE_COUNT];
    u16 domeRecordWinStreaks[2][FRONTIER_LVL_MODE_COUNT];
    u16 domeTotalChampionships[2][FRONTIER_LVL_MODE_COUNT];
    struct BattleDomeTrainer domeTrainers[DOME_TOURNAMENT_TRAINERS_COUNT];
    u16 domeMonIds[DOME_TOURNAMENT_TRAINERS_COUNT][FRONTIER_PARTY_SIZE];
    u16 unused_DC4;
    u16 palacePrize;
    u16 palaceWinStreaks[2][FRONTIER_LVL_MODE_COUNT];
    u16 palaceRecordWinStreaks[2][FRONTIER_LVL_MODE_COUNT];
    u16 arenaPrize;
    u16 arenaWinStreaks[FRONTIER_LVL_MODE_COUNT];
    u16 arenaRecordStreaks[FRONTIER_LVL_MODE_COUNT];
    u16 factoryWinStreaks[2][FRONTIER_LVL_MODE_COUNT];
    u16 factoryRecordWinStreaks[2][FRONTIER_LVL_MODE_COUNT];
    u16 factoryRentsCount[2][FRONTIER_LVL_MODE_COUNT];
    u16 factoryRecordRentsCount[2][FRONTIER_LVL_MODE_COUNT];
    u16 pikePrize;
    u16 pikeWinStreaks[FRONTIER_LVL_MODE_COUNT];
    u16 pikeRecordStreaks[FRONTIER_LVL_MODE_COUNT];
    u16 pikeTotalStreaks[FRONTIER_LVL_MODE_COUNT];
    u8 pikeHintedRoomIndex:3;
    u8 pikeHintedRoomType:4;
    u8 pikeHealingRoomsDisabled:1;
    //u8 padding2;
    u16 pikeHeldItemsBackup[FRONTIER_PARTY_SIZE];
    u16 pyramidPrize;
    u16 pyramidWinStreaks[FRONTIER_LVL_MODE_COUNT];
    u16 pyramidRecordStreaks[FRONTIER_LVL_MODE_COUNT];
    u16 pyramidRandoms[4];
    u8 pyramidTrainerFlags; // 1 bit for each trainer (MAX_PYRAMID_TRAINERS)
    //u8 padding3;
    struct PyramidBag pyramidBag;
    u8 pyramidLightRadius;
    //u8 padding4;
    u16 verdanturfTentPrize;
    u16 fallarborTentPrize;
    u16 slateportTentPrize;
    struct RentalMon rentalMons[FRONTIER_PARTY_SIZE * 2];
    u16 battlePoints;
    u16 cardBattlePoints;
    u32 battlesCount;
    u16 domeWinningMoves[DOME_TOURNAMENT_TRAINERS_COUNT];
    u8 trainerFlags;
    u8 opponentNames[FRONTIER_LVL_MODE_COUNT][PLAYER_NAME_LENGTH + 1];
    u8 opponentTrainerIds[FRONTIER_LVL_MODE_COUNT][TRAINER_ID_LENGTH];
    u8 unk_EF9:7; // Never read
    u8 savedGame:1;
    u8 unused_EFA;
    u8 unused_EFB;
    struct DomeMonData domePlayerPartyData[FRONTIER_PARTY_SIZE];
};

struct ApprenticeQuestion
{
    u8 questionId:2;
    u8 monId:2;
    u8 moveSlot:2;
    u8 suggestedChange:2; // TRUE if told to use held item or second move, FALSE if told to use no item or first move
    //u8 padding;
    u16 data; // used both as an itemId and a move
};

struct PlayersApprentice
{
    u8 id;
    u8 lvlMode:2;  //0: Unassigned, 1: Lv 50, 2: Open Lv
    u8 questionsAnswered:4;
    u8 leadMonId:2;
    u8 party:3;
    u8 saveId:2;
    //u8 padding1:3;
    u8 unused;
    u8 speciesIds[MULTI_PARTY_SIZE];
    //u8 padding2;
    struct ApprenticeQuestion questions[APPRENTICE_MAX_QUESTIONS];
};

struct RankingHall1P
{
    u8 id[TRAINER_ID_LENGTH];
    u16 winStreak;
    u8 name[PLAYER_NAME_LENGTH + 1];
    u8 language;
    //u8 padding;
};

struct RankingHall2P
{
    u8 id1[TRAINER_ID_LENGTH];
    u8 id2[TRAINER_ID_LENGTH];
    u16 winStreak;
    u8 name1[PLAYER_NAME_LENGTH + 1];
    u8 name2[PLAYER_NAME_LENGTH + 1];
    u8 language;
    //u8 padding;
};

struct SaveBlock2
{
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 playerGender; // MALE, FEMALE
    u8 specialSaveWarpFlags;
    u8 playerTrainerId[TRAINER_ID_LENGTH];
    u16 playTimeHours;
    u8 playTimeMinutes;
    u8 playTimeSeconds;
    u8 playTimeVBlanks;
    u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
    u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
    u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
    u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
    u16 optionsBattleSceneOff:1; // whether battle animations are disabled
    u16 regionMapZoom:1; // whether the map is zoomed in
    //u16 padding1:4;
    //u16 padding2;
    struct Pokedex pokedex;
    u8 filler_90[0x8];
    struct Time localTimeOffset;
    struct Time lastBerryTreeUpdate;
    u32 gcnLinkFlags; // Read by Pokémon Colosseum/XD
    u32 encryptionKey;
    struct PlayersApprentice playerApprentice;
    struct Apprentice apprentices[APPRENTICE_COUNT];
    struct BerryCrush berryCrush;
    struct PokemonJumpRecords pokeJump;
    struct BerryPickingResults berryPick;
    struct RankingHall1P hallRecords1P[HALL_FACILITIES_COUNT][FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT]; // From record mixing.
    struct RankingHall2P hallRecords2P[FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT]; // From record mixing.
    u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    struct BattleFrontier frontier;
}; // sizeof=0xF2C

extern struct SaveBlock2 *gSaveBlock2Ptr;

struct SecretBaseParty
{
    u32 personality[PARTY_SIZE];
    u16 moves[PARTY_SIZE * MAX_MON_MOVES];
    u16 species[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    u8 levels[PARTY_SIZE];
    u8 EVs[PARTY_SIZE];
};

struct SecretBase
{
    u8 secretBaseId;
    bool8 toRegister:4;
    u8 gender:1;
    u8 battledOwnerToday:1;
    u8 registryStatus:2;
    u8 trainerName[PLAYER_NAME_LENGTH];
    u8 trainerId[TRAINER_ID_LENGTH]; // byte 0 is used for determining trainer class
    u8 language;
    u16 numSecretBasesReceived;
    u8 numTimesEntered;
    u8 unused;
    u8 decorations[DECOR_MAX_SECRET_BASE];
    u8 decorationPositions[DECOR_MAX_SECRET_BASE];
    //u8 padding[2];
    struct SecretBaseParty party;
};

#include "constants/game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "global.tv.h"
#include "pokemon.h"

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    //u8 padding;
    s16 x, y;
};

struct ItemSlot
{
    u16 itemId;
    u16 quantity;
};

struct Pokeblock
{
    u8 color;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 feel;
};

struct Roamer
{
    u32 ivs;
    u32 personality;
    u16 species;
    u16 hp;
    u8 level;
    u8 status;
    u8 cool;
    u8 beauty;
    u8 cute;
    u8 smart;
    u8 tough;
    bool8 active;
    u8 filler[0x8];
};

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 localId;
    u8 script[995];
    //u8 padding;
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

// See dewford_trend.c
struct DewfordTrend
{
    u16 trendiness:7;
    u16 maxTrendiness:7;
    u16 gainingTrendiness:1;
    //u16 padding:1;
    u16 rand;
    u16 words[2];
}; /*size = 0x8*/

struct MauvilleManCommon
{
    u8 id;
};

struct MauvilleManBard
{
    u8 id;
    //u8 padding1;
    u16 songLyrics[NUM_BARD_SONG_WORDS];
    u16 newSongLyrics[NUM_BARD_SONG_WORDS];
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 filler_2DB6[0x3];
    u8 playerTrainerId[TRAINER_ID_LENGTH];
    bool8 hasChangedSong;
    u8 language;
    //u8 padding2;
}; /*size = 0x2C*/

struct MauvilleManStoryteller
{
    u8 id;
    bool8 alreadyRecorded;
    u8 filler2[2];
    u8 gameStatIDs[NUM_STORYTELLER_TALES];
    u8 trainerNames[NUM_STORYTELLER_TALES][PLAYER_NAME_LENGTH];
    u8 statValues[NUM_STORYTELLER_TALES][4];
    u8 language[NUM_STORYTELLER_TALES];
};

struct MauvilleManGiddy
{
    u8 id;
    u8 taleCounter;
    u8 questionNum;
    //u8 padding1;
    u16 randomWords[GIDDY_MAX_TALES];
    u8 questionList[GIDDY_MAX_QUESTIONS];
    u8 language;
    //u8 padding2;
}; /*size = 0x2C*/

struct MauvilleManHipster
{
    u8 id;
    bool8 taughtWord;
    u8 language;
};

struct MauvilleOldManTrader
{
    u8 id;
    u8 decorations[NUM_TRADER_ITEMS];
    u8 playerNames[NUM_TRADER_ITEMS][11];
    u8 alreadyTraded;
    u8 language[NUM_TRADER_ITEMS];
};

typedef union OldMan
{
    struct MauvilleManCommon common;
    struct MauvilleManBard bard;
    struct MauvilleManGiddy giddy;
    struct MauvilleManHipster hipster;
    struct MauvilleOldManTrader trader;
    struct MauvilleManStoryteller storyteller;
    u8 filler[0x40];
} OldMan;

#define LINK_B_RECORDS_COUNT 5

struct LinkBattleRecord
{
    u8 name[PLAYER_NAME_LENGTH + 1];
    u16 trainerId;
    u16 wins;
    u16 losses;
    u16 draws;
};

struct LinkBattleRecords
{
    struct LinkBattleRecord entries[LINK_B_RECORDS_COUNT];
    u8 languages[LINK_B_RECORDS_COUNT];
    //u8 padding;
};

struct RecordMixingGiftData
{
    u8 unk0;
    u8 quantity;
    u16 itemId;
    u8 filler4[8];
};

struct RecordMixingGift
{
    int checksum;
    struct RecordMixingGiftData data;
};

struct ContestWinner
{
    u32 personality;
    u32 trainerId;
    u16 species;
    u8 contestCategory;
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u8 contestRank;
    //u8 padding;
};

struct Mail
{
    u16 words[MAIL_WORDS_COUNT];
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 trainerId[TRAINER_ID_LENGTH];
    u16 species;
    u16 itemId;
};

struct DaycareMail
{
    struct Mail message;
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 gameLanguage:4;
    u8 monLanguage:4;
};

struct DaycareMon
{
    struct BoxPokemon mon;
    struct DaycareMail mail;
    u32 steps;
};

struct DayCare
{
    struct DaycareMon mons[DAYCARE_MON_COUNT];
    u32 offspringPersonality;
    u8 stepCounter;
    //u8 padding[3];
};

struct LilycoveLadyQuiz
{
    u8 id;
    u8 state;
    u16 question[QUIZ_QUESTION_LEN];
    u16 correctAnswer;
    u16 playerAnswer;
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u16 playerTrainerId[TRAINER_ID_LENGTH];
    u16 prize;
    bool8 waitingForChallenger;
    u8 questionId;
    u8 prevQuestionId;
    u8 language;
};

struct LilycoveLadyFavor
{
    u8 id;
    u8 state;
    bool8 likedItem;
    u8 numItemsGiven;
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 favorId;
    //u8 padding1;
    u16 itemId;
    u16 bestItem;
    u8 language;
    //u8 padding2;
};

struct LilycoveLadyContest
{
    u8 id;
    bool8 givenPokeblock;
    u8 numGoodPokeblocksGiven;
    u8 numOtherPokeblocksGiven;
    u8 playerName[PLAYER_NAME_LENGTH + 1];
    u8 maxSheen;
    u8 category;
    u8 language;
};

typedef union // 3b58
{
    struct LilycoveLadyQuiz quiz;
    struct LilycoveLadyFavor favor;
    struct LilycoveLadyContest contest;
    u8 id;
    u8 filler[0x40];
} LilycoveLady;

struct WaldaPhrase
{
    u16 colors[2]; // Background, foreground.
    u8 text[16];
    u8 iconId;
    u8 patternId;
    bool8 patternUnlocked;
    //u8 padding;
};

struct TrainerNameRecord
{
    u32 trainerId;
    u8 ALIGNED(2) trainerName[PLAYER_NAME_LENGTH + 1];
};

struct TrainerHillSave
{
    u32 timer;
    u32 bestTime;
    u8 unk_3D6C;
    u8 unused;
    u16 receivedPrize:1;
    u16 checkedFinalTime:1;
    u16 spokeToOwner:1;
    u16 hasLost:1;
    u16 maybeECardScanDuringChallenge:1;
    u16 field_3D6E_0f:1;
    u16 mode:2; // HILL_MODE_*
    //u16 padding:8;
};

struct WonderNewsMetadata
{
    u8 newsType:2;
    u8 sentRewardCounter:3;
    u8 rewardCounter:3;
    u8 berry;
    //u8 padding[2];
};

struct WonderNews
{
    u16 id;
    u8 sendType; // SEND_TYPE_*
    u8 bgType;
    u8 titleText[WONDER_NEWS_TEXT_LENGTH];
    u8 bodyText[WONDER_NEWS_BODY_TEXT_LINES][WONDER_NEWS_TEXT_LENGTH];
};

struct WonderCard
{
    u16 flagId; // Event flag (sReceivedGiftFlags) + WONDER_CARD_FLAG_OFFSET
    u16 iconSpecies;
    u32 idNumber;
    u8 type:2; // CARD_TYPE_*
    u8 bgType:4;
    u8 sendType:2; // SEND_TYPE_*
    u8 maxStamps;
    u8 titleText[WONDER_CARD_TEXT_LENGTH];
    u8 subtitleText[WONDER_CARD_TEXT_LENGTH];
    u8 bodyText[WONDER_CARD_BODY_TEXT_LINES][WONDER_CARD_TEXT_LENGTH];
    u8 footerLine1Text[WONDER_CARD_TEXT_LENGTH];
    u8 footerLine2Text[WONDER_CARD_TEXT_LENGTH];
    //u8 padding[2];
};

struct WonderCardMetadata
{
    u16 battlesWon;
    u16 battlesLost;
    u16 numTrades;
    u16 iconSpecies;
    u16 stampData[2][MAX_STAMP_CARD_STAMPS]; // First element is STAMP_SPECIES, second is STAMP_ID
};

struct MysteryGiftSave
{
    u32 newsCrc;
    struct WonderNews news;
    u32 cardCrc;
    struct WonderCard card;
    u32 cardMetadataCrc;
    struct WonderCardMetadata cardMetadata;
    u16 questionnaireWords[NUM_QUESTIONNAIRE_WORDS];
    struct WonderNewsMetadata newsMetadata;
    u32 trainerIds[2][5]; // Saved ids for 10 trainers, 5 each for battles and trades
}; // 0x36C 0x3598

// For external event data storage. The majority of these may have never been used.
// In Emerald, the only known used fields are the PokeCoupon and BoxRS ones, but hacking the distribution discs allows Emerald to receive events and set the others
struct ExternalEventData
{
    u8 unknownExternalDataFields1[7]; // if actually used, may be broken up into different fields.
    u32 unknownExternalDataFields2:8;
    u32 currentPokeCoupons:24; // PokéCoupons stored by Pokémon Colosseum and XD from Mt. Battle runs. Earned PokéCoupons are also added to totalEarnedPokeCoupons. Colosseum/XD caps this at 9,999,999, but will read up to 16,777,215.
    u32 gotGoldPokeCouponTitleReward:1; // Master Ball from JP Colosseum Bonus Disc; for reaching 30,000 totalEarnedPokeCoupons
    u32 gotSilverPokeCouponTitleReward:1; // Light Ball Pikachu from JP Colosseum Bonus Disc; for reaching 5000 totalEarnedPokeCoupons
    u32 gotBronzePokeCouponTitleReward:1; // PP Max from JP Colosseum Bonus Disc; for reaching 2500 totalEarnedPokeCoupons
    u32 receivedAgetoCelebi:1; // from JP Colosseum Bonus Disc
    u32 unknownExternalDataFields3:4;
    u32 totalEarnedPokeCoupons:24; // Used by the JP Colosseum bonus disc. Determines PokéCoupon rank to distribute rewards. Unread in International games. Colosseum/XD caps this at 9,999,999.
    u8 unknownExternalDataFields4[5]; // if actually used, may be broken up into different fields.
} __attribute__((packed)); /*size = 0x14*/

// For external event flags. The majority of these may have never been used.
// In Emerald, Jirachi cannot normally be received, but hacking the distribution discs allows Emerald to receive Jirachi and set the flag
struct ExternalEventFlags
{
    u8 usedBoxRS:1; // Set by Pokémon Box: Ruby & Sapphire; denotes whether this save has connected to it and triggered the free False Swipe Swablu Egg giveaway.
    u8 boxRSEggsUnlocked:2; // Set by Pokémon Box: Ruby & Sapphire; denotes the number of Eggs unlocked from deposits; 1 for ExtremeSpeed Zigzagoon (at 100 deposited), 2 for Pay Day Skitty (at 500 deposited), 3 for Surf Pichu (at 1499 deposited)
    //u8 padding:5;
    u8 unknownFlag1;
    u8 receivedGCNJirachi; // Both the US Colosseum Bonus Disc and PAL/AUS Pokémon Channel use this field. One cannot receive a WISHMKR Jirachi and CHANNEL Jirachi with the same savefile.
    u8 unknownFlag3;
    u8 unknownFlag4;
    u8 unknownFlag5;
    u8 unknownFlag6;
    u8 unknownFlag7;
    u8 unknownFlag8;
    u8 unknownFlag9;
    u8 unknownFlag10;
    u8 unknownFlag11;
    u8 unknownFlag12;
    u8 unknownFlag13;
    u8 unknownFlag14;
    u8 unknownFlag15;
    u8 unknownFlag16;
    u8 unknownFlag17;
    u8 unknownFlag18;
    u8 unknownFlag19;
    u8 unknownFlag20;

} __attribute__((packed));/*size = 0x15*/

struct SaveBlock1
{
    struct Coords16 pos;
    struct WarpData location;
    struct WarpData continueGameWarp;
    struct WarpData dynamicWarp;
    struct WarpData lastHealLocation; // used by white-out and teleport
    struct WarpData escapeWarp; // used by Dig and Escape Rope
    u16 savedMusic;
    u8 weather;
    u8 weatherCycleStage;
    u8 flashLevel;
    //u8 padding1;
    u16 mapLayoutId;
    u16 mapView[0x100];
    u8 playerPartyCount;
    //u8 padding2[3];
    struct Pokemon playerParty[PARTY_SIZE];
    u32 money;
    u16 coins;
    u16 registeredItem; // registered for use with SELECT button
    struct ItemSlot pcItems[PC_ITEMS_COUNT];
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
    struct Pokeblock pokeblocks[POKEBLOCKS_COUNT];
    u8 seen1[NUM_DEX_FLAG_BYTES];
    u16 berryBlenderRecords[3];
    u8 unused_9C2[6];
    u16 trainerRematchStepCounter;
    u8 trainerRematches[MAX_REMATCH_ENTRIES];
    //u8 padding3[2];
    struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];
    u8 flags[NUM_FLAG_BYTES];
    u16 vars[VARS_COUNT];
    u32 gameStats[NUM_GAME_STATS];
    struct BerryTree berryTrees[BERRY_TREES_COUNT];
    struct SecretBase secretBases[SECRET_BASES_COUNT];
    u8 playerRoomDecorations[DECOR_MAX_PLAYERS_HOUSE];
    u8 playerRoomDecorationPositions[DECOR_MAX_PLAYERS_HOUSE];
    u8 decorationDesks[10];
    u8 decorationChairs[10];
    u8 decorationPlants[10];
    u8 decorationOrnaments[30];
    u8 decorationMats[30];
    u8 decorationPosters[10];
    u8 decorationDolls[40];
    u8 decorationCushions[10];
    //u8 padding4[2];
    TVShow tvShows[TV_SHOWS_COUNT];
    PokeNews pokeNews[POKE_NEWS_COUNT];
    u16 outbreakPokemonSpecies;
    u8 outbreakLocationMapNum;
    u8 outbreakLocationMapGroup;
    u8 outbreakPokemonLevel;
    u8 outbreakUnused1;
    u16 outbreakUnused2;
    u16 outbreakPokemonMoves[MAX_MON_MOVES];
    u8 outbreakUnused3;
    u8 outbreakPokemonProbability;
    u16 outbreakDaysLeft;
    struct GabbyAndTyData gabbyAndTyData;
    u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 easyChatBattleStart[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 easyChatBattleWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 easyChatBattleLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct Mail mail[MAIL_COUNT];
    u8 unlockedTrendySayings[NUM_TRENDY_SAYING_BYTES]; // Bitfield for unlockable Easy Chat words in EC_GROUP_TRENDY_SAYING
    //u8 padding5[3];
    OldMan oldMan;
    struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    struct ContestWinner contestWinners[NUM_CONTEST_WINNERS]; // see CONTEST_WINNER_*
    struct DayCare daycare;
    struct LinkBattleRecords linkBattleRecords;
    u8 giftRibbons[GIFT_RIBBONS_COUNT];
    struct ExternalEventData externalEventData;
    struct ExternalEventFlags externalEventFlags;
    struct Roamer roamer;
    struct EnigmaBerry enigmaBerry;
    struct MysteryGiftSave mysteryGift;
    u8 unused_3598[0x180];
    u32 trainerHillTimes[NUM_TRAINER_HILL_MODES];
    struct RamScript ramScript;
    struct RecordMixingGift recordMixingGift;
    u8 seen2[NUM_DEX_FLAG_BYTES];
    LilycoveLady lilycoveLady;
    struct TrainerNameRecord trainerNameRecords[20];
    u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    u8 unused_3D5A[10];
    struct TrainerHillSave trainerHill;
    struct WaldaPhrase waldaPhrase;
    // sizeof: 0x3D88
};

extern struct SaveBlock1 *gSaveBlock1Ptr;

struct MapPosition
{
    s16 x;
    s16 y;
    s8 elevation;
};

#endif // GUARD_GLOBAL_H
