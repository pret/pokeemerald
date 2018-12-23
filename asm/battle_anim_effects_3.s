	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AnimTask_GetReturnPowerLevel
AnimTask_GetReturnPowerLevel: @ 815F8A0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, =gBattleAnimArgs
	movs r2, 0
	strh r2, [r3, 0xE]
	ldr r1, =gAnimFriendship
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
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_GetReturnPowerLevel

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
	bl GetAnimBattlerSpriteId
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
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
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldr r2, [r0, 0x8]
	mov r10, r2
	ldr r3, [r0, 0xC]
	mov r9, r3
	ldrh r6, [r0]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSpriteSubpriority
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0
	b _0815FB4E
	.pool
_0815FA28:
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FAC8
	ldr r7, =gBattlerPartyIndexes
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
	ldr r0, =gBattleSpritesDataPtr
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
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0
	movs r5, 0x88
	lsls r5, 1
	b _0815FB50
	.pool
_0815FAC8:
	ldr r7, =gBattlerPartyIndexes
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
	ldr r0, =gBattleSpritesDataPtr
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
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r7, 0x1
_0815FB4E:
	ldr r5, =0x0000ffe0
_0815FB50:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
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
	ldr r4, =gBattleAnimAttacker
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
	ldr r0, =gBattleSpritesDataPtr
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0815FCB4
	lsls r4, r5, 16
	asrs r4, 16
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bge _0815FCD6
	b _0815FCCA
	.pool
_0815FCB4:
	lsls r4, r5, 16
	asrs r4, 16
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0
	bl GetBattlerSpriteCoord
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
	bl GetAnimBattlerSpriteId
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
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
	bl GetAnimBattlerSpriteId
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
	ldr r0, =gBattleAnimAttacker
	mov r10, r0
	ldrb r0, [r0]
	str r2, [sp, 0x18]
	bl GetBattlerSide
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
	bl GetBattlerSpriteCoord
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
	bl GetBattlerSpriteCoord
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
	bl DestroyAnimVisualTask
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
	bl BattleAnimAdjustPanning
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x7A
	bl PlaySE12WithPanning
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0815FFBC
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0815FFBC
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
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
	bl DestroyAnimSprite
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0
	bl GetBattlerSpriteCoord
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
	ldr r1, =gBattlerSpriteIds
	ldr r0, =gBattleAnimAttacker
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
	ldr r1, =gBattlerSpriteIds
	ldr r0, =gBattleAnimAttacker
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
	ldr r1, =gBattlerSpriteIds
	ldr r0, =gBattleAnimAttacker
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
	bl DestroyAnimVisualTask
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
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	strh r0, [r4, 0xE]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
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
	bl DestroyAnimVisualTask
_081602DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81601DC

	thumb_func_start sub_81602E0
sub_81602E0: @ 81602E0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
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
	bl DestroyAnimSprite
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
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
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
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
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
	bl DestroySpriteAndMatrix
_081604E8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81603F4

	thumb_func_start AnimTask_GetWeather
AnimTask_GetWeather: @ 81604F0
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
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	thumb_func_end AnimTask_GetWeather

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
	bl GetAnimBattlerSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x26]
	ldr r2, =gUnknown_085CE9C8
	adds r0, r4, 0
	bl PrepareAffineAnimInTaskData
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
	bl RunAffineAnimFromTaskData
	lsls r0, 24
	cmp r0, 0
	bne _08160618
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_08160618:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816058C

	.align 2, 0 @ Don't pad with nop.
