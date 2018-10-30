	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81109F0
sub_81109F0: @ 81109F0
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gBattleAnimArgs
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08110A10
	ldr r0, =gBattleAnimTarget
	ldrb r0, [r0]
	adds r2, r5, 0
	adds r2, 0x20
	adds r3, r5, 0
	adds r3, 0x22
	movs r1, 0
	bl SetAverageBattlerPositions
_08110A10:
	ldrh r0, [r6]
	ldrh r1, [r5, 0x20]
	adds r0, r1
	movs r4, 0
	strh r0, [r5, 0x20]
	ldrh r0, [r5, 0x22]
	adds r0, 0xE
	strh r0, [r5, 0x22]
	ldrb r1, [r6, 0x2]
	adds r0, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0
	bl AnimateSprite
	strh r4, [r5, 0x2E]
	strh r4, [r5, 0x30]
	movs r0, 0x4
	strh r0, [r5, 0x32]
	movs r0, 0x10
	strh r0, [r5, 0x34]
	ldr r0, =0x0000ffba
	strh r0, [r5, 0x36]
	ldrh r0, [r6, 0x4]
	strh r0, [r5, 0x38]
	ldr r1, =sub_8110A70
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A6450
	str r1, [r5, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81109F0

	thumb_func_start sub_8110A70
sub_8110A70: @ 8110A70
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x38]
	ldrh r2, [r4, 0x20]
	adds r0, r1, r2
	strh r0, [r4, 0x20]
	movs r0, 0xC0
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x30]
	movs r0, 0x4
	strh r0, [r4, 0x32]
	movs r0, 0x20
	strh r0, [r4, 0x34]
	ldr r0, =0x0000ffe8
	strh r0, [r4, 0x36]
	ldr r1, =move_anim_8074EE0
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	ldr r1, =sub_80A6450
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110A70

	thumb_func_start sub_8110AB4
sub_8110AB4: @ 8110AB4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gBattleAnimArgs
	ldrb r1, [r4, 0xA]
	bl StartSpriteAnim
	adds r0, r5, 0
	bl AnimateSprite
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08110AE4
	ldrh r0, [r5, 0x20]
	ldrh r1, [r4]
	subs r0, r1
	b _08110AEA
	.pool
_08110AE4:
	ldrh r0, [r4]
	ldrh r1, [r5, 0x20]
	adds r0, r1
_08110AEA:
	strh r0, [r5, 0x20]
	ldr r3, =gBattleAnimArgs
	ldrh r2, [r3, 0x2]
	ldrh r0, [r5, 0x22]
	adds r2, r0
	movs r4, 0
	strh r2, [r5, 0x22]
	ldrh r0, [r3, 0x8]
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x30]
	ldrh r1, [r3, 0x4]
	adds r0, r1
	strh r0, [r5, 0x32]
	strh r2, [r5, 0x34]
	ldrh r0, [r3, 0x6]
	adds r2, r0
	strh r2, [r5, 0x36]
	adds r0, r5, 0
	bl sub_80A6E14
	strh r4, [r5, 0x34]
	strh r4, [r5, 0x36]
	ldr r0, =sub_80A656C
	str r0, [r5, 0x1C]
	ldr r1, =move_anim_8074EE0
	adds r0, r5, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110AB4

	thumb_func_start sub_8110B38
sub_8110B38: @ 8110B38
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimArgs
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08110B54
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	b _08110B5C
	.pool
_08110B54:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A6980
_08110B5C:
	ldr r1, =gBattleAnimArgs
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0x30]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x32]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x34]
	ldr r0, =sub_8110B80
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110B38

	thumb_func_start sub_8110B80
sub_8110B80: @ 8110B80
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x36]
	adds r0, r1
	strh r0, [r4, 0x36]
	lsls r0, 16
	asrs r0, 24
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	ldrh r1, [r4, 0x38]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x2E]
	subs r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08110BC6
	adds r0, r4, 0
	bl DestroyAnimSprite
_08110BC6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8110B80

	thumb_func_start AnimTask_LoadSandstormBackground
AnimTask_LoadSandstormBackground: @ 8110BCC
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
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
	bne _08110C10
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetAnimBgAttribute
_08110C10:
	ldr r0, =gBattle_BG1_X
	strh r5, [r0]
	ldr r4, =gBattle_BG1_Y
	strh r5, [r4]
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
	ldr r1, =gUnknown_08D8D58C
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r1, =gUnknown_08D8D410
	mov r0, sp
	movs r2, 0
	bl sub_80A6D60
	ldr r0, =gBattleAnimSpritePalette_261
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08110C6E
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08110C6E
	movs r5, 0x1
_08110C6E:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	strh r5, [r1, 0x8]
	ldr r0, =sub_8110CB0
	str r0, [r1]
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_LoadSandstormBackground

	thumb_func_start sub_8110CB0
sub_8110CB0: @ 8110CB0
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0
	bne _08110CE4
	ldr r1, =gBattle_BG1_X
	ldr r3, =0x0000fffa
	adds r0, r3, 0
	ldrh r3, [r1]
	adds r0, r3
	b _08110CEA
	.pool
_08110CE4:
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r1]
	adds r0, 0x6
_08110CEA:
	strh r0, [r1]
	ldr r1, =gBattle_BG1_Y
	ldr r3, =0x0000ffff
	adds r0, r3, 0
	ldrh r3, [r1]
	adds r0, r3
	strh r0, [r1]
	lsls r1, r5, 2
	adds r0, r1, r5
	lsls r0, 3
	adds r0, r2
	movs r3, 0x20
	ldrsh r0, [r0, r3]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _08110D0C
	b _08110E3A
_08110D0C:
	lsls r0, 2
	ldr r1, =_08110D28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08110D28:
	.4byte _08110D3C
	.4byte _08110D7E
	.4byte _08110D98
	.4byte _08110DDA
	.4byte _08110DFC
_08110D3C:
	adds r0, r4, r5
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08110E3A
	strh r5, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	adds r1, 0x1
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
	cmp r0, 0x7
	bne _08110E3A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x1E]
	b _08110E3A
_08110D7E:
	adds r0, r4, r5
	lsls r0, 3
	adds r1, r0, r2
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x65
	bne _08110E3A
	movs r0, 0x7
	strh r0, [r1, 0x1E]
	b _08110DF0
_08110D98:
	adds r0, r4, r5
	lsls r0, 3
	adds r4, r0, r2
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bne _08110E3A
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
	bne _08110E3A
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x1E]
	b _08110E3A
_08110DDA:
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	bl sub_80A6C68
	ldr r0, =gTasks
	adds r1, r4, r5
	lsls r1, 3
	adds r1, r0
_08110DF0:
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	b _08110E3A
	.pool
_08110DFC:
	bl IsContest
	lsls r0, 24
	cmp r0, 0
	bne _08110E10
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl SetAnimBgAttribute
_08110E10:
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
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08110E3A:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110CB0

	thumb_func_start sub_8110E4C
sub_8110E4C: @ 8110E4C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08110EC8
	ldr r4, =gBattleAnimArgs
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08110E98
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	beq _08110E98
	movs r0, 0x98
	lsls r0, 1
	strh r0, [r5, 0x20]
	ldrh r0, [r4, 0x2]
	negs r0, r0
	strh r0, [r4, 0x2]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	ldrb r1, [r5, 0x3]
	subs r0, 0x40
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r5, 0x3]
	b _08110E9C
	.pool
_08110E98:
	ldr r0, =0x0000ffc0
	strh r0, [r5, 0x20]
_08110E9C:
	ldr r4, =gBattleAnimArgs
	ldrh r0, [r4]
	strh r0, [r5, 0x22]
	ldr r1, =gUnknown_08596BC0
	adds r0, r5, 0
	bl SetSubspriteTables
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0x30]
	ldrh r0, [r4, 0x4]
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _08110F24
	.pool
_08110EC8:
	ldrh r1, [r5, 0x30]
	ldrh r3, [r5, 0x34]
	adds r1, r3
	ldrh r2, [r5, 0x32]
	ldrh r0, [r5, 0x36]
	adds r2, r0
	lsls r0, r1, 16
	asrs r0, 24
	ldrh r3, [r5, 0x24]
	adds r0, r3
	strh r0, [r5, 0x24]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r3, [r5, 0x26]
	adds r0, r3
	strh r0, [r5, 0x26]
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r5, 0x34]
	ands r2, r0
	strh r2, [r5, 0x36]
	movs r1, 0x38
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08110F0E
	movs r2, 0x20
	ldrsh r0, [r5, r2]
	movs r3, 0x24
	ldrsh r1, [r5, r3]
	adds r0, r1
	movs r1, 0x88
	lsls r1, 1
	cmp r0, r1
	ble _08110F24
	b _08110F20
_08110F0E:
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	adds r0, r1
	movs r1, 0x20
	negs r1, r1
	cmp r0, r1
	bge _08110F24
_08110F20:
	ldr r0, =DestroyAnimSprite
	str r0, [r5, 0x1C]
_08110F24:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110E4C

	thumb_func_start sub_8110F30
sub_8110F30: @ 8110F30
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x8]
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A69CC
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x32]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x36]
	ldr r0, =sub_80A6EEC
	str r0, [r4, 0x1C]
	ldr r1, =DestroyAnimSprite
	adds r0, r4, 0
	bl StoreSpriteCallbackInData6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110F30

	thumb_func_start sub_8110F74
sub_8110F74: @ 8110F74
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	ldr r5, =gBattleAnimAttacker
	ldrb r0, [r5]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r0, [r5]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 8
	movs r1, 0xC0
	lsls r1, 13
	adds r0, r1
	lsrs r7, r0, 16
	ldr r4, =gBattleAnimTarget
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldrb r0, [r4]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 8
	movs r2, 0xC0
	lsls r2, 13
	adds r0, r2
	lsrs r0, 16
	mov r8, r0
	ldrb r1, [r5]
	movs r0, 0x2
	eors r0, r1
	ldrb r4, [r4]
	cmp r0, r4
	bne _08110FE4
	mov r8, r7
_08110FE4:
	bl sub_811135C
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bne _08111000
	movs r0, 0x20
	b _08111006
	.pool
_08111000:
	lsls r1, r5, 3
	movs r0, 0x30
	subs r0, r1
_08111006:
	strh r0, [r6, 0x18]
	movs r4, 0
	strh r4, [r6, 0x8]
	strh r4, [r6, 0x1E]
	strh r4, [r6, 0x1A]
	movs r0, 0x1
	strh r0, [r6, 0x20]
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bge _0811101E
	adds r0, 0x7
_0811101E:
	asrs r0, 3
	subs r0, 0x1
	strh r0, [r6, 0x1C]
	mov r2, r9
	lsls r0, r2, 3
	strh r0, [r6, 0xC]
	lsls r0, r7, 3
	strh r0, [r6, 0xE]
	mov r1, r10
	subs r0, r1, r2
	lsls r0, 3
	movs r2, 0x18
	ldrsh r1, [r6, r2]
	bl __divsi3
	strh r0, [r6, 0x10]
	mov r1, r8
	subs r0, r1, r7
	lsls r0, 3
	movs r2, 0x18
	ldrsh r1, [r6, r2]
	bl __divsi3
	strh r0, [r6, 0x12]
	strh r4, [r6, 0x14]
	strh r4, [r6, 0x16]
	movs r0, 0x40
	negs r0, r0
	bl BattleAnimAdjustPanning
	adds r4, r0, 0
	lsls r4, 24
	asrs r4, 8
	lsrs r4, 16
	movs r0, 0x3F
	bl BattleAnimAdjustPanning
	lsls r0, 24
	strh r4, [r6, 0x22]
	asrs r0, 24
	lsls r4, 16
	asrs r4, 16
	subs r0, r4
	movs r2, 0x18
	ldrsh r1, [r6, r2]
	bl __divsi3
	strh r0, [r6, 0x24]
	strh r5, [r6, 0xA]
	movs r0, 0
	bl GetAnimBattlerSpriteId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x26]
	ldr r0, =sub_81110A4
	str r0, [r6]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8110F74

	thumb_func_start sub_81110A4
sub_81110A4: @ 81110A4
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
	bls _081110BE
	b _0811120C
_081110BE:
	lsls r0, 2
	ldr r1, =_081110D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081110D0:
	.4byte _081110E4
	.4byte _08111148
	.4byte _08111150
	.4byte _081111AC
	.4byte _081111FE
_081110E4:
	ldrh r2, [r4, 0x14]
	ldrh r0, [r4, 0x10]
	subs r2, r0
	strh r2, [r4, 0x14]
	ldrh r0, [r4, 0x16]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x16]
	ldr r3, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	lsls r2, 16
	asrs r2, 19
	strh r2, [r0, 0x24]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r0, [r4, 0x16]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08111134
	movs r0, 0x14
	strh r0, [r4, 0x1E]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_08111134:
	ldrh r1, [r4, 0x22]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xA2
	bl PlaySE12WithPanning
	b _0811120C
	.pool
_08111148:
	ldrh r0, [r4, 0x1E]
	subs r0, 0x1
	strh r0, [r4, 0x1E]
	b _081111F0
_08111150:
	ldrh r0, [r4, 0x1A]
	subs r0, 0x1
	strh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _08111170
	ldrh r0, [r4, 0x10]
	ldrh r2, [r4, 0x14]
	adds r0, r2
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	strh r0, [r4, 0x16]
	b _0811117A
_08111170:
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x16]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0811117A:
	ldr r2, =gSprites
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r4, 0x14]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r1, 0x24]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r4, 0x16]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r1, 0x26]
	b _0811120C
	.pool
_081111AC:
	ldrh r0, [r4, 0x10]
	ldrh r2, [r4, 0xC]
	adds r0, r2
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x12]
	ldrh r1, [r4, 0xE]
	adds r0, r1
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _081111EA
	movs r0, 0
	strh r0, [r4, 0x1A]
	adds r0, r4, 0
	bl sub_8111214
	ldrh r1, [r4, 0x24]
	ldrh r0, [r4, 0x22]
	adds r1, r0
	strh r1, [r4, 0x22]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0xAF
	bl PlaySE12WithPanning
_081111EA:
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
_081111F0:
	lsls r0, 16
	cmp r0, 0
	bne _0811120C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0811120C
_081111FE:
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0811120C
	adds r0, r2, 0
	bl DestroyAnimVisualTask
_0811120C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81110A4

	thumb_func_start sub_8111214
sub_8111214: @ 8111214
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _08111304
	lsls r0, 2
	ldr r1, =_08111234
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08111234:
	.4byte _08111248
	.4byte _08111254
	.4byte _08111254
	.4byte _08111260
	.4byte _0811126C
_08111248:
	ldr r3, =gUnknown_08596C28
	movs r5, 0
	b _08111270
	.pool
_08111254:
	ldr r3, =gUnknown_08596C40
	movs r5, 0x50
	b _08111270
	.pool
_08111260:
	ldr r3, =gUnknown_08596C40
	movs r5, 0x40
	b _08111270
	.pool
_0811126C:
	ldr r3, =gUnknown_08596C40
	movs r5, 0x30
_08111270:
	ldrh r1, [r4, 0xC]
	lsls r1, 16
	asrs r1, 19
	lsls r1, 16
	lsrs r1, 16
	ldrh r2, [r4, 0xE]
	lsls r2, 16
	asrs r2, 19
	lsls r2, 16
	movs r6, 0x20
	ldrsh r0, [r4, r6]
	lsls r0, 2
	adds r1, r0
	lsls r1, 16
	lsrs r6, r1, 16
	asrs r1, 16
	lsrs r7, r2, 16
	asrs r2, 16
	adds r0, r3, 0
	movs r3, 0x23
	bl CreateSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081112FC
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x12
	strh r1, [r0, 0x2E]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	lsls r2, r1, 2
	adds r2, r1
	lsls r2, 2
	adds r2, r6, r2
	movs r6, 0xA
	ldrsh r3, [r4, r6]
	lsls r1, r3, 1
	adds r1, r3
	adds r2, r1
	strh r2, [r0, 0x32]
	strh r7, [r0, 0x36]
	movs r1, 0xA
	ldrsh r2, [r4, r1]
	lsls r2, 1
	movs r3, 0x10
	negs r3, r3
	adds r1, r3, 0
	subs r1, r2
	strh r1, [r0, 0x38]
	ldrh r3, [r0, 0x4]
	lsls r2, r3, 22
	lsrs r2, 22
	adds r2, r5
	ldr r5, =0x000003ff
	adds r1, r5, 0
	ands r2, r1
	ldr r1, =0xfffffc00
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x4]
	bl sub_80A68D4
	ldrh r0, [r4, 0x1E]
	adds r0, 0x1
	strh r0, [r4, 0x1E]
_081112FC:
	movs r6, 0x20
	ldrsh r0, [r4, r6]
	negs r0, r0
	strh r0, [r4, 0x20]
_08111304:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111214

	thumb_func_start sub_811131C
sub_811131C: @ 811131C
	push {r4,lr}
	adds r4, r0, 0
	bl TranslateAnimArc
	lsls r0, 24
	cmp r0, 0
	beq _0811134E
	ldr r0, =sub_81110A4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _08111348
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x1E]
	subs r0, 0x1
	strh r0, [r1, 0x1E]
_08111348:
	adds r0, r4, 0
	bl DestroySprite
_0811134E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811131C

	thumb_func_start sub_811135C
sub_811135C: @ 811135C
	push {lr}
	ldr r0, =gAnimDisableStructPtr
	ldr r0, [r0]
	ldrb r1, [r0, 0x11]
	lsrs r0, r1, 4
	lsls r1, 28
	lsrs r1, 28
	subs r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x4
	bls _0811137E
	movs r1, 0x1
_0811137E:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811135C

	thumb_func_start sub_8111388
sub_8111388: @ 8111388
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimArgs
	ldrb r1, [r5, 0x8]
	bl StartSpriteAnim
	ldrh r0, [r5]
	strh r0, [r4, 0x24]
	ldrh r0, [r5, 0x2]
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	ldrh r1, [r5, 0x4]
	subs r0, r1
	strh r0, [r4, 0x34]
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x30]
	ldr r0, =sub_81113C8
	str r0, [r4, 0x1C]
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111388

	thumb_func_start sub_81113C8
sub_81113C8: @ 81113C8
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r3]
	ldrh r1, [r2, 0x34]
	movs r3, 0x34
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08111400
	ldrh r3, [r2, 0x32]
	adds r0, r1, r3
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x2E]
	adds r1, r0
	strh r1, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r1, 16
	cmp r1, 0
	ble _08111412
	movs r0, 0
	strh r0, [r2, 0x34]
	b _08111412
_08111400:
	ldrh r0, [r2, 0x30]
	subs r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _08111412
	adds r0, r2, 0
	bl DestroyAnimSprite
_08111412:
	pop {r0}
	bx r0
	thumb_func_end sub_81113C8

	thumb_func_start sub_8111418
sub_8111418: @ 8111418
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gBattleAnimAttacker
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08111434
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_08111434:
	adds r0, r4, 0
	bl TranslateAnimSpriteToTargetMonLocation
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111418

	thumb_func_start sub_8111444
sub_8111444: @ 8111444
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gBattleAnimTarget
	ldrb r0, [r5]
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	ldrb r0, [r5]
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleAnimArgs
	ldrh r3, [r2]
	ldrh r5, [r4, 0x20]
	adds r1, r3, r5
	strh r1, [r4, 0x20]
	ldrh r1, [r2, 0x2]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r3, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldrh r0, [r2, 0x4]
	strh r0, [r4, 0x38]
	ldrb r1, [r2, 0x6]
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_811149C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111444

	thumb_func_start sub_811149C
sub_811149C: @ 811149C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x2E]
	adds r0, 0x8
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x30]
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	ldrh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	adds r0, r2
	strh r0, [r4, 0x36]
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	movs r1, 0x28
	bl __divsi3
	ldrh r1, [r4, 0x24]
	adds r1, r0
	strh r1, [r4, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, 0x26]
	subs r1, r0
	strh r1, [r4, 0x26]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x8C
	ble _081114E6
	adds r0, r4, 0
	bl DestroyAnimSprite
_081114E6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811149C

	thumb_func_start AnimTask_GetSeismicTossDamageLevel
AnimTask_GetSeismicTossDamageLevel: @ 81114EC
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gAnimMoveDmg
	ldr r0, [r2]
	cmp r0, 0x20
	bgt _08111500
	ldr r1, =gBattleAnimArgs
	movs r0, 0
	strh r0, [r1, 0xE]
_08111500:
	ldr r2, [r2]
	adds r0, r2, 0
	subs r0, 0x21
	cmp r0, 0x20
	bhi _08111510
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	strh r0, [r1, 0xE]
_08111510:
	cmp r2, 0x41
	ble _0811151A
	ldr r1, =gBattleAnimArgs
	movs r0, 0x2
	strh r0, [r1, 0xE]
_0811151A:
	adds r0, r3, 0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end AnimTask_GetSeismicTossDamageLevel

	thumb_func_start sub_811152C
sub_811152C: @ 811152C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0811154E
	movs r0, 0
	bl sub_80A6DAC
	movs r0, 0xC8
	strh r0, [r5, 0xA]
_0811154E:
	ldr r4, =gBattle_BG3_Y
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	movs r1, 0xA
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r0
	strh r1, [r4]
	ldrh r0, [r5, 0xA]
	subs r0, 0x3
	strh r0, [r5, 0xA]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x78
	bne _0811157A
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_0811157A:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811152C

	thumb_func_start sub_8111590
sub_8111590: @ 8111590
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081115BC
	movs r0, 0
	bl sub_80A6DAC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gBattle_BG3_Y
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
_081115BC:
	ldrh r0, [r4, 0xA]
	adds r0, 0x50
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0xA]
	ldr r6, =gBattle_BG3_Y
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r0, 0x4
	bl Cos
	ldrh r4, [r4, 0xC]
	adds r0, r4
	strh r0, [r6]
	ldr r0, =gBattleAnimArgs
	movs r2, 0xE
	ldrsh r1, [r0, r2]
	ldr r0, =0x00000fff
	cmp r1, r0
	bne _081115F4
	movs r0, 0
	strh r0, [r6]
	movs r0, 0x1
	bl sub_80A6DAC
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_081115F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8111590

	.align 2, 0
