#include "global.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"

extern void sub_81A3ACC(void);

extern const u32 gUnknown_085DF9AC[][2];
extern const u32 gUnknown_085DF9CC[][2];
extern void (* const gUnknown_085DF96C[])(void);

// This file's functions.
void sub_8164ED8(void);
u16 sub_8164FCC(u8, u8);

// code
void sub_8161F74(void)
{
    gUnknown_085DF96C[gSpecialVar_0x8004]();
}

void sub_8161F94(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.field_CA8 = 1;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    sub_81A3ACC();
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_085DF9AC[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] = 0;

    sub_8164ED8();
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

void sub_8162054(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case 1:
        gSpecialVar_Result = sub_8164FCC(lvlMode, battleMode);
        break;
    case 2:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_085DF9AC[battleMode][lvlMode]) != 0);
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D07 = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    }
}

void sub_81620F4(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        break;
    case 1:
        gSaveBlock2Ptr->frontier.field_CE0[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_085DF9AC[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_085DF9CC[battleMode][lvlMode];
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D07 = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    }
}
