	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




	thumb_func_start ListMenuDrawCursor
@ void ListMenuDrawCursor(struct ListMenu *listMenu)
ListMenuDrawCursor: @ 81AEB20
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldrb r0, [r6, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetFontAttribute
	ldrb r1, [r6, 0x16]
	lsls r1, 26
	lsrs r1, 29
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r6, 0x13]
	mov r8, r1
	ldrh r1, [r6, 0x1A]
	muls r1, r0
	ldrb r0, [r6, 0x14]
	lsls r0, 28
	lsrs r0, 28
	adds r0, r1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r6, 0x17]
	lsrs r0, 6
	cmp r0, 0x1
	beq _081AEC0C
	cmp r0, 0x1
	bgt _081AEB66
	cmp r0, 0
	beq _081AEB70
	b _081AEC0C
_081AEB66:
	cmp r0, 0x2
	beq _081AEB84
	cmp r0, 0x3
	beq _081AEBCC
	b _081AEC0C
_081AEB70:
	ldr r1, =gText_SelectorArrow2
	adds r0, r6, 0
	mov r2, r8
	adds r3, r7, 0
	bl ListMenuPrint
	b _081AEC0C
	.pool
_081AEB84:
	ldrb r0, [r6, 0x1E]
	cmp r0, 0xFF
	bne _081AEB94
	adds r0, r6, 0
	movs r1, 0
	bl ListMenuAddCursorObject
	strb r0, [r6, 0x1E]
_081AEB94:
	ldrb r5, [r6, 0x1E]
	ldrb r0, [r6, 0x10]
	movs r1, 0x1
	bl GetWindowAttribute
	adds r4, r0, 0
	lsls r4, 19
	ldr r0, =0xffff0000
	adds r4, r0
	lsrs r4, 16
	ldrb r0, [r6, 0x10]
	movs r1, 0x2
	bl GetWindowAttribute
	adds r2, r0, 0
	lsls r2, 3
	adds r2, r7
	subs r2, 0x1
	lsls r2, 16
	lsrs r2, 16
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0
	bl ListMenuUpdateCursorObject
	b _081AEC0C
	.pool
_081AEBCC:
	ldrb r0, [r6, 0x1E]
	cmp r0, 0xFF
	bne _081AEBDC
	adds r0, r6, 0
	movs r1, 0x1
	bl ListMenuAddCursorObject
	strb r0, [r6, 0x1E]
_081AEBDC:
	ldrb r5, [r6, 0x1E]
	ldrb r0, [r6, 0x10]
	movs r1, 0x1
	bl GetWindowAttribute
	adds r4, r0, 0
	lsls r4, 3
	add r4, r8
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r6, 0x10]
	movs r1, 0x2
	bl GetWindowAttribute
	adds r2, r0, 0
	lsls r2, 3
	adds r2, r7
	lsls r2, 16
	lsrs r2, 16
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl ListMenuUpdateCursorObject
_081AEC0C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ListMenuDrawCursor

	thumb_func_start ListMenuAddCursorObject
ListMenuAddCursorObject: @ 81AEC18
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	mov r1, sp
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xA0
	strb r0, [r1, 0x1]
	ldrb r0, [r4, 0x10]
	movs r1, 0x3
	bl GetWindowAttribute
	mov r1, sp
	lsls r0, 3
	adds r0, 0x2
	strh r0, [r1, 0x2]
	ldrb r0, [r4, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetFontAttribute
	mov r1, sp
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x2
	strh r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 7
	strh r0, [r1, 0x6]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x8]
	movs r0, 0xF
	strb r0, [r1, 0xA]
	mov r0, sp
	adds r1, r5, 0
	bl ListMenuAddCursorObjectInternal
	lsls r0, 24
	lsrs r0, 24
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ListMenuAddCursorObject

	thumb_func_start ListMenuErasePrintedCursor
ListMenuErasePrintedCursor: @ 81AEC78
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r7, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	ldrb r1, [r7, 0x17]
	lsrs r0, r1, 6
	cmp r0, 0
	bne _081AECF4
	lsls r0, r1, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetFontAttribute
	adds r4, r0, 0
	ldrb r0, [r7, 0x16]
	lsls r0, 26
	lsrs r0, 29
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r7, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r7, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	ldrb r6, [r7, 0x10]
	ldrb r2, [r7, 0x15]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	ldrb r2, [r7, 0x13]
	mov r3, r8
	muls r3, r4
	adds r4, r3, 0
	ldrb r3, [r7, 0x14]
	lsls r3, 28
	lsrs r3, 28
	adds r3, r4
	lsls r3, 16
	lsrs r3, 16
	str r5, [sp]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	bl FillWindowPixelRect
_081AECF4:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ListMenuErasePrintedCursor

	thumb_func_start ListMenuUpdateSelectedRowIndexAndScrollOffset
@ u8 ListMenuUpdateSelectedRowIndexAndScrollOffset(int, bool8 movingDown)
ListMenuUpdateSelectedRowIndexAndScrollOffset: @ 81AED00
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	ldrh r3, [r4, 0x1A]
	ldrh r5, [r4, 0x18]
	cmp r1, 0
	bne _081AED74
	ldrh r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081AED18
	movs r2, 0
	b _081AED2A
_081AED18:
	ldrh r0, [r4, 0xE]
	lsrs r2, r0, 1
	movs r1, 0x1
	ands r1, r0
	adds r2, r1
	subs r0, r2
	subs r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
_081AED2A:
	cmp r5, 0
	bne _081AED50
	cmp r3, 0
	beq _081AEDB6
	ldr r1, [r4]
	movs r2, 0x3
	negs r2, r2
_081AED38:
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r0, r5, r3
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	cmp r0, r2
	bne _081AEDBA
	cmp r3, 0
	bne _081AED38
	b _081AEDB6
_081AED50:
	cmp r3, r2
	bls _081AED70
	ldr r1, [r4]
	movs r6, 0x3
	negs r6, r6
_081AED5A:
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r0, r5, r3
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	cmp r0, r6
	bne _081AEDBA
	cmp r3, r2
	bhi _081AED5A
_081AED70:
	subs r0, r5, 0x1
	b _081AEDE2
_081AED74:
	ldrh r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081AED7E
	movs r2, 0
	b _081AED88
_081AED7E:
	ldrh r0, [r4, 0xE]
	lsrs r2, r0, 1
	movs r1, 0x1
	ands r1, r0
	adds r2, r1
_081AED88:
	adds r1, r0, 0
	ldrh r0, [r4, 0xC]
	subs r0, r1
	cmp r5, r0
	bne _081AEDC0
	subs r0, r1, 0x1
	cmp r3, r0
	bge _081AEDB6
	ldr r2, [r4]
	movs r6, 0x3
	negs r6, r6
	adds r1, r0, 0
_081AEDA0:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r0, r5, r3
	lsls r0, 3
	adds r0, r2
	ldr r0, [r0, 0x4]
	cmp r0, r6
	bne _081AEDBA
	cmp r3, r1
	blt _081AEDA0
_081AEDB6:
	movs r0, 0
	b _081AEDE8
_081AEDBA:
	strh r3, [r4, 0x1A]
	movs r0, 0x1
	b _081AEDE8
_081AEDC0:
	cmp r3, r2
	bcs _081AEDE0
	ldr r1, [r4]
	movs r6, 0x3
	negs r6, r6
_081AEDCA:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r0, r5, r3
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	cmp r0, r6
	bne _081AEDBA
	cmp r3, r2
	bcc _081AEDCA
_081AEDE0:
	adds r0, r5, 0x1
_081AEDE2:
	strh r2, [r4, 0x1A]
	strh r0, [r4, 0x18]
	movs r0, 0x2
_081AEDE8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ListMenuUpdateSelectedRowIndexAndScrollOffset

	thumb_func_start ListMenuScroll
@ void ListMenuScroll(struct ListMenu *listMenu, int a2, bool8 movingDown)
ListMenuScroll: @ 81AEDF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	adds r7, r5, 0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldrh r0, [r6, 0xE]
	cmp r5, r0
	bcc _081AEE2A
	ldrb r0, [r6, 0x10]
	ldrb r2, [r6, 0x15]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl FillWindowPixelBuffer
	ldrh r1, [r6, 0x18]
	ldrh r3, [r6, 0xE]
	adds r0, r6, 0
	movs r2, 0
	bl ListMenuPrintEntries
	b _081AEF1A
_081AEE2A:
	ldrb r0, [r6, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetFontAttribute
	ldrb r1, [r6, 0x16]
	lsls r1, 26
	lsrs r1, 29
	adds r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, r8
	cmp r1, 0
	bne _081AEEBC
	ldrb r0, [r6, 0x10]
	adds r2, r5, 0
	muls r2, r4
	lsls r2, 24
	lsrs r2, 24
	ldrb r1, [r6, 0x15]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0x1
	bl ScrollWindow
	ldrh r1, [r6, 0x18]
	adds r0, r6, 0
	movs r2, 0
	adds r3, r5, 0
	bl ListMenuPrintEntries
	ldrh r0, [r6, 0xE]
	adds r1, r0, 0
	muls r1, r4
	adds r0, r1, 0
	ldrb r4, [r6, 0x14]
	lsls r4, 28
	lsrs r4, 28
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r6, 0x10]
	movs r1, 0x3
	bl GetWindowAttribute
	adds r5, r0, 0
	lsls r5, 19
	lsrs r5, 16
	ldrb r0, [r6, 0x10]
	movs r1, 0x4
	bl GetWindowAttribute
	lsls r0, 3
	subs r0, r4
	lsls r0, 16
	lsrs r0, 16
	ldrb r3, [r6, 0x10]
	ldrb r2, [r6, 0x15]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	str r5, [sp]
	str r0, [sp, 0x4]
	adds r0, r3, 0
	movs r2, 0
	adds r3, r4, 0
	bl FillWindowPixelRect
	b _081AEF1A
_081AEEBC:
	ldrb r0, [r6, 0x10]
	adds r2, r7, 0
	muls r2, r4
	lsls r2, 24
	lsrs r2, 24
	ldrb r1, [r6, 0x15]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	bl ScrollWindow
	ldrh r2, [r6, 0xE]
	subs r2, r7
	ldrh r1, [r6, 0x18]
	adds r1, r2
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	adds r0, r6, 0
	adds r3, r7, 0
	bl ListMenuPrintEntries
	ldrb r0, [r6, 0x10]
	movs r1, 0x3
	bl GetWindowAttribute
	lsls r0, 19
	lsrs r0, 16
	ldrb r3, [r6, 0x10]
	ldrb r2, [r6, 0x15]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	str r0, [sp]
	ldrb r0, [r6, 0x14]
	lsls r0, 28
	lsrs r0, 28
	str r0, [sp, 0x4]
	adds r0, r3, 0
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
_081AEF1A:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ListMenuScroll

	thumb_func_start ListMenuChangeSelection
@ bool8 ListMenuChangeSelection(struct ListMenu *listMenu, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown)
ListMenuChangeSelection: @ 81AEF28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	ldrh r0, [r4, 0x1A]
	mov r10, r0
	movs r7, 0
	movs r5, 0
	movs r0, 0
	cmp r7, r8
	bcs _081AEF90
_081AEF56:
	adds r6, r0, 0x1
	b _081AEF76
_081AEF5A:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r4, 0x18]
	ldrh r1, [r4, 0x1A]
	adds r0, r1
	ldr r1, [r4]
	lsls r0, 3
	adds r0, r1
	ldr r1, [r0, 0x4]
	movs r0, 0x3
	negs r0, r0
	cmp r1, r0
	bne _081AEF88
_081AEF76:
	adds r0, r4, 0
	mov r1, r9
	bl ListMenuUpdateSelectedRowIndexAndScrollOffset
	lsls r0, 24
	lsrs r0, 24
	orrs r5, r0
	cmp r0, 0x2
	beq _081AEF5A
_081AEF88:
	lsls r0, r6, 24
	lsrs r0, 24
	cmp r0, r8
	bcc _081AEF56
_081AEF90:
	ldr r0, [sp]
	cmp r0, 0
	beq _081AEFEE
	cmp r5, 0x1
	beq _081AEFA6
	cmp r5, 0x1
	ble _081AEFA2
	cmp r5, 0x3
	ble _081AEFC6
_081AEFA2:
	movs r0, 0x1
	b _081AEFF0
_081AEFA6:
	adds r0, r4, 0
	mov r1, r10
	bl ListMenuErasePrintedCursor
	adds r0, r4, 0
	bl ListMenuDrawCursor
	adds r0, r4, 0
	movs r1, 0
	bl ListMenuCallSelectionChangedCallback
	ldrb r0, [r4, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	b _081AEFEE
_081AEFC6:
	adds r0, r4, 0
	mov r1, r10
	bl ListMenuErasePrintedCursor
	adds r0, r4, 0
	adds r1, r7, 0
	mov r2, r9
	bl ListMenuScroll
	adds r0, r4, 0
	bl ListMenuDrawCursor
	adds r0, r4, 0
	movs r1, 0
	bl ListMenuCallSelectionChangedCallback
	ldrb r0, [r4, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
_081AEFEE:
	movs r0, 0
_081AEFF0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ListMenuChangeSelection

	thumb_func_start ListMenuCallSelectionChangedCallback
@ void ListMenuCallSelectionChangedCallback(struct ListMenu *listMenu, u8 a2)
ListMenuCallSelectionChangedCallback: @ 81AF000
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r3, [r2, 0x4]
	cmp r3, 0
	beq _081AF022
	ldrh r0, [r2, 0x18]
	ldrh r1, [r2, 0x1A]
	adds r0, r1
	ldr r1, [r2]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	adds r1, r4, 0
	bl _call_via_r3
_081AF022:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ListMenuCallSelectionChangedCallback

	thumb_func_start sub_81AF028
sub_81AF028: @ 81AF028
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r6, =gUnknown_03006300
	movs r5, 0xF
	ands r0, r5
	ldrb r3, [r6]
	mov r8, r3
	movs r4, 0x10
	negs r4, r4
	adds r3, r4, 0
	mov r7, r8
	ands r3, r7
	orrs r3, r0
	lsrs r1, 20
	ands r3, r5
	orrs r3, r1
	strb r3, [r6]
	ands r2, r5
	ldrb r0, [r6, 0x1]
	ands r4, r0
	orrs r4, r2
	strb r4, [r6, 0x1]
	ldrb r0, [r6, 0x3]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r6, 0x3]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AF028

	thumb_func_start sub_81AF078
sub_81AF078: @ 81AF078
	push {lr}
	lsls r1, 24
	cmp r1, 0
	bne _081AF086
	movs r0, 0x5
	bl PlaySE
_081AF086:
	pop {r0}
	bx r0
	thumb_func_end sub_81AF078

	.align 2, 0 @ Don't pad with nop.
