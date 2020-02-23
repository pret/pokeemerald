#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "fldeff.h"
#include "party_menu.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"

// static functions
static void FldEff_UseStrength(void);
static void sub_8145E74(void);

// text
bool8 SetUpFieldMove_Strength(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER) == TRUE)
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FldEff_UseStrength;
        return TRUE;
    }
    return FALSE;
}

static void FldEff_UseStrength(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_FldEffStrength);
}

bool8 sub_8145E2C(void)
{
    u8 taskId = oei_task_add();
    gTasks[taskId].data[8] = (u32)sub_8145E74 >> 16;
    gTasks[taskId].data[9] = (u32)sub_8145E74;
    GetMonNickname(&gPlayerParty[gFieldEffectArguments[0]], gStringVar1);
    return FALSE;
}

static void sub_8145E74(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_STRENGTH);
    EnableBothScriptContexts();
}
