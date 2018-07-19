#include "global.h"
#include "global.fieldmap.h"
#include "sprite.h"
#include "event_object_movement.h"
#include "bike.h"

static u8 EventObjectCB2_NoMovement2();
void sub_808C280(struct EventObject *); //struct EventObject *playerEventObj
bool8 TryInterruptEventObjectSpecialAnim(struct EventObject *, u8);
void npc_clear_strange_bits(struct EventObject *);
void DoPlayerAvatarTransition(void);
bool8 TryDoMetatileBehaviorForcedMovement();
void MovePlayerAvatarUsingKeypadInput(u8, u16, u16);
void PlayerAllowForcedMovementIfMovingSameDirection();

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
