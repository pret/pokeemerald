#ifndef GUARD_GLOBAL_BERRY_H
#define GUARD_GLOBAL_BERRY_H

#include "constants/hold_effects.h"

#define BERRY_NAME_LENGTH 6
#define BERRY_ITEM_EFFECT_COUNT 18

struct BerryInfo
{
    const u8 name[BERRY_NAME_LENGTH + 1];
    enum BerryFirmness firmness:4;
    enum BerryColor color:4;
    u16 size:10;
    u16 weedsBonus:3;
    u16 pestsBonus:3;
    u8 maxYield;
    u8 minYield:4;
    u8 waterBonus:4;
    const u8 *description1;
    const u8 *description2;
    u8 growthDuration;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 smoothness;
    u8 drainRate;
};

struct Berry
{
    struct BerryInfo info;
    u32 naturalGiftType:6;
    u32 naturalGiftPower:8;
    u32 berryCrushDifficulty:8; // The number of A presses required to crush it
    u32 berryCrushPowder:10;
    const u32 *berryPic;
    const u16 *berryPal;
    const struct SpriteFrameImage *berryTreePicTable;
    const u8 *berryTreePaletteSlotTable;
};

// with no const fields

struct EnigmaBerryInfo
{
    u8 name[BERRY_NAME_LENGTH + 1];
    enum BerryFirmness firmness:4;
    enum BerryColor color:4;
    u16 size:10;
    u16 weedsBonus:3;
    u16 pestsBonus:3;
    u8 maxYield;
    u8 minYield:4;
    u8 waterBonus:4;
    u8 *description1;
    u8 *description2;
    u8 growthDuration;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 smoothness;
    u8 drainRate;
};

struct EnigmaBerry
{
    struct EnigmaBerryInfo berry;
    u8 itemEffect[BERRY_ITEM_EFFECT_COUNT];
    enum HoldEffect holdEffect:8;
    u8 holdEffectParam;
    u32 checksum;
};

struct BattleEnigmaBerry
{
    /*0x00*/ u8 name[BERRY_NAME_LENGTH + 1];
    /*0x07*/ enum HoldEffect holdEffect:8;
    /*0x08*/ u8 itemEffect[BERRY_ITEM_EFFECT_COUNT];
    /*0x1A*/ u8 holdEffectParam;
};

struct BerryTree
{
    u8 berry:7;
    u8 weeds:1;
    u8 stage:3;
    u8 mulch:4;
    u8 stopGrowth:1;
    u16 minutesUntilNextStage:14;
    u16 mutationA:2;
    u8 berryYield:5;
    u8 pests:1;
    u8 mutationB:2;
    u8 regrowthCount:4;
    u8 watered:4; // Used to keep track of bonuses in case of gradient watering
    u16 moistureLevel:7;
    u16 moistureClock:7;
    u16 padding:2;
};

#endif // GUARD_GLOBAL_BERRY_H
