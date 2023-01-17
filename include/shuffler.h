#ifndef GUARD_SHUFFLER_H
#define GUARD_SHUFFLER_H

#include "data.h"
#include "trade.h"

#define MAX_OBJECTS 10
#define POSSIBLE_STARTERS 108
#define POSSIBLE_HEALING_ITEMS 16
#define POSSIBLE_TMS 50
#define POSSIBLE_MISC_ITEMS 49
#define POSSIBLE_WILD_MON 350
#define POSSIBLE_WILD_MON_LEGENDARY 82
#define WILD_LEGEND_ODDS 512
#define POSSIBLE_NPCS 3
#define POSSIBLE_WITCH_ITEM_REWARDS 1
#define POSSIBLE_WITCH_EFFECTS 1
#define POSSIBLE_WITCH_REWARD_TYPES 1
#define ROOMS_PER_SET 15
#define TOTAL_WARPS ROOMS_PER_SET + 1
#define MAT1 0x8f7011ee
#define MAT2 0xfc78ff1f
#define TMAT 0x3793fdff

#define EVO_STRAT_DO_NOT 1
#define EVO_STRAT_NO_BELLOSSOM 2
#define EVO_STRAT_NO_MAROWAK_ALOLAN 3
#define EVO_STRAT_NO_EXEGGUTOR_ALOLAN 4
#define EVO_STRAT_NO_GALLADE 5
#define EVO_STRAT_NO_MR_MIME_GALARIAN 6
#define EVO_STRAT_WILD 7
#define EVO_STRAT_NO_VILEPLUME 8

struct PokemonTemplate {
    u16 species;
    u8 minLevel;
    u8 maxLevel;
    u16 moves[MAX_MON_MOVES];
    u16 heldItem;
    u16 iv;
    u8 weight;
    u8 evoStrat;
};

struct TrainerTemplate {
    u8 trainerClass; // No longer used for displaying class name but still controls the transition animation and some music.
    u8 encounterMusic_gender;
    u8 trainerPic;
    const u8* trainerName;
    u8 partySize;
    u8 poolSize;
    
    struct PokemonTemplate* party;

    const u8* introText;
    const u8* defeatText;
    const u8* postbattleText;
    u16 graphicsId;
};

union TrainerMonParty {
    struct TrainerMonNoItemDefaultMoves NoItemDefaultMoves[6];
    struct TrainerMonNoItemCustomMoves NoItemCustomMoves[6];
    struct TrainerMonItemDefaultMoves ItemDefaultMoves[6];
    struct TrainerMonItemCustomMoves ItemCustomMoves[6];
};

struct WildMon {
    u8 type;
    union {
        struct TrainerMonNoItemDefaultMoves NoItemDefaultMoves;
        struct TrainerMonNoItemCustomMoves NoItemCustomMoves;
        struct TrainerMonItemDefaultMoves ItemDefaultMoves;
        struct TrainerMonItemCustomMoves ItemCustomMoves;
    };
};

struct ShuffledTrainerInfo {
    struct Trainer trainer;
    struct TrainerMonItemCustomMoves party[6];
    const u8* introText;
    const u8* defeatText;
    const u8* postbattleText;
    const u8* name;
};

struct NPCTraderInfo {
    struct InGameTrade igt;
};

struct NPCWitchItemReward {
    u16 item;
    u16 quantity;
};

struct NPCWitchInfo {
    u8 effect;
    u8 rewardType;
    u32 seed;
    const u8* effectText;
    const u8* rewardText;
    union {
        struct NPCWitchItemReward itemReward;
    };
};

struct NPCInfo {
    u8 type;
    union {
        struct NPCTraderInfo trader;
        struct NPCWitchInfo witch;
    };
};

union ShuffledObject {
    struct ShuffledTrainerInfo t;
    struct WildMon wm;
    u16 itemId;
    struct NPCInfo npc;
};

extern u16 realStarterMon[6];

void Shuffle(u32 s);
void DeclareTrainer(u8 objNum, u8 trainerType, u8 partnerObjNum);
const u8 *GetAdjustedTrainerIntroText(u16 objNum);
const u8 *GetAdjustedTrainerDefeatText(u16 objNum);
const u8 *GetAdjustedTrainerName(u16 index);
const u8 *GetAdjustedTrainerPostbattleText(u8 objNum);
const struct Trainer *RedirectTrainer(u16 index);
void DeclareWildMon(u8 objNum);
u8 GetAdjustedWildMonLevel(u8 objNum);
u16 GetAdjustedWildMonSpecies(u8 objNum);
void NotifyShufflerChangedRoom();
void RedirectShuffledWarp(struct WarpData *warp);
void DeclareItem(u16 objNum);
u16 AdjustItem(u16 index);
u16 GetShuffledNPCType(void);
struct InGameTrade* GetShuffledInGameTrade(u16 index);
u16 GetNPCFlag(void);
u16 SetNPCFlag(void);
u16 ClearNPCFlag(void);
void DeclareNPC(u16 objNum, u8 npcType);
u16 DoWitchDeal(void);
u16 BufferWitchText(void);
u16 ShuffledFlagNumberByObjectEventId(u16 objNum);
u8 GetScaledLevel(u8 distance);
u16 AdjustSpecies(u16 species, u8 level, int evoStrat);

#endif // GUARD_SHUFFLER_H
