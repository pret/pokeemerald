
// Includes
#include "global.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

// .rodata

// .text

u32 sub_81D1574(u8 *a)
{
    switch (*a)
    {
        case 0:
        default:
            return 0;
        case 1:
        case 5:
            return 1;
        case 2:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
    }
}
