#ifndef GUARD_LIST_MENU_H
#define GUARD_LIST_MENU_H

// Exported type declarations

// Exported RAM declarations

struct ListMenuItem
{
    const u8 *unk_00;
    s32 unk_04;
};

struct ListMenu;

struct ListMenuTemplate
{
    const struct ListMenuItem *items;
    void (* unk_04)(u32, bool8, struct ListMenu *);
    void (* unk_08)(u8, s32, u8);
    u16 totalItems;
    u16 maxShowed;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 cursor_Y;
    u32 upText_Y:4; // x1, x2, x4, x8 = xF
    u32 cursorColor:4; // x10, x20, x40, x80 = xF0
    u32 fillColor:4; // x100, x200, x400, x800 = xF00
    u32 cursorShadowColor:4; // x1000, x2000, x4000, x8000 = xF000
    u32 unk_16_0:1; // x10000
    u32 spaceBetweenItems:6; // x20000, x40000, x80000, x100000, x200000, x400000 = x7E0000
    u32 unk_16_7:1; // x800000
    u32 unk_17_0:6; // x1000000, x2000000, x4000000, x8000000, x10000000, x20000000 = x3F000000
};

struct ListMenu {
    struct ListMenuTemplate _template;
    u16 scrollOffset;
    u16 selectedRow;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
};

extern struct ListMenuTemplate gUnknown_03006310;

// Exported ROM declarations

u8 ListMenuInit(struct ListMenuTemplate *template, u16 a1, u16 a2);
s32 ListMenuHandleInput(u8 id);
void get_coro_args_x18_x1A(u8 a0, u16 *a1, u16 *a2);
void sub_81AE6C8(u8 a0, u16 *a1, u16 *a2);

#endif //GUARD_LIST_MENU_H
