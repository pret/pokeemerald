#include "global.h"
#include "contest.h"
#include "contest_link.h"
#include "event_data.h"
#include "link.h"
#include "random.h"
#include "task.h"

static void sub_81D9F14(u8);
static void sub_81D9F30(u8);
static void sub_81D9F4C(u8);
static void sub_81D9F68(u8);
static void sub_81DA10C(u8);
static void sub_81DA138(u8);
static void sub_81DA160(u8);
static void sub_81DA244(u8);
static void sub_81DA2E8(u8);
static void sub_81DA3B8(u8);
static void sub_81DA488(u8);

#define tCategory data[9]

void sub_81D9DE4(u8 taskId)
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
    SetTaskFuncWithFollowupFunc(taskId, sub_81DA160, sub_81D9F14);
}

static void sub_81D9F14(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_81DA244, sub_81D9F30);
}

static void sub_81D9F30(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_81DA2E8, sub_81D9F4C);
}

static void sub_81D9F4C(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_81DA3B8, sub_81D9F68);
}

static void sub_81D9F68(u8 taskId)
{
    u8 i;
    u8 rank;
    int gameCleared;
    u8 contestCategories[CONTESTANT_COUNT];
    u8 data2[CONTESTANT_COUNT];

    memset(contestCategories, 0, sizeof(contestCategories));
    memset(data2, 0, sizeof(data2));

    for (i = 0; i < gNumLinkContestPlayers; i++)
        contestCategories[i] = gTasks[taskId].data[i + 1];
    
    // Ensure all players are doing the same category
    i = 0;
    if (i < gNumLinkContestPlayers)
    {
        while (++i < gNumLinkContestPlayers)
        {
            if (contestCategories[0] != contestCategories[i])
                break;
        }
    }

    if (i == gNumLinkContestPlayers)
        gSpecialVar_0x8004 = FALSE;
    else
        gSpecialVar_0x8004 = TRUE;

    for (i = 0; i < gNumLinkContestPlayers; i++)
        data2[i] = gTasks[taskId].data[i + 5];
    
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
        
        gameCleared = 1;
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            if (!gContestMons[i].gameCleared)
            {
                gameCleared = 0;
                break;
            }
        }

        SetLinkAIContestants(contestCategories[0], rank, gameCleared);
    }

    gUnknown_02039F2B = sub_80F86E0(data2);
    if (gNumLinkContestPlayers < CONTESTANT_COUNT)
        SetTaskFuncWithFollowupFunc(taskId, sub_81DA488, sub_81DA10C);
    else
        gTasks[taskId].func = sub_81DA10C;
}

static void sub_81DA10C(u8 taskId)
{
    sub_80DB09C(gSpecialVar_ContestCategory);
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateRound1Points, sub_81DA138);
}

static void sub_81DA138(u8 taskId)
{
    SortContestants(FALSE);
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateTurnOrder, sub_80F8714);
}

static void sub_81DA160(u8 taskId)
{
    int i;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
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

static void sub_81DA244(u8 taskId)
{
    if (!sub_80FC670(&gTasks[taskId].data[12]))
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
            
            if (LinkContest_SendBlock(&gRngValue, sizeof(gRngValue)) == 1)
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
            memcpy(&gRngValue, gBlockRecvBuffer[0], sizeof(gRngValue));
            memcpy(&gContestRngValue, gBlockRecvBuffer[0], sizeof(gContestRngValue));
            gTasks[taskId].data[0]++;
        }
        break;
    }
}

static void sub_81DA2E8(u8 taskId)
{
    int i;
    u16 data[4];
    u16 var0;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
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
            var0 = 0x6E;
            if (LinkContest_SendBlock(&var0, sizeof(var0)) == 1)
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

static void sub_81DA3B8(u8 taskId)
{
    int i;
    u16 data[CONTESTANT_COUNT];
    u16 category;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
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

static void sub_81DA488(u8 taskId)
{
    int i;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
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
