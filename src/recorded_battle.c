#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "recorded_battle.h"
#include "main.h"
#include "pokemon.h"
#include "random.h"
#include "event_data.h"
#include "link.h"
#include "string_util.h"
#include "palette.h"
#include "save.h"
#include "malloc.h"
#include "util.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "battle_setup.h"
#include "frontier_util.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

struct PlayerInfo
{
    u32 trainerId;
    u8 name[PLAYER_NAME_LENGTH + 1];
    u8 gender;
    u16 battlerId;
    u16 language;
};

// Save data using TryWriteSpecialSaveSector is allowed to exceed SECTOR_DATA_SIZE (up to the counter field)
STATIC_ASSERT(sizeof(struct RecordedBattleSave) <= SECTOR_COUNTER_OFFSET, RecordedBattleSaveFreeSpace);

EWRAM_DATA u32 gRecordedBattleRngSeed = 0;
EWRAM_DATA u32 gBattlePalaceMoveSelectionRngValue = 0;
EWRAM_DATA static u8 sBattleRecords[MAX_BATTLERS_COUNT][BATTLER_RECORD_SIZE] = {0};
EWRAM_DATA static u16 sBattlerRecordSizes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA static u16 sBattlerPrevRecordSizes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA static u16 sBattlerSavedRecordSizes[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA static u8 sRecordMode = 0;
EWRAM_DATA static u8 sLvlMode = 0;
EWRAM_DATA static u8 sFrontierFacility = 0;
EWRAM_DATA static u8 sFrontierBrainSymbol = 0;
EWRAM_DATA static MainCallback sCallback2_AfterRecordedBattle = NULL;
EWRAM_DATA u8 gRecordedBattleMultiplayerId = 0;
EWRAM_DATA static u8 sFrontierPassFlag = 0;
EWRAM_DATA static u8 sBattleScene = 0;
EWRAM_DATA static u8 sTextSpeed = 0;
EWRAM_DATA static u32 sBattleFlags = 0;
EWRAM_DATA static u32 sAI_Scripts = 0;
EWRAM_DATA static struct Pokemon sSavedPlayerParty[PARTY_SIZE] = {0};
EWRAM_DATA static struct Pokemon sSavedOpponentParty[PARTY_SIZE] = {0};
EWRAM_DATA static u16 sPlayerMonMoves[MAX_BATTLERS_COUNT / 2][MAX_MON_MOVES] = {0};
EWRAM_DATA static struct PlayerInfo sPlayers[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA static bool8 sIsPlaybackFinished = 0;
EWRAM_DATA static u8 sRecordMixFriendName[PLAYER_NAME_LENGTH + 1] = {0};
EWRAM_DATA static u8 sRecordMixFriendClass = 0;
EWRAM_DATA static u8 sApprenticeId = 0;
EWRAM_DATA static u16 sEasyChatSpeech[EASY_CHAT_BATTLE_WORDS_COUNT] = {0};
EWRAM_DATA static u8 sBattleOutcome = 0;

static u8 sRecordMixFriendLanguage;
static u8 sApprenticeLanguage;

static u8 GetNextRecordedDataByte(u8 *, u8 *, u8 *);
static bool32 CopyRecordedBattleFromSave(struct RecordedBattleSave *);
static void RecordedBattle_RestoreSavedParties(void);
static void CB2_RecordedBattle(void);

void RecordedBattle_Init(u8 mode)
{
    s32 i, j;

    sRecordMode = mode;
    sIsPlaybackFinished = FALSE;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerRecordSizes[i] = 0;
        sBattlerPrevRecordSizes[i] = 0;
        sBattlerSavedRecordSizes[i] = 0;

        if (mode == B_RECORD_MODE_RECORDING)
        {
            for (j = 0; j < BATTLER_RECORD_SIZE; j++)
                sBattleRecords[i][j] = 0xFF;
            sBattleFlags = gBattleTypeFlags;
            sAI_Scripts = gBattleResources->ai->aiFlags;
        }
    }
}

void RecordedBattle_SetTrainerInfo(void)
{
    s32 i, j;

    if (sRecordMode == B_RECORD_MODE_RECORDING)
    {
        gRecordedBattleRngSeed = gRngValue;
        sFrontierFacility = VarGet(VAR_FRONTIER_FACILITY);
        sFrontierBrainSymbol = GetFronterBrainSymbol();
    }
    else if (sRecordMode == B_RECORD_MODE_PLAYBACK)
    {
        gRngValue = gRecordedBattleRngSeed;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        // Link recorded battle, record info for all trainers
        u8 linkPlayersCount;
        u8 text[30];

        gRecordedBattleMultiplayerId = GetMultiplayerId();
        linkPlayersCount = GetLinkPlayerCount();

        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            sPlayers[i].trainerId = gLinkPlayers[i].trainerId;
            sPlayers[i].gender = gLinkPlayers[i].gender;
            sPlayers[i].battlerId = gLinkPlayers[i].id;
            sPlayers[i].language = gLinkPlayers[i].language;

            // Record names
            if (i < linkPlayersCount)
            {
                StringCopy(text, gLinkPlayers[i].name);
                StripExtCtrlCodes(text);
                StringCopy(sPlayers[i].name, text);
            }
            else
            {
                for (j = 0; j < PLAYER_NAME_LENGTH + 1; j++)
                    sPlayers[i].name[j] = gLinkPlayers[i].name[j];
            }
        }
    }
    else
    {
        // Local battle, just record own info
        sPlayers[0].trainerId = (gSaveBlock2Ptr->playerTrainerId[0])
                              | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
                              | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
                              | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

        sPlayers[0].gender = gSaveBlock2Ptr->playerGender;
        sPlayers[0].battlerId = 0;
        sPlayers[0].language = gGameLanguage;

        for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
            sPlayers[0].name[i] = gSaveBlock2Ptr->playerName[i];
    }
}

void RecordedBattle_SetBattlerAction(u8 battlerId, u8 action)
{
    if (sBattlerRecordSizes[battlerId] < BATTLER_RECORD_SIZE && sRecordMode != B_RECORD_MODE_PLAYBACK)
        sBattleRecords[battlerId][sBattlerRecordSizes[battlerId]++] = action;
}

void RecordedBattle_ClearBattlerAction(u8 battlerId, u8 bytesToClear)
{
    s32 i;

    for (i = 0; i < bytesToClear; i++)
    {
        sBattlerRecordSizes[battlerId]--;
        sBattleRecords[battlerId][sBattlerRecordSizes[battlerId]] = 0xFF;
        if (sBattlerRecordSizes[battlerId] == 0)
            break;
    }
}

u8 RecordedBattle_GetBattlerAction(u32 actionType, u8 battlerId)
{
    if (gTestRunnerEnabled)
        TestRunner_Battle_CheckBattleRecordActionType(battlerId, sBattlerRecordSizes[battlerId], actionType);

    // Trying to read past array or invalid action byte, battle is over.
    if (sBattlerRecordSizes[battlerId] >= BATTLER_RECORD_SIZE || sBattleRecords[battlerId][sBattlerRecordSizes[battlerId]] == 0xFF)
    {
        gSpecialVar_Result = gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED; // hah
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_QuitRecordedBattle);
        return 0xFF;
    }
    else
    {
        return sBattleRecords[battlerId][sBattlerRecordSizes[battlerId]++];
    }
}

static u8 UNUSED GetRecordedBattleMode(void)
{
    return sRecordMode;
}

u8 RecordedBattle_BufferNewBattlerData(u8 *dst)
{
    u8 i, j;
    u8 idx = 0;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (sBattlerRecordSizes[i] != sBattlerPrevRecordSizes[i])
        {
            dst[idx++] = i;
            dst[idx++] = sBattlerRecordSizes[i] - sBattlerPrevRecordSizes[i];

            for (j = 0; j < sBattlerRecordSizes[i] - sBattlerPrevRecordSizes[i]; j++)
                dst[idx++] = sBattleRecords[i][sBattlerPrevRecordSizes[i] + j];

            sBattlerPrevRecordSizes[i] = sBattlerRecordSizes[i];
        }
    }

    return idx;
}

void RecordedBattle_RecordAllBattlerData(u8 *src)
{
    s32 i;
    u8 idx = 2;
    u8 size;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        if ((gLinkPlayers[i].version & 0xFF) != VERSION_EMERALD)
            return;
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
    {
        for (size = *src; size != 0;)
        {
            u8 battlerId = GetNextRecordedDataByte(src, &idx, &size);
            u8 numActions = GetNextRecordedDataByte(src, &idx, &size);

            for (i = 0; i < numActions; i++)
                sBattleRecords[battlerId][sBattlerSavedRecordSizes[battlerId]++] = GetNextRecordedDataByte(src, &idx, &size);
        }
    }
}

static u8 GetNextRecordedDataByte(u8 *data, u8 *idx, u8 *size)
{
    (*size)--;
    return data[(*idx)++];
}

bool32 CanCopyRecordedBattleSaveData(void)
{
    struct RecordedBattleSave *dst = AllocZeroed(sizeof(struct RecordedBattleSave));
    bool32 ret = CopyRecordedBattleFromSave(dst);
    Free(dst);
    return ret;
}

static bool32 IsRecordedBattleSaveValid(struct RecordedBattleSave *save)
{
    if (save->battleFlags == 0)
        return FALSE;
    if (save->battleFlags & BATTLE_TYPE_RECORDED_INVALID)
        return FALSE;
    if (CalcByteArraySum((void *)(save), sizeof(*save) - 4) != save->checksum)
        return FALSE;

    return TRUE;
}

static bool32 RecordedBattleToSave(struct RecordedBattleSave *battleSave, struct RecordedBattleSave *saveSector)
{
    memset(saveSector, 0, SECTOR_SIZE);
    memcpy(saveSector, battleSave, sizeof(*battleSave));

    saveSector->checksum = CalcByteArraySum((void *)(saveSector), sizeof(*saveSector) - 4);

    if (TryWriteSpecialSaveSector(SECTOR_ID_RECORDED_BATTLE, (void *)(saveSector)) != SAVE_STATUS_OK)
        return FALSE;
    else
        return TRUE;
}

bool32 MoveRecordedBattleToSaveData(void)
{
    s32 i, j;
    bool32 ret;
    struct RecordedBattleSave *battleSave, *savSection;
    u8 saveAttempts;

    saveAttempts = 0;
    battleSave = AllocZeroed(sizeof(struct RecordedBattleSave));
    savSection = AllocZeroed(SECTOR_SIZE);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        battleSave->playerParty[i] = sSavedPlayerParty[i];
        battleSave->opponentParty[i] = sSavedOpponentParty[i];
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        for (j = 0; j < PLAYER_NAME_LENGTH + 1; j++)
            battleSave->playersName[i][j] = sPlayers[i].name[j];
        battleSave->playersGender[i] = sPlayers[i].gender;
        battleSave->playersLanguage[i] = sPlayers[i].language;
        battleSave->playersBattlers[i] = sPlayers[i].battlerId;
        battleSave->playersTrainerId[i] = sPlayers[i].trainerId;
    }

    battleSave->rngSeed = gRecordedBattleRngSeed;

    if (sBattleFlags & BATTLE_TYPE_LINK)
    {
        battleSave->battleFlags = (sBattleFlags & ~(BATTLE_TYPE_LINK | BATTLE_TYPE_LINK_IN_BATTLE)) | BATTLE_TYPE_RECORDED_LINK;

        // BATTLE_TYPE_RECORDED_IS_MASTER set indicates battle will play
        // out from player's perspective (i.e. player with back to camera)
        // Otherwise player will appear on "opponent" side
        if (sBattleFlags & BATTLE_TYPE_IS_MASTER)
        {
            battleSave->battleFlags |= BATTLE_TYPE_RECORDED_IS_MASTER;
        }
        else if (sBattleFlags & BATTLE_TYPE_MULTI)
        {
            switch (sPlayers[0].battlerId)
            {
            case 0:
            case 2:
                if (!(sPlayers[gRecordedBattleMultiplayerId].battlerId & 1))
                    battleSave->battleFlags |= BATTLE_TYPE_RECORDED_IS_MASTER;
                break;
            case 1:
            case 3:
                if ((sPlayers[gRecordedBattleMultiplayerId].battlerId & 1))
                    battleSave->battleFlags |= BATTLE_TYPE_RECORDED_IS_MASTER;
                break;
            }
        }
    }
    else
    {
        battleSave->battleFlags = sBattleFlags;
    }

    battleSave->opponentA = gTrainerBattleOpponent_A;
    battleSave->opponentB = gTrainerBattleOpponent_B;
    battleSave->partnerId = gPartnerTrainerId;
    battleSave->multiplayerId = gRecordedBattleMultiplayerId;
    battleSave->lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleSave->frontierFacility = sFrontierFacility;
    battleSave->frontierBrainSymbol = sFrontierBrainSymbol;
    battleSave->battleScene = gSaveBlock2Ptr->optionsBattleSceneOff;
    battleSave->textSpeed = gSaveBlock2Ptr->optionsTextSpeed;
    battleSave->AI_scripts = sAI_Scripts;

    if (gTrainerBattleOpponent_A >= TRAINER_RECORD_MIXING_FRIEND && gTrainerBattleOpponent_A < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
            battleSave->recordMixFriendName[i] = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_FRIEND].name[i];
        battleSave->recordMixFriendClass = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_FRIEND].facilityClass;

        if (sBattleOutcome == B_OUTCOME_WON)
        {
            for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
                battleSave->easyChatSpeech[i] = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_FRIEND].speechLost[i];
        }
        else
        {
            for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
                battleSave->easyChatSpeech[i] = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_FRIEND].speechWon[i];
        }
        battleSave->recordMixFriendLanguage = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_FRIEND].language;
    }
    else if (gTrainerBattleOpponent_B >= TRAINER_RECORD_MIXING_FRIEND && gTrainerBattleOpponent_B < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
            battleSave->recordMixFriendName[i] = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_FRIEND].name[i];
        battleSave->recordMixFriendClass = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_FRIEND].facilityClass;

        if (sBattleOutcome == B_OUTCOME_WON)
        {
            for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
                battleSave->easyChatSpeech[i] = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_FRIEND].speechLost[i];
        }
        else
        {
            for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
                battleSave->easyChatSpeech[i] = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_FRIEND].speechWon[i];
        }
        battleSave->recordMixFriendLanguage = gSaveBlock2Ptr->frontier.towerRecords[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_FRIEND].language;
    }
    else if (gPartnerTrainerId >= TRAINER_RECORD_MIXING_FRIEND && gPartnerTrainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
            battleSave->recordMixFriendName[i] = gSaveBlock2Ptr->frontier.towerRecords[gPartnerTrainerId - TRAINER_RECORD_MIXING_FRIEND].name[i];
        battleSave->recordMixFriendClass = gSaveBlock2Ptr->frontier.towerRecords[gPartnerTrainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;

        battleSave->recordMixFriendLanguage = gSaveBlock2Ptr->frontier.towerRecords[gPartnerTrainerId - TRAINER_RECORD_MIXING_FRIEND].language;
    }

    if (gTrainerBattleOpponent_A >= TRAINER_RECORD_MIXING_APPRENTICE)
    {
        battleSave->apprenticeId = gSaveBlock2Ptr->apprentices[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_APPRENTICE].id;
        for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
            battleSave->easyChatSpeech[i] = gSaveBlock2Ptr->apprentices[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_APPRENTICE].speechWon[i];
        battleSave->apprenticeLanguage = gSaveBlock2Ptr->apprentices[gTrainerBattleOpponent_A - TRAINER_RECORD_MIXING_APPRENTICE].language;
    }
    else if (gTrainerBattleOpponent_B >= TRAINER_RECORD_MIXING_APPRENTICE)
    {
        battleSave->apprenticeId = gSaveBlock2Ptr->apprentices[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_APPRENTICE].id;
        for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
            battleSave->easyChatSpeech[i] = gSaveBlock2Ptr->apprentices[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_APPRENTICE].speechWon[i];
        battleSave->apprenticeLanguage = gSaveBlock2Ptr->apprentices[gTrainerBattleOpponent_B - TRAINER_RECORD_MIXING_APPRENTICE].language;
    }
    else if (gPartnerTrainerId >= TRAINER_RECORD_MIXING_APPRENTICE)
    {
        battleSave->apprenticeId = gSaveBlock2Ptr->apprentices[gPartnerTrainerId - TRAINER_RECORD_MIXING_APPRENTICE].id;

        battleSave->apprenticeLanguage = gSaveBlock2Ptr->apprentices[gPartnerTrainerId - TRAINER_RECORD_MIXING_APPRENTICE].language;
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        for (j = 0; j < BATTLER_RECORD_SIZE; j++)
            battleSave->battleRecord[i][j] = sBattleRecords[i][j];

    while (1)
    {
        ret = RecordedBattleToSave(battleSave, savSection);
        if (ret == TRUE)
            break;
        saveAttempts++;
        if (saveAttempts >= 3)
            break;
    }

    Free(battleSave);
    Free(savSection);
    return ret;
}

static bool32 TryCopyRecordedBattleSaveData(struct RecordedBattleSave *dst, struct SaveSector *saveBuffer)
{
    if (TryReadSpecialSaveSector(SECTOR_ID_RECORDED_BATTLE, (void *)(saveBuffer)) != SAVE_STATUS_OK)
        return FALSE;

    memcpy(dst, saveBuffer, sizeof(struct RecordedBattleSave));

    if (!IsRecordedBattleSaveValid(dst))
        return FALSE;

    return TRUE;
}

static bool32 CopyRecordedBattleFromSave(struct RecordedBattleSave *dst)
{
    struct SaveSector *savBuffer = AllocZeroed(SECTOR_SIZE);
    bool32 ret = TryCopyRecordedBattleSaveData(dst, savBuffer);
    Free(savBuffer);

    return ret;
}

static void CB2_RecordedBattleEnd(void)
{
    gSaveBlock2Ptr->frontier.lvlMode = sLvlMode;
    gBattleOutcome = 0;
    gBattleTypeFlags = 0;
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
    gPartnerTrainerId = 0;

    RecordedBattle_RestoreSavedParties();
    SetMainCallback2(sCallback2_AfterRecordedBattle);
}

#define tFramesToWait data[0]

static void Task_StartAfterCountdown(u8 taskId)
{
    if (--gTasks[taskId].tFramesToWait == 0)
    {
        gMain.savedCallback = CB2_RecordedBattleEnd;
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

void SetPartiesFromRecordedSave(struct RecordedBattleSave *src)
{
    s32 i;

    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    for (i = 0; i < PARTY_SIZE; i++)
    {
        gPlayerParty[i] = src->playerParty[i];
        gEnemyParty[i] = src->opponentParty[i];
    }
}

void SetVariablesForRecordedBattle(struct RecordedBattleSave *src)
{
    bool8 var;
    s32 i, j;

    SetPartiesFromRecordedSave(src);
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        for (var = FALSE, j = 0; j < PLAYER_NAME_LENGTH + 1; j++)
        {
            gLinkPlayers[i].name[j] = src->playersName[i][j];
            if (src->playersName[i][j] == EOS)
                var = TRUE;
        }
        gLinkPlayers[i].gender = src->playersGender[i];
        gLinkPlayers[i].language = src->playersLanguage[i];
        gLinkPlayers[i].id = src->playersBattlers[i];
        gLinkPlayers[i].trainerId = src->playersTrainerId[i];

        if (var)
            ConvertInternationalString(gLinkPlayers[i].name, gLinkPlayers[i].language);
    }

    gRecordedBattleRngSeed = src->rngSeed;
    gBattleTypeFlags = src->battleFlags | BATTLE_TYPE_RECORDED;
    gTrainerBattleOpponent_A = src->opponentA;
    gTrainerBattleOpponent_B = src->opponentB;
    gPartnerTrainerId = src->partnerId;
    gRecordedBattleMultiplayerId = src->multiplayerId;
    sLvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    sFrontierFacility = src->frontierFacility;
    sFrontierBrainSymbol = src->frontierBrainSymbol;
    sBattleScene = src->battleScene;
    sTextSpeed = src->textSpeed;
    sAI_Scripts = src->AI_scripts;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
        sRecordMixFriendName[i] = src->recordMixFriendName[i];

    sRecordMixFriendClass = src->recordMixFriendClass;
    sApprenticeId = src->apprenticeId;
    sRecordMixFriendLanguage = src->recordMixFriendLanguage;
    sApprenticeLanguage = src->apprenticeLanguage;

    for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
        sEasyChatSpeech[i] = src->easyChatSpeech[i];

    gSaveBlock2Ptr->frontier.lvlMode = src->lvlMode;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        for (j = 0; j < BATTLER_RECORD_SIZE; j++)
            sBattleRecords[i][j] = src->battleRecord[i][j];
}

void PlayRecordedBattle(void (*CB2_After)(void))
{
    struct RecordedBattleSave *battleSave = AllocZeroed(sizeof(struct RecordedBattleSave));
    if (CopyRecordedBattleFromSave(battleSave) == TRUE)
    {
        u8 taskId;

        RecordedBattle_SaveParties();
        SetVariablesForRecordedBattle(battleSave);

        taskId = CreateTask(Task_StartAfterCountdown, 1);
        gTasks[taskId].tFramesToWait = 128;

        sCallback2_AfterRecordedBattle = CB2_After;
        PlayMapChosenOrBattleBGM(FALSE);
        SetMainCallback2(CB2_RecordedBattle);
    }
    Free(battleSave);
}

#undef tFramesToWait

static void CB2_RecordedBattle(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTasks();
}

u8 GetRecordedBattleFrontierFacility(void)
{
    return sFrontierFacility;
}

u8 GetRecordedBattleFronterBrainSymbol(void)
{
    return sFrontierBrainSymbol;
}

void RecordedBattle_SaveParties(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        sSavedPlayerParty[i] = gPlayerParty[i];
        sSavedOpponentParty[i] = gEnemyParty[i];
    }
}

static void RecordedBattle_RestoreSavedParties(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gPlayerParty[i] = sSavedPlayerParty[i];
        gEnemyParty[i] = sSavedOpponentParty[i];
    }
}

u8 GetBattlerLinkPlayerGender(u32 battler)
{
    s32 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayers[i].id == battler)
            break;
    }

    if (i != MAX_LINK_PLAYERS)
        return gLinkPlayers[i].gender;

    return 0;
}

void RecordedBattle_ClearFrontierPassFlag(void)
{
    sFrontierPassFlag = 0;
}

// Set sFrontierPassFlag to received state of FLAG_SYS_FRONTIER_PASS
void RecordedBattle_SetFrontierPassFlagFromHword(u16 flags)
{
    sFrontierPassFlag |= (flags & (1 << 15)) >> 15;
}

u8 RecordedBattle_GetFrontierPassFlag(void)
{
    return sFrontierPassFlag;
}

u8 GetBattleSceneInRecordedBattle(void)
{
    return sBattleScene;
}

u8 GetTextSpeedInRecordedBattle(void)
{
    return sTextSpeed;
}

void RecordedBattle_CopyBattlerMoves(u32 battler)
{
    s32 i;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        return;
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return;
    if (sRecordMode == B_RECORD_MODE_PLAYBACK)
        return;

    for (i = 0; i < MAX_MON_MOVES; i++)
        sPlayerMonMoves[battler / 2][i] = gBattleMons[battler].moves[i];
}

// This is a special battle action only used by this function
// It shares a value with B_ACTION_SAFARI_POKEBLOCK, which can never occur in a recorded battle.
#define ACTION_MOVE_CHANGE 6

void RecordedBattle_CheckMovesetChanges(u8 mode)
{
    s32 battlerId, j, k;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return;

    for (battlerId = 0; battlerId < gBattlersCount; battlerId++)
    {
        // Player's side only
        if (GetBattlerSide(battlerId) != B_SIDE_OPPONENT)
        {
            if (mode == B_RECORD_MODE_RECORDING)
            {
                // Check if any of the battler's moves have changed.
                for (j = 0; j < MAX_MON_MOVES; j++)
                {
                    if (gBattleMons[battlerId].moves[j] != sPlayerMonMoves[battlerId / 2][j])
                        break;
                }
                if (j != MAX_MON_MOVES)
                {
                    // At least one of the moves has been changed
                    RecordedBattle_SetBattlerAction(battlerId, ACTION_MOVE_CHANGE);
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        for (k = 0; k < MAX_MON_MOVES; k++)
                        {
                            if (gBattleMons[battlerId].moves[j] == sPlayerMonMoves[battlerId / 2][k])
                            {
                                RecordedBattle_SetBattlerAction(battlerId, k);
                                break;
                            }
                        }
                    }
                }
            }
            else // B_RECORD_MODE_PLAYBACK
            {
                if (sBattleRecords[battlerId][sBattlerRecordSizes[battlerId]] == ACTION_MOVE_CHANGE)
                {
                    u8 ppBonuses[MAX_MON_MOVES];
                    u8 moveSlots[MAX_MON_MOVES];
                    u8 mimickedMoveSlots[MAX_MON_MOVES];
                    struct ChooseMoveStruct movePp;
                    u8 ppBonusSet;

                    // We know the current action is ACTION_MOVE_CHANGE, retrieve
                    // it without saving it to move on to the next action.
                    RecordedBattle_GetBattlerAction(RECORDED_BYTE, battlerId);

                    for (j = 0; j < MAX_MON_MOVES; j++)
                        ppBonuses[j] = ((gBattleMons[battlerId].ppBonuses & (3 << (j << 1))) >> (j << 1));

                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        moveSlots[j] = RecordedBattle_GetBattlerAction(RECORDED_BYTE, battlerId);
                        movePp.moves[j] = gBattleMons[battlerId].moves[moveSlots[j]];
                        movePp.currentPp[j] = gBattleMons[battlerId].pp[moveSlots[j]];
                        movePp.maxPp[j] = ppBonuses[moveSlots[j]];
                        mimickedMoveSlots[j] = (gDisableStructs[battlerId].mimickedMoves & gBitTable[j]) >> j;
                    }
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        gBattleMons[battlerId].moves[j] = movePp.moves[j];
                        gBattleMons[battlerId].pp[j] = movePp.currentPp[j];
                    }
                    gBattleMons[battlerId].ppBonuses = 0;
                    gDisableStructs[battlerId].mimickedMoves = 0;
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        gBattleMons[battlerId].ppBonuses |= movePp.maxPp[j] << (j << 1);
                        gDisableStructs[battlerId].mimickedMoves |= mimickedMoveSlots[j] << j;
                    }

                    if (!(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED))
                    {
                        for (j = 0; j < MAX_MON_MOVES; j++)
                            ppBonuses[j] = (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PP_BONUSES, NULL) & ((3 << (j << 1)))) >> (j << 1);

                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            movePp.moves[j] = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_MOVE1 + moveSlots[j], NULL);
                            movePp.currentPp[j] = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PP1 + moveSlots[j], NULL);
                            movePp.maxPp[j] = ppBonuses[moveSlots[j]];
                        }
                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            SetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_MOVE1 + j, &movePp.moves[j]);
                            SetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PP1 + j, &movePp.currentPp[j]);
                        }
                        ppBonusSet = 0;
                        for (j = 0; j < MAX_MON_MOVES; j++)
                            ppBonusSet |= movePp.maxPp[j] << (j << 1);

                        SetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_PP_BONUSES, &ppBonusSet);
                    }
                    gChosenMoveByBattler[battlerId] = gBattleMons[battlerId].moves[*(gBattleStruct->chosenMovePositions + battlerId)];
                }
            }
        }
    }
}

u32 GetAiScriptsInRecordedBattle(void)
{
    return sAI_Scripts;
}

// Used to determine when the player is allowed to press B to end a recorded battle's playback
void RecordedBattle_SetPlaybackFinished(void)
{
    sIsPlaybackFinished = TRUE;
}

bool8 RecordedBattle_CanStopPlayback(void)
{
    return (sIsPlaybackFinished == FALSE);
}

void GetRecordedBattleRecordMixFriendName(u8 *dst)
{
    s32 i;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
        dst[i] = sRecordMixFriendName[i];
    dst[PLAYER_NAME_LENGTH] = EOS;
    ConvertInternationalString(dst, sRecordMixFriendLanguage);
}

u8 GetRecordedBattleRecordMixFriendClass(void)
{
    return sRecordMixFriendClass;
}

u8 GetRecordedBattleApprenticeId(void)
{
    return sApprenticeId;
}

u8 GetRecordedBattleRecordMixFriendLanguage(void)
{
    return sRecordMixFriendLanguage;
}

u8 GetRecordedBattleApprenticeLanguage(void)
{
    return sApprenticeLanguage;
}

void RecordedBattle_SaveBattleOutcome(void)
{
    sBattleOutcome = gBattleOutcome;
}

u16 *GetRecordedBattleEasyChatSpeech(void)
{
    return sEasyChatSpeech;
}
