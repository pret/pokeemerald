#ifndef POKENAV_REGION_MAP_H
#define POKENAV_REGION_MAP_H

#define NUM_CITY_MAPS 22

struct CityMapEntry {
    u16 mapSecId;
    u16 index;
    const u32 *tilemap;
};

#endif