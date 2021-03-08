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

struct SendRecvMgr
{
    u8 master_slave;       // 0: clock slave; 1: clock master
    u8 state;              // EREADER_XFR_STATE_*
    u8 xferState;          // EREADER_XFER_*
    u8 checksumResult;     // EREADER_CHECKSUM_*
    u8 cancellationReason; // EREADER_CANCEL_*
    u32 *dataptr;          // Payload source or destination
    s32 cursor;            // Index of the next word
    s32 size;              // Last word index
    u32 checksum;          // Validation checksum
};

static void GetKeyInput(void);
static bool16 DetermineSendRecvState(u8);
static void EnableSio(void);
static void EReader_StopTimer(void);
static void SetUpTransferManager(u32, const u32*, u32*);
static void EReader_SetTimer(void);

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
                .moves = { MOVE_GIGA_DRAIN, MOVE_FAINT_ATTACK, MOVE_THUNDER_PUNCH, MOVE_GROWTH },
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

static u8 GetNewTrainerHillTrainerID(void)
{
    return (gSaveBlock1Ptr->trainerHill.unused + 1) % 256;
}

static bool32 Struct_EReaderTrainerHillTrainer_ValidateChecksum(const struct EReaderTrainerHillTrainer *arg0)
{
    u32 checksum = CalcByteArraySum((u8 *)arg0, sizeof(struct EReaderTrainerHillTrainer) - sizeof(arg0->checksum));
    if (checksum != arg0->checksum)
        return FALSE;

    return TRUE;
}

bool8 EReader_IsReceivedDataValid(struct EReaderTrainerHillSet *buffer)
{
    u32 i;
    u32 checksum;
    u32 var0 = buffer->count;
    if (var0 == 0 || var0 > 8)
        return FALSE;

    for (i = 0; i < var0; i++)
    {
        if (!Struct_EReaderTrainerHillTrainer_ValidateChecksum(&buffer->unk_8[i]))
            return FALSE;
    }

    checksum = CalcByteArraySum((u8 *)buffer->unk_8, var0 * sizeof(struct EReaderTrainerHillTrainer));
    if (checksum != buffer->checksum)
        return FALSE;

    return TRUE;
}

static bool32 TrainerHill_VerifyChecksum(struct EReaderTrainerHillSet *buffer)
{
    u32 checksum;
    u32 var0 = buffer->count;
    if (var0 == 0 || var0 > 8)
        return FALSE;

    checksum = CalcByteArraySum((u8 *)buffer->unk_8, sizeof(struct EReaderTrainerHillSet) - offsetof(struct EReaderTrainerHillSet, unk_8));
    if (checksum != buffer->checksum)
        return FALSE;

    return TRUE;
}

static bool32 TryWriteTrainerHill_r(const struct EReaderTrainerHillSet *ttdata, struct TrHillTag *buffer2)
{
    int i;

    AGB_ASSERT_EX(ttdata->dummy == 0, "cereader_tool.c", 450);
    AGB_ASSERT_EX(ttdata->id == 0, "cereader_tool.c", 452);

    memset(buffer2, 0, 0x1000);
    buffer2->numTrainers = ttdata->count;
    buffer2->unused1 = GetNewTrainerHillTrainerID();
    buffer2->numFloors = (ttdata->count + 1) / 2;

    for (i = 0; i < ttdata->count; i++)
    {
        if (!(i & 1))
        {
            buffer2->floors[i / 2].trainerNum1 = ttdata->unk_8[i].unk0;
            buffer2->floors[i / 2].display = ttdata->unk_8[i].unk14C;
            buffer2->floors[i / 2].trainers[0] = ttdata->unk_8[i].unk4;
        }
        else
        {
            buffer2->floors[i / 2].trainerNum2 = ttdata->unk_8[i].unk0;
            buffer2->floors[i / 2].trainers[1] = ttdata->unk_8[i].unk4;
        }
    }

    if (i & 1)
    {
        buffer2->floors[i / 2].trainers[1] = sTrainerHillTrainerTemplates_JP[i / 2];
    }

    buffer2->checksum = CalcByteArraySum((u8 *)buffer2->floors, 4 * sizeof(struct TrHillFloor));
    if (TryWriteSpecialSaveSection(SECTOR_ID_TRAINER_HILL, (u8 *)buffer2) != SAVE_STATUS_OK)
        return FALSE;

    return TRUE;
}

bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *arg0)
{
    void *var0 = AllocZeroed(0x1000);
    bool32 result = TryWriteTrainerHill_r(arg0, var0);
    Free(var0);
    return result;
}

static bool32 TryReadTrainerHill_r(struct EReaderTrainerHillSet *dst, u8 *buffer)
{
    if (TryReadSpecialSaveSection(SECTOR_ID_TRAINER_HILL, buffer) != SAVE_STATUS_OK)
        return FALSE;

    memcpy(dst, buffer, sizeof(struct EReaderTrainerHillSet));
    if (!TrainerHill_VerifyChecksum(dst))
        return FALSE;

    return TRUE;
}

static bool32 TryReadTrainerHill(struct EReaderTrainerHillSet *arg0)
{
    u8 *var0 = AllocZeroed(0x1000);
    bool32 result = TryReadTrainerHill_r(arg0, var0);
    Free(var0);
    return result;
}

bool32 ReadTrainerHillAndValidate(void)
{
    struct EReaderTrainerHillSet *var0 = AllocZeroed(0x1000);
    bool32 result = TryReadTrainerHill(var0);
    Free(var0);
    return result;
}

int Unused_EReader_Send(u32 arg0, u32 *arg1)
{
    int result;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (TEST_BUTTON(sJoyNew, B_BUTTON))
            gShouldAdvanceLinkState = 2;

        sSendRecvStatus = EReaderHandleTransfer(1, arg0, arg1, NULL);

        if ((sSendRecvStatus & 0x13) == 0x10)
        {
            result = 0;
            break;
        }

        if (sSendRecvStatus & 0x8)
        {
            result = 1;
            break;
        }

        if (sSendRecvStatus & 0x4)
        {
            result = 2;
            break;
        }

        gShouldAdvanceLinkState = 0;
        VBlankIntrWait();
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(struct SendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

int Unused_EReader_Recv(u32 *arg0)
{
    int result;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (TEST_BUTTON(sJoyNew, B_BUTTON))
            gShouldAdvanceLinkState = 2;

        sSendRecvStatus = EReaderHandleTransfer(0, 0, NULL, arg0);
        if ((sSendRecvStatus & 0x13) == 0x10)
        {
            result = 0;
            break;
        }

        if (sSendRecvStatus & 0x8)
        {
            result = 1;
            break;
        }

        if (sSendRecvStatus & 0x4)
        {
            result = 2;
            break;
        }

        gShouldAdvanceLinkState = 0;
        VBlankIntrWait();
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(struct SendRecvMgr));
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
        CpuFill32(0, &sSendRecvMgr, sizeof(struct SendRecvMgr));
}

static void OpenSerial32(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = SIO_INTR_ENABLE | SIO_32BIT_MODE;
    REG_SIOCNT |= SIO_MULTI_SD;
    gShouldAdvanceLinkState = 0;
    sCounter1 = 0;
    sCounter2 = 0;
}

u16 EReaderHandleTransfer(u8 arg0, u32 arg1, const u32 *arg2, u32 *arg3)
{
    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_INIT:
        OpenSerialMulti();
        sSendRecvMgr.xferState = EREADER_XFER_EXE;
        sSendRecvMgr.state = EREADER_XFR_STATE_HANDSHAKE;
        break;
    case 1:
        if (DetermineSendRecvState(arg0))
            EnableSio();

        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        // Progression is handled by the serial callback
        break;
    case EREADER_XFR_STATE_START:
        OpenSerial32();
        SetUpTransferManager(arg1, arg2, arg3);
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
            if (sSendRecvMgr.master_slave == 0 && sCounter2 > 60)
            {
                sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
                sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
            }

            if (sSendRecvMgr.xferState != EREADER_XFER_CHK)
            {
                if (sSendRecvMgr.master_slave != 0 && sCounter1 > 2)
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
        // Progression is handled by the serial callback
        break;
    case EREADER_XFR_STATE_TRANSFER_DONE:
        OpenSerialMulti();
        sSendRecvMgr.state = EREADER_XFR_STATE_CHECKSUM;
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (sSendRecvMgr.master_slave == 1 && sCounter1 > 2)
            EnableSio();

        if (++sCounter1 > 60)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
        // Progression is handled by the serial callback
    case EREADER_XFR_STATE_DONE:
        if (sSendRecvMgr.xferState != 0)
        {
            CloseSerial();
            sSendRecvMgr.xferState = 0;
        }
        break;
    }

    return (sSendRecvMgr.xferState << EREADER_XFER_SHIFT) | (sSendRecvMgr.cancellationReason << EREADER_CANCEL_SHIFT) | (sSendRecvMgr.checksumResult << EREADER_CHECKSUM_SHIFT);
}

static bool16 DetermineSendRecvState(u8 arg0)
{
    const struct SioMultiCnt sioMultiCnt = *(struct SioMultiCnt *)REG_ADDR_SIOCNT;
    if (!sioMultiCnt.si && sioMultiCnt.sd && arg0)
    {
        sSendRecvMgr.master_slave = TRUE;
        return TRUE;
    }
    else
    {
        sSendRecvMgr.master_slave = FALSE;
        return FALSE;
    }
}

static void SetUpTransferManager(u32 arg0, const u32 *arg1, u32 *arg2)
{
    if (sSendRecvMgr.master_slave != 0)
    {
        REG_SIOCNT |= SIO_38400_BPS;
        sSendRecvMgr.dataptr = (u32 *)arg1;
        REG_SIODATA32 = arg0;
        sSendRecvMgr.size = arg0 / 4 + 1;
        EReader_SetTimer();
    }
    else
    {
        REG_SIOCNT = REG_SIOCNT;
        sSendRecvMgr.dataptr = arg2;
    }
}

static void EReader_SetTimer(void)
{
    REG_TM3CNT_L = 0xFDA7;
    REG_TM3CNT_H = TIMER_INTR_ENABLE;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = 1;
}

void EReaderHelper_Timer3Callback(void)
{
    EReader_StopTimer();
    EnableSio();
}

void EReaderHelper_SerialCallback(void)
{
    u16 i, playerCount, k;
    u32 value;
    u16 recvBuffer[4];

    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_HANDSHAKE:
        REG_SIOMLT_SEND = 0xCCD0; // Handshake id
        *(u64 *)recvBuffer = REG_SIOMLT_RECV;
        for (i = 0, playerCount = 0, k = 0; i < 4; i++)
        {
            if (recvBuffer[i] == 0xCCD0)
                playerCount++;
            else if (recvBuffer[i] != 0xFFFF)
                k++;
        }

        if (playerCount == 2 && k == 0)
            sSendRecvMgr.state = EREADER_XFR_STATE_START;
        break;
    case EREADER_XFR_STATE_TRANSFER:
        value = REG_SIODATA32;
        // The first value sent by the EReader is the payload size
        if (!sSendRecvMgr.cursor && !sSendRecvMgr.master_slave)
            sSendRecvMgr.size = value / 4 + 1;

        if (sSendRecvMgr.master_slave == 1)
        {
            if (sSendRecvMgr.cursor < sSendRecvMgr.size)
            {
                REG_SIODATA32 = sSendRecvMgr.dataptr[sSendRecvMgr.cursor];
                sSendRecvMgr.checksum += sSendRecvMgr.dataptr[sSendRecvMgr.cursor];
            }
            else
            {
                REG_SIODATA32 = sSendRecvMgr.checksum;
            }
        }
        else
        {
            if (sSendRecvMgr.cursor > 0 && sSendRecvMgr.cursor < sSendRecvMgr.size + 1)
            {
                sSendRecvMgr.dataptr[sSendRecvMgr.cursor - 1] = value;
                sSendRecvMgr.checksum += value;
            }
            else if (sSendRecvMgr.cursor)
            {
                if (sSendRecvMgr.checksum == value)
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_OK;
                else
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_ERR;
            }

            sCounter2 = 0;
        }

        if (++sSendRecvMgr.cursor < sSendRecvMgr.size + 2)
        {
            if (sSendRecvMgr.master_slave)
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
        if (sSendRecvMgr.master_slave == 0)
            REG_SIOMLT_SEND = sSendRecvMgr.checksumResult;

        *(u64 *)recvBuffer = REG_SIOMLT_RECV;
        if (recvBuffer[1] == EREADER_CHECKSUM_OK || recvBuffer[1] == EREADER_CHECKSUM_ERR)
        {
            if (sSendRecvMgr.master_slave == 1)
                // EReader has (in)validated the payload
                sSendRecvMgr.checksumResult = recvBuffer[1];

            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    }
}

static void EnableSio(void)
{
    REG_SIOCNT |= SIO_ENABLE;
}

static void EReader_StopTimer(void)
{
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = -601;
}

static void GetKeyInput(void)
{
    u16 rawKeys = REG_KEYINPUT ^ KEYS_MASK;
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

void EReaderHelper_ClearsSendRecvMgr(void)
{
    CpuFill32(0, &sSendRecvMgr, sizeof(struct SendRecvMgr));
}
