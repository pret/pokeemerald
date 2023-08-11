#ifndef GUARD_LIBRFU_H
#define GUARD_LIBRFU_H

#include "global.h"
#include "main.h"

#define LIBRFU_VERSION 1026

/* TODOs:
 * - documentation
 * - check if any field needs to be volatile
 * - check if field names make sense
 */

// --------------------------------------------------------------------------
//
// Restrictions When Using RFU
//
// --------------------------------------------------------------------------
/*
  The following restrictions apply when using RFU.

  <Restrictions for Direct Sound>
    (a) The timer for Sound DMA uses only 0
    (b) The prescaler for the timer count for the Sound DMA uses 59.5 ns.
    (c) The sound sampling rate is Max36.314KHz.

  <Restrictions for H-DMA or DMA started with V-Blank>
    These types of DMA can be operated on a maximum CPU cycle of 42 cycles.
    Calculate the number of the transferable DMA count based on this 42 cycles and the access cycles of the destination and source.
    For example, if both the CPU internal RAM --> VRAM have a one cycle access, then a 21 count DMA can occur.


  If RFU is used outside of these restrictions, problems, such as the loss of data caused by the failure of the AGB, as a clock slave,
  to notify that data has been received from the RFU, will occur.
  When this problem occurs, the REQ callback will send a REQ_commandID=ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ notification.
   (When using Link Manager, the LMAN call back will send a LMAN_msg=LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA notification.)

*/

// REQ-COMMAND (STWI) ID CODE LIST

// REQ Command ID returned by the REQ callback
#define ID_RESET_REQ                                0x0010
#define ID_LINK_STATUS_REQ                          0x0011
#define ID_VERSION_STATUS_REQ                       0x0012    // not defined in SDK header
#define ID_SYSTEM_STATUS_REQ                        0x0013
#define ID_SLOT_STATUS_REQ                          0x0014    // not defined in SDK header
#define ID_CONFIG_STATUS_REQ                        0x0015    // not defined in SDK header
#define ID_GAME_CONFIG_REQ                          0x0016
#define ID_SYSTEM_CONFIG_REQ                        0x0017
#define ID_SC_START_REQ                             0x0019
#define ID_SC_POLL_REQ                              0x001a
#define ID_SC_END_REQ                               0x001b
#define ID_SP_START_REQ                             0x001c
#define ID_SP_POLL_REQ                              0x001d
#define ID_SP_END_REQ                               0x001e
#define ID_CP_START_REQ                             0x001f
#define ID_CP_POLL_REQ                              0x0020
#define ID_CP_END_REQ                               0x0021
#define ID_DATA_TX_REQ                              0x0024
#define ID_DATA_TX_AND_CHANGE_REQ                   0x0025
#define ID_DATA_RX_REQ                              0x0026
#define ID_MS_CHANGE_REQ                            0x0027    // When returned by the REQ callback, this ID indicates that execution of rfu_REQ_changeMasterSlave has finished.
                                                              // This ID is returned by both the REQ callback and the MSC callback.
                                                              // When returned by the MSC callback, this is notification that after the AGB has been made into the clock slave, the MC_Timer expired and the RFU returned the AGB to be the clock master.
#define ID_DISCONNECT_REQ                           0x0030
#define ID_TEST_MODE_REQ                            0x0031    // not defined in SDK header
#define ID_CPR_START_REQ                            0x0032
#define ID_CPR_POLL_REQ                             0x0033
#define ID_CPR_END_REQ                              0x0034
#define ID_UNK35_REQ                                0x0035    // not defined in SDK header
#define ID_UNK36_REQ                                0x0036    // not defined in SDK header
#define ID_RESUME_RETRANSMIT_AND_CHANGE_REQ         0x0037
#define ID_STOP_MODE_REQ                            0x003d
#define ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ   0x00ff    // When the AGB is the clock slave, the RFU generates an informational notice, and an automatically started DMA, such as HDMA, is generated at the instant the AGB is being returned as the clock master. This ID is notified by a REQ callback when the exchange of this information (REQ command) fails.

// REQ Command ID returned by the MSC callback
#define ID_DISCONNECTED_AND_CHANGE_REQ              0x0029
#define ID_DATA_READY_AND_CHANGE_REQ                0x0028
#define ID_DRAC_REQ_WITH_ACK_FLAG                   0x0128

// --------------------------------------------------------------------------
//
// Data Definitions
//
// --------------------------------------------------------------------------

#define RFU_ID                          0x00008001         // ID number of AGB-RFU device: ID returned by execution of rfu_REQBN_softReset_and_checkID.

#define RFU_MBOOT_DOWNLOADER_SERIAL_NO  0x0000             // The game serial number of the multi-boot downloader (programs that boot without a Game Pak)

#define RFU_API_BUFF_SIZE_RAM           0x0e64             // Necessary size for buffer specified by rfu_initializeAPI (fast communication version that operates the library SIO interrupt routines in RAM)
#define RFU_API_BUFF_SIZE_ROM           0x0504             // Necessary size for buffer specified by rfu_initializeAPI (fast communication version that operates the library SIO interrupt routines in ROM)

#define RFU_CHILD_MAX                   4                  // Maximum number of slaves that can be connected to one parent device

#define RFU_GAME_NAME_LENGTH            13                 // Possible length of game name set by rfu_REQB_configGameData
#define RFU_USER_NAME_LENGTH            8                  // Possible length of user name set by rfu_REQB_configGameData

#define RFU_H_DMA_MAX_CPU_CYCLE         42                 // Maximum number of CPU cycles for H-DMA or DMA that starts with V-Blank that can operate when using RFU

// Value to determine the level of the icon that displays the link strength of the wireless status (value of rfuLinkStatus->strength[0-3])
#define RFU_LINK_ICON_LEVEL4_MAX        255                // 90% -100%  (If the value is betwen 229 and 255, the icon level is 4)
#define RFU_LINK_ICON_LEVEL4_MIN        229
#define RFU_LINK_ICON_LEVEL3_MAX        228                // 50% - 89%  (If the value is betwen 127 and 228, the icon level is 3)
#define RFU_LINK_ICON_LEVEL3_MIN        127
#define RFU_LINK_ICON_LEVEL2_MAX        126                // 10% - 49%  (If the value is betwen 25 and 126, the icon level is 2)
#define RFU_LINK_ICON_LEVEL2_MIN         25
#define RFU_LINK_ICON_LEVEL1_MAX         24                //  0% -  9%  (If the value is betwen 0 and 24, the icon level is 1)
#define RFU_LINK_ICON_LEVEL1_MIN          0


// *******************************************************
// Definition Data for Arguments Used in Library Functions
// *******************************************************
// Specified by u16 mbootFlag in rfu_REQ_configGameData
#define RFU_MBOOT_FLAG                  0x01               // Enabling this flag, allows connection to a multi-boot program.

// AvailSlot (number of slots available for connection) used in u16 availSlotFlag in rfu_REQ_configSystem
#define AVAIL_SLOT4                     0x0000
#define AVAIL_SLOT3                     0x0001
#define AVAIL_SLOT2                     0x0002
#define AVAIL_SLOT1                     0x0003

// u8 connTypeFlag specified by rfu_setRecvBuffer
#define TYPE_UNI                        0x10               // UNI-type
#define TYPE_NI                         0x20               // NI-type

// u8 connTypeFlag specified by rfu_clearSlot
#define TYPE_UNI_SEND                   0x01               // UNI-type send
#define TYPE_UNI_RECV                   0x02               // UNI-type receive
#define TYPE_NI_SEND                    0x04               // NI-type send
#define TYPE_NI_RECV                    0x08               // NI-type receive

// *******************************************************
// Definition Data Returned by Return Values for Library Functions
// *******************************************************

// The function doesn't have return value.
// Value of u8 *status for rfu_REQ_pollConnectParent (Connection Trial Status)
// #define CP_STATUS_DONE                  0x00               // Connection successful
// #define CP_STATUS_IN_PROCESS            0x01               // Connecting
// #define CP_STATUS_SLOT_CLOSED           0x02               // Parent device is not in connection mode with child device
// #define CP_STATUS_DISCONNECTED          0x03               // Disconnected by parent device while connecting
// #define CP_STATUS_UNKNOWN               0xff               // Cannot read status due to REQ-API execution error

// The function doesn't exist.
// Value of u8 *status argument for rfu_REQ_pollRecoveryConnect (Link Restore Status)
// #define RC_STATUS_DONE                  0x00               // Connection restore successful
// #define RC_STATUS_FAILED                0x01               // Connection restore failure (meaningless to try anymore)
// #define RC_STATUS_SEARCHING_PARENT      0x02               // Searching for parent device
// #define RC_STATUS_UNKNOWN               0xff               // Cannot read status due to REQ-API execution error

// Value of u8 *linkLossReason argument for rfu_REQBN_watchLink (Reason for Link Loss)
#define REASON_DISCONNECTED             0x00               // State of complete disconnection with rfuLL_disconnect and no possibility of restoring the link (can detect only child device)
#define REASON_LINK_LOSS                0x01               // State of link loss that allows for the possibility for the link to be restored


// *******************************************************
// Definition Data Returned with Return Values for Library Functions
// *******************************************************

// Value returned by rfu_getMasterSlave
#define AGB_CLK_SLAVE                   0                  // AGB clock slave
#define AGB_CLK_MASTER                  1                  // AGB clock master

// *******************************************************
// Error Code Group for Library Functions
// *******************************************************

// Error codes returned by u16 REQ_result with a REQ callback when a REQ-API function is executed
#define ERR_REQ_CMD                     0x0000
#define ERR_REQ_CMD_CLOCK_DRIFT        (ERR_REQ_CMD | 0x0001) // Clock drift occurs when a REQ command is sent
#define ERR_REQ_CMD_SENDING            (ERR_REQ_CMD | 0x0002) // The next command cannot be issued because a REQ command is being sent
#define ERR_REQ_CMD_ACK_REJECTION      (ERR_REQ_CMD | 0x0003) // The REQ command was refused when issued
#define ERR_REQ_CMD_CLOCK_SLAVE        (ERR_REQ_CMD | 0x0004) // Issuing the REQ command was attempted but failed because the AGB is the clock slave
#define ERR_REQ_CMD_IME_DISABLE        (ERR_REQ_CMD | 0x0006) // Issuing the REQ command was attempted but failed because the IME register is 0

#define ERR_PID_NOT_FOUND               0x0100                // The specified PID does not exist in the gRfuLinkStatus->partner[0-3].id list

// Error code returned by the return value of rfu_initializeAPI
#define ERR_RFU_API_BUFF_SIZE           0x0001
#define ERR_RFU_API_BUFF_ADR            0x0002

// Error codes returned by return values for rfu_REQBN_softReset_and_checkID
#define ERR_ID_CHECK_IME_DISABLE        0xffffffff            // ID check could not be executed because REG_IME=0 when executing rfu_REQBN_softReset_and_checkID

// Error codes returned by rfu_getConnectParentStatus and rfu_CHILD_getConnectRecoveryStatus
#define ERR_REQ_CMD_ID                 (ERR_REQ_CMD | 0x0010) // A required REQ command was not executed within this function execution

// Error codes returned by rfu_NI_setSendData, rfu_UNI_setSendData, and rfu_NI_CHILD_setSendGameName
#define ERR_MODE                        0x0300
#define ERR_MODE_NOT_PARENT            (ERR_MODE | 0x0000)    // not in SDK
#define ERR_MODE_NOT_CONNECTED         (ERR_MODE | 0x0001)    // RFU is not in connection mode (parent or child)

#define ERR_SLOT                        0x0400
#define ERR_SLOT_NO                    (ERR_SLOT | 0x0000)    // The specified slot number is not right
#define ERR_SLOT_NOT_CONNECTED         (ERR_SLOT | 0x0001)    // The specified slot is not connected
#define ERR_SLOT_BUSY                  (ERR_SLOT | 0x0002)    // The specified slot is already communicating
#define ERR_SLOT_NOT_SENDING           (ERR_SLOT | 0x0003)    // The specified slot is not currently sending (Note: This is returned by rfu_UNI_re_setSendData)
#define ERR_SLOT_TARGET                (ERR_SLOT | 0x0004)    // The specified target slot is not right

#define ERR_SUBFRAME_SIZE               0x0500                // The specified subframe size is either larger than the remaining communication frame size or smaller than the link layer subframe header size

// Error code returned by rfu_clearSlot, rfu_setRecvBuffer, and rfu_changeSendTarget
#define ERR_COMM_TYPE                   0x0600                // The specified communication format is not right

// Error code returned by rfu_REQ_recvData (when receiving NI-type or UNI-type data)
#define ERR_DATA_RECV                   0x0700                // Error notification is issued in the following format.
                                                              // "ERR_DATA_RECV | (slot number issuing error with 0x0010<<UNI) | (slot number issuing error with 0x0001<<NI)"
                                                              // The actual error code is stored in gRfuSlotStatusNI or gRfuSlotStatusUNI[x]->recv.errorCode.

// Error code during NI-type communication (code entered into gRfuSlotStatusNI[x]->recv.errorCode)
#define ERR_RECV_BUFF_OVER              (ERR_DATA_RECV | 0x0001)  // The receive data size is larger than the receive buffer (Note: This error is used for both NI and UNI)
#define ERR_RECV_REPLY_SUBFRAME_SIZE    (ERR_DATA_RECV | 0x0002)  // All frames are already in use by other communications, and a subframe for reception response could not be secured

// Error code during UNI-type communication (code entered into gRfuSlotStatusUNI[x]->recv.errorCode)
#define ERR_RECV_DATA_OVERWRITED        (ERR_DATA_RECV | 0x0008)  // Received new data when gRfuSlotStatusUNI[x]->recv.newDataFlag=1

// not in SDK header
#define ERR_RECV_UNK                    (ERR_DATA_RECV | 0x0001 | 0x0008)

// *******************************************************
// Definition Data Used by Global Variables in the Library
// *******************************************************

// gRfuLinkStatus-------------------------------------------
// Connection status (refer to gRfuLinkStatus->parentChild)
#define MODE_NEUTRAL                    0xff               // Initialization
#define MODE_CHILD                      0x00               // Child
#define MODE_PARENT                     0x01               // Parent


// gRfuSlotStatusNI,UNI-----------------------------------
// Definition data for NI-(Numbered Information) and UNI-(Un-Numbered Information) type communication

// Definition data common to NI- and UNI-type communication
#define LLF_P_SIZE                      87                 // Maximum link layer communication frame size for the Parent (Maximum number of bytes per transmission)
#define LLF_C_SIZE                      16                 //      "                                "     for the Child
#define LLSF_P_HEADER_SIZE              3                  // Header size used by one link layer subframe (NI or UNI frame) for the Parent
#define LLSF_C_HEADER_SIZE              2                  //      "                                "                       for the Child

// Link Layer Communication Code
#define LCOM_NULL                       0x0000
#define LCOM_NI_START                   0x0001
#define LCOM_NI                         0x0002
#define LCOM_NI_END                     0x0003
#define LCOM_UNI                        0x0004

// Flag for Slot Status Data
#define SLOT_BUSY_FLAG                  0x8000             // Slot in use
#define SLOT_SEND_FLAG                  0x0020             // Send
#define SLOT_RECV_FLAG                  0x0040             // Receive

// NI- and UNI-type shared slot stand-by data (same state as gRfuSlotStatusNI[x]->send or ->recv.state or gRfuSlotStatusUNI)
#define SLOT_STATE_READY                0x0000             // Slot initialization

// Status data for NI-type communication (gRfuSlotStatusNI[x]->send or ->recv.state)
#define SLOT_STATE_SEND_START           (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NI_START)   // Start transmission
#define SLOT_STATE_SENDING              (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NI)         // Transmitting
#define SLOT_STATE_SEND_LAST            (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NI_END)     // Verify transmission end
#define SLOT_STATE_SEND_NULL            (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NULL)       // Send NULL subframe to notify end of transmission
#define SLOT_STATE_SEND_SUCCESS         (                 SLOT_SEND_FLAG | 0x006)           // Transmission successful
#define SLOT_STATE_SEND_FAILED          (                 SLOT_SEND_FLAG | 0x007)           // Transmission failed
                                                                                            // Distinction of slot where transmission succeeded/failed compares gRfuSlotStatusNI[x]->send.bmSlot and same bmSlot_org
#define SLOT_STATE_RECV_START           (SLOT_BUSY_FLAG | SLOT_RECV_FLAG | LCOM_NI_START)   // Start reception
#define SLOT_STATE_RECEIVING            (SLOT_BUSY_FLAG | SLOT_RECV_FLAG | LCOM_NI)         // Receiving
#define SLOT_STATE_RECV_LAST            (SLOT_BUSY_FLAG | SLOT_RECV_FLAG | LCOM_NI_END)     // Verify reception end
#define SLOT_STATE_RECV_SUCCESS         (                 SLOT_RECV_FLAG | 0x006)           // Reception successful
#define SLOT_STATE_RECV_FAILED          (                 SLOT_RECV_FLAG | 0x007)           // Reception failed
#define SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN     (SLOT_RECV_FLAG | 0x008)           // The data was received successful, but because the end of the communication was incomplete, whether the transmission side status is successful or failed is unknown
#define SLOT_STATE_RECV_IGNORE          (                 SLOT_RECV_FLAG | 0x009)           // Ignore reception (refer to gRfuSlotStatusNI[x]->recv.errorCode for reason for ignoring)

// Status data for UNI-type communication (refer to gRfuSlotStatusUNI[x]->send.state)
#define SLOT_STATE_SEND_UNI             (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_UNI)        // Transmitting

// the following structs are not documented in SDK
struct RfuPacket8
{
    u8 data[0x74];
};

struct RfuPacket32
{
    u32 command;
    u32 data[0x1C];
};

union RfuPacket
{
    struct RfuPacket32 rfuPacket32;
    struct RfuPacket8 rfuPacket8;
};

struct STWIStatus
{
    vs32 state;
    u8 reqLength;
    u8 reqNext;
    u8 reqActiveCommand;
    u8 ackLength;
    u8 ackNext;
    u8 ackActiveCommand;
    u8 timerSelect;
    u8 unk_b;
#if LIBRFU_VERSION >= 1026
    s32 timerState;
#else
    u32 timerState;
#endif
    vu8 timerActive;
    u8 unk_11;
    vu16 error;
    vu8 msMode;
    u8 recoveryCount;
    u8 unk_16;
    u8 unk_17;
    void (*callbackM)();
    void (*callbackS)(u16);
    void (*callbackID)(void);
    union RfuPacket *txPacket;
    union RfuPacket *rxPacket;
    vu8 sending;
};

// This struct is used as u8 array in SDK.
struct RfuIntrStruct
{
    union RfuPacket rxPacketAlloc;
    union RfuPacket txPacketAlloc;
    u8 ALIGNED(2) block1[0x960]; // size of librfu_intr.s binary
    struct STWIStatus block2;
};

// Data Structure for Transmitting UNI-Type Data
struct UNISend
{
    u16 state;         // Slot communication state (SLOT_STATE_READY, SLOT_STATE_SEND_UNI)
    u8 dataReadyFlag;  // Flag indicating transmission data is prepared (0: data sent; 1: transmission data ready)
                       //   Set with rfu_UNI_re_setSendData or rfu_UNI_readySendData, cleared when data is sent with rfu_REQ_sendData.
    u8 bmSlot;         // Expresses transmission destination slot as bits
    u16 payloadSize;   // Payload size of 1 transmission. "size" specified by rfu_UNI_setSendData or rfu_UNI_re_setSendData is used.
    const void *src;   // Beginning address of transmission data
};

// Data Structure for Receiving UNI Data
struct UNIRecv
{
    u16 state;         // Slot communication state (SLOT_STATE_READY, SLOT_STATE_RECEIVING, SLOT_STATE_RECV_IGNORE)
    u16 errorCode;     // Error code during reception
    u16 dataSize;      // Size of receive data
    u8 newDataFlag;    // Flag indicating whether receive data has newly arrived (0: no newly arrived data; 1: newly arrived data)
                       //   The flag is cleared with rfu_UNI_clearRecvNewDataFlag; it is set when data is received with rfu_REQ_recvData.
    u8 dataBlockFlag;  // Flag for unreferenced receive data overwrite block (default is 0 Note: not used)
};

// Slot Status Data Structure for UNI-Type Communication
struct RfuSlotStatusUNI
{
    struct UNISend send;    // Transmission Status
    struct UNIRecv recv;    // Reception Status
    void *recvBuffer;       // Reception Buffer Address
    u32 recvBufferSize;     // Reception Buffer Size
};

#define WINDOW_COUNT    4

struct NIComm
{
    u16 state;                     // Communication state of slot
    u16 failCounter;               // Count of failed transmissions/receptions (Count is increased when transmission/reception of data does not succeed within 1PF=16.7 ms)
    const u8 *now_p[WINDOW_COUNT]; // Address of current send/receive (The data is divided into WINDOW_COUNT blocks and sent in payloadSize units.)
    u32 remainSize;                // Size of remaining communication data
    u16 errorCode;                 // Error code
    u8 bmSlot;                     // Expresses the current communication slot in bits
                                   //   (When sending from the Master, because multiple slaves can be specified with bmSlot, communications are terminated based on the failCounter for each child device)
    // Parameters used inside the Library
    u8 recvAckFlag[WINDOW_COUNT];
    u8 ack;
    u8 phase;
    u8 n[WINDOW_COUNT];
    // Parameters indicating the current communication content
    const void *src;               // Start address transmission data (valid only for transmitting device)
    u8 bmSlotOrg;                  // Expresses the communication source slot at the beginning of the transmission in bits (valid only for transmitting device)
    u8 dataType;                   // Transmission/reception data type (0: User data; 1: Game identification information)
    u16 payloadSize;               // Payload size for one transmission
    u32 dataSize;                  // Size of transmission/reception data
                                   //   Calculated by subtracting link layer header size from subFrameSize specified by the rfu_NI_setSendData function
};

struct RfuSlotStatusNI
{
    struct NIComm send;              // Transmission Status
    struct NIComm recv;              // Reception Status
    void *recvBuffer;                // Reception Buffer Address
    u32 recvBufferSize;              // Reception Buffer Size
};

// Game Identification Information Data Structure
struct RfuTgtData
{
    u16 id;                                    // ID of parent candidate                                 ID of connection partner
    u8  slot;                                  // Slot number where parent candidate can enter           Connection slot number
    u8  mbootFlag;                             // Flag to indicate whether or not the parent candidate   Flag to indicate whether or not the connection partner
                                               //   is multiboot program for download                      is multiboot program for download
    u16 serialNo;                              // Game serial number of parent candidate                 Game serial number of connection partner
    u8  gname[RFU_GAME_NAME_LENGTH + 2];       // Game name of parent candidate                          Game name of connection partner
    u8  uname[RFU_USER_NAME_LENGTH + 1];       // User name for parent candidate                         User name for connection partner
};

struct RfuLinkStatus
{
    u8  parentChild;                            // Connection status (0x01:MODE_PARENT  0x00:MODE_CHILD  0xff:MODE_NEUTRAL)
    u8  connCount;                              // Number of connections
    u8  connSlotFlag;                           // Flag to indicate in bits the connection slot (0x01<<Connection slot number)
    u8  linkLossSlotFlag;                       // Flag to indicate in bits the slot where the link loss was generated (")
    u8  sendSlotNIFlag;                         // Flag to indicate in bits the slot where NI-type send is occurring (")
    u8  recvSlotNIFlag;                         // Flag to indicate in bits the slot where NI-type receive is occurring (")
    u8  sendSlotUNIFlag;                        // Flag to indicate in bits the slot where UNI-type send is occurring (")
    u8  getNameFlag;                            // Parent: Flag to indicate whether or not game identification information was obtained from the child connected to this slot (")
                                                // Child: Flag to indicate whether or not game identification information was sent to the parent connected to this slot (")
    u8  findParentCount;                        // Number of parent candidates discovered with rfu_REQ_xxxSearchParent, valid only with a child device
    u8  watchInterval;                          // Link monitor execution interval (16.7 ms unit AGB picture frame)
    u8  strength[RFU_CHILD_MAX];                // Link strength value (0x00 - 0xff; 0x00 is link loss. Updates with rfu_REQBN_watchLink)
    vu8 LLFReadyFlag;                           // Indicates whether the link layer frame to send next has be constructed (Flag is on when calling rfu_constructLLFrame, flag is cleared when sending by rfu_REQ_sendData.)
    u8  remainLLFrameSizeParent;                // Remaining size of the link layer communication frame for the parent device
    u8  remainLLFrameSizeChild[RFU_CHILD_MAX];  // Remaining size of the link layer communication frame for each slot for child device
    struct RfuTgtData partner[RFU_CHILD_MAX];   // Parent, Child: When there is a connection, the matrix element corresponding to the number of the connected slot
                                                //   stores the game identification information for the connection partner.
                                                // Child: Stores the game identification information for the parent candidate discovered when executing rfu_REQ_xxxxSearchParent.
    struct RfuTgtData my;                       // The device's own game identification information (unrelated to the element slot value)
};

// the following structs are not documented in SDK
struct RfuFixed
{
    void (*reqCallback)(u16, u16);
    void (*fastCopyPtr)(const u8 **, u8 **, s32);
    u16 fastCopyBuffer[24];
    u32 fastCopyBuffer2[12];
    u32 LLFBuffer[29];
    struct RfuIntrStruct *STWIBuffer;
};

struct RfuStatic
{
    u8 flags;
    u8 NIEndRecvFlag;
    u8 recvRenewalFlag;
    u8 commExistFlag;
    u8 recvErrorFlag;
    u8 recoveryBmSlot;
    u8 nowWatchInterval;
    u8 nullFrameCount;
    u8 emberCount;
    u8 SCStartFlag;
    u8 linkEmergencyFlag[RFU_CHILD_MAX];
    u8 lsFixedCount[RFU_CHILD_MAX];
    u16 cidBak[RFU_CHILD_MAX];
    u16 linkEmergencyLimit;
    u16 reqResult;
    u16 tryPid;
    u16 watchdogTimer;
    u32 totalPacketSize;
};

extern struct STWIStatus *gSTWIStatus;
extern struct RfuLinkStatus *gRfuLinkStatus;
extern struct RfuStatic *gRfuStatic;
extern struct RfuFixed *gRfuFixed;
extern struct RfuSlotStatusNI *gRfuSlotStatusNI[RFU_CHILD_MAX];
extern struct RfuSlotStatusUNI *gRfuSlotStatusUNI[RFU_CHILD_MAX];

// librfu_sio32id
s32 AgbRFU_checkID(u8 maxTries);

// Arguments with "bm..." specify slots of the form (0x01 << slot number) that are the object of a function operation.

// librfu_rfu
// API Initialization and Initial Settings
    // API Initialization
u16 rfu_initializeAPI(u32 *APIBuffer, u16 buffByteSize, IntrFunc *sioIntrTable_p, bool8 copyInterruptToRam);
    // Set Timer Interrupt
void rfu_setTimerInterrupt(u8 timerNo, IntrFunc *timerIntrTable_p);
    // Resident Function called from within a V-Blank Interrupt
u16 rfu_syncVBlank(void);
    // Specify REQ Callback function
void rfu_setREQCallback(void (*callback)(u16 reqCommandId, u16 reqResult));
    // REQ-API Execution Completion Wait
u16 rfu_waitREQComplete(void);

// RFU Initialization and Initial Settings
    // RFU Startup and ID Check (Forced RFU reset occurs simultaneously)
u32 rfu_REQBN_softReset_and_checkID(void);
    // RFU Reset
void rfu_REQ_reset(void);
    // Set RFU to Stop Mode (Power Down)
void rfu_REQ_stopMode(void);
    // RFU Hardware Settings
void rfu_REQ_configSystem(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer);
    // Game Identification Information Configuration
void rfu_REQ_configGameData(u8 mbootFlag, u16 serialNo, const u8 *gname, const u8 *uname);

// RFU Connection Process
    // Operate as parent device; search for and connect to child device
void rfu_REQ_startSearchChild(void);
void rfu_REQ_pollSearchChild(void);
void rfu_REQ_endSearchChild(void);
    // Operate as child device; search for parent device
void rfu_REQ_startSearchParent(void);
void rfu_REQ_pollSearchParent(void);
void rfu_REQ_endSearchParent(void);
    // Operate as child device; connect to specified parent device
void rfu_REQ_startConnectParent(u16 pid);
void rfu_REQ_pollConnectParent(void);
void rfu_REQ_endConnectParent(void);
u16 rfu_getConnectParentStatus(u8 *status,u8 *connectSlotNo);
    // Restore link from child device
void rfu_REQ_CHILD_startConnectRecovery(u8 bmRecoverySlot);
void rfu_REQ_CHILD_pollConnectRecovery(void);
void rfu_REQ_CHILD_endConnectRecovery(void);
u16 rfu_CHILD_getConnectRecoveryStatus(u8 *status);

// RFU Link Management
    // Link Monitoring
u16 rfu_REQBN_watchLink(u16 reqCommandId, u8 *bmLinkLossSlot, u8 *linkLossReason, u8 *parentBmLinkRecoverySlot);
    // Link Disconnect
void rfu_REQ_disconnect(u8 bmDisconnectSlot);

// Relation of clock between AGB and RFU
    // Switch to AGB clock slave
void rfu_REQ_changeMasterSlave(void);
    // Acquire either the master or slave clock from the current AGB-RFU
bool8 rfu_getMasterSlave(void);

// Communication Configuration
    // MSC Callback Configuration
void rfu_setMSCCallback(void (*callback)(u16 reqCommandId));
    // Shared by NI- and UNI-type communications
        // Clear Communication Status
void rfu_clearAllSlot(void);
u16 rfu_clearSlot(u8 connTypeFlag, u8 slotStatusIndex);
        // Set Receive Buffer
u16 rfu_setRecvBuffer(u8 connType, u8 slotNo, void *buffer, u32 buffSize);

// Receive/Send Data
    // UNI-type communication
        // Set transmission data
u16 rfu_UNI_setSendData(u8 bmSendSlot, const void *src, u8 size);
        // Enable transmission data
void rfu_UNI_readySendData(u8 slotStatusIndex);
        // Change address or size of transmission data and enable transmission data
u16 rfu_UNI_changeAndReadySendData(u8 slotStatusIndex, const void *src, u8 size);
        // Used only by parent device. At the beginning of a MSC Callback that received notification that the data transmission completed, an ACK flag is obtained.
u16 rfu_UNI_PARENT_getDRAC_ACK(u8 *ackFlag);
        // Clear the flag that indicates newly arrived reception data
void rfu_UNI_clearRecvNewDataFlag(u8 slotStatusIndex);
    // NI-type Communication
        // Set transmission data
u16 rfu_NI_setSendData(u8 bmSendSlot, u8 subFrameSize, const void *src, u32 size);
        // Used only by child device. After establishing connection at the RFU level, configure transmission of child device game identification information in order to authenticate connection
u16 rfu_NI_CHILD_setSendGameName(u8 slotNo, u8 subFrameSize);
        // Stop the NI data currently being received
u16 rfu_NI_stopReceivingData(u8 slotStatusIndex);
    // Shared by NI- and UNI-type communications
        // Narrow transmission targets for transmission data.
u16 rfu_changeSendTarget(u8 connType, u8 slotStatusIndex, u8 bmNewTgtSlot);

    // Functions for sending/receiving data to RFU
        // Data transmission
void rfu_REQ_sendData(bool8 clockChangeFlag);
        // Used only by parent device. Resend previous sent data (packet)
void rfu_REQ_PARENT_resumeRetransmitAndChange(void);
        // Read receive data
void rfu_REQ_recvData(void);

// For Multi-boot
    // Inherits the information about the link established by the downloader just after the program downloaded with multiboot starts up.
u16 rfu_MBOOT_CHILD_inheritanceLinkStatus(void);

// For Debug
    // Obtain address of the SWTI-layer receive buffer
u8 *rfu_getSTWIRecvBuffer(void);
    // Obtain RFU state
void rfu_REQ_RFUStatus(void);
u16 rfu_getRFUStatus(u8 *rfuState);
    // Using RFU, generate noise (jamming radio waves) for other RFUs
void rfu_REQ_noise(void);

// librfu_intr
void IntrSIO32(void);

// librfu_stwi
void STWI_init_all(struct RfuIntrStruct *interruptStruct, IntrFunc *interrupt, bool8 copyInterruptToRam);
void STWI_set_MS_mode(u8 mode);
void STWI_init_Callback_M(void);
void STWI_init_Callback_S(void);
void STWI_set_Callback_M(void *callbackM);
void STWI_set_Callback_S(void (*callbackS)(u16));
void STWI_init_timer(IntrFunc *interrupt, s32 timerSelect);
void AgbRFU_SoftReset(void);
void STWI_set_Callback_ID(void (*func)(void));
u16 STWI_read_status(u8 index);
u16 STWI_poll_CommandEnd(void);
void STWI_send_DataRxREQ(void);
void STWI_send_MS_ChangeREQ(void);
void STWI_send_StopModeREQ(void);
void STWI_send_SystemStatusREQ(void);
void STWI_send_GameConfigREQ(const u8 *serial_uname, const u8 *gname);
void STWI_send_ResetREQ(void);
void STWI_send_LinkStatusREQ(void);
void STWI_send_VersionStatusREQ(void);
void STWI_send_SlotStatusREQ(void);
void STWI_send_ConfigStatusREQ(void);
void STWI_send_ResumeRetransmitAndChangeREQ(void);
void STWI_send_SystemConfigREQ(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer);
void STWI_send_SC_StartREQ(void);
void STWI_send_SC_PollingREQ(void);
void STWI_send_SC_EndREQ(void);
void STWI_send_SP_StartREQ(void);
void STWI_send_SP_PollingREQ(void);
void STWI_send_SP_EndREQ(void);
void STWI_send_CP_StartREQ(u16 unk1);
void STWI_send_CP_PollingREQ(void);
void STWI_send_CP_EndREQ(void);
void STWI_send_DataTxREQ(const void *in, u8 size);
void STWI_send_DataTxAndChangeREQ(const void *in, u8 size);
void STWI_send_DataReadyAndChangeREQ(u8 unk);
void STWI_send_DisconnectedAndChangeREQ(u8 unk0, u8 unk1);
void STWI_send_DisconnectREQ(u8 unk);
void STWI_send_TestModeREQ(u8 unk0, u8 unk1);
void STWI_send_CPR_StartREQ(u16 unk0, u16 unk1, u8 unk2);
void STWI_send_CPR_PollingREQ(void);
void STWI_send_CPR_EndREQ(void);

#endif // GUARD_LIBRFU_H
