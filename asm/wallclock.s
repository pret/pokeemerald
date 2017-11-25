	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81350E8
sub_81350E8: @ 81350E8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0xC]
	cmp r3, 0x1
	beq _0813510C
	cmp r3, 0x2
	beq _0813511E
	b _0813512A
	.pool
_0813510C:
	cmp r0, 0xB
	beq _08135116
	cmp r0, 0x17
	beq _0813511A
	b _0813512A
_08135116:
	movs r0, 0
	b _08135128
_0813511A:
	strh r3, [r1, 0x12]
	b _0813512A
_0813511E:
	cmp r0, 0
	beq _08135128
	cmp r0, 0xC
	bne _0813512A
	movs r0, 0x1
_08135128:
	strh r0, [r1, 0x12]
_0813512A:
	pop {r0}
	bx r0
	thumb_func_end sub_81350E8

	thumb_func_start sub_8135130
sub_8135130: @ 8135130
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl RtcCalcLocalTime
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r6, r0, r1
	ldr r5, =gLocalTime
	movs r0, 0x2
	ldrsb r0, [r5, r0]
	strh r0, [r6, 0xC]
	movs r0, 0x3
	ldrsb r0, [r5, r0]
	strh r0, [r6, 0xE]
	movs r0, 0xE
	ldrsh r1, [r6, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	strh r0, [r6, 0x8]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	movs r1, 0xC
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	lsls r4, r0, 4
	subs r4, r0
	lsls r4, 1
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r1, 0xA
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	adds r4, r1
	strh r4, [r6, 0xA]
	movs r0, 0x2
	ldrsb r0, [r5, r0]
	cmp r0, 0xB
	bgt _081351A0
	movs r0, 0
	b _081351A2
	.pool
_081351A0:
	movs r0, 0x1
_081351A2:
	strh r0, [r6, 0x12]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8135130

	thumb_func_start sub_81351AC
sub_81351AC: @ 81351AC
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r4, [r0, 0x8]
	adds r7, r4, 0
	adds r0, r4, 0
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _081351D4
	adds r0, 0xF
_081351D4:
	lsls r0, 12
	lsrs r5, r0, 16
	adds r0, r4, 0
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _081351E8
	adds r0, 0xF
_081351E8:
	lsls r1, r0, 12
	lsrs r1, 16
	lsls r3, r5, 16
	lsrs r2, r3, 16
	negs r3, r3
	lsrs r3, 16
	str r1, [sp]
	movs r0, 0
	bl SetOamMatrix
	ldr r1, =gUnknown_085B22D0
	lsls r2, r7, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r3, r0, 16
	adds r1, 0x1
	adds r2, r1
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r3, 0x80
	bls _08135224
	movs r1, 0xFF
	lsls r1, 8
	adds r0, r1, 0
	orrs r3, r0
_08135224:
	cmp r2, 0x80
	bls _08135230
	movs r1, 0xFF
	lsls r1, 8
	adds r0, r1, 0
	orrs r2, r0
_08135230:
	strh r3, [r6, 0x24]
	strh r2, [r6, 0x26]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81351AC

	thumb_func_start sub_8135244
sub_8135244: @ 8135244
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r4, [r0, 0xA]
	adds r7, r4, 0
	adds r0, r4, 0
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0813526C
	adds r0, 0xF
_0813526C:
	lsls r0, 12
	lsrs r5, r0, 16
	adds r0, r4, 0
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08135280
	adds r0, 0xF
_08135280:
	lsls r1, r0, 12
	lsrs r1, 16
	lsls r3, r5, 16
	lsrs r2, r3, 16
	negs r3, r3
	lsrs r3, 16
	str r1, [sp]
	movs r0, 0x1
	bl SetOamMatrix
	ldr r1, =gUnknown_085B22D0
	lsls r2, r7, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r3, r0, 16
	adds r1, 0x1
	adds r2, r1
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r3, 0x80
	bls _081352BC
	movs r1, 0xFF
	lsls r1, 8
	adds r0, r1, 0
	orrs r3, r0
_081352BC:
	cmp r2, 0x80
	bls _081352C8
	movs r1, 0xFF
	lsls r1, 8
	adds r0, r1, 0
	orrs r2, r0
_081352C8:
	strh r3, [r6, 0x24]
	strh r2, [r6, 0x26]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135244

	thumb_func_start sub_81352DC
sub_81352DC: @ 81352DC
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0813531C
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0
	subs r0, 0x3C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08135308
	adds r0, r1, 0x5
	strh r0, [r4, 0x30]
_08135308:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x3B
	bgt _0813533C
	adds r0, r1, 0x1
	b _0813533A
	.pool
_0813531C:
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0
	subs r0, 0x2E
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _0813532E
	subs r0, r1, 0x5
	strh r0, [r4, 0x30]
_0813532E:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x4B
	ble _0813533C
	subs r0, r1, 0x1
_0813533A:
	strh r0, [r4, 0x30]
_0813533C:
	ldrh r0, [r4, 0x30]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r0, r1, 1
	cmp r0, 0
	bge _08135354
	ldr r1, =0x00000fff
	adds r0, r1
_08135354:
	asrs r0, 12
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r0, r1, 1
	cmp r0, 0
	bge _08135370
	ldr r2, =0x00000fff
	adds r0, r2
_08135370:
	asrs r0, 12
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81352DC

	thumb_func_start sub_8135380
sub_8135380: @ 8135380
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081353C0
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0
	subs r0, 0x69
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _081353AC
	adds r0, r1, 0x5
	strh r0, [r4, 0x30]
_081353AC:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x68
	bgt _081353E0
	adds r0, r1, 0x1
	b _081353DE
	.pool
_081353C0:
	ldrh r1, [r4, 0x30]
	adds r0, r1, 0
	subs r0, 0x5B
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _081353D2
	subs r0, r1, 0x5
	strh r0, [r4, 0x30]
_081353D2:
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x78
	ble _081353E0
	subs r0, r1, 0x1
_081353DE:
	strh r0, [r4, 0x30]
_081353E0:
	ldrh r0, [r4, 0x30]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r0, r1, 1
	cmp r0, 0
	bge _081353F8
	ldr r1, =0x00000fff
	adds r0, r1
_081353F8:
	asrs r0, 12
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r0, r1, 1
	cmp r0, 0
	bge _08135414
	ldr r2, =0x00000fff
	adds r0, r2
_08135414:
	asrs r0, 12
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8135380

	.align 2, 0 @ Don't pad with nop.
