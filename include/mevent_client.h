#ifndef GUARD_MEVENT_CLIENT_H
#define GUARD_MEVENT_CLIENT_H

#include "mevent_server_helpers.h"

// Return values for client functions called by MysteryGiftClient_Run
enum {
    CLI_RET_INIT,
    CLI_RET_1,
    CLI_RET_2,
    CLI_RET_3,
    CLI_RET_ASK_TOSS,
    CLI_RET_5,
    CLI_RET_END,
};

// IDs for client script instructions
enum {
    CLI_NONE,
    CLI_RETURN,
    CLI_RECV,
    CLI_SEND_LOADED,
    CLI_COPY_RECV,
    CLI_5,
    CLI_COPY_RECV_IF_N,
    CLI_COPY_RECV_IF,
    CLI_8,
    CLI_9,
    CLI_10,
    CLI_11,
    CLI_12,
    CLI_ASK_TOSS,
    CLI_LOAD_TOSS_RESPONSE,
    CLI_15,
    CLI_16,
    CLI_17,
    CLI_RECV_EREADER_TRAINER,
    CLI_SEND_STAT,
    CLI_20,
    CLI_21,
};

struct MysteryGiftClientCmd
{
    u32 instr;
    u32 parameter;
};

struct MysteryGiftClient
{
    u32 unk_00;
    u32 param;
    u32 funcId;
    u32 funcState;
    u32 cmdidx;
    void * sendBuffer;
    void * recvBuffer;
    struct MysteryGiftClientCmd * cmdBuffer;
    void * buffer;
    struct MysteryGiftLink link;
    bool32 isWonderNews;
};

void MysteryGiftClient_Create(bool32 isWonderNews);
u32 MysteryGiftClient_Run(u16 * param);
void MysteryGiftClient_AdvanceState(void);
void * mevent_client_get_buffer(void);
void MysteryGiftClient_SetParam(u32 value);

#endif //GUARD_MEVENT_CLIENT_H
