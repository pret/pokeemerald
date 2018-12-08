#ifndef GUARD_ROULETTE_H
#define GUARD_ROULETTE_H

struct UnkStruct1
{
    u16 var00;
    u16 var02;
    u8 var04;
    u8 var05;
    u8 var06;
    s8 var07_0:5;
    s8 var07_5:2;
    s8 var07_7:1;
};

struct UnkStruct3
{
    u8 var00_0:7;
    u8 var00_7:1;
    u8 var01;
    s8 var02;
    s8 var03;
    struct UnkStruct1 var04;
};

struct UnkStruct0
{
    u8 var00;
    u8 var01;
    u16 var02; //flag for each UnkStruct3
    struct UnkStruct3 var04[0x10];
};

#endif // GUARD_ROULETTE_H
