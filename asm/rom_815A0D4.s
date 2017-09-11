	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_815A0D4
sub_815A0D4: @ 815A0D4
	push {lr}
	adds r2, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r3, [r2, 0x20]
	adds r0, r3
	strh r0, [r2, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r3, [r2, 0x22]
	adds r0, r3
	strh r0, [r2, 0x22]
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0815A0FC
	ldrh r0, [r1, 0x4]
	b _0815A100
	.pool
_0815A0FC:
	ldrh r0, [r1, 0x4]
	negs r0, r0
_0815A100:
	strh r0, [r2, 0x2E]
	ldrh r0, [r1, 0x8]
	strh r0, [r2, 0x30]
	ldr r0, =sub_815A114
	str r0, [r2, 0x1C]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A0D4

	thumb_func_start sub_815A114
sub_815A114: @ 815A114
	push {lr}
	adds r3, r0, 0
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	ble _0815A154
	ldrh r1, [r3, 0x32]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r3, 0x24]
	ldrh r0, [r3, 0x2E]
	adds r1, r0
	strh r1, [r3, 0x32]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	b _0815A15A
_0815A154:
	adds r0, r3, 0
	bl move_anim_8072740
_0815A15A:
	pop {r0}
	bx r0
	thumb_func_end sub_815A114

	thumb_func_start sub_815A160
sub_815A160: @ 815A160
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r6, =gAnimationBankTarget
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 8
	movs r0, 0x80
	lsls r0, 12
	adds r4, r0
	asrs r4, 16
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 8
	movs r0, 0x80
	lsls r0, 12
	adds r1, r0
	asrs r1, 16
	adds r0, r4, 0
	movs r2, 0
	bl sub_807521C
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A160

	thumb_func_start sub_815A1B0
sub_815A1B0: @ 815A1B0
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x5A
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	movs r0, 0x7
	strh r0, [r4, 0x30]
	ldr r1, =sub_815A1F4
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r0, [r4, 0x30]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A1B0

	thumb_func_start sub_815A1F4
sub_815A1F4: @ 815A1F4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _0815A228
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815A234
	str r0, [r4, 0x1C]
_0815A228:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A1F4

	thumb_func_start sub_815A234
sub_815A234: @ 815A234
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815A234

	thumb_func_start sub_815A254
sub_815A254: @ 815A254
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
	ldrh r0, [r5, 0x20]
	subs r0, r7
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r5, 0x22]
	subs r1, r6
	lsls r1, 16
	asrs r1, 16
	bl sub_80A74F4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 23
	adds r0, r1
	lsrs r4, r0, 16
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815A2B2
	movs r1, 0x80
	lsls r1, 7
	adds r0, r4, r1
	lsls r0, 16
	lsrs r4, r0, 16
_0815A2B2:
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r5, 0
	movs r1, 0
	adds r2, r3, 0
	bl sub_80A73E0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	strh r7, [r5, 0x32]
	strh r6, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A254

	thumb_func_start sub_815A2F0
sub_815A2F0: @ 815A2F0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x4
	strh r0, [r4, 0x2E]
	ldr r0, =sub_815A31C
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A2F0

	thumb_func_start sub_815A31C
sub_815A31C: @ 815A31C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815A342
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	b _0815A346
_0815A342:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
_0815A346:
	strh r0, [r4, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0xF
	beq _0815A354
	cmp r0, 0x4
	bne _0815A35C
_0815A354:
	ldrh r0, [r4, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0x30]
_0815A35C:
	ldrh r0, [r4, 0x32]
	adds r1, r0, 0x1
	strh r1, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x46
	ble _0815A3A0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r0, 0
	strh r0, [r4, 0x32]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815A3AC
	str r0, [r4, 0x1C]
_0815A3A0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A31C

	thumb_func_start sub_815A3AC
sub_815A3AC: @ 815A3AC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x32]
	adds r1, r0, 0x1
	strh r1, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	ble _0815A3E8
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	adds r0, r3, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815A3E8
	ldr r0, =sub_815A3F0
	str r0, [r3, 0x1C]
_0815A3E8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A3AC

	thumb_func_start sub_815A3F0
sub_815A3F0: @ 815A3F0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	bhi _0815A448
	lsls r0, 2
	ldr r1, =_0815A40C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815A40C:
	.4byte _0815A428
	.4byte _0815A428
	.4byte _0815A432
	.4byte _0815A432
	.4byte _0815A440
	.4byte _0815A440
	.4byte _0815A448
_0815A428:
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x24]
	strh r1, [r4, 0x26]
	b _0815A450
_0815A432:
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x24]
	movs r0, 0
	b _0815A44E
	.pool
_0815A440:
	movs r0, 0
	strh r0, [r4, 0x24]
	movs r0, 0x1
	b _0815A44E
_0815A448:
	movs r0, 0
	strh r0, [r4, 0x24]
	ldr r0, =0x0000ffff
_0815A44E:
	strh r0, [r4, 0x26]
_0815A450:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0815A462
	strh r2, [r4, 0x34]
_0815A462:
	ldrh r0, [r4, 0x36]
	adds r1, r0, 0x1
	strh r1, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0815A48C
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	strh r2, [r4, 0x30]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r1, [r4, 0x2E]
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_815A49C
	str r0, [r4, 0x1C]
_0815A48C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A3F0

	thumb_func_start sub_815A49C
sub_815A49C: @ 815A49C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815A4CC
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
_0815A4CC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815A4E0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0815A4E0:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _0815A4FE
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
_0815A4FE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815A49C

	thumb_func_start sub_815A504
sub_815A504: @ 815A504
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_815A52C
	str r0, [r1]
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_815A504

	thumb_func_start sub_815A52C
sub_815A52C: @ 815A52C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80A6D94
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gTasks
	lsls r5, r4, 2
	adds r1, r5, r4
	lsls r1, 3
	adds r1, r7
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815A59C
	ldr r0, =gPlttBufferFaded
	lsls r2, r6, 4
	adds r1, r2, 0
	adds r1, 0xB
	lsls r1, 1
	adds r1, r0
	ldrh r3, [r1]
	mov r8, r3
	movs r3, 0xA
	mov r9, r7
	adds r7, r5, 0
	mov r12, r0
	adds r5, r2, 0
	lsls r0, r6, 5
	add r0, r12
	adds r2, r0, 0
	adds r2, 0x14
_0815A57A:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, 0x2
	subs r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bgt _0815A57A
	adds r0, r5, 0x1
	lsls r0, 1
	add r0, r12
	movs r1, 0
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, r4
	lsls r0, 3
	add r0, r9
	strh r1, [r0, 0x12]
_0815A59C:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0815A5AC
	adds r0, r4, 0
	bl DestroyTask
_0815A5AC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A52C

	thumb_func_start c3_80DE6F0
c3_80DE6F0: @ 815A5C8
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_815A5F0
	str r0, [r1]
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end c3_80DE6F0

	thumb_func_start sub_815A5F0
sub_815A5F0: @ 815A5F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl sub_80A6D94
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gTasks
	mov r0, r8
	lsls r3, r0, 2
	adds r1, r3, r0
	lsls r1, 3
	adds r1, r5
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815A692
	ldr r0, =gPlttBufferFaded
	lsls r2, r7, 4
	adds r1, r2, 0
	adds r1, 0xB
	lsls r1, 1
	adds r1, r0
	ldrh r6, [r1]
	movs r4, 0xA
	mov r10, r3
	mov r9, r0
	adds r5, r2, 0
	ldr r2, =gPlttBufferUnfaded
	mov r12, r2
	lsls r0, r7, 5
	add r0, r9
	adds r3, r0, 0
	adds r3, 0x14
_0815A644:
	ldrh r0, [r3]
	strh r0, [r1]
	subs r3, 0x2
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bgt _0815A644
	adds r0, r5, 0x1
	lsls r0, 1
	add r0, r9
	strh r6, [r0]
	adds r1, r5, 0
	adds r1, 0xB
	lsls r1, 1
	add r1, r12
	ldrh r6, [r1]
	movs r4, 0xA
	lsls r0, r7, 5
	add r0, r12
	adds r2, r0, 0
	adds r2, 0x14
_0815A66E:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, 0x2
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bgt _0815A66E
	adds r0, r5, 0x1
	lsls r0, 1
	add r0, r12
	movs r1, 0
	strh r6, [r0]
	mov r0, r10
	add r0, r8
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	strh r1, [r0, 0x12]
_0815A692:
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0815A6A2
	mov r0, r8
	bl DestroyTask
_0815A6A2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A5F0

	thumb_func_start sub_815A6C4
sub_815A6C4: @ 815A6C4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	mov r5, sp
	adds r5, 0x2
	movs r1, 0
	mov r2, sp
	adds r3, r5, 0
	bl sub_80A8924
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815A6F8
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_0815A6F8:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	mov r2, sp
	ldrh r0, [r1, 0x4]
	ldrh r2, [r2]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0x6]
	ldrh r5, [r5]
	adds r0, r5
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffce
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_815A73C
	str r0, [r4, 0x1C]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A6C4

	thumb_func_start sub_815A73C
sub_815A73C: @ 815A73C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0815A75E
	movs r1, 0
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_815A76C
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
_0815A75E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A73C

	thumb_func_start sub_815A76C
sub_815A76C: @ 815A76C
	push {lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815A798
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
_0815A798:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _0815A7AC
	adds r0, r3, 0
	bl move_anim_8072740
_0815A7AC:
	pop {r0}
	bx r0
	thumb_func_end sub_815A76C

	thumb_func_start sub_815A7B0
sub_815A7B0: @ 815A7B0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_80A6838
	ldr r5, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A7B0

	thumb_func_start sub_815A7EC
sub_815A7EC: @ 815A7EC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815A84C
	adds r0, r4, 0
	bl sub_80A6838
	ldr r5, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r0, r4, 0
	bl sub_80A6864
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815A840
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815A830
	ldrh r0, [r5, 0x4]
	b _0815A846
	.pool
_0815A830:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	negs r0, r0
	strh r0, [r4, 0x30]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	negs r0, r0
	b _0815A84A
_0815A840:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	negs r0, r0
_0815A846:
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0x6]
_0815A84A:
	strh r0, [r4, 0x32]
_0815A84C:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	movs r3, 0xFF
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x34]
	adds r1, r2
	strh r1, [r4, 0x34]
	ldrh r1, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	adds r1, r2
	strh r1, [r4, 0x36]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	strh r1, [r4, 0x24]
	ands r0, r3
	movs r1, 0x5
	bl Sin
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	lsrs r2, r1, 31
	adds r1, r2
	asrs r1, 1
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF0
	bls _0815A8A4
	adds r0, r4, 0
	bl move_anim_8072740
_0815A8A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815A7EC

	thumb_func_start sub_815A8AC
sub_815A8AC: @ 815A8AC
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815A8C2
	adds r0, r2, 0
	bl move_anim_8072740
_0815A8C2:
	pop {r0}
	bx r0
	thumb_func_end sub_815A8AC

	thumb_func_start sub_815A8C8
sub_815A8C8: @ 815A8C8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815A8EC
	ldr r1, =gBattleAnimArgs
	movs r0, 0
	b _0815A8F0
	.pool
_0815A8EC:
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
_0815A8F0:
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A8C8

	thumb_func_start sub_815A904
sub_815A904: @ 815A904
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMoveDmgMoveAnim
	ldr r0, [r0]
	cmp r0, 0
	ble _0815A920
	ldr r1, =gBattleAnimArgs
	movs r0, 0
	b _0815A924
	.pool
_0815A920:
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
_0815A924:
	strh r0, [r1, 0xE]
	adds r0, r2, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A904

	thumb_func_start sub_815A934
sub_815A934: @ 815A934
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =0x00001f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E26
	strh r1, [r4]
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x44
	bl SetGpuReg
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A6980
	ldrb r1, [r5, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r5, 0x1]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815A9A0
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A934

	thumb_func_start sub_815A9A0
sub_815A9A0: @ 815A9A0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bhi _0815AA60
	lsls r0, 2
	ldr r1, =_0815A9BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815A9BC:
	.4byte _0815A9D4
	.4byte _0815A9F2
	.4byte _0815AA12
	.4byte _0815A9F2
	.4byte _0815AA32
	.4byte _0815AA42
_0815A9D4:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815AA60
	b _0815AA3A
_0815A9F2:
	ldrh r0, [r4, 0x30]
	adds r0, 0x75
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _0815AA60
	movs r0, 0
	strh r0, [r4, 0x32]
	b _0815AA3A
_0815AA12:
	ldrh r0, [r4, 0x30]
	subs r0, 0x75
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x29
	bne _0815AA60
	movs r0, 0
	strh r0, [r4, 0x32]
	b _0815AA3A
_0815AA32:
	adds r0, r4, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
_0815AA3A:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815AA60
_0815AA42:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815AA60
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815AA6C
	str r0, [r4, 0x1C]
_0815AA60:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815A9A0

	thumb_func_start sub_815AA6C
sub_815AA6C: @ 815AA6C
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AA6C

	thumb_func_start sub_815AAA4
sub_815AAA4: @ 815AAA4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815AAD0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
_0815AAD0:
	ldrh r0, [r6]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	movs r3, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r6, 0x2]
	ldrh r4, [r5, 0x22]
	adds r0, r4
	strh r0, [r5, 0x22]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815AB2C
	ldrb r1, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r0, =0x0000fff4
	strh r0, [r5, 0x24]
	movs r0, 0x2
	b _0815AB32
	.pool
_0815AB2C:
	movs r0, 0xC
	strh r0, [r5, 0x24]
	ldr r0, =0x0000fffe
_0815AB32:
	strh r0, [r5, 0x30]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r0, 0xFF
	beq _0815AB46
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x34]
_0815AB46:
	ldr r0, =sub_815AB5C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AAA4

	thumb_func_start sub_815AB5C
sub_815AB5C: @ 815AB5C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x32]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815AB9A
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0815ABBA
	adds r0, r2, 0x1
	strh r0, [r4, 0x32]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815ABBA
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xDE
	bl PlaySE1WithPanning
	b _0815ABBA
_0815AB9A:
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x30]
	subs r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _0815ABAC
	negs r0, r0
_0815ABAC:
	cmp r0, 0xC
	bne _0815ABBA
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	subs r0, r2, 0x1
	strh r0, [r4, 0x32]
_0815ABBA:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815ABC8
	adds r0, r4, 0
	bl move_anim_8072740
_0815ABC8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815AB5C

	thumb_func_start sub_815ABD0
sub_815ABD0: @ 815ABD0
	push {lr}
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r1, 0xFF
	strh r1, [r0, 0x34]
	bl sub_815AAA4
	pop {r0}
	bx r0
	thumb_func_end sub_815ABD0

	thumb_func_start sub_815ABEC
sub_815ABEC: @ 815ABEC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815AC40
	ldr r1, =0x00001f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =gUnknown_02022E28
	ldr r2, =0x000098f0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E2A
	movs r0, 0xA0
	strh r0, [r1]
	ldr r0, =gUnknown_02022E24
	ldrh r1, [r0]
	movs r0, 0x42
	bl SetGpuReg
	ldr r0, =gUnknown_02022E26
	ldrh r1, [r0]
	movs r0, 0x46
	bl SetGpuReg
	b _0815AC70
	.pool
_0815AC40:
	ldr r1, =0x00001f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =gUnknown_02022E28
	movs r0, 0xF0
	strh r0, [r1]
	ldr r4, =gUnknown_02022E2A
	ldr r1, =0x000078a0
	adds r0, r1, 0
	strh r0, [r4]
	movs r0, 0x42
	movs r1, 0xF0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x46
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl SetGpuRegBits
_0815AC70:
	adds r0, r5, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ABEC

	thumb_func_start sub_815AC8C
sub_815AC8C: @ 815AC8C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r0, =gUnknown_02022E28
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E2A
	strh r1, [r0]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815ACB8
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
_0815ACB8:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AC8C

	thumb_func_start sub_815ACD0
sub_815ACD0: @ 815ACD0
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815ACEC
	ldr r4, =gAnimationBankAttacker
	b _0815ACEE
	.pool
_0815ACEC:
	ldr r4, =gAnimationBankTarget
_0815ACEE:
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x2]
	adds r0, r6
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2, 0x4]
	strh r0, [r5, 0x26]
	movs r3, 0
	lsls r0, 16
	asrs r0, 16
	ldrh r4, [r2, 0x6]
	movs r6, 0x6
	ldrsh r1, [r2, r6]
	cmp r0, r1
	ble _0815AD26
	movs r3, 0x1
_0815AD26:
	strh r3, [r5, 0x2E]
	movs r0, 0
	strh r0, [r5, 0x30]
	ldrh r0, [r2, 0x8]
	strh r0, [r5, 0x32]
	ldrh r0, [r2, 0xA]
	strh r0, [r5, 0x34]
	strh r4, [r5, 0x36]
	ldr r0, =sub_815AD4C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ACD0

	thumb_func_start sub_815AD4C
sub_815AD4C: @ 815AD4C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x30]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r2, 0x30]
	ldr r1, =gSineTable
	movs r3, 0x30
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x34]
	ldrh r3, [r2, 0x26]
	adds r1, r0, r3
	strh r1, [r2, 0x26]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _0815AD98
	lsls r0, r1, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bge _0815ADAA
	adds r0, r2, 0
	bl move_anim_8072740
	b _0815ADAA
	.pool
_0815AD98:
	lsls r0, r1, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r2, r3]
	cmp r0, r1
	ble _0815ADAA
	adds r0, r2, 0
	bl move_anim_8072740
_0815ADAA:
	pop {r0}
	bx r0
	thumb_func_end sub_815AD4C

	thumb_func_start sub_815ADB0
sub_815ADB0: @ 815ADB0
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815ADDC
	ldr r4, =gAnimationBankAttacker
	b _0815ADDE
	.pool
_0815ADDC:
	ldr r4, =gAnimationBankTarget
_0815ADDE:
	ldrb r0, [r4]
	bl sub_80A6190
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r0, [r4]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r6, 0
	adds r1, r0, 0
	adds r1, 0x24
	movs r2, 0
	strh r1, [r5, 0x8]
	strh r1, [r5, 0xA]
	subs r0, 0x21
	strh r0, [r5, 0xC]
	cmp r0, 0
	bge _0815AE08
	strh r2, [r5, 0xC]
_0815AE08:
	ldrh r0, [r5, 0x8]
	strh r0, [r5, 0xE]
	movs r0, 0x8
	strh r0, [r5, 0x10]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x12]
	strh r2, [r5, 0x14]
	strh r2, [r5, 0x16]
	cmp r7, 0x1
	bne _0815AE30
	ldr r0, =gUnknown_02022E18
	b _0815AE32
	.pool
_0815AE30:
	ldr r0, =gUnknown_02022E1C
_0815AE32:
	ldrh r2, [r0]
	strh r2, [r5, 0x18]
	adds r3, r2, 0
	adds r3, 0xF0
	strh r3, [r5, 0x1A]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x1C]
	movs r4, 0x4
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _0815AE54
	strh r3, [r5, 0x1E]
	ldrh r3, [r5, 0x18]
	b _0815AE58
	.pool
_0815AE54:
	strh r2, [r5, 0x1E]
	ldrh r3, [r5, 0x1A]
_0815AE58:
	movs r0, 0
	strh r0, [r5, 0x26]
	ldrh r1, [r5, 0xC]
	lsls r2, r1, 16
	asrs r1, r2, 16
	movs r6, 0xE
	ldrsh r0, [r5, r6]
	cmp r1, r0
	bgt _0815AE8E
	ldr r4, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r0, r4
	mov r12, r0
_0815AE74:
	asrs r2, 16
	lsls r1, r2, 1
	adds r0, r1, r4
	strh r3, [r0]
	add r1, r12
	strh r3, [r1]
	adds r2, 0x1
	lsls r2, 16
	asrs r1, r2, 16
	movs r6, 0xE
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _0815AE74
_0815AE8E:
	cmp r7, 0x1
	bne _0815AEA0
	ldr r0, =0x04000014
	b _0815AEA2
	.pool
_0815AEA0:
	ldr r0, =0x04000018
_0815AEA2:
	str r0, [sp]
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_815AED8
	str r0, [r5]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ADB0

	thumb_func_start sub_815AED8
sub_815AED8: @ 815AED8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0xC]
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0815AF00
	strh r2, [r4, 0x8]
_0815AF00:
	ldrh r1, [r4, 0x10]
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0815AF2C
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0xC]
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0815AF30
	strh r2, [r4, 0xA]
	movs r0, 0x1
	strh r0, [r4, 0x26]
	b _0815AF30
	.pool
_0815AF2C:
	subs r0, r1, 0x1
	strh r0, [r4, 0x10]
_0815AF30:
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815AF5C
	movs r0, 0
	strh r0, [r4, 0x14]
	movs r1, 0
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0815AF4E
	movs r1, 0x1
_0815AF4E:
	strh r1, [r4, 0x16]
	cmp r1, 0
	beq _0815AF58
	ldrh r0, [r4, 0x18]
	b _0815AF5A
_0815AF58:
	ldrh r0, [r4, 0x1A]
_0815AF5A:
	strh r0, [r4, 0x20]
_0815AF5C:
	ldrh r1, [r4, 0x8]
	lsls r3, r1, 16
	asrs r1, r3, 16
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _0815AF90
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0815AF72:
	asrs r3, 16
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0x20]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0x20]
	strh r0, [r1]
	adds r3, 0x1
	lsls r3, 16
	asrs r1, r3, 16
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _0815AF72
_0815AF90:
	ldrh r1, [r4, 0xA]
	lsls r3, r1, 16
	asrs r1, r3, 16
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _0815AFC4
	ldr r5, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0815AFA6:
	asrs r3, 16
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0x1E]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0x1E]
	strh r0, [r1]
	adds r3, 0x1
	lsls r3, 16
	asrs r1, r3, 16
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _0815AFA6
_0815AFC4:
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0815AFE0
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815AFDA
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
_0815AFDA:
	adds r0, r7, 0
	bl move_anim_task_del
_0815AFE0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AED8

	thumb_func_start sub_815AFF0
sub_815AFF0: @ 815AFF0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r5, 0
	strh r5, [r4, 0x8]
	strh r5, [r4, 0xA]
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	ldrb r0, [r6]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xE]
	movs r0, 0x20
	strh r0, [r4, 0x10]
	ldr r0, =0x0000ffec
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x14]
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_815B054
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815AFF0

	thumb_func_start sub_815B054
sub_815B054: @ 815B054
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0x5
	bls _0815B074
	b _0815B22E
_0815B074:
	lsls r0, 2
	ldr r1, =_0815B088
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815B088:
	.4byte _0815B0A0
	.4byte _0815B160
	.4byte _0815B18E
	.4byte _0815B1A2
	.4byte _0815B1B8
	.4byte _0815B220
_0815B0A0:
	movs r0, 0xC
	ldrsh r2, [r6, r0]
	ldrh r1, [r6, 0xA]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815B0B6
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	subs r0, r2, r0
	b _0815B0BC
_0815B0B6:
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	adds r0, r2, r0
_0815B0BC:
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r2, [r6, 0x12]
	ldrh r0, [r6, 0xE]
	adds r2, r0
	ldr r0, =gUnknown_08593114
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	ldrb r4, [r6, 0xA]
	movs r3, 0x6
	subs r3, r4
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xBA
	bl PlaySE12WithPanning
	cmp r4, 0x40
	beq _0815B120
	ldr r5, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r3, r1, r5
	ldrh r0, [r6, 0xA]
	movs r2, 0x1
	ands r2, r0
	adds r3, 0x3F
	ldrb r4, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r4
	orrs r0, r2
	strb r0, [r3]
	adds r5, 0x1C
	adds r1, r5
	ldr r0, =SpriteCallbackDummy
	str r0, [r1]
_0815B120:
	ldrh r1, [r6, 0xA]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0815B138
	ldrh r0, [r6, 0x10]
	subs r0, 0x6
	strh r0, [r6, 0x10]
	ldrh r0, [r6, 0x12]
	subs r0, 0x6
	strh r0, [r6, 0x12]
_0815B138:
	ldrh r1, [r6, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE2A0
	adds r0, r6, 0
	bl sub_80A7CFC
	ldrh r0, [r6, 0xA]
	adds r0, 0x1
	strh r0, [r6, 0xA]
	strh r4, [r6, 0x8]
	b _0815B22E
	.pool
_0815B160:
	adds r0, r6, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0815B22E
	movs r2, 0xA
	ldrsh r1, [r6, r2]
	cmp r1, 0x6
	bne _0815B180
	movs r0, 0x8
	strh r0, [r6, 0x14]
	movs r0, 0x3
	strh r0, [r6, 0x8]
	b _0815B22E
_0815B180:
	cmp r1, 0x2
	bgt _0815B186
	movs r0, 0xA
_0815B186:
	strh r0, [r6, 0x14]
	movs r0, 0x2
	strh r0, [r6, 0x8]
	b _0815B22E
_0815B18E:
	ldrh r0, [r6, 0x14]
	movs r2, 0x14
	ldrsh r1, [r6, r2]
	cmp r1, 0
	beq _0815B19E
	subs r0, 0x1
	strh r0, [r6, 0x14]
	b _0815B22E
_0815B19E:
	strh r1, [r6, 0x8]
	b _0815B22E
_0815B1A2:
	ldrh r1, [r6, 0x14]
	movs r2, 0x14
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _0815B1B2
	subs r0, r1, 0x1
	strh r0, [r6, 0x14]
	b _0815B22E
_0815B1B2:
	movs r0, 0x4
	strh r0, [r6, 0x8]
	b _0815B22E
_0815B1B8:
	movs r5, 0
	movs r7, 0
	ldr r3, =gSprites
	movs r0, 0x1C
	adds r0, r3
	mov r8, r0
_0815B1C4:
	lsls r0, r5, 4
	adds r0, r5
	lsls r4, r0, 2
	adds r0, r3, 0
	adds r0, 0x14
	adds r0, r4, r0
	ldr r1, [r0]
	ldr r0, =gUnknown_08593114
	cmp r1, r0
	bne _0815B200
	adds r0, r4, r3
	strh r2, [r0, 0x2E]
	movs r1, 0x6
	strh r1, [r0, 0x30]
	movs r1, 0x2
	str r2, [sp]
	str r3, [sp, 0x4]
	bl StartSpriteAnim
	mov r0, r8
	adds r1, r4, r0
	ldr r0, =sub_815B23C
	str r0, [r1]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	cmp r7, 0x6
	beq _0815B20A
_0815B200:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3F
	bls _0815B1C4
_0815B20A:
	strh r7, [r6, 0x14]
	movs r0, 0x5
	strh r0, [r6, 0x8]
	b _0815B22E
	.pool
_0815B220:
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815B22E
	adds r0, r2, 0
	bl move_anim_task_del
_0815B22E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815B054

	thumb_func_start sub_815B23C
sub_815B23C: @ 815B23C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815B270
	ldr r3, =gTasks
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x2E
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0815B270:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B23C

	thumb_func_start sub_815B27C
sub_815B27C: @ 815B27C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815B290
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A69CC
_0815B290:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	bgt _0815B2C2
	ldrh r0, [r5, 0x2E]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815B2B4
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _0815B2C0
_0815B2B4:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
_0815B2C0:
	strb r0, [r2]
_0815B2C2:
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x1E
	ble _0815B2D8
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0815B2D8:
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x3D
	bne _0815B324
	ldr r1, =move_anim_8072740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldrh r0, [r5, 0x24]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x24]
	strh r1, [r5, 0x26]
	movs r0, 0x14
	strh r0, [r5, 0x2E]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
_0815B324:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B27C

	thumb_func_start sub_815B338
sub_815B338: @ 815B338
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815B35C
	cmp r0, 0x1
	beq _0815B37C
	b _0815B38E
	.pool
_0815B35C:
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE350
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B38E
	.pool
_0815B37C:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B38E
	adds r0, r5, 0
	bl move_anim_task_del
_0815B38E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B338

	thumb_func_start sub_815B394
sub_815B394: @ 815B394
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r6, r0, 24
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0815B3F4
	cmp r0, 0x1
	bgt _0815B3B4
	cmp r0, 0
	beq _0815B3BE
	b _0815B496
_0815B3B4:
	cmp r0, 0x2
	beq _0815B424
	cmp r0, 0x3
	beq _0815B478
	b _0815B496
_0815B3BE:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	adds r0, r6, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0x30]
	strh r0, [r5, 0x32]
	b _0815B46C
	.pool
_0815B3F4:
	ldrh r0, [r5, 0x30]
	adds r0, 0x60
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	subs r0, 0x1A
	strh r0, [r5, 0x32]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	movs r0, 0x32
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815B424
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0815B424:
	ldrh r0, [r5, 0x30]
	adds r0, 0x60
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x30
	strh r0, [r5, 0x32]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	movs r0, 0x32
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815B496
	movs r0, 0
	strh r0, [r5, 0x34]
	ldr r1, =gSprites
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0
	bl sub_80A7344
_0815B46C:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0815B496
	.pool
_0815B478:
	ldrh r0, [r5, 0x26]
	subs r0, 0x6
	strh r0, [r5, 0x26]
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	movs r2, 0x26
	ldrsh r1, [r5, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _0815B496
	adds r0, r5, 0
	bl move_anim_8072740
_0815B496:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815B394

	thumb_func_start sub_815B49C
sub_815B49C: @ 815B49C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815B4BC
	ldr r0, =0x0000fff0
	b _0815B4C0
	.pool
_0815B4BC:
	movs r0, 0x80
	lsls r0, 1
_0815B4C0:
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0x22]
	ldr r0, =sub_815B4D4
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B49C

	thumb_func_start sub_815B4D4
sub_815B4D4: @ 815B4D4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x48
	strh r0, [r4, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815B4F8
	ldrh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 20
	b _0815B500
	.pool
_0815B4F8:
	ldrh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
_0815B500:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x30]
	adds r0, 0x10
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r5, r0, r1
	strh r5, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0815B54C
	ldr r0, =gUnknown_085CE3A0
	ldrh r1, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x22]
	adds r2, r5
	lsls r2, 16
	asrs r2, 16
	adds r3, r4, 0
	adds r3, 0x43
	ldrb r3, [r3]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSpriteAndAnimate
_0815B54C:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x20
	movs r1, 0x98
	lsls r1, 1
	cmp r0, r1
	bls _0815B566
	adds r0, r4, 0
	bl move_anim_8072740
_0815B566:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B4D4

	thumb_func_start sub_815B570
sub_815B570: @ 815B570
	push {r4,lr}
	adds r4, r0, 0
	bl Random2
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0815B58A
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x4
	b _0815B592
_0815B58A:
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x5
_0815B592:
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	bl Random2
	movs r1, 0x7
	ands r0, r1
	adds r1, r0, 0
	cmp r1, 0x3
	ble _0815B5B4
	negs r0, r1
	lsls r0, 24
	lsrs r0, 24
_0815B5B4:
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x26]
	ldr r0, =sub_815B5D0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B570

	thumb_func_start sub_815B5D0
sub_815B5D0: @ 815B5D0
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	bgt _0815B612
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0815B646
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r0, 0
	b _0815B644
_0815B612:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0x2
	bne _0815B628
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0815B628:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0x3
	bne _0815B640
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =0x0000ffff
	strh r0, [r3, 0x30]
_0815B640:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
_0815B644:
	strh r0, [r3, 0x30]
_0815B646:
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0x3C
	ble _0815B654
	adds r0, r3, 0
	bl DestroySprite
_0815B654:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B5D0

	thumb_func_start sub_815B65C
sub_815B65C: @ 815B65C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815B69C
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE3B8
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B6AE
	.pool
_0815B69C:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B6AE
	adds r0, r5, 0
	bl move_anim_task_del
_0815B6AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B65C

	thumb_func_start sub_815B6B4
sub_815B6B4: @ 815B6B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815B6F4
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE3E0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B706
	.pool
_0815B6F4:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B706
	adds r0, r5, 0
	bl move_anim_task_del
_0815B706:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B6B4

	thumb_func_start sub_815B70C
sub_815B70C: @ 815B70C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815B71E
	cmp r0, 0x1
	beq _0815B748
	b _0815B770
_0815B71E:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	movs r0, 0x90
	lsls r0, 4
	strh r0, [r4, 0x30]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815B770
	.pool
_0815B748:
	ldrh r2, [r4, 0x30]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	subs r2, 0x60
	strh r2, [r4, 0x30]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _0815B770
	adds r0, r4, 0
	bl move_anim_8072740
_0815B770:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815B70C

	thumb_func_start sub_815B778
sub_815B778: @ 815B778
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815B7B8
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE430
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815B7CA
	.pool
_0815B7B8:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815B7CA
	adds r0, r5, 0
	bl move_anim_task_del
_0815B7CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815B778

	thumb_func_start sub_815B7D0
sub_815B7D0: @ 815B7D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r3, r1, 0
	cmp r0, 0x4
	bls _0815B7F6
	b _0815BAFC
_0815B7F6:
	lsls r0, 2
	ldr r1, =_0815B808
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815B808:
	.4byte _0815B81C
	.4byte _0815B86C
	.4byte _0815B8A8
	.4byte _0815BA44
	.4byte _0815BA82
_0815B81C:
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815B844
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0x1
	bl lcd_bg_operations
	b _0815B84E
	.pool
_0815B844:
	movs r0, 0x2
	movs r1, 0x2
	movs r2, 0x1
	bl lcd_bg_operations
_0815B84E:
	ldr r0, =gTasks
	mov r6, r8
	lsls r1, r6, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r1, 0x1C]
	b _0815BA26
	.pool
_0815B86C:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0xC]
	adds r1, r0, 0x1
	strh r1, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _0815B886
	b _0815BAFC
_0815B886:
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	ldrh r5, [r4, 0xA]
	lsls r1, r5, 4
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	cmp r5, 0xF
	beq _0815B8A6
	b _0815BAFC
_0815B8A6:
	b _0815BA7A
_0815B8A8:
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	ldr r1, =gAnimationBankTarget
	ldrb r1, [r1]
	mov r2, r8
	lsls r4, r2, 2
	adds r2, r4, r2
	lsls r2, 3
	adds r2, r3
	ldrb r2, [r2, 0x1C]
	bl sub_805E448
	ldrb r1, [r5]
	mov r0, sp
	bl sub_80A6BFC
	bl IsContest
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	beq _0815B8E0
	movs r1, 0
	b _0815B8EA
	.pool
_0815B8E0:
	ldrb r0, [r5]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r1, r0, 24
_0815B8EA:
	ldr r0, =gBattleSpritesGfx
	ldr r2, [r0]
	lsls r0, r1, 2
	adds r2, 0x4
	adds r2, r0
	ldr r1, =gBattleMonForms
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 11
	ldr r0, [r2]
	adds r0, r1
	ldr r1, [sp]
	ldr r2, =0x04000200
	bl CpuSet
	ldr r1, [sp]
	movs r2, 0x80
	lsls r2, 4
	mov r0, sp
	ldrh r3, [r0, 0xA]
	movs r0, 0x1
	bl LoadBgTiles
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815BA1C
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	bl sub_80DB2A8
	adds r4, r0, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0, 0x2]
	bl sub_80DB2A8
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _0815B99C
	ldr r6, [sp, 0x4]
	movs r5, 0
	movs r0, 0x7
	mov r12, r0
	movs r7, 0
_0815B950:
	movs r4, 0
	adds r3, r7, r6
	mov r1, r12
	lsls r0, r1, 1
	adds r2, r0, r6
_0815B95A:
	ldrh r1, [r3]
	ldrh r0, [r2]
	strh r0, [r3]
	strh r1, [r2]
	adds r3, 0x2
	subs r2, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0815B95A
	movs r2, 0x20
	add r12, r2
	adds r7, 0x40
	adds r5, 0x1
	cmp r5, 0x7
	ble _0815B950
	movs r5, 0
	movs r0, 0x80
	lsls r0, 3
	adds r3, r0, 0
_0815B980:
	adds r2, r5, 0x1
	lsls r0, r5, 6
	adds r1, r0, r6
	movs r4, 0x7
_0815B988:
	ldrh r0, [r1]
	eors r0, r3
	strh r0, [r1]
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0815B988
	adds r5, r2, 0
	cmp r5, 0x7
	ble _0815B980
_0815B99C:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0, 0x2]
	bl sub_80DB2A8
	lsls r0, 24
	cmp r0, 0
	beq _0815B9EC
	ldr r3, =gSprites
	ldr r4, =gBankSpriteIds
	ldr r2, =gAnimationBankAttacker
	ldrb r0, [r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gUnknown_082FF6C0
	b _0815BA06
	.pool
_0815B9EC:
	ldr r3, =gSprites
	ldr r4, =gBankSpriteIds
	ldr r2, =gAnimationBankAttacker
	ldrb r0, [r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gUnknown_082FF694
_0815BA06:
	str r1, [r0]
	ldrb r0, [r2]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	bl StartSpriteAffineAnim
_0815BA1C:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
_0815BA26:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815BAFC
	.pool
_0815BA44:
	mov r1, r8
	lsls r0, r1, 2
	add r0, r8
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0xC]
	adds r1, r0, 0x1
	strh r1, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815BAFC
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	ldrh r5, [r4, 0xA]
	lsls r1, r5, 4
	orrs r1, r5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	cmp r5, 0
	bne _0815BAFC
_0815BA7A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815BAFC
_0815BA82:
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815BAAC
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl lcd_bg_operations
	b _0815BAB6
	.pool
_0815BAAC:
	movs r0, 0x2
	movs r1, 0x2
	movs r2, 0
	bl lcd_bg_operations
_0815BAB6:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815BAF6
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815BAF6
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r6, 0x1C
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bne _0815BAF6
	ldrb r0, [r4]
	ldr r1, =gUnknown_020244D0
	ldr r1, [r1]
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r2
	ldrh r1, [r1, 0x2]
	bl sub_805EE54
_0815BAF6:
	mov r0, r8
	bl move_anim_task_del
_0815BAFC:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815B7D0

	thumb_func_start c3_80DFBE4
c3_80DFBE4: @ 815BB18
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gBattleAnimArgs
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	ldr r1, =gAnimationBankAttacker
	ldrb r1, [r1]
	adds r1, r2
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	adds r1, 0x3E
	ldrb r1, [r1]
	lsls r1, 29
	lsrs r1, 31
	strh r1, [r4, 0xE]
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_80DFBE4

	thumb_func_start sub_815BB58
sub_815BB58: @ 815BB58
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	ldr r1, =gAnimationBankTarget
	ldrb r1, [r1]
	movs r2, 0x1
	bl sub_805E448
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BB58

	thumb_func_start sub_815BB84
sub_815BB84: @ 815BB84
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _0815BBA2
	b _0815BDF2
_0815BBA2:
	lsls r0, 2
	ldr r1, =_0815BBB4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815BBB4:
	.4byte _0815BBC8
	.4byte _0815BCB8
	.4byte _0815BD08
	.4byte _0815BD72
	.4byte _0815BDA6
_0815BBC8:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815BC02
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0815BC02:
	mov r0, sp
	bl sub_80A6B30
	ldr r1, =gUnknown_08C2A6EC
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815BC34
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ffc8
	b _0815BC5C
	.pool
_0815BC34:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815BC58
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ff79
	adds r0, r2, 0
	b _0815BC5E
	.pool
_0815BC58:
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000fff6
_0815BC5C:
	adds r0, r3, 0
_0815BC5E:
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1A
	movs r0, 0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2A634
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C2A6D4
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r1, 0x1C]
	ldr r0, =gUnknown_02022E1A
	ldrh r0, [r0]
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	b _0815BD8E
	.pool
_0815BCB8:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x10]
	adds r1, r0, 0x1
	strh r1, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bgt _0815BCCE
	b _0815BDF2
_0815BCCE:
	movs r0, 0
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0815BCE4
	movs r0, 0xC
	strh r0, [r4, 0xA]
_0815BCE4:
	ldrh r0, [r4, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _0815BDF2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815BDF2
_0815BD08:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bge _0815BD20
	movs r0, 0
	strh r0, [r4, 0xA]
_0815BD20:
	ldrh r0, [r4, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0815BDF2
	ldr r2, =gUnknown_02022E18
	ldr r1, =gUnknown_085CE460
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x1C]
	adds r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815BD6C
	strh r0, [r4, 0x8]
	b _0815BDF2
	.pool
_0815BD6C:
	movs r0, 0x3
	strh r0, [r4, 0x8]
	b _0815BDF2
_0815BD72:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0xE]
	adds r0, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815BDF2
	movs r0, 0
	strh r0, [r1, 0xE]
	movs r0, 0x1
_0815BD8E:
	strh r0, [r1, 0x8]
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xE4
	bl PlaySE12WithPanning
	b _0815BDF2
_0815BDA6:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815BDC8
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0815BDC8:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_task_del
_0815BDF2:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BB84

	thumb_func_start sub_815BE04
sub_815BE04: @ 815BE04
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	bl Random2
	lsls r0, 16
	movs r1, 0xFC
	lsls r1, 14
	ands r1, r0
	lsrs r5, r1, 16
	adds r1, r5, 0
	cmp r1, 0x1F
	ble _0815BE2E
	movs r0, 0x20
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
_0815BE2E:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, r5
	strh r0, [r7, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r7, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r7, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r7, 0x32]
	ldr r4, =gUnknown_085CE48C
	movs r0, 0x20
	ldrsh r1, [r7, r0]
	movs r0, 0x22
	ldrsh r2, [r7, r0]
	adds r5, r7, 0
	adds r5, 0x43
	ldrb r3, [r5]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	bl CreateSprite
	mov r9, r0
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0x20
	ldrsh r1, [r7, r0]
	movs r0, 0x22
	ldrsh r2, [r7, r0]
	ldrb r3, [r5]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	bl CreateSprite
	mov r8, r0
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	mov r0, r9
	lsls r2, r0, 4
	add r2, r9
	lsls r2, 2
	ldr r1, =gSprites
	mov r10, r1
	adds r5, r2, r1
	adds r0, r5, 0
	movs r1, 0x1
	str r2, [sp]
	bl StartSpriteAnim
	mov r0, r8
	lsls r6, r0, 4
	add r6, r8
	lsls r6, 2
	mov r1, r10
	adds r4, r6, r1
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x32]
	ldrh r0, [r1]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x32]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0x3C]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x3C]
	adds r5, 0x3E
	ldrb r0, [r5]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5]
	adds r4, 0x3E
	ldrb r0, [r4]
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x1C
	add r10, r0
	ldr r2, [sp]
	add r2, r10
	ldr r0, =sub_815C050
	str r0, [r2]
	add r6, r10
	str r0, [r6]
	mov r1, r9
	strh r1, [r7, 0x3A]
	mov r0, r8
	strh r0, [r7, 0x3C]
	ldr r0, =sub_815BF44
	str r0, [r7, 0x1C]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BE04

	thumb_func_start sub_815BF44
sub_815BF44: @ 815BF44
	push {lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x32]
	ldrh r0, [r3, 0x34]
	adds r2, r0
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r3, 0x26]
	subs r1, r0
	strh r1, [r3, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r3, 0x34]
	movs r2, 0x36
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815BF92
	lsls r0, r1, 16
	asrs r0, 16
	movs r1, 0x8
	negs r1, r1
	cmp r0, r1
	bge _0815BF92
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, 0x36]
	adds r0, 0x1
	strh r0, [r3, 0x36]
_0815BF92:
	movs r1, 0x36
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	bne _0815BFC6
	movs r2, 0x26
	ldrsh r1, [r3, r2]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0815BFC6
	ldr r2, =gSprites
	movs r0, 0x3C
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, 0x36]
	adds r0, 0x1
	strh r0, [r3, 0x36]
_0815BFC6:
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815BFE8
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815BFF4
	str r0, [r3, 0x1C]
_0815BFE8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BF44

	thumb_func_start sub_815BFF4
sub_815BFF4: @ 815BFF4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r6, r5, 0
	adds r6, 0x1C
	adds r0, r3, r6
	ldr r2, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r2, r0
	bne _0815C040
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldr r0, [r1]
	cmp r0, r2
	bne _0815C040
	adds r0, r3, r5
	bl DestroySprite
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	adds r0, r4, 0
	bl move_anim_8072740
_0815C040:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815BFF4

	thumb_func_start sub_815C050
sub_815C050: @ 815C050
	push {lr}
	adds r3, r0, 0
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0815C09C
	ldrh r2, [r3, 0x32]
	ldrh r1, [r3, 0x34]
	adds r2, r1
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r3, 0x26]
	subs r0, r1
	strh r0, [r3, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r3, 0x34]
	ldrh r0, [r3, 0x30]
	subs r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815C09C
	mov r1, r12
	ldrb r0, [r1]
	movs r1, 0x4
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
_0815C09C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C050

	thumb_func_start sub_815C0A4
sub_815C0A4: @ 815C0A4
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _0815C0C2
	b _0815C396
_0815C0C2:
	lsls r0, 2
	ldr r1, =_0815C0D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815C0D4:
	.4byte _0815C0EC
	.4byte _0815C224
	.4byte _0815C2AC
	.4byte _0815C2E2
	.4byte _0815C310
	.4byte _0815C34A
_0815C0EC:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000d03
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815C124
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
_0815C124:
	mov r0, sp
	bl sub_80A6B30
	ldr r1, =gUnknown_08C2A6EC
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815C15C
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ffc8
	adds r0, r3, 0
	b _0815C1CA
	.pool
_0815C15C:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815C1B4
	cmp r4, 0x1
	bne _0815C180
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ff65
	adds r0, r2, 0
	strh r0, [r1]
_0815C180:
	cmp r4, 0x3
	bne _0815C18C
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ff8d
	adds r0, r3, 0
	strh r0, [r1]
_0815C18C:
	cmp r4, 0
	bne _0815C196
	ldr r1, =gUnknown_02022E18
	movs r0, 0xE
	strh r0, [r1]
_0815C196:
	cmp r4, 0x2
	bne _0815C1CC
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000ffec
	b _0815C1C8
	.pool
_0815C1B4:
	cmp r4, 0x1
	bne _0815C1C0
	ldr r1, =gUnknown_02022E18
	ldr r3, =0x0000ff79
	adds r0, r3, 0
	strh r0, [r1]
_0815C1C0:
	cmp r4, 0
	bne _0815C1CC
	ldr r1, =gUnknown_02022E18
	ldr r2, =0x0000fff6
_0815C1C8:
	adds r0, r2, 0
_0815C1CA:
	strh r0, [r1]
_0815C1CC:
	ldr r1, =gUnknown_02022E1A
	movs r0, 0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2A634
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C2A6D4
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r1, 0x1C]
	ldr r0, =gUnknown_02022E1A
	ldrh r0, [r0]
	strh r0, [r1, 0x1E]
	b _0815C2A4
	.pool
_0815C224:
	ldr r1, =gTasks
	lsls r4, r6, 2
	adds r0, r4, r6
	lsls r0, 3
	adds r5, r0, r1
	movs r0, 0
	strh r0, [r5, 0xE]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815C268
	ldr r2, =gUnknown_02022E18
	ldr r1, =gUnknown_085CE4A4
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r5, [r5, 0x1C]
	adds r0, r5
	b _0815C27A
	.pool
_0815C268:
	ldr r2, =gUnknown_02022E18
	ldr r1, =gUnknown_085CE4A4
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	adds r0, r1
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldrh r0, [r5, 0x1C]
	subs r0, r1
_0815C27A:
	strh r0, [r2]
	ldr r0, =gTasks
	adds r1, r4, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815C2A4
	strh r0, [r1, 0x8]
	b _0815C396
	.pool
_0815C2A4:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815C396
_0815C2AC:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r4
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bgt _0815C2C6
	movs r0, 0x5
	strh r0, [r4, 0xA]
_0815C2C6:
	ldrh r1, [r4, 0xA]
	lsls r1, 8
	movs r0, 0x3
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bne _0815C396
	b _0815C302
_0815C2E2:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r4
	ldrh r1, [r4, 0xE]
	adds r1, 0x1
	strh r1, [r4, 0xE]
	lsls r1, 16
	asrs r1, 16
	ldr r2, =gUnknown_085CE4A8
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	adds r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _0815C396
_0815C302:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C396
	.pool
_0815C310:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r4
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	ble _0815C32A
	movs r0, 0xD
	strh r0, [r4, 0xA]
_0815C32A:
	ldrh r1, [r4, 0xA]
	lsls r1, 8
	movs r0, 0x3
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xD
	bne _0815C396
	movs r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C396
_0815C34A:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815C36C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0815C36C:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r6, 0
	bl move_anim_task_del
_0815C396:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C0A4

	thumb_func_start sub_815C3A8
sub_815C3A8: @ 815C3A8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815C3E8
	movs r0, 0
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE4B0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C3FA
	.pool
_0815C3E8:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815C3FA
	adds r0, r5, 0
	bl move_anim_task_del
_0815C3FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815C3A8

	thumb_func_start sub_815C400
sub_815C400: @ 815C400
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _0815C41E
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815C472
_0815C41E:
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	cmp r1, 0x14
	ble _0815C472
	ldrh r0, [r4, 0x30]
	adds r0, 0xA0
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	adds r0, 0x80
	strh r0, [r4, 0x32]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815C450
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	b _0815C456
	.pool
_0815C450:
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
_0815C456:
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	ble _0815C472
	adds r0, r4, 0
	bl move_anim_8072740
_0815C472:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815C400

	thumb_func_start sub_815C478
sub_815C478: @ 815C478
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldr r5, =gBattleAnimArgs
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815C4A4
	adds r0, r2, 0
	bl move_anim_task_del
	b _0815C538
	.pool
_0815C4A4:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _0815C4B0
	movs r0, 0
	strh r0, [r5, 0x4]
_0815C4B0:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0x2
	ble _0815C4BC
	movs r0, 0x2
	strh r0, [r5, 0x4]
_0815C4BC:
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	lsls r1, 1
	movs r0, 0x8
	subs r0, r1
	strh r0, [r4, 0xE]
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	lsls r0, 7
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r4, 0x10]
	ldrh r0, [r5, 0x4]
	adds r0, 0x2
	strh r0, [r4, 0x12]
	ldrh r0, [r5, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x14]
	ldrb r0, [r5]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815C508
	ldr r0, =gAnimationBankAttacker
	b _0815C50A
	.pool
_0815C508:
	ldr r0, =gAnimationBankTarget
_0815C50A:
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815C528
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x10]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x12]
_0815C528:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_815C548
	str r0, [r4]
_0815C538:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C478

	thumb_func_start sub_815C548
sub_815C548: @ 815C548
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r6, [r4, r0]
	cmp r6, 0x1
	beq _0815C5D0
	cmp r6, 0x1
	bgt _0815C570
	cmp r6, 0
	beq _0815C57C
	b _0815C6A8
	.pool
_0815C570:
	cmp r6, 0x2
	beq _0815C628
	cmp r6, 0x3
	bne _0815C57A
	b _0815C698
_0815C57A:
	b _0815C6A8
_0815C57C:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x12]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	strh r1, [r0, 0x24]
	ldrh r0, [r4, 0xC]
	ldrh r1, [r4, 0x10]
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0815C6A8
	strh r6, [r4, 0xA]
	b _0815C690
	.pool
_0815C5D0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x24]
	ldrh r2, [r4, 0x12]
	subs r1, r2
	strh r1, [r0, 0x24]
	ldrh r0, [r4, 0x10]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	lsls r1, 16
	asrs r1, 16
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 1
	cmp r1, r0
	blt _0815C6A8
	movs r0, 0
	strh r0, [r4, 0xA]
	b _0815C690
	.pool
_0815C628:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x12]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	movs r5, 0
	strh r1, [r0, 0x24]
	ldrh r0, [r4, 0xC]
	ldrh r1, [r4, 0x10]
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r4, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0815C6A8
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0815C690
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	strh r5, [r4, 0xA]
	strh r5, [r4, 0x8]
	b _0815C6A8
	.pool
_0815C690:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815C6A8
_0815C698:
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	adds r0, r5, 0
	bl move_anim_task_del
_0815C6A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815C548

	thumb_func_start sub_815C6B0
sub_815C6B0: @ 815C6B0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0815C6D4
	strh r0, [r4, 0x20]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	b _0815C6DE
	.pool
_0815C6D4:
	movs r0, 0xF0
	strh r0, [r4, 0x20]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	subs r0, 0x1E
_0815C6DE:
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x32]
	ldrb r1, [r1, 0x2]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_815C700
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C6B0

	thumb_func_start sub_815C700
sub_815C700: @ 815C700
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x3
	strh r0, [r4, 0x2E]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815C744
	ldrh r1, [r4, 0x20]
	adds r1, 0x5
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	subs r0, 0x1
	strh r0, [r4, 0x22]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0xF0
	ble _0815C732
	adds r0, r4, 0
	bl move_anim_8072740
_0815C732:
	ldrh r1, [r4, 0x2E]
	movs r0, 0xFF
	ands r0, r1
	movs r1, 0x10
	bl Sin
	b _0815C768
	.pool
_0815C744:
	ldrh r1, [r4, 0x20]
	subs r1, 0x5
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	lsls r1, 16
	cmp r1, 0
	bge _0815C75C
	adds r0, r4, 0
	bl move_anim_8072740
_0815C75C:
	ldrh r1, [r4, 0x2E]
	movs r0, 0xFF
	ands r0, r1
	movs r1, 0x10
	bl Cos
_0815C768:
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815C700

	thumb_func_start sub_815C770
sub_815C770: @ 815C770
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	movs r0, 0x20
	strh r0, [r4, 0x20]
	movs r0, 0x40
	strh r0, [r4, 0x22]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r4, 0x24]
	ldr r0, =gBattleAnimArgs
	ldrb r0, [r0]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	movs r1, 0
	bl sub_80A7270
	ldr r0, =sub_815C7C4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815C770

	thumb_func_start sub_815C7C4
sub_815C7C4: @ 815C7C4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	mov r8, r0
	cmp r0, 0x1
	beq _0815C860
	cmp r0, 0x1
	bgt _0815C7F4
	cmp r0, 0
	beq _0815C7FC
	b _0815C8DA
	.pool
_0815C7F4:
	mov r2, r8
	cmp r2, 0x2
	beq _0815C8C8
	b _0815C8DA
_0815C7FC:
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	ldrh r1, [r7, 0xC]
	adds r2, r0, r1
	strh r2, [r7, 0xC]
	lsls r0, r2, 16
	asrs r0, 16
	ldrh r3, [r7, 0x24]
	mov r8, r3
	movs r3, 0x24
	ldrsh r1, [r7, r3]
	cmp r0, r1
	blt _0815C8DA
	mov r0, r8
	subs r5, r0, r2
	lsls r5, 16
	asrs r5, 16
	adds r6, r1, 0
	lsls r6, 1
	adds r0, r5, 0
	adds r1, r6, 0
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	asrs r4, 16
	movs r1, 0x1
	ands r4, r1
	cmp r4, 0
	bne _0815C854
	lsls r0, 16
	asrs r0, 16
	mov r2, r8
	subs r0, r2, r0
	b _0815C8B2
_0815C854:
	lsls r0, 16
	asrs r0, 16
	mov r3, r8
	subs r0, r3
	strh r0, [r7, 0xC]
	b _0815C8DA
_0815C860:
	ldr r1, =0xfffffe00
	adds r0, r1, 0
	ldrh r2, [r7, 0xC]
	adds r1, r0, r2
	strh r1, [r7, 0xC]
	movs r3, 0xC
	ldrsh r0, [r7, r3]
	movs r2, 0x24
	ldrsh r6, [r7, r2]
	cmn r0, r6
	bgt _0815C8DA
	ldrh r3, [r7, 0x24]
	mov r9, r3
	mov r0, r9
	subs r4, r0, r1
	lsls r4, 16
	asrs r4, 16
	lsls r6, 1
	adds r0, r4, 0
	adds r1, r6, 0
	bl __divsi3
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 16
	lsrs r2, r0, 16
	mov r1, r8
	ands r1, r5
	lsls r0, r1, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _0815C8BC
	lsls r0, r2, 16
	asrs r0, 16
	mov r2, r9
	subs r0, r2
_0815C8B2:
	strh r0, [r7, 0xC]
	strh r1, [r7, 0x8]
	b _0815C8DA
	.pool
_0815C8BC:
	lsls r0, r2, 16
	asrs r0, 16
	mov r3, r9
	subs r0, r3, r0
	strh r0, [r7, 0xC]
	b _0815C8DA
_0815C8C8:
	ldrh r0, [r7, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A7344
	adds r0, r4, 0
	bl move_anim_task_del
	b _0815C950
_0815C8DA:
	ldrh r0, [r7, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	ldrh r3, [r7, 0xC]
	adds r1, r2, 0
	bl obj_id_set_rotscale
	ldrh r0, [r7, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A73A0
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	movs r2, 0xC
	ldrsh r0, [r7, r2]
	cmp r0, 0
	bge _0815C90E
	adds r0, 0x3F
_0815C90E:
	asrs r0, 6
	negs r0, r0
	strh r0, [r1, 0x24]
	ldrh r0, [r7, 0xA]
	adds r0, 0x1
	strh r0, [r7, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0815C950
	ldrh r1, [r7, 0x20]
	movs r3, 0x20
	ldrsh r0, [r7, r3]
	cmp r0, 0
	beq _0815C94C
	subs r0, r1, 0x1
	strh r0, [r7, 0x20]
	ldrh r0, [r7, 0x24]
	ldrh r1, [r7, 0x22]
	subs r0, r1
	strh r0, [r7, 0x24]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _0815C950
	movs r0, 0x10
	strh r0, [r7, 0x24]
	b _0815C950
	.pool
_0815C94C:
	movs r0, 0x2
	strh r0, [r7, 0x8]
_0815C950:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815C7C4

	thumb_func_start sub_815C95C
sub_815C95C: @ 815C95C
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815C9BC
	ldr r6, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0815C990
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
_0815C990:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrh r1, [r6, 0x2]
	ldrh r2, [r5, 0x22]
	adds r0, r1, r2
	strh r0, [r5, 0x22]
	movs r0, 0x80
	strh r0, [r5, 0x30]
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r5, 0x32]
	strh r1, [r5, 0x34]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0815CA1A
	.pool
_0815C9BC:
	ldrh r1, [r5, 0x30]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r5, 0x26]
	adds r0, r2
	strh r0, [r5, 0x26]
	movs r2, 0x36
	ldrsh r0, [r5, r2]
	adds r4, r1, 0
	cmp r0, 0
	bne _0815C9FA
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmn r1, r0
	ble _0815C9FA
	movs r0, 0x1
	strh r0, [r5, 0x36]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	negs r0, r0
	movs r1, 0x3
	bl __divsi3
	lsls r0, 1
	strh r0, [r5, 0x32]
_0815C9FA:
	adds r0, r4, 0
	adds r0, 0xC0
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x80
	strh r0, [r5, 0x32]
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0815CA1A
	adds r0, r5, 0
	bl move_anim_8072740
_0815CA1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815C95C

	thumb_func_start sub_815CA20
sub_815CA20: @ 815CA20
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r2, r0, r1
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _0815CB2C
	ldr r0, =gBattleAnimArgs
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r1, 0
	bne _0815CA5C
	ldr r0, =gAnimationBankAttacker
	b _0815CA5E
	.pool
_0815CA5C:
	ldr r0, =gAnimationBankTarget
_0815CA5E:
	ldrb r0, [r0]
	strh r0, [r2, 0x1E]
	mov r1, r8
	ldrb r0, [r1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r4, r7, 2
	adds r0, r4, r7
	lsls r0, 3
	adds r6, r0, r1
	strh r5, [r6, 0x1C]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A7270
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x1
	beq _0815CAC0
	cmp r0, 0x1
	bgt _0815CAA0
	cmp r0, 0
	beq _0815CAA8
	lsls r2, r5, 4
	b _0815CB08
	.pool
_0815CAA0:
	cmp r0, 0x2
	beq _0815CACA
	lsls r2, r5, 4
	b _0815CB08
_0815CAA8:
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r5, 0
	movs r1, 0xE0
	movs r3, 0
	bl obj_id_set_rotscale
	adds r0, r5, 0
	bl sub_80A7E6C
	lsls r2, r5, 4
	b _0815CB08
_0815CAC0:
	movs r2, 0x98
	lsls r2, 1
	movs r3, 0xF0
	lsls r3, 4
	b _0815CAD2
_0815CACA:
	movs r2, 0x98
	lsls r2, 1
	movs r3, 0xF1
	lsls r3, 8
_0815CAD2:
	adds r0, r5, 0
	movs r1, 0xD0
	bl obj_id_set_rotscale
	adds r0, r5, 0
	bl sub_80A7E6C
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815CAF8
	ldrb r0, [r6, 0x1E]
	bl GetBankSide
	lsls r0, 24
	lsls r2, r5, 4
	cmp r0, 0
	bne _0815CB08
_0815CAF8:
	ldr r0, =gSprites
	lsls r2, r5, 4
	adds r1, r2, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x10
	strh r0, [r1, 0x26]
_0815CB08:
	ldr r1, =gSprites
	adds r0, r2, r5
	lsls r0, 2
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0, 0x24]
	ldr r0, =gTasks
	adds r1, r4, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815CB78
	.pool
_0815CB2C:
	ldrb r5, [r2, 0x1C]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	movs r4, 0
	strh r0, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0815CB50
	strh r4, [r2, 0xC]
	ldr r0, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x24]
	negs r0, r0
	strh r0, [r1, 0x24]
_0815CB50:
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _0815CB78
	adds r0, r5, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	strh r4, [r0, 0x24]
	strh r4, [r0, 0x26]
	adds r0, r7, 0
	bl move_anim_task_del
_0815CB78:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CA20

	thumb_func_start sub_815CB88
sub_815CB88: @ 815CB88
	push {r4,r5,lr}
	adds r4, r0, 0
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xC
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	bl Random2
	ldr r5, =0x000001ff
	ands r5, r0
	bl Random2
	movs r1, 0xFF
	ands r1, r0
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0815CBE0
	movs r2, 0xBC
	lsls r2, 3
	adds r0, r5, r2
	b _0815CBE8
	.pool
_0815CBE0:
	movs r3, 0xBC
	lsls r3, 3
	adds r0, r3, 0
	subs r0, r5
_0815CBE8:
	strh r0, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815CBFA
	movs r2, 0x90
	lsls r2, 3
	adds r0, r1, r2
	b _0815CC02
_0815CBFA:
	movs r3, 0x90
	lsls r3, 3
	adds r0, r3, 0
	subs r0, r1
_0815CC02:
	strh r0, [r4, 0x30]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne _0815CC1C
	ldr r0, =0x0000fff8
	b _0815CC1E
	.pool
_0815CC1C:
	movs r0, 0xF8
_0815CC1E:
	strh r0, [r4, 0x20]
	movs r0, 0x68
	strh r0, [r4, 0x22]
	ldr r0, =sub_815CC34
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CB88

	thumb_func_start sub_815CC34
sub_815CC34: @ 815CC34
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815CC4C
	ldrh r3, [r4, 0x2E]
	lsls r0, r3, 16
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	b _0815CC56
_0815CC4C:
	ldrh r3, [r4, 0x2E]
	lsls r1, r3, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
_0815CC56:
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x30]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	adds r0, r3, 0
	subs r0, 0x16
	strh r0, [r4, 0x2E]
	adds r1, r2, 0
	subs r1, 0x30
	strh r1, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _0815CC7A
	movs r0, 0
	strh r0, [r4, 0x2E]
_0815CC7A:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _0815CC8E
	adds r0, r4, 0
	bl move_anim_8072740
_0815CC8E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815CC34

	thumb_func_start sub_815CC94
sub_815CC94: @ 815CC94
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, =0x00001f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gUnknown_02022E26
	strh r1, [r4]
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A6980
	ldrb r1, [r5, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r5, 0x1]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_815CD0C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CC94

	thumb_func_start sub_815CD0C
sub_815CD0C: @ 815CD0C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0815CD4A
	cmp r0, 0x1
	bgt _0815CD22
	cmp r0, 0
	beq _0815CD2C
	b _0815CDAA
_0815CD22:
	cmp r0, 0x2
	beq _0815CD60
	cmp r0, 0x3
	beq _0815CD82
	b _0815CDAA
_0815CD2C:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815CDAA
	b _0815CD7A
_0815CD4A:
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _0815CDAA
	adds r0, r4, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
	b _0815CD7A
_0815CD60:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0815CDAA
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0815CD7A:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	b _0815CDAA
_0815CD82:
	ldr r1, =0x00003f3f
	movs r0, 0x4A
	bl SetGpuReg
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl move_anim_8072740
_0815CDAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CD0C

	thumb_func_start sub_815CDB4
sub_815CDB4: @ 815CDB4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x30]
	ldr r1, =sub_815CDFC
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CDB4

	thumb_func_start sub_815CDFC
sub_815CDFC: @ 815CDFC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	bl Sin
	strh r0, [r4, 0x24]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	ldrh r1, [r4, 0x34]
	lsls r1, 16
	asrs r1, 24
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x9
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	lsls r1, r0, 16
	cmp r0, 0x3F
	bls _0815CE36
	asrs r0, r1, 16
	cmp r0, 0xC3
	ble _0815CE48
_0815CE36:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	subs r0, 0x1
	b _0815CE52
	.pool
_0815CE48:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	adds r0, 0x1
_0815CE52:
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	movs r3, 0x38
	ldrsh r2, [r4, r3]
	cmp r2, 0
	bne _0815CE98
	movs r1, 0x80
	lsls r1, 3
	adds r0, r1, 0
	ldrh r3, [r4, 0x32]
	adds r0, r3
	strh r0, [r4, 0x32]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ldrh r3, [r4, 0x34]
	adds r0, r3
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _0815CEC8
	strh r2, [r4, 0x36]
	movs r0, 0x1
	strh r0, [r4, 0x38]
	b _0815CEC8
	.pool
_0815CE98:
	cmp r2, 0x1
	bne _0815CEC8
	ldr r1, =0xfffffc00
	adds r0, r1, 0
	ldrh r2, [r4, 0x32]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldr r3, =0xffffff00
	adds r0, r3, 0
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x36]
	adds r0, 0x1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _0815CEC8
	adds r0, r4, 0
	bl move_anim_8072740
_0815CEC8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CDFC

	thumb_func_start sub_815CED8
sub_815CED8: @ 815CED8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	movs r0, 0
	bl GetAnimBankSpriteId
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815CF18
	movs r0, 0x1
	str r0, [sp, 0x1C]
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldr r1, [r0, 0x10]
	mov r9, r1
	ldr r2, [r0, 0xC]
	mov r8, r2
	ldrh r6, [r0, 0x2]
	movs r3, 0x14
	b _0815D058
	.pool
_0815CF18:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815CFC4
	movs r0, 0
	str r0, [sp, 0x1C]
	ldr r6, =gBattlePartyID
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r7, =gPlayerParty
	adds r0, r7
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
	movs r1, 0x1
	bl GetMonData
	mov r8, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815CFBC
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815CF9C
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
	b _0815CFAA
	.pool
_0815CF9C:
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
_0815CFAA:
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815CFBE
	.pool
_0815CFBC:
	ldrh r6, [r1, 0x2]
_0815CFBE:
	movs r1, 0x14
	mov r10, r1
	b _0815D05A
_0815CFC4:
	movs r2, 0x1
	str r2, [sp, 0x1C]
	ldr r6, =gBattlePartyID
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r7, =gEnemyParty
	adds r0, r7
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
	movs r1, 0x1
	bl GetMonData
	mov r8, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815D054
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815D03C
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	b _0815D048
	.pool
_0815D03C:
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r7
_0815D048:
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815D056
_0815D054:
	ldrh r6, [r1, 0x2]
_0815D056:
	ldr r3, =0x0000ffec
_0815D058:
	mov r10, r3
_0815D05A:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A8328
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	mov r2, r10
	lsls r1, r2, 16
	asrs r1, 16
	adds r4, r1
	lsls r4, 16
	asrs r4, 16
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	str r0, [sp, 0x10]
	movs r0, 0x1
	str r0, [sp, 0x14]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0
	adds r3, r4, 0
	bl sub_80A8394
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gSprites
	lsls r5, r6, 4
	adds r5, r6
	lsls r5, 2
	adds r5, r0
	movs r0, 0x3
	ands r7, r0
	lsls r7, 2
	mov r8, r7
	ldrb r0, [r5, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r1, r4, 0
	ands r1, r0
	mov r2, r8
	orrs r1, r2
	strb r1, [r5, 0x5]
	ldrb r2, [r5, 0x1]
	adds r0, r4, 0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r5, 0x1]
	ldr r0, =0x00007fff
	lsrs r1, 4
	lsls r1, 4
	movs r3, 0x80
	lsls r3, 1
	adds r2, r3, 0
	orrs r1, r2
	movs r2, 0x20
	bl FillPalette
	ldrb r0, [r5, 0x5]
	ands r4, r0
	mov r0, r8
	orrs r4, r0
	strb r4, [r5, 0x5]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gTasks
	ldr r1, [sp, 0x18]
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0xA]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	strh r6, [r4, 0x8]
	ldr r0, =sub_815D160
	str r0, [r4]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815CED8

	thumb_func_start sub_815D160
sub_815D160: @ 815D160
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815D1AE
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0xA]
	adds r1, 0x1
	strh r1, [r4, 0xA]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xA
	bne _0815D1AE
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x1C]
	strh r0, [r4, 0x1E]
	ldr r0, =sub_815D1BC
	str r0, [r4]
_0815D1AE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D160

	thumb_func_start sub_815D1BC
sub_815D1BC: @ 815D1BC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrb r2, [r5, 0x8]
	ldrh r0, [r5, 0x1C]
	subs r0, 0x10
	movs r4, 0
	strh r0, [r5, 0x1C]
	ldrh r0, [r5, 0x1E]
	adds r0, 0x80
	strh r0, [r5, 0x1E]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r6, r0, r1
	ldrb r2, [r6, 0x1]
	lsls r1, r2, 30
	lsrs r1, 30
	movs r0, 0x2
	orrs r1, r0
	subs r0, 0x6
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x1]
	movs r0, 0x1C
	ldrsh r2, [r5, r0]
	movs r0, 0x1E
	ldrsh r3, [r5, r0]
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80A73E0
	ldrh r0, [r5, 0x20]
	adds r0, 0x1
	strh r0, [r5, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815D22A
	adds r0, r6, 0
	bl sub_80A749C
	adds r0, r6, 0
	bl sub_80A8610
	ldr r0, =sub_80A6814
	str r0, [r5]
_0815D22A:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D1BC

	thumb_func_start sub_815D240
sub_815D240: @ 815D240
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815D26C
	ldr r0, =gAnimationBankAttacker
	b _0815D26E
	.pool
_0815D26C:
	ldr r0, =gAnimationBankTarget
_0815D26E:
	ldrb r5, [r0]
	movs r6, 0
	strh r6, [r4, 0x8]
	strh r6, [r4, 0xA]
	strh r6, [r4, 0xC]
	movs r0, 0x10
	strh r0, [r4, 0xE]
	strh r6, [r4, 0x10]
	strh r5, [r4, 0x12]
	movs r0, 0x20
	strh r0, [r4, 0x14]
	strh r6, [r4, 0x16]
	movs r0, 0x18
	strh r0, [r4, 0x18]
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815D2A0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	negs r0, r0
	strh r0, [r4, 0x18]
_0815D2A0:
	adds r0, r5, 0
	bl sub_80A6190
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x22
	strh r0, [r4, 0x22]
	cmp r0, 0
	bge _0815D2B4
	strh r6, [r4, 0x22]
_0815D2B4:
	ldrh r0, [r4, 0x22]
	adds r0, 0x42
	strh r0, [r4, 0x24]
	ldr r0, =gBattleAnimArgs
	ldrb r0, [r0]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	adds r0, r5, 0
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815D304
	ldr r0, =0x04000014
	str r0, [sp]
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gUnknown_02022E18
	ldrh r5, [r0]
	ldr r0, =gUnknown_02022E1A
	b _0815D316
	.pool
_0815D304:
	ldr r0, =0x04000018
	str r0, [sp]
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	ldr r0, =gUnknown_02022E1C
	ldrh r5, [r0]
	ldr r0, =gUnknown_02022E1E
_0815D316:
	ldrh r3, [r0]
	movs r7, 0
	movs r2, 0
	ldr r6, =gUnknown_02038C28
	movs r0, 0xF0
	lsls r0, 3
	adds r0, r6
	mov r12, r0
_0815D326:
	lsls r2, 16
	asrs r2, 16
	lsls r1, r2, 1
	adds r0, r1, r6
	strh r5, [r0]
	add r1, r12
	strh r5, [r1]
	adds r0, r2, 0x1
	lsls r0, 1
	adds r1, r0, r6
	strh r3, [r1]
	add r0, r12
	strh r3, [r0]
	lsls r0, r7, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	adds r2, 0x2
	lsls r2, 16
	lsrs r2, 16
	lsrs r7, r0, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _0815D326
	ldr r0, =0xa6600001
	str r0, [sp, 0x4]
	mov r1, sp
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	mov r0, sp
	strb r2, [r0, 0x9]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl sub_80BA038
	ldr r0, =sub_815D398
	str r0, [r4]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D240

	thumb_func_start sub_815D398
sub_815D398: @ 815D398
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r6, r0, r1
	ldrb r0, [r6, 0x12]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815D3D8
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_02022E1A
	b _0815D3E0
	.pool
_0815D3D8:
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_02022E1E
_0815D3E0:
	ldrh r0, [r0]
	str r0, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bne _0815D3EE
	b _0815D5CC
_0815D3EE:
	cmp r0, 0x1
	bgt _0815D400
	cmp r0, 0
	beq _0815D40E
	b _0815D63C
	.pool
_0815D400:
	cmp r0, 0x2
	bne _0815D406
	b _0815D5EC
_0815D406:
	cmp r0, 0x3
	bne _0815D40C
	b _0815D636
_0815D40C:
	b _0815D63C
_0815D40E:
	movs r2, 0x24
	ldrsh r0, [r6, r2]
	lsls r0, 17
	lsrs r5, r0, 16
	movs r3, 0
	str r3, [sp]
	mov r9, r3
	movs r4, 0
	ldrh r0, [r6, 0xA]
	adds r0, 0x2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r6, 0xA]
	ldrh r7, [r6, 0xA]
	mov r8, r7
	movs r0, 0x14
	ldrsh r1, [r6, r0]
	movs r0, 0xFC
	lsls r0, 3
	bl __divsi3
	strh r0, [r6, 0x1A]
	movs r1, 0x16
	ldrsh r0, [r6, r1]
	lsls r0, 1
	movs r2, 0x1A
	ldrsh r1, [r6, r2]
	bl __divsi3
	negs r0, r0
	strh r0, [r6, 0x1C]
	ldrh r0, [r6, 0x16]
	strh r0, [r6, 0x1E]
	lsls r0, 16
	asrs r0, 21
	lsls r0, 16
	lsrs r7, r0, 16
	strh r7, [r6, 0x20]
	ldrh r2, [r6, 0x24]
	lsls r3, r2, 16
	mov r12, r3
	asrs r1, r3, 16
	movs r3, 0x22
	ldrsh r0, [r6, r3]
	cmp r1, r0
	ble _0815D52E
	ldr r0, =gUnknown_02039B28
	mov r10, r0
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	asrs r0, 16
	str r0, [sp, 0x10]
	ldr r2, [sp, 0x8]
	lsls r0, r2, 16
	asrs r0, 16
	str r0, [sp, 0xC]
_0815D47E:
	lsls r5, 16
	asrs r5, 16
	adds r2, r5, 0x1
	lsls r2, 1
	mov r3, r10
	ldrb r1, [r3, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	ldr r0, =gUnknown_02038C28
	adds r2, r0
	lsls r4, 16
	asrs r4, 16
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	subs r0, r4, r0
	ldr r3, [sp, 0xC]
	adds r0, r3, r0
	strh r0, [r2]
	lsls r3, r5, 1
	mov r0, r10
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r3, r0
	ldr r1, =gUnknown_02038C28
	adds r3, r1
	lsls r1, r7, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	adds r1, r2, r1
	mov r7, r8
	lsls r2, r7, 16
	asrs r2, 16
	lsls r0, r2, 1
	ldr r7, =gSineTable
	adds r0, r7
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
	adds r1, r0
	strh r1, [r3]
	adds r2, 0xA
	mov r8, r2
	movs r0, 0xFF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrh r0, [r6, 0x1C]
	ldrh r2, [r6, 0x1E]
	adds r0, r2
	strh r0, [r6, 0x1E]
	lsls r0, 16
	asrs r0, 21
	lsls r0, 16
	lsrs r7, r0, 16
	strh r7, [r6, 0x20]
	adds r4, 0x1
	lsls r4, 16
	lsrs r4, 16
	subs r5, 0x2
	lsls r5, 16
	lsrs r5, 16
	ldr r3, [sp]
	lsls r0, r3, 16
	asrs r0, 16
	ldrh r1, [r6, 0x14]
	adds r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	str r2, [sp]
	asrs r0, 21
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r0, =0xffff0000
	add r0, r12
	lsrs r2, r0, 16
	lsls r3, r2, 16
	mov r12, r3
	asrs r1, r3, 16
	movs r3, 0x22
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bgt _0815D47E
_0815D52E:
	lsls r1, r2, 17
	cmp r1, 0
	blt _0815D55A
	ldr r4, =gUnknown_02038C28
	ldr r7, [sp, 0x4]
	lsls r0, r7, 16
	asrs r0, 16
	adds r3, r0, 0
	adds r3, 0xF0
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r4, r0
_0815D546:
	asrs r2, r1, 16
	lsls r1, r2, 1
	adds r0, r1, r4
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	subs r2, 0x2
	lsls r1, r2, 16
	cmp r1, 0
	bge _0815D546
_0815D55A:
	ldrh r0, [r6, 0x14]
	adds r0, 0x1
	strh r0, [r6, 0x14]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0815D5C2
	movs r0, 0x40
	strh r0, [r6, 0x14]
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815D594
	ldrh r0, [r6, 0xE]
	subs r0, 0x1
	strh r0, [r6, 0xE]
	b _0815D59A
	.pool
_0815D594:
	ldrh r0, [r6, 0x10]
	adds r0, 0x1
	strh r0, [r6, 0x10]
_0815D59A:
	ldrh r1, [r6, 0x10]
	lsls r1, 8
	ldrh r0, [r6, 0xE]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	cmp r1, 0
	bne _0815D63C
	movs r3, 0x10
	ldrsh r0, [r6, r3]
	cmp r0, 0x10
	bne _0815D63C
	strh r1, [r6, 0xC]
	strh r1, [r6, 0xE]
	b _0815D62E
_0815D5C2:
	ldrh r0, [r6, 0x18]
	ldrh r7, [r6, 0x16]
	adds r0, r7
	strh r0, [r6, 0x16]
	b _0815D63C
_0815D5CC:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	ble _0815D63C
	ldr r1, =gUnknown_02039B28
	movs r0, 0x3
	strb r0, [r1, 0x15]
	movs r0, 0
	strh r0, [r6, 0xC]
	b _0815D62E
	.pool
_0815D5EC:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815D602
	ldrh r0, [r6, 0xE]
	adds r0, 0x1
	strh r0, [r6, 0xE]
	b _0815D608
_0815D602:
	ldrh r0, [r6, 0x10]
	subs r0, 0x1
	strh r0, [r6, 0x10]
_0815D608:
	ldrh r1, [r6, 0x10]
	lsls r1, 8
	ldrh r0, [r6, 0xE]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0x10
	bne _0815D63C
	movs r2, 0x10
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0815D63C
	strh r0, [r6, 0xC]
	strh r0, [r6, 0xE]
_0815D62E:
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _0815D63C
_0815D636:
	adds r0, r4, 0
	bl move_anim_task_del
_0815D63C:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815D398

	thumb_func_start sub_815D64C
sub_815D64C: @ 815D64C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =gBattleAnimArgs
	ldrb r0, [r0]
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE5F0
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_815D694
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D64C

	thumb_func_start sub_815D694
sub_815D694: @ 815D694
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r2, =gTasks
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	adds r1, r0, 0x1
	movs r5, 0
	strh r1, [r3, 0x8]
	subs r0, 0x14
	lsls r0, 16
	lsrs r0, 16
	adds r6, r2, 0
	cmp r0, 0x16
	bhi _0815D6F8
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815D708
	strh r5, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _0815D6F8
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	b _0815D708
	.pool
_0815D6F8:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
_0815D708:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _0815D720
	adds r0, r4, 0
	bl move_anim_task_del
_0815D720:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D694

	thumb_func_start sub_815D72C
sub_815D72C: @ 815D72C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r5, r2, 0
	adds r0, r3, 0
	ldr r4, [sp, 0x14]
	ldr r6, [sp, 0x18]
	lsls r1, 16
	lsrs r1, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r6, 16
	lsrs r6, 16
	mov r2, r8
	strh r1, [r2, 0x20]
	strh r5, [r2, 0x22]
	lsls r1, 16
	asrs r1, 16
	lsls r2, r1, 4
	mov r3, r8
	strh r2, [r3, 0x36]
	lsls r5, 16
	asrs r5, 16
	lsls r2, r5, 4
	strh r2, [r3, 0x38]
	lsls r0, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	mov r1, r8
	strh r0, [r1, 0x3A]
	lsls r4, 16
	asrs r4, 16
	subs r4, r5
	lsls r4, 4
	adds r0, r4, 0
	adds r1, r6, 0
	bl __divsi3
	mov r2, r8
	strh r0, [r2, 0x3C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815D72C

	thumb_func_start sub_815D794
sub_815D794: @ 815D794
	ldrh r1, [r0, 0x3A]
	ldrh r2, [r0, 0x36]
	adds r1, r2
	strh r1, [r0, 0x36]
	ldrh r2, [r0, 0x3C]
	ldrh r3, [r0, 0x38]
	adds r2, r3
	strh r2, [r0, 0x38]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r0, 0x20]
	lsls r2, 16
	asrs r2, 20
	strh r2, [r0, 0x22]
	bx lr
	thumb_func_end sub_815D794

	thumb_func_start sub_815D7B4
sub_815D7B4: @ 815D7B4
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldrh r6, [r4, 0x20]
	ldrh r5, [r4, 0x22]
	bl sub_80A6838
	ldr r0, =gBattleAnimArgs
	ldrb r1, [r0]
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x22
	ldrsh r2, [r4, r0]
	lsls r6, 16
	asrs r6, 16
	lsls r5, 16
	asrs r5, 16
	str r5, [sp]
	movs r0, 0x40
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r3, r6, 0
	bl sub_815D72C
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_815D804
	str r0, [r4, 0x1C]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D7B4

	thumb_func_start sub_815D804
sub_815D804: @ 815D804
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	lsls r4, 3
	movs r0, 0xFF
	ands r4, r0
	adds r0, r5, 0
	bl sub_815D794
	adds r0, r4, 0
	movs r1, 0x8
	bl Sin
	strh r0, [r5, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x3A
	ble _0815D86A
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815D86A
	movs r0, 0
	strh r0, [r5, 0x30]
	ldrh r1, [r5, 0x32]
	adds r1, 0x1
	strh r1, [r5, 0x32]
	movs r0, 0x1
	ands r1, r0
	adds r3, r5, 0
	adds r3, 0x3E
	lsls r1, 2
	ldrb r2, [r3]
	subs r0, 0x6
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0x3
	ble _0815D86A
	adds r0, r5, 0
	bl move_anim_8074EE0
_0815D86A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815D804

	thumb_func_start sub_815D870
sub_815D870: @ 815D870
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x2E]
	ldrb r1, [r6]
	adds r0, r5, 0
	bl StartSpriteAffineAnim
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815D896
	ldrh r0, [r6, 0x2]
	negs r0, r0
	strh r0, [r6, 0x2]
_0815D896:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x2]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x4]
	adds r0, r6
	strh r0, [r5, 0x22]
	ldr r0, =sub_810E2C8
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D870

	thumb_func_start sub_815D8D8
sub_815D8D8: @ 815D8D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	subs r0, 0x1
	strh r0, [r3, 0x8]
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r8, r2
	cmp r0, 0
	beq _0815D95A
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815D95A
	movs r2, 0x1A
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815D92C
	ldrh r0, [r3, 0x10]
	strh r0, [r3, 0x1A]
	negs r0, r0
	strh r0, [r3, 0x10]
	b _0815D92E
	.pool
_0815D92C:
	strh r7, [r3, 0x1A]
_0815D92E:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	mov r2, r8
	adds r1, r0, r2
	movs r2, 0x1C
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0815D94A
	ldrh r0, [r1, 0x12]
	strh r0, [r1, 0x1C]
	negs r0, r0
	strh r0, [r1, 0x12]
	b _0815D94E
_0815D94A:
	movs r0, 0
	strh r0, [r1, 0x1C]
_0815D94E:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	add r0, r8
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0xA]
_0815D95A:
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	ldrh r6, [r4, 0x16]
	ldrh r7, [r4, 0x18]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r12, r2
	cmp r0, 0
	beq _0815D998
	ldr r3, =gSprites
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	lsrs r2, r6, 8
	ldrh r0, [r4, 0x1A]
	subs r0, r2
	strh r0, [r1, 0x24]
	adds r2, r3, 0
	b _0815D9AE
	.pool
_0815D998:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	lsrs r1, r6, 8
	ldrh r4, [r4, 0x1A]
	adds r1, r4
	strh r1, [r0, 0x24]
_0815D9AE:
	mov r1, r12
	adds r0, r1, r5
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0815D9E0
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r2, r7, 8
	ldrh r0, [r4, 0x1C]
	subs r0, r2
	b _0815D9F2
	.pool
_0815D9E0:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r0, r7, 8
	ldrh r4, [r4, 0x1C]
	adds r0, r4
_0815D9F2:
	strh r0, [r1, 0x26]
	mov r2, r12
	adds r0, r2, r5
	lsls r0, 3
	add r0, r8
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bgt _0815DA12
	adds r0, r5, 0
	bl DestroyTask
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_0815DA12:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815D8D8

	thumb_func_start sub_815DA20
sub_815DA20: @ 815DA20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r7, 0
	ldr r2, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	subs r0, 0x1
	strh r0, [r3, 0x8]
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r8, r2
	cmp r0, 0
	beq _0815DAA6
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0815DAA6
	movs r2, 0x1A
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815DA78
	ldrh r0, [r3, 0x10]
	strh r0, [r3, 0x1A]
	negs r0, r0
	strh r0, [r3, 0x10]
	b _0815DA7A
	.pool
_0815DA78:
	strh r7, [r3, 0x1A]
_0815DA7A:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	mov r2, r8
	adds r1, r0, r2
	movs r2, 0x1C
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0815DA96
	ldrh r0, [r1, 0x12]
	strh r0, [r1, 0x1C]
	negs r0, r0
	strh r0, [r1, 0x12]
	b _0815DA9A
_0815DA96:
	movs r0, 0
	strh r0, [r1, 0x1C]
_0815DA9A:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	add r0, r8
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0xA]
_0815DAA6:
	lsls r3, r6, 2
	adds r0, r3, r6
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	ldrh r2, [r4, 0xC]
	ldr r1, =0x00007fff
	adds r0, r1, 0
	ands r0, r2
	ldrh r2, [r4, 0x16]
	adds r0, r2
	lsls r5, r0, 16
	lsrs r0, r5, 16
	mov r9, r0
	ldrh r0, [r4, 0xE]
	ands r1, r0
	ldrh r2, [r4, 0x18]
	adds r1, r2
	lsls r1, 16
	lsrs r7, r1, 16
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	mov r12, r3
	cmp r0, 0
	beq _0815DB00
	ldr r3, =gSprites
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	lsrs r2, r5, 24
	ldrh r0, [r4, 0x1A]
	subs r0, r2
	strh r0, [r1, 0x24]
	adds r2, r3, 0
	b _0815DB16
	.pool
_0815DB00:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	lsrs r1, r5, 24
	ldrh r4, [r4, 0x1A]
	adds r1, r4
	strh r1, [r0, 0x24]
_0815DB16:
	mov r1, r12
	adds r0, r1, r6
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0815DB48
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r2, r7, 8
	ldrh r0, [r4, 0x1C]
	subs r0, r2
	b _0815DB5A
	.pool
_0815DB48:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsrs r0, r7, 8
	ldrh r4, [r4, 0x1C]
	adds r0, r4
_0815DB5A:
	strh r0, [r1, 0x26]
	mov r2, r12
	adds r0, r2, r6
	lsls r0, 3
	mov r1, r8
	adds r2, r0, r1
	mov r0, r9
	strh r0, [r2, 0x16]
	strh r7, [r2, 0x18]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bgt _0815DB80
	movs r0, 0x1E
	strh r0, [r2, 0x8]
	movs r0, 0
	strh r0, [r2, 0x22]
	ldr r0, =sub_815D8D8
	str r0, [r2]
_0815DB80:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DA20

	thumb_func_start sub_815DB90
sub_815DB90: @ 815DB90
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gTasks
	mov r8, r0
	lsls r7, r6, 2
	adds r0, r7, r6
	lsls r0, 3
	mov r1, r8
	adds r4, r0, r1
	ldr r1, =gBankSpriteIds
	ldr r2, =gAnimationBankAttacker
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r4, 0x26]
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5]
	strh r0, [r4, 0x24]
	ldrh r0, [r5]
	strh r0, [r4, 0x8]
	ldrh r0, [r5, 0xC]
	strh r0, [r4, 0x22]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, 0
	beq _0815DBD4
	ldrh r0, [r4, 0x14]
	ldr r3, =0xffff8000
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r4, 0x14]
_0815DBD4:
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815DC04
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0xC]
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0xE]
	mov r3, r8
	adds r4, r7, 0
	b _0815DC74
	.pool
_0815DC04:
	movs r7, 0x2
	ldrsh r0, [r5, r7]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0815DC20
	ldrh r1, [r5, 0x2]
	ldr r0, =0x00007fff
	ands r0, r1
	b _0815DC28
	.pool
_0815DC20:
	ldrh r0, [r5, 0x2]
	ldr r2, =0xffff8000
	adds r1, r2, 0
	orrs r0, r1
_0815DC28:
	strh r0, [r4, 0xC]
	ldr r0, =gBattleAnimArgs
	movs r3, 0x4
	ldrsh r1, [r0, r3]
	movs r2, 0x80
	lsls r2, 8
	ands r1, r2
	adds r5, r0, 0
	cmp r1, 0
	beq _0815DC60
	ldr r3, =gTasks
	lsls r4, r6, 2
	adds r1, r4, r6
	lsls r1, 3
	adds r1, r3
	ldrh r2, [r5, 0x4]
	ldr r0, =0x00007fff
	ands r0, r2
	b _0815DC72
	.pool
_0815DC60:
	ldr r3, =gTasks
	lsls r4, r6, 2
	adds r1, r4, r6
	lsls r1, 3
	adds r1, r3
	ldrh r2, [r5, 0x4]
	ldr r7, =0xffff8000
	adds r0, r7, 0
	orrs r0, r2
_0815DC72:
	strh r0, [r1, 0xE]
_0815DC74:
	adds r0, r4, r6
	lsls r0, 3
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x18]
	strh r1, [r0, 0x16]
	ldrh r1, [r5, 0x8]
	strh r1, [r0, 0x10]
	ldrh r1, [r5, 0xA]
	strh r1, [r0, 0x12]
	ldr r1, =sub_815DA20
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DB90

	thumb_func_start sub_815DCA4
sub_815DCA4: @ 815DCA4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	ldr r4, =gBattleAnimArgs
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815DCC4
	adds r0, r2, 0
	bl move_anim_task_del
_0815DCC4:
	movs r0, 0
	strh r0, [r5, 0x8]
	strh r0, [r5, 0xA]
	strh r0, [r5, 0xC]
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0xE]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815DCE8
	ldr r0, =gAnimationBankAttacker
	b _0815DCEA
	.pool
_0815DCE8:
	ldr r0, =gAnimationBankTarget
_0815DCEA:
	ldrb r4, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x10]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	adds r0, r4, 0
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x14]
	ldr r0, =gBattleAnimArgs
	ldrb r0, [r0]
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r5, 0x26]
	ldr r2, =gUnknown_085CE74C
	adds r0, r5, 0
	bl sub_80A7CFC
	ldr r0, =sub_815DD48
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DCA4

	thumb_func_start sub_815DD48
sub_815DD48: @ 815DD48
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815DD6C
	cmp r0, 0x1
	beq _0815DDCC
	b _0815DDDA
	.pool
_0815DD6C:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815DD82
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_815DDE0
_0815DD82:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x12
	bne _0815DD92
	adds r0, r5, 0
	movs r1, 0
	bl sub_815DDE0
_0815DD92:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0815DDDA
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _0815DDB4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815DDDA
_0815DDB4:
	strh r1, [r4, 0xA]
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE74C
	adds r0, r4, 0
	bl sub_80A7CFC
	b _0815DDDA
	.pool
_0815DDCC:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815DDDA
	adds r0, r5, 0
	bl move_anim_task_del
_0815DDDA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815DD48

	thumb_func_start sub_815DDE0
sub_815DDE0: @ 815DDE0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r2, =gTasks
	adds r4, r0, r2
	cmp r1, 0
	bne _0815DE08
	movs r1, 0x12
	movs r3, 0xEC
	b _0815DE0C
	.pool
_0815DE08:
	movs r1, 0x1E
	movs r3, 0x14
_0815DE0C:
	mov r2, sp
	ldrh r0, [r4, 0x10]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x10]
	subs r0, r1
	subs r0, 0x4
	strh r0, [r2, 0x2]
	ldrh r0, [r4, 0x10]
	adds r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r4, 0x10]
	adds r0, r1
	adds r0, 0x4
	strh r0, [r2, 0x6]
	add r2, sp, 0x8
	lsls r1, r3, 24
	asrs r1, 24
	ldrh r0, [r4, 0x12]
	adds r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x12]
	adds r0, r1
	adds r0, 0x6
	strh r0, [r2, 0x2]
	movs r5, 0
	mov r8, r2
	ldr r7, =gSprites
_0815DE44:
	lsls r0, r5, 1
	add r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	ands r0, r5
	lsls r0, 1
	add r0, r8
	movs r3, 0
	ldrsh r2, [r0, r3]
	ldrb r3, [r4, 0x14]
	subs r3, 0x5
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_085CE76C
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0815DE98
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r7
	movs r0, 0
	strh r0, [r1, 0x2E]
	movs r0, 0x2
	cmp r5, 0x1
	bhi _0815DE86
	movs r2, 0x2
	negs r2, r2
	adds r0, r2, 0
_0815DE86:
	strh r0, [r1, 0x30]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x32]
	strh r6, [r1, 0x34]
	movs r0, 0x2
	strh r0, [r1, 0x36]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
_0815DE98:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _0815DE44
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DDE0

	thumb_func_start sub_815DEBC
sub_815DEBC: @ 815DEBC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x32]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _0815DF02
	ldr r3, =gTasks
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x34
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0815DF02:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DEBC

	thumb_func_start sub_815DF0C
sub_815DF0C: @ 815DF0C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0xA]
	ldrb r0, [r1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	adds r0, r1
	strh r0, [r4, 0xC]
	ldr r0, =sub_815DF64
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DF0C

	thumb_func_start sub_815DF64
sub_815DF64: @ 815DF64
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815DFB4
	ldrh r0, [r4, 0xC]
	ldr r2, =gUnknown_085CE784
	movs r3, 0x8
	ldrsh r1, [r4, r3]
	lsls r1, 1
	adds r1, r2
	ldrh r3, [r1]
	movs r1, 0x10
	movs r2, 0x8
	bl BlendPalette
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	ble _0815DFA4
	movs r0, 0
	strh r0, [r4, 0x8]
_0815DFA4:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	b _0815DFC6
	.pool
_0815DFB4:
	ldrh r0, [r4, 0xC]
	movs r1, 0x10
	movs r2, 0
	movs r3, 0
	bl BlendPalette
	adds r0, r5, 0
	bl move_anim_task_del
_0815DFC6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815DF64

	thumb_func_start sub_815DFCC
sub_815DFCC: @ 815DFCC
	push {lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0xD0
	lsls r2, 1
	ldr r1, =gAnimationBankAttacker
	ldrb r3, [r1]
	ldr r1, =gBattleAnimArgs
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, 0xA
	str r1, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0x1E
	str r1, [sp, 0xC]
	ldr r1, =gUnknown_08C2DC68
	str r1, [sp, 0x10]
	ldr r1, =gUnknown_08C2DDC4
	str r1, [sp, 0x14]
	ldr r1, =gUnknown_08C2DDA4
	str r1, [sp, 0x18]
	movs r1, 0
	bl sub_8117854
	add sp, 0x1C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815DFCC

	thumb_func_start sub_815E01C
sub_815E01C: @ 815E01C
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815E038
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0815E038:
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r5, 0x22]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815E080
	movs r0, 0xA0
	lsls r0, 2
	strh r0, [r5, 0x2E]
	ldr r0, =0x0000fd80
	strh r0, [r5, 0x30]
	b _0815E0A8
	.pool
_0815E080:
	cmp r0, 0x1
	bne _0815E09A
	adds r2, r5, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0xA0
	lsls r0, 2
	strh r0, [r5, 0x2E]
	strh r0, [r5, 0x30]
	b _0815E0A8
_0815E09A:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
	movs r0, 0xA0
	lsls r0, 2
	strh r0, [r5, 0x2E]
_0815E0A8:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815E0C8
	ldrh r0, [r5, 0x2E]
	negs r0, r0
	strh r0, [r5, 0x2E]
	adds r2, r5, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_0815E0C8:
	ldr r0, =sub_815E0DC
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E01C

	thumb_func_start sub_815E0DC
sub_815E0DC: @ 815E0DC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x3A]
	adds r0, r1
	strh r0, [r2, 0x3A]
	ldrh r1, [r2, 0x30]
	ldrh r3, [r2, 0x3C]
	adds r1, r3
	strh r1, [r2, 0x3C]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x24]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r2, 0x26]
	ldrh r0, [r2, 0x38]
	adds r0, 0x1
	strh r0, [r2, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bne _0815E110
	adds r0, r2, 0
	bl move_anim_8072740
_0815E110:
	pop {r0}
	bx r0
	thumb_func_end sub_815E0DC

	thumb_func_start sub_815E114
sub_815E114: @ 815E114
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	bl IsContest
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0815E144
	movs r0, 0x8
	strh r0, [r6, 0x12]
	movs r0, 0x3
	strh r0, [r6, 0x14]
	movs r0, 0x1
	strh r0, [r6, 0x16]
	b _0815E14E
	.pool
_0815E144:
	movs r0, 0xC
	strh r0, [r6, 0x12]
	movs r0, 0x3
	strh r0, [r6, 0x14]
	strh r1, [r6, 0x16]
_0815E14E:
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815E188
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E17C
	adds r0, 0x3
_0815E17C:
	asrs r0, 2
	adds r0, r4, r0
	b _0815E1AC
	.pool
_0815E188:
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E1A8
	adds r0, 0x3
_0815E1A8:
	asrs r0, 2
	subs r0, r4, r0
_0815E1AC:
	strh r0, [r6, 0x1E]
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r4, r0, 0
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E1D0
	adds r0, 0x3
_0815E1D0:
	asrs r0, 2
	subs r0, r4, r0
	strh r0, [r6, 0x20]
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x22]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x24]
	ldr r0, =sub_815E20C
	str r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E114

	thumb_func_start sub_815E20C
sub_815E20C: @ 815E20C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _0815E238
	cmp r1, 0x1
	bne _0815E230
	b _0815E330
_0815E230:
	b _0815E33E
	.pool
_0815E238:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0815E33E
	strh r1, [r5, 0xA]
	movs r1, 0x1E
	ldrsh r0, [r5, r1]
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r3, 0x22
	ldrsh r2, [r5, r3]
	movs r4, 0x24
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, 0x12]
	str r4, [sp]
	ldrb r4, [r5, 0xC]
	str r4, [sp, 0x4]
	add r4, sp, 0x10
	str r4, [sp, 0x8]
	adds r4, 0x2
	str r4, [sp, 0xC]
	bl sub_815E34C
	movs r6, 0
	mov r8, r4
	ldr r4, =gSprites
_0815E272:
	add r0, sp, 0x10
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r3, r8
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r0, =gUnknown_085CE7EC
	movs r3, 0x23
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x40
	beq _0815E306
	movs r1, 0x16
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815E2C6
	cmp r6, 0
	bne _0815E2B4
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	negs r0, r0
	strh r0, [r1, 0x26]
	strh r0, [r1, 0x24]
	b _0815E2EE
	.pool
_0815E2B4:
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	strh r0, [r1, 0x26]
	ldrh r0, [r5, 0x14]
	strh r0, [r1, 0x24]
	b _0815E2EE
_0815E2C6:
	cmp r6, 0
	bne _0815E2DC
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	negs r0, r0
	strh r0, [r1, 0x24]
	ldrh r0, [r5, 0x14]
	b _0815E2EC
_0815E2DC:
	lsls r2, r3, 4
	adds r1, r2, r3
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r5, 0x14]
	strh r0, [r1, 0x24]
	ldrh r0, [r5, 0x14]
	negs r0, r0
_0815E2EC:
	strh r0, [r1, 0x26]
_0815E2EE:
	ldr r1, =gSprites
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x2E]
	strh r7, [r0, 0x30]
	movs r1, 0xA
	strh r1, [r0, 0x32]
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
_0815E306:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x1
	bls _0815E272
	ldrh r2, [r5, 0xC]
	movs r3, 0xC
	ldrsh r1, [r5, r3]
	movs r4, 0x12
	ldrsh r0, [r5, r4]
	cmp r1, r0
	bne _0815E324
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_0815E324:
	adds r0, r2, 0x1
	strh r0, [r5, 0xC]
	b _0815E33E
	.pool
_0815E330:
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0815E33E
	adds r0, r7, 0
	bl move_anim_task_del
_0815E33E:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815E20C

	thumb_func_start sub_815E34C
sub_815E34C: @ 815E34C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	ldr r6, [sp, 0x30]
	mov r9, r6
	ldr r6, [sp, 0x34]
	mov r10, r6
	lsls r0, 16
	lsrs r0, 16
	mov r12, r0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	lsls r2, 16
	lsrs r2, 16
	adds r7, r2, 0
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r6, r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r8, r5
	cmp r5, 0
	bne _0815E394
	mov r2, r9
	strh r0, [r2]
	mov r6, r10
	strh r1, [r6]
	b _0815E3F2
_0815E394:
	cmp r5, r6
	bcc _0815E3A2
	mov r0, r9
	strh r2, [r0]
	mov r1, r10
	strh r3, [r1]
	b _0815E3F2
_0815E3A2:
	subs r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	mov r2, r12
	lsls r1, r2, 16
	asrs r1, 16
	lsls r5, r1, 8
	lsls r0, r7, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 8
	adds r1, r6, 0
	bl __divsi3
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r5, r0
	ldr r2, [sp]
	lsls r1, r2, 16
	asrs r1, 16
	lsls r4, r1, 8
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	asrs r0, 16
	subs r0, r1
	lsls r0, 8
	adds r1, r6, 0
	bl __divsi3
	mov r6, r8
	muls r6, r0
	adds r0, r6, 0
	adds r4, r0
	asrs r5, 8
	mov r0, r9
	strh r5, [r0]
	asrs r4, 8
	mov r1, r10
	strh r4, [r1]
_0815E3F2:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815E34C

	thumb_func_start sub_815E404
sub_815E404: @ 815E404
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x24
	ble _0815E43A
	ldr r3, =gTasks
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r1, 1
	movs r0, 0x30
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl DestroySprite
_0815E43A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E404

	thumb_func_start sub_815E444
sub_815E444: @ 815E444
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x22]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	ldr r1, =move_anim_8072740
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A70C0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E444

	thumb_func_start sub_815E47C
sub_815E47C: @ 815E47C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	ldr r0, =gAnimationBankAttacker
	mov r10, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x1E]
	mov r1, r10
	ldrb r0, [r1]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x20]
	ldr r0, =gAnimationBankTarget
	mov r8, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x22]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r4, r0, 0
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0
	bl sub_80A861C
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0815E4EE
	adds r0, 0x3
_0815E4EE:
	asrs r0, 2
	adds r0, r4, r0
	strh r0, [r7, 0x24]
	ldr r4, =gUnknown_085CE84C
	movs r0, 0x1E
	ldrsh r5, [r7, r0]
	movs r1, 0x20
	ldrsh r6, [r7, r1]
	mov r1, r8
	ldrb r0, [r1]
	bl sub_80A82E4
	adds r3, r0, 0
	subs r3, 0x5
	lsls r3, 24
	lsrs r3, 24
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x26]
	cmp r0, 0x40
	beq _0815E5B8
	ldr r4, =gSprites
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x10
	strh r1, [r0, 0x2E]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r7, 0x22]
	strh r1, [r0, 0x32]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r7, 0x24]
	strh r1, [r0, 0x36]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x38]
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl sub_80A68D4
	mov r1, r10
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815E596
	movs r0, 0x26
	ldrsh r1, [r7, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAffineAnim
_0815E596:
	ldr r0, =sub_815E5CC
	str r0, [r7]
	b _0815E5BE
	.pool
_0815E5B8:
	mov r0, r9
	bl move_anim_task_del
_0815E5BE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_815E47C

	thumb_func_start sub_815E5CC
sub_815E5CC: @ 815E5CC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _0815E634
	cmp r1, 0x1
	bgt _0815E5F4
	cmp r1, 0
	beq _0815E5FE
	b _0815E6D2
	.pool
_0815E5F4:
	cmp r1, 0x2
	beq _0815E658
	cmp r1, 0x3
	beq _0815E6CC
	b _0815E6D2
_0815E5FE:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E6D2
	strh r1, [r4, 0xA]
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80A6900
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0815E6D2
	b _0815E6BE
	.pool
_0815E634:
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _0815E6D2
	movs r0, 0
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	b _0815E6BE
	.pool
_0815E658:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E6D2
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r2, [r4, 0xC]
	adds r2, 0x1
	strh r2, [r4, 0xC]
	ldr r5, =gSprites
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r0, 0x1
	ands r2, r0
	adds r1, 0x3E
	lsls r2, 2
	ldrb r3, [r1]
	subs r0, 0x6
	ands r0, r3
	orrs r0, r2
	strb r0, [r1]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _0815E6D2
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
_0815E6BE:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815E6D2
	.pool
_0815E6CC:
	adds r0, r2, 0
	bl move_anim_task_del
_0815E6D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815E5CC

	thumb_func_start sub_815E6D8
sub_815E6D8: @ 815E6D8
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r6, r0, 0
	cmp r1, 0
	bne _0815E6F4
	ldr r0, =gAnimationBankAttacker
	b _0815E6F6
	.pool
_0815E6F4:
	ldr r0, =gAnimationBankTarget
_0815E6F6:
	ldrb r5, [r0]
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r1, r6, 0
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x3A]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	movs r1, 0x1
	cmp r0, 0
	bne _0815E724
	movs r3, 0x1
	negs r3, r3
	adds r1, r3, 0
_0815E724:
	strh r1, [r4, 0x3C]
	adds r0, r5, 0
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815E768
	ldrb r2, [r4, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x47
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	subs r0, 0x8
	b _0815E772
	.pool
_0815E768:
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	adds r0, 0x8
_0815E772:
	strh r0, [r4, 0x20]
	ldr r0, =sub_815E784
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E6D8

	thumb_func_start sub_815E784
sub_815E784: @ 815E784
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	cmp r1, 0x1
	beq _0815E7CC
	cmp r1, 0x1
	bgt _0815E79A
	cmp r1, 0
	beq _0815E7A4
	b _0815E83C
_0815E79A:
	cmp r1, 0x2
	beq _0815E7DC
	cmp r1, 0x3
	beq _0815E802
	b _0815E83C
_0815E7A4:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E83C
	strh r1, [r2, 0x30]
	ldrh r0, [r2, 0x3C]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _0815E83C
	b _0815E7FA
_0815E7CC:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bne _0815E83C
	b _0815E7F6
_0815E7DC:
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	lsls r1, 2
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815E83C
_0815E7F6:
	movs r0, 0
	strh r0, [r2, 0x30]
_0815E7FA:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _0815E83C
_0815E802:
	movs r0, 0x3C
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bne _0815E83C
	ldrh r0, [r2, 0x3A]
	subs r0, 0x1
	strh r0, [r2, 0x3A]
	lsls r0, 16
	cmp r0, 0
	beq _0815E836
	movs r0, 0
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	b _0815E83C
_0815E836:
	adds r0, r2, 0
	bl move_anim_8072740
_0815E83C:
	pop {r0}
	bx r0
	thumb_func_end sub_815E784

	thumb_func_start sub_815E840
sub_815E840: @ 815E840
	push {r4,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r2, =gBattleAnimArgs
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _0815E85C
	adds r0, r1, 0
	bl move_anim_task_del
	b _0815E884
	.pool
_0815E85C:
	ldr r0, =gTasks
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r2, 0x2]
	strh r0, [r4, 0x8]
	ldrb r0, [r2]
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE87C
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_815E898
	str r0, [r4]
_0815E884:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E840

	thumb_func_start sub_815E898
sub_815E898: @ 815E898
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815E8F2
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815E8E0
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	b _0815E8F0
	.pool
_0815E8E0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
_0815E8F0:
	strh r1, [r0, 0x24]
_0815E8F2:
	adds r0, r4, 0
	bl sub_80A7D34
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0815E94E
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	cmp r0, 0
	beq _0815E948
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_085CE87C
	bl sub_80A7CFC
	strh r5, [r4, 0xA]
	strh r5, [r4, 0xC]
	b _0815E94E
	.pool
_0815E948:
	adds r0, r6, 0
	bl move_anim_task_del
_0815E94E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_815E898

	thumb_func_start sub_815E954
sub_815E954: @ 815E954
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815E970
	ldr r4, =gAnimationBankAttacker
	b _0815E972
	.pool
_0815E970:
	ldr r4, =gAnimationBankTarget
_0815E972:
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	strh r0, [r5, 0x22]
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	cmp r0, 0x7
	bgt _0815E996
	movs r0, 0x8
	strh r0, [r5, 0x22]
_0815E996:
	movs r2, 0
	strh r2, [r5, 0x2E]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x30]
	strh r2, [r5, 0x32]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x34]
	ldr r0, =sub_815E9BC
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815E954

	thumb_func_start sub_815E9BC
sub_815E9BC: @ 815E9BC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x30
	ldrsh r1, [r3, r2]
	cmp r0, r1
	blt _0815EA10
	movs r0, 0
	strh r0, [r3, 0x2E]
	ldrh r1, [r3, 0x32]
	adds r1, 0x1
	movs r0, 0x1
	ands r1, r0
	strh r1, [r3, 0x32]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	lsls r1, 2
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r2, 0x32
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _0815EA10
	ldrh r0, [r3, 0x34]
	subs r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	cmp r0, 0
	bne _0815EA10
	adds r0, r3, 0
	bl move_anim_8072740
_0815EA10:
	pop {r0}
	bx r0
	thumb_func_end sub_815E9BC

	thumb_func_start sub_815EA14
sub_815EA14: @ 815EA14
	push {lr}
	adds r3, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815EA44
	ldrb r2, [r3, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x47
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	movs r0, 0x64
	strh r0, [r3, 0x20]
	movs r0, 0x1
	b _0815EA4A
	.pool
_0815EA44:
	movs r0, 0x8C
	strh r0, [r3, 0x20]
	ldr r0, =0x0000ffff
_0815EA4A:
	strh r0, [r3, 0x3C]
	movs r0, 0x38
	strh r0, [r3, 0x22]
	ldr r0, =sub_815EA60
	str r0, [r3, 0x1C]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815EA14

	thumb_func_start sub_815EA60
sub_815EA60: @ 815EA60
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	bls _0815EA6E
	b _0815EC40
_0815EA6E:
	lsls r0, 2
	ldr r1, =_0815EA7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815EA7C:
	.4byte _0815EAA0
	.4byte _0815EAD2
	.4byte _0815EAE4
	.4byte _0815EB24
	.4byte _0815EB36
	.4byte _0815EB74
	.4byte _0815EBD8
	.4byte _0815EBF8
	.4byte _0815EC1E
_0815EAA0:
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	lsls r0, 1
	ldrh r1, [r4, 0x22]
	subs r1, r0
	strh r1, [r4, 0x22]
	ldrh r2, [r4, 0x30]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0815EAC2
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r1, 1
	ldrh r0, [r4, 0x20]
	subs r0, r1
	strh r0, [r4, 0x20]
_0815EAC2:
	adds r0, r2, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	beq _0815EAD0
	b _0815EC40
_0815EAD0:
	b _0815EC12
_0815EAD2:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _0815EAE2
	b _0815EC40
_0815EAE2:
	b _0815EC12
_0815EAE4:
	ldrh r2, [r4, 0x30]
	adds r2, 0x1
	strh r2, [r4, 0x30]
	movs r3, 0x3C
	ldrsh r1, [r4, r3]
	lsls r0, r1, 1
	adds r0, r1
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r3, =gSineTable
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x3C]
	muls r0, r1
	strh r0, [r4, 0x24]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0xC
	beq _0815EB1C
	b _0815EC40
_0815EB1C:
	b _0815EC12
	.pool
_0815EB24:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	beq _0815EB34
	b _0815EC40
_0815EB34:
	b _0815EC12
_0815EB36:
	ldrh r2, [r4, 0x30]
	adds r2, 0x1
	strh r2, [r4, 0x30]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	ldrh r0, [r4, 0x22]
	subs r0, r1
	strh r0, [r4, 0x22]
	ldr r3, =gSineTable
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x3C]
	muls r0, r1
	strh r0, [r4, 0x24]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0xC
	bne _0815EC40
	b _0815EC16
	.pool
_0815EB74:
	ldrh r2, [r4, 0x30]
	adds r2, 0x1
	strh r2, [r4, 0x30]
	movs r3, 0x3C
	ldrsh r1, [r4, r3]
	lsls r0, r1, 1
	adds r0, r1
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r3, =gSineTable
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x3C]
	muls r0, r1
	strh r0, [r4, 0x24]
	lsls r2, 16
	asrs r2, 16
	cmp r2, 0xF
	bne _0815EBC0
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
_0815EBC0:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x12
	bne _0815EC40
	b _0815EC12
	.pool
_0815EBD8:
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	ldrh r0, [r4, 0x20]
	adds r1, r0
	strh r1, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815EC40
	b _0815EC12
_0815EBF8:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r0, 1
	ldrh r3, [r4, 0x20]
	adds r0, r3
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0815EC40
_0815EC12:
	movs r0, 0
	strh r0, [r4, 0x30]
_0815EC16:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815EC40
_0815EC1E:
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	ldrh r0, [r4, 0x20]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815EC40
	adds r0, r4, 0
	bl move_anim_8072740
_0815EC40:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815EA60

	thumb_func_start sub_815EC48
sub_815EC48: @ 815EC48
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x26]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815ECD0
	bl battle_type_is_double
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x1
	bne _0815ECB4
	ldr r5, =gAnimationBankAttacker
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r1, [r5]
	movs r0, 0x2
	eors r0, r1
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	ble _0815ECAC
	strh r7, [r6, 0x24]
	b _0815ECD4
	.pool
_0815ECAC:
	ldr r0, =0x0000ffff
	b _0815ECD2
	.pool
_0815ECB4:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815ECD0
	ldr r0, =0x0000ffff
	b _0815ECD2
	.pool
_0815ECD0:
	movs r0, 0x1
_0815ECD2:
	strh r0, [r6, 0x24]
_0815ECD4:
	ldr r0, =sub_815ECE4
	str r0, [r6]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815EC48

	thumb_func_start sub_815ECE4
sub_815ECE4: @ 815ECE4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	movs r1, 0x8
	ldrsh r0, [r3, r1]
	cmp r0, 0x8
	bls _0815ECFE
	b _0815EE78
_0815ECFE:
	lsls r0, 2
	ldr r1, =_0815ED10
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815ED10:
	.4byte _0815ED34
	.4byte _0815ED46
	.4byte _0815ED78
	.4byte _0815EDA8
	.4byte _0815EDCE
	.4byte _0815EDF8
	.4byte _0815EE08
	.4byte _0815EE28
	.4byte _0815EE60
_0815ED34:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	beq _0815ED44
	b _0815EE78
_0815ED44:
	b _0815EE50
_0815ED46:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	lsls r2, r0, 1
	adds r2, r0
	ldrh r0, [r1, 0x24]
	subs r0, r2
	strh r0, [r1, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	beq _0815ED72
	b _0815EE78
_0815ED72:
	b _0815EE50
	.pool
_0815ED78:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x24
	ldrsh r2, [r3, r0]
	lsls r0, r2, 1
	adds r0, r2
	ldrh r2, [r1, 0x24]
	adds r0, r2
	strh r0, [r1, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815EE78
	b _0815EE50
	.pool
_0815EDA8:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0815EE78
	movs r0, 0
	strh r0, [r3, 0xA]
	ldrh r1, [r3, 0xC]
	movs r2, 0xC
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bne _0815EE54
	adds r0, r1, 0x1
	strh r0, [r3, 0xC]
	movs r0, 0x1
	strh r0, [r3, 0x8]
	b _0815EE78
_0815EDCE:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r3, 0x24]
	ldrh r2, [r0, 0x24]
	adds r1, r2
	strh r1, [r0, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0815EE78
	b _0815EE50
	.pool
_0815EDF8:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0815EE78
	b _0815EE50
_0815EE08:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0x24
	ldrsh r2, [r3, r0]
	lsls r2, 2
	ldrh r0, [r1, 0x24]
	subs r0, r2
	b _0815EE40
	.pool
_0815EE28:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	lsls r0, 2
	ldrh r2, [r1, 0x24]
	adds r0, r2
_0815EE40:
	strh r0, [r1, 0x24]
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0815EE78
_0815EE50:
	movs r0, 0
	strh r0, [r3, 0xA]
_0815EE54:
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _0815EE78
	.pool
_0815EE60:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x24]
	adds r0, r4, 0
	bl move_anim_task_del
_0815EE78:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815ECE4

	thumb_func_start sub_815EE84
sub_815EE84: @ 815EE84
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815EEA8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gAnimationBankAttacker
	b _0815EEAA
	.pool
_0815EEA8:
	ldr r0, =gAnimationBankTarget
_0815EEAA:
	ldrb r0, [r0]
	strh r0, [r4, 0x3C]
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815EECE
	ldrb r0, [r4, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r4, 0x3]
_0815EECE:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A8328
	movs r2, 0x3
	ands r2, r0
	lsls r2, 2
	ldrb r3, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	adds r0, r1, 0
	ands r0, r3
	orrs r0, r2
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0x1]
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r4, 0x1]
	ldr r0, =sub_815EF08
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815EE84

	thumb_func_start sub_815EF08
sub_815EF08: @ 815EF08
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _0815EF16
	b _0815F106
_0815EF16:
	lsls r0, 2
	ldr r1, =_0815EF24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815EF24:
	.4byte _0815EF38
	.4byte _0815F038
	.4byte _0815F0A0
	.4byte _0815F0B4
	.4byte _0815F100
_0815EF38:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0x5
	bhi _0815EF68
	lsls r0, 2
	ldr r1, =_0815EF50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815EF50:
	.4byte _0815EF6C
	.4byte _0815EF88
	.4byte _0815EFAA
	.4byte _0815EFC6
	.4byte _0815EF6C
	.4byte _0815EFEC
_0815EF68:
	movs r0, 0
	strh r0, [r4, 0x3A]
_0815EF6C:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	b _0815EFE0
_0815EF88:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x4
	b _0815EFE6
_0815EFAA:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	b _0815EFE0
_0815EFC6:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
_0815EFE0:
	bl sub_80A861C
	subs r0, 0x4
_0815EFE6:
	lsls r0, 16
	lsrs r1, r0, 16
	b _0815F00C
_0815EFEC:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r1, r0, 24
_0815F00C:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0x4
	bne _0815F018
	movs r0, 0x18
	b _0815F022
_0815F018:
	cmp r0, 0x5
	bne _0815F020
	movs r0, 0x6
	b _0815F022
_0815F020:
	movs r0, 0xC
_0815F022:
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	strh r1, [r4, 0x36]
	adds r0, r4, 0
	bl obj_translate_based_on_private_1_2_3_4
	b _0815F0F8
_0815F038:
	adds r0, r4, 0
	bl sub_80A6F3C
	lsls r0, 24
	cmp r0, 0
	beq _0815F106
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	beq _0815F070
	cmp r0, 0x5
	beq _0815F090
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _0815F088
_0815F070:
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x38]
_0815F088:
	ldrh r0, [r4, 0x3A]
	adds r0, 0x1
	strh r0, [r4, 0x3A]
	b _0815F106
_0815F090:
	movs r0, 0
	strh r0, [r4, 0x2E]
	movs r1, 0x10
	strh r1, [r4, 0x30]
	strh r0, [r4, 0x32]
	movs r0, 0x3
	strh r0, [r4, 0x38]
	b _0815F106
_0815F0A0:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0815F106
	movs r0, 0
	strh r0, [r4, 0x38]
	b _0815F106
_0815F0B4:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815F0C6
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	b _0815F0CC
_0815F0C6:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
_0815F0CC:
	ldrh r1, [r4, 0x32]
	lsls r1, 8
	ldrh r0, [r4, 0x30]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	bne _0815F106
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0815F0F8:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _0815F106
_0815F100:
	adds r0, r4, 0
	bl move_anim_8072740
_0815F106:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815EF08

	thumb_func_start sub_815F10C
sub_815F10C: @ 815F10C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	subs r0, r1
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	muls r0, r1
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r5, r0, 0
	strh r5, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	subs r0, r1
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	muls r0, r1
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r3, r0, 0
	strh r3, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815F16A
	ldr r0, =gUnknown_085CE3A0
	ldrh r1, [r4, 0x20]
	adds r1, r5
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x22]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0x5
	bl CreateSprite
_0815F16A:
	movs r0, 0x38
	ldrsh r1, [r4, r0]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0815F17C
	adds r0, r4, 0
	bl move_anim_8072740
_0815F17C:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F10C

	thumb_func_start sub_815F18C
sub_815F18C: @ 815F18C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A5C6C
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0815F1B8
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815F1D0
_0815F1B8:
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r5, 0x20]
	ldrh r0, [r2]
	subs r0, r1, r0
	strh r0, [r5, 0x2E]
	ldrh r0, [r2, 0x4]
	subs r1, r0
	b _0815F1DE
	.pool
_0815F1D0:
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r5, 0x20]
	ldrh r0, [r2]
	adds r0, r1, r0
	strh r0, [r5, 0x2E]
	ldrh r0, [r2, 0x4]
	adds r1, r0
_0815F1DE:
	strh r1, [r5, 0x32]
	adds r3, r2, 0
	ldrh r1, [r5, 0x22]
	ldrh r2, [r3, 0x2]
	adds r2, r1, r2
	strh r2, [r5, 0x30]
	ldrh r0, [r3, 0x6]
	adds r1, r0
	strh r1, [r5, 0x34]
	ldrh r0, [r3, 0x8]
	strh r0, [r5, 0x36]
	ldrh r0, [r5, 0x2E]
	strh r0, [r5, 0x20]
	strh r2, [r5, 0x22]
	ldr r0, =sub_815F10C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F18C

	thumb_func_start sub_815F20C
sub_815F20C: @ 815F20C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r5, r0, 24
	adds r2, r5, 0
	ldr r0, =gTasks
	mov r9, r0
	lsls r7, r6, 2
	adds r0, r7, r6
	lsls r0, 3
	mov r8, r0
	mov r4, r8
	add r4, r9
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0815F254
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	b _0815F2A0
	.pool
_0815F254:
	cmp r0, 0x1
	bne _0815F2AC
	ldrh r0, [r4, 0xA]
	adds r0, 0x60
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	subs r0, 0xD
	strh r0, [r4, 0xC]
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r0, 0xC
	ldrsh r2, [r4, r0]
	adds r0, r5, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bne _0815F310
	movs r0, 0
	strh r0, [r4, 0xE]
	adds r0, r5, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0815F2A0:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815F310
	.pool
_0815F2AC:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl refresh_graphics_maybe
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815F2EE
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x10
	adds r0, r1
	ldr r1, =gUnknown_082FF6C0
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	bl StartSpriteAffineAnim
_0815F2EE:
	mov r4, r9
	adds r3, r7, 0
	ldr r5, =sub_815F330
	movs r1, 0xF
	mov r2, r8
	adds r0, r4, r2
	adds r0, 0x26
	movs r2, 0
_0815F2FE:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0815F2FE
	adds r0, r3, r6
	lsls r0, 3
	adds r0, r4
	str r5, [r0]
_0815F310:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F20C

	thumb_func_start sub_815F330
sub_815F330: @ 815F330
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _0815F394
	cmp r5, 0x1
	bgt _0815F360
	cmp r5, 0
	beq _0815F36A
	b _0815F482
	.pool
_0815F360:
	cmp r5, 0x2
	beq _0815F400
	cmp r5, 0x3
	beq _0815F43C
	b _0815F482
_0815F36A:
	ldr r0, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldr r0, =0x0000ff38
	strh r0, [r1, 0x26]
	movs r0, 0xC8
	strh r0, [r1, 0x24]
	adds r1, 0x3E
	ldrb r2, [r1]
	subs r0, 0xCD
	ands r0, r2
	strb r0, [r1]
	strh r5, [r4, 0x1C]
	b _0815F42E
	.pool
_0815F394:
	ldrh r1, [r4, 0x1C]
	adds r1, 0x70
	movs r5, 0
	strh r1, [r4, 0x1C]
	ldr r2, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r2, r0, r2
	lsls r1, 16
	asrs r1, 24
	ldrh r3, [r2, 0x26]
	adds r1, r3
	strh r1, [r2, 0x26]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	blt _0815F3C4
	strh r5, [r2, 0x24]
_0815F3C4:
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	ble _0815F3CE
	strh r5, [r2, 0x26]
_0815F3CE:
	movs r3, 0x26
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _0815F482
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7D
	bl PlaySE12WithPanning
	ldr r1, =0xfffff800
	adds r0, r1, 0
	ldrh r2, [r4, 0x1C]
	adds r0, r2
	strh r0, [r4, 0x1C]
	b _0815F42E
	.pool
_0815F400:
	ldrh r0, [r4, 0x1C]
	subs r0, 0x70
	strh r0, [r4, 0x1C]
	lsls r0, 16
	cmp r0, 0
	bge _0815F410
	movs r0, 0
	strh r0, [r4, 0x1C]
_0815F410:
	ldr r0, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r4, 0x1C]
	lsls r2, 16
	asrs r2, 24
	ldrh r0, [r1, 0x26]
	subs r0, r2
	strh r0, [r1, 0x26]
	movs r3, 0x1C
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0815F482
_0815F42E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815F482
	.pool
_0815F43C:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x70
	strh r0, [r4, 0x1C]
	ldr r2, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r1, 0x26]
	adds r0, r2
	strh r0, [r1, 0x26]
	lsls r0, 16
	cmp r0, 0
	ble _0815F460
	movs r0, 0
	strh r0, [r1, 0x26]
_0815F460:
	movs r3, 0x26
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0815F482
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7D
	bl PlaySE12WithPanning
	adds r0, r6, 0
	bl move_anim_task_del
_0815F482:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F330

	thumb_func_start sub_815F48C
sub_815F48C: @ 815F48C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankTarget
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815F4B8
	ldrb r0, [r4]
	bl sub_80A82E4
	subs r0, 0x2
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	ldr r4, =0x0000ff70
	b _0815F4C8
	.pool
_0815F4B8:
	ldrb r0, [r4]
	bl sub_80A82E4
	adds r0, 0x2
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
	ldr r4, =0x0000ffa0
_0815F4C8:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x3
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	strh r4, [r5, 0x26]
	ldr r0, =sub_815F4F0
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F48C

	thumb_func_start sub_815F4F0
sub_815F4F0: @ 815F4F0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _0815F4FE
	b _0815F61A
_0815F4FE:
	lsls r0, 2
	ldr r1, =_0815F50C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815F50C:
	.4byte _0815F520
	.4byte _0815F544
	.4byte _0815F584
	.4byte _0815F5B4
	.4byte _0815F5E0
_0815F520:
	ldrh r0, [r4, 0x26]
	adds r0, 0xA
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _0815F61A
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCD
	bl PlaySE12WithPanning
	movs r0, 0
	strh r0, [r4, 0x26]
	b _0815F5D8
_0815F544:
	ldrh r1, [r4, 0x30]
	adds r1, 0x4
	movs r5, 0
	strh r1, [r4, 0x30]
	ldr r2, =gSineTable
	movs r3, 0x30
	ldrsh r0, [r4, r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	negs r0, r0
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _0815F61A
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCD
	bl PlaySE12WithPanning
	strh r5, [r4, 0x30]
	strh r5, [r4, 0x26]
	b _0815F5D8
	.pool
_0815F584:
	ldrh r1, [r4, 0x30]
	adds r1, 0x6
	movs r3, 0
	strh r1, [r4, 0x30]
	ldr r2, =gSineTable
	movs r5, 0x30
	ldrsh r0, [r4, r5]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	negs r0, r0
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x7F
	ble _0815F61A
	strh r3, [r4, 0x30]
	strh r3, [r4, 0x26]
	b _0815F5D8
	.pool
_0815F5B4:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0815F61A
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xC0
	bl PlaySE12WithPanning
	movs r0, 0
	strh r0, [r4, 0x30]
_0815F5D8:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815F61A
_0815F5E0:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0815F61A
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x32]
	adds r1, 0x1
	strh r1, [r4, 0x32]
	movs r0, 0x1
	ands r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	lsls r1, 2
	ldrb r2, [r3]
	subs r0, 0x6
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bne _0815F61A
	adds r0, r4, 0
	bl move_anim_8072740
_0815F61A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815F4F0

	thumb_func_start sub_815F620
sub_815F620: @ 815F620
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl IsContest
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _0815F66E
	movs r0, 0x1
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	lsrs r1, r0, 16
	mov r10, r1
	asrs r6, r0, 16
	cmp r6, 0
	blt _0815F66E
	movs r0, 0x1
	bl duplicate_obj_of_side_rel2move_in_transparent_mode
	lsls r0, 16
	lsrs r1, r0, 16
	mov r9, r1
	asrs r1, r0, 16
	cmp r1, 0
	bge _0815F67C
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl obj_delete_but_dont_free_vram
_0815F66E:
	mov r0, r8
	bl move_anim_task_del
	b _0815F780
	.pool
_0815F67C:
	ldr r4, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r0, r4
	ldrh r0, [r5, 0x24]
	adds r0, 0x18
	strh r0, [r5, 0x24]
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	adds r6, r0, r4
	ldrh r0, [r6, 0x24]
	subs r0, 0x18
	strh r0, [r6, 0x24]
	strh r7, [r5, 0x2E]
	strh r7, [r6, 0x2E]
	strh r7, [r5, 0x30]
	strh r7, [r6, 0x30]
	strh r7, [r5, 0x32]
	strh r7, [r6, 0x32]
	movs r0, 0x10
	strh r0, [r5, 0x34]
	ldr r0, =0x0000fff0
	strh r0, [r6, 0x34]
	strh r7, [r5, 0x36]
	movs r0, 0x80
	strh r0, [r6, 0x36]
	movs r0, 0x18
	strh r0, [r5, 0x38]
	strh r0, [r6, 0x38]
	mov r0, r8
	strh r0, [r5, 0x3A]
	strh r0, [r6, 0x3A]
	strh r7, [r5, 0x3C]
	strh r7, [r6, 0x3C]
	ldr r2, =gTasks
	mov r1, r8
	lsls r3, r1, 2
	adds r0, r3, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x8]
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r7, r4, 0
	mov r12, r3
	cmp r0, 0
	bne _0815F720
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	b _0815F736
	.pool
_0815F720:
	adds r1, r5, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
_0815F736:
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r4, r2, r7
	ldrb r1, [r4, 0x1]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4, 0x1]
	mov r1, r10
	lsls r0, r1, 16
	asrs r0, 16
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r4, r1, r7
	ldrb r0, [r4, 0x1]
	ands r3, r0
	strb r3, [r4, 0x1]
	adds r3, r7, 0
	adds r3, 0x1C
	adds r2, r3
	ldr r0, =sub_815F7C4
	str r0, [r2]
	adds r1, r3
	str r0, [r1]
	mov r0, r12
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldr r1, =sub_815F79C
	str r1, [r0]
_0815F780:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F620

	thumb_func_start sub_815F79C
sub_815F79C: @ 815F79C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815F7BA
	adds r0, r2, 0
	bl move_anim_task_del
_0815F7BA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F79C

	thumb_func_start sub_815F7C4
sub_815F7C4: @ 815F7C4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0815F80E
	movs r0, 0
	strh r0, [r4, 0x30]
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0815F80E
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r1, r2, 29
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0815F80E:
	ldrh r0, [r4, 0x34]
	ldrh r1, [r4, 0x36]
	adds r0, r1
	movs r5, 0
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x36]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815F840
	cmp r0, 0x1
	beq _0815F858
	b _0815F896
	.pool
_0815F840:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	bne _0815F896
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0815F896
_0815F858:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	lsls r0, 16
	cmp r0, 0
	ble _0815F896
	strh r5, [r4, 0x32]
	ldrh r0, [r4, 0x38]
	subs r0, 0x2
	strh r0, [r4, 0x38]
	lsls r0, 16
	cmp r0, 0
	bge _0815F896
	ldr r3, =gTasks
	movs r2, 0x3C
	ldrsh r1, [r4, r2]
	lsls r1, 1
	movs r0, 0x3A
	ldrsh r2, [r4, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r3, 0x8
	adds r1, r3
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	adds r0, r4, 0
	bl obj_delete_but_dont_free_vram
_0815F896:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F7C4

	thumb_func_start sub_815F8A0
sub_815F8A0: @ 815F8A0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, =gBattleAnimArgs
	movs r2, 0
	strh r2, [r3, 0xE]
	ldr r1, =gHappinessMoveAnim
	ldrb r0, [r1]
	ldrb r1, [r1]
	adds r0, r1, 0
	subs r0, 0x3D
	lsls r0, 24
	lsrs r0, 24
	adds r2, r1, 0
	cmp r0, 0x1E
	bhi _0815F8C4
	movs r0, 0x1
	strh r0, [r3, 0xE]
_0815F8C4:
	adds r0, r2, 0
	subs r0, 0x5C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6C
	bhi _0815F8D4
	movs r0, 0x2
	strh r0, [r3, 0xE]
_0815F8D4:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0xC8
	bls _0815F8E0
	movs r0, 0x3
	strh r0, [r3, 0xE]
_0815F8E0:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F8A0

	thumb_func_start sub_815F8F4
sub_815F8F4: @ 815F8F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bls _0815F91A
	b _0815FE68
_0815F91A:
	lsls r0, 2
	ldr r1, =_0815F92C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815F92C:
	.4byte _0815F940
	.4byte _0815F9F4
	.4byte _0815FBE8
	.4byte _0815FD08
	.4byte _0815FD8C
_0815F940:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	mov r2, r8
	lsls r4, r2, 2
	adds r0, r4, r2
	lsls r0, 3
	adds r6, r0, r1
	movs r3, 0x80
	lsls r3, 4
	adds r0, r3, 0
	ldrh r1, [r6, 0xA]
	adds r0, r1
	strh r0, [r6, 0xA]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0815F998
	ldr r2, =gSprites
	lsls r3, r7, 4
	adds r1, r3, r7
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r6, 0xA]
	lsls r0, 16
	asrs r0, 24
	ldrh r4, [r1, 0x24]
	adds r0, r4
	strh r0, [r1, 0x24]
	b _0815F9B2
	.pool
_0815F998:
	ldr r3, =gSprites
	lsls r4, r7, 4
	adds r2, r4, r7
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r6, 0xA]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
	adds r3, r4, 0
_0815F9B2:
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	strh r0, [r4, 0xA]
	adds r1, r3, r7
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x24]
	ldrh r1, [r1, 0x20]
	adds r0, r1
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 14
	adds r0, r1
	movs r1, 0x98
	lsls r1, 17
	cmp r0, r1
	bhi _0815F9DE
	b _0815FE68
_0815F9DE:
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0815FE68
	.pool
_0815F9F4:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0815FA28
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldr r2, [r0, 0x8]
	mov r10, r2
	ldr r3, [r0, 0xC]
	mov r9, r3
	ldrh r6, [r0]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0
	b _0815FB4E
	.pool
_0815FA28:
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FAC8
	ldr r7, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r10, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	mov r9, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815FA9C
	lsls r0, r2, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815FA9E
	.pool
_0815FA9C:
	ldrh r6, [r1, 0x2]
_0815FA9E:
	movs r0, 0x1
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0
	movs r5, 0x88
	lsls r5, 1
	b _0815FB50
	.pool
_0815FAC8:
	ldr r7, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r10, r0
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	mov r9, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	bne _0815FB2C
	lsls r0, r2, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	b _0815FB2E
	.pool
_0815FB2C:
	ldrh r6, [r1, 0x2]
_0815FB2E:
	movs r0, 0x1
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0x1
_0815FB4E:
	ldr r5, =0x0000ffe0
_0815FB50:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r5, 16
	asrs r3, 16
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r4, r10
	str r4, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	str r0, [sp, 0x10]
	movs r0, 0
	str r0, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	bl sub_80A8394
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldrb r0, [r4]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0815FBBA
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r0, r1
	ldr r3, =0x00007fff
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
_0815FBBA:
	ldr r0, =gTasks
	mov r3, r8
	lsls r1, r3, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	strh r5, [r1, 0x26]
	b _0815FD7E
	.pool
_0815FBE8:
	ldr r1, =gTasks
	mov r0, r8
	lsls r4, r0, 2
	adds r0, r4, r0
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0x26]
	lsls r0, 24
	lsrs r5, r0, 24
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1, 0
	ldrh r2, [r6, 0xA]
	adds r0, r2
	strh r0, [r6, 0xA]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0815FC40
	ldr r3, =gSprites
	lsls r4, r5, 4
	adds r2, r4, r5
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r6, 0xA]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
	adds r3, r4, 0
	b _0815FC56
	.pool
_0815FC40:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r1, r3, r5
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r6, 0xA]
	lsls r0, 16
	asrs r0, 24
	ldrh r4, [r1, 0x24]
	adds r0, r4
	strh r0, [r1, 0x24]
_0815FC56:
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r6, r0, r1
	ldrb r0, [r6, 0xA]
	strh r0, [r6, 0xA]
	adds r1, r3, r5
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x24]
	ldrh r1, [r1, 0x20]
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0815FCD6
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FCB4
	lsls r4, r5, 16
	asrs r4, 16
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bge _0815FCD6
	b _0815FCCA
	.pool
_0815FCB4:
	lsls r4, r5, 16
	asrs r4, 16
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	ble _0815FCD6
_0815FCCA:
	ldrh r0, [r6, 0x24]
	adds r0, 0x1
	strh r0, [r6, 0x24]
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x0000ffff
	strh r0, [r1, 0xE]
_0815FCD6:
	lsls r0, r5, 16
	movs r2, 0x80
	lsls r2, 14
	adds r0, r2
	movs r1, 0x98
	lsls r1, 17
	cmp r0, r1
	bhi _0815FCE8
	b _0815FE68
_0815FCE8:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0xA]
	b _0815FD7E
	.pool
_0815FD08:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	mov r3, r8
	lsls r4, r3, 2
	adds r0, r4, r3
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x26]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	bl sub_80A8610
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0815FD60
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	adds r1, r5
	ldrh r0, [r1, 0x20]
	negs r0, r0
	subs r0, 0x20
	strh r0, [r1, 0x24]
	b _0815FD74
	.pool
_0815FD60:
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	adds r0, r5
	ldrh r2, [r0, 0x20]
	movs r4, 0x88
	lsls r4, 1
	adds r1, r4, 0
	subs r1, r2
	strh r1, [r0, 0x24]
_0815FD74:
	ldr r0, =gTasks
	mov r1, r9
	add r1, r8
	lsls r1, 3
	adds r1, r0
_0815FD7E:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0815FE68
	.pool
_0815FD8C:
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	mov r0, r8
	lsls r4, r0, 2
	adds r0, r4, r0
	lsls r0, 3
	adds r2, r0, r1
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1, 0
	ldrh r3, [r2, 0xA]
	adds r0, r3
	strh r0, [r2, 0xA]
	ldr r0, =gAnimationBankAttacker
	mov r10, r0
	ldrb r0, [r0]
	str r2, [sp, 0x18]
	bl GetBankSide
	lsls r0, 24
	mov r9, r4
	ldr r2, [sp, 0x18]
	cmp r0, 0
	bne _0815FE0C
	ldr r1, =gSprites
	lsls r5, r7, 4
	adds r0, r5, r7
	lsls r0, 2
	adds r6, r0, r1
	ldrh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r6, 0x24]
	adds r0, r1
	strh r0, [r6, 0x24]
	movs r2, 0x24
	ldrsh r4, [r6, r2]
	movs r3, 0x20
	ldrsh r0, [r6, r3]
	adds r4, r0
	mov r1, r10
	ldrb r0, [r1]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r3, r5, 0
	cmp r4, r0
	blt _0815FE44
	movs r2, 0
	strh r2, [r6, 0x24]
	b _0815FE44
	.pool
_0815FE0C:
	ldr r1, =gSprites
	lsls r5, r7, 4
	adds r0, r5, r7
	lsls r0, 2
	adds r6, r0, r1
	ldrh r1, [r2, 0xA]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r6, 0x24]
	subs r0, r1
	strh r0, [r6, 0x24]
	movs r3, 0x24
	ldrsh r4, [r6, r3]
	movs r1, 0x20
	ldrsh r0, [r6, r1]
	adds r4, r0
	mov r2, r10
	ldrb r0, [r2]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r3, r5, 0
	cmp r4, r0
	bgt _0815FE44
	movs r4, 0
	strh r4, [r6, 0x24]
_0815FE44:
	ldr r1, =gTasks
	mov r0, r9
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0xA]
	strh r1, [r0, 0xA]
	ldr r1, =gSprites
	adds r0, r3, r7
	lsls r0, 2
	adds r0, r1
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0815FE68
	mov r0, r8
	bl move_anim_task_del
_0815FE68:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815F8F4

	thumb_func_start sub_815FE80
sub_815FE80: @ 815FE80
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0815FE92
	cmp r0, 0x1
	beq _0815FF3A
	b _0815FFBC
_0815FE92:
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0815FF2C
	movs r0, 0x3F
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7A
	bl PlaySE12WithPanning
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	strh r0, [r4, 0x22]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815FFBC
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815FFBC
	movs r0, 0x1
	bl GetAnimBankSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0x1
	adds r1, r4, 0
	adds r1, 0x43
	strb r0, [r1]
	b _0815FFBC
	.pool
_0815FF2C:
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _0815FFBC
_0815FF3A:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x2E
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r2, [r4, 0x30]
	adds r0, r2, 0x5
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7F
	ble _0815FF6E
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r0, r2, 0
	subs r0, 0x7A
	strh r0, [r4, 0x30]
_0815FF6E:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FF9C
	ldrh r2, [r4, 0x32]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
	strh r0, [r4, 0x24]
	adds r1, r2, 0
	b _0815FFA8
	.pool
_0815FF9C:
	ldrh r1, [r4, 0x32]
	lsls r0, r1, 16
	asrs r0, 24
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
_0815FFA8:
	movs r0, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x2
	bne _0815FFBC
	adds r0, r4, 0
	bl move_anim_8072740
_0815FFBC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815FE80

	thumb_func_start sub_815FFC4
sub_815FFC4: @ 815FFC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x26
	ldrsh r0, [r0, r2]
	adds r3, r1, 0
	cmp r0, 0x4
	bls _0815FFE0
	b _08160132
_0815FFE0:
	lsls r0, 2
	ldr r1, =_0815FFF4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0815FFF4:
	.4byte _08160008
	.4byte _08160058
	.4byte _081600B4
	.4byte _081600CC
	.4byte _08160132
_08160008:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	movs r0, 0x6
	strh r0, [r1, 0x8]
	cmp r5, r2
	ble _0816003E
	negs r0, r0
	strh r0, [r1, 0x8]
_0816003E:
	strh r5, [r1, 0xA]
	strh r2, [r1, 0xC]
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _08160150
	.pool
_08160058:
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r1
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r3
	ldrh r0, [r2, 0x8]
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _081600A0
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	b _08160126
	.pool
_081600A0:
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _08160150
	b _0816012A
_081600B4:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r3
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	negs r1, r1
	strh r1, [r0, 0x8]
	ldrh r1, [r0, 0x26]
	adds r1, 0x1
	strh r1, [r0, 0x26]
	b _08160150
_081600CC:
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r1
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r3
	ldrh r0, [r2, 0x8]
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	movs r3, 0x8
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bge _08160118
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xA
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _08160150
	b _0816012A
	.pool
_08160118:
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	movs r3, 0x24
	ldrsh r1, [r1, r3]
	adds r0, r1
	movs r3, 0xA
	ldrsh r1, [r2, r3]
_08160126:
	cmp r0, r1
	blt _08160150
_0816012A:
	ldrh r0, [r2, 0x26]
	adds r0, 0x1
	strh r0, [r2, 0x26]
	b _08160150
_08160132:
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x24]
	adds r0, r4, 0
	bl move_anim_task_del
_08160150:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815FFC4

	thumb_func_start sub_8160164
sub_8160164: @ 8160164
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	movs r0, 0
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0xE]
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	bne _08160198
	movs r1, 0x1
_08160198:
	strh r1, [r4, 0x10]
	ldr r2, =gSprites
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x14]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x20]
	strh r0, [r4, 0x12]
	strh r5, [r4, 0x1A]
	strh r5, [r4, 0x1E]
	movs r0, 0x1
	strh r0, [r4, 0x1C]
	strh r5, [r4, 0x20]
	ldr r0, =sub_81601DC
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160164

	thumb_func_start sub_81601DC
sub_81601DC: @ 81601DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08160284
	cmp r0, 0x1
	bgt _08160204
	cmp r0, 0
	beq _0816020A
	b _081602DA
	.pool
_08160204:
	cmp r0, 0x2
	beq _081602D4
	b _081602DA
_0816020A:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x8
	movs r2, 0xFF
	ands r0, r2
	strh r0, [r4, 0x1E]
	ldr r5, =gSprites
	movs r6, 0xE
	ldrsh r0, [r4, r6]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldr r3, =gSineTable
	movs r6, 0x1E
	ldrsh r0, [r4, r6]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
	strh r0, [r1, 0x24]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x2
	ands r0, r2
	strh r0, [r4, 0x1A]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r5
	movs r6, 0x1A
	ldrsh r0, [r4, r6]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	ldrh r1, [r4, 0x10]
	muls r0, r1
	ldrh r1, [r4, 0x12]
	adds r0, r1
	strh r0, [r2, 0x20]
	movs r6, 0x1A
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bne _081602DA
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r4, 0x12]
	strh r1, [r0, 0x20]
	b _081602C4
	.pool
_08160284:
	ldrh r0, [r4, 0x1E]
	adds r0, 0x8
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x1E]
	ldr r3, =gSprites
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldr r2, =gSineTable
	movs r5, 0x1E
	ldrsh r0, [r4, r5]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 21
	strh r0, [r1, 0x24]
	movs r6, 0x1E
	ldrsh r2, [r4, r6]
	cmp r2, 0
	bne _081602DA
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	strh r2, [r1, 0x24]
_081602C4:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081602DA
	.pool
_081602D4:
	adds r0, r2, 0
	bl move_anim_task_del
_081602DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81601DC

	thumb_func_start sub_81602E0
sub_81602E0: @ 81602E0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldrh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl Sin
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08160326
	adds r0, r4, 0
	bl move_anim_8072740
_08160326:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81602E0

	thumb_func_start sub_8160338
sub_8160338: @ 8160338
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0816037C
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r4, 0x20]
	ldrh r1, [r2]
	subs r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldr r0, =0x0000fff5
	strh r0, [r4, 0x2E]
	movs r0, 0xC0
	strh r0, [r4, 0x30]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _08160396
	.pool
_0816037C:
	movs r0, 0xB
	strh r0, [r4, 0x2E]
	movs r0, 0xC0
	strh r0, [r4, 0x30]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_08160396:
	ldr r0, =sub_81602E0
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160338

	thumb_func_start sub_81603A8
sub_81603A8: @ 81603A8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gAnimationBankAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	strh r0, [r5, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _081603D2
	movs r0, 0x10
	strh r0, [r5, 0x22]
_081603D2:
	movs r0, 0
	strh r0, [r5, 0x3A]
	movs r1, 0x10
	strh r1, [r5, 0x3C]
	ldr r0, =sub_81603F4
	str r0, [r5, 0x1C]
	lsls r1, 8
	movs r0, 0x52
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81603A8

	thumb_func_start sub_81603F4
sub_81603F4: @ 81603F4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _0816046C
	cmp r1, 0x1
	bgt _0816040A
	cmp r1, 0
	beq _08160414
	b _081604E8
_0816040A:
	cmp r1, 0x2
	beq _08160482
	cmp r1, 0x3
	beq _081604E2
	b _081604E8
_08160414:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081604E8
	strh r1, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0816043E
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r0, 0xF
	bgt _0816044C
	adds r0, r2, 0x1
	strh r0, [r4, 0x3A]
	b _0816044C
_0816043E:
	ldrh r2, [r4, 0x3C]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0816044C
	subs r0, r2, 0x1
	strh r0, [r4, 0x3C]
_0816044C:
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081604E8
	b _081604DA
_0816046C:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _081604E8
	strh r1, [r4, 0x2E]
	strh r1, [r4, 0x30]
	b _081604DA
_08160482:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081604E8
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldrh r1, [r4, 0x30]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081604AE
	ldrh r2, [r4, 0x3A]
	movs r3, 0x3A
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _081604BC
	subs r0, r2, 0x1
	strh r0, [r4, 0x3A]
	b _081604BC
_081604AE:
	ldrh r2, [r4, 0x3C]
	movs r3, 0x3C
	ldrsh r0, [r4, r3]
	cmp r0, 0xF
	bgt _081604BC
	adds r0, r2, 0x1
	strh r0, [r4, 0x3C]
_081604BC:
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	ldrh r1, [r4, 0x3C]
	lsls r1, 8
	ldrh r0, [r4, 0x3A]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _081604E8
_081604DA:
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	b _081604E8
_081604E2:
	adds r0, r4, 0
	bl move_anim_8074EE0
_081604E8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81603F4

	thumb_func_start sub_81604F0
sub_81604F0: @ 81604F0
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gBattleAnimArgs
	movs r0, 0
	strh r0, [r2, 0xE]
	ldr r0, =gWeatherMoveAnim
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08160514
	movs r0, 0x1
	b _08160536
	.pool
_08160514:
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08160520
	movs r0, 0x2
	b _08160536
_08160520:
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _0816052C
	movs r0, 0x3
	b _08160536
_0816052C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160538
	movs r0, 0x4
_08160536:
	strh r0, [r2, 0xE]
_08160538:
	adds r0, r3, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	thumb_func_end sub_81604F0

	thumb_func_start sub_8160544
sub_8160544: @ 8160544
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r0, =gBattleAnimArgs
	ldrb r0, [r0]
	bl GetAnimBankSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE9C8
	adds r0, r4, 0
	bl sub_80A7CFC
	ldr r0, =sub_816058C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160544

	thumb_func_start sub_816058C
sub_816058C: @ 816058C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r2, =gTasks
	adds r3, r0, r2
	ldrh r0, [r3, 0x8]
	adds r1, r0, 0x1
	movs r5, 0
	strh r1, [r3, 0x8]
	subs r0, 0x10
	lsls r0, 16
	lsrs r0, 16
	adds r6, r2, 0
	cmp r0, 0x16
	bhi _081605F0
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08160600
	strh r5, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _081605F0
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x24]
	b _08160600
	.pool
_081605F0:
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x24]
_08160600:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	bl sub_80A7D34
	lsls r0, 24
	cmp r0, 0
	bne _08160618
	adds r0, r4, 0
	bl move_anim_task_del
_08160618:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816058C

	thumb_func_start sub_8160624
sub_8160624: @ 8160624
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8160624

	thumb_func_start sub_8160638
sub_8160638: @ 8160638
	push {lr}
	sub sp, 0x4
	bl script_env_2_enable
	ldr r0, =sub_8160664
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160638

	thumb_func_start sub_8160664
sub_8160664: @ 8160664
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08160688
	ldr r0, =sub_81606A0
	bl SetMainCallback2
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80AF168
	str r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_08160688:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160664

	thumb_func_start sub_81606A0
sub_81606A0: @ 81606A0
	push {r4-r6,lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl clear_scheduled_bg_copies_to_vram
	ldr r6, =gUnknown_0203BC34
	movs r0, 0x8C
	lsls r0, 1
	bl AllocZeroed
	str r0, [r6]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	adds r0, 0x44
	movs r5, 0
	strb r1, [r0]
	ldr r0, =sub_8160624
	bl SetVBlankCallback
	bl sub_81607EC
	movs r0, 0
	bl sub_81D2824
	ldr r4, =gUnknown_0203BC38
	movs r0, 0
	strh r5, [r4]
	strh r5, [r4, 0x2]
	strb r0, [r4, 0x4]
	bl sub_8161280
	ldr r0, =gUnknown_085CEBB0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085CEBB8
	bl LoadSpritePalette
	bl sub_81610B8
	ldr r0, =gUnknown_03006310
	ldrh r1, [r4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	ldr r1, [r6]
	movs r2, 0x89
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_816082C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81606A0

	thumb_func_start sub_8160740
sub_8160740: @ 8160740
	push {r4,r5,lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl clear_scheduled_bg_copies_to_vram
	ldr r5, =gUnknown_0203BC34
	movs r0, 0x8C
	lsls r0, 1
	bl AllocZeroed
	str r0, [r5]
	movs r1, 0x1C
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	adds r0, 0x44
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	adds r0, 0x45
	strb r1, [r0]
	ldr r0, =sub_8160624
	bl SetVBlankCallback
	bl sub_81607EC
	ldr r4, =gUnknown_0203BC38
	ldrb r0, [r4, 0x4]
	bl sub_81D2824
	bl sub_8161280
	ldr r0, =gUnknown_085CEBB0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085CEBB8
	bl LoadSpritePalette
	bl sub_81610B8
	ldr r0, =gUnknown_03006310
	ldrh r1, [r4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	ldr r1, [r5]
	movs r2, 0x89
	lsls r2, 1
	adds r1, r2
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_816082C
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160740

	thumb_func_start sub_81607EC
sub_81607EC: @ 81607EC
	push {lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085CEC28
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	bl sub_8121E10
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81607EC

	thumb_func_start sub_816082C
sub_816082C: @ 816082C
	push {lr}
	bl sub_8160868
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_816082C

	thumb_func_start sub_816084C
sub_816084C: @ 816084C
	push {r4,lr}
	adds r1, r0, 0
	ldr r4, =gStringVar4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816084C

	thumb_func_start sub_8160868
sub_8160868: @ 8160868
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r1, =gUnknown_0203BC34
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r7, r1, 0
	cmp r0, 0x21
	bls _0816087E
	b _08160E8A
_0816087E:
	lsls r0, 2
	ldr r1, =_08160890
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08160890:
	.4byte _08160918
	.4byte _08160932
	.4byte _0816094C
	.4byte _08160954
	.4byte _0816095C
	.4byte _08160964
	.4byte _08160980
	.4byte _08160E8A
	.4byte _08160988
	.4byte _081609A8
	.4byte _08160E8A
	.4byte _08160E8A
	.4byte _08160A44
	.4byte _08160A64
	.4byte _08160CB8
	.4byte _08160CD8
	.4byte _08160AB8
	.4byte _08160AD0
	.4byte _08160AEC
	.4byte _08160C1C
	.4byte _08160C48
	.4byte _08160C98
	.4byte _08160CA6
	.4byte _08160E8A
	.4byte _08160B2C
	.4byte _08160B60
	.4byte _08160B80
	.4byte _08160BDC
	.4byte _08160CFC
	.4byte _08160D48
	.4byte _08160E0C
	.4byte _08160E38
	.4byte _08160E58
	.4byte _08160E70
_08160918:
	ldr r1, [r7]
	ldrb r0, [r1]
	adds r0, 0x1
	movs r4, 0
	strb r0, [r1]
	movs r0, 0
	bl render_previous_quest_text
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	b _08160CAE
_08160932:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160940
	b _08160E8A
_08160940:
	ldr r1, [r7]
	movs r0, 0x4
	b _08160E88
	.pool
_0816094C:
	ldr r1, [r7]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
_08160954:
	movs r0, 0
	bl render_previous_quest_text
	b _0816096A
_0816095C:
	movs r0, 0
	bl sub_8160F50
	b _08160E8A
_08160964:
	movs r0, 0
	bl sub_8161074
_0816096A:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_81611AC
	b _08160E8A
	.pool
_08160980:
	movs r0, 0x1
	bl sub_8160F50
	b _08160E8A
_08160988:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160994
	b _08160E8A
_08160994:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_081609A8:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160A0A
	ldr r5, =gUnknown_0203BC34
	ldr r0, [r5]
	adds r0, 0x44
	ldrb r1, [r0]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	bl sub_8161054
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl GiveMoveToMon
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _08160A04
	ldr r0, =gUnknown_085EF8E4
	bl sub_816084C
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x1
	strh r0, [r1]
	ldr r1, [r5]
	movs r0, 0x1F
	b _08160E88
	.pool
_08160A04:
	ldr r1, [r5]
	movs r0, 0x10
	b _08160E88
_08160A0A:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160A18
	cmp r1, 0x1
	beq _08160A18
	b _08160E8A
_08160A18:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160A30
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160A30:
	cmp r0, 0x1
	beq _08160A36
	b _08160E8A
_08160A36:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160A44:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160A50
	b _08160E8A
_08160A50:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160A64:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160A7C
	ldr r0, =gSpecialVar_0x8004
	strh r1, [r0]
	b _08160E82
	.pool
_08160A7C:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160A8A
	cmp r1, 0x1
	beq _08160A8A
	b _08160E8A
_08160A8A:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160AA4
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160AA4:
	cmp r0, 0x1
	beq _08160AAA
	b _08160E8A
_08160AAA:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160AB8:
	ldr r0, =gUnknown_085EF8F3
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160AD0:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160ADC
	b _08160E8A
_08160ADC:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x12
	b _08160E88
	.pool
_08160AEC:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160B10
	ldr r0, =gUnknown_085EFA10
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x13
	b _08160E88
	.pool
_08160B10:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160B1E
	cmp r1, 0x1
	beq _08160B1E
	b _08160E8A
_08160B1E:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x18
	b _08160E88
	.pool
_08160B2C:
	ldr r4, =gStringVar2
	bl sub_8161054
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gUnknown_085EF960
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160B60:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160B6C
	b _08160E8A
_08160B6C:
	bl sub_81D2C50
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160B80:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _08160B98
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x1B
	b _08160E88
	.pool
_08160B98:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08160BA6
	cmp r1, 0x1
	beq _08160BA6
	b _08160E8A
_08160BA6:
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160BC4
	ldr r2, =gUnknown_0203BC34
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1]
	adds r7, r2, 0
	b _08160BD0
	.pool
_08160BC4:
	ldr r7, =gUnknown_0203BC34
	cmp r0, 0x1
	bne _08160BD0
	ldr r1, [r7]
	movs r0, 0x5
	strb r0, [r1]
_08160BD0:
	ldr r1, [r7]
	movs r0, 0x10
	b _08160E88
	.pool
_08160BDC:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160BE8
	b _08160E8A
_08160BE8:
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160C08
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x3
	b _08160E88
	.pool
_08160C08:
	cmp r0, 0x1
	beq _08160C0E
	b _08160E8A
_08160C0E:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x5
	b _08160E88
	.pool
_08160C1C:
	bl sub_81D2C3C
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08160C2A
	b _08160E8A
_08160C2A:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x14
	strb r0, [r1]
	subs r0, 0x15
	str r2, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08160E8A
	.pool
_08160C48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160C56
	b _08160E8A
_08160C56:
	bl sub_8161054
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gPlayerParty
	ldr r1, =gUnknown_0203BC34
	ldr r1, [r1]
	adds r1, 0x44
	ldrb r1, [r1]
	ldr r2, =gPlayerPartyCount
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_8160740
	str r0, [sp]
	adds r0, r4, 0
	bl sub_81BFA38
	bl sub_8160EA0
	b _08160E8A
	.pool
_08160C98:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	beq _08160CA4
	b _08160E8A
_08160CA4:
	b _08160E82
_08160CA6:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
_08160CAE:
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _08160E8A
_08160CB8:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	b _08160E88
	.pool
_08160CD8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160CE6
	b _08160E8A
_08160CE6:
	bl sub_8160EA0
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	b _08160E8A
	.pool
_08160CFC:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08160D30
	movs r0, 0x1
	bl render_previous_quest_text
	b _08160D3A
	.pool
_08160D30:
	cmp r0, 0x1
	bne _08160D3A
	movs r0, 0x1
	bl sub_8161074
_08160D3A:
	bl sub_8161234
	movs r0, 0x3
	movs r1, 0x2
	bl CopyWindowToVram
	b _08160E8A
_08160D48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08160D56
	b _08160E8A
_08160D56:
	ldr r1, [r7]
	adds r2, r1, 0
	adds r2, 0x45
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _08160D6C
	movs r0, 0x18
	b _08160E88
	.pool
_08160D6C:
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	movs r4, 0x64
	muls r0, r4
	ldr r5, =gPlayerParty
	adds r0, r5
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gStringVar3
	movs r1, 0xD
	mov r8, r1
	mov r1, r8
	muls r1, r0
	ldr r6, =gMoveNames
	adds r1, r6
	adds r0, r2, 0
	bl StringCopy
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r0, [r0]
	muls r0, r4
	adds r0, r5
	adds r1, 0x45
	ldrb r1, [r1]
	bl RemoveMonPPBonus
	ldr r0, [r7]
	adds r0, 0x44
	ldrb r0, [r0]
	muls r4, r0
	adds r4, r5
	bl sub_8161054
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [r7]
	adds r0, 0x45
	ldrb r2, [r0]
	adds r0, r4, 0
	bl SetMonMoveSlot
	ldr r4, =gStringVar2
	bl sub_8161054
	mov r1, r8
	muls r1, r0
	adds r1, r6
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gUnknown_085EF979
	bl sub_816084C
	ldr r1, [r7]
	movs r0, 0x1E
	strb r0, [r1]
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x1
	strh r0, [r1]
	b _08160E8A
	.pool
_08160E0C:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	bne _08160E8A
	ldr r0, =gUnknown_085EF9A6
	bl sub_816084C
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x1F
	strb r0, [r1]
	ldr r0, =0x0000016f
	bl PlayFanfare
	b _08160E8A
	.pool
_08160E38:
	bl sub_81D2C3C
	lsls r0, 16
	cmp r0, 0
	bne _08160E8A
	ldr r0, =0x0000016f
	bl PlayFanfare
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x20
	b _08160E88
	.pool
_08160E58:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _08160E8A
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0x21
	b _08160E88
	.pool
_08160E70:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08160E8A
	movs r0, 0x5
	bl PlaySE
_08160E82:
	ldr r0, =gUnknown_0203BC34
	ldr r1, [r0]
	movs r0, 0xE
_08160E88:
	strb r0, [r1]
_08160E8A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160868

	thumb_func_start sub_8160EA0
sub_8160EA0: @ 8160EA0
	push {r4,lr}
	bl sub_8161234
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	movs r1, 0x89
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gUnknown_0203BC38
	adds r2, r1, 0x2
	bl sub_81AE6C8
	bl FreeAllWindowBuffers
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160EA0

	thumb_func_start render_previous_quest_text
render_previous_quest_text: @ 8160EE0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0
	ldr r6, =gSprites
	ldr r4, =gUnknown_0203BC34
	movs r3, 0x4
_08160EF0:
	ldr r0, [r4]
	adds r0, 0x1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0xF
	ble _08160EF0
	cmp r5, 0
	bne _08160F38
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF8C2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
_08160F38:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end render_previous_quest_text

	thumb_func_start sub_8160F50
sub_8160F50: @ 8160F50
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r6, =gUnknown_0203BC34
	ldr r0, [r6]
	movs r4, 0x89
	lsls r4, 1
	adds r0, r4
	ldrb r0, [r0]
	bl ListMenuHandleInput
	adds r5, r0, 0
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ldr r4, =gUnknown_0203BC38
	adds r2, r4, 0x2
	adds r1, r4, 0
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _08160FE4
	adds r0, 0x1
	cmp r5, r0
	bne _08161010
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _08160F9C
	bl GetLRKeysState
	lsls r0, 24
	cmp r0, 0
	beq _0816103E
_08160F9C:
	movs r0, 0x5
	bl PlaySE
	cmp r7, 0
	bne _08160FC4
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r1, 0x5
	strb r1, [r0]
	movs r0, 0x1
	strb r0, [r4, 0x4]
	b _08160FD4
	.pool
_08160FC4:
	movs r0, 0
	bl PutWindowTilemap
	ldr r0, [r6]
	movs r2, 0
	movs r1, 0x3
	strb r1, [r0]
	strb r2, [r4, 0x4]
_08160FD4:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	bl sub_8161054
	bl sub_816137C
	b _0816103E
_08160FE4:
	movs r0, 0x5
	bl PlaySE
	bl sub_8161234
	ldr r1, [r6]
	movs r0, 0xC
	strb r0, [r1]
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF9E6
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
	b _0816103E
	.pool
_08161010:
	movs r0, 0x5
	bl PlaySE
	bl sub_8161234
	ldr r1, [r6]
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r5
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF8DA
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	bl sub_81D2BF4
_0816103E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8160F50

	thumb_func_start sub_8161054
sub_8161054: @ 8161054
	ldr r0, =gUnknown_0203BC34
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BC38
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 3
	adds r2, 0x4C
	adds r2, r0
	ldr r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8161054

	thumb_func_start sub_8161074
sub_8161074: @ 8161074
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081610A6
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EF8C2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
_081610A6:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161074

	thumb_func_start sub_81610B8
sub_81610B8: @ 81610B8
	push {r4-r7,lr}
	ldr r2, =gUnknown_0203BC34
	ldr r0, [r2]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, =0x00000113
	adds r1, r0, r2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	bl sub_81611AC
	movs r4, 0
	ldr r5, =gUnknown_085CEC10
_081610DC:
	adds r2, r4, 0
	cmp r4, 0
	bge _081610E4
	adds r2, r4, 0x3
_081610E4:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r4, r1
	lsls r1, 19
	movs r0, 0xD0
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	lsls r2, 19
	movs r0, 0x90
	lsls r0, 14
	adds r2, r0
	asrs r2, 16
	adds r0, r5, 0
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_0203BC34
	ldr r1, [r2]
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x7
	ble _081610DC
	movs r4, 0
	ldr r7, =gUnknown_085CEC10
	adds r6, r2, 0
_0816111C:
	adds r2, r4, 0
	cmp r4, 0
	bge _08161124
	adds r2, r4, 0x3
_08161124:
	asrs r2, 2
	lsls r1, r2, 2
	subs r1, r4, r1
	lsls r1, 19
	movs r0, 0xD0
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	lsls r2, 19
	movs r0, 0xD0
	lsls r0, 14
	adds r2, r0
	asrs r2, 16
	adds r0, r7, 0
	movs r3, 0
	bl CreateSprite
	ldr r1, [r6]
	adds r2, r4, 0
	adds r2, 0x8
	adds r1, 0x1
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gSprites
	adds r0, r5
	movs r1, 0x2
	bl StartSpriteAnim
	adds r4, 0x1
	cmp r4, 0x7
	ble _0816111C
	movs r4, 0
	ldr r3, =gUnknown_0203BC34
	movs r2, 0x4
_08161176:
	ldr r0, [r3]
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0xF
	ble _08161176
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81610B8

	thumb_func_start sub_81611AC
sub_81611AC: @ 81611AC
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BC34
	ldr r1, [r4]
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081611D4
	ldr r0, =gUnknown_085CEBC0
	movs r3, 0x8B
	lsls r3, 1
	adds r1, r3
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	movs r5, 0x8A
	lsls r5, 1
	adds r1, r5
	strb r0, [r1]
_081611D4:
	ldr r0, [r4]
	ldr r6, =0x00000113
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08161210
	ldr r0, =gUnknown_0203CE8C
	adds r2, r0, 0
	ldr r1, =gUnknown_085CEBD0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r1, [r1]
	str r1, [r2]
	ldr r2, [r4]
	movs r3, 0x88
	lsls r3, 1
	adds r1, r2, r3
	ldrb r1, [r1]
	ldr r5, =0x00000111
	adds r2, r5
	ldrb r2, [r2]
	subs r1, r2
	strh r1, [r0, 0x8]
	ldr r1, =gUnknown_0203BC38
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	ldr r6, =0x00000113
	adds r1, r6
	strb r0, [r1]
_08161210:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81611AC

	thumb_func_start sub_8161234
sub_8161234: @ 8161234
	push {r4,lr}
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	movs r2, 0x8A
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08161256
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_08161256:
	ldr r0, [r4]
	ldr r2, =0x00000113
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08161270
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r2, =0x00000113
	adds r1, r0, r2
	movs r0, 0xFF
	strb r0, [r1]
_08161270:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161234

	thumb_func_start sub_8161280
sub_8161280: @ 8161280
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r4, =gUnknown_0203BC34
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	adds r1, 0x12
	bl GetMoveRelearnerMoves
	ldr r1, [r4]
	movs r6, 0x88
	lsls r6, 1
	adds r1, r6
	strb r0, [r1]
	movs r5, 0
	ldr r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	bge _081612F6
	mov r8, r4
	movs r0, 0xD
	mov r12, r0
	ldr r2, =gMoveNames
	mov r9, r2
_081612C2:
	mov r7, r8
	ldr r4, [r7]
	lsls r3, r5, 3
	adds r2, r4, 0
	adds r2, 0x48
	adds r2, r3
	lsls r0, r5, 1
	adds r1, r4, 0
	adds r1, 0x12
	adds r1, r0
	ldrh r0, [r1]
	mov r7, r12
	muls r7, r0
	adds r0, r7, 0
	add r0, r9
	str r0, [r2]
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r3
	ldrh r1, [r1]
	str r1, [r0]
	adds r5, 0x1
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r5, r0
	blt _081612C2
_081612F6:
	ldr r4, =gUnknown_0203BC34
	ldr r0, [r4]
	adds r0, 0x44
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	ldr r0, =gStringVar1
	mov r1, sp
	bl StringCopy10
	ldr r2, [r4]
	movs r5, 0x88
	lsls r5, 1
	adds r3, r2, r5
	ldrb r0, [r3]
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x48
	adds r1, r0
	ldr r0, =gUnknown_085E8CF0
	str r0, [r1]
	ldrb r0, [r3]
	lsls r0, 3
	adds r2, 0x4C
	adds r2, r0
	movs r0, 0x2
	negs r0, r0
	str r0, [r2]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x48
	adds r1, r5
	ldrb r1, [r1]
	bl sub_81D28C8
	ldr r1, [r4]
	ldr r2, =0x00000111
	adds r1, r2
	strb r0, [r1]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161280

	thumb_func_start sub_816137C
sub_816137C: @ 816137C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BC38
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08161394
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081613CC
_08161394:
	movs r5, 0
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203BC34
	movs r2, 0x4
_0816139C:
	ldr r0, [r3]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xF
	bls _0816139C
	b _081614FE
	.pool
_081613CC:
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	lsls r4, 3
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x1]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
	mov r8, r4
	cmp r6, 0xFF
	bne _081613EE
	movs r6, 0
_081613EE:
	movs r5, 0
	ldr r7, =gUnknown_0203BC34
	ldr r4, =gSprites
_081613F4:
	cmp r5, r6
	bcs _08161420
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartSpriteAnim
	b _08161436
	.pool
_08161420:
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0
	bl StartSpriteAnim
_08161436:
	ldr r0, [r7]
	adds r0, 0x1
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _081613F4
	ldr r1, =gContestEffects
	ldr r0, =gContestMoves
	add r0, r8
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xFF
	bne _0816147C
	movs r6, 0
_0816147C:
	movs r5, 0
	ldr r0, =gUnknown_0203BC34
	mov r8, r0
	ldr r7, =gSprites
_08161484:
	cmp r5, r6
	bcs _081614B8
	mov r1, r8
	ldr r0, [r1]
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x3
	bl StartSpriteAnim
	b _081614D4
	.pool
_081614B8:
	mov r3, r8
	ldr r0, [r3]
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x2
	bl StartSpriteAnim
_081614D4:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _08161484
_081614FE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816137C

	thumb_func_start hm_prepare_dive_probably
hm_prepare_dive_probably: @ 8161508
	push {r4-r6,lr}
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0x64
	muls r0, r6
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r4, r0
	bhi _08161558
	movs r0, 0
	b _0816155A
	.pool
_08161558:
	movs r0, 0x1
_0816155A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end hm_prepare_dive_probably

	thumb_func_start sub_8161560
sub_8161560: @ 8161560
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0xA
	strb r1, [r0, 0xB]
	ldrb r1, [r0, 0x9]
	strb r1, [r0, 0xA]
	bl brm_get_pokemon_selection
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81B0FCC
	movs r0, 0x5
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161560

	thumb_func_start sub_81615A8
sub_81615A8: @ 81615A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	str r4, [sp, 0x4]
	ldr r1, =gUnknown_0203CEC8
	ldrb r7, [r1, 0x9]
	mov r8, r7
	ldrb r0, [r1, 0xA]
	adds r5, r0, 0
	cmp r5, 0x6
	bls _081615EC
	movs r0, 0
	strb r0, [r1, 0xB]
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
	b _08161658
	.pool
_081615EC:
	movs r0, 0x64
	mov r10, r0
	mov r0, r10
	muls r0, r5
	ldr r1, =gPlayerParty
	mov r9, r1
	adds r6, r0, r1
	adds r0, r6, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _0816161A
	cmp r7, r5
	beq _0816161A
	adds r0, r6, 0
	movs r1, 0x3A
	bl GetMonData
	cmp r0, r4
	bne _08161628
_0816161A:
	ldr r0, [sp, 0x4]
	bl sub_81617B8
	b _08161658
	.pool
_08161628:
	movs r0, 0x1
	bl PlaySE
	mov r1, r10
	mov r0, r8
	muls r0, r1
	add r0, r9
	movs r1, 0x3A
	bl GetMonData
	movs r1, 0x5
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 16
	asrs r3, 16
	movs r2, 0x1
	negs r2, r2
	ldr r0, =sub_816166C
	str r0, [sp]
	ldr r0, [sp, 0x4]
	mov r1, r8
	bl sub_81B1F18
_08161658:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81615A8

	thumb_func_start sub_816166C
sub_816166C: @ 816166C
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl PlaySE
	ldr r5, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r5, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	movs r1, 0x5
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 16
	asrs r3, 16
	ldrb r1, [r5, 0xA]
	ldr r0, =sub_81616C0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_81B1F18
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816166C

	thumb_func_start sub_81616C0
sub_81616C0: @ 81616C0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0xA
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085E9C17
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8161724
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81616C0

	thumb_func_start sub_8161724
sub_8161724: @ 8161724
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08161772
	ldr r4, =gUnknown_0203CEC8
	movs r0, 0
	strb r0, [r4, 0xB]
	ldrb r0, [r4, 0x9]
	movs r1, 0
	bl sub_81B0FCC
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	ldrb r0, [r4, 0xA]
	movs r1, 0x1
	bl sub_81B0FCC
	movs r0, 0x6
	movs r1, 0
	bl sub_8198070
	movs r0, 0x6
	bl ClearWindowTilemap
	movs r0, 0
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
_08161772:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161724

	thumb_func_start sub_8161784
sub_8161784: @ 8161784
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081617AA
	movs r0, 0x5
	bl display_pokemon_menu_message
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B1370
	str r0, [r1]
_081617AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161784

	thumb_func_start sub_81617B8
sub_81617B8: @ 81617B8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_085E9712
	movs r1, 0
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8161784
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81617B8


	.align 2, 0 @ Don't pad with nop.
