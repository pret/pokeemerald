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
#include "random.h"
#include "item_icon.h"
#include "pokemon_summary_screen.h"
#include "menu.h"
#include "party_menu.h"
#include "overworld.h"
#include "event_data.h"
#include "bw_summary_screen.h"

static bool8 CheckPyramidBagHasItem(u16 itemId, u16 count);
static bool8 CheckPyramidBagHasSpace(u16 itemId, u16 count);
static void ShowItemIconSprite(u16 item, bool8 firstTime, bool8 flash);
static void DestroyItemIconSprite(void);
static const u8 *ItemId_GetPluralName(u16);
static bool32 DoesItemHavePluralName(u16);

EWRAM_DATA struct BagPocket gBagPockets[POCKETS_COUNT] = {0};
EWRAM_DATA static u8 sHeaderBoxWindowId = 0;
EWRAM_DATA u8 sItemIconSpriteId = 0;
EWRAM_DATA u8 sItemIconSpriteId2 = 0;

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

void CopyItemName(u16 itemId, u8 *dst)
{
    StringCopy(dst, ItemId_GetName(itemId));
}

const u8 sText_s[] =_("s");

void CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity)
{
    u8 *end = StringCopy(dst, ItemId_GetName(itemId)) - 1;

    if (quantity < 2)
        return;

    if (DoesItemHavePluralName(itemId))
        StringCopy(dst, ItemId_GetPluralName(itemId));
    else
        StringAppend(end, sText_s);
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

const u8 *ItemId_GetNameRandom(u16 itemId)
{
    if (DECAP_ENABLED && DECAP_MIRRORING && !DECAP_ITEM_NAMES)
        return ROM_MIRROR_PTR(gItemsInfo[SanitizeItemId(itemId)].name);
    else
    {
        if (GetPocketByItemId(SanitizeItemId(itemId)) == POCKET_TM_HM)
        {
            return gMovesInfo[GetRandomMove(itemId, gItemsInfo[itemId].secondaryId)].name;
        }
        else
            return gItemsInfo[SanitizeItemId(itemId)].name;
    }
}

const u8 *ItemId_GetName(u16 itemId)
{
    if(FlagGet(FLAG_RANDOM_MODE))
    {
        return ItemId_GetNameRandom(itemId);
    }
    if (DECAP_ENABLED && DECAP_MIRRORING && !DECAP_ITEM_NAMES)
        return ROM_MIRROR_PTR(gItemsInfo[SanitizeItemId(itemId)].name);
    else
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

EWRAM_DATA u8 tmStringVar[0x100] = {0};
const u8 *ItemId_GetDescriptionRandom(u16 itemId)
{
    if (GetPocketByItemId(SanitizeItemId(itemId)) == POCKET_TM_HM)
    {
        FormatTextByWidth(tmStringVar, 100, FONT_NORMAL, gMovesInfo[GetRandomMove(itemId, gItemsInfo[itemId].secondaryId)].description, 1);
        return tmStringVar;
    }
    else
        return gItemsInfo[SanitizeItemId(itemId)].description;
}

const u8 *ItemId_GetDescription(u16 itemId)
{   
    if(FlagGet(FLAG_RANDOM_MODE))
    {
        return ItemId_GetDescriptionRandom(itemId);
    }
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


//tx_randomizer_and_challenges
#define RANDOM_CONSUMABLE_ITEM_COUNT ARRAY_COUNT(sRandomConsumableValidItems)
static const u16 sRandomConsumableValidItems[] =
{
    // Medicine
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_MAX_POTION,
    ITEM_FULL_RESTORE,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_FRESH_WATER,
    ITEM_SODA_POP,
    ITEM_LEMONADE,
    ITEM_MOOMOO_MILK,
    ITEM_ENERGY_POWDER,
    ITEM_ENERGY_ROOT,
    ITEM_HEAL_POWDER,
    ITEM_REVIVAL_HERB,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_FULL_HEAL,
    ITEM_ETHER,
    ITEM_MAX_ETHER,
    ITEM_ELIXIR,
    ITEM_MAX_ELIXIR,
    ITEM_SACRED_ASH,
    ITEM_ABILITY_CAPSULE,
    ITEM_ABILITY_PATCH,
    ITEM_RARE_CANDY,
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_X_SP_ATK,
    ITEM_X_SP_DEF,
    ITEM_X_SPEED,
    ITEM_X_ACCURACY,
    ITEM_DIRE_HIT,
    ITEM_GUARD_SPEC,
};

#define RANDOM_BERRY_ITEM_COUNT ARRAY_COUNT(sRandomBerryValidItems)
static const u16 sRandomBerryValidItems[] =
{
    ITEM_CHERI_BERRY,
    ITEM_CHESTO_BERRY,
    ITEM_PECHA_BERRY,
    ITEM_RAWST_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_LEPPA_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_PERSIM_BERRY,
    ITEM_LUM_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_IAPAPA_BERRY,
    ITEM_WEPEAR_BERRY,
    ITEM_CHILAN_BERRY,
    ITEM_OCCA_BERRY,
    ITEM_PASSHO_BERRY,
    ITEM_WACAN_BERRY,
    ITEM_RINDO_BERRY,
    ITEM_YACHE_BERRY,
    ITEM_CHOPLE_BERRY,
    ITEM_KEBIA_BERRY,
    ITEM_SHUCA_BERRY,
    ITEM_COBA_BERRY,
    ITEM_PAYAPA_BERRY,
    ITEM_TANGA_BERRY,
    ITEM_CHARTI_BERRY,
    ITEM_KASIB_BERRY,
    ITEM_HABAN_BERRY,
    ITEM_COLBUR_BERRY,
    ITEM_BABIRI_BERRY,
    ITEM_ROSELI_BERRY,
    ITEM_LIECHI_BERRY,
    ITEM_GANLON_BERRY,
    ITEM_SALAC_BERRY,
    ITEM_PETAYA_BERRY,
    ITEM_APICOT_BERRY,
    ITEM_LANSAT_BERRY,
    ITEM_STARF_BERRY,
    ITEM_ENIGMA_BERRY,
    ITEM_MICLE_BERRY,
    ITEM_CUSTAP_BERRY,
    ITEM_JABOCA_BERRY,
    ITEM_ROWAP_BERRY,
    ITEM_KEE_BERRY,
    ITEM_MARANGA_BERRY,
};

#define RANDOM_HELD_ITEM_COUNT ARRAY_COUNT(sRandomHeldValidItems)
static const u16 sRandomHeldValidItems[] =
{
    // Medicinal Flutes
    ITEM_BLUE_FLUTE,
    ITEM_YELLOW_FLUTE,
    ITEM_RED_FLUTE,
    ITEM_EVERSTONE,
    ITEM_LAX_INCENSE,
    ITEM_ODD_INCENSE,
    ITEM_FULL_INCENSE,
    ITEM_SILK_SCARF,
    ITEM_CHARCOAL,
    ITEM_MYSTIC_WATER,
    ITEM_MAGNET,
    ITEM_MIRACLE_SEED,
    ITEM_NEVER_MELT_ICE,
    ITEM_BLACK_BELT,
    ITEM_POISON_BARB,
    ITEM_SOFT_SAND,
    ITEM_SHARP_BEAK,
    ITEM_TWISTED_SPOON,
    ITEM_SILVER_POWDER,
    ITEM_HARD_STONE,
    ITEM_SPELL_TAG,
    ITEM_DRAGON_FANG,
    ITEM_BLACK_GLASSES,
    ITEM_METAL_COAT,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SPECS,
    ITEM_CHOICE_SCARF,
    ITEM_FLAME_ORB,
    ITEM_TOXIC_ORB,
    ITEM_DAMP_ROCK,
    ITEM_HEAT_ROCK,
    ITEM_SMOOTH_ROCK,
    ITEM_ICY_ROCK,
    ITEM_BRIGHT_POWDER,
    ITEM_WHITE_HERB,
    ITEM_QUICK_CLAW,
    ITEM_SOOTHE_BELL,
    ITEM_MENTAL_HERB,
    ITEM_KINGS_ROCK,
    ITEM_AMULET_COIN,
    ITEM_CLEANSE_TAG,
    ITEM_SMOKE_BALL,
    ITEM_FOCUS_BAND,
    ITEM_LUCKY_EGG,
    ITEM_SCOPE_LENS,
    ITEM_LEFTOVERS,
    ITEM_SHELL_BELL,
    ITEM_WIDE_LENS,
    ITEM_MUSCLE_BAND,
    ITEM_WISE_GLASSES,
    ITEM_EXPERT_BELT,
    ITEM_LIGHT_CLAY,
    ITEM_LIFE_ORB,
    ITEM_POWER_HERB,
    ITEM_FOCUS_SASH,
    ITEM_ZOOM_LENS,
    ITEM_METRONOME,
    ITEM_IRON_BALL,
    ITEM_LAGGING_TAIL,
    ITEM_DESTINY_KNOT,
    ITEM_BLACK_SLUDGE,
    ITEM_GRIP_CLAW,
    ITEM_STICKY_BARB,
    ITEM_SHED_SHELL,
    ITEM_BIG_ROOT,
    ITEM_RAZOR_CLAW,
    ITEM_RAZOR_FANG,
    ITEM_EVIOLITE,
    ITEM_FLOAT_STONE,
    ITEM_ROCKY_HELMET,
    ITEM_AIR_BALLOON,
    ITEM_RED_CARD,
    ITEM_RING_TARGET,
    ITEM_BINDING_BAND,
    ITEM_EJECT_BUTTON,
    ITEM_WEAKNESS_POLICY,
    ITEM_ASSAULT_VEST,
    ITEM_SAFETY_GOGGLES,
    ITEM_ADRENALINE_ORB,
    ITEM_TERRAIN_EXTENDER,
    ITEM_PROTECTIVE_PADS,
    ITEM_THROAT_SPRAY,
    ITEM_EJECT_PACK,
    ITEM_HEAVY_DUTY_BOOTS,
    ITEM_BLUNDER_POLICY,
    ITEM_ROOM_SERVICE,
    ITEM_UTILITY_UMBRELLA,
};

u16 RandomItemId(u16 itemId)
{
    u16 randomItemCategory = 0;
    if (ItemId_GetPocket(itemId) == POCKET_TM_HM)
    {
        return itemId;
    }
    else if (ItemId_GetPocket(itemId) != POCKET_KEY_ITEMS)
    {
        randomItemCategory = Random32() % 10;
        if(randomItemCategory < 5)
            itemId = sRandomConsumableValidItems[RandomSeededModulo(itemId + VarGet(VAR_PIT_FLOOR) + gSaveBlock1Ptr->pos.x, RANDOM_CONSUMABLE_ITEM_COUNT)];
        else if(randomItemCategory < 8)
            itemId = sRandomHeldValidItems[RandomSeededModulo(itemId + VarGet(VAR_PIT_FLOOR) + gSaveBlock1Ptr->pos.x, RANDOM_HELD_ITEM_COUNT)];
        else
            itemId = sRandomBerryValidItems[RandomSeededModulo(itemId + VarGet(VAR_PIT_FLOOR) + gSaveBlock1Ptr->pos.x, RANDOM_BERRY_ITEM_COUNT)];
    }

    VarSet(VAR_0x8006, itemId);
    return itemId;
}

u16 RandomItem(void)
{
    u16 itemId = RandomItemId(gSpecialVar_0x8000);

    gSpecialVar_0x8000 = itemId;
    return itemId;
}

u16 RandomItemHidden(void) //same as normal hidden item, but differen special var
{
    u16 itemId = RandomItemId(gSpecialVar_0x8005);

    gSpecialVar_0x8005 = itemId;
    return itemId;
}


// Item Description Header
static u8 ReformatItemDescription(u16 item, u8 *dest)
{
    u8 count = 0;
    u8 numLines = 1;
    u8 maxChars = 32;
    u8 *desc = (u8 *)gItemsInfo[item].description;

    while (*desc != EOS)
    {
        if (count >= maxChars)
        {
            while (*desc != CHAR_SPACE && *desc != CHAR_NEWLINE)
            {
                *dest = *desc;  //finish word
                dest++;
                desc++;
            }

            *dest = CHAR_NEWLINE;
            count = 0;
            numLines++;
            dest++;
            desc++;
            continue;
        }

        *dest = *desc;
        if (*desc == CHAR_NEWLINE)
        {
            *dest = CHAR_SPACE;
        }

        dest++;
        desc++;
        count++;
    }

    // finish string
    *dest = EOS;
    return numLines;
}

#define ITEM_ICON_X 26
#define ITEM_ICON_Y 24
void DrawHeaderBox(void)
{
    struct WindowTemplate template;
    u16 item = gSpecialVar_0x8006;
    u8 headerType = gSpecialVar_0x8009;
    u8 textY;
    u8 *dst;
    bool8 handleFlash = FALSE;

    if (GetFlashLevel() > 0 || InBattlePyramid_())
        handleFlash = TRUE;

    if (headerType == 1)
        dst = gStringVar3;
    else
        dst = gStringVar1;

    SetWindowTemplateFields(&template, 0, 1, 1, 28, 3, 15, 8);
    sHeaderBoxWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sHeaderBoxWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sHeaderBoxWindowId);
    CopyWindowToVram(sHeaderBoxWindowId, 3);
    SetStandardWindowBorderStyle(sHeaderBoxWindowId, FALSE);
    DrawStdFrameWithCustomTileAndPalette(sHeaderBoxWindowId, FALSE, 0x214, 14);

    if (ReformatItemDescription(item, dst) == 1)
        textY = 4;
    else
        textY = 0;

    ShowItemIconSprite(item, TRUE, handleFlash);
    AddTextPrinterParameterized(sHeaderBoxWindowId, 0, dst, ITEM_ICON_X + 2, textY, 0, NULL);
}

void HideHeaderBox(void)
{
    DestroyItemIconSprite();

    if (1)
    {
        //header box only exists if haven't seen item before
        ClearStdWindowAndFrameToTransparent(sHeaderBoxWindowId, FALSE);
        CopyWindowToVram(sHeaderBoxWindowId, 3);
        RemoveWindow(sHeaderBoxWindowId);
    }
}

#include "gpu_regs.h"

#define ITEM_TAG 0x2722 //same as money label
static void ShowItemIconSprite(u16 item, bool8 firstTime, bool8 flash)
{
    s16 x, y;
    x = 0;
    y = 0;
    u8 iconSpriteId;   
    u8 spriteId2 = MAX_SPRITES;

    if (flash)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }

    iconSpriteId = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
    if (flash)
        spriteId2 = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
    if (iconSpriteId != MAX_SPRITES)
    {
        if (!firstTime)
        {
            //show in message box
            x = 213;
            y = 140;
        }
        else
        {
            // show in header box
            x = ITEM_ICON_X;
            y = ITEM_ICON_Y;
        }

        gSprites[iconSpriteId].x2 = x;
        gSprites[iconSpriteId].y2 = y;
        gSprites[iconSpriteId].oam.priority = 0;
    }

    if (spriteId2 != MAX_SPRITES)
    {
        gSprites[spriteId2].x2 = x;
        gSprites[spriteId2].y2 = y;
        gSprites[spriteId2].oam.priority = 0;
        gSprites[spriteId2].oam.objMode = ST_OAM_OBJ_WINDOW;
        sItemIconSpriteId2 = spriteId2;
    }

    sItemIconSpriteId = iconSpriteId;
}

static void DestroyItemIconSprite(void)
{
    FreeSpriteTilesByTag(ITEM_TAG);
    FreeSpritePaletteByTag(ITEM_TAG);
    FreeSpriteOamMatrix(&gSprites[sItemIconSpriteId]);
    DestroySprite(&gSprites[sItemIconSpriteId]);

    if ((GetFlashLevel() > 0 || InBattlePyramid_()) && sItemIconSpriteId2 != MAX_SPRITES)
    {
        //FreeSpriteTilesByTag(ITEM_TAG);
        //FreeSpritePaletteByTag(ITEM_TAG);
        FreeSpriteOamMatrix(&gSprites[sItemIconSpriteId2]);
        DestroySprite(&gSprites[sItemIconSpriteId2]);
    }
}
