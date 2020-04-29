#include "global.h"
#include "braille_puzzles.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "overworld.h"
#include "party_menu.h"
#include "sprite.h"
#include "constants/field_effects.h"

// static functions
static void hm2_dig(void);
static void sub_8135780(void);

// text
bool8 SetUpFieldMove_Dig(void)
{
    if (CanUseDigOrEscapeRopeOnCurMap() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = hm2_dig;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void hm2_dig(void)
{
    Overworld_ResetStateAfterDigEscRope();
    FieldEffectStart(FLDEFF_USE_DIG);
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
}

bool8 FldEff_UseDig(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)sub_8135780 >> 16;
    gTasks[taskId].data[9] = (u32)sub_8135780;
    if (!ShouldDoBrailleDigEffect())
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

static void sub_8135780(void)
{
    u8 taskId;

    FieldEffectActiveListRemove(FLDEFF_USE_DIG);
    if (ShouldDoBrailleDigEffect())
    {
        DoBrailleDigEffect();
    }
    else
    {
        taskId = CreateTask(Task_UseDigEscapeRopeOnField, 8);
        gTasks[taskId].data[0] = 0;
    }
}
