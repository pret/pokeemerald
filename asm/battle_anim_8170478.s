	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8170478
sub_8170478: @ 8170478
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	ldr r0, =gAnimBankAttacker
	ldrb r4, [r0]
	ldr r0, =gBattle_WIN0H
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_WIN0V
	strh r1, [r0]
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
	movs r1, 0x80
	lsls r1, 5
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
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	bl SetAnimBgAttribute
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetAnimBgAttribute
	ldr r0, =gHealthBoxesIds
	adds r4, r0
	ldrb r0, [r4]
	ldr r1, =gSprites
	mov r9, r1
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	add r4, r9
	ldrb r7, [r4, 0x6]
	ldrh r6, [r4, 0x38]
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =SpriteCallbackDummy
	bl CreateInvisibleSpriteWithCallback
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	ldr r0, =SpriteCallbackDummy
	bl CreateInvisibleSpriteWithCallback
	mov r10, r0
	mov r2, r10
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	ldrb r1, [r4, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x4
	mov r8, r1
	mov r2, r8
	orrs r0, r2
	strb r0, [r4, 0x5]
	lsls r5, r7, 4
	adds r5, r7
	lsls r5, 2
	add r5, r9
	ldrb r1, [r5, 0x5]
	adds r0, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x5]
	adds r0, r3, 0
	ands r0, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [sp, 0x14]
	lsls r6, r0, 4
	adds r6, r0
	lsls r6, 2
	mov r1, r9
	adds r7, r6, r1
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x44
	str r3, [sp, 0x18]
	bl memcpy
	mov r2, r10
	lsls r4, r2, 4
	add r4, r10
	lsls r4, 2
	adds r0, r4, 0
	add r0, r9
	mov r8, r0
	adds r1, r5, 0
	movs r2, 0x44
	bl memcpy
	ldrb r1, [r7, 0x1]
	ldr r3, [sp, 0x18]
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r7, 0x1]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	ands r3, r0
	orrs r3, r1
	strb r3, [r2, 0x1]
	movs r0, 0x1C
	add r9, r0
	add r6, r9
	ldr r1, =SpriteCallbackDummy
	str r1, [r6]
	add r4, r9
	str r1, [r4]
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2EA9C
	bl sub_80A6D48
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2EA50
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C2DDA4
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r1, =gBattle_BG1_X
	ldrh r0, [r7, 0x20]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r1]
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r7, 0x22]
	negs r0, r0
	subs r0, 0x20
	strh r0, [r1]
	ldr r1, =gTasks
	ldr r2, [sp, 0x10]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0xA0
	lsls r1, 2
	strh r1, [r0, 0xA]
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0x8]
	mov r2, r10
	strh r2, [r0, 0xC]
	ldr r1, =sub_8170660
	str r1, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170478

	thumb_func_start sub_8170660
sub_8170660: @ 8170660
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r5, r0, r1
	ldrh r1, [r5, 0xA]
	ldrh r0, [r5, 0x22]
	adds r1, r0
	movs r3, 0
	strh r1, [r5, 0x22]
	ldr r2, =gBattle_BG1_Y
	lsls r0, r1, 16
	lsrs r0, 24
	ldrh r4, [r2]
	adds r0, r4
	strh r0, [r2]
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r5, 0x22]
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081706F0
	cmp r0, 0x1
	bgt _081706B4
	cmp r0, 0
	beq _081706BA
	b _08170814
	.pool
_081706B4:
	cmp r0, 0x2
	beq _08170708
	b _08170814
_081706BA:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _081706CA
	b _08170814
_081706CA:
	strh r3, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	adds r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x20
	ldrsh r0, [r5, r2]
	cmp r0, 0x8
	beq _081706EE
	b _08170814
_081706EE:
	b _08170700
_081706F0:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	beq _08170700
	b _08170814
_08170700:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	b _08170814
_08170708:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08170814
	strh r3, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	subs r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x20
	ldrsh r4, [r5, r0]
	cmp r4, 0
	bne _08170814
	movs r0, 0
	bl sub_80A477C
	ldr r0, =gBattle_WIN0H
	strh r4, [r0]
	ldr r0, =gBattle_WIN0V
	strh r4, [r0]
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
	bne _0817076C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl SetAnimBgAttribute
_0817076C:
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
	movs r4, 0x8
	ldrsh r1, [r5, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r6, =gSprites
	adds r0, r6
	bl DestroySprite
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl SetAnimBgAttribute
	ldr r0, =gHealthBoxesIds
	add r0, r8
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x6]
	mov r8, r2
	ldrh r4, [r1, 0x38]
	lsls r4, 24
	lsrs r4, 24
	ldrb r3, [r1, 0x5]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r5, 0x4
	orrs r0, r5
	strb r0, [r1, 0x5]
	mov r0, r8
	lsls r1, r0, 4
	add r1, r8
	lsls r1, 2
	adds r1, r6
	ldrb r3, [r1, 0x5]
	adds r0, r2, 0
	ands r0, r3
	orrs r0, r5
	strb r0, [r1, 0x5]
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x5]
	ands r2, r1
	orrs r2, r5
	strb r2, [r0, 0x5]
	adds r0, r7, 0
	bl DestroyAnimVisualTask
_08170814:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170660

	thumb_func_start sub_8170834
sub_8170834: @ 8170834
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gHealthBoxesIds
	adds r2, r0
	ldrb r0, [r2]
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r0, =gSprites
	adds r5, r0
	ldrb r1, [r5, 0x6]
	mov r10, r1
	ldrh r4, [r5, 0x38]
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000d709
	bl AllocSpritePalette
	mov r2, r9
	strb r0, [r2]
	ldr r0, =0x0000d70a
	bl AllocSpritePalette
	strb r0, [r7]
	ldrb r0, [r5, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r3, r1, 0
	orrs r0, r3
	lsls r6, r4, 4
	adds r6, r4
	lsls r6, 2
	ldr r2, =gSprites
	adds r6, r2
	ldrb r4, [r6, 0x5]
	lsrs r4, 4
	lsls r4, 4
	orrs r4, r3
	lsls r0, 1
	ldr r1, =gPlttBufferUnfaded
	mov r8, r1
	add r0, r8
	mov r2, r9
	ldrb r1, [r2]
	lsls r1, 4
	adds r1, r3, r1
	movs r2, 0x20
	str r3, [sp]
	bl LoadPalette
	lsls r4, 1
	add r4, r8
	ldrb r0, [r7]
	lsls r0, 4
	ldr r3, [sp]
	adds r3, r0
	adds r0, r4, 0
	adds r1, r3, 0
	movs r2, 0x20
	bl LoadPalette
	mov r0, r9
	ldrb r1, [r0]
	lsls r1, 4
	ldrb r2, [r5, 0x5]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	mov r2, r10
	lsls r1, r2, 4
	add r1, r10
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	mov r0, r9
	ldrb r2, [r0]
	lsls r2, 4
	ldrb r4, [r1, 0x5]
	adds r0, r3, 0
	ands r0, r4
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldrb r0, [r7]
	lsls r0, 4
	ldrb r1, [r6, 0x5]
	ands r3, r1
	orrs r3, r0
	strb r3, [r6, 0x5]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170834

	thumb_func_start sub_8170920
sub_8170920: @ 8170920
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, sp
	adds r1, 0x1
	ldr r0, =gAnimBankAttacker
	ldrb r2, [r0]
	mov r0, sp
	bl sub_8170834
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170920

	thumb_func_start sub_817094C
sub_817094C: @ 817094C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gHealthBoxesIds
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gSprites
	mov r8, r1
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	add r5, r8
	ldrb r0, [r5, 0x6]
	mov r9, r0
	ldrh r6, [r5, 0x38]
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =0x0000d709
	bl FreeSpritePaletteByTag
	ldr r0, =0x0000d70a
	bl FreeSpritePaletteByTag
	ldr r0, =0x0000d6ff
	bl IndexOfSpritePaletteTag
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000d704
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsls r4, 4
	ldrb r2, [r5, 0x5]
	movs r3, 0xF
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r4
	strb r1, [r5, 0x5]
	mov r1, r9
	lsls r2, r1, 4
	add r2, r9
	lsls r2, 2
	add r2, r8
	ldrb r5, [r2, 0x5]
	adds r1, r3, 0
	ands r1, r5
	orrs r1, r4
	strb r1, [r2, 0x5]
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	add r1, r8
	lsrs r0, 20
	ldrb r2, [r1, 0x5]
	ands r3, r2
	orrs r3, r0
	strb r3, [r1, 0x5]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817094C

	thumb_func_start sub_81709EC
sub_81709EC: @ 81709EC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	bl sub_817094C
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81709EC

	thumb_func_start sub_8170A0C
sub_8170A0C: @ 8170A0C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =gBattleAnimArgs
	ldrh r0, [r2]
	strh r0, [r1, 0x1C]
	ldrh r0, [r2, 0x2]
	strh r0, [r1, 0x1E]
	ldr r0, =sub_8170A38
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8170A0C

	thumb_func_start sub_8170A38
sub_8170A38: @ 8170A38
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r6, 0
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08170AF8
	strh r6, [r4, 0x8]
	ldr r0, =0x0000d709
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0x1C
	ldrsh r0, [r4, r3]
	movs r1, 0x2
	cmp r0, 0
	bne _08170A76
	movs r1, 0x6
_08170A76:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08170A8C
	cmp r0, 0x1
	beq _08170AC8
	b _08170AF8
	.pool
_08170A8C:
	ldrh r0, [r4, 0xC]
	adds r0, 0x2
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08170A9E
	movs r0, 0x10
	strh r0, [r4, 0xC]
_08170A9E:
	lsls r0, r2, 4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	orrs r0, r1
	ldrb r2, [r4, 0xC]
	ldr r3, =0x00007f74
	movs r1, 0x1
	bl BlendPalette
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0x10
	bne _08170AF8
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _08170AF8
	.pool
_08170AC8:
	ldrh r0, [r4, 0xC]
	subs r0, 0x2
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bge _08170AD6
	strh r6, [r4, 0xC]
_08170AD6:
	lsls r0, r2, 4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	orrs r0, r1
	ldrb r2, [r4, 0xC]
	ldr r3, =0x00007f74
	movs r1, 0x1
	bl BlendPalette
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _08170AF8
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08170AF8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170A38

	thumb_func_start sub_8170B04
sub_8170B04: @ 8170B04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r5, [r0]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08170B52
	cmp r0, 0x1
	bgt _08170B3C
	cmp r0, 0
	beq _08170B42
	b _08170BA4
	.pool
_08170B3C:
	cmp r0, 0x2
	beq _08170B84
	b _08170BA4
_08170B42:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x1C]
	b _08170B76
_08170B52:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x30
	strh r0, [r4, 0x1C]
	movs r0, 0x1C
	ldrsh r2, [r4, r0]
	adds r0, r5, 0
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	adds r0, r5, 0
	bl sub_80A7E6C
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	ldr r0, =0x000002cf
	cmp r1, r0
	ble _08170BA4
_08170B76:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08170BA4
	.pool
_08170B84:
	adds r0, r5, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0
	bl DestroyAnimVisualTask
_08170BA4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170B04

	thumb_func_start sub_8170BB0
sub_8170BB0: @ 8170BB0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gBankSpriteIds
	ldr r4, =gAnimBankAttacker
	ldrb r0, [r4]
	adds r1, r0, r1
	ldrb r1, [r1]
	mov r9, r1
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08170BF8
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	b _08170C08
	.pool
_08170BF8:
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
_08170C08:
	adds r0, r1
	movs r1, 0x26
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl ItemIdToBallId
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r6, r0, r2
	movs r0, 0x8
	ldrsh r7, [r6, r0]
	cmp r7, 0
	beq _08170C44
	cmp r7, 0x1
	beq _08170CC4
	b _08170CEE
	.pool
_08170C44:
	ldr r5, =gAnimBankAttacker
	ldrb r0, [r5]
	movs r1, 0
	bl GetBankCoord
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x1
	bl GetBankCoord
	adds r1, r0, 0
	lsls r1, 24
	ldr r2, =gSprites
	mov r3, r9
	lsls r0, r3, 4
	add r0, r9
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	lsls r2, 28
	lsrs r2, 30
	adds r0, 0x43
	ldrb r3, [r0]
	movs r0, 0x80
	lsls r0, 22
	adds r1, r0
	lsrs r1, 24
	mov r0, r8
	str r0, [sp]
	adds r0, r4, 0
	bl LaunchBallStarsTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x1C]
	str r7, [sp]
	str r7, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r2, r0, 0
	ldrb r1, [r5]
	movs r0, 0
	mov r3, r8
	bl LaunchBallFadeMonTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x1E]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _08170CEE
	.pool
_08170CC4:
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08170CEE
	movs r3, 0x1E
	ldrsh r0, [r6, r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08170CEE
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08170CEE:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8170BB0

	thumb_func_start sub_8170CFC
sub_8170CFC: @ 8170CFC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	bl ItemIdToBallId
	lsls r0, 24
	lsrs r0, 24
	bl LoadBallGfx
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170CFC

	thumb_func_start sub_8170D24
sub_8170D24: @ 8170D24
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	bl ItemIdToBallId
	lsls r0, 24
	lsrs r0, 24
	bl FreeBallGfx
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170D24

	thumb_func_start sub_8170D4C
sub_8170D4C: @ 8170D4C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x5
	bne _08170D70
	ldr r1, =gBattleAnimArgs
	ldr r0, =0x0000ffff
	b _08170D74
	.pool
_08170D70:
	ldr r1, =gBattleAnimArgs
	movs r0, 0
_08170D74:
	strh r0, [r1, 0xE]
	adds r0, r2, 0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170D4C

	thumb_func_start ItemIdToBallId
ItemIdToBallId: @ 8170D84
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r0, 0xB
	bhi _08170DFC
	lsls r0, 2
	ldr r1, =_08170DA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08170DA0:
	.4byte _08170DD0
	.4byte _08170DD4
	.4byte _08170DD8
	.4byte _08170DFC
	.4byte _08170DDC
	.4byte _08170DE0
	.4byte _08170DE4
	.4byte _08170DE8
	.4byte _08170DEC
	.4byte _08170DF0
	.4byte _08170DF4
	.4byte _08170DF8
_08170DD0:
	movs r0, 0x4
	b _08170DFE
_08170DD4:
	movs r0, 0x3
	b _08170DFE
_08170DD8:
	movs r0, 0x1
	b _08170DFE
_08170DDC:
	movs r0, 0x2
	b _08170DFE
_08170DE0:
	movs r0, 0x5
	b _08170DFE
_08170DE4:
	movs r0, 0x6
	b _08170DFE
_08170DE8:
	movs r0, 0x7
	b _08170DFE
_08170DEC:
	movs r0, 0x8
	b _08170DFE
_08170DF0:
	movs r0, 0x9
	b _08170DFE
_08170DF4:
	movs r0, 0xA
	b _08170DFE
_08170DF8:
	movs r0, 0xB
	b _08170DFE
_08170DFC:
	movs r0, 0
_08170DFE:
	pop {r1}
	bx r1
	thumb_func_end ItemIdToBallId

	thumb_func_start sub_8170E04
sub_8170E04: @ 8170E04
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	mov r10, r0
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	bl ItemIdToBallId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	ldr r1, =gBallSpriteTemplates
	adds r0, r1
	movs r1, 0x20
	movs r2, 0x50
	movs r3, 0x1D
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gSprites
	mov r9, r1
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r6, r4, r1
	movs r0, 0x22
	strh r0, [r6, 0x2E]
	ldr r2, =gAnimBankTarget
	mov r8, r2
	ldrb r0, [r2]
	movs r1, 0
	bl GetBankCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x30]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x1
	bl GetBankCoord
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x10
	strh r0, [r6, 0x32]
	mov r0, r9
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_8171104
	str r0, [r4]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r3, [r0, 0x8]
	ldr r1, =gBankSpriteIds
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	lsls r1, 1
	ldrb r2, [r3, 0x9]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x9]
	ldr r1, =gTasks
	mov r2, r10
	lsls r0, r2, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	ldr r1, =sub_8170EF0
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170E04

	thumb_func_start sub_8170EF0
sub_8170EF0: @ 8170EF0
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x8]
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x2E]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08170F1A
	adds r0, r3, 0
	bl DestroyAnimVisualTask
_08170F1A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170EF0

	thumb_func_start sub_8170F2C
sub_8170F2C: @ 8170F2C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _08170F50
	movs r6, 0x20
	movs r5, 0xB
	b _08170F54
	.pool
_08170F50:
	movs r6, 0x17
	movs r5, 0x5
_08170F54:
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	bl ItemIdToBallId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A82E4
	adds r3, r0, 0
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r1, =gBallSpriteTemplates
	adds r0, r1
	adds r1, r6, 0
	adds r1, 0x20
	movs r2, 0x50
	orrs r5, r2
	adds r2, r5, 0
	bl CreateSprite
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gSprites
	mov r9, r0
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r6, r4, r0
	movs r0, 0x22
	strh r0, [r6, 0x2E]
	ldr r1, =gAnimBankTarget
	mov r8, r1
	ldrb r0, [r1]
	movs r1, 0
	bl GetBankCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x30]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x1
	bl GetBankCoord
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x10
	strh r0, [r6, 0x32]
	movs r0, 0x1C
	add r9, r0
	add r4, r9
	ldr r0, =SpriteCallbackDummy
	str r0, [r4]
	movs r0, 0
	bl GetBankByIdentity
	ldr r1, =gBankSpriteIds
	lsls r0, 24
	lsrs r0, 24
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	ldr r1, =sub_8039E84
	str r1, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	ldr r1, =sub_8171030
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170F2C

	thumb_func_start sub_8171030
sub_8171030: @ 8171030
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gSprites
	movs r0, 0
	bl GetBankByIdentity
	ldr r1, =gBankSpriteIds
	lsls r0, 24
	lsrs r0, 24
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0817108A
	movs r0, 0x3D
	movs r1, 0
	bl PlaySE12WithPanning
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8171104
	str r1, [r0]
	ldr r0, =sub_81710A8
	movs r1, 0xA
	bl CreateTask
	ldr r0, =sub_8170EF0
	str r0, [r4]
_0817108A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171030

	thumb_func_start sub_81710A8
sub_81710A8: @ 81710A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gSprites
	movs r0, 0
	bl GetBankByIdentity
	ldr r4, =gBankSpriteIds
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _081710F4
	movs r0, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0
	bl StartSpriteAnim
	adds r0, r5, 0
	bl DestroyTask
_081710F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81710A8

	thumb_func_start sub_8171104
sub_8171104: @ 8171104
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x32]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	strh r2, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_8171134
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171104

	thumb_func_start sub_8171134
sub_8171134: @ 8171134
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl AnimateBallThrow
	lsls r0, 24
	cmp r0, 0
	beq _081711D2
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x5
	bne _08171160
	ldr r0, =sub_8171CAC
	str r0, [r4, 0x1C]
	b _081711D2
	.pool
_08171160:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x26]
	adds r1, r4, 0
	adds r1, 0x2E
	movs r2, 0
	adds r0, r4, 0
	adds r0, 0x3C
_08171188:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _08171188
	movs r0, 0
	strh r0, [r4, 0x38]
	ldr r0, =sub_81711E8
	str r0, [r4, 0x1C]
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	bl ItemIdToBallId
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xB
	bgt _081711D2
	cmp r5, 0
	blt _081711D2
	ldrh r0, [r4, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	str r5, [sp]
	movs r2, 0x1
	movs r3, 0x1C
	bl LaunchBallStarsTask
	ldr r0, =gAnimBankTarget
	ldrb r1, [r0]
	movs r0, 0
	movs r2, 0xE
	adds r3, r5, 0
	bl LaunchBallFadeMonTask
_081711D2:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171134

	thumb_func_start sub_81711E8
sub_81711E8: @ 81711E8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08171224
	ldr r0, =TaskDummy
	movs r1, 0x32
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x38]
	ldr r0, =sub_8171240
	str r0, [r4, 0x1C]
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x30]
_08171224:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81711E8

	thumb_func_start sub_8171240
sub_8171240: @ 8171240
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimBankTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r4, [r0]
	ldrh r0, [r7, 0x38]
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _08171272
	movs r0, 0x3C
	bl PlaySE
_08171272:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081712E8
	cmp r0, 0x1
	bgt _08171290
	cmp r0, 0
	beq _08171296
	b _08171354
	.pool
_08171290:
	cmp r0, 0x2
	beq _0817132C
	b _08171354
_08171296:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0x1C]
	ldr r1, =gUnknown_030062DC
	movs r0, 0x1C
	str r0, [r1]
	ldr r2, =gUnknown_030062E4
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x26]
	ldrh r0, [r0, 0x22]
	adds r1, r0
	ldrh r0, [r7, 0x26]
	ldrh r7, [r7, 0x22]
	adds r0, r7
	subs r1, r0
	strh r1, [r2]
	ldr r4, =gUnknown_030062E0
	ldrh r0, [r2]
	lsls r0, 8
	movs r1, 0x1C
	bl __udivsi3
	strh r0, [r4]
	strh r0, [r5, 0xC]
	b _08171346
	.pool
_081712E8:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x20
	strh r0, [r5, 0x1C]
	movs r0, 0x1C
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0xC]
	ldrh r1, [r5, 0xE]
	adds r0, r1
	strh r0, [r5, 0xE]
	ldr r0, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	negs r0, r0
	asrs r0, 8
	strh r0, [r1, 0x26]
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	ldr r0, =0x0000047f
	cmp r1, r0
	ble _0817137C
	b _08171346
	.pool
_0817132C:
	adds r0, r4, 0
	bl sub_80A7344
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08171346:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0817137C
	.pool
_08171354:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0xA
	ble _0817137C
	adds r0, r6, 0
	bl DestroyTask
	adds r0, r7, 0
	movs r1, 0x2
	bl StartSpriteAnim
	movs r0, 0
	strh r0, [r7, 0x38]
	ldr r0, =sub_817138C
	str r0, [r7, 0x1C]
_0817137C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171240

	thumb_func_start sub_817138C
sub_817138C: @ 817138C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081713C6
	movs r1, 0
	strh r1, [r4, 0x34]
	movs r0, 0x28
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	movs r0, 0
	movs r1, 0x28
	bl Cos
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldr r0, =sub_81713D0
	str r0, [r4, 0x1C]
_081713C6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817138C

	thumb_func_start sub_81713D0
sub_81713D0: @ 81713D0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0
	beq _081713E6
	cmp r1, 0x1
	beq _0817145A
	b _08171486
_081713E6:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	adds r1, 0x4
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 24
	adds r1, r0
	strh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3F
	ble _08171486
	ldrh r0, [r4, 0x36]
	subs r0, 0xA
	strh r0, [r4, 0x36]
	ldr r1, =0x00000101
	adds r0, r2, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	cmp r0, 0x4
	bne _08171422
	movs r5, 0x1
_08171422:
	cmp r0, 0x2
	beq _08171442
	cmp r0, 0x2
	bgt _08171434
	cmp r0, 0x1
	beq _0817143A
	b _08171452
	.pool
_08171434:
	cmp r0, 0x3
	beq _0817144A
	b _08171452
_0817143A:
	movs r0, 0x38
	bl PlaySE
	b _08171486
_08171442:
	movs r0, 0x39
	bl PlaySE
	b _08171486
_0817144A:
	movs r0, 0x3A
	bl PlaySE
	b _08171486
_08171452:
	movs r0, 0x3B
	bl PlaySE
	b _08171486
_0817145A:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl Cos
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	subs r1, 0x4
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 24
	subs r1, r0
	strh r1, [r4, 0x38]
	lsls r1, 16
	cmp r1, 0
	bgt _08171486
	strh r5, [r4, 0x38]
	ldr r0, =0xffffff00
	ands r0, r2
	strh r0, [r4, 0x34]
_08171486:
	cmp r5, 0
	beq _081714CA
	movs r5, 0
	strh r5, [r4, 0x34]
	movs r0, 0x40
	movs r1, 0x28
	bl Cos
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x26]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _081714C0
	strh r5, [r4, 0x38]
	ldr r0, =sub_81717B4
	str r0, [r4, 0x1C]
	b _081714CA
	.pool
_081714C0:
	ldr r0, =sub_81714D4
	str r0, [r4, 0x1C]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r5, [r4, 0x38]
_081714CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81713D0

	thumb_func_start sub_81714D4
sub_81714D4: @ 81714D4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08171510
	strh r5, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strh r5, [r0, 0xC]
	ldr r0, =sub_8171520
	str r0, [r4, 0x1C]
	movs r0, 0x17
	bl PlaySE
_08171510:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81714D4

	thumb_func_start sub_8171520
sub_8171520: @ 8171520
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0x6
	bls _08171530
	b _08171768
_08171530:
	lsls r0, r1, 2
	ldr r1, =_08171540
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08171540:
	.4byte _0817155C
	.4byte _081715AE
	.4byte _081715F4
	.4byte _08171654
	.4byte _081716A4
	.4byte _08171708
	.4byte _08171768
_0817155C:
	ldr r1, =gBattleSpritesDataPtr
	ldr r5, [r1]
	ldr r2, [r5, 0x8]
	ldrh r3, [r2, 0xC]
	movs r6, 0xC
	ldrsh r0, [r2, r6]
	adds r6, r1, 0
	cmp r0, 0xFF
	ble _08171584
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldr r1, [r5, 0x8]
	ldrb r0, [r1, 0xC]
	strh r0, [r1, 0xC]
	b _0817158A
	.pool
_08171584:
	adds r0, r3, 0
	adds r0, 0xB0
	strh r0, [r2, 0xC]
_0817158A:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xE
	bhi _081715AC
	b _081717AE
_081715AC:
	b _08171644
_081715AE:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08171660
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bge _081715EA
	adds r0, r4, 0
	movs r1, 0x2
	bl ChangeSpriteAffineAnim
	b _081717AE
_081715EA:
	adds r0, r4, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
	b _081717AE
_081715F4:
	ldr r1, =gBattleSpritesDataPtr
	ldr r5, [r1]
	ldr r2, [r5, 0x8]
	ldrh r3, [r2, 0xC]
	movs r6, 0xC
	ldrsh r0, [r2, r6]
	adds r6, r1, 0
	cmp r0, 0xFF
	ble _0817161C
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldr r1, [r5, 0x8]
	ldrb r0, [r1, 0xC]
	strh r0, [r1, 0xC]
	b _08171622
	.pool
_0817161C:
	adds r0, r3, 0
	adds r0, 0xB0
	strh r0, [r2, 0xC]
_08171622:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0xC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x18
	bhi _08171644
	b _081717AE
_08171644:
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	strh r3, [r0, 0xC]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	strh r3, [r4, 0x38]
	b _081717AE
_08171654:
	ldrh r0, [r4, 0x38]
	adds r1, r0, 0x1
	strh r1, [r4, 0x38]
	lsls r0, 16
	cmp r0, 0
	bge _0817166E
_08171660:
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	b _081717AE
_0817166E:
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bge _0817169C
	adds r0, r4, 0
	movs r1, 0x2
	bl ChangeSpriteAffineAnim
	b _081716A4
_0817169C:
	adds r0, r4, 0
	movs r1, 0x1
	bl ChangeSpriteAffineAnim
_081716A4:
	ldr r1, =gBattleSpritesDataPtr
	ldr r5, [r1]
	ldr r2, [r5, 0x8]
	ldrh r3, [r2, 0xC]
	movs r6, 0xC
	ldrsh r0, [r2, r6]
	adds r6, r1, 0
	cmp r0, 0xFF
	ble _081716CC
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldr r1, [r5, 0x8]
	ldrb r0, [r1, 0xC]
	strh r0, [r1, 0xC]
	b _081716D2
	.pool
_081716CC:
	adds r0, r3, 0
	adds r0, 0xB0
	strh r0, [r2, 0xC]
_081716D2:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	bls _081717AE
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	strh r3, [r0, 0xC]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	strh r3, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	b _081717AE
_08171708:
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6, 0
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r1, r0, 24
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r1, r0
	bne _08171740
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_81717B4
	str r0, [r4, 0x1C]
	b _081717AE
	.pool
_08171740:
	cmp r0, 0x4
	bne _08171754
	cmp r1, 0x3
	bne _08171754
	ldr r0, =sub_81717D8
	str r0, [r4, 0x1C]
	b _0817175A
	.pool
_08171754:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
_0817175A:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	b _081717AE
_08171768:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _081717AE
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r1, [r4, 0x34]
	ldr r0, =0xffffff00
	ands r0, r1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAffineAnim
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bge _081717A0
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAffineAnim
	b _081717A8
	.pool
_081717A0:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
_081717A8:
	movs r0, 0x17
	bl PlaySE
_081717AE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8171520

	thumb_func_start sub_81717B4
sub_81717B4: @ 81717B4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x38]
	adds r0, 0x1
	strh r0, [r1, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _081717CE
	movs r0, 0
	strh r0, [r1, 0x38]
	ldr r0, =sub_8171AE4
	str r0, [r1, 0x1C]
_081717CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81717B4

	thumb_func_start sub_81717D8
sub_81717D8: @ 81717D8
	adds r3, r0, 0
	adds r3, 0x2C
	ldrb r1, [r3]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r3]
	ldr r1, =sub_81717F8
	str r1, [r0, 0x1C]
	movs r1, 0
	strh r1, [r0, 0x34]
	strh r1, [r0, 0x36]
	strh r1, [r0, 0x38]
	bx lr
	.pool
	thumb_func_end sub_81717D8

	thumb_func_start sub_81717F8
sub_81717F8: @ 81717F8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r7, =gAnimBankTarget
	ldrh r0, [r6, 0x36]
	adds r0, 0x1
	movs r1, 0
	mov r8, r1
	strh r0, [r6, 0x36]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0x28
	bne _0817183C
	movs r0, 0xFE
	bl PlaySE
	ldrb r1, [r6, 0x5]
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r1
	movs r1, 0x6
	movs r2, 0
	bl BlendPalettes
	adds r0, r6, 0
	bl sub_81719EC
	b _081718BC
	.pool
_0817183C:
	cmp r1, 0x3C
	bne _0817185A
	ldrb r1, [r6, 0x5]
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r1
	mov r1, r8
	str r1, [sp]
	movs r1, 0x2
	movs r2, 0x6
	movs r3, 0
	bl BeginNormalPaletteFade
	b _081718BC
_0817185A:
	cmp r1, 0x5F
	bne _08171880
	ldr r0, =gDoingBattleAnim
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	bl UpdateOamPriorityInAllHealthboxes
	bl m4aMPlayAllStop
	ldr r0, =0x00000213
	bl PlaySE
	b _081718BC
	.pool
_08171880:
	ldr r0, =0x0000013b
	cmp r1, r0
	bne _081718BC
	ldr r5, =gSprites
	ldr r4, =gBankSpriteIds
	ldrb r0, [r7]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r0, [r7]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
	mov r0, r8
	strh r0, [r6, 0x2E]
	ldr r0, =sub_81718D8
	str r0, [r6, 0x1C]
_081718BC:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81717F8

	thumb_func_start sub_81718D8
sub_81718D8: @ 81718D8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08171944
	cmp r0, 0x1
	bgt _081718F0
	cmp r0, 0
	beq _081718F6
	b _0817198A
_081718F0:
	cmp r0, 0x2
	beq _08171976
	b _0817198A
_081718F6:
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrb r1, [r4, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, [r4, 0x14]
	ldrh r0, [r0, 0x2]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r1, 0x1
	lsls r1, r0
	ldr r0, =0x00007fff
	str r0, [sp]
	adds r0, r1, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08171982
	.pool
_08171944:
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	ble _081719B0
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r2, [r4, 0x32]
	adds r2, 0x1
	strh r2, [r4, 0x32]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _081719B0
	b _08171982
_08171976:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08171982:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081719B0
_0817198A:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081719B0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	strh r5, [r4, 0x2E]
	ldr r0, =sub_81719C0
	str r0, [r4, 0x1C]
_081719B0:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81718D8

	thumb_func_start sub_81719C0
sub_81719C0: @ 81719C0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081719D8
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x2E]
	b _081719E4
	.pool
_081719D8:
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_081719E4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81719C0

	thumb_func_start sub_81719EC
sub_81719EC: @ 81719EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	adds r1, r6, 0
	adds r1, 0x43
	ldrb r0, [r1]
	cmp r0, 0
	beq _08171A0C
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	b _08171A14
_08171A0C:
	movs r0, 0
	mov r8, r0
	movs r0, 0x1
	strb r0, [r1]
_08171A14:
	movs r0, 0x4
	bl sub_8171D60
	movs r7, 0
	ldr r2, =gSprites
	mov r9, r2
	movs r0, 0x1C
	add r0, r9
	mov r10, r0
_08171A26:
	movs r2, 0x20
	ldrsh r1, [r6, r2]
	movs r0, 0x22
	ldrsh r2, [r6, r0]
	ldr r0, =gUnknown_085E5250
	mov r3, r8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08171A82
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	mov r2, r9
	adds r5, r4, r2
	movs r0, 0x18
	strh r0, [r5, 0x2E]
	ldr r0, =gUnknown_085E5088
	lsls r1, r7, 2
	adds r1, r0
	movs r0, 0
	ldrsb r0, [r1, r0]
	ldrh r2, [r6, 0x20]
	adds r0, r2
	strh r0, [r5, 0x32]
	movs r0, 0x1
	ldrsb r0, [r1, r0]
	ldrh r2, [r6, 0x22]
	adds r0, r2
	strh r0, [r5, 0x36]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	add r4, r10
	ldr r0, =sub_8171AAC
	str r0, [r4]
	ldr r0, =gUnknown_085E51B4
	ldrb r1, [r0, 0x4]
	adds r0, r5, 0
	bl StartSpriteAnim
_08171A82:
	adds r7, 0x1
	cmp r7, 0x2
	bls _08171A26
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81719EC

	thumb_func_start sub_8171AAC
sub_8171AAC: @ 8171AAC
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, 0
	bl AnimateBallThrow
	lsls r0, 24
	cmp r0, 0
	beq _08171ADC
	adds r0, r4, 0
	bl DestroySprite
_08171ADC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8171AAC

	thumb_func_start sub_8171AE4
sub_8171AE4: @ 8171AE4
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	ldr r0, =sub_8171BAC
	str r0, [r4, 0x1C]
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	bl ItemIdToBallId
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xB
	bgt _08171B36
	cmp r5, 0
	blt _08171B36
	ldrh r0, [r4, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	str r5, [sp]
	movs r2, 0x1
	movs r3, 0x1C
	bl LaunchBallStarsTask
	ldr r0, =gAnimBankTarget
	ldrb r1, [r0]
	movs r0, 0x1
	movs r2, 0xE
	adds r3, r5, 0
	bl LaunchBallFadeMonTask
_08171B36:
	ldr r6, =gSprites
	ldr r5, =gBankSpriteIds
	ldr r4, =gAnimBankTarget
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl AnimateSprite
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x80
	lsls r1, 5
	strh r1, [r0, 0x30]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171AE4

	thumb_func_start sub_8171BAC
sub_8171BAC: @ 8171BAC
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08171BCA
	adds r2, r7, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08171BCA:
	ldr r4, =gSprites
	ldr r3, =gBankSpriteIds
	ldr r2, =gAnimBankTarget
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _08171C04
	adds r0, r1, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	movs r5, 0x1
	b _08171C24
	.pool
_08171C04:
	ldr r6, =0xfffffee0
	adds r0, r6, 0
	ldrh r6, [r1, 0x30]
	adds r0, r6
	strh r0, [r1, 0x30]
	ldrb r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r1, 0x26]
_08171C24:
	adds r0, r7, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08171C8A
	cmp r5, 0
	beq _08171C8A
	ldr r4, =gSprites
	ldr r3, =gBankSpriteIds
	ldr r2, =gAnimBankTarget
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r6, 0
	movs r5, 0
	strh r5, [r0, 0x26]
	ldrb r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	lsls r1, 30
	adds r2, 0x3E
	lsrs r1, 31
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	strh r5, [r7, 0x2E]
	ldr r0, =sub_81719C0
	str r0, [r7, 0x1C]
	ldr r0, =gDoingBattleAnim
	strb r6, [r0]
	movs r0, 0x1
	bl UpdateOamPriorityInAllHealthboxes
_08171C8A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171BAC

	thumb_func_start sub_8171CAC
sub_8171CAC: @ 8171CAC
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x24]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x26]
	ldrh r3, [r2, 0x22]
	adds r0, r3
	strh r0, [r2, 0x22]
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	ldr r4, =sub_8171CE8
	movs r3, 0
	movs r1, 0x5
	adds r0, r2, 0
	adds r0, 0x38
_08171CD0:
	strh r3, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08171CD0
	str r4, [r2, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171CAC

	thumb_func_start sub_8171CE8
sub_8171CE8: @ 8171CE8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 4
	adds r2, r0, 0
	ldrh r1, [r4, 0x2E]
	adds r2, r1
	movs r0, 0xD0
	lsls r0, 3
	adds r3, r0, 0
	ldrh r1, [r4, 0x30]
	adds r3, r1
	lsls r1, r3, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
	strh r0, [r4, 0x24]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r4, 0x2E]
	ands r3, r0
	strh r3, [r4, 0x30]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	cmp r0, 0xA0
	bgt _08171D3E
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x8
	negs r1, r1
	cmp r0, r1
	bge _08171D52
_08171D3E:
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_81719C0
	str r0, [r4, 0x1C]
	ldr r1, =gDoingBattleAnim
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	bl UpdateOamPriorityInAllHealthboxes
_08171D52:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171CE8

	thumb_func_start sub_8171D60
sub_8171D60: @ 8171D60
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, =gUnknown_085E5094
	lsrs r5, r0, 21
	adds r4, r5, r1
	ldrh r0, [r4, 0x6]
	bl GetSpriteTileStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _08171D86
	adds r0, r4, 0
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_085E50F4
	adds r0, r5, r0
	bl LoadCompressedObjectPaletteUsingHeap
_08171D86:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171D60

	thumb_func_start LaunchBallStarsTask
LaunchBallStarsTask: @ 8171D98
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	mov r8, r1
	mov r9, r2
	mov r10, r3
	ldr r5, [sp, 0x1C]
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl sub_8171D60
	ldr r1, =gUnknown_085E51C0
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x5
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0xA]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	mov r1, r10
	strh r1, [r0, 0x10]
	strh r5, [r0, 0x26]
	movs r0, 0xF
	bl PlaySE
	adds r0, r4, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end LaunchBallStarsTask

	thumb_func_start sub_8171E20
sub_8171E20: @ 8171E20
	push {lr}
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08171E3E
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	ldrb r0, [r1, 0xA]
	adds r0, 0x1
	strb r0, [r1, 0xA]
_08171E3E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171E20

	thumb_func_start sub_8171E50
sub_8171E50: @ 8171E50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0x26]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r2, 0x8
	ldrsh r0, [r6, r2]
	adds r2, r1, 0
	cmp r0, 0xF
	bgt _08171F48
	ldrb r1, [r6, 0xA]
	ldrb r2, [r6, 0xC]
	ldrb r4, [r6, 0xE]
	mov r9, r4
	ldrb r3, [r6, 0x10]
	ldr r4, [sp]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r4, =gUnknown_085E51F0
	adds r0, r4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0x40
	beq _08171EEC
	bl sub_8171E20
	mov r0, r10
	lsls r4, r0, 4
	add r4, r10
	lsls r4, 2
	ldr r5, =gSprites
	adds r7, r4, r5
	ldr r0, =gUnknown_085E51B4
	ldr r1, [sp]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r7, 0
	bl StartSpriteAnim
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_8171F68
	str r0, [r4]
	movs r0, 0x3
	mov r2, r9
	ands r2, r0
	lsls r2, 2
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r7, 0x5]
	ldrb r0, [r6, 0x8]
	cmp r0, 0x7
	bls _08171EE8
	subs r0, 0x8
	lsls r0, 24
	lsrs r0, 24
_08171EE8:
	lsls r0, 5
	strh r0, [r7, 0x2E]
_08171EEC:
	ldr r0, =gTasks
	mov r4, r8
	lsls r1, r4, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	adds r2, r0, 0
	cmp r1, 0xF
	bne _08171F48
	ldr r0, =gMain
	ldr r4, =0x00000439
	adds r0, r4
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08171F22
	ldr r0, =gSprites
	mov r2, r10
	lsls r1, r2, 4
	add r1, r10
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08171F22:
	mov r0, r8
	bl DestroyTask
	b _08171F58
	.pool
_08171F48:
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
_08171F58:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8171E50

	thumb_func_start sub_8171F68
sub_8171F68: @ 8171F68
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x30]
	movs r3, 0x30
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08171F80
	ldr r0, =sub_8171F88
	str r0, [r1, 0x1C]
	b _08171F84
	.pool
_08171F80:
	subs r0, r2, 0x1
	strh r0, [r1, 0x30]
_08171F84:
	pop {r0}
	bx r0
	thumb_func_end sub_8171F68

	thumb_func_start sub_8171F88
sub_8171F88: @ 8171F88
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x32
	bne _08171FBC
	adds r0, r4, 0
	bl sub_8172944
_08171FBC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8171F88

	thumb_func_start sub_8171FC4
sub_8171FC4: @ 8171FC4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x4]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0x8]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0xC]
	movs r7, 0
	ldr r3, =gSprites
	mov r10, r3
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 3
	str r0, [sp, 0x10]
_0817200A:
	ldr r0, =gUnknown_085E51F0
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817206A
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r3, r10
	adds r5, r4, r3
	ldr r0, =gUnknown_085E51B4
	add r0, r8
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0xA
	strh r0, [r5, 0x36]
	movs r0, 0x2
	strh r0, [r5, 0x38]
	movs r0, 0x1
	strh r0, [r5, 0x3A]
_0817206A:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _0817200A
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172092
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172092:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171FC4

	thumb_func_start sub_81720C8
sub_81720C8: @ 81720C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x4]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0x8]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0xC]
	movs r7, 0
	ldr r3, =gSprites
	mov r10, r3
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 3
	str r0, [sp, 0x10]
_0817210E:
	ldr r0, =gUnknown_085E51F0
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817216E
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r3, r10
	adds r5, r4, r3
	ldr r0, =gUnknown_085E51B4
	add r0, r8
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0xA
	strh r0, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	movs r0, 0x2
	strh r0, [r5, 0x3A]
_0817216E:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _0817210E
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172196
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172196:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81720C8

	thumb_func_start sub_81721CC
sub_81721CC: @ 81721CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r0, 0xA]
	str r2, [sp]
	ldrb r3, [r0, 0xC]
	str r3, [sp, 0x4]
	ldrb r2, [r0, 0xE]
	str r2, [sp, 0x8]
	ldrb r0, [r0, 0x10]
	str r0, [sp, 0xC]
	movs r7, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	str r0, [sp, 0x10]
	ldr r3, =gSprites
	mov r8, r3
	ldr r0, =gUnknown_085E51B4
	adds r1, r0
	mov r10, r1
_08172212:
	ldr r0, =gUnknown_085E51F0
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817226E
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r2, r8
	adds r5, r4, r2
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0x4
	strh r0, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	strh r0, [r5, 0x3A]
_0817226E:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _08172212
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172296
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172296:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81721CC

	thumb_func_start sub_81722CC
sub_81722CC: @ 81722CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x4]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0x8]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0xC]
	movs r7, 0
	ldr r3, =gSprites
	mov r10, r3
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 3
	str r0, [sp, 0x10]
_08172312:
	ldr r0, =gUnknown_085E51F0
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08172376
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r3, r10
	adds r5, r4, r3
	ldr r0, =gUnknown_085E51B4
	add r0, r8
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 3
	adds r0, r7
	strh r0, [r5, 0x2E]
	movs r0, 0x5
	strh r0, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	strh r0, [r5, 0x3A]
_08172376:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x9
	bls _08172312
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0817239E
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_0817239E:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81722CC

	thumb_func_start sub_81723D4
sub_81723D4: @ 81723D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r0, r2, r0
	lsls r0, 3
	adds r3, r0, r1
	ldrh r1, [r3, 0x16]
	movs r4, 0x16
	ldrsh r0, [r3, r4]
	cmp r0, 0
	beq _08172404
	subs r0, r1, 0x1
	strh r0, [r3, 0x16]
	b _081724D6
	.pool
_08172404:
	ldrh r0, [r3, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r3, 0xA]
	str r1, [sp]
	ldrb r4, [r3, 0xC]
	str r4, [sp, 0x4]
	ldrb r1, [r3, 0xE]
	str r1, [sp, 0x8]
	ldrb r3, [r3, 0x10]
	str r3, [sp, 0xC]
	movs r7, 0
	str r2, [sp, 0x14]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	str r1, [sp, 0x10]
	ldr r3, =gSprites
	mov r9, r3
	ldr r1, =gUnknown_085E51B4
	adds r0, r1
	mov r10, r0
_08172430:
	ldr r0, =gUnknown_085E51F0
	ldr r4, [sp, 0x10]
	adds r0, r4, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817248C
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r0, r9
	adds r5, r4, r0
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0x8
	strh r0, [r5, 0x36]
	movs r0, 0x2
	strh r0, [r5, 0x38]
	strh r0, [r5, 0x3A]
_0817248C:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _08172430
	ldr r0, =gTasks
	ldr r1, [sp, 0x14]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x8
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0x2
	bne _081724D6
	ldr r0, =gMain
	ldr r4, =0x00000439
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _081724D0
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_081724D0:
	mov r0, r8
	bl DestroyTask
_081724D6:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81723D4

	thumb_func_start sub_8172508
sub_8172508: @ 8172508
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x2E]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	ldrh r2, [r4, 0x30]
	adds r0, r2
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _08172558
	adds r0, r4, 0
	bl sub_8172944
_08172558:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8172508

	thumb_func_start sub_8172560
sub_8172560: @ 8172560
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r0, 0xA]
	str r2, [sp]
	ldrb r3, [r0, 0xC]
	str r3, [sp, 0x4]
	ldrb r2, [r0, 0xE]
	str r2, [sp, 0x8]
	ldrb r0, [r0, 0x10]
	str r0, [sp, 0xC]
	movs r7, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	str r0, [sp, 0x10]
	ldr r3, =gSprites
	mov r8, r3
	ldr r0, =gUnknown_085E51B4
	adds r1, r0
	mov r10, r1
_081725A6:
	ldr r0, =gUnknown_085E51F0
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _081725FE
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r2, r8
	adds r5, r4, r2
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_817265C
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 2
	adds r0, r7
	strh r0, [r5, 0x2E]
_081725FE:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xB
	bls _081725A6
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172626
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172626:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172560

	thumb_func_start sub_817265C
sub_817265C: @ 817265C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	bl Sin
	strh r0, [r5, 0x24]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	adds r0, r4, 0
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl Cos
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x6
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _081726B4
	adds r0, r5, 0
	bl sub_8172944
_081726B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817265C

	thumb_func_start sub_81726BC
sub_81726BC: @ 81726BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	ldr r0, =gTasks
	ldr r2, [sp]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp, 0x4]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x8]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0xC]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0x10]
	movs r3, 0
	mov r8, r3
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 3
	str r0, [sp, 0x14]
_08172700:
	movs r7, 0
	movs r2, 0x1
	add r2, r8
	mov r10, r2
_08172708:
	ldr r0, =gUnknown_085E51F0
	ldr r3, [sp, 0x14]
	adds r0, r3, r0
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08172790
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	ldr r0, =gSprites
	adds r5, r4, r0
	ldr r0, =gUnknown_085E51B4
	add r0, r9
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r1, =gSprites + 0x1C
	adds r4, r1
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r1, [sp, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r2, r3, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0x8
	strh r0, [r5, 0x36]
	mov r0, r8
	cmp r0, 0
	bne _08172788
	movs r0, 0x2
	strh r0, [r5, 0x38]
	movs r0, 0x1
	b _0817278E
	.pool
_08172788:
	movs r0, 0x1
	strh r0, [r5, 0x38]
	movs r0, 0x2
_0817278E:
	strh r0, [r5, 0x3A]
_08172790:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _08172708
	mov r1, r10
	lsls r0, r1, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x1
	bls _08172700
	ldr r0, =gMain
	ldr r2, =0x00000439
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081727C4
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_081727C4:
	ldr r0, [sp]
	bl DestroyTask
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81726BC

	thumb_func_start sub_81727E8
sub_81727E8: @ 81727E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r0, 0xA]
	str r2, [sp]
	ldrb r3, [r0, 0xC]
	str r3, [sp, 0x4]
	ldrb r2, [r0, 0xE]
	str r2, [sp, 0x8]
	ldrb r0, [r0, 0x10]
	str r0, [sp, 0xC]
	movs r7, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	str r0, [sp, 0x10]
	ldr r3, =gSprites
	mov r8, r3
	ldr r0, =gUnknown_085E51B4
	adds r1, r0
	mov r10, r1
_0817282E:
	ldr r0, =gUnknown_085E51F0
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08172880
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r2, r8
	adds r5, r4, r2
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartSpriteAnim
	ldr r0, =gSprites + 0x1C
	adds r4, r0
	ldr r0, =sub_81728E0
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
_08172880:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _0817282E
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081728A8
	ldr r0, =gSprites
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_081728A8:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81727E8

	thumb_func_start sub_81728E0
sub_81728E0: @ 81728E0
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	bl Sin
	strh r0, [r5, 0x24]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	ldrh r1, [r5, 0x2E]
	movs r0, 0x3F
	ands r0, r1
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	bl Sin
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl Cos
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x2E]
	adds r0, 0xA
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _0817293C
	adds r0, r5, 0
	bl sub_8172944
_0817293C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81728E0

	thumb_func_start sub_8172944
sub_8172944: @ 8172944
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172970
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	bne _081729CA
	adds r0, r7, 0
	bl DestroySpriteAndFreeResources
	b _081729E2
	.pool
_08172970:
	ldr r2, =gBattleSpritesDataPtr
	ldr r0, [r2]
	ldr r1, [r0, 0x8]
	ldrb r0, [r1, 0xA]
	subs r0, 0x1
	strb r0, [r1, 0xA]
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	bne _081729DC
	movs r4, 0
	ldr r5, =gUnknown_085E51C0
	b _08172998
	.pool
_08172994:
	adds r5, 0x4
	adds r4, 0x1
_08172998:
	cmp r4, 0xB
	bgt _081729AA
	ldr r0, [r5]
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08172994
_081729AA:
	cmp r4, 0xC
	bne _081729CA
	movs r6, 0
	ldr r5, =gUnknown_085E5094
	ldr r4, =gUnknown_085E50F4
_081729B4:
	ldrh r0, [r5, 0x6]
	bl FreeSpriteTilesByTag
	ldrh r0, [r4, 0x4]
	bl FreeSpritePaletteByTag
	adds r5, 0x8
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0xB
	ble _081729B4
_081729CA:
	adds r0, r7, 0
	bl DestroySprite
	b _081729E2
	.pool
_081729DC:
	adds r0, r7, 0
	bl DestroySprite
_081729E2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8172944

	thumb_func_start LaunchBallFadeMonTask
LaunchBallFadeMonTask: @ 81729E8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	mov r9, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r3, 24
	lsrs r7, r3, 24
	ldr r0, =sub_8172AB0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	strh r7, [r5, 0x26]
	strh r6, [r5, 0xE]
	mov r0, r9
	strh r0, [r5, 0x1C]
	mov r1, r9
	lsrs r0, r1, 16
	strh r0, [r5, 0x1E]
	cmp r4, 0
	bne _08172A58
	lsls r0, r6, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 16
	ldr r2, =gUnknown_085E5310
	lsls r1, r7, 1
	adds r1, r2
	ldrh r3, [r1]
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	movs r0, 0x1
	strh r0, [r5, 0xA]
	b _08172A7E
	.pool
_08172A58:
	lsls r0, r6, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	ldr r2, =gUnknown_085E5310
	lsls r1, r7, 1
	adds r1, r2
	ldrh r3, [r1]
	movs r1, 0x10
	movs r2, 0x10
	bl BlendPalette
	movs r0, 0x10
	strh r0, [r5, 0x8]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0xA]
	ldr r0, =sub_8172B40
	str r0, [r5]
_08172A7E:
	ldr r0, =0x00007fff
	str r0, [sp]
	mov r0, r9
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	mov r0, r8
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end LaunchBallFadeMonTask

	thumb_func_start sub_8172AB0
sub_8172AB0: @ 8172AB0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bgt _08172B08
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 16
	ldrb r2, [r4, 0x8]
	ldr r3, =gUnknown_085E5310
	lsls r1, 1
	adds r1, r3
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	b _08172B30
	.pool
_08172B08:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08172B30
	ldrh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	lsls r1, 16
	orrs r0, r1
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	adds r0, r5, 0
	bl DestroyTask
_08172B30:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172AB0

	thumb_func_start sub_8172B40
sub_8172B40: @ 8172B40
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08172B78
	ldr r0, =gTasks
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	lsls r1, 16
	orrs r0, r1
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_8172B90
	str r0, [r4]
_08172B78:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172B40

	thumb_func_start sub_8172B90
sub_8172B90: @ 8172B90
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0x10
	bgt _08172BE4
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 20
	movs r3, 0x80
	lsls r3, 17
	adds r0, r3
	lsrs r0, 16
	ldrb r2, [r4, 0x8]
	ldr r3, =gUnknown_085E5310
	lsls r1, 1
	adds r1, r3
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	b _08172BEA
	.pool
_08172BE4:
	adds r0, r2, 0
	bl DestroyTask
_08172BEA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8172B90

	thumb_func_start sub_8172BF0
sub_8172BF0: @ 8172BF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r0, =gBankSpriteIds
	ldr r3, =gAnimBankAttacker
	ldrb r2, [r3]
	adds r0, r2, r0
	ldrb r6, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08172CC8
	cmp r0, 0x1
	bgt _08172C30
	cmp r0, 0
	beq _08172C36
	b _08172D8A
	.pool
_08172C30:
	cmp r0, 0x2
	beq _08172CDA
	b _08172D8A
_08172C36:
	ldr r0, =gBattleAnimArgs
	ldrh r0, [r0]
	strh r0, [r5, 0x1E]
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r2, 0
	ldrh r4, [r5, 0x8]
	adds r0, r4
	strh r0, [r5, 0x8]
	ldrb r0, [r3]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08172C78
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r1, r3, r6
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 24
	ldrh r4, [r1, 0x24]
	adds r0, r4
	strh r0, [r1, 0x24]
	adds r4, r3, 0
	b _08172C90
	.pool
_08172C78:
	ldr r3, =gSprites
	lsls r4, r6, 4
	adds r2, r4, r6
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r5, 0x8]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
_08172C90:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r3, r0, r1
	ldrb r0, [r3, 0x8]
	strh r0, [r3, 0x8]
	adds r0, r4, r6
	lsls r0, 2
	adds r0, r2
	movs r2, 0x20
	ldrsh r1, [r0, r2]
	movs r4, 0x24
	ldrsh r0, [r0, r4]
	adds r1, r0
	adds r1, 0x20
	movs r0, 0x98
	lsls r0, 1
	cmp r1, r0
	bls _08172D8A
	ldrh r0, [r3, 0x1C]
	adds r0, 0x1
	strh r0, [r3, 0x1C]
	b _08172D8A
	.pool
_08172CC8:
	ldrb r1, [r5, 0x1E]
	adds r0, r2, 0
	adds r2, r6, 0
	bl LoadBattleMonGfxAndAnimate
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	b _08172D8A
_08172CDA:
	movs r1, 0xA0
	lsls r1, 3
	adds r0, r1, 0
	ldrh r2, [r5, 0x8]
	adds r0, r2
	strh r0, [r5, 0x8]
	ldrb r0, [r3]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08172D10
	ldr r0, =gSprites
	lsls r3, r6, 4
	adds r2, r3, r6
	lsls r2, 2
	adds r2, r0
	ldrh r1, [r5, 0x8]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r4, r3, 0
	b _08172D28
	.pool
_08172D10:
	ldr r0, =gSprites
	lsls r2, r6, 4
	adds r1, r2, r6
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 24
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	adds r4, r2, 0
_08172D28:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x8]
	strh r1, [r0, 0x8]
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08172D68
	ldr r0, =gSprites
	adds r1, r4, r6
	lsls r1, 2
	adds r1, r0
	movs r4, 0x24
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bgt _08172D7E
	movs r0, 0
	strh r0, [r1, 0x24]
	b _08172D84
	.pool
_08172D68:
	ldr r0, =gSprites
	adds r1, r4, r6
	lsls r1, 2
	adds r1, r0
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _08172D7E
	strh r2, [r1, 0x24]
	movs r4, 0x1
	mov r8, r4
_08172D7E:
	mov r0, r8
	cmp r0, 0
	beq _08172D8A
_08172D84:
	adds r0, r7, 0
	bl DestroyAnimVisualTask
_08172D8A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172BF0

	thumb_func_start sub_8172D98
sub_8172D98: @ 8172D98
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08172E14
	cmp r0, 0x1
	bgt _08172DC0
	cmp r0, 0
	beq _08172DC6
	b _08172E84
	.pool
_08172DC0:
	cmp r0, 0x2
	beq _08172E4E
	b _08172E84
_08172DC6:
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	bl sub_80A8364
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08172DE8
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _08172DF0
	.pool
_08172DE8:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_08172DF0:
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _08172E84
	.pool
_08172E14:
	ldrh r0, [r4, 0xA]
	adds r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08172E84
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r2, [r4, 0x8]
	adds r2, 0x1
	strh r2, [r4, 0x8]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _08172E84
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	b _08172E84
_08172E4E:
	ldr r1, =gBankSpriteIds
	ldr r4, =gAnimBankAttacker
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r0, =0x06010000
	adds r1, r0
	movs r2, 0x80
	lsls r2, 4
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldrb r0, [r4]
	bl ClearBehindSubstituteBit
	adds r0, r5, 0
	bl DestroyAnimVisualTask
_08172E84:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172D98

	thumb_func_start sub_8172E9C
sub_8172E9C: @ 8172E9C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gBattleAnimArgs
	ldr r1, =gBattleSpritesDataPtr
	ldr r2, [r1]
	ldr r1, =gAnimBankAttacker
	ldrb r1, [r1]
	ldr r2, [r2]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	lsls r1, 29
	lsrs r1, 31
	strh r1, [r3, 0xE]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172E9C

	thumb_func_start sub_8172ED0
sub_8172ED0: @ 8172ED0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gAnimBankTarget
	ldr r1, =gEffectBank
	ldrb r1, [r1]
	strb r1, [r2]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172ED0

	thumb_func_start sub_8172EF0
sub_8172EF0: @ 8172EF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r4, r0, 0
	adds r0, r6, 0
	bl IsAnimBankSpriteVisible
	lsls r0, 24
	cmp r0, 0
	beq _08172FC8
	lsrs r0, r5, 16
	ldr r7, =0x0000ffff
	ands r5, r7
	eors r0, r5
	lsrs r1, r4, 16
	eors r0, r1
	ands r4, r7
	eors r0, r4
	cmp r0, 0x7
	bhi _08172F4E
	movs r0, 0x1
	mov r8, r0
_08172F4E:
	mov r0, r8
	cmp r0, 0
	beq _08172FC8
	ldr r0, =0x000027f9
	bl GetSpriteTileStartByTag
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r7
	bne _08172F6E
	ldr r0, =gBattleAnimPicTable + 0x748
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gBattleAnimPaletteTable + 0x748
	bl LoadCompressedObjectPaletteUsingHeap
_08172F6E:
	ldr r5, =sub_8172FEC
	adds r0, r5, 0
	movs r1, 0xA
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	adds r2, r3
	movs r4, 0
	strh r6, [r2, 0x8]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	strh r6, [r1, 0x8]
	strh r4, [r2, 0xA]
	movs r0, 0x1
	strh r0, [r1, 0xA]
	b _08172FDE
	.pool
_08172FC8:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x1]
_08172FDE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172EF0

	thumb_func_start sub_8172FEC
sub_8172FEC: @ 8172FEC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0x22]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0x3B
	bgt _08173018
	adds r0, r1, 0x1
	strh r0, [r4, 0x22]
	b _08173190
	.pool
_08173018:
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08173026
	b _08173190
_08173026:
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	beq _0817303A
	b _08173190
_0817303A:
	ldrb r0, [r4, 0x8]
	mov r8, r0
	movs r1, 0
	bl GetBankCoord
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	movs r1, 0x1
	bl GetBankCoord
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08173074
	ldr r0, =gUnknown_085CE388
	adds r1, r5, 0
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	b _081730D6
	.pool
_08173074:
	cmp r0, 0
	blt _081730A8
	cmp r0, 0x3
	bgt _081730A8
	ldr r0, =gUnknown_085CE3A0
	adds r1, r5, 0
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSprites
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	adds r2, r0
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x4
	b _081730C8
	.pool
_081730A8:
	ldr r0, =gUnknown_085CE3A0
	adds r1, r5, 0
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gSprites
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	adds r2, r0
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x5
_081730C8:
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
_081730D6:
	ldr r2, =gTasks
	lsls r1, r7, 2
	adds r0, r1, r7
	lsls r0, 3
	adds r6, r0, r2
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	mov r9, r1
	cmp r0, 0
	bne _08173118
	ldr r1, =gSprites
	lsls r2, r5, 4
	adds r0, r2, r5
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81731FC
	str r1, [r0]
	adds r4, r2, 0
	b _08173160
	.pool
_08173118:
	ldr r3, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =sub_8173250
	str r2, [r0]
	adds r1, r3
	ldr r0, =0x0000ffe0
	strh r0, [r1, 0x24]
	movs r0, 0x20
	strh r0, [r1, 0x26]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	movs r1, 0x1E
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08173160
	mov r0, r8
	bl GetBankSide
	lsls r0, 24
	movs r1, 0x3F
	cmp r0, 0
	bne _08173156
	movs r1, 0xC0
_08173156:
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x66
	bl PlaySE12WithPanning
_08173160:
	ldr r1, =gSprites
	adds r0, r4, r5
	lsls r0, 2
	adds r0, r1
	strh r7, [r0, 0x2E]
	ldr r1, =gTasks
	mov r2, r9
	adds r0, r2, r7
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	cmp r5, 0x40
	beq _08173184
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
_08173184:
	movs r4, 0x1E
	ldrsh r0, [r1, r4]
	cmp r0, 0x5
	bne _08173190
	ldr r0, =sub_81731B0
	str r0, [r1]
_08173190:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172FEC

	thumb_func_start sub_81731B0
sub_81731B0: @ 81731B0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r1, r0, r1
	movs r2, 0x20
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _081731F0
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _081731EA
	ldrb r1, [r1, 0x8]
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x1]
_081731EA:
	adds r0, r3, 0
	bl DestroyTask
_081731F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81731B0

	thumb_func_start sub_81731FC
sub_81731FC: @ 81731FC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x18
	bl Sin
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x18
	bl Cos
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0xC
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _08173246
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_08173246:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81731FC

	thumb_func_start sub_8173250
sub_8173250: @ 8173250
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	bgt _08173264
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	b _081732A6
_08173264:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r1, [r4, 0x24]
	adds r1, 0x5
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r0, 0x5
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x20
	ble _081732A6
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
_081732A6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173250

	thumb_func_start sub_81732B0
sub_81732B0: @ 81732B0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gBattleAnimPicTable + 0x868
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gBattleAnimPaletteTable + 0x868
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r0, =0x0000281d
	bl IndexOfSpritePaletteTag
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81732B0

	thumb_func_start sub_81732E4
sub_81732E4: @ 81732E4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =0x0000281d
	adds r0, r5, 0
	bl FreeSpriteTilesByTag
	adds r0, r5, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81732E4

	thumb_func_start sub_817330C
sub_817330C: @ 817330C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	movs r0, 0x1
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetBankCoord
	lsls r0, 24
	ldr r5, =gBattleAnimArgs
	lsrs r0, 24
	ldrh r1, [r5, 0x4]
	adds r0, r1
	strh r0, [r4, 0x32]
	movs r0, 0x1
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl GetBankCoord
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5, 0x6]
	adds r0, r5
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039E84
	str r1, [r0]
	ldr r0, =sub_817339C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817330C

	thumb_func_start sub_817339C
sub_817339C: @ 817339C
	push {lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	ldr r1, =gBankSpriteIds
	ldr r0, =gAnimBankAttacker
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081733C0
	ldr r0, =sub_81733D4
	str r0, [r3, 0x1C]
_081733C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817339C

	thumb_func_start sub_81733D4
sub_81733D4: @ 81733D4
	push {r4,lr}
	adds r4, r0, 0
	bl AnimateBallThrow
	lsls r0, 24
	cmp r0, 0
	beq _081733F6
	movs r0, 0
	strh r0, [r4, 0x2E]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_8173400
	str r0, [r4, 0x1C]
_081733F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81733D4

	thumb_func_start sub_8173400
sub_8173400: @ 8173400
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gSprites
	ldr r3, =gBankSpriteIds
	ldr r2, =gAnimBankAttacker
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _08173448
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	ble _08173448
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0
	bl StartSpriteAnim
	adds r0, r4, 0
	bl DestroyAnimSprite
_08173448:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173400

	thumb_func_start sub_817345C
sub_817345C: @ 817345C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gBattleAnimArgs
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08173478
	cmp r0, 0x1
	beq _0817348C
	b _081734A0
	.pool
_08173478:
	movs r0, 0
	bl GetBankByIdentity
	ldr r1, =gAnimBankAttacker
	strb r0, [r1]
	movs r0, 0x1
	b _08173498
	.pool
_0817348C:
	movs r0, 0x1
	bl GetBankByIdentity
	ldr r1, =gAnimBankAttacker
	strb r0, [r1]
	movs r0, 0
_08173498:
	bl GetBankByIdentity
	ldr r1, =gAnimBankTarget
	strb r0, [r1]
_081734A0:
	adds r0, r4, 0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817345C

	thumb_func_start sub_81734B4
sub_81734B4: @ 81734B4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gBattleSpritesDataPtr
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrh r1, [r0]
	cmp r1, 0x53
	bne _081734D4
	ldr r1, =gBattleAnimArgs
	movs r0, 0x1
	b _0817350C
	.pool
_081734D4:
	cmp r1, 0xFA
	bne _081734E4
	ldr r1, =gBattleAnimArgs
	movs r0, 0x2
	b _0817350C
	.pool
_081734E4:
	cmp r1, 0x80
	bne _081734F4
	ldr r1, =gBattleAnimArgs
	movs r0, 0x3
	b _0817350C
	.pool
_081734F4:
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	bne _08173508
	ldr r1, =gBattleAnimArgs
	movs r0, 0x4
	b _0817350C
	.pool
_08173508:
	ldr r1, =gBattleAnimArgs
	movs r0, 0
_0817350C:
	strh r0, [r1]
	adds r0, r2, 0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81734B4

	thumb_func_start sub_817351C
sub_817351C: @ 817351C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gAnimBankAttacker
	ldr r1, =gBattleSpritesDataPtr
	ldr r2, [r1]
	ldr r1, [r2, 0x8]
	ldrh r1, [r1]
	strb r1, [r3]
	ldr r3, =gAnimBankTarget
	ldr r1, [r2, 0x8]
	ldrh r1, [r1]
	lsrs r1, 8
	strb r1, [r3]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817351C

	.align 2, 0 @ Don't pad with nop.
