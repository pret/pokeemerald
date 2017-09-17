	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AllocItemIconTemporaryBuffers
@ bool8 AllocItemIconTemporaryBuffers()
AllocItemIconTemporaryBuffers: @ 81AFDE4
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203CEBC
	movs r0, 0x90
	lsls r0, 1
	bl Alloc
	str r0, [r5]
	cmp r0, 0
	beq _081AFE1A
	ldr r4, =gUnknown_0203CEC0
	movs r0, 0x80
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	cmp r0, 0
	beq _081AFE14
	movs r0, 0x1
	b _081AFE1C
	.pool
_081AFE14:
	ldr r0, [r5]
	bl Free
_081AFE1A:
	movs r0, 0
_081AFE1C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end AllocItemIconTemporaryBuffers

	thumb_func_start FreeItemIconTemporaryBuffers
@ void FreeItemIconTemporaryBuffers()
FreeItemIconTemporaryBuffers: @ 81AFE24
	push {lr}
	ldr r0, =gUnknown_0203CEBC
	ldr r0, [r0]
	bl Free
	ldr r0, =gUnknown_0203CEC0
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeItemIconTemporaryBuffers

	thumb_func_start CopyItemIconPicTo4x4Buffer
@ void CopyItemIconPicTo4x4Buffer(void *src, void *dest)
CopyItemIconPicTo4x4Buffer: @ 81AFE44
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r4, 0
_081AFE4C:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 5
	adds r0, r6, r0
	lsls r1, r4, 7
	adds r1, r5, r1
	movs r2, 0x30
	bl CpuSet
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081AFE4C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end CopyItemIconPicTo4x4Buffer

	thumb_func_start AddItemIconObject
@ u8 AddItemIconObject(u16 tilesTag, u16 paletteTag, u16 itemId)
AddItemIconObject: @ 81AFE70
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	bl AllocItemIconTemporaryBuffers
	lsls r0, 24
	cmp r0, 0
	beq _081AFF28
	adds r0, r5, 0
	movs r1, 0
	bl GetItemIconPicOrPalette
	ldr r4, =gUnknown_0203CEBC
	ldr r1, [r4]
	bl LZDecompressWram
	ldr r0, [r4]
	ldr r4, =gUnknown_0203CEC0
	ldr r1, [r4]
	bl CopyItemIconPicTo4x4Buffer
	ldr r0, [r4]
	str r0, [sp]
	ldr r4, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r4
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	lsls r2, r7, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r5, 0
	movs r1, 0x1
	bl GetItemIconPicOrPalette
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	ldr r1, [r0, 0x4]
	ands r1, r4
	orrs r1, r6
	str r1, [r0, 0x4]
	bl LoadCompressedObjectPalette
	movs r0, 0x18
	bl Alloc
	adds r5, r0, 0
	ldr r0, =gUnknown_08614FF4
	adds r1, r5, 0
	movs r2, 0xC
	bl CpuSet
	strh r7, [r5]
	strh r6, [r5, 0x2]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl FreeItemIconTemporaryBuffers
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	b _081AFF2A
	.pool
_081AFF28:
	movs r0, 0x40
_081AFF2A:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AddItemIconObject

	thumb_func_start AddItemIconObjectWithCustomObjectTemplate
@ u8 AddItemIconObjectWithCustomObjectTemplate(struct objtemplate *objectTemplate, u16 tilesTag, u16 paletteTag, u16 itemId)
AddItemIconObjectWithCustomObjectTemplate: @ 81AFF34
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	bl AllocItemIconTemporaryBuffers
	lsls r0, 24
	cmp r0, 0
	beq _081AFFEC
	adds r0, r5, 0
	movs r1, 0
	bl GetItemIconPicOrPalette
	ldr r4, =gUnknown_0203CEBC
	ldr r1, [r4]
	bl LZDecompressWram
	ldr r0, [r4]
	ldr r4, =gUnknown_0203CEC0
	ldr r1, [r4]
	bl CopyItemIconPicTo4x4Buffer
	ldr r0, [r4]
	str r0, [sp]
	ldr r4, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r4
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	lsls r2, r7, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r5, 0
	movs r1, 0x1
	bl GetItemIconPicOrPalette
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	ldr r1, [r0, 0x4]
	ands r1, r4
	orrs r1, r6
	str r1, [r0, 0x4]
	bl LoadCompressedObjectPalette
	movs r0, 0x18
	bl Alloc
	adds r5, r0, 0
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0xC
	bl CpuSet
	strh r7, [r5]
	strh r6, [r5, 0x2]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl FreeItemIconTemporaryBuffers
	adds r0, r5, 0
	bl Free
	adds r0, r4, 0
	b _081AFFEE
	.pool
_081AFFEC:
	movs r0, 0x40
_081AFFEE:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AddItemIconObjectWithCustomObjectTemplate

	thumb_func_start GetItemIconPicOrPalette
@ u32 GetItemIconPicOrPalette(u16 itemId, u8 which)
GetItemIconPicOrPalette: @ 81AFFFC
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =0x0000ffff
	cmp r3, r0
	bne _081B0018
	ldr r3, =0x00000179
	b _081B0022
	.pool
_081B0018:
	movs r0, 0xBC
	lsls r0, 1
	cmp r3, r0
	bls _081B0022
	movs r3, 0
_081B0022:
	ldr r2, =gItemIconTable
	lsls r0, r1, 2
	lsls r1, r3, 3
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetItemIconPicOrPalette

	thumb_func_start sub_81B0038
sub_81B0038: @ 81B0038
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	lsls r4, 24
	lsrs r6, r4, 24
	bl reset_brm
	ldr r0, =gUnknown_0203CEC4
	mov r10, r0
	movs r0, 0x8E
	lsls r0, 2
	bl Alloc
	adds r5, r0, 0
	mov r1, r10
	str r5, [r1]
	cmp r5, 0
	bne _081B0088
	ldr r0, [sp, 0x2C]
	bl SetMainCallback2
	b _081B0194
	.pool
_081B0088:
	ldr r3, =gUnknown_0203CEC8
	movs r1, 0xF
	mov r4, r8
	ands r1, r4
	ldrb r2, [r3, 0x8]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x8]
	ldr r0, [sp, 0x2C]
	str r0, [r3]
	movs r4, 0
	strb r7, [r3, 0xB]
	lsls r2, r6, 2
	ldrh r1, [r5, 0xA]
	movs r0, 0x3
	ands r0, r1
	orrs r0, r2
	strh r0, [r5, 0xA]
	ldr r0, [sp, 0x28]
	str r0, [r5]
	str r4, [r5, 0x4]
	ldrb r1, [r5, 0x8]
	movs r0, 0xF
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x8]
	mov r1, r10
	ldr r2, [r1]
	ldrh r0, [r2, 0x8]
	movs r4, 0xFE
	lsls r4, 3
	adds r1, r4, 0
	orrs r0, r1
	strh r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xFE
	lsls r1, 10
	orrs r0, r1
	str r0, [r2, 0x8]
	adds r6, r3, 0
	mov r5, r8
	cmp r5, 0x4
	bne _081B00F0
	ldrb r0, [r2, 0x8]
	movs r1, 0x1
	orrs r0, r1
	b _081B00F8
	.pool
_081B00F0:
	ldrb r1, [r2, 0x8]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
_081B00F8:
	strb r0, [r2, 0x8]
	mov r0, r9
	cmp r0, 0xFF
	beq _081B0114
	movs r0, 0x3
	mov r1, r9
	ands r0, r1
	lsls r0, 4
	ldrb r2, [r6, 0x8]
	movs r1, 0x31
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x8]
_081B0114:
	movs r2, 0
	ldr r5, =gUnknown_0203CEC4
	movs r4, 0x86
	lsls r4, 2
	movs r3, 0
_081B011E:
	ldr r0, [r5]
	lsls r1, r2, 1
	adds r0, r4
	adds r0, r1
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _081B011E
	movs r2, 0
	ldr r4, =gUnknown_0203CEC4
	movs r3, 0xFF
_081B0138:
	ldr r0, [r4]
	adds r0, 0xC
	adds r0, r2
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x2
	bls _081B0138
	ldr r4, [sp]
	cmp r4, 0
	bne _081B015C
	strb r4, [r6, 0x9]
	b _081B017E
	.pool
_081B015C:
	adds r1, r6, 0
	movs r0, 0x9
	ldrsb r0, [r1, r0]
	cmp r0, 0x5
	bgt _081B017A
	adds r1, r0, 0
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	bne _081B017E
_081B017A:
	movs r0, 0
	strb r0, [r6, 0x9]
_081B017E:
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl CalculatePlayerPartyCount
	ldr r0, =c2_811EBD0
	bl SetMainCallback2
_081B0194:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B0038

	.align 2, 0 @ Don't pad with nop.
