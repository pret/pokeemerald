	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_810F1EC
sub_810F1EC: @ 810F1EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	bl IsContest
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810F212
	mov r0, r8
	cmp r0, 0
	beq _0810F22E
_0810F212:
	ldrb r1, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r5, 0x5]
	adds r1, r5, 0
	adds r1, 0x43
	movs r0, 0xC8
	strb r0, [r1]
	mov r1, r8
	cmp r1, 0
	bne _0810F2B8
_0810F22E:
	movs r0, 0x1
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	adds r0, r4, 0
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r6, r1, 31
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F264
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80A438C
_0810F264:
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r7
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F284
	movs r0, 0x1
	eors r6, r0
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80A438C
_0810F284:
	mov r0, r8
	cmp r0, 0
	bne _0810F2B8
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _0810F2B8
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810F2B0
	movs r0, 0x48
	strh r0, [r5, 0x20]
	movs r0, 0x50
	b _0810F2F2
	.pool
_0810F2B0:
	movs r0, 0xB0
	strh r0, [r5, 0x20]
	movs r0, 0x28
	b _0810F2F2
_0810F2B8:
	ldr r6, =gBattleAnimAttacker
	ldrb r0, [r6]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810F2CE
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810F2CE:
	ldrb r0, [r6]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	ldr r4, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r4, [r4, 0x2]
	adds r0, r4
_0810F2F2:
	strh r0, [r5, 0x22]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 20
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r0, [r5, 0x2E]
	mov r0, r8
	cmp r0, 0
	beq _0810F32C
	ldrh r0, [r5, 0x22]
	adds r0, 0x9
	strh r0, [r5, 0x22]
	ldr r1, =sub_810F3C8
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	b _0810F330
	.pool
_0810F32C:
	ldr r0, =sub_810F340
	str r0, [r5, 0x1C]
_0810F330:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F1EC
@

	thumb_func_start sub_810F340
sub_810F340: @ 810F340
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x1
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0x3C
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810F35C
	movs r0, 0x1
	strh r0, [r5, 0x3C]
	b _0810F3B6
_0810F35C:
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F382
	ldr r2, =gSprites
	ldr r0, =gBattlerSpriteIds
	adds r0, r4, r0
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
_0810F382:
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F3AC
	ldr r2, =gSprites
	ldr r0, =gBattlerSpriteIds
	adds r0, r4, r0
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
_0810F3AC:
	ldr r1, =sub_810F3C8
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
_0810F3B6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F340

	thumb_func_start sub_810F3C8
sub_810F3C8: @ 810F3C8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0xD
	bne _0810F3F4
	ldr r0, =sub_810F400
	str r0, [r4, 0x1C]
	b _0810F3F8
	.pool
_0810F3F4:
	adds r0, r1, 0x1
	strh r0, [r4, 0x34]
_0810F3F8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810F3C8

	thumb_func_start sub_810F400
sub_810F400: @ 810F400
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _0810F45E
	movs r0, 0
	strh r0, [r3, 0x30]
	ldrh r4, [r3, 0x2E]
	ldr r1, =gPlttBufferFaded
	adds r0, r4, 0
	adds r0, 0x8
	lsls r0, 1
	adds r0, r1
	ldrh r7, [r0]
	movs r5, 0x8
	adds r6, r1, 0
	adds r1, r4, 0x7
	lsls r0, r4, 1
	adds r0, r6
	adds r2, r0, 0
	adds r2, 0x10
	lsls r1, 1
	adds r1, r6
_0810F436:
	ldrh r0, [r1]
	strh r0, [r2]
	subs r1, 0x2
	subs r2, 0x2
	subs r5, 0x1
	cmp r5, 0
	bgt _0810F436
	adds r0, r4, 0x1
	lsls r0, 1
	adds r0, r6
	strh r7, [r0]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bne _0810F45E
	ldr r0, =sub_810F46C
	str r0, [r3, 0x1C]
_0810F45E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F400

	thumb_func_start sub_810F46C
sub_810F46C: @ 810F46C
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x34]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r5, 0x34]
	subs r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810F512
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810F502
	movs r0, 0x1
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F4D4
	ldr r2, =gSprites
	ldr r0, =gBattlerSpriteIds
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
_0810F4D4:
	movs r0, 0x2
	adds r4, r0, 0
	eors r4, r6
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F502
	ldr r2, =gSprites
	ldr r0, =gBattlerSpriteIds
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
_0810F502:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_810F524
	str r0, [r5, 0x1C]
_0810F512:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F46C

	thumb_func_start sub_810F524
sub_810F524: @ 810F524
	push {r4-r6,lr}
	adds r6, r0, 0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810F57C
	movs r0, 0x1
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r5, r1, 31
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F562
	adds r0, r5, 0
	bl sub_80A477C
_0810F562:
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, 0
	bl IsBattlerSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _0810F57C
	movs r0, 0x1
	eors r5, r0
	adds r0, r5, 0
	bl sub_80A477C
_0810F57C:
	ldr r0, =DestroyAnimSprite
	str r0, [r6, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F524

	thumb_func_start sub_810F58C
sub_810F58C: @ 810F58C
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810F618
	ldr r5, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	movs r6, 0
	cmp r0, 0
	bne _0810F5A6
	movs r6, 0x1
_0810F5A6:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810F5EE
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	beq _0810F5EE
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810F5E0
	ldrh r0, [r5]
	movs r1, 0x48
	subs r1, r0
	strh r1, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	adds r0, 0x50
	strh r0, [r4, 0x22]
	b _0810F610
	.pool
_0810F5E0:
	ldrh r0, [r5]
	adds r0, 0xB0
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	adds r0, 0x28
	strh r0, [r4, 0x22]
	b _0810F610
_0810F5EE:
	ldr r0, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0810F608
	adds r0, r4, 0
	adds r1, r6, 0
	bl InitSpritePosToAnimAttacker
	b _0810F610
	.pool
_0810F608:
	adds r0, r4, 0
	adds r1, r6, 0
	bl InitSpritePosToAnimTarget
_0810F610:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810F62C
_0810F618:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	beq _0810F62C
	adds r0, r4, 0
	bl DestroySpriteAndMatrix
_0810F62C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810F58C

	thumb_func_start sub_810F634
sub_810F634: @ 810F634
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
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810F684
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r5, 0x20]
	subs r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	adds r0, 0xA
	strh r0, [r5, 0x22]
	ldr r0, =0x0000ffff
	b _0810F692
	.pool
_0810F684:
	ldrh r0, [r5, 0x20]
	adds r0, 0x28
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	subs r0, 0xA
	strh r0, [r5, 0x22]
	movs r0, 0x1
_0810F692:
	strh r0, [r5, 0x30]
	ldr r1, =DestroyAnimSprite
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =RunStoredCallbackWhenAnimEnds
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F634

	thumb_func_start sub_810F6B0
sub_810F6B0: @ 810F6B0
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimAttacker
	ldrb r0, [r6]
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	lsls r1, 15
	lsrs r4, r1, 16
	ldrb r0, [r6]
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r1, r0, 16
	lsrs r0, 31
	adds r1, r0
	asrs r1, 1
	negs r1, r1
	lsls r1, 16
	lsrs r7, r1, 16
	ldrb r0, [r6]
	bl GetBattlerSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810F6F6
	lsls r0, r4, 16
	negs r0, r0
	lsrs r4, r0, 16
_0810F6F6:
	ldrb r0, [r6]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	strh r0, [r5, 0x20]
	ldrb r0, [r6]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	adds r0, r7
	strh r0, [r5, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bgt _0810F722
	movs r0, 0x10
	strh r0, [r5, 0x22]
_0810F722:
	ldr r1, =sub_810F740
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =RunStoredCallbackWhenAnimEnds
	str r0, [r5, 0x1C]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F6B0

	thumb_func_start sub_810F740
sub_810F740: @ 810F740
	push {r4,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =gUnknown_08596740
	str r0, [r4, 0x10]
	movs r0, 0
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	ldr r0, =sub_810F774
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F740

	thumb_func_start sub_810F774
sub_810F774: @ 810F774
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810F786
	cmp r0, 0x1
	beq _0810F7B4
	b _0810F7CC
_0810F786:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0810F7CC
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x12
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810F7CC
_0810F7B4:
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0810F7CC
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810F7CC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F774

	thumb_func_start sub_810F7D4
sub_810F7D4: @ 810F7D4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	movs r0, 0
	bl GetAnimBattlerSpriteId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	strh r1, [r4, 0x8]
	ldr r2, =gUnknown_0859675C
	adds r0, r4, 0
	bl PrepareAffineAnimInTaskData
	ldr r0, =sub_810F810
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F7D4

	thumb_func_start sub_810F810
sub_810F810: @ 810F810
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	bl RunAffineAnimFromTaskData
	lsls r0, 24
	cmp r0, 0
	bne _0810F830
	adds r0, r4, 0
	bl DestroyAnimVisualTask
_0810F830:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F810

	thumb_func_start sub_810F83C
sub_810F83C: @ 810F83C
	push {r4,lr}
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
	movs r1, 0
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xA]
	strh r1, [r4, 0xC]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	movs r1, 0x8
	cmp r0, 0
	beq _0810F870
	movs r1, 0x4
_0810F870:
	strh r1, [r4, 0xE]
	ldrb r1, [r4, 0x8]
	ldr r2, =gUnknown_0859677C
	adds r0, r4, 0
	bl PrepareAffineAnimInTaskData
	ldr r0, =sub_810F898
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F83C

	thumb_func_start sub_810F898
sub_810F898: @ 810F898
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810F8BC
	cmp r0, 0x1
	beq _0810F8D8
	b _0810F936
	.pool
_0810F8BC:
	adds r0, r4, 0
	bl RunAffineAnimFromTaskData
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0810F936
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _0810F936
_0810F8D8:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810F900
	ldr r2, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x8
	strh r1, [r0, 0x26]
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _0810F936
	.pool
_0810F900:
	ldr r3, =gSprites
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	ldrb r0, [r4, 0x8]
	bl ResetSpriteRotScale
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_0810F936:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F898

	thumb_func_start sub_810F940
sub_810F940: @ 810F940
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	movs r1, 0
	movs r0, 0x10
	strh r0, [r5, 0xE]
	strh r1, [r5, 0x10]
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x24]
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldrb r0, [r4]
	movs r1, 0
	bl sub_80A861C
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, r6
	bcs _0810F9AA
	adds r1, r6, 0
_0810F9AA:
	strh r1, [r5, 0x20]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =sub_810F9D4
	str r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810F940

	thumb_func_start sub_810F9D4
sub_810F9D4: @ 810F9D4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0x1
	beq _0810FAD4
	cmp r1, 0x1
	bgt _0810F9FC
	cmp r1, 0
	beq _0810FA0A
	b _0810FB5A
	.pool
_0810F9FC:
	cmp r1, 0x2
	bne _0810FA02
	b _0810FB36
_0810FA02:
	cmp r1, 0x3
	bne _0810FA08
	b _0810FB44
_0810FA08:
	b _0810FB5A
_0810FA0A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	bgt _0810FA1A
	b _0810FB5A
_0810FA1A:
	strh r1, [r4, 0xA]
	ldr r0, =gUnknown_08596794
	movs r2, 0x22
	ldrsh r1, [r4, r2]
	movs r3, 0x24
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	adds r1, 0x8
	lsls r1, 1
	adds r0, r4, 0
	adds r0, 0x8
	adds r0, r1
	strh r2, [r0]
	cmp r2, 0x40
	beq _0810FABE
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0810FA78
	cmp r0, 0x1
	bgt _0810FA5C
	cmp r0, 0
	beq _0810FA66
	b _0810FABE
	.pool
_0810FA5C:
	cmp r0, 0x2
	beq _0810FA90
	cmp r0, 0x3
	beq _0810FAA8
	b _0810FABE
_0810FA66:
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r4, 0x20]
	b _0810FAB6
	.pool
_0810FA78:
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r4, 0x20]
	negs r0, r0
	strh r0, [r1, 0x24]
	ldrh r0, [r4, 0x20]
	b _0810FABC
	.pool
_0810FA90:
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r4, 0x20]
	strh r1, [r0, 0x24]
	ldrh r1, [r4, 0x20]
	strh r1, [r0, 0x26]
	b _0810FABE
	.pool
_0810FAA8:
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r4, 0x20]
	negs r0, r0
_0810FAB6:
	strh r0, [r1, 0x24]
	ldrh r0, [r4, 0x20]
	negs r0, r0
_0810FABC:
	strh r0, [r1, 0x26]
_0810FABE:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	bne _0810FB5A
	b _0810FB36
	.pool
_0810FAD4:
	ldrh r0, [r4, 0xA]
	ands r1, r0
	cmp r1, 0
	beq _0810FAE4
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _0810FAEA
_0810FAE4:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
_0810FAEA:
	ldrh r1, [r4, 0x10]
	lsls r1, 8
	ldrh r0, [r4, 0xE]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	bne _0810FB5A
	movs r5, 0x8
	adds r6, r4, 0
	adds r6, 0x8
_0810FB10:
	lsls r0, r5, 1
	adds r1, r6, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x40
	beq _0810FB2C
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_0810FB2C:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0xC
	bls _0810FB10
_0810FB36:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0810FB5A
	.pool
_0810FB44:
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_0810FB5A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_810F9D4


	thumb_func_start sub_810FB60
sub_810FB60: @ 810FB60
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	subs r0, 0xA
	cmp r1, r0
	ble _0810FB8A
	ldrh r0, [r4, 0x30]
	movs r1, 0x1
	ands r1, r0
	adds r3, r4, 0
	adds r3, 0x3E
	lsls r1, 2
	ldrb r2, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810FB8A:
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0810FB9C
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810FB9C:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810FB60

	thumb_func_start sub_810FBA8
sub_810FBA8: @ 810FBA8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810FBD4
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
_0810FBD4:
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x2E]
	ldr r0, =sub_810FB60
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810FBA8

	thumb_func_start sub_810FBF0
sub_810FBF0: @ 810FBF0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r5, r1, r0
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0810FC94
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _0810FC60
	ldr r0, =0x0000fff6
	strh r0, [r5, 0x1C]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	b _0810FD1E
	.pool
_0810FC60:
	movs r0, 0xA
	strh r0, [r5, 0x1C]
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	b _0810FD12
	.pool
_0810FC94:
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _0810FCE8
	ldr r0, =0x0000fff6
	strh r0, [r5, 0x1C]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x4
	bl sub_80A861C
	adds r0, 0x8
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x2
	bl sub_80A861C
	adds r0, 0x8
	b _0810FD1E
	.pool
_0810FCE8:
	movs r0, 0xA
	strh r0, [r5, 0x1C]
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x1E]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	subs r0, 0x8
	strh r0, [r5, 0x20]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x5
	bl sub_80A861C
	subs r0, 0x8
_0810FD12:
	strh r0, [r5, 0x22]
	ldrb r0, [r4]
	movs r1, 0x3
	bl sub_80A861C
	subs r0, 0x8
_0810FD1E:
	strh r0, [r5, 0x24]
	movs r0, 0x6
	strh r0, [r5, 0xA]
	ldr r0, =sub_810FD3C
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810FBF0

	thumb_func_start sub_810FD3C
sub_810FD3C: @ 810FD3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _0810FD60
	cmp r1, 0x1
	beq _0810FDD4
	b _0810FDE8
	.pool
_0810FD60:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _0810FDE8
	strh r1, [r5, 0xA]
	ldr r0, =gUnknown_08596864
	movs r2, 0x1E
	ldrsh r1, [r5, r2]
	movs r3, 0x20
	ldrsh r2, [r5, r3]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0810FDB4
	ldr r0, =gSprites
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r4, r0
	movs r0, 0x10
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x22]
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0x24]
	strh r0, [r4, 0x36]
	ldrh r0, [r5, 0x1C]
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl InitAnimArcTranslation
	ldrb r0, [r5, 0xC]
	movs r1, 0x3
	ands r1, r0
	adds r0, r4, 0
	bl StartSpriteAffineAnim
_0810FDB4:
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _0810FDE8
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0810FDE8
	.pool
_0810FDD4:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x11
	ble _0810FDE8
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_0810FDE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810FD3C

	thumb_func_start sub_810FDF0
sub_810FDF0: @ 810FDF0
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _0810FE0E
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_0810FE0E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810FDF0

	thumb_func_start sub_810FE14
sub_810FE14: @ 810FE14
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerYCoordWithElevation
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	subs r0, 0x20
	strh r0, [r4, 0x24]
	ldr r0, =gBattleAnimArgs
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	beq _0810FE6A
	cmp r0, 0x1
	bgt _0810FE58
	cmp r0, 0
	beq _0810FE5E
	b _0810FE86
	.pool
_0810FE58:
	cmp r0, 0x2
	beq _0810FE76
	b _0810FE86
_0810FE5E:
	movs r0, 0x2
	strh r0, [r4, 0x1E]
	movs r0, 0x5
	strh r0, [r4, 0x20]
	movs r0, 0x40
	b _0810FE7E
_0810FE6A:
	movs r0, 0x2
	strh r0, [r4, 0x1E]
	movs r0, 0x5
	strh r0, [r4, 0x20]
	movs r0, 0xC0
	b _0810FE7E
_0810FE76:
	movs r0, 0x4
	strh r0, [r4, 0x1E]
	strh r0, [r4, 0x20]
	movs r0, 0
_0810FE7E:
	strh r0, [r4, 0x22]
	adds r0, r1, 0
	adds r0, 0x20
	strh r0, [r4, 0x26]
_0810FE86:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _0810FE92
	movs r0, 0
	strh r0, [r4, 0x24]
_0810FE92:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0810FEB8
	ldr r0, =gBattle_BG1_X
	ldrh r0, [r0]
	strh r0, [r4, 0x1C]
	ldr r0, =0x04000014
	b _0810FEC0
	.pool
_0810FEB8:
	ldr r0, =gBattle_BG2_X
	ldrh r0, [r0]
	strh r0, [r4, 0x1C]
	ldr r0, =0x04000018
_0810FEC0:
	str r0, [sp]
	ldrh r1, [r4, 0x24]
	lsls r3, r1, 16
	asrs r1, r3, 16
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	adds r0, 0x40
	cmp r1, r0
	bgt _0810FEFA
	ldr r5, =gScanlineEffectRegBuffers
	movs r0, 0xF0
	lsls r0, 3
	adds r6, r5, r0
_0810FEDA:
	asrs r3, 16
	lsls r1, r3, 1
	adds r2, r1, r5
	ldrh r0, [r4, 0x1C]
	strh r0, [r2]
	adds r1, r6
	ldrh r0, [r4, 0x1C]
	strh r0, [r1]
	adds r3, 0x1
	lsls r3, 16
	asrs r1, r3, 16
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	adds r0, 0x40
	cmp r1, r0
	ble _0810FEDA
_0810FEFA:
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
	ldr r0, =sub_810FF34
	str r0, [r4]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810FE14

	thumb_func_start sub_810FF34
sub_810FF34: @ 810FF34
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0811000E
	cmp r0, 0x1
	bgt _0810FF60
	cmp r0, 0
	beq _0810FF66
	b _08110026
	.pool
_0810FF60:
	cmp r0, 0x2
	beq _08110020
	b _08110026
_0810FF66:
	ldrh r3, [r5, 0x22]
	ldrh r4, [r5, 0x24]
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0810FFFE
	ldr r0, =gSineTable
	mov r9, r0
	movs r7, 0x3
	ldr r1, =gScanlineEffectRegBuffers
	mov r12, r1
	movs r2, 0xF0
	lsls r2, 3
	add r2, r12
	mov r8, r2
_0810FF88:
	lsls r2, r3, 16
	asrs r0, r2, 15
	add r0, r9
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r3, 0x20
	ldrsh r1, [r5, r3]
	asrs r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r3, r0, 16
	adds r6, r2, 0
	cmp r3, 0
	ble _0810FFB8
	ldrh r1, [r5, 0xA]
	adds r0, r7, 0
	ands r0, r1
	adds r0, r3, r0
	b _0810FFC4
	.pool
_0810FFB8:
	cmp r3, 0
	bge _0810FFC8
	ldrh r1, [r5, 0xA]
	adds r0, r7, 0
	ands r0, r1
	subs r0, r3, r0
_0810FFC4:
	lsls r0, 16
	lsrs r1, r0, 16
_0810FFC8:
	lsls r2, r4, 16
	asrs r2, 16
	lsls r3, r2, 1
	mov r0, r12
	adds r4, r3, r0
	ldrh r0, [r5, 0x1C]
	lsls r1, 16
	asrs r1, 16
	adds r0, r1, r0
	strh r0, [r4]
	add r3, r8
	ldrh r0, [r5, 0x1C]
	adds r1, r0
	strh r1, [r3]
	asrs r0, r6, 16
	ldrh r1, [r5, 0x1E]
	adds r0, r1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r2, 0x1
	lsls r2, 16
	lsrs r4, r2, 16
	asrs r2, 16
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r2, r0
	ble _0810FF88
_0810FFFE:
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	ble _08110026
	b _08110014
_0811000E:
	ldr r1, =gScanlineEffect
	movs r0, 0x3
	strb r0, [r1, 0x15]
_08110014:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _08110026
	.pool
_08110020:
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_08110026:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_810FF34

	thumb_func_start sub_8110034
sub_8110034: @ 8110034
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	bl AllocOamMatrix
	lsls r0, 24
	lsrs r5, r0, 24
	mov r10, r5
	adds r6, r5, 0
	cmp r6, 0xFF
	bne _0811006C
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	b _08110116
	.pool
_0811006C:
	ldr r1, =gBattleAnimArgs
	ldrb r0, [r1]
	bl CloneBattlerSpriteWithBlend
	lsls r0, 16
	lsrs r1, r0, 16
	mov r9, r1
	asrs r0, 16
	cmp r0, 0
	bge _08110094
	adds r0, r5, 0
	bl FreeOamMatrix
	mov r0, r8
	bl DestroyAnimVisualTask
	b _08110116
	.pool
_08110094:
	ldr r2, =gSprites
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r0, r2, 0
	adds r0, 0x1C
	adds r0, r4, r0
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	adds r4, r2
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x1F
	ands r6, r0
	lsls r2, r6, 1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x3]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, 0
	adds r1, 0x43
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r1, r9
	lsls r0, r1, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	movs r3, 0
	bl SetSpriteRotScale
	ldrb r3, [r4, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r4, 0
	bl CalcCenterToCornerVec
	ldr r1, =gBattleAnimArgs
	ldrb r0, [r1]
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0x22]
	mov r0, r10
	strh r0, [r7, 0x24]
	mov r1, r9
	strh r1, [r7, 0x26]
	ldr r0, =sub_8110134
	str r0, [r7]
_08110116:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110034

	thumb_func_start sub_8110134
sub_8110134: @ 8110134
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
	cmp r0, 0x1
	beq _081101B8
	cmp r0, 0x1
	bgt _0811015C
	cmp r0, 0
	beq _08110166
	b _08110238
	.pool
_0811015C:
	cmp r0, 0x2
	beq _08110208
	cmp r0, 0x3
	beq _08110228
	b _08110238
_08110166:
	ldrh r0, [r4, 0xA]
	adds r0, 0x4
	strh r0, [r4, 0xA]
	ldr r1, =gSineTable
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 17
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	adds r1, r2, 0
	movs r3, 0
	bl SetSpriteRotScale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	lsls r1, 24
	lsrs r1, 24
	bl SetBattlerSpriteYOffsetFromOtherYScale
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x30
	bne _08110238
	b _0811021A
	.pool
_081101B8:
	ldrh r0, [r4, 0xA]
	subs r0, 0x4
	strh r0, [r4, 0xA]
	ldr r1, =gSineTable
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 17
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	adds r1, r2, 0
	movs r3, 0
	bl SetSpriteRotScale
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	lsls r1, 24
	lsrs r1, 24
	bl SetBattlerSpriteYOffsetFromOtherYScale
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _08110238
	b _0811021A
	.pool
_08110208:
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl obj_delete_but_dont_free_vram
_0811021A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08110238
	.pool
_08110228:
	ldrh r0, [r4, 0x24]
	lsls r0, 24
	lsrs r0, 24
	bl FreeOamMatrix
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08110238:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8110134
@*/

	thumb_func_start sub_8110240
sub_8110240: @ 8110240
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081102B8
	cmp r0, 0x1
	bgt _08110256
	cmp r0, 0
	beq _08110260
	b _08110360
_08110256:
	cmp r0, 0x2
	beq _081102EA
	cmp r0, 0x3
	beq _0811034A
	b _08110360
_08110260:
	ldr r4, =gBattleAnimAttacker
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
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	beq _0811028E
	ldrh r0, [r5, 0x22]
	adds r0, 0xC
	strh r0, [r5, 0x22]
_0811028E:
	movs r0, 0x8
	strh r0, [r5, 0x30]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldrh r0, [r5, 0x30]
	movs r1, 0x10
	subs r1, r0
	lsls r1, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	b _081102E2
	.pool
_081102B8:
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08110360
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xCB
	bl PlaySE12WithPanning
	adds r0, r5, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
_081102E2:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08110360
_081102EA:
	ldrh r0, [r5, 0x32]
	adds r1, r0, 0x1
	strh r1, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0811032E
	movs r0, 0
	strh r0, [r5, 0x32]
	ldrh r1, [r5, 0x30]
	subs r1, 0x1
	strh r1, [r5, 0x30]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0811032E
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_0811032E:
	movs r0, 0xE0
	lsls r0, 2
	adds r2, r0, 0
	ldrh r1, [r5, 0x34]
	adds r2, r1
	lsls r1, r2, 16
	asrs r1, 24
	ldrh r0, [r5, 0x26]
	subs r0, r1
	strh r0, [r5, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r5, 0x34]
	b _08110360
_0811034A:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyAnimSprite
_08110360:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8110240

	.align 2, 0
