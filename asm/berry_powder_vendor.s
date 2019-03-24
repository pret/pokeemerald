	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8024668
sub_8024668: @ 8024668
	ldr r1, =gSaveBlock2Ptr
	ldr r1, [r1]
	adds r1, 0xAC
	ldr r0, [r0]
	ldr r1, [r1]
	eors r0, r1
	bx lr
	.pool
	thumb_func_end sub_8024668

	thumb_func_start SetBerryPowder
SetBerryPowder: @ 802467C
	ldr r2, =gSaveBlock2Ptr
	ldr r2, [r2]
	adds r2, 0xAC
	ldr r2, [r2]
	eors r2, r1
	str r2, [r0]
	bx lr
	.pool
	thumb_func_end SetBerryPowder

	thumb_func_start ApplyNewEncryptionKeyToBerryPowder
ApplyNewEncryptionKeyToBerryPowder: @ 8024690
	push {lr}
	adds r1, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r2, 0xFA
	lsls r2, 1
	adds r0, r2
	bl ApplyNewEncryptionKeyToWord
	pop {r0}
	bx r0
	.pool
	thumb_func_end ApplyNewEncryptionKeyToBerryPowder

	thumb_func_start sub_80246AC
sub_80246AC: @ 80246AC
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	bl sub_8024668
	cmp r0, r4
	bcc _080246CC
	movs r0, 0x1
	b _080246CE
	.pool
_080246CC:
	movs r0, 0
_080246CE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80246AC

	thumb_func_start sub_80246D4
sub_80246D4: @ 80246D4
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	bl sub_8024668
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	cmp r0, r1
	bcc _080246F8
	movs r0, 0x1
	b _080246FA
	.pool
_080246F8:
	movs r0, 0
_080246FA:
	pop {r1}
	bx r1
	thumb_func_end sub_80246D4

	thumb_func_start sub_8024700
sub_8024700: @ 8024700
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r5, r0, r1
	adds r0, r5, 0
	bl sub_8024668
	adds r1, r0, r4
	ldr r2, =0x0001869f @ Note to decompiler: See UNKNOWN_OFFSET
	cmp r1, r2
	bhi _08024730
	adds r0, r5, 0
	bl SetBerryPowder
	movs r0, 0x1
	b _0802473A
	.pool
_08024730:
	adds r0, r5, 0
	adds r1, r2, 0
	bl SetBerryPowder
	movs r0, 0
_0802473A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024700

	thumb_func_start sub_8024740
sub_8024740: @ 8024740
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r4, r0, r1
	adds r0, r5, 0
	bl sub_80246AC
	lsls r0, 24
	cmp r0, 0
	beq _08024774
	adds r0, r4, 0
	bl sub_8024668
	adds r1, r0, 0
	subs r1, r5
	adds r0, r4, 0
	bl SetBerryPowder
	movs r0, 0x1
	b _08024776
	.pool
_08024774:
	movs r0, 0
_08024776:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8024740

	thumb_func_start sub_802477C
sub_802477C: @ 802477C
	push {r4,r5,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r4, r0, r1
	ldr r5, =gSpecialVar_0x8004
	ldrh r0, [r5]
	bl sub_80246AC
	lsls r0, 24
	cmp r0, 0
	beq _080247B4
	adds r0, r4, 0
	bl sub_8024668
	adds r1, r0, 0
	ldrh r0, [r5]
	subs r1, r0
	adds r0, r4, 0
	bl SetBerryPowder
	movs r0, 0x1
	b _080247B6
	.pool
_080247B4:
	movs r0, 0
_080247B6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_802477C

	thumb_func_start sub_80247BC
sub_80247BC: @ 80247BC
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r1
	bl sub_8024668
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80247BC

	thumb_func_start sub_80247D4
sub_80247D4: @ 80247D4
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x24]
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gStringVar1
	mov r9, r0
	movs r2, 0x1
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	mov r2, r9
	mov r3, r8
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80247D4

	thumb_func_start sub_802482C
sub_802482C: @ 802482C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r8, r3
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl DrawStdFrameWithCustomTileAndPalette
	ldr r2, =gText_Powder
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	str r4, [sp]
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0x1A
	movs r3, 0x11
	bl sub_80247D4
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802482C

	thumb_func_start sub_802488C
sub_802488C: @ 802488C
	push {lr}
	sub sp, 0x4
	bl sub_80247BC
	adds r1, r0, 0
	ldr r0, =gUnknown_02022C94
	ldrb r0, [r0]
	movs r2, 0
	str r2, [sp]
	movs r2, 0x1A
	movs r3, 0x11
	bl sub_80247D4
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802488C

	thumb_func_start sub_80248B0
sub_80248B0: @ 80248B0
	push {r4,r5,lr}
	sub sp, 0x18
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x1C
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl SetWindowTemplateFields
	ldr r4, =gUnknown_02022C94
	add r0, sp, 0x10
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	ldr r5, =0x0000021d
	adds r1, r5, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	ldrb r4, [r4]
	bl sub_80247BC
	adds r3, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xD
	bl sub_802482C
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80248B0

	thumb_func_start sub_8024918
sub_8024918: @ 8024918
	push {r4,lr}
	ldr r4, =gUnknown_02022C94
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	movs r1, 0x1
	bl ClearStdWindowAndFrameToTransparent
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8024918

	.align 2, 0 @ don't pad with nop
