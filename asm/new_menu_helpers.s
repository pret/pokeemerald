	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8197184
sub_8197184: @ 8197184
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0860EA6C
	movs r2, 0x80
	lsls r2, 1
	lsls r4, 16
	lsrs r4, 16
	adds r3, r4, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_0860EA4C
	lsls r5, 20
	lsrs r5, 16
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197184

	thumb_func_start sub_81971C4
sub_81971C4: @ 81971C4
	push {lr}
	bl sub_819645C
	pop {r0}
	bx r0
	thumb_func_end sub_81971C4

	thumb_func_start sub_81971D0
sub_81971D0: @ 81971D0
	push {lr}
	ldr r0, =gUnknown_0860F098
	bl InitWindows
	ldr r0, =gUnknown_0203CD8C
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, =gUnknown_0203CD8D
	strb r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81971D0

	thumb_func_start sub_81971F4
sub_81971F4: @ 81971F4
	push {lr}
	bl FreeAllWindowBuffers
	pop {r0}
	bx r0
	thumb_func_end sub_81971F4

	thumb_func_start sub_8197200
sub_8197200: @ 8197200
	push {lr}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	bl DeactivateAllTextPrinters
	bl sub_81973A4
	pop {r0}
	bx r0
	thumb_func_end sub_8197200

	thumb_func_start sub_8197224
sub_8197224: @ 8197224
	push {lr}
	bl RunTextPrinters
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8197224

	thumb_func_start AddTextPrinterParametrized
@ u16 AddTextPrinterParametrized(u8 windowId, u8 fontId, u8 *str, u8 speed, void ( *callback)(u16, struct TextPrinter *), u8 fgColor, u8 bgColor, u8 shadowColor)
AddTextPrinterParametrized: @ 8197238
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r7, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	mov r8, r4
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	lsls r3, 24
	lsrs r3, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	str r2, [sp]
	mov r2, sp
	movs r4, 0
	strb r0, [r2, 0x4]
	mov r0, sp
	strb r1, [r0, 0x5]
	strb r4, [r0, 0x6]
	movs r1, 0x1
	strb r1, [r0, 0x7]
	strb r4, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r4, [r0, 0xA]
	strb r4, [r0, 0xB]
	mov r4, sp
	ldrb r2, [r4, 0xC]
	subs r1, 0x11
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4, 0xC]
	mov r0, sp
	mov r2, r8
	lsls r2, 4
	movs r4, 0xF
	strb r2, [r0, 0xC]
	mov r2, sp
	ands r5, r4
	ldrb r0, [r2, 0xD]
	ands r1, r0
	orrs r1, r5
	strb r1, [r2, 0xD]
	mov r0, sp
	lsrs r6, 20
	ands r1, r4
	orrs r1, r6
	strb r1, [r0, 0xD]
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	adds r1, r3, 0
	adds r2, r7, 0
	bl AddTextPrinter
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddTextPrinterParametrized

	thumb_func_start AddTextPrinterForMessage
@ void AddTextPrinterForMessage(u8 allowSkippingDelayWithButtonPress)
AddTextPrinterForMessage: @ 81972C4
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	movs r5, 0
	ldr r3, =gTextFlags
	movs r4, 0x1
	ands r0, r4
	ldrb r2, [r3]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	bl sav2_get_text_speed
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r2, =gStringVar4
	str r5, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParametrized
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddTextPrinterForMessage

	thumb_func_start AddTextPrinterForMessage_2
@ void AddTextPrinterForMessage_2(u8 allowSkippingDelayWithButtonPress)
AddTextPrinterForMessage_2: @ 8197310
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTextFlags
	movs r4, 0x1
	ands r0, r4
	ldrb r2, [r3]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	bl sav2_get_text_speed
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r2, =gStringVar4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParametrized
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddTextPrinterForMessage_2

	thumb_func_start AddTextPrinterWithCustomSpeedForMessage
@ void AddTextPrinterWithCustomSpeedForMessage(u8 allowSkippingDelayWithButtonPress, u8 speed)
AddTextPrinterWithCustomSpeedForMessage: @ 819735C
	push {r4,r5,lr}
	sub sp, 0x10
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r4, =gTextFlags
	movs r5, 0x1
	ands r0, r5
	ldrb r2, [r4]
	movs r1, 0x2
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r4]
	ldr r2, =gStringVar4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	bl AddTextPrinterParametrized
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AddTextPrinterWithCustomSpeedForMessage

	thumb_func_start sub_81973A4
sub_81973A4: @ 81973A4
	push {lr}
	movs r1, 0x80
	lsls r1, 2
	movs r0, 0
	movs r2, 0xF0
	bl copy_textbox_border_tile_patterns_to_vram
	movs r1, 0x85
	lsls r1, 2
	movs r0, 0
	movs r2, 0xE0
	bl sub_809882C
	pop {r0}
	bx r0
	thumb_func_end sub_81973A4

	thumb_func_start sub_81973C4
sub_81973C4: @ 81973C4
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_81975F4
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _081973F2
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_081973F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81973C4

	thumb_func_start sub_81973FC
sub_81973FC: @ 81973FC
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_81974A4
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _0819742A
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0819742A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81973FC

	thumb_func_start sub_8197434
sub_8197434: @ 8197434
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_8197804
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl ClearWindowTilemap
	cmp r4, 0x1
	bne _08197462
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08197462:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197434

	thumb_func_start sub_819746C
sub_819746C: @ 819746C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_81977BC
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl ClearWindowTilemap
	cmp r4, 0x1
	bne _0819749A
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0819749A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819746C

	thumb_func_start sub_81974A4
sub_81974A4: @ 81974A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r4, r2, 0
	ldr r2, [sp, 0x3C]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsls r4, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x10]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	movs r3, 0x85
	lsls r3, 2
	lsrs r0, r1, 24
	str r0, [sp, 0xC]
	movs r2, 0xFF
	lsls r2, 24
	adds r2, r1
	mov r8, r2
	lsrs r2, 24
	lsrs r0, r4, 24
	mov r9, r0
	movs r0, 0xFF
	lsls r0, 24
	adds r4, r0
	lsrs r4, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r6, 0xE
	str r6, [sp, 0x8]
	adds r0, r7, 0
	adds r1, r3, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000215
	ldr r2, [sp, 0x10]
	str r2, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0xC]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000216
	ldr r3, [sp, 0xC]
	ldr r2, [sp, 0x10]
	adds r0, r3, r2
	lsls r0, 24
	mov r10, r0
	lsrs r2, r0, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r7, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	mov r5, r9
	ldr r0, [sp, 0x14]
	add r0, r9
	cmp r9, r0
	bge _08197578
	mov r3, r8
	str r3, [sp, 0x18]
	movs r6, 0x1
	movs r0, 0xE
	mov r8, r0
_0819753E:
	lsls r4, r5, 24
	lsrs r4, 24
	str r6, [sp]
	str r6, [sp, 0x4]
	mov r2, r8
	str r2, [sp, 0x8]
	adds r0, r7, 0
	ldr r1, =0x00000217
	ldr r3, [sp, 0x18]
	lsrs r2, r3, 24
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r6, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	adds r0, r7, 0
	ldr r1, =0x00000219
	mov r3, r10
	lsrs r2, r3, 24
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	adds r5, 0x1
	ldr r0, [sp, 0x14]
	add r0, r9
	cmp r5, r0
	blt _0819753E
_08197578:
	ldr r1, =0x0000021a
	ldr r2, [sp, 0xC]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r4, [sp, 0x14]
	add r4, r9
	lsls r4, 24
	lsrs r4, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r6, 0xE
	str r6, [sp, 0x8]
	adds r0, r7, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000021b
	ldr r0, [sp, 0x10]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r7, 0
	ldr r2, [sp, 0xC]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	movs r1, 0x87
	lsls r1, 2
	ldr r3, [sp, 0xC]
	ldr r0, [sp, 0x10]
	adds r2, r3, r0
	lsls r2, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r7, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81974A4

	thumb_func_start sub_81975F4
sub_81975F4: @ 81975F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	adds r6, r0, 0
	adds r5, r2, 0
	mov r8, r3
	ldr r2, [sp, 0x44]
	lsls r6, 24
	lsrs r6, 24
	lsls r0, r1, 24
	lsls r5, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r1, r2, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	ldr r1, =0x00000201
	lsrs r2, r0, 24
	str r2, [sp, 0xC]
	movs r3, 0xFE
	lsls r3, 24
	adds r2, r0, r3
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsrs r0, r5, 24
	mov r10, r0
	movs r2, 0xFF
	lsls r2, 24
	adds r5, r2
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r3, 0xF
	mov r9, r3
	str r3, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0x14]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000203
	ldr r0, [sp, 0xC]
	subs r0, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r6, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	movs r1, 0x81
	lsls r1, 2
	mov r0, r8
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0xC]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000205
	ldr r7, [sp, 0xC]
	add r7, r8
	subs r0, r7, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x20]
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	adds r0, r6, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000206
	lsls r2, r7, 24
	lsrs r7, r2, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r6, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000207
	str r4, [sp]
	movs r5, 0x5
	str r5, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000209
	add r8, r4
	mov r3, r8
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	str r5, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x0000020a
	str r4, [sp]
	str r5, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r6, 0
	adds r2, r7, 0
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000a01
	ldr r3, [sp, 0x10]
	add r10, r3
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0x14]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000a03
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000a04
	ldr r0, [sp, 0x1C]
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0xC]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000a05
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r3, r9
	str r3, [sp, 0x8]
	adds r0, r6, 0
	ldr r2, [sp, 0x20]
	mov r3, r10
	bl FillBgTilemapBufferRect
	ldr r1, =0x00000a06
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r6, 0
	adds r2, r7, 0
	mov r3, r10
	bl FillBgTilemapBufferRect
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81975F4

	thumb_func_start sub_81977BC
sub_81977BC: @ 81977BC
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r1, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsls r5, 24
	lsls r3, 24
	lsls r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r4, r2
	lsrs r4, 24
	adds r5, r2
	lsrs r5, 24
	movs r2, 0x80
	lsls r2, 18
	adds r3, r2
	lsrs r3, 24
	str r3, [sp]
	adds r1, r2
	lsrs r1, 24
	str r1, [sp, 0x4]
	movs r1, 0xE
	str r1, [sp, 0x8]
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81977BC

	thumb_func_start sub_8197804
sub_8197804: @ 8197804
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r1, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsls r5, 24
	lsls r3, 24
	lsls r1, 24
	movs r2, 0xFD
	lsls r2, 24
	adds r4, r2
	lsrs r4, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r5, r2
	lsrs r5, 24
	movs r2, 0xC0
	lsls r2, 19
	adds r3, r2
	lsrs r3, 24
	str r3, [sp]
	movs r2, 0x80
	lsls r2, 18
	adds r1, r2
	lsrs r1, 24
	str r1, [sp, 0x4]
	movs r1, 0xE
	str r1, [sp, 0x8]
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8197804

	thumb_func_start SetStandardWindowBorderStyle
@ void SetStandardWindowBorderStyle(u8 windowId, bool copyToVram)
SetStandardWindowBorderStyle: @ 8197854
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0x85
	lsls r2, 2
	movs r3, 0xE
	bl SetWindowBorderStyle
	pop {r0}
	bx r0
	thumb_func_end SetStandardWindowBorderStyle

	thumb_func_start sub_819786C
sub_819786C: @ 819786C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r6, 0x80
	lsls r6, 2
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xF0
	bl copy_textbox_border_tile_patterns_to_vram
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0xF
	bl sub_8197B1C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_819786C

	thumb_func_start sub_819789C
sub_819789C: @ 819789C
	push {lr}
	ldr r0, =gUnknown_0860F074
	movs r1, 0xE0
	movs r2, 0x14
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_819789C

	thumb_func_start sub_81978B0
sub_81978B0: @ 81978B0
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gUnknown_0860F074
	movs r2, 0x14
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81978B0

	thumb_func_start sub_81978C8
sub_81978C8: @ 81978C8
	ldr r0, =gUnknown_0860F074
	bx lr
	.pool
	thumb_func_end sub_81978C8

	thumb_func_start sub_81978D0
sub_81978D0: @ 81978D0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _081978DC
	movs r1, 0
_081978DC:
	ldr r0, =gUnknown_0860F074
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81978D0

	thumb_func_start DisplayItemMessageOnField
@ void DisplayItemMessageOnField(u8 taskId, u8 *str, void ( *callback)(u8 taskId))
DisplayItemMessageOnField: @ 81978EC
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81973A4
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 2
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0xF
	bl DisplayMessageAndContinueTask
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end DisplayItemMessageOnField

	thumb_func_start sub_8197930
sub_8197930: @ 8197930
	push {lr}
	ldr r0, =gUnknown_0860F0A8
	movs r1, 0x85
	lsls r1, 2
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197930

	thumb_func_start sub_8197948
sub_8197948: @ 8197948
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0860F0A8
	movs r1, 0x85
	lsls r1, 2
	movs r2, 0xE
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197948

	thumb_func_start sub_8197964
sub_8197964: @ 8197964
	push {lr}
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08197988
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsls r0, 29
	lsrs r0, 29
	b _0819798A
	.pool
_08197988:
	movs r0, 0x1
_0819798A:
	pop {r1}
	bx r1
	thumb_func_end sub_8197964

	thumb_func_start sav2_get_text_speed
sav2_get_text_speed: @ 8197990
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrb r1, [r2, 0x14]
	lsls r0, r1, 29
	lsrs r0, 29
	cmp r0, 0x2
	bls _081979AC
	movs r0, 0x8
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x14]
_081979AC:
	bl sub_8197964
	ldr r1, =gUnknown_0860F094
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sav2_get_text_speed

	thumb_func_start sub_81979C4
sub_81979C4: @ 81979C4
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r4, =gUnknown_0203CD8C
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081979F6
	lsls r0, r1, 25
	movs r1, 0x80
	lsls r1, 18
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	ldr r0, =0x00000139
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x1
	movs r3, 0x7
	bl sub_8198AA4
	strb r0, [r4]
_081979F6:
	ldrb r0, [r4]
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81979C4

	thumb_func_start GetStartMenuWindowId
GetStartMenuWindowId: @ 8197A08
	ldr r0, =gUnknown_0203CD8C
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetStartMenuWindowId

	thumb_func_start remove_start_menu_window_maybe
remove_start_menu_window_maybe: @ 8197A14
	push {r4,lr}
	ldr r4, =gUnknown_0203CD8C
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08197A26
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
_08197A26:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end remove_start_menu_window_maybe

	thumb_func_start sub_8197A30
sub_8197A30: @ 8197A30
	movs r0, 0x80
	lsls r0, 2
	bx lr
	thumb_func_end sub_8197A30

	thumb_func_start sub_8197A38
sub_8197A38: @ 8197A38
	movs r0, 0x85
	lsls r0, 2
	bx lr
	thumb_func_end sub_8197A38

	thumb_func_start AddMapNamePopUpWindow
AddMapNamePopUpWindow: @ 8197A40
	push {r4,lr}
	sub sp, 0xC
	ldr r4, =gUnknown_0203CD8D
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _08197A66
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	adds r0, 0xF9
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0xA
	bl sub_8198AA4
	strb r0, [r4]
_08197A66:
	ldrb r0, [r4]
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddMapNamePopUpWindow

	thumb_func_start GetMapNamePopUpWindowId
GetMapNamePopUpWindowId: @ 8197A74
	ldr r0, =gUnknown_0203CD8D
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetMapNamePopUpWindowId

	thumb_func_start RemoveMapNamePopUpWindow
RemoveMapNamePopUpWindow: @ 8197A80
	push {r4,lr}
	ldr r4, =gUnknown_0203CD8D
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08197A92
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
_08197A92:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveMapNamePopUpWindow

	.align 2, 0 @ Don't pad with nop.
