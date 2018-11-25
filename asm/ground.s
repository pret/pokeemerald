	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8114994
sub_8114994: @ 8114994
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	ldr r5, =gBattleAnimTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl InitAnimArcTranslation
	ldr r0, =sub_81149FC
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114994

	thumb_func_start sub_81149FC
sub_81149FC: @ 81149FC
	push {r4,r5,lr}
	adds r5, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _08114A50
	ldrh r0, [r5, 0x24]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x26]
	ldrh r2, [r5, 0x22]
	adds r0, r2
	strh r0, [r5, 0x22]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x24]
	movs r0, 0x14
	strh r0, [r5, 0x2E]
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	movs r0, 0x28
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl InitAnimArcTranslation
	ldr r0, =sub_8114A60
	str r0, [r5, 0x1C]
_08114A50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81149FC

	thumb_func_start sub_8114A60
sub_8114A60: @ 8114A60
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _08114A74
	adds r0, r4, 0
	bl DestroyAnimSprite
_08114A74:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8114A60

	thumb_func_start sub_8114A7C
sub_8114A7C: @ 8114A7C
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08114A9C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_08114A9C:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldr r5, =gBattleAnimTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x6]
	adds r0, r4
	strh r0, [r6, 0x36]
	ldr r0, =StartAnimLinearTranslation
	str r0, [r6, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114A7C

	thumb_func_start sub_8114AF0
sub_8114AF0: @ 8114AF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	movs r1, 0x1
	bl InitAnimSpritePos
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord2
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord2
	lsls r0, 24
	lsrs r7, r0, 24
	bl Random2
	movs r4, 0x1F
	adds r5, r4, 0
	ands r5, r0
	bl Random2
	ands r4, r0
	adds r1, r5, 0
	cmp r1, 0x10
	ble _08114B38
	movs r0, 0x10
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
_08114B38:
	lsls r0, r4, 16
	asrs r1, r0, 16
	cmp r1, 0x10
	ble _08114B48
	movs r0, 0x10
	subs r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
_08114B48:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r6, 0x2E]
	mov r1, r8
	adds r0, r1, r5
	strh r0, [r6, 0x32]
	adds r0, r7, r4
	strh r0, [r6, 0x36]
	ldr r0, =StartAnimLinearTranslation
	str r0, [r6, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114AF0

	thumb_func_start sub_8114B80
sub_8114B80: @ 8114B80
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x1
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08114BF4
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r6, 0x2]
	adds r0, r2
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r3, [r6, 0x4]
	adds r0, r3
	strh r0, [r5, 0x22]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	cmp r0, 0
	ble _08114BDA
	movs r1, 0x1
_08114BDA:
	strh r1, [r5, 0x2E]
	ldr r0, =sub_8114C10
	b _08114C02
	.pool
_08114BF4:
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x20]
	ldrh r0, [r6, 0x4]
	strh r0, [r5, 0x22]
	negs r0, r0
	strh r0, [r5, 0x26]
	ldr r0, =sub_8114C4C
_08114C02:
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114B80

	thumb_func_start sub_8114C10
sub_8114C10: @ 8114C10
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08114C2E
	movs r0, 0
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r2, 0x20]
_08114C2E:
	ldrh r0, [r2, 0x22]
	subs r0, 0x4
	strh r0, [r2, 0x22]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x4
	negs r1, r1
	cmp r0, r1
	bge _08114C46
	adds r0, r2, 0
	bl DestroyAnimSprite
_08114C46:
	pop {r0}
	bx r0
	thumb_func_end sub_8114C10

	thumb_func_start sub_8114C4C
sub_8114C4C: @ 8114C4C
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _08114C5E
	cmp r1, 0x1
	beq _08114C74
	b _08114CB6
_08114C5E:
	ldrh r0, [r3, 0x26]
	adds r0, 0x4
	strh r0, [r3, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _08114CB6
	strh r1, [r3, 0x26]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _08114CB6
_08114C74:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	cmp r0, 0
	ble _08114CB6
	movs r0, 0
	strh r0, [r3, 0x30]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r2, [r1]
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
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08114CB6
	adds r0, r3, 0
	bl DestroyAnimSprite
_08114CB6:
	pop {r0}
	bx r0
	thumb_func_end sub_8114C4C

	thumb_func_start sub_8114CBC
sub_8114CBC: @ 8114CBC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r1, r0, r1
	ldr r0, =gBattleAnimArgs
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _08114CE8
	ldr r0, =sub_8114CFC
	b _08114CEA
	.pool
_08114CE8:
	ldr r0, =sub_8114EB4
_08114CEA:
	str r0, [r1]
	ldr r1, [r1]
	adds r0, r2, 0
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114CBC

	thumb_func_start sub_8114CFC
sub_8114CFC: @ 8114CFC
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
	bls _08114D16
	b _08114EAA
_08114D16:
	lsls r0, 2
	ldr r1, =_08114D28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08114D28:
	.4byte _08114D3C
	.4byte _08114DC4
	.4byte _08114DD4
	.4byte _08114E78
	.4byte _08114E8C
_08114D3C:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl sub_80A8364
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1E]
	cmp r0, 0x1
	bne _08114D70
	ldr r0, =gBattle_BG1_X
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	ldr r0, =gBattle_BG1_Y
	b _08114D78
	.pool
_08114D70:
	ldr r0, =gBattle_BG2_X
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	ldr r0, =gBattle_BG2_Y
_08114D78:
	ldrh r0, [r0]
	strh r0, [r4, 0x22]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerYCoordWithElevation
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r4, 0x24]
	adds r0, 0x20
	strh r0, [r4, 0x26]
	cmp r1, 0
	bge _08114D9A
	movs r0, 0
	strh r0, [r4, 0x24]
_08114D9A:
	ldr r2, =gSprites
	movs r3, 0x1C
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08114E7E
	.pool
_08114DC4:
	ldrb r0, [r4, 0x1E]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	movs r3, 0x26
	ldrsh r2, [r4, r3]
	bl sub_81150E0
	b _08114E7E
_08114DD4:
	ldrh r0, [r4, 0xC]
	adds r0, 0x6
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08114DF6
	movs r0, 0
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
_08114DF6:
	ldr r1, =gSineTable
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 20
	ldrh r3, [r4, 0xE]
	adds r2, r0, r3
	strh r2, [r4, 0x12]
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08114E20
	ldr r1, =gBattle_BG1_Y
	b _08114E22
	.pool
_08114E20:
	ldr r1, =gBattle_BG2_Y
_08114E22:
	ldrh r0, [r4, 0x22]
	subs r0, r2
	strh r0, [r1]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0x3F
	ble _08114EAA
	ldrh r0, [r4, 0x24]
	movs r1, 0x78
	subs r2, r1, r0
	strh r2, [r4, 0x12]
	movs r3, 0x1E
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _08114E4C
	ldr r1, =gBattle_BG1_Y
	b _08114E4E
	.pool
_08114E4C:
	ldr r1, =gBattle_BG2_Y
_08114E4E:
	ldrh r0, [r4, 0x22]
	subs r0, r2
	strh r0, [r1]
	ldr r2, =gSprites
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x20]
	movs r3, 0x88
	lsls r3, 1
	adds r0, r3, 0
	subs r0, r2
	strh r0, [r1, 0x24]
	b _08114E7E
	.pool
_08114E78:
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08114E7E:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08114EAA
	.pool
_08114E8C:
	adds r0, r2, 0
	bl DestroyAnimVisualTask
	ldr r2, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08114EAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114CFC

	thumb_func_start sub_8114EB4
sub_8114EB4: @ 8114EB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r3]
	movs r4, 0
	strh r4, [r1, 0x24]
	strh r4, [r1, 0x26]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl sub_80A8364
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08114F00
	ldr r0, =gBattle_BG1_Y
	b _08114F02
	.pool
_08114F00:
	ldr r0, =gBattle_BG2_Y
_08114F02:
	strh r4, [r0]
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114EB4

	thumb_func_start sub_8114F14
sub_8114F14: @ 8114F14
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r1, r0, r1
	ldr r0, =gBattleAnimArgs
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _08114F40
	ldr r0, =sub_8114F54
	b _08114F42
	.pool
_08114F40:
	ldr r0, =sub_8114FD8
_08114F42:
	str r0, [r1]
	ldr r1, [r1]
	adds r0, r2, 0
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8114F14

	thumb_func_start sub_8114F54
sub_8114F54: @ 8114F54
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
	cmp r5, 0
	beq _08114F78
	cmp r5, 0x1
	beq _08114FCC
	b _08114FD2
	.pool
_08114F78:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldr r3, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
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
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r5, [r0, 0x24]
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r2, [r1, 0x22]
	movs r0, 0xA0
	subs r0, r2
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08114FD2
	.pool
_08114FCC:
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_08114FD2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8114F54

	thumb_func_start sub_8114FD8
sub_8114FD8: @ 8114FD8
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
	bhi _081150DA
	lsls r0, 2
	ldr r1, =_08115004
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08115004:
	.4byte _08115018
	.4byte _0811506C
	.4byte _0811507A
	.4byte _08115094
	.4byte _081150D4
_08115018:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1C]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl sub_80A8364
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1E]
	cmp r0, 0x1
	bne _08115044
	ldr r0, =gBattle_BG1_X
	b _08115046
	.pool
_08115044:
	ldr r0, =gBattle_BG2_X
_08115046:
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerYCoordWithElevation
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r1, 0x20
	strh r1, [r4, 0x24]
	adds r0, 0x20
	strh r0, [r4, 0x26]
	b _081150C2
	.pool
_0811506C:
	ldrb r0, [r4, 0x1E]
	movs r1, 0x26
	ldrsh r2, [r4, r1]
	movs r1, 0
	bl sub_81150E0
	b _081150C2
_0811507A:
	ldr r2, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x60
	strh r1, [r0, 0x26]
	b _081150C2
	.pool
_08115094:
	ldr r2, =gSprites
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x8
	strh r1, [r0, 0x26]
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081150DA
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
_081150C2:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081150DA
	.pool
_081150D4:
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_081150DA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8114FD8

	thumb_func_start sub_81150E0
sub_81150E0: @ 81150E0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	cmp r0, 0x1
	bne _08115104
	ldr r0, =gBattle_BG1_X
	ldrh r3, [r0]
	ldr r0, =0x04000014
	b _0811510A
	.pool
_08115104:
	ldr r0, =gBattle_BG2_X
	ldrh r3, [r0]
	ldr r0, =0x04000018
_0811510A:
	str r0, [sp]
	lsls r0, r1, 16
	cmp r0, 0
	bge _08115114
	movs r1, 0
_08115114:
	lsls r2, r1, 16
	lsls r0, r4, 16
	asrs r4, r0, 16
	cmp r2, r0
	bge _08115140
	ldr r5, =gScanlineEffectRegBuffers
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_08115126:
	asrs r2, 16
	lsls r1, r2, 1
	adds r0, r1, r5
	strh r3, [r0]
	adds r1, r6
	strh r3, [r1]
	adds r2, 0x1
	lsls r2, 16
	lsrs r1, r2, 16
	lsls r2, r1, 16
	asrs r0, r2, 16
	cmp r0, r4
	blt _08115126
_08115140:
	lsls r1, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	bgt _0811516E
	ldr r4, =gScanlineEffectRegBuffers
	lsls r0, r3, 16
	asrs r0, 16
	adds r3, r0, 0
	adds r3, 0xF0
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r4, r0
_08115158:
	asrs r2, r1, 16
	lsls r1, r2, 1
	adds r0, r1, r4
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r2, 0x1
	lsls r1, r2, 16
	asrs r0, r1, 16
	cmp r0, 0x9F
	ble _08115158
_0811516E:
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
	bl ScanlineEffect_SetParams
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81150E0

	thumb_func_start sub_81151A0
sub_81151A0: @ 81151A0
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r7, r0, 0
	cmp r1, 0
	bne _081151BC
	ldr r0, =gBattleAnimAttacker
	b _081151BE
	.pool
_081151BC:
	ldr r0, =gBattleAnimTarget
_081151BE:
	ldrb r4, [r0]
	movs r6, 0x18
	adds r1, r7, 0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _081151DA
	negs r0, r6
	lsls r0, 16
	lsrs r6, r0, 16
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1, 0x4]
_081151DA:
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r0, r6
	strh r0, [r5, 0x20]
	adds r0, r4, 0
	bl GetBattlerYCoordWithElevation
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1E
	strh r0, [r5, 0x22]
	ldrh r1, [r7, 0xA]
	strh r1, [r5, 0x2E]
	ldrh r1, [r7, 0x4]
	ldrh r2, [r5, 0x20]
	adds r1, r2
	strh r1, [r5, 0x32]
	ldrh r1, [r7, 0x6]
	adds r0, r1
	strh r0, [r5, 0x36]
	ldrh r0, [r7, 0x8]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl InitAnimArcTranslation
	ldr r0, =sub_8115228
	str r0, [r5, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81151A0

	thumb_func_start sub_8115228
sub_8115228: @ 8115228
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _0811523C
	adds r0, r4, 0
	bl DestroyAnimSprite
_0811523C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8115228

	thumb_func_start sub_8115244
sub_8115244: @ 8115244
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08115260
	ldr r0, =gBattleAnimAttacker
	b _08115262
	.pool
_08115260:
	ldr r0, =gBattleAnimTarget
_08115262:
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x0000fff0
	adds r0, r2
	ldr r4, =gBattleAnimArgs
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	lsls r1, 5
	adds r0, r1
	strh r0, [r6, 0x20]
	adds r0, r5, 0
	bl GetBattlerYCoordWithElevation
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x20
	strh r0, [r6, 0x22]
	ldrh r2, [r6, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, 0x4]
	ldr r1, =DestroyAnimSprite
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	ldrh r0, [r4, 0x4]
	strh r0, [r6, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115244

	thumb_func_start sub_81152DC
sub_81152DC: @ 81152DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldr r0, =gBattleAnimArgs
	ldrh r2, [r0, 0x2]
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	adds r6, r0, 0
	cmp r1, 0
	beq _08115308
	adds r0, r2, 0x3
	b _08115314
	.pool
_08115308:
	ldr r0, =gAnimMovePower
	ldrh r0, [r0]
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0x3
_08115314:
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x24]
	adds r1, r6, 0
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0xE]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x4
	beq _08115340
	cmp r0, 0x5
	bne _08115380
	ldr r0, =gBattle_BG3_X
	ldrh r0, [r0]
	strh r0, [r4, 0x22]
	ldr r0, =sub_81153AC
	b _0811539E
	.pool
_08115340:
	movs r0, 0
	strh r0, [r4, 0x22]
	movs r5, 0
_08115346:
	lsls r0, r5, 24
	lsrs r0, 24
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _08115370
	movs r3, 0x22
	ldrsh r0, [r4, r3]
	adds r0, 0x9
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x8
	adds r1, r0
	ldr r0, =gBattlerSpriteIds
	adds r0, r5, r0
	ldrb r0, [r0]
	strh r0, [r1]
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
_08115370:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x3
	bls _08115346
	b _0811539C
	.pool
_08115380:
	ldrb r0, [r6]
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x1A]
	cmp r0, 0xFF
	bne _08115398
	adds r0, r5, 0
	bl DestroyAnimVisualTask
	b _081153A0
_08115398:
	movs r0, 0x1
	strh r0, [r4, 0x22]
_0811539C:
	ldr r0, =sub_81154A4
_0811539E:
	str r0, [r4]
_081153A0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81152DC

	thumb_func_start sub_81153AC
sub_81153AC: @ 81153AC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r3, r0, r1
	movs r0, 0x8
	ldrsh r1, [r3, r0]
	cmp r1, 0x1
	beq _08115430
	cmp r1, 0x1
	bgt _081153D4
	cmp r1, 0
	beq _081153DA
	b _0811549C
	.pool
_081153D4:
	cmp r1, 0x2
	beq _08115490
	b _0811549C
_081153DA:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811549C
	strh r1, [r3, 0xA]
	ldrh r1, [r3, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08115404
	ldr r1, =gBattle_BG3_X
	ldrh r0, [r3, 0x26]
	ldrh r2, [r3, 0x22]
	adds r0, r2
	strh r0, [r1]
	b _0811540E
	.pool
_08115404:
	ldr r0, =gBattle_BG3_X
	ldrh r1, [r3, 0x22]
	ldrh r2, [r3, 0x26]
	subs r1, r2
	strh r1, [r0]
_0811540E:
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bne _0811549C
	movs r0, 0
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x24]
	subs r0, 0x1
	strh r0, [r3, 0x24]
	b _08115484
	.pool
_08115430:
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	strh r0, [r3, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811549C
	movs r0, 0
	strh r0, [r3, 0xA]
	ldrh r0, [r3, 0xC]
	ands r1, r0
	cmp r1, 0
	bne _0811545C
	ldr r1, =gBattle_BG3_X
	ldrh r0, [r3, 0x24]
	ldrh r2, [r3, 0x22]
	adds r0, r2
	strh r0, [r1]
	b _08115466
	.pool
_0811545C:
	ldr r0, =gBattle_BG3_X
	ldrh r1, [r3, 0x22]
	ldrh r2, [r3, 0x24]
	subs r1, r2
	strh r1, [r0]
_08115466:
	ldrh r0, [r3, 0xC]
	adds r0, 0x1
	strh r0, [r3, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0811549C
	movs r0, 0
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x24]
	subs r0, 0x1
	strh r0, [r3, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0811549C
_08115484:
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	b _0811549C
	.pool
_08115490:
	ldr r1, =gBattle_BG3_X
	ldrh r0, [r3, 0x22]
	strh r0, [r1]
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_0811549C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81153AC

	thumb_func_start sub_81154A4
sub_81154A4: @ 81154A4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r5, [r4, r0]
	cmp r5, 0x1
	beq _08115504
	cmp r5, 0x1
	bgt _081154CC
	cmp r5, 0
	beq _081154D2
	b _0811557E
	.pool
_081154CC:
	cmp r5, 0x2
	beq _08115540
	b _0811557E
_081154D2:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811557E
	strh r5, [r4, 0xA]
	adds r0, r4, 0
	bl sub_8115588
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _0811557E
	strh r5, [r4, 0xC]
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	strh r0, [r4, 0x24]
	b _08115538
_08115504:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811557E
	strh r5, [r4, 0xA]
	adds r0, r4, 0
	bl sub_8115588
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0811557E
	strh r5, [r4, 0xC]
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0811557E
_08115538:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0811557E
_08115540:
	movs r2, 0
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	cmp r2, r0
	bge _08115578
	ldr r0, =gSprites
	mov r12, r0
	adds r5, r4, 0
	adds r5, 0x8
	movs r6, 0
_08115554:
	adds r0, r2, 0
	adds r0, 0x9
	lsls r0, 1
	adds r0, r5, r0
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r12
	strh r6, [r0, 0x24]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	cmp r2, r0
	blt _08115554
_08115578:
	adds r0, r3, 0
	bl DestroyAnimVisualTask
_0811557E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81154A4

	thumb_func_start sub_8115588
sub_8115588: @ 8115588
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0xC]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _081155B0
	movs r0, 0x24
	ldrsh r1, [r3, r0]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	ldrh r2, [r3, 0x24]
	adds r0, r4, 0
	ands r0, r2
	adds r1, r0
	lsls r1, 16
	lsrs r4, r1, 16
	b _081155C0
_081155B0:
	movs r1, 0x24
	ldrsh r0, [r3, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
_081155C0:
	movs r2, 0
	movs r7, 0x22
	ldrsh r0, [r3, r7]
	cmp r2, r0
	bge _081155F4
	ldr r6, =gSprites
	adds r5, r3, 0
	adds r5, 0x8
_081155D0:
	adds r0, r2, 0
	adds r0, 0x9
	lsls r0, 1
	adds r0, r5, r0
	movs r7, 0
	ldrsh r1, [r0, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r4, [r0, 0x24]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x22
	ldrsh r0, [r3, r1]
	cmp r2, r0
	blt _081155D0
_081155F4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115588

	thumb_func_start AnimTask_IsPowerOver99
AnimTask_IsPowerOver99: @ 8115600
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r3, =gBattleAnimArgs
	movs r2, 0
	ldr r0, =gAnimMovePower
	ldrh r0, [r0]
	cmp r0, 0x63
	bls _08115614
	movs r2, 0x1
_08115614:
	strh r2, [r3, 0x1E]
	adds r0, r1, 0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_IsPowerOver99

	thumb_func_start sub_8115628
sub_8115628: @ 8115628
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _08115648
	ldr r0, =gBattleAnimTarget
	b _0811564A
	.pool
_08115648:
	ldr r0, =gBattleAnimAttacker
_0811564A:
	ldrb r0, [r0]
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	ble _0811565A
	movs r0, 0x2
	eors r5, r0
_0811565A:
	ldr r0, =sub_81156D0
	ldrb r1, [r6, 0x2]
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r5, 0
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x20
	subs r1, r0
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r1, r0
	strh r1, [r4, 0xA]
	adds r0, r5, 0
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x40
	subs r1, r0
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0xC]
	ldr r2, =gBattle_BG3_X
	ldrh r0, [r4, 0xA]
	strh r0, [r2]
	ldr r0, =gBattle_BG3_Y
	strh r1, [r0]
	ldrh r0, [r6, 0x4]
	strh r0, [r4, 0xE]
	adds r0, r7, 0
	bl DestroyAnimVisualTask
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8115628

	thumb_func_start sub_81156D0
sub_81156D0: @ 81156D0
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	ldr r1, =gTasks
	adds r2, r0, r1
	ldr r0, =gBattleAnimArgs
	movs r4, 0xE
	ldrsh r1, [r0, r4]
	movs r4, 0xE
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bne _08115710
	ldr r0, =gBattle_BG3_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG3_Y
	strh r1, [r0]
	adds r0, r3, 0
	bl DestroyTask
	b _0811571C
	.pool
_08115710:
	ldr r1, =gBattle_BG3_X
	ldrh r0, [r2, 0xA]
	strh r0, [r1]
	ldr r1, =gBattle_BG3_Y
	ldrh r0, [r2, 0xC]
	strh r0, [r1]
_0811571C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81156D0

	.align 2, 0
