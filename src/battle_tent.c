
// Includes
#include "global.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_tower.h"
#include "battle_frontier_2.h"
#include "rng.h"
#include "item.h"
#include "items.h"

// Static type declarations

// Static RAM declarations

// Static ROM declarations

void sub_81B99D4(void);
void sub_81B9A28(void);
void sub_81B9A44(void);
void sub_81B9A60(void);
void sub_81B9A90(void);
void sub_81B9ABC(void);
void sub_81B9B00(void);
void sub_81B9B28(void);
void sub_81B9BA0(void);
void sub_81B9BF4(void);
void sub_81B9C10(void);
void sub_81B9C2C(void);
void sub_81B9C70(void);
void sub_81B9C98(void);
void sub_81B9CF0(void);
void sub_81B9D28(void);
void sub_81B9D7C(void);
void sub_81B9D98(void);
void sub_81B9DB4(void);
void sub_81B9DF8(void);
void sub_81B9E20(void);
void sub_81B9E78(void);
void sub_81B9E88(void);
void sub_81BA040(void);
void sub_81B9EC0(void);

// .rodata

void (*const gUnknown_086160B4[])(void) = {
    sub_81B99D4,
    sub_81B9A28,
    sub_81B9A44,
    sub_81B9A60,
    sub_81B9A90,
    sub_81B9ABC,
    sub_81B9B00,
    sub_81B9B28
};

const u16 gUnknown_086160D4[] = {ITEM_NEST_BALL, ITEM_NONE};

void (*const gUnknown_086160D8[])(void) = {
    sub_81B9BA0,
    sub_81B9BF4,
    sub_81B9C10,
    sub_81B9C2C,
    sub_81B9C70,
    sub_81B9C98,
    sub_81B9CF0
};

const u16 gUnknown_086160F4[] = {ITEM_HYPER_POTION, ITEM_NONE};

void (*const gUnknown_086160F8[])(void) = {
    sub_81B9D28,
    sub_81B9D7C,
    sub_81B9D98,
    sub_81B9DB4,
    sub_81B9DF8,
    sub_81B9E20,
    sub_81B9E78,
    sub_81B9E88,
    sub_81BA040,
    sub_81B9EC0
};

const u16 gUnknown_08616120[] = {ITEM_FULL_HEAL, ITEM_NONE};

// .text

void sub_81B99B4(void)
{
    gUnknown_086160B4[gSpecialVar_0x8004]();
}

void sub_81B99D4(void)
{
    gSaveBlock2Ptr->field_CA8 = 0;
    gSaveBlock2Ptr->field_CB2 = 0;
    gSaveBlock2Ptr->field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9A28(void)
{
    gScriptResult = gSaveBlock2Ptr->field_E6A;
}

void sub_81B9A44(void)
{
    gSaveBlock2Ptr->field_E6A = gSpecialVar_0x8006;
}

void sub_81B9A60(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) >> 6;
    sub_8162614(gTrainerBattleOpponent_A, 0);
}

void sub_81B9A90(void)
{
    if (gTrainerBattleOpponent_A < 300)
    {
        ConvertBattleFrontierTrainerSpeechToString(gUnknown_0203BC88[gTrainerBattleOpponent_A].speechBefore);
    }
}

void sub_81B9ABC(void)
{
    gSaveBlock2Ptr->field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_0x4000, 0);
    gSaveBlock2Ptr->field_CA9_a = TRUE;
    sub_81A4C30();
}

void sub_81B9B00(void)
{
    gSaveBlock2Ptr->field_E6A = gUnknown_086160D4[Random() % 1];
}

void sub_81B9B28(void)
{
    if (AddBagItem(gSaveBlock2Ptr->field_E6A, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->field_E6A, gStringVar1);
        gSaveBlock2Ptr->field_E6A = ITEM_NONE;
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

void sub_81B9B80(void)
{
    gUnknown_086160D8[gSpecialVar_0x8004]();
}

void sub_81B9BA0(void)
{
    gSaveBlock2Ptr->field_CA8 = 0;
    gSaveBlock2Ptr->field_CB2 = 0;
    gSaveBlock2Ptr->field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9BF4(void)
{
    gScriptResult = gSaveBlock2Ptr->field_E6C;
}

void sub_81B9C10(void)
{
    gSaveBlock2Ptr->field_E6C = gSpecialVar_0x8006;
}

void sub_81B9C2C(void)
{
    gSaveBlock2Ptr->field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_0x4000, 0);
    gSaveBlock2Ptr->field_CA9_a = TRUE;
    sub_81A4C30();
}

void sub_81B9C70(void)
{
    gSaveBlock2Ptr->field_E6C = gUnknown_086160F4[Random() % 1];
}

void sub_81B9C98(void)
{
    if (AddBagItem(gSaveBlock2Ptr->field_E6C, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->field_E6C, gStringVar1);
        gSaveBlock2Ptr->field_E6C = ITEM_NONE;
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

void sub_81B9CF0(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void sub_81B9D08(void)
{
    gUnknown_086160F8[gSpecialVar_0x8004]();
}

void sub_81B9D28(void)
{
    gSaveBlock2Ptr->field_CA8 = 0;
    gSaveBlock2Ptr->field_CB2 = 0;
    gSaveBlock2Ptr->field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

void sub_81B9D7C(void)
{
    gScriptResult = gSaveBlock2Ptr->field_E6E;
}

void sub_81B9D98(void)
{
    gSaveBlock2Ptr->field_E6E = gSpecialVar_0x8006;
}

void sub_81B9DB4(void)
{
    gSaveBlock2Ptr->field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_0x4000, 0);
    gSaveBlock2Ptr->field_CA9_a = TRUE;
    sub_81A4C30();
}

void sub_81B9DF8(void)
{
    gSaveBlock2Ptr->field_E6E = gUnknown_08616120[Random() % 1];
}

void sub_81B9E20(void)
{
    if (AddBagItem(gSaveBlock2Ptr->field_E6E, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->field_E6E, gStringVar1);
        gSaveBlock2Ptr->field_E6E = ITEM_NONE;
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

void sub_81B9E78(void)
{
    ZeroPlayerPartyMons();
    sub_819A4F8();
}

void sub_81B9E88(void)
{
    sub_819DC00();
}

bool8 sub_81B9E94(void)
{
    return (gMapHeader.regionMapSectionId == REGION_MAP_SLATEPORT_CITY && ((gMapHeader.mapDataId == 385) | (gMapHeader.mapDataId == 386)) ? TRUE : FALSE);
}
