#ifndef GUARD_MEVENT_SERVER_H
#define GUARD_MEVENT_SERVER_H

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

struct mevent_cmd_ish
{
    u32 instr;
    u32 parameter;
};

struct mevent_srv_ish
{
    u32 unk_00;
    u32 param;
    u32 mainseqno;
    u32 flag;
    u32 cmdidx;
    void * sendBuffer;
    void * recvBuffer;
    struct mevent_cmd_ish * cmdBuffer;
    void * buffer;
    struct mevent_srv_sub manager;
};

struct mevent_cmd
{
    u32 instr;
    bool32 flag;
    void * parameter;
};

struct mevent_srv_common
{
    u32 unk_00;
    u32 param;
    u32 mainseqno;
    u32 cmdidx;
    const struct mevent_cmd * cmdBuffer;
    void * recvBuffer;
    struct MEventBuffer_32E0_Sub * mevent_32e0;
    struct MEventBuffer_3120_Sub * mevent_3120;
    struct MEventStruct_Unk1442CC * mevent_unk1442cc;
    void * sendBuffer1;
    u32 sendBuffer1Size;
    void * sendBuffer2;
    u32 sendBuffer2Size;
    u32 sendWord;
    struct mevent_srv_sub manager;
};

void mevent_srv_new_wcard();
void mevent_srv_init_wnews();
u32 mevent_srv_common_do_exec(u16 * a0);

#endif //GUARD_MEVENT_SERVER_H
