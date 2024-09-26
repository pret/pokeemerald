#ifndef GUARD_HEAL_LOCATION_H
#define GUARD_HEAL_LOCATION_H

struct HealLocation
{
    s8 mapGroup;
    s8 mapNum;
    u16 x;
    u16 y;
};

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum);
const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum);
const struct HealLocation *GetHealLocation(u32 index);

#endif // GUARD_HEAL_LOCATION_H
