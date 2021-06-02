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
#include "malloc.h"
#include "palette.h"
#include "script.h"
#include "battle_setup.h"
#include "constants/event_objects.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/abilities.h"
#include "constants/battle_config.h"
#include "constants/easy_chat.h"
#include "constants/layouts.h"
#include "constants/rgb.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/battle_pike.h"

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
    u16 moves[MAX_MON_MOVES];
};

// IWRAM bss
static u8 sRoomType;
static u8 sStatusMon;
static bool8 sInWildMonRoom;
static u32 sStatusFlags;
static u8 sNpcId;

// This file's functions.
static void SetRoomType(void);
static void GetBattlePikeData(void);
static void SetBattlePikeData(void);
static void IsNextRoomFinal(void);
static void SetupRoomObjectEvents(void);
static void GetRoomType(void);
static void SetInWildMonRoom(void);
static void ClearInWildMonRoom(void);
static void SavePikeChallenge(void);
static void PikeDummy1(void);
static void PikeDummy2(void);
static void GetRoomInflictedStatus(void);
static void GetRoomInflictedStatusMon(void);
static void HealOneOrTwoMons(void);
static void BufferNPCMessage(void);
static void StatusInflictionScreenFlash(void);
static void GetInBattlePike(void);
static void SetHintedRoom(void);
static void GetHintedRoomIndex(void);
static void GetRoomTypeHint(void);
static void ClearPikeTrainerIds(void);
static void BufferTrainerIntro(void);
static void GetCurrentRoomPikeQueenFightType(void);
static void HealSomeMonsBeforePikeQueen(void);
static void SetHealingroomTypesDisabled(void);
static void IsPartyFullHealed(void);
static void SaveMonHeldItems(void);
static void RestoreMonHeldItems(void);
static void InitPikeChallenge(void);
static u8 GetNextRoomType(void);
static void PrepareOneTrainer(bool8 difficult);
static u16 GetNPCRoomGraphicsId(void);
static void PrepareTwoTrainers(void);
static void TryHealMons(u8 healCount);
static void Task_DoStatusInflictionScreenFlash(u8 taskId);
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
        .graphicsId = OBJ_EVENT_GFX_POKEFAN_F,
        .speechId1 = 3,
        .speechId2 = 5,
        .speechId3 = 6
    },
    {
        .graphicsId = OBJ_EVENT_GFX_NINJA_BOY,
        .speechId1 = 13,
        .speechId2 = 32,
        .speechId3 = 37
    },
    {
        .graphicsId = OBJ_EVENT_GFX_FAT_MAN,
        .speechId1 = 8,
        .speechId2 = 11,
        .speechId3 = 12
    },
    {
        .graphicsId = OBJ_EVENT_GFX_BUG_CATCHER,
        .speechId1 = 34,
        .speechId2 = 30,
        .speechId3 = 33
    },
    {
        .graphicsId = OBJ_EVENT_GFX_EXPERT_M,
        .speechId1 = 0,
        .speechId2 = 0,
        .speechId3 = 0
    },
    {
        .graphicsId = OBJ_EVENT_GFX_OLD_WOMAN,
        .speechId1 = 1,
        .speechId2 = 1,
        .speechId3 = 1
    },
    {
        .graphicsId = OBJ_EVENT_GFX_BLACK_BELT,
        .speechId1 = 22,
        .speechId2 = 23,
        .speechId3 = 27
    },
    {
        .graphicsId = OBJ_EVENT_GFX_HIKER,
        .speechId1 = 8,
        .speechId2 = 22,
        .speechId3 = 31
    },
    {
        .graphicsId = OBJ_EVENT_GFX_GIRL_3,
        .speechId1 = 13,
        .speechId2 = 39,
        .speechId3 = 21
    },
    {
        .graphicsId = OBJ_EVENT_GFX_WOMAN_2,
        .speechId1 = 2,
        .speechId2 = 4,
        .speechId3 = 17
    },
    {
        .graphicsId = OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,
        .speechId1 = 30,
        .speechId2 = 20,
        .speechId3 = 36
    },
    {
        .graphicsId = OBJ_EVENT_GFX_MAN_5,
        .speechId1 = 28,
        .speechId2 = 34,
        .speechId3 = 25
    },
    {
        .graphicsId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .speechId1 = 23,
        .speechId2 = 38,
        .speechId3 = 26
    },
    {
        .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
        .speechId1 = 23,
        .speechId2 = 30,
        .speechId3 = 11
    },
    {
        .graphicsId = OBJ_EVENT_GFX_LASS,
        .speechId1 = 15,
        .speechId2 = 19,
        .speechId3 = 14
    },
    {
        .graphicsId = OBJ_EVENT_GFX_MANIAC,
        .speechId1 = 2,
        .speechId2 = 29,
        .speechId3 = 26
    },
    {
        .graphicsId = OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
        .speechId1 = 37,
        .speechId2 = 12,
        .speechId3 = 32
    },
    {
        .graphicsId = OBJ_EVENT_GFX_MAN_3,
        .speechId1 = 24,
        .speechId2 = 23,
        .speechId3 = 38
    },
    {
        .graphicsId = OBJ_EVENT_GFX_WOMAN_3,
        .speechId1 = 5,
        .speechId2 = 22,
        .speechId3 = 4
    },
    {
        .graphicsId = OBJ_EVENT_GFX_LITTLE_BOY,
        .speechId1 = 41,
        .speechId2 = 37,
        .speechId3 = 35
    },
    {
        .graphicsId = OBJ_EVENT_GFX_TUBER_F,
        .speechId1 = 39,
        .speechId2 = 14,
        .speechId3 = 13
    },
    {
        .graphicsId = OBJ_EVENT_GFX_GENTLEMAN,
        .speechId1 = 10,
        .speechId2 = 7,
        .speechId3 = 9
    },
    {
        .graphicsId = OBJ_EVENT_GFX_LITTLE_GIRL,
        .speechId1 = 40,
        .speechId2 = 20,
        .speechId3 = 16
    },
    {
        .graphicsId = OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F,
        .speechId1 = 18,
        .speechId2 = 13,
        .speechId3 = 21
    },
    {
        .graphicsId = OBJ_EVENT_GFX_MAN_1,
        .speechId1 = 22,
        .speechId2 = 31,
        .speechId3 = 27
    }
};

static const u16 sNPCSpeeches[][EASY_CHAT_BATTLE_WORDS_COUNT] =
{
    {EC_WORD_I_AM, EC_WORD_LOST, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_MOVE2(HELPING_HAND)},
    {EC_WORD_I_VE, EC_WORD_NO, EC_WORD_SENSE, EC_WORD_OF, EC_WORD_WHERE, EC_WORD_I_AM},
    {EC_WORD_WHAT, EC_WORD_SHOULD, EC_WORD_I, EC_WORD_DO, EC_WORD_NOW, EC_WORD_QUES},
    {EC_WORD_THIS, EC_WORD_IS, EC_WORD_TOO, EC_WORD_EXCITING, EC_WORD_FOR, EC_WORD_ME},
    {EC_WORD_DID, EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_A, EC_WORD_MISTAKE, EC_WORD_QUES},
    {EC_WORD_IT_S, EC_WORD_MEAN, EC_WORD_AND, EC_WORD_AWFUL, EC_WORD_IN, EC_WORD_HERE},
    {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_TIRED, EC_WORD_OF, EC_WORD_THIS, EC_WORD_PLACE},
    {EC_WORD_I, EC_WORD_QUITE, EC_WORD_ENJOY, EC_WORD_THIS, EC_WORD_CHALLENGE, EC_EMPTY_WORD},
    {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_HOW, EC_WORD_I, EC_MOVE2(TACKLE), EC_WORD_THIS},
    {EC_WORD_READY, EC_WORD_TO, EC_WORD_GIVE_UP, EC_WORD_YET, EC_WORD_QUES, EC_EMPTY_WORD},
    {EC_WORD_OH, EC_WORD_NO, EC_WORD_WHO, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_QUES},
    {EC_WORD_I_VE, EC_WORD_BEEN, EC_WORD_WANDERING, EC_WORD_ABOUT, EC_WORD_FOREVER, EC_WORD_ELLIPSIS},
    {EC_WORD_I, EC_WORD_THINK, EC_WORD_I, EC_WORD_WILL, EC_WORD_GIVE_UP, EC_EMPTY_WORD},
    {EC_WORD_WHAT, EC_WORD_SHOULD, EC_WORD_I, EC_WORD_DO, EC_WORD_NEXT, EC_WORD_QUES},
    {EC_WORD_I, EC_WORD_CAN_WIN, EC_WORD_WITH, EC_WORD_MY, EC_MOVE(SHEER_COLD), EC_WORD_GENIUS},
    {EC_WORD_WON_T, EC_WORD_SOMEONE, EC_WORD_COOL, EC_WORD_SHOW, EC_WORD_UP, EC_WORD_QUES},
    {EC_WORD_BATTLE, EC_WORD_GAME, EC_WORD_IS, EC_WORD_AWESOME, EC_WORD_EXCL, EC_EMPTY_WORD},
    {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_TAKE, EC_WORD_THIS, EC_WORD_ANY, EC_WORD_MORE},
    {EC_WORD_I, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_IF, EC_WORD_IT_S, EC_WORD_OKAY},
    {EC_WORD_OH, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_NOT, EC_WORD_ANOTHER, EC_WORD_TRAINER},
    {EC_WORD_IT, EC_WORD_HAS, EC_WORD_TO, EC_WORD_BE, EC_WORD_LEFT, EC_WORD_NEXT},
    {EC_WORD_IT, EC_WORD_MUST_BE, EC_WORD_OVER, EC_WORD_SOON, EC_WORD_RIGHT, EC_WORD_QUES},
    {EC_WORD_THIS, EC_WORD_IS, EC_WORD_TOTALLY, EC_WORD_EASY, EC_WORD_ISN_T_IT_QUES, EC_EMPTY_WORD},
    {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_POWER, EC_WORD_ON, EC_EMPTY_WORD},
    {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NO, EC_WORD_GIVE_UP, EC_WORD_IN, EC_WORD_ME},
    {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_GOING, EC_WORD_TO, EC_WORD_MAKE, EC_WORD_IT},
    {EC_WORD_GO, EC_WORD_ON, EC_WORD_I, EC_WORD_CAN_T, EC_WORD_ANY, EC_WORD_MORE},
    {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_AFTER, EC_WORD_ANOTHER, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
    {EC_WORD_DO, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_STEEL, EC_WORD_POKEMON, EC_WORD_QUES},
    {EC_WORD_EVERY, EC_WORD_TRAINER, EC_WORD_HERE, EC_WORD_IS, EC_WORD_TOO_WEAK, EC_EMPTY_WORD},
    {EC_WORD_YOU, EC_WORD_THINK, EC_WORD_THIS, EC_WORD_IS, EC_WORD_EASY, EC_WORD_QUES},
    {EC_WORD_WHAT, EC_WORD_WILL, EC_WORD_COME, EC_WORD_AFTER, EC_WORD_THIS, EC_WORD_QUES},
    {EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_SO, EC_WORD_CONFUSED, EC_WORD_EXCL, EC_EMPTY_WORD},
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

// Table duplicated from frontier_util, only Battle Pike entry used
static const u8 sFrontierBrainStreakAppearances[NUM_FRONTIER_FACILITIES][4] =
{
    [FRONTIER_FACILITY_TOWER]   = {35,  70, 35, 1},
    [FRONTIER_FACILITY_DOME]    = { 4,   9,  5, 0},
    [FRONTIER_FACILITY_PALACE]  = {21,  42, 21, 1},
    [FRONTIER_FACILITY_ARENA]   = {28,  56, 28, 1},
    [FRONTIER_FACILITY_FACTORY] = {21,  42, 21, 1},
    [FRONTIER_FACILITY_PIKE]    = {28, 140, 56, 1},
    [FRONTIER_FACILITY_PYRAMID] = {21,  70, 35, 0},
};

static void (* const sBattlePikeFunctions[])(void) =
{
    [BATTLE_PIKE_FUNC_SET_ROOM_TYPE]           = SetRoomType,
    [BATTLE_PIKE_FUNC_GET_DATA]                = GetBattlePikeData,
    [BATTLE_PIKE_FUNC_SET_DATA]                = SetBattlePikeData,
    [BATTLE_PIKE_FUNC_IS_FINAL_ROOM]           = IsNextRoomFinal,
    [BATTLE_PIKE_FUNC_SET_ROOM_OBJECTS]        = SetupRoomObjectEvents,
    [BATTLE_PIKE_FUNC_GET_ROOM_TYPE]           = GetRoomType,
    [BATTLE_PIKE_FUNC_SET_IN_WILD_MON_ROOM]    = SetInWildMonRoom,
    [BATTLE_PIKE_FUNC_CLEAR_IN_WILD_MON_ROOM]  = ClearInWildMonRoom,
    [BATTLE_PIKE_FUNC_SAVE]                    = SavePikeChallenge,
    [BATTLE_PIKE_FUNC_DUMMY_1]                 = PikeDummy1,
    [BATTLE_PIKE_FUNC_DUMMY_2]                 = PikeDummy2,
    [BATTLE_PIKE_FUNC_GET_ROOM_STATUS]         = GetRoomInflictedStatus,
    [BATTLE_PIKE_FUNC_GET_ROOM_STATUS_MON]     = GetRoomInflictedStatusMon,
    [BATTLE_PIKE_FUNC_HEAL_ONE_TWO_MONS]       = HealOneOrTwoMons,
    [BATTLE_PIKE_FUNC_BUFFER_NPC_MSG]          = BufferNPCMessage,
    [BATTLE_PIKE_FUNC_STATUS_SCREEN_FLASH]     = StatusInflictionScreenFlash,
    [BATTLE_PIKE_FUNC_IS_IN]                   = GetInBattlePike,
    [BATTLE_PIKE_FUNC_SET_HINT_ROOM]           = SetHintedRoom,
    [BATTLE_PIKE_FUNC_GET_HINT_ROOM_ID]        = GetHintedRoomIndex,
    [BATTLE_PIKE_FUNC_GET_ROOM_TYPE_HINT]      = GetRoomTypeHint,
    [BATTLE_PIKE_FUNC_CLEAR_TRAINER_IDS]       = ClearPikeTrainerIds,
    [BATTLE_PIKE_FUNC_GET_TRAINER_INTRO]       = BufferTrainerIntro,
    [BATTLE_PIKE_FUNC_GET_QUEEN_FIGHT_TYPE]    = GetCurrentRoomPikeQueenFightType,
    [BATTLE_PIKE_FUNC_HEAL_MONS_BEFORE_QUEEN]  = HealSomeMonsBeforePikeQueen,
    [BATTLE_PIKE_FUNC_SET_HEAL_ROOMS_DISABLED] = SetHealingroomTypesDisabled,
    [BATTLE_PIKE_FUNC_IS_PARTY_FULL_HEALTH]    = IsPartyFullHealed,
    [BATTLE_PIKE_FUNC_SAVE_HELD_ITEMS]         = SaveMonHeldItems,
    [BATTLE_PIKE_FUNC_RESET_HELD_ITEMS]        = RestoreMonHeldItems,
    [BATTLE_PIKE_FUNC_INIT]                    = InitPikeChallenge
};

static const u8 sRoomTypeHints[] = {
    PIKE_HINT_PEOPLE,     // PIKE_ROOM_SINGLE_BATTLE
    PIKE_HINT_PEOPLE,     // PIKE_ROOM_HEAL_FULL
    PIKE_HINT_WHISPERING, // PIKE_ROOM_NPC
    PIKE_HINT_NOSTALGIA,  // PIKE_ROOM_STATUS
    PIKE_HINT_NOSTALGIA,  // PIKE_ROOM_HEAL_PART
    PIKE_HINT_POKEMON,    // PIKE_ROOM_WILD_MONS
    PIKE_HINT_POKEMON,    // PIKE_ROOM_HARD_BATTLE
    PIKE_HINT_WHISPERING, // PIKE_ROOM_DOUBLE_BATTLE
    PIKE_HINT_BRAIN,      // PIKE_ROOM_BRAIN
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

static bool8 (* const sStatusInflictionScreenFlashFuncs[])(struct Task *) =
{
    StatusInflictionFadeOut, StatusInflictionFadeIn
};

static const u32 sWinStreakFlags[] = {STREAK_PIKE_50, STREAK_PIKE_OPEN};

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

static void SetupRoomObjectEvents(void)
{
    bool32 setObjGfx1, setObjGfx2;
    u32 objGfx1;
    u16 objGfx2;

    VarSet(VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LINK_RECEPTIONIST);
    VarSet(VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_DUSCLOPS);
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
        objGfx1 = OBJ_EVENT_GFX_LINK_RECEPTIONIST;
        break;
    case PIKE_ROOM_NPC:
        objGfx1 = (u8)(GetNPCRoomGraphicsId());
        break;
    case PIKE_ROOM_STATUS:
        objGfx1 = OBJ_EVENT_GFX_GENTLEMAN;
        if (sStatusMon == PIKE_STATUSMON_DUSCLOPS)
            objGfx2 = OBJ_EVENT_GFX_DUSCLOPS;
        else
            objGfx2 = OBJ_EVENT_GFX_KIRLIA;
        setObjGfx2 = TRUE;
        break;
    case PIKE_ROOM_HEAL_PART:
        objGfx1 = OBJ_EVENT_GFX_GENTLEMAN;
        break;
    case PIKE_ROOM_WILD_MONS:
        setObjGfx1 = FALSE;
        break;
    case PIKE_ROOM_HARD_BATTLE:
        PrepareOneTrainer(TRUE);
        objGfx2 = OBJ_EVENT_GFX_LINK_RECEPTIONIST;
        setObjGfx1 = FALSE;
        setObjGfx2 = TRUE;
        break;
    case PIKE_ROOM_DOUBLE_BATTLE:
        PrepareTwoTrainers();
        setObjGfx1 = FALSE;
        break;
    case PIKE_ROOM_BRAIN:
        SetFrontierBrainObjEventGfx(FRONTIER_FACILITY_PIKE);
        objGfx2 = OBJ_EVENT_GFX_LINK_RECEPTIONIST;
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
    case PIKE_DATA_PRIZE:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikePrize;
        break;
    case PIKE_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeWinStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case PIKE_DATA_RECORD_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case PIKE_DATA_TOTAL_STREAKS:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pikeTotalStreaks[gSaveBlock2Ptr->frontier.lvlMode];
        break;
    case PIKE_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_PIKE_OPEN;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_PIKE_50;
        break;
    }
}

static void SetBattlePikeData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case PIKE_DATA_PRIZE:
        gSaveBlock2Ptr->frontier.pikePrize = gSpecialVar_0x8006;
        break;
    case PIKE_DATA_WIN_STREAK:
        if (gSpecialVar_0x8006 <= MAX_STREAK)
            gSaveBlock2Ptr->frontier.pikeWinStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case PIKE_DATA_RECORD_STREAK:
        if (gSpecialVar_0x8006 <= MAX_STREAK && gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode] < gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.pikeRecordStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case PIKE_DATA_TOTAL_STREAKS:
        if (gSpecialVar_0x8006 <= MAX_STREAK)
            gSaveBlock2Ptr->frontier.pikeTotalStreaks[gSaveBlock2Ptr->frontier.lvlMode] = gSpecialVar_0x8006;
        break;
    case PIKE_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_PIKE_OPEN;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~(STREAK_PIKE_OPEN);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_PIKE_50;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~(STREAK_PIKE_50);
        }
        break;
    }
}

static void IsNextRoomFinal(void)
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

static void SetInWildMonRoom(void)
{
    sInWildMonRoom = TRUE;
}

static void ClearInWildMonRoom(void)
{
    sInWildMonRoom = FALSE;
}

static void SavePikeChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveMapView();
    TrySavingData(SAVE_LINK);
}

static void PikeDummy1(void)
{

}

static void PikeDummy2(void)
{

}

static void GetRoomInflictedStatus(void)
{
    switch (sStatusFlags)
    {
    case STATUS1_FREEZE:
        gSpecialVar_Result = PIKE_STATUS_FREEZE;
        break;
    case STATUS1_BURN:
        gSpecialVar_Result = PIKE_STATUS_BURN;
        break;
    case STATUS1_TOXIC_POISON:
        gSpecialVar_Result = PIKE_STATUS_TOXIC;
        break;
    case STATUS1_PARALYSIS:
        gSpecialVar_Result = PIKE_STATUS_PARALYSIS;
        break;
    case STATUS1_SLEEP:
        gSpecialVar_Result = PIKE_STATUS_SLEEP;
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

static void StatusInflictionScreenFlash(void)
{
    CreateTask(Task_DoStatusInflictionScreenFlash, 2);
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
    u16 ability = GetMonAbility(mon);
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
        if (gBaseStats[species].type1 == TYPE_GROUND || gBaseStats[species].type2 == TYPE_GROUND
            || (B_PARALYZE_ELECTRIC >= GEN_6 &&
                (gBaseStats[species].type1 == TYPE_ELECTRIC || gBaseStats[species].type2 == TYPE_ELECTRIC)))
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
    u8 indices[FRONTIER_PARTY_SIZE];
    u32 status;
    u16 species;
    bool8 statusChosen;
    struct Pokemon *mon;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        indices[i] = i;
    for (j = 0; j < 10; j++)
    {
        u8 temp, id;

        i = Random() % FRONTIER_PARTY_SIZE;
        id = Random() % FRONTIER_PARTY_SIZE;
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
            for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            {
                mon = &gPlayerParty[indices[i]];
                if (GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS)) == AILMENT_NONE
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
        sStatusMon = PIKE_STATUSMON_DUSCLOPS;
        break;
    case STATUS1_BURN:
        if (Random() % 2 != 0)
            sStatusMon = PIKE_STATUSMON_DUSCLOPS;
        else
            sStatusMon = PIKE_STATUSMON_KIRLIA;
        break;
    case STATUS1_PARALYSIS:
    case STATUS1_SLEEP:
    case STATUS1_TOXIC_POISON:
    default:
        sStatusMon = PIKE_STATUSMON_KIRLIA;
        break;
    }

    j = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[indices[i]];
        if (GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS)) == AILMENT_NONE
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
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS)) == AILMENT_NONE
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
    bool8 roomTypesDisabled[NUM_PIKE_ROOM_TYPES - 1]; // excludes Brain room, which cant be disabled
    u8 i;
    u8 nextRoomType;
    u8 roomHint;
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

    for (i = 0; i < ARRAY_COUNT(roomTypesDisabled); i++)
        roomTypesDisabled[i] = FALSE;

    numRoomCandidates = NUM_PIKE_ROOM_TYPES - 1;

    // The other two room types cannot be the same type as the one associated with the lady's hint
    roomHint = sRoomTypeHints[gSaveBlock2Ptr->frontier.pikeHintedRoomType];
    for (i = 0; i < ARRAY_COUNT(roomTypesDisabled); i++)
    {
        if (sRoomTypeHints[i] == roomHint)
        {
            roomTypesDisabled[i] = TRUE;
            numRoomCandidates--;
        }
    }

    // Remove room type candidates that would have no effect on the player's party.
    if (roomTypesDisabled[PIKE_ROOM_DOUBLE_BATTLE] != TRUE && !AtLeastTwoAliveMons())
    {
        roomTypesDisabled[PIKE_ROOM_DOUBLE_BATTLE] = TRUE;
        numRoomCandidates--;
    }
    if (roomTypesDisabled[PIKE_ROOM_STATUS] != TRUE && !AtLeastOneHealthyMon())
    {
        roomTypesDisabled[PIKE_ROOM_STATUS] = TRUE;
        numRoomCandidates--;
    }

    // Remove healing room type candidates if healing rooms are disabled.
    if (gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled)
    {
        if (roomTypesDisabled[PIKE_ROOM_HEAL_FULL] != TRUE)
        {
            roomTypesDisabled[PIKE_ROOM_HEAL_FULL] = TRUE;
            numRoomCandidates--;
        }
        if (roomTypesDisabled[PIKE_ROOM_HEAL_PART] != TRUE)
        {
            roomTypesDisabled[PIKE_ROOM_HEAL_PART] = TRUE;
            numRoomCandidates--;
        }
    }

    roomCandidates = AllocZeroed(numRoomCandidates);
    id = 0;
    for (i = 0; i < ARRAY_COUNT(roomTypesDisabled); i++)
    {
        if (roomTypesDisabled[i] == FALSE)
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

// Unused
static u8 GetInWildMonRoom(void)
{
    return sInWildMonRoom;
}

bool32 TryGenerateBattlePikeWildMon(bool8 checkKeenEyeIntimidate)
{
    s32 i;
    s32 monLevel;
    u8 headerId = GetBattlePikeWildMonHeaderId();
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    const struct PikeWildMon *const *const wildMons = sWildMons[lvlMode];
    u32 abilityNum;
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

    if (gBaseStats[wildMons[headerId][pikeMonId].species].abilities[1])
        abilityNum = Random() % 2;
    else
        abilityNum = 0;
    SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
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

static void DoStatusInflictionScreenFlash(u8 taskId)
{
    while (sStatusInflictionScreenFlashFuncs[gTasks[taskId].data[0]](&gTasks[taskId]));
}

static bool8 StatusInflictionFadeOut(struct Task *task)
{
    if (task->data[6] == 0 || --task->data[6] == 0)
    {
        task->data[6] = task->data[1];
        task->data[7] += task->data[4];
        if (task->data[7] > 16)
            task->data[7] = 16;
        BlendPalettes(PALETTES_ALL, task->data[7], RGB(11, 11, 11));
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
        BlendPalettes(PALETTES_ALL, task->data[7], RGB(11, 11, 11));
    }

    if (task->data[7] == 0)
    {
        if (--task->data[3] == 0)
        {
            DestroyTask(FindTaskIdByFunc(DoStatusInflictionScreenFlash));
        }
        else
        {
            task->data[6] = task->data[1];
            task->data[0] = 0;
        }
    }
    return FALSE;
}

static void StartStatusInflictionScreenFlash(s16 fadeOutDelay, s16 fadeInDelay, s16 numFades, s16 fadeOutSpeed, s16 fadeInSpped)
{
    u8 taskId = CreateTask(DoStatusInflictionScreenFlash, 3);

    gTasks[taskId].data[1] = fadeOutDelay;
    gTasks[taskId].data[2] = fadeInDelay;
    gTasks[taskId].data[3] = numFades;
    gTasks[taskId].data[4] = fadeOutSpeed;
    gTasks[taskId].data[5] = fadeInSpped;
    gTasks[taskId].data[6] = fadeOutDelay;
}

static bool8 IsStatusInflictionScreenFlashTaskFinished(void)
{
    if (FindTaskIdByFunc(DoStatusInflictionScreenFlash) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void Task_DoStatusInflictionScreenFlash(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[0]++;
        StartStatusInflictionScreenFlash(0, 0, 3, 2, 2);
    }
    else
    {
        if (IsStatusInflictionScreenFlashTaskFinished())
        {
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
    }
}

static void TryHealMons(u8 healCount)
{
    u8 j, i, k;
    u8 indices[FRONTIER_PARTY_SIZE];

    if (healCount == 0)
        return;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        indices[i] = i;
    for (k = 0; k < 10; k++)
    {
        u8 temp;

        i = Random() % FRONTIER_PARTY_SIZE;
        j = Random() % FRONTIER_PARTY_SIZE;
        SWAP(indices[i], indices[j], temp);
    }

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        bool32 canBeHealed = FALSE;
        struct Pokemon *mon = &gPlayerParty[indices[i]];
        u16 curr = GetMonData(mon, MON_DATA_HP);
        u16 max = GetMonData(mon, MON_DATA_MAX_HP);
        if (curr < max)
        {
            canBeHealed = TRUE;
        }
        else if (GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS)) != AILMENT_NONE)
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
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_UNUSED;
}

static void SetHintedRoom(void)
{
    u8 i, count, id;
    u8 *roomCandidates;

    gSpecialVar_Result = FALSE;
    if (GetPikeQueenFightType(1))
    {
        gSpecialVar_Result = TRUE;
        gSaveBlock2Ptr->frontier.pikeHintedRoomIndex = Random() % 6;
        gSaveBlock2Ptr->frontier.pikeHintedRoomType = PIKE_ROOM_BRAIN;
    }
    else
    {
        gSaveBlock2Ptr->frontier.pikeHintedRoomIndex = Random() % 3;
        if (gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled)
            count = NUM_PIKE_ROOM_TYPES - 3; // exclude healing rooms and Brain room
        else
            count = NUM_PIKE_ROOM_TYPES - 1; // exclude Brain room

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
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, battleNum);
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
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, 1);
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
        trainerId = GetRandomScaledFrontierTrainerId(challengeNum, 1);
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

static void BufferTrainerIntro(void)
{
    if (gSpecialVar_0x8005 == 0)
    {
        if (gTrainerBattleOpponent_A < FRONTIER_TRAINERS_COUNT)
            FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
    }
    else if (gSpecialVar_0x8005 == 1)
    {
        if (gTrainerBattleOpponent_B < FRONTIER_TRAINERS_COUNT)
            FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_B].speechBefore);
    }
}

static bool8 AtLeastTwoAliveMons(void)
{
    struct Pokemon *mon;
    u8 i, countDead;

    mon = &gPlayerParty[0];
    countDead = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++, mon++)
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

    u8 facility = FRONTIER_FACILITY_PIKE;
    u8 ret = FRONTIER_BRAIN_NOT_READY;
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    winStreak += nextRoom;
    numPikeSymbols = GetPlayerSymbolCountForFacility(FRONTIER_FACILITY_PIKE);

    switch (numPikeSymbols)
    {
    case 0:
    case 1:
        if (winStreak == sFrontierBrainStreakAppearances[facility][numPikeSymbols] - sFrontierBrainStreakAppearances[facility][3])
            ret = numPikeSymbols + 1; // FRONTIER_BRAIN_SILVER and FRONTIER_BRAIN_GOLD
        break;
    case 2:
    default:
        if (winStreak == sFrontierBrainStreakAppearances[facility][0] - sFrontierBrainStreakAppearances[facility][3])
            ret = FRONTIER_BRAIN_STREAK;
        else if (winStreak == sFrontierBrainStreakAppearances[facility][1] - sFrontierBrainStreakAppearances[facility][3]
                 || (winStreak > sFrontierBrainStreakAppearances[facility][1]
                     && (winStreak - sFrontierBrainStreakAppearances[facility][1] + sFrontierBrainStreakAppearances[facility][3]) % sFrontierBrainStreakAppearances[facility][2] == 0))
            ret = FRONTIER_BRAIN_STREAK_LONG;
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

static void SetHealingroomTypesDisabled(void)
{
    gSaveBlock2Ptr->frontier.pikeHealingRoomsDisabled = gSpecialVar_0x8005;
}

static void IsPartyFullHealed(void)
{
    u8 i, j;

    gSpecialVar_Result = TRUE;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        bool32 canBeHealed = FALSE;
        struct Pokemon *mon = &gPlayerParty[i];
        u16 curr = GetMonData(mon, MON_DATA_HP);
        u16 max = GetMonData(mon, MON_DATA_MAX_HP);
        if (curr >= max && GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS)) == AILMENT_NONE)
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

static void SaveMonHeldItems(void)
{
    u8 i;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        int heldItem = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1],
                                  MON_DATA_HELD_ITEM);
        gSaveBlock2Ptr->frontier.pikeHeldItemsBackup[i] = heldItem;
    }
}

static void RestoreMonHeldItems(void)
{
    u8 i;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        SetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1],
                   MON_DATA_HELD_ITEM,
                   &gSaveBlock2Ptr->frontier.pikeHeldItemsBackup[i]);
    }
}

static void InitPikeChallenge(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    if (!(gSaveBlock2Ptr->frontier.winStreakActiveFlags & sWinStreakFlags[lvlMode]))
        gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] = 0;

    gTrainerBattleOpponent_A = 0;
    gBattleOutcome = 0;
}

static bool8 CanEncounterWildMon(u8 enemyMonLevel)
{
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u16 monAbility = GetMonAbility(&gPlayerParty[0]);
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
