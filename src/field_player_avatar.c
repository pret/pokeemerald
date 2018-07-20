#include "global.h"
#include "global.fieldmap.h"
#include "sprite.h"
#include "event_object_movement.h"
#include "bike.h"

extern bool8 (*const gUnknown_08497444[])(void);
extern bool8 (*const gUnknown_084973FC[])(u8);

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

void MovementType_Player(struct Sprite *sprite)
{
	// ((Sprite->data[0] << 3) + Sprite->data[0]) << 2
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

NAKED
bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *eventObject, u8 direction)
{
	asm_unified("push {r4-r6,lr}\n\
	adds r4, r0, 0\n\
	lsls r1, 24\n\
	lsrs r5, r1, 24\n\
	adds r6, r5, 0\n\
	bl EventObjectIsMovementOverridden\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _0808AA92\n\
	adds r0, r4, 0\n\
	bl EventObjectClearHeldMovementIfFinished\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	bne _0808AA92\n\
	adds r0, r4, 0\n\
	bl EventObjectGetHeldMovementActionId\n\
	lsls r0, 24\n\
	movs r1, 0xE7\n\
	lsls r1, 24\n\
	adds r0, r1\n\
	lsrs r0, 24\n\
	cmp r0, 0x3\n\
	bhi _0808AA70\n\
	cmp r5, 0\n\
	bne _0808AA74\n\
_0808AA70:\n\
	movs r0, 0x1\n\
	b _0808AA94\n\
_0808AA74:\n\
	ldrb r0, [r4, 0x18]\n\
	lsrs r0, 4\n\
	cmp r0, r5\n\
	beq _0808AA84\n\
_0808AA7C:\n\
	adds r0, r4, 0\n\
	bl EventObjectClearHeldMovement\n\
	b _0808AA92\n\
_0808AA84:\n\
	adds r0, r6, 0\n\
	bl sub_808B028\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _0808AA7C\n\
	b _0808AA70\n\
_0808AA92:\n\
	movs r0, 0\n\
_0808AA94:\n\
	pop {r4-r6}\n\
	pop {r1}\n\
	bx r1");
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
