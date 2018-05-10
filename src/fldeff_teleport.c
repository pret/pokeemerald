#include "global.h"
#include "fldeff_teleport.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "party_menu.h"
#include "overworld.h"
#include "rom6.h"
#include "task.h"

bool8 SetUpFieldMove_Teleport(void)
{
    if (Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
    {
        gUnknown_03005DB0 = FieldCallback_Teleport;
        gUnknown_0203CEEC = hm_teleport_run_dp02scr;
        return TRUE;
    }
    return FALSE;
}

void hm_teleport_run_dp02scr(void)
{
    Overworld_ResetStateAfterTeleport();
    FieldEffectStart(FLDEFF_USE_TELEPORT);
    gFieldEffectArguments[0] = (u32)GetCursorSelectionMonId();
}

bool8 FldEff_UseTeleport(void)
{
    u8 taskId = oei_task_add();
    gTasks[taskId].data[8] = (u32)sub_817C94C >> 16;
    gTasks[taskId].data[9] = (u32)sub_817C94C;
    SetPlayerAvatarTransitionFlags(1);
    return FALSE;
}

void sub_817C94C(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TELEPORT);
    CreateTeleportFieldEffectTask();
}


