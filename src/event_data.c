#include "global.h"
#include "event_data.h"

extern u8 gUnknown_020375FC[16];

void InitEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, sizeof(gSaveBlock1Ptr->flags));
    memset(gSaveBlock1Ptr->vars, 0, sizeof(gSaveBlock1Ptr->vars));
    memset(gUnknown_020375FC, 0, sizeof(gUnknown_020375FC));
}
