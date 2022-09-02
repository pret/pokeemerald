#include "global.h"
#include "malloc.h"
#include "script.h"
#include "mystery_gift.h"
#include "mystery_gift_server.h"
#include "mystery_gift_link.h"

enum {
    FUNC_INIT,
    FUNC_DONE,
    FUNC_RECV,
    FUNC_SEND,
    FUNC_RUN,
};

EWRAM_DATA static struct MysteryGiftServer * sServer = NULL;

static void MysteryGiftServer_Init(struct MysteryGiftServer *, const void *, u32, u32);
static void MysteryGiftServer_Free(struct MysteryGiftServer *);
static u32 MysteryGiftServer_CallFunc(struct MysteryGiftServer *);

extern const struct MysteryGiftServerCmd gMysteryGiftServerScript_SendWonderNews[];
extern const struct MysteryGiftServerCmd gMysteryGiftServerScript_SendWonderCard[];

void MysterGiftServer_CreateForNews(void)
{
    sServer = AllocZeroed(sizeof(*sServer));
    MysteryGiftServer_Init(sServer, gMysteryGiftServerScript_SendWonderNews, 0, 1);
}

void MysterGiftServer_CreateForCard(void)
{
    sServer = AllocZeroed(sizeof(*sServer));
    MysteryGiftServer_Init(sServer, gMysteryGiftServerScript_SendWonderCard, 0, 1);
}

u32 MysterGiftServer_Run(u16 * endVal)
{
    u32 result;
    if (sServer == NULL)
        return SVR_RET_END;
    result = MysteryGiftServer_CallFunc(sServer);
    if (result == SVR_RET_END)
    {
        *endVal = sServer->param;
        MysteryGiftServer_Free(sServer);
        FREE_AND_SET_NULL(sServer);
    }
    return result;
}

static void MysteryGiftServer_Init(struct MysteryGiftServer * svr, const void * script, u32 sendPlayerId, u32 recvPlayerId)
{
    svr->unused = 0;
    svr->funcId = FUNC_INIT;
    svr->card = AllocZeroed(sizeof(*svr->card));
    svr->news = AllocZeroed(sizeof(*svr->news));
    svr->recvBuffer = AllocZeroed(MG_LINK_BUFFER_SIZE);
    svr->linkGameData = AllocZeroed(sizeof(*svr->linkGameData));
    svr->script = script;
    svr->cmdidx = 0;
    MysteryGiftLink_Init(&svr->link, sendPlayerId, recvPlayerId);
}

static void MysteryGiftServer_Free(struct MysteryGiftServer * svr)
{
    Free(svr->card);
    Free(svr->news);
    Free(svr->recvBuffer);
    Free(svr->linkGameData);
}

static void MysteryGiftServer_InitSend(struct MysteryGiftServer * svr, u32 ident, const void * src, u32 size)
{
    AGB_ASSERT(size <= MG_LINK_BUFFER_SIZE);
    MysteryGiftLink_InitSend(&svr->link, ident, src, size);
}

// Given the command pointer parameter and the 'default' normal data.
// If the command's pointer is not empty use that as the send data, otherwise use the default.
static const void * MysteryGiftServer_GetSendData(const void * dynamicData, const void * defaultData)
{
    if (dynamicData != NULL)
        return dynamicData;
    else
        return defaultData;
}

static u32 MysteryGiftServer_Compare(const void * a, const void * b)
{
    if (b < a)
        return 0;
    else if (b == a)
        return 1;
    else
        return 2;
}

static u32 Server_Init(struct MysteryGiftServer * svr)
{
    svr->funcId = FUNC_RUN;
    return SVR_RET_INIT;
}

static u32 Server_Done(struct MysteryGiftServer * svr)
{
    return SVR_RET_END;
}

static u32 Server_Recv(struct MysteryGiftServer * svr)
{
    if (MysteryGiftLink_Recv(&svr->link))
        svr->funcId = FUNC_RUN;
    return SVR_RET_ACTIVE;
}

static u32 Server_Send(struct MysteryGiftServer * svr)
{
    if (MysteryGiftLink_Send(&svr->link))
        svr->funcId = FUNC_RUN;
    return SVR_RET_ACTIVE;
}

static u32 Server_Run(struct MysteryGiftServer * svr)
{
    // process command
    const struct MysteryGiftServerCmd * cmd = &svr->script[svr->cmdidx];
    const void * ptr;
    svr->cmdidx++;

    switch (cmd->instr)
    {
    case SVR_RETURN:
        AGB_ASSERT(cmd->ptr == NULL);
        svr->funcId = FUNC_DONE;
        svr->param = cmd->parameter; // Set for endVal in MysteryGiftServer_Run
        break;
    case SVR_SEND:
        svr->funcId = FUNC_SEND;
        break;
    case SVR_RECV:
        AGB_ASSERT(cmd->ptr == NULL);
        MysteryGiftLink_InitRecv(&svr->link, cmd->parameter, svr->recvBuffer);
        svr->funcId = FUNC_RECV;
        break;
    case SVR_GOTO:
        AGB_ASSERT(cmd->parameter == 0);
        svr->cmdidx = 0;
        svr->script = cmd->ptr;
        break;
    case SVR_COPY_GAME_DATA:
        AGB_ASSERT(cmd->parameter == 0);
        AGB_ASSERT(cmd->ptr == NULL);
        memcpy(svr->linkGameData, svr->recvBuffer, sizeof(*svr->linkGameData));
        break;
    case SVR_CHECK_GAME_DATA_CARD:
        AGB_ASSERT(cmd->parameter == 0);
        AGB_ASSERT(cmd->ptr == NULL);
        svr->param = MysteryGift_ValidateLinkGameData(svr->linkGameData, FALSE);
        break;
    case SVR_CHECK_GAME_DATA_NEWS:
        AGB_ASSERT(cmd->parameter == 0);
        AGB_ASSERT(cmd->ptr == NULL);
        svr->param = MysteryGift_ValidateLinkGameData(svr->linkGameData, TRUE);
        break;
    case SVR_GOTO_IF_EQ:
        if (svr->param == cmd->parameter)
        {
            svr->cmdidx = 0;
            svr->script = cmd->ptr;
        }
        break;
    case SVR_CHECK_EXISTING_CARD:
        AGB_ASSERT(cmd->parameter == 0);
        ptr = MysteryGiftServer_GetSendData(cmd->ptr, svr->card);
        svr->param = MysteryGift_CompareCardFlags(ptr, svr->linkGameData, ptr);
        break;
    case SVR_READ_RESPONSE:
        AGB_ASSERT(cmd->parameter == 0);
        AGB_ASSERT(cmd->ptr == NULL);
        svr->param = *(u32 *)svr->recvBuffer;
        break;
    case SVR_CHECK_EXISTING_STAMPS:
        AGB_ASSERT(cmd->parameter == 0);
        ptr = MysteryGiftServer_GetSendData(cmd->ptr, &svr->stamp);
        svr->param = MysteryGift_CheckStamps(ptr, svr->linkGameData, ptr);
        break;
    case SVR_GET_CARD_STAT:
        AGB_ASSERT(cmd->ptr == NULL);
        svr->param = MysteryGift_GetCardStatFromLinkData(svr->linkGameData, cmd->parameter);
        break;
    case SVR_CHECK_QUESTIONNAIRE:
        AGB_ASSERT(cmd->parameter == 0);
        svr->param = MysteryGift_DoesQuestionnaireMatch(svr->linkGameData, cmd->ptr);
        break;
    case SVR_COMPARE:
        AGB_ASSERT(cmd->parameter == 0);
        svr->param = MysteryGiftServer_Compare(cmd->ptr, *(void **)svr->recvBuffer);
        break;
    case SVR_LOAD_NEWS:
        AGB_ASSERT(cmd->parameter == 0);
        MysteryGiftServer_InitSend(svr, MG_LINKID_NEWS, MysteryGiftServer_GetSendData(cmd->ptr, svr->news), sizeof(*svr->news));
        break;
    case SVR_LOAD_CARD:
        AGB_ASSERT(cmd->parameter == 0);
        MysteryGiftServer_InitSend(svr, MG_LINKID_CARD, MysteryGiftServer_GetSendData(cmd->ptr, svr->card), sizeof(*svr->card));
        break;
    case SVR_LOAD_STAMP:
        AGB_ASSERT(cmd->parameter == 0);
        MysteryGiftServer_InitSend(svr, MG_LINKID_STAMP, MysteryGiftServer_GetSendData(cmd->ptr, &svr->stamp), sizeof(svr->stamp));
        break;
    case SVR_LOAD_RAM_SCRIPT:
        if (cmd->ptr == NULL)
            MysteryGiftServer_InitSend(svr, MG_LINKID_RAM_SCRIPT, svr->ramScript, svr->ramScriptSize);
        else
            MysteryGiftServer_InitSend(svr, MG_LINKID_RAM_SCRIPT, cmd->ptr, cmd->parameter);
        break;
    case SVR_LOAD_CLIENT_SCRIPT:
        if (cmd->ptr == NULL)
            MysteryGiftServer_InitSend(svr, MG_LINKID_CLIENT_SCRIPT, svr->clientScript, svr->clientScriptSize);
        else
            MysteryGiftServer_InitSend(svr, MG_LINKID_CLIENT_SCRIPT, cmd->ptr, cmd->parameter);
        break;
    case SVR_LOAD_EREADER_TRAINER:
        AGB_ASSERT(cmd->parameter == 0);
        MysteryGiftServer_InitSend(svr, MG_LINKID_EREADER_TRAINER, cmd->ptr, sizeof(struct BattleTowerEReaderTrainer));
        break;
    case SVR_LOAD_MSG:
        MysteryGiftServer_InitSend(svr, MG_LINKID_DYNAMIC_MSG, cmd->ptr, cmd->parameter);
        break;
    case SVR_LOAD_UNK_2:
        MysteryGiftServer_InitSend(svr, MG_LINKID_UNK_2, cmd->ptr, cmd->parameter);
        break;
    case SVR_COPY_CARD:
        AGB_ASSERT(cmd->parameter == 0);
        memcpy(svr->card, cmd->ptr, sizeof(*svr->card));
        break;
    case SVR_COPY_NEWS:
        AGB_ASSERT(cmd->parameter == 0);
        memcpy(svr->news, cmd->ptr, sizeof(*svr->news));
        break;
    case SVR_COPY_STAMP:
        AGB_ASSERT(cmd->parameter == 0);
        svr->stamp = *(u32 *)cmd->ptr;
        break;
    case SVR_SET_RAM_SCRIPT:
        svr->ramScript = cmd->ptr;
        svr->ramScriptSize = cmd->parameter;
        break;
    case SVR_SET_CLIENT_SCRIPT:
        svr->clientScript = cmd->ptr;
        svr->clientScriptSize = cmd->parameter;
        break;
    case SVR_COPY_SAVED_CARD:
        AGB_ASSERT(cmd->parameter == 0 && cmd->ptr == NULL);
        memcpy(svr->card, GetSavedWonderCard(), sizeof(*svr->card));
        DisableWonderCardSending(svr->card);
        break;
    case SVR_COPY_SAVED_NEWS:
        AGB_ASSERT(cmd->parameter == 0 && cmd->ptr == NULL);
        memcpy(svr->news, GetSavedWonderNews(), sizeof(*svr->news));
        break;
    case SVR_COPY_SAVED_RAM_SCRIPT:
        AGB_ASSERT(cmd->parameter == 0 && cmd->ptr == NULL);
        svr->ramScript = GetSavedRamScriptIfValid();
        break;
    case SVR_LOAD_UNK_1:
        MysteryGiftServer_InitSend(svr, MG_LINKID_UNK_1, cmd->ptr, cmd->parameter);
        break;
    }

    return SVR_RET_ACTIVE;
}

static u32 (*const sFuncTable[])(struct MysteryGiftServer *) = {
    [FUNC_INIT] = Server_Init,
    [FUNC_DONE] = Server_Done,
    [FUNC_RECV] = Server_Recv,
    [FUNC_SEND] = Server_Send,
    [FUNC_RUN] = Server_Run
};

static u32 MysteryGiftServer_CallFunc(struct MysteryGiftServer * svr)
{
    u32 response;
    AGB_ASSERT(svr->funcId < ARRAY_COUNT(sFuncTable));
    response = sFuncTable[svr->funcId](svr);
    AGB_ASSERT(svr->funcId < ARRAY_COUNT(sFuncTable));
    return response;
}
