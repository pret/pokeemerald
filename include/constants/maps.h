#ifndef GUARD_CONSTANTS_MAPS_H
#define GUARD_CONSTANTS_MAPS_H

#include "map_groups.h"

#define MAP_NONE (0x7F | (0x7F << 8))
#define MAP_UNDEFINED (0xFF | (0xFF << 8))

#define MAP_GROUP(map) (MAP_##map >> 8)
#define MAP_NUM(map) (MAP_##map & 0xFF)

// These groups are used by pokedex_area_screen.c to find wild
// pokemon locations.
#define MAP_GROUP_OVERWORLD_MONS MAP_GROUP(PETALBURG_CITY)
#define MAP_GROUP_SPECIAL_MONS_1 MAP_GROUP(METEOR_FALLS_1F_1R)
#define MAP_GROUP_SPECIAL_MONS_2 MAP_GROUP(SAFARI_ZONE_NORTHWEST)

#endif  // GUARD_CONSTANTS_MAPS_H
