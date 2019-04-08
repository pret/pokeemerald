#include "global.h"
#include "braille_puzzles.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/map_types.h"
#include "constants/songs.h"

// static functions
static void task08_080C9820(u8 taskId);
static void sub_8135578(u8 taskId);
static void sub_813552C(u8 taskId);
static void sub_813561C(u8 taskId);
static void sub_81356C4(void);
static void sub_8135714(void);

// text
bool8 CheckObjectGraphicsInFrontOfPlayer(u8 graphicsId)
{
    u8 eventObjId;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    gPlayerFacingPosition.height = PlayerGetZCoord();
    eventObjId = GetEventObjectIdByXYZ(gPlayerFacingPosition.x, gPlayerFacingPosition.y, gPlayerFacingPosition.height);
    if (gEventObjects[eventObjId].graphicsId != graphicsId)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_LastTalked = gEventObjects[eventObjId].localId;
        return TRUE;
    }
}

u8 oei_task_add(void)
{
    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    return CreateTask(task08_080C9820, 8);
}

static void task08_080C9820(u8 taskId)
{
    u8 eventObjId;

    ScriptContext2_Enable();
    gPlayerAvatar.preventStep = TRUE;
    eventObjId = gPlayerAvatar.eventObjectId;
    if (!EventObjectIsMovementOverridden(&gEventObjects[eventObjId])
     || EventObjectClearHeldMovementIfFinished(&gEventObjects[eventObjId]))
    {
        if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
        {
            FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
            gTasks[taskId].func = sub_8135578;
        }
        else
        {
            sub_808C114();
            EventObjectSetHeldMovement(&gEventObjects[eventObjId], MOVEMENT_ACTION_START_ANIM_IN_DIRECTION);
            gTasks[taskId].func = sub_813552C;
        }
    }
}

static void sub_813552C(u8 taskId)
{
    if (EventObjectCheckHeldMovementStatus(&gEventObjects[gPlayerAvatar.eventObjectId]) == TRUE)
    {
        FieldEffectStart(FLDEFF_FIELD_MOVE_SHOW_MON_INIT);
        gTasks[taskId].func = sub_8135578;
    }
}

static void sub_8135578(u8 taskId)
{
    if (!FieldEffectActiveListContains(FLDEFF_FIELD_MOVE_SHOW_MON))
    {
        gFieldEffectArguments[1] = GetPlayerFacingDirection();
        if (gFieldEffectArguments[1] == 1)
            gFieldEffectArguments[2] = 0;
        if (gFieldEffectArguments[1] == 2)
            gFieldEffectArguments[2] = 1;
        if (gFieldEffectArguments[1] == 3)
            gFieldEffectArguments[2] = 2;
        if (gFieldEffectArguments[1] == 4)
            gFieldEffectArguments[2] = 3;
        EventObjectSetGraphicsId(&gEventObjects[gPlayerAvatar.eventObjectId], GetPlayerAvatarGraphicsIdByCurrentState());
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
    // In Ruby and Sapphire, Regirock's tomb is opened by using Strength. In Emerald,
    // it is opened by using Rock Smash.
    if (ShouldDoBrailleRegirockEffect())
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = SetUpPuzzleEffectRegirock;
        return TRUE;
    }
    else if (CheckObjectGraphicsInFrontOfPlayer(EVENT_OBJ_GFX_BREAKABLE_ROCK) == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = sub_81356C4;
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
    ScriptContext1_SetupScript(EventScript_FldEffRockSmash);
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
