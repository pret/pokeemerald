#include "global.h"
#include "contest.h"
#include "contest_link.h"
#include "event_data.h"
#include "link.h"
#include "random.h"
#include "task.h"

/*
    The functions in this file handle preliminary communication
    for Emerald-only link contests. If the link contest has an RS
    player linked, none of these functions are used.

    The equivalent functions for RS-linked contests are spread
    between contest_link.c and contest_util.c, and are suffixed RS
    instead of Em
*/

static void Task_LinkContest_CommunicateMonsEm(u8);
static void Task_LinkContest_StartCommunicateRngEm(u8);
static void Task_LinkContest_CommunicateRngEm(u8);
static void Task_LinkContest_StartCommunicateLeaderIdsEm(u8);
static void Task_LinkContest_CommunicateLeaderIdsEm(u8);
static void Task_LinkContest_StartCommunicateCategoryEm(u8);
static void Task_LinkContest_CommunicateCategoryEm(u8);
static void Task_LinkContest_SetUpContestEm(u8);
static void Task_LinkContest_CommunicateAIMonsEm(u8);
static void Task_LinkContest_CalculateRound1Em(u8);
static void Task_LinkContest_CalculateTurnOrderEm(u8);

#define tCategory data[9]

void Task_LinkContest_StartCommunicationEm(u8 taskId)
{
    int gameCleared;

    switch (gTasks[taskId].tCategory)
    {
    case CONTEST_CATEGORY_COOL:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_COOL_RIBBON);
        break;
    case CONTEST_CATEGORY_BEAUTY:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_BEAUTY_RIBBON);
        break;
    case CONTEST_CATEGORY_CUTE:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_CUTE_RIBBON);
        break;
    case CONTEST_CATEGORY_SMART:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_SMART_RIBBON);
        break;
    case CONTEST_CATEGORY_TOUGH:
    default:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_TOUGH_RIBBON);
        break;
    }

    gContestMons[gContestPlayerMonIndex].highestRank = gHighestRibbonRank;
    gameCleared = FlagGet(FLAG_SYS_GAME_CLEAR) > 0;
    gContestMons[gContestPlayerMonIndex].gameCleared = gameCleared;
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateMonsEm, Task_LinkContest_StartCommunicateRngEm);
}

static void Task_LinkContest_StartCommunicateRngEm(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateRngEm, Task_LinkContest_StartCommunicateLeaderIdsEm);
}

static void Task_LinkContest_StartCommunicateLeaderIdsEm(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateLeaderIdsEm, Task_LinkContest_StartCommunicateCategoryEm);
}

static void Task_LinkContest_StartCommunicateCategoryEm(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateCategoryEm, Task_LinkContest_SetUpContestEm);
}

static void Task_LinkContest_SetUpContestEm(u8 taskId)
{
    u8 i;
    u8 rank;
    int gameCleared;
    u8 categories[CONTESTANT_COUNT];
    u8 leaderIds[CONTESTANT_COUNT];

    memset(categories, 0, sizeof(categories));
    memset(leaderIds, 0, sizeof(leaderIds));

    for (i = 0; i < gNumLinkContestPlayers; i++)
        categories[i] = gTasks[taskId].data[i + 1];
    
    // Ensure all players are doing the same category
    for (i = 0; i < gNumLinkContestPlayers && categories[0] == categories[i]; i++)
        ;

    if (i == gNumLinkContestPlayers)
        gSpecialVar_0x8004 = FALSE; // Category choices the same
    else
        gSpecialVar_0x8004 = TRUE; // Category choices differ

    for (i = 0; i < gNumLinkContestPlayers; i++)
        leaderIds[i] = gTasks[taskId].data[i + 5];
    
    // If < 4 players and player is leader, set AI contestants based on rank and game clear
    if (gNumLinkContestPlayers != CONTESTANT_COUNT && GetMultiplayerId() == 0)
    {
        rank = gContestMons[0].highestRank;
        for (i = 1; i < gNumLinkContestPlayers; i++)
        {
            if (rank < gContestMons[i].highestRank)
                rank = gContestMons[i].highestRank;
        }

        if (rank)
            rank--;
        
        gameCleared = TRUE;
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            if (!gContestMons[i].gameCleared)
            {
                gameCleared = FALSE;
                break;
            }
        }

        SetLinkAIContestants(categories[0], rank, gameCleared);
    }

    // Assign link leader. After initial communication all players will read data only from them
    gContestLinkLeaderIndex = LinkContest_GetLeaderIndex(leaderIds);

    if (gNumLinkContestPlayers < CONTESTANT_COUNT)
        SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateAIMonsEm, Task_LinkContest_CalculateRound1Em);
    else
        gTasks[taskId].func = Task_LinkContest_CalculateRound1Em;
}

static void Task_LinkContest_CalculateRound1Em(u8 taskId)
{
    CalculateRound1Points(gSpecialVar_ContestCategory);
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateRound1Points, Task_LinkContest_CalculateTurnOrderEm);
}

static void Task_LinkContest_CalculateTurnOrderEm(u8 taskId)
{
    SortContestants(FALSE);
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateTurnOrder, Task_LinkContest_FinalizeConnection);
}

static void Task_LinkContest_CommunicateMonsEm(u8 taskId)
{
    int i;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    case 0:
        if (IsLinkTaskFinished())
        {
            if (LinkContest_SendBlock(&gContestMons[gContestPlayerMonIndex], sizeof(struct ContestPokemon)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
            {
                memcpy(&gContestMons[i], gBlockRecvBuffer[i], sizeof(struct ContestPokemon));
                StripPlayerAndMonNamesForLinkContest(&gContestMons[i], gLinkPlayers[i].language);
            }

            gTasks[taskId].data[0]++;
        }
        break;
    }
}

static void Task_LinkContest_CommunicateRngEm(u8 taskId)
{
    if (!LinkContest_TryLinkStandby(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    case 0:
        if (GetMultiplayerId() == 0)
        {
            // Only the leader sends the RNG seed
            if (!IsLinkTaskFinished())
                return;
            
            if (LinkContest_SendBlock(&gRngValue, sizeof(gRngValue)) == 1)
                gTasks[taskId].data[0]++;
        }
        else
        {
            // Other link members skip to waiting
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        // Wait to receive RNG data
        if (LinkContest_GetBlockReceived(0))
        {
            memcpy(&gRngValue, gBlockRecvBuffer[0], sizeof(gRngValue));
            memcpy(&gContestRngValue, gBlockRecvBuffer[0], sizeof(gContestRngValue));
            gTasks[taskId].data[0]++;
        }
        break;
    }
}

static void Task_LinkContest_CommunicateLeaderIdsEm(u8 taskId)
{
    int i;
    u16 data[CONTESTANT_COUNT];
    u16 leaderId;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    case 0:
        if (IsLinkTaskFinished())
        {
            leaderId = 0x6E;
            if (LinkContest_SendBlock(&leaderId, sizeof(leaderId)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
            {
                data[i] = gBlockRecvBuffer[i][0];
                gTasks[taskId].data[i + 5] = data[i];
            }

            gTasks[taskId].data[0]++;
        }
        break;
    }
}

static void Task_LinkContest_CommunicateCategoryEm(u8 taskId)
{
    int i;
    u16 data[CONTESTANT_COUNT];
    u16 category;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    case 0:
        if (IsLinkTaskFinished())
        {
            category = gTasks[taskId].tCategory;
            if (LinkContest_SendBlock(&category, sizeof(category)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceivedFromAllPlayers())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
            {
                data[i] = gBlockRecvBuffer[i][0];
                gTasks[taskId].data[i + 1] = data[i];
            }

            gTasks[taskId].data[0]++;
        }
        break;
    }
}

static void Task_LinkContest_CommunicateAIMonsEm(u8 taskId)
{
    int i;

    if (!LinkContest_TryLinkStandby(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    case 0:
        if (GetMultiplayerId() == 0)
        {
            if (!IsLinkTaskFinished())
                return;
            
            if (LinkContest_SendBlock(&gContestMons[gNumLinkContestPlayers], (CONTESTANT_COUNT - gNumLinkContestPlayers) * sizeof(struct ContestPokemon)) == 1)
                gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (LinkContest_GetBlockReceived(0))
        {
            memcpy(&gContestMons[gNumLinkContestPlayers], gBlockRecvBuffer[0], (CONTESTANT_COUNT - gNumLinkContestPlayers) * sizeof(struct ContestPokemon));
            for (i = gNumLinkContestPlayers; i < CONTESTANT_COUNT; i++)
                StripPlayerAndMonNamesForLinkContest(&gContestMons[i], gLinkPlayers[0].language);

            gTasks[taskId].data[0]++;
        }
        break;
    }
}
