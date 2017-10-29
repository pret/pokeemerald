	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81DA57C
sub_81DA57C: @ 81DA57C
	push {lr}
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081DA5CA
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bhi _081DA5CA
	movs r0, 0x5B
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081DA5C0
	ldr r0, =gUnknown_0862AD34
	movs r1, 0x8
	movs r2, 0x5
	bl sub_81DA5D4
	b _081DA5CA
	.pool
_081DA5C0:
	ldr r0, =gUnknown_0862AD44
	movs r1, 0x7
	movs r2, 0x1
	bl sub_81DA5D4
_081DA5CA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA57C

	thumb_func_start sub_81DA5D4
sub_81DA5D4: @ 81DA5D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	adds r7, r1, 0
	mov r10, r2
	movs r6, 0
	movs r0, 0x5
	mov r8, r0
	movs r5, 0
	cmp r5, r7
	bcs _081DA61C
	mov r4, r9
_081DA5F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r4]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA614
	adds r0, r1, 0
	bl sub_81DA6CC
	cmp r8, r0
	ble _081DA612
	mov r8, r0
_081DA612:
	adds r6, 0x1
_081DA614:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	bcc _081DA5F4
_081DA61C:
	cmp r6, 0
	beq _081DA6BA
	cmp r8, r10
	bhi _081DA6BA
	movs r6, 0
	movs r5, 0
	cmp r5, r7
	bcs _081DA654
	mov r4, r9
_081DA62E:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r4]
	ldr r2, =0x000009ca
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA64C
	adds r0, r1, 0
	bl sub_81DA6CC
	cmp r0, r8
	bne _081DA64C
	adds r6, 0x1
_081DA64C:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	bcc _081DA62E
_081DA654:
	cmp r6, 0
	beq _081DA6BA
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	adds r6, r0, 0
	movs r5, 0
	cmp r5, r7
	bcs _081DA6BA
	ldr r2, =gSaveBlock1Ptr
	ldr r3, =0x000009ca
	mov r4, r9
_081DA674:
	ldr r0, [r2]
	ldrh r1, [r4]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA6B2
	adds r0, r1, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	bl sub_81DA6CC
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r0, r8
	bne _081DA6B2
	cmp r6, 0
	bne _081DA6B0
	ldr r0, [r2]
	adds r0, r3
	ldrh r4, [r4]
	adds r0, r4
	mov r1, r8
	strb r1, [r0]
	b _081DA6BA
	.pool
_081DA6B0:
	subs r6, 0x1
_081DA6B2:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	bcc _081DA674
_081DA6BA:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81DA5D4

	thumb_func_start sub_81DA6CC
sub_81DA6CC: @ 81DA6CC
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r6, =gUnknown_085500A4
_081DA6D4:
	lsls r0, r4, 1
	lsls r1, r5, 4
	adds r0, r1
	adds r0, r6
	ldrh r0, [r0]
	bl HasTrainerAlreadyBeenFought
	lsls r0, 24
	cmp r0, 0
	bne _081DA6F0
	adds r0, r4, 0
	b _081DA6F8
	.pool
_081DA6F0:
	adds r4, 0x1
	cmp r4, 0x4
	ble _081DA6D4
	movs r0, 0x5
_081DA6F8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81DA6CC

	.align 2, 0 @ Don't pad with nop.
