	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80DF080
sub_80DF080: @ 80DF080
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gContestResources
	ldr r3, [r2]
	ldr r5, [r3, 0x10]
	ldrb r1, [r5, 0x1]
	movs r7, 0x1
	adds r0, r7, 0
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	bne _080DF0D2
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	ble _080DF0D2
	ldr r1, [r3, 0x4]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF0D2
	ldr r1, [r3, 0x1C]
	lsls r2, r4, 4
	adds r1, r2, r1
	ldrb r3, [r1, 0xC]
	movs r0, 0x1
	orrs r0, r3
	strb r0, [r1, 0xC]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	adds r2, r0
	ldrb r0, [r2, 0xE]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0xE]
_080DF0D2:
	ldr r3, [r6]
	ldr r1, [r3, 0x4]
	lsls r2, r4, 3
	subs r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	adds r7, r2, 0
	cmp r0, 0
	beq _080DF0FA
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF0FA:
	ldr r3, [r6]
	ldr r2, [r3, 0x10]
	ldrb r1, [r2, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF126
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _080DF126
	movs r0, 0x2
	ldrsb r0, [r2, r0]
	cmp r0, 0x3C
	bne _080DF126
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x4
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF126:
	ldr r3, [r6]
	ldr r1, [r3, 0x4]
	subs r0, r7, r4
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080DF14E
	ldrb r0, [r2, 0x16]
	cmp r0, 0
	beq _080DF14E
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF14E:
	movs r3, 0
	movs r5, 0
_080DF152:
	cmp r3, r4
	beq _080DF180
	ldr r1, [r6]
	ldr r0, [r1, 0x4]
	adds r0, r5, r0
	ldrb r0, [r0, 0xE]
	cmp r0, 0
	beq _080DF180
	ldr r0, [r1, 0x1C]
	lsls r2, r4, 4
	adds r2, r0
	ldrb r0, [r2, 0xC]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	lsls r2, r3, 4
	adds r2, r0
	ldrb r0, [r2, 0xC]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xC]
_080DF180:
	adds r5, 0x1C
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF152
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	subs r0, r7, r4
	lsls r5, r0, 2
	adds r1, r5, r1
	ldrb r3, [r1, 0xC]
	movs r0, 0x6
	ands r0, r3
	cmp r0, 0
	bne _080DF1A6
	ldrb r1, [r1, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080DF1BC
_080DF1A6:
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x20
	orrs r0, r2
	strb r0, [r1, 0xC]
	b _080DF1F6
	.pool
_080DF1BC:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	bne _080DF1F6
	ldr r2, [r2, 0x1C]
	lsls r3, r4, 4
	adds r2, r3, r2
	ldrb r0, [r2, 0xC]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r6]
	ldr r1, [r0, 0x1C]
	adds r1, r3, r1
	ldrb r0, [r1, 0xE]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1, 0xE]
	ldr r1, [r6]
	ldr r0, [r1, 0x1C]
	adds r3, r0
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	adds r3, r0
	ldr r0, [r1, 0x4]
	adds r0, r5, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r3]
_080DF1F6:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	subs r0, r7, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080DF21A
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1, 0xD]
_080DF21A:
	ldr r2, [r6]
	ldr r0, [r2]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bne _080DF24A
	ldr r3, [r2, 0x10]
	ldrb r1, [r3, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF24A
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0
	bge _080DF24A
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x20
	orrs r0, r2
	strb r0, [r1, 0xD]
_080DF24A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF080

	thumb_func_start sub_80DF250
sub_80DF250: @ 80DF250
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	movs r1, 0
	movs r0, 0
	str r0, [sp, 0x20]
	movs r4, 0
	ldr r6, =gContestResources
	mov r2, sp
	adds r2, 0xC
	str r2, [sp, 0x28]
	mov r3, sp
	adds r3, 0x14
	str r3, [sp, 0x2C]
	mov r7, sp
	adds r7, 0x2
	str r7, [sp, 0x24]
	ldr r5, =gContestFinalStandings
	movs r2, 0
	movs r3, 0x80
	lsls r3, 17
_080DF280:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF298
	lsrs r0, r2, 24
	str r0, [sp, 0x20]
	b _080DF29E
	.pool
_080DF298:
	cmp r0, 0x3
	bne _080DF29E
	lsrs r1, r2, 24
_080DF29E:
	adds r2, r3
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DF280
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	lsls r1, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x1
	orrs r0, r2
	strb r0, [r1, 0xD]
	movs r4, 0
	ldr r1, [sp, 0x20]
	lsls r1, 4
	str r1, [sp, 0x30]
	mov r9, r4
	mov r10, r4
_080DF2C2:
	ldr r2, [sp, 0x20]
	cmp r4, r2
	beq _080DF2EE
	ldr r1, =gUnknown_02039F08
	lsls r0, r2, 1
	adds r0, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	add r1, r10
	movs r6, 0
	ldrsh r0, [r1, r6]
	subs r2, r0
	cmp r2, 0x32
	bgt _080DF2EE
	ldr r7, =gContestResources
	ldr r0, [r7]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF2EE:
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	mov r3, r9
	adds r2, r3, r0
	ldrb r1, [r2, 0xE]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080DF30A
	ldrb r0, [r2, 0xD]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF30A:
	movs r5, 0
	ldr r2, =gContestMonConditions
	add r2, r10
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r7, =gContestMonConditions
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r1, r0
	blt _080DF336
	adds r3, r2, 0
	adds r2, r7, 0
_080DF322:
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	bgt _080DF336
	movs r6, 0
	ldrsh r1, [r3, r6]
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DF322
_080DF336:
	cmp r5, 0x4
	bne _080DF354
	ldr r1, =gContestFinalStandings
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DF354
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF354:
	movs r3, 0
	mov r12, r3
	mov r8, r3
	movs r5, 0
	ldr r0, =gContestMonConditions
	add r0, r10
	movs r7, 0
	ldrsh r6, [r0, r7]
	str r6, [sp, 0x34]
	ldr r2, =gContestMonConditions
	ldr r0, =gUnknown_02039F18
	mov r1, r10
	adds r6, r1, r0
	adds r3, r0, 0
_080DF370:
	movs r7, 0
	ldrsh r0, [r2, r7]
	ldr r1, [sp, 0x34]
	cmp r1, r0
	ble _080DF37E
	movs r7, 0x1
	mov r12, r7
_080DF37E:
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble _080DF38E
	movs r0, 0x1
	mov r8, r0
_080DF38E:
	adds r2, 0x2
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DF370
	mov r1, r12
	cmp r1, 0
	bne _080DF3B4
	mov r2, r8
	cmp r2, 0
	bne _080DF3B4
	ldr r3, =gContestResources
	ldr r0, [r3]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF3B4:
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	mov r7, r9
	adds r2, r7, r0
	ldrb r1, [r2, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DF3D0
	ldrb r0, [r2, 0xD]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF3D0:
	movs r0, 0x10
	add r9, r0
	movs r1, 0x2
	add r10, r1
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080DF3E0
	b _080DF2C2
_080DF3E0:
	movs r4, 0
	movs r5, 0
	movs r3, 0
	ldr r2, [sp, 0x28]
	mov r1, sp
_080DF3EA:
	strh r3, [r1]
	adds r0, r2, r4
	strb r5, [r0]
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x4
	ble _080DF3EA
	mov r1, sp
	ldr r0, =0x0000ffff
	strh r0, [r1, 0xA]
	movs r0, 0
	ldr r2, [sp, 0x28]
	strb r0, [r2, 0x5]
	movs r4, 0
	ldr r0, =gContestResources
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [sp, 0x30]
_080DF40E:
	mov r3, r8
	ldr r0, [r3, 0x1C]
	adds r0, r7, r0
	lsls r1, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	adds r4, 0x1
	mov r12, r4
	cmp r0, 0
	beq _080DF450
	ldr r0, =gContestResources
	ldr r6, [r0]
	ldr r3, [sp, 0x28]
	mov r4, sp
	movs r5, 0x4
_080DF42C:
	ldr r0, [r6, 0x1C]
	adds r0, r7, r0
	adds r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _080DF440
	cmp r2, 0
	bne _080DF446
	strh r0, [r4]
_080DF440:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_080DF446:
	adds r3, 0x1
	adds r4, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _080DF42C
_080DF450:
	mov r4, r12
	cmp r4, 0x4
	ble _080DF40E
	mov r0, sp
	ldrh r0, [r0]
	ldr r6, [sp, 0x2C]
	strh r0, [r6]
	ldr r7, [sp, 0x28]
	ldrb r3, [r7]
	movs r6, 0
	movs r4, 0x1
	ldr r1, [sp, 0x24]
	ldrh r0, [r1]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _080DF4C0
	ldr r5, [sp, 0x2C]
	adds r7, r1, 0
	mov r2, sp
	adds r2, 0x2
_080DF478:
	ldr r0, [sp, 0x28]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r3, r0
	bcs _080DF4A4
	ldrh r0, [r2]
	strh r0, [r5]
	ldrb r3, [r1]
	movs r6, 0x1
	b _080DF4B6
	.pool
_080DF4A4:
	cmp r3, r0
	bne _080DF4B6
	lsls r0, r6, 1
	adds r0, r5, r0
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080DF4B6:
	adds r2, 0x2
	adds r4, 0x1
	ldrh r0, [r2]
	cmp r0, r7
	bne _080DF478
_080DF4C0:
	bl Random
	ldr r1, =gContestResources
	ldr r1, [r1]
	ldr r4, [r1, 0x1C]
	ldr r1, [sp, 0x30]
	adds r4, r1, r4
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 1
	ldr r2, [sp, 0x2C]
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r4, 0xA]
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF250

	thumb_func_start sub_80DF4F8
sub_80DF4F8: @ 80DF4F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DF514
	b _080DF6EE
_080DF514:
	movs r7, 0
	movs r3, 0
	ldr r0, =gContestResources
	mov r12, r0
_080DF51C:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF528
	lsls r0, r3, 24
	lsrs r7, r0, 24
_080DF528:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF51C
	movs r1, 0
	mov r9, r1
	mov r10, r1
	movs r3, 0
	lsls r2, r7, 1
	lsls r4, r7, 4
	mov r8, r4
	ldr r1, =gContestMonConditions
	adds r0, r2, r1
	movs r6, 0
	ldrsh r5, [r0, r6]
	str r5, [sp, 0x8]
	adds r5, r1, 0
	ldr r0, =gUnknown_02039F18
	adds r2, r0
	adds r4, r0, 0
_080DF54E:
	movs r1, 0
	ldrsh r0, [r5, r1]
	ldr r6, [sp, 0x8]
	cmp r6, r0
	bge _080DF562
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080DF562:
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bge _080DF578
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_080DF578:
	adds r5, 0x2
	adds r4, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF54E
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrb r1, [r0, 0xC]
	movs r4, 0
	movs r2, 0x1
	movs r3, 0x7
_080DF592:
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _080DF5A0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080DF5A0:
	lsrs r1, 1
	subs r3, 0x1
	cmp r3, 0
	bge _080DF592
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrb r1, [r0, 0xC]
	movs r4, 0
	movs r2, 0
	movs r3, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DF5DC
	cmp r5, 0
	beq _080DF5F6
_080DF5D6:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080DF5DC:
	lsrs r1, 1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, 0x1
	cmp r3, 0x7
	bgt _080DF5F6
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DF5DC
	cmp r5, r4
	bne _080DF5D6
_080DF5F6:
	movs r1, 0x1
	adds r0, r1, 0
	lsls r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r7, 0
	bne _080DF628
	mov r0, sp
	strb r1, [r0]
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	ldrb r4, [r0, 0x1D]
	movs r3, 0x2
	b _080DF638
	.pool
_080DF628:
	mov r1, sp
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	ldrb r4, [r0, 0xD]
	movs r3, 0x1
_080DF638:
	mov r12, r1
	movs r5, 0x1
	lsls r2, 24
	str r2, [sp, 0x4]
	cmp r3, 0x3
	bgt _080DF682
_080DF644:
	cmp r3, r7
	beq _080DF67C
	mov r6, r12
	ldr r2, [r6]
	ldr r0, [r2, 0x1C]
	lsls r1, r3, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0xD]
	cmp r4, r0
	bcs _080DF66C
	mov r0, sp
	strb r3, [r0]
	ldr r0, [r2, 0x1C]
	adds r0, r1, r0
	ldrb r4, [r0, 0xD]
	movs r5, 0x1
	b _080DF67C
	.pool
_080DF66C:
	cmp r4, r0
	bne _080DF67C
	mov r1, sp
	adds r0, r1, r5
	strb r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080DF67C:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF644
_080DF682:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	add r0, sp
	ldrb r6, [r0]
	movs r2, 0x80
	movs r3, 0
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r0, [r0, 0x1C]
	lsls r1, r6, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0xD]
	ands r0, r2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080DF6C4
_080DF6AE:
	lsrs r2, 1
	adds r3, 0x1
	cmp r3, 0x7
	bgt _080DF6C4
	ldr r0, [r5]
	ldr r0, [r0, 0x1C]
	adds r0, r1, r0
	ldrb r4, [r0, 0xD]
	ands r4, r2
	cmp r4, 0
	beq _080DF6AE
_080DF6C4:
	mov r0, r9
	bl ContestLiveUpdates_BeforeInterview_1
	mov r0, r10
	bl ContestLiveUpdates_BeforeInterview_2
	ldr r5, [sp, 0x4]
	lsrs r0, r5, 24
	bl ContestLiveUpdates_BeforeInterview_3
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrh r0, [r0, 0xA]
	bl ContestLiveUpdates_BeforeInterview_4
	adds r0, r4, 0
	adds r1, r6, 0
	bl ContestLiveUpdates_BeforeInterview_5
_080DF6EE:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF4F8

	thumb_func_start sub_80DF704
sub_80DF704: @ 80DF704
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r4, r0, 0
	cmp r1, 0
	bne _080DF72C
	cmp r3, 0
	bne _080DF728
	movs r0, 0x2
	b _080DF72E
	.pool
_080DF728:
	movs r0, 0x3
	b _080DF72E
_080DF72C:
	movs r0, 0
_080DF72E:
	strb r0, [r2]
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF746
	bl sub_80DAEA4
	bl sub_80DB2BC
	b _080DF74A
_080DF746:
	bl sub_80DF750
_080DF74A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF704

	thumb_func_start sub_80DF750
sub_80DF750: @ 80DF750
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r0, =gUnknown_020322D5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF766
	b _080DF924
_080DF766:
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080DF77C
	b _080DF924
_080DF77C:
	movs r7, 0
	mov r2, sp
	adds r2, 0x18
	str r2, [sp, 0x30]
_080DF784:
	adds r0, r7, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF784
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080DF874
	movs r7, 0
	movs r2, 0x7
	mov r10, r2
	ldr r0, [sp, 0x30]
	mov r9, r0
_080DF7AE:
	add r0, sp, 0x4
	ldr r1, =gText_CDot
	bl StringCopy
	adds r5, r0, 0
	ldr r0, =gUnknown_02039F26
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r1, r10
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	lsls r0, r7, 4
	adds r0, r1
	ldrb r4, [r0, 0xC]
	movs r6, 0x7
	adds r2, r7, 0x1
	mov r8, r2
_080DF7DE:
	movs r1, 0x1
	ands r1, r4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	lsrs r4, 1
	lsls r0, r6, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r6, r0, 24
	asrs r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bgt _080DF7DE
	movs r6, 0
	ldr r4, =gUnknown_02039F26
	ldr r3, [sp, 0x30]
_080DF80A:
	lsls r0, r6, 24
	asrs r0, 24
	adds r2, r3, r0
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r5, r0, 24
	cmp r5, 0x4
	ble _080DF80A
	mov r0, r9
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r4, r7, r4
	ldrb r0, [r4]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	ldrb r0, [r4]
	mov r1, sp
	adds r1, r5
	adds r1, 0x4
	mov r2, r10
	str r2, [sp]
	movs r2, 0x37
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF7AE
	b _080DF920
	.pool
_080DF874:
	movs r7, 0
	mov r2, sp
	adds r2, 0x6
	str r2, [sp, 0x2C]
	ldr r0, [sp, 0x30]
	mov r9, r0
	movs r1, 0x7
	mov r10, r1
_080DF884:
	add r0, sp, 0x4
	ldr r1, =gText_BDot
	bl StringCopy
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	lsls r0, r7, 4
	adds r0, r1
	ldrb r4, [r0, 0xD]
	ldr r5, [sp, 0x2C]
	movs r6, 0x7
	adds r2, r7, 0x1
	mov r8, r2
_080DF8A0:
	movs r1, 0x1
	ands r1, r4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	lsrs r4, 1
	lsls r0, r6, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r6, r0, 24
	asrs r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bgt _080DF8A0
	movs r6, 0
	ldr r4, =gUnknown_02039F26
	ldr r3, [sp, 0x30]
_080DF8CC:
	lsls r0, r6, 24
	asrs r0, 24
	adds r2, r3, r0
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r5, r0, 24
	cmp r5, 0x4
	ble _080DF8CC
	mov r0, r9
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r4, r7, r4
	ldrb r0, [r4]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	ldrb r0, [r4]
	mov r1, sp
	adds r1, r5
	adds r1, 0x4
	mov r2, r10
	str r2, [sp]
	movs r2, 0x37
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF884
_080DF920:
	bl sub_80DB2BC
_080DF924:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF750

	thumb_func_start sub_80DF940
sub_80DF940: @ 80DF940
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x2
	ldrb r0, [r4]
	cmp r0, 0xFC
	bne _080DF956
	ldrb r0, [r4, 0x1]
	cmp r0, 0x15
	bne _080DF956
	movs r0, 0x2
	b _080DF9CC
_080DF956:
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _080DF9CA
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _080DF9CA
_080DF96A:
	ldrb r1, [r4]
	adds r0, r1, 0
	adds r0, 0x45
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x33
	bls _080DF9BE
	adds r0, r1, 0
	adds r0, 0x5F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bls _080DF9BE
	adds r0, r1, 0
	cmp r0, 0
	beq _080DF9BE
	cmp r0, 0xAD
	beq _080DF9BE
	cmp r0, 0xB8
	beq _080DF9BE
	cmp r0, 0xAB
	beq _080DF9BE
	cmp r0, 0xAC
	beq _080DF9BE
	cmp r0, 0xB5
	beq _080DF9BE
	cmp r0, 0xB6
	beq _080DF9BE
	cmp r0, 0xBA
	beq _080DF9BE
	cmp r0, 0xAE
	beq _080DF9BE
	cmp r0, 0xB0
	beq _080DF9BE
	cmp r0, 0xB1
	beq _080DF9BE
	cmp r0, 0xB2
	beq _080DF9BE
	cmp r0, 0xB3
	beq _080DF9BE
	cmp r0, 0xB1
	bne _080DF9C8
_080DF9BE:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _080DF96A
	b _080DF9CA
_080DF9C8:
	movs r5, 0x1
_080DF9CA:
	adds r0, r5, 0
_080DF9CC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80DF940

	thumb_func_start sub_80DF9D4
sub_80DF9D4: @ 80DF9D4
	ldrb r2, [r0, 0x5]
	movs r1, 0xFF
	strb r1, [r0, 0x5]
	strb r2, [r0, 0x7]
	bx lr
	thumb_func_end sub_80DF9D4

	thumb_func_start sub_80DF9E0
sub_80DF9E0: @ 80DF9E0
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl StripExtCtrlCodes
	cmp r4, 0x1
	bne _080DF9F8
	movs r0, 0xFF
	strb r0, [r5, 0x5]
	movs r0, 0xFC
	strb r0, [r5, 0xA]
	b _080DFA00
_080DF9F8:
	ldrb r1, [r5, 0x5]
	movs r0, 0xFF
	strb r0, [r5, 0x5]
	strb r1, [r5, 0xA]
_080DFA00:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF9E0

	thumb_func_start sub_80DFA08
sub_80DFA08: @ 80DFA08
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r5, 0x2
	cmp r6, 0x1
	bne _080DFA28
	adds r0, r4, 0
	bl sub_80DF940
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl ConvertInternationalString
	b _080DFA3E
_080DFA28:
	ldrb r0, [r4, 0xA]
	cmp r0, 0xFC
	bne _080DFA38
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _080DFA3E
_080DFA38:
	strb r0, [r4, 0x5]
	movs r0, 0xFF
	strb r0, [r4, 0xA]
_080DFA3E:
	adds r4, r5, 0
	adds r4, 0xD
	cmp r6, 0x1
	bne _080DFA68
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	ldrb r0, [r4, 0x4]
	strb r0, [r4, 0x6]
	ldrb r0, [r4, 0x3]
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0x2]
	strb r0, [r4, 0x4]
	ldrb r0, [r4, 0x1]
	strb r0, [r4, 0x3]
	ldrb r0, [r5, 0xD]
	strb r0, [r4, 0x2]
	movs r0, 0x15
	strb r0, [r4, 0x1]
	movs r0, 0xFC
	strb r0, [r5, 0xD]
	b _080DFA70
_080DFA68:
	ldrb r0, [r4, 0x7]
	strb r0, [r4, 0x5]
	movs r0, 0xFF
	strb r0, [r4, 0x7]
_080DFA70:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80DFA08

	.align 2, 0 @ Don't pad with nop.
