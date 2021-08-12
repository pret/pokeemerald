#include "global.h"
#include "contest.h"
#include "decompress.h"
#include "event_data.h"
#include "link.h"
#include "pokemon.h"
#include "random.h"
#include "task.h"
#include "contest_link.h"

static void Task_LinkContest_StartInitFlags(u8);
static void Task_LinkContest_InitFlags(u8);

#define tState         data[0]
#define tDelayTimer    data[1]
#define tCategories(i) data[(i) + 1]
#define tLeaderIds(i)  data[(i) + 5]
#define tCategory      data[9]
#define tTimer         data[11]
#define tStandbyState  data[12]

bool32 LinkContest_SendBlock(void *src, u16 size)
{
    memcpy(gDecompressionBuffer, src, size);
    if (SendBlock(bitmask_all_link_players_but_self(), gDecompressionBuffer, size))
        return TRUE;
    else
        return FALSE;
}

bool8 LinkContest_GetBlockReceived(u8 flag)
{
    u8 mask = (1 << flag);
    if (!(GetBlockReceivedStatus() & mask))
    {
        return FALSE;
    }
    else
    {
        ResetBlockReceivedFlag(flag);
        return TRUE;
    }
}

bool8 LinkContest_GetBlockReceivedFromAllPlayers(void)
{
    if (GetBlockReceivedStatus() == GetLinkPlayerCountAsBitFlags())
    {
        ResetBlockReceivedFlags();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Task_LinkContest_Init(u8 taskId)
{
    u8 i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        gBlockRecvBuffer[i][0] = 0xFF;
    
    gTasks[taskId].tState = 0;
    gTasks[taskId].func = Task_LinkContest_StartInitFlags;
}

static void Task_LinkContest_StartInitFlags(u8 taskId)
{
    gTasks[taskId].func = Task_LinkContest_InitFlags;
}

static void Task_LinkContest_InitFlags(u8 taskId)
{
    int i;

    if (!gReceivedRemoteLinkPlayers)
        return;

    gContestPlayerMonIndex = GetMultiplayerId();
    gNumLinkContestPlayers = GetLinkPlayerCount();
    gLinkContestFlags = LINK_CONTEST_FLAG_IS_LINK;
    if (gWirelessCommType == 1)
        gLinkContestFlags = LINK_CONTEST_FLAG_IS_LINK | LINK_CONTEST_FLAG_IS_WIRELESS;

    // Get number of players using Emerald/FRLG
    for (i = 0; i < gNumLinkContestPlayers && (u32)(gLinkPlayers[i].version & 0xFF) - 1 > VERSION_RUBY - 1; i++)
        ;

    if (i < gNumLinkContestPlayers)
        gLinkContestFlags |= LINK_CONTEST_FLAG_HAS_RS_PLAYER;

    SwitchTaskToFollowupFunc(taskId);
}

bool32 LinkContest_TryLinkStandby(s16 *state)
{
    // Skip standby for RS cabled links
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
        return TRUE;
    
    switch (*state)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            SetLinkStandbyCallback();
            (*state)++;
        }
        return FALSE;
    case 1:
        (*state)++;
        return FALSE;
    default:
        if (IsLinkTaskFinished() != TRUE)
            return FALSE;
        else
            return TRUE;
    }
}

void Task_LinkContest_CommunicateMonsRS(u8 taskId)
{
    int i;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].tStandbyState))
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        // Send players mon
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished())
            {
                memcpy(gBlockSendBuffer, &gContestMons[gContestPlayerMonIndex], sizeof(struct ContestPokemon));
                gTasks[taskId].tState = 10;
            }
        }
        else
        {
            memcpy(gBlockSendBuffer, &gContestMons[gContestPlayerMonIndex], sizeof(struct ContestPokemon));
            gTasks[taskId].tState = 1;
        }
        break;
    case 1:
        // Wait for other players data
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
            {
                memcpy(&gContestMons[i], gBlockRecvBuffer[i], sizeof(struct ContestPokemon));
                StripPlayerAndMonNamesForLinkContest(&gContestMons[i], gLinkPlayers[i].language);
            }

            gTasks[taskId].tState++;
        }
        break;
    case 10:
        // Only if leader. Request other players data
        if (++gTasks[taskId].tTimer > 300)
        {
            SendBlockRequest(2);
            gTasks[taskId].tState = 1;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tStandbyState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateRngRS(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished() && LinkContest_SendBlock(&gRngValue, sizeof(gRngValue)) == TRUE)
                gTasks[taskId].tState++;
        }
        else
        {
            gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceived(0))
        {
            memcpy(&gRngValue, gBlockRecvBuffer[0], sizeof(gRngValue));
            memcpy(&gContestRngValue, gBlockRecvBuffer[0], sizeof(gContestRngValue));
            gTasks[taskId].tState++;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateCategoryRS(u8 taskId)
{
    int i;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].tStandbyState))
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        gBlockSendBuffer[0] = gTasks[taskId].tCategory;
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished())
                gTasks[taskId].tState = 10;
        }
        else
        {
            gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
                gTasks[taskId].tCategories(i) = gBlockRecvBuffer[i][0];

            gTasks[taskId].tState++;
        }
        break;
    case 10:
        if (++gTasks[taskId].tTimer > 10)
        {
            SendBlockRequest(2);
            gTasks[taskId].tState = 1;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tStandbyState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateMonIdxs(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(&gContestPlayerMonIndex, sizeof(gContestPlayerMonIndex)) == TRUE)
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
            gTasks[taskId].tState++;
        break;
    default:
        gTasks[taskId].tState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateMoveSelections(u8 taskId)
{
    int i;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            // Send player's move selection
            if (LinkContest_SendBlock(&eContestantStatus[gContestPlayerMonIndex].currMove, sizeof(eContestantStatus[gContestPlayerMonIndex].currMove)) == TRUE)
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            // Receive partners' move selections
            for (i = 0; i < gNumLinkContestPlayers; i++)
                eContestantStatus[i].currMove = gBlockRecvBuffer[i][0];

            gTasks[taskId].tState++;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateFinalStandings(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestMonTotalPoints, sizeof(gContestMonTotalPoints)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestMonTotalPoints, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestMonTotalPoints));
            gTasks[taskId].tState++;
        }
        break;
    case 2:
    case 5:
    case 8:
    case 11:
        if (gTasks[taskId].tDelayTimer++ > 10)
        {
            gTasks[taskId].tDelayTimer = 0;
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestMonAppealPointTotals, sizeof(gContestMonAppealPointTotals)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 4:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestMonAppealPointTotals, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestMonAppealPointTotals));
            gTasks[taskId].tState++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestMonRound2Points, sizeof(gContestMonRound2Points)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 7:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestMonRound2Points, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestMonRound2Points));
            gTasks[taskId].tState++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestFinalStandings, sizeof(gContestFinalStandings)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 10:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestFinalStandings, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestFinalStandings));
            gTasks[taskId].tState++;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateAppealsState(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(eContestantStatus, CONTESTANT_COUNT * sizeof(struct ContestantStatus)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(eContestantStatus, gBlockRecvBuffer[gContestLinkLeaderIndex], CONTESTANT_COUNT * sizeof(struct ContestantStatus));
            gTasks[taskId].tState++;
        }
        break;
    case 2:
    case 5:
    case 8:
    case 11:
        if (gTasks[taskId].tDelayTimer++ > 10)
        {
            gTasks[taskId].tDelayTimer = 0;
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestResources->appealResults, sizeof(struct ContestAppealMoveResults)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 4:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestResources->appealResults, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(struct ContestAppealMoveResults));
            gTasks[taskId].tState++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestResources->excitement, sizeof(struct ContestExcitement)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 7:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestResources->excitement, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(struct ContestExcitement));
            gTasks[taskId].tState++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestantTurnOrder, sizeof(gContestantTurnOrder)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 10:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestantTurnOrder, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestantTurnOrder));
            gTasks[taskId].tState++;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateLeaderIdsRS(u8 taskId)
{
    int i;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].tStandbyState))
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        gBlockSendBuffer[0] = 0x6E;
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished())
                gTasks[taskId].tState = 10;
        }
        else
        {
            gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            for (i = 0; i < CONTESTANT_COUNT; i++)
                gTasks[taskId].tLeaderIds(i) = gBlockRecvBuffer[i][0];

            gTasks[taskId].tState++;
        }
        break;
    case 10:
        if (++gTasks[taskId].tTimer > 10)
        {
            SendBlockRequest(2);
            gTasks[taskId].tState = 1;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tStandbyState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateRound1Points(u8 taskId)
{
    if (!LinkContest_TryLinkStandby(&gTasks[taskId].tStandbyState))
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestMonRound1Points, sizeof(gContestMonRound1Points)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestMonRound1Points, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestMonRound1Points));
            gTasks[taskId].tState++;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        gTasks[taskId].tStandbyState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void Task_LinkContest_CommunicateTurnOrder(u8 taskId)
{
    if (!LinkContest_TryLinkStandby(&gTasks[taskId].tStandbyState))
        return;

    switch (gTasks[taskId].tState)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(gContestantTurnOrder, sizeof(gContestantTurnOrder)) == 1)
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            memcpy(gContestantTurnOrder, gBlockRecvBuffer[gContestLinkLeaderIndex], sizeof(gContestantTurnOrder));
            gTasks[taskId].tState++;
        }
        break;
    default:
        gTasks[taskId].tState = 0;
        gTasks[taskId].tStandbyState = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}
