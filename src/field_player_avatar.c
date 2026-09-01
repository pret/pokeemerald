#include "global.h"
#include "main.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_screen_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "follower_npc.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "oras_dowse.h"
#include "overworld.h"
#include "party_menu.h"
#include "random.h"
#include "rotating_gate.h"
#include "rtc.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "tv.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/metatile_behaviors.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/trainer_types.h"

#define NUM_FORCED_MOVEMENTS 22
#define NUM_ACRO_BIKE_COLLISIONS 5

enum SpinDirection
{
    SPIN_DIRECTION_NONE,
    SPIN_DIRECTION_CLOCKWISE,
    SPIN_DIRECTION_COUNTER_CLOCKWISE,
};

struct SpinData
{
    u32 triggerEvo:1;
    u32 spinDirection:2;
    u32 spinTimeout:6;
    u32 spinHistory0:3;
    u32 spinHistory1:3;
    u32 spinHistory2:3;
    u32 spinHistory3:3;
    u32 VBlanksSpinning:11; //34,1 seconds
};

static EWRAM_DATA u8 sSpinStartFacingDir = 0;
EWRAM_DATA struct ObjectEvent gObjectEvents[OBJECT_EVENTS_COUNT] = {};
EWRAM_DATA struct PlayerAvatar gPlayerAvatar = {};
EWRAM_DATA struct SpinData gPlayerSpinData = {};

// static declarations
static u8 ObjectEventCB2_NoMovement2(void);
static bool8 TryUpdatePlayerSpinDirection(void);
static bool8 TryInterruptObjectEventSpecialAnim(struct ObjectEvent *, enum Direction);
static void npc_clear_strange_bits(struct ObjectEvent *);
static void MovePlayerAvatarUsingKeypadInput(enum Direction, u16, u16);
static void PlayerAllowForcedMovementIfMovingSameDirection(void);
static u8 GetForcedMovementByMetatileBehavior(void);
static void PlayerSetCopyableMovement(enum CopyMovement movement);

static bool8 ForcedMovement_None(void);
static bool8 ForcedMovement_Slip(void);
static bool8 ForcedMovement_WalkSouth(void);
static bool8 ForcedMovement_WalkNorth(void);
static bool8 ForcedMovement_WalkWest(void);
static bool8 ForcedMovement_WalkEast(void);
static bool8 ForcedMovement_PushedSouthByCurrent(void);
static bool8 ForcedMovement_PushedNorthByCurrent(void);
static bool8 ForcedMovement_PushedWestByCurrent(void);
static bool8 ForcedMovement_PushedEastByCurrent(void);
static bool8 ForcedMovement_SlideSouth(void);
static bool8 ForcedMovement_SlideNorth(void);
static bool8 ForcedMovement_SlideWest(void);
static bool8 ForcedMovement_SlideEast(void);
static bool8 ForcedMovement_MatJump(void);
static bool8 ForcedMovement_MatSpin(void);
static bool8 ForcedMovement_MuddySlope(void);
static bool8 ForcedMovement_SpinRight(void);
static bool8 ForcedMovement_SpinLeft(void);
static bool8 ForcedMovement_SpinUp(void);
static bool8 ForcedMovement_SpinDown(void);
static void PlaySpinSound(void);

static void MovePlayerNotOnBike(enum Direction, u16);
static u8 CheckMovementInputNotOnBike(enum Direction);
static void PlayerNotOnBikeNotMoving(enum Direction, u16);
static void PlayerNotOnBikeTurningInPlace(enum Direction, u16);
static void PlayerNotOnBikeMoving(enum Direction, u16);
static enum Collision CheckForPlayerAvatarCollision(enum Direction);
static enum Collision CheckForPlayerAvatarStaticCollision(enum Direction);
static enum Collision CheckForObjectEventStaticCollision(struct ObjectEvent *, s16, s16, enum Direction, u8);
static bool8 CanStopSurfing(s16, s16, enum Direction);
static bool8 ShouldJumpLedge(s16, s16, enum Direction);
static bool8 TryPushBoulder(s16, s16, enum Direction);
static void CheckAcroBikeCollision(s16, s16, u8, enum Collision *);

static void DoPlayerAvatarTransition(void);
static void PlayerAvatarTransition_Dummy(struct ObjectEvent *);
static void PlayerAvatarTransition_Normal(struct ObjectEvent *);
static void PlayerAvatarTransition_MachBike(struct ObjectEvent *);
static void PlayerAvatarTransition_AcroBike(struct ObjectEvent *);
static void PlayerAvatarTransition_Surfing(struct ObjectEvent *);
static void PlayerAvatarTransition_Underwater(struct ObjectEvent *);
static void PlayerAvatarTransition_ReturnToField(struct ObjectEvent *);

static bool8 PlayerAnimIsMultiFrameStationary(void);
static bool8 PlayerAnimIsMultiFrameStationaryAndStateNotTurning(void);
static bool8 PlayerIsAnimActive(void);
static bool8 PlayerCheckIfAnimFinishedOrInactive(void);

static void PlayerWalkSlowStairs(enum Direction direction);
static void UNUSED PlayerWalkSlow(enum Direction direction);
static void PlayerRunSlow(enum Direction direction);
static void PlayerRun(enum Direction);
static void PlayerNotOnBikeCollide(enum Direction);
static void PlayerNotOnBikeCollideWithFarawayIslandMew(enum Direction);

static void PlayCollisionSoundIfNotFacingWarp(enum Direction);
static void PlayerGoSpin(enum Direction direction);
static void PlayerApplyTileForcedMovement(u8 metatileBehavior);

static void HideShowWarpArrow(struct ObjectEvent *);

static void StartStrengthAnim(u8, enum Direction);
static void Task_PushBoulder(u8);
static bool8 PushBoulder_Start(struct Task *, struct ObjectEvent *, struct ObjectEvent *);
static bool8 PushBoulder_Move(struct Task *, struct ObjectEvent *, struct ObjectEvent *);
static bool8 PushBoulder_End(struct Task *, struct ObjectEvent *, struct ObjectEvent *);

static void DoPlayerMatJump(void);
static void DoPlayerAvatarSecretBaseMatJump(u8);
static u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *, struct ObjectEvent *);

static void DoPlayerMatSpin(void);
static void PlayerAvatar_DoSecretBaseMatSpin(u8);
static bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *, struct ObjectEvent *);
static bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *, struct ObjectEvent *);
static bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *, struct ObjectEvent *);
static bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *, struct ObjectEvent *);

static void CreateStopSurfingTask(enum Direction);
static void Task_StopSurfingInit(u8);
static void Task_WaitStopSurfing(u8);

static u8 TrySpinPlayerForWarp(struct ObjectEvent *, s16 *);

static bool8 (*const sForcedMovementTestFuncs[NUM_FORCED_MOVEMENTS])(u8) =
{
    MetatileBehavior_IsTrickHouseSlipperyFloor,
    MetatileBehavior_IsIce_2,
    MetatileBehavior_IsWalkSouth,
    MetatileBehavior_IsWalkNorth,
    MetatileBehavior_IsWalkWest,
    MetatileBehavior_IsWalkEast,
    MetatileBehavior_IsSouthwardCurrent,
    MetatileBehavior_IsNorthwardCurrent,
    MetatileBehavior_IsWestwardCurrent,
    MetatileBehavior_IsEastwardCurrent,
    MetatileBehavior_IsSlideSouth,
    MetatileBehavior_IsSlideNorth,
    MetatileBehavior_IsSlideWest,
    MetatileBehavior_IsSlideEast,
    MetatileBehavior_IsWaterfall,
    MetatileBehavior_IsSecretBaseJumpMat,
    MetatileBehavior_IsSecretBaseSpinMat,
    MetatileBehavior_IsMuddySlope,
    MetatileBehavior_IsSpinRight,
    MetatileBehavior_IsSpinLeft,
    MetatileBehavior_IsSpinUp,
    MetatileBehavior_IsSpinDown,
};

// + 1 for ForcedMovement_None, which is excluded above
static bool8 (*const sForcedMovementFuncs[NUM_FORCED_MOVEMENTS + 1])(void) =
{
    ForcedMovement_None,
    ForcedMovement_Slip,
    ForcedMovement_Slip,
    ForcedMovement_WalkSouth,
    ForcedMovement_WalkNorth,
    ForcedMovement_WalkWest,
    ForcedMovement_WalkEast,
    ForcedMovement_PushedSouthByCurrent,
    ForcedMovement_PushedNorthByCurrent,
    ForcedMovement_PushedWestByCurrent,
    ForcedMovement_PushedEastByCurrent,
    ForcedMovement_SlideSouth,
    ForcedMovement_SlideNorth,
    ForcedMovement_SlideWest,
    ForcedMovement_SlideEast,
    ForcedMovement_PushedSouthByCurrent,
    ForcedMovement_MatJump,
    ForcedMovement_MatSpin,
    ForcedMovement_MuddySlope,
    ForcedMovement_SpinRight,
    ForcedMovement_SpinLeft,
    ForcedMovement_SpinUp,
    ForcedMovement_SpinDown,
};

static void (*const sPlayerNotOnBikeFuncs[])(enum Direction, u16) =
{
    [NOT_MOVING]     = PlayerNotOnBikeNotMoving,
    [TURN_DIRECTION] = PlayerNotOnBikeTurningInPlace,
    [MOVING]         = PlayerNotOnBikeMoving,
};

static bool8 (*const sAcroBikeTrickMetatiles[NUM_ACRO_BIKE_COLLISIONS])(u8) =
{
    MetatileBehavior_IsBumpySlope,
    MetatileBehavior_IsIsolatedVerticalRail,
    MetatileBehavior_IsIsolatedHorizontalRail,
    MetatileBehavior_IsVerticalRail,
    MetatileBehavior_IsHorizontalRail,
};

static const enum Collision sAcroBikeTrickCollisionTypes[NUM_ACRO_BIKE_COLLISIONS] = {
    COLLISION_WHEELIE_HOP,
    COLLISION_ISOLATED_VERTICAL_RAIL,
    COLLISION_ISOLATED_HORIZONTAL_RAIL,
    COLLISION_VERTICAL_RAIL,
    COLLISION_HORIZONTAL_RAIL,
};

static void (*const sPlayerAvatarTransitionFuncs[])(struct ObjectEvent *) =
{
    [PLAYER_AVATAR_STATE_NORMAL]     = PlayerAvatarTransition_Normal,
    [PLAYER_AVATAR_STATE_MACH_BIKE]  = PlayerAvatarTransition_MachBike,
    [PLAYER_AVATAR_STATE_ACRO_BIKE]  = PlayerAvatarTransition_AcroBike,
    [PLAYER_AVATAR_STATE_SURFING]    = PlayerAvatarTransition_Surfing,
    [PLAYER_AVATAR_STATE_UNDERWATER] = PlayerAvatarTransition_Underwater,
    [PLAYER_AVATAR_STATE_FIELD_MOVE] = PlayerAvatarTransition_ReturnToField,
    [PLAYER_AVATAR_STATE_FISHING]    = PlayerAvatarTransition_Dummy,
    [PLAYER_AVATAR_STATE_WATERING]   = PlayerAvatarTransition_Dummy,
};

static bool8 (*const sArrowWarpMetatileBehaviorChecks[])(u8) =
{
    [DIR_SOUTH - 1] = MetatileBehavior_IsSouthArrowWarp,
    [DIR_NORTH - 1] = MetatileBehavior_IsNorthArrowWarp,
    [DIR_WEST - 1]  = MetatileBehavior_IsWestArrowWarp,
    [DIR_EAST - 1]  = MetatileBehavior_IsEastArrowWarp,
};

static const u8 sRivalAvatarGfxIds[][GENDER_COUNT] =
{
    [PLAYER_AVATAR_STATE_NORMAL]     = {OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL,     OBJ_EVENT_GFX_RIVAL_MAY_NORMAL},
    [PLAYER_AVATAR_STATE_MACH_BIKE]  = {OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE,  OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE},
    [PLAYER_AVATAR_STATE_ACRO_BIKE]  = {OBJ_EVENT_GFX_RIVAL_BRENDAN_ACRO_BIKE,  OBJ_EVENT_GFX_RIVAL_MAY_ACRO_BIKE},
    [PLAYER_AVATAR_STATE_SURFING]    = {OBJ_EVENT_GFX_RIVAL_BRENDAN_SURFING,    OBJ_EVENT_GFX_RIVAL_MAY_SURFING},
    [PLAYER_AVATAR_STATE_UNDERWATER] = {OBJ_EVENT_GFX_BRENDAN_UNDERWATER,       OBJ_EVENT_GFX_MAY_UNDERWATER},
    [PLAYER_AVATAR_STATE_FIELD_MOVE] = {OBJ_EVENT_GFX_RIVAL_BRENDAN_FIELD_MOVE, OBJ_EVENT_GFX_RIVAL_MAY_FIELD_MOVE},
    [PLAYER_AVATAR_STATE_FISHING]    = {OBJ_EVENT_GFX_BRENDAN_FISHING,          OBJ_EVENT_GFX_MAY_FISHING},
    [PLAYER_AVATAR_STATE_WATERING]   = {OBJ_EVENT_GFX_BRENDAN_WATERING,         OBJ_EVENT_GFX_MAY_WATERING},
    [PLAYER_AVATAR_STATE_VSSEEKER]   = {OBJ_EVENT_GFX_RIVAL_BRENDAN_FIELD_MOVE, OBJ_EVENT_GFX_RIVAL_MAY_FIELD_MOVE},
};

static const u16 sPlayerAvatarGfxIds[][GENDER_COUNT] =
{
    [PLAYER_AVATAR_STATE_NORMAL]     = {PLAYER_AVATAR_GFX_MALE_NORMAL,     PLAYER_AVATAR_GFX_FEMALE_NORMAL},
    [PLAYER_AVATAR_STATE_MACH_BIKE]  = {PLAYER_AVATAR_GFX_MALE_MACH_BIKE,  PLAYER_AVATAR_GFX_FEMALE_MACH_BIKE},
    [PLAYER_AVATAR_STATE_ACRO_BIKE]  = {PLAYER_AVATAR_GFX_MALE_ACRO_BIKE,  PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE},
    [PLAYER_AVATAR_STATE_SURFING]    = {PLAYER_AVATAR_GFX_MALE_SURFING,    PLAYER_AVATAR_GFX_FEMALE_SURFING},
    [PLAYER_AVATAR_STATE_UNDERWATER] = {PLAYER_AVATAR_GFX_MALE_UNDERWATER, PLAYER_AVATAR_GFX_FEMALE_UNDERWATER},
    [PLAYER_AVATAR_STATE_FIELD_MOVE] = {PLAYER_AVATAR_GFX_MALE_FIELD_MOVE, PLAYER_AVATAR_GFX_FEMALE_FIELD_MOVE},
    [PLAYER_AVATAR_STATE_FISHING]    = {PLAYER_AVATAR_GFX_MALE_FISHING,    PLAYER_AVATAR_GFX_FEMALE_FISHING},
    [PLAYER_AVATAR_STATE_WATERING]   = {PLAYER_AVATAR_GFX_MALE_WATERING,   PLAYER_AVATAR_GFX_FEMALE_WATERING},
    [PLAYER_AVATAR_STATE_VSSEEKER]   = {PLAYER_AVATAR_GFX_MALE_VSSEEKER,   PLAYER_AVATAR_GFX_FEMALE_VSSEEKER},
};

static const u8 sFRLGAvatarGfxIds[GENDER_COUNT] =
{
    [MALE]   = OBJ_EVENT_GFX_RED,
    [FEMALE] = OBJ_EVENT_GFX_LEAF
};

static const u8 sRSAvatarGfxIds[GENDER_COUNT] =
{
    [MALE]   = OBJ_EVENT_GFX_LINK_RS_BRENDAN,
    [FEMALE] = OBJ_EVENT_GFX_LINK_RS_MAY
};

static const struct PACKED
{
    u16 graphicsId;
    u8 playerFlag;
} sPlayerAvatarGfxToStateFlag[GENDER_COUNT][5] =
{
    [MALE] =
    {
        {PLAYER_AVATAR_GFX_MALE_NORMAL,     PLAYER_AVATAR_FLAG_ON_FOOT},
        {PLAYER_AVATAR_GFX_MALE_MACH_BIKE,  PLAYER_AVATAR_FLAG_MACH_BIKE},
        {PLAYER_AVATAR_GFX_MALE_ACRO_BIKE,  PLAYER_AVATAR_FLAG_ACRO_BIKE},
        {PLAYER_AVATAR_GFX_MALE_SURFING,    PLAYER_AVATAR_FLAG_SURFING},
        {PLAYER_AVATAR_GFX_MALE_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER},
    },
    [FEMALE] =
    {
        {PLAYER_AVATAR_GFX_FEMALE_NORMAL,         PLAYER_AVATAR_FLAG_ON_FOOT},
        {PLAYER_AVATAR_GFX_FEMALE_MACH_BIKE,      PLAYER_AVATAR_FLAG_MACH_BIKE},
        {PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE,      PLAYER_AVATAR_FLAG_ACRO_BIKE},
        {PLAYER_AVATAR_GFX_FEMALE_SURFING,        PLAYER_AVATAR_FLAG_SURFING},
        {PLAYER_AVATAR_GFX_FEMALE_UNDERWATER,     PLAYER_AVATAR_FLAG_UNDERWATER},
    }
};

static bool8 (*const sArrowWarpMetatileBehaviorChecks2[])(u8) =  //Duplicate of sArrowWarpMetatileBehaviorChecks
{
    [DIR_SOUTH - 1] = MetatileBehavior_IsSouthArrowWarp,
    [DIR_NORTH - 1] = MetatileBehavior_IsNorthArrowWarp,
    [DIR_WEST - 1]  = MetatileBehavior_IsWestArrowWarp,
    [DIR_EAST - 1]  = MetatileBehavior_IsEastArrowWarp,
};

static bool8 (*const sPushBoulderFuncs[])(struct Task *, struct ObjectEvent *, struct ObjectEvent *) =
{
    PushBoulder_Start,
    PushBoulder_Move,
    PushBoulder_End,
};

static bool8 (*const sPlayerAvatarSecretBaseMatJump[])(struct Task *, struct ObjectEvent *) =
{
    PlayerAvatar_DoSecretBaseMatJump,
};

static bool8 (*const sPlayerAvatarSecretBaseMatSpin[])(struct Task *, struct ObjectEvent *) =
{
    PlayerAvatar_SecretBaseMatSpinStep0,
    PlayerAvatar_SecretBaseMatSpinStep1,
    PlayerAvatar_SecretBaseMatSpinStep2,
    PlayerAvatar_SecretBaseMatSpinStep3,
};

void MovementType_Player(struct Sprite *sprite)
{
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, (bool8 (*)(struct ObjectEvent *, struct Sprite *))ObjectEventCB2_NoMovement2);
}

static u8 ObjectEventCB2_NoMovement2(void)
{
    return 0;
}

void PlayerStep(enum Direction direction, u16 newKeys, u16 heldKeys)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    HideShowWarpArrow(playerObjEvent);
    if (gPlayerAvatar.preventStep == FALSE && !TryUpdatePlayerSpinDirection())
    {
        Bike_TryAcroBikeHistoryUpdate(newKeys, heldKeys);
        if (TryInterruptObjectEventSpecialAnim(playerObjEvent, direction) == 0)
        {
            npc_clear_strange_bits(playerObjEvent);
            DoPlayerAvatarTransition();
            if (TryDoMetatileBehaviorForcedMovement() == 0)
            {
                if (GetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT) != FNPC_FORCED_NONE)
                {
                    gPlayerAvatar.preventStep = TRUE;
                    CreateTask(Task_MoveNPCFollowerAfterForcedMovement, 1);
                }
                else
                {
                    MovePlayerAvatarUsingKeypadInput(direction, newKeys, heldKeys);
                    PlayerAllowForcedMovementIfMovingSameDirection();
                }
            }
        }
    }
}

#define sCounter        data[3]

static bool8 TryInterruptObjectEventSpecialAnim(struct ObjectEvent *playerObjEvent, enum Direction direction)
{
    if (ObjectEventIsMovementOverridden(playerObjEvent)
     && !ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        u8 heldMovementActionId = ObjectEventGetHeldMovementActionId(playerObjEvent);
        if (heldMovementActionId > MOVEMENT_ACTION_WALK_FAST_RIGHT && heldMovementActionId < MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN)
        {
            struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];

            if (direction == DIR_NONE)
            {
                return TRUE;
            }

            if (playerObjEvent->movementDirection != direction)
            {
                if (I_ORAS_DOWSING_FLAG != 0 && FlagGet(I_ORAS_DOWSING_FLAG))
                    gSprites[playerObj->fieldEffectSpriteId].sCounter = 0;

                ObjectEventClearHeldMovement(playerObjEvent);
                return FALSE;
            }

            if (CheckForPlayerAvatarStaticCollision(direction) == COLLISION_NONE)
            {
                if (I_ORAS_DOWSING_FLAG != 0 && FlagGet(I_ORAS_DOWSING_FLAG))
                {
                    gSprites[playerObj->fieldEffectSpriteId].sCounter = 0;
                    gSprites[playerObj->fieldEffectSpriteId].y2 = 0;
                }

                ObjectEventClearHeldMovement(playerObjEvent);
                return FALSE;
            }
        }

        return TRUE;
    }

    return FALSE;
}

#undef sCounter

static void npc_clear_strange_bits(struct ObjectEvent *objEvent)
{
    objEvent->inanimate = FALSE;
    objEvent->disableAnim = FALSE;
    objEvent->facingDirectionLocked = FALSE;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_DASH;
}

static void MovePlayerAvatarUsingKeypadInput(enum Direction direction, u16 newKeys, u16 heldKeys)
{
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        MovePlayerOnBike(direction, newKeys, heldKeys);
    else
        MovePlayerNotOnBike(direction, heldKeys);
}

static void PlayerAllowForcedMovementIfMovingSameDirection(void)
{
    if (gPlayerAvatar.runningState == MOVING)
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
}

static bool8 TryUpdatePlayerSpinDirection(void)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_FORCED_MOVE) && MetatileBehavior_IsSpinTile(gPlayerAvatar.lastSpinTile))
    {
        struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
        if (playerObjEvent->heldMovementFinished)
        {
            if (MetatileBehavior_IsStopSpinning(playerObjEvent->currentMetatileBehavior))
            {
                return FALSE;
            }
            if (MetatileBehavior_IsSpinTile(playerObjEvent->currentMetatileBehavior))
            {
                gPlayerAvatar.lastSpinTile = playerObjEvent->currentMetatileBehavior;
            }
            ObjectEventClearHeldMovement(playerObjEvent);
            PlayerApplyTileForcedMovement(gPlayerAvatar.lastSpinTile);
        }
        return TRUE;
    }
    return FALSE;
}

bool8 TryDoMetatileBehaviorForcedMovement(void)
{
    return sForcedMovementFuncs[GetForcedMovementByMetatileBehavior()]();
}

static u8 GetForcedMovementByMetatileBehavior(void)
{
    u8 i;

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_CONTROLLABLE))
    {
        u8 metatileBehavior = gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior;

        for (i = 0; i < NUM_FORCED_MOVEMENTS; i++)
        {
            if (sForcedMovementTestFuncs[i](metatileBehavior))
            {
                gPlayerAvatar.lastSpinTile = metatileBehavior;
                return i + 1;
            }
        }
    }
    return 0;
}

static bool8 ForcedMovement_None(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_FORCED_MOVE)
    {
        struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

        playerObjEvent->facingDirectionLocked = FALSE;
        playerObjEvent->enableAnim = TRUE;
        SetObjectEventDirection(playerObjEvent, playerObjEvent->facingDirection);
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_FORCED_MOVE;
        PlayerSetCopyableMovement(COPY_MOVE_NONE);
    }
    return FALSE;
}

static bool8 DoForcedMovement(enum Direction direction, void (*moveFunc)(enum Direction))
{
    struct PlayerAvatar *playerAvatar = &gPlayerAvatar;
    enum Collision collision;

    // Check for sideways stairs onto ice movement.
    switch (direction)
    {
    case DIR_NORTHWEST:
    case DIR_SOUTHWEST:
        direction = DIR_WEST;
        break;
    case DIR_NORTHEAST:
    case DIR_SOUTHEAST:
        direction = DIR_EAST;
        break;
    default:
        break;
    }

    collision = CheckForPlayerAvatarCollision(direction);

    playerAvatar->flags |= PLAYER_AVATAR_FLAG_FORCED_MOVE;
    if (collision)
    {
        ForcedMovement_None();
        if (collision < COLLISION_STOP_SURFING)
        {
            return FALSE;
        }
        else
        {
            if (collision == COLLISION_LEDGE_JUMP)
            {
                SetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT, FNPC_FORCED_NONE);
                PlayerJumpLedge(direction);
            }

            playerAvatar->flags |= PLAYER_AVATAR_FLAG_FORCED_MOVE;
            playerAvatar->runningState = MOVING;
            return TRUE;
        }
    }
    else
    {
        if (PlayerHasFollowerNPC() && GetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT) != FNPC_FORCED_STAY)
            SetFollowerNPCData(FNPC_DATA_FORCED_MOVEMENT, FNPC_FORCED_FOLLOW);

        playerAvatar->runningState = MOVING;
        moveFunc(direction);
        return TRUE;
    }
}

static bool8 DoForcedMovementInCurrentDirection(void (*moveFunc)(enum Direction))
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    playerObjEvent->disableAnim = TRUE;
    return DoForcedMovement(playerObjEvent->movementDirection, moveFunc);
}

static bool8 ForcedMovement_Slip(void)
{
    return DoForcedMovementInCurrentDirection(PlayerWalkFast);
}

static bool8 ForcedMovement_WalkSouth(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerWalkNormal);
}

static bool8 ForcedMovement_WalkNorth(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerWalkNormal);
}

static bool8 ForcedMovement_WalkWest(void)
{
    return DoForcedMovement(DIR_WEST, PlayerWalkNormal);
}

static bool8 ForcedMovement_WalkEast(void)
{
    return DoForcedMovement(DIR_EAST, PlayerWalkNormal);
}

static bool8 ForcedMovement_PushedSouthByCurrent(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerRideWaterCurrent);
}

static bool8 ForcedMovement_PushedNorthByCurrent(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerRideWaterCurrent);
}

static bool8 ForcedMovement_PushedWestByCurrent(void)
{
    return DoForcedMovement(DIR_WEST, PlayerRideWaterCurrent);
}

static bool8 ForcedMovement_PushedEastByCurrent(void)
{
    return DoForcedMovement(DIR_EAST, PlayerRideWaterCurrent);
}

static bool8 ForcedMovement_Slide(enum Direction direction, void (*moveFunc)(enum Direction))
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    playerObjEvent->disableAnim = TRUE;
    playerObjEvent->facingDirectionLocked = TRUE;
    return DoForcedMovement(direction, moveFunc);
}

static bool8 ForcedMovement_SlideSouth(void)
{
    return ForcedMovement_Slide(DIR_SOUTH, PlayerWalkFast);
}

static bool8 ForcedMovement_SlideNorth(void)
{
    return ForcedMovement_Slide(DIR_NORTH, PlayerWalkFast);
}

static bool8 ForcedMovement_SlideWest(void)
{
    return ForcedMovement_Slide(DIR_WEST, PlayerWalkFast);
}

static bool8 ForcedMovement_SlideEast(void)
{
    return ForcedMovement_Slide(DIR_EAST, PlayerWalkFast);
}

static bool8 ForcedMovement_MatJump(void)
{
    DoPlayerMatJump();
    return TRUE;
}

static bool8 ForcedMovement_MatSpin(void)
{
    DoPlayerMatSpin();
    return TRUE;
}

static bool8 ForcedMovement_MuddySlope(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (playerObjEvent->movementDirection != DIR_NORTH || GetPlayerSpeed() < PLAYER_SPEED_FASTEST)
    {
        Bike_UpdateBikeCounterSpeed(0);
        playerObjEvent->facingDirectionLocked = TRUE;
        return DoForcedMovement(DIR_SOUTH, PlayerWalkFast);
    }
    else
    {
        return FALSE;
    }
}

static bool8 ForcedMovement_SpinRight(void)
{
    PlaySpinSound();
    return DoForcedMovement(DIR_EAST, PlayerGoSpin);
}

static bool8 ForcedMovement_SpinLeft(void)
{
    PlaySpinSound();
    return DoForcedMovement(DIR_WEST, PlayerGoSpin);
}

static bool8 ForcedMovement_SpinUp(void)
{
    PlaySpinSound();
    return DoForcedMovement(DIR_NORTH, PlayerGoSpin);
}

static bool8 ForcedMovement_SpinDown(void)
{
    PlaySpinSound();
    return DoForcedMovement(DIR_SOUTH, PlayerGoSpin);
}

static void PlaySpinSound(void)
{
    PlaySE(SE_M_RAZOR_WIND2);
}

static void MovePlayerNotOnBike(enum Direction direction, u16 heldKeys)
{
    sPlayerNotOnBikeFuncs[CheckMovementInputNotOnBike(direction)](direction, heldKeys);
}

static u8 CheckMovementInputNotOnBike(enum Direction direction)
{
    if (direction == DIR_NONE)
        return gPlayerAvatar.runningState = NOT_MOVING;
    else if (direction != GetPlayerMovementDirection() && gPlayerAvatar.runningState != MOVING)
        return gPlayerAvatar.runningState = TURN_DIRECTION;
    else
        return gPlayerAvatar.runningState = MOVING;
}

static void PlayerNotOnBikeNotMoving(enum Direction direction, u16 heldKeys)
{
    PlayerFaceDirection(GetPlayerFacingDirection());
}

void UpdateSpinData(void)
{
    if (gPlayerSpinData.spinTimeout != 0)
    {
        gPlayerSpinData.spinTimeout--;
        if (gPlayerSpinData.VBlanksSpinning < 2048)
            gPlayerSpinData.VBlanksSpinning++;
        if (gPlayerSpinData.spinTimeout == 0 && gPlayerSpinData.spinDirection != SPIN_DIRECTION_NONE)
            gPlayerSpinData.triggerEvo = TRUE;
    }
}

void ResetSpinTimer(void)
{
    gPlayerSpinData.spinTimeout = 0;
    gPlayerSpinData.VBlanksSpinning = 0;
    gPlayerSpinData.spinDirection = SPIN_DIRECTION_NONE;
    gPlayerSpinData.spinHistory0 = DIR_NONE;
    gPlayerSpinData.spinHistory1 = DIR_NONE;
    gPlayerSpinData.spinHistory2 = DIR_NONE;
    gPlayerSpinData.spinHistory3 = DIR_NONE;
}

static const u8 sClockwiseDirections[4][4] =
{
    { DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST, },
    { DIR_EAST, DIR_SOUTH, DIR_WEST, DIR_NORTH, },
    { DIR_SOUTH, DIR_WEST, DIR_NORTH, DIR_EAST, },
    { DIR_WEST, DIR_NORTH, DIR_EAST, DIR_SOUTH, },
};

static const u8 sCounterClockwiseDirections[4][4] =
{
    { DIR_NORTH, DIR_WEST, DIR_SOUTH, DIR_EAST, },
    { DIR_WEST, DIR_SOUTH, DIR_EAST, DIR_NORTH, },
    { DIR_SOUTH, DIR_EAST, DIR_NORTH, DIR_WEST, },
    { DIR_EAST, DIR_NORTH, DIR_WEST, DIR_SOUTH, },
};

static void WindUpSpinTimer(enum Direction direction)
{
    gPlayerSpinData.spinTimeout = 60;
    gPlayerSpinData.spinHistory0 = gPlayerSpinData.spinHistory1;
    gPlayerSpinData.spinHistory1 = gPlayerSpinData.spinHistory2;
    gPlayerSpinData.spinHistory2 = gPlayerSpinData.spinHistory3;
    gPlayerSpinData.spinHistory3 = direction;

    for (int i = 0; i < ARRAY_COUNT(sClockwiseDirections); i++)
    {
        if (gPlayerSpinData.spinHistory0 == sClockwiseDirections[i][0]
            && gPlayerSpinData.spinHistory1 == sClockwiseDirections[i][1]
            && gPlayerSpinData.spinHistory2 == sClockwiseDirections[i][2]
            && gPlayerSpinData.spinHistory3 == sClockwiseDirections[i][3])
        {
            gPlayerSpinData.spinDirection = SPIN_DIRECTION_CLOCKWISE;
            return;
        }
    }
    for (int i = 0; i < ARRAY_COUNT(sCounterClockwiseDirections); i++)
    {
        if (gPlayerSpinData.spinHistory0 == sCounterClockwiseDirections[i][0]
            && gPlayerSpinData.spinHistory1 == sCounterClockwiseDirections[i][1]
            && gPlayerSpinData.spinHistory2 == sCounterClockwiseDirections[i][2]
            && gPlayerSpinData.spinHistory3 == sCounterClockwiseDirections[i][3])
        {
            gPlayerSpinData.spinDirection = SPIN_DIRECTION_COUNTER_CLOCKWISE;
            return;
        }
    }
    gPlayerSpinData.spinDirection = SPIN_DIRECTION_NONE;
}

bool32 CanTriggerSpinEvolution()
{
    gSpecialVar_0x8000 = EVO_NONE;
    if (gPlayerSpinData.triggerEvo)
    {
        u32 seconds = gPlayerSpinData.VBlanksSpinning / 60;
        u32 direction = gPlayerSpinData.spinDirection;
        if (seconds >= 10)
        {
            gSpecialVar_0x8000 = SPIN_EITHER;
        }

        else if (seconds >= 5 && seconds < 10)
        {
            if (direction == SPIN_DIRECTION_CLOCKWISE)
                gSpecialVar_0x8000 = SPIN_CW_LONG;
            else if (direction == SPIN_DIRECTION_COUNTER_CLOCKWISE)
                gSpecialVar_0x8000 = SPIN_CCW_LONG;
        }
        else if (seconds < 5)
        {
            if (direction == SPIN_DIRECTION_CLOCKWISE)
                gSpecialVar_0x8000 = SPIN_CW_SHORT;
            else if (direction == SPIN_DIRECTION_COUNTER_CLOCKWISE)
                gSpecialVar_0x8000 = SPIN_CCW_SHORT;
        }
        gPlayerSpinData.triggerEvo = FALSE;
    }
    if (gSpecialVar_0x8000 != EVO_NONE)
        return TRUE;

    return FALSE;
}

static void PlayerNotOnBikeTurningInPlace(enum Direction direction, u16 heldKeys)
{
    WindUpSpinTimer(direction);
    PlayerTurnInPlace(direction);
}

static void PlayerNotOnBikeMoving(enum Direction direction, u16 heldKeys)
{
    enum Collision collision = CheckForPlayerAvatarCollision(direction);

    if (collision)
    {
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerJumpLedge(direction);
            return;
        }
        else if (collision == COLLISION_OBJECT_EVENT && IsPlayerCollidingWithFarawayIslandMew(direction))
        {
            PlayerNotOnBikeCollideWithFarawayIslandMew(direction);
            return;
        }
        else if (collision == COLLISION_STAIR_WARP)
        {
            PlayerFaceDirection(direction);
        }
        else
        {
            // Player collided with something. Certain collisions have special handling that precludes the normal collision effect.
            // COLLISION_STOP_SURFING and COLLISION_PUSHED_BOULDER's effects are started by CheckForObjectEventCollision.
            // COLLISION_LEDGE_JUMP's effect is handled further up in this function, so it will never reach this point.
            // COLLISION_ROTATING_GATE is unusual however, this was probably included by mistake. When the player walks into a
            // rotating gate that cannot rotate there is no additional handling, it's just a regular collision. Its exclusion here
            // means that the player avatar won't update if they encounter this kind of collision. This has two noticeable effects:
            // - Colliding with it head-on stops the player dead, rather than playing the walking animation and playing a bump sound effect
            // - Colliding with it by changing direction won't turn the player avatar, their walking animation will just speed up.
#ifdef BUGFIX
            if (collision != COLLISION_STOP_SURFING
             && collision != COLLISION_LEDGE_JUMP
             && collision != COLLISION_PUSHED_BOULDER)
#else
            if (collision != COLLISION_STOP_SURFING
             && collision != COLLISION_LEDGE_JUMP
             && collision != COLLISION_PUSHED_BOULDER
             && collision != COLLISION_ROTATING_GATE)
#endif
            {
                PlayerNotOnBikeCollide(direction);
            }
            return;
        }
    }

    ResetSpinTimer(); // Everything below will move the player a space, reset the timer.
    gPlayerAvatar.creeping = FALSE;
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
    {
        if (FlagGet(DN_FLAG_SEARCHING) && (heldKeys & A_BUTTON))
        {
            gPlayerAvatar.creeping = TRUE;
            PlayerWalkSlow(direction);
        }
        else
        {
            // speed 2 is fast, same speed as running
            PlayerWalkFast(direction);
        }
        return;
    }

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_UNDERWATER)
     && (heldKeys & B_BUTTON)
     && FlagGet(FLAG_SYS_B_DASH)
     && IsRunningDisallowed(gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior) == 0
     && !FollowerNPCComingThroughDoor()
     && (I_ORAS_DOWSING_FLAG == 0 || (I_ORAS_DOWSING_FLAG != 0 && !FlagGet(I_ORAS_DOWSING_FLAG))))
    {
        if (ObjectMovingOnRockStairs(&gObjectEvents[gPlayerAvatar.objectEventId], direction))
            PlayerRunSlow(direction);
        else
            PlayerRun(direction);

        gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_DASH;
        return;
    }
    else if (FlagGet(DN_FLAG_SEARCHING) && (heldKeys & A_BUTTON))
    {
        gPlayerAvatar.creeping = TRUE;
        PlayerWalkSlow(direction);
    }
    else
    {
        if (ObjectMovingOnRockStairs(&gObjectEvents[gPlayerAvatar.objectEventId], direction))
            PlayerWalkSlowStairs(direction);
        else
            PlayerWalkNormal(direction);
    }
}

static enum Collision CheckForPlayerAvatarCollision(enum Direction direction)
{
    s16 x, y;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    x = playerObjEvent->currentCoords.x;
    y = playerObjEvent->currentCoords.y;
    if (IsDirectionalStairWarpMetatileBehavior(MapGridGetMetatileBehaviorAt(x, y), direction))
        return COLLISION_STAIR_WARP;

    MoveCoords(direction, &x, &y);
    return CheckForObjectEventCollision(playerObjEvent, x, y, direction, MapGridGetMetatileBehaviorAt(x, y));
}

static enum Collision CheckForPlayerAvatarStaticCollision(enum Direction direction)
{
    s16 x, y;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    x = playerObjEvent->currentCoords.x;
    y = playerObjEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return CheckForObjectEventStaticCollision(playerObjEvent, x, y, direction, MapGridGetMetatileBehaviorAt(x, y));
}

enum Collision CheckForObjectEventCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, enum Direction direction, u8 metatileBehavior)
{
    enum Collision collision = GetCollisionAtCoords(objectEvent, x, y, direction);

    if (collision == COLLISION_ELEVATION_MISMATCH && CanStopSurfing(x, y, direction))
        return COLLISION_STOP_SURFING;

    if (ShouldJumpLedge(x, y, direction))
    {
        IncrementGameStat(GAME_STAT_JUMPED_DOWN_LEDGES);
        return COLLISION_LEDGE_JUMP;
    }
    if (collision == COLLISION_OBJECT_EVENT && TryPushBoulder(x, y, direction))
        return COLLISION_PUSHED_BOULDER;

    if (collision == COLLISION_NONE)
    {
        if (CheckForRotatingGatePuzzleCollision(direction, x, y))
            return COLLISION_ROTATING_GATE;
        CheckAcroBikeCollision(x, y, metatileBehavior, &collision);
    }

    return collision;
}

static enum Collision CheckForObjectEventStaticCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, enum Direction direction, u8 metatileBehavior)
{
    enum Collision collision = GetCollisionAtCoords(objectEvent, x, y, direction);

    if (collision == COLLISION_NONE)
    {
        if (CheckForRotatingGatePuzzleCollisionWithoutAnimation(direction, x, y))
            return COLLISION_ROTATING_GATE;
        CheckAcroBikeCollision(x, y, metatileBehavior, &collision);
    }
    return collision;
}

static bool8 CanStopSurfing(s16 x, s16 y, enum Direction direction)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
     && MapGridGetElevationAt(x, y) == ELEVATION_DEFAULT
     && (GetObjectEventIdByPosition(x, y, ELEVATION_DEFAULT) == OBJECT_EVENTS_COUNT
     || GetObjectEventIdByPosition(x, y, ELEVATION_DEFAULT) == GetFollowerNPCObjectId()
     ))
    {
        CreateStopSurfingTask(direction);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldJumpLedge(s16 x, s16 y, enum Direction direction)
{
    if (GetLedgeJumpDirection(x, y, direction) != DIR_NONE)
        return TRUE;
    else
        return FALSE;
}

static bool8 TryPushBoulder(s16 x, s16 y, enum Direction direction)
{
    if (FlagGet(FLAG_SYS_USE_STRENGTH))
    {
        u8 objectEventId = GetObjectEventIdByXY(x, y);

        if (objectEventId != OBJECT_EVENTS_COUNT && (gObjectEvents[objectEventId].graphicsId == OBJ_EVENT_GFX_PUSHABLE_BOULDER || gObjectEvents[objectEventId].graphicsId == OBJ_EVENT_GFX_PUSHABLE_BOULDER_FRLG))
        {
            x = gObjectEvents[objectEventId].currentCoords.x;
            y = gObjectEvents[objectEventId].currentCoords.y;
            MoveCoords(direction, &x, &y);
            if (GetCollisionAtCoords(&gObjectEvents[objectEventId], x, y, direction) == COLLISION_NONE
             && MetatileBehavior_IsNonAnimDoor(MapGridGetMetatileBehaviorAt(x, y)) == FALSE)
            {
                StartStrengthAnim(objectEventId, direction);
                return TRUE;
            }
        }
    }
    return FALSE;
}

static void CheckAcroBikeCollision(s16 x, s16 y, u8 metatileBehavior, enum Collision *collision)
{
    u8 i;

    for (i = 0; i < NUM_ACRO_BIKE_COLLISIONS; i++)
    {
        if (sAcroBikeTrickMetatiles[i](metatileBehavior))
        {
            *collision = sAcroBikeTrickCollisionTypes[i];
            return;
        }
    }
}

bool8 IsPlayerCollidingWithFarawayIslandMew(enum Direction direction)
{
    u8 mewObjectId;
    struct ObjectEvent *object;
    s16 playerX;
    s16 playerY;
    s16 mewPrevX;

    object = &gObjectEvents[gPlayerAvatar.objectEventId];
    playerX = object->currentCoords.x;
    playerY = object->currentCoords.y;

    MoveCoords(direction, &playerX, &playerY);
    mewObjectId = GetObjectEventIdByLocalIdAndMap(LOCALID_FARAWAY_ISLAND_MEW, MAP_NUM(MAP_FARAWAY_ISLAND_INTERIOR), MAP_GROUP(MAP_FARAWAY_ISLAND_INTERIOR));
    if (mewObjectId == OBJECT_EVENTS_COUNT)
        return FALSE;

    object = &gObjectEvents[mewObjectId];
    mewPrevX = object->previousCoords.x;

    if (mewPrevX == playerX)
    {
        if (object->previousCoords.y != playerY
            || object->currentCoords.x != mewPrevX
            || object->currentCoords.y != object->previousCoords.y)
        {
            if (object->previousCoords.x == playerX &&
                object->previousCoords.y == playerY)
                return TRUE;
        }
    }
    return FALSE;
}

void SetPlayerAvatarTransitionFlags(u16 transitionFlags)
{
    gPlayerAvatar.transitionFlags |= transitionFlags;
    DoPlayerAvatarTransition();
}

static void DoPlayerAvatarTransition(void)
{
    u8 i;
    u8 flags = gPlayerAvatar.transitionFlags;

    if (flags != 0)
    {
        for (i = 0; i < ARRAY_COUNT(sPlayerAvatarTransitionFuncs); i++, flags >>= 1)
        {
            if (flags & 1)
                sPlayerAvatarTransitionFuncs[i](&gObjectEvents[gPlayerAvatar.objectEventId]);
        }
        gPlayerAvatar.transitionFlags = 0;
    }
}

static void PlayerAvatarTransition_Dummy(struct ObjectEvent *objEvent)
{

}

static void PlayerAvatarTransition_Normal(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ON_FOOT);
}

static void PlayerAvatarTransition_MachBike(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_MACH_BIKE));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    if (IS_FRLG)
        SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_BIKE);
    else
        SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_MACH_BIKE);
    BikeClearState(0, 0);
}

static void PlayerAvatarTransition_AcroBike(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_ACRO_BIKE));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    if (IS_FRLG)
        SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_BIKE);
    else
        SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ACRO_BIKE);
    BikeClearState(0, 0);
    Bike_HandleBumpySlopeJump();
}

static void PlayerAvatarTransition_Surfing(struct ObjectEvent *objEvent)
{
    u8 spriteId;

    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_SURFING));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_SURFING);
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = gPlayerAvatar.objectEventId;
    spriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    objEvent->fieldEffectSpriteId = spriteId;
    SetSurfBlob_BobState(spriteId, BOB_PLAYER_AND_MON);
}

static void PlayerAvatarTransition_Underwater(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_UNDERWATER));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_UNDERWATER);
    objEvent->fieldEffectSpriteId = StartUnderwaterSurfBlobBobbing(objEvent->spriteId);
}

static void PlayerAvatarTransition_ReturnToField(struct ObjectEvent *objEvent)
{
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_CONTROLLABLE;
}

void UpdatePlayerAvatarTransitionState(void)
{
    gPlayerAvatar.tileTransitionState = T_NOT_MOVING;
    if (PlayerIsAnimActive())
    {
        if (!PlayerCheckIfAnimFinishedOrInactive())
        {
            if (!PlayerAnimIsMultiFrameStationary())
                gPlayerAvatar.tileTransitionState = T_TILE_TRANSITION;
        }
        else
        {
            if (!PlayerAnimIsMultiFrameStationaryAndStateNotTurning())
                gPlayerAvatar.tileTransitionState = T_TILE_CENTER;
        }
    }
}

static bool8 PlayerAnimIsMultiFrameStationary(void)
{
    u8 movementActionId = gObjectEvents[gPlayerAvatar.objectEventId].movementActionId;

    if (movementActionId <= MOVEMENT_ACTION_FACE_RIGHT
     || (movementActionId >= MOVEMENT_ACTION_DELAY_1 && movementActionId <= MOVEMENT_ACTION_DELAY_16)
     || (movementActionId >= MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN && movementActionId <= MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_RIGHT)
     || (movementActionId >= MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN && movementActionId <= MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT)
     || (movementActionId >= MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN && movementActionId <= MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT))
        return TRUE;
    else
        return FALSE;
}

static bool8 PlayerAnimIsMultiFrameStationaryAndStateNotTurning(void)
{
    if (PlayerAnimIsMultiFrameStationary() && gPlayerAvatar.runningState != TURN_DIRECTION)
        return TRUE;
    else
        return FALSE;
}

static bool8 PlayerIsAnimActive(void)
{
    return ObjectEventIsMovementOverridden(&gObjectEvents[gPlayerAvatar.objectEventId]);
}

static bool8 PlayerCheckIfAnimFinishedOrInactive(void)
{
    return ObjectEventCheckHeldMovementStatus(&gObjectEvents[gPlayerAvatar.objectEventId]);
}

static void PlayerSetCopyableMovement(enum CopyMovement movement)
{
    gObjectEvents[gPlayerAvatar.objectEventId].playerCopyableMovement = movement;
}

enum CopyMovement PlayerGetCopyableMovement(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].playerCopyableMovement;
}

static void PlayerForceSetHeldMovement(u8 movementActionId)
{
    ObjectEventForceSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], movementActionId);
}

void PlayerSetAnimId(u8 movementActionId, enum CopyMovement copyableMovement)
{
    if (!PlayerIsAnimActive())
    {
        PlayerSetCopyableMovement(copyableMovement);
        ObjectEventSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], movementActionId);
    }
}

// slow stairs (from FRLG--faster than slow)
static void PlayerWalkSlowStairs(enum Direction direction)
{
    PlayerSetAnimId(GetWalkSlowStairsMovementAction(direction), COPY_MOVE_WALK);
}

// slow
static void UNUSED PlayerWalkSlow(enum Direction direction)
{
    PlayerSetAnimId(GetWalkSlowMovementAction(direction), COPY_MOVE_WALK);
}

static void PlayerRunSlow(enum Direction direction)
{
    PlayerSetAnimId(GetPlayerRunSlowMovementAction(direction), COPY_MOVE_WALK);
}

// normal speed (1 speed)
void PlayerWalkNormal(enum Direction direction)
{
    PlayerSetAnimId(GetWalkNormalMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerWalkFast(enum Direction direction)
{
    PlayerSetAnimId(GetWalkFastMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerRideWaterCurrent(enum Direction direction)
{
    PlayerSetAnimId(GetRideWaterCurrentMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerWalkFaster(enum Direction direction)
{
    PlayerSetAnimId(GetWalkFasterMovementAction(direction), COPY_MOVE_WALK);
}

static void PlayerRun(enum Direction direction)
{
    PlayerSetAnimId(GetPlayerRunMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerOnBikeCollide(enum Direction direction)
{
    PlayCollisionSoundIfNotFacingWarp(direction);
    PlayerSetAnimId(GetWalkInPlaceNormalMovementAction(direction), COPY_MOVE_WALK_COLLIDE);
    // Edge case: If the player stops at the top of a mud slide, but the NPC follower is still on a mud slide tile,
    // move the follower into the player and hide them.
    if (PlayerHasFollowerNPC())
    {
        struct ObjectEvent *npcFollower = &gObjectEvents[GetFollowerNPCObjectId()];
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

        if (npcFollower->invisible == FALSE
         && player->currentMetatileBehavior != MB_MUDDY_SLOPE
         && npcFollower->currentMetatileBehavior == MB_MUDDY_SLOPE)
        {
            gPlayerAvatar.preventStep = TRUE;
            ObjectEventSetHeldMovement(npcFollower, MOVEMENT_ACTION_WALK_FAST_UP);
            CreateTask(Task_HideNPCFollowerAfterMovementFinish, 2);
        }
    }
}

void PlayerOnBikeCollideWithFarawayIslandMew(enum Direction direction)
{
    PlayerSetAnimId(GetWalkInPlaceNormalMovementAction(direction), COPY_MOVE_WALK_COLLIDE);
}

static void PlayerNotOnBikeCollide(enum Direction direction)
{
    PlayCollisionSoundIfNotFacingWarp(direction);
    PlayerSetAnimId(GetWalkInPlaceSlowMovementAction(direction), COPY_MOVE_WALK_COLLIDE_SLOW);
}

static void PlayerNotOnBikeCollideWithFarawayIslandMew(enum Direction direction)
{
    PlayerSetAnimId(GetWalkInPlaceSlowMovementAction(direction), COPY_MOVE_WALK_COLLIDE);
}

void PlayerFaceDirection(enum Direction direction)
{
    PlayerSetAnimId(GetFaceDirectionMovementAction(direction), COPY_MOVE_FACE);
}

void PlayerTurnInPlace(enum Direction direction)
{
    PlayerSetAnimId(GetWalkInPlaceFastMovementAction(direction), COPY_MOVE_FACE);
}

void PlayerJumpLedge(enum Direction direction)
{
    PlaySE(SE_LEDGE);
    PlayerSetAnimId(GetJump2MovementAction(direction), COPY_MOVE_JUMP2);
}

// Stop player on current facing direction once they're done moving and if they're not currently Acro Biking on bumpy slope
void PlayerFreeze(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_CENTER || gPlayerAvatar.tileTransitionState == T_NOT_MOVING)
    {
        if (IsPlayerNotUsingAcroBikeOnBumpySlope())
            PlayerForceSetHeldMovement(GetFaceDirectionMovementAction(gObjectEvents[gPlayerAvatar.objectEventId].facingDirection));
    }
}

static void PlayerGoSpin(enum Direction direction)
{
    PlayerSetAnimId(GetSpinMovementAction(direction), 3);
}

static void PlayerApplyTileForcedMovement(u8 metatileBehavior)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(sForcedMovementTestFuncs); i++)
    {
        if (sForcedMovementTestFuncs[i](metatileBehavior))
            sForcedMovementFuncs[i + 1]();
    }
}

// wheelie idle
void PlayerIdleWheelie(enum Direction direction)
{
    PlayerSetAnimId(GetAcroWheelieFaceDirectionMovementAction(direction), COPY_MOVE_FACE);
}

// normal to wheelie
void PlayerStartWheelie(enum Direction direction)
{
    PlayerSetAnimId(GetAcroPopWheelieFaceDirectionMovementAction(direction), COPY_MOVE_FACE);
}

// wheelie to normal
void PlayerEndWheelie(enum Direction direction)
{
    PlayerSetAnimId(GetAcroEndWheelieFaceDirectionMovementAction(direction), COPY_MOVE_FACE);
}

// wheelie hopping standing
void PlayerStandingHoppingWheelie(enum Direction direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(GetAcroWheelieHopFaceDirectionMovementAction(direction), COPY_MOVE_FACE);
}

// wheelie hopping moving
void PlayerMovingHoppingWheelie(enum Direction direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(GetAcroWheelieHopDirectionMovementAction(direction), COPY_MOVE_WALK);
}

// wheelie hopping ledge
void PlayerLedgeHoppingWheelie(enum Direction direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(GetAcroWheelieJumpDirectionMovementAction(direction), COPY_MOVE_JUMP2);
}

// acro turn jump
void PlayerAcroTurnJump(enum Direction direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(GetJumpInPlaceTurnAroundMovementAction(direction), COPY_MOVE_FACE);
}

void PlayerWheelieInPlace(enum Direction direction)
{
    PlaySE(SE_WALL_HIT);
    PlayerSetAnimId(GetAcroWheelieInPlaceDirectionMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerPopWheelieWhileMoving(enum Direction direction)
{
    PlayerSetAnimId(GetAcroPopWheelieMoveDirectionMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerWheelieMove(enum Direction direction)
{
    PlayerSetAnimId(GetAcroWheelieMoveDirectionMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerEndWheelieWhileMoving(enum Direction direction)
{
    PlayerSetAnimId(GetAcroEndWheelieMoveDirectionMovementAction(direction), COPY_MOVE_WALK);
}

static void PlayCollisionSoundIfNotFacingWarp(enum Direction direction)
{
    s16 x, y;
    u8 metatileBehavior = gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior;

    if (!sArrowWarpMetatileBehaviorChecks[direction - 1](metatileBehavior))
    {
        // Check if walking up into a door
        if (direction == DIR_NORTH)
        {
            PlayerGetDestCoords(&x, &y);
            MoveCoords(direction, &x, &y);
            if (MetatileBehavior_IsWarpDoor(MapGridGetMetatileBehaviorAt(x, y)))
                return;
        }
        PlaySE(SE_WALL_HIT);
    }
}

void GetXYCoordsOneStepInFrontOfPlayer(s16 *x, s16 *y)
{
    *x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    *y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    MoveCoords(GetPlayerFacingDirection(), x, y);
}

void PlayerGetDestCoords(s16 *x, s16 *y)
{
    *x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    *y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
}

u8 player_get_pos_including_state_based_drift(s16 *x, s16 *y)
{
    struct ObjectEvent *object = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (object->heldMovementActive && !object->heldMovementFinished && !gSprites[object->spriteId].data[2])
    {
        *x = object->currentCoords.x;
        *y = object->currentCoords.y;

        switch (object->movementActionId)
        {
        case MOVEMENT_ACTION_WALK_NORMAL_DOWN:
        case MOVEMENT_ACTION_PLAYER_RUN_DOWN:
            (*y)++;
            return TRUE;
        case MOVEMENT_ACTION_WALK_NORMAL_UP:
        case MOVEMENT_ACTION_PLAYER_RUN_UP:
            (*y)--;
            return TRUE;
        case MOVEMENT_ACTION_WALK_NORMAL_LEFT:
        case MOVEMENT_ACTION_PLAYER_RUN_LEFT:
            (*x)--;
            return TRUE;
        case MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
        case MOVEMENT_ACTION_PLAYER_RUN_RIGHT:
            (*x)++;
            return TRUE;
        }
    }

    *x = -1;
    *y = -1;
    return FALSE;
}

enum Direction GetPlayerFacingDirection(void)
{
    Script_RequestEffects(SCREFF_V1);

    return gObjectEvents[gPlayerAvatar.objectEventId].facingDirection;
}

enum Direction GetPlayerMovementDirection(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].movementDirection;
}

u8 PlayerGetElevation(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].previousElevation;
}

u8 TestPlayerAvatarFlags(u8 flag)
{
    return gPlayerAvatar.flags & flag;
}

u8 GetPlayerAvatarFlags(void)
{
    return gPlayerAvatar.flags;
}

u8 GetPlayerAvatarSpriteId(void)
{
    return gPlayerAvatar.spriteId;
}

void CancelPlayerForcedMovement(void)
{
    ForcedMovement_None();
}

void StopPlayerAvatar(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    npc_clear_strange_bits(playerObjEvent);
    SetObjectEventDirection(playerObjEvent, playerObjEvent->facingDirection);
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        Bike_HandleBumpySlopeJump();
        Bike_UpdateBikeCounterSpeed(0);
    }
}

u16 GetRivalAvatarGraphicsIdByStateIdAndGender(u8 state, enum Gender gender)
{
    if (IS_FRLG)
        return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gender);
    else
        return sRivalAvatarGfxIds[state][gender];
}

u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, enum Gender gender)
{
    return sPlayerAvatarGfxIds[state][gender];
}

u16 GetFRLGAvatarGraphicsIdByGender(enum Gender gender)
{
    return sFRLGAvatarGfxIds[gender];
}

u16 GetRSAvatarGraphicsIdByGender(enum Gender gender)
{
    return sRSAvatarGfxIds[gender];
}

u16 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
    return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar.gender);
}

enum Gender GetPlayerAvatarGenderByGraphicsId(u16 gfxId)
{
    switch (gfxId)
    {
    case OBJ_EVENT_GFX_MAY_NORMAL:
    case OBJ_EVENT_GFX_MAY_MACH_BIKE:
    case OBJ_EVENT_GFX_MAY_ACRO_BIKE:
    case OBJ_EVENT_GFX_MAY_SURFING:
    case OBJ_EVENT_GFX_MAY_FIELD_MOVE:
    case OBJ_EVENT_GFX_MAY_UNDERWATER:
    case OBJ_EVENT_GFX_MAY_FISHING:
    case OBJ_EVENT_GFX_MAY_WATERING:
    case OBJ_EVENT_GFX_GREEN_NORMAL:
    case OBJ_EVENT_GFX_GREEN_BIKE:
    case OBJ_EVENT_GFX_GREEN_SURF:
    case OBJ_EVENT_GFX_GREEN_FIELD_MOVE:
    case OBJ_EVENT_GFX_GREEN_FISH:
    case OBJ_EVENT_GFX_GREEN_VS_SEEKER:
    case OBJ_EVENT_GFX_GREEN_VS_SEEKER_BIKE:
        return FEMALE;
    default:
        return MALE;
    }
}

bool8 PartyHasMonWithSurf(void)
{
    u8 i;

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == SPECIES_NONE)
                break;
            if (MonKnowsMove(&gParties[B_TRAINER_PLAYER][i], MOVE_SURF))
                return TRUE;
        }
    }
    return FALSE;
}

bool8 IsPlayerSurfingNorth(void)
{
    if (GetPlayerMovementDirection() == DIR_NORTH && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        return TRUE;
    else
        return FALSE;
}

bool8 IsPlayerFacingSurfableFishableWater(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    MoveCoords(playerObjEvent->facingDirection, &x, &y);
    if (GetCollisionAtCoords(playerObjEvent, x, y, playerObjEvent->facingDirection) == COLLISION_ELEVATION_MISMATCH
     && PlayerGetElevation() == ELEVATION_DEFAULT
     && MetatileBehavior_IsSurfableFishableWater(MapGridGetMetatileBehaviorAt(x, y)))
        return TRUE;
    else
        return FALSE;
}

void ClearPlayerAvatarInfo(void)
{
    memset(&gPlayerAvatar, 0, sizeof(struct PlayerAvatar));
}

void SetPlayerAvatarStateMask(u8 flags)
{
    gPlayerAvatar.flags &= (PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_FORCED_MOVE | PLAYER_AVATAR_FLAG_CONTROLLABLE);
    gPlayerAvatar.flags |= flags;
}

static u8 GetPlayerAvatarStateTransitionByGraphicsId(u16 graphicsId, u8 gender)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sPlayerAvatarGfxToStateFlag[0]); i++)
    {
        if (sPlayerAvatarGfxToStateFlag[gender][i].graphicsId == graphicsId)
            return sPlayerAvatarGfxToStateFlag[gender][i].playerFlag;
    }
    return PLAYER_AVATAR_FLAG_ON_FOOT;
}

u16 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
    u8 i;
    u8 flags = gPlayerAvatar.flags;

    for (i = 0; i < ARRAY_COUNT(sPlayerAvatarGfxToStateFlag[0]); i++)
    {
        if (sPlayerAvatarGfxToStateFlag[gPlayerAvatar.gender][i].playerFlag & flags)
            return sPlayerAvatarGfxToStateFlag[gPlayerAvatar.gender][i].graphicsId;
    }
    return 0;
}

void SetPlayerAvatarExtraStateTransition(u16 graphicsId, u8 transitionFlag)
{
    u8 stateFlag = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar.gender);

    gPlayerAvatar.transitionFlags |= stateFlag | transitionFlag;
    DoPlayerAvatarTransition();
}

void InitPlayerAvatar(s16 x, s16 y, enum Direction direction, enum Gender gender)
{
    struct ObjectEventTemplate playerObjEventTemplate;
    u8 objectEventId;
    struct ObjectEvent *objectEvent;

    playerObjEventTemplate.localId = LOCALID_PLAYER;
    playerObjEventTemplate.graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);
    playerObjEventTemplate.x = x - MAP_OFFSET;
    playerObjEventTemplate.y = y - MAP_OFFSET;
    playerObjEventTemplate.elevation = ELEVATION_TRANSITION;
    playerObjEventTemplate.movementType = MOVEMENT_TYPE_PLAYER;
    playerObjEventTemplate.movementRangeX = 0;
    playerObjEventTemplate.movementRangeY = 0;
    playerObjEventTemplate.trainerType = TRAINER_TYPE_NONE;
    playerObjEventTemplate.trainerRange_berryTreeId = 0;
    playerObjEventTemplate.script = NULL;
    playerObjEventTemplate.flagId = 0;
    objectEventId = SpawnSpecialObjectEvent(&playerObjEventTemplate);
    objectEvent = &gObjectEvents[objectEventId];
    objectEvent->isPlayer = TRUE;
    objectEvent->warpArrowSpriteId = CreateWarpArrowSprite();
    ObjectEventTurn(objectEvent, direction);
    ClearPlayerAvatarInfo();
    gPlayerAvatar.runningState = NOT_MOVING;
    gPlayerAvatar.tileTransitionState = T_NOT_MOVING;
    gPlayerAvatar.objectEventId = objectEventId;
    gPlayerAvatar.spriteId = objectEvent->spriteId;
    gPlayerAvatar.gender = gender;
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_CONTROLLABLE | PLAYER_AVATAR_FLAG_ON_FOOT);
    CreateFollowerNPCAvatar();
}

void SetPlayerInvisibility(bool8 invisible)
{
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = invisible;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        gSprites[gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId].invisible = invisible;
}

void SetPlayerAvatarFieldMove(void)
{
    EndORASDowsing();
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_FIELD_MOVE));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], ANIM_FIELD_MOVE);
}

void SetPlayerAvatarFishing(enum Direction direction)
{
    EndORASDowsing();
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_FISHING));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingDirectionAnimNum(direction));
}

void PlayerUseAcroBikeOnBumpySlope(enum Direction direction)
{
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_ACRO_BIKE));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetAcroWheelieDirectionAnimNum(direction));
    SeekSpriteAnim(&gSprites[gPlayerAvatar.spriteId], 1);
}

void SetPlayerAvatarWatering(enum Direction direction)
{
    EndORASDowsing();
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_WATERING));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFaceDirectionAnimNum(direction));
}

static void HideShowWarpArrow(struct ObjectEvent *objectEvent)
{
    s16 x;
    s16 y;
    enum Direction direction;
    u8 metatileBehavior = objectEvent->currentMetatileBehavior;

    for (x = 0, direction = DIR_SOUTH; x < 4; x++, direction++)
    {
        if (sArrowWarpMetatileBehaviorChecks2[x](metatileBehavior) && direction == objectEvent->movementDirection)
        {
            // Show warp arrow if applicable
            x = objectEvent->currentCoords.x;
            y = objectEvent->currentCoords.y;
            MoveCoords(direction, &x, &y);
            ShowWarpArrowSprite(objectEvent->warpArrowSpriteId, direction, x, y);
            return;
        }
    }
    SetSpriteInvisible(objectEvent->warpArrowSpriteId);
}

/* Strength */

#define tState        data[0]
#define tBoulderObjId data[1]
#define tDirection    data[2]

static void StartStrengthAnim(u8 objectEventId, enum Direction direction)
{
    u8 taskId = CreateTask(Task_PushBoulder, 0xFF);

    gTasks[taskId].tBoulderObjId = objectEventId;
    gTasks[taskId].tDirection = direction;
    Task_PushBoulder(taskId);
}

static void Task_PushBoulder(u8 taskId)
{
    while (sPushBoulderFuncs[gTasks[taskId].tState](&gTasks[taskId],
                                                     &gObjectEvents[gPlayerAvatar.objectEventId],
                                                     &gObjectEvents[gTasks[taskId].tBoulderObjId]))
        ;
}

static bool8 PushBoulder_Start(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tState++;
    return FALSE;
}

static bool8 PushBoulder_Move(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder)
{
    if (ObjectEventIsHeldMovementActive(player))
        ObjectEventClearHeldMovementIfFinished(player);

    if (ObjectEventIsHeldMovementActive(boulder))
        ObjectEventClearHeldMovementIfFinished(boulder);

    if (!ObjectEventIsMovementOverridden(player)
     && !ObjectEventIsMovementOverridden(boulder))
    {
        ObjectEventClearHeldMovementIfFinished(player);
        ObjectEventClearHeldMovementIfFinished(boulder);
        ObjectEventSetHeldMovement(player, GetWalkInPlaceNormalMovementAction((u8)task->tDirection));
        ObjectEventSetHeldMovement(boulder, GetWalkSlowMovementAction((u8)task->tDirection));
        gFieldEffectArguments[0] = boulder->currentCoords.x;
        gFieldEffectArguments[1] = boulder->currentCoords.y;
        gFieldEffectArguments[2] = boulder->previousElevation;
        gFieldEffectArguments[3] = gSprites[boulder->spriteId].oam.priority;
        FieldEffectStart(FLDEFF_DUST);
        PlaySE(SE_M_STRENGTH);
        task->tState++;
    }
    return FALSE;
}

static bool8 PushBoulder_End(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder)
{
    if (ObjectEventCheckHeldMovementStatus(player)
     && ObjectEventCheckHeldMovementStatus(boulder))
    {
        ObjectEventClearHeldMovementIfFinished(player);
        ObjectEventClearHeldMovementIfFinished(boulder);
        HandleBoulderFallThroughHole(boulder);
        HandleBoulderActivateVictoryRoadSwitch(boulder->currentCoords.x, boulder->currentCoords.y);
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        DestroyTask(FindTaskIdByFunc(Task_PushBoulder));
    }
    return FALSE;
}

#undef tState
#undef tBoulderObjId
#undef tDirection

/* Some field effect */

static void DoPlayerMatJump(void)
{
    DoPlayerAvatarSecretBaseMatJump(CreateTask(DoPlayerAvatarSecretBaseMatJump, 0xFF));
}

static void DoPlayerAvatarSecretBaseMatJump(u8 taskId)
{
    while (sPlayerAvatarSecretBaseMatJump[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]))
        ;
}

// because data[0] is used to call this, it can be inferred that there may have been multiple mat jump functions at one point, so the name for these groups of functions is appropriate in assuming the sole use of mat jump.
static u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *task, struct ObjectEvent *objectEvent)
{
    gPlayerAvatar.preventStep = TRUE;
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        PlaySE(SE_LEDGE);
        ObjectEventSetHeldMovement(objectEvent, GetJumpInPlaceMovementAction(objectEvent->facingDirection));
        task->data[1]++;
        if (task->data[1] > 1)
        {
            gPlayerAvatar.preventStep = FALSE;
            gPlayerAvatar.transitionFlags |= PLAYER_AVATAR_FLAG_CONTROLLABLE;
            DestroyTask(FindTaskIdByFunc(DoPlayerAvatarSecretBaseMatJump));
        }
    }
    return FALSE;
}

/* Some field effect */

static void DoPlayerMatSpin(void)
{
    u8 taskId = CreateTask(PlayerAvatar_DoSecretBaseMatSpin, 0xFF);

    PlayerAvatar_DoSecretBaseMatSpin(taskId);
}

static void PlayerAvatar_DoSecretBaseMatSpin(u8 taskId)
{
    while (sPlayerAvatarSecretBaseMatSpin[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]))
        ;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *task, struct ObjectEvent *objectEvent)
{
    task->data[0]++;
    task->data[1] = objectEvent->movementDirection;
    gPlayerAvatar.preventStep = TRUE;
    LockPlayerFieldControls();
    PlaySE(SE_WARP_IN);
    return TRUE;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *task, struct ObjectEvent *objectEvent)
{
    enum Direction directions[] = {DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        enum Direction direction;

        ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(direction = directions[objectEvent->movementDirection - 1]));
        if (direction == (u8)task->data[1])
            task->data[2]++;
        task->data[0]++;
        if (task->data[2] > 3 && direction == GetOppositeDirection(task->data[1]))
            task->data[0]++;
    }
    return FALSE;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *task, struct ObjectEvent *objectEvent)
{
    const u8 actions[] = {
        MOVEMENT_ACTION_DELAY_1,
        MOVEMENT_ACTION_DELAY_1,
        MOVEMENT_ACTION_DELAY_2,
        MOVEMENT_ACTION_DELAY_4,
        MOVEMENT_ACTION_DELAY_8,
    };

    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        ObjectEventSetHeldMovement(objectEvent, actions[task->data[2]]);
        task->data[0] = 1;
    }
    return FALSE;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *task, struct ObjectEvent *objectEvent)
{
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        ObjectEventSetHeldMovement(objectEvent, GetWalkSlowMovementAction(GetOppositeDirection(task->data[1])));
        UnlockPlayerFieldControls();
        gPlayerAvatar.preventStep = FALSE;
        DestroyTask(FindTaskIdByFunc(PlayerAvatar_DoSecretBaseMatSpin));
    }
    return FALSE;
}

void SeafoamIslandsB4F_CurrentDumpsPlayerOnLand(void)
{
    CreateStopSurfingTask(DIR_NORTH);
}

static void CreateStopSurfingTask(enum Direction direction)
{
    u8 taskId;

    LockPlayerFieldControls();
    Overworld_ClearSavedMusic();
    Overworld_ChangeMusicToDefault();
    gPlayerAvatar.flags ^= PLAYER_AVATAR_FLAG_SURFING;
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_ON_FOOT;
    gPlayerAvatar.preventStep = TRUE;
    taskId = CreateTask(Task_StopSurfingInit, 0xFF);
    gTasks[taskId].data[0] = direction;
    Task_StopSurfingInit(taskId);
    PrepareFollowerNPCDismountSurf();
}

static void Task_StopSurfingInit(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventIsMovementOverridden(playerObjEvent))
    {
        if (!ObjectEventClearHeldMovementIfFinished(playerObjEvent))
            return;
    }
    SetSurfBlob_BobState(playerObjEvent->fieldEffectSpriteId, BOB_JUST_MON);
    ObjectEventSetHeldMovement(playerObjEvent, GetJumpSpecialMovementAction((u8)gTasks[taskId].data[0]));
    gTasks[taskId].func = Task_WaitStopSurfing;
}

static void Task_WaitStopSurfing(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        ObjectEventSetGraphicsId(playerObjEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
        ObjectEventSetHeldMovement(playerObjEvent, GetFaceDirectionMovementAction(playerObjEvent->facingDirection));
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        DestroySprite(&gSprites[playerObjEvent->fieldEffectSpriteId]);
#ifdef BUGFIX
        // If this is not defined but the player steps into grass from surfing, they will appear over the grass instead of in the grass.
        playerObjEvent->triggerGroundEffectsOnMove = TRUE;
#endif
        DestroyTask(taskId);
    }
}

void SetSpinStartFacingDir(enum Direction direction)
{
    sSpinStartFacingDir = direction;
}

static enum Direction GetSpinStartFacingDir(void)
{
    if (sSpinStartFacingDir == DIR_NONE)
        return DIR_SOUTH;

    return sSpinStartFacingDir;
}

// Task data for Task_DoPlayerSpinEntrance and Task_DoPlayerSpinExit
#define tState          data[0]
#define tSpinDelayTimer data[1]
#define tSpeed          data[2]
#define tCurY           data[3]
#define tDestY          data[4]
#define tStartDir       data[5]
#define tPriority       data[6]
#define tSubpriority    data[7]
#define tGroundTimer    data[8]

static void Task_DoPlayerSpinExit(u8 taskId)
{
    struct ObjectEvent *object = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[object->spriteId];
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0: // Init
        if (!ObjectEventClearHeldMovementIfFinished(object))
            return;

        SetSpinStartFacingDir(object->facingDirection);
        tSpinDelayTimer = 0;
        tSpeed = 1;
        tCurY = (u16)(sprite->y + sprite->y2) << 4;
        sprite->y2 = 0;
        CameraObjectFreeze();
        object->fixedPriority = TRUE;
        sprite->oam.priority = 0;
        sprite->subpriority = 0;
        sprite->subspriteMode = SUBSPRITES_OFF;
        tState++;
    case 1: // Spin while rising
        TrySpinPlayerForWarp(object, &tSpinDelayTimer);

        // Rise and accelerate
        tCurY -= tSpeed;
        tSpeed += 3;
        sprite->y = tCurY >> 4;

        // Check if offscreen
        if (sprite->y + (s16)gTotalCameraPixelOffsetY < -32)
            tState++;
        break;
    case 2:
        DestroyTask(taskId);
        break;
    }
}

static void Task_DoPlayerSpinEntrance(u8 taskId);

void DoPlayerSpinEntrance(void)
{
    Task_DoPlayerSpinEntrance(CreateTask(Task_DoPlayerSpinEntrance, 0));
}

bool32 IsPlayerSpinEntranceActive(void)
{
    return FuncIsActiveTask(Task_DoPlayerSpinEntrance);
}

void DoPlayerSpinExit(void)
{
    Task_DoPlayerSpinExit(CreateTask(Task_DoPlayerSpinExit, 0));
}

bool32 IsPlayerSpinExitActive(void)
{
    return FuncIsActiveTask(Task_DoPlayerSpinExit);
}

static const enum Direction sSpinDirections[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

static void Task_DoPlayerSpinEntrance(u8 taskId)
{
    struct ObjectEvent *object = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[object->spriteId];
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        // Because the spin start facing direction is never set for this
        // warp type, the player will always exit the warp facing South.
        // This may have been intentional, unclear
        tStartDir = GetSpinStartFacingDir();
        ObjectEventForceSetHeldMovement(object, GetFaceDirectionMovementAction(sSpinDirections[tStartDir]));
        tSpinDelayTimer = 0;
        tSpeed = 116;
        tDestY = sprite->y;
        tPriority = sprite->oam.priority;
        tSubpriority = sprite->subpriority;
        tCurY = -((u16)sprite->y2 + 32) * 16;
        sprite->y2 = 0;
        CameraObjectFreeze();
        object->fixedPriority = TRUE;
        sprite->oam.priority = 1;
        sprite->subpriority = 0;
        sprite->subspriteMode = SUBSPRITES_OFF;
        tState++;
    case 1: // Spin while descending
        TrySpinPlayerForWarp(object, &tSpinDelayTimer);

        // Fall and decelerate
        tCurY += tSpeed;
        tSpeed -= 3;
        if (tSpeed < 4)
            tSpeed = 4;
        sprite->y = tCurY >> 4;

        // Check if reached dest
        if (sprite->y >= tDestY)
        {
            sprite->y = tDestY;
            tGroundTimer = 0;
            tState++;
        }
        break;
    case 2: // Spin on ground
        TrySpinPlayerForWarp(object, &tSpinDelayTimer);
        if (++tGroundTimer > 8)
            tState++;
        break;
    case 3: // Spin until facing original direction
        if (tStartDir == TrySpinPlayerForWarp(object, &tSpinDelayTimer))
        {
            object->fixedPriority = 0;
            sprite->oam.priority = tPriority;
            sprite->subpriority = tSubpriority;
            CameraObjectReset();
            DestroyTask(taskId);
        }
        break;
    }
}

static u8 TrySpinPlayerForWarp(struct ObjectEvent *object, s16 *delayTimer)
{
    if (*delayTimer < 8 && ++(*delayTimer) < 8)
        return object->facingDirection;

    if (!ObjectEventCheckHeldMovementStatus(object))
        return object->facingDirection;

    ObjectEventForceSetHeldMovement(object, GetFaceDirectionMovementAction(sSpinDirections[object->facingDirection]));
    *delayTimer = 0;
    return sSpinDirections[object->facingDirection];
}

//sideways stairs
enum Direction GetRightSideStairsDirection(enum Direction direction)
{
    switch (direction)
    {
    case DIR_WEST:
        return DIR_NORTHWEST;
    case DIR_EAST:
        return DIR_SOUTHEAST;
    default:
        if (direction > DIR_EAST)
            direction -= DIR_EAST;
        return direction;
    }
}

enum Direction GetLeftSideStairsDirection(enum Direction direction)
{
    switch (direction)
    {
    case DIR_WEST:
        return DIR_SOUTHWEST;
    case DIR_EAST:
        return DIR_NORTHEAST;
    default:
        if (direction > DIR_EAST)
            direction -= DIR_EAST;
        return direction;
    }
}

bool8 ObjectMovingOnRockStairs(struct ObjectEvent *objectEvent, enum Direction direction)
{
    #if SLOW_MOVEMENT_ON_STAIRS == TRUE
        s16 x = objectEvent->currentCoords.x;
        s16 y = objectEvent->currentCoords.y;

        if (IsFollowerVisible() && GetFollowerObject() != NULL && (objectEvent->isPlayer || objectEvent->localId == OBJ_EVENT_ID_FOLLOWER))
            return FALSE;

        switch (direction)
        {
        case DIR_NORTH:
            return MetatileBehavior_IsRockStairs(MapGridGetMetatileBehaviorAt(x,y));
        case DIR_SOUTH:
            MoveCoords(DIR_SOUTH, &x, &y);
            return MetatileBehavior_IsRockStairs(MapGridGetMetatileBehaviorAt(x,y));
        case DIR_WEST:
        case DIR_EAST:
        case DIR_NORTHEAST:
        case DIR_NORTHWEST:
        case DIR_SOUTHWEST:
        case DIR_SOUTHEAST:
            // directionOverwrite is only used for sideways stairs motion
            if (objectEvent->directionOverwrite)
                return TRUE;
        default:
            return FALSE;
        }
    #else
        return FALSE;
    #endif
}
