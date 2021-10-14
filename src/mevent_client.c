#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "overworld.h"
#include "script.h"
#include "battle_tower.h"
#include "mevent.h"
#include "mystery_event_script.h"
#include "mevent_client.h"

enum {
    FUNC_INIT,
    FUNC_DONE,
    FUNC_RECV,
    FUNC_SEND,
    FUNC_RUN,
    FUNC_WAIT,
    FUNC_6,
    FUNC_7,
};

EWRAM_DATA static struct MysteryGiftClient * sClient = NULL;

static void MysteryGiftClient_Init(struct MysteryGiftClient *, u32, u32);
static u32 MysteryGiftClient_CallFunc(struct MysteryGiftClient *);
static void MysteryGiftClient_Free(struct MysteryGiftClient *);

extern const struct MysteryGiftClientCmd gUnknown_082F2598[];

void MysteryGiftClient_Create(bool32 isWonderNews)
{
    sClient = AllocZeroed(sizeof(*sClient));
    MysteryGiftClient_Init(sClient, 1, 0);
    sClient->isWonderNews = isWonderNews;
}

u32 MysteryGiftClient_Run(u16 * endVal)
{
    u32 result;
    if (sClient == NULL)
        return CLI_RET_END;
    result = MysteryGiftClient_CallFunc(sClient);
    if (result == CLI_RET_END)
    {
        *endVal = sClient->param;
        MysteryGiftClient_Free(sClient);
        Free(sClient);
        sClient = NULL;
    }
    return result;
}

void MysteryGiftClient_AdvanceState(void)
{
    sClient->funcState++;
}

void * mevent_client_get_buffer(void)
{
    return sClient->buffer;
}

void MysteryGiftClient_SetParam(u32 val)
{
    sClient->param = val;
}

static void MysteryGiftClient_Init(struct MysteryGiftClient * client, u32 sendPlayerNo, u32 recvPlayerNo)
{
    client->unk_00 = 0;
    client->funcId = FUNC_INIT;
    client->funcState = 0;
    client->sendBuffer = AllocZeroed(ME_SEND_BUF_SIZE);
    client->recvBuffer = AllocZeroed(ME_SEND_BUF_SIZE);
    client->cmdBuffer = AllocZeroed(ME_SEND_BUF_SIZE);
    client->buffer = AllocZeroed(0x40);
    MysteryGiftLink_Init(&client->link, sendPlayerNo, recvPlayerNo);
}

static void MysteryGiftClient_Free(struct MysteryGiftClient * client)
{
    Free(client->sendBuffer);
    Free(client->recvBuffer);
    Free(client->cmdBuffer);
    Free(client->buffer);
}

static void MysteryGiftClient_CopyRecvScript(struct MysteryGiftClient * client)
{
    memcpy(client->cmdBuffer, client->recvBuffer, ME_SEND_BUF_SIZE);
    client->cmdidx = 0;
}

static void MysteryGiftClient_InitSend(struct MysteryGiftClient * client, u32 ident, u32 word)
{
    CpuFill32(0, client->sendBuffer, ME_SEND_BUF_SIZE);
    *(u32 *)client->sendBuffer = word;
    MysteryGiftLink_InitSend(&client->link, ident, client->sendBuffer, sizeof(u32));
}

static u32 Client_Init(struct MysteryGiftClient * client)
{
    memcpy(client->cmdBuffer, gUnknown_082F2598, ME_SEND_BUF_SIZE);
    client->cmdidx = 0;
    client->funcId = FUNC_RUN;
    client->funcState = 0;
    return CLI_RET_INIT;
}

static u32 Client_Done(struct MysteryGiftClient * client)
{
    return CLI_RET_END;
}


static u32 Client_Recv(struct MysteryGiftClient * client)
{
    if (MysteryGiftLink_Recv(&client->link))
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_1;
}

static u32 Client_Send(struct MysteryGiftClient * client)
{
    if (MysteryGiftLink_Send(&client->link))
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_1;
}

static u32 Client_Run(struct MysteryGiftClient * client)
{
    // process command
    struct MysteryGiftClientCmd * cmd = &client->cmdBuffer[client->cmdidx];
    client->cmdidx++;
    switch (cmd->instr)
    {
    case CLI_NONE:
        break;
    case CLI_RETURN:
        client->param = cmd->parameter; // Set for endVal in MysteryGiftClient_Run
        client->funcId = FUNC_DONE;
        client->funcState = 0;
        break;
    case CLI_RECV:
        MysteryGiftLink_InitRecv(&client->link, cmd->parameter, client->recvBuffer);
        client->funcId = FUNC_RECV;
        client->funcState = 0;
        break;
    case CLI_SEND_LOADED:
        // Send without a MysteryGiftLink_InitSend
        // Sends whatever has been loaded already
        client->funcId = FUNC_SEND;
        client->funcState = 0;
        break;
    case CLI_20:
        MysteryGiftLink_InitSend(&client->link, 0x14, client->sendBuffer, 0);
        client->funcId = FUNC_SEND;
        client->funcState = 0;
        break;
    case CLI_SEND_STAT:
        MysteryGiftClient_InitSend(client, 0x12, GetGameStat(cmd->parameter));
        client->funcId = FUNC_SEND;
        client->funcState = 0;
        break;
    case CLI_COPY_RECV_IF_N:
        if (client->param == FALSE)
            MysteryGiftClient_CopyRecvScript(client);
        break;
    case CLI_COPY_RECV_IF:
        if (client->param == TRUE)
            MysteryGiftClient_CopyRecvScript(client);
        break;
    case CLI_COPY_RECV:
        MysteryGiftClient_CopyRecvScript(client);
        break;
    case CLI_5:
        memcpy(client->buffer, client->recvBuffer, 0x40);
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_2;
    case CLI_11:
        memcpy(client->buffer, client->recvBuffer, 0x40);
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_3;
    case CLI_12:
        memcpy(client->buffer, client->recvBuffer, 0x40);
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_5;
    case CLI_ASK_TOSS:
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_ASK_TOSS;
    case CLI_8:
        sub_801B580(client->sendBuffer, client->isWonderNews);
        MysteryGiftLink_InitSend(&client->link, 0x11, client->sendBuffer, sizeof(struct MEventStruct_Unk1442CC));
        break;
    case CLI_LOAD_TOSS_RESPONSE:
        // param here is set by MG_STATE_LINK_ASK_TOSS or MG_STATE_LINK_ASK_TOSS_UNRECEIVED
        MysteryGiftClient_InitSend(client, 0x13, client->param);
        break;
    case CLI_10:
        SaveWonderCard(client->recvBuffer);
        break;
    case CLI_9:
        if (!sub_801B1A4(client->recvBuffer))
        {
            SaveWonderNews(client->recvBuffer);
            MysteryGiftClient_InitSend(client, 0x13, 0);
        }
        else
            MysteryGiftClient_InitSend(client, 0x13, 1);
        break;
    case CLI_15:
        client->funcId = FUNC_6;
        client->funcState = 0;
        break;
    case CLI_16:
        sub_801B508(client->recvBuffer);
        break;
    case CLI_17:
        InitRamScript_NoObjectEvent(client->recvBuffer, 1000);
        break;
    case CLI_RECV_EREADER_TRAINER:
        memcpy(&gSaveBlock2Ptr->frontier.ereaderTrainer, client->recvBuffer, sizeof(gSaveBlock2Ptr->frontier.ereaderTrainer));
        ValidateEReaderTrainer();
        break;
    case CLI_21:
        memcpy(gDecompressionBuffer, client->recvBuffer, ME_SEND_BUF_SIZE);
        client->funcId = FUNC_7;
        client->funcState = 0;
        break;
    }

    return CLI_RET_1;
}

static u32 Client_Wait(struct MysteryGiftClient * client)
{
    if (client->funcState)
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_1;
}

static u32 Client_6(struct MysteryGiftClient * client)
{
    switch (client->funcState)
    {
    case 0:
        InitMysteryGiftScriptContext(client->recvBuffer);
        client->funcState++;
        break;
    case 1:
        if (!RunMysteryGiftScriptContextCommand(&client->param))
        {
            client->funcId = FUNC_RUN;
            client->funcState = 0;
        }
        break;
    }
    return CLI_RET_1;
}

static u32 Client_7(struct MysteryGiftClient * client)
{
    // exec arbitrary code
    u32 (*func)(u32 *, struct SaveBlock2 *, struct SaveBlock1 *) = (void *)gDecompressionBuffer;
    if (func(&client->param, gSaveBlock2Ptr, gSaveBlock1Ptr) == 1)
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_1;
}

static u32 MysteryGiftClient_CallFunc(struct MysteryGiftClient * client)
{
    u32 (*funcs[])(struct MysteryGiftClient *) = {
        [FUNC_INIT] = Client_Init,
        [FUNC_DONE] = Client_Done,
        [FUNC_RECV] = Client_Recv,
        [FUNC_SEND] = Client_Send,
        [FUNC_RUN]  = Client_Run,
        [FUNC_WAIT] = Client_Wait,
        [FUNC_6]    = Client_6,
        [FUNC_7]    = Client_7
    };
    return funcs[client->funcId](client);
}
