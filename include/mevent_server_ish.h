#ifndef GUARD_MEVENT_SERVER_ISH_H
#define GUARD_MEVENT_SERVER_ISH_H

#include "mevent_server_helpers.h"

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
    u32 unk_4C;
};

void mevent_srv_ish_do_init(u32 arg);
u32 mevent_srv_ish_do_exec(u16 * a0);
void mevent_srv_ish_inc_flag(void);
void * mevent_srv_ish_get_buffer(void);
void mevent_srv_ish_set_param(u32 a0);

#endif //GUARD_MEVENT_SERVER_ISH_H
