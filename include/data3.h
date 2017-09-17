//
// Created by Scott Norton on 9/8/17.
//

#ifndef GUARD_DATA3_H
#define GUARD_DATA3_H

struct PairedPalettes {
    u16 tag;
    const u16 *data;
};

extern u8 gUnknown_084975C4[0x10];
extern const struct SpriteTemplate gUnknown_084975D4;
extern void (*const gUnknown_084975EC[3])(struct Sprite *);
extern const struct SpritePalette gUnknown_0850BBC8[];
extern const struct PairedPalettes gUnknown_0850BD00[15];
extern const struct PairedPalettes gUnknown_0850BD78[15];
extern const u16 *const gUnknown_0850BE38[2];
extern const s16 gUnknown_0850D6DC[4]; // {0x20, 0x40, 0x60, 0x80}
extern const s16 gUnknown_0850D6EC[4];
extern const u8 gUnknown_0850D710[4]; // {DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST}
extern const u8 gUnknown_0850D770[2]; // {DIR_SOUTH, DIR_NORTH}
extern const u8 gUnknown_0850D790[2]; // {DIR_WEST, DIR_EAST}
extern const u8 gUnknown_0850D7F0[2]; // {DIR_NORTH, DIR_WEST}
extern const u8 gUnknown_0850D808[2]; // {DIR_NORTH, DIR_EAST}
extern const u8 gUnknown_0850D820[2]; // {DIR_SOUTH, DIR_WEST}
extern const u8 gUnknown_0850D838[2]; // {DIR_SOUTH, DIR_EAST}
extern const u8 gUnknown_0850D850[4];
extern const u8 gUnknown_0850D868[4];
extern const u8 gUnknown_0850D880[4];
extern const u8 gUnknown_0850D898[4];
extern const u8 gUnknown_0850D8AC[5];
extern const u8 gUnknown_0850D8C4[5];
extern const u8 gUnknown_0850D8E8[4];
extern bool8 (*const gUnknown_0850DA64[])(struct MapObject *, struct Sprite *, u8, bool8(u8));
extern bool8 (*const gUnknown_0850DB5C[])(u8);
extern bool8 (*const gUnknown_0850DB6C[])(u8);

extern const u8 gUnknown_0850DBA0[5];

#endif //GUARD_DATA3_H
