	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_801209C
sub_801209C: @ 801209C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	mov r8, r5
	ldr r6, =gUnknown_03005000
	adds r0, r6, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _080120BA
	adds r0, r5, 0
	bl DestroyTask
_080120BA:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	movs r1, 0x96
	lsls r1, 17
	cmp r0, r1
	ble _080120E4
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	adds r0, r5, 0
	bl DestroyTask
_080120E4:
	ldr r1, =0x00000ccd
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801217C
	ldr r0, =gUnknown_03004140
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0801217C
	movs r2, 0x86
	lsls r2, 1
	adds r0, r6, r2
	bl ReadU16
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =0x00000119
	adds r0, r6, r2
	bl sub_8011CE4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _0801217C
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	ldr r7, =gUnknown_03007890
	lsls r4, r2, 5
	adds r2, r4, 0
	adds r2, 0x14
	ldr r1, [r7]
	adds r1, r2
	adds r1, 0x6
	bl sub_801200C
	cmp r0, 0
	bne _0801216C
	ldr r0, [r7]
	adds r1, r0, r4
	ldrb r0, [r1, 0x16]
	cmp r0, 0xFF
	beq _0801217C
	ldrh r0, [r1, 0x14]
	movs r1, 0x5A
	bl sub_800C12C
	lsls r0, 24
	cmp r0, 0
	bne _0801217C
	movs r0, 0xA
	strh r0, [r6, 0x4]
	adds r0, r5, 0
	bl DestroyTask
	b _0801217C
	.pool
_0801216C:
	movs r1, 0xE0
	lsls r1, 7
	movs r0, 0x2
	bl sub_8011A64
	mov r0, r8
	bl DestroyTask
_0801217C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801209C

	thumb_func_start sub_8012188
sub_8012188: @ 8012188
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	ldr r6, =gUnknown_03005000
	ldr r1, =0x00000ccf
	adds r0, r6, r1
	movs r7, 0
	strb r7, [r0]
	adds r0, r6, 0
	adds r0, 0xF1
	strb r7, [r0]
	ldr r1, =0x00000119
	adds r0, r6, r1
	adds r1, r3, 0
	bl StringCopy
	movs r1, 0x85
	lsls r1, 1
	adds r0, r6, r1
	adds r1, r5, 0
	movs r2, 0xD
	bl memcpy
	bl sub_800D658
	ldr r0, =sub_801209C
	movs r1, 0x2
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	strh r4, [r1, 0xA]
	ldr r0, =sub_800EB44
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	adds r2, r1, 0
	cmp r4, 0x45
	bne _08012210
	cmp r1, 0xFF
	beq _0801221E
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0, 0x16]
	b _0801221E
	.pool
_08012210:
	cmp r2, 0xFF
	beq _0801221E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r5
	strh r7, [r0, 0x16]
_0801221E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8012188

	thumb_func_start sub_8012224
sub_8012224: @ 8012224
	push {lr}
	ldr r0, =gUnknown_03005000
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08012238
	movs r0, 0
	b _0801223A
	.pool
_08012238:
	movs r0, 0x1
_0801223A:
	pop {r1}
	bx r1
	thumb_func_end sub_8012224

	thumb_func_start sub_8012240
sub_8012240: @ 8012240
	push {r4,lr}
	movs r1, 0
	ldr r0, =gUnknown_03004140
	ldrb r2, [r0]
	ldr r4, =gUnknown_03005000+0xCD1
	movs r3, 0x1
_0801224C:
	adds r0, r2, 0
	asrs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0801226C
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801226C
	movs r0, 0
	b _08012274
	.pool
_0801226C:
	adds r1, 0x1
	cmp r1, 0x3
	ble _0801224C
	movs r0, 0x1
_08012274:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8012240

	thumb_func_start sub_801227C
sub_801227C: @ 801227C
	push {r4,lr}
	movs r4, 0
_08012280:
	lsls r2, r4, 24
	lsrs r2, 24
	ldr r0, =gUnknown_082ED82C
	movs r1, 0
	bl nullsub_5
	adds r4, 0x1
	cmp r4, 0x13
	ble _08012280
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801227C

	thumb_func_start sub_801229C
sub_801229C: @ 801229C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1C
	movs r2, 0x13
	movs r3, 0x2
	bl nullsub_13
	ldr r4, =gUnknown_03007890
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	movs r1, 0x14
	movs r2, 0x1
	movs r3, 0x1
	bl nullsub_13
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	movs r1, 0x17
	movs r2, 0x1
	movs r3, 0x1
	bl nullsub_13
	ldr r0, =gUnknown_03005000
	ldrb r0, [r0, 0xC]
	cmp r0, 0x1
	bne _08012378
	movs r6, 0
	adds r7, r4, 0
	movs r5, 0x14
_080122E0:
	ldr r2, [r7]
	ldrb r0, [r2, 0x7]
	asrs r0, r6
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801231E
	lsls r0, r6, 5
	adds r0, r2, r0
	ldrh r0, [r0, 0x18]
	adds r4, r6, 0x3
	lsls r4, 24
	lsrs r4, 24
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r5
	adds r0, 0x6
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, [r7]
	adds r0, r5
	adds r0, 0x15
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
_0801231E:
	adds r5, 0x20
	adds r6, 0x1
	cmp r6, 0x3
	ble _080122E0
	movs r6, 0
	ldr r0, =gUnknown_03005000
	mov r8, r0
_0801232C:
	movs r5, 0
	adds r7, r6, 0x1
	lsls r0, r6, 3
	adds r2, r6, 0
	adds r2, 0xB
	subs r0, r6
	lsls r0, 1
	mov r1, r8
	adds r1, 0x14
	adds r4, r0, r1
	lsls r6, r2, 24
_08012342:
	ldrb r0, [r4]
	lsls r1, r5, 25
	lsrs r1, 24
	lsrs r2, r6, 24
	movs r3, 0x2
	bl nullsub_13
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, 0xD
	ble _08012342
	adds r6, r7, 0
	cmp r6, 0x3
	ble _0801232C
	ldr r0, =gUnknown_082ED868
	movs r1, 0x1
	movs r2, 0xF
	bl nullsub_5
	b _080124AA
	.pool
_08012378:
	ldr r1, [r4]
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08012414
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08012414
	movs r6, 0
	movs r5, 0xC0
	lsls r5, 18
_0801238C:
	lsrs r4, r5, 24
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, =gUnknown_082ED84B
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, =gUnknown_082ED85B
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
	movs r1, 0x80
	lsls r1, 17
	adds r5, r1
	adds r6, 0x1
	cmp r6, 0x3
	ble _0801238C
	ldr r5, =gUnknown_03007890
	ldr r1, [r5]
	ldr r4, =gUnknown_03005000
	ldr r0, =0x00000c3e
	adds r4, r0
	ldrb r0, [r4]
	lsls r0, 5
	adds r1, r0
	ldrh r0, [r1, 0x18]
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x4
	bl nullsub_13
	ldrb r1, [r4]
	lsls r1, 5
	adds r1, 0x14
	ldr r0, [r5]
	adds r0, r1
	adds r0, 0x6
	movs r1, 0x6
	movs r2, 0x3
	bl nullsub_5
	ldrb r1, [r4]
	lsls r1, 5
	adds r1, 0x14
	ldr r0, [r5]
	adds r0, r1
	adds r0, 0x15
	movs r1, 0x16
	movs r2, 0x3
	bl nullsub_5
	b _080124AA
	.pool
_08012414:
	movs r6, 0
	ldr r1, =gUnknown_03007890
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	bge _08012470
	adds r7, r1, 0
	movs r1, 0x14
	mov r8, r1
_08012426:
	ldr r0, [r7]
	lsls r5, r6, 5
	adds r1, r0, r5
	ldrb r0, [r1, 0x16]
	cmp r0, 0xFF
	beq _08012462
	ldrh r0, [r1, 0x18]
	adds r4, r6, 0x3
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r5
	ldrh r0, [r0, 0x14]
	movs r1, 0x6
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, [r7]
	add r0, r8
	adds r0, 0x15
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
_08012462:
	movs r0, 0x20
	add r8, r0
	adds r6, 0x1
	ldr r0, [r7]
	ldrb r0, [r0, 0x8]
	cmp r6, r0
	blt _08012426
_08012470:
	cmp r6, 0x3
	bgt _080124AA
	lsls r0, r6, 24
	movs r1, 0xC0
	lsls r1, 18
	adds r5, r0, r1
_0801247C:
	lsrs r4, r5, 24
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x4
	bl nullsub_13
	ldr r0, =gUnknown_082ED84B
	movs r1, 0x6
	adds r2, r4, 0
	bl nullsub_5
	ldr r0, =gUnknown_082ED85B
	movs r1, 0x16
	adds r2, r4, 0
	bl nullsub_5
	movs r0, 0x80
	lsls r0, 17
	adds r5, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _0801247C
_080124AA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801229C

	thumb_func_start sub_80124C0
sub_80124C0: @ 80124C0
	ldr r0, =gUnknown_03005000
	ldr r1, =0x00000c1a
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80124C0

	thumb_func_start sub_80124D4
sub_80124D4: @ 80124D4
	ldr r0, =gUnknown_03005000
	ldr r1, =0x000009e6
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80124D4

	.align 2, 0 @ don't pad with nop
