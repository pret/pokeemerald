#ifndef GUARD_MEVENT_CLIENT_H
#define GUARD_MEVENT_CLIENT_H

#include "mevent_server_helpers.h"

struct mevent_client_cmd
{
    u32 instr;
    u32 parameter;
};

struct mevent_client
{
    u32 unk_00;
    u32 param;
    u32 mainseqno;
    u32 flag;
    u32 cmdidx;
    void * sendBuffer;
    void * recvBuffer;
    struct mevent_client_cmd * cmdBuffer;
    void * buffer;
    struct mevent_srv_sub manager;
    u32 unk_4C;
};

void mevent_client_do_init(u32 arg);
u32 mevent_client_do_exec(u16 * a0);
void mevent_client_inc_flag(void);
void * mevent_client_get_buffer(void);
void mevent_client_set_param(u32 a0);

#endif //GUARD_MEVENT_CLIENT_H
