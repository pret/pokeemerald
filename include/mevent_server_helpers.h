#ifndef GUARD_MEVENT_SERVER_HELPERS_H
#define GUARD_MEVENT_SERVER_HELPERS_H

#define MG_LINK_BUFFER_SIZE 0x400

// Send/receive ids for the Client/Server to make sure
// they're sending/receiving the same thing
enum {
    MG_LINKID_CLIENT_SCRIPT = 16,
    MG_LINKID_GAME_DATA,
    MG_LINKID_GAME_STAT,
    MG_LINKID_RESPONSE,
    MG_LINKID_READY_END,
    MG_LINKID_DYNAMIC_MSG,
    MG_LINKID_CARD,
    MG_LINKID_NEWS,
    MG_LINKID_STAMP,
    MG_LINKID_RAM_SCRIPT,
    MG_LINKID_EREADER_TRAINER,
    MG_LINKID_UNK_1,
    MG_LINKID_UNK_2,
};

struct MysteryGiftLink
{
    s32 state;
    u8 sendPlayerId;
    u8 recvPlayerId;
    u16 recvIdent;
    u16 recvCounter;
    u16 recvCRC;
    u16 recvSize;
    u16 sendIdent;
    u16 sendCounter;
    u16 sendCRC;
    u16 sendSize;
    void * recvBfr;
    const void * sendBfr;
    u32 (*recvFunc)(struct MysteryGiftLink *);
    u32 (*sendFunc)(struct MysteryGiftLink *);
};

void MysteryGiftLink_Init(struct MysteryGiftLink *, u32, u32);
void MysteryGiftLink_InitSend(struct MysteryGiftLink * manager, u32 ident, const void * src, u32 size);
bool32 MysteryGiftLink_Recv(struct MysteryGiftLink * manager);
bool32 MysteryGiftLink_Send(struct MysteryGiftLink * manager);
void MysteryGiftLink_InitRecv(struct MysteryGiftLink *, u32, void *);

#endif //GUARD_MEVENT_SERVER_HELPERS_H
