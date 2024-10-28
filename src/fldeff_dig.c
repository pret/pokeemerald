#include "global.h"
#include "braille_puzzles.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sprite.h"
#include "constants/field_effects.h"

// static functions
static void FieldCallback_Dig(void);
static void StartDigFieldEffect(void);

// text
bool8 SetUpFieldMove_Dig(void)
{
    if (CanUseDigOrEscapeRopeOnCurMap() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Dig;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void FieldCallback_Dig(void)
{
    Overworld_ResetStateAfterDigEscRope();
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseDig);
}

bool8 FldEff_UseDig(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartDigFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartDigFieldEffect;
    if (!ShouldDoBrailleDigEffect())
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

static void StartDigFieldEffect(void)
{
    u8 taskId;

    FieldEffectActiveListRemove(FLDEFF_USE_DIG);
    if (ShouldDoBrailleDigEffect())
    {
        // EventScript_DigSealedChamber handles DoBrailleDigEffect call
        ScriptContext_Enable();
    }
    else
    {
        taskId = CreateTask(Task_UseDigEscapeRopeOnField, 8);
        gTasks[taskId].data[0] = 0;
    }
}
