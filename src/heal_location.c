
// Includes
#include "global.h"
#include "constants/maps.h"
#include "heal_location.h"

#define HEAL_LOCATION(map, x, y) {MAP_GROUP(map), MAP_NUM(map), x, y}

// Static type declarations

// Static RAM declarations

// Static ROM declarations

// .rodata

static const struct HealLocation sHealLocations[] = {
    HEAL_LOCATION(LITTLEROOT_TOWN_BRENDANS_HOUSE_2F,  4,  2),
    HEAL_LOCATION(LITTLEROOT_TOWN_MAYS_HOUSE_2F,      4,  2),
    HEAL_LOCATION(PETALBURG_CITY,                    20, 17),
    HEAL_LOCATION(SLATEPORT_CITY,                    19, 20),
    HEAL_LOCATION(MAUVILLE_CITY,                     22,  6),
    HEAL_LOCATION(RUSTBORO_CITY,                     16, 39),
    HEAL_LOCATION(FORTREE_CITY,                       5,  7),
    HEAL_LOCATION(LILYCOVE_CITY,                     24, 15),
    HEAL_LOCATION(MOSSDEEP_CITY,                     28, 17),
    HEAL_LOCATION(SOOTOPOLIS_CITY,                   43, 32),
    HEAL_LOCATION(EVER_GRANDE_CITY,                  27, 49),
    HEAL_LOCATION(LITTLEROOT_TOWN,                    5,  9),
    HEAL_LOCATION(LITTLEROOT_TOWN,                   14,  9),
    HEAL_LOCATION(OLDALE_TOWN,                        6, 17),
    HEAL_LOCATION(DEWFORD_TOWN,                       2, 11),
    HEAL_LOCATION(LAVARIDGE_TOWN,                     9,  7),
    HEAL_LOCATION(FALLARBOR_TOWN,                    14,  8),
    HEAL_LOCATION(VERDANTURF_TOWN,                   16,  4),
    HEAL_LOCATION(PACIFIDLOG_TOWN,                    8, 16),
    HEAL_LOCATION(EVER_GRANDE_CITY,                  18,  6),
    HEAL_LOCATION(SOUTHERN_ISLAND_EXTERIOR,          15, 20),
    HEAL_LOCATION(BATTLE_FRONTIER_OUTSIDE_EAST,       3, 52)
};

#define NUM_HEAL_LOCATIONS (ARRAY_COUNT(sHealLocations))

// .text

static u32 GetHealLocationIndexFromMapGroupAndNum(u16 mapGroup, u16 mapNum)
{
    u32 i;

    for (i = 0; i < NUM_HEAL_LOCATIONS; i++)
    {
        if (sHealLocations[i].group == mapGroup && sHealLocations[i].map == mapNum)
        {
            return i + 1;
        }
    }
    return 0;
}

const struct HealLocation *GetHealLocationPointerFromMapGroupAndNum(u16 mapGroup, u16 mapNum)
{
    u32 loc;

    loc = GetHealLocationIndexFromMapGroupAndNum(mapGroup, mapNum);
    if (loc == 0)
    {
        return NULL;
    }
    return &sHealLocations[loc - 1];
}

const struct HealLocation *GetHealLocationPointer(u32 loc)
{
    if (loc == 0)
    {
        return NULL;
    }
    if (loc > NUM_HEAL_LOCATIONS)
    {
        return NULL;
    }
    return &sHealLocations[loc - 1];
}
