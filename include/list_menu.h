#ifndef GUARD_LIST_MENU_H
#define GUARD_LIST_MENU_H

#include "window.h"

#define LIST_NOTHING_CHOSEN -1
#define LIST_CANCEL -2
#define LIST_HEADER -3

enum {
    LIST_NO_MULTIPLE_SCROLL,
    LIST_MULTIPLE_SCROLL_DPAD,
    LIST_MULTIPLE_SCROLL_L_R,
};

enum {
    CURSOR_BLACK_ARROW,
    CURSOR_INVISIBLE,
    CURSOR_RED_OUTLINE,
    CURSOR_RED_ARROW,
};

enum {
    SCROLL_ARROW_LEFT,
    SCROLL_ARROW_RIGHT,
    SCROLL_ARROW_UP,
    SCROLL_ARROW_DOWN
};

// For ListMenuGet/SetTemplateField
enum ListMenuFields
{
    LISTFIELD_MOVECURSORFUNC = 0,
    LISTFIELD_MOVECURSORFUNC2,
    LISTFIELD_TOTALITEMS,
    LISTFIELD_MAXSHOWED,
    LISTFIELD_WINDOWID,
    LISTFIELD_HEADERX,
    LISTFIELD_ITEMX,
    LISTFIELD_CURSORX,
    LISTFIELD_UPTEXTY,
    LISTFIELD_CURSORPAL,
    LISTFIELD_FILLVALUE,
    LISTFIELD_CURSORSHADOWPAL,
    LISTFIELD_LETTERSPACING,
    LISTFIELD_ITEMVERTICALPADDING,
    LISTFIELD_SCROLLMULTIPLE,
    LISTFIELD_FONTID,
    LISTFIELD_CURSORKIND,
};

struct ListMenu;

struct ListMenuItem
{
    const u8 *name;
    s32 id;
};

struct ListMenuTemplate
{
    const struct ListMenuItem *items;
    void (*moveCursorFunc)(s32 itemIndex, bool8 onInit, struct ListMenu *list);
    void (*itemPrintFunc)(u8 windowId, u32 instanceId, u8 y);
    u32 totalItems:12;
    u32 maxShowed:12;
    u32 textNarrowWidth:8;
    u8 windowId;
    u8 header_X;
    u8 item_X;
    u8 cursor_X;
    u8 upText_Y:4; // x1, x2, x4, x8 = xF
    u8 cursorPal:4; // x10, x20, x40, x80 = xF0
    u8 fillValue:4; // x1, x2, x4, x8 = xF
    u8 cursorShadowPal:4; // x10, x20, x40, x80 = xF0
    u8 lettersSpacing:3;
    u8 itemVerticalPadding:3;
    u8 scrollMultiple:2; // x40, x80 = xC0
    u8 fontId:5; // x1, x2, x4, x8, x10 = x1F
    u8 cursorKind:2; // x20, x40
    u8 isDynamic:1; //Dynamic list doesn't store all items in memory but load them from ROM when necessary
};

struct ListMenu
{
    struct ListMenuTemplate template;
    u16 scrollOffset;
    u16 selectedRow;
    u8 unk_1C;
    u8 unk_1D;
    u8 taskId;
    u8 unk_1F;
};

struct ListMenuWindowRect
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 palNum;
};

struct ScrollArrowsTemplate
{
    u8 firstArrowType;
    u8 firstX;
    u8 firstY;
    u8 secondArrowType;
    u8 secondX;
    u8 secondY;
    u16 fullyUpThreshold;
    u16 fullyDownThreshold;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

struct CursorStruct
{
    u8 left;
    u8 top;
    u16 rowWidth;
    u16 rowHeight;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

extern struct ScrollArrowsTemplate gTempScrollArrowTemplate;
extern struct ListMenuTemplate gMultiuseListMenuTemplate;

s32 DoMysteryGiftListMenu(const struct WindowTemplate *windowTemplate, const struct ListMenuTemplate *listMenuTemplate, u8 drawMode, u16 tileNum, u16 palOffset);
u8 ListMenuInit(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow);
s32 ListMenu_ProcessInput(u8 listTaskId);
void DestroyListMenuTask(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow);
void RedrawListMenu(u8 listTaskId);
void ListMenuGetCurrentItemArrayId(u8 listTaskId, u16 *arrayId);
void ListMenuGetScrollAndRow(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow);
u16 ListMenuGetYCoordForPrintingArrowCursor(u8 listTaskId);
void ListMenuDefaultCursorMoveFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
void ListMenuSetTemplateField(u8 taskId, u8 field, s32 value);
u8 AddScrollIndicatorArrowPair(const struct ScrollArrowsTemplate *arrowInfo, u16 *scrollOffset);
u8 AddScrollIndicatorArrowPairParameterized(u32 arrowType, s32 commonPos, s32 firstPos, s32 secondPos, s32 fullyDownThreshold, s32 tileTag, s32 palTag, u16 *scrollOffset);
void RemoveScrollIndicatorArrowPair(u8 taskId);
void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId);
bool8 ListMenuChangeSelection(struct ListMenu *list, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown);
bool8 ListMenuChangeSelectionFull(struct ListMenu *list, bool32 updateCursor, bool32 callCallback, u8 count, bool8 movingDown);

#endif //GUARD_LIST_MENU_H
