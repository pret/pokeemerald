	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




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
	ldr r2, =sPickupItemsLvl50
	b _081AAB5A
	.pool
_081AAB58:
	ldr r2, =sPickupItemsLvlOpen
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
