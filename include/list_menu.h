#ifndef GUARD_LIST_MENU_H
#define GUARD_LIST_MENU_H

// Exported type declarations

// Exported RAM declarations

struct ListMenuItem {
    const u8 *unk_00;
    s32 unk_04;
};

struct ListMenu;

struct ListMenuTemplate {
    struct ListMenuItem *unk_00;
    void (* unk_04)(u32, bool8, struct ListMenu *);
    void (* unk_08)(u8, s32, u8);
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u32 unk_14_0:4;
    u32 unk_14_4:4;
    u32 unk_15_0:4;
    u32 unk_15_4:4;
    u32 unk_16_0:1;
    u32 unk_16_1:6;
    u32 unk_16_7:1;
    u32 unk_17_0:6;
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
