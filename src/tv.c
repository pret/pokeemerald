
// Includes
#include "global.h"
#include "rng.h"
#include "tv.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

void sub_80EEE5C(void);
u8 sub_80EFFE0(u8);

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

u8 special_0x44(void)
{
    u8 i;
    u8 j;
    u8 selIdx;
    struct TVShowMassOutbreak *massOutbreak;

    for (i = 5; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 1; i ++)
    {
        if (gSaveBlock1Ptr->tvShows[i].common.var00 == 0)
        {
            break;
        }
    }
    j = Random() % i;
    selIdx = j;
    do
    {
        if (sub_80EFFE0(gSaveBlock1Ptr->tvShows[j].common.var00) != 4)
        {
            if (gSaveBlock1Ptr->tvShows[j].common.var01 == TRUE)
            {
                return j;
            }
        }
        else
        {
            massOutbreak = &gSaveBlock1Ptr->tvShows[j].massOutbreak;
            if (massOutbreak->var16 == 0 && massOutbreak->var01 == TRUE)
            {
                return j;
            }
        }
        if (j == 0)
        {
            j = ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 2;
        }
        else
        {
            j --;
        }
    } while (j != selIdx);
    return 0xFF;
}
