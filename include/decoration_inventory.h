#ifndef GUARD_DECORATION_INVENTORY_H
#define GUARD_DECORATION_INVENTORY_H

struct DecorationInventory
{
    u8 *items;
    u8 size;
};

extern struct DecorationInventory gDecorationInventories[];

void SetDecorationInventoriesPointers(void);
void ClearDecorationInventories(void);
s8 GetFirstEmptyDecorSlot(u8 category);
u8 CheckHasDecoration(u8 decor);
u8 DecorationAdd(u8 decor);
u8 DecorationCheckSpace(u8 decor);
s8 DecorationRemove(u8 decor);
void CondenseDecorationsInCategory(u8 category);
u8 GetNumOwnedDecorationsInCategory(u8 category);
u8 GetNumOwnedDecorations(void);

#endif // GUARD_DECORATION_INVENTORY_H
