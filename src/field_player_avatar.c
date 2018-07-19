#include "global.h"
#include "global.fieldmap.h"
#include "sprite.h"
#include "event_object_movement.h"
#include "bike.h"

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
