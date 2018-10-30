	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_810DBAC
sub_810DBAC: @ 810DBAC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810DBC2
	adds r0, r5, 0
	movs r1, 0x2
	bl StartSpriteAnim
_0810DBC2:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldrh r0, [r4, 0x4]
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
	ldr r0, =0x0000ffe2
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	ldr r0, =sub_810DC10
	str r0, [r5, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DBAC

	thumb_func_start sub_810DC10
sub_810DC10: @ 810DC10
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _0810DC24
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810DC24:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DC10

	thumb_func_start sub_810DC2C
sub_810DC2C: @ 810DC2C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810DC44
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
_0810DC44:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A69CC
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	mov r6, sp
	adds r6, 0x2
	movs r1, 0x1
	mov r2, sp
	adds r3, r6, 0
	bl SetAverageBattlerPositions
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _0810DC72
	ldrh r0, [r5, 0x8]
	negs r0, r0
	strh r0, [r5, 0x8]
_0810DC72:
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	mov r1, sp
	ldrh r0, [r5, 0x8]
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0xA]
	ldrh r6, [r6]
	adds r0, r6
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffe2
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_810DCB4
	str r0, [r4, 0x1C]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DC2C

	thumb_func_start sub_810DCB4
sub_810DCB4: @ 810DCB4
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _0810DCC8
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810DCC8:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DCB4

	thumb_func_start sub_810DCD0
sub_810DCD0: @ 810DCD0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrh r0, [r5, 0x4]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	ldrh r1, [r5, 0x2]
	adds r0, r1
	strh r0, [r4, 0x36]
	adds r0, r4, 0
	bl sub_80A6E14
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r4, 0x38]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r4, 0x3A]
	ldr r0, =sub_810DD24
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DCD0

	thumb_func_start sub_810DD24
sub_810DD24: @ 810DD24
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A656C
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x38]
	subs r0, r1
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x32]
	ldrh r1, [r4, 0x3A]
	subs r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0810DD4A
	adds r0, r4, 0
	bl DestroyAnimSprite
_0810DD4A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_810DD24

	thumb_func_start sub_810DD50
sub_810DD50: @ 810DD50
	push {r4,lr}
	adds r4, r0, 0
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
	beq _0810DD7C
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1]
	negs r0, r0
	strh r0, [r1]
_0810DD7C:
	ldr r0, =gBattleAnimArgs
	ldrh r2, [r0]
	ldrh r1, [r4, 0x20]
	adds r2, r1
	strh r2, [r4, 0x20]
	ldrh r1, [r0, 0x2]
	ldrh r3, [r4, 0x22]
	adds r1, r3
	strh r1, [r4, 0x22]
	ldrh r3, [r0, 0x8]
	strh r3, [r4, 0x2E]
	ldrh r0, [r0, 0x4]
	adds r2, r0
	strh r2, [r4, 0x32]
	adds r1, r3
	strh r1, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DD50

	thumb_func_start sub_810DDC4
sub_810DDC4: @ 810DDC4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0810DDE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80A6980
	b _0810DE16
	.pool
_0810DDE0:
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
	beq _0810DE06
	ldrh r0, [r5]
	negs r0, r0
	strh r0, [r5]
_0810DE06:
	ldrh r0, [r5]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_0810DE16:
	ldr r0, =sub_810DE2C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_810DDC4

	.align 2, 0
