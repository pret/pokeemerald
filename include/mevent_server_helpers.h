#ifndef GUARD_MEVENT_SERVER_HELPERS_H
#define GUARD_MEVENT_SERVER_HELPERS_H

#define ME_SEND_BUF_SIZE 0x400

struct MysteryGiftLink
{
    s32 seqno;
    u8 sendPlayerNo;
    u8 recvPlayerNo;
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

struct send_recv_header
{
    u16 ident;
    u16 crc;
    u16 size;
};

void MysteryGiftLink_Init(struct MysteryGiftLink *, u32, u32);
void MysteryGiftLink_InitSend(struct MysteryGiftLink * manager, u32 ident, const void * src, u32 size);
bool32 MysteryGiftLink_Recv(struct MysteryGiftLink * manager);
bool32 MysteryGiftLink_Send(struct MysteryGiftLink * manager);
void MysteryGiftLink_InitRecv(struct MysteryGiftLink *, u32, void *);

#endif //GUARD_MEVENT_SERVER_HELPERS_H
