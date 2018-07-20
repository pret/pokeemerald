	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start MovePlayerNotOnBike
@ void MovePlayerNotOnBike(u8 direction, u8 heldKeys)
MovePlayerNotOnBike: @ 808AE68
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =gUnknown_08497490
	adds r0, r4, 0
	bl CheckMovementInputNotOnBike
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MovePlayerNotOnBike

	thumb_func_start CheckMovementInputNotOnBike
@ u8 CheckMovementInputNotOnBike(u8 direction)
CheckMovementInputNotOnBike: @ 808AE98
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0808AEB0
	ldr r0, =gPlayerAvatar
	strb r4, [r0, 0x2]
	movs r0, 0
	b _0808AED2
	.pool
_0808AEB0:
	bl GetPlayerMovementDirection
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _0808AECC
	ldr r1, =gPlayerAvatar
	ldrb r0, [r1, 0x2]
	cmp r0, 0x2
	beq _0808AECC
	movs r0, 0x1
	b _0808AED0
	.pool
_0808AECC:
	ldr r1, =gPlayerAvatar
	movs r0, 0x2
_0808AED0:
	strb r0, [r1, 0x2]
_0808AED2:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMovementInputNotOnBike

	thumb_func_start PlayerNotOnBikeNotMoving
@ void PlayerNotOnBikeNotMoving(u8 direction, u8 heldKeys)
PlayerNotOnBikeNotMoving: @ 808AEDC
	push {lr}
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	bl PlayerFaceDirection
	pop {r0}
	bx r0
	thumb_func_end PlayerNotOnBikeNotMoving

	thumb_func_start PlayerNotOnBikeTurningInPlace
@ void PlayerNotOnBikeTurningInPlace(u8 direction, u8 heldKeys)
PlayerNotOnBikeTurningInPlace: @ 808AEF0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl PlayerTurnInPlace
	pop {r0}
	bx r0
	thumb_func_end PlayerNotOnBikeTurningInPlace

	thumb_func_start PlayerNotOnBikeMoving
@ void PlayerNotOnBikeMoving(u8 direction, u8 heldKeys)
PlayerNotOnBikeMoving: @ 808AF00
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	adds r0, r5, 0
	bl CheckForPlayerAvatarCollision
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0808AF4E
	cmp r4, 0x6
	bne _0808AF24
	adds r0, r5, 0
	bl PlayerJumpLedge
	b _0808AFB6
_0808AF24:
	cmp r4, 0x4
	bne _0808AF3C
	adds r0, r5, 0
	bl IsPlayerCollidingWithFarawayIslandMew
	lsls r0, 24
	cmp r0, 0
	beq _0808AF3C
	adds r0, r5, 0
	bl PlayerNotOnBikeCollideWithFarawayIslandMew
	b _0808AFB6
_0808AF3C:
	subs r0, r4, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0808AFB6
	adds r0, r5, 0
	bl PlayerNotOnBikeCollide
	b _0808AFB6
_0808AF4E:
	ldr r4, =gPlayerAvatar
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0808AF68
	adds r0, r5, 0
	bl PlayerGoSpeed2
	b _0808AFB6
	.pool
_0808AF68:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0808AFB0
	movs r0, 0x2
	ands r6, r0
	cmp r6, 0
	beq _0808AFB0
	movs r0, 0x8C
	lsls r0, 4
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0808AFB0
	ldr r2, =gEventObjects
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1E]
	bl IsRunningDisallowed
	cmp r0, 0
	bne _0808AFB0
	adds r0, r5, 0
	bl PlayerRun
	ldrb r1, [r4]
	movs r0, 0x80
	orrs r0, r1
	strb r0, [r4]
	b _0808AFB6
	.pool
_0808AFB0:
	adds r0, r5, 0
	bl PlayerGoSpeed1
_0808AFB6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end PlayerNotOnBikeMoving

	thumb_func_start CheckForPlayerAvatarCollision
CheckForPlayerAvatarCollision: @ 808AFBC
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	ldrh r1, [r4, 0x10]
	add r0, sp, 0x4
	strh r1, [r0]
	ldrh r0, [r4, 0x12]
	mov r5, sp
	adds r5, 0x6
	strh r0, [r5]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	bl MoveCoords
	add r0, sp, 0x4
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	add r1, sp, 0x4
	movs r3, 0
	ldrsh r1, [r1, r3]
	movs r3, 0
	ldrsh r2, [r5, r3]
	str r0, [sp]
	adds r0, r4, 0
	adds r3, r6, 0
	bl CheckForEventObjectCollision
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckForPlayerAvatarCollision

	thumb_func_start sub_808B028
sub_808B028: @ 808B028
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	ldrh r1, [r4, 0x10]
	add r0, sp, 0x4
	strh r1, [r0]
	ldrh r0, [r4, 0x12]
	mov r5, sp
	adds r5, 0x6
	strh r0, [r5]
	adds r0, r6, 0
	add r1, sp, 0x4
	adds r2, r5, 0
	bl MoveCoords
	add r0, sp, 0x4
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	add r1, sp, 0x4
	movs r3, 0
	ldrsh r1, [r1, r3]
	movs r3, 0
	ldrsh r2, [r5, r3]
	str r0, [sp]
	adds r0, r4, 0
	adds r3, r6, 0
	bl sub_808B164
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808B028

	thumb_func_start CheckForEventObjectCollision
@ u8 CheckForEventObjectCollision(struct npc_state *eventObject, u16 x, u16 y, u8 direction, u8 metatileBehavior)
CheckForEventObjectCollision: @ 808B094
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	lsls r1, 16
	lsls r2, 16
	lsls r3, 24
	lsrs r6, r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	lsrs r7, r1, 16
	asrs r5, r1, 16
	lsrs r1, r2, 16
	mov r9, r1
	asrs r4, r2, 16
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl GetCollisionAtCoords
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	cmp r0, 0x3
	bne _0808B0E4
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_808B1BC
	lsls r0, 24
	cmp r0, 0
	beq _0808B0E4
	movs r0, 0x5
	b _0808B152
_0808B0E4:
	lsls r5, r7, 16
	asrs r0, r5, 16
	mov r8, r0
	mov r1, r9
	lsls r4, r1, 16
	asrs r7, r4, 16
	adds r1, r7, 0
	adds r2, r6, 0
	bl ShouldJumpLedge
	lsls r0, 24
	cmp r0, 0
	beq _0808B108
	movs r0, 0x2B
	bl IncrementGameStat
	movs r0, 0x6
	b _0808B152
_0808B108:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0808B124
	mov r0, r8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_808B238
	lsls r0, 24
	cmp r0, 0
	beq _0808B124
	movs r0, 0x7
	b _0808B152
_0808B124:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0808B14E
	asrs r5, 16
	asrs r4, 16
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl CheckForRotatingGatePuzzleCollision
	cmp r0, 0
	beq _0808B142
	movs r0, 0x8
	b _0808B152
_0808B142:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r10
	mov r3, sp
	bl check_acro_bike_metatile
_0808B14E:
	mov r0, sp
	ldrb r0, [r0]
_0808B152:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckForEventObjectCollision

	thumb_func_start sub_808B164
sub_808B164: @ 808B164
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r4, [sp, 0x18]
	lsls r3, 24
	lsrs r6, r3, 24
	lsls r4, 24
	lsrs r7, r4, 24
	lsls r1, 16
	asrs r5, r1, 16
	lsls r2, 16
	asrs r4, r2, 16
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl GetCollisionAtCoords
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	cmp r0, 0
	bne _0808B1AE
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl CheckForRotatingGatePuzzleCollisionWithoutAnimation
	cmp r0, 0
	beq _0808B1A2
	movs r0, 0x8
	b _0808B1B2
_0808B1A2:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, sp
	bl check_acro_bike_metatile
_0808B1AE:
	mov r0, sp
	ldrb r0, [r0]
_0808B1B2:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808B164

	thumb_func_start sub_808B1BC
@ bool8 sub_808B1BC(u16 x, u16 y, u8 direction)
sub_808B1BC: @ 808B1BC
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0808B20C
	lsls r5, r3, 16
	asrs r0, r5, 16
	lsls r4, 16
	asrs r1, r4, 16
	bl MapGridGetZCoordAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0808B20C
	lsrs r0, r5, 16
	lsrs r1, r4, 16
	movs r2, 0x3
	bl GetEventObjectIdByXYZ
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bne _0808B20C
	adds r0, r6, 0
	bl sub_808C750
	movs r0, 0x1
	b _0808B20E
	.pool
_0808B20C:
	movs r0, 0
_0808B20E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808B1BC

	thumb_func_start ShouldJumpLedge
@ bool8 ShouldJumpLedge(s16 x, s16 y, u8 direction)
ShouldJumpLedge: @ 808B214
	push {lr}
	lsls r2, 24
	lsrs r2, 24
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl GetLedgeJumpDirection
	lsls r0, 24
	cmp r0, 0
	bne _0808B230
	movs r0, 0
	b _0808B232
_0808B230:
	movs r0, 0x1
_0808B232:
	pop {r1}
	bx r1
	thumb_func_end ShouldJumpLedge

	thumb_func_start sub_808B238
sub_808B238: @ 808B238
	push {r4-r7,lr}
	sub sp, 0x4
	mov r3, sp
	strh r0, [r3]
	mov r5, sp
	adds r5, 0x2
	strh r1, [r5]
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r0, =0x00000889
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0808B2D8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl GetEventObjectIdByXY
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x10
	beq _0808B2D8
	ldr r0, =gEventObjects
	lsls r1, r6, 3
	adds r1, r6
	lsls r1, 2
	adds r4, r1, r0
	ldrb r0, [r4, 0x5]
	cmp r0, 0x57
	bne _0808B2D8
	ldrh r1, [r4, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r4, 0x12]
	strh r0, [r5]
	adds r0, r7, 0
	mov r1, sp
	adds r2, r5, 0
	bl MoveCoords
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r3, r7, 0
	bl GetCollisionAtCoords
	lsls r0, 24
	cmp r0, 0
	bne _0808B2D8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsNonAnimDoor
	lsls r0, 24
	cmp r0, 0
	bne _0808B2D8
	adds r0, r6, 0
	adds r1, r7, 0
	bl task_add_bump_boulder
	movs r0, 0x1
	b _0808B2DA
	.pool
_0808B2D8:
	movs r0, 0
_0808B2DA:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808B238

	thumb_func_start check_acro_bike_metatile
@ void check_acro_bike_metatile(s16 x, s16 y, u8 metatileBehavior, u8 *returnValue)
check_acro_bike_metatile: @ 808B2E4
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r2, 24
	lsrs r5, r2, 24
	movs r4, 0
	ldr r7, =gUnknown_0849749C
_0808B2F0:
	lsls r0, r4, 2
	adds r0, r7
	ldr r1, [r0]
	adds r0, r5, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0808B314
	ldr r0, =gUnknown_084974B0
	adds r0, r4, r0
	ldrb r0, [r0]
	strb r0, [r6]
	b _0808B31E
	.pool
_0808B314:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _0808B2F0
_0808B31E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end check_acro_bike_metatile

	thumb_func_start IsPlayerCollidingWithFarawayIslandMew
@ bool8 IsPlayerCollidingWithFarawayIslandMew(u8 direction)
IsPlayerCollidingWithFarawayIslandMew: @ 808B324
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerAvatar
	ldrb r2, [r1, 0x5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	ldr r5, =gEventObjects
	adds r3, r1, r5
	ldrh r2, [r3, 0x10]
	mov r1, sp
	strh r2, [r1]
	ldrh r1, [r3, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r1, [r4]
	mov r1, sp
	adds r2, r4, 0
	bl MoveCoords
	movs r0, 0x1
	movs r1, 0x39
	movs r2, 0x1A
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r1, r0, 24
	adds r6, r4, 0
	cmp r1, 0x10
	beq _0808B3C0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r5
	mov r0, sp
	movs r1, 0x14
	ldrsh r2, [r3, r1]
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r2, r0
	bne _0808B3C0
	movs r5, 0x16
	ldrsh r1, [r3, r5]
	movs r4, 0
	ldrsh r0, [r6, r4]
	ldrh r4, [r3, 0x16]
	cmp r1, r0
	bne _0808B398
	movs r5, 0x10
	ldrsh r0, [r3, r5]
	cmp r0, r2
	bne _0808B398
	movs r2, 0x12
	ldrsh r0, [r3, r2]
	cmp r0, r1
	beq _0808B3C0
_0808B398:
	mov r0, sp
	movs r5, 0x14
	ldrsh r1, [r3, r5]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0808B3C0
	lsls r0, r4, 16
	asrs r0, 16
	movs r4, 0
	ldrsh r1, [r6, r4]
	cmp r0, r1
	bne _0808B3C0
	movs r0, 0x1
	b _0808B3C2
	.pool
_0808B3C0:
	movs r0, 0
_0808B3C2:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end IsPlayerCollidingWithFarawayIslandMew

	thumb_func_start SetPlayerAvatarTransitionFlags
@ void SetPlayerAvatarTransitionFlags(u16 transitionFlags)
SetPlayerAvatarTransitionFlags: @ 808B3CC
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x1]
	orrs r0, r1
	strb r0, [r2, 0x1]
	bl DoPlayerAvatarTransition
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetPlayerAvatarTransitionFlags

	thumb_func_start DoPlayerAvatarTransition
@ void DoPlayerAvatarTransition()
DoPlayerAvatarTransition: @ 808B3E8
	push {r4,r5,lr}
	ldr r0, =gPlayerAvatar
	ldrb r4, [r0, 0x1]
	cmp r4, 0
	beq _0808B428
	movs r5, 0
_0808B3F4:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0808B416
	ldr r0, =gUnknown_084974B8
	lsls r2, r5, 2
	adds r2, r0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	ldr r1, [r2]
	bl _call_via_r1
_0808B416:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	lsrs r4, 1
	cmp r5, 0x7
	bls _0808B3F4
	ldr r1, =gPlayerAvatar
	movs r0, 0
	strb r0, [r1, 0x1]
_0808B428:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoPlayerAvatarTransition

	thumb_func_start PlayerAvatarTransition_Dummy
@ void PlayerAvatarTransition_Dummy(struct npc_state *eventObject)
PlayerAvatarTransition_Dummy: @ 808B43C
	bx lr
	thumb_func_end PlayerAvatarTransition_Dummy

	thumb_func_start PlayerAvatarTransition_Normal
@ void PlayerAvatarTransition_Normal(struct npc_state *eventObject)
PlayerAvatarTransition_Normal: @ 808B440
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	movs r0, 0x1
	bl SetPlayerAvatarStateMask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerAvatarTransition_Normal

	thumb_func_start PlayerAvatarTransition_MachBike
@ void PlayerAvatarTransition_MachBike(struct npc_state *eventObject)
PlayerAvatarTransition_MachBike: @ 808B46C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	movs r0, 0x2
	bl SetPlayerAvatarStateMask
	movs r0, 0
	movs r1, 0
	bl BikeClearState
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerAvatarTransition_MachBike

	thumb_func_start PlayerAvatarTransition_AcroBike
@ void PlayerAvatarTransition_AcroBike(struct npc_state *eventObject)
PlayerAvatarTransition_AcroBike: @ 808B4A0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	movs r0, 0x4
	bl SetPlayerAvatarStateMask
	movs r0, 0
	movs r1, 0
	bl BikeClearState
	bl Bike_HandleBumpySlopeJump
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerAvatarTransition_AcroBike

	thumb_func_start PlayerAvatarTransition_Surfing
@ void PlayerAvatarTransition_Surfing(struct npc_state *eventObject)
PlayerAvatarTransition_Surfing: @ 808B4D8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	movs r0, 0x8
	bl SetPlayerAvatarStateMask
	ldr r1, =gFieldEffectArguments
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	str r0, [r1, 0x4]
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	str r0, [r1, 0x8]
	movs r0, 0x8
	bl FieldEffectStart
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r4, 0x1A]
	movs r1, 0x1
	bl sub_81555AC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayerAvatarTransition_Surfing

	thumb_func_start PlayerAvatarTransition_Underwater
@ void PlayerAvatarTransition_Underwater(struct npc_state *eventObject)
PlayerAvatarTransition_Underwater: @ 808B534
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x4
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	movs r0, 0x10
	bl SetPlayerAvatarStateMask
	ldrb r0, [r4, 0x4]
	bl sub_8155800
	strb r0, [r4, 0x1A]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerAvatarTransition_Underwater

	thumb_func_start PlayerAvatarTransition_ReturnToField
@ void PlayerAvatarTransition_ReturnToField(struct npc_state *eventObject)
PlayerAvatarTransition_ReturnToField: @ 808B568
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2]
	movs r0, 0x20
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end PlayerAvatarTransition_ReturnToField

	thumb_func_start sub_808B578
sub_808B578: @ 808B578
	push {r4,lr}
	ldr r4, =gPlayerAvatar
	movs r0, 0
	strb r0, [r4, 0x3]
	bl PlayerIsAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _0808B5B6
	bl PlayerCheckIfAnimFinishedOrInactive
	lsls r0, 24
	cmp r0, 0
	bne _0808B5A8
	bl player_is_anim_in_certain_ranges
	lsls r0, 24
	cmp r0, 0
	bne _0808B5B6
	movs r0, 0x1
	b _0808B5B4
	.pool
_0808B5A8:
	bl sub_808B618
	lsls r0, 24
	cmp r0, 0
	bne _0808B5B6
	movs r0, 0x2
_0808B5B4:
	strb r0, [r4, 0x3]
_0808B5B6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_808B578

	thumb_func_start player_is_anim_in_certain_ranges
player_is_anim_in_certain_ranges: @ 808B5BC
	push {lr}
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1C]
	cmp r1, 0x3
	bls _0808B602
	adds r0, r1, 0
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _0808B602
	adds r0, r1, 0
	subs r0, 0x19
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	bls _0808B602
	adds r0, r1, 0
	subs r0, 0x64
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB
	bls _0808B602
	adds r0, r1, 0
	subs r0, 0x7C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _0808B610
_0808B602:
	movs r0, 0x1
	b _0808B612
	.pool
_0808B610:
	movs r0, 0
_0808B612:
	pop {r1}
	bx r1
	thumb_func_end player_is_anim_in_certain_ranges

	thumb_func_start sub_808B618
sub_808B618: @ 808B618
	push {lr}
	bl player_is_anim_in_certain_ranges
	lsls r0, 24
	cmp r0, 0
	beq _0808B634
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x2]
	cmp r0, 0x1
	beq _0808B634
	movs r0, 0x1
	b _0808B636
	.pool
_0808B634:
	movs r0, 0
_0808B636:
	pop {r1}
	bx r1
	thumb_func_end sub_808B618

	thumb_func_start PlayerIsAnimActive
@ bool8 PlayerIsAnimActive()
PlayerIsAnimActive: @ 808B63C
	push {lr}
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	bl EventObjectIsMovementOverridden
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end PlayerIsAnimActive

	thumb_func_start PlayerCheckIfAnimFinishedOrInactive
@ bool8 PlayerCheckIfAnimFinishedOrInactive()
PlayerCheckIfAnimFinishedOrInactive: @ 808B660
	push {lr}
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	bl EventObjectCheckHeldMovementStatus
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end PlayerCheckIfAnimFinishedOrInactive

	thumb_func_start player_set_x22
player_set_x22: @ 808B684
	ldr r3, =gEventObjects
	ldr r1, =gPlayerAvatar
	ldrb r2, [r1, 0x5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	adds r1, 0x22
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end player_set_x22

	thumb_func_start PlayerGetCopyableMovement
PlayerGetCopyableMovement: @ 808B6A0
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x22
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end PlayerGetCopyableMovement

	thumb_func_start sub_808B6BC
sub_808B6BC: @ 808B6BC
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gPlayerAvatar
	ldrb r2, [r0, 0x5]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r2, =gEventObjects
	adds r0, r2
	bl EventObjectForceSetHeldMovement
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808B6BC

	thumb_func_start PlayerSetAnimId
@ void PlayerSetAnimId(u8 animState, u8 a2)
PlayerSetAnimId: @ 808B6E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	bl PlayerIsAnimActive
	lsls r0, 24
	cmp r0, 0
	bne _0808B712
	adds r0, r4, 0
	bl player_set_x22
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	adds r1, r5, 0
	bl EventObjectSetHeldMovement
_0808B712:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayerSetAnimId

	thumb_func_start PlayerGoSpeed1
@ void PlayerGoSpeed1(u8 direction)
PlayerGoSpeed1: @ 808B720
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkNormalMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerGoSpeed1

	thumb_func_start PlayerGoSpeed2
@ void PlayerGoSpeed2(u8 direction)
PlayerGoSpeed2: @ 808B738
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkFastMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerGoSpeed2

	thumb_func_start PlayerGoSpeed3
@ void PlayerGoSpeed3(u8 direction)
PlayerGoSpeed3: @ 808B750
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetRideWaterCurrentMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerGoSpeed3

	thumb_func_start PlayerGoSpeed4
@ void PlayerGoSpeed4(u8 direction)
PlayerGoSpeed4: @ 808B768
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkFastestMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerGoSpeed4

	thumb_func_start PlayerRun
@ void PlayerRun(u8 direction)
PlayerRun: @ 808B780
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetPlayerRunMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerRun

	thumb_func_start PlayerOnBikeCollide
@ void PlayerOnBikeCollide(u8 direction)
PlayerOnBikeCollide: @ 808B798
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PlayCollisionSoundIfNotFacingWarp
	adds r0, r4, 0
	bl GetWalkInPlaceNormalMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerOnBikeCollide

	thumb_func_start PlayerOnBikeCollideWithFarawayIslandMew
@ void PlayerOnBikeCollideWithFarawayIslandMew(u8 direction)
PlayerOnBikeCollideWithFarawayIslandMew: @ 808B7BC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkInPlaceNormalMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerOnBikeCollideWithFarawayIslandMew

	thumb_func_start PlayerNotOnBikeCollide
@ void PlayerNotOnBikeCollide(u8 direction)
PlayerNotOnBikeCollide: @ 808B7D4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PlayCollisionSoundIfNotFacingWarp
	adds r0, r4, 0
	bl GetWalkInPlaceSlowMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerNotOnBikeCollide

	thumb_func_start PlayerNotOnBikeCollideWithFarawayIslandMew
@ void PlayerNotOnBikeCollideWithFarawayIslandMew(u8 direction)
PlayerNotOnBikeCollideWithFarawayIslandMew: @ 808B7F8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkInPlaceSlowMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerNotOnBikeCollideWithFarawayIslandMew

	thumb_func_start PlayerFaceDirection
@ void PlayerFaceDirection(u8 direction)
PlayerFaceDirection: @ 808B810
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerFaceDirection

	thumb_func_start PlayerTurnInPlace
@ void PlayerTurnInPlace(u8 direction)
PlayerTurnInPlace: @ 808B828
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkInPlaceFastMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerTurnInPlace

	thumb_func_start PlayerJumpLedge
@ void PlayerJumpLedge(u8 direction)
PlayerJumpLedge: @ 808B840
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xA
	bl PlaySE
	adds r0, r4, 0
	bl GetJump2MovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x8
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerJumpLedge

	thumb_func_start sub_808B864
sub_808B864: @ 808B864
	push {r4,lr}
	ldr r4, =gPlayerAvatar
	ldrb r0, [r4, 0x3]
	cmp r0, 0x2
	beq _0808B872
	cmp r0, 0
	bne _0808B89A
_0808B872:
	bl player_should_look_direction_be_enforced_upon_movement
	lsls r0, 24
	cmp r0, 0
	beq _0808B89A
	ldr r2, =gEventObjects
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	bl sub_808B6BC
_0808B89A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808B864

	thumb_func_start PlayerIdleWheelie
PlayerIdleWheelie: @ 808B8A8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetAcroWheelieFaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerIdleWheelie

	thumb_func_start PlayerStartWheelie
PlayerStartWheelie: @ 808B8C0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetAcroPopWheelieFaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerStartWheelie

	thumb_func_start PlayerEndWheelie
PlayerEndWheelie: @ 808B8D8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetAcroEndWheelieFaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end PlayerEndWheelie

	thumb_func_start PlayerStandingHoppingWheelie
PlayerStandingHoppingWheelie: @ 808B8F0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x22
	bl PlaySE
	adds r0, r4, 0
	bl GetAcroWheelieHopFaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerStandingHoppingWheelie

	thumb_func_start PlayerMovingHoppingWheelie
PlayerMovingHoppingWheelie: @ 808B914
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x22
	bl PlaySE
	adds r0, r4, 0
	bl GetAcroWheelieHopDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerMovingHoppingWheelie

	thumb_func_start PlayerLedgeHoppingWheelie
PlayerLedgeHoppingWheelie: @ 808B938
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x22
	bl PlaySE
	adds r0, r4, 0
	bl GetAcroWheelieJumpDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x8
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerLedgeHoppingWheelie

	thumb_func_start PlayerAcroTurnJump
PlayerAcroTurnJump: @ 808B95C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x22
	bl PlaySE
	adds r0, r4, 0
	bl GetJumpInPlaceTurnAroundMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayerAcroTurnJump

	thumb_func_start sub_808B980
sub_808B980: @ 808B980
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x7
	bl PlaySE
	adds r0, r4, 0
	bl GetAcroWheelieInPlaceDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_808B980

	thumb_func_start sub_808B9A4
sub_808B9A4: @ 808B9A4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetAcroPopWheelieMoveDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end sub_808B9A4

	thumb_func_start sub_808B9BC
sub_808B9BC: @ 808B9BC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetAcroWheelieMoveDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end sub_808B9BC

	thumb_func_start npc_use_some_d2s
npc_use_some_d2s: @ 808B9D4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetAcroEndWheelieMoveDirectionMovementAction
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl PlayerSetAnimId
	pop {r0}
	bx r0
	thumb_func_end npc_use_some_d2s

	thumb_func_start PlayCollisionSoundIfNotFacingWarp
@ void PlayCollisionSoundIfNotFacingWarp(u8 direction)
PlayCollisionSoundIfNotFacingWarp: @ 808B9EC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1E]
	ldr r2, =gUnknown_084974D8
	subs r1, r4, 0x1
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0808BA54
	cmp r4, 0x2
	bne _0808BA4E
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	movs r0, 0x2
	mov r1, sp
	adds r2, r4, 0
	bl MoveCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsWarpDoor
	lsls r0, 24
	cmp r0, 0
	bne _0808BA54
_0808BA4E:
	movs r0, 0x7
	bl PlaySE
_0808BA54:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayCollisionSoundIfNotFacingWarp

	thumb_func_start GetXYCoordsOneStepInFrontOfPlayer
GetXYCoordsOneStepInFrontOfPlayer: @ 808BA68
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r3, =gEventObjects
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x10]
	strh r0, [r4]
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x12]
	strh r0, [r5]
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r2, r5, 0
	bl MoveCoords
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetXYCoordsOneStepInFrontOfPlayer

	thumb_func_start PlayerGetDestCoords
@ void PlayerGetDestCoords(u16 *x, u16 *y)
PlayerGetDestCoords: @ 808BAAC
	push {r4,r5,lr}
	ldr r5, =gEventObjects
	ldr r4, =gPlayerAvatar
	ldrb r3, [r4, 0x5]
	lsls r2, r3, 3
	adds r2, r3
	lsls r2, 2
	adds r2, r5
	ldrh r2, [r2, 0x10]
	strh r2, [r0]
	ldrb r2, [r4, 0x5]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x12]
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlayerGetDestCoords

	thumb_func_start plaer_get_pos_including_state_based_drift
plaer_get_pos_including_state_based_drift: @ 808BADC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	beq _0808BAFC
	b _0808BC24
_0808BAFC:
	ldr r2, =gSprites
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0808BB12
	b _0808BC24
_0808BB12:
	ldrh r0, [r3, 0x10]
	strh r0, [r4]
	ldrh r0, [r3, 0x12]
	strh r0, [r5]
	ldrb r0, [r3, 0x1C]
	subs r0, 0x8
	cmp r0, 0x30
	bls _0808BB24
	b _0808BC24
_0808BB24:
	lsls r0, 2
	ldr r1, =_0808BB40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0808BB40:
	.4byte _0808BC04
	.4byte _0808BC0A
	.4byte _0808BC14
	.4byte _0808BC1A
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC24
	.4byte _0808BC04
	.4byte _0808BC0A
	.4byte _0808BC14
	.4byte _0808BC1A
_0808BC04:
	ldrh r0, [r5]
	adds r0, 0x1
	b _0808BC0E
_0808BC0A:
	ldrh r0, [r5]
	subs r0, 0x1
_0808BC0E:
	strh r0, [r5]
	movs r0, 0x1
	b _0808BC30
_0808BC14:
	ldrh r0, [r4]
	subs r0, 0x1
	b _0808BC1E
_0808BC1A:
	ldrh r0, [r4]
	adds r0, 0x1
_0808BC1E:
	strh r0, [r4]
	movs r0, 0x1
	b _0808BC30
_0808BC24:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r4]
	strh r0, [r5]
	movs r0, 0
_0808BC30:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end plaer_get_pos_including_state_based_drift

	thumb_func_start GetPlayerFacingDirection
@ u8 GetPlayerFacingDirection()
GetPlayerFacingDirection: @ 808BC38
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bx lr
	.pool
	thumb_func_end GetPlayerFacingDirection

	thumb_func_start GetPlayerMovementDirection
@ u8 GetPlayerMovementDirection()
GetPlayerMovementDirection: @ 808BC58
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	lsrs r0, 4
	bx lr
	.pool
	thumb_func_end GetPlayerMovementDirection

	thumb_func_start PlayerGetZCoord
@ u8 PlayerGetZCoord()
PlayerGetZCoord: @ 808BC74
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xB]
	lsrs r0, 4
	bx lr
	.pool
	thumb_func_end PlayerGetZCoord

	thumb_func_start sub_808BC90
sub_808BC90: @ 808BC90
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	lsls r3, 16
	asrs r3, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r3, 0
	bl sub_808EB08
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808BC90

	thumb_func_start TestPlayerAvatarFlags
@ u32 TestPlayerAvatarFlags(u32 mask)
TestPlayerAvatarFlags: @ 808BCC0
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1]
	ands r1, r0
	adds r0, r1, 0
	bx lr
	.pool
	thumb_func_end TestPlayerAvatarFlags

	thumb_func_start sub_808BCD0
sub_808BCD0: @ 808BCD0
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_808BCD0

	thumb_func_start GetPlayerAvatarObjectId
@ u8 GetPlayerAvatarObjectId()
GetPlayerAvatarObjectId: @ 808BCDC
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end GetPlayerAvatarObjectId

	thumb_func_start sub_808BCE8
sub_808BCE8: @ 808BCE8
	push {lr}
	bl ForcedMovement_None
	pop {r0}
	bx r0
	thumb_func_end sub_808BCE8

	thumb_func_start sub_808BCF4
sub_808BCF4: @ 808BCF4
	push {r4,lr}
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	adds r0, r4, 0
	bl npc_clear_strange_bits
	ldrb r1, [r4, 0x18]
	lsls r1, 28
	lsrs r1, 28
	adds r0, r4, 0
	bl SetEventObjectDirection
	movs r0, 0x6
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _0808BD2C
	bl Bike_HandleBumpySlopeJump
	movs r0, 0
	bl Bike_UpdateBikeCounterSpeed
_0808BD2C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808BCF4

	thumb_func_start GetRivalAvatarGraphicsIdByStateIdAndGender
GetRivalAvatarGraphicsIdByStateIdAndGender: @ 808BD3C
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_084974E8
	lsrs r0, 23
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end GetRivalAvatarGraphicsIdByStateIdAndGender

	thumb_func_start GetPlayerAvatarGraphicsIdByStateIdAndGender
@ u8 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 stateId, u8 gender)
GetPlayerAvatarGraphicsIdByStateIdAndGender: @ 808BD54
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_084974F8
	lsrs r0, 23
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end GetPlayerAvatarGraphicsIdByStateIdAndGender

	thumb_func_start sub_808BD6C
sub_808BD6C: @ 808BD6C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_08497508
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_808BD6C

	thumb_func_start sub_808BD7C
sub_808BD7C: @ 808BD7C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0849750A
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_808BD7C

	thumb_func_start GetPlayerAvatarGraphicsIdByStateId
@ u8 GetPlayerAvatarGraphicsIdByStateId(u8 stateId)
GetPlayerAvatarGraphicsIdByStateId: @ 808BD8C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerAvatar
	ldrb r1, [r1, 0x7]
	bl GetPlayerAvatarGraphicsIdByStateIdAndGender
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetPlayerAvatarGraphicsIdByStateId

	thumb_func_start sub_808BDA8
sub_808BDA8: @ 808BDA8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x70
	beq _0808BDCA
	cmp r0, 0x70
	bgt _0808BDC2
	cmp r0, 0x6D
	bgt _0808BDCE
	cmp r0, 0x69
	blt _0808BDCE
	b _0808BDCA
_0808BDC2:
	cmp r1, 0x8A
	beq _0808BDCA
	cmp r1, 0xC0
	bne _0808BDCE
_0808BDCA:
	movs r0, 0x1
	b _0808BDD0
_0808BDCE:
	movs r0, 0
_0808BDD0:
	pop {r1}
	bx r1
	thumb_func_end sub_808BDA8

	thumb_func_start GetPlayerAvatarGenderByGraphicsId
@ u8 GetPlayerAvatarGenderByGraphicsId(u8 graphicsId)
GetPlayerAvatarGenderByGraphicsId: @ 808BDD4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x70
	beq _0808BDF6
	cmp r0, 0x70
	bgt _0808BDEE
	cmp r0, 0x5D
	bgt _0808BDFA
	cmp r0, 0x59
	blt _0808BDFA
	b _0808BDF6
_0808BDEE:
	cmp r1, 0x8A
	beq _0808BDF6
	cmp r1, 0xC0
	bne _0808BDFA
_0808BDF6:
	movs r0, 0x1
	b _0808BDFC
_0808BDFA:
	movs r0, 0
_0808BDFC:
	pop {r1}
	bx r1
	thumb_func_end GetPlayerAvatarGenderByGraphicsId

	thumb_func_start PartyHasMonWithSurf
@ bool8 PartyHasMonWithSurf()
PartyHasMonWithSurf: @ 808BE00
	push {r4,r5,lr}
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	bne _0808BE44
	movs r5, 0
	b _0808BE2A
_0808BE12:
	adds r0, r4, 0
	movs r1, 0x39
	bl pokemon_has_move
	lsls r0, 24
	cmp r0, 0
	beq _0808BE24
	movs r0, 0x1
	b _0808BE46
_0808BE24:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0808BE2A:
	cmp r5, 0x5
	bhi _0808BE44
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	bne _0808BE12
_0808BE44:
	movs r0, 0
_0808BE46:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end PartyHasMonWithSurf

	thumb_func_start IsPlayerSurfingNorth
@ bool8 IsPlayerSurfingNorth()
IsPlayerSurfingNorth: @ 808BE50
	push {lr}
	bl GetPlayerMovementDirection
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0808BE6E
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _0808BE6E
	movs r0, 0x1
	b _0808BE70
_0808BE6E:
	movs r0, 0
_0808BE70:
	pop {r1}
	bx r1
	thumb_func_end IsPlayerSurfingNorth

	thumb_func_start IsPlayerFacingSurfableFishableWater
@ bool8 IsPlayerFacingSurfableFishableWater()
IsPlayerFacingSurfableFishableWater: @ 808BE74
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	ldrh r1, [r4, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r4, 0x12]
	mov r5, sp
	adds r5, 0x2
	strh r0, [r5]
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	mov r1, sp
	adds r2, r5, 0
	bl MoveCoords
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0
	ldrsh r2, [r5, r0]
	ldrb r3, [r4, 0x18]
	lsls r3, 28
	lsrs r3, 28
	adds r0, r4, 0
	bl GetCollisionAtCoords
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0808BEF4
	bl PlayerGetZCoord
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0808BEF4
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsSurfableFishableWater
	lsls r0, 24
	cmp r0, 0
	beq _0808BEF4
	movs r0, 0x1
	b _0808BEF6
	.pool
_0808BEF4:
	movs r0, 0
_0808BEF6:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end IsPlayerFacingSurfableFishableWater

	thumb_func_start ClearPlayerAvatarInfo
@ void ClearPlayerAvatarInfo()
ClearPlayerAvatarInfo: @ 808BF00
	push {lr}
	ldr r0, =gPlayerAvatar
	movs r1, 0
	movs r2, 0x24
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearPlayerAvatarInfo

	thumb_func_start SetPlayerAvatarStateMask
@ void SetPlayerAvatarStateMask(u8 stateMask)
SetPlayerAvatarStateMask: @ 808BF14
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gPlayerAvatar
	ldrb r2, [r3]
	movs r1, 0xE0
	ands r1, r2
	orrs r0, r1
	strb r0, [r3]
	bx lr
	.pool
	thumb_func_end SetPlayerAvatarStateMask

	thumb_func_start GetPlayerAvatarStateTransitionByGraphicsId
@ u8 GetPlayerAvatarStateTransitionByGraphicsId(u8 graphicsId, u8 gender)
GetPlayerAvatarStateTransitionByGraphicsId: @ 808BF2C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	ldr r3, =gUnknown_0849750C
	lsls r0, r1, 2
	adds r0, r1
	lsls r4, r0, 1
	adds r6, r3, 0x1
_0808BF42:
	lsls r0, r2, 1
	adds r1, r0, r4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r5
	bne _0808BF58
	adds r0, r1, r6
	ldrb r0, [r0]
	b _0808BF64
	.pool
_0808BF58:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x4
	bls _0808BF42
	movs r0, 0x1
_0808BF64:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetPlayerAvatarStateTransitionByGraphicsId

	thumb_func_start GetPlayerAvatarGraphicsIdByCurrentState
@ u8 GetPlayerAvatarGraphicsIdByCurrentState()
GetPlayerAvatarGraphicsIdByCurrentState: @ 808BF6C
	push {r4-r6,lr}
	ldr r0, =gPlayerAvatar
	ldrb r5, [r0]
	movs r2, 0
	ldr r3, =gUnknown_0849750C
	ldrb r1, [r0, 0x7]
	lsls r0, r1, 2
	adds r0, r1
	lsls r4, r0, 1
	adds r6, r3, 0x1
_0808BF80:
	lsls r0, r2, 1
	adds r1, r0, r4
	adds r0, r1, r6
	ldrb r0, [r0]
	ands r0, r5
	cmp r0, 0
	beq _0808BF9C
	adds r0, r1, r3
	ldrb r0, [r0]
	b _0808BFA8
	.pool
_0808BF9C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x4
	bls _0808BF80
	movs r0, 0
_0808BFA8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetPlayerAvatarGraphicsIdByCurrentState

	thumb_func_start SetPlayerAvatarExtraStateTransition
@ void SetPlayerAvatarExtraStateTransition(u8 graphicsId, u8 state)
SetPlayerAvatarExtraStateTransition: @ 808BFB0
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gPlayerAvatar
	ldrb r1, [r5, 0x7]
	bl GetPlayerAvatarStateTransitionByGraphicsId
	lsls r0, 24
	lsrs r0, 24
	orrs r0, r4
	ldrb r1, [r5, 0x1]
	orrs r0, r1
	strb r0, [r5, 0x1]
	bl DoPlayerAvatarTransition
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetPlayerAvatarExtraStateTransition

	thumb_func_start InitPlayerAvatar
@ void InitPlayerAvatar(u16 x, u16 y, u8 direction, u8 gender)
InitPlayerAvatar: @ 808BFE0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x18
	adds r4, r0, 0
	adds r5, r1, 0
	mov r9, r2
	mov r8, r3
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0
	mov r1, r8
	bl GetPlayerAvatarGraphicsIdByStateIdAndGender
	mov r1, sp
	movs r3, 0
	strb r0, [r1, 0x1]
	mov r0, sp
	lsls r4, 16
	asrs r4, 16
	subs r4, 0x7
	movs r6, 0
	strh r4, [r0, 0x4]
	lsls r5, 16
	asrs r5, 16
	subs r5, 0x7
	strh r5, [r0, 0x6]
	strb r6, [r0, 0x8]
	movs r0, 0xB
	strb r0, [r1, 0x9]
	mov r2, sp
	ldrb r1, [r2, 0xA]
	subs r0, 0x1B
	ands r0, r1
	strb r0, [r2, 0xA]
	mov r0, sp
	strb r6, [r0, 0xA]
	strh r3, [r0, 0xC]
	strh r3, [r0, 0xE]
	str r3, [sp, 0x10]
	strh r3, [r0, 0x14]
	bl SpawnSpecialEventObject
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 3
	adds r4, r5
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	ldrb r0, [r4, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x2]
	bl sub_8154228
	strb r0, [r4, 0x1B]
	adds r0, r4, 0
	mov r1, r9
	bl EventObjectTurn
	bl ClearPlayerAvatarInfo
	ldr r0, =gPlayerAvatar
	strb r6, [r0, 0x2]
	strb r6, [r0, 0x3]
	strb r5, [r0, 0x5]
	ldrb r1, [r4, 0x4]
	strb r1, [r0, 0x4]
	mov r1, r8
	strb r1, [r0, 0x7]
	movs r0, 0x21
	bl SetPlayerAvatarStateMask
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitPlayerAvatar

	thumb_func_start sub_808C0A8
sub_808C0A8: @ 808C0A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gEventObjects
	ldr r5, =gPlayerAvatar
	ldrb r0, [r5, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r0, 0x1
	ands r4, r0
	lsls r3, r4, 5
	ldrb r2, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x1]
	movs r0, 0x8
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _0808C100
	ldr r2, =gSprites
	ldrb r1, [r5, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x1A]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	lsls r3, r4, 2
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
_0808C100:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C0A8

	thumb_func_start sub_808C114
sub_808C114: @ 808C114
	push {r4,r5,lr}
	ldr r5, =gPlayerAvatar
	ldrb r0, [r5, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	movs r0, 0x5
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C114

	thumb_func_start sub_808C15C
sub_808C15C: @ 808C15C
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gPlayerAvatar
	ldrb r0, [r6, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	movs r0, 0x6
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r0, [r6, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r5, 0
	bl GetFishingDirectionAnimNum
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C15C

	thumb_func_start sub_808C1B4
sub_808C1B4: @ 808C1B4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gPlayerAvatar
	ldrb r0, [r6, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	movs r0, 0x2
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r0, [r6, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	mov r8, r0
	add r4, r8
	adds r0, r5, 0
	bl GetAcroWheelieDirectionAnimNum
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrb r1, [r6, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	movs r1, 0x1
	bl SeekSpriteAnim
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C1B4

	thumb_func_start sub_808C228
sub_808C228: @ 808C228
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gPlayerAvatar
	ldrb r0, [r6, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	adds r4, r0
	movs r0, 0x7
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r0, [r6, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r5, 0
	bl GetFaceDirectionAnimNum
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C228

	thumb_func_start sub_808C280
@ void sub_808C280(struct EventObject *playerEventObj);
sub_808C280: @ 808C280
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrb r0, [r5, 0x1E]
	mov r8, r0
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	movs r6, 0x1
	ldr r1, =gUnknown_08497520
	mov r9, r1
	mov r4, sp
	mov r7, sp
	adds r7, 0x2
_0808C2A2:
	movs r1, 0
	ldrsh r0, [r4, r1]
	lsls r0, 2
	add r0, r9
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0808C2E8
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	cmp r6, r0
	bne _0808C2E8
	ldrh r0, [r5, 0x10]
	strh r0, [r4]
	ldrh r0, [r5, 0x12]
	strh r0, [r7]
	adds r0, r6, 0
	mov r1, sp
	adds r2, r7, 0
	bl MoveCoords
	ldrb r0, [r5, 0x1B]
	movs r1, 0
	ldrsh r2, [r4, r1]
	movs r1, 0
	ldrsh r3, [r7, r1]
	adds r1, r6, 0
	bl sub_8154298
	b _0808C302
	.pool
_0808C2E8:
	ldrh r1, [r4]
	adds r1, 0x1
	strh r1, [r4]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3
	ble _0808C2A2
	ldrb r0, [r5, 0x1B]
	bl objid_set_invisible
_0808C302:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808C280

	thumb_func_start task_add_bump_boulder
task_add_bump_boulder: @ 808C310
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =taskFF_bump_boulder
	adds r0, r6, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xA]
	strh r5, [r1, 0xC]
	bl _call_via_r6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_add_bump_boulder

	thumb_func_start taskFF_bump_boulder
taskFF_bump_boulder: @ 808C34C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_08497530
	ldr r2, =gTasks
	ldr r5, =gEventObjects
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0808C360:
	movs r0, 0x8
	ldrsh r3, [r4, r0]
	lsls r3, 2
	adds r3, r6
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 2
	adds r2, r5
	ldr r3, [r3]
	adds r0, r4, 0
	bl _call_via_r3
	lsls r0, 24
	cmp r0, 0
	bne _0808C360
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end taskFF_bump_boulder

	thumb_func_start sub_808C3A4
sub_808C3A4: @ 808C3A4
	push {r4,lr}
	adds r4, r0, 0
	bl ScriptContext2_Enable
	ldr r1, =gPlayerAvatar
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C3A4

	thumb_func_start do_boulder_dust
@ int do_boulder_dust(int a1, struct npc_state *a2, struct npc_state *a3)
do_boulder_dust: @ 808C3C4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r0, r5, 0
	bl EventObjectIsHeldMovementActive
	lsls r0, 24
	cmp r0, 0
	beq _0808C3DE
	adds r0, r5, 0
	bl EventObjectClearHeldMovementIfFinished
_0808C3DE:
	adds r0, r4, 0
	bl EventObjectIsHeldMovementActive
	lsls r0, 24
	cmp r0, 0
	beq _0808C3F0
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
_0808C3F0:
	adds r0, r5, 0
	bl EventObjectIsMovementOverridden
	lsls r0, 24
	cmp r0, 0
	bne _0808C472
	adds r0, r4, 0
	bl EventObjectIsMovementOverridden
	lsls r0, 24
	cmp r0, 0
	bne _0808C472
	adds r0, r5, 0
	bl EventObjectClearHeldMovementIfFinished
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	ldrb r0, [r6, 0xC]
	bl GetWalkInPlaceNormalMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl EventObjectSetHeldMovement
	ldrb r0, [r6, 0xC]
	bl GetWalkSlowMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetHeldMovement
	ldr r2, =gFieldEffectArguments
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	str r0, [r2]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	str r0, [r2, 0x4]
	ldrb r0, [r4, 0xB]
	lsrs r0, 4
	str r0, [r2, 0x8]
	ldr r3, =gSprites
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r2, 0xC]
	movs r0, 0xA
	bl FieldEffectStart
	movs r0, 0xD6
	bl PlaySE
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_0808C472:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end do_boulder_dust

	thumb_func_start sub_808C484
sub_808C484: @ 808C484
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl EventObjectCheckHeldMovementStatus
	lsls r0, 24
	cmp r0, 0
	beq _0808C4C6
	adds r0, r5, 0
	bl EventObjectCheckHeldMovementStatus
	lsls r0, 24
	cmp r0, 0
	beq _0808C4C6
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	adds r0, r5, 0
	bl EventObjectClearHeldMovementIfFinished
	ldr r1, =gPlayerAvatar
	movs r0, 0
	strb r0, [r1, 0x6]
	bl ScriptContext2_Disable
	ldr r0, =taskFF_bump_boulder
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0808C4C6:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C484

	thumb_func_start sub_808C4D8
sub_808C4D8: @ 808C4D8
	push {r4,lr}
	ldr r4, =sub_808C4F8
	adds r0, r4, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C4D8

	thumb_func_start sub_808C4F8
sub_808C4F8: @ 808C4F8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0849753C
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0808C50A:
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	lsls r2, 2
	adds r2, r5
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r1, r0
	ldr r2, [r2]
	adds r0, r4, 0
	bl _call_via_r2
	lsls r0, 24
	cmp r0, 0
	bne _0808C50A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C4F8

	thumb_func_start sub_808C544
sub_808C544: @ 808C544
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, =gPlayerAvatar
	movs r0, 0x1
	strb r0, [r5, 0x6]
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808C5A0
	movs r0, 0xA
	bl PlaySE
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetJumpInPlaceMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetHeldMovement
	ldrh r0, [r6, 0xA]
	adds r0, 0x1
	strh r0, [r6, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0808C5A0
	movs r0, 0
	strb r0, [r5, 0x6]
	ldrb r0, [r5, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldr r0, =sub_808C4F8
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0808C5A0:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C544

	thumb_func_start sub_808C5B0
sub_808C5B0: @ 808C5B0
	push {r4,lr}
	ldr r4, =sub_808C5D0
	adds r0, r4, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C5B0

	thumb_func_start sub_808C5D0
sub_808C5D0: @ 808C5D0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_08497540
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0808C5E2:
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	lsls r2, 2
	adds r2, r5
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r1, r0
	ldr r2, [r2]
	adds r0, r4, 0
	bl _call_via_r2
	lsls r0, 24
	cmp r0, 0
	bne _0808C5E2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C5D0

	thumb_func_start sub_808C61C
sub_808C61C: @ 808C61C
	push {lr}
	ldrh r2, [r0, 0x8]
	adds r2, 0x1
	strh r2, [r0, 0x8]
	ldrb r1, [r1, 0x18]
	lsrs r1, 4
	strh r1, [r0, 0xA]
	ldr r1, =gPlayerAvatar
	movs r0, 0x1
	strb r0, [r1, 0x6]
	bl ScriptContext2_Enable
	movs r0, 0x2D
	bl PlaySE
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C61C

	thumb_func_start sub_808C644
sub_808C644: @ 808C644
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, =gUnknown_08497550
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	adds r0, r5, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808C6AC
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	subs r0, 0x1
	add r0, sp
	ldrb r6, [r0]
	adds r0, r6, 0
	bl GetFaceDirectionMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl EventObjectSetHeldMovement
	ldrb r0, [r4, 0xA]
	cmp r6, r0
	bne _0808C68A
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
_0808C68A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _0808C6AC
	ldrb r0, [r4, 0xA]
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _0808C6AC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0808C6AC:
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C644

	thumb_func_start sub_808C6BC
sub_808C6BC: @ 808C6BC
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, =gUnknown_08497554
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808C6EC
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	add r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	bl EventObjectSetHeldMovement
	movs r0, 0x1
	strh r0, [r5, 0x8]
_0808C6EC:
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C6BC

	thumb_func_start sub_808C6FC
sub_808C6FC: @ 808C6FC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808C740
	ldrb r0, [r4, 0xA]
	bl GetOppositeDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetWalkSlowMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl EventObjectSetHeldMovement
	bl ScriptContext2_Disable
	ldr r1, =gPlayerAvatar
	movs r0, 0
	strb r0, [r1, 0x6]
	ldr r0, =sub_808C5D0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0808C740:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808C6FC

	thumb_func_start sub_808C750
sub_808C750: @ 808C750
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ScriptContext2_Enable
	bl Overworld_ClearSavedMusic
	bl Overworld_ChangeMusicToDefault
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2]
	movs r0, 0xF7
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x1
	strb r0, [r2, 0x6]
	ldr r5, =taskFF_0805D1D4
	adds r0, r5, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	bl _call_via_r5
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C750

	thumb_func_start taskFF_0805D1D4
taskFF_0805D1D4: @ 808C7A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r5, r0, r1
	adds r0, r5, 0
	bl EventObjectIsMovementOverridden
	lsls r0, 24
	cmp r0, 0
	beq _0808C7D4
	adds r0, r5, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808C7FC
_0808C7D4:
	ldrb r0, [r5, 0x1A]
	movs r1, 0x2
	bl sub_81555AC
	ldr r0, =gTasks
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r0
	ldrb r0, [r4, 0x8]
	bl GetJumpSpecialMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl EventObjectSetHeldMovement
	ldr r0, =sub_808C814
	str r0, [r4]
_0808C7FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end taskFF_0805D1D4

	thumb_func_start sub_808C814
sub_808C814: @ 808C814
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gPlayerAvatar
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808C87A
	movs r0, 0
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetFaceDirectionMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetHeldMovement
	movs r0, 0
	strb r0, [r6, 0x6]
	bl ScriptContext2_Disable
	ldrb r1, [r4, 0x1A]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r5, 0
	bl DestroyTask
_0808C87A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808C814

	thumb_func_start StartFishing
StartFishing: @ 808C88C
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =Task_Fish
	adds r0, r5, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x26]
	bl _call_via_r5
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end StartFishing

	thumb_func_start Task_Fish
Task_Fish: @ 808C8C0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0849755C
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0808C8D2:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0808C8D2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_Fish

	thumb_func_start fish0
fish0: @ 808C8F8
	push {r4,lr}
	adds r4, r0, 0
	bl ScriptContext2_Enable
	ldr r1, =gPlayerAvatar
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish0

	thumb_func_start fish1
fish1: @ 808C918
	push {r4-r6,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r1, =gUnknown_0849759C
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	add r4, sp, 0x8
	ldr r1, =gUnknown_084975A2
	adds r0, r4, 0
	movs r2, 0x6
	bl memcpy
	movs r0, 0
	strh r0, [r5, 0x20]
	bl Random
	movs r2, 0x26
	ldrsh r1, [r5, r2]
	lsls r1, 1
	mov r2, sp
	adds r6, r2, r1
	lsls r0, 16
	lsrs r0, 16
	adds r4, r1
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl __modsi3
	ldrh r1, [r6]
	adds r1, r0
	strh r1, [r5, 0x22]
	ldr r3, =gEventObjects
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x5]
	strh r0, [r5, 0x24]
	ldrb r0, [r2, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	adds r4, r3
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfActive
	ldrb r0, [r4, 0x1]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_808C15C
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish1

	thumb_func_start fish2
fish2: @ 808C9B0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_808CF78
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3B
	ble _0808C9CC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0808C9CC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end fish2

	thumb_func_start fish3
fish3: @ 808C9D4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x1
	bl sub_819786C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xA]
	strh r1, [r4, 0xC]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	adds r1, r0, 0
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0808CA0C
	adds r0, r1, 0x4
	strh r0, [r4, 0xE]
_0808CA0C:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	ble _0808CA18
	movs r0, 0xA
	strh r0, [r4, 0xE]
_0808CA18:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end fish3

	thumb_func_start fish4
fish4: @ 808CA20
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r1, =gUnknown_084975A8
	add r0, sp, 0xC
	movs r2, 0x2
	bl memcpy
	bl sub_808CF78
	ldrh r0, [r4, 0xA]
	adds r1, r0, 0x1
	strh r1, [r4, 0xA]
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	movs r5, 0x1
	adds r2, r5, 0
	ands r2, r0
	cmp r2, 0
	beq _0808CA64
	movs r0, 0xB
	strh r0, [r4, 0x8]
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0808CA58
	movs r0, 0xC
	strh r0, [r4, 0x8]
_0808CA58:
	movs r0, 0x1
	b _0808CAB4
	.pool
_0808CA64:
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0808CAB2
	strh r2, [r4, 0xA]
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _0808CA94
	ldrh r0, [r4, 0x8]
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	ldrh r2, [r4, 0x20]
	movs r3, 0x20
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0808CA8E
	adds r0, r1, 0x1
	strh r0, [r4, 0x8]
_0808CA8E:
	adds r0, r2, 0x1
	strh r0, [r4, 0x20]
	b _0808CAB2
_0808CA94:
	movs r0, 0xC
	ldrsh r3, [r4, r0]
	lsls r3, 27
	lsrs r3, 24
	str r5, [sp]
	str r2, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl PrintTextOnWindow
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
_0808CAB2:
	movs r0, 0
_0808CAB4:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end fish4

	thumb_func_start fish5
fish5: @ 808CABC
	push {r4-r6,lr}
	adds r5, r0, 0
	bl sub_808CF78
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r6, 0
	bl DoesCurrentMapHaveFishingMons
	lsls r0, 24
	cmp r0, 0
	bne _0808CADC
	movs r0, 0xB
	strh r0, [r5, 0x8]
	b _0808CB5C
_0808CADC:
	ldr r4, =gPlayerParty
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _0808CB14
	adds r0, r4, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x15
	beq _0808CAFC
	cmp r0, 0x3C
	bne _0808CB14
_0808CAFC:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xE
	bls _0808CB14
	movs r6, 0x1
_0808CB14:
	cmp r6, 0
	bne _0808CB32
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0808CB30
	movs r0, 0xB
	strh r0, [r5, 0x8]
	b _0808CB32
	.pool
_0808CB30:
	movs r6, 0x1
_0808CB32:
	cmp r6, 0x1
	bne _0808CB5C
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFishingBiteDirectionAnimNum
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
_0808CB5C:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish5

	thumb_func_start fish6
fish6: @ 808CB6C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	bl sub_808CF78
	ldr r2, =gText_OhABite
	movs r0, 0x11
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	strh r4, [r5, 0xA]
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish6

	thumb_func_start fish7
fish7: @ 808CBA4
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_084975AA
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	bl sub_808CF78
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r0, 1
	add r0, sp
	lsls r1, 16
	asrs r1, 16
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _0808CBDC
	movs r0, 0xC
	b _0808CBEC
	.pool
_0808CBDC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808CBEE
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
_0808CBEC:
	strh r0, [r4, 0x8]
_0808CBEE:
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish7

	thumb_func_start fish8
fish8: @ 808CBFC
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r1, =gUnknown_084975B0
	mov r0, sp
	movs r2, 0xC
	bl memcpy
	bl sub_808CF78
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _0808CC52
	cmp r1, 0x1
	bgt _0808CC56
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	movs r3, 0x20
	ldrsh r2, [r4, r3]
	lsls r2, 1
	movs r3, 0x26
	ldrsh r1, [r4, r3]
	lsls r1, 2
	adds r2, r1
	mov r3, sp
	adds r1, r3, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	ble _0808CC56
_0808CC52:
	movs r0, 0x3
	strh r0, [r4, 0x8]
_0808CC56:
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish8

	thumb_func_start fish9
fish9: @ 808CC64
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	bl sub_808CF78
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_PokemonOnHook
	movs r5, 0
	str r5, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	strh r5, [r4, 0xA]
	movs r0, 0
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fish9

	thumb_func_start fishA_wait_for_a_pressed
fishA_wait_for_a_pressed: @ 808CCA8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0808CCBC
	bl sub_808CF78
_0808CCBC:
	bl RunTextPrinters
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0808CD58
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0
	bne _0808CD50
	ldr r7, =gPlayerAvatar
	ldrb r0, [r7, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	mov r8, r0
	add r4, r8
	ldrh r1, [r5, 0x24]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	ldrb r1, [r7]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0808CD1A
	ldrb r0, [r7, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r0, [r1, 0x1A]
	movs r1, 0
	movs r2, 0
	bl sub_8155604
_0808CD1A:
	ldr r2, =gSprites
	ldrb r1, [r7, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r6, [r0, 0x24]
	ldrb r1, [r7, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r6, [r0, 0x26]
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	b _0808CD80
	.pool
_0808CD50:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0808CD80
_0808CD58:
	ldr r1, =gPlayerAvatar
	movs r0, 0
	strb r0, [r1, 0x6]
	bl ScriptContext2_Disable
	ldrh r0, [r5, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl FishingWildEncounter
	movs r0, 0x1
	bl sub_80ED950
	ldr r0, =Task_Fish
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0808CD80:
	movs r0, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fishA_wait_for_a_pressed

	thumb_func_start fishB
fishB: @ 808CD94
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	bl sub_808CF78
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFishingNoCatchDirectionAnimNum
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_NotEvenANibble
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized
	movs r0, 0xD
	strh r0, [r5, 0x8]
	movs r0, 0x1
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fishB

	thumb_func_start fishC
fishC: @ 808CE04
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	bl sub_808CF78
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	bl GetFishingNoCatchDirectionAnimNum
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_ItGotAway
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fishC

	thumb_func_start fishD
fishD: @ 808CE74
	push {r4,lr}
	adds r4, r0, 0
	bl sub_808CF78
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end fishD

	thumb_func_start fishE
fishE: @ 808CE8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	bl sub_808CF78
	ldr r7, =gSprites
	ldr r5, =gPlayerAvatar
	ldrb r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3F
	ldrb r0, [r1]
	lsls r0, 27
	cmp r0, 0
	bge _0808CF12
	ldrb r0, [r5, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gEventObjects
	mov r8, r0
	add r4, r8
	ldrh r1, [r6, 0x24]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectSetGraphicsId
	ldrb r1, [r4, 0x18]
	lsrs r1, 4
	adds r0, r4, 0
	bl EventObjectTurn
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0808CEF2
	ldrb r0, [r5, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r0, [r1, 0x1A]
	movs r1, 0
	movs r2, 0
	bl sub_8155604
_0808CEF2:
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r2, 0
	strh r2, [r0, 0x24]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x26]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_0808CF12:
	movs r0, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end fishE

	thumb_func_start fishF
fishF: @ 808CF2C
	push {lr}
	bl RunTextPrinters
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _0808CF68
	ldr r0, =gPlayerAvatar
	strb r1, [r0, 0x6]
	bl ScriptContext2_Disable
	bl UnfreezeEventObjects
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	movs r0, 0
	bl sub_80ED950
	ldr r0, =Task_Fish
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0808CF68:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end fishF

	thumb_func_start sub_808CF78
sub_808CF78: @ 808CF78
	push {r4-r7,lr}
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r4, 0
	bl AnimateSprite
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r5, [r0]
	movs r0, 0x2A
	adds r0, r4
	mov r12, r0
	ldrb r0, [r0]
	ldr r1, [r4, 0x8]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r6, r5, 2
	adds r0, r6, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r7, 0x1
	negs r7, r7
	cmp r0, r7
	beq _0808CFEA
	adds r3, r4, 0
	adds r3, 0x2C
	ldrb r2, [r3]
	lsls r1, r2, 26
	lsrs r1, 26
	adds r1, 0x1
	movs r0, 0x3F
	ands r1, r0
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r1, r12
	ldrb r0, [r1]
	ldr r1, [r4, 0x8]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	adds r0, r6, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, r7
	bne _0808CFF0
_0808CFEA:
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0808CFF0:
	adds r0, r4, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	ldr r1, [r4, 0x8]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r1
	ldrb r5, [r0]
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _0808D022
	movs r0, 0x8
	strh r0, [r4, 0x24]
	bl GetPlayerFacingDirection
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0808D022
	ldr r0, =0x0000fff8
	strh r0, [r4, 0x24]
_0808D022:
	cmp r5, 0x5
	bne _0808D02A
	ldr r0, =0x0000fff8
	strh r0, [r4, 0x26]
_0808D02A:
	adds r0, r5, 0
	subs r0, 0xA
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0808D03A
	movs r0, 0x8
	strh r0, [r4, 0x26]
_0808D03A:
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0808D05E
	ldr r2, =gEventObjects
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1A]
	movs r1, 0x26
	ldrsh r2, [r4, r1]
	movs r1, 0x1
	bl sub_8155604
_0808D05E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808CF78

	thumb_func_start sub_808D074
sub_808D074: @ 808D074
	ldr r1, =gUnknown_0203734C
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_808D074

	thumb_func_start sub_808D080
sub_808D080: @ 808D080
	push {lr}
	ldr r1, =gUnknown_0203734C
	ldrb r0, [r1]
	cmp r0, 0
	bne _0808D08C
	movs r0, 0x1
_0808D08C:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808D080

	thumb_func_start sub_808D094
sub_808D094: @ 808D094
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r7, r0, r1
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0
	ldrsh r6, [r5, r0]
	cmp r6, 0x1
	beq _0808D14A
	cmp r6, 0x1
	bgt _0808D0E8
	cmp r6, 0
	beq _0808D0EE
	b _0808D18A
	.pool
_0808D0E8:
	cmp r6, 0x2
	beq _0808D184
	b _0808D18A
_0808D0EE:
	adds r0, r4, 0
	bl EventObjectClearHeldMovementIfFinished
	lsls r0, 24
	cmp r0, 0
	beq _0808D18A
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_808D074
	movs r1, 0
	mov r8, r1
	strh r6, [r5, 0x2]
	movs r0, 0x1
	strh r0, [r5, 0x4]
	ldrh r0, [r7, 0x26]
	ldrh r2, [r7, 0x22]
	adds r0, r2
	lsls r0, 4
	strh r0, [r5, 0x6]
	strh r6, [r7, 0x26]
	bl CameraObjectReset2
	ldrb r0, [r4, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r7, 0x5]
	adds r0, r7, 0
	adds r0, 0x43
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_0808D14A:
	adds r1, r5, 0x2
	adds r0, r4, 0
	bl sub_808D38C
	ldrh r0, [r5, 0x6]
	ldrh r1, [r5, 0x4]
	subs r0, r1
	strh r0, [r5, 0x6]
	adds r1, 0x3
	strh r1, [r5, 0x4]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r7, 0x22]
	movs r2, 0x22
	ldrsh r1, [r7, r2]
	ldr r0, =gUnknown_03005DE8
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r1, r0
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	bge _0808D18A
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _0808D18A
	.pool
_0808D184:
	adds r0, r2, 0
	bl DestroyTask
_0808D18A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808D094

	thumb_func_start sub_808D194
sub_808D194: @ 808D194
	push {r4,lr}
	ldr r4, =sub_808D1FC
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808D194

	thumb_func_start sub_808D1B4
sub_808D1B4: @ 808D1B4
	push {lr}
	ldr r0, =sub_808D1FC
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808D1B4

	thumb_func_start sub_808D1C8
sub_808D1C8: @ 808D1C8
	push {r4,lr}
	ldr r4, =sub_808D094
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808D1C8

	thumb_func_start sub_808D1E8
sub_808D1E8: @ 808D1E8
	push {lr}
	ldr r0, =sub_808D094
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808D1E8

	thumb_func_start sub_808D1FC
sub_808D1FC: @ 808D1FC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r4, r0, r1
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r7, r0, r1
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r2, 0
	ldrsh r6, [r5, r2]
	cmp r6, 0x1
	beq _0808D2DE
	cmp r6, 0x1
	bgt _0808D254
	cmp r6, 0
	beq _0808D25E
	b _0808D37E
	.pool
_0808D254:
	cmp r6, 0x2
	beq _0808D31C
	cmp r6, 0x3
	beq _0808D33A
	b _0808D37E
_0808D25E:
	bl sub_808D080
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	ldr r1, =gUnknown_084975BC
	movs r3, 0xA
	ldrsh r0, [r5, r3]
	adds r0, r1
	ldrb r0, [r0]
	bl GetFaceDirectionMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl EventObjectForceSetHeldMovement
	movs r0, 0
	mov r9, r0
	strh r6, [r5, 0x2]
	movs r0, 0x74
	strh r0, [r5, 0x4]
	ldrh r0, [r7, 0x22]
	strh r0, [r5, 0x8]
	ldrb r0, [r7, 0x5]
	lsls r0, 28
	lsrs r0, 30
	strh r0, [r5, 0xC]
	movs r1, 0x43
	adds r1, r7
	mov r8, r1
	ldrb r0, [r1]
	strh r0, [r5, 0xE]
	ldrh r0, [r7, 0x26]
	adds r0, 0x20
	negs r0, r0
	lsls r0, 4
	strh r0, [r5, 0x6]
	strh r6, [r7, 0x26]
	bl CameraObjectReset2
	ldrb r0, [r4, 0x3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r4, 0x3]
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r7, 0x5]
	mov r3, r9
	mov r2, r8
	strb r3, [r2]
	adds r2, r7, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_0808D2DE:
	adds r1, r5, 0x2
	adds r0, r4, 0
	bl sub_808D38C
	ldrh r0, [r5, 0x4]
	ldrh r2, [r5, 0x6]
	adds r1, r0, r2
	strh r1, [r5, 0x6]
	subs r0, 0x3
	strh r0, [r5, 0x4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bgt _0808D2FE
	movs r0, 0x4
	strh r0, [r5, 0x4]
_0808D2FE:
	ldrh r0, [r5, 0x6]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r7, 0x22]
	ldrh r2, [r5, 0x8]
	movs r3, 0x8
	ldrsh r1, [r5, r3]
	cmp r0, r1
	blt _0808D37E
	strh r2, [r7, 0x22]
	movs r0, 0
	strh r0, [r5, 0x10]
	b _0808D332
	.pool
_0808D31C:
	adds r1, r5, 0x2
	adds r0, r4, 0
	bl sub_808D38C
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	strh r0, [r5, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0808D37E
_0808D332:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	b _0808D37E
_0808D33A:
	movs r0, 0xA
	ldrsh r6, [r5, r0]
	adds r1, r5, 0x2
	adds r0, r4, 0
	bl sub_808D38C
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _0808D37E
	ldrb r1, [r4, 0x3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x3]
	movs r0, 0x3
	ldrb r1, [r5, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x5]
	ldrh r1, [r5, 0xE]
	adds r0, r7, 0
	adds r0, 0x43
	strb r1, [r0]
	bl CameraObjectReset1
	mov r0, r8
	bl DestroyTask
_0808D37E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808D1FC

	thumb_func_start sub_808D38C
sub_808D38C: @ 808D38C
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldrh r1, [r6]
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0x7
	bgt _0808D3A8
	adds r0, r1, 0x1
	strh r0, [r6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0808D3E4
_0808D3A8:
	adds r0, r5, 0
	bl EventObjectCheckHeldMovementStatus
	lsls r0, 24
	cmp r0, 0
	beq _0808D3E4
	ldr r4, =gUnknown_084975BC
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	adds r0, r4
	ldrb r0, [r0]
	bl GetFaceDirectionMovementAction
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl EventObjectForceSetHeldMovement
	movs r0, 0
	strh r0, [r6]
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	adds r0, r4
	ldrb r0, [r0]
	b _0808D3EA
	.pool
_0808D3E4:
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
_0808D3EA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808D38C

	.align 2, 0 @ Don't pad with nop.
