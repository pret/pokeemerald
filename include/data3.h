//
// Created by Scott Norton on 9/8/17.
//

#ifndef POKEEMERALD_DATA3_H
#define POKEEMERALD_DATA3_H

struct PairedPalettes {
    u16 tag;
    const u16 *data;
};

extern const struct SpritePalette gUnknown_0850BBC8[];
extern const struct PairedPalettes gUnknown_0850BD00[15];
extern const struct PairedPalettes gUnknown_0850BD78[15];
extern u8 gUnknown_084975C4[0x10];
extern const struct SpriteTemplate gUnknown_084975D4;
extern void (*const gUnknown_084975EC[3])(struct Sprite *);

#endif //POKEEMERALD_DATA3_H
