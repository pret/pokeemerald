#include "global.h"
#include "malloc.h"
#include "random.h"
#include "constants/items.h"
#include "text.h"
#include "item.h"
#include "task.h"
#include "constants/species.h"
#include "save.h"
#include "load_save.h"
#include "pokemon.h"
#include "cable_club.h"
#include "link.h"
#include "link_rfu.h"
#include "tv.h"
#include "battle_tower.h"
#include "window.h"
#include "mystery_event_script.h"
#include "secret_base.h"
#include "mauville_old_man.h"
#include "sound.h"
#include "constants/songs.h"
#include "menu.h"
#include "overworld.h"
#include "field_screen.h"
#include "fldeff_80F9BCC.h"
#include "script.h"
#include "event_data.h"
#include "lilycove_lady.h"
#include "strings.h"
#include "string_util.h"
#include "record_mixing.h"
#include "new_game.h"
#include "daycare.h"
#include "international_string_util.h"

extern void ReceiveSecretBasesData(struct SecretBaseRecord *, size_t, u8);
extern void ReceiveEasyChatPairsData(struct EasyChatPair *, size_t, u8);

// Static type declarations

struct UnknownRecMixingStruct
{
    u32 field_0;
    u16 field_4;
    u8 field_6[9];
};

struct UnknownRecMixingStruct2
{
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u8 field_A[16];
};

struct UnknownRecMixingStruct3
{
    u8 field_0[0x810];
};

struct PlayerRecordsRS
{
    struct SecretBaseRecord secretBases[SECRET_BASES_COUNT];
    TVShow tvShows[TV_SHOWS_COUNT];
    PokeNews pokeNews[POKE_NEWS_COUNT];
    OldMan oldMan;
    struct EasyChatPair easyChatPairs[5];
    struct RecordMixingDayCareMail dayCareMail;
    struct RSBattleTowerRecord battleTowerRecord;
    u16 filler11C8[0x32];
};

struct PlayerRecordsEmerald
{
    /* 0x0000 */ struct SecretBaseRecord secretBases[SECRET_BASES_COUNT];
    /* 0x0c80 */ TVShow tvShows[TV_SHOWS_COUNT];
    /* 0x1004 */ PokeNews pokeNews[POKE_NEWS_COUNT];
    /* 0x1044 */ OldMan oldMan;
    /* 0x1084 */ struct EasyChatPair easyChatPairs[5];
    /* 0x10ac */ struct RecordMixingDayCareMail dayCareMail;
    /* 0x1124 */ struct EmeraldBattleTowerRecord battleTowerRecord;
    /* 0x1210 */ u16 unk_1210;
    /* 0x1214 */ LilycoveLady lilycoveLady;
    /* 0x1254 */ struct UnkRecordMixingStruct unk_1254[2];
    /* 0x12dc */ struct UnkRecordMixingStruct2 unk_12dc;
    /* 0x1434 */ u8 field_1434[0x10];
}; // 0x1444

union PlayerRecords
{
    struct PlayerRecordsRS ruby;
    struct PlayerRecordsEmerald emerald;
};

// Static RAM declarations

static IWRAM_DATA bool8 gUnknown_03001130;
static IWRAM_DATA struct SecretBaseRecord *sSecretBasesSave;
static IWRAM_DATA TVShow *sTvShowsSave;
static IWRAM_DATA PokeNews *sPokeNewsSave;
static IWRAM_DATA OldMan *sOldManSave;
static IWRAM_DATA struct EasyChatPair *sEasyChatPairsSave;
static IWRAM_DATA struct RecordMixingDayCareMail *gUnknown_03001148;
static IWRAM_DATA void *sBattleTowerSave;
static IWRAM_DATA LilycoveLady *sLilycoveLadySave;
static IWRAM_DATA void *gUnknown_03001154; // gSaveBlock2Ptr->field_0DC;
static IWRAM_DATA void *sBattleTowerSave_Duplicate;
static IWRAM_DATA u32 sRecordStructSize;
static IWRAM_DATA u8 gUnknown_03001160;
static IWRAM_DATA u32 filler_03001164;
static IWRAM_DATA u32 gUnknown_03001168[3];

static EWRAM_DATA struct RecordMixingDayCareMail gUnknown_02039F9C = {0};
static EWRAM_DATA union PlayerRecords *sReceivedRecords = NULL;
static EWRAM_DATA union PlayerRecords *sSentRecord = NULL;

// Static ROM declarations

static void Task_RecordMixing_Main(u8 taskId);
static void sub_80E7324(u8 taskId);
static void Task_SendPacket(u8 taskId);
static void Task_CopyReceiveBuffer(u8 taskId);
static void Task_SendPacket_SwitchToReceive(u8 taskId);
static void *LoadPtrFromTaskData(const u16 *asShort);
static void StorePtrInTaskData(void *records, u16 *a1);
static u8 GetMultiplayerId_(void);
static void *GetPlayerRecvBuffer(u8);
static void ReceiveOldManData(OldMan *, size_t, u8);
static void ReceiveBattleTowerData(void *battleTowerRecord, size_t, u8);
static void ReceiveLilycoveLadyData(LilycoveLady *, size_t, u8);
static void sub_80E7B2C(const u8 *);
static void ReceiveDaycareMailData(struct RecordMixingDayCareMail *, size_t, u8, TVShow *);
static void sub_80E7F68(u16 *item, u8 which);
static void sub_80E7FF8(u8 taskId);
static void sub_80E8110(struct UnkRecordMixingStruct *arg0, struct UnkRecordMixingStruct *arg1);
static void sub_80E8468(struct UnkRecordMixingStruct *arg0, size_t arg1, u32 arg2);
static void sub_80E89AC(struct UnkRecordMixingStruct2 *arg0, size_t arg1, u32 arg2);
static void sub_80E89F8(struct RecordMixingDayCareMail *dst);
static void SanitizeDayCareMailForRuby(struct RecordMixingDayCareMail *src);
static void SanitizeEmeraldBattleTowerRecord(struct EmeraldBattleTowerRecord *arg0);
static void SanitizeRubyBattleTowerRecord(struct RSBattleTowerRecord *src);

// .rodata

static const u8 gUnknown_0858CF8C[] = {1, 0};

static const u8 gUnknown_0858CF8E[][3] =
{
    {1, 2, 0},
    {2, 0, 1},
};

static const u8 gUnknown_0858CF94[][4] =
{
    {1, 0, 3, 2},
    {3, 0, 1, 2},
    {2, 0, 3, 1},
    {1, 3, 0, 2},
    {2, 3, 0, 1},
    {3, 2, 0, 1},
    {1, 2, 3, 0},
    {2, 3, 1, 0},
    {3, 2, 1, 0},
};

static const u8 gUnknown_0858CFB8[3][2] =
{
    {0, 1},
    {1, 2},
    {2, 0},
};

static const u8 gUnknown_0858CFBE[3][4] =
{
    {0, 1, 2, 3},
    {0, 2, 1, 3},
    {0, 3, 2, 1},
};

// .text

#define BUFFER_CHUNK_SIZE 200

void sub_80E6BE8(void)
{
    sub_80B37D4(Task_RecordMixing_Main);
}

// these variables were const in R/S, but had to become changeable because of saveblocks changing RAM position
static void SetSrcLookupPointers(void)
{
    sSecretBasesSave = gSaveBlock1Ptr->secretBases;
    sTvShowsSave = gSaveBlock1Ptr->tvShows;
    sPokeNewsSave = gSaveBlock1Ptr->pokeNews;
    sOldManSave = &gSaveBlock1Ptr->oldMan;
    sEasyChatPairsSave = gSaveBlock1Ptr->easyChatPairs;
    gUnknown_03001148 = &gUnknown_02039F9C;
    sBattleTowerSave = &gSaveBlock2Ptr->battleTower;
    sLilycoveLadySave = &gSaveBlock1Ptr->lilycoveLady;
    gUnknown_03001154 = gSaveBlock2Ptr->field_DC;
    sBattleTowerSave_Duplicate = &gSaveBlock2Ptr->battleTower;
}

static void PrepareUnknownExchangePacket(struct PlayerRecordsRS *dest)
{
    memcpy(dest->secretBases, sSecretBasesSave, sizeof(dest->secretBases));
    memcpy(dest->tvShows, sTvShowsSave, sizeof(dest->tvShows));
    sub_80F14F8(dest->tvShows);
    memcpy(dest->pokeNews, sPokeNewsSave, sizeof(dest->pokeNews));
    memcpy(&dest->oldMan, sOldManSave, sizeof(dest->oldMan));
    memcpy(dest->easyChatPairs, sEasyChatPairsSave, sizeof(dest->easyChatPairs));
    sub_80E89F8(&dest->dayCareMail);
    sub_81659DC(sBattleTowerSave, &dest->battleTowerRecord);

    if (GetMultiplayerId() == 0)
        dest->battleTowerRecord.unk_11c8 = GetRecordMixingGift();
}

static void PrepareExchangePacketForRubySapphire(struct PlayerRecordsRS *dest)
{
    memcpy(dest->secretBases, sSecretBasesSave, sizeof(dest->secretBases));
    sub_80EB18C(dest->secretBases);
    memcpy(dest->tvShows, sTvShowsSave, sizeof(dest->tvShows));
    sub_80F1208(dest->tvShows);
    memcpy(dest->pokeNews, sPokeNewsSave, sizeof(dest->pokeNews));
    memcpy(&dest->oldMan, sOldManSave, sizeof(dest->oldMan));
    sub_8120B70(&dest->oldMan);
    memcpy(dest->easyChatPairs, sEasyChatPairsSave, sizeof(dest->easyChatPairs));
    sub_80E89F8(&dest->dayCareMail);
    SanitizeDayCareMailForRuby(&dest->dayCareMail);
    sub_81659DC(sBattleTowerSave, &dest->battleTowerRecord);
    SanitizeRubyBattleTowerRecord(&dest->battleTowerRecord);

    if (GetMultiplayerId() == 0)
        dest->battleTowerRecord.unk_11c8 = GetRecordMixingGift();
}

static void PrepareExchangePacket(void)
{
    sub_80E9914();
    sub_80F0BB8();
    SetSrcLookupPointers();

    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (sub_800A03C() == 0)
            PrepareUnknownExchangePacket(&sSentRecord->ruby);
        else
            PrepareExchangePacketForRubySapphire(&sSentRecord->ruby);
    }
    else
    {
        memcpy(sSentRecord->emerald.secretBases, sSecretBasesSave, sizeof(sSentRecord->emerald.secretBases));
        memcpy(sSentRecord->emerald.tvShows, sTvShowsSave, sizeof(sSentRecord->emerald.tvShows));
        memcpy(sSentRecord->emerald.pokeNews, sPokeNewsSave, sizeof(sSentRecord->emerald.pokeNews));
        memcpy(&sSentRecord->emerald.oldMan, sOldManSave, sizeof(sSentRecord->emerald.oldMan));
        memcpy(&sSentRecord->emerald.lilycoveLady, sLilycoveLadySave, sizeof(sSentRecord->emerald.lilycoveLady));
        memcpy(sSentRecord->emerald.easyChatPairs, sEasyChatPairsSave, sizeof(sSentRecord->emerald.easyChatPairs));
        sub_80E89F8(&sSentRecord->emerald.dayCareMail);
        memcpy(&sSentRecord->emerald.battleTowerRecord, sBattleTowerSave, sizeof(sSentRecord->emerald.battleTowerRecord));
        SanitizeEmeraldBattleTowerRecord(&sSentRecord->emerald.battleTowerRecord);

        if (GetMultiplayerId() == 0)
            sSentRecord->emerald.unk_1210 = GetRecordMixingGift();

        sub_80E8110(sSentRecord->emerald.unk_1254, gUnknown_03001154);
        sub_80E8260(&sSentRecord->emerald.unk_12dc);
    }
}

static void ReceiveExchangePacket(u32 which)
{
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        // Ruby/Sapphire
        sub_80E7B2C((void *)sReceivedRecords->ruby.tvShows);
        ReceiveSecretBasesData(sReceivedRecords->ruby.secretBases, sizeof(struct PlayerRecordsRS), which);
        ReceiveDaycareMailData(&sReceivedRecords->ruby.dayCareMail, sizeof(struct PlayerRecordsRS), which, sReceivedRecords->ruby.tvShows);
        ReceiveBattleTowerData(&sReceivedRecords->ruby.battleTowerRecord, sizeof(struct PlayerRecordsRS), which);
        ReceiveTvShowsData(sReceivedRecords->ruby.tvShows, sizeof(struct PlayerRecordsRS), which);
        ReceivePokeNewsData(sReceivedRecords->ruby.pokeNews, sizeof(struct PlayerRecordsRS), which);
        ReceiveOldManData(&sReceivedRecords->ruby.oldMan, sizeof(struct PlayerRecordsRS), which);
        ReceiveEasyChatPairsData(sReceivedRecords->ruby.easyChatPairs, sizeof(struct PlayerRecordsRS), which);
        sub_80E7F68(&sReceivedRecords->ruby.battleTowerRecord.unk_11c8, which);
    }
    else
    {
        // Emerald
        sub_80E7B2C((void *)sReceivedRecords->emerald.tvShows);
        ReceiveSecretBasesData(sReceivedRecords->emerald.secretBases, sizeof(struct PlayerRecordsEmerald), which);
        ReceiveTvShowsData(sReceivedRecords->emerald.tvShows, sizeof(struct PlayerRecordsEmerald), which);
        ReceivePokeNewsData(sReceivedRecords->emerald.pokeNews, sizeof(struct PlayerRecordsEmerald), which);
        ReceiveOldManData(&sReceivedRecords->emerald.oldMan, sizeof(struct PlayerRecordsEmerald), which);
        ReceiveEasyChatPairsData(sReceivedRecords->emerald.easyChatPairs, sizeof(struct PlayerRecordsEmerald), which);
        ReceiveDaycareMailData(&sReceivedRecords->emerald.dayCareMail, sizeof(struct PlayerRecordsEmerald), which, sReceivedRecords->emerald.tvShows);
        ReceiveBattleTowerData(&sReceivedRecords->emerald.battleTowerRecord, sizeof(struct PlayerRecordsEmerald), which);
        sub_80E7F68(&sReceivedRecords->emerald.unk_1210, which);
        ReceiveLilycoveLadyData(&sReceivedRecords->emerald.lilycoveLady, sizeof(struct PlayerRecordsEmerald), which);
        sub_80E8468(sReceivedRecords->emerald.unk_1254, sizeof(struct PlayerRecordsEmerald), (u8) which);
        sub_80E89AC(&sReceivedRecords->emerald.unk_12dc, sizeof(struct PlayerRecordsEmerald), (u8) which);
    }
}

static void PrintTextOnRecordMixing(const u8 *src)
{
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    PrintTextOnWindow(0, 1, src, 0, 1, 0, NULL);
    CopyWindowToVram(0, 3);
}

#define tCounter data[0]

static void Task_RecordMixing_SoundEffect(u8 taskId)
{
    if (++gTasks[taskId].tCounter == 50)
    {
        PlaySE(SE_W213);
        gTasks[taskId].tCounter = 0;
    }
}

#undef tCounter

#define tState        data[0]
#define tSndEffTaskId data[15]

static void Task_RecordMixing_Main(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0: // init
        sSentRecord = malloc(sizeof(union PlayerRecords));
        sReceivedRecords = malloc(sizeof(union PlayerRecords) * 4);
        sub_8009628(gSpecialVar_0x8005);
        VarSet(VAR_TEMP_0, 1);
        gUnknown_03001130 = FALSE;
        PrepareExchangePacket();
        CreateRecordMixingSprite();
        tState = 1;
        data[10] = CreateTask(sub_80E7324, 80);
        tSndEffTaskId = CreateTask(Task_RecordMixing_SoundEffect, 81);
        break;
    case 1: // wait for sub_80E7324
        if (!gTasks[data[10]].isActive)
        {
            tState = 2;
            FlagSet(FLAG_SYS_MIX_RECORD);
            DestroyRecordMixingSprite();
            DestroyTask(tSndEffTaskId);
        }
        break;
    case 2:
        data[10] = CreateTask(sub_80E7FF8, 10);
        tState = 3;
        PlaySE(SE_W226);
        break;
    case 3: // wait for sub_80E7FF8
        if (!gTasks[data[10]].isActive)
        {
            tState = 4;
            if (gWirelessCommType == 0)
                data[10] = sub_80B3050();

            PrintTextOnRecordMixing(gText_RecordMixingComplete);
            data[8] = 0;
        }
        break;
    case 4: // wait 60 frames
        if (++data[8] > 60)
            tState = 5;
        break;
    case 5:
        if (!gTasks[data[10]].isActive)
        {
            free(sReceivedRecords);
            free(sSentRecord);
            sub_808729C();
            if (gWirelessCommType != 0)
            {
                CreateTask(sub_80AF2B4, 10);
            }
            sub_8197434(0, 1);
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
        break;
    }
}

#undef tState
#undef tSndEffTaskId

static void sub_80E7324(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        PrintTextOnRecordMixing(gText_MixingRecords);
        task->data[8] = 0x708;
        task->data[0] = 400;
        ClearLinkCallback_2();
        break;
    case 100: // wait 20 frames
        if (++task->data[12] > 20)
        {
            task->data[12] = 0;
            task->data[0] = 101;
        }
        break;
    case 101:
        {
            u8 players = GetLinkPlayerCount_2();
            if (IsLinkMaster() == TRUE)
            {
                if (players == sub_800AA48())
                {
                    PlaySE(SE_PIN);
                    task->data[0] = 201;
                    task->data[12] = 0;
                }
            }
            else
            {
                PlaySE(SE_BOO);
                task->data[0] = 301;
            }
        }
        break;
    case 201:
        if (sub_800AA48() == GetLinkPlayerCount_2() && ++task->data[12] > (GetLinkPlayerCount_2() * 30))
        {
            sub_800A620();
            task->data[0] = 1;
        }
        break;
    case 301:
        if (sub_800AA48() == GetLinkPlayerCount_2())
            task->data[0] = 1;
        break;
    case 400: // wait 20 frames
        if (++task->data[12] > 20)
        {
            task->data[0] = 1;
            task->data[12] = 0;
        }
        break;
    case 1: // wait for handshake
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ConvertIntToDecimalStringN(gStringVar1, GetMultiplayerId_(), STR_CONV_MODE_LEADING_ZEROS, 2);
            task->data[0] = 5;
        }
        break;
    case 2:
        {
            u8 subTaskId;

            task->data[6] = GetLinkPlayerCount_2();
            task->data[0] = 0;
            task->data[5] = GetMultiplayerId_();
            task->func = Task_SendPacket;
            if (Link_AnyPartnersPlayingRubyOrSapphire())
            {
                StorePtrInTaskData(sSentRecord, (u16 *)&task->data[2]);
                subTaskId = CreateTask(Task_CopyReceiveBuffer, 80);
                task->data[10] = subTaskId;
                gTasks[subTaskId].data[0] = taskId;
                StorePtrInTaskData(sReceivedRecords, (u16 *)&gTasks[subTaskId].data[5]);
                sRecordStructSize = sizeof(struct PlayerRecordsRS);
            }
            else
            {
                StorePtrInTaskData(sSentRecord, (u16 *)&task->data[2]);
                subTaskId = CreateTask(Task_CopyReceiveBuffer, 80);
                task->data[10] = subTaskId;
                gTasks[subTaskId].data[0] = taskId;
                StorePtrInTaskData(sReceivedRecords, (u16 *)&gTasks[subTaskId].data[5]);
                sRecordStructSize = sizeof(struct PlayerRecordsEmerald);
            }
        }
        break;
    case 5: // wait 60 frames
        if (++task->data[10] > 60)
        {
            task->data[10] = 0;
            task->data[0] = 2;
        }
        break;
    }
}

static void Task_SendPacket(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    // does this send the data 24 times?

    switch (task->data[0])
    {
    case 0: // Copy record data to send buffer
        {
            void *recordData = LoadPtrFromTaskData(&task->data[2]) + task->data[4] * BUFFER_CHUNK_SIZE;

            memcpy(gBlockSendBuffer, recordData, BUFFER_CHUNK_SIZE);
            task->data[0]++;
        }
        break;
    case 1:
        if (GetMultiplayerId() == 0)
            sub_800A4D8(1);
        task->data[0]++;
        break;
    case 2:
        break;
    case 3:
        task->data[4]++;
        if (task->data[4] == sRecordStructSize / 200 + 1)
            task->data[0]++;
        else
            task->data[0] = 0;
        break;
    case 4:
        if (!gTasks[task->data[10]].isActive)
            task->func = Task_SendPacket_SwitchToReceive;
        break;
    }
}

static void Task_CopyReceiveBuffer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 status = GetBlockReceivedStatus();
    u8 handledPlayers = 0;

    if (status == sub_800A9D8())
    {
        u8 i;

        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            void *dest;
            void *src;

            if ((status >> i) & 1)
            {
                dest = LoadPtrFromTaskData((u16 *)&task->data[5]) + task->data[i + 1] * BUFFER_CHUNK_SIZE + sRecordStructSize * i;
                src = GetPlayerRecvBuffer(i);
                if ((task->data[i + 1] + 1) * BUFFER_CHUNK_SIZE > sRecordStructSize)
                    memcpy(dest, src, sRecordStructSize - task->data[i + 1] * BUFFER_CHUNK_SIZE);
                else
                    memcpy(dest, src, BUFFER_CHUNK_SIZE);
                ResetBlockReceivedFlag(i);
                task->data[i + 1]++;
                if (task->data[i + 1] == sRecordStructSize / BUFFER_CHUNK_SIZE + 1)
                    handledPlayers++;
            }
        }
        gTasks[task->data[0]].data[0]++;
    }

    if (handledPlayers == GetLinkPlayerCount())
        DestroyTask(taskId);
}

static void sub_80E776C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (!gTasks[task->data[10]].isActive)
        DestroyTask(taskId);
}

static void Task_ReceivePacket(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->func = sub_80E776C;
    if (gUnknown_03001130 == TRUE)
        ReceiveExchangePacket(task->data[5]);
}

static void Task_SendPacket_SwitchToReceive(u8 taskId)
{
    gTasks[taskId].func = Task_ReceivePacket;
    gUnknown_03001130 = TRUE;
}

static void *LoadPtrFromTaskData(const u16 *asShort)
{
    return (void *)(asShort[0] | (asShort[1] << 16));
}

static void StorePtrInTaskData(void *records, u16 *asShort)
{
    asShort[0] = (u32)records;
    asShort[1] = ((u32)records >> 16);
}

static u8 GetMultiplayerId_(void)
{
    return GetMultiplayerId();
}

static void *GetPlayerRecvBuffer(u8 id)
{
    return gBlockRecvBuffer[id];
}

static void ShufflePlayerIndices(u32 *data)
{
    u32 i;
    u32 linkTrainerId;
    u32 players = GetLinkPlayerCount();

    switch (players)
    {
    case 2:
        for (i = 0; i < 2; i++)
            data[i] = gUnknown_0858CF8C[i];
        break;
    case 3:
        linkTrainerId = GetLinkPlayerTrainerId(0) % 2;
        for (i = 0; i < 3; i++)
            data[i] = gUnknown_0858CF8E[linkTrainerId][i];
        break;
    case 4:
        linkTrainerId = GetLinkPlayerTrainerId(0) % 9;
        for (i = 0; i < 4; i++)
            data[i] = gUnknown_0858CF94[linkTrainerId][i];
        break;
    }
}

static void ReceiveOldManData(OldMan *oldMan, size_t recordSize, u8 which)
{
    u8 version;
    u16 language;
    OldMan *dest;
    u32 mixIndices[4];

    ShufflePlayerIndices(mixIndices);
    dest = (void *)oldMan + recordSize * mixIndices[which];
    version = gLinkPlayers[mixIndices[which]].version;
    language = gLinkPlayers[mixIndices[which]].language;

    if (Link_AnyPartnersPlayingRubyOrSapphire())
        SanitizeReceivedRubyOldMan(dest, version, language);
    else
        SanitizeReceivedEmeraldOldMan(dest, version, language);

    memcpy(sOldManSave, (void *)oldMan + recordSize * mixIndices[which], sizeof(OldMan));
    ResetMauvilleOldManFlag();
}

static void ReceiveBattleTowerData(void *battleTowerRecord, size_t recordSize, u8 which)
{
    struct EmeraldBattleTowerRecord *dest;
    struct UnknownPokemonStruct *btPokemon;
    u32 mixIndices[4];
    s32 i;

    ShufflePlayerIndices(mixIndices);
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (sub_816587C((void *)battleTowerRecord + recordSize * mixIndices[which], (void *)battleTowerRecord + recordSize * which) == TRUE)
        {
            dest = (void *)battleTowerRecord + recordSize * which;
            dest->language = gLinkPlayers[mixIndices[which]].language;
            CalcEmeraldBattleTowerChecksum(dest);
        }
    }
    else
    {
        memcpy((void *)battleTowerRecord + recordSize * which, (void *)battleTowerRecord + recordSize * mixIndices[which], sizeof(union BattleTowerRecord));
        dest = (void *)battleTowerRecord + recordSize * which;
        for (i = 0; i < 4; i ++)
        {
            btPokemon = &dest->party[i];
            if (btPokemon->species != SPECIES_NONE && IsStringJapanese(btPokemon->nickname))
                ConvertInternationalString(btPokemon->nickname, LANGUAGE_JAPANESE);
        }
        CalcEmeraldBattleTowerChecksum(dest);
    }
    sub_81628A0((void *)battleTowerRecord + recordSize * which);
}

static void ReceiveLilycoveLadyData(LilycoveLady *lilycoveLady, size_t recordSize, u8 which)
{
    LilycoveLady *dest;
    u32 mixIndices[4];

    ShufflePlayerIndices(mixIndices);
    memcpy((void *)lilycoveLady + recordSize * which, sLilycoveLadySave, sizeof(LilycoveLady));

    if (GetLilycoveLadyId() == 0)
    {
        dest = malloc(sizeof(LilycoveLady));
        if (dest == NULL)
            return;

        memcpy(dest, sLilycoveLadySave, sizeof(LilycoveLady));
    }
    else
    {
        dest = NULL;
    }

    memcpy(sLilycoveLadySave, (void *)lilycoveLady + recordSize * mixIndices[which], sizeof(LilycoveLady));
    sub_818DA78();
    if (dest != NULL)
    {
        sub_818E570(dest);
        free(dest);
    }
}

static u8 sub_80E7A9C(struct DayCareMail *rmMail)
{
    return rmMail->message.itemId;
}

static void sub_80E7AA4(struct RecordMixingDayCareMail *src, size_t recordSize, u8 (*idxs)[2], u8 which0, u8 which1)
{
    struct DayCareMail buffer;
    struct RecordMixingDayCareMail *mail1;
    struct RecordMixingDayCareMail *mail2;

    mail1 = (void *)src + recordSize * idxs[which0][0];
    memcpy(&buffer, &mail1->mail[idxs[which0][1]], sizeof(struct DayCareMail));
    mail2 = (void *)src + recordSize * idxs[which1][0];
    memcpy(&mail1->mail[idxs[which0][1]], &mail2->mail[idxs[which1][1]], sizeof(struct DayCareMail));
    memcpy(&mail2->mail[idxs[which1][1]], &buffer, sizeof(struct DayCareMail));
}

static void sub_80E7B2C(const u8 *src)
{
    u8 sum;
    s32 i;

    sum = 0;
    for (i = 0; i < 256; i ++)
        sum += src[i];

    gUnknown_03001160 = sum;
}

static u8 sub_80E7B54(void)
{
    return gUnknown_03001160;
}

#ifdef NONMATCHING
static void ReceiveDaycareMailData(struct RecordMixingDayCareMail *src, size_t recordSize, u8 which, TVShow *shows)
{
    // r9 = which
    u16 i;
    u16 j;
    u8 linkPlayerCount;
    u16 language;
    u16 otNameLanguage;
    u16 nicknameLanguage;
    u32 version;
    u8 dcMail1;
    u8 dcMail2;
    u8 r1_80e7b54;
    struct DayCareMail *recordMixingMail;
    struct RecordMixingDayCareMail *_src;
    u8 sp04[4];
    u8 sp08[4];
    struct RecordMixingDayCareMail *sp0c[4]; // -> sp+48
    u8 sp1c[4][2]; // [][0] -> sp+4c, [][1] -> sp+50
    u8 sp24[4][2];
    // sp+2c = src
    // sp+30 = recordSize
    u8 sp34;
    u16 oldSeed;
    bool32 anyRS; // sp+3c

    oldSeed = Random2();
    SeedRng2(gLinkPlayers[0].trainerId);
    linkPlayerCount = GetLinkPlayerCount();
    for (i = 0; i < 4; i ++)
    {
        sp04[i] = 0xFF;
        sp08[i] = 0;
        sp1c[i][0] = 0;
        sp1c[i][1] = 0;
    }
    anyRS = Link_AnyPartnersPlayingRubyOrSapphire();
    for (i = 0; i < GetLinkPlayerCount(); i ++) // r8 = i
    {
        // sp+54 = linkPlayerCount << 16
        // sp+44 = which * recordSize
        _src = (void *)src + i * recordSize; // r7
        language = gLinkPlayers[i].language; // r9
        version = (u8)gLinkPlayers[i].version; // sp+40
        for (j = 0; j < _src->unk_70; j ++)
        {
            // r10 = ~0x10
            recordMixingMail = &_src->unk_00[j];
            if (recordMixingMail->mail.itemId != ITEM_NONE)
            {
                if (anyRS)
                {
                    if (StringLength(recordMixingMail->OT_name) <= 5)
                    {
                        otNameLanguage = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        StripExtCtrlCodes(recordMixingMail->OT_name);
                        otNameLanguage = language;
                    }
                    if (recordMixingMail->monName[0] == EXT_CTRL_CODE_BEGIN && recordMixingMail->monName[1] == EXT_CTRL_CODE_JPN)
                    {
                        StripExtCtrlCodes(recordMixingMail->monName);
                        nicknameLanguage = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        nicknameLanguage = language;
                    }
                    if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
                    {
                        recordMixingMail->language_maybe = otNameLanguage;
                        recordMixingMail->unknown = nicknameLanguage;
                    }
                }
                else if (language == LANGUAGE_JAPANESE)
                {
                    if (IsStringJapanese(recordMixingMail->OT_name))
                    {
                        recordMixingMail->language_maybe = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        recordMixingMail->language_maybe = GAME_LANGUAGE;
                    }
                    if (IsStringJapanese(recordMixingMail->monName))
                    {
                        recordMixingMail->unknown = LANGUAGE_JAPANESE;
                    }
                    else
                    {
                        recordMixingMail->unknown = GAME_LANGUAGE;
                    }
                }
            }
        }
    }
    sp34 = 0;
    for (i = 0; i < linkPlayerCount; i ++)
    {
        _src = (void *)src + i * recordSize; // r7
        if (_src->unk_70 != 0)
        {
            for (j = 0; j < _src->unk_70; j ++)
            {
                if (_src->unk_74[j] == 0)
                {
                    sp1c[i][j] = 1;
                }
            }
        }
    }
    i = 0;
    for (j = 0; j < linkPlayerCount; j ++)
    {
        _src = (void *)src + j * recordSize;
        if (sp1c[j][0] == TRUE || sp1c[j][1] == TRUE)
        {
            sp34 ++;
        }
        if (sp1c[j][0] == TRUE && sp1c[j][1] == FALSE)
        {
            sp24[i][0] = j;
            sp24[i][1] = 0;
            i ++;
        }
        else if (sp1c[j][0] == FALSE && sp1c[j][1] == TRUE)
        {
            sp24[i][0] = j;
            sp24[i][1] = 0;
            i ++;
        }
        else if (sp1c[j][0] == TRUE && sp1c[j][1] == TRUE)
        {
            sp24[i][0] = j;
            dcMail1 = sub_80E7A9C(&_src->unk_00[0]);
            dcMail2 = sub_80E7A9C(&_src->unk_00[1]);
            if (!dcMail1 && dcMail2)
            {
                sp24[i][1] = 1;
            }
            else if ((dcMail1 && dcMail2) || (!dcMail1 && !dcMail2))
            {
                sp24[i][1] = Random2() % 2;
            }
            else
            {
                sp24[i][1] = 0;
            }
            i ++;
        }
    }
    for (i = 0; i < 4; i ++)
    {
        _src = &src[which * recordSize];
        sp0c[i] = _src;
    }
    r1_80e7b54 = sub_80E7B54() % 3;
    switch (sp34)
    {
        case 2:
            sub_80E7AA4(src, recordSize, sp24, 0, 1);
            break;
        case 3:
            sub_80E7AA4(src, recordSize, sp24, gUnknown_0858CFB8[r1_80e7b54][0], gUnknown_0858CFB8[r1_80e7b54][1]);
            break;
        case 4:
            sub_80E7AA4(src, recordSize, sp24, gUnknown_0858CFBE[r1_80e7b54][0], gUnknown_0858CFBE[r1_80e7b54][1]);
            sub_80E7AA4(src, recordSize, sp24, gUnknown_0858CFBE[r1_80e7b54][2], gUnknown_0858CFBE[r1_80e7b54][3]);
            break;
    }
    _src = (void *)src + which * recordSize;
    memcpy(&gSaveBlock1Ptr->daycare.mons[0].misc.mail, &_src->unk_00[0], sizeof(struct DayCareMail));
    memcpy(&gSaveBlock1Ptr->daycare.mons[1].misc.mail, &_src->unk_00[1], sizeof(struct DayCareMail));
    SeedRng(oldSeed);
}
#else
NAKED
static void ReceiveDaycareMailData(struct RecordMixingDayCareMail *src, size_t recordSize, u8 which, TVShow *shows)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tsub sp, 0x58\n"
                    "\tstr r0, [sp, 0x2C]\n"
                    "\tstr r1, [sp, 0x30]\n"
                    "\tlsls r2, 24\n"
                    "\tlsrs r2, 24\n"
                    "\tmov r9, r2\n"
                    "\tbl Random2\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tstr r0, [sp, 0x38]\n"
                    "\tldr r0, =gLinkPlayers\n"
                    "\tldrh r0, [r0, 0x4]\n"
                    "\tbl SeedRng2\n"
                    "\tbl GetLinkPlayerCount\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r4, r0, 24\n"
                    "\tmovs r0, 0\n"
                    "\tmov r8, r0\n"
                    "\tmov r1, sp\n"
                    "\tadds r1, 0x1C\n"
                    "\tstr r1, [sp, 0x4C]\n"
                    "\tmov r2, sp\n"
                    "\tadds r2, 0x1D\n"
                    "\tstr r2, [sp, 0x50]\n"
                    "\tmov r3, sp\n"
                    "\tadds r3, 0xC\n"
                    "\tstr r3, [sp, 0x48]\n"
                    "\tmovs r7, 0xFF\n"
                    "\tadd r3, sp, 0x8\n"
                    "\tmovs r2, 0\n"
                    "\tadds r6, r1, 0\n"
                    "\tldr r5, [sp, 0x50]\n"
                    "_080E7BB0:\n"
                    "\tmov r1, sp\n"
                    "\tadd r1, r8\n"
                    "\tadds r1, 0x4\n"
                    "\tldrb r0, [r1]\n"
                    "\torrs r0, r7\n"
                    "\tstrb r0, [r1]\n"
                    "\tmov r1, r8\n"
                    "\tadds r0, r3, r1\n"
                    "\tstrb r2, [r0]\n"
                    "\tlsls r1, 1\n"
                    "\tadds r0, r6, r1\n"
                    "\tstrb r2, [r0]\n"
                    "\tadds r1, r5, r1\n"
                    "\tstrb r2, [r1]\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "\tcmp r0, 0x3\n"
                    "\tbls _080E7BB0\n"
                    "\tbl Link_AnyPartnersPlayingRubyOrSapphire\n"
                    "\tstr r0, [sp, 0x3C]\n"
                    "\tmovs r2, 0\n"
                    "\tmov r8, r2\n"
                    "\tlsls r4, 16\n"
                    "\tstr r4, [sp, 0x54]\n"
                    "\tldr r0, [sp, 0x30]\n"
                    "\tmov r3, r9\n"
                    "\tmuls r3, r0\n"
                    "\tstr r3, [sp, 0x44]\n"
                    "\tb _080E7D04\n"
                    "\t.pool\n"
                    "_080E7BF8:\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tmov r0, r8\n"
                    "\tmuls r0, r1\n"
                    "\tldr r2, [sp, 0x2C]\n"
                    "\tadds r7, r2, r0\n"
                    "\tldr r1, =gLinkPlayers\n"
                    "\tmov r3, r8\n"
                    "\tlsls r0, r3, 3\n"
                    "\tsubs r0, r3\n"
                    "\tlsls r0, 2\n"
                    "\tadds r0, r1\n"
                    "\tldrh r1, [r0, 0x1A]\n"
                    "\tmov r9, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tstr r0, [sp, 0x40]\n"
                    "\tmovs r6, 0\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r6, r0\n"
                    "\tbcs _080E7CFA\n"
                    "\tmovs r2, 0x10\n"
                    "\tnegs r2, r2\n"
                    "\tmov r10, r2\n"
                    "_080E7C24:\n"
                    "\tlsls r0, r6, 3\n"
                    "\tsubs r0, r6\n"
                    "\tlsls r0, 3\n"
                    "\tadds r5, r7, r0\n"
                    "\tldrh r0, [r5, 0x20]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7CEE\n"
                    "\tldr r3, [sp, 0x3C]\n"
                    "\tcmp r3, 0\n"
                    "\tbeq _080E7C9A\n"
                    "\tadds r4, r5, 0\n"
                    "\tadds r4, 0x24\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl StringLength\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tcmp r0, 0x5\n"
                    "\tbhi _080E7C54\n"
                    "\tmovs r4, 0x1\n"
                    "\tb _080E7C5C\n"
                    "\t.pool\n"
                    "_080E7C54:\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl StripExtCtrlCodes\n"
                    "\tmov r4, r9\n"
                    "_080E7C5C:\n"
                    "\tldrh r1, [r5, 0x2C]\n"
                    "\tldr r0, =0x000015fc\n"
                    "\tcmp r1, r0\n"
                    "\tbne _080E7C74\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x2C\n"
                    "\tbl StripExtCtrlCodes\n"
                    "\tmovs r1, 0x1\n"
                    "\tb _080E7C76\n"
                    "\t.pool\n"
                    "_080E7C74:\n"
                    "\tmov r1, r9\n"
                    "_080E7C76:\n"
                    "\tldr r0, [sp, 0x40]\n"
                    "\tsubs r0, 0x1\n"
                    "\tcmp r0, 0x1\n"
                    "\tbhi _080E7CEE\n"
                    "\tadds r2, r5, 0\n"
                    "\tadds r2, 0x37\n"
                    "\tmovs r0, 0xF\n"
                    "\tands r4, r0\n"
                    "\tldrb r0, [r2]\n"
                    "\tmov r3, r10\n"
                    "\tands r0, r3\n"
                    "\torrs r0, r4\n"
                    "\tlsls r1, 4\n"
                    "\tmovs r3, 0xF\n"
                    "\tands r0, r3\n"
                    "\torrs r0, r1\n"
                    "\tstrb r0, [r2]\n"
                    "\tb _080E7CEE\n"
                    "_080E7C9A:\n"
                    "\tmov r0, r9\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7CEE\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x24\n"
                    "\tbl IsStringJapanese\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7CBA\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x37\n"
                    "\tldrb r1, [r0]\n"
                    "\tmov r2, r10\n"
                    "\tands r1, r2\n"
                    "\tmovs r2, 0x1\n"
                    "\tb _080E7CC6\n"
                    "_080E7CBA:\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x37\n"
                    "\tldrb r1, [r0]\n"
                    "\tmov r3, r10\n"
                    "\tands r1, r3\n"
                    "\tmovs r2, 0x2\n"
                    "_080E7CC6:\n"
                    "\torrs r1, r2\n"
                    "\tstrb r1, [r0]\n"
                    "\tadds r4, r0, 0\n"
                    "\tadds r0, r5, 0\n"
                    "\tadds r0, 0x2C\n"
                    "\tbl IsStringJapanese\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7CE2\n"
                    "\tldrb r0, [r4]\n"
                    "\tmovs r1, 0xF\n"
                    "\tands r1, r0\n"
                    "\tmovs r0, 0x10\n"
                    "\tb _080E7CEA\n"
                    "_080E7CE2:\n"
                    "\tldrb r0, [r4]\n"
                    "\tmovs r1, 0xF\n"
                    "\tands r1, r0\n"
                    "\tmovs r0, 0x20\n"
                    "_080E7CEA:\n"
                    "\torrs r1, r0\n"
                    "\tstrb r1, [r4]\n"
                    "_080E7CEE:\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r6, r0\n"
                    "\tbcc _080E7C24\n"
                    "_080E7CFA:\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "_080E7D04:\n"
                    "\tbl GetLinkPlayerCount\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tcmp r8, r0\n"
                    "\tbcs _080E7D12\n"
                    "\tb _080E7BF8\n"
                    "_080E7D12:\n"
                    "\tmovs r0, 0\n"
                    "\tstr r0, [sp, 0x34]\n"
                    "\tmov r8, r0\n"
                    "\tldr r1, [sp, 0x54]\n"
                    "\tlsrs r0, r1, 16\n"
                    "\tldr r2, [sp, 0x34]\n"
                    "\tcmp r2, r0\n"
                    "\tbcs _080E7D70\n"
                    "\tadds r5, r0, 0\n"
                    "_080E7D24:\n"
                    "\tldr r3, [sp, 0x30]\n"
                    "\tmov r0, r8\n"
                    "\tmuls r0, r3\n"
                    "\tldr r1, [sp, 0x2C]\n"
                    "\tadds r7, r1, r0\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E7D62\n"
                    "\tmovs r6, 0\n"
                    "\tcmp r6, r0\n"
                    "\tbcs _080E7D62\n"
                    "\tadds r3, r7, 0\n"
                    "\tadds r3, 0x74\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tmov r0, r8\n"
                    "\tlsls r1, r0, 1\n"
                    "\tmovs r4, 0x1\n"
                    "_080E7D46:\n"
                    "\tlsls r0, r6, 1\n"
                    "\tadds r0, r3, r0\n"
                    "\tldrh r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080E7D56\n"
                    "\tadds r0, r6, r1\n"
                    "\tadds r0, r2, r0\n"
                    "\tstrb r4, [r0]\n"
                    "_080E7D56:\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "\tldr r0, [r7, 0x70]\n"
                    "\tcmp r6, r0\n"
                    "\tbcc _080E7D46\n"
                    "_080E7D62:\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "\tcmp r8, r5\n"
                    "\tbcc _080E7D24\n"
                    "_080E7D70:\n"
                    "\tmovs r6, 0\n"
                    "\tmov r8, r6\n"
                    "\tldr r1, [sp, 0x54]\n"
                    "\tcmp r1, 0\n"
                    "\tbeq _080E7E64\n"
                    "\tadd r2, sp, 0x24\n"
                    "\tmov r10, r2\n"
                    "\tmovs r3, 0x25\n"
                    "\tadd r3, sp\n"
                    "\tmov r9, r3\n"
                    "_080E7D84:\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tmov r0, r8\n"
                    "\tmuls r0, r1\n"
                    "\tldr r2, [sp, 0x2C]\n"
                    "\tadds r7, r2, r0\n"
                    "\tmov r3, r8\n"
                    "\tlsls r1, r3, 1\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbeq _080E7DA6\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7DB0\n"
                    "_080E7DA6:\n"
                    "\tldr r0, [sp, 0x34]\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tstr r0, [sp, 0x34]\n"
                    "_080E7DB0:\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7DD4\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r2, [r0]\n"
                    "\tcmp r2, 0\n"
                    "\tbne _080E7DD4\n"
                    "_080E7DC4:\n"
                    "\tlsls r1, r6, 1\n"
                    "\tmov r3, r10\n"
                    "\tadds r0, r3, r1\n"
                    "\tmov r3, r8\n"
                    "\tstrb r3, [r0]\n"
                    "\tadd r1, r9\n"
                    "\tstrb r2, [r1]\n"
                    "\tb _080E7E4E\n"
                    "_080E7DD4:\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080E7DE8\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r2, [r0]\n"
                    "\tcmp r2, 0x1\n"
                    "\tbeq _080E7DC4\n"
                    "_080E7DE8:\n"
                    "\tldr r2, [sp, 0x4C]\n"
                    "\tadds r0, r2, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7E54\n"
                    "\tldr r3, [sp, 0x50]\n"
                    "\tadds r0, r3, r1\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080E7E54\n"
                    "\tlsls r5, r6, 1\n"
                    "\tmov r1, r10\n"
                    "\tadds r0, r1, r5\n"
                    "\tmov r2, r8\n"
                    "\tstrb r2, [r0]\n"
                    "\tadds r0, r7, 0\n"
                    "\tbl sub_80E7A9C\n"
                    "\tadds r4, r0, 0\n"
                    "\tlsls r4, 24\n"
                    "\tlsrs r4, 24\n"
                    "\tadds r0, r7, 0\n"
                    "\tadds r0, 0x38\n"
                    "\tbl sub_80E7A9C\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r1, r0, 24\n"
                    "\tcmp r4, 0\n"
                    "\tbne _080E7E30\n"
                    "\tcmp r1, 0\n"
                    "\tbeq _080E7E34\n"
                    "\tmov r3, r9\n"
                    "\tadds r1, r3, r5\n"
                    "\tmovs r0, 0x1\n"
                    "\tstrb r0, [r1]\n"
                    "\tb _080E7E4E\n"
                    "_080E7E30:\n"
                    "\tcmp r1, 0\n"
                    "\tbeq _080E7E48\n"
                    "_080E7E34:\n"
                    "\tbl Random2\n"
                    "\tmov r1, r9\n"
                    "\tadds r2, r1, r5\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmovs r1, 0x1\n"
                    "\tands r0, r1\n"
                    "\tstrb r0, [r2]\n"
                    "\tb _080E7E4E\n"
                    "_080E7E48:\n"
                    "\tmov r2, r9\n"
                    "\tadds r0, r2, r5\n"
                    "\tstrb r1, [r0]\n"
                    "_080E7E4E:\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "_080E7E54:\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r3, r0, 16\n"
                    "\tmov r8, r3\n"
                    "\tldr r1, [sp, 0x54]\n"
                    "\tcmp r0, r1\n"
                    "\tbcc _080E7D84\n"
                    "_080E7E64:\n"
                    "\tmovs r2, 0\n"
                    "\tmov r8, r2\n"
                    "\tldr r3, [sp, 0x44]\n"
                    "\tlsls r0, r3, 4\n"
                    "\tsubs r0, r3\n"
                    "\tlsls r0, 3\n"
                    "\tldr r1, [sp, 0x2C]\n"
                    "\tadds r7, r1, r0\n"
                    "\tldr r1, [sp, 0x48]\n"
                    "_080E7E76:\n"
                    "\tmov r2, r8\n"
                    "\tlsls r0, r2, 2\n"
                    "\tadds r0, r1, r0\n"
                    "\tstr r7, [r0]\n"
                    "\tmov r0, r8\n"
                    "\tadds r0, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r8, r0\n"
                    "\tcmp r0, 0x3\n"
                    "\tbls _080E7E76\n"
                    "\tbl sub_80E7B54\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r0, 24\n"
                    "\tmovs r1, 0x3\n"
                    "\tbl __umodsi3\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r1, r0, 24\n"
                    "\tldr r3, [sp, 0x34]\n"
                    "\tcmp r3, 0x3\n"
                    "\tbeq _080E7EC8\n"
                    "\tcmp r3, 0x3\n"
                    "\tbgt _080E7EAE\n"
                    "\tcmp r3, 0x2\n"
                    "\tbeq _080E7EB6\n"
                    "\tb _080E7F1C\n"
                    "_080E7EAE:\n"
                    "\tldr r0, [sp, 0x34]\n"
                    "\tcmp r0, 0x4\n"
                    "\tbeq _080E7EE8\n"
                    "\tb _080E7F1C\n"
                    "_080E7EB6:\n"
                    "\tadd r2, sp, 0x24\n"
                    "\tmovs r0, 0x1\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tmovs r3, 0\n"
                    "\tbl sub_80E7AA4\n"
                    "\tb _080E7F1C\n"
                    "_080E7EC8:\n"
                    "\tldr r0, =gUnknown_0858CFB8\n"
                    "\tlsls r1, 1\n"
                    "\tadds r2, r1, r0\n"
                    "\tldrb r3, [r2]\n"
                    "\tadds r0, 0x1\n"
                    "\tadds r1, r0\n"
                    "\tldrb r0, [r1]\n"
                    "\tadd r2, sp, 0x24\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tbl sub_80E7AA4\n"
                    "\tb _080E7F1C\n"
                    "\t.pool\n"
                    "_080E7EE8:\n"
                    "\tadd r6, sp, 0x24\n"
                    "\tldr r4, =gUnknown_0858CFBE\n"
                    "\tlsls r5, r1, 2\n"
                    "\tadds r0, r5, r4\n"
                    "\tldrb r3, [r0]\n"
                    "\tadds r0, r4, 0x1\n"
                    "\tadds r0, r5, r0\n"
                    "\tldrb r0, [r0]\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tadds r2, r6, 0\n"
                    "\tbl sub_80E7AA4\n"
                    "\tadds r0, r4, 0x2\n"
                    "\tadds r0, r5, r0\n"
                    "\tldrb r3, [r0]\n"
                    "\tadds r4, 0x3\n"
                    "\tadds r5, r4\n"
                    "\tldrb r0, [r5]\n"
                    "\tstr r0, [sp]\n"
                    "\tldr r0, [sp, 0x2C]\n"
                    "\tldr r1, [sp, 0x30]\n"
                    "\tadds r2, r6, 0\n"
                    "\tbl sub_80E7AA4\n"
                    "_080E7F1C:\n"
                    "\tldr r1, [sp, 0x2C]\n"
                    "\tldr r2, [sp, 0x44]\n"
                    "\tadds r7, r1, r2\n"
                    "\tldr r4, =gSaveBlock1Ptr\n"
                    "\tldr r0, [r4]\n"
                    "\tmovs r3, 0xC2\n"
                    "\tlsls r3, 6\n"
                    "\tadds r0, r3\n"
                    "\tadds r1, r7, 0\n"
                    "\tmovs r2, 0x38\n"
                    "\tbl memcpy\n"
                    "\tldr r0, [r4]\n"
                    "\tldr r1, =0x0000310c\n"
                    "\tadds r0, r1\n"
                    "\tadds r1, r7, 0\n"
                    "\tadds r1, 0x38\n"
                    "\tmovs r2, 0x38\n"
                    "\tbl memcpy\n"
                    "\tldr r0, [sp, 0x38]\n"
                    "\tbl SeedRng\n"
                    "\tadd sp, 0x58\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif // NONMATCHING

static void sub_80E7F68(u16 *item, u8 which)
{
    if (which != 0 && *item != ITEM_NONE && GetPocketByItemId(*item) == POCKET_KEY_ITEMS)
    {
        if (!CheckBagHasItem(*item, 1) && !CheckPCHasItem(*item, 1) && AddBagItem(*item, 1))
        {
            VarSet(VAR_TEMP_1, *item);
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            if (*item == ITEM_EON_TICKET)
                FlagSet(FLAG_SYS_HAS_EON_TICKET);
        }
        else
        {
            VarSet(VAR_TEMP_1, ITEM_NONE);
        }
    }
}

static void sub_80E7FF8(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[0]++;
        break;
    case 1:
        if (Link_AnyPartnersPlayingRubyOrSapphire())
            task->data[0]++;
        else
            task->data[0] = 6;
        break;
    case 2:
        sub_8076D5C();
        sub_8153430();
        task->data[0] ++;
        break;
    case 3:
        if (sub_8153474())
        {
            sav2_gender2_inplace_and_xFE();
            task->data[0] = 4;
            task->data[1] = 0;
        }
        break;
    case 4:
        if (++task->data[1] > 10)
        {
            sub_800AC34();
            task->data[0] ++;
        }
        break;
    case 5:
        if (gReceivedRemoteLinkPlayers == 0)
            DestroyTask(taskId);
        break;
    case 6:
        if (!sub_801048C(0))
        {
            CreateTask(sub_8153688, 5);
            task->data[0] ++;
        }
        break;
    case 7:
        if (!FuncIsActiveTask(sub_8153688))
        {
            if (gWirelessCommType)
            {
                sub_801048C(1);
                task->data[0] = 8;
            }
            else
            {
                task->data[0] = 4;
            }
        }
        break;
    case 8:
        sub_800ADF8();
        task->data[0] ++;
        break;
    case 9:
        if (sub_800A520())
            DestroyTask(taskId);
        break;
    }
}

// New Emerald functions

static void sub_80E8110(struct UnkRecordMixingStruct *dst, struct UnkRecordMixingStruct *src)
{
    s32 i, id;
    s32 var_2C, var_28, var_24, r8;

    dst[0].field_38[0] = 0xFF;
    dst[1].field_38[0] = 0xFF;

    dst[0] = src[0];

    var_28 = 0;
    var_24 = 0;
    var_2C = 0;
    r8 = 0;
    for (i = 0; i < 2; i++)
    {
        id = ((i + gSaveBlock2Ptr->field_B2_1) % 3) + 1;
        if (src[id].field_38[0] != 0xFF)
        {
            if (ReadUnalignedWord(src[id].playerId) != ReadUnalignedWord(gSaveBlock2Ptr->playerTrainerId))
            {
                r8++;
                var_2C = id;
            }
            if (ReadUnalignedWord(src[id].playerId) == ReadUnalignedWord(gSaveBlock2Ptr->playerTrainerId))
            {
                var_24++;
                var_28 = id;
            }
        }
    }

    if (r8 == 0 && var_24 != 0)
    {
        r8 = var_24;
        var_2C = var_28;
    }

    switch (r8)
    {
    case 1:
        dst[1] = src[var_2C];
        break;
    case 2:
        if (Random2() > 0x3333)
        {
            dst[1] = src[gSaveBlock2Ptr->field_B2_1 + 1];
        }
        else
        {
            dst[1] = src[((gSaveBlock2Ptr->field_B2_1 + 1) % 3 + 1)];
        }
        break;
    }
}

void sub_80E8260(struct UnkRecordMixingStruct2 *dst)
{
    s32 i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 2; j++)
        {
            CopyUnalignedWord(dst->field_0[i][j].playerId, gSaveBlock2Ptr->playerTrainerId);
            dst->field_0[i][j].language = LANGUAGE_ENGLISH;
            StringCopy(dst->field_0[i][j].playerName, gSaveBlock2Ptr->playerName);
        }
    }

    for (j = 0; j < 2; j++)
    {
        dst->field_120[j].language = LANGUAGE_ENGLISH;
        CopyUnalignedWord(dst->field_120[j].playerId1, gSaveBlock2Ptr->playerTrainerId);
        CopyUnalignedWord(dst->field_120[j].playerId2, gSaveBlock2Ptr->field_EF1[j]);
        StringCopy(dst->field_120[j].playerName1, gSaveBlock2Ptr->playerName);
        StringCopy(dst->field_120[j].playerName2, gSaveBlock2Ptr->field_EE1[j]);
    }

    for (i = 0; i < 2; i++)
    {
        dst->field_0[0][i].field_4 = gSaveBlock2Ptr->field_CF0[i];
        dst->field_0[1][i].field_4 = gSaveBlock2Ptr->field_CF4[i];
        dst->field_0[2][i].field_4 = gSaveBlock2Ptr->field_CF8[i];
        dst->field_0[3][i].field_4 = gSaveBlock2Ptr->field_D14[i];
        dst->field_0[4][i].field_4 = gSaveBlock2Ptr->field_DD0[i];
        dst->field_0[5][i].field_4 = gSaveBlock2Ptr->field_DDE[i];
        dst->field_0[6][i].field_4 = gSaveBlock2Ptr->field_DEA[i];
        dst->field_0[7][i].field_4 = gSaveBlock2Ptr->field_E08[i];
        dst->field_0[8][i].field_4 = gSaveBlock2Ptr->field_E1E[i];

        dst->field_120[i].field_8 = gSaveBlock2Ptr->field_CFC[i];
    }
}

static bool32 sub_80E841C(struct UnkRecordMixingStruct *arg0, struct UnkRecordMixingStruct *arg1)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (ReadUnalignedWord(arg0->playerId) == ReadUnalignedWord(arg1[i].playerId)
            && arg0->field_0[2] == arg1[i].field_0[2])
        {
            return TRUE;
        }
    }

    return FALSE;
}

static void sub_80E8468(struct UnkRecordMixingStruct *arg0, size_t arg1, u32 arg2)
{
    s32 i, r7, r8;
    struct UnkRecordMixingStruct *structPtr;
    u32 mixIndices[4];
    u32 structId;

    ShufflePlayerIndices(mixIndices);
    structPtr = (void*)(arg0) + (arg1 * mixIndices[arg2]);
    r7 = 0;
    r8 = 0;
    for (i = 0; i < 2; i++)
    {
        if (structPtr[i].field_38[0] != 0xFF && !sub_80E841C(&structPtr[i], gSaveBlock2Ptr->field_DC))
        {
            r7++;
            r8 = i;
        }
    }

    switch (r7)
    {
    case 1:
        structId = gSaveBlock2Ptr->field_B2_1 + 1;
        gSaveBlock2Ptr->field_DC[structId] = structPtr[r8];
        gSaveBlock2Ptr->field_B2_1 = (gSaveBlock2Ptr->field_B2_1 + 1) % 3;
        break;
    case 2:
        for (i = 0; i < 2; i++)
        {
            structId = ((i ^ 1) + gSaveBlock2Ptr->field_B2_1) % 3 + 1;
            gSaveBlock2Ptr->field_DC[structId] = structPtr[i];
        }
        gSaveBlock2Ptr->field_B2_1 = (gSaveBlock2Ptr->field_B2_1 + 2) % 3;
        break;
    }
}

NAKED
static void sub_80E8578(struct UnknownRecMixingStruct3 *arg0, struct UnkRecordMixingStruct2 *arg1, size_t arg2, u32 arg3, u32 arg4)
{
    asm_unified("	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x54\n\
	str r0, [sp]\n\
	ldr r0, [sp, 0x74]\n\
	movs r4, 0\n\
	mov r8, r4\n\
	movs r5, 0\n\
	str r5, [sp, 0x4]\n\
	ldr r4, =gUnknown_03001168\n\
	b _080E85A0\n\
	.pool\n\
_080E8598:\n\
	adds r1, r2\n\
	ldr r6, [sp, 0x4]\n\
	adds r6, 0x1\n\
	str r6, [sp, 0x4]\n\
_080E85A0:\n\
	ldr r5, [sp, 0x4]\n\
	cmp r5, r0\n\
	bge _080E85B6\n\
	cmp r5, r3\n\
	beq _080E85B0\n\
	stm r4!, {r1}\n\
	movs r6, 0x1\n\
	add r8, r6\n\
_080E85B0:\n\
	mov r5, r8\n\
	cmp r5, 0x3\n\
	bne _080E8598\n\
_080E85B6:\n\
	movs r6, 0\n\
	str r6, [sp, 0x4]\n\
	subs r0, 0x1\n\
	str r0, [sp, 0x24]\n\
_080E85BE:\n\
	movs r0, 0\n\
	str r0, [sp, 0x8]\n\
	ldr r1, [sp, 0x4]\n\
	adds r1, 0x1\n\
	str r1, [sp, 0x28]\n\
	ldr r2, [sp, 0x4]\n\
	lsls r2, 1\n\
	str r2, [sp, 0x34]\n\
	ldr r3, [sp, 0x4]\n\
	adds r3, r2, r3\n\
	str r3, [sp, 0x10]\n\
	movs r4, 0\n\
	str r4, [sp, 0x44]\n\
	movs r5, 0\n\
	str r5, [sp, 0x48]\n\
_080E85DC:\n\
	movs r6, 0\n\
	mov r8, r6\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r1, [r0]\n\
	ldr r2, [sp, 0x10]\n\
	lsls r0, r2, 5\n\
	ldr r3, [sp, 0x48]\n\
	adds r0, r3, r0\n\
	adds r3, r0, r1\n\
	lsls r0, r2, 6\n\
	ldr r4, [sp, 0x44]\n\
	adds r0, r4, r0\n\
	ldr r5, [sp]\n\
	adds r2, r0, r5\n\
_080E85F8:\n\
	adds r0, r2, 0\n\
	movs r6, 0x87\n\
	lsls r6, 2\n\
	adds r1, r3, r6\n\
	ldm r1!, {r4-r6}\n\
	stm r0!, {r4-r6}\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	adds r3, 0x10\n\
	adds r2, 0x10\n\
	movs r0, 0x1\n\
	add r8, r0\n\
	mov r1, r8\n\
	cmp r1, 0x2\n\
	ble _080E85F8\n\
	movs r2, 0\n\
	mov r8, r2\n\
	ldr r3, [sp, 0x24]\n\
	cmp r8, r3\n\
	bge _080E86DC\n\
	ldr r4, [sp, 0x4]\n\
	lsls r4, 5\n\
	mov r9, r4\n\
	ldr r5, [sp, 0x8]\n\
	lsls r7, r5, 4\n\
	ldr r6, [sp, 0x34]\n\
	ldr r1, [sp, 0x4]\n\
	adds r0, r6, r1\n\
	lsls r0, 6\n\
	str r0, [sp, 0x14]\n\
	ldr r2, [sp]\n\
	adds r0, r2, r0\n\
	ldr r3, [sp, 0x44]\n\
	str r3, [sp, 0x18]\n\
	adds r0, r3\n\
	str r0, [sp, 0x1C]\n\
	ldr r4, [sp, 0x14]\n\
	adds r0, r3, r4\n\
	adds r0, r2\n\
	adds r0, 0x30\n\
	mov r10, r0\n\
_080E864A:\n\
	movs r5, 0\n\
	str r5, [sp, 0xC]\n\
	movs r3, 0\n\
	mov r6, r8\n\
	lsls r6, 2\n\
	str r6, [sp, 0x38]\n\
	ldr r1, [sp, 0x18]\n\
	ldr r2, [sp, 0x14]\n\
	adds r0, r1, r2\n\
	ldr r4, [sp]\n\
	adds r5, r0, r4\n\
	ldr r0, =gUnknown_03001168\n\
	adds r0, r6, r0\n\
	str r0, [sp, 0x50]\n\
_080E8666:\n\
	lsls r0, r3, 4\n\
	ldr r6, [sp, 0x1C]\n\
	adds r0, r6, r0\n\
	str r3, [sp, 0x4C]\n\
	bl ReadUnalignedWord\n\
	adds r4, r0, 0\n\
	ldr r1, [sp, 0x50]\n\
	ldr r0, [r1]\n\
	add r0, r9\n\
	adds r0, r7\n\
	bl ReadUnalignedWord\n\
	ldr r3, [sp, 0x4C]\n\
	cmp r4, r0\n\
	bne _080E86A8\n\
	ldr r2, [sp, 0xC]\n\
	adds r2, 0x1\n\
	str r2, [sp, 0xC]\n\
	ldr r4, [sp, 0x50]\n\
	ldr r0, [r4]\n\
	mov r6, r9\n\
	adds r1, r7, r6\n\
	adds r1, r0, r1\n\
	ldrh r0, [r5, 0x4]\n\
	ldrh r2, [r1, 0x4]\n\
	cmp r0, r2\n\
	bcs _080E86A8\n\
	adds r0, r5, 0\n\
	ldm r1!, {r2,r4,r6}\n\
	stm r0!, {r2,r4,r6}\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
_080E86A8:\n\
	adds r5, 0x10\n\
	adds r3, 0x1\n\
	cmp r3, 0x2\n\
	ble _080E8666\n\
	ldr r3, [sp, 0xC]\n\
	cmp r3, 0\n\
	bne _080E86CE\n\
	ldr r0, =gUnknown_03001168\n\
	ldr r4, [sp, 0x38]\n\
	adds r0, r4, r0\n\
	ldr r0, [r0]\n\
	mov r5, r9\n\
	adds r2, r7, r5\n\
	mov r1, r10\n\
	adds r0, r2\n\
	ldm r0!, {r2,r3,r6}\n\
	stm r1!, {r2,r3,r6}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
_080E86CE:\n\
	movs r4, 0x10\n\
	add r10, r4\n\
	movs r5, 0x1\n\
	add r8, r5\n\
	ldr r6, [sp, 0x24]\n\
	cmp r8, r6\n\
	blt _080E864A\n\
_080E86DC:\n\
	ldr r0, [sp, 0x44]\n\
	adds r0, 0x60\n\
	str r0, [sp, 0x44]\n\
	ldr r1, [sp, 0x48]\n\
	adds r1, 0x30\n\
	str r1, [sp, 0x48]\n\
	ldr r2, [sp, 0x8]\n\
	adds r2, 0x1\n\
	str r2, [sp, 0x8]\n\
	cmp r2, 0x1\n\
	bgt _080E86F4\n\
	b _080E85DC\n\
_080E86F4:\n\
	ldr r3, [sp, 0x28]\n\
	str r3, [sp, 0x4]\n\
	cmp r3, 0x8\n\
	bgt _080E86FE\n\
	b _080E85BE\n\
_080E86FE:\n\
	movs r4, 0\n\
	str r4, [sp, 0x8]\n\
_080E8702:\n\
	ldr r5, [sp, 0x8]\n\
	adds r5, 0x1\n\
	str r5, [sp, 0x2C]\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r1, [r0]\n\
	movs r0, 0x54\n\
	ldr r6, [sp, 0x8]\n\
	muls r0, r6\n\
	adds r3, r0, r1\n\
	movs r0, 0xA8\n\
	muls r0, r6\n\
	ldr r1, [sp]\n\
	adds r2, r0, r1\n\
	movs r4, 0x2\n\
	mov r8, r4\n\
_080E8720:\n\
	movs r5, 0xD8\n\
	lsls r5, 3\n\
	adds r0, r2, r5\n\
	ldr r6, =0x0000057c\n\
	adds r1, r3, r6\n\
	ldm r1!, {r4-r6}\n\
	stm r0!, {r4-r6}\n\
	ldm r1!, {r4-r6}\n\
	stm r0!, {r4-r6}\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	adds r3, 0x1C\n\
	adds r2, 0x1C\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	add r8, r0\n\
	mov r1, r8\n\
	cmp r1, 0\n\
	bge _080E8720\n\
	movs r2, 0\n\
	mov r8, r2\n\
	ldr r3, [sp, 0x24]\n\
	cmp r8, r3\n\
	blt _080E8752\n\
	b _080E885A\n\
_080E8752:\n\
	ldr r4, [sp, 0x8]\n\
	lsls r1, r4, 3\n\
	movs r0, 0xA8\n\
	adds r5, r4, 0\n\
	muls r5, r0\n\
	str r5, [sp, 0x20]\n\
	str r5, [sp, 0x3C]\n\
	subs r1, r4\n\
	lsls r1, 2\n\
	mov r10, r1\n\
_080E8766:\n\
	movs r6, 0\n\
	str r6, [sp, 0xC]\n\
	mov r0, r8\n\
	lsls r0, 2\n\
	str r0, [sp, 0x38]\n\
	mov r1, r8\n\
	adds r1, 0x1\n\
	str r1, [sp, 0x30]\n\
	ldr r0, =gUnknown_03001168\n\
	ldr r2, [sp, 0x38]\n\
	adds r2, r0\n\
	mov r9, r2\n\
	ldr r3, [sp]\n\
	movs r4, 0xD8\n\
	lsls r4, 3\n\
	adds r0, r3, r4\n\
	ldr r5, [sp, 0x3C]\n\
	adds r7, r5, r0\n\
	str r6, [sp, 0x40]\n\
	movs r3, 0x2\n\
_080E878E:\n\
	ldr r1, [sp, 0x20]\n\
	movs r2, 0xD8\n\
	lsls r2, 3\n\
	adds r0, r1, r2\n\
	ldr r4, [sp]\n\
	adds r0, r4, r0\n\
	ldr r6, [sp, 0x40]\n\
	adds r5, r0, r6\n\
	adds r0, r5, 0\n\
	str r3, [sp, 0x4C]\n\
	bl ReadUnalignedWord\n\
	adds r4, r0, 0\n\
	movs r6, 0x90\n\
	lsls r6, 1\n\
	add r6, r10\n\
	mov r1, r9\n\
	ldr r0, [r1]\n\
	adds r0, r6\n\
	bl ReadUnalignedWord\n\
	ldr r3, [sp, 0x4C]\n\
	cmp r4, r0\n\
	bne _080E8808\n\
	adds r0, r5, 0x4\n\
	bl ReadUnalignedWord\n\
	adds r4, r0, 0\n\
	mov r2, r9\n\
	ldr r0, [r2]\n\
	adds r0, r6\n\
	adds r0, 0x4\n\
	bl ReadUnalignedWord\n\
	ldr r3, [sp, 0x4C]\n\
	cmp r4, r0\n\
	bne _080E8808\n\
	ldr r4, [sp, 0xC]\n\
	adds r4, 0x1\n\
	str r4, [sp, 0xC]\n\
	mov r5, r9\n\
	ldr r0, [r5]\n\
	mov r6, r10\n\
	adds r2, r0, r6\n\
	movs r0, 0x94\n\
	lsls r0, 1\n\
	adds r1, r2, r0\n\
	ldrh r0, [r7, 0x8]\n\
	ldrh r1, [r1]\n\
	cmp r0, r1\n\
	bcs _080E8808\n\
	adds r0, r7, 0\n\
	movs r4, 0x90\n\
	lsls r4, 1\n\
	adds r1, r2, r4\n\
	ldm r1!, {r2,r5,r6}\n\
	stm r0!, {r2,r5,r6}\n\
	ldm r1!, {r4-r6}\n\
	stm r0!, {r4-r6}\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
_080E8808:\n\
	adds r7, 0x1C\n\
	ldr r0, [sp, 0x40]\n\
	adds r0, 0x1C\n\
	str r0, [sp, 0x40]\n\
	subs r3, 0x1\n\
	cmp r3, 0\n\
	bge _080E878E\n\
	ldr r1, [sp, 0xC]\n\
	cmp r1, 0\n\
	bne _080E8850\n\
	mov r0, r8\n\
	adds r0, 0x3\n\
	lsls r1, r0, 3\n\
	subs r1, r0\n\
	lsls r1, 2\n\
	ldr r2, [sp, 0x20]\n\
	adds r1, r2\n\
	ldr r3, [sp]\n\
	adds r1, r3, r1\n\
	ldr r0, =gUnknown_03001168\n\
	ldr r4, [sp, 0x38]\n\
	adds r0, r4, r0\n\
	ldr r0, [r0]\n\
	add r0, r10\n\
	movs r5, 0xD8\n\
	lsls r5, 3\n\
	adds r1, r5\n\
	movs r6, 0x90\n\
	lsls r6, 1\n\
	adds r0, r6\n\
	ldm r0!, {r2-r4}\n\
	stm r1!, {r2-r4}\n\
	ldm r0!, {r2,r5,r6}\n\
	stm r1!, {r2,r5,r6}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
_080E8850:\n\
	ldr r3, [sp, 0x30]\n\
	mov r8, r3\n\
	ldr r4, [sp, 0x24]\n\
	cmp r8, r4\n\
	blt _080E8766\n\
_080E885A:\n\
	ldr r5, [sp, 0x2C]\n\
	str r5, [sp, 0x8]\n\
	cmp r5, 0x1\n\
	bgt _080E8864\n\
	b _080E8702\n\
_080E8864:\n\
	add sp, 0x54\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    ");
}

static void sub_80E8880(struct UnknownRecMixingStruct *arg0, struct UnknownRecMixingStruct *arg1)
{
    s32 i, j;

    for (i = 0; i < 3; i++)
    {
        s32 r2 = 0;
        s32 r4 = -1;
        for (j = 0; j < 6; j++)
        {
            if (arg1[j].field_4 > r2)
            {
                r4 = j;
                r2 = arg1[j].field_4;
            }
        }

        if (r4 >= 0)
        {
            arg0[i] = arg1[r4];
            arg1[r4].field_4 = 0;
        }
    }
}

static void sub_80E88CC(struct UnknownRecMixingStruct2 *arg0, struct UnknownRecMixingStruct2 *arg1)
{
    s32 i, j;

    for (i = 0; i < 3; i++)
    {
        s32 r2 = 0;
        s32 r4 = -1;
        for (j = 0; j < 6; j++)
        {
            if (arg1[j].field_8 > r2)
            {
                r4 = j;
                r2 = arg1[j].field_8;
            }
        }

        if (r4 >= 0)
        {
            arg0[i] = arg1[r4];
            arg1[r4].field_8 = 0;
        }
    }
}

NAKED
static void sub_80E8924(struct UnknownRecMixingStruct3 *arg0)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	mov r9, r0\n\
	movs r0, 0\n\
	ldr r1, =gSaveBlock2Ptr\n\
	mov r10, r1\n\
_080E8936:\n\
	lsls r1, r0, 1\n\
	adds r2, r0, 0x1\n\
	mov r8, r2\n\
	adds r1, r0\n\
	lsls r0, r1, 5\n\
	movs r2, 0x87\n\
	lsls r2, 2\n\
	adds r7, r0, r2\n\
	lsls r1, 6\n\
	mov r0, r9\n\
	adds r4, r0, r1\n\
	movs r6, 0\n\
	movs r5, 0x1\n\
_080E8950:\n\
	mov r1, r10\n\
	ldr r0, [r1]\n\
	adds r0, r7\n\
	adds r0, r6\n\
	adds r1, r4, 0\n\
	bl sub_80E8880\n\
	adds r4, 0x60\n\
	adds r6, 0x30\n\
	subs r5, 0x1\n\
	cmp r5, 0\n\
	bge _080E8950\n\
	mov r0, r8\n\
	cmp r0, 0x8\n\
	ble _080E8936\n\
	movs r5, 0\n\
	ldr r4, =gSaveBlock2Ptr\n\
_080E8972:\n\
	movs r0, 0x54\n\
	adds r1, r5, 0\n\
	muls r1, r0\n\
	ldr r2, =0x0000057c\n\
	adds r1, r2\n\
	ldr r0, [r4]\n\
	adds r0, r1\n\
	movs r1, 0xA8\n\
	muls r1, r5\n\
	movs r2, 0xD8\n\
	lsls r2, 3\n\
	adds r1, r2\n\
	add r1, r9\n\
	bl sub_80E88CC\n\
	adds r5, 0x1\n\
	cmp r5, 0x1\n\
	ble _080E8972\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool");
}

static void sub_80E89AC(struct UnkRecordMixingStruct2 *arg0, size_t arg1, u32 arg2)
{
    u8 linkPlayerCount = GetLinkPlayerCount();
    struct UnknownRecMixingStruct3 *largeStructPtr = AllocZeroed(sizeof(struct UnknownRecMixingStruct3));

    sub_80E8578(largeStructPtr, arg0, arg1, arg2, linkPlayerCount);
    sub_80E8924(largeStructPtr);

    Free(largeStructPtr);
}

static void sub_80E89F8(struct RecordMixingDayCareMail *dst)
{
    gUnknown_02039F9C.mail[0] = gSaveBlock1Ptr->daycare.mons[0].mail;
    gUnknown_02039F9C.mail[1] = gSaveBlock1Ptr->daycare.mons[1].mail;
    InitDaycareMailRecordMixing(&gSaveBlock1Ptr->daycare, &gUnknown_02039F9C);
    *dst = *gUnknown_03001148;
}

static void SanitizeDayCareMailForRuby(struct RecordMixingDayCareMail *src)
{
    s32 i;

    for (i = 0; i < src->numDaycareMons; i++)
    {
        struct DayCareMail *mail = &src->mail[i];
        if (mail->message.itemId != 0)
        {
            if (mail->gameLanguage != LANGUAGE_JAPANESE)
                PadNameString(mail->OT_name, 0xFC);

            ConvertInternationalString(mail->monName, mail->monLanguage);
        }
    }
}

static void SanitizeRubyBattleTowerRecord(struct RSBattleTowerRecord *src)
{

}

static void SanitizeEmeraldBattleTowerRecord(struct EmeraldBattleTowerRecord *dst)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        struct UnknownPokemonStruct *towerMon = &dst->party[i];
        if (towerMon->species != 0)
            StripExtCtrlCodes(towerMon->nickname);
    }

    CalcEmeraldBattleTowerChecksum(dst);
}
