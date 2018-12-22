	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81136E8
sub_81136E8: @ 81136E8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =gBattleAnimArgs
	ldrh r1, [r1]
	strh r1, [r0, 0x8]
	ldr r1, =gBattleAnimAttacker
	ldrb r4, [r1]
	movs r1, 0x10
	strh r1, [r0, 0xA]
	movs r0, 0x52
	bl SetGpuReg
	adds r0, r4, 0
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08113734
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _0811373C
	.pool
_08113734:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_0811373C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_811375C
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81136E8

	thumb_func_start sub_811375C
sub_811375C: @ 811375C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0xA]
	lsrs r4, r0, 8
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	ldrb r2, [r6, 0x8]
	cmp r0, r2
	bne _081137D8
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 8
	orrs r1, r0
	movs r5, 0
	strh r1, [r6, 0xA]
	ldrh r1, [r6, 0xA]
	movs r0, 0x52
	bl SetGpuReg
	strh r5, [r6, 0xC]
	cmp r4, 0x10
	bne _081137DE
	ldr r2, =gSprites
	ldr r1, =gBattlerSpriteIds
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	adds r0, r1
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
	adds r0, r7, 0
	bl DestroyAnimVisualTask
	b _081137DE
	.pool
_081137D8:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
_081137DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811375C

	thumb_func_start sub_81137E4
sub_81137E4: @ 81137E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r2, 0x8]
	movs r1, 0x80
	lsls r1, 5
	strh r1, [r2, 0xA]
	ldr r0, =sub_811381C
	str r0, [r2]
	movs r0, 0x52
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81137E4

	thumb_func_start sub_811381C
sub_811381C: @ 811381C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0xA]
	lsrs r4, r0, 8
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	ldrb r2, [r6, 0x8]
	cmp r0, r2
	bne _0811387C
	subs r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 8
	orrs r1, r0
	movs r5, 0
	strh r1, [r6, 0xA]
	ldrh r1, [r6, 0xA]
	movs r0, 0x52
	bl SetGpuReg
	strh r5, [r6, 0xC]
	cmp r4, 0
	bne _08113882
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r7, 0
	bl DestroyAnimVisualTask
	b _08113882
	.pool
_0811387C:
	ldrh r0, [r6, 0xC]
	adds r0, 0x1
	strh r0, [r6, 0xC]
_08113882:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811381C

	thumb_func_start sub_8113888
sub_8113888: @ 8113888
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081138BC
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _081138C4
	.pool
_081138BC:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_081138C4:
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113888

	thumb_func_start sub_81138D4
sub_81138D4: @ 81138D4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gBattleAnimTarget
	ldrb r0, [r6]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x30]
	ldr r5, =gBattleAnimAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r6]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	movs r0, 0x7E
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl InitSpriteDataForLinearTranslation
	ldrh r0, [r4, 0x30]
	negs r0, r0
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x32]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x3A]
	ldr r1, =sub_8113950
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81138D4

	thumb_func_start sub_8113950
sub_8113950: @ 8113950
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r5, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	adds r2, r5, r0
	strh r2, [r4, 0x34]
	ldrh r3, [r4, 0x32]
	ldrh r6, [r4, 0x36]
	adds r1, r3, r6
	strh r1, [r4, 0x36]
	lsls r0, r2, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	lsls r0, r1, 16
	asrs r0, 24
	strh r0, [r4, 0x26]
	movs r6, 0x3C
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bne _08113992
	adds r0, r2, r5
	strh r0, [r4, 0x34]
	adds r1, r3
	strh r1, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
_08113992:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r6, [r4, 0x26]
	adds r0, r6
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	cmp r0, 0x7F
	ble _081139C2
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x14
	strh r0, [r4, 0x3A]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
_081139C2:
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bne _081139D4
	adds r0, r4, 0
	bl DestroyAnimSprite
_081139D4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8113950

	thumb_func_start sub_81139DC
sub_81139DC: @ 81139DC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	ldrb r1, [r5, 0x4]
	adds r0, r4, 0
	bl StartSpriteAffineAnim
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x30]
	ldrh r0, [r5, 0xA]
	strh r0, [r4, 0x32]
	ldr r0, =sub_8113A18
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81139DC

	thumb_func_start sub_8113A18
sub_8113A18: @ 8113A18
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x36]
	adds r0, r1
	strh r0, [r2, 0x36]
	ldrh r1, [r2, 0x30]
	ldrh r3, [r2, 0x38]
	adds r1, r3
	strh r1, [r2, 0x38]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2, 0x24]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r2, 0x26]
	ldrh r0, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x32
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bne _08113A4E
	ldr r0, =sub_8113A58
	str r0, [r2, 0x1C]
_08113A4E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113A18

	thumb_func_start sub_8113A58
sub_8113A58: @ 8113A58
	push {lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x36]
	ldrh r0, [r3, 0x2E]
	subs r1, r0
	strh r1, [r3, 0x36]
	ldrh r0, [r3, 0x38]
	ldrh r2, [r3, 0x30]
	subs r0, r2
	strh r0, [r3, 0x38]
	lsls r1, 16
	asrs r1, 24
	strh r1, [r3, 0x24]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r3, 0x26]
	ldrh r0, [r3, 0x34]
	subs r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	cmp r0, 0
	bne _08113A8A
	adds r0, r3, 0
	bl DestroySpriteAndMatrix
_08113A8A:
	pop {r0}
	bx r0
	thumb_func_end sub_8113A58

	thumb_func_start sub_8113A90
sub_8113A90: @ 8113A90
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r3, r0, 0
	cmp r1, 0
	bne _08113AAC
	ldr r0, =gBattleAnimAttacker
	b _08113AAE
	.pool
_08113AAC:
	ldr r0, =gBattleAnimTarget
_08113AAE:
	ldrb r5, [r0]
	movs r6, 0x14
	ldrh r2, [r4, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x4
	ldr r7, =0x000003ff
	adds r0, r7, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	beq _08113B0C
	cmp r0, 0x1
	bgt _08113AE8
	cmp r0, 0
	beq _08113AF2
	b _08113B60
	.pool
_08113AE8:
	cmp r0, 0x2
	beq _08113B26
	cmp r0, 0x3
	beq _08113B3E
	b _08113B60
_08113AF2:
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r4, 0x22]
	b _08113B60
_08113B0C:
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0xE
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x10
	strh r0, [r4, 0x22]
	b _08113B60
_08113B26:
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	b _08113B54
_08113B3E:
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0xE
	strh r0, [r4, 0x20]
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x10
_08113B54:
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r6, 0xEC
_08113B60:
	movs r0, 0x20
	strh r0, [r4, 0x2E]
	lsls r0, r6, 24
	asrs r0, 24
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	adds r0, 0xC
	strh r0, [r4, 0x36]
	ldr r0, =0x0000fff4
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl InitAnimArcTranslation
	ldr r0, =sub_8113B90
	str r0, [r4, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113A90

	thumb_func_start sub_8113B90
sub_8113B90: @ 8113B90
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _08113BA4
	adds r0, r4, 0
	bl DestroySpriteAndMatrix
_08113BA4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8113B90

	thumb_func_start sub_8113BAC
sub_8113BAC: @ 8113BAC
	push {r4-r7,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1F
	movs r6, 0
	strh r0, [r5, 0x16]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	subs r0, 0x7
	strh r0, [r5, 0x14]
	ldrh r1, [r5, 0x16]
	strh r1, [r5, 0x12]
	strh r0, [r5, 0x10]
	subs r1, r0
	lsls r1, 8
	strh r1, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r5, 0x24]
	adds r0, 0x20
	strh r0, [r5, 0x26]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _08113C1C
	ldr r0, =0x0000fff4
	b _08113C1E
	.pool
_08113C1C:
	ldr r0, =0x0000ffc0
_08113C1E:
	strh r0, [r5, 0x18]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	cmp r0, 0x1
	bne _08113C80
	add r4, sp, 0xC
	adds r0, r4, 0
	bl sub_80A6B30
	ldr r0, =gBattle_BG1_Y
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldrb r1, [r4, 0x8]
	lsls r1, 4
	movs r0, 0
	movs r2, 0x20
	bl FillPalette
	ldr r0, =0x04000016
	str r0, [sp]
	movs r7, 0x2
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08113CB0
	ldr r1, =gBattle_BG2_X
	b _08113CAA
	.pool
_08113C80:
	ldr r0, =gBattle_BG2_Y
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0
	movs r1, 0x90
	movs r2, 0x20
	bl FillPalette
	ldr r0, =0x0400001a
	str r0, [sp]
	movs r7, 0x4
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08113CB0
	ldr r1, =gBattle_BG1_X
_08113CAA:
	ldrh r0, [r1]
	adds r0, 0xF0
	strh r0, [r1]
_08113CB0:
	ldr r0, =0xa2600001
	str r0, [sp, 0x4]
	mov r2, sp
	movs r1, 0
	movs r0, 0x1
	strb r0, [r2, 0x8]
	mov r0, sp
	strb r1, [r0, 0x9]
	strh r1, [r5, 0x1E]
	movs r0, 0x10
	strh r0, [r5, 0x20]
	strh r1, [r5, 0x8]
	strh r1, [r5, 0xA]
	strh r1, [r5, 0xC]
	movs r0, 0x3
	bl sub_8114374
	movs r3, 0
	ldr r4, =gScanlineEffectRegBuffers
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r4, r0
_08113CDC:
	lsls r1, r3, 1
	adds r2, r1, r4
	ldrh r0, [r5, 0x1C]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r5, 0x1C]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x6F
	bls _08113CDC
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	movs r0, 0x3F
	eors r7, r0
	movs r1, 0xFC
	lsls r1, 6
	adds r0, r1, 0
	orrs r7, r0
	movs r0, 0x4A
	adds r1, r7, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r2, =gBattle_WIN0H
	ldrh r0, [r5, 0x24]
	lsls r0, 8
	ldrh r1, [r5, 0x26]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, =gBattle_WIN0V
	movs r0, 0xA0
	strh r0, [r1]
	ldr r0, =sub_8113D60
	str r0, [r5]
	add sp, 0x1C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113BAC

	thumb_func_start sub_8113D60
sub_8113D60: @ 8113D60
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bls _08113D7A
	b _08113E72
_08113D7A:
	lsls r0, 2
	ldr r1, =_08113D8C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08113D8C:
	.4byte _08113DA0
	.4byte _08113E02
	.4byte _08113E1C
	.4byte _08113E58
	.4byte _08113E6C
_08113DA0:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08113E72
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08113DD0
	ldrh r1, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	cmp r0, 0xC
	beq _08113DDE
	adds r0, r1, 0x1
	strh r0, [r4, 0x1E]
	b _08113DDE
_08113DD0:
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	beq _08113DDE
	subs r0, r1, 0x1
	strh r0, [r4, 0x20]
_08113DDE:
	ldrh r1, [r4, 0x20]
	lsls r1, 8
	ldrh r0, [r4, 0x1E]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _08113E72
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x8
	bne _08113E72
	b _08113E5E
_08113E02:
	ldrh r0, [r4, 0x10]
	subs r0, 0x8
	strh r0, [r4, 0x10]
	adds r0, r4, 0
	bl sub_8114244
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _08113E72
	b _08113E5E
_08113E1C:
	ldrh r0, [r4, 0x10]
	subs r0, 0x8
	strh r0, [r4, 0x10]
	adds r0, r4, 0
	bl sub_8114244
	ldrh r1, [r4, 0x24]
	adds r1, 0x4
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r2, r0, 0x4
	strh r2, [r4, 0x26]
	lsls r1, 16
	lsls r0, r2, 16
	cmp r1, r0
	blt _08113E3E
	strh r2, [r4, 0x24]
_08113E3E:
	ldr r3, =gBattle_WIN0H
	ldrh r2, [r4, 0x24]
	lsls r0, r2, 8
	ldrh r1, [r4, 0x26]
	orrs r0, r1
	strh r0, [r3]
	lsls r2, 16
	lsls r1, 16
	cmp r2, r1
	bne _08113E72
	b _08113E5E
	.pool
_08113E58:
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08113E5E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08113E72
	.pool
_08113E6C:
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_08113E72:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8113D60

	thumb_func_start sub_8113E78
sub_8113E78: @ 8113E78
	push {r4-r7,lr}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x4
	bls _08113E94
	b _081140A6
_08113E94:
	lsls r0, 2
	ldr r1, =_08113EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08113EA8:
	.4byte _08113EBC
	.4byte _08113F40
	.4byte _08113F84
	.4byte _08113FF0
	.4byte _08114058
_08113EBC:
	bl IsContest
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08113EF8
	ldr r0, =gBattle_WIN0H
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	adds r0, r6, 0
	bl DestroyAnimVisualTask
	b _081140A6
	.pool
_08113EF8:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xE]
	cmp r0, 0x1
	bne _08113F24
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =gBattle_BG2_X
	b _08113F2E
	.pool
_08113F24:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =gBattle_BG1_X
_08113F2E:
	ldrh r0, [r1]
	adds r0, 0xF0
	strh r0, [r1]
	b _08114044
	.pool
_08113F40:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08113F68
	mov r0, sp
	bl sub_80A6B30
	ldr r0, =gBattle_BG1_Y
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	mov r0, sp
	ldrb r1, [r0, 0x8]
	lsls r1, 4
	movs r0, 0
	movs r2, 0x20
	bl FillPalette
	b _08113F78
	.pool
_08113F68:
	ldr r0, =gBattle_BG2_Y
	ldrh r0, [r0]
	strh r0, [r5, 0x1C]
	movs r0, 0
	movs r1, 0x90
	movs r2, 0x20
	bl FillPalette
_08113F78:
	movs r0, 0x3
	bl sub_8114374
	b _08114044
	.pool
_08113F84:
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1F
	movs r6, 0
	strh r0, [r5, 0x16]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	subs r0, 0x7
	strh r0, [r5, 0x14]
	ldrh r1, [r5, 0x16]
	subs r1, r0
	lsls r1, 8
	strh r1, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	subs r1, r0, 0x4
	strh r1, [r5, 0x24]
	adds r0, 0x4
	strh r0, [r5, 0x26]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _08113FD8
	ldr r0, =0x0000fff4
	b _08113FDA
	.pool
_08113FD8:
	ldr r0, =0x0000ffc0
_08113FDA:
	strh r0, [r5, 0x18]
	ldrh r0, [r5, 0x18]
	strh r0, [r5, 0x10]
	strh r0, [r5, 0x12]
	movs r0, 0xC
	strh r0, [r5, 0x1E]
	movs r0, 0x8
	strh r0, [r5, 0x20]
	b _08114044
	.pool
_08113FF0:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08114000
	ldr r0, =0x04000016
	b _08114002
	.pool
_08114000:
	ldr r0, =0x0400001a
_08114002:
	str r0, [sp, 0x10]
	movs r3, 0
	add r4, sp, 0x10
	ldr r6, =gScanlineEffectRegBuffers
	movs r0, 0xF0
	lsls r0, 3
	adds r7, r6, r0
_08114010:
	lsls r1, r3, 1
	adds r2, r1, r6
	ldrh r0, [r5, 0x1C]
	adds r0, 0x9F
	subs r0, r3
	strh r0, [r2]
	adds r1, r7
	ldrh r0, [r5, 0x1C]
	adds r0, 0x9F
	subs r0, r3
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x6F
	bls _08114010
	ldr r1, =0xa2600001
	str r1, [r4, 0x4]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r4, 0x8]
	strb r2, [r4, 0x9]
	ldr r0, [sp, 0x10]
	ldr r2, [r4, 0x8]
	bl ScanlineEffect_SetParams
_08114044:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _081140A6
	.pool
_08114058:
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08114070
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	b _08114078
	.pool
_08114070:
	ldr r1, =0x00003f3b
	movs r0, 0x4A
	bl SetGpuReg
_08114078:
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r2, =gBattle_WIN0H
	ldrh r0, [r5, 0x24]
	lsls r0, 8
	ldrh r1, [r5, 0x26]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, =gBattle_WIN0V
	movs r0, 0xA0
	strh r0, [r1]
	movs r0, 0
	strh r0, [r5, 0x8]
	strh r0, [r5, 0xA]
	strh r0, [r5, 0xC]
	ldr r1, =0x0000080c
	movs r0, 0x52
	bl SetGpuReg
	ldr r0, =sub_81140C8
	str r0, [r5]
_081140A6:
	add sp, 0x1C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8113E78

	thumb_func_start sub_81140C8
sub_81140C8: @ 81140C8
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
	cmp r0, 0x4
	bls _081140E2
	b _08114232
_081140E2:
	lsls r0, 2
	ldr r1, =_081140F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081140F4:
	.4byte _08114108
	.4byte _08114134
	.4byte _0811419C
	.4byte _081141FE
	.4byte _08114210
_08114108:
	ldrh r0, [r4, 0x12]
	adds r0, 0x8
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0x16]
	movs r3, 0x16
	ldrsh r1, [r4, r3]
	cmp r0, r1
	blt _0811411E
	strh r2, [r4, 0x12]
_0811411E:
	adds r0, r4, 0
	bl sub_8114244
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r1, r0
	beq _08114132
	b _08114232
_08114132:
	b _08114204
_08114134:
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	subs r0, r1
	cmp r0, 0x3F
	bgt _08114150
	ldrh r0, [r4, 0x24]
	subs r0, 0x4
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	adds r0, 0x4
	strh r0, [r4, 0x26]
	b _08114154
_08114150:
	movs r0, 0x1
	strh r0, [r4, 0xA]
_08114154:
	ldr r2, =gBattle_WIN0H
	ldrh r0, [r4, 0x24]
	lsls r0, 8
	ldrh r1, [r4, 0x26]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x10]
	adds r0, 0x8
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	ldrh r2, [r4, 0x14]
	movs r3, 0x14
	ldrsh r1, [r4, r3]
	cmp r0, r1
	blt _08114176
	strh r2, [r4, 0x10]
_08114176:
	adds r0, r4, 0
	bl sub_8114244
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08114232
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08114232
	movs r0, 0
	strh r0, [r4, 0xA]
	b _08114204
	.pool
_0811419C:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08114232
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081141CC
	ldrh r1, [r4, 0x1E]
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081141DA
	subs r0, r1, 0x1
	strh r0, [r4, 0x1E]
	b _081141DA
_081141CC:
	ldrh r1, [r4, 0x20]
	movs r3, 0x20
	ldrsh r0, [r4, r3]
	cmp r0, 0xF
	bgt _081141DA
	adds r0, r1, 0x1
	strh r0, [r4, 0x20]
_081141DA:
	ldrh r1, [r4, 0x20]
	lsls r1, 8
	ldrh r0, [r4, 0x1E]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08114232
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bne _08114232
	b _08114204
_081141FE:
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08114204:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08114232
	.pool
_08114210:
	ldr r0, =gBattle_WIN0H
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08114232:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81140C8

	thumb_func_start sub_8114244
sub_8114244: @ 8114244
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldrh r0, [r6, 0x12]
	ldrh r4, [r6, 0x10]
	subs r0, r4
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	beq _08114338
	movs r2, 0x22
	ldrsh r0, [r6, r2]
	bl __divsi3
	mov r8, r0
	movs r3, 0x14
	ldrsh r0, [r6, r3]
	lsls r5, r0, 8
	lsls r0, r4, 16
	movs r4, 0
	cmp r0, 0
	ble _081142A4
	ldr r0, =gScanlineEffectRegBuffers
	mov r12, r0
	ldr r7, =gScanlineEffect
_08114278:
	lsls r2, r4, 16
	asrs r2, 16
	lsls r3, r2, 1
	ldrb r1, [r7, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r3, r0
	add r3, r12
	adds r1, r2, 0
	subs r1, 0x9F
	ldrh r0, [r6, 0x1C]
	subs r0, r1
	strh r0, [r3]
	adds r2, 0x1
	lsls r2, 16
	lsrs r4, r2, 16
	asrs r2, 16
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	cmp r2, r0
	blt _08114278
_081142A4:
	ldrh r4, [r6, 0x10]
	lsls r3, r4, 16
	asrs r1, r3, 16
	movs r2, 0x12
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bgt _081142EE
	ldr r0, =gScanlineEffectRegBuffers
	mov r12, r0
	ldr r7, =gScanlineEffect
_081142B8:
	asrs r4, r3, 16
	cmp r4, 0
	blt _081142DA
	asrs r1, r5, 8
	subs r1, r4
	lsls r3, r4, 1
	ldrb r2, [r7, 0x14]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 7
	adds r3, r0
	add r3, r12
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r6, 0x1C]
	adds r1, r2
	strh r1, [r3]
_081142DA:
	add r5, r8
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r3, r4, 16
	asrs r1, r3, 16
	movs r2, 0x12
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _081142B8
_081142EE:
	movs r3, 0x1C
	ldrsh r0, [r6, r3]
	adds r0, 0x9F
	lsls r2, r4, 16
	asrs r1, r2, 16
	subs r5, r0, r1
	movs r3, 0x16
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bge _08114366
	ldr r7, =gScanlineEffectRegBuffers
	ldr r4, =gScanlineEffect
_08114306:
	asrs r3, r2, 16
	cmp r3, 0
	blt _0811431E
	lsls r2, r3, 1
	ldrb r1, [r4, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 7
	adds r2, r0
	adds r2, r7
	strh r5, [r2]
	subs r5, 0x1
_0811431E:
	adds r0, r3, 0x1
	lsls r2, r0, 16
	asrs r1, r2, 16
	movs r3, 0x16
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08114306
	b _08114366
	.pool
_08114338:
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	adds r5, r0, 0
	adds r5, 0x9F
	movs r4, 0
	ldr r3, =gScanlineEffectRegBuffers
	movs r2, 0xF0
	lsls r2, 3
	adds r6, r3, r2
_0811434A:
	lsls r0, r4, 16
	asrs r0, 16
	lsls r2, r0, 1
	adds r1, r2, r3
	strh r5, [r1]
	adds r2, r6
	strh r5, [r2]
	subs r5, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	ble _0811434A
_08114366:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114244

	thumb_func_start sub_8114374
sub_8114374: @ 8114374
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0
	ldr r7, =gSprites
	movs r1, 0x3
	ands r0, r1
	lsls r5, r0, 2
	movs r0, 0xD
	negs r0, r0
	adds r6, r0, 0
_0811438A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _081143AA
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r0, [r1, 0x5]
	ands r0, r6
	orrs r0, r5
	strb r0, [r1, 0x5]
_081143AA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _0811438A
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114374

	thumb_func_start sub_81143C0
sub_81143C0: @ 81143C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r6, =gBattleAnimAttacker
	ldrb r0, [r6]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	ldrb r0, [r6]
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80A438C
	ldr r0, =gSprites
	mov r9, r0
	ldr r0, =gBattlerSpriteIds
	mov r8, r0
	ldrb r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r9
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r7, 0x5
	negs r7, r7
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r6]
	movs r5, 0x2
	eors r0, r5
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0811444E
	ldrb r0, [r6]
	eors r0, r5
	movs r1, 0x1
	eors r4, r1
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80A438C
	ldrb r0, [r6]
	eors r0, r5
	add r0, r8
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r7, 0
	ands r1, r2
	strb r1, [r0]
_0811444E:
	mov r0, r10
	bl DestroyAnimVisualTask
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81143C0

	thumb_func_start sub_8114470
sub_8114470: @ 8114470
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r5, r1, 31
	adds r0, r5, 0
	bl sub_80A477C
	ldrb r1, [r4]
	movs r0, 0x2
	eors r0, r1
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _081144AC
	movs r0, 0x1
	eors r5, r0
	adds r0, r5, 0
	bl sub_80A477C
_081144AC:
	adds r0, r6, 0
	bl DestroyAnimVisualTask
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114470

	thumb_func_start sub_81144BC
sub_81144BC: @ 81144BC
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	ldrb r1, [r1, 0x4]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =RunStoredCallbackWhenAnimEnds
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81144BC

	thumb_func_start sub_81144F8
sub_81144F8: @ 81144F8
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	ldr r0, =gBattle_WIN0H
	strh r6, [r0]
	ldr r0, =gBattle_WIN0V
	strh r6, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000c08
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0
	bl SetAnimBgAttribute
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0811455C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetAnimBgAttribute
_0811455C:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _081145D6
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _081145D6
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0811458C
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, 24
	cmp r0, 0
	bne _081145D6
_0811458C:
	ldrb r0, [r4]
	movs r5, 0x2
	eors r0, r5
	bl IsBattlerSpriteVisible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081145D6
	ldr r3, =gSprites
	ldr r1, =gBattlerSpriteIds
	ldrb r0, [r4]
	eors r0, r5
	adds r0, r1
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0x1
	bl SetAnimBgAttribute
	movs r6, 0x1
_081145D6:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _08114614
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrh r5, [r0]
	b _0811465C
	.pool
_08114614:
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08114640
	ldr r1, =gBattlerPartyIndexes
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _08114650
	.pool
_08114640:
	ldr r1, =gBattlerPartyIndexes
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_08114650:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
_0811465C:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A89C8
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C1D210
	bl sub_80A6D48
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C1D0AC
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C1D1E8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r2, =gBattle_BG1_X
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x20]
	negs r0, r0
	adds r0, 0x60
	strh r0, [r2]
	ldr r2, =gBattle_BG1_Y
	ldrh r0, [r1, 0x22]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r2]
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	adds r1, r0, 0
	ldr r2, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _08114708
	adds r0, r1, 0
	movs r1, 0
	bl SetGreyscaleOrOriginalPalette
	b _08114714
	.pool
_08114708:
	lsls r0, r1, 4
	ldrh r3, [r2, 0x4]
	movs r1, 0x10
	movs r2, 0xB
	bl BlendPalette
_08114714:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	strh r1, [r0, 0xA]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0xC]
	ldrh r1, [r2, 0x4]
	strh r1, [r0, 0xE]
	strh r6, [r0, 0x14]
	ldr r1, =sub_8114748
	str r1, [r0]
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81144F8

	thumb_func_start sub_8114748
sub_8114748: @ 8114748
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r0, 0x4
	movs r5, 0
	strh r0, [r4, 0x1C]
	ldr r2, =gBattle_BG1_X
	ldrh r3, [r2]
	subs r1, r3, 0x4
	strh r1, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x80
	beq _08114776
	b _08114886
_08114776:
	strh r5, [r4, 0x1C]
	adds r0, r3, 0
	adds r0, 0x7C
	strh r0, [r2]
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _08114824
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	adds r1, r0, 0
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081147B8
	adds r0, r1, 0
	movs r1, 0x1
	bl SetGreyscaleOrOriginalPalette
_081147B8:
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08114886
	ldr r2, =gBattlerSpriteIds
	ldr r0, =gBattleAnimAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	adds r0, r2
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r5
	ldrb r3, [r2, 0x5]
	lsls r1, r3, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	b _08114886
	.pool
_08114824:
	cmp r0, 0x3
	bne _08114886
	ldr r0, =gBattle_WIN0H
	strh r5, [r0]
	ldr r0, =gBattle_WIN0V
	strh r5, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08114856
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl SetAnimBgAttribute
_08114856:
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
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_08114886:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114748

	thumb_func_start sub_811489C
sub_811489C: @ 811489C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r2, r0, 0
	cmp r1, 0x7
	bhi _08114900
	lsls r0, r1, 2
	ldr r1, =_081148C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081148C4:
	.4byte _081148E4
	.4byte _081148E4
	.4byte _081148E4
	.4byte _081148E4
	.4byte _081148F0
	.4byte _081148F4
	.4byte _081148F8
	.4byte _081148FC
_081148E4:
	ldrb r0, [r2]
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r2, r0, 24
	b _08114902
_081148F0:
	movs r4, 0
	b _08114908
_081148F4:
	movs r4, 0x2
	b _08114908
_081148F8:
	movs r4, 0x1
	b _08114908
_081148FC:
	movs r4, 0x3
	b _08114908
_08114900:
	movs r2, 0xFF
_08114902:
	movs r0, 0
	cmp r0, 0
	beq _0811492E
_08114908:
	adds r0, r4, 0
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0811492C
	ldr r0, =gBattlerSpriteIds
	adds r0, r4, r0
	ldrb r2, [r0]
	b _0811492E
	.pool
_0811492C:
	movs r2, 0xFF
_0811492E:
	cmp r2, 0xFF
	beq _0811494A
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	adds r0, 0x10
	ldr r1, =gBattleAnimArgs
	ldrb r1, [r1, 0x2]
	bl SetGreyscaleOrOriginalPalette
_0811494A:
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811489C

	thumb_func_start sub_8114960
sub_8114960: @ 8114960
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gAnimMoveTurn
	ldrb r0, [r2]
	cmp r0, 0x1
	bhi _08114974
	ldr r1, =gBattleAnimArgs
	movs r0, 0
	strh r0, [r1, 0xE]
_08114974:
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _08114980
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	strh r0, [r1, 0xE]
_08114980:
	adds r0, r3, 0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114960

	.align 2, 0
