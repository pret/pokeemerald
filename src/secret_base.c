
// Includes
#include "global.h"
#include "list_menu.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "text.h"
#include "event_data.h"
#include "secret_base.h"

// Static type declarations

struct SecretBaseListMenuBuffer {
    struct ListMenuItem items[11];
    u8 names[11][32];
};

// Static RAM declarations
EWRAM_DATA u8 sCurSecretBaseId = 0;
EWRAM_DATA u8 gUnknown_0203A01D = 0;
EWRAM_DATA struct SecretBaseListMenuBuffer *gUnknown_0203A020 = NULL;

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

void ResetSecretBases(void)
{
    u16 i;

    for (i = 0; i < 20; i ++)
    {
        sub_80E8AF0(&gSaveBlock1Ptr->secretBases[i]);
    }
}

void sub_80E8B58(void)
{
    sCurSecretBaseId = gSpecialVar_0x8004;
}

void sub_80E8B6C(void)
{
    u16 i;

    gScriptResult = FALSE;
    for (i = 0; i < 20; i ++)
    {
        if (sCurSecretBaseId != gSaveBlock1Ptr->secretBases[i].secretBaseId)
        {
            continue;
        }
        gScriptResult = TRUE;
        VarSet(VAR_0x4054, i);
        break;
    }
}

void sub_80E8BC8(void)
{
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId != 0)
    {
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

// .rodata

// .text
