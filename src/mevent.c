#include "global.h"
#include "main.h"
#include "decompress.h"
#include "constants/songs.h"
#include "task.h"
#include "link.h"
#include "link_rfu.h"
#include "alloc.h"
#include "unk_81d3b54.h"
#include "strings.h"
#include "sound.h"
#include "cereader_tool.h"
#include "mystery_gift_menu.h"
#include "mevent.h"

struct MEventTaskData1
{
    u16 t00;
    u16 t02;
    u16 t04;
    u16 t06;
    u8 t08;
    u8 t09;
    u8 t0A;
    u8 t0B;
    u8 t0C;
    u8 t0D;
    u8 t0E;
    struct MEvent_Str_2 *t10;
};

void sub_81D5084(u8 taskId);
bool32 sub_8143E64(const struct MEventBuffer_3120_Sub * src);
void sub_8143E9C(void);
void sub_8143ED0(void);
bool32 sub_8144018(const struct MEventBuffer_32E0_Sub * src);
void sub_814407C(void);
void sub_81440B4(void);
void sub_8144824(u32, u32, u32 *, s32);
void sub_8144790(void);

extern const u8 gUnknownSerialData_Start[];
extern const u8 gUnknownSerialData_End[];

struct MEvent_Str_1 gUnknown_03006370;

static EWRAM_DATA bool32 gUnknown_203F3BC = FALSE;

void sub_81D4D50(struct MEvent_Str_1 *a0, size_t a1, const void * a2)
{
    vu16 imeBak = REG_IME;
    REG_IME = 0;
    gIntrTable[1] = sub_81D3FAC;
    gIntrTable[2] = sub_81D3F9C;
    sub_81D41A0();
    sub_81D4238();
    REG_IE |= INTR_FLAG_VCOUNT;
    REG_IME = imeBak;
    a0->unk_000 = 0;
    a0->unk_004 = a1;
    a0->unk_008 = a2;
}

void sub_81D4DB8(struct MEvent_Str_1 *unused)
{
    vu16 imeBak = REG_IME;
    REG_IME = 0;
    sub_81D4238();
    sub_81D41F4();
    RestoreSerialTimer3IntrHandlers();
    REG_IME = imeBak;
}

u8 sub_81D4DE8(struct MEvent_Str_1 *a0)
{
    u8 resp = 0;
    a0->unk_000 = sub_81D3D70(1, a0->unk_004, a0->unk_008, 0);
    if ((a0->unk_000 & 0x13) == 0x10)
        resp = 1;
    if (a0->unk_000 & 8)
        resp = 2;
    if (a0->unk_000 & 4)
        resp = 3;
    gShouldAdvanceLinkState = 0;
    return resp;
}

void sub_81D4E30(void)
{
    memset(gDecompressionBuffer, 0, 0x2000);
    gLinkType = 0x5503;
    OpenLink();
    SetSuppressLinkErrorMessage(TRUE);
}

bool32 sub_81D4E60(void)
{
    vu16 imeBak = REG_IME;
    u16 data[4];
    REG_IME = 0;
    *(u64 *)data = *(u64 *)gLink.tempRecvBuffer;
    REG_IME = imeBak;
    if (   data[0] == 0xB9A0
           && data[1] == 0xCCD0
           && data[2] == 0xFFFF
           && data[3] == 0xFFFF
        )
        return TRUE;
    return FALSE;
}

bool32 sub_81D4EC0(void)
{
    if (IsLinkMaster() && GetLinkPlayerCount_2() == 2)
        return TRUE;
    return FALSE;
}

u32 sub_81D4EE4(u8 * r4, u16 * r5)
{
    if ((*r4 == 3 || *r4 == 4 || *r4 == 5) && HasLinkErrorOccurred())
    {
        *r4 = 0;
        return 3;
    }
    switch (*r4)
    {
        case 0:
            if (IsLinkMaster() && GetLinkPlayerCount_2() > 1)
            {
                *r4 = 1;
            }
            else if (JOY_NEW(B_BUTTON))
            {
                *r4 = 0;
                return 1;
            }
            break;
        case 1:
            if (++(*r5) > 5)
            {
                *r5 = 0;
                *r4 = 2;
            }
            break;
        case 2:
            if (GetLinkPlayerCount_2() == 2)
            {
                PlaySE(SE_PINPON);
                sub_800A620();
                *r5 = 0;
                *r4 = 3;
            }
            else if (JOY_NEW(B_BUTTON))
            {
                *r4 = 0;
                return 1;
            }
            break;
        case 3:
            if (++(*r5) > 30)
            {
                *r4 = 0;
                return 5;
            }
            else if (IsLinkConnectionEstablished())
            {
                if (gReceivedRemoteLinkPlayers)
                {
                    if (IsLinkPlayerDataExchangeComplete())
                    {
                        *r4 = 0;
                        return 2;
                    }
                    else
                        *r4 = 4;
                }
                else
                    *r4 = 3;
            }
            break;
        case 4:
            sub_800ABF4(0);
            *r4 = 5;
            break;
        case 5:
            if (!gReceivedRemoteLinkPlayers)
            {
                *r4 = 0;
                return 4;
            }
            break;
    }
    return 0;
}

void sub_81D5014(void)
{
    u8 taskId = CreateTask(sub_81D5084, 0);
    struct MEventTaskData1 *data = (struct MEventTaskData1 *)gTasks[taskId].data;
    data->t08 = 0;
    data->t09 = 0;
    data->t0A = 0;
    data->t0B = 0;
    data->t0C = 0;
    data->t0D = 0;
    data->t00 = 0;
    data->t02 = 0;
    data->t04 = 0;
    data->t06 = 0;
    data->t0E = 0;
    data->t10 = AllocZeroed(sizeof(struct MEvent_Str_2));
}

void sub_81D505C(u16 *a0)
{
    *a0 = 0;
}

bool32 sub_81D5064(u16 * a0, u16 a1)
{
    if (++(*a0) > a1)
    {
        *a0 = 0;
        return TRUE;
    }
    return FALSE;
}

void sub_81D5084(u8 taskId)
{
    struct MEventTaskData1 *data = (struct MEventTaskData1 *)gTasks[taskId].data;
    switch (data->t08)
    {
        case 0:
            if (mevent_0814257C(&data->t09, gUnknown_085EDFD6))
                data->t08 = 1;
            break;
        case 1:
            sub_81D4E30();
            sub_81D505C(&data->t00);
            data->t08 = 2;
            break;
        case 2:
            if (sub_81D5064(&data->t00, 10))
                data->t08 = 3;
            break;
        case 3:
            if (!sub_81D4EC0())
            {
                CloseLink();
                data->t08 = 4;
            }
            else
                data->t08 = 13;
            break;
        case 4:
            if (mevent_0814257C(&data->t09, gUnknown_085EDFF5))
            {
                sub_8018884(gUnknown_085EE014);
                sub_81D505C(&data->t00);
                data->t08 = 5;
            }
            break;
        case 5:
            if (sub_81D5064(&data->t00, 90))
            {
                sub_81D4E30();
                data->t08 = 6;
            }
            else if (JOY_NEW(B_BUTTON))
            {
                sub_81D505C(&data->t00);
                PlaySE(SE_SELECT);
                data->t08 = 23;
            }
            break;
        case 6:
            if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                CloseLink();
                sub_81D505C(&data->t00);
                data->t08 = 23;
            }
            else if (GetLinkPlayerCount_2() > 1)
            {
                sub_81D505C(&data->t00);
                CloseLink();
                data->t08 = 7;
            }
            else if (sub_81D4E60())
            {
                PlaySE(SE_SELECT);
                CloseLink();
                sub_81D505C(&data->t00);
                data->t08 = 8;
            }
            else if (sub_81D5064(&data->t00, 10))
            {
                CloseLink();
                sub_81D4E30();
                sub_81D505C(&data->t00);
            }
            break;
        case 7:
            if (mevent_0814257C(&data->t09, gUnknown_085EE05C))
                data->t08 = 4;
            break;
        case 8:
            sub_8018884(gUnknown_085EE097);
            sub_81D4D50(&gUnknown_03006370, gUnknownSerialData_End - gUnknownSerialData_Start, gUnknownSerialData_Start);
            data->t08 = 9;
            break;
        case 9:
            data->t0E = sub_81D4DE8(&gUnknown_03006370);
            if (data->t0E != 0)
                data->t08 = 10;
            break;
        case 10:
            sub_81D4DB8(&gUnknown_03006370);
            if (data->t0E == 3)
                data->t08 = 20;
            else if (data->t0E == 1)
            {
                sub_81D505C(&data->t00);
                sub_8018884(gUnknown_085EE120);
                data->t08 = 11;
            }
            else
                data->t08 = 0;
            break;
        case 11:
            if (sub_81D5064(&data->t00, 840))
                data->t08 = 12;
            break;
        case 12:
            sub_81D4E30();
            sub_8018884(gUnknown_085EE0DC);
            data->t08 = 13;
            break;
        case 13:
            switch (sub_81D4EE4(&data->t09, &data->t00))
            {
                case 0:
                    break;
                case 2:
                    sub_8018884(gUnknown_085EE097);
                    data->t08 = 14;
                    break;
                case 1:
                    PlaySE(SE_SELECT);
                    CloseLink();
                    data->t08 = 23;
                    break;
                case 5:
                    CloseLink();
                    data->t08 = 21;
                    break;
                case 3:
                case 4:
                    CloseLink();
                    data->t08 = 20;
                    break;
            }
            break;
        case 14:
            if (HasLinkErrorOccurred())
            {
                CloseLink();
                data->t08 = 20;
            }
            else if (GetBlockReceivedStatus())
            {
                ResetBlockReceivedFlags();
                data->t08 = 15;
            }
            break;
        case 15:
            data->t0E = sub_81D3920(gDecompressionBuffer);
            sub_800ABF4(data->t0E);
            data->t08 = 16;
            break;
        case 16:
            if (!gReceivedRemoteLinkPlayers)
            {
                if (data->t0E == 1)
                    data->t08 = 17;
                else
                    data->t08 = 20;
            }
            break;
        case 17:
            if (sub_81D3AB0(gDecompressionBuffer))
            {
                sub_8018884(gUnknown_085EE0FA);
                sub_81D505C(&data->t00);
                data->t08 = 18;
            }
            else
                data->t08 = 22;
            break;
        case 18:
            if (sub_81D5064(&data->t00, 120))
            {
                sub_8018884(gUnknown_085EE107);
                PlayFanfare(MUS_FANFA4);
                data->t08 = 19;
            }
            break;
        case 19:
            if (IsFanfareTaskInactive() &&JOY_NEW(A_BUTTON | B_BUTTON))
                data->t08 = 26;
            break;
        case 23:
            if (mevent_0814257C(&data->t09, gUnknown_085EE06B))
                data->t08 = 26;
            break;
        case 20:
            if (mevent_0814257C(&data->t09, gUnknown_085EE0A3))
                data->t08 = 0;
            break;
        case 21:
            if (mevent_0814257C(&data->t09, gUnknown_085EE0BF))
                data->t08 = 0;
            break;
        case 22:
            if (mevent_0814257C(&data->t09, gUnknown_085EE12D))
                data->t08 = 0;
            break;
        case 26:
            Free(data->t10);
            DestroyTask(taskId);
            SetMainCallback2(sub_80186A4);
            break;
    }
}

