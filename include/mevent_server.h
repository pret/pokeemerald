#ifndef GUARD_MEVENT_SERVER_H
#define GUARD_MEVENT_SERVER_H

#include "mevent_server_helpers.h"

struct mevent_cmd
{
    u32 instr;
    bool32 flag;
    const void * parameter;
};

struct mevent_srv_common
{
    u32 unk_00;
    u32 param;
    u32 mainseqno;
    u32 cmdidx;
    const struct mevent_cmd * cmdBuffer;
    void * recvBuffer;
    struct WonderCard * wonder_card;
    struct WonderNews * wonder_news;
    struct MEventStruct_Unk1442CC * mevent_unk1442cc;
    const void * sendBuffer1;
    u32 sendBuffer1Size;
    const void * sendBuffer2;
    u32 sendBuffer2Size;
    u32 sendWord;
    struct mevent_srv_sub manager;
};

void mevent_srv_new_wcard();
void mevent_srv_init_wnews();
u32 mevent_srv_common_do_exec(u16 * a0);

#endif //GUARD_MEVENT_SERVER_H
