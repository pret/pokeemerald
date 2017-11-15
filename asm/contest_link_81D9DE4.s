	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81D9DE4
sub_81D9DE4: @ 81D9DE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bhi _081D9EA4
	lsls r0, 2
	ldr r1, =_081D9E10
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D9E10:
	.4byte _081D9E24
	.4byte _081D9E44
	.4byte _081D9E64
	.4byte _081D9E84
	.4byte _081D9EA4
_081D9E24:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _081D9EB4
	.pool
_081D9E44:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _081D9EB4
	.pool
_081D9E64:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _081D9EB4
	.pool
_081D9E84:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _081D9EB4
	.pool
_081D9EA4:
	ldr r4, =gUnknown_02039F31
	ldr r0, =gUnknown_02039F24
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_081D9EB4:
	bl GetMonData
	strb r0, [r4]
	ldr r5, =gUnknown_02039E00
	ldr r4, =gUnknown_02039F25
	ldrb r0, [r4]
	lsls r0, 6
	adds r0, r5
	ldr r1, =gUnknown_02039F31
	ldrb r1, [r1]
	adds r0, 0x2C
	strb r1, [r0]
	ldr r0, =0x00000864
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	lsrs r0, 31
	ldrb r1, [r4]
	lsls r1, 6
	adds r1, r5
	adds r1, 0x2D
	strb r0, [r1]
	ldr r1, =sub_81DA160
	ldr r2, =sub_81D9F14
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9DE4

	thumb_func_start sub_81D9F14
sub_81D9F14: @ 81D9F14
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_81DA244
	ldr r2, =sub_81D9F30
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F14

	thumb_func_start sub_81D9F30
sub_81D9F30: @ 81D9F30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_81DA2E8
	ldr r2, =sub_81D9F4C
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F30

	thumb_func_start sub_81D9F4C
sub_81D9F4C: @ 81D9F4C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sub_81DA3B8
	ldr r2, =sub_81D9F68
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F4C

	thumb_func_start sub_81D9F68
sub_81D9F68: @ 81D9F68
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r3, 0
	ldr r5, =gUnknown_02039F30
	mov r8, r5
	ldr r0, =gSpecialVar_0x8004
	mov r12, r0
	add r1, sp, 0x4
	mov r9, r1
	ldrb r4, [r5]
	cmp r3, r4
	bcs _081D9FB2
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 3
	ldr r7, =gTasks + 0x8
_081D9F98:
	mov r0, sp
	adds r2, r0, r3
	adds r1, r3, 0x1
	lsls r0, r1, 1
	adds r0, r4
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r3, r1, 24
	ldrb r1, [r5]
	cmp r3, r1
	bcc _081D9F98
_081D9FB2:
	movs r3, 0
	mov r4, r8
	ldrb r0, [r4]
	cmp r3, r0
	bcs _081D9FD6
	adds r4, r0, 0
	mov r2, sp
_081D9FC0:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcs _081D9FD6
	mov r7, sp
	adds r1, r7, r3
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081D9FC0
_081D9FD6:
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bne _081D9FF4
	movs r0, 0
	mov r1, r12
	strh r0, [r1]
	b _081D9FFA
	.pool
_081D9FF4:
	movs r0, 0x1
	mov r4, r12
	strh r0, [r4]
_081D9FFA:
	movs r3, 0
	mov r7, r8
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bcs _081DA02A
	mov r4, r9
	lsls r0, r6, 2
	adds r0, r6
	lsls r2, r0, 3
	ldr r5, =gTasks + 0x8
_081DA010:
	adds r1, r4, r3
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r2
	adds r0, r5
	ldrh r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r7]
	cmp r3, r1
	bcc _081DA010
_081DA02A:
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, 0x4
	beq _081DA0B8
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _081DA0B8
	ldr r0, =gUnknown_02039E00
	adds r1, r0, 0
	adds r1, 0x2C
	ldrb r2, [r1]
	movs r3, 0x1
	ldrb r1, [r4]
	adds r5, r0, 0
	cmp r3, r1
	bcs _081DA06C
	adds r4, r5, 0
	mov r7, r8
	ldrb r1, [r7]
_081DA054:
	lsls r0, r3, 6
	adds r0, r4
	adds r0, 0x2C
	ldrb r7, [r0]
	cmp r2, r7
	bcs _081DA062
	ldrb r2, [r0]
_081DA062:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r1
	bcc _081DA054
_081DA06C:
	cmp r2, 0
	beq _081DA076
	subs r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_081DA076:
	movs r4, 0x1
	movs r3, 0
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bcs _081DA0AC
	adds r0, r5, 0
	b _081DA0A2
	.pool
_081DA090:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	mov r1, r8
	ldrb r1, [r1]
	cmp r3, r1
	bcs _081DA0AC
	lsls r0, r3, 6
	adds r0, r5
_081DA0A2:
	adds r0, 0x2D
	ldrb r0, [r0]
	cmp r0, 0
	bne _081DA090
	movs r4, 0
_081DA0AC:
	mov r0, sp
	ldrb r0, [r0]
	adds r1, r2, 0
	adds r2, r4, 0
	bl sub_80DACBC
_081DA0B8:
	mov r0, r9
	bl sub_80F86E0
	ldr r1, =gUnknown_02039F2B
	strb r0, [r1]
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r0, 0x3
	bhi _081DA0E8
	ldr r1, =sub_81DA488
	ldr r2, =sub_81DA10C
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	b _081DA0F6
	.pool
_081DA0E8:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81DA10C
	str r0, [r1]
_081DA0F6:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D9F68

	thumb_func_start sub_81DA10C
sub_81DA10C: @ 81DA10C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSpecialVar_ContestCategory
	ldrb r0, [r0]
	bl sub_80DB09C
	ldr r1, =sub_80FCF40
	ldr r2, =sub_81DA138
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA10C

	thumb_func_start sub_81DA138
sub_81DA138: @ 81DA138
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_80DCE58
	ldr r1, =sub_80FCFD0
	ldr r2, =sub_80F8714
	adds r0, r4, 0
	bl SetTaskFuncWithFollowupFunc
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA138

	thumb_func_start sub_81DA160
sub_81DA160: @ 81DA160
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r6, r7, 2
	adds r0, r6, r7
	lsls r4, r0, 3
	ldr r5, =gTasks + 0x8
	adds r0, r4, r5
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA224
	adds r0, r5, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA1A4
	cmp r0, 0x1
	beq _081DA1D4
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r7, 0
	bl SwitchTaskToFollowupFunc
	b _081DA224
	.pool
_081DA1A4:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA224
	ldr r0, =gUnknown_02039F25
	ldrb r0, [r0]
	lsls r0, 6
	ldr r1, =gUnknown_02039E00
	adds r0, r1
	movs r1, 0x40
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA224
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA224
	.pool
_081DA1D4:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _081DA224
	movs r5, 0
	ldr r0, =gUnknown_02039F30
	mov r8, r6
	ldrb r0, [r0]
	cmp r5, r0
	bge _081DA214
	ldr r6, =gLinkPlayers
_081DA1EC:
	lsls r4, r5, 6
	ldr r0, =gUnknown_02039E00
	adds r4, r0
	lsls r1, r5, 8
	ldr r0, =gBlockRecvBuffer
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x40
	bl memcpy
	ldrh r1, [r6, 0x1A]
	adds r0, r4, 0
	bl sub_80DFA08
	adds r6, 0x1C
	adds r5, 0x1
	ldr r0, =gUnknown_02039F30
	ldrb r0, [r0]
	cmp r5, r0
	blt _081DA1EC
_081DA214:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA224:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA160

	thumb_func_start sub_81DA244
sub_81DA244: @ 81DA244
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r5, r0, 3
	ldr r6, =gTasks + 0x8
	adds r0, r5, r6
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA2D4
	adds r0, r6, 0
	subs r0, 0x8
	adds r5, r0
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _081DA284
	cmp r0, 0x1
	beq _081DA2AC
	movs r0, 0
	strh r0, [r5, 0x8]
	strh r0, [r5, 0x20]
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
	b _081DA2D4
	.pool
_081DA284:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _081DA2CE
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA2D4
	ldr r0, =gRngValue
	movs r1, 0x4
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA2D4
	b _081DA2CE
	.pool
_081DA2AC:
	movs r0, 0
	bl sub_80FC530
	lsls r0, 24
	cmp r0, 0
	beq _081DA2D4
	ldr r0, =gRngValue
	ldr r4, =gBlockRecvBuffer
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
	ldr r0, =gUnknown_030060B8
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
_081DA2CE:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_081DA2D4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA244

	thumb_func_start sub_81DA2E8
sub_81DA2E8: @ 81DA2E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	mov r9, r0
	adds r0, r6
	lsls r5, r0, 3
	ldr r1, =gTasks + 0x8
	mov r8, r1
	adds r0, r5, r1
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA39E
	movs r0, 0x8
	negs r0, r0
	add r0, r8
	mov r10, r0
	adds r4, r5, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA338
	cmp r0, 0x1
	beq _081DA35A
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _081DA39E
	.pool
_081DA338:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA39E
	add r0, sp, 0x8
	movs r1, 0x6E
	strh r1, [r0]
	movs r1, 0x2
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA39E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA39E
_081DA35A:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _081DA39E
	movs r1, 0
	ldr r7, =gUnknown_02039F30
	ldrb r0, [r7]
	cmp r1, r0
	bge _081DA390
	mov r0, r8
	adds r0, 0xA
	adds r3, r5, r0
	ldr r4, =gBlockRecvBuffer
	mov r2, sp
	movs r5, 0x80
	lsls r5, 1
_081DA37C:
	ldrh r0, [r4]
	strh r0, [r2]
	strh r0, [r3]
	adds r3, 0x2
	adds r4, r5
	adds r2, 0x2
	adds r1, 0x1
	ldrb r0, [r7]
	cmp r1, r0
	blt _081DA37C
_081DA390:
	mov r0, r9
	adds r1, r0, r6
	lsls r1, 3
	add r1, r10
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA39E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA2E8

	thumb_func_start sub_81DA3B8
sub_81DA3B8: @ 81DA3B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	mov r9, r0
	adds r0, r6
	lsls r5, r0, 3
	ldr r1, =gTasks + 0x8
	mov r8, r1
	adds r0, r5, r1
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA46E
	movs r0, 0x8
	negs r0, r0
	add r0, r8
	mov r10, r0
	adds r4, r5, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA408
	cmp r0, 0x1
	beq _081DA42A
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _081DA46E
	.pool
_081DA408:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA46E
	ldrh r1, [r4, 0x1A]
	add r0, sp, 0x8
	strh r1, [r0]
	movs r1, 0x2
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA46E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA46E
_081DA42A:
	bl sub_80FC55C
	lsls r0, 24
	cmp r0, 0
	beq _081DA46E
	movs r1, 0
	ldr r7, =gUnknown_02039F30
	ldrb r0, [r7]
	cmp r1, r0
	bge _081DA460
	mov r0, r8
	adds r0, 0x2
	adds r3, r5, r0
	ldr r4, =gBlockRecvBuffer
	mov r2, sp
	movs r5, 0x80
	lsls r5, 1
_081DA44C:
	ldrh r0, [r4]
	strh r0, [r2]
	strh r0, [r3]
	adds r3, 0x2
	adds r4, r5
	adds r2, 0x2
	adds r1, 0x1
	ldrb r0, [r7]
	cmp r1, r0
	blt _081DA44C
_081DA460:
	mov r0, r9
	adds r1, r0, r6
	lsls r1, 3
	add r1, r10
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA46E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA3B8

	thumb_func_start sub_81DA488
sub_81DA488: @ 81DA488
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r7, r6, 2
	adds r0, r7, r6
	lsls r4, r0, 3
	ldr r5, =gTasks + 0x8
	adds r0, r4, r5
	adds r0, 0x18
	bl sub_80FC670
	cmp r0, 0
	beq _081DA55C
	adds r0, r5, 0
	subs r0, 0x8
	adds r4, r0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DA4CC
	cmp r0, 0x1
	beq _081DA50C
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x20]
	adds r0, r6, 0
	bl SwitchTaskToFollowupFunc
	b _081DA55C
	.pool
_081DA4CC:
	bl GetMultiplayerId
	lsls r0, 24
	cmp r0, 0
	bne _081DA4FA
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _081DA55C
	ldr r0, =gUnknown_02039F30
	ldrb r2, [r0]
	lsls r0, r2, 6
	ldr r1, =gUnknown_02039E00
	adds r0, r1
	movs r1, 0x4
	subs r1, r2
	lsls r1, 22
	lsrs r1, 16
	bl sub_80FC4F4
	cmp r0, 0x1
	bne _081DA55C
_081DA4FA:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DA55C
	.pool
_081DA50C:
	movs r0, 0
	bl sub_80FC530
	lsls r0, 24
	cmp r0, 0
	beq _081DA55C
	ldr r4, =gUnknown_02039F30
	ldrb r3, [r4]
	lsls r0, r3, 6
	ldr r5, =gUnknown_02039E00
	adds r0, r5
	ldr r1, =gBlockRecvBuffer
	movs r2, 0x4
	subs r2, r3
	lsls r2, 6
	bl memcpy
	ldrb r4, [r4]
	mov r8, r7
	cmp r4, 0x3
	bgt _081DA54C
	lsls r0, r4, 6
	adds r5, r0, r5
	ldr r7, =gLinkPlayers
_081DA53C:
	ldrh r1, [r7, 0x1A]
	adds r0, r5, 0
	bl sub_80DFA08
	adds r5, 0x40
	adds r4, 0x1
	cmp r4, 0x3
	ble _081DA53C
_081DA54C:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_081DA55C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA488

	.align 2, 0 @ Don't pad with nop.
