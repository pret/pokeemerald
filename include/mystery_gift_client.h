#ifndef GUARD_MYSTERY_GIFT_CLIENT_H
#define GUARD_MYSTERY_GIFT_CLIENT_H

#include "mystery_gift_link.h"

// Return values for client functions called by MysteryGiftClient_Run
enum {
    CLI_RET_INIT,
    CLI_RET_ACTIVE,
    CLI_RET_YES_NO,
    CLI_RET_PRINT_MSG,
    CLI_RET_ASK_TOSS,
    CLI_RET_COPY_MSG,
    CLI_RET_END,
};

// IDs for client script instructions
enum {
    CLI_NONE,
    CLI_RETURN,
    CLI_RECV,
    CLI_SEND_LOADED,
    CLI_COPY_RECV,
    CLI_YES_NO,
    CLI_COPY_RECV_IF_N,
    CLI_COPY_RECV_IF,
    CLI_LOAD_GAME_DATA,
    CLI_SAVE_NEWS,
    CLI_SAVE_CARD,
    CLI_PRINT_MSG,
    CLI_COPY_MSG,
    CLI_ASK_TOSS,
    CLI_LOAD_TOSS_RESPONSE,
    CLI_RUN_MEVENT_SCRIPT,
    CLI_SAVE_STAMP,
    CLI_SAVE_RAM_SCRIPT,
    CLI_RECV_EREADER_TRAINER,
    CLI_SEND_STAT,
    CLI_SEND_READY_END,
    CLI_RUN_BUFFER_SCRIPT,
};

// IDs for client messages when ending a script.
// Given as the parameter to CLI_RETURN, and resolved to text in GetClientResultMessage
enum {
    CLI_MSG_NOTHING_SENT,
    CLI_MSG_RECORD_UPLOADED,
    CLI_MSG_CARD_RECEIVED,
    CLI_MSG_NEWS_RECEIVED,
    CLI_MSG_STAMP_RECEIVED,
    CLI_MSG_HAD_CARD,
    CLI_MSG_HAD_STAMP,
    CLI_MSG_HAD_NEWS,
    CLI_MSG_NO_ROOM_STAMPS,
    CLI_MSG_COMM_CANCELED,
    CLI_MSG_CANT_ACCEPT,
    CLI_MSG_COMM_ERROR,
    CLI_MSG_TRAINER_RECEIVED,
    CLI_MSG_BUFFER_SUCCESS,
    CLI_MSG_BUFFER_FAILURE,
};

#define CLIENT_MAX_MSG_SIZE 64

struct MysteryGiftClientCmd
{
    u32 instr;
    u32 parameter;
};

struct MysteryGiftClient
{
    u32 unused;
    u32 param;
    u32 funcId;
    u32 funcState;
    u32 cmdidx;
    void * sendBuffer;
    void * recvBuffer;
    struct MysteryGiftClientCmd * script;
    void * msg;
    struct MysteryGiftLink link;
    bool32 isWonderNews;
};

void MysteryGiftClient_Create(bool32 isWonderNews);
u32 MysteryGiftClient_Run(u16 * endVal);
void MysteryGiftClient_AdvanceState(void);
void * MysteryGiftClient_GetMsg(void);
void MysteryGiftClient_SetParam(u32 value);

#endif //GUARD_MYSTERY_GIFT_CLIENT_H
