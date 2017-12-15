#ifndef GUARD_DECORATION_H
#define GUARD_DECORATION_H

enum DecorPerm {
    /*
     * The nomenclature here describes collision and placement permissions, in that order.
     */
    DECORPERM_SOLID_FLOOR,
    DECORPERM_PASS_FLOOR,
    DECORPERM_BEHIND_FLOOR,
    DECORPERM_NA_WALL,
    DECORPERM_SOLID_MAT
};

enum DecorShape {
    /*
     * Width-x-height
     */
    DECORSHAPE_1x1,
    DECORSHAPE_2x1,
    DECORSHAPE_3x1, // unused
    DECORSHAPE_4x2,
    DECORSHAPE_2x2,
    DECORSHAPE_1x2,
    DECORSHAPE_1x3, // unused
    DECORSHAPE_2x4,
    DECORSHAPE_3x3,
    DECORSHAPE_3x2
};

enum DecorCat {
    /*
     * In which category you can find the decoration in the PC.
     */
    /*0*/ DECORCAT_DESK,
    /*1*/ DECORCAT_CHAIR,
    /*2*/ DECORCAT_PLANT,
    /*3*/ DECORCAT_ORNAMENT,
    /*4*/ DECORCAT_MAT,
    /*5*/ DECORCAT_POSTER,
    /*6*/ DECORCAT_DOLL,
    /*7*/ DECORCAT_CUSHION
};

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

struct DecorPCPointers
{
    /* 0x00 */ u8 *items;
    /* 0x04 */ u8 *pos;
    /* 0x08 */ u8 size;
    /* 0x09 */ u8 isPlayerRoom;
};

extern const struct Decoration gDecorations[];
extern EWRAM_DATA u8 *gCurDecorInventoryItems;
extern EWRAM_DATA u8 gCurDecorationIndex;

void sub_8126968(void);
void sub_8126AD8(u8 taskId);
void sub_8127D38(u16 mapX, u16 mapY, u16 decor);

#endif //GUARD_DECORATION_H
