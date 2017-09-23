#include "global.h"
#include "item.h"
#include "items.h"
#include "string_util.h"
#include "text.h"
#include "event_data.h"

extern void ApplyNewEncyprtionKeyToHword(u16* hword, u32 newKey);
extern bool8 InBattlePyramid(void);

extern const u8 gText_PokeBalls[];
extern const u8 gText_Berries[];
extern const u8 gText_Berry[];
extern const u8 gUnknown_085897E4[][28]; // not sure what this one is

bool8 CheckPyramidBagHasItem(u16 itemId, u16 count);
bool8 CheckPyramidBagHasSpace(u16 itemId, u16 count);

enum
{
    ITEMS_POCKET,
    BALLS_POCKET,
    TMHM_POCKET,
    BERRIES_POCKET,
    KEYITEMS_POCKET
};

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
        for (item = 0; item < gBagPockets[pocket].capacity; item++)
            ApplyNewEncyprtionKeyToHword(&(gBagPockets[pocket].itemSlots[item].quantity), newKey);
    }
}

void ApplyNewEncyprtionKeyToBagItems_(u32 newKey) // really GF?
{
    ApplyNewEncyprtionKeyToBagItems(newKey);
}

// TODO: move those max values to defines

void SetBagItemsPointers(void)
{
    gBagPockets[ITEMS_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_Items;
    gBagPockets[ITEMS_POCKET].capacity = 30;

    gBagPockets[KEYITEMS_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_KeyItems;
    gBagPockets[KEYITEMS_POCKET].capacity = 30;

    gBagPockets[BALLS_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_PokeBalls;
    gBagPockets[BALLS_POCKET].capacity = 16;

    gBagPockets[TMHM_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_TMHM;
    gBagPockets[TMHM_POCKET].capacity = 64;

    gBagPockets[BERRIES_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_Berries;
    gBagPockets[BERRIES_POCKET].capacity = 46;
}

void CopyItemName(u16 itemId, u8 *string)
{
    StringCopy(string, ItemId_GetItem(itemId)->name);
}

void CopyItemNameHandlePlural(u16 itemId, u8 *string, u32 quantity)
{
    if (itemId == ITEM_POKE_BALL)
    {
        if (quantity < 2)
            StringCopy(string, ItemId_GetItem(ITEM_POKE_BALL)->name);
        else
            StringCopy(string, gText_PokeBalls);
    }
    else
    {
        if (itemId >= 0x85 && itemId <= 0xAF)
            GetBerryCountString(string, gUnknown_085897E4[itemId], quantity);
        else
            StringCopy(string, ItemId_GetItem(itemId)->name);
    }
}

void GetBerryCountString(u8* dst, const u8* berryName, u32 quantity)
{
    const u8* berryString;
    u8* txtPtr;

    if (quantity < 2)
        berryString = gText_Berry;
    else
        berryString = gText_Berries;
    txtPtr = StringCopy(dst, berryName);
    *txtPtr = CHAR_SPACE;
    StringCopy(txtPtr + 1, berryString);
}

bool8 IsBagPocketNonEmpty(u8 pocket)
{
    u8 i;

    for (i = 0; i < gBagPockets[pocket - 1].capacity; i++)
    {
        if (gBagPockets[pocket - 1].itemSlots[i].itemId != 0)
            return TRUE;
    }
    return FALSE;
}

bool8 CheckBagHasItem(u16 itemId, u16 count)
{
    u8 i;
    u8 pocket;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;
    if (InBattlePyramid() || FlagGet(0x4004) == TRUE)
        return CheckPyramidBagHasItem(itemId, count);
    pocket = ItemId_GetPocket(itemId) - 1;
    //Check for item slots that contain the item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            //Does this item slot contain enough of the item?
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity >= count)
                return TRUE;
            count -= quantity;
            //Does this item slot and all previous slots contain enough of the item?
            if (count == 0)
                return TRUE;
        }
    }
    return FALSE;
}

bool8 HasAtLeastOneBerry(void)
{
    u16 i;
    for (i = 0x85; i < 0xB3; i++)
    {
        if (CheckBagHasItem(i, 1) == TRUE)
        {
            gScriptResult = 1;
            return TRUE;
        }
    }
    gScriptResult = 0;
    return FALSE;
}

/* Refuses to match.
bool8 CheckBagHasSpace(u16 itemId, u16 count)
{
    u8 i;
    u8 pocket;
    u16 slotCapacity;
    u16 quantity;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;
    if (InBattlePyramid() || FlagGet(0x4004) == TRUE)
        return CheckPyramidBagHasSpace(itemId, count);
    pocket = ItemId_GetPocket(itemId) - 1;
    if (pocket != BERRIES_POCKET)
        slotCapacity = 99;
    else
        slotCapacity = 999;

    //Check space in any existing item slots that already contain this item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity + count <= slotCapacity)
                return TRUE;
            if (pocket == TMHM_POCKET || pocket == BERRIES_POCKET)
                return FALSE;
            count -= slotCapacity - quantity;
            if (count == 0)
                return TRUE;
        }
    }

    //Check space in empty item slots
    if (count > 0)
    {
        for (i = 0; i < gBagPockets[pocket].capacity; i++)
        {
            if (gBagPockets[pocket].itemSlots[i].itemId == 0)
            {
                if (count <= slotCapacity)
                    return TRUE;
                if (pocket == TMHM_POCKET || pocket == BERRIES_POCKET)
                    return FALSE;
                count -= slotCapacity;
            }
        }
        if (count > 0)
            return FALSE; //No more item slots. The bag is full
    }

    return TRUE;
}*/
