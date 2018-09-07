#include "global.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"

extern void sub_8162614(u16, u8);

extern void (* const gUnknown_0860DE50[])(void);
extern const u32 gUnknown_0860DE98[][2];
extern const u32 gUnknown_0860DEA8[][2];

// code
void sub_8195960(void)
{
    gUnknown_0860DE50[gSpecialVar_0x8004]();
}

void sub_8195980(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860DE98[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode] = 0;

    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

void sub_8195A38(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_DC4[1];
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode];
        break;
    case 2:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860DE98[battleMode][lvlMode]) != 0);
        break;
    }
}

void sub_8195AE4(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_DC4[1] = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_0860DE98[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_0860DEA8[battleMode][lvlMode];
        break;
    }
}

void sub_8195BB0(void)
{
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode] < 50)
        gSpecialVar_Result = Random() % 3;
    else if (gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode] < 99)
        gSpecialVar_Result = 3;
    else
        gSpecialVar_Result = 4;
}

void sub_8195C20(void)
{
    gTrainerBattleOpponent_A = 5 *(Random() % 255) / 64u;
    sub_8162614(gTrainerBattleOpponent_A, 0);
}

void sub_8195C50(void)
{
    if (gTrainerBattleOpponent_A < 300)
        ConvertBattleFrontierTrainerSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

/*
void sub_8195C7C(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    if (gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode] < 9999)
    {
        u16 wat = 0;
        gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode]++;
        if (lvlMode < gSaveBlock2Ptr->frontier.field_DD0[battleMode][lvlMode])
            wat = 1;
        if (gSaveBlock2Ptr->frontier.field_DC8[battleMode][wat] != 0)
            gSaveBlock2Ptr->frontier.field_DD0[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.field_DC8[battleMode][lvlMode];
    }
}
*/
