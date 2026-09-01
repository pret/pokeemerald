#ifndef GUARD_DATA_H
#define GUARD_DATA_H

#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/battle.h"
#include "constants/pokeball.h"
#include "difficulty.h"
#include "debug.h"

#define MAX_TRAINER_ITEMS 4

#define TRAINER_PIC_WIDTH 64
#define TRAINER_PIC_HEIGHT 64
#define TRAINER_PIC_SIZE (TRAINER_PIC_WIDTH * TRAINER_PIC_HEIGHT / 2)

// Red and Leaf's back pics have 5 frames, but this is presumably irrelevant in the places this is used.
#define MAX_TRAINER_PIC_FRAMES 4

enum {
    BATTLER_AFFINE_NORMAL,
    BATTLER_AFFINE_EMERGE,
    BATTLER_AFFINE_RETURN,
};

struct MonCoords
{
    // This would use a bitfield, but some function
    // uses it as a u8 and casting won't match.
    u8 size; // u8 width:4, height:4;
    u8 y_offset;
};

struct TrainerFrontPicInfo
{
    const u32 *imageData;
    const u16 *paletteData;
    const union AnimCmd *const *const animation;
    const struct Coords16 mugshotCoords;
    s16 mugshotRotation;
};

struct TrainerBackPicInfo
{
    const struct MonCoords coordinates;
    const struct SpriteFrameImage image;
    const u16 *paletteData;
    const union AnimCmd *const *const animation;
};

struct TrainerPicInfo
{
    const struct TrainerFrontPicInfo *frontPic;
    const struct TrainerBackPicInfo *backPic;
};

#define MON_COORDS_SIZE(width, height) (DIV_ROUND_UP(width, 8) << 4 | DIV_ROUND_UP(height, 8))
#define GET_MON_COORDS_WIDTH(size) ((size >> 4) * 8)
#define GET_MON_COORDS_HEIGHT(size) ((size & 0xF) * 8)
#define TRAINER_PARTY_IVS(hp, atk, def, speed, spatk, spdef) (hp | (atk << 5) | (def << 10) | (speed << 15) | (spatk << 20) | (spdef << 25))
#define TRAINER_PARTY_EVS(hp, atk, def, speed, spatk, spdef) ((const u8[6]){hp,atk,def,spatk,spdef,speed})

// Shared by both trainer and frontier mons
// See CreateNPCTrainerPartyFromTrainer and CreateFacilityMon
struct TrainerMon
{
    const u8 *nickname;
    const u8 *ev;
    u32 iv;
    enum Move moves[MAX_MON_MOVES];
    enum Species species;
    enum Item heldItem;
    enum Ability ability;
    u8 lvl;
    enum PokeBall ball:8;
    u8 friendship;
    u8 nature:5;
    bool8 gender:2;
    bool8 isShiny:1;
    enum Type teraType:5;
    bool8 gigantamaxFactor:1;
    u8 shouldUseDynamax:1;
    u8 padding1:1;
    u8 dynamaxLevel:4;
    u8 padding2:4;
    u32 tags;
};

#define TRAINER_PARTY(partyArray) partyArray, .partySize = ARRAY_COUNT(partyArray)

enum TrainerBattleType
{
    TRAINER_BATTLE_TYPE_SINGLES,
    TRAINER_BATTLE_TYPE_DOUBLES,
};

enum MultiTeamSize
{
    MULTI_TEAM_SIZE_FULL,
    MULTI_TEAM_SIZE_HALF,
};

#define UNPACK_STARTING_STATUSES_STRUCT(_enum, _fieldName, _typeMaxValue, ...) INVOKE_WITH_(UNPACK_STARTING_STATUSES_STRUCT_, _fieldName, UNPACK_B(_typeMaxValue));
#define UNPACK_STARTING_STATUSES_STRUCT_(_fieldName, _type, ...) _type FIRST(__VA_OPT__(_fieldName:BIT_SIZE(FIRST(__VA_ARGS__)),) _fieldName)

struct StartingStatuses
{
    STARTING_STATUS_DEFINITIONS(UNPACK_STARTING_STATUSES_STRUCT)
    // Expands to:
    // u32 electricTerrain:1;
    // u32 mistyTerrain:1;
    // u32 grassyTerrain:1;
    // u32 psychicTerrain:1;
    // u32 trickRoom:1;
    // u32 magicRoom:1;
    // u32 wonderRoom:1;
    // u32 tailwindPlayer:1;
    // u32 tailwindOpponent:1;
    // u32 rainbowPlayer:1;
    // u32 rainbowOpponent:1;
    // u32 seaOfFirePlayer:1;
    // u32 seaOfFireOpponent:1;
    // u32 swampPlayer:1;
    // u32 swampOpponent:1;
};

struct Trainer
{
    u64 aiFlags;
    const struct TrainerMon *party;
    enum Item items[MAX_TRAINER_ITEMS];
    struct StartingStatuses startingStatus; // this trainer starts a battle with a given status. see include/constants/battle.h for values
    u8 trainerClass;
    u16 encounterMusic:4;
    u16 multiTeamSize:1;
    u16 gender:1;
    u16 battleType:2;
    u16 mugshotColor:3;
    u16 partySize:3;
    u16 padding:2;
    enum TrainerPicID trainerPic;
    u8 trainerName[TRAINER_NAME_LENGTH + 1];
    u8 poolSize;
    u8 poolRuleIndex;
    u8 poolPickIndex;
    u8 poolPruneIndex;
    u16 overrideTrainer;
};

struct TrainerClass
{
    u8 name[13];
    u8 money;
    u16 ball;
};

struct TypeInfo
{
    u8 name[TYPE_NAME_LENGTH + 1];
    u8 generic[17];
    u8 palette;
    u16 zMove;
    u16 maxMove;
    u16 teraTypeRGBValue;    // Most values pulled from the Tera type icon palette.
    u16 damageCategory:2;    // Used for B_PHYSICAL_SPECIAL_SPLIT <= GEN_3
    u16 useSecondTypeIconPalette:1;
    u16 isSpecialCaseType:1;
    u16 isHiddenPowerType:1; // Changing this for any type will change the distribution of all Hidden Power types from vanilla.
    u16 padding:11;
    const u16 *const paletteTMHM;
    //enum Item enhanceItem;
    //enum Item berry;
    //enum Item gem;
    //enum Item plate;
    //enum Item memory;
    //enum Item zCrystal;
    //enum Item teraShard;
    //u16 arceusForm;
};

struct FollowerMsgInfo
{
    const u8 *text;
    const u8 *script;
};

struct FollowerMessagePool
{
    const struct FollowerMsgInfo *messages;
    const u8 *script;
    u16 length;
};

extern const u16 gMinigameDigits_Pal[];
extern const u32 gMinigameDigits_Gfx[];

extern const struct SpriteFrameImage gBattlerPicTable_PlayerLeft[];
extern const struct SpriteFrameImage gBattlerPicTable_OpponentLeft[];
extern const struct SpriteFrameImage gBattlerPicTable_PlayerRight[];
extern const struct SpriteFrameImage gBattlerPicTable_OpponentRight[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Brendan[];
extern const struct SpriteFrameImage gTrainerBackPicTable_May[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Red[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Leaf[];
extern const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireBrendan[];
extern const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireMay[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Wally[];
extern const struct SpriteFrameImage gTrainerBackPicTable_Steven[];

extern const union AffineAnimCmd *const gAffineAnims_BattleSpritePlayerSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteOpponentSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteContest[];

extern const union AnimCmd sAnim_GeneralFrame0[];
extern const union AnimCmd sAnim_GeneralFrame3[];
extern const union AnimCmd *const gAnims_MonPic[];
extern const union AnimCmd *const gAnims_Trainer[];
extern const struct TrainerPicInfo gTrainerPicInfo[TRAINER_PIC_COUNT];

extern const struct Trainer gTrainers[DIFFICULTY_COUNT][TRAINERS_COUNT];
extern const struct Trainer gBattlePartners[DIFFICULTY_COUNT][PARTNER_COUNT];

extern const struct TrainerClass gTrainerClasses[TRAINER_CLASS_COUNT];

extern const struct EggData gEggDatas[EGG_ID_COUNT];

// Follower text messages
extern const struct FollowerMsgInfo gFollowerHappyMessages[];
extern const struct FollowerMsgInfo gFollowerNeutralMessages[];
extern const struct FollowerMsgInfo gFollowerSadMessages[];
extern const struct FollowerMsgInfo gFollowerUpsetMessages[];
extern const struct FollowerMsgInfo gFollowerAngryMessages[];
extern const struct FollowerMsgInfo gFollowerPensiveMessages[];
extern const struct FollowerMsgInfo gFollowerLoveMessages[];
extern const struct FollowerMsgInfo gFollowerSurpriseMessages[];
extern const struct FollowerMsgInfo gFollowerCuriousMessages[];
extern const struct FollowerMsgInfo gFollowerMusicMessages[];
extern const struct FollowerMsgInfo gFollowerPoisonedMessages[];

static inline bool8 IsPartnerTrainerId(u16 trainerId)
{
    if (trainerId > TRAINER_PARTNER(PARTNER_NONE) && trainerId < TRAINER_PARTNER(PARTNER_COUNT))
        return TRUE;
    return FALSE;
}

static inline bool32 IsSpecialTrainer(u16 trainerId)
{
    if (trainerId == TRAINER_SECRET_BASE ||
        trainerId == TRAINER_LINK_OPPONENT ||
        trainerId == TRAINER_UNION_ROOM)
    {
        return TRUE;
    }
    return FALSE;
}

static inline u16 SanitizeTrainerId(u16 trainerId)
{
    assertf(trainerId < TRAINERS_COUNT, "invalid trainer: %d", trainerId)
    {
        return TRAINER_NONE;
    }

    return trainerId;
}

//sanitizes but also converts partner trainer ids into gBattlePartners indexes
static inline u16 GetPartnerIdFromTrainerId(u16 trainerId)
{
    assertf(IsPartnerTrainerId(trainerId), "invalid trainer id for partner: %d", trainerId)
    {
        return PARTNER_NONE;
    }

    return (trainerId - TRAINER_PARTNER(PARTNER_NONE));
}

static inline const struct Trainer *GetTrainerStructFromId(u16 trainerId)
{
    if (gIsDebugBattle) return GetDebugAiTrainer();
    enum DifficultyLevel difficulty;

    if (IsPartnerTrainerId(trainerId))
    {
        difficulty = GetBattlePartnerDifficultyLevel(trainerId);
        return &gBattlePartners[difficulty][GetPartnerIdFromTrainerId(trainerId)];
    }
    else
    {
        difficulty = GetTrainerDifficultyLevel(trainerId);
        return &gTrainers[difficulty][SanitizeTrainerId(trainerId)];
    }
}

static inline const enum TrainerClassID GetTrainerClassFromId(u16 trainerId)
{
    const struct Trainer *trainer = GetTrainerStructFromId(trainerId);

    return trainer->trainerClass;
}

static inline const u8 *GetTrainerClassNameFromId(u16 trainerId)
{
    return gTrainerClasses[GetTrainerClassFromId(trainerId)].name;
}

static inline const u8 *GetTrainerNameFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->trainerName;
}

static inline const enum TrainerPicID GetTrainerPicFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->trainerPic;
}

static inline const struct StartingStatuses GetTrainerStartingStatusFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->startingStatus;
}

static inline const enum TrainerBattleType GetTrainerBattleType(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->battleType;
}

static inline const u8 GetTrainerPartySizeFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->partySize;
}

static inline const bool32 DoesTrainerHaveMugshot(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->mugshotColor;
}

static inline const u8 GetTrainerMugshotColorFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->mugshotColor;
}

static inline const enum Item *GetTrainerItemsFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->items;
}

static inline const struct TrainerMon *GetTrainerPartyFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->party;
}

static inline const u64 GetTrainerAIFlagsFromId(u16 trainerId)
{
    return GetTrainerStructFromId(trainerId)->aiFlags;
}

static inline enum TrainerPicID SanitizeTrainerPic(enum TrainerPicID trainerPicId)
{
    assertf(trainerPicId < TRAINER_PIC_COUNT, "trainerPicId %d out of range", trainerPicId)
    {
        return TRAINER_PIC_NONE;
    };
    return trainerPicId;
}

static inline enum TrainerPicID SanitizeFrontTrainerPic(enum TrainerPicID trainerPicId)
{
    trainerPicId = SanitizeTrainerPic(trainerPicId);
    assertf(gTrainerPicInfo[trainerPicId].frontPic != NULL, "trainerPicId %d does not have a front pic defined", trainerPicId)
    {
        return TRAINER_PIC_NONE;
    }
    return trainerPicId;
}

static inline enum TrainerPicID SanitizeBackTrainerPic(enum TrainerPicID trainerPicId)
{
    trainerPicId = SanitizeTrainerPic(trainerPicId);
    assertf(gTrainerPicInfo[trainerPicId].backPic != NULL, "trainerPicId %d does not have a back pic defined", trainerPicId)
    {
        return TRAINER_PIC_NONE;
    }
    return trainerPicId;
}

static inline const u32 *GetTrainerFrontPicData(enum TrainerPicID trainerPic)
{
    return gTrainerPicInfo[SanitizeFrontTrainerPic(trainerPic)].frontPic->imageData;
}

static inline const u16 *GetTrainerFrontPicPalette(enum TrainerPicID trainerPic)
{
    return gTrainerPicInfo[SanitizeFrontTrainerPic(trainerPic)].frontPic->paletteData;
}

static inline const struct Coords16 GetTrainerFrontPicMugshotCoords(enum TrainerPicID trainerPic)
{
    return gTrainerPicInfo[SanitizeFrontTrainerPic(trainerPic)].frontPic->mugshotCoords;
}

static inline s16 GetTrainerFrontPicMugshotRotation(enum TrainerPicID trainerPic)
{
    return gTrainerPicInfo[SanitizeFrontTrainerPic(trainerPic)].frontPic->mugshotRotation;
}

static inline const struct MonCoords *GetTrainerBackPicCoords(enum TrainerPicID trainerPic)
{
    return &gTrainerPicInfo[SanitizeBackTrainerPic(trainerPic)].backPic->coordinates;
}

static inline const struct SpriteFrameImage *GetTrainerBackPicImage(enum TrainerPicID trainerPic)
{
    return &gTrainerPicInfo[SanitizeBackTrainerPic(trainerPic)].backPic->image;
}

static inline const union AnimCmd *const *GetTrainerBackPicAnims(enum TrainerPicID trainerPic)
{
    return gTrainerPicInfo[SanitizeBackTrainerPic(trainerPic)].backPic->animation;
}

static inline const u16 *GetTrainerBackPicPalette(enum TrainerPicID trainerPic)
{
    return gTrainerPicInfo[SanitizeBackTrainerPic(trainerPic)].backPic->paletteData;
}

#endif // GUARD_DATA_H
