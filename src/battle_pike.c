#include "global.h"
#include "battle_pike.h"
#include "event_data.h"
#include "frontier_util.h"
#include "fieldmap.h"
#include "save.h"
#include "battle.h"
#include "random.h"
#include "task.h"
#include "battle_tower.h"
#include "party_menu.h"
#include "alloc.h"
#include "palette.h"
#include "script.h"
#include "battle_setup.h"
#include "constants/event_objects.h"
#include "constants/battle_frontier.h"
#include "constants/abilities.h"
#include "constants/easy_chat.h"
#include "constants/layouts.h"
#include "constants/rgb.h"
#include "constants/trainers.h"
#include "constants/species.h"
#include "constants/moves.h"

#define PIKE_ROOM_SINGLE_BATTLE 0
#define PIKE_ROOM_HEAL_FULL 1
#define PIKE_ROOM_NPC 2
#define PIKE_ROOM_STATUS 3
#define PIKE_ROOM_HEAL_PART 4
#define PIKE_ROOM_WILD_MONS 5
#define PIKE_ROOM_HARD_BATTLE 6
#define PIKE_ROOM_DOUBLE_BATTLE 7
#define PIKE_ROOM_BRAIN 8

// For the room with a status effect.
#define PIKE_STATUS_KIRLIA 0
#define PIKE_STATUS_DUSCLOPS 1

struct PikeRoomNPC
{
    u16 graphicsId;
    u8 speechId1;
    u8 speechId2;
    u8 speechId3;
};

struct PikeWildMon
{
    u16 species;
    u8 levelDelta;
    u16 moves[4];
};

// IWRAM bss
static IWRAM_DATA u8 sRoomType;
static IWRAM_DATA u8 sStatusMon;
static IWRAM_DATA bool8 sUnknown_0300128E;
static IWRAM_DATA u32 sStatusFlags;
static IWRAM_DATA u8 sNpcId;

// This file's functions.
static void SetRoomType(void);
static void GetBattlePikeData(void);
static void SetBattlePikeData(void);
static void GetInFinalRoom(void);
static void SetupRoomEventObjects(void);
static void GetRoomType(void);
static void sub_81A7400(void);
static void sub_81A740C(void);
static void sub_81A7418(void);
static void nullsub_76(void);
static void nullsub_124(void);
static void GetRoomInflictedStatus(void);
static void GetRoomInflictedStatusMon(void);
static void HealOneOrTwoMons(void);
static void BufferNPCMessage(void);
static void StatusInflictionScreenFade(void);
static void GetInBattlePike(void);
static void SetHintedRoom(void);
static void GetHintedRoomIndex(void);
static void GetRoomTypeHint(void);
static void ClearPikeTrainerIds(void);
static void BufferRecordMixingTrainerMessage(void);
static void GetCurrentRoomPikeQueenFightType(void);
static void HealSomeMonsBeforePikeQueen(void);
static void SetHealingRoomsDisabled(void);
static void CanAnyPartyMonsBeHealed(void);
static void BackupMonHeldItems(void);
static void RestoreMonHeldItems(void);
static void InitPikeChallenge(void);
static u8 GetNextRoomType(void);
static void PrepareOneTrainer(bool8 difficult);
static u16 GetNPCRoomGraphicsId(void);
static void PrepareTwoTrainers(void);
static void TryHealMons(u8 healCount);
static void Task_DoStatusInflictionScreenFade(u8 taskId);
static bool8 AtLeastTwoAliveMons(void);
static u8 SpeciesToPikeMonId(u16 species);
static bool8 CanEncounterWildMon(u8 monLevel);
static u8 GetPikeQueenFightType(u8);
static bool8 StatusInflictionFadeOut(struct Task *task);
static bool8 StatusInflictionFadeIn(struct Task *task);

// Const rom data.
static const struct PikeWildMon sLvl50_Mons1[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_BODY_SLAM, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_SURF}
    },
    {
        .species = SPECIES_DUSCLOPS,
        .levelDelta = 5,
        .moves = {MOVE_WILL_O_WISP, MOVE_MEAN_LOOK, MOVE_TOXIC, MOVE_SHADOW_PUNCH}
    }
};

static const struct PikeWildMon sLvl50_Mons2[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_BODY_SLAM, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_SURF}
    },
    {
        .species = SPECIES_ELECTRODE,
        .levelDelta = 5,
        .moves = {MOVE_EXPLOSION, MOVE_SELF_DESTRUCT, MOVE_THUNDER, MOVE_TOXIC}
    }
};

static const struct PikeWildMon sLvl50_Mons3[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_BODY_SLAM, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_SURF}
    },
    {
        .species = SPECIES_BRELOOM,
        .levelDelta = 5,
        .moves = {MOVE_SPORE, MOVE_STUN_SPORE, MOVE_POISON_POWDER, MOVE_HIDDEN_POWER}
    }
};

static const struct PikeWildMon sLvl50_Mons4[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_BODY_SLAM, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_SURF}
    },
    {
        .species = SPECIES_WOBBUFFET,
        .levelDelta = 5,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_SAFEGUARD, MOVE_DESTINY_BOND}
    }
};

static const struct PikeWildMon *const sLvl50Mons[] =
{
    sLvl50_Mons1,
    sLvl50_Mons2,
    sLvl50_Mons3,
    sLvl50_Mons4
};

static const struct PikeWildMon sLvlOpen_Mons1[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_POISON_FANG, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_ICE_BEAM}
    },
    {
        .species = SPECIES_DUSCLOPS,
        .levelDelta = 5,
        .moves = {MOVE_WILL_O_WISP, MOVE_MEAN_LOOK, MOVE_TOXIC, MOVE_ICE_BEAM}
    }
};

static const struct PikeWildMon sLvlOpen_Mons2[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_POISON_FANG, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_ICE_BEAM}
    },
    {
        .species = SPECIES_ELECTRODE,
        .levelDelta = 5,
        .moves = {MOVE_EXPLOSION, MOVE_SELF_DESTRUCT, MOVE_THUNDER, MOVE_TOXIC}
    }
};

static const struct PikeWildMon sLvlOpen_Mons3[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_POISON_FANG, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_ICE_BEAM}
    },
    {
        .species = SPECIES_BRELOOM,
        .levelDelta = 5,
        .moves = {MOVE_SPORE, MOVE_STUN_SPORE, MOVE_POISON_POWDER, MOVE_HIDDEN_POWER}
    }
};

static const struct PikeWildMon sLvlOpen_Mons4[] =
{
    {
        .species = SPECIES_SEVIPER,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_GLARE, MOVE_POISON_FANG, MOVE_SLUDGE_BOMB}
    },
    {
        .species = SPECIES_MILOTIC,
        .levelDelta = 4,
        .moves = {MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_BODY_SLAM, MOVE_ICE_BEAM}
    },
    {
        .species = SPECIES_WOBBUFFET,
        .levelDelta = 5,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_SAFEGUARD, MOVE_ENCORE}
    }
};

static const struct PikeWildMon *const sLvlOpenMons[] =
{
    sLvlOpen_Mons1,
    sLvlOpen_Mons2,
    sLvlOpen_Mons3,
    sLvlOpen_Mons4
};

static const struct PikeWildMon *const *const sWildMons[2] =
{
    [FRONTIER_LVL_50]   = sLvl50Mons,
    [FRONTIER_LVL_OPEN] = sLvlOpenMons
};

static const struct PikeRoomNPC sNPCTable[] =
{
    {
        .graphicsId = EVENT_OBJ_GFX_POKEFAN_F,
        .speechId1 = 3,
        .speechId2 = 5,
        .speechId3 = 6
    },
    {
        .graphicsId = EVENT_OBJ_GFX_NINJA_BOY,
        .speechId1 = 13,
        .speechId2 = 32,
        .speechId3 = 37
    },
    {
        .graphicsId = EVENT_OBJ_GFX_FAT_MAN,
        .speechId1 = 8,
        .speechId2 = 11,
        .speechId3 = 12
    },
    {
        .graphicsId = EVENT_OBJ_GFX_BUG_CATCHER,
        .speechId1 = 34,
        .speechId2 = 30,
        .speechId3 = 33
    },
    {
        .graphicsId = EVENT_OBJ_GFX_EXPERT_M,
        .speechId1 = 0,
        .speechId2 = 0,
        .speechId3 = 0
    },
    {
        .graphicsId = EVENT_OBJ_GFX_OLD_WOMAN,
        .speechId1 = 1,
        .speechId2 = 1,
        .speechId3 = 1
    },
    {
        .graphicsId = EVENT_OBJ_GFX_BLACK_BELT,
        .speechId1 = 22,
        .speechId2 = 23,
        .speechId3 = 27
    },
    {
        .graphicsId = EVENT_OBJ_GFX_HIKER,
        .speechId1 = 8,
        .speechId2 = 22,
        .speechId3 = 31
    },
    {
        .graphicsId = EVENT_OBJ_GFX_GIRL_3,
        .speechId1 = 13,
        .speechId2 = 39,
        .speechId3 = 21
    },
    {
        .graphicsId = EVENT_OBJ_GFX_WOMAN_2,
        .speechId1 = 2,
        .speechId2 = 4,
        .speechId3 = 17
    },
    {
        .graphicsId = EVENT_OBJ_GFX_CYCLING_TRIATHLETE_M,
        .speechId1 = 30,
        .speechId2 = 20,
        .speechId3 = 36
    },
    {
        .graphicsId = EVENT_OBJ_GFX_MAN_5,
        .speechId1 = 28,
        .speechId2 = 34,
        .speechId3 = 25
    },
    {
        .graphicsId = EVENT_OBJ_GFX_SCHOOL_KID_M,
        .speechId1 = 23,
        .speechId2 = 38,
        .speechId3 = 26
    },
    {
        .graphicsId = EVENT_OBJ_GFX_FISHERMAN,
        .speechId1 = 23,
        .speechId2 = 30,
        .speechId3 = 11
    },
    {
        .graphicsId = EVENT_OBJ_GFX_LASS,
        .speechId1 = 15,
        .speechId2 = 19,
        .speechId3 = 14
    },
    {
        .graphicsId = EVENT_OBJ_GFX_MANIAC,
        .speechId1 = 2,
        .speechId2 = 29,
        .speechId3 = 26
    },
    {
        .graphicsId = EVENT_OBJ_GFX_RUNNING_TRIATHLETE_M,
        .speechId1 = 37,
        .speechId2 = 12,
        .speechId3 = 32
    },
    {
        .graphicsId = EVENT_OBJ_GFX_MAN_3,
        .speechId1 = 24,
        .speechId2 = 23,
        .speechId3 = 38
    },
    {
        .graphicsId = EVENT_OBJ_GFX_WOMAN_3,
        .speechId1 = 5,
        .speechId2 = 22,
        .speechId3 = 4
    },
    {
        .graphicsId = EVENT_OBJ_GFX_LITTLE_BOY,
        .speechId1 = 41,
        .speechId2 = 37,
        .speechId3 = 35
    },
    {
        .graphicsId = EVENT_OBJ_GFX_TUBER_F,
        .speechId1 = 39,
        .speechId2 = 14,
        .speechId3 = 13
    },
    {
        .graphicsId = EVENT_OBJ_GFX_GENTLEMAN,
        .speechId1 = 10,
        .speechId2 = 7,
        .speechId3 = 9
    },
    {
        .graphicsId = EVENT_OBJ_GFX_LITTLE_GIRL,
        .speechId1 = 40,
        .speechId2 = 20,
        .speechId3 = 16
    },
    {
        .graphicsId = EVENT_OBJ_GFX_RUNNING_TRIATHLETE_F,
        .speechId1 = 18,
        .speechId2 = 13,
        .speechId3 = 21
    },
    {
        .graphicsId = EVENT_OBJ_GFX_MAN_1,
        .speechId1 = 22,
        .speechId2 = 31,
        .speechId3 = 27
    }
};

static const u16 sNPCSpeeches[][6] =
{
    {EC_WORD_I_AM, EC_WORD_LOST, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_MOVE2(HELPING_HAND)},
    {EC_WORD_I_VE, EC_WORD_NO, EC_WORD_SENSE, EC_WORD_OF, EC_WORD_WHERE, EC_WORD_I_AM},
    {EC_WORD_WHAT, EC_WORD_SHOULD, EC_WORD_I, EC_WORD_DO, EC_WORD_NOW, EC_WORD_QUES},
    {EC_WORD_THIS, EC_WORD_IS, EC_WORD_TOO, EC_WORD_EXCITING, EC_WORD_FOR, EC_WORD_ME},
    {EC_WORD_DID, EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_A, EC_WORD_MISTAKE, EC_WORD_QUES},
    {EC_WORD_IT_S, EC_WORD_MEAN, EC_WORD_AND, EC_WORD_AWFUL, EC_WORD_IN, EC_WORD_HERE},
    {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_TIRED, EC_WORD_OF, EC_WORD_THIS, EC_WORD_PLACE},
    {EC_WORD_I, EC_WORD_QUITE, EC_WORD_ENJOY, EC_WORD_THIS, EC_WORD_CHALLENGE, 0xFFFF},
    {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_HOW, EC_WORD_I, EC_MOVE2(TACKLE), EC_WORD_THIS},
    {EC_WORD_READY, EC_WORD_TO, EC_WORD_GIVE_UP, EC_WORD_YET, EC_WORD_QUES, 0xFFFF},
    {EC_WORD_OH, EC_WORD_NO, EC_WORD_WHO, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_QUES},
    {EC_WORD_I_VE, EC_WORD_BEEN, EC_WORD_WANDERING, EC_WORD_ABOUT, EC_WORD_FOREVER, EC_WORD_ELLIPSIS},
    {EC_WORD_I, EC_WORD_THINK, EC_WORD_I, EC_WORD_WILL, EC_WORD_GIVE_UP, 0xFFFF},
    {EC_WORD_WHAT, EC_WORD_SHOULD, EC_WORD_I, EC_WORD_DO, EC_WORD_NEXT, EC_WORD_QUES},
    {EC_WORD_I, EC_WORD_CAN_WIN, EC_WORD_WITH, EC_WORD_MY, EC_MOVE(SHEER_COLD), EC_WORD_GENIUS},
    {EC_WORD_WON_T, EC_WORD_SOMEONE, EC_WORD_COOL, EC_WORD_SHOW, EC_WORD_UP, EC_WORD_QUES},
    {EC_WORD_BATTLE, EC_WORD_GAME, EC_WORD_IS, EC_WORD_AWESOME, EC_WORD_EXCL, 0xFFFF},
    {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_TAKE, EC_WORD_THIS, EC_WORD_ANY, EC_WORD_MORE},
    {EC_WORD_I, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_IF, EC_WORD_IT_S, EC_WORD_OKAY},
    {EC_WORD_OH, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_NOT, EC_WORD_ANOTHER, EC_WORD_TRAINER},
    {EC_WORD_IT, EC_WORD_HAS, EC_WORD_TO, EC_WORD_BE, EC_WORD_LEFT, EC_WORD_NEXT},
    {EC_WORD_IT, EC_WORD_MUST_BE, EC_WORD_OVER, EC_WORD_SOON, EC_WORD_RIGHT, EC_WORD_QUES},
    {EC_WORD_THIS, EC_WORD_IS, EC_WORD_TOTALLY, EC_WORD_EASY, EC_WORD_ISN_T_IT_QUES, 0xFFFF},
    {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_POWER, EC_WORD_ON, 0xFFFF},
    {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NO, EC_WORD_GIVE_UP, EC_WORD_IN, EC_WORD_ME},
    {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_GOING, EC_WORD_TO, EC_WORD_MAKE, EC_WORD_IT},
    {EC_WORD_GO, EC_WORD_ON, EC_WORD_I, EC_WORD_CAN_T, EC_WORD_ANY, EC_WORD_MORE},
    {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_AFTER, EC_WORD_ANOTHER, EC_WORD_ELLIPSIS, 0xFFFF},
    {EC_WORD_DO, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_STEEL, EC_WORD_POKEMON, EC_WORD_QUES},
    {EC_WORD_EVERY, EC_WORD_TRAINER, EC_WORD_HERE, EC_WORD_IS, EC_WORD_TOO_WEAK, 0xFFFF},
    {EC_WORD_YOU, EC_WORD_THINK, EC_WORD_THIS, EC_WORD_IS, EC_WORD_EASY, EC_WORD_QUES},
    {EC_WORD_WHAT, EC_WORD_WILL, EC_WORD_COME, EC_WORD_AFTER, EC_WORD_THIS, EC_WORD_QUES},
    {EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_SO, EC_WORD_CONFUSED, EC_WORD_EXCL, 0xFFFF},
    {EC_WORD_I, EC_WORD_JUST, EC_WORD_WANT, EC_WORD_TO, EC_WORD_GO_HOME, EC_WORD_ELLIPSIS},
    {EC_WORD_YEEHAW_EXCL, EC_WORD_THIS, EC_WORD_PLACE, EC_WORD_IS, EC_WORD_A, EC_WORD_PUSHOVER},
    {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_BEEN, EC_WORD_IN, EC_WORD_A, EC_WORD_BATTLE},
    {EC_WORD_MAYBE, EC_WORD_IT_S, EC_WORD_RIGHT, EC_WORD_NEXT, EC_WORD_I, EC_WORD_THINK},
    {EC_WORD_WAAAH, EC_WORD_EXCL, EC_WORD_IT, EC_WORD_WASN_T, EC_WORD_THIS, EC_WORD_WAY},
    {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_TOO, EC_WORD_TIRED, EC_WORD_ELLIPSIS},
    {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_TO, EC_WORD_POISON},
    {EC_WORD_LALALA, EC_WORD_LALALA, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_AWESOME, EC_WORD_LALALA},
    {EC_MOVE2(TOXIC), EC_WORD_IS, EC_WORD_A, EC_WORD_TERRIBLE, EC_WORD_THING, EC_WORD_ISN_T_IT_QUES},
};

// Only the 5th array in this data is used by the code.
static const u8 sPikeQueenWinStreakAppearances[][4] =
{
    {35,  70, 35, 1},
    { 4,   9,  5, 0},
    {21,  42, 21, 1},
    {28,  56, 28, 1},
    {21,  42, 21, 1},
    {28, 140, 56, 1},
    {21,  70, 35, 0},
};

static void (* const sBattlePikeFunctions[])(void) =
{
    SetRoomType,
    GetBattlePikeData,
    SetBattlePikeData,
    GetInFinalRoom,
    SetupRoomEventObjects,
    GetRoomType,
    sub_81A7400,
    sub_81A740C,
    sub_81A7418,
    nullsub_76,
    nullsub_124,
    GetRoomInflictedStatus,
    GetRoomInflictedStatusMon,
    HealOneOrTwoMons,
    BufferNPCMessage,
    StatusInflictionScreenFade,
    GetInBattlePike,
    SetHintedRoom,
    GetHintedRoomIndex,
    GetRoomTypeHint,
    ClearPikeTrainerIds,
    BufferRecordMixingTrainerMessage,
    GetCurrentRoomPikeQueenFightType,
    HealSomeMonsBeforePikeQueen,
    SetHealingRoomsDisabled,
    CanAnyPartyMonsBeHealed,
    BackupMonHeldItems,
    RestoreMonHeldItems,
    InitPikeChallenge
};

static const u8 sRoomTypeHints[] = {
    3, // PIKE_ROOM_SINGLE_BATTLE
    3, // PIKE_ROOM_HEAL_FULL
    1, // PIKE_ROOM_NPC
    0, // PIKE_ROOM_STATUS
    0, // PIKE_ROOM_HEAL_PART
    2, // PIKE_ROOM_WILD_MONS
    2, // PIKE_ROOM_HARD_BATTLE
    1, // PIKE_ROOM_DOUBLE_BATTLE
    4, // PIKE_ROOM_BRAIN
};

static const u8 sNumMonsToHealBeforePikeQueen[][3] =
{
    {2, 1, 0},
    {2, 0, 1},
    {1, 2, 0},
    {1, 0, 2},
    {0, 2, 1},
    {0, 1, 2},
};

static bool8 (* const sStatusInflictionScreenFadeFuncs[])(struct Task *) =
{
    StatusInflictionFadeOut, StatusInflictionFadeIn
};

static const u32 gUnknown_08612690[] = {0x400, 0x800};

// code
void CallBattlePikeFunction(void)
{
    sBattlePikeFunctions[gSpecialVar_0x8004]();
}

static void SetRoomType(void)
{
    u8 roomType = GetNextRoomType();
    sRoomType = roomType;
}

static void SetupRoomEventObjects(void)
{
    bool32 setObjGfx1, setObjGfx2;
    u32 objGfx1;
    u16 objGfx2;

    VarSet(VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_LINK_RECEPTIONIST);
    VarSet(VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_DUSCLOPS);
    setObjGfx1 = TRUE;
    setObjGfx2 = FALSE;
    objGfx1 = 0;
    objGfx2 = 0;

    switch (sRoomType)
    {
    case PIKE_ROOM_SINGLE_BATTLE:
        PrepareOneTrainer(FALSE);
        setObjGfx1 = FALSE;
        break;
    case PIKE_ROOM_HEAL_FULL:
        objGfx1 = EVENT_OBJ_GFX_LINK_RECEPTIONIST;
        break;
    case PIKE_ROOM_NPC:
        objGfx1 = (u8)(GetNPCRoomGraphicsId());
        break;
    case PIKE_ROOM_STATUS:
        objGfx1 = EVENT_OBJ_GFX_GENTLEMAN;
        if (sStatusMon == PIKE_STATUS_DUSCLOPS)
            objGfx2 = EVENT_OBJ_GFX_DUSCLOPS;
        else
            objGfx2 = EVENT_OBJ_GFX_KIRLIA;
        setObjGfx2 = TRUE;
        break;
    case PIKE_ROOM_HEAL_PART:
        objGfx1 = EVENT_OBJ_GFX_GENTLEMAN;
        break;
    case PIKE_ROOM_WILD_MONS:
        setObjGfx1 = FALSE;
        break;
    case PIKE_ROOM_HARD_BATTLE:
        PrepareOneTrainer(TRUE);
        objGfx2 = EVENT_OBJ_GFX_LINK_RECEPTIONIST;
        setObjGfx1 = FALSE;
        setObjGfx2 = TRUE;
        break;
    case PIKE_ROOM_DOUBLE_BATTLE:
        PrepareTwoTrainers();
        setObjGfx1 = FALSE;
        break;
    case PIKE_ROOM_BRAIN:
        SetFrontierBrainEventObjGfx(FRONTIER_FACILITY_PIKE);
        objGfx2 = EVENT_OBJ_GFX_LINK_RECEPTIONIST;
        setObjGfx1 = FALSE;
        setObjGfx2 = TRUE;
        break;
    default:
        return;
    }

    if (setObjGfx1 == TRUE)
        VarSet(VAR_OBJ_GFX_ID_0, objGfx1);
    if (setObjGfx2 == TRUE)
        VarSet(VAR_OBJ_GFX_ID_1, objGfx2);
}

static void GetBattlePikeData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E02;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeWinStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeTotalStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case 4:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x800;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x400;
        break;
    }
}

static void SetBattlePikeData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E02 = gSpecialVar_0x8006;
        break;
    case 1:
        if (gSpecialVar_0x8006 <= 9999)
            gSaveBlock2Ptr->frontier.pikeWinStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006 <= 9999 && gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode] < gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case 3:
        if (gSpecialVar_0x8006 <= 9999)
            gSaveBlock2Ptr->frontier.pikeTotalStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case 4:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x800;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x800);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x400;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x400);
        }
        break;
    }
}

static void GetInFinalRoom(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum > 14)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static void GetRoomType(void)
{
    gSpecialVar_Result = sRoomType;
}

static void sub_81A7400(void)
{
    sUnknown_0300128E = TRUE;
}

static void sub_81A740C(void)
{
    sUnknown_0300128E = FALSE;
}

static void sub_81A7418(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    save_serialize_map();
    TrySavingData(SAVE_LINK);
}

static void nullsub_76(void)
{

}

static void nullsub_124(void)
{

}

static void GetRoomInflictedStatus(void)
{
    switch (sStatusFlags)
    {
    case STATUS1_FREEZE:
        gSpecialVar_Result = 0;
        break;
    case STATUS1_BURN:
        gSpecialVar_Result = 1;
        break;
    case STATUS1_TOXIC_POISON:
        gSpecialVar_Result = 2;
        break;
    case STATUS1_PARALYSIS:
        gSpecialVar_Result = 3;
        break;
    case STATUS1_SLEEP:
        gSpecialVar_Result = 4;
        break;
    }
}

static void GetRoomInflictedStatusMon(void)
{
    gSpecialVar_Result = sStatusMon;
}

static void HealOneOrTwoMons(void)
{
    u16 toHeal = (Random() % 2) + 1;
    TryHealMons(toHeal);
    gSpecialVar_Result = toHeal;
}

static void BufferNPCMessage(void)
{
    int speechId;

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 4)
        speechId = sNPCTable[sNpcId].speechId1;
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 10)
        speechId = sNPCTable[sNpcId].speechId2;
    else
        speechId = sNPCTable[sNpcId].speechId3;

    FrontierSpeechToString(sNPCSpeeches[speechId]);
}

static void StatusInflictionScreenFade(void)
{
    CreateTask(Task_DoStatusInflictionScreenFade, 2);
}

static void HealMon(struct Pokemon *mon)
{
    u8 i;
    u16 hp;
    u8 ppBonuses;
    u8 data[4];

    for (i = 0; i < 4; i++)
        data[i] = 0;

    hp = GetMonData(mon, MON_DATA_MAX_HP);
    data[0] = hp;
    data[1] = hp >> 8;
    SetMonData(mon, MON_DATA_HP, data);

    ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 move = GetMonData(mon, MON_DATA_MOVE1 + i);
        data[0] = CalculatePPWithBonus(move, ppBonuses, i);
        SetMonData(mon, MON_DATA_PP1 + i, data);
    }

    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    SetMonData(mon, MON_DATA_STATUS, data);
}

static bool8 DoesAbilityPreventStatus(struct Pokemon *mon, u32 status)
{
    u8 ability = GetMonAbility(mon);
    bool8 ret = FALSE;

    switch (status)
    {
    case STATUS1_FREEZE:
        if (ability == ABILITY_MAGMA_ARMOR)
            ret = TRUE;
        break;
    case STATUS1_BURN:
        if (ability == ABILITY_WATER_VEIL)
            ret = TRUE;
        break;
    case STATUS1_PARALYSIS:
        if (ability == ABILITY_LIMBER)
            ret = TRUE;
        break;
    case STATUS1_SLEEP:
        if (ability == ABILITY_INSOMNIA || ability == ABILITY_VITAL_SPIRIT)
            ret = TRUE;
        break;
    case STATUS1_TOXIC_POISON:
        if (ability == ABILITY_IMMUNITY)
            ret = TRUE;
        break;
    }
    return ret;
}

static bool8 DoesTypePreventStatus(u16 species, u32 status)
{
    bool8 ret = FALSE;

    switch (status)
    {
    case STATUS1_TOXIC_POISON:
        if (gBaseStats[species].type1 == TYPE_STEEL || gBaseStats[species].type1 == TYPE_POISON
            || gBaseStats[species].type2 == TYPE_STEEL || gBaseStats[species].type2 == TYPE_POISON)
            ret = TRUE;
        break;
    case STATUS1_FREEZE:
        if (gBaseStats[species].type1 == TYPE_ICE || gBaseStats[species].type2 == TYPE_ICE)
            ret = TRUE;
        break;
    case STATUS1_PARALYSIS:
        if (gBaseStats[species].type1 == TYPE_GROUND || gBaseStats[species].type1 == TYPE_ELECTRIC
            || gBaseStats[species].type2 == TYPE_GROUND || gBaseStats[species].type2 == TYPE_ELECTRIC)
            ret = TRUE;
        break;
    case STATUS1_BURN:
        if (gBaseStats[species].type1 == TYPE_FIRE || gBaseStats[species].type2 == TYPE_FIRE)
            ret = TRUE;
        break;
    case STATUS1_SLEEP:
        break;
    }
    return ret;
}

static bool8 TryInflictRandomStatus(void)
{
    u8 j, i;
    u8 count;
    u8 indices[3];
    u32 status;
    u16 species;
    bool8 statusChosen;
    struct Pokemon *mon;

    for (i = 0; i < 3; i++)
        indices[i] = i;
    for (j = 0; j < 10; j++)
    {
        u8 temp, id;

        i = Random() % 3;
        id = Random() % 3;
        SWAP(indices[i], indices[id], temp);
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 4)
        count = 1;
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 9)
        count = 2;
    else
        count = 3;

    status = 0;
    do
    {
        u8 rand;

        statusChosen = FALSE;
        rand = Random() % 100;

        if (rand < 35)
            sStatusFlags = STATUS1_TOXIC_POISON;
        else if (rand < 60)
            sStatusFlags = STATUS1_FREEZE;
        else if (rand < 80)
            sStatusFlags = STATUS1_PARALYSIS;
        else if (rand < 90)
            sStatusFlags = STATUS1_SLEEP;
        else
            sStatusFlags = STATUS1_BURN;

        if (status != sStatusFlags)
        {
            status = sStatusFlags;
            j = 0;
            for (i = 0; i < 3; i++)
            {
                mon = &gPlayerParty[indices[i]];
                if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0
                    && GetMonData(mon, MON_DATA_HP) != 0)
                {
                    j++;
                    species = GetMonData(mon, MON_DATA_SPECIES);
                    if (!DoesTypePreventStatus(species, sStatusFlags))
                    {
                        statusChosen = TRUE;
                        break;
                    }
                }
                if (j == count)
                    break;
            }
            if (j == 0)
                return FALSE;
        }
    } while (!statusChosen);

    switch (sStatusFlags)
    {
    case STATUS1_FREEZE:
        sStatusMon = PIKE_STATUS_DUSCLOPS;
        break;
    case STATUS1_BURN:
        if (Random() % 2 != 0)
            sStatusMon = PIKE_STATUS_DUSCLOPS;
        else
            sStatusMon = PIKE_STATUS_KIRLIA;
        break;
    case STATUS1_PARALYSIS:
    case STATUS1_SLEEP:
    case STATUS1_TOXIC_POISON:
    default:
        sStatusMon = PIKE_STATUS_KIRLIA;
        break;
    }

    j = 0;
    for (i = 0; i < 3; i++)
    {
        mon = &gPlayerParty[indices[i]];
        if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0
            && GetMonData(mon, MON_DATA_HP) != 0)
        {
            j++;
            species = GetMonData(mon, MON_DATA_SPECIES);
            if (!DoesAbilityPreventStatus(mon, sStatusFlags) && !DoesTypePreventStatus(species, sStatusFlags))
                SetMonData(mon, MON_DATA_STATUS, &sStatusFlags);
        }
        if (j == count)
            break;
    }

    return TRUE;
}

static bool8 AtLeastOneHealthyMon(void)
{
    u8 i;
    u8 healthyMonsCount;
    u8 count;

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 4)
        count = 1;
    else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 9)
        count = 2;
    else
        count = 3;

    healthyMonsCount = 0;
    for (i = 0; i < 3; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0
            && GetMonData(mon, MON_DATA_HP) != 0)
        {
            healthyMonsCount++;
        }
        if (healthyMonsCount == count)
            break;
    }

    if (healthyMonsCount == 0)
        return FALSE;
    else
        return TRUE;
}

static u8 GetNextRoomType(void)
{
    u8 roomTypesAvailability[8];
    u8 i;
    u8 nextRoomType;
    u8 roomTypeGroup;
    u8 numRoomCandidates;
    u8 *roomCandidates;
    u8 id;

    if (gSaveBlock2Ptr->frontier.pikeHintedRoomType == PIKE_ROOM_BRAIN)
        return gSaveBlock2Ptr->frontier.pikeHintedRoomType;

    // Check if the player walked into the same room that the lady gave a hint about.
    if (gSpecialVar_0x8007 == gSaveBlock2Ptr->frontier.pikeHintedRoomIndex)
    {
        if (gSaveBlock2Ptr->frontier.pikeHintedRoomType == PIKE_ROOM_STATUS)
            TryInflictRandomStatus();
        return gSaveBlock2Ptr->frontier.pikeHintedRoomType;
    }

    for (i = 0; i < 8; i++)
        roomTypesAvailability[i] = 0;

    numRoomCandidates = 8;

    // The room types associated with the lady's hint cannot be in the other two rooms.
    roomTypeGroup = sRoomTypeHints[gSaveBlock2Ptr->frontier.pikeHintedRoomType];
    for (i = 0; i < 8; i++)
    {
        if (sRoomTypeHints[i] == roomTypeGroup)
        {
            roomTypesAvailability[i] = 1;
            numRoomCandidates--;
        }
    }

    // Remove room type candidates that would have no effect on the player's party.
    if (roomTypesAvailability[PIKE_ROOM_DOUBLE_BATTLE] != 1 && !AtLeastTwoAliveMons())
    {
        roomTypesAvailability[PIKE_ROOM_DOUBLE_BATTLE] = 1;
        numRoomCandidates--;
    }
    if (roomTypesAvailability[PIKE_ROOM_STATUS] != 1 && !AtLeastOneHealthyMon())
    {
        roomTypesAvailability[PIKE_ROOM_STATUS] = 1;
        numRoomCandidates--;
    }

    // Remove healing room type candidates if healing rooms are disabled.
    if (gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled)
    {
        if (roomTypesAvailability[PIKE_ROOM_HEAL_FULL] != 1)
        {
            roomTypesAvailability[PIKE_ROOM_HEAL_FULL] = 1;
            numRoomCandidates--;
        }
        if (roomTypesAvailability[PIKE_ROOM_HEAL_PART] != 1)
        {
            roomTypesAvailability[PIKE_ROOM_HEAL_PART] = 1;
            numRoomCandidates--;
        }
    }

    roomCandidates = AllocZeroed(numRoomCandidates);
    id = 0;
    for (i = 0; i < 8; i++)
    {
        if (roomTypesAvailability[i] == 0)
            roomCandidates[id++] = i;
    }

    nextRoomType = roomCandidates[Random() % numRoomCandidates];
    free(roomCandidates);
    if (nextRoomType == PIKE_ROOM_STATUS)
        TryInflictRandomStatus();

    return nextRoomType;
}

static u16 GetNPCRoomGraphicsId(void)
{
    sNpcId = Random() % ARRAY_COUNT(sNPCTable);
    return sNPCTable[sNpcId].graphicsId;
}

static u8 sub_81A7B84(void)
{
    return sUnknown_0300128E;
}

bool32 TryGenerateBattlePikeWildMon(bool8 checkKeenEyeIntimidate)
{
    s32 i;
    s32 monLevel;
    u8 headerId = GetBattlePikeWildMonHeaderId();
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    const struct PikeWildMon *const *const wildMons = sWildMons[lvlMode];
    u32 abilityBit;
    s32 pikeMonId = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL);
    pikeMonId = SpeciesToPikeMonId(pikeMonId);

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
    {
        monLevel = GetHighestLevelInPlayerParty();
        if (monLevel < 60)
        {
            monLevel = 60;
        }
        else
        {
            monLevel -= wildMons[headerId][pikeMonId].levelDelta;
            if (monLevel < 60)
                monLevel = 60;
        }
    }
    else
    {
        monLevel = 50 - wildMons[headerId][pikeMonId].levelDelta;
    }

    if (checkKeenEyeIntimidate == TRUE && !CanEncounterWildMon(monLevel))
        return FALSE;

    SetMonData(&gEnemyParty[0],
               MON_DATA_EXP,
               &gExperienceTables[gBaseStats[wildMons[headerId][pikeMonId].species].growthRate][monLevel]);

    if (gBaseStats[wildMons[headerId][pikeMonId].species].ability2)
        abilityBit = Random() % 2;
    else
        abilityBit = 0;
    SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityBit);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(&gEnemyParty[0], wildMons[headerId][pikeMonId].moves[i], i);

    CalculateMonStats(&gEnemyParty[0]);
    return TRUE;
}

u8 GetBattlePikeWildMonHeaderId(void)
{
    u8 headerId;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];

    if (winStreak <= 280)
        headerId = 0;
    else if (winStreak <= 560)
        headerId = 1;
    else if (winStreak <= 840)
        headerId = 2;
    else
        headerId = 3;

    return headerId;
}

static void DoStatusInflictionScreenFade(u8 taskId)
{
    while (sStatusInflictionScreenFadeFuncs[gTasks[taskId].data[0]](&gTasks[taskId]));
}

static bool8 StatusInflictionFadeOut(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[1];
        task->data[7] += task->data[4];
        if (task->data[7] > 16)
            task->data[7] = 16;
        BlendPalettes(0xFFFFFFFF, task->data[7], RGB(11, 11, 11));
    }

    if (task->data[7] >= 16)
    {
        task->data[0]++;
        task->data[6] = task->data[2];
    }
    return FALSE;
}

static bool8 StatusInflictionFadeIn(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[2];
        task->data[7] -= task->data[5];
        if (task->data[7] < 0)
            task->data[7] = 0;
        BlendPalettes(0xFFFFFFFF, task->data[7], RGB(11, 11, 11));
    }

    if (task->data[7] == 0)
    {
        if (--task->data[3] == 0)
        {
            DestroyTask(FindTaskIdByFunc(DoStatusInflictionScreenFade));
        }
        else
        {
            task->data[6] = task->data[1];
            task->data[0] = 0;
        }
    }
    return FALSE;
}

static void StartStatusInflictionScreenFade(s16 fadeOutDelay, s16 fadeInDelay, s16 numFades, s16 fadeOutSpeed, s16 fadeInSpped)
{
    u8 taskId = CreateTask(DoStatusInflictionScreenFade, 3);

    gTasks[taskId].data[1] = fadeOutDelay;
    gTasks[taskId].data[2] = fadeInDelay;
    gTasks[taskId].data[3] = numFades;
    gTasks[taskId].data[4] = fadeOutSpeed;
    gTasks[taskId].data[5] = fadeInSpped;
    gTasks[taskId].data[6] = fadeOutDelay;
}

static bool8 IsStatusInflictionScreenFadeTaskFinished(void)
{
    if (FindTaskIdByFunc(DoStatusInflictionScreenFade) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

static void Task_DoStatusInflictionScreenFade(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[0]++;
        StartStatusInflictionScreenFade(0, 0, 3, 2, 2);
    }
    else
    {
        if (IsStatusInflictionScreenFadeTaskFinished())
        {
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
    }
}

static void TryHealMons(u8 healCount)
{
    u8 j, i, k;
    u8 indices[3];

    if (healCount == 0)
        return;

    for (i = 0; i < 3; i++)
        indices[i] = i;
    for (k = 0; k < 10; k++)
    {
        u8 temp;

        i = Random() % 3;
        j = Random() % 3;
        SWAP(indices[i], indices[j], temp);
    }

    for (i = 0; i < 3; i++)
    {
        bool32 canBeHealed = FALSE;
        struct Pokemon *mon = &gPlayerParty[indices[i]];
        u16 curr = GetMonData(mon, MON_DATA_HP);
        u16 max = GetMonData(mon, MON_DATA_MAX_HP);
        if (curr < max)
        {
            canBeHealed = TRUE;
        }
        else if (pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) != 0)
        {
            canBeHealed = TRUE;
        }
        else
        {
            u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 move = GetMonData(mon, MON_DATA_MOVE1 + j);
                max = CalculatePPWithBonus(move, ppBonuses, j);
                curr = GetMonData(mon, MON_DATA_PP1 + j);
                if (curr < max)
                {
                    canBeHealed = TRUE;
                    break;
                }
            }
        }

        if (canBeHealed == TRUE)
        {
            HealMon(&gPlayerParty[indices[i]]);
            if (--healCount == 0)
                break;
        }
    }
}

static void GetInBattlePike(void)
{
    gSpecialVar_Result = InBattlePike();
}

bool8 InBattlePike(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM1
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM3
        || gMapHeader.mapLayoutId == LAYOUT_UNKNOWN_084693AC;
}

static void SetHintedRoom(void)
{
    u8 i, count, id;
    u8 *roomCandidates;

    gSpecialVar_Result = 0;
    if (GetPikeQueenFightType(1))
    {
        gSpecialVar_Result = 1;
        gSaveBlock2Ptr->frontier.pikeHintedRoomIndex = Random() % 6;
        gSaveBlock2Ptr->frontier.pikeHintedRoomType = PIKE_ROOM_BRAIN;
    }
    else
    {
        gSaveBlock2Ptr->frontier.pikeHintedRoomIndex = Random() % 3;
        if (gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled)
            count = 6;
        else
            count = 8;

        roomCandidates = AllocZeroed(count);
        for (i = 0, id = 0; i < count; i++)
        {
            if (gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled)
            {
                if (i != PIKE_ROOM_HEAL_FULL && i != PIKE_ROOM_HEAL_PART)
                    roomCandidates[id++] = i;
            }
            else
            {
                roomCandidates[i] = i;
            }
        }

        gSaveBlock2Ptr->frontier.pikeHintedRoomType = roomCandidates[Random() % count];
        free(roomCandidates);
        if (gSaveBlock2Ptr->frontier.pikeHintedRoomType == PIKE_ROOM_STATUS && !AtLeastOneHealthyMon())
            gSaveBlock2Ptr->frontier.pikeHintedRoomType = PIKE_ROOM_NPC;
        if (gSaveBlock2Ptr->frontier.pikeHintedRoomType == PIKE_ROOM_DOUBLE_BATTLE && !AtLeastTwoAliveMons())
            gSaveBlock2Ptr->frontier.pikeHintedRoomType = PIKE_ROOM_NPC;
    }
}

static void GetHintedRoomIndex(void)
{
    // 0 = left room
    // 1 = center room
    // 2 = right room
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeHintedRoomIndex;
}

static void GetRoomTypeHint(void)
{
    gSpecialVar_Result = sRoomTypeHints[gSaveBlock2Ptr->frontier.pikeHintedRoomType];
}

static void PrepareOneTrainer(bool8 difficult)
{
    int i;
    u8 lvlMode;
    u8 battleNum;
    u16 challengeNum;
    u16 trainerId;

    if (!difficult)
        battleNum = 1;
    else
        battleNum = 6;

    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / 14;
    do
    {
        trainerId = sub_8162548(challengeNum, battleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1);

    gTrainerBattleOpponent_A = trainerId;
    gFacilityTrainers = gBattleFrontierTrainers;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 14)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1] = gTrainerBattleOpponent_A;
}

static void PrepareTwoTrainers(void)
{
    int i;
    u16 trainerId;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / 14;

    gFacilityTrainers = gBattleFrontierTrainers;
    do
    {
        trainerId = sub_8162548(challengeNum, 1);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1);

    gTrainerBattleOpponent_A = trainerId;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum <= 14)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1] = gTrainerBattleOpponent_A;

    do
    {
        trainerId = sub_8162548(challengeNum, 1);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    gTrainerBattleOpponent_B = trainerId;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_B, 1);
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 14)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum - 2] = gTrainerBattleOpponent_B;
}

static void ClearPikeTrainerIds(void)
{
    u8 i;

    for (i = 0; i < 14; i++)
        gSaveBlock2Ptr->frontier.trainerIds[i] = 0xFFFF;
}

static void BufferRecordMixingTrainerMessage(void)
{
    if (gSpecialVar_0x8005 == 0)
    {
        if (gTrainerBattleOpponent_A < TRAINER_RECORD_MIXING_FRIEND)
            FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
    }
    else if (gSpecialVar_0x8005 == 1)
    {
        if (gTrainerBattleOpponent_B < TRAINER_RECORD_MIXING_FRIEND)
            FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_B].speechBefore);
    }
}

static bool8 AtLeastTwoAliveMons(void)
{
    struct Pokemon *mon;
    u8 i, countDead;

    mon = &gPlayerParty[0];
    countDead = 0;
    for (i = 0; i < 3; i++, mon++)
    {
        if (GetMonData(mon, MON_DATA_HP) == 0)
            countDead++;
    }

    if (countDead >= 2)
        return FALSE;
    else
        return TRUE;
}

static u8 GetPikeQueenFightType(u8 nextRoom)
{
    u8 numPikeSymbols;

    u8 var = 5;
    u8 ret = 0;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    winStreak += nextRoom;
    numPikeSymbols = GetPlayerSymbolCountForFacility(FRONTIER_FACILITY_PIKE);

    switch (numPikeSymbols)
    {
    case 0:
    case 1:
        if (winStreak == sPikeQueenWinStreakAppearances[var][numPikeSymbols] - sPikeQueenWinStreakAppearances[var][3])
            ret = numPikeSymbols + 1;
        break;
    case 2:
    default:
        if (winStreak == sPikeQueenWinStreakAppearances[var][0] - sPikeQueenWinStreakAppearances[var][3])
            ret = 3;
        else if (winStreak == sPikeQueenWinStreakAppearances[var][1] - sPikeQueenWinStreakAppearances[var][3]
                 || (winStreak > sPikeQueenWinStreakAppearances[var][1]
                     && (winStreak - sPikeQueenWinStreakAppearances[var][1] + sPikeQueenWinStreakAppearances[var][3]) % sPikeQueenWinStreakAppearances[var][2] == 0))
            ret = 4;
        break;
    }

    return ret;
}

static void GetCurrentRoomPikeQueenFightType(void)
{
    gSpecialVar_Result = GetPikeQueenFightType(0);
}

static void HealSomeMonsBeforePikeQueen(void)
{
    u8 toHealCount = sNumMonsToHealBeforePikeQueen[gSaveBlock2Ptr->frontier.pikeHintedRoomIndex][gSpecialVar_0x8007];

    TryHealMons(toHealCount);
    gSpecialVar_Result = toHealCount;
}

static void SetHealingRoomsDisabled(void)
{
    gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled = gSpecialVar_0x8005;
}

static void CanAnyPartyMonsBeHealed(void)
{
    u8 i, j;

    gSpecialVar_Result = TRUE;
    for (i = 0; i < 3; i++)
    {
        bool32 canBeHealed = FALSE;
        struct Pokemon *mon = &gPlayerParty[i];
        u16 curr = GetMonData(mon, MON_DATA_HP);
        u16 max = GetMonData(mon, MON_DATA_MAX_HP);
        if (curr >= max && pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS)) == 0)
        {
            u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 move = GetMonData(mon, MON_DATA_MOVE1 + j);
                max = CalculatePPWithBonus(move, ppBonuses, j);
                curr = GetMonData(mon, MON_DATA_PP1 + j);
                if (curr < max)
                {
                    canBeHealed = TRUE;
                    break;
                }
            }
        }
        else
        {
            canBeHealed = TRUE;
        }

        if (canBeHealed == TRUE)
        {
            gSpecialVar_Result = FALSE;
            break;
        }
    }
}

static void BackupMonHeldItems(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        int heldItem = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1],
                                  MON_DATA_HELD_ITEM);
        gSaveBlock2Ptr->frontier.pikeHeldItemsBackup[i] = heldItem;
    }
}

static void RestoreMonHeldItems(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        SetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1],
                   MON_DATA_HELD_ITEM,
                   &gSaveBlock2Ptr->frontier.pikeHeldItemsBackup[i]);
    }
}

static void InitPikeChallenge(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_08612690[lvlMode]))
        gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] = 0;

    gTrainerBattleOpponent_A = 0;
    gBattleOutcome = 0;
}

static bool8 CanEncounterWildMon(u8 enemyMonLevel)
{
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u8 monAbility = GetMonAbility(&gPlayerParty[0]);
        if (monAbility == ABILITY_KEEN_EYE || monAbility == ABILITY_INTIMIDATE)
        {
            u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
            if (playerMonLevel > 5 && enemyMonLevel <= playerMonLevel - 5 && Random() % 2 == 0)
                return FALSE;
        }
    }

    return TRUE;
}

static u8 SpeciesToPikeMonId(u16 species)
{
    u8 ret;

    if (species == SPECIES_SEVIPER)
        ret = 0;
    else if (species == SPECIES_MILOTIC)
        ret = 1;
    else
        ret = 2;

    return ret;
}
