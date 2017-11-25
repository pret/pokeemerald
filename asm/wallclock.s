	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8134EA4
sub_8134EA4: @ 8134EA4
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	bl RtcInitLocalTimeOffset
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =c2_080111BC
	str r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134EA4

	thumb_func_start c2_080111BC
c2_080111BC: @ 8134EE8
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08134F02
	bl FreeAllWindowBuffers
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_08134F02:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_080111BC

	thumb_func_start sub_8134F10
sub_8134F10: @ 8134F10
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08134F30
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8134F40
	str r0, [r1]
_08134F30:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134F10

	thumb_func_start sub_8134F40
sub_8134F40: @ 8134F40
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8135130
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08134F66
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8134F78
	str r0, [r1]
_08134F66:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134F40

	thumb_func_start sub_8134F78
sub_8134F78: @ 8134F78
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8134FB0
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134F78

	thumb_func_start sub_8134FB0
sub_8134FB0: @ 8134FB0
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08134FC6
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
_08134FC6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134FB0

	thumb_func_start sub_8134FD4
sub_8134FD4: @ 8134FD4
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x3C
	bls _08134FE4
	movs r0, 0x6
	b _08134FF6
_08134FE4:
	cmp r0, 0x1E
	bls _08134FEC
	movs r0, 0x3
	b _08134FF6
_08134FEC:
	cmp r1, 0xA
	bhi _08134FF4
	movs r0, 0x1
	b _08134FF6
_08134FF4:
	movs r0, 0x2
_08134FF6:
	pop {r1}
	bx r1
	thumb_func_end sub_8134FD4

	thumb_func_start sub_8134FFC
sub_8134FFC: @ 8134FFC
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	adds r0, r2, 0
	bl sub_8134FD4
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r5, 0x1
	beq _0813501E
	cmp r5, 0x2
	beq _08135030
	b _08135044
_0813501E:
	cmp r4, 0
	beq _08135026
	subs r0, r4, r1
	b _0813503C
_08135026:
	movs r2, 0xB4
	lsls r2, 1
	adds r0, r2, 0
	subs r0, r1
	b _0813503C
_08135030:
	movs r0, 0xB4
	lsls r0, 1
	subs r0, r1
	cmp r4, r0
	bge _08135042
	adds r0, r4, r1
_0813503C:
	lsls r0, 16
	lsrs r4, r0, 16
	b _08135044
_08135042:
	movs r4, 0
_08135044:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8134FFC

	thumb_func_start sub_813504C
sub_813504C: @ 813504C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	cmp r4, 0x1
	beq _08135060
	cmp r4, 0x2
	beq _081350A0
	b _081350DE
_08135060:
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xE]
	movs r5, 0xE
	ldrsh r0, [r1, r5]
	cmp r0, 0
	ble _08135080
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	b _081350DE
	.pool
_08135080:
	movs r0, 0x3B
	strh r0, [r1, 0xE]
	ldrh r2, [r1, 0xC]
	movs r6, 0xC
	ldrsh r0, [r1, r6]
	cmp r0, 0
	ble _08135092
	subs r0, r2, 0x1
	b _08135094
_08135092:
	movs r0, 0x17
_08135094:
	strh r0, [r1, 0xC]
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_81350E8
	b _081350DE
_081350A0:
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xE]
	movs r5, 0xE
	ldrsh r0, [r1, r5]
	cmp r0, 0x3A
	bgt _081350C0
	adds r0, r2, 0x1
	strh r0, [r1, 0xE]
	b _081350DE
	.pool
_081350C0:
	movs r5, 0
	strh r5, [r1, 0xE]
	ldrh r2, [r1, 0xC]
	movs r6, 0xC
	ldrsh r0, [r1, r6]
	cmp r0, 0x16
	bgt _081350D4
	adds r0, r2, 0x1
	strh r0, [r1, 0xC]
	b _081350D6
_081350D4:
	strh r5, [r1, 0xC]
_081350D6:
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_81350E8
_081350DE:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_813504C

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
