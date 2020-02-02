#include "global.h"
#include "main.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "random.h"
#include "rotating_gate.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "tv.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"

static EWRAM_DATA u8 gUnknown_0203734C = 0;
EWRAM_DATA struct EventObject gEventObjects[EVENT_OBJECTS_COUNT] = {};
EWRAM_DATA struct PlayerAvatar gPlayerAvatar = {};

// static declarations

static u8 EventObjectCB2_NoMovement2();
static bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *, u8);
static void npc_clear_strange_bits(struct EventObject *);
static void MovePlayerAvatarUsingKeypadInput(u8, u16, u16);
static void PlayerAllowForcedMovementIfMovingSameDirection();
static bool8 TryDoMetatileBehaviorForcedMovement();
static u8 GetForcedMovementByMetatileBehavior();

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
static bool8 ForcedMovement_0xBB(void);
static bool8 ForcedMovement_0xBC(void);
static bool8 ForcedMovement_MuddySlope(void);

static void MovePlayerNotOnBike(u8, u16);
static u8 CheckMovementInputNotOnBike(u8);
static void PlayerNotOnBikeNotMoving(u8, u16);
static void PlayerNotOnBikeTurningInPlace(u8, u16);
static void PlayerNotOnBikeMoving(u8, u16);
static u8 CheckForPlayerAvatarCollision(u8);
static u8 sub_808B028(u8);
static u8 sub_808B164(struct EventObject *, s16, s16, u8, u8);
static bool8 CanStopSurfing(s16, s16, u8);
static bool8 ShouldJumpLedge(s16, s16, u8);
static bool8 TryPushBoulder(s16, s16, u8);
static void CheckAcroBikeCollision(s16, s16, u8, u8 *);

static void DoPlayerAvatarTransition(void);
static void PlayerAvatarTransition_Dummy(struct EventObject *a);
static void PlayerAvatarTransition_Normal(struct EventObject *a);
static void PlayerAvatarTransition_MachBike(struct EventObject *a);
static void PlayerAvatarTransition_AcroBike(struct EventObject *a);
static void PlayerAvatarTransition_Surfing(struct EventObject *a);
static void PlayerAvatarTransition_Underwater(struct EventObject *a);
static void PlayerAvatarTransition_ReturnToField(struct EventObject *a);

static bool8 player_is_anim_in_certain_ranges(void);
static bool8 sub_808B618(void);
static bool8 PlayerIsAnimActive(void);
static bool8 PlayerCheckIfAnimFinishedOrInactive(void);

static void PlayerRun(u8);
static void PlayerNotOnBikeCollide(u8);
static void PlayerNotOnBikeCollideWithFarawayIslandMew(u8);

static void PlayCollisionSoundIfNotFacingWarp(u8 a);

static void sub_808C280(struct EventObject *);

static void StartStrengthAnim(u8, u8);
static void Task_BumpBoulder(u8 taskId);
static u8 sub_808C3A4(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject);
static u8 do_boulder_dust(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject);
static u8 sub_808C484(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject);

static void DoPlayerMatJump(void);
static void DoPlayerAvatarSecretBaseMatJump(u8 taskId);
static u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *task, struct EventObject *eventObject);

static void DoPlayerMatSpin(void);
static void PlayerAvatar_DoSecretBaseMatSpin(u8 taskId);
static bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *task, struct EventObject *eventObject);
static bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *task, struct EventObject *eventObject);
static bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *task, struct EventObject *eventObject);
static bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *task, struct EventObject *eventObject);

static void CreateStopSurfingTask(u8);
static void Task_StopSurfingInit(u8 taskId);
static void Task_WaitStopSurfing(u8 taskId);

static void Task_Fishing(u8 taskId);
static u8 Fishing1(struct Task *task);
static u8 Fishing2(struct Task *task);
static u8 Fishing3(struct Task *task);
static u8 Fishing4(struct Task *task);
static u8 Fishing5(struct Task *task);
static u8 Fishing6(struct Task *task);
static u8 Fishing7(struct Task *task);
static u8 Fishing8(struct Task *task);
static u8 Fishing9(struct Task *task);
static u8 Fishing10(struct Task *task);
static u8 Fishing11(struct Task *task);
static u8 Fishing12(struct Task *task);
static u8 Fishing13(struct Task *task);
static u8 Fishing14(struct Task *task);
static u8 Fishing15(struct Task *task);
static u8 Fishing16(struct Task *task);
static void AlignFishingAnimationFrames(void);

static u8 sub_808D38C(struct EventObject *object, s16 *a1);

// .rodata

static bool8 (*const sForcedMovementTestFuncs[])(u8) =
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
};

static bool8 (*const sForcedMovementFuncs[])(void) =
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
    ForcedMovement_0xBB,
    ForcedMovement_0xBC,
    ForcedMovement_MuddySlope,
};

static void (*const gUnknown_08497490[])(u8, u16) =
{
    PlayerNotOnBikeNotMoving,
    PlayerNotOnBikeTurningInPlace,
    PlayerNotOnBikeMoving,
};

static bool8 (*const sAcroBikeTrickMetatiles[])(u8) =
{
    MetatileBehavior_IsBumpySlope,
    MetatileBehavior_IsIsolatedVerticalRail,
    MetatileBehavior_IsIsolatedHorizontalRail,
    MetatileBehavior_IsVerticalRail,
    MetatileBehavior_IsHorizontalRail,
};

static const u8 sAcroBikeTrickCollisionTypes[] = {
    COLLISION_WHEELIE_HOP,
    COLLISION_ISOLATED_VERTICAL_RAIL,
    COLLISION_ISOLATED_HORIZONTAL_RAIL,
    COLLISION_VERTICAL_RAIL,
    COLLISION_HORIZONTAL_RAIL,
};

static void (*const gUnknown_084974B8[])(struct EventObject *) =
{
    PlayerAvatarTransition_Normal,
    PlayerAvatarTransition_MachBike,
    PlayerAvatarTransition_AcroBike,
    PlayerAvatarTransition_Surfing,
    PlayerAvatarTransition_Underwater,
    PlayerAvatarTransition_ReturnToField,
    PlayerAvatarTransition_Dummy,
    PlayerAvatarTransition_Dummy,
};

static bool8 (*const sArrowWarpMetatileBehaviorChecks[])(u8) =
{
    MetatileBehavior_IsSouthArrowWarp,
    MetatileBehavior_IsNorthArrowWarp,
    MetatileBehavior_IsWestArrowWarp,
    MetatileBehavior_IsEastArrowWarp,
};

static const u8 sRivalAvatarGfxIds[][2] =
{
    {EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL,     EVENT_OBJ_GFX_RIVAL_MAY_NORMAL},
    {EVENT_OBJ_GFX_RIVAL_BRENDAN_MACH_BIKE,  EVENT_OBJ_GFX_RIVAL_MAY_MACH_BIKE},
    {EVENT_OBJ_GFX_RIVAL_BRENDAN_ACRO_BIKE,  EVENT_OBJ_GFX_RIVAL_MAY_ACRO_BIKE},
    {EVENT_OBJ_GFX_RIVAL_BRENDAN_SURFING,    EVENT_OBJ_GFX_RIVAL_MAY_SURFING},
    {EVENT_OBJ_GFX_BRENDAN_UNDERWATER,       EVENT_OBJ_GFX_MAY_UNDERWATER},
    {EVENT_OBJ_GFX_RIVAL_BRENDAN_FIELD_MOVE, EVENT_OBJ_GFX_RIVAL_MAY_FIELD_MOVE},
    {EVENT_OBJ_GFX_BRENDAN_FISHING,          EVENT_OBJ_GFX_MAY_FISHING},
    {EVENT_OBJ_GFX_BRENDAN_WATERING,         EVENT_OBJ_GFX_MAY_WATERING}
};

static const u8 sPlayerAvatarGfxIds[][2] =
{
    {EVENT_OBJ_GFX_BRENDAN_NORMAL,     EVENT_OBJ_GFX_MAY_NORMAL},
    {EVENT_OBJ_GFX_BRENDAN_MACH_BIKE,  EVENT_OBJ_GFX_MAY_MACH_BIKE},
    {EVENT_OBJ_GFX_BRENDAN_ACRO_BIKE,  EVENT_OBJ_GFX_MAY_ACRO_BIKE},
    {EVENT_OBJ_GFX_BRENDAN_SURFING,    EVENT_OBJ_GFX_MAY_SURFING},
    {EVENT_OBJ_GFX_BRENDAN_UNDERWATER, EVENT_OBJ_GFX_MAY_UNDERWATER},
    {EVENT_OBJ_GFX_BRENDAN_FIELD_MOVE, EVENT_OBJ_GFX_MAY_FIELD_MOVE},
    {EVENT_OBJ_GFX_BRENDAN_FISHING,    EVENT_OBJ_GFX_MAY_FISHING},
    {EVENT_OBJ_GFX_BRENDAN_WATERING,   EVENT_OBJ_GFX_MAY_WATERING},
};

static const u8 sFRLGAvatarGfxIds[] = {EVENT_OBJ_GFX_RED, EVENT_OBJ_GFX_LEAF};

static const u8 sRSAvatarGfxIds[] = {EVENT_OBJ_GFX_LINK_RS_BRENDAN, EVENT_OBJ_GFX_LINK_RS_MAY};

static const u8 gUnknown_0849750C[2][5][2] =
{
    //male
    {
        {EVENT_OBJ_GFX_BRENDAN_NORMAL, 1},
        {EVENT_OBJ_GFX_BRENDAN_MACH_BIKE, 2},
        {EVENT_OBJ_GFX_BRENDAN_ACRO_BIKE, 4},
        {EVENT_OBJ_GFX_BRENDAN_SURFING, 8},
        {EVENT_OBJ_GFX_BRENDAN_UNDERWATER, 16},
    },
    //female
    {
        {EVENT_OBJ_GFX_MAY_NORMAL, 1},
        {EVENT_OBJ_GFX_MAY_MACH_BIKE, 2},
        {EVENT_OBJ_GFX_MAY_ACRO_BIKE, 4},
        {EVENT_OBJ_GFX_MAY_SURFING, 8},
        {EVENT_OBJ_GFX_MAY_UNDERWATER, 16},
    }
};

static bool8 (*const sArrowWarpMetatileBehaviorChecks2[])(u8) =  //Duplicate of sArrowWarpMetatileBehaviorChecks
{
    MetatileBehavior_IsSouthArrowWarp,
    MetatileBehavior_IsNorthArrowWarp,
    MetatileBehavior_IsWestArrowWarp,
    MetatileBehavior_IsEastArrowWarp,
};

static bool8 (*const gUnknown_08497530[])(struct Task *, struct EventObject *, struct EventObject *) =
{
    sub_808C3A4,
    do_boulder_dust,
    sub_808C484,
};

static bool8 (*const sPlayerAvatarSecretBaseMatJump[])(struct Task *, struct EventObject *) =
{
    PlayerAvatar_DoSecretBaseMatJump,
};

static bool8 (*const sPlayerAvatarSecretBaseMatSpin[])(struct Task *, struct EventObject *) =
{
    PlayerAvatar_SecretBaseMatSpinStep0,
    PlayerAvatar_SecretBaseMatSpinStep1,
    PlayerAvatar_SecretBaseMatSpinStep2,
    PlayerAvatar_SecretBaseMatSpinStep3,
};

// .text

void MovementType_Player(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, EventObjectCB2_NoMovement2);
}

static u8 EventObjectCB2_NoMovement2(void)
{
    return 0;
}

void player_step(u8 direction, u16 newKeys, u16 heldKeys)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    sub_808C280(playerEventObj);
    if (gPlayerAvatar.preventStep == FALSE)
    {
        Bike_TryAcroBikeHistoryUpdate(newKeys, heldKeys);
        if (TryInterruptEventObjectSpecialAnim(playerEventObj, direction) == 0)
        {
            npc_clear_strange_bits(playerEventObj);
            DoPlayerAvatarTransition();
            if (TryDoMetatileBehaviorForcedMovement() == 0)
            {
                MovePlayerAvatarUsingKeypadInput(direction, newKeys, heldKeys);
                PlayerAllowForcedMovementIfMovingSameDirection();
            }
        }
    }
}

static bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *playerEventObj, u8 direction)
{
    u8 r5 = direction;
    u8 r6 = direction;
    r6++; r6--;

    if (EventObjectIsMovementOverridden(playerEventObj)
     && !EventObjectClearHeldMovementIfFinished(playerEventObj))
    {
        u8 heldMovementActionId = EventObjectGetHeldMovementActionId(playerEventObj);
        if (heldMovementActionId > MOVEMENT_ACTION_WALK_FAST_RIGHT && heldMovementActionId < MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN)
        {
            if (direction == DIR_NONE)
            {
                return TRUE;
            }

            if (playerEventObj->movementDirection != r5)
            {
                EventObjectClearHeldMovement(playerEventObj);
                return FALSE;
            }

            if (!sub_808B028(r6))
            {
                EventObjectClearHeldMovement(playerEventObj);
                return FALSE;
            }
        }

        return TRUE;
    }

    return FALSE;
}

static void npc_clear_strange_bits(struct EventObject *eventObj)
{
    eventObj->inanimate = 0;
    eventObj->disableAnim = 0;
    eventObj->facingDirectionLocked = 0;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_DASH;
}

static void MovePlayerAvatarUsingKeypadInput(u8 direction, u16 newKeys, u16 heldKeys)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
     || (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE))
        MovePlayerOnBike(direction, newKeys, heldKeys);
    else
        MovePlayerNotOnBike(direction, heldKeys);
}

static void PlayerAllowForcedMovementIfMovingSameDirection(void)
{
    if (gPlayerAvatar.runningState == MOVING)
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_5;
}

static bool8 TryDoMetatileBehaviorForcedMovement(void)
{
    return sForcedMovementFuncs[GetForcedMovementByMetatileBehavior()]();
}

static u8 GetForcedMovementByMetatileBehavior(void)
{
    u8 i;

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_5))
    {
        u8 metatileBehavior = gEventObjects[gPlayerAvatar.eventObjectId].currentMetatileBehavior;

        for (i = 0; i < 18; i++)
        {
            if (sForcedMovementTestFuncs[i](metatileBehavior))
                return i + 1;
        }
    }
    return 0;
}

static bool8 ForcedMovement_None(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_6)
    {
        struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

        playerEventObj->facingDirectionLocked = 0;
        playerEventObj->enableAnim = 1;
        SetEventObjectDirection(playerEventObj, playerEventObj->facingDirection);
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_6;
    }
    return FALSE;
}

static u8 DoForcedMovement(u8 direction, void (*b)(u8))
{
    struct PlayerAvatar *playerAvatar = &gPlayerAvatar;
    u8 collision = CheckForPlayerAvatarCollision(direction);

    playerAvatar->flags |= PLAYER_AVATAR_FLAG_6;
    if (collision)
    {
        ForcedMovement_None();
        if (collision < COLLISION_STOP_SURFING)
        {
            return 0;
        }
        else
        {
            if (collision == COLLISION_LEDGE_JUMP)
                PlayerJumpLedge(direction);
            playerAvatar->flags |= PLAYER_AVATAR_FLAG_6;
            playerAvatar->runningState = MOVING;
            return 1;
        }
    }
    else
    {
        playerAvatar->runningState = MOVING;
        b(direction);
        return 1;
    }
}

static u8 DoForcedMovementInCurrentDirection(void (*a)(u8))
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    playerEventObj->disableAnim = 1;
    return DoForcedMovement(playerEventObj->movementDirection, a);
}

static bool8 ForcedMovement_Slip(void)
{
    return DoForcedMovementInCurrentDirection(PlayerGoSpeed2);
}

static bool8 ForcedMovement_WalkSouth(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerGoSpeed1);
}

static bool8 ForcedMovement_WalkNorth(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerGoSpeed1);
}

static bool8 ForcedMovement_WalkWest(void)
{
    return DoForcedMovement(DIR_WEST, PlayerGoSpeed1);
}

static bool8 ForcedMovement_WalkEast(void)
{
    return DoForcedMovement(DIR_EAST, PlayerGoSpeed1);
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

u8 ForcedMovement_Slide(u8 direction, void (*b)(u8))
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    playerEventObj->disableAnim = 1;
    playerEventObj->facingDirectionLocked = 1;
    return DoForcedMovement(direction, b);
}

static bool8 ForcedMovement_SlideSouth(void)
{
    return ForcedMovement_Slide(DIR_SOUTH, PlayerGoSpeed2);
}

static bool8 ForcedMovement_SlideNorth(void)
{
    return ForcedMovement_Slide(DIR_NORTH, PlayerGoSpeed2);
}

static bool8 ForcedMovement_SlideWest(void)
{
    return ForcedMovement_Slide(DIR_WEST, PlayerGoSpeed2);
}

static bool8 ForcedMovement_SlideEast(void)
{
    return ForcedMovement_Slide(DIR_EAST, PlayerGoSpeed2);
}

static bool8 ForcedMovement_0xBB(void)
{
    DoPlayerMatJump();
    return TRUE;
}

static bool8 ForcedMovement_0xBC(void)
{
    DoPlayerMatSpin();
    return TRUE;
}

static bool8 ForcedMovement_MuddySlope(void)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    if (playerEventObj->movementDirection != DIR_NORTH || GetPlayerSpeed() <= 3)
    {
        Bike_UpdateBikeCounterSpeed(0);
        playerEventObj->facingDirectionLocked = 1;
        return DoForcedMovement(1, PlayerGoSpeed2);
    }
    else
    {
        return FALSE;
    }
}

static void MovePlayerNotOnBike(u8 direction, u16 heldKeys)
{
    gUnknown_08497490[CheckMovementInputNotOnBike(direction)](direction, heldKeys);
}

static u8 CheckMovementInputNotOnBike(u8 direction)
{
    if (direction == DIR_NONE)
    {
        gPlayerAvatar.runningState = NOT_MOVING;
        return 0;
    }
    else if (direction != GetPlayerMovementDirection() && gPlayerAvatar.runningState != MOVING)
    {
        gPlayerAvatar.runningState = TURN_DIRECTION;
        return 1;
    }
    else
    {
        gPlayerAvatar.runningState = MOVING;
        return 2;
    }
}

static void PlayerNotOnBikeNotMoving(u8 direction, u16 heldKeys)
{
    PlayerFaceDirection(GetPlayerFacingDirection());
}

static void PlayerNotOnBikeTurningInPlace(u8 direction, u16 heldKeys)
{
    PlayerTurnInPlace(direction);
}

static void PlayerNotOnBikeMoving(u8 direction, u16 heldKeys)
{
    u8 collision = CheckForPlayerAvatarCollision(direction);

    if (collision)
    {
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerJumpLedge(direction);
            return;
        }
        else if (collision == COLLISION_EVENT_OBJECT && IsPlayerCollidingWithFarawayIslandMew(direction))
        {
            PlayerNotOnBikeCollideWithFarawayIslandMew(direction);
            return;
        }
        else
        {
            u8 adjustedCollision = collision - COLLISION_STOP_SURFING;
            if (adjustedCollision > 3)
                PlayerNotOnBikeCollide(direction);
            return;
        }
    }

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
    {
    // speed 2 is fast, same speed as running
        PlayerGoSpeed2(direction);
        return;
    }

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_UNDERWATER) && (heldKeys & B_BUTTON) && FlagGet(FLAG_SYS_B_DASH)
     && IsRunningDisallowed(gEventObjects[gPlayerAvatar.eventObjectId].currentMetatileBehavior) == 0)
    {
        PlayerRun(direction);
        gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_DASH;
        return;
    }
    else
    {
        PlayerGoSpeed1(direction);
    }
}

static u8 CheckForPlayerAvatarCollision(u8 direction)
{
    s16 x, y;
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    x = playerEventObj->currentCoords.x;
    y = playerEventObj->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return CheckForEventObjectCollision(playerEventObj, x, y, direction, MapGridGetMetatileBehaviorAt(x, y));
}

static u8 sub_808B028(u8 direction)
{
    s16 x, y;
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    x = playerEventObj->currentCoords.x;
    y = playerEventObj->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return sub_808B164(playerEventObj, x, y, direction, MapGridGetMetatileBehaviorAt(x, y));
}

u8 CheckForEventObjectCollision(struct EventObject *eventObject, s16 x, s16 y, u8 direction, u8 metatileBehavior)
{
    u8 collision = GetCollisionAtCoords(eventObject, x, y, direction);
    if (collision == COLLISION_ELEVATION_MISMATCH && CanStopSurfing(x, y, direction))
        return COLLISION_STOP_SURFING;

    if (ShouldJumpLedge(x, y, direction))
    {
        IncrementGameStat(GAME_STAT_JUMPED_DOWN_LEDGES);
        return COLLISION_LEDGE_JUMP;
    }
    if (collision == COLLISION_EVENT_OBJECT && TryPushBoulder(x, y, direction))
        return COLLISION_PUSHED_BOULDER;

    if (collision == COLLISION_NONE)
    {
        if (CheckForRotatingGatePuzzleCollision(direction, x, y))
            return COLLISION_ROTATING_GATE;
        CheckAcroBikeCollision(x, y, metatileBehavior, &collision);
    }
    return collision;
}

static u8 sub_808B164(struct EventObject *eventObject, s16 x, s16 y, u8 direction, u8 metatileBehavior)
{
    u8 collision = GetCollisionAtCoords(eventObject, x, y, direction);

    if (collision == COLLISION_NONE)
    {
        if (CheckForRotatingGatePuzzleCollisionWithoutAnimation(direction, x, y))
            return COLLISION_ROTATING_GATE;
        CheckAcroBikeCollision(x, y, metatileBehavior, &collision);
    }
    return collision;
}

static bool8 CanStopSurfing(s16 x, s16 y, u8 direction)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
     && MapGridGetZCoordAt(x, y) == 3
     && GetEventObjectIdByXYZ(x, y, 3) == EVENT_OBJECTS_COUNT)
    {
        CreateStopSurfingTask(direction);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldJumpLedge(s16 x, s16 y, u8 z)
{
    if (GetLedgeJumpDirection(x, y, z) != 0)
        return TRUE;
    else
        return FALSE;
}

static bool8 TryPushBoulder(s16 x, s16 y, u8 direction)
{
    if (FlagGet(FLAG_SYS_USE_STRENGTH))
    {
        u8 eventObjectId = GetEventObjectIdByXY(x, y);

        if (eventObjectId != 16 && gEventObjects[eventObjectId].graphicsId == EVENT_OBJ_GFX_PUSHABLE_BOULDER)
        {
            x = gEventObjects[eventObjectId].currentCoords.x;
            y = gEventObjects[eventObjectId].currentCoords.y;
            MoveCoords(direction, &x, &y);
            if (GetCollisionAtCoords(&gEventObjects[eventObjectId], x, y, direction) == COLLISION_NONE
             && MetatileBehavior_IsNonAnimDoor(MapGridGetMetatileBehaviorAt(x, y)) == 0)
            {
                StartStrengthAnim(eventObjectId, direction);
                return TRUE;
            }
        }
    }
    return FALSE;
}

static void CheckAcroBikeCollision(s16 x, s16 y, u8 metatileBehavior, u8 *collision)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sAcroBikeTrickMetatiles); i++)
    {
        if (sAcroBikeTrickMetatiles[i](metatileBehavior))
        {
            *collision = sAcroBikeTrickCollisionTypes[i];
            return;
        }
    }
}

bool8 IsPlayerCollidingWithFarawayIslandMew(u8 direction)
{
    u8 mewObjectId;
    struct EventObject *object;
    s16 playerX;
    s16 playerY;
    s16 mewPrevX;

    object = &gEventObjects[gPlayerAvatar.eventObjectId];
    playerX = object->currentCoords.x;
    playerY = object->currentCoords.y;

    MoveCoords(direction, &playerX, &playerY);
    mewObjectId = GetEventObjectIdByLocalIdAndMap(1, MAP_NUM(FARAWAY_ISLAND_INTERIOR), MAP_GROUP(FARAWAY_ISLAND_INTERIOR));
    if (mewObjectId == EVENT_OBJECTS_COUNT)
        return FALSE;

    object = &gEventObjects[mewObjectId];
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
    gPlayerAvatar.unk1 |= transitionFlags;
    DoPlayerAvatarTransition();
}

static void DoPlayerAvatarTransition(void)
{
    u8 i;
    u8 flags = gPlayerAvatar.unk1;

    if (flags != 0)
    {
        for (i = 0; i < 8; i++, flags >>= 1)
        {
            if (flags & 1)
                gUnknown_084974B8[i](&gEventObjects[gPlayerAvatar.eventObjectId]);
        }
        gPlayerAvatar.unk1 = 0;
    }
}

static void PlayerAvatarTransition_Dummy(struct EventObject *eventObj)
{

}

static void PlayerAvatarTransition_Normal(struct EventObject *eventObj)
{
    EventObjectSetGraphicsId(eventObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    EventObjectTurn(eventObj, eventObj->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ON_FOOT);
}

static void PlayerAvatarTransition_MachBike(struct EventObject *eventObj)
{
    EventObjectSetGraphicsId(eventObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_MACH_BIKE));
    EventObjectTurn(eventObj, eventObj->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_MACH_BIKE);
    BikeClearState(0, 0);
}

static void PlayerAvatarTransition_AcroBike(struct EventObject *eventObj)
{
    EventObjectSetGraphicsId(eventObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_ACRO_BIKE));
    EventObjectTurn(eventObj, eventObj->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ACRO_BIKE);
    BikeClearState(0, 0);
    Bike_HandleBumpySlopeJump();
}

static void PlayerAvatarTransition_Surfing(struct EventObject *eventObj)
{
    u8 spriteId;

    EventObjectSetGraphicsId(eventObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_SURFING));
    EventObjectTurn(eventObj, eventObj->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_SURFING);
    gFieldEffectArguments[0] = eventObj->currentCoords.x;
    gFieldEffectArguments[1] = eventObj->currentCoords.y;
    gFieldEffectArguments[2] = gPlayerAvatar.eventObjectId;
    spriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    eventObj->fieldEffectSpriteId = spriteId;
    sub_81555AC(spriteId, 1);
}

static void PlayerAvatarTransition_Underwater(struct EventObject *eventObj)
{
    EventObjectSetGraphicsId(eventObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_UNDERWATER));
    EventObjectTurn(eventObj, eventObj->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_UNDERWATER);
    eventObj->fieldEffectSpriteId = sub_8155800(eventObj->spriteId);
}

static void PlayerAvatarTransition_ReturnToField(struct EventObject *eventObj)
{
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_5;
}

void sub_808B578(void)
{
    gPlayerAvatar.tileTransitionState = T_NOT_MOVING;
    if (PlayerIsAnimActive())
    {
        if (!PlayerCheckIfAnimFinishedOrInactive())
        {
            if (!player_is_anim_in_certain_ranges())
                gPlayerAvatar.tileTransitionState = T_TILE_TRANSITION;
        }
        else
        {
            if (!sub_808B618())
                gPlayerAvatar.tileTransitionState = T_TILE_CENTER;
        }
    }
}

static bool8 player_is_anim_in_certain_ranges(void)
{
    u8 movementActionId = gEventObjects[gPlayerAvatar.eventObjectId].movementActionId;

    if (movementActionId <= MOVEMENT_ACTION_FACE_RIGHT
     || (movementActionId >= MOVEMENT_ACTION_DELAY_1 && movementActionId <= MOVEMENT_ACTION_DELAY_16)
     || (movementActionId >= MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN && movementActionId <= MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_RIGHT)
     || (movementActionId >= MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN && movementActionId <= MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT)
     || (movementActionId >= MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN && movementActionId <= MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT))
        return TRUE;
    else
        return FALSE;
}

static bool8 sub_808B618(void)
{
    if (player_is_anim_in_certain_ranges() && gPlayerAvatar.runningState != TURN_DIRECTION)
        return TRUE;
    else
        return FALSE;
}

static bool8 PlayerIsAnimActive(void)
{
    return EventObjectIsMovementOverridden(&gEventObjects[gPlayerAvatar.eventObjectId]);
}

static bool8 PlayerCheckIfAnimFinishedOrInactive(void)
{
    return EventObjectCheckHeldMovementStatus(&gEventObjects[gPlayerAvatar.eventObjectId]);
}

static void PlayerSetCopyableMovement(u8 a)
{
    gEventObjects[gPlayerAvatar.eventObjectId].playerCopyableMovement = a;
}

u8 PlayerGetCopyableMovement(void)
{
    return gEventObjects[gPlayerAvatar.eventObjectId].playerCopyableMovement;
}

static void sub_808B6BC(u8 a)
{
    EventObjectForceSetHeldMovement(&gEventObjects[gPlayerAvatar.eventObjectId], a);
}

void PlayerSetAnimId(u8 movementActionId, u8 copyableMovement)
{
    if (!PlayerIsAnimActive())
    {
        PlayerSetCopyableMovement(copyableMovement);
        EventObjectSetHeldMovement(&gEventObjects[gPlayerAvatar.eventObjectId], movementActionId);
    }
}

// normal speed (1 speed)
void PlayerGoSpeed1(u8 a)
{
    PlayerSetAnimId(GetWalkNormalMovementAction(a), 2);
}

// fast speed (2 speed)
void PlayerGoSpeed2(u8 a)
{
    PlayerSetAnimId(GetWalkFastMovementAction(a), 2);
}

void PlayerRideWaterCurrent(u8 a)
{
    PlayerSetAnimId(GetRideWaterCurrentMovementAction(a), 2);
}

// fastest speed (4 speed)
void PlayerGoSpeed4(u8 a)
{
    PlayerSetAnimId(GetWalkFastestMovementAction(a), 2);
}

static void PlayerRun(u8 a)
{
    PlayerSetAnimId(GetPlayerRunMovementAction(a), 2);
}

void PlayerOnBikeCollide(u8 a)
{
    PlayCollisionSoundIfNotFacingWarp(a);
    PlayerSetAnimId(GetWalkInPlaceNormalMovementAction(a), 2);
}

void PlayerOnBikeCollideWithFarawayIslandMew(u8 a)
{
    PlayerSetAnimId(GetWalkInPlaceNormalMovementAction(a), 2);
}

static void PlayerNotOnBikeCollide(u8 a)
{
    PlayCollisionSoundIfNotFacingWarp(a);
    PlayerSetAnimId(GetWalkInPlaceSlowMovementAction(a), 2);
}

static void PlayerNotOnBikeCollideWithFarawayIslandMew(u8 a)
{
    PlayerSetAnimId(GetWalkInPlaceSlowMovementAction(a), 2);
}

void PlayerFaceDirection(u8 direction)
{
    PlayerSetAnimId(GetFaceDirectionMovementAction(direction), 1);
}

void PlayerTurnInPlace(u8 direction)
{
    PlayerSetAnimId(GetWalkInPlaceFastMovementAction(direction), 1);
}

void PlayerJumpLedge(u8 direction)
{
    PlaySE(SE_DANSA);
    PlayerSetAnimId(GetJump2MovementAction(direction), 8);
}

void sub_808B864(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_CENTER || gPlayerAvatar.tileTransitionState == T_NOT_MOVING)
    {
        if (player_should_look_direction_be_enforced_upon_movement())
            sub_808B6BC(GetFaceDirectionMovementAction(gEventObjects[gPlayerAvatar.eventObjectId].facingDirection));
    }
}

// wheelie idle
void PlayerIdleWheelie(u8 direction)
{
    PlayerSetAnimId(GetAcroWheelieFaceDirectionMovementAction(direction), 1);
}

// normal to wheelie
void PlayerStartWheelie(u8 direction)
{
    PlayerSetAnimId(GetAcroPopWheelieFaceDirectionMovementAction(direction), 1);
}

// wheelie to normal
void PlayerEndWheelie(u8 direction)
{
    PlayerSetAnimId(GetAcroEndWheelieFaceDirectionMovementAction(direction), 1);
}

// wheelie hopping standing
void PlayerStandingHoppingWheelie(u8 a)
{
    PlaySE(SE_JITE_PYOKO);
    PlayerSetAnimId(GetAcroWheelieHopFaceDirectionMovementAction(a), 1);
}

// wheelie hopping moving
void PlayerMovingHoppingWheelie(u8 a)
{
    PlaySE(SE_JITE_PYOKO);
    PlayerSetAnimId(GetAcroWheelieHopDirectionMovementAction(a), 2);
}

// wheelie hopping ledge
void PlayerLedgeHoppingWheelie(u8 a)
{
    PlaySE(SE_JITE_PYOKO);
    PlayerSetAnimId(GetAcroWheelieJumpDirectionMovementAction(a), 8);
}

// acro turn jump
void PlayerAcroTurnJump(u8 direction)
{
    PlaySE(SE_JITE_PYOKO);
    PlayerSetAnimId(GetJumpInPlaceTurnAroundMovementAction(direction), 1);
}

void sub_808B980(u8 direction)
{
    PlaySE(SE_WALL_HIT);
    PlayerSetAnimId(GetAcroWheelieInPlaceDirectionMovementAction(direction), 2);
}

void sub_808B9A4(u8 direction)
{
    PlayerSetAnimId(GetAcroPopWheelieMoveDirectionMovementAction(direction), 2);
}

void sub_808B9BC(u8 direction)
{
    PlayerSetAnimId(GetAcroWheelieMoveDirectionMovementAction(direction), 2);
}

void sub_808B9D4(u8 direction)
{
    PlayerSetAnimId(GetAcroEndWheelieMoveDirectionMovementAction(direction), 2);
}

static void PlayCollisionSoundIfNotFacingWarp(u8 a)
{
    s16 x, y;
    u8 metatileBehavior = gEventObjects[gPlayerAvatar.eventObjectId].currentMetatileBehavior;

    if (!sArrowWarpMetatileBehaviorChecks[a - 1](metatileBehavior))
    {
        if (a == 2)
        {
            PlayerGetDestCoords(&x, &y);
            MoveCoords(2, &x, &y);
            if (MetatileBehavior_IsWarpDoor(MapGridGetMetatileBehaviorAt(x, y)))
                return;
        }
        PlaySE(SE_WALL_HIT);
    }
}

void GetXYCoordsOneStepInFrontOfPlayer(s16 *x, s16 *y)
{
    *x = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x;
    *y = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y;
    MoveCoords(GetPlayerFacingDirection(), x, y);
}

void PlayerGetDestCoords(s16 *x, s16 *y)
{
    *x = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x;
    *y = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y;
}

u8 player_get_pos_including_state_based_drift(s16 *x, s16 *y)
{
    struct EventObject *object = &gEventObjects[gPlayerAvatar.eventObjectId];

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

u8 GetPlayerFacingDirection(void)
{
    return gEventObjects[gPlayerAvatar.eventObjectId].facingDirection;
}

u8 GetPlayerMovementDirection(void)
{
    return gEventObjects[gPlayerAvatar.eventObjectId].movementDirection;
}

u8 PlayerGetZCoord(void)
{
    return gEventObjects[gPlayerAvatar.eventObjectId].previousElevation;
}

void sub_808BC90(s16 x, s16 y)
{
    MoveEventObjectToMapCoords(&gEventObjects[gPlayerAvatar.eventObjectId], x, y);
}

u8 TestPlayerAvatarFlags(u8 a)
{
    return gPlayerAvatar.flags & a;
}

u8 sub_808BCD0(void)
{
    return gPlayerAvatar.flags;
}

u8 GetPlayerAvatarObjectId(void)
{
    return gPlayerAvatar.spriteId;
}

void sub_808BCE8(void)
{
    ForcedMovement_None();
}

void sub_808BCF4(void)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    npc_clear_strange_bits(playerEventObj);
    SetEventObjectDirection(playerEventObj, playerEventObj->facingDirection);
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        Bike_HandleBumpySlopeJump();
        Bike_UpdateBikeCounterSpeed(0);
    }
}

u8 GetRivalAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
    return sRivalAvatarGfxIds[state][gender];
}

u8 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
    return sPlayerAvatarGfxIds[state][gender];
}

u8 GetFRLGAvatarGraphicsIdByGender(u8 gender)
{
    return sFRLGAvatarGfxIds[gender];
}

u8 GetRSAvatarGraphicsIdByGender(u8 gender)
{
    return sRSAvatarGfxIds[gender];
}

u8 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
    return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar.gender);
}

u8 unref_GetRivalAvatarGenderByGraphicsId(u8 gfxId)
{
    switch (gfxId)
    {
    case EVENT_OBJ_GFX_RIVAL_MAY_NORMAL:
    case EVENT_OBJ_GFX_RIVAL_MAY_MACH_BIKE:
    case EVENT_OBJ_GFX_RIVAL_MAY_ACRO_BIKE:
    case EVENT_OBJ_GFX_RIVAL_MAY_SURFING:
    case EVENT_OBJ_GFX_RIVAL_MAY_FIELD_MOVE:
    case EVENT_OBJ_GFX_MAY_UNDERWATER:
    case EVENT_OBJ_GFX_MAY_FISHING:
    case EVENT_OBJ_GFX_MAY_WATERING:
        return FEMALE;
    default:
        return MALE;
    }
}

u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId)
{
    switch (gfxId)
    {
    case EVENT_OBJ_GFX_MAY_NORMAL:
    case EVENT_OBJ_GFX_MAY_MACH_BIKE:
    case EVENT_OBJ_GFX_MAY_ACRO_BIKE:
    case EVENT_OBJ_GFX_MAY_SURFING:
    case EVENT_OBJ_GFX_MAY_FIELD_MOVE:
    case EVENT_OBJ_GFX_MAY_UNDERWATER:
    case EVENT_OBJ_GFX_MAY_FISHING:
    case EVENT_OBJ_GFX_MAY_WATERING:
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
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE)
                break;
            if (MonKnowsMove(&gPlayerParty[i], MOVE_SURF))
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
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];
    s16 x = playerEventObj->currentCoords.x;
    s16 y = playerEventObj->currentCoords.y;

    MoveCoords(playerEventObj->facingDirection, &x, &y);
    if (GetCollisionAtCoords(playerEventObj, x, y, playerEventObj->facingDirection) == COLLISION_ELEVATION_MISMATCH
     && PlayerGetZCoord() == 3
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
    gPlayerAvatar.flags &= (PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_6 | PLAYER_AVATAR_FLAG_5);
    gPlayerAvatar.flags |= flags;
}

static u8 GetPlayerAvatarStateTransitionByGraphicsId(u8 graphicsId, u8 gender)
{
    u8 i;

    for (i = 0; i < 5; i++)
    {
        if (gUnknown_0849750C[gender][i][0] == graphicsId)
            return gUnknown_0849750C[gender][i][1];
    }
    return 1;
}

u8 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
    u8 i;
    u8 r5 = gPlayerAvatar.flags;

    for (i = 0; i < 5; i++)
    {
        if (gUnknown_0849750C[gPlayerAvatar.gender][i][1] & r5)
            return gUnknown_0849750C[gPlayerAvatar.gender][i][0];
    }
    return 0;
}

void SetPlayerAvatarExtraStateTransition(u8 graphicsId, u8 b)
{
    u8 unk = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar.gender);

    gPlayerAvatar.unk1 |= unk | b;
    DoPlayerAvatarTransition();
}

void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender)
{
    struct EventObjectTemplate playerEventObjTemplate;
    u8 eventObjectId;
    struct EventObject *eventObject;

    playerEventObjTemplate.localId = EVENT_OBJ_ID_PLAYER;
    playerEventObjTemplate.graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);
    playerEventObjTemplate.x = x - 7;
    playerEventObjTemplate.y = y - 7;
    playerEventObjTemplate.elevation = 0;
    playerEventObjTemplate.movementType = MOVEMENT_TYPE_PLAYER;
    playerEventObjTemplate.movementRangeX = 0;
    playerEventObjTemplate.movementRangeY = 0;
    playerEventObjTemplate.trainerType = 0;
    playerEventObjTemplate.trainerRange_berryTreeId = 0;
    playerEventObjTemplate.script = NULL;
    playerEventObjTemplate.flagId = 0;
    eventObjectId = SpawnSpecialEventObject(&playerEventObjTemplate);
    eventObject = &gEventObjects[eventObjectId];
    eventObject->isPlayer = 1;
    eventObject->warpArrowSpriteId = CreateWarpArrowSprite();
    EventObjectTurn(eventObject, direction);
    ClearPlayerAvatarInfo();
    gPlayerAvatar.runningState = NOT_MOVING;
    gPlayerAvatar.tileTransitionState = T_NOT_MOVING;
    gPlayerAvatar.eventObjectId = eventObjectId;
    gPlayerAvatar.spriteId = eventObject->spriteId;
    gPlayerAvatar.gender = gender;
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_5 | PLAYER_AVATAR_FLAG_ON_FOOT);
}

void SetPlayerInvisibility(bool8 invisible)
{
    gEventObjects[gPlayerAvatar.eventObjectId].invisible = invisible;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        gSprites[gEventObjects[gPlayerAvatar.eventObjectId].fieldEffectSpriteId].invisible = invisible;
}

void sub_808C114(void)
{
    EventObjectSetGraphicsId(&gEventObjects[gPlayerAvatar.eventObjectId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_FIELD_MOVE));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], 0);
}

void sub_808C15C(u8 direction)
{
    EventObjectSetGraphicsId(&gEventObjects[gPlayerAvatar.eventObjectId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_FISHING));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingDirectionAnimNum(direction));
}

void sub_808C1B4(u8 direction)
{
    EventObjectSetGraphicsId(&gEventObjects[gPlayerAvatar.eventObjectId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_ACRO_BIKE));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetAcroWheelieDirectionAnimNum(direction));
    SeekSpriteAnim(&gSprites[gPlayerAvatar.spriteId], 1);
}

void sub_808C228(u8 direction)
{
    EventObjectSetGraphicsId(&gEventObjects[gPlayerAvatar.eventObjectId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_WATERING));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFaceDirectionAnimNum(direction));
}

static void sub_808C280(struct EventObject *eventObject)
{
    s16 x;
    s16 y;
    u8 direction;
    u8 metatileBehavior = eventObject->currentMetatileBehavior;

    for (x = 0, direction = DIR_SOUTH; x < 4; x++, direction++)
    {
        if (sArrowWarpMetatileBehaviorChecks2[x](metatileBehavior) && direction == eventObject->movementDirection)
        {
            x = eventObject->currentCoords.x;
            y = eventObject->currentCoords.y;
            MoveCoords(direction, &x, &y);
            ShowWarpArrowSprite(eventObject->warpArrowSpriteId, direction, x, y);
            return;
        }
    }
    SetSpriteInvisible(eventObject->warpArrowSpriteId);
}

/* Strength */

static void StartStrengthAnim(u8 a, u8 b)
{
    u8 taskId = CreateTask(Task_BumpBoulder, 0xFF);

    gTasks[taskId].data[1] = a;
    gTasks[taskId].data[2] = b;
    Task_BumpBoulder(taskId);
}

static void Task_BumpBoulder(u8 taskId)
{
    while (gUnknown_08497530[gTasks[taskId].data[0]](&gTasks[taskId],
                                                     &gEventObjects[gPlayerAvatar.eventObjectId],
                                                     &gEventObjects[gTasks[taskId].data[1]]))
        ;
}

static bool8 sub_808C3A4(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject)
{
    ScriptContext2_Enable();
    gPlayerAvatar.preventStep = TRUE;
    task->data[0]++;
    return FALSE;
}

static bool8 do_boulder_dust(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject)
{
    if (EventObjectIsHeldMovementActive(playerObject))
    {
        EventObjectClearHeldMovementIfFinished(playerObject);
    }

    if (EventObjectIsHeldMovementActive(strengthObject))
    {
        EventObjectClearHeldMovementIfFinished(strengthObject);
    }

    if (!EventObjectIsMovementOverridden(playerObject)
     && !EventObjectIsMovementOverridden(strengthObject))
    {
        EventObjectClearHeldMovementIfFinished(playerObject);
        EventObjectClearHeldMovementIfFinished(strengthObject);
        EventObjectSetHeldMovement(playerObject, GetWalkInPlaceNormalMovementAction((u8)task->data[2]));
        EventObjectSetHeldMovement(strengthObject, GetWalkSlowMovementAction((u8)task->data[2]));
        gFieldEffectArguments[0] = strengthObject->currentCoords.x;
        gFieldEffectArguments[1] = strengthObject->currentCoords.y;
        gFieldEffectArguments[2] = strengthObject->previousElevation;
        gFieldEffectArguments[3] = gSprites[strengthObject->spriteId].oam.priority;
        FieldEffectStart(FLDEFF_DUST);
        PlaySE(SE_W070);
        task->data[0]++;
    }
    return FALSE;
}

static bool8 sub_808C484(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject)
{
    if (EventObjectCheckHeldMovementStatus(playerObject)
     && EventObjectCheckHeldMovementStatus(strengthObject))
    {
        EventObjectClearHeldMovementIfFinished(playerObject);
        EventObjectClearHeldMovementIfFinished(strengthObject);
        gPlayerAvatar.preventStep = FALSE;
        ScriptContext2_Disable();
        DestroyTask(FindTaskIdByFunc(Task_BumpBoulder));
    }
    return FALSE;
}

/* Some field effect */

static void DoPlayerMatJump(void)
{
    DoPlayerAvatarSecretBaseMatJump(CreateTask(DoPlayerAvatarSecretBaseMatJump, 0xFF));
}

static void DoPlayerAvatarSecretBaseMatJump(u8 taskId)
{
    while (sPlayerAvatarSecretBaseMatJump[gTasks[taskId].data[0]](&gTasks[taskId], &gEventObjects[gPlayerAvatar.eventObjectId]))
        ;
}

// because data[0] is used to call this, it can be inferred that there may have been multiple mat jump functions at one point, so the name for these groups of functions is appropriate in assuming the sole use of mat jump.
static u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *task, struct EventObject *eventObject)
{
    gPlayerAvatar.preventStep = TRUE;
    if (EventObjectClearHeldMovementIfFinished(eventObject))
    {
        PlaySE(SE_DANSA);
        EventObjectSetHeldMovement(eventObject, GetJumpInPlaceMovementAction(eventObject->facingDirection));
        task->data[1]++;
        if (task->data[1] > 1)
        {
            gPlayerAvatar.preventStep = FALSE;
            gPlayerAvatar.unk1 |= 0x20;
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
    while (sPlayerAvatarSecretBaseMatSpin[gTasks[taskId].data[0]](&gTasks[taskId], &gEventObjects[gPlayerAvatar.eventObjectId]))
        ;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *task, struct EventObject *eventObject)
{
    task->data[0]++;
    task->data[1] = eventObject->movementDirection;
    gPlayerAvatar.preventStep = TRUE;
    ScriptContext2_Enable();
    PlaySE(SE_TK_WARPIN);
    return TRUE;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *task, struct EventObject *eventObject)
{
    u8 directions[] = {DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

    if (EventObjectClearHeldMovementIfFinished(eventObject))
    {
        u8 direction;

        EventObjectSetHeldMovement(eventObject, GetFaceDirectionMovementAction(direction = directions[eventObject->movementDirection - 1]));
        if (direction == (u8)task->data[1])
            task->data[2]++;
        task->data[0]++;
        if (task->data[2] > 3 && direction == GetOppositeDirection(task->data[1]))
            task->data[0]++;
    }
    return FALSE;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *task, struct EventObject *eventObject)
{
    const u8 actions[] = {
        MOVEMENT_ACTION_DELAY_1,
        MOVEMENT_ACTION_DELAY_1,
        MOVEMENT_ACTION_DELAY_2,
        MOVEMENT_ACTION_DELAY_4,
        MOVEMENT_ACTION_DELAY_8,
    };

    if (EventObjectClearHeldMovementIfFinished(eventObject))
    {
        EventObjectSetHeldMovement(eventObject, actions[task->data[2]]);
        task->data[0] = 1;
    }
    return FALSE;
}

static bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *task, struct EventObject *eventObject)
{
    if (EventObjectClearHeldMovementIfFinished(eventObject))
    {
        EventObjectSetHeldMovement(eventObject, GetWalkSlowMovementAction(GetOppositeDirection(task->data[1])));
        ScriptContext2_Disable();
        gPlayerAvatar.preventStep = FALSE;
        DestroyTask(FindTaskIdByFunc(PlayerAvatar_DoSecretBaseMatSpin));
    }
    return FALSE;
}

static void CreateStopSurfingTask(u8 direction)
{
    u8 taskId;

    ScriptContext2_Enable();
    Overworld_ClearSavedMusic();
    Overworld_ChangeMusicToDefault();
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_SURFING;
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_ON_FOOT;
    gPlayerAvatar.preventStep = TRUE;
    taskId = CreateTask(Task_StopSurfingInit, 0xFF);
    gTasks[taskId].data[0] = direction;
    Task_StopSurfingInit(taskId);
}

static void Task_StopSurfingInit(u8 taskId)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    if (EventObjectIsMovementOverridden(playerEventObj))
    {
        if (!EventObjectClearHeldMovementIfFinished(playerEventObj))
            return;
    }
    sub_81555AC(playerEventObj->fieldEffectSpriteId, 2);
    EventObjectSetHeldMovement(playerEventObj, GetJumpSpecialMovementAction((u8)gTasks[taskId].data[0]));
    gTasks[taskId].func = Task_WaitStopSurfing;
}

static void Task_WaitStopSurfing(u8 taskId)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    if (EventObjectClearHeldMovementIfFinished(playerEventObj))
    {
        EventObjectSetGraphicsId(playerEventObj, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
        EventObjectSetHeldMovement(playerEventObj, GetFaceDirectionMovementAction(playerEventObj->facingDirection));
        gPlayerAvatar.preventStep = FALSE;
        ScriptContext2_Disable();
        DestroySprite(&gSprites[playerEventObj->fieldEffectSpriteId]);
        DestroyTask(taskId);
    }
}

static bool8 (*const sFishingStateFuncs[])(struct Task *) =
{
    Fishing1,
    Fishing2,
    Fishing3,
    Fishing4,
    Fishing5,
    Fishing6,
    Fishing7,
    Fishing8,
    Fishing9,
    Fishing10,
    Fishing11,
    Fishing12,
    Fishing13,
    Fishing14,
    Fishing15,
    Fishing16,
};

#define tStep              data[0]
#define tFrameCounter      data[1]
#define tNumDots           data[2]
#define tDotsRequired      data[3]
#define tRoundsPlayed      data[12]
#define tMinRoundsRequired data[13]
#define tPlayerGfxId       data[14]
#define tFishingRod        data[15]

#define FISHING_START_ROUND 3
#define FISHING_GOT_BITE 6
#define FISHING_ON_HOOK 9
#define FISHING_NO_BITE 11
#define FISHING_GOT_AWAY 12
#define FISHING_SHOW_RESULT 13

void StartFishing(u8 rod)
{
    u8 taskId = CreateTask(Task_Fishing, 0xFF);

    gTasks[taskId].tFishingRod = rod;
    Task_Fishing(taskId);
}

static void Task_Fishing(u8 taskId)
{
    while (sFishingStateFuncs[gTasks[taskId].tStep](&gTasks[taskId]))
        ;
}

static bool8 Fishing1(struct Task *task)
{
    ScriptContext2_Enable();
    gPlayerAvatar.preventStep = TRUE;
    task->tStep++;
    return FALSE;
}

static bool8 Fishing2(struct Task *task)
{
    struct EventObject *playerEventObj;
    const s16 arr1[] = {1, 1, 1};
    const s16 arr2[] = {1, 3, 6};

    task->tRoundsPlayed = 0;
    task->tMinRoundsRequired = arr1[task->tFishingRod] + (Random() % arr2[task->tFishingRod]);
    task->tPlayerGfxId = gEventObjects[gPlayerAvatar.eventObjectId].graphicsId;
    playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];
    EventObjectClearHeldMovementIfActive(playerEventObj);
    playerEventObj->enableAnim = 1;
    sub_808C15C(playerEventObj->facingDirection);
    task->tStep++;
    return FALSE;
}

static bool8 Fishing3(struct Task *task)
{
    AlignFishingAnimationFrames();

    // Wait one second
    task->tFrameCounter++;
    if (task->tFrameCounter >= 60)
        task->tStep++;
    return FALSE;
}

static bool8 Fishing4(struct Task *task)
{
    u32 randVal;

    sub_819786C(0, TRUE);
    task->tStep++;
    task->tFrameCounter = 0;
    task->tNumDots = 0;
    randVal = Random();
    randVal %= 10;
    task->tDotsRequired = randVal + 1;
    if (task->tRoundsPlayed == 0)
        task->tDotsRequired = randVal + 4;
    if (task->tDotsRequired >= 10)
        task->tDotsRequired = 10;
    return TRUE;
}

// Play a round of the dot game
static bool8 Fishing5(struct Task *task)
{
    const u8 dot[] = _("·");

    AlignFishingAnimationFrames();
    task->tFrameCounter++;
    if (gMain.newKeys & A_BUTTON)
    {
        task->tStep = FISHING_NO_BITE;
        if (task->tRoundsPlayed != 0)
            task->tStep = FISHING_GOT_AWAY;
        return TRUE;
    }
    else
    {
        if (task->tFrameCounter >= 20)
        {
            task->tFrameCounter = 0;
            if (task->tNumDots >= task->tDotsRequired)
            {
                task->tStep++;
                if (task->tRoundsPlayed != 0)
                    task->tStep++;
                task->tRoundsPlayed++;
            }
            else
            {
                AddTextPrinterParameterized(0, 1, dot, task->tNumDots * 8, 1, 0, NULL);
                task->tNumDots++;
            }
        }
        return FALSE;
    }
}

// Determine if fish bites
static bool8 Fishing6(struct Task *task)
{
    bool8 bite;

    AlignFishingAnimationFrames();
    task->tStep++;
    bite = FALSE;

    if (!DoesCurrentMapHaveFishingMons())
    {
        task->tStep = FISHING_NO_BITE;
    }
    else
    {
        if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        {
            u8 ability = GetMonAbility(&gPlayerParty[0]);
            if (ability == ABILITY_SUCTION_CUPS || ability  == ABILITY_STICKY_HOLD)
            {
                if (Random() % 100 > 14)
                {
                    bite = TRUE;
                }
            }
        }

        if (!bite)
        {
            if (Random() & 1)
            {
                task->tStep = FISHING_NO_BITE;
            }
            else
            {
                bite = TRUE;
            }
        }

        if (bite == TRUE)
        {
            StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingBiteDirectionAnimNum(GetPlayerFacingDirection()));
        }
    }
    return TRUE;
}

// Oh! A Bite!
static bool8 Fishing7(struct Task *task)
{
    AlignFishingAnimationFrames();
    AddTextPrinterParameterized(0, 1, gText_OhABite, 0, 17, 0, NULL);
    task->tStep++;
    task->tFrameCounter = 0;
    return FALSE;
}

// We have a bite. Now, wait for the player to press A, or the timer to expire.
static bool8 Fishing8(struct Task *task)
{
    const s16 reelTimeouts[3] = {36, 33, 30};

    AlignFishingAnimationFrames();
    task->tFrameCounter++;
    if (task->tFrameCounter >= reelTimeouts[task->tFishingRod])
        task->tStep = FISHING_GOT_AWAY;
    else if (gMain.newKeys & A_BUTTON)
        task->tStep++;
    return FALSE;
}

// Determine if we're going to play the dot game again
static bool8 Fishing9(struct Task *task)
{
    const s16 arr[][2] =
    {
        {0, 0},
        {40, 10},
        {70, 30}
    };

    AlignFishingAnimationFrames();
    task->tStep++;
    if (task->tRoundsPlayed < task->tMinRoundsRequired)
    {
        task->tStep = FISHING_START_ROUND;
    }
    else if (task->tRoundsPlayed < 2)
    {
        // probability of having to play another round
        s16 probability = Random() % 100;

        if (arr[task->tFishingRod][task->tRoundsPlayed] > probability)
            task->tStep = FISHING_START_ROUND;
    }
    return FALSE;
}

static bool8 Fishing10(struct Task *task)
{
    AlignFishingAnimationFrames();
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, 1, gText_PokemonOnHook, 1, 0, 2, 1, 3);
    task->tStep++;
    task->tFrameCounter = 0;
    return FALSE;
}

static bool8 Fishing11(struct Task *task)
{
    if (task->tFrameCounter == 0)
        AlignFishingAnimationFrames();

    RunTextPrinters();

    if (task->tFrameCounter == 0)
    {
        if (!IsTextPrinterActive(0))
        {
            struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

            EventObjectSetGraphicsId(playerEventObj, task->tPlayerGfxId);
            EventObjectTurn(playerEventObj, playerEventObj->movementDirection);
            if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
                sub_8155604(gEventObjects[gPlayerAvatar.eventObjectId].fieldEffectSpriteId, 0, 0);
            gSprites[gPlayerAvatar.spriteId].pos2.x = 0;
            gSprites[gPlayerAvatar.spriteId].pos2.y = 0;
            ClearDialogWindowAndFrame(0, TRUE);
            task->tFrameCounter++;
            return FALSE;
        }
    }

    if (task->tFrameCounter != 0)
    {
        gPlayerAvatar.preventStep = FALSE;
        ScriptContext2_Disable();
        FishingWildEncounter(task->tFishingRod);
        sub_80ED950(1);
        DestroyTask(FindTaskIdByFunc(Task_Fishing));
    }
    return FALSE;
}

// Not even a nibble
static bool8 Fishing12(struct Task *task)
{
    AlignFishingAnimationFrames();
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingNoCatchDirectionAnimNum(GetPlayerFacingDirection()));
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, 1, gText_NotEvenANibble, 1, 0, 2, 1, 3);
    task->tStep = FISHING_SHOW_RESULT;
    return TRUE;
}

// It got away
static bool8 Fishing13(struct Task *task)
{
    AlignFishingAnimationFrames();
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingNoCatchDirectionAnimNum(GetPlayerFacingDirection()));
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, 1, gText_ItGotAway, 1, 0, 2, 1, 3);
    task->tStep++;
    return TRUE;
}

// Wait one second
static bool8 Fishing14(struct Task *task)
{
    AlignFishingAnimationFrames();
    task->tStep++;
    return FALSE;
}

static bool8 Fishing15(struct Task *task)
{
    AlignFishingAnimationFrames();
    if (gSprites[gPlayerAvatar.spriteId].animEnded)
    {
        struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

        EventObjectSetGraphicsId(playerEventObj, task->tPlayerGfxId);
        EventObjectTurn(playerEventObj, playerEventObj->movementDirection);
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
            sub_8155604(gEventObjects[gPlayerAvatar.eventObjectId].fieldEffectSpriteId, 0, 0);
        gSprites[gPlayerAvatar.spriteId].pos2.x = 0;
        gSprites[gPlayerAvatar.spriteId].pos2.y = 0;
        task->tStep++;
    }
    return FALSE;
}

static bool8 Fishing16(struct Task *task)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(0))
    {
        gPlayerAvatar.preventStep = FALSE;
        ScriptContext2_Disable();
        UnfreezeEventObjects();
        ClearDialogWindowAndFrame(0, TRUE);
        sub_80ED950(0);
        DestroyTask(FindTaskIdByFunc(Task_Fishing));
    }
    return FALSE;
}

#undef tStep
#undef tFrameCounter
#undef tFishingRod

static void AlignFishingAnimationFrames(void)
{
    struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];
    u8 animCmdIndex;
    u8 animType;

    AnimateSprite(playerSprite);
    playerSprite->pos2.x = 0;
    playerSprite->pos2.y = 0;
    animCmdIndex = playerSprite->animCmdIndex;
    if (playerSprite->anims[playerSprite->animNum][animCmdIndex].type == -1)
    {
        animCmdIndex--;
    }
    else
    {
        playerSprite->animDelayCounter++;
        if (playerSprite->anims[playerSprite->animNum][animCmdIndex].type == -1)
            animCmdIndex--;
    }
    animType = playerSprite->anims[playerSprite->animNum][animCmdIndex].type;
    if (animType == 1 || animType == 2 || animType == 3)
    {
        playerSprite->pos2.x = 8;
        if (GetPlayerFacingDirection() == 3)
            playerSprite->pos2.x = -8;
    }
    if (animType == 5)
        playerSprite->pos2.y = -8;
    if (animType == 10 || animType == 11)
        playerSprite->pos2.y = 8;
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
        sub_8155604(gEventObjects[gPlayerAvatar.eventObjectId].fieldEffectSpriteId, 1, playerSprite->pos2.y);
}

void sub_808D074(u8 a0)
{
    gUnknown_0203734C = a0;
}

static u8 sub_808D080(void)
{
    if (gUnknown_0203734C == 0)
    {
        return 1;
    }
    return gUnknown_0203734C;
}

static void sub_808D094(u8 taskId)
{
    struct EventObject *object = &gEventObjects[gPlayerAvatar.eventObjectId];
    struct Sprite *sprite = &gSprites[object->spriteId];
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            if (!EventObjectClearHeldMovementIfFinished(object))
            {
                return;
            }

            sub_808D074(object->facingDirection);
            data[1] = 0;
            data[2] = 1;
            data[3] = (u16)(sprite->pos1.y + sprite->pos2.y) * 16;
            sprite->pos2.y = 0;
            CameraObjectReset2();
            object->fixedPriority = TRUE;
            sprite->oam.priority = 0;
            sprite->subpriority = 0;
            sprite->subspriteMode = SUBSPRITES_OFF;
            data[0]++;
        case 1:
            sub_808D38C(object, &data[1]);
            data[3] -= data[2];
            data[2] += 3;
            sprite->pos1.y = data[3] >> 4;
            if (sprite->pos1.y + (s16)gTotalCameraPixelOffsetY < -32)
            {
                data[0]++;
            }
            break;
        case 2:
            DestroyTask(taskId);
            break;
    }
}

static void sub_808D1FC(u8 taskId);

void sub_808D194(void)
{
    sub_808D1FC(CreateTask(sub_808D1FC, 0));
}

bool32 sub_808D1B4(void)
{
    return FuncIsActiveTask(sub_808D1FC);
}

void sub_808D1C8(void)
{
    sub_808D094(CreateTask(sub_808D094, 0));
}

bool32 sub_808D1E8(void)
{
    return FuncIsActiveTask(sub_808D094);
}

static const u8 gUnknown_084975BC[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

static void sub_808D1FC(u8 taskId)
{
    struct EventObject *object = &gEventObjects[gPlayerAvatar.eventObjectId];
    struct Sprite *sprite = &gSprites[object->spriteId];
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            data[5] = sub_808D080();
            EventObjectForceSetHeldMovement(object, GetFaceDirectionMovementAction(gUnknown_084975BC[data[5]]));
            data[1] = 0;
            data[2] = 116;
            data[4] = sprite->pos1.y;
            data[6] = sprite->oam.priority;
            data[7] = sprite->subpriority;
            data[3] = -((u16)sprite->pos2.y + 32) * 16;
            sprite->pos2.y = 0;
            CameraObjectReset2();
            object->fixedPriority = TRUE;
            sprite->oam.priority = 1;
            sprite->subpriority = 0;
            sprite->subspriteMode = SUBSPRITES_OFF;
            data[0]++;
        case 1:
            sub_808D38C(object, &data[1]);
            data[3] += data[2];
            data[2] -= 3;
            if (data[2] < 4)
            {
                data[2] = 4;
            }
            sprite->pos1.y = data[3] >> 4;
            if (sprite->pos1.y >= data[4])
            {
                sprite->pos1.y = data[4];
                data[8] = 0;
                data[0]++;
            }
            break;
        case 2:
            sub_808D38C(object, &data[1]);
            data[8]++;
            if (data[8] > 8)
            {
                data[0]++;
            }
            break;
        case 3:
            if (data[5] == sub_808D38C(object, &data[1]))
            {
                object->fixedPriority = 0;
                sprite->oam.priority = data[6];
                sprite->subpriority = data[7];
                CameraObjectReset1();
                DestroyTask(taskId);
            }
            break;
    }
}

static u8 sub_808D38C(struct EventObject *object, s16 *a1)
{
    if (*a1 < 8 && ++(*a1) < 8)
    {
        return object->facingDirection;
    }

    if (!EventObjectCheckHeldMovementStatus(object))
    {
        return object->facingDirection;
    }

    EventObjectForceSetHeldMovement(object, GetFaceDirectionMovementAction(gUnknown_084975BC[object->facingDirection]));
    *a1 = 0;
    return gUnknown_084975BC[object->facingDirection];
}
