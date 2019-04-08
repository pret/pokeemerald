#ifndef GUARD_MEVENT_SERVER_HELPERS_H
#define GUARD_MEVENT_SERVER_HELPERS_H

#define ME_SEND_BUF_SIZE 0x400

struct mevent_srv_sub
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
    u32 (*recvFunc)(struct mevent_srv_sub *);
    u32 (*sendFunc)(struct mevent_srv_sub *);
};

struct send_recv_header
{
    u16 ident;
    u16 crc;
    u16 size;
};

void mevent_srv_sub_init(struct mevent_srv_sub *, u32, u32);
void mevent_srv_sub_init_send(struct mevent_srv_sub * manager, u32 ident, const void * src, u32 size);
bool32 mevent_srv_sub_recv(struct mevent_srv_sub * manager);
bool32 mevent_srv_sub_send(struct mevent_srv_sub * manager);
void mevent_srv_sub_init_recv(struct mevent_srv_sub *, u32, void *);

#endif //GUARD_MEVENT_SERVER_HELPERS_H
