	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A3934
sub_80A3934: @ 80A3934
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gAnimFramesToWait
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gAnimScriptActive
	strb r1, [r0]
	ldr r0, =gAnimVisualTaskCount
	strb r1, [r0]
	ldr r0, =gAnimSoundTaskCount
	strb r1, [r0]
	ldr r0, =gDisableStructMoveAnim
	movs r1, 0
	str r1, [r0]
	ldr r0, =gMoveDmgMoveAnim
	str r1, [r0]
	ldr r0, =gMovePowerMoveAnim
	movs r2, 0
	strh r1, [r0]
	ldr r0, =gHappinessMoveAnim
	strb r2, [r0]
	ldr r4, =gUnknown_02038430
	ldr r5, =gUnknown_02038432
	ldr r6, =gUnknown_02038433
	ldr r7, =gAnimMoveIndex
	ldr r0, =gAnimationBankAttacker
	mov r12, r0
	ldr r1, =gAnimationBankTarget
	mov r8, r1
	ldr r0, =gUnknown_02038440
	mov r9, r0
	ldr r1, =0x0000ffff
	adds r3, r1, 0
	ldr r1, =gAnimSpriteIndexArray
	movs r2, 0x7
_080A397E:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A397E
	ldr r1, =gBattleAnimArgs
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0xE
_080A3994:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080A3994
	movs r1, 0
	movs r0, 0xFF
	strb r0, [r4]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r4, 0x1]
	strb r1, [r5]
	strb r1, [r6]
	movs r0, 0
	strh r1, [r7]
	mov r1, r12
	strb r0, [r1]
	mov r1, r8
	strb r0, [r1]
	mov r1, r9
	strb r0, [r1]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3934

	thumb_func_start move_anim_start_t1
move_anim_start_t1: @ 80A3A10
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, =gAnimationBankAttacker
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r2, =gAnimationBankTarget
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gUnknown_082C8D6C
	movs r2, 0x1
	bl move_something
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_start_t1

	thumb_func_start move_something
move_something: @ 80A3A48
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A3AE8
	bl sub_80A8278
	movs r0, 0
	bl sub_8072A88
	movs r4, 0
	mov r0, r8
	lsls r0, 2
	mov r10, r0
	ldr r6, =gBattlePartyID
	movs r7, 0x64
	ldr r5, =gUnknown_02038438
_080A3A84:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _080A3AA8
	ldrh r0, [r6]
	muls r0, r7
	ldr r1, =gEnemyParty
	b _080A3AAE
	.pool
_080A3AA8:
	ldrh r0, [r6]
	muls r0, r7
	ldr r1, =gPlayerParty
_080A3AAE:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	strh r0, [r5]
	adds r6, 0x2
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _080A3A84
	ldr r3, =gAnimMoveIndex
	ldr r5, =gUnknown_02038430
	ldr r1, =gAnimScriptActive
	mov r12, r1
	ldr r7, =gAnimScriptCallback
	ldr r6, =move_anim_execute
	b _080A3B10
	.pool
_080A3AE8:
	ldr r3, =gAnimMoveIndex
	ldr r5, =gUnknown_02038430
	mov r0, r8
	lsls r0, 2
	mov r10, r0
	ldr r1, =gAnimScriptActive
	mov r12, r1
	ldr r7, =gAnimScriptCallback
	ldr r6, =move_anim_execute
	ldr r2, =gUnknown_02039F34
	ldr r1, =gUnknown_02038438
	movs r4, 0x3
_080A3B00:
	ldr r0, [r2]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _080A3B00
_080A3B10:
	mov r0, r9
	cmp r0, 0
	bne _080A3B38
	strh r0, [r3]
	b _080A3B3C
	.pool
_080A3B38:
	mov r1, r8
	strh r1, [r3]
_080A3B3C:
	ldr r1, =gBattleAnimArgs
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0xE
_080A3B44:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080A3B44
	movs r0, 0xFF
	strb r0, [r5]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r5, 0x1]
	ldr r0, [sp]
	add r0, r10
	ldr r0, [r0]
	ldr r1, =gBattleAnimScriptPtr
	str r0, [r1]
	movs r0, 0x1
	mov r1, r12
	strb r0, [r1]
	movs r0, 0
	ldr r1, =gAnimFramesToWait
	strb r0, [r1]
	str r6, [r7]
	ldr r0, =0x0000ffff
	adds r2, r0, 0
	ldr r1, =gAnimSpriteIndexArray
	movs r4, 0x7
_080A3B76:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _080A3B76
	mov r1, r9
	cmp r1, 0
	beq _080A3BC2
	movs r4, 0
	ldr r2, =gUnknown_082C8D64
	b _080A3BAA
	.pool
_080A3BA8:
	adds r4, 0x1
_080A3BAA:
	lsls r0, r4, 1
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _080A3BC2
	cmp r8, r0
	bne _080A3BA8
	ldr r0, =gMPlay_BGM
	movs r2, 0x80
	bl m4aMPlayVolumeControl
_080A3BC2:
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r0, =gUnknown_02022E28
	strh r1, [r0]
	ldr r0, =gUnknown_02022E2A
	strh r1, [r0]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_something

	thumb_func_start move_anim_8072740
move_anim_8072740: @ 80A3BFC
	push {r4,lr}
	adds r4, r0, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_8072740

	thumb_func_start move_anim_task_del
move_anim_task_del: @ 80A3C1C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_task_del

	thumb_func_start move_anim_related_task_del
move_anim_related_task_del: @ 80A3C38
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_related_task_del

	thumb_func_start sub_80A3C54
sub_80A3C54: @ 80A3C54
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r4, =0x0000ffff
	ldr r1, =gAnimSpriteIndexArray
_080A3C60:
	ldrh r0, [r1]
	cmp r0, r4
	bne _080A3C74
	strh r3, [r1]
	b _080A3C7C
	.pool
_080A3C74:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x7
	ble _080A3C60
_080A3C7C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3C54

	thumb_func_start sub_80A3C84
sub_80A3C84: @ 80A3C84
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r0, =0x0000ffff
	adds r4, r0, 0
	ldr r1, =gAnimSpriteIndexArray
_080A3C92:
	ldrh r0, [r1]
	cmp r0, r3
	bne _080A3CA8
	orrs r0, r4
	strh r0, [r1]
	b _080A3CB0
	.pool
_080A3CA8:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x7
	ble _080A3C92
_080A3CB0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3C84

	thumb_func_start move_anim_waiter
move_anim_waiter: @ 80A3CB8
	push {lr}
	ldr r2, =gAnimFramesToWait
	ldrb r1, [r2]
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	bgt _080A3CDC
	ldr r0, =gAnimScriptCallback
	ldr r1, =move_anim_execute
	str r1, [r0]
	movs r0, 0
	b _080A3CDE
	.pool
_080A3CDC:
	subs r0, r1, 0x1
_080A3CDE:
	strb r0, [r2]
	pop {r0}
	bx r0
	thumb_func_end move_anim_waiter

	thumb_func_start move_anim_execute
move_anim_execute: @ 80A3CE4
	push {r4,lr}
	ldr r4, =gUnknown_08525E98
_080A3CE8:
	ldr r0, =gBattleAnimScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gAnimFramesToWait
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080A3D0C
	ldr r0, =gAnimScriptActive
	ldrb r0, [r0]
	cmp r0, 0
	bne _080A3CE8
_080A3D0C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_execute

	thumb_func_start ma00_load_graphics
ma00_load_graphics: @ 80A3D24
	push {r4-r6,lr}
	ldr r6, =gBattleAnimScriptPtr
	ldr r0, [r6]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r4, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r4, r0
	lsls r5, r4, 3
	ldr r0, =gUnknown_085112C4
	adds r0, r5, r0
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_08511BCC
	adds r5, r0
	adds r0, r5, 0
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r0, [r6]
	adds r0, 0x2
	str r0, [r6]
	ldr r0, =0xffffd8f0
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	bl sub_80A3C54
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gAnimScriptCallback
	ldr r0, =move_anim_waiter
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma00_load_graphics

	thumb_func_start ma01_080728D0
@ void ma01_080728D0()
ma01_080728D0: @ 80A3D8C
	push {r4-r6,lr}
	ldr r6, =gBattleAnimScriptPtr
	ldr r0, [r6]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r4, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r4, r0
	ldr r1, =gUnknown_08524B44
	ldr r0, =0xffffd8f0
	adds r4, r0
	lsls r0, r4, 3
	adds r0, r1
	ldrh r5, [r0, 0x6]
	adds r0, r5, 0
	bl FreeSpriteTilesByTag
	adds r0, r5, 0
	bl FreeSpritePaletteByTag
	ldr r0, [r6]
	adds r0, 0x2
	str r0, [r6]
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	bl sub_80A3C84
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma01_080728D0

	thumb_func_start ma02_instanciate_template
ma02_instanciate_template: @ 80A3DD8
	push {r4-r7,lr}
	ldr r5, =gBattleAnimScriptPtr
	ldr r1, [r5]
	adds r3, r1, 0x1
	str r3, [r5]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 24
	adds r7, r2, r0
	adds r0, r1, 0x5
	str r0, [r5]
	ldrb r4, [r1, 0x5]
	adds r0, r1, 0x6
	str r0, [r5]
	ldrb r0, [r1, 0x6]
	adds r1, 0x7
	str r1, [r5]
	cmp r0, 0
	beq _080A3E28
	adds r6, r5, 0
	ldr r5, =gBattleAnimArgs
	adds r3, r0, 0
_080A3E10:
	ldr r2, [r6]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r5]
	adds r2, 0x2
	str r2, [r6]
	adds r5, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _080A3E10
_080A3E28:
	movs r0, 0x80
	ands r0, r4
	cmp r0, 0
	beq _080A3E58
	movs r0, 0x80
	eors r4, r0
	cmp r4, 0x3F
	bls _080A3E48
	adds r0, r4, 0
	subs r0, 0x40
	b _080A3E4A
	.pool
_080A3E48:
	negs r0, r4
_080A3E4A:
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gAnimationBankTarget
	b _080A3E6A
	.pool
_080A3E58:
	cmp r4, 0x3F
	bls _080A3E62
	adds r0, r4, 0
	subs r0, 0x40
	b _080A3E64
_080A3E62:
	negs r0, r4
_080A3E64:
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gAnimationBankAttacker
_080A3E6A:
	ldrb r0, [r0]
	bl sub_80A82E4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 24
	asrs r1, 24
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r0, r6, 16
	asrs r0, 16
	cmp r0, 0x2
	bgt _080A3E88
	movs r6, 0x3
_080A3E88:
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x3
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, r6, 24
	lsrs r3, 24
	adds r0, r7, 0
	adds r1, r4, 0
	bl CreateSpriteAndAnimate
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma02_instanciate_template

	thumb_func_start sub_80A3ECC
sub_80A3ECC: @ 80A3ECC
	push {r4-r7,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r1, [r4]
	adds r3, r1, 0x1
	str r3, [r4]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 24
	adds r6, r2, r0
	adds r0, r1, 0x5
	str r0, [r4]
	ldrb r7, [r1, 0x5]
	adds r0, r1, 0x6
	str r0, [r4]
	ldrb r0, [r1, 0x6]
	adds r1, 0x7
	str r1, [r4]
	cmp r0, 0
	beq _080A3F1C
	adds r5, r4, 0
	ldr r4, =gBattleAnimArgs
	adds r3, r0, 0
_080A3F04:
	ldr r2, [r5]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r4]
	adds r2, 0x2
	str r2, [r5]
	adds r4, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _080A3F04
_080A3F1C:
	adds r0, r6, 0
	adds r1, r7, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r6
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3ECC

	thumb_func_start ma04_wait_countdown
ma04_wait_countdown: @ 80A3F48
	push {r4,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r2, r0, 0x1
	str r2, [r1]
	ldr r3, =gAnimFramesToWait
	ldrb r0, [r0, 0x1]
	strb r0, [r3]
	lsls r0, 24
	cmp r0, 0
	bne _080A3F66
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	strb r0, [r3]
_080A3F66:
	adds r0, r2, 0x1
	str r0, [r1]
	ldr r1, =gAnimScriptCallback
	ldr r0, =move_anim_waiter
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma04_wait_countdown

	thumb_func_start sub_80A3F88
sub_80A3F88: @ 80A3F88
	push {lr}
	ldr r0, =gAnimVisualTaskCount
	ldrb r2, [r0]
	cmp r2, 0
	bne _080A3FAC
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	ldr r0, =gAnimFramesToWait
	strb r2, [r0]
	b _080A3FB2
	.pool
_080A3FAC:
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
_080A3FB2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3F88

	thumb_func_start nullsub_6
nullsub_6: @ 80A3FBC
	bx lr
	thumb_func_end nullsub_6

	thumb_func_start nullsub_7
nullsub_7: @ 80A3FC0
	bx lr
	thumb_func_end nullsub_7

	thumb_func_start sub_80A3FC4
sub_80A3FC4: @ 80A3FC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	ldr r0, =gAnimVisualTaskCount
	ldrb r0, [r0]
	cmp r0, 0
	bne _080A3FEC
	ldr r0, =gAnimSoundTaskCount
	ldrb r0, [r0]
	cmp r0, 0
	bne _080A3FEC
	ldr r1, =gUnknown_02038430
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _080A3FEC
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	beq _080A4004
_080A3FEC:
	ldr r1, =gSoundAnimFramesToWait
	movs r0, 0
	strh r0, [r1]
	b _080A401E
	.pool
_080A4004:
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _080A403C
	ldr r1, =gSoundAnimFramesToWait
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5A
	bhi _080A4030
_080A401E:
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
	b _080A40A2
	.pool
_080A4030:
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
_080A403C:
	ldr r1, =gSoundAnimFramesToWait
	movs r0, 0
	strh r0, [r1]
	movs r5, 0
	ldr r7, =0x0000ffff
	ldr r6, =gUnknown_08524B44
	ldr r4, =gAnimSpriteIndexArray
_080A404A:
	ldrh r0, [r4]
	cmp r0, r7
	beq _080A406E
	lsls r0, 3
	adds r0, r6
	ldrh r0, [r0, 0x6]
	bl FreeSpriteTilesByTag
	ldrh r0, [r4]
	lsls r0, 3
	adds r0, r6
	ldrh r0, [r0, 0x6]
	bl FreeSpritePaletteByTag
	ldrh r1, [r4]
	adds r0, r7, 0
	orrs r0, r1
	strh r0, [r4]
_080A406E:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x7
	ble _080A404A
	mov r1, r8
	cmp r1, 0
	bne _080A40A2
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A409C
	bl sub_80A8278
	movs r0, 0x1
	bl sub_8072A88
_080A409C:
	ldr r0, =gAnimScriptActive
	mov r1, r8
	strb r1, [r0]
_080A40A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A3FC4

	thumb_func_start ma09_play_sound
ma09_play_sound: @ 80A40CC
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	adds r1, r0, 0x1
	str r1, [r4]
	ldrb r0, [r0, 0x1]
	ldrb r1, [r1, 0x1]
	lsls r1, 8
	orrs r0, r1
	bl PlaySE
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma09_play_sound

	thumb_func_start sub_80A40F4
sub_80A40F4: @ 80A40F4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	mov r8, r1
	adds r6, r0, r1
	ldr r1, =gBankSpriteIds
	movs r2, 0
	ldrsh r0, [r6, r2]
	adds r0, r1
	ldrb r5, [r0]
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r4, r0, r1
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r3, 0x4
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _080A4148
	adds r0, r7, 0
	bl move_anim_task_del
	b _080A41BE
	.pool
_080A4148:
	ldr r0, =task_pA_ma0A_obj_to_bg_pal
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	mov r1, r8
	subs r1, 0x8
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	strh r5, [r1, 0x8]
	ldrh r0, [r4, 0x24]
	ldrh r3, [r4, 0x20]
	adds r0, r3
	strh r0, [r1, 0xA]
	ldrh r0, [r4, 0x26]
	ldrh r4, [r4, 0x22]
	adds r0, r4
	strh r0, [r1, 0xC]
	movs r3, 0x2
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _080A4190
	ldr r0, =gUnknown_02022E18
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	ldr r0, =gUnknown_02022E1A
	b _080A4198
	.pool
_080A4190:
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	strh r0, [r1, 0xE]
	ldr r0, =gUnknown_02022E1E
_080A4198:
	ldrh r0, [r0]
	strh r0, [r1, 0x10]
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r6, 0x2]
	strh r1, [r0, 0x12]
	ldrh r1, [r6]
	strh r1, [r0, 0x14]
	ldr r1, =gUnknown_02038430
	movs r3, 0x6
	ldrsh r0, [r6, r3]
	adds r0, r1
	strb r2, [r0]
	adds r0, r7, 0
	bl move_anim_task_del
_080A41BE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A40F4

	thumb_func_start sub_80A41D8
sub_80A41D8: @ 80A41D8
	push {r4,r5,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r2, [r1]
	adds r0, r2, 0x1
	str r0, [r1]
	ldrb r0, [r2, 0x1]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A41F8
	ldr r0, =gAnimationBankTarget
	b _080A41FA
	.pool
_080A41F8:
	ldr r0, =gAnimationBankAttacker
_080A41FA:
	ldrb r4, [r0]
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4266
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _080A4226
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4230
_080A4226:
	movs r5, 0
	b _080A4232
	.pool
_080A4230:
	movs r5, 0x1
_080A4232:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A438C
	ldr r0, =sub_80A40F4
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	strh r4, [r0, 0x8]
	strh r5, [r0, 0xA]
	movs r1, 0x1
	strh r1, [r0, 0xC]
	strh r2, [r0, 0xE]
_080A4266:
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A42D8
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _080A4294
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A42A4
_080A4294:
	movs r5, 0
	b _080A42A6
	.pool
_080A42A4:
	movs r5, 0x1
_080A42A6:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A438C
	ldr r0, =sub_80A40F4
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	strh r5, [r0, 0xA]
	movs r1, 0x1
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
_080A42D8:
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gAnimScriptCallback
	ldr r0, =move_anim_waiter
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A41D8

	thumb_func_start b_side_obj__get_some_boolean
b_side_obj__get_some_boolean: @ 80A4310
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4330
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	cmp r4, r0
	beq _080A4374
	b _080A4384
	.pool
_080A4330:
	adds r0, r4, 0
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _080A4384
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A4374
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A4374
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r5, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _080A4384
_080A4374:
	movs r0, 0x1
	b _080A4386
	.pool
_080A4384:
	movs r0, 0
_080A4386:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end b_side_obj__get_some_boolean

	thumb_func_start sub_80A438C
sub_80A438C: @ 80A438C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	cmp r1, 0
	beq _080A43AA
	b _080A455E
_080A43AA:
	bl IsContest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080A43DC
	ldr r1, =0x06008000
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldr r1, =0x0600f000
	movs r2, 0x80
	lsls r2, 5
	movs r0, 0xFF
	movs r3, 0
	bl RequestDma3Fill
	b _080A43F8
	.pool
_080A43DC:
	ldr r1, =0x06004000
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldr r1, =0x0600e000
	movs r2, 0x80
	lsls r2, 5
	movs r0, 0xFF
	movs r3, 0
	bl RequestDma3Fill
_080A43F8:
	add r0, sp, 0x10
	bl sub_80A6B30
	add r0, sp, 0x20
	movs r1, 0
	strh r1, [r0]
	ldr r1, [sp, 0x10]
	ldr r2, =0x01000800
	bl CpuSet
	mov r0, sp
	adds r0, 0x22
	movs r1, 0xFF
	strh r1, [r0]
	ldr r1, [sp, 0x14]
	ldr r2, =0x01000400
	bl CpuSet
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x2
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl lcd_bg_operations
	ldr r0, =gBankSpriteIds
	adds r0, r6, r0
	ldrb r4, [r0]
	ldr r5, =gUnknown_02022E18
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x24]
	ldrh r1, [r1, 0x20]
	adds r0, r1
	negs r0, r0
	adds r0, 0x20
	strh r0, [r5]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A447A
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	bl sub_80DB2A8
	lsls r0, 24
	cmp r0, 0
	beq _080A447A
	ldrh r0, [r5]
	subs r0, 0x1
	strh r0, [r5]
_080A447A:
	ldr r5, =gUnknown_02022E1A
	ldr r2, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x26]
	ldrh r1, [r1, 0x22]
	adds r0, r1
	negs r0, r0
	adds r0, 0x20
	strh r0, [r5]
	mov r0, r9
	cmp r0, 0
	beq _080A44B0
	ldr r0, =gBankSpriteIds
	adds r0, r6, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080A44B0:
	ldr r0, =gUnknown_02022E18
	ldrh r1, [r0]
	movs r0, 0x14
	bl SetGpuReg
	ldrh r1, [r5]
	movs r0, 0x16
	bl SetGpuReg
	lsls r4, r6, 5
	ldr r0, =gPlttBufferUnfaded + 0x200
	adds r4, r0
	add r0, sp, 0x10
	ldrb r1, [r0, 0x8]
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	add r0, sp, 0x10
	ldrb r1, [r0, 0x8]
	lsls r1, 5
	movs r0, 0xA0
	lsls r0, 19
	adds r1, r0
	ldr r2, =0x04000008
	adds r0, r4, 0
	bl CpuSet
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4524
	movs r3, 0
	b _080A452E
	.pool
_080A4524:
	adds r0, r6, 0
	bl GetBankIdentity
	lsls r0, 24
	lsrs r3, r0, 24
_080A452E:
	add r0, sp, 0x10
	ldrb r0, [r0, 0x8]
	str r0, [sp]
	ldr r0, [sp, 0x10]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x8]
	add r0, sp, 0x10
	ldrh r0, [r0, 0xA]
	str r0, [sp, 0xC]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_8118FBC
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A4558
	b _080A4666
_080A4558:
	bl sub_80A46A0
	b _080A4666
_080A455E:
	ldr r1, =0x06006000
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldr r1, =0x0600f000
	movs r7, 0x80
	lsls r7, 5
	movs r0, 0
	adds r2, r7, 0
	movs r3, 0x1
	bl RequestDma3Fill
	add r0, sp, 0x10
	movs r1, 0x2
	bl sub_80A6B90
	add r0, sp, 0x24
	movs r4, 0
	strh r4, [r0]
	ldr r1, [sp, 0x10]
	adds r1, r7
	ldr r2, =0x01000800
	bl CpuSet
	mov r0, sp
	adds r0, 0x26
	strh r4, [r0]
	ldr r1, [sp, 0x14]
	movs r2, 0x80
	lsls r2, 4
	mov r8, r2
	add r1, r8
	ldr r2, =0x01000400
	bl CpuSet
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl lcd_bg_operations
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl lcd_bg_operations
	ldr r0, =gBankSpriteIds
	adds r2, r5, r0
	ldrb r4, [r2]
	ldr r5, =gUnknown_02022E1C
	ldr r3, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r1, 0x24]
	ldrh r4, [r1, 0x20]
	adds r0, r4
	negs r0, r0
	adds r0, 0x20
	strh r0, [r5]
	ldr r4, =gUnknown_02022E1E
	ldrh r0, [r1, 0x26]
	ldrh r1, [r1, 0x22]
	adds r0, r1
	negs r0, r0
	adds r0, 0x20
	strh r0, [r4]
	mov r0, r9
	cmp r0, 0
	beq _080A460E
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080A460E:
	ldrh r1, [r5]
	movs r0, 0x18
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x1A
	bl SetGpuReg
	lsls r4, r6, 5
	ldr r0, =gPlttBufferUnfaded + 0x200
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x90
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =0x05000120
	ldr r2, =0x04000008
	adds r0, r4, 0
	bl CpuSet
	adds r0, r6, 0
	bl GetBankIdentity
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0x10
	ldrb r0, [r0, 0x8]
	str r0, [sp]
	ldr r0, [sp, 0x10]
	adds r0, r7
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x14]
	add r0, r8
	str r0, [sp, 0x8]
	add r0, sp, 0x10
	ldrh r0, [r0, 0xA]
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl sub_8118FBC
_080A4666:
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A438C

	thumb_func_start sub_80A46A0
sub_80A46A0: @ 80A46A0
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r0, [r0]
	bl sub_80DB2A8
	lsls r0, 24
	cmp r0, 0
	beq _080A4712
	mov r0, sp
	bl sub_80A6B30
	ldr r6, [sp, 0x4]
	movs r5, 0
	movs r0, 0x7
	mov r12, r0
	movs r7, 0
_080A46C6:
	movs r4, 0
	adds r3, r7, r6
	mov r1, r12
	lsls r0, r1, 1
	adds r2, r0, r6
_080A46D0:
	ldrh r1, [r3]
	ldrh r0, [r2]
	strh r0, [r3]
	strh r1, [r2]
	adds r3, 0x2
	subs r2, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _080A46D0
	movs r0, 0x20
	add r12, r0
	adds r7, 0x40
	adds r5, 0x1
	cmp r5, 0x7
	ble _080A46C6
	movs r5, 0
	movs r1, 0x80
	lsls r1, 3
	adds r3, r1, 0
_080A46F6:
	adds r2, r5, 0x1
	lsls r0, r5, 6
	adds r1, r0, r6
	movs r4, 0x7
_080A46FE:
	ldrh r0, [r1]
	eors r0, r3
	strh r0, [r1]
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _080A46FE
	adds r5, r2, 0
	cmp r5, 0x7
	ble _080A46F6
_080A4712:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A46A0

	thumb_func_start sub_80A4720
sub_80A4720: @ 80A4720
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, 0
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r3, 24
	movs r0, 0x40
	mov r12, r0
	cmp r3, 0
	bne _080A473C
	movs r1, 0x20
	mov r12, r1
_080A473C:
	lsls r0, r5, 28
	lsrs r5, r0, 16
	movs r0, 0
	cmp r0, r12
	bge _080A476C
	ldr r7, =0x00000fff
_080A4748:
	adds r4, r0, 0x1
	lsls r0, 6
	mov r1, r8
	adds r3, r0, r1
	movs r2, 0x1F
_080A4752:
	ldrh r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	orrs r0, r5
	adds r0, r6
	strh r0, [r3]
	adds r3, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A4752
	adds r0, r4, 0
	cmp r0, r12
	blt _080A4748
_080A476C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A4720

	thumb_func_start sub_80A477C
sub_80A477C: @ 80A477C
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r0, sp
	bl sub_80A6B30
	cmp r4, 0
	beq _080A479C
	bl IsContest
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080A47B8
_080A479C:
	movs r0, 0x1
	bl sub_80A6C68
	ldr r0, =gUnknown_02022E18
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	b _080A47C6
	.pool
_080A47B8:
	movs r0, 0x2
	bl sub_80A6C68
	ldr r0, =gUnknown_02022E1C
	strh r4, [r0]
	ldr r0, =gUnknown_02022E1E
	strh r4, [r0]
_080A47C6:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A477C

	thumb_func_start task_pA_ma0A_obj_to_bg_pal
@ void task_pA_ma0A_obj_to_bg_pal(int task_id)
task_pA_ma0A_obj_to_bg_pal: @ 80A47D8
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r2
	ldrb r4, [r5, 0x8]
	ldrb r6, [r5, 0x14]
	mov r0, sp
	bl sub_80A6B30
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x24]
	ldrh r0, [r1, 0x20]
	adds r2, r0
	ldrh r0, [r5, 0xA]
	subs r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	ldrh r2, [r1, 0x26]
	ldrh r1, [r1, 0x22]
	adds r2, r1
	ldrh r0, [r5, 0xC]
	subs r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080A4870
	ldr r1, =gUnknown_02022E18
	lsls r0, r3, 16
	asrs r0, 16
	ldrh r3, [r5, 0xE]
	adds r0, r3
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1A
	lsls r0, r2, 16
	asrs r0, 16
	ldrh r5, [r5, 0x10]
	adds r0, r5
	strh r0, [r1]
	lsls r0, r6, 5
	ldr r2, =gPlttBufferFaded + 0x200
	adds r0, r2
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 5
	ldr r3, =0xfffffe00
	adds r2, r3
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	b _080A4896
	.pool
_080A4870:
	ldr r1, =gUnknown_02022E1C
	lsls r0, r3, 16
	asrs r0, 16
	ldrh r3, [r5, 0xE]
	adds r0, r3
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1E
	lsls r0, r2, 16
	asrs r0, 16
	ldrh r5, [r5, 0x10]
	adds r0, r5
	strh r0, [r1]
	lsls r0, r6, 5
	ldr r1, =gPlttBufferFaded + 0x200
	adds r0, r1
	subs r1, 0xE0
	ldr r2, =0x04000008
	bl CpuSet
_080A4896:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_pA_ma0A_obj_to_bg_pal

	thumb_func_start ma0B_0807324C
ma0B_0807324C: @ 80A48B0
	push {r4,r5,lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r2, [r0]
	adds r1, r2, 0x1
	str r1, [r0]
	ldrb r4, [r2, 0x1]
	cmp r4, 0
	bne _080A48C8
	movs r4, 0x2
	b _080A48D2
	.pool
_080A48C8:
	cmp r4, 0x1
	bne _080A48CE
	movs r4, 0x3
_080A48CE:
	cmp r4, 0
	beq _080A48D6
_080A48D2:
	cmp r4, 0x2
	bne _080A48E0
_080A48D6:
	ldr r0, =gAnimationBankAttacker
	b _080A48E2
	.pool
_080A48E0:
	ldr r0, =gAnimationBankTarget
_080A48E2:
	ldrb r5, [r0]
	ldr r3, =gUnknown_02038430
	ldrb r0, [r3]
	cmp r0, 0xFF
	beq _080A4908
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r5, r0
	ldrb r1, [r0]
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
_080A4908:
	cmp r4, 0x1
	bls _080A4948
	ldrb r0, [r3, 0x1]
	cmp r0, 0xFF
	beq _080A4948
	ldr r3, =gSprites
	ldr r2, =gBankSpriteIds
	movs r1, 0x2
	adds r0, r5, 0
	eors r0, r1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	b _080A494A
	.pool
_080A4948:
	movs r4, 0
_080A494A:
	ldr r0, =sub_80A4980
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	strh r5, [r1, 0xC]
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma0B_0807324C

	thumb_func_start sub_80A4980
sub_80A4980: @ 80A4980
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _080A4A0A
	ldrb r0, [r1, 0xC]
	bl GetBankIdentity
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _080A49BC
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A49C4
_080A49BC:
	movs r4, 0
	b _080A49C6
	.pool
_080A49C4:
	movs r4, 0x1
_080A49C6:
	ldr r6, =gUnknown_02038430
	ldrb r0, [r6]
	cmp r0, 0xFF
	beq _080A49DE
	adds r0, r4, 0
	bl sub_80A477C
	ldrb r0, [r6]
	bl DestroyTask
	movs r0, 0xFF
	strb r0, [r6]
_080A49DE:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	ble _080A4A04
	movs r0, 0x1
	eors r4, r0
	adds r0, r4, 0
	bl sub_80A477C
	ldrb r0, [r6, 0x1]
	bl DestroyTask
	movs r0, 0xFF
	strb r0, [r6, 0x1]
_080A4A04:
	adds r0, r5, 0
	bl DestroyTask
_080A4A0A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A4980

	thumb_func_start sub_80A4A18
sub_80A4A18: @ 80A4A18
	push {r4,r5,lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r2, [r0]
	adds r1, r2, 0x1
	str r1, [r0]
	ldrb r5, [r2, 0x1]
	cmp r5, 0
	bne _080A4A30
	movs r5, 0x2
	b _080A4A3A
	.pool
_080A4A30:
	cmp r5, 0x1
	bne _080A4A36
	movs r5, 0x3
_080A4A36:
	cmp r5, 0
	beq _080A4A3E
_080A4A3A:
	cmp r5, 0x2
	bne _080A4A48
_080A4A3E:
	ldr r0, =gAnimationBankAttacker
	b _080A4A4A
	.pool
_080A4A48:
	ldr r0, =gAnimationBankTarget
_080A4A4A:
	ldrb r4, [r0]
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4A8A
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _080A4A76
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4A80
_080A4A76:
	movs r1, 0
	b _080A4A82
	.pool
_080A4A80:
	movs r1, 0x1
_080A4A82:
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A438C
_080A4A8A:
	movs r0, 0x2
	eors r4, r0
	cmp r5, 0x1
	bls _080A4ACA
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4ACA
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _080A4ABC
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4AC0
_080A4ABC:
	movs r1, 0
	b _080A4AC2
_080A4AC0:
	movs r1, 0x1
_080A4AC2:
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A438C
_080A4ACA:
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A4A18

	thumb_func_start ma23_8073484
ma23_8073484: @ 80A4ADC
	push {r4-r6,lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r2, [r0]
	adds r1, r2, 0x1
	str r1, [r0]
	ldrb r5, [r2, 0x1]
	cmp r5, 0
	bne _080A4AF4
	movs r5, 0x2
	b _080A4AFE
	.pool
_080A4AF4:
	cmp r5, 0x1
	bne _080A4AFA
	movs r5, 0x3
_080A4AFA:
	cmp r5, 0
	beq _080A4B02
_080A4AFE:
	cmp r5, 0x2
	bne _080A4B0C
_080A4B02:
	ldr r0, =gAnimationBankAttacker
	b _080A4B0E
	.pool
_080A4B0C:
	ldr r0, =gAnimationBankTarget
_080A4B0E:
	ldrb r6, [r0]
	adds r0, r6, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4B38
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r6, r0
	ldrb r1, [r0]
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
_080A4B38:
	cmp r5, 0x1
	bls _080A4B78
	movs r0, 0x2
	adds r4, r6, 0
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4B78
	ldr r2, =gSprites
	ldr r0, =gBankSpriteIds
	adds r0, r4, r0
	ldrb r1, [r0]
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
	b _080A4B7A
	.pool
_080A4B78:
	movs r5, 0
_080A4B7A:
	ldr r0, =sub_80A4BB0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	strh r6, [r1, 0xC]
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma23_8073484

	thumb_func_start sub_80A4BB0
sub_80A4BB0: @ 80A4BB0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	beq _080A4C3E
	ldrb r4, [r1, 0xC]
	adds r0, r4, 0
	bl GetBankIdentity
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bls _080A4BEE
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4BF8
_080A4BEE:
	movs r5, 0
	b _080A4BFA
	.pool
_080A4BF8:
	movs r5, 0x1
_080A4BFA:
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4C0C
	adds r0, r5, 0
	bl sub_80A477C
_080A4C0C:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	ble _080A4C38
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _080A4C38
	movs r0, 0x1
	eors r5, r0
	adds r0, r5, 0
	bl sub_80A477C
_080A4C38:
	adds r0, r6, 0
	bl DestroyTask
_080A4C3E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A4BB0

	thumb_func_start ma0C_set_BLDCNT_to_x3F40_and_BLDALPHA_to_argument
ma0C_set_BLDCNT_to_x3F40_and_BLDALPHA_to_argument: @ 80A4C48
	push {r4,r5,lr}
	ldr r2, =gBattleAnimScriptPtr
	ldr r0, [r2]
	adds r1, r0, 0x1
	str r1, [r2]
	ldrb r5, [r0, 0x1]
	adds r0, r1, 0x1
	str r0, [r2]
	ldrb r4, [r1, 0x1]
	lsls r4, 8
	adds r0, 0x1
	str r0, [r2]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	orrs r5, r4
	movs r0, 0x52
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma0C_set_BLDCNT_to_x3F40_and_BLDALPHA_to_argument

	thumb_func_start ma1E_set_BLDCNT
ma1E_set_BLDCNT: @ 80A4C80
	push {lr}
	ldr r3, =gBattleAnimScriptPtr
	ldr r0, [r3]
	adds r2, r0, 0x1
	str r2, [r3]
	ldrb r1, [r0, 0x1]
	adds r0, r2, 0x1
	str r0, [r3]
	ldrb r2, [r2, 0x1]
	lsls r2, 8
	adds r0, 0x1
	str r0, [r3]
	orrs r1, r2
	movs r0, 0x50
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1E_set_BLDCNT

	thumb_func_start ma0D_reset_BLDCNT_and_BLDALPHA
ma0D_reset_BLDCNT_and_BLDALPHA: @ 80A4CA8
	push {lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma0D_reset_BLDCNT_and_BLDALPHA

	thumb_func_start ma0E_call
ma0E_call: @ 80A4CCC
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r1, [r4]
	adds r3, r1, 0x1
	str r3, [r4]
	ldr r2, =gBattleAnimScriptRetAddr
	adds r0, r1, 0x5
	str r0, [r2]
	ldrb r1, [r1, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma0E_call

	thumb_func_start sub_80A4D00
sub_80A4D00: @ 80A4D00
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, =gBattleAnimScriptRetAddr
	ldr r1, [r1]
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80A4D00

	thumb_func_start ma10_080736AC
ma10_080736AC: @ 80A4D14
	push {r4,r5,lr}
	ldr r5, =gBattleAnimScriptPtr
	ldr r1, [r5]
	adds r0, r1, 0x1
	str r0, [r5]
	ldrb r2, [r1, 0x1]
	adds r3, r0, 0x1
	str r3, [r5]
	ldrb r4, [r0, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r4, r0
	adds r1, 0x4
	str r1, [r5]
	ldr r0, =gBattleAnimArgs
	lsls r2, 1
	adds r2, r0
	strh r4, [r2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma10_080736AC

	thumb_func_start ma11_if_else
ma11_if_else: @ 80A4D48
	push {lr}
	ldr r3, =gBattleAnimScriptPtr
	ldr r2, [r3]
	adds r0, r2, 0x1
	str r0, [r3]
	ldr r0, =gUnknown_02038432
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A4D62
	adds r0, r2, 0x5
	str r0, [r3]
_080A4D62:
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma11_if_else

	thumb_func_start ma12_cond_if
ma12_cond_if: @ 80A4D88
	push {r4,r5,lr}
	ldr r5, =gBattleAnimScriptPtr
	ldr r4, [r5]
	adds r2, r4, 0x1
	str r2, [r5]
	ldrb r1, [r4, 0x1]
	adds r3, r2, 0x1
	str r3, [r5]
	ldr r0, =gUnknown_02038432
	ldrb r0, [r0]
	cmp r1, r0
	bne _080A4DC0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r5]
	b _080A4DC4
	.pool
_080A4DC0:
	adds r0, r4, 0x6
	str r0, [r5]
_080A4DC4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ma12_cond_if

	thumb_func_start ma13_goto
ma13_goto: @ 80A4DCC
	ldr r3, =gBattleAnimScriptPtr
	ldr r0, [r3]
	adds r2, r0, 0x1
	str r2, [r3]
	ldrb r1, [r0, 0x1]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r3]
	bx lr
	.pool
	thumb_func_end ma13_goto

	thumb_func_start IsContest
IsContest: @ 80A4DF0
	push {lr}
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A4E10
	movs r0, 0
	b _080A4E12
	.pool
_080A4E10:
	movs r0, 0x1
_080A4E12:
	pop {r1}
	bx r1
	thumb_func_end IsContest

	thumb_func_start ma14_load_background
ma14_load_background: @ 80A4E18
	push {r4,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r2, [r1]
	adds r0, r2, 0x1
	str r0, [r1]
	ldrb r4, [r2, 0x1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, =task_p5_load_battle_screen_elements
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	ldr r1, =gUnknown_02038433
	movs r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma14_load_background

	thumb_func_start sub_80A4E5C
sub_80A4E5C: @ 80A4E5C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r2, =gBattleAnimScriptPtr
	ldr r1, [r2]
	adds r0, r1, 0x1
	str r0, [r2]
	ldrb r3, [r1, 0x1]
	mov r8, r3
	ldrb r7, [r0, 0x1]
	ldrb r6, [r0, 0x2]
	adds r1, 0x4
	str r1, [r2]
	ldr r0, =task_p5_load_battle_screen_elements
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A4EA8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0x8]
	b _080A4EDA
	.pool
_080A4EA8:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080A4ECC
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r7, [r0, 0x8]
	b _080A4EDA
	.pool
_080A4ECC:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	mov r1, r8
	strh r1, [r0, 0x8]
_080A4EDA:
	ldr r1, =gUnknown_02038433
	movs r0, 0x1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A4E5C

	thumb_func_start task_p5_load_battle_screen_elements
task_p5_load_battle_screen_elements: @ 80A4EF4
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r6, [r4, 0x1C]
	movs r0, 0x1C
	ldrsh r3, [r4, r0]
	adds r7, r1, 0
	cmp r3, 0
	bne _080A4F2C
	str r3, [sp]
	movs r0, 0xE8
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginHardwarePaletteFade
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	b _080A4FBC
	.pool
_080A4F2C:
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080A4FBC
	cmp r3, 0x1
	bne _080A4F50
	adds r0, r6, 0x1
	strh r0, [r4, 0x1C]
	ldr r1, =gUnknown_02038433
	movs r0, 0x2
	strb r0, [r1]
	b _080A4F94
	.pool
_080A4F50:
	cmp r3, 0x2
	bne _080A4F94
	ldrh r0, [r4, 0x8]
	lsls r2, r0, 16
	asrs r1, r2, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A4F68
	bl dp01t_11_3_message_for_player_only
	b _080A4F6E
_080A4F68:
	lsrs r0, r2, 16
	bl sub_80A4FC8
_080A4F6E:
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xE8
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginHardwarePaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x1C]
	adds r1, 0x1
	strh r1, [r0, 0x1C]
	b _080A4FBC
	.pool
_080A4F94:
	ldrb r1, [r2, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080A4FBC
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r7
	movs r1, 0x1C
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	bne _080A4FBC
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =gUnknown_02038433
	strb r4, [r0]
_080A4FBC:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_p5_load_battle_screen_elements

	thumb_func_start sub_80A4FC8
sub_80A4FC8: @ 80A4FC8
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r7, r0, 16
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A5050
	ldr r6, =gUnknown_08525D54
	lsls r4, r7, 1
	adds r4, r7
	lsls r4, 2
	adds r0, r6, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r5, =0x0201c000
	adds r1, r5, 0
	bl LZDecompressWram
	bl sub_80A6D94
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	adds r1, r5, 0
	movs r3, 0
	bl sub_80A4720
	ldr r1, =0x0600d000
	ldr r0, =0x040000d4
	str r5, [r0]
	str r1, [r0, 0x4]
	ldr r1, =0x84000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	adds r0, r4, r6
	ldr r0, [r0]
	ldr r1, =0x06002000
	bl LZDecompressVram
	adds r6, 0x4
	adds r4, r6
	ldr r4, [r4]
	bl sub_80A6D94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 20
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	b _080A507E
	.pool
_080A5050:
	ldr r5, =gUnknown_08525D54
	lsls r4, r7, 1
	adds r4, r7
	lsls r4, 2
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =0x0600d000
	bl LZDecompressVram
	adds r0, r4, r5
	ldr r0, [r0]
	ldr r1, =0x06008000
	bl LZDecompressVram
	adds r5, 0x4
	adds r4, r5
	ldr r0, [r4]
	movs r1, 0x20
	movs r2, 0x20
	bl LoadCompressedPalette
_080A507E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A4FC8

	thumb_func_start dp01t_11_3_message_for_player_only
dp01t_11_3_message_for_player_only: @ 80A5090
	push {lr}
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A50A2
	bl sub_80D7724
	b _080A50A6
_080A50A2:
	bl load_battle_oval_graphics
_080A50A6:
	pop {r0}
	bx r0
	thumb_func_end dp01t_11_3_message_for_player_only

	thumb_func_start ma15_load_battle_screen_elements
ma15_load_battle_screen_elements: @ 80A50AC
	push {lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, =task_p5_load_battle_screen_elements
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x8]
	ldr r1, =gUnknown_02038433
	movs r0, 0x1
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma15_load_battle_screen_elements

	thumb_func_start ma16_wait_for_battle_screen_elements_s2
ma16_wait_for_battle_screen_elements_s2: @ 80A50F0
	push {lr}
	ldr r0, =gUnknown_02038433
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080A5114
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r1, =gAnimFramesToWait
	movs r0, 0
	b _080A5118
	.pool
_080A5114:
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
_080A5118:
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma16_wait_for_battle_screen_elements_s2

	thumb_func_start sub_80A5124
sub_80A5124: @ 80A5124
	push {lr}
	ldr r0, =gUnknown_02038433
	ldrb r2, [r0]
	cmp r2, 0
	bne _080A5148
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	ldr r0, =gAnimFramesToWait
	strb r2, [r0]
	b _080A514E
	.pool
_080A5148:
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
_080A514E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5124

	thumb_func_start ma18_load_background_probably
ma18_load_background_probably: @ 80A5158
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r1, [r4]
	adds r0, r1, 0x1
	str r0, [r4]
	ldrb r0, [r1, 0x1]
	bl sub_80A4FC8
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma18_load_background_probably

	thumb_func_start BattleAnimGetPanControl
BattleAnimGetPanControl: @ 80A5178
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A51C0
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gAnimationBankAttacker
	ldrb r2, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A51C0
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	movs r4, 0xC0
	cmp r0, 0
	beq _080A5252
	movs r4, 0x3F
	b _080A5252
	.pool
_080A51C0:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A51E8
	ldr r0, =gAnimationBankAttacker
	ldr r1, =gAnimationBankTarget
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080A524C
	cmp r0, 0x2
	bne _080A524C
	cmp r4, 0x3F
	beq _080A525E
	b _080A524C
	.pool
_080A51E8:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080A5226
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080A5252
	lsls r0, r4, 24
	asrs r1, r0, 24
	cmp r1, 0x3F
	bne _080A5218
	movs r4, 0xC0
	b _080A5252
	.pool
_080A5218:
	movs r0, 0x40
	negs r0, r0
	cmp r1, r0
	beq _080A5252
	negs r0, r1
	lsls r0, 24
	b _080A5250
_080A5226:
	ldr r0, =gAnimationBankTarget
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080A524C
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0x40
	negs r1, r1
	cmp r0, r1
	bne _080A5252
	movs r4, 0x3F
	b _080A5252
	.pool
_080A524C:
	lsls r0, r4, 24
	negs r0, r0
_080A5250:
	lsrs r4, r0, 24
_080A5252:
	lsls r0, r4, 24
	asrs r0, 24
	cmp r0, 0x3F
	ble _080A525E
	movs r4, 0x3F
	b _080A526C
_080A525E:
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0x40
	negs r1, r1
	cmp r0, r1
	bge _080A526C
	movs r4, 0xC0
_080A526C:
	lsls r0, r4, 24
	asrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end BattleAnimGetPanControl

	thumb_func_start sub_80A5278
sub_80A5278: @ 80A5278
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A52C0
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gAnimationBankAttacker
	ldrb r2, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A52C0
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	movs r4, 0xC0
	cmp r0, 0
	beq _080A52DE
	movs r4, 0x3F
	b _080A52DE
	.pool
_080A52C0:
	ldr r0, =gAnimationBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080A52D8
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A52DE
_080A52D8:
	lsls r0, r4, 24
	negs r0, r0
	lsrs r4, r0, 24
_080A52DE:
	lsls r0, r4, 24
	asrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A5278

	thumb_func_start sub_80A52EC
sub_80A52EC: @ 80A52EC
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r2, r0, 16
	cmp r2, 0x3F
	ble _080A52FC
	movs r1, 0x3F
	b _080A5306
_080A52FC:
	movs r0, 0x40
	negs r0, r0
	cmp r2, r0
	bge _080A5306
	ldr r1, =0x0000ffc0
_080A5306:
	lsls r0, r1, 16
	asrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A52EC

	thumb_func_start sub_80A5314
sub_80A5314: @ 80A5314
	push {lr}
	lsls r2, 16
	lsrs r2, 16
	adds r3, r2, 0
	lsls r0, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bge _080A5332
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A5342
	b _080A5340
_080A5332:
	cmp r0, r1
	ble _080A5348
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A5340
	negs r0, r0
_080A5340:
	negs r0, r0
_080A5342:
	lsls r0, 16
	lsrs r0, 16
	b _080A534A
_080A5348:
	movs r0, 0
_080A534A:
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_80A5314

	thumb_func_start ma19_08073BC8
ma19_08073BC8: @ 80A5354
	push {r4,r5,lr}
	ldr r5, =gBattleAnimScriptPtr
	ldr r0, [r5]
	adds r1, r0, 0x1
	str r1, [r5]
	ldrb r4, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r4, r0
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimGetPanControl
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl PlaySE12WithPanning
	ldr r0, [r5]
	adds r0, 0x3
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma19_08073BC8

	thumb_func_start ma1A_8073C00
ma1A_8073C00: @ 80A538C
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r1, [r4]
	adds r0, r1, 0x1
	str r0, [r4]
	movs r0, 0x1
	ldrsb r0, [r1, r0]
	bl BattleAnimGetPanControl
	lsls r0, 24
	asrs r0, 24
	bl SE12PanpotControl
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1A_8073C00

	thumb_func_start ma1B_8073C2C
ma1B_8073C2C: @ 80A53B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleAnimScriptPtr
	mov r10, r0
	ldr r0, [r0]
	adds r1, r0, 0x1
	mov r2, r10
	str r1, [r2]
	ldrb r0, [r0, 0x1]
	mov r9, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	mov r2, r9
	orrs r2, r0
	mov r9, r2
	ldrb r4, [r1, 0x3]
	ldrb r6, [r1, 0x4]
	ldrb r7, [r1, 0x5]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimGetPanControl
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	asrs r4, 24
	adds r0, r4, 0
	bl BattleAnimGetPanControl
	mov r8, r0
	lsls r5, 24
	asrs r5, 24
	mov r0, r8
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	lsls r6, 24
	asrs r6, 24
	adds r0, r5, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_80A5314
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =c3_08073CEC
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	mov r2, r8
	strh r2, [r1, 0xA]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xC]
	strh r7, [r1, 0xE]
	strh r5, [r1, 0x10]
	mov r0, r9
	adds r1, r5, 0
	bl PlaySE12WithPanning
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r1, r10
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1B_8073C2C

	thumb_func_start c3_08073CEC
c3_08073CEC: @ 80A5478
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x18]
	adds r1, r0, 0x1
	strh r1, [r2, 0x18]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0xE
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _080A54FC
	strh r7, [r2, 0x18]
	ldrh r6, [r2, 0x8]
	ldrh r3, [r2, 0xA]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	movs r4, 0xC
	ldrsh r1, [r2, r4]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	strh r4, [r2, 0x10]
	cmp r1, 0
	bne _080A54C0
	lsls r2, r3, 16
	b _080A54E4
	.pool
_080A54C0:
	lsls r1, r6, 16
	lsls r0, r3, 16
	asrs r3, r0, 16
	adds r2, r0, 0
	cmp r1, r2
	bge _080A54D6
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, r3
	blt _080A54E0
	b _080A54E4
_080A54D6:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, r3
	bgt _080A54E0
	movs r7, 0x1
_080A54E0:
	cmp r7, 0
	beq _080A54F4
_080A54E4:
	lsrs r4, r2, 16
	adds r0, r5, 0
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_080A54F4:
	lsls r0, r4, 24
	asrs r0, 24
	bl SE12PanpotControl
_080A54FC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_08073CEC

	thumb_func_start sub_80A5508
sub_80A5508: @ 80A5508
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	ldr r0, =gBattleAnimScriptPtr
	mov r9, r0
	ldr r0, [r0]
	adds r1, r0, 0x1
	mov r2, r9
	str r1, [r2]
	ldrb r0, [r0, 0x1]
	mov r8, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	mov r2, r8
	orrs r2, r0
	mov r8, r2
	ldrb r4, [r1, 0x2]
	ldrb r5, [r1, 0x3]
	ldrb r6, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	mov r10, r1
	ldr r0, =c3_08073CEC
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0x8]
	lsls r5, 24
	asrs r5, 24
	strh r5, [r1, 0xA]
	lsls r6, 24
	asrs r6, 24
	strh r6, [r1, 0xC]
	mov r0, r10
	strh r0, [r1, 0xE]
	strh r4, [r1, 0x10]
	mov r0, r8
	adds r1, r4, 0
	bl PlaySE12WithPanning
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5508

	thumb_func_start sub_80A559C
sub_80A559C: @ 80A559C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattleAnimScriptPtr
	mov r10, r0
	ldr r0, [r0]
	adds r1, r0, 0x1
	mov r2, r10
	str r1, [r2]
	ldrb r0, [r0, 0x1]
	mov r9, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	mov r2, r9
	orrs r2, r0
	mov r9, r2
	ldrb r4, [r1, 0x3]
	ldrb r0, [r1, 0x4]
	mov r8, r0
	ldrb r7, [r1, 0x5]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl sub_80A5278
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	asrs r4, 24
	adds r0, r4, 0
	bl sub_80A5278
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	mov r0, r8
	bl sub_80A5278
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =c3_08073CEC
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsls r6, 24
	asrs r6, 24
	strh r6, [r1, 0x8]
	lsls r5, 24
	asrs r5, 24
	strh r5, [r1, 0xA]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xC]
	strh r7, [r1, 0xE]
	strh r6, [r1, 0x10]
	mov r0, r9
	adds r1, r6, 0
	bl PlaySE12WithPanning
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r2, r10
	ldr r0, [r2]
	adds r0, 0x6
	str r0, [r2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A559C

	thumb_func_start ma1C_8073ED0
ma1C_8073ED0: @ 80A565C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r6, =gBattleAnimScriptPtr
	ldr r0, [r6]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r5, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r5, r0
	ldrb r0, [r1, 0x3]
	mov r8, r0
	ldrb r2, [r1, 0x4]
	mov r9, r2
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimGetPanControl
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80A56E4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xA]
	mov r2, r8
	strh r2, [r1, 0xC]
	mov r2, r9
	strh r2, [r1, 0xE]
	mov r2, r8
	strh r2, [r1, 0x18]
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x5
	str r0, [r6]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1C_8073ED0

	thumb_func_start sub_80A56E4
sub_80A56E4: @ 80A56E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x18]
	adds r1, r0, 0x1
	strh r1, [r2, 0x18]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _080A5732
	movs r0, 0
	strh r0, [r2, 0x18]
	ldrh r0, [r2, 0x8]
	ldrb r1, [r2, 0xA]
	ldrh r4, [r2, 0xE]
	subs r4, 0x1
	strh r4, [r2, 0xE]
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	asrs r1, 24
	bl PlaySE12WithPanning
	cmp r4, 0
	bne _080A5732
	adds r0, r5, 0
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_080A5732:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A56E4

	thumb_func_start ma1D_08073FB4
ma1D_08073FB4: @ 80A5740
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r6, =gBattleAnimScriptPtr
	ldr r0, [r6]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r5, [r0, 0x1]
	ldrb r0, [r1, 0x1]
	lsls r0, 8
	orrs r5, r0
	ldrb r0, [r1, 0x3]
	mov r8, r0
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	bl BattleAnimGetPanControl
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80A57B4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0xA]
	mov r0, r8
	strh r0, [r1, 0xC]
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x4
	str r0, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma1D_08073FB4

	thumb_func_start sub_80A57B4
sub_80A57B4: @ 80A57B4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0xC]
	subs r1, r0, 0x1
	strh r1, [r2, 0xC]
	lsls r0, 16
	cmp r0, 0
	bgt _080A57E8
	ldrh r0, [r2, 0x8]
	movs r1, 0xA
	ldrsb r1, [r2, r1]
	bl PlaySE12WithPanning
	adds r0, r4, 0
	bl DestroyTask
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_080A57E8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A57B4

	thumb_func_start sub_80A57F8
sub_80A57F8: @ 80A57F8
	push {r4-r6,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r1, [r4]
	adds r3, r1, 0x1
	str r3, [r4]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r3, 0x2]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 24
	adds r6, r2, r0
	adds r0, r1, 0x5
	str r0, [r4]
	ldrb r0, [r1, 0x5]
	adds r1, 0x6
	str r1, [r4]
	cmp r0, 0
	beq _080A5842
	adds r5, r4, 0
	ldr r4, =gBattleAnimArgs
	adds r3, r0, 0
_080A582A:
	ldr r2, [r5]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r4]
	adds r2, 0x2
	str r2, [r5]
	adds r4, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _080A582A
_080A5842:
	adds r0, r6, 0
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r6
	ldr r1, =gAnimSoundTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A57F8

	thumb_func_start ma20_wait_for_something
ma20_wait_for_something: @ 80A586C
	push {r4,r5,lr}
	ldr r0, =gAnimSoundTaskCount
	ldrb r5, [r0]
	cmp r5, 0
	bne _080A58B4
	bl IsSEPlaying
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A58CC
	ldr r4, =gSoundAnimFramesToWait
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5A
	bls _080A58BA
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
	strh r5, [r4]
	b _080A58DE
	.pool
_080A58B4:
	ldr r1, =gSoundAnimFramesToWait
	movs r0, 0
	strh r0, [r1]
_080A58BA:
	ldr r1, =gAnimFramesToWait
	movs r0, 0x1
	strb r0, [r1]
	b _080A58DE
	.pool
_080A58CC:
	ldr r0, =gSoundAnimFramesToWait
	movs r2, 0
	strh r1, [r0]
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, =gAnimFramesToWait
	strb r2, [r0]
_080A58DE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma20_wait_for_something

	thumb_func_start ma21_08074164
ma21_08074164: @ 80A58F0
	push {r4-r6,lr}
	ldr r5, =gBattleAnimScriptPtr
	ldr r4, [r5]
	adds r3, r4, 0x1
	str r3, [r5]
	ldrb r2, [r4, 0x1]
	ldrb r1, [r3, 0x1]
	ldrb r0, [r3, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r0, =gBattleAnimArgs
	lsls r2, 1
	adds r2, r0
	lsls r1, 16
	asrs r1, 16
	movs r6, 0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bne _080A5938
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	adds r1, r0
	str r1, [r5]
	b _080A593E
	.pool
_080A5938:
	adds r0, r4, 0
	adds r0, 0x8
	str r0, [r5]
_080A593E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ma21_08074164

	thumb_func_start sub_80A5944
sub_80A5944: @ 80A5944
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _080A5978
	ldr r2, [r4]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r4]
	b _080A597E
	.pool
_080A5978:
	ldr r0, [r4]
	adds r0, 0x4
	str r0, [r4]
_080A597E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A5944

	thumb_func_start sub_80A5984
sub_80A5984: @ 80A5984
	push {r4,lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, [r0]
	ldrb r2, [r1, 0x1]
	adds r1, 0x2
	str r1, [r0]
	cmp r2, 0
	beq _080A59A0
	ldr r0, =gAnimationBankTarget
	b _080A59A2
	.pool
_080A59A0:
	ldr r0, =gAnimationBankAttacker
_080A59A2:
	ldrb r0, [r0]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A59D2
	cmp r4, 0
	beq _080A59BE
	cmp r4, 0x3
	bne _080A59D2
_080A59BE:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl lcd_bg_operations
_080A59D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5984

	thumb_func_start sub_80A59DC
sub_80A59DC: @ 80A59DC
	push {lr}
	ldr r0, =gBattleAnimScriptPtr
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5A04
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl lcd_bg_operations
_080A5A04:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A59DC

	thumb_func_start sub_80A5A0C
sub_80A5A0C: @ 80A5A0C
	push {r4-r7,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	ldrb r6, [r0, 0x1]
	adds r0, 0x2
	str r0, [r1]
	ldr r7, =gAnimationBankAttacker
	ldrb r0, [r7]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _080A5A78
	cmp r6, 0
	beq _080A5A48
	ldrb r0, [r5]
	b _080A5A4A
	.pool
_080A5A48:
	ldrb r0, [r7]
_080A5A4A:
	bl GetBankIdentity
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5A78
	cmp r4, 0
	beq _080A5A64
	cmp r4, 0x3
	bne _080A5A78
_080A5A64:
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x2
	movs r1, 0x4
	movs r2, 0x2
	bl lcd_bg_operations
_080A5A78:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A5A0C

	thumb_func_start ma2B_make_side_invisible
ma2B_make_side_invisible: @ 80A5A80
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5AA8
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_080A5AA8:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma2B_make_side_invisible

	thumb_func_start ma2C_make_side_visible
ma2C_make_side_visible: @ 80A5ABC
	push {r4,lr}
	ldr r4, =gBattleAnimScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5AE6
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
_080A5AE6:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma2C_make_side_visible

	thumb_func_start sub_80A5AFC
sub_80A5AFC: @ 80A5AFC
	push {r4-r7,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	ldrb r7, [r0, 0x1]
	adds r0, 0x2
	str r0, [r1]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5BA6
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080A5BA6
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080A5BA6
	cmp r7, 0
	bne _080A5B54
	ldrb r0, [r6]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	b _080A5B60
	.pool
_080A5B54:
	ldrb r0, [r5]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1
_080A5B60:
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5BA6
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r2, r0, r1
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	cmp r4, 0x2
	bne _080A5B90
	ldrb r0, [r2, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r2, 0x5]
_080A5B90:
	cmp r4, 0x1
	bne _080A5BA0
	movs r0, 0
	bl sub_80A477C
	b _080A5BA6
	.pool
_080A5BA0:
	movs r0, 0x1
	bl sub_80A477C
_080A5BA6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A5AFC

	thumb_func_start sub_80A5BAC
sub_80A5BAC: @ 80A5BAC
	push {r4-r7,lr}
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	ldrb r7, [r0, 0x1]
	adds r0, 0x2
	str r0, [r1]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _080A5C38
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080A5C38
	ldr r6, =gAnimationBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	adds r4, r0, 0
	ldr r5, =gAnimationBankTarget
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _080A5C38
	cmp r7, 0
	bne _080A5C04
	ldrb r0, [r6]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	b _080A5C10
	.pool
_080A5C04:
	ldrb r0, [r5]
	bl GetBankIdentity_permutated
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1
_080A5C10:
	bl GetAnimBankSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080A5C38
	cmp r4, 0x2
	bne _080A5C38
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
_080A5C38:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80A5BAC

	thumb_func_start ma2F_stop_music
ma2F_stop_music: @ 80A5C44
	push {lr}
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
	ldr r1, =gBattleAnimScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ma2F_stop_music

	.align 2, 0 @ Don't pad with nop.
