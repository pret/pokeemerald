	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81A8934
@ void sub_81A8934(u8)
sub_81A8934: @ 81A8934
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203CE50
	ldr r0, [r4]
	cmp r0, 0
	bne _081A894A
	movs r0, 0x44
	bl AllocZeroed
	str r0, [r4]
_081A894A:
	ldr r0, [r4]
	adds r0, 0x41
	strb r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A8934

	thumb_func_start sub_81A895C
sub_81A895C: @ 81A895C
	push {r4,lr}
	ldr r4, =gUnknown_0203CE50
	ldr r0, [r4]
	cmp r0, 0
	beq _081A896E
	bl Free
	movs r0, 0
	str r0, [r4]
_081A896E:
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetEventObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gEventObjects
	adds r0, r1
	bl EventObjectClearHeldMovementIfFinished
	bl sub_80D338C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A895C

	thumb_func_start sub_81A89A0
sub_81A89A0: @ 81A89A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r1, r0
	mov r9, r1
	movs r3, 0
	mov r10, r3
	mov r8, r3
_081A89C4:
	mov r0, r8
	lsls r4, r0, 1
	adds r1, r4, r0
	lsls r1, 3
	add r1, r9
	ldrh r0, [r1, 0x4]
	adds r0, 0x7
	ldrh r1, [r1, 0x6]
	adds r1, 0x7
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_0203CE50
	ldr r0, [r0]
	adds r0, 0x41
	ldrb r0, [r0]
	movs r2, 0xA6
	lsls r2, 2
	cmp r0, 0
	bne _081A89F8
	subs r2, 0x48
_081A89F8:
	ldr r0, =0x0000024f
	cmp r1, r0
	bls _081A8AD4
	subs r1, r2
	adds r0, r1, 0
	cmp r1, 0
	bge _081A8A08
	adds r0, r1, 0x7
_081A8A08:
	asrs r2, r0, 3
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x4
	bhi _081A8AD4
	ldr r3, [sp]
	cmp r0, r3
	bne _081A8AD4
	lsls r0, r2, 3
	subs r0, r1, r0
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bhi _081A8AD4
	movs r1, 0
	movs r2, 0
	cmp r5, 0x1
	beq _081A8A58
	cmp r5, 0x1
	bgt _081A8A44
	cmp r5, 0
	beq _081A8A4E
	b _081A8AD4
	.pool
_081A8A44:
	cmp r5, 0x2
	beq _081A8A64
	cmp r5, 0x3
	beq _081A8A70
	b _081A8AD4
_081A8A4E:
	ldr r7, =gUnknown_08612698
	movs r1, 0x1
	b _081A8A74
	.pool
_081A8A58:
	ldr r7, =gUnknown_0861269C
	movs r2, 0x1
	b _081A8A74
	.pool
_081A8A64:
	ldr r7, =gUnknown_086126A0
	movs r1, 0xFF
	b _081A8A74
	.pool
_081A8A70:
	ldr r7, =gUnknown_086126A4
	movs r2, 0xFF
_081A8A74:
	mov r3, r8
	adds r0, r4, r3
	lsls r0, 3
	mov r3, r9
	adds r4, r0, r3
	lsls r0, r1, 24
	asrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r4, 0x4]
	lsls r0, r2, 24
	asrs r0, 24
	ldrh r3, [r4, 0x6]
	adds r0, r3
	strh r0, [r4, 0x6]
	ldrb r0, [r4]
	ldr r6, =gSaveBlock1Ptr
	ldr r2, [r6]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _081A8ACC
	mov r0, r8
	adds r1, r5, 0
	bl sub_81A8D60
	ldrb r4, [r4]
	mov r10, r4
	mov r0, r10
	ldr r2, [r6]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	adds r3, r7, 0
	bl ScriptMovement_StartObjectMovementScript
	b _081A8AD4
	.pool
_081A8ACC:
	mov r0, r8
	adds r1, r5, 0
	bl sub_81A8D94
_081A8AD4:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3F
	bhi _081A8AE4
	b _081A89C4
_081A8AE4:
	mov r0, r10
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81A89A0

	thumb_func_start sub_81A8AF8
sub_81A8AF8: @ 81A8AF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r1, =gUnknown_0203CE50
	ldr r2, [r1]
	cmp r2, 0
	bne _081A8B0C
	b _081A8D4A
_081A8B0C:
	adds r0, r2, 0
	adds r0, 0x41
	ldrb r0, [r0]
	movs r3, 0xA6
	lsls r3, 2
	mov r10, r3
	cmp r0, 0
	bne _081A8B22
	movs r0, 0x94
	lsls r0, 2
	mov r10, r0
_081A8B22:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r3, 0xC7
	lsls r3, 4
	adds r7, r0, r3
	movs r0, 0
	mov r9, r0
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r9, r0
	bcc _081A8B3C
	b _081A8D4A
_081A8B3C:
	mov r8, r1
_081A8B3E:
	mov r1, r8
	ldr r0, [r1]
	mov r2, r9
	lsls r4, r2, 2
	adds r0, r4
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r7
	ldrh r0, [r1, 0x4]
	adds r0, 0x7
	ldrh r1, [r1, 0x6]
	adds r1, 0x7
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r0, 16
	mov r3, r10
	subs r1, r0, r3
	adds r0, r1, 0
	cmp r1, 0
	bge _081A8B76
	adds r0, r1, 0x7
_081A8B76:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	lsrs r0, 24
	mov r2, r8
	ldr r1, [r2]
	adds r1, r4
	ldrb r1, [r1]
	subs r0, r1
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	blt _081A8B96
	cmp r1, 0x3
	bne _081A8BAC
_081A8B96:
	movs r0, 0x3
	negs r0, r0
	movs r6, 0
	cmp r1, r0
	bne _081A8BB4
	b _081A8BB2
	.pool
_081A8BAC:
	movs r6, 0x2
	cmp r1, 0
	ble _081A8BB4
_081A8BB2:
	movs r6, 0x1
_081A8BB4:
	ldr r5, =gUnknown_0203CE50
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl GetEventObjectIdByLocalIdAndMap
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x10
	bne _081A8BDC
	b _081A8D32
_081A8BDC:
	ldr r0, =gEventObjects
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x18]
	lsls r0, 28
	lsrs r0, 28
	adds r1, r0, 0
	cmp r6, 0
	bne _081A8C9C
	cmp r0, 0x2
	beq _081A8C60
	cmp r0, 0x2
	bgt _081A8C0C
	cmp r0, 0x1
	beq _081A8C30
	b _081A8D32
	.pool
_081A8C0C:
	cmp r0, 0x3
	beq _081A8C48
	cmp r0, 0x4
	beq _081A8C16
	b _081A8D32
_081A8C16:
	ldr r3, =gUnknown_086126AE
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0x7
	b _081A8C72
	.pool
_081A8C30:
	ldr r3, =gUnknown_086126A8
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0xA
	b _081A8C72
	.pool
_081A8C48:
	ldr r3, =gUnknown_086126AA
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0x8
	b _081A8C72
	.pool
_081A8C60:
	ldr r3, =gUnknown_086126AC
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0x9
_081A8C72:
	strb r1, [r0, 0x9]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl ScriptMovement_StartObjectMovementScript
	b _081A8D32
	.pool
_081A8C9C:
	cmp r6, 0x1
	bne _081A8D32
	cmp r0, 0x2
	beq _081A8D00
	cmp r0, 0x2
	bgt _081A8CAE
	cmp r0, 0x1
	beq _081A8CD0
	b _081A8D32
_081A8CAE:
	cmp r1, 0x3
	beq _081A8CE8
	cmp r1, 0x4
	bne _081A8D32
	ldr r3, =gUnknown_086126AA
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0x8
	b _081A8D12
	.pool
_081A8CD0:
	ldr r3, =gUnknown_086126AC
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0x9
	b _081A8D12
	.pool
_081A8CE8:
	ldr r3, =gUnknown_086126AE
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0x7
	b _081A8D12
	.pool
_081A8D00:
	ldr r3, =gUnknown_086126A8
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	movs r1, 0xA
_081A8D12:
	strb r1, [r0, 0x9]
	mov r2, r8
	ldr r0, [r2]
	adds r0, r4
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r7
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl ScriptMovement_StartObjectMovementScript
_081A8D32:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r9, r0
	bcs _081A8D4A
	b _081A8B3E
_081A8D4A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A8AF8

	thumb_func_start sub_81A8D60
sub_81A8D60: @ 81A8D60
	push {r4,lr}
	ldr r4, =gUnknown_0203CE50
	ldr r3, [r4]
	adds r2, r3, 0
	adds r2, 0x40
	ldrb r2, [r2]
	lsls r2, 2
	adds r3, r2
	strb r0, [r3, 0x1]
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	lsls r0, 2
	adds r2, r0
	strb r1, [r2]
	ldr r1, [r4]
	adds r1, 0x40
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A8D60

	thumb_func_start sub_81A8D94
sub_81A8D94: @ 81A8D94
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r5, r0, r1
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, r5
	ldrh r0, [r1, 0x4]
	adds r0, 0x7
	ldrh r1, [r1, 0x6]
	adds r1, 0x7
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_0203CE50
	ldr r0, [r0]
	adds r0, 0x41
	ldrb r0, [r0]
	movs r1, 0xA6
	lsls r1, 2
	cmp r0, 0
	bne _081A8DDA
	subs r1, 0x48
_081A8DDA:
	subs r1, r2, r1
	adds r0, r1, 0
	cmp r1, 0
	bge _081A8DE4
	adds r0, r1, 0x7
_081A8DE4:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	lsrs r0, 24
	subs r0, r6
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	blt _081A8DFC
	cmp r1, 0x3
	bne _081A8E08
_081A8DFC:
	movs r2, 0
	b _081A8E1A
	.pool
_081A8E08:
	cmp r1, 0
	bgt _081A8E14
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	bne _081A8E18
_081A8E14:
	movs r2, 0x1
	b _081A8E1A
_081A8E18:
	movs r2, 0x2
_081A8E1A:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r5
	ldrb r0, [r1, 0x9]
	adds r3, r0, 0
	cmp r2, 0
	bne _081A8E4C
	cmp r0, 0x8
	beq _081A8E72
	cmp r0, 0x8
	bgt _081A8E38
	cmp r0, 0x7
	beq _081A8E48
	b _081A8E76
_081A8E38:
	cmp r0, 0x9
	beq _081A8E44
	cmp r0, 0xA
	bne _081A8E76
	movs r0, 0x7
	b _081A8E74
_081A8E44:
	movs r0, 0x8
	b _081A8E74
_081A8E48:
	movs r0, 0x9
	b _081A8E74
_081A8E4C:
	cmp r2, 0x1
	bne _081A8E76
	cmp r0, 0x8
	beq _081A8E6A
	cmp r0, 0x8
	bgt _081A8E5E
	cmp r0, 0x7
	beq _081A8E72
	b _081A8E76
_081A8E5E:
	cmp r3, 0x9
	beq _081A8E6E
	cmp r3, 0xA
	bne _081A8E76
	movs r0, 0x8
	b _081A8E74
_081A8E6A:
	movs r0, 0x9
	b _081A8E74
_081A8E6E:
	movs r0, 0x7
	b _081A8E74
_081A8E72:
	movs r0, 0xA
_081A8E74:
	strb r0, [r1, 0x9]
_081A8E76:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81A8D94

	.align 2, 0 @ Don't pad with nop.
