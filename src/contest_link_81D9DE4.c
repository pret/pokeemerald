#include "global.h"
#include "contest.h"
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

void sub_81D9DE4(u8 taskId)
{
    int gameCleared;

    switch (gTasks[taskId].data[9])
    {
    case 0:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_COOL_RIBBON);
        break;
    case 1:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_BEAUTY_RIBBON);
        break;
    case 2:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_CUTE_RIBBON);
        break;
    case 3:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_SMART_RIBBON);
        break;
    case 4:
    default:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_TOUGH_RIBBON);
        break;
    }

    gContestMons[gContestPlayerMonIndex].unk2C[0] = gHighestRibbonRank;
    gameCleared = FlagGet(FLAG_SYS_GAME_CLEAR) > 0;
    gContestMons[gContestPlayerMonIndex].unk2C[1] = gameCleared;
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
    u8 data1[4];
    u8 data2[4];

    memset(data1, 0, sizeof(data1));
    memset(data2, 0, sizeof(data2));

    for (i = 0; i < gNumLinkContestPlayers; i++)
        data1[i] = gTasks[taskId].data[i + 1];
    
    i = 0;
    if (i < gNumLinkContestPlayers)
    {
        while (++i < gNumLinkContestPlayers)
        {
            if (data1[0] != data1[i])
                break;
        }
    }

    if (i == gNumLinkContestPlayers)
        gSpecialVar_0x8004 = 0;
    else
        gSpecialVar_0x8004 = 1;

    for (i = 0; i < gNumLinkContestPlayers; i++)
        data2[i] = gTasks[taskId].data[i + 5];
    
    if (gNumLinkContestPlayers != 4 && GetMultiplayerId() == 0)
    {
        rank = gContestMons[0].unk2C[0];
        for (i = 1; i < gNumLinkContestPlayers; i++)
        {
            if (rank < gContestMons[i].unk2C[0])
                rank = gContestMons[i].unk2C[0];
        }

        if (rank)
            rank--;
        
        gameCleared = 1;
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            if (!gContestMons[i].unk2C[1])
            {
                gameCleared = 0;
                break;
            }
        }

        sub_80DACBC(data1[0], rank, gameCleared);
    }

    gUnknown_02039F2B = sub_80F86E0(data2);
    if (gNumLinkContestPlayers < 4)
        SetTaskFuncWithFollowupFunc(taskId, sub_81DA488, sub_81DA10C);
    else
        gTasks[taskId].func = sub_81DA10C;
}

static void sub_81DA10C(u8 taskId)
{
    sub_80DB09C(gSpecialVar_ContestCategory);
    SetTaskFuncWithFollowupFunc(taskId, sub_80FCF40, sub_81DA138);
}

static void sub_81DA138(u8 taskId)
{
    SortContestants(FALSE);
    SetTaskFuncWithFollowupFunc(taskId, sub_80FCFD0, sub_80F8714);
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
            if (sub_80FC4F4(&gContestMons[gContestPlayerMonIndex], sizeof(struct ContestPokemon)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
            {
                memcpy(&gContestMons[i], gBlockRecvBuffer[i], sizeof(struct ContestPokemon));
                sub_80DFA08(&gContestMons[i], gLinkPlayers[i].language);
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
            
            if (sub_80FC4F4(&gRngValue, sizeof(gRngValue)) == 1)
                gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC530(0))
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
            if (sub_80FC4F4(&var0, sizeof(var0)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
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
            var0 = gTasks[taskId].data[9];
            if (sub_80FC4F4(&var0, sizeof(var0)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
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
            
            if (sub_80FC4F4(&gContestMons[gNumLinkContestPlayers], (4 - gNumLinkContestPlayers) * sizeof(struct ContestPokemon)) == 1)
                gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC530(0))
        {
            memcpy(&gContestMons[gNumLinkContestPlayers], gBlockRecvBuffer[0], (4 - gNumLinkContestPlayers) * sizeof(struct ContestPokemon));
            for (i = gNumLinkContestPlayers; i < 4; i++)
                sub_80DFA08(&gContestMons[i], gLinkPlayers[0].language);

            gTasks[taskId].data[0]++;
        }
        break;
    }
}
