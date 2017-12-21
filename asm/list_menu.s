	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ListMenuDummyTask
@ void ListMenuDummyTask(u8 taskId)
ListMenuDummyTask: @ 81AE458
	bx lr
	thumb_func_end ListMenuDummyTask

	thumb_func_start DoMysteryGiftListMenu
@ int DoMysteryGiftListMenu(struct WindowTemplate *windowTemplate, struct ListMenuTemplate *listMenuTemplate, int a3, int a4, int a5)
DoMysteryGiftListMenu: @ 81AE45C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r12, r0
	str r1, [sp]
	ldr r0, [sp, 0x28]
	lsls r2, 24
	lsrs r6, r2, 24
	mov r10, r6
	lsls r3, 16
	lsrs r7, r3, 16
	str r7, [sp, 0x4]
	lsls r0, 16
	mov r8, r0
	lsrs r0, 16
	mov r9, r0
	ldr r5, =gUnknown_0203CE84
	ldrb r4, [r5, 0x4]
	cmp r4, 0x1
	beq _081AE4F4
	cmp r4, 0x1
	ble _081AE492
	cmp r4, 0x2
	beq _081AE558
_081AE492:
	mov r0, r12
	bl AddWindow
	strb r0, [r5, 0x5]
	cmp r6, 0x1
	beq _081AE4B0
	cmp r6, 0x2
	bne _081AE4C0
	ldrb r0, [r5, 0x5]
	mov r1, r9
	lsls r2, r1, 24
	lsrs r2, 24
	adds r1, r7, 0
	bl sub_809882C
_081AE4B0:
	ldrb r0, [r5, 0x5]
	mov r3, r8
	lsrs r2, r3, 20
	lsls r2, 24
	lsrs r2, 24
	ldr r1, [sp, 0x4]
	bl sub_8098858
_081AE4C0:
	ldr r0, =gMultiuseListMenuTemplate
	adds r2, r0, 0
	ldr r1, [sp]
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldr r4, =gUnknown_0203CE84
	ldrb r1, [r4, 0x5]
	strb r1, [r0, 0x10]
	movs r1, 0
	movs r2, 0
	bl ListMenuInit
	strb r0, [r4, 0x6]
	ldrb r0, [r4, 0x5]
	movs r1, 0x1
	bl CopyWindowToVram
	movs r0, 0x1
	strb r0, [r4, 0x4]
	b _081AE570
	.pool
_081AE4F4:
	ldrb r0, [r5, 0x6]
	bl ListMenuHandleInputGetItemId
	str r0, [r5]
	ldr r1, =gMain
	ldrh r0, [r1, 0x2E]
	ands r4, r0
	cmp r4, 0
	beq _081AE50A
	movs r0, 0x2
	strb r0, [r5, 0x4]
_081AE50A:
	ldrh r1, [r1, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081AE51E
	movs r0, 0x2
	negs r0, r0
	str r0, [r5]
	movs r0, 0x2
	strb r0, [r5, 0x4]
_081AE51E:
	ldrb r0, [r5, 0x4]
	cmp r0, 0x2
	bne _081AE570
	cmp r6, 0
	bne _081AE534
	ldrb r0, [r5, 0x5]
	bl ClearWindowTilemap
	b _081AE546
	.pool
_081AE534:
	mov r4, r10
	cmp r4, 0
	blt _081AE546
	cmp r4, 0x2
	bgt _081AE546
	ldrb r0, [r5, 0x5]
	movs r1, 0
	bl sub_819746C
_081AE546:
	ldr r0, =gUnknown_0203CE84
	ldrb r0, [r0, 0x5]
	movs r1, 0x1
	bl CopyWindowToVram
	b _081AE570
	.pool
_081AE558:
	ldrb r0, [r5, 0x6]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldrb r0, [r5, 0x5]
	bl RemoveWindow
	movs r0, 0
	strb r0, [r5, 0x4]
	ldr r0, [r5]
	b _081AE574
_081AE570:
	movs r0, 0x1
	negs r0, r0
_081AE574:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end DoMysteryGiftListMenu

	thumb_func_start ListMenuInit
@ u8 ListMenuInit(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow)
ListMenuInit: @ 81AE584
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	bl ListMenuInitInternal
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5, 0x10]
	bl PutWindowTilemap
	ldrb r0, [r5, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end ListMenuInit

	thumb_func_start Unused_ListMenuInit2
@ u8 Unused_ListMenuInit2(struct ListMenuTemplate *listMenuTemplate, int a2, u16 scrollOffset, u16 selectedRow)
Unused_ListMenuInit2: @ 81AE5B0
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r4, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	bl ListMenuInitInternal
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r4, 0x4]
	cmp r0, 0xFF
	beq _081AE5F0
	adds r5, r4, 0
_081AE5D4:
	ldrb r0, [r6, 0x10]
	ldrb r1, [r5]
	ldrb r2, [r5, 0x1]
	ldrb r3, [r5, 0x2]
	ldrb r4, [r5, 0x3]
	str r4, [sp]
	ldrb r4, [r5, 0x4]
	str r4, [sp, 0x4]
	bl PutWindowRectTilemapOverridePalette
	adds r5, 0x8
	ldrb r0, [r5, 0x4]
	cmp r0, 0xFF
	bne _081AE5D4
_081AE5F0:
	ldrb r0, [r6, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end Unused_ListMenuInit2

	thumb_func_start ListMenuHandleInputGetItemId
@ int ListMenuHandleInputGetItemId(u8 taskId)
ListMenuHandleInputGetItemId: @ 81AE604
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r3, r1, r0
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081AE638
	ldrh r0, [r3, 0x18]
	ldrh r1, [r3, 0x1A]
	adds r0, r1
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	b _081AE6C2
	.pool
_081AE638:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081AE646
	movs r0, 0x2
	negs r0, r0
	b _081AE6C2
_081AE646:
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081AE65A
	adds r0, r3, 0
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0
	b _081AE6BA
_081AE65A:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081AE66A
	adds r0, r3, 0
	movs r1, 0x1
	movs r2, 0x1
	b _081AE6B8
_081AE66A:
	ldrb r0, [r3, 0x16]
	lsrs r0, 6
	cmp r0, 0x1
	beq _081AE680
	cmp r0, 0x1
	ble _081AE67A
	cmp r0, 0x2
	beq _081AE68C
_081AE67A:
	movs r2, 0
	movs r0, 0
	b _081AE6A0
_081AE680:
	movs r0, 0x20
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0x10
	b _081AE69A
_081AE68C:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0x80
	lsls r0, 1
_081AE69A:
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
_081AE6A0:
	cmp r2, 0
	beq _081AE6AE
	ldrb r2, [r3, 0xE]
	adds r0, r3, 0
	movs r1, 0x1
	movs r3, 0
	b _081AE6BA
_081AE6AE:
	cmp r0, 0
	beq _081AE6BE
	ldrb r2, [r3, 0xE]
	adds r0, r3, 0
	movs r1, 0x1
_081AE6B8:
	movs r3, 0x1
_081AE6BA:
	bl ListMenuChangeSelection
_081AE6BE:
	movs r0, 0x1
	negs r0, r0
_081AE6C2:
	pop {r1}
	bx r1
	thumb_func_end ListMenuHandleInputGetItemId

	thumb_func_start sub_81AE6C8
sub_81AE6C8: @ 81AE6C8
	push {r4,lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r1, r0, r1
	cmp r3, 0
	beq _081AE6E4
	ldrh r0, [r1, 0x18]
	strh r0, [r3]
_081AE6E4:
	cmp r2, 0
	beq _081AE6EC
	ldrh r0, [r1, 0x1A]
	strh r0, [r2]
_081AE6EC:
	ldrb r0, [r1, 0x1E]
	cmp r0, 0xFF
	beq _081AE6FC
	ldrb r1, [r1, 0x17]
	lsrs r1, 6
	subs r1, 0x2
	bl ListMenuRemoveCursorObject
_081AE6FC:
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AE6C8

	thumb_func_start sub_81AE70C
sub_81AE70C: @ 81AE70C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0x10]
	ldrb r2, [r4, 0x15]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl FillWindowPixelBuffer
	ldrh r1, [r4, 0x18]
	ldrh r3, [r4, 0xE]
	adds r0, r4, 0
	movs r2, 0
	bl ListMenuPrintEntries
	adds r0, r4, 0
	bl ListMenuDrawCursor
	ldrb r0, [r4, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AE70C

	thumb_func_start sub_81AE750
sub_81AE750: @ 81AE750
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	lsrs r1, 20
	ldrb r6, [r4, 0x14]
	movs r5, 0xF
	adds r0, r5, 0
	ands r0, r6
	orrs r0, r1
	strb r0, [r4, 0x14]
	ands r2, r5
	ldrb r1, [r4, 0x15]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	lsrs r3, 20
	ands r0, r5
	orrs r0, r3
	strb r0, [r4, 0x15]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AE750

	thumb_func_start sub_81AE794
sub_81AE794: @ 81AE794
	push {r4,r5,lr}
	adds r3, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0x10]
	movs r1, 0x1
	adds r2, r3, 0
	bl SetWindowAttribute
	ldrb r0, [r4, 0x10]
	movs r1, 0x2
	adds r2, r5, 0
	bl SetWindowAttribute
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AE794

	thumb_func_start sub_81AE7D0
sub_81AE7D0: @ 81AE7D0
	push {r4-r7,lr}
	sub sp, 0x20
	mov r12, r2
	ldr r5, [sp, 0x34]
	lsls r3, 16
	lsrs r3, 16
	adds r4, r3, 0
	mov r3, sp
	ldm r0!, {r2,r6,r7}
	stm r3!, {r2,r6,r7}
	ldm r0!, {r2,r6,r7}
	stm r3!, {r2,r6,r7}
	mov r0, sp
	movs r3, 0
	strh r1, [r0, 0x18]
	mov r1, r12
	strh r1, [r0, 0x1A]
	strb r3, [r0, 0x1C]
	strb r3, [r0, 0x1D]
	cmp r4, 0x40
	bne _081AE804
	movs r1, 0
	movs r2, 0x1
	movs r3, 0
	bl ListMenuChangeSelection
_081AE804:
	cmp r4, 0x80
	bne _081AE814
	mov r0, sp
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl ListMenuChangeSelection
_081AE814:
	cmp r5, 0
	beq _081AE81E
	mov r0, sp
	ldrh r0, [r0, 0x18]
	strh r0, [r5]
_081AE81E:
	ldr r2, [sp, 0x38]
	cmp r2, 0
	beq _081AE82A
	mov r0, sp
	ldrh r0, [r0, 0x1A]
	strh r0, [r2]
_081AE82A:
	movs r0, 0x1
	negs r0, r0
	add sp, 0x20
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81AE7D0

	thumb_func_start sub_81AE838
sub_81AE838: @ 81AE838
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	cmp r2, 0
	beq _081AE856
	ldrh r0, [r1, 0x1A]
	ldrh r1, [r1, 0x18]
	adds r0, r1
	strh r0, [r2]
_081AE856:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AE838

	thumb_func_start sub_81AE860
sub_81AE860: @ 81AE860
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	cmp r3, 0
	beq _081AE87A
	ldrh r0, [r1, 0x18]
	strh r0, [r3]
_081AE87A:
	cmp r2, 0
	beq _081AE882
	ldrh r0, [r1, 0x1A]
	strh r0, [r2]
_081AE882:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AE860

	thumb_func_start ListMenuGetYCoordForPrintingArrowCursor
@ u8 ListMenuGetYCoordForPrintingArrowCursor(u8 taskId)
ListMenuGetYCoordForPrintingArrowCursor: @ 81AE88C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetFontAttribute
	ldrb r1, [r4, 0x16]
	lsls r1, 26
	lsrs r1, 29
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x1A]
	adds r2, r1, 0
	muls r2, r0
	adds r1, r2, 0
	ldrb r0, [r4, 0x14]
	lsls r0, 28
	lsrs r0, 28
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ListMenuGetYCoordForPrintingArrowCursor

	thumb_func_start ListMenuInitInternal
@ u8 ListMenuInitInternal(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow)
ListMenuInitInternal: @ 81AE8D4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =ListMenuDummyTask
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	adds r0, r7, 0
	ldm r4!, {r1-r3}
	stm r0!, {r1-r3}
	ldm r4!, {r1-r3}
	stm r0!, {r1-r3}
	movs r1, 0
	strh r5, [r7, 0x18]
	strh r6, [r7, 0x1A]
	strb r1, [r7, 0x1C]
	strb r1, [r7, 0x1D]
	movs r0, 0xFF
	strb r0, [r7, 0x1E]
	strb r1, [r7, 0x1F]
	ldr r3, =gUnknown_03006300
	ldrb r1, [r7, 0x14]
	movs r5, 0xF
	lsrs r1, 4
	ldrb r4, [r3]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r7, 0x15]
	lsls r1, 28
	lsrs r1, 24
	ands r0, r5
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r7, 0x15]
	lsrs r0, 4
	ands r5, r0
	ldrb r0, [r3, 0x1]
	ands r2, r0
	orrs r2, r5
	strb r2, [r3, 0x1]
	ldrb r1, [r7, 0x16]
	lsls r1, 29
	lsrs r1, 17
	ldr r0, [r3]
	ldr r2, =0xfffc0fff
	ands r0, r2
	orrs r0, r1
	str r0, [r3]
	ldrb r0, [r7, 0x17]
	lsls r0, 26
	lsrs r0, 26
	strb r0, [r3, 0x3]
	ldrh r0, [r7, 0xC]
	ldrh r1, [r7, 0xE]
	cmp r0, r1
	bcs _081AE96C
	strh r0, [r7, 0xE]
_081AE96C:
	ldrb r0, [r7, 0x10]
	ldrb r2, [r7, 0x15]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl FillWindowPixelBuffer
	ldrh r1, [r7, 0x18]
	ldrh r3, [r7, 0xE]
	adds r0, r7, 0
	movs r2, 0
	bl ListMenuPrintEntries
	adds r0, r7, 0
	bl ListMenuDrawCursor
	adds r0, r7, 0
	movs r1, 0x1
	bl ListMenuCallSelectionChangedCallback
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ListMenuInitInternal

	thumb_func_start ListMenuPrint
@ void ListMenuPrint(struct ListMenu *listMenu, u8 *str, u8 x, u8 y)
ListMenuPrint: @ 81AE9B4
	push {r4-r7,lr}
	sub sp, 0x18
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r12, r3
	ldr r5, =gUnknown_03006300
	ldrb r1, [r5, 0x3]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _081AEA20
	add r1, sp, 0x14
	ldr r2, [r5]
	lsls r0, r2, 24
	lsrs r0, 28
	movs r3, 0
	strb r0, [r1]
	lsls r0, r2, 28
	lsrs r0, 28
	strb r0, [r1, 0x1]
	lsls r0, r2, 20
	lsrs r0, 28
	strb r0, [r1, 0x2]
	ldrb r0, [r4, 0x10]
	lsls r1, r2, 1
	lsrs r1, 25
	lsls r2, 14
	lsrs r2, 26
	str r2, [sp]
	str r3, [sp, 0x4]
	add r2, sp, 0x14
	str r2, [sp, 0x8]
	movs r2, 0x1
	negs r2, r2
	str r2, [sp, 0xC]
	str r6, [sp, 0x10]
	adds r2, r7, 0
	mov r3, r12
	bl AddTextPrinterParametrized2
	ldrb r1, [r5, 0x3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r5, 0x3]
	b _081AEA5E
	.pool
_081AEA20:
	add r2, sp, 0x14
	ldrb r1, [r4, 0x15]
	lsls r0, r1, 28
	lsrs r0, 28
	strb r0, [r2]
	ldrb r0, [r4, 0x14]
	lsrs r0, 4
	strb r0, [r2, 0x1]
	adds r0, r2, 0
	lsls r1, 24
	lsrs r1, 28
	strb r1, [r0, 0x2]
	ldrb r0, [r4, 0x10]
	ldrb r1, [r4, 0x17]
	lsls r1, 26
	lsrs r1, 26
	ldrb r2, [r4, 0x16]
	lsls r2, 29
	lsrs r2, 29
	str r2, [sp]
	str r3, [sp, 0x4]
	add r2, sp, 0x14
	str r2, [sp, 0x8]
	movs r2, 0x1
	negs r2, r2
	str r2, [sp, 0xC]
	str r6, [sp, 0x10]
	adds r2, r7, 0
	mov r3, r12
	bl AddTextPrinterParametrized2
_081AEA5E:
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ListMenuPrint

	thumb_func_start ListMenuPrintEntries
@ void ListMenuPrintEntries(struct ListMenu *listMenu, u16 startIndex, u16 yOffset, u16 count)
ListMenuPrintEntries: @ 81AEA68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp]
	lsls r3, 16
	lsrs r3, 16
	mov r10, r3
	ldrb r0, [r4, 0x17]
	lsls r0, 26
	lsrs r0, 26
	movs r1, 0x1
	bl GetFontAttribute
	ldrb r1, [r4, 0x16]
	lsls r1, 26
	lsrs r1, 29
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r0, 0
	mov r8, r0
	cmp r8, r10
	bge _081AEB10
_081AEAAA:
	ldr r0, [r4]
	mov r2, r9
	lsls r1, r2, 3
	adds r0, r1, r0
	ldr r2, [r0, 0x4]
	movs r0, 0x3
	negs r0, r0
	adds r5, r1, 0
	cmp r2, r0
	beq _081AEAC2
	ldrb r6, [r4, 0x12]
	b _081AEAC4
_081AEAC2:
	ldrb r6, [r4, 0x11]
_081AEAC4:
	ldr r0, [sp]
	add r0, r8
	ldr r2, [sp, 0x4]
	adds r1, r0, 0
	muls r1, r2
	ldrb r0, [r4, 0x14]
	lsls r0, 28
	lsrs r0, 28
	adds r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r7, r2, 0
	ldr r3, [r4, 0x8]
	cmp r3, 0
	beq _081AEAEE
	ldrb r0, [r4, 0x10]
	ldr r1, [r4]
	adds r1, r5, r1
	ldr r1, [r1, 0x4]
	bl _call_via_r3
_081AEAEE:
	ldr r0, [r4]
	adds r0, r5, r0
	ldr r1, [r0]
	adds r0, r4, 0
	adds r2, r6, 0
	adds r3, r7, 0
	bl ListMenuPrint
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r0, 0x1
	add r8, r0
	cmp r8, r10
	blt _081AEAAA
_081AEB10:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ListMenuPrintEntries

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
