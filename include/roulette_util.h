#ifndef GUARD_ROULETTE_UTIL_H
#define GUARD_ROULETTE_UTIL_H

struct InnerStruct203CF18_3
{
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    s8 unk7_0:4;
    s8 unk7_4:2;
    s8 unk7_6:1;
    s8 unk7_7:1;
};

struct InnerStruct203CF18_2
{
    u8 unk0;
    u8 unk1_0:4;
    u8 unk1_4:1;
    s8 unk1_5:1;
    s8 unk1_6:1;
    u32 unk1_7:1;
    u8 unk2;
    u8 unk3;
    struct InnerStruct203CF18_3 unk4;
};

// structures
struct InnerStruct203CF18
{
    u16 unk0;
    struct InnerStruct203CF18_2 unk4[16];
};

int sub_8151B68(struct InnerStruct203CF18 *, const struct InnerStruct203CF18_3 *);
void sub_8151B3C(struct InnerStruct203CF18 *);
void sub_8151CA8(struct InnerStruct203CF18 *, u16, u8);
void sub_8151C50(struct InnerStruct203CF18 *, u16, u8);
void sub_8151D28(struct InnerStruct203CF18 *, u16, u8);
void sub_8151E50(struct InnerStruct203CF18 *);
void sub_8152008(u16 *dest, u16 src, u8 left, u8 top, u8 width, u8 height);
void sub_8152058(u16 *dest, u16 *src, u8 left, u8 top, u8 width, u8 height);

#endif // GUARD_ROULETTE_UTIL_H
