	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81DA700
sub_81DA700: @ 81DA700
	push {lr}
	sub sp, 0x8
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_0862AD54
	ldr r1, [sp, 0x4]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_0862AF30
	ldr r1, [sp]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_0862B53C
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0862B724
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0862B72C
	bl LoadSpritePalette
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA700

	thumb_func_start sub_81DA74C
sub_81DA74C: @ 81DA74C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x24]
	ldr r1, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r4, 24
	lsrs r7, r4, 24
	ldr r0, =gUnknown_0862B758
	lsls r5, 16
	asrs r5, 16
	lsls r6, 16
	asrs r6, 16
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r7, 0x1
	beq _081DA7D0
	cmp r7, 0x1
	bgt _081DA7A8
	cmp r7, 0
	beq _081DA7B8
	b _081DA7AC
	.pool
_081DA7A8:
	cmp r7, 0x2
	beq _081DA7E4
_081DA7AC:
	ldr r6, =gSprites
	lsls r3, r5, 4
	b _081DA7F8
	.pool
_081DA7B8:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x78
	strh r1, [r0, 0x2E]
	movs r1, 0x2D
	b _081DA7F4
	.pool
_081DA7D0:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x59
	b _081DA7F0
	.pool
_081DA7E4:
	ldr r2, =gSprites
	lsls r3, r5, 4
	adds r0, r3, r5
	lsls r0, 2
	adds r0, r2
	movs r1, 0x97
_081DA7F0:
	strh r1, [r0, 0x2E]
	movs r1, 0x61
_081DA7F4:
	strh r1, [r0, 0x30]
	adds r6, r2, 0
_081DA7F8:
	adds r4, r3, r5
	lsls r4, 2
	adds r0, r4, r6
	mov r2, r8
	lsls r1, r2, 24
	asrs r1, 24
	movs r2, 0
	strh r1, [r0, 0x32]
	mov r3, r9
	lsls r1, r3, 24
	asrs r1, 24
	strh r1, [r0, 0x34]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, 0x3A]
	mov r3, r10
	strh r3, [r0, 0x3C]
	strh r2, [r0, 0x36]
	strh r2, [r0, 0x38]
	adds r1, r7, 0
	bl StartSpriteAnim
	adds r0, r6, 0
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_81DA848
	str r0, [r4]
	adds r0, r5, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DA74C

	thumb_func_start sub_81DA848
sub_81DA848: @ 81DA848
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r2, r3, 0
	adds r2, 0x2E
	movs r0, 0x20
	ldrsh r1, [r3, r0]
	movs r4, 0x2E
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bne _081DA874
	movs r5, 0x22
	ldrsh r1, [r3, r5]
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bne _081DA874
	ldr r0, =SpriteCallbackDummy
	str r0, [r3, 0x1C]
	b _081DA8B4
	.pool
_081DA874:
	ldrh r4, [r2, 0x8]
	movs r5, 0x8
	ldrsh r1, [r2, r5]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _081DA890
	ldrh r0, [r2, 0x4]
	ldrh r1, [r3, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r3, 0x20]
	strh r1, [r2, 0x8]
	b _081DA894
_081DA890:
	adds r0, r4, 0x1
	strh r0, [r2, 0x8]
_081DA894:
	ldrh r4, [r2, 0xA]
	movs r5, 0xA
	ldrsh r1, [r2, r5]
	movs r5, 0xE
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _081DA8B0
	ldrh r0, [r2, 0x6]
	ldrh r1, [r3, 0x22]
	adds r0, r1
	movs r1, 0
	strh r0, [r3, 0x22]
	strh r1, [r2, 0xA]
	b _081DA8B4
_081DA8B0:
	adds r0, r4, 0x1
	strh r0, [r2, 0xA]
_081DA8B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81DA848

	thumb_func_start sub_81DA8BC
sub_81DA8BC: @ 81DA8BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r1
	ldr r0, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x4]
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r7, r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0862B758
	lsls r6, 16
	asrs r6, 16
	mov r1, r8
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	adds r1, r6, 0
	mov r2, r8
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r5, 0x1
	beq _081DA94C
	cmp r5, 0x1
	bgt _081DA924
	cmp r5, 0
	beq _081DA934
	b _081DA928
	.pool
_081DA924:
	cmp r5, 0x2
	beq _081DA960
_081DA928:
	ldr r2, =gSprites
	lsls r3, r6, 4
	b _081DA972
	.pool
_081DA934:
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0x78
	strh r1, [r0, 0x2E]
	movs r1, 0x2D
	b _081DA970
	.pool
_081DA94C:
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0x59
	b _081DA96C
	.pool
_081DA960:
	ldr r2, =gSprites
	lsls r3, r6, 4
	adds r0, r3, r6
	lsls r0, 2
	adds r0, r2
	movs r1, 0x97
_081DA96C:
	strh r1, [r0, 0x2E]
	movs r1, 0x61
_081DA970:
	strh r1, [r0, 0x30]
_081DA972:
	adds r4, r3, r6
	lsls r4, 2
	adds r0, r4, r2
	mov r3, sp
	ldrh r3, [r3]
	strh r3, [r0, 0x32]
	mov r1, sp
	ldrh r1, [r1, 0x4]
	strh r1, [r0, 0x34]
	mov r3, r10
	strh r3, [r0, 0x36]
	mov r1, r9
	strh r1, [r0, 0x38]
	strh r7, [r0, 0x3A]
	adds r1, r5, 0
	str r2, [sp, 0x8]
	bl StartSpriteAnim
	ldr r2, [sp, 0x8]
	adds r0, r2, 0
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_81DA9BC
	str r0, [r4]
	adds r0, r6, 0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81DA8BC

	thumb_func_start sub_81DA9BC
sub_81DA9BC: @ 81DA9BC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x32]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	muls r0, r1
	asrs r0, 12
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x32]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x36
	ldrsh r1, [r4, r3]
	muls r0, r1
	asrs r0, 12
	strh r0, [r4, 0x26]
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r2, 0x34
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0xB4
	lsls r1, 1
	bl __modsi3
	strh r0, [r4, 0x32]
	ldrh r2, [r4, 0x36]
	movs r3, 0x36
	ldrsh r1, [r4, r3]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	beq _081DAA12
	ldrh r0, [r4, 0x3A]
	adds r0, r2, r0
	strh r0, [r4, 0x36]
	b _081DAA16
_081DAA12:
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081DAA16:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DA9BC

	thumb_func_start sub_81DAA20
sub_81DAA20: @ 81DAA20
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =0x00002e90
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	movs r0, 0x10
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	movs r0, 0x12
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81DAA20

	thumb_func_start sub_81DAA74
sub_81DAA74: @ 81DAA74
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	movs r0, 0x10
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r2, 0
	adds r5, 0x1C
	adds r0, r5
	ldr r4, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r4, r0
	bne _081DAAC4
	movs r0, 0x12
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r2, [r0]
	cmp r2, r4
	bne _081DAAC4
	movs r1, 0x14
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldr r0, [r1]
	cmp r0, r2
	bne _081DAAC4
	movs r0, 0x1
	b _081DAAC6
	.pool
_081DAAC4:
	movs r0, 0
_081DAAC6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAA74

	thumb_func_start sub_81DAACC
sub_81DAACC: @ 81DAACC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081DAB20
	bl sub_81DA700
	ldr r1, =0x00003f41
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r1, 0xA0
	lsls r1, 3
	movs r0, 0
	movs r2, 0x2
	bl ChangeBgY
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	b _081DAB46
	.pool
_081DAB20:
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	bl ClearGpuRegBits
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
_081DAB46:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAACC

	thumb_func_start sub_81DAB4C
sub_81DAB4C: @ 81DAB4C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081DAB64
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0
	bl SetGpuRegBits
_081DAB64:
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bne _081DAB98
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0x1F
	bne _081DAB92
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	str r0, [sp]
	adds r0, r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _081DABB0
_081DAB92:
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _081DABB0
_081DAB98:
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	ldrh r1, [r4, 0xC]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_081DABB0:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81DAB4C

	.align 2, 0 @ Don't pad with nop.
