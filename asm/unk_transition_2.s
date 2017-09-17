	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81DB158
sub_81DB158: @ 81DB158
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7E8
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DB16A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DB16A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB158

	thumb_func_start sub_81DB190
sub_81DB190: @ 81DB190
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081DB1BE
	movs r0, 0x80
	str r0, [sp]
	str r1, [sp, 0x4]
	subs r0, 0x84
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x2D
	movs r2, 0xC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB212
_081DB1BE:
	cmp r1, 0x10
	bne _081DB1E6
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	subs r0, 0x4
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x59
	movs r1, 0x61
	movs r2, 0xFC
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB212
_081DB1E6:
	cmp r1, 0x20
	bne _081DB212
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	subs r0, 0x4
	str r0, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x97
	movs r1, 0x61
	movs r2, 0x84
	movs r3, 0x4
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB212:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB190

	thumb_func_start sub_81DB224
sub_81DB224: @ 81DB224
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB248
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DB158
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB248:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB224

	thumb_func_start sub_81DB258
sub_81DB258: @ 81DB258
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0862B7FC
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_081DB26A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _081DB26A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DB258

	thumb_func_start sub_81DB290
sub_81DB290: @ 81DB290
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _081DB2C2
	movs r2, 0x8E
	lsls r2, 1
	movs r0, 0x83
	str r0, [sp]
	movs r0, 0x23
	str r0, [sp, 0x4]
	subs r0, 0x26
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	b _081DB316
_081DB2C2:
	cmp r1, 0x10
	bne _081DB2EA
	movs r0, 0x83
	str r0, [sp]
	movs r0, 0x23
	str r0, [sp, 0x4]
	subs r0, 0x26
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	movs r0, 0x78
	movs r1, 0x50
	movs r2, 0x2C
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x12]
	b _081DB316
_081DB2EA:
	cmp r1, 0x20
	bne _081DB316
	movs r0, 0x83
	str r0, [sp]
	movs r0, 0x23
	str r0, [sp, 0x4]
	subs r0, 0x26
	str r0, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x79
	movs r1, 0x50
	movs r2, 0xA4
	movs r3, 0x8
	bl sub_81DA8BC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081DB316:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DB290

	thumb_func_start sub_81DB328
sub_81DB328: @ 81DB328
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081DB34C
	adds r0, r2, 0
	bl sub_81DAA20
	ldr r0, =sub_81DB258
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_081DB34C:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DB328

	.align 2, 0 @ Don't pad with nop.
