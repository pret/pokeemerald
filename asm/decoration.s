	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8127554
sub_8127554: @ 8127554
	push {r4,lr}
	ldr r4, =gUnknown_0203A18C
	ldr r0, [r4]
	ldr r2, =0x00000522
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _08127572
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x00000522
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_08127572:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127554

	thumb_func_start sub_8127580
sub_8127580: @ 8127580
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_81269D4
	adds r0, r4, 0
	bl sub_812759C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8127580

	thumb_func_start sub_812759C
sub_812759C: @ 812759C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	ldr r0, =gTasks + 0x8
	adds r5, r0
	movs r0, 0x3
	bl sub_81269D4
	ldr r0, =gUnknown_0203A173
	ldrb r0, [r0]
	bl sub_8127718
	ldr r6, =gUnknown_0203A18C
	ldr r0, =0x00000524
	bl AllocZeroed
	str r0, [r6]
	ldr r1, =0x00000522
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	bl sub_8127284
	bl sub_81272C8
	bl sub_81272F8
	adds r0, r4, 0
	bl sub_8127330
	ldr r0, =gUnknown_03006310
	ldr r1, =gUnknown_0203A170
	ldrh r1, [r1]
	ldr r2, =gUnknown_0203A16E
	ldrh r2, [r2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x1A]
	bl sub_8127500
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812759C

	thumb_func_start sub_8127620
sub_8127620: @ 8127620
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_812759C
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_812764C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127620

	thumb_func_start sub_812764C
sub_812764C: @ 812764C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08127700
	ldrb r0, [r5, 0x1A]
	bl ListMenuHandleInput
	adds r4, r0, 0
	ldrb r0, [r5, 0x1A]
	ldr r7, =gUnknown_0203A170
	ldr r1, =gUnknown_0203A16E
	mov r8, r1
	adds r1, r7, 0
	mov r2, r8
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081276A4
	adds r0, 0x1
	cmp r4, r0
	bne _081276C4
	b _08127700
	.pool
_081276A4:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_085A6B78
	movs r2, 0x16
	ldrsh r1, [r5, r2]
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r6, 0
	bl _call_via_r1
	b _08127700
	.pool
_081276C4:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0203A172
	strb r4, [r0]
	bl sub_8127554
	ldrb r0, [r5, 0x1A]
	adds r1, r7, 0
	mov r2, r8
	bl sub_81AE6C8
	movs r0, 0x1
	bl sub_8126A58
	bl sub_81277A8
	ldr r0, =gUnknown_0203A18C
	ldr r0, [r0]
	bl Free
	ldr r1, =gUnknown_085A6B78
	movs r2, 0x16
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl _call_via_r1
_08127700:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812764C

	thumb_func_start sub_8127718
sub_8127718: @ 8127718
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	bl sub_81269D4
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8126F68
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8127718

	thumb_func_start sub_8127744
sub_8127744: @ 8127744
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r0, =gUnknown_0203A188
	ldrb r5, [r0, 0x3]
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0203A151
	ldrb r0, [r0]
	cmp r4, r0
	bcc _08127770
	ldr r2, =gText_GoBackPrevMenu
	b _08127782
	.pool
_08127770:
	ldr r1, =gDecorations
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 5
	adds r1, 0x18
	adds r0, r1
	ldr r2, [r0]
_08127782:
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127744

	thumb_func_start sub_81277A8
sub_81277A8: @ 81277A8
	push {lr}
	movs r0, 0x3
	bl sub_8126A58
	movs r0, 0x2
	bl sub_8126A58
	pop {r0}
	bx r0
	thumb_func_end sub_81277A8

	thumb_func_start sub_81277BC
sub_81277BC: @ 81277BC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_0203A152
_081277C6:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081277D8
	movs r0, 0x1
	b _081277E4
	.pool
_081277D8:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _081277C6
	movs r0, 0
_081277E4:
	pop {r1}
	bx r1
	thumb_func_end sub_81277BC

	thumb_func_start sub_81277E8
sub_81277E8: @ 81277E8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_0203A162
_081277F2:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _08127804
	movs r0, 0x1
	b _08127810
	.pool
_08127804:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xB
	bls _081277F2
	movs r0, 0
_08127810:
	pop {r1}
	bx r1
	thumb_func_end sub_81277E8

	thumb_func_start sub_8127814
sub_8127814: @ 8127814
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	ldr r0, =gUnknown_0203A152
	movs r1, 0
	movs r2, 0x10
	bl memset
	ldr r0, =gUnknown_0203A162
	movs r1, 0
	movs r2, 0xC
	bl memset
	movs r6, 0
	ldr r0, =gSaveBlock1Ptr
	mov r10, r0
	ldr r1, =0x00001aae
	mov r9, r1
	ldr r3, =gUnknown_0203A173
	mov r8, r3
_08127842:
	mov r1, r10
	ldr r0, [r1]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _081278E2
	movs r2, 0
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, 3
	ldr r1, =gDecorationInventories
	adds r0, r1
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bcs _081278E2
	ldr r7, =gUnknown_0203A152
	adds r3, r1, 0
	mov r12, r3
_08127868:
	ldr r0, =gUnknown_0203A14C
	ldr r1, [r0]
	adds r1, r2
	mov r3, r10
	ldr r0, [r3]
	add r0, r9
	adds r0, r6
	ldrb r1, [r1]
	adds r4, r2, 0x1
	ldrb r0, [r0]
	cmp r1, r0
	bne _081278D0
	movs r1, 0
	cmp r1, r5
	bcs _081278A2
	ldrb r0, [r7]
	cmp r0, r4
	beq _081278A2
	ldr r3, =gUnknown_0203A152
	adds r2, r4, 0
_08127890:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r5
	bcs _081278A2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _08127890
_081278A2:
	cmp r1, r5
	bne _081278D0
	adds r0, r5, r7
	strb r4, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _081278E2
	.pool
_081278D0:
	lsls r0, r4, 16
	lsrs r2, r0, 16
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, 3
	add r0, r12
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bcc _08127868
_081278E2:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0xF
	bls _08127842
	movs r5, 0
	movs r6, 0
	ldr r3, =gDecorationInventories
	mov r8, r3
_081278F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000271c
	adds r0, r1
	adds r0, r6
	ldrb r0, [r0]
	adds r7, r6, 0x1
	cmp r0, 0
	beq _0812799A
	movs r2, 0
	b _0812798C
	.pool
_08127918:
	ldr r0, =gUnknown_0203A14C
	ldr r1, [r0]
	adds r1, r2
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x0000271c
	adds r0, r3
	adds r0, r6
	ldrb r1, [r1]
	adds r4, r2, 0x1
	ldrb r0, [r0]
	cmp r1, r0
	bne _08127988
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_81277BC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08127988
	movs r1, 0
	cmp r1, r5
	bcs _08127966
	ldr r2, =gUnknown_0203A162
	ldrb r0, [r2]
	cmp r0, r4
	beq _08127966
	adds r3, r2, 0
	adds r2, r4, 0
_08127954:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r5
	bcs _08127966
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _08127954
_08127966:
	cmp r1, r5
	bne _08127988
	ldr r0, =gUnknown_0203A162
	adds r0, r5, r0
	strb r4, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _0812799A
	.pool
_08127988:
	lsls r0, r4, 16
	lsrs r2, r0, 16
_0812798C:
	ldr r0, =gUnknown_0203A173
	ldrb r0, [r0]
	lsls r0, 3
	add r0, r8
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bcc _08127918
_0812799A:
	lsls r0, r7, 16
	lsrs r6, r0, 16
	cmp r6, 0xB
	bls _081278F4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127814

	thumb_func_start sub_81279B4
sub_81279B4: @ 81279B4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8127814
	pop {r0}
	bx r0
	thumb_func_end sub_81279B4

	thumb_func_start sub_81279C4
sub_81279C4: @ 81279C4
	push {r4,lr}
	movs r2, 0
	ldr r0, =gUnknown_0203A170
	ldrh r0, [r0]
	ldr r1, =gUnknown_0203A16E
	ldrh r1, [r1]
	adds r0, r1
	adds r1, r0, 0x1
	ldr r4, =gUnknown_0203A152
	ldr r3, =gUnknown_0203A162
_081279D8:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, r1
	beq _081279EC
	cmp r2, 0xB
	bhi _08127A00
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, r1
	bne _08127A00
_081279EC:
	movs r0, 0
	b _08127A0C
	.pool
_08127A00:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _081279D8
	movs r0, 0x1
_08127A0C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81279C4

	thumb_func_start sub_8127A14
sub_8127A14: @ 8127A14
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_81269D4
	adds r0, r4, 0
	bl sub_8127620
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8127A14

	thumb_func_start sub_8127A30
sub_8127A30: @ 8127A30
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8127A14
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127A30

	thumb_func_start sub_8127A5C
sub_8127A5C: @ 8127A5C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08127A82
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	movs r0, 0x1
	bl sub_81269D4
	adds r0, r4, 0
	bl sub_8127620
_08127A82:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127A5C

	thumb_func_start sub_8127A8C
sub_8127A8C: @ 8127A8C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_8127554
	bl sub_81277A8
	ldrb r0, [r4, 0x1A]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203A18C
	ldr r0, [r0]
	bl Free
	adds r0, r5, 0
	bl sub_8126E44
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127A8C

	thumb_func_start sub_8127ACC
sub_8127ACC: @ 8127ACC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r4, r2, r3
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrh r0, [r1]
	strh r0, [r4, 0xE]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x10]
	adds r3, 0x8
	adds r2, r3
	adds r1, r2, 0x2
	adds r0, r2, 0
	bl PlayerGetDestCoords
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127ACC

	thumb_func_start sub_8127B04
sub_8127B04: @ 8127B04
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	bl DrawWholeMapView
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	ldrb r1, [r1, 0x5]
	lsls r1, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	ldr r3, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r3
	movs r3, 0xE
	ldrsb r3, [r4, r3]
	ldrb r4, [r4, 0x10]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp]
	bl Overworld_SetWarpDestination
	bl warp_in
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127B04

	thumb_func_start sub_8127B54
sub_8127B54: @ 8127B54
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =0x0000ffff
	cmp r2, 0x22
	beq _08127B7C
	cmp r2, 0x26
	bne _08127B86
	ldr r0, =gUnknown_085A72E4
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 28
	lsrs r0, 16
	b _08127B86
	.pool
_08127B7C:
	ldr r0, =gUnknown_085A72EC
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 28
	lsrs r0, 16
_08127B86:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8127B54

	thumb_func_start sub_8127B90
sub_8127B90: @ 8127B90
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r4, [sp, 0x54]
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x4]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x8]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0xC]
	lsls r4, 16
	lsrs r4, 16
	str r4, [sp, 0x10]
	movs r2, 0
	lsls r0, r3, 16
	cmp r2, r3
	bcc _08127BC6
	b _08127D28
_08127BC6:
	ldr r1, [sp, 0x8]
	str r1, [sp, 0x28]
	str r0, [sp, 0x2C]
_08127BCC:
	ldr r3, [sp, 0x4]
	ldr r4, [sp, 0xC]
	subs r1, r3, r4
	lsls r0, r2, 16
	asrs r0, 16
	adds r0, 0x1
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x14]
	movs r0, 0
	mov r10, r0
	adds r1, r2, 0x1
	str r1, [sp, 0x30]
	ldr r3, [sp, 0x28]
	cmp r10, r3
	bcc _08127BF0
	b _08127D18
_08127BF0:
	ldr r4, [sp, 0x10]
	lsls r4, 5
	str r4, [sp, 0x18]
	ldr r0, =gDecorations + 0x1c
	adds r0, r4, r0
	str r0, [sp, 0x1C]
	ldr r0, =gDecorations
	adds r0, r4, r0
	str r0, [sp, 0x24]
	ldr r3, [sp, 0x8]
	adds r1, r2, 0
	muls r1, r3
	str r1, [sp, 0x20]
_08127C0A:
	ldr r0, [sp]
	add r0, r10
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, [sp, 0x20]
	add r1, r10
	ldr r4, [sp, 0x1C]
	ldr r0, [r4]
	lsls r1, 1
	adds r1, r0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl GetBehaviorByMetatileId
	lsls r4, r0, 16
	lsls r0, r4, 8
	lsrs r0, 24
	bl MetatileBehavior_IsMB_B9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08127C50
	ldr r3, [sp, 0x24]
	ldrb r0, [r3, 0x11]
	cmp r0, 0x1
	beq _08127C60
	lsrs r0, r4, 28
	cmp r0, 0
	beq _08127C60
_08127C50:
	movs r4, 0xC0
	lsls r4, 4
	mov r8, r4
	b _08127C64
	.pool
_08127C60:
	movs r0, 0
	mov r8, r0
_08127C64:
	ldr r1, [sp, 0x24]
	ldrb r0, [r1, 0x11]
	lsls r7, r5, 16
	ldr r2, [sp, 0x14]
	lsls r2, 16
	mov r9, r2
	cmp r0, 0x3
	beq _08127C8E
	asrs r0, r7, 16
	asrs r1, r2, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsMB_B7
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0x1
	cmp r0, 0x1
	beq _08127C90
_08127C8E:
	movs r6, 0
_08127C90:
	ldr r3, [sp, 0x18]
	ldr r4, =gDecorations
	adds r0, r3, r4
	ldrb r0, [r0]
	ldr r4, [sp, 0x20]
	add r4, r10
	lsls r1, r4, 24
	lsrs r1, 24
	bl sub_8127B54
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _08127CE0
	asrs r0, r7, 16
	mov r2, r9
	asrs r1, r2, 16
	ldr r3, [sp, 0x1C]
	ldr r2, [r3]
	lsls r3, r4, 1
	adds r3, r2
	movs r4, 0x80
	lsls r4, 2
	adds r2, r4, 0
	orrs r6, r2
	ldrh r3, [r3]
	adds r2, r6, r3
	mov r3, r8
	orrs r3, r2
	orrs r3, r5
	lsls r2, r3, 16
	lsrs r2, 16
	bl MapGridSetMetatileEntryAt
	b _08127D06
	.pool
_08127CE0:
	asrs r0, r7, 16
	mov r2, r9
	asrs r1, r2, 16
	ldr r3, [sp, 0x1C]
	ldr r2, [r3]
	lsls r3, r4, 1
	adds r3, r2
	movs r4, 0x80
	lsls r4, 2
	adds r2, r4, 0
	orrs r6, r2
	ldrh r3, [r3]
	adds r2, r6, r3
	mov r3, r8
	orrs r3, r2
	lsls r2, r3, 16
	lsrs r2, 16
	bl MapGridSetMetatileIdAt
_08127D06:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	ldr r4, [sp, 0x28]
	cmp r10, r4
	bcs _08127D18
	b _08127C0A
_08127D18:
	ldr r1, [sp, 0x30]
	lsls r0, r1, 16
	lsrs r2, r0, 16
	ldr r3, [sp, 0x2C]
	lsrs r0, r3, 16
	cmp r2, r0
	bcs _08127D28
	b _08127BCC
_08127D28:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8127B90

	thumb_func_start sub_8127D38
sub_8127D38: @ 8127D38
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gDecorations
	lsls r0, r2, 5
	adds r0, r1
	ldrb r0, [r0, 0x12]
	cmp r0, 0x9
	bhi _08127E10
	lsls r0, 2
	ldr r1, =_08127D68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08127D68:
	.4byte _08127D90
	.4byte _08127D9A
	.4byte _08127DA4
	.4byte _08127DB4
	.4byte _08127DBE
	.4byte _08127DC8
	.4byte _08127DD8
	.4byte _08127DE2
	.4byte _08127DF2
	.4byte _08127E02
_08127D90:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x1
	b _08127DAC
_08127D9A:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x2
	b _08127DAC
_08127DA4:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x3
_08127DAC:
	movs r3, 0x1
	bl sub_8127B90
	b _08127E10
_08127DB4:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x4
	b _08127DD0
_08127DBE:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x2
	b _08127DD0
_08127DC8:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x1
_08127DD0:
	movs r3, 0x2
	bl sub_8127B90
	b _08127E10
_08127DD8:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x1
	b _08127DFA
_08127DE2:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x2
	movs r3, 0x4
	bl sub_8127B90
	b _08127E10
_08127DF2:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x3
_08127DFA:
	movs r3, 0x3
	bl sub_8127B90
	b _08127E10
_08127E02:
	str r2, [sp]
	adds r0, r3, 0
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0x2
	bl sub_8127B90
_08127E10:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8127D38

	thumb_func_start sub_8127E18
sub_8127E18: @ 8127E18
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r6, 0
	ldr r7, =gMapHeader
	ldr r0, =gSpecialVar_0x8005
	mov r8, r0
	ldr r1, =gSpecialVar_0x8006
	mov r10, r1
	ldr r2, =gSaveBlock1Ptr
	mov r9, r2
_08127E34:
	adds r5, r6, 0
	adds r5, 0xAE
	adds r4, r5, 0
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08127F1C
	adds r0, r4, 0
	bl FlagClear
	movs r2, 0
	ldr r0, [r7, 0x4]
	ldrb r4, [r0]
	cmp r2, r4
	bcs _08127E82
	ldr r0, [r0, 0x4]
	ldrh r0, [r0, 0x14]
	cmp r0, r5
	beq _08127E82
	ldr r0, =gMapHeader
	ldr r3, [r0, 0x4]
	ldrb r6, [r3]
	adds r4, r5, 0
_08127E68:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r6
	bcs _08127E82
	ldr r0, [r3, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x14]
	cmp r0, r4
	bne _08127E68
_08127E82:
	ldr r0, [r7, 0x4]
	ldr r1, [r0, 0x4]
	lsls r4, r2, 1
	adds r4, r2
	lsls r4, 3
	adds r1, r4, r1
	ldr r5, =0x00003f20
	adds r0, r5, 0
	ldrb r1, [r1, 0x1]
	adds r0, r1
	ldr r1, =gUnknown_0203A190
	ldr r1, [r1]
	ldr r1, [r1, 0x1C]
	ldrh r1, [r1]
	bl VarSet
	ldr r0, [r7, 0x4]
	ldr r0, [r0, 0x4]
	adds r4, r0
	ldrb r0, [r4]
	mov r6, r8
	strh r0, [r6]
	ldr r1, =gUnknown_0203AA34
	ldrh r1, [r1]
	mov r2, r10
	strh r1, [r2]
	ldr r1, =gUnknown_0203AA36
	ldrh r1, [r1]
	ldr r4, =gSpecialVar_0x8007
	strh r1, [r4]
	mov r5, r9
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl show_sprite
	ldrb r0, [r6]
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	mov r6, r10
	movs r4, 0
	ldrsh r3, [r6, r4]
	ldr r5, =gSpecialVar_0x8007
	movs r6, 0
	ldrsh r4, [r5, r6]
	str r4, [sp]
	bl sub_808EBA8
	mov r1, r8
	ldrb r0, [r1]
	mov r4, r9
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl sub_808F254
	b _08127F26
	.pool
_08127F1C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xD
	bls _08127E34
_08127F26:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8127E18

	thumb_func_start sub_8127F38
sub_8127F38: @ 8127F38
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r2, [r0, 0x8]
	cmp r1, r2
	bcs _08127F62
	ldr r3, [r0]
_08127F46:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08127F58
	movs r0, 0x1
	b _08127F64
	.pool
_08127F58:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bcc _08127F46
_08127F62:
	movs r0, 0
_08127F64:
	pop {r1}
	bx r1
	thumb_func_end sub_8127F38

	thumb_func_start sub_8127F68
sub_8127F68: @ 8127F68
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A17C
	ldrb r0, [r0, 0x9]
	cmp r0, 0x1
	bne _08127FAC
	ldr r0, =gUnknown_0203A173
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _08127FAC
	cmp r0, 0x7
	beq _08127FAC
	ldr r4, =gStringVar4
	ldr r1, =gText_CantPlaceInRoom
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _0812804C
	.pool
_08127FAC:
	bl sub_81279C4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08128038
	bl sub_8127F38
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08127FE8
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_8128060
	str r1, [r0]
	b _0812804C
	.pool
_08127FE8:
	ldr r0, =gStringVar1
	ldr r4, =gUnknown_0203A17C
	ldrb r1, [r4, 0x8]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	bne _08128018
	ldr r0, =gStringVar4
	ldr r1, =gText_NoMoreDecorations
	bl StringExpandPlaceholders
	b _08128020
	.pool
_08128018:
	ldr r0, =gStringVar4
	ldr r1, =gText_NoMoreDecorations2
	bl StringExpandPlaceholders
_08128020:
	ldr r1, =gStringVar4
	ldr r2, =sub_8127A5C
	adds r0, r5, 0
	bl DisplayItemMessageOnField
	b _0812804C
	.pool
_08128038:
	ldr r4, =gStringVar4
	ldr r1, =gText_InUseAlready
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_0812804C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8127F68

	thumb_func_start sub_8128060
sub_8128060: @ 8128060
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r7, r0, r1
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	beq _081280AC
	cmp r0, 0x1
	bgt _08128088
	cmp r0, 0
	beq _0812808E
	b _08128112
	.pool
_08128088:
	cmp r0, 0x2
	beq _081280FC
	b _08128112
_0812808E:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08128112
	adds r0, r6, 0
	bl sub_8127ACC
	movs r0, 0x1
	strh r0, [r7, 0xC]
	b _08128112
	.pool
_081280AC:
	ldr r4, =gPaletteFade
	ldrb r0, [r4, 0x8]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r4, 0x8]
	ldr r5, =gUnknown_0203A190
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl ConfigureCameraObjectForPlacingDecoration
	adds r0, r6, 0
	bl sub_812826C
	adds r0, r6, 0
	adds r1, r5, 0
	bl SetUpPlacingDecorationPlayerAvatar
	bl pal_fill_black
	ldrb r1, [r4, 0x8]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r4, 0x8]
	movs r0, 0x2
	strh r0, [r7, 0xC]
	b _08128112
	.pool
_081280FC:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08128112
	movs r0, 0
	strh r0, [r7, 0x20]
	adds r0, r6, 0
	bl sub_8128FD8
_08128112:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8128060

	thumb_func_start ConfigureCameraObjectForPlacingDecoration
ConfigureCameraObjectForPlacingDecoration: @ 8128118
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0203AA38
	ldr r4, =gSprites
	ldr r5, =gUnknown_03005DD0
	ldr r2, [r5, 0x4]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2E]
	strb r0, [r3]
	adds r0, r6, 0
	bl gpu_pal_decompress_alloc_tag_and_upload
	lsls r0, 24
	lsrs r0, 24
	str r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r5, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, =sub_81292D0
	str r1, [r0]
	adds r2, r4
	ldr r3, =gUnknown_085A7250
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	strh r0, [r2, 0x20]
	ldr r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x3]
	strh r0, [r1, 0x22]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ConfigureCameraObjectForPlacingDecoration

	thumb_func_start SetUpPlacingDecorationPlayerAvatar
SetUpPlacingDecorationPlayerAvatar: @ 81281A8
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	ldrb r2, [r2, 0x12]
	ldr r3, =gUnknown_085A7250
	ldr r0, [r1]
	ldrb r4, [r0, 0x12]
	lsls r1, r4, 2
	adds r1, r3
	lsls r0, r2, 4
	ldrb r1, [r1, 0x2]
	adds r0, r1
	subs r2, 0x1
	lsls r2, 3
	subs r0, r2
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0x2
	beq _081281E2
	cmp r4, 0x8
	beq _081281E2
	cmp r4, 0x9
	bne _081281EA
_081281E2:
	adds r0, r2, 0
	subs r0, 0x8
	lsls r0, 24
	lsrs r2, r0, 24
_081281EA:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0812820C
	ldr r1, =SpriteCallbackDummy
	str r0, [sp]
	movs r0, 0xC1
	b _08128214
	.pool
_0812820C:
	ldr r1, =SpriteCallbackDummy
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC2
_08128214:
	movs r3, 0x48
	bl AddPseudoFieldObject
	ldr r1, =gUnknown_0203AA39
	strb r0, [r1]
	ldr r3, =gSprites
	ldr r0, =gUnknown_0203AA39
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r4, =gUnknown_0203AA38
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	bl DestroySprite
	ldr r0, =gUnknown_03005DD0
	ldr r0, [r0, 0x4]
	strb r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpPlacingDecorationPlayerAvatar

	thumb_func_start sub_812826C
sub_812826C: @ 812826C
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gDecorations
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 5
	adds r0, r2
	ldrb r0, [r0, 0x12]
	cmp r0, 0x9
	bls _0812828C
	b _081283B2
_0812828C:
	lsls r0, 2
	ldr r1, =_081282A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081282A8:
	.4byte _081282D0
	.4byte _081282E4
	.4byte _081282FC
	.4byte _08128314
	.4byte _08128328
	.4byte _0812833C
	.4byte _08128350
	.4byte _08128370
	.4byte _08128388
	.4byte _081283A0
_081282D0:
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	b _08128394
	.pool
_081282E4:
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0, 0x12]
	movs r1, 0x1
	b _081283B0
	.pool
_081282FC:
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r1, 0x3
	strh r1, [r0, 0x12]
	movs r1, 0x1
	b _081283B0
	.pool
_08128314:
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r1, 0x4
	b _081283AC
	.pool
_08128328:
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	b _08128394
	.pool
_0812833C:
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	b _081283AC
	.pool
_08128350:
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x12]
	movs r0, 0x3
	strh r0, [r1, 0x14]
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	b _081283B2
	.pool
_08128370:
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r1, 0x2
	strh r1, [r0, 0x12]
	movs r1, 0x4
	b _081283B0
	.pool
_08128388:
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	movs r0, 0x3
_08128394:
	strh r0, [r1, 0x12]
	strh r0, [r1, 0x14]
	b _081283B2
	.pool
_081283A0:
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	movs r1, 0x3
_081283AC:
	strh r1, [r0, 0x12]
	movs r1, 0x2
_081283B0:
	strh r1, [r0, 0x14]
_081283B2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812826C

	thumb_func_start sub_81283BC
sub_81283BC: @ 81283BC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	ldr r3, =gSprites
	ldr r0, =gUnknown_0203AA38
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r2, 0x1
	strh r2, [r0, 0x3C]
	ldr r0, =gUnknown_0203AA39
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x3C]
	bl sub_8128DE0
	adds r0, r4, 0
	bl sub_8128950
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81283BC

	thumb_func_start sub_8128414
sub_8128414: @ 8128414
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	ldr r3, =gSprites
	ldr r0, =gUnknown_0203AA38
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r2, 0x1
	strh r2, [r0, 0x3C]
	ldr r0, =gUnknown_0203AA39
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x3C]
	bl sub_8128DE0
	ldr r5, =gStringVar4
	ldr r1, =gText_CancelDecorating
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8128B80
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128414

	thumb_func_start sub_8128484
sub_8128484: @ 8128484
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	bl MetatileBehavior_IsMB_B3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812849E
	cmp r4, 0
	beq _081284A2
_0812849E:
	movs r0, 0
	b _081284A4
_081284A2:
	movs r0, 0x1
_081284A4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8128484

	thumb_func_start sub_81284AC
sub_81284AC: @ 81284AC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	lsls r1, 16
	asrs r1, 16
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	adds r0, 0x7
	cmp r1, r0
	bne _081284EC
	lsls r1, r4, 16
	asrs r1, 16
	movs r3, 0x10
	ldrsh r0, [r2, r3]
	adds r0, 0x7
	cmp r1, r0
	bne _081284EC
	cmp r5, 0
	beq _081284EC
	movs r0, 0
	b _081284EE
	.pool
_081284EC:
	movs r0, 0x1
_081284EE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81284AC

	thumb_func_start sub_81284F4
sub_81284F4: @ 81284F4
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_B3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08128534
	ldrb r0, [r5]
	cmp r0, 0x21
	bne _08128522
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_C2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08128530
_08128522:
	lsls r0, r6, 24
	lsrs r0, 24
	bl MetatileBehavior_IsNormal
	lsls r0, 24
	cmp r0, 0
	beq _08128534
_08128530:
	movs r0, 0x1
	b _08128536
_08128534:
	movs r0, 0
_08128536:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81284F4

	thumb_func_start sub_812853C
sub_812853C: @ 812853C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp]
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	ldrb r2, [r0, 0x14]
	str r2, [sp, 0x4]
	ldrb r0, [r0, 0x12]
	str r0, [sp, 0x8]
	ldr r3, [sp]
	ldrb r0, [r3, 0x11]
	adds r2, r1, 0
	cmp r0, 0x4
	bls _0812856E
	b _0812893C
_0812856E:
	lsls r0, 2
	ldr r1, =_08128580
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08128580:
	.4byte _08128594
	.4byte _08128594
	.4byte _08128680
	.4byte _08128834
	.4byte _081288B8
_08128594:
	movs r6, 0
	ldr r0, [sp, 0x4]
	cmp r6, r0
	bcc _0812859E
	b _0812893C
_0812859E:
	mov r1, r10
	lsls r1, 2
	str r1, [sp, 0x1C]
_081285A4:
	mov r2, r10
	lsls r0, r2, 2
	add r0, r10
	lsls r0, 3
	ldr r3, =gTasks
	adds r0, r3
	ldrh r0, [r0, 0xA]
	subs r0, r6
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r7, 0
	adds r6, 0x1
	str r6, [sp, 0x14]
	ldr r0, [sp, 0x8]
	cmp r7, r0
	bcs _0812866E
	mov r1, r9
	lsls r1, 16
	str r1, [sp, 0xC]
	asrs r1, 16
	mov r9, r1
_081285D0:
	ldr r0, [sp, 0x1C]
	add r0, r10
	lsls r0, 3
	ldr r2, =gTasks
	adds r0, r2
	ldrh r0, [r0, 0x8]
	adds r0, r7
	lsls r0, 16
	mov r8, r0
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r9
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, [sp, 0x4]
	ldr r1, [sp, 0x14]
	subs r0, r3, r1
	ldr r2, [sp, 0x8]
	adds r1, r0, 0
	muls r1, r2
	adds r1, r7
	ldr r3, [sp]
	ldr r0, [r3, 0x1C]
	lsls r1, 1
	adds r1, r0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl GetBehaviorByMetatileId
	movs r3, 0xF0
	lsls r3, 8
	adds r1, r3, 0
	adds r5, r1, 0
	ands r5, r0
	adds r0, r4, 0
	ldr r1, [sp]
	bl sub_81284F4
	lsls r0, 24
	cmp r0, 0
	bne _08128632
	b _0812890C
_08128632:
	mov r0, r10
	adds r1, r6, 0
	mov r2, r9
	adds r3, r5, 0
	bl sub_81284AC
	lsls r0, 24
	cmp r0, 0
	bne _08128646
	b _0812890C
_08128646:
	mov r1, r8
	lsrs r0, r1, 16
	ldr r2, [sp, 0xC]
	lsrs r1, r2, 16
	movs r2, 0
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08128662
	cmp r4, 0x10
	beq _08128662
	b _0812890C
_08128662:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcc _081285D0
_0812866E:
	ldr r1, [sp, 0x14]
	lsls r0, r1, 24
	lsrs r6, r0, 24
	ldr r2, [sp, 0x4]
	cmp r6, r2
	bcc _081285A4
	b _0812893C
	.pool
_08128680:
	movs r6, 0
	mov r3, r10
	lsls r3, 2
	str r3, [sp, 0x1C]
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x18]
	cmp r6, r0
	bge _0812876C
	adds r0, r3, 0
	add r0, r10
	lsls r0, 3
	str r0, [sp, 0x10]
_0812869A:
	ldr r1, [sp, 0x10]
	adds r0, r1, r2
	ldrh r0, [r0, 0xA]
	subs r0, r6
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r7, 0
	adds r6, 0x1
	str r6, [sp, 0x14]
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcs _08128760
	lsls r0, 16
	str r0, [sp, 0x20]
_081286B8:
	ldr r1, [sp, 0x10]
	adds r0, r1, r2
	ldrh r0, [r0, 0x8]
	adds r0, r7
	lsls r0, 16
	mov r8, r0
	asrs r6, r0, 16
	mov r2, r9
	lsls r1, r2, 16
	adds r0, r6, 0
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, [sp, 0x4]
	ldr r1, [sp, 0x14]
	subs r0, r3, r1
	ldr r2, [sp, 0x8]
	adds r1, r0, 0
	muls r1, r2
	adds r1, r7
	ldr r3, [sp]
	ldr r0, [r3, 0x1C]
	lsls r1, 1
	adds r1, r0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl GetBehaviorByMetatileId
	movs r3, 0xF0
	lsls r3, 8
	adds r1, r3, 0
	adds r5, r1, 0
	ands r5, r0
	adds r0, r4, 0
	bl MetatileBehavior_IsNormal
	lsls r0, 24
	cmp r0, 0
	bne _08128724
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8128484
	lsls r0, 24
	cmp r0, 0
	bne _08128724
	b _0812890C
_08128724:
	mov r0, r10
	adds r1, r6, 0
	ldr r3, [sp, 0x20]
	asrs r2, r3, 16
	adds r3, r5, 0
	bl sub_81284AC
	lsls r0, 24
	cmp r0, 0
	bne _0812873A
	b _0812890C
_0812873A:
	mov r1, r8
	lsrs r0, r1, 16
	ldr r2, [sp, 0x20]
	lsrs r1, r2, 16
	movs r2, 0
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _08128752
	b _0812890C
_08128752:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gTasks
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcc _081286B8
_08128760:
	ldr r1, [sp, 0x14]
	lsls r0, r1, 24
	lsrs r6, r0, 24
	ldr r3, [sp, 0x18]
	cmp r6, r3
	blt _0812869A
_0812876C:
	ldr r0, [sp, 0x1C]
	add r0, r10
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0xA]
	ldr r1, [sp, 0x4]
	subs r0, r1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r7, 0
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcc _0812878C
	b _0812893C
_0812878C:
	lsls r0, 16
	str r0, [sp, 0x20]
_08128790:
	ldr r0, [sp, 0x1C]
	add r0, r10
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldrh r0, [r0, 0x8]
	adds r0, r7
	lsls r0, 16
	mov r8, r0
	asrs r6, r0, 16
	mov r2, r9
	lsls r1, r2, 16
	adds r0, r6, 0
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, [sp]
	ldr r0, [r3, 0x1C]
	lsls r1, r7, 1
	adds r1, r0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl GetBehaviorByMetatileId
	movs r3, 0xF0
	lsls r3, 8
	adds r1, r3, 0
	adds r5, r1, 0
	ands r5, r0
	adds r0, r4, 0
	bl MetatileBehavior_IsNormal
	lsls r0, 24
	cmp r0, 0
	bne _081287F2
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_B7
	lsls r0, 24
	cmp r0, 0
	bne _081287F2
	b _0812890C
_081287F2:
	mov r0, r10
	adds r1, r6, 0
	ldr r3, [sp, 0x20]
	asrs r2, r3, 16
	adds r3, r5, 0
	bl sub_81284AC
	lsls r0, 24
	cmp r0, 0
	bne _08128808
	b _0812890C
_08128808:
	mov r1, r8
	lsrs r0, r1, 16
	ldr r2, [sp, 0x20]
	lsrs r1, r2, 16
	movs r2, 0
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08128822
	cmp r4, 0x10
	bne _0812890C
_08128822:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcc _08128790
	b _0812893C
	.pool
_08128834:
	movs r6, 0
	ldr r0, [sp, 0x4]
	cmp r6, r0
	bcc _0812883E
	b _0812893C
_0812883E:
	mov r1, r10
	lsls r0, r1, 2
	add r0, r10
	lsls r1, r0, 3
	ldr r2, =gTasks
	adds r0, r1, r2
	ldrh r0, [r0, 0xA]
	subs r0, r6
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r7, 0
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcs _081288A4
	adds r0, r2, 0
	adds r1, r0
	mov r8, r1
	mov r1, r9
	lsls r0, r1, 16
	asrs r5, r0, 16
_08128868:
	mov r2, r8
	ldrh r0, [r2, 0x8]
	adds r0, r7
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsMB_B7
	lsls r0, 24
	cmp r0, 0
	beq _0812890C
	adds r0, r4, 0
	adds r1, r5, 0x1
	bl MapGridGetMetatileIdAt
	movs r1, 0xA3
	lsls r1, 2
	cmp r0, r1
	beq _0812890C
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcc _08128868
_081288A4:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [sp, 0x4]
	cmp r6, r0
	bcc _0812883E
	b _0812893C
	.pool
_081288B8:
	mov r3, r10
	lsls r1, r3, 2
	adds r0, r1, r3
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0xA]
	mov r9, r0
	movs r7, 0
	str r1, [sp, 0x1C]
	ldr r0, [sp, 0x8]
	cmp r7, r0
	bcs _0812893C
	adds r6, r2, 0
	mov r1, r9
	lsls r1, 16
	str r1, [sp, 0x20]
_081288D8:
	ldr r0, [sp, 0x1C]
	add r0, r10
	lsls r0, 3
	adds r0, r6
	ldrh r0, [r0, 0x8]
	adds r0, r7
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	mov r2, r9
	lsls r1, r2, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, [sp]
	ldrb r0, [r3, 0x12]
	cmp r0, 0x5
	bne _08128910
_08128900:
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_C3
	lsls r0, 24
	cmp r0, 0
	bne _0812891C
_0812890C:
	movs r0, 0
	b _0812893E
_08128910:
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_B5
	lsls r0, 24
	cmp r0, 0
	beq _08128900
_0812891C:
	adds r0, r5, 0
	ldr r2, [sp, 0x20]
	lsrs r1, r2, 16
	movs r2, 0
	bl GetFieldObjectIdByXYZ
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bne _0812890C
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r3, [sp, 0x8]
	cmp r7, r3
	bcc _081288D8
_0812893C:
	movs r0, 0x1
_0812893E:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812853C

	thumb_func_start sub_8128950
sub_8128950: @ 8128950
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r1, 5
	ldr r0, =gDecorations
	adds r1, r0
	adds r0, r5, 0
	bl sub_812853C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081289A4
	ldr r4, =gStringVar4
	ldr r1, =gText_PlaceItHere
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_81289D0
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _081289BE
	.pool
_081289A4:
	movs r0, 0x20
	bl PlaySE
	ldr r4, =gStringVar4
	ldr r1, =gText_CantBePlacedHere
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8129020
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_081289BE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128950

	thumb_func_start sub_81289D0
sub_81289D0: @ 81289D0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A72C4
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81289D0

	thumb_func_start sub_81289F0
sub_81289F0: @ 81289F0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_8128AAC
	ldr r2, =gDecorations
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	ldrb r3, [r0]
	lsls r0, r3, 5
	adds r0, r2
	ldrb r0, [r0, 0x11]
	cmp r0, 0x4
	beq _08128A44
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	ldrh r1, [r1, 0xA]
	adds r2, r3, 0
	bl sub_8127D38
	b _08128A64
	.pool
_08128A44:
	ldr r2, =gUnknown_0203AA34
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	subs r0, 0x7
	strh r0, [r2]
	ldr r2, =gUnknown_0203AA36
	ldrh r0, [r1, 0xA]
	subs r0, 0x7
	strh r0, [r2]
	ldr r0, =gUnknown_08275D1F
	bl ScriptContext1_SetupScript
_08128A64:
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AA38
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x22]
	adds r1, 0x2
	strh r1, [r0, 0x22]
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	cmp r0, 0x56
	bne _08128A84
	bl sub_80EE104
_08128A84:
	adds r0, r4, 0
	bl sub_8128BBC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81289F0

	thumb_func_start sub_8128AAC
sub_8128AAC: @ 8128AAC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r3, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	adds r5, r0, 0
	cmp r3, r1
	bcs _08128AD2
	ldr r4, [r5]
_08128AC0:
	adds r2, r4, r3
	ldrb r0, [r2]
	cmp r0, 0
	beq _08128AF0
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	bcc _08128AC0
_08128AD2:
	ldrb r0, [r5, 0x9]
	cmp r0, 0
	bne _08128B3C
	movs r3, 0
	ldr r0, =gUnknown_0203A152
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0
	bne _08128B28
	b _08128B48
	.pool
_08128AF0:
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r2, [r5, 0x4]
	adds r2, r3
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x8]
	subs r0, 0x7
	lsls r0, 4
	ldrb r1, [r1, 0xA]
	subs r1, 0x7
	adds r0, r1
	strb r0, [r2]
	b _08128AD2
	.pool
_08128B28:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0xF
	bhi _08128B76
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _08128B28
	b _08128B6E
_08128B3C:
	movs r3, 0
	ldr r0, =gUnknown_0203A162
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0
	bne _08128B5C
_08128B48:
	ldr r0, =gUnknown_0203A172
	ldrb r0, [r0]
	adds r0, 0x1
	strb r0, [r2]
	b _08128B76
	.pool
_08128B5C:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0xB
	bhi _08128B76
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _08128B5C
_08128B6E:
	ldr r0, =gUnknown_0203A172
	ldrb r0, [r0]
	adds r0, 0x1
	strb r0, [r1]
_08128B76:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128AAC

	thumb_func_start sub_8128B80
sub_8128B80: @ 8128B80
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A72CC
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128B80

	thumb_func_start sub_8128BA0
sub_8128BA0: @ 8128BA0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_8128BBC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8128BA0

	thumb_func_start sub_8128BBC
sub_8128BBC: @ 8128BBC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =c1_overworld_prev_quest
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128BBC

	thumb_func_start c1_overworld_prev_quest
c1_overworld_prev_quest: @ 8128BEC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08128C10
	cmp r0, 0x1
	beq _08128C30
	b _08128C4C
	.pool
_08128C10:
	bl ScriptContext2_Enable
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08128C4C
	adds r0, r4, 0
	bl sub_8127B04
	movs r0, 0x1
	strh r0, [r5, 0xC]
	b _08128C4C
	.pool
_08128C30:
	bl sub_812A3C8
	ldr r0, =0x00000be5
	bl FreeSpritePaletteByTag
	ldr r1, =gFieldCallback
	ldr r0, =sub_8128CD4
	str r0, [r1]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08128C4C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c1_overworld_prev_quest

	thumb_func_start sub_8128C64
sub_8128C64: @ 8128C64
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08128C9C
	cmp r0, 0x1
	bgt _08128C8C
	cmp r0, 0
	beq _08128C96
	b _08128CCA
	.pool
_08128C8C:
	cmp r0, 0x2
	beq _08128CA8
	cmp r0, 0x3
	beq _08128CB4
	b _08128CCA
_08128C96:
	bl sub_80E9578
	b _08128CAC
_08128C9C:
	ldr r0, =gUnknown_08275D0C
	bl ScriptContext1_SetupScript
	b _08128CAC
	.pool
_08128CA8:
	bl ScriptContext2_Enable
_08128CAC:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	b _08128CCA
_08128CB4:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08128CCA
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_812764C
	str r1, [r0]
_08128CCA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128C64

	thumb_func_start sub_8128CD4
sub_8128CD4: @ 8128CD4
	push {r4,lr}
	bl ScriptContext2_Enable
	bl pal_fill_black
	ldr r0, =sub_8128C64
	movs r1, 0x8
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8127580
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128CD4

	thumb_func_start sub_8128D10
sub_8128D10: @ 8128D10
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	ldr r0, =gUnknown_0203AA3A
	ldrb r1, [r0]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _08128D48
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r4, 0xC
	ldrsh r1, [r2, r4]
	subs r0, r1
	subs r0, 0x6
	cmp r0, 0
	bge _08128D48
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	b _08128D62
	.pool
_08128D48:
	ldrb r0, [r3]
	cmp r0, 0x2
	bne _08128D6C
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	subs r1, 0x7
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r1, r0
	blt _08128D6C
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
_08128D62:
	strh r0, [r2, 0x2]
	movs r0, 0
	b _08128DAE
	.pool
_08128D6C:
	ldrb r0, [r3]
	cmp r0, 0x3
	bne _08128D82
	movs r1, 0
	ldrsh r0, [r2, r1]
	subs r0, 0x7
	cmp r0, 0
	bge _08128D82
	ldrh r0, [r2]
	adds r0, 0x1
	b _08128DA2
_08128D82:
	ldrb r0, [r3]
	cmp r0, 0x4
	bne _08128DAC
	movs r3, 0
	ldrsh r1, [r2, r3]
	movs r4, 0xA
	ldrsh r0, [r2, r4]
	adds r1, r0
	subs r1, 0x8
	ldr r0, =gMapHeader
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	blt _08128DAC
	ldrh r0, [r2]
	subs r0, 0x1
_08128DA2:
	strh r0, [r2]
	movs r0, 0
	b _08128DAE
	.pool
_08128DAC:
	movs r0, 0x1
_08128DAE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8128D10

	thumb_func_start sub_8128DB4
sub_8128DB4: @ 8128DB4
	push {lr}
	ldr r0, =gMain
	ldrh r0, [r0, 0x2C]
	movs r1, 0xF0
	ands r1, r0
	cmp r1, 0x40
	beq _08128DD8
	cmp r1, 0x80
	beq _08128DD8
	cmp r1, 0x20
	beq _08128DD8
	cmp r1, 0x10
	beq _08128DD8
	movs r0, 0
	b _08128DDA
	.pool
_08128DD8:
	movs r0, 0x1
_08128DDA:
	pop {r1}
	bx r1
	thumb_func_end sub_8128DB4

	thumb_func_start sub_8128DE0
sub_8128DE0: @ 8128DE0
	push {r4,lr}
	ldr r1, =gUnknown_0203AA3A
	movs r0, 0
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203AA38
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r2, 0
	strh r2, [r0, 0x32]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128DE0

	thumb_func_start sub_8128E18
sub_8128E18: @ 8128E18
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r2, r0, 24
	mov r8, r2
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r5, =gSprites
	ldr r3, =gUnknown_0203AA38
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x36
	ldrsh r6, [r0, r1]
	cmp r6, 0
	beq _08128E46
	b _08128F66
_08128E46:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08128E68
	ldr r0, =gUnknown_085A72D4
	movs r3, 0x18
	ldrsh r1, [r4, r3]
	lsls r1, 3
	b _08128E76
	.pool
_08128E68:
	cmp r0, 0x2
	bne _08128E88
	ldr r0, =gUnknown_085A72D4
	movs r3, 0x18
	ldrsh r1, [r4, r3]
	lsls r1, 3
	adds r0, 0x4
_08128E76:
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	bl _call_via_r1
	b _08128FBA
	.pool
_08128E88:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r7, 0xF0
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x40
	bne _08128EBC
	ldr r1, =gUnknown_0203AA3A
	movs r0, 0x1
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x34]
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
_08128EBC:
	ldrh r1, [r2, 0x2C]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x80
	bne _08128EEC
	ldr r1, =gUnknown_0203AA3A
	movs r0, 0x2
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x2
	strh r1, [r0, 0x34]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
_08128EEC:
	ldrh r1, [r2, 0x2C]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x20
	bne _08128F1C
	ldr r1, =gUnknown_0203AA3A
	movs r0, 0x3
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x32]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x34]
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
_08128F1C:
	ldrh r1, [r2, 0x2C]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0x10
	bne _08128F4C
	ldr r1, =gUnknown_0203AA3A
	movs r0, 0x4
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x2
	strh r1, [r0, 0x32]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x34]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_08128F4C:
	bl sub_8128DB4
	lsls r0, 24
	cmp r0, 0
	beq _08128F62
	mov r0, r8
	bl sub_8128D10
	lsls r0, 24
	cmp r0, 0
	bne _08128F66
_08128F62:
	bl sub_8128DE0
_08128F66:
	ldr r0, =gUnknown_0203AA3A
	ldrb r0, [r0]
	cmp r0, 0
	beq _08128F94
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203AA38
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x36]
	adds r1, 0x1
	strh r1, [r0, 0x36]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrh r2, [r1, 0x36]
	movs r0, 0x7
	ands r0, r2
	strh r0, [r1, 0x36]
_08128F94:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08128FBA
	ldr r3, =gMain
	ldrh r1, [r3, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08128FAC
	strh r2, [r4, 0x14]
_08128FAC:
	ldrh r1, [r3, 0x2E]
	movs r2, 0x2
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08128FBA
	strh r2, [r4, 0x14]
_08128FBA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128E18

	thumb_func_start sub_8128FD8
sub_8128FD8: @ 8128FD8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AA38
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0
	strh r2, [r0, 0x3C]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0x1C]
	ldr r1, =sub_8128E18
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8128FD8

	thumb_func_start sub_8129020
sub_8129020: @ 8129020
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0812903A
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08129040
_0812903A:
	adds r0, r2, 0
	bl sub_8128FD8
_08129040:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129020

	thumb_func_start sub_8129048
sub_8129048: @ 8129048
	push {lr}
	sub sp, 0x4
	adds r1, r0, 0
	mov r2, sp
	movs r0, 0
	strh r0, [r2]
	ldr r2, =0x01000452
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129048

	thumb_func_start sub_8129068
sub_8129068: @ 8129068
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldr r0, =gTilesetPointer_SecretBase
	ldr r0, [r0]
	lsrs r1, 11
	ldr r0, [r0, 0x8]
	adds r0, r1
	adds r1, r2, 0
	movs r2, 0x8
	bl CpuFastSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129068

	thumb_func_start sub_8129088
sub_8129088: @ 8129088
	push {r4-r7,lr}
	sub sp, 0x20
	adds r7, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	lsrs r4, r1, 26
	adds r5, r4, 0
	cmp r2, 0
	beq _0812909E
	ldr r0, =0x000003ff
	ands r2, r0
_0812909E:
	ldr r0, =gTilesetPointer_SecretBase
	ldr r0, [r0]
	lsls r1, r2, 5
	ldr r0, [r0, 0x4]
	adds r0, r1
	mov r1, sp
	movs r2, 0x8
	bl CpuFastSet
	cmp r4, 0x1
	beq _081290DE
	cmp r4, 0x1
	bgt _081290C8
	cmp r4, 0
	beq _081290D2
	b _0812919A
	.pool
_081290C8:
	cmp r5, 0x2
	beq _0812913E
	cmp r5, 0x3
	beq _08129176
	b _0812919A
_081290D2:
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x8
	bl CpuFastSet
	b _0812919A
_081290DE:
	movs r5, 0
	movs r6, 0xF
_081290E2:
	lsls r4, r5, 2
	adds r4, r7
	adds r5, 0x1
	lsls r3, r5, 2
	subs r0, r3, 0x1
	add r0, sp
	ldrb r2, [r0]
	lsrs r1, r2, 4
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 4
	adds r1, r0
	strb r1, [r4]
	subs r0, r3, 0x2
	add r0, sp
	ldrb r2, [r0]
	lsrs r1, r2, 4
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 4
	adds r1, r0
	strb r1, [r4, 0x1]
	subs r0, r3, 0x3
	add r0, sp
	ldrb r2, [r0]
	lsrs r1, r2, 4
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 4
	adds r1, r0
	strb r1, [r4, 0x2]
	subs r3, 0x4
	mov r1, sp
	adds r0, r1, r3
	ldrb r2, [r0]
	lsrs r1, r2, 4
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 4
	adds r1, r0
	strb r1, [r4, 0x3]
	lsls r5, 16
	lsrs r5, 16
	cmp r5, 0x7
	bls _081290E2
	b _0812919A
_0812913E:
	movs r5, 0
	movs r3, 0x7
_08129142:
	lsls r2, r5, 2
	adds r2, r7
	subs r1, r3, r5
	lsls r1, 2
	mov r4, sp
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r0, r1, 0x1
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r2, 0x1]
	adds r0, r1, 0x2
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r2, 0x2]
	adds r1, 0x3
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r2, 0x3]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x7
	bls _08129142
	b _0812919A
_08129176:
	movs r5, 0
	movs r4, 0x1F
	movs r6, 0xF
_0812917C:
	adds r3, r7, r5
	subs r0, r4, r5
	add r0, sp
	ldrb r2, [r0]
	lsrs r1, r2, 4
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 4
	adds r1, r0
	strb r1, [r3]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x1F
	bls _0812917C
_0812919A:
	add sp, 0x20
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8129088

	thumb_func_start sub_81291A4
sub_81291A4: @ 81291A4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
_081291AA:
	lsls r0, r4, 5
	adds r0, 0x84
	adds r0, r5, r0
	lsls r2, r4, 1
	adds r1, r5, 0x4
	adds r1, r2
	ldrh r1, [r1]
	bl sub_8129088
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3F
	bls _081291AA
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81291A4

	thumb_func_start sub_81291CC
sub_81291CC: @ 81291CC
	lsls r0, 16
	ldr r1, =gTilesetPointer_SecretBaseRedCave
	ldr r1, [r1]
	ldr r1, [r1, 0xC]
	lsrs r0, 15
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x00000fff
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_81291CC

	thumb_func_start sub_81291E8
sub_81291E8: @ 81291E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, [r0]
	ldrb r0, [r0, 0x12]
	movs r6, 0
	ldr r1, =gUnknown_085A71B0
	lsls r5, r0, 4
	adds r0, r5, r1
	ldrb r0, [r0, 0xC]
	cmp r6, r0
	bcs _0812924C
	adds r7, r1, 0
_08129204:
	mov r4, r8
	ldm r4!, {r1}
	adds r0, r7, 0x4
	adds r0, r5, r0
	ldr r0, [r0]
	adds r0, r6
	ldrb r0, [r0]
	ldr r1, [r1, 0x1C]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	adds r1, r7, 0
	adds r1, 0x8
	adds r1, r5, r1
	ldr r1, [r1]
	adds r1, r6
	lsls r0, 3
	ldrb r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bl sub_81291CC
	adds r2, r5, r7
	ldr r1, [r2]
	adds r1, r6
	ldrb r1, [r1]
	lsls r1, 1
	adds r4, r1
	strh r0, [r4]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r2, [r2, 0xC]
	cmp r6, r2
	bcc _08129204
_0812924C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81291E8

	thumb_func_start sub_812925C
sub_812925C: @ 812925C
	push {r4,r5,lr}
	lsls r0, 24
	ldr r3, =gUnknown_0203AA3C
	movs r1, 0
	strb r1, [r3]
	ldrb r2, [r3, 0x1]
	subs r1, 0x4
	ands r1, r2
	movs r5, 0xD
	negs r5, r5
	ands r1, r5
	movs r2, 0x11
	negs r2, r2
	ands r1, r2
	subs r2, 0x10
	ands r1, r2
	strb r1, [r3, 0x1]
	ldr r1, =gUnknown_085A7250
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0]
	movs r4, 0x3F
	lsls r1, 6
	strb r1, [r3, 0x1]
	ldrh r2, [r3, 0x2]
	ldr r1, =0xfffffe00
	ands r1, r2
	strh r1, [r3, 0x2]
	ldrb r2, [r3, 0x3]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	strb r1, [r3, 0x3]
	ldrb r0, [r0, 0x1]
	lsls r0, 6
	ands r4, r1
	orrs r4, r0
	strb r4, [r3, 0x3]
	ldrh r1, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r1
	strh r0, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	ands r5, r0
	movs r0, 0xF
	ands r5, r0
	strb r5, [r3, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812925C

	thumb_func_start sub_81292D0
sub_81292D0: @ 81292D0
	movs r1, 0
	strh r1, [r0, 0x32]
	strh r1, [r0, 0x34]
	strh r1, [r0, 0x36]
	strh r1, [r0, 0x38]
	strh r1, [r0, 0x3A]
	strh r1, [r0, 0x3C]
	ldr r1, =sub_81292E8
	str r1, [r0, 0x1C]
	bx lr
	.pool
	thumb_func_end sub_81292D0

	thumb_func_start sub_81292E8
sub_81292E8: @ 81292E8
	push {lr}
	adds r2, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _08129322
	movs r1, 0x3A
	ldrsh r0, [r2, r1]
	cmp r0, 0xE
	bgt _0812930A
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	b _08129314
_0812930A:
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
_08129314:
	strb r0, [r3]
	ldrh r0, [r2, 0x3A]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r2, 0x3A]
	b _0812932E
_08129322:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0812932E:
	pop {r0}
	bx r0
	thumb_func_end sub_81292E8

	thumb_func_start gpu_pal_decompress_alloc_tag_and_upload
gpu_pal_decompress_alloc_tag_and_upload: @ 8129334
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	bl sub_8129048
	lsls r4, 5
	ldr r0, =gDecorations
	adds r4, r0
	str r4, [r5]
	ldrb r0, [r4, 0x11]
	cmp r0, 0x4
	beq _081293B4
	ldr r0, =0x00000be5
	bl FreeSpritePaletteByTag
	adds r0, r5, 0
	bl sub_81291E8
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	bl sub_812925C
	adds r0, r5, 0
	bl sub_81291A4
	ldr r1, =0x00000884
	adds r0, r5, r1
	ldr r1, =gTilesetPointer_SecretBaseRedCave
	ldr r2, [r1]
	ldr r1, [r5]
	ldr r1, [r1, 0x1C]
	ldrh r1, [r1]
	ldr r2, [r2, 0xC]
	lsls r1, 4
	adds r1, r2
	ldrh r1, [r1, 0xE]
	lsrs r1, 12
	bl sub_8129068
	ldr r0, =gUnknown_085A72BC
	bl LoadSpritePalette
	ldr r0, =gUnknown_085A728C
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	b _081293C6
	.pool
_081293B4:
	ldr r0, [r4, 0x1C]
	ldrh r0, [r0]
	ldr r1, =SpriteCallbackDummy
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0
	movs r3, 0
	bl AddPseudoFieldObject
_081293C6:
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end gpu_pal_decompress_alloc_tag_and_upload

	thumb_func_start AddDecorationIconObjectFromIconTable
@ u8 AddDecorationIconObjectFromIconTable(u16 tilesTag, u16 paletteTag, u8 decorationId)
AddDecorationIconObjectFromIconTable: @ 81293D8
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 24
	lsrs r5, r2, 24
	bl AllocItemIconTemporaryBuffers
	lsls r0, 24
	cmp r0, 0
	beq _08129490
	adds r0, r5, 0
	movs r1, 0
	bl GetDecorationIconPicOrPalette
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
	bl GetDecorationIconPicOrPalette
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
	adds r1, r5, 0
	ldr r0, =gUnknown_08614FF4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
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
	b _08129492
	.pool
_08129490:
	movs r0, 0x40
_08129492:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AddDecorationIconObjectFromIconTable

	thumb_func_start GetDecorationIconPicOrPalette
@ u32 GetDecorationIconPicOrPalette(u16 decorationId, u8 which)
GetDecorationIconPicOrPalette: @ 812949C
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r3, 0x78
	bls _081294AC
	movs r3, 0
_081294AC:
	ldr r2, =gUnknown_085A6BE8
	lsls r0, 2
	lsls r1, r3, 3
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetDecorationIconPicOrPalette

	thumb_func_start AddDecorationIconObjectFromFieldObject
@ u8 AddDecorationIconObjectFromFieldObject(u16 tilesTag, u16 paletteTag, u8 decorationId)
AddDecorationIconObjectFromFieldObject: @ 81294C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r4, r2, 0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gUnknown_0203A190
	adds r0, r6, 0
	bl sub_8129048
	lsls r4, 5
	ldr r0, =gDecorations
	adds r4, r0
	str r4, [r6]
	ldrb r0, [r4, 0x11]
	cmp r0, 0x4
	beq _081295A4
	adds r0, r6, 0
	bl sub_81291E8
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	bl sub_812925C
	adds r0, r6, 0
	bl sub_81291A4
	ldr r0, =0x00000884
	adds r5, r6, r0
	ldr r0, =gTilesetPointer_SecretBaseRedCave
	ldr r1, [r0]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	ldrh r0, [r0]
	ldr r1, [r1, 0xC]
	lsls r0, 4
	adds r0, r1
	ldrh r1, [r0, 0xE]
	lsrs r1, 12
	adds r0, r5, 0
	bl sub_8129068
	adds r0, r6, 0
	adds r0, 0x84
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_085A72F4
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 21
	ldr r4, =0xffff0000
	mov r2, r8
	lsls r1, r2, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	bl LoadSpriteSheet
	str r5, [sp, 0xC]
	add r0, sp, 0xC
	ldr r1, [r0, 0x4]
	ands r1, r4
	orrs r1, r7
	str r1, [r0, 0x4]
	bl LoadSpritePalette
	movs r0, 0x18
	bl Alloc
	adds r4, r0, 0
	adds r1, r4, 0
	ldr r0, =gUnknown_085A72A4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r3, r8
	strh r3, [r4]
	strh r7, [r4, 0x2]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl Free
	b _081295BA
	.pool
_081295A4:
	ldr r0, [r4, 0x1C]
	ldrh r0, [r0]
	ldr r1, =SpriteCallbackDummy
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0
	movs r3, 0
	bl AddPseudoFieldObject
	lsls r0, 24
	lsrs r5, r0, 24
_081295BA:
	adds r0, r5, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddDecorationIconObjectFromFieldObject

	thumb_func_start AddDecorationIconObject
@ u8 AddDecorationIconObject(u8 decorationId, u16 x, u16 y, u8 priority, u16 tilesTag, u16 paletteTag)
AddDecorationIconObject: @ 81295CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	lsls r0, 24
	lsrs r6, r0, 24
	mov r12, r6
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	mov r9, r8
	lsls r2, 16
	lsrs r7, r2, 16
	mov r10, r7
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	lsls r4, 16
	lsrs r4, 16
	adds r3, r4, 0
	lsls r5, 16
	lsrs r5, 16
	adds r2, r5, 0
	cmp r6, 0x78
	bls _08129634
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl AddDecorationIconObjectFromIconTable
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x40
	beq _08129696
	ldr r2, =gSprites
	lsls r3, r4, 4
	adds r1, r3, r4
	lsls r1, 2
	adds r1, r2
	mov r5, r8
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, 0x4
	strh r0, [r1, 0x24]
	lsls r0, r7, 16
	b _081296B2
	.pool
_08129634:
	ldr r0, =gUnknown_085A6BE8
	lsls r1, r6, 3
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	bne _08129684
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl AddDecorationIconObjectFromFieldObject
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x40
	beq _08129696
	ldr r1, =gSprites
	lsls r2, r4, 4
	adds r0, r2, r4
	lsls r0, 2
	adds r5, r0, r1
	mov r0, r8
	strh r0, [r5, 0x24]
	adds r0, r6, 0
	subs r0, 0x2A
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08129680
	lsls r0, r7, 16
	asrs r0, 16
	subs r0, 0x4
	strh r0, [r5, 0x26]
	b _081296BC
	.pool
_08129680:
	strh r7, [r5, 0x26]
	b _081296BC
_08129684:
	adds r0, r3, 0
	adds r1, r2, 0
	mov r2, r12
	bl AddDecorationIconObjectFromIconTable
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x40
	bne _0812969A
_08129696:
	movs r0, 0x40
	b _081296D8
_0812969A:
	ldr r2, =gSprites
	lsls r3, r4, 4
	adds r1, r3, r4
	lsls r1, 2
	adds r1, r2
	mov r5, r9
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, 0x4
	strh r0, [r1, 0x24]
	mov r5, r10
	lsls r0, r5, 16
_081296B2:
	asrs r0, 16
	adds r0, 0x4
	strh r0, [r1, 0x26]
	adds r1, r2, 0
	adds r2, r3, 0
_081296BC:
	adds r2, r4
	lsls r2, 2
	adds r2, r1
	movs r0, 0x3
	ldr r1, [sp]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r0, r4, 0
_081296D8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddDecorationIconObject

	thumb_func_start sub_81296EC
sub_81296EC: @ 81296EC
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_0203A17C
	ldr r1, [r3]
	adds r1, r0
	movs r2, 0
	strb r2, [r1]
	ldr r1, [r3, 0x4]
	adds r1, r0
	strb r2, [r1]
	bx lr
	.pool
	thumb_func_end sub_81296EC

	thumb_func_start sub_8129708
sub_8129708: @ 8129708
	push {r4-r6,lr}
	ldr r6, =gSpecialVar_0x8005
	movs r0, 0
	strh r0, [r6]
	ldr r2, =gScriptResult
	strh r0, [r2]
	ldr r4, =gSpecialVar_0x8004
	ldr r1, =gUnknown_0203AAC4
	ldrh r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08129744
	movs r0, 0x1
	strh r0, [r2]
	b _08129796
	.pool
_08129738:
	ldr r1, =gSpecialVar_0x8006
	ldrb r0, [r2]
	strh r0, [r1]
	b _08129796
	.pool
_08129744:
	ldr r3, =gDecorations
	ldr r2, =gUnknown_0203A17C
	ldr r1, =gUnknown_0203AA44
	ldrh r0, [r4]
	lsls r0, 3
	adds r4, r0, r1
	ldrb r1, [r4]
	ldr r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 5
	adds r0, r3
	ldrb r0, [r0, 0x11]
	cmp r0, 0x4
	bne _08129796
	ldrh r0, [r4, 0x4]
	strh r0, [r6]
	ldrb r0, [r4]
	bl sub_81296EC
	movs r1, 0
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	ldrb r2, [r0]
	cmp r1, r2
	bcs _08129796
	ldr r5, [r0, 0x4]
	ldrh r4, [r6]
	adds r3, r2, 0
_0812977E:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0, r5
	ldrh r0, [r2, 0x14]
	cmp r0, r4
	beq _08129738
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r3
	bcc _0812977E
_08129796:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129708

	thumb_func_start sub_81297AC
sub_81297AC: @ 81297AC
	push {r4-r6,lr}
	movs r2, 0
	ldr r0, =gMapHeader
	ldr r0, [r0, 0x4]
	ldrb r1, [r0]
	cmp r2, r1
	bcs _081297F0
	adds r3, r0, 0
	ldr r5, [r3, 0x4]
	ldr r0, =gSpecialVar_0x8004
	ldrh r4, [r0]
	ldr r6, =gSpecialVar_0x8005
_081297C4:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r5
	ldrh r0, [r1, 0x14]
	cmp r0, r4
	bne _081297E4
	ldrb r0, [r1]
	strh r0, [r6]
	b _081297F0
	.pool
_081297E4:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r3]
	cmp r2, r0
	bcc _081297C4
_081297F0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81297AC

	thumb_func_start sub_81297F8
sub_81297F8: @ 81297F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r6, 0
	b _081298BE
_08129808:
	ldr r3, =gUnknown_0203AA44
	lsls r5, r6, 3
	adds r4, r5, r3
	ldrb r1, [r4]
	ldr r2, =gUnknown_0203A17C
	ldr r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 5
	ldr r7, =gDecorations
	adds r0, r7
	ldrb r2, [r0, 0x11]
	ldr r7, =gUnknown_0203A17C
	ldr r0, [r7, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	lsrs r1, r0, 4
	mov r8, r1
	movs r7, 0xF
	adds r1, r7, 0
	ands r1, r0
	str r1, [sp]
	adds r7, r5, 0
	adds r6, 0x1
	str r6, [sp, 0x4]
	cmp r2, 0x4
	beq _081298B8
	movs r6, 0
	ldrb r4, [r4, 0x2]
	cmp r6, r4
	bcs _081298AE
_08129846:
	movs r4, 0
	adds r0, r5, r3
	adds r2, r6, 0x1
	mov r10, r2
	ldrb r0, [r0, 0x1]
	cmp r4, r0
	bcs _0812989C
	ldr r3, =gUnknown_0203AA44
	adds r3, r7
	mov r9, r3
	subs r5, r6, 0x7
	str r5, [sp, 0x8]
_0812985E:
	adds r0, r4, 0x7
	add r0, r8
	ldr r1, =gMapHeader
	ldr r3, [r1]
	ldr r1, [sp]
	subs r2, r1, r6
	ldr r1, [r3]
	muls r2, r1
	mov r5, r8
	adds r1, r5, r4
	adds r1, r2
	ldr r2, [r3, 0xC]
	lsls r1, 1
	adds r1, r2
	ldrh r1, [r1]
	movs r3, 0xC0
	lsls r3, 6
	adds r2, r3, 0
	orrs r2, r1
	ldr r5, [sp]
	ldr r3, [sp, 0x8]
	subs r1, r5, r3
	bl MapGridSetMetatileEntryAt
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r5, r9
	ldrb r5, [r5, 0x1]
	cmp r4, r5
	bcc _0812985E
_0812989C:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r6, r0, 24
	ldr r3, =gUnknown_0203AA44
	adds r5, r7, 0
	adds r0, r7, r3
	ldrb r0, [r0, 0x2]
	cmp r6, r0
	bcc _08129846
_081298AE:
	ldr r2, =gUnknown_0203AA44
	adds r0, r7, r2
	ldrb r0, [r0]
	bl sub_81296EC
_081298B8:
	ldr r3, [sp, 0x4]
	lsls r0, r3, 24
	lsrs r6, r0, 24
_081298BE:
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08129808
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81297F8

	thumb_func_start sub_81298EC
sub_81298EC: @ 81298EC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08129928
	cmp r0, 0x1
	bgt _08129914
	cmp r0, 0
	beq _0812991E
	b _08129994
	.pool
_08129914:
	cmp r0, 0x2
	beq _08129954
	cmp r0, 0x3
	beq _08129968
	b _08129994
_0812991E:
	bl sub_81297F8
	movs r0, 0x1
	strh r0, [r4, 0xC]
	b _08129994
_08129928:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08129994
	bl DrawWholeMapView
	ldr r0, =gUnknown_08275D2E
	bl ScriptContext1_SetupScript
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	movs r0, 0x2
	strh r0, [r4, 0xC]
	b _08129994
	.pool
_08129954:
	bl ScriptContext2_Enable
	adds r0, r5, 0
	bl sub_8127814
	bl pal_fill_black
	movs r0, 0x3
	strh r0, [r4, 0xC]
	b _08129994
_08129968:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08129994
	ldr r4, =gStringVar4
	ldr r1, =gText_DecorationReturnedToPC
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8129D64
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	ldr r0, =gMapHeader
	ldrb r0, [r0, 0x14]
	cmp r0, 0x56
	bne _08129994
	bl sub_80EE104
_08129994:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81298EC

	thumb_func_start sub_81299AC
sub_81299AC: @ 81299AC
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r2, [r0, 0x8]
	cmp r1, r2
	bcs _081299D6
	ldr r3, [r0]
_081299BA:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081299CC
	movs r0, 0x1
	b _081299D8
	.pool
_081299CC:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bcc _081299BA
_081299D6:
	movs r0, 0
_081299D8:
	pop {r1}
	bx r1
	thumb_func_end sub_81299AC

	thumb_func_start SetUpPuttingAwayDecorationPlayerAvatar
SetUpPuttingAwayDecorationPlayerAvatar: @ 81299DC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	bl player_get_direction_lower_nybble
	ldr r3, =gUnknown_0203AA38
	ldr r2, =gSprites
	ldr r4, =gUnknown_03005DD0
	ldr r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x2E]
	strb r0, [r3]
	bl sub_812A39C
	ldr r0, =gUnknown_085A7404
	movs r1, 0x78
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	str r0, [r4, 0x4]
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08129A3C
	ldr r1, =SpriteCallbackDummy
	str r0, [sp]
	movs r0, 0xC1
	b _08129A44
	.pool
_08129A3C:
	ldr r1, =SpriteCallbackDummy
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC2
_08129A44:
	movs r2, 0x88
	movs r3, 0x48
	bl AddPseudoFieldObject
	ldr r1, =gUnknown_0203AA39
	strb r0, [r1]
	ldr r6, =gSprites
	ldr r0, =gUnknown_0203AA39
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	movs r2, 0x4
	mov r8, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r5, =gUnknown_0203AA38
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
	ldr r0, =gUnknown_03005DD0
	ldr r0, [r0, 0x4]
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x5]
	ands r4, r1
	mov r1, r8
	orrs r4, r1
	strb r4, [r0, 0x5]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetUpPuttingAwayDecorationPlayerAvatar

	thumb_func_start sub_8129ABC
sub_8129ABC: @ 8129ABC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08129B0C
	cmp r0, 0x1
	bgt _08129AE4
	cmp r0, 0
	beq _08129AEA
	b _08129B2E
	.pool
_08129AE4:
	cmp r0, 0x2
	beq _08129B1A
	b _08129B2E
_08129AEA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08129B2E
	adds r0, r5, 0
	bl sub_8127ACC
	movs r0, 0x1
	strh r0, [r4, 0x4]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xA]
	b _08129B2E
	.pool
_08129B0C:
	bl SetUpPuttingAwayDecorationPlayerAvatar
	bl pal_fill_black
	movs r0, 0x2
	strh r0, [r4, 0x4]
	b _08129B2E
_08129B1A:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08129B2E
	strh r0, [r4, 0x18]
	adds r0, r5, 0
	bl sub_8129B34
_08129B2E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8129ABC

	thumb_func_start sub_8129B34
sub_8129B34: @ 8129B34
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203AA38
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r6, 0
	strh r6, [r0, 0x3C]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_812A36C
	str r1, [r0]
	ldr r2, =gUnknown_0203AA39
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x88
	strh r1, [r0, 0x20]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x48
	strh r1, [r0, 0x22]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0x1C]
	ldr r1, =sub_8128E18
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129B34

	thumb_func_start sub_8129BCC
sub_8129BCC: @ 8129BCC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	bl sub_8128DE0
	adds r0, r4, 0
	bl sub_8129C74
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129BCC

	thumb_func_start sub_8129BF8
sub_8129BF8: @ 8129BF8
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x1C]
	bl sub_8128DE0
	ldr r3, =gSprites
	ldr r5, =gUnknown_0203AA38
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldr r5, =gStringVar4
	ldr r1, =gText_StopPuttingAwayDecorations
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A1F0
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129BF8

	thumb_func_start sub_8129C74
sub_8129C74: @ 8129C74
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_812A0E8
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08129CA8
	ldr r4, =gStringVar4
	ldr r1, =gText_ReturnDecorationToPC
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A1A0
	b _08129D14
	.pool
_08129CA8:
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl MetatileBehavior_IsSecretBasePC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08129CDE
	adds r0, r4, 0
	bl MetatileBehavior_IsMB_C5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08129D3C
_08129CDE:
	ldr r3, =gSprites
	ldr r4, =gUnknown_0203AA38
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldr r4, =gStringVar4
	ldr r1, =gText_StopPuttingAwayDecorations
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A1F0
_08129D14:
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _08129D50
	.pool
_08129D3C:
	ldr r4, =gStringVar4
	ldr r1, =gText_NoDecorationHere
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8129D64
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_08129D50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129C74

	thumb_func_start sub_8129D64
sub_8129D64: @ 8129D64
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08129D7E
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08129D84
_08129D7E:
	adds r0, r2, 0
	bl sub_8129B34
_08129D84:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129D64

	thumb_func_start sub_8129D8C
sub_8129D8C: @ 8129D8C
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	ldr r1, =gDecorations
	lsrs r0, 19
	adds r0, r1
	ldrb r1, [r0, 0x12]
	cmp r1, 0
	bne _08129DA8
	movs r0, 0x1
	strb r0, [r2, 0x1]
	b _08129E06
	.pool
_08129DA8:
	cmp r1, 0x1
	bne _08129DB4
	movs r0, 0x2
	strb r0, [r2, 0x1]
	strb r1, [r2, 0x2]
	b _08129E08
_08129DB4:
	cmp r1, 0x2
	bne _08129DC0
	movs r0, 0x3
	strb r0, [r2, 0x1]
	movs r0, 0x1
	b _08129E06
_08129DC0:
	cmp r1, 0x3
	bne _08129DC8
	movs r0, 0x4
	b _08129E02
_08129DC8:
	cmp r1, 0x4
	bne _08129DD2
	movs r0, 0x2
	strb r0, [r2, 0x1]
	b _08129E06
_08129DD2:
	cmp r1, 0x5
	bne _08129DDA
	movs r0, 0x1
	b _08129E02
_08129DDA:
	cmp r1, 0x6
	bne _08129DE6
	movs r0, 0x1
	strb r0, [r2, 0x1]
	movs r0, 0x3
	b _08129E06
_08129DE6:
	cmp r1, 0x7
	bne _08129DF2
	movs r0, 0x2
	strb r0, [r2, 0x1]
	movs r0, 0x4
	b _08129E06
_08129DF2:
	cmp r1, 0x8
	bne _08129DFC
	movs r0, 0x3
	strb r0, [r2, 0x1]
	b _08129E06
_08129DFC:
	cmp r1, 0x9
	bne _08129E08
	movs r0, 0x3
_08129E02:
	strb r0, [r2, 0x1]
	movs r0, 0x2
_08129E06:
	strb r0, [r2, 0x2]
_08129E08:
	pop {r0}
	bx r0
	thumb_func_end sub_8129D8C

	thumb_func_start sub_8129E0C
sub_8129E0C: @ 8129E0C
	push {r4-r6,lr}
	lsls r0, 24
	lsls r1, 24
	ldr r5, =gSprites
	ldr r6, =gUnknown_0203AA38
	ldrb r3, [r6]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r5
	adds r2, 0x3E
	ldrb r3, [r2]
	movs r4, 0x4
	orrs r3, r4
	strb r3, [r2]
	ldrb r3, [r6]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r3, r5, 0
	adds r3, 0x1C
	adds r2, r3
	ldr r3, =SpriteCallbackDummy
	str r3, [r2]
	ldr r4, =gUnknown_0203AA39
	ldrb r3, [r4]
	lsls r2, r3, 4
	adds r2, r3
	lsls r2, 2
	adds r2, r5
	lsrs r0, 20
	adds r0, 0x88
	strh r0, [r2, 0x20]
	ldrb r2, [r4]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	lsrs r1, 20
	adds r1, 0x48
	strh r1, [r0, 0x22]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8129E0C

	thumb_func_start sub_8129E74
sub_8129E74: @ 8129E74
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r2
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	ldrb r0, [r2, 0x8]
	subs r0, 0x7
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r2, 0xA]
	subs r0, 0x7
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gUnknown_0203A17C
	ldr r0, [r2, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	lsrs r5, r0, 4
	movs r6, 0xF
	ands r6, r0
	mov r0, r9
	ldrb r4, [r0, 0x2]
	ldr r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x29
	bne _08129ED4
	adds r0, r5, 0x7
	adds r1, r6, 0x7
	bl MapGridGetMetatileIdAt
	movs r1, 0xA3
	lsls r1, 2
	cmp r0, r1
	bne _08129ED4
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_08129ED4:
	cmp r7, r5
	bcc _08129F10
	mov r0, r9
	ldrb r2, [r0, 0x1]
	adds r0, r5, r2
	cmp r7, r0
	bge _08129F10
	subs r0, r6, r4
	cmp r8, r0
	ble _08129F10
	cmp r8, r6
	bhi _08129F10
	subs r0, r7, r5
	adds r0, 0x1
	subs r0, r2, r0
	lsls r0, 24
	lsrs r0, 24
	mov r2, r8
	subs r1, r6, r2
	lsls r1, 24
	lsrs r1, 24
	bl sub_8129E0C
	movs r0, 0x1
	b _08129F12
	.pool
_08129F10:
	movs r0, 0
_08129F12:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8129E74

	thumb_func_start sub_8129F20
sub_8129F20: @ 8129F20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, =gUnknown_0203A17C
	ldr r3, =gUnknown_0203AA44
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r3
	ldrb r1, [r0]
	ldr r0, [r2, 0x4]
	adds r0, r1
	ldrb r0, [r0]
	lsrs r1, r0, 4
	mov r8, r1
	movs r6, 0xF
	ands r6, r0
	movs r4, 0
	ldr r7, =gSaveBlock1Ptr
	mov r9, r3
_08129F4A:
	ldr r1, [r7]
	lsls r0, r4, 1
	adds r0, r4
	lsls r5, r0, 3
	adds r1, r5
	ldr r2, =0x00000c74
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r8
	bne _08129FB0
	ldr r2, =0x00000c76
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r6
	bne _08129FB0
	ldr r2, =0x00000c84
	adds r0, r1, r2
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08129FB0
	ldr r0, =gUnknown_0203AAC4
	ldrb r1, [r0]
	lsls r1, 3
	add r1, r9
	ldr r0, [r7]
	adds r0, r5
	ldr r2, =0x00000c84
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1, 0x4]
	b _08129FBA
	.pool
_08129FB0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3F
	bls _08129F4A
_08129FBA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8129F20

	thumb_func_start sub_8129FC8
sub_8129FC8: @ 8129FC8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	b _0812A02A
_08129FD2:
	ldr r0, [r0]
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0
	beq _0812A024
	ldr r0, =gDecorations
	ldrb r2, [r1]
	lsls r1, r2, 5
	adds r1, r0
	ldrb r0, [r1, 0x11]
	cmp r0, 0x4
	bne _0812A024
	ldr r5, =gUnknown_0203AA44
	adds r0, r2, 0
	adds r1, r5, 0
	bl sub_8129D8C
	lsls r1, r6, 24
	lsrs r1, 24
	adds r0, r7, 0
	adds r2, r5, 0
	bl sub_8129E74
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0812A024
	strb r6, [r5]
	bl sub_8129F20
	ldr r0, =gUnknown_0203AAC4
	strb r4, [r0]
	movs r0, 0x1
	b _0812A034
	.pool
_0812A024:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_0812A02A:
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r6, r1
	bcc _08129FD2
	movs r0, 0
_0812A034:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8129FC8

	thumb_func_start sub_812A040
sub_812A040: @ 812A040
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	movs r4, 0
	ldr r7, =gUnknown_0203A17C
	ldrb r0, [r7, 0x8]
	cmp r4, r0
	bcs _0812A0C6
	adds r6, r7, 0
	ldr r5, =gUnknown_0203AAC4
_0812A072:
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	ldr r0, [r6, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	lsrs r3, r0, 4
	movs r2, 0xF
	ands r2, r0
	cmp r1, 0
	beq _0812A0BA
	ldr r0, =gDecorations
	lsls r1, 5
	adds r1, r0
	ldrb r0, [r1, 0x11]
	cmp r0, 0x4
	bne _0812A0BA
	ldr r0, [sp]
	cmp r0, r3
	bhi _0812A0BA
	cmp r10, r2
	bhi _0812A0BA
	cmp r9, r3
	bcc _0812A0BA
	cmp r8, r2
	bcc _0812A0BA
	ldr r0, =gUnknown_0203AA44
	ldrb r1, [r5]
	lsls r1, 3
	adds r1, r0
	strb r4, [r1]
	bl sub_8129F20
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
_0812A0BA:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r7, 0x8]
	cmp r4, r0
	bcc _0812A072
_0812A0C6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A040

	thumb_func_start sub_812A0E8
sub_812A0E8: @ 812A0E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_0203AAC4
	movs r0, 0
	strb r0, [r4]
	adds r0, r6, 0
	bl sub_8129FC8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0812A18C
	movs r5, 0
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r5, r1
	bcs _0812A15A
	adds r7, r4, 0
_0812A10E:
	ldr r0, [r0]
	adds r0, r5
	ldrb r1, [r0]
	cmp r1, 0
	beq _0812A14C
	ldr r4, =gUnknown_0203AA44
	adds r0, r1, 0
	adds r1, r4, 0
	bl sub_8129D8C
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8129E74
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A14C
	strb r5, [r4]
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	b _0812A15A
	.pool
_0812A14C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203A17C
	ldrb r1, [r0, 0x8]
	cmp r5, r1
	bcc _0812A10E
_0812A15A:
	ldr r0, =gUnknown_0203AAC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812A18C
	ldr r0, =gUnknown_0203A17C
	ldr r2, =gUnknown_0203AA44
	ldrb r1, [r2]
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldrb r1, [r0]
	lsrs r0, r1, 4
	movs r3, 0xF
	ands r3, r1
	ldrb r1, [r2, 0x2]
	subs r1, r3, r1
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r2, 0x1]
	adds r2, r0
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	bl sub_812A040
_0812A18C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A0E8

	thumb_func_start sub_812A1A0
sub_812A1A0: @ 812A1A0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A7348
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1A0

	thumb_func_start sub_812A1C0
sub_812A1C0: @ 812A1C0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_81298EC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1C0

	thumb_func_start sub_812A1F0
sub_812A1F0: @ 812A1F0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A7350
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A1F0

	thumb_func_start sub_812A210
sub_812A210: @ 812A210
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_812A22C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812A210

	thumb_func_start sub_812A22C
sub_812A22C: @ 812A22C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r1, =sub_812A25C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A22C

	thumb_func_start sub_812A25C
sub_812A25C: @ 812A25C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _0812A280
	cmp r0, 0x1
	beq _0812A29C
	b _0812A2B2
	.pool
_0812A280:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812A2B2
	adds r0, r4, 0
	bl sub_8127B04
	movs r0, 0x1
	strh r0, [r5, 0xC]
	b _0812A2B2
	.pool
_0812A29C:
	bl sub_812A3C8
	ldr r0, =gFieldCallback
	ldr r1, =sub_812A334
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_0812A2B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A25C

	thumb_func_start sub_812A2C4
sub_812A2C4: @ 812A2C4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r5, r1, 3
	ldr r6, =gTasks + 0x8
	adds r4, r5, r6
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0812A2FC
	cmp r0, 0x1
	bgt _0812A2EC
	cmp r0, 0
	beq _0812A2F6
	b _0812A32A
	.pool
_0812A2EC:
	cmp r0, 0x2
	beq _0812A308
	cmp r0, 0x3
	beq _0812A314
	b _0812A32A
_0812A2F6:
	bl sub_80E9578
	b _0812A30C
_0812A2FC:
	ldr r0, =gUnknown_08275D0C
	bl ScriptContext1_SetupScript
	b _0812A30C
	.pool
_0812A308:
	bl ScriptContext2_Enable
_0812A30C:
	ldrh r0, [r4, 0x4]
	adds r0, 0x1
	strh r0, [r4, 0x4]
	b _0812A32A
_0812A314:
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A32A
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r5, r0
	ldr r1, =sub_8126B80
	str r1, [r0]
_0812A32A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A2C4

	thumb_func_start sub_812A334
sub_812A334: @ 812A334
	push {lr}
	bl pal_fill_black
	movs r0, 0
	movs r1, 0x1
	bl sub_81973C4
	bl sub_8126ABC
	ldr r0, =sub_812A2C4
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0xC]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A334

	thumb_func_start sub_812A36C
sub_812A36C: @ 812A36C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r2, 0x2E]
	cmp r0, 0xF
	ble _0812A38C
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _0812A398
_0812A38C:
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0812A398:
	pop {r0}
	bx r0
	thumb_func_end sub_812A36C

	thumb_func_start sub_812A39C
sub_812A39C: @ 812A39C
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0812A3B8
	ldr r0, =gUnknown_085A73D8
	bl LoadSpritePalette
	b _0812A3BE
	.pool
_0812A3B8:
	ldr r0, =gUnknown_085A73E0
	bl LoadSpritePalette
_0812A3BE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A39C

	thumb_func_start sub_812A3C8
sub_812A3C8: @ 812A3C8
	push {lr}
	movs r0, 0x8
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_812A3C8

	thumb_func_start sub_812A3D4
sub_812A3D4: @ 812A3D4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81279C4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0812A430
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_0203A172
	ldrb r2, [r1]
	ldr r1, =gUnknown_0203A14C
	ldr r1, [r1]
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 5
	ldr r2, =gDecorations + 1
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_DecorationWillBeDiscarded
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_812A458
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	b _0812A444
	.pool
_0812A430:
	ldr r4, =gStringVar4
	ldr r1, =gText_CantThrowAwayInUse
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
_0812A444:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A3D4

	thumb_func_start sub_812A458
sub_812A458: @ 812A458
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_085A741C
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A458

	thumb_func_start sub_812A478
sub_812A478: @ 812A478
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r5, =gUnknown_0203A173
	ldrb r0, [r5]
	bl CountDecorationCategoryN
	ldr r1, =gUnknown_0203A151
	strb r0, [r1]
	ldrb r0, [r5]
	bl CondenseDecorationCategoryN
	adds r0, r4, 0
	bl sub_8127814
	ldr r5, =gStringVar4
	ldr r1, =gText_DecorationThrownAway
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_8127A5C
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A478

	.align 2, 0 @ Don't pad with nop.
