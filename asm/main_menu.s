	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start task_new_game_prof_birch_speech_5
task_new_game_prof_birch_speech_5: @ 8030A2C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne _08030A58
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8A1F
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_6
	str r1, [r0]
_08030A58:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_5

	thumb_func_start sub_8030A70
sub_8030A70: @ 8030A70
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gTasks
	ldr r0, =gUnknown_03000DD0
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldrb r0, [r0, 0x1A]
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	movs r5, 0
	movs r1, 0x64
	strh r1, [r2, 0x20]
	movs r1, 0x4B
	strh r1, [r2, 0x22]
	movs r1, 0x3E
	adds r1, r2
	mov r12, r1
	ldrb r3, [r1]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	mov r3, r12
	strb r1, [r3]
	strh r5, [r2, 0x2E]
	ldrb r1, [r2, 0x5]
	lsrs r1, 4
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x20
	str r2, [sp, 0x8]
	ldr r2, =0x0000ffff
	str r2, [sp, 0xC]
	ldr r2, =0x00000127
	str r2, [sp, 0x10]
	movs r2, 0x70
	movs r3, 0x3A
	bl CreatePokeballSpriteToReleaseMon
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r6
	ldr r1, =sub_8030B14
	str r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r5, [r0, 0x16]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030A70

	thumb_func_start sub_8030B14
sub_8030B14: @ 8030B14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	subs r1, 0x8
	mov r8, r1
	ldr r2, =gUnknown_03000DD0
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	mov r1, r8
	adds r6, r0, r1
	movs r0, 0x1A
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r7, r2, 0
	cmp r0, 0
	beq _08030B64
	cmp r0, 0x1
	beq _08030B7C
	b _08030B98
	.pool
_08030B64:
	ldr r1, [r3, 0x1C]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	bne _08030BBA
	ldrb r1, [r3, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x1]
	b _08030B98
	.pool
_08030B7C:
	movs r1, 0x16
	ldrsh r0, [r6, r1]
	cmp r0, 0x5F
	ble _08030BBA
	adds r0, r4, 0
	bl DestroyTask
	ldrb r1, [r7]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	mov r1, r8
	adds r2, r0, r1
	b _08030BAA
_08030B98:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	ldr r2, =gTasks
	ldrb r1, [r7]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, r0, r2
_08030BAA:
	ldrh r3, [r2, 0x16]
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	ldr r0, =0x00003fff
	cmp r1, r0
	bgt _08030BBA
	adds r0, r3, 0x1
	strh r0, [r2, 0x16]
_08030BBA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030B14

	thumb_func_start task_new_game_prof_birch_speech_6
task_new_game_prof_birch_speech_6: @ 8030BCC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08030BFE
	ldr r0, =gUnknown_02022D04
	strb r1, [r0]
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8BD0
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_7
	str r1, [r0]
_08030BFE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_6

	thumb_func_start task_new_game_prof_birch_speech_7
task_new_game_prof_birch_speech_7: @ 8030C18
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne _08030C7C
	ldr r5, =gSprites
	ldr r0, =gTasks
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r3, [r1, 0x1]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r1, 0x1]
	movs r0, 0x1A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	ands r2, r1
	orrs r2, r3
	strb r2, [r0, 0x1]
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8031ACC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8031C88
	movs r0, 0x40
	strh r0, [r4, 0x16]
	ldr r0, =task_new_game_prof_birch_speech_8
	str r0, [r4]
_08030C7C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_7

	thumb_func_start task_new_game_prof_birch_speech_8
task_new_game_prof_birch_speech_8: @ 8030C90
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	ldrh r3, [r2, 0x10]
	movs r0, 0x10
	ldrsh r1, [r2, r0]
	movs r0, 0x3C
	negs r0, r0
	cmp r1, r0
	beq _08030CC0
	subs r0, r3, 0x2
	strh r0, [r2, 0x10]
	ldrh r1, [r2, 0x10]
	movs r0, 0x14
	bl SetGpuReg
	b _08030CC8
	.pool
_08030CC0:
	ldr r0, =0x0000ffc4
	strh r0, [r2, 0x10]
	ldr r0, =task_new_game_prof_birch_speech_9
	str r0, [r2]
_08030CC8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_8

	thumb_func_start task_new_game_prof_birch_speech_9
task_new_game_prof_birch_speech_9: @ 8030CD4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08030D7A
	ldr r2, =gSprites
	movs r0, 0x18
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r7, 0x4
	orrs r1, r7
	strb r1, [r0]
	movs r0, 0x1A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r7
	strb r1, [r0]
	ldrh r0, [r4, 0x16]
	movs r1, 0x16
	ldrsh r6, [r4, r1]
	cmp r6, 0
	beq _08030D34
	subs r0, 0x1
	strh r0, [r4, 0x16]
	b _08030D7A
	.pool
_08030D34:
	ldrb r3, [r4, 0x1C]
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	movs r0, 0xB4
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	movs r2, 0x3E
	adds r2, r1
	mov r12, r2
	ldrb r2, [r2]
	subs r0, 0x41
	ands r0, r2
	mov r2, r12
	strb r0, [r2]
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r7
	strb r0, [r1, 0x1]
	strh r3, [r4, 0xC]
	strh r6, [r4, 0x14]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_8031BAC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8031D34
	ldr r0, =task_new_game_prof_birch_speech_10
	str r0, [r4]
_08030D7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_9

	thumb_func_start task_new_game_prof_birch_speech_10
task_new_game_prof_birch_speech_10: @ 8030D84
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _08030DB8
	ldr r2, =gSprites
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, =task_new_game_prof_birch_speech_11
	str r0, [r3]
_08030DB8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_10

	thumb_func_start task_new_game_prof_birch_speech_11
task_new_game_prof_birch_speech_11: @ 8030DC8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_8032318
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8BDD
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_12
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_11

	thumb_func_start task_new_game_prof_birch_speech_12
task_new_game_prof_birch_speech_12: @ 8030E08
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne _08030E2A
	bl sub_8031D74
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_new_game_prof_birch_speech_13
	str r0, [r1]
_08030E2A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_12

	thumb_func_start task_new_game_prof_birch_speech_13
task_new_game_prof_birch_speech_13: @ 8030E38
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8031DB4
	lsls r0, 24
	asrs r4, r0, 24
	cmp r4, 0
	beq _08030E52
	cmp r4, 0x1
	beq _08030E52
	lsls r4, r5, 2
	b _08030E76
_08030E52:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	strb r4, [r0, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	bl sub_80322E0
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_14
	str r1, [r0]
	adds r4, r2, 0
_08030E76:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gTasks
	adds r0, r4, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r3, r0
	beq _08030EB8
	strh r3, [r4, 0x14]
	ldr r2, =gSprites
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x1]
	adds r0, r5, 0
	movs r1, 0
	bl sub_8031ACC
	ldr r0, =sub_8030ED4
	str r0, [r4]
_08030EB8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_13

	thumb_func_start sub_8030ED4
sub_8030ED4: @ 8030ED4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	ldrb r5, [r4, 0xC]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0
	bne _08030F0C
	ldr r0, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x4
	strh r0, [r1, 0x20]
	b _08030F72
	.pool
_08030F0C:
	ldr r3, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08030F30
	ldrb r5, [r4, 0x1E]
	b _08030F32
	.pool
_08030F30:
	ldrb r5, [r4, 0x1C]
_08030F32:
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	adds r2, r3
	movs r0, 0xF0
	strh r0, [r2, 0x20]
	movs r0, 0x3C
	strh r0, [r2, 0x22]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	subs r0, 0x41
	ands r0, r1
	strb r0, [r3]
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r7
	strh r5, [r4, 0xC]
	ldrb r1, [r2, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x1]
	adds r0, r6, 0
	movs r1, 0
	bl sub_8031BAC
	ldr r0, =sub_8030F7C
	str r0, [r4]
_08030F72:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030ED4

	thumb_func_start sub_8030F7C
sub_8030F7C: @ 8030F7C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	ldrb r1, [r3, 0xC]
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	ldrh r1, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, 0xB4
	ble _08030FB0
	subs r0, r1, 0x4
	strh r0, [r2, 0x20]
	b _08030FCA
	.pool
_08030FB0:
	movs r0, 0xB4
	strh r0, [r2, 0x20]
	movs r1, 0x12
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _08030FCA
	ldrb r0, [r2, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r0
	strb r1, [r2, 0x1]
	ldr r0, =task_new_game_prof_birch_speech_13
	str r0, [r3]
_08030FCA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8030F7C

	thumb_func_start task_new_game_prof_birch_speech_14
task_new_game_prof_birch_speech_14: @ 8030FD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_8032318
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8BFF
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_15
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_14

	thumb_func_start task_new_game_prof_birch_speech_15
task_new_game_prof_birch_speech_15: @ 8031014
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne _08031032
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_new_game_prof_birch_speech_16
	str r0, [r1]
_08031032:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_15

	thumb_func_start task_new_game_prof_birch_speech_16
task_new_game_prof_birch_speech_16: @ 8031040
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0803105C
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803107A
_0803105C:
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
	ldr r1, =task_new_game_prof_birch_speech_17
	str r1, [r0]
_0803107A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_16

	thumb_func_start task_new_game_prof_birch_speech_17
task_new_game_prof_birch_speech_17: @ 8031090
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _080310EC
	bl FreeAllWindowBuffers
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x1A]
	bl sub_818D820
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	bl set_default_player_name
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r2, [r1, 0x8]
	str r5, [sp]
	ldr r0, =new_game_prof_birch_speech_part2_start
	str r0, [sp, 0x4]
	movs r0, 0
	movs r3, 0
	bl DoNamingScreen
_080310EC:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_17

	thumb_func_start task_new_game_prof_birch_speech_part2_2
task_new_game_prof_birch_speech_part2_2: @ 8031104
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_8032318
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8C1C
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_part2_3
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_2

	thumb_func_start task_new_game_prof_birch_speech_part2_3
task_new_game_prof_birch_speech_part2_3: @ 8031144
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne _08031178
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0xF3
	movs r3, 0xDF
	bl sub_80323CC
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =task_new_game_prof_birch_speech_part2_4
	str r1, [r0]
_08031178:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_3

	thumb_func_start task_new_game_prof_birch_speech_part2_4
task_new_game_prof_birch_speech_part2_4: @ 8031188
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _080311AE
	cmp r1, 0
	bgt _080311A8
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080311FC
	b _08031210
_080311A8:
	cmp r1, 0x1
	beq _080311FC
	b _08031210
_080311AE:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSprites
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x1]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_8031ACC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8031C88
	ldr r0, =task_new_game_prof_birch_speech_part2_5
	str r0, [r4]
	b _08031210
	.pool
_080311FC:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_new_game_prof_birch_speech_11
	str r0, [r1]
_08031210:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_4

	thumb_func_start task_new_game_prof_birch_speech_part2_5
task_new_game_prof_birch_speech_part2_5: @ 8031220
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0x10]
	movs r3, 0x10
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0803124C
	adds r0, r2, 0x2
	strh r0, [r1, 0x10]
	ldrh r1, [r1, 0x10]
	movs r0, 0x14
	bl SetGpuReg
	b _08031250
	.pool
_0803124C:
	ldr r0, =task_new_game_prof_birch_speech_part2_6
	str r0, [r1]
_08031250:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_5

	thumb_func_start task_new_game_prof_birch_speech_part2_6
task_new_game_prof_birch_speech_part2_6: @ 8031258
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _08031320
	ldr r5, =gSprites
	movs r2, 0x1C
	ldrsh r1, [r7, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	mov r12, r3
	mov r2, r12
	orrs r1, r2
	strb r1, [r0]
	movs r3, 0x1E
	ldrsh r1, [r7, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r7, 0x18]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r0, 0x88
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r4, 0x5
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r3]
	ldrb r3, [r1, 0x1]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	mov r3, r12
	orrs r0, r3
	strb r0, [r1, 0x1]
	ldrb r1, [r7, 0x1A]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x64
	strh r1, [r0, 0x20]
	movs r1, 0x4B
	strh r1, [r0, 0x22]
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	ands r4, r1
	strb r4, [r3]
	ldrb r1, [r0, 0x1]
	ands r2, r1
	mov r1, r12
	orrs r2, r1
	strb r2, [r0, 0x1]
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8031BAC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8031D34
	movs r0, 0
	bl sub_8032318
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8C2A
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r0, =task_new_game_prof_birch_speech_part2_7
	str r0, [r7]
_08031320:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_6

	thumb_func_start task_new_game_prof_birch_speech_part2_7
task_new_game_prof_birch_speech_part2_7: @ 803133C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080313D2
	ldr r7, =gSprites
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	movs r6, 0xD
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	bl sub_8197224
	lsls r0, 16
	cmp r0, 0
	bne _080313D2
	movs r0, 0x18
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r2, [r0, 0x1]
	adds r1, r6, 0
	ands r1, r2
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r0, 0x1]
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x1]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_8031ACC
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8031C88
	movs r0, 0x40
	strh r0, [r4, 0x16]
	ldr r0, =task_new_game_prof_birch_speech_part2_8
	str r0, [r4]
_080313D2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_7

	thumb_func_start task_new_game_prof_birch_speech_part2_8
task_new_game_prof_birch_speech_part2_8: @ 80313E4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	adds r7, r1, 0
	cmp r0, 0
	beq _080314B0
	ldr r2, =gSprites
	movs r3, 0x18
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r0]
	movs r0, 0x1A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	ldrh r1, [r4, 0x16]
	movs r3, 0x16
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08031444
	subs r0, r1, 0x1
	strh r0, [r4, 0x16]
	b _080314B0
	.pool
_08031444:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _08031458
	ldrb r5, [r4, 0x1E]
	b _0803145A
	.pool
_08031458:
	ldrb r5, [r4, 0x1C]
_0803145A:
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r2
	movs r0, 0x78
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	subs r0, 0x41
	ands r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x1]
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r7
	strh r5, [r4, 0xC]
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_8031BAC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8031D34
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_082C8C7A
	bl StringExpandPlaceholders
	movs r0, 0x1
	bl AddTextPrinterForMessage
	ldr r0, =task_new_game_prof_birch_speech_part2_9
	str r0, [r4]
_080314B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_8

	thumb_func_start task_new_game_prof_birch_speech_part2_9
task_new_game_prof_birch_speech_part2_9: @ 80314C4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	movs r1, 0x12
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0803155C
	ldr r7, =gSprites
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	bl sub_8197224
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	bne _0803155C
	ldrb r0, [r6, 0xC]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r5, r4, r7
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r5, 0x1]
	adds r0, r7, 0
	adds r0, 0x10
	adds r0, r4, r0
	ldr r1, =gUnknown_082FF114
	str r1, [r0]
	adds r0, r5, 0
	bl InitSpriteAffineAnim
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r0, r7, 0
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_80318D8
	str r0, [r4]
	ldr r0, =0x0000ffff
	mov r1, r8
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	movs r0, 0x4
	bl FadeOutBGM
	ldr r0, =task_new_game_prof_birch_speech_part2_10
	str r0, [r6]
_0803155C:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_9

	thumb_func_start task_new_game_prof_birch_speech_part2_10
task_new_game_prof_birch_speech_part2_10: @ 8031580
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r3, r1, r2
	ldrb r1, [r3, 0xC]
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080315AA
	ldr r0, =task_new_game_prof_birch_speech_part2_11
	str r0, [r3]
_080315AA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_10

	thumb_func_start task_new_game_prof_birch_speech_part2_11
task_new_game_prof_birch_speech_part2_11: @ 80315BC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0803160A
	ldr r0, =gTasks
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 3
	adds r4, r0
	ldrb r2, [r4, 0xC]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =nullsub_11
	str r1, [r0]
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r0, =0xffff0000
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =task_new_game_prof_birch_speech_part2_12
	str r0, [r4]
_0803160A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_11

	thumb_func_start task_new_game_prof_birch_speech_part2_12
task_new_game_prof_birch_speech_part2_12: @ 8031630
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08031666
	bl FreeAllWindowBuffers
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x1A]
	bl sub_818D820
	bl dp13_810BB8C
	ldr r0, =CB2_NewGame
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08031666:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_12

	thumb_func_start new_game_prof_birch_speech_part2_start
new_game_prof_birch_speech_part2_start: @ 8031678
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gUnknown_082FF0E8
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_082FF0F0
	bl InitBgFromTemplate
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	add r0, sp, 0x4
	movs r4, 0
	strh r4, [r0]
	ldr r1, =0x040000d4
	str r0, [r1]
	movs r4, 0xC0
	lsls r4, 19
	str r4, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0
	str r2, [sp, 0x8]
	add r0, sp, 0x8
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add r0, sp, 0x4
	strh r2, [r0]
	str r0, [r1]
	movs r0, 0xA0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x81000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl ResetPaletteFade
	ldr r0, =gBirchIntroShadowGfx
	adds r1, r4, 0
	bl LZ77UnCompVram
	ldr r0, =gUnknown_082FEEF0
	ldr r1, =0x06003800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_082FECFC
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	ldr r0, =gUnknown_082FF018+2
	movs r1, 0x1
	movs r2, 0x10
	bl LoadPalette
	bl ResetTasks
	ldr r0, =task_new_game_prof_birch_speech_part2_1
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x5
	strh r0, [r4, 0x16]
	ldr r0, =0x0000ffc4
	strh r0, [r4, 0x10]
	bl ScanlineEffect_Stop
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl dp13_810BB8C
	adds r0, r5, 0
	bl AddBirchSpeechObjects
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	beq _080317DC
	movs r0, 0x1
	strh r0, [r4, 0x14]
	ldrb r3, [r4, 0x1E]
	b _080317E0
	.pool
_080317DC:
	strh r0, [r4, 0x14]
	ldrb r3, [r4, 0x1C]
_080317E0:
	ldr r0, =gSprites
	lsls r1, r3, 4
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	movs r4, 0
	movs r0, 0xB4
	strh r0, [r1, 0x20]
	movs r0, 0x3C
	strh r0, [r1, 0x22]
	adds r1, 0x3E
	ldrb r2, [r1]
	subs r0, 0x41
	ands r0, r2
	strb r0, [r1]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r3, [r0, 0xC]
	ldr r1, =0x0000ffc4
	movs r0, 0x14
	bl SetGpuReg
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	ldr r3, =0x04000208
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, =0x04000200
	ldrh r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	ldr r0, =VBlankCB_MainMenu
	bl SetVBlankCallback
	ldr r0, =CB2_MainMenu
	bl SetMainCallback2
	ldr r0, =gUnknown_082FF080
	bl InitWindows
	movs r0, 0
	movs r1, 0xF3
	bl LoadMainMenuWindowFrameTiles
	movs r0, 0
	movs r1, 0xFC
	movs r2, 0xF0
	bl copy_textbox_border_tile_patterns_to_vram
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end new_game_prof_birch_speech_part2_start

	thumb_func_start nullsub_11
nullsub_11: @ 80318D4
	bx lr
	thumb_func_end nullsub_11

	thumb_func_start sub_80318D8
sub_80318D8: @ 80318D8
	movs r2, 0x22
	ldrsh r1, [r0, r2]
	lsls r1, 16
	movs r3, 0x2E
	ldrsh r2, [r0, r3]
	adds r1, r2
	movs r2, 0xC0
	lsls r2, 8
	adds r1, r2
	lsrs r2, r1, 16
	strh r2, [r0, 0x22]
	strh r1, [r0, 0x2E]
	bx lr
	thumb_func_end sub_80318D8

	thumb_func_start sub_80318F4
sub_80318F4: @ 80318F4
	push {lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =0x00000127
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r0, 0xE
	str r0, [sp, 0x8]
	ldr r0, =0x0000ffff
	str r0, [sp, 0xC]
	adds r0, r2, 0
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_818D3E4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x10
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80318F4

	thumb_func_start AddBirchSpeechObjects
@ void AddBirchSpeechObjects(u8 taskId)
AddBirchSpeechObjects: @ 803192C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x88
	movs r1, 0x3C
	movs r2, 0x1
	bl AddNewGameBirchObject
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	mov r9, r1
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	movs r3, 0x1C
	add r3, r9
	mov r8, r3
	adds r1, r2, r3
	ldr r7, =nullsub_11
	str r7, [r1]
	add r2, r9
	ldrb r3, [r2, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x4
	mov r10, r3
	mov r3, r10
	orrs r1, r3
	strb r1, [r2]
	ldr r1, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r1
	strh r0, [r5, 0x18]
	movs r0, 0x64
	movs r1, 0x4B
	bl sub_80318F4
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	mov r4, r8
	adds r1, r2, r4
	str r7, [r1]
	add r2, r9
	ldrb r3, [r2, 0x5]
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	mov r3, r10
	orrs r1, r3
	strb r1, [r2]
	strh r0, [r5, 0x1A]
	movs r0, 0x3C
	bl sub_806EFF0
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =0x0201c000
	str r4, [sp]
	movs r1, 0x78
	movs r2, 0x3C
	movs r3, 0
	bl CreateTrainerSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	mov r3, r8
	adds r1, r2, r3
	str r7, [r1]
	add r2, r9
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	mov r4, r10
	orrs r1, r4
	strb r1, [r3]
	ldrb r3, [r2, 0x5]
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x5]
	strh r0, [r5, 0x1C]
	movs r0, 0x3F
	bl sub_806EFF0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x0201c000
	movs r2, 0x80
	lsls r2, 4
	adds r4, r1, r2
	str r4, [sp]
	movs r1, 0x78
	movs r2, 0x3C
	movs r3, 0
	bl CreateTrainerSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r8, r2
	mov r3, r8
	str r7, [r3]
	add r2, r9
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	mov r4, r10
	orrs r1, r4
	strb r1, [r3]
	ldrb r1, [r2, 0x5]
	ands r6, r1
	strb r6, [r2, 0x5]
	strh r0, [r5, 0x1E]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddBirchSpeechObjects

	thumb_func_start sub_8031A5C
sub_8031A5C: @ 8031A5C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r2, r0, r4
	ldrh r1, [r2, 0xA]
	movs r5, 0xA
	ldrsh r0, [r2, r5]
	cmp r0, 0
	bne _08031A94
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x1
	strh r0, [r1, 0x12]
	adds r0, r3, 0
	bl DestroyTask
	b _08031AC4
	.pool
_08031A94:
	ldrh r3, [r2, 0x10]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	cmp r0, 0
	beq _08031AA4
	subs r0, r3, 0x1
	strh r0, [r2, 0x10]
	b _08031AC4
_08031AA4:
	ldrh r0, [r2, 0xE]
	strh r0, [r2, 0x10]
	subs r1, 0x1
	strh r1, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	lsls r0, 8
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_08031AC4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8031A5C

	thumb_func_start sub_8031ACC
sub_8031ACC: @ 8031ACC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x94
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gTasks
	mov r8, r0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r6, 0
	strh r6, [r0, 0x12]
	ldr r0, =sub_8031A5C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	add r1, r8
	strh r4, [r1, 0x8]
	movs r0, 0x10
	strh r0, [r1, 0xA]
	strh r6, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031ACC

	thumb_func_start sub_8031B3C
sub_8031B3C: @ 8031B3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r2, r0, r4
	ldrh r1, [r2, 0xA]
	movs r5, 0xA
	ldrsh r0, [r2, r5]
	cmp r0, 0x10
	bne _08031B74
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x1
	strh r0, [r1, 0x12]
	adds r0, r3, 0
	bl DestroyTask
	b _08031BA4
	.pool
_08031B74:
	ldrh r3, [r2, 0x10]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	cmp r0, 0
	beq _08031B84
	subs r0, r3, 0x1
	strh r0, [r2, 0x10]
	b _08031BA4
_08031B84:
	ldrh r0, [r2, 0xE]
	strh r0, [r2, 0x10]
	adds r1, 0x1
	strh r1, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	subs r0, 0x1
	strh r0, [r2, 0xC]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	lsls r0, 8
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_08031BA4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8031B3C

	thumb_func_start sub_8031BAC
sub_8031BAC: @ 8031BAC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x94
	lsls r1, 2
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gTasks
	mov r8, r0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	add r0, r8
	movs r6, 0
	strh r6, [r0, 0x12]
	ldr r0, =sub_8031B3C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	add r1, r8
	strh r4, [r1, 0x8]
	strh r6, [r1, 0xA]
	movs r0, 0x10
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031BAC

	thumb_func_start sub_8031C1C
sub_8031C1C: @ 8031C1C
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	ldrh r3, [r1, 0xC]
	movs r4, 0xC
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08031C40
	subs r0, r3, 0x1
	strh r0, [r1, 0xC]
	b _08031C7C
	.pool
_08031C40:
	ldrh r3, [r1, 0xA]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r0, 0x8
	bne _08031C52
	adds r0, r2, 0
	bl DestroyTask
	b _08031C7C
_08031C52:
	ldrh r2, [r1, 0x10]
	movs r4, 0x10
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08031C62
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	b _08031C7C
_08031C62:
	ldrh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	adds r0, r3, 0x1
	strh r0, [r1, 0xA]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	lsls r0, 1
	ldr r1, =gUnknown_082FF018
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x10
	bl LoadPalette
_08031C7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031C1C

	thumb_func_start sub_8031C88
sub_8031C88: @ 8031C88
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sub_8031C1C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r4, [r1, 0x8]
	strh r0, [r1, 0xA]
	movs r0, 0x8
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031C88

	thumb_func_start sub_8031CC8
sub_8031CC8: @ 8031CC8
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	ldrh r3, [r1, 0xC]
	movs r4, 0xC
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08031CEC
	subs r0, r3, 0x1
	strh r0, [r1, 0xC]
	b _08031D28
	.pool
_08031CEC:
	ldrh r3, [r1, 0xA]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _08031CFE
	adds r0, r2, 0
	bl DestroyTask
	b _08031D28
_08031CFE:
	ldrh r2, [r1, 0x10]
	movs r4, 0x10
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08031D0E
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	b _08031D28
_08031D0E:
	ldrh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	subs r0, r3, 0x1
	strh r0, [r1, 0xA]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	lsls r0, 1
	ldr r1, =gUnknown_082FF018
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x10
	bl LoadPalette
_08031D28:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031CC8

	thumb_func_start sub_8031D34
sub_8031D34: @ 8031D34
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sub_8031CC8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	movs r0, 0x8
	strh r0, [r1, 0xA]
	strh r0, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r5, [r1, 0x10]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031D34

	thumb_func_start sub_8031D74
sub_8031D74: @ 8031D74
	push {lr}
	ldr r0, =gUnknown_082FF088
	movs r1, 0xF3
	bl DrawMainMenuWindowBorder
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gUnknown_082FF118
	movs r0, 0x1
	movs r1, 0x2
	bl PrintMenuTable
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8031D74

	thumb_func_start sub_8031DB4
sub_8031DB4: @ 8031DB4
	push {lr}
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8031DB4

	thumb_func_start set_default_player_name
@ void set_default_player_name(int name_id)
set_default_player_name: @ 8031DC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gSaveBlock2Ptr
	ldr r0, [r1]
	ldrb r0, [r0, 0x8]
	adds r5, r1, 0
	cmp r0, 0
	bne _08031DE4
	ldr r1, =gMalePresetNames
	b _08031DE6
	.pool
_08031DE4:
	ldr r1, =gFemalePresetNames
_08031DE6:
	lsls r0, r2, 2
	adds r0, r1
	ldr r3, [r0]
	movs r2, 0
	ldr r4, =gSaveBlock2Ptr
_08031DF0:
	ldr r1, [r4]
	adds r1, r2
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x6
	bls _08031DF0
	ldr r1, [r5]
	movs r0, 0xFF
	strb r0, [r1, 0x7]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_default_player_name

	thumb_func_start CreateMainMenuErrorWindow
@ void CreateMainMenuErrorWindow(u8 *str)
CreateMainMenuErrorWindow: @ 8031E18
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0x7
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x7
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0x7
	bl PutWindowTilemap
	movs r0, 0x7
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, =gUnknown_082FF070
	ldr r1, =0x000001d5
	bl DrawMainMenuWindowBorder
	ldr r1, =0x000009e7
	movs r0, 0x40
	bl SetGpuReg
	ldr r1, =0x0000719f
	movs r0, 0x44
	bl SetGpuReg
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateMainMenuErrorWindow

	thumb_func_start fmt_savegame
fmt_savegame: @ 8031E7C
	push {lr}
	bl fmt_time
	bl fmt_pokedex
	bl fmt_player
	bl fmt_badges
	pop {r0}
	bx r0
	thumb_func_end fmt_savegame

	thumb_func_start fmt_time
fmt_time: @ 8031E94
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r4, =gStringVar4
	ldr r1, =gText_ContinueMenuPlayer
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x11
	bl box_print
	ldr r4, =gSaveBlock2Ptr
	ldr r1, [r4]
	movs r0, 0x1
	movs r2, 0x64
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	ldr r0, [r4]
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_time

	thumb_func_start fmt_player
fmt_player: @ 8031EF8
	push {r4-r6,lr}
	sub sp, 0x2C
	ldr r4, =gStringVar4
	ldr r1, =gText_ContinueMenuTime
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x6C
	movs r3, 0x11
	bl box_print
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldrh r1, [r0, 0xE]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r1, 0xF0
	strb r1, [r0]
	adds r0, 0x1
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0xD0
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_player

	thumb_func_start fmt_pokedex
fmt_pokedex: @ 8031F7C
	push {r4-r7,lr}
	sub sp, 0x2C
	ldr r0, =0x00000861
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08031FFE
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _08031FA4
	movs r0, 0x1
	bl pokedex_count
	b _08031FAA
	.pool
_08031FA4:
	movs r0, 0x1
	bl sub_80C0844
_08031FAA:
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r4, =gStringVar4
	ldr r1, =gText_ContinueMenuPokedex
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x21
	bl box_print
	add r0, sp, 0xC
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x64
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x21
	bl box_print
_08031FFE:
	add sp, 0x2C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_pokedex

	thumb_func_start fmt_badges
fmt_badges: @ 8032014
	push {r4-r7,lr}
	sub sp, 0x2C
	movs r7, 0
	ldr r4, =0x00000867
_0803201C:
	lsls r0, r4, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08032030
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_08032030:
	adds r4, 0x1
	ldr r0, =0x0000086e
	cmp r4, r0
	bls _0803201C
	ldr r4, =gStringVar4
	ldr r1, =gText_ContinueMenuBadges
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r6, =gUnknown_082FF0E3
	str r6, [sp]
	movs r5, 0x1
	negs r5, r5
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x6C
	movs r3, 0x21
	bl box_print
	add r0, sp, 0xC
	adds r1, r7, 0
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0xD0
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0x21
	bl box_print
	add sp, 0x2C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fmt_badges

	thumb_func_start LoadMainMenuWindowFrameTiles
@ void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset)
LoadMainMenuWindowFrameTiles: @ 80320A4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 16
	lsrs r5, 16
	ldr r6, =gSaveBlock2Ptr
	ldr r0, [r6]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl GetWindowFrameTilesPal
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	adds r0, r4, 0
	adds r3, r5, 0
	bl LoadBgTiles
	ldr r0, [r6]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl GetWindowFrameTilesPal
	ldr r0, [r0, 0x4]
	movs r1, 0x20
	movs r2, 0x20
	bl LoadPalette
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadMainMenuWindowFrameTiles

	thumb_func_start DrawMainMenuWindowBorder
@ void DrawMainMenuWindowBorder(struct WindowTemplate *template, u16 baseTileNum)
DrawMainMenuWindowBorder: @ 80320EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r4, r0, 0
	lsls r6, r1, 16
	movs r0, 0x80
	lsls r0, 9
	adds r0, r6
	lsrs r0, 16
	mov r9, r0
	movs r1, 0x80
	lsls r1, 10
	adds r1, r6
	lsrs r1, 16
	mov r10, r1
	movs r7, 0xC0
	lsls r7, 10
	adds r1, r6, r7
	lsrs r1, 16
	str r1, [sp, 0x18]
	movs r0, 0xA0
	lsls r0, 11
	adds r1, r6, r0
	lsrs r1, 16
	str r1, [sp, 0xC]
	movs r7, 0xC0
	lsls r7, 11
	adds r1, r6, r7
	lsrs r1, 16
	str r1, [sp, 0x10]
	movs r0, 0xE0
	lsls r0, 11
	adds r1, r6, r0
	lsrs r1, 16
	str r1, [sp, 0x14]
	lsrs r1, r6, 16
	movs r7, 0x80
	lsls r7, 12
	adds r6, r7
	lsrs r6, 16
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r7, 0x2
	mov r8, r7
	str r7, [sp, 0x8]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r4, 0x3]
	str r1, [sp]
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	mov r1, r9
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r1, [r4, 0x1]
	adds r2, r1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	mov r1, r10
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r1, [r4, 0x4]
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	ldr r1, [sp, 0x18]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r7, [r4, 0x1]
	adds r2, r7
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r1, [r4, 0x4]
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	ldr r1, [sp, 0xC]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r7, [r4, 0x2]
	adds r3, r7
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	ldr r1, [sp, 0x10]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x4]
	ldrb r7, [r4, 0x2]
	adds r3, r7
	lsls r3, 24
	lsrs r3, 24
	ldrb r1, [r4, 0x3]
	str r1, [sp]
	str r5, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	ldr r1, [sp, 0x14]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r7, [r4, 0x1]
	adds r2, r7
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r1, [r4, 0x2]
	adds r3, r1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	mov r7, r8
	str r7, [sp, 0x8]
	adds r1, r6, 0
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	bl CopyBgTilemapBufferToVram
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DrawMainMenuWindowBorder

	thumb_func_start sub_8032250
sub_8032250: @ 8032250
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldrb r0, [r6]
	ldrb r1, [r6, 0x1]
	subs r2, r1, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r4, [r6, 0x2]
	subs r3, r4, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r5, [r6, 0x3]
	adds r1, r5
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	ldrb r1, [r6, 0x4]
	adds r4, r1
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0
	bl FillBgTilemapBufferRect
	ldrb r0, [r6]
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8032250

	thumb_func_start sub_8032298
sub_8032298: @ 8032298
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r1, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsls r5, 24
	lsls r3, 24
	lsls r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r4, r2
	lsrs r4, 24
	adds r5, r2
	lsrs r5, 24
	movs r2, 0x80
	lsls r2, 18
	adds r3, r2
	lsrs r3, 24
	str r3, [sp]
	adds r1, r2
	lsrs r1, 24
	str r1, [sp, 0x4]
	movs r1, 0x2
	str r1, [sp, 0x8]
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8032298

	thumb_func_start sub_80322E0
sub_80322E0: @ 80322E0
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_8032298
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl ClearWindowTilemap
	cmp r4, 0x1
	bne _0803230E
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0803230E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80322E0

	thumb_func_start sub_8032318
sub_8032318: @ 8032318
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x1
	movs r1, 0x6
	bl GetFontAttribute
	mov r9, r0
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0x1
	movs r1, 0
	bl GetFontAttribute
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x1
	movs r1, 0x1
	bl GetFontAttribute
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0x3
	bl GetWindowAttribute
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0x4
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	muls r1, r4
	str r1, [sp]
	muls r0, r5
	str r0, [sp, 0x4]
	adds r0, r6, 0
	mov r1, r9
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
	adds r0, r6, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8032318

	thumb_func_start sub_80323A0
sub_80323A0: @ 80323A0
	push {lr}
	ldr r0, [r0]
	subs r0, 0x2
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _080323C0
	ldr r1, =gUnknown_02022D04
	ldrb r0, [r1]
	cmp r0, 0
	bne _080323C0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =sub_8030A70
	movs r1, 0
	bl CreateTask
_080323C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80323A0

	thumb_func_start sub_80323CC
sub_80323CC: @ 80323CC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	ldr r6, [sp, 0x34]
	ldr r1, [sp, 0x38]
	lsls r4, 24
	lsls r5, 24
	mov r0, r8
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x80
	lsls r0, 17
	adds r4, r0
	lsrs r4, 24
	adds r5, r0
	lsrs r5, 24
	movs r0, 0x5
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r3, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_8198A50
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	add r0, sp, 0x18
	mov r1, r8
	adds r2, r6, 0
	movs r3, 0
	bl CreateYesNoMenu
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80323CC

	thumb_func_start unknown_rbox_to_vram
unknown_rbox_to_vram: @ 803243C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_8032474
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _0803246A
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0803246A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unknown_rbox_to_vram

	thumb_func_start sub_8032474
sub_8032474: @ 8032474
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	adds r5, r2, 0
	mov r9, r3
	ldr r0, [sp, 0x40]
	ldr r6, [sp, 0x44]
	mov r2, r8
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r1, 24
	lsls r5, 24
	mov r2, r9
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r6, 24
	lsrs r6, 24
	lsrs r0, r1, 24
	str r0, [sp, 0xC]
	movs r2, 0xFE
	lsls r2, 24
	adds r1, r2
	lsrs r1, 24
	str r1, [sp, 0x14]
	lsrs r0, r5, 24
	mov r10, r0
	movs r2, 0xFF
	lsls r2, 24
	adds r5, r2
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0xFD
	ldr r2, [sp, 0x14]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, 0xC]
	subs r0, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0xFF
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	movs r1, 0x80
	lsls r1, 1
	mov r0, r9
	str r0, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0xC]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000101
	ldr r7, [sp, 0xC]
	add r7, r9
	subs r0, r7, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	movs r1, 0x81
	lsls r1, 1
	lsls r2, r7, 24
	lsrs r7, r2, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000103
	str r4, [sp]
	movs r5, 0x5
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000105
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	mov r3, r10
	bl FillBgTilemapBufferRect
	movs r1, 0x83
	lsls r1, 1
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x000008fd
	ldr r2, [sp, 0x10]
	add r10, r2
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x000008ff
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	mov r3, r10
	bl FillBgTilemapBufferRect
	movs r1, 0x90
	lsls r1, 4
	movs r2, 0x1
	negs r2, r2
	add r9, r2
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0xC]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000901
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x1C]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000902
	str r4, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	mov r3, r10
	bl FillBgTilemapBufferRect
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8032474

	thumb_func_start task_new_game_prof_birch_speech_part2_1
task_new_game_prof_birch_speech_part2_1: @ 803261C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x16]
	subs r1, r0, 0x1
	strh r1, [r4, 0x16]
	lsls r0, 16
	cmp r0, 0
	bgt _08032644
	movs r0, 0
	movs r1, 0x1
	bl unknown_rbox_to_vram
	ldr r0, =task_new_game_prof_birch_speech_part2_2
	str r0, [r4]
_08032644:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_new_game_prof_birch_speech_part2_1

	.align 2, 0 @ Don't pad with nop.
