#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_gfx_sfx_util.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tv.h"
#include "cable_club.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_animation.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "sound.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "trainer.h"
#include "util.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/item_effects.h"
#include "constants/songs.h"
#include "test/battle.h"
#include "test/test.h"

static EWRAM_DATA u8 sLinkSendTaskId = 0;
static EWRAM_DATA u8 sLinkReceiveTaskId = 0;

COMMON_DATA void (*gBattlerControllerFuncs[MAX_BATTLERS_COUNT])(enum BattlerId battler) = {0};
COMMON_DATA u8 gBattleControllerData[MAX_BATTLERS_COUNT] = {0}; // Used by the battle controllers to store misc sprite/task IDs for each battler
COMMON_DATA void (*gBattlerControllerEndFuncs[MAX_BATTLERS_COUNT])(enum BattlerId battler) = {0}; // Controller's buffer complete function for each battler
u8 gBattlerBattleController[MAX_BATTLERS_COUNT] = {0}; // Battle controller for each battler

static void CreateTasksForSendRecvLinkBuffers(void);
static void InitBtlControllersInternal(void);
static void SetBattlePartyIds(void);
static void Task_HandleSendLinkBuffersData(u8 taskId);
static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId);
static void Task_StartSendOutAnim(u8 taskId);
static void SpriteCB_FreePlayerSpriteLoadMonSprite(struct Sprite *sprite);
static void SpriteCB_FreeOpponentSprite(struct Sprite *sprite);
static u32 ReturnAnimIdForBattler(bool32 isPlayerSide, u32 specificBattler);
static void LaunchKOAnimation(enum BattlerId battlerId, u16 animId, bool32 isFront);
static void AnimateMonAfterKnockout(enum BattlerId battler);

bool32 IsAiVsAiBattle(void)
{
    return (B_FLAG_AI_VS_AI_BATTLE && FlagGet(B_FLAG_AI_VS_AI_BATTLE));
}

bool32 BattlerIsPlayer(enum BattlerId battlerId)
{
    return (gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_PLAYER
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_RECORDED_PLAYER);
}

bool32 BattlerIsPartner(enum BattlerId battlerId)
{
    return (gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_PLAYER_PARTNER
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_RECORDED_PARTNER
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_LINK_PARTNER);
}

bool32 BattlerIsOpponent(enum BattlerId battlerId)
{
    return (gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_OPPONENT
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_RECORDED_OPPONENT
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_LINK_OPPONENT);
}

bool32 BattlerIsRecorded(enum BattlerId battlerId)
{
    return (gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_RECORDED_PLAYER
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_RECORDED_PARTNER
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_RECORDED_OPPONENT);
}

bool32 BattlerIsLink(enum BattlerId battlerId)
{
    return (gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_LINK_PARTNER
         || gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_LINK_OPPONENT);
}

bool32 BattlerIsWally(enum BattlerId battlerId)
{
    return (gBattlerBattleController[battlerId] == BATTLE_CONTROLLER_WALLY);
}

bool32 BattlerHasAi(enum BattlerId battlerId)
{
    switch (gBattlerBattleController[battlerId])
    {
    case BATTLE_CONTROLLER_OPPONENT:
    case BATTLE_CONTROLLER_PLAYER_PARTNER:
    case BATTLE_CONTROLLER_SAFARI:
    case BATTLE_CONTROLLER_WALLY:
        return TRUE;
    default:
        break;
    }

    if (IsAiVsAiBattle())
        return TRUE;

    return FALSE;
}

void HandleLinkBattleSetup(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if (gWirelessCommType)
            SetWirelessCommType1();
        if (!gReceivedRemoteLinkPlayers)
            OpenLink();
        CreateTask(Task_WaitForLinkPlayerConnection, 0);
        CreateTasksForSendRecvLinkBuffers();
    }
}

void SetUpBattleVarsAndBirchZigzagoon(void)
{
    s32 i;

    gBattleMainFunc = BeginBattleIntroDummy;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattlerControllerFuncs[i] = BattleControllerDummy;
        gBattlerPositions[i] = B_POSITION_ABSENT;
        gActionSelectionCursor[i] = 0;
        gMoveSelectionCursor[i] = 0;
    }

    HandleLinkBattleSetup();
    gBattleControllerExecFlags = 0;
    ClearBattleAnimationVars();
    BattleAI_SetupItems();
    BattleAI_SetupFlags();

    if (!IS_FRLG && gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        CreateWildMon(SPECIES_ZIGZAGOON, 2);
}

void InitBattleControllers(void)
{
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        RecordedBattle_Init(B_RECORD_MODE_RECORDING);
    else
        RecordedBattle_Init(B_RECORD_MODE_PLAYBACK);

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        RecordedBattle_SaveParties();

    InitBtlControllersInternal();

    SetBattlePartyIds();

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            BufferBattlePartyCurrentOrderBySide(battler, 0);
    }

    for (i = 0; i < sizeof(gBattleStruct->tvMovePoints); i++)
        *((u8 *)(&gBattleStruct->tvMovePoints) + i) = 0;

    for (i = 0; i < sizeof(gBattleStruct->tv); i++)
        *((u8 *)(&gBattleStruct->tv) + i) = 0;
}

static void InitBtlControllersInternal(void)
{
    s32 i;
    bool32 isLink = (gBattleTypeFlags & BATTLE_TYPE_LINK);
    bool32 isDouble = IsDoubleBattle();
    bool32 isMaster = (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER);
    bool32 isRecorded = (gBattleTypeFlags & BATTLE_TYPE_RECORDED);
    bool32 isRecordedMaster = (gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER);
    bool32 isRecordedLink = (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK);
    bool32 isMulti = (gBattleTypeFlags & BATTLE_TYPE_MULTI);
    bool32 isInGamePartner = (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER);
    bool32 isAIvsAI = IsAiVsAiBattle();

    if (!isLink || isMaster)
        gBattleMainFunc = BeginBattleIntro;

    if (!isDouble)
        gBattlersCount = 2;
    else
        gBattlersCount = MAX_BATTLERS_COUNT;

    if ((gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
        || !isMulti
        || (TESTING && isMulti)
        || (!isLink && !isRecorded)
        || (isLink && !isDouble))
    {
        bool32 isPlayerPrimary;
        if (isLink)
            isPlayerPrimary = (isMaster || (isDouble && isMulti));
        else if (!isRecorded)
            isPlayerPrimary = TRUE;
        else if (isDouble)
            isPlayerPrimary = (isInGamePartner || isMulti || isMaster);
        else
            isPlayerPrimary = (!isRecordedLink || isRecordedMaster);

        gBattlerPositions[B_BATTLER_0] = isPlayerPrimary ? B_POSITION_PLAYER_LEFT : B_POSITION_OPPONENT_LEFT;
        gBattlerPositions[B_BATTLER_1] = isPlayerPrimary ? B_POSITION_OPPONENT_LEFT : B_POSITION_PLAYER_LEFT;
        if (isDouble)
        {
            gBattlerPositions[B_BATTLER_2] = isPlayerPrimary ? B_POSITION_PLAYER_RIGHT : B_POSITION_OPPONENT_RIGHT;
            gBattlerPositions[B_BATTLER_3] = isPlayerPrimary ? B_POSITION_OPPONENT_RIGHT : B_POSITION_PLAYER_RIGHT;
        }

        if (isLink)
        {
            if (isDouble && isMulti && !isMaster)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = SetControllerToLinkPartner;
            else
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = SetControllerToPlayer;

            if (!isDouble || !isMulti || !isMaster)
            {
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_1)] = SetControllerToLinkOpponent;
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToPlayer;
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_3)] = SetControllerToLinkOpponent;
            }
            else
            {
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_1)] = SetControllerToOpponent;
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToLinkPartner;
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_3)] = SetControllerToOpponent;
            }

            // Set gBattlerBattleController early for link multis so GetBattlerTrainer can use it
            if (isDouble && isMulti)
            {
                for (enum BattlerId i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (gBattlerControllerFuncs[i] == SetControllerToPlayer)
                        gBattlerBattleController[i] = BATTLE_CONTROLLER_PLAYER;
                    else if (gBattlerControllerFuncs[i] == SetControllerToLinkPartner)
                        gBattlerBattleController[i] = BATTLE_CONTROLLER_LINK_PARTNER;
                    else if (gBattlerControllerFuncs[i] == SetControllerToLinkOpponent)
                        gBattlerBattleController[i] = BATTLE_CONTROLLER_LINK_OPPONENT;
                    else if (gBattlerControllerFuncs[i] == SetControllerToOpponent)
                        gBattlerBattleController[i] = BATTLE_CONTROLLER_OPPONENT;
                }
            }
        }
        else
        {
            // Player 1
            if (isRecorded)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = SetControllerToRecordedPlayer;
            else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = SetControllerToSafari;
            else if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = IS_FRLG ? SetControllerToOakOrOldMan : SetControllerToWally;
            else if (IS_FRLG && (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE))
                gBattlerControllerFuncs[gBattlerPositions[B_BATTLER_0]] = SetControllerToOakOrOldMan;
            else if (isAIvsAI)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = SetControllerToPlayerPartner;
            else
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] = SetControllerToPlayer;

            // Opponent 1
            bool32 isOpponent1Recorded;
            if (isDouble)
                isOpponent1Recorded = ((!isInGamePartner && isRecorded && !isMulti && isRecordedLink) || (TESTING && isMulti && isRecordedLink));
            else
                isOpponent1Recorded = isRecorded && isRecordedLink;

            if (isOpponent1Recorded)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_1)] = SetControllerToRecordedOpponent;
            else
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_1)] = SetControllerToOpponent;

            // Player 2
            if (TESTING && isMulti && isRecordedLink)
            {
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToRecordedPartner;
            }
            else if (TESTING && isMulti && isRecorded && !isRecordedLink)
            { // Sets to PlayerPartner if EXPECT_XXXX used in test for partner trainer, else sets to RecordedPartner.
#if TESTING
                if (gBattleTestRunnerState->data.expectedAiActions[B_BATTLER_2][0].actionSet == TRUE)
                    gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToPlayerPartner;
                else
#endif
                    gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToRecordedPartner;
            }
            else if ((isInGamePartner && !isRecorded)
                    || isAIvsAI)
            {
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToPlayerPartner;
            }
            else if (isRecorded)
            {
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToRecordedPlayer;
            }
            else
            {
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] = SetControllerToPlayer;
            }

            // Opponent 2
            if (TESTING && isMulti && isRecordedLink)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_3)] = SetControllerToRecordedOpponent;
            else if (isInGamePartner || !isRecorded || isMulti || !isRecordedLink)
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_3)] = SetControllerToOpponent;
            else
                gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_3)] = SetControllerToRecordedOpponent;
        }

        bool32 bufferPartyOrders;

        if (!isLink)
            bufferPartyOrders = (isInGamePartner || (isRecorded && isMulti));
        else
            bufferPartyOrders = (isDouble && isMulti);

        if (bufferPartyOrders)
        {
            BufferBattlePartyCurrentOrderBySide(0, 0);
            BufferBattlePartyCurrentOrderBySide(1, 0);
            BufferBattlePartyCurrentOrderBySide(2, 1);
            BufferBattlePartyCurrentOrderBySide(3, 1);

            gBattlerPartyIndexes[0] = 0;
            gBattlerPartyIndexes[1] = 0;
            gBattlerPartyIndexes[2] = BattleSideHasTwoTrainers(B_SIDE_PLAYER) ? 0 : 1;
            gBattlerPartyIndexes[3] = BattleSideHasTwoTrainers(B_SIDE_OPPONENT) ? 0 : 1;
        }
    }
    else
    {
        u8 multiplayerId = isLink ? GetMultiplayerId() : gRecordedBattleMultiplayerId;

        for (i = 0; i < MAX_LINK_PLAYERS; i++)
        {
            enum BattlerPosition linkPositionLeft, linkPositionRight;
            BattleControllerFunc linkBtlControllerFunc;

            if (i == multiplayerId)
            {
                linkPositionLeft = B_POSITION_PLAYER_LEFT;
                linkPositionRight = B_POSITION_PLAYER_RIGHT;
                linkBtlControllerFunc = isLink ? SetControllerToPlayer : SetControllerToRecordedPlayer;
            }
            else if ((!(gLinkPlayers[i].id & 1) && !(gLinkPlayers[multiplayerId].id & 1))
                || ((gLinkPlayers[i].id & 1) && (gLinkPlayers[multiplayerId].id & 1)))
            {
                linkPositionLeft = B_POSITION_PLAYER_LEFT;
                linkPositionRight = B_POSITION_PLAYER_RIGHT;
                linkBtlControllerFunc = isLink ? SetControllerToLinkPartner : SetControllerToRecordedPlayer;
            }
            else
            {
                linkPositionLeft = B_POSITION_OPPONENT_LEFT;
                linkPositionRight = B_POSITION_OPPONENT_RIGHT;
                linkBtlControllerFunc = isLink ? SetControllerToLinkOpponent : SetControllerToRecordedOpponent;
            }
            // Set early to set gBattlerBattleController for GetBattlerTrainer
            linkBtlControllerFunc(gLinkPlayers[i].id);

            gBattlerPositions[gLinkPlayers[i].id] = gLinkPlayers[i].id & BIT_FLANK ? linkPositionRight : linkPositionLeft;
            BufferBattlePartyCurrentOrderBySide(gLinkPlayers[i].id, gLinkPlayers[i].id & BIT_FLANK);
            gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
        }
    }
}

bool32 IsValidForBattle(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    return (species != SPECIES_NONE
         && species != SPECIES_EGG
         && GetMonData(mon, MON_DATA_HP) != 0
         && GetMonData(mon, MON_DATA_IS_EGG) == FALSE);
}

bool32 IsValidForBattleButDead(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    return (species != SPECIES_NONE
         && species != SPECIES_EGG
         && GetMonData(mon, MON_DATA_IS_EGG) == FALSE);
}

static inline bool32 IsControllerPlayer(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == PlayerBufferExecCompleted);
}

static inline bool32 IsControllerRecordedPlayer(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == RecordedPlayerBufferExecCompleted);
}

static inline bool32 IsControllerRecordedPartner(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == RecordedPartnerBufferExecCompleted);
}

static inline bool32 IsControllerOpponent(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == OpponentBufferExecCompleted);
}

static inline bool32 IsControllerPlayerPartner(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == PlayerPartnerBufferExecCompleted);
}

static inline bool32 IsControllerWally(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == WallyBufferExecCompleted);
}

static inline bool32 IsControllerOakOldMan(u32 battler)
{
    return (gBattlerControllerEndFuncs[battler] == OakOldManBufferExecCompleted);
}

static inline bool32 IsControllerRecordedOpponent(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == RecordedOpponentBufferExecCompleted);
}

static inline bool32 IsControllerLinkOpponent(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == LinkOpponentBufferExecCompleted);
}

static inline bool32 IsControllerLinkPartner(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == LinkPartnerBufferExecCompleted);
}

static inline bool32 IsControllerSafari(enum BattlerId battler)
{
    return (gBattlerControllerEndFuncs[battler] == SafariBufferExecCompleted);
}

bool32 ShouldUpdateTvData(enum BattlerId battler)
{
    return (IsControllerPlayer(battler)
         || IsControllerLinkPartner(battler)
         || IsControllerLinkOpponent(battler));
}

static void SetBattlePartyIds(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (enum BattlerId i = 0; i < gBattlersCount; i++)
        {
            for (u32 j = 0; j < PARTY_SIZE; j++)
            {
                if (i < 2)
                {
                    if (IsValidForBattle(&GetBattlerParty(i)[j]))
                    {
                        gBattlerPartyIndexes[i] = j;
                        break;
                    }
                }
                else
                {
                    if (gBattlerPartyIndexes[i - 2] == j && BattlersShareParty(i - 2, i))
                    {
                        // Exclude already assigned Pokémon;
                    }
                    else if (IsValidForBattle(&GetBattlerParty(i)[j]))
                    {
                        gBattlerPartyIndexes[i] = j;
                        break;
                    }
                    else if (IsValidForBattleButDead(&GetBattlerParty(i)[j]) && gBattlerPartyIndexes[i] < PARTY_SIZE)
                    {
                        // Put an "option" on a dead mon that can be revived;
                        gBattlerPartyIndexes[i] = j + PARTY_SIZE;
                    }

                    if (gBattlerPartyIndexes[i] >= PARTY_SIZE)
                        continue;
                    // No valid mons were found. Add the empty slot.
                    if (gBattlerPartyIndexes[i - 2] == 0)
                        gBattlerPartyIndexes[i] = 1;
                    else
                        gBattlerPartyIndexes[i] = 0;
                }
            }
            if (gBattlerPartyIndexes[i] >= PARTY_SIZE)
                gBattlerPartyIndexes[i] -= PARTY_SIZE;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            gBattlerPartyIndexes[1] = 0, gBattlerPartyIndexes[3] = 0;
    }
}

static void PrepareBufferDataTransfer(enum BattlerId battler, u32 bufferId, u8 *data, u16 size)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        PrepareBufferDataTransferLink(battler, bufferId, size, data);
    }
    else
    {
        switch (bufferId)
        {
        case B_COMM_TO_CONTROLLER:
            for (i = 0; i < size; data++, i++)
                gBattleResources->bufferA[battler][i] = *data;
            break;
        case B_COMM_TO_ENGINE:
            for (i = 0; i < size; data++, i++)
                gBattleResources->bufferB[battler][i] = *data;
            break;
        }
    }
}

#define tInitialDelayTimer      data[10]
#define tState                  data[11]
#define tCurrentBlock_WrapFrom  data[12]
#define tBlockSendDelayTimer    data[13]
#define tCurrentBlock_End       data[14]
#define tCurrentBlock_Start     data[15]
//
// Inbound communications are stored in one buffer; outbound communications
// in another. Both buffers work pretty similarly: the next message will be
// written into the buffer after the previous message (with 4-byte alignment),
// unless we're too close to the end of the buffer, in which case we jump back
// to the start.
//
// Regarding the task variable names above: these variables are altered in-
// place, so the precise operational definition of "current" depends on when
// the variables are being accessed. When data is present in the send and
// receive buffers, "current" refers to the most recently received message;
// but when a message is actually being placed in the buffers, "current"
// refers to the previous message, until such time that we finish updating it
// to refer to the new message.

static void CreateTasksForSendRecvLinkBuffers(void)
{
    sLinkSendTaskId = CreateTask(Task_HandleSendLinkBuffersData, 0);
    gTasks[sLinkSendTaskId].tState                 = 0;
    gTasks[sLinkSendTaskId].tCurrentBlock_WrapFrom = 0;
    gTasks[sLinkSendTaskId].tBlockSendDelayTimer   = 0;
    gTasks[sLinkSendTaskId].tCurrentBlock_End      = 0;
    gTasks[sLinkSendTaskId].tCurrentBlock_Start    = 0;

    sLinkReceiveTaskId = CreateTask(Task_HandleCopyReceivedLinkBuffersData, 0);
    gTasks[sLinkReceiveTaskId].tCurrentBlock_WrapFrom = 0;
    gTasks[sLinkReceiveTaskId].tBlockSendDelayTimer   = 0; // not used by "receive" task
    gTasks[sLinkReceiveTaskId].tCurrentBlock_End      = 0;
    gTasks[sLinkReceiveTaskId].tCurrentBlock_Start    = 0;
}

enum
{
    LINK_BUFF_BUFFER_ID,
    LINK_BUFF_ACTIVE_BATTLER,
    LINK_BUFF_ATTACKER,
    LINK_BUFF_TARGET,
    LINK_BUFF_SIZE_LO,
    LINK_BUFF_SIZE_HI,
    LINK_BUFF_ABSENT_BATTLER_FLAGS,
    LINK_BUFF_EFFECT_BATTLER,
    LINK_BUFF_DATA,
};

// We want to send a message. Place it into the "send" buffer.
// First argument is a BATTLELINKCOMMTYPE_
void PrepareBufferDataTransferLink(enum BattlerId battler, u32 bufferId, u16 size, u8 *data)
{
    s32 alignedSize;
    s32 i;

    alignedSize = size - size % 4 + 4;
    if (gTasks[sLinkSendTaskId].tCurrentBlock_End + alignedSize + LINK_BUFF_DATA + 1 > BATTLE_BUFFER_LINK_SIZE)
    {
        gTasks[sLinkSendTaskId].tCurrentBlock_WrapFrom = gTasks[sLinkSendTaskId].tCurrentBlock_End;
        gTasks[sLinkSendTaskId].tCurrentBlock_End      = 0;
    }

    #define BYTE_TO_SEND(offset) \
        gLinkBattleSendBuffer[gTasks[sLinkSendTaskId].tCurrentBlock_End + offset]

    BYTE_TO_SEND(LINK_BUFF_BUFFER_ID)            = bufferId;
    BYTE_TO_SEND(LINK_BUFF_ACTIVE_BATTLER)       = battler;
    BYTE_TO_SEND(LINK_BUFF_ATTACKER)             = gBattlerAttacker;
    BYTE_TO_SEND(LINK_BUFF_TARGET)               = gBattlerTarget;
    BYTE_TO_SEND(LINK_BUFF_SIZE_LO)              = alignedSize;
    BYTE_TO_SEND(LINK_BUFF_SIZE_HI)              = (alignedSize & 0x0000FF00) >> 8;
    BYTE_TO_SEND(LINK_BUFF_ABSENT_BATTLER_FLAGS) = gAbsentBattlerFlags;
    BYTE_TO_SEND(LINK_BUFF_EFFECT_BATTLER)       = gEffectBattler;

    for (i = 0; i < size; i++)
        BYTE_TO_SEND(LINK_BUFF_DATA + i) = data[i];

    #undef BYTE_TO_SEND

    gTasks[sLinkSendTaskId].tCurrentBlock_End = gTasks[sLinkSendTaskId].tCurrentBlock_End + alignedSize + LINK_BUFF_DATA;
}

enum {
   SENDTASK_STATE_INITIALIZE        = 0,
   SENDTASK_STATE_INITIAL_DELAY     = 1,
   SENDTASK_STATE_COUNT_PLAYERS     = 2,
   SENDTASK_STATE_BEGIN_SEND_BLOCK  = 3,
   SENDTASK_STATE_FINISH_SEND_BLOCK = 4,
   SENDTASK_STATE_UNUSED_STATE      = 5,
};

static void Task_HandleSendLinkBuffersData(u8 taskId)
{
    u16 numPlayers;
    u16 blockSize;

    #define BYTE_TO_SEND(offset) \
        gLinkBattleSendBuffer[gTasks[taskId].tCurrentBlock_Start + offset]

    switch (gTasks[taskId].tState)
    {
    case SENDTASK_STATE_INITIALIZE:
        gTasks[taskId].tInitialDelayTimer = 100;
        gTasks[taskId].tState++;
        break;
    case SENDTASK_STATE_INITIAL_DELAY:
        gTasks[taskId].tInitialDelayTimer--;
        if (gTasks[taskId].tInitialDelayTimer == 0)
            gTasks[taskId].tState++;
        break;
    case SENDTASK_STATE_COUNT_PLAYERS:
        if (gWirelessCommType)
        {
            gTasks[taskId].tState++;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = (gBattleTypeFlags & BATTLE_TYPE_MULTI) ? 4 : 2;

            if (GetLinkPlayerCount_2() >= numPlayers)
            {
                if (IsLinkMaster())
                {
                    CheckShouldAdvanceLinkState();
                    gTasks[taskId].tState++;
                }
                else
                {
                    gTasks[taskId].tState++;
                }
            }
        }
        break;
    case SENDTASK_STATE_BEGIN_SEND_BLOCK:
        if (gTasks[taskId].tCurrentBlock_Start != gTasks[taskId].tCurrentBlock_End)
        {
            if (gTasks[taskId].tBlockSendDelayTimer == 0)
            {
                if (gTasks[taskId].tCurrentBlock_Start >  gTasks[taskId].tCurrentBlock_End
                 && gTasks[taskId].tCurrentBlock_Start == gTasks[taskId].tCurrentBlock_WrapFrom)
                {
                    gTasks[taskId].tCurrentBlock_WrapFrom = 0;
                    gTasks[taskId].tCurrentBlock_Start    = 0;
                }
                blockSize = (BYTE_TO_SEND(LINK_BUFF_SIZE_LO) | (BYTE_TO_SEND(LINK_BUFF_SIZE_HI) << 8)) + LINK_BUFF_DATA;
                SendBlock(BitmaskAllOtherLinkPlayers(), &BYTE_TO_SEND(0), blockSize);
                gTasks[taskId].tState++;
            }
            else
            {
                gTasks[taskId].tBlockSendDelayTimer--;
                break;
            }
        }
        break;
    case SENDTASK_STATE_FINISH_SEND_BLOCK:
        if (IsLinkTaskFinished())
        {
            blockSize = BYTE_TO_SEND(LINK_BUFF_SIZE_LO) | (BYTE_TO_SEND(LINK_BUFF_SIZE_HI) << 8);
            gTasks[taskId].tBlockSendDelayTimer = 1;
            gTasks[taskId].tCurrentBlock_Start  = gTasks[taskId].tCurrentBlock_Start + blockSize + LINK_BUFF_DATA;
            gTasks[taskId].tState = SENDTASK_STATE_BEGIN_SEND_BLOCK;
        }
        break;
    case SENDTASK_STATE_UNUSED_STATE:
        if (--gTasks[taskId].tBlockSendDelayTimer == 0)
        {
            gTasks[taskId].tBlockSendDelayTimer = 1;
            gTasks[taskId].tState = SENDTASK_STATE_BEGIN_SEND_BLOCK;
        }
        break;
    }

    #undef BYTE_TO_SEND
}

// We have received a message. Place it into the "receive" buffer.
//
// Counterintuitively, we also "receive" the outbound messages that
// we send to other players. The GBA basically stores communicated
// data for all four players, so inbound and outbound data can be
// handled uniformly unless a game specifically decides to do
// otherwise. Pokemon, evidently, did not specifically decide to do
// otherwise.
void TryReceiveLinkBattleData(void)
{
    u8 i;
    s32 j;
    u8 *recvBuffer;

    if (gReceivedRemoteLinkPlayers && (gBattleTypeFlags & BATTLE_TYPE_LINK_IN_BATTLE))
    {
        DestroyTask_RfuIdle();
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (GetBlockReceivedStatus() & (1 << (i)))
            {
                ResetBlockReceivedFlag(i);
                recvBuffer = (u8 *)gBlockRecvBuffer[i];
                {
                    u8 *dest, *src;
                    u16 dataSize = gBlockRecvBuffer[i][2];

                    if (gTasks[sLinkReceiveTaskId].tCurrentBlock_End + 9 + dataSize > 0x1000)
                    {
                        gTasks[sLinkReceiveTaskId].tCurrentBlock_WrapFrom = gTasks[sLinkReceiveTaskId].tCurrentBlock_End;
                        gTasks[sLinkReceiveTaskId].tCurrentBlock_End = 0;
                    }

                    dest = &gLinkBattleRecvBuffer[gTasks[sLinkReceiveTaskId].tCurrentBlock_End];
                    src = recvBuffer;

                    for (j = 0; j < dataSize + 8; j++)
                        dest[j] = src[j];

                    gTasks[sLinkReceiveTaskId].tCurrentBlock_End = gTasks[sLinkReceiveTaskId].tCurrentBlock_End + dataSize + 8;
                }
            }
        }
    }
}

static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId)
{
    u16 blockSize;
    enum BattlerId battler;
    u8 playerId;

    #define BYTE_TO_RECEIVE(offset) \
        gLinkBattleRecvBuffer[gTasks[taskId].tCurrentBlock_Start + offset]

    if (gTasks[taskId].tCurrentBlock_Start != gTasks[taskId].tCurrentBlock_End)
    {
        if (gTasks[taskId].tCurrentBlock_Start >  gTasks[taskId].tCurrentBlock_End
         && gTasks[taskId].tCurrentBlock_Start == gTasks[taskId].tCurrentBlock_WrapFrom)
        {
            gTasks[taskId].tCurrentBlock_WrapFrom = 0;
            gTasks[taskId].tCurrentBlock_Start    = 0;
        }
        battler = BYTE_TO_RECEIVE(LINK_BUFF_ACTIVE_BATTLER);
        blockSize = BYTE_TO_RECEIVE(LINK_BUFF_SIZE_LO) | (BYTE_TO_RECEIVE(LINK_BUFF_SIZE_HI) << 8);

        switch (BYTE_TO_RECEIVE(0))
        {
        case B_COMM_TO_CONTROLLER:
            if (IsBattleControllerActiveOnLocal(battler))
                return;

            memcpy(gBattleResources->bufferA[battler], &BYTE_TO_RECEIVE(LINK_BUFF_DATA), blockSize);
            MarkBattlerReceivedLinkData(battler);

            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
            {
                gBattlerAttacker    = BYTE_TO_RECEIVE(LINK_BUFF_ATTACKER);
                gBattlerTarget      = BYTE_TO_RECEIVE(LINK_BUFF_TARGET);
                gAbsentBattlerFlags = BYTE_TO_RECEIVE(LINK_BUFF_ABSENT_BATTLER_FLAGS);
                gEffectBattler      = BYTE_TO_RECEIVE(LINK_BUFF_EFFECT_BATTLER);
            }
            break;
        case B_COMM_TO_ENGINE:
            memcpy(gBattleResources->bufferB[battler], &gLinkBattleRecvBuffer[gTasks[taskId].tCurrentBlock_Start + LINK_BUFF_DATA], blockSize);
            break;
        case B_COMM_CONTROLLER_IS_DONE:
            playerId = BYTE_TO_RECEIVE(LINK_BUFF_DATA);
            MarkBattleControllerIdleForPlayer(battler, playerId);
            break;
        }

        gTasks[taskId].tCurrentBlock_Start = gTasks[taskId].tCurrentBlock_Start + blockSize + LINK_BUFF_DATA;
    }

    #undef BYTE_TO_RECEIVE
}

#undef tInitialDelayTimer
#undef tState
#undef tCurrentBlock_WrapFrom
#undef tBlockSendDelayTimer
#undef tCurrentBlock_End
#undef tCurrentBlock_Start

void BtlController_EmitGetMonData(enum BattlerId battler, u32 bufferId, u8 requestId, u8 monToCheck)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_GETMONDATA;
    gBattleResources->transferBuffer[1] = requestId;
    gBattleResources->transferBuffer[2] = monToCheck;
    gBattleResources->transferBuffer[3] = 0;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

static void UNUSED BtlController_EmitGetRawMonData(enum BattlerId battler, u32 bufferId, u8 monId, u8 bytes)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_GETRAWMONDATA;
    gBattleResources->transferBuffer[1] = monId;
    gBattleResources->transferBuffer[2] = bytes;
    gBattleResources->transferBuffer[3] = 0;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitSetMonData(enum BattlerId battler, u32 bufferId, u8 requestId, u8 monToCheck, u8 bytes, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_SETMONDATA;
    gBattleResources->transferBuffer[1] = requestId;
    gBattleResources->transferBuffer[2] = monToCheck;
    for (i = 0; i < bytes; i++)
        gBattleResources->transferBuffer[3 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 3 + bytes);
}

static void UNUSED BtlController_EmitSetRawMonData(enum BattlerId battler, u32 bufferId, u8 monId, u8 bytes, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_SETRAWMONDATA;
    gBattleResources->transferBuffer[1] = monId;
    gBattleResources->transferBuffer[2] = bytes;
    for (i = 0; i < bytes; i++)
        gBattleResources->transferBuffer[3 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, bytes + 3);
}

void BtlController_EmitLoadMonSprite(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_LOADMONSPRITE;
    gBattleResources->transferBuffer[1] = CONTROLLER_LOADMONSPRITE;
    gBattleResources->transferBuffer[2] = CONTROLLER_LOADMONSPRITE;
    gBattleResources->transferBuffer[3] = CONTROLLER_LOADMONSPRITE;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitSwitchInAnim(enum BattlerId battler, u32 bufferId, u8 partyId, bool8 dontClearTransform, bool8 dontClearSubstituteBit)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_SWITCHINANIM;
    gBattleResources->transferBuffer[1] = partyId;
    gBattleResources->transferBuffer[2] = dontClearTransform;
    gBattleResources->transferBuffer[3] = dontClearSubstituteBit;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitReturnMonToBall(enum BattlerId battler, u32 bufferId, bool8 skipAnim)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_RETURNMONTOBALL;
    gBattleResources->transferBuffer[1] = skipAnim;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 2);
}

void BtlController_EmitDrawTrainerPic(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_DRAWTRAINERPIC;
    gBattleResources->transferBuffer[1] = CONTROLLER_DRAWTRAINERPIC;
    gBattleResources->transferBuffer[2] = CONTROLLER_DRAWTRAINERPIC;
    gBattleResources->transferBuffer[3] = CONTROLLER_DRAWTRAINERPIC;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitTrainerSlide(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_TRAINERSLIDE;
    gBattleResources->transferBuffer[1] = CONTROLLER_TRAINERSLIDE;
    gBattleResources->transferBuffer[2] = CONTROLLER_TRAINERSLIDE;
    gBattleResources->transferBuffer[3] = CONTROLLER_TRAINERSLIDE;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitTrainerSlideBack(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_TRAINERSLIDEBACK;
    gBattleResources->transferBuffer[1] = CONTROLLER_TRAINERSLIDEBACK;
    gBattleResources->transferBuffer[2] = CONTROLLER_TRAINERSLIDEBACK;
    gBattleResources->transferBuffer[3] = CONTROLLER_TRAINERSLIDEBACK;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitFaintAnimation(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_FAINTANIMATION;
    gBattleResources->transferBuffer[1] = CONTROLLER_FAINTANIMATION;
    gBattleResources->transferBuffer[2] = CONTROLLER_FAINTANIMATION;
    gBattleResources->transferBuffer[3] = CONTROLLER_FAINTANIMATION;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

static void UNUSED BtlController_EmitPaletteFade(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_PALETTEFADE;
    gBattleResources->transferBuffer[1] = CONTROLLER_PALETTEFADE;
    gBattleResources->transferBuffer[2] = CONTROLLER_PALETTEFADE;
    gBattleResources->transferBuffer[3] = CONTROLLER_PALETTEFADE;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitBallThrowAnim(enum BattlerId battler, u32 bufferId, u8 caseId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_BALLTHROWANIM;
    gBattleResources->transferBuffer[1] = caseId;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 2);
}

static void UNUSED BtlController_EmitPause(enum BattlerId battler, u32 bufferId, u8 toWait, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_PAUSE;
    gBattleResources->transferBuffer[1] = toWait;
    for (i = 0; i < toWait * 3; i++)
        gBattleResources->transferBuffer[2 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, toWait * 3 + 2);
}

void BtlController_EmitMoveAnimation(enum BattlerId battler, u32 bufferId, enum Move move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, u8 multihit)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_MOVEANIMATION;
    gBattleResources->transferBuffer[1] = move;
    gBattleResources->transferBuffer[2] = (move & 0xFF00) >> 8;
    gBattleResources->transferBuffer[3] = turnOfMove;
    gBattleResources->transferBuffer[4] = movePower;
    gBattleResources->transferBuffer[5] = (movePower & 0xFF00) >> 8;
    gBattleResources->transferBuffer[6] = dmg;
    gBattleResources->transferBuffer[7] = (dmg & 0x0000FF00) >> 8;
    gBattleResources->transferBuffer[8] = (dmg & 0x00FF0000) >> 16;
    gBattleResources->transferBuffer[9] = (dmg & 0xFF000000) >> 24;
    gBattleResources->transferBuffer[10] = friendship;
    gBattleResources->transferBuffer[11] = multihit;
    if (HasWeatherEffect())
    {
        gBattleResources->transferBuffer[12] = gBattleWeather;
        gBattleResources->transferBuffer[13] = (gBattleWeather & 0xFF00) >> 8;
    }
    else
    {
        gBattleResources->transferBuffer[12] = 0;
        gBattleResources->transferBuffer[13] = 0;
    }
    gBattleResources->transferBuffer[14] = 0;
    gBattleResources->transferBuffer[15] = 0;

    struct LinkBattleAnim anim = {0};
    anim.isTransformedMonShiny = gBattleMons[battler].volatiles.isTransformedMonShiny;
    anim.transformedMonPID  = gBattleMons[battler].volatiles.transformedMonPID;
    anim.rolloutTimer  = gBattleMons[battler].volatiles.rolloutTimer;
    anim.furyCutterCounter  = gBattleMons[battler].volatiles.furyCutterCounter;
    anim.syrupBombIsShiny = gBattleMons[battler].volatiles.syrupBombIsShiny;
    anim.isTransformedMonShiny = gBattleMons[battler].volatiles.isTransformedMonShiny;
    anim.stockpileCounter = gBattleMons[battler].volatiles.stockpileCounter;
    memcpy(&gBattleResources->transferBuffer[16], &anim, sizeof(struct LinkBattleAnim));

    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 16 + sizeof(struct LinkBattleAnim));
}

void BtlController_EmitPrintString(enum BattlerId battler, u32 bufferId, enum StringID stringID)
{
    s32 i;
    struct BattleMsgData *stringInfo;

    gBattleResources->transferBuffer[0] = CONTROLLER_PRINTSTRING;
    gBattleResources->transferBuffer[1] = gBattleOutcome;
    gBattleResources->transferBuffer[2] = stringID;
    gBattleResources->transferBuffer[3] = (stringID & 0xFF00) >> 8;

    stringInfo = (struct BattleMsgData *)(&gBattleResources->transferBuffer[4]);
    stringInfo->currentMove = gCurrentMove;
    stringInfo->originallyUsedMove = gChosenMove;
    stringInfo->lastItem = gLastUsedItem;
    stringInfo->lastAbility = gLastUsedAbility;
    stringInfo->scrActive = gBattleScripting.battler;
    stringInfo->bakScriptPartyIdx = gBattleStruct->scriptPartyIdx;
    stringInfo->hpScale = gBattleStruct->hpScale;
    stringInfo->itemEffectBattler = gPotentialItemEffectBattler;
    stringInfo->moveType = GetMoveType(gCurrentMove);

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        stringInfo->abilities[i] = gBattleMons[i].ability;
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        stringInfo->textBuffs[0][i] = gBattleTextBuff1[i];
        stringInfo->textBuffs[1][i] = gBattleTextBuff2[i];
        stringInfo->textBuffs[2][i] = gBattleTextBuff3[i];
    }
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, sizeof(struct BattleMsgData) + 4);
}

void BtlController_EmitPrintSelectionString(enum BattlerId battler, u32 bufferId, enum StringID stringID)
{
    s32 i;
    struct BattleMsgData *stringInfo;

    gBattleResources->transferBuffer[0] = CONTROLLER_PRINTSTRINGPLAYERONLY;
    gBattleResources->transferBuffer[1] = CONTROLLER_PRINTSTRINGPLAYERONLY;
    gBattleResources->transferBuffer[2] = stringID;
    gBattleResources->transferBuffer[3] = (stringID & 0xFF00) >> 8;

    stringInfo = (struct BattleMsgData *)(&gBattleResources->transferBuffer[4]);
    stringInfo->currentMove = gCurrentMove;
    stringInfo->originallyUsedMove = gChosenMove;
    stringInfo->lastItem = gLastUsedItem;
    stringInfo->lastAbility = gLastUsedAbility;
    stringInfo->scrActive = gBattleScripting.battler;
    stringInfo->bakScriptPartyIdx = gBattleStruct->scriptPartyIdx;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        stringInfo->abilities[i] = gBattleMons[i].ability;
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        stringInfo->textBuffs[0][i] = gBattleTextBuff1[i];
        stringInfo->textBuffs[1][i] = gBattleTextBuff2[i];
        stringInfo->textBuffs[2][i] = gBattleTextBuff3[i];
    }
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, sizeof(struct BattleMsgData) + 4);
}

// itemId only relevant for B_ACTION_USE_ITEM
void BtlController_EmitChooseAction(enum BattlerId battler, u32 bufferId, u8 action, enum Item itemId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_CHOOSEACTION;
    gBattleResources->transferBuffer[1] = action;
    gBattleResources->transferBuffer[2] = itemId;
    gBattleResources->transferBuffer[3] = (itemId & 0xFF00) >> 8;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

// Only used by the forfeit prompt in the Battle Frontier
// For other Yes/No boxes in battle, see Cmd_yesnobox
void BtlController_EmitYesNoBox(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_YESNOBOX;
    gBattleResources->transferBuffer[1] = CONTROLLER_YESNOBOX;
    gBattleResources->transferBuffer[2] = CONTROLLER_YESNOBOX;
    gBattleResources->transferBuffer[3] = CONTROLLER_YESNOBOX;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitChooseMove(enum BattlerId battler, u32 bufferId, bool8 isDoubleBattle, bool8 noPPNumber, struct ChooseMoveStruct *movePPData)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_CHOOSEMOVE;
    gBattleResources->transferBuffer[1] = isDoubleBattle;
    gBattleResources->transferBuffer[2] = noPPNumber;
    gBattleResources->transferBuffer[3] = 0;
    for (i = 0; i < sizeof(*movePPData); i++)
        gBattleResources->transferBuffer[4 + i] = *((u8 *)(movePPData) + i);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, sizeof(*movePPData) + 4);
}

void BtlController_EmitChooseItem(enum BattlerId battler, u32 bufferId, u8 *battlePartyOrder)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_OPENBAG;
    for (i = 0; i < PARTY_SIZE / 2; i++)
        gBattleResources->transferBuffer[1 + i] = battlePartyOrder[i];
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitChoosePokemon(enum BattlerId battler, u32 bufferId, u8 caseId, u8 slotId, enum Ability abilityId, enum BattlerId battlerPreventingSwitchout, u8 *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_CHOOSEPOKEMON;
    gBattleResources->transferBuffer[1] = caseId;
    gBattleResources->transferBuffer[2] = slotId;
    gBattleResources->transferBuffer[3] = abilityId & 0xFF;
    gBattleResources->transferBuffer[7] = (abilityId >> 8) & 0xFF;
    gBattleResources->transferBuffer[8] = battlerPreventingSwitchout;
    for (i = 0; i < 3; i++)
        gBattleResources->transferBuffer[4 + i] = data[i];
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 9);  // Only 7 bytes were written.
}

static void UNUSED BtlController_EmitCmd23(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_23;
    gBattleResources->transferBuffer[1] = CONTROLLER_23;
    gBattleResources->transferBuffer[2] = CONTROLLER_23;
    gBattleResources->transferBuffer[3] = CONTROLLER_23;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

// why is the argument u16 if it's being cast to s16 anyway?
void BtlController_EmitHealthBarUpdate(enum BattlerId battler, u32 bufferId, u16 hpValue)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_HEALTHBARUPDATE;
    gBattleResources->transferBuffer[1] = 0;
    gBattleResources->transferBuffer[2] = (s16)hpValue;
    gBattleResources->transferBuffer[3] = ((s16)hpValue & 0xFF00) >> 8;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitExpUpdate(enum BattlerId battler, u32 bufferId, u8 partyId, s32 expPoints)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_EXPUPDATE;
    gBattleResources->transferBuffer[1] = partyId;
    gBattleResources->transferBuffer[2] = expPoints;
    gBattleResources->transferBuffer[3] = (expPoints & 0x0000FF00) >> 8;
    gBattleResources->transferBuffer[4] = (expPoints & 0x00FF0000) >> 16;
    gBattleResources->transferBuffer[5] = (expPoints & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 6);
}

void BtlController_EmitStatusIconUpdate(enum BattlerId battler, u32 bufferId, u32 status)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_STATUSICONUPDATE;
    gBattleResources->transferBuffer[1] = status;
    gBattleResources->transferBuffer[2] = (status & 0x0000FF00) >> 8;
    gBattleResources->transferBuffer[3] = (status & 0x00FF0000) >> 16;
    gBattleResources->transferBuffer[4] = (status & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 5);
}

void BtlController_EmitStatusAnimation(enum BattlerId battler, u32 bufferId, bool8 isVolatile, u32 status)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_STATUSANIMATION;
    gBattleResources->transferBuffer[1] = isVolatile;
    gBattleResources->transferBuffer[2] = status;
    gBattleResources->transferBuffer[3] = (status & 0x0000FF00) >> 8;
    gBattleResources->transferBuffer[4] = (status & 0x00FF0000) >> 16;
    gBattleResources->transferBuffer[5] = (status & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 6);
}

static void UNUSED BtlController_EmitStatusXor(enum BattlerId battler, u32 bufferId, u8 b)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_STATUSXOR;
    gBattleResources->transferBuffer[1] = b;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 2);
}

void BtlController_EmitDataTransfer(enum BattlerId battler, u32 bufferId, u16 size, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_DATATRANSFER;
    gBattleResources->transferBuffer[1] = CONTROLLER_DATATRANSFER;
    gBattleResources->transferBuffer[2] = size;
    gBattleResources->transferBuffer[3] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        gBattleResources->transferBuffer[4 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, size + 4);
}

static void UNUSED BtlController_EmitDMA3Transfer(enum BattlerId battler, u32 bufferId, void *dst, u16 size, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_DMA3TRANSFER;
    gBattleResources->transferBuffer[1] = (u32)(dst);
    gBattleResources->transferBuffer[2] = ((u32)(dst) & 0x0000FF00) >> 8;
    gBattleResources->transferBuffer[3] = ((u32)(dst) & 0x00FF0000) >> 16;
    gBattleResources->transferBuffer[4] = ((u32)(dst) & 0xFF000000) >> 24;
    gBattleResources->transferBuffer[5] = size;
    gBattleResources->transferBuffer[6] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        gBattleResources->transferBuffer[7 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, size + 7);
}

static void UNUSED BtlController_EmitPlayBGM(enum BattlerId battler, u32 bufferId, u16 songId, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_PLAYBGM;
    gBattleResources->transferBuffer[1] = songId;
    gBattleResources->transferBuffer[2] = (songId & 0xFF00) >> 8;

    // Nonsense loop using songId as a size
    // Would go out of bounds for any song id after SE_RG_BAG_POCKET (253)
    for (i = 0; i < songId; i++)
        gBattleResources->transferBuffer[3 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, songId + 3);
}

static void UNUSED BtlController_EmitCmd32(enum BattlerId battler, u32 bufferId, u16 size, void *data)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_32;
    gBattleResources->transferBuffer[1] = size;
    gBattleResources->transferBuffer[2] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        gBattleResources->transferBuffer[3 + i] = *(u8 *)(data++);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, size + 3);
}

void BtlController_EmitTwoReturnValues(enum BattlerId battler, u32 bufferId, u8 ret8, u32 ret32)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_TWORETURNVALUES;
    gBattleResources->transferBuffer[1] = ret8;
    gBattleResources->transferBuffer[2] = ret32;
    gBattleResources->transferBuffer[3] = (ret32 & 0x0000FF00) >> 8;
    gBattleResources->transferBuffer[4] = (ret32 & 0x00FF0000) >> 16;
    gBattleResources->transferBuffer[5] = (ret32 & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 6);
}

void BtlController_EmitChosenMonReturnValue(enum BattlerId battler, u32 bufferId, u8 partyId, u8 *battlePartyOrder)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_CHOSENMONRETURNVALUE;
    gBattleResources->transferBuffer[1] = partyId;
    if (battlePartyOrder != NULL)
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
            gBattleResources->transferBuffer[2 + i] = battlePartyOrder[i];
    }
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 5);
}

void BtlController_EmitOneReturnValue(enum BattlerId battler, u32 bufferId, u16 ret)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_ONERETURNVALUE;
    gBattleResources->transferBuffer[1] = ret;
    gBattleResources->transferBuffer[2] = (ret & 0xFF00) >> 8;
    gBattleResources->transferBuffer[3] = 0;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitOneReturnValue_Duplicate(enum BattlerId battler, u32 bufferId, u16 ret)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_ONERETURNVALUE_DUPLICATE;
    gBattleResources->transferBuffer[1] = ret;
    gBattleResources->transferBuffer[2] = (ret & 0xFF00) >> 8;
    gBattleResources->transferBuffer[3] = 0;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitHitAnimation(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_HITANIMATION;
    gBattleResources->transferBuffer[1] = CONTROLLER_HITANIMATION;
    gBattleResources->transferBuffer[2] = CONTROLLER_HITANIMATION;
    gBattleResources->transferBuffer[3] = CONTROLLER_HITANIMATION;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitCantSwitch(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_CANTSWITCH;
    gBattleResources->transferBuffer[1] = CONTROLLER_CANTSWITCH;
    gBattleResources->transferBuffer[2] = CONTROLLER_CANTSWITCH;
    gBattleResources->transferBuffer[3] = CONTROLLER_CANTSWITCH;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitPlaySE(enum BattlerId battler, u32 bufferId, u16 songId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_PLAYSE;
    gBattleResources->transferBuffer[1] = songId;
    gBattleResources->transferBuffer[2] = (songId & 0xFF00) >> 8;
    gBattleResources->transferBuffer[3] = 0;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitPlayFanfareOrBGM(enum BattlerId battler, u32 bufferId, u16 songId, bool8 playBGM)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_PLAYFANFAREORBGM;
    gBattleResources->transferBuffer[1] = songId;
    gBattleResources->transferBuffer[2] = (songId & 0xFF00) >> 8;
    gBattleResources->transferBuffer[3] = playBGM;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitFaintingCry(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_FAINTINGCRY;
    gBattleResources->transferBuffer[1] = CONTROLLER_FAINTINGCRY;
    gBattleResources->transferBuffer[2] = CONTROLLER_FAINTINGCRY;
    gBattleResources->transferBuffer[3] = CONTROLLER_FAINTINGCRY;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitIntroSlide(enum BattlerId battler, u32 bufferId, u8 environmentId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_INTROSLIDE;
    gBattleResources->transferBuffer[1] = environmentId;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 2);
}

void BtlController_EmitIntroTrainerBallThrow(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_INTROTRAINERBALLTHROW;
    gBattleResources->transferBuffer[1] = CONTROLLER_INTROTRAINERBALLTHROW;
    gBattleResources->transferBuffer[2] = CONTROLLER_INTROTRAINERBALLTHROW;
    gBattleResources->transferBuffer[3] = CONTROLLER_INTROTRAINERBALLTHROW;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitDrawPartyStatusSummary(enum BattlerId battler, u32 bufferId, struct HpAndStatus *hpAndStatus, u8 flags)
{
    s32 i;

    gBattleResources->transferBuffer[0] = CONTROLLER_DRAWPARTYSTATUSSUMMARY;
    gBattleResources->transferBuffer[1] = flags & ~PARTY_SUMM_SKIP_DRAW_DELAY; // If true, skip player side
    gBattleResources->transferBuffer[2] = (flags & PARTY_SUMM_SKIP_DRAW_DELAY) >> 7; // If true, skip delay after drawing. True during intro
    gBattleResources->transferBuffer[3] = CONTROLLER_DRAWPARTYSTATUSSUMMARY;
    for (i = 0; i < (s32)(sizeof(struct HpAndStatus) * PARTY_SIZE); i++)
        gBattleResources->transferBuffer[4 + i] = *(i + (u8 *)(hpAndStatus));
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, sizeof(struct HpAndStatus) * PARTY_SIZE + 4);
}

void BtlController_EmitHidePartyStatusSummary(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_HIDEPARTYSTATUSSUMMARY;
    gBattleResources->transferBuffer[1] = CONTROLLER_HIDEPARTYSTATUSSUMMARY;
    gBattleResources->transferBuffer[2] = CONTROLLER_HIDEPARTYSTATUSSUMMARY;
    gBattleResources->transferBuffer[3] = CONTROLLER_HIDEPARTYSTATUSSUMMARY;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitEndBounceEffect(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_ENDBOUNCE;
    gBattleResources->transferBuffer[1] = CONTROLLER_ENDBOUNCE;
    gBattleResources->transferBuffer[2] = CONTROLLER_ENDBOUNCE;
    gBattleResources->transferBuffer[3] = CONTROLLER_ENDBOUNCE;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitSpriteInvisibility(enum BattlerId battler, u32 bufferId, bool8 isInvisible)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_SPRITEINVISIBILITY;
    gBattleResources->transferBuffer[1] = isInvisible;
    gBattleResources->transferBuffer[2] = CONTROLLER_SPRITEINVISIBILITY;
    gBattleResources->transferBuffer[3] = CONTROLLER_SPRITEINVISIBILITY;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4);
}

void BtlController_EmitBattleAnimation(enum BattlerId battler, u32 bufferId, u8 animationId, u16 argument)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_BATTLEANIMATION;
    gBattleResources->transferBuffer[1] = animationId;
    gBattleResources->transferBuffer[2] = argument;
    gBattleResources->transferBuffer[3] = (argument & 0xFF00) >> 8;

    struct LinkBattleAnim anim = {0};
    anim.isTransformedMonShiny = gBattleMons[battler].volatiles.isTransformedMonShiny;
    anim.transformedMonPID  = gBattleMons[battler].volatiles.transformedMonPID;
    anim.rolloutTimer  = gBattleMons[battler].volatiles.rolloutTimer;
    anim.furyCutterCounter  = gBattleMons[battler].volatiles.furyCutterCounter;
    anim.syrupBombIsShiny = gBattleMons[battler].volatiles.syrupBombIsShiny;
    anim.isTransformedMonShiny = gBattleMons[battler].volatiles.isTransformedMonShiny;
    anim.stockpileCounter = gBattleMons[battler].volatiles.stockpileCounter;
    memcpy(&gBattleResources->transferBuffer[4], &anim, sizeof(struct LinkBattleAnim));

    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 4 + sizeof(struct LinkBattleAnim));
}

// mode is a LINK_STANDBY_* constant
void BtlController_EmitLinkStandbyMsg(enum BattlerId battler, u32 bufferId, u8 mode, bool32 record)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_LINKSTANDBYMSG;
    gBattleResources->transferBuffer[1] = mode;

    if (record)
        gBattleResources->transferBuffer[3] = gBattleResources->transferBuffer[2] = RecordedBattle_BufferNewBattlerData(&gBattleResources->transferBuffer[4]);
    else
        gBattleResources->transferBuffer[3] = gBattleResources->transferBuffer[2] = 0;

    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, gBattleResources->transferBuffer[2] + 4);
}

void BtlController_EmitResetActionMoveSelection(enum BattlerId battler, u32 bufferId, u8 caseId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_RESETACTIONMOVESELECTION;
    gBattleResources->transferBuffer[1] = caseId;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 2);
}

void BtlController_EmitEndLinkBattle(enum BattlerId battler, u32 bufferId, u8 battleOutcome)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_ENDLINKBATTLE;
    gBattleResources->transferBuffer[1] = battleOutcome;
    gBattleResources->transferBuffer[2] = gSaveBlock2Ptr->frontier.disableRecordBattle;
    gBattleResources->transferBuffer[3] = gSaveBlock2Ptr->frontier.disableRecordBattle;
    gBattleResources->transferBuffer[5] = gBattleResources->transferBuffer[4] = RecordedBattle_BufferNewBattlerData(&gBattleResources->transferBuffer[6]);
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, gBattleResources->transferBuffer[4] + 6);
}

void BtlController_EmitDebugMenu(enum BattlerId battler, u32 bufferId)
{
    gBattleResources->transferBuffer[0] = CONTROLLER_DEBUGMENU;
    PrepareBufferDataTransfer(battler, bufferId, gBattleResources->transferBuffer, 1);
}

// Standardized Controller functions

// Can be used for all the controllers.
void BtlController_Complete(enum BattlerId battler)
{
    gBattlerControllerEndFuncs[battler](battler);
}

static u32 GetBattlerMonData(enum BattlerId battler, struct Pokemon *party, u32 monId, u8 *dst)
{
    struct BattlePokemon battleMon;
    struct MovePPInfo moveData;
    u8 nickname[POKEMON_NAME_LENGTH * 2];
    u8 *src;
    s16 data16;
    u32 data32;
    s32 size = 0;

    switch (gBattleResources->bufferA[battler][1])
    {
    case REQUEST_ALL_BATTLE:
        battleMon.species = GetMonData(&party[monId], MON_DATA_SPECIES);
        battleMon.item = GetMonData(&party[monId], MON_DATA_HELD_ITEM);
        for (size = 0; size < MAX_MON_MOVES; size++)
        {
            battleMon.moves[size] = GetMonData(&party[monId], MON_DATA_MOVE1 + size);
            battleMon.pp[size] = GetMonData(&party[monId], MON_DATA_PP1 + size);
        }
        battleMon.ppBonuses = GetMonData(&party[monId], MON_DATA_PP_BONUSES);
        battleMon.friendship = GetMonData(&party[monId], MON_DATA_FRIENDSHIP);
        battleMon.experience = GetMonData(&party[monId], MON_DATA_EXP);
        battleMon.hpIV = GetMonData(&party[monId], MON_DATA_HP_IV);
        battleMon.attackIV = GetMonData(&party[monId], MON_DATA_ATK_IV);
        battleMon.defenseIV = GetMonData(&party[monId], MON_DATA_DEF_IV);
        battleMon.speedIV = GetMonData(&party[monId], MON_DATA_SPEED_IV);
        battleMon.spAttackIV = GetMonData(&party[monId], MON_DATA_SPATK_IV);
        battleMon.spDefenseIV = GetMonData(&party[monId], MON_DATA_SPDEF_IV);
        battleMon.personality = GetMonData(&party[monId], MON_DATA_PERSONALITY);
        battleMon.status1 = GetMonData(&party[monId], MON_DATA_STATUS);
        battleMon.level = GetMonData(&party[monId], MON_DATA_LEVEL);
        battleMon.hp = GetMonData(&party[monId], MON_DATA_HP);
        battleMon.maxHP = GetMonData(&party[monId], MON_DATA_MAX_HP);
        battleMon.attack = GetMonData(&party[monId], MON_DATA_ATK);
        battleMon.defense = GetMonData(&party[monId], MON_DATA_DEF);
        battleMon.speed = GetMonData(&party[monId], MON_DATA_SPEED);
        battleMon.spAttack = GetMonData(&party[monId], MON_DATA_SPATK);
        battleMon.spDefense = GetMonData(&party[monId], MON_DATA_SPDEF);
        battleMon.abilityNum = GetMonData(&party[monId], MON_DATA_ABILITY_NUM);
        battleMon.otId = GetMonData(&party[monId], MON_DATA_OT_ID);
        battleMon.metLevel = GetMonData(&party[monId], MON_DATA_MET_LEVEL);
        battleMon.isShiny = GetMonData(&party[monId], MON_DATA_IS_SHINY);
        battleMon.affectionHearts = GetMonAffectionHearts(&party[monId]);
        GetMonData(&party[monId], MON_DATA_NICKNAME, nickname);
        StringCopy_Nickname(battleMon.nickname, nickname);
        GetMonData(&party[monId], MON_DATA_OT_NAME, battleMon.otName);
        src = (u8 *)&battleMon;
        for (size = 0; size < sizeof(battleMon); size++)
            dst[size] = src[size];
        #if TESTING
        if (gTestRunnerEnabled)
        {
            enum BattleTrainer trainer = GetBattlerTrainer(battler);
            u32 partyIndex = gBattlerPartyIndexes[battler];
            if (TestRunner_Battle_GetForcedAbility(trainer, partyIndex))
                gBattleMons[battler].ability = TestRunner_Battle_GetForcedAbility(trainer, partyIndex);
        }
        #endif
        break;
    case REQUEST_SPECIES_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPECIES);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_HELDITEM_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_HELD_ITEM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (size = 0; size < MAX_MON_MOVES; size++)
        {
            moveData.moves[size] = GetMonData(&party[monId], MON_DATA_MOVE1 + size);
            moveData.pp[size] = GetMonData(&party[monId], MON_DATA_PP1 + size);
        }
        moveData.ppBonuses = GetMonData(&party[monId], MON_DATA_PP_BONUSES);
        src = (u8 *)(&moveData);
        for (size = 0; size < sizeof(moveData); size++)
            dst[size] = src[size];
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_MOVE1 + gBattleResources->bufferA[battler][1] - REQUEST_MOVE1_BATTLE);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_PP_DATA_BATTLE:
        for (size = 0; size < MAX_MON_MOVES; size++)
            dst[size] = GetMonData(&party[monId], MON_DATA_PP1 + size);
        dst[size] = GetMonData(&party[monId], MON_DATA_PP_BONUSES);
        size++;
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_PP1 + gBattleResources->bufferA[battler][1] - REQUEST_PPMOVE1_BATTLE);
        size = 1;
        break;
    case REQUEST_OTID_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_OT_ID);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_EXP_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_EXP);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        size = 3;
        break;
    case REQUEST_HP_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_HP_EV);
        size = 1;
        break;
    case REQUEST_ATK_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_ATK_EV);
        size = 1;
        break;
    case REQUEST_DEF_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_DEF_EV);
        size = 1;
        break;
    case REQUEST_SPEED_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPEED_EV);
        size = 1;
        break;
    case REQUEST_SPATK_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPATK_EV);
        size = 1;
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPDEF_EV);
        size = 1;
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_FRIENDSHIP);
        size = 1;
        break;
    case REQUEST_POKERUS_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_POKERUS);
        size = 1;
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_MET_LOCATION);
        size = 1;
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_MET_LEVEL);
        size = 1;
        break;
    case REQUEST_MET_GAME_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_MET_GAME);
        size = 1;
        break;
    case REQUEST_POKEBALL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_POKEBALL);
        size = 1;
        break;
    case REQUEST_ALL_IVS_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_HP_IV);
        dst[1] = GetMonData(&party[monId], MON_DATA_ATK_IV);
        dst[2] = GetMonData(&party[monId], MON_DATA_DEF_IV);
        dst[3] = GetMonData(&party[monId], MON_DATA_SPEED_IV);
        dst[4] = GetMonData(&party[monId], MON_DATA_SPATK_IV);
        dst[5] = GetMonData(&party[monId], MON_DATA_SPDEF_IV);
        size = 6;
        break;
    case REQUEST_HP_IV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_HP_IV);
        size = 1;
        break;
    case REQUEST_ATK_IV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_ATK_IV);
        size = 1;
        break;
    case REQUEST_DEF_IV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_DEF_IV);
        size = 1;
        break;
    case REQUEST_SPEED_IV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPEED_IV);
        size = 1;
        break;
    case REQUEST_SPATK_IV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPATK_IV);
        size = 1;
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SPDEF_IV);
        size = 1;
        break;
    case REQUEST_PERSONALITY_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_PERSONALITY);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_CHECKSUM_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_CHECKSUM);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_STATUS_BATTLE:
        data32 = GetMonData(&party[monId], MON_DATA_STATUS);
        dst[0] = (data32 & 0x000000FF);
        dst[1] = (data32 & 0x0000FF00) >> 8;
        dst[2] = (data32 & 0x00FF0000) >> 16;
        dst[3] = (data32 & 0xFF000000) >> 24;
        size = 4;
        break;
    case REQUEST_LEVEL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_LEVEL);
        size = 1;
        break;
    case REQUEST_HP_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_MAX_HP_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_MAX_HP);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_ATK_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_ATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_DEF_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_DEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPEED_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPEED);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPATK_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPATK);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_SPDEF_BATTLE:
        data16 = GetMonData(&party[monId], MON_DATA_SPDEF);
        dst[0] = data16;
        dst[1] = data16 >> 8;
        size = 2;
        break;
    case REQUEST_COOL_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_COOL);
        size = 1;
        break;
    case REQUEST_BEAUTY_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_BEAUTY);
        size = 1;
        break;
    case REQUEST_CUTE_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_CUTE);
        size = 1;
        break;
    case REQUEST_SMART_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SMART);
        size = 1;
        break;
    case REQUEST_TOUGH_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_TOUGH);
        size = 1;
        break;
    case REQUEST_SHEEN_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SHEEN);
        size = 1;
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_COOL_RIBBON);
        size = 1;
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_BEAUTY_RIBBON);
        size = 1;
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_CUTE_RIBBON);
        size = 1;
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_SMART_RIBBON);
        size = 1;
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        dst[0] = GetMonData(&party[monId], MON_DATA_TOUGH_RIBBON);
        size = 1;
        break;
    }

    return size;
}

static void SetBattlerMonData(enum BattlerId battler, struct Pokemon *party, u32 monId)
{
    struct BattlePokemon *battlePokemon = (struct BattlePokemon *)&gBattleResources->bufferA[battler][3];
    struct MovePPInfo *moveData = (struct MovePPInfo *)&gBattleResources->bufferA[battler][3];
    s32 i;

    switch (gBattleResources->bufferA[battler][1])
    {
    case REQUEST_ALL_BATTLE:
        {
            u8 iv;

            SetMonData(&party[monId], MON_DATA_SPECIES, &battlePokemon->species);
            SetMonData(&party[monId], MON_DATA_HELD_ITEM, &battlePokemon->item);
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                SetMonData(&party[monId], MON_DATA_MOVE1 + i, &battlePokemon->moves[i]);
                SetMonData(&party[monId], MON_DATA_PP1 + i, &battlePokemon->pp[i]);
            }
            SetMonData(&party[monId], MON_DATA_PP_BONUSES, &battlePokemon->ppBonuses);
            SetMonData(&party[monId], MON_DATA_FRIENDSHIP, &battlePokemon->friendship);
            SetMonData(&party[monId], MON_DATA_EXP, &battlePokemon->experience);
            iv = battlePokemon->hpIV;
            SetMonData(&party[monId], MON_DATA_HP_IV, &iv);
            iv = battlePokemon->attackIV;
            SetMonData(&party[monId], MON_DATA_ATK_IV, &iv);
            iv = battlePokemon->defenseIV;
            SetMonData(&party[monId], MON_DATA_DEF_IV, &iv);
            iv = battlePokemon->speedIV;
            SetMonData(&party[monId], MON_DATA_SPEED_IV, &iv);
            iv = battlePokemon->spAttackIV;
            SetMonData(&party[monId], MON_DATA_SPATK_IV, &iv);
            iv = battlePokemon->spDefenseIV;
            SetMonData(&party[monId], MON_DATA_SPDEF_IV, &iv);
            SetMonData(&party[monId], MON_DATA_PERSONALITY, &battlePokemon->personality);
            SetMonData(&party[monId], MON_DATA_STATUS, &battlePokemon->status1);
            SetMonData(&party[monId], MON_DATA_LEVEL, &battlePokemon->level);
            SetMonData(&party[monId], MON_DATA_HP, &battlePokemon->hp);
            SetMonData(&party[monId], MON_DATA_MAX_HP, &battlePokemon->maxHP);
            SetMonData(&party[monId], MON_DATA_ATK, &battlePokemon->attack);
            SetMonData(&party[monId], MON_DATA_DEF, &battlePokemon->defense);
            SetMonData(&party[monId], MON_DATA_SPEED, &battlePokemon->speed);
            SetMonData(&party[monId], MON_DATA_SPATK, &battlePokemon->spAttack);
            SetMonData(&party[monId], MON_DATA_SPDEF, &battlePokemon->spDefense);
        }
        break;
    case REQUEST_SPECIES_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPECIES, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_HELDITEM_BATTLE:
        SetMonData(&party[monId], MON_DATA_HELD_ITEM, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_MOVES_PP_BATTLE:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            SetMonData(&party[monId], MON_DATA_MOVE1 + i, &moveData->moves[i]);
            SetMonData(&party[monId], MON_DATA_PP1 + i, &moveData->pp[i]);
        }
        SetMonData(&party[monId], MON_DATA_PP_BONUSES, &moveData->ppBonuses);
        break;
    case REQUEST_MOVE1_BATTLE:
    case REQUEST_MOVE2_BATTLE:
    case REQUEST_MOVE3_BATTLE:
    case REQUEST_MOVE4_BATTLE:
        SetMonData(&party[monId], MON_DATA_MOVE1 + gBattleResources->bufferA[battler][1] - REQUEST_MOVE1_BATTLE, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_PP_DATA_BATTLE:
        SetMonData(&party[monId], MON_DATA_PP1, &gBattleResources->bufferA[battler][3]);
        SetMonData(&party[monId], MON_DATA_PP2, &gBattleResources->bufferA[battler][4]);
        SetMonData(&party[monId], MON_DATA_PP3, &gBattleResources->bufferA[battler][5]);
        SetMonData(&party[monId], MON_DATA_PP4, &gBattleResources->bufferA[battler][6]);
        SetMonData(&party[monId], MON_DATA_PP_BONUSES, &gBattleResources->bufferA[battler][7]);
        break;
    case REQUEST_PPMOVE1_BATTLE:
    case REQUEST_PPMOVE2_BATTLE:
    case REQUEST_PPMOVE3_BATTLE:
    case REQUEST_PPMOVE4_BATTLE:
        SetMonData(&party[monId], MON_DATA_PP1 + gBattleResources->bufferA[battler][1] - REQUEST_PPMOVE1_BATTLE, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_OTID_BATTLE:
        SetMonData(&party[monId], MON_DATA_OT_ID, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_EXP_BATTLE:
        SetMonData(&party[monId], MON_DATA_EXP, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_HP_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_HP_EV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_ATK_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_ATK_EV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_DEF_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_DEF_EV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPEED_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPEED_EV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPATK_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPATK_EV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPDEF_EV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPDEF_EV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_FRIENDSHIP_BATTLE:
        SetMonData(&party[monId], MON_DATA_FRIENDSHIP, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_POKERUS_BATTLE:
        SetMonData(&party[monId], MON_DATA_POKERUS, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_MET_LOCATION_BATTLE:
        SetMonData(&party[monId], MON_DATA_MET_LOCATION, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_MET_LEVEL_BATTLE:
        SetMonData(&party[monId], MON_DATA_MET_LEVEL, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_MET_GAME_BATTLE:
        SetMonData(&party[monId], MON_DATA_MET_GAME, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_POKEBALL_BATTLE:
        SetMonData(&party[monId], MON_DATA_POKEBALL, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_ALL_IVS_BATTLE:
        SetMonData(&party[monId], MON_DATA_HP_IV, &gBattleResources->bufferA[battler][3]);
        SetMonData(&party[monId], MON_DATA_ATK_IV, &gBattleResources->bufferA[battler][4]);
        SetMonData(&party[monId], MON_DATA_DEF_IV, &gBattleResources->bufferA[battler][5]);
        SetMonData(&party[monId], MON_DATA_SPEED_IV, &gBattleResources->bufferA[battler][6]);
        SetMonData(&party[monId], MON_DATA_SPATK_IV, &gBattleResources->bufferA[battler][7]);
        SetMonData(&party[monId], MON_DATA_SPDEF_IV, &gBattleResources->bufferA[battler][8]);
        break;
    case REQUEST_HP_IV_BATTLE:
        SetMonData(&party[monId], MON_DATA_HP_IV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_ATK_IV_BATTLE:
        SetMonData(&party[monId], MON_DATA_ATK_IV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_DEF_IV_BATTLE:
        SetMonData(&party[monId], MON_DATA_DEF_IV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPEED_IV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPEED_IV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPATK_IV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPATK_IV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPDEF_IV_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPDEF_IV, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_PERSONALITY_BATTLE:
        SetMonData(&party[monId], MON_DATA_PERSONALITY, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_CHECKSUM_BATTLE:
        SetMonData(&party[monId], MON_DATA_CHECKSUM, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_STATUS_BATTLE:
        SetMonData(&party[monId], MON_DATA_STATUS, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_LEVEL_BATTLE:
        SetMonData(&party[monId], MON_DATA_LEVEL, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_HP_BATTLE:
        SetMonData(&party[monId], MON_DATA_HP, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_MAX_HP_BATTLE:
        SetMonData(&party[monId], MON_DATA_MAX_HP, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_ATK_BATTLE:
        SetMonData(&party[monId], MON_DATA_ATK, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_DEF_BATTLE:
        SetMonData(&party[monId], MON_DATA_DEF, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPEED_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPEED, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPATK_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPATK, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SPDEF_BATTLE:
        SetMonData(&party[monId], MON_DATA_SPDEF, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_COOL_BATTLE:
        SetMonData(&party[monId], MON_DATA_COOL, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_BEAUTY_BATTLE:
        SetMonData(&party[monId], MON_DATA_BEAUTY, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_CUTE_BATTLE:
        SetMonData(&party[monId], MON_DATA_CUTE, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SMART_BATTLE:
        SetMonData(&party[monId], MON_DATA_SMART, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_TOUGH_BATTLE:
        SetMonData(&party[monId], MON_DATA_TOUGH, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SHEEN_BATTLE:
        SetMonData(&party[monId], MON_DATA_SHEEN, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_COOL_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_COOL_RIBBON, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_BEAUTY_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_BEAUTY_RIBBON, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_CUTE_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_CUTE_RIBBON, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_SMART_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_SMART_RIBBON, &gBattleResources->bufferA[battler][3]);
        break;
    case REQUEST_TOUGH_RIBBON_BATTLE:
        SetMonData(&party[monId], MON_DATA_TOUGH_RIBBON, &gBattleResources->bufferA[battler][3]);
        break;
    }

    if (IsOnPlayerSide(battler))
        HandleLowHpMusicChange(&party[gBattlerPartyIndexes[battler]], battler);
}

// In normal singles, if follower Pokémon exists, and the Pokémon following is being sent out, have it slide in instead of being thrown
static bool8 ShouldDoSlideInAnim(enum BattlerId battler)
{
    struct ObjectEvent *followerObj = GetFollowerObject();
    if (!followerObj || followerObj->invisible)
        return FALSE;

    if (gBattleTypeFlags & (
        BATTLE_TYPE_LINK | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_FIRST_BATTLE |
        BATTLE_TYPE_SAFARI | BATTLE_TYPE_CATCH_TUTORIAL | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TWO_OPPONENTS |
        BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_RECORDED | BATTLE_TYPE_TRAINER_HILL)
    )
        return FALSE;

    if (GetFirstLiveMon() != GetBattlerMon(battler))
        return FALSE;

    return TRUE;
}

void StartSendOutAnim(enum BattlerId battler, bool32 dontClearTransform, bool32 dontClearSubstituteBit, bool32 doSlideIn)
{
    enum Species species;
    struct Pokemon *mon = GetBattlerMon(battler);
    u32 sendoutType;

    if (IsOnPlayerSide(battler))
    {
        if (doSlideIn)
            sendoutType = POKEBALL_PLAYER_SLIDEIN;
        else
            sendoutType = POKEBALL_PLAYER_SENDOUT;
    }
    else
    {
        sendoutType = POKEBALL_OPPONENT_SENDOUT;
    }

    ClearTemporarySpeciesSpriteData(battler, dontClearTransform, dontClearSubstituteBit);
    gBattlerPartyIndexes[battler] = gBattleResources->bufferA[battler][1];
    species = GetBattlerVisualSpecies(battler);
    gBattleControllerData[battler] = CreateInvisibleSpriteWithCallback(SpriteCB_WaitForBattlerBallReleaseAnim);
    // Load sprite for opponent only, player sprite is expected to be already loaded.
    if (!IsOnPlayerSide(battler))
        BattleLoadMonSpriteGfx(mon, battler);
    SetMultiuseSpriteTemplateToPokemon(species, GetBattlerPosition(battler));

    gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                        GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2),
                                        GetBattlerSpriteDefault_Y(battler),
                                        GetBattlerSpriteSubpriority(battler));

    gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
    gSprites[gBattlerSpriteIds[battler]].data[2] = species;
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
    gSprites[gBattlerSpriteIds[battler]].invisible = TRUE;
    gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;

    gSprites[gBattleControllerData[battler]].data[1] = gBattlerSpriteIds[battler];
    gSprites[gBattleControllerData[battler]].data[2] = battler;
    gSprites[gBattleControllerData[battler]].data[0] = DoPokeballSendOutAnimation(battler, 0, sendoutType);
}

static void FreeMonSprite(enum BattlerId battler)
{
    FreeSpriteOamMatrix(&gSprites[gBattlerSpriteIds[battler]]);
    DestroySprite(&gSprites[gBattlerSpriteIds[battler]]);
    if (!IsOnPlayerSide(battler))
        HideBattlerShadowSprite(battler);
    SetHealthboxSpriteInvisible(gHealthboxSpriteIds[battler]);
}

static void Controller_ReturnMonToBall2(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
    {
        FreeMonSprite(battler);
        BtlController_Complete(battler);
    }
}

static void Controller_ReturnMonToBall(enum BattlerId battler)
{
    switch (gBattleSpritesDataPtr->healthBoxesData[battler].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_SUBSTITUTE_TO_MON);

        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
            InitAndLaunchSpecialAnimation(battler, battler, battler, !IsOnPlayerSide(battler) ? B_ANIM_SWITCH_OUT_OPPONENT_MON : B_ANIM_SWITCH_OUT_PLAYER_MON);
            gBattlerControllerFuncs[battler] = Controller_ReturnMonToBall2;
        }
        break;
    }
}

static void Controller_FaintPlayerMon(enum BattlerId battler)
{
    u32 spriteId = gBattlerSpriteIds[battler];
    if (gSprites[spriteId].y + gSprites[spriteId].y2 > DISPLAY_HEIGHT)
    {
        BattleGfxSfxDummy2(GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES));
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[battler]);
        BtlController_Complete(battler);
    }
}

static void Controller_FaintOpponentMon(enum BattlerId battler)
{
    if (!gSprites[gBattlerSpriteIds[battler]].inUse)
    {
        SetHealthboxSpriteInvisible(gHealthboxSpriteIds[battler]);
        BtlController_Complete(battler);
    }
}

static void Controller_DoMoveAnimation(enum BattlerId battler)
{
    enum Move move = gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8);

    switch (gBattleSpritesDataPtr->healthBoxesData[battler].animationState)
    {
    case 0:
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute
            && !gBattleSpritesDataPtr->battlerData[battler].flag_x8)
        {
            gBattleSpritesDataPtr->battlerData[battler].flag_x8 = 1;
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_SUBSTITUTE_TO_MON);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 1;
        break;
    case 1:
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            SetBattlerSpriteAffineMode(ST_OAM_AFFINE_OFF);
            DoMoveAnim(move);
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 2;
        }
        break;
    case 2:
        gAnimScriptCallback();
        if (!gAnimScriptActive)
        {
            u8 multihit = gBattleResources->bufferA[battler][11];

            SetBattlerSpriteAffineMode(ST_OAM_AFFINE_NORMAL);
            if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute && multihit < 2)
            {
                InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);
                gBattleSpritesDataPtr->battlerData[battler].flag_x8 = 0;
            }
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 3;
        }
        break;
    case 3:
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            CopyAllBattleSpritesInvisibilities();
            TrySetBehindSubstituteSpriteBit(battler, gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
            BtlController_Complete(battler);
        }
        break;
    }
}

static void Controller_HandleTrainerSlideBack(enum BattlerId battler)
{
    if (gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (!IsOnPlayerSide(battler))
            FreeTrainerFrontPicPalette(gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.affineParam);
        FreeSpriteOamMatrix(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]]);
        DestroySprite(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]]);
        BtlController_Complete(battler);
    }
}

void Controller_WaitForHealthBar(enum BattlerId battler)
{
    s16 hpValue = MoveBattleBar(battler, gHealthboxSpriteIds[battler], HEALTH_BAR, 0);
    struct Pokemon *mon = GetBattlerMon(battler);
    s32 maxHP = GetMonData(mon, MON_DATA_MAX_HP);

    SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
    if (hpValue != -1)
    {
        UpdateHpTextInHealthbox(gHealthboxSpriteIds[battler], HP_CURRENT, hpValue, maxHP);
    }
    else
    {
        if (IsOnPlayerSide(battler))
            HandleLowHpMusicChange(GetBattlerMon(battler), battler);

        if (IS_FRLG && GetBattlerSide(battler) == B_SIDE_OPPONENT && !BtlCtrl_OakOldMan_TestState2Flag(1) && (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE))
        {
            BtlCtrl_OakOldMan_SetState2Flag(1);
            gBattlerControllerFuncs[battler] = PrintOakText_InflictingDamageIsKey;
        }
        else
        {
            BtlController_Complete(battler);
        }
    }
}

static void Controller_WaitForBallThrow(enum BattlerId battler)
{
    if (!gDoingBattleAnim || !gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        BtlController_Complete(battler);
}

static void Controller_WaitForBattleAnimation(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].animFromTableActive)
        BtlController_Complete(battler);
}

static void Controller_WaitForStatusAnimation(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive)
        BtlController_Complete(battler);
}

static void Controller_WaitForTrainerPic(enum BattlerId battler)
{
    if (gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback == SpriteCallbackDummy)
        BtlController_Complete(battler);
}

void Controller_WaitForString(enum BattlerId battler)
{
    if (!IsTextPrinterActiveOnWindow(B_WIN_MSG))
        BtlController_Complete(battler);
}

static void Controller_WaitForPartyStatusSummary(enum BattlerId battler)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusDelayTimer++ > 92)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusDelayTimer = 0;
        BtlController_Complete(battler);
    }
}

static void Controller_HitAnimation(enum BattlerId battler)
{
    u32 spriteId = gBattlerSpriteIds[battler];

    if (gSprites[spriteId].data[1] == 32)
    {
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = FALSE;
        gDoingBattleAnim = FALSE;
        BtlController_Complete(battler);
    }
    else
    {
        if ((gSprites[spriteId].data[1] % 4) == 0)
            gSprites[spriteId].invisible ^= 1;
        gSprites[spriteId].data[1]++;
    }
}

// Used for all the commands which do nothing.
void BtlController_Empty(enum BattlerId battler)
{
    BtlController_Complete(battler);
}

// Dummy function at the end of the table.
void BtlController_TerminatorNop(enum BattlerId battler)
{
}

void BattleControllerDummy(enum BattlerId battler)
{
}

// Handlers of the controller commands
void BtlController_HandleGetMonData(enum BattlerId battler)
{
    u8 monData[sizeof(struct Pokemon) * 2 + 56]; // this allows to get full data of two Pokémon, trying to get more will result in overwriting data
    struct Pokemon *party = GetBattlerParty(battler);
    u32 size = 0;
    u8 monToCheck;
    s32 i;

    if (gBattleResources->bufferA[battler][2] == 0)
    {
        size += GetBattlerMonData(battler, party, gBattlerPartyIndexes[battler], monData);
    }
    else
    {
        monToCheck = gBattleResources->bufferA[battler][2];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (monToCheck & 1)
                size += GetBattlerMonData(battler, party, i, monData + size);
            monToCheck >>= 1;
        }
    }
    BtlController_EmitDataTransfer(battler, B_COMM_TO_ENGINE, size, monData);
    BtlController_Complete(battler);
}

void BtlController_HandleGetRawMonData(enum BattlerId battler)
{
    struct BattlePokemon battleMon;
    struct Pokemon *mon = GetBattlerMon(battler);

    u8 *src = (u8 *)mon + gBattleResources->bufferA[battler][1];
    u8 *dst = (u8 *)&battleMon + gBattleResources->bufferA[battler][1];
    u8 i;

    for (i = 0; i < gBattleResources->bufferA[battler][2]; i++)
        dst[i] = src[i];

    BtlController_EmitDataTransfer(battler, B_COMM_TO_ENGINE, gBattleResources->bufferA[battler][2], dst);
    BtlController_Complete(battler);
}

void BtlController_HandleSetMonData(enum BattlerId battler)
{
    struct Pokemon *party = GetBattlerParty(battler);
    u32 i, monToCheck;

    if (gBattleResources->bufferA[battler][2] == 0)
    {
        SetBattlerMonData(battler, party, gBattlerPartyIndexes[battler]);
    }
    else
    {
        monToCheck = gBattleResources->bufferA[battler][2];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (monToCheck & 1)
                SetBattlerMonData(battler, party, i);
            monToCheck >>= 1;
        }
    }
    BtlController_Complete(battler);
}

void BtlController_HandleSetRawMonData(enum BattlerId battler)
{
    u32 i;
    u8 *dst = (u8 *)GetBattlerMon(battler) + gBattleResources->bufferA[battler][1];

    for (i = 0; i < gBattleResources->bufferA[battler][2]; i++)
        dst[i] = gBattleResources->bufferA[battler][3 + i];

    BtlController_Complete(battler);
}

void BtlController_HandleLoadMonSprite(enum BattlerId battler)
{
    u32 y;
    struct Pokemon *mon = GetBattlerMon(battler);
    enum Species species = GetBattlerVisualSpecies(battler);

    if (gBattleTypeFlags & BATTLE_TYPE_GHOST && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        DecompressGhostFrontPic(battler);
        y = GetGhostSpriteDefault_Y(battler);
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = TRUE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = TRUE;
    }
    else
    {
        BattleLoadMonSpriteGfx(mon, battler);
        y = GetBattlerSpriteDefault_Y(battler);
    }
    SetMultiuseSpriteTemplateToPokemon(species, GetBattlerPosition(battler));

    gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                               GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2),
                                               y,
                                               GetBattlerSpriteSubpriority(battler));

    gSprites[gBattlerSpriteIds[battler]].x2 = -DISPLAY_WIDTH;
    gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
    gSprites[gBattlerSpriteIds[battler]].data[2] = species;
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);

    if (!(gBattleTypeFlags & BATTLE_TYPE_GHOST))
        SetBattlerShadowSpriteCallback(battler, species);

    if (IsControllerOpponent(battler) || IsControllerLinkOpponent(battler) || IsControllerRecordedOpponent(battler))
        gBattlerControllerFuncs[battler] = TryShinyAnimAfterMonAnim;
    else
        gBattlerControllerFuncs[battler] = WaitForMonAnimAfterLoad;
}

void BtlController_HandleSwitchInAnim(enum BattlerId battler)
{
    bool32 isPlayerSide = (IsControllerPlayer(battler)
                        || IsControllerPlayerPartner(battler)
                        || IsControllerRecordedPlayer(battler)
                        || IsControllerRecordedPartner(battler)
                        || IsControllerLinkPartner(battler));

    if (IsControllerPlayer(battler))
    {
        gActionSelectionCursor[battler] = 0;
        gMoveSelectionCursor[battler] = 0;
    }
    else if (IsControllerOpponent(battler))
    {
        gBattleStruct->monToSwitchIntoId[battler] = PARTY_SIZE;
    }

    if (isPlayerSide)
        ClearTemporarySpeciesSpriteData(battler, gBattleResources->bufferA[battler][2], gBattleResources->bufferA[battler][3]);
    gBattlerPartyIndexes[battler] = gBattleResources->bufferA[battler][1];
    if (isPlayerSide)
        BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
    StartSendOutAnim(battler, gBattleResources->bufferA[battler][2], gBattleResources->bufferA[battler][3], FALSE);
    gBattlerControllerFuncs[battler] = BtlController_HandleSwitchInTryShinyAnim;
}

void BtlController_HandleReturnMonToBall(enum BattlerId battler)
{
    if (gBattleResources->bufferA[battler][1] == 0)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
        gBattlerControllerFuncs[battler] = Controller_ReturnMonToBall;
    }
    else
    {
        FreeMonSprite(battler);
        BtlController_Complete(battler);
    }
}

// In emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven)
// that use an animated back pic.

#define sSpeedX data[0]

void BtlController_HandleDrawTrainerPic(enum BattlerId battler, enum TrainerPicID trainerPicId, bool32 isFrontPic, s16 xPos, s16 yPos, s32 subpriority)
{
    if (!IsOnPlayerSide(battler)) // Always the front sprite for the opponent.
    {
        DecompressTrainerFrontPic(trainerPicId, battler);
        SetMultiuseSpriteTemplateToTrainerFront(trainerPicId, GetBattlerPosition(battler));
        if (subpriority == -1)
            subpriority = GetBattlerSpriteSubpriority(battler);
        gBattleStruct->trainerSlideSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                   xPos,
                                                   yPos,
                                                   subpriority);

        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(GetTrainerPicTag(trainerPicId, TRUE));
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].x2 = -DISPLAY_WIDTH;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].sSpeedX = 2;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.affineParam = trainerPicId;
    }
    else // Player's side
    {
        if (isFrontPic)
        {
            DecompressTrainerFrontPic(trainerPicId, battler);
            SetMultiuseSpriteTemplateToTrainerFront(trainerPicId, GetBattlerPosition(battler));
            if (subpriority == -1)
                subpriority = GetBattlerSpriteSubpriority(battler);
            gBattleStruct->trainerSlideSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                             xPos,
                                                             yPos,
                                                             subpriority);

            gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(GetTrainerPicTag(trainerPicId, TRUE));
            gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.affineMode = ST_OAM_AFFINE_OFF;
            gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].hFlip = 1;
            gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].y2 = 48;
        }
        else
        {
            LoadSpritePaletteWithTag(GetTrainerBackPicPalette(trainerPicId), GetTrainerPicTag(trainerPicId, FALSE));
            SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(battler));
            if (subpriority == -1)
                subpriority = GetBattlerSpriteSubpriority(battler);
            gBattleStruct->trainerSlideSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                             xPos,
                                                             yPos,
                                                             subpriority);
            if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
                gBattlerSpriteIds[battler] = gBattleStruct->trainerSlideSpriteIds[battler];

            // Sets sprite priority to 1 so mons don't remain in foreground
            gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.priority = 1;
            gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(GetTrainerPicTag(trainerPicId, FALSE));
        }
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].x2 = DISPLAY_WIDTH;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].sSpeedX = -2;
    }
    if (B_FAST_INTRO_NO_SLIDE || gTestRunnerHeadless)
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback = SpriteCB_TrainerSpawn;
    else
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback = SpriteCB_TrainerSlideIn;

    gBattlerControllerFuncs[battler] = Controller_WaitForTrainerPic;
}

void BtlController_HandleTrainerSlide(enum BattlerId battler, enum TrainerPicID trainerPicId)
{
    if (IsOnPlayerSide(battler))
    {
        LoadSpritePaletteWithTag(GetTrainerBackPicPalette(trainerPicId), GetTrainerPicTag(trainerPicId, FALSE));
        SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(battler));
        gBattleStruct->trainerSlideSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate,
                                                         80,
                                                         (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80,
                                                         30);
        if ((gBattleTypeFlags & BATTLE_TYPE_SAFARI) && GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
            gBattlerSpriteIds[battler] = gBattleStruct->trainerSlideSpriteIds[battler];
        // Sets sprite priority to 1 so mons don't remain in foreground
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.priority = 1;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(GetTrainerPicTag(trainerPicId, FALSE));
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].x2 = -96;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].sSpeedX = 2;
    }
    else
    {
        DecompressTrainerFrontPic(trainerPicId, battler);
        SetMultiuseSpriteTemplateToTrainerFront(trainerPicId, GetBattlerPosition(battler));
        gBattleStruct->trainerSlideSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, 176, 40, 0);
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.affineParam = trainerPicId;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].oam.paletteNum = IndexOfSpritePaletteTag(GetTrainerPicTag(trainerPicId, TRUE));
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].x2 = 96;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].x += 32;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].sSpeedX = -2;
    }
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback = SpriteCB_TrainerSlideIn;

    gBattlerControllerFuncs[battler] = Controller_WaitForTrainerPic;
}

#undef sSpeedX

void BtlController_HandleTrainerSlideBack(enum BattlerId battler, s16 data0, bool32 startAnim)
{
    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]]);
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[0] = data0;
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[2] = IsOnPlayerSide(battler) ? -40 : 280;
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[4] = gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].y;
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]], SpriteCallbackDummy);
    if (startAnim)
        StartSpriteAnim(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]], 1);
    gBattlerControllerFuncs[battler] = Controller_HandleTrainerSlideBack;
}

#define sSpeedX data[1]
#define sSpeedY data[2]

void BtlController_HandleFaintAnimation(enum BattlerId battler)
{
    SetHealthboxSpriteInvisible(gHealthboxSpriteIds[battler]);
    if (gBattleSpritesDataPtr->healthBoxesData[battler].animationState == 0)
    {
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_SUBSTITUTE_TO_MON);
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState++;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
            if (IsOnPlayerSide(battler))
            {
                HandleLowHpMusicChange(GetBattlerMon(battler), battler);
                gSprites[gBattlerSpriteIds[battler]].sSpeedX = 0;
                gSprites[gBattlerSpriteIds[battler]].sSpeedY = 5;
                PlaySE12WithPanning(SE_FAINT, SOUND_PAN_ATTACKER);
                gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_FaintSlideAnim;
                gBattlerControllerFuncs[battler] = Controller_FaintPlayerMon;
            }
            else
            {
                PlaySE12WithPanning(SE_FAINT, SOUND_PAN_TARGET);
                gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_FaintOpponentMon;
                gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
                gBattlerControllerFuncs[battler] = Controller_FaintOpponentMon;
            }
            // The player's sprite callback just slides the mon, the opponent's removes the sprite.
            // The player's sprite is removed in Controller_FaintPlayerMon. Controller_FaintOpponentMon only removes the healthbox once the sprite is removed by SpriteCB_FaintOpponentMon.
        }
    }
    AnimateMonAfterKnockout(battler);
}

#undef sSpeedX
#undef sSpeedY

static void HandleBallThrow(enum BattlerId battler, enum BattlerId target, u32 animId, bool32 allowCriticalCapture)
{
    gDoingBattleAnim = TRUE;
    if (allowCriticalCapture && IsCriticalCapture())
        animId = B_ANIM_CRITICAL_CAPTURE_THROW;
    InitAndLaunchSpecialAnimation(battler, battler, target, animId);

    gBattlerControllerFuncs[battler] = Controller_WaitForBallThrow;
}

void BtlController_HandleBallThrowAnim(enum BattlerId battler)
{
    bool32 allowCriticalCapture = FALSE;
    u32 animId = B_ANIM_BALL_THROW;
    enum BattlerId target = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);

    if (BattlerIsPlayer(battler))
    {
        allowCriticalCapture = TRUE;
        target = gBattlerTarget;
    }
    else if (IsControllerSafari(battler) || IsControllerWally(battler) || IsControllerOakOldMan(battler))
    {
        animId = B_ANIM_BALL_THROW_WITH_TRAINER;
    }

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = gBattleResources->bufferA[battler][1];
    HandleBallThrow(battler, target, animId, allowCriticalCapture);
}

void BtlController_HandleMoveAnimation(enum BattlerId battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        u16 move = gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8);

        gAnimMoveTurn = gBattleResources->bufferA[battler][3];
        gAnimMovePower = gBattleResources->bufferA[battler][4] | (gBattleResources->bufferA[battler][5] << 8);
        gAnimMoveDmg = gBattleResources->bufferA[battler][6] | (gBattleResources->bufferA[battler][7] << 8) | (gBattleResources->bufferA[battler][8] << 16) | (gBattleResources->bufferA[battler][9] << 24);
        gAnimFriendship = gBattleResources->bufferA[battler][10];
        gWeatherMoveAnim = gBattleResources->bufferA[battler][12] | (gBattleResources->bufferA[battler][13] << 8);
        gAnimDisableStructPtr = (struct LinkBattleAnim *)&gBattleResources->bufferA[battler][16];
        gTransformedPersonalities[battler] = gAnimDisableStructPtr->transformedMonPID;
        gTransformedShininess[battler] = gAnimDisableStructPtr->isTransformedMonShiny;
        gBattleSpritesDataPtr->healthBoxesData[battler].animationState = 0;
        gBattlerControllerFuncs[battler] = Controller_DoMoveAnimation;
        if (ShouldUpdateTvData(battler))
            BattleTv_SetDataBasedOnMove(move, gWeatherMoveAnim);
    }
}

void BtlController_HandlePrintString(enum BattlerId battler)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = (u16 *)(&gBattleResources->bufferA[battler][2]);
    BufferStringBattle(*stringId, battler);

    if (gTestRunnerEnabled)
    {
        TestRunner_Battle_RecordMessage(gDisplayedStringBattle);
        if (gTestRunnerHeadless || *stringId == STRINGID_CELEBRATEMESSAGE)
        {
            BtlController_Complete(battler);
            return;
        }
    }


    // if (BattleStringShouldBeColored(*stringId))
    //     BattlePutTextOnWindow(gDisplayedStringBattle, (B_WIN_MSG | B_TEXT_FLAG_NPC_CONTEXT_FONT));
    // else
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MSG);

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        switch (*stringId)
        {
        case STRINGID_TRAINER1WINTEXT:
            gBattlerControllerFuncs[battler] = PrintOakText_HowDisappointing;
            return;
        case STRINGID_DONTLEAVEBIRCH:
            gBattlerControllerFuncs[battler] = PrintOakText_OakNoRunningFromATrainer;
            return;
        }
    }

    gBattlerControllerFuncs[battler] = Controller_WaitForString;
    if (ShouldUpdateTvData(battler))
        BattleTv_SetDataBasedOnString(*stringId);
    if (IsControllerPlayer(battler)
     || IsControllerOpponent(battler))
        BattleArena_DeductSkillPoints(battler, *stringId);
}

void BtlController_HandlePrintStringPlayerOnly(enum BattlerId battler)
{
    if (IsOnPlayerSide(battler))
        BtlController_HandlePrintString(battler);
    else
        BtlController_Complete(battler);
}

void BtlController_HandleHealthBarUpdate(enum BattlerId battler)
{
    s32 maxHP, curHP;
    s16 hpVal;
    struct Pokemon *mon = GetBattlerMon(battler);

    LoadBattleBarGfx(0);
    hpVal = gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8);
    maxHP = GetMonData(mon, MON_DATA_MAX_HP);
    curHP = GetMonData(mon, MON_DATA_HP);

    if (hpVal != INSTANT_HP_BAR_DROP)
    {
        SetBattleBarStruct(battler, gHealthboxSpriteIds[battler], maxHP, curHP, hpVal);
        TestRunner_Battle_RecordHP(battler, curHP, min(maxHP, max(0, curHP - hpVal)));
    }
    else
    {
        SetBattleBarStruct(battler, gHealthboxSpriteIds[battler], maxHP, 0, hpVal);
        if (IsControllerPlayer(battler)
         || IsControllerRecordedPlayer(battler)
         || IsControllerRecordedPartner(battler)
         || IsControllerOakOldMan(battler)
         || IsControllerWally(battler))
            UpdateHpTextInHealthbox(gHealthboxSpriteIds[battler], HP_CURRENT, 0, maxHP);
        TestRunner_Battle_RecordHP(battler, curHP, 0);
    }

    gBattlerControllerFuncs[battler] = Controller_WaitForHealthBar;
}

void BtlController_HandleStatusIconUpdate(enum BattlerId battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        struct Pokemon *mon = GetBattlerMon(battler);

        if (IsControllerSafari(battler))
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_SAFARI_BALLS_TEXT);
            BtlController_Complete(battler);
        }
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_STATUS_ICON);
            gBattleSpritesDataPtr->healthBoxesData[battler].statusAnimActive = 0;
            gBattlerControllerFuncs[battler] = Controller_WaitForStatusAnimation;
            if (gTestRunnerEnabled && BattlerIsRecorded(battler))
                TestRunner_Battle_RecordStatus1(battler, GetMonData(GetBattlerMon(battler), MON_DATA_STATUS));
        }
    }
}

void BtlController_HandleStatusAnimation(enum BattlerId battler)
{
    if (!IsBattleSEPlaying(battler))
    {
        InitAndLaunchChosenStatusAnimation(battler, gBattleResources->bufferA[battler][1],
                        gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8) | (gBattleResources->bufferA[battler][4] << 16) | (gBattleResources->bufferA[battler][5] << 24));
        gBattlerControllerFuncs[battler] = Controller_WaitForStatusAnimation;
    }
}

void BtlController_HandleHitAnimation(enum BattlerId battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].invisible == TRUE || (gTestRunnerHeadless && !gBattleTestRunnerState->forceMoveAnim))
    {
        BtlController_Complete(battler);
    }
    else
    {
        gDoingBattleAnim = TRUE;
        gSprites[gBattlerSpriteIds[battler]].data[1] = 0;
        DoHitAnimHealthboxEffect(battler);
        gBattlerControllerFuncs[battler] = Controller_HitAnimation;
    }
}

void BtlController_HandlePlaySE(enum BattlerId battler)
{
    if (gTestRunnerHeadless && !gBattleTestRunnerState->forceMoveAnim)
    {
        BtlController_Complete(battler);
        return;
    }
    s32 pan = IsOnPlayerSide(battler) ? SOUND_PAN_ATTACKER : SOUND_PAN_TARGET;

    PlaySE12WithPanning(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8), pan);
    BtlController_Complete(battler);
}

void BtlController_HandlePlayFanfareOrBGM(enum BattlerId battler)
{
    if (gTestRunnerHeadless && !gBattleTestRunnerState->forceMoveAnim)
    {
        BtlController_Complete(battler);
        return;
    }
    if (gBattleResources->bufferA[battler][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    }

    BtlController_Complete(battler);
}

void BtlController_HandleFaintingCry(enum BattlerId battler)
{
    struct Pokemon *party = GetBattlerParty(battler);
    s8 pan;

    if (IsOnPlayerSide(battler))
        pan = -25;
    else
        pan = 25;

    PlayCry_ByMode(GetMonData(&party[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), pan, CRY_MODE_FAINT);
    BtlController_Complete(battler);
}

void BtlController_HandleIntroSlide(enum BattlerId battler)
{
    HandleIntroSlide(gBattleResources->bufferA[battler][1]);
    gIntroSlideFlags |= 1;
    BtlController_Complete(battler);
}

void BtlController_HandleSpriteInvisibility(enum BattlerId battler)
{
    if (IsBattlerSpritePresent(battler))
    {
        gSprites[gBattlerSpriteIds[battler]].invisible = gBattleResources->bufferA[battler][1];
        CopyBattleSpriteInvisibility(battler);
    }
    BtlController_Complete(battler);
}

bool32 TwoPlayerIntroMons(enum BattlerId battler) // Double battle with both player Pokémon active.
{
    return (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(battler ^ BIT_FLANK)));
}

bool32 TwoOpponentIntroMons(enum BattlerId battler) // Double battle with both opponent Pokémon active.
{
    return (IsDoubleBattle()
            && IsValidForBattle(GetBattlerMon(battler))
            && IsValidForBattle(GetBattlerMon(GetPartnerBattler(battler))));
}

// Task data for Task_StartSendOutAnim
#define tBattlerId          data[0]
#define tStartTimer         data[1]
#define tFramesToWait       data[2]
#define tControllerFunc_1   3 // Stored as two halfwords
#define tControllerFunc_2   4

// Sprite data for SpriteCB_FreePlayerSpriteLoadMonSprite
#define sBattlerId data[5]

void BtlController_HandleIntroTrainerBallThrow(enum BattlerId battler, u16 tagTrainerPal, const u16 *trainerPal, s16 framesToWait, void (*controllerCallback)(enum BattlerId battler))
{
    u8 taskId;
    enum BattleSide side = GetBattlerSide(battler);

    SetSpritePrimaryCoordsFromSecondaryCoords(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]]);
    if (side == B_SIDE_PLAYER)
    {
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[0] = 50;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[2] = -40;
    }
    else
    {
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[0] = 35;
        gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[2] = 280;
    }

    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].data[4] = gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].y;
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].callback = StartAnimLinearTranslation;
    gSprites[gBattleStruct->trainerSlideSpriteIds[battler]].sBattlerId = battler;

    if (side == B_SIDE_PLAYER)
    {
        StoreSpriteCallbackInData6(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]], SpriteCB_FreePlayerSpriteLoadMonSprite);
        StartSpriteAnim(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]], ShouldDoSlideInAnim(battler) ? 2 : 1);
    }
    else
    {
        StoreSpriteCallbackInData6(&gSprites[gBattleStruct->trainerSlideSpriteIds[battler]], SpriteCB_FreeOpponentSprite);
    }

    taskId = CreateTask(Task_StartSendOutAnim, 5);
    gTasks[taskId].tBattlerId = battler;
    gTasks[taskId].tFramesToWait = framesToWait;
    SetWordTaskArg(taskId, tControllerFunc_1, (uint32_t)(controllerCallback));

    if (gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[battler]].func = Task_HidePartyStatusSummary;

    gBattleSpritesDataPtr->animationData->introAnimActive = TRUE;
    gBattlerControllerFuncs[battler] = BattleControllerDummy;
}

static bool32 TwoMonsAtSendOut(enum BattlerId battler)
{
    if (IsOnPlayerSide(battler))
    {
        if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        if ((!TwoOpponentIntroMons(battler) || (gBattleTypeFlags & BATTLE_TYPE_MULTI)) && !BATTLE_TWO_VS_ONE_OPPONENT)
            return FALSE;
        else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) || (BATTLE_TWO_VS_ONE_OPPONENT && !TwoOpponentIntroMons(battler)))
            return FALSE;
        else
            return TRUE;
    }
    return FALSE;
}

// Send out at start of battle
static void Task_StartSendOutAnim(u8 taskId)
{
    if (gTasks[taskId].tFramesToWait != 0 && gTasks[taskId].tStartTimer < gTasks[taskId].tFramesToWait)
    {
        gTasks[taskId].tStartTimer++;
    }
    else
    {
        enum BattlerId battlerPartner;
        enum BattlerId battler = gTasks[taskId].tBattlerId;

        if (TwoMonsAtSendOut(battler))
        {
            gBattleResources->bufferA[battler][1] = gBattlerPartyIndexes[battler];
            StartSendOutAnim(battler, FALSE, FALSE, ShouldDoSlideInAnim(battler));

            battlerPartner = battler ^ BIT_FLANK;
            gBattleResources->bufferA[battlerPartner][1] = gBattlerPartyIndexes[battlerPartner];
            BattleLoadMonSpriteGfx(GetBattlerMon(battlerPartner), battlerPartner);
            StartSendOutAnim(battlerPartner, FALSE, FALSE, ShouldDoSlideInAnim(battler));
        }
        else
        {
            gBattleResources->bufferA[battler][1] = gBattlerPartyIndexes[battler];
            StartSendOutAnim(battler, FALSE, FALSE, ShouldDoSlideInAnim(battler));
        }
        gBattlerControllerFuncs[battler] = (void*)(GetWordTaskArg(taskId, tControllerFunc_1));
        DestroyTask(taskId);
    }
}

#undef tBattlerId
#undef tStartTimer
#undef tFramesToWait
#undef tControllerFunc_1
#undef tControllerFunc_2

static void SpriteCB_FreePlayerSpriteLoadMonSprite(struct Sprite *sprite)
{
    enum BattlerId battler = sprite->sBattlerId;

    // Free player trainer sprite
    FreeSpriteOamMatrix(sprite);
    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));
    DestroySprite(sprite);

    // Load mon sprite
    BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
}

static void SpriteCB_FreeOpponentSprite(struct Sprite *sprite)
{
    FreeTrainerFrontPicPalette(sprite->oam.affineParam);
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
}

#undef sBattlerId

void BtlController_HandleDrawPartyStatusSummary(enum BattlerId battler, enum BattleSide side, bool32 considerDelay)
{
    if (gBattleResources->bufferA[battler][1] != 0 && IsOnPlayerSide(battler))
    {
        BtlController_Complete(battler);
    }
    else
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown = 1;

        if (side == B_SIDE_OPPONENT && gBattleResources->bufferA[battler][2] != 0)
        {
            if (gBattleSpritesDataPtr->healthBoxesData[battler].opponentDrawPartyStatusSummaryDelay < 2)
            {
                gBattleSpritesDataPtr->healthBoxesData[battler].opponentDrawPartyStatusSummaryDelay++;
                return;
            }
            else
            {
                gBattleSpritesDataPtr->healthBoxesData[battler].opponentDrawPartyStatusSummaryDelay = 0;
            }
        }

        gBattlerStatusSummaryTaskId[battler] = CreatePartyStatusSummarySprites(battler, (struct HpAndStatus *)&gBattleResources->bufferA[battler][4], gBattleResources->bufferA[battler][1], gBattleResources->bufferA[battler][2]);
        gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusDelayTimer = 0;

        // If intro, skip the delay after drawing
        if (considerDelay && gBattleResources->bufferA[battler][2] != 0)
            gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusDelayTimer = 93;

        gBattlerControllerFuncs[battler] = Controller_WaitForPartyStatusSummary;
    }
}

void BtlController_HandleHidePartyStatusSummary(enum BattlerId battler)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].partyStatusSummaryShown)
        gTasks[gBattlerStatusSummaryTaskId[battler]].func = Task_HidePartyStatusSummary;
    BtlController_Complete(battler);
}

void BtlController_HandleBattleAnimation(enum BattlerId battler)
{
    if ((gBattleTypeFlags & (BATTLE_TYPE_SAFARI | BATTLE_TYPE_CATCH_TUTORIAL))
        || IsControllerOakOldMan(battler)
        || !IsBattleSEPlaying(battler))
    {
        u8 animationId = gBattleResources->bufferA[battler][1];
        u16 argument = gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8);

        gAnimDisableStructPtr = (struct LinkBattleAnim *)&gBattleResources->bufferA[battler][4];

        if (TryHandleLaunchBattleTableAnimation(battler, battler, battler, animationId, argument))
            BtlController_Complete(battler);
        else
            gBattlerControllerFuncs[battler] = Controller_WaitForBattleAnimation;

        if (ShouldUpdateTvData(battler))
            BattleTv_SetDataBasedOnAnimation(animationId);
    }
}

void AnimateMonAfterPokeBallFail(enum BattlerId battler)
{
    if (B_ANIMATE_MON_AFTER_FAILED_POKEBALL == FALSE)
        return;

    LaunchKOAnimation(battler, ReturnAnimIdForBattler(TRUE, battler), TRUE);
    TryShinyAnimation(gBattlerTarget, GetBattlerMon(gBattlerTarget));
}

static void AnimateMonAfterKnockout(enum BattlerId battler)
{
    if (B_ANIMATE_MON_AFTER_KO == FALSE)
        return;

    enum BattlerId oppositeBattler = GetOppositeBattler(battler);
    enum BattlerId partnerBattler = GetPartnerBattler(oppositeBattler);
    bool32 wasPlayerSideKnockedOut = (IsOnPlayerSide(battler));

    if (IsBattlerAlive(oppositeBattler))
        LaunchKOAnimation(oppositeBattler, ReturnAnimIdForBattler(wasPlayerSideKnockedOut, oppositeBattler), wasPlayerSideKnockedOut);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsBattlerAlive(partnerBattler))
        LaunchKOAnimation(partnerBattler, ReturnAnimIdForBattler(wasPlayerSideKnockedOut, partnerBattler), wasPlayerSideKnockedOut);
}

static void LaunchKOAnimation(enum BattlerId battlerId, u16 animId, bool32 isFront)
{
    enum Species species = GetBattlerVisualSpecies(battlerId);
    u32 spriteId = gBattlerSpriteIds[battlerId];

    gBattleStruct->battlerKOAnimsRunning++;

    if (isFront)
    {
        LaunchAnimationTaskForFrontSprite(&gSprites[spriteId], animId);

        if (HasTwoFramesAnimation(species))
            StartSpriteAnim(&gSprites[spriteId], 1);
    }
    else
    {
        LaunchAnimationTaskForBackSprite(&gSprites[spriteId], animId);
    }

    PlayCry_Normal(species, CRY_PRIORITY_NORMAL);
}

static u32 ReturnAnimIdForBattler(bool32 wasPlayerSideKnockedOut, u32 specificBattler)
{
    enum Species species = GetBattlerVisualSpecies(specificBattler);
    if (wasPlayerSideKnockedOut)
        return gSpeciesInfo[species].frontAnimId;
    else
        return GetSpeciesBackAnimSet(species);
}

void TrySetBattlerShadowSpriteCallback(enum BattlerId battler)
{
    if (gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdPrimary].callback == SpriteCallbackDummy
     && (B_ENEMY_MON_SHADOW_STYLE <= GEN_3 || P_GBA_STYLE_SPECIES_GFX == TRUE
      || gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].shadowSpriteIdSecondary].callback == SpriteCallbackDummy))
        SetBattlerShadowSpriteCallback(battler, GetBattlerVisualSpecies(battler));
}

void TryShinyAnimAfterMonAnim(enum BattlerId battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].x2 == 0)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim)
        {
            TryShinyAnimation(battler, GetBattlerMon(battler));
        }

        if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
        {
            gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
            FreeShinyStars();
            BtlController_Complete(battler);
        }
    }
}

void WaitForMonAnimAfterLoad(enum BattlerId battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].animEnded && gSprites[gBattlerSpriteIds[battler]].x2 == 0)
        BtlController_Complete(battler);
}

void BtlController_HandleSwitchInShowSubstitute(enum BattlerId battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        if (IsOnPlayerSide(battler))
            CopyBattleSpriteInvisibility(battler);

        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

        if (IsControllerOpponent(battler)
         && IsControllerLinkOpponent(battler)
         && IsControllerRecordedOpponent(battler))
            gBattlerControllerFuncs[battler] = BtlController_HandleSwitchInSoundAndEnd;
        else
            gBattlerControllerFuncs[battler] = BtlController_HandleSwitchInWaitAndEnd;
    }
}

void BtlController_HandleSwitchInWaitAndEnd(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        BtlController_Complete(battler);
}

void BtlController_Intro_DelayAndEnd(enum BattlerId battler)
{
    if (--gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay == (u8)-1)
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 0;
        BtlController_Complete(battler);
    }
}

void BtlController_HandleSwitchInSoundAndEnd(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive && !IsCryPlayingOrClearCrySongs())
    {
        if (gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
         || gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy_2
         || IsOnPlayerSide(battler))
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
            if (IsControllerPlayer(battler))
                HandleLowHpMusicChange(GetBattlerMon(battler), battler);
            BtlController_Complete(battler);
        }
    }
}

void BtlController_HandleSwitchInShowHealthbox(enum BattlerId battler)
{
    enum BattleSide side = GetBattlerSide(battler);
    if (gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && (side == B_SIDE_PLAYER || gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy))
    {
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeShinyStars();

        if (side == B_SIDE_PLAYER)
        {
            CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
            HandleLowHpMusicChange(GetBattlerMon(battler), battler);
        }

        StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
        StartHealthboxSlideIn(battler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

        if (side == B_SIDE_OPPONENT)
            CopyBattleSpriteInvisibility(battler);
        gBattlerControllerFuncs[battler] = BtlController_HandleSwitchInShowSubstitute;
    }
}

static void SwitchIn_CleanShinyAnimShowSubstitute(enum BattlerId battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
     && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
     && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        CopyBattleSpriteInvisibility(battler);

        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeShinyStars();

        // Check if Substitute should be shown
        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

        gBattlerControllerFuncs[battler] = BtlController_HandleSwitchInSoundAndEnd;
    }
}

void BtlController_HandleSwitchInTryShinyAnim(enum BattlerId battler)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim)
        TryShinyAnimation(battler, GetBattlerMon(battler));

    if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        DestroySprite(&gSprites[gBattleControllerData[battler]]);

        if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
            SetBattlerShadowSpriteCallback(battler, GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES));

        if (IsControllerPlayer(battler))
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
            gBattlerControllerFuncs[battler] = SwitchIn_CleanShinyAnimShowSubstitute;
        }
        else
        {
            gBattlerControllerFuncs[battler] = BtlController_HandleSwitchInShowHealthbox;
        }
    }
}

void UpdateFriendshipFromXItem(enum BattlerId battler)
{
    struct Pokemon *party = GetBattlerParty(battler);

    u8 friendship;
    gBattleResources->bufferA[battler][1] = REQUEST_FRIENDSHIP_BATTLE;
    GetBattlerMonData(battler, party, gBattlerPartyIndexes[battler], &friendship);

    enum Item heldItem;
    gBattleResources->bufferA[battler][1] = REQUEST_HELDITEM_BATTLE;
    GetBattlerMonData(battler, party, gBattlerPartyIndexes[battler], (u8*)&heldItem);

    if (friendship < X_ITEM_MAX_FRIENDSHIP)
    {
        friendship += CalculateFriendshipBonuses(GetBattlerMon(battler), X_ITEM_FRIENDSHIP_INCREASE, GetItemHoldEffect(heldItem));

        if (friendship > MAX_FRIENDSHIP)
            friendship = MAX_FRIENDSHIP;

        gBattleMons[battler].friendship = friendship;
        gBattleResources->bufferA[battler][3] = friendship;
        gBattleResources->bufferA[battler][1] = REQUEST_FRIENDSHIP_BATTLE;
        SetBattlerMonData(battler, GetBattlerParty(battler), gBattlerPartyIndexes[battler]);
    }
}

bool32 ShouldBattleRestrictionsApply(enum BattlerId battler)
{
    return IsControllerPlayer(battler);
}

void FreeShinyStars(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim)
            return;
    }
    FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
    FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);
}

enum BattleTrainer GetBattlerTrainer(enum BattlerId battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        switch (gBattlerBattleController[battler])
        {
        case BATTLE_CONTROLLER_PLAYER:
        case BATTLE_CONTROLLER_RECORDED_PLAYER:
            return B_TRAINER_PLAYER;
        case BATTLE_CONTROLLER_LINK_PARTNER:
        case BATTLE_CONTROLLER_RECORDED_PARTNER:
            return B_TRAINER_PARTNER;
        case BATTLE_CONTROLLER_LINK_OPPONENT:
        case BATTLE_CONTROLLER_RECORDED_OPPONENT:
        case BATTLE_CONTROLLER_OPPONENT:
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                return (battler & BIT_FLANK) ? B_TRAINER_OPPONENT_B : B_TRAINER_OPPONENT_A;
            return B_TRAINER_OPPONENT_A;
        default:
            break;
        }
    }

    return (enum BattleTrainer)(BattleSideHasTwoTrainers(battler & BIT_SIDE) ? battler : battler & BIT_SIDE);
}

enum BattleTrainer GetTrainerFromBattlePosition(enum BattlerPosition position)
{
    return GetBattlerTrainer(GetBattlerAtPosition(position));
}

bool32 BattleSideHasTwoTrainers(enum BattleSide side)
{
    if (side == B_SIDE_PLAYER)
        return gBattleTypeFlags & BATTLE_TYPE_MULTI;
    else
        return ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && TRAINER_BATTLE_PARAM.opponentB != 0xFFFF) || (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI));
}

bool32 BattlersShareParty(enum BattlerId battler1, enum BattlerId battler2)
{
    return (GetBattlerParty(battler1) == GetBattlerParty(battler2));
}

bool32 TrainerHasParty(enum BattleTrainer trainer)
{
    return (trainer < B_TRAINER_PARTNER || BattleSideHasTwoTrainers((enum BattleSide)(trainer & BIT_SIDE)));
}

// Used for partner and opponent
void SetFinalChosenTarget(enum BattlerId battler, bool32 checkPartner)
{
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);

    enum BattlerId chosenTarget = gAiBattleData->chosenTarget[battler];
    u32 chosenMoveIndex = gAiBattleData->chosenMoveIndex[battler];
    u32 chosenMove = moveInfo->moves[chosenMoveIndex];
    enum MoveTarget targetType = GetBattlerMoveSelectionTargetType(battler, chosenMove);

    switch (targetType)
    {
    case TARGET_ALLY:
        chosenTarget = GetPartnerBattler(battler);
        break;
    case TARGET_USER_OR_ALLY: // AI could have chosen opponent as the target because of the way the score system works
        if (!IsBattlerAlly(battler, chosenTarget) || !IsBattlerAlive(GetPartnerBattler(battler)))
            chosenTarget = battler;
        break;
    case TARGET_USER:
    case TARGET_ALL_BATTLERS:
    case TARGET_FIELD:
        chosenTarget = battler;
        break;
    case TARGET_BOTH:
        if (checkPartner)
        {
            chosenTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            if (!IsBattlerAlive(chosenTarget))
                chosenTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        }
        else
        {
            chosenTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            if (!IsBattlerAlive(chosenTarget))
                chosenTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        }
        break;
    default:
        break;
    }

    gBattlerTarget = chosenTarget;

    enum Gimmick usableGimmick = gBattleStruct->gimmick.usableGimmick[battler];
    bool32 isAIUsingGimmick = gAiBattleData->aiUsingGimmick & (1u << battler);
    if (usableGimmick != GIMMICK_NONE && isAIUsingGimmick && !HasTrainerUsedGimmick(battler, usableGimmick))
    {
        gBattleStruct->gimmick.toActivate |= 1u << battler;
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, (chosenMoveIndex) | (RET_GIMMICK) | (chosenTarget << 8));
    }
    else
    {
        SetAIUsingGimmick(battler, NO_GIMMICK);
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, (chosenMoveIndex) | (chosenTarget << 8));
    }
}
