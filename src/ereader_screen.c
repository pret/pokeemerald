#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "mystery_gift_menu.h"
#include "mystery_gift_client.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "strings.h"
#include "util.h"
#include "constants/songs.h"

// Equivalent to MysteryGiftTaskData
struct EReaderTaskData
{
    u16 timer;
    u16 unused1;
    u16 unused2;
    u16 unused3;
    u8 state;
    u8 textState;
    u8 unused4;
    u8 unused5;
    u8 unused6;
    u8 unused7;
    u8 status;
    u8 *unusedBuffer;
};

struct EReaderData
{
    u16 status;
    u32 size;
    u32 *data;
};

static void Task_EReader(u8);

// This belongs in COMMON somewhere between party_menu and ereader_screen, but it's unused so it's unclear where.
COMMON_DATA UNUSED u8 gUnknownSpace[64] = {0};

COMMON_DATA struct EReaderData gEReaderData = {0};

extern const u8 gMultiBootProgram_EReader_Start[];
extern const u8 gMultiBootProgram_EReader_End[];

static void EReader_Load(struct EReaderData *eReader, int size, u32 *data)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    gIntrTable[1] = EReaderHelper_SerialCallback;
    gIntrTable[2] = EReaderHelper_Timer3Callback;
    EReaderHelper_SaveRegsState();
    EReaderHelper_ClearSendRecvMgr();
    REG_IE |= INTR_FLAG_VCOUNT;
    REG_IME = backupIME;
    eReader->status = 0;
    eReader->size = size;
    eReader->data = data;
}

static void EReader_Reset(struct EReaderData *eReader)
{
    volatile u16 backupIME = REG_IME;
    REG_IME = 0;
    EReaderHelper_ClearSendRecvMgr();
    EReaderHelper_RestoreRegsState();
    RestoreSerialTimer3IntrHandlers();
    REG_IME = backupIME;
}

// Return values for EReader_Transfer
enum {
    TRANSFER_ACTIVE,
    TRANSFER_SUCCESS,
    TRANSFER_CANCELED,
    TRANSFER_TIMEOUT,
};

static u8 EReader_Transfer(struct EReaderData *eReader)
{
    u8 transferStatus = TRANSFER_ACTIVE;
    eReader->status = EReaderHandleTransfer(TRUE, eReader->size, eReader->data, NULL);

    if ((eReader->status & EREADER_XFER_MASK) == 0 && eReader->status & EREADER_CHECKSUM_OK_MASK)
        transferStatus = TRANSFER_SUCCESS;

    if (eReader->status & EREADER_CANCEL_KEY_MASK)
        transferStatus = TRANSFER_CANCELED;

    if (eReader->status & EREADER_CANCEL_TIMEOUT_MASK)
        transferStatus = TRANSFER_TIMEOUT;

    gShouldAdvanceLinkState = 0;
    return transferStatus;
}

static void OpenEReaderLink(void)
{
    memset(gDecompressionBuffer, 0, 0x2000);
    gLinkType = LINKTYPE_EREADER_EM;
    OpenLink();
    SetSuppressLinkErrorMessage(TRUE);
}

static bool32 ValidateEReaderConnection(void)
{
    volatile u16 backupIME;
    u16 handshakes[MAX_LINK_PLAYERS];

    backupIME = REG_IME;
    REG_IME = 0;
    *(u64 *)handshakes = *(u64 *)gLink.handshakeBuffer;
    REG_IME = backupIME;

    // Validate that we are player 1, the EReader is player 2,
    // and that players 3 and 4 are empty.
    if (handshakes[0] == SLAVE_HANDSHAKE && handshakes[1] == EREADER_HANDSHAKE
     && handshakes[2] == 0xFFFF && handshakes[3] == 0xFFFF)
    {
        return TRUE;
    }

    return FALSE;
}

static bool32 IsChildConnected(void)
{
    if (IsLinkMaster() && GetLinkPlayerCount_2() == 2)
        return TRUE;

    return FALSE;
}

// States for TryReceiveCard
enum {
    RECV_STATE_INIT,
    RECV_STATE_WAIT_START,
    RECV_STATE_START,
    RECV_STATE_EXCHANGE,
    RECV_STATE_START_DISCONNECT,
    RECV_STATE_WAIT_DISCONNECT,
};

// Return values for TryReceiveCard
enum {
    RECV_ACTIVE,
    RECV_CANCELED,
    RECV_SUCCESS,
    RECV_ERROR,
    RECV_DISCONNECTED,
    RECV_TIMEOUT,
};

static u32 TryReceiveCard(u8 *state, u16 *timer)
{
    if (*state >= RECV_STATE_EXCHANGE
     && *state <= RECV_STATE_WAIT_DISCONNECT
     && HasLinkErrorOccurred())
    {
        // Return error status if an error occurs
        // during the link exchange.
        *state = 0;
        return RECV_ERROR;
    }

    switch (*state)
    {
    case RECV_STATE_INIT:
        if (IsLinkMaster() && GetLinkPlayerCount_2() > 1)
        {
            *state = RECV_STATE_WAIT_START;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            *state = 0;
            return RECV_CANCELED;
        }
        break;
    case RECV_STATE_WAIT_START:
        if (++(*timer) > 5)
        {
            *timer = 0;
            *state = RECV_STATE_START;
        }
        break;
    case RECV_STATE_START:
        if (GetLinkPlayerCount_2() == 2)
        {
            PlaySE(SE_DING_DONG);
            CheckShouldAdvanceLinkState();
            *timer = 0;
            *state = RECV_STATE_EXCHANGE;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            *state = 0;
            return RECV_CANCELED;
        }
        break;
    case RECV_STATE_EXCHANGE:
        if (++(*timer) > 30)
        {
            *state = 0;
            return RECV_TIMEOUT;
        }

        if (IsLinkConnectionEstablished())
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkPlayerDataExchangeComplete())
                {
                    *state = 0;
                    return RECV_SUCCESS;
                }
                else
                {
                    *state = RECV_STATE_START_DISCONNECT;
                }
            }
            else
            {
                *state = RECV_STATE_EXCHANGE;
            }
        }
        break;
    case RECV_STATE_START_DISCONNECT:
        SetCloseLinkCallbackAndType(0);
        *state = RECV_STATE_WAIT_DISCONNECT;
        break;
    case RECV_STATE_WAIT_DISCONNECT:
        if (!gReceivedRemoteLinkPlayers)
        {
            *state = 0;
            return RECV_DISCONNECTED;
        }
        break;
    default:
        return RECV_ACTIVE;
    }

    return RECV_ACTIVE;
}

void CreateEReaderTask(void)
{
    struct EReaderTaskData *data;
    u8 taskId = CreateTask(Task_EReader, 0);
    data = (struct EReaderTaskData *)gTasks[taskId].data;
    data->state = 0;
    data->textState = 0;
    data->unused4 = 0;
    data->unused5 = 0;
    data->unused6 = 0;
    data->unused7 = 0;
    data->timer = 0;
    data->unused1 = 0;
    data->unused2 = 0;
    data->unused3 = 0;
    data->status = 0;
    data->unusedBuffer = AllocZeroed(CLIENT_MAX_MSG_SIZE);
}

static void ResetTimer(u16 *timer)
{
    *timer = 0;
}

static bool32 UpdateTimer(u16 *timer, u16 time)
{
    if (++(*timer) > time)
    {
        // Timer has finished
        *timer = 0;
        return TRUE;
    }

    return FALSE;
}

// States for Task_EReader
enum {
    ER_STATE_START,
    ER_STATE_INIT_LINK,
    ER_STATE_INIT_LINK_WAIT,
    ER_STATE_INIT_LINK_CHECK,
    ER_STATE_MSG_SELECT_CONNECT,
    ER_STATE_MSG_SELECT_CONNECT_WAIT,
    ER_STATE_TRY_LINK,
    ER_STATE_INCORRECT_LINK,
    ER_STATE_CONNECTING,
    ER_STATE_TRANSFER,
    ER_STATE_TRANSFER_END,
    ER_STATE_TRANSFER_SUCCESS,
    ER_STATE_LOAD_CARD_START,
    ER_STATE_LOAD_CARD,
    ER_STATE_WAIT_RECV_CARD,
    ER_STATE_VALIDATE_CARD,
    ER_STATE_WAIT_DISCONNECT,
    ER_STATE_SAVE,
    ER_STATE_SUCCESS_MSG,
    ER_STATE_SUCCESS_END,
    ER_STATE_LINK_ERROR,
    ER_STATE_LINK_ERROR_TRY_AGAIN,
    ER_STATE_SAVE_FAILED,
    ER_STATE_CANCELED_CARD_READ,
    ER_STATE_UNUSED_1,
    ER_STATE_UNUSED_2,
    ER_STATE_END,
};

static void Task_EReader(u8 taskId)
{
    struct EReaderTaskData *data = (struct EReaderTaskData *)gTasks[taskId].data;
    switch (data->state)
    {
    case ER_STATE_START:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_ReceiveMysteryGiftWithEReader))
            data->state = ER_STATE_INIT_LINK;
        break;
    case ER_STATE_INIT_LINK:
        OpenEReaderLink();
        ResetTimer(&data->timer);
        data->state = ER_STATE_INIT_LINK_WAIT;
        break;
    case ER_STATE_INIT_LINK_WAIT:
        if (UpdateTimer(&data->timer, 10))
            data->state = ER_STATE_INIT_LINK_CHECK;
        break;
    case ER_STATE_INIT_LINK_CHECK:
        if (!IsChildConnected())
        {
            CloseLink();
            data->state = ER_STATE_MSG_SELECT_CONNECT;
        }
        else
        {
            data->state = ER_STATE_LOAD_CARD;
        }
        break;
    case ER_STATE_MSG_SELECT_CONNECT:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_SelectConnectFromEReaderMenu))
        {
            MG_AddMessageTextPrinter(gJPText_SelectConnectWithGBA);
            ResetTimer(&data->timer);
            data->state = ER_STATE_MSG_SELECT_CONNECT_WAIT;
        }
        break;
    case ER_STATE_MSG_SELECT_CONNECT_WAIT:
        if (UpdateTimer(&data->timer, 90))
        {
            OpenEReaderLink();
            data->state = ER_STATE_TRY_LINK;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            ResetTimer(&data->timer);
            PlaySE(SE_SELECT);
            data->state = ER_STATE_CANCELED_CARD_READ;
        }
        break;
    case ER_STATE_TRY_LINK:
        if (JOY_NEW(B_BUTTON))
        {
            // Canceled
            PlaySE(SE_SELECT);
            CloseLink();
            ResetTimer(&data->timer);
            data->state = ER_STATE_CANCELED_CARD_READ;
        }
        else if (GetLinkPlayerCount_2() > 1)
        {
            ResetTimer(&data->timer);
            CloseLink();
            data->state = ER_STATE_INCORRECT_LINK;
        }
        else if (ValidateEReaderConnection())
        {
            // Successful connection
            PlaySE(SE_SELECT);
            CloseLink();
            ResetTimer(&data->timer);
            data->state = ER_STATE_CONNECTING;
        }
        else if (UpdateTimer(&data->timer, 10))
        {
            // Retry connection
            CloseLink();
            OpenEReaderLink();
            ResetTimer(&data->timer);
        }
        break;
    case ER_STATE_INCORRECT_LINK:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_LinkIsIncorrect))
            data->state = ER_STATE_MSG_SELECT_CONNECT;
        break;
    case ER_STATE_CONNECTING:
        MG_AddMessageTextPrinter(gJPText_Connecting);
        // XXX: This (u32 *) cast is discarding the const qualifier from gMultiBootProgram_EReader_Start
        EReader_Load(&gEReaderData, gMultiBootProgram_EReader_End - gMultiBootProgram_EReader_Start, (u32 *)gMultiBootProgram_EReader_Start);
        data->state = ER_STATE_TRANSFER;
        break;
    case ER_STATE_TRANSFER:
        data->status = EReader_Transfer(&gEReaderData);
        if (data->status != TRANSFER_ACTIVE)
            data->state = ER_STATE_TRANSFER_END;
        break;
    case ER_STATE_TRANSFER_END:
        EReader_Reset(&gEReaderData);
        if (data->status == TRANSFER_TIMEOUT)
        {
            data->state = ER_STATE_LINK_ERROR;
        }
        else if (data->status == TRANSFER_SUCCESS)
        {
            ResetTimer(&data->timer);
            MG_AddMessageTextPrinter(gJPText_PleaseWaitAMoment);
            data->state = ER_STATE_TRANSFER_SUCCESS;
        }
        else // TRANSFER_CANCELED
        {
            data->state = ER_STATE_START;
        }
        break;
    case ER_STATE_TRANSFER_SUCCESS:
        if (UpdateTimer(&data->timer, 840))
            data->state = ER_STATE_LOAD_CARD_START;
        break;
    case ER_STATE_LOAD_CARD_START:
        OpenEReaderLink();
        MG_AddMessageTextPrinter(gJPText_AllowEReaderToLoadCard);
        data->state = ER_STATE_LOAD_CARD;
        break;
    case ER_STATE_LOAD_CARD:
        switch (TryReceiveCard(&data->textState, &data->timer))
        {
        case RECV_ACTIVE:
            break;
        case RECV_SUCCESS:
            MG_AddMessageTextPrinter(gJPText_Connecting);
            data->state = ER_STATE_WAIT_RECV_CARD;
            break;
        case RECV_CANCELED:
            PlaySE(SE_SELECT);
            CloseLink();
            data->state = ER_STATE_CANCELED_CARD_READ;
            break;
        case RECV_TIMEOUT:
            CloseLink();
            data->state = ER_STATE_LINK_ERROR_TRY_AGAIN;
            break;
        case RECV_ERROR:
        case RECV_DISCONNECTED:
            CloseLink();
            data->state = ER_STATE_LINK_ERROR;
            break;
        }
        break;
    case ER_STATE_WAIT_RECV_CARD:
        if (HasLinkErrorOccurred())
        {
            CloseLink();
            data->state = ER_STATE_LINK_ERROR;
        }
        else if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            data->state = ER_STATE_VALIDATE_CARD;
        }
        break;
    case ER_STATE_VALIDATE_CARD:
        data->status = ValidateTrainerHillData((struct EReaderTrainerHillSet *)gDecompressionBuffer);
        SetCloseLinkCallbackAndType(data->status);
        data->state = ER_STATE_WAIT_DISCONNECT;
        break;
    case ER_STATE_WAIT_DISCONNECT:
        if (!gReceivedRemoteLinkPlayers)
        {
            if (data->status == TRUE) // Was data valid?
                data->state = ER_STATE_SAVE;
            else
                data->state = ER_STATE_LINK_ERROR;
        }
        break;
    case ER_STATE_SAVE:
        if (TryWriteTrainerHill((struct EReaderTrainerHillSet *)&gDecompressionBuffer))
        {
            MG_AddMessageTextPrinter(gJPText_ConnectionComplete);
            ResetTimer(&data->timer);
            data->state = ER_STATE_SUCCESS_MSG;
        }
        else
        {
            data->state = ER_STATE_SAVE_FAILED;
        }
        break;
    case ER_STATE_SUCCESS_MSG:
        if (UpdateTimer(&data->timer, 120))
        {
            MG_AddMessageTextPrinter(gJPText_NewTrainerHasComeToHoenn);
            PlayFanfare(MUS_OBTAIN_ITEM);
            data->state = ER_STATE_SUCCESS_END;
        }
        break;
    case ER_STATE_SUCCESS_END:
        if (IsFanfareTaskInactive() && (JOY_NEW(A_BUTTON | B_BUTTON)))
            data->state = ER_STATE_END;
        break;
    case ER_STATE_CANCELED_CARD_READ:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_CardReadingHasBeenHalted))
            data->state = ER_STATE_END;
        break;
    case ER_STATE_LINK_ERROR:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_ConnectionErrorCheckLink))
            data->state = ER_STATE_START;
        break;
    case ER_STATE_LINK_ERROR_TRY_AGAIN:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_ConnectionErrorTryAgain))
            data->state = ER_STATE_START;
        break;
    case ER_STATE_SAVE_FAILED:
        if (PrintMysteryGiftMenuMessage(&data->textState, gJPText_WriteErrorUnableToSaveData))
            data->state = ER_STATE_START;
        break;
    case ER_STATE_END:
        Free(data->unusedBuffer);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}
