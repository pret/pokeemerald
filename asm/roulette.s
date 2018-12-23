	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8140238
sub_8140238: @ 8140238
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xB8
	ldrb r0, [r1]
	cmp r0, 0
	beq _0814025A
	adds r0, r1, 0
	bl task_tutorial_controls_fadein
_0814025A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140238

	thumb_func_start sub_8140264
sub_8140264: @ 8140264
	push {r4,lr}
	sub sp, 0x4
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	bl sub_8142814
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	ldrh r0, [r0, 0x26]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x14
	bl SetGpuReg
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _081402A0
	ldrh r1, [r1, 0x34]
	movs r0, 0x52
	bl SetGpuReg
_081402A0:
	ldr r2, [r4]
	movs r3, 0x2A
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _081402C0
	ldr r1, =0x040000d4
	ldr r3, =0x0000133c
	adds r0, r2, r3
	str r0, [r1]
	ldr r0, =0x060021c0
	str r0, [r1, 0x4]
	ldr r0, =0x800001a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0
	strh r0, [r2, 0x2A]
_081402C0:
	ldr r0, [r4]
	movs r2, 0x28
	ldrsh r1, [r0, r2]
	cmp r1, 0x1
	beq _081402EC
	cmp r1, 0x1
	ble _08140374
	cmp r1, 0x2
	beq _08140324
	cmp r1, 0xFF
	beq _08140348
	b _08140374
	.pool
_081402EC:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0
	bl ShowBg
	ldr r1, =0x040000d4
	ldr r2, [r4]
	movs r3, 0xCF
	lsls r3, 2
	adds r0, r2, r3
	str r0, [r1]
	ldr r0, =0x0600f9c0
	str r0, [r1, 0x4]
	ldr r0, =0x800001a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0x2
	strh r0, [r2, 0x28]
	b _08140374
	.pool
_08140324:
	ldr r1, =0x040000d4
	movs r2, 0xCF
	lsls r2, 2
	adds r0, r2
	str r0, [r1]
	ldr r0, =0x0600f9c0
	str r0, [r1, 0x4]
	ldr r0, =0x800001a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	b _08140374
	.pool
_08140348:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0
	bl ShowBg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r3, sp
	str r3, [r1]
	ldr r0, =0x0600f9c0
	str r0, [r1, 0x4]
	ldr r0, =0x810001a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0x28]
_08140374:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140264

	thumb_func_start sub_8140388
sub_8140388: @ 8140388
	push {r4,r5,lr}
	sub sp, 0x4
	movs r5, 0
	str r5, [sp]
	ldr r4, =gUnknown_0203AB88
	movs r0, 0xE6
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085B6140
	movs r0, 0x1
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r1, [r4]
	movs r0, 0xBE
	lsls r0, 1
	adds r1, r0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r2, =0x0000117c
	adds r1, r2
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x0000317c
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_085B614C
	bl InitWindows
	bl sub_8197200
	ldr r0, =gUnknown_0203AB8C
	strb r5, [r0]
	ldr r0, =gUnknown_085B5DFC
	mov r1, sp
	bl malloc_and_decompress
	ldr r1, [r4]
	ldr r2, =0x0000397c
	adds r1, r2
	str r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140388

	thumb_func_start sub_8140418
sub_8140418: @ 8140418
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	ldr r4, =0x0000397c
	adds r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	adds r0, r4
	movs r4, 0
	str r4, [r0]
	bl FreeAllWindowBuffers
	movs r0, 0
	bl UnsetBgTilemapBuffer
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x2
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r0, [r5]
	movs r2, 0xE6
	lsls r2, 6
	movs r1, 0
	bl memset
	ldr r0, [r5]
	bl Free
	str r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140418

	thumb_func_start sub_8140470
sub_8140470: @ 8140470
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r1, =gUnknown_085B6418
	mov r0, sp
	movs r2, 0x6
	bl memcpy
	ldr r5, =gUnknown_0203AB88
	ldr r3, [r5]
	ldr r4, =gSpecialVar_0x8004
	ldrb r0, [r4]
	movs r1, 0x1
	ands r1, r0
	ldrb r2, [r3, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x4]
	ldrh r1, [r4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081404AA
	ldr r0, [r5]
	ldrb r1, [r0, 0x4]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x4]
_081404AA:
	ldr r1, [r5]
	ldr r2, =gUnknown_085B6348
	ldrb r0, [r1, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r2
	ldrb r0, [r0, 0x3]
	adds r1, 0x22
	strb r0, [r1]
	ldr r1, [r5]
	ldrb r0, [r1, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r2
	ldrb r0, [r0, 0x4]
	adds r1, 0x23
	strb r0, [r1]
	ldr r2, [r5]
	ldr r3, =gUnknown_085B6344
	ldrb r1, [r2, 0x4]
	lsls r0, r1, 30
	lsrs r0, 30
	lsrs r1, 7
	lsls r1, 1
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r2, 0x19]
	ldr r2, [r5]
	ldrb r1, [r2, 0x1A]
	movs r0, 0xF
	ands r0, r1
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x1A]
	ldr r0, [r5]
	ldrb r0, [r0, 0x19]
	cmp r0, 0x1
	bne _08140520
	ldr r4, =gPlttBufferUnfaded
	ldr r3, =gPlttBufferFaded
	mov r0, sp
	ldrh r2, [r0]
	b _08140528
	.pool
_08140520:
	ldr r4, =gPlttBufferUnfaded
	ldr r3, =gPlttBufferFaded
	mov r0, sp
	ldrh r2, [r0, 0x2]
_08140528:
	adds r0, r3, 0
	adds r0, 0xA2
	strh r2, [r0]
	ldr r1, =0x0000ffff
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3]
	ands r0, r1
	adds r2, r4, 0
	adds r2, 0xA2
	strh r0, [r2]
	ands r0, r1
	strh r0, [r4]
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0xB8
	bl sub_8151678
	movs r4, 0
_0814054E:
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	adds r0, 0xB8
	lsls r2, r4, 3
	ldr r1, =gUnknown_085B6388
	adds r2, r1
	adds r1, r4, 0
	bl sub_815168C
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xC
	bls _0814054E
	movs r4, 0
_0814056C:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x41
	bl GetMonData
	adds r1, r0, 0
	movs r0, 0x98
	lsls r0, 1
	cmp r1, r0
	beq _081405AC
	adds r0, 0x2
	cmp r1, r0
	bne _081405B6
	ldr r0, [r5]
	ldrb r1, [r0, 0x2]
	movs r2, 0x1
	b _081405B2
	.pool
_081405AC:
	ldr r0, [r5]
	ldrb r1, [r0, 0x2]
	movs r2, 0x2
_081405B2:
	orrs r1, r2
	strb r1, [r0, 0x2]
_081405B6:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _0814056C
	bl RtcCalcLocalTime
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8140470

	thumb_func_start sub_81405CC
sub_81405CC: @ 81405CC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x8
	bls _081405E0
	b _081407F8
_081405E0:
	lsls r0, 2
	ldr r1, =_081405F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081405F4:
	.4byte _08140618
	.4byte _08140630
	.4byte _08140650
	.4byte _08140662
	.4byte _0814069C
	.4byte _081406C0
	.4byte _081406E0
	.4byte _08140750
	.4byte _0814077A
_08140618:
	movs r0, 0
	bl SetVBlankCallback
	bl ScanlineEffect_Stop
	bl SetVBlankHBlankCallbacksToNull
	bl ResetVramOamAndBgCntRegs
	bl ResetAllBgsCoordinates
	b _081407F8
_08140630:
	bl sub_8140388
	bl DeactivateAllTextPrinters
	movs r1, 0x90
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x0000060a
	movs r0, 0x52
	bl SetGpuReg
	b _081407F8
	.pool
_08140650:
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	bl reset_temp_tile_data_buffers
	b _081407F8
_08140662:
	ldr r0, =gUnknown_085B5BFC
	movs r2, 0xE0
	lsls r2, 1
	movs r1, 0
	bl LoadPalette
	ldr r1, =gRouletteMenuTiles
	movs r4, 0
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, =gRouletteWheelTiles
	str r4, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081407F8
	.pool
_0814069C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081406A8
	b _08140806
_081406A8:
	bl sub_8140470
	ldr r1, =gUnknown_085B5FA0
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	b _081407F8
	.pool
_081406C0:
	movs r0, 0
	bl sub_8142C0C
	bl sub_81439C8
	bl sub_814391C
	bl sub_8143314
	bl sub_8142CD0
	bl sub_8142F7C
	bl sub_81431E4
	b _081407F8
_081406E0:
	bl AnimateSprites
	bl BuildOamBuffer
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	bl sub_8143514
	movs r0, 0x6
	bl sub_814372C
	movs r0, 0
	bl sub_81436D0
	movs r0, 0
	bl sub_81424FC
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5B89
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gSpriteCoordOffsetX
	movs r2, 0x3C
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gSpriteCoordOffsetY
	strh r5, [r0]
	b _081407F8
	.pool
_08140750:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	b _081407F8
_0814077A:
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_8140264
	bl SetVBlankCallback
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginHardwarePaletteFade
	ldr r0, =sub_81408A8
	movs r1, 0
	bl CreateTask
	ldr r5, =gUnknown_0203AB88
	ldr r1, [r5]
	adds r1, 0xA4
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r0, 0x6
	strh r0, [r4, 0x14]
	bl GetCoins
	strh r0, [r4, 0x22]
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	bl sub_80EDE84
	ldr r0, =sub_8140814
	movs r1, 0x1
	bl CreateTask
	ldr r1, [r5]
	adds r1, 0xA5
	strb r0, [r1]
	ldr r0, =sub_8140238
	bl SetMainCallback2
	b _08140806
	.pool
_081407F8:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08140806:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81405CC

	thumb_func_start sub_8140814
sub_8140814: @ 8140814
	push {r4-r6,lr}
	ldr r3, =gUnknown_0203AB88
	ldr r0, [r3]
	adds r0, 0x21
	ldrb r2, [r0]
	adds r1, r2, 0x1
	strb r1, [r0]
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x23
	lsls r2, 24
	lsrs r2, 24
	adds r6, r3, 0
	ldrb r0, [r0]
	cmp r2, r0
	bne _0814085A
	adds r1, 0x21
	movs r0, 0
	strb r0, [r1]
	ldr r2, [r6]
	adds r3, r2, 0
	adds r3, 0x22
	ldrb r1, [r3]
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	lsls r0, 16
	cmp r0, 0
	bge _0814085A
	ldrb r1, [r3]
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3, 0
	subs r0, r1
	strh r0, [r2, 0x24]
_0814085A:
	adds r4, r6, 0
	ldr r0, [r4]
	ldrh r0, [r0, 0x24]
	bl Sin2
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [r4]
	ldrh r0, [r0, 0x24]
	bl Cos2
	lsls r0, 16
	lsrs r1, r0, 16
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0
	bge _0814087E
	adds r0, 0xF
_0814087E:
	lsls r0, 12
	lsrs r5, r0, 16
	ldr r3, [r6]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0
	bge _0814088E
	adds r0, 0xF
_0814088E:
	asrs r0, 4
	strh r0, [r3, 0x32]
	strh r0, [r3, 0x2C]
	strh r5, [r3, 0x2E]
	lsls r0, r5, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r3, 0x30]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140814

	thumb_func_start sub_81408A8
sub_81408A8: @ 81408A8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081408FE
	movs r1, 0x90
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000808
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x14]
	adds r0, r4, 0
	bl sub_8141FF4
	bl sub_8142070
	bl sub_8143A40
	movs r0, 0
	bl sub_81424FC
	movs r0, 0x6
	bl sub_814372C
	ldr r1, =sub_8140968
	ldr r2, =0x0000ffff
	adds r0, r4, 0
	movs r3, 0x3
	bl sub_8141F7C
_081408FE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81408A8

	thumb_func_start sub_8140914
sub_8140914: @ 8140914
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl DisplayYesNoMenu
	ldr r5, =gUnknown_0203AB8C
	ldrb r0, [r5]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r5]
	ldr r2, =gUnknown_082A5C13
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gUnknown_085B6410
	adds r0, r4, 0
	bl sub_8121F68
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140914

	thumb_func_start sub_8140968
sub_8140968: @ 8140968
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_819746C
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8140BD0
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140968

	thumb_func_start sub_8140994
sub_8140994: @ 8140994
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0xA5
	ldrb r0, [r0]
	bl DestroyTask
	adds r0, r4, 0
	bl sub_8141DE4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140994

	thumb_func_start sub_81409B8
sub_81409B8: @ 81409B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _081409CA
	b _08140AE8
_081409CA:
	lsls r0, r4, 2
	ldr r1, =_081409D8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081409D8:
	.4byte _08140A18
	.4byte _08140A3C
	.4byte _08140A3C
	.4byte _08140A3C
	.4byte _08140A3C
	.4byte _08140A90
	.4byte _08140AE8
	.4byte _08140AE8
	.4byte _08140AE8
	.4byte _08140AE8
	.4byte _08140A90
	.4byte _08140AE8
	.4byte _08140AE8
	.4byte _08140AE8
	.4byte _08140AE8
	.4byte _08140A90
_08140A18:
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	movs r1, 0x10
	str r1, [sp]
	movs r1, 0xD
	str r1, [sp, 0x4]
	movs r1, 0
	movs r2, 0xE
	movs r3, 0x7
	bl sub_8152008
	b _08140B4E
	.pool
_08140A3C:
	lsls r0, r4, 1
	adds r0, r4
	adds r0, 0xE
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	movs r4, 0xBE
	lsls r4, 1
	adds r0, r4
	movs r1, 0x10
	str r1, [sp]
	movs r6, 0xD
	str r6, [sp, 0x4]
	movs r1, 0
	movs r2, 0xE
	movs r3, 0x7
	bl sub_8152008
	ldr r0, [r5]
	adds r4, r0, r4
	ldr r1, =0x0000397c
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =0x00000232
	adds r1, r0
	movs r0, 0x3
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r0, r4, 0
	mov r2, r8
	movs r3, 0x7
	bl sub_8152058
	b _08140B4E
	.pool
_08140A90:
	subs r0, r4, 0x1
	movs r1, 0x5
	bl __divsi3
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0xA
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	movs r4, 0xBE
	lsls r4, 1
	adds r0, r4
	movs r6, 0x10
	str r6, [sp]
	movs r1, 0xD
	str r1, [sp, 0x4]
	movs r1, 0
	movs r2, 0xE
	movs r3, 0x7
	bl sub_8152008
	ldr r0, [r5]
	adds r4, r0, r4
	ldr r1, =0x0000397c
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0xA0
	lsls r0, 2
	adds r1, r0
	str r6, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0xE
	adds r3, r7, 0
	bl sub_8152058
	b _08140B4E
	.pool
_08140AE8:
	adds r0, r4, 0
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0xE
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	subs r0, r4, 0x1
	movs r1, 0x5
	bl __divsi3
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0x7
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	movs r4, 0xBE
	lsls r4, 1
	adds r0, r4
	movs r1, 0x10
	str r1, [sp]
	movs r1, 0xD
	str r1, [sp, 0x4]
	movs r1, 0
	movs r2, 0xE
	movs r3, 0x7
	bl sub_8152008
	ldr r0, [r5]
	adds r4, r0, r4
	ldr r1, =0x0000397c
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x88
	lsls r0, 2
	adds r1, r0
	movs r0, 0x3
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r2, r8
	adds r3, r7, 0
	bl sub_8152058
_08140B4E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81409B8

	thumb_func_start sub_8140B64
sub_8140B64: @ 8140B64
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrb r0, [r4, 0x10]
	bl sub_81436D0
	ldrb r0, [r4, 0x10]
	bl sub_81409B8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140B64

	thumb_func_start sub_8140B8C
sub_8140B8C: @ 8140B8C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0203AB88
	ldr r2, [r5]
	movs r6, 0
	movs r1, 0x1
	strh r1, [r2, 0x28]
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrb r0, [r4, 0x10]
	bl sub_81409B8
	ldr r0, [r5]
	adds r0, 0x23
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x21
	strb r6, [r0]
	ldr r0, =sub_8141040
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140B8C

	thumb_func_start sub_8140BD0
sub_8140BD0: @ 8140BD0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gUnknown_0203AB88
	ldr r0, [r1]
	ldr r2, [r0, 0x8]
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _08140C30
	movs r3, 0xB
	ldr r5, =gUnknown_085B6154
	adds r0, r5, 0
	adds r0, 0xE4
	ldr r0, [r0]
	ands r2, r0
	ldr r0, =gTasks
	mov r12, r0
	lsls r7, r6, 2
	cmp r2, 0
	beq _08140C6E
	adds r4, r1, 0
	adds r5, 0x8
_08140BFE:
	lsls r0, r3, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r3, r0, 16
	asrs r2, r0, 16
	cmp r2, 0xD
	bgt _08140C6E
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	ldr r1, [r1, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08140BFE
	b _08140C6E
	.pool
_08140C30:
	movs r3, 0x6
	ldr r5, =gUnknown_085B6154
	adds r0, r5, 0
	adds r0, 0x80
	ldr r0, [r0]
	ands r2, r0
	ldr r0, =gTasks
	mov r12, r0
	lsls r7, r6, 2
	cmp r2, 0
	beq _08140C6E
	adds r4, r1, 0
	adds r5, 0x8
_08140C4A:
	lsls r0, r3, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r3, r0, 16
	asrs r2, r0, 16
	cmp r2, 0x9
	bgt _08140C6E
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	ldr r1, [r1, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08140C4A
_08140C6E:
	adds r4, r7, r6
	lsls r4, 3
	add r4, r12
	movs r5, 0
	strh r3, [r4, 0x10]
	adds r0, r6, 0
	bl sub_8141FF4
	ldrb r0, [r4, 0x10]
	bl sub_81424FC
	ldrb r0, [r4, 0x10]
	bl sub_81436D0
	ldrb r0, [r4, 0x10]
	bl sub_8142284
	strh r5, [r4, 0xA]
	ldr r0, =sub_8140B8C
	str r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140BD0

	thumb_func_start sub_8140CA8
sub_8140CA8: @ 8140CA8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r6, 0
	movs r7, 0
	ldr r1, =gUnknown_085B641E
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	ldrb r0, [r4]
	mov r8, r0
	cmp r5, 0
	blt _08140D1C
	cmp r5, 0x1
	bgt _08140CF4
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl __modsi3
	lsls r0, 24
	lsrs r6, r0, 24
	movs r2, 0xF0
	lsls r2, 20
	adds r1, r0, r2
	lsrs r7, r1, 24
	cmp r0, 0
	bne _08140D1C
	movs r6, 0x5
	b _08140D1C
	.pool
_08140CF4:
	cmp r5, 0x3
	bgt _08140D1C
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r2, 0x80
	lsls r2, 19
	adds r0, r1, r2
	lsrs r7, r0, 24
	cmp r1, 0
	bne _08140D1C
	movs r6, 0x1
_08140D1C:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r2, [r4]
	adds r0, r2
	strh r0, [r4]
	lsls r1, r6, 24
	asrs r3, r1, 24
	lsls r0, 16
	asrs r0, 16
	lsls r2, r7, 24
	cmp r0, r3
	bge _08140D3E
	asrs r0, r2, 24
	strh r0, [r4]
_08140D3E:
	movs r0, 0
	ldrsh r1, [r4, r0]
	asrs r0, r2, 24
	cmp r1, r0
	ble _08140D4A
	strh r3, [r4]
_08140D4A:
	mov r1, r8
	lsls r0, r1, 24
	movs r2, 0
	ldrsh r1, [r4, r2]
	asrs r0, 24
	cmp r1, r0
	bne _08140D5C
	movs r0, 0
	b _08140D5E
_08140D5C:
	movs r0, 0x1
_08140D5E:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8140CA8

	thumb_func_start sub_8140D6C
sub_8140D6C: @ 8140D6C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0
	mov r9, r0
	movs r5, 0
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08140DA8
	movs r5, 0x1
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	adds r0, 0x8
	movs r1, 0
	bl sub_8140CA8
	lsls r0, 24
	cmp r0, 0
	bne _08140DA8
	b _08140F3A
_08140DA8:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08140DCE
	movs r5, 0x1
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	adds r0, 0x8
	movs r1, 0x1
	bl sub_8140CA8
	lsls r0, 24
	cmp r0, 0
	bne _08140DCE
	b _08140F3A
_08140DCE:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08140DF4
	movs r5, 0x1
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	adds r0, 0x8
	movs r1, 0x2
	bl sub_8140CA8
	lsls r0, 24
	cmp r0, 0
	bne _08140DF4
	b _08140F3A
_08140DF4:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08140E1A
	movs r5, 0x1
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	adds r0, 0x8
	movs r1, 0x3
	bl sub_8140CA8
	lsls r0, 24
	cmp r0, 0
	bne _08140E1A
	b _08140F3A
_08140E1A:
	cmp r5, 0
	bne _08140E20
	b _08140F3A
_08140E20:
	ldr r0, =gTasks
	lsls r6, r7, 2
	adds r4, r6, r7
	lsls r4, 3
	adds r4, r0
	ldrb r0, [r4, 0x10]
	bl sub_81424FC
	adds r0, r7, 0
	bl sub_8140B64
	mov r1, r9
	strh r1, [r4, 0xA]
	movs r0, 0x5
	bl PlaySE
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	adds r0, 0xB8
	ldr r1, =0x0000ffff
	bl sub_8151A9C
	ldr r5, [r5]
	movs r2, 0xB8
	lsls r2, 1
	adds r3, r5, r2
	ldrb r2, [r3]
	movs r1, 0x7F
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	movs r0, 0xB2
	lsls r0, 1
	adds r3, r5, r0
	ldrb r2, [r3]
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	movs r0, 0xAC
	lsls r0, 1
	adds r2, r5, r0
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	ldrb r0, [r4, 0x10]
	bl sub_8142284
	movs r4, 0
	mov r9, r6
	ldr r1, =gSprites
	mov r12, r1
	movs r2, 0x8
	add r2, r12
	mov r10, r2
_08140E8C:
	ldr r0, =gUnknown_0203AB88
	ldr r5, [r0]
	adds r0, r4, 0
	adds r0, 0x29
	adds r6, r5, 0
	adds r6, 0x3C
	adds r0, r6, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r1, r12
	adds r3, r0, r1
	adds r2, r3, 0
	adds r2, 0x40
	add r0, r10
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =0x000003ff
	mov r8, r2
	mov r0, r8
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _08140E8C
	ldr r0, =gTasks
	mov r2, r9
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r3, [r1, 0x10]
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _08140F3A
	ldr r2, =gUnknown_085B6154
	movs r0, 0x10
	ldrsh r1, [r1, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r5, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08140F3A
	subs r0, r3, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, 0x29
	adds r0, r6, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	adds r2, r3, 0
	adds r2, 0x40
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldrh r2, [r2]
	adds r1, r2
	mov r2, r8
	ands r1, r2
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
_08140F3A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140D6C

	thumb_func_start sub_8140F6C
sub_8140F6C: @ 8140F6C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80EECA4
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	movs r0, 0xFF
	strh r0, [r1, 0x28]
	ldrb r2, [r1, 0x19]
	cmp r2, 0x1
	bne _08140F90
	adds r0, r1, 0
	adds r0, 0x23
	strb r2, [r0]
	b _08140F96
	.pool
_08140F90:
	adds r1, 0x23
	movs r0, 0
	strb r0, [r1]
_08140F96:
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x21
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x20
	strh r1, [r0, 0xA]
	ldr r1, =sub_81410FC
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140F6C

	thumb_func_start sub_8140FC4
sub_8140FC4: @ 8140FC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_0203AB88
	ldr r2, [r4]
	ldrb r1, [r2, 0x1A]
	lsls r1, 28
	lsrs r1, 28
	adds r2, 0x1B
	adds r2, r1
	ldr r3, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r5, r1, r3
	ldrh r0, [r5, 0x10]
	strb r0, [r2]
	ldr r1, [r4]
	ldrb r0, [r1, 0x1A]
	lsls r0, 28
	lsrs r0, 28
	adds r1, 0x1B
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8142758
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xC]
	ldr r1, [r4]
	ldrb r0, [r1, 0x1A]
	lsls r0, 28
	lsrs r0, 28
	adds r1, 0x1B
	adds r1, r0
	ldrb r0, [r1]
	bl sub_81436D0
	ldr r0, [r4]
	ldrb r1, [r0, 0x19]
	ldrh r0, [r5, 0x22]
	subs r0, r1
	strh r0, [r5, 0x22]
	lsls r0, 16
	cmp r0, 0
	bge _08141024
	movs r0, 0
	strh r0, [r5, 0x22]
_08141024:
	ldrh r0, [r5, 0x22]
	bl sub_8143514
	ldr r0, =sub_8140F6C
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8140FC4

	thumb_func_start sub_8141040
sub_8141040: @ 8141040
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_8140D6C
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x1E
	beq _08141076
	cmp r0, 0x1E
	bgt _0814106C
	cmp r0, 0
	beq _08141072
	b _0814108A
	.pool
_0814106C:
	cmp r0, 0x3B
	beq _08141084
	b _0814108A
_08141072:
	ldrb r0, [r4, 0x10]
	b _08141078
_08141076:
	movs r0, 0
_08141078:
	bl sub_81409B8
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _0814109A
_08141084:
	movs r0, 0
	strh r0, [r4, 0xA]
	b _0814109A
_0814108A:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
_0814109A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081410F2
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r2, =gUnknown_085B6154
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r3, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _081410E8
	movs r0, 0x16
	bl PlaySE
	b _081410F2
	.pool
_081410E8:
	movs r0, 0x5F
	bl m4aSongNumStart
	ldr r0, =sub_8140FC4
	str r0, [r4]
_081410F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141040

	thumb_func_start sub_81410FC
sub_81410FC: @ 81410FC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0xA]
	subs r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	ble _08141168
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08141128
	ldr r1, =gSpriteCoordOffsetX
	ldrh r0, [r1]
	adds r0, 0x2
	strh r0, [r1]
_08141128:
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	ldrh r0, [r1, 0x26]
	adds r0, 0x4
	strh r0, [r1, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x68
	bne _08141180
	ldr r2, =gSprites
	adds r0, r1, 0
	adds r0, 0x55
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	b _08141180
	.pool
_08141168:
	movs r0, 0x1
	movs r1, 0xFF
	bl sub_8142E70
	movs r0, 0x1
	movs r1, 0xFF
	bl sub_8143038
	ldr r0, =sub_8141344
	str r0, [r4]
	movs r0, 0
	strh r0, [r4, 0xA]
_08141180:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81410FC

	thumb_func_start sub_814118C
sub_814118C: @ 814118C
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldrb r2, [r3, 0x2]
	adds r5, r0, 0
	cmp r2, 0x2
	bgt _081411AC
	cmp r2, 0x1
	bge _081411B2
	b _08141280
	.pool
_081411AC:
	cmp r2, 0x3
	beq _08141214
	b _08141280
_081411B2:
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	subs r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bhi _081411E4
	cmp r4, 0xB
	bls _081411CC
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08141296
_081411CC:
	ldr r0, =gUnknown_085B6348
	ldrb r1, [r3, 0x4]
	lsls r1, 30
	lsrs r1, 25
	adds r1, r0
	ldrb r0, [r1, 0x2]
	lsrs r0, 1
	b _0814133A
	.pool
_081411E4:
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08141200
	ldr r0, =gUnknown_085B6348
	ldrb r1, [r3, 0x4]
	lsls r1, 30
	lsrs r1, 25
	adds r1, r0
	ldrb r0, [r1, 0x2]
	lsrs r0, 1
	b _0814133A
	.pool
_08141200:
	ldr r0, =gUnknown_085B6348
	ldrb r1, [r3, 0x4]
	lsls r1, 30
	lsrs r1, 25
	adds r1, r0
	ldrb r0, [r1, 0x2]
	b _0814133A
	.pool
_08141214:
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	subs r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bhi _08141248
	cmp r4, 0x5
	bls _0814122E
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08141296
_0814122E:
	ldr r0, =gUnknown_085B6348
	ldrb r1, [r3, 0x4]
	lsls r1, 30
	lsrs r1, 25
	adds r1, r0
	ldrb r0, [r1, 0x2]
	lsrs r0, 1
	b _0814133A
	.pool
_08141248:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08141268
	cmp r4, 0x6
	bls _08141268
	ldr r0, =gUnknown_085B6348
	ldrb r1, [r3, 0x4]
	lsls r1, 30
	lsrs r1, 25
	adds r1, r0
	ldrb r0, [r1, 0x2]
	lsrs r0, 2
	b _0814133A
	.pool
_08141268:
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsrs r0, 1
	b _0814133A
	.pool
_08141280:
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	subs r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bhi _081412B8
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081412A0
_08141296:
	movs r0, 0x1
	b _0814133A
	.pool
_081412A0:
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsrs r0, 1
	b _0814133A
	.pool
_081412B8:
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081412F0
	cmp r4, 0xC
	bls _081412DC
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsrs r0, 1
	b _0814133A
	.pool
_081412DC:
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x2]
	b _0814133A
	.pool
_081412F0:
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08141328
	cmp r4, 0xC
	bls _08141314
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x2]
	b _0814133A
	.pool
_08141314:
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x1]
	b _0814133A
	.pool
_08141328:
	ldr r1, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 25
	lsrs r0, 24
_0814133A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814118C

	thumb_func_start sub_8141344
sub_8141344: @ 8141344
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r4, 0
	ldr r1, =gUnknown_085B6422
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	bl Random
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r7, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r3, =gUnknown_0203AB88
	ldr r0, [r3]
	ldr r2, =gTasks
	mov r5, r10
	lsls r1, r5, 2
	add r1, r10
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0x14]
	adds r0, 0x7C
	strb r2, [r0]
	ldr r0, [r3]
	adds r2, r0, 0
	adds r2, 0x7F
	strb r4, [r2]
	subs r2, 0x1
	strb r4, [r2]
	adds r0, 0x7D
	strb r4, [r0]
	ldrh r0, [r1, 0x18]
	adds r1, r7, 0
	bl sub_814118C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r1, r4, 24
	adds r0, r7, 0
	bl __modsi3
	lsrs r4, 25
	subs r0, r4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	movs r5, 0x1
	cmp r0, 0xC
	bgt _081413C8
	movs r5, 0
_081413C8:
	cmp r6, 0x4F
	bhi _081413E0
	lsls r0, r5, 25
	b _081413EA
	.pool
_081413E0:
	lsls r1, r5, 24
	asrs r1, 24
	movs r0, 0x1
	subs r0, r1
	lsls r0, 25
_081413EA:
	lsrs r5, r0, 24
	ldr r0, _08141530  @ =gUnknown_0203AB88
	ldr r6, [r0]
	ldrb r0, [r6, 0x4]
	lsls r0, 30
	lsrs r0, 25
	ldr r1, _08141534  @ =gUnknown_085B6348
	adds r0, r1
	lsls r4, 24
	asrs r4, 24
	ldrh r0, [r0, 0x1A]
	adds r4, r0
	adds r0, r6, 0
	adds r0, 0x80
	strh r4, [r0]
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _0814141C
	ldr r1, _08141538  @ =0x47800000
	bl __addsf3
_0814141C:
	ldr r1, _0814153C  @ =0x40A00000
	bl __divsf3
	bl __fixunssfsi
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r0, r4, 1
	adds r0, r4
	movs r2, 0x82
	adds r2, r6
	mov r8, r2
	strh r0, [r2]
	adds r0, r6, 0
	adds r0, 0x84
	strh r4, [r0]
	adds r0, 0x2
	strh r4, [r0]
	movs r0, 0x88
	adds r0, r6
	mov r9, r0
	movs r0, 0x1
	ands r0, r7
	lsls r1, r5, 24
	asrs r1, 24
	adds r0, r1
	lsls r0, 1
	add r0, sp
	movs r1, 0
	ldrsh r4, [r0, r1]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08141468
	ldr r1, _08141538  @ =0x47800000
	bl __addsf3
_08141468:
	mov r2, r9
	str r0, [r2]
	adds r7, r6, 0
	adds r7, 0x8C
	ldrb r0, [r6, 0x4]
	lsls r0, 30
	lsrs r0, 25
	ldr r5, _08141534  @ =gUnknown_085B6348
	adds r0, r5
	movs r1, 0x18
	ldrsh r4, [r0, r1]
	adds r0, r4, 0
	bl __floatsisf
	adds r5, r0, 0
	cmp r4, 0
	bge _08141492
	ldr r1, _08141538  @ =0x47800000
	bl __addsf3
	adds r5, r0, 0
_08141492:
	str r5, [r7]
	adds r7, r6, 0
	adds r7, 0x90
	ldr r1, _08141540  @ =0x3F000000
	adds r0, r5, 0
	bl __mulsf3
	adds r1, r5, 0
	bl __subsf3
	adds r5, r0, 0
	mov r2, r8
	movs r0, 0
	ldrsh r4, [r2, r0]
	adds r0, r4, 0
	bl __floatsisf
	adds r2, r0, 0
	cmp r4, 0
	bge _081414C2
	ldr r1, _08141538  @ =0x47800000
	bl __addsf3
	adds r2, r0, 0
_081414C2:
	adds r0, r5, 0
	adds r1, r2, 0
	bl __divsf3
	str r0, [r7]
	adds r1, r6, 0
	adds r1, 0x94
	ldr r0, _08141544  @ =0x42880000
	str r0, [r1]
	adds r1, 0x8
	ldr r0, _08141548  @ =0x00000000
	str r0, [r1]
	adds r5, r6, 0
	adds r5, 0x98
	mov r1, r8
	movs r2, 0
	ldrsh r4, [r1, r2]
	adds r0, r4, 0
	bl __floatsisf
	adds r2, r0, 0
	cmp r4, 0
	bge _081414F8
	ldr r1, _08141538  @ =0x47800000
	bl __addsf3
	adds r2, r0, 0
_081414F8:
	ldr r0, _0814154C  @ =0x41000000
	adds r1, r2, 0
	bl __divsf3
	bl __negsf2
	str r0, [r5]
	adds r1, r6, 0
	adds r1, 0xA0
	ldr r0, _08141550  @ =0x42100000
	str r0, [r1]
	ldr r1, _08141554  @ =gTasks
	mov r5, r10
	lsls r0, r5, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	ldr r1, _08141558  @ =sub_814155C
	str r1, [r0]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08141530:
	.4byte gUnknown_0203AB88
_08141534:
	.4byte gUnknown_085B6348
_08141538:
	.4byte 0x47800000
_0814153C:
	.4byte 0x40A00000
_08141540:
	.4byte 0x3F000000
_08141544:
	.4byte 0x42880000
_08141548:
	.4byte 0x00000000
_0814154C:
	.4byte 0x41000000
_08141550:
	.4byte 0x42100000
_08141554:
	.4byte gTasks
_08141558:
	.4byte sub_814155C
	thumb_func_end sub_8141344

	thumb_func_start sub_814155C
sub_814155C: @ 814155C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_0203AB88
	ldr r3, [r4]
	ldrb r1, [r3, 0x3]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r3, 0x3]
	ldr r3, [r4]
	adds r2, r3, 0
	adds r2, 0x7C
	adds r1, r3, 0
	adds r1, 0x3C
	ldrb r2, [r2]
	adds r1, r2
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gSprites
	adds r1, r2
	str r1, [r3, 0x38]
	ldr r2, =sub_81446AC
	str r2, [r1, 0x1C]
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrh r1, [r4, 0x14]
	adds r1, 0x1
	strh r1, [r4, 0x14]
	ldrh r0, [r4, 0x18]
	adds r0, 0x1
	strh r0, [r4, 0x18]
	movs r0, 0x6
	subs r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl sub_814372C
	movs r0, 0x5C
	bl m4aSongNumStart
	ldr r0, =sub_81415D4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814155C

	thumb_func_start sub_81415D4
sub_81415D4: @ 81415D4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_0203AB88
	ldr r3, [r6]
	adds r0, r3, 0
	adds r0, 0x7D
	ldrb r0, [r0]
	cmp r0, 0
	beq _081416C6
	ldrb r1, [r3, 0x3]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08141614
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081416C6
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x3]
	ldr r2, [r6]
	ldrb r1, [r2, 0x3]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	b _081416C6
	.pool
_08141614:
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r0, r1, r4
	lsls r0, 3
	adds r5, r0, r2
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	adds r7, r1, 0
	cmp r0, 0
	bne _08141660
	adds r0, r3, 0
	adds r0, 0x7E
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_81420D0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r6]
	ldrb r1, [r2, 0x1A]
	lsls r1, 28
	lsrs r1, 28
	adds r2, 0x1B
	adds r2, r1
	ldrb r1, [r2]
	bl sub_81421E8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x12]
	cmp r0, 0x1
	bne _08141660
	ldr r0, [r6]
	adds r0, 0xB8
	movs r1, 0x80
	lsls r1, 5
	bl sub_8151A48
_08141660:
	ldr r0, =gTasks
	adds r1, r7, r4
	lsls r1, 3
	adds r4, r1, r0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x3C
	bgt _08141690
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08141680
	movs r0, 0x3C
	strh r0, [r4, 0xA]
_08141680:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _081416C6
	.pool
_08141690:
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	ldrb r0, [r1, 0x1A]
	lsls r0, 28
	lsrs r0, 28
	adds r1, 0x1B
	adds r1, r0
	ldrb r0, [r1]
	bl sub_81424FC
	ldrh r1, [r4, 0x20]
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_8142E70
	ldrb r1, [r4, 0x14]
	subs r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_8143038
	movs r0, 0x20
	strh r0, [r4, 0xA]
	ldr r0, =sub_81416D4
	str r0, [r4]
_081416C6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81415D4

	thumb_func_start sub_81416D4
sub_81416D4: @ 81416D4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	subs r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	ble _08141740
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _08141700
	ldr r1, =gSpriteCoordOffsetX
	ldrh r0, [r1]
	subs r0, 0x2
	strh r0, [r1]
_08141700:
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	ldrh r0, [r1, 0x26]
	subs r0, 0x4
	strh r0, [r1, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x68
	bne _08141768
	ldr r2, =gSprites
	adds r0, r1, 0
	adds r0, 0x55
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_814390C
	str r1, [r0]
	b _08141768
	.pool
_08141740:
	ldrh r0, [r4, 0x20]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8143150
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _08141756
	movs r0, 0x79
	b _08141758
_08141756:
	movs r0, 0x3D
_08141758:
	strh r0, [r4, 0xA]
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8141778
	str r0, [r1]
_08141768:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81416D4

	thumb_func_start sub_8141778
sub_8141778: @ 8141778
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0xA]
	subs r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _081417E8
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081417A2
	adds r0, 0xF
_081417A2:
	asrs r0, 4
	lsls r0, 4
	subs r0, r1, r0
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _081417CC
	cmp r0, 0x8
	bne _081417F4
	movs r0, 0
	movs r1, 0xFF
	bl sub_8142E70
	movs r0, 0
	movs r1, 0xFF
	bl sub_8143038
	b _081417F4
	.pool
_081417CC:
	ldrh r1, [r4, 0x20]
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_8142E70
	ldrb r1, [r4, 0x14]
	subs r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_8143038
	b _081417F4
_081417E8:
	ldr r1, =sub_814189C
	adds r0, r2, 0
	movs r2, 0x1E
	movs r3, 0
	bl sub_8141F7C
_081417F4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141778

	thumb_func_start sub_8141800
sub_8141800: @ 8141800
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08141864
	cmp r0, 0
	blt _08141864
	cmp r0, 0x2
	bgt _08141864
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _08141888
	movs r0, 0x1D
	bl GetGameStat
	ldrh r1, [r4, 0x1E]
	adds r1, 0x1
	strh r1, [r4, 0x1E]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bcs _08141848
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	movs r0, 0x1D
	bl SetGameStat
_08141848:
	ldr r1, =sub_8141A18
	ldr r2, =0x0000ffff
	adds r0, r5, 0
	movs r3, 0x3
	bl sub_8141F7C
	b _08141888
	.pool
_08141864:
	bl IsSEPlaying
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _08141888
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0x1E]
	ldr r1, =sub_8141AC0
	ldr r2, =0x0000ffff
	adds r0, r5, 0
	movs r3, 0x3
	bl sub_8141F7C
_08141888:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141800

	thumb_func_start sub_814189C
sub_814189C: @ 814189C
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	cmp r1, 0
	beq _08141928
	cmp r1, 0
	blt _08141928
	cmp r1, 0x2
	bgt _08141928
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0xC
	bne _081418EC
	ldr r0, =0x00000185
	bl PlayFanfare
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5BD7
	b _08141902
	.pool
_081418EC:
	movs r0, 0xC3
	lsls r0, 1
	bl PlayFanfare
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5BCB
_08141902:
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	b _08141958
	.pool
_08141928:
	movs r0, 0x20
	bl m4aSongNumStart
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5BE0
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
_08141958:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xA]
	ldr r1, =sub_8141800
	str r1, [r0]
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814189C

	thumb_func_start sub_8141984
sub_8141984: @ 8141984
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x16
	ldrsh r5, [r4, r0]
	cmp r5, 0
	beq _081419AC
	cmp r5, 0x3
	beq _081419DC
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	b _081419E4
	.pool
_081419AC:
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
	movs r0, 0x15
	bl m4aSongNumStart
	ldrh r0, [r4, 0x22]
	bl sub_8143514
	movs r2, 0x22
	ldrsh r1, [r4, r2]
	ldr r0, =0x0000270e
	cmp r1, r0
	ble _081419D0
	strh r5, [r4, 0xA]
	b _081419E6
	.pool
_081419D0:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x16]
	adds r0, 0x1
	b _081419E4
_081419DC:
	movs r0, 0x15
	bl m4aSongNumStop
	movs r0, 0
_081419E4:
	strh r0, [r4, 0x16]
_081419E6:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08141A04
	ldr r1, =sub_8141AC0
	ldr r2, =0x0000ffff
	adds r0, r6, 0
	movs r3, 0x3
	bl sub_8141F7C
_08141A04:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141984

	thumb_func_start sub_8141A18
sub_8141A18: @ 8141A18
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gStringVar1
	ldr r1, =gUnknown_0203AB88
	mov r9, r1
	ldr r1, [r1]
	ldrb r2, [r1, 0x19]
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	adds r1, r2, 0
	muls r1, r0
	adds r0, r3, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r2, =gStringVar4
	mov r8, r2
	ldr r1, =gUnknown_082A5BEF
	mov r0, r8
	bl StringExpandPlaceholders
	ldr r5, =gUnknown_0203AB8C
	ldrb r0, [r5]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r5]
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	mov r2, r8
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	mov r1, r9
	ldr r0, [r1]
	ldrb r1, [r0, 0x19]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	muls r0, r1
	strh r0, [r4, 0xA]
	strh r6, [r4, 0x16]
	ldr r0, =sub_8141984
	str r0, [r4]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141A18

	thumb_func_start sub_8141AC0
sub_8141AC0: @ 8141AC0
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0203AB88
	ldr r0, [r5]
	adds r0, 0xB8
	ldr r1, =0x0000ffff
	bl sub_8151A9C
	ldr r6, [r5]
	movs r0, 0xB8
	lsls r0, 1
	adds r3, r6, r0
	ldrb r2, [r3]
	movs r1, 0x7F
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	movs r0, 0xB2
	lsls r0, 1
	adds r3, r6, r0
	ldrb r2, [r3]
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3]
	movs r0, 0xAC
	lsls r0, 1
	adds r2, r6, r0
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	ldr r6, =gSprites
	ldr r2, [r5]
	ldr r5, =gUnknown_085B6154
	ldr r0, =gTasks
	lsls r3, r4, 2
	adds r3, r4
	lsls r3, 3
	adds r3, r0
	movs r0, 0x20
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0]
	adds r2, r0
	adds r2, 0x43
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =sub_8141B58
	str r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141AC0

	thumb_func_start sub_8141B58
sub_8141B58: @ 8141B58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	movs r2, 0
	strh r5, [r0, 0x10]
	ldr r4, =gUnknown_0203AB88
	ldr r1, [r4]
	ldrb r0, [r1, 0x1A]
	lsls r0, 28
	lsrs r0, 28
	adds r1, 0x1B
	adds r1, r0
	strb r2, [r1]
	movs r0, 0
	bl sub_81424FC
	ldr r3, =gSprites
	ldr r0, [r4]
	adds r0, 0x6C
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r7, r3, 0
	movs r0, 0x8
	adds r0, r7
	mov r12, r0
	ldr r1, =0xfffffc00
	mov r8, r1
_08141BB0:
	ldr r0, =gUnknown_0203AB88
	ldr r4, [r0]
	adds r0, r4, r5
	adds r0, 0x65
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r7
	adds r2, r3, 0
	adds r2, 0x40
	add r0, r12
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08141BB0
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r2, r1, r0
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	ldrb r4, [r4, 0x19]
	cmp r0, r4
	blt _08141CBC
	movs r1, 0x14
	ldrsh r0, [r2, r1]
	cmp r0, 0x6
	bne _08141C58
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5C21
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =dp01t_12_3_battle_menu
	b _08141C8E
	.pool
_08141C58:
	movs r0, 0x22
	ldrsh r1, [r2, r0]
	ldr r0, =0x0000270f
	cmp r1, r0
	bne _08141CB0
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5C61
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =sub_8140914
_08141C8E:
	ldr r2, =0x0000ffff
	adds r0, r6, 0
	movs r3, 0x3
	bl sub_8141F7C
	b _08141CF2
	.pool
_08141CB0:
	ldr r0, =sub_8140914
	str r0, [r2]
	b _08141CF2
	.pool
_08141CBC:
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5C04
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =sub_8140994
	adds r0, r6, 0
	movs r2, 0x3C
	movs r3, 0x3
	bl sub_8141F7C
_08141CF2:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141B58

	thumb_func_start dp01t_12_3_battle_menu
dp01t_12_3_battle_menu: @ 8141D0C
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x14]
	adds r0, r5, 0
	bl sub_8141FF4
	bl sub_8142070
	bl sub_8143A40
	movs r0, 0
	bl sub_81424FC
	movs r0, 0x6
	bl sub_814372C
	ldr r7, =gSprites
	ldr r3, =gUnknown_0203AB88
	movs r6, 0x5
	negs r6, r6
_08141D44:
	ldr r0, [r3]
	adds r0, r4
	adds r0, 0x43
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xB
	bls _08141D44
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	movs r0, 0x22
	ldrsh r1, [r2, r0]
	ldr r0, =0x0000270f
	cmp r1, r0
	bne _08141DD4
	ldr r4, =gUnknown_0203AB8C
	ldrb r0, [r4]
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldrb r0, [r4]
	ldr r2, =gUnknown_082A5C61
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldrb r0, [r4]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =sub_8140914
	ldr r2, =0x0000ffff
	adds r0, r5, 0
	movs r3, 0x3
	bl sub_8141F7C
	b _08141DD8
	.pool
_08141DD4:
	ldr r0, =sub_8140914
	str r0, [r2]
_08141DD8:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_12_3_battle_menu

	thumb_func_start sub_8141DE4
sub_8141DE4: @ 8141DE4
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	adds r0, 0xB8
	ldr r1, =0x0000ffff
	bl sub_8151A9C
	ldr r0, [r4]
	adds r0, 0xB8
	bl sub_8151678
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x22]
	bl SetCoins
	bl GetCoins
	ldr r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1, 0x19]
	cmp r0, r1
	bcs _08141E38
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x1
	b _08141E3C
	.pool
_08141E38:
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0
_08141E3C:
	strh r0, [r1]
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	bl sub_80EDD78
	movs r0, 0
	str r0, [sp]
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginHardwarePaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8141E7C
	str r1, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141DE4

	thumb_func_start sub_8141E7C
sub_8141E7C: @ 8141E7C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08141EDE
	movs r0, 0
	bl SetVBlankCallback
	ldr r1, =gSpriteCoordOffsetX
	ldr r0, =gSpriteCoordOffsetY
	strh r4, [r0]
	strh r4, [r1]
	bl ResetVramOamAndBgCntRegs
	bl ResetAllBgsCoordinates
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	bl FreeAllSpritePalettes
	bl ResetPaletteFade
	bl ResetSpriteData
	bl sub_8140418
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_08141EDE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141E7C

	thumb_func_start sub_8141EF8
sub_8141EF8: @ 8141EF8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0203AB88
	ldr r3, [r1]
	adds r0, r3, 0
	adds r0, 0xA8
	ldrh r0, [r0]
	adds r5, r1, 0
	cmp r0, 0
	beq _08141F1E
	ldr r0, =gMain
	adds r2, r3, 0
	adds r2, 0xAA
	ldrh r1, [r0, 0x2E]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08141F52
_08141F1E:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0xAC
	ldr r1, [r1]
	str r1, [r0]
	adds r0, r3, 0
	adds r0, 0xAA
	ldrh r0, [r0]
	cmp r0, 0
	beq _08141F40
	movs r0, 0x5
	bl PlaySE
_08141F40:
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0xAC
	movs r1, 0
	str r1, [r0]
	subs r0, 0x2
	strh r1, [r0]
	subs r0, 0x2
	strh r1, [r0]
_08141F52:
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0xA8
	ldrh r2, [r1]
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _08141F64
	subs r0, r2, 0x1
	strh r0, [r1]
_08141F64:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141EF8

	thumb_func_start sub_8141F7C
sub_8141F7C: @ 8141F7C
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 16
	lsrs r4, r2, 16
	lsls r3, 16
	lsrs r7, r3, 16
	ldr r2, =gUnknown_0203AB88
	ldr r0, [r2]
	mov r12, r0
	mov r3, r12
	adds r3, 0xB4
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0]
	str r0, [r3]
	adds r3, r1, 0
	cmp r5, 0
	bne _08141FAC
	adds r5, r0, 0
_08141FAC:
	mov r0, r12
	adds r0, 0xAC
	str r5, [r0]
	subs r0, 0x4
	strh r4, [r0]
	ldr r0, =0x0000ffff
	cmp r4, r0
	bne _08141FD8
	cmp r7, 0
	bne _08141FD8
	mov r1, r12
	adds r1, 0xAA
	ldrh r0, [r1]
	orrs r4, r0
	strh r4, [r1]
	b _08141FDE
	.pool
_08141FD8:
	ldr r0, [r2]
	adds r0, 0xAA
	strh r7, [r0]
_08141FDE:
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r3
	ldr r1, =sub_8141EF8
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141F7C

	thumb_func_start sub_8141FF4
sub_8141FF4: @ 8141FF4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r3, =gUnknown_0203AB88
	ldr r0, [r3]
	strb r4, [r0]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	movs r0, 0x20
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r6, =gTasks
	adds r2, r3, 0
	movs r1, 0
_08142036:
	ldr r0, [r2]
	adds r0, 0x1B
	adds r0, r4
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _08142036
	ldr r2, [r3]
	ldrb r1, [r2, 0x1A]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x1A]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r6
	movs r1, 0
	strh r1, [r0, 0xA]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8141FF4

	thumb_func_start sub_8142070
sub_8142070: @ 8142070
	push {lr}
	ldr r2, =gUnknown_0203AB88
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r1, 0
	movs r3, 0
_0814207E:
	ldr r0, [r2]
	adds r0, 0xC
	adds r0, r1
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x5
	bls _0814207E
	movs r1, 0
	ldr r3, =gUnknown_0203AB88
	movs r2, 0
_08142096:
	ldr r0, [r3]
	adds r0, 0x12
	adds r0, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _08142096
	movs r1, 0
	ldr r3, =gUnknown_0203AB88
	movs r2, 0
_081420AE:
	ldr r0, [r3]
	adds r0, 0x16
	adds r0, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bls _081420AE
	movs r0, 0x1
	movs r1, 0xFF
	bl sub_8143038
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142070

	thumb_func_start sub_81420D0
sub_81420D0: @ 81420D0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	mov r1, sp
	ldr r0, =gUnknown_085B642C
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r2, sp, 0x10
	adds r1, r2, 0
	ldr r0, =gUnknown_085B643C
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	mov r8, r2
	cmp r5, 0xB
	bls _0814210C
	movs r0, 0
	b _081421C8
	.pool
_0814210C:
	ldr r6, =gUnknown_0203AB88
	ldr r3, [r6]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r7, 0x14
	ldrsh r1, [r0, r7]
	adds r3, r1
	ldr r4, =gUnknown_085B62E4
	lsls r5, 3
	adds r2, r5, r4
	ldrb r1, [r2, 0x2]
	strb r1, [r3, 0xB]
	ldrb r1, [r2, 0x2]
	strh r1, [r0, 0x20]
	ldr r2, [r6]
	adds r0, r4, 0x4
	adds r0, r5, r0
	ldr r1, [r2, 0x8]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r2, 0x8]
	movs r3, 0
	mov r9, r4
	mov r12, r5
	adds r5, r0, 0
_08142144:
	lsls r0, r3, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r0, [r4]
	ands r0, r5
	cmp r0, 0
	beq _0814215E
	ldr r1, [r6]
	adds r1, 0x12
	adds r1, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0814215E:
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x12
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x2
	bls _08142174
	ldr r0, [r2, 0x8]
	ldr r1, [r4]
	orrs r0, r1
	str r0, [r2, 0x8]
_08142174:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _08142144
	movs r6, 0
	ldr r0, =gUnknown_085B62E4+0x4
	add r0, r12
	ldr r7, [r0]
	ldr r4, =gUnknown_0203AB88
	mov r5, r8
_0814218A:
	lsls r0, r6, 2
	adds r2, r5, r0
	ldr r0, [r2]
	ands r0, r7
	cmp r0, 0
	beq _081421A2
	ldr r1, [r4]
	adds r1, 0x16
	adds r1, r6
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081421A2:
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0x16
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x3
	bls _081421B8
	ldr r0, [r3, 0x8]
	ldr r1, [r2]
	orrs r0, r1
	str r0, [r3, 0x8]
_081421B8:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _0814218A
	mov r0, r12
	add r0, r9
	ldrb r0, [r0, 0x2]
_081421C8:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81420D0

	thumb_func_start sub_81421E8
sub_81421E8: @ 81421E8
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	lsrs r3, r0, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x12
	bhi _0814227C
	cmp r2, 0xF
	bhi _08142278
	lsls r0, r2, 2
	ldr r1, =_08142210
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08142210:
	.4byte _08142250
	.4byte _08142254
	.4byte _08142254
	.4byte _08142254
	.4byte _08142254
	.4byte _08142268
	.4byte _08142278
	.4byte _08142278
	.4byte _08142278
	.4byte _08142278
	.4byte _08142268
	.4byte _08142278
	.4byte _08142278
	.4byte _08142278
	.4byte _08142278
	.4byte _08142268
_08142250:
	movs r0, 0x3
	b _0814227E
_08142254:
	adds r0, r2, 0x5
	cmp r3, r0
	beq _08142274
	adds r0, 0x5
	cmp r3, r0
	beq _08142274
	adds r0, 0x5
	cmp r3, r0
	bne _0814227C
	b _08142274
_08142268:
	adds r0, r2, 0x1
	cmp r3, r0
	blt _0814227C
	adds r0, r2, 0x4
	cmp r3, r0
	bgt _0814227C
_08142274:
	movs r0, 0x1
	b _0814227E
_08142278:
	cmp r3, r2
	beq _08142274
_0814227C:
	movs r0, 0
_0814227E:
	pop {r1}
	bx r1
	thumb_func_end sub_81421E8

	thumb_func_start sub_8142284
sub_8142284: @ 8142284
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0
	str r0, [sp, 0x18]
	cmp r7, 0xA
	beq _081422AA
	cmp r7, 0xA
	bgt _081422A6
	cmp r7, 0x5
	beq _081422AA
	b _0814230C
_081422A6:
	cmp r7, 0xF
	bne _0814230C
_081422AA:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r2, r7, 0x5
	ldr r1, =gUnknown_0203AB88
	mov r12, r1
	cmp r4, r2
	bge _081422E8
	ldr r0, [r1]
	ldr r3, =gUnknown_085B6154
	ldr r5, [r0, 0x8]
	adds r6, r3, 0
	adds r6, 0x8
_081422C4:
	lsls r0, r4, 2
	adds r0, r4
	lsls r1, r0, 2
	adds r0, r1, r6
	ldr r0, [r0]
	ands r0, r5
	cmp r0, 0
	bne _081422DE
	adds r0, r1, r3
	ldrh r0, [r0, 0x10]
	ldr r1, [sp, 0x18]
	orrs r1, r0
	str r1, [sp, 0x18]
_081422DE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r2
	blt _081422C4
_081422E8:
	mov r2, r12
	ldr r0, [r2]
	adds r0, 0xB8
	ldr r1, =0x0000dfff
	ldr r3, [sp, 0x18]
	ands r3, r1
	str r3, [sp, 0x18]
	adds r1, r3, 0
	bl sub_8151A48
	b _081424E2
	.pool
_0814230C:
	mov r0, sp
	ldr r1, =gUnknown_085B63F0
	ldm r1!, {r2,r4,r5}
	stm r0!, {r2,r4,r5}
	ldm r1!, {r3-r5}
	stm r0!, {r3-r5}
	subs r0, r7, 0x1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	mov r9, r1
	cmp r0, 0x3
	bhi _0814232A
	movs r2, 0x3
	mov r9, r2
_0814232A:
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 8
	ldr r3, =0xffff0000
	adds r0, r3
	lsrs r0, 16
	mov r8, r0
	adds r0, r7, 0
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _08142390
	cmp r0, 0x2
	bgt _08142368
	cmp r0, 0x1
	beq _0814237C
	ldr r4, =gUnknown_0203AB88
	mov r12, r4
	b _081423D4
	.pool
_08142368:
	cmp r0, 0x3
	beq _081423A4
	cmp r0, 0x4
	beq _081423B8
	ldr r5, =gUnknown_0203AB88
	mov r12, r5
	b _081423D4
	.pool
_0814237C:
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203AB88
	ldr r0, [r2]
	adds r0, 0x43
	b _081423C0
	.pool
_08142390:
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203AB88
	ldr r0, [r2]
	adds r0, 0x44
	b _081423C0
	.pool
_081423A4:
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203AB88
	ldr r0, [r2]
	adds r0, 0x45
	b _081423C0
	.pool
_081423B8:
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203AB88
	ldr r0, [r2]
	adds r0, 0x46
_081423C0:
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	lsls r0, 4
	mov r8, r0
	mov r12, r2
_081423D4:
	mov r0, r9
	cmp r0, 0x1
	bne _08142430
	mov r1, r12
	ldr r4, [r1]
	ldr r1, =gUnknown_085B6154
	lsls r2, r7, 2
	adds r0, r2, r7
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r1, [r4, 0x8]
	ldr r0, [r0]
	ands r1, r0
	str r2, [sp, 0x1C]
	cmp r1, 0
	bne _081424E2
	adds r0, r7, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	subs r1, r0, 0x1
	lsls r1, 3
	mov r3, sp
	adds r2, r3, r1
	ldrh r1, [r2, 0x2]
	add r1, r8
	strh r1, [r2, 0x2]
	adds r1, r4, 0
	adds r1, 0xB8
	lsls r0, 3
	subs r0, 0x8
	adds r2, r3, r0
	adds r0, r1, 0
	movs r1, 0xD
	bl sub_815168C
	b _081424C4
	.pool
_08142430:
	movs r4, 0
	lsls r5, r7, 2
	str r5, [sp, 0x1C]
	ldr r0, =gUnknown_085B6154
	mov r10, r0
_0814243A:
	lsls r0, r4, 2
	adds r0, r4
	adds r0, r7, r0
	adds r0, 0x5
	lsls r0, 24
	lsrs r3, r0, 24
	mov r1, r12
	ldr r5, [r1]
	lsls r0, r3, 2
	adds r0, r3
	lsls r6, r0, 2
	mov r0, r10
	adds r0, 0x8
	adds r0, r6, r0
	ldr r1, [r5, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _081424B0
	adds r0, r3, 0
	movs r1, 0x5
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	subs r1, r0, 0x1
	lsls r1, 3
	mov r3, sp
	adds r2, r3, r1
	ldrh r1, [r2, 0x2]
	add r1, r8
	strh r1, [r2, 0x2]
	adds r3, r5, 0
	adds r3, 0xB8
	adds r1, r4, 0
	adds r1, 0xD
	lsls r1, 24
	lsrs r1, 24
	lsls r0, 3
	subs r0, 0x8
	mov r5, sp
	adds r2, r5, r0
	adds r0, r3, 0
	bl sub_815168C
	mov r0, r9
	cmp r0, 0x3
	bne _081424A2
	mov r1, r10
	adds r0, r6, r1
	ldrh r0, [r0, 0x10]
	str r0, [sp, 0x18]
_081424A2:
	mov r0, r9
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r2, =gUnknown_0203AB88
	mov r12, r2
_081424B0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0814243A
	mov r3, r9
	cmp r3, 0x2
	beq _081424C4
	movs r4, 0
	str r4, [sp, 0x18]
_081424C4:
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r2, =gUnknown_085B6154
	ldr r5, [sp, 0x1C]
	adds r1, r5, r7
	lsls r1, 2
	adds r1, r2
	ldrh r1, [r1, 0x10]
	ldr r2, [sp, 0x18]
	orrs r2, r1
	str r2, [sp, 0x18]
	adds r1, r2, 0
	bl sub_8151A48
_081424E2:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142284

	thumb_func_start sub_81424FC
sub_81424FC: @ 81424FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_0203AB88
	ldr r1, [r4]
	movs r0, 0x1
	strh r0, [r1, 0x2A]
	movs r0, 0
	movs r1, 0
	bl sub_8142E70
	ldr r1, [r4]
	ldr r2, =0x0000117c
	adds r0, r1, r2
	ldr r2, =0x0000397c
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0x10
	str r2, [sp]
	movs r2, 0xD
	str r2, [sp, 0x4]
	movs r2, 0xE
	movs r3, 0x7
	bl sub_8152058
	cmp r5, 0xF
	bhi _081425FC
	lsls r0, r5, 2
	ldr r1, =_08142558
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08142558:
	.4byte _08142738
	.4byte _08142598
	.4byte _08142598
	.4byte _08142598
	.4byte _08142598
	.4byte _081425CC
	.4byte _081425FC
	.4byte _081425FC
	.4byte _081425FC
	.4byte _081425FC
	.4byte _081425CC
	.4byte _081425FC
	.4byte _081425FC
	.4byte _081425FC
	.4byte _081425FC
	.4byte _081425CC
_08142598:
	movs r0, 0x4
	str r0, [sp, 0x18]
	add r1, sp, 0x8
	movs r0, 0
	strb r0, [r1]
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0x3
	bhi _08142604
	add r4, sp, 0x10
	adds r3, r1, 0
_081425AE:
	ldrb r2, [r3]
	adds r2, r4
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r5, r0
	strb r0, [r2]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldrb r0, [r3]
	ldr r1, [sp, 0x18]
	cmp r0, r1
	bcc _081425AE
	b _08142604
_081425CC:
	movs r2, 0x5
	str r2, [sp, 0x18]
	add r1, sp, 0x8
	movs r0, 0
	strb r0, [r1]
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _08142604
	add r3, sp, 0x10
	adds r2, r1, 0
_081425E2:
	ldrb r1, [r2]
	adds r1, r3
	ldrb r0, [r2]
	adds r0, r5, r0
	strb r0, [r1]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldrb r0, [r2]
	ldr r1, [sp, 0x18]
	cmp r0, r1
	bcc _081425E2
	b _08142604
_081425FC:
	movs r2, 0x1
	str r2, [sp, 0x18]
	add r0, sp, 0x10
	strb r5, [r0]
_08142604:
	add r1, sp, 0x8
	movs r0, 0
	strb r0, [r1]
	adds r0, r1, 0
	ldrb r0, [r0]
	ldr r1, [sp, 0x18]
	cmp r0, r1
	bcc _08142616
	b _08142738
_08142616:
	mov r2, sp
	adds r2, 0xE
	str r2, [sp, 0x1C]
	add r0, sp, 0x10
	mov r10, r0
	add r1, sp, 0x8
	mov r9, r1
	subs r2, 0x4
	str r2, [sp, 0x20]
_08142628:
	mov r1, r9
	ldrb r0, [r1]
	add r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r2, =gUnknown_085B6154
	adds r0, r2
	ldrb r0, [r0, 0x6]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	mov r2, r9
	ldrb r0, [r2]
	add r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_085B6154
	adds r0, r1
	ldrb r0, [r0, 0x3]
	ldr r2, [sp, 0x20]
	strh r0, [r2]
	mov r7, sp
	adds r7, 0x9
	movs r0, 0
	strb r0, [r7]
	ldrb r0, [r7]
	cmp r0, 0x2
	bhi _08142726
	add r6, sp, 0xC
	mov r8, r2
	ldr r0, [sp, 0x1C]
	mov r12, r0
	ldr r1, =gUnknown_0203AB88
	str r1, [sp, 0x28]
_08142672:
	mov r2, r9
	ldrb r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_085B6154
	adds r1, r0
	str r7, [sp, 0x24]
	ldrb r0, [r7]
	ldrb r1, [r1, 0x4]
	adds r0, r1
	lsls r0, 5
	strh r0, [r6]
	ldr r1, [sp, 0x28]
	ldr r4, [r1]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r2, [r6]
	adds r2, r0
	lsls r2, 1
	ldr r0, =0x0000117c
	adds r5, r4, r0
	adds r2, r5, r2
	mov r1, r12
	ldrb r0, [r1]
	ldrb r1, [r7]
	adds r1, r0
	ldr r0, =0x0000397c
	adds r4, r0
	ldr r3, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r0, r3
	movs r1, 0xD0
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r2, [r6]
	adds r2, r0
	adds r2, 0x1
	lsls r2, 1
	adds r2, r5, r2
	mov r1, r12
	ldrb r0, [r1]
	ldrb r1, [r7]
	adds r1, r0
	ldr r3, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r0, r3
	movs r1, 0xD1
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	mov r2, r8
	ldrh r1, [r2]
	ldrh r0, [r6]
	adds r0, r1
	adds r0, 0x2
	lsls r0, 1
	adds r5, r0
	mov r1, r12
	ldrb r0, [r1]
	ldrb r1, [r7]
	adds r1, r0
	ldr r2, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r0, r2
	movs r2, 0xD2
	lsls r2, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r5]
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	ldr r1, [sp, 0x24]
	ldrb r0, [r1]
	cmp r0, 0x2
	bls _08142672
_08142726:
	mov r2, r9
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldrb r0, [r2]
	ldr r1, [sp, 0x18]
	cmp r0, r1
	bcs _08142738
	b _08142628
_08142738:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81424FC

	thumb_func_start sub_8142758
sub_8142758: @ 8142758
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_085B6448
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x13
	bls _08142770
	movs r4, 0
_08142770:
	ldr r3, =gUnknown_085B6154
	lsls r0, r4, 2
	adds r0, r4
	lsls r2, r0, 2
	adds r0, r2, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 28
	lsrs r0, 28
	cmp r0, 0x4
	beq _081427C4
	cmp r0, 0x4
	bgt _08142798
	cmp r0, 0x3
	beq _0814279E
	b _08142808
	.pool
_08142798:
	cmp r0, 0xC
	beq _081427E8
	b _08142808
_0814279E:
	adds r0, r4, 0
	movs r1, 0x5
	bl __udivsi3
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x16
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0x3
	bhi _08142808
	ldrb r0, [r1]
	adds r0, 0x1
	b _081427DC
	.pool
_081427C4:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x12
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _08142808
	ldrb r0, [r1]
	adds r0, 0x2
_081427DC:
	add r0, sp
	ldrb r0, [r0]
	b _0814280A
	.pool
_081427E8:
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	adds r0, r3, 0
	adds r0, 0x8
	adds r0, r2, r0
	ldr r1, [r1, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08142808
	mov r0, sp
	ldrb r0, [r0, 0x4]
	b _0814280A
	.pool
_08142808:
	movs r0, 0
_0814280A:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8142758

	thumb_func_start sub_8142814
sub_8142814: @ 8142814
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	ldrh r1, [r0, 0x2C]
	movs r0, 0x20
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x2E]
	movs r0, 0x22
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x30]
	movs r0, 0x24
	bl SetGpuReg
	ldr r0, [r4]
	ldrh r1, [r0, 0x32]
	movs r0, 0x26
	bl SetGpuReg
	ldr r3, [r4]
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	ldr r0, =gSpriteCoordOffsetY
	movs r4, 0
	ldrsh r2, [r0, r4]
	adds r2, 0x50
	adds r0, r1, 0
	muls r0, r2
	movs r4, 0xE8
	lsls r4, 7
	subs r4, r0
	movs r6, 0x2C
	ldrsh r5, [r3, r6]
	ldr r0, =gSpriteCoordOffsetX
	movs r6, 0
	ldrsh r1, [r0, r6]
	adds r1, 0x74
	adds r0, r5, 0
	muls r0, r1
	subs r4, r0
	movs r5, 0x32
	ldrsh r0, [r3, r5]
	muls r0, r2
	movs r5, 0xA8
	lsls r5, 7
	subs r5, r0
	movs r6, 0x30
	ldrsh r0, [r3, r6]
	muls r0, r1
	subs r5, r0
	lsls r1, r4, 16
	lsrs r1, 16
	movs r0, 0x28
	bl SetGpuReg
	ldr r6, =0x0fff0000
	ands r4, r6
	lsrs r4, 16
	movs r0, 0x2A
	adds r1, r4, 0
	bl SetGpuReg
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0x2C
	bl SetGpuReg
	ands r5, r6
	lsrs r5, 16
	movs r0, 0x2E
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142814

	thumb_func_start sub_81428C4
sub_81428C4: @ 81428C4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl DisplayYesNoMenu
	ldr r1, =gUnknown_085B6408
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81428C4

	thumb_func_start sub_81428E4
sub_81428E4: @ 81428E4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08142908
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_81405CC
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08142908:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81428E4

	thumb_func_start sub_8142918
sub_8142918: @ 8142918
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0x1
	bl sub_819746C
	bl HideCoinsWindow
	bl FreeAllWindowBuffers
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	lsls r1, 26
	lsrs r1, 26
	ldrb r3, [r2, 0x4]
	movs r0, 0x40
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x4]
	bl UpdatePaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81428E4
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142918

	thumb_func_start sub_814297C
sub_814297C: @ 814297C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	bl sub_819746C
	bl HideCoinsWindow
	bl ScriptContext2_Disable
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_814297C

	thumb_func_start sub_81429A0
sub_81429A0: @ 81429A0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081429DE
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x1
	strh r0, [r1]
	bl HideCoinsWindow
	movs r0, 0
	movs r1, 0x1
	bl sub_819746C
	bl ScriptContext2_Disable
	adds r0, r4, 0
	bl DestroyTask
_081429DE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81429A0

	thumb_func_start sub_81429F0
sub_81429F0: @ 81429F0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08142A60
	ldr r2, =gUnknown_085B6344
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	lsrs r1, 7
	lsls r1, 1
	adds r0, r1
	adds r0, r2
	ldrb r1, [r0]
	ldr r0, =gStringVar1
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_082A5B12
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	str r5, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81428C4
	str r1, [r0]
_08142A60:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81429F0

	thumb_func_start sub_8142A88
sub_8142A88: @ 8142A88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r6, r0, r1
	movs r1, 0x22
	ldrsh r0, [r6, r1]
	bl PrintCoinsString
	ldr r2, =gUnknown_085B6344
	ldr r0, =gSpecialVar_0x8004
	mov r8, r0
	ldrh r1, [r0]
	movs r7, 0x1
	adds r0, r7, 0
	ands r0, r1
	lsrs r1, 7
	lsls r1, 1
	adds r0, r1
	adds r0, r2
	ldrb r4, [r0]
	ldr r0, =gStringVar1
	adds r1, r4, 0
	movs r2, 0x2
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	movs r1, 0x22
	ldrsh r0, [r6, r1]
	cmp r0, r4
	blt _08142B78
	mov r0, r8
	ldrh r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08142B28
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08142B28
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	ldr r2, =gUnknown_082A5B6B
	str r7, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_81429F0
	str r0, [r6]
	b _08142BB0
	.pool
_08142B28:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_082A5B12
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81428C4
	str r1, [r0]
	b _08142BB0
	.pool
_08142B78:
	ldr r5, =gStringVar4
	ldr r1, =gUnknown_082A5B4E
	adds r0, r5, 0
	bl StringExpandPlaceholders
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawStdWindowFrame
	str r7, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_81429A0
	str r0, [r6]
	strh r4, [r6, 0x22]
	strh r4, [r6, 0x8]
_08142BB0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142A88

	thumb_func_start sub_8142BC8
sub_8142BC8: @ 8142BC8
	push {r4,lr}
	bl ScriptContext2_Enable
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	movs r2, 0x1
	bl ShowCoinsWindow
	ldr r0, =sub_8142A88
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl GetCoins
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r2
	strh r0, [r1, 0x22]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142BC8

	thumb_func_start sub_8142C0C
sub_8142C0C: @ 8142C0C
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _08142C44
	bl FreeAllSpritePalettes
	ldr r0, =gUnknown_085B7384
	bl LoadSpritePalettes
	ldr r0, =gUnknown_085B7864
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_085B7978
	bl LoadCompressedSpriteSheet
	ldr r0, =gUnknown_085B7A40
	bl LoadCompressedSpriteSheet
	b _08142C5A
	.pool
_08142C44:
	movs r0, 0xE
	bl FreeSpriteTilesByTag
	movs r0, 0xD
	bl FreeSpriteTilesByTag
	movs r0, 0xC
	bl FreeSpriteTilesByTag
	bl FreeAllSpritePalettes
_08142C5A:
	pop {r0}
	bx r0
	thumb_func_end sub_8142C0C

	thumb_func_start sub_8142C60
sub_8142C60: @ 8142C60
	push {r4-r6,lr}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r0, 0x4]
	ldrb r3, [r1]
	movs r1, 0x74
	movs r2, 0x50
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r0, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r6]
	strh r0, [r1, 0x2E]
	strh r4, [r1, 0x30]
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	adds r1, 0x2C
	ldrb r0, [r1]
	movs r2, 0x40
	orrs r0, r2
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r1]
	ldrh r2, [r6]
	adds r0, r2, 0
	adds r0, 0x1E
	strh r0, [r6]
	lsls r0, 16
	ldr r1, =0x01670000
	cmp r0, r1
	bls _08142CBC
	ldr r1, =0xfffffeb6
	adds r0, r2, r1
	strh r0, [r6]
_08142CBC:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8142C60

	thumb_func_start sub_8142CD0
sub_8142CD0: @ 8142CD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, =gUnknown_085B7488
	ldr r0, [r4]
	ldr r5, =gDecompressionBuffer
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp]
	mov r6, sp
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	ldr r4, =gUnknown_085B7490
	ldr r0, [r4]
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp]
	ldrh r0, [r4, 0x4]
	strh r0, [r6, 0x4]
	ldrh r0, [r4, 0x6]
	strh r0, [r6, 0x6]
	mov r0, sp
	bl LoadSpriteSheet
	movs r6, 0
	ldr r0, =gSprites
	mov r8, r0
_08142D18:
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 27
	lsrs r4, r0, 24
	movs r5, 0
	lsls r7, r6, 2
_08142D24:
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	ldr r0, =gSpriteTemplate_85B75B0
	adds r0, r1, r0
	adds r1, 0x94
	adds r2, r4, 0
	adds r2, 0x5C
	movs r3, 0x1E
	bl CreateSprite
	ldr r1, =gUnknown_0203AB88
	ldr r1, [r1]
	adds r2, r5, 0
	adds r2, 0x1D
	adds r2, r7, r2
	adds r1, 0x3C
	adds r1, r2
	strb r0, [r1]
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x18
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x47
	bls _08142D6E
	movs r4, 0
_08142D6E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08142D24
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _08142D18
	movs r6, 0
	ldr r4, =gSprites
_08142D86:
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	ldr r0, =gSpriteTemplate_85B7508
	adds r0, r1, r0
	adds r1, 0x94
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x46
	movs r3, 0x1E
	bl CreateSprite
	ldr r1, =gUnknown_0203AB88
	ldr r1, [r1]
	adds r1, r6
	adds r1, 0x65
	strb r0, [r1]
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _08142D86
	movs r6, 0
	ldr r4, =gSprites
_08142DCC:
	lsls r2, r6, 1
	adds r2, r6
	lsls r2, 3
	ldr r0, =gSpriteTemplate_85B7568
	adds r0, r2, r0
	adds r2, 0x5C
	lsls r2, 16
	asrs r2, 16
	movs r1, 0x7E
	movs r3, 0x1E
	bl CreateSprite
	ldr r1, =gUnknown_0203AB88
	ldr r1, [r1]
	adds r1, r6
	adds r1, 0x69
	strb r0, [r1]
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _08142DCC
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142CD0

	thumb_func_start sub_8142E3C
sub_8142E3C: @ 8142E3C
	push {r4,lr}
	movs r4, 0
_08142E40:
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, r4
	adds r0, 0x59
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xB
	bls _08142E40
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142E3C

	thumb_func_start sub_8142E70
sub_8142E70: @ 8142E70
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r12, r1
	cmp r0, 0
	beq _08142EC0
	cmp r0, 0x1
	bne _08142F66
	movs r4, 0
	ldr r5, =gSprites
	ldr r3, =gUnknown_0203AB88
	movs r2, 0x4
_08142E92:
	ldr r0, [r3]
	adds r0, r4
	adds r0, 0x59
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x12
	bls _08142E92
	b _08142F66
	.pool
_08142EC0:
	movs r4, 0
	ldr r0, =gUnknown_0203AB88
	mov r9, r0
	ldr r7, =gUnknown_085B62E4
	adds r1, r7, 0x4
	mov r8, r1
	ldr r5, =gSprites
	movs r6, 0x5
	negs r6, r6
_08142ED2:
	mov r0, r9
	ldr r2, [r0]
	lsls r3, r4, 3
	mov r1, r8
	adds r0, r3, r1
	ldr r1, [r2, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08142F14
	adds r0, r3, r7
	ldrb r0, [r0, 0x2]
	cmp r0, r12
	beq _08142F14
	adds r0, r2, r4
	adds r0, 0x59
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08142F2C
	.pool
_08142F14:
	adds r0, r2, r4
	adds r0, 0x59
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
_08142F2C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xB
	bls _08142ED2
	cmp r4, 0x12
	bhi _08142F66
	ldr r6, =gSprites
	ldr r3, =gUnknown_0203AB88
	movs r5, 0x5
	negs r5, r5
_08142F42:
	ldr r0, [r3]
	adds r0, r4
	adds r0, 0x59
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x12
	bls _08142F42
_08142F66:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142E70

	thumb_func_start sub_8142F7C
sub_8142F7C: @ 8142F7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	ldr r6, =gUnknown_0203AB88
	ldr r4, =gSprites
	movs r0, 0x4
	mov r8, r0
_08142F8C:
	ldr r0, =gSpriteTemplate_85B7928
	movs r1, 0x74
	movs r2, 0x14
	movs r3, 0xA
	bl CreateSprite
	ldr r1, [r6]
	adds r3, r5, 0
	adds r3, 0x31
	adds r1, 0x3C
	adds r1, r3
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	mov r2, r8
	orrs r1, r2
	strb r1, [r0]
	ldr r2, [r6]
	adds r2, 0x3C
	adds r2, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_814390C
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	movs r7, 0xD
	negs r7, r7
	adds r2, r7, 0
	ands r1, r2
	mov r2, r8
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r0, [r6]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x8
	bl StartSpriteAnim
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08142F8C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8142F7C

	thumb_func_start sub_8143038
sub_8143038: @ 8143038
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r6, 0
	cmp r0, 0
	beq _08143084
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203AB88
	movs r2, 0x4
_08143056:
	ldr r0, [r3]
	adds r0, r6
	adds r0, 0x6D
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _08143056
	b _08143142
	.pool
_08143084:
	ldr r0, =gUnknown_0203AB88
	mov r8, r0
	ldr r7, =gSprites
	ldr r0, =gUnknown_085B6154
	mov r12, r0
	movs r0, 0x5
	negs r0, r0
	mov r10, r0
_08143094:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xC
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _081430A8
	cmp r6, r9
	bne _081430D0
_081430A8:
	adds r0, r1, r6
	adds r0, 0x6D
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _08143138
	.pool
_081430D0:
	adds r5, r6, 0
	adds r5, 0x31
	adds r0, r1, 0
	adds r0, 0x3C
	adds r0, r5
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	mov r0, r10
	ands r0, r2
	strb r0, [r1]
	mov r0, r8
	ldr r3, [r0]
	adds r4, r3, 0
	adds r4, 0x3C
	adds r4, r5
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r7
	adds r3, 0xC
	adds r3, r6
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r0, [r0, 0x3]
	adds r0, 0x1
	lsls r0, 3
	adds r0, 0x4
	strh r0, [r2, 0x20]
	ldrb r0, [r4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r7
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r0, [r0, 0x4]
	adds r0, 0x1
	lsls r0, 3
	adds r0, 0x3
	strh r0, [r2, 0x22]
_08143138:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _08143094
_08143142:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8143038

	thumb_func_start sub_8143150
sub_8143150: @ 8143150
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08143180
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x6C
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _081431D0
	.pool
_08143180:
	ldr r4, =gSprites
	ldr r3, =gUnknown_0203AB88
	ldr r0, [r3]
	adds r0, 0x6C
	ldrb r1, [r0]
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
	ldr r3, [r3]
	adds r3, 0x6C
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldr r0, =gUnknown_085B6154
	lsls r2, r5, 2
	adds r2, r5
	lsls r2, 2
	adds r2, r0
	ldrb r0, [r2, 0x3]
	adds r0, 0x2
	lsls r0, 3
	strh r0, [r1, 0x20]
	ldrb r0, [r3]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r2, 0x4]
	adds r0, 0x2
	lsls r0, 3
	strh r0, [r1, 0x22]
_081431D0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143150

	thumb_func_start sub_81431E4
sub_81431E4: @ 81431E4
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r4, =gUnknown_085B741C
	ldr r0, [r4]
	ldr r5, =gDecompressionBuffer
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	ldrh r2, [r4, 0x6]
	lsls r2, 16
	ldrh r1, [r4, 0x4]
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadSpriteSheet
	movs r1, 0xF
	mov r0, sp
	strh r1, [r0]
	movs r0, 0
	ldr r7, =gSprites
_08143210:
	movs r4, 0
	adds r6, r0, 0x1
	lsls r5, r0, 2
_08143216:
	adds r1, r5, r4
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	ldr r1, =gSpriteTemplate_85B7610
	adds r0, r1
	movs r1, 0x28
	mov r2, sp
	bl sub_8142C60
	ldr r1, =gUnknown_0203AB88
	ldr r1, [r1]
	adds r2, r4, 0x7
	adds r2, r5, r2
	adds r1, 0x3C
	adds r1, r2
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x2C
	ldrb r0, [r1]
	movs r2, 0x40
	orrs r0, r2
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _08143216
	lsls r0, r6, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _08143210
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81431E4

	thumb_func_start sub_8143280
sub_8143280: @ 8143280
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	ldrh r0, [r6, 0x2E]
	ldrh r1, [r1, 0x24]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r1, r0, 16
	ldr r0, =0x00000167
	cmp r1, r0
	ble _081432A2
	ldr r2, =0xfffffe98
	adds r0, r1, r2
	lsls r0, 16
	lsrs r4, r0, 16
_081432A2:
	adds r0, r4, 0
	bl Sin2
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	bl Cos2
	lsls r2, r5, 16
	asrs r2, 16
	movs r3, 0x30
	ldrsh r1, [r6, r3]
	muls r1, r2
	asrs r1, 12
	strh r1, [r6, 0x24]
	lsls r0, 16
	asrs r4, r0, 16
	negs r1, r4
	movs r3, 0x30
	ldrsh r0, [r6, r3]
	muls r0, r1
	asrs r0, 12
	strh r0, [r6, 0x26]
	ldrb r0, [r6, 0x3]
	lsls r0, 26
	lsrs r3, r0, 27
	cmp r2, 0
	bge _081432DC
	adds r2, 0xF
_081432DC:
	lsls r0, r2, 12
	lsrs r5, r0, 16
	ldr r1, =gOamMatrices
	lsls r0, r3, 3
	adds r1, r0, r1
	adds r0, r4, 0
	cmp r0, 0
	bge _081432EE
	adds r0, 0xF
_081432EE:
	asrs r0, 4
	strh r0, [r1, 0x6]
	strh r0, [r1]
	strh r5, [r1, 0x2]
	lsls r0, r5, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r1, 0x4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143280

	thumb_func_start sub_8143314
sub_8143314: @ 8143314
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r5, 0
	ldr r7, =gDecompressionBuffer
	mov r6, sp
_08143322:
	ldr r0, =gUnknown_085B7750
	lsls r4, r5, 3
	adds r4, r0
	ldr r0, [r4]
	adds r1, r7, 0
	bl LZ77UnCompWram
	str r7, [sp]
	ldrh r2, [r4, 0x4]
	ldr r0, =0xffff0000
	ldr r1, [r6, 0x4]
	ands r1, r0
	orrs r1, r2
	str r1, [r6, 0x4]
	ldrh r2, [r4, 0x6]
	lsls r2, 16
	ldr r0, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [r6, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _08143322
	ldr r0, =gSpriteTemplate_85B77E4
	movs r1, 0xD0
	movs r2, 0x10
	movs r3, 0x4
	bl CreateSprite
	ldr r3, =gUnknown_0203AB88
	ldr r1, [r3]
	adds r1, 0x50
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r0, [r3]
	adds r0, 0x50
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	movs r5, 0
	adds r7, r3, 0
_0814338C:
	lsls r1, r5, 19
	movs r0, 0xC4
	lsls r0, 16
	adds r1, r0
	asrs r1, 16
	ldr r0, =gUnknown_085B77FC
	movs r2, 0x18
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7]
	adds r3, r5, 0
	adds r3, 0x15
	adds r1, 0x3C
	adds r1, r3
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r6, 0x40
	orrs r1, r6
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _0814338C
	ldr r0, =gUnknown_085B7814
	movs r1, 0x78
	movs r2, 0x44
	movs r3, 0x4
	bl CreateSprite
	ldr r2, =gUnknown_0203AB88
	ldr r1, [r2]
	adds r1, 0x55
	strb r0, [r1]
	ldr r3, =gSprites
	ldr r0, [r2]
	adds r0, 0x55
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x2C
	ldrb r1, [r0]
	orrs r1, r6
	strb r1, [r0]
	movs r5, 0
	adds r4, r2, 0
	adds r7, r3, 0
_0814341C:
	lsls r1, r5, 20
	movs r2, 0xC0
	lsls r2, 16
	adds r1, r2
	asrs r1, 16
	ldr r0, =gUnknown_085B782C
	movs r2, 0x24
	movs r3, 0x4
	bl CreateSprite
	ldr r1, [r4]
	adds r2, r5, 0
	adds r2, 0x1A
	adds r1, 0x3C
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x3C
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x4
	mov r8, r3
	mov r3, r8
	orrs r1, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x3C
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r6, 0x40
	orrs r1, r6
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x2
	bls _0814341C
	ldr r0, =gUnknown_085B7844
	movs r1, 0x98
	movs r2, 0x60
	movs r3, 0x9
	bl CreateSprite
	ldr r3, =gUnknown_0203AB88
	ldr r1, [r3]
	adds r1, 0x6C
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r0, [r3]
	adds r0, 0x6C
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r3]
	adds r0, 0x6C
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x2C
	ldrb r1, [r0]
	orrs r1, r6
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, 0x6C
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143314

	thumb_func_start sub_8143514
sub_8143514: @ 8143514
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r7, r0, 16
	movs r0, 0xFA
	lsls r0, 2
	mov r8, r0
	movs r4, 0
	movs r6, 0
	ldr r1, =gSprites
	mov r9, r1
	ldr r0, =gUnknown_0203AB88
	mov r10, r0
_08143534:
	adds r0, r7, 0
	mov r1, r8
	bl __udivsi3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_0203AB88
	ldr r0, [r1]
	adds r3, r6, 0
	adds r3, 0x15
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	cmp r5, 0
	bne _0814356E
	cmp r4, 0
	bne _0814356E
	cmp r6, 0x3
	bne _081435CC
_0814356E:
	mov r4, r10
	ldr r0, [r4]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r4, 0x5
	negs r4, r4
	adds r2, r4, 0
	ands r1, r2
	strb r1, [r0]
	mov r1, r10
	ldr r0, [r1]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	mov r4, r9
	adds r3, r0, r4
	adds r4, r3, 0
	adds r4, 0x40
	ldr r1, =gSprites + 8
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r1
	ldrh r2, [r0]
	ldrh r4, [r4]
	adds r2, r4
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r2, r0
	ldrh r0, [r3, 0x4]
	ldr r4, =0xfffffc00
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x4]
	movs r4, 0x1
_081435CC:
	adds r0, r7, 0
	mov r1, r8
	bl __umodsi3
	lsls r0, 16
	lsrs r7, r0, 16
	mov r0, r8
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _08143534
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143514

	thumb_func_start sub_8143614
sub_8143614: @ 8143614
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_085B7B04
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	cmp r4, 0x13
	bls _0814362C
	movs r4, 0
_0814362C:
	ldr r3, =gUnknown_085B6154
	lsls r0, r4, 2
	adds r0, r4
	lsls r2, r0, 2
	adds r0, r2, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 28
	lsrs r0, 28
	cmp r0, 0x4
	beq _08143680
	cmp r0, 0x4
	bgt _08143654
	cmp r0, 0x3
	beq _0814365A
	b _081436C4
	.pool
_08143654:
	cmp r0, 0xC
	beq _081436A4
	b _081436C4
_0814365A:
	adds r0, r4, 0
	movs r1, 0x5
	bl __udivsi3
	subs r0, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x16
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0x3
	bhi _081436C4
	ldrb r0, [r1]
	adds r0, 0x1
	b _08143698
	.pool
_08143680:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x12
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _081436C4
	ldrb r0, [r1]
	adds r0, 0x2
_08143698:
	add r0, sp
	ldrb r0, [r0]
	b _081436C6
	.pool
_081436A4:
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	adds r0, r3, 0
	adds r0, 0x8
	adds r0, r2, r0
	ldr r1, [r1, 0x8]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _081436C4
	mov r0, sp
	ldrb r0, [r0, 0x4]
	b _081436C6
	.pool
_081436C4:
	movs r0, 0
_081436C6:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8143614

	thumb_func_start sub_81436D0
sub_81436D0: @ 81436D0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203AB88
	ldr r1, [r1]
	adds r1, 0x55
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gSprites
	adds r4, r1, r2
	bl sub_8143614
	adds r3, r4, 0
	adds r3, 0x2B
	strb r0, [r3]
	adds r2, r4, 0
	adds r2, 0x40
	ldr r1, [r4, 0x8]
	ldrb r0, [r3]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r4, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81436D0

	thumb_func_start sub_814372C
sub_814372C: @ 814372C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r6, 0
	ldr r1, =gUnknown_0203AB88
	ldr r0, [r1]
	ldrb r0, [r0, 0x19]
	adds r5, r1, 0
	cmp r0, 0x1
	bne _08143746
	movs r6, 0x2
_08143746:
	cmp r2, 0x6
	bls _0814374C
	b _081438A8
_0814374C:
	lsls r0, r2, 2
	ldr r1, =_08143760
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08143760:
	.4byte _081438A8
	.4byte _08143864
	.4byte _0814383C
	.4byte _08143830
	.4byte _08143808
	.4byte _081437FC
	.4byte _0814377C
_0814377C:
	movs r4, 0
	ldr r5, =gSprites
	ldr r6, =gUnknown_0203AB88
	movs r0, 0x5
	negs r0, r0
	mov r12, r0
	adds r7, r5, 0
	adds r7, 0x8
	ldr r2, =0xfffffc00
	mov r8, r2
_08143790:
	ldr r0, [r6]
	adds r3, r4, 0
	adds r3, 0x1A
	adds r0, 0x3C
	adds r0, r3
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r2, [r1]
	mov r0, r12
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r5
	adds r2, r3, 0
	adds r2, 0x40
	adds r0, r7
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _08143790
	b _081438F4
	.pool
_081437FC:
	ldr r2, =gSprites
	ldr r0, [r5]
	adds r0, 0x58
	b _0814386A
	.pool
_08143808:
	ldr r2, =gSprites
	ldr r0, [r5]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r2
	adds r4, r3, 0
	adds r4, 0x40
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r0, r1
	ldrh r1, [r0, 0x8]
	b _08143886
	.pool
_08143830:
	ldr r2, =gSprites
	ldr r0, [r5]
	adds r0, 0x57
	b _0814386A
	.pool
_0814383C:
	ldr r2, =gSprites
	ldr r0, [r5]
	adds r0, 0x57
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r2
	adds r4, r3, 0
	adds r4, 0x40
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r0, r1
	ldrh r1, [r0, 0x8]
	b _08143886
	.pool
_08143864:
	ldr r2, =gSprites
	ldr r0, [r5]
	adds r0, 0x56
_0814386A:
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r2
	adds r4, r3, 0
	adds r4, 0x40
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r6, 2
	adds r0, r1
	ldrh r1, [r0, 0x4]
_08143886:
	ldrh r4, [r4]
	adds r1, r4
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	b _081438F4
	.pool
_081438A8:
	movs r4, 0
	lsls r7, r6, 2
	ldr r6, =gSprites
	movs r0, 0x8
	adds r0, r6
	mov r12, r0
	ldr r2, =0xfffffc00
	mov r8, r2
_081438B8:
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x56
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, r0, r6
	adds r2, r3, 0
	adds r2, 0x40
	add r0, r12
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, r7, r0
	ldrh r1, [r0, 0x8]
	ldrh r2, [r2]
	adds r1, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081438B8
_081438F4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814372C

	thumb_func_start sub_814390C
sub_814390C: @ 814390C
	ldr r1, =gUnknown_0203AB88
	ldr r1, [r1]
	ldrh r1, [r1, 0x26]
	strh r1, [r0, 0x24]
	bx lr
	.pool
	thumb_func_end sub_814390C

	thumb_func_start sub_814391C
sub_814391C: @ 814391C
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r4, =gUnknown_085B7948
	ldr r0, [r4]
	ldr r5, =gDecompressionBuffer
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp]
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	ldr r0, =gSpriteTemplate_85B7950
	movs r1, 0x74
	movs r2, 0x50
	movs r3, 0x51
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldrh r0, [r0, 0x24]
	movs r2, 0
	strh r0, [r1, 0x2E]
	strh r2, [r1, 0x30]
	adds r3, r1, 0
	adds r3, 0x2C
	ldrb r0, [r3]
	movs r2, 0x40
	orrs r0, r2
	movs r2, 0x80
	orrs r0, r2
	strb r0, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814391C

	thumb_func_start sub_814399C
sub_814399C: @ 814399C
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	ldr r1, =gOamMatrices
	lsls r0, 3
	adds r0, r1
	ldr r1, =gUnknown_0203AB88
	ldr r2, [r1]
	ldrh r1, [r2, 0x2C]
	strh r1, [r0, 0x6]
	ldrh r1, [r2, 0x2C]
	strh r1, [r0]
	ldrh r1, [r2, 0x2E]
	strh r1, [r0, 0x2]
	ldrh r1, [r2, 0x30]
	strh r1, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_814399C

	thumb_func_start sub_81439C8
sub_81439C8: @ 81439C8
	push {r4-r6,lr}
	movs r4, 0
	ldr r5, =gUnknown_0203AB88
	ldr r6, =gSprites
_081439D0:
	movs r3, 0x39
	subs r3, r4
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gSpriteTemplate_85B7928
	movs r1, 0x74
	movs r2, 0x50
	bl CreateSprite
	ldr r1, [r5]
	adds r1, 0x3C
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x3C
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0x40
	beq _08143A24
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x3C
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_08143A24:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081439D0
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81439C8

	thumb_func_start sub_8143A40
sub_8143A40: @ 8143A40
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x3C
	ldrb r5, [r0]
	movs r6, 0
	ldr r7, =gSprites
	movs r0, 0x1C
	adds r0, r7
	mov r10, r0
	movs r1, 0x2E
	adds r1, r7
	mov r9, r1
	mov r8, r6
_08143A64:
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r0, r4, r7
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r3]
	mov r1, r10
	adds r2, r4, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r2]
	movs r1, 0
	bl StartSpriteAnim
	movs r1, 0
	adds r2, r5, 0x1
	adds r3, r6, 0x1
_08143A8C:
	lsls r0, r1, 1
	adds r0, r4
	add r0, r9
	mov r5, r8
	strh r5, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x7
	bls _08143A8C
	lsls r0, r2, 24
	lsrs r5, r0, 24
	lsls r0, r3, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _08143A64
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143A40

	thumb_func_start sub_8143AC8
sub_8143AC8: @ 8143AC8
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldrh r4, [r0, 0x24]
	movs r2, 0x24
	ldrsh r1, [r0, r2]
	ldrh r2, [r3, 0x34]
	movs r5, 0x34
	ldrsh r0, [r3, r5]
	cmp r1, r0
	ble _08143B04
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r2, r1
	subs r2, r0, r4
	strh r2, [r3, 0x3A]
	lsls r1, r2, 16
	ldr r0, =0x01670000
	cmp r1, r0
	ble _08143B08
	ldr r5, =0xfffffe98
	adds r0, r2, r5
	b _08143B06
	.pool
_08143B04:
	subs r0, r2, r4
_08143B06:
	strh r0, [r3, 0x3A]
_08143B08:
	movs r1, 0x3A
	ldrsh r0, [r3, r1]
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8143AC8

	thumb_func_start sub_8143B14
sub_8143B14: @ 8143B14
	push {r4,r5,lr}
	bl sub_8143AC8
	ldr r5, =gUnknown_0203AB88
	ldr r4, [r5]
	lsls r0, 16
	asrs r0, 16
	bl __floatsisf
	ldr r1, =0x41f00000
	bl __divsf3
	bl __fixunssfsi
	adds r4, 0x7E
	strb r0, [r4]
	ldr r0, [r5]
	adds r0, 0x7E
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8143B14

	thumb_func_start sub_8143B48
sub_8143B48: @ 8143B48
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8143AC8
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1E
	bl __modsi3
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0xE
	bne _08143B68
	movs r0, 0
	strh r0, [r4, 0x32]
	b _08143B7E
_08143B68:
	cmp r1, 0xD
	bgt _08143B70
	movs r0, 0xE
	b _08143B72
_08143B70:
	movs r0, 0x2B
_08143B72:
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 16
_08143B7E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8143B48

	thumb_func_start sub_8143B84
sub_8143B84: @ 8143B84
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	ldr r5, _08143BCC  @ =gUnknown_0203AB88
	ldr r6, [r5]
	adds r4, r6, 0
	adds r4, 0x8C
	adds r1, r6, 0
	adds r1, 0x90
	ldr r0, [r4]
	ldr r1, [r1]
	bl __addsf3
	adds r1, r0, 0
	str r1, [r4]
	subs r4, 0x4
	ldr r0, [r4]
	bl __addsf3
	adds r6, r0, 0
	str r6, [r4]
	ldr r0, _08143BD0  @ =0x43B40000
	mov r8, r0
	adds r0, r6, 0
	mov r1, r8
	bl __gesf2
	cmp r0, 0
	blt _08143BD4
	adds r0, r6, 0
	mov r1, r8
	bl __subsf3
	b _08143BE8
	.align 2, 0
_08143BCC:
	.4byte gUnknown_0203AB88
_08143BD0:
	.4byte 0x43B40000
_08143BD4:
	ldr r1, _08143C80  @ =0x00000000
	adds r0, r6, 0
	bl __ltsf2
	cmp r0, 0
	bge _08143BEA
	adds r0, r6, 0
	mov r1, r8
	bl __addsf3
_08143BE8:
	str r0, [r4]
_08143BEA:
	ldr r5, [r5]
	adds r0, r5, 0
	adds r0, 0x88
	ldr r0, [r0]
	bl __fixsfsi
	strh r0, [r7, 0x34]
	adds r4, r5, 0
	adds r4, 0x98
	adds r1, r5, 0
	adds r1, 0x9C
	ldr r0, [r4]
	ldr r1, [r1]
	bl __addsf3
	adds r1, r0, 0
	str r1, [r4]
	subs r4, 0x4
	ldr r0, [r4]
	bl __addsf3
	str r0, [r4]
	bl __fixsfsi
	strh r0, [r7, 0x36]
	ldrh r0, [r7, 0x34]
	bl Sin2
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrh r0, [r7, 0x34]
	bl Cos2
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x36
	ldrsh r1, [r7, r2]
	muls r1, r4
	asrs r1, 12
	strh r1, [r7, 0x24]
	lsls r0, 16
	asrs r0, 16
	negs r0, r0
	movs r2, 0x36
	ldrsh r1, [r7, r2]
	muls r0, r1
	asrs r0, 12
	strh r0, [r7, 0x26]
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _08143C74
	ldr r0, _08143C84  @ =gMPlayInfo_SE1
	ldr r4, _08143C88  @ =0x0000FFFF
	ldrh r2, [r7, 0x24]
	lsls r2, 24
	asrs r2, 24
	adds r1, r4, 0
	bl m4aMPlayPanpotControl
	ldr r0, _08143C8C  @ =gMPlayInfo_SE2
	ldrh r2, [r7, 0x24]
	lsls r2, 24
	asrs r2, 24
	adds r1, r4, 0
	bl m4aMPlayPanpotControl
_08143C74:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08143C80:
	.4byte 0x00000000
_08143C84:
	.4byte gMPlayInfo_SE1
_08143C88:
	.4byte 0x0000FFFF
_08143C8C:
	.4byte gMPlayInfo_SE2
	thumb_func_end sub_8143B84

	thumb_func_start sub_8143C90
sub_8143C90: @ 8143C90
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203AB88
	ldr r1, [r0]
	ldrh r0, [r5, 0x3A]
	ldrh r1, [r1, 0x24]
	adds r2, r0, r1
	strh r2, [r5, 0x34]
	lsls r1, r2, 16
	ldr r0, =0x01670000
	cmp r1, r0
	ble _08143CAE
	ldr r1, =0xfffffe98
	adds r0, r2, r1
	strh r0, [r5, 0x34]
_08143CAE:
	ldrh r0, [r5, 0x34]
	bl Sin2
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrh r0, [r5, 0x34]
	bl Cos2
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	muls r1, r4
	asrs r1, 12
	strh r1, [r5, 0x24]
	lsls r0, 16
	asrs r0, 16
	negs r0, r0
	movs r2, 0x36
	ldrsh r1, [r5, r2]
	muls r0, r1
	ldr r1, =gSpriteCoordOffsetY
	asrs r0, 12
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r5, 0x26]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143C90

	thumb_func_start sub_8143CFC
sub_8143CFC: @ 8143CFC
	push {r4-r7,lr}
	adds r5, r0, 0
	bl sub_8143B84
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x36]
	adds r0, 0x84
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xD4
	bls _08143D22
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _08143D2E
_08143D22:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
_08143D2E:
	strb r0, [r2]
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0x1D
	ble _08143DF8
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08143D6C
	ldr r7, _08143D64  @ =gUnknown_0203AB88
	ldr r6, [r7]
	adds r4, r6, 0
	adds r4, 0x94
	adds r0, r6, 0
	adds r0, 0xA0
	ldr r0, [r0]
	ldr r1, _08143D68  @ =0x40000000
	bl __subsf3
	adds r1, r0, 0
	ldr r0, [r4]
	bl __lesf2
	cmp r0, 0
	bgt _08143DF8
	b _08143D8C
	.align 2, 0
_08143D64:
	.4byte gUnknown_0203AB88
_08143D68:
	.4byte 0x40000000
_08143D6C:
	ldr r7, _08143E00  @ =gUnknown_0203AB88
	ldr r6, [r7]
	adds r4, r6, 0
	adds r4, 0x94
	adds r0, r6, 0
	adds r0, 0xA0
	ldr r0, [r0]
	ldr r1, _08143E04  @ =0x40000000
	bl __subsf3
	adds r1, r0, 0
	ldr r0, [r4]
	bl __gesf2
	cmp r0, 0
	blt _08143DF8
_08143D8C:
	adds r1, r6, 0
	adds r1, 0x7D
	movs r0, 0xFF
	strb r0, [r1]
	ldr r2, [r7]
	ldrb r1, [r2, 0x3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x3]
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	adds r1, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0
	bl sub_8143B14
	movs r0, 0x1E
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_8143AC8
	movs r1, 0x3A
	ldrsh r0, [r5, r1]
	movs r1, 0x1E
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	adds r1, 0xF
	strh r1, [r5, 0x3A]
	ldr r0, _08143E08  @ =sub_8143C90
	str r0, [r5, 0x1C]
	movs r0, 0x47
	bl m4aSongNumStartOrChange
	ldr r3, [r7]
	adds r2, r3, 0
	adds r2, 0x9C
	adds r1, r3, 0
	adds r1, 0x98
	ldr r0, _08143E0C  @ =0x00000000
	str r0, [r1]
	str r0, [r2]
	subs r1, 0xC
	ldr r0, _08143E10  @ =0xBF800000
	str r0, [r1]
_08143DF8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08143E00:
	.4byte gUnknown_0203AB88
_08143E04:
	.4byte 0x40000000
_08143E08:
	.4byte sub_8143C90
_08143E0C:
	.4byte 0x00000000
_08143E10:
	.4byte 0xBF800000
	thumb_func_end sub_8143CFC

	thumb_func_start sub_8143E14
sub_8143E14: @ 8143E14
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	bl sub_8143B84
	movs r1, 0x34
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _08143E32
	cmp r0, 0xB4
	beq _08143E9C
	b _08143F80
_08143E32:
	movs r1, 0x2E
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	bne _08143E3C
	b _08143F80
_08143E3C:
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	bl __floatsisf
	mov r9, r0
	ldr r0, =gUnknown_085B6348
	mov r10, r0
	ldr r1, =gUnknown_0203AB88
	mov r8, r1
	ldr r0, [r1]
	ldrb r4, [r0, 0x4]
	lsls r4, 30
	lsrs r0, r4, 25
	add r0, r10
	ldrb r0, [r0, 0x1]
	bl __floatsisf
	adds r1, r0, 0
	mov r0, r9
	bl __mulsf3
	adds r6, r0, 0
	lsrs r0, r4, 25
	add r0, r10
	ldrb r0, [r0, 0x2]
	subs r0, 0x1
	bl __floatsisf
	adds r1, r0, 0
	adds r0, r6, 0
	bl __addsf3
	adds r5, r0, 0
	lsrs r4, 25
	add r4, r10
	ldrh r0, [r4, 0xC]
	bl __floatsisf
	adds r1, r0, 0
	mov r0, r9
	bl __divsf3
	b _08143EFC
	.pool
_08143E9C:
	movs r1, 0x2E
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _08143F80
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	bl __floatsisf
	mov r9, r0
	ldr r0, _08143F90  @ =gUnknown_085B6348
	mov r10, r0
	ldr r1, _08143F94  @ =gUnknown_0203AB88
	mov r8, r1
	ldr r0, [r1]
	ldrb r4, [r0, 0x4]
	lsls r4, 30
	lsrs r0, r4, 25
	add r0, r10
	ldrb r0, [r0, 0x1]
	bl __floatsisf
	adds r1, r0, 0
	mov r0, r9
	bl __mulsf3
	adds r6, r0, 0
	lsrs r0, r4, 25
	add r0, r10
	ldrb r0, [r0, 0x2]
	subs r0, 0x1
	bl __floatsisf
	adds r1, r0, 0
	adds r0, r6, 0
	bl __addsf3
	adds r5, r0, 0
	lsrs r4, 25
	add r4, r10
	ldrh r0, [r4, 0xC]
	bl __floatsisf
	adds r1, r0, 0
	mov r0, r9
	bl __divsf3
	bl __negsf2
_08143EFC:
	adds r2, r0, 0
	mov r0, r8
	ldr r6, [r0]
	adds r1, r6, 0
	adds r1, 0xA0
	adds r0, r6, 0
	adds r0, 0x94
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0
	adds r0, 0x98
	str r2, [r0]
	movs r0, 0x9C
	adds r0, r6
	mov r8, r0
	adds r0, r2, 0
	adds r1, r2, 0
	bl __addsf3
	adds r1, r5, 0
	bl __divsf3
	adds r4, r0, 0
	adds r0, r5, 0
	adds r1, r5, 0
	bl __mulsf3
	adds r1, r0, 0
	ldr r0, _08143F98  @ =0x40000000
	bl __divsf3
	adds r1, r0, 0
	adds r0, r4, 0
	bl __addsf3
	bl __negsf2
	mov r1, r8
	str r0, [r1]
	adds r1, r6, 0
	adds r1, 0x8C
	ldr r0, _08143F9C  @ =0x00000000
	str r0, [r1]
	adds r2, r7, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r7, 0
	adds r0, 0x2A
	movs r2, 0
	strb r2, [r0]
	adds r3, r7, 0
	adds r3, 0x3F
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r3]
	ldr r0, _08143FA0  @ =sub_8143CFC
	str r0, [r7, 0x1C]
	strh r2, [r7, 0x32]
_08143F80:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08143F90:
	.4byte gUnknown_085B6348
_08143F94:
	.4byte gUnknown_0203AB88
_08143F98:
	.4byte 0x40000000
_08143F9C:
	.4byte 0x00000000
_08143FA0:
	.4byte sub_8143CFC
	thumb_func_end sub_8143E14

	thumb_func_start sub_8143FA4
sub_8143FA4: @ 8143FA4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	bl __floatsisf
	adds r4, r0, 0
	ldr r1, =0x3d4ccccd
	bl __mulsf3
	adds r1, r4, 0
	bl __mulsf3
	bl __fixsfsi
	adds r1, r0, 0
	subs r1, 0x2D
	strh r1, [r5, 0x26]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1D
	ble _0814403E
	lsls r0, r1, 16
	cmp r0, 0
	blt _0814403E
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	adds r0, 0x7D
	movs r1, 0xFF
	strb r1, [r0]
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x3]
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	adds r1, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0
	bl sub_8143B14
	movs r0, 0x1E
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_8143AC8
	movs r1, 0x3A
	ldrsh r0, [r5, r1]
	movs r1, 0x1E
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	adds r1, 0xF
	strh r1, [r5, 0x3A]
	ldr r0, =sub_8143C90
	str r0, [r5, 0x1C]
	movs r0, 0x47
	bl m4aSongNumStartOrChange
	ldr r2, [r4]
	ldrb r0, [r2, 0x3]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0x3]
_0814403E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8143FA4

	thumb_func_start sub_8144050
sub_8144050: @ 8144050
	push {r4,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x32]
	adds r1, r0, 0x1
	strh r1, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2C
	bgt _08144098
	ldrh r4, [r3, 0x26]
	subs r0, r4, 0x1
	strh r0, [r3, 0x26]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x2D
	bne _0814411E
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x73
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0814411E
	strh r4, [r3, 0x26]
	b _0814411E
	.pool
_08144098:
	lsls r0, r1, 16
	asrs r0, 16
	movs r2, 0x3C
	ldrsh r1, [r3, r2]
	cmp r0, r1
	bge _081440E4
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x73
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bne _0814411E
	adds r0, r1, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081440DC
	ldrh r0, [r3, 0x26]
	adds r0, 0x1
	strh r0, [r3, 0x26]
	b _0814411E
	.pool
_081440DC:
	ldrh r0, [r3, 0x26]
	subs r0, 0x1
	strh r0, [r3, 0x26]
	b _0814411E
_081440E4:
	adds r2, r3, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x3F
	adds r0, r3
	mov r12, r0
	ldrb r0, [r0]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	mov r1, r12
	strb r0, [r1]
	strh r2, [r3, 0x32]
	ldr r0, =sub_8143FA4
	str r0, [r3, 0x1C]
	movs r0, 0x3D
	bl m4aSongNumStart
_0814411E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144050

	thumb_func_start sub_8144128
sub_8144128: @ 8144128
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8143B84
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	cmp r1, 0x5A
	beq _08144142
	movs r0, 0x87
	lsls r0, 1
	cmp r1, r0
	beq _0814414C
	b _0814415C
_08144142:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0814415C
	b _08144154
_0814414C:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0814415C
_08144154:
	ldr r0, =sub_8144050
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x32]
_0814415C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144128

	thumb_func_start sub_8144168
sub_8144168: @ 8144168
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8143B84
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	lsls r0, 27
	lsrs r0, 27
	cmp r0, 0
	beq _08144182
	cmp r0, 0x1
	beq _08144194
_08144182:
	adds r0, r4, 0
	bl sub_81446DC
	ldr r0, =sub_8143E14
	b _0814419C
	.pool
_08144194:
	adds r0, r4, 0
	bl sub_81448B8
	ldr r0, =sub_8144128
_0814419C:
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144168

	thumb_func_start prev_quest_read_x24_hm_usage
prev_quest_read_x24_hm_usage: @ 81441A8
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8143B84
	ldrh r0, [r5, 0x32]
	subs r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	bne _081441CE
	ldr r0, =gUnknown_0203AB88
	ldr r4, [r0]
	adds r4, 0x98
	ldr r0, [r4]
	ldr r1, =0xbf800000
	bl __mulsf3
	str r0, [r4]
_081441CE:
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0814425C
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _08144244
	ldr r2, =gUnknown_0203AB88
	ldr r0, [r2]
	adds r0, 0x7D
	movs r1, 0xFF
	strb r1, [r0]
	ldr r2, [r2]
	ldrb r1, [r2, 0x3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x3]
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	adds r1, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0
	bl sub_8143B14
	movs r0, 0x1E
	strh r0, [r5, 0x36]
	adds r0, r5, 0
	bl sub_8143AC8
	movs r1, 0x3A
	ldrsh r0, [r5, r1]
	movs r1, 0x1E
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	adds r1, 0xF
	strh r1, [r5, 0x3A]
	ldr r0, =sub_8143C90
	str r0, [r5, 0x1C]
	movs r0, 0x47
	bl m4aSongNumStartOrChange
	b _0814425C
	.pool
_08144244:
	adds r0, r5, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0x38
	bl m4aSongNumStart
	adds r0, r5, 0
	bl sub_8144A24
_0814425C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end prev_quest_read_x24_hm_usage

	thumb_func_start sub_8144264
sub_8144264: @ 8144264
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	bl sub_8143B84
	movs r0, 0
	strh r0, [r6, 0x32]
	adds r0, r6, 0
	bl sub_8143B14
	ldr r1, _081442F0  @ =gUnknown_085B62E4
	ldr r4, _081442F4  @ =gUnknown_0203AB88
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x7E
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x8]
	ands r0, r1
	cmp r0, 0
	bne _081442FC
	adds r1, r2, 0
	adds r1, 0x7D
	movs r0, 0xFF
	strb r0, [r1]
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x3]
	adds r0, r6, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	adds r1, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl StartSpriteAnim
	adds r0, r6, 0
	bl sub_8143B14
	movs r0, 0x1E
	strh r0, [r6, 0x36]
	adds r0, r6, 0
	bl sub_8143AC8
	movs r1, 0x3A
	ldrsh r0, [r6, r1]
	movs r1, 0x1E
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	adds r1, 0xF
	strh r1, [r6, 0x3A]
	ldr r0, _081442F8  @ =sub_8143C90
	str r0, [r6, 0x1C]
	movs r0, 0x47
	bl m4aSongNumStartOrChange
	b _081443F8
	.align 2, 0
_081442F0:
	.4byte gUnknown_085B62E4
_081442F4:
	.4byte gUnknown_0203AB88
_081442F8:
	.4byte sub_8143C90
_081442FC:
	movs r0, 0x38
	bl m4aSongNumStart
	bl Random
	movs r1, 0x1
	mov r8, r1
	ands r1, r0
	mov r8, r1
	cmp r1, 0
	beq _08144340
	ldr r4, [r4]
	adds r1, r4, 0
	adds r1, 0x8C
	ldr r0, _08144338  @ =0x00000000
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x7E
	ldrb r0, [r0]
	adds r0, 0x1
	movs r1, 0xC
	bl __modsi3
	lsls r1, r0, 24
	lsrs r2, r1, 24
	adds r1, r4, 0
	adds r1, 0x7F
	strb r0, [r1]
	ldr r5, _0814433C  @ =gUnknown_085B6348
	b _08144378
_08144338:
	.4byte 0x00000000
_0814433C:
	.4byte gUnknown_085B6348
_08144340:
	ldr r7, [r4]
	adds r4, r7, 0
	adds r4, 0x8C
	ldr r5, =gUnknown_085B6348
	ldrb r0, [r7, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	adds r0, r1, 0
	bl __addsf3
	str r0, [r4]
	adds r0, r7, 0
	adds r0, 0x7E
	ldrb r4, [r0]
	adds r0, r4, 0
	adds r0, 0xB
	movs r1, 0xC
	bl __modsi3
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r7, 0
	adds r0, 0x7F
	strb r4, [r0]
_08144378:
	ldr r0, =gUnknown_085B62E4
	lsls r1, r2, 3
	adds r0, 0x4
	adds r1, r0
	ldr r2, =gUnknown_0203AB88
	ldr r3, [r2]
	ldr r1, [r1]
	ldr r0, [r3, 0x8]
	ands r1, r0
	cmp r1, 0
	beq _081443AC
	movs r0, 0x1
	strh r0, [r6, 0x2E]
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r5
	ldrb r0, [r0, 0x2]
	strh r0, [r6, 0x32]
	b _081443E8
	.pool
_081443AC:
	strh r1, [r6, 0x2E]
	ldrb r1, [r3, 0x4]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081443C4
	lsls r0, r1, 30
	lsrs r0, 25
	adds r0, r5
	ldrb r0, [r0, 0x1]
	strh r0, [r6, 0x32]
	b _081443E8
_081443C4:
	lsls r0, r1, 30
	lsrs r0, 25
	adds r0, r5
	ldrb r0, [r0, 0x2]
	strh r0, [r6, 0x32]
	mov r0, r8
	cmp r0, 0
	beq _081443E0
	adds r1, r3, 0
	adds r1, 0x8C
	ldr r0, =0x3f000000
	b _081443E6
	.pool
_081443E0:
	adds r1, r3, 0
	adds r1, 0x8C
	ldr r0, =0xbfc00000
_081443E6:
	str r0, [r1]
_081443E8:
	ldr r0, [r2]
	adds r0, 0x98
	ldr r1, =0x3dae147b
	str r1, [r0]
	ldr r0, =prev_quest_read_x24_hm_usage
	str r0, [r6, 0x1C]
	movs r0, 0x5
	strh r0, [r6, 0x30]
_081443F8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144264

	thumb_func_start sub_8144410
sub_8144410: @ 8144410
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	bl sub_8143B84
	ldr r4, _081444A4  @ =gUnknown_0203AB88
	ldr r0, [r4]
	adds r0, 0x8C
	ldr r0, [r0]
	ldr r1, _081444A8  @ =0x3F000000
	bl __gtsf2
	cmp r0, 0
	bgt _081444FA
	adds r0, r6, 0
	bl sub_8143B14
	adds r0, r6, 0
	bl sub_8143B48
	lsls r0, 16
	cmp r0, 0
	bne _081444BC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x90
	ldr r0, _081444AC  @ =0x00000000
	str r0, [r1]
	movs r0, 0x8C
	adds r0, r2
	mov r8, r0
	ldr r1, _081444B0  @ =gUnknown_085B6348
	mov r9, r1
	ldrb r0, [r2, 0x4]
	lsls r7, r0, 30
	lsrs r0, r7, 25
	add r0, r9
	movs r4, 0x3
	ldrsb r4, [r0, r4]
	adds r0, r4, 0
	bl __floatsisf
	adds r5, r0, 0
	cmp r4, 0
	bge _08144476
	ldr r1, _081444B4  @ =0x43800000
	bl __addsf3
	adds r5, r0, 0
_08144476:
	lsrs r0, r7, 25
	add r0, r9
	ldrb r0, [r0, 0x4]
	adds r0, 0x1
	bl __floatsisf
	adds r1, r0, 0
	adds r0, r5, 0
	bl __divsf3
	adds r1, r0, 0
	mov r2, r8
	ldr r0, [r2]
	bl __subsf3
	mov r1, r8
	str r0, [r1]
	movs r0, 0x4
	strh r0, [r6, 0x30]
	ldr r0, _081444B8  @ =sub_8144264
	str r0, [r6, 0x1C]
	b _081444FA
	.align 2, 0
_081444A4:
	.4byte gUnknown_0203AB88
_081444A8:
	.4byte 0x3F000000
_081444AC:
	.4byte 0x00000000
_081444B0:
	.4byte gUnknown_085B6348
_081444B4:
	.4byte 0x43800000
_081444B8:
	.4byte sub_8144264
_081444BC:
	ldr r4, [r4]
	adds r7, r4, 0
	adds r7, 0x90
	ldr r0, [r7]
	ldr r6, _08144508  @ =0x00000000
	adds r1, r6, 0
	bl __nesf2
	cmp r0, 0
	beq _081444FA
	adds r5, r4, 0
	adds r5, 0x8C
	ldr r0, [r5]
	adds r1, r6, 0
	bl __ltsf2
	cmp r0, 0
	bge _081444FA
	str r6, [r7]
	str r6, [r5]
	adds r4, 0x98
	ldr r0, [r4]
	bl __extendsfdf2
	ldr r2, _0814450C  @ =0x3FF33333
	ldr r3, _08144510  @ =0x33333333
	bl __divdf3
	bl __truncdfsf2
	str r0, [r4]
_081444FA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144508:
	.4byte 0x00000000
_0814450C:
	.4byte 0x3FF33333
_08144510:
	.4byte 0x33333333
	thumb_func_end sub_8144410

	thumb_func_start sub_8144514
sub_8144514: @ 8144514
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	bl sub_8143B84
	ldr r0, =gUnknown_0203AB88
	ldr r5, [r0]
	adds r0, r5, 0
	adds r0, 0x94
	ldr r0, [r0]
	ldr r1, =0x42200000
	bl __gtsf2
	cmp r0, 0
	bgt _081445B8
	movs r0, 0x98
	adds r0, r5
	mov r8, r0
	adds r7, r5, 0
	adds r7, 0x86
	movs r1, 0
	ldrsh r4, [r7, r1]
	adds r0, r4, 0
	bl __floatsisf
	adds r2, r0, 0
	cmp r4, 0
	bge _08144556
	ldr r1, =0x47800000
	bl __addsf3
	adds r2, r0, 0
_08144556:
	ldr r0, =0x40800000
	adds r1, r2, 0
	bl __divsf3
	bl __negsf2
	mov r1, r8
	str r0, [r1]
	movs r0, 0x90
	adds r0, r5
	mov r8, r0
	adds r5, 0x8C
	movs r1, 0
	ldrsh r4, [r7, r1]
	adds r0, r4, 0
	bl __floatsisf
	adds r2, r0, 0
	cmp r4, 0
	bge _08144586
	ldr r1, =0x47800000
	bl __addsf3
	adds r2, r0, 0
_08144586:
	ldr r0, [r5]
	adds r1, r2, 0
	bl __divsf3
	bl __negsf2
	mov r1, r8
	str r0, [r1]
	adds r1, r6, 0
	adds r1, 0x2A
	movs r0, 0x2
	strb r0, [r1]
	adds r2, r6, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x3
	strh r0, [r6, 0x30]
	ldr r0, =sub_8144410
	str r0, [r6, 0x1C]
_081445B8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144514

	thumb_func_start sub_81445D8
sub_81445D8: @ 81445D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	bl sub_8143B84
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	adds r0, 0x94
	ldr r0, [r0]
	ldr r1, =0x42700000
	bl __gtsf2
	cmp r0, 0
	bgt _0814468A
	movs r0, 0x5D
	bl m4aSongNumStartOrChange
	ldr r5, [r4]
	movs r0, 0x98
	adds r0, r5
	mov r8, r0
	adds r7, r5, 0
	adds r7, 0x84
	movs r1, 0
	ldrsh r4, [r7, r1]
	adds r0, r4, 0
	bl __floatsisf
	adds r2, r0, 0
	cmp r4, 0
	bge _08144620
	ldr r1, =0x47800000
	bl __addsf3
	adds r2, r0, 0
_08144620:
	ldr r0, =0x41a00000
	adds r1, r2, 0
	bl __divsf3
	bl __negsf2
	mov r1, r8
	str r0, [r1]
	movs r0, 0x90
	adds r0, r5
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x8C
	ldr r1, [r0]
	ldr r0, =0x3f800000
	bl __subsf3
	adds r5, r0, 0
	movs r1, 0
	ldrsh r4, [r7, r1]
	adds r0, r4, 0
	bl __floatsisf
	adds r2, r0, 0
	cmp r4, 0
	bge _0814465C
	ldr r1, =0x47800000
	bl __addsf3
	adds r2, r0, 0
_0814465C:
	adds r0, r5, 0
	adds r1, r2, 0
	bl __divsf3
	mov r1, r8
	str r0, [r1]
	adds r1, r6, 0
	adds r1, 0x2A
	movs r0, 0x1
	strb r0, [r1]
	adds r2, r6, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x2
	strh r0, [r6, 0x30]
	ldr r0, =sub_8144514
	str r0, [r6, 0x1C]
_0814468A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81445D8

	thumb_func_start sub_81446AC
sub_81446AC: @ 81446AC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x32]
	adds r0, r4, 0
	bl sub_8143B84
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =sub_81445D8
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81446AC

	thumb_func_start sub_81446DC
sub_81446DC: @ 81446DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	ldr r1, =gUnknown_085B7B0A
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	mov r1, r8
	ldrh r0, [r1, 0x3C]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r5, =gUnknown_0203AB88
	ldr r0, =gSpriteTemplate_85B79F8
	movs r2, 0xC
	negs r2, r2
	movs r1, 0x24
	movs r3, 0x32
	bl CreateSprite
	ldr r1, [r5]
	adds r1, 0x73
	strb r0, [r1]
	ldr r4, =gSpriteTemplate_85B7ABC
	mov r3, r8
	movs r0, 0x2E
	ldrsh r2, [r3, r0]
	lsls r2, 2
	mov r1, sp
	adds r0, r1, r2
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r0, sp
	adds r0, 0x2
	adds r0, r2
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r0, r4, 0
	movs r3, 0x3B
	bl CreateSprite
	ldr r1, [r5]
	adds r1, 0x74
	strb r0, [r1]
	adds r4, 0x18
	adds r0, r4, 0
	movs r1, 0x24
	movs r2, 0x8C
	movs r3, 0x33
	bl CreateSprite
	ldr r1, [r5]
	adds r1, 0x75
	strb r0, [r1]
	ldr r3, =gSprites
	ldr r0, [r5]
	adds r0, 0x75
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r2, [r0, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r7, 0
	adds r6, r3, 0
	ldr r0, =gUnknown_085B6348
	mov r12, r0
	mov r10, r5
_0814477C:
	ldr r0, [r5]
	adds r3, r7, 0
	adds r3, 0x37
	adds r0, 0x3C
	adds r0, r3
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x3C
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r4, [r5]
	adds r2, r4, 0
	adds r2, 0x3C
	adds r2, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r1, r4, 0
	adds r1, 0x73
	ldrb r1, [r1]
	strh r1, [r0, 0x36]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r1, r4, 0
	adds r1, 0x74
	ldrb r1, [r1]
	strh r1, [r0, 0x38]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r1, r4, 0
	adds r1, 0x75
	ldrb r1, [r1]
	strh r1, [r0, 0x3A]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r9
	strh r1, [r0, 0x32]
	ldrb r0, [r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r6
	mov r0, r8
	movs r1, 0x3C
	ldrsh r3, [r0, r1]
	ldrb r1, [r4, 0x4]
	lsls r1, 30
	lsrs r0, r1, 25
	add r0, r12
	ldrb r0, [r0, 0x1]
	muls r3, r0
	lsrs r1, 25
	add r1, r12
	ldrb r0, [r1, 0x2]
	ldr r1, =0x0000ffff
	adds r0, r1
	adds r3, r0
	strh r3, [r2, 0x34]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gSprites
	cmp r7, 0x2
	bls _0814477C
	mov r3, r10
	ldr r0, [r3]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r3]
	mov r1, r8
	str r1, [r0, 0x38]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81446DC

	thumb_func_start sub_81448B8
sub_81448B8: @ 81448B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	ldr r1, =gUnknown_085B7B12
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	ldrh r0, [r7, 0x3C]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	ldr r0, =gSpriteTemplate_85B7A10
	movs r1, 0x2E
	ldrsh r2, [r7, r1]
	lsls r2, 2
	mov r3, sp
	adds r1, r3, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	mov r4, sp
	adds r4, 0x2
	adds r2, r4, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r3, 0x32
	bl CreateSprite
	ldr r5, =gUnknown_0203AB88
	ldr r1, [r5]
	adds r1, 0x73
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x73
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r6, =gSprites
	adds r0, r6
	ldrh r1, [r7, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAnim
	ldr r0, =gUnknown_085B7AEC
	movs r1, 0x2E
	ldrsh r2, [r7, r1]
	lsls r2, 2
	mov r3, sp
	adds r1, r3, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r4, r2
	movs r3, 0
	ldrsh r2, [r4, r3]
	movs r3, 0x33
	bl CreateSprite
	ldr r1, [r5]
	adds r1, 0x74
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	mov r0, r9
	lsls r2, r0, 16
	asrs r2, 16
	ldr r3, =gUnknown_085B6348
	ldr r0, [r5]
	ldrb r1, [r0, 0x4]
	lsls r1, 30
	lsrs r0, r1, 25
	adds r0, r3
	ldrb r0, [r0, 0x1]
	muls r2, r0
	lsrs r1, 25
	adds r1, r3
	ldrh r0, [r1, 0x10]
	adds r0, 0x2D
	adds r2, r0
	strh r2, [r7, 0x3C]
_08144992:
	ldr r0, =gUnknown_0203AB88
	ldr r4, [r0]
	mov r1, r8
	adds r2, r4, r1
	adds r2, 0x73
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r1, r4, 0
	adds r1, 0x73
	ldrb r1, [r1]
	strh r1, [r0, 0x36]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r3, r4, 0
	adds r3, 0x74
	ldrb r1, [r3]
	strh r1, [r0, 0x38]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r3]
	strh r1, [r0, 0x3A]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r3, r9
	strh r3, [r0, 0x32]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r7, 0x3C]
	subs r0, 0x2D
	strh r0, [r1, 0x34]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x1
	bls _08144992
	str r7, [r4, 0x38]
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81448B8

	thumb_func_start sub_8144A24
sub_8144A24: @ 8144A24
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r7, r0, 0
	movs r0, 0
	mov r9, r0
	movs r1, 0x5
	mov r8, r1
	str r0, [sp, 0xC]
	mov r0, sp
	movs r1, 0
	movs r2, 0xA
	bl memset
	bl Random
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	ldr r3, _08144B10  @ =gUnknown_0203AB88
	ldr r0, [r3]
	adds r0, 0x7D
	movs r5, 0x1
	strb r5, [r0]
	ldr r2, [r3]
	ldrb r0, [r2, 0x3]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x3]
	ldr r2, [r3]
	ldrb r1, [r2, 0x3]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r0, [r3]
	adds r0, 0x7E
	movs r1, 0xFF
	strb r1, [r0]
	ldr r6, [r3]
	adds r4, r6, 0
	adds r4, 0x88
	movs r1, 0x34
	ldrsh r0, [r7, r1]
	bl __floatsisf
	str r0, [r4]
	adds r1, r6, 0
	adds r1, 0x98
	ldr r0, _08144B14  @ =0x00000000
	str r0, [r1]
	adds r2, r6, 0
	adds r2, 0x8C
	ldr r1, _08144B18  @ =gUnknown_085B6348
	ldrb r0, [r6, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r0, [r6, 0x4]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 1
	adds r1, 0x21
	ldrb r0, [r6, 0x3]
	lsls r0, 27
	lsrs r0, 27
	subs r5, r0
	lsls r0, r5, 4
	subs r0, r5
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r5, r9
	movs r0, 0x34
	ldrsh r2, [r7, r0]
_08144ACA:
	cmp r1, r2
	bge _08144AD6
	adds r0, r1, 0
	adds r0, 0x5A
	cmp r2, r0
	ble _08144B38
_08144AD6:
	cmp r5, 0x3
	beq _08144B1C
	adds r0, r1, 0
	adds r0, 0x5A
	lsls r0, 16
	lsrs r1, r0, 16
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08144ACA
_08144AEC:
	ldr r0, _08144B10  @ =gUnknown_0203AB88
	ldr r0, [r0]
	ldrb r1, [r0, 0x3]
	movs r0, 0x1F
	ands r0, r1
	cmp r0, 0
	beq _08144B64
	movs r1, 0x2E
	ldrsh r0, [r7, r1]
	cmp r0, 0
	beq _08144B58
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	bl PlayCry1
	b _08144B70
	.align 2, 0
_08144B10:
	.4byte gUnknown_0203AB88
_08144B14:
	.4byte 0x00000000
_08144B18:
	.4byte gUnknown_085B6348
_08144B1C:
	movs r0, 0x1
	strh r0, [r7, 0x2E]
	ldr r0, =gUnknown_0203AB88
	ldr r2, [r0]
	ldrb r1, [r2, 0x3]
	movs r0, 0x20
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x3]
	b _08144AEC
	.pool
_08144B38:
	lsrs r0, r5, 1
	strh r0, [r7, 0x2E]
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	movs r1, 0x1
	ands r1, r5
	ldrb r2, [r3, 0x3]
	movs r0, 0x20
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	b _08144AEC
	.pool
_08144B58:
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	bl PlayCry1
	b _08144B70
_08144B64:
	movs r0, 0x99
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	bl PlayCry1
_08144B70:
	movs r0, 0x2
	mov r10, r0
	ldr r4, =gUnknown_0203AB88
	ldr r5, [r4]
	adds r0, r5, 0
	adds r0, 0x7F
	ldrb r0, [r0]
	adds r0, 0x2
	movs r1, 0xC
	bl __modsi3
	lsls r0, 24
	lsrs r6, r0, 24
	ldrb r1, [r5, 0x3]
	movs r0, 0x1F
	ands r0, r1
	cmp r0, 0x1
	bne _08144BA8
	ldrb r1, [r5, 0x4]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _08144BA8
	mov r0, r8
	adds r0, 0x6
	b _08144BAC
	.pool
_08144BA8:
	mov r0, r8
	add r0, r10
_08144BAC:
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r5, r10
	cmp r5, r8
	bcs _08144C18
	ldr r1, =gUnknown_085B6154+0xC
	mov r10, r1
_08144BBC:
	ldr r3, [r4]
	lsls r0, r6, 3
	ldr r1, =gUnknown_085B62E4+0x4
	adds r0, r1
	ldr r1, [r3, 0x8]
	ldr r2, [r0]
	ands r1, r2
	cmp r1, 0
	bne _08144C02
	mov r0, r9
	adds r1, r0, 0x1
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	add r0, sp
	strb r5, [r0]
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _08144C02
	ldrb r1, [r3, 0x1A]
	lsls r1, 28
	lsrs r1, 28
	adds r0, r3, 0
	adds r0, 0x1B
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _08144C02
	str r5, [sp, 0xC]
_08144C02:
	adds r0, r6, 0x1
	movs r1, 0xC
	bl __modsi3
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r8
	bcc _08144BBC
_08144C18:
	ldr r0, [r4]
	ldrb r1, [r0, 0x3]
	lsls r1, 27
	lsrs r1, 27
	adds r1, 0x1
	ldrb r0, [r0, 0x2]
	ands r1, r0
	cmp r1, 0
	beq _08144C48
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _08144C48
	movs r0, 0xFF
	ldr r1, [sp, 0x10]
	ands r0, r1
	cmp r0, 0xBF
	bhi _08144C48
	mov r0, sp
	ldrh r0, [r0, 0xC]
	b _08144C54
	.pool
_08144C48:
	ldr r0, [sp, 0x10]
	mov r1, r9
	bl __modsi3
	add r0, sp
	ldrb r0, [r0]
_08144C54:
	strh r0, [r7, 0x3C]
	ldr r1, =sub_8144168
	str r1, [r7, 0x1C]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144A24

	thumb_func_start sub_8144C70
sub_8144C70: @ 8144C70
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0x1
	strh r1, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _08144CC0
	ldrh r0, [r2, 0x20]
	subs r0, 0x2
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bge _08144CC0
	ldr r4, =gUnknown_0203AB88
	ldr r3, [r4]
	ldrb r1, [r3, 0x3]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08144CAC
	movs r0, 0x40
	orrs r0, r1
	strb r0, [r3, 0x3]
_08144CAC:
	adds r0, r2, 0
	bl DestroySprite
	ldr r1, [r4]
	movs r0, 0
	strb r0, [r1, 0x1]
	ldr r1, [r4]
	ldr r0, =gUnknown_085B7B1A
	ldrh r0, [r0]
	strh r0, [r1, 0x34]
_08144CC0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144C70

	thumb_func_start sub_8144CD0
sub_8144CD0: @ 8144CD0
	push {r4,lr}
	sub sp, 0x18
	adds r4, r0, 0
	ldr r1, =gUnknown_085B7B2E
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	ldrh r0, [r4, 0x30]
	adds r2, r0, 0x1
	strh r2, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x34
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _08144D54
	movs r0, 0x1
	ands r2, r0
	cmp r2, 0
	beq _08144D2E
	ldr r3, =gSpriteCoordOffsetY
	movs r0, 0x3C
	ldrsh r2, [r4, r0]
	lsls r2, 1
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 3
	adds r2, r0
	mov r1, sp
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r3]
	movs r3, 0x3C
	ldrsh r2, [r4, r3]
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _08144D26
	adds r0, r2, 0x4
_08144D26:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	strh r0, [r4, 0x3C]
_08144D2E:
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _08144D7E
	.pool
_08144D54:
	ldr r1, =gSpriteCoordOffsetY
	movs r0, 0
	strh r0, [r1]
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	adds r0, 0x73
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2C
	ldrb r2, [r0]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	adds r0, r4, 0
	bl DestroySprite
_08144D7E:
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144CD0

	thumb_func_start sub_8144D94
sub_8144D94: @ 8144D94
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	bl __floatsisf
	adds r4, r0, 0
	ldr r1, =0x3d1fbe77
	bl __mulsf3
	adds r1, r4, 0
	bl __mulsf3
	bl __fixsfsi
	strh r0, [r5, 0x26]
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r2, =gUnknown_085B7B1A
	ldrb r0, [r3, 0x1]
	subs r0, 0x1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3, 0x34]
	ldrb r0, [r3, 0x1]
	cmp r0, 0x12
	bhi _08144DDC
	adds r0, 0x1
	strb r0, [r3, 0x1]
_08144DDC:
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x3C
	ble _08144E3E
	movs r0, 0
	strh r0, [r5, 0x30]
	ldr r3, =sub_8144C70
	str r3, [r5, 0x1C]
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r2, 0
	adds r4, 0x1C
	adds r0, r4
	str r3, [r0]
	movs r0, 0x3A
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x30]
	movs r0, 0x38
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x38
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_8144CD0
	str r1, [r0]
	movs r0, 0xD6
	bl m4aSongNumStart
_08144E3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144D94

	thumb_func_start sub_8144E60
sub_8144E60: @ 8144E60
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08144EE4
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r1, [r3, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08144E94
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x8]
	b _08144EA6
	.pool
_08144E94:
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x8]
	adds r0, 0xB4
_08144EA6:
	cmp r2, r0
	bne _08144F7C
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	movs r0, 0x2B
	bl m4aSongNumStart
	ldr r2, =gUnknown_0203AB88
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	ldr r1, [r2]
	ldr r0, =gUnknown_085B7B1A
	ldrh r0, [r0]
	strh r0, [r1, 0x34]
	b _08144F7C
	.pool
_08144EE4:
	ldr r5, =gUnknown_0203AB88
	ldr r3, [r5]
	ldr r2, =gUnknown_085B7B1A
	ldrb r0, [r3, 0x1]
	subs r0, 0x1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r3, 0x34]
	ldrb r0, [r3, 0x1]
	cmp r0, 0x12
	bhi _08144F06
	adds r0, 0x1
	strb r0, [r3, 0x1]
_08144F06:
	ldr r3, [r5]
	ldr r1, [r3, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08144F30
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0xA]
	b _08144F42
	.pool
_08144F30:
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0xA]
	adds r0, 0xB4
_08144F42:
	cmp r2, r0
	bne _08144F7C
	ldr r2, =gSprites
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8144D94
	str r1, [r0]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	movs r0, 0
	strh r0, [r4, 0x3C]
_08144F7C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144E60

	thumb_func_start sub_8144F94
sub_8144F94: @ 8144F94
	adds r0, 0x3E
	ldrb r3, [r0]
	lsls r1, r3, 29
	lsrs r1, 31
	movs r2, 0x1
	eors r2, r1
	lsls r2, 2
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_8144F94

	thumb_func_start sub_8144FB0
sub_8144FB0: @ 8144FB0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x22]
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	ble _08144FC8
	subs r0, r2, 0x1
	strh r0, [r4, 0x22]
	b _0814501C
_08144FC8:
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	subs r2, 0x12
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x5E
	bl m4aSongNumStop
	adds r0, r4, 0
	bl DestroySprite
	ldr r5, =gSprites
	ldr r4, =gUnknown_0203AB88
	ldr r0, [r4]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldr r0, [r4]
	adds r0, 0x74
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl DestroySprite
_0814501C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8144FB0

	thumb_func_start sub_8145030
sub_8145030: @ 8145030
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _0814505A
	subs r1, 0x1
	strh r1, [r4, 0x30]
	ldrh r0, [r4, 0x22]
	subs r0, 0x1
	strh r0, [r4, 0x22]
	lsls r1, 16
	cmp r1, 0
	bne _081450C6
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081450C6
	b _08145080
_0814505A:
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _08145090
	subs r0, r1, 0x1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _081450C6
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08145088
_08145080:
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	b _081450C6
_08145088:
	ldrh r0, [r4, 0x26]
	subs r0, 0x1
	strh r0, [r4, 0x26]
	b _081450C6
_08145090:
	movs r0, 0x2B
	bl m4aSongNumStart
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	ldrh r1, [r0, 0x2E]
	adds r1, 0x4
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r0, =sub_8144FB0
	str r0, [r4, 0x1C]
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2C
	ldrb r2, [r0]
	movs r1, 0x7F
	ands r1, r2
	strb r1, [r0]
_081450C6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145030

	thumb_func_start sub_81450D8
sub_81450D8: @ 81450D8
	push {r4,r5,lr}
	sub sp, 0x14
	adds r4, r0, 0
	ldr r1, =gUnknown_085B7B46
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	add r5, sp, 0x4
	ldr r1, =gUnknown_085B7B48
	adds r0, r5, 0
	movs r2, 0x10
	bl memcpy
	ldrh r0, [r4, 0x30]
	subs r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0814516C
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	add r0, sp
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _08145208
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r4, 0x74
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	negs r4, r4
	ldr r0, =gMPlayInfo_SE1
	ldr r5, =0x0000ffff
	lsls r4, 24
	asrs r4, 24
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	ldr r0, =gMPlayInfo_SE2
	adds r1, r5, 0
	adds r2, r4, 0
	bl m4aMPlayPanpotControl
	b _08145208
	.pool
_0814516C:
	lsls r0, r1, 16
	cmp r0, 0
	blt _081451BC
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r0, r2]
	add r0, sp
	movs r2, 0
	ldrsb r2, [r0, r2]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x7
	subs r0, r1, r0
	lsls r0, 1
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	muls r0, r2
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	subs r1, r0
	lsls r1, 1
	mov r0, sp
	adds r0, 0x5
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	b _08145208
	.pool
_081451BC:
	movs r0, 0x5E
	bl m4aSongNumStartOrChange
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081451E0
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	bl PlayCry1
	b _081451EC
	.pool
_081451E0:
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x3F
	negs r1, r1
	bl PlayCry1
_081451EC:
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	ldrh r1, [r0, 0x2E]
	adds r1, 0x2
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	movs r0, 0x2D
	strh r0, [r4, 0x30]
	ldr r0, =sub_8145030
	str r0, [r4, 0x1C]
_08145208:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81450D8

	thumb_func_start sub_8145218
sub_8145218: @ 8145218
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_085B7B46
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	ldrh r0, [r4, 0x30]
	subs r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	blt _08145284
	ldr r0, =gUnknown_0203AB88
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	add r0, sp
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r4, 0x20]
	ldr r1, =gSprites
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	adds r2, 0x3E
	ldrb r3, [r2]
	lsls r0, r3, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	b _08145288
	.pool
_08145284:
	ldr r0, =sub_8144F94
	str r0, [r4, 0x1C]
_08145288:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145218

	thumb_func_start sub_8145294
sub_8145294: @ 8145294
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB88
	ldr r3, [r0]
	ldr r1, [r3, 0x38]
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _081452DC
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x12]
	adds r0, 0x5A
	cmp r2, r0
	bne _0814533E
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x34
	b _08145306
	.pool
_081452DC:
	movs r0, 0x34
	ldrsh r2, [r1, r0]
	ldr r1, =gUnknown_085B6348
	ldrb r0, [r3, 0x4]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r1
	ldrh r0, [r0, 0x14]
	movs r1, 0x87
	lsls r1, 1
	adds r0, r1
	cmp r2, r0
	bne _0814533E
	ldr r2, =gSprites
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x2E
_08145306:
	strh r3, [r0, 0x30]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r3, [r0, 0x30]
	movs r0, 0x3A
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8145218
	str r1, [r0]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =sub_81450D8
	str r1, [r0]
	movs r0, 0x2B
	bl m4aSongNumStart
_0814533E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145294

	.align 2, 0 @ Don't pad with nop.
