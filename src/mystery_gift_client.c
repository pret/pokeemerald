#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "overworld.h"
#include "script.h"
#include "battle_tower.h"
#include "mystery_gift.h"
#include "mystery_event_script.h"
#include "mystery_gift_client.h"

enum {
    FUNC_INIT,
    FUNC_DONE,
    FUNC_RECV,
    FUNC_SEND,
    FUNC_RUN,
    FUNC_WAIT,
    FUNC_RUN_MEVENT,
    FUNC_RUN_BUFFER,
};

EWRAM_DATA static struct MysteryGiftClient * sClient = NULL;

static void MysteryGiftClient_Init(struct MysteryGiftClient *, u32, u32);
static u32 MysteryGiftClient_CallFunc(struct MysteryGiftClient *);
static void MysteryGiftClient_Free(struct MysteryGiftClient *);

extern const struct MysteryGiftClientCmd gMysteryGiftClientScript_Init[];

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

void * MysteryGiftClient_GetMsg(void)
{
    return sClient->msg;
}

void MysteryGiftClient_SetParam(u32 val)
{
    sClient->param = val;
}

static void MysteryGiftClient_Init(struct MysteryGiftClient * client, u32 sendPlayerId, u32 recvPlayerId)
{
    client->unused = 0;
    client->funcId = FUNC_INIT;
    client->funcState = 0;
    client->sendBuffer = AllocZeroed(MG_LINK_BUFFER_SIZE);
    client->recvBuffer = AllocZeroed(MG_LINK_BUFFER_SIZE);
    client->script = AllocZeroed(MG_LINK_BUFFER_SIZE);
    client->msg = AllocZeroed(CLIENT_MAX_MSG_SIZE);
    MysteryGiftLink_Init(&client->link, sendPlayerId, recvPlayerId);
}

static void MysteryGiftClient_Free(struct MysteryGiftClient * client)
{
    Free(client->sendBuffer);
    Free(client->recvBuffer);
    Free(client->script);
    Free(client->msg);
}

static void MysteryGiftClient_CopyRecvScript(struct MysteryGiftClient * client)
{
    memcpy(client->script, client->recvBuffer, MG_LINK_BUFFER_SIZE);
    client->cmdidx = 0;
}

static void MysteryGiftClient_InitSendWord(struct MysteryGiftClient * client, u32 ident, u32 word)
{
    CpuFill32(0, client->sendBuffer, MG_LINK_BUFFER_SIZE);
    *(u32 *)client->sendBuffer = word;
    MysteryGiftLink_InitSend(&client->link, ident, client->sendBuffer, sizeof(word));
}

static u32 Client_Init(struct MysteryGiftClient * client)
{
    memcpy(client->script, gMysteryGiftClientScript_Init, MG_LINK_BUFFER_SIZE);
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
    return CLI_RET_ACTIVE;
}

static u32 Client_Send(struct MysteryGiftClient * client)
{
    if (MysteryGiftLink_Send(&client->link))
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_ACTIVE;
}

static u32 Client_Run(struct MysteryGiftClient * client)
{
    // process command
    struct MysteryGiftClientCmd * cmd = &client->script[client->cmdidx];
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
    case CLI_SEND_READY_END:
        MysteryGiftLink_InitSend(&client->link, MG_LINKID_READY_END, client->sendBuffer, 0);
        client->funcId = FUNC_SEND;
        client->funcState = 0;
        break;
    case CLI_SEND_STAT:
        MysteryGiftClient_InitSendWord(client, MG_LINKID_GAME_STAT, GetGameStat(cmd->parameter));
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
    case CLI_YES_NO:
        memcpy(client->msg, client->recvBuffer, CLIENT_MAX_MSG_SIZE);
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_YES_NO;
    case CLI_PRINT_MSG:
        memcpy(client->msg, client->recvBuffer, CLIENT_MAX_MSG_SIZE);
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_PRINT_MSG;
    case CLI_COPY_MSG:
        memcpy(client->msg, client->recvBuffer, CLIENT_MAX_MSG_SIZE);
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_COPY_MSG;
    case CLI_ASK_TOSS:
        client->funcId = FUNC_WAIT;
        client->funcState = 0;
        return CLI_RET_ASK_TOSS;
    case CLI_LOAD_GAME_DATA:
        MysteryGift_LoadLinkGameData(client->sendBuffer, client->isWonderNews);
        MysteryGiftLink_InitSend(&client->link, MG_LINKID_GAME_DATA, client->sendBuffer, sizeof(struct MysteryGiftLinkGameData));
        break;
    case CLI_LOAD_TOSS_RESPONSE:
        // param here is set by MG_STATE_LINK_ASK_TOSS or MG_STATE_LINK_ASK_TOSS_UNRECEIVED
        MysteryGiftClient_InitSendWord(client, MG_LINKID_RESPONSE, client->param);
        break;
    case CLI_SAVE_CARD:
        SaveWonderCard(client->recvBuffer);
        break;
    case CLI_SAVE_NEWS:
        if (!IsWonderNewsSameAsSaved(client->recvBuffer))
        {
            SaveWonderNews(client->recvBuffer);
            MysteryGiftClient_InitSendWord(client, MG_LINKID_RESPONSE, FALSE);
        }
        else
        {
            // Wonder News has already been saved (or is invalid).
            // Prepare a signal to indicate it was not saved.
            MysteryGiftClient_InitSendWord(client, MG_LINKID_RESPONSE, TRUE);
        }
        break;
    case CLI_RUN_MEVENT_SCRIPT:
        client->funcId = FUNC_RUN_MEVENT;
        client->funcState = 0;
        break;
    case CLI_SAVE_STAMP:
        MysteryGift_TrySaveStamp(client->recvBuffer);
        break;
    case CLI_SAVE_RAM_SCRIPT:
        InitRamScript_NoObjectEvent(client->recvBuffer, 1000);
        break;
    case CLI_RECV_EREADER_TRAINER:
        memcpy(&gSaveBlock2Ptr->frontier.ereaderTrainer, client->recvBuffer, sizeof(gSaveBlock2Ptr->frontier.ereaderTrainer));
        ValidateEReaderTrainer();
        break;
    case CLI_RUN_BUFFER_SCRIPT:
        memcpy(gDecompressionBuffer, client->recvBuffer, MG_LINK_BUFFER_SIZE);
        client->funcId = FUNC_RUN_BUFFER;
        client->funcState = 0;
        break;
    }

    return CLI_RET_ACTIVE;
}

static u32 Client_Wait(struct MysteryGiftClient * client)
{
    if (client->funcState)
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_ACTIVE;
}

static u32 Client_RunMysteryEventScript(struct MysteryGiftClient * client)
{
    switch (client->funcState)
    {
    case 0:
        InitMysteryEventScriptContext(client->recvBuffer);
        client->funcState++;
        break;
    case 1:
        if (!RunMysteryEventScriptContextCommand(&client->param))
        {
            client->funcId = FUNC_RUN;
            client->funcState = 0;
        }
        break;
    }
    return CLI_RET_ACTIVE;
}

static u32 Client_RunBufferScript(struct MysteryGiftClient * client)
{
    // exec arbitrary code
    u32 (*func)(u32 *, struct SaveBlock2 *, struct SaveBlock1 *) = (void *)gDecompressionBuffer;
    if (func(&client->param, gSaveBlock2Ptr, gSaveBlock1Ptr) == 1)
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_ACTIVE;
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
        [FUNC_RUN_MEVENT] = Client_RunMysteryEventScript,
        [FUNC_RUN_BUFFER] = Client_RunBufferScript
    };
    return funcs[client->funcId](client);
}
