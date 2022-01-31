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

#ifdef __wasm__
#define MYLOG(f_, ...) printf("GBA: "); printf((f_), ##__VA_ARGS__); printf("\n")
#else
#include "printf.h"
#include "mgba.h"
#define MYLOG(f_, ...) mgba_printf(MGBA_LOG_INFO, (f_), ##__VA_ARGS__)
#endif

EWRAM_DATA int seed;
EWRAM_DATA tinymt32_t currentRoomSeed;
EWRAM_DATA u16 realStarterMon[6];

EWRAM_DATA struct MapEvents AdjustedMapEvents;
EWRAM_DATA struct ObjectEventTemplate AdjustedTemplates[MAX_OBJECTS];
EWRAM_DATA u16 CurrentAdjustedRoom = 0xFFFF;
EWRAM_DATA u8 CurrentAdjustedRoomIndex;

EWRAM_DATA union ShuffledObject AdjustedObjects[MAX_OBJECTS];

EWRAM_DATA struct WarpData realWarps[TOTAL_WARPS] = {};
EWRAM_DATA u8 distances[TOTAL_ROOMS];

void Shuffle(u32 s) {
    tinymt32_t tinymt;
    tinymt.mat1 = MAT1;
    tinymt.mat2 = MAT2;
    tinymt.tmat = TMAT;
    seed = s;
    tinymt32_init(&tinymt, seed);
    MYLOG("seed: %u", seed);

    int r;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
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

    int allRooms[TOTAL_ROOMS - 1];
    for (int j = 0; j < TOTAL_ROOMS - 2; j++) {
        allRooms[j] = j + 1;
    }
    allRooms[TOTAL_ROOMS - 2] = TOTAL_ROOMS - 1;
    
    for (int j = TOTAL_ROOMS - 3; j > 0; j--) {
        r = (tinymt32_generate_uint32(&tinymt) % j);
        u16 t = allRooms[r];
        allRooms[r] = allRooms[j];
        allRooms[j] = t;
    }

    int currentRoomIndex = 0;
    distances[currentRoomIndex] = 0;
    for (int j = 0; j < TOTAL_ROOMS - 1; j++) {
        int targetRoomIndex = allRooms[j];
        distances[targetRoomIndex] = distances[currentRoomIndex] + 1;
        u8 roomGroup = Rooms[targetRoomIndex].id >> 8;
        u8 roomId = Rooms[targetRoomIndex].id & 0xFF;
        realWarps[currentRoomIndex] = (struct WarpData){roomGroup, roomId, 0, -1, -1};
        currentRoomIndex = targetRoomIndex;
    }

    for (int i = 0; i < 5; i++) {
        r = tinymt32_generate_uint32(&tinymt) % 50;
        AddBagItem(ITEM_TM01 + r, 1);
    }

    AddBagItem(ITEM_POTION, 5);
    AddBagItem(ITEM_MAX_ELIXIR, 3);
    AddBagItem(ITEM_REVIVE, 1);

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
    int broke = 0;
    // burn an appropriate amount of RNs here.
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        seed2 = tinymt32_generate_uint32(&tinymt);
        if (Rooms[i].id == CurrentAdjustedRoom) {
            CurrentAdjustedRoomIndex = i;
            broke = 1;
            break;
        }
    }
    if (broke == 0) {
        MYLOG("never broke!");
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

void DeclareTrainer(u8 objNum) {
    MirrorMapData();

    int i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_TRAINERS;

    const struct TrainerTemplate *tt = qTrainers[i];

    AdjustedObjects[objNum].t.trainer.aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY;
    AdjustedObjects[objNum].t.trainer.doubleBattle = FALSE;
    AdjustedObjects[objNum].t.trainer.encounterMusic_gender = tt->encounterMusic_gender;
    AdjustedObjects[objNum].t.trainer.trainerClass = tt->trainerClass;
    AdjustedObjects[objNum].t.trainer.trainerPic = tt->trainerPic;
    for (int i = 0; i < 4; i++) {
        AdjustedObjects[objNum].t.trainer.items[i] = ITEM_NONE;
    }
    if (tt->rarity == 0) {
        AdjustedObjects[objNum].t.trainer.partyFlags = tt->partyFlags;
        AdjustedObjects[objNum].t.trainer.partySize = tt->partySize;

        int move_bytes = tt->partySize;
        switch (tt->partyFlags & 3) {
            case 0:
                move_bytes *= sizeof(struct TrainerMonNoItemDefaultMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt->party.NoItemDefaultMoves, move_bytes);
                for (int i = 0; i < tt->partySize; i++) {
                    AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.NoItemDefaultMoves = AdjustedObjects[objNum].t.party.NoItemDefaultMoves;
                break;
            case F_TRAINER_PARTY_CUSTOM_MOVESET:
                move_bytes *= sizeof(struct TrainerMonNoItemCustomMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt->party.NoItemCustomMoves, move_bytes);
                for (int i = 0; i < tt->partySize; i++) {
                    AdjustedObjects[objNum].t.party.NoItemCustomMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.NoItemCustomMoves = AdjustedObjects[objNum].t.party.NoItemCustomMoves;
                break;
            case F_TRAINER_PARTY_HELD_ITEM:
                move_bytes *= sizeof(struct TrainerMonItemDefaultMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt->party.ItemDefaultMoves, move_bytes);
                for (int i = 0; i < tt->partySize; i++) {
                    AdjustedObjects[objNum].t.party.ItemDefaultMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.ItemDefaultMoves = AdjustedObjects[objNum].t.party.ItemDefaultMoves;
                break;
            case F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET:
                move_bytes *= sizeof(struct TrainerMonItemCustomMoves);
                memcpy(&AdjustedObjects[objNum].t.party, tt->party.ItemCustomMoves, move_bytes);
                for (int i = 0; i < tt->partySize; i++) {
                    AdjustedObjects[objNum].t.party.ItemCustomMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
                }
                AdjustedObjects[objNum].t.trainer.party.ItemCustomMoves = AdjustedObjects[objNum].t.party.ItemCustomMoves;
                break;
        }
    } else {
        AdjustedObjects[objNum].t.trainer.partyFlags = 0;
        AdjustedObjects[objNum].t.trainer.partySize = 2;
        for (int i = 0; i < AdjustedObjects[objNum].t.trainer.partySize; i++) {
            AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].iv = 0;
            AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].lvl = distances[CurrentAdjustedRoomIndex] + 1;
            int r = tinymt32_generate_uint32(&currentRoomSeed) % 20;
            int s = TrainerMonTypes[tt->type1][r];
            AdjustedObjects[objNum].t.party.NoItemDefaultMoves[i].species = s;
        }
        AdjustedObjects[objNum].t.trainer.party.NoItemDefaultMoves = AdjustedObjects[objNum].t.party.NoItemDefaultMoves;
    }
    AdjustedObjects[objNum].t.defeatText = tt->defeatText;
    AdjustedObjects[objNum].t.introText = tt->introText;
    AdjustedObjects[objNum].t.postbattleText = tt->postbattleText;
    AdjustedObjects[objNum].t.name = tt->trainerName;
    AdjustedTemplates[objNum].graphicsId = tt->graphicsId;
}

void DeclareWildMon(u8 objNum) {
    MirrorMapData();
    int i = tinymt32_generate_uint32(&currentRoomSeed) % 809;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.iv = 15;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.lvl = distances[CurrentAdjustedRoomIndex] + 1;
    AdjustedObjects[objNum].wm.NoItemDefaultMoves.species = i + 1;
    AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_POKEMON_001 + i;
}

void DeclareItem(u16 objNum) {
    MirrorMapData();
    int i = tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_ITEMS;
    AdjustedObjects[objNum].itemId = possibleItems[i];
    AdjustedTemplates[objNum].graphicsId = OBJ_EVENT_GFX_ITEM_BALL;
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
void DeclareNPC(u16 objNum) {
    MirrorMapData();
    int i = (tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_NPCS) + 1;
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
        AdjustedObjects[objNum].npc.trader.igt.heldItem = possibleItems[tinymt32_generate_uint32(&currentRoomSeed) % POSSIBLE_ITEMS];
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

u16 GetAdjustedTrainerFlag(u16 index) {
    u16 objNum = index - 1;
    if (objNum >= AdjustedMapEvents.objectEventCount) {
        MYLOG("problem with trainer flags");
        return TRAINER_FLAGS_START + index;
    }
    return TRAINER_FLAGS_START + AdjustedMapEvents.objectEvents[objNum].flagId;
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
    // We skip the first two warp redirects.
    // The first warp places the player in the truck.
    // The second warp takes the player from the truck to littleroot town.
    static int warpSkips = 0;
    if (warpSkips < 1) {
        warpSkips++;
        return;
    }
    int fromIndex = -1;
    int roomId = (warp->mapGroup << 8) | warp->mapNum;
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        if (Rooms[i].id == roomId) {
            fromIndex = i;
            break;
        }
    }
    if (fromIndex == -1) {
        if (warp->mapGroup == 0 && warp->mapNum == 0 && warp->warpId == 0 && warp->x == 0 && warp->y == 0) {
            MYLOG("white out warp");
        } else {
            MYLOG("unknown warp {%d, %d, %d, %d, %d}", warp->mapGroup, warp->mapNum, warp->warpId, warp->x, warp->y);
        }
        return;
    }
    int leavingDirection = warp->warpId;
    struct WarpData w = realWarps[fromIndex];
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
