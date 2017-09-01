	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_817018C
sub_817018C: @ 817018C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCD0
	movs r0, 0x89
	lsls r0, 4
	bl Alloc
	str r0, [r4]
	ldr r1, =0x0000088c
	adds r2, r0, r1
	movs r1, 0
	strh r1, [r2]
	str r5, [r0]
	ldr r0, =sub_81701C4
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817018C

	thumb_func_start sub_81701C4
sub_81701C4: @ 81701C4
	push {lr}
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	bl ResetSpriteData
	bl ResetObjectPaletteAllocator
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E5068
	movs r0, 0x1
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085E5070
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x27
	movs r2, 0xD0
	bl sub_809882C
	bl clear_scheduled_bg_copies_to_vram
	ldr r0, =sub_8170274
	bl SetMainCallback2
	ldr r0, =sub_8170260
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81701C4

	thumb_func_start sub_8170260
sub_8170260: @ 8170260
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8170260

	thumb_func_start sub_8170274
sub_8170274: @ 8170274
	push {lr}
	bl sub_8170290
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	bl do_scheduled_bg_tilemap_copies_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_8170274

	thumb_func_start sub_8170290
sub_8170290: @ 8170290
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =gUnknown_0203BCD0
	ldr r0, [r1]
	ldr r2, =0x0000088c
	adds r0, r2
	ldrh r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x6
	bls _081702A6
	b _08170416
_081702A6:
	lsls r0, 2
	ldr r1, =_081702BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081702BC:
	.4byte _081702D8
	.4byte _08170300
	.4byte _08170358
	.4byte _08170380
	.4byte _08170394
	.4byte _081703C0
	.4byte _081703E8
_081702D8:
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	bl sub_8122CDC
	movs r0, 0
	movs r1, 0
	bl sub_8124288
	movs r0, 0x1
	movs r1, 0x1
	bl sub_81240D4
	ldr r1, [r4]
	ldr r0, =0x0000088c
	adds r1, r0
	b _081703D8
	.pool
_08170300:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x27
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r5, =gUnknown_085EE8F1
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0
	movs r2, 0x27
	movs r3, 0xD
	bl SetWindowBorderStyle
	bl sub_8170428
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	b _081703CC
	.pool
_08170358:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =gUnknown_0203BCD0
	ldr r1, [r0]
	ldr r0, =0x0000088c
	adds r1, r0
	b _081703D8
	.pool
_08170380:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08170416
	ldr r1, [r4]
	b _081703D4
	.pool
_08170394:
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _081703A6
	bl sub_8170428
	b _08170416
_081703A6:
	cmp r0, 0x3
	blt _08170416
	cmp r0, 0x5
	bgt _08170416
	ldr r0, =gUnknown_0203BCD0
	ldr r1, [r0]
	ldr r0, =0x0000088c
	adds r1, r0
	b _081703D8
	.pool
_081703C0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
_081703CC:
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BCD0
	ldr r1, [r0]
_081703D4:
	ldr r2, =0x0000088c
	adds r1, r2
_081703D8:
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _08170416
	.pool
_081703E8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08170416
	bl sub_812305C
	ldr r4, =gUnknown_0203BCD0
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	cmp r0, 0
	beq _08170412
	bl Free
	str r5, [r4]
_08170412:
	bl FreeAllWindowBuffers
_08170416:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170290

	thumb_func_start sub_8170428
sub_8170428: @ 8170428
	push {r4,lr}
	sub sp, 0xC
	ldr r4, =gUnknown_0203BCD0
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08170460
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, [r4]
	adds r2, 0xC
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	b _08170470
	.pool
_08170460:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08170470:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8170428

	.align 2, 0 @ Don't pad with nop.
