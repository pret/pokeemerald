	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_810C324
sub_810C324: @ 810C324
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C366
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetAnimBgAttribute
_0810C366:
	ldr r0, =gBattle_BG1_X
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gBattle_BG1_Y
	strh r1, [r4]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gWeatherFog1Tiles
	movs r2, 0x80
	lsls r2, 4
	mov r3, sp
	ldrh r3, [r3, 0xA]
	bl LoadBgTiles
	ldr r1, =gBattleAnimFogTilemap
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	ldr r0, =gUnknown_083970E8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x26]
	ldr r1, =sub_810C3F0
	str r1, [r0]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C324

	thumb_func_start sub_810C3F0
sub_810C3F0: @ 810C3F0
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gBattle_BG1_X
	ldr r3, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r3
	ldrh r0, [r1, 0x26]
	ldrh r5, [r2]
	adds r0, r5
	strh r0, [r2]
	movs r2, 0x20
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	bls _0810C416
	b _0810C54A
_0810C416:
	lsls r0, 2
	ldr r1, =_0810C42C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810C42C:
	.4byte _0810C440
	.4byte _0810C484
	.4byte _0810C4A6
	.4byte _0810C4EA
	.4byte _0810C50C
_0810C440:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	ldr r1, =gUnknown_08595C88
	movs r5, 0x1A
	ldrsh r0, [r4, r5]
	adds r0, r1
	ldrb r1, [r0]
	strh r1, [r4, 0x1E]
	movs r0, 0x11
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bne _0810C54A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0x1E]
	b _0810C54A
	.pool
_0810C484:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r3
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _0810C54A
	movs r0, 0x5
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _0810C54A
_0810C4A6:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r3
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0810C54A
	movs r0, 0
	strh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	subs r1, 0x1
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r1, 0
	bne _0810C54A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _0810C54A
_0810C4EA:
	mov r0, sp
	bl sub_80A6B30
	movs r0, 0x1
	bl sub_80A6C68
	movs r0, 0x2
	bl sub_80A6C68
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
_0810C50C:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C520
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl SetAnimBgAttribute
_0810C520:
	ldr r0, =gBattle_BG1_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r1, [r0]
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_0810C54A:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C3F0

	thumb_func_start sub_810C560
sub_810C560: @ 810C560
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6]
	strh r0, [r5, 0x2E]
	ldr r0, =gBattleAnimAttacker
	mov r8, r0
	ldrb r0, [r0]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	adds r4, r0, 0
	ldr r7, =gBattleAnimTarget
	ldrb r0, [r7]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bcs _0810C594
	movs r0, 0x80
	lsls r0, 8
	strh r0, [r5, 0x3C]
_0810C594:
	ldr r3, =gBattlerPositions
	ldrb r0, [r7]
	adds r0, r3
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0810C5F4
	ldrh r0, [r6, 0x2]
	negs r0, r0
	strh r0, [r6, 0x2]
	ldrh r0, [r6, 0x6]
	negs r0, r0
	strh r0, [r6, 0x6]
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810C5F0
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0810C5F0
	movs r0, 0x1
	bl GetAnimBattlerSpriteId
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
	adds r1, r5, 0
	adds r1, 0x43
	strb r0, [r1]
_0810C5F0:
	movs r0, 0x1
	strh r0, [r5, 0x3A]
_0810C5F4:
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r6, =gBattleAnimArgs
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0810C65C
	ldrh r0, [r6, 0x2]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x30]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x6]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r6, 0x4]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	b _0810C684
	.pool
_0810C65C:
	ldrh r0, [r6, 0x2]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	strh r0, [r5, 0x30]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x6]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r6, 0x4]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x1
_0810C684:
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x8]
	adds r0, r6
	strh r0, [r5, 0x36]
	ldrb r0, [r4]
	bl GetBattlerSpriteBGPriority
	lsls r0, 24
	lsrs r0, 16
	ldrh r1, [r5, 0x3C]
	orrs r0, r1
	strh r0, [r5, 0x3C]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810C6B8
	movs r0, 0x1
	strh r0, [r5, 0x3A]
	adds r1, r5, 0
	adds r1, 0x43
	movs r0, 0x80
	strb r0, [r1]
_0810C6B8:
	adds r0, r5, 0
	bl InitAnimLinearTranslation
	ldr r0, =sub_810C6D4
	str r0, [r5, 0x1C]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C560

	thumb_func_start sub_810C6D4
sub_810C6D4: @ 810C6D4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	movs r5, 0xFF
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0x1
	beq _0810C7BC
	cmp r1, 0x1
	bgt _0810C6EE
	cmp r1, 0
	beq _0810C6F6
	b _0810C90C
_0810C6EE:
	cmp r1, 0x2
	bne _0810C6F4
	b _0810C8D0
_0810C6F4:
	b _0810C90C
_0810C6F6:
	adds r0, r4, 0
	bl AnimTranslateLinear
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	asrs r0, 4
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810C724
	ldrh r0, [r4, 0x38]
	subs r0, 0x8
	b _0810C728
	.pool
_0810C724:
	ldrh r0, [r4, 0x38]
	adds r0, 0x8
_0810C728:
	ands r0, r5
	strh r0, [r4, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0810C736
	b _0810C90C
_0810C736:
	movs r5, 0x50
	strh r5, [r4, 0x2E]
	ldr r6, =gBattleAnimTarget
	ldrb r0, [r6]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x26]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	adds r0, 0x1D
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C78C
	ldr r1, =gBattlerPositions
	ldrb r0, [r6]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810C78C
	movs r0, 0xCC
	strh r0, [r4, 0x38]
	b _0810C78E
	.pool
_0810C78C:
	strh r5, [r4, 0x38]
_0810C78E:
	movs r0, 0
	strh r0, [r4, 0x26]
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	asrs r0, 3
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	adds r0, 0x2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl InitAnimLinearTranslation
	b _0810C90C
	.pool
_0810C7BC:
	adds r0, r4, 0
	bl AnimTranslateLinear
	ldr r1, =gSineTable
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r0, 3
	ldrh r2, [r4, 0x24]
	adds r0, r2
	strh r0, [r4, 0x24]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	adds r0, 0x40
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	negs r0, r0
	asrs r0, 8
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C83A
	ldrh r1, [r4, 0x38]
	adds r0, r1, 0
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	adds r3, r1, 0
	cmp r0, 0x7F
	bhi _0810C81C
	ldrh r1, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 24
	b _0810C824
	.pool
_0810C81C:
	ldrh r1, [r4, 0x3C]
	lsls r1, 16
	asrs r1, 24
	adds r1, 0x1
_0810C824:
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r0, r3, 0x4
	b _0810C85A
_0810C83A:
	ldrh r0, [r4, 0x38]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _0810C84E
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x80
	b _0810C854
_0810C84E:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x8C
_0810C854:
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	subs r0, 0x4
_0810C85A:
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bgt _0810C90C
	movs r5, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	adds r0, 0x4
	strh r0, [r4, 0x36]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C8B4
	ldr r1, =gBattlerPositions
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810C8B4
	movs r0, 0x80
	lsls r0, 1
	b _0810C8B6
	.pool
_0810C8B4:
	ldr r0, =0x0000fff0
_0810C8B6:
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x3C]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	adds r0, r4, 0
	bl sub_80A6FD4
	b _0810C90C
	.pool
_0810C8D0:
	adds r0, r4, 0
	bl AnimTranslateLinear
	lsls r0, 24
	cmp r0, 0
	beq _0810C90C
	ldrb r0, [r4, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810C8FE
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
_0810C8FE:
	adds r0, r4, 0
	bl DestroySprite
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_0810C90C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C6D4

	thumb_func_start sub_810C918
sub_810C918: @ 810C918
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r0, =sub_810C934
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_810C918

	thumb_func_start sub_810C934
sub_810C934: @ 810C934
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _0810C978
	cmp r5, 0x1
	bgt _0810C95C
	cmp r5, 0
	beq _0810C962
	b _0810C9DC
	.pool
_0810C95C:
	cmp r5, 0x2
	beq _0810C9CE
	b _0810C9DC
_0810C962:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0810C9DC
	strh r5, [r4, 0x10]
	strh r5, [r4, 0x12]
	strh r5, [r4, 0xC]
	b _0810C9B4
_0810C978:
	ldrh r1, [r4, 0x12]
	movs r3, 0x12
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _0810C9C8
	ldrb r0, [r4, 0xE]
	ldrb r1, [r4, 0xC]
	movs r3, 0x1
	bl sub_810C9E4
	lsls r0, 24
	cmp r0, 0
	beq _0810C998
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_0810C998:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	bne _0810C9C4
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _0810C9BC
_0810C9B4:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810C9DC
_0810C9BC:
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
	b _0810C9DC
_0810C9C4:
	strh r5, [r4, 0x12]
	b _0810C9DC
_0810C9C8:
	subs r0, r1, 0x1
	strh r0, [r4, 0x12]
	b _0810C9DC
_0810C9CE:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810C9DC
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_0810C9DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810C934

	thumb_func_start sub_810C9E4
sub_810C9E4: @ 810C9E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_08595CB4
	lsrs r0, 22
	adds r4, r0, r1
	ldrb r0, [r4, 0x3]
	lsls r0, 24
	asrs r0, 28
	mov r8, r0
	cmp r0, 0x2
	beq _0810CAD0
	ldrh r0, [r4, 0x2]
	lsls r0, 20
	lsrs r0, 24
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810CAD0
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, r8
	cmp r1, 0
	beq _0810CA60
	cmp r1, 0x1
	beq _0810CA96
	b _0810CAE2
	.pool
_0810CA60:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r7, 16
	asrs r1, 16
	subs r1, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r6, 16
	asrs r1, 16
	subs r1, r0
	b _0810CACA
_0810CA96:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r7, 16
	asrs r1, 16
	adds r1, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x6
	bl __divsi3
	lsls r1, r6, 16
	asrs r1, 16
	adds r1, r0
_0810CACA:
	lsls r1, 16
	lsrs r6, r1, 16
	b _0810CAE2
_0810CAD0:
	ldrh r0, [r4]
	lsls r0, 22
	asrs r0, 6
	lsrs r7, r0, 16
	ldr r0, [r4]
	lsls r0, 12
	asrs r0, 22
	lsls r0, 16
	lsrs r6, r0, 16
_0810CAE2:
	lsls r0, r6, 16
	asrs r0, 16
	adds r0, 0x8
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r1, r7, 16
	asrs r1, 16
	subs r1, r0
	ldr r0, =gUnknown_08595D2C
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x8
	negs r2, r2
	movs r3, 0x12
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x40
	beq _0810CB44
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	mov r1, r9
	bl StartSpriteAffineAnim
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	strh r7, [r4, 0x34]
	strh r6, [r4, 0x36]
	mov r1, r9
	strh r1, [r4, 0x38]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x3A]
	mov r1, r10
	strh r1, [r4, 0x3C]
	movs r0, 0x1
	b _0810CB46
	.pool
_0810CB44:
	movs r0, 0
_0810CB46:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_810C9E4

	thumb_func_start sub_810CB58
sub_810CB58: @ 810CB58
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	ldrh r1, [r4, 0x22]
	adds r2, r1, 0
	adds r2, 0x8
	strh r2, [r4, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _0810CB82
	lsls r0, r2, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0810CC32
_0810CB82:
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _0810CC04
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810CC04
	ldr r0, =gUnknown_08595B68
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	movs r3, 0x36
	ldrsh r2, [r4, r3]
	adds r3, r4, 0
	adds r3, 0x43
	ldrb r3, [r3]
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2E]
	cmp r0, 0x40
	beq _0810CBE6
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_810CC3C
	str r1, [r0]
	movs r3, 0x2E
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x3A]
	strh r1, [r0, 0x3A]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r4, 0x3C]
	strh r1, [r0, 0x3C]
_0810CBE6:
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	b _0810CC32
	.pool
_0810CC04:
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
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810CC32:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CB58

	thumb_func_start sub_810CC3C
sub_810CC3C: @ 810CC3C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _0810CC7C
	ldr r3, =gTasks
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
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
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810CC7C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CC3C

	thumb_func_start unc_080B06FC
unc_080B06FC: @ 810CC88
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =gAnimDisableStructPtr
	ldr r0, [r0]
	ldrb r1, [r0, 0x11]
	lsrs r0, r1, 4
	lsls r1, 28
	lsrs r1, 28
	subs r0, r1
	subs r0, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _0810CCA6
	movs r1, 0x4
_0810CCA6:
	adds r0, r5, 0
	bl StartSpriteAffineAnim
	adds r0, r5, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x2E]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810CCCE
	ldrh r0, [r6, 0x4]
	negs r0, r0
	strh r0, [r6, 0x4]
_0810CCCE:
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x6]
	adds r0, r1
	strh r0, [r5, 0x36]
	ldrh r0, [r6, 0xA]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl InitAnimArcTranslation
	ldr r0, =sub_810CD1C
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unc_080B06FC

	thumb_func_start sub_810CD1C
sub_810CD1C: @ 810CD1C
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _0810CD3E
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, =RunStoredCallbackWhenAnimEnds
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
_0810CD3E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CD1C

	thumb_func_start sub_810CD4C
sub_810CD4C: @ 810CD4C
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x8
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl InitSpritePosToAnimTarget
	bl Random2
	movs r5, 0xFF
	ands r5, r0
	movs r0, 0x80
	lsls r0, 1
	adds r6, r0, 0
	orrs r5, r6
	bl Random2
	ldr r1, =0x000001ff
	ands r1, r0
	adds r0, r1, 0
	cmp r0, 0xFF
	ble _0810CD92
	subs r0, r6, r0
	lsls r0, 16
	lsrs r1, r0, 16
_0810CD92:
	strh r5, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldr r0, =sub_810CDB0
	str r0, [r4, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CD4C

	thumb_func_start sub_810CDB0
sub_810CDB0: @ 810CDB0
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x34]
	adds r3, r0, r1
	strh r3, [r2, 0x34]
	ldrh r1, [r2, 0x32]
	ldrh r4, [r2, 0x36]
	adds r1, r4
	strh r1, [r2, 0x36]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0810CDD4
	lsls r0, r3, 16
	asrs r0, 24
	negs r0, r0
	b _0810CDD8
_0810CDD4:
	lsls r0, r3, 16
	asrs r0, 24
_0810CDD8:
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x15
	bne _0810CDF6
	adds r0, r2, 0
	bl DestroyAnimSprite
_0810CDF6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810CDB0

	thumb_func_start AnimTask_GetRolloutCounter
AnimTask_GetRolloutCounter: @ 810CDFC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleAnimArgs
	ldrb r3, [r1]
	lsls r3, 1
	adds r3, r1
	ldr r1, =gAnimDisableStructPtr
	ldr r1, [r1]
	ldrb r1, [r1, 0x11]
	lsrs r2, r1, 4
	lsls r1, 28
	lsrs r1, 28
	subs r2, r1
	subs r2, 0x1
	strh r2, [r3]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_GetRolloutCounter

	.align 2, 0
