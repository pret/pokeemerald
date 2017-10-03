	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AddTextPrinterWithCallbackForMessage
@ void AddTextPrinterWithCallbackForMessage(u8 allowSkippingDelayWithButtonPress, void ( *callback)(u16, struct TextPrinter *))
AddTextPrinterWithCallbackForMessage: @ 8197A9C
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r1, 0
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
	thumb_func_end AddTextPrinterWithCallbackForMessage

	thumb_func_start sub_8197AE8
sub_8197AE8: @ 8197AE8
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	cmp r4, 0x1
	bne _08197B12
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_08197B12:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8197AE8

	thumb_func_start sub_8197B1C
sub_8197B1C: @ 8197B1C
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CD9C
	strh r2, [r0]
	ldr r0, =gUnknown_0203CD9E
	strb r3, [r0]
	ldr r1, =sub_8197BB4
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _08197B52
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08197B52:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197B1C

	thumb_func_start sub_8197B64
sub_8197B64: @ 8197B64
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CD9C
	strh r2, [r0]
	ldr r5, =gUnknown_0203CD9E
	adds r0, r6, 0
	movs r1, 0x5
	bl GetWindowAttribute
	strb r0, [r5]
	ldr r1, =sub_8197BB4
	adds r0, r6, 0
	bl CallWindowFunction
	adds r0, r6, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r6, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _08197BA2
	adds r0, r6, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08197BA2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197B64

	thumb_func_start sub_8197BB4
sub_8197BB4: @ 8197BB4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	mov r8, r0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r2, [sp, 0x44]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, r1, 24
	lsls r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r1, r2, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	ldr r2, =gUnknown_0203CD9C
	ldrh r1, [r2]
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	lsrs r3, r0, 24
	str r3, [sp, 0xC]
	movs r3, 0xFE
	lsls r3, 24
	adds r2, r0, r3
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsrs r0, r5, 24
	mov r9, r0
	movs r2, 0xFF
	lsls r2, 24
	adds r5, r2
	lsrs r5, 24
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r3, =gUnknown_0203CD9E
	mov r10, r3
	ldrb r0, [r3]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r0, =gUnknown_0203CD9C
	ldrh r1, [r0]
	adds r1, 0x3
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0xC]
	subs r0, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r3, =gUnknown_0203CD9C
	ldrh r1, [r3]
	adds r1, 0x4
	lsls r1, 16
	lsrs r1, 16
	subs r0, r6, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0xC]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r3, =gUnknown_0203CD9C
	ldrh r1, [r3]
	adds r1, 0x5
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0xC]
	adds r7, r0, r6
	subs r0, r7, 0x1
	lsls r2, r0, 24
	lsrs r2, 24
	str r2, [sp, 0x20]
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x20]
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r3, =gUnknown_0203CD9C
	ldrh r1, [r3]
	adds r1, 0x6
	lsls r1, 16
	lsrs r1, 16
	lsls r2, r7, 24
	lsrs r7, r2, 24
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	ldr r3, =gUnknown_0203CD9C
	ldrh r1, [r3]
	adds r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	str r4, [sp]
	movs r5, 0x5
	str r5, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	mov r3, r9
	bl FillBgTilemapBufferRect
	ldr r3, =gUnknown_0203CD9C
	ldrh r1, [r3]
	adds r1, 0x9
	lsls r1, 16
	lsrs r1, 16
	adds r6, 0x1
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp]
	str r5, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	mov r3, r9
	bl FillBgTilemapBufferRect
	ldr r3, =gUnknown_0203CD9C
	ldrh r1, [r3]
	adds r1, 0xA
	lsls r1, 16
	lsrs r1, 16
	str r4, [sp]
	str r5, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	mov r3, r9
	bl FillBgTilemapBufferRect
	ldr r3, =0x00000801
	adds r1, r3, 0
	ldr r0, =gUnknown_0203CD9C
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x10]
	add r9, r2
	mov r3, r9
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x14]
	bl FillBgTilemapBufferRect
	ldr r3, =0x00000803
	adds r1, r3, 0
	ldr r0, =gUnknown_0203CD9C
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	ldrb r0, [r2]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x18]
	mov r3, r9
	bl FillBgTilemapBufferRect
	ldr r3, =0x00000804
	adds r1, r3, 0
	ldr r0, =gUnknown_0203CD9C
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x1C]
	str r2, [sp]
	str r4, [sp, 0x4]
	mov r3, r10
	ldrb r0, [r3]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0xC]
	mov r3, r9
	bl FillBgTilemapBufferRect
	ldr r0, =0x00000805
	adds r1, r0, 0
	ldr r2, =gUnknown_0203CD9C
	ldrh r2, [r2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r3, r10
	ldrb r0, [r3]
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r2, [sp, 0x20]
	mov r3, r9
	bl FillBgTilemapBufferRect
	ldr r0, =0x00000806
	adds r1, r0, 0
	ldr r2, =gUnknown_0203CD9C
	ldrh r2, [r2]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r3, r10
	ldrb r0, [r3]
	str r0, [sp, 0x8]
	mov r0, r8
	adds r2, r7, 0
	mov r3, r9
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
	thumb_func_end sub_8197BB4

	thumb_func_start sub_8197DF8
sub_8197DF8: @ 8197DF8
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_8197E30
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl ClearWindowTilemap
	cmp r4, 0x1
	bne _08197E26
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08197E26:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197DF8

	thumb_func_start sub_8197E30
sub_8197E30: @ 8197E30
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
	movs r1, 0
	str r1, [sp, 0x8]
	adds r2, r4, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8197E30

	thumb_func_start SetWindowBorderStyle
@ void SetWindowBorderStyle(u8 windowId, bool copyToVram, s16 tileStart, s8 palette)
SetWindowBorderStyle: @ 8197E80
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CD9C
	strh r2, [r0]
	ldr r0, =gUnknown_0203CD9E
	strb r3, [r0]
	ldr r1, =DrawWindowBorder
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _08197EB6
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08197EB6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWindowBorderStyle

	thumb_func_start sub_8197EC8
sub_8197EC8: @ 8197EC8
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CD9C
	strh r2, [r0]
	ldr r5, =gUnknown_0203CD9E
	adds r0, r6, 0
	movs r1, 0x5
	bl GetWindowAttribute
	strb r0, [r5]
	ldr r1, =DrawWindowBorder
	adds r0, r6, 0
	bl CallWindowFunction
	adds r0, r6, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r6, 0
	bl PutWindowTilemap
	cmp r4, 0x1
	bne _08197F06
	adds r0, r6, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08197F06:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8197EC8

	thumb_func_start DrawWindowBorder
DrawWindowBorder: @ 8197F18
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r9, r0
	adds r6, r1, 0
	adds r4, r2, 0
	ldr r0, [sp, 0x38]
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r6, 24
	lsls r4, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x10]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	ldr r2, =gUnknown_0203CD9C
	ldrh r1, [r2]
	lsrs r0, r6, 24
	str r0, [sp, 0xC]
	movs r2, 0xFF
	lsls r2, 24
	adds r6, r2
	lsrs r6, 24
	lsrs r0, r4, 24
	mov r8, r0
	adds r4, r2
	lsrs r4, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	ldr r7, =gUnknown_0203CD9E
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r2, =gUnknown_0203CD9C
	ldrh r1, [r2]
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x10]
	str r0, [sp]
	str r5, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	ldr r2, [sp, 0xC]
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r2, =gUnknown_0203CD9C
	ldrh r1, [r2]
	adds r1, 0x2
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0xC]
	ldr r2, [sp, 0x10]
	adds r0, r2
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	str r5, [sp]
	str r5, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	mov r2, r10
	adds r3, r4, 0
	bl FillBgTilemapBufferRect
	ldr r0, =gUnknown_0203CD9C
	ldrh r1, [r0]
	adds r1, 0x3
	lsls r1, 16
	lsrs r1, 16
	str r5, [sp]
	ldr r2, [sp, 0x14]
	str r2, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	adds r2, r6, 0
	mov r3, r8
	bl FillBgTilemapBufferRect
	ldr r0, =gUnknown_0203CD9C
	ldrh r1, [r0]
	adds r1, 0x5
	lsls r1, 16
	lsrs r1, 16
	str r5, [sp]
	ldr r2, [sp, 0x14]
	str r2, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	mov r2, r10
	mov r3, r8
	bl FillBgTilemapBufferRect
	ldr r0, =gUnknown_0203CD9C
	ldrh r1, [r0]
	adds r1, 0x6
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x14]
	add r8, r2
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	str r5, [sp]
	str r5, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	adds r2, r6, 0
	mov r3, r8
	bl FillBgTilemapBufferRect
	ldr r2, =gUnknown_0203CD9C
	ldrh r1, [r2]
	adds r1, 0x7
	lsls r1, 16
	lsrs r1, 16
	ldr r0, [sp, 0x10]
	str r0, [sp]
	str r5, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	ldr r2, [sp, 0xC]
	mov r3, r8
	bl FillBgTilemapBufferRect
	ldr r2, =gUnknown_0203CD9C
	ldrh r1, [r2]
	adds r1, 0x8
	lsls r1, 16
	lsrs r1, 16
	str r5, [sp]
	str r5, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0x8]
	mov r0, r9
	mov r2, r10
	mov r3, r8
	bl FillBgTilemapBufferRect
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawWindowBorder

	thumb_func_start sub_8198070
sub_8198070: @ 8198070
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =sub_81980A8
	adds r0, r5, 0
	bl CallWindowFunction
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r5, 0
	bl ClearWindowTilemap
	cmp r4, 0x1
	bne _0819809E
	adds r0, r5, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0819809E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8198070

	thumb_func_start sub_81980A8
sub_81980A8: @ 81980A8
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
	movs r1, 0
	str r1, [sp, 0x8]
	adds r2, r4, 0
	adds r3, r5, 0
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81980A8

	thumb_func_start sub_81980F0
sub_81980F0: @ 81980F0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, [sp, 0x20]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r4, 16
	lsrs r4, 16
	mov r0, sp
	movs r1, 0
	movs r2, 0x8
	bl memset
	cmp r6, 0x3
	bls _08198126
	movs r1, 0
	mov r0, sp
	strb r1, [r0]
	b _0819812A
_08198126:
	mov r0, sp
	strb r6, [r0]
_0819812A:
	mov r1, sp
	mov r0, r8
	strb r0, [r1, 0x2]
	movs r0, 0x2
	strb r0, [r1, 0x4]
	movs r0, 0x1E
	subs r0, r7
	strb r0, [r1, 0x1]
	strb r7, [r1, 0x3]
	strb r5, [r1, 0x5]
	strh r4, [r1, 0x6]
	ldr r4, =gUnknown_0203CDA0
	mov r0, sp
	bl AddWindow
	strb r0, [r4]
	cmp r5, 0xF
	bls _08198158
	movs r5, 0xF0
	b _0819815C
	.pool
_08198158:
	lsls r0, r5, 28
	lsrs r5, r0, 24
_0819815C:
	ldr r0, =gUnknown_0860F0B0
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0203CDA0
	ldrb r0, [r0]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81980F0

	thumb_func_start sub_8198180
sub_8198180: @ 8198180
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r6, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r5, =gUnknown_0203CDA0
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _081981EE
	bl PutWindowTilemap
	ldrb r0, [r5]
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	movs r1, 0x1
	bl GetWindowAttribute
	movs r2, 0xEC
	subs r2, r7
	lsls r0, 3
	subs r2, r0
	subs r2, r4
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r5]
	ldr r1, =gUnknown_0860F0D0
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r3, 0x1
	bl box_print
	mov r0, r8
	cmp r0, 0
	beq _081981EE
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
_081981EE:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8198180

	thumb_func_start sub_8198204
sub_8198204: @ 8198204
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	adds r6, r1, 0
	ldr r0, [sp, 0x38]
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r4, 0
	ldr r0, =gUnknown_0203CDA0
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0xFF
	beq _081982C8
	cmp r2, 0
	beq _08198244
	add r0, sp, 0x14
	strb r4, [r0]
	adds r1, r0, 0
	b _0819824A
	.pool
_08198244:
	add r1, sp, 0x14
	movs r0, 0xF
	strb r0, [r1]
_0819824A:
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	adds r5, r7, 0
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r5]
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	cmp r6, 0
	beq _0819829E
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	bl GetStringWidth
	lsls r0, 16
	lsrs r4, r0, 16
	ldrb r0, [r5]
	movs r1, 0x1
	bl GetWindowAttribute
	movs r2, 0xEC
	mov r1, r8
	subs r2, r1
	lsls r0, 3
	subs r2, r0
	subs r2, r4
	lsls r2, 24
	lsrs r2, 24
	ldrb r0, [r5]
	add r1, sp, 0x14
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r3, 0x1
	bl box_print
_0819829E:
	ldrb r0, [r7]
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	add r2, sp, 0x14
	str r2, [sp, 0x8]
	str r1, [sp, 0xC]
	mov r1, r10
	str r1, [sp, 0x10]
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0x1
	bl AddTextPrinterParametrized2
	mov r2, r9
	cmp r2, 0
	beq _081982C8
	ldrb r0, [r7]
	movs r1, 0x3
	bl CopyWindowToVram
_081982C8:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8198204

	thumb_func_start sub_81982D8
sub_81982D8: @ 81982D8
	push {lr}
	ldr r1, =gUnknown_0203CDA0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081982E8
	movs r1, 0x3
	bl CopyWindowToVram
_081982E8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81982D8

	thumb_func_start sub_81982F0
sub_81982F0: @ 81982F0
	push {r4,lr}
	ldr r4, =gUnknown_0203CDA0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08198308
	movs r1, 0xFF
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
_08198308:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81982F0

	thumb_func_start sub_8198314
sub_8198314: @ 8198314
	push {r4,lr}
	ldr r4, =gUnknown_0203CDA0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _0819833C
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
_0819833C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8198314

	thumb_func_start sub_8198348
sub_8198348: @ 8198348
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, 0x18]
	mov r8, r4
	ldr r4, [sp, 0x1C]
	ldr r5, [sp, 0x20]
	ldr r6, [sp, 0x24]
	mov r12, r6
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r7, r5, 24
	ldr r5, =gUnknown_0203CD90
	movs r6, 0
	strb r2, [r5]
	strb r3, [r5, 0x1]
	strb r6, [r5, 0x3]
	subs r4, 0x1
	strb r4, [r5, 0x4]
	strb r0, [r5, 0x5]
	strb r1, [r5, 0x6]
	mov r0, r8
	strb r0, [r5, 0x8]
	mov r4, r12
	strb r4, [r5, 0xB]
	cmp r7, 0
	blt _08198388
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	cmp r7, r0
	ble _08198390
_08198388:
	strb r6, [r5, 0x2]
	b _08198392
	.pool
_08198390:
	strb r7, [r5, 0x2]
_08198392:
	movs r0, 0
	bl MoveMenuCursor
	ldr r0, =gUnknown_0203CD90
	ldrb r0, [r0, 0x2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8198348

	thumb_func_start sub_81983AC
sub_81983AC: @ 81983AC
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r4, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r6, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r4, 0
	str r4, [sp, 0xC]
	bl sub_8198348
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81983AC

	thumb_func_start sub_81983EC
sub_81983EC: @ 81983EC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	adds r6, r1, 0
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r6, 24
	lsrs r6, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0x1
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	mov r0, r8
	adds r1, r6, 0
	ldr r2, [sp, 0xC]
	ldr r3, [sp, 0x10]
	bl sub_81983AC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81983EC

	thumb_func_start RedrawMenuCursor
@ void RedrawMenuCursor(s8 oldPos, s8 newPos)
RedrawMenuCursor: @ 8198448
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r1
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r5, =gUnknown_0203CD90
	ldrb r0, [r5, 0x6]
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5, 0x6]
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r5, 0x5]
	mov r9, r1
	ldrb r2, [r5]
	ldrb r1, [r5, 0x8]
	adds r3, r1, 0
	muls r3, r6
	ldrb r6, [r5, 0x1]
	adds r3, r6
	lsls r3, 16
	lsrs r3, 16
	str r4, [sp]
	str r0, [sp, 0x4]
	mov r0, r9
	movs r1, 0x11
	bl FillWindowPixelRect
	ldrb r0, [r5, 0x5]
	ldrb r1, [r5, 0x6]
	ldr r2, =gText_SelectorArrow3
	ldrb r3, [r5]
	ldrb r4, [r5, 0x8]
	mov r6, r8
	muls r6, r4
	adds r4, r6, 0
	ldrb r5, [r5, 0x1]
	adds r4, r5
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RedrawMenuCursor

	thumb_func_start MoveMenuCursor
@ s8 MoveMenuCursor(s8 cursorDelta)
MoveMenuCursor: @ 81984D8
	push {r4,r5,lr}
	ldr r1, =gUnknown_0203CD90
	ldrb r5, [r1, 0x2]
	movs r2, 0x2
	ldrsb r2, [r1, r2]
	lsls r0, 24
	asrs r3, r0, 24
	adds r2, r3
	movs r0, 0x3
	ldrsb r0, [r1, r0]
	adds r4, r1, 0
	cmp r2, r0
	bge _081984FC
	ldrb r0, [r4, 0x4]
	b _0819850A
	.pool
_081984FC:
	movs r0, 0x4
	ldrsb r0, [r4, r0]
	cmp r2, r0
	ble _08198508
	ldrb r0, [r4, 0x3]
	b _0819850A
_08198508:
	adds r0, r3, r5
_0819850A:
	strb r0, [r4, 0x2]
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl RedrawMenuCursor
	ldrb r0, [r4, 0x2]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end MoveMenuCursor

	thumb_func_start MoveMenuCursorNoWrapAround
@ s8 MoveMenuCursorNoWrapAround(s8 cursorDelta)
MoveMenuCursorNoWrapAround: @ 819851C
	push {r4,r5,lr}
	ldr r1, =gUnknown_0203CD90
	ldrb r5, [r1, 0x2]
	movs r2, 0x2
	ldrsb r2, [r1, r2]
	lsls r0, 24
	asrs r3, r0, 24
	adds r2, r3
	movs r0, 0x3
	ldrsb r0, [r1, r0]
	adds r4, r1, 0
	cmp r2, r0
	bge _08198540
	ldrb r0, [r4, 0x3]
	b _0819854E
	.pool
_08198540:
	movs r0, 0x4
	ldrsb r0, [r4, r0]
	cmp r2, r0
	ble _0819854C
	ldrb r0, [r4, 0x4]
	b _0819854E
_0819854C:
	adds r0, r3, r5
_0819854E:
	strb r0, [r4, 0x2]
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl RedrawMenuCursor
	ldrb r0, [r4, 0x2]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end MoveMenuCursorNoWrapAround

	thumb_func_start GetMenuCursorPos
GetMenuCursorPos: @ 8198560
	ldr r0, =gUnknown_0203CD90
	ldrb r0, [r0, 0x2]
	bx lr
	.pool
	thumb_func_end GetMenuCursorPos

	thumb_func_start ProcessMenuInput
ProcessMenuInput: @ 819856C
	push {r4,lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08198598
	ldr r4, =gUnknown_0203CD90
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _08198588
	movs r0, 0x5
	bl PlaySE
_08198588:
	movs r0, 0x2
	ldrsb r0, [r4, r0]
	b _081985D2
	.pool
_08198598:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081985A6
	movs r0, 0x1
	negs r0, r0
	b _081985D2
_081985A6:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081985BA
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _081985CA
_081985BA:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081985CE
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_081985CA:
	bl MoveMenuCursor
_081985CE:
	movs r0, 0x2
	negs r0, r0
_081985D2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ProcessMenuInput

	thumb_func_start ProcessMenuInputNoWrapAround
@ int ProcessMenuInputNoWrapAround()
ProcessMenuInputNoWrapAround: @ 81985D8
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203CD90
	ldrb r5, [r4, 0x2]
	adds r6, r5, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08198608
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _081985F8
	movs r0, 0x5
	bl PlaySE
_081985F8:
	movs r0, 0x2
	ldrsb r0, [r4, r0]
	b _08198650
	.pool
_08198608:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08198616
	movs r0, 0x1
	negs r0, r0
	b _08198650
_08198616:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08198630
	movs r0, 0x1
	negs r0, r0
	bl MoveMenuCursorNoWrapAround
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _0819864C
	b _08198646
_08198630:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0819864C
	movs r0, 0x1
	bl MoveMenuCursorNoWrapAround
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	beq _0819864C
_08198646:
	movs r0, 0x5
	bl PlaySE
_0819864C:
	movs r0, 0x2
	negs r0, r0
_08198650:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ProcessMenuInputNoWrapAround

	thumb_func_start ProcessMenuInput_other
ProcessMenuInput_other: @ 8198658
	push {r4,lr}
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08198684
	ldr r4, =gUnknown_0203CD90
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _08198674
	movs r0, 0x5
	bl PlaySE
_08198674:
	movs r0, 0x2
	ldrsb r0, [r4, r0]
	b _081986BC
	.pool
_08198684:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08198692
	movs r0, 0x1
	negs r0, r0
	b _081986BC
_08198692:
	ldrh r0, [r2, 0x30]
	movs r1, 0xF0
	ands r1, r0
	cmp r1, 0x40
	bne _081986A8
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _081986B4
_081986A8:
	cmp r1, 0x80
	bne _081986B8
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_081986B4:
	bl MoveMenuCursor
_081986B8:
	movs r0, 0x2
	negs r0, r0
_081986BC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ProcessMenuInput_other

	thumb_func_start ProcessMenuInputNoWrapAround_other
ProcessMenuInputNoWrapAround_other: @ 81986C4
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203CD90
	ldrb r5, [r4, 0x2]
	adds r6, r5, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081986F4
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _081986E4
	movs r0, 0x5
	bl PlaySE
_081986E4:
	movs r0, 0x2
	ldrsb r0, [r4, r0]
	b _0819873A
	.pool
_081986F4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08198702
	movs r0, 0x1
	negs r0, r0
	b _0819873A
_08198702:
	ldrh r0, [r2, 0x30]
	movs r1, 0xF0
	ands r1, r0
	cmp r1, 0x40
	bne _0819871E
	movs r0, 0x1
	negs r0, r0
	bl MoveMenuCursorNoWrapAround
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _08198736
	b _08198730
_0819871E:
	cmp r1, 0x80
	bne _08198736
	movs r0, 0x1
	bl MoveMenuCursorNoWrapAround
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	beq _08198736
_08198730:
	movs r0, 0x5
	bl PlaySE
_08198736:
	movs r0, 0x2
	negs r0, r0
_0819873A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ProcessMenuInputNoWrapAround_other

	thumb_func_start PrintTextArray
PrintTextArray: @ 8198740
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r4, 24
	lsrs r7, r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r4, 0
	cmp r4, r5
	bcs _081987A4
_08198774:
	lsls r0, r4, 3
	ldr r1, [sp, 0x34]
	adds r0, r1
	ldr r2, [r0]
	adds r0, r7, 0
	muls r0, r4
	add r0, r8
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	mov r1, r10
	mov r3, r9
	bl PrintTextOnWindow
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08198774
_081987A4:
	adds r0, r6, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PrintTextArray

	thumb_func_start sub_81987BC
sub_81987BC: @ 81987BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x40]
	ldr r5, [sp, 0x44]
	ldr r6, [sp, 0x4C]
	ldr r7, [sp, 0x50]
	mov r8, r7
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x14]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x1C]
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r9, r6
	mov r0, r8
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _0819883C
_08198804:
	lsls r0, r4, 3
	ldr r1, [sp, 0x48]
	adds r0, r1
	ldr r2, [r0]
	mov r0, r10
	muls r0, r4
	ldr r1, [sp, 0x1C]
	adds r0, r1, r0
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	adds r0, r7, 0
	ldr r1, [sp, 0x14]
	ldr r3, [sp, 0x18]
	bl sub_8199F74
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08198804
_0819883C:
	adds r0, r7, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81987BC

	thumb_func_start sub_8198854
sub_8198854: @ 8198854
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	mov r8, r0
	adds r6, r1, 0
	adds r4, r2, 0
	adds r5, r3, 0
	ldr r7, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r7, [sp, 0x8]
	mov r0, r8
	adds r1, r6, 0
	movs r3, 0x1
	bl PrintTextArray
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8198854

	thumb_func_start AddItemMenuActionTextPrinters
AddItemMenuActionTextPrinters: @ 81988A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r1, 0
	mov r8, r2
	ldr r1, [sp, 0x38]
	mov r9, r1
	ldr r1, [sp, 0x3C]
	ldr r2, [sp, 0x40]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r6, 24
	lsrs r6, 24
	mov r4, r8
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r7, r2, 24
	mov r0, sp
	ldrb r1, [r0, 0x10]
	strb r1, [r0, 0x4]
	strb r6, [r0, 0x5]
	adds r0, r6, 0
	movs r1, 0x5
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r5, 0xF
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	adds r0, r6, 0
	movs r1, 0x6
	bl GetFontAttribute
	mov r3, sp
	adds r1, r5, 0
	ands r1, r0
	ldrb r2, [r3, 0xD]
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xD]
	adds r0, r6, 0
	movs r1, 0x7
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xD]
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	adds r0, r6, 0
	movs r1, 0x4
	bl GetFontAttribute
	mov r1, sp
	ands r5, r0
	ldrb r0, [r1, 0xC]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0xC]
	mov r0, sp
	mov r2, r9
	strb r2, [r0, 0xA]
	adds r0, r6, 0
	movs r1, 0x3
	bl GetFontAttribute
	mov r1, sp
	strb r0, [r1, 0xB]
	mov r0, sp
	mov r4, r8
	strb r4, [r0, 0x6]
	strb r4, [r0, 0x8]
	movs r4, 0
	cmp r4, r7
	bcs _0819899E
	mov r5, sp
_0819896E:
	ldr r1, [sp, 0x48]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, 3
	ldr r2, [sp, 0x44]
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	mov r0, r10
	muls r0, r4
	ldr r1, [sp, 0x14]
	adds r0, r1, r0
	strb r0, [r5, 0x7]
	strb r0, [r5, 0x9]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r7
	bcc _0819896E
_0819899E:
	ldr r0, [sp, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end AddItemMenuActionTextPrinters

	thumb_func_start sub_81989B8
sub_81989B8: @ 81989B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r9, r0
	adds r4, r1, 0
	adds r6, r2, 0
	mov r8, r3
	ldr r7, [sp, 0x30]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0
	bl GetFontAttribute
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	movs r1, 0x2
	bl GetFontAttribute
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	str r6, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	ldr r0, [sp, 0x34]
	str r0, [sp, 0x10]
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl AddItemMenuActionTextPrinters
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81989B8

	thumb_func_start SetWindowTemplateFields
@ void SetWindowTemplateFields(WindowTemplate *template, char bg_id, char x, char y, char w, char h, char a7, s16 a8)
SetWindowTemplateFields: @ 8198A24
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, 0x18]
	ldr r5, [sp, 0x1C]
	ldr r6, [sp, 0x20]
	ldr r7, [sp, 0x24]
	mov r8, r7
	strb r1, [r0]
	strb r2, [r0, 0x1]
	strb r3, [r0, 0x2]
	strb r4, [r0, 0x3]
	strb r5, [r0, 0x4]
	strb r6, [r0, 0x5]
	mov r1, r8
	strh r1, [r0, 0x6]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SetWindowTemplateFields

	thumb_func_start sub_8198A50
sub_8198A50: @ 8198A50
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x18
	mov r8, r0
	ldr r0, [sp, 0x2C]
	ldr r4, [sp, 0x30]
	ldr r5, [sp, 0x34]
	ldr r6, [sp, 0x38]
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 16
	lsrs r6, 16
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	add r0, sp, 0x10
	bl SetWindowTemplateFields
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	mov r2, r8
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r0, r8
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r2}
	bx r2
	thumb_func_end sub_8198A50

	thumb_func_start sub_8198AA4
sub_8198AA4: @ 8198AA4
	push {r4-r6,lr}
	sub sp, 0x18
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, [sp, 0x28]
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	str r3, [sp]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	add r0, sp, 0x10
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl SetWindowTemplateFields
	add r0, sp, 0x10
	bl AddWindow
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x18
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8198AA4

	thumb_func_start sub_8198AF8
sub_8198AF8: @ 8198AF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r6, r1, 0
	mov r8, r2
	mov r9, r3
	ldr r4, [sp, 0x3C]
	ldr r5, [sp, 0x40]
	ldr r1, [sp, 0x44]
	mov r10, r1
	lsls r6, 24
	lsrs r6, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	mov r1, r10
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	ldr r7, =gUnknown_0203CD9F
	bl AddWindow
	strb r0, [r7]
	ldrb r0, [r7]
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl SetWindowBorderStyle
	ldr r0, =gText_YesNo
	str r0, [sp, 0xC]
	add r1, sp, 0xC
	ldrb r0, [r7]
	strb r0, [r1, 0x4]
	adds r0, r1, 0
	strb r6, [r0, 0x5]
	adds r0, r6, 0
	movs r1, 0
	bl GetFontAttribute
	add r1, sp, 0xC
	add r0, r8
	strb r0, [r1, 0x6]
	adds r0, r1, 0
	mov r1, r9
	strb r1, [r0, 0x7]
	adds r1, r0, 0
	ldrb r0, [r0, 0x6]
	strb r0, [r1, 0x8]
	adds r0, r1, 0
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	adds r0, r6, 0
	movs r1, 0x5
	bl GetFontAttribute
	add r3, sp, 0xC
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r5, 0xF
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	adds r0, r6, 0
	movs r1, 0x6
	bl GetFontAttribute
	add r3, sp, 0xC
	adds r1, r5, 0
	ands r1, r0
	ldrb r2, [r3, 0xD]
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xD]
	adds r0, r6, 0
	movs r1, 0x7
	bl GetFontAttribute
	add r3, sp, 0xC
	lsls r0, 4
	ldrb r2, [r3, 0xD]
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	adds r0, r6, 0
	movs r1, 0x4
	bl GetFontAttribute
	add r1, sp, 0xC
	ands r5, r0
	ldrb r0, [r1, 0xC]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0xC]
	adds r0, r6, 0
	movs r1, 0x2
	bl GetFontAttribute
	add r1, sp, 0xC
	strb r0, [r1, 0xA]
	adds r0, r6, 0
	movs r1, 0x3
	bl GetFontAttribute
	add r1, sp, 0xC
	strb r0, [r1, 0xB]
	adds r0, r1, 0
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	adds r0, r6, 0
	movs r1, 0x1
	bl GetFontAttribute
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r7]
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	mov r0, r10
	str r0, [sp, 0x8]
	adds r0, r1, 0
	adds r1, r6, 0
	mov r2, r8
	mov r3, r9
	bl sub_81983AC
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8198AF8

	thumb_func_start sub_8198C34
sub_8198C34: @ 8198C34
	push {lr}
	sub sp, 0xC
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 24
	lsrs r3, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	movs r3, 0x1
	bl sub_8198AF8
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_8198C34

	thumb_func_start sub_8198C58
sub_8198C58: @ 8198C58
	push {r4,lr}
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _08198C6E
	bl sub_8198C78
_08198C6E:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8198C58

	thumb_func_start sub_8198C78
sub_8198C78: @ 8198C78
	push {r4,lr}
	ldr r4, =gUnknown_0203CD9F
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_8198070
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8198C78

	thumb_func_start sub_8198C94
sub_8198C94: @ 8198C94
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x40]
	ldr r5, [sp, 0x44]
	ldr r6, [sp, 0x48]
	ldr r7, [sp, 0x4C]
	mov r8, r7
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x10]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x18]
	lsls r5, 24
	lsrs r5, 24
	str r5, [sp, 0x1C]
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	cmp r5, r9
	bcs _08198D3A
_08198CE0:
	movs r4, 0
	adds r1, r5, 0x1
	mov r8, r1
	cmp r4, r6
	bcs _08198D30
	ldr r7, [sp, 0x1C]
	adds r0, r7, 0
	muls r0, r5
	ldr r1, [sp, 0x14]
	adds r0, r1, r0
	lsls r0, 24
	lsrs r7, r0, 24
_08198CF8:
	adds r0, r5, 0
	muls r0, r6
	adds r0, r4
	lsls r0, 3
	ldr r1, [sp, 0x50]
	adds r0, r1
	ldr r2, [r0]
	ldr r0, [sp, 0x18]
	adds r3, r0, 0
	muls r3, r4
	ldr r1, [sp, 0x10]
	adds r3, r1, r3
	lsls r3, 24
	lsrs r3, 24
	str r7, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r0, r10
	ldr r1, [sp, 0xC]
	bl PrintTextOnWindow
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _08198CF8
_08198D30:
	mov r7, r8
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, r9
	bcc _08198CE0
_08198D3A:
	mov r0, r10
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8198C94

	thumb_func_start sub_8198D54
sub_8198D54: @ 8198D54
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	mov r9, r0
	mov r8, r1
	adds r4, r2, 0
	adds r5, r3, 0
	ldr r6, [sp, 0x34]
	ldr r3, [sp, 0x38]
	ldr r7, [sp, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0
	str r3, [sp, 0x14]
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	ldr r3, [sp, 0x14]
	str r3, [sp, 0xC]
	str r7, [sp, 0x10]
	mov r0, r9
	mov r1, r8
	movs r3, 0
	bl sub_8198C94
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8198D54

	thumb_func_start sub_8198DBC
sub_8198DBC: @ 8198DBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x40]
	ldr r5, [sp, 0x44]
	ldr r6, [sp, 0x48]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x14]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x1C]
	lsls r5, 24
	lsrs r5, 24
	mov r8, r5
	lsls r6, 24
	lsrs r6, 24
	mov r10, r6
	mov r0, sp
	ldrb r1, [r0, 0x10]
	strb r1, [r0, 0x4]
	strb r7, [r0, 0x5]
	adds r0, r7, 0
	movs r1, 0x5
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r5, 0xF
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	adds r0, r7, 0
	movs r1, 0x6
	bl GetFontAttribute
	mov r3, sp
	adds r1, r5, 0
	ands r1, r0
	ldrb r2, [r3, 0xD]
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xD]
	adds r0, r7, 0
	movs r1, 0x7
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xD]
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	adds r0, r7, 0
	movs r1, 0x4
	bl GetFontAttribute
	mov r1, sp
	ands r5, r0
	ldrb r0, [r1, 0xC]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0xC]
	adds r0, r7, 0
	movs r1, 0x2
	bl GetFontAttribute
	mov r1, sp
	strb r0, [r1, 0xA]
	adds r0, r7, 0
	movs r1, 0x3
	bl GetFontAttribute
	mov r1, sp
	strb r0, [r1, 0xB]
	movs r6, 0
	cmp r6, r10
	bcs _08198EDE
_08198E7A:
	movs r5, 0
	adds r2, r6, 0x1
	mov r9, r2
	cmp r5, r8
	bcs _08198ED4
	mov r4, sp
_08198E86:
	mov r0, r8
	muls r0, r6
	adds r0, r5
	ldr r1, [sp, 0x50]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 3
	ldr r2, [sp, 0x4C]
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r1, [sp, 0x1C]
	adds r0, r1, 0
	muls r0, r5
	ldr r2, [sp, 0x14]
	adds r0, r2, r0
	strb r0, [r4, 0x6]
	adds r0, r7, 0
	movs r1, 0x1
	bl GetFontAttribute
	adds r1, r6, 0
	muls r1, r0
	ldr r0, [sp, 0x18]
	adds r1, r0, r1
	strb r1, [r4, 0x7]
	ldrb r0, [r4, 0x6]
	strb r0, [r4, 0x8]
	strb r1, [r4, 0x9]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r8
	bcc _08198E86
_08198ED4:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, r10
	bcc _08198E7A
_08198EDE:
	ldr r0, [sp, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8198DBC

	thumb_func_start sub_8198EF8
sub_8198EF8: @ 8198EF8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r8, r0
	adds r3, r1, 0
	adds r4, r2, 0
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r7, [sp, 0x38]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	adds r0, r3, 0
	movs r1, 0
	str r3, [sp, 0x14]
	bl GetFontAttribute
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	ldr r0, [sp, 0x3C]
	str r0, [sp, 0x10]
	mov r0, r8
	ldr r3, [sp, 0x14]
	adds r1, r3, 0
	movs r3, 0
	bl sub_8198DBC
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8198EF8

	thumb_func_start sub_8198F58
sub_8198F58: @ 8198F58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, [sp, 0x20]
	mov r12, r4
	ldr r4, [sp, 0x24]
	mov r8, r4
	ldr r4, [sp, 0x28]
	mov r9, r4
	ldr r4, [sp, 0x2C]
	mov r10, r4
	ldr r4, [sp, 0x30]
	ldr r5, [sp, 0x34]
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r7, r5, 24
	ldr r5, =gUnknown_0203CD90
	movs r6, 0
	strb r2, [r5]
	strb r3, [r5, 0x1]
	strb r6, [r5, 0x3]
	subs r4, 0x1
	strb r4, [r5, 0x4]
	strb r0, [r5, 0x5]
	strb r1, [r5, 0x6]
	mov r0, r12
	strb r0, [r5, 0x7]
	mov r4, r8
	strb r4, [r5, 0x8]
	mov r0, r9
	strb r0, [r5, 0x9]
	mov r4, r10
	strb r4, [r5, 0xA]
	cmp r7, 0
	blt _08198FAC
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	cmp r7, r0
	ble _08198FB4
_08198FAC:
	strb r6, [r5, 0x2]
	b _08198FB6
	.pool
_08198FB4:
	strb r7, [r5, 0x2]
_08198FB6:
	movs r0, 0
	movs r1, 0
	bl sub_8199134
	ldr r0, =gUnknown_0203CD90
	ldrb r0, [r0, 0x2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8198F58

	thumb_func_start sub_8198FD4
sub_8198FD4: @ 8198FD4
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x20
	mov r9, r0
	mov r8, r1
	mov r10, r2
	ldr r6, [sp, 0x3C]
	ldr r4, [sp, 0x40]
	ldr r5, [sp, 0x44]
	ldr r2, [sp, 0x48]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r3, 24
	lsrs r3, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r2, 24
	lsrs r2, 24
	mov r0, r8
	movs r1, 0x1
	str r2, [sp, 0x18]
	str r3, [sp, 0x1C]
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	muls r1, r5
	lsls r1, 24
	lsrs r1, 24
	str r6, [sp]
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	str r1, [sp, 0x10]
	ldr r2, [sp, 0x18]
	str r2, [sp, 0x14]
	mov r0, r9
	mov r1, r8
	mov r2, r10
	ldr r3, [sp, 0x1C]
	bl sub_8198F58
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8198FD4

	thumb_func_start sub_8199060
sub_8199060: @ 8199060
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, r1, 24
	lsrs r7, r0, 24
	ldr r5, =gUnknown_0203CD90
	ldrb r0, [r5, 0x6]
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	mov r9, r0
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	ldrb r0, [r5, 0x6]
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldrb r0, [r5, 0x9]
	mov r10, r0
	mov r0, r8
	mov r1, r10
	bl __umodsi3
	ldrb r1, [r5, 0x7]
	adds r4, r1, 0
	muls r4, r0
	ldrb r1, [r5]
	adds r4, r1
	lsls r4, 24
	lsrs r4, 24
	mov r0, r8
	mov r1, r10
	bl __udivsi3
	ldrb r1, [r5, 0x8]
	adds r3, r1, 0
	muls r3, r0
	ldrb r0, [r5, 0x1]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r5, 0x5]
	mov r1, r9
	str r1, [sp]
	str r6, [sp, 0x4]
	movs r1, 0x11
	adds r2, r4, 0
	bl FillWindowPixelRect
	ldrb r6, [r5, 0x9]
	adds r0, r7, 0
	adds r1, r6, 0
	bl __umodsi3
	ldrb r1, [r5, 0x7]
	adds r4, r1, 0
	muls r4, r0
	ldrb r0, [r5]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	adds r1, r6, 0
	bl __udivsi3
	ldrb r1, [r5, 0x8]
	adds r3, r1, 0
	muls r3, r0
	ldrb r1, [r5, 0x1]
	adds r3, r1
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r5, 0x5]
	ldrb r1, [r5, 0x6]
	ldr r2, =gText_SelectorArrow3
	str r3, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	str r3, [sp, 0x8]
	adds r3, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8199060

	thumb_func_start sub_8199134
sub_8199134: @ 8199134
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	ldr r1, =gUnknown_0203CD90
	ldrb r2, [r1, 0x2]
	mov r8, r2
	lsls r0, 24
	asrs r6, r0, 24
	adds r5, r1, 0
	cmp r6, 0
	beq _0819918A
	movs r7, 0x2
	ldrsb r7, [r5, r7]
	ldrb r4, [r5, 0x9]
	adds r0, r7, 0
	adds r1, r4, 0
	bl __modsi3
	adds r0, r6
	cmp r0, 0
	bge _08199174
	adds r0, r4, 0
	adds r0, 0xFF
	add r0, r8
	b _08199188
	.pool
_08199174:
	cmp r0, r4
	blt _08199184
	adds r0, r7, 0
	adds r1, r4, 0
	bl __divsi3
	muls r0, r4
	b _08199188
_08199184:
	mov r1, r8
	adds r0, r6, r1
_08199188:
	strb r0, [r5, 0x2]
_0819918A:
	mov r2, r9
	lsls r0, r2, 24
	asrs r6, r0, 24
	cmp r6, 0
	beq _081991CE
	movs r0, 0x2
	ldrsb r0, [r5, r0]
	ldrb r4, [r5, 0x9]
	adds r1, r4, 0
	bl __divsi3
	adds r1, r0, r6
	cmp r1, 0
	bge _081991B2
	ldrb r0, [r5, 0xA]
	subs r0, 0x1
	muls r0, r4
	ldrb r1, [r5, 0x2]
	adds r0, r1
	b _081991CC
_081991B2:
	ldrb r0, [r5, 0xA]
	cmp r1, r0
	blt _081991C4
	subs r0, 0x1
	adds r1, r4, 0
	muls r1, r0
	ldrb r0, [r5, 0x2]
	subs r0, r1
	b _081991CC
_081991C4:
	adds r0, r4, 0
	muls r0, r6
	ldrb r2, [r5, 0x2]
	adds r0, r2
_081991CC:
	strb r0, [r5, 0x2]
_081991CE:
	movs r1, 0x2
	ldrsb r1, [r5, r1]
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bgt _081991E4
	ldrb r1, [r5, 0x2]
	mov r0, r8
	bl sub_8199060
	b _081991E8
_081991E4:
	mov r0, r8
	strb r0, [r5, 0x2]
_081991E8:
	ldrb r0, [r5, 0x2]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8199134

	thumb_func_start sub_81991F8
sub_81991F8: @ 81991F8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r1, =gUnknown_0203CD90
	ldrb r7, [r1, 0x2]
	lsls r0, 24
	asrs r4, r0, 24
	adds r5, r1, 0
	cmp r4, 0
	beq _0819922C
	movs r0, 0x2
	ldrsb r0, [r5, r0]
	ldrb r6, [r5, 0x9]
	adds r1, r6, 0
	bl __modsi3
	adds r0, r4
	cmp r0, 0
	blt _0819922C
	cmp r0, r6
	bge _0819922C
	adds r0, r4, r7
	strb r0, [r5, 0x2]
_0819922C:
	mov r1, r8
	lsls r0, r1, 24
	asrs r4, r0, 24
	cmp r4, 0
	beq _08199258
	movs r0, 0x2
	ldrsb r0, [r5, r0]
	ldrb r6, [r5, 0x9]
	adds r1, r6, 0
	bl __divsi3
	adds r0, r4
	cmp r0, 0
	blt _08199258
	ldrb r1, [r5, 0xA]
	cmp r0, r1
	bge _08199258
	adds r0, r6, 0
	muls r0, r4
	ldrb r1, [r5, 0x2]
	adds r0, r1
	strb r0, [r5, 0x2]
_08199258:
	movs r1, 0x2
	ldrsb r1, [r5, r1]
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bgt _08199274
	ldrb r1, [r5, 0x2]
	adds r0, r7, 0
	bl sub_8199060
	b _08199276
	.pool
_08199274:
	strb r7, [r5, 0x2]
_08199276:
	ldrb r0, [r5, 0x2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81991F8

	thumb_func_start sub_8199284
sub_8199284: @ 8199284
	push {r4,lr}
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081992AC
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203CD90
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	b _0819932C
	.pool
_081992AC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081992BA
	movs r0, 0x1
	negs r0, r0
	b _0819932C
_081992BA:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081992D0
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	b _08199324
_081992D0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081992E4
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	movs r1, 0x1
	b _08199324
_081992E4:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081992F8
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08199304
_081992F8:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _08199322
_08199304:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0819931A
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08199328
_0819931A:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_08199322:
	movs r1, 0
_08199324:
	bl sub_8199134
_08199328:
	movs r0, 0x2
	negs r0, r0
_0819932C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8199284

	thumb_func_start sub_8199334
sub_8199334: @ 8199334
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203CD90
	ldrb r4, [r5, 0x2]
	ldr r6, =gMain
	ldrh r1, [r6, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0819935C
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x2
	ldrsb r0, [r5, r0]
	b _081993D2
	.pool
_0819935C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0819936A
	movs r0, 0x1
	negs r0, r0
	b _081993D2
_0819936A:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0819937A
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	b _081993BC
_0819937A:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08199388
	movs r0, 0
	movs r1, 0x1
	b _081993BC
_08199388:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0819939C
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081993A2
_0819939C:
	movs r0, 0x1
	negs r0, r0
	b _081993BA
_081993A2:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081993B8
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081993CE
_081993B8:
	movs r0, 0x1
_081993BA:
	movs r1, 0
_081993BC:
	bl sub_81991F8
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _081993CE
	movs r0, 0x5
	bl PlaySE
_081993CE:
	movs r0, 0x2
	negs r0, r0
_081993D2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8199334

	thumb_func_start sub_81993D8
sub_81993D8: @ 81993D8
	push {r4,r5,lr}
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08199400
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203CD90
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	b _0819947C
	.pool
_08199400:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0819940E
	movs r0, 0x1
	negs r0, r0
	b _0819947C
_0819940E:
	ldrh r0, [r4, 0x30]
	movs r5, 0xF0
	adds r1, r5, 0
	ands r1, r0
	cmp r1, 0x40
	bne _08199428
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	b _08199474
_08199428:
	cmp r1, 0x80
	bne _08199438
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	movs r1, 0x1
	b _08199474
_08199438:
	cmp r1, 0x20
	beq _08199448
	bl sub_812210C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08199454
_08199448:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _08199472
_08199454:
	ldrh r1, [r4, 0x30]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x10
	beq _0819946A
	bl sub_812210C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08199478
_0819946A:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_08199472:
	movs r1, 0
_08199474:
	bl sub_8199134
_08199478:
	movs r0, 0x2
	negs r0, r0
_0819947C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81993D8

	thumb_func_start sub_8199484
sub_8199484: @ 8199484
	push {r4-r6,lr}
	ldr r6, =gUnknown_0203CD90
	ldrb r4, [r6, 0x2]
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081994AC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x2
	ldrsb r0, [r6, r0]
	b _0819951E
	.pool
_081994AC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081994BA
	movs r0, 0x1
	negs r0, r0
	b _0819951E
_081994BA:
	ldrh r0, [r5, 0x30]
	movs r6, 0xF0
	adds r1, r6, 0
	ands r1, r0
	cmp r1, 0x40
	bne _081994CE
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	b _08199508
_081994CE:
	cmp r1, 0x80
	bne _081994D8
	movs r0, 0
	movs r1, 0x1
	b _08199508
_081994D8:
	cmp r1, 0x20
	beq _081994E8
	bl sub_812210C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081994EE
_081994E8:
	movs r0, 0x1
	negs r0, r0
	b _08199506
_081994EE:
	ldrh r1, [r5, 0x30]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0x10
	beq _08199504
	bl sub_812210C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0819951A
_08199504:
	movs r0, 0x1
_08199506:
	movs r1, 0
_08199508:
	bl sub_81991F8
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _0819951A
	movs r0, 0x5
	bl PlaySE
_0819951A:
	movs r0, 0x2
	negs r0, r0
_0819951E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8199484

	thumb_func_start InitMenuInUpperLeftCorner
@ int InitMenuInUpperLeftCorner(s8 windowId, s8 numItems, u8 initialCursorPos, bool doNotPlaySoundWhenAPressed)
InitMenuInUpperLeftCorner: @ 8199524
	push {r4-r6,lr}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	ldr r4, =gUnknown_0203CD90
	movs r6, 0
	strb r6, [r4]
	movs r2, 0x1
	strb r2, [r4, 0x1]
	strb r6, [r4, 0x3]
	subs r1, 0x1
	strb r1, [r4, 0x4]
	strb r0, [r4, 0x5]
	strb r2, [r4, 0x6]
	movs r0, 0x10
	strb r0, [r4, 0x8]
	strb r3, [r4, 0xB]
	cmp r5, 0
	blt _08199554
	movs r0, 0x4
	ldrsb r0, [r4, r0]
	cmp r5, r0
	ble _0819955C
_08199554:
	strb r6, [r4, 0x2]
	b _0819955E
	.pool
_0819955C:
	strb r5, [r4, 0x2]
_0819955E:
	movs r0, 0
	bl MoveMenuCursor
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end InitMenuInUpperLeftCorner

	thumb_func_start InitMenuInUpperLeftCornerPlaySoundWhenAPressed
InitMenuInUpperLeftCornerPlaySoundWhenAPressed: @ 8199570
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	bl InitMenuInUpperLeftCorner
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end InitMenuInUpperLeftCornerPlaySoundWhenAPressed

	thumb_func_start PrintMenuTable
PrintMenuTable: @ 819958C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	movs r5, 0
	cmp r5, r7
	bcs _081995D0
	movs r6, 0x80
	lsls r6, 17
	adds r4, r2, 0
_081995AA:
	ldr r2, [r4]
	lsrs r0, r6, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, r7
	bcc _081995AA
_081995D0:
	mov r0, r8
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PrintMenuTable

	thumb_func_start sub_81995E4
sub_81995E4: @ 81995E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r2
	mov r8, r3
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	mov r0, sp
	movs r1, 0
	mov r10, r1
	strb r6, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x5]
	movs r1, 0x5
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r5, 0xF
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	movs r0, 0x1
	movs r1, 0x6
	bl GetFontAttribute
	mov r3, sp
	adds r1, r5, 0
	ands r1, r0
	ldrb r2, [r3, 0xD]
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xD]
	movs r0, 0x1
	movs r1, 0x7
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xD]
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	movs r0, 0x1
	movs r1, 0x4
	bl GetFontAttribute
	mov r1, sp
	ands r5, r0
	ldrb r0, [r1, 0xC]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0xC]
	mov r0, sp
	mov r1, r10
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	movs r1, 0x8
	strb r1, [r0, 0x6]
	strb r1, [r0, 0x8]
	movs r4, 0
	cmp r4, r7
	bcs _081996A6
	mov r5, sp
_0819967C:
	mov r1, r8
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, 3
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	lsls r0, r4, 4
	adds r0, 0x1
	strb r0, [r5, 0x7]
	strb r0, [r5, 0x9]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r7
	bcc _0819967C
_081996A6:
	adds r0, r6, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81995E4

	thumb_func_start CreateYesNoMenu
@ void CreateYesNoMenu(struct WindowTemplate *windowTemplate, u16 borderFirstTileNum, u8 borderPalette, u8 initialCursorPos)
CreateYesNoMenu: @ 81996C0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r1, =gUnknown_0203CD9F
	mov r8, r1
	bl AddWindow
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r2]
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl SetWindowBorderStyle
	ldr r0, =gText_YesNo
	str r0, [sp]
	mov r1, sp
	mov r2, r8
	ldrb r0, [r2]
	movs r2, 0
	mov r9, r2
	strb r0, [r1, 0x4]
	mov r0, sp
	movs r2, 0x1
	strb r2, [r0, 0x5]
	movs r0, 0x8
	strb r0, [r1, 0x6]
	mov r0, sp
	strb r2, [r0, 0x7]
	ldrb r0, [r0, 0x6]
	strb r0, [r1, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x7]
	strb r0, [r1, 0x9]
	movs r0, 0x1
	movs r1, 0x5
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r5, 0xF
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	movs r0, 0x1
	movs r1, 0x6
	bl GetFontAttribute
	mov r3, sp
	adds r1, r5, 0
	ands r1, r0
	ldrb r2, [r3, 0xD]
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xD]
	movs r0, 0x1
	movs r1, 0x7
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xD]
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	movs r0, 0x1
	movs r1, 0x4
	bl GetFontAttribute
	mov r1, sp
	ands r5, r0
	ldrb r0, [r1, 0xC]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0xC]
	mov r0, sp
	mov r1, r9
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	mov r2, r8
	ldrb r0, [r2]
	movs r1, 0x2
	adds r2, r6, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateYesNoMenu

	thumb_func_start sub_81997AC
sub_81997AC: @ 81997AC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x10]
	movs r7, 0
	cmp r7, r3
	bcs _08199824
_081997D4:
	movs r4, 0
	adds r0, r7, 0x1
	mov r9, r0
	cmp r4, r6
	bcs _0819981C
	lsls r0, r7, 4
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0x80
	lsls r5, 20
_081997EC:
	adds r0, r7, 0
	muls r0, r6
	adds r0, r4
	lsls r0, 3
	ldr r1, [sp, 0x34]
	adds r0, r1
	ldr r2, [r0]
	lsrs r3, r5, 24
	mov r0, r8
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r0, r10
	movs r1, 0x1
	bl PrintTextOnWindow
	ldr r1, [sp, 0xC]
	lsls r0, r1, 24
	adds r5, r0
	adds r4, 0x1
	cmp r4, r6
	bcc _081997EC
_0819981C:
	mov r7, r9
	ldr r4, [sp, 0x10]
	cmp r7, r4
	bcc _081997D4
_08199824:
	mov r0, r10
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81997AC

	thumb_func_start sub_819983C
sub_819983C: @ 819983C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x14]
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	mov r0, sp
	movs r6, 0
	ldrb r1, [r0, 0x10]
	strb r1, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x5]
	movs r1, 0x5
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xC]
	movs r5, 0xF
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xC]
	movs r0, 0x1
	movs r1, 0x6
	bl GetFontAttribute
	mov r3, sp
	adds r1, r5, 0
	ands r1, r0
	ldrb r2, [r3, 0xD]
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xD]
	movs r0, 0x1
	movs r1, 0x7
	bl GetFontAttribute
	mov r3, sp
	lsls r0, 4
	ldrb r2, [r3, 0xD]
	adds r1, r5, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0xD]
	movs r0, 0x1
	movs r1, 0x4
	bl GetFontAttribute
	mov r1, sp
	ands r5, r0
	ldrb r0, [r1, 0xC]
	ands r4, r0
	orrs r4, r5
	strb r4, [r1, 0xC]
	mov r0, sp
	strb r6, [r0, 0xA]
	strb r6, [r0, 0xB]
	movs r7, 0
	cmp r7, r10
	bcs _0819992A
_081998D6:
	movs r5, 0
	adds r2, r7, 0x1
	mov r9, r2
	cmp r5, r8
	bcs _08199920
	mov r4, sp
	lsls r0, r7, 4
	adds r6, r0, 0x1
_081998E6:
	mov r0, r8
	muls r0, r7
	adds r0, r5
	ldr r1, [sp, 0x3C]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 3
	ldr r2, [sp, 0x38]
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r1, [sp, 0x14]
	adds r0, r1, 0
	muls r0, r5
	adds r0, 0x8
	strb r0, [r4, 0x6]
	strb r6, [r4, 0x7]
	strb r0, [r4, 0x8]
	strb r6, [r4, 0x9]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r8
	bcc _081998E6
_08199920:
	mov r2, r9
	lsls r0, r2, 24
	lsrs r7, r0, 24
	cmp r7, r10
	bcc _081998D6
_0819992A:
	ldr r0, [sp, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_819983C

	thumb_func_start sub_8199944
sub_8199944: @ 8199944
	push {r4-r7,lr}
	ldr r4, [sp, 0x14]
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r7, r4, 24
	ldr r6, =gUnknown_0203CD90
	movs r4, 0
	mov r12, r4
	mov r4, r12
	strb r4, [r6]
	movs r5, 0x1
	strb r5, [r6, 0x1]
	strb r4, [r6, 0x3]
	adds r4, r2, 0
	muls r4, r3
	subs r4, 0x1
	strb r4, [r6, 0x4]
	strb r0, [r6, 0x5]
	strb r5, [r6, 0x6]
	strb r1, [r6, 0x7]
	movs r0, 0x10
	strb r0, [r6, 0x8]
	strb r2, [r6, 0x9]
	strb r3, [r6, 0xA]
	cmp r7, 0
	blt _08199986
	movs r0, 0x4
	ldrsb r0, [r6, r0]
	cmp r7, r0
	ble _08199990
_08199986:
	mov r0, r12
	strb r0, [r6, 0x2]
	b _08199992
	.pool
_08199990:
	strb r7, [r6, 0x2]
_08199992:
	movs r0, 0
	movs r1, 0
	bl sub_8199134
	ldr r0, =gUnknown_0203CD90
	ldrb r0, [r0, 0x2]
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8199944

	thumb_func_start clear_scheduled_bg_copies_to_vram
@ void clear_scheduled_bg_copies_to_vram()
clear_scheduled_bg_copies_to_vram: @ 81999A8
	push {lr}
	ldr r0, =gUnknown_0203CDA4
	movs r1, 0
	movs r2, 0x4
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end clear_scheduled_bg_copies_to_vram

	thumb_func_start schedule_bg_copy_tilemap_to_vram
@ void schedule_bg_copy_tilemap_to_vram(u8 bg_id)
schedule_bg_copy_tilemap_to_vram: @ 81999BC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CDA4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end schedule_bg_copy_tilemap_to_vram

	thumb_func_start do_scheduled_bg_tilemap_copies_to_vram
@ void do_scheduled_bg_tilemap_copies_to_vram()
do_scheduled_bg_tilemap_copies_to_vram: @ 81999D0
	push {r4,lr}
	ldr r4, =gUnknown_0203CDA4
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _081999E4
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	strb r0, [r4]
_081999E4:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	bne _081999F4
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	strb r0, [r4, 0x1]
_081999F4:
	ldrb r0, [r4, 0x2]
	cmp r0, 0x1
	bne _08199A04
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	strb r0, [r4, 0x2]
_08199A04:
	ldrb r0, [r4, 0x3]
	cmp r0, 0x1
	bne _08199A14
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	strb r0, [r4, 0x3]
_08199A14:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end do_scheduled_bg_tilemap_copies_to_vram

	thumb_func_start reset_temp_tile_data_buffers
@ void reset_temp_tile_data_buffers()
reset_temp_tile_data_buffers: @ 8199A20
	push {lr}
	ldr r3, =gUnknown_0203CDA8
	ldr r1, =gUnknown_0203CDAC
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x7C
_08199A2C:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _08199A2C
	movs r0, 0
	strh r0, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end reset_temp_tile_data_buffers

	thumb_func_start free_temp_tile_data_buffers_if_possible
free_temp_tile_data_buffers_if_possible: @ 8199A44
	push {r4-r6,lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08199A88
	ldr r1, =gUnknown_0203CDA8
	ldrh r0, [r1]
	cmp r0, 0
	beq _08199A7C
	movs r4, 0
	ldrh r1, [r1]
	cmp r4, r1
	bge _08199A76
	ldr r5, =gUnknown_0203CDAC
	movs r6, 0
_08199A64:
	ldr r0, [r5]
	bl Free
	stm r5!, {r6}
	adds r4, 0x1
	ldr r0, =gUnknown_0203CDA8
	ldrh r0, [r0]
	cmp r4, r0
	blt _08199A64
_08199A76:
	ldr r1, =gUnknown_0203CDA8
	movs r0, 0
	strh r0, [r1]
_08199A7C:
	movs r0, 0
	b _08199A8A
	.pool
_08199A88:
	movs r0, 0x1
_08199A8A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end free_temp_tile_data_buffers_if_possible

	thumb_func_start decompress_and_copy_tile_data_to_vram
@ int decompress_and_copy_tile_data_to_vram(u8 bg_id, int src, int size, u16 offset, u8 mode)
decompress_and_copy_tile_data_to_vram: @ 8199A90
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r1, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	mov r9, r3
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r6, =gUnknown_0203CDA8
	ldrh r0, [r6]
	cmp r0, 0x1F
	bhi _08199AF8
	adds r0, r4, 0
	add r1, sp, 0x4
	bl malloc_and_decompress
	adds r4, r0, 0
	cmp r5, 0
	bne _08199AC8
	ldr r5, [sp, 0x4]
_08199AC8:
	cmp r4, 0
	beq _08199AEC
	lsls r2, r5, 16
	lsrs r2, 16
	str r7, [sp]
	mov r0, r8
	adds r1, r4, 0
	mov r3, r9
	bl copy_decompressed_tile_data_to_vram
	ldr r2, =gUnknown_0203CDAC
	ldrh r0, [r6]
	adds r1, r0, 0x1
	strh r1, [r6]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r2
	str r4, [r0]
_08199AEC:
	adds r0, r4, 0
	b _08199AFA
	.pool
_08199AF8:
	movs r0, 0
_08199AFA:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end decompress_and_copy_tile_data_to_vram

	thumb_func_start copy_decompressed_tile_data_to_vram_autofree
@ void copy_decompressed_tile_data_to_vram_autofree(u8 bg_id, int src, u16 size, u16 offset, u8 mode)
copy_decompressed_tile_data_to_vram_autofree: @ 8199B08
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r5, r2, 0
	ldr r2, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r3, 16
	lsrs r3, 16
	mov r9, r3
	lsls r2, 24
	lsrs r7, r2, 24
	adds r0, r1, 0
	add r1, sp, 0x4
	bl malloc_and_decompress
	adds r6, r0, 0
	cmp r5, 0
	bne _08199B36
	ldr r5, [sp, 0x4]
_08199B36:
	cmp r6, 0
	beq _08199B6E
	ldr r0, =task_free_buf_after_copying_tile_data_to_vram
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, r5, 16
	lsrs r2, 16
	str r7, [sp]
	mov r0, r8
	adds r1, r6, 0
	mov r3, r9
	bl copy_decompressed_tile_data_to_vram
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r2
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl SetWordTaskArg
_08199B6E:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end copy_decompressed_tile_data_to_vram_autofree

	thumb_func_start task_free_buf_after_copying_tile_data_to_vram
@ void task_free_buf_after_copying_tile_data_to_vram(int task_id)
task_free_buf_after_copying_tile_data_to_vram: @ 8199B84
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl CheckForSpaceForDma3Request
	lsls r0, 16
	cmp r0, 0
	bne _08199BB4
	adds r0, r4, 0
	movs r1, 0x1
	bl GetWordTaskArg
	bl Free
	adds r0, r4, 0
	bl DestroyTask
_08199BB4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_free_buf_after_copying_tile_data_to_vram

	thumb_func_start malloc_and_decompress
@ void *malloc_and_decompress(void *src, int *size)
malloc_and_decompress: @ 8199BC0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrb r0, [r5, 0x1]
	strb r0, [r1]
	ldrb r0, [r5, 0x2]
	strb r0, [r1, 0x1]
	ldrb r0, [r5, 0x3]
	strb r0, [r1, 0x2]
	movs r0, 0
	strb r0, [r1, 0x3]
	ldr r0, [r1]
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	beq _08199BE8
	adds r0, r5, 0
	adds r1, r4, 0
	bl LZ77UnCompWram
_08199BE8:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end malloc_and_decompress

	thumb_func_start copy_decompressed_tile_data_to_vram
@ s16 copy_decompressed_tile_data_to_vram(u8 bg_id, int src, u16 size, u16 offset, u8 mode)
copy_decompressed_tile_data_to_vram: @ 8199BF0
	push {r4,lr}
	adds r4, r1, 0
	ldr r1, [sp, 0x8]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0
	beq _08199C18
	cmp r1, 0x1
	beq _08199C20
	ldr r0, =0x0000ffff
	b _08199C2A
	.pool
_08199C18:
	adds r1, r4, 0
	bl LoadBgTiles
	b _08199C26
_08199C20:
	adds r1, r4, 0
	bl LoadBgTilemap
_08199C26:
	lsls r0, 16
	lsrs r0, 16
_08199C2A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end copy_decompressed_tile_data_to_vram

	thumb_func_start sub_8199C30
sub_8199C30: @ 8199C30
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r2, 0
	ldr r4, [sp, 0x28]
	ldr r2, [sp, 0x2C]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	bl GetBgTilemapBuffer
	mov r8, r0
	adds r0, r5, r4
	cmp r5, r0
	bge _08199CA8
	mov r9, r0
_08199C6E:
	ldr r3, [sp]
	ldr r1, [sp, 0x4]
	adds r0, r3, r1
	adds r7, r5, 0x1
	cmp r3, r0
	bge _08199CA0
	lsls r6, r5, 5
	ldr r1, =0x00000fff
	mov r12, r1
	mov r1, r10
	lsls r5, r1, 12
	adds r4, r0, 0
_08199C86:
	adds r1, r6, r3
	lsls r1, 1
	add r1, r8
	ldrh r2, [r1]
	mov r0, r12
	ands r0, r2
	orrs r0, r5
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	blt _08199C86
_08199CA0:
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, r9
	blt _08199C6E
_08199CA8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8199C30

	thumb_func_start sub_8199CBC
sub_8199CBC: @ 8199CBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r1
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r4, 24
	lsrs r4, 24
	mov r8, r4
	bl GetBgTilemapBuffer
	adds r7, r0, 0
	movs r0, 0
	cmp r0, r8
	bcs _08199D2A
_08199CF4:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r5
	bcs _08199D22
	adds r4, r0, 0
	muls r4, r5
	ldr r1, [sp]
	adds r0, r1
	lsls r3, r0, 5
_08199D06:
	adds r1, r4, r2
	lsls r1, 1
	add r1, r10
	adds r0, r3, r2
	add r0, r9
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r5
	bcc _08199D06
_08199D22:
	lsls r0, r6, 24
	lsrs r0, 24
	cmp r0, r8
	bcc _08199CF4
_08199D2A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8199CBC

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

	thumb_func_start AddTextPrinterParametrized2
@ void AddTextPrinterParametrized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, struct TextColor *color, u8 speed, u8 *str)
AddTextPrinterParametrized2: @ 8199EEC
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
	thumb_func_end AddTextPrinterParametrized2

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
	ldr r0, =gUnknown_08DC4318
	b _0819A2E6
	.pool
_0819A2DC:
	ldr r0, =gUnknown_08DC4338
	b _0819A2E6
	.pool
_0819A2E4:
	ldr r0, =gUnknown_08DC4358
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
	ldr r4, =gUnknown_08DC4378
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
