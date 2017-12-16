#include "global.h"
#include "trainer_see.h"
#include "battle_setup.h"

extern u8 gApproachingTrainerId;
extern u8 gNoOfApproachingTrainers;
extern u8 gUnknown_030060AC;
extern u16 gUnknown_03006080;

// this file's functions
u8 CheckIfTrainerWantsBattle(u8 mapObjectId);

bool8 CheckForTrainersWantingBattle(void)
{
    u8 i;

    gNoOfApproachingTrainers = 0;
    gApproachingTrainerId = 0;

    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
    {
        u8 retVal;

        if (!gMapObjects[i].active)
            continue;
        if (gMapObjects[i].trainerType != 1 && gMapObjects[i].trainerType != 3)
            continue;

        retVal = CheckIfTrainerWantsBattle(i);
        if (retVal == 2)
            break; // two trainers have been found

        if (retVal == 0) // no trainers
            continue;

        if (gNoOfApproachingTrainers > 1)
            break;
        if (GetMonsStateToDoubles_2() != 0) // one trainer found and cant have a double battle
            break;
    }

    if (gNoOfApproachingTrainers == 1)
    {
        ResetTrainerOpponentIds();
        ConfigureAndSetUpOneTrainerBattle(gApproachingTrainers[gNoOfApproachingTrainers - 1].mapObjectId,
                                          gApproachingTrainers[gNoOfApproachingTrainers - 1].trainerScriptPtr);
        gUnknown_030060AC = 1;
        return TRUE;
    }
    else if (gNoOfApproachingTrainers == 2)
    {
        ResetTrainerOpponentIds();
        for (i = 0; i < gNoOfApproachingTrainers; i++, gApproachingTrainerId++)
        {
            ConfigureTwoTrainersBattle(gApproachingTrainers[i].mapObjectId,
                                       gApproachingTrainers[i].trainerScriptPtr);
        }
        SetUpTwoTrainersBattle();
        gApproachingTrainerId = 0;
        gUnknown_030060AC = 1;
        return TRUE;
    }
    else
    {
        gUnknown_030060AC = 0;
        return FALSE;
    }
}
