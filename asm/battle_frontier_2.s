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

	thumb_func_start sub_81A8E7C
sub_81A8E7C: @ 81A8E7C
	push {lr}
	ldr r1, =gUnknown_08613EE0
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A8E7C

	thumb_func_start sub_81A8E9C
sub_81A8E9C: @ 81A8E9C
	push {r4-r6,lr}
	ldr r3, =gSaveBlock2Ptr
	ldr r1, [r3]
	ldr r4, =0x00000ca9
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	ldr r0, =0x00000ca8
	adds r1, r0
	movs r2, 0
	strb r2, [r1]
	ldr r1, [r3]
	ldr r6, =0x00000cb2
	adds r0, r1, r6
	strh r2, [r0]
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	cmp r5, 0
	beq _081A8EF0
	ldr r0, [r3]
	ldr r1, =0x00000cdc
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 6
	b _081A8EFC
	.pool
_081A8EF0:
	ldr r0, [r3]
	ldr r6, =0x00000cdc
	adds r0, r6
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 5
_081A8EFC:
	ands r2, r0
	cmp r2, 0
	bne _081A8F14
	ldr r0, [r3]
	lsls r1, r5, 1
	ldr r3, =0x00000e1a
	adds r0, r3
	adds r0, r1
	strh r2, [r0]
	adds r0, r5, 0
	bl sub_81AAA7C
_081A8F14:
	bl sub_81C4EEC
	ldr r0, =gTrainerBattleOpponent_A
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattleOutcome
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A8E9C

	thumb_func_start sub_81A8F38
sub_81A8F38: @ 81A8F38
	push {r4,lr}
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r2, =0x00000ca9
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r4, r0, 30
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x6
	bls _081A8F54
	b _081A903A
_081A8F54:
	lsls r0, 2
	ldr r1, =_081A8F70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081A8F70:
	.4byte _081A8F8C
	.4byte _081A8F9C
	.4byte _081A8FB4
	.4byte _081A8FE4
	.4byte _081A8FF8
	.4byte _081A9010
	.4byte _081A9028
_081A8F8C:
	ldr r0, =gSpecialVar_Result
	ldr r1, [r3]
	ldr r3, =0x00000e18
	b _081A8FFE
	.pool
_081A8F9C:
	ldr r2, =gSpecialVar_Result
	ldr r0, [r3]
	lsls r1, r4, 1
	ldr r3, =0x00000e1a
	adds r0, r3
	adds r0, r1
	ldrh r0, [r0]
	b _081A9038
	.pool
_081A8FB4:
	cmp r4, 0
	beq _081A8FCC
	ldr r2, =gSpecialVar_Result
	ldr r0, [r3]
	ldr r1, =0x00000cdc
	adds r0, r1
	b _081A9030
	.pool
_081A8FCC:
	ldr r2, =gSpecialVar_Result
	ldr r0, [r3]
	ldr r3, =0x00000cdc
	adds r0, r3
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	b _081A9036
	.pool
_081A8FE4:
	ldr r0, =gSpecialVar_Result
	ldr r1, [r3]
	ldr r2, =0x00000e1a
	adds r1, r2
	b _081A9000
	.pool
_081A8FF8:
	ldr r0, =gSpecialVar_Result
	ldr r1, [r3]
	ldr r3, =0x00000e1c
_081A8FFE:
	adds r1, r3
_081A9000:
	ldrh r1, [r1]
	strh r1, [r0]
	b _081A903A
	.pool
_081A9010:
	ldr r2, =gSpecialVar_Result
	ldr r0, [r3]
	ldr r1, =0x00000cdc
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	b _081A9036
	.pool
_081A9028:
	ldr r2, =gSpecialVar_Result
	ldr r0, [r3]
	ldr r3, =0x00000cdc
	adds r0, r3
_081A9030:
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
_081A9036:
	ands r0, r1
_081A9038:
	strh r0, [r2]
_081A903A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A8F38

	thumb_func_start sub_81A9048
sub_81A9048: @ 81A9048
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r1, r0, 30
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _081A9098
	cmp r0, 0x1
	bgt _081A9078
	cmp r0, 0
	beq _081A9082
	b _081A9126
	.pool
_081A9078:
	cmp r0, 0x2
	beq _081A90B0
	cmp r0, 0x7
	beq _081A911C
	b _081A9126
_081A9082:
	ldr r0, =gSpecialVar_0x8006
	ldrh r1, [r0]
	ldr r3, =0x00000e18
	adds r0, r2, r3
	strh r1, [r0]
	b _081A9126
	.pool
_081A9098:
	lsls r1, 1
	ldr r3, =0x00000e1a
	adds r0, r2, r3
	adds r0, r1
	ldr r1, =gSpecialVar_0x8006
	ldrh r1, [r1]
	strh r1, [r0]
	b _081A9126
	.pool
_081A90B0:
	cmp r1, 0
	beq _081A90E4
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	beq _081A90D0
	ldr r1, =0x00000cdc
	adds r0, r2, r1
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 6
	b _081A90F6
	.pool
_081A90D0:
	ldr r3, =0x00000cdc
	adds r0, r2, r3
	ldr r1, [r0]
	ldr r2, =0xffffdfff
	b _081A910C
	.pool
_081A90E4:
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	beq _081A9104
	ldr r1, =0x00000cdc
	adds r0, r2, r1
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 5
_081A90F6:
	orrs r1, r2
	str r1, [r0]
	b _081A9126
	.pool
_081A9104:
	ldr r3, =0x00000cdc
	adds r0, r2, r3
	ldr r1, [r0]
	ldr r2, =0xffffefff
_081A910C:
	ands r1, r2
	str r1, [r0]
	b _081A9126
	.pool
_081A911C:
	ldr r0, =gSpecialVar_0x8006
	ldrh r1, [r0]
	ldr r3, =0x00000e2a
	adds r0, r2, r3
	strb r1, [r0]
_081A9126:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9048

	thumb_func_start sub_81A9134
sub_81A9134: @ 81A9134
	push {r4,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	ldr r2, =0x00000ca8
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	movs r1, 0
	bl VarSet
	ldr r1, [r4]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	bl save_serialize_map
	movs r0, 0x1
	bl TrySavingData
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9134

	thumb_func_start sub_81A917C
sub_81A917C: @ 81A917C
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	ldr r2, =0x00000ca9
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 29
	ldr r2, =0x00000e1a
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0x29
	bls _081A91CC
	bl Random
	ldr r4, [r4]
	ldr r5, =gUnknown_08613F34
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 15
	adds r0, r5
	ldrh r0, [r0]
	ldr r1, =0x00000e18
	adds r4, r1
	b _081A91EA
	.pool
_081A91CC:
	bl Random
	ldr r4, [r4]
	ldr r5, =gUnknown_08613F28
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 15
	adds r0, r5
	ldrh r0, [r0]
	ldr r2, =0x00000e18
	adds r4, r2
_081A91EA:
	strh r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A917C

	thumb_func_start sub_81A91FC
sub_81A91FC: @ 81A91FC
	push {r4,r5,lr}
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldr r1, =0x00000e18
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _081A9244
	ldr r0, [r4]
	ldr r1, =0x00000e18
	adds r0, r1
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, [r4]
	ldr r1, =0x00000e18
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
	b _081A924A
	.pool
_081A9244:
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
_081A924A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A91FC

	thumb_func_start sub_81A9254
sub_81A9254: @ 81A9254
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gSaveBlock2Ptr
_081A925A:
	bl Random
	ldr r1, [r5]
	lsls r2, r4, 1
	ldr r3, =0x00000e22
	adds r1, r3
	adds r1, r2
	strh r0, [r1]
	adds r4, 0x1
	cmp r4, 0x3
	ble _081A925A
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e2a
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9254

	thumb_func_start CalculateBattlePyramidItemBallItemId
CalculateBattlePyramidItemBallItemId: @ 81A9290
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldr r2, =0x00000ca9
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	mov r10, r0
	adds r2, 0x9
	adds r0, r1, r2
	ldrh r0, [r0]
	str r0, [sp]
	mov r2, r10
	lsls r0, r2, 1
	ldr r2, =0x00000e1a
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0x13
	bls _081A92DE
	movs r0, 0x13
	mov r8, r0
_081A92DE:
	bl sub_81AA9E4
	lsls r0, 24
	ldr r1, =gSpecialVar_LastTalked
	ldrh r4, [r1]
	ldr r1, =gUnknown_08613650
	lsrs r0, 20
	adds r0, r1
	ldrb r0, [r0, 0x1]
	subs r4, r0
	subs r7, r4, 0x1
	ldr r1, [r5]
	lsrs r0, r7, 31
	adds r0, r7, r0
	asrs r0, 1
	lsls r0, 1
	ldr r2, =0x00000e22
	adds r1, r2
	adds r1, r0
	ldrh r6, [r1]
	adds r0, r6, 0
	bl SeedRng2
	movs r5, 0
	mov r0, r8
	lsls r0, 2
	mov r9, r0
	cmp r5, r4
	bge _081A9332
_081A9318:
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r6, r0, 16
	adds r5, 0x1
	adds r0, r7, 0x1
	cmp r5, r0
	blt _081A9318
_081A9332:
	ldr r0, =gUnknown_08613B3A
	ldr r1, [sp]
	adds r0, r1, r0
	ldrb r5, [r0]
	ldr r1, =gUnknown_08613ABC
	ldr r3, =gSpecialVar_0x8000
	ldr r4, =gSpecialVar_0x8001
	cmp r5, 0x3E
	bhi _081A935E
	lsls r2, r5, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r6, r0
	blt _081A935E
	adds r0, r2, r1
_081A9350:
	adds r0, 0x2
	adds r5, 0x1
	cmp r5, 0x3E
	bhi _081A935E
	ldrb r2, [r0]
	cmp r6, r2
	bge _081A9350
_081A935E:
	mov r0, r10
	cmp r0, 0
	beq _081A9394
	ldr r2, =gUnknown_0861392C
	b _081A9396
	.pool
_081A9394:
	ldr r2, =gUnknown_0861379C
_081A9396:
	lsls r0, r5, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 1
	mov r1, r9
	add r1, r8
	lsls r1, 2
	adds r0, r1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	movs r0, 0x1
	strh r0, [r4]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CalculateBattlePyramidItemBallItemId

	thumb_func_start sub_81A93C8
sub_81A93C8: @ 81A93C8
	push {r4,r5,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r3, r0, r1
	movs r2, 0
	ldr r4, =gSpecialVar_LastTalked
	b _081A93F4
	.pool
_081A93E4:
	adds r2, 0x1
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _081A940A
_081A93F4:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r3
	ldrb r0, [r1]
	ldrh r5, [r4]
	cmp r0, r5
	bne _081A93E4
	ldr r0, =0x00007fff
	strh r0, [r1, 0x4]
	strh r0, [r1, 0x6]
_081A940A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A93C8

	thumb_func_start sub_81A9414
sub_81A9414: @ 81A9414
	ldr r1, =gFacilityTrainers
	ldr r0, =gBattleFrontierTrainers
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81A9414

	thumb_func_start sub_81A9424
sub_81A9424: @ 81A9424
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	movs r0, 0
	mov r9, r0
	movs r7, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r1, r0
	mov r8, r1
	ldr r2, =gEventObjects
	ldr r0, =gSelectedEventObject
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x8]
	bl sub_81A9AA8
	lsls r0, 16
	lsrs r5, r0, 16
	movs r6, 0
	ldr r2, =gUnknown_08613C1C
	ldr r0, =gFacilityTrainers
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r5
	adds r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bne _081A9488
	ldrb r2, [r2, 0x1]
	mov r9, r2
	b _081A94AE
	.pool
_081A9488:
	adds r6, 0x1
	cmp r6, 0x31
	bhi _081A94AE
	ldr r4, =gUnknown_08613C1C
	lsls r3, r6, 1
	adds r2, r3, r4
	ldr r0, =gFacilityTrainers
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r5
	adds r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bne _081A9488
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	mov r9, r0
_081A94AE:
	ldr r3, =gUnknown_08613ED8
	ldr r2, =gEventObjects
	ldr r0, =gSelectedEventObject
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x8]
	subs r0, 0x1
	adds r0, r3
	ldrb r0, [r0]
	str r0, [sp]
	movs r6, 0
	mov r3, r9
	lsls r3, 2
	mov r9, r3
_081A94D0:
	ldr r0, [sp]
	cmp r0, 0x8
	bls _081A94D8
	b _081A95E8
_081A94D8:
	lsls r0, 2
	ldr r1, =_081A94FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081A94FC:
	.4byte _081A9520
	.4byte _081A9530
	.4byte _081A9572
	.4byte _081A95B4
	.4byte _081A95BA
	.4byte _081A95C0
	.4byte _081A95C6
	.4byte _081A95D2
	.4byte _081A95DE
_081A9520:
	mov r0, sp
	movs r1, 0x8
	movs r2, 0
	bl sub_81A9998
	lsls r0, 24
	lsrs r7, r0, 24
	b _081A95EE
_081A9530:
	movs r6, 0
	ldr r2, =0x7fff0000
	mov r4, r8
	adds r4, 0x4
	mov r5, r8
	b _081A9560
	.pool
_081A9540:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3B
	bne _081A955A
	movs r1, 0
	ldrsh r0, [r4, r1]
	asrs r1, r2, 16
	cmp r0, r1
	beq _081A955A
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	cmp r0, r1
	beq _081A955A
	adds r7, 0x1
_081A955A:
	adds r4, 0x18
	adds r5, 0x18
	adds r6, 0x1
_081A9560:
	str r2, [sp, 0x4]
	bl sub_81AAA40
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x4]
	cmp r6, r0
	blt _081A9540
	b _081A95EE
_081A9572:
	bl sub_81AA9E4
	lsls r0, 24
	ldr r1, =gUnknown_08613650
	lsrs r0, 20
	adds r0, r1
	ldrb r7, [r0, 0x1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e2a
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gBitTable
	movs r6, 0x7
_081A958E:
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _081A9598
	subs r7, 0x1
_081A9598:
	adds r1, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _081A958E
	b _081A95EE
	.pool
_081A95B4:
	mov r0, sp
	movs r1, 0x8
	b _081A95D6
_081A95BA:
	mov r0, sp
	movs r1, 0x8
	b _081A95CA
_081A95C0:
	mov r0, sp
	movs r1, 0x10
	b _081A95D6
_081A95C6:
	mov r0, sp
	movs r1, 0x10
_081A95CA:
	movs r2, 0x1
	bl sub_81A9998
	b _081A95E8
_081A95D2:
	mov r0, sp
	movs r1, 0x18
_081A95D6:
	movs r2, 0x2
	bl sub_81A9998
	b _081A95E8
_081A95DE:
	mov r0, sp
	movs r1, 0x18
	movs r2, 0x1
	bl sub_81A9998
_081A95E8:
	cmp r6, 0
	bne _081A95EE
	b _081A94D0
_081A95EE:
	ldr r1, =gUnknown_08613EC0
	add r1, r9
	ldr r0, [sp]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9424

	thumb_func_start sub_81A9618
sub_81A9618: @ 81A9618
	push {r4,r5,lr}
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldr r2, =0x00000ca9
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r2, r0, 29
	ldr r4, =0x00000e1a
	adds r1, r4
	adds r1, r2
	ldrh r3, [r1]
	ldr r0, =0x000003e6
	cmp r3, r0
	bhi _081A963A
	adds r0, r3, 0x1
	strh r0, [r1]
_081A963A:
	ldr r0, [r5]
	adds r1, r0, r4
	adds r1, r2
	ldr r3, =0x00000e1e
	adds r0, r3
	adds r0, r2
	ldrh r1, [r1]
	ldrh r2, [r0]
	cmp r1, r2
	bls _081A9650
	strh r1, [r0]
_081A9650:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9618

	thumb_func_start sub_81A966C
sub_81A966C: @ 81A966C
	push {r4,lr}
	ldr r4, =gSpecialVar_Result
	bl InBattlePyramid
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A966C

	thumb_func_start sub_81A9684
sub_81A9684: @ 81A9684
	push {r4,lr}
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	cmp r0, 0
	beq _081A9698
	cmp r0, 0x1
	beq _081A96B4
	b _081A9754
	.pool
_081A9698:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	ldr r2, =0x00000e68
	adds r0, r2
	strb r1, [r0]
	b _081A9754
	.pool
_081A96B4:
	ldr r4, =gSpecialVar_Result
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _081A9710
	cmp r0, 0x1
	bgt _081A9754
	cmp r0, 0
	bne _081A9754
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081A9754
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000e68
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x77
	bls _081A96F4
	movs r0, 0x78
	strb r0, [r1]
	b _081A96FC
	.pool
_081A96F4:
	ldr r0, =gSpecialVar_0x8007
	ldrh r0, [r0]
	bl PlaySE
_081A96FC:
	ldr r1, =gSpecialVar_Result
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _081A9754
	.pool
_081A9710:
	ldr r1, =gSpecialVar_0x8005
	ldrh r0, [r1]
	cmp r0, 0
	beq _081A9750
	subs r0, 0x1
	strh r0, [r1]
	ldr r3, =gSaveBlock2Ptr
	ldr r1, [r3]
	ldr r2, =0x00000e68
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r3]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x78
	bls _081A973E
	movs r0, 0x78
	strb r0, [r1]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081A973E:
	bl door_upload_tiles
	b _081A9754
	.pool
_081A9750:
	movs r0, 0x2
	strh r0, [r4]
_081A9754:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81A9684

	thumb_func_start sub_81A975C
sub_81A975C: @ 81A975C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	movs r5, 0
	movs r0, 0x64
	mov r9, r0
	ldr r1, =gPlayerParty
	mov r8, r1
_081A9776:
	movs r4, 0
	adds r7, r5, 0x1
	mov r6, r9
	muls r6, r5
_081A977E:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	lsls r1, r4, 1
	ldr r2, =0x00000caa
	adds r0, r2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	beq _081A97A2
	subs r0, 0x1
	cmp r0, r5
	bne _081A97A2
	mov r1, r8
	adds r0, r6, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
_081A97A2:
	adds r4, 0x1
	cmp r4, 0x3
	ble _081A977E
	adds r5, r7, 0
	cmp r5, 0x5
	ble _081A9776
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A975C

	thumb_func_start sub_81A97C8
sub_81A97C8: @ 81A97C8
	push {lr}
	ldr r0, =sub_81A97DC
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A97C8

	thumb_func_start sub_81A97DC
sub_81A97DC: @ 81A97DC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081A980C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 5
	ldr r1, =gUnknown_08D856C8
	adds r0, r1
	ldr r1, =gPlttBufferUnfaded + 0xC0
	movs r2, 0x10
	bl CpuSet
	adds r0, r4, 0
	bl DestroyTask
_081A980C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A97DC

	thumb_func_start sub_81A9828
sub_81A9828: @ 81A9828
	push {lr}
	bl sub_809FDD4
	pop {r0}
	bx r0
	thumb_func_end sub_81A9828

	thumb_func_start sub_81A9834
sub_81A9834: @ 81A9834
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r0, 0
	str r0, [sp]
_081A9844:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, [sp]
	lsls r1, r2, 1
	ldr r5, =0x00000caa
	adds r0, r5
	adds r0, r1
	ldrh r0, [r0]
	subs r5, r0, 0x1
	movs r0, 0
	str r0, [sp, 0x4]
	movs r2, 0x64
	adds r1, r5, 0
	muls r1, r2
	str r1, [sp, 0x8]
	movs r0, 0x8E
	lsls r0, 2
	adds r6, r1, r0
	movs r1, 0
	str r1, [sp, 0x10]
_081A986C:
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	ldr r3, =gPlayerParty
	ldr r1, [sp, 0x10]
	adds r0, r1, r3
	movs r1, 0xB
	movs r2, 0
	str r3, [sp, 0x14]
	bl GetMonData
	ldr r3, [sp, 0x14]
	cmp r4, r0
	bne _081A993C
	movs r6, 0
	adds r2, r5, 0x1
	str r2, [sp, 0xC]
	movs r1, 0x64
	adds r0, r5, 0
	muls r0, r1
	movs r5, 0x8E
	lsls r5, 2
	adds r5, r0
	mov r9, r5
	ldr r7, [sp, 0x4]
	muls r7, r1
	mov r10, r3
_081A98AC:
	movs r5, 0
	adds r0, r6, 0x1
	mov r8, r0
	b _081A98C6
	.pool
_081A98C4:
	adds r5, 0x1
_081A98C6:
	cmp r5, 0x3
	bgt _081A98EE
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	add r0, r9
	adds r1, r5, 0
	adds r1, 0xD
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	adds r1, r6, 0
	adds r1, 0xD
	mov r2, r10
	adds r0, r7, r2
	movs r2, 0
	bl GetMonData
	cmp r4, r0
	bne _081A98C4
_081A98EE:
	cmp r5, 0x4
	bne _081A9900
	lsls r2, r6, 24
	lsrs r2, 24
	mov r5, r10
	adds r0, r7, r5
	movs r1, 0xA6
	bl SetMonMoveSlot
_081A9900:
	mov r6, r8
	cmp r6, 0x3
	ble _081A98AC
	ldr r1, =gSaveBlock1Ptr
	ldr r0, [r1]
	ldr r2, [sp, 0x8]
	adds r0, r2
	movs r5, 0x8E
	lsls r5, 2
	adds r0, r5
	ldr r1, =gPlayerParty
	ldr r2, [sp, 0x10]
	adds r1, r2, r1
	movs r2, 0x64
	bl memcpy
	ldr r0, =gUnknown_0203CEF8
	ldr r5, [sp, 0x4]
	adds r0, r5, r0
	mov r1, sp
	ldrb r1, [r1, 0xC]
	strb r1, [r0]
	b _081A994C
	.pool
_081A993C:
	ldr r2, [sp, 0x10]
	adds r2, 0x64
	str r2, [sp, 0x10]
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x4]
	cmp r0, 0x2
	ble _081A986C
_081A994C:
	ldr r1, [sp]
	adds r1, 0x1
	str r1, [sp]
	cmp r1, 0x2
	bgt _081A9958
	b _081A9844
_081A9958:
	movs r2, 0
	str r2, [sp]
	ldr r4, =gSaveBlock2Ptr
	ldr r3, =0x00000caa
	ldr r2, =gUnknown_0203CEF8
_081A9962:
	ldr r1, [r4]
	ldr r5, [sp]
	lsls r0, r5, 1
	adds r1, r3
	adds r1, r0
	adds r0, r5, r2
	ldrb r0, [r0]
	strh r0, [r1]
	adds r5, 0x1
	str r5, [sp]
	cmp r5, 0x2
	ble _081A9962
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9834

	thumb_func_start sub_81A9998
sub_81A9998: @ 81A9998
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	movs r4, 0
	ldr r0, =gUnknown_03005DC0
	ldr r5, [r0, 0x8]
	ldr r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 1
	adds r0, 0xE
	adds r5, r0
	movs r3, 0
	ldr r0, =0x000003ff
	mov r8, r0
	ldr r1, =0x0000028e
	mov r12, r1
	ldr r0, =gEventObjects
	mov r9, r0
_081A99CC:
	movs r2, 0
_081A99CE:
	lsls r0, r2, 1
	adds r0, r5
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, r12
	bne _081A9A8A
	adds r2, 0x7
	ldr r0, =gSelectedEventObject
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r5, 0xC
	ldrsh r1, [r0, r5]
	subs r2, r1
	adds r1, r3, 0x7
	movs r3, 0xE
	ldrsh r0, [r0, r3]
	subs r3, r1, r0
	cmp r2, r6
	bge _081A9A0E
	negs r0, r6
	cmp r2, r0
	ble _081A9A0E
	cmp r3, r6
	bge _081A9A0E
	cmp r3, r0
	ble _081A9A0E
	cmp r7, 0
	bne _081A9A84
_081A9A0E:
	cmp r2, 0
	ble _081A9A34
	cmp r3, 0
	ble _081A9A34
	movs r4, 0x3
	cmp r2, r3
	blt _081A9A7C
	movs r4, 0x2
	b _081A9A7C
	.pool
_081A9A34:
	cmp r2, 0
	bge _081A9A46
	cmp r3, 0
	bge _081A9A46
	movs r4, 0x1
	cmp r2, r3
	ble _081A9A7C
	movs r4, 0
	b _081A9A7C
_081A9A46:
	cmp r2, 0
	bne _081A9A54
	movs r4, 0
	cmp r3, 0
	ble _081A9A7C
	movs r4, 0x3
	b _081A9A7C
_081A9A54:
	cmp r3, 0
	bne _081A9A62
	movs r4, 0x1
	cmp r2, 0
	ble _081A9A7C
	movs r4, 0x2
	b _081A9A7C
_081A9A62:
	cmp r2, 0
	bge _081A9A72
	adds r0, r2, r3
	movs r4, 0x1
	cmp r0, 0
	ble _081A9A7C
	movs r4, 0x3
	b _081A9A7C
_081A9A72:
	adds r0, r2, r3
	mvns r0, r0
	asrs r4, r0, 31
	movs r0, 0x2
	ands r4, r0
_081A9A7C:
	movs r0, 0
	mov r5, r10
	str r0, [r5]
	b _081A9A98
_081A9A84:
	mov r0, r10
	str r7, [r0]
	b _081A9A98
_081A9A8A:
	adds r2, 0x1
	cmp r2, 0x1F
	ble _081A99CE
	adds r5, 0x5E
	adds r3, 0x1
	cmp r3, 0x1F
	ble _081A99CC
_081A9A98:
	adds r0, r4, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81A9998

	thumb_func_start sub_81A9AA8
sub_81A9AA8: @ 81A9AA8
	lsls r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	lsrs r0, 23
	adds r1, r0
	ldr r0, =0x00000cb2
	adds r1, r0
	ldrh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81A9AA8

	thumb_func_start GetBattlePyramidTrainerFlag
GetBattlePyramidTrainerFlag: @ 81A9AC4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r2, [r1]
	ldr r1, =0x00000e2a
	adds r2, r1
	ldr r4, =gBitTable
	ldr r3, =gEventObjects
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r0, [r1, 0x8]
	subs r0, 0x1
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ldrb r1, [r2]
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBattlePyramidTrainerFlag

	thumb_func_start sub_81A9B04
sub_81A9B04: @ 81A9B04
	push {lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	bl sub_81A9B44
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _081A9B2E
	movs r0, 0x1
	bl GetChosenApproachingTrainerEventObjectId
	ldr r1, =gSelectedEventObject
	strb r0, [r1]
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_81A9B44
_081A9B2E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9B04

	thumb_func_start sub_81A9B44
sub_81A9B44: @ 81A9B44
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r5, r0, 16
	movs r3, 0
	ldr r0, =gEventObjects
	mov r12, r0
	ldr r6, =gSelectedEventObject
	ldr r1, =gSaveBlock1Ptr
	mov r10, r1
	ldr r7, =gSaveBlock2Ptr
	mov r9, r7
	ldr r0, =0x00000cb4
	mov r8, r0
	ldr r4, =gBitTable
_081A9B68:
	mov r1, r9
	ldr r2, [r1]
	lsls r0, r3, 1
	mov r7, r8
	adds r1, r2, r7
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, r5
	bne _081A9B86
	ldr r1, =0x00000e2a
	adds r0, r2, r1
	ldr r1, [r4]
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
_081A9B86:
	adds r4, 0x4
	adds r3, 0x1
	cmp r3, 0x7
	ble _081A9B68
	ldrb r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r12
	movs r3, 0x2
	strb r3, [r0, 0x6]
	mov r7, r10
	ldr r2, [r7]
	ldr r0, =gSpecialVar_LastTalked
	ldrh r1, [r0]
	subs r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	ldr r1, =0x00000c79
	adds r2, r1
	strb r3, [r2]
	ldrb r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldrh r1, [r0, 0x10]
	strh r1, [r0, 0xC]
	ldrb r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldrh r1, [r0, 0x12]
	strh r1, [r0, 0xE]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9B44

	thumb_func_start GenerateBattlePyramidWildMon
GenerateBattlePyramidWildMon: @ 81A9C04
	push {r4-r6,lr}
	sub sp, 0x14
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000ca9
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r5, r0, 30
	lsls r0, r5, 1
	ldr r2, =0x00000e1a
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x13
	bls _081A9C3A
	movs r0, 0x13
_081A9C3A:
	cmp r5, 0
	beq _081A9C54
	ldr r1, =gBattlePyramidOpenLevelWildMonPointers
	b _081A9C56
	.pool
_081A9C54:
	ldr r1, =gBattlePyramidLevel50WildMonPointers
_081A9C56:
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	ldr r4, =gEnemyParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	subs r0, 0x1
	str r0, [sp, 0x10]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r2, r6, r2
	adds r0, r4, 0
	movs r1, 0xB
	bl SetMonData
	ldr r1, [sp, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r0]
	mov r0, sp
	bl GetSpeciesName
	adds r0, r4, 0
	movs r1, 0x2
	mov r2, sp
	bl SetMonData
	cmp r5, 0
	beq _081A9CD4
	bl SetFacilityPtrsGetLevel
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, [sp, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	subs r5, r0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xB
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x5
	adds r5, r0
	b _081A9CF6
	.pool
_081A9CD4:
	bl Random
	ldr r2, [sp, 0x10]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r6
	ldrb r4, [r1, 0x2]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xB
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x5
	adds r5, r4, r0
_081A9CF6:
	ldr r4, =gEnemyParty
	ldr r2, =gBaseStats
	ldr r1, [sp, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	adds r2, r1, 0
	muls r2, r0
	lsls r0, r5, 2
	ldr r1, =gExperienceTables
	adds r0, r1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x19
	bl SetMonData
	ldr r1, [sp, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x3]
	cmp r1, 0
	blt _081A9D4C
	cmp r1, 0x1
	bgt _081A9D4C
	adds r2, r0, 0x3
	b _081A9D7C
	.pool
_081A9D4C:
	ldr r2, =gBaseStats
	ldr r1, [sp, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrh r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x17]
	cmp r0, 0
	beq _081A9D90
	ldr r4, =gEnemyParty
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	movs r1, 0x1
	ands r1, r0
	str r1, [sp, 0xC]
	add r2, sp, 0xC
_081A9D7C:
	adds r0, r4, 0
	movs r1, 0x2E
	bl SetMonData
	b _081A9D9C
	.pool
_081A9D90:
	str r0, [sp, 0xC]
	ldr r0, =gEnemyParty
	add r2, sp, 0xC
	movs r1, 0x2E
	bl SetMonData
_081A9D9C:
	movs r0, 0
	str r0, [sp, 0xC]
	movs r2, 0
	lsls r4, r5, 1
_081A9DA4:
	ldr r1, [sp, 0x10]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	lsls r1, r2, 1
	adds r0, 0x4
	adds r0, r1
	ldrh r1, [r0]
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gEnemyParty
	bl SetMonMoveSlot
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	str r0, [sp, 0xC]
	adds r2, r0, 0
	cmp r2, 0x3
	ble _081A9DA4
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e1a
	adds r0, r1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x8B
	bls _081A9E0C
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, 0xF
	str r0, [sp, 0x10]
	movs r0, 0
	str r0, [sp, 0xC]
_081A9DF6:
	adds r1, r0, 0
	adds r1, 0x27
	ldr r0, =gEnemyParty
	add r2, sp, 0x10
	bl SetMonData
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	str r0, [sp, 0xC]
	cmp r0, 0x5
	ble _081A9DF6
_081A9E0C:
	ldr r0, =gEnemyParty
	bl CalculateMonStats
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GenerateBattlePyramidWildMon

	thumb_func_start sub_81A9E28
sub_81A9E28: @ 81A9E28
	push {lr}
	bl sub_81AA9E4
	lsls r0, 24
	ldr r1, =gUnknown_08613650
	lsrs r0, 20
	adds r0, r1
	ldrb r0, [r0, 0x4]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81A9E28

	thumb_func_start InBattlePyramid
InBattlePyramid: @ 81A9E40
	push {lr}
	ldr r0, =gMapHeader
	ldrh r1, [r0, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	bne _081A9E58
	movs r0, 0x1
	b _081A9E66
	.pool
_081A9E58:
	movs r0, 0xBD
	lsls r0, 1
	cmp r1, r0
	beq _081A9E64
	movs r0, 0
	b _081A9E66
_081A9E64:
	movs r0, 0x2
_081A9E66:
	pop {r1}
	bx r1
	thumb_func_end InBattlePyramid

	thumb_func_start sub_81A9E6C
sub_81A9E6C: @ 81A9E6C
	push {lr}
	movs r2, 0
	ldr r0, =gMapHeader
	ldrh r1, [r0, 0x12]
	ldr r0, =0x00000169
	cmp r1, r0
	beq _081A9E80
	adds r0, 0x11
	cmp r1, r0
	bne _081A9E82
_081A9E80:
	movs r2, 0x1
_081A9E82:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81A9E6C

	thumb_func_start sub_81A9E90
sub_81A9E90: @ 81A9E90
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _081A9EB8
	bl sub_81A9834
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca8
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, =0x0000400e
	movs r1, 0
	bl VarSet
	bl LoadPlayerParty
_081A9EB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9E90

	thumb_func_start sub_81A9EC8
sub_81A9EC8: @ 81A9EC8
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _081A9ED8
	bl DoSoftReset
_081A9ED8:
	pop {r0}
	bx r0
	thumb_func_end sub_81A9EC8

	thumb_func_start sub_81A9EDC
sub_81A9EDC: @ 81A9EDC
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gFacilityTrainers
	movs r1, 0x34
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0xC
	bl FrontierSpeechToString
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9EDC

	thumb_func_start sub_81A9EFC
sub_81A9EFC: @ 81A9EFC
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gFacilityTrainers
	movs r1, 0x34
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0x18
	bl FrontierSpeechToString
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9EFC

	thumb_func_start sub_81A9F1C
sub_81A9F1C: @ 81A9F1C
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gFacilityTrainers
	movs r1, 0x34
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	adds r0, 0x24
	bl FrontierSpeechToString
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9F1C

	thumb_func_start GetTrainerEncounterMusicIdInBattlePyramind
GetTrainerEncounterMusicIdInBattlePyramind: @ 81A9F3C
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	movs r4, 0
	ldr r3, =gFacilityClassToTrainerClass
	ldr r1, =gFacilityTrainers
	ldr r2, [r1]
	movs r1, 0x34
	muls r0, r1
	adds r0, r2
	ldrb r0, [r0]
	adds r0, r3
	ldrb r2, [r0]
	ldr r1, =gUnknown_08613B44
_081A9F58:
	ldrb r0, [r1]
	cmp r0, r2
	bne _081A9F70
	ldrb r0, [r1, 0x1]
	b _081A9F7A
	.pool
_081A9F70:
	adds r1, 0x4
	adds r4, 0x1
	cmp r4, 0x35
	bls _081A9F58
	movs r0, 0
_081A9F7A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetTrainerEncounterMusicIdInBattlePyramind

	thumb_func_start sub_81A9F80
sub_81A9F80: @ 81A9F80
	push {lr}
	ldr r0, =BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88
	bl ScriptContext1_SetupScript
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81A9F80

	thumb_func_start sub_81A9F90
sub_81A9F90: @ 81A9F90
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r1, =0x00000ca9
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 29
	ldr r2, =0x00000e1a
	adds r0, r4, r2
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x00000cb2
	adds r4, r1
	ldrh r1, [r4]
	cmp r1, 0x7
	bne _081AA020
	adds r0, 0x1
	lsls r7, r0, 24
	lsls r1, 24
	mov r8, r1
_081A9FCC:
	lsrs r0, r7, 24
	mov r2, r8
	lsrs r1, r2, 24
	bl sub_8162548
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r5
	bge _081AA004
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r4, =0x00000cb4
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r3
	beq _081AA004
	adds r6, r1, 0
_081A9FF0:
	adds r2, 0x1
	cmp r2, r5
	bge _081AA004
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r0, r4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _081A9FF0
_081AA004:
	cmp r2, r5
	bne _081A9FCC
	b _081AA062
	.pool
_081AA020:
	lsls r1, 24
	mov r8, r1
	lsls r7, r0, 24
_081AA026:
	lsrs r0, r7, 24
	mov r2, r8
	lsrs r1, r2, 24
	bl sub_8162548
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r5
	bge _081AA05E
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldr r4, =0x00000cb4
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r3
	beq _081AA05E
	adds r6, r1, 0
_081AA04A:
	adds r2, 0x1
	cmp r2, r5
	bge _081AA05E
	ldr r0, [r6]
	lsls r1, r2, 1
	adds r0, r4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne _081AA04A
_081AA05E:
	cmp r2, r5
	bne _081AA026
_081AA062:
	adds r0, r3, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81A9F90

	thumb_func_start sub_81AA078
sub_81AA078: @ 81AA078
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	str r0, [sp, 0x4]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x8]
	movs r0, 0x10
	bl AllocZeroed
	str r0, [sp, 0xC]
	bl sub_81AA96C
	mov r4, sp
	adds r4, 0x1
	mov r0, sp
	adds r1, r4, 0
	bl sub_81AA33C
	movs r7, 0
_081AA0A6:
	ldr r1, [sp, 0xC]
	adds r0, r1, r7
	ldrb r0, [r0]
	ldr r2, =0x00000169
	adds r0, r2
	lsls r0, 2
	ldr r1, =gMapLayouts
	adds r0, r1
	ldr r6, [r0]
	ldr r2, [r6, 0xC]
	mov r10, r2
	ldr r0, [sp, 0x4]
	ldr r1, =gUnknown_03005DC0
	str r0, [r1, 0x8]
	ldr r0, [r6]
	lsls r0, 2
	adds r2, r0, 0
	adds r2, 0xF
	str r2, [r1]
	ldr r0, [r6, 0x4]
	lsls r0, 2
	adds r0, 0xE
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x4]
	mov r9, r0
	adds r1, r7, 0
	cmp r7, 0
	bge _081AA0E0
	adds r1, r7, 0x3
_081AA0E0:
	asrs r1, 2
	ldr r4, [r6, 0x4]
	adds r0, r1, 0
	muls r0, r4
	adds r0, 0x7
	muls r2, r0
	lsls r1, 2
	subs r1, r7, r1
	ldr r3, [r6]
	adds r0, r1, 0
	muls r0, r3
	adds r0, 0x7
	adds r2, r0
	lsls r2, 1
	add r9, r2
	movs r1, 0
	mov r8, r1
	adds r2, r7, 0x1
	str r2, [sp, 0x10]
	cmp r8, r4
	bge _081AA1B6
_081AA10A:
	movs r0, 0
	mov r12, r0
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x14]
	cmp r12, r3
	bge _081AA1A2
	ldr r2, =gSaveBlock1Ptr
	str r2, [sp, 0x18]
	mov r4, r9
	mov r5, r10
_081AA120:
	ldrh r1, [r5]
	ldr r0, =0x000003ff
	ands r0, r1
	ldr r2, =0x0000028e
	cmp r0, r2
	bne _081AA194
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r7, r0
	beq _081AA194
	mov r0, sp
	ldrb r0, [r0]
	cmp r7, r0
	bne _081AA164
	ldr r1, [sp, 0x8]
	cmp r1, 0
	bne _081AA164
	ldr r2, [sp, 0x18]
	ldr r3, [r2]
	adds r2, r7, 0
	cmp r7, 0
	bge _081AA14E
	adds r2, r7, 0x3
_081AA14E:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r7, r1
	ldr r0, [r6]
	muls r0, r1
	add r0, r12
	strh r0, [r3]
	ldr r0, [r6, 0x4]
	muls r0, r2
	add r0, r8
	strh r0, [r3, 0x2]
_081AA164:
	ldrh r0, [r5]
	movs r1, 0xFC
	lsls r1, 8
	ands r1, r0
	ldr r2, =0x0000028d
	adds r0, r2, 0
	orrs r1, r0
	strh r1, [r4]
	ldr r3, [r6]
	b _081AA196
	.pool
_081AA194:
	strh r1, [r4]
_081AA196:
	adds r4, 0x2
	adds r5, 0x2
	movs r0, 0x1
	add r12, r0
	cmp r12, r3
	blt _081AA120
_081AA1A2:
	lsls r0, r3, 3
	adds r0, 0x1E
	add r9, r0
	lsls r0, r3, 1
	add r10, r0
	ldr r1, [sp, 0x14]
	mov r8, r1
	ldr r0, [r6, 0x4]
	cmp r8, r0
	blt _081AA10A
_081AA1B6:
	ldr r7, [sp, 0x10]
	cmp r7, 0xF
	bgt _081AA1BE
	b _081AA0A6
_081AA1BE:
	bl mapheader_run_script_with_tag_x1
	ldr r0, [sp, 0xC]
	bl Free
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81AA078

	thumb_func_start sub_81AA1D8
sub_81AA1D8: @ 81AA1D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r5, 0
	mov r6, sp
	adds r6, 0x1
	add r0, sp, 0x4
	mov r8, r0
	ldr r4, =gSaveBlock2Ptr
	ldr r3, =0x00000cb4
	ldr r0, =0x0000ffff
	adds r2, r0, 0
_081AA1F2:
	ldr r0, [r4]
	lsls r1, r5, 1
	adds r0, r3
	adds r0, r1
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	adds r5, 0x1
	cmp r5, 0x7
	ble _081AA1F2
	bl sub_81AA9E4
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, sp
	adds r1, r6, 0
	bl sub_81AA33C
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0xC7
	lsls r0, 4
	adds r1, r0
	ldr r2, =0x05000180
	mov r0, r8
	bl CpuSet
	movs r5, 0
_081AA22E:
	cmp r5, 0
	bne _081AA254
	ldr r1, =gUnknown_08613650
	lsls r0, r7, 4
	adds r0, r1
	ldrb r0, [r0, 0x3]
	b _081AA25C
	.pool
_081AA254:
	ldr r1, =gUnknown_08613650
	lsls r0, r7, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
_081AA25C:
	cmp r0, 0x4
	bhi _081AA2E4
	lsls r0, 2
	ldr r1, =_081AA274
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AA274:
	.4byte _081AA288
	.4byte _081AA292
	.4byte _081AA2A2
	.4byte _081AA2B0
	.4byte _081AA2CC
_081AA288:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_81AA398
	b _081AA2E4
_081AA292:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_81AA4D8
	b _081AA2BE
_081AA2A2:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	ldrb r1, [r6]
	adds r0, r4, 0
	bl sub_81AA4D8
	b _081AA2BE
_081AA2B0:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_81AA648
_081AA2BE:
	lsls r0, 24
	cmp r0, 0
	beq _081AA2E4
	adds r0, r4, 0
	bl sub_81AA398
	b _081AA2E4
_081AA2CC:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	ldrb r1, [r6]
	adds r0, r4, 0
	bl sub_81AA648
	lsls r0, 24
	cmp r0, 0
	beq _081AA2E4
	adds r0, r4, 0
	bl sub_81AA398
_081AA2E4:
	adds r5, 0x1
	cmp r5, 0x1
	ble _081AA22E
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81AA1D8

	thumb_func_start sub_81AA2F8
sub_81AA2F8: @ 81AA2F8
	push {r4,r5,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r5, =BattleFrontier_BattlePyramidEmptySquare_EventScript_252C4F
	ldr r4, =BattleFrontier_BattlePyramidEmptySquare_EventScript_252C6A
	movs r2, 0xC8
	lsls r2, 4
	adds r1, r0, r2
	movs r3, 0xC7
	lsls r3, 4
	adds r2, r0, r3
	movs r3, 0x3F
_081AA310:
	ldrb r0, [r2, 0x1]
	cmp r0, 0x3B
	beq _081AA328
	str r5, [r1]
	b _081AA32A
	.pool
_081AA328:
	str r4, [r1]
_081AA32A:
	adds r1, 0x18
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _081AA310
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81AA2F8

	thumb_func_start sub_81AA33C
sub_81AA33C: @ 81AA33C
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r5, =gSaveBlock2Ptr
	ldr r1, [r5]
	ldr r2, =0x00000e28
	adds r0, r1, r2
	ldrh r2, [r0]
	movs r3, 0xF
	ands r2, r3
	strb r2, [r4]
	ldr r7, =0x00000e22
	adds r1, r7
	ldrh r0, [r1]
	ands r0, r3
	strb r0, [r6]
	cmp r2, r0
	bne _081AA386
	ldr r1, [r5]
	ldr r2, =0x00000e28
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r3, r2, 0x1
	adds r0, r3, 0
	asrs r0, 4
	lsls r0, 4
	subs r0, r3, r0
	strb r0, [r4]
	adds r0, r1, r7
	ldrh r1, [r0]
	adds r2, r1, 0
	adds r2, 0xF
	adds r0, r2, 0
	asrs r0, 4
	lsls r0, 4
	subs r0, r2, r0
	strb r0, [r6]
_081AA386:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AA33C

	thumb_func_start sub_81AA398
sub_81AA398: @ 81AA398
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r5, 0
	bl sub_81AA9E4
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x10
	bl AllocZeroed
	str r0, [sp, 0x8]
	bl sub_81AA96C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e26
	adds r0, r1
	ldrh r4, [r0]
	movs r0, 0xF
	ands r4, r0
	ldr r0, [sp]
	cmp r0, 0
	bne _081AA3F0
	ldr r1, =gUnknown_08613650
	lsls r0, r6, 4
	adds r0, r1
	ldrb r0, [r0, 0x1]
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x4]
	b _081AA3FE
	.pool
_081AA3F0:
	ldr r1, =gUnknown_08613650
	lsls r0, r6, 4
	adds r0, r1
	ldrb r1, [r0]
	mov r10, r1
	ldrb r0, [r0, 0x1]
	str r0, [sp, 0x4]
_081AA3FE:
	movs r0, 0
	mov r8, r0
	cmp r8, r10
	bge _081AA4C0
_081AA406:
	movs r1, 0x1
	add r1, r8
	mov r9, r1
	b _081AA42E
	.pool
_081AA414:
	lsls r2, r4, 24
	lsrs r2, 24
	ldr r3, [sp, 0x4]
	add r3, r8
	lsls r3, 24
	lsrs r3, 24
	ldr r0, [sp]
	ldr r1, [sp, 0x8]
	bl sub_81AA760
	lsls r0, 24
	cmp r0, 0
	beq _081AA4B6
_081AA42E:
	ldr r0, =gBitTable
	mov r12, r0
	ldr r6, =gSaveBlock2Ptr
	ldr r7, =0x00000e28
	movs r3, 0x2
	lsls r0, r4, 2
	mov r1, r12
	adds r2, r0, r1
_081AA43E:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _081AA464
	ldr r0, [r6]
	adds r0, r7
	ldrh r1, [r0]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _081AA474
	b _081AA472
	.pool
_081AA464:
	ldr r0, [r6]
	adds r0, r7
	ldrh r1, [r0]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _081AA474
_081AA472:
	orrs r5, r3
_081AA474:
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _081AA480
	mov r2, r12
	movs r4, 0
_081AA480:
	ldr r0, [r6]
	ldr r1, =0x00000e26
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xF
	ands r1, r0
	cmp r4, r1
	bne _081AA4A6
	movs r1, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _081AA4A4
	movs r0, 0x6
	orrs r5, r0
	b _081AA4A6
	.pool
_081AA4A4:
	orrs r5, r1
_081AA4A6:
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _081AA43E
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _081AA414
_081AA4B6:
	movs r0, 0x1
	ands r5, r0
	mov r8, r9
	cmp r8, r10
	blt _081AA406
_081AA4C0:
	ldr r0, [sp, 0x8]
	bl Free
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81AA398

	thumb_func_start sub_81AA4D8
sub_81AA4D8: @ 81AA4D8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	movs r6, 0
	movs r7, 0
	movs r0, 0
	str r0, [sp, 0xC]
	bl sub_81AA9E4
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x10
	bl AllocZeroed
	str r0, [sp, 0x14]
	bl sub_81AA96C
	ldr r1, [sp]
	cmp r1, 0
	bne _081AA524
	ldr r1, =gUnknown_08613650
	lsls r0, r4, 4
	adds r0, r1
	ldrb r0, [r0, 0x1]
	str r0, [sp, 0x10]
	movs r0, 0
	b _081AA530
	.pool
_081AA524:
	ldr r1, =gUnknown_08613650
	lsls r0, r4, 4
	adds r0, r1
	ldrb r2, [r0]
	str r2, [sp, 0x10]
	ldrb r0, [r0, 0x1]
_081AA530:
	movs r3, 0
	str r3, [sp, 0x8]
	ldr r1, [sp, 0x10]
	asrs r1, 31
	str r1, [sp, 0x18]
	ldr r2, [sp, 0x10]
	cmp r3, r2
	bge _081AA622
	str r0, [sp, 0x1C]
	adds r3, r0, 0
	lsls r3, 24
	mov r9, r3
_081AA548:
	cmp r7, 0
	bne _081AA56E
	mov r0, r9
	lsrs r3, r0, 24
	ldr r0, [sp]
	ldr r1, [sp, 0x14]
	ldr r2, [sp, 0x4]
	bl sub_81AA760
	lsls r0, 24
	cmp r0, 0
	beq _081AA568
	movs r7, 0x1
	b _081AA56E
	.pool
_081AA568:
	ldr r1, [sp, 0xC]
	adds r1, 0x1
	str r1, [sp, 0xC]
_081AA56E:
	movs r0, 0x1
	ands r0, r7
	cmp r0, 0
	beq _081AA600
	ldr r2, =gUnknown_08613F46
	mov r8, r2
	ldr r3, [sp, 0x4]
	lsls r4, r3, 2
	adds r0, r6, r4
	add r0, r8
	ldrb r2, [r0]
	mov r0, r9
	lsrs r3, r0, 24
	ldr r0, [sp]
	ldr r1, [sp, 0x14]
	bl sub_81AA760
	lsls r0, 24
	ldr r1, [sp, 0x1C]
	mov r10, r1
	adds r5, r4, 0
	cmp r0, 0
	beq _081AA5E8
	ldr r4, [sp, 0xC]
	adds r4, 0x1
	b _081AA5C2
	.pool
_081AA5A8:
	adds r0, r6, r5
	adds r0, r2
	ldrb r2, [r0]
	mov r0, r10
	lsls r3, r0, 24
	lsrs r3, 24
	ldr r0, [sp]
	ldr r1, [sp, 0x14]
	bl sub_81AA760
	lsls r0, 24
	cmp r0, 0
	beq _081AA5E0
_081AA5C2:
	adds r6, 0x1
	ldr r0, =gUnknown_08613F46
	adds r1, r6, r5
	adds r1, r0
	ldrb r1, [r1]
	adds r2, r0, 0
	cmp r1, 0xFF
	beq _081AA5D6
	cmp r6, 0x3
	ble _081AA5D8
_081AA5D6:
	movs r6, 0
_081AA5D8:
	adds r7, 0x2
	asrs r0, r7, 1
	cmp r0, 0x4
	bne _081AA5A8
_081AA5E0:
	str r4, [sp, 0xC]
	b _081AA600
	.pool
_081AA5E8:
	adds r6, 0x1
	adds r0, r6, r4
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _081AA5F8
	cmp r6, 0x3
	ble _081AA5FA
_081AA5F8:
	movs r6, 0
_081AA5FA:
	ldr r1, [sp, 0xC]
	adds r1, 0x1
	str r1, [sp, 0xC]
_081AA600:
	asrs r0, r7, 1
	cmp r0, 0x4
	beq _081AA622
	movs r0, 0x1
	ands r7, r0
	ldr r2, [sp, 0x1C]
	adds r2, 0x1
	str r2, [sp, 0x1C]
	movs r3, 0x80
	lsls r3, 17
	add r9, r3
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	ldr r1, [sp, 0x10]
	cmp r0, r1
	blt _081AA548
_081AA622:
	movs r1, 0
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x18]
	subs r0, r2, r3
	asrs r0, 1
	ldr r2, [sp, 0xC]
	cmp r0, r2
	ble _081AA634
	movs r1, 0x1
_081AA634:
	adds r0, r1, 0
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81AA4D8

	thumb_func_start sub_81AA648
sub_81AA648: @ 81AA648
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r6, r1, 24
	movs r4, 0
	movs r7, 0
	movs r0, 0
	mov r8, r0
	bl sub_81AA9E4
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x10
	bl AllocZeroed
	str r0, [sp, 0x8]
	bl sub_81AA96C
	ldr r1, [sp]
	cmp r1, 0
	bne _081AA694
	ldr r1, =gUnknown_08613650
	lsls r0, r5, 4
	adds r0, r1
	ldrb r0, [r0, 0x1]
	mov r10, r0
	movs r0, 0
	b _081AA6A0
	.pool
_081AA694:
	ldr r1, =gUnknown_08613650
	lsls r0, r5, 4
	adds r0, r1
	ldrb r2, [r0]
	mov r10, r2
	ldrb r0, [r0, 0x1]
_081AA6A0:
	movs r3, 0
	str r3, [sp, 0x4]
	mov r1, r10
	asrs r1, 31
	str r1, [sp, 0xC]
	cmp r3, r10
	bge _081AA73E
	ldr r2, =gUnknown_08613F46
	mov r9, r2
	lsls r5, r6, 2
	lsls r6, r0, 24
_081AA6B6:
	adds r0, r4, r5
	add r0, r9
	ldrb r2, [r0]
	lsrs r3, r6, 24
	ldr r0, [sp]
	ldr r1, [sp, 0x8]
	bl sub_81AA760
	lsls r0, 24
	cmp r0, 0
	beq _081AA714
	adds r7, 0x1
	b _081AA6EE
	.pool
_081AA6D8:
	adds r0, r4, r5
	adds r0, r1
	ldrb r2, [r0]
	lsrs r3, r6, 24
	ldr r0, [sp]
	ldr r1, [sp, 0x8]
	bl sub_81AA760
	lsls r0, 24
	cmp r0, 0
	beq _081AA728
_081AA6EE:
	adds r4, 0x1
	adds r0, r4, r5
	add r0, r9
	ldrb r0, [r0]
	ldr r1, =gUnknown_08613F46
	cmp r0, 0xFF
	beq _081AA700
	cmp r4, 0x3
	ble _081AA702
_081AA700:
	movs r4, 0
_081AA702:
	movs r3, 0x1
	add r8, r3
	mov r0, r8
	cmp r0, 0x4
	bne _081AA6D8
	b _081AA728
	.pool
_081AA714:
	adds r4, 0x1
	adds r0, r4, r5
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _081AA724
	cmp r4, 0x3
	ble _081AA726
_081AA724:
	movs r4, 0
_081AA726:
	adds r7, 0x1
_081AA728:
	mov r1, r8
	cmp r1, 0x4
	beq _081AA73E
	movs r2, 0x80
	lsls r2, 17
	adds r6, r2
	ldr r3, [sp, 0x4]
	adds r3, 0x1
	str r3, [sp, 0x4]
	cmp r3, r10
	blt _081AA6B6
_081AA73E:
	movs r1, 0
	mov r2, r10
	ldr r3, [sp, 0xC]
	subs r0, r2, r3
	asrs r0, 1
	cmp r0, r7
	ble _081AA74E
	movs r1, 0x1
_081AA74E:
	adds r0, r1, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81AA648

	thumb_func_start sub_81AA760
sub_81AA760: @ 81AA760
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r7, r3, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000e22
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081AA7D0
	movs r6, 0x7
_081AA792:
	movs r4, 0x7
	lsls r5, r6, 24
_081AA796:
	lsls r1, r4, 24
	lsrs r1, 24
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r0, r9
	lsrs r2, r5, 24
	mov r3, r10
	bl sub_81AA810
	lsls r0, 24
	cmp r0, 0
	beq _081AA7CC
	subs r4, 0x1
	cmp r4, 0
	bge _081AA796
	subs r6, 0x1
	movs r1, 0x1
	negs r1, r1
	cmp r6, r1
	bgt _081AA792
	b _081AA7FC
	.pool
_081AA7CC:
	movs r0, 0
	b _081AA7FE
_081AA7D0:
	movs r6, 0
_081AA7D2:
	movs r4, 0
	lsls r5, r6, 24
_081AA7D6:
	lsls r1, r4, 24
	lsrs r1, 24
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r0, r9
	lsrs r2, r5, 24
	mov r3, r10
	bl sub_81AA810
	lsls r0, 24
	cmp r0, 0
	beq _081AA7CC
	adds r4, 0x1
	cmp r4, 0x7
	ble _081AA7D6
	adds r6, 0x1
	cmp r6, 0x7
	ble _081AA7D2
_081AA7FC:
	movs r0, 0x1
_081AA7FE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81AA760

	thumb_func_start sub_81AA810
sub_81AA810: @ 81AA810
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	lsls r5, 24
	lsrs r6, r5, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r1, r0, r1
	str r1, [sp, 0x8]
	add r3, r10
	ldrb r1, [r3]
	adds r1, 0x2C
	movs r0, 0x19
	bl Overworld_GetMapHeaderByGroupAndId
	adds r5, r0, 0
	movs r7, 0
	ldr r1, [r5, 0x4]
	ldrb r2, [r1]
	cmp r7, r2
	bge _081AA95A
	movs r0, 0x3
	ands r0, r4
	lsls r0, 3
	str r0, [sp, 0xC]
_081AA868:
	ldr r1, [r1, 0x4]
	lsls r2, r7, 1
	adds r0, r2, r7
	lsls r0, 3
	adds r3, r0, r1
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	ldr r1, [r5, 0x4]
	mov r12, r1
	mov r9, r2
	ldr r2, [sp, 0x4]
	cmp r0, r2
	bne _081AA950
	movs r4, 0x6
	ldrsh r0, [r3, r4]
	cmp r0, r8
	bne _081AA950
	ldr r0, [sp]
	cmp r0, 0
	bne _081AA896
	ldrb r0, [r3, 0x1]
	cmp r0, 0x3B
	bne _081AA8A2
_081AA896:
	ldr r1, [sp]
	cmp r1, 0x1
	bne _081AA950
	ldrb r0, [r3, 0x1]
	cmp r0, 0x3B
	bne _081AA950
_081AA8A2:
	movs r3, 0
	ldr r2, [r5, 0x4]
	mov r12, r2
	cmp r3, r6
	bge _081AA8DC
	ldr r4, [sp, 0x4]
	ldr r0, [sp, 0xC]
	adds r4, r0
	str r4, [sp, 0x10]
	mov r1, r10
	lsrs r0, r1, 2
	lsls r0, 3
	mov r2, r8
	adds r1, r2, r0
	ldr r2, [sp, 0x8]
	adds r2, 0x4
_081AA8C2:
	movs r4, 0
	ldrsh r0, [r2, r4]
	ldr r4, [sp, 0x10]
	cmp r0, r4
	bne _081AA8D4
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	cmp r0, r1
	beq _081AA8DC
_081AA8D4:
	adds r2, 0x18
	adds r3, 0x1
	cmp r3, r6
	blt _081AA8C2
_081AA8DC:
	cmp r3, r6
	bne _081AA950
	lsls r0, r6, 1
	mov r8, r0
	adds r0, r6
	lsls r0, 3
	ldr r1, [sp, 0x8]
	adds r5, r0, r1
	mov r3, r12
	ldr r2, [r3, 0x4]
	mov r4, r9
	adds r1, r4, r7
	lsls r1, 3
	adds r0, r5, 0
	adds r1, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldrh r0, [r5, 0x4]
	ldr r1, [sp, 0xC]
	adds r0, r1
	strh r0, [r5, 0x4]
	mov r2, r10
	lsrs r0, r2, 2
	lsls r0, 3
	ldrh r3, [r5, 0x6]
	adds r0, r3
	strh r0, [r5, 0x6]
	adds r0, r6, 0x1
	strb r0, [r5]
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3B
	beq _081AA940
	adds r0, r6, 0
	bl sub_81A9F90
	lsls r0, 16
	lsrs r7, r0, 16
	adds r4, r7, 0
	adds r0, r4, 0
	bl GetBattleFacilityTrainerGfxId
	strb r0, [r5, 0x1]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000cb4
	adds r0, r1
	add r0, r8
	strh r4, [r0]
_081AA940:
	movs r0, 0
	b _081AA95C
	.pool
_081AA950:
	adds r7, 0x1
	mov r1, r12
	ldrb r2, [r1]
	cmp r7, r2
	blt _081AA868
_081AA95A:
	movs r0, 0x1
_081AA95C:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81AA810

	thumb_func_start sub_81AA96C
sub_81AA96C: @ 81AA96C
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r2, =0x00000e22
	adds r1, r0, r2
	ldrh r4, [r1]
	ldr r1, =0x00000e24
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	orrs r4, r0
	bl sub_81AA9E4
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r2, =gUnknown_08613650+0x5
	mov r12, r2
	movs r7, 0x7
_081AA994:
	adds r2, r6, r3
	adds r0, r4, 0
	ands r0, r7
	lsls r1, r5, 4
	adds r0, r1
	add r0, r12
	ldrb r0, [r0]
	strb r0, [r2]
	asrs r4, 3
	cmp r3, 0x7
	bne _081AA9C0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000e26
	adds r0, r1, r2
	ldrh r4, [r0]
	ldr r0, =0x00000e28
	adds r1, r0
	ldrh r0, [r1]
	lsls r0, 16
	orrs r4, r0
	asrs r4, 8
_081AA9C0:
	adds r3, 0x1
	cmp r3, 0xF
	ble _081AA994
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AA96C

	thumb_func_start sub_81AA9E4
sub_81AA9E4: @ 81AA9E4
	push {r4,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r4, [r0]
	ldr r1, =0x00000e28
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =0x00000cb2
	adds r4, r0
	ldrh r0, [r4]
	ldr r1, =gUnknown_08613794
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0x21
	bhi _081AAA38
	ldr r1, =gUnknown_08613750
	lsls r0, r2, 1
	adds r0, r1
_081AAA10:
	ldrb r1, [r0]
	cmp r3, r1
	bge _081AAA30
	ldrb r0, [r0, 0x1]
	b _081AAA3A
	.pool
_081AAA30:
	adds r0, 0x2
	adds r2, 0x1
	cmp r2, 0x21
	bls _081AAA10
_081AAA38:
	movs r0, 0
_081AAA3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81AA9E4

	thumb_func_start sub_81AAA40
sub_81AAA40: @ 81AAA40
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xC7
	lsls r1, 4
	adds r2, r0, r1
	movs r1, 0
	movs r3, 0xC7
	lsls r3, 4
	adds r0, r3
	b _081AAA6E
	.pool
_081AAA5C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bhi _081AAA74
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r2
_081AAA6E:
	ldrb r0, [r0]
	cmp r0, 0
	bne _081AAA5C
_081AAA74:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_81AAA40

	thumb_func_start sub_81AAA7C
sub_81AAA7C: @ 81AAA7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	lsls r1, r0, 2
	adds r1, r0
	movs r0, 0
	mov r12, r0
	lsls r4, r1, 1
	ldr r7, =0x00000e2c
	movs r6, 0
	ldr r5, =0x00000e54
	lsls r2, r1, 2
_081AAA9E:
	mov r1, r8
	ldr r0, [r1]
	adds r1, r0, r7
	adds r1, r2
	strh r6, [r1]
	adds r1, r3, r4
	adds r0, r5
	adds r0, r1
	mov r1, r12
	strb r1, [r0]
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x9
	ble _081AAA9E
	movs r0, 0x15
	movs r1, 0x1
	bl AddPyramidBagItem
	movs r0, 0x22
	movs r1, 0x1
	bl AddPyramidBagItem
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AAA7C

	thumb_func_start GetBattlePyramidPickupItemId
GetBattlePyramidPickupItemId: @ 81AAAE0
	push {r4-r6,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000ca9
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r6, r0, 30
	lsls r0, r6, 1
	ldr r2, =0x00000e1a
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	ble _081AAB0A
	movs r4, 0x13
_081AAB0A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r3, =gUnknown_08613F86
	ldrb r0, [r3]
	lsls r5, r4, 2
	cmp r0, r2
	bgt _081AAB36
_081AAB28:
	adds r1, 0x1
	cmp r1, 0x9
	bhi _081AAB3A
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	ble _081AAB28
_081AAB36:
	cmp r1, 0x9
	bls _081AAB3C
_081AAB3A:
	movs r1, 0x9
_081AAB3C:
	cmp r6, 0
	bne _081AAB58
	ldr r2, =gUnknown_0861379C
	b _081AAB5A
	.pool
_081AAB58:
	ldr r2, =gUnknown_0861392C
_081AAB5A:
	lsls r1, 1
	adds r0, r5, r4
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBattlePyramidPickupItemId

	.align 2, 0 @ Don't pad with nop.
