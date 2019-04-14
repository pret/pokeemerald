#include "global.h"
#include "heal_location.h"
#include "constants/maps.h"

#include "data/heal_locations.h"

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(gHealLocations); i++)
    {
        if (gHealLocations[i].group == mapGroup && gHealLocations[i].map == mapNum)
            return i + 1;
    }
    return 0;
}

const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum)
{
    u32 index = GetHealLocationIndexByMap(mapGroup, mapNum);

    if (index == 0)
        return NULL;
    else
        return &gHealLocations[index - 1];
}

const struct HealLocation *GetHealLocation(u32 index)
{
    if (index == 0)
        return NULL;
    else if (index > ARRAY_COUNT(gHealLocations))
        return NULL;
    else
        return &gHealLocations[index - 1];
}
