	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified
    
@ File centered around AllocSubstruct(9)

	thumb_func_start sub_81CF9BC
sub_81CF9BC: @ 81CF9BC
	push {r4,lr}
	movs r0, 0x9
	movs r1, 0x20
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CF9FC
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl AllocSubstruct
	str r0, [r4, 0x1C]
	cmp r0, 0
	beq _081CF9FC
	ldr r0, =sub_81CFA68
	str r0, [r4]
	ldr r0, =sub_81CFB74
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	movs r0, 0
	str r0, [r4, 0x14]
	movs r0, 0x1
	b _081CF9FE
	.pool
_081CF9FC:
	movs r0, 0
_081CF9FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CF9BC

	thumb_func_start sub_81CFA04
sub_81CFA04: @ 81CFA04
	push {r4,lr}
	movs r0, 0x9
	movs r1, 0x20
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFA2C
	movs r0, 0x12
	bl GetSubstructPtr
	str r0, [r4, 0x1C]
	ldr r0, =sub_81CFA88
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0x14]
	b _081CFA2E
	.pool
_081CFA2C:
	movs r0, 0
_081CFA2E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFA04

	thumb_func_start sub_81CFA34
sub_81CFA34: @ 81CFA34
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81CFA34

	thumb_func_start sub_81CFA48
sub_81CFA48: @ 81CFA48
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	ldr r0, [r0, 0x18]
	cmp r0, 0
	bne _081CFA5C
	movs r0, 0x12
	bl FreePokenavSubstruct
_081CFA5C:
	movs r0, 0x9
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_81CFA48

	thumb_func_start sub_81CFA68
sub_81CFA68: @ 81CFA68
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x4]
	bl IsLoopedTaskActive
	cmp r0, 0
	bne _081CFA7A
	ldr r0, =sub_81CFA88
	str r0, [r4]
_081CFA7A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFA68

	thumb_func_start sub_81CFA88
sub_81CFA88: @ 81CFA88
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CFAA0
	movs r0, 0x1
	b _081CFAFE
	.pool
_081CFAA0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CFAAC
	movs r0, 0x2
	b _081CFAFE
_081CFAAC:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CFABA
	movs r0, 0x3
	b _081CFAFE
_081CFABA:
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _081CFACA
	movs r0, 0x4
	b _081CFAFE
_081CFACA:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081CFAE0
	str r2, [r4, 0x18]
	ldr r0, =sub_81CFB08
	str r0, [r4]
	movs r0, 0x5
	b _081CFAFE
	.pool
_081CFAE0:
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081CFAEE
	movs r0, 0
	b _081CFAFE
_081CFAEE:
	bl GetSelectedMatchCall
	ldr r1, [r4, 0x1C]
	strh r0, [r1, 0x2]
	str r5, [r4, 0x18]
	ldr r0, =sub_81CFB10
	str r0, [r4]
	movs r0, 0x6
_081CFAFE:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFA88

	thumb_func_start sub_81CFB08
sub_81CFB08: @ 81CFB08
	ldr r0, =0x000186a5
	bx lr
	.pool
	thumb_func_end sub_81CFB08

	thumb_func_start sub_81CFB10
sub_81CFB10: @ 81CFB10
	ldr r0, =0x000186ad
	bx lr
	.pool
	thumb_func_end sub_81CFB10

	thumb_func_start sub_81CFB18
sub_81CFB18: @ 81CFB18
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	ldr r0, [r0, 0x14]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB18

	thumb_func_start sub_81CFB28
sub_81CFB28: @ 81CFB28
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	ldr r0, [r0, 0x1C]
	adds r0, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB28

	thumb_func_start sub_81CFB38
sub_81CFB38: @ 81CFB38
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB38

	thumb_func_start sub_81CFB48
sub_81CFB48: @ 81CFB48
	push {r4,lr}
	movs r0, 0x9
	bl GetSubstructPtr
	adds r4, r0, 0
	bl GetSelectedMatchCall
	ldr r1, [r4, 0x1C]
	lsls r0, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB48

	thumb_func_start sub_81CFB64
sub_81CFB64: @ 81CFB64
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CFB64

	thumb_func_start sub_81CFB74
sub_81CFB74: @ 81CFB74
	push {lr}
	ldr r2, =gUnknown_086235D8
	lsls r1, r0, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFB74

	thumb_func_start sub_81CFB8C
sub_81CFB8C: @ 81CFB8C
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x9
	bl GetSubstructPtr
	adds r6, r0, 0
	ldr r0, [r6, 0x1C]
	movs r1, 0
	strh r1, [r0]
	ldr r0, [r6, 0x1C]
	strh r1, [r0, 0x2]
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xE
	orrs r0, r1
	str r0, [sp]
	movs r5, 0
_081CFBB0:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CFC10
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CFC0A
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMonData
	cmp r0, 0
	bne _081CFC0A
	adds r0, r4, 0
	movs r1, 0x52
	bl GetMonData
	adds r3, r0, 0
	cmp r3, 0
	beq _081CFC0A
	lsls r1, r5, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r6, 0
	mov r1, sp
	bl sub_81CFCEC
_081CFC0A:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CFBB0
_081CFC10:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CFB8C

	thumb_func_start sub_81CFC2C
sub_81CFC2C: @ 81CFC2C
	push {lr}
	movs r0, 0x9
	bl GetSubstructPtr
	movs r1, 0
	str r1, [r0, 0x10]
	str r1, [r0, 0xC]
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_81CFC2C

	thumb_func_start sub_81CFC40
sub_81CFC40: @ 81CFC40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0x9
	bl GetSubstructPtr
	mov r8, r0
	ldr r7, [r0, 0xC]
	ldr r6, [r0, 0x10]
	movs r0, 0
	mov r9, r0
	cmp r7, 0xD
	bgt _081CFCD4
	b _081CFCC8
_081CFC60:
	adds r0, r7, 0
	adds r1, r6, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081CFCA6
	lsls r0, r7, 24
	lsrs r5, r0, 24
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x52
	bl GetBoxMonDataAt
	adds r3, r0, 0
	cmp r3, 0
	beq _081CFCA6
	ldr r1, =0xffffff00
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r5
	lsls r2, r4, 8
	ldr r1, =0xffff00ff
	ands r0, r1
	orrs r0, r2
	lsls r2, r3, 16
	ldr r1, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, r8
	mov r1, sp
	bl sub_81CFCEC
_081CFCA6:
	movs r1, 0x1
	add r9, r1
	adds r6, 0x1
	mov r0, r9
	cmp r0, 0xE
	ble _081CFCC8
	mov r1, r8
	str r7, [r1, 0xC]
	str r6, [r1, 0x10]
	movs r0, 0x3
	b _081CFCDC
	.pool
_081CFCC8:
	cmp r6, 0x1D
	ble _081CFC60
	movs r6, 0
	adds r7, 0x1
	cmp r7, 0xD
	ble _081CFCC8
_081CFCD4:
	movs r0, 0x1
	mov r1, r8
	str r0, [r1, 0x14]
	movs r0, 0x4
_081CFCDC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFC40

	thumb_func_start sub_81CFCEC
sub_81CFCEC: @ 81CFCEC
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	movs r1, 0
	ldr r0, [r5, 0x1C]
	ldrh r2, [r0]
	lsrs r3, r2, 1
	cmp r2, r3
	beq _081CFD1C
	adds r6, r0, 0
	ldrh r4, [r7, 0x2]
_081CFD02:
	lsls r0, r3, 2
	adds r0, r6, r0
	ldrh r0, [r0, 0x6]
	cmp r4, r0
	bls _081CFD10
	adds r2, r3, 0
	b _081CFD12
_081CFD10:
	adds r1, r3, 0x1
_081CFD12:
	subs r0, r2, r1
	lsrs r0, 1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CFD02
_081CFD1C:
	ldr r0, [r5, 0x1C]
	ldrh r2, [r0]
	lsls r6, r3, 2
	cmp r2, r3
	bls _081CFD40
	lsls r0, r2, 2
	subs r4, r0, 0x4
_081CFD2A:
	ldr r0, [r5, 0x1C]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r1, r0, r1
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, 0x4
	subs r2, 0x1
	cmp r2, r3
	bhi _081CFD2A
_081CFD40:
	ldr r0, [r5, 0x1C]
	adds r0, 0x4
	adds r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, 0x1C]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81CFCEC

	thumb_func_start sub_81CFD58
sub_81CFD58: @ 81CFD58
	push {r4-r6,lr}
	movs r5, 0
_081CFD5C:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _081CFD8A
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _081CFD8A
	adds r0, r4, 0
	movs r1, 0x53
	bl GetMonData
	cmp r0, 0
	bne _081CFDB2
_081CFD8A:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081CFD5C
	movs r5, 0
_081CFD92:
	movs r4, 0
	lsls r6, r5, 24
_081CFD96:
	adds r0, r5, 0
	adds r1, r4, 0
	bl CheckBoxMonSanityAt
	cmp r0, 0
	beq _081CFDBC
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r6, 24
	movs r2, 0x53
	bl GetBoxMonDataAt
	cmp r0, 0
	beq _081CFDBC
_081CFDB2:
	movs r0, 0x1
	b _081CFDCA
	.pool
_081CFDBC:
	adds r4, 0x1
	cmp r4, 0x1D
	ble _081CFD96
	adds r5, 0x1
	cmp r5, 0xD
	ble _081CFD92
	movs r0, 0
_081CFDCA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFD58

	thumb_func_start sub_81CFDD0
sub_81CFDD0: @ 81CFDD0
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0xA
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFE00
	ldr r0, =sub_81CFEB8
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r4]
	movs r0, 0
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081CFE02
	.pool
_081CFE00:
	movs r0, 0
_081CFE02:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFDD0

	thumb_func_start sub_81CFE08
sub_81CFE08: @ 81CFE08
	push {r4,lr}
	movs r1, 0x81
	lsls r1, 4
	movs r0, 0xA
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CFE38
	ldr r0, =sub_81CFEB8
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r4]
	movs r0, 0x1
	str r0, [r4, 0xC]
	b _081CFE3A
	.pool
_081CFE38:
	movs r0, 0
_081CFE3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE08

	thumb_func_start sub_81CFE40
sub_81CFE40: @ 81CFE40
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, =gUnknown_086237B8
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r5, 0x4]
	ldr r0, =sub_81CFE84
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CFE40

	thumb_func_start sub_81CFE70
sub_81CFE70: @ 81CFE70
	push {lr}
	movs r0, 0xA
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE70

	thumb_func_start sub_81CFE84
sub_81CFE84: @ 81CFE84
	push {lr}
	movs r0, 0xA
	bl GetSubstructPtr
	ldr r0, [r0, 0x4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	thumb_func_end sub_81CFE84

	thumb_func_start sub_81CFE98
sub_81CFE98: @ 81CFE98
	push {r4,lr}
	movs r0, 0xA
	bl GetSubstructPtr
	adds r4, r0, 0
	bl sub_81C8234
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0xA
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CFE98

	thumb_func_start sub_81CFEB8
sub_81CFEB8: @ 81CFEB8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0xA
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x5
	bls _081CFECC
	b _081CFFF2
_081CFECC:
	lsls r0, r4, 2
	ldr r1, =_081CFEDC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CFEDC:
	.4byte _081CFEF4
	.4byte _081CFF48
	.4byte _081CFF76
	.4byte _081CFF94
	.4byte _081CFFA4
	.4byte _081CFFDE
_081CFEF4:
	ldr r0, =gUnknown_086237B0
	movs r1, 0x2
	bl InitBgTemplates
	ldr r1, =gUnknown_08623604
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x10
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_086236CC
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_086235E4
	movs r1, 0x10
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
_081CFF32:
	movs r0, 0
	b _081CFFF4
	.pool
_081CFF48:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	bl sub_81CFB18
	cmp r0, 0
	beq _081CFFEE
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	b _081CFF32
_081CFF76:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	ldr r0, =gUnknown_08623790
	movs r1, 0x20
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	bl sub_81D0304
	b _081CFF32
	.pool
_081CFF94:
	bl sub_81C8224
	cmp r0, 0
	bne _081CFFEE
	adds r0, r5, 0
	bl sub_81D024C
	b _081CFF32
_081CFFA4:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081CFFEE
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x9
	bl sub_81C7BA4
	movs r0, 0x1
	bl sub_81C7AC0
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _081CFF32
	movs r0, 0x2
	bl LoadLeftHeaderGfxForIndex
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0
	bl sub_81C7FA0
	b _081CFF32
_081CFFDE:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081CFFEE
	bl sub_81C8010
	cmp r0, 0
	beq _081CFFF2
_081CFFEE:
	movs r0, 0x2
	b _081CFFF4
_081CFFF2:
	movs r0, 0x4
_081CFFF4:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFEB8

	thumb_func_start sub_81CFFFC
sub_81CFFFC: @ 81CFFFC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D004A
	cmp r4, 0x1
	bgt _081D0016
	cmp r4, 0
	beq _081D0020
	b _081D006A
_081D0016:
	cmp r4, 0x2
	beq _081D0052
	cmp r4, 0x3
	beq _081D005C
	b _081D006A
_081D0020:
	bl MatchCall_MoveCursorUp
	cmp r0, 0x1
	beq _081D0038
	cmp r0, 0x1
	bgt _081D0032
	cmp r0, 0
	beq _081D006A
	b _081D0058
_081D0032:
	cmp r0, 0x2
	beq _081D0042
	b _081D0058
_081D0038:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D006C
_081D0042:
	movs r0, 0x5
	bl PlaySE
	b _081D0058
_081D004A:
	bl sub_81C8630
	cmp r0, 0
	bne _081D0066
_081D0052:
	adds r0, r5, 0
	bl sub_81D0288
_081D0058:
	movs r0, 0
	b _081D006C
_081D005C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D006A
_081D0066:
	movs r0, 0x2
	b _081D006C
_081D006A:
	movs r0, 0x4
_081D006C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CFFFC

	thumb_func_start sub_81D0074
sub_81D0074: @ 81D0074
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D00C2
	cmp r4, 0x1
	bgt _081D008E
	cmp r4, 0
	beq _081D0098
	b _081D00E2
_081D008E:
	cmp r4, 0x2
	beq _081D00CA
	cmp r4, 0x3
	beq _081D00D4
	b _081D00E2
_081D0098:
	bl MatchCall_MoveCursorDown
	cmp r0, 0x1
	beq _081D00B0
	cmp r0, 0x1
	bgt _081D00AA
	cmp r0, 0
	beq _081D00E2
	b _081D00D0
_081D00AA:
	cmp r0, 0x2
	beq _081D00BA
	b _081D00D0
_081D00B0:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D00E4
_081D00BA:
	movs r0, 0x5
	bl PlaySE
	b _081D00D0
_081D00C2:
	bl sub_81C8630
	cmp r0, 0
	bne _081D00DE
_081D00CA:
	adds r0, r5, 0
	bl sub_81D0288
_081D00D0:
	movs r0, 0
	b _081D00E4
_081D00D4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D00E2
_081D00DE:
	movs r0, 0x2
	b _081D00E4
_081D00E2:
	movs r0, 0x4
_081D00E4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0074

	thumb_func_start sub_81D00EC
sub_81D00EC: @ 81D00EC
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D013A
	cmp r4, 0x1
	bgt _081D0106
	cmp r4, 0
	beq _081D0110
	b _081D015A
_081D0106:
	cmp r4, 0x2
	beq _081D0142
	cmp r4, 0x3
	beq _081D014C
	b _081D015A
_081D0110:
	bl MatchCall_PageUp
	cmp r0, 0x1
	beq _081D0128
	cmp r0, 0x1
	bgt _081D0122
	cmp r0, 0
	beq _081D015A
	b _081D0148
_081D0122:
	cmp r0, 0x2
	beq _081D0132
	b _081D0148
_081D0128:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D015C
_081D0132:
	movs r0, 0x5
	bl PlaySE
	b _081D0148
_081D013A:
	bl sub_81C8630
	cmp r0, 0
	bne _081D0156
_081D0142:
	adds r0, r5, 0
	bl sub_81D0288
_081D0148:
	movs r0, 0
	b _081D015C
_081D014C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D015A
_081D0156:
	movs r0, 0x2
	b _081D015C
_081D015A:
	movs r0, 0x4
_081D015C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D00EC

	thumb_func_start sub_81D0164
sub_81D0164: @ 81D0164
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D01B2
	cmp r4, 0x1
	bgt _081D017E
	cmp r4, 0
	beq _081D0188
	b _081D01D2
_081D017E:
	cmp r4, 0x2
	beq _081D01BA
	cmp r4, 0x3
	beq _081D01C4
	b _081D01D2
_081D0188:
	bl MatchCall_PageDown
	cmp r0, 0x1
	beq _081D01A0
	cmp r0, 0x1
	bgt _081D019A
	cmp r0, 0
	beq _081D01D2
	b _081D01C0
_081D019A:
	cmp r0, 0x2
	beq _081D01AA
	b _081D01C0
_081D01A0:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x7
	b _081D01D4
_081D01AA:
	movs r0, 0x5
	bl PlaySE
	b _081D01C0
_081D01B2:
	bl sub_81C8630
	cmp r0, 0
	bne _081D01CE
_081D01BA:
	adds r0, r5, 0
	bl sub_81D0288
_081D01C0:
	movs r0, 0
	b _081D01D4
_081D01C4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D01D2
_081D01CE:
	movs r0, 0x2
	b _081D01D4
_081D01D2:
	movs r0, 0x4
_081D01D4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0164

	thumb_func_start sub_81D01DC
sub_81D01DC: @ 81D01DC
	push {lr}
	cmp r0, 0
	beq _081D01E8
	cmp r0, 0x1
	beq _081D01FC
	b _081D0214
_081D01E8:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	bl sub_81C78A0
	movs r0, 0
	b _081D0216
_081D01FC:
	bl IsPaletteFadeActive
	cmp r0, 0
	bne _081D020C
	bl MainMenuLoopedTaskIsBusy
	cmp r0, 0
	beq _081D0210
_081D020C:
	movs r0, 0x2
	b _081D0216
_081D0210:
	bl sub_81C7FDC
_081D0214:
	movs r0, 0x4
_081D0216:
	pop {r1}
	bx r1
	thumb_func_end sub_81D01DC

	thumb_func_start sub_81D021C
sub_81D021C: @ 81D021C
	push {lr}
	cmp r0, 0
	beq _081D0228
	cmp r0, 0x1
	beq _081D0238
	b _081D0244
_081D0228:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081D0246
_081D0238:
	bl IsPaletteFadeActive
	cmp r0, 0
	beq _081D0244
	movs r0, 0x2
	b _081D0246
_081D0244:
	movs r0, 0x4
_081D0246:
	pop {r1}
	bx r1
	thumb_func_end sub_81D021C

	thumb_func_start sub_81D024C
sub_81D024C: @ 81D024C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_086237D4
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	bl sub_81CFB38
	adds r2, r0, 0
	ldrh r0, [r4, 0x8]
	movs r1, 0
	bl sub_81D02B0
	ldrb r0, [r4, 0x8]
	movs r1, 0x1
	bl CopyWindowToVram
	adds r0, r4, 0
	bl sub_81D0288
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D024C

	thumb_func_start sub_81D0288
sub_81D0288: @ 81D0288
	push {r4,r5,lr}
	adds r5, r0, 0
	bl GetSelectedMatchCall
	adds r4, r0, 0
	bl sub_81CFB38
	adds r2, r0, 0
	ldrh r0, [r5, 0x8]
	adds r4, 0x1
	adds r1, r4, 0
	bl sub_81D02B0
	ldrb r0, [r5, 0x8]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0288

	thumb_func_start sub_81D02B0
sub_81D02B0: @ 81D02B0
	push {r4,r5,lr}
	sub sp, 0x1C
	adds r4, r0, 0
	adds r5, r2, 0
	add r0, sp, 0xC
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	add sp, 0x1C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81D02B0

	thumb_func_start sub_81D0304
sub_81D0304: @ 81D0304
	push {r4,lr}
	sub sp, 0x18
	bl sub_81CFB28
	str r0, [sp]
	bl sub_81CFB38
	mov r1, sp
	movs r4, 0
	strh r0, [r1, 0x4]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	bl sub_81CFB64
	mov r1, sp
	strh r0, [r1, 0x6]
	movs r0, 0xD
	strb r0, [r1, 0x9]
	movs r0, 0x11
	strb r0, [r1, 0xA]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0xB]
	movs r0, 0x8
	strb r0, [r1, 0xC]
	movs r0, 0x2
	strb r0, [r1, 0xD]
	mov r0, sp
	strb r2, [r0, 0xE]
	ldr r0, =sub_81D035C
	str r0, [sp, 0x10]
	str r4, [sp, 0x14]
	ldr r0, =gUnknown_086237B4
	movs r2, 0
	bl sub_81C81D4
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D0304

	thumb_func_start sub_81D035C
sub_81D035C: @ 81D035C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r1, 0
	adds r7, r0, 0
	ldrb r0, [r7]
	cmp r0, 0xE
	bne _081D03A4
	ldrb r1, [r7, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMonData
	b _081D03CC
	.pool
_081D03A4:
	ldrb r0, [r7]
	ldrb r1, [r7, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gStringVar3
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBoxMonData
_081D03CC:
	ldr r4, =gStringVar3
	adds r0, r4, 0
	bl StringGetEnd10
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x3C
	bl sub_81DB494
	adds r6, r0, 0
	cmp r5, 0
	beq _081D03F8
	cmp r5, 0xFE
	beq _081D0400
	ldr r1, =gUnknown_086237F4
	b _081D0402
	.pool
_081D03F8:
	ldr r1, =gUnknown_086237DC
	b _081D0402
	.pool
_081D0400:
	ldr r1, =gUnknown_086237E8
_081D0402:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	bl StringCopy
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0xF9
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x5
	strb r1, [r0]
	adds r0, 0x1
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0x36
	bl sub_81DB494
	adds r6, r0, 0
	ldrh r1, [r7, 0x2]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D035C
        
    .align 2, 0 @ Don't pad with nop.
