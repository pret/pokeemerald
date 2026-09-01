#include "global.h"
#include "item.h"
#include "berry.h"
#include "pokeball.h"
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
#include "graphics.h"
#include "shop_criteria.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/item_effects.h"
#include "constants/hold_effects.h"

#define DUMMY_PC_BAG_POCKET                 \
{                                           \
    .id = POCKET_DUMMY,                     \
    .capacity = PC_ITEMS_COUNT,             \
    .itemSlots = gSaveBlock1Ptr->pcItems,   \
}

static bool32 CheckPyramidBagHasItem(enum Item itemId, u16 count);
static bool32 CheckPyramidBagHasSpace(enum Item itemId, u16 count);
static const u8 *GetItemPluralName(enum Item);
static bool32 DoesItemHavePluralName(enum Item);
static void NONNULL BagPocket_CompactItems(struct BagPocket *pocket);
static enum Item SanitizeItemId(enum Item itemId);
static enum Item SanitizeBagItemId(enum Item itemId);

EWRAM_DATA struct BagPocket gBagPockets[POCKETS_COUNT] = {0};

#include "data/pokemon/item_effects.h"
#include "data/items.h"

#define UNPACK_TM_ITEM_ID(_tm) [CAT(ENUM_TM_HM_, _tm) + 1] = { CAT(ITEM_TM_, _tm), CAT(MOVE_, _tm) },
#define UNPACK_HM_ITEM_ID(_hm) [CAT(ENUM_TM_HM_, _hm) + 1] = { CAT(ITEM_HM_, _hm), CAT(MOVE_, _hm) },

const struct TmHmIndexKey gTMHMItemMoveIds[NUM_ALL_MACHINES + 1] =
{
    [0] = { ITEM_NONE, MOVE_NONE }, // Failsafe
    FOREACH_TM(UNPACK_TM_ITEM_ID)
    FOREACH_HM(UNPACK_HM_ITEM_ID)
    /*
     * Expands to the following:
     *
     * [1] = { ITEM_TM_FOCUS_PUNCH, MOVE_FOCUS_PUNCH },
     * [2] = { ITEM_TM_DRAGON_CLAW, MOVE_DRAGON_CLAW },
     * [3] = { ITEM_TM_WATER_PULSE, MOVE_WATER_PULSE },
     * etc etc
    */
};

#undef UNPACK_TM_ITEM_ID
#undef UNPACK_HM_ITEM_ID

static inline struct ItemSlot NONNULL BagPocket_GetSlotDataGeneric(struct BagPocket *pocket, u32 pocketPos)
{
    return (struct ItemSlot) {
        .itemId = pocket->itemSlots[pocketPos].itemId,
        .quantity = pocket->itemSlots[pocketPos].quantity ^ gSaveBlock2Ptr->encryptionKey,
    };
}

static inline struct ItemSlot NONNULL BagPocket_GetSlotDataPC(struct BagPocket *pocket, u32 pocketPos)
{
    return (struct ItemSlot) {
        .itemId = pocket->itemSlots[pocketPos].itemId,
        .quantity = pocket->itemSlots[pocketPos].quantity,
    };
}

static inline void NONNULL BagPocket_SetSlotDataGeneric(struct BagPocket *pocket, u32 pocketPos, struct ItemSlot newSlot)
{
    pocket->itemSlots[pocketPos].itemId = newSlot.itemId;
    pocket->itemSlots[pocketPos].quantity = newSlot.quantity ^ gSaveBlock2Ptr->encryptionKey;
}

static inline void NONNULL BagPocket_SetSlotDataPC(struct BagPocket *pocket, u32 pocketPos, struct ItemSlot newSlot)
{
    pocket->itemSlots[pocketPos].itemId = newSlot.itemId;
    pocket->itemSlots[pocketPos].quantity = newSlot.quantity;
}

struct ItemSlot NONNULL BagPocket_GetSlotData(struct BagPocket *pocket, u32 pocketPos)
{
    switch (pocket->id)
    {
    case POCKET_ITEMS:
    case POCKET_KEY_ITEMS:
    case POCKET_POKE_BALLS:
    case POCKET_TM_HM:
    case POCKET_BERRIES:
        return BagPocket_GetSlotDataGeneric(pocket, pocketPos);
    case POCKET_DUMMY:
        return BagPocket_GetSlotDataPC(pocket, pocketPos);
    }

    return (struct ItemSlot) {0}; // Because compiler complains
}

void NONNULL BagPocket_SetSlotData(struct BagPocket *pocket, u32 pocketPos, struct ItemSlot newSlot)
{
    if (newSlot.itemId == ITEM_NONE || newSlot.quantity == 0) // Sets to zero if quantity or itemId is zero
    {
        newSlot.itemId = ITEM_NONE;
        newSlot.quantity = 0;
    }

    switch (pocket->id)
    {
    case POCKET_ITEMS:
    case POCKET_KEY_ITEMS:
    case POCKET_POKE_BALLS:
    case POCKET_TM_HM:
    case POCKET_BERRIES:
        BagPocket_SetSlotDataGeneric(pocket, pocketPos, newSlot);
        break;
    case POCKET_DUMMY:
        BagPocket_SetSlotDataPC(pocket, pocketPos, newSlot);
        break;
    }
}

void ApplyNewEncryptionKeyToBagItems(u32 newKey)
{
    enum Pocket pocketId;
    enum Item item;
    for (pocketId = 0; pocketId < POCKETS_COUNT; pocketId++)
    {
        for (item = ITEM_NONE; item < gBagPockets[pocketId].capacity; item++)
            ApplyNewEncryptionKeyToHword(&(gBagPockets[pocketId].itemSlots[item].quantity), newKey);
    }
}

void SetBagItemsPointers(void)
{
    gBagPockets[POCKET_ITEMS].itemSlots = gSaveBlock1Ptr->bag.items;
    gBagPockets[POCKET_ITEMS].capacity = BAG_ITEMS_COUNT;
    gBagPockets[POCKET_ITEMS].id = POCKET_ITEMS;

    gBagPockets[POCKET_KEY_ITEMS].itemSlots = gSaveBlock1Ptr->bag.keyItems;
    gBagPockets[POCKET_KEY_ITEMS].capacity = BAG_KEYITEMS_COUNT;
    gBagPockets[POCKET_KEY_ITEMS].id = POCKET_KEY_ITEMS;

    gBagPockets[POCKET_POKE_BALLS].itemSlots = gSaveBlock1Ptr->bag.pokeBalls;
    gBagPockets[POCKET_POKE_BALLS].capacity = BAG_POKEBALLS_COUNT;
    gBagPockets[POCKET_POKE_BALLS].id = POCKET_POKE_BALLS;

    gBagPockets[POCKET_TM_HM].itemSlots = gSaveBlock1Ptr->bag.TMsHMs;
    gBagPockets[POCKET_TM_HM].capacity = BAG_TMHM_COUNT;
    gBagPockets[POCKET_TM_HM].id = POCKET_TM_HM;

    gBagPockets[POCKET_BERRIES].itemSlots = gSaveBlock1Ptr->bag.berries;
    gBagPockets[POCKET_BERRIES].capacity = BAG_BERRIES_COUNT;
    gBagPockets[POCKET_BERRIES].id = POCKET_BERRIES;
}

u8 *CopyItemName(enum Item itemId, u8 *dst)
{
    return StringCopy(dst, GetItemName(itemId));
}

const u8 sText_s[] =_("s");

u8 *CopyItemNameHandlePlural(enum Item itemId, u8 *dst, u32 quantity)
{
    if (quantity == 1)
    {
        return StringCopy(dst, GetItemName(itemId));
    }
    else if (DoesItemHavePluralName(itemId))
    {
        return StringCopy(dst, GetItemPluralName(itemId));
    }
    else
    {
        u8 *end = StringCopy(dst, GetItemName(itemId));
        return StringCopy(end, sText_s);
    }
}

bool32 IsBagPocketNonEmpty(enum Pocket pocketId)
{
    u8 i;

    for (i = 0; i < gBagPockets[pocketId].capacity; i++)
    {
        if (GetBagItemId(pocketId, i) != ITEM_NONE)
            return TRUE;
    }
    return FALSE;
}

static bool32 NONNULL BagPocket_CheckHasItem(struct BagPocket *pocket, enum Item itemId, u16 count)
{
    struct ItemSlot tempItem;

    // Check for item slots that contain the item
    for (u32 i = 0; i < pocket->capacity && count > 0; i++)
    {
        tempItem = BagPocket_GetSlotData(pocket, i);
        if (tempItem.itemId == itemId)
            count -= min(count, tempItem.quantity);
    }

    return count == 0;
}

bool32 CheckBagHasItem(enum Item itemId, u16 count)
{
    if (GetItemPocket(itemId) >= POCKETS_COUNT)
        return FALSE;
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        return CheckPyramidBagHasItem(itemId, count);

    return BagPocket_CheckHasItem(&gBagPockets[GetItemPocket(itemId)], itemId, count);
}

bool32 HasAtLeastOneBerry(void)
{
    for (enum BerryId berryId = 1; berryId <= NUM_BERRIES; berryId++)
    {
        if (CheckBagHasItem(BerryTypeToItemId(berryId), 1) == TRUE)
            return (gSpecialVar_Result = TRUE);
    }

    return (gSpecialVar_Result = FALSE);
}

bool32 HasAtLeastOnePokeBall(void)
{
    for (enum PokeBall ballId = BALL_STRANGE; ballId < POKEBALL_COUNT; ballId++)
    {
        if (CheckBagHasItem(gPokeBalls[ballId].itemId, 1) == TRUE)
            return TRUE;
    }
    return FALSE;
}

bool32 CheckBagHasSpace(enum Item itemId, u16 count)
{
    if (GetItemPocket(itemId) >= POCKETS_COUNT)
        return FALSE;

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        return CheckPyramidBagHasSpace(itemId, count);

    return GetFreeSpaceForItemInBag(itemId) >= count;
}

static u32 NONNULL BagPocket_GetFreeSpaceForItem(struct BagPocket *pocket, enum Item itemId)
{
    u32 spaceForItem = 0;
    struct ItemSlot tempItem;

    // Check space in any existing item slots that already contain this item
    for (u32 i = 0; i < pocket->capacity; i++)
    {
        tempItem = BagPocket_GetSlotData(pocket, i);
        if (tempItem.itemId == ITEM_NONE || tempItem.itemId == itemId)
            spaceForItem += (tempItem.itemId ? (MAX_BAG_ITEM_CAPACITY - tempItem.quantity) : MAX_BAG_ITEM_CAPACITY);
    }

    return spaceForItem;
}

u32 GetFreeSpaceForItemInBag(enum Item itemId)
{
    if (GetItemPocket(itemId) >= POCKETS_COUNT)
        return 0;

    return BagPocket_GetFreeSpaceForItem(&gBagPockets[GetItemPocket(itemId)], itemId);
}

static inline bool32 NONNULL CheckSlotAndUpdateCount(struct BagPocket *pocket, enum Item itemId, u32 pocketPos, u32 *nextPocketPos, u16 *count, u16 *tempPocketSlotQuantities)
{
    struct ItemSlot tempItem = BagPocket_GetSlotData(pocket, pocketPos);
    if (tempItem.itemId == ITEM_NONE || tempItem.itemId == itemId)
    {
        // The quantity already at the slot - zero if an empty slot
        if (tempItem.itemId == ITEM_NONE)
            tempItem.quantity = 0;

        // Record slot quantity in tempPocketSlotQuantities, adjust count
        tempPocketSlotQuantities[pocketPos] = min(MAX_BAG_ITEM_CAPACITY, *count + tempItem.quantity);
        *count -= min(*count, MAX_BAG_ITEM_CAPACITY - tempItem.quantity);

        // Set the starting index for the next loop to set items (shifted by one)
        if (!*nextPocketPos)
            *nextPocketPos = pocketPos + 1;

        return TRUE;
    }

    return FALSE;
}

static bool32 NONNULL BagPocket_AddItem(struct BagPocket *pocket, enum Item itemId, u16 count)
{
    u32 itemLookupIndex, itemAddIndex = 0;

    // First, check that there is a free slot for this item
    u16 *tempPocketSlotQuantities = AllocZeroed(sizeof(u16) * pocket->capacity);

    switch (pocket->id)
    {
    case POCKET_TM_HM:
    case POCKET_BERRIES:
        for (itemLookupIndex = 0; itemLookupIndex < pocket->capacity && count > 0; itemLookupIndex++)
        {
            // Check if we found a slot to store the item but weren't able to reduce count to 0
            // This means that we have more than one stack's worth, which isn't allowed in these pockets
            if (CheckSlotAndUpdateCount(pocket, itemId, itemLookupIndex, &itemAddIndex, &count, tempPocketSlotQuantities) && count > 0)
            {
                Free(tempPocketSlotQuantities);
                return FALSE;
            }
        }
        break;
    default:
        for (itemLookupIndex = 0; itemLookupIndex < pocket->capacity && count > 0; itemLookupIndex++)
            CheckSlotAndUpdateCount(pocket, itemId, itemLookupIndex, &itemAddIndex, &count, tempPocketSlotQuantities);
    }

    // If the count is still greater than zero, clearly we have not found enough slots for this...
    // Otherwise, we have found slots - update the actual pockets with the updated quantities
    if (count == 0)
    {
        for (--itemAddIndex; itemAddIndex < itemLookupIndex; itemAddIndex++)
        {
            if (tempPocketSlotQuantities[itemAddIndex] > 0)
                BagPocket_SetSlotItemIdAndCount(pocket, itemAddIndex, itemId, tempPocketSlotQuantities[itemAddIndex]);
        }
    }

    Free(tempPocketSlotQuantities);
    return count == 0;
}

bool32 AddBagItem(enum Item itemId, u16 count)
{
    itemId = SanitizeBagItemId(itemId);
    if (itemId == ITEM_NONE)
        return FALSE;

    // check Battle Pyramid Bag
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        return AddPyramidBagItem(itemId, count);

    return BagPocket_AddItem(&gBagPockets[GetItemPocket(itemId)], itemId, count);
}

static bool32 NONNULL BagPocket_RemoveItem(struct BagPocket *pocket, enum Item itemId, u16 count)
{
    u32 itemLookupIndex, itemRemoveIndex = 0, totalQuantity = 0;
    struct ItemSlot tempItem;
    u16 *tempPocketSlotQuantities = AllocZeroed(sizeof(u16) * pocket->capacity);

    for (itemLookupIndex = 0; itemLookupIndex < pocket->capacity && totalQuantity < count; itemLookupIndex++)
    {
        tempItem = BagPocket_GetSlotData(pocket, itemLookupIndex);
        if (tempItem.itemId == itemId)
        {
            // Index for the next loop - where we should start removing items
            if (!itemRemoveIndex)
                itemRemoveIndex = itemLookupIndex + 1;

            // Gather quantities (+ 1 to tempPocketSlotQuantities so that even if setting to 0 we know which indices to target)
            totalQuantity += tempItem.quantity;
            tempPocketSlotQuantities[itemLookupIndex] = (tempItem.quantity <= count ? 0 : tempItem.quantity - count) + 1;
        }
    }

    if (totalQuantity >= count) // We have enough of the item
    {
        if (CurMapIsSecretBase() == TRUE)
        {
            VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_BAG);
            VarSet(VAR_SECRET_BASE_LAST_ITEM_USED, itemId);
        }

        // Update the quantities correctly with the items removed
        for (--itemRemoveIndex; itemRemoveIndex < itemLookupIndex; itemRemoveIndex++)
        {
            if (tempPocketSlotQuantities[itemRemoveIndex] > 0)
                BagPocket_SetSlotItemIdAndCount(pocket, itemRemoveIndex, itemId, tempPocketSlotQuantities[itemRemoveIndex] - 1);
        }
    }

    if (totalQuantity == count)
        BagPocket_CompactItems(pocket);

    Free(tempPocketSlotQuantities);
    return totalQuantity >= count;
}

bool32 RemoveBagItem(enum Item itemId, u16 count)
{
    itemId = SanitizeBagItemId(itemId);
    if (itemId == ITEM_NONE)
        return FALSE;

    // check Battle Pyramid Bag
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        return RemovePyramidBagItem(itemId, count);

    return BagPocket_RemoveItem(&gBagPockets[GetItemPocket(itemId)], itemId, count);
}

// Unsafe function: Only use with functions that already check the slot and count are valid
void RemoveBagItemFromSlot(struct BagPocket *pocket, u16 slotId, u16 count)
{
    struct ItemSlot itemSlot = BagPocket_GetSlotData(pocket, slotId);
    BagPocket_SetSlotItemIdAndCount(pocket, slotId, itemSlot.itemId, itemSlot.quantity - count);
}

static u8 NONNULL BagPocket_CountUsedItemSlots(struct BagPocket *pocket)
{
    u8 usedSlots = 0;

    for (u32 i = 0; i < pocket->capacity; i++)
    {
        if (BagPocket_GetSlotData(pocket, i).itemId != ITEM_NONE)
            usedSlots++;
    }
    return usedSlots;
}

u8 CountUsedPCItemSlots(void)
{
    struct BagPocket dummyPocket = DUMMY_PC_BAG_POCKET;
    return BagPocket_CountUsedItemSlots(&dummyPocket);
}

static bool32 NONNULL BagPocket_CheckPocketForItemCount(struct BagPocket *pocket, enum Item itemId, u16 count)
{
    struct ItemSlot tempItem;

    for (u32 i = 0; i < pocket->capacity; i++)
    {
        tempItem = BagPocket_GetSlotData(pocket, i);
        if (tempItem.itemId == itemId && tempItem.quantity >= count)
            return TRUE;
    }
    return FALSE;
}

bool32 CheckPCHasItem(enum Item itemId, u16 count)
{
    struct BagPocket dummyPocket = DUMMY_PC_BAG_POCKET;
    return BagPocket_CheckPocketForItemCount(&dummyPocket, itemId, count);
}

bool32 AddPCItem(enum Item itemId, u16 count)
{
    struct BagPocket dummyPocket = DUMMY_PC_BAG_POCKET;
    return BagPocket_AddItem(&dummyPocket, itemId, count);
}

static void NONNULL BagPocket_CompactItems(struct BagPocket *pocket)
{
    struct ItemSlot tempItem;
    u32 slotCursor = 0;
    for (u32 i = 0; i < pocket->capacity; i++)
    {
        tempItem = BagPocket_GetSlotData(pocket, i);
        if (tempItem.itemId == ITEM_NONE)
        {
            if (!slotCursor)
                slotCursor = i + 1;
        }
        else if (slotCursor > 0)
        {
            BagPocket_SetSlotData(pocket, slotCursor++ - 1, tempItem);
            BagPocket_SetSlotItemIdAndCount(pocket, i, ITEM_NONE, 0);
        }
    }
}

void RemovePCItem(u8 index, u16 count)
{
    struct BagPocket dummyPocket = DUMMY_PC_BAG_POCKET;

    // Get id, quantity at slot
    struct ItemSlot tempItem = BagPocket_GetSlotData(&dummyPocket, index);

    // Remove quantity
    BagPocket_SetSlotItemIdAndCount(&dummyPocket, index, tempItem.itemId, tempItem.quantity - count);

    // Compact if necessary
    if (tempItem.quantity == 0)
        BagPocket_CompactItems(&dummyPocket);
}

void CompactPCItems(void)
{
    struct BagPocket dummyPocket = DUMMY_PC_BAG_POCKET;
    BagPocket_CompactItems(&dummyPocket);
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

void CompactItemsInBagPocket(enum Pocket pocketId)
{
    BagPocket_CompactItems(&gBagPockets[pocketId]);
}

static inline void NONNULL BagPocket_MoveItemSlot(struct BagPocket *pocket, u32 from, u32 to)
{
    if (from != to)
    {
        s8 shift = (to > from) ? 1 : -1;
        if (to > from)
            to--;

        // Record the values at "from"
        struct ItemSlot fromSlot = BagPocket_GetSlotData(pocket, from);

        // Shuffle items between "to" and "from"
        for (u32 i = from; i != to; i += shift)
            BagPocket_SetSlotData(pocket, i, BagPocket_GetSlotData(pocket, i + shift));

        // Move the saved "from" to "to"
        BagPocket_SetSlotData(pocket, to, fromSlot);
    }
}

void MoveItemSlotInPocket(enum Pocket pocketId, u32 from, u32 to)
{
    BagPocket_MoveItemSlot(&gBagPockets[pocketId], from, to);
}

void MoveItemSlotInPC(struct ItemSlot *itemSlots, u32 from, u32 to)
{
    struct BagPocket dummyPocket = DUMMY_PC_BAG_POCKET;
    return BagPocket_MoveItemSlot(&dummyPocket, from, to);
}

void ClearBag(void)
{
    CpuFastFill(0, &gSaveBlock1Ptr->bag, sizeof(struct Bag));
}

static inline u16 NONNULL BagPocket_CountTotalItemQuantity(struct BagPocket *pocket, enum Item itemId)
{
    u32 ownedCount = 0;
    struct ItemSlot tempItem;

    for (u32 i = 0; i < pocket->capacity; i++)
    {
        tempItem = BagPocket_GetSlotData(pocket, i);
        if (tempItem.itemId == itemId)
            ownedCount += tempItem.quantity;
    }

    return ownedCount;
}

u16 CountTotalItemQuantityInBag(enum Item itemId)
{
    return BagPocket_CountTotalItemQuantity(&gBagPockets[GetItemPocket(itemId)], itemId);
}

static bool32 CheckPyramidBagHasItem(enum Item itemId, u16 count)
{
    u8 i;
    enum Item *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
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

static bool32 CheckPyramidBagHasSpace(enum Item itemId, u16 count)
{
    u8 i;
    enum Item *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
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

bool32 AddPyramidBagItem(enum Item itemId, u16 count)
{
    u16 i;

    enum Item *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
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

bool32 RemovePyramidBagItem(enum Item itemId, u16 count)
{
    u16 i;

    enum Item *items = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
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

static enum Item SanitizeItemId(enum Item itemId)
{
    assertf(itemId < ITEMS_COUNT, "invalid item: %d", itemId)
    {
        return ITEM_NONE;
    }

    return itemId;
}

static enum Item SanitizeBagItemId(enum Item itemId)
{
    itemId = SanitizeItemId(itemId);

    assertf(itemId != ITEM_NONE, "invalid bag item: ITEM_NONE")
    {
        return ITEM_NONE;
    }

    assertf(GetItemPocket(itemId) < POCKETS_COUNT, "invalid bag item pocket: %S", gItemsInfo[itemId].name)
    {
        return ITEM_NONE;
    }

    return itemId;
}

const u8 *GetItemName(enum Item itemId)
{
    const u8 *name = gItemsInfo[SanitizeItemId(itemId)].name;

    return name == NULL ? gQuestionMarksItemName : name;
}

u32 GetItemPrice(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].price;
}

static bool32 DoesItemHavePluralName(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pluralName != NULL;
}

static const u8 *GetItemPluralName(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pluralName;
}

const u8 *GetItemEffect(enum Item itemId)
{
    if (itemId == ITEM_ENIGMA_BERRY_E_READER)
    #if FREE_ENIGMA_BERRY == FALSE
        return gSaveBlock1Ptr->enigmaBerry.itemEffect;
    #else
        return NULL;
    #endif //FREE_ENIGMA_BERRY
    else
        return gItemsInfo[SanitizeItemId(itemId)].effect;
}

enum HoldEffect GetItemHoldEffect(enum Item itemId)
{
    if (itemId == ITEM_ENIGMA_BERRY_E_READER)
    #if FREE_ENIGMA_BERRY == FALSE
        return gSaveBlock1Ptr->enigmaBerry.holdEffect;
    #else
        return HOLD_EFFECT_NONE;
    #endif //FREE_ENIGMA_BERRY
    else
        return gItemsInfo[SanitizeItemId(itemId)].holdEffect;
}

u32 GetItemHoldEffectParam(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].holdEffectParam;
}

const u8 *GetItemDescription(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].description;
}

u8 GetItemImportance(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].importance;
}

u8 GetItemConsumability(enum Item itemId)
{
    return !gItemsInfo[SanitizeItemId(itemId)].notConsumed;
}

enum Pocket GetItemPocket(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].pocket;
}

enum ItemType GetItemType(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].type;
}

ItemUseFunc GetItemFieldFunc(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].fieldUseFunc;
}

// Returns an item's battle effect script ID.
enum EffectItem GetItemBattleUsage(enum Item itemId)
{
    enum Item item = SanitizeItemId(itemId);
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

u32 GetItemSecondaryId(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].secondaryId;
}

u32 GetItemFlingPower(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].flingPower;
}


u32 GetItemStatus1Mask(enum Item itemId)
{
    const u8 *effect = GetItemEffect(itemId);
    switch (effect[3])
    {
    case ITEM3_PARALYSIS:
        return STATUS1_PARALYSIS;
    case ITEM3_FREEZE:
        return STATUS1_ICY_ANY;
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

u32 GetItemSellPrice(enum Item itemId)
{
    return GetItemPrice(itemId) / ITEM_SELL_FACTOR;
}

bool32 IsHoldEffectChoice(enum HoldEffect holdEffect)
{
    return holdEffect == HOLD_EFFECT_CHOICE_BAND
        || holdEffect == HOLD_EFFECT_CHOICE_SCARF
        || holdEffect == HOLD_EFFECT_CHOICE_SPECS;
}

ShopCriteriaFunc GetItemShopCriteriaFunc(enum Item itemId)
{
    return gItemsInfo[SanitizeItemId(itemId)].shopCriteriaFunc;
}

bool32 IsItemShopCriteriaFulfilled(enum Item itemId)
{
    ShopCriteriaFunc func = GetItemShopCriteriaFunc(itemId);

    if (!func)
        return TRUE;

    return func(SanitizeItemId(itemId));
}
