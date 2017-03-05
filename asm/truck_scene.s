	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80FB0B0
sub_80FB0B0: @ 80FB0B0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x78
	bl __modsi3
	cmp r0, 0
	bne _080FB0C4
	movs r0, 0x1
	negs r0, r0
	b _080FB0D6
_080FB0C4:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	cmp r0, 0x4
	ble _080FB0D4
	movs r0, 0
	b _080FB0D6
_080FB0D4:
	movs r0, 0x1
_080FB0D6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80FB0B0

	thumb_func_start sub_80FB0DC
sub_80FB0DC: @ 80FB0DC
	push {lr}
	adds r0, 0x78
	movs r1, 0xB4
	bl __modsi3
	cmp r0, 0
	beq _080FB0EE
	movs r0, 0
	b _080FB0F2
_080FB0EE:
	movs r0, 0x1
	negs r0, r0
_080FB0F2:
	pop {r1}
	bx r1
	thumb_func_end sub_80FB0DC

	thumb_func_start sub_80FB0F8
sub_80FB0F8: @ 80FB0F8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r0, 0x1E
	bl sub_80FB0DC
	ldr r4, =gUnknown_03005D8C
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	lsls r0, 18
	movs r3, 0xC0
	lsls r3, 10
	orrs r0, r3
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x1
	movs r3, 0x3
	bl sub_808E82C
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl sub_80FB0DC
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	lsls r0, 17
	ldr r3, =0xfffd0000
	adds r0, r3
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x2
	movs r3, 0
	bl sub_808E82C
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_80FB0DC
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	movs r4, 0
	movs r3, 0x3
	negs r3, r3
	lsls r0, 18
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x3
	bl sub_808E82C
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	ldr r1, =0x75300000
	cmp r0, r1
	bne _080FB180
	strh r4, [r5]
_080FB180:
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl sub_80FB0B0
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl SetCameraPanning
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB0F8

	thumb_func_start sub_80FB1AC
sub_80FB1AC: @ 80FB1AC
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r3, r0, 3
	ldr r4, =gTasks + 0x8
	adds r7, r3, r4
	ldrh r1, [r7]
	adds r1, 0x1
	strh r1, [r7]
	ldrh r0, [r7, 0x4]
	adds r0, 0x1
	strh r0, [r7, 0x4]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x5
	ble _080FB1DC
	movs r0, 0
	strh r0, [r7]
	ldrh r0, [r7, 0x2]
	adds r0, 0x1
	strh r0, [r7, 0x2]
_080FB1DC:
	ldrh r0, [r7, 0x2]
	cmp r0, 0x13
	bne _080FB1F0
	adds r0, r2, 0
	bl DestroyTask
	b _080FB2A8
	.pool
_080FB1F0:
	ldr r2, =gUnknown_0858E898
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x2
	bne _080FB20C
	adds r0, r4, 0
	subs r0, 0x8
	adds r0, r3, r0
	ldr r1, =sub_80FB2C0
	str r1, [r0]
_080FB20C:
	movs r4, 0x2
	ldrsh r0, [r7, r4]
	adds r0, r2
	movs r5, 0
	ldrsb r5, [r0, r5]
	lsls r5, 16
	lsrs r5, 16
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl sub_80FB0B0
	adds r1, r0, 0
	lsls r5, 16
	asrs r5, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r5, 0
	bl SetCameraPanning
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	adds r0, 0x1E
	bl sub_80FB0DC
	ldr r6, =gUnknown_03005D8C
	ldr r2, [r6]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	movs r3, 0x3
	subs r3, r5
	lsls r3, 16
	asrs r3, 16
	lsls r0, 18
	movs r4, 0xC0
	lsls r4, 10
	orrs r0, r4
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x1
	bl sub_808E82C
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl sub_80FB0DC
	ldr r2, [r6]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	negs r3, r5
	lsls r3, 16
	asrs r3, 16
	lsls r0, 17
	ldr r4, =0xfffd0000
	adds r0, r4
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x2
	bl sub_808E82C
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl sub_80FB0DC
	ldr r2, [r6]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	movs r4, 0x3
	negs r4, r4
	adds r3, r4, 0
	subs r3, r5
	lsls r3, 16
	asrs r3, 16
	lsls r0, 18
	asrs r0, 16
	str r0, [sp]
	movs r0, 0x3
	bl sub_808E82C
_080FB2A8:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB1AC

	thumb_func_start sub_80FB2C0
sub_80FB2C0: @ 80FB2C0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _080FB2F0
	movs r0, 0
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	strh r0, [r2, 0x2]
_080FB2F0:
	ldrh r0, [r2, 0x2]
	cmp r0, 0x13
	bne _080FB304
	adds r0, r3, 0
	bl DestroyTask
	b _080FB358
	.pool
_080FB304:
	ldr r1, =gUnknown_0858E898
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	adds r0, r1
	movs r1, 0
	mov r8, r1
	movs r6, 0
	ldrsb r6, [r0, r6]
	adds r0, r6, 0
	bl SetCameraPanning
	ldr r5, =gUnknown_03005D8C
	ldr r0, [r5]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r3, 0x3
	subs r3, r6
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0x1
	bl sub_808E82C
	ldr r0, [r5]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	negs r3, r6
	mov r4, r8
	subs r4, 0x3
	str r4, [sp]
	movs r0, 0x2
	bl sub_808E82C
	ldr r0, [r5]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	subs r4, r6
	mov r3, r8
	str r3, [sp]
	movs r0, 0x3
	adds r3, r4, 0
	bl sub_808E82C
_080FB358:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB2C0

	thumb_func_start sub_80FB36C
sub_80FB36C: @ 80FB36C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bls _080FB386
	b _080FB4D8
_080FB386:
	lsls r0, 2
	ldr r1, =_080FB398
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080FB398:
	.4byte _080FB3B0
	.4byte _080FB3E8
	.4byte _080FB404
	.4byte _080FB450
	.4byte _080FB474
	.4byte _080FB492
_080FB3B0:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	beq _080FB3C0
	b _080FB4D8
_080FB3C0:
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r0, =sub_80FB0F8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x4]
	movs r0, 0x1
	strh r0, [r4]
	movs r0, 0x31
	bl audio_play
	b _080FB4D8
	.pool
_080FB3E8:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x96
	bne _080FB4D8
	bl pal_fill_black
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x2
	strh r0, [r4]
	b _080FB4D8
_080FB404:
	ldrh r0, [r4, 0x2]
	adds r3, r0, 0x1
	strh r3, [r4, 0x2]
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _080FB4D8
	lsls r1, r3, 16
	movs r0, 0x96
	lsls r0, 17
	cmp r1, r0
	ble _080FB4D8
	strh r2, [r4, 0x2]
	ldrb r0, [r4, 0x4]
	bl DestroyTask
	ldr r0, =sub_80FB1AC
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x6]
	movs r0, 0x3
	strh r0, [r4]
	movs r0, 0x32
	bl audio_play
	b _080FB4D8
	.pool
_080FB450:
	ldr r2, =gTasks
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r5, [r0, 0x4]
	cmp r5, 0
	bne _080FB4D8
	bl InstallCameraPanAheadCallback
	strh r5, [r4, 0x2]
	movs r0, 0x4
	strh r0, [r4]
	b _080FB4D8
	.pool
_080FB474:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	bne _080FB4D8
	movs r0, 0x33
	bl audio_play
	movs r0, 0
	strh r0, [r4, 0x2]
	movs r0, 0x5
	strh r0, [r4]
	b _080FB4D8
_080FB492:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x78
	bne _080FB4D8
	movs r2, 0x82
	lsls r2, 2
	movs r0, 0xB
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	movs r2, 0x84
	lsls r2, 2
	movs r0, 0xB
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	movs r2, 0x86
	lsls r2, 2
	movs r0, 0xB
	movs r1, 0xA
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	movs r0, 0x34
	bl audio_play
	adds r0, r5, 0
	bl DestroyTask
	bl script_env_2_disable
_080FB4D8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80FB36C

	thumb_func_start sub_80FB4E0
sub_80FB4E0: @ 80FB4E0
	push {lr}
	sub sp, 0x4
	ldr r2, =0x0000020d
	movs r0, 0xB
	movs r1, 0x8
	bl MapGridSetMetatileIdAt
	ldr r2, =0x00000215
	movs r0, 0xB
	movs r1, 0x9
	bl MapGridSetMetatileIdAt
	ldr r2, =0x0000021d
	movs r0, 0xB
	movs r1, 0xA
	bl MapGridSetMetatileIdAt
	bl DrawWholeMapView
	bl script_env_2_enable
	movs r0, 0
	str r0, [sp]
	ldr r1, =gPlttBufferFaded
	ldr r2, =0x01000100
	mov r0, sp
	bl CpuFastSet
	ldr r0, =sub_80FB36C
	movs r1, 0xA
	bl CreateTask
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB4E0

	thumb_func_start sub_80FB540
sub_80FB540: @ 80FB540
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r0, =sub_80FB36C
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _080FB58A
	ldr r4, =gUnknown_03005D8C
	ldr r0, [r4]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0x1
	movs r3, 0x3
	bl sub_808E82C
	ldr r0, [r4]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	movs r5, 0x3
	negs r5, r5
	str r5, [sp]
	movs r0, 0x2
	movs r3, 0
	bl sub_808E82C
	ldr r0, [r4]
	ldrb r1, [r0, 0x5]
	ldrb r2, [r0, 0x4]
	str r6, [sp]
	movs r0, 0x3
	adds r3, r5, 0
	bl sub_808E82C
_080FB58A:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80FB540

	.align 2, 0 @ Don't pad with nop.
