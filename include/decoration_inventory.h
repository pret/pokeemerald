#ifndef GUARD_DECORATION_INVENTORY_H
#define GUARD_DECORATION_INVENTORY_H
struct DecorationInventory {
    u8 *items;
    u8 size;
};

extern EWRAM_DATA struct DecorationInventory gDecorationInventories[];

void ClearDecorationInventories(void);
u8 CheckHasDecoration(u8);
u8 DecorationAdd(u8);
u8 DecorationCheckSpace(u8);
s8 DecorationRemove(u8);
void sub_8161A38(u8);

#endif // GUARD_DECORATION_INVENTORY_H
