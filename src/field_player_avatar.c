#include "global.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "global.fieldmap.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "rotating_gate.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/flags.h"

extern void task_add_bump_boulder(u8, u8);
static bool8 ShouldJumpLedge(s16, s16, u8);
static bool8 sub_808B1BC(s16, s16, u8);
static u8 sub_808B164(struct EventObject *, s16, s16, u8, u8);
static u8 sub_808B238(s16, s16, u8);
static void check_acro_bike_metatile(s16, s16, u8, u8 *);
extern void PlayerNotOnBikeCollide(u8);
extern void PlayerNotOnBikeCollideWithFarawayIslandMew(u8);
extern void PlayerRun(u8); 
static void MovePlayerNotOnBike(u8, u16);
static u8 CheckMovementInputNotOnBike(u8);
extern void sub_808C5B0(void);
extern void sub_808C4D8(void);
static u8 CheckForPlayerAvatarCollision(u8);
static u8 EventObjectCB2_NoMovement2();
extern void sub_808C280(struct EventObject *); 
static bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *, u8);
void npc_clear_strange_bits(struct EventObject *);
extern void DoPlayerAvatarTransition(void); 
static bool8 TryDoMetatileBehaviorForcedMovement();
static void MovePlayerAvatarUsingKeypadInput(u8, u16, u16);
static void PlayerAllowForcedMovementIfMovingSameDirection();
static u8 sub_808B028(u8);
static u8 GetForcedMovementByMetatileBehavior();
static void PlayerNotOnBikeNotMoving(u8, u16);
static void PlayerNotOnBikeTurningInPlace(u8, u16);
static void PlayerNotOnBikeMoving(u8, u16);
extern void sub_808C750(u8);

extern void PlayerAvatarTransition_Normal(struct EventObject *a);
extern void PlayerAvatarTransition_MachBike(struct EventObject *a);
extern void PlayerAvatarTransition_AcroBike(struct EventObject *a);
extern void PlayerAvatarTransition_Surfing(struct EventObject *a);
extern void PlayerAvatarTransition_Underwater(struct EventObject *a);
extern void PlayerAvatarTransition_ReturnToField(struct EventObject *a);
extern void PlayerAvatarTransition_Dummy(struct EventObject *a);

extern u8 sub_808C3A4(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject);
extern u8 do_boulder_dust(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject);
extern u8 sub_808C484(struct Task *task, struct EventObject *playerObject, struct EventObject *strengthObject);

extern u8 sub_808C544(struct Task *task, struct EventObject *eventObject);

extern u8 sub_808C61C(struct Task *task, struct EventObject *eventObject);
extern u8 sub_808C644(struct Task *task, struct EventObject *eventObject);
extern u8 sub_808C6BC(struct Task *task, struct EventObject *eventObject);
extern u8 sub_808C6FC(struct Task *task, struct EventObject *eventObject);

extern u8 fish0(struct Task *task);
extern u8 fish1(struct Task *task);
extern u8 fish2(struct Task *task);
extern u8 fish3(struct Task *task);
extern u8 fish4(struct Task *task);
extern u8 fish5(struct Task *task);
extern u8 fish6(struct Task *task);
extern u8 fish7(struct Task *task);
extern u8 fish8(struct Task *task);
extern u8 fish9(struct Task *task);
extern u8 fishA_wait_for_a_pressed(struct Task *task);
extern u8 fishB(struct Task *task);
extern u8 fishC(struct Task *task);
extern u8 fishD(struct Task *task);
extern u8 fishE(struct Task *task);
extern u8 fishF(struct Task *task);

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

static bool8 (*const gUnknown_0849749C[])(u8) =
{
    MetatileBehavior_IsBumpySlope,
    MetatileBehavior_IsIsolatedVerticalRail,
    MetatileBehavior_IsIsolatedHorizontalRail,
    MetatileBehavior_IsVerticalRail,
    MetatileBehavior_IsHorizontalRail,
};

static const u8 gUnknown_084974B0[] = {9, 10, 11, 12, 13, 0, 0, 0};

void (*const gUnknown_084974B8[])(struct EventObject *) =
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

bool8 (*const sArrowWarpMetatileBehaviorChecks[])(u8) =
{
    MetatileBehavior_IsSouthArrowWarp,
    MetatileBehavior_IsNorthArrowWarp,
    MetatileBehavior_IsWestArrowWarp,
    MetatileBehavior_IsEastArrowWarp,
};

const u8 sRivalAvatarGfxIds[][2] =
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

const u8 sPlayerAvatarGfxIds[][2] =
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

const u8 gUnknown_08497508[] = {EVENT_OBJ_GFX_RED, EVENT_OBJ_GFX_LEAF};

const u8 gUnknown_0849750A[] = {EVENT_OBJ_GFX_LINK_RS_BRENDAN, EVENT_OBJ_GFX_LINK_RS_MAY};

const u8 gUnknown_0849750C[2][5][2] =
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

bool8 (*const sArrowWarpMetatileBehaviorChecks2[])(u8) =  //Duplicate of sArrowWarpMetatileBehaviorChecks
{
    MetatileBehavior_IsSouthArrowWarp,
    MetatileBehavior_IsNorthArrowWarp,
    MetatileBehavior_IsWestArrowWarp,
    MetatileBehavior_IsEastArrowWarp,
};

u8 (*const gUnknown_08497530[])(struct Task *, struct EventObject *, struct EventObject *) =
{
    sub_808C3A4,
    do_boulder_dust,
    sub_808C484,
};

u8 (*const gUnknown_0849753C[])(struct Task *, struct EventObject *) =
{
    sub_808C544,
};

u8 (*const gUnknown_08497540[])(struct Task *, struct EventObject *) =
{
    sub_808C61C,
    sub_808C644,
    sub_808C6BC,
    sub_808C6FC,
};

const u8 gUnknown_08497550[] = {3, 4, 2, 1};

const u8 gUnknown_08497554[] = {16, 16, 17, 18, 19};

u8 (*const sFishingStateFuncs[])(struct Task *) =
{
    fish0,
    fish1,
    fish2,
    fish3,
    fish4,
    fish5,
    fish6,
    fish7,
    fish8,
    fish9,
    fishA_wait_for_a_pressed,
    fishB,
    fishC,
    fishD,
    fishE,
    fishF,
};

const u16 gUnknown_0849759C[] = {1, 1, 1};

const u16 gUnknown_084975A2[] = {1, 3, 6};

const u8 gText_Dot[] = _("·");

const u16 sReelTimeouts[] = {36, 33, 30};

const u16 gUnknown_084975B0[] =
{
    0, 0,
    0x28, 10,
    0x46, 30,
};

const u8 gUnknown_084975BC[] = {0x01, 0x03, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00};

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
    #ifdef NONMATCHING
        u8 r5 = direction;
        u8 r6 = direction;
    #else
        u8 r5 = direction;
        register u8 r6 asm("r6") = direction;
    #endif
    //a very bad HACK 

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

void npc_clear_strange_bits(struct EventObject *eventObj)
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

bool8 ForcedMovement_None(void)
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
    u8 collisionType = CheckForPlayerAvatarCollision(direction);

    playerAvatar->flags |= PLAYER_AVATAR_FLAG_6;
    if (collisionType != 0)
    {
        ForcedMovement_None();
        if (collisionType <= 4)
        {
            return 0;
        }
        else
        {
            if (collisionType == COLLISION_LEDGE_JUMP)
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

u8 DoForcedMovementInCurrentDirection(void (*a)(u8))
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    playerEventObj->disableAnim = 1;
    return DoForcedMovement(playerEventObj->movementDirection, a);
}

bool8 ForcedMovement_Slip(void)
{
    return DoForcedMovementInCurrentDirection(PlayerGoSpeed2);
}

bool8 ForcedMovement_WalkSouth(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerGoSpeed1);
}

bool8 ForcedMovement_WalkNorth(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerGoSpeed1);
}

bool8 ForcedMovement_WalkWest(void)
{
    return DoForcedMovement(DIR_WEST, PlayerGoSpeed1);
}

bool8 ForcedMovement_WalkEast(void)
{
    return DoForcedMovement(DIR_EAST, PlayerGoSpeed1);
}

bool8 ForcedMovement_PushedSouthByCurrent(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerGoSpeed3);
}

bool8 ForcedMovement_PushedNorthByCurrent(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerGoSpeed3);
}

bool8 ForcedMovement_PushedWestByCurrent(void)
{
    return DoForcedMovement(DIR_WEST, PlayerGoSpeed3);
}

bool8 ForcedMovement_PushedEastByCurrent(void)
{
    return DoForcedMovement(DIR_EAST, PlayerGoSpeed3);
}

u8 ForcedMovement_Slide(u8 direction, void (*b)(u8))
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    playerEventObj->disableAnim = 1;
    playerEventObj->facingDirectionLocked = 1;
    return DoForcedMovement(direction, b);
}

bool8 ForcedMovement_SlideSouth(void)
{
    return ForcedMovement_Slide(DIR_SOUTH, PlayerGoSpeed2);
}

bool8 ForcedMovement_SlideNorth(void)
{
    return ForcedMovement_Slide(DIR_NORTH, PlayerGoSpeed2);
}

bool8 ForcedMovement_SlideWest(void)
{
    return ForcedMovement_Slide(DIR_WEST, PlayerGoSpeed2);
}

bool8 ForcedMovement_SlideEast(void)
{
    return ForcedMovement_Slide(DIR_EAST, PlayerGoSpeed2);
}

bool8 ForcedMovement_0xBB(void)
{
    sub_808C4D8();
    return TRUE;
}

bool8 ForcedMovement_0xBC(void)
{
    sub_808C5B0();
    return TRUE;
}

bool8 ForcedMovement_MuddySlope(void)
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
    u8 r0 = CheckForPlayerAvatarCollision(direction);

    if (r0 != 0)
    {
        if (r0 == 6)
        {
            PlayerJumpLedge(direction);
            return;
        }
        else if (r0 == 4 && IsPlayerCollidingWithFarawayIslandMew(direction) != 0)
        {
            PlayerNotOnBikeCollideWithFarawayIslandMew(direction);
            return;
        }
        else
        {
            u8 r4 = r0 - 5;

            if (r4 > 3)
            {
                PlayerNotOnBikeCollide(direction);
                return;
            }
            else
            {
                return;
            }
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

u8 CheckForEventObjectCollision(struct EventObject *a, s16 x, s16 y, u8 direction, u8 e)
{
    u8 collision;

    collision = GetCollisionAtCoords(a, x, y, direction);
    if (collision == 3 && sub_808B1BC(x, y, direction))
        return 5;
    if (ShouldJumpLedge(x, y, direction))
    {
        IncrementGameStat(GAME_STAT_JUMPED_DOWN_LEDGES);
        return COLLISION_LEDGE_JUMP;
    }
    if (collision == 4 && sub_808B238(x, y, direction))
        return 7;

    if (collision == 0)
    {
        if (CheckForRotatingGatePuzzleCollision(direction, x, y))
            return 8;
        check_acro_bike_metatile(x, y, e, &collision);
    }
    return collision;
}

static u8 sub_808B164(struct EventObject *a, s16 x, s16 y, u8 direction, u8 e)
{
    u8 collision = GetCollisionAtCoords(a, x, y, direction);

    if (collision == 0)
    {
        if (CheckForRotatingGatePuzzleCollisionWithoutAnimation(direction, x, y) != 0)
            return 8;
        check_acro_bike_metatile(x, y, e, &collision);
    }
    return collision;
}

static bool8 sub_808B1BC(s16 x, s16 y, u8 direction)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
     && MapGridGetZCoordAt(x, y) == 3
     && GetEventObjectIdByXYZ(x, y, 3) == 16)
    {
        sub_808C750(direction);
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

static u8 sub_808B238(s16 x, s16 y, u8 direction)
{
    if (FlagGet(FLAG_SYS_USE_STRENGTH))
    {
        u8 eventObjectId = GetEventObjectIdByXY(x, y);

            if (eventObjectId != 16 && gEventObjects[eventObjectId].graphicsId == 0x57)
            {
                x = gEventObjects[eventObjectId].currentCoords.x;
                y = gEventObjects[eventObjectId].currentCoords.y;
                MoveCoords(direction, &x, &y);
                if (GetCollisionAtCoords(&gEventObjects[eventObjectId], x, y, direction) == 0
                 && MetatileBehavior_IsNonAnimDoor(MapGridGetMetatileBehaviorAt(x, y)) == 0)
                {
                    task_add_bump_boulder(eventObjectId, direction);
                    return 1;
                }
            }
    }
    return 0;
}

static void check_acro_bike_metatile(s16 unused1, s16 unused2, u8 c, u8 *d)
{
    u8 i;

    for (i = 0; i < 5; i++)
    {
        if (gUnknown_0849749C[i](c))
        {
            *d = gUnknown_084974B0[i];
            return;
        }
    }
}
