#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "follower_npc.h"
#include "pokemon.h"
#include "script.h"
#include "script_movement.h"
#include "sprite.h"
#include "task.h"
#include "trainer_see.h"
#include "trainer_hill.h"
#include "util.h"
#include "battle_pyramid.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/script_commands.h"
#include "constants/trainer_types.h"

// this file's functions
static u8 CheckTrainer(u8 objectEventId);
static u8 GetTrainerApproachDistance(struct ObjectEvent *trainerObj);
static u8 CheckPathBetweenTrainerAndPlayer(struct ObjectEvent *trainerObj, u8 approachDistance, enum Direction direction);
static void InitTrainerApproachTask(struct ObjectEvent *trainerObj, u8 range);
static void Task_RunTrainerSeeFuncList(u8 taskId);
static void Task_EndTrainerApproach(u8 taskId);
static void SetIconSpriteData(struct Sprite *sprite, u16 fldEffId, u8 spriteAnimNum);

static u8 GetTrainerApproachDistanceSouth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceNorth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceWest(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);
static u8 GetTrainerApproachDistanceEast(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y);

static bool8 TrainerSeeIdle(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 TrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitTrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 TrainerTurnToFacePlayer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 TrainerMoveToPlayer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 PlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitPlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 RevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitRevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 RevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 PopOutOfAshBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 JumpInPlaceBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);
static bool8 WaitRevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj);

static void SpriteCB_TrainerIcons(struct Sprite *sprite);

// IWRAM common
COMMON_DATA u16 gWhichTrainerToFaceAfterBattle = 0;
COMMON_DATA u8 gPostBattleMovementScript[4] = {0};
COMMON_DATA struct ApproachingTrainer gApproachingTrainers[NUM_APPROACHING_TRAINER] = {0};
COMMON_DATA u8 gNoOfApproachingTrainers = 0;
COMMON_DATA bool8 gTrainerApproachedPlayer = 0;

// EWRAM
EWRAM_DATA u8 gApproachingTrainerId = 0;

// const rom data
static const u16 sGfx_Emoticons[] = INCGFX_U16("graphics/misc/emoticons.png", ".4bpp", "-mwidth 2 -mheight 2");
static const u8 sEmotion_ExclamationMarkGfx[] = INCGFX_U8("graphics/field_effects/pics/emotion_exclamation.png", ".4bpp");
static const u8 sEmotion_QuestionMarkGfx[] = INCGFX_U8("graphics/field_effects/pics/emotion_question.png", ".4bpp");
static const u8 sEmotion_HeartGfx[] = INCGFX_U8("graphics/field_effects/pics/emotion_heart.png", ".4bpp");
static const u8 sEmotion_DoubleExclamationMarkGfx[] = INCGFX_U8("graphics/field_effects/pics/emotion_double_exclamation.png", ".4bpp");
static const u8 sEmotion_XGfx[] = INCGFX_U8("graphics/field_effects/pics/emote_x.png", ".4bpp");
// HGSS emote graphics ripped by Lemon on The Spriters Resource: https://www.spriters-resource.com/ds_dsi/pokemonheartgoldsoulsilver/sheet/30497/
static const u8 sEmotion_Gfx[] = INCGFX_U8("graphics/misc/emotes.png", ".4bpp", "-mwidth 2 -mheight 2");

static u8 (*const sDirectionalApproachDistanceFuncs[])(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y) =
{
    GetTrainerApproachDistanceSouth,
    GetTrainerApproachDistanceNorth,
    GetTrainerApproachDistanceWest,
    GetTrainerApproachDistanceEast,
};

enum {
    TRSEE_NONE,
    TRSEE_EXCLAMATION,
    TRSEE_EXCLAMATION_WAIT,
    TRSEE_TURN_TO_FACE_PLAYER,
    TRSEE_MOVE_TO_PLAYER,
    TRSEE_PLAYER_FACE,
    TRSEE_PLAYER_FACE_WAIT,
    TRSEE_REVEAL_DISGUISE,
    TRSEE_REVEAL_DISGUISE_WAIT,
    TRSEE_REVEAL_BURIED,
    TRSEE_BURIED_POP_OUT,
    TRSEE_BURIED_JUMP,
    TRSEE_REVEAL_BURIED_WAIT,
};

static bool8 (*const sTrainerSeeFuncList[])(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj) =
{
    [TRSEE_NONE]                 = TrainerSeeIdle,
    [TRSEE_EXCLAMATION]          = TrainerExclamationMark,
    [TRSEE_EXCLAMATION_WAIT]     = WaitTrainerExclamationMark,
    [TRSEE_TURN_TO_FACE_PLAYER]  = TrainerTurnToFacePlayer,
    [TRSEE_MOVE_TO_PLAYER]       = TrainerMoveToPlayer,
    [TRSEE_PLAYER_FACE]          = PlayerFaceApproachingTrainer,
    [TRSEE_PLAYER_FACE_WAIT]     = WaitPlayerFaceApproachingTrainer,
    [TRSEE_REVEAL_DISGUISE]      = RevealDisguisedTrainer,
    [TRSEE_REVEAL_DISGUISE_WAIT] = WaitRevealDisguisedTrainer,
    [TRSEE_REVEAL_BURIED]        = RevealBuriedTrainer,
    [TRSEE_BURIED_POP_OUT]       = PopOutOfAshBuriedTrainer,
    [TRSEE_BURIED_JUMP]          = JumpInPlaceBuriedTrainer,
    [TRSEE_REVEAL_BURIED_WAIT]   = WaitRevealBuriedTrainer,
};

static bool8 (*const sTrainerSeeFuncList2[])(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj) =
{
    RevealBuriedTrainer,
    PopOutOfAshBuriedTrainer,
    JumpInPlaceBuriedTrainer
};

static const struct OamData sOamData_Icons =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sSpriteImages_Emoticons[] = {
    {sGfx_Emoticons + 0x000, 0x80},
    {sGfx_Emoticons + 0x040, 0x80},
    {sGfx_Emoticons + 0x080, 0x80},

    {sGfx_Emoticons + 0x180, 0x80},
    {sGfx_Emoticons + 0x1C0, 0x80},
    {sGfx_Emoticons + 0x200, 0x80},

    {sGfx_Emoticons + 0x0C0, 0x80},
    {sGfx_Emoticons + 0x100, 0x80},
    {sGfx_Emoticons + 0x140, 0x80},

    {sGfx_Emoticons + 0x240, 0x80},
    {sGfx_Emoticons + 0x280, 0x80},
    {sGfx_Emoticons + 0x2C0, 0x80},

    {sGfx_Emoticons + 0x300, 0x80},
    {sGfx_Emoticons + 0x340, 0x80},
    {sGfx_Emoticons + 0x380, 0x80},
};

static const union AnimCmd sAnimCmd_ExclamationMark1[] = {
    ANIMCMD_FRAME( 0,  4),
    ANIMCMD_FRAME( 1,  4),
    ANIMCMD_FRAME( 2, 52),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_DoubleExclMark[] = {
    ANIMCMD_FRAME( 6,  4),
    ANIMCMD_FRAME( 7,  4),
    ANIMCMD_FRAME( 8, 52),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_X[] = {
    ANIMCMD_FRAME( 3,  4),
    ANIMCMD_FRAME( 4,  4),
    ANIMCMD_FRAME( 5, 52),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_SmileyFace[] = {
    ANIMCMD_FRAME( 9,  4),
    ANIMCMD_FRAME(10,  4),
    ANIMCMD_FRAME(11, 52),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_QuestionMark[] = {
    ANIMCMD_FRAME(12,  4),
    ANIMCMD_FRAME(13,  4),
    ANIMCMD_FRAME(14, 52),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Emoticons[] = {
    sAnimCmd_ExclamationMark1,
    sAnimCmd_DoubleExclMark,
    sAnimCmd_X,
    sAnimCmd_SmileyFace,
    sAnimCmd_QuestionMark
};

static const struct SpriteTemplate sSpriteTemplate_Emoticons = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_PLAYER_RED,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Emoticons,
    .images = sSpriteImages_Emoticons,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteFrameImage sSpriteImageTable_ExclamationQuestionMark[] =
{
    {
        .data = sEmotion_ExclamationMarkGfx,
        .size = sizeof(sEmotion_ExclamationMarkGfx)
    },
    {
        .data = sEmotion_QuestionMarkGfx,
        .size = sizeof(sEmotion_QuestionMarkGfx)
    },
    {
        .data = sEmotion_DoubleExclamationMarkGfx,
        .size = sizeof(sEmotion_DoubleExclamationMarkGfx)
    },
    {
        .data = sEmotion_XGfx,
        .size = sizeof(sEmotion_XGfx)
    }
};

static const struct SpriteFrameImage sSpriteImageTable_HeartIcon[] =
{
    {
        .data = sEmotion_HeartGfx,
        .size = sizeof(sEmotion_HeartGfx)
    }
};

static const struct SpriteFrameImage sSpriteImageTable_Emotes[] =
{
    overworld_frame(sEmotion_Gfx, 2, 2, 0), // FOLLOWER_EMOTION_HAPPY
    overworld_frame(sEmotion_Gfx, 2, 2, 1), // FOLLOWER_EMOTION_HAPPY
    overworld_frame(sEmotion_Gfx, 2, 2, 2), // FOLLOWER_EMOTION_NEUTRAL
    overworld_frame(sEmotion_Gfx, 2, 2, 3), // FOLLOWER_EMOTION_NEUTRAL
    overworld_frame(sEmotion_Gfx, 2, 2, 4), // FOLLOWER_EMOTION_SAD
    overworld_frame(sEmotion_Gfx, 2, 2, 5), // FOLLOWER_EMOTION_SAD
    overworld_frame(sEmotion_Gfx, 2, 2, 6), // FOLLOWER_EMOTION_UPSET
    overworld_frame(sEmotion_Gfx, 2, 2, 7), // FOLLOWER_EMOTION_UPSET
    overworld_frame(sEmotion_Gfx, 2, 2, 8), // FOLLOWER_EMOTION_ANGRY
    overworld_frame(sEmotion_Gfx, 2, 2, 9), // FOLLOWER_EMOTION_ANGRY
    overworld_frame(sEmotion_Gfx, 2, 2, 10), // FOLLOWER_EMOTION_PENSIVE
    overworld_frame(sEmotion_Gfx, 2, 2, 11), // FOLLOWER_EMOTION_PENSIVE
    overworld_frame(sEmotion_Gfx, 2, 2, 12), // FOLLOWER_EMOTION_LOVE
    overworld_frame(sEmotion_Gfx, 2, 2, 13), // FOLLOWER_EMOTION_LOVE
    overworld_frame(sEmotion_Gfx, 2, 2, 14), // FOLLOWER_EMOTION_SURPRISE
    overworld_frame(sEmotion_Gfx, 2, 2, 15), // FOLLOWER_EMOTION_SURPRISE
    overworld_frame(sEmotion_Gfx, 2, 2, 16), // FOLLOWER_EMOTION_CURIOUS
    overworld_frame(sEmotion_Gfx, 2, 2, 17), // FOLLOWER_EMOTION_CURIOUS
    overworld_frame(sEmotion_Gfx, 2, 2, 18), // FOLLOWER_EMOTION_MUSIC
    overworld_frame(sEmotion_Gfx, 2, 2, 19), // FOLLOWER_EMOTION_MUSIC
    overworld_frame(sEmotion_Gfx, 2, 2, 20), // FOLLOWER_EMOTION_POISONED
    overworld_frame(sEmotion_Gfx, 2, 2, 21), // FOLLOWER_EMOTION_POISONED
};

static const union AnimCmd sSpriteAnim_Emotes0[] =
{
    ANIMCMD_FRAME(0*2, 30),
    ANIMCMD_FRAME(0*2+1, 25),
    ANIMCMD_FRAME(0*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes1[] =
{
    ANIMCMD_FRAME(1*2, 30),
    ANIMCMD_FRAME(1*2+1, 25),
    ANIMCMD_FRAME(1*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes2[] =
{
    ANIMCMD_FRAME(2*2, 30),
    ANIMCMD_FRAME(2*2+1, 25),
    ANIMCMD_FRAME(2*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes3[] =
{
    ANIMCMD_FRAME(3*2, 30),
    ANIMCMD_FRAME(3*2+1, 25),
    ANIMCMD_FRAME(3*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes4[] =
{
    ANIMCMD_FRAME(4*2, 30),
    ANIMCMD_FRAME(4*2+1, 25),
    ANIMCMD_FRAME(4*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes5[] =
{
    ANIMCMD_FRAME(5*2, 30),
    ANIMCMD_FRAME(5*2+1, 25),
    ANIMCMD_FRAME(5*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes6[] =
{
    ANIMCMD_FRAME(6*2, 30),
    ANIMCMD_FRAME(6*2+1, 25),
    ANIMCMD_FRAME(6*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes7[] =
{
    ANIMCMD_FRAME(7*2, 30),
    ANIMCMD_FRAME(7*2+1, 25),
    ANIMCMD_FRAME(7*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes8[] =
{
    ANIMCMD_FRAME(8*2, 30),
    ANIMCMD_FRAME(8*2+1, 25),
    ANIMCMD_FRAME(8*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes9[] =
{
    ANIMCMD_FRAME(9*2, 30),
    ANIMCMD_FRAME(9*2+1, 25),
    ANIMCMD_FRAME(9*2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Emotes10[] =
{
    ANIMCMD_FRAME(10*2, 30),
    ANIMCMD_FRAME(10*2+1, 25),
    ANIMCMD_FRAME(10*2, 30),
    ANIMCMD_END
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


static const union AnimCmd sSpriteAnim_Icons3[] =
{
    ANIMCMD_FRAME(2, 60),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Icons4[] =
{
    ANIMCMD_FRAME(3, 60),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Icons[] =
{
    sSpriteAnim_Icons1,
    sSpriteAnim_Icons2,
    sSpriteAnim_Icons3,
    sSpriteAnim_Icons4
};

static const union AnimCmd *const sSpriteAnimTable_Emotes[] =
{
    sSpriteAnim_Emotes0,
    sSpriteAnim_Emotes1,
    sSpriteAnim_Emotes2,
    sSpriteAnim_Emotes3,
    sSpriteAnim_Emotes4,
    sSpriteAnim_Emotes5,
    sSpriteAnim_Emotes6,
    sSpriteAnim_Emotes7,
    sSpriteAnim_Emotes8,
    sSpriteAnim_Emotes9,
    sSpriteAnim_Emotes10,
};

static const struct SpriteTemplate sSpriteTemplate_ExclamationQuestionMark =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_ExclamationQuestionMark,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteTemplate sSpriteTemplate_HeartIcon =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_NPC_1,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Icons,
    .images = sSpriteImageTable_HeartIcon,
    .callback = SpriteCB_TrainerIcons
};

static const struct SpriteTemplate sSpriteTemplate_Emote =
{
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_EMOTES,
    .oam = &sOamData_Icons,
    .anims = sSpriteAnimTable_Emotes,
    .images = sSpriteImageTable_Emotes,
    .callback = SpriteCB_TrainerIcons
};

// code
bool8 CheckForTrainersWantingBattle(void)
{
    u8 i;
    u8 trainerObjects[OBJECT_EVENTS_COUNT] = {0};
    u8 trainerObjectsCount = 0;

    if (FlagGet(OW_FLAG_NO_TRAINER_SEE))
        return FALSE;

    gNoOfApproachingTrainers = 0;
    gApproachingTrainerId = 0;

    // Adds trainers wanting to battle to array
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            continue;
        if (gObjectEvents[i].trainerType != TRAINER_TYPE_NORMAL && gObjectEvents[i].trainerType != TRAINER_TYPE_SEE_ALL_DIRECTIONS && gObjectEvents[i].trainerType != TRAINER_TYPE_BURIED)
            continue;
        trainerObjects[trainerObjectsCount++] = i;
    }

    // Sorts array by localId
    for (i = 1; i <= trainerObjectsCount; i++)
    {
        u8 x = trainerObjects[i];
        u8 j = i;
        while (j > 0 && gObjectEvents[trainerObjects[j-1]].localId > gObjectEvents[x].localId)
        {
            trainerObjects[j] = trainerObjects[j-1];
            j--;
        }
        trainerObjects[j] = x;
    }

    for (i = 0; i <= trainerObjectsCount; i++)
    {
        u8 numTrainers;
        numTrainers = CheckTrainer(trainerObjects[i]);
        if (numTrainers == 0xFF) // non-trainerbattle script
        {
            u32 objectEventId = gApproachingTrainers[gNoOfApproachingTrainers - 1].objectEventId;
            gApproachingTrainers[gNoOfApproachingTrainers - 1].trainerScriptPtr = GetObjectEventScriptPointerByObjectEventId(objectEventId);
            gSelectedObjectEvent = objectEventId;
            gSpecialVar_LastTalked = gObjectEvents[objectEventId].localId;
            ScriptContext_SetupScript(EventScript_ObjectApproachPlayer);
            LockPlayerFieldControls();
            return TRUE;
        }

        if (numTrainers == 2)
            break;

        if (numTrainers == 0)
            continue;

        if (gNoOfApproachingTrainers > 1)
            break;
        if (GetMonsStateToDoubles_2() != PLAYER_HAS_TWO_USABLE_MONS) // one trainer found and can't have a double battle
            break;
    }

    if (gNoOfApproachingTrainers > 0)
    {
        if (InBattlePyramid() || InTrainerHillChallenge())
            ConfigureApproachingFacilityTrainerBattle(gApproachingTrainers);
        else
            ConfigureApproachingTrainerBattle(gApproachingTrainers);
            
        gTrainerApproachedPlayer = TRUE;
        gApproachingTrainerId = 0;
        return TRUE;
    }
    else
    {
        gTrainerApproachedPlayer = FALSE;
        return FALSE;
    }
}

static u8 CheckTrainer(u8 objectEventId)
{
    const u8 *trainerBattlePtr;
    u8 numTrainers = 1;

    u8 approachDistance = GetTrainerApproachDistance(&gObjectEvents[objectEventId]);
    if (approachDistance == 0)
        return 0;

    if (InTrainerHill())
    {
        trainerBattlePtr = GetTrainerHillTrainerScript();
    }
    else if (InBattlePyramid()) {
        trainerBattlePtr = GetBattlePyramidTrainerScript();
    }
    else
    {
        trainerBattlePtr = GetObjectEventScriptPointerByObjectEventId(objectEventId);
        struct ScriptContext ctx;
        if (RunScriptImmediatelyUntilEffect(SCREFF_V1 | SCREFF_SAVE | SCREFF_HARDWARE | SCREFF_TRAINERBATTLE, trainerBattlePtr, &ctx))
        {
            if (*ctx.scriptPtr == SCR_OP_TRAINERBATTLE)
                trainerBattlePtr = ctx.scriptPtr;
            else
                trainerBattlePtr = NULL;
        }
        else
        {
            return 0; // no effect
        }
    }

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        if (GetBattlePyramidTrainerFlag(objectEventId))
            return 0;
    }
    else if (InTrainerHill())
    {
        if (GetHillTrainerFlag(objectEventId))
            return 0;
    }
    else if (trainerBattlePtr)
    {
        if (GetTrainerFlagFromScriptPointer(trainerBattlePtr))
        {
            //If there is a rematch, we want to trigger the approach sequence
            if (I_VS_SEEKER_CHARGING && GetRematchFromScriptPointer(trainerBattlePtr))
            {
                trainerBattlePtr = NULL;
                numTrainers = 0xFF;
            }
            else
            {
                 return 0;
            }
        }
    }
    else
    {
        numTrainers = 0xFF;
    }

    if (trainerBattlePtr && !InTrainerHillChallenge() && !InBattlePyramid()) 
    {
        TrainerBattleParameter *temp = (TrainerBattleParameter *)(trainerBattlePtr + 1);
        if (temp->params.isDoubleBattle)
        {
            if (GetMonsStateToDoubles_2() != PLAYER_HAS_TWO_USABLE_MONS)
                return 0;

            numTrainers = 2;
        }
    }

    gApproachingTrainers[gNoOfApproachingTrainers].objectEventId = objectEventId;
    gApproachingTrainers[gNoOfApproachingTrainers].trainerScriptPtr = trainerBattlePtr;
    gApproachingTrainers[gNoOfApproachingTrainers].radius = approachDistance;
    InitTrainerApproachTask(&gObjectEvents[objectEventId], approachDistance - 1);
    gNoOfApproachingTrainers++;

    return numTrainers;
}

static u8 GetTrainerApproachDistance(struct ObjectEvent *trainerObj)
{
    s16 x, y;
    u8 i;
    u8 approachDistance;

    PlayerGetDestCoords(&x, &y);
    if (trainerObj->trainerType == TRAINER_TYPE_NORMAL)  // can only see in one direction
    {
        // Disable trainer approach while moving diagonally (usually moving on sideway stairs)
        if (trainerObj->facingDirection > DIR_EAST)
            return 0;
        approachDistance = sDirectionalApproachDistanceFuncs[trainerObj->facingDirection - 1](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
        return CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, trainerObj->facingDirection);
    }
    else // TRAINER_TYPE_SEE_ALL_DIRECTIONS, TRAINER_TYPE_BURIED
    {
        for (i = 0; i < ARRAY_COUNT(sDirectionalApproachDistanceFuncs); i++)
        {
            approachDistance = sDirectionalApproachDistanceFuncs[i](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
            if (CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, i + 1)) // directions are 1-4 instead of 0-3. south north west east
                return approachDistance;
        }
    }

    return 0;
}

// Returns how far south the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceSouth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.x == x
     && y > trainerObj->currentCoords.y
     && y <= trainerObj->currentCoords.y + range)
        return (y - trainerObj->currentCoords.y);
    else
        return 0;
}

// Returns how far north the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceNorth(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.x == x
     && y < trainerObj->currentCoords.y
     && y >= trainerObj->currentCoords.y - range)
        return (trainerObj->currentCoords.y - y);
    else
        return 0;
}

// Returns how far west the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceWest(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.y == y
     && x < trainerObj->currentCoords.x
     && x >= trainerObj->currentCoords.x - range)
        return (trainerObj->currentCoords.x - x);
    else
        return 0;
}

// Returns how far east the player is from trainer. 0 if out of trainer's sight.
static u8 GetTrainerApproachDistanceEast(struct ObjectEvent *trainerObj, s16 range, s16 x, s16 y)
{
    if (trainerObj->currentCoords.y == y
     && x > trainerObj->currentCoords.x
     && x <= trainerObj->currentCoords.x + range)
        return (x - trainerObj->currentCoords.x);
    else
        return 0;
}

static u8 CheckPathBetweenTrainerAndPlayer(struct ObjectEvent *trainerObj, u8 approachDistance, enum Direction direction)
{
    s16 x, y;
    u8 rangeX, rangeY;
    u8 i;
    enum Collision collision;

    if (approachDistance == 0)
        return 0;

    x = trainerObj->currentCoords.x;
    y = trainerObj->currentCoords.y;

    MoveCoords(direction, &x, &y);
    for (i = 0; i < approachDistance - 1; i++, MoveCoords(direction, &x, &y))
    {
        // Check for collisions on approach, ignoring the "out of range" collision for regular movement
        collision = GetCollisionFlagsAtCoords(trainerObj, x, y, direction);
        if (collision != 0 && (collision & ~(1 << (COLLISION_OUTSIDE_RANGE - 1))))
            return 0;
    }

    rangeX = trainerObj->range.rangeX;
    rangeY = trainerObj->range.rangeY;
    trainerObj->range.rangeX = 0;
    trainerObj->range.rangeY = 0;

    collision = GetCollisionAtCoords(trainerObj, x, y, direction);

    trainerObj->range.rangeX = rangeX;
    trainerObj->range.rangeY = rangeY;
    if (collision == COLLISION_OBJECT_EVENT)
        return approachDistance;

    return 0;
}

#define tFuncId             data[0]
#define tTrainerRange       data[3]
#define tOutOfAshSpriteId   data[4]
#define tTrainerObjectEventId data[7]

static void InitTrainerApproachTask(struct ObjectEvent *trainerObj, u8 range)
{
    struct Task *task;

    gApproachingTrainers[gNoOfApproachingTrainers].taskId = CreateTask(Task_RunTrainerSeeFuncList, 0x50);
    task = &gTasks[gApproachingTrainers[gNoOfApproachingTrainers].taskId];
    task->tTrainerRange = range;
    task->tTrainerObjectEventId = gApproachingTrainers[gNoOfApproachingTrainers].objectEventId;
}

static void StartTrainerApproach(TaskFunc followupFunc)
{
    u8 taskId;
    TaskFunc taskFunc;

    if (gApproachingTrainerId == 0)
        taskId = gApproachingTrainers[0].taskId;
    else
        taskId = gApproachingTrainers[1].taskId;

    if (PlayerHasFollowerNPC() && (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT))
        ObjectEventForceSetHeldMovement(&gObjectEvents[GetFollowerNPCObjectId()], GetFaceDirectionAnimNum(gObjectEvents[GetFollowerNPCObjectId()].facingDirection));

    taskFunc = Task_RunTrainerSeeFuncList;
    SetTaskFuncWithFollowupFunc(taskId, taskFunc, followupFunc);
    gTasks[taskId].tFuncId = TRSEE_EXCLAMATION;
    taskFunc(taskId);
}

static void Task_RunTrainerSeeFuncList(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *trainerObj = &gObjectEvents[task->tTrainerObjectEventId];

    if (!trainerObj->active)
    {
        SwitchTaskToFollowupFunc(taskId);
    }
    else
    {
        while (sTrainerSeeFuncList[task->tFuncId](taskId, task, trainerObj));
    }
}

static bool8 TrainerSeeIdle(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    return FALSE;
}

// TRSEE_EXCLAMATION
static bool8 TrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    enum Direction direction;

    ObjectEventGetLocalIdAndMap(trainerObj, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON);
    direction = GetFaceDirectionMovementAction(trainerObj->facingDirection);
    ObjectEventSetHeldMovement(trainerObj, direction);
    task->tFuncId++; // TRSEE_EXCLAMATION_WAIT
    return TRUE;
}

// TRSEE_EXCLAMATION_WAIT
static bool8 WaitTrainerExclamationMark(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (FieldEffectActiveListContains(FLDEFF_EXCLAMATION_MARK_ICON))
    {
        return FALSE;
    }
    else
    {
        task->tFuncId++; // TRSEE_TURN_TO_FACE_PLAYER
        if (trainerObj->movementType == MOVEMENT_TYPE_TREE_DISGUISE || trainerObj->movementType == MOVEMENT_TYPE_MOUNTAIN_DISGUISE)
            task->tFuncId = TRSEE_REVEAL_DISGUISE;
        if (trainerObj->movementType == MOVEMENT_TYPE_BURIED)
            task->tFuncId = TRSEE_REVEAL_BURIED;
        return TRUE;
    }
}

// TRSEE_TURN_TO_FACE_PLAYER
static bool8 TrainerTurnToFacePlayer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj) || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        ObjectEventSetHeldMovement(trainerObj, MOVEMENT_ACTION_FACE_PLAYER);

        if (!task->tTrainerRange)
            task->tFuncId = TRSEE_PLAYER_FACE;
        else
            task->tFuncId++; // TRSEE_MOVE_TO_PLAYER
    }
    return FALSE;
}

// TRSEE_MOVE_TO_PLAYER
static bool8 TrainerMoveToPlayer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj) || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        if (task->tTrainerRange--)
        {
            ObjectEventSetHeldMovement(trainerObj, GetWalkNormalMovementAction(trainerObj->facingDirection));
        }
        else
        {
            // Set trainer's movement type so they stop and remain facing that direction
            SetTrainerMovementType(trainerObj, GetTrainerFacingDirectionMovementType(trainerObj->facingDirection));
            TryOverrideTemplateCoordsForObjectEvent(trainerObj, GetTrainerFacingDirectionMovementType(trainerObj->facingDirection));
            OverrideTemplateCoordsForObjectEvent(trainerObj);
            task->tFuncId++;
        }
    }
    return FALSE;
}

// TRSEE_PLAYER_FACE
static bool8 PlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    struct ObjectEvent *playerObj;

    playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (ObjectEventIsMovementOverridden(playerObj) && !ObjectEventClearHeldMovementIfFinished(playerObj))
        return FALSE;

    CancelPlayerForcedMovement();
    ObjectEventSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], GetFaceDirectionMovementAction(GetOppositeDirection(trainerObj->facingDirection)));
    task->tFuncId++; // TRSEE_PLAYER_FACE_WAIT
    return FALSE;
}

// TRSEE_PLAYER_FACE_WAIT
static bool8 WaitPlayerFaceApproachingTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObj)
     || ObjectEventClearHeldMovementIfFinished(playerObj))
        SwitchTaskToFollowupFunc(taskId);
    return FALSE;
}

// TRSEE_REVEAL_DISGUISE
static bool8 RevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj)
     || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        ObjectEventSetHeldMovement(trainerObj, MOVEMENT_ACTION_REVEAL_TRAINER);
        task->tFuncId++; // TRSEE_REVEAL_DISGUISE_WAIT
    }
    return FALSE;
}

// TRSEE_REVEAL_DISGUISE_WAIT
static bool8 WaitRevealDisguisedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (ObjectEventClearHeldMovementIfFinished(trainerObj))
        task->tFuncId = TRSEE_MOVE_TO_PLAYER;

    return FALSE;
}

// TRSEE_REVEAL_BURIED
static bool8 RevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!ObjectEventIsMovementOverridden(trainerObj)
     || ObjectEventClearHeldMovementIfFinished(trainerObj))
    {
        ObjectEventSetHeldMovement(trainerObj, MOVEMENT_ACTION_FACE_PLAYER);
        task->tFuncId++;
    }
    return FALSE;
}

// TRSEE_BURIED_POP_OUT
static bool8 PopOutOfAshBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (ObjectEventCheckHeldMovementStatus(trainerObj))
    {
        gFieldEffectArguments[0] = trainerObj->currentCoords.x;
        gFieldEffectArguments[1] = trainerObj->currentCoords.y;
        gFieldEffectArguments[2] = gSprites[trainerObj->spriteId].subpriority - 1;
        gFieldEffectArguments[3] = 2;
        task->tOutOfAshSpriteId = FieldEffectStart(FLDEFF_ASH_PUFF);
        task->tFuncId++;
    }
    return FALSE;
}

// TRSEE_BURIED_JUMP
static bool8 JumpInPlaceBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    struct Sprite *sprite;

    if (gSprites[task->tOutOfAshSpriteId].animCmdIndex == 2)
    {
        trainerObj->fixedPriority = 0;
        trainerObj->triggerGroundEffectsOnMove = TRUE;

        sprite = &gSprites[trainerObj->spriteId];
        sprite->oam.priority = 2;
        ObjectEventClearHeldMovementIfFinished(trainerObj);
        ObjectEventSetHeldMovement(trainerObj, GetJumpInPlaceMovementAction(trainerObj->facingDirection));
        task->tFuncId++;
    }

    return FALSE;
}

// TRSEE_REVEAL_BURIED_WAIT
static bool8 WaitRevealBuriedTrainer(u8 taskId, struct Task *task, struct ObjectEvent *trainerObj)
{
    if (!FieldEffectActiveListContains(FLDEFF_ASH_PUFF))
        task->tFuncId = TRSEE_MOVE_TO_PLAYER;

    return FALSE;
}

#undef tTrainerRange
#undef tOutOfAshSpriteId
#undef tTrainerObjectEventId

#define tObjEvent data[1]

static void Task_SetBuriedTrainerMovement(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *objEvent;

    LoadWordFromTwoHalfwords((u16*) &task->tObjEvent, (u32 *)&objEvent);
    if (!task->data[7])
    {
        ObjectEventClearHeldMovement(objEvent);
        task->data[7]++;
    }
    if (task->tFuncId < ARRAY_COUNT(sTrainerSeeFuncList2))
    {
        sTrainerSeeFuncList2[task->tFuncId](taskId, task, objEvent);
    }
    else if (!FieldEffectActiveListContains(FLDEFF_ASH_PUFF))
    {
        SetTrainerMovementType(objEvent, GetTrainerFacingDirectionMovementType(objEvent->facingDirection));
        TryOverrideTemplateCoordsForObjectEvent(objEvent, GetTrainerFacingDirectionMovementType(objEvent->facingDirection));
        DestroyTask(taskId);
        return;
    }
    objEvent->heldMovementFinished = 0;
}

// Called when a buried Trainer has the reveal_trainer movement applied, from direct interaction
void SetBuriedTrainerMovement(struct ObjectEvent *objEvent)
{
    StoreWordInTwoHalfwords((u16*) &gTasks[CreateTask(Task_SetBuriedTrainerMovement, 0)].tObjEvent, (u32)objEvent);
}

void DoTrainerApproach(void)
{
    StartTrainerApproach(Task_EndTrainerApproach);
}

static void Task_EndTrainerApproach(u8 taskId)
{
    DestroyTask(taskId);
    ScriptContext_Enable();
}

void PrepareSecondApproachingTrainer(void)
{
    if (gApproachingTrainerId == 0)
    {
        gApproachingTrainerId++;
        gSpecialVar_Result = TRUE;
        UnfreezeObjectEvents();
        FreezeObjectEventsExceptOne(gApproachingTrainers[1].objectEventId);
    }
    else
    {
        gApproachingTrainerId = 0;
        gSpecialVar_Result = FALSE;
    }
}

void TryPrepareSecondApproachingTrainer(void)
{
    if (gNoOfApproachingTrainers == 2)
    {
        PrepareSecondApproachingTrainer();
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

#define sLocalId    data[0]
#define sMapNum     data[1]
#define sMapGroup   data[2]
#define sYVelocity  data[3]
#define sYOffset    data[4]
#define sFldEffId   data[7]

u8 FldEff_ExclamationMarkIcon(void)
{
    u8 spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_ExclamationQuestionMark, 0, 0, 0x53);

    if (spriteId != MAX_SPRITES)
    {
        SetIconSpriteData(&gSprites[spriteId], FLDEFF_EXCLAMATION_MARK_ICON, 0);
        UpdateSpritePaletteByTemplate(&sSpriteTemplate_ExclamationQuestionMark, &gSprites[spriteId]);
    }

    return 0;
}

u8 FldEff_QuestionMarkIcon(void)
{
    u8 spriteId;
    if (gFieldEffectArguments[7] >= 0)
    {
        // Use follower emotes
        u8 emotion = gFieldEffectArguments[7];
        spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_Emote, 0, 0, 0x52);
        if (spriteId == MAX_SPRITES)
            return 0;
        SetIconSpriteData(&gSprites[spriteId], FLDEFF_EMOTE, emotion); // Set animation based on emotion
        UpdateSpritePaletteByTemplate(&sSpriteTemplate_Emote, &gSprites[spriteId]);
        return 0;
    }
    spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_ExclamationQuestionMark, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
    {
        SetIconSpriteData(&gSprites[spriteId], FLDEFF_QUESTION_MARK_ICON, 1);
        UpdateSpritePaletteByTemplate(&sSpriteTemplate_ExclamationQuestionMark, &gSprites[spriteId]);
    }

    return 0;
}

u8 FldEff_HeartIcon(void)
{
    u8 spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_HeartIcon, 0, 0, 0x52);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_HEART_ICON, 0);
        UpdateSpritePaletteByTemplate(&sSpriteTemplate_HeartIcon, sprite);
    }

    return 0;
}

u8 FldEff_DoubleExclMarkIcon(void)
{
    u8 spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_ExclamationQuestionMark, 0, 0, 0x53);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_DOUBLE_EXCL_MARK_ICON, 2);
        UpdateSpritePaletteByTemplate(&sSpriteTemplate_ExclamationQuestionMark, sprite);
    }

    return 0;
}

u8 FldEff_XIcon(void)
{
    u8 spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_ExclamationQuestionMark, 0, 0, 0x53);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];

        SetIconSpriteData(sprite, FLDEFF_X_ICON, 3);
        UpdateSpritePaletteByTemplate(&sSpriteTemplate_ExclamationQuestionMark, sprite);
    }

    return 0;
}

u8 FldEff_SmileyFaceIcon(void)
{
    u8 spriteId = CreateSpriteAtEndUnchecked(&sSpriteTemplate_Emoticons, 0, 0, 0x53);

    if (spriteId != MAX_SPRITES)
        SetIconSpriteData(&gSprites[spriteId], FLDEFF_SMILEY_FACE_ICON, 3);

    return 0;
}

static void SetIconSpriteData(struct Sprite *sprite, u16 fldEffId, u8 spriteAnimNum)
{
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = 1;

    sprite->sLocalId = gFieldEffectArguments[0];
    sprite->sMapNum = gFieldEffectArguments[1];
    sprite->sMapGroup = gFieldEffectArguments[2];
    sprite->sYVelocity = -5;
    sprite->sFldEffId = fldEffId;

    StartSpriteAnim(sprite, spriteAnimNum);
}

static void SpriteCB_TrainerIcons(struct Sprite *sprite)
{
    u8 objEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objEventId)
     || sprite->animEnded)
    {
        FieldEffectStop(sprite, sprite->sFldEffId);
    }
    else
    {
        struct Sprite *objEventSprite = &gSprites[gObjectEvents[objEventId].spriteId];
        sprite->sYOffset += sprite->sYVelocity;
        sprite->x = objEventSprite->x;
        sprite->y = objEventSprite->y - 16;
        sprite->x2 = objEventSprite->x2;
        sprite->y2 = objEventSprite->y2 + sprite->sYOffset;
        if (sprite->sYOffset)
            sprite->sYVelocity++;
        else
            sprite->sYVelocity = 0;
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sYVelocity
#undef sYOffset
#undef sFldEffId

u8 GetCurrentApproachingTrainerObjectEventId(void)
{
    if (gApproachingTrainerId == 0)
        return gApproachingTrainers[0].objectEventId;
    else
        return gApproachingTrainers[1].objectEventId;
}

u8 GetChosenApproachingTrainerObjectEventId(u8 arrayId)
{
    if (arrayId >= ARRAY_COUNT(gApproachingTrainers))
        return 0;
    else if (arrayId == 0)
        return gApproachingTrainers[0].objectEventId;
    else
        return gApproachingTrainers[1].objectEventId;
}

void PlayerFaceTrainerAfterBattle(void)
{
    struct ObjectEvent *objEvent;

    if (gTrainerApproachedPlayer == TRUE)
    {
        objEvent = &gObjectEvents[gApproachingTrainers[gWhichTrainerToFaceAfterBattle].objectEventId];
        gPostBattleMovementScript[0] = GetFaceDirectionMovementAction(GetOppositeDirection(objEvent->facingDirection));
        gPostBattleMovementScript[1] = MOVEMENT_ACTION_STEP_END;
        ScriptMovement_StartObjectMovementScript(LOCALID_PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gPostBattleMovementScript);
    }
    else
    {
        objEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
        gPostBattleMovementScript[0] = GetFaceDirectionMovementAction(objEvent->facingDirection);
        gPostBattleMovementScript[1] = MOVEMENT_ACTION_STEP_END;
        ScriptMovement_StartObjectMovementScript(LOCALID_PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gPostBattleMovementScript);
    }

    SetMovingNpcId(LOCALID_PLAYER);
}
