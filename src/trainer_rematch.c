#include "global.h"
#include "constants/flags.h"
#include "random.h"
#include "event_data.h"
#include "battle_setup.h"
#include "trainer_rematch.h"

static void sub_81DA5D4(const u16 *data, size_t size, u32 a2);
static s32 sub_81DA6CC(u32 trainerIdx);

static const u16 GymLeaderRematches_AfterNewMauville[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    REMATCH_WATTSON,
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
    REMATCH_WINONA,
    REMATCH_TATE_AND_LIZA,
    REMATCH_JUAN
};

static const u16 GymLeaderRematches_BeforeNewMauville[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    // Wattson isn't available at this time
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
    REMATCH_WINONA,
    REMATCH_TATE_AND_LIZA,
    REMATCH_JUAN
};

void sub_81DA57C(void)
{
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && (Random() % 100) <= 30)
    {
        if (FlagGet(FLAG_0x05B))
            sub_81DA5D4(GymLeaderRematches_AfterNewMauville, ARRAY_COUNT(GymLeaderRematches_AfterNewMauville), 5);
        else
            sub_81DA5D4(GymLeaderRematches_BeforeNewMauville, ARRAY_COUNT(GymLeaderRematches_BeforeNewMauville), 1);
    }
}

static void sub_81DA5D4(const u16 *data, size_t size, u32 a2)
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

static s32 sub_81DA6CC(u32 trainerIdx)
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
