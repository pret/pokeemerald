#ifndef GUARD_GLOBAL_BERRY_H
#define GUARD_GLOBAL_BERRY_H

struct Berry
{
    /*0x00*/ u8 name[7];
    /*0x07*/ u8 firmness;
    /*0x08*/ u16 size;
    /*0x0A*/ u8 maxYield;
    /*0x0B*/ u8 minYield;
    /*0x0C*/ const u8 *description1;
    /*0x10*/ const u8 *description2;
    /*0x14*/ u8 stageDuration;
    /*0x15*/ u8 spicy;
    /*0x16*/ u8 dry;
    /*0x17*/ u8 sweet;
    /*0x18*/ u8 bitter;
    /*0x19*/ u8 sour;
    /*0x1A*/ u8 smoothness;
};

struct EnigmaBerry
{
    /*0x000*/ struct Berry berry;
    /*0x01B*/ u8 pic[(6 * 6) * TILE_SIZE_4BPP];
    /*0x49C*/ u16 palette[16];
    /*0x4BC*/ u8 description1[45];
    /*0x4E9*/ u8 description2[45];
    /*0x516*/ u8 itemEffect[18];
    /*0x528*/ u8 holdEffect;
    /*0x529*/ u8 holdEffectParam;
    /*0x52C*/ u32 checksum;
};

struct BattleEnigmaBerry
{
    /*0x00*/ u8 name[7];
    /*0x07*/ u8 holdEffect;
    /*0x08*/ u8 itemEffect[18];
    /*0x1A*/ u8 holdEffectParam;
};

struct BerryTree
{
    /*0x00*/ u8 berry;
    /*0x01*/ u8 stage:7;
    /*
        A berry sparkle is a state that a berry tree
        can be in after growing within the player's
        viewport.
    */
    /*0x01*/ bool8 growthSparkle:1;
    /*0x02*/ u16 minutesUntilNextStage;
    /*0x04*/ u8 berryYield;
    /*0x05*/ u8 regrowthCount:4;
    /*0x05*/ u8 watered1:1;
    /*0x05*/ u8 watered2:1;
    /*0x05*/ u8 watered3:1;
    /*0x05*/ u8 watered4:1;
};

#endif // GUARD_GLOBAL_BERRY_H
