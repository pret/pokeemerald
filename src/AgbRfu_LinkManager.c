#include "global.h"
#include "librfu.h"
#include "link_rfu.h"

#define RN_ACCEPT           0x01
#define RN_NAME_TIMER_CLEAR 0x02
#define RN_DISCONNECT       0x04

#define LINK_RECOVERY_OFF        0x00
#define LINK_RECOVERY_START      0x01
#define LINK_RECOVERY_EXE        0x02
#define LINK_RECOVERY_IMPOSSIBLE 0x04

#define FSP_ON    0x01
#define FSP_START 0x02

LINK_MANAGER lman;

static void rfu_LMAN_clearVariables(void);
static void rfu_LMAN_settingPCSWITCH(u32 rand);
static void rfu_LMAN_REQ_callback(u16 reqCommandId, u16 reqResult);
static void rfu_LMAN_MSC_callback(u16 reqCommandId);
static void rfu_LMAN_PARENT_checkRecvChildName(void);
static void rfu_LMAN_CHILD_checkSendChildName(void);
static void rfu_LMAN_CHILD_checkSendChildName2(void);
static void rfu_LMAN_CHILD_linkRecoveryProcess(void);
static u8 rfu_LMAN_CHILD_checkEnableParentCandidate(void);
static void rfu_LMAN_occureCallback(u8 msg, u8 param_count);
static void rfu_LMAN_disconnect(u8 bmDisconnectSlot);
static void rfu_LMAN_reflectCommunicationStatus(u8 bm_disconnectedSlot);
static void rfu_LMAN_checkNICommunicateStatus(void);
static void rfu_LMAN_managerChangeAgbClockMaster(void);

u32 rfu_LMAN_REQBN_softReset_and_checkID(void)
{
    u32 id = rfu_REQBN_softReset_and_checkID();
    if (id == RFU_ID)
        lman.RFU_powerOn_flag = 1;
    if (lman.state != LMAN_FORCED_STOP_AND_RFU_RESET && lman.state != LMAN_STATE_SOFT_RESET_AND_CHECK_ID)
    {
        lman.state = lman.next_state = LMAN_STATE_READY;
    }
    lman.pcswitch_flag = 0;
    lman.reserveDisconnectSlot_flag = 0;
    lman.acceptCount = 0;
    lman.acceptSlot_flag = 0;
    lman.parent_child = MODE_NEUTRAL;
    rfu_LMAN_managerChangeAgbClockMaster();
    return id;
}

void rfu_LMAN_REQ_sendData(u8 clockChangeFlag)
{
    if (gRfuLinkStatus->parentChild == MODE_CHILD)
    {
        if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON)
            clockChangeFlag = TRUE;
        else
            clockChangeFlag = FALSE;
    }
    else
        lman.parentAck_flag = 0;
    rfu_REQ_sendData(clockChangeFlag);
}

u8 rfu_LMAN_initializeManager(void (*LMAN_callback_p)(u8, u8), void (*MSC_callback_p)(u16))
{
    if (LMAN_callback_p == NULL)
    {
        return LMAN_ERROR_ILLEGAL_PARAMETER;
    }
    CpuFill16(0, &lman, sizeof(struct linkManagerTag));
    lman.parent_child = MODE_NEUTRAL;
    lman.LMAN_callback = LMAN_callback_p;
    lman.MSC_callback = MSC_callback_p;
    rfu_setMSCCallback(rfu_LMAN_MSC_callback);
    rfu_setREQCallback(rfu_LMAN_REQ_callback);
    return 0;
}

static void rfu_LMAN_endManager(void)
{
    CpuFill16(0, &lman, sizeof(struct linkManagerTag) - 8);
    lman.parent_child = MODE_NEUTRAL;
}

void rfu_LMAN_initializeRFU(INIT_PARAM *init_parameters)
{
    rfu_LMAN_clearVariables();
    lman.state = LMAN_STATE_SOFT_RESET_AND_CHECK_ID;
    lman.next_state = LMAN_STATE_RESET;
    lman.init_param = init_parameters;
    lman.linkRecovery_enable = init_parameters->linkRecovery_enable;
    lman.linkRecoveryTimer.count_max = init_parameters->linkRecovery_period;
    lman.NI_failCounter_limit = init_parameters->NI_failCounter_limit;
    if (init_parameters->fastSearchParent_flag)
    {
        lman.fastSearchParent_flag = FSP_ON;
    }
}

static void rfu_LMAN_clearVariables(void)
{
    u8 i;

    lman.state = lman.next_state = LMAN_STATE_READY;
    lman.parent_child = MODE_NEUTRAL;
    lman.pcswitch_flag = 0;
    lman.child_slot = 0;
    lman.connectSlot_flag_old = 0;
    lman.nameAcceptTimer.active = 0;
    lman.linkRecoveryTimer.active = 0;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        lman.nameAcceptTimer.count[i] = 0;
        lman.linkRecoveryTimer.count[i] = 0;
    }
}

void rfu_LMAN_powerDownRFU(void)
{
    lman.state = LMAN_STATE_STOP_MODE;
}

u8 rfu_LMAN_establishConnection(u8 parent_child, u16 connect_period, u16 name_accept_period, u16 *acceptable_serialNo_list)
{
    u8 i;
    u16 *serial_list;

    if (lman.state != LMAN_STATE_READY && (lman.state != LMAN_STATE_WAIT_RECV_CHILD_NAME || parent_child != MODE_PARENT))
    {
        lman.param[0] = 1;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_MANAGER_BUSY;
    }
    if (rfu_getMasterSlave() == AGB_CLK_SLAVE)
    {
        lman.param[0] = 2;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_AGB_CLK_SLAVE;
    }
    for (i = 0, serial_list = acceptable_serialNo_list; i < 16; i++)
    {
        if (*serial_list++ == 0xFFFF)
        {
            break;
        }
    }
    if (i == 16)
    {
        lman.param[0] = 4;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_ILLEGAL_PARAMETER;
    }
    if (parent_child > MODE_PARENT)
    {
        lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
        parent_child = MODE_PARENT;
        connect_period = 0;
    }
    else
    {
        lman.pcswitch_flag = 0;
    }
    if (parent_child != MODE_CHILD)
    {
        lman.state = LMAN_STATE_START_SEARCH_CHILD;
    }
    else
    {
        lman.state = LMAN_STATE_START_SEARCH_PARENT;
        if (lman.fastSearchParent_flag)
        {
            lman.fastSearchParent_flag = FSP_START;
        }
    }
    lman.parent_child = parent_child;
    lman.connect_period = connect_period;
    lman.nameAcceptTimer.count_max = name_accept_period;
    lman.acceptable_serialNo_list = acceptable_serialNo_list;
    return 0;
}

u8 rfu_LMAN_CHILD_connectParent(u16 parentId, u16 connect_period)
{
    u8 i;

    if (lman.state != LMAN_STATE_READY && (lman.state < 9 || lman.state > 11))
    {
        lman.param[0] = 1;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_MANAGER_BUSY;
    }
    if (rfu_getMasterSlave() == AGB_CLK_SLAVE)
    {
        lman.param[0] = 2;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_AGB_CLK_SLAVE;
    }
    for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
    {
        if (gRfuLinkStatus->partner[i].id == parentId)
        {
            break;
        }
    }
    if (gRfuLinkStatus->findParentCount == 0 || i == gRfuLinkStatus->findParentCount)
    {
        lman.param[0] = 3;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_PID_NOT_FOUND;
    }
    if (lman.state == LMAN_STATE_READY || lman.state == LMAN_STATE_START_SEARCH_PARENT)
    {
        lman.state = LMAN_STATE_START_CONNECT_PARENT;
        lman.next_state = LMAN_STATE_POLL_CONNECT_PARENT;
    }
    else
    {
        lman.state = LMAN_STATE_END_SEARCH_PARENT;
        lman.next_state = LMAN_STATE_START_CONNECT_PARENT;
    }
    lman.work = parentId;
    lman.connect_period = connect_period;
    if (lman.pcswitch_flag != 0)
    {
        lman.pcswitch_flag = PCSWITCH_CP;
    }
    return 0;
}

static void rfu_LMAN_PARENT_stopWaitLinkRecoveryAndDisconnect(u8 bm_targetSlot)
{
    u8 i;

    if ((bm_targetSlot & lman.linkRecoveryTimer.active) == 0)
        return;
    lman.linkRecoveryTimer.active &= ~bm_targetSlot;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((bm_targetSlot >> i) & 1)
        {
            lman.linkRecoveryTimer.count[i] = 0;
        }
    }
    i = gRfuLinkStatus->linkLossSlotFlag & bm_targetSlot;
    if (i)
    {
        rfu_LMAN_disconnect(i);
    }
    lman.param[0] = i;
    rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, i);
}

void rfu_LMAN_stopManager(u8 forced_stop_and_RFU_reset_flag)
{
    u8 msg = 0;
    lman.pcswitch_flag = 0;
    if (forced_stop_and_RFU_reset_flag)
    {
        rfu_LMAN_clearVariables();
        lman.state = LMAN_FORCED_STOP_AND_RFU_RESET;
        return;
    }
    switch (lman.state)
    {
    case LMAN_STATE_START_SEARCH_CHILD:
        lman.state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
        lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED;
        break;
    case LMAN_STATE_POLL_SEARCH_CHILD:
        lman.state = LMAN_STATE_END_SEARCH_CHILD;
        lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
        break;
    case LMAN_STATE_END_SEARCH_CHILD:
        lman.state = LMAN_STATE_END_SEARCH_CHILD;
        lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
        break;
    case LMAN_STATE_WAIT_RECV_CHILD_NAME:
        break;
    case LMAN_STATE_START_SEARCH_PARENT:
        lman.state = lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED;
        break;
    case LMAN_STATE_POLL_SEARCH_PARENT:
        lman.state = LMAN_STATE_END_SEARCH_PARENT;
        lman.next_state = LMAN_STATE_READY;
        break;
    case LMAN_STATE_END_SEARCH_PARENT:
        lman.state = LMAN_STATE_END_SEARCH_PARENT;
        lman.next_state = LMAN_STATE_READY;
        break;
    case LMAN_STATE_START_CONNECT_PARENT:
        lman.state = lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_CONNECT_PARENT_FAILED;
        break;
    case LMAN_STATE_POLL_CONNECT_PARENT:
        lman.state = LMAN_STATE_END_CONNECT_PARENT;
        break;
    case LMAN_STATE_END_CONNECT_PARENT:
        lman.state = LMAN_STATE_END_CONNECT_PARENT;
        break;
    case LMAN_STATE_SEND_CHILD_NAME:
        break;
    case LMAN_STATE_START_LINK_RECOVERY:
        lman.state = lman.state_bak[0];
        lman.next_state = lman.state_bak[1];
        rfu_LMAN_disconnect(gRfuLinkStatus->linkLossSlotFlag);
        lman.param[0] = gRfuLinkStatus->linkLossSlotFlag;
        rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
        return;
    case LMAN_STATE_POLL_LINK_RECOVERY:
        lman.state = LMAN_STATE_END_LINK_RECOVERY;
        break;
    case LMAN_STATE_END_LINK_RECOVERY:
        lman.state = LMAN_STATE_END_LINK_RECOVERY;
        break;
    default:
        lman.state = lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_MANAGER_STOPPED;
        break;
    }
    if (lman.state == LMAN_STATE_READY)
    {
        rfu_LMAN_occureCallback(msg, 0);
    }
}

static bool8 rfu_LMAN_linkWatcher(u16 REQ_commandID)
{
    u8 i;
    u8 bm_linkLossSlot;
    u8 reason;
    u8 bm_linkRecoverySlot;
    u8 bm_disconnectSlot;

    bool8 disconnect_occure_flag = FALSE;
    rfu_REQBN_watchLink(REQ_commandID, &bm_linkLossSlot, &reason, &bm_linkRecoverySlot);
    if (bm_linkLossSlot)
    {
        lman.param[0] = bm_linkLossSlot;
        lman.param[1] = reason;
        if (lman.linkRecovery_enable)
        {
            lman.linkRecovery_start_flag = LINK_RECOVERY_START;
            if (lman.parent_child == MODE_CHILD && reason == REASON_DISCONNECTED)
            {
                lman.linkRecovery_start_flag = LINK_RECOVERY_IMPOSSIBLE;
            }
            if (lman.linkRecovery_start_flag == LINK_RECOVERY_START)
            {
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((bm_linkLossSlot >> i) & 1)
                    {
                        lman.linkRecoveryTimer.active |= (1 << i);
                        lman.linkRecoveryTimer.count[i] = lman.linkRecoveryTimer.count_max;
                    }
                }
                rfu_LMAN_occureCallback(LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY, 1);
            }
            else
            {
                lman.linkRecovery_start_flag = 0;
                rfu_LMAN_disconnect(bm_linkLossSlot);
                disconnect_occure_flag = TRUE;
                rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
            }
        }
        else
        {
            rfu_LMAN_disconnect(bm_linkLossSlot);
            disconnect_occure_flag = TRUE;
            rfu_LMAN_occureCallback(LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED, 2);
        }
        rfu_LMAN_managerChangeAgbClockMaster();
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        if (bm_linkRecoverySlot)
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((lman.linkRecoveryTimer.active >> i) & 1 && (bm_linkRecoverySlot >> i) & 1)
                {
                    lman.linkRecoveryTimer.count[i] = 0;
                }
            }
            lman.linkRecoveryTimer.active &= ~bm_linkRecoverySlot;
            lman.param[0] = bm_linkRecoverySlot;
            rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_SUCCESSED, 1);
        }
        if (lman.linkRecoveryTimer.active)
        {
            bm_disconnectSlot = 0;
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((lman.linkRecoveryTimer.active >> i) & 1 && lman.linkRecoveryTimer.count[i] && --lman.linkRecoveryTimer.count[i] == 0)
                {
                    lman.linkRecoveryTimer.active &= ~(1 << i);
                    bm_disconnectSlot |= (1 << i);
                }
            }
            if (bm_disconnectSlot)
            {
                rfu_LMAN_disconnect(bm_disconnectSlot);
                disconnect_occure_flag = TRUE;
                lman.param[0] = bm_disconnectSlot;
                rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
            }
        }
        if (!lman.linkRecoveryTimer.active)
        {
            lman.linkRecovery_start_flag = 0;
        }
    }
    return disconnect_occure_flag;
}

void rfu_LMAN_syncVBlank(void)
{
    if (rfu_syncVBlank())
    {
        rfu_LMAN_occureCallback(LMAN_MSG_WATCH_DOG_TIMER_ERROR, 0);
        rfu_LMAN_managerChangeAgbClockMaster();
    }
}

void rfu_LMAN_manager_entity(u32 rand)
{
    u8 msg;

    if (lman.LMAN_callback == NULL && lman.state != LMAN_STATE_READY)
    {
        lman.state = LMAN_STATE_READY;
        return;
    }
    if (lman.pcswitch_flag)
    {
        rfu_LMAN_settingPCSWITCH(rand);
    }
    while (1)
    {
        if (lman.state != LMAN_STATE_READY)
        {
            rfu_waitREQComplete();
            lman.active = 1;
            switch (lman.state)
            {
            case LMAN_FORCED_STOP_AND_RFU_RESET:
                if (rfu_LMAN_REQBN_softReset_and_checkID() == RFU_ID)
                {
                    msg=LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET;
                }
                else
                {
                    msg=LMAN_MSG_RFU_FATAL_ERROR;
                }
                lman.state = lman.next_state = LMAN_STATE_READY;
                rfu_LMAN_occureCallback(msg, 0);
                break;
            case LMAN_STATE_SOFT_RESET_AND_CHECK_ID:
                if (rfu_LMAN_REQBN_softReset_and_checkID() == RFU_ID)
                {
                    lman.state = lman.next_state;
                    lman.next_state = LMAN_STATE_CONFIG_SYSTEM;
                }
                else
                {
                    lman.state = lman.next_state = LMAN_STATE_READY;
                    rfu_LMAN_occureCallback(LMAN_MSG_RFU_FATAL_ERROR, 0);
                }
                break;
            case LMAN_STATE_RESET:
                rfu_REQ_reset();
                break;
            case LMAN_STATE_CONFIG_SYSTEM:
                rfu_REQ_configSystem(lman.init_param->availSlot_flag, lman.init_param->maxMFrame, lman.init_param->MC_TimerCount);
                break;
            case LMAN_STATE_CONFIG_GAME_DATA:
                rfu_REQ_configGameData(lman.init_param->mboot_flag, lman.init_param->serialNo, (const u8 *)lman.init_param->gameName, lman.init_param->userName);
                break;
            case LMAN_STATE_START_SEARCH_CHILD:
                rfu_REQ_startSearchChild();
                break;
            case LMAN_STATE_POLL_SEARCH_CHILD:
                rfu_REQ_pollSearchChild();
                break;
            case LMAN_STATE_END_SEARCH_CHILD:
                rfu_REQ_endSearchChild();
                break;
            case LMAN_STATE_WAIT_RECV_CHILD_NAME:
                break;
            case LMAN_STATE_START_SEARCH_PARENT:
                rfu_REQ_startSearchParent();
                break;
            case LMAN_STATE_POLL_SEARCH_PARENT:
                rfu_REQ_pollSearchParent();
                break;
            case LMAN_STATE_END_SEARCH_PARENT:
                rfu_REQ_endSearchParent();
                break;
            case LMAN_STATE_START_CONNECT_PARENT:
                rfu_REQ_startConnectParent(lman.work);
                break;
            case LMAN_STATE_POLL_CONNECT_PARENT:
                rfu_REQ_pollConnectParent();
                break;
            case LMAN_STATE_END_CONNECT_PARENT:
                rfu_REQ_endConnectParent();
                break;
            case LMAN_STATE_SEND_CHILD_NAME:
                break;
            case LMAN_STATE_START_LINK_RECOVERY:
                rfu_REQ_CHILD_startConnectRecovery(gRfuLinkStatus->linkLossSlotFlag);
                break;
            case LMAN_STATE_POLL_LINK_RECOVERY:
                rfu_REQ_CHILD_pollConnectRecovery();
                break;
            case LMAN_STATE_END_LINK_RECOVERY:
                rfu_REQ_CHILD_endConnectRecovery();
                break;
            case LMAN_STATE_MS_CHANGE:
                rfu_REQ_changeMasterSlave();
                break;
            case LMAN_STATE_WAIT_CLOCK_MASTER:
                break;
            case LMAN_STATE_STOP_MODE:
                rfu_REQ_stopMode();
                break;
            case LMAN_STATE_BACK_STATE:
                break;
            default:
                break;
            }
            rfu_waitREQComplete();
            lman.active = 0;
        }
        if (lman.state == LMAN_STATE_END_LINK_RECOVERY || lman.state == LMAN_STATE_MS_CHANGE)
            ;
        else
            break;
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        if (rfu_LMAN_linkWatcher(0))
            return;
    }
    rfu_LMAN_PARENT_checkRecvChildName();
    rfu_LMAN_CHILD_checkSendChildName();
    rfu_LMAN_CHILD_linkRecoveryProcess();
    rfu_LMAN_checkNICommunicateStatus();
}

static void rfu_LMAN_settingPCSWITCH(u32 rand)
{
    if (lman.pcswitch_flag == PCSWITCH_3RD_SC_START)
    {
        lman.parent_child = MODE_PARENT;
        lman.state = LMAN_STATE_START_SEARCH_CHILD;
        lman.connect_period = lman.pcswitch_period_bak;
        if (lman.connect_period)
        {
            lman.pcswitch_flag = PCSWITCH_3RD_SC;
        }
        else
        {
            lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
        }
    }
    if (lman.pcswitch_flag == PCSWITCH_1ST_SC_START)
    {
        lman.parent_child = MODE_PARENT;
        lman.state = LMAN_STATE_START_SEARCH_CHILD;
        lman.connect_period = rand % 140;
        lman.pcswitch_period_bak = 140 - lman.connect_period;
        if (lman.connect_period)
        {
            lman.pcswitch_flag = PCSWITCH_1ST_SC;
        }
        else
        {
            lman.pcswitch_flag = PCSWITCH_2ND_SP_START;
        }
    }
    if (lman.pcswitch_flag == PCSWITCH_2ND_SP_START)
    {
        lman.parent_child = MODE_CHILD;
        lman.connect_period = PCSWITCH_SP_PERIOD;
        lman.pcswitch_flag = PCSWITCH_2ND_SP;
        lman.state = LMAN_STATE_START_SEARCH_PARENT;
    }
}

static void rfu_LMAN_REQ_callback(u16 reqCommandId, u16 reqResult)
{
    u8 status;
    u8 *stwiRecvBuffer;
    u8 i;

    if (lman.active != 0)
    {
        lman.active = 0;
        switch (reqCommandId)
        {
        case ID_RESET_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state;
                lman.next_state = LMAN_STATE_CONFIG_GAME_DATA;
            }
            break;
        case ID_SYSTEM_CONFIG_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state;
                lman.next_state = LMAN_STATE_READY;
            }
            break;
        case ID_GAME_CONFIG_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state = LMAN_STATE_READY;
                rfu_LMAN_occureCallback(LMAN_MSG_INITIALIZE_COMPLETED, 0);
            }
            break;
        case ID_SC_START_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state = LMAN_STATE_POLL_SEARCH_CHILD;
            }
            break;
        case ID_SC_POLL_REQ:
            if (lman.connect_period && --lman.connect_period == 0)
            {
                lman.state = LMAN_STATE_END_SEARCH_CHILD;
                lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
            }
            break;
        case ID_SC_END_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state;
                lman.next_state = LMAN_STATE_READY;
                if (lman.pcswitch_flag == 0)
                {
                    rfu_LMAN_occureCallback(LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED, 0);
                }
            }
            break;
        case ID_SP_START_REQ:
            if (reqResult == 0)
            {
                if (lman.fastSearchParent_flag == FSP_ON)
                {
                    if (lman.connect_period > 1)
                    {
                        lman.connect_period--;
                    }
                }
                lman.state = lman.next_state = LMAN_STATE_POLL_SEARCH_PARENT;
            }
            break;
        case ID_SP_POLL_REQ:
            if (reqResult == 0)
            {
                status = rfu_LMAN_CHILD_checkEnableParentCandidate();
                lman.param[0] = status;
                if (status)
                {
                    rfu_LMAN_occureCallback(LMAN_MSG_PARENT_FOUND, 1);
                }
                if (lman.fastSearchParent_flag && lman.connect_period != 1 && gRfuLinkStatus->findParentCount == RFU_CHILD_MAX)
                {
                    rfu_REQ_endSearchParent();
                    rfu_waitREQComplete();
                    lman.state = LMAN_STATE_START_SEARCH_PARENT;
                    lman.fastSearchParent_flag = FSP_ON;
                }
            }
            if (lman.connect_period && --lman.connect_period == 0)
            {
                lman.state = LMAN_STATE_END_SEARCH_PARENT;
                lman.next_state = LMAN_STATE_READY;
            }
            break;
        case ID_SP_END_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state;
                if (lman.pcswitch_flag == 0)
                {
                    if (lman.state == LMAN_STATE_READY)
                    {
                        rfu_LMAN_occureCallback(LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED, 0);
                    }
                }
                else if (lman.pcswitch_flag != PCSWITCH_CP)
                {
                    lman.state = LMAN_STATE_START_SEARCH_CHILD;
                    lman.pcswitch_flag = PCSWITCH_3RD_SC_START;
                }
            }
            break;
        case ID_CP_START_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state = LMAN_STATE_POLL_CONNECT_PARENT;
            }
            break;
        case ID_CP_POLL_REQ:
            if (reqResult == 0 && !rfu_getConnectParentStatus(&status, &lman.child_slot) && !status)
            {
                lman.state = LMAN_STATE_END_CONNECT_PARENT;
            }
            if (lman.connect_period && --lman.connect_period == 0)
            {
                lman.state = LMAN_STATE_END_CONNECT_PARENT;
            }
            break;
        case ID_CP_END_REQ:
            if (reqResult == 0 && !rfu_getConnectParentStatus(&status, &lman.child_slot))
            {
                if (!status)
                {
                    lman.state = LMAN_STATE_MS_CHANGE;
                    lman.next_state = LMAN_STATE_SEND_CHILD_NAME;
                    lman.work = 0x22;
                    lman.param[0] = lman.child_slot;
                }
                else
                {
                    lman.state = lman.next_state = LMAN_STATE_READY;
                    lman.work = 0x23;
                    lman.param[0] = status;
                    if (lman.pcswitch_flag)
                    {
                        lman.pcswitch_flag = PCSWITCH_2ND_SP_START;
                        lman.state = LMAN_STATE_START_SEARCH_PARENT;
                    }
                }
                rfu_LMAN_occureCallback(lman.work, 0x01);
                lman.work = 0;
            }
            break;
        case ID_CPR_START_REQ:
            if (reqResult == 0)
            {
                lman.param[0] = gRfuLinkStatus->linkLossSlotFlag;
                lman.state = lman.next_state = LMAN_STATE_POLL_LINK_RECOVERY;
                for (lman.child_slot = 0; lman.child_slot < RFU_CHILD_MAX; lman.child_slot++)
                {
                    if ((gRfuLinkStatus->linkLossSlotFlag >> lman.child_slot) & 1)
                    {
                        break;
                    }
                }
            }
            break;
        case ID_CPR_POLL_REQ:
            if (reqResult == 0 && !rfu_CHILD_getConnectRecoveryStatus(&status) && status < 2)
            {
                lman.state = LMAN_STATE_END_LINK_RECOVERY;
            }
            if (lman.linkRecoveryTimer.count[lman.child_slot] && --lman.linkRecoveryTimer.count[lman.child_slot] == 0)
            {
                lman.state = LMAN_STATE_END_LINK_RECOVERY;
            }
            break;
        case ID_CPR_END_REQ:
            if (reqResult == 0 && !rfu_CHILD_getConnectRecoveryStatus(&status))
            {
                if (!status)
                {
                    lman.state = LMAN_STATE_MS_CHANGE;
                    lman.next_state = LMAN_STATE_BACK_STATE;
                    lman.work = 0x32;
                }
                else
                {
                    lman.state = lman.next_state = LMAN_STATE_READY;
                    rfu_LMAN_disconnect(gRfuLinkStatus->linkLossSlotFlag);
                    lman.work = 0x33;
                }
                lman.linkRecoveryTimer.count[lman.child_slot] = 0;
                lman.linkRecoveryTimer.active = 0;
                lman.linkRecovery_start_flag = 0;
                rfu_LMAN_occureCallback(lman.work, 0x01);
                lman.work = 0;
            }
            break;
        case ID_MS_CHANGE_REQ:
            if (reqResult == 0)
            {
                if (lman.next_state == LMAN_STATE_BACK_STATE)
                {
                    lman.state = lman.state_bak[0];
                    lman.next_state = lman.state_bak[1];
                    lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_ON;
                    rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE, 0);
                }
                else if (lman.next_state == LMAN_STATE_SEND_CHILD_NAME)
                {
                    lman.state = lman.next_state;
                    lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_ON;
                    rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE, 0);
                    lman.nameAcceptTimer.active |= 1 << lman.child_slot;
                    lman.nameAcceptTimer.count[lman.child_slot] = lman.nameAcceptTimer.count_max;
                    rfu_clearSlot(TYPE_NI_SEND, lman.child_slot);
                    status = rfu_NI_CHILD_setSendGameName(lman.child_slot, 0x0e);
                    if (status)
                    {
                        lman.state = lman.next_state = LMAN_STATE_READY;
                        rfu_LMAN_managerChangeAgbClockMaster();
                        rfu_LMAN_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
                        lman.param[0] = status;
                        rfu_LMAN_occureCallback(LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED, 1);
                    }
                }
            }
            break;
        case ID_STOP_MODE_REQ:
            if (reqResult == 0)
            {
                lman.state = lman.next_state = LMAN_STATE_READY;
                rfu_LMAN_occureCallback(LMAN_MSG_RFU_POWER_DOWN, 0);
            }
            break;
        }
        lman.active = 1;
    }
    else if (reqResult == 3 && lman.msc_exe_flag && (reqCommandId == ID_DATA_TX_REQ || reqCommandId == ID_DATA_RX_REQ || reqCommandId == ID_MS_CHANGE_REQ))
    {
        rfu_REQ_RFUStatus();
        rfu_waitREQComplete();
        rfu_getRFUStatus(&status);
        if (status == 0 && gRfuLinkStatus->parentChild == MODE_CHILD)
        {
            stwiRecvBuffer = rfu_getSTWIRecvBuffer() + 4;
            *stwiRecvBuffer++ = gRfuLinkStatus->connSlotFlag;
            *stwiRecvBuffer = REASON_LINK_LOSS;
            rfu_LMAN_linkWatcher(ID_DISCONNECTED_AND_CHANGE_REQ);
            reqResult = 0;
        }
    }
    switch (reqCommandId)
    {
    case ID_DISCONNECT_REQ:
        if (reqResult == 0)
        {
            lman.param[0] = *(rfu_getSTWIRecvBuffer() + 8);
            rfu_LMAN_reflectCommunicationStatus(lman.param[0]);
            if (lman.linkRecoveryTimer.active)
            {
                lman.linkRecoveryTimer.active &= ~lman.param[0];
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((lman.param[0] >> i) & 1)
                    {
                        lman.linkRecoveryTimer.count[i] = 0;
                    }
                }
                if (lman.parent_child == MODE_CHILD)
                {
                    lman.state = lman.next_state = LMAN_STATE_READY;
                }
            }
            status = lman.acceptSlot_flag & lman.param[0];
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((status >> i) & 1 && lman.acceptCount)
                {
                    lman.acceptCount--;
                }
            }
            lman.acceptSlot_flag &= ~lman.param[0];
            if (lman.pcswitch_flag)
            {
                if (gRfuLinkStatus->parentChild == MODE_NEUTRAL)
                {
                    if (lman.pcswitch_flag == PCSWITCH_SC_LOCK)
                    {
                        lman.connect_period = lman.pcswitch_period_bak;
                        lman.pcswitch_flag = PCSWITCH_3RD_SC;
                        lman.state = LMAN_STATE_POLL_SEARCH_CHILD;
                    }
                    else if (lman.state != LMAN_STATE_POLL_SEARCH_CHILD && lman.state != LMAN_STATE_END_SEARCH_CHILD)
                    {
                        lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
                        lman.state = LMAN_STATE_START_SEARCH_CHILD;
                    }
                }
            }
            if (gRfuLinkStatus->parentChild == MODE_NEUTRAL)
            {
                if (lman.state == LMAN_STATE_READY)
                {
                    lman.parent_child = MODE_NEUTRAL;
                }
            }
            if (lman.active == 0)
            {
                rfu_LMAN_occureCallback(LMAN_MSG_LINK_DISCONNECTED_BY_USER, 1);
            }
        }
        break;
    case ID_DATA_RX_REQ:
        rfu_LMAN_CHILD_checkSendChildName2();
        if (gRfuLinkStatus->parentChild != MODE_NEUTRAL)
        {
            rfu_LMAN_occureCallback(LMAN_MSG_RECV_DATA_REQ_COMPLETED, 0);
        }
        break;
    case ID_RESET_REQ:
    case ID_STOP_MODE_REQ:
        if (reqResult == 0)
        {
            lman.reserveDisconnectSlot_flag = 0;
            lman.acceptCount = 0;
            lman.acceptSlot_flag = 0;
            lman.parent_child = MODE_NEUTRAL;
            rfu_LMAN_managerChangeAgbClockMaster();
            if (reqCommandId == ID_STOP_MODE_REQ)
            {
                rfu_LMAN_endManager();
            }
        }
        break;
    }
    if (reqResult != 0)
    {
        if (reqCommandId == ID_SP_START_REQ && reqResult != 0 && lman.pcswitch_flag == PCSWITCH_2ND_SP)
        {
            gRfuLinkStatus->parentChild = MODE_PARENT;
            gRfuLinkStatus->connSlotFlag = 0xF;
            rfu_LMAN_disconnect(15);
            rfu_waitREQComplete();
            return;
        }
        else
        {
            lman.param[0] = reqCommandId;
            lman.param[1] = reqResult;
            if (lman.active)
            {
                lman.state = lman.next_state = LMAN_STATE_READY;
            }
            rfu_LMAN_occureCallback(LMAN_MSG_REQ_API_ERROR, 2);
            rfu_LMAN_managerChangeAgbClockMaster();
        }
    }
    if (reqCommandId == ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ)
    {
        rfu_LMAN_occureCallback(LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA, 0);
        rfu_LMAN_managerChangeAgbClockMaster();
    }
}

static void rfu_LMAN_MSC_callback(u16 reqCommandId)
{
    u8 active_bak;
    u8 thisAck_flag;

    active_bak = lman.active;
    lman.active = 0;
    lman.msc_exe_flag = 1;
    if (gRfuLinkStatus->parentChild == MODE_CHILD)
    {
        rfu_LMAN_linkWatcher(reqCommandId);
        if (lman.childClockSlave_flag != RFU_CHILD_CLOCK_SLAVE_ON)
        {
            rfu_LMAN_managerChangeAgbClockMaster();
            lman.msc_exe_flag = 0;
            lman.active = active_bak;
            return;
        }
    }
    else
    {
        if (!rfu_UNI_PARENT_getDRAC_ACK(&thisAck_flag))
        {
            lman.parentAck_flag |= thisAck_flag;
        }
    }
    if (lman.MSC_callback != NULL)
    {
        lman.MSC_callback(reqCommandId);
        rfu_waitREQComplete();
        if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_OFF_REQ)
        {
            rfu_LMAN_managerChangeAgbClockMaster();
        }
    }
    lman.msc_exe_flag = 0;
    lman.active = active_bak;
}

static void rfu_LMAN_PARENT_checkRecvChildName(void)
{
    u8 newSlot;
    u8 newAcceptSlot;
    u8 i;
    u8 flags;
    u8 tgtSlot;
    const u16 *ptr;

    if (lman.state == LMAN_STATE_START_SEARCH_CHILD || lman.state == LMAN_STATE_POLL_SEARCH_CHILD || lman.state == LMAN_STATE_END_SEARCH_CHILD || lman.state == LMAN_STATE_WAIT_RECV_CHILD_NAME)
    {
        newSlot = ((gRfuLinkStatus->connSlotFlag ^ lman.connectSlot_flag_old) & gRfuLinkStatus->connSlotFlag) & ~gRfuLinkStatus->getNameFlag;
        lman.connectSlot_flag_old = gRfuLinkStatus->connSlotFlag;
        if (newSlot)
        {
            lman.param[0] = newSlot;
            rfu_LMAN_occureCallback(LMAN_MSG_NEW_CHILD_CONNECT_DETECTED, 1);
        }
        newAcceptSlot = 0x00;
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            tgtSlot = 1 << i;
            flags = 0x00;
            if (newSlot & tgtSlot)
            {
                lman.nameAcceptTimer.count[i] = lman.nameAcceptTimer.count_max;
                lman.nameAcceptTimer.active |= tgtSlot;
            }
            else if (lman.nameAcceptTimer.active & tgtSlot)
            {
                if (gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS)
                {
                    if (gRfuSlotStatusNI[i]->recv.dataType == 1)
                    {
                        flags = RN_NAME_TIMER_CLEAR;
                        for (ptr = lman.acceptable_serialNo_list; *ptr != 0xFFFF; ptr++)
                        {
                            if (gRfuLinkStatus->partner[i].serialNo == *ptr)
                            {
                                lman.acceptSlot_flag |= tgtSlot;
                                lman.acceptCount++;
                                newAcceptSlot |= tgtSlot;
                                flags |= RN_ACCEPT;
                                break;
                            }
                        }
                        if (!(flags & RN_ACCEPT))
                        {
                            flags |= RN_DISCONNECT;
                        }
                    }
                }
                else if (--lman.nameAcceptTimer.count[i] == 0)
                {
                    flags = RN_NAME_TIMER_CLEAR | RN_DISCONNECT;
                }
                if (flags & RN_NAME_TIMER_CLEAR)
                {
                    lman.nameAcceptTimer.active &= ~tgtSlot;
                    lman.nameAcceptTimer.count[i] = 0;
                    rfu_clearSlot(TYPE_NI_RECV, i);
                }
                if (flags & RN_DISCONNECT)
                {
                    lman.reserveDisconnectSlot_flag |= tgtSlot;
                }
            }
        }
        if (newAcceptSlot)
        {
            lman.param[0] = newAcceptSlot;
            rfu_LMAN_occureCallback(LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED, 1);
        }
        if (lman.reserveDisconnectSlot_flag)
        {
            flags = 1;
            if (gRfuLinkStatus->sendSlotUNIFlag)
            {
                if (((lman.parentAck_flag & lman.acceptSlot_flag) != lman.acceptSlot_flag))
                {
                    flags = 0;
                }
            }
            if (flags)
            {
                rfu_LMAN_disconnect(lman.reserveDisconnectSlot_flag);
                lman.param[0] = lman.reserveDisconnectSlot_flag;
                lman.reserveDisconnectSlot_flag = 0;
                rfu_LMAN_occureCallback(LMAN_MSG_NEW_CHILD_CONNECT_REJECTED, 1);
            }
        }
        if (lman.nameAcceptTimer.active == 0 && lman.state == LMAN_STATE_WAIT_RECV_CHILD_NAME)
        {
            if (lman.pcswitch_flag == 0)
            {
                lman.state = lman.next_state = LMAN_STATE_READY;
                rfu_LMAN_occureCallback(LMAN_MSG_END_WAIT_CHILD_NAME, 0);
            }
            else
            {
                if (lman.pcswitch_flag == PCSWITCH_1ST_SC)
                {
                    lman.pcswitch_flag = PCSWITCH_2ND_SP_START;
                    lman.state = LMAN_STATE_START_SEARCH_PARENT;
                }
                else
                {
                    lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
                    lman.state = LMAN_STATE_START_SEARCH_CHILD;
                }
                if (lman.acceptSlot_flag)
                {
                    lman.connect_period = 0;
                    lman.pcswitch_flag = PCSWITCH_SC_LOCK;
                    lman.state = LMAN_STATE_START_SEARCH_CHILD;
                }
            }
        }
    }
}

static void rfu_LMAN_CHILD_checkSendChildName(void)
{
    u16 imeBak = REG_IME;
    REG_IME = 0;
    if (lman.state == LMAN_STATE_SEND_CHILD_NAME)
    {
        if (--lman.nameAcceptTimer.count[lman.child_slot] == 0 || gRfuSlotStatusNI[lman.child_slot]->send.state == SLOT_STATE_SEND_FAILED)
        {
            rfu_LMAN_requestChangeAgbClockMaster();
            lman.state = LMAN_STATE_WAIT_CHANGE_CLOCK_MASTER;
            rfu_clearSlot(TYPE_NI_SEND, lman.child_slot);
            lman.nameAcceptTimer.active &= ~(1 << lman.child_slot);
            lman.nameAcceptTimer.count[lman.child_slot] = 0;
        }
    }
    REG_IME = imeBak;
    if (lman.state == LMAN_STATE_WAIT_CHANGE_CLOCK_MASTER)
    {
        if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON)
        {
            rfu_LMAN_requestChangeAgbClockMaster();
        }
        if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_OFF)
        {
            lman.state = lman.next_state = LMAN_STATE_READY;
            rfu_LMAN_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
            lman.param[0] = 0;
            rfu_LMAN_occureCallback(LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED, 1);
        }
    }
}

static void rfu_LMAN_CHILD_checkSendChildName2(void)
{
    if (lman.state == LMAN_STATE_SEND_CHILD_NAME && gRfuSlotStatusNI[lman.child_slot]->send.state == SLOT_STATE_SEND_SUCCESS)
    {
        lman.state = lman.next_state = LMAN_STATE_READY;
        rfu_clearSlot(TYPE_NI_SEND, lman.child_slot);
        lman.nameAcceptTimer.active &= ~(1 << lman.child_slot);
        lman.nameAcceptTimer.count[lman.child_slot] = 0;
        rfu_LMAN_occureCallback(LMAN_MSG_CHILD_NAME_SEND_COMPLETED, 0);
    }
}

static void rfu_LMAN_CHILD_linkRecoveryProcess(void)
{
    if (lman.parent_child == MODE_CHILD && lman.linkRecovery_start_flag == LINK_RECOVERY_START)
    {
        lman.state_bak[0] = lman.state;
        lman.state_bak[1] = lman.next_state;
        lman.state = LMAN_STATE_START_LINK_RECOVERY;
        lman.next_state = LMAN_STATE_POLL_LINK_RECOVERY;
        lman.linkRecovery_start_flag = LINK_RECOVERY_EXE;
    }
}

static u8 rfu_LMAN_CHILD_checkEnableParentCandidate(void)
{
    u8 i;
    u16 *serialNo;
    u8 flags = 0x00;

    for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
    {
        for (serialNo = lman.acceptable_serialNo_list; *serialNo != 0xFFFF; serialNo++)
        {
            if (gRfuLinkStatus->partner[i].serialNo == *serialNo)
            {
                flags |= (1 << i);
            }
        }
    }
    return flags;
}

static void rfu_LMAN_occureCallback(u8 msg, u8 param_count)
{
    if (lman.LMAN_callback != NULL)
    {
        lman.LMAN_callback(msg, param_count);
    }
    lman.param[0] = lman.param[1] = 0;
}

static void rfu_LMAN_disconnect(u8 bm_disconnectedSlot)
{
    u8 active_bak = lman.active;
    lman.active = 1;
    rfu_REQ_disconnect(bm_disconnectedSlot);
    rfu_waitREQComplete();
    lman.active = active_bak;
}

static void rfu_LMAN_reflectCommunicationStatus(u8 bm_disconnectedSlot)
{
    u8 i;

    if (gRfuLinkStatus->sendSlotNIFlag)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (gRfuSlotStatusNI[i]->send.state & SLOT_BUSY_FLAG && gRfuSlotStatusNI[i]->send.bmSlot & bm_disconnectedSlot)
            {
                rfu_changeSendTarget(TYPE_NI, i, gRfuSlotStatusNI[i]->send.bmSlot & ~bm_disconnectedSlot);
            }
        }
    }
    if (gRfuLinkStatus->recvSlotNIFlag)
    {
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (gRfuSlotStatusNI[i]->recv.state & SLOT_BUSY_FLAG && gRfuSlotStatusNI[i]->recv.bmSlot & bm_disconnectedSlot)
            {
                rfu_NI_stopReceivingData(i);
            }
        }
    }
    if (gRfuLinkStatus->sendSlotUNIFlag)
    {
        gRfuLinkStatus->sendSlotUNIFlag &= ~bm_disconnectedSlot;
        for (i = 0; i < RFU_CHILD_MAX; i++)
        {
            if (gRfuSlotStatusUNI[i]->send.state == SLOT_STATE_SEND_UNI && bm_disconnectedSlot & gRfuSlotStatusUNI[i]->send.bmSlot)
            {
                gRfuSlotStatusUNI[i]->send.bmSlot &= ~bm_disconnectedSlot;
            }
        }
    }
}

static void rfu_LMAN_checkNICommunicateStatus(void)
{
    u8 i;
    u8 j;
    u8 flags;

    if (lman.NI_failCounter_limit)
    {
        if (gRfuLinkStatus->sendSlotNIFlag)
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if (gRfuSlotStatusNI[i]->send.state & SLOT_BUSY_FLAG)
                {
                    flags = 0;
                    for (j = 0; j < RFU_CHILD_MAX; j++)
                    {
                        if ((gRfuSlotStatusNI[i]->send.bmSlot >> j) & 1 && gRfuSlotStatusNI[j]->send.failCounter > lman.NI_failCounter_limit)
                        {
                            flags |= (1 << j);
                        }
                        if (flags)
                        {
                            rfu_changeSendTarget(TYPE_NI, i, flags ^ gRfuSlotStatusNI[i]->send.bmSlot);
                        }
                    }
                }
            }
        }
        if (gRfuLinkStatus->recvSlotNIFlag)
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if (gRfuSlotStatusNI[i]->recv.state & SLOT_BUSY_FLAG && gRfuSlotStatusNI[i]->recv.failCounter > lman.NI_failCounter_limit)
                {
                    rfu_NI_stopReceivingData(i);
                }
            }
        }
    }
}

void rfu_LMAN_setMSCCallback(void (*MSC_callback_p)(u16))
{
    lman.MSC_callback = MSC_callback_p;
    rfu_setMSCCallback(rfu_LMAN_MSC_callback);
}

static void rfu_LMAN_setLMANCallback(void (*func)(u8, u8))
{
    lman.LMAN_callback = func;
}

u8 rfu_LMAN_setLinkRecovery(u8 enable_flag, u16 recovery_period)
{
    u16 imeBak;
    if (lman.linkRecovery_enable && enable_flag == 0 && lman.linkRecoveryTimer.active)
    {
        return LMAN_ERROR_NOW_LINK_RECOVERY;
    }
    imeBak = REG_IME;
    REG_IME = 0;
    lman.linkRecovery_enable = enable_flag;
    lman.linkRecoveryTimer.count_max = recovery_period;
    REG_IME = imeBak;
    return 0;
}

static u8 rfu_LMAN_setNIFailCounterLimit(u16 NI_failCounter_limit)
{
    if (gRfuLinkStatus->sendSlotNIFlag | gRfuLinkStatus->recvSlotNIFlag)
    {
        lman.param[0] = 6;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_NOW_COMMUNICATION;
    }
    lman.NI_failCounter_limit = NI_failCounter_limit;
    return 0;
}

static u8 rfu_LMAN_setFastSearchParent(u8 enable_flag)
{
    if (lman.state == LMAN_STATE_START_SEARCH_PARENT || lman.state == LMAN_STATE_POLL_SEARCH_PARENT || lman.state == LMAN_STATE_END_SEARCH_PARENT)
    {
        lman.param[0] = 7;
        rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_NOW_SEARCH_PARENT;
    }
    if (enable_flag)
    {
        lman.fastSearchParent_flag = FSP_ON;
    }
    else
    {
        lman.fastSearchParent_flag = 0;
    }
    return 0;
}

static void rfu_LMAN_managerChangeAgbClockMaster(void)
{
    if (lman.childClockSlave_flag != RFU_CHILD_CLOCK_SLAVE_OFF)
    {
        lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_OFF;
        rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_MASTER, 0);
    }
}

void rfu_LMAN_requestChangeAgbClockMaster(void)
{
    if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_OFF)
    {
        rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_MASTER, 0);
    }
    else if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON)
    {
        lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_OFF_REQ;
    }
}

void rfu_LMAN_forceChangeSP(void)
{
    if (lman.pcswitch_flag)
    {
        switch (lman.state)
        {
        case LMAN_STATE_START_SEARCH_CHILD:
            lman.pcswitch_flag = PCSWITCH_2ND_SP_START;
            lman.state = LMAN_STATE_START_SEARCH_PARENT;
            break;
        case LMAN_STATE_POLL_SEARCH_CHILD:
            lman.pcswitch_flag = PCSWITCH_1ST_SC;
            lman.connect_period = 1;
            break;
        case LMAN_STATE_END_SEARCH_CHILD:
        case LMAN_STATE_WAIT_RECV_CHILD_NAME:
            lman.pcswitch_flag = PCSWITCH_1ST_SC;
            break;
        case LMAN_STATE_START_SEARCH_PARENT:
        case LMAN_STATE_POLL_SEARCH_PARENT:
            lman.connect_period = PCSWITCH_SP_PERIOD;
            break;
        case LMAN_STATE_END_SEARCH_PARENT:
            lman.connect_period = PCSWITCH_SP_PERIOD;
            lman.state = LMAN_STATE_POLL_SEARCH_PARENT;
            break;
        }
    }
}
