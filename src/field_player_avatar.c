#include "global.h"
#include "global.fieldmap.h"
#include "sprite.h"
#include "event_object_movement.h"
#include "bike.h"
#include "metatile_behavior.h"
#include "metatile_behaviors.h"
#include "constants/flags.h"
#include "event_data.h"
#include "fieldmap.h"
#include "overworld.h"
#include "rotating_gate.h"

bool8 ForcedMovement_None(void);
bool8 ForcedMovement_Slip(void);
bool8 ForcedMovement_WalkSouth(void);
bool8 ForcedMovement_WalkNorth(void);
bool8 ForcedMovement_WalkWest(void);
bool8 ForcedMovement_WalkEast(void);
bool8 ForcedMovement_PushedSouthByCurrent(void);
bool8 ForcedMovement_PushedNorthByCurrent(void);
bool8 ForcedMovement_PushedWestByCurrent(void);
bool8 ForcedMovement_PushedEastByCurrent(void);
bool8 ForcedMovement_SlideSouth(void);
bool8 ForcedMovement_SlideNorth(void);
bool8 ForcedMovement_SlideWest(void);
bool8 ForcedMovement_SlideEast(void);
bool8 ForcedMovement_0xBB(void);
bool8 ForcedMovement_0xBC(void);
bool8 ForcedMovement_MuddySlope(void);

void task_add_bump_boulder(u8, u8);
u8 GetLedgeJumpDirection(s16 x, s16 y, u8 z);
bool32 CheckForRotatingGatePuzzleCollisionWithoutAnimation(u8, s16, s16); // from rotating_gate.c
bool8 ShouldJumpLedge(s16, s16, u8);
bool8 sub_808B1BC(s16, s16, u8);
u8 sub_808B164(struct EventObject *, s16, s16, u8, u8);
u8 CheckForEventObjectCollision(struct EventObject *, s16, s16, u8, u8);
u8 sub_808B238(s16, s16, u8);
void check_acro_bike_metatile(s16, s16, u8, u8 *);
void PlayerNotOnBikeCollide(u8);
void PlayerNotOnBikeCollideWithFarawayIslandMew(u8);
bool8 IsPlayerCollidingWithFarawayIslandMew(u8);
void PlayerRun(u8);
void PlayerTurnInPlace(u8);
void PlayerFaceDirection(u8);
u8 GetPlayerFacingDirection(void);
void MovePlayerNotOnBike(u8, u16);
u8 CheckMovementInputNotOnBike(u8);
u8 GetPlayerMovementDirection(void);
void sub_808C5B0(void);
void sub_808C4D8(void);
void PlayerJumpLedge(u8);
u8 CheckForPlayerAvatarCollision(u8);
void PlayerGoSpeed1(u8);
void PlayerGoSpeed2(u8);
void PlayerGoSpeed3(u8);
static u8 EventObjectCB2_NoMovement2();
void sub_808C280(struct EventObject *); //struct EventObject *playerEventObj
bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *, u8);
void npc_clear_strange_bits(struct EventObject *);
u8 EventObjectGetHeldMovementActionId(struct EventObject *);
void DoPlayerAvatarTransition(void);
bool8 TryDoMetatileBehaviorForcedMovement();
void MovePlayerAvatarUsingKeypadInput(u8, u16, u16);
void PlayerAllowForcedMovementIfMovingSameDirection();
void MovePlayerNotOnBike(u8 a, u16 b);
u8 sub_808B028(u8);
u8 GetForcedMovementByMetatileBehavior();
void PlayerNotOnBikeNotMoving(u8, u16);
void PlayerNotOnBikeTurningInPlace(u8, u16);
void PlayerNotOnBikeMoving(u8, u16);
void sub_808C750(u8);

static bool8 (*const gUnknown_084973FC[])(u8) =
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
static bool8 (*const gUnknown_08497444[])(void) =
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

void MovementType_Player(struct Sprite *sprite)
{
	UpdateEventObjectCurrentMovement(&gEventObjects[sprite->data[0]], sprite, EventObjectCB2_NoMovement2);
}

static u8 EventObjectCB2_NoMovement2()
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

bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *playerEventObj, u8 direction)
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
        if (heldMovementActionId > 24 && heldMovementActionId < 29)
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

void MovePlayerAvatarUsingKeypadInput(u8 direction, u16 newKeys, u16 heldKeys)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
     || (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE))
        MovePlayerOnBike(direction, newKeys, heldKeys);
    else
        MovePlayerNotOnBike(direction, heldKeys);
}

void PlayerAllowForcedMovementIfMovingSameDirection(void)
{
    if (gPlayerAvatar.runningState == MOVING)
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_5;
}

bool8 TryDoMetatileBehaviorForcedMovement()
{
	return gUnknown_08497444[GetForcedMovementByMetatileBehavior()]();
}

u8 GetForcedMovementByMetatileBehavior(void)
{
    u8 i;

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_5))
    {
        u8 metatileBehavior = gEventObjects[gPlayerAvatar.eventObjectId].currentMetatileBehavior;

        for (i = 0; i < 18; i++)
        {
            if (gUnknown_084973FC[i](metatileBehavior))
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

void MovePlayerNotOnBike(u8 direction, u16 heldKeys)
{
    gUnknown_08497490[CheckMovementInputNotOnBike(direction)](direction, heldKeys);
}

u8 CheckMovementInputNotOnBike(u8 direction)
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

void PlayerNotOnBikeNotMoving(u8 direction, u16 heldKeys)
{
    PlayerFaceDirection(GetPlayerFacingDirection());
}

void PlayerNotOnBikeTurningInPlace(u8 direction, u16 heldKeys)
{
    PlayerTurnInPlace(direction);
}

void PlayerNotOnBikeMoving(u8 direction, u16 heldKeys)
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

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_4) && (heldKeys & B_BUTTON) && FlagGet(FLAG_SYS_B_DASH)
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

u8 CheckForPlayerAvatarCollision(u8 direction)
{
    s16 x, y;
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    x = playerEventObj->currentCoords.x;
    y = playerEventObj->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return CheckForEventObjectCollision(playerEventObj, x, y, direction, MapGridGetMetatileBehaviorAt(x, y));
}

u8 sub_808B028(u8 direction)
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

u8 sub_808B164(struct EventObject *a, s16 x, s16 y, u8 direction, u8 e)
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

bool8 sub_808B1BC(s16 x, s16 y, u8 direction)
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

bool8 ShouldJumpLedge(s16 x, s16 y, u8 z)
{
    if (GetLedgeJumpDirection(x, y, z) != 0)
        return TRUE;
    else
        return FALSE;
}

u8 sub_808B238(s16 x, s16 y, u8 direction)
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

void check_acro_bike_metatile(s16 unused1, s16 unused2, u8 c, u8 *d)
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
