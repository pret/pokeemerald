#ifndef GUARD_LIST_MENU_H
#define GUARD_LIST_MENU_H

// Exported type declarations

// Exported RAM declarations

struct ListMenuItem {
    const u8 *unk_00;
    s32 unk_04;
};

struct ListMenuTemplate {
    struct ListMenuItem *unk_00;
    u8 filler_04[8]; // TODO: Finish this
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10;
    u8 filler_11[7];
};

extern struct ListMenuTemplate gUnknown_03006310;

// Exported ROM declarations

u8 ListMenuInit(struct ListMenuTemplate *template, u16 a1, u16 a2);
s32 ListMenuHandleInput(u8 id);
void get_coro_args_x18_x1A(u8 a0, u16 *a1, u16 *a2);
void sub_81AE6C8(u8 a0, u16 *a1, u16 *a2);

#endif //GUARD_LIST_MENU_H
