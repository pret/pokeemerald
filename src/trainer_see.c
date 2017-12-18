#include "global.h"
#include "trainer_see.h"
#include "battle_setup.h"
#include "pokemon.h"
#include "sprite.h"
#include "field_map_obj.h"
#include "pokenav.h"
#include "task.h"

extern u8 gApproachingTrainerId;
extern u8 gNoOfApproachingTrainers;
extern u8 gUnknown_030060AC;
extern u16 gUnknown_03006080;

extern bool8 InBattlePyramid(void);
extern bool32 InTrainerHill(void);
extern bool8 GetBattlePyramidTrainerFlag(u8 mapObjectId);
extern bool8 GetTrainerHillTrainerFlag(u8 mapObjectId);

// this file's functions
static u8 CheckTrainer(u8 mapObjectId);
u8 GetTrainerApproachDistance(struct MapObject *trainerObj);
void TrainerApproachPlayer(struct MapObject *trainerObj, u8 radius);

u8 GetTrainerApproachDistanceSouth(struct MapObject *trainerObj, s16 range, s16 x, s16 y);
u8 GetTrainerApproachDistanceNorth(struct MapObject *trainerObj, s16 range, s16 x, s16 y);
u8 GetTrainerApproachDistanceWest(struct MapObject *trainerObj, s16 range, s16 x, s16 y);
u8 GetTrainerApproachDistanceEast(struct MapObject *trainerObj, s16 range, s16 x, s16 y);

bool8 sub_80B4178(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B417C(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B41C0(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B4200(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B425C(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B4318(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B435C(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B4390(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B43AC(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B43E0(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B4438(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B44AC(u8 taskId, struct Task *task, struct MapObject *trainerObj);

bool8 sub_80B43AC(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B43E0(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B4438(u8 taskId, struct Task *task, struct MapObject *trainerObj);
bool8 sub_80B44AC(u8 taskId, struct Task *task, struct MapObject *trainerObj);

void objc_exclamation_mark_probably(struct Sprite *sprite);

// const rom data
const u8 gEmotion_ExclamationMarkGfx[] = INCBIN_U8("graphics/misc/emotion_exclamation.4bpp");
const u8 gEmotion_QuestionMarkGfx[] = INCBIN_U8("graphics/misc/emotion_question.4bpp");
const u8 gEmotion_HeartGfx[] = INCBIN_U8("graphics/misc/emotion_heart.4bpp");

u8 (*const sDirectionalApproachDistanceFuncs[])(struct MapObject *trainerObj, s16 range, s16 x, s16 y) =
{
    GetTrainerApproachDistanceSouth,
    GetTrainerApproachDistanceNorth,
    GetTrainerApproachDistanceWest,
    GetTrainerApproachDistanceEast,
};

bool8 (*const gTrainerSeeFuncList[])(u8 taskId, struct Task *task, struct MapObject *trainerObj) =
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

bool8 (*const gTrainerSeeFuncList2[])(u8 taskId, struct Task *task, struct MapObject *trainerObj) =
{
    sub_80B43AC,
    sub_80B43E0,
    sub_80B4438,
    sub_80B44AC,
};

const struct OamData gOamData_855077C =
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

const struct SpriteFrameImage gSpriteImageTable_8550784[] =
{
    {gEmotion_ExclamationMarkGfx, 0x80},
    {gEmotion_QuestionMarkGfx, 0x80}
};

const struct SpriteFrameImage gSpriteImageTable_8550794[] =
{
    {gEmotion_HeartGfx, 0x80}
};

const union AnimCmd gSpriteAnim_855079C[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_END
};

const union AnimCmd gSpriteAnim_85507A4[] =
{
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_END
};

const union AnimCmd *const gSpriteAnimTable_85507AC[] =
{
    gSpriteAnim_855079C,
    gSpriteAnim_85507A4
};

const struct SpriteTemplate gSpriteTemplate_85507B4 =
{
    .tileTag = 0xffff,
    .paletteTag = 0xffff,
    .oam = &gOamData_855077C,
    .anims = gSpriteAnimTable_85507AC,
    .images = gSpriteImageTable_8550784,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = objc_exclamation_mark_probably
};

const struct SpriteTemplate gSpriteTemplate_85507CC =
{
    .tileTag = 0xffff,
    .paletteTag = 0x1004,
    .oam = &gOamData_855077C,
    .anims = gSpriteAnimTable_85507AC,
    .images = gSpriteImageTable_8550794,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = objc_exclamation_mark_probably
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

/*
u8 GetTrainerApproachDistance(struct MapObject *trainerObj)
{
    s16 x, y;
    u8 i;
    u8 approachDistance;

    PlayerGetDestCoords(&x, &y);
    if (trainerObj->trainerType == 1)  // can only see in one direction
    {
        approachDistance = sDirectionalApproachDistanceFuncs[trainerObj->mapobj_unk_18 - 1](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
        return CheckPathBetweenTrainerAndPlayer((struct MapObject2 *)trainerObj, approachDistance, trainerObj->mapobj_unk_18);
    }
    else  // can see in all directions
    {
        for (i = 0; i < 4; i++)
        {
            approachDistance = sDirectionalApproachDistanceFuncs[i](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
            if (CheckPathBetweenTrainerAndPlayer((struct MapObject2 *)trainerObj, approachDistance, i + 1)) // directions are 1-4 instead of 0-3. south north west east
                return approachDistance;
        }
    }
    return 0;
}
*/
