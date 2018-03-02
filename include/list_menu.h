#ifndef GUARD_LIST_MENU_H
#define GUARD_LIST_MENU_H

#define LIST_NOTHING_CHOSEN -1
#define LIST_B_PRESSED -2

#define LIST_NO_MULTIPLE_SCROLL     0
#define LIST_MULTIPLE_SCROLL_DPAD   1
#define LIST_MULTIPLE_SCROLL_L_R    2

// Exported type declarations

// Exported RAM declarations

struct ListMenuItem
{
    const u8 *name;
    s32 id;
};

struct ListMenu;

struct ListMenuTemplate
{
    const struct ListMenuItem *items;
    void (* moveCursorFunc)(u32, bool8, struct ListMenu *);
    void (* unk_08)(u8 windowId, s32 itemId, u8 y);
    u16 totalItems;
    u16 maxShowed;
    u8 windowId;
    u8 unk_11;
    u8 unk_12;
    u8 cursor_Y;
    u8 upText_Y:4; // x1, x2, x4, x8 = xF
    u8 cursorPal:4; // x10, x20, x40, x80 = xF0
    u8 fillPal:4; // x1, x2, x4, x8 = xF
    u8 cursorShadowPal:4; // x10, x20, x40, x80 = xF0
    u8 lettersSpacing:3;
    u8 unk_16_3:3;
    u8 scrollMultiple:2; // x40, x80 = xC0
    u8 fontId:6; // x1, x2, x4, x8, x10, x20 = x3F
    u8 cursorKind:2; // x40, x80
};

struct ListMenu
{
    struct ListMenuTemplate template;
    u16 scrollOffset;
    u16 selectedRow;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
};

extern struct ListMenuTemplate gMultiuseListMenuTemplate;

// Exported ROM declarations

u8 ListMenuInit(struct ListMenuTemplate *template, u16 scrollOffset, u16 selectedRow);
s32 ListMenuHandleInputGetItemId(u8 listTaskId);
void ListMenuGetScrollAndRow(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow);
void DestroyListMenuTask(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow);
u16 ListMenuGetYCoordForPrintingArrowCursor(u8 listTaskId);

#endif //GUARD_LIST_MENU_H
