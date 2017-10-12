#ifndef GUARD_DECORATION_H
#define GUARD_DECORATION_H

struct Decoration
{
    /*0x00*/ u8 id;
    /*0x01*/ u8 name[16];
    /*0x11*/ u8 permission;
    /*0x12*/ u8 shape;
    /*0x13*/ u8 category;
    /*0x14*/ u16 price;
    /*0x18*/ const u8 *description;
    /*0x1c*/ const u16 *tiles;
};

extern const struct Decoration gDecorations[];

#endif // GUARD_DECORATION_H
