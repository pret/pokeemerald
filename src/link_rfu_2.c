#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "berry_blender.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "overworld.h"
#include "random.h"
#include "palette.h"
#include "union_room.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/species.h"
#include "constants/union_room.h"
#include "save.h"
#include "mystery_gift.h"

u32 gf_rfu_REQ_api[RFU_API_BUFF_SIZE_RAM / 4];
struct UnkRfuStruct_2 Rfu;

static u8 gUnknown_03000D78[8];
static u8 sResendBlock8[14];
static u16 sResendBlock16[7];

void Task_idle(u8 taskId);

EWRAM_DATA struct GFtgtGname gHostRFUtgtGnameBuffer = {};
EWRAM_DATA ALIGNED(2) u8 gHostRFUtgtUnameBuffer[RFU_USER_NAME_LENGTH] = {};
EWRAM_DATA INIT_PARAM sRfuReqConfig = {};
EWRAM_DATA struct UnkLinkRfuStruct_02022B44 gUnknown_02022B44 = {};

const struct InitializeParametersTag sRfuReqConfigTemplate = {
    .maxMFrame = 4,
    .MC_TimerCount = 32,
    .availSlot_flag = 0,
    .mboot_flag = 0,
    .serialNo = 0x0002,
    .gameName = (void *)&gHostRFUtgtGnameBuffer,
    .userName = gHostRFUtgtUnameBuffer,
    .fastSearchParent_flag = TRUE,
    .linkRecovery_enable = FALSE,
    .linkRecovery_period = 600,
    .NI_failCounter_limit = 300
};

const u8 sAvailSlots[] = {
    [1] = AVAIL_SLOT1,
    [2] = AVAIL_SLOT2,
    [3] = AVAIL_SLOT3,
	[4] = AVAIL_SLOT4
};

const u32 sAllBlocksReceived[] = {
    0x000000,
    0x000001,
    0x000003,
    0x000007,
    0x00000f,
    0x00001f,
    0x00003f,
    0x00007f,
    0x0000ff,
    0x0001ff,
    0x0003ff,
    0x0007ff,
    0x000fff,
    0x001fff,
    0x003fff,
    0x007fff,
    0x00ffff,
    0x01ffff,
    0x03ffff,
    0x07ffff,
    0x0fffff,
    0x1fffff,
    0x3fffff,
    0x7fffff,
    0xffffff
};

const u8 gUnknown_082ED68C[] = {
    0, 0, 1,
    1, 2, 2,
    2, 2, 3
};

const u8 gUnknown_082ED695[] = {
    0, 1, 1, 2,
    1, 2, 2, 3,
    1, 2, 2, 3,
    2, 3, 3, 4
};

const u8 gUnknown_082ED6A5[] = {
    0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

const struct {
    u8 *buffer;
    u32 size;
} gUnknown_082ED6B8[] = {
    { gBlockSendBuffer, 200 },
    { gBlockSendBuffer, 200 },
    { gBlockSendBuffer, 100 },
    { gBlockSendBuffer, 220 },
    { gBlockSendBuffer,  40 }
};

const u16 sAcceptedSerialNos[] = {
    0x0002, // Pokemon FR/LG/EM
	0x7f7d,
	0x0000,
	0xFFFF
};

const char sUnref_082ED6E8[][15] = {
    "RFU WAIT",
    "RFU BOOT",
    "RFU ERROR",
    "RFU RESET",
    "RFU CONFIG",
    "RFU START",
    "RFU SC POLL",
    "RFU SP POLL",
    "RFU START",
    "RFU SEND ERR",
    "RFU CP POLL"
};
const char sUnref_082ED6E9[][16] = {
    "              ",
    "RECOVER START ",
    "DISSCONECT    ",
    "RECOVER SUUSES",
    "RECOVER FAILED"
};

const TaskFunc gUnknown_082ED7E0[] = {
    sub_801084C,
    Task_ExchangeLinkPlayers,
    sub_8010D0C
};

void rfu_dbg_print_str(const void *string, u8 x, u8 y)
{
    // debug?
}

void rfu_dbg_print_num(u16 num, u8 x, u8 y, u8 ndigits)
{

}

void ResetLinkRfuGFLayer(void)
{
    s32 i;
    u8 errorState_bak = Rfu.errorState; 
	CpuFill16(0, &Rfu, sizeof Rfu);
    Rfu.errorState = errorState_bak;
    Rfu.parent_child = MODE_NEUTRAL;
    if (Rfu.errorState != 4)
    {
        Rfu.errorState = 0;
    }
    for (i = 0; i < 5; i++)
    {
        ResetSendDataManager(Rfu.cmd_8800_recvbuf + i);
    }
    ResetSendDataManager(&Rfu.cmd_8800_sendbuf);
    RFU_queue_32_70_reset(&Rfu.unk_124);
    RFU_queue_40_14_reset(&Rfu.sendQueue);
    CpuFill16(0, gSendCmd, sizeof gSendCmd);
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
    CpuFill16(0, gLinkPlayers, sizeof gLinkPlayers);
}

void InitRFU(void)
{
    IntrFunc serialIntr = gIntrTable[1];
    IntrFunc timerIntr = gIntrTable[2];
    sub_800E700();
    rfu_REQ_stopMode();
    rfu_waitREQComplete();
    REG_IME = 0;
    gIntrTable[1] = serialIntr;
    gIntrTable[2] = timerIntr;
    REG_IME = INTR_FLAG_VBLANK;
}

void sub_800E700(void)
{
    if (!rfu_initializeAPI(gf_rfu_REQ_api, RFU_API_BUFF_SIZE_RAM, gIntrTable + 1, TRUE))
    {
        gLinkType = 0;
        sub_800AAF4();
        sub_80111B0(FALSE);
        ResetLinkRfuGFLayer();
        rfu_setTimerInterrupt(3, gIntrTable + 2);
    }
}

void Task_LinkLeaderSearchForChildren(u8 taskId)
{
    sub_8010750();
    switch (Rfu.state)
    {
        case 0:
            rfu_LMAN_initializeRFU(&sRfuReqConfig);
            Rfu.state = 1;
            gTasks[taskId].data[1] = 1;
            break;
        case 1:
            break;
        case 2:
            rfu_LMAN_establishConnection(Rfu.parent_child, 0, 240, (u16*)sAcceptedSerialNos);
            Rfu.state = 3;
            gTasks[taskId].data[1] = 6;
            break;
        case 3:
            break;
        case 4:
            rfu_LMAN_stopManager(FALSE);
            Rfu.state = 5;
            break;
        case 5:
            break;
        case 18:
            Rfu.unk_cdb = 0;
            rfu_LMAN_setMSCCallback(MSCCallback_SetUnkCDB);
            sub_800EAB4();
            sub_800EAFC();
            Rfu.state = 20;
            gTasks[taskId].data[1] = 8;
            CreateTask(sub_801084C, 5);
            DestroyTask(taskId);
            break;
    }
}

s32 sub_800E87C(u8 idx)
{
    return gUnknown_082ED6A5[idx];
}

void sub_800E88C(s32 r2, s32 r5)
{
    u8 i;
    u8 r4 = 1;
    s32 r1 = r2;
    s32 r6 = 0;
    if (r5 == -1)
    {
        for (i = 0; i < RFU_CHILD_MAX; r2 >>= 1, i++)
        {
            if (r2 & 1)
            {
                Rfu.linkPlayerIdx[i] = r4;
                r4++;
            }
        }
    }
    else
    {
        for (i = 0; i < RFU_CHILD_MAX; r1 >>= 1, i++)
        {
            if (!(r1 & 1))
            {
                Rfu.linkPlayerIdx[i] = 0;
            }
        }
        for (r4 = 4; r4 != 0; r4--)
        {
            for (i = 0; i < RFU_CHILD_MAX && Rfu.linkPlayerIdx[i] != r4; i++);
            if (i == 4)
            {
                r6 = r4;
            }
        }
        for (r5 &= ~r2, i = 0; i < RFU_CHILD_MAX; r5 >>= 1, i++)
        {
            if (r5 & 1)
            {
                Rfu.linkPlayerIdx[i] = r6++;
            }
        }
    }
}

void Task_JoinGroupSearchForParent(u8 taskId)
{
    switch (Rfu.state)
    {
        case 0:
            rfu_LMAN_initializeRFU((INIT_PARAM*)&sRfuReqConfigTemplate);
            Rfu.state = 1;
            gTasks[taskId].data[1] = 1;
            break;
        case 1:
            break;
        case 6:
            rfu_LMAN_establishConnection(Rfu.parent_child, 0, 240, (u16*)sAcceptedSerialNos);
            Rfu.state = 7;
            gTasks[taskId].data[1] = 7;
            break;
        case 7:
            break;
        case 9:
            gTasks[taskId].data[1] = 10;
            break;
        case 11:
            switch (sub_80107A0())
            {
                case 5:
                    Rfu.state = 12;
                    break;
                case 6:
                case 9:
                    rfu_LMAN_requestChangeAgbClockMaster();
                    Rfu.unk_ce4 = 2;
                    DestroyTask(taskId);
                    break;
            }
            break;
        case 12:
        {
            u8 bmChildSlot = 1 << Rfu.child_slot;
            rfu_clearSlot(TYPE_NI_SEND | TYPE_NI_RECV, Rfu.child_slot);
            rfu_setRecvBuffer(TYPE_UNI, Rfu.child_slot, Rfu.unk_c3f, sizeof(Rfu.unk_c3f));
            rfu_UNI_setSendData(bmChildSlot, Rfu.unk_4c, sizeof(Rfu.unk_4c));
            gTasks[taskId].data[1] = 8;
            DestroyTask(taskId);
            if (gUnknown_02022B44.unk_0f == 0)
            {
                rfu_dbg_clear();
                gUnknown_02022B44.unk_0f++;
            }
            CreateTask(sub_801084C, 5);
            break;
        }
    }
}

void sub_800EAB4(void)
{
    u8 i;
    u8 acceptSlot = lman.acceptSlot_flag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (acceptSlot & 1)
        {
            rfu_setRecvBuffer(TYPE_UNI, i, Rfu.unk_14[i], sizeof(Rfu.unk_14[i]));
            rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, i);
        }
        acceptSlot >>= 1;
    }
}

void sub_800EAFC(void)
{
    u8 acceptSlot = lman.acceptSlot_flag;
    rfu_UNI_setSendData(acceptSlot, Rfu.recvCmds, sizeof(Rfu.recvCmds));
    Rfu.unk_cda = sub_800E87C(acceptSlot);
    Rfu.bm_PartnerFlags = acceptSlot;
    sub_800E88C(acceptSlot, -1);
    Rfu.parent_child = MODE_PARENT;
}

void Task_LinkRfu_UnionRoomListen(u8 taskId)
{
    if (GetHostRFUtgtGname()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM) && RfuGetErrorStatus() == 4)
    {
        rfu_REQ_disconnect(lman.acceptSlot_flag);
        rfu_waitREQComplete();
        RfuSetErrorStatus(0, 0);
    }
    switch (Rfu.state)
    {
        case 0:
            rfu_LMAN_initializeRFU(&sRfuReqConfig);
            Rfu.state = 1;
            gTasks[taskId].data[1] = 1;
            break;
        case 1:
            break;
        case 17:
            rfu_LMAN_establishConnection(2, 0, 240, (u16*)sAcceptedSerialNos);
            rfu_LMAN_setMSCCallback(MscCallback_Child);
            Rfu.state = 18;
            break;
        case 18:
            break;
        case 13:
            if (rfu_UNI_setSendData(1 << Rfu.child_slot, Rfu.unk_4c, sizeof(Rfu.unk_4c)) == 0)
            {
                Rfu.parent_child = MODE_CHILD;
                DestroyTask(taskId);
                if (gTasks[taskId].data[7])
                {
                    CreateTask(sub_8010D0C, 1);
                }
                else
                {
                    CreateTask(sub_801084C, 5);
                }
            }
            break;
        case 14:
            rfu_LMAN_stopManager(FALSE);
            Rfu.state = 15;
            break;
        case 15:
            break;
        case 16:
            Rfu.unk_cdb = 0;
            rfu_LMAN_setMSCCallback(MSCCallback_SetUnkCDB);
            UpdateGameData_GroupLockedIn(1);
            sub_800EAB4();
            sub_800EAFC();
            Rfu.state = 20;
            gTasks[taskId].data[1] = 8;
            Rfu.parent_child = MODE_PARENT;
            CreateTask(sub_801084C, 5);
            Rfu.unk_ce8 = TRUE;
            DestroyTask(taskId);
            break;
    }
}

void LinkRfu_CreateConnectionAsParent(void)
{
    rfu_LMAN_establishConnection(MODE_PARENT, 0, 240, (u16*)sAcceptedSerialNos);
}

void LinkRfu_StopManagerBeforeEnteringChat(void)
{
    rfu_LMAN_stopManager(FALSE);
}

void MscCallback_Child(u16 unused)
{
    s32 i;

    for (i = 0; i < 14; i++)
    {
        Rfu.unk_4c[i] = 0;
    }
    rfu_REQ_recvData();
    rfu_waitREQComplete();
    if (gRfuSlotStatusUNI[Rfu.child_slot]->recv.newDataFlag)
    {
        Rfu.unk_cd0++;
        RFU_queue_32_70_recv(&Rfu.unk_124, Rfu.unk_c3f);
        gUnknown_02022B44.unk_06++;
        sub_800F048();
        rfu_UNI_readySendData(Rfu.child_slot);
        rfu_UNI_clearRecvNewDataFlag(Rfu.child_slot);
    }
    rfu_LMAN_REQ_sendData(TRUE);
}

void MSCCallback_SetUnkCDB(u16 unused)
{
    Rfu.unk_cdb = 1;
}

void LinkRfu_Shutdown(void)
{
    u8 i;

    rfu_LMAN_powerDownRFU();
    if (Rfu.parent_child == MODE_PARENT)
    {
        if (FuncIsActiveTask(Task_LinkLeaderSearchForChildren) == TRUE)
        {
            DestroyTask(Rfu.unk_67);
            ResetLinkRfuGFLayer();
        }
    }
    else if (Rfu.parent_child == MODE_CHILD)
    {
        if (FuncIsActiveTask(Task_JoinGroupSearchForParent) == TRUE)
        {
            DestroyTask(Rfu.unk_67);
            ResetLinkRfuGFLayer();
        }
    }
    else if (Rfu.parent_child == 2)
    {
        if (FuncIsActiveTask(Task_LinkRfu_UnionRoomListen) == TRUE)
        {
            DestroyTask(Rfu.unk_67);
            ResetLinkRfuGFLayer();
        }
    }
    for (i = 0; i < NELEMS(gUnknown_082ED7E0); i++)
    {
        if (FuncIsActiveTask(gUnknown_082ED7E0[i]) == TRUE)
        {
            DestroyTask(FindTaskIdByFunc(gUnknown_082ED7E0[i]));
        }
    }
}

void CreateTask_LinkLeaderSearchForChildren(void)
{
    Rfu.unk_67 = CreateTask(Task_LinkLeaderSearchForChildren, 1);
}

bool8 RfuStateIs7AndPlayerIsChild(void)
{
    if (Rfu.state == 7 && Rfu.parentId)
    {
        return TRUE;
    }
    return FALSE;
}

bool32 IsParentSuccessfullyReconnected(void)
{
    if (Rfu.state == 7 && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[Rfu.reconnectedParentIdx].id, 240))
    {
        Rfu.state = 9;
        return TRUE;
    }
    return FALSE;
}

void CreateTask_JoinGroupSearchForParent(void)
{
    Rfu.unk_67 = CreateTask(Task_JoinGroupSearchForParent, 1);
}

bool8 LmanAcceptSlotFlagIsNotZero(void)
{
    if (lman.acceptSlot_flag)
    {
        return TRUE;
    }
    return FALSE;
}

void LinkRfu_StopManagerAndFinalizeSlots(void)
{
    Rfu.state = 4;
    Rfu.acceptSlot_flag = lman.acceptSlot_flag;
}

bool32 WaitRfuState(bool32 force)
{
    if (Rfu.state == 17 || force)
    {
        Rfu.state = 18;
        return TRUE;
    }
    return FALSE;
}

void sub_800EF7C(void)
{
    Rfu.state = 14;
}

void sub_800EF88(u8 a0)
{
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (a0 & 1)
        {
            rfu_UNI_readySendData(i);
            break;
        }
        a0 >>= 1;
    }
}

void sub_800EFB0(void)
{
    s32 i, j;

    for (i = 0; i < 5; i++)
    {
        GF_RFU_MANAGER *ptr = &Rfu;
        for (j = 0; j < 7; j++)
        {
            ptr->recvCmds[i][j][1] = gRecvCmds[i][j] >> 8;
            ptr->recvCmds[i][j][0] = gRecvCmds[i][j];
        }
    }
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
}

void sub_800F014(void)
{
    s32 i;
    for (i = 0; i < 7; i++)
    {
        gRecvCmds[0][i] = gSendCmd[i];
    }
    for (i = 0; i < 7; i++)
    {
        gSendCmd[i] = 0;
    }
}

void sub_800F048(void)
{
    if (Rfu.unk_c3c)
    {
        u8 r2 = RFU_queue_2_14_send(&Rfu.unk_c1c, Rfu.unk_4c);
        if (Rfu.unk_c1c.count == 0)
        {
            Rfu.unk_c3c = 0;
        }
        if (r2)
        {
            return;
        }
    }
    if (Rfu.unk_c3c == 0)
    {
        RFU_queue_40_14_send(&Rfu.sendQueue, Rfu.unk_4c);
        RFU_queue_2_14_recv(&Rfu.unk_c1c, Rfu.unk_4c);
    }
}

bool32 IsRfuRecvQueueEmpty(void)
{
    s32 i;
    s32 j;

    if (gRfuLinkStatus->sendSlotUNIFlag == 0)
    {
        return FALSE;
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (gRecvCmds[i][j] != 0)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

bool32 sub_800F0F8(void)
{
    if (Rfu.state < 20)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(FALSE);
    }
    else
    {
        Rfu.unk_cdb = 0;
        if ((Rfu.bm_PartnerFlags & gRfuLinkStatus->connSlotFlag) == Rfu.bm_PartnerFlags && (Rfu.bm_PartnerFlags & gRfuLinkStatus->connSlotFlag))
        {
            if (!Rfu.unk_cdc)
            {
                if (Rfu.bm_DisconnectSlot)
                {
                    RfuReqDisconnectSlot(Rfu.bm_DisconnectSlot);
                    Rfu.bm_DisconnectSlot = 0;
                    if (Rfu.unk_ce4 == 1)
                    {
                        RfuSetErrorStatus(2, 0x8000);
                        GetLinkmanErrorParams(0x8000);
                        return FALSE;
                    }
                    if (!lman.acceptSlot_flag)
                    {
                        LinkRfu_Shutdown();
                        gReceivedRemoteLinkPlayers = FALSE;
                        return FALSE;
                    }
                }
                sub_800EFB0();
                rfu_UNI_readySendData(Rfu.unk_cda);
                rfu_LMAN_REQ_sendData(TRUE);
            }
            else
            {
                rfu_REQ_PARENT_resumeRetransmitAndChange();
            }
            Rfu.unk_0e = 1;
        }
    }
    return FALSE;
}

bool32 sub_800F1E0(void)
{
    u16 i;
    u16 flags;
    u8 r0;
    u16 j;
    u8 retval;

    if (Rfu.state >= 20 && Rfu.unk_0e == 1)
    {
        rfu_waitREQComplete();
        while (Rfu.unk_cdb == 0)
        {
            if (Rfu.errorState != 0)
            {
                return FALSE;
            }
        }
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        if ((lman.parentAck_flag & Rfu.bm_PartnerFlags) == Rfu.bm_PartnerFlags)
        {
            Rfu.unk_cdc = 0;
            gUnknown_02022B44.unk_06++;
            flags = lman.acceptSlot_flag;
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if (flags & 1)
                {
                    if (Rfu.unk_14[i][1])
                    {
                        if (Rfu.unk_cee[i] != 0xFF && (Rfu.unk_14[i][0] >> 5) != ((Rfu.unk_cee[i] + 1) & 7))
                        {
                            if (++Rfu.unk_cea[i] > 4)
                                GetLinkmanErrorParams(0x8100);
                        }
                        else
                        {
                            Rfu.unk_cee[i] = Rfu.unk_14[i][0] / 32;
                            Rfu.unk_cea[i] = 0;
                            Rfu.unk_14[i][0] &= 0x1f;
                            r0 = Rfu.linkPlayerIdx[i];
                            for (j = 0; j < 7; j++)
                            {
                                gRecvCmds[r0][j] = (Rfu.unk_14[i][(j << 1) + 1] << 8) | Rfu.unk_14[i][(j << 1) + 0];
                                Rfu.unk_14[i][(j << 1) + 1] = 0;
                                Rfu.unk_14[i][(j << 1) + 0] = 0;
                            }
                        }
                    }
                    rfu_UNI_clearRecvNewDataFlag(i);
                }
                flags >>= 1;
            }
            sub_800F014();
            RfuHandleReceiveCommand(0);
            CallRfuFunc();
            if (Rfu.unk_ce5 && !Rfu.unk_cd9)
            {
                gUnknown_02022B44.unk_0e = 0;
                rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, Rfu.unk_cda);
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((Rfu.unk_ce5 >> i) & 1)
                    {
                        rfu_setRecvBuffer(TYPE_UNI, i, Rfu.unk_14[i], sizeof(Rfu.unk_14[i]));
                    }
                }
                sub_800E88C(Rfu.bm_PartnerFlags, Rfu.bm_PartnerFlags | Rfu.unk_ce5);
                Rfu.unk_ce9 = Rfu.unk_ce5;
                Rfu.bm_PartnerFlags |= Rfu.unk_ce5;
                Rfu.unk_ce5 = 0;
                rfu_UNI_setSendData(Rfu.bm_PartnerFlags, Rfu.recvCmds, sizeof(Rfu.recvCmds));
                Rfu.unk_cda = sub_800E87C(Rfu.bm_PartnerFlags);
                CreateTask(Task_ExchangeLinkPlayers, 0);
            }
        }
        else
        {
            Rfu.unk_cdc = 1;
            Rfu.unk_0e = 0;
        }
        Rfu.unk_0e = 0;
    }
    retval = Rfu.unk_cdc;
    return gRfuLinkStatus->sendSlotUNIFlag ? retval & 1 : FALSE;
}

void sub_800F498(u16 *a0, u8 *a1)
{
    s32 i;

    if (a0[0])
    {
        a0[0] |= (Rfu.unk_102 << 5);
        Rfu.unk_102 = (Rfu.unk_102 + 1) & 7;
        for (i = 0; i < 7; i++)
        {
            a1[2 * i + 1] = a0[i] >> 8;
            a1[2 * i + 0] = a0[i];
        }
    }
    else
    {
        for (i = 0; i < 14; i++)
            a1[i] = 0;
    }
}

bool32 RfuProcessEnqueuedRecvBlock(void)
{
    u8 i;
    u8 j;
    u8 sp00[MAX_RFU_PLAYERS * (2 * (CMD_LENGTH - 1))];
    u8 sp48[2 * (CMD_LENGTH - 1)];
    u8 switchval;

    RFU_queue_32_70_send(&Rfu.unk_124, sp00);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH - 1; j++)
        {
            gRecvCmds[i][j] = (sp00[i * 14 + (j << 1) + 1] << 8) | sp00[i * 14 + (j << 1) + 0];
        }
    }
    RfuHandleReceiveCommand(0);
    if (lman.childClockSlave_flag == 0 && Rfu.unk_ce4)
    {
        rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
        rfu_waitREQComplete();
        switchval = RfuGetErrorStatus();
        if (switchval != 1 && switchval != 6 && switchval != 9)
            RfuSetErrorStatus(2, 0x9000);
        rfu_clearAllSlot();
        gReceivedRemoteLinkPlayers = FALSE;
        Rfu.RfuFunc = NULL;
        if (Rfu.unk_ce4 == 1)
        {
            RfuSetErrorStatus(2, 0x9000);
            GetLinkmanErrorParams(0x9000);
        }
        lman.state = lman.next_state = 0;
        Rfu.unk_ce4 = 0;
    }
    if (Rfu.unk_cd0)
    {
        Rfu.unk_cd0--;
        CallRfuFunc();
        sub_800F498(gSendCmd, sp48);
        RFU_queue_40_14_recv(&Rfu.sendQueue, sp48);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i] = 0;
    }
    return IsRfuRecvQueueEmpty();
}

void HandleSendFailure(u8 unused, u32 flags)
{
    s32 i, j;

    const u8 *r10 = Rfu.cmd_8800_sendbuf.payload;
    for (i = 0; i < Rfu.cmd_8800_sendbuf.count; i++)
    {
        if (!(flags & 1))
        {
            sResendBlock16[0] = RFU_COMMAND_0x8900 | i;
            for (j = 0; j < 7; j++)
            {
                sResendBlock16[j + 1] = (r10[12 * i + (j << 1) + 1] << 8) | r10[12 * i + (j << 1) + 0];
            }
            for (j = 0; j < 7; j++)
            {
                sResendBlock8[2 * j + 1] = sResendBlock16[j] >> 8;
                sResendBlock8[2 * j + 0] = sResendBlock16[j];

                j++;j--; // Needed to match;
            }
            RFU_queue_40_14_recv(&Rfu.sendQueue, sResendBlock8);
            Rfu.cmd_8800_sendbuf.failedFlags |= (1 << i);
        }
        flags >>= 1;
    }
}

void Rfu_SetBlockReceivedFlag(u8 a0)
{
    if (Rfu.parent_child == MODE_PARENT && a0)
        Rfu.unk_61[a0] = 1;
    else
        Rfu.unk_5c[a0] = 1;
}

void Rfu_ResetBlockReceivedFlag(u8 a0)
{
    Rfu.unk_5c[a0] = 0;
    Rfu.cmd_8800_recvbuf[a0].receiving = 0;
}

u8 sub_800F74C(const u8 *a0)
{
    u8 i;

    if (Rfu.parent_child == MODE_PARENT)
        return FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        Rfu.linkPlayerIdx[i] = a0[i];
    }
    return a0[Rfu.child_slot];
}

void RfuFunc_SendKeysToRfu(void)
{
    if (gReceivedRemoteLinkPlayers
        && gHeldKeyCodeToSend != LINK_KEY_CODE_NULL
        && gLinkTransferringData != TRUE)
    {
        gUnknown_03000D78[0]++;
        gHeldKeyCodeToSend |= (gUnknown_03000D78[0] << 8);
        RfuPrepareSendBuffer(RFU_COMMAND_0xbe00);
    }
}

struct GFtgtGname *GetHostRFUtgtGname(void)
{
    return &gHostRFUtgtGnameBuffer;
}

bool32 IsSendingKeysToRfu(void)
{
    return Rfu.RfuFunc == RfuFunc_SendKeysToRfu;
}

void StartSendingKeysToRfu(void)
{
    Rfu.RfuFunc = RfuFunc_SendKeysToRfu;
}

void ClearLinkRfuCallback(void)
{
    Rfu.RfuFunc = NULL;
}

void sub_800F820(void)
{
    RfuPrepareSendBuffer(RFU_COMMAND_0x4400);
    if (GetMultiplayerId() == 0)
        gSendCmd[6] = GetBlenderArrowPosition();
    gUnknown_020223C0++;
}

void sub_800F850(void)
{
    if (Rfu.RfuFunc == NULL)
        Rfu.RfuFunc = sub_800F820;
}

void RfuHandleReceiveCommand(u8 unused)
{
    u16 i;
    u16 j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
switch (gRecvCmds[i][0] & 0xff00)
        {
        case RFU_COMMAND_0x7800:
            if (Rfu.parent_child == MODE_CHILD && gReceivedRemoteLinkPlayers)
                return;
            // fallthrough
        case RFU_COMMAND_0x7700:
            if (gRfuLinkStatus->parentChild == MODE_CHILD)
            {
                Rfu.playerCount = gRecvCmds[i][1];
                Rfu.unk_cce = sub_800F74C((u8 *)(gRecvCmds[i] + 2));
            }
            break;
        case RFU_COMMAND_0x8800:
            if (Rfu.cmd_8800_recvbuf[i].receiving == 0)
            {
                Rfu.cmd_8800_recvbuf[i].next = 0;
                Rfu.cmd_8800_recvbuf[i].count = gRecvCmds[i][1];
                Rfu.cmd_8800_recvbuf[i].owner = gRecvCmds[i][2];
                Rfu.cmd_8800_recvbuf[i].receivedFlags = 0;
                Rfu.cmd_8800_recvbuf[i].receiving = 1;
                Rfu.unk_5c[i] = 0;
            }
            break;
        case RFU_COMMAND_0x8900:
            if (Rfu.cmd_8800_recvbuf[i].receiving == 1)
            {
                Rfu.cmd_8800_recvbuf[i].next = gRecvCmds[i][0] & 0xff;
                Rfu.cmd_8800_recvbuf[i].receivedFlags |= (1 << Rfu.cmd_8800_recvbuf[i].next);
                for (j = 0; j < 6; j++)
                    gBlockRecvBuffer[i][Rfu.cmd_8800_recvbuf[i].next * 6 + j] = gRecvCmds[i][j + 1];
                if (Rfu.cmd_8800_recvbuf[i].receivedFlags == sAllBlocksReceived[Rfu.cmd_8800_recvbuf[i].count])
                {
                    Rfu.cmd_8800_recvbuf[i].receiving = 2;
                    Rfu_SetBlockReceivedFlag(i);
                    if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && gReceivedRemoteLinkPlayers && Rfu.parent_child == MODE_CHILD)
                        ValidateAndReceivePokemonSioInfo(gBlockRecvBuffer);
                }
            }
            break;
        case RFU_COMMAND_0xa100:
            Rfu_InitBlockSend(gUnknown_082ED6B8[gRecvCmds[i][1]].buffer, (u16)gUnknown_082ED6B8[gRecvCmds[i][1]].size);
            break;
        case RFU_COMMAND_0x5f00:
            Rfu.cmd5f00Ack[i] = 1;
            break;
        case RFU_COMMAND_0x6600:
            if (Rfu.cmd_6600_count == gRecvCmds[i][1])
                Rfu.cmd_6600_recvd[i] = 1;
            break;
        case RFU_COMMAND_0xed00:
            if (Rfu.parent_child == MODE_CHILD)
            {
                if (gReceivedRemoteLinkPlayers)
                {
                    if (gRecvCmds[i][1] & gRfuLinkStatus->connSlotFlag)
                    {
                        gReceivedRemoteLinkPlayers = FALSE;
                        rfu_LMAN_requestChangeAgbClockMaster();
                        Rfu.unk_ce4 = gRecvCmds[i][2];
                    }
                    Rfu.playerCount = gRecvCmds[i][3];
                    sub_80109E8(gRecvCmds[i][1]);
                }
            }
            else
            {
                RfuPrepareSendBuffer(RFU_COMMAND_0xee00);
                gSendCmd[1] = gRecvCmds[i][1];
                gSendCmd[2] = gRecvCmds[i][2];
                gSendCmd[3] = gRecvCmds[i][3];
            }
            break;
        case RFU_COMMAND_0xee00:
            if (Rfu.parent_child == MODE_PARENT)
            {
                Rfu.bm_DisconnectSlot |= gRecvCmds[i][1];
                Rfu.unk_ce4 = gRecvCmds[i][2];
                sub_80109E8(gRecvCmds[i][1]);
            }
            break;
        case RFU_COMMAND_0x4400:
        case RFU_COMMAND_0xbe00:
            gLinkPartnersHeldKeys[i] = gRecvCmds[i][1];
            break;
        }
        if (Rfu.parent_child == MODE_PARENT && Rfu.unk_61[i])
        {
            if (Rfu.unk_61[i] == 4)
            {
                Rfu.unk_5c[i] = 1;
                Rfu.unk_61[i] = 0;
            }
            else
                Rfu.unk_61[i]++;
        }
    }
}

bool8 Cmd8000recvIsFinished(void)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        if (Rfu.cmd_8800_recvbuf[i].receiving)
            return FALSE;
    }
    return TRUE;
}

bool8 sub_800FC88(void)
{
    s32 i;

    for (i = 0; i < Rfu.playerCount; i++)
    {
        if (Rfu.cmd_8800_recvbuf[i].receiving != 2 || Rfu.unk_5c[i] != 1)
            return FALSE;
    }
    return TRUE;
}

void ResetSendDataManager(struct RfuBlockSend *data)
{
    data->next = 0;
    data->count = 0;
    data->payload = NULL;
    data->receivedFlags = 0;
    data->sending = 0;
    data->owner = 0;
    data->receiving = 0;
}

u8 Rfu_GetBlockReceivedStatus(void)
{
    u8 flags = 0;
    s32 i;

    for (i = 0; i < 5; i++)
    {
        if (Rfu.cmd_8800_recvbuf[i].receiving == 2 && Rfu.unk_5c[i] == 1)
        {
            flags |= (1 << i);
        }
    }
    return flags;
}

void RfuPrepareSendBuffer(u16 command)
{
    u8 i;
    u8 *buff;
    u8 tmp;

    gSendCmd[0] = command;
    switch (command)
    {
    case RFU_COMMAND_0x8800:
        gSendCmd[1] = Rfu.cmd_8800_sendbuf.count;
        gSendCmd[2] = Rfu.cmd_8800_sendbuf.owner + 0x80;
        break;
    case RFU_COMMAND_0xa100:
        if (Cmd8000recvIsFinished())
            gSendCmd[1] = Rfu.cmdA100_blockRequestType;
        break;
    case RFU_COMMAND_0x7700:
    case RFU_COMMAND_0x7800:
        tmp = Rfu.bm_PartnerFlags ^ Rfu.bm_DisconnectSlot;
        Rfu.playerCount = gUnknown_082ED695[tmp] + 1;
        gSendCmd[1] = Rfu.playerCount;
        buff = (u8 *)(gSendCmd + 2);
        for (i = 0; i < RFU_CHILD_MAX; i++)
            buff[i] = Rfu.linkPlayerIdx[i];
        break;
    case RFU_COMMAND_0x6600:
    case RFU_COMMAND_0x5f00:
        gSendCmd[1] = Rfu.cmd_6600_count;
        break;
    case RFU_COMMAND_0x4400:
        gSendCmd[0] = command;
        gSendCmd[1] = gMain.heldKeys;
        break;
    case RFU_COMMAND_0x2f00:
        for (i = 0; i < 6; i++)
            gSendCmd[1 + i] = Rfu.unk_f2[i];
        break;
    case RFU_COMMAND_0xbe00:
        gSendCmd[1] = gHeldKeyCodeToSend;
        break;
    case RFU_COMMAND_0xee00:
        break;
    case RFU_COMMAND_0xed00:
        break;
    }
}

void RfuPrepareSend0x2f00(void *data)
{
    if (gSendCmd[0] == 0 && !RfuIsErrorStatus1or2())
    {
        memcpy(Rfu.unk_f2, data, sizeof(Rfu.unk_f2));
        RfuPrepareSendBuffer(RFU_COMMAND_0x2f00);
    }
}

bool32 Rfu_InitBlockSend(const u8 *src, size_t size)
{
    bool8 r4;
    if (Rfu.RfuFunc != NULL)
        return FALSE;
    if (gSendCmd[0] != 0)
        return FALSE;
    if (Rfu.cmd_8800_sendbuf.sending != 0)
    {
        gUnknown_02022B44.unk_83++;
        return FALSE;
    }
    r4 = (size % 12) != 0;
    Rfu.cmd_8800_sendbuf.owner = GetMultiplayerId();
    Rfu.cmd_8800_sendbuf.sending = 1;
    Rfu.cmd_8800_sendbuf.count = (size / 12) + r4;
    Rfu.cmd_8800_sendbuf.next = 0;
    if (size > 0x100) // should never be reached
        Rfu.cmd_8800_sendbuf.payload = src;
    else
    {
        if (src != gBlockSendBuffer)
            memcpy(gBlockSendBuffer, src, size);
        Rfu.cmd_8800_sendbuf.payload = gBlockSendBuffer;
    }
    RfuPrepareSendBuffer(RFU_COMMAND_0x8800);
    Rfu.RfuFunc = RfuFunc_HandleBlockSend;
    Rfu.unk_5b = 0;
    return TRUE;
}

void RfuFunc_HandleBlockSend(void)
{
    if (gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFU_COMMAND_0x8800);
        if (Rfu.parent_child == MODE_PARENT)
        {
            if (++Rfu.unk_5b > 2)
                Rfu.RfuFunc = RfuFunc_SendNextBlock;
        }
        else
        {
            if ((gRecvCmds[GetMultiplayerId()][0] & 0xff00) == RFU_COMMAND_0x8800)
                Rfu.RfuFunc = RfuFunc_SendNextBlock;
        }
    }
}

void RfuFunc_SendNextBlock(void)
{
    s32 i;
    const u8 *src = Rfu.cmd_8800_sendbuf.payload;
    gSendCmd[0] = RFU_COMMAND_0x8900 | Rfu.cmd_8800_sendbuf.next;
    for (i = 0; i < 7; i++)
        gSendCmd[i + 1] = (src[(i << 1) + Rfu.cmd_8800_sendbuf.next * 12 + 1] << 8) | src[(i << 1) + Rfu.cmd_8800_sendbuf.next * 12 + 0];
    Rfu.cmd_8800_sendbuf.next++;
    if (Rfu.cmd_8800_sendbuf.count <= Rfu.cmd_8800_sendbuf.next)
    {
        Rfu.cmd_8800_sendbuf.sending = 0;
        Rfu.RfuFunc = RfuFunc_SendLastBlock;
    }
}

void RfuFunc_SendLastBlock(void)
{
    const u8 *src = Rfu.cmd_8800_sendbuf.payload;
    u8 mpId = GetMultiplayerId();
    s32 i;
    if (Rfu.parent_child == MODE_CHILD)
    {
        gSendCmd[0] = RFU_COMMAND_0x8900 | (Rfu.cmd_8800_sendbuf.count - 1);
        for (i = 0; i < 7; i++)
            gSendCmd[i + 1] = (src[(i << 1) + (Rfu.cmd_8800_sendbuf.count - 1) * 12 + 1] << 8) | src[(i << 1) + (Rfu.cmd_8800_sendbuf.count - 1) * 12 + 0];
        if ((u8)gRecvCmds[mpId][0] == Rfu.cmd_8800_sendbuf.count - 1)
        {
            if (Rfu.cmd_8800_recvbuf[mpId].receivedFlags != sAllBlocksReceived[Rfu.cmd_8800_recvbuf[mpId].count])
            {
                HandleSendFailure(mpId, Rfu.cmd_8800_recvbuf[mpId].receivedFlags);
                gUnknown_02022B44.unk_64++;
            }
            else
                Rfu.RfuFunc = NULL;
        }
    }
    else
        Rfu.RfuFunc = NULL;
}

bool8 LinkRfu_PrepareCmd0xA100(u8 blockRequestType)
{
    Rfu.cmdA100_blockRequestType = blockRequestType;
    RfuPrepareSendBuffer(RFU_COMMAND_0xa100);
    return TRUE;
}

void RfuFunc_End5F00_PowerDownRfu(void)
{
    rfu_clearAllSlot();
    rfu_LMAN_powerDownRFU();
    gReceivedRemoteLinkPlayers = FALSE;
    Rfu.isShuttingDown = TRUE;
    Rfu.RfuFunc = NULL;
}

void RfuFunc_End5F00_ParentDisconnect(void)
{
    rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
    rfu_waitREQComplete();
    RfuFunc_End5F00_PowerDownRfu();
}

void RfuFunc_End5F00(void)
{
    if (Rfu.parent_child == MODE_CHILD)
    {
        rfu_LMAN_requestChangeAgbClockMaster();
        Rfu.unk_ce4 = 2;
    }
    else
        Rfu.RfuFunc = RfuFunc_End5F00_ParentDisconnect;
}

void LinkRfu_FatalError(void)
{
    rfu_LMAN_requestChangeAgbClockMaster();
    Rfu.unk_ce4 = 1;
    Rfu.bm_DisconnectSlot = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
}

void RfuFunc_WaitAck5F00(void)
{
    s32 i;
    u8 playerCount = Rfu.playerCount;
    s32 count = 0;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (Rfu.cmd5f00Ack[i])
            count++;
    }
    if (count == playerCount)
    {
        gBattleTypeFlags &= ~BATTLE_TYPE_20;
        if (Rfu.parent_child == MODE_CHILD)
        {
            Rfu.errorState = 3;
            RfuFunc_End5F00();
        }
        else
            Rfu.RfuFunc = RfuFunc_End5F00;
    }
}

void RfuFunc_BuildCommand5F00(void)
{
    if (gSendCmd[0] == 0 && !Rfu.unk_ce8)
    {
        RfuPrepareSendBuffer(RFU_COMMAND_0x5f00);
        Rfu.RfuFunc = RfuFunc_WaitAck5F00;
    }
}

void Task_WaitRfuFuncAndSetBuildCmd5F00(u8 taskId)
{
    if (Rfu.RfuFunc == NULL)
    {
        Rfu.unk_cd9 = 1;
        Rfu.RfuFunc = RfuFunc_BuildCommand5F00;
        DestroyTask(taskId);
    }
}

void Rfu_BeginBuildAndSendCommand5F(void)
{
    if (!FuncIsActiveTask(Task_WaitRfuFuncAndSetBuildCmd5F00))
        CreateTask(Task_WaitRfuFuncAndSetBuildCmd5F00, 5);
}

void RfuFunc_Send6600_3(void)
{
    u8 playerCount;
    u8 i;

    if (GetMultiplayerId() != 0) //child
    {
        if (Rfu.unk_124.count == 0 && Rfu.cmd_6600_timer > 60)
        {
			RfuPrepareSendBuffer(RFU_COMMAND_0x6600);
            Rfu.cmd_6600_timer = 0;
        }
    }
    playerCount = GetLinkPlayerCount();
    for (i = 0; i < playerCount; i++)
    {
        if (Rfu.cmd_6600_recvd[i] == 0)
            break;
    }
    if (i == playerCount)
    {
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            Rfu.cmd_6600_recvd[i] = 0;
        Rfu.cmd_6600_count++;
        Rfu.RfuFunc = NULL;
    }
    Rfu.cmd_6600_timer++;
}

void RfuFunc_Send6600_2(void)
{
    if (Rfu.unk_124.count == 0 && gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFU_COMMAND_0x6600);
        Rfu.RfuFunc = RfuFunc_Send6600_3;
    }
}

void RfuFunc_Send6600_1(void)
{
    u8 i;
    u8 playerCount;

    if (GetMultiplayerId() != 0) // child
    {
        if (Rfu.unk_124.count == 0 && gSendCmd[0] == 0)
        {
            RfuPrepareSendBuffer(RFU_COMMAND_0x6600);
            Rfu.RfuFunc = RfuFunc_Send6600_3;
        }
    }
    else // parent
    {
        playerCount = GetLinkPlayerCount();
        for (i = 1; i < playerCount; i++)
        {
            if (Rfu.cmd_6600_recvd[i] == 0)
                break;
        }
        if (i == playerCount)
        {
            if (Rfu.unk_124.count == 0 && gSendCmd[0] == 0)
            {
                RfuPrepareSendBuffer(RFU_COMMAND_0x6600);
                Rfu.RfuFunc = RfuFunc_Send6600_2;
            }
        }
    }
}

void LinkRfu_SetRfuFuncToSend6600(void)
{
    if (Rfu.RfuFunc == NULL)
    {
        Rfu.RfuFunc = RfuFunc_Send6600_1;
        Rfu.cmd_6600_timer = 0;
    }
}

bool32 RfuSerialNumberIsValid(u32 serialNo)
{
    s32 i;
    for (i = 0; sAcceptedSerialNos[i] != serialNo; i++)
    {
        if (sAcceptedSerialNos[i] == 0xFFFF)
            return FALSE;
    }
    return TRUE;
}

u8 ToggleLMANlinkRecovery(bool32 a0)
{
    if (!a0)
        return rfu_LMAN_setLinkRecovery(0, 0);
    rfu_LMAN_setLinkRecovery(1, 600);
    return 0;
}

void sub_80104B0(void)
{
    Rfu.unk_cd9 = 1;
    rfu_LMAN_stopManager(FALSE);
}

u8 LinkRfu_GetMultiplayerId(void)
{
    if (Rfu.parent_child == MODE_PARENT)
        return 0;
    return Rfu.unk_cce;
}

u8 GetRfuPlayerCount(void)
{
    return Rfu.playerCount;
}

bool8 IsLinkRfuTaskFinished(void)
{
    if (Rfu.unk_f1 == 2)
        return FALSE;
    return Rfu.RfuFunc ? FALSE : TRUE;
}

void CallRfuFunc(void)
{
    if (Rfu.RfuFunc)
        Rfu.RfuFunc();
}

bool8 sub_8010540(void)
{
    s32 i;
    bool8 retval = FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Rfu.unk_cd1[i] < 5 || Rfu.unk_cd1[i] > 6)
        {
            if (gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS || gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN)
            {
                if (Rfu.unk_cd5[i] == 8)
                {
                    Rfu.unk_cd1[i] = 9;
                    Rfu.unk_cd5[i] = 10;
                    rfu_clearSlot(TYPE_NI_RECV, i);
                    rfu_NI_setSendData(1 << i, 8, Rfu.unk_cd1 + i, 1);
                    retval = TRUE;
                }

            }
            else if (gRfuSlotStatusNI[Rfu.child_slot]->recv.state == SLOT_STATE_RECV_FAILED)
            {
                rfu_clearSlot(TYPE_NI_RECV, i);
            }
        }
    }
    return retval;
}

bool32 sub_80105EC(void)
{
    u8 flags = 0;
    s32 i;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Rfu.unk_cd5[i] == 11)
        {
            flags |= (1 << i);
            Rfu.unk_cd5[i] = 0;
        }
    }
    if (flags)
    {
        rfu_REQ_disconnect(flags);
        rfu_waitREQComplete();
    }
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (Rfu.unk_cd5[i] == 10 || Rfu.unk_cd5[i] == 11)
            return TRUE;
    }
    return FALSE;
}

bool32 TrainerIdAndNameStillInPartnersList(u16 trainerId, const u8 *trainerName)
{
    u8 r1 = GetPartnerIndexByNameAndTrainerID(trainerName, trainerId);
    if (r1 == 0xFF)
        return TRUE;
    if (Rfu.unk_cd1[r1] == 9)
        return TRUE;
    return FALSE;
}

void SendByteToPartnerByIdAndName(u8 value, u16 trainerId, const u8 *trainerName)
{
    u8 slotNo = GetPartnerIndexByNameAndTrainerID(trainerName, trainerId);
    Rfu.unk_cd1[slotNo] = value;
    rfu_clearSlot(TYPE_NI_SEND, slotNo);
    rfu_NI_setSendData(1 << slotNo, 8, Rfu.unk_cd1 + slotNo, 1);
}

void LinkRfuNIsend8(void)
{
    Rfu.unk_c85 = 8;
    rfu_clearSlot(TYPE_NI_SEND, Rfu.child_slot);
    rfu_NI_setSendData(1 << Rfu.child_slot, 8, &Rfu.unk_c85, 1);
}

u32 WaitSendByteToPartnerByIdAndName(u16 trainerId, const u8 *trainerName)
{
    u8 r0 = GetPartnerIndexByNameAndTrainerID(trainerName, trainerId);
    if (r0 == 0xFF)
        return 2;
    if (gRfuSlotStatusNI[r0]->send.state == SLOT_STATE_READY)
        return 1;
    return 0;
}

void sub_8010750(void)
{
    s32 i;

    sub_8010540();
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (gRfuSlotStatusNI[i]->send.state == SLOT_STATE_SEND_SUCCESS || gRfuSlotStatusNI[i]->send.state == SLOT_STATE_SEND_FAILED)
        {
            if (Rfu.unk_cd5[i] == 10)
                Rfu.unk_cd5[i] = 11;
            rfu_clearSlot(TYPE_NI_SEND, i);
        }
    }
}

s32 sub_80107A0(void)
{
    s32 retval = 0;
    if (Rfu.unk_c85 == 8)
    {
        if (gRfuSlotStatusNI[Rfu.child_slot]->send.state == SLOT_STATE_SEND_SUCCESS || gRfuSlotStatusNI[Rfu.child_slot]->send.state == SLOT_STATE_SEND_FAILED)
            rfu_clearSlot(TYPE_NI_SEND, Rfu.child_slot);
    }
    if (gRfuSlotStatusNI[Rfu.child_slot]->recv.state == SLOT_STATE_RECV_SUCCESS || gRfuSlotStatusNI[Rfu.child_slot]->recv.state == SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN)
    {
        rfu_clearSlot(TYPE_NI_RECV, Rfu.child_slot);
        RfuSetErrorStatus(Rfu.unk_c86, 0);
        retval = Rfu.unk_c86;
    }
    else if (gRfuSlotStatusNI[Rfu.child_slot]->recv.state == SLOT_STATE_RECV_FAILED)
    {
        rfu_clearSlot(TYPE_NI_RECV, Rfu.child_slot);
        retval = 6;
    }
    return retval;
}

void sub_801084C(u8 taskId)
{
    s32 i;

    if (Rfu.unk_f1 == 1 || Rfu.unk_f1 == 2)
    {
        Rfu.unk_ce8 = FALSE;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (Cmd8000recvIsFinished())
            {
                ResetBlockReceivedFlags();
                PrepareLocalLinkPlayerBlock();
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (Rfu.parent_child == MODE_PARENT)
            {
                if (gReceivedRemoteLinkPlayers)
                    RfuPrepareSendBuffer(RFU_COMMAND_0x7800);
                else
                    RfuPrepareSendBuffer(RFU_COMMAND_0x7700);
                gTasks[taskId].data[0] = 101;
            }
            else
                gTasks[taskId].data[0] = 2;
            break;
        case 101:
            if (gSendCmd[0] == 0)
                gTasks[taskId].data[0] = 2;
            break;
        case 2:
            if (Rfu.playerCount)
                gTasks[taskId].data[0]++;
            break;
        case 3:
            if (Rfu.parent_child == MODE_PARENT)
            {
                if (Cmd8000recvIsFinished())
                {
                    Rfu.cmdA100_blockRequestType = 0;
                    RfuPrepareSendBuffer(RFU_COMMAND_0xa100);
                    gTasks[taskId].data[0]++;
                }
            }
            else
                gTasks[taskId].data[0]++;
            break;
        case 4:
            if (sub_800FC88())
                gTasks[taskId].data[0]++;
            break;
        case 5:
            for (i = 0; i < Rfu.playerCount; i++)
            {
                LinkPlayerFromBlock(i);
                Rfu_ResetBlockReceivedFlag(i);
            }
            gTasks[taskId].data[0]++;
            break;
        case 6:
            DestroyTask(taskId);
            gReceivedRemoteLinkPlayers = TRUE;
            Rfu.unk_ce8 = FALSE;
            rfu_LMAN_setLinkRecovery(1, 600);
            if (Rfu.unionRoomChatters)
            {
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((Rfu.unionRoomChatters >> i) & 1)
                    {
                        Rfu.unk_ce5 = 1 << i;
                        Rfu.unionRoomChatters ^= (1 << i);
                    }
                }
            }
            break;
    }
}

void sub_80109E8(u16 a0)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((a0 >> i) & 1)
            Rfu.linkPlayerIdx[i] = 0;
    }
}

void ReceiveRfuLinkPlayers(const struct SioInfo *chunk)
{
    s32 i;
    Rfu.playerCount = chunk->playerCount;
    for (i = 0; i < RFU_CHILD_MAX; i++)
        Rfu.linkPlayerIdx[i] = chunk->linkPlayerIdx[i];
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        gLinkPlayers[i] = chunk->linkPlayers[i];
        IntlConvertLinkPlayerName(gLinkPlayers + i);
    }
}

void ValidateAndReceivePokemonSioInfo(void *recvBuffer)
{
    if (strcmp("PokemonSioInfo", recvBuffer) == 0)
    {
        ReceiveRfuLinkPlayers(recvBuffer);
        CpuFill16(0, recvBuffer, sizeof(struct SioInfo));
        ResetBlockReceivedFlag(0);
    }
}

void Task_ExchangeLinkPlayers(u8 taskId)
{
    s32 i;
    struct LinkPlayerBlock *r2;
    struct SioInfo *r5;
    u8 r4 = Rfu.linkPlayerIdx[gUnknown_082ED68C[Rfu.unk_ce9]];
    if (Rfu.unk_f1 == 1 || Rfu.unk_f1 == 2)
    {
        Rfu.unk_ce8 = FALSE;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (gSendCmd[0] == 0)
            {
                ResetBlockReceivedFlag(r4);
                RfuPrepareSendBuffer(RFU_COMMAND_0x7800);
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (gSendCmd[0] == 0)
                gTasks[taskId].data[0]++;
            break;
        case 2:
            if ((GetBlockReceivedStatus() >> r4) & 1)
            {
                ResetBlockReceivedFlag(r4);
                r2 = (struct LinkPlayerBlock *)gBlockRecvBuffer[r4];
                gLinkPlayers[r4] = r2->linkPlayer;
                IntlConvertLinkPlayerName(gLinkPlayers + r4);
                gTasks[taskId].data[0]++;
            }
            break;
        case 3:
            r5 = (struct SioInfo *)gBlockSendBuffer;
            memcpy(r5->magic, "PokemonSioInfo", sizeof("PokemonSioInfo"));
            r5->playerCount = Rfu.playerCount;
            for (i = 0; i < RFU_CHILD_MAX; i++)
                r5->linkPlayerIdx[i] = Rfu.linkPlayerIdx[i];
            memcpy(r5->linkPlayers, gLinkPlayers, sizeof gLinkPlayers);
            gTasks[taskId].data[0]++;
            // fallthrough
        case 4:
            r5 = (struct SioInfo *)gBlockSendBuffer;
            r5->playerCount = Rfu.playerCount;
            for (i = 0; i < RFU_CHILD_MAX; i++)
                r5->linkPlayerIdx[i] = Rfu.linkPlayerIdx[i];
            memcpy(r5->linkPlayers, gLinkPlayers, sizeof gLinkPlayers);
            if (SendBlock(0, gBlockSendBuffer, 0xa0))
                gTasks[taskId].data[0]++;
            break;
        case 5:
            if (IsLinkTaskFinished() && GetBlockReceivedStatus() & 1)
            {
                CpuFill16(0, gBlockRecvBuffer, sizeof(struct SioInfo));
                ResetBlockReceivedFlag(0);
                Rfu.unk_ce8 = FALSE;
                if (Rfu.unionRoomChatters)
                {
                    for (i = 0; i < RFU_CHILD_MAX; i++)
                    {
                        if ((Rfu.unionRoomChatters >> i) & 1)
                        {
                            Rfu.unk_ce5 = 1 << i;
                            Rfu.unionRoomChatters ^= (1 << i);
                            Rfu.unk_ce8 = TRUE;
                            break;
                        }
                    }
                }
                DestroyTask(taskId);
            }
            break;
    }
}

void sub_8010D0C(u8 taskId)
{
    if (Rfu.unk_f1 == 1 || Rfu.unk_f1 == 2)
        DestroyTask(taskId);
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (Rfu.playerCount)
            {
                PrepareLocalLinkPlayerBlock();
                SendBlock(0, gBlockSendBuffer, sizeof(struct LinkPlayerBlock));
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (IsLinkTaskFinished())
                gTasks[taskId].data[0]++;
            break;
        case 2:
            if (GetBlockReceivedStatus() & 1)
            {
                ReceiveRfuLinkPlayers((const struct SioInfo *)gBlockRecvBuffer);
                ResetBlockReceivedFlag(0);
                gReceivedRemoteLinkPlayers = TRUE;
                DestroyTask(taskId);
            }
            break;
    }
}

void RfuCheckErrorStatus(void)
{
    if (Rfu.errorState == 1 && lman.childClockSlave_flag == 0)
    {
        if (gMain.callback2 == c2_mystery_gift_e_reader_run || lman.init_param->mboot_flag)
            gWirelessCommType = 2;
        SetMainCallback2(CB2_LinkError);
        gMain.savedCallback = CB2_LinkError;
        SetLinkErrorFromRfu((Rfu.linkman_msg << 16) | (Rfu.linkman_param[0] << 8) | Rfu.linkman_param[1], Rfu.unk_124.count, Rfu.sendQueue.count, RfuGetErrorStatus() == 2);
        Rfu.errorState = 2;
        CloseLink();
    }
    else if (Rfu.sendQueue.full == 1 || Rfu.unk_124.full == 1)
    {
        if (lman.childClockSlave_flag)
            rfu_LMAN_requestChangeAgbClockMaster();
        RfuSetErrorStatus(1, 0x7000);
        GetLinkmanErrorParams(0x7000);
    }
}

void rfu_REQ_recvData_then_sendData(void)
{
    if (lman.parent_child == MODE_PARENT)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(FALSE);
    }
}

bool32 LinkRfuMain1(void)
{
    bool32 retval = FALSE;
    Rfu.parentId = 0;
    rfu_LMAN_manager_entity(Random2());
    if (!Rfu.isShuttingDown)
    {
        switch (Rfu.parent_child)
        {
            case 1:
                sub_800F0F8();
                break;
            case 0:
                retval = RfuProcessEnqueuedRecvBlock();
                break;
            case 2:
                rfu_REQ_recvData_then_sendData();
                break;
        }
    }
    return retval;
}

bool32 LinkRfuMain2(void)
{
    bool32 retval = FALSE;
    if (!Rfu.isShuttingDown)
    {
        if (Rfu.parent_child == MODE_PARENT)
            retval = sub_800F1E0();
        RfuCheckErrorStatus();
    }
    return retval;
}

void CopyPlayerNameToUnameBuffer(void)
{
    StringCopy(gHostRFUtgtUnameBuffer, gSaveBlock2Ptr->playerName);
}

void ClearAndInitHostRFUtgtGname(void)
{
    memset(&gHostRFUtgtGnameBuffer, 0, RFU_GAME_NAME_LENGTH);
    InitHostRFUtgtGname(&gHostRFUtgtGnameBuffer, 0, FALSE, 0);
}

void SetHostRFUtgtGname(u8 activity, u32 child_sprite_genders, u32 started)
{
    InitHostRFUtgtGname(&gHostRFUtgtGnameBuffer, activity, started, child_sprite_genders);
}

void SetGnameBufferWonderFlags(bool32 hasNews, bool32 hasCard)
{
    gHostRFUtgtGnameBuffer.unk_00.hasNews = hasNews;
    gHostRFUtgtGnameBuffer.unk_00.hasCard = hasCard;
}

void RfuUpdatePlayerGnameStateAndSend(u32 type, u32 species, u32 level)
{
    gHostRFUtgtGnameBuffer.type = type;
    gHostRFUtgtGnameBuffer.species = species;
    gHostRFUtgtGnameBuffer.level = level;
}

u8 sub_801100C(s32 a0)
{
    u8 retval = 0x80;
    retval |= (gLinkPlayers[a0].gender << 3);
    retval |= (gLinkPlayers[a0].trainerId & 7);
    return retval;
}

void sub_801103C(void)
{
    struct GFtgtGname *r5 = &gHostRFUtgtGnameBuffer;
    s32 i;

    for (i = 1; i < GetLinkPlayerCount(); i++)
        r5->child_sprite_gender[i - 1] = sub_801100C(i);
}

void UpdateGameData_GroupLockedIn(bool8 started)
{
    gHostRFUtgtGnameBuffer.started = started;
    rfu_REQ_configGameData(0, 0x0002, (void *)&gHostRFUtgtGnameBuffer, gHostRFUtgtUnameBuffer);
}

void UpdateGameDataWithActivitySpriteGendersFlag(u8 activity, u32 child_sprite_genders, u32 started)
{
    if (activity)
        SetHostRFUtgtGname(activity, child_sprite_genders, started);
    rfu_REQ_configGameData(0, 0x0002, (void *)&gHostRFUtgtGnameBuffer, gHostRFUtgtUnameBuffer);
}

void sub_80110B8(u32 linkPlayerCount)
{
    s32 i;
    u32 numConnectedChildren;
    u32 child_sprite_genders;
    s32 bm_child_slots;

    if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        numConnectedChildren = 0;
        child_sprite_genders = 0;
        bm_child_slots = Rfu.bm_PartnerFlags ^ Rfu.bm_DisconnectSlot;
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((bm_child_slots >> i) & 1)
            {
                // The 0x80 prevents this element from being incorrectly read as a 0.
				child_sprite_genders |= ((
					0x80 | ((gLinkPlayers[Rfu.linkPlayerIdx[i]].gender & 1) << 3) | (gLinkPlayers[Rfu.linkPlayerIdx[i]].trainerId & 7)
				) << (numConnectedChildren << 3));
                numConnectedChildren++;
                if (numConnectedChildren == linkPlayerCount - 1)
                    break;
            }
        }
        UpdateGameDataWithActivitySpriteGendersFlag(ACTIVITY_CHAT | IN_UNION_ROOM, child_sprite_genders, 0);
    }
}

void GetLinkmanErrorParams(u32 msg)
{
    if (Rfu.errorState == 0)
    {
        Rfu.linkman_param[0] = lman.param[0];
        Rfu.linkman_param[1] = lman.param[1];
        Rfu.linkman_msg = msg;
        Rfu.errorState = 1;
    }
}

void ResetErrorState(void)
{
    Rfu.errorState = 0;
}

void sub_80111B0(bool32 a0)
{
    if (!a0)
        Rfu.errorState = 0;
    else
        Rfu.errorState = 4;
}

void sub_80111DC(void)
{
    sub_8011E94(lman.acceptSlot_flag, 1);
    Rfu.RfuFunc = NULL;
}

void sub_80111FC(void)
{
    Rfu.RfuFunc = sub_80111DC;
}

void LmanCallback_Parent2(u8 msg, u8 param_count)
{
    u8 i;
    u8 bmDisconnectFlag = 0;
    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        Rfu.state = 2;
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
        sub_80115EC(lman.param[0]);
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((lman.param[0] >> i) & 1)
            {
                struct GFtgtGname *structPtr = (void *)&gRfuLinkStatus->partner[i].gname;
                if (structPtr->activity == GetHostRFUtgtGname()->activity)
                {
                    Rfu.unk_cd1[i] = 0;
                    Rfu.unk_cd5[i] = 0;
                    rfu_setRecvBuffer(TYPE_NI, i, Rfu.unk_cd5 + i, 1);
                }
                else
                {
                    bmDisconnectFlag |= (1 << i);
                }
            }
        }
        if (bmDisconnectFlag)
        {
            rfu_REQ_disconnect(bmDisconnectFlag);
            rfu_waitREQComplete();
        }
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_REJECTED:
        break;
    case LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_END_WAIT_CHILD_NAME:
        if (Rfu.acceptSlot_flag != lman.acceptSlot_flag)
        {
            rfu_REQ_disconnect(Rfu.acceptSlot_flag ^ lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        Rfu.state = 17;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        Rfu.linkLossRecoveryState = 1;
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        Rfu.linkLossRecoveryState = 3;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        Rfu.linkLossRecoveryState = 4;
        Rfu.bm_PartnerFlags &= ~lman.param[0];
        if (gReceivedRemoteLinkPlayers == TRUE)
        {
            if (Rfu.bm_PartnerFlags == 0)
                GetLinkmanErrorParams(msg);
            else
                sub_80111FC();
        }
        RfuSetErrorStatus(2, msg);
        break;
    case 0x34:
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetErrorStatus(1, msg);
        GetLinkmanErrorParams(msg);
        Rfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        GetLinkmanErrorParams(msg);
        RfuSetErrorStatus(1, msg);
        Rfu.unk_cdb = 1;
        break;
    }
}

void LmanCallback_Child(u8 msg, u8 param_count)
{
    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        Rfu.state = 6;
        break;
    case LMAN_MSG_PARENT_FOUND:
        Rfu.parentId = lman.param[0];
        break;
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
        Rfu.child_slot = lman.param[0];
        break;
    case LMAN_MSG_CONNECT_PARENT_FAILED:
        RfuSetErrorStatus(2, msg);
        break;
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED:
        Rfu.state = 11;
        Rfu.unk_c85 = 0;
        Rfu.unk_c86 = 0;
        rfu_setRecvBuffer(TYPE_NI, Rfu.child_slot, &Rfu.unk_c86, 1);
        rfu_setRecvBuffer(TYPE_UNI, Rfu.child_slot, Rfu.unk_c3f, sizeof(Rfu.unk_c3f));
        break;
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED:
        RfuSetErrorStatus(2, msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
        Rfu.linkLossRecoveryState = 2;
        if (Rfu.unk_c86 == 6)
            break;
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        if (Rfu.linkLossRecoveryState != 2)
            Rfu.linkLossRecoveryState = 4;
        if (Rfu.unk_c86 != 9)
            RfuSetErrorStatus(2, msg);
        rfu_dbg_print_str("LINK LOSS DISCONNECT!", 5, 5);
        if (gReceivedRemoteLinkPlayers == TRUE)
            GetLinkmanErrorParams(msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        Rfu.linkLossRecoveryState = 1;
        rfu_dbg_print_str("LINK LOSS RECOVERY NOW", 5, 5);
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        Rfu.linkLossRecoveryState = 3;
        Rfu.unk_c3c = 1;
        break;
    case 0x34:
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetErrorStatus(1, msg);
        GetLinkmanErrorParams(msg);
        Rfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        RfuSetErrorStatus(1, msg);
        GetLinkmanErrorParams(msg);
        Rfu.unk_cdb = 1;
        break;
    }
}

void sub_80115EC(s32 bmConnectedFlag)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((bmConnectedFlag >> i) & 1)
        {
            Rfu.unk_cea[i] = 0;
            Rfu.unk_cee[i] = 0xFF;
        }
    }
}

u8 GetNewChildrenInUnionRoomChat(s32 bmNewChildSlot)
{
    u8 ret = 0;
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((bmNewChildSlot >> i) & 1)
        {
            struct GFtgtGname *structPtr = (void *)gRfuLinkStatus->partner[i].gname;
            if (structPtr->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
                ret |= (1 << i);
        }
    }

    return ret;
}

void LmanCallback_Parent(u8 msg, u8 param_count)
{
    u8 r1;

    switch (msg)
    {
    case LMAN_MSG_INITIALIZE_COMPLETED:
        Rfu.state = 17;
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_DETECTED:
        RfuSetErrorStatus(4, 0);
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED:
        if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && Rfu.unk_cd9 == 0)
        {
            u8 bmAcceptSlot = GetNewChildrenInUnionRoomChat(lman.param[0]);
            if (bmAcceptSlot != 0)
            {
                r1 = 1 << sub_800E87C(bmAcceptSlot);
                if (Rfu.unionRoomChatters == 0 && !Rfu.unk_ce8)
                {
                    Rfu.unk_ce5 = r1;
                    Rfu.unionRoomChatters |= (r1 ^ bmAcceptSlot);
                    Rfu.unk_ce8 = TRUE;
                }
                else
                {
                    Rfu.unionRoomChatters |= bmAcceptSlot;
                }
            }
            if (bmAcceptSlot != lman.param[0])
            {
                Rfu.bm_DisconnectSlot |= (bmAcceptSlot ^ lman.param[0]);
                Rfu.unk_ce4 = 2;
            }
        }
        else if (GetHostRFUtgtGname()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM))
        {
            rfu_REQ_disconnect(lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        sub_80115EC(lman.param[0]);
        break;
    case LMAN_MSG_NEW_CHILD_CONNECT_REJECTED:
        break;
    case LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_END_WAIT_CHILD_NAME:
        if (GetHostRFUtgtGname()->activity != (ACTIVITY_CHAT | IN_UNION_ROOM) && lman.acceptCount > 1)
        {
            r1 = 1 << sub_800E87C(lman.param[0]);
            rfu_REQ_disconnect(lman.acceptSlot_flag ^ r1);
            rfu_waitREQComplete();
        }
        if (Rfu.state == 15)
            Rfu.state = 16;
        break;
    case LMAN_MSG_PARENT_FOUND:
        Rfu.parentId = lman.param[0];
        break;
    case LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED:
        break;
    case LMAN_MSG_CONNECT_PARENT_SUCCESSED:
        Rfu.child_slot = lman.param[0];
        break;
    case LMAN_MSG_CONNECT_PARENT_FAILED:
        Rfu.state = 18;
        if (Rfu.unk_ccf < 2)
        {
            Rfu.unk_ccf++;
            CreateTask(sub_801209C, 2);
        }
        else
        {
            RfuSetErrorStatus(2, msg);
        }
        break;
    case LMAN_MSG_CHILD_NAME_SEND_COMPLETED:
        Rfu.state = 13;
        RfuSetErrorStatus(3, 0);
        rfu_setRecvBuffer(TYPE_UNI, Rfu.child_slot, Rfu.unk_c3f, sizeof(Rfu.unk_c3f));
        break;
    case LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED:
        RfuSetErrorStatus(2, msg);
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY:
        if (lman.acceptSlot_flag & lman.param[0])
            Rfu.linkLossRecoveryState = 1;
        break;
    case LMAN_MSG_LINK_RECOVERY_SUCCESSED:
        Rfu.linkLossRecoveryState = 3;
        if (gRfuLinkStatus->parentChild == MODE_CHILD)
            Rfu.unk_c3c = 1;
        break;
    case LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED:
        Rfu.linkLossRecoveryState = 2;
        // fallthrough
    case LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED:
        if (Rfu.linkLossRecoveryState != 2)
            Rfu.linkLossRecoveryState = 4;
        if (Rfu.parent_child == MODE_PARENT)
        {
            if (gReceivedRemoteLinkPlayers == TRUE)
            {
                Rfu.bm_PartnerFlags &= ~(lman.param[0]);
                if (Rfu.bm_PartnerFlags == 0)
                    GetLinkmanErrorParams(msg);
                else
                    sub_80111FC();
            }
        }
        else if (Rfu.unk_ce4 != 2 && gReceivedRemoteLinkPlayers == TRUE)
        {
            GetLinkmanErrorParams(msg);
            rfu_LMAN_stopManager(FALSE);
        }

        if (gRfuLinkStatus->parentChild == MODE_NEUTRAL && lman.pcswitch_flag == 0 && FuncIsActiveTask(Task_LinkRfu_UnionRoomListen) == TRUE)
            Rfu.state = 17;

        RfuSetErrorStatus(2, msg);
        break;
    case LMAN_MSG_LINK_DISCONNECTED_BY_USER:
        Rfu.bm_DisconnectSlot = 0;
        break;
    case LMAN_MSG_RFU_POWER_DOWN:
    case LMAN_MSG_MANAGER_STOPPED:
    case LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET:
        break;
    case LMAN_MSG_LMAN_API_ERROR_RETURN:
        RfuSetErrorStatus(1, msg);
        GetLinkmanErrorParams(msg);
        Rfu.isShuttingDown = TRUE;
        break;
    case LMAN_MSG_REQ_API_ERROR:
    case LMAN_MSG_WATCH_DOG_TIMER_ERROR:
    case LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA:
    case LMAN_MSG_RFU_FATAL_ERROR:
        GetLinkmanErrorParams(msg);
        RfuSetErrorStatus(1, msg);
        Rfu.unk_cdb = 0;
        break;
    }
}

void sub_8011A50(void)
{
    Rfu.unk_ce4 = 2;
}

void RfuSetErrorStatus(u8 a0, u16 msg)
{
    Rfu.unk_f1 = a0;
    Rfu.linkman_msg = msg;
}

u8 RfuGetErrorStatus(void)
{
    return Rfu.unk_f1;
}

bool32 RfuIsErrorStatus1or2(void)
{
    u32 var = RfuGetErrorStatus();
    if (var == 1 || var == 2)
        return TRUE;
    else
        return FALSE;
}

bool32 GetRfuUnkCE8(void)
{
    return Rfu.unk_ce8;
}

bool8 Rfu_IsMaster(void)
{
    return Rfu.parent_child;
}

void RfuVSync(void)
{
    rfu_LMAN_syncVBlank();
}

void sub_8011AC8(void)
{
    CpuFill32(0, gRecvCmds, sizeof(gRecvCmds));
}

void sub_8011AE8(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_8011AFC(void)
{
    s32 i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();
    SetVBlankCallback(sub_8011AE8);
    if (IsWirelessAdapterConnected())
    {
        gLinkType = LINKTYPE_0x1111;
        SetWirelessCommType1();
        OpenLink();
        SeedRng(gMain.vblankCounter2);
        for (i = 0; i < RFU_CHILD_MAX; i++)
            gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_1D_MAP);
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        LinkRfu_CreateIdleTask();
        SetMainCallback2(sub_8011BF8);
    }
}

bool32 IsUnionRoomListenTaskActive(void)
{
    return FuncIsActiveTask(Task_LinkRfu_UnionRoomListen);
}

void LinkRfu_CreateIdleTask(void)
{
    if (!FuncIsActiveTask(Task_idle))
        Rfu.unk_66 = CreateTask(Task_idle, 0);
}

void LinkRfu_DestroyIdleTask(void)
{
     if (FuncIsActiveTask(Task_idle) == TRUE)
        DestroyTask(Rfu.unk_66);
}

void sub_8011BF8(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void InitializeRfuLinkManager_LinkLeader(u32 availSlots)
{
    Rfu.parent_child = MODE_PARENT;
    CopyPlayerNameToUnameBuffer();
    rfu_LMAN_initializeManager(LmanCallback_Parent2, NULL);
    sRfuReqConfig = sRfuReqConfigTemplate;
    sRfuReqConfig.availSlot_flag = sAvailSlots[availSlots - 1];
    CreateTask_LinkLeaderSearchForChildren();
}

void InitializeRfuLinkManager_JoinGroup(void)
{
    Rfu.parent_child = MODE_CHILD;
    CopyPlayerNameToUnameBuffer();
    rfu_LMAN_initializeManager(LmanCallback_Child, MscCallback_Child);
    CreateTask_JoinGroupSearchForParent();
}

void InitializeRfuLinkManager_EnterUnionRoom(void)
{
    Rfu.parent_child = 2;
    CopyPlayerNameToUnameBuffer();
    rfu_LMAN_initializeManager(LmanCallback_Parent, NULL);
    sRfuReqConfig = sRfuReqConfigTemplate;
    sRfuReqConfig.linkRecovery_enable = 0;
    sRfuReqConfig.linkRecovery_period = 600;
    Rfu.unk_67 = CreateTask(Task_LinkRfu_UnionRoomListen, 1);
}

u16 ReadU16(const void *ptr)
{
    const u8 *ptr_ = ptr;
    return (ptr_[1] << 8) | (ptr_[0]);
}

/*
 * ================================================================
 * Looks up the player by uname and pid. Returns the index in
 * gRfuLinkStatus->partner of the first match with a valid slot ID.
 * Returns 0xFF if not found.
 * ================================================================
 */
u8 GetPartnerIndexByNameAndTrainerID(const u8 *trainerName, u16 trainerId)
{
    u8 i;
    u8 ret = 0xFF;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        u16 partnerTrainerId = ReadU16(((struct GFtgtGname *)gRfuLinkStatus->partner[i].gname)->unk_00.playerTrainerId);
        if (RfuSerialNumberIsValid(gRfuLinkStatus->partner[i].serialNo)
            && !StringCompare(trainerName, gRfuLinkStatus->partner[i].uname)
            && trainerId == partnerTrainerId)
        {
            ret = i;
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
                break;
        }
    }

    return ret;
}

void RfuReqDisconnectSlot(u32 bmDisconnectSlot)
{
    rfu_REQ_disconnect(bmDisconnectSlot);
    rfu_waitREQComplete();
    Rfu.bm_PartnerFlags &= ~(bmDisconnectSlot);
    rfu_clearSlot(TYPE_UNI_SEND, Rfu.unk_cda);
    rfu_UNI_setSendData(Rfu.bm_PartnerFlags, Rfu.recvCmds, 70);
    Rfu.unk_cda = sub_800E87C(Rfu.bm_PartnerFlags);
}

void RequestDisconnectSlotByTrainerNameAndId(const u8 *trainerName, u16 trainerId)
{
    u8 var = GetPartnerIndexByNameAndTrainerID(trainerName, trainerId);
    if (var != 0xFF)
        RfuReqDisconnectSlot(1 << var);
}

void sub_8011DE0(u32 a0)
{
    if (a0 != 0)
    {
        s32 i;
        u8 var = 0;

        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (Rfu.linkPlayerIdx[i] == a0 && (Rfu.bm_PartnerFlags >> i) & 1)
                var |= 1 << i;
        }
        if (var)
            sub_8011E94(var, 2);
    }
}

void sub_8011E2C(u8 taskId)
{
    if (gSendCmd[0] == 0 && !Rfu.unk_ce8)
    {
        RfuPrepareSendBuffer(RFU_COMMAND_0xed00);
        gSendCmd[1] = gTasks[taskId].data[0];
        gSendCmd[2] = gTasks[taskId].data[1];
        Rfu.playerCount -= gUnknown_082ED695[gTasks[taskId].data[0]];
        gSendCmd[3] = Rfu.playerCount;
        DestroyTask(taskId);
    }
}

void sub_8011E94(u32 a0, u32 a1)
{
    u8 taskId = FindTaskIdByFunc(sub_8011E2C);
    if (taskId == 0xFF)
    {
        taskId = CreateTask(sub_8011E2C, 5);
        gTasks[taskId].data[0] = a0;
    }
    else
    {
        gTasks[taskId].data[0] |= a0;
    }

    gTasks[taskId].data[1] = a1;
}

void Task_RfuReconnectWithParent(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (RfuStateIs7AndPlayerIsChild())
    {
        u8 id = GetPartnerIndexByNameAndTrainerID((u8*)data, ReadU16(&data[8]));
        if (id != 0xFF)
        {
            if (gRfuLinkStatus->partner[id].slot != 0xFF)
            {
                Rfu.reconnectedParentIdx = id;
                if (IsParentSuccessfullyReconnected())
                    DestroyTask(taskId);
            }
            else if (GetHostRFUtgtGname()->activity == ACTIVITY_WCARD2 || GetHostRFUtgtGname()->activity == ACTIVITY_WNEWS2)
            {
                data[15]++;
            }
            else
            {
                RfuSetErrorStatus(2, 0x7000);
                DestroyTask(taskId);
            }
        }
        else
        {
            data[15]++;
            Rfu.reconnectedParentIdx = id;
        }
    }
    else
    {
        data[15]++;
    }

    if (data[15] > 240)
    {
        RfuSetErrorStatus(2, 0x7000);
        DestroyTask(taskId);
    }
}

void CreateTask_RfuReconnectWithParent(const u8 *trainerName, u16 trainerId)
{
    u8 taskId;
    s16 *data;

    Rfu.unk_f1 = 0;
    taskId = CreateTask(Task_RfuReconnectWithParent, 3);
    data = gTasks[taskId].data;
    StringCopy((u8*)(data), trainerName);
    data[8] = trainerId;
}

bool32 ShouldRejectPartnerConnectionBasedOnActivity(s16 activity, struct GFtgtGname *partnerGname)
{
    if (GetHostRFUtgtGname()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        if (partnerGname->activity != (ACTIVITY_CHAT | IN_UNION_ROOM))
            return TRUE;
    }
    else if (partnerGname->activity != IN_UNION_ROOM)
    {
        return TRUE;
    }
    else if (activity == (ACTIVITY_TRADE | IN_UNION_ROOM))
    {
        struct GFtgtGname *myTradeGname = (struct GFtgtGname *)&Rfu.unk_104.gname;
        if (myTradeGname->species == SPECIES_EGG)
        {
            if (partnerGname->species == myTradeGname->species)
                return FALSE;
            else
                return TRUE;
        }
        else if (partnerGname->species != myTradeGname->species
                 || partnerGname->level != myTradeGname->level
                 || partnerGname->type != myTradeGname->type)
        {
            return TRUE;
        }
    }

    return FALSE;
}

void sub_801209C(u8 taskId)
{
    if (Rfu.unk_f1 == 4)
        DestroyTask(taskId);

    if (++gTasks[taskId].data[0] > 300)
    {
        RfuSetErrorStatus(2, 0x7000);
        DestroyTask(taskId);
    }

    if (Rfu.parentId != 0 && lman.parent_child == MODE_CHILD)
    {
        u16 trainerId = ReadU16(((struct GFtgtGname *)&Rfu.unk_104.gname)->unk_00.playerTrainerId);
        u8 id = GetPartnerIndexByNameAndTrainerID(Rfu.unk_104.uname, trainerId);
        if (id != 0xFF)
        {
            if (!ShouldRejectPartnerConnectionBasedOnActivity(gTasks[taskId].data[1], (struct GFtgtGname *)&gRfuLinkStatus->partner[id].gname))
            {
                if (gRfuLinkStatus->partner[id].slot != 0xFF && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[id].id, 90))
                {
                    Rfu.state = 10;
                    DestroyTask(taskId);
                }
            }
            else
            {
                RfuSetErrorStatus(2, 0x7000);
                DestroyTask(taskId);
            }
        }
    }
}

void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 activity)
{
    u8 taskId, taskId2;

    Rfu.unk_ccf = 0;
    Rfu.unk_f1 = 0;
    StringCopy(Rfu.unk_104.uname, name);
    memcpy(Rfu.unk_104.gname, structPtr, RFU_GAME_NAME_LENGTH);
    rfu_LMAN_forceChangeSP();
    taskId = CreateTask(sub_801209C, 2);
    gTasks[taskId].data[1] = activity;
    taskId2 = FindTaskIdByFunc(Task_LinkRfu_UnionRoomListen);
    if (activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
    {
        if (taskId2 != 0xFF)
            gTasks[taskId2].data[7] = 1;
    }
    else
    {
        if (taskId2 != 0xFF)
            gTasks[taskId2].data[7] = 0;
    }
}

bool8 sub_8012224(void)
{
    if (Rfu.linkLossRecoveryState == 1)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8012240(void)
{
    s32 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((lman.acceptSlot_flag >> i) & 1 && Rfu.unk_cd1[i] == 0)
            return FALSE;
    }

    return TRUE;
}

void rfu_dbg_clear(void)
{
    s32 i;

    for (i = 0; i < 20; i++)
        rfu_dbg_print_str("                              ", 0, i);
}

const char gUnknown_082ED84B[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',0x00};
const char gUnknown_082ED85B[9] = {' ',' ',' ',' ',' ',' ',' ',' ',0x00};
ALIGNED(4) const char gUnknown_082ED864[2] = {' ',0x00};
const char gUnknown_082ED866[2] = {'*',0x00};

void rfu_dbg_print_status(void)
{
    s32 i, j;

    rfu_dbg_print_num(GetBlockReceivedStatus(), 0x1C, 0x13, 2);
    rfu_dbg_print_num(gRfuLinkStatus->connSlotFlag, 0x14, 1, 1);
    rfu_dbg_print_num(gRfuLinkStatus->linkLossSlotFlag, 0x17, 1, 1);
	if (Rfu.parent_child == MODE_PARENT)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if ((gRfuLinkStatus->getNameFlag >> i) & 1)
            {
                rfu_dbg_print_num(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                rfu_dbg_print_str((void*) &gRfuLinkStatus->partner[i].gname, 6, i + 3);
                rfu_dbg_print_str(gRfuLinkStatus->partner[i].uname, 0x16, i + 3);
            }
        }
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            for (j = 0; j < 14; j++)
            {
                rfu_dbg_print_num(Rfu.unk_14[i][j], j * 2, i + 11, 2);
            }
        }
        rfu_dbg_print_str("NOWSLOT", 1, 0xF);
    }
    else if (gRfuLinkStatus->connSlotFlag != 0 && gRfuLinkStatus->getNameFlag != 0)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            rfu_dbg_print_num(0, 1, i + 3, 4);
            rfu_dbg_print_str(gUnknown_082ED84B, 6, i + 3);
            rfu_dbg_print_str(gUnknown_082ED85B, 0x16, i + 3);
        }
        rfu_dbg_print_num(gRfuLinkStatus->partner[Rfu.child_slot].serialNo, 1, 3, 4);
        rfu_dbg_print_str(gRfuLinkStatus->partner[Rfu.child_slot].gname, 6, 3);
        rfu_dbg_print_str(gRfuLinkStatus->partner[Rfu.child_slot].uname, 0x16, 3);
    }
    else
    {
        for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
        {
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
            {
                rfu_dbg_print_num(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                rfu_dbg_print_num(gRfuLinkStatus->partner[i].id, 6, i + 3, 4);
                rfu_dbg_print_str(gRfuLinkStatus->partner[i].uname, 0x16, i + 3);
            }
        }
        for (; i < RFU_CHILD_MAX; i++)
        {
            rfu_dbg_print_num(0, 1, i + 3, 4);
            rfu_dbg_print_str(gUnknown_082ED84B, 6, i + 3);
            rfu_dbg_print_str(gUnknown_082ED85B, 0x16, i + 3);
        }
    }
}

const char gUnknown_082ED870[][12] = {
    "           ",
    "CLOCK DRIFT",
    "BUSY SEND  ",
    "CMD REJECT ",
    "CLOCK SLAVE"
};

const char gUnknown_082ED8A8[][8] = {
    "CHILD ",
    "PARENT",
    "SEARCH"
};

u32 sub_80124C0(void)
{
    return Rfu.sendQueue.count;
}

u32 GetRfuRecvQueueLength(void)
{
    return Rfu.unk_124.count;
}

void Task_idle(u8 taskId)
{

}
