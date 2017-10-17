
// Includes
#include "global.h"
#include "decoration.h"
#include "decoration_inventory.h"

// Static type declarations

// Static RAM declarations

extern EWRAM_DATA u8 *gUnknown_0203A14C;
extern EWRAM_DATA u8 gUnknown_0203A173;
extern EWRAM_DATA struct DecoPCPointers gUnknown_0203A17C;

// Static ROM declarations

// .rodata

// .text

void sub_8126968(void)
{
    if (gUnknown_0203A173 < 8)
    {
        gUnknown_0203A14C = gDecorationInventories[gUnknown_0203A173].items;
    }
    if (gUnknown_0203A17C.isPlayerRoom == FALSE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    }
    if (gUnknown_0203A17C.isPlayerRoom == TRUE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    }
}
