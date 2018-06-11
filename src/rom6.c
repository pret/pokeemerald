#include "global.h"
#include "constants/map_objects.h"
#include "constants/songs.h"
#include "rom6.h"
#include "braille_puzzles.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "item_use.h"
#include "party_menu.h"
#include "overworld.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"

// static functions
static void task08_080C9820(u8 taskId);
static void sub_8135578(u8 taskId);
static void sub_813552C(u8 taskId);
static void sub_813561C(u8 taskId);
static void sub_81356C4(void);
static void sub_8135714(void);
static void hm2_dig(void);
static void sub_8135780(void);

// extern RAM loc
extern struct MapPosition gUnknown_0203AB40;

// text
bool8 npc_before_player_of_type(u8 a)
{
    u8 mapObjId;

    GetXYCoordsOneStepInFrontOfPlayer(&gUnknown_0203AB40.x, &gUnknown_0203AB40.y);
    gUnknown_0203AB40.height = PlayerGetZCoord();
    mapObjId = GetFieldObjectIdByXYZ(gUnknown_0203AB40.x, gUnknown_0203AB40.y, gUnknown_0203AB40.height);
    if (gMapObjects[mapObjId].graphicsId != a)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_LastTalked = gMapObjects[mapObjId].localId;
        return TRUE;
    }
}

u8 oei_task_add(void)
{
    GetXYCoordsOneStepInFrontOfPlayer(&gUnknown_0203AB40.x, &gUnknown_0203AB40.y);
    return CreateTask(task08_080C9820, 8);
}

static void task08_080C9820(u8 taskId)
{
    u8 mapObjId;

    ScriptContext2_Enable();
    gPlayerAvatar.preventStep = TRUE;
    mapObjId = gPlayerAvatar.mapObjectId;
    if (!FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(&gMapObjects[mapObjId])
     || FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[mapObjId]))
    {
        if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
        {
            FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
            gTasks[taskId].func = sub_8135578;
        }
        else
        {
            sub_808C114();
            FieldObjectSetSpecialAnim(&gMapObjects[mapObjId], 0x39);
            gTasks[taskId].func = sub_813552C;
        }
    }
}

static void sub_813552C(u8 taskId)
{
    if (FieldObjectCheckIfSpecialAnimFinishedOrInactive(&gMapObjects[gPlayerAvatar.mapObjectId]) == TRUE)
    {
        FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
        gTasks[taskId].func = sub_8135578;
    }
}

static void sub_8135578(u8 taskId)
{
    if (!FieldEffectActiveListContains(6))
    {
        gFieldEffectArguments[1] = player_get_direction_lower_nybble();
        if (gFieldEffectArguments[1] == 1)
            gFieldEffectArguments[2] = 0;
        if (gFieldEffectArguments[1] == 2)
            gFieldEffectArguments[2] = 1;
        if (gFieldEffectArguments[1] == 3)
            gFieldEffectArguments[2] = 2;
        if (gFieldEffectArguments[1] == 4)
            gFieldEffectArguments[2] = 3;
        FieldObjectSetGraphicsId(&gMapObjects[gPlayerAvatar.mapObjectId], GetPlayerAvatarGraphicsIdByCurrentState());
        StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], gFieldEffectArguments[2]);
        FieldEffectActiveListRemove(6);
        gTasks[taskId].func = sub_813561C;
    }
}

static void sub_813561C(u8 taskId)
{
    void (*func)(void) = (void (*)(void))(((u16)gTasks[taskId].data[8] << 16) | (u16)gTasks[taskId].data[9]);

    func();
    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(taskId);
}

bool8 SetUpFieldMove_RockSmash(void)
{
    if(ShouldDoBrailleStrengthEffect())
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gUnknown_03005DB0 = FieldCallback_Teleport;
        gUnknown_0203CEEC = sub_8179834;
        return TRUE;
    }
    else if (npc_before_player_of_type(0x56) == TRUE)
    {
        gUnknown_03005DB0 = FieldCallback_Teleport;
        gUnknown_0203CEEC = sub_81356C4;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void sub_81356C4(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(Route111_EventScript_2907F0);
}

bool8 FldEff_UseRockSmash(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)sub_8135714 >> 16;
    gTasks[taskId].data[9] = (u32)sub_8135714;
    IncrementGameStat(GAME_STAT_USED_ROCK_SMASH);
    return FALSE;
}

static void sub_8135714(void)
{
    PlaySE(SE_W088);
    FieldEffectActiveListRemove(FLDEFF_USE_ROCK_SMASH);
    EnableBothScriptContexts();
}

bool8 SetUpFieldMove_Dig(void)
{
    if (CanUseEscapeRopeOnCurrMap() == TRUE)
    {
        gUnknown_03005DB0 = FieldCallback_Teleport;
        gUnknown_0203CEEC = hm2_dig;
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
        SetPlayerAvatarTransitionFlags(1);
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
        taskId = CreateTask(task08_080A1C44, 8);
        gTasks[taskId].data[0] = 0;
    }
}
