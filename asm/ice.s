	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_810B614
sub_810B614: @ 810B614
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_085956C0
	movs r2, 0x22
	ldrsh r1, [r4, r2]
	movs r3, 0x24
	ldrsh r2, [r4, r3]
	ldrh r3, [r4, 0x20]
	lsls r3, 24
	lsrs r3, 24
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0810B658
	ldr r3, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x1C
	adds r1, r0, r1
	ldr r2, =sub_810B684
	str r2, [r1]
	adds r0, r3
	strh r5, [r0, 0x3A]
	movs r1, 0xA
	strh r1, [r0, 0x3C]
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
_0810B658:
	ldrh r2, [r4, 0x24]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _0810B67C
	adds r0, r2, 0
	adds r0, 0x20
	strh r0, [r4, 0x24]
	movs r0, 0
	b _0810B67E
	.pool
_0810B67C:
	movs r0, 0x1
_0810B67E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_810B614

	thumb_func_start sub_810B684
sub_810B684: @ 810B684
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810B6B8
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
	adds r0, r4, 0
	bl DestroySprite
_0810B6B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B684

	thumb_func_start sub_810B6C4
sub_810B6C4: @ 810B6C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r2, [r5, 0x4]
	lsls r1, r2, 22
	lsrs r1, 22
	adds r1, 0x7
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r0, [r4]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r4]
	movs r1, 0x3
	str r3, [sp]
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r1]
	ldr r3, [sp]
	adds r0, r3
	strh r0, [r5, 0x30]
	ldrh r0, [r1, 0x4]
	mov r4, r9
	adds r0, r4, r0
	strh r0, [r5, 0x32]
	ldrh r0, [r1, 0x2]
	adds r0, r6
	strh r0, [r5, 0x34]
	ldrh r0, [r1, 0x6]
	mov r7, r8
	adds r0, r7, r0
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A64EC
	adds r4, 0x20
	movs r0, 0x98
	lsls r0, 1
	mov r12, r0
	ldr r3, [sp]
	cmp r4, r12
	bhi _0810B79E
	adds r0, r7, 0
	adds r0, 0x20
	ldrh r1, [r5, 0x30]
	ldrh r2, [r5, 0x32]
	cmp r0, 0xE0
	bhi _0810B79E
	adds r4, r1, 0
	mov r10, r12
_0810B76A:
	mov r7, r9
	lsls r1, r7, 16
	asrs r1, 16
	adds r1, r4
	lsls r1, 16
	mov r7, r8
	lsls r0, r7, 16
	asrs r0, 16
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsrs r0, r1, 16
	mov r9, r0
	movs r7, 0x80
	lsls r7, 14
	adds r1, r7
	lsrs r1, 16
	cmp r1, r10
	bhi _0810B79E
	mov r1, r8
	lsls r0, r1, 16
	adds r0, r7
	lsrs r0, 16
	cmp r0, 0xE0
	bls _0810B76A
_0810B79E:
	ldrh r0, [r5, 0x30]
	negs r7, r0
	strh r7, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	negs r4, r0
	strh r4, [r5, 0x32]
	lsls r0, r3, 16
	movs r1, 0x80
	lsls r1, 14
	adds r0, r1
	lsrs r0, 16
	movs r2, 0x98
	lsls r2, 1
	mov r12, r2
	ldr r1, =gBattleAnimArgs
	mov r10, r1
	cmp r0, r12
	bhi _0810B80A
	lsls r1, r6, 16
	movs r2, 0x80
	lsls r2, 14
	adds r0, r1, r2
	b _0810B802
	.pool
_0810B7E0:
	lsls r1, r3, 16
	asrs r1, 16
	adds r1, r7
	lsls r1, 16
	asrs r0, r2, 16
	adds r0, r4
	lsls r0, 16
	lsrs r6, r0, 16
	lsrs r3, r1, 16
	movs r0, 0x80
	lsls r0, 14
	adds r1, r0
	lsrs r1, 16
	cmp r1, r12
	bhi _0810B80A
	lsls r1, r6, 16
	adds r0, r1, r0
_0810B802:
	lsrs r0, 16
	adds r2, r1, 0
	cmp r0, 0xE0
	bls _0810B7E0
_0810B80A:
	strh r3, [r5, 0x20]
	strh r6, [r5, 0x22]
	mov r1, r10
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	strh r3, [r5, 0x30]
	mov r2, r9
	strh r2, [r5, 0x32]
	strh r6, [r5, 0x34]
	mov r3, r8
	strh r3, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A64EC
	mov r7, r10
	ldrh r0, [r7, 0xA]
	strh r0, [r5, 0x34]
	ldrh r0, [r7, 0xC]
	strh r0, [r5, 0x36]
	ldr r0, =sub_810B848
	str r0, [r5, 0x1C]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B6C4

	thumb_func_start sub_810B848
sub_810B848: @ 810B848
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0810B8A0
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x38]
	adds r1, r2
	strh r1, [r4, 0x38]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x3A]
	adds r0, r2
	strh r0, [r4, 0x3A]
	strh r1, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x36]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810B8A6
_0810B8A0:
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810B8A6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810B848

	thumb_func_start sub_810B8AC
sub_810B8AC: @ 810B8AC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r4, 0x2E]
	movs r0, 0x3C
	strh r0, [r4, 0x30]
	movs r0, 0x9
	strh r0, [r4, 0x32]
	movs r0, 0x1E
	strh r0, [r4, 0x34]
	movs r0, 0xFE
	lsls r0, 8
	strh r0, [r4, 0x36]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =TranslateSpriteInGrowingCircleOverDuration
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B8AC

	thumb_func_start sub_810B8EC
sub_810B8EC: @ 810B8EC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x32]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810B92C
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r4, 0x32]
	ldrh r0, [r0, 0x4]
	subs r1, r0
	strh r1, [r4, 0x32]
	b _0810B936
	.pool
_0810B92C:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
_0810B936:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	movs r1, 0x3
	bl GetBattlerSpriteCoord
	lsls r0, 24
	ldr r1, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r2, [r1, 0x6]
	adds r0, r2
	strh r0, [r4, 0x36]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x2E]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =StartAnimLinearTranslation
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B8EC

	thumb_func_start sub_810B974
sub_810B974: @ 810B974
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810B990
	adds r0, r4, 0
	movs r1, 0x1
	bl InitSpritePosToAnimTarget
	b _0810B9C6
	.pool
_0810B990:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0x1
	bl SetAverageBattlerPositions
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810B9B6
	ldrh r0, [r5]
	negs r0, r0
	strh r0, [r5]
_0810B9B6:
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_0810B9C6:
	ldr r1, =sub_810B9E8
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r0, =RunStoredCallbackWhenAffineAnimEnds
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810B974

	thumb_func_start sub_810B9E8
sub_810B9E8: @ 810B9E8
	push {lr}
	adds r3, r0, 0
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
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
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	bne _0810BA1E
	adds r0, r3, 0
	bl DestroySpriteAndMatrix
_0810BA1E:
	pop {r0}
	bx r0
	thumb_func_end sub_810B9E8

	thumb_func_start sub_810BA24
sub_810BA24: @ 810BA24
	push {r4-r7,lr}
	sub sp, 0x10
	adds r5, r0, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r6, =gBattleAnimArgs
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BA74
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
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r5, 0x36]
	b _0810BA86
	.pool
_0810BA74:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl SetAverageBattlerPositions
_0810BA86:
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BAAC
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r5, 0x32]
	ldrh r0, [r0, 0x4]
	subs r1, r0
	strh r1, [r5, 0x32]
	b _0810BAB6
	.pool
_0810BAAC:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x4]
	ldrh r2, [r5, 0x32]
	adds r0, r2
	strh r0, [r5, 0x32]
_0810BAB6:
	adds r7, r5, 0
	adds r7, 0x2E
	adds r2, r7, 0
	mov r1, sp
	movs r4, 0x7
_0810BAC0:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BAC0
	adds r0, r5, 0
	bl InitAnimFastLinearTranslationWithSpeed
	ldrh r0, [r5, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	eors r0, r1
	strh r0, [r5, 0x32]
_0810BAE2:
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	bl AnimFastTranslateLinear
	movs r0, 0x20
	ldrsh r1, [r5, r0]
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	adds r1, r0
	adds r1, 0x10
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bhi _0810BB16
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810BB16
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BAE2
_0810BB16:
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
	ldr r6, =sub_80A718C
	ldr r1, =sub_810BB60
	mov r3, sp
	adds r2, r7, 0
	movs r4, 0x7
_0810BB36:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BB36
	str r6, [r5, 0x1C]
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BA24

	thumb_func_start sub_810BB60
sub_810BB60: @ 810BB60
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r5, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x26]
	strh r5, [r4, 0x24]
	movs r0, 0x80
	strh r0, [r4, 0x2E]
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	ldr r1, =0x0000ffec
	cmp r0, 0
	beq _0810BB90
	movs r1, 0x14
_0810BB90:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r1, 16
	asrs r1, 16
	bl Sin
	strh r0, [r4, 0x34]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0xF
	bl Cos
	strh r0, [r4, 0x36]
	strh r5, [r4, 0x38]
	ldr r1, =sub_810BBC8
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BB60

	thumb_func_start sub_810BBC8
sub_810BBC8: @ 810BBC8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	ldr r1, =0x0000ffec
	cmp r0, 0
	beq _0810BBDE
	movs r1, 0x14
_0810BBDE:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0x1F
	bgt _0810BC24
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r1, 16
	asrs r1, 16
	bl Sin
	ldrh r1, [r4, 0x34]
	subs r0, r1
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r1, 0xF
	bl Cos
	ldrh r1, [r4, 0x36]
	subs r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x10
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	b _0810BC42
	.pool
_0810BC24:
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x26]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x36]
	strh r1, [r4, 0x34]
	ldr r0, =sub_810BC4C
	str r0, [r4, 0x1C]
_0810BC42:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BBC8

	thumb_func_start sub_810BC4C
sub_810BC4C: @ 810BC4C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	adds r0, r4, 0
	bl AnimFastTranslateLinear
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x10
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	bhi _0810BC88
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r1, r0, r1
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	bgt _0810BC88
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BC8E
_0810BC88:
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810BC8E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810BC4C

	thumb_func_start sub_810BC94
sub_810BC94: @ 810BC94
	push {r4-r7,lr}
	sub sp, 0x10
	adds r5, r0, 0
	movs r1, 0x1
	bl InitSpritePosToAnimAttacker
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0810BCE0
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
	b _0810BCF2
	.pool
_0810BCE0:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x32
	adds r3, r5, 0
	adds r3, 0x36
	movs r1, 0x1
	bl SetAverageBattlerPositions
_0810BCF2:
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BD1C
	ldr r0, =gBattleAnimArgs
	ldrh r1, [r5, 0x32]
	ldrh r2, [r0, 0x4]
	subs r1, r2
	strh r1, [r5, 0x32]
	adds r1, r0, 0
	b _0810BD26
	.pool
_0810BD1C:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x4]
	ldrh r2, [r5, 0x32]
	adds r0, r2
	strh r0, [r5, 0x32]
_0810BD26:
	ldrh r0, [r1, 0x6]
	ldrh r1, [r5, 0x36]
	adds r0, r1
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl InitAnimFastLinearTranslationWithSpeed
	adds r7, r5, 0
	adds r7, 0x2E
	adds r2, r7, 0
	mov r1, sp
	movs r4, 0x7
_0810BD3E:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BD3E
	ldrh r0, [r5, 0x30]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	eors r0, r1
	strh r0, [r5, 0x32]
_0810BD5A:
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	adds r0, r5, 0
	bl AnimFastTranslateLinear
	movs r2, 0x20
	ldrsh r1, [r5, r2]
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	adds r1, r0
	adds r1, 0x10
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bhi _0810BD8E
	movs r0, 0x22
	ldrsh r1, [r5, r0]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810BD8E
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BD5A
_0810BD8E:
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
	ldr r1, =gBattleAnimArgs
	ldr r6, =sub_810BDD8
	mov r3, sp
	adds r2, r7, 0
	movs r4, 0x7
_0810BDAE:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0810BDAE
	ldrh r0, [r1, 0xA]
	strh r0, [r5, 0x38]
	ldrh r0, [r1, 0xC]
	strh r0, [r5, 0x3A]
	str r6, [r5, 0x1C]
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BC94

	thumb_func_start sub_810BDD8
sub_810BDD8: @ 810BDD8
	push {r4,lr}
	adds r4, r0, 0
	bl AnimFastTranslateLinear
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810BDEC
	movs r0, 0x1
	strh r0, [r4, 0x2E]
_0810BDEC:
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	ldrh r2, [r4, 0x3C]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x3C]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _0810BE42
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	adds r0, 0x10
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	bhi _0810BE3C
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	adds r1, r0
	cmp r1, 0xA0
	bgt _0810BE3C
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _0810BE42
_0810BE3C:
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810BE42:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810BDD8

	thumb_func_start sub_810BE48
sub_810BE48: @ 810BE48
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810BEB4
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810BE6C
	adds r0, r4, 0
	movs r1, 0
	bl InitSpritePosToAnimTarget
	b _0810BEA2
	.pool
_0810BE6C:
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r2, r4, 0
	adds r2, 0x20
	adds r3, r4, 0
	adds r3, 0x22
	movs r1, 0
	bl SetAverageBattlerPositions
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BE92
	ldrh r0, [r5]
	negs r0, r0
	strh r0, [r5]
_0810BE92:
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_0810BEA2:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0810BEC8
	.pool
_0810BEB4:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0810BEC8
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810BEC8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_810BE48

	thumb_func_start sub_810BED0
sub_810BED0: @ 810BED0
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BF40
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BEF4
	adds r0, r5, 0
	movs r1, 0
	bl InitSpritePosToAnimAttacker
	b _0810BF32
	.pool
_0810BEF4:
	ldr r4, =gBattleAnimAttacker
	ldrb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl SetAverageBattlerPositions
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BF20
	ldrh r0, [r5, 0x20]
	ldrh r1, [r6]
	subs r0, r1
	b _0810BF26
	.pool
_0810BF20:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_0810BF26:
	strh r0, [r5, 0x20]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
_0810BF32:
	ldr r0, =gBattleAnimAttacker
	b _0810BF90
	.pool
_0810BF40:
	movs r1, 0xA
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0810BF52
	adds r0, r5, 0
	movs r1, 0
	bl InitSpritePosToAnimTarget
	b _0810BF8E
_0810BF52:
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl SetAverageBattlerPositions
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810BF7C
	ldrh r0, [r5, 0x20]
	ldrh r1, [r6]
	subs r0, r1
	b _0810BF82
	.pool
_0810BF7C:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_0810BF82:
	strh r0, [r5, 0x20]
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0, 0x2]
	ldrh r1, [r5, 0x22]
	adds r0, r1
	strh r0, [r5, 0x22]
_0810BF8E:
	ldr r0, =gBattleAnimTarget
_0810BF90:
	ldrb r0, [r0]
	strh r0, [r5, 0x3C]
	ldr r0, =gBattleAnimArgs
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0810BFA8
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _0810BFB4
_0810BFA8:
	movs r0, 0x20
	b _0810BFB6
	.pool
_0810BFB4:
	movs r0, 0x40
_0810BFB6:
	strh r0, [r5, 0x3A]
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _0810BFCC
	ldrh r0, [r5, 0x22]
	adds r0, 0x8
	strh r0, [r5, 0x22]
_0810BFCC:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x22]
	strh r0, [r5, 0x34]
	ldrh r1, [r1, 0x4]
	adds r0, r1
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl InitAnimLinearTranslation
	movs r0, 0x40
	strh r0, [r5, 0x38]
	ldr r1, =sub_810C008
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810BED0

	thumb_func_start sub_810C008
sub_810C008: @ 810C008
	push {r4,lr}
	adds r4, r0, 0
	bl AnimTranslateLinear
	lsls r0, 24
	cmp r0, 0
	bne _0810C092
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x3A
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r1, 0x6
	negs r1, r1
	bl Cos
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x38]
	subs r0, 0x40
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7F
	bhi _0810C064
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
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
	b _0810C086
_0810C064:
	ldrh r0, [r4, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bl GetBattlerSpriteBGPriority
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r4, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
_0810C086:
	ldrh r0, [r4, 0x38]
	adds r0, 0x3
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	b _0810C098
_0810C092:
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810C098:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810C008

	thumb_func_start sub_810C0A0
sub_810C0A0: @ 810C0A0
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
	bne _0810C0E2
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetAnimBgAttribute
_0810C0E2:
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
	ldr r1, =sub_810C164
	str r1, [r0]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C0A0

	thumb_func_start sub_810C164
sub_810C164: @ 810C164
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gBattle_BG1_X
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x20
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _0810C18E
	b _0810C2DA
_0810C18E:
	lsls r0, 2
	ldr r1, =_0810C1A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0810C1A8:
	.4byte _0810C1BC
	.4byte _0810C214
	.4byte _0810C236
	.4byte _0810C27A
	.4byte _0810C29C
_0810C1BC:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _0810C1D6
	b _0810C2DA
_0810C1D6:
	strh r5, [r4, 0x1C]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	ldr r1, =gUnknown_08595C5C
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r1, [r0]
	strh r1, [r4, 0x1E]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0x9
	bne _0810C2DA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x1E]
	b _0810C2DA
	.pool
_0810C214:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _0810C2DA
	movs r0, 0x9
	strh r0, [r1, 0x1E]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _0810C2DA
_0810C236:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _0810C2DA
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
	bne _0810C2DA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _0810C2DA
_0810C27A:
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
_0810C29C:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _0810C2B0
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl SetAnimBgAttribute
_0810C2B0:
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
_0810C2DA:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C164

	thumb_func_start sub_810C2F0
sub_810C2F0: @ 810C2F0
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
	ldr r0, =TranslateAnimSpriteToTargetMonLocation
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810C2F0

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
