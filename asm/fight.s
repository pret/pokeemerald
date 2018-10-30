	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start unc_080B08A0
unc_080B08A0: @ 810CE2C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r0, 0
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_80A6864
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0xF
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unc_080B08A0

	thumb_func_start sub_810CE68
sub_810CE68: @ 810CE68
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0810CE90
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810CE90
	ldrh r0, [r4, 0x2]
	negs r0, r0
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x6]
	negs r0, r0
	strh r0, [r4, 0x6]
_0810CE90:
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0xC]
	adds r0, r5, 0
	bl StartSpriteAnim
	movs r0, 0
	strh r0, [r4, 0xC]
	adds r0, r5, 0
	bl sub_80A7938
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CE68

	thumb_func_start sub_810CEB4
sub_810CEB4: @ 810CEB4
	push {r4,lr}
	adds r4, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810CED0
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x2]
	negs r1, r1
	strh r1, [r0, 0x2]
	ldrh r1, [r0, 0x6]
	negs r1, r1
	strh r1, [r0, 0x6]
_0810CED0:
	adds r0, r4, 0
	bl sub_810CE68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CEB4

	thumb_func_start sub_810CEE0
sub_810CEE0: @ 810CEE0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x8]
	bl StartSpriteAnim
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810CF04
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	b _0810CF0C
	.pool
_0810CF04:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A6980
_0810CF0C:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r5, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CEE0

	thumb_func_start sub_810CF30
sub_810CF30: @ 810CF30
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r9, r0
	cmp r1, 0
	bne _0810CF54
	ldr r0, =gBattleAnimAttacker
	b _0810CF56
	.pool
_0810CF54:
	ldr r0, =gBattleAnimTarget
_0810CF56:
	ldrb r0, [r0]
	mov r8, r0
	mov r4, r9
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bge _0810CF74
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	strh r0, [r4, 0x4]
_0810CF74:
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl StartSpriteAnim
	mov r0, r8
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	mov r0, r8
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	mov r0, r8
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	lsls r1, 15
	lsrs r6, r1, 16
	mov r0, r8
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0810CFBE
	adds r0, 0x3
_0810CFBE:
	lsls r4, r0, 14
	lsrs r4, 16
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r6, 16
	asrs r1, 16
	bl __modsi3
	lsls r0, 16
	lsrs r6, r0, 16
	bl Random2
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	asrs r4, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 16
	lsrs r4, r0, 16
	bl Random2
	movs r7, 0x1
	adds r1, r7, 0
	ands r1, r0
	cmp r1, 0
	beq _0810D000
	lsls r0, r6, 16
	negs r0, r0
	lsrs r6, r0, 16
_0810D000:
	bl Random2
	adds r1, r7, 0
	ands r1, r0
	cmp r1, 0
	beq _0810D012
	lsls r0, r4, 16
	negs r0, r0
	lsrs r4, r0, 16
_0810D012:
	ldr r0, =gBattlerPositions
	add r0, r8
	ldrb r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _0810D028
	lsls r0, r4, 16
	ldr r1, =0xfff00000
	adds r0, r1
	lsrs r4, r0, 16
_0810D028:
	lsls r0, r6, 16
	asrs r0, 16
	ldrh r2, [r5, 0x20]
	adds r0, r2
	strh r0, [r5, 0x20]
	lsls r0, r4, 16
	asrs r0, 16
	ldrh r3, [r5, 0x22]
	adds r0, r3
	strh r0, [r5, 0x22]
	mov r1, r9
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x2E]
	ldr r0, =gBasicHitSplatSpriteTemplate
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r3, 0x22
	ldrsh r2, [r5, r3]
	adds r3, r5, 0
	adds r3, 0x43
	ldrb r3, [r3]
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x3C]
	cmp r0, 0x40
	beq _0810D08C
	movs r0, 0x3C
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0
	bl StartSpriteAffineAnim
	movs r2, 0x3C
	ldrsh r1, [r5, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
_0810D08C:
	ldr r0, =sub_810D0B8
	str r0, [r5, 0x1C]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810CF30

	thumb_func_start sub_810D0B8
sub_810D0B8: @ 810D0B8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _0810D100
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0x40
	beq _0810D0F4
	ldr r4, =gSprites
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	movs r0, 0x3C
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
_0810D0F4:
	adds r0, r5, 0
	bl DestroyAnimSprite
	b _0810D104
	.pool
_0810D100:
	subs r0, r1, 0x1
	strh r0, [r5, 0x2E]
_0810D104:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810D0B8

	thumb_func_start sub_810D10C
sub_810D10C: @ 810D10C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D130
	ldrh r0, [r4, 0x20]
	subs r0, 0x14
	strh r0, [r4, 0x32]
	b _0810D142
	.pool
_0810D130:
	ldrh r0, [r4, 0x20]
	adds r0, 0x14
	strh r0, [r4, 0x32]
	adds r2, r4, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_0810D142:
	ldrh r0, [r4, 0x22]
	subs r0, 0x14
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =sub_810D164
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D10C

	thumb_func_start sub_810D164
sub_810D164: @ 810D164
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x38]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r5, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _0810D1A4
	ldrh r2, [r5, 0x20]
	ldrh r4, [r5, 0x24]
	subs r0, r2, r4
	strh r0, [r5, 0x32]
	ldrh r1, [r5, 0x22]
	ldrh r3, [r5, 0x26]
	subs r0, r1, r3
	strh r0, [r5, 0x36]
	movs r0, 0x8
	strh r0, [r5, 0x2E]
	adds r2, r4
	strh r2, [r5, 0x20]
	adds r1, r3
	strh r1, [r5, 0x22]
	strh r6, [r5, 0x26]
	strh r6, [r5, 0x24]
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_0810D1A4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D164

	thumb_func_start sub_810D1B4
sub_810D1B4: @ 810D1B4
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r1, [r0]
	movs r0, 0x2
	ldr r2, =gBattleAnimTarget
	eors r0, r1
	ldrb r1, [r2]
	cmp r0, r1
	bne _0810D1E0
	ldrb r0, [r2]
	bl GetBattlerPosition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0810D1E0
	ldr r1, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	strh r0, [r1]
_0810D1E0:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810D1FE
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_0810D1FE:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x6]
	movs r5, 0
	strh r0, [r6, 0x2E]
	ldrh r0, [r6, 0x20]
	strh r0, [r6, 0x30]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrh r0, [r6, 0x22]
	strh r0, [r6, 0x34]
	strh r0, [r6, 0x36]
	adds r0, r6, 0
	bl InitAnimLinearTranslation
	ldrh r0, [r4, 0xA]
	strh r0, [r6, 0x38]
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x3A]
	strh r5, [r6, 0x3C]
	ldr r0, =sub_810D240
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D1B4

	thumb_func_start sub_810D240
sub_810D240: @ 810D240
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimLinear
	lsls r0, 24
	cmp r0, 0
	bne _0810D26C
	ldrh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	strh r0, [r4, 0x3C]
	b _0810D272
_0810D26C:
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810D272:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810D240

	thumb_func_start sub_810D278
sub_810D278: @ 810D278
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x4]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =sub_810D2B0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D278

	thumb_func_start sub_810D2B0
sub_810D2B0: @ 810D2B0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x14
	strh r0, [r4, 0x2E]
	ldr r0, =sub_80A64B0
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D2B0

	thumb_func_start sub_810D2E4
sub_810D2E4: @ 810D2E4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	strh r0, [r4, 0x2E]
	ldr r0, =sub_810D308
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D2E4

	thumb_func_start sub_810D308
sub_810D308: @ 810D308
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	subs r0, 0x1
	strh r0, [r5, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810D34C
	movs r0, 0x6
	strh r0, [r5, 0x2E]
	ldr r4, =gBattleAnimTarget
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
	ldr r0, =sub_80A6EEC
	str r0, [r5, 0x1C]
	ldr r1, =sub_810D360
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
_0810D34C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D308

	thumb_func_start sub_810D360
sub_810D360: @ 810D360
	push {lr}
	movs r1, 0xF
	strh r1, [r0, 0x2E]
	ldr r1, =sub_80A64B0
	str r1, [r0, 0x1C]
	ldr r1, =DestroyAnimSprite
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D360

	thumb_func_start sub_810D37C
sub_810D37C: @ 810D37C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810D3A8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810D404
	.pool
_0810D3A8:
	ldrh r0, [r4, 0x30]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r4, 0x24]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
	cmp r0, 0x64
	ble _0810D3F6
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	lsls r0, 1
	subs r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810D3F6:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	ble _0810D404
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810D404:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810D37C

	thumb_func_start sub_810D40C
sub_810D40C: @ 810D40C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D428
	ldr r4, =gBattleAnimAttacker
	b _0810D42A
	.pool
_0810D428:
	ldr r4, =gBattleAnimTarget
_0810D42A:
	ldrb r0, [r4]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	ldrh r2, [r5, 0x20]
	adds r0, r2
	movs r2, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r1, 0x4]
	ldrh r3, [r5, 0x22]
	adds r0, r3
	strh r0, [r5, 0x22]
	strh r2, [r5, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x32]
	strh r2, [r5, 0x34]
	ldr r0, =sub_810D47C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D40C

	thumb_func_start sub_810D47C
sub_810D47C: @ 810D47C
	push {lr}
	adds r1, r0, 0
	movs r0, 0x2E
	ldrsh r2, [r1, r0]
	cmp r2, 0
	beq _0810D48E
	cmp r2, 0x1
	beq _0810D4B2
	b _0810D4EC
_0810D48E:
	ldrh r0, [r1, 0x30]
	subs r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _0810D4EC
	movs r2, 0x32
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0810D4AA
	adds r0, r1, 0
	bl DestroyAnimSprite
	b _0810D4EC
_0810D4AA:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _0810D4EC
_0810D4B2:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0810D4DA
	movs r0, 0
	strh r0, [r1, 0x30]
	ldrh r0, [r1, 0x34]
	adds r0, 0x1
	strh r0, [r1, 0x34]
	ands r0, r2
	lsls r0, 16
	cmp r0, 0
	beq _0810D4D6
	movs r0, 0x2
	b _0810D4D8
_0810D4D6:
	ldr r0, =0x0000fffe
_0810D4D8:
	strh r0, [r1, 0x24]
_0810D4DA:
	ldrh r0, [r1, 0x32]
	subs r0, 0x1
	strh r0, [r1, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne _0810D4EC
	adds r0, r1, 0
	bl DestroyAnimSprite
_0810D4EC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D47C

	thumb_func_start sub_810D4F4
sub_810D4F4: @ 810D4F4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810D520
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r2, [r6, 0x4]
	adds r0, r2
	b _0810D532
	.pool
_0810D520:
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	adds r0, r1
_0810D532:
	strh r0, [r5, 0x20]
	ldrb r0, [r4]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r5, 0x22]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	ldr r3, =gBattleAnimArgs
	movs r4, 0x2
	ldrsh r0, [r3, r4]
	lsls r0, 4
	adds r1, r0
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	movs r1, 0
	movs r0, 0
	strh r0, [r5, 0x2E]
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	cmp r0, 0x1
	beq _0810D5A0
	cmp r0, 0x1
	bgt _0810D58C
	cmp r0, 0
	beq _0810D596
	b _0810D5C6
	.pool
_0810D58C:
	cmp r0, 0x2
	beq _0810D5B0
	cmp r0, 0x3
	beq _0810D5C0
	b _0810D5C6
_0810D596:
	ldr r0, =0x0000fffd
	b _0810D5C0
	.pool
_0810D5A0:
	movs r0, 0x3
	strh r0, [r5, 0x3A]
	ldr r0, =0x0000fffd
	strh r0, [r5, 0x3C]
	b _0810D5CE
	.pool
_0810D5B0:
	ldr r0, =0x0000fffd
	strh r0, [r5, 0x3A]
	movs r0, 0x3
	strh r0, [r5, 0x3C]
	b _0810D5CE
	.pool
_0810D5C0:
	strh r0, [r5, 0x3A]
	strh r0, [r5, 0x3C]
	b _0810D5CE
_0810D5C6:
	adds r0, r5, 0
	bl DestroyAnimSprite
	b _0810D5D2
_0810D5CE:
	ldr r0, =sub_810D5DC
	str r0, [r5, 0x1C]
_0810D5D2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D4F4

	thumb_func_start sub_810D5DC
sub_810D5DC: @ 810D5DC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x3A]
	ldrh r2, [r1, 0x20]
	adds r0, r2
	strh r0, [r1, 0x20]
	ldrh r0, [r1, 0x3C]
	ldrh r2, [r1, 0x22]
	adds r0, r2
	strh r0, [r1, 0x22]
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0810D604
	adds r0, r1, 0
	bl DestroyAnimSprite
_0810D604:
	pop {r0}
	bx r0
	thumb_func_end sub_810D5DC

	thumb_func_start sub_810D608
sub_810D608: @ 810D608
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D664
	ldr r4, =gBattlerAttacker
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
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	ldr r0, =gBattleAnimTarget
	b _0810D680
	.pool
_0810D664:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	ldr r0, =gBattleAnimAttacker
_0810D680:
	ldrb r0, [r0]
	strh r0, [r5, 0x3C]
	movs r0, 0
	strh r0, [r5, 0x2E]
	movs r0, 0xC
	strh r0, [r5, 0x30]
	movs r0, 0x8
	strh r0, [r5, 0x32]
	ldr r0, =sub_810D6A8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D608

	thumb_func_start sub_810D6A8
sub_810D6A8: @ 810D6A8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB4
	bne _0810D704
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl InitAnimLinearTranslation
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6F98
	str r0, [r4, 0x1C]
_0810D704:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D6A8

	thumb_func_start sub_810D714
sub_810D714: @ 810D714
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4]
	strh r0, [r5, 0x20]
	movs r2, 0x78
	strh r2, [r5, 0x22]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	adds r0, 0x36
	adds r1, r5, 0
	adds r1, 0x38
	lsls r2, 8
	bl sub_80A8048
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x3A]
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r1, r0
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r0, =sub_810D770
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D714

	thumb_func_start sub_810D770
sub_810D770: @ 810D770
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _0810D7C2
	movs r2, 0x36
	ldrsh r0, [r7, r2]
	movs r2, 0x38
	ldrsh r1, [r7, r2]
	bl sub_80A8050
	adds r4, r0, 0
	movs r1, 0x3A
	ldrsh r0, [r7, r1]
	subs r4, r0
	adds r0, r7, 0
	adds r0, 0x36
	adds r1, r7, 0
	adds r1, 0x38
	adds r2, r4, 0
	bl sub_80A8048
	asrs r4, 8
	strh r4, [r7, 0x22]
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x8
	negs r0, r0
	cmp r4, r0
	bge _0810D7BA
	adds r0, r7, 0
	bl DestroyAnimSprite
	b _0810D818
_0810D7BA:
	ldrh r0, [r7, 0x2E]
	subs r0, 0x1
	strh r0, [r7, 0x2E]
	b _0810D818
_0810D7C2:
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r2, =gBattleAnimTarget
	mov r8, r2
	ldrb r0, [r2]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	subs r4, r6
	strh r4, [r7, 0x2E]
	lsrs r0, 24
	subs r0, r5
	strh r0, [r7, 0x30]
	ldrh r0, [r7, 0x20]
	lsls r0, 4
	strh r0, [r7, 0x32]
	ldrh r0, [r7, 0x22]
	lsls r0, 4
	strh r0, [r7, 0x34]
	ldr r0, =sub_810D830
	str r0, [r7, 0x1C]
_0810D818:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D770

	thumb_func_start sub_810D830
sub_810D830: @ 810D830
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	ldrh r1, [r2, 0x30]
	ldrh r3, [r2, 0x34]
	adds r1, r3
	strh r1, [r2, 0x34]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r3, r1, 20
	strh r3, [r2, 0x22]
	adds r0, 0x8
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 17
	cmp r0, r1
	bhi _0810D86A
	adds r1, r3, 0
	movs r0, 0x8
	negs r0, r0
	cmp r1, r0
	blt _0810D86A
	cmp r1, 0x78
	ble _0810D870
_0810D86A:
	adds r0, r2, 0
	bl DestroyAnimSprite
_0810D870:
	pop {r0}
	bx r0
	thumb_func_end sub_810D830

	thumb_func_start sub_810D874
sub_810D874: @ 810D874
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810D8B8
	ldr r4, =gBattlerAttacker
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
	ldr r0, =gBattleAnimTarget
	ldrb r4, [r0]
	ldr r0, =gBattleAnimAttacker
	b _0810D8BE
	.pool
_0810D8B8:
	ldr r0, =gBattleAnimAttacker
	ldrb r4, [r0]
	ldr r0, =gBattleAnimTarget
_0810D8BE:
	ldrb r0, [r0]
	bl sub_80A8328
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810D8F8
	ldrb r2, [r5, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x47
	b _0810D912
	.pool
_0810D8F8:
	adds r0, r4, 0
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810D918
	ldrb r2, [r5, 0x3]
	lsls r1, r2, 26
	lsrs r1, 27
	movs r0, 0x18
	orrs r1, r0
	lsls r1, 1
	subs r0, 0x57
_0810D912:
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x3]
_0810D918:
	movs r0, 0x10
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl InitAnimLinearTranslation
	ldr r1, =DestroyAnimSprite
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =sub_80A6F98
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D874

	thumb_func_start sub_810D960
sub_810D960: @ 810D960
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0810D976
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810D976:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810D960

	thumb_func_start sub_810D984
sub_810D984: @ 810D984
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimTarget
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
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x30]
	ldrh r0, [r1]
	strh r0, [r5, 0x32]
	ldrh r0, [r1, 0x2]
	strh r0, [r5, 0x34]
	ldrh r0, [r1, 0x4]
	strh r0, [r5, 0x36]
	ldr r0, =gAnimMoveTurn
	ldrb r6, [r0]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810D9CE
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0810D9CE:
	movs r0, 0x1
	ands r6, r0
	cmp r6, 0
	beq _0810D9E2
	ldrh r0, [r5, 0x32]
	negs r0, r0
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
_0810D9E2:
	ldrh r1, [r5, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	ldrh r0, [r5, 0x32]
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x34]
	strh r0, [r5, 0x26]
	ldr r0, =sub_810D960
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810D984

	thumb_func_start sub_810DA10
sub_810DA10: @ 810DA10
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810DA2C
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	b _0810DA34
	.pool
_0810DA2C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
_0810DA34:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810DA48
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	b _0810DA5E
_0810DA48:
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DA5E
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0810DA5E:
	ldr r0, =sub_80A67D8
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DA10

	thumb_func_start sub_810DA7C
sub_810DA7C: @ 810DA7C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810DAB6
	ldrh r0, [r4, 0x30]
	adds r0, 0x28
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x2
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _0810DAB6
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810DAB6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DA7C

	thumb_func_start sub_810DABC
sub_810DABC: @ 810DABC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0810DAF4
	cmp r0, 0x1
	bgt _0810DB0E
	cmp r0, 0
	bne _0810DB0E
	movs r0, 0
	bl sub_80A6DAC
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x18]
	b _0810DB06
	.pool
_0810DAF4:
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810DB1A
_0810DB06:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810DB1A
_0810DB0E:
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r2, 0
	ldrh r1, [r4, 0x1A]
	adds r0, r1
	strh r0, [r4, 0x1A]
_0810DB1A:
	movs r2, 0xB0
	lsls r2, 4
	adds r0, r2, 0
	ldrh r1, [r4, 0x1C]
	adds r0, r1
	strh r0, [r4, 0x1C]
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810DB50
	ldr r1, =gBattle_BG3_X
	ldrh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 24
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	adds r7, r1, 0
	b _0810DB60
	.pool
_0810DB50:
	ldr r2, =gBattle_BG3_X
	ldrh r1, [r4, 0x1A]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	adds r7, r2, 0
_0810DB60:
	ldr r3, =gBattle_BG3_Y
	ldrh r2, [r4, 0x1C]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r3]
	adds r0, r1
	strh r0, [r3]
	movs r0, 0xFF
	ldrb r1, [r4, 0x1A]
	movs r5, 0
	strh r1, [r4, 0x1A]
	ands r0, r2
	strh r0, [r4, 0x1C]
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0810DB98
	strh r5, [r7]
	strh r5, [r3]
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_0810DB98:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DABC

	.align 2, 0
