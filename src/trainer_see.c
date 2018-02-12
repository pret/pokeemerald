#include "global.h"
#include "trainer_see.h"
#include "battle_setup.h"
#include "pokemon.h"
#include "sprite.h"
#include "field_effect.h"
#include "field_map_obj.h"
#include "field_player_avatar.h"
#include "field_map_obj_helpers.h"
#include "pokenav.h"
#include "task.h"
#include "util.h"
#include "script.h"
#include "event_data.h"
#include "script_movement.h"

extern bool8 InBattlePyramid(void);
extern bool32 InTrainerHill(void);
extern bool8 GetBattlePyramidTrainerFlag(u8 mapObjectId);
extern bool8 GetTrainerHillTrainerFlag(u8 mapObjectId);
extern void sub_809BE48(u16 npcId);

// this file's functions
static u8 CheckTrainer(u8 mapObjectId);
static u8 GetTrainerApproachDistance(struct MapObject *trainerObj);
static u8 CheckPathBetweenTrainerAndPlayer(struct MapObject *trainerObj, u8 approachDistance, u8 direction);
static void TrainerApproachPlayer(struct MapObject *trainerObj, u8 range);
static void Task_RunTrainerSeeFuncList(u8 taskId);
static void Task_DestroyTrainerApproachTask(u8 taskId);
static void SetIconSpriteData(struct Sprite *sprite, u16 fldEffId, u8 spriteAnimNum);

static u8 GetTrainerApproachDistanceSouth(struct MapObject *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceNorth(struct MapObject *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceWest(struct MapObject *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceEast(struct MapObject *trainerObj, s16 range, s16 x, s16 y);

static bool8 sub_80B4178(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B417C(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B41C0(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B4200(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B425C(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B4318(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B435C(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B4390(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B43AC(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B43E0(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B4438(u8 taskId, struct Task *task, struct MapObject *trainerObj);
static bool8 sub_80B44AC(u8 taskId, struct Task *task, struct MapObject *trainerObj);

static void SpriteCB_TrainerIcons(struct Sprite *sprite);

// IWRAM common
u16 gUnknown_03006080;
u8 gUnknown_03006084[4];
struct ApproachingTrainer gApproachingTrainers[2];
u8 gNoOfApproachingTrainers;
u8 gUnknown_030060AC;

// EWRAM
EWRAM_DATA u8 gApproachingTrainerId = 0;

// const rom data
static const u8 sEmotion_ExclamationMarkGfx[] = INCBIN_U8("graphics/misc/emotion_exclamation.4bpp");
static const u8 sEmotion_QuestionMarkGfx[] = INCBIN_U8("graphics/misc/emotion_question.4bpp");
static const u8 sEmotion_HeartGfx[] = INCBIN_U8("graphics/misc/emotion_heart.4bpp");

static u8 (*const sDirectionalApproachDistanceFuncs[])(struct MapObject *trainerObj, s16 range, s16 x, s16 y) =
{
    GetTrainerApproachDistanceSouth,
    GetTrainerApproachDistanceNorth,
    GetTrainerApproachDistanceWest,
    GetTrainerApproachDistanceEast,
};

static bool8 (*const sTrainerSeeFuncList[])(u8 taskId, struct Task *task, struct MapObject *trainerObj) =
{
    sub_80B4178,
	sub_80B417C,
	sub_80B41C0,
	sub_80B4200,
	sub_80B425C,
	sub_80B4318,
	sub_80B435C,
	sub_80B4390,
	sub_80B43AC,
	sub_80B43E0,
	sub_80B4438,
	sub_80B44AC
};

static bool8 (*const sTrainerSeeFuncList2[])(u8 taskId, struct Task *task, struct MapObject *trainerObj) =
{
    sub_80B43AC,
    sub_80B43E0,
    sub_80B4438,
    sub_80B44AC,
};

static const struct OamData sOamData_Icons =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sSpriteImageTable_ExclamationQuestionMark[] =
{
    {sEmotion_ExclamationMarkGfx, 0x80},
    {sEmotion_QuestionMarkGfx, 0x80}
};

static const struct SpriteFrameImage sSpriteImageTable_HeartIcon[] =
{
    {sEmotion_HeartGfx, 0x80}
};

static const union AnimCmd sSpriteAnim_Icons1[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Icons2[] =
{
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Icons[] =
{
    sSpriteAnim_Icons1,
    sSpriteAnim_Icons2
};

static const struct SpriteTemplate sSpriteTemplate_ExclamationQuestionMark =
{
    .tileTag = 0xffff,
    .paletteTag = 0xffff,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_ExclamationQuestionMark,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteTemplate sSpriteTemplate_HeartIcon =
{
    .tileTag = 0xffff,
    .paletteTag = 0x1004,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_HeartIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TrainerIcons
};

// code
bool8 CheckForTrainersWantingBattle(void)
{
    u8 i;

    gNoOfApproachingTrainers = 0;
    gApproachingTrainerId = 0;

    for (i = 0; i < MAP_OBJECTS_COUNT; i++)
    {
        u8 retVal;

        if (!gMapObjects[i].active)
            continue;
        if (gMapObjects[i].trainerType != 1 && gMapObjects[i].trainerType != 3)
            continue;

        retVal = CheckTrainer(i);
        if (retVal == 2)
            break; // two trainers have been found

        if (retVal == 0) // no trainers
            continue;

        if (gNoOfApproachingTrainers > 1)
            break;
        if (GetMonsStateToDoubles_2() != 0) // one trainer found and cant have a double battle
            break;
    }

    if (gNoOfApproachingTrainers == 1)
    {
        ResetTrainerOpponentIds();
        ConfigureAndSetUpOneTrainerBattle(gApproachingTrainers[gNoOfApproachingTrainers - 1].mapObjectId,
                                          gApproachingTrainers[gNoOfApproachingTrainers - 1].trainerScriptPtr);
        gUnknown_030060AC = 1;
        return TRUE;
    }
    else if (gNoOfApproachingTrainers == 2)
    {
        ResetTrainerOpponentIds();
        for (i = 0; i < gNoOfApproachingTrainers; i++, gApproachingTrainerId++)
        {
            ConfigureTwoTrainersBattle(gApproachingTrainers[i].mapObjectId,
                                       gApproachingTrainers[i].trainerScriptPtr);
        }
        SetUpTwoTrainersBattle();
        gApproachingTrainerId = 0;
        gUnknown_030060AC = 1;
        return TRUE;
    }
    else
    {
        gUnknown_030060AC = 0;
        return FALSE;
    }
}

static u8 CheckTrainer(u8 mapObjectId)
{
    const u8 *scriptPtr;
    u8 ret = 1;
    u8 approachDistance;

    if (InTrainerHill() == TRUE)
        scriptPtr = sub_81D62AC();
    else
        scriptPtr = GetFieldObjectScriptPointerByFieldObjectId(mapObjectId);

    if (InBattlePyramid())
    {
        if (GetBattlePyramidTrainerFlag(mapObjectId))
            return 0;
    }
    else if (InTrainerHill() == TRUE)
    {
        if (GetTrainerHillTrainerFlag(mapObjectId))
            return 0;
    }
    else
    {
        if (GetTrainerFlagFromScriptPointer(scriptPtr))
            return 0;
    }

    approachDistance = GetTrainerApproachDistance(&gMapObjects[mapObjectId]);

    if (approachDistance != 0)
    {
        if (scriptPtr[1] == TRAINER_BATTLE_DOUBLE
            || scriptPtr[1] == TRAINER_BATTLE_REMATCH_DOUBLE
            || scriptPtr[1] == TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE)
        {
            if (GetMonsStateToDoubles_2() != 0)
                return 0;

            ret = 2;
        }

        gApproachingTrainers[gNoOfApproachingTrainers].mapObjectId = mapObjectId;
        gApproachingTrainers[gNoOfApproachingTrainers].trainerScriptPtr = scriptPtr;
        gApproachingTrainers[gNoOfApproachingTrainers].radius = approachDistance;
        TrainerApproachPlayer(&gMapObjects[mapObjectId], approachDistance - 1);
        gNoOfApproachingTrainers++;

        return ret;
    }

    return 0;
}

static u8 GetTrainerApproachDistance(struct MapObject *trainerObj)
{
    s16 x, y;
    u8 i;
    u8 approachDistance;

    PlayerGetDestCoords(&x, &y);
    if (trainerObj->trainerType == 1)  // can only see in one direction
    {
        approachDistance = sDirectionalApproachDistanceFuncs[trainerObj->mapobj_unk_18 - 1](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
        return CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, trainerObj->mapobj_unk_18);
    }
    else  // can see in all directions
    {
        for (i = 0; i < 4; i++)
        {
            approachDistance = sDirectionalApproachDistanceFuncs[i](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
            if (CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, i + 1)) // directions are 1-4 instead of 0-3. south north west east
                return approachDistance;
        }
    }

    return 0;
}

// Returns how far south the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceSouth(struct MapObject *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->coords2.x == x
     && y > trainerObj->coords2.y
     && y <= trainerObj->coords2.y + range)
        return (y - trainerObj->coords2.y);
    else
        return 0;
}

// Returns how far north the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceNorth(struct MapObject *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->coords2.x == x
     && y < trainerObj->coords2.y
     && y >= trainerObj->coords2.y - range)
        return (trainerObj->coords2.y - y);
    else
        return 0;
}

// Returns how far west the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceWest(struct MapObject *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->coords2.y == y
     && x < trainerObj->coords2.x
     && x >= trainerObj->coords2.x - range)
        return (trainerObj->coords2.x - x);
    else
        return 0;
}

// Returns how far east the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceEast(struct MapObject *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->coords2.y == y
     && x > trainerObj->coords2.x
     && x <= trainerObj->coords2.x + range)
        return (x - trainerObj->coords2.x);
    else
        return 0;
}

#define COLLISION_MASK (~1)

static u8 CheckPathBetweenTrainerAndPlayer(struct MapObject *trainerObj, u8 approachDistance, u8 direction)
{
    s16 x, y;
    u8 unk19_temp;
    u8 unk19b_temp;
    u8 i;
    u8 collision;

    if (approachDistance == 0)
        return 0;

    x = trainerObj->coords2.x;
    y = trainerObj->coords2.y;

    MoveCoords(direction, &x, &y);
    for (i = 0; i < approachDistance - 1; i++, MoveCoords(direction, &x, &y))
    {
        collision = sub_8092C8C(trainerObj, x, y, direction);
        if (collision != 0 && (collision & COLLISION_MASK))
            return 0;
    }

    // preserve mapobj_unk_19 before clearing.
    unk19_temp = trainerObj->range.as_nybbles.x;
    unk19b_temp = trainerObj->range.as_nybbles.y;
    trainerObj->range.as_nybbles.x = 0;
    trainerObj->range.as_nybbles.y = 0;

    collision = npc_block_way(trainerObj, x, y, direction);

    trainerObj->range.as_nybbles.x = unk19_temp;
    trainerObj->range.as_nybbles.y = unk19b_temp;
    if (collision == 4)
        return approachDistance;

    return 0;
}

#define tFuncId             data[0]
#define tTrainerRange       data[3]
#define tOutOfAshSpriteId   data[4]
#define tTrainerMapObjectId data[7]

static void TrainerApproachPlayer(struct MapObject *trainerObj, u8 range)
{
    struct Task *task;

    gApproachingTrainers[gNoOfApproachingTrainers].taskId = CreateTask(Task_RunTrainerSeeFuncList, 0x50);
    task = &gTasks[gApproachingTrainers[gNoOfApproachingTrainers].taskId];
    task->tTrainerRange = range;
    task->tTrainerMapObjectId = gApproachingTrainers[gNoOfApproachingTrainers].mapObjectId;
}

static void sub_80B40C8(TaskFunc followupFunc)
{
    u8 taskId;
    TaskFunc taskFunc;

    if (gApproachingTrainerId == 0)
        taskId = gApproachingTrainers[0].taskId;
    else
        taskId = gApproachingTrainers[1].taskId;

    taskFunc = Task_RunTrainerSeeFuncList;
    SetTaskFuncWithFollowupFunc(taskId, taskFunc, followupFunc);
    gTasks[taskId].tFuncId = 1;
    taskFunc(taskId);
}

static void Task_RunTrainerSeeFuncList(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct MapObject *trainerObj = &gMapObjects[task->tTrainerMapObjectId];

    if (!trainerObj->active)
    {
        SwitchTaskToFollowupFunc(taskId);
    }
    else
    {
        while (sTrainerSeeFuncList[task->tFuncId](taskId, task, trainerObj));
    }
}

static bool8 sub_80B4178(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    return FALSE;
}

static bool8 sub_80B417C(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    u8 direction;

    FieldObjectGetLocalIdAndMap(trainerObj, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON_1);
    direction = GetFaceDirectionAnimId(trainerObj->mapobj_unk_18);
    FieldObjectSetSpecialAnim(trainerObj, direction);
    task->tFuncId++;
    return TRUE;
}

static bool8 sub_80B41C0(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (FieldEffectActiveListContains(FLDEFF_EXCLAMATION_MARK_ICON_1))
    {
        return FALSE;
    }
    else
    {
        task->tFuncId++;
        if (trainerObj->animPattern == 57 || trainerObj->animPattern == 58)
            task->tFuncId = 6;
        if (trainerObj->animPattern == 63)
            task->tFuncId = 8;
        return TRUE;
    }
}

static bool8 sub_80B4200(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (!(FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(trainerObj)) || FieldObjectClearAnimIfSpecialAnimFinished(trainerObj))
    {
        if (task->tTrainerRange)
        {
            FieldObjectSetSpecialAnim(trainerObj, GetGoSpeed0AnimId(trainerObj->mapobj_unk_18));
            task->tTrainerRange--;
        }
        else
        {
            FieldObjectSetSpecialAnim(trainerObj, 0x3E);
            task->tFuncId++;
        }
    }
    return FALSE;
}

static bool8 sub_80B425C(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    struct MapObject *playerObj;

    if (FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(trainerObj) && !FieldObjectClearAnimIfSpecialAnimFinished(trainerObj))
        return FALSE;

    npc_set_running_behaviour_etc(trainerObj, npc_running_behaviour_by_direction(trainerObj->mapobj_unk_18));
    sub_808F23C(trainerObj, npc_running_behaviour_by_direction(trainerObj->mapobj_unk_18));
    sub_808F208(trainerObj);

    playerObj = &gMapObjects[gPlayerAvatar.mapObjectId];
    if (FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(playerObj) && !FieldObjectClearAnimIfSpecialAnimFinished(playerObj))
        return FALSE;

    sub_808BCE8();
    FieldObjectSetSpecialAnim(&gMapObjects[gPlayerAvatar.mapObjectId], GetFaceDirectionAnimId(GetOppositeDirection(trainerObj->mapobj_unk_18)));
    task->tFuncId++;
    return FALSE;
}

static bool8 sub_80B4318(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    struct MapObject *playerObj = &gMapObjects[gPlayerAvatar.mapObjectId];

    if (!FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(playerObj)
     || FieldObjectClearAnimIfSpecialAnimFinished(playerObj))
        SwitchTaskToFollowupFunc(taskId);
    return FALSE;
}

static bool8 sub_80B435C(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (!FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(trainerObj)
     || FieldObjectClearAnimIfSpecialAnimFinished(trainerObj))
    {
        FieldObjectSetSpecialAnim(trainerObj, 0x59);
        task->tFuncId++;
    }
    return FALSE;
}

static bool8 sub_80B4390(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (FieldObjectClearAnimIfSpecialAnimFinished(trainerObj))
        task->tFuncId = 3;

    return FALSE;
}

static bool8 sub_80B43AC(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (!FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive(trainerObj)
     || FieldObjectClearAnimIfSpecialAnimFinished(trainerObj))
    {
        FieldObjectSetSpecialAnim(trainerObj, 0x3E);
        task->tFuncId++;
    }
    return FALSE;
}

static bool8 sub_80B43E0(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (FieldObjectCheckIfSpecialAnimFinishedOrInactive(trainerObj))
    {
        gFieldEffectArguments[0] = trainerObj->coords2.x;
        gFieldEffectArguments[1] = trainerObj->coords2.y;
        gFieldEffectArguments[2] = gSprites[trainerObj->spriteId].subpriority - 1;
        gFieldEffectArguments[3] = 2;
        task->tOutOfAshSpriteId = FieldEffectStart(FLDEFF_POP_OUT_OF_ASH);
        task->tFuncId++;
    }
    return FALSE;
}

static bool8 sub_80B4438(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    struct Sprite *sprite;

    if (gSprites[task->tOutOfAshSpriteId].animCmdIndex == 2)
    {
        trainerObj->mapobj_bit_26 = 0;
        trainerObj->mapobj_bit_2 = 1;

        sprite = &gSprites[trainerObj->spriteId];
        sprite->oam.priority = 2;
        FieldObjectClearAnimIfSpecialAnimFinished(trainerObj);
        FieldObjectSetSpecialAnim(trainerObj, sub_80934BC(trainerObj->mapobj_unk_18));
        task->tFuncId++;
    }

    return FALSE;
}

static bool8 sub_80B44AC(u8 taskId, struct Task *task, struct MapObject *trainerObj)
{
    if (!FieldEffectActiveListContains(FLDEFF_POP_OUT_OF_ASH))
        task->tFuncId = 3;

    return FALSE;
}

#undef tFuncId
#undef tTrainerRange
#undef tOutOfAshSpriteId
#undef tTrainerMapObjectId

static void sub_80B44C8(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct MapObject *mapObj;

    // another mapObj loaded into by loadword?
    LoadWordFromTwoHalfwords(&task->data[1], (u32 *)&mapObj);
    if (!task->data[7])
    {
        FieldObjectClearAnim(mapObj);
        task->data[7]++;
    }
    sTrainerSeeFuncList2[task->data[0]](taskId, task, mapObj);
    if (task->data[0] == 3 && !FieldEffectActiveListContains(FLDEFF_POP_OUT_OF_ASH))
    {
        npc_set_running_behaviour_etc(mapObj, npc_running_behaviour_by_direction(mapObj->mapobj_unk_18));
        sub_808F23C(mapObj, npc_running_behaviour_by_direction(mapObj->mapobj_unk_18));
        DestroyTask(taskId);
    }
    else
    {
        mapObj->mapobj_bit_7 = 0;
    }
}

void sub_80B4578(struct MapObject *var)
{
    StoreWordInTwoHalfwords(&gTasks[CreateTask(sub_80B44C8, 0)].data[1], (u32)var);
}

void EndTrainerApproach(void)
{
    sub_80B40C8(Task_DestroyTrainerApproachTask);
}

static void Task_DestroyTrainerApproachTask(u8 taskId)
{
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

void sub_80B45D0(void)
{
    if (gNoOfApproachingTrainers == 2)
    {
        if (gApproachingTrainerId == 0)
        {
            gApproachingTrainerId++;
            gSpecialVar_Result = 1;
            UnfreezeMapObjects();
            FreezeMapObjectsExceptOne(gApproachingTrainers[1].mapObjectId);
        }
        else
        {
            gApproachingTrainerId = 0;
            gSpecialVar_Result = 0;
        }
    }
    else
    {
        gSpecialVar_Result = 0;
    }
}

#define sLocalId    data[0]
#define sMapNum     data[1]
#define sMapGroup   data[2]
#define sData3      data[3]
#define sData4      data[4]
#define sFldEffId   data[7]

u8 FldEff_ExclamationMarkIcon1(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_ExclamationQuestionMark, 0, 0, 0x53);

    if (spriteId != MAX_SPRITES)
        SetIconSpriteData(&gSprites[spriteId], FLDEFF_EXCLAMATION_MARK_ICON_1, 0);

    return 0;
}

u8 FldEff_ExclamationMarkIcon2(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_ExclamationQuestionMark, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
        SetIconSpriteData(&gSprites[spriteId], FLDEFF_EXCLAMATION_MARK_ICON_2, 1);

    return 0;
}

u8 FldEff_HeartIcon(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSpriteTemplate_HeartIcon, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_HEART_ICON, 0);
        sprite->oam.paletteNum = 2;
    }

    return 0;
}

static void SetIconSpriteData(struct Sprite *sprite, u16 fldEffId, u8 spriteAnimNum)
{
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = 1;

    sprite->sLocalId = gFieldEffectArguments[0];
    sprite->sMapNum = gFieldEffectArguments[1];
    sprite->sMapGroup = gFieldEffectArguments[2];
    sprite->sData3 = -5;
    sprite->sFldEffId = fldEffId;

    StartSpriteAnim(sprite, spriteAnimNum);
}

static void SpriteCB_TrainerIcons(struct Sprite *sprite)
{
    u8 mapObjId;

    if (TryGetFieldObjectIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &mapObjId)
     || sprite->animEnded)
    {
        FieldEffectStop(sprite, sprite->sFldEffId);
    }
    else
    {
        struct Sprite *mapObjSprite = &gSprites[gMapObjects[mapObjId].spriteId];
        sprite->sData4 += sprite->sData3;
        sprite->pos1.x = mapObjSprite->pos1.x;
        sprite->pos1.y = mapObjSprite->pos1.y - 16;
        sprite->pos2.x = mapObjSprite->pos2.x;
        sprite->pos2.y = mapObjSprite->pos2.y + sprite->sData4;
        if (sprite->sData4)
            sprite->sData3++;
        else
            sprite->sData3 = 0;
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sData3
#undef sData4
#undef sFldEffId

u8 GetCurrentApproachingTrainerMapObjectId(void)
{
    if (gApproachingTrainerId == 0)
        return gApproachingTrainers[0].mapObjectId;
    else
        return gApproachingTrainers[1].mapObjectId;
}

u8 GetChosenApproachingTrainerMapObjectId(u8 arrayId)
{
    if (arrayId >= ARRAY_COUNT(gApproachingTrainers))
        return 0;
    else if (arrayId == 0)
        return gApproachingTrainers[0].mapObjectId;
    else
        return gApproachingTrainers[1].mapObjectId;
}

void sub_80B4808(void)
{
    struct MapObject *trainerObj;

    if (gUnknown_030060AC == 1)
    {
        trainerObj = &gMapObjects[gApproachingTrainers[gUnknown_03006080].mapObjectId];
        gUnknown_03006084[0] = GetFaceDirectionAnimId(GetOppositeDirection(trainerObj->mapobj_unk_18));
        gUnknown_03006084[1] = 0xFE;
        ScriptMovement_StartObjectMovementScript(0xFF, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gUnknown_03006084);
    }
    else
    {
        trainerObj = &gMapObjects[gPlayerAvatar.mapObjectId];
        gUnknown_03006084[0] = GetFaceDirectionAnimId(trainerObj->mapobj_unk_18);
        gUnknown_03006084[1] = 0xFE;
        ScriptMovement_StartObjectMovementScript(0xFF, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gUnknown_03006084);
    }

    sub_809BE48(0xFF);
}
