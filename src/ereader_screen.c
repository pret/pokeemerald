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

struct Unk81D5014
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 *unk10;
};

struct Unk03006370
{
    u16 unk0;
    u32 unk4;
    u32 *unk8;
};

static void sub_81D5084(u8);

struct Unk03006370 gUnknown_03006370;

extern const u8 gUnknown_089A3470[];
extern const u8 gMultiBootProgram_BerryGlitchFix_Start[];

static void sub_81D4D50(struct Unk03006370 *arg0, int arg1, u32 *arg2)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    gIntrTable[1] = EReaderHelper_SerialCallback;
    gIntrTable[2] = EReaderHelper_Timer3Callback;
    EReaderHelper_SaveRegsState();
    EReaderHelper_ClearSendRecvMgr();
    REG_IE |= INTR_FLAG_VCOUNT;
    REG_IME = backupIME;
    arg0->unk0 = 0;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
}

static void sub_81D4DB8(struct Unk03006370 *arg0)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    EReaderHelper_ClearSendRecvMgr();
    EReaderHelper_RestoreRegsState();
    RestoreSerialTimer3IntrHandlers();
    REG_IME = backupIME;
}

static u8 sub_81D4DE8(struct Unk03006370 *arg0)
{
    u8 var0 = 0;
    arg0->unk0 = EReaderHandleTransfer(1, arg0->unk4, arg0->unk8, NULL);
    if ((arg0->unk0 & 0x13) == 0x10)
        var0 = 1;

    if (arg0->unk0 & 0x8)
        var0 = 2;

    if (arg0->unk0 & 0x4)
        var0 = 3;

    gShouldAdvanceLinkState = 0;
    return var0;
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
    volatile u16 backupIME;
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

static bool32 sub_81D4EC0(void)
{
    if (IsLinkMaster() && GetLinkPlayerCount_2() == 2)
        return TRUE;

    return FALSE;
}

static u32 sub_81D4EE4(u8 *arg0, u16 *arg1)
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
    struct Unk81D5014 *data;
    u8 taskId = CreateTask(sub_81D5084, 0);
    data = (struct Unk81D5014 *)gTasks[taskId].data;
    data->unk8 = 0;
    data->unk9 = 0;
    data->unkA = 0;
    data->unkB = 0;
    data->unkC = 0;
    data->unkD = 0;
    data->unk0 = 0;
    data->unk2 = 0;
    data->unk4 = 0;
    data->unk6 = 0;
    data->unkE = 0;
    data->unk10 = AllocZeroed(0x40);
}

static void sub_81D505C(u16 *arg0)
{
    *arg0 = 0;
}

static bool32 sub_81D5064(u16 *arg0, u16 arg1)
{
    if (++(*arg0) > arg1)
    {
        *arg0 = 0;
        return TRUE;
    }
    
    return FALSE;
}

static void sub_81D5084(u8 taskId)
{
    struct Unk81D5014 *data = (struct Unk81D5014 *)gTasks[taskId].data;
    switch (data->unk8)
    {
    case 0:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_ReceiveMysteryGiftWithEReader))
            data->unk8 = 1;
        break;
    case 1:
        OpenEReaderLink();
        sub_81D505C(&data->unk0);
        data->unk8 = 2;
        break;
    case 2:
        if (sub_81D5064(&data->unk0, 10))
            data->unk8 = 3;
        break;
    case 3:
        if (!sub_81D4EC0())
        {
            CloseLink();
            data->unk8 = 4;
        }
        else
        {
            data->unk8 = 13;
        }
        break;
    case 4:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_SelectConnectFromEReaderMenu))
        {
            AddTextPrinterToWindow1(gJPText_SelectConnectWithGBA);
            sub_81D505C(&data->unk0);
            data->unk8 = 5;
        }
        break;
    case 5:
        if (sub_81D5064(&data->unk0, 90))
        {
            OpenEReaderLink();
            data->unk8 = 6;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            sub_81D505C(&data->unk0);
            PlaySE(SE_SELECT);
            data->unk8 = 23;
        }
        break;
    case 6:
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseLink();
            sub_81D505C(&data->unk0);
            data->unk8 = 23;
        }
        else if (GetLinkPlayerCount_2() > 1)
        {
            sub_81D505C(&data->unk0);
            CloseLink();
            data->unk8 = 7;
        }
        else if (sub_81D4E60())
        {
            PlaySE(SE_SELECT);
            CloseLink();
            sub_81D505C(&data->unk0);
            data->unk8 = 8;
        }
        else if (sub_81D5064(&data->unk0, 10))
        {
            CloseLink();
            OpenEReaderLink();
            sub_81D505C(&data->unk0);
        }
        break;
    case 7:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_LinkIsIncorrect))
            data->unk8 = 4;
        break;
    case 8:
        AddTextPrinterToWindow1(gJPText_Connecting);
        // XXX: This (u32*) cast is discarding the const qualifier from gUnknown_089A3470
        sub_81D4D50(&gUnknown_03006370, gMultiBootProgram_BerryGlitchFix_Start - gUnknown_089A3470, (u32*)gUnknown_089A3470);
        data->unk8 = 9;
        break;
    case 9:
        data->unkE = sub_81D4DE8(&gUnknown_03006370);
        if (data->unkE)
            data->unk8 = 10;
        break;
    case 10:
        sub_81D4DB8(&gUnknown_03006370);
        if (data->unkE == 3)
        {
            data->unk8 = 20;
        }
        else if (data->unkE == 1)
        {
            sub_81D505C(&data->unk0);
            AddTextPrinterToWindow1(gJPText_PleaseWaitAMoment);
            data->unk8 = 11;
        }
        else
        {
            data->unk8 = 0;
        }
        break;
    case 11:
        if (sub_81D5064(&data->unk0, 840))
            data->unk8 = 12;
        break;
    case 12:
        OpenEReaderLink();
        AddTextPrinterToWindow1(gJPText_AllowEReaderToLoadCard);
        data->unk8 = 13;
        break;
    case 13:
        switch (sub_81D4EE4(&data->unk9, &data->unk0))
        {
            case 0:
                break;
            case 2:
                AddTextPrinterToWindow1(gJPText_Connecting);
                data->unk8 = 14;
                break;
            case 1:
                PlaySE(SE_SELECT);
                CloseLink();
                data->unk8 = 23;
                break;
            case 5:
                CloseLink();
                data->unk8 = 21;
                break;
            case 3:
            case 4:
                CloseLink();
                data->unk8 = 20;
                break;
        }
        break;
    case 14:
        if (HasLinkErrorOccurred())
        {
            CloseLink();
            data->unk8 = 20;
        }
        else if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            data->unk8 = 15;
        }
        break;
    case 15:
        data->unkE = ValidateTrainerHillData((struct EReaderTrainerHillSet *)gDecompressionBuffer);
        SetCloseLinkCallbackAndType(data->unkE);
        data->unk8 = 16;
        break;
    case 16:
        if (!gReceivedRemoteLinkPlayers)
        {
            if (data->unkE == 1)
                data->unk8 = 17;
            else
                data->unk8 = 20;
        }
        break;
    case 17:
        if (TryWriteTrainerHill((struct EReaderTrainerHillSet *)&gDecompressionBuffer))
        {
            AddTextPrinterToWindow1(gJPText_ConnectionComplete);
            sub_81D505C(&data->unk0);
            data->unk8 = 18;
        }
        else
        {
            data->unk8 = 22;
        }
        break;
    case 18:
        if (sub_81D5064(&data->unk0, 120))
        {
            AddTextPrinterToWindow1(gJPText_NewTrainerHasComeToHoenn);
            PlayFanfare(MUS_OBTAIN_ITEM);
            data->unk8 = 19;
        }
        break;
    case 19:
        if (IsFanfareTaskInactive() && (JOY_NEW(A_BUTTON | B_BUTTON)))
            data->unk8 = 26;
        break;
    case 23:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_CardReadingHasBeenHalted))
            data->unk8 = 26;
        break;
    case 20:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_ConnectionErrorCheckLink))
            data->unk8 = 0;
        break;
    case 21:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_ConnectionErrorTryAgain))
            data->unk8 = 0;
        break;
    case 22:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->unk9, gJPText_WriteErrorUnableToSaveData))
            data->unk8 = 0;
        break;
    case 26:
        Free(data->unk10);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}
