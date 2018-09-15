#ifndef GUARD_ROM_8034C54_H
#define GUARD_ROM_8034C54_H

struct UnkStruct3
{
    u8 field_0_0:2;
    u8 shape:2;
    u8 size:2;
    u8 priority:2;
    u8 field_1;
    u8 xDelta;
    s16 x;
    s16 y;
    const struct SpriteSheet *spriteSheet;
    const struct SpritePalette *spritePal;
};

bool32 sub_8034C54(u32 count);
void sub_8034CC8(void);
bool32 sub_8034D14(u32 id, s32 arg1, const struct UnkStruct3 *arg2);
void sub_8035044(u32 id, s32 arg1);
void sub_80353DC(u32 id);
void sub_803547C(u32 id, bool32 arg1);
u8 sub_80355F8(u32 shape, u32 size);

#endif // GUARD_ROM_8034C54_H
