#include "global.h"
#include "malloc.h"
#include "script.h"
#include "mevent.h"
#include "mevent_server.h"
#include "mevent_server_helpers.h"

EWRAM_DATA struct mevent_srv_common * s_mevent_srv_common_ptr = NULL;

static void mevent_srv_init_common(struct mevent_srv_common *, const void *, u32, u32);
static void mevent_srv_free_resources(struct mevent_srv_common *);
static u32 mevent_srv_exec_common(struct mevent_srv_common *);

extern const struct mevent_cmd s_mevent_wonder_news[];
extern const struct mevent_cmd s_mevent_wonder_card[];

void mevent_srv_init_wnews(void)
{
    s_mevent_srv_common_ptr = AllocZeroed(sizeof(struct mevent_srv_common));
    mevent_srv_init_common(s_mevent_srv_common_ptr, s_mevent_wonder_news, 0, 1);
}

void mevent_srv_new_wcard(void)
{
    s_mevent_srv_common_ptr = AllocZeroed(sizeof(struct mevent_srv_common));
    mevent_srv_init_common(s_mevent_srv_common_ptr, s_mevent_wonder_card, 0, 1);
}

u32 mevent_srv_common_do_exec(u16 * a0)
{
    u32 result;
    if (s_mevent_srv_common_ptr == NULL)
        return 3;
    result = mevent_srv_exec_common(s_mevent_srv_common_ptr);
    if (result == 3)
    {
        *a0 = s_mevent_srv_common_ptr->param;
        mevent_srv_free_resources(s_mevent_srv_common_ptr);
        Free(s_mevent_srv_common_ptr);
        s_mevent_srv_common_ptr = NULL;
    }
    return result;
}

static void mevent_srv_init_common(struct mevent_srv_common * svr, const void * cmdBuffer, u32 sendPlayerNo, u32 recvPlayerNo)
{
    svr->unk_00 = 0;
    svr->mainseqno = 0;
    svr->wonder_card = AllocZeroed(sizeof(struct WonderCard));
    svr->wonder_news = AllocZeroed(sizeof(struct WonderNews));
    svr->recvBuffer = AllocZeroed(ME_SEND_BUF_SIZE);
    svr->mevent_unk1442cc = AllocZeroed(sizeof(struct MEventStruct_Unk1442CC));
    svr->cmdBuffer = cmdBuffer;
    svr->cmdidx = 0;
    mevent_srv_sub_init(&svr->manager, sendPlayerNo, recvPlayerNo);
}

static void mevent_srv_free_resources(struct mevent_srv_common * svr)
{
    Free(svr->wonder_card);
    Free(svr->wonder_news);
    Free(svr->recvBuffer);
    Free(svr->mevent_unk1442cc);
}

void mevent_srv_common_init_send(struct mevent_srv_common * svr, u32 ident, const void * src, u32 size)
{
    AGB_ASSERT(size <= ME_SEND_BUF_SIZE);
    mevent_srv_sub_init_send(&svr->manager, ident, src, size);
}

static const void * mevent_first_if_not_null_else_second(const void * a0, const void * a1)
{
    if (a0 != NULL)
        return a0;
    else
        return a1;
}

static u32 mevent_compare_pointers(const void * a0, const void * a1)
{
    if (a1 < a0)
        return 0;
    else if (a1 == a0)
        return 1;
    else
        return 2;
}

static u32 common_mainseq_0(struct mevent_srv_common * svr)
{
    // start
    svr->mainseqno = 4;
    return 0;
}

static u32 common_mainseq_1(struct mevent_srv_common * svr)
{
    // done
    return 3;
}

static u32 common_mainseq_2(struct mevent_srv_common * svr)
{
    // do recv
    if (mevent_srv_sub_recv(&svr->manager))
        svr->mainseqno = 4;
    return 1;
}

static u32 common_mainseq_3(struct mevent_srv_common * svr)
{
    // do send
    if (mevent_srv_sub_send(&svr->manager))
        svr->mainseqno = 4;
    return 1;
}

static u32 common_mainseq_4(struct mevent_srv_common * svr)
{
    // process command
    const struct mevent_cmd * cmd = &svr->cmdBuffer[svr->cmdidx];
    const void * ptr;
    svr->cmdidx++;

    switch (cmd->instr)
    {
    case 0:
        // end
        AGB_ASSERT(cmd->parameter == NULL);
        svr->mainseqno = 1;
        svr->param = cmd->flag;
        break;
    case 1:
        // wait_send
        svr->mainseqno = 3;
        break;
    case 2:
        // receive
        AGB_ASSERT(cmd->parameter == NULL);
        mevent_srv_sub_init_recv(&svr->manager, cmd->flag, svr->recvBuffer);
        svr->mainseqno = 2;
        break;
    case 3:
        // jump
        AGB_ASSERT(cmd->flag == FALSE);
        svr->cmdidx = 0;
        svr->cmdBuffer = cmd->parameter;
        break;
    case 5:
        // get_1442CC
        AGB_ASSERT(cmd->flag == FALSE);
        AGB_ASSERT(cmd->parameter == NULL);
        memcpy(svr->mevent_unk1442cc, svr->recvBuffer, sizeof(struct MEventStruct_Unk1442CC));
        break;
    case 6:
        // check_header__pass_false
        AGB_ASSERT(cmd->flag == FALSE);
        AGB_ASSERT(cmd->parameter == NULL);
        svr->param = sub_801B6A0(svr->mevent_unk1442cc, FALSE);
        break;
    case 30:
        // check_header__pass_true
        AGB_ASSERT(cmd->flag == FALSE);
        AGB_ASSERT(cmd->parameter == NULL);
        svr->param = sub_801B6A0(svr->mevent_unk1442cc, TRUE);
        break;
    case 4:
        // jump_if_eq
        if (svr->param == cmd->flag)
        {
            svr->cmdidx = 0;
            svr->cmdBuffer = cmd->parameter;
        }
        break;
    case 7:
        // check_crc
        AGB_ASSERT(cmd->flag == FALSE);
        ptr = mevent_first_if_not_null_else_second(cmd->parameter, svr->wonder_card);
        svr->param = sub_801B6EC(ptr, svr->mevent_unk1442cc, ptr);
        break;
    case 8:
        // read_word
        AGB_ASSERT(cmd->flag == FALSE);
        AGB_ASSERT(cmd->parameter == NULL);
        svr->param = *(u32 *)svr->recvBuffer;
        break;
    case 9:
        AGB_ASSERT(cmd->flag == FALSE);
        ptr = mevent_first_if_not_null_else_second(cmd->parameter, &svr->sendWord);
        svr->param = sub_801B708(ptr, svr->mevent_unk1442cc, ptr);
        break;
    case 10:
        AGB_ASSERT(cmd->parameter == NULL);
        svr->param = MEventStruct_Unk1442CC_GetValueNFrom_unk_20(svr->mevent_unk1442cc, cmd->flag);
        break;
    case 11:
        AGB_ASSERT(cmd->flag == FALSE);
        svr->param = MEventStruct_Unk1442CC_CompareField_unk_16(svr->mevent_unk1442cc, cmd->parameter);
        break;
    case 12:
        AGB_ASSERT(cmd->flag == FALSE);
        svr->param = mevent_compare_pointers(cmd->parameter, *(void **)svr->recvBuffer);
        break;
    case 14:
        AGB_ASSERT(cmd->flag == FALSE);
        mevent_srv_common_init_send(svr, 0x17, mevent_first_if_not_null_else_second(cmd->parameter, svr->wonder_news), sizeof(struct WonderNews));
        break;
    case 13:
        AGB_ASSERT(cmd->flag == FALSE);
        mevent_srv_common_init_send(svr, 0x16, mevent_first_if_not_null_else_second(cmd->parameter, svr->wonder_card), sizeof(struct WonderCard));
        break;
    case 16:
        AGB_ASSERT(cmd->flag == FALSE);
        mevent_srv_common_init_send(svr, 0x18, mevent_first_if_not_null_else_second(cmd->parameter, &svr->sendWord), 4);
        break;
    case 15:
        if (cmd->parameter == NULL)
            mevent_srv_common_init_send(svr, 0x19, svr->sendBuffer1, svr->sendBuffer1Size);
        else
            mevent_srv_common_init_send(svr, 0x19, cmd->parameter, cmd->flag);
        break;
    case 18:
        if (cmd->parameter == NULL)
            mevent_srv_common_init_send(svr, 0x10, svr->sendBuffer2, svr->sendBuffer2Size);
        else
            mevent_srv_common_init_send(svr, 0x10, cmd->parameter, cmd->flag);
        break;
    case 19:
        AGB_ASSERT(cmd->flag == FALSE);
        mevent_srv_common_init_send(svr, 0x1a, cmd->parameter, 188);
        break;
    case 20:
        mevent_srv_common_init_send(svr, 0x15, cmd->parameter, cmd->flag);
        break;
    case 17:
        mevent_srv_common_init_send(svr, 0x1c, cmd->parameter, cmd->flag);
        break;
    case 22:
        AGB_ASSERT(cmd->flag == FALSE);
        memcpy(svr->wonder_card, cmd->parameter, 332);
        break;
    case 23:
        AGB_ASSERT(cmd->flag == FALSE);
        memcpy(svr->wonder_news, cmd->parameter, 444);
        break;
    case 21:
        AGB_ASSERT(cmd->flag == FALSE);
        svr->sendWord = *(u32 *)cmd->parameter;
        break;
    case 24:
        svr->sendBuffer1 = cmd->parameter;
        svr->sendBuffer1Size = cmd->flag;
        break;
    case 25:
        svr->sendBuffer2 = cmd->parameter;
        svr->sendBuffer2Size = cmd->flag;
        break;
    case 26:
        AGB_ASSERT(cmd->flag == FALSE && cmd->parameter == NULL);
        memcpy(svr->wonder_card, GetSavedWonderCard(), 332);
        WonderCard_ResetInternalReceivedFlag(svr->wonder_card);
        break;
    case 27:
        AGB_ASSERT(cmd->flag == FALSE && cmd->parameter == NULL);
        memcpy(svr->wonder_news, GetSavedWonderNews(), 444);
        break;
    case 28:
        AGB_ASSERT(cmd->flag == FALSE && cmd->parameter == NULL);
        svr->sendBuffer1 = GetSavedRamScriptIfValid();
        break;
    case 29:
        mevent_srv_common_init_send(svr, 0x1b, cmd->parameter, cmd->flag);
        break;
    }

    return 1;
}

static u32 (*const func_tbl[])(struct mevent_srv_common *) = {
    common_mainseq_0,
    common_mainseq_1,
    common_mainseq_2,
    common_mainseq_3,
    common_mainseq_4
};

static u32 mevent_srv_exec_common(struct mevent_srv_common * svr)
{
    u32 response;
    AGB_ASSERT(svr->mainseqno < ARRAY_COUNT(func_tbl));
    response = func_tbl[svr->mainseqno](svr);
    AGB_ASSERT(svr->mainseqno < ARRAY_COUNT(func_tbl));
    return response;
}
