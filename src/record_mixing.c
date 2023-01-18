#include "global.h"
#include "malloc.h"
#include "random.h"
#include "constants/items.h"
#include "text.h"
#include "item.h"
#include "task.h"
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
#include "field_screen_effect.h"
#include "fldeff_misc.h"
#include "script.h"
#include "event_data.h"
#include "lilycove_lady.h"
#include "strings.h"
#include "string_util.h"
#include "record_mixing.h"
#include "new_game.h"
#include "daycare.h"
#include "international_string_util.h"
#include "constants/battle_frontier.h"
#include "dewford_trend.h"

// Number of bytes of the record transferred at a time
#define BUFFER_CHUNK_SIZE 200

#define NUM_SWAP_COMBOS 3

// Used by several tasks in this file
#define tState        data[0]

struct RecordMixingHallRecords
{
    struct RankingHall1P hallRecords1P[HALL_FACILITIES_COUNT][FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT * 2];
    struct RankingHall2P hallRecords2P[FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT * 2];
};

struct PlayerRecordRS
{
    struct SecretBase secretBases[SECRET_BASES_COUNT];
    TVShow tvShows[TV_SHOWS_COUNT];
    PokeNews pokeNews[POKE_NEWS_COUNT];
    OldMan oldMan;
    struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    struct RecordMixingDaycareMail daycareMail;
    struct RSBattleTowerRecord battleTowerRecord;
    u16 giftItem;
    u16 filler[50];
};

struct PlayerRecordEmerald
{
    /* 0x0000 */ struct SecretBase secretBases[SECRET_BASES_COUNT];
    /* 0x0C80 */ TVShow tvShows[TV_SHOWS_COUNT];
    /* 0x1004 */ PokeNews pokeNews[POKE_NEWS_COUNT];
    /* 0x1044 */ OldMan oldMan;
    /* 0x1084 */ struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    /* 0x10AC */ struct RecordMixingDaycareMail daycareMail;
    /* 0x1124 */ struct EmeraldBattleTowerRecord battleTowerRecord;
    /* 0x1210 */ u16 giftItem;
    /* 0x1214 */ LilycoveLady lilycoveLady;
    /* 0x1254 */ struct Apprentice apprentices[2];
    /* 0x12DC */ struct PlayerHallRecords hallRecords;
    /* 0x1434 */ u8 filler_1434[16];
}; // 0x1444

union PlayerRecord
{
    struct PlayerRecordRS ruby;
    struct PlayerRecordEmerald emerald;
};

static bool8 sReadyToReceive;
static struct SecretBase *sSecretBasesSave;
static TVShow *sTvShowsSave;
static PokeNews *sPokeNewsSave;
static OldMan *sOldManSave;
static struct DewfordTrend *sDewfordTrendsSave;
static struct RecordMixingDaycareMail *sRecordMixMailSave;
static void *sBattleTowerSave;
static LilycoveLady *sLilycoveLadySave;
static void *sApprenticesSave;
static void *sBattleTowerSave_Duplicate;
static u32 sRecordStructSize;
static u8 sDaycareMailRandSum;
static struct PlayerHallRecords *sPartnerHallRecords[HALL_RECORDS_COUNT];

static EWRAM_DATA struct RecordMixingDaycareMail sRecordMixMail = {0};
static EWRAM_DATA union PlayerRecord *sReceivedRecords = NULL;
static EWRAM_DATA union PlayerRecord *sSentRecord = NULL;

static void Task_RecordMixing_Main(u8);
static void Task_MixingRecordsRecv(u8);
static void Task_SendPacket(u8);
static void Task_CopyReceiveBuffer(u8);
static void Task_SendPacket_SwitchToReceive(u8);
static void *LoadPtrFromTaskData(const u16 *);
static void StorePtrInTaskData(void *, u16 *);
static u8 GetMultiplayerId_(void);
static void *GetPlayerRecvBuffer(u8);
static void ReceiveOldManData(OldMan *, size_t, u8);
static void ReceiveBattleTowerData(void *, size_t, u8);
static void ReceiveLilycoveLadyData(LilycoveLady *, size_t, u8);
static void CalculateDaycareMailRandSum(const u8 *);
static void ReceiveDaycareMailData(struct RecordMixingDaycareMail *, size_t, u8, TVShow *);
static void ReceiveGiftItem(u16 *, u8 );
static void Task_DoRecordMixing(u8);
static void GetSavedApprentices(struct Apprentice *, struct Apprentice *);
static void ReceiveApprenticeData(struct Apprentice *, size_t, u32);
static void ReceiveRankingHallRecords(struct PlayerHallRecords *, size_t, u32);
static void GetRecordMixingDaycareMail(struct RecordMixingDaycareMail *);
static void SanitizeDaycareMailForRuby(struct RecordMixingDaycareMail *);
static void SanitizeEmeraldBattleTowerRecord(struct EmeraldBattleTowerRecord *);
static void SanitizeRubyBattleTowerRecord(struct RSBattleTowerRecord *);

static const u8 sPlayerIdxOrders_2Player[] = {1, 0};

static const u8 sPlayerIdxOrders_3Player[][3] =
{
    {1, 2, 0},
    {2, 0, 1},
};

static const u8 sPlayerIdxOrders_4Player[][4] =
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

// When 3 players can swap mail 2 players are randomly selected and the 3rd is left out
static const u8 sDaycareMailSwapIds_3Player[NUM_SWAP_COMBOS][2] =
{
    {0, 1},
    {1, 2},
    {2, 0},
};

static const u8 sDaycareMailSwapIds_4Player[NUM_SWAP_COMBOS][4] =
{
    {0, 1,   2, 3}, // 0 swaps with 1, 2 swaps with 3
    {0, 2,   1, 3},
    {0, 3,   2, 1},
};

void RecordMixingPlayerSpotTriggered(void)
{
    CreateTask_EnterCableClubSeat(Task_RecordMixing_Main);
}

// these variables were const in R/S, but had to become changeable because of saveblocks changing RAM position
static void SetSrcLookupPointers(void)
{
    sSecretBasesSave = gSaveBlock1Ptr->secretBases;
    sTvShowsSave = gSaveBlock1Ptr->tvShows;
    sPokeNewsSave = gSaveBlock1Ptr->pokeNews;
    sOldManSave = &gSaveBlock1Ptr->oldMan;
    sDewfordTrendsSave = gSaveBlock1Ptr->dewfordTrends;
    sRecordMixMailSave = &sRecordMixMail;
    sBattleTowerSave = &gSaveBlock2Ptr->frontier.towerPlayer;
    sLilycoveLadySave = &gSaveBlock1Ptr->lilycoveLady;
    sApprenticesSave = gSaveBlock2Ptr->apprentices;
    sBattleTowerSave_Duplicate = &gSaveBlock2Ptr->frontier.towerPlayer;
}

static void PrepareUnknownExchangePacket(struct PlayerRecordRS *dest)
{
    memcpy(dest->secretBases, sSecretBasesSave, sizeof(dest->secretBases));
    memcpy(dest->tvShows, sTvShowsSave, sizeof(dest->tvShows));
    SanitizeTVShowLocationsForRuby(dest->tvShows);
    memcpy(dest->pokeNews, sPokeNewsSave, sizeof(dest->pokeNews));
    memcpy(&dest->oldMan, sOldManSave, sizeof(dest->oldMan));
    memcpy(dest->dewfordTrends, sDewfordTrendsSave, sizeof(dest->dewfordTrends));
    GetRecordMixingDaycareMail(&dest->daycareMail);
    EmeraldBattleTowerRecordToRuby(sBattleTowerSave, &dest->battleTowerRecord);

    if (GetMultiplayerId() == 0)
        dest->giftItem = GetRecordMixingGift();
}

static void PrepareExchangePacketForRubySapphire(struct PlayerRecordRS *dest)
{
    memcpy(dest->secretBases, sSecretBasesSave, sizeof(dest->secretBases));
    ClearJapaneseSecretBases(dest->secretBases);
    memcpy(dest->tvShows, sTvShowsSave, sizeof(dest->tvShows));
    SanitizeTVShowsForRuby(dest->tvShows);
    memcpy(dest->pokeNews, sPokeNewsSave, sizeof(dest->pokeNews));
    memcpy(&dest->oldMan, sOldManSave, sizeof(dest->oldMan));
    SanitizeMauvilleOldManForRuby(&dest->oldMan);
    memcpy(dest->dewfordTrends, sDewfordTrendsSave, sizeof(dest->dewfordTrends));
    GetRecordMixingDaycareMail(&dest->daycareMail);
    SanitizeDaycareMailForRuby(&dest->daycareMail);
    EmeraldBattleTowerRecordToRuby(sBattleTowerSave, &dest->battleTowerRecord);
    SanitizeRubyBattleTowerRecord(&dest->battleTowerRecord);

    if (GetMultiplayerId() == 0)
        dest->giftItem = GetRecordMixingGift();
}

static void PrepareExchangePacket(void)
{
    SetPlayerSecretBaseParty();
    DeactivateAllNormalTVShows();
    SetSrcLookupPointers();

    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (LinkDummy_Return2() == 0)
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
        memcpy(sSentRecord->emerald.dewfordTrends, sDewfordTrendsSave, sizeof(sSentRecord->emerald.dewfordTrends));
        GetRecordMixingDaycareMail(&sSentRecord->emerald.daycareMail);
        memcpy(&sSentRecord->emerald.battleTowerRecord, sBattleTowerSave, sizeof(sSentRecord->emerald.battleTowerRecord));
        SanitizeEmeraldBattleTowerRecord(&sSentRecord->emerald.battleTowerRecord);

        if (GetMultiplayerId() == 0)
            sSentRecord->emerald.giftItem = GetRecordMixingGift();

        GetSavedApprentices(sSentRecord->emerald.apprentices, sApprenticesSave);
        GetPlayerHallRecords(&sSentRecord->emerald.hallRecords);
    }
}

static void ReceiveExchangePacket(u32 multiplayerId)
{
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        // Ruby/Sapphire
        CalculateDaycareMailRandSum((void *)sReceivedRecords->ruby.tvShows);
        ReceiveSecretBasesData(sReceivedRecords->ruby.secretBases, sizeof(sReceivedRecords->ruby), multiplayerId);
        ReceiveDaycareMailData(&sReceivedRecords->ruby.daycareMail, sizeof(sReceivedRecords->ruby), multiplayerId, sReceivedRecords->ruby.tvShows);
        ReceiveBattleTowerData(&sReceivedRecords->ruby.battleTowerRecord, sizeof(sReceivedRecords->ruby), multiplayerId);
        ReceiveTvShowsData(sReceivedRecords->ruby.tvShows, sizeof(sReceivedRecords->ruby), multiplayerId);
        ReceivePokeNewsData(sReceivedRecords->ruby.pokeNews, sizeof(sReceivedRecords->ruby), multiplayerId);
        ReceiveOldManData(&sReceivedRecords->ruby.oldMan, sizeof(sReceivedRecords->ruby), multiplayerId);
        ReceiveDewfordTrendData(sReceivedRecords->ruby.dewfordTrends, sizeof(sReceivedRecords->ruby), multiplayerId);
        ReceiveGiftItem(&sReceivedRecords->ruby.giftItem, multiplayerId);
    }
    else
    {
        // Emerald
        CalculateDaycareMailRandSum((void *)sReceivedRecords->emerald.tvShows);
        ReceiveSecretBasesData(sReceivedRecords->emerald.secretBases, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceiveTvShowsData(sReceivedRecords->emerald.tvShows, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceivePokeNewsData(sReceivedRecords->emerald.pokeNews, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceiveOldManData(&sReceivedRecords->emerald.oldMan, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceiveDewfordTrendData(sReceivedRecords->emerald.dewfordTrends, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceiveDaycareMailData(&sReceivedRecords->emerald.daycareMail, sizeof(sReceivedRecords->emerald), multiplayerId, sReceivedRecords->emerald.tvShows);
        ReceiveBattleTowerData(&sReceivedRecords->emerald.battleTowerRecord, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceiveGiftItem(&sReceivedRecords->emerald.giftItem, multiplayerId);
        ReceiveLilycoveLadyData(&sReceivedRecords->emerald.lilycoveLady, sizeof(sReceivedRecords->emerald), multiplayerId);
        ReceiveApprenticeData(sReceivedRecords->emerald.apprentices, sizeof(sReceivedRecords->emerald), (u8)multiplayerId);
        ReceiveRankingHallRecords(&sReceivedRecords->emerald.hallRecords, sizeof(sReceivedRecords->emerald), (u8)multiplayerId);
    }
}

static void PrintTextOnRecordMixing(const u8 *src)
{
    DrawDialogueFrame(0, FALSE);
    AddTextPrinterParameterized(0, FONT_NORMAL, src, 0, 1, 0, NULL);
    CopyWindowToVram(0, COPYWIN_FULL);
}

#define tCounter data[0]

static void Task_RecordMixing_SoundEffect(u8 taskId)
{
    if (++gTasks[taskId].tCounter == 50)
    {
        PlaySE(SE_M_ATTRACT);
        gTasks[taskId].tCounter = 0;
    }
}

#undef tCounter

#define tTimer       data[8]
#define tLinkTaskId  data[10]
#define tSoundTaskId data[15]

// Note: gSpecialVar_0x8005 here contains the player's spot id.
static void Task_RecordMixing_Main(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0: // init
        sSentRecord = Alloc(sizeof(*sSentRecord));
        sReceivedRecords = Alloc(sizeof(*sReceivedRecords) * MAX_LINK_PLAYERS);
        SetLocalLinkPlayerId(gSpecialVar_0x8005);
        VarSet(VAR_TEMP_0, 1);
        sReadyToReceive = FALSE;
        PrepareExchangePacket();
        CreateRecordMixingLights();
        tState = 1;
        tLinkTaskId = CreateTask(Task_MixingRecordsRecv, 80);
        tSoundTaskId = CreateTask(Task_RecordMixing_SoundEffect, 81);
        break;
    case 1: // wait for Task_MixingRecordsRecv
        if (!gTasks[tLinkTaskId].isActive)
        {
            tState = 2;
            FlagSet(FLAG_SYS_MIX_RECORD);
            DestroyRecordMixingLights();
            DestroyTask(tSoundTaskId);
        }
        break;
    case 2:
        tLinkTaskId = CreateTask(Task_DoRecordMixing, 10);
        tState = 3;
        PlaySE(SE_M_BATON_PASS);
        break;
    case 3: // wait for Task_DoRecordMixing
        if (!gTasks[tLinkTaskId].isActive)
        {
            tState = 4;
            if (gWirelessCommType == 0)
                tLinkTaskId = CreateTask_ReestablishCableClubLink();

            PrintTextOnRecordMixing(gText_RecordMixingComplete);
            tTimer = 0;
        }
        break;
    case 4: // wait 60 frames
        if (++tTimer > 60)
            tState = 5;
        break;
    case 5: // Wait for the task created by CreateTask_ReestablishCableClubLink
        if (!gTasks[tLinkTaskId].isActive)
        {
            Free(sReceivedRecords);
            Free(sSentRecord);
            SetLinkWaitingForScript();
            if (gWirelessCommType != 0)
                CreateTask(Task_ReturnToFieldRecordMixing, 10);
            ClearDialogWindowAndFrame(0, TRUE);
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
        break;
    }
}

#undef tTimer
#undef tLinkTaskId
#undef tSoundTaskId

// Task data for Task_MixingRecordsRecv and subsequent tasks
#define tSentRecord    data[2] // Used to store a ptr, so data[2] and data[3]
#define tNumChunksSent data[4]
#define tMultiplayerId data[5]
#define tCopyTaskId    data[10]

// Task data for Task_CopyReceiveBuffer
#define tParentTaskId     data[0]
#define tNumChunksRecv(i) data[1 + (i)] // Number of chunks of the record received per player
#define tRecvRecords      data[5] // Used to store a ptr, so data[5] and data[6]

static void Task_MixingRecordsRecv(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        PrintTextOnRecordMixing(gText_MixingRecords);
        task->data[8] = 0x708;
        task->tState = 400;
        ClearLinkCallback_2();
        break;
    case 100: // wait 20 frames
        if (++task->data[12] > 20)
        {
            task->data[12] = 0;
            task->tState = 101;
        }
        break;
    case 101:
        {
            u8 players = GetLinkPlayerCount_2();
            if (IsLinkMaster() == TRUE)
            {
                if (players == GetSavedPlayerCount())
                {
                    PlaySE(SE_PIN);
                    task->tState = 201;
                    task->data[12] = 0;
                }
            }
            else
            {
                PlaySE(SE_BOO);
                task->tState = 301;
            }
        }
        break;
    case 201:
        // We're the link master. Delay for 30 frames per connected player.
        if (GetSavedPlayerCount() == GetLinkPlayerCount_2() && ++task->data[12] > (GetLinkPlayerCount_2() * 30))
        {
            CheckShouldAdvanceLinkState();
            task->tState = 1;
        }
        break;
    case 301:
        if (GetSavedPlayerCount() == GetLinkPlayerCount_2())
            task->tState = 1;
        break;
    case 400: // wait 20 frames
        if (++task->data[12] > 20)
        {
            task->tState = 1;
            task->data[12] = 0;
        }
        break;
    case 1: // wait for handshake
        if (gReceivedRemoteLinkPlayers)
        {
            ConvertIntToDecimalStringN(gStringVar1, GetMultiplayerId_(), STR_CONV_MODE_LEADING_ZEROS, 2);
            task->tState = 5;
        }
        break;
    case 2:
        {
            u8 subTaskId;

            task->data[6] = GetLinkPlayerCount_2();
            task->tState = 0;
            task->tMultiplayerId = GetMultiplayerId_();
            task->func = Task_SendPacket;
            if (Link_AnyPartnersPlayingRubyOrSapphire())
            {
                StorePtrInTaskData(sSentRecord, &task->tSentRecord);
                subTaskId = CreateTask(Task_CopyReceiveBuffer, 80);
                task->tCopyTaskId = subTaskId;
                gTasks[subTaskId].tParentTaskId = taskId;
                StorePtrInTaskData(sReceivedRecords, &gTasks[subTaskId].tRecvRecords);
                sRecordStructSize = sizeof(struct PlayerRecordRS);
            }
            else
            {
                StorePtrInTaskData(sSentRecord, &task->tSentRecord);
                subTaskId = CreateTask(Task_CopyReceiveBuffer, 80);
                task->tCopyTaskId = subTaskId;
                gTasks[subTaskId].tParentTaskId = taskId;
                StorePtrInTaskData(sReceivedRecords, &gTasks[subTaskId].tRecvRecords);
                sRecordStructSize = sizeof(struct PlayerRecordEmerald);
            }
        }
        break;
    case 5: // wait 60 frames
        if (++task->data[10] > 60)
        {
            task->data[10] = 0;
            task->tState = 2;
        }
        break;
    }
}

static void Task_SendPacket(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->tState)
    {
    case 0: // Copy record data chunk to send buffer
        {
            void *recordData = LoadPtrFromTaskData(&task->tSentRecord) + task->tNumChunksSent * BUFFER_CHUNK_SIZE;

            memcpy(gBlockSendBuffer, recordData, BUFFER_CHUNK_SIZE);
            task->tState++;
        }
        break;
    case 1:
        if (GetMultiplayerId() == 0)
            SendBlockRequest(BLOCK_REQ_SIZE_200);
        task->tState++;
        break;
    case 2:
        break;
    case 3:
        // If sent final chunk of record, move on to next state.
        // Otherwise return to first state and send next chunk.
        task->tNumChunksSent++;
        if (task->tNumChunksSent == sRecordStructSize / BUFFER_CHUNK_SIZE + 1)
            task->tState++;
        else
            task->tState = 0;
        break;
    case 4:
        if (!gTasks[task->tCopyTaskId].isActive)
            task->func = Task_SendPacket_SwitchToReceive;
        break;
    }
}

static void Task_CopyReceiveBuffer(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 status = GetBlockReceivedStatus();
    u8 handledPlayers = 0;

    if (status == GetLinkPlayerCountAsBitFlags())
    {
        u8 i;
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if ((status >> i) & 1)
            {
                void *dest = LoadPtrFromTaskData(&task->tRecvRecords) + task->tNumChunksRecv(i) * BUFFER_CHUNK_SIZE + sRecordStructSize * i;
                void *src = GetPlayerRecvBuffer(i);
                if ((task->tNumChunksRecv(i) + 1) * BUFFER_CHUNK_SIZE > sRecordStructSize)
                    memcpy(dest, src, sRecordStructSize - task->tNumChunksRecv(i) * BUFFER_CHUNK_SIZE);
                else
                    memcpy(dest, src, BUFFER_CHUNK_SIZE);
                ResetBlockReceivedFlag(i);
                task->tNumChunksRecv(i)++;
                if (task->tNumChunksRecv(i) == sRecordStructSize / BUFFER_CHUNK_SIZE + 1)
                    handledPlayers++;
            }
        }
        gTasks[task->tParentTaskId].tState++;
    }

    if (handledPlayers == GetLinkPlayerCount())
        DestroyTask(taskId);
}

static void Task_WaitReceivePacket(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    // Wait for Task_CopyReceiveBuffer to finish
    if (!gTasks[task->tCopyTaskId].isActive)
        DestroyTask(taskId);
}

static void Task_ReceivePacket(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->func = Task_WaitReceivePacket;
    if (sReadyToReceive == TRUE)
        ReceiveExchangePacket(task->tMultiplayerId);
}

static void Task_SendPacket_SwitchToReceive(u8 taskId)
{
    gTasks[taskId].func = Task_ReceivePacket;
    sReadyToReceive = TRUE;
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
        for (i = 0; i < ARRAY_COUNT(sPlayerIdxOrders_2Player); i++)
            data[i] = sPlayerIdxOrders_2Player[i];
        break;
    case 3:
        linkTrainerId = GetLinkPlayerTrainerId(0) % ARRAY_COUNT(sPlayerIdxOrders_3Player);
        for (i = 0; i < ARRAY_COUNT(sPlayerIdxOrders_3Player[0]); i++)
            data[i] = sPlayerIdxOrders_3Player[linkTrainerId][i];
        break;
    case 4:
        linkTrainerId = GetLinkPlayerTrainerId(0) % ARRAY_COUNT(sPlayerIdxOrders_4Player);
        for (i = 0; i < ARRAY_COUNT(sPlayerIdxOrders_4Player[0]); i++)
            data[i] = sPlayerIdxOrders_4Player[linkTrainerId][i];
        break;
    }
}

static void ReceiveOldManData(OldMan *records, size_t recordSize, u8 multiplayerId)
{
    u8 version;
    u16 language;
    OldMan *oldMan;
    u32 mixIndices[MAX_LINK_PLAYERS];

    ShufflePlayerIndices(mixIndices);
    oldMan = (void *)records + recordSize * mixIndices[multiplayerId];
    version = gLinkPlayers[mixIndices[multiplayerId]].version;
    language = gLinkPlayers[mixIndices[multiplayerId]].language;

    if (Link_AnyPartnersPlayingRubyOrSapphire())
        SanitizeReceivedRubyOldMan(oldMan, version, language);
    else
        SanitizeReceivedEmeraldOldMan(oldMan, version, language);

    memcpy(sOldManSave, (void *)records + recordSize * mixIndices[multiplayerId], sizeof(OldMan));
    ResetMauvilleOldManFlag();
}

static void ReceiveBattleTowerData(void *records, size_t recordSize, u8 multiplayerId)
{
    struct EmeraldBattleTowerRecord *battleTowerRecord;
    struct BattleTowerPokemon *btPokemon;
    u32 mixIndices[MAX_LINK_PLAYERS];
    s32 i;

    ShufflePlayerIndices(mixIndices);
    if (Link_AnyPartnersPlayingRubyOrSapphire())
    {
        if (RubyBattleTowerRecordToEmerald((void *)records + recordSize * mixIndices[multiplayerId], (void *)records + recordSize * multiplayerId) == TRUE)
        {
            battleTowerRecord = (void *)records + recordSize * multiplayerId;
            battleTowerRecord->language = gLinkPlayers[mixIndices[multiplayerId]].language;
            CalcEmeraldBattleTowerChecksum(battleTowerRecord);
        }
    }
    else
    {
        memcpy((void *)records + recordSize * multiplayerId, (void *)records + recordSize * mixIndices[multiplayerId], sizeof(struct EmeraldBattleTowerRecord));
        battleTowerRecord = (void *)records + recordSize * multiplayerId;
        for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        {
            btPokemon = &battleTowerRecord->party[i];
            if (btPokemon->species != SPECIES_NONE && IsStringJapanese(btPokemon->nickname))
                ConvertInternationalString(btPokemon->nickname, LANGUAGE_JAPANESE);
        }
        CalcEmeraldBattleTowerChecksum(battleTowerRecord);
    }
    PutNewBattleTowerRecord((void *)records + recordSize * multiplayerId);
}

static void ReceiveLilycoveLadyData(LilycoveLady *records, size_t recordSize, u8 multiplayerId)
{
    LilycoveLady *lilycoveLady;
    u32 mixIndices[MAX_LINK_PLAYERS];

    ShufflePlayerIndices(mixIndices);
    memcpy((void *)records + recordSize * multiplayerId, sLilycoveLadySave, sizeof(LilycoveLady));

    if (GetLilycoveLadyId() == 0)
    {
        lilycoveLady = Alloc(sizeof(*lilycoveLady));
        if (lilycoveLady == NULL)
            return;

        memcpy(lilycoveLady, sLilycoveLadySave, sizeof(LilycoveLady));
    }
    else
    {
        lilycoveLady = NULL;
    }

    memcpy(sLilycoveLadySave, (void *)records + recordSize * mixIndices[multiplayerId], sizeof(LilycoveLady));
    ResetLilycoveLadyForRecordMix();
    if (lilycoveLady != NULL)
    {
        QuizLadyClearQuestionForRecordMix(lilycoveLady);
        Free(lilycoveLady);
    }
}

static u8 GetDaycareMailItemId(struct DaycareMail *mail)
{
    return mail->message.itemId;
}

// Indexes for a 2 element array used to store the multiplayer id and daycare
// slot that correspond to a daycare Pokémon that can hold an item.
enum {
    MULTIPLAYER_ID,
    DAYCARE_SLOT,
};

static void SwapDaycareMail(struct RecordMixingDaycareMail *records, size_t recordSize, u8 (*idxs)[2], u8 playerSlot1, u8 playerSlot2)
{
    struct DaycareMail temp;
    struct RecordMixingDaycareMail *mixMail1, *mixMail2;

    // 1st player's daycare mail --> temp
    mixMail1 = (void *)records + recordSize * idxs[playerSlot1][MULTIPLAYER_ID];
    memcpy(&temp, &mixMail1->mail[idxs[playerSlot1][DAYCARE_SLOT]], sizeof(struct DaycareMail));

    // 2nd player's daycare mail --> 1st player's daycare mail
    mixMail2 = (void *)records + recordSize * idxs[playerSlot2][MULTIPLAYER_ID];
    memcpy(&mixMail1->mail[idxs[playerSlot1][DAYCARE_SLOT]], &mixMail2->mail[idxs[playerSlot2][DAYCARE_SLOT]], sizeof(struct DaycareMail));

    // temp --> 2nd player's daycare mail
    memcpy(&mixMail2->mail[idxs[playerSlot2][DAYCARE_SLOT]], &temp, sizeof(struct DaycareMail));
}

// This sum is used to determine which players will swap daycare mail if there are more than 2 players who can.
// The TV show data is used to calculate this sum.
static void CalculateDaycareMailRandSum(const u8 *src)
{
    u8 sum;
    s32 i;

    sum = 0;
    for (i = 0; i < 256; i++)
        sum += src[i];

    sDaycareMailRandSum = sum;
}

static u8 GetDaycareMailRandSum(void)
{
    return sDaycareMailRandSum;
}

static void ReceiveDaycareMailData(struct RecordMixingDaycareMail *records, size_t recordSize, u8 multiplayerId, TVShow *shows)
{
    u16 i, j;
    u8 linkPlayerCount;
    u8 tableId;
    struct RecordMixingDaycareMail *mixMail;
    u8 playerSlot1, playerSlot2;
    void *ptr;
    u8 unusedArr1[MAX_LINK_PLAYERS];
    u8 unusedArr2[MAX_LINK_PLAYERS];
    struct RecordMixingDaycareMail *unusedMixMail[MAX_LINK_PLAYERS];
    bool8 canHoldItem[MAX_LINK_PLAYERS][DAYCARE_MON_COUNT];
    u8 idxs[MAX_LINK_PLAYERS][2];
    u8 numDaycareCanHold;
    u16 oldSeed;
    bool32 anyRS;

    // Seed RNG to the first player's trainer id so that
    // every player has the same random swap occur
    // (see the other use of Random2 in this function)
    oldSeed = Random2();
    SeedRng2(gLinkPlayers[0].trainerId);
    linkPlayerCount = GetLinkPlayerCount();
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        unusedArr1[i] = 0xFF;
        unusedArr2[i] = 0;
        canHoldItem[i][0] = FALSE;
        canHoldItem[i][1] = FALSE;
    }

    // Handle language differences if RS / Japanese players are present
    anyRS = Link_AnyPartnersPlayingRubyOrSapphire();
    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        u32 language, version;

        mixMail = (void *)records + i * recordSize;
        language = gLinkPlayers[i].language;
        version = gLinkPlayers[i].version & 0xFF;

        for (j = 0; j < mixMail->numDaycareMons; j++)
        {
            u16 otNameLanguage, nicknameLanguage;
            struct DaycareMail *daycareMail = &mixMail->mail[j];

            if (daycareMail->message.itemId == ITEM_NONE)
                continue;

            if (anyRS)
            {
                // Handle OT name language
                if (StringLength(daycareMail->otName) <= 5)
                {
                    otNameLanguage = LANGUAGE_JAPANESE;
                }
                else
                {
                    StripExtCtrlCodes(daycareMail->otName);
                    otNameLanguage = language;
                }

                // Handle nickname langugae
                if (daycareMail->monName[0] == EXT_CTRL_CODE_BEGIN && daycareMail->monName[1] == EXT_CTRL_CODE_JPN)
                {
                    StripExtCtrlCodes(daycareMail->monName);
                    nicknameLanguage = LANGUAGE_JAPANESE;
                }
                else
                {
                    nicknameLanguage = language;
                }

                // Set languages
                if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
                {
                    daycareMail->gameLanguage = otNameLanguage;
                    daycareMail->monLanguage = nicknameLanguage;
                }
            }
            else if (language == LANGUAGE_JAPANESE)
            {
                if (IsStringJapanese(daycareMail->otName))
                    daycareMail->gameLanguage = LANGUAGE_JAPANESE;
                else
                    daycareMail->gameLanguage = GAME_LANGUAGE;

                if (IsStringJapanese(daycareMail->monName))
                    daycareMail->monLanguage = LANGUAGE_JAPANESE;
                else
                    daycareMail->monLanguage = GAME_LANGUAGE;
            }
        }
    }

    // For each player, get which of their daycare Pokémon can hold items
    // (can't hold items if already holding one, or if daycare slot is empty).
    // Note that when deposited in the daycare, Pokémon have their mail taken
    // from them and returned upon withdrawal, which means daycare Pokémon that
    // have associated mail do not have a held item.
    // Because not holding an item is the only determination for a swap, this also
    // means that a "swap" can occur even if neither Pokémon has associated mail.
    numDaycareCanHold = 0;
    for (i = 0; i < linkPlayerCount; i++)
    {
        mixMail = (void *)records + i * recordSize;
        if (mixMail->numDaycareMons == 0)
            continue;

        for (j = 0; j < mixMail->numDaycareMons; j++)
        {
            if (!mixMail->cantHoldItem[j])
                canHoldItem[i][j] = TRUE;
        }
    }

    // Fill the idxs array with data about which players
    // and which daycare slots should swap mail.
    j = 0;
    for (i = 0; i < linkPlayerCount; i++)
    {
        mixMail = (void *)records + i * recordSize;

        // Count number of players that have at least
        // one daycare Pokémon with no held item
        if (canHoldItem[i][0] == TRUE || canHoldItem[i][1] == TRUE)
            numDaycareCanHold++;

        if (canHoldItem[i][0] == TRUE && canHoldItem[i][1] == FALSE)
        {
            // Only daycare slot 0 can hold an item for this player, record it
            idxs[j][MULTIPLAYER_ID] = i;
            idxs[j][DAYCARE_SLOT] = 0;
            j++;
        }
        else if (canHoldItem[i][0] == FALSE && canHoldItem[i][1] == TRUE)
        {
            // Only daycare slot 1 can hold an item for this player, record it
            idxs[j][MULTIPLAYER_ID] = i;
            idxs[j][DAYCARE_SLOT] = 1;
            j++;
        }
        else if (canHoldItem[i][0] == TRUE && canHoldItem[i][1] == TRUE)
        {
            // Both daycare slots can hold an item, choose which one to use.
            // If either one is the only one to have associated mail, use that one.
            // If both do or don't have associated mail, choose one randomly.
            u32 itemId1, itemId2;
            idxs[j][MULTIPLAYER_ID] = i;
            itemId1 = GetDaycareMailItemId(&mixMail->mail[0]);
            itemId2 = GetDaycareMailItemId(&mixMail->mail[1]);

            if ((!itemId1 && !itemId2) || (itemId1 && itemId2))
                idxs[j][DAYCARE_SLOT] = Random2() % 2;
            else if (itemId1 && !itemId2)
                idxs[j][DAYCARE_SLOT] = 0;
            else if (!itemId1 && itemId2)
                 idxs[j][DAYCARE_SLOT] = 1;

            j++;
        }
    }

    // Copy the player's record mix mail 4 times to an array that's never read.
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        mixMail = &records[multiplayerId * recordSize];
        unusedMixMail[i] = mixMail;
    }

    // Choose a random table id to determine who will
    // swap if there are more than 2 candidate players.
    tableId = GetDaycareMailRandSum() % NUM_SWAP_COMBOS;
    switch (numDaycareCanHold)
    {
    case 2:
        // 2 players can swap, just perform swap.
        SwapDaycareMail(records, recordSize, idxs, 0, 1);
        break;
    case 3:
        // 3 players can swap, select 2 and leave the 3rd out
        playerSlot1 = sDaycareMailSwapIds_3Player[tableId][0];
        playerSlot2 = sDaycareMailSwapIds_3Player[tableId][1];
        SwapDaycareMail(records, recordSize, idxs, playerSlot1, playerSlot2);
        break;
    case 4:
        // 4 players can swap, select which 2 pairings will swap
        ptr = idxs;

        // Swap pair 1
        playerSlot1 = sDaycareMailSwapIds_4Player[tableId][0];
        playerSlot2 = sDaycareMailSwapIds_4Player[tableId][1];
        SwapDaycareMail(records, recordSize, ptr, playerSlot1, playerSlot2);

        // Swap pair 2
        playerSlot1 = sDaycareMailSwapIds_4Player[tableId][2];
        playerSlot2 = sDaycareMailSwapIds_4Player[tableId][3];
        SwapDaycareMail(records, recordSize, ptr, playerSlot1, playerSlot2);
        break;
    }

    // Save player's record mixed mail to the daycare (in case it has changed)
    mixMail = (void *)records + multiplayerId * recordSize;
    memcpy(&gSaveBlock1Ptr->daycare.mons[0].mail, &mixMail->mail[0], sizeof(struct DaycareMail));
    memcpy(&gSaveBlock1Ptr->daycare.mons[1].mail, &mixMail->mail[1], sizeof(struct DaycareMail));
    SeedRng(oldSeed);
}


static void ReceiveGiftItem(u16 *item, u8 multiplayerId)
{
    if (multiplayerId != 0 && *item != ITEM_NONE && GetPocketByItemId(*item) == POCKET_KEY_ITEMS)
    {
        if (!CheckBagHasItem(*item, 1) && !CheckPCHasItem(*item, 1) && AddBagItem(*item, 1))
        {
            VarSet(VAR_TEMP_1, *item);
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            if (*item == ITEM_EON_TICKET)
                FlagSet(FLAG_ENABLE_SHIP_SOUTHERN_ISLAND);
        }
        else
        {
            VarSet(VAR_TEMP_1, ITEM_NONE);
        }
    }
}

static void Task_DoRecordMixing(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        if (Link_AnyPartnersPlayingRubyOrSapphire())
            task->tState++;
        else
            task->tState = 6;
        break;
    case 2:
        // Mixing Ruby/Sapphire records.
        SetContinueGameWarpStatusToDynamicWarp();
        WriteSaveBlock2();
        task->tState++;
        break;
    case 3:
        if (WriteSaveBlock1Sector())
        {
            ClearContinueGameWarpStatus2();
            task->tState = 4;
            task->data[1] = 0;
        }
        break;
    case 4: // Wait 10 frames
        if (++task->data[1] > 10)
        {
            SetCloseLinkCallback();
            task->tState++;
        }
        break;
    case 5:
        // Finish mixing Ruby/Sapphire records
        if (gReceivedRemoteLinkPlayers == FALSE)
            DestroyTask(taskId);
        break;

    // Mixing Emerald records.
    case 6:
        if (!Rfu_SetLinkRecovery(FALSE))
        {
            CreateTask(Task_LinkFullSave, 5);
            task->tState++;
        }
        break;
    case 7: // wait for Task_LinkFullSave to finish.
        if (!FuncIsActiveTask(Task_LinkFullSave))
        {
            if (gWirelessCommType)
            {
                Rfu_SetLinkRecovery(TRUE);
                task->tState = 8;
            }
            else
            {
                task->tState = 4;
            }
        }
        break;
    case 8:
        SetLinkStandbyCallback();
        task->tState++;
        break;
    case 9:
        if (IsLinkTaskFinished())
            DestroyTask(taskId);
        break;
    }
}

static void GetSavedApprentices(struct Apprentice *dst, struct Apprentice *src)
{
    s32 i, id;
    s32 apprenticeSaveId, oldPlayerApprenticeSaveId;
    s32 numOldPlayerApprentices, numMixApprentices;

    dst[0].playerName[0] = EOS;
    dst[1].playerName[0] = EOS;

    dst[0] = src[0];

    oldPlayerApprenticeSaveId = 0;
    numOldPlayerApprentices = 0;
    apprenticeSaveId = 0;
    numMixApprentices = 0;
    for (i = 0; i < 2; i++)
    {
        id = (i + gSaveBlock2Ptr->playerApprentice.saveId) % (APPRENTICE_COUNT - 1) + 1;
        if (src[id].playerName[0] != EOS)
        {
            if (GetTrainerId(src[id].playerId) != GetTrainerId(gSaveBlock2Ptr->playerTrainerId))
            {
                numMixApprentices++;
                apprenticeSaveId = id;
            }
            if (GetTrainerId(src[id].playerId) == GetTrainerId(gSaveBlock2Ptr->playerTrainerId))
            {
                numOldPlayerApprentices++;
                oldPlayerApprenticeSaveId = id;
            }
        }
    }

    // Prefer passing on other mixed Apprentices rather than old player's Apprentices
    if (numMixApprentices == 0 && numOldPlayerApprentices != 0)
    {
        numMixApprentices = numOldPlayerApprentices;
        apprenticeSaveId = oldPlayerApprenticeSaveId;
    }

    switch (numMixApprentices)
    {
    case 1:
        dst[1] = src[apprenticeSaveId];
        break;
    case 2:
        if (Random2() > 0x3333)
            dst[1] = src[gSaveBlock2Ptr->playerApprentice.saveId + 1];
        else
            dst[1] = src[((gSaveBlock2Ptr->playerApprentice.saveId + 1) % (APPRENTICE_COUNT - 1) + 1)];
        break;
    }
}

void GetPlayerHallRecords(struct PlayerHallRecords *dst)
{
    s32 i, j;

    for (i = 0; i < HALL_FACILITIES_COUNT; i++)
    {
        for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
        {
            CopyTrainerId(dst->onePlayer[i][j].id, gSaveBlock2Ptr->playerTrainerId);
            dst->onePlayer[i][j].language = GAME_LANGUAGE;
            StringCopy(dst->onePlayer[i][j].name, gSaveBlock2Ptr->playerName);
        }
    }

    for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
    {
        dst->twoPlayers[j].language = GAME_LANGUAGE;
        CopyTrainerId(dst->twoPlayers[j].id1, gSaveBlock2Ptr->playerTrainerId);
        CopyTrainerId(dst->twoPlayers[j].id2, gSaveBlock2Ptr->frontier.opponentTrainerIds[j]);
        StringCopy(dst->twoPlayers[j].name1, gSaveBlock2Ptr->playerName);
        StringCopy(dst->twoPlayers[j].name2, gSaveBlock2Ptr->frontier.opponentNames[j]);
    }

    for (i = 0; i < FRONTIER_LVL_MODE_COUNT; i++)
    {
        dst->onePlayer[RANKING_HALL_TOWER_SINGLES][i].winStreak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[FRONTIER_MODE_SINGLES][i];
        dst->onePlayer[RANKING_HALL_TOWER_DOUBLES][i].winStreak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[FRONTIER_MODE_DOUBLES][i];
        dst->onePlayer[RANKING_HALL_TOWER_MULTIS][i].winStreak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[FRONTIER_MODE_MULTIS][i];
        dst->onePlayer[RANKING_HALL_DOME][i].winStreak = gSaveBlock2Ptr->frontier.domeRecordWinStreaks[FRONTIER_MODE_SINGLES][i];
        dst->onePlayer[RANKING_HALL_PALACE][i].winStreak = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[FRONTIER_MODE_SINGLES][i];
        dst->onePlayer[RANKING_HALL_ARENA][i].winStreak = gSaveBlock2Ptr->frontier.arenaRecordStreaks[i];
        dst->onePlayer[RANKING_HALL_FACTORY][i].winStreak = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[FRONTIER_MODE_SINGLES][i];
        dst->onePlayer[RANKING_HALL_PIKE][i].winStreak = gSaveBlock2Ptr->frontier.pikeRecordStreaks[i];
        dst->onePlayer[RANKING_HALL_PYRAMID][i].winStreak = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[i];

        dst->twoPlayers[i].winStreak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[FRONTIER_MODE_LINK_MULTIS][i];
    }
}

static bool32 IsApprenticeAlreadySaved(struct Apprentice *mixApprentice, struct Apprentice *apprentices)
{
    s32 i;

    for (i = 0; i < APPRENTICE_COUNT; i++)
    {
        if (GetTrainerId(mixApprentice->playerId) == GetTrainerId(apprentices[i].playerId)
            && mixApprentice->number == apprentices[i].number)
            return TRUE;
    }

    return FALSE;
}

static void ReceiveApprenticeData(struct Apprentice *records, size_t recordSize, u32 multiplayerId)
{
    s32 i, numApprentices, apprenticeId;
    struct Apprentice *mixApprentice;
    u32 mixIndices[MAX_LINK_PLAYERS];
    u32 apprenticeSaveId;

    ShufflePlayerIndices(mixIndices);
    mixApprentice = (void *)records + (recordSize * mixIndices[multiplayerId]);
    numApprentices = 0;
    apprenticeId = 0;
    for (i = 0; i < 2; i++)
    {
        if (mixApprentice[i].playerName[0] != EOS && !IsApprenticeAlreadySaved(&mixApprentice[i], &gSaveBlock2Ptr->apprentices[0]))
        {
            numApprentices++;
            apprenticeId = i;
        }
    }

    switch (numApprentices)
    {
    case 1:
        apprenticeSaveId = gSaveBlock2Ptr->playerApprentice.saveId + 1;
        gSaveBlock2Ptr->apprentices[apprenticeSaveId] = mixApprentice[apprenticeId];
        gSaveBlock2Ptr->playerApprentice.saveId = (gSaveBlock2Ptr->playerApprentice.saveId + 1) % (APPRENTICE_COUNT - 1);
        break;
    case 2:
        for (i = 0; i < 2; i++)
        {
            apprenticeSaveId = ((i ^ 1) + gSaveBlock2Ptr->playerApprentice.saveId) % (APPRENTICE_COUNT - 1) + 1;
            gSaveBlock2Ptr->apprentices[apprenticeSaveId] = mixApprentice[i];
        }
        gSaveBlock2Ptr->playerApprentice.saveId = (gSaveBlock2Ptr->playerApprentice.saveId + 2) % (APPRENTICE_COUNT - 1);
        break;
    }
}

static void GetNewHallRecords(struct RecordMixingHallRecords *dst, void *records, size_t recordSize, u32 multiplayerId, s32 linkPlayerCount)
{
    s32 i, j, k, l;
    s32 repeatTrainers;

    // Load sPartnerHallRecords with link partners' hall records
    k = 0;
    for (i = 0; i < linkPlayerCount; i++)
    {
        if (i != multiplayerId)
            sPartnerHallRecords[k++] = records;
        if (k == HALL_RECORDS_COUNT)
            break;
        records += recordSize;
    }

    // Get improved 1P hall records
    for (i = 0; i < HALL_FACILITIES_COUNT; i++)
    {
        for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
        {
            // First get the existing saved records
            for (k = 0; k < HALL_RECORDS_COUNT; k++)
                dst->hallRecords1P[i][j][k] = gSaveBlock2Ptr->hallRecords1P[i][j][k];

            // Then read the new mixed records
            for (k = 0; k < linkPlayerCount - 1; k++)
            {
                repeatTrainers = 0;
                for (l = 0; l < HALL_RECORDS_COUNT; l++)
                {
                    // If the new trainer is already in the existing saved records, only
                    // use the new one if the win streak is better
                    if (GetTrainerId(dst->hallRecords1P[i][j][l].id) == GetTrainerId(sPartnerHallRecords[k]->onePlayer[i][j].id))
                    {
                        repeatTrainers++;
                        if (dst->hallRecords1P[i][j][l].winStreak < sPartnerHallRecords[k]->onePlayer[i][j].winStreak)
                            dst->hallRecords1P[i][j][l] = sPartnerHallRecords[k]->onePlayer[i][j];
                    }
                }

                // If all of the mixed records are new trainers, just save them
                if (repeatTrainers == 0)
                    dst->hallRecords1P[i][j][k + HALL_RECORDS_COUNT] = sPartnerHallRecords[k]->onePlayer[i][j];
            }
        }
    }

    // Get improved 2P hall records
    for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
    {
        // First get the existing saved records
        for (k = 0; k < HALL_RECORDS_COUNT; k++)
            dst->hallRecords2P[j][k] = gSaveBlock2Ptr->hallRecords2P[j][k];

        // Then read the new mixed records
        for (k = 0; k < linkPlayerCount - 1; k++)
        {
            repeatTrainers = 0;
            for (l = 0; l < HALL_RECORDS_COUNT; l++)
            {
                // If the new trainer pair is already in the existing saved records, only
                // use the new pair if the win streak is better
                if (GetTrainerId(dst->hallRecords2P[j][l].id1) == GetTrainerId(sPartnerHallRecords[k]->twoPlayers[j].id1)
                 && GetTrainerId(dst->hallRecords2P[j][l].id2) == GetTrainerId(sPartnerHallRecords[k]->twoPlayers[j].id2))
                {
                    repeatTrainers++;
                    if (dst->hallRecords2P[j][l].winStreak < sPartnerHallRecords[k]->twoPlayers[j].winStreak)
                        dst->hallRecords2P[j][l] = sPartnerHallRecords[k]->twoPlayers[j];
                }
            }

            // If all of the mixed records are new trainer pairs, just save them
            if (repeatTrainers == 0)
                dst->hallRecords2P[j][k + HALL_RECORDS_COUNT] = sPartnerHallRecords[k]->twoPlayers[j];
        }
    }
}

static void FillWinStreakRecords1P(struct RankingHall1P *playerRecords, struct RankingHall1P *mixRecords)
{
    s32 i, j;

    // Fill the player's 1P records with the highest win streaks from the mixed records
    for (i = 0; i < HALL_RECORDS_COUNT; i++)
    {
        // Get the highest remaining win streak in the mixed hall records
        s32 highestWinStreak = 0;
        s32 highestId = -1;
        for (j = 0; j < HALL_RECORDS_COUNT * 2; j++)
        {
            if (mixRecords[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = mixRecords[j].winStreak;
            }
        }

        // Save the win streak to the player's records, then clear it from the mixed records
        if (highestId >= 0)
        {
            playerRecords[i] = mixRecords[highestId];
            mixRecords[highestId].winStreak = 0;
        }
    }
}

static void FillWinStreakRecords2P(struct RankingHall2P *playerRecords, struct RankingHall2P *mixRecords)
{
    s32 i, j;

    // Fill the player's 2P records with the highest win streaks from the mixed records
    for (i = 0; i < HALL_RECORDS_COUNT; i++)
    {
        // Get the highest remaining win streak in the mixed hall records
        s32 highestWinStreak = 0;
        s32 highestId = -1;
        for (j = 0; j < HALL_RECORDS_COUNT * 2; j++)
        {
            if (mixRecords[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = mixRecords[j].winStreak;
            }
        }

        // Save the win streak to the player's records, then clear it from the mixed records
        if (highestId >= 0)
        {
            playerRecords[i] = mixRecords[highestId];
            mixRecords[highestId].winStreak = 0;
        }
    }
}

static void SaveHighestWinStreakRecords(struct RecordMixingHallRecords *mixHallRecords)
{
    s32 i, j;

    for (i = 0; i < HALL_FACILITIES_COUNT; i++)
    {
        for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
            FillWinStreakRecords1P(gSaveBlock2Ptr->hallRecords1P[i][j], mixHallRecords->hallRecords1P[i][j]);
    }
    for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
        FillWinStreakRecords2P(gSaveBlock2Ptr->hallRecords2P[j], mixHallRecords->hallRecords2P[j]);
}

static void ReceiveRankingHallRecords(struct PlayerHallRecords *records, size_t recordSize, u32 multiplayerId)
{
    u8 linkPlayerCount = GetLinkPlayerCount();
    struct RecordMixingHallRecords *mixHallRecords = AllocZeroed(sizeof(*mixHallRecords));

    GetNewHallRecords(mixHallRecords, records, recordSize, multiplayerId, linkPlayerCount);
    SaveHighestWinStreakRecords(mixHallRecords);

    Free(mixHallRecords);
}

static void GetRecordMixingDaycareMail(struct RecordMixingDaycareMail *dst)
{
    sRecordMixMail.mail[0] = gSaveBlock1Ptr->daycare.mons[0].mail;
    sRecordMixMail.mail[1] = gSaveBlock1Ptr->daycare.mons[1].mail;
    InitDaycareMailRecordMixing(&gSaveBlock1Ptr->daycare, &sRecordMixMail);
    *dst = *sRecordMixMailSave;
}

static void SanitizeDaycareMailForRuby(struct RecordMixingDaycareMail *src)
{
    s32 i;

    for (i = 0; i < src->numDaycareMons; i++)
    {
        struct DaycareMail *mail = &src->mail[i];
        if (mail->message.itemId != ITEM_NONE)
        {
            if (mail->gameLanguage != LANGUAGE_JAPANESE)
                PadNameString(mail->otName, EXT_CTRL_CODE_BEGIN);

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

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        struct BattleTowerPokemon *towerMon = &dst->party[i];
        if (towerMon->species != SPECIES_NONE)
            StripExtCtrlCodes(towerMon->nickname);
    }

    CalcEmeraldBattleTowerChecksum(dst);
}
