#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "union_room.h"
#include "save.h"
#include "sprite.h"
#include "task.h"
#include "util.h"
#include "trainer_hill.h"
#include "constants/easy_chat.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/trainer_hill.h"

enum {
    EREADER_XFR_STATE_INIT = 0,
    EREADER_XFR_STATE_HANDSHAKE,
    EREADER_XFR_STATE_START,
    EREADER_XFR_STATE_TRANSFER,
    EREADER_XFR_STATE_TRANSFER_DONE,
    EREADER_XFR_STATE_CHECKSUM,
    EREADER_XFR_STATE_DONE
};

#define EREADER_XFER_EXE 1
#define EREADER_XFER_CHK 2
#define EREADER_XFER_SHIFT 0
#define EREADER_XFER_MASK  3

#define EREADER_CANCEL_TIMEOUT 1
#define EREADER_CANCEL_KEY     2
#define EREADER_CANCEL_MASK  0xC
#define EREADER_CANCEL_SHIFT 2

#define EREADER_CHECKSUM_OK  1
#define EREADER_CHECKSUM_ERR 2
#define EREADER_CHECKSUM_MASK  0x30
#define EREADER_CHECKSUM_SHIFT 4

struct SendRecvMgr
{
    bool8 isParent;
    u8 state;              // EREADER_XFR_STATE_*
    u8 xferState;          // EREADER_XFER_*
    u8 checksumResult;     // EREADER_CHECKSUM_*
    u8 cancellationReason; // EREADER_CANCEL_*
    u32 *data;             // Payload source or destination
    int cursor;            // Index of the next word
    int size;              // Last word index
    int checksum;
};

static void GetKeyInput(void);
static u16 DetermineSendRecvState(u8);
static void EnableSio(void);
static void DisableTm3(void);
static void SetUpTransferManager(size_t, const void *, void *);
static void StartTm3(void);

static struct SendRecvMgr sSendRecvMgr;
static u16 sJoyNewOrRepeated;
static u16 sJoyNew;
static u16 sSendRecvStatus;
static u16 sCounter1;
static u32 sCounter2;
static u16 sSavedIme;
static u16 sSavedIe;
static u16 sSavedTm3Cnt;
static u16 sSavedSioCnt;
static u16 sSavedRCnt;

static const struct TrainerHillTrainer sTrainerHillTrainerTemplates_JP[] = {
    [0] = {
        .name = __("マキエ$$$$$   "),
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .unused = 0x1,
        .speechBefore = { EC_WORD_PREPOSTEROUS, EC_WORD_CASE, EC_WORD_THERE, EC_WORD_TO_HER, EC_WORD_CHALLENGE, EC_WORD_JOKING },
        .speechWin = { EC_WORD_HERS, EC_WORD_TRUMP_CARD, EC_MOVE2(SECRET_POWER), EC_WORD_USING, EC_WORD_WON, EC_WORD_EXCL_EXCL },
        .speechLose = { EC_WORD_TO_HER, EC_WORD_WIN, EC_WORD_JOKING, EC_WORD_HIGHS, EC_WORD_SCARY, EC_WORD_ELLIPSIS_EXCL },
        .speechAfter = { EC_WORD_IGNORANT, EC_WORD_SO, EC_WORD_TODAY, EC_WORD_NIGHTTIME, EC_WORD_YOU_RE, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS },
        .mons = {
            [0] = NULL_BATTLE_TOWER_POKEMON,
            [1] = NULL_BATTLE_TOWER_POKEMON,
            [2] = NULL_BATTLE_TOWER_POKEMON,
            [3] = {
                .species = SPECIES_SWALOT,
                .heldItem = ITEM_SHELL_BELL,
                .moves = { MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_PAIN_SPLIT, MOVE_YAWN },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 55,
                .attackEV = 255,
                .defenseEV = 100,
                .speedEV = 0,
                .spAttackEV = 0,
                .spDefenseEV = 100,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 1,
                .personality = 0x80,
                .nickname = __("マルノーム$$$$$$"),
                .friendship = 255
            },
            [4] = {
                .species = SPECIES_DUSTOX,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_SILVER_WIND, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 0,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x6,
                .nickname = __("ドクケイル$$$$$$"),
                .friendship = 255
            },
            [5] = {
                .species = SPECIES_RELICANTH,
                .heldItem = ITEM_QUICK_CLAW,
                .moves = { MOVE_ANCIENT_POWER, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_AMNESIA },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 100,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 155,
                .spDefenseEV = 255,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x2f,
                .nickname = __("ジーランス$$$$$$"),
                .friendship = 255
            },
        }
    },
    [1] = {
        .name = __("ハルヒト$$$$   "),
        .facilityClass = FACILITY_CLASS_CAMPER,
        .unused = 0x1,
        .speechBefore = { EC_MOVE2(BOUNCE), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_STRONG, EC_WORD_EXCL },
        .speechWin = { EC_MOVE(FLY), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_HAPPY, EC_WORD_EXCL },
        .speechLose = { EC_MOVE2(MINIMIZE), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_SAD, EC_WORD_EXCL },
        .speechAfter = { EC_MOVE(BITE), EC_WORD_AS_MUCH_AS, EC_EMPTY_WORD, EC_WORD_THEY_RE, EC_WORD_ANGRY, EC_WORD_EXCL },
        .mons = {
            [0] = NULL_BATTLE_TOWER_POKEMON,
            [1] = NULL_BATTLE_TOWER_POKEMON,
            [2] = NULL_BATTLE_TOWER_POKEMON,
            [3] = {
                .species = SPECIES_CACTURNE,
                .heldItem = ITEM_QUICK_CLAW,
                .moves = { MOVE_GIGA_DRAIN, MOVE_FEINT_ATTACK, MOVE_THUNDER_PUNCH, MOVE_GROWTH },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 55,
                .attackEV = 0,
                .defenseEV = 100,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 100,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x8c,
                .nickname = __("ノクタス$$$$$$$"),
                .friendship = 255
            },
            [4] = {
                .species = SPECIES_SWELLOW,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_DOUBLE_TEAM },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 255,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 0,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x80,
                .nickname = __("オオスバメ$$$$$$"),
                .friendship = 255
            },
            [5] = {
                .species = SPECIES_WHISCASH,
                .heldItem = ITEM_CHESTO_BERRY,
                .moves = { MOVE_SURF, MOVE_EARTHQUAKE, MOVE_AMNESIA, MOVE_REST },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 0,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x0,
                .nickname = __("ナマズン$$$$$$$"),
                .friendship = 255
            },
        }
    },
    [2] = {
        .name = __("メイコ$$$$$   "),
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .unused = 0x1,
        .speechBefore = { EC_WORD_SHINE, EC_WORD_POKEMON, EC_WORD_RELEASE, EC_WORD_WAS, EC_MOVE2(FRUSTRATION), EC_WORD_WITHOUT },
        .speechWin = { EC_WORD_SHINE, EC_WORD_POKEMON, EC_WORD_TO_HER, EC_MOVE2(PRESENT), EC_WORD_KNOWS, EC_WORD_WITHOUT },
        .speechLose = { EC_WORD_THAT, EC_WORD_ABOVE, EC_WORD_LOST, EC_WORD_STORES, EC_WORD_JOKING, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS },
        .speechAfter = { EC_WORD_ENTERTAINING, EC_WORD_NONE, EC_WORD_HEY_QUES, EC_WORD_ALMOST, EC_WORD_EXCL, EC_EMPTY_WORD },
        .mons = {
            [0] = NULL_BATTLE_TOWER_POKEMON,
            [1] = NULL_BATTLE_TOWER_POKEMON,
            [2] = NULL_BATTLE_TOWER_POKEMON,
            [3] = {
                .species = SPECIES_DELCATTY,
                .heldItem = ITEM_LUM_BERRY,
                .moves = { MOVE_SING, MOVE_BODY_SLAM, MOVE_SHADOW_BALL, MOVE_IRON_TAIL },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 0,
                .attackEV = 255,
                .defenseEV = 0,
                .speedEV = 255,
                .spAttackEV = 0,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x3,
                .nickname = __("エネコロロ$$$$$$"),
                .friendship = 255
            },
            [4] = {
                .species = SPECIES_ROSELIA,
                .heldItem = ITEM_LEFTOVERS,
                .moves = { MOVE_GIGA_DRAIN, MOVE_GRASS_WHISTLE, MOVE_TOXIC, MOVE_LEECH_SEED },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 255,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 1,
                .personality = 0x6,
                .nickname = __("ロゼリア$$$$$$$"),
                .friendship = 255
            },
            [5] = {
                .species = SPECIES_BEAUTIFLY,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_SILVER_WIND, MOVE_AERIAL_ACE, MOVE_ATTRACT, MOVE_PSYCHIC },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 100,
                .attackEV = 200,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 200,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x6,
                .nickname = __("アゲハント$$$$$$"),
                .friendship = 255
            },
        }
    },
    [3] = {
        .name = __("ピエール$$$$   "),
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .unused = 0x1,
        .speechBefore = { EC_WORD_SHE_WAS, EC_WORD_NO_1, EC_WORD_STRONG, EC_WORD_UNCLE, EC_WORD_THERE, EC_WORD_EXCL },
        .speechWin = { EC_WORD_HAHAHA, EC_WORD_TEACHER, EC_WORD_BECOMES, EC_WORD_GIVE, EC_WORD_IS_IT_QUES, EC_EMPTY_WORD },
        .speechLose = { EC_WORD_OUTSIDE, EC_WORD_UNCLE, EC_WORD_SURPRISE, EC_WORD_THESE, EC_WORD_HEY_QUES, EC_WORD_ELLIPSIS_EXCL },
        .speechAfter = { EC_WORD_HE_S, EC_WORD_NO_1, EC_WORD_STRONG, EC_WORD_CHILDREN, EC_WORD_CAN_T, EC_WORD_EXCL_EXCL },
        .mons = {
            [0] = NULL_BATTLE_TOWER_POKEMON,
            [1] = NULL_BATTLE_TOWER_POKEMON,
            [2] = NULL_BATTLE_TOWER_POKEMON,
            [3] = {
                .species = SPECIES_MAWILE,
                .heldItem = ITEM_BRIGHT_POWDER,
                .moves = { MOVE_CRUNCH, MOVE_FLAMETHROWER, MOVE_THUNDER_PUNCH, MOVE_COMET_PUNCH },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 0,
                .attackEV = 0,
                .defenseEV = 100,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 155,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 1,
                .personality = 0x0,
                .nickname = __("クチート$$$$$$$"),
                .friendship = 255
            },
            [4] = {
                .species = SPECIES_SHARPEDO,
                .heldItem = ITEM_SCOPE_LENS,
                .moves = { MOVE_SURF, MOVE_CRUNCH, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 255,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x96,
                .nickname = __("サメハダー$$$$$$"),
                .friendship = 255
            },
            [5] = {
                .species = SPECIES_BANETTE,
                .heldItem = ITEM_LUM_BERRY,
                .moves = { MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_WILL_O_WISP },
                .level = 0,
                .ppBonuses = 0x0,
                .hpEV = 255,
                .attackEV = 0,
                .defenseEV = 0,
                .speedEV = 0,
                .spAttackEV = 255,
                .spDefenseEV = 0,
                .otId = 0x10000000,
                .hpIV = 5,
                .attackIV = 5,
                .defenseIV = 5,
                .speedIV = 5,
                .spAttackIV = 5,
                .spDefenseIV = 5,
                .abilityNum = 0,
                .personality = 0x96,
                .nickname = __("ジュペッタ$$$$$$"),
                .friendship = 255
            },
        }
    },
};

static u8 GetTrainerHillUnkVal(void)
{
    return (gSaveBlock1Ptr->trainerHill.unused + 1) % 256;
}

static bool32 ValidateTrainerChecksum(struct EReaderTrainerHillTrainer * hillTrainer)
{
    int checksum = CalcByteArraySum((u8 *)hillTrainer, offsetof(typeof(*hillTrainer), checksum));
    if (checksum != hillTrainer->checksum)
        return FALSE;

    return TRUE;
}

bool8 ValidateTrainerHillData(struct EReaderTrainerHillSet * hillSet)
{
    u32 i;
    u32 checksum;
    int numTrainers = hillSet->numTrainers;

    // Validate number of trainers
    if (numTrainers < 1 || numTrainers > NUM_TRAINER_HILL_TRAINERS)
        return FALSE;

    // Validate trainers
    for (i = 0; i < numTrainers; i++)
    {
        if (!ValidateTrainerChecksum(&hillSet->trainers[i]))
            return FALSE;
    }

    // Validate checksum
    checksum = CalcByteArraySum((u8 *)hillSet->trainers, numTrainers * sizeof(struct EReaderTrainerHillTrainer));
    if (checksum != hillSet->checksum)
        return FALSE;

    return TRUE;
}

static bool32 ValidateTrainerHillChecksum(struct EReaderTrainerHillSet *hillSet)
{
    u32 checksum;
    int numTrainers = hillSet->numTrainers;
    if (numTrainers < 1 || numTrainers > NUM_TRAINER_HILL_TRAINERS)
        return FALSE;

    checksum = CalcByteArraySum((u8 *)hillSet->trainers, sizeof(struct EReaderTrainerHillSet) - offsetof(struct EReaderTrainerHillSet, trainers));
    if (checksum != hillSet->checksum)
        return FALSE;

    return TRUE;
}

static bool32 TryWriteTrainerHill_Internal(struct EReaderTrainerHillSet * hillSet, struct TrHillTag * hillTag)
{
    int i;

    AGB_ASSERT_EX(hillSet->dummy == 0, "cereader_tool.c", 450);
    AGB_ASSERT_EX(hillSet->id == 0, "cereader_tool.c", 452);

    memset(hillTag, 0, SECTOR_SIZE);
    hillTag->numTrainers = hillSet->numTrainers;
    hillTag->unused1 = GetTrainerHillUnkVal();
    hillTag->numFloors = (hillSet->numTrainers + 1) / TRAINER_HILL_TRAINERS_PER_FLOOR;

    for (i = 0; i < hillSet->numTrainers; i++)
    {
        if (!(i & 1))
        {
            hillTag->floors[i / TRAINER_HILL_TRAINERS_PER_FLOOR].trainerNum1 = hillSet->trainers[i].trainerNum;
            hillTag->floors[i / TRAINER_HILL_TRAINERS_PER_FLOOR].display = hillSet->trainers[i].display;
            hillTag->floors[i / TRAINER_HILL_TRAINERS_PER_FLOOR].trainers[0] = hillSet->trainers[i].trainer;
        }
        else
        {
            hillTag->floors[i / TRAINER_HILL_TRAINERS_PER_FLOOR].trainerNum2 = hillSet->trainers[i].trainerNum;
            hillTag->floors[i / TRAINER_HILL_TRAINERS_PER_FLOOR].trainers[1] = hillSet->trainers[i].trainer;
        }
    }

    if (i & 1)
    {
        hillTag->floors[i / TRAINER_HILL_TRAINERS_PER_FLOOR].trainers[1] = sTrainerHillTrainerTemplates_JP[i / TRAINER_HILL_TRAINERS_PER_FLOOR];
    }

    hillTag->checksum = CalcByteArraySum((u8 *)hillTag->floors, NUM_TRAINER_HILL_FLOORS * sizeof(struct TrHillFloor));
    if (TryWriteSpecialSaveSection(SECTOR_ID_TRAINER_HILL, (u8 *)hillTag) != SAVE_STATUS_OK)
        return FALSE;

    return TRUE;
}

bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet * hillSet)
{
    void *buffer = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryWriteTrainerHill_Internal(hillSet, buffer);
    Free(buffer);
    return result;
}

static bool32 TryReadTrainerHill_Internal(struct EReaderTrainerHillSet * dest, u8 * buffer)
{
    if (TryReadSpecialSaveSection(SECTOR_ID_TRAINER_HILL, buffer) != SAVE_STATUS_OK)
        return FALSE;

    memcpy(dest, buffer, sizeof(struct EReaderTrainerHillSet));
    if (!ValidateTrainerHillChecksum(dest))
        return FALSE;

    return TRUE;
}

static bool32 TryReadTrainerHill(struct EReaderTrainerHillSet * hillSet)
{
    u8 *buffer = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryReadTrainerHill_Internal(hillSet, buffer);
    Free(buffer);
    return result;
}

bool32 ReadTrainerHillAndValidate(void)
{
    struct EReaderTrainerHillSet *hillSet = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryReadTrainerHill(hillSet);
    Free(hillSet);
    return result;
}

int EReader_Send(int size, const void * src)
{
    int result;
    int sendStatus;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (sJoyNew & B_BUTTON)
            gShouldAdvanceLinkState = 2;

        sendStatus = EReaderHandleTransfer(1, size, src, NULL);
        sSendRecvStatus = sendStatus;
        if ((sSendRecvStatus & 0x13) == 0x10)
        {
            result = 0;
            break;
        }
        else if (sSendRecvStatus & 0x8)
        {
            result = 1;
            break;
        }
        else if (sSendRecvStatus & 0x4)
        {
            result = 2;
            break;
        }
        else
        {
            gShouldAdvanceLinkState = 0;
            VBlankIntrWait();
        }
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

int EReader_Recv(void * dest)
{
    int result;
    int recvStatus;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (sJoyNew & B_BUTTON)
            gShouldAdvanceLinkState = 2;

        recvStatus = EReaderHandleTransfer(0, 0, NULL, dest);
        sSendRecvStatus = recvStatus;
        if ((sSendRecvStatus & 0x13) == 0x10)
        {
            result = 0;
            break;
        }
        else if (sSendRecvStatus & 0x8)
        {
            result = 1;
            break;
        }
        else if (sSendRecvStatus & 0x4)
        {
            result = 2;
            break;
        }
        else
        {
            gShouldAdvanceLinkState = 0;
            VBlankIntrWait();
        }
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

static void CloseSerial(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

static void OpenSerialMulti(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_115200_BPS;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;

    if (sSendRecvMgr.state == 0)
        CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
}

static void OpenSerial32(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_INTR_ENABLE;
    REG_SIOCNT |= SIO_MULTI_SD;
    gShouldAdvanceLinkState = 0;
    sCounter1 = 0;
    sCounter2 = 0;
}

int EReaderHandleTransfer(u8 mode, size_t size, const void * data, void * recvBuffer)
{
    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_INIT:
        OpenSerialMulti();
        sSendRecvMgr.xferState = EREADER_XFER_EXE;
        sSendRecvMgr.state = EREADER_XFR_STATE_HANDSHAKE;
        break;
    case EREADER_XFR_STATE_HANDSHAKE:
        if (DetermineSendRecvState(mode))
            EnableSio();

        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    case EREADER_XFR_STATE_START:
        OpenSerial32();
        SetUpTransferManager(size, data, recvBuffer);
        sSendRecvMgr.state = EREADER_XFR_STATE_TRANSFER;
        // fall through
    case EREADER_XFR_STATE_TRANSFER:
        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        else
        {
            sCounter1++;
            sCounter2++;
            if (!sSendRecvMgr.isParent && sCounter2 > 60)
            {
                sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
                sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
            }

            if (sSendRecvMgr.xferState != EREADER_XFER_CHK)
            {
                if (sSendRecvMgr.isParent && sCounter1 > 2)
                {
                    EnableSio();
                    sSendRecvMgr.xferState = EREADER_XFER_CHK;
                }
                else
                {
                    EnableSio();
                    sSendRecvMgr.xferState = EREADER_XFER_CHK;
                }
            }
        }
        break;
    case EREADER_XFR_STATE_TRANSFER_DONE:
        OpenSerialMulti();
        sSendRecvMgr.state = EREADER_XFR_STATE_CHECKSUM;
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (sSendRecvMgr.isParent == TRUE && sCounter1 > 2)
            EnableSio();

        if (++sCounter1 > 60)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    case EREADER_XFR_STATE_DONE:
        if (sSendRecvMgr.xferState)
        {
            CloseSerial();
            sSendRecvMgr.xferState = 0;
        }
        break;
    }

    return (sSendRecvMgr.xferState << EREADER_XFER_SHIFT)
         | (sSendRecvMgr.cancellationReason << EREADER_CANCEL_SHIFT) 
         | (sSendRecvMgr.checksumResult << EREADER_CHECKSUM_SHIFT);
}

static u16 DetermineSendRecvState(u8 mode)
{
    bool16 resp;
    if ((*(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SI | SIO_MULTI_SD)) == SIO_MULTI_SD && mode)
        resp = sSendRecvMgr.isParent = TRUE;
    else
        resp = sSendRecvMgr.isParent = FALSE;
    return resp;
}

static void SetUpTransferManager(size_t size, const void * data, void * recvBuffer)
{
    if (sSendRecvMgr.isParent)
    {
        REG_SIOCNT |= SIO_38400_BPS;
        sSendRecvMgr.data = (void *)data;
        REG_SIODATA32 = size;
        sSendRecvMgr.size = size / 4 + 1;
        StartTm3();
    }
    else
    {
        REG_SIOCNT = REG_SIOCNT;
        sSendRecvMgr.data = recvBuffer;
    }
}

static void StartTm3(void)
{
    REG_TM3CNT_L = -601;
    REG_TM3CNT_H = TIMER_INTR_ENABLE;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = 1;
}

void EReaderHelper_Timer3Callback(void)
{
    DisableTm3();
    EnableSio();
}

void EReaderHelper_SerialCallback(void)
{
    u16 i, cnt1, cnt2;
    u32 recv32;
    u16 recv[4];

    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_HANDSHAKE:
        REG_SIOMLT_SEND = 0xCCD0; // Handshake id
        *(u64 *)recv = REG_SIOMLT_RECV;
        for (i = 0, cnt1 = 0, cnt2 = 0; i < 4; i++)
        {
            if (recv[i] == 0xCCD0)
                cnt1++;
            else if (recv[i] != 0xFFFF)
                cnt2++;
        }

        if (cnt1 == 2 && cnt2 == 0)
            sSendRecvMgr.state = 2;
        break;
    case EREADER_XFR_STATE_TRANSFER:
        recv32 = REG_SIODATA32;
        // The first value sent by the EReader is the payload size
        if (!sSendRecvMgr.cursor && !sSendRecvMgr.isParent)
            sSendRecvMgr.size = recv32 / 4 + 1;

        if (sSendRecvMgr.isParent == TRUE)
        {
            // Send mode
            if (sSendRecvMgr.cursor < sSendRecvMgr.size)
            {
                REG_SIODATA32 = sSendRecvMgr.data[sSendRecvMgr.cursor];
                sSendRecvMgr.checksum += sSendRecvMgr.data[sSendRecvMgr.cursor];
            }
            else
            {
                REG_SIODATA32 = sSendRecvMgr.checksum;
            }
        }
        else
        {
            // Receive mode
            if (sSendRecvMgr.cursor > 0 && sSendRecvMgr.cursor < sSendRecvMgr.size + 1)
            {
                sSendRecvMgr.data[sSendRecvMgr.cursor - 1] = recv32;
                sSendRecvMgr.checksum += recv32;
            }
            else if (sSendRecvMgr.cursor)
            {
                if (sSendRecvMgr.checksum == recv32)
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_OK;
                else
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_ERR;
            }

            sCounter2 = 0;
        }

        if (++sSendRecvMgr.cursor < sSendRecvMgr.size + 2)
        {
            if (sSendRecvMgr.isParent)
                REG_TM3CNT_H |= TIMER_ENABLE;
            else
                EnableSio();
        }
        else
        {
            sSendRecvMgr.state = EREADER_XFR_STATE_TRANSFER_DONE;
            sCounter1 = 0;
        }
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (!sSendRecvMgr.isParent)
            REG_SIOMLT_SEND = sSendRecvMgr.checksumResult;

        *(vu64 *)recv = REG_SIOMLT_RECV;
        if (recv[1] == EREADER_CHECKSUM_OK || recv[1] == EREADER_CHECKSUM_ERR)
        {
            if (sSendRecvMgr.isParent == TRUE)
                sSendRecvMgr.checksumResult = recv[1]; // EReader has (in)validated the payload

            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    }
}

static void EnableSio(void)
{
    REG_SIOCNT |= SIO_ENABLE;
}

static void DisableTm3(void)
{
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = 0xFDA7;
}

static void GetKeyInput(void)
{
    int rawKeys = REG_KEYINPUT ^ KEYS_MASK;
    sJoyNew = rawKeys & ~sJoyNewOrRepeated;
    sJoyNewOrRepeated = rawKeys;
}

void EReaderHelper_SaveRegsState(void)
{
    sSavedIme = REG_IME;
    sSavedIe = REG_IE;
    sSavedTm3Cnt = REG_TM3CNT_H;
    sSavedSioCnt = REG_SIOCNT;
    sSavedRCnt = REG_RCNT;
}

void EReaderHelper_RestoreRegsState(void)
{
    REG_IME = sSavedIme;
    REG_IE = sSavedIe;
    REG_TM3CNT_H = sSavedTm3Cnt;
    REG_SIOCNT = sSavedSioCnt;
    REG_RCNT = sSavedRCnt;
}

void EReaderHelper_ClearSendRecvMgr(void)
{
    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
}
