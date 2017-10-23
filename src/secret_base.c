
// Includes
#include "global.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "text.h"
#include "secret_base.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

void sub_80E8AF0(struct SecretBaseRecord *sbr)
{
    u16 i;

    CpuFastFill16(0, sbr, sizeof(struct SecretBaseRecord));
    for (i = 0; i < 7; i ++)
    {
        sbr->trainerName[i] = EOS;
    }
}

// .rodata

// .text
