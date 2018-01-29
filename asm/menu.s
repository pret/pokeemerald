	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	
	thumb_func_start sub_8199D3C
sub_8199D3C: @ 8199D3C
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, [sp, 0x14]
	adds r4, r2, 0
	muls r4, r3
	cmp r0, 0x1
	bne _08199D64
	adds r3, r6, 0
	movs r2, 0
	cmp r2, r4
	bge _08199D8C
_08199D54:
	adds r1, r3, r2
	ldrb r0, [r1]
	adds r0, r5
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, r4
	blt _08199D54
	b _08199D8C
_08199D64:
	cmp r4, 0
	ble _08199D8C
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	ldr r0, =0x000003ff
	adds r7, r0, 0
	adds r3, r6, 0
	adds r2, r4, 0
_08199D76:
	ldrh r0, [r3]
	mov r1, r12
	ands r1, r0
	adds r0, r5
	ands r0, r7
	orrs r1, r0
	strh r1, [r3]
	adds r3, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _08199D76
_08199D8C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8199D3C

	thumb_func_start sub_8199D98
sub_8199D98: @ 8199D98
	push {lr}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r0}
	bx r0
	thumb_func_end sub_8199D98

	thumb_func_start sub_8199DF0
sub_8199DF0: @ 8199DF0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r2
	mov r9, r3
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x4
	bl GetBgAttribute
	lsls r0, 16
	movs r7, 0x40
	cmp r0, 0
	bne _08199E16
	movs r7, 0x20
_08199E16:
	adds r0, r5, 0
	movs r1, 0x1
	bl GetBgAttribute
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0xA
	bl GetBgAttribute
	lsls r4, 16
	lsrs r4, 2
	lsls r0, 16
	lsrs r0, 16
	add r0, r8
	muls r0, r7
	adds r4, r0
	lsls r0, r6, 24
	lsls r1, r6, 16
	orrs r0, r1
	lsls r1, r6, 8
	orrs r0, r1
	orrs r0, r6
	movs r1, 0xC0
	lsls r1, 19
	adds r4, r1
	mov r2, r9
	muls r2, r7
	lsls r2, 16
	lsrs r2, 16
	adds r1, r4, 0
	movs r3, 0x1
	bl RequestDma3Fill
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8199DF0

	thumb_func_start box_print
box_print: @ 8199E64
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r1, 0
	ldr r6, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r1, [sp, 0x28]
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r1, [sp]
	mov r1, sp
	strb r0, [r1, 0x4]
	mov r0, sp
	strb r4, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r3, [r0, 0x7]
	ldrb r0, [r0, 0x6]
	strb r0, [r1, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	adds r0, r4, 0
	movs r1, 0x2
	bl GetFontAttribute
	mov r1, sp
	strb r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x3
	bl GetFontAttribute
	mov r1, sp
	strb r0, [r1, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	movs r1, 0x10
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	ldrb r0, [r6, 0x1]
	lsls r0, 4
	movs r4, 0xF
	strb r0, [r2, 0xC]
	ldrb r2, [r6]
	adds r0, r4, 0
	ands r0, r2
	ldrb r2, [r3, 0xD]
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	mov r2, sp
	ldrb r0, [r6, 0x2]
	lsls r0, 4
	ands r1, r4
	orrs r1, r0
	strb r1, [r2, 0xD]
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end box_print

	thumb_func_start AddTextPrinterParameterized2
@ void AddTextPrinterParameterized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, struct TextColor *color, u8 speed, u8 *str)
AddTextPrinterParameterized2: @ 8199EEC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	adds r5, r1, 0
	ldr r1, [sp, 0x28]
	mov r8, r1
	ldr r1, [sp, 0x2C]
	mov r9, r1
	ldr r6, [sp, 0x30]
	ldr r1, [sp, 0x34]
	ldr r4, [sp, 0x38]
	str r4, [sp]
	mov r4, sp
	strb r0, [r4, 0x4]
	mov r0, sp
	strb r5, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r3, [r0, 0x7]
	mov r2, sp
	ldrb r0, [r0, 0x6]
	strb r0, [r2, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x7]
	strb r0, [r2, 0x9]
	mov r0, sp
	mov r2, r8
	strb r2, [r0, 0xA]
	mov r2, r9
	strb r2, [r0, 0xB]
	ldrb r3, [r4, 0xC]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r4, 0xC]
	mov r3, sp
	ldrb r0, [r6, 0x1]
	lsls r0, 4
	movs r5, 0xF
	strb r0, [r3, 0xC]
	ldrb r3, [r6]
	adds r0, r5, 0
	ands r0, r3
	ldrb r3, [r4, 0xD]
	ands r2, r3
	orrs r2, r0
	strb r2, [r4, 0xD]
	mov r3, sp
	ldrb r0, [r6, 0x2]
	lsls r0, 4
	ands r2, r5
	orrs r2, r0
	strb r2, [r3, 0xD]
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	movs r2, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end AddTextPrinterParameterized2

	thumb_func_start sub_8199F74
sub_8199F74: @ 8199F74
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r6, r1, 0
	ldr r4, [sp, 0x2C]
	ldr r1, [sp, 0x30]
	mov r8, r1
	ldr r7, [sp, 0x34]
	ldr r5, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	mov r9, r1
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	str r2, [sp]
	mov r1, sp
	strb r0, [r1, 0x4]
	mov r0, sp
	strb r6, [r0, 0x5]
	strb r3, [r0, 0x6]
	strb r4, [r0, 0x7]
	strb r3, [r0, 0x8]
	strb r4, [r0, 0x9]
	strb r5, [r0, 0xA]
	mov r1, r9
	strb r1, [r0, 0xB]
	mov r2, sp
	ldrb r1, [r2, 0xC]
	movs r5, 0x10
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0xC]
	adds r0, r6, 0
	movs r1, 0x5
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r4, 0xF
	adds r1, r4, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	adds r0, r6, 0
	movs r1, 0x6
	bl GetFontAttribute
	mov r2, sp
	adds r1, r4, 0
	ands r1, r0
	ldrb r0, [r2, 0xD]
	ands r5, r0
	orrs r5, r1
	strb r5, [r2, 0xD]
	adds r0, r6, 0
	movs r1, 0x7
	bl GetFontAttribute
	mov r2, sp
	lsls r0, 4
	ldrb r1, [r2, 0xD]
	ands r4, r1
	orrs r4, r0
	strb r4, [r2, 0xD]
	mov r0, sp
	mov r1, r8
	adds r2, r7, 0
	bl AddTextPrinter
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8199F74

	thumb_func_start sub_819A024
sub_819A024: @ 819A024
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	movs r2, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldrb r0, [r3]
	ldr r6, =gStringVar4
	cmp r0, 0xFF
	beq _0819A04C
_0819A042:
	adds r2, 0x1
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0819A042
_0819A04C:
	adds r0, r6, 0
	bl StringExpandPlaceholders
	lsls r3, r4, 24
	lsrs r3, 24
	lsls r0, r5, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819A024

	thumb_func_start sub_819A080
sub_819A080: @ 819A080
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [sp, 0x48]
	ldr r4, [sp, 0x4C]
	ldr r1, [sp, 0x50]
	ldr r5, [sp, 0x54]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x8]
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	lsls r4, 16
	lsrs r4, 16
	lsls r1, 16
	lsrs r1, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r2, [sp, 0x4]
	ldrh r0, [r2, 0x4]
	ldr r2, [sp, 0xC]
	subs r0, r2
	ldr r2, [sp, 0x8]
	adds r2, r1, r2
	str r2, [sp, 0x10]
	cmp r0, r1
	bge _0819A0CC
	ldr r1, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x10]
_0819A0CC:
	ldr r2, [sp, 0x4]
	ldrh r1, [r2, 0x6]
	subs r0, r1, r4
	cmp r0, r5
	bge _0819A0DE
	adds r0, r3, r1
	subs r0, r4
	str r0, [sp, 0x14]
	b _0819A0E2
_0819A0DE:
	adds r5, r3, r5
	str r5, [sp, 0x14]
_0819A0E2:
	ldr r0, [sp]
	ldrh r1, [r0, 0x4]
	movs r2, 0x7
	adds r0, r1, 0
	ands r0, r2
	adds r1, r0
	asrs r1, 3
	str r1, [sp, 0x18]
	ldr r0, [sp, 0x4]
	ldrh r1, [r0, 0x4]
	adds r0, r1, 0
	ands r0, r2
	adds r1, r0
	asrs r1, 3
	str r1, [sp, 0x1C]
	mov r12, r3
	mov r8, r4
	ldr r1, [sp, 0x14]
	cmp r12, r1
	blt _0819A10C
	b _0819A24A
_0819A10C:
	ldr r5, [sp, 0x8]
	ldr r6, [sp, 0xC]
	mov r2, r12
	adds r2, 0x1
	str r2, [sp, 0x20]
	mov r0, r8
	adds r0, 0x1
	str r0, [sp, 0x24]
	ldr r1, [sp, 0x10]
	cmp r5, r1
	blt _0819A124
	b _0819A23A
_0819A124:
	movs r7, 0x1
	movs r2, 0xF0
	mov r10, r2
	movs r0, 0xF
	mov r9, r0
_0819A12E:
	asrs r0, r5, 1
	movs r1, 0x3
	ands r0, r1
	ldr r2, [sp]
	ldr r1, [r2]
	adds r1, r0
	asrs r0, r5, 3
	lsls r0, 5
	adds r1, r0
	mov r2, r12
	asrs r0, r2, 3
	ldr r2, [sp, 0x18]
	muls r0, r2
	lsls r0, 5
	adds r1, r0
	mov r2, r12
	lsls r0, r2, 29
	lsrs r0, 27
	adds r3, r1, r0
	asrs r0, r6, 1
	movs r1, 0x3
	ands r0, r1
	ldr r2, [sp, 0x4]
	ldr r1, [r2]
	adds r1, r0
	asrs r0, r6, 3
	lsls r0, 5
	adds r1, r0
	mov r2, r8
	asrs r0, r2, 3
	ldr r2, [sp, 0x1C]
	muls r0, r2
	lsls r0, 5
	adds r1, r0
	mov r2, r8
	lsls r0, r2, 29
	lsrs r0, 27
	adds r4, r1, r0
	adds r0, r4, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A1DA
	subs r4, 0x1
	adds r0, r6, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A1B2
	ldrh r0, [r4]
	ldr r2, =0x00000fff
	ands r2, r0
	adds r0, r5, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A1A8
	ldrb r1, [r3]
	mov r0, r10
	ands r0, r1
	lsls r0, 8
	b _0819A22A
	.pool
_0819A1A8:
	ldrb r1, [r3]
	mov r0, r9
	ands r0, r1
	lsls r0, 12
	b _0819A22A
_0819A1B2:
	ldrh r0, [r4]
	ldr r2, =0x0000f0ff
	ands r2, r0
	adds r0, r5, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A1D0
	ldrb r1, [r3]
	mov r0, r10
	ands r0, r1
	lsls r0, 4
	b _0819A22A
	.pool
_0819A1D0:
	ldrb r1, [r3]
	mov r0, r9
	ands r0, r1
	lsls r0, 8
	b _0819A22A
_0819A1DA:
	adds r0, r6, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A206
	ldrh r0, [r4]
	ldr r2, =0x0000ff0f
	ands r2, r0
	adds r0, r5, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A1FC
	ldrb r1, [r3]
	mov r0, r10
	b _0819A228
	.pool
_0819A1FC:
	ldrb r1, [r3]
	mov r0, r9
	ands r0, r1
	lsls r0, 4
	b _0819A22A
_0819A206:
	ldrh r0, [r4]
	ldr r2, =0x0000fff0
	ands r2, r0
	adds r0, r5, 0
	ands r0, r7
	cmp r0, 0
	beq _0819A224
	ldrb r1, [r3]
	mov r0, r10
	ands r0, r1
	lsrs r0, 4
	b _0819A22A
	.pool
_0819A224:
	ldrb r1, [r3]
	mov r0, r9
_0819A228:
	ands r0, r1
_0819A22A:
	orrs r2, r0
	strh r2, [r4]
	adds r5, 0x1
	adds r6, 0x1
	ldr r0, [sp, 0x10]
	cmp r5, r0
	bge _0819A23A
	b _0819A12E
_0819A23A:
	ldr r1, [sp, 0x20]
	mov r12, r1
	ldr r2, [sp, 0x24]
	mov r8, r2
	ldr r0, [sp, 0x14]
	cmp r12, r0
	bge _0819A24A
	b _0819A10C
_0819A24A:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_819A080

	thumb_func_start sub_819A25C
sub_819A25C: @ 819A25C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, 16
	lsrs r0, 16
	bl GetValidMonIconPalettePtr
	adds r1, r4, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_819A25C

	thumb_func_start sub_819A27C
sub_819A27C: @ 819A27C
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r4, r3, 0
	ldr r5, [sp, 0x18]
	lsls r6, 24
	lsrs r6, 24
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	movs r2, 0x1
	bl GetMonIconPtr
	adds r1, r0, 0
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl BlitBitmapToWindow
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_819A27C

	thumb_func_start sub_819A2BC
sub_819A2BC: @ 819A2BC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _0819A2DC
	cmp r1, 0x1
	ble _0819A2D2
	cmp r1, 0x2
	beq _0819A2E4
_0819A2D2:
	ldr r0, =gFireRedMenuElements1_Pal
	b _0819A2E6
	.pool
_0819A2DC:
	ldr r0, =gFireRedMenuElements2_Pal
	b _0819A2E6
	.pool
_0819A2E4:
	ldr r0, =gFireRedMenuElements3_Pal
_0819A2E6:
	adds r1, r2, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819A2BC

	thumb_func_start blit_move_info_icon
@ void blit_move_info_icon(u8 windowId, u8 a2, u16 x, u16 y)
blit_move_info_icon: @ 819A2F8
	push {r4,r5,lr}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r4, =gUnknown_0860F0D4
	lsrs r1, 22
	adds r1, r4
	ldrh r5, [r1, 0x2]
	lsls r5, 5
	ldr r4, =gFireRedMenuElements_Gfx
	adds r5, r4
	movs r4, 0x80
	str r4, [sp]
	str r4, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	ldrb r2, [r1]
	str r2, [sp, 0x10]
	ldrb r1, [r1, 0x1]
	str r1, [sp, 0x14]
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end blit_move_info_icon

	thumb_func_start sub_819A344
sub_819A344: @ 819A344
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r2, 24
	lsrs r2, 24
	adds r5, r1, 0
	movs r1, 0xFC
	strb r1, [r5]
	adds r5, 0x1
	movs r0, 0x1
	strb r0, [r5]
	adds r5, 0x1
	strb r2, [r5]
	adds r5, 0x1
	strb r1, [r5]
	adds r5, 0x1
	movs r0, 0x3
	strb r0, [r5]
	adds r5, 0x1
	adds r2, 0x1
	strb r2, [r5]
	adds r5, 0x1
	cmp r3, 0x4
	bhi _0819A43C
	lsls r0, r3, 2
	ldr r1, =_0819A384
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0819A384:
	.4byte _0819A398
	.4byte _0819A3A8
	.4byte _0819A3D6
	.4byte _0819A404
	.4byte _0819A414
_0819A398:
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy
	b _0819A43C
	.pool
_0819A3A8:
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _0819A3B8
	movs r0, 0x1
	bl pokedex_count
	b _0819A3BE
_0819A3B8:
	movs r0, 0x1
	bl sub_80C0844
_0819A3BE:
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	movs r0, 0xFF
	strb r0, [r5]
	b _0819A43C
_0819A3D6:
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	ldrh r1, [r0, 0xE]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	movs r0, 0xF0
	strb r0, [r5]
	adds r5, 0x1
	ldr r0, [r4]
	ldrb r1, [r0, 0x10]
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	b _0819A43C
	.pool
_0819A404:
	ldr r0, =gMapHeader
	ldrb r1, [r0, 0x14]
	adds r0, r5, 0
	bl sub_81245DC
	b _0819A43C
	.pool
_0819A414:
	ldr r4, =0x00000867
	movs r6, 0
	adds r7, r5, 0x1
_0819A41A:
	lsls r0, r4, 16
	lsrs r0, 16
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0819A42A
	adds r6, 0x1
_0819A42A:
	adds r4, 0x1
	ldr r0, =0x0000086e
	cmp r4, r0
	ble _0819A41A
	adds r0, r6, 0
	subs r0, 0x5F
	strb r0, [r5]
	movs r0, 0xFF
	strb r0, [r7]
_0819A43C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819A344

	thumb_func_start sub_819A44C
sub_819A44C: @ 819A44C
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrb r4, [r5, 0x5]
	lsrs r4, 4
	movs r0, 0x65
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsls r4, 16
	lsrs r4, 16
	lsrs r0, 24
	cmp r4, r0
	bne _0819A4BA
	adds r0, r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0819A4B0
	ldrh r1, [r5, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _0819A484
	subs r0, r1, 0x1
	strh r0, [r5, 0x2E]
	b _0819A4C2
_0819A484:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _0819A4A6
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAnim
	movs r0, 0x20
	strh r0, [r5, 0x2E]
	b _0819A4C2
_0819A4A6:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
	b _0819A4C2
_0819A4B0:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnimIfDifferent
	b _0819A4C2
_0819A4BA:
	adds r0, r5, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
_0819A4C2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_819A44C

	.align 2, 0 @ Don't pad with nop.
