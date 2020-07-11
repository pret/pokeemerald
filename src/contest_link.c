#include "global.h"
#include "contest.h"
#include "decompress.h"
#include "event_data.h"
#include "link.h"
#include "pokemon.h"
#include "random.h"
#include "task.h"
#include "contest_link.h"
#include "constants/flags.h"

static void sub_80FC5C0(u8);
static void sub_80FC5DC(u8);

bool32 sub_80FC4F4(void *src, u16 size)
{
    memcpy(gDecompressionBuffer, src, size);
    if (SendBlock(bitmask_all_link_players_but_self(), gDecompressionBuffer, size))
        return TRUE;
    else
        return FALSE;
}

bool8 sub_80FC530(u8 arg0)
{
    u8 mask = (1 << arg0);
    if (!(GetBlockReceivedStatus() & mask))
    {
        return FALSE;
    }
    else
    {
        ResetBlockReceivedFlag(arg0);
        return TRUE;
    }
}

bool8 sub_80FC55C(void)
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

void sub_80FC580(u8 taskId)
{
    u8 i;

    for (i = 0; i < 4; i++)
        gBlockRecvBuffer[i][0] = 0xFF;
    
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = sub_80FC5C0;
}

static void sub_80FC5C0(u8 taskId)
{
    gTasks[taskId].func = sub_80FC5DC;
}

static void sub_80FC5DC(u8 taskId)
{
    int i;

    if (!gReceivedRemoteLinkPlayers)
        return;

    gContestPlayerMonIndex = GetMultiplayerId();
    gNumLinkContestPlayers = GetLinkPlayerCount();
    gLinkContestFlags = LINK_CONTEST_FLAG_IS_LINK;
    if (gWirelessCommType == 1)
        gLinkContestFlags = LINK_CONTEST_FLAG_IS_LINK | LINK_CONTEST_FLAG_IS_WIRELESS;

    for (i = 0; i < gNumLinkContestPlayers && (u32)(gLinkPlayers[i].version & 0xFF) - 1 > VERSION_RUBY - 1; i++)
        ;

    if (i < gNumLinkContestPlayers)
        gLinkContestFlags |= LINK_CONTEST_FLAG_HAS_RS_PLAYER;

    SwitchTaskToFollowupFunc(taskId);
}

bool32 sub_80FC670(s16 *arg0)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
        return TRUE;
    
    switch (*arg0)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            sub_800ADF8();
            (*arg0)++;
        }
        return FALSE;
    case 1:
        (*arg0)++;
        return FALSE;
    default:
        if (IsLinkTaskFinished() != TRUE)
            return FALSE;
        else
            return TRUE;
    }
}

void sub_80FC6BC(u8 taskId)
{
    int i;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished())
            {
                memcpy(gBlockSendBuffer, &gContestMons[gContestPlayerMonIndex], sizeof(struct ContestPokemon));
                gTasks[taskId].data[0] = 10;
            }
        }
        else
        {
            memcpy(gBlockSendBuffer, &gContestMons[gContestPlayerMonIndex], sizeof(struct ContestPokemon));
            gTasks[taskId].data[0] = 1;
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
    case 10:
        if (++gTasks[taskId].data[11] > 300)
        {
            sub_800A4D8(2);
            gTasks[taskId].data[0] = 1;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[11] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FC804(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished() && sub_80FC4F4(&gRngValue, sizeof(gRngValue)) == TRUE)
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
    default:
        gTasks[taskId].data[0] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FC894(u8 taskId)
{
    int i;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gBlockSendBuffer[0] = gTasks[taskId].data[9];
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished())
                gTasks[taskId].data[0] = 10;
        }
        else
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
                gTasks[taskId].data[i + 1] = gBlockRecvBuffer[i][0];

            gTasks[taskId].data[0]++;
        }
        break;
    case 10:
        if (++gTasks[taskId].data[11] > 10)
        {
            sub_800A4D8(2);
            gTasks[taskId].data[0] = 1;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[11] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FC998(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(&gContestPlayerMonIndex, sizeof(gContestPlayerMonIndex)) == TRUE)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
            gTasks[taskId].data[0]++;
        break;
    default:
        gTasks[taskId].data[0] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FC9F8(u8 taskId)
{
    int i;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(&eContestantStatus[gContestPlayerMonIndex].currMove, sizeof(eContestantStatus[gContestPlayerMonIndex].currMove)) == TRUE)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            for (i = 0; i < gNumLinkContestPlayers; i++)
                eContestantStatus[i].currMove = gBlockRecvBuffer[i][0];

            gTasks[taskId].data[0]++;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FCACC(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestMonTotalPoints, sizeof(gContestMonTotalPoints)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            memcpy(gContestMonTotalPoints, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gContestMonTotalPoints));
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
    case 5:
    case 8:
    case 11:
        if (gTasks[taskId].data[1]++ > 10)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gUnknown_02039F10, sizeof(gUnknown_02039F10)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 4:
        if (sub_80FC55C())
        {
            memcpy(gUnknown_02039F10, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gUnknown_02039F10));
            gTasks[taskId].data[0]++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestMonRound2Points, sizeof(gContestMonRound2Points)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 7:
        if (sub_80FC55C())
        {
            memcpy(gContestMonRound2Points, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gContestMonRound2Points));
            gTasks[taskId].data[0]++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestFinalStandings, sizeof(gContestFinalStandings)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 10:
        if (sub_80FC55C())
        {
            memcpy(gContestFinalStandings, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gContestFinalStandings));
            gTasks[taskId].data[0]++;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FCC88(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(eContestantStatus, 4 * sizeof(struct ContestantStatus)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            memcpy(eContestantStatus, gBlockRecvBuffer[gUnknown_02039F2B], 4 * sizeof(struct ContestantStatus));
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
    case 5:
    case 8:
    case 11:
        if (gTasks[taskId].data[1]++ > 10)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestResources->field_8, sizeof(struct UnknownContestStruct7)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 4:
        if (sub_80FC55C())
        {
            memcpy(gContestResources->field_8, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(struct UnknownContestStruct7));
            gTasks[taskId].data[0]++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestResources->field_10, sizeof(struct UnknownContestStruct5)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 7:
        if (sub_80FC55C())
        {
            memcpy(gContestResources->field_10, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(struct UnknownContestStruct5));
            gTasks[taskId].data[0]++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestantTurnOrder, sizeof(gContestantTurnOrder)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 10:
        if (sub_80FC55C())
        {
            memcpy(gContestantTurnOrder, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gContestantTurnOrder));
            gTasks[taskId].data[0]++;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FCE48(u8 taskId)
{
    int i;

    if (!sub_80FC670(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gBlockSendBuffer[0] = 0x6E;
        if (GetMultiplayerId() == 0)
        {
            if (IsLinkTaskFinished())
                gTasks[taskId].data[0] = 10;
        }
        else
        {
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            for (i = 0; i < 4; i++)
                gTasks[taskId].data[i + 5] = gBlockRecvBuffer[i][0];

            gTasks[taskId].data[0]++;
        }
        break;
    case 10:
        if (++gTasks[taskId].data[11] > 10)
        {
            sub_800A4D8(2);
            gTasks[taskId].data[0] = 1;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[11] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FCF40(u8 taskId)
{
    if (!sub_80FC670(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestMonConditions, sizeof(gContestMonConditions)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            memcpy(gContestMonConditions, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gContestMonConditions));
            gTasks[taskId].data[0]++;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}

void sub_80FCFD0(u8 taskId)
{
    if (!sub_80FC670(&gTasks[taskId].data[12]))
        return;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            if (sub_80FC4F4(gContestantTurnOrder, sizeof(gContestantTurnOrder)) == 1)
                gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (sub_80FC55C())
        {
            memcpy(gContestantTurnOrder, gBlockRecvBuffer[gUnknown_02039F2B], sizeof(gContestantTurnOrder));
            gTasks[taskId].data[0]++;
        }
        break;
    default:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[12] = 0;
        SwitchTaskToFollowupFunc(taskId);
        break;
    }
}
