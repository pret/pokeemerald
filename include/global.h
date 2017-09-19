#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"
#include "config.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

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

struct SaveBlock2
{
    /*0x00*/ u8 playerName[8];
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

    /*0x64C*/ u8 field_64C[1629];
    /*0xCA9*/ u8 frontierChosenLvl : 2;
    /*0xCA9*/ u8 field_CA9_a : 6;
    /*0xCAA*/ u8 field_CAA[368];
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
    /*ID?*/ /*0x1A08*/ u8 sbr_field_0;
    /*0x1A09*/ u8 sbr_field_1_0:4;
    /*0x1A09*/ u8 gender:1;
    /*0x1A09*/ u8 sbr_field_1_5:1;
    /*0x1A09*/ u8 sbr_field_1_6:2;
    /*0x1A0A*/ u8 sbr_field_2[7]; // 0xFF bytes?
    /*0x1A12*/ u8 trainerId[4]; // byte 0 is used for determining trainer class
    /*0x1A16*/ u16 sbr_field_e;
    /*0x1A18*/ u8 sbr_field_10;
    /*0x1A19*/ u8 sbr_field_11;
    /*0x1A1A*/ u8 decorations[16];
    /*0x1A2A*/ u8 decorationPos[16];
    /*0x1A3A*/ u32 partyPersonality[6];
    /*0x1A54*/ u16 partyMoves[6 * 4];
    /*0x1A84*/ u16 partySpecies[6];
    /*0x1A90*/ u16 partyHeldItems[6];
    /*0x1A9C*/ u8 partyLevels[6];
    /*0x1AA2*/ u8 partyEVs[6];
};

#include "game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
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

struct TVShowCommon
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 pad02[20];
    /*0x16*/ u16 var16[3];
    /*0x1C*/ u8 srcTrainerId3Lo;
    /*0x1D*/ u8 srcTrainerId3Hi;
    /*0x1E*/ u8 srcTrainerId2Lo;
    /*0x1F*/ u8 srcTrainerId2Hi;
    /*0x20*/ u8 srcTrainerIdLo;
    /*0x21*/ u8 srcTrainerIdHi;
    /*0x22*/ u8 trainerIdLo;
    /*0x23*/ u8 trainerIdHi;
};

struct TVShowFanClubLetter
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 species;
    /*0x04*/ u16 pad04[6];
    /*0x10*/ u8 playerName[8];
    /*0x18*/ u8 language;
};

struct TVShowRecentHappenings
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 var02;
    /*0x04*/ u16 var04[6];
    /*0x10*/ u8 playerName[8];
    /*0x18*/ u8 language;
    /*0x19*/ u8 pad19[10];
};

struct TVShowFanclubOpinions
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 var02;
    /*0x04*/ u8 var04A:4;
    /*0x04*/ u8 var04B:4;
    /*0x05*/ u8 playerName[8];
    /*0x0D*/ u8 language;
    /*0x0E*/ u8 var0E;
    /*0x0F*/ u8 var0F;
    /*0x10*/ u8 var10[8];
    /*0x18*/ u16 var18[2];
    /*0x1C*/ u16 var1C[4];
};

struct TVShowUnknownType04
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 pad02[4];
    /*0x06*/ u16 var06;
};

struct TVShowNameRaterShow
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 species;
    /*0x04*/ u8 pokemonName[11];
    /*0x0F*/ u8 trainerName[11];
    /*0x1A*/ u8 random;
    /*0x1B*/ u8 random2;
    /*0x1C*/ u16 var1C;
    /*0x1E*/ u8 language;
    /*0x1F*/ u8 pokemonNameLanguage;
};

struct TVShowBravoTrainerPokemonProfiles
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 species;
    /*0x04*/ u16 var04[2];
    /*0x08*/ u8 pokemonNickname[11];
    /*0x13*/ u8 contestCategory:3;
    /*0x13*/ u8 contestRank:2;
    /*0x13*/ u8 contestResult:2;
    /*0x13*/ u8 var13_7:1;
    /*0x14*/ u16 var14;
    /*0x16*/ u8 playerName[8];
    /*0x1E*/ u8 language;
    /*0x1F*/ u8 var1f;
};

struct TVShowBravoTrainerBattleTowerSpotlight
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 trainerName[8];
    /*0x0A*/ u16 species;
    /*0x0C*/ u8 pokemonName[8];
    /*0x14*/ u16 defeatedSpecies;
    /*0x16*/ u16 var16;
    /*0x18*/ u16 var18[1];
    /*0x1A*/ u8 btLevel;
    /*0x1B*/ u8 var1b;
    /*0x1C*/ u8 var1c;
    /*0x1D*/ u8 language;
};

struct TVShowPokemonToday
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 language;
    /*0x03*/ u8 language2;
    /*0x04*/ u8 nickname[11];
    /*0x0F*/ u8 ball;
    /*0x10*/ u16 species;
    /*0x12*/ u8 var12;
    /*0x13*/ u8 playerName[8];
};

struct TVShowSmartShopper
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 priceReduced;
    /*0x03*/ u8 language;
    /*0x04*/ u8 pad04[2];
    /*0x06*/ u16 itemIds[3];
    /*0x0C*/ u16 itemAmounts[3];
    /*0x12*/ u8 shopLocation;
    /*0x13*/ u8 playerName[8];
};

struct TVShowPokemonTodayFailed
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 language;
    /*0x03*/ u8 pad03[9];
    /*0x0c*/ u16 species;
    /*0x0e*/ u16 species2;
    /*0x10*/ u8 var10;
    /*0x11*/ u8 var11;
    /*0x12*/ u8 var12;
    /*0x13*/ u8 playerName[8];
};

struct TVShowPokemonAngler
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 var02;
    /*0x03*/ u8 var03;
    /*0x04*/ u16 var04;
    /*0x06*/ u8 language;
             u8 pad07[12];
    /*0x13*/ u8 playerName[8];
};

struct TVShowWorldOfMasters
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u16 var02;
    /*0x04*/ u16 var04;
    /*0x06*/ u16 var06;
    /*0x08*/ u16 var08;
    /*0x0a*/ u8 var0a;
    /*0x0b*/ u8 language;
             u8 pad0c[7];
    /*0x13*/ u8 playerName[8];
};

struct TVShowMassOutbreak
{
    /*0x00*/ u8 var00;
    /*0x01*/ u8 var01;
    /*0x02*/ u8 var02;
    /*0x03*/ u8 var03;
    /*0x04*/ u16 moves[4];
    /*0x0C*/ u16 species;
    /*0x0E*/ u16 var0E;
    /*0x10*/ u8 locationMapNum;
    /*0x11*/ u8 locationMapGroup;
    /*0x12*/ u8 var12;
    /*0x13*/ u8 probability;
    /*0x14*/ u8 level;
    /*0x15*/ u8 var15;
    /*0x16*/ u16 var16;
    /*0x18*/ u8 language;
             u8 pad19[11];
};

typedef union TVShow
{
    struct TVShowCommon common;
    struct TVShowFanClubLetter fanclubLetter;
    struct TVShowRecentHappenings recentHappenings;
    struct TVShowFanclubOpinions fanclubOpinions;
    struct TVShowUnknownType04 unkShow04;
    struct TVShowNameRaterShow nameRaterShow;
    struct TVShowBravoTrainerPokemonProfiles bravoTrainer;
    struct TVShowBravoTrainerBattleTowerSpotlight bravoTrainerTower;
    struct TVShowPokemonToday pokemonToday;
    struct TVShowSmartShopper smartshopperShow;
    struct TVShowPokemonTodayFailed pokemonTodayFailed;
    struct TVShowPokemonAngler pokemonAngler;
    struct TVShowWorldOfMasters worldOfMasters;
    struct TVShowMassOutbreak massOutbreak;
} TVShow;

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

struct UnknownSaveStruct2ABC
{
    u8 val0;
    u8 val1;
    u16 val2;
};

struct GabbyAndTyData
{
    /*2b10*/ u16 mon1;
    /*2b12*/ u16 mon2;
    /*2b14*/ u16 lastMove;
    /*2b16*/ u16 quote;
    /*2b18*/ u8 mapnum;
    /*2b19*/ u8 battleNum;
    /*2b1a*/ u8 valA_0:1;
    /*2b1a*/ u8 valA_1:1;
    /*2b1a*/ u8 valA_2:1;
    /*2b1a*/ u8 valA_3:1;
    /*2b1a*/ u8 valA_4:1;
    /*2b1a*/ u8 valA_5:3;
    /*2b1b*/ u8 valB_0:1;
    /*2b1b*/ u8 valB_1:1;
    /*2b1b*/ u8 valB_2:1;
    /*2b1b*/ u8 valB_3:1;
    /*2b1b*/ u8 valB_4:1;
    /*2b1b*/ u8 valB_5:3;
};

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
    u8 language;
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

typedef union // TODO
{
    struct
    {
        /*0x000*/ u8 id;
        /*0x001*/ u8 language;
    } quiz;

    struct
    {
        /*0x000*/ u8 id;
    } flavor;

    struct
    {
        /*0x000*/ u8 id;
        /*0x001*/ u8 filler_001[12];
        /*0x00d*/ u8 category; // maybe?
    } contest;

    struct
    {
        /*0x000*/ u8 id;
        /*0x001*/ u8 filler_001[535];
    } common;
} LilycoveLady;

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
    /*0x2B50*/ struct UnknownSaveStruct2ABC pokeNews[16];
    /*0x2B90*/ u16 outbreakPokemonSpecies;
    /*0x????*/ u8 outbreakLocationMapNum;
    /*0x????*/ u8 outbreakLocationMapGroup;
    /*0x????*/ u8 outbreakPokemonLevel;
    /*0x????*/ u8 outbreakUnk1;
    /*0x????*/ u16 outbreakUnk2;
    /*0x????*/ u16 outbreakPokemonMoves[4];
    /*0x????*/ u8 outbreakUnk4;
    /*0x????*/ u8 outbreakPokemonProbability;
    /*0x????*/ u16 outbreakUnk5;
    /*0x2BA4*/ struct GabbyAndTyData gabbyAndTyData;
    /*0x????*/ u16 unk2B1C[6];
    /*0x????*/ u16 unk2B28[6];
    /*0x????*/ u16 unk2B34[6];
    /*0x????*/ u16 unk2B3A[3];
    /*0x2BE0*/ struct MailStruct mail[16];
    /*0x2E20*/ u8 additionalPhrases[5]; // bitfield for 33 additional phrases in easy chat system
    /*0x2E25*/ u8 unk2E25[3]; // possibly padding?
    /*0x2E28*/ OldMan oldMan;
    /*0x2e64*/ struct EasyChatPair easyChatPairs[5]; //Dewford trend [0] and some other stuff
    /*0x2e8c*/ u8 filler_2E8C[0x4];
    /*0x2e90*/ struct ContestWinner contestWinners[13]; // 0 - 5 used in contest hall, 6 - 7 unused?, 8 - 12 museum
    /*0x3030*/ struct DaycareData daycare;
    /*0x3150*/ struct LinkBattleRecord linkBattleRecords[5];
    /*0x31A0*/ u8 filler_31A0[8];
    /*0x31A8*/ u8 giftRibbons[52];
    /*0x31DC*/ struct Roamer roamer;
    /*0x31F8*/ struct EnigmaBerry enigmaBerry;
    /*0x322C*/ u8 field_322C[1276];
    /*0x3728*/ struct RamScript ramScript;
    /*0x3B14*/ struct RecordMixingGift recordMixingGift;
    /*0x3B24*/ u8 seen2[52];
    /*0x3B58*/ LilycoveLady lilycoveLady; // TODO: convert to a union
    /*0x3D70*/ u8 babyPhrase[24]; // TODO: convert to a struct
    // sizeof: 0x3D88
};

extern struct SaveBlock1* gSaveBlock1Ptr;

struct Bitmap           // TODO: Find a better spot for this
{
    u8* pixels;
    u32 width:16;
    u32 height:16;
};

#endif // GUARD_GLOBAL_H
