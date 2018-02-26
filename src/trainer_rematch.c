
// Includes
#include "global.h"
#include "constants/flags.h"
#include "random.h"
#include "event_data.h"
#include "battle_setup.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

void sub_81DA5D4(const u16 *data, size_t size, u32 a2);
s32 sub_81DA6CC(u32 trainerIdx);

// .rodata

const u16 gUnknown_0862AD34[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48};
const u16 gUnknown_0862AD44[] = {0x41, 0x42, 0x44, 0x45, 0x46, 0x47, 0x48};

// .text

void sub_81DA57C(void)
{
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && (Random() % 100) <= 30)
    {
        if (FlagGet(FLAG_0x05B))
            sub_81DA5D4(gUnknown_0862AD34, ARRAY_COUNT(gUnknown_0862AD34), 5);
        else
            sub_81DA5D4(gUnknown_0862AD44, ARRAY_COUNT(gUnknown_0862AD44), 1);
    }
}

void sub_81DA5D4(const u16 *data, size_t size, u32 a2)
{
    s32 r6 = 0;
    s32 r8 = 5;
    u32 i;
    for (i = 0; i < size; i++)
    {
        if (!gSaveBlock1Ptr->trainerRematches[data[i]])
        {
            s32 val = sub_81DA6CC(data[i]);
            if (r8 > val)
                r8 = val;
            r6++;
        }
    }
    if (r6 != 0 && r8 <= a2)
    {
        r6 = 0;
        for (i = 0; i < size; i++)
        {
            if (!gSaveBlock1Ptr->trainerRematches[data[i]])
            {
                s32 val = sub_81DA6CC(data[i]);
                if (val == r8)
                    r6++;
            }
        }
        if (r6 != 0)
        {
            r6 = Random() % r6;
            for (i = 0; i < size; i++)
            {
                if (!gSaveBlock1Ptr->trainerRematches[data[i]])
                {
                    s32 val = sub_81DA6CC(data[i]);
                    if (val == r8)
                    {
                        if (r6 == 0)
                        {
                            gSaveBlock1Ptr->trainerRematches[data[i]] = r8;
                            break;
                        }
                        r6--;
                    }
                }
            }
        }
    }
}

s32 sub_81DA6CC(u32 trainerIdx)
{
    s32 i;
    for (i = 0; i < 5; i++)
    {
        if (!HasTrainerBeenFought(gRematchTable[trainerIdx].trainerIds[i]))
        {
            return i;
        }
    }
    return 5;
}
