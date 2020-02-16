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
#include "save.h"
#include "mystery_gift.h"

extern u16 gHeldKeyCodeToSend;

u32 gf_rfu_REQ_api[RFU_API_BUFF_SIZE_RAM / 4];
struct UnkRfuStruct_2 Rfu;

BSS_DATA u8 gUnknown_03000D78[8];
BSS_DATA u8 gUnknown_03000D80[16];
BSS_DATA u16 gUnknown_03000D90[8];

EWRAM_DATA struct GFtgtGname gUnknown_02022B14 = {};
EWRAM_DATA ALIGNED(2) u8 gUnknown_02022B22[RFU_USER_NAME_LENGTH] = {};
EWRAM_DATA INIT_PARAM gUnknown_02022B2C = {};
EWRAM_DATA struct UnkLinkRfuStruct_02022B44 gUnknown_02022B44 = {};

// Static ROM declarations

// .rodata

const INIT_PARAM gUnknown_082ED608 = {
    0x04, 0x20, 0x00, 0x00, 0x02,
    (u8 *)&gUnknown_02022B14,
    gUnknown_02022B22,
    0x01, 0x00, 0x258, 0x12c
};
const u8 gUnknown_082ED620[] = {
    0, 3, 2, 1, 0
};
const u32 gUnknown_082ED628[] = {
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
const u16 gUnknown_082ED6E0[] = {
    0x0002, 0x7f7d, 0x0000, 0xFFFF
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
    sub_8010AAC,
    sub_8010D0C
};
const char gUnknown_082ED7EC[] = "PokemonSioInfo";
const char gUnknown_082ED7FC[] = "LINK LOSS DISCONNECT!";
const char gUnknown_082ED814[] = "LINK LOSS RECOVERY NOW";

ALIGNED(4) const char gUnknown_082ED82C[31] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',0x00};
const char gUnknown_082ED84B[16] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',0x00};
const char gUnknown_082ED85B[9] = {' ',' ',' ',' ',' ',' ',' ',' ',0x00};
ALIGNED(4) const char gUnknown_082ED864[2] = {' ',0x00};
const char gUnknown_082ED866[2] = {'*',0x00};
const char gUnknown_082ED868[8] = "NOWSLOT";
const char gUnknown_082ED870[12] = "           ";
const char gUnknown_082ED87C[12] = "CLOCK DRIFT";
const char gUnknown_082ED888[12] = "BUSY SEND  ";
const char gUnknown_082ED894[12] = "CMD REJECT ";
const char gUnknown_082ED8A0[12] = "CLOCK SLAVE";
const char gUnknown_082ED8A8[3][8] = {
    "CHILD ",
    "PARENT",
    "SEARCH"
};

// .text

void nullsub_5(const void *unused_0, u8 unused_1, u8 unused_2)
{
    // debug?
}

void nullsub_13(u16 unused_0, u8 unused_1, u8 unused_2, u8 unused_3)
{

}

void sub_800E604(void)
{
    s32 i;
    u8 unk_ee_bak = Rfu.unk_ee;
    CpuFill16(0, &Rfu, sizeof Rfu);
    Rfu.unk_ee = unk_ee_bak;
    Rfu.unk_0c = 0xFF;
    if (Rfu.unk_ee != 4)
    {
        Rfu.unk_ee = 0;
    }
    for (i = 0; i < 5; i++)
    {
        sub_800FCC4(Rfu.unk_80 + i);
    }
    sub_800FCC4(&Rfu.unk_6c);
    sub_800D6C8(&Rfu.unk_124);
    sub_800D724(&Rfu.unk_9e8);
    CpuFill16(0, gSendCmd, sizeof gSendCmd);
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
    CpuFill16(0, gLinkPlayers, sizeof gLinkPlayers);
}

void sub_800E6D0(void)
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
    if (!rfu_initializeAPI((void *)gf_rfu_REQ_api, sizeof gf_rfu_REQ_api, gIntrTable + 1, TRUE))
    {
        gLinkType = 0;
        sub_800AAF4();
        sub_80111B0(0);
        sub_800E604();
        rfu_setTimerInterrupt(3, gIntrTable + 2);
    }
}

void sub_800E748(u8 taskId)
{
    sub_8010750();
    switch (Rfu.unk_04)
    {
        case 0:
            rfu_LMAN_initializeRFU(&gUnknown_02022B2C);
            Rfu.unk_04 = 1;
            gTasks[taskId].data[1] = 1;
            break;
        case 1:
            break;
        case 2:
            rfu_LMAN_establishConnection(Rfu.unk_0c, 0, 240, (u16 *)gUnknown_082ED6E0);
            Rfu.unk_04 = 3;
            gTasks[taskId].data[1] = 6;
            break;
        case 3:
            break;
        case 4:
            rfu_LMAN_stopManager(FALSE);
            Rfu.unk_04 = 5;
            break;
        case 5:
            break;
        case 18:
            Rfu.unk_cdb = 0;
            rfu_LMAN_setMSCCallback(sub_800EDBC);
            sub_800EAB4();
            sub_800EAFC();
            Rfu.unk_04 = 20;
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
        for (i = 0; i < 4; r2 >>= 1, i++)
        {
            if (r2 & 1)
            {
                Rfu.unk_cde[i] = r4;
                r4++;
            }
        }
    }
    else
    {
        for (i = 0; i < 4; r1 >>= 1, i++)
        {
            if (!(r1 & 1))
            {
                Rfu.unk_cde[i] = 0;
            }
        }
        for (r4 = 4; r4 != 0; r4--)
        {
            for (i = 0; i < 4 && Rfu.unk_cde[i] != r4; i++);
            if (i == 4)
            {
                r6 = r4;
            }
        }
        for (r5 &= ~r2, i = 0; i < 4; r5 >>= 1, i++)
        {
            if (r5 & 1)
            {
                Rfu.unk_cde[i] = r6++;
            }
        }
    }
}

void sub_800E94C(u8 taskId)
{
    switch (Rfu.unk_04)
    {
        case 0:
            rfu_LMAN_initializeRFU((INIT_PARAM *)&gUnknown_082ED608);
            Rfu.unk_04 = 1;
            gTasks[taskId].data[1] = 1;
            break;
        case 1:
            break;
        case 6:
            rfu_LMAN_establishConnection(Rfu.unk_0c, 0, 0xf0, (u16 *)gUnknown_082ED6E0);
            Rfu.unk_04 = 7;
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
                    Rfu.unk_04 = 12;
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
            u8 r5 = 1 << Rfu.unk_c3e;
            rfu_clearSlot(12, Rfu.unk_c3e);
            rfu_setRecvBuffer(16, Rfu.unk_c3e, Rfu.unk_c3f, 70);
            rfu_UNI_setSendData(r5, Rfu.unk_4c, 14);
            gTasks[taskId].data[1] = 8;
            DestroyTask(taskId);
            if (gUnknown_02022B44.unk_0f == 0)
            {
                sub_801227C();
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
    u8 r5 = lman.acceptSlot_flag;
    for (i = 0; i < 4; i++)
    {
        if (r5 & 1)
        {
            rfu_setRecvBuffer(16, i, Rfu.unk_14[i], 14);
            rfu_clearSlot(3, i);
        }
        r5 >>= 1;
    }
}

void sub_800EAFC(void)
{
    u8 r5 = lman.acceptSlot_flag;
    rfu_UNI_setSendData(r5, Rfu.unk_c87, 70);
    Rfu.unk_cda = sub_800E87C(r5);
    Rfu.unk_ce2 = r5;
    sub_800E88C(r5, -1);
    Rfu.unk_0c = 1;
}

void sub_800EB44(u8 taskId)
{
    if (sub_800F7DC()->activity == 0x54 && sub_8011A74() == 4)
    {
        rfu_REQ_disconnect(lman.acceptSlot_flag);
        rfu_waitREQComplete();
        sub_8011A64(0, 0);
    }
    switch (Rfu.unk_04)
    {
        case 0:
            rfu_LMAN_initializeRFU(&gUnknown_02022B2C);
            Rfu.unk_04 = 1;
            gTasks[taskId].data[1] = 1;
            break;
        case 1:
            break;
        case 17:
            rfu_LMAN_establishConnection(2, 0, 240, (u16 *)gUnknown_082ED6E0);
            rfu_LMAN_setMSCCallback(sub_800ED34);
            Rfu.unk_04 = 18;
            break;
        case 18:
            break;
        case 13:
            if (rfu_UNI_setSendData(1 << Rfu.unk_c3e, Rfu.unk_4c, 14) == 0)
            {
                Rfu.unk_0c = 0;
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
            rfu_LMAN_stopManager(0);
            Rfu.unk_04 = 15;
            break;
        case 15:
            break;
        case 16:
            Rfu.unk_cdb = 0;
            rfu_LMAN_setMSCCallback(sub_800EDBC);
            sub_8011068(1);
            sub_800EAB4();
            sub_800EAFC();
            Rfu.unk_04 = 20;
            gTasks[taskId].data[1] = 8;
            Rfu.unk_0c = 1;
            CreateTask(sub_801084C, 5);
            Rfu.unk_ce8 = 1;
            DestroyTask(taskId);
            break;
    }
}

void sub_800ED10(void)
{
    rfu_LMAN_establishConnection(1, 0, 240, (u16 *)gUnknown_082ED6E0);
}

void sub_800ED28(void)
{
    rfu_LMAN_stopManager(FALSE);
}

void sub_800ED34(u16 unused)
{
    s32 i;

    for (i = 0; i < 14; i++)
    {
        Rfu.unk_4c[i] = 0;
    }
    rfu_REQ_recvData();
    rfu_waitREQComplete();
    if (gRfuSlotStatusUNI[Rfu.unk_c3e]->recv.newDataFlag)
    {
        Rfu.unk_cd0++;
        sub_800D7D8(&Rfu.unk_124, Rfu.unk_c3f);
        gUnknown_02022B44.unk_06++;
        sub_800F048();
        rfu_UNI_readySendData(Rfu.unk_c3e);
        rfu_UNI_clearRecvNewDataFlag(Rfu.unk_c3e);
    }
    rfu_LMAN_REQ_sendData(1);
}

void sub_800EDBC(u16 unused)
{
    Rfu.unk_cdb = 1;
}

void sub_800EDD4(void)
{
    u8 i;

    rfu_LMAN_powerDownRFU();
    if (Rfu.unk_0c == 1)
    {
        if (FuncIsActiveTask(sub_800E748) == TRUE)
        {
            DestroyTask(Rfu.unk_67);
            sub_800E604();
        }
    }
    else if (Rfu.unk_0c == 0)
    {
        if (FuncIsActiveTask(sub_800E94C) == TRUE)
        {
            DestroyTask(Rfu.unk_67);
            sub_800E604();
        }
    }
    else if (Rfu.unk_0c == 2)
    {
        if (FuncIsActiveTask(sub_800EB44) == TRUE)
        {
            DestroyTask(Rfu.unk_67);
            sub_800E604();
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (FuncIsActiveTask(gUnknown_082ED7E0[i]) == TRUE)
        {
            DestroyTask(FindTaskIdByFunc(gUnknown_082ED7E0[i]));
        }
    }
}

void sub_800EE78(void)
{
    Rfu.unk_67 = CreateTask(sub_800E748, 1);
}

bool8 sub_800EE94(void)
{
    if (Rfu.unk_04 == 7 && Rfu.unk_ccd)
    {
        return TRUE;
    }
    return FALSE;
}

bool32 sub_800EEBC(void)
{
    if (Rfu.unk_04 == 7 && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[Rfu.unk_c3d].id, 240))
    {
        Rfu.unk_04 = 9;
        return TRUE;
    }
    return FALSE;
}

void sub_800EF00(void)
{
    Rfu.unk_67 = CreateTask(sub_800E94C, 1);
}

bool8 sub_800EF1C(void)
{
    if (lman.acceptSlot_flag)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_800EF38(void)
{
    Rfu.unk_04 = 4;
    Rfu.unk_ce7 = lman.acceptSlot_flag;
}

bool32 sub_800EF58(bool32 a0)
{
    if (Rfu.unk_04 == 17 || a0)
    {
        Rfu.unk_04 = 18;
        return TRUE;
    }
    return FALSE;
}

void sub_800EF7C(void)
{
    Rfu.unk_04 = 14;
}

void sub_800EF88(u8 a0)
{
    u8 i;

    for (i = 0; i < 4; i++)
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
        struct UnkRfuStruct_2 *ptr = &Rfu;
        for (j = 0; j < 7; j++)
        {
            ptr->unk_c87[i][j][1] = gRecvCmds[i][j] >> 8;
            ptr->unk_c87[i][j][0] = gRecvCmds[i][j];
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
        u8 r2 = sub_800DAC8(&Rfu.unk_c1c, Rfu.unk_4c);
        if (Rfu.unk_c1c.unk_1e == 0)
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
        sub_800D9DC(&Rfu.unk_9e8, Rfu.unk_4c);
        sub_800DA68(&Rfu.unk_c1c, Rfu.unk_4c);
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
    if (Rfu.unk_04 < 20)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(0);
    }
    else
    {
        Rfu.unk_cdb = 0;
        if ((Rfu.unk_ce2 & gRfuLinkStatus->connSlotFlag) == Rfu.unk_ce2 && (Rfu.unk_ce2 & gRfuLinkStatus->connSlotFlag))
        {
            if (!Rfu.unk_cdc)
            {
                if (Rfu.unk_ce3)
                {
                    sub_8011D6C(Rfu.unk_ce3);
                    Rfu.unk_ce3 = 0;
                    if (Rfu.unk_ce4 == 1)
                    {
                        sub_8011A64(2, 0x8000);
                        sub_8011170(0x8000);
                        return FALSE;
                    }
                    if (!lman.acceptSlot_flag)
                    {
                        sub_800EDD4();
                        gReceivedRemoteLinkPlayers = 0;
                        return FALSE;
                    }
                }
                sub_800EFB0();
                rfu_UNI_readySendData(Rfu.unk_cda);
                rfu_LMAN_REQ_sendData(1);
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

    if (Rfu.unk_04 >= 20 && Rfu.unk_0e == 1)
    {
        rfu_waitREQComplete();
        while (Rfu.unk_cdb == 0)
        {
            if (Rfu.unk_ee != 0)
            {
                return FALSE;
            }
        }
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        if ((lman.parentAck_flag & Rfu.unk_ce2) == Rfu.unk_ce2)
        {
            Rfu.unk_cdc = 0;
            gUnknown_02022B44.unk_06++;
            flags = lman.acceptSlot_flag;
            for (i = 0; i < 4; i++)
            {
                if (flags & 1)
                {
                    if (Rfu.unk_14[i][1])
                    {
                        if (Rfu.unk_cee[i] != 0xFF && (Rfu.unk_14[i][0] >> 5) != ((Rfu.unk_cee[i] + 1) & 7))
                        {
                            if (++Rfu.unk_cea[i] > 4)
                                sub_8011170(0x8100);
                        }
                        else
                        {
                            Rfu.unk_cee[i] = Rfu.unk_14[i][0] / 32;
                            Rfu.unk_cea[i] = 0;
                            Rfu.unk_14[i][0] &= 0x1f;
                            r0 = Rfu.unk_cde[i];
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
            sub_800F86C(0);
            sub_8010528();
            if (Rfu.unk_ce5 && !Rfu.unk_cd9)
            {
                gUnknown_02022B44.unk_0e = 0;
                rfu_clearSlot(3, Rfu.unk_cda);
                for (i = 0; i < 4; i++)
                {
                    if ((Rfu.unk_ce5 >> i) & 1)
                    {
                        rfu_setRecvBuffer(0x10, i, Rfu.unk_14[i], 14);
                    }
                }
                sub_800E88C(Rfu.unk_ce2, Rfu.unk_ce2 | Rfu.unk_ce5);
                Rfu.unk_ce9 = Rfu.unk_ce5;
                Rfu.unk_ce2 |= Rfu.unk_ce5;
                Rfu.unk_ce5 = 0;
                rfu_UNI_setSendData(Rfu.unk_ce2, Rfu.unk_c87, 70);
                Rfu.unk_cda = sub_800E87C(Rfu.unk_ce2);
                CreateTask(sub_8010AAC, 0);
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

bool32 sub_800F4F0(void)
{
    u8 i;
    u8 j;
    u8 sp00[MAX_RFU_PLAYERS * (2 * (CMD_LENGTH - 1))];
    u8 sp48[2 * (CMD_LENGTH - 1)];
    u8 switchval;

    sub_800D934(&Rfu.unk_124, sp00);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH - 1; j++)
        {
            gRecvCmds[i][j] = (sp00[i * 14 + (j << 1) + 1] << 8) | sp00[i * 14 + (j << 1) + 0];
        }
    }
    sub_800F86C(0);
    if (lman.childClockSlave_flag == 0 && Rfu.unk_ce4)
    {
        rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
        rfu_waitREQComplete();
        switchval = sub_8011A74();
        if (switchval != 1 && switchval != 6 && switchval != 9)
            sub_8011A64(2, 0x9000);
        rfu_clearAllSlot();
        gReceivedRemoteLinkPlayers = FALSE;
        Rfu.linkRfuCallback = NULL;
        if (Rfu.unk_ce4 == 1)
        {
            sub_8011A64(2, 0x9000);
            sub_8011170(0x9000);
        }
        lman.state = lman.next_state = 0;
        Rfu.unk_ce4 = 0;
    }
    if (Rfu.unk_cd0)
    {
        Rfu.unk_cd0--;
        sub_8010528();
        sub_800F498(gSendCmd, sp48);
        sub_800D888(&Rfu.unk_9e8, sp48);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i] = 0;
    }
    return IsRfuRecvQueueEmpty();
}

void sub_800F638(u8 unused, u32 flags)
{
    s32 i, j;

    const u8 *r10 = Rfu.unk_6c.unk_04;
    for (i = 0; i < Rfu.unk_6c.unk_02; i++)
    {
        if (!(flags & 1))
        {
            gUnknown_03000D90[0] = (~0x76ff) | i;
            for (j = 0; j < 7; j++)
            {
                gUnknown_03000D90[j + 1] = (r10[12 * i + (j << 1) + 1] << 8) | r10[12 * i + (j << 1) + 0];
            }
            for (j = 0; j < 7; j++)
            {
                gUnknown_03000D80[2 * j + 1] = gUnknown_03000D90[j] >> 8;
                gUnknown_03000D80[2 * j + 0] = gUnknown_03000D90[j];

                j++;j--; // Needed to match;
            }
            sub_800D888(&Rfu.unk_9e8, gUnknown_03000D80);
            Rfu.unk_6c.unk_0c |= (1 << i);
        }
        flags >>= 1;
    }
}

void sub_800F6FC(u8 a0)
{
    if (Rfu.unk_0c == 1 && a0)
        Rfu.unk_61[a0] = 1;
    else
        Rfu.unk_5c[a0] = 1;
}

void sub_800F728(u8 a0)
{
    Rfu.unk_5c[a0] = 0;
    Rfu.unk_80[a0].unk_12 = 0;
}

u8 sub_800F74C(const u8 *a0)
{
    u8 i;

    if (Rfu.unk_0c == 1)
        return FALSE;
    for (i = 0; i < 4; i++)
    {
        Rfu.unk_cde[i] = a0[i];
    }
    return a0[Rfu.unk_c3e];
}

void rfu_func_080F97B8(void)
{
    if (gReceivedRemoteLinkPlayers
        && gHeldKeyCodeToSend != LINK_KEY_CODE_NULL
        && gLinkTransferringData != TRUE)
    {
        gUnknown_03000D78[0]++;
        gHeldKeyCodeToSend |= (gUnknown_03000D78[0] << 8);
        sub_800FD14(0xbe00);
    }
}

struct GFtgtGname *sub_800F7DC(void)
{
    return &gUnknown_02022B14;
}

bool32 IsSendingKeysToRfu(void)
{
    return Rfu.linkRfuCallback == rfu_func_080F97B8;
}

void sub_800F804(void)
{
    Rfu.linkRfuCallback = rfu_func_080F97B8;
}

void ClearLinkRfuCallback(void)
{
    Rfu.linkRfuCallback = NULL;
}

void sub_800F820(void)
{
    sub_800FD14(0x4400);
    if (GetMultiplayerId() == 0)
        gSendCmd[6] = GetBlenderArrowPosition();
    gUnknown_020223C0++;
}

void sub_800F850(void)
{
    if (Rfu.linkRfuCallback == NULL)
        Rfu.linkRfuCallback = sub_800F820;
}

void sub_800F86C(u8 unused)
{
    u16 i;
    u16 j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        switch (gRecvCmds[i][0] & 0xff00)
        {
        case 0x7800:
            if (Rfu.unk_0c == 0 && gReceivedRemoteLinkPlayers != 0)
                return;
            // fallthrough
        case 0x7700:
            if (gRfuLinkStatus->parentChild == 0)
            {
                Rfu.playerCount = gRecvCmds[i][1];
                Rfu.unk_cce = sub_800F74C((u8 *)(gRecvCmds[i] + 2));
            }
            break;
        case 0x8800:
            if (Rfu.unk_80[i].unk_12 == 0)
            {
                Rfu.unk_80[i].unk_00 = 0;
                Rfu.unk_80[i].unk_02 = gRecvCmds[i][1];
                Rfu.unk_80[i].unk_11 = gRecvCmds[i][2];
                Rfu.unk_80[i].unk_08 = 0;
                Rfu.unk_80[i].unk_12 = 1;
                Rfu.unk_5c[i] = 0;
            }
            break;
        case 0x8900:
            if (Rfu.unk_80[i].unk_12 == 1)
            {
                Rfu.unk_80[i].unk_00 = gRecvCmds[i][0] & 0xff;
                Rfu.unk_80[i].unk_08 |= (1 << Rfu.unk_80[i].unk_00);
                for (j = 0; j < 6; j++)
                    gBlockRecvBuffer[i][Rfu.unk_80[i].unk_00 * 6 + j] = gRecvCmds[i][j + 1];
                if (Rfu.unk_80[i].unk_08 == gUnknown_082ED628[Rfu.unk_80[i].unk_02])
                {
                    Rfu.unk_80[i].unk_12 = 2;
                    sub_800F6FC(i);
                    if (sub_800F7DC()->activity == 0x45 && gReceivedRemoteLinkPlayers != 0 && Rfu.unk_0c == 0)
                        sub_8010A70(gBlockRecvBuffer);
                }
            }
            break;
        case 0xa100:
            sub_800FE84(gUnknown_082ED6B8[gRecvCmds[i][1]].buffer, (u16)gUnknown_082ED6B8[gRecvCmds[i][1]].size);
            break;
        case 0x5f00:
            Rfu.unk_e4[i] = 1;
            break;
        case 0x6600:
            if (Rfu.unk_100 == gRecvCmds[i][1])
                Rfu.unk_e9[i] = 1;
            break;
        case 0xed00:
            if (Rfu.unk_0c == 0)
            {
                if (gReceivedRemoteLinkPlayers != 0)
                {
                    if (gRecvCmds[i][1] & gRfuLinkStatus->connSlotFlag)
                    {
                        gReceivedRemoteLinkPlayers = 0;
                        rfu_LMAN_requestChangeAgbClockMaster();
                        Rfu.unk_ce4 = gRecvCmds[i][2];
                    }
                    Rfu.playerCount = gRecvCmds[i][3];
                    sub_80109E8(gRecvCmds[i][1]);
                }
            }
            else
            {
                sub_800FD14(0xee00);
                gSendCmd[1] = gRecvCmds[i][1];
                gSendCmd[2] = gRecvCmds[i][2];
                gSendCmd[3] = gRecvCmds[i][3];
            }
            break;
        case 0xee00:
            if (Rfu.unk_0c == 1)
            {
                Rfu.unk_ce3 |= gRecvCmds[i][1];
                Rfu.unk_ce4 = gRecvCmds[i][2];
                sub_80109E8(gRecvCmds[i][1]);
            }
            break;
        case 0x4400:
        case 0xbe00:
            gLinkPartnersHeldKeys[i] = gRecvCmds[i][1];
            break;
        }
        if (Rfu.unk_0c == 1 && Rfu.unk_61[i])
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

bool8 sub_800FC60(void)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        if (Rfu.unk_80[i].unk_12)
            return FALSE;
    }
    return TRUE;
}

bool8 sub_800FC88(void)
{
    s32 i;

    for (i = 0; i < Rfu.playerCount; i++)
    {
        if (Rfu.unk_80[i].unk_12 != 2 || Rfu.unk_5c[i] != 1)
            return FALSE;
    }
    return TRUE;
}

void sub_800FCC4(struct UnkRfuStruct_2_Sub_6c *data)
{
    data->unk_00 = 0;
    data->unk_02 = 0;
    data->unk_04 = NULL;
    data->unk_08 = 0;
    data->unk_10 = 0;
    data->unk_11 = 0;
    data->unk_12 = 0;
}

u8 sub_800FCD8(void)
{
    u8 flags = 0;
    s32 i;

    for (i = 0; i < 5; i++)
    {
        if (Rfu.unk_80[i].unk_12 == 2 && Rfu.unk_5c[i] == 1)
        {
            flags |= (1 << i);
        }
    }
    return flags;
}

void sub_800FD14(u16 command)
{
    u8 i;
    u8 *buff;
    u8 tmp;

    gSendCmd[0] = command;
    switch (command)
    {
    case 0x8800:
        gSendCmd[1] = Rfu.unk_6c.unk_02;
        gSendCmd[2] = Rfu.unk_6c.unk_11 + 0x80;
        break;
    case 0xa100:
        if (sub_800FC60())
            gSendCmd[1] = Rfu.unk_5a;
        break;
    case 0x7700:
    case 0x7800:
        tmp = Rfu.unk_ce2 ^ Rfu.unk_ce3;
        Rfu.playerCount = gUnknown_082ED695[tmp] + 1;
        gSendCmd[1] = Rfu.playerCount;
        buff = (u8 *)(gSendCmd + 2);
        for (i = 0; i < 4; i++)
            buff[i] = Rfu.unk_cde[i];
        break;
    case 0x6600:
    case 0x5f00:
        gSendCmd[1] = Rfu.unk_100;
        break;
    case 0x4400:
        gSendCmd[0] = command;
        gSendCmd[1] = gMain.heldKeys;
        break;
    case 0x2f00:
        for (i = 0; i < 6; i++)
            gSendCmd[1 + i] = Rfu.unk_f2[i];
        break;
    case 0xbe00:
        gSendCmd[1] = gHeldKeyCodeToSend;
        break;
    case 0xee00:
        break;
    case 0xed00:
        break;
    }
}

void sub_800FE50(void *a0)
{
    if (gSendCmd[0] == 0 && !sub_8011A80())
    {
        memcpy(Rfu.unk_f2, a0, sizeof(Rfu.unk_f2));
        sub_800FD14(0x2f00);
    }
}

bool32 sub_800FE84(const u8 *src, size_t size)
{
    bool8 r4;
    if (Rfu.linkRfuCallback != NULL)
        return FALSE;
    if (gSendCmd[0] != 0)
        return FALSE;
    if (Rfu.unk_6c.unk_10 != 0)
    {
        gUnknown_02022B44.unk_83++;
        return FALSE;
    }
    r4 = (size % 12) != 0;
    Rfu.unk_6c.unk_11 = GetMultiplayerId();
    Rfu.unk_6c.unk_10 = 1;
    Rfu.unk_6c.unk_02 = (size / 12) + r4;
    Rfu.unk_6c.unk_00 = 0;
    if (size > 0x100)
        Rfu.unk_6c.unk_04 = src;
    else
    {
        if (src != gBlockSendBuffer)
            memcpy(gBlockSendBuffer, src, size);
        Rfu.unk_6c.unk_04 = gBlockSendBuffer;
    }
    sub_800FD14(0x8800);
    Rfu.linkRfuCallback = rfufunc_80F9F44;
    Rfu.unk_5b = 0;
    return TRUE;
}

void rfufunc_80F9F44(void)
{
    if (gSendCmd[0] == 0)
    {
        sub_800FD14(0x8800);
        if (Rfu.unk_0c == 1)
        {
            if (++Rfu.unk_5b > 2)
                Rfu.linkRfuCallback = sub_800FFB0;
        }
        else
        {
            if ((gRecvCmds[GetMultiplayerId()][0] & 0xff00) == 0x8800)
                Rfu.linkRfuCallback = sub_800FFB0;
        }
    }
}

void sub_800FFB0(void)
{
    s32 i;
    const u8 *src = Rfu.unk_6c.unk_04;
    gSendCmd[0] = 0x8900 | Rfu.unk_6c.unk_00;
    for (i = 0; i < 7; i++)
        gSendCmd[i + 1] = (src[(i << 1) + Rfu.unk_6c.unk_00 * 12 + 1] << 8) | src[(i << 1) + Rfu.unk_6c.unk_00 * 12 + 0];
    Rfu.unk_6c.unk_00++;
    if (Rfu.unk_6c.unk_02 <= Rfu.unk_6c.unk_00)
    {
        Rfu.unk_6c.unk_10 = 0;
        Rfu.linkRfuCallback = rfufunc_80FA020;
    }
}

void rfufunc_80FA020(void)
{
    const u8 *src = Rfu.unk_6c.unk_04;
    u8 mpId = GetMultiplayerId();
    s32 i;
    if (Rfu.unk_0c == 0)
    {
        gSendCmd[0] = (~0x76ff) | (Rfu.unk_6c.unk_02 - 1);
        for (i = 0; i < 7; i++)
            gSendCmd[i + 1] = (src[(i << 1) + (Rfu.unk_6c.unk_02 - 1) * 12 + 1] << 8) | src[(i << 1) + (Rfu.unk_6c.unk_02 - 1) * 12 + 0];
        if ((u8)gRecvCmds[mpId][0] == Rfu.unk_6c.unk_02 - 1)
        {
            if (Rfu.unk_80[mpId].unk_08 != gUnknown_082ED628[Rfu.unk_80[mpId].unk_02])
            {
                sub_800F638(mpId, Rfu.unk_80[mpId].unk_08);
                gUnknown_02022B44.unk_64++;
            }
            else
                Rfu.linkRfuCallback = NULL;
        }
    }
    else
        Rfu.linkRfuCallback = NULL;
}

bool8 sub_8010100(u8 a0)
{
    Rfu.unk_5a = a0;
    sub_800FD14(0xa100);
    return TRUE;
}

void sub_801011C(void)
{
    rfu_clearAllSlot();
    rfu_LMAN_powerDownRFU();
    gReceivedRemoteLinkPlayers = 0;
    Rfu.unk_ef = 1;
    Rfu.linkRfuCallback = NULL;
}

void sub_8010148(void)
{
    rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
    rfu_waitREQComplete();
    sub_801011C();
}

void sub_8010168(void)
{
    if (Rfu.unk_0c == 0)
    {
        rfu_LMAN_requestChangeAgbClockMaster();
        Rfu.unk_ce4 = 2;
    }
    else
        Rfu.linkRfuCallback = sub_8010148;
}

void LinkRfu_FatalError(void)
{
    rfu_LMAN_requestChangeAgbClockMaster();
    Rfu.unk_ce4 = 1;
    Rfu.unk_ce3 = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
}

void sub_80101CC(void)
{
    s32 i;
    u8 playerCount = Rfu.playerCount;
    s32 count = 0;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (Rfu.unk_e4[i])
            count++;
    }
    if (count == playerCount)
    {
        gBattleTypeFlags &= ~BATTLE_TYPE_20;
        if (Rfu.unk_0c == 0)
        {
            Rfu.unk_ee = 3;
            sub_8010168();
        }
        else
            Rfu.linkRfuCallback = sub_8010168;
    }
}

void sub_801022C(void)
{
    if (gSendCmd[0] == 0 && Rfu.unk_ce8 == 0)
    {
        sub_800FD14(0x5f00);
        Rfu.linkRfuCallback = sub_80101CC;
    }
}

void sub_8010264(u8 taskId)
{
    if (Rfu.linkRfuCallback == NULL)
    {
        Rfu.unk_cd9 = 1;
        Rfu.linkRfuCallback = sub_801022C;
        DestroyTask(taskId);
    }
}

void task_add_05_task_del_08FA224_when_no_RfuFunc(void)
{
    if (!FuncIsActiveTask(sub_8010264))
        CreateTask(sub_8010264, 5);
}

void sub_80102B8(void)
{
    u8 playerCount;
    u8 i;

    if (GetMultiplayerId() != 0)
    {
        u8 r4 = Rfu.unk_124.unk_8c2;
        if (r4 == 0 && Rfu.unk_fe > 0x3c)
        {
            sub_800FD14(0x6600);
            Rfu.unk_fe = r4;
        }
    }
    playerCount = GetLinkPlayerCount();
    for (i = 0; i < playerCount; i++)
    {
        if (Rfu.unk_e9[i] == 0)
            break;
    }
    if (i == playerCount)
    {
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            Rfu.unk_e9[i] = 0;
        Rfu.unk_100++;
        Rfu.linkRfuCallback = NULL;
    }
    Rfu.unk_fe++;
}

void sub_8010358(void)
{
    if (Rfu.unk_124.unk_8c2 == 0 && gSendCmd[0] == 0)
    {
        sub_800FD14(0x6600);
        Rfu.linkRfuCallback = sub_80102B8;
    }
}

void sub_8010390(void)
{
    u8 i;
    u8 playerCount;

    if (GetMultiplayerId() != 0)
    {
        if (Rfu.unk_124.unk_8c2 == 0 && gSendCmd[0] == 0)
        {
            sub_800FD14(0x6600);
            Rfu.linkRfuCallback = sub_80102B8;
        }
    }
    else
    {
        playerCount = GetLinkPlayerCount();
        for (i = 1; i < playerCount; i++)
        {
            if (Rfu.unk_e9[i] == 0)
                break;
        }
        if (i == playerCount)
        {
            if (Rfu.unk_124.unk_8c2 == 0 && gSendCmd[0] == 0)
            {
                sub_800FD14(0x6600);
                Rfu.linkRfuCallback = sub_8010358;
            }
        }
    }
}

void sub_8010434(void)
{
    if (Rfu.linkRfuCallback == NULL)
    {
        Rfu.linkRfuCallback = sub_8010390;
        Rfu.unk_fe = 0;
    }
}

bool32 sub_8010454(u32 a0)
{
    s32 i;
    for (i = 0; gUnknown_082ED6E0[i] != a0; i++)
    {
        if (gUnknown_082ED6E0[i] == 0xFFFF)
            return FALSE;
    }
    return TRUE;
}

u8 sub_801048C(bool32 a0)
{
    if (a0 == FALSE)
        return rfu_LMAN_setLinkRecovery(0, 0);
    rfu_LMAN_setLinkRecovery(1, 0x258);
    return 0;
}

void sub_80104B0(void)
{
    Rfu.unk_cd9 = 1;
    rfu_LMAN_stopManager(FALSE);
}

u8 rfu_get_multiplayer_id(void)
{
    if (Rfu.unk_0c == 1)
        return 0;
    return Rfu.unk_cce;
}

u8 sub_80104F4(void)
{
    return Rfu.playerCount;
}

bool8 IsLinkRfuTaskFinished(void)
{
    if (Rfu.unk_f1 == 2)
        return FALSE;
    return Rfu.linkRfuCallback ? FALSE : TRUE;
}

void sub_8010528(void)
{
    if (Rfu.linkRfuCallback)
        Rfu.linkRfuCallback();
}

bool8 sub_8010540(void)
{
    s32 i;
    bool8 retval = FALSE;
    for (i = 0; i < 4; i++)
    {
        if (Rfu.unk_cd1[i] < 5 || Rfu.unk_cd1[i] > 6)
        {
            if (gRfuSlotStatusNI[i]->recv.state == 0x46 || gRfuSlotStatusNI[i]->recv.state == 0x48)
            {
                if (Rfu.unk_cd5[i] == 8)
                {
                    Rfu.unk_cd1[i] = 9;
                    Rfu.unk_cd5[i] = 10;
                    rfu_clearSlot(8, i);
                    rfu_NI_setSendData(1 << i, 8, Rfu.unk_cd1 + i, 1);
                    retval = TRUE;
                }

            }
            else if (gRfuSlotStatusNI[Rfu.unk_c3e]->recv.state == 0x47)
                rfu_clearSlot(8, i);
            {

            }
        }
    }
    return retval;
}

bool32 sub_80105EC(void)
{
    u8 flags = 0;
    s32 i;
    for (i = 0; i < 4; i++)
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
    for (i = 0; i < 4; i++)
    {
        if (Rfu.unk_cd5[i] == 10 || Rfu.unk_cd5[i] == 11)
            return TRUE;
    }
    return FALSE;
}

bool32 sub_801064C(u16 a0, const u8 *a1)
{
    u8 r1 = sub_8011CE4(a1, a0);
    if (r1 == 0xFF)
        return TRUE;
    if (Rfu.unk_cd1[r1] == 9)
        return TRUE;
    return FALSE;
}

void sub_8010688(u8 a0, u16 a1, const u8 *a2)
{
    u8 r4 = sub_8011CE4(a2, a1);
    Rfu.unk_cd1[r4] = a0;
    rfu_clearSlot(4, r4);
    rfu_NI_setSendData(1 << r4, 8, Rfu.unk_cd1 + r4, 1);
}

void sub_80106D4(void)
{
    Rfu.unk_c85 = 8;
    rfu_clearSlot(4, Rfu.unk_c3e);
    rfu_NI_setSendData(1 << Rfu.unk_c3e, 8, &Rfu.unk_c85, 1);
}

u32 sub_8010714(u16 a0, const u8 *a1)
{
    u8 r0 = sub_8011CE4(a1, a0);
    if (r0 == 0xFF)
        return 2;
    if (gRfuSlotStatusNI[r0]->send.state == 0)
        return 1;
    return 0;
}

void sub_8010750(void)
{
    s32 i;

    sub_8010540();
    for (i = 0; i < 4; i++)
    {
        if (gRfuSlotStatusNI[i]->send.state == 0x26 || gRfuSlotStatusNI[i]->send.state == 0x27)
        {
            if (Rfu.unk_cd5[i] == 10)
                Rfu.unk_cd5[i] = 11;
            rfu_clearSlot(4, i);
        }
    }
}

s32 sub_80107A0(void)
{
    s32 retval = 0;
    if (Rfu.unk_c85 == 8)
    {
        if (gRfuSlotStatusNI[Rfu.unk_c3e]->send.state == 0x26 || gRfuSlotStatusNI[Rfu.unk_c3e]->send.state == 0x27)
            rfu_clearSlot(4, Rfu.unk_c3e);
    }
    if (gRfuSlotStatusNI[Rfu.unk_c3e]->recv.state == 0x46 || gRfuSlotStatusNI[Rfu.unk_c3e]->recv.state == 0x48)
    {
        rfu_clearSlot(8, Rfu.unk_c3e);
        sub_8011A64(Rfu.unk_c86, 0);
        retval = Rfu.unk_c86;
    }
    else if (gRfuSlotStatusNI[Rfu.unk_c3e]->recv.state == 0x47)
    {
        rfu_clearSlot(8, Rfu.unk_c3e);
        retval = 6;
    }
    return retval;
}

void sub_801084C(u8 taskId)
{
    s32 i;

    if (Rfu.unk_f1 == 1 || Rfu.unk_f1 == 2)
    {
        Rfu.unk_ce8 = 0;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (sub_800FC60())
            {
                ResetBlockReceivedFlags();
                sub_800B348();
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (Rfu.unk_0c == 1)
            {
                if (gReceivedRemoteLinkPlayers)
                    sub_800FD14(0x7800);
                else
                    sub_800FD14(0x7700);
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
            if (Rfu.unk_0c == 1)
            {
                if (sub_800FC60())
                {
                    Rfu.unk_5a = 0;
                    sub_800FD14(0xa100);
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
                sub_800B3A4(i);
                sub_800F728(i);
            }
            gTasks[taskId].data[0]++;
            break;
        case 6:
            DestroyTask(taskId);
            gReceivedRemoteLinkPlayers = 1;
            Rfu.unk_ce8 = 0;
            rfu_LMAN_setLinkRecovery(1, 0x258);
            if (Rfu.unk_ce6)
            {
                for (i = 0; i < 4; i++)
                {
                    if ((Rfu.unk_ce6 >> i) & 1)
                    {
                        Rfu.unk_ce5 = 1 << i;
                        Rfu.unk_ce6 ^= (1 << i);
                    }
                }
            }
            break;
    }
}

void sub_80109E8(u16 a0)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if ((a0 >> i) & 1)
            Rfu.unk_cde[i] = 0;
    }
}

void sub_8010A14(const struct UnkRfuStruct_8010A14 *a0)
{
    s32 i;
    Rfu.playerCount = a0->unk_0f;
    for (i = 0; i < 4; i++)
        Rfu.unk_cde[i] = a0->unk_10[i];
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        gLinkPlayers[i] = a0->unk_14[i];
        sub_800B524(gLinkPlayers + i);
    }
}

void sub_8010A70(void *a0)
{
    if (strcmp(gUnknown_082ED7EC, a0) == 0)
    {
        sub_8010A14(a0);
        CpuFill16(0, a0, sizeof(struct UnkRfuStruct_8010A14));
        ResetBlockReceivedFlag(0);
    }
}

void sub_8010AAC(u8 taskId)
{
    s32 i;
    struct LinkPlayerBlock *r2;
    struct UnkRfuStruct_8010A14 *r5;
    u8 r4 = Rfu.unk_cde[gUnknown_082ED68C[Rfu.unk_ce9]];
    if (Rfu.unk_f1 == 1 || Rfu.unk_f1 == 2)
    {
        Rfu.unk_ce8 = 0;
        DestroyTask(taskId);
    }
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (gSendCmd[0] == 0)
            {
                ResetBlockReceivedFlag(r4);
                sub_800FD14(0x7800);
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
                sub_800B524(gLinkPlayers + r4);
                gTasks[taskId].data[0]++;
            }
            break;
        case 3:
            r5 = (struct UnkRfuStruct_8010A14 *)gBlockSendBuffer;
            memcpy(r5->unk_00, gUnknown_082ED7EC, sizeof gUnknown_082ED7EC);
            r5->unk_0f = Rfu.playerCount;
            for (i = 0; i < 4; i++)
                r5->unk_10[i] = Rfu.unk_cde[i];
            memcpy(r5->unk_14, gLinkPlayers, sizeof gLinkPlayers);
            gTasks[taskId].data[0]++;
            // fallthrough
        case 4:
            r5 = (struct UnkRfuStruct_8010A14 *)gBlockSendBuffer;
            r5->unk_0f = Rfu.playerCount;
            for (i = 0; i < 4; i++)
                r5->unk_10[i] = Rfu.unk_cde[i];
            memcpy(r5->unk_14, gLinkPlayers, sizeof gLinkPlayers);
            if (SendBlock(0, gBlockSendBuffer, 0xa0))
                gTasks[taskId].data[0]++;
            break;
        case 5:
            if (IsLinkTaskFinished() && GetBlockReceivedStatus() & 1)
            {
                CpuFill16(0, gBlockRecvBuffer, sizeof(struct UnkRfuStruct_8010A14));
                ResetBlockReceivedFlag(0);
                Rfu.unk_ce8 = 0;
                if (Rfu.unk_ce6)
                {
                    for (i = 0; i < 4; i++)
                    {
                        if ((Rfu.unk_ce6 >> i) & 1)
                        {
                            Rfu.unk_ce5 = 1 << i;
                            Rfu.unk_ce6 ^= (1 << i);
                            Rfu.unk_ce8 = 1;
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
                sub_800B348();
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
                sub_8010A14((const struct UnkRfuStruct_8010A14 *)gBlockRecvBuffer);
                ResetBlockReceivedFlag(0);
                gReceivedRemoteLinkPlayers = 1;
                DestroyTask(taskId);
            }
            break;
    }
}

void sub_8010DB4(void)
{
    if (Rfu.unk_ee == 1 && lman.childClockSlave_flag == 0)
    {
        if (gMain.callback2 == c2_mystery_gift_e_reader_run || lman.init_param->mboot_flag)
            gWirelessCommType = 2;
        SetMainCallback2(CB2_LinkError);
        gMain.savedCallback = CB2_LinkError;
        sub_800AF18((Rfu.unk_0a << 16) | (Rfu.unk_10 << 8) | Rfu.unk_12, Rfu.unk_124.unk_8c2, Rfu.unk_9e8.unk_232, sub_8011A74() == 2);
        Rfu.unk_ee = 2;
        CloseLink();
    }
    else if (Rfu.unk_9e8.unk_233 == 1 || Rfu.unk_124.unk_8c3 == 1)
    {
        if (lman.childClockSlave_flag)
            rfu_LMAN_requestChangeAgbClockMaster();
        sub_8011A64(1, 0x7000);
        sub_8011170(0x7000);
    }
}

void rfu_REQ_recvData_then_sendData(void)
{
    if (lman.parent_child == 1)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(0);
    }
}

bool32 sub_8010EC0(void)
{
    bool32 retval = FALSE;
    Rfu.unk_ccd = 0;
    rfu_LMAN_manager_entity(Random2());
    if (Rfu.unk_ef == 0)
    {
        switch (Rfu.unk_0c)
        {
            case 1:
                sub_800F0F8();
                break;
            case 0:
                retval = sub_800F4F0();
                break;
            case 2:
                rfu_REQ_recvData_then_sendData();
                break;
        }
    }
    return retval;
}

bool32 sub_8010F1C(void)
{
    bool32 retval = FALSE;
    if (Rfu.unk_ef == 0)
    {
        if (Rfu.unk_0c == 1)
            retval = sub_800F1E0();
        sub_8010DB4();
    }
    return retval;
}

void sub_8010F48(void)
{
    StringCopy(gUnknown_02022B22, gSaveBlock2Ptr->playerName);
}

void sub_8010F60(void)
{
    memset(&gUnknown_02022B14, 0, 0xD);
    sub_800DD94(&gUnknown_02022B14, 0, 0, 0);
}

void sub_8010F84(u8 a0, u32 a1, u32 a2)
{
    sub_800DD94(&gUnknown_02022B14, a0, a2, a1);
}

void sub_8010FA0(bool32 a0, bool32 a1)
{
    gUnknown_02022B14.unk_00.hasNews = a0;
    gUnknown_02022B14.unk_00.hasCard = a1;
}

void sub_8010FCC(u32 type, u32 species, u32 level)
{
    gUnknown_02022B14.type = type;
    gUnknown_02022B14.species = species;
    gUnknown_02022B14.level = level;
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
    struct GFtgtGname *r5 = &gUnknown_02022B14;
    s32 i;

    for (i = 1; i < GetLinkPlayerCount(); i++)
        r5->child_sprite_gender[i - 1] = sub_801100C(i);
}

void sub_8011068(u8 a0)
{
    gUnknown_02022B14.started = a0;
    rfu_REQ_configGameData(0, 2, (const u8 *)&gUnknown_02022B14, gUnknown_02022B22);
}

void sub_8011090(u8 a0, u32 a1, u32 a2)
{
    if (a0)
        sub_8010F84(a0, a1, a2);
    rfu_REQ_configGameData(0, 2, (const u8 *)&gUnknown_02022B14, gUnknown_02022B22);
}

void sub_80110B8(u32 a0)
{
    s32 i;
    u32 r5;
    u32 r7;
    s32 r8;

    if (sub_800F7DC()->activity == 0x45)
    {
        r5 = 0;
        r7 = 0;
        r8 = Rfu.unk_ce2 ^ Rfu.unk_ce3;
        for (i = 0; i < 4; i++)
        {
            if ((r8 >> i) & 1)
            {
                r7 |= ((0x80 | ((gLinkPlayers[Rfu.unk_cde[i]].gender & 1) << 3) | (gLinkPlayers[Rfu.unk_cde[i]].trainerId & 7)) << (r5 << 3));
                r5++;
                if (r5 == a0 - 1)
                    break;
            }
        }
        sub_8011090(0x45, r7, 0);
    }
}

void sub_8011170(u32 a0)
{
    if (Rfu.unk_ee == 0)
    {
        Rfu.unk_10 = lman.param[0];
        Rfu.unk_12 = lman.param[1];
        Rfu.unk_0a = a0;
        Rfu.unk_ee = 1;
    }
}

void sub_80111A0(void)
{
    Rfu.unk_ee = 0;
}

void sub_80111B0(bool32 a0)
{
    if (!a0)
        Rfu.unk_ee = 0;
    else
        Rfu.unk_ee = 4;
}

void sub_80111DC(void)
{
    sub_8011E94(lman.acceptSlot_flag, 1);
    Rfu.linkRfuCallback = NULL;
}

void sub_80111FC(void)
{
    Rfu.linkRfuCallback = sub_80111DC;
}

void sub_801120C(u8 a0, u8 unused1)
{
    u8 i;
    u8 r6 = 0;
    switch (a0)
    {
    case 0x00:
        Rfu.unk_04 = 2;
        break;
    case 0x10:
        break;
    case 0x11:
        sub_80115EC(lman.param[0]);
        for (i = 0; i < 4; i++)
        {
            if ((lman.param[0] >> i) & 1)
            {
                struct GFtgtGname *structPtr = (void *)gRfuLinkStatus->partner[i].gname;
                if (structPtr->activity == sub_800F7DC()->activity)
                {
                    Rfu.unk_cd1[i] = 0;
                    Rfu.unk_cd5[i] = 0;
                    rfu_setRecvBuffer(0x20, i, Rfu.unk_cd5 + i, 1);
                }
                else
                {
                    r6 |= (1 << i);
                }
            }
        }
        if (r6)
        {
            rfu_REQ_disconnect(r6);
            rfu_waitREQComplete();
        }
        break;
    case 0x12:
        break;
    case 0x13:
        break;
    case 0x14:
        if (Rfu.unk_ce7 != lman.acceptSlot_flag)
        {
            rfu_REQ_disconnect(Rfu.unk_ce7 ^ lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        Rfu.unk_04 = 0x11;
        break;
    case 0x31:
        Rfu.unk_f0 = 1;
        break;
    case 0x32:
        Rfu.unk_f0 = 3;
        break;
    case 0x30:
    case 0x33:
        Rfu.unk_f0 = 4;
        Rfu.unk_ce2 &= ~lman.param[0];
        if (gReceivedRemoteLinkPlayers == 1)
        {
            if (Rfu.unk_ce2 == 0)
                sub_8011170(a0);
            else
                sub_80111FC();
        }
        sub_8011A64(2, a0);
        break;
    case 0x34:
        break;
    case 0x42 ... 0x44:
        break;
    case 0xf3:
        sub_8011A64(1, a0);
        sub_8011170(a0);
        Rfu.unk_ef = 1;
        break;
    case 0xf0 ... 0xf2:
    case 0xff:
        sub_8011170(a0);
        sub_8011A64(1, a0);
        Rfu.unk_cdb = 1;
        break;
    }
}

void sub_8011404(u8 a0, u8 unused1)
{
    switch (a0)
    {
    case 0x00:
        Rfu.unk_04 = 6;
        break;
    case 0x20:
        Rfu.unk_ccd = lman.param[0];
        break;
    case 0x21:
        break;
    case 0x22:
        Rfu.unk_c3e = lman.param[0];
        break;
    case 0x23:
        sub_8011A64(2, a0);
        break;
    case 0x24:
        Rfu.unk_04 = 11;
        Rfu.unk_c85 = 0;
        Rfu.unk_c86 = 0;
        rfu_setRecvBuffer(0x20, Rfu.unk_c3e, &Rfu.unk_c86, 1);
        rfu_setRecvBuffer(0x10, Rfu.unk_c3e, Rfu.unk_c3f, 70);
        break;
    case 0x25:
        sub_8011A64(2, 0x25);
        break;
    case 0x30:
        Rfu.unk_f0 = 2;
        if (Rfu.unk_c86 == 6)
            break;
    case 0x33:
        if (Rfu.unk_f0 != 2)
            Rfu.unk_f0 = 4;
        if (Rfu.unk_c86 != 9)
            sub_8011A64(2, a0);
        nullsub_5(gUnknown_082ED7FC, 5, 5);
        if (gReceivedRemoteLinkPlayers == 1)
            sub_8011170(a0);
        break;
    case 0x31:
        Rfu.unk_f0 = 1;
        nullsub_5(gUnknown_082ED814, 5, 5);
        break;
    case 0x32:
        Rfu.unk_f0 = 3;
        Rfu.unk_c3c = 1;
        break;
    case 0x34:
        break;
    case 0x42 ... 0x44:
        break;
    case 0xF3:
        sub_8011A64(1, a0);
        sub_8011170(a0);
        Rfu.unk_ef = 1;
        break;
    case 0xF0 ... 0xF2:
    case 0xFF:
        sub_8011A64(1, a0);
        sub_8011170(a0);
        Rfu.unk_cdb = 1;
        break;
    }
}

void sub_80115EC(s32 a0)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if ((a0 >> i) & 1)
        {
            Rfu.unk_cea[i] = 0;
            Rfu.unk_cee[i] = 0xFF;
        }
    }
}

u8 sub_8011628(s32 a0)
{
    u8 ret = 0;
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if ((a0 >> i) & 1)
        {
            struct GFtgtGname *structPtr = (void *)gRfuLinkStatus->partner[i].gname;
            if (structPtr->activity == 0x45)
                ret |= (1 << i);
        }
    }

    return ret;
}

void sub_8011674(u8 a0, u8 unused1)
{
    u8 r1;

    switch (a0)
    {
    case 0x00:
        Rfu.unk_04 = 0x11;
        break;
    case 0x10:
        sub_8011A64(4, 0);
        break;
    case 0x11:
        if (sub_800F7DC()->activity == 0x45 && Rfu.unk_cd9 == 0)
        {
            u8 idx = sub_8011628(lman.param[0]);
            if (idx != 0)
            {
                r1 = 1 << sub_800E87C(idx);
                if (Rfu.unk_ce6 == 0 && Rfu.unk_ce8 == 0)
                {
                    Rfu.unk_ce5 = r1;
                    Rfu.unk_ce6 |= (r1 ^ idx);
                    Rfu.unk_ce8 = 1;
                }
                else
                {
                    Rfu.unk_ce6 |= idx;
                }
            }
            if (idx != lman.param[0])
            {
                Rfu.unk_ce3 |= (idx ^ lman.param[0]);
                Rfu.unk_ce4 = 2;
            }
        }
        else if (sub_800F7DC()->activity == 0x54)
        {
            rfu_REQ_disconnect(lman.acceptSlot_flag);
            rfu_waitREQComplete();
        }
        sub_80115EC(lman.param[0]);
        break;
    case 0x12:
        break;
    case 0x13:
        break;
    case 0x14:
        if (sub_800F7DC()->activity != 0x45 && lman.acceptCount > 1)
        {
            r1 = 1 << sub_800E87C(lman.param[0]);
            rfu_REQ_disconnect(lman.acceptSlot_flag ^ r1);
            rfu_waitREQComplete();
        }
        if (Rfu.unk_04 == 0xF)
            Rfu.unk_04 = 0x10;
        break;
        break;
    case 0x20:
        Rfu.unk_ccd = lman.param[0];
        break;
    case 0x21:
        break;
    case 0x22:
        Rfu.unk_c3e = lman.param[0];
        break;
    case 0x23:
        Rfu.unk_04 = 0x12;
        if (Rfu.unk_ccf < 2)
        {
            Rfu.unk_ccf++;
            CreateTask(sub_801209C, 2);
        }
        else
        {
            sub_8011A64(2, a0);
        }
        break;
    case 0x24:
        Rfu.unk_04 = 0xD;
        sub_8011A64(3, 0);
        rfu_setRecvBuffer(0x10, Rfu.unk_c3e, Rfu.unk_c3f, 70);
        break;
    case 0x25:
        sub_8011A64(2, a0);
        break;
    case 0x31:
        if (lman.acceptSlot_flag & lman.param[0])
            Rfu.unk_f0 = 1;
        break;
    case 0x32:
        Rfu.unk_f0 = 3;
        if (gRfuLinkStatus->parentChild == 0)
            Rfu.unk_c3c = 1;
        break;
    case 0x30:
        Rfu.unk_f0 = 2;
    case 0x33:
        if (Rfu.unk_f0 != 2)
            Rfu.unk_f0 = 4;
        if (Rfu.unk_0c == 1)
        {
            if (gReceivedRemoteLinkPlayers == 1)
            {
                Rfu.unk_ce2 &= ~(lman.param[0]);
                if (Rfu.unk_ce2 == 0)
                    sub_8011170(a0);
                else
                    sub_80111FC();
            }
        }
        else if (Rfu.unk_ce4 != 2 && gReceivedRemoteLinkPlayers == 1)
        {
            sub_8011170(a0);
            rfu_LMAN_stopManager(0);
        }

        if (gRfuLinkStatus->parentChild == 0xFF && lman.pcswitch_flag == 0 && FuncIsActiveTask(sub_800EB44) == TRUE)
            Rfu.unk_04 = 0x11;

        sub_8011A64(2, a0);
        break;
    case 0x40:
        Rfu.unk_ce3 = 0;
        break;
    case 0x42 ... 0x44:
        break;
    case 0xF3:
        sub_8011A64(1, a0);
        sub_8011170(a0);
        Rfu.unk_ef = 1;
        break;
    case 0xF0 ... 0xF2:
    case 0xFF:
        sub_8011170(a0);
        sub_8011A64(1, a0);
        Rfu.unk_cdb = 0;
        break;
    }
}

void sub_8011A50(void)
{
    Rfu.unk_ce4 = 2;
}

void sub_8011A64(u8 a0, u16 a1)
{
    Rfu.unk_f1 = a0;
    Rfu.unk_0a = a1;
}

u8 sub_8011A74(void)
{
    return Rfu.unk_f1;
}

bool32 sub_8011A80(void)
{
    u32 var = sub_8011A74() - 1;
    if (var < 2)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8011A9C(void)
{
    return Rfu.unk_ce8;
}

bool8 Rfu_IsMaster(void)
{
    return Rfu.unk_0c;
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
        sub_800B488();
        OpenLink();
        SeedRng(gMain.vblankCounter2);
        for (i = 0; i < 4; i++)
            gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_1D_MAP);
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        sub_8011BA4();
        SetMainCallback2(sub_8011BF8);
    }
}

bool32 sub_8011B90(void)
{
    return FuncIsActiveTask(sub_800EB44);
}

void sub_8011BA4(void)
{
    if (!FuncIsActiveTask(nullsub_89))
        Rfu.unk_66 = CreateTask(nullsub_89, 0);
}

void sub_8011BD0(void)
{
     if (FuncIsActiveTask(nullsub_89) == TRUE)
        DestroyTask(Rfu.unk_66);
}

void sub_8011BF8(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_8011C10(u32 a0)
{
    Rfu.unk_0c = 1;
    sub_8010F48();
    rfu_LMAN_initializeManager(sub_801120C, NULL);
    gUnknown_02022B2C = gUnknown_082ED608;
    gUnknown_02022B2C.availSlot_flag = gUnknown_082ED620[a0 - 1];
    sub_800EE78();
}

void sub_8011C5C(void)
{
    Rfu.unk_0c = 0;
    sub_8010F48();
    rfu_LMAN_initializeManager(sub_8011404, sub_800ED34);
    sub_800EF00();
}

void sub_8011C84(void)
{
    Rfu.unk_0c = 2;
    sub_8010F48();
    rfu_LMAN_initializeManager(sub_8011674, NULL);
    gUnknown_02022B2C = gUnknown_082ED608;
    gUnknown_02022B2C.linkRecovery_enable = 0;
    gUnknown_02022B2C.linkRecovery_period = 0x258;
    Rfu.unk_67 = CreateTask(sub_800EB44, 1);
}

u16 ReadU16(const void *ptr)
{
    const u8 *ptr_ = ptr;
    return (ptr_[1] << 8) | (ptr_[0]);
}

u8 sub_8011CE4(const u8 *a0, u16 a1)
{
    u8 i;
    u8 ret = 0xFF;

    for (i = 0; i < 4; i++)
    {
        u16 trainerId = ReadU16(gRfuLinkStatus->partner[i].gname + 2);
        if (sub_8010454(gRfuLinkStatus->partner[i].serialNo)
            && !StringCompare(a0, gRfuLinkStatus->partner[i].uname)
            && a1 == trainerId)
        {
            ret = i;
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
                break;
        }
    }

    return ret;
}

void sub_8011D6C(u32 a0)
{
    rfu_REQ_disconnect(a0);
    rfu_waitREQComplete();
    Rfu.unk_ce2 &= ~(a0);
    rfu_clearSlot(1, Rfu.unk_cda);
    rfu_UNI_setSendData(Rfu.unk_ce2, Rfu.unk_c87, 70);
    Rfu.unk_cda = sub_800E87C(Rfu.unk_ce2);
}

void sub_8011DC0(const u8 *ptr, u16 a1)
{
    u8 var = sub_8011CE4(ptr, a1);
    if (var != 0xFF)
        sub_8011D6C(1 << var);
}

void sub_8011DE0(u32 a0)
{
    if (a0 != 0)
    {
        s32 i;
        u8 var = 0;

        for (i = 0; i < 4; i++)
        {
            if (Rfu.unk_cde[i] == a0 && (Rfu.unk_ce2 >> i) & 1)
                var |= 1 << i;
        }
        if (var)
            sub_8011E94(var, 2);
    }
}

void sub_8011E2C(u8 taskId)
{
    if (gSendCmd[0] == 0 && Rfu.unk_ce8 == 0)
    {
        sub_800FD14(0xED00);
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

void sub_8011EF4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (sub_800EE94())
    {
        u8 id = sub_8011CE4((u8*)data, ReadU16(&data[8]));
        if (id != 0xFF)
        {
            if (gRfuLinkStatus->partner[id].slot != 0xFF)
            {
                Rfu.unk_c3d = id;
                if (sub_800EEBC())
                    DestroyTask(taskId);
            }
            else if (sub_800F7DC()->activity == 0x15 || sub_800F7DC()->activity == 0x16)
            {
                data[15]++;
            }
            else
            {
                sub_8011A64(2, 0x7000);
                DestroyTask(taskId);
            }
        }
        else
        {
            data[15]++;
            Rfu.unk_c3d = id;
        }
    }
    else
    {
        data[15]++;
    }

    if (data[15] > 240)
    {
        sub_8011A64(2, 0x7000);
        DestroyTask(taskId);
    }
}

void sub_8011FC8(const u8 *src, u16 trainerId)
{
    u8 taskId;
    s16 *data;

    Rfu.unk_f1 = 0;
    taskId = CreateTask(sub_8011EF4, 3);
    data = gTasks[taskId].data;
    StringCopy((u8*)(data), src);
    data[8] = trainerId;
}

bool32 sub_801200C(s16 a1, struct GFtgtGname *structPtr)
{
    if (sub_800F7DC()->activity == 0x45)
    {
        if (structPtr->activity != 0x45)
            return TRUE;
    }
    else if (structPtr->activity != 0x40)
    {
        return TRUE;
    }
    else if (a1 == 0x44)
    {
        struct GFtgtGname *structPtr2 = &Rfu.unk_10A;
        if (structPtr2->species == SPECIES_EGG)
        {
            if (structPtr->species == structPtr2->species)
                return FALSE;
            else
                return TRUE;
        }
        else if (structPtr->species != structPtr2->species
                 || structPtr->level != structPtr2->level
                 || structPtr->type != structPtr2->type)
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
        sub_8011A64(2, 0x7000);
        DestroyTask(taskId);
    }

    if (Rfu.unk_ccd != 0 && lman.parent_child == 0)
    {
        u16 trainerId = ReadU16(Rfu.unk_10A.unk_00.playerTrainerId);
        u8 id = sub_8011CE4(Rfu.playerName, trainerId);
        if (id != 0xFF)
        {
            if (!sub_801200C(gTasks[taskId].data[1], (void *)gRfuLinkStatus->partner[id].gname))
            {
                if (gRfuLinkStatus->partner[id].slot != 0xFF && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[id].id, 0x5A))
                {
                    Rfu.unk_04 = 0xA;
                    DestroyTask(taskId);
                }
            }
            else
            {
                sub_8011A64(2, 0x7000);
                DestroyTask(taskId);
            }
        }
    }
}

void sub_8012188(const u8 *name, struct GFtgtGname *structPtr, u8 a2)
{
    u8 taskId, taskId2;

    Rfu.unk_ccf = 0;
    Rfu.unk_f1 = 0;
    StringCopy(Rfu.playerName, name);
    memcpy(&Rfu.unk_10A, structPtr, 0xD);
    rfu_LMAN_forceChangeSP();
    taskId = CreateTask(sub_801209C, 2);
    gTasks[taskId].data[1] = a2;
    taskId2 = FindTaskIdByFunc(sub_800EB44);
    if (a2 == 0x45)
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
    if (Rfu.unk_f0 == 1)
        return TRUE;
    else
        return FALSE;
}

bool32 sub_8012240(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if ((lman.acceptSlot_flag >> i) & 1 && Rfu.unk_cd1[i] == 0)
            return FALSE;
    }

    return TRUE;
}

void sub_801227C(void)
{
    s32 i;

    for (i = 0; i < 20; i++)
        nullsub_5(gUnknown_082ED82C, 0, i);
}

void sub_801229C(void)
{
    s32 i, j;

    nullsub_13(GetBlockReceivedStatus(), 0x1C, 0x13, 2);
    nullsub_13(gRfuLinkStatus->connSlotFlag, 0x14, 1, 1);
    nullsub_13(gRfuLinkStatus->linkLossSlotFlag, 0x17, 1, 1);
    if (Rfu.unk_0c == 1)
    {
        for (i = 0; i < 4; i++)
        {
            if ((gRfuLinkStatus->getNameFlag >> i) & 1)
            {
                nullsub_13(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                nullsub_5((void*)gRfuLinkStatus->partner[i].gname, 6, i + 3);
                nullsub_5(gRfuLinkStatus->partner[i].uname, 0x16, i + 3);
            }
        }
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 14; j++)
            {
                nullsub_13(Rfu.unk_14[i][j], j * 2, i + 11, 2);
            }
        }
        nullsub_5(gUnknown_082ED868, 1, 0xF);
    }
    else if (gRfuLinkStatus->connSlotFlag != 0 && gRfuLinkStatus->getNameFlag != 0)
    {
        for (i = 0; i < 4; i++)
        {
            nullsub_13(0, 1, i + 3, 4);
            nullsub_5(gUnknown_082ED84B, 6, i + 3);
            nullsub_5(gUnknown_082ED85B, 0x16, i + 3);
        }
        nullsub_13(gRfuLinkStatus->partner[Rfu.unk_c3e].serialNo, 1, 3, 4);
        nullsub_5((void*)gRfuLinkStatus->partner[Rfu.unk_c3e].gname, 6, 3);
        nullsub_5(gRfuLinkStatus->partner[Rfu.unk_c3e].uname, 0x16, 3);
    }
    else
    {
        for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
        {
            if (gRfuLinkStatus->partner[i].slot != 0xFF)
            {
                nullsub_13(gRfuLinkStatus->partner[i].serialNo, 1, i + 3, 4);
                nullsub_13(gRfuLinkStatus->partner[i].id, 6, i + 3, 4);
                nullsub_5(gRfuLinkStatus->partner[i].uname, 0x16, i + 3);
            }
        }
        for (; i < 4; i++)
        {
            nullsub_13(0, 1, i + 3, 4);
            nullsub_5(gUnknown_082ED84B, 6, i + 3);
            nullsub_5(gUnknown_082ED85B, 0x16, i + 3);
        }
    }
}

u32 sub_80124C0(void)
{
    return Rfu.unk_9e8.unk_232;
}

u32 GetRfuRecvQueueLength(void)
{
    return Rfu.unk_124.unk_8c2;
}

void nullsub_89(u8 taskId)
{

}
