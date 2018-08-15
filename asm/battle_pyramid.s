	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81C5238
sub_81C5238: @ 81C5238
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203CF2C
	ldr r0, [r4]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bhi _081C52F0
	lsls r0, 2
	ldr r1, =_081C5264
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C5264:
	.4byte _081C5278
	.4byte _081C5294
	.4byte _081C52B8
	.4byte _081C52C8
	.4byte _081C52D4
_081C5278:
	bl reset_temp_tile_data_buffers
	ldr r1, =gBagScreen_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081C52D8
	.pool
_081C5294:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5308
	ldr r0, =gUnknown_08D9AE04
	ldr r4, =gUnknown_0203CF2C
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C52DC
	.pool
_081C52B8:
	ldr r0, =gUnknown_08D9AF44
	movs r1, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	b _081C52D8
	.pool
_081C52C8:
	ldr r0, =gUnknown_0861F3CC
	bl LoadCompressedObjectPic
	b _081C52D8
	.pool
_081C52D4:
	bl sub_81C6E98
_081C52D8:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
_081C52DC:
	ldr r0, =0x00000984
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _081C5308
	.pool
_081C52F0:
	bl LoadListMenuArrowsGfx
	ldr r0, [r4]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _081C530A
	.pool
_081C5308:
	movs r0, 0
_081C530A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C5238

	thumb_func_start sub_81C5314
sub_81C5314: @ 81C5314
	push {r4-r7,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r3, =0x00000e2c
	adds r0, r3
	adds r7, r2, r0
	movs r6, 0
	ldr r1, =gUnknown_0203CF2C
	ldr r0, [r1]
	ldr r4, =0x00000821
	adds r0, r4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _081C5382
	adds r5, r1, 0
_081C5344:
	lsls r1, r6, 1
	adds r4, r1, r6
	lsls r4, 3
	ldr r0, =0x0000087c
	adds r4, r0
	ldr r0, [r5]
	adds r0, r4
	adds r1, r7
	ldrh r1, [r1]
	bl sub_81C540C
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x00000824
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, =0x00000828
	adds r0, r1, r4
	adds r0, r2
	str r6, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x00000821
	adds r1, r0
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r6, r0
	blt _081C5344
_081C5382:
	ldr r5, =gUnknown_0203CF2C
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	ldr r1, =0x0000087c
	adds r4, r1
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gText_CloseBag
	bl StringCopy
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x00000824
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, =0x00000828
	adds r1, r4
	adds r1, r2
	movs r0, 0x2
	negs r0, r0
	str r0, [r1]
	ldr r2, =gMultiuseListMenuTemplate
	adds r1, r2, 0
	ldr r0, =gUnknown_0861F2C0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r5]
	ldr r6, =0x00000821
	adds r0, r1, r6
	ldrb r0, [r0]
	strh r0, [r2, 0xC]
	adds r3, r1, r3
	str r3, [r2]
	ldr r7, =0x00000822
	adds r1, r7
	ldrb r0, [r1]
	strh r0, [r2, 0xE]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5314

	thumb_func_start sub_81C540C
sub_81C540C: @ 81C540C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r0, r4, 0
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _081C5450
	ldr r0, =gStringVar1
	adds r1, r4, 0
	subs r1, 0x84
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar2
	adds r0, r4, 0
	bl CopyItemName
	ldr r1, =gText_UnkF908Var1Clear7Var2
	adds r0, r5, 0
	bl StringExpandPlaceholders
	b _081C5458
	.pool
_081C5450:
	adds r0, r4, 0
	adds r1, r5, 0
	bl CopyItemName
_081C5458:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C540C

	thumb_func_start sub_81C5460
sub_81C5460: @ 81C5460
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081C5476
	movs r0, 0x5
	bl PlaySE
	bl sub_81C6F20
_081C5476:
	ldr r5, =gUnknown_0203CF2C
	ldr r1, [r5]
	ldr r2, =0x00000814
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C5504
	adds r2, 0x1
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
	bl sub_81C6FF8
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C54E0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, r4, 1
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00000e2c
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	ldr r1, [r5]
	ldr r2, =0x00000815
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81C6F90
	b _081C54EE
	.pool
_081C54E0:
	ldr r0, =0x0000ffff
	ldr r1, [r5]
	ldr r2, =0x00000815
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81C6F90
_081C54EE:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000815
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_81C55D8
_081C5504:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5460

	thumb_func_start sub_81C5518
sub_81C5518: @ 81C5518
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C55B8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _081C5560
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r1, r0
	bne _081C5558
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C5AB8
	b _081C5560
	.pool
_081C5558:
	adds r0, r5, 0
	movs r1, 0xFF
	bl sub_81C5AB8
_081C5560:
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	ldr r2, =0x00000ca9
	adds r1, r3, r2
	ldrb r2, [r1]
	lsls r2, 30
	lsrs r2, 30
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 1
	adds r1, r4, r1
	ldr r2, =0x00000e54
	adds r3, r2
	adds r3, r1
	ldrb r1, [r3]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x77
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r0, 0xFF
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r4, 0
	adds r3, r5, 0
	bl sub_81C6C94
_081C55B8:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5518

	thumb_func_start sub_81C55D8
sub_81C55D8: @ 81C55D8
	push {r4,lr}
	sub sp, 0x10
	adds r3, r0, 0
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _081C561C
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, 1
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00000e2c
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	bl ItemId_GetDescription
	adds r4, r0, 0
	b _081C5638
	.pool
_081C561C:
	ldr r0, =gStringVar1
	ldr r2, =gReturnToXStringsTable2
	ldr r1, =gUnknown_0203CF30
	ldrb r1, [r1, 0x4]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_ReturnToVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
_081C5638:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C55D8

	thumb_func_start sub_81C5674
sub_81C5674: @ 81C5674
	push {r4,lr}
	sub sp, 0x10
	ldr r4, =gUnknown_0203CF2C
	ldr r1, [r4]
	ldr r2, =0x00000816
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C56B4
	adds r2, 0xB
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x00000b5e
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0203CF30+8
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xAC
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParameterized
	ldr r1, [r4]
	ldr r2, =0x00000816
	adds r1, r2
	strb r0, [r1]
_081C56B4:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5674

	thumb_func_start sub_81C56CC
sub_81C56CC: @ 81C56CC
	push {r4,lr}
	ldr r4, =gUnknown_0203CF2C
	ldr r0, [r4]
	ldr r2, =0x00000816
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C56EA
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x00000816
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_081C56EA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C56CC

	thumb_func_start sub_81C56F8
sub_81C56F8: @ 81C56F8
	push {r4,lr}
	ldr r0, =sub_81C5BC8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gMultiuseListMenuTemplate
	ldr r2, =gUnknown_0203CF30
	ldrh r1, [r2, 0x8]
	ldrh r2, [r2, 0x6]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C56F8

	thumb_func_start sub_81C5738
sub_81C5738: @ 81C5738
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSaveBlock2Ptr
	ldr r6, [r2]
	ldr r3, =0x00000ca9
	adds r2, r6, r3
	ldrb r3, [r2]
	lsls r3, 30
	lsrs r2, r3, 30
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 2
	ldr r2, =0x00000e2c
	adds r4, r2
	adds r4, r6, r4
	lsrs r3, 30
	lsls r2, r3, 2
	adds r2, r3
	lsls r2, 1
	ldr r3, =0x00000e54
	adds r2, r3
	adds r6, r2
	lsls r5, r0, 1
	adds r5, r4
	ldrh r2, [r5]
	mov r8, r2
	lsls r2, r1, 1
	adds r2, r4
	ldrh r3, [r2]
	strh r3, [r5]
	mov r3, r8
	strh r3, [r2]
	adds r0, r6, r0
	ldrb r2, [r0]
	adds r6, r1
	ldrb r1, [r6]
	strb r1, [r0]
	strb r2, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5738

	thumb_func_start sub_81C57A8
sub_81C57A8: @ 81C57A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r6, r3, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r3, r0
	cmp r4, r5
	beq _081C5862
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	mov r12, r0
	adds r0, r3, r4
	ldrb r0, [r0]
	mov r8, r0
	cmp r5, r4
	bls _081C5830
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, r4, 16
	cmp r4, r5
	bge _081C5854
_081C5802:
	asrs r2, 16
	lsls r0, r2, 1
	adds r0, r6
	ldrh r1, [r0, 0x2]
	strh r1, [r0]
	adds r1, r3, r2
	ldrb r0, [r1, 0x1]
	strb r0, [r1]
	adds r2, 0x1
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, r5
	blt _081C5802
	b _081C5854
	.pool
_081C5830:
	lsls r2, r7, 16
	cmp r7, r5
	ble _081C5854
_081C5836:
	asrs r2, 16
	lsls r1, r2, 1
	adds r1, r6
	subs r0, r1, 0x2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, r3, r2
	subs r0, r1, 0x1
	ldrb r0, [r0]
	strb r0, [r1]
	subs r2, 0x1
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, r5
	bgt _081C5836
_081C5854:
	lsls r0, r5, 1
	adds r0, r6
	mov r2, r12
	strh r2, [r0]
	adds r0, r3, r5
	mov r1, r8
	strb r1, [r0]
_081C5862:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C57A8

	thumb_func_start sub_81C586C
sub_81C586C: @ 81C586C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r0, r3
	mov r9, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r4, =0x00000e54
	adds r0, r4
	adds r3, r0
	mov r8, r3
	movs r5, 0
	movs r3, 0
_081C58A4:
	lsls r0, r5, 1
	mov r1, r9
	adds r2, r0, r1
	ldrh r0, [r2]
	mov r4, r8
	adds r1, r4, r5
	cmp r0, 0
	beq _081C58BA
	ldrb r0, [r1]
	cmp r0, 0
	bne _081C58BE
_081C58BA:
	strh r3, [r2]
	strb r3, [r1]
_081C58BE:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _081C58A4
	movs r5, 0
_081C58CA:
	adds r1, r5, 0x1
	lsls r0, r1, 24
	lsrs r4, r0, 24
	adds r7, r1, 0
	cmp r4, 0x9
	bhi _081C58FE
	lsls r0, r5, 1
	mov r1, r9
	adds r6, r0, r1
_081C58DC:
	ldrh r0, [r6]
	cmp r0, 0
	beq _081C58EC
	mov r2, r8
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C58F4
_081C58EC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81C5738
_081C58F4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C58DC
_081C58FE:
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, 0x8
	bls _081C58CA
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C586C

	thumb_func_start sub_81C5924
sub_81C5924: @ 81C5924
	push {r4-r6,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x00000e2c
	adds r0, r1
	adds r5, r2, r0
	bl sub_81C586C
	ldr r3, =gUnknown_0203CF2C
	ldr r0, [r3]
	ldr r2, =0x00000821
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	movs r4, 0
	adds r6, r3, 0
_081C5954:
	lsls r0, r4, 1
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, =gUnknown_0203CF2C
	cmp r0, 0
	beq _081C596A
	ldr r1, [r6]
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081C596A:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9
	bls _081C5954
	ldr r0, [r3]
	ldr r2, =0x00000821
	adds r0, r2
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r2, [r2]
	cmp r2, 0x8
	bls _081C59AC
	ldr r2, =0x00000822
	adds r1, r0, r2
	movs r0, 0x8
	strb r0, [r1]
	b _081C59B2
	.pool
_081C59AC:
	ldr r1, =0x00000822
	adds r0, r1
	strb r2, [r0]
_081C59B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5924

	thumb_func_start sub_81C59BC
sub_81C59BC: @ 81C59BC
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x8]
	adds r3, r0, 0
	ldr r4, =gUnknown_0203CF2C
	cmp r1, 0
	beq _081C59E4
	ldrh r0, [r3, 0x8]
	ldr r1, [r4]
	ldr r5, =0x00000822
	adds r2, r1, r5
	ldrb r2, [r2]
	adds r0, r2
	subs r5, 0x1
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	ble _081C59E4
	subs r0, r1, r2
	strh r0, [r3, 0x8]
_081C59E4:
	adds r2, r3, 0
	ldrh r1, [r2, 0x8]
	ldrh r0, [r2, 0x6]
	adds r1, r0
	ldr r0, [r4]
	ldr r4, =0x00000821
	adds r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _081C5A18
	adds r1, r0, 0
	cmp r1, 0
	bne _081C5A14
	strh r1, [r2, 0x6]
	b _081C5A18
	.pool
_081C5A14:
	subs r0, 0x1
	strh r0, [r3, 0x6]
_081C5A18:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C59BC

	thumb_func_start sub_81C5A20
sub_81C5A20: @ 81C5A20
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x6]
	adds r5, r0, 0
	cmp r1, 0x4
	bls _081C5A80
	movs r4, 0
	ldrh r0, [r5, 0x6]
	subs r0, 0x4
	cmp r4, r0
	bgt _081C5A80
	ldrh r2, [r5, 0x8]
	ldr r6, =gUnknown_0203CF2C
	ldr r0, [r6]
	ldr r3, =0x00000822
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, r1
	ldr r7, =0x00000821
	adds r0, r7
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C5A80
	adds r3, r5, 0
_081C5A50:
	ldrh r0, [r3, 0x6]
	subs r0, 0x1
	strh r0, [r3, 0x6]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r3, 0x6]
	subs r0, 0x4
	cmp r4, r0
	bgt _081C5A80
	ldrh r2, [r5, 0x8]
	ldr r1, [r6]
	ldr r7, =0x00000822
	adds r0, r1, r7
	ldrb r0, [r0]
	adds r2, r0
	ldr r0, =0x00000821
	adds r1, r0
	ldrb r1, [r1]
	cmp r2, r1
	bne _081C5A50
_081C5A80:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5A20

	thumb_func_start sub_81C5A98
sub_81C5A98: @ 81C5A98
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_81C5AB8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C5A98

	thumb_func_start sub_81C5AB8
sub_81C5AB8: @ 81C5AB8
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r2, 0xFF
	bne _081C5AF4
	movs r0, 0x1
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl FillWindowPixelRect
	b _081C5B08
_081C5AF4:
	ldr r1, =gText_SelectorArrow2
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0
	adds r3, r5, 0
	bl sub_81C6C3C
_081C5B08:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5AB8

	thumb_func_start sub_81C5B14
sub_81C5B14: @ 81C5B14
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C5B4C
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5B14

	thumb_func_start sub_81C5B4C
sub_81C5B4C: @ 81C5B4C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r2, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C5BBC
	ldrb r0, [r2]
	ldr r4, =gUnknown_0203CF30+8
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl DestroyListMenuTask
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _081C5B94
	bl SetMainCallback2
	b _081C5B9E
	.pool
_081C5B94:
	adds r0, r4, 0
	subs r0, 0x8
	ldr r0, [r0]
	bl SetMainCallback2
_081C5B9E:
	bl sub_81C56CC
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
_081C5BBC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5B4C

	thumb_func_start sub_81C5BC8
sub_81C5BC8: @ 81C5BC8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C5BEA
	b _081C5D16
_081C5BEA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C5BF8
	b _081C5D16
_081C5BF8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _081C5C5C
	ldr r4, =gUnknown_0203CF30
	ldrb r0, [r4, 0x4]
	cmp r0, 0x2
	bne _081C5C12
	b _081C5D16
_081C5C12:
	ldrb r0, [r7]
	adds r1, r4, 0
	adds r1, 0x8
	adds r2, r4, 0x6
	bl ListMenuGetScrollAndRow
	ldrh r1, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	adds r1, r0
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000821
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _081C5D16
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C67CC
	b _081C5D16
	.pool
_081C5C5C:
	ldrb r0, [r7]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r7]
	ldr r1, =gUnknown_0203CF30+8
	mov r8, r1
	mov r2, r8
	subs r2, 0x2
	bl ListMenuGetScrollAndRow
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081C5C88
	adds r0, 0x1
	cmp r6, r0
	bne _081C5CA0
	b _081C5D16
	.pool
_081C5C88:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gSpecialVar_ItemId
	strh r4, [r0]
	adds r0, r5, 0
	bl sub_81C5B14
	b _081C5D16
	.pool
_081C5CA0:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gSpecialVar_ItemId
	mov r12, r2
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, r6, 1
	ldr r0, =0x00000ca9
	adds r4, r2, r0
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r1, =0x00000e2c
	adds r0, r2, r1
	adds r0, r3
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1]
	strh r6, [r7, 0x2]
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r6, r0
	ldr r1, =0x00000e54
	adds r2, r1
	adds r2, r0
	ldrb r0, [r2]
	strh r0, [r7, 0x4]
	mov r0, r8
	subs r0, 0x8
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2
	bne _081C5D10
	adds r0, r5, 0
	bl sub_81C674C
	b _081C5D16
	.pool
_081C5D10:
	adds r0, r5, 0
	bl sub_81C5D20
_081C5D16:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C5BC8

	thumb_func_start sub_81C5D20
sub_81C5D20: @ 81C5D20
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C56CC
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_81C5A98
	ldr r0, =gUnknown_0203CF30
	ldrb r4, [r0, 0x4]
	cmp r4, 0x1
	beq _081C5D74
	cmp r4, 0x3
	beq _081C5DC4
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F308
	str r0, [r2]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	movs r0, 0x4
	b _081C5DD8
	.pool
_081C5D74:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	bl ItemId_GetBattleUsage
	lsls r0, 24
	cmp r0, 0
	beq _081C5DA0
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F30E
	b _081C5DCE
	.pool
_081C5DA0:
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r2, r0, r1
	ldr r1, =gUnknown_0861F310
	str r1, [r2]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	strb r4, [r0]
	b _081C5DDA
	.pool
_081C5DC4:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F30C
_081C5DCE:
	str r0, [r2]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	movs r0, 0x2
_081C5DD8:
	strb r0, [r1]
_081C5DDA:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_Var1IsSelected
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C5E3C
	movs r0, 0
	b _081C5E42
	.pool
_081C5E3C:
	cmp r0, 0x2
	bne _081C5E50
	movs r0, 0x1
_081C5E42:
	bl sub_81C6D24
	lsls r0, 24
	lsrs r0, 24
	bl sub_81C5EAC
	b _081C5E62
_081C5E50:
	movs r0, 0x2
	bl sub_81C6D24
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	movs r2, 0x2
	bl sub_81C5F08
_081C5E62:
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _081C5E8C
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C5FE4
	b _081C5E98
	.pool
_081C5E8C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C5F68
_081C5E98:
	str r0, [r1]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5D20

	thumb_func_start sub_81C5EAC
sub_81C5EAC: @ 81C5EAC
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	ldr r6, =gUnknown_0203CF2C
	ldr r1, [r6]
	movs r5, 0x82
	lsls r5, 4
	adds r0, r1, r5
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0861F2D8
	str r0, [sp, 0xC]
	ldr r0, =0x00000818
	adds r1, r0
	ldr r0, [r1]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl AddItemMenuActionTextPrinters
	ldr r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5EAC

	thumb_func_start sub_81C5F08
sub_81C5F08: @ 81C5F08
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x38
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	ldr r0, =gUnknown_0861F2D8
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl sub_8198DBC
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x38
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8199944
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5F08

	thumb_func_start sub_81C5F68
sub_81C5F68: @ 81C5F68
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5FD0
	bl Menu_ProcessInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C5FD0
	adds r0, 0x1
	cmp r4, r0
	bne _081C5FA8
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0861F2D8
	ldr r1, [r0, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	b _081C5FD0
	.pool
_081C5FA8:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gUnknown_0861F2D8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000818
	adds r0, r2
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	beq _081C5FD0
	adds r0, r6, 0
	bl _call_via_r1
_081C5FD0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5F68

	thumb_func_start sub_81C5FE4
sub_81C5FE4: @ 81C5FE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C5FF8
	b _081C6160
_081C5FF8:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C6040
	lsls r0, r4, 24
	asrs r0, 24
	cmp r0, 0
	bgt _081C6016
	b _081C6160
_081C6016:
	subs r0, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	bne _081C6028
	b _081C6160
_081C6028:
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	bl sub_8199134
	b _081C6160
	.pool
_081C6040:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C6084
	lsls r0, r4, 24
	asrs r1, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r2, 0x82
	lsls r2, 4
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x2
	cmp r1, r0
	blt _081C6060
	b _081C6160
_081C6060:
	adds r0, r1, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	movs r1, 0x1
	bl sub_8199134
	b _081C6160
	.pool
_081C6084:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C6098
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C60C0
_081C6098:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6160
	subs r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _081C60FA
_081C60C0:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C60D6
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C6102
_081C60D6:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081C6160
	adds r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_081C60FA:
	movs r1, 0
	bl sub_8199134
	b _081C6160
_081C6102:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6148
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gUnknown_0861F2D8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	lsls r1, r4, 24
	asrs r1, 24
	ldr r3, =0x00000818
	adds r0, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r2, 0x4
	adds r0, r2
	ldr r1, [r0]
	cmp r1, 0
	beq _081C6160
	adds r0, r6, 0
	bl _call_via_r1
	b _081C6160
	.pool
_081C6148:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0861F2D8
	ldr r1, [r0, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
_081C6160:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5FE4

	thumb_func_start sub_81C616C
sub_81C616C: @ 81C616C
	push {lr}
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	blt _081C61A0
	ldr r0, =gUnknown_0203CF2C
	ldr r2, [r0]
	movs r3, 0x82
	lsls r3, 4
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bgt _081C61A0
	ldr r3, =0x00000818
	adds r0, r2, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _081C61A0
	movs r0, 0x1
	b _081C61A2
	.pool
_081C61A0:
	movs r0, 0
_081C61A2:
	pop {r1}
	bx r1
	thumb_func_end sub_81C616C

	thumb_func_start sub_81C61A8
sub_81C61A8: @ 81C61A8
	push {lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C61C8
	movs r0, 0
	bl sub_81C6D6C
	b _081C61DA
	.pool
_081C61C8:
	cmp r0, 0x2
	bne _081C61D4
	movs r0, 0x1
	bl sub_81C6D6C
	b _081C61DA
_081C61D4:
	movs r0, 0x2
	bl sub_81C6D6C
_081C61DA:
	pop {r0}
	bx r0
	thumb_func_end sub_81C61A8

	thumb_func_start sub_81C61E0
sub_81C61E0: @ 81C61E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	beq _081C620C
	cmp r0, 0x2
	beq _081C620C
	cmp r0, 0x3
	beq _081C620C
	ldrh r0, [r4]
	bl ItemIsMail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C6228
_081C620C:
	bl sub_81C61A8
	ldr r1, =gText_DadsAdvice
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C6252
	.pool
_081C6228:
	ldrh r0, [r4]
	bl ItemId_GetFieldFunc
	cmp r0, 0
	beq _081C6252
	bl sub_81C61A8
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldrh r0, [r4]
	bl ItemId_GetFieldFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081C6252:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C61E0

	thumb_func_start sub_81C6258
sub_81C6258: @ 81C6258
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C61A8
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6258

	thumb_func_start sub_81C629C
sub_81C629C: @ 81C629C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81C5674
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C5BC8
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C629C

	thumb_func_start sub_81C62C4
sub_81C62C4: @ 81C62C4
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r6, r0, 3
	ldr r7, =gTasks + 0x8
	adds r4, r6, r7
	bl sub_81C61A8
	movs r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _081C62F4
	adds r0, r5, 0
	bl sub_81C6350
	b _081C6334
	.pool
_081C62F4:
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_TossHowManyVar1s
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	bl sub_81C6404
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81C64B4
	str r1, [r0]
_081C6334:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C62C4

	thumb_func_start sub_81C6350
sub_81C6350: @ 81C6350
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_ConfirmTossItems
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldr r1, =gUnknown_0861F314
	adds r0, r5, 0
	bl sub_81C6DAC
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6350

	thumb_func_start sub_81C63D0
sub_81C63D0: @ 81C63D0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C63D0

	thumb_func_start sub_81C6404
sub_81C6404: @ 81C6404
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gStringVar1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	bl sub_81C6CEC
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6404

	thumb_func_start sub_81C645C
sub_81C645C: @ 81C645C
	push {r4,lr}
	sub sp, 0xC
	adds r1, r0, 0
	ldr r0, =gStringVar1
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C645C

	thumb_func_start sub_81C64B4
sub_81C64B4: @ 81C64B4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x10
	ldrh r1, [r4, 0x4]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C64E8
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	bl sub_81C645C
	b _081C6544
	.pool
_081C64E8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C651C
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C6350
	b _081C6544
	.pool
_081C651C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C6544
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl sub_81C63D0
_081C6544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C64B4

	thumb_func_start sub_81C654C
sub_81C654C: @ 81C654C
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar4
	ldr r1, =gText_ThrewAwayVar2Var1s
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81C65CC
	str r0, [r4]
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C654C

	thumb_func_start sub_81C65CC
sub_81C65CC: @ 81C65CC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r6, =gUnknown_0203CF30+8
	subs r7, r6, 0x2
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081C662E
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldrh r1, [r4, 0x10]
	bl RemovePyramidBagItem
	ldrb r0, [r4]
	adds r1, r6, 0
	adds r2, r7, 0
	bl DestroyListMenuTask
	bl sub_81C5924
	bl sub_81C59BC
	bl sub_81C5314
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r6]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C629C
_081C662E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C65CC

	thumb_func_start sub_81C6648
sub_81C6648: @ 81C6648
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	bl sub_81C61A8
	ldr r5, =gSpecialVar_ItemId
	ldrh r0, [r5]
	bl ItemIsMail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C667C
	ldr r1, =gText_CantWriteMail
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C66A6
	.pool
_081C667C:
	ldrh r0, [r5]
	bl ItemId_GetImportance
	lsls r0, 24
	cmp r0, 0
	bne _081C66A0
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =sub_81B7F60
	str r0, [r1]
	adds r0, r4, 0
	bl sub_81C5B14
	b _081C66A6
	.pool
_081C66A0:
	adds r0, r6, 0
	bl sub_81C66AC
_081C66A6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C6648

	thumb_func_start sub_81C66AC
sub_81C66AC: @ 81C66AC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r5, =gStringVar4
	ldr r1, =gText_Var1CantBeHeld
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageInBattlePyramid
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C66AC

	thumb_func_start sub_81C66EC
sub_81C66EC: @ 81C66EC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C670A
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81C6714
_081C670A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C66EC

	thumb_func_start sub_81C6714
sub_81C6714: @ 81C6714
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C6E1C
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6714

	thumb_func_start sub_81C674C
sub_81C674C: @ 81C674C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r5, =gSpecialVar_ItemId
	ldrh r0, [r5]
	bl itemid_80BF6D8_mail_related
	lsls r0, 24
	cmp r0, 0
	bne _081C677C
	ldr r1, =gText_CantWriteMail
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C6796
	.pool
_081C677C:
	ldrh r0, [r5]
	bl ItemId_GetImportance
	lsls r0, 24
	cmp r0, 0
	bne _081C6790
	adds r0, r4, 0
	bl sub_81C5B14
	b _081C6796
_081C6790:
	adds r0, r6, 0
	bl sub_81C66AC
_081C6796:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C674C

	thumb_func_start sub_81C679C
sub_81C679C: @ 81C679C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	cmp r0, 0
	beq _081C67C0
	bl sub_81C61A8
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081C67C0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C679C

	thumb_func_start sub_81C67CC
sub_81C67CC: @ 81C67CC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r5, r4, r0
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x6]
	ldrh r0, [r0, 0x8]
	adds r1, r0
	strh r1, [r5, 0x2]
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000814
	adds r0, r2
	movs r2, 0
	mov r8, r2
	strb r1, [r0]
	ldrb r0, [r5]
	movs r1, 0x10
	movs r2, 0x1
	bl ListMenuSetUnkIndicatorsStructField
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	lsls r2, 1
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r0, =0x00000e2c
	adds r3, r0
	adds r3, r2
	ldrh r0, [r3]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r6, =gStringVar4
	ldr r1, =gText_MoveVar1Where
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	mov r1, r8
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_81C5A98
	ldrb r0, [r5, 0x2]
	bl sub_81C704C
	movs r2, 0x8
	negs r2, r2
	add r9, r2
	add r4, r9
	ldr r0, =sub_81C68B0
	str r0, [r4]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C67CC

	thumb_func_start sub_81C68B0
sub_81C68B0: @ 81C68B0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C695C
	ldr r7, =gMain
	ldrh r1, [r7, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081C68F8
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	ldr r1, =gUnknown_0203CF30+8
	subs r2, r1, 0x2
	bl ListMenuGetScrollAndRow
	b _081C6940
	.pool
_081C68F8:
	ldrb r0, [r4]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r4]
	ldr r4, =gUnknown_0203CF30+8
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl ListMenuGetScrollAndRow
	movs r0, 0
	bl sub_81C7028
	subs r4, 0x8
	ldrb r0, [r4, 0x6]
	bl sub_81C704C
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081C6930
	adds r0, 0x1
	cmp r6, r0
	bne _081C6950
	b _081C695C
	.pool
_081C6930:
	movs r0, 0x5
	bl PlaySE
	ldrh r1, [r7, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6948
_081C6940:
	adds r0, r5, 0
	bl sub_81C6964
	b _081C695C
_081C6948:
	adds r0, r5, 0
	bl sub_81C6A14
	b _081C695C
_081C6950:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C6964
_081C695C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C68B0

	thumb_func_start sub_81C6964
sub_81C6964: @ 81C6964
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
	ldr r7, =gUnknown_0203CF30+8
	subs r0, r7, 0x2
	mov r8, r0
	ldrh r0, [r0]
	ldrh r1, [r7]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	cmp r1, r4
	beq _081C6996
	subs r0, r4, 0x1
	cmp r1, r0
	bne _081C69A8
_081C6996:
	adds r0, r6, 0
	bl sub_81C6A14
	b _081C69FC
	.pool
_081C69A8:
	ldrb r0, [r5, 0x2]
	lsls r1, r4, 24
	lsrs r1, 24
	bl sub_81C57A8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C7028
	ldrb r0, [r5]
	adds r1, r7, 0
	mov r2, r8
	bl DestroyListMenuTask
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	cmp r0, r4
	bge _081C69E0
	adds r1, r7, 0
	subs r1, 0x8
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	strh r0, [r1, 0x6]
_081C69E0:
	bl sub_81C5314
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r7]
	mov r3, r8
	ldrh r2, [r3]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_81C629C
_081C69FC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6964

	thumb_func_start sub_81C6A14
sub_81C6A14: @ 81C6A14
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r5, =gUnknown_0203CF30+8
	subs r7, r5, 0x2
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C7028
	ldrb r0, [r4]
	adds r1, r5, 0
	adds r2, r7, 0
	bl DestroyListMenuTask
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldrh r0, [r5]
	ldrh r1, [r7]
	adds r0, r1
	cmp r2, r0
	bge _081C6A5E
	adds r1, r5, 0
	subs r1, 0x8
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	strh r0, [r1, 0x6]
_081C6A5E:
	bl sub_81C5314
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r5]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	adds r0, r6, 0
	bl sub_81C629C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6A14

	thumb_func_start sub_81C6A94
sub_81C6A94: @ 81C6A94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r0, =gPlayerParty
	mov r9, r0
	movs r0, 0x14
	bl Alloc
	adds r7, r0, 0
	movs r0, 0xA
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	ldr r2, [r1]
	ldr r4, =0x00000ca9
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, =0x00000e2c
	adds r1, r0
	adds r0, r7, 0
	movs r2, 0x14
	bl memcpy
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	adds r1, r2
	ldr r0, =0x00000e54
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0xA
	bl memcpy
	movs r6, 0
_081C6AF8:
	movs r0, 0x64
	muls r0, r6
	add r0, r9
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	cmp r0, 0
	beq _081C6B88
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	bne _081C6B88
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x00000e2c
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x14
	bl memcpy
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r2
	ldr r1, =0x00000e54
	adds r0, r1
	adds r1, r5, 0
	movs r2, 0xA
	bl memcpy
	adds r0, r7, 0
	bl Free
	adds r0, r5, 0
	bl Free
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	b _081C6BC6
	.pool
_081C6B88:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _081C6AF8
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	movs r6, 0
	movs r4, 0x64
_081C6B9C:
	adds r0, r6, 0
	muls r0, r4
	add r0, r9
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _081C6B9C
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	adds r0, r7, 0
	bl Free
	adds r0, r5, 0
	bl Free
_081C6BC6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6A94

	thumb_func_start sub_81C6BD8
sub_81C6BD8: @ 81C6BD8
	push {r4,lr}
	ldr r0, =gUnknown_0861F328
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xD0
	bl LoadMessageBoxGfx
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081C6C04:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081C6C04
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6BD8

	thumb_func_start sub_81C6C3C
sub_81C6C3C: @ 81C6C3C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	ldr r5, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861F31C
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	bl AddTextPrinterParameterized2
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6C3C

	thumb_func_start sub_81C6C94
sub_81C6C94: @ 81C6C94
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	ldr r5, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861F31C
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x7
	bl AddTextPrinterParameterized2
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6C94

	thumb_func_start sub_81C6CEC
sub_81C6CEC: @ 81C6CEC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C6CEC

	thumb_func_start sub_81C6D08
sub_81C6D08: @ 81C6D08
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF2C
	ldr r1, [r1]
	ldr r2, =0x0000080f
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C6D08

	thumb_func_start sub_81C6D24
sub_81C6D24: @ 81C6D24
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r3, =0x0000080f
	adds r1, r2, r3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C6D58
	lsls r0, r2, 3
	ldr r1, =gUnknown_0861F350
	adds r0, r1
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_081C6D58:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C6D24

	thumb_func_start sub_81C6D6C
sub_81C6D6C: @ 81C6D6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF2C
	ldr r2, =0x0000080f
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C6D9E
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0xFF
	strb r0, [r4]
_081C6D9E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6D6C

	thumb_func_start sub_81C6DAC
sub_81C6DAC: @ 81C6DAC
	push {lr}
	sub sp, 0x10
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0861F370
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0xE
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6DAC

	thumb_func_start DisplayItemMessageInBattlePyramid
@ void DisplayItemMessageInBattlePyramid(u8 taskId, u8 *str, void ( *callback)(u8 taskId))
DisplayItemMessageInBattlePyramid: @ 81C6DD8
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	bl GetPlayerTextSpeed
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0xA
	movs r3, 0xD
	bl DisplayMessageAndContinueTask
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end DisplayItemMessageInBattlePyramid

	thumb_func_start sub_81C6E1C
sub_81C6E1C: @ 81C6E1C
	push {lr}
	movs r0, 0x2
	movs r1, 0
	bl sub_8197DF8
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C6E1C

	thumb_func_start sub_81C6E38
sub_81C6E38: @ 81C6E38
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r2, =0x00000804
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _081C6E80
	ldr r0, =0x00001024
	adds r4, r0
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0xFF
	strb r0, [r5]
_081C6E80:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6E38

	thumb_func_start sub_81C6E98
sub_81C6E98: @ 81C6E98
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0x40
	bl Alloc
	adds r4, r0, 0
	ldr r0, =gUnknown_08D9ADD0
	adds r1, r4, 0
	bl LZDecompressWram
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r4, r0
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	ldr r1, =0x00001024
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpritePalette
	adds r0, r4, 0
	bl Free
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6E98

	thumb_func_start sub_81C6EF4
sub_81C6EF4: @ 81C6EF4
	push {r4,lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r4, [r0]
	ldr r0, =0x00000804
	adds r4, r0
	ldr r0, =gUnknown_0861F3D4
	movs r1, 0x44
	movs r2, 0x38
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6EF4

	thumb_func_start sub_81C6F20
sub_81C6F20: @ 81C6F20
	push {r4,lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000804
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081C6F50
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =sub_81C6F68
	str r0, [r4, 0x1C]
_081C6F50:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F20

	thumb_func_start sub_81C6F68
sub_81C6F68: @ 81C6F68
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081C6F84
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081C6F84:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F68

	thumb_func_start sub_81C6F90
sub_81C6F90: @ 81C6F90
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r2, =0x00000805
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _081C6FE0
	ldr r0, =0x00001025
	adds r4, r0
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl AddItemIconSprite
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081C6FE0
	strb r2, [r5]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x18
	strh r1, [r0, 0x24]
	movs r1, 0x58
	strh r1, [r0, 0x26]
_081C6FE0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F90

	thumb_func_start sub_81C6FF8
sub_81C6FF8: @ 81C6FF8
	push {lr}
	lsls r0, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 24
	bl sub_81C6E38
	pop {r0}
	bx r0
	thumb_func_end sub_81C6FF8

	thumb_func_start sub_81C700C
sub_81C700C: @ 81C700C
	push {lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	movs r1, 0x8
	bl sub_8122344
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C700C

	thumb_func_start sub_81C7028
sub_81C7028: @ 81C7028
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	movs r1, 0x8
	bl sub_81223FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7028

	thumb_func_start sub_81C704C
sub_81C704C: @ 81C704C
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	lsrs r3, 4
	movs r1, 0x80
	lsls r1, 13
	adds r3, r1
	lsrs r3, 16
	movs r1, 0x88
	movs r2, 0x78
	bl sub_8122448
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C704C

	thumb_func_start sub_81C7078
sub_81C7078: @ 81C7078
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl is_c1_link_related_active
	cmp r0, 0
	bne _081C7090
	ldr r0, =sub_81C7170
	b _081C7092
	.pool
_081C7090:
	ldr r0, =sub_81C71E4
_081C7092:
	lsls r1, r4, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =gUnknown_0203CF3C
	ldrb r1, [r2]
	strh r1, [r0, 0xE]
	ldrb r0, [r2]
	adds r1, r0, 0x1
	strb r1, [r2]
	lsls r0, 24
	lsrs r0, 8
	orrs r0, r4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7078

	thumb_func_start sub_81C70D8
sub_81C70D8: @ 81C70D8
	push {lr}
	ldr r1, =0x0000ffff
	ands r1, r0
	lsrs r3, r0, 16
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _081C711C
	ldr r2, [r1]
	ldr r0, =sub_81C7170
	cmp r2, r0
	beq _081C70FE
	ldr r0, =sub_81C71E4
	cmp r2, r0
	bne _081C711C
_081C70FE:
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, r3
	bne _081C711C
	movs r0, 0x1
	b _081C711E
	.pool
_081C711C:
	movs r0, 0
_081C711E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C70D8

	thumb_func_start sub_81C7124
sub_81C7124: @ 81C7124
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gTasks
_081C712C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _081C7160
	ldr r1, [r4]
	ldr r0, =sub_81C7170
	cmp r1, r0
	beq _081C7140
	ldr r0, =sub_81C71E4
	cmp r1, r0
	bne _081C7160
_081C7140:
	lsls r0, r5, 24
	lsrs r0, 24
	movs r1, 0x1
	bl GetWordTaskArg
	cmp r0, r6
	bne _081C7160
	movs r0, 0x1
	b _081C716A
	.pool
_081C7160:
	adds r4, 0x28
	adds r5, 0x1
	cmp r5, 0xF
	ble _081C712C
	movs r0, 0
_081C716A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7124

	thumb_func_start sub_81C7170
sub_81C7170: @ 81C7170
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r6, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r7, 0
_081C718C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r6
	cmp r0, 0x4
	bhi _081C71D6
	lsls r0, 2
	ldr r1, =_081C71AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C71AC:
	.4byte _081C71C6
	.4byte _081C71C0
	.4byte _081C71DE
	.4byte _081C71DA
	.4byte _081C71CE
_081C71C0:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C71D8
_081C71C6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081C71DE
_081C71CE:
	adds r0, r5, 0
	bl DestroyTask
	b _081C71DE
_081C71D6:
	subs r0, 0x5
_081C71D8:
	strh r0, [r4]
_081C71DA:
	cmp r7, 0
	beq _081C718C
_081C71DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7170

	thumb_func_start sub_81C71E4
sub_81C71E4: @ 81C71E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8087598
	cmp r0, 0
	bne _081C724A
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r2, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r2
	cmp r0, 0x4
	bhi _081C7246
	lsls r0, 2
	ldr r1, =_081C7224
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C7224:
	.4byte _081C7238
	.4byte _081C7238
	.4byte _081C724A
	.4byte _081C724A
	.4byte _081C723E
_081C7238:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C7248
_081C723E:
	adds r0, r5, 0
	bl DestroyTask
	b _081C724A
_081C7246:
	subs r0, 0x5
_081C7248:
	strh r0, [r4]
_081C724A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C71E4

	.align 2, 0 @ Don't pad with nop.
