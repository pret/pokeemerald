#ifndef GUARD_LIST_MENU_H
#define GUARD_LIST_MENU_H

#define LIST_NOTHING_CHOSEN -1
#define LIST_B_PRESSED -2

#define LIST_NO_MULTIPLE_SCROLL     0
#define LIST_MULTIPLE_SCROLL_DPAD   1
#define LIST_MULTIPLE_SCROLL_L_R    2

struct ListMenu;

struct ListMenuItem
{
    const u8 *name;
    s32 id;
};

struct ListMenuTemplate
{
    const struct ListMenuItem *items;
    void (* moveCursorFunc)(s32, bool8, struct ListMenu *);
    void (* unk_08)(u8 windowId, s32 itemId, u8 y);
    u16 totalItems;
    u16 maxShowed;
    u8 windowId;
    u8 unk_11;
    u8 unk_12;
    u8 cursor_X;
    u8 upText_Y:4; // x1, x2, x4, x8 = xF
    u8 cursorPal:4; // x10, x20, x40, x80 = xF0
    u8 fillValue:4; // x1, x2, x4, x8 = xF
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

struct UnknownListMenuWindowStruct
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 palNum;
};

struct ArrowStruct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u16 unk8;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

struct CursorStruct
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

extern struct ArrowStruct gUnknown_0203CE8C;
extern struct ListMenuTemplate gMultiuseListMenuTemplate;

s32 DoMysteryGiftListMenu(struct WindowTemplate *windowTemplate, struct ListMenuTemplate *listMenuTemplate, u8 arg2, u16 tileNum, u16 palNum);
u8 ListMenuInit(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow);
u8 ListMenuInitWithWindows(struct ListMenuTemplate *listMenuTemplate, struct UnknownListMenuWindowStruct *arg1, u16 scrollOffset, u16 selectedRow);
s32 ListMenuHandleInputGetItemId(u8 listTaskId);
void DestroyListMenuTask(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow);
void sub_81AE70C(u8 listTaskId);
void ChangeListMenuPals(u8 listTaskId, u8 cursorPal, u8 fillValue, u8 cursorShadowPal);
void ChangeListMenuCoords(u8 listTaskId, u8 x, u8 y);
s32 ListMenuTestInput(struct ListMenuTemplate *template, u32 scrollOffset, u32 selectedRow, u16 keys, u16 *newScrollOffset, u16 *newSelectedRow);
void ListMenuGetCurrentItemArrayId(u8 listTaskId, u16 *arrayId);
void ListMenuGetScrollAndRow(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow);
u16 ListMenuGetYCoordForPrintingArrowCursor(u8 listTaskId);
void sub_81AF028(u8 cursorPal, u8 fillValue, u8 cursorShadowPal);
void sub_81AF078(s32 arg0, u8 arg1, struct ListMenu *list);
s32 sub_81AF08C(u8 taskId, u8 field);
void sub_81AF15C(u8 taskId, u8 field, s32 value);
u8 AddScrollIndicatorArrowPair(const struct ArrowStruct *arrowInfo, u16 *arg1);
u8 AddScrollIndicatorArrowPairParametrized(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 tileTag, s32 palTag, void *arg7);
void RemoveScrollIndicatorArrowPair(u8 taskId);
void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId);

#endif //GUARD_LIST_MENU_H
