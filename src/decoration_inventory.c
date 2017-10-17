
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
