#include "global.h"
#include "gym_leader_rematch.h"
#include "pokenav.h"

bool32 sub_81C98D4(void)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (sub_81CB0C8(i) == gMapHeader.regionMapSectionId
         && sub_81CAE08(i)
         && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    return FALSE;
}
