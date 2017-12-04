#include "global.h"
#include "field_effect.h"
#include "task.h"

extern bool8 is_light_level_1_2_3_or_6(u8 mapType);
extern void* hm_add_c3_launch_phase_2(void);
extern void hm_teleport_run_dp02scr(void);
extern void* gUnknown_0203CEEC;
extern void* gUnknown_03005DB0;
extern void sub_808469C(void);
extern u8 GetCursorSelectionMonId(void);
extern void sub_817C94C(void);
extern u8 oei_task_add(void);
extern void FieldEffectActiveListRemove(u8 id);
extern void sub_80B7FC8(void);
extern void SetPlayerAvatarTransitionFlags(u8);


// 817C8BC
bool8 SetUpFieldMove_Teleport()
{
    if (is_light_level_1_2_3_or_6(gMapHeader.mapType) == TRUE)
    {
        gUnknown_03005DB0 = hm_add_c3_launch_phase_2;
        gUnknown_0203CEEC = hm_teleport_run_dp02scr;   
        return TRUE;
    } 
    return FALSE;
}

// 817C8FC
void hm_teleport_run_dp02scr()
{
    sub_808469C();
    FieldEffectStart(0x3F);
    gFieldEffectArguments[0] = (u32)GetCursorSelectionMonId();
}

// 817C91C
u8 FldEff_UseTeleport()
{
    u8 taskID = oei_task_add();
    gTasks[taskID].data[8] = (u32)sub_817C94C >> 16;
    gTasks[taskID].data[9] = (u32)sub_817C94C;
    SetPlayerAvatarTransitionFlags(1);
    return 0;
}

void sub_817C94C()
{
    FieldEffectActiveListRemove(0x3F);
    sub_80B7FC8();
}


