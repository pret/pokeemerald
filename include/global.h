#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"
#include "config.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")

#if defined (__APPLE__) || defined (__CYGWIN__)
void *memset(void *, int, size_t);
void *memcpy(void *, const void *, size_t);
int strcmp(const char *s1, const char *s2);
char* strcpy(char *dst0, const char *src0);
#endif // __APPLE__

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

#define POKEMON_NAME_LENGTH 10
#define OT_NAME_LENGTH 7

extern u8 gStringVar1[];
extern u8 gStringVar2[];
extern u8 gStringVar3[];
extern u8 gStringVar4[];

enum
{
    VERSION_SAPPHIRE = 1,
    VERSION_RUBY = 2,
    VERSION_EMERALD = 3,
    VERSION_FIRE_RED = 4,
    VERSION_LEAF_GREEN = 5,
};

enum LanguageId {
    LANGUAGE_JAPANESE = 1,
    LANGUAGE_ENGLISH = 2,
    LANGUAGE_GERMAN = 5,
};

#define GAME_LANGUAGE (LANGUAGE_ENGLISH)

enum
{
    MALE,
    FEMALE
};

enum
{
    OPTIONS_BUTTON_MODE_NORMAL,
    OPTIONS_BUTTON_MODE_LR,
    OPTIONS_BUTTON_MODE_L_EQUALS_A
};

enum
{
    OPTIONS_TEXT_SPEED_SLOW,
    OPTIONS_TEXT_SPEED_MID,
    OPTIONS_TEXT_SPEED_FAST
};

enum
{
    OPTIONS_SOUND_MONO,
    OPTIONS_SOUND_STEREO
};

enum
{
    OPTIONS_BATTLE_STYLE_SHIFT,
    OPTIONS_BATTLE_STYLE_SET
};

enum
{
    BAG_ITEMS = 1,
    BAG_POKEBALLS,
    BAG_TMsHMs,
    BAG_BERRIES,
    BAG_KEYITEMS
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

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

struct Pokedex
{
    /*0x00*/ u8 order;
    /*0x01*/ u8 unknown1;
    /*0x02*/ u8 nationalMagic; // must equal 0xDA in order to have National mode
    /*0x03*/ u8 unknown2;
    /*0x04*/ u32 unownPersonality; // set when you first see Unown
    /*0x08*/ u32 spindaPersonality; // set when you first see Spinda
    /*0x0C*/ u32 unknown3;
    /*0x10*/ u8 owned[52];
    /*0x44*/ u8 seen[52];
};

struct PokemonJumpResults // possibly used in the game itself?
{
    u16 jumpsInRow;
    u16 field2;
    u16 excellentsInRow;
    u16 field6;
    u16 field8;
    u16 fieldA;
    u32 bestJumpScore;
};

struct BerryPickingResults // possibly used in the game itself? Size may be wrong as well
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
    u16 items_Lvl50[10];
    u16 items_OpenLvl[10];
    u8 quantity[10];
};

struct BerryCrush
{
    u16 berryCrushResults[4];
    u32 berryPowderAmount;
    u32 unk;
};

#define PLAYER_NAME_LENGTH  8

struct SaveBlock2
{
    /*0x00*/ u8 playerName[PLAYER_NAME_LENGTH];
    /*0x08*/ u8 playerGender; // MALE, FEMALE
    /*0x09*/ u8 specialSaveWarp;
    /*0x0A*/ u8 playerTrainerId[4];
    /*0x0E*/ u16 playTimeHours;
    /*0x10*/ u8 playTimeMinutes;
    /*0x11*/ u8 playTimeSeconds;
    /*0x12*/ u8 playTimeVBlanks;
    /*0x13*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x14*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
             u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
             u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
             u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
             u16 optionsBattleSceneOff:1; // whether battle animations are disabled
             u16 regionMapZoom:1; // whether the map is zoomed in
    /*0x18*/ struct Pokedex pokedex;
    /*0x90*/ u8 filler_90[0x8];
    /*0x98*/ struct Time localTimeOffset;
    /*0xA0*/ struct Time lastBerryTreeUpdate;
    /*0xA8*/ u32 field_A8;
    /*0xAC*/ u32 encryptionKey;

        // TODO: fix and verify labels
    /*0xB0*/ u8 field_B0[316];
    /*0x1EC*/ struct BerryCrush berryCrush;
    /*0x1FC*/ struct PokemonJumpResults pokeJump;
    /*0x20C*/ struct BerryPickingResults berryPick;
    /*0x214*/ u8 field_214[1032];
    /*0x624*/ u16 contestLinkResults[20]; // 4 positions for 5 categories, possibly a struct or a 2d array

        // All below could be a one giant struct

    /*0x64C*/ u8 field_64C[0x588];
    /*0xBD4*/ u16 field_BD4;
    /*0xBD6*/ u16 field_BD6;
    /*0xBD8*/ u8 field_BD8[11];
    /*0xBE3*/ u8 filler_BE3[8];
    /*0xBEB*/ u8 field_BEB;
    /*0xBE3*/ u8 filler_BEC[189];
    /*0xCA9*/ u8 frontierChosenLvl : 2; // 0x1, 0x2 -> 0x3
    /*0xCA9*/ u8 field_CA9_a : 1;   // 0x4
    /*0xCA9*/ u8 field_CA9_b : 1;   // 0x8
    /*0xCA9*/ u8 field_CA9_c : 1;   // 0x10
    /*0xCA9*/ u8 field_CA9_d : 1;   // 0x20
    /*0xCA9*/ u8 field_CA9_e : 1;   // 0x40
    /*0xCA9*/ u8 field_CA9_f : 1;   // 0x80
    /*0xCAA*/ u16 field_CAA[0x2e];
    /*0xD06*/ u8 field_D06;
    /*0xD07*/ u8 field_D07;
    /*0xd08*/ u8 filler_D08[0x112];
    /*0xE1A*/ u16 battlePyramidFloor; // possibly?
    /*0xE1C*/ u8 field_E1C[16];
    /*0xE2C*/ struct PyramidBag pyramidBag;
    /*0x???*/ u8 field_notSure[13];
    /*0xE6E*/ u16 battleTentWinStreak;
    /*0xE70*/ u8 field_E70[72];
    /*0xEB8*/ u16 frontierBattlePoints;
    /*0xEBA*/ u8 field_EBA[39];
    /*0xEE1*/ u8 field_EE1;
    /*0xEE2*/ u8 field_EE2[7];
    /*0xEE9*/ u8 field_EE9;
    /*0xEEA*/ u8 field_EEA[66];
    // sizeof=0xF2C
};

extern struct SaveBlock2 *gSaveBlock2Ptr;

struct SecretBaseRecord
{
    /*0x1A9C*/ u8 secretBaseId;
    /*0x1A9D*/ u8 sbr_field_1_0:4;
    /*0x1A9D*/ u8 gender:1;
    /*0x1A9D*/ u8 sbr_field_1_5:1;
    /*0x1A9D*/ u8 sbr_field_1_6:2;
    /*0x1A9E*/ u8 trainerName[OT_NAME_LENGTH];
    /*0x1AA5*/ u8 trainerId[4]; // byte 0 is used for determining trainer class
    /*0x1AA9*/ u8 language;
    /*0x1AAA*/ u16 sbr_field_e;
    /*0x1AAC*/ u8 sbr_field_10;
    /*0x1AAD*/ u8 sbr_field_11;
    /*0x1AAE*/ u8 decorations[16];
    /*0x1ABE*/ u8 decorationPos[16];
    /*0x1AD0*/ u32 partyPersonality[6];
    /*0x1AE8*/ u16 partyMoves[6 * 4];
    /*0x1B18*/ u16 partySpecies[6];
    /*0x1B24*/ u16 partyHeldItems[6];
    /*0x1B2E*/ u8 partyLevels[6];
    /*0x1B34*/ u8 partyEVs[6];
};

#include "game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "global.tv.h"
#include "pokemon.h"

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
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
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ bool8 active;
    /*0x14*/ u8 filler[0x8];
};

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 objectId;
    u8 script[995];
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

struct EasyChatPair
{
    u16 unk0_0:7;
    u16 unk0_7:7;
    u16 unk1_6:1;
    u16 unk2;
    u16 words[2];
}; /*size = 0x8*/

struct MailStruct
{
    /*0x00*/ u16 words[9];
    /*0x12*/ u8 playerName[8];
    /*0x1A*/ u8 trainerId[4];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
};

struct UnkMauvilleOldManStruct
{
               u8 unk_2D94;
               u8 unk_2D95;
    /*0x2D96*/ u16 mauvilleOldMan_ecArray[6];
    /*0x2DA2*/ u16 mauvilleOldMan_ecArray2[6];
    /*0x2DAE*/ u8 playerName[8];
    /*0x2DB6*/ u8 filler_2DB6[0x3];
    /*0x2DB9*/ u8 playerTrainerId[4];
               u8 unk_2DBD;
}; /*size = 0x2C*/

struct UnkMauvilleOldManStruct2
{
    u8 filler0;
    u8 unk1;
    u8 unk2;
    u16 mauvilleOldMan_ecArray[10];
    u8 mauvilleOldMan_ecArray2[12];
    u8 fillerF[0x2];
}; /*size = 0x2C*/

struct MauvilleOldManTrader
{
    u8 unk0;
    u8 unk1[4];
    u8 unk5[4][11];
    u8 unk31;
};

typedef union OldMan
{
    struct UnkMauvilleOldManStruct oldMan1;
    struct UnkMauvilleOldManStruct2 oldMan2;
    struct MauvilleOldManTrader trader;
    u8 filler[0x40];
} OldMan;

struct RecordMixing_UnknownStructSub
{
    u32 unk0;
    u8 data[0x34];
    //u8 data[0x38];
};

struct RecordMixing_UnknownStruct
{
    struct RecordMixing_UnknownStructSub data[2];
    u32 unk70;
    u16 unk74[0x2];
};

struct LinkBattleRecord
{
    u8 name[8];
    u16 trainerId;
    u16 wins;
    u16 losses;
    u16 draws;
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
    u8 monName[11];
    u8 trainerName[8];
    u8 contestRank;
};

struct DaycareMon
{
    struct BoxPokemon mon;
    struct MailStruct mail;
    u8 OT_name[OT_NAME_LENGTH + 1];
    u8 monName[11];
    u8 language_maybe : 4;
    u8 unknown : 4;
    u32 stepsTaken;
};

struct DaycareData
{
    struct DaycareMon mons[2];
    u32 offspringPersonality;
    u8 stepCounter;
};

#define MAP_OBJECTS_COUNT  16
#define BERRY_TREES_COUNT  128
#define FLAGS_COUNT        300
#define VARS_COUNT         256

enum {
    LILYCOVE_LADY_QUIZ,
    LILYCOVE_LADY_FAVOUR,
    LILYCOVE_LADY_CONTEST
};

struct LilycoveLadyQuiz
{
    /*0x000*/ u8 id;
    /*0x001*/ u8 phase;
    /*0x002*/ u16 unk_002[9];
    /*0x014*/ u16 unk_014;
    /*0x016*/ u16 unk_016;
    /*0x018*/ u8 playerName[8];
    /*0x020*/ u16 playerTrainerId[4];
    /*0x028*/ u16 itemId;
    /*0x02a*/ u8 unk_02a;
    /*0x02b*/ u8 unk_02b;
    /*0x02c*/ u8 unk_02c;
    /*0x02d*/ u8 language;
};

struct LilycoveLadyFavour
{
    /*0x000*/ u8 id;
    /*0x001*/ u8 phase;
    /*0x002*/ u8 unk_002;
    /*0x003*/ u8 unk_003;
    /*0x004*/ u8 playerName[8];
    /*0x00c*/ u8 unk_00c;
    /*0x00e*/ u16 itemId;
    /*0x010*/ u16 unk_010;
    /*0x012*/ u8 language;
};

struct LilycoveLadyContest
{
    /*0x000*/ u8 id;
    /*0x001*/ u8 phase;
    /*0x002*/ u8 fave_pkblk;
    /*0x003*/ u8 other_pkblk;
    /*0x004*/ u8 playerName[8];
    /*0x00c*/ u8 max_sheen;
    /*0x00d*/ u8 category;
    /*0x00e*/ u8 language;
};

typedef union // TODO
{
    struct LilycoveLadyQuiz quiz;
    struct LilycoveLadyFavour favour;
    struct LilycoveLadyContest contest;
    u8 id;
} LilycoveLady;

struct WaldaPhrase
{
    u16 field_0;
    u16 field_2;
    u8 text[16];
    u8 iconId;
    u8 patternId;
    bool8 patternUnlocked;
};

struct SaveBlock1
{
    /*0x00*/ struct Coords16 pos;
    /*0x04*/ struct WarpData location;
    /*0x0C*/ struct WarpData warp1;
    /*0x14*/ struct WarpData warp2;
    /*0x1C*/ struct WarpData warp3;
    /*0x24*/ struct WarpData warp4;
    /*0x2C*/ u16 battleMusic;
    /*0x2E*/ u8 weather;
    /*0x2F*/ u8 filler_2F;
    /*0x30*/ u8 flashUsed;
    /*0x32*/ u16 mapDataId;
    /*0x34*/ u16 mapView[0x100];
    /*0x234*/ u8 playerPartyCount;
    /*0x238*/ struct Pokemon playerParty[6];
    /*0x490*/ u32 money;
    /*0x494*/ u16 coins;
    /*0x496*/ u16 registeredItem; // registered for use with SELECT button
    /*0x498*/ struct ItemSlot pcItems[50];
    /*0x560*/ struct ItemSlot bagPocket_Items[30];
    /*0x5D8*/ struct ItemSlot bagPocket_KeyItems[30];
    /*0x650*/ struct ItemSlot bagPocket_PokeBalls[16];
    /*0x690*/ struct ItemSlot bagPocket_TMHM[64];
    /*0x790*/ struct ItemSlot bagPocket_Berries[46];
    /*0x848*/ struct Pokeblock pokeblocks[40];
    /*0x988*/ u8 seen1[52];
    /*0x9BC*/ u16 berryBlenderRecords[3];
    /*0x9C2*/ u8 field_9C2[6];
    /*0x9C8*/ u16 trainerRematchStepCounter;
    /*0x9CA*/ u8 trainerRematches[100];
    /*0xA30*/ struct MapObject mapObjects[MAP_OBJECTS_COUNT];
    /*0xC70*/ struct MapObjectTemplate mapObjectTemplates[64];
    /*0x1270*/ u8 flags[FLAGS_COUNT];
    /*0x139C*/ u16 vars[VARS_COUNT];
    /*0x159C*/ u32 gameStats[NUM_GAME_STATS];
    /*0x169C*/ struct BerryTree berryTrees[BERRY_TREES_COUNT];
    /*0x1A9C*/ struct SecretBaseRecord secretBases[20];
    /*0x271C*/ u8 playerRoomDecor[12];
    /*0x2728*/ u8 playerRoomDecorPos[12];
    /*0x2734*/ u8 decorDesk[10];
    /*0x????*/ u8 decorChair[10];
    /*0x????*/ u8 decorPlant[10];
    /*0x????*/ u8 decorOrnament[30];
    /*0x????*/ u8 decorMat[30];
    /*0x????*/ u8 decorPoster[10];
    /*0x????*/ u8 decorDoll[40];
    /*0x????*/ u8 decorCushion[10];
    /*0x27CA*/ u8 padding_27CA[2];
    /*0x27CC*/ TVShow tvShows[25];
    /*0x2B50*/ PokeNews pokeNews[16];
    /*0x2B90*/ u16 outbreakPokemonSpecies;
    /*0x2B92*/ u8 outbreakLocationMapNum;
    /*0x2B93*/ u8 outbreakLocationMapGroup;
    /*0x2B94*/ u8 outbreakPokemonLevel;
    /*0x2B95*/ u8 outbreakUnk1;
    /*0x2B96*/ u16 outbreakUnk2;
    /*0x2B98*/ u16 outbreakPokemonMoves[4];
    /*0x2BA0*/ u8 outbreakUnk4;
    /*0x2BA1*/ u8 outbreakPokemonProbability;
    /*0x2BA2*/ u16 outbreakDaysLeft;
    /*0x2BA4*/ struct GabbyAndTyData gabbyAndTyData;
    /*0x2BB0*/ u16 unk2BB0[6];
    /*0x2BBC*/ u16 unk2BBC[6];
    /*0x2BC8*/ u16 unk2BC8[6];
    /*0x2BD4*/ u16 unk2BD4[3];
    /*0x2BE0*/ struct MailStruct mail[16];
    /*0x2E20*/ u8 additionalPhrases[5]; // bitfield for 33 additional phrases in easy chat system
    /*0x2E25*/ u8 unk2E25[3]; // possibly padding?
    /*0x2E28*/ OldMan oldMan;
    /*0x2e64*/ struct EasyChatPair easyChatPairs[5]; //Dewford trend [0] and some other stuff
    /*0x2e8c*/ u8 filler_2E8C[0x4];
    /*0x2e90*/ struct ContestWinner contestWinners[13]; // 0 - 5 used in contest hall, 6 - 7 unused?, 8 - 12 museum
    /*0x3030*/ struct DaycareData daycare;
    /*0x3150*/ struct LinkBattleRecord linkBattleRecords[5];
    /*0x31A0*/ u8 unk_31A0;
    /*0x31A1*/ u8 filler_31A1[7];
    /*0x31A8*/ u8 giftRibbons[52];
    /*0x31DC*/ struct Roamer roamer;
    /*0x31F8*/ struct EnigmaBerry enigmaBerry;
    /*0x322C*/ u8 field_322C[1276];
    /*0x3728*/ struct RamScript ramScript;
    /*0x3B14*/ struct RecordMixingGift recordMixingGift;
    /*0x3B24*/ u8 seen2[52];
    /*0x3B58*/ LilycoveLady lilycoveLady;
    /*0x3B88*/ u8 filler_3B88[0x1E8];
    /*0x3D70*/ struct WaldaPhrase waldaPhrase;
    // sizeof: 0x3D88
};

extern struct SaveBlock1* gSaveBlock1Ptr;

struct Bitmap           // TODO: Find a better spot for this
{
    u8* pixels;
    u32 width:16;
    u32 height:16;
};

extern u8 gReservedSpritePaletteCount;

#endif // GUARD_GLOBAL_H
