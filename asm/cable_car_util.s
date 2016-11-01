	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81520A8
sub_81520A8: @ 81520A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r0
	ldr r0, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	movs r0, 0
	lsrs r4, r3, 24
	cmp r0, r8
	bcs _08152122
_081520DA:
	ldr r2, [sp]
	movs r3, 0
	adds r6, r4, 0x1
	adds r0, 0x1
	mov r12, r0
	cmp r3, r7
	bcs _0815210C
	lsls r5, r4, 6
_081520EA:
	lsls r0, r2, 1
	adds r0, r5
	add r0, r10
	mov r1, r9
	strh r1, [r0]
	adds r1, r2, 0x1
	adds r0, r1, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r1, r0
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r7
	bcc _081520EA
_0815210C:
	adds r0, r6, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r6, r0
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, r12
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, r8
	bcc _081520DA
_08152122:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81520A8

	thumb_func_start sub_8152134
sub_8152134: @ 8152134
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r0
	ldr r0, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	lsls r4, 24
	lsrs r4, 24
	mov r9, r4
	movs r0, 0
	adds r5, r1, 0
	lsrs r4, r3, 24
	cmp r0, r9
	bcs _081521AE
_08152164:
	ldr r2, [sp]
	movs r3, 0
	adds r7, r4, 0x1
	adds r0, 0x1
	mov r8, r0
	cmp r3, r12
	bcs _08152198
	lsls r6, r4, 6
_08152174:
	lsls r0, r2, 1
	adds r0, r6
	add r0, r10
	ldrh r1, [r5]
	strh r1, [r0]
	adds r5, 0x2
	adds r1, r2, 0x1
	adds r0, r1, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r1, r0
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r12
	bcc _08152174
_08152198:
	adds r0, r7, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r7, r0
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, r8
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, r9
	bcc _08152164
_081521AE:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8152134

	thumb_func_start sub_81521C0
sub_81521C0: @ 81521C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	cmp r4, 0
	beq _081521FE
	cmp r4, 0x40
	bls _081521D6
	movs r4, 0x40
_081521D6:
	ldr r6, =gUnknown_0203ABB8
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r6]
	cmp r0, 0
	beq _081521FE
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 4
	bl AllocZeroed
	ldr r1, [r6]
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _08152208
	adds r0, r1, 0
	bl Free
	str r5, [r6]
_081521FE:
	movs r0, 0
	b _08152244
	.pool
_08152208:
	strb r4, [r1]
	cmp r5, r4
	bcs _08152242
	adds r3, r6, 0
	ldr r0, =gDefaultOamAttributes
	mov r12, r0
	movs r2, 0x4
	mov r8, r2
_08152218:
	ldr r0, [r3]
	ldr r2, [r0, 0x4]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 4
	adds r2, r1, r2
	mov r0, r12
	ldm r0!, {r6,r7}
	stm r2!, {r6,r7}
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r0, [r1, 0x19]
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x19]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r4
	bcc _08152218
_08152242:
	movs r0, 0x1
_08152244:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81521C0

	thumb_func_start sub_8152254
sub_8152254: @ 8152254
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gUnknown_0203ABB8
	ldr r2, [r0]
	adds r5, r0, 0
	cmp r2, 0
	bne _0815226C
	movs r0, 0
	b _081522C4
	.pool
_0815226C:
	ldrb r2, [r2]
	cmp r3, r2
	bcs _08152292
	ldr r0, =gUnknown_030024F8
	mov r12, r0
	ldr r4, =gDefaultOamAttributes
	adds r2, r5, 0
_0815227A:
	lsls r1, r3, 3
	add r1, r12
	adds r0, r4, 0
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r3, r0
	bcc _0815227A
_08152292:
	ldr r1, [r5]
	ldrb r0, [r1]
	lsls r2, r0, 1
	adds r2, r0
	ldr r0, [r1, 0x4]
	lsls r2, 4
	movs r1, 0
	bl memset
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0, 0x4]
	movs r1, 0
	movs r2, 0x8
	bl memset
	ldr r0, [r5]
	bl Free
	str r4, [r5]
	movs r0, 0x1
_081522C4:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8152254

	thumb_func_start sub_81522D4
sub_81522D4: @ 81522D4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, =gUnknown_0203ABB8
	ldr r1, [r0]
	adds r3, r0, 0
	cmp r1, 0
	beq _081522EC
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _081522F4
_081522EC:
	movs r0, 0
	b _081523D2
	.pool
_081522F4:
	ldrb r1, [r1]
	cmp r6, r1
	bcs _081523D0
	adds r7, r3, 0
	movs r0, 0x3
	mov r8, r0
_08152300:
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r5, r0, 4
	adds r2, r5, r1
	ldrb r1, [r2, 0x19]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x3
	bne _081523C2
	ldr r1, [r2, 0x2C]
	cmp r1, 0
	beq _08152322
	adds r0, r2, 0
	bl _call_via_r1
_08152322:
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r2, r5, r0
	ldrb r1, [r2, 0x19]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08152348
	lsls r0, r6, 3
	ldr r1, =gUnknown_030024F8
	adds r0, r1
	ldr r1, =gDefaultOamAttributes
	ldm r1!, {r2,r3}
	stm r0!, {r2,r3}
	b _081523C0
	.pool
_08152348:
	ldrb r0, [r2, 0xE]
	ldrb r4, [r2, 0xA]
	adds r0, r4
	strb r0, [r2]
	ldr r4, [r7]
	ldr r3, [r4, 0x4]
	adds r3, r5, r3
	movs r0, 0x8
	ldrsh r2, [r3, r0]
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	adds r2, r0
	ldr r1, =0x000001ff
	adds r0, r1, 0
	ands r2, r0
	ldrh r0, [r3, 0x2]
	ldr r1, =0xfffffe00
	mov r12, r1
	mov r1, r12
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x2]
	ldr r3, [r4, 0x4]
	adds r3, r5, r3
	ldrb r0, [r3, 0x19]
	lsls r0, 27
	lsrs r0, 30
	mov r2, r8
	ands r0, r2
	lsls r0, 2
	ldrb r1, [r3, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x5]
	ldr r4, [r7]
	ldr r2, [r4, 0x4]
	adds r2, r5, r2
	ldrh r3, [r2, 0x14]
	ldr r1, =0x000003ff
	adds r0, r1, 0
	adds r1, r3, 0
	ands r1, r0
	mov r12, r1
	ldrh r0, [r2, 0x4]
	ldr r3, =0xfffffc00
	adds r1, r3, 0
	ands r0, r1
	mov r1, r12
	orrs r0, r1
	strh r0, [r2, 0x4]
	lsls r1, r6, 3
	ldr r2, =gUnknown_030024F8
	ldr r0, [r4, 0x4]
	adds r1, r2
	adds r0, r5, r0
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
_081523C0:
	ldr r3, =gUnknown_0203ABB8
_081523C2:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08152300
_081523D0:
	movs r0, 0x1
_081523D2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81522D4

	thumb_func_start sub_81523F4
sub_81523F4: @ 81523F4
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0
	beq _08152430
	ldrh r0, [r4, 0x10]
	bl GetObjectTileRangeStartByTag
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _08152430
	strb r6, [r4, 0x18]
	ldrb r0, [r4, 0x1]
	lsrs r0, 6
	ldrb r1, [r4, 0x3]
	lsrs r1, 6
	bl sub_80355F8
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	adds r0, r5, r0
	strh r0, [r4, 0x14]
	movs r0, 0x1
	b _08152432
	.pool
_08152430:
	movs r0, 0
_08152432:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81523F4

	thumb_func_start sub_8152438
sub_8152438: @ 8152438
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203ABB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0815246C
	ldrb r1, [r0]
	cmp r2, r1
	bcs _0815246C
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r3, r0, r1
	ldrb r1, [r3, 0x19]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815246C
	str r4, [r3, 0x2C]
	adds r0, r2, 0
	b _0815246E
	.pool
_0815246C:
	movs r0, 0xFF
_0815246E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8152438

	thumb_func_start sub_8152474
sub_8152474: @ 8152474
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 16
	lsrs r5, r2, 16
	ldr r0, =gUnknown_0203ABB8
	ldr r0, [r0]
	cmp r0, 0
	beq _081524A8
	ldrb r1, [r0]
	cmp r3, r1
	bcs _081524A8
	ldr r1, [r0, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 4
	adds r2, r0, r1
	ldrb r1, [r2, 0x19]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081524A8
	cmp r4, 0x7
	bls _081524B0
_081524A8:
	movs r0, 0xFF
	b _081524BC
	.pool
_081524B0:
	lsls r1, r4, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r0, r1
	strh r5, [r0]
	adds r0, r3, 0
_081524BC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8152474

	thumb_func_start sub_81524C4
sub_81524C4: @ 81524C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r0
	ldr r0, [sp, 0x30]
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0xC]
	lsls r5, 24
	lsrs r5, 24
	mov r10, r5
	movs r5, 0
	ldr r0, =gUnknown_0203ABB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0815255E
	mov r1, r9
	cmp r1, 0
	bne _08152530
	b _0815255E
	.pool
_08152514:
	adds r5, r2, 0
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x30
	bl memset
	strb r4, [r5, 0x16]
	ldrb r0, [r5, 0x19]
	movs r1, 0x1
	orrs r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r5, 0x19]
	b _0815255A
_08152530:
	movs r4, 0
	ldrb r1, [r0]
	cmp r5, r1
	bcs _0815255A
	ldr r6, [r0, 0x4]
	adds r3, r1, 0
	movs r7, 0x1
_0815253E:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 4
	adds r2, r0, r6
	ldrb r1, [r2, 0x19]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08152514
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r3
	bcc _0815253E
_0815255A:
	cmp r5, 0
	bne _08152562
_0815255E:
	movs r0, 0xFF
	b _081525C0
_08152562:
	adds r1, r5, 0
	mov r0, r9
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, 0x10]
	mov r1, r8
	strh r1, [r5, 0x12]
	mov r2, sp
	ldrh r2, [r2, 0x4]
	strh r2, [r5, 0x8]
	mov r3, sp
	ldrh r3, [r3, 0x8]
	strh r3, [r5, 0xA]
	mov r0, r8
	bl IndexOfObjectPaletteTag
	lsls r0, 4
	ldrb r1, [r5, 0x5]
	movs r4, 0xF
	ands r4, r1
	orrs r4, r0
	strb r4, [r5, 0x5]
	mov r0, r10
	cmp r0, 0x3
	bhi _081525B6
	movs r1, 0x3
	ands r1, r0
	lsls r3, r1, 3
	ldrb r2, [r5, 0x19]
	movs r0, 0x19
	negs r0, r0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5, 0x19]
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r4, r0
	orrs r4, r1
	strb r4, [r5, 0x5]
_081525B6:
	adds r0, r5, 0
	ldr r1, [sp, 0xC]
	bl sub_81523F4
	ldrb r0, [r5, 0x16]
_081525C0:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81524C4

	thumb_func_start sub_81525D0
sub_81525D0: @ 81525D0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gUnknown_0203ABB8
	ldr r0, [r6]
	cmp r0, 0
	beq _081525F2
	ldr r1, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r4, r0, 4
	adds r2, r4, r1
	ldrb r1, [r2, 0x19]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081525FC
_081525F2:
	movs r0, 0xFF
	b _0815263C
	.pool
_081525FC:
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	movs r1, 0xA0
	strb r1, [r0]
	ldr r3, [r6]
	ldr r2, [r3, 0x4]
	adds r2, r4, r2
	ldrh r1, [r2, 0x2]
	ldr r0, =0xfffffe00
	ands r0, r1
	movs r1, 0xF0
	orrs r0, r1
	strh r0, [r2, 0x2]
	ldr r1, [r3, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x19]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x19]
	lsls r1, r5, 3
	ldr r0, =gUnknown_030024F8
	adds r1, r0
	ldr r0, =gDefaultOamAttributes
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	adds r0, r5, 0
_0815263C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81525D0

	.align 2, 0 @ Don't pad with nop.
