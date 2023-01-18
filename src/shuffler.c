#include "global.h"

#include "shuffler.h"
#include "tinymt32.h"
#include "data.h"
#include "global.fieldmap.h"

#include "random.h"
#include "battle_setup.h"
#include "item.h"
#include "event_data.h"
#include "string_util.h"

#include "constants/battle.h"
#include "constants/battle_ai.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/trainers.h"

#include "data/shuffle_trainers.h"
#include "data/shuffle_starters.h"
#include "data/shuffle_rooms.h"
#include "data/shuffle_items.h"
#include "data/shuffle_wildmon.h"

#ifdef __wasm__
#define MYLOG(f_, ...) printf("GBA: "); printf((f_), ##__VA_ARGS__); printf("\n")
#else
#include "printf.h"
#include "mgba.h"
#define MYLOG(f_, ...) mgba_printf(MGBA_LOG_INFO, (f_), ##__VA_ARGS__)
#endif

extern struct Evolution gEvolutionTable[][EVOS_PER_MON];
extern u32 GetTotalBaseStat(u32 species);

EWRAM_DATA int seed;
EWRAM_DATA tinymt32_t currentRoomSeed;
EWRAM_DATA u16 realStarterMon[6];

EWRAM_DATA struct MapEvents AdjustedMapEvents;
EWRAM_DATA struct ObjectEventTemplate AdjustedTemplates[MAX_OBJECTS];
EWRAM_DATA u16 CurrentAdjustedRoom = 0xFFFF;
EWRAM_DATA u8 CurrentAdjustedRoomIndex;

EWRAM_DATA u16 AdjustedObjectsDirty = 0xFFFF; 
EWRAM_DATA u16 RedirectedTrainerFlags = 0;
EWRAM_DATA union ShuffledObject AdjustedObjects[MAX_OBJECTS];

EWRAM_DATA struct WarpData realWarps[TOTAL_WARPS] = {};
EWRAM_DATA u8 distance = 0;
EWRAM_DATA u16 lastRoom = 0;

void Shuffle(u32 s) {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    seed = s;
    tinymt32_init(&tinymt, seed);
    MYLOG("seed: %u", seed);

    int r;
    for (int i = 0; i < ROOMS_PER_SET; i++) {
        // burn RNs for room seeds.
        r = tinymt32_generate_uint32(&tinymt); 
    }

    for (int i = 0; i < 6; ) {
        r = tinymt32_generate_uint32(&tinymt) % POSSIBLE_STARTERS;
        int cont = 0;
        for (int j = 0; j < i; j++) {
            if (realStarterMon[j] == possibleStarters[r]) {
                cont = 1;
                break;
            }
        }
        if (cont == 1) {
            continue;
        }
        realStarterMon[i] = possibleStarters[r];
        i++;
    }

    int normals[TOTAL_NORMAL_ROOMS];
    int gyms[TOTAL_GYM_ROOMS];
    int elites[TOTAL_ELITE_ROOMS];
    int normalIdx = 0;
    int gymIdx = 0;
    int eliteIdx = 0;

    // this is basically always going to be TOTAL_NORMAL_ROOMS
    // but just in case it ever isn't, we check here.
    // it should all get optimized out by the compiler anyway.
    int max = TOTAL_NORMAL_ROOMS;
    if (TOTAL_GYM_ROOMS > max) {
        max = TOTAL_GYM_ROOMS;
    }
    if (TOTAL_ELITE_ROOMS > max) {
        max = TOTAL_ELITE_ROOMS;
    }

    for (int j = 0; j < max; j++) {
        if (j < TOTAL_NORMAL_ROOMS) {
            normals[j] = j;
        }
        if (j < TOTAL_GYM_ROOMS) {
            gyms[j] = j;
        }
        if (j < TOTAL_ELITE_ROOMS) {
            elites[j] = j;
        }
    }

    for (int j = max - 1; j > 0; j--) {
        int t;
        if (j < TOTAL_NORMAL_ROOMS) {
            r = tinymt32_generate_uint32(&tinymt) % (j + 1);
            t = normals[r];
            normals[r] = normals[j];
            normals[j] = t;
        }
        if (j < TOTAL_GYM_ROOMS) {
            r = tinymt32_generate_uint32(&tinymt) % (j + 1);
            t = gyms[r];
            gyms[r] = gyms[j];
            gyms[j] = t;
        }
        if (j < TOTAL_ELITE_ROOMS) {
            r = tinymt32_generate_uint32(&tinymt) % (j + 1);
            t = elites[r];
            elites[r] = elites[j];
            elites[j] = t;
        }
    }

    for (int j = 0; j <= ROOMS_PER_SET; j++) {
        u8 roomGroup, roomId;
        if (j == ROOMS_PER_SET) {
            roomGroup = EndRooms[0] >> 8;
            roomId = EndRooms[0] & 0xFF;
        } else if (j <= 4 || (j >= 7 && j <= 11)) {
            roomGroup = NormalRooms[normals[normalIdx]] >> 8;
            roomId = NormalRooms[normals[normalIdx]] & 0xFF;
            normalIdx++;
        } else if (j == 5 || j == 12) {
            roomGroup = GymRooms[gyms[gymIdx]] >> 8;
            roomId = GymRooms[gyms[gymIdx]] & 0xFF;
            gymIdx++;
        } else if (j == 6 || j == 13) {
            roomGroup = PostGymRooms[0] >> 8;
            roomId = PostGymRooms[0] & 0xFF;
        } else if (j == 14) {
            roomGroup = EliteRooms[elites[eliteIdx]] >> 8;
            roomId = EliteRooms[elites[eliteIdx]] & 0xFF;
            eliteIdx++;
        }
        realWarps[j] = (struct WarpData){roomGroup, roomId, 0, -1, -1};
    }

    for (int i = 0; i < 5; i++) {
        r = tinymt32_generate_uint32(&tinymt) % 50;
        AddBagItem(ITEM_TM01 + r, 1);
    }

    AddBagItem(ITEM_SITRUS_BERRY, 5);
    AddBagItem(ITEM_LEPPA_BERRY, 5);

    AddBagItem(ITEM_POKE_BALL, 8);
    AddBagItem(ITEM_GREAT_BALL, 4);
    AddBagItem(ITEM_ULTRA_BALL, 2);
    AddBagItem(ITEM_MASTER_BALL, 1);
}

void SetCurrentRoomSeed() {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    tinymt32_init(&tinymt, seed);
    int seed2;
    // burn an appropriate amount of RNs here.
    for (int i = 0; i < distance; i++) {
        seed2 = tinymt32_generate_uint32(&tinymt);
    }
    currentRoomSeed.mat1 = MAT1;
    currentRoomSeed.mat2 = MAT2;
    currentRoomSeed.tmat = TMAT;
    tinymt32_init(&currentRoomSeed, seed2);
}

void MirrorMapData() {
    u16 currentRoom = gSaveBlock1Ptr->location.mapNum | (gSaveBlock1Ptr->location.mapGroup << 8);
    if (CurrentAdjustedRoom != currentRoom) {
        CurrentAdjustedRoom = currentRoom;
        AdjustedObjectsDirty = 0xFFFF;
        RedirectedTrainerFlags = 0;
        distance++;
        MYLOG("distance: %u", distance);
        SetCurrentRoomSeed();

        size_t mapevents_bytes = sizeof(struct MapEvents);
        memcpy(&AdjustedMapEvents, gMapHeader.events, mapevents_bytes);
        
        u8 num_objs = AdjustedMapEvents.objectEventCount;
        if (num_objs > MAX_OBJECTS) {
            MYLOG("num_objs > MAX_OBJECTS, shit is broken: %d", num_objs);
        } else {
            size_t objs_bytes = num_objs * sizeof(struct ObjectEventTemplate);
            memcpy(&AdjustedTemplates, AdjustedMapEvents.objectEvents, objs_bytes);
            AdjustedMapEvents.objectEvents = &AdjustedTemplates[0];
        }
    }

    gMapHeader.events = &AdjustedMapEvents;
}

void DeclareTrainer(u8 objNum, u8 trainerType, u8 partnerObjNum) {
    MirrorMapData();
    AdjustedObjectsDirty ^= (1 << objNum);

    int i = tinymt32_generate_uint32(&currentRoomSeed) % allTrainersCount[trainerType];

    const struct TrainerTemplate *tt = allTrainers[trainerType][i];

    AdjustedObjects[objNum].t.trainer.aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
    AdjustedObjects[objNum].t.trainer.doubleBattle = FALSE;
    AdjustedObjects[objNum].t.trainer.encounterMusic_gender = tt->encounterMusic_gender;
    AdjustedObjects[objNum].t.trainer.trainerClass = tt->trainerClass;
    AdjustedObjects[objNum].t.trainer.trainerPic = tt->trainerPic;
    for (int j = 0; j < 4; j++) {
        AdjustedObjects[objNum].t.trainer.items[j] = ITEM_NONE;
    }

    AdjustedObjects[objNum].t.trainer.partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM;
    AdjustedObjects[objNum].t.trainer.partySize = tt->partySize;

    int poolSize = tt->poolSize;
    int pool[poolSize];
    int nextIndex = 0;
    u8 level = GetScaledLevel(distance);
    for (int j = 0; j < tt->poolSize; j++) {
        if ((tt->party[j].minLevel != 0 && level < tt->party[j].minLevel) || (tt->party[j].maxLevel != 0 && level > tt->party[j].maxLevel)) {
            poolSize--;
            continue;
        }
        pool[nextIndex] = j;
        nextIndex++;
    }
    for (int j = poolSize - 1; j > 0; j--) {
        int k = tinymt32_generate_uint32(&currentRoomSeed) % (j + 1);
        int tmp = pool[j];
        pool[j] = pool[k];
        pool[k] = tmp;
    }

    for (int j = 0; j < tt->partySize; j++) {
        AdjustedObjects[objNum].t.party[j].iv = 0;
        AdjustedObjects[objNum].t.party[j].lvl = level;
        AdjustedObjects[objNum].t.party[j].species =
            AdjustSpecies(tt->party[pool[j]].species, level, tt->party[pool[j]].evoStrat);
        AdjustedObjects[objNum].t.party[j].heldItem =
            tt->party[pool[j]].heldItem;
        if (tt->party[j].moves[0] == 0) {
            for (int k = 0; k < 4; k++) {
                AdjustedObjects[objNum].t.party[j].moves[k] = 0xFFFF;
            }
        } else {
            for (int k = 0; k < 4; k++) {
                AdjustedObjects[objNum].t.party[j].moves[k] = tt->party[pool[j]].moves[k];
            }
        }
    }
    AdjustedObjects[objNum].t.trainer.party.ItemCustomMoves = AdjustedObjects[objNum].t.party;

    AdjustedObjects[objNum].t.defeatText = tt->defeatText;
    AdjustedObjects[objNum].t.introText = tt->introText;
    AdjustedObjects[objNum].t.postbattleText = tt->postbattleText;
    AdjustedObjects[objNum].t.name = tt->trainerName;
    AdjustedTemplates[objNum].graphicsId = tt->graphicsId;
    AdjustedTemplates[objNum].flagId = ShuffledFlagNumberByObjectEventId(objNum + 1);

    if (partnerObjNum != 0xFF && (AdjustedObjectsDirty & (1 << partnerObjNum)) == 0) {
        // combine the parties
        int partySizeA = AdjustedObjects[objNum].t.trainer.partySize >> 1;
        if (partySizeA < 1) {
            partySizeA = 1;
        } else if (partySizeA > 3) {
            partySizeA = 3;
        }
        int partySizeB = AdjustedObjects[partnerObjNum].t.trainer.partySize >> 1;
        if (partySizeB < 1) {
            partySizeB = 1;
        } else if (partySizeB > 3) {
            partySizeB = 3;
        }

        int copyDestIndex;
        if (partySizeA == 3) {
            if (partySizeB == 1) {
                copyDestIndex = 3;
            } else {
                copyDestIndex = 4;
            }
            memcpy(&AdjustedObjects[objNum].t.party[copyDestIndex], &AdjustedObjects[objNum].t.party[2], sizeof(struct TrainerMonItemCustomMoves));
        }
        
        if (partySizeA >= 2) {
            memcpy(&AdjustedObjects[objNum].t.party[2], &AdjustedObjects[objNum].t.party[1], sizeof(struct TrainerMonItemCustomMoves));
        }

        if (partySizeB == 3) {
            memcpy(&AdjustedObjects[objNum].t.party[partySizeA + 2], &AdjustedObjects[partnerObjNum].t.party[2], sizeof(struct TrainerMonItemCustomMoves));
        }

        if (partySizeB >= 2) {
            if (partySizeA == 1) {
                copyDestIndex = 2;
            } else {
                copyDestIndex = 3;
            }
            memcpy(&AdjustedObjects[objNum].t.party[copyDestIndex], &AdjustedObjects[partnerObjNum].t.party[1], sizeof(struct TrainerMonItemCustomMoves));
        }

        memcpy(&AdjustedObjects[objNum].t.party[1], &AdjustedObjects[partnerObjNum].t.party[0], sizeof(struct TrainerMonItemCustomMoves));

        // copy relevant data
        AdjustedObjects[partnerObjNum].t.trainer.party.ItemCustomMoves = AdjustedObjects[objNum].t.party;

        AdjustedObjects[objNum].t.trainer.partySize = partySizeA + partySizeB;
        AdjustedObjects[partnerObjNum].t.trainer.partySize = partySizeA + partySizeB;

        AdjustedObjects[objNum].t.trainer.doubleBattle = TRUE;
        AdjustedObjects[partnerObjNum].t.trainer.doubleBattle = TRUE;

        RedirectedTrainerFlags |= 1 << partnerObjNum;
        MYLOG("DeclareTrainer RedirectedTrainerFlags: %d", RedirectedTrainerFlags);
        AdjustedTemplates[partnerObjNum].flagId = AdjustedTemplates[objNum].flagId;
    }
}

void DeclareWildMon(u8 objNum) {
    MirrorMapData();
    AdjustedObjectsDirty ^= (1 << objNum);
    int i;
    if (WILD_LEGEND_ODDS == 0) {
        i = 1;
    } else {
        i = tinymt32_generate_uint32(&currentRoomSeed) % WILD_LEGEND_ODDS;
    }
    u16 species;
    if (i == 0) {
        i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_WILD_MON_LEGENDARY;
        species = possibleWildLegends[i];
    } else {
        i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_WILD_MON;
        species = possibleWildMon[i];
    }
    u8 level = GetScaledLevel(distance);
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.iv = 15;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.lvl = level;
    u16 adjustedSpecies = AdjustSpecies(species, level, EVO_STRAT_WILD);
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.species = adjustedSpecies;
    AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_POKEMON_001 + AdjustedObjects[objNum].wm.NoItemDefaultMoves.species - 1;
    AdjustedTemplates[objNum].flagId = ShuffledFlagNumberByObjectEventId(objNum + 1);
}

void DeclareItem(u16 objNum) {
    MirrorMapData();
    AdjustedObjectsDirty ^= (1 << objNum);
    int i = tinymt32_generate_uint32(&currentRoomSeed) % 6;
    switch (i) {
    case 0:
    case 1:
    case 2:
        AdjustedObjects[objNum].itemId = possibleHealingItems[tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_HEALING_ITEMS];
        AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_ITEM_BALL_GREEN;
        break;
    case 3:
        AdjustedObjects[objNum].itemId = possibleMiscItems[tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_MISC_ITEMS];
        AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_ITEM_BALL_PURPLE;
        break;
    case 4:
    case 5:
        AdjustedObjects[objNum].itemId = possibleTMs[tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_TMS];
        AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_ITEM_BALL;
        break;
    default:
        MYLOG("error randomizing an item ball.");
        break;
    }
    AdjustedTemplates[objNum].flagId = ShuffledFlagNumberByObjectEventId(objNum + 1);
}

static const u8 nickname[] = _("SHITASS");
static const u8 traderName[] = _("TRADER JOE");

static const u8 witchEffectText0[] = _("poison all your pokemon");
static const u8 witchRewardText0[] = _("5 rare candies");
static const u8* const witchEffectTexts[POSSIBLE_WITCH_EFFECTS] = {
    witchEffectText0
};
static const u16 witchItemRewards[POSSIBLE_WITCH_ITEM_REWARDS] = {
    ITEM_RARE_CANDY
};
static const u16 witchItemQuantities[POSSIBLE_WITCH_ITEM_REWARDS] = {
    5
};
static const u8* const witchItemRewardTexts[POSSIBLE_WITCH_ITEM_REWARDS] = {
    witchRewardText0
};
void DeclareNPC(u16 objNum, u8 npcType) {
    MirrorMapData();
    AdjustedObjectsDirty ^= (1 << objNum);
    int i = npcType;
    if (npcType == 0) {
        i = (tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_NPCS) + 1;
    }
    AdjustedObjects[objNum].npc.type = i;
    switch(i) {
    case 1: // Trader
        memcpy(AdjustedObjects[objNum].npc.trader.igt.nickname, nickname, sizeof(nickname));
        memcpy(AdjustedObjects[objNum].npc.trader.igt.otName, traderName, sizeof(traderName));
        AdjustedObjects[objNum].npc.trader.igt.species = tinymt32_generate_uint32(&currentRoomSeed) % 809;
        AdjustedObjects[objNum].npc.trader.igt.ivs[0] = 15;
        AdjustedObjects[objNum].npc.trader.igt.ivs[1] = 15;
        AdjustedObjects[objNum].npc.trader.igt.ivs[2] = 15;
        AdjustedObjects[objNum].npc.trader.igt.ivs[3] = 15;
        AdjustedObjects[objNum].npc.trader.igt.ivs[4] = 15;
        AdjustedObjects[objNum].npc.trader.igt.ivs[5] = 15;
        AdjustedObjects[objNum].npc.trader.igt.abilityNum = 0;
        AdjustedObjects[objNum].npc.trader.igt.otId = 42069;
        AdjustedObjects[objNum].npc.trader.igt.conditions[0] = 30;
        AdjustedObjects[objNum].npc.trader.igt.conditions[1] = 5;
        AdjustedObjects[objNum].npc.trader.igt.conditions[2] = 5;
        AdjustedObjects[objNum].npc.trader.igt.conditions[3] = 5;
        AdjustedObjects[objNum].npc.trader.igt.conditions[4] = 5;
        AdjustedObjects[objNum].npc.trader.igt.personality = 0x84;
        AdjustedObjects[objNum].npc.trader.igt.heldItem = possibleHealingItems[tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_HEALING_ITEMS];
        AdjustedObjects[objNum].npc.trader.igt.mailNum = -1;
        AdjustedObjects[objNum].npc.trader.igt.otGender = MALE;
        AdjustedObjects[objNum].npc.trader.igt.sheen = 10;
        AdjustedObjects[objNum].npc.trader.igt.requestedSpecies = 0;
        u8 type = tinymt32_generate_uint32(&currentRoomSeed) % 18;
        if (type >= TYPE_MYSTERY) {
            type++;
        }
        AdjustedObjects[objNum].npc.trader.igt.requestedType = type;
        AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_CAMPER;
        break;
    case 2: // healer
        AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_NURSE;
        break;
    case 3: // witch
        i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_WITCH_EFFECTS;
        AdjustedObjects[objNum].npc.witch.effect = i;
        AdjustedObjects[objNum].npc.witch.effectText = witchEffectTexts[i];

        i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_WITCH_REWARD_TYPES;
        AdjustedObjects[objNum].npc.witch.rewardType = i;
        switch (i) {
        case 0: // item reward
            i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_WITCH_ITEM_REWARDS;
            AdjustedObjects[objNum].npc.witch.itemReward.item = witchItemRewards[i];
            AdjustedObjects[objNum].npc.witch.itemReward.quantity = witchItemQuantities[i];
            AdjustedObjects[objNum].npc.witch.rewardText = witchItemRewardTexts[i];
            break;
        default:
            MYLOG("witch reward error! %d", i);
            break;
        }
        AdjustedObjects[objNum].npc.witch.seed = tinymt32_generate_uint32(&currentRoomSeed);
        AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_LEAF; // replace with something more witchy
        break;
    default: // unknown
        MYLOG("unknown NPC!");
        break;
    }
    AdjustedTemplates[objNum].flagId = ShuffledFlagNumberByObjectEventId(objNum + 1);
}

const u8 *GetAdjustedTrainerIntroText(u16 objNum) {
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.introText;
    }
    return unknown_string;
}

const u8 *GetAdjustedTrainerDefeatText(u16 objNum) {
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.defeatText;
    }
    return unknown_string;
}

const u8 *GetAdjustedTrainerName(u16 index) {
    u16 objNum = index - 1;
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.name;
    }
    return unknown_string;
}

const u8 *GetAdjustedTrainerPostbattleText(u8 objNum) {
    if (objNum < MAX_OBJECTS) {
        return AdjustedObjects[objNum].t.postbattleText;
    }
    return unknown_string;
}

const struct Trainer *RedirectTrainer(u16 index) {
    u16 objNum = index - 1;
    if (objNum < MAX_OBJECTS) {
        return &AdjustedObjects[objNum].t.trainer;
    }
    return &gTrainers[index];
}

u8 GetAdjustedWildMonLevel(u8 objNum) {
    return AdjustedObjects[objNum].wm.NoItemDefaultMoves.lvl;
}

u16 GetAdjustedWildMonSpecies(u8 objNum) {
    return AdjustedObjects[objNum].wm.NoItemDefaultMoves.species;
}

void NotifyShufflerChangedRoom() {
    CurrentAdjustedRoom = -1;
    CurrentAdjustedRoomIndex = -1;
    // When a pokemon encounter happens, AI data from the last trainer faced is read.
    // If we've switched rooms since fighting a trainer, this could be an invalid value,
    // so just 0 it out here.
    // I don't actually know if the AI flags are used or not during the wild battle.
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
}

void RedirectShuffledWarp(struct WarpData *warp) {
    // We skip the first warp redirects.
    // The first warp places the player in the start room.
    static int warpSkips = 0;
    if (warpSkips < 1) {
        warpSkips++;
        return;
    }
    if (warp->mapGroup == 0 && warp->mapNum == 0 && warp->warpId == 0 && warp->x == 0 && warp->y == 0) {
        MYLOG("white out warp");
        return;
    }
    int leavingDirection = warp->warpId;
    struct WarpData w = realWarps[distance];
    warp->mapGroup = w.mapGroup;
    warp->mapNum = w.mapNum;
    warp->warpId = w.warpId;
    warp->x = w.x;
    warp->y = w.y;
}

u16 AdjustItem(u16 index) {
    u16 objNum = index - 1;
    return AdjustedObjects[objNum].itemId;
}

u16 GetShuffledNPCType(void) {
    u16 objNum = gSpecialVar_0x8008 - 1;
    return AdjustedObjects[objNum].npc.type;
}

struct InGameTrade* GetShuffledInGameTrade(u16 index) {
    u16 objNum = index - 1;
    return &AdjustedObjects[objNum].npc.trader.igt;
}

u16 GetNPCFlag(void) {
    u16 objNum = gSpecialVar_0x8008 - 1;
    u16 flagId = AdjustedTemplates[objNum].flagId;
    return FlagGet(flagId);
}

u16 SetNPCFlag(void) {
    u16 objNum = gSpecialVar_0x8008 - 1;
    u16 flagId = AdjustedTemplates[objNum].flagId;
    if (FlagSet(flagId) != 0 || FlagGet(flagId) != 1) {
        MYLOG("NPC Flag wasn't set properly! %X", flagId);
    }
    return 1;
}

u16 ClearNPCFlag(void) {
    u16 objNum = gSpecialVar_0x8008 - 1;
    u16 flagId = AdjustedTemplates[objNum].flagId;
    if (FlagClear(flagId) != 0 || FlagGet(flagId) != 0) {
        MYLOG("NPC Flag wasn't cleared properly! %X", flagId);
    }
    return 0;
}

u16 DoWitchDeal(void) {
    u16 objNum = gSpecialVar_0x8008 - 1;

    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    tinymt32_init(&tinymt, AdjustedObjects[objNum].npc.witch.seed);

    bool8 broke = FALSE;
    int status = STATUS1_POISON;
    for (int i = 0; i < gPlayerPartyCount; i++) {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) && gPlayerParty[i].hp > 0) {
            SetMonData(&gPlayerParty[i], MON_DATA_STATUS, &status);
        }
    }

    AddBagItem(AdjustedObjects[objNum].npc.witch.itemReward.item, AdjustedObjects[objNum].npc.witch.itemReward.quantity);
}

u16 BufferWitchText(void) {
    u16 objNum = gSpecialVar_0x8008 - 1;
    StringCopy(gStringVar1, AdjustedObjects[objNum].npc.witch.effectText);
    StringCopy(gStringVar2, AdjustedObjects[objNum].npc.witch.rewardText);
}

u16 ShuffledFlagNumberByObjectEventId(u16 objNum) {
    if (RedirectedTrainerFlags & (1 << (objNum - 1))) {
        return TEMP_FLAGS_START + AdjustedTemplates[objNum - 1].flagId;
    }
    return TEMP_FLAGS_START + objNum;
}

u8 GetScaledLevel(u8 dist) {
    switch(dist) {
    case 0:
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 5;
    case 4:
        return 6;
    case 5:
        return 8;
    case 6:
        return 10;
    case 7:
        return 12;
    case 8:
        return 14;
    case 9:
        return 15;
    case 10:
        return 17;
    case 11:
        return 18;
    case 12:
        return 21;
    case 13:
        return 25;
    default:
        return 90;
    }
}

u16 AdjustSpecies(u16 species, u8 level, int evoStrat) {
    u16 newSpecies = species;
    int possible = 0;
    u16 possibilities[EVOS_PER_MON + 1];
    int addSelf = 0;

    for (int i = 0; i < EVOS_PER_MON; i++) {
        u16 method = gEvolutionTable[species][i].method;
        u16 param = gEvolutionTable[species][i].param;
        u16 targetSpecies = gEvolutionTable[species][i].targetSpecies;
        if (!method) {
            continue;
        }
        if (method == EVO_MEGA_EVOLUTION || method == EVO_MOVE_MEGA_EVOLUTION || method == EVO_PRIMAL_REVERSION || evoStrat == EVO_STRAT_DO_NOT) {
            continue;
        }
        if ((evoStrat == EVO_STRAT_NO_BELLOSSOM && targetSpecies == SPECIES_BELLOSSOM) ||
            (evoStrat == EVO_STRAT_NO_MAROWAK_ALOLAN && targetSpecies == SPECIES_MAROWAK_ALOLAN) ||
            (evoStrat == EVO_STRAT_NO_EXEGGUTOR_ALOLAN && targetSpecies == SPECIES_EXEGGUTOR_ALOLAN) ||
            (evoStrat == EVO_STRAT_NO_GALLADE && targetSpecies == SPECIES_GALLADE) ||
            (evoStrat == EVO_STRAT_NO_MR_MIME_GALARIAN && targetSpecies == SPECIES_MR_MIME_GALARIAN) ||
            (evoStrat == EVO_STRAT_NO_VILEPLUME && targetSpecies == SPECIES_VILEPLUME)) {
            
            continue;
        }
        if ((method == EVO_LEVEL
            || method == EVO_LEVEL_ATK_GT_DEF
            || method == EVO_LEVEL_ATK_EQ_DEF
            || method == EVO_LEVEL_ATK_LT_DEF
            || method == EVO_LEVEL_SILCOON
            || method == EVO_LEVEL_CASCOON
            || method == EVO_LEVEL_NINJASK
            || method == EVO_LEVEL_SHEDINJA
            || method == EVO_LEVEL_FEMALE
            || method == EVO_LEVEL_MALE
            || method == EVO_LEVEL_NIGHT
            || method == EVO_LEVEL_DAY
            || method == EVO_LEVEL_DUSK
            || method == EVO_ITEM_HOLD_DAY
            || method == EVO_ITEM_HOLD_NIGHT
            || method == EVO_LEVEL_RAIN) && param <= level) {

            possibilities[possible] = targetSpecies;
            possible++;
            continue;
        }
        if (evoStrat == EVO_STRAT_WILD) {
            // we don't want to evolve wild pokemon that level up in a way other than level.
            continue;
        }
        if (method == EVO_FRIENDSHIP
            || method == EVO_FRIENDSHIP_DAY
            || method == EVO_FRIENDSHIP_NIGHT
            || method == EVO_TRADE
            || method == EVO_TRADE_ITEM
            || method == EVO_ITEM
            || method == EVO_ITEM_HOLD_DAY
            || method == EVO_ITEM_HOLD_NIGHT
            || method == EVO_MAPSEC
            || method == EVO_ITEM_MALE
            || method == EVO_ITEM_FEMALE
            || method == EVO_SPECIFIC_MAP
            || method == EVO_BEAUTY
            || method == EVO_MOVE
            || method == EVO_MOVE_TYPE
            || method == EVO_SPECIFIC_MON_IN_PARTY
            || method == EVO_LEVEL_DARK_TYPE_MON_IN_PARTY
            || method == EVO_TRADE_SPECIFIC_MON) {

            u32 bstOld = GetTotalBaseStat(species);
            u32 bstNew = GetTotalBaseStat(targetSpecies);
            // int levelOld = (bstOld - 208) / 3.59;
            // int levelNew = (bstNew - 321) / 4.68;
            int levelMid = (((bstOld - 208) / 3.59) + ((bstNew - 321) / 4.68)) / 2;

            if (levelMid <= level) {
                possibilities[possible] = targetSpecies;
                possible++;
                continue;
            }
        }
    }
    if (addSelf || possible == 0) {
        possibilities[possible] = species;
        possible++;
    }

    newSpecies = possibilities[tinymt32_generate_uint32(&currentRoomSeed) % possible];
    if (newSpecies == species) {
        return newSpecies;
    }

    return AdjustSpecies(newSpecies, level, evoStrat);
}
