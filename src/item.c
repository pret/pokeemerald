#include "global.h"
#include "item.h"
#include "berry.h"
#include "string_util.h"
#include "text.h"
#include "event_data.h"
#include "malloc.h"
#include "secret_base.h"
#include "item_menu.h"
#include "party_menu.h"
#include "strings.h"
#include "load_save.h"
#include "item_use.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/hold_effects.h"

static bool8 CheckPyramidBagHasItem(u16 itemId, u16 count);
static bool8 CheckPyramidBagHasSpace(u16 itemId, u16 count);
static const u8 *ItemId_GetPluralName(u16);
static bool32 DoesItemHavePluralName(u16);

EWRAM_DATA struct BagPocket gBagPockets[POCKETS_COUNT] = {0};

#include "data/pokemon/item_effects.h"
#include "data/items.h"

static u16 GetBagItemQuantity(u16 *quantity)
{
    return gSaveBlock2Ptr->encryptionKey ^ *quantity;
}

static void SetBagItemQuantity(u16 *quantity, u16 newValue)
{
    *quantity =  newValue ^ gSaveBlock2Ptr->encryptionKey;
}

static u16 GetPCItemQuantity(u16 *quantity)
{
    return *quantity;
}

static void SetPCItemQuantity(u16 *quantity, u16 newValue)
{
    *quantity = newValue;
}

void ApplyNewEncryptionKeyToBagItems(u32 newKey)
{
    u32 pocket, item;
    for (pocket = 0; pocket < POCKETS_COUNT; pocket++)
    {
        for (item = 0; item < gBagPockets[pocket].capacity; item++)
            ApplyNewEncryptionKeyToHword(&(gBagPockets[pocket].itemSlots[item].quantity), newKey);
    }
}

void ApplyNewEncryptionKeyToBagItems_(u32 newKey) // really GF?
{
    ApplyNewEncryptionKeyToBagItems(newKey);
}

void SetBagItemsPointers(void)
{
    gBagPockets[ITEMS_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_Items;
    gBagPockets[ITEMS_POCKET].capacity = BAG_ITEMS_COUNT;

    gBagPockets[KEYITEMS_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_KeyItems;
    gBagPockets[KEYITEMS_POCKET].capacity = BAG_KEYITEMS_COUNT;

    gBagPockets[BALLS_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_PokeBalls;
    gBagPockets[BALLS_POCKET].capacity = BAG_POKEBALLS_COUNT;

    gBagPockets[TMHM_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_TMHM;
    gBagPockets[TMHM_POCKET].capacity = BAG_TMHM_COUNT;

    gBagPockets[BERRIES_POCKET].itemSlots = gSaveBlock1Ptr->bagPocket_Berries;
    gBagPockets[BERRIES_POCKET].capacity = BAG_BERRIES_COUNT;
}

u8 *CopyItemName(u16 itemId, u8 *dst)
{
    return StringCopy(dst, ItemId_GetName(itemId));
}

const u8 sText_s[] =_("s");

u8 *CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity)
{
    if (quantity == 1)
    {
        return StringCopy(dst, ItemId_GetName(itemId));
    }
    else if (DoesItemHavePluralName(itemId))
    {
        return StringCopy(dst, ItemId_GetPluralName(itemId));
    }
    else
    {
        u8 *end = StringCopy(dst, ItemId_GetName(itemId));
        return StringCopy(end, sText_s);
    }
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
    if (InBattlePyramid() || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        return CheckPyramidBagHasItem(itemId, count);
    pocket = ItemId_GetPocket(itemId) - 1;
    // Check for item slots that contain the item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            // Does this item slot contain enough of the item?
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity >= count)
                return TRUE;
            count -= quantity;
            // Does this item slot and all previous slots contain enough of the item?
            if (count == 0)
                return TRUE;
        }
    }
    return FALSE;
}

bool8 HasAtLeastOneBerry(void)
{
    u16 i;

    for (i = FIRST_BERRY_INDEX; i <= LAST_BERRY_INDEX; i++)
    {
        if (CheckBagHasItem(i, 1) == TRUE)
        {
            gSpecialVar_Result = TRUE;
            return TRUE;
        }
    }
    gSpecialVar_Result = FALSE;
    return FALSE;
}

bool8 CheckBagHasSpace(u16 itemId, u16 count)
{
    if (ItemId_GetPocket(itemId) == POCKET_NONE)
        return FALSE;

    if (InBattlePyramid() || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        return CheckPyramidBagHasSpace(itemId, count);

    return GetFreeSpaceForItemInBag(itemId) >= count;
}

u32 GetFreeSpaceForItemInBag(u16 itemId)
{
    u8 i;
    u8 pocket = ItemId_GetPocket(itemId) - 1;
    u16 ownedCount;
    u32 spaceForItem = 0;

    if (ItemId_GetPocket(itemId) == POCKET_NONE)
        return 0;

    // Check space in any existing item slots that already contain this item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            ownedCount = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            spaceForItem += max(0, MAX_BAG_ITEM_CAPACITY - ownedCount);
        }
        else if (gBagPockets[pocket].itemSlots[i].itemId == ITEM_NONE)
        {
            spaceForItem += MAX_BAG_ITEM_CAPACITY;
        }
    }
    return spaceForItem;
}

bool8 AddBagItem(u16 itemId, u16 count)
{
    u8 i;

    if (ItemId_GetPocket(itemId) == POCKET_NONE)
        return FALSE;

    // check Battle Pyramid Bag
    if (InBattlePyramid() || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
    {
        return AddPyramidBagItem(itemId, count);
    }
    else
    {
        struct BagPocket *itemPocket;
        struct ItemSlot *newItems;
        u16 ownedCount;
        u8 pocket = ItemId_GetPocket(itemId) - 1;

        itemPocket = &gBagPockets[pocket];
        newItems = AllocZeroed(itemPocket->capacity * sizeof(struct ItemSlot));
        memcpy(newItems, itemPocket->itemSlots, itemPocket->capacity * sizeof(struct ItemSlot));

        for (i = 0; i < itemPocket->capacity; i++)
        {
            if (newItems[i].itemId == itemId)
            {
                ownedCount = GetBagItemQuantity(&newItems[i].quantity);
                // check if won't exceed max slot capacity
                if (ownedCount + count <= MAX_BAG_ITEM_CAPACITY)
                {
                    // successfully added to already existing item's count
                    SetBagItemQuantity(&newItems[i].quantity, ownedCount + count);
                    memcpy(itemPocket->itemSlots, newItems, itemPocket->capacity * sizeof(struct ItemSlot));
                    Free(newItems);
                    return TRUE;
                }
                else
                {
                    // try creating another instance of the item if possible
                    if (pocket == TMHM_POCKET || pocket == BERRIES_POCKET)
                    {
                        Free(newItems);
                        return FALSE;
                    }
                    else
                    {
                        count -= MAX_BAG_ITEM_CAPACITY - ownedCount;
                        SetBagItemQuantity(&newItems[i].quantity, MAX_BAG_ITEM_CAPACITY);
                        // don't create another instance of the item if it's at max slot capacity and count is equal to 0
                        if (count == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }

        // we're done if quantity is equal to 0
        if (count > 0)
        {
            // either no existing item was found or we have to create another instance, because the capacity was exceeded
            for (i = 0; i < itemPocket->capacity; i++)
            {
                if (newItems[i].itemId == ITEM_NONE)
                {
                    newItems[i].itemId = itemId;
                    if (count > MAX_BAG_ITEM_CAPACITY)
                    {
                        // try creating a new slot with max capacity if duplicates are possible
                        if (pocket == TMHM_POCKET || pocket == BERRIES_POCKET)
                        {
                            Free(newItems);
                            return FALSE;
                        }
                        count -= MAX_BAG_ITEM_CAPACITY;
                        SetBagItemQuantity(&newItems[i].quantity, MAX_BAG_ITEM_CAPACITY);
                    }
                    else
                    {
                        // created a new slot and added quantity
                        SetBagItemQuantity(&newItems[i].quantity, count);
                        count = 0;
                        break;
                    }
                }
            }

            if (count > 0)
            {
                Free(newItems);
                return FALSE;
            }
        }
        memcpy(itemPocket->itemSlots, newItems, itemPocket->capacity * sizeof(struct ItemSlot));
        Free(newItems);
        return TRUE;
    }
}

bool8 RemoveBagItem(u16 itemId, u16 count)
{
    u8 i;
    u16 totalQuantity = 0;

    if (ItemId_GetPocket(itemId) == POCKET_NONE || itemId == ITEM_NONE)
        return FALSE;

    // check Battle Pyramid Bag
    if (InBattlePyramid() || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
    {
        return RemovePyramidBagItem(itemId, count);
    }
    else
    {
        u8 pocket;
        u8 var;
        u16 ownedCount;
        struct BagPocket *itemPocket;

        pocket = ItemId_GetPocket(itemId) - 1;
        itemPocket = &gBagPockets[pocket];

        for (i = 0; i < itemPocket->capacity; i++)
        {
            if (itemPocket->itemSlots[i].itemId == itemId)
                totalQuantity += GetBagItemQuantity(&itemPocket->itemSlots[i].quantity);
        }

        if (totalQuantity < count)
            return FALSE;   // We don't have enough of the item

        if (CurMapIsSecretBase() == TRUE)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_BAG);
            VarSet(VAR_SECRET_BASE_LAST_ITEM_USED, itemId);
        }

        var = GetItemListPosition(pocket);
        if (itemPocket->capacity > var
         && itemPocket->itemSlots[var].itemId == itemId)
        {
            ownedCount = GetBagItemQuantity(&itemPocket->itemSlots[var].quantity);
            if (ownedCount >= count)
            {
                SetBagItemQuantity(&itemPocket->itemSlots[var].quantity, ownedCount - count);
                count = 0;
            }
            else
            {
                count -= ownedCount;
                SetBagItemQuantity(&itemPocket->itemSlots[var].quantity, 0);
            }

            if (GetBagItemQuantity(&itemPocket->itemSlots[var].quantity) == 0)
                itemPocket->itemSlots[var].itemId = ITEM_NONE;

            if (count == 0)
                return TRUE;
        }

        for (i = 0; i < itemPocket->capacity; i++)
        {
            if (itemPocket->itemSlots[i].itemId == itemId)
            {
                ownedCount = GetBagItemQuantity(&itemPocket->itemSlots[i].quantity);
                if (ownedCount >= count)
                {
                    SetBagItemQuantity(&itemPocket->itemSlots[i].quantity, ownedCount - count);
                    count = 0;
                }
                else
                {
                    count -= ownedCount;
                    SetBagItemQuantity(&itemPocket->itemSlots[i].quantity, 0);
                }

                if (GetBagItemQuantity(&itemPocket->itemSlots[i].quantity) == 0)
                    itemPocket->itemSlots[i].itemId = ITEM_NONE;

                if (count == 0)
                    return TRUE;
            }
        }
        return TRUE;
    }
}

u8 GetPocketByItemId(u16 itemId)
{
    return ItemId_GetPocket(itemId);
}

void ClearItemSlots(struct ItemSlot *itemSlots, u8 itemCount)
{
    u16 i;

    for (i = 0; i < itemCount; i++)
    {
        itemSlots[i].itemId = ITEM_NONE;
        SetBagItemQuantity(&itemSlots[i].quantity, 0);
    }
}

static s32 FindFreePCItemSlot(void)
{
    s8 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId == ITEM_NONE)
            return i;
    }
    return -1;
}

u8 CountUsedPCItemSlots(void)
{
    u8 usedSlots = 0;
    u8 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId != ITEM_NONE)
            usedSlots++;
    }
    return usedSlots;
}

bool8 CheckPCHasItem(u16 itemId, u16 count)
{
    u8 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId == itemId && GetPCItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity) >= count)
            return TRUE;
    }
    return FALSE;
}

bool8 AddPCItem(u16 itemId, u16 count)
{
    u8 i;
    s8 freeSlot;
    u16 ownedCount;
    struct ItemSlot *newItems;

    // Copy PC items
    newItems = AllocZeroed(sizeof(gSaveBlock1Ptr->pcItems));
    memcpy(newItems, gSaveBlock1Ptr->pcItems, sizeof(gSaveBlock1Ptr->pcItems));

    // Use any item slots that already contain this item
    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (newItems[i].itemId == itemId)
        {
            ownedCount = GetPCItemQuantity(&newItems[i].quantity);
            if (ownedCount + count <= MAX_PC_ITEM_CAPACITY)
            {
                SetPCItemQuantity(&newItems[i].quantity, ownedCount + count);
                memcpy(gSaveBlock1Ptr->pcItems, newItems, sizeof(gSaveBlock1Ptr->pcItems));
                Free(newItems);
                return TRUE;
            }
            count += ownedCount - MAX_PC_ITEM_CAPACITY;
            SetPCItemQuantity(&newItems[i].quantity, MAX_PC_ITEM_CAPACITY);
            if (count == 0)
            {
                memcpy(gSaveBlock1Ptr->pcItems, newItems, sizeof(gSaveBlock1Ptr->pcItems));
                Free(newItems);
                return TRUE;
            }
        }
    }

    // Put any remaining items into a new item slot.
    if (count > 0)
    {
        freeSlot = FindFreePCItemSlot();
        if (freeSlot == -1)
        {
            Free(newItems);
            return FALSE;
        }
        else
        {
            newItems[freeSlot].itemId = itemId;
            SetPCItemQuantity(&newItems[freeSlot].quantity, count);
        }
    }

    // Copy items back to the PC
    memcpy(gSaveBlock1Ptr->pcItems, newItems, sizeof(gSaveBlock1Ptr->pcItems));
    Free(newItems);
    return TRUE;
}

void RemovePCItem(u8 index, u16 count)
{
    gSaveBlock1Ptr->pcItems[index].quantity -= count;
    if (gSaveBlock1Ptr->pcItems[index].quantity == 0)
    {
        gSaveBlock1Ptr->pcItems[index].itemId = ITEM_NONE;
        CompactPCItems();
    }
}

void CompactPCItems(void)
{
    u16 i;
    u16 j;

    for (i = 0; i < PC_ITEMS_COUNT - 1; i++)
    {
        for (j = i + 1; j < PC_ITEMS_COUNT; j++)
        {
            if (gSaveBlock1Ptr->pcItems[i].itemId == 0)
            {
                struct ItemSlot temp = gSaveBlock1Ptr->pcItems[i];
                gSaveBlock1Ptr->pcItems[i] = gSaveBlock1Ptr->pcItems[j];
                gSaveBlock1Ptr->pcItems[j] = temp;
            }
        }
    }
}

void SwapRegisteredBike(void)
{
    switch (gSaveBlock1Ptr->registeredItem)
    {
    case ITEM_MACH_BIKE:
        gSaveBlock1Ptr->registeredItem = ITEM_ACRO_BIKE;
        break;
    case ITEM_ACRO_BIKE:
        gSaveBlock1Ptr->registeredItem = ITEM_MACH_BIKE;
        break;
    }
}

u16 BagGetItemIdByPocketPosition(u8 pocketId, u16 pocketPos)
{
    return gBagPockets[pocketId - 1].itemSlots[pocketPos].itemId;
}

u16 BagGetQuantityByPocketPosition(u8 pocketId, u16 pocketPos)
{
    return GetBagItemQuantity(&gBagPockets[pocketId - 1].itemSlots[pocketPos].quantity);
}

static void SwapItemSlots(struct ItemSlot *a, struct ItemSlot *b)
{
    struct ItemSlot temp;
    SWAP(*a, *b, temp);
}

void CompactItemsInBagPocket(struct BagPocket *bagPocket)
{
    u16 i, j;

    for (i = 0; i < bagPocket->capacity - 1; i++)
    {
        for (j = i + 1; j < bagPocket->capacity; j++)
        {
            if (GetBagItemQuantity(&bagPocket->itemSlots[i].quantity) == 0)
                SwapItemSlots(&bagPocket->itemSlots[i], &bagPocket->itemSlots[j]);
        }
    }
}

void SortBerriesOrTMHMs(struct BagPocket *bagPocket)
{
    u16 i, j;

    for (i = 0; i < bagPocket->capacity - 1; i++)
    {
        for (j = i + 1; j < bagPocket->capacity; j++)
        {
            if (GetBagItemQuantity(&bagPocket->itemSlots[i].quantity) != 0)
            {
                if (GetBagItemQuantity(&bagPocket->itemSlots[j].quantity) == 0)
                    continue;
                if (bagPocket->itemSlots[i].itemId <= bagPocket->itemSlots[j].itemId)
                    continue;
            }
            SwapItemSlots(&bagPocket->itemSlots[i], &bagPocket->itemSlots[j]);
        }
    }
}

void MoveItemSlotInList(struct ItemSlot* itemSlots_, u32 from, u32 to_)
{
    // dumb assignments needed to match
    struct ItemSlot *itemSlots = itemSlots_;
    u32 to = to_;

    if (from != to)
    {
        s16 i, count;
        struct ItemSlot firstSlot = itemSlots[from];

        if (to > from)
        {
            to--;
            for (i = from, count = to; i < count; i++)
                itemSlots[i] = itemSlots[i + 1];
        }
        else
        {
            for (i = from, count = to; i > count; i--)
                itemSlots[i] = itemSlots[i - 1];
        }
        itemSlots[to] = firstSlot;
    }
}

void ClearBag(void)
{
    u16 i;

    for (i = 0; i < POCKETS_COUNT; i++)
    {
        ClearItemSlots(gBagPockets[i].itemSlots, gBagPockets[i].capacity);
    }
}

u16 CountTotalItemQuantityInBag(u16 itemId)
{
    u16 i;
    u16 ownedCount = 0;
    struct BagPocket *bagPocket = &gBagPockets[ItemId_GetPocket(itemId) - 1];

    for (i = 0; i < bagPocket->capacity; i++)
    {
        if (bagPocket->itemSlots[i].itemId == itemId)
            ownedCount += GetBagItemQuantity(&bagPocket->itemSlots[i].quantity);
    }

    return ownedCount;
}

static bool8 CheckPyramidBagHasItem(u16 itemId, u16 count)
{
    u8 i;
    u16 *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#endif

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (items[i] == itemId)
        {
            if (quantities[i] >= count)
                return TRUE;

            count -= quantities[i];
            if (count == 0)
                return TRUE;
        }
    }

    return FALSE;
}

static bool8 CheckPyramidBagHasSpace(u16 itemId, u16 count)
{
    u8 i;
    u16 *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#endif

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (items[i] == itemId || items[i] == ITEM_NONE)
        {
            if (quantities[i] + count <= MAX_PYRAMID_BAG_ITEM_CAPACITY)
                return TRUE;

            count = (quantities[i] + count) - MAX_PYRAMID_BAG_ITEM_CAPACITY;
            if (count == 0)
                return TRUE;
        }
    }

    return FALSE;
}

bool8 AddPyramidBagItem(u16 itemId, u16 count)
{
    u16 i;

    u16 *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
    u16 *newItems = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));

#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
    u16 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
    u8 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
#endif

    memcpy(newItems, items, PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));
    memcpy(newQuantities, quantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (newItems[i] == itemId && newQuantities[i] < MAX_PYRAMID_BAG_ITEM_CAPACITY)
        {
            newQuantities[i] += count;
            if (newQuantities[i] > MAX_PYRAMID_BAG_ITEM_CAPACITY)
            {
                count = newQuantities[i] - MAX_PYRAMID_BAG_ITEM_CAPACITY;
                newQuantities[i] = MAX_PYRAMID_BAG_ITEM_CAPACITY;
            }
            else
            {
                count = 0;
            }

            if (count == 0)
                break;
        }
    }

    if (count > 0)
    {
        for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
        {
            if (newItems[i] == ITEM_NONE)
            {
                newItems[i] = itemId;
                newQuantities[i] = count;
                if (newQuantities[i] > MAX_PYRAMID_BAG_ITEM_CAPACITY)
                {
                    count = newQuantities[i] - MAX_PYRAMID_BAG_ITEM_CAPACITY;
                    newQuantities[i] = MAX_PYRAMID_BAG_ITEM_CAPACITY;
                }
                else
                {
                    count = 0;
                }

                if (count == 0)
                    break;
            }
        }
    }

    if (count == 0)
    {
        memcpy(items, newItems, PYRAMID_BAG_ITEMS_COUNT * sizeof(*items));
        memcpy(quantities, newQuantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(*quantities));
        Free(newItems);
        Free(newQuantities);
        return TRUE;
    }
    else
    {
        Free(newItems);
        Free(newQuantities);
        return FALSE;
    }
}

bool8 RemovePyramidBagItem(u16 itemId, u16 count)
{
    u16 i;

    u16 *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#endif

    i = gPyramidBagMenuState.cursorPosition + gPyramidBagMenuState.scrollPosition;
    if (items[i] == itemId && quantities[i] >= count)
    {
        quantities[i] -= count;
        if (quantities[i] == 0)
            items[i] = ITEM_NONE;
        return TRUE;
    }
    else
    {
        u16 *newItems = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));
    #if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
        u16 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
    #else
        u8 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
    #endif

        memcpy(newItems, items, PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));
        memcpy(newQuantities, quantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));

        for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
        {
            if (newItems[i] == itemId)
            {
                if (newQuantities[i] >= count)
                {
                    newQuantities[i] -= count;
                    count = 0;
                    if (newQuantities[i] == 0)
                        newItems[i] = ITEM_NONE;
                }
                else
                {
                    count -= newQuantities[i];
                    newQuantities[i] = 0;
                    newItems[i] = ITEM_NONE;
                }

                if (count == 0)
                    break;
            }
        }

        if (count == 0)
        {
            memcpy(items, newItems, PYRAMID_BAG_ITEMS_COUNT * sizeof(*items));
            memcpy(quantities, newQuantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(*quantities));
            Free(newItems);
            Free(newQuantities);
            return TRUE;
        }
        else
        {
            Free(newItems);
            Free(newQuantities);
            return FALSE;
        }
    }
}

static u16 SanitizeItemId(u16 itemId)
{
    if (itemId >= ITEMS_COUNT)
        return ITEM_NONE;
    else
        return itemId;
}

const u8 *ItemId_GetName(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].name;
}

u32 ItemId_GetPrice(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].price;
}

static bool32 DoesItemHavePluralName(u16 itemId)
{
    return (gItemsInfo[SanitizeItemId(itemId)].pluralName[0] != '\0');
}

static const u8 *ItemId_GetPluralName(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pluralName;
}

const u8 *ItemId_GetEffect(u32 itemId)
{
    if (itemId == ITEM_ENIGMA_BERRY_E_READER)
    #if FREE_ENIGMA_BERRY == FALSE
        return gSaveBlock1Ptr->enigmaBerry.itemEffect;
    #else
        return 0;
    #endif //FREE_ENIGMA_BERRY
    else
        return gItemsInfo[SanitizeItemId(itemId)].effect;
}

u32 ItemId_GetHoldEffect(u32 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].holdEffect;
}

u32 ItemId_GetHoldEffectParam(u32 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].holdEffectParam;
}

const u8 *ItemId_GetDescription(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].description;
}

u8 ItemId_GetImportance(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].importance;
}

u8 ItemId_GetPocket(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pocket;
}

u8 ItemId_GetType(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].type;
}

ItemUseFunc ItemId_GetFieldFunc(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].fieldUseFunc;
}

// Returns an item's battle effect script ID.
u8 ItemId_GetBattleUsage(u16 itemId)
{
    u16 item = SanitizeItemId(itemId);
    // Handle E-Reader berries.
    if (item == ITEM_ENIGMA_BERRY_E_READER)
    {
        switch (GetItemEffectType(gSpecialVar_ItemId))
        {
            case ITEM_EFFECT_X_ITEM:
                return EFFECT_ITEM_INCREASE_STAT;
            case ITEM_EFFECT_HEAL_HP:
                return EFFECT_ITEM_RESTORE_HP;
            case ITEM_EFFECT_CURE_POISON:
            case ITEM_EFFECT_CURE_SLEEP:
            case ITEM_EFFECT_CURE_BURN:
            case ITEM_EFFECT_CURE_FREEZE_FROSTBITE:
            case ITEM_EFFECT_CURE_PARALYSIS:
            case ITEM_EFFECT_CURE_ALL_STATUS:
            case ITEM_EFFECT_CURE_CONFUSION:
            case ITEM_EFFECT_CURE_INFATUATION:
                return EFFECT_ITEM_CURE_STATUS;
            case ITEM_EFFECT_HEAL_PP:
                return EFFECT_ITEM_RESTORE_PP;
            default:
                return 0;
        }
    }
    else
        return gItemsInfo[item].battleUsage;
}

u8 ItemId_GetSecondaryId(u16 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].secondaryId;
}

u32 ItemId_GetFlingPower(u32 itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].flingPower;
}


u32 GetItemStatus1Mask(u16 itemId)
{
    const u8 *effect = ItemId_GetEffect(itemId);
    switch (effect[3])
    {
        case ITEM3_PARALYSIS:
            return STATUS1_PARALYSIS;
        case ITEM3_FREEZE:
            return STATUS1_FREEZE | STATUS1_FROSTBITE;
        case ITEM3_BURN:
            return STATUS1_BURN;
        case ITEM3_POISON:
            return STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER;
        case ITEM3_SLEEP:
            return STATUS1_SLEEP;
        case ITEM3_STATUS_ALL:
            return STATUS1_ANY | STATUS1_TOXIC_COUNTER;
    }
    return 0;
}

u32 GetItemStatus2Mask(u16 itemId)
{
    const u8 *effect = ItemId_GetEffect(itemId);
    if (effect[3] & ITEM3_STATUS_ALL)
        return STATUS2_INFATUATION | STATUS2_CONFUSION;
    else if (effect[0] & ITEM0_INFATUATION)
        return STATUS2_INFATUATION;
    else if (effect[3] & ITEM3_CONFUSION)
        return STATUS2_CONFUSION;
    else
        return 0;
}
