
// Includes
#include "global.h"
#include "list_menu.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_player_avatar.h"
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

// .rodata

extern const struct {
    u16 tile1;
    u16 tile2;
} gUnknown_0858CFCC[7];

// .text

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

u8 sub_80E8BF8(void)
{
    s16 x;
    s16 y;
    s16 behavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y) & 0xFFF;
    if (behavior == 0x90 || behavior == 0x91)
    {
        return 1;
    }
    if (behavior == 0x92 || behavior == 0x93)
    {
        return 2;
    }
    if (behavior == 0x9a || behavior == 0x9b)
    {
        return 3;
    }
    if (behavior == 0x94 || behavior == 0x95)
    {
        return 4;
    }
    if (behavior == 0x96 || behavior == 0x97 || behavior == 0x9c || behavior == 0x9d)
    {
        return 5;
    }
    if (behavior == 0x98 || behavior == 0x99)
    {
        return 6;
    }
    return 0;
}

void sub_80E8C98(void)
{
    gSpecialVar_0x8007 = sub_80E8BF8();
}

#ifdef NONMATCHING
// This function was refactored in some mysterious way
void sub_80E8CB0(s16 *xPtr, s16 *yPtr, u16 tile)
{
    struct MapData *mapData;
    s16 x;
    s16 y;

    mapData = gMapHeader.mapData;
    for (y = 0; y < mapData->height; y ++)
    {
        for (x = 0; x < mapData->width; x ++)
        {
            if ((mapData->map[y * mapData->width + x] % 0x400) == tile)
            {
                *xPtr = x;
                *yPtr = y;
                return;
            }
        }
    }
}
#else
__attribute__((naked)) void sub_80E8CB0(s16 *xPtr, s16 *yPtr, u16 tile)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tsub sp, 0x8\n"
                    "\tstr r0, [sp]\n"
                    "\tstr r1, [sp, 0x4]\n"
                    "\tlsls r2, 16\n"
                    "\tlsrs r2, 16\n"
                    "\tmov r10, r2\n"
                    "\tldr r0, =gMapHeader\n"
                    "\tldr r0, [r0]\n"
                    "\tmov r8, r0\n"
                    "\tmovs r0, 0\n"
                    "\tmov r12, r0\n"
                    "\tmov r1, r8\n"
                    "\tldr r0, [r1, 0x4]\n"
                    "\tcmp r12, r0\n"
                    "\tbge _080E8D3C\n"
                    "\tldr r4, [r1]\n"
                    "_080E8CDA:\n"
                    "\tmovs r2, 0\n"
                    "\tmov r0, r12\n"
                    "\tlsls r7, r0, 16\n"
                    "\tcmp r2, r4\n"
                    "\tbge _080E8D28\n"
                    "\tasrs r0, r7, 16\n"
                    "\tadds r6, r0, 0\n"
                    "\tmuls r6, r4\n"
                    "\tmov r1, r8\n"
                    "\tldr r5, [r1, 0xC]\n"
                    "\tldr r0, =0x000003ff\n"
                    "\tmov r9, r0\n"
                    "_080E8CF2:\n"
                    "\tlsls r0, r2, 16\n"
                    "\tasrs r3, r0, 16\n"
                    "\tadds r0, r6, r3\n"
                    "\tlsls r0, 1\n"
                    "\tadds r0, r5\n"
                    "\tldrh r1, [r0]\n"
                    "\tmov r0, r9\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, r10\n"
                    "\tbne _080E8D1C\n"
                    "\tldr r1, [sp]\n"
                    "\tstrh r2, [r1]\n"
                    "\tmov r0, r12\n"
                    "\tldr r2, [sp, 0x4]\n"
                    "\tstrh r0, [r2]\n"
                    "\tb _080E8D3C\n"
                    "\t.pool\n"
                    "_080E8D1C:\n"
                    "\tadds r0, r3, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r2, r0, 16\n"
                    "\tasrs r0, 16\n"
                    "\tcmp r0, r4\n"
                    "\tblt _080E8CF2\n"
                    "_080E8D28:\n"
                    "\tmovs r2, 0x80\n"
                    "\tlsls r2, 9\n"
                    "\tadds r1, r7, r2\n"
                    "\tlsrs r0, r1, 16\n"
                    "\tmov r12, r0\n"
                    "\tasrs r1, 16\n"
                    "\tmov r2, r8\n"
                    "\tldr r0, [r2, 0x4]\n"
                    "\tcmp r1, r0\n"
                    "\tblt _080E8CDA\n"
                    "_080E8D3C:\n"
                    "\tadd sp, 0x8\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0");
}
#endif

void sub_80E8D4C(void)
{
    s16 x;
    s16 y;
    s16 tile;
    u16 i;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tile = MapGridGetMetatileIdAt(x, y);
    for (i = 0; i < 7; i ++)
    {
        if (gUnknown_0858CFCC[i].tile1 == tile)
        {
            MapGridSetMetatileIdAt(x, y, gUnknown_0858CFCC[i].tile2 | 0xC00);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
    for (i = 0; i < 7; i ++)
    {
        if (gUnknown_0858CFCC[i].tile2 == tile)
        {
            MapGridSetMetatileIdAt(x, y, gUnknown_0858CFCC[i].tile1 | 0xC00);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
}
