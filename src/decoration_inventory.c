
// Includes
#include "global.h"
#include "constants/decorations.h"
#include "decoration.h"
#include "decoration_inventory.h"

// Static type declarations

// Static RAM declarations

EWRAM_DATA struct DecorationInventory gDecorationInventories[8] = {};

// Static ROM declarations

// .rodata

// .text

#define SET_DECOR_INV(i, ptr) {\
    gDecorationInventories[i].items = ptr;\
    gDecorationInventories[i].size = sizeof(ptr);\
}

void SetDecorationInventoriesPointers(void)
{
    SET_DECOR_INV(0, gSaveBlock1Ptr->decorDesk);
    SET_DECOR_INV(1, gSaveBlock1Ptr->decorChair);
    SET_DECOR_INV(2, gSaveBlock1Ptr->decorPlant);
    SET_DECOR_INV(3, gSaveBlock1Ptr->decorOrnament);
    SET_DECOR_INV(4, gSaveBlock1Ptr->decorMat);
    SET_DECOR_INV(5, gSaveBlock1Ptr->decorPoster);
    SET_DECOR_INV(6, gSaveBlock1Ptr->decorDoll);
    SET_DECOR_INV(7, gSaveBlock1Ptr->decorCushion);
    sub_8126968();
}

static void ClearDecorationInventory(u8 idx)
{
    u8 i;

    for (i = 0; i < gDecorationInventories[idx].size; i ++)
    {
        gDecorationInventories[idx].items[i] = DECOR_NONE;
    }
}

void ClearDecorationInventories(void)
{
    u8 idx;

    for (idx = 0; idx < 8; idx ++)
    {
        ClearDecorationInventory(idx);
    }
}

s8 GetFirstEmptyDecorSlot(u8 idx)
{
    s8 i;

    for (i = 0; i < (s8)gDecorationInventories[idx].size; i ++)
    {
        if (gDecorationInventories[idx].items[i] == DECOR_NONE)
        {
            return i;
        }
    }
    return -1;
}

bool8 CheckHasDecoration(u8 decor)
{
    u8 i;
    u8 category;

    category = gDecorations[decor].category;
    for (i = 0; i < gDecorationInventories[category].size; i ++)
    {
        if (gDecorationInventories[category].items[i] == decor)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 DecorationAdd(u8 decor)
{
    u8 category;
    s8 idx;

    if (decor == DECOR_NONE)
    {
        return FALSE;
    }
    category = gDecorations[decor].category;
    idx = GetFirstEmptyDecorSlot(category);
    if (idx == -1)
    {
        return FALSE;
    }
    gDecorationInventories[category].items[idx] = decor;
    return TRUE;
}

bool8 DecorationCheckSpace(u8 decor)
{
    if (decor == DECOR_NONE)
    {
        return FALSE;
    }
    if (GetFirstEmptyDecorSlot(gDecorations[decor].category) == -1)
    {
        return FALSE;
    }
    return TRUE;
}

s8 DecorationRemove(u8 decor)
{
    u8 i;
    u8 idx;

    i = 0;
    if (decor == DECOR_NONE)
    {
        return 0;
    }
    for (i = 0; i < gDecorationInventories[gDecorations[decor].category].size; i ++)
    {
        idx = gDecorations[decor].category;
        if (gDecorationInventories[idx].items[i] == decor)
        {
            gDecorationInventories[idx].items[i] = DECOR_NONE;
            CondenseDecorationCategoryN(idx);
            return 1;
        }
    }
    return 0;
}

void CondenseDecorationCategoryN(u8 idx)
{
    u8 i;
    u8 j;
    u8 tmp;

    for (i = 0; i < gDecorationInventories[idx].size; i ++)
    {
        for (j = i + 1; j < gDecorationInventories[idx].size; j ++)
        {
            if (gDecorationInventories[idx].items[j] != DECOR_NONE && (gDecorationInventories[idx].items[i] == DECOR_NONE || gDecorationInventories[idx].items[i] > gDecorationInventories[idx].items[j]))
            {
                tmp = gDecorationInventories[idx].items[i];
                gDecorationInventories[idx].items[i] = gDecorationInventories[idx].items[j];
                gDecorationInventories[idx].items[j] = tmp;
            }
        }
    }
}

u8 CountDecorationCategoryN(u8 idx)
{
    u8 i;
    u8 ct;

    ct = 0;
    for (i = 0; i < gDecorationInventories[idx].size; i ++)
    {
        if (gDecorationInventories[idx].items[i] != DECOR_NONE)
        {
            ct ++;
        }
    }
    return ct;
}

u8 CountDecorations(void)
{
    u8 idx;
    u8 ct;

    ct = 0;
    for (idx = 0; idx < 8; idx ++)
    {
        ct += CountDecorationCategoryN(idx);
    }
    return ct;
}
