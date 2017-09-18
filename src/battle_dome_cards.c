
// Includes
#include "global.h"

// Static type declarations

struct BattleDomeCard {
    u8 unk_00[12];
};

// Static RAM declarations

extern struct BattleDomeCard gUnknown_0203CD04[8];

// Static ROM declarations

// .rodata

extern const struct BattleDomeCard gUnknown_0860B058;

// .text

void nullsub_122(void)
{

}

bool8 dp13_810BB8C(void)
{
    int i;

    for (i = 0; i < 8; i ++)
    {
        gUnknown_0203CD04[i] = gUnknown_0860B058;
    }
    return FALSE;
}
