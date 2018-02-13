#include "global.h"
#include "field_effect.h"
#include "rom6.h"
#include "party_menu.h"

#include "script.h"

extern u16 gSpecialVar_Result;
extern void (*gUnknown_0203CEEC)(void);
extern bool8 (*gUnknown_03005DB0)(void);
static void sub_8145E0C(void);

extern u8 FieryPath_EventScript_2908FD[];

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

static void sub_8145E0C(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(FieryPath_EventScript_2908FD);
}

/*
#include "braille_puzzles.h"
#include "field_effect.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_menu.h"

#include "script.h"
#include "task.h"
#include "text.h"

static void sub_811AA18(void);
static void sub_811AA38(void);
static void sub_811AA9C(void);

extern u8 gLastFieldPokeMenuOpened;
extern u16 gSpecialVar_Result;
extern void (*gFieldCallback)(void);
extern void (*gUnknown_03005CE4)(void);

extern u8 S_UseStrength[];

bool8 SetUpFieldMove_Strength(void)
{
    if (ShouldDoBrailleStrengthEffect())
    {
        gSpecialVar_Result = gLastFieldPokeMenuOpened;
        gFieldCallback = FieldCallback_Teleport;
        gUnknown_03005CE4 = sub_811AA38;
    }
    else
    {
        if (npc_before_player_of_type(87) != TRUE)
            return 0;
        gSpecialVar_Result = gLastFieldPokeMenuOpened;
        gFieldCallback = FieldCallback_Teleport;
        gUnknown_03005CE4 = sub_811AA18;
    }

    return TRUE;
}

static void sub_811AA18(void)
{
    gFieldEffectArguments[0] = gLastFieldPokeMenuOpened;
    ScriptContext1_SetupScript(S_UseStrength);
}

static void sub_811AA38(void)
{
    gFieldEffectArguments[0] = gLastFieldPokeMenuOpened;
    FieldEffectStart(FLDEFF_USE_STRENGTH);
}

bool8 FldEff_UseStrength(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)sub_811AA9C >> 16;
    gTasks[taskId].data[9] = (u32)sub_811AA9C;
    GetMonNickname(&gPlayerParty[gFieldEffectArguments[0]], gStringVar1);
    return FALSE;
}

static void sub_811AA9C(void)
{
    if (ShouldDoBrailleStrengthEffect())
    {
        DoBrailleStrengthEffect();
    }
    else
    {
        FieldEffectActiveListRemove(40);
        EnableBothScriptContexts();
    }
}
*/
