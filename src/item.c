#include "global.h"
#include "item.h"

extern void ApplyNewEncyprtionKeyToHword(u16* hword, u32 newKey);

enum
{
    ITEMS_POCKET,
    BALLS_POCKET,
    TMHM_POCKET,
    BERRIES_POCKET,
    KEYITEMS_POCKET
};

struct BagItem
{
    struct ItemSlot (*items)[];
    u8 maxPerPocket;
};

extern struct BagItem gBagItems[];

u16 GetBagItemQuantity(u16* quantity)
{
    return gSaveBlock2Ptr->encryptionKey ^ *quantity;
}

void SetBagItemQuantity(u16* quantity, u16 newValue)
{
    *quantity =  newValue ^ gSaveBlock2Ptr->encryptionKey;
}

u16 GetBagItemId(u16* slot)
{
    return *slot;
}

void SetBagItemId(u16* slot, u16 newItemId)
{
    *slot = newItemId;
}

void ApplyNewEncyprtionKeyToBagItems(u32 newKey)
{
    u32 pocket, item;
    for (pocket = 0; pocket < 5; pocket++)
    {
        for (item = 0; item < gBagItems[pocket].maxPerPocket; item++)
            ApplyNewEncyprtionKeyToHword(&((*gBagItems[pocket].items)[item].quantity), newKey);
    }
}

void ApplyNewEncyprtionKeyToBagItems_(u32 newKey) // really GF?
{
    ApplyNewEncyprtionKeyToBagItems(newKey);
}

// TODO: move those max values to defines

void SetBagItemsPointers(void)
{
    gBagItems[ITEMS_POCKET].items = &gSaveBlock1Ptr->bagPocket_Items;
    gBagItems[ITEMS_POCKET].maxPerPocket = 30;

    gBagItems[KEYITEMS_POCKET].items = &gSaveBlock1Ptr->bagPocket_KeyItems;
    gBagItems[KEYITEMS_POCKET].maxPerPocket = 30;

    gBagItems[BALLS_POCKET].items = &gSaveBlock1Ptr->bagPocket_PokeBalls;
    gBagItems[BALLS_POCKET].maxPerPocket = 16;

    gBagItems[TMHM_POCKET].items = &gSaveBlock1Ptr->bagPocket_TMHM;
    gBagItems[TMHM_POCKET].maxPerPocket = 64;

    gBagItems[BERRIES_POCKET].items = &gSaveBlock1Ptr->bagPocket_Berries;
    gBagItems[BERRIES_POCKET].maxPerPocket = 46;
}
