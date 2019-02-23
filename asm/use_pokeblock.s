	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8167BA0
sub_8167BA0: @ 8167BA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r7, =gUnknown_0203BCAC
	ldr r3, [r7]
	ldr r1, =0x00008041
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08167C46
	lsls r2, r4, 6
	ldr r0, =0x00007b95
	adds r2, r0
	adds r2, r3, r2
	movs r0, 0x1
	str r0, [sp]
	movs r5, 0
	str r5, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	ldr r1, =0x00008041
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81672A4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNature
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, [r7]
	ldr r6, =0x0000804a
	adds r0, r6
	ldr r1, =gText_NatureSlash
	bl StringCopy
	ldr r1, =gNatureNamePointers
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	bl StringCopy
	ldr r0, =gUnknown_085DFCC9
	str r0, [sp]
	str r5, [sp, 0x4]
	ldr r0, [r7]
	adds r0, r6
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x1
	bl AddTextPrinterParameterized3
_08167C46:
	mov r2, r8
	cmp r2, 0
	beq _08167C84
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	b _08167C94
	.pool
_08167C84:
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_08167C94:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8167BA0

	thumb_func_start sub_8167CA0
sub_8167CA0: @ 8167CA0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _08167CC0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007fb5
	adds r0, r1
	b _08167CC8
	.pool
_08167CC0:
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00007fb4
	adds r0, r2
_08167CC8:
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r5, =gUnknown_0203BCAC
	ldr r2, [r5]
	ldr r3, =0x00007c58
	adds r0, r2, r3
	ldr r4, =0x00007fb3
	adds r1, r2, r4
	movs r3, 0
	ldrsb r3, [r1, r3]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	ldr r4, =0x00007c6c
	adds r1, r4
	adds r1, r2, r1
	lsls r3, r6, 2
	adds r3, r6
	lsls r3, 2
	adds r3, r4
	adds r2, r3
	bl sub_81D1F84
	ldr r4, [r5]
	ldr r1, =0x00008041
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, =0x00008040
	mov r12, r2
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, 0x1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	cmp r7, 0
	beq _08167D98
	ldr r3, =0x00007fb4
	adds r0, r4, r3
	ldrb r1, [r0]
	subs r2, 0x8B
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00007fb3
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, =0x00007fb6
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	adds r3, 0x8D
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08167D58
	mov r4, r12
	adds r0, r1, r4
	ldrb r0, [r0]
_08167D58:
	subs r2, r0, 0x1
	ldr r0, =0x00008041
	adds r1, r0
	strb r2, [r1]
	ldr r1, =gUnknown_0203BCAC
	ldr r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0
	bne _08167D74
	ldr r1, =0x00008040
	adds r0, r3, r1
	ldrb r0, [r0]
_08167D74:
	subs r1, r0, 0x1
	b _08167E1E
	.pool
_08167D98:
	ldr r3, =0x00007fb5
	adds r0, r4, r3
	ldrb r1, [r0]
	ldr r2, =0x00007fb4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, =0x00007fb3
	adds r1, r0, r4
	ldrb r1, [r1]
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, =0x00007fb6
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r5]
	adds r3, 0x8C
	adds r0, r2, r3
	ldrb r1, [r0]
	adds r4, 0x8D
	adds r0, r2, r4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bge _08167DEC
	adds r3, r1, 0x1
	b _08167DEE
	.pool
_08167DEC:
	movs r3, 0
_08167DEE:
	ldr r1, =0x00008041
	adds r0, r2, r1
	strb r3, [r0]
	ldr r2, =gUnknown_0203BCAC
	ldr r3, [r2]
	adds r1, r3, r1
	ldrb r1, [r1]
	ldr r4, =0x00008040
	adds r0, r3, r4
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r2, 0
	cmp r1, r0
	bge _08167E1C
	adds r1, 0x1
	b _08167E1E
	.pool
_08167E1C:
	movs r1, 0
_08167E1E:
	ldr r2, =0x00007b4c
	adds r0, r3, r2
	strb r1, [r0]
	adds r5, r6, 0
	ldr r0, [r5]
	ldr r3, =0x00008041
	adds r1, r0, r3
	ldrb r2, [r1]
	ldr r4, =0x00008040
	adds r1, r0, r4
	ldrb r1, [r1]
	subs r1, 0x1
	eors r2, r1
	negs r1, r2
	orrs r1, r2
	lsrs r4, r1, 31
	ldr r1, =0x00007b1c
	adds r0, r1
	bl sub_81D3520
	mov r2, r8
	cmp r2, 0
	bne _08167E70
	ldr r0, [r5]
	ldr r3, =0x00008044
	adds r0, r3
	ldr r1, =sub_8167EA4
	b _08167E90
	.pool
_08167E70:
	cmp r4, 0
	bne _08167E88
	ldr r0, [r5]
	ldr r4, =0x00008044
	adds r0, r4
	ldr r1, =sub_8167FA4
	b _08167E90
	.pool
_08167E88:
	ldr r0, [r6]
	ldr r1, =0x00008044
	adds r0, r1
	ldr r1, =sub_8168048
_08167E90:
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8167CA0

	thumb_func_start sub_8167EA4
sub_8167EA4: @ 8167EA4
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08167EE4
	cmp r0, 0x1
	bgt _08167EC8
	cmp r0, 0
	beq _08167ED2
	b _08167F9C
	.pool
_08167EC8:
	cmp r0, 0x2
	beq _08167F08
	cmp r0, 0x3
	beq _08167F48
	b _08167F9C
_08167ED2:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	bl sub_8167608
	b _08167F2C
	.pool
_08167EE4:
	ldr r6, =0x00007fb3
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	b _08167F30
	.pool
_08167F08:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r6, =0x00007b0e
	adds r1, r6
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _08167F9C
	ldr r1, [r4]
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r6, =0x00007fb6
	adds r1, r6
	ldrb r1, [r1]
	bl sub_816753C
_08167F2C:
	ldr r1, [r4]
	adds r1, r5
_08167F30:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08167F9C
	.pool
_08167F48:
	ldr r2, =0x00007b1c
	adds r0, r1, r2
	bl sub_81D3464
	ldr r3, [r4]
	ldr r6, =0x00008041
	adds r0, r3, r6
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08167F82
	subs r6, 0x8E
	adds r0, r3, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r6, =0x00007b1c
	adds r0, r3, r6
	subs r6, 0xC
	adds r1, r3, r6
	ldrb r1, [r1]
	bl sub_81D3480
_08167F82:
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	movs r0, 0
	b _08167F9E
	.pool
_08167F9C:
	movs r0, 0x1
_08167F9E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8167EA4

	thumb_func_start sub_8167FA4
sub_8167FA4: @ 8167FA4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r2, r1, r5
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08167FF0
	cmp r0, 0x1
	bgt _08167FC8
	cmp r0, 0
	beq _08167FD2
	b _0816803E
	.pool
_08167FC8:
	cmp r0, 0x2
	beq _08168014
	cmp r0, 0x3
	beq _08168038
	b _0816803E
_08167FD2:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r2, =0x00007b0e
	adds r1, r2
	bl sub_81D31A4
	lsls r0, 24
	cmp r0, 0
	bne _0816803E
	b _08168024
	.pool
_08167FF0:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	b _08168028
	.pool
_08168014:
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r2, =0x00007fb6
	adds r1, r2
	ldrb r1, [r1]
	bl sub_816753C
_08168024:
	ldr r1, [r4]
	adds r1, r5
_08168028:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0816803E
	.pool
_08168038:
	movs r0, 0
	strb r0, [r2]
	b _08168040
_0816803E:
	movs r0, 0x1
_08168040:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8167FA4

	thumb_func_start sub_8168048
sub_8168048: @ 8168048
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r1, [r4]
	ldr r5, =0x00008048
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081680A8
	cmp r0, 0x1
	bgt _0816806C
	cmp r0, 0
	beq _08168076
	b _08168160
	.pool
_0816806C:
	cmp r0, 0x2
	beq _081680CC
	cmp r0, 0x3
	beq _0816810C
	b _08168160
_08168076:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	bl sub_81D2074
	ldr r0, [r4]
	ldr r6, =0x00007b0e
	adds r0, r6
	bl sub_81D3150
	lsls r0, 24
	cmp r0, 0
	bne _08168160
	ldr r0, [r4]
	ldr r1, =0x00007fb3
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8167608
	b _081680F0
	.pool
_081680A8:
	ldr r2, =0x00007fb3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_8167BA0
	ldr r1, [r4]
	ldr r6, =0x00008048
	adds r1, r6
	b _081680F4
	.pool
_081680CC:
	ldr r2, =0x00007c58
	adds r0, r1, r2
	ldr r6, =0x00007b0e
	adds r1, r6
	bl sub_81D3178
	lsls r0, 24
	cmp r0, 0
	bne _08168160
	ldr r1, [r4]
	ldr r2, =0x00007b4c
	adds r0, r1, r2
	ldrb r0, [r0]
	ldr r6, =0x00007fb6
	adds r1, r6
	ldrb r1, [r1]
	bl sub_816753C
_081680F0:
	ldr r1, [r4]
	adds r1, r5
_081680F4:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08168160
	.pool
_0816810C:
	ldr r2, =0x00007b1c
	adds r0, r1, r2
	bl sub_81D3464
	ldr r3, [r4]
	ldr r6, =0x00008041
	adds r0, r3, r6
	ldrb r1, [r0]
	ldr r2, =0x00008040
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _08168146
	subs r6, 0x8E
	adds r0, r3, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r2, 0x90
	adds r0, r3, r2
	adds r0, r1
	ldrb r2, [r0]
	ldr r6, =0x00007b1c
	adds r0, r3, r6
	subs r6, 0xC
	adds r1, r3, r6
	ldrb r1, [r1]
	bl sub_81D3480
_08168146:
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
	movs r0, 0
	b _08168162
	.pool
_08168160:
	movs r0, 0x1
_08168162:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8168048

	thumb_func_start sub_8168168
sub_8168168: @ 8168168
	ldr r1, =gUnknown_0203BCAC
	ldr r1, [r1]
	ldr r2, =0x00007b0e
	adds r1, r2
	ldrh r1, [r1]
	adds r1, 0x26
	strh r1, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_8168168

	thumb_func_start sub_8168180
sub_8168180: @ 8168180
	push {lr}
	adds r2, r0, 0
	movs r0, 0x2E
	ldrsh r1, [r2, r0]
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r3, =0x00008041
	adds r0, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _081681A8
	adds r0, r2, 0
	movs r1, 0
	bl StartSpriteAnim
	b _081681B0
	.pool
_081681A8:
	adds r0, r2, 0
	movs r1, 0x1
	bl StartSpriteAnim
_081681B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8168180

	thumb_func_start sub_81681B4
sub_81681B4: @ 81681B4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r2, =0x00008041
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _081681DC
	movs r0, 0x65
	b _081681DE
	.pool
_081681DC:
	movs r0, 0x66
_081681DE:
	bl IndexOfSpritePaletteTag
	lsls r0, 4
	ldrb r2, [r4, 0x5]
	movs r1, 0xF
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81681B4

	thumb_func_start sub_81681F4
sub_81681F4: @ 81681F4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	bl GetMonData
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r3, =0x00007fb3
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r3, 0x3
	adds r0, r3
	adds r4, r0, r1
	cmp r2, 0xFF
	beq _0816823C
	adds r0, r2, 0
	movs r1, 0x1D
	bl __udivsi3
	b _0816823E
	.pool
_0816823C:
	movs r0, 0x9
_0816823E:
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81681F4

	thumb_func_start sub_8168248
sub_8168248: @ 8168248
	push {lr}
	sub sp, 0x10
	ldr r0, =gUnknown_085DFDB8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gUsePokeblockCondition_Gfx
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x80
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	adds r1, 0x1
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadCompressedSpriteSheet
	add r0, sp, 0x8
	bl LoadSpritePalette
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168248

	thumb_func_start sub_8168294
sub_8168294: @ 8168294
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0203BCAC
	ldr r0, [r0]
	ldr r1, =0x00007b44
	adds r7, r0, r1
	ldr r0, =gUnknown_085DFDA0
	mov r10, r0
	movs r6, 0
	movs r1, 0x40
	mov r9, r1
	movs r0, 0x60
	negs r0, r0
	mov r8, r0
_081682B6:
	mov r5, r9
	muls r5, r6
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x11
	lsls r2, r0, 16
	mov r0, r10
	asrs r2, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _081682FE
	ldr r0, =gSprites
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	adds r4, r0
	movs r1, 0x8
	strh r1, [r4, 0x2E]
	movs r0, 0x20
	orrs r5, r0
	strh r5, [r4, 0x30]
	strh r6, [r4, 0x32]
	lsls r1, r6, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	lsls r0, r6, 2
	adds r0, r7
	str r4, [r0]
_081682FE:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1
	bls _081682B6
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168294

	thumb_func_start sub_8168328
sub_8168328: @ 8168328
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203BCAC
	ldr r0, [r4]
	ldr r5, =0x00008048
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08168348
	cmp r0, 0x1
	beq _08168360
	b _0816836C
	.pool
_08168348:
	bl sub_8168248
	ldr r1, [r4]
	ldr r0, =0x00008048
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	b _0816836E
	.pool
_08168360:
	bl sub_8168294
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0
	strb r1, [r0]
_0816836C:
	movs r0, 0
_0816836E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8168328

	thumb_func_start sub_8168374
sub_8168374: @ 8168374
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x20]
	ldrh r1, [r2, 0x2E]
	adds r3, r0, r1
	strh r3, [r2, 0x20]
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x30
	ldrsh r1, [r2, r0]
	cmp r4, r1
	bgt _08168398
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	bge _081683A0
	cmp r4, r1
	blt _081683A8
_08168398:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r1
	bgt _081683A8
_081683A0:
	ldrh r0, [r2, 0x30]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081683A8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8168374

	.align 2, 0 @ Don't pad with nop.
