
// Includes
#include "global.h"
#include "tv.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

void sub_80EEE5C(void);

// .rodata

// .text

void ClearTVShowData(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows); i ++)
    {
        gSaveBlock1Ptr->tvShows[i].common.var00 = 0;
        gSaveBlock1Ptr->tvShows[i].common.var01 = 0;
        for (j = 0; j < sizeof(TVShow) - 2; j ++)
        {
            gSaveBlock1Ptr->tvShows[i].common.pad02[j] = 0;
        }
    }
    sub_80EEE5C();
}
