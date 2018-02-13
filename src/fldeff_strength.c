#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "party_menu.h"
#include "rom6.h"
#include "script.h"
#include "task.h"

void sub_8145E0C(void);
void sub_8145E74(void);

bool8 hm_prepare_rocksmash(void)
{
    if (npc_before_player_of_type(87) == TRUE)
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gUnknown_03005DB0 = FieldCallback_Teleport;
        gUnknown_0203CEEC = sub_8145E0C;
        return TRUE;
    }
    return FALSE;
}

void sub_8145E0C(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(FieryPath_EventScript_2908FD);
}

bool8 sub_8145E2C(void)
{
    u8 taskId = oei_task_add();
    gTasks[taskId].data[8] = (u32)sub_8145E74 >> 16;
    gTasks[taskId].data[9] = (u32)sub_8145E74;
    GetMonNickname(&gPlayerParty[gFieldEffectArguments[0]], gStringVar1);
    return FALSE;
}

void sub_8145E74(void)
{
    FieldEffectActiveListRemove(40);
    EnableBothScriptContexts();
}
