#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "mystery_gift.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "strings.h"
#include "util.h"
#include "constants/songs.h"

struct MEventTaskData1
{
    u16 stateAdvanceDelay;
    u16 t02;
    u16 t04;
    u16 t06;
    u8 state;
    u8 textOrReceiveState;
    u8 t0A;
    u8 t0B;
    u8 t0C;
    u8 t0D;
    u8 initialSendResult;
    struct MEvent_Str_2 *t10;
};

struct MEvent_Str_1
{
    u16 status;
    u32 size;
    const u32 *data;
};

static void Task_EReaderComm(u8);

struct MEvent_Str_1 sMEventSendToEReaderManager;

extern const u8 gUnknown_089A3470[];
extern const u8 gMultiBootProgram_BerryGlitchFix_Start[];

static void SendUnknownSerialData_Init(struct MEvent_Str_1 *arg0, u32 arg1, u32 *arg2)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    gIntrTable[1] = EReaderHelper_SerialCallback;
    gIntrTable[2] = EReaderHelper_Timer3Callback;
    EReaderHelper_SaveRegsState();
    EReaderHelper_ClearsSendRecvMgr();
    REG_IE |= INTR_FLAG_VCOUNT;
    REG_IME = backupIME;
    arg0->status = 0;
    arg0->size = arg1;
    arg0->data = arg2;
}

static void SendUnknownSerialData_Teardown(struct MEvent_Str_1 *arg0)
{
    vu16 backupIME = REG_IME;
    REG_IME = 0;
    EReaderHelper_ClearsSendRecvMgr();
    EReaderHelper_RestoreRegsState();
    RestoreSerialTimer3IntrHandlers();
    REG_IME = backupIME;
}

static u8 SendUnknownSerialData_Run(struct MEvent_Str_1 *arg0)
{
    u8 retVar = 0;
    arg0->status = EReaderHandleTransfer(1, arg0->size, arg0->data, NULL);
    if ((arg0->status & 0x13) == 0x10)
        retVar = 1;

    if (arg0->status & 0x8)
        retVar = 2;

    if (arg0->status & 0x4)
        retVar = 3;

    gShouldAdvanceLinkState = 0;
    return retVar;
}

static void OpenEReaderLink(void)
{
    memset(gDecompressionBuffer, 0, 0x2000);
    gLinkType = LINKTYPE_EREADER;
    OpenLink();
    SetSuppressLinkErrorMessage(TRUE);
}

static bool32 sub_81D4E60(void)
{
    vu16 backupIME;
    u16 sp4[4];

    backupIME = REG_IME;
    REG_IME = 0;
    *(u64 *)sp4 = *(u64 *)gLink.tempRecvBuffer;
    REG_IME = backupIME;
    if (sp4[0] == 0xB9A0 && sp4[1] == 0xCCD0
     && sp4[2] == 0xFFFF && sp4[3] == 0xFFFF)
    {
        return TRUE;
    }

    return FALSE;
}

static bool32 IsEReaderConnectionSane(void)
{
    if (IsLinkMaster() && GetLinkPlayerCount_2() == 2)
        return TRUE;

    return FALSE;
}

static u32 EReaderReceive(u8 *arg0, u16 *arg1)
{
    u8 var0;

    var0 = *arg0 - 3;
    if (var0 < 3 && HasLinkErrorOccurred())
    {
        *arg0 = 0;
        return 3;
    }

    switch (*arg0)
    {
    case 0:
        if (IsLinkMaster() && GetLinkPlayerCount_2() > 1)
        {
            *arg0 = 1;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            *arg0 = 0;
            return 1;
        }
        break;
    case 1:
        if (++(*arg1) > 5)
        {
            *arg1 = 0;
            *arg0 = 2;
        }
        break;
    case 2:
        if (GetLinkPlayerCount_2() == 2)
        {
            PlaySE(SE_DING_DONG);
            CheckShouldAdvanceLinkState();
            *arg1 = 0;
            *arg0 = 3;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            *arg0 = 0;
            return 1;
        }
        break;
    case 3:
        if (++(*arg1) > 30)
        {
            *arg0 = 0;
            return 5;
        }

        if (IsLinkConnectionEstablished())
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkPlayerDataExchangeComplete())
                {
                    *arg0 = 0;
                    return 2;
                }
                else
                {
                    *arg0 = 4;
                }
            }
            else
            {
                *arg0 = 3;
            }
        }
        break;
    case 4:
        SetCloseLinkCallbackAndType(0);
        *arg0 = 5;
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
        {
            *arg0 = 0;
            return 4;
        }
        break;
    default:
        return 0;
    }

    return 0;
}

void task_add_00_ereader(void)
{
    u8 taskId = CreateTask(Task_EReaderComm, 0);
    struct MEventTaskData1 *data = (struct MEventTaskData1 *)gTasks[taskId].data;
    data->state = 0;
    data->textOrReceiveState = 0;
    data->t0A = 0;
    data->t0B = 0;
    data->t0C = 0;
    data->t0D = 0;
    data->stateAdvanceDelay = 0;
    data->t02 = 0;
    data->t04 = 0;
    data->t06 = 0;
    data->initialSendResult = 0;
    data->t10 = AllocZeroed(0x40); // sizeof(struct MEvent_Str_2)
}

static void ResetDelayTimer(u16 *arg0)
{
    *arg0 = 0;
}

static bool32 AdvanceDelayTimerCheckTimeout(u16 *arg0, u16 arg1)
{
    if (++(*arg0) > arg1)
    {
        *arg0 = 0;
        return TRUE;
    }

    return FALSE;
}

static void Task_EReaderComm(u8 taskId)
{
    struct MEventTaskData1 *data = (struct MEventTaskData1 *)gTasks[taskId].data;
    switch (data->state)
    {
    case 0:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_ReceiveMysteryGiftWithEReader))
            data->state = 1;
        break;
    case 1:
        OpenEReaderLink();
        ResetDelayTimer(&data->stateAdvanceDelay);
        data->state = 2;
        break;
    case 2:
        if (AdvanceDelayTimerCheckTimeout(&data->stateAdvanceDelay, 10))
            data->state = 3;
        break;
    case 3:
        if (!IsEReaderConnectionSane())
        {
            CloseLink();
            data->state = 4;
        }
        else
        {
            data->state = 13;
        }
        break;
    case 4:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_SelectConnectFromEReaderMenu))
        {
            AddTextPrinterToWindow1(gJPText_SelectConnectWithGBA);
            ResetDelayTimer(&data->stateAdvanceDelay);
            data->state = 5;
        }
        break;
    case 5:
        if (AdvanceDelayTimerCheckTimeout(&data->stateAdvanceDelay, 90))
        {
            OpenEReaderLink();
            data->state = 6;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            ResetDelayTimer(&data->stateAdvanceDelay);
            PlaySE(SE_SELECT);
            data->state = 23;
        }
        break;
    case 6:
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseLink();
            ResetDelayTimer(&data->stateAdvanceDelay);
            data->state = 23;
        }
        else if (GetLinkPlayerCount_2() > 1)
        {
            ResetDelayTimer(&data->stateAdvanceDelay);
            CloseLink();
            data->state = 7;
        }
        else if (sub_81D4E60())
        {
            PlaySE(SE_SELECT);
            CloseLink();
            ResetDelayTimer(&data->stateAdvanceDelay);
            data->state = 8;
        }
        else if (AdvanceDelayTimerCheckTimeout(&data->stateAdvanceDelay, 10))
        {
            CloseLink();
            OpenEReaderLink();
            ResetDelayTimer(&data->stateAdvanceDelay);
        }
        break;
    case 7:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_LinkIsIncorrect))
            data->state = 4;
        break;
    case 8:
        AddTextPrinterToWindow1(gJPText_Connecting);
        // XXX: This (u32*) cast is discarding the const qualifier from gUnknown_089A3470
        SendUnknownSerialData_Init(&sMEventSendToEReaderManager, gMultiBootProgram_BerryGlitchFix_Start - gUnknown_089A3470, (u32*)gUnknown_089A3470);
        data->state = 9;
        break;
    case 9:
        data->initialSendResult = SendUnknownSerialData_Run(&sMEventSendToEReaderManager);
        if (data->initialSendResult != 0)
            data->state = 10;
        break;
    case 10:
        SendUnknownSerialData_Teardown(&sMEventSendToEReaderManager);
        if (data->initialSendResult == 3)
        {
            // Error
            data->state = 20;
            break;
        }
        if (data->initialSendResult == 1)
        {
            ResetDelayTimer(&data->stateAdvanceDelay);
            AddTextPrinterToWindow1(gJPText_PleaseWaitAMoment);
            data->state = 11;
            break;
        }
        data->state = 0;
        break;
    case 11:
        if (AdvanceDelayTimerCheckTimeout(&data->stateAdvanceDelay, 840))
            data->state = 12;
        break;
    case 12:
        OpenEReaderLink();
        AddTextPrinterToWindow1(gJPText_AllowEReaderToLoadCard);
        data->state = 13;
        break;
    case 13:
        switch (EReaderReceive(&data->textOrReceiveState, &data->stateAdvanceDelay))
        {
        case 0:
            break;
        case 2:
            AddTextPrinterToWindow1(gJPText_Connecting);
            data->state = 14;
            break;
        case 1:
            PlaySE(SE_SELECT);
            CloseLink();
            data->state = 23;
            break;
        case 5:
            CloseLink();
            data->state = 21;
            break;
        case 3:
        case 4:
            CloseLink();
            data->state = 20;
            break;
        }
        break;
    case 14:
        if (HasLinkErrorOccurred())
        {
            CloseLink();
            data->state = 20;
            break;
        }
        if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            data->state = 15;
        }
        break;
    case 15:
        data->initialSendResult = EReader_IsReceivedDataValid((struct EReaderTrainerHillSet *)gDecompressionBuffer);
        SetCloseLinkCallbackAndType(data->initialSendResult);
        data->state = 16;
        break;
    case 16:
        if (!gReceivedRemoteLinkPlayers)
        {
            if (data->initialSendResult == 1)
                data->state = 17;
            else
                data->state = 20;
        }
        break;
    case 17:
        if (TryWriteTrainerHill((struct EReaderTrainerHillSet *)&gDecompressionBuffer))
        {
            AddTextPrinterToWindow1(gJPText_ConnectionComplete);
            ResetDelayTimer(&data->stateAdvanceDelay);
            data->state = 18;
        }
        else
        {
            data->state = 22;
        }
        break;
    case 18:
        if (AdvanceDelayTimerCheckTimeout(&data->stateAdvanceDelay, 120))
        {
            AddTextPrinterToWindow1(gJPText_NewTrainerHasComeToHoenn);
            PlayFanfare(MUS_OBTAIN_ITEM);
            data->state = 19;
        }
        break;
    case 19:
        if (IsFanfareTaskInactive() && (JOY_NEW(A_BUTTON | B_BUTTON)))
            data->state = 26;
        break;
    case 23:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_CardReadingHasBeenHalted))
            data->state = 26;
        break;
    case 20:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_ConnectionErrorCheckLink))
            data->state = 0;
        break;
    case 21:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_ConnectionErrorTryAgain))
            data->state = 0;
        break;
    case 22:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textOrReceiveState, gJPText_WriteErrorUnableToSaveData))
            data->state = 0;
        break;
    case 26:
        Free(data->t10);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}
