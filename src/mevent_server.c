#include "global.h"
#include "alloc.h"
#include "mevent.h"
#include "mevent_server.h"
#include "mevent_server_helpers.h"

EWRAM_DATA struct mevent_srv_common * s_mevent_srv_common_ptr = NULL;
EWRAM_DATA struct mevent_srv_ish * s_mevent_srv_ish_ptr = NULL;

static void mevent_srv_init_common(struct mevent_srv_common *, const void *, u32, u32);
u32 mevent_srv_exec_common(struct mevent_srv_common *);
u32 mevent_srv_free_resources(struct mevent_srv_common *);

extern const struct mevent_cmd s_mevent_wonder_news[];
extern const struct mevent_cmd s_mevent_wonder_card[];

void mevent_srv_init_wnews(void)
{
    s_mevent_srv_common_ptr = AllocZeroed(sizeof(struct mevent_srv_common));
    mevent_srv_init_common(s_mevent_srv_common_ptr, s_mevent_wonder_news, 0, 1);
}

void mevent_srv_new_wcard(void)
{
    s_mevent_srv_common_ptr = AllocZeroed(sizeof(struct mevent_srv_common));
    mevent_srv_init_common(s_mevent_srv_common_ptr, s_mevent_wonder_card, 0, 1);
}

u32 mevent_srv_common_do_exec(u16 * a0)
{
    u32 result;
    if (s_mevent_srv_common_ptr == NULL)
        return 3;
    result = mevent_srv_exec_common(s_mevent_srv_common_ptr);
    if (result == 3)
    {
        *a0 = s_mevent_srv_common_ptr->param;
        mevent_srv_free_resources(s_mevent_srv_common_ptr);
        Free(s_mevent_srv_common_ptr);
        s_mevent_srv_common_ptr = NULL;
    }
    return result;
}

static void mevent_srv_init_common(struct mevent_srv_common * svr, const void * cmdBuffer, u32 sendPlayerNo, u32 recvPlayerNo)
{
    svr->unk_00 = 0;
    svr->mainseqno = 0;
    svr->mevent_32e0 = AllocZeroed(sizeof(struct MEventBuffer_32E0_Sub));
    svr->mevent_3120 = AllocZeroed(sizeof(struct MEventBuffer_3120_Sub));
    svr->recvBuffer = AllocZeroed(ME_SEND_BUF_SIZE);
    svr->mevent_unk1442cc = AllocZeroed(sizeof(struct MEventStruct_Unk1442CC));
    svr->cmdBuffer = cmdBuffer;
    svr->cmdidx = 0;
    mevent_srv_sub_init(&svr->manager, sendPlayerNo, recvPlayerNo);
}
