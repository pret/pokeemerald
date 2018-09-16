#ifndef GUARD_ROM_81520A8_H
#define GUARD_ROM_81520A8_H

struct UnkStruct_81520A8
{
    struct OamData oam;
    s16 x;
    s16 y;
    s16 xDelta;
    s16 yDelta;
    u16 tileTag;
    u16 palTag;
    u16 tileNum;
    u8 id;
    u8 filler17; // Unused.
    u8 unk18;
    u8 unk19_0:1;
    u8 unk19_1:1;
    u8 unk19_2:1;
    u8 priority:2;
    s16 data[8];
    void (*callback)(struct UnkStruct_81520A8 *);
};

bool32 sub_81521C0(u8 count);
bool32 sub_8152254(void);
bool32 sub_81522D4(void);
u8 sub_8152438(u8 id, void (*func)(struct UnkStruct_81520A8 *));
u8 sub_8152474(u8 id, u8 dataArrayId, s16 dataValue);
u8 sub_81524C4(const struct OamData *oam, u16 tileTag, u16 palTag, s16 x, s16 y, u8 arg5, u8 priority);
u8 sub_81525D0(u8 id);

#endif // GUARD_ROM_81520A8_H
