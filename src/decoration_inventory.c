
// Includes
#include "global.h"
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

void ClearDecorationInventory(u8 idx)
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

s8 sub_81618D0(u8 idx)
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
    idx = sub_81618D0(category);
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
    if (sub_81618D0(gDecorations[decor].category) == -1)
    {
        return FALSE;
    }
    return TRUE;
}
