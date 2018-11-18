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
s8 GetFirstEmptyDecorSlot(u8 idx);
u8 CheckHasDecoration(u8);
u8 DecorationAdd(u8);
u8 DecorationCheckSpace(u8);
s8 DecorationRemove(u8);
void CondenseDecorationCategoryN(u8);
u8 CountDecorationCategoryN(u8 idx);
u8 CountDecorations(void);

#endif // GUARD_DECORATION_INVENTORY_H
