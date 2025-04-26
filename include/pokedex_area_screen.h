#ifndef GUARD_POKEDEX_AREA_SCREEN_H
#define GUARD_POKEDEX_AREA_SCREEN_H


// There are two types of indicators for the area screen to show where a Pokémon can occur:
// - Area glows, which highlight any of the maps in MAP_GROUP_TOWNS_AND_ROUTES that have the species.
//   These are a tilemap with colored rectangular areas that blends in and out. The positions of the
//   rectangles is determined by the positions of the matching MAPSEC values on the region map layout.
// - Area markers, which highlight any of the maps in MAP_GROUP_DUNGEONS or MAP_GROUP_SPECIAL_AREA that
//   have the species. These are circular sprites that flash twice. The positions of the sprites is
//   determined by the data for the corresponding MAPSEC in gRegionMapEntries.

// Only maps in the following map groups have their encounters considered for the area screen
#define MAP_GROUP_TOWNS_AND_ROUTES MAP_GROUP(PETALBURG_CITY)
#define MAP_GROUP_DUNGEONS MAP_GROUP(METEOR_FALLS_1F_1R)
#define MAP_GROUP_SPECIAL_AREA MAP_GROUP(SAFARI_ZONE_NORTHWEST)

#define AREA_SCREEN_WIDTH 32
#define AREA_SCREEN_HEIGHT 20

#define GLOW_FULL      0xFFFF
#define GLOW_EDGE_R    (1 << 0)
#define GLOW_EDGE_L    (1 << 1)
#define GLOW_EDGE_B    (1 << 2)
#define GLOW_EDGE_T    (1 << 3)
#define GLOW_CORNER_TL (1 << 4)
#define GLOW_CORNER_BL (1 << 5)
#define GLOW_CORNER_TR (1 << 6)
#define GLOW_CORNER_BR (1 << 7)

#define GLOW_PALETTE 10

#define TAG_AREA_MARKER 2
#define TAG_AREA_UNKNOWN 3

#define MAX_AREA_HIGHLIGHTS 64 // Maximum number of rectangular route highlights
#define MAX_AREA_MARKERS 32 // Maximum number of circular spot highlights

void ShowPokedexAreaScreen(u16, u8 *);

#endif // GUARD_POKEDEX_AREA_SCREEN_H
