	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_810DE70
sub_810DE70: @ 810DE70
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl InitSpritePosToAnimTarget
	ldrh r0, [r4, 0x22]
	adds r0, 0x14
	strh r0, [r4, 0x22]
	movs r0, 0xBF
	strh r0, [r4, 0x30]
	ldr r1, =sub_810DE98
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DE70

	thumb_func_start sub_810DE98
sub_810DE98: @ 810DE98
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x20
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x5
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x47
	bne _0810DED2
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810DED2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DE98

	thumb_func_start sub_810DED8
sub_810DED8: @ 810DED8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x8]
	ldrh r0, [r1]
	strh r0, [r4, 0xA]
	ldr r0, =0x00002719
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	ldr r0, =sub_810DF18
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DED8

	thumb_func_start sub_810DF18
sub_810DF18: @ 810DF18
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r3, 0x1C]
	lsls r0, 16
	asrs r0, 16
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	adds r7, r2, 0
	cmp r0, r1
	bne _0810DF76
	movs r0, 0
	strh r0, [r3, 0x1C]
	ldrb r0, [r3, 0xC]
	ldr r2, =gPlttBufferFaded
	lsls r0, 4
	movs r3, 0x84
	lsls r3, 1
	adds r1, r0, r3
	lsls r1, 1
	adds r1, r2
	ldrh r6, [r1]
	movs r4, 0x7
	mov r12, r0
	ldr r0, =0x00000107
	add r0, r12
	lsls r0, 1
	adds r3, r0, r2
_0810DF5E:
	ldrh r0, [r3]
	strh r0, [r1]
	subs r3, 0x2
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bgt _0810DF5E
	ldr r0, =0x00000101
	add r0, r12
	lsls r0, 1
	adds r0, r2
	strh r6, [r0]
_0810DF76:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r7
	ldrh r1, [r0, 0x8]
	subs r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	cmp r1, 0
	bne _0810DF90
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_0810DF90:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DF18

	thumb_func_start sub_810DFA8
sub_810DFA8: @ 810DFA8
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DFC8
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
_0810DFC8:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x8]
	strh r0, [r6, 0x2E]
	ldrh r0, [r6, 0x20]
	strh r0, [r6, 0x30]
	ldr r5, =gBattleAnimTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x4]
	adds r0, r1
	strh r0, [r6, 0x32]
	ldrh r0, [r6, 0x22]
	strh r0, [r6, 0x34]
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x6]
	adds r0, r4
	strh r0, [r6, 0x36]
	adds r0, r6, 0
	bl InitAnimLinearTranslation
	ldr r0, =RunStoredCallbackWhenAffineAnimEnds
	str r0, [r6, 0x1C]
	ldr r1, =sub_810E028
	adds r0, r6, 0
	bl StoreSpriteCallbackInData6
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DFA8

	thumb_func_start sub_810E028
sub_810E028: @ 810E028
	push {r4,lr}
	adds r4, r0, 0
	bl AnimTranslateLinear
	lsls r0, 24
	cmp r0, 0
	beq _0810E03C
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810E03C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810E028

	thumb_func_start sub_810E044
sub_810E044: @ 810E044
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810E070
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
	ldrh r0, [r1, 0x2]
	negs r0, r0
	strh r0, [r1, 0x2]
	ldrh r0, [r1, 0x4]
	negs r0, r0
	strh r0, [r1, 0x4]
	ldrh r0, [r1, 0x6]
	negs r0, r0
	strh r0, [r1, 0x6]
_0810E070:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810E088
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0x2]
	negs r1, r1
	strh r1, [r0, 0x2]
	ldrh r1, [r0, 0x6]
	negs r1, r1
	strh r1, [r0, 0x6]
_0810E088:
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
	ldr r2, =gBattleAnimArgs
	ldrh r1, [r2]
	ldrh r3, [r5, 0x20]
	adds r1, r3
	strh r1, [r5, 0x20]
	lsrs r0, 24
	ldrh r1, [r2, 0x2]
	adds r0, r1
	strh r0, [r5, 0x22]
	ldrh r0, [r2, 0x8]
	strh r0, [r5, 0x2E]
	movs r3, 0xC
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _0810E0EC
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
	b _0810E0FE
	.pool
_0810E0EC:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl SetAverageBattlerPositions
_0810E0FE:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4, 0x4]
	ldrh r1, [r5, 0x32]
	adds r0, r1
	strh r0, [r5, 0x32]
	ldrh r0, [r4, 0x6]
	ldrh r3, [r5, 0x36]
	adds r0, r3
	strh r0, [r5, 0x36]
	ldr r0, =StartAnimLinearTranslation
	str r0, [r5, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldrb r1, [r4, 0xA]
	adds r0, r5, 0
	bl SeekSpriteAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E044

	thumb_func_start sub_810E13C
sub_810E13C: @ 810E13C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =sub_810E184
	str r0, [r4, 0x1C]
	movs r0, 0
	bl GetAnimBattlerSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E13C

	thumb_func_start sub_810E184
sub_810E184: @ 810E184
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0810E198
	subs r0, r1, 0x1
	strh r0, [r2, 0x2E]
	b _0810E1AA
_0810E198:
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	subs r1, r0
	strh r1, [r2, 0x26]
_0810E1AA:
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _0810E1C2
	adds r0, r2, 0
	bl DestroyAnimSprite
_0810E1C2:
	pop {r0}
	bx r0
	thumb_func_end sub_810E184

	thumb_func_start sub_810E1C8
sub_810E1C8: @ 810E1C8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810E1F8
	movs r0, 0x88
	lsls r0, 1
	strh r0, [r5, 0x20]
	ldr r0, =0x0000ffe0
	strh r0, [r5, 0x22]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	b _0810E1FE
	.pool
_0810E1F8:
	ldr r0, =0x0000ffe0
	strh r0, [r5, 0x20]
	strh r0, [r5, 0x22]
_0810E1FE:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl InitAnimLinearTranslation
	ldr r0, =sub_810E24C
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E1C8

	thumb_func_start sub_810E24C
sub_810E24C: @ 810E24C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl AnimTranslateLinear
	ldrh r1, [r4, 0x34]
	lsrs r0, r1, 8
	cmp r0, 0xC8
	bls _0810E274
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	movs r0, 0
	strh r0, [r4, 0x24]
	movs r0, 0xFF
	ands r0, r1
	strh r0, [r4, 0x34]
_0810E274:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x20
	movs r1, 0x98
	lsls r1, 1
	cmp r0, r1
	bhi _0810E296
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	cmp r0, 0xA0
	ble _0810E2BC
_0810E296:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810E2BC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E24C

	thumb_func_start sub_810E2C8
sub_810E2C8: @ 810E2C8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	subs r1, r0, 0x1
	strh r1, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	bgt _0810E308
	ldrb r0, [r4, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810E2FA
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
_0810E2FA:
	adds r0, r4, 0
	bl DestroySprite
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
_0810E308:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E2C8

	thumb_func_start sub_810E314
sub_810E314: @ 810E314
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r5, r7, 0
	adds r5, 0x2E
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r0, 0xE]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0810E33C
	ldr r0, =gBattleAnimAttacker
	b _0810E33E
	.pool
_0810E33C:
	ldr r0, =gBattleAnimTarget
_0810E33E:
	ldrb r6, [r0]
	adds r0, r6, 0
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810E354
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810E354:
	adds r0, r6, 0
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r7, 0x20]
	adds r0, r6, 0
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	ldrh r1, [r4, 0x2]
	lsrs r0, 24
	adds r1, r0, r1
	strh r1, [r7, 0x22]
	lsls r1, 8
	strh r1, [r5, 0x8]
	ldrh r1, [r4, 0xC]
	adds r0, r1
	lsls r0, 1
	ldrh r2, [r5, 0xE]
	movs r1, 0x1
	ands r1, r2
	orrs r1, r0
	strh r1, [r5, 0xE]
	ldrb r0, [r5]
	movs r2, 0x4
	mov r8, r2
	mov r1, r8
	orrs r0, r1
	strb r0, [r5]
	ldrh r0, [r4, 0x4]
	ldrb r1, [r4, 0x4]
	strh r1, [r5, 0x2]
	lsls r0, 16
	lsrs r0, 24
	strh r0, [r5, 0xA]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x4]
	ldrh r0, [r4, 0x8]
	strh r0, [r5, 0x6]
	ldrh r0, [r4, 0xA]
	strh r0, [r5, 0xC]
	subs r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x7F
	bhi _0810E44A
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E3F0
	adds r0, r6, 0
	bl GetBattlerSpriteBGPriority
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r7, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x5]
	b _0810E408
	.pool
_0810E3F0:
	adds r0, r6, 0
	bl GetBattlerSpriteBGPriority
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x5]
_0810E408:
	ldrb r1, [r5, 0xE]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r5, 0xE]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	bne _0810E4AA
	adds r3, r7, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r0, r2, 31
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r7, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	b _0810E4A2
_0810E44A:
	adds r0, r6, 0
	bl GetBattlerSpriteBGPriority
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, 0x5]
	ldrb r0, [r5, 0xE]
	movs r4, 0x1
	orrs r0, r4
	strb r0, [r5, 0xE]
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810E4AA
	adds r3, r7, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	ands r1, r4
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r7, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	mov r2, r8
	orrs r0, r2
_0810E4A2:
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
_0810E4AA:
	ldrh r1, [r5, 0x2]
	lsrs r1, 6
	lsls r1, 4
	ldrb r2, [r5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	ldr r3, =gSineTable
	ldrh r0, [r5, 0x2]
	lsls r0, 1
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, 0xC]
	muls r0, r1
	asrs r0, 8
	strh r0, [r7, 0x24]
	ldrb r2, [r7, 0x3]
	lsls r2, 26
	lsrs r2, 27
	movs r1, 0x24
	ldrsh r0, [r7, r1]
	negs r0, r0
	asrs r0, 1
	ldrb r5, [r5, 0xA]
	adds r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r3
	ldrh r4, [r1]
	ldr r1, =gOamMatrices
	lsls r2, 3
	adds r2, r1
	adds r0, 0x40
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r2, 0x6]
	strh r0, [r2]
	strh r4, [r2, 0x2]
	lsls r0, r4, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r2, 0x4]
	ldr r0, =sub_810E520
	str r0, [r7, 0x1C]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E314

	thumb_func_start sub_810E520
sub_810E520: @ 810E520
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r6, 0
	adds r4, r5, 0
	adds r4, 0x2E
	ldrb r2, [r4]
	movs r7, 0x1
	movs r0, 0x1
	mov r9, r0
	ands r0, r2
	cmp r0, 0
	beq _0810E55A
	ldrb r0, [r4, 0x1]
	adds r1, r0, 0
	adds r1, 0xFF
	strb r1, [r4, 0x1]
	lsls r0, 24
	cmp r0, 0
	beq _0810E54E
	b _0810EA36
_0810E54E:
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810EA36
_0810E55A:
	ldrh r0, [r4, 0x2]
	lsrs r1, r0, 6
	mov r12, r0
	cmp r1, 0x1
	bne _0810E566
	b _0810E68A
_0810E566:
	cmp r1, 0x1
	bgt _0810E570
	cmp r1, 0
	beq _0810E57E
	b _0810E97C
_0810E570:
	cmp r1, 0x2
	bne _0810E576
	b _0810E77E
_0810E576:
	cmp r1, 0x3
	bne _0810E57C
	b _0810E872
_0810E57C:
	b _0810E97C
_0810E57E:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0x1
	bne _0810E592
	movs r0, 0x8
	orrs r0, r2
	orrs r0, r7
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810E680
_0810E592:
	lsrs r0, r1, 28
	cmp r0, 0x3
	bne _0810E5B4
	lsls r0, r2, 30
	lsrs r0, 31
	movs r1, 0x1
	eors r0, r1
	ands r0, r7
	lsls r0, 1
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	orrs r1, r7
	strb r1, [r4]
	strb r6, [r4, 0x1]
	b _0810E680
_0810E5B4:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E680
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E672
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E642
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E628
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E660
_0810E628:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E660
_0810E642:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E656
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E65E
_0810E656:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E65E:
	strb r0, [r1]
_0810E660:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E672:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E680:
	ldrb r1, [r4]
	movs r0, 0xF
	ands r0, r1
	strb r0, [r4]
	b _0810E97C
_0810E68A:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0
	bne _0810E698
	movs r0, 0x8
	orrs r0, r2
	b _0810E6A0
_0810E698:
	lsrs r0, r1, 28
	cmp r0, 0x2
	bne _0810E6A8
	adds r0, r2, 0
_0810E6A0:
	orrs r0, r7
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810E774
_0810E6A8:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E774
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E766
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E736
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E71C
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E754
_0810E71C:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E754
_0810E736:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E74A
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E752
_0810E74A:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E752:
	strb r0, [r1]
_0810E754:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E766:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E774:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x10
	b _0810E978
_0810E77E:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0x3
	bne _0810E78C
	movs r0, 0x8
	orrs r0, r2
	b _0810E794
_0810E78C:
	lsrs r0, r1, 28
	cmp r0, 0x1
	bne _0810E79C
	adds r0, r2, 0
_0810E794:
	orrs r0, r7
	strb r0, [r4]
	strb r6, [r4, 0x1]
	b _0810E868
_0810E79C:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E868
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E85A
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E82A
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E810
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E848
_0810E810:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E848
_0810E82A:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E83E
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E846
_0810E83E:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E846:
	strb r0, [r1]
_0810E848:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E85A:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E868:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x20
	b _0810E978
_0810E872:
	lsls r1, r2, 24
	lsrs r0, r1, 28
	cmp r0, 0x2
	bne _0810E882
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r4]
	b _0810E970
_0810E882:
	lsrs r0, r1, 28
	cmp r0, 0
	bne _0810E8A4
	lsls r0, r2, 30
	lsrs r0, 31
	movs r1, 0x1
	eors r0, r1
	ands r0, r7
	lsls r0, 1
	movs r1, 0x3
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	orrs r1, r7
	strb r1, [r4]
	strb r6, [r4, 0x1]
	b _0810E970
_0810E8A4:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0810E970
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r1, r2, 31
	lsrs r1, 31
	movs r6, 0x1
	eors r1, r6
	ands r1, r7
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r0, 31
	lsrs r0, 31
	adds r1, r5, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810E962
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810E932
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E918
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	subs r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E950
_0810E918:
	ldrb r2, [r5, 0x5]
	lsls r1, r2, 28
	lsrs r1, 30
	adds r1, 0x1
	movs r0, 0x3
	ands r1, r0
	lsls r1, 2
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0810E950
_0810E932:
	ldrb r1, [r4, 0xE]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0810E946
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	subs r0, 0xC
	b _0810E94E
_0810E946:
	adds r1, r5, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0xC
_0810E94E:
	strb r0, [r1]
_0810E950:
	ldrb r2, [r4, 0xE]
	lsls r0, r2, 31
	lsrs r0, 31
	eors r0, r6
	ands r0, r7
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0xE]
_0810E962:
	ldrb r1, [r4]
	movs r0, 0x9
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrh r1, [r4, 0x2]
	mov r12, r1
_0810E970:
	ldrb r0, [r4]
	movs r1, 0xF
	ands r1, r0
	movs r0, 0x30
_0810E978:
	orrs r1, r0
	strb r1, [r4]
_0810E97C:
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 31
	adds r0, r4, 0
	adds r0, 0xC
	adds r0, r1
	ldrb r1, [r0]
	ldr r3, =gSineTable
	mov r2, r12
	lsls r0, r2, 1
	adds r0, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r0, r1
	asrs r0, 8
	strh r0, [r5, 0x24]
	ldrb r2, [r5, 0x3]
	lsls r2, 26
	lsrs r2, 27
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	negs r0, r0
	asrs r0, 1
	ldrb r1, [r4, 0xA]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r3
	ldrh r6, [r1]
	ldr r1, =gOamMatrices
	lsls r2, 3
	adds r2, r1
	adds r0, 0x40
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r2, 0x6]
	strh r0, [r2]
	strh r6, [r2, 0x2]
	lsls r0, r6, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r2, 0x4]
	ldrh r0, [r4, 0x6]
	ldrh r2, [r4, 0x8]
	adds r0, r2
	strh r0, [r4, 0x8]
	lsls r0, 16
	lsrs r0, 24
	strh r0, [r5, 0x22]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0810EA0C
	ldrh r0, [r4, 0x4]
	subs r1, 0x1
	ands r1, r0
	ldrh r0, [r4, 0x2]
	subs r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2]
	b _0810EA1C
	.pool
_0810EA0C:
	ldrh r0, [r4, 0x4]
	ldr r1, =0x00007fff
	ands r1, r0
	ldrh r2, [r4, 0x2]
	adds r1, r2
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r4, 0x2]
_0810EA1C:
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	ldrh r0, [r4, 0xE]
	lsrs r0, 1
	cmp r1, r0
	blt _0810EA36
	movs r0, 0
	strh r0, [r5, 0x2E]
	ldr r0, =sub_810E2C8
	str r0, [r5, 0x1C]
_0810EA36:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810E520

	thumb_func_start sub_810EA4C
sub_810EA4C: @ 810EA4C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriority
	movs r1, 0x3
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
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
	ldr r0, =TranslateAnimSpriteToTargetMonLocation
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EA4C

	thumb_func_start sub_810EAA0
sub_810EAA0: @ 810EAA0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810EABC
	adds r0, r5, 0
	movs r1, 0
	bl InitSpritePosToAnimAttacker
	b _0810EAC4
	.pool
_0810EABC:
	adds r0, r5, 0
	movs r1, 0
	bl InitSpritePosToAnimTarget
_0810EAC4:
	ldr r4, =gBattleAnimArgs
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0810EADC
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810EAF2
_0810EADC:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0810EAF8
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810EAF8
_0810EAF2:
	ldrh r0, [r5, 0x20]
	adds r0, 0x8
	strh r0, [r5, 0x20]
_0810EAF8:
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0x8]
	adds r0, r5, 0
	bl SeekSpriteAnim
	ldrh r0, [r5, 0x20]
	subs r0, 0x20
	strh r0, [r5, 0x20]
	ldr r0, =0x00000ccc
	strh r0, [r5, 0x30]
	ldrh r1, [r4, 0x8]
	movs r0, 0xC
	adds r2, r0, 0
	muls r2, r1
	adds r0, r2, 0
	ldrh r2, [r5, 0x24]
	adds r0, r2
	strh r0, [r5, 0x24]
	strh r1, [r5, 0x2E]
	ldrh r0, [r4, 0x6]
	strh r0, [r5, 0x3C]
	ldr r0, =sub_810EB40
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EAA0

	thumb_func_start sub_810EB40
sub_810EB40: @ 810EB40
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bne _0810EB6A
	strh r1, [r4, 0x2E]
	strh r1, [r4, 0x24]
	adds r0, r4, 0
	bl StartSpriteAnim
_0810EB6A:
	ldrh r0, [r4, 0x3C]
	subs r0, 0x1
	strh r0, [r4, 0x3C]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810EB82
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810EB82:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810EB40

	thumb_func_start sub_810EB88
sub_810EB88: @ 810EB88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	ldrh r0, [r7, 0x8]
	movs r1, 0x1F
	ands r0, r1
	cmp r0, 0
	bne _0810EC02
	ldr r1, =gAnimVisualTaskCount
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	movs r5, 0xD
	negs r5, r5
	adds r1, r5, 0
	bl Sin
	ldr r4, =gBattleAnimArgs
	strh r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	adds r1, r5, 0
	bl Cos
	strh r0, [r4, 0x2]
	movs r0, 0x1
	strh r0, [r4, 0x4]
	movs r0, 0x3
	strh r0, [r4, 0x6]
	ldr r0, =gUnknown_085973E8
	mov r8, r0
	ldr r5, =gBattleAnimTarget
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0x3
	bl CreateSpriteAndAnimate
_0810EC02:
	ldrh r0, [r7, 0x8]
	adds r0, 0x8
	strh r0, [r7, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _0810EC16
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_0810EC16:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EB88

	thumb_func_start sub_810EC34
sub_810EC34: @ 810EC34
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810EC46
	cmp r0, 0x1
	beq _0810EC78
	b _0810EC8C
_0810EC46:
	adds r0, r4, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	movs r0, 0
	bl GetAnimBattlerSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810EC8C
	.pool
_0810EC78:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810EC8C
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810EC8C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810EC34

	thumb_func_start sub_810EC94
sub_810EC94: @ 810EC94
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0810ECCC
	cmp r0, 0x1
	bgt _0810ECAA
	cmp r0, 0
	beq _0810ECB0
	b _0810ED1E
_0810ECAA:
	cmp r0, 0x2
	beq _0810ECE0
	b _0810ED1E
_0810ECB0:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	negs r0, r0
	subs r0, 0x20
	strh r0, [r4, 0x26]
	b _0810ECD8
	.pool
_0810ECCC:
	ldrh r0, [r4, 0x26]
	adds r0, 0xA
	strh r0, [r4, 0x26]
	lsls r0, 16
	cmp r0, 0
	blt _0810ED1E
_0810ECD8:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810ED1E
_0810ECE0:
	ldrh r0, [r4, 0x26]
	subs r0, 0xA
	strh r0, [r4, 0x26]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _0810ED1E
	movs r0, 0
	bl GetAnimBattlerSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810ED1E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EC94

	thumb_func_start sub_810ED28
sub_810ED28: @ 810ED28
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =sub_810ED70
	str r0, [r4, 0x1C]
	movs r0, 0
	bl GetAnimBattlerSpriteId
	ldr r2, =gSprites
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ED28

	thumb_func_start sub_810ED70
sub_810ED70: @ 810ED70
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2E]
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0810ED84
	subs r0, r1, 0x1
	strh r0, [r2, 0x2E]
	b _0810EDC8
_0810ED84:
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	ble _0810EDAA
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	subs r1, r0
	strh r1, [r2, 0x26]
	b _0810EDC8
_0810EDAA:
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x34]
	adds r1, r0, 0x1
	strh r1, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _0810EDC8
	ldr r0, =sub_810EDD0
	str r0, [r2, 0x1C]
_0810EDC8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810ED70

	thumb_func_start sub_810EDD0
sub_810EDD0: @ 810EDD0
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
	movs r3, 0x22
	ldrsh r0, [r2, r3]
	movs r3, 0x26
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	ble _0810EE00
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
_0810EE00:
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	ble _0810EE0E
	adds r0, r2, 0
	bl DestroyAnimSprite
_0810EE0E:
	pop {r0}
	bx r0
	thumb_func_end sub_810EDD0

	thumb_func_start sub_810EE14
sub_810EE14: @ 810EE14
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0810EE28
	cmp r0, 0x1
	beq _0810EE80
	b _0810EEEC
_0810EE28:
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0810EE40
	ldr r4, =gBattleAnimAttacker
	b _0810EE42
	.pool
_0810EE40:
	ldr r4, =gBattleAnimTarget
_0810EE42:
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
	movs r0, 0
	movs r3, 0x80
	lsls r3, 2
	strh r3, [r5, 0x30]
	movs r2, 0x80
	lsls r2, 1
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl TrySetSpriteRotScale
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0810EEEC
	.pool
_0810EE80:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0xB
	bgt _0810EE8E
	ldrh r0, [r5, 0x30]
	subs r0, 0x28
	b _0810EE92
_0810EE8E:
	ldrh r0, [r5, 0x30]
	adds r0, 0x28
_0810EE92:
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x32]
	movs r2, 0x80
	lsls r2, 1
	movs r0, 0x30
	ldrsh r3, [r5, r0]
	str r1, [sp]
	adds r0, r5, 0
	bl TrySetSpriteRotScale
	ldrb r1, [r5, 0x3]
	lsls r1, 26
	lsrs r1, 27
	movs r0, 0xF4
	lsls r0, 6
	ldr r2, =gOamMatrices
	lsls r1, 3
	adds r1, r2
	movs r2, 0x6
	ldrsh r1, [r1, r2]
	bl __divsi3
	adds r1, r0, 0x1
	cmp r1, 0x80
	ble _0810EECC
	movs r1, 0x80
_0810EECC:
	movs r0, 0x40
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r1, r0, 1
	strh r1, [r5, 0x26]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0x18
	bne _0810EEEC
	adds r0, r5, 0
	bl sub_80A749C
	adds r0, r5, 0
	bl DestroyAnimSprite
_0810EEEC:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EE14

	thumb_func_start sub_810EEF8
sub_810EEF8: @ 810EEF8
	push {r4,r5,lr}
	adds r5, r0, 0
	bl Random2
	ldr r4, =0x000001ff
	ands r4, r0
	bl Random2
	movs r1, 0x7F
	ands r1, r0
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0810EF20
	movs r2, 0xB8
	lsls r2, 2
	adds r0, r4, r2
	b _0810EF28
	.pool
_0810EF20:
	movs r2, 0xB8
	lsls r2, 2
	adds r0, r2, 0
	subs r0, r4
_0810EF28:
	strh r0, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0810EF3C
	movs r2, 0xE0
	lsls r2, 2
	adds r0, r2, 0
	adds r0, r1, r0
	b _0810EF44
_0810EF3C:
	movs r2, 0xE0
	lsls r2, 2
	adds r0, r2, 0
	subs r0, r1
_0810EF44:
	strh r0, [r5, 0x30]
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	strh r0, [r5, 0x32]
	lsls r0, 16
	cmp r0, 0
	beq _0810EF60
	ldrb r0, [r5, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r0
	movs r0, 0x10
	orrs r1, r0
	strb r1, [r5, 0x3]
_0810EF60:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _0810EF74
	ldr r4, =gBattleAnimAttacker
	b _0810EF76
	.pool
_0810EF74:
	ldr r4, =gBattleAnimTarget
_0810EF76:
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
	adds r0, 0x20
	strh r0, [r5, 0x22]
	ldr r0, =sub_810EFA8
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810EEF8

	thumb_func_start sub_810EFA8
sub_810EFA8: @ 810EFA8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810EFC0
	ldrh r3, [r4, 0x2E]
	lsls r0, r3, 16
	asrs r0, 24
	ldrh r1, [r4, 0x24]
	adds r0, r1
	b _0810EFCA
_0810EFC0:
	ldrh r3, [r4, 0x2E]
	lsls r1, r3, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
_0810EFCA:
	strh r0, [r4, 0x24]
	ldrh r2, [r4, 0x30]
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r4, 0x26]
	subs r0, r1
	strh r0, [r4, 0x26]
	strh r3, [r4, 0x2E]
	adds r0, r2, 0
	subs r0, 0x20
	strh r0, [r4, 0x30]
	lsls r0, r3, 16
	cmp r0, 0
	bge _0810EFEA
	movs r0, 0
	strh r0, [r4, 0x2E]
_0810EFEA:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _0810EFFE
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810EFFE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810EFA8

	thumb_func_start sub_810F004
sub_810F004: @ 810F004
	movs r1, 0
	strh r1, [r0, 0x3A]
	movs r1, 0x40
	strh r1, [r0, 0x3C]
	ldr r1, =sub_810F018
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_810F004

	thumb_func_start sub_810F018
sub_810F018: @ 810F018
	push {lr}
	adds r3, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _0810F02A
	cmp r1, 0x1
	beq _0810F078
	b _0810F07E
_0810F02A:
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0810F07E
	strh r1, [r3, 0x30]
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
	cmp r0, 0x5
	ble _0810F07E
	ldrb r1, [r1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0810F07E
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _0810F07E
_0810F078:
	adds r0, r3, 0
	bl DestroyAnimSprite
_0810F07E:
	pop {r0}
	bx r0
	thumb_func_end sub_810F018

	thumb_func_start sub_810F084
sub_810F084: @ 810F084
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	ldrh r4, [r0, 0x20]
	ldrh r5, [r0, 0x22]
	ldr r6, =gBattleAnimAttacker
	ldrb r0, [r6]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0x20]
	ldrb r0, [r6]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	mov r2, r8
	strh r6, [r2, 0x22]
	ldrh r0, [r2, 0x20]
	mov r9, r0
	mov r1, r9
	lsls r0, r1, 4
	strh r0, [r2, 0x36]
	lsls r0, r6, 4
	strh r0, [r2, 0x38]
	lsls r4, 16
	asrs r4, 16
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	subs r0, r4, r0
	lsls r0, 4
	movs r1, 0xC
	bl __divsi3
	mov r2, r8
	strh r0, [r2, 0x3A]
	lsls r5, 16
	asrs r5, 16
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	subs r0, r5, r0
	lsls r0, 4
	movs r1, 0xC
	bl __divsi3
	mov r2, r8
	strh r0, [r2, 0x3C]
	mov r0, r9
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	subs r5, r6
	lsls r5, 16
	asrs r5, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl ArcTan2Neg
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 24
	adds r0, r1
	lsrs r0, 16
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	mov r0, r8
	movs r1, 0x1
	adds r2, r3, 0
	bl TrySetSpriteRotScale
	ldr r0, =sub_810F140
	mov r2, r8
	str r0, [r2, 0x1C]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F084

	thumb_func_start sub_810F140
sub_810F140: @ 810F140
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x3A]
	ldrh r1, [r2, 0x36]
	adds r0, r1
	strh r0, [r2, 0x36]
	ldrh r1, [r2, 0x3C]
	ldrh r3, [r2, 0x38]
	adds r1, r3
	strh r1, [r2, 0x38]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	lsls r1, 16
	asrs r3, r1, 20
	strh r3, [r2, 0x22]
	adds r0, 0x2D
	lsls r0, 16
	movs r1, 0xA5
	lsls r1, 17
	cmp r0, r1
	bhi _0810F17A
	adds r1, r3, 0
	cmp r1, 0x9D
	bgt _0810F17A
	movs r0, 0x2D
	negs r0, r0
	cmp r1, r0
	bge _0810F180
_0810F17A:
	adds r0, r2, 0
	bl DestroySpriteAndMatrix
_0810F180:
	pop {r0}
	bx r0
	thumb_func_end sub_810F140

	thumb_func_start sub_810F184
sub_810F184: @ 810F184
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810F1BC
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	b _0810F1DA
	.pool
_0810F1BC:
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
_0810F1DA:
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F184

	.align 2, 0
