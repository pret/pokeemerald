	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start MovePlayerOnBike
@ void MovePlayerOnBike(int dpad_direction, int buttons_new, int buttons_held)
MovePlayerOnBike: @ 8119164
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0811918C
	adds r0, r3, 0
	adds r1, r4, 0
	bl MovePlayerOnMachBike
	b _08119194
	.pool
_0811918C:
	adds r0, r3, 0
	adds r1, r4, 0
	bl MovePlayerOnAcroBike
_08119194:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end MovePlayerOnBike

	thumb_func_start MovePlayerOnMachBike
MovePlayerOnMachBike: @ 811919C
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	strb r0, [r1]
	ldr r4, =gUnknown_0859744C
	mov r0, sp
	bl CheckMovementInputMachBike
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	mov r1, sp
	ldrb r1, [r1]
	ldr r2, [r0]
	adds r0, r1, 0
	bl _call_via_r2
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MovePlayerOnMachBike

	thumb_func_start CheckMovementInputMachBike
CheckMovementInputMachBike: @ 81191CC
	push {r4,lr}
	adds r4, r0, 0
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	ldrb r1, [r4]
	cmp r1, 0
	bne _081191F4
	strb r0, [r4]
	ldr r2, =gPlayerAvatar
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _08119208
	strb r1, [r2, 0x2]
	movs r0, 0
	b _0811921C
	.pool
_081191F4:
	ldr r2, =gPlayerAvatar
	cmp r1, r3
	beq _08119218
	ldrb r0, [r2, 0x2]
	cmp r0, 0x2
	beq _08119218
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _08119214
	strb r3, [r4]
_08119208:
	movs r0, 0x2
	strb r0, [r2, 0x2]
	movs r0, 0x3
	b _0811921C
	.pool
_08119214:
	movs r0, 0x1
	b _0811921A
_08119218:
	movs r0, 0x2
_0811921A:
	strb r0, [r2, 0x2]
_0811921C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end CheckMovementInputMachBike

	thumb_func_start sub_8119224
sub_8119224: @ 8119224
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl PlayerFaceDirection
	bl sub_811A128
	pop {r0}
	bx r0
	thumb_func_end sub_8119224

	thumb_func_start sub_8119238
sub_8119238: @ 8119238
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	ldrb r1, [r4, 0x1E]
	adds r0, r5, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	beq _08119270
	adds r0, r5, 0
	bl PlayerTurnInPlace
	bl sub_811A128
	b _0811927A
	.pool
_08119270:
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl sub_8119224
_0811927A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8119238

	thumb_func_start sub_8119280
sub_8119280: @ 8119280
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	ldr r6, =gPlayerAvatar
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	ldrb r1, [r4, 0x1E]
	adds r0, r5, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _081192C6
	ldrb r0, [r6, 0xB]
	cmp r0, 0
	beq _081192BC
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl sub_8119344
	b _0811933A
	.pool
_081192BC:
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl sub_8119224
	b _0811933A
_081192C6:
	adds r0, r5, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0xA
	bhi _08119316
	cmp r4, 0x6
	bne _081192E8
	adds r0, r5, 0
	bl PlayerJumpLedge
	b _0811933A
_081192E8:
	bl sub_811A128
	cmp r4, 0x4
	bne _08119304
	adds r0, r5, 0
	bl IsPlayerCollidingWithFarawayIslandMew
	lsls r0, 24
	cmp r0, 0
	beq _08119304
	adds r0, r5, 0
	bl PlayerOnBikeCollideWithFarawayIslandMew
	b _0811933A
_08119304:
	subs r0, r4, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0811933A
	adds r0, r7, 0
	bl PlayerOnBikeCollide
	b _0811933A
_08119316:
	ldr r1, =gUnknown_0859745C
	ldrb r0, [r6, 0xA]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r7, 0
	bl _call_via_r1
	ldrb r2, [r6, 0xA]
	lsls r0, r2, 24
	lsrs r1, r0, 24
	lsrs r0, 25
	adds r0, r2, r0
	strb r0, [r6, 0xB]
	cmp r1, 0x1
	bhi _0811933A
	adds r0, r2, 0x1
	strb r0, [r6, 0xA]
_0811933A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119280

	thumb_func_start sub_8119344
sub_8119344: @ 8119344
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	ldr r6, =gPlayerAvatar
	ldrb r0, [r6, 0xB]
	cmp r0, 0
	beq _0811935A
	subs r0, 0x1
	strb r0, [r6, 0xB]
	strb r0, [r6, 0xA]
_0811935A:
	adds r0, r5, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0xA
	bhi _081193AE
	cmp r4, 0x6
	bne _08119380
	adds r0, r5, 0
	bl PlayerJumpLedge
	b _081193BE
	.pool
_08119380:
	bl sub_811A128
	cmp r4, 0x4
	bne _0811939C
	adds r0, r5, 0
	bl IsPlayerCollidingWithFarawayIslandMew
	lsls r0, 24
	cmp r0, 0
	beq _0811939C
	adds r0, r5, 0
	bl PlayerOnBikeCollideWithFarawayIslandMew
	b _081193BE
_0811939C:
	subs r0, r4, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _081193BE
	adds r0, r7, 0
	bl PlayerOnBikeCollide
	b _081193BE
_081193AE:
	ldr r0, =gUnknown_0859745C
	ldrb r1, [r6, 0xA]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r7, 0
	bl _call_via_r1
_081193BE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119344

	thumb_func_start MovePlayerOnAcroBike
@ void MovePlayerOnAcroBike(int dpad_direction, int buttons_new, int buttons_held)
MovePlayerOnAcroBike: @ 81193C8
	push {r4,lr}
	sub sp, 0x4
	mov r3, sp
	strb r0, [r3]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gUnknown_08597468
	mov r0, sp
	bl CheckMovementInputAcroBike
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	mov r1, sp
	ldrb r1, [r1]
	ldr r2, [r0]
	adds r0, r1, 0
	bl _call_via_r2
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MovePlayerOnAcroBike

	thumb_func_start CheckMovementInputAcroBike
CheckMovementInputAcroBike: @ 8119400
	push {r4,lr}
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gUnknown_0859749C
	ldr r3, =gPlayerAvatar
	ldrb r3, [r3, 0x8]
	lsls r3, 2
	adds r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMovementInputAcroBike

	thumb_func_start CheckMovementInputAcroBikeNormal
CheckMovementInputAcroBikeNormal: @ 811942C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gPlayerAvatar
	movs r0, 0
	strb r0, [r2, 0xA]
	ldrb r1, [r4]
	cmp r1, 0
	bne _0811946C
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _08119464
	strb r3, [r4]
	strb r1, [r2, 0x2]
	movs r0, 0x2
	strb r0, [r2, 0x8]
	movs r0, 0x3
	b _081194C0
	.pool
_08119464:
	strb r3, [r4]
	strb r1, [r2, 0x2]
	movs r0, 0
	b _081194C0
_0811946C:
	cmp r1, r3
	bne _08119492
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	beq _0811948A
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0811948A
	adds r0, 0x1
	strb r0, [r2, 0xB]
	movs r0, 0x4
	strb r0, [r2, 0x8]
	movs r0, 0xB
	b _081194C0
_0811948A:
	ldrb r0, [r4]
	ldr r2, =gPlayerAvatar
	cmp r0, r3
	beq _081194BC
_08119492:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x2]
	adds r2, r0, 0
	cmp r1, 0x2
	beq _081194BC
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x8]
	ldrb r0, [r4]
	strb r0, [r2, 0x9]
	strb r1, [r2, 0x2]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl CheckMovementInputAcroBike
	lsls r0, 24
	lsrs r0, 24
	b _081194C0
	.pool
_081194BC:
	movs r0, 0x2
	strb r0, [r2, 0x2]
_081194C0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CheckMovementInputAcroBikeNormal

	thumb_func_start CheckMovementInputAcroBikeChangingDirection
CheckMovementInputAcroBikeChangingDirection: @ 81194C8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gPlayerAvatar
	ldrb r0, [r4, 0x9]
	strb r0, [r5]
	ldrb r0, [r4, 0xA]
	adds r0, 0x1
	strb r0, [r4, 0xA]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bls _081194F4
	movs r0, 0x1
	strb r0, [r4, 0x2]
	movs r0, 0
	strb r0, [r4, 0x8]
	bl sub_811A128
	movs r0, 0x1
	b _0811953A
	.pool
_081194F4:
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_8119D30
	ldrb r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _08119536
	bl sub_811A128
	movs r0, 0x1
	strb r0, [r4, 0xB]
	adds r0, r6, 0
	bl GetOppositeDirection
	ldrb r1, [r5]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0811952A
	movs r0, 0x6
	strb r0, [r4, 0x8]
	movs r0, 0x9
	b _0811953A
_0811952A:
	movs r0, 0x2
	strb r0, [r4, 0x2]
	movs r0, 0x5
	strb r0, [r4, 0x8]
	movs r0, 0x8
	b _0811953A
_08119536:
	strb r6, [r5]
	movs r0, 0
_0811953A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CheckMovementInputAcroBikeChangingDirection

	thumb_func_start CheckMovementInputAcroBikeStandingWheelie
CheckMovementInputAcroBikeStandingWheelie: @ 8119540
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r4, r2, 16
	lsrs r4, 16
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gPlayerAvatar
	ldrb r1, [r5, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r1, r0, r1
	movs r0, 0
	strb r0, [r5, 0x2]
	movs r0, 0x2
	ands r4, r0
	lsls r4, 16
	lsrs r4, 16
	cmp r4, 0
	bne _08119594
	strb r4, [r5, 0xA]
	ldrb r0, [r1, 0x1E]
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0811959A
	strb r6, [r7]
	strb r0, [r5, 0x8]
	bl sub_811A128
	movs r0, 0x4
	b _081195D8
	.pool
_08119594:
	ldrb r0, [r5, 0xA]
	adds r0, 0x1
	strb r0, [r5, 0xA]
_0811959A:
	ldr r1, =gPlayerAvatar
	ldrb r0, [r1, 0xA]
	cmp r0, 0x27
	bls _081195B4
	strb r6, [r7]
	movs r0, 0x3
	strb r0, [r1, 0x8]
	bl sub_811A128
	movs r0, 0x6
	b _081195D8
	.pool
_081195B4:
	ldrb r0, [r7]
	cmp r0, r6
	bne _081195CA
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_811A128
	movs r0, 0xA
	b _081195D8
_081195CA:
	cmp r0, 0
	beq _081195D4
	movs r0, 0x1
	strb r0, [r1, 0x2]
	b _081195D6
_081195D4:
	strb r6, [r7]
_081195D6:
	movs r0, 0x5
_081195D8:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckMovementInputAcroBikeStandingWheelie

	thumb_func_start CheckMovementInputAcroBikeBunnyHop
CheckMovementInputAcroBikeBunnyHop: @ 81195E0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	ldr r4, =gPlayerAvatar
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r7, r0, r1
	movs r0, 0x2
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _08119652
	bl sub_811A128
	ldrb r0, [r7, 0x1E]
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08119648
	movs r0, 0x2
	strb r0, [r4, 0x8]
	adds r0, r6, 0
	mov r1, r9
	mov r2, r8
	bl CheckMovementInputAcroBike
	lsls r0, 24
	lsrs r0, 24
	b _08119676
	.pool
_08119648:
	strb r5, [r6]
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x8]
	movs r0, 0x4
	b _08119676
_08119652:
	ldrb r0, [r6]
	cmp r0, 0
	bne _0811965C
	strb r5, [r6]
	b _08119668
_0811965C:
	cmp r0, r2
	beq _0811966E
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _0811966E
	movs r0, 0x1
_08119668:
	strb r0, [r4, 0x2]
	movs r0, 0x6
	b _08119676
_0811966E:
	ldr r1, =gPlayerAvatar
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0x7
_08119676:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMovementInputAcroBikeBunnyHop

	thumb_func_start CheckMovementInputAcroBikeMovingWheelie
CheckMovementInputAcroBikeMovingWheelie: @ 8119688
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	ldr r4, =gPlayerAvatar
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r7, r0, r1
	movs r0, 0x2
	mov r9, r0
	movs r0, 0x2
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _08119720
	bl sub_811A128
	ldrb r0, [r7, 0x1E]
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0811970C
	strb r1, [r4, 0x8]
	ldrb r0, [r6]
	cmp r0, 0
	bne _081196EC
	strb r5, [r6]
	b _081196F6
	.pool
_081196EC:
	cmp r0, r5
	beq _081196FC
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _081196FC
_081196F6:
	strb r1, [r4, 0x2]
	movs r0, 0x4
	b _08119750
_081196FC:
	ldr r1, =gPlayerAvatar
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0xC
	b _08119750
	.pool
_0811970C:
	mov r0, r9
	strb r0, [r4, 0x8]
	adds r0, r6, 0
	mov r1, r10
	mov r2, r8
	bl CheckMovementInputAcroBike
	lsls r0, 24
	lsrs r0, 24
	b _08119750
_08119720:
	ldrb r0, [r6]
	cmp r0, 0
	bne _08119736
	strb r5, [r6]
	mov r1, r9
	strb r1, [r4, 0x8]
	strb r0, [r4, 0x2]
	bl sub_811A128
	movs r0, 0x5
	b _08119750
_08119736:
	cmp r2, r0
	beq _08119748
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _08119748
	movs r0, 0
	strb r0, [r4, 0x2]
	movs r0, 0x5
	b _08119750
_08119748:
	ldr r1, =gPlayerAvatar
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0xA
_08119750:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMovementInputAcroBikeMovingWheelie

	thumb_func_start CheckMovementInputAcroBikeUnknownMode5
CheckMovementInputAcroBikeUnknownMode5: @ 8119764
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =gPlayerAvatar
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	ldrb r2, [r0, 0x1]
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	strb r1, [r0, 0x1]
	ldrb r1, [r0, 0x18]
	lsls r1, 28
	lsrs r1, 28
	bl FieldObjectSetDirection
	movs r0, 0
	strb r0, [r6, 0x8]
	mov r0, r8
	adds r1, r4, 0
	adds r2, r5, 0
	bl CheckMovementInputAcroBike
	lsls r0, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMovementInputAcroBikeUnknownMode5

	thumb_func_start CheckMovementInputAcroBikeUnknownMode6
CheckMovementInputAcroBikeUnknownMode6: @ 81197C0
	push {r4,lr}
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gPlayerAvatar
	movs r3, 0
	strb r3, [r4, 0x8]
	bl CheckMovementInputAcroBike
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMovementInputAcroBikeUnknownMode6

	thumb_func_start sub_81197E4
sub_81197E4: @ 81197E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl PlayerFaceDirection
	pop {r0}
	bx r0
	thumb_func_end sub_81197E4

	thumb_func_start sub_81197F4
sub_81197F4: @ 81197F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _0811981A
	ldrb r0, [r5, 0x18]
	lsrs r4, r0, 4
_0811981A:
	adds r0, r4, 0
	bl PlayerFaceDirection
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81197F4

	thumb_func_start sub_8119830
sub_8119830: @ 8119830
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	ldrb r1, [r4, 0x1E]
	adds r0, r5, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _08119868
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl sub_81197E4
	b _081198BA
	.pool
_08119868:
	adds r0, r5, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0xA
	bhi _081198B4
	cmp r4, 0x6
	bne _0811988A
	adds r0, r5, 0
	bl PlayerJumpLedge
	b _081198BA
_0811988A:
	cmp r4, 0x4
	bne _081198A2
	adds r0, r5, 0
	bl IsPlayerCollidingWithFarawayIslandMew
	lsls r0, 24
	cmp r0, 0
	beq _081198A2
	adds r0, r5, 0
	bl PlayerOnBikeCollideWithFarawayIslandMew
	b _081198BA
_081198A2:
	subs r0, r4, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _081198BA
	adds r0, r6, 0
	bl PlayerOnBikeCollide
	b _081198BA
_081198B4:
	adds r0, r6, 0
	bl PlayerGoSpeed2
_081198BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8119830

	thumb_func_start sub_81198C0
sub_81198C0: @ 81198C0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _081198E6
	ldrb r0, [r5, 0x18]
	lsrs r4, r0, 4
_081198E6:
	adds r0, r4, 0
	bl sub_808B8C0
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81198C0

	thumb_func_start sub_81198FC
sub_81198FC: @ 81198FC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _08119922
	ldrb r0, [r5, 0x18]
	lsrs r4, r0, 4
_08119922:
	adds r0, r4, 0
	bl sub_808B8D8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81198FC

	thumb_func_start sub_8119938
sub_8119938: @ 8119938
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _0811995E
	ldrb r0, [r5, 0x18]
	lsrs r4, r0, 4
_0811995E:
	adds r0, r4, 0
	bl sub_808B8A8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119938

	thumb_func_start sub_8119974
sub_8119974: @ 8119974
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _0811999A
	ldrb r0, [r5, 0x18]
	lsrs r4, r0, 4
_0811999A:
	adds r0, r4, 0
	bl sub_808B8F0
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119974

	thumb_func_start sub_81199B0
sub_81199B0: @ 81199B0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _081199E4
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	bl sub_8119974
	b _08119A1E
	.pool
_081199E4:
	adds r0, r4, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08119A18
	cmp r1, 0x9
	beq _08119A18
	cmp r1, 0x6
	bne _08119A02
	adds r0, r4, 0
	bl sub_808B938
	b _08119A1E
_08119A02:
	subs r0, r1, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08119A1E
	cmp r1, 0xB
	bhi _08119A18
	adds r0, r4, 0
	bl sub_8119974
	b _08119A1E
_08119A18:
	adds r0, r4, 0
	bl sub_808B914
_08119A1E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81199B0

	thumb_func_start sub_8119A24
sub_8119A24: @ 8119A24
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0
	beq _08119A58
	cmp r0, 0x7
	beq _08119A84
	cmp r0, 0x9
	bls _08119A50
	adds r0, r1, 0
	adds r1, r5, 0
	bl sub_8119FC4
	lsls r0, 24
	cmp r0, 0
	bne _08119A58
_08119A50:
	adds r0, r5, 0
	bl sub_81197F4
	b _08119A84
_08119A58:
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gMapObjects
	adds r4, r0
	movs r0, 0x22
	bl PlaySE
	ldrb r0, [r4, 0x1]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8093514
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl player_npc_set_state_and_x22_etc
_08119A84:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119A24

	thumb_func_start sub_8119A94
sub_8119A94: @ 8119A94
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_808B95C
	pop {r0}
	bx r0
	thumb_func_end sub_8119A94

	thumb_func_start sub_8119AA4
sub_8119AA4: @ 8119AA4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r7, =gPlayerAvatar
	ldrb r1, [r7, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _08119ADC
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	bl sub_808B8A8
	b _08119B2C
	.pool
_08119ADC:
	adds r0, r4, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0xA
	bhi _08119B22
	cmp r1, 0x6
	bne _08119AFE
	adds r0, r4, 0
	bl sub_808B938
	b _08119B2C
_08119AFE:
	cmp r1, 0x9
	beq _08119B12
	cmp r1, 0x4
	bhi _08119B2C
	ldrb r0, [r5, 0x1E]
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	cmp r0, 0
	beq _08119B1A
_08119B12:
	adds r0, r4, 0
	bl sub_808B8A8
	b _08119B2C
_08119B1A:
	adds r0, r4, 0
	bl sub_808B980
	b _08119B2C
_08119B22:
	adds r0, r6, 0
	bl sub_808B9BC
	movs r0, 0x2
	strb r0, [r7, 0x2]
_08119B2C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8119AA4

	thumb_func_start sub_8119B34
sub_8119B34: @ 8119B34
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r7, =gPlayerAvatar
	ldrb r1, [r7, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _08119B6C
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	bl sub_808B8C0
	b _08119BBC
	.pool
_08119B6C:
	adds r0, r4, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0xA
	bhi _08119BB2
	cmp r1, 0x6
	bne _08119B8E
	adds r0, r4, 0
	bl sub_808B938
	b _08119BBC
_08119B8E:
	cmp r1, 0x9
	beq _08119BA2
	cmp r1, 0x4
	bhi _08119BBC
	ldrb r0, [r5, 0x1E]
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	cmp r0, 0
	beq _08119BAA
_08119BA2:
	adds r0, r4, 0
	bl sub_808B8A8
	b _08119BBC
_08119BAA:
	adds r0, r4, 0
	bl sub_808B980
	b _08119BBC
_08119BB2:
	adds r0, r6, 0
	bl sub_808B9A4
	movs r0, 0x2
	strb r0, [r7, 0x2]
_08119BBC:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8119B34

	thumb_func_start sub_8119BC4
sub_8119BC4: @ 8119BC4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r5, r0, r1
	ldrb r1, [r5, 0x1E]
	adds r0, r4, 0
	bl sub_8119F74
	lsls r0, 24
	cmp r0, 0
	bne _08119BFC
	ldrb r0, [r5, 0x18]
	lsrs r0, 4
	bl sub_808B8D8
	b _08119C36
	.pool
_08119BFC:
	adds r0, r4, 0
	bl sub_8119E38
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0xA
	bhi _08119C30
	cmp r1, 0x6
	bne _08119C1E
	adds r0, r4, 0
	bl PlayerJumpLedge
	b _08119C36
_08119C1E:
	subs r0, r1, 0x5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08119C36
	adds r0, r4, 0
	bl sub_808B8D8
	b _08119C36
_08119C30:
	adds r0, r6, 0
	bl npc_use_some_d2s
_08119C36:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8119BC4

	thumb_func_start sub_8119C3C
@ void sub_8119C3C(int buttons_new, int buttons_held)
sub_8119C3C: @ 8119C3C
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 16
	lsrs r2, r1, 16
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08119C5A
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8119C64
_08119C5A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119C3C

	thumb_func_start sub_8119C64
@ void sub_8119C64(int buttons_new, int buttons_held)
sub_8119C64: @ 8119C64
	push {r4,r5,lr}
	lsls r1, 16
	lsrs r5, r1, 16
	adds r0, r5, 0
	bl sub_8119DF8
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r4, =gPlayerAvatar
	ldr r0, [r4, 0xC]
	movs r1, 0xF
	ands r0, r1
	cmp r2, r0
	bne _08119C90
	ldrb r0, [r4, 0x14]
	cmp r0, 0xFE
	bhi _08119C9A
	adds r0, 0x1
	strb r0, [r4, 0x14]
	b _08119C9A
	.pool
_08119C90:
	adds r0, r2, 0
	bl sub_8119D80
	movs r0, 0
	strb r0, [r4, 0xB]
_08119C9A:
	movs r0, 0xF
	adds r2, r5, 0
	ands r2, r0
	ldr r4, =gPlayerAvatar
	ldr r0, [r4, 0x10]
	movs r1, 0xF
	ands r0, r1
	cmp r2, r0
	bne _08119CBC
	ldrb r0, [r4, 0x1C]
	cmp r0, 0xFE
	bhi _08119CC6
	adds r0, 0x1
	strb r0, [r4, 0x1C]
	b _08119CC6
	.pool
_08119CBC:
	adds r0, r2, 0
	bl sub_8119DBC
	movs r0, 0
	strb r0, [r4, 0xB]
_08119CC6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8119C64

	thumb_func_start sub_8119CCC
sub_8119CCC: @ 8119CCC
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r2, 0
	ldrb r0, [r3]
	cmp r0, 0
	beq _08119CF6
	ldr r5, =gUnknown_020375A4
_08119CDC:
	adds r0, r2, r5
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08119D0C
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08119CDC
_08119CF6:
	movs r2, 0
	ldrb r0, [r4]
	cmp r0, 0
	beq _08119D26
	ldr r3, =gUnknown_020375AC
_08119D00:
	adds r0, r2, r3
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08119D18
_08119D0C:
	movs r0, 0
	b _08119D28
	.pool
_08119D18:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08119D00
_08119D26:
	movs r0, 0x1
_08119D28:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8119CCC

	thumb_func_start sub_8119D30
sub_8119D30: @ 8119D30
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_08119D36:
	ldr r0, =gUnknown_085974C0
	adds r4, r5, r0
	ldr r0, =gPlayerAvatar
	ldr r1, [r0, 0xC]
	ldr r2, [r0, 0x10]
	ldr r0, [r4, 0x8]
	ands r1, r0
	ldr r0, [r4, 0xC]
	ands r2, r0
	ldr r0, [r4]
	cmp r1, r0
	bne _08119D70
	ldr r0, [r4, 0x4]
	cmp r2, r0
	bne _08119D70
	ldr r0, [r4, 0x10]
	ldr r1, [r4, 0x14]
	bl sub_8119CCC
	lsls r0, 24
	cmp r0, 0
	beq _08119D70
	ldrb r0, [r4, 0x18]
	b _08119D7A
	.pool
_08119D70:
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	bls _08119D36
	movs r0, 0
_08119D7A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8119D30

	thumb_func_start sub_8119D80
sub_8119D80: @ 8119D80
	push {r4,lr}
	lsls r0, 24
	ldr r3, =gPlayerAvatar
	ldr r2, [r3, 0xC]
	lsls r2, 4
	movs r1, 0xF0
	lsls r1, 20
	ands r1, r0
	lsrs r1, 24
	orrs r2, r1
	str r2, [r3, 0xC]
	movs r1, 0x7
	adds r4, r3, 0
	adds r3, 0x14
_08119D9C:
	adds r2, r1, r3
	subs r1, 0x1
	adds r0, r1, r3
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _08119D9C
	movs r0, 0x1
	strb r0, [r4, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119D80

	thumb_func_start sub_8119DBC
sub_8119DBC: @ 8119DBC
	push {r4,lr}
	lsls r0, 24
	ldr r3, =gPlayerAvatar
	ldr r2, [r3, 0x10]
	lsls r2, 4
	movs r1, 0xF0
	lsls r1, 20
	ands r1, r0
	lsrs r1, 24
	orrs r2, r1
	str r2, [r3, 0x10]
	movs r1, 0x7
	adds r4, r3, 0
	adds r3, 0x1C
_08119DD8:
	adds r2, r1, r3
	subs r1, 0x1
	adds r0, r1, r3
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	bne _08119DD8
	movs r0, 0x1
	strb r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119DBC

	thumb_func_start sub_8119DF8
sub_8119DF8: @ 8119DF8
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08119E0C
	movs r0, 0x2
	b _08119E32
_08119E0C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08119E18
	movs r0, 0x1
	b _08119E32
_08119E18:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08119E24
	movs r0, 0x3
	b _08119E32
_08119E24:
	movs r0, 0x10
	ands r2, r0
	cmp r2, 0
	bne _08119E30
	movs r0, 0
	b _08119E32
_08119E30:
	movs r0, 0x4
_08119E32:
	pop {r1}
	bx r1
	thumb_func_end sub_8119DF8

	thumb_func_start sub_8119E38
sub_8119E38: @ 8119E38
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
	ldr r0, =gMapObjects
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
	bl sub_8119EA4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8119E38

	thumb_func_start sub_8119EA4
sub_8119EA4: @ 8119EA4
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r4, [sp, 0x10]
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	adds r5, r4, 0
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	str r5, [sp]
	bl CheckForFieldObjectCollision
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bhi _08119EE4
	cmp r4, 0
	bne _08119EE0
	adds r0, r5, 0
	bl IsRunningDisallowedByMetatile
	lsls r0, 24
	cmp r0, 0
	beq _08119EDC
	movs r4, 0x2
_08119EDC:
	cmp r4, 0
	beq _08119EE4
_08119EE0:
	bl sub_8119F50
_08119EE4:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8119EA4

	thumb_func_start sub_8119EF0
sub_8119EF0: @ 8119EF0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl IsRunningDisallowedByMetatile
	lsls r0, 24
	cmp r0, 0
	bne _08119F08
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x17]
	cmp r0, 0x8
	bne _08119F10
_08119F08:
	movs r0, 0x1
	b _08119F12
	.pool
_08119F10:
	movs r0, 0
_08119F12:
	pop {r1}
	bx r1
	thumb_func_end sub_8119EF0

	thumb_func_start IsRunningDisallowedByMetatile
@ bool8 IsRunningDisallowedByMetatile(u8 metatileBehavior)
IsRunningDisallowedByMetatile: @ 8119F18
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsRunningDisallowed
	lsls r0, 24
	cmp r0, 0
	bne _08119F42
	adds r0, r4, 0
	bl MetatileBehavior_IsFortreeBridge
	lsls r0, 24
	cmp r0, 0
	beq _08119F46
	bl PlayerGetZCoord
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _08119F46
_08119F42:
	movs r0, 0x1
	b _08119F48
_08119F46:
	movs r0, 0
_08119F48:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end IsRunningDisallowedByMetatile

	thumb_func_start sub_8119F50
sub_8119F50: @ 8119F50
	push {lr}
	ldr r0, =gUnknown_0203AB54
	ldrb r0, [r0]
	cmp r0, 0
	beq _08119F66
	ldr r1, =gUnknown_0203AB55
	ldrb r0, [r1]
	cmp r0, 0x63
	bhi _08119F66
	adds r0, 0x1
	strb r0, [r1]
_08119F66:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8119F50

	thumb_func_start sub_8119F74
sub_8119F74: @ 8119F74
	push {r4,r5,lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r5, r4, 0
	movs r1, 0xFD
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08119F9E
	adds r0, r4, 0
	bl MetatileBehavior_IsIsolatedVerticalRail
	lsls r0, 24
	cmp r0, 0
	bne _08119FB6
	adds r0, r4, 0
	bl MetatileBehavior_IsVerticalRail
	b _08119FB0
_08119F9E:
	adds r0, r5, 0
	bl MetatileBehavior_IsIsolatedHorizontalRail
	lsls r0, 24
	cmp r0, 0
	bne _08119FB6
	adds r0, r5, 0
	bl MetatileBehavior_IsHorizontalRail
_08119FB0:
	lsls r0, 24
	cmp r0, 0
	beq _08119FBA
_08119FB6:
	movs r0, 0
	b _08119FBC
_08119FBA:
	movs r0, 0x1
_08119FBC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8119F74

	thumb_func_start sub_8119FC4
sub_8119FC4: @ 8119FC4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	lsls r1, 24
	movs r3, 0xFF
	lsls r3, 24
	adds r1, r3
	lsrs r1, 24
	cmp r1, 0x1
	bhi _08119FE4
	cmp r0, 0xA
	beq _08119FEC
	cmp r0, 0xC
	bne _08119FF0
	b _08119FEC
_08119FE4:
	cmp r2, 0xB
	beq _08119FEC
	cmp r2, 0xD
	bne _08119FF0
_08119FEC:
	movs r0, 0
	b _08119FF2
_08119FF0:
	movs r0, 0x1
_08119FF2:
	pop {r1}
	bx r1
	thumb_func_end sub_8119FC4

	thumb_func_start sub_8119FF8
sub_8119FF8: @ 8119FF8
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	bne _0811A038
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl IsRunningDisallowedByMetatile
	lsls r0, 24
	cmp r0, 0
	bne _0811A038
	movs r0, 0
	b _0811A03A
	.pool
_0811A038:
	movs r0, 0x1
_0811A03A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8119FF8

	thumb_func_start player_should_look_direction_be_enforced_upon_movement
player_should_look_direction_be_enforced_upon_movement: @ 811A044
	push {lr}
	movs r0, 0x4
	bl TestPlayerAvatarFlags
	lsls r0, 24
	cmp r0, 0
	beq _0811A078
	ldr r2, =gMapObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1E]
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	cmp r0, 0
	beq _0811A078
	movs r0, 0
	b _0811A07A
	.pool
_0811A078:
	movs r0, 0x1
_0811A07A:
	pop {r1}
	bx r1
	thumb_func_end player_should_look_direction_be_enforced_upon_movement

	thumb_func_start GetOnOffBike
@ void GetOnOffBike(u8 transitionFlags)
GetOnOffBike: @ 811A080
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gUnknown_02037348
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	beq _0811A0B0
	movs r0, 0x1
	bl SetPlayerAvatarTransitionFlags
	bl Overworld_ClearSavedMusic
	bl sub_8085784
	b _0811A0C4
	.pool
_0811A0B0:
	adds r0, r2, 0
	bl SetPlayerAvatarTransitionFlags
	ldr r4, =0x00000193
	adds r0, r4, 0
	bl Overworld_SetSavedMusic
	adds r0, r4, 0
	bl Overworld_ChangeMusicTo
_0811A0C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetOnOffBike

	thumb_func_start sub_811A0D0
sub_811A0D0: @ 811A0D0
	push {lr}
	ldr r2, =gPlayerAvatar
	movs r3, 0
	strb r3, [r2, 0x8]
	strb r3, [r2, 0x9]
	strb r3, [r2, 0xA]
	strb r3, [r2, 0xB]
	str r0, [r2, 0xC]
	str r1, [r2, 0x10]
	movs r1, 0
	adds r2, 0x14
_0811A0E6:
	adds r0, r1, r2
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x7
	bls _0811A0E6
	movs r1, 0
	ldr r3, =gUnknown_020375AC
	movs r2, 0
_0811A0FA:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x7
	bls _0811A0FA
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811A0D0

	thumb_func_start sub_811A114
sub_811A114: @ 811A114
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gPlayerAvatar
	strb r0, [r2, 0xA]
	lsrs r1, r0, 1
	adds r0, r1
	strb r0, [r2, 0xB]
	bx lr
	.pool
	thumb_func_end sub_811A114

	thumb_func_start sub_811A128
sub_811A128: @ 811A128
	ldr r1, =gPlayerAvatar
	movs r0, 0
	strb r0, [r1, 0xA]
	strb r0, [r1, 0xB]
	bx lr
	.pool
	thumb_func_end sub_811A128

	thumb_func_start sub_811A138
sub_811A138: @ 811A138
	push {lr}
	sub sp, 0x8
	ldr r1, =gUnknown_085974B8
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0811A168
	ldrb r0, [r2, 0xA]
	lsls r0, 1
	add r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	b _0811A182
	.pool
_0811A168:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0811A174
	movs r0, 0x3
	b _0811A182
_0811A174:
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _0811A180
	movs r0, 0x1
	b _0811A182
_0811A180:
	movs r0, 0x2
_0811A182:
	add sp, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_811A138

	thumb_func_start sub_811A188
sub_811A188: @ 811A188
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gPlayerAvatar
	ldrb r1, [r5]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0811A1D0
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsBumpySlope
	lsls r0, 24
	cmp r0, 0
	beq _0811A1D0
	movs r0, 0x2
	strb r0, [r5, 0x8]
	bl player_get_direction_upper_nybble
	lsls r0, 24
	lsrs r0, 24
	bl sub_808C1B4
_0811A1D0:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811A188

	thumb_func_start IsRunningDisallowed
@ bool8 IsRunningDisallowed(u8 metatileBehavior)
IsRunningDisallowed: @ 811A1DC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMapHeader
	ldrb r1, [r0, 0x1A]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0811A1FC
	adds r0, r2, 0
	bl IsRunningDisallowedByMetatile
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0811A204
_0811A1FC:
	movs r0, 0x1
	b _0811A206
	.pool
_0811A204:
	movs r0, 0
_0811A206:
	pop {r1}
	bx r1
	thumb_func_end IsRunningDisallowed

	.align 2, 0 @ Don't pad with nop.
