	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8133EDC
sub_8133EDC: @ 8133EDC
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x3
	bls _08133EE8
	movs r1, 0
_08133EE8:
	ldr r0, =gUnknown_085B1DF8
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8133EDC

	thumb_func_start sub_8133EF8
sub_8133EF8: @ 8133EF8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8133EF8

	thumb_func_start set_256color_bg_bg0
set_256color_bg_bg0: @ 8133F0C
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0xC
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
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
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	add r1, sp, 0x4
	movs r0, 0
	strh r0, [r1]
	ldr r2, =0x040000d4
	str r1, [r2]
	movs r1, 0xC0
	lsls r1, 19
	str r1, [r2, 0x4]
	ldr r0, =0x8100c000
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	mov r9, r0
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	str r0, [r2]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r2, 0x4]
	ldr r0, =0x85000100
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	add r0, sp, 0x4
	mov r3, r9
	strh r3, [r0]
	str r0, [r2]
	movs r0, 0xA0
	lsls r0, 19
	str r0, [r2, 0x4]
	ldr r0, =0x81000200
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	ldr r0, =gUnknown_085B0E04
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0A80
	ldr r1, =0x06003000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0C0C
	ldr r1, =0x06003800
	bl LZ77UnCompVram
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085B1E00
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085B1DCC
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r1, 0xAA
	lsls r1, 2
	movs r0, 0
	movs r2, 0xD0
	bl sub_809882C
	bl clear_scheduled_bg_copies_to_vram
	bl remove_some_task
	bl ResetTasks
	bl ResetSpriteData
	bl ResetPaletteFade
	bl FreeAllSpritePalettes
	bl dp13_810BB8C
	bl sub_8098C64
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_085B0A00
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	ldr r0, =gUnknown_085B1ED8
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085B1EE8
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085B1EF8
	bl LoadSpritePalettes
	movs r0, 0x1
	negs r0, r0
	mov r1, r9
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_8133EF8
	bl SetVBlankCallback
	ldr r0, =sub_81341E0
	bl SetMainCallback2
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x1F
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0xFE
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0x7
	bl SetGpuReg
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r0, =sub_81341FC
	movs r1, 0
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r3, 0x1
	mov r10, r3
	mov r1, r10
	strh r1, [r0, 0x8]
	ldr r0, =gUnknown_085B1F10
	movs r1, 0x78
	movs r2, 0x38
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gSprites
	mov r8, r3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	strh r4, [r1, 0x2E]
	ldr r6, =gUnknown_085B1F28
	ldr r5, =gUnknown_085B1DEC
	ldrb r1, [r5]
	ldrb r2, [r5, 0x1]
	adds r0, r6, 0
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	strh r4, [r1, 0x2E]
	mov r0, r9
	strh r0, [r1, 0x30]
	ldrb r1, [r5, 0x2]
	ldrb r2, [r5, 0x3]
	adds r0, r6, 0
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	strh r4, [r1, 0x2E]
	mov r3, r10
	strh r3, [r1, 0x30]
	ldrb r1, [r5, 0x4]
	ldrb r2, [r5, 0x5]
	adds r0, r6, 0
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r8
	strh r4, [r1, 0x2E]
	movs r0, 0x2
	strh r0, [r1, 0x30]
	ldr r1, =gUnknown_030011F8
	movs r0, 0xFF
	strh r0, [r1]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_256color_bg_bg0

	thumb_func_start sub_81341E0
sub_81341E0: @ 81341E0
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81341E0

	thumb_func_start sub_81341FC
sub_81341FC: @ 81341FC
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrb r0, [r4, 0x8]
	bl sub_81344C8
	movs r2, 0xAA
	lsls r2, 2
	movs r0, 0
	movs r1, 0
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r2, =gUnknown_085E8C53
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =sub_813425C
	str r0, [r4]
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81341FC

	thumb_func_start sub_813425C
sub_813425C: @ 813425C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r6, r0, r2
	ldrh r7, [r6, 0x8]
	ldrb r4, [r6, 0x8]
	ldr r1, =gMain
	ldrh r3, [r1, 0x2E]
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _081342F8
	bl sub_8134604
	ldr r0, =gUnknown_085B1F40
	ldr r1, =gUnknown_085B1DEC
	lsls r2, r4, 1
	adds r3, r2, r1
	ldrb r5, [r3]
	adds r1, 0x1
	adds r2, r1
	ldrb r4, [r2]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0xC]
	ldrh r0, [r6, 0x8]
	bl sub_8133EDC
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8134690
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r2, r4, 0
	adds r2, 0x10
	adds r2, r1, r2
	ldr r3, =gUnknown_085B1ED0
	str r3, [r2]
	adds r4, 0x1C
	adds r1, r4
	ldr r2, =sub_8134774
	str r2, [r1]
	strh r0, [r6, 0xA]
	ldr r0, =sub_8134340
	str r0, [r6]
	b _08134334
	.pool
_081342F8:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _08134314
	cmp r4, 0
	beq _08134314
	subs r0, r7, 0x1
	strh r0, [r6, 0x8]
	ldr r0, =sub_8134640
	str r0, [r6]
	b _08134334
	.pool
_08134314:
	ldrh r1, [r1, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08134334
	cmp r4, 0x1
	bhi _08134334
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	ldr r1, =sub_8134640
	str r1, [r0]
_08134334:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813425C

	thumb_func_start sub_8134340
sub_8134340: @ 8134340
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gSprites
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r2
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _0813437E
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x78
	bne _0813437E
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x40
	bne _0813437E
	ldr r0, =sub_8134390
	str r0, [r2]
_0813437E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134340

	thumb_func_start sub_8134390
sub_8134390: @ 8134390
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrh r0, [r4, 0x8]
	bl sub_8133EDC
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl cry_related
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gUnknown_085E8C90
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
	ldr r0, =gUnknown_085B1DDC
	movs r1, 0xAA
	lsls r1, 2
	movs r2, 0xD
	movs r3, 0
	bl CreateYesNoMenu
	ldr r0, =sub_8134400
	str r0, [r4]
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134390

	thumb_func_start sub_8134400
sub_8134400: @ 8134400
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _08134426
	cmp r1, 0
	bgt _08134420
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08134450
	b _0813449A
_08134420:
	cmp r1, 0x1
	beq _08134450
	b _0813449A
_08134426:
	ldr r2, =gUnknown_020375F0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	strh r0, [r2]
	bl dp13_810BB8C
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	bl SetMainCallback2
	b _0813449A
	.pool
_08134450:
	movs r0, 0x5
	bl audio_play
	ldr r0, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r0
	ldrb r4, [r5, 0xA]
	ldr r6, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl sub_818D820
	ldrb r0, [r5, 0xC]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r4, r6
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	ldr r0, =sub_81344AC
	str r0, [r5]
_0813449A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134400

	thumb_func_start sub_81344AC
sub_81344AC: @ 81344AC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_81341FC
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81344AC

	thumb_func_start sub_81344C8
sub_81344C8: @ 81344C8
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x34
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl sub_8133EDC
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	add r1, sp, 0xC
	bl sub_81DB468
	movs r0, 0xB
	adds r1, r4, 0
	muls r1, r0
	mov r9, r1
	ldr r0, =gSpeciesNames
	add r9, r0
	ldr r0, =gUnknown_085B1DE4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x2C]
	str r1, [sp, 0x30]
	ldr r3, =gUnknown_085B1DF2
	lsls r5, 1
	adds r2, r5, r3
	mov r10, r2
	ldrb r0, [r2]
	lsls r0, 8
	ldr r1, =0xffff00ff
	ldr r2, [sp, 0x2C]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x2C]
	adds r3, 0x1
	adds r5, r3
	ldrb r1, [r5]
	lsls r1, 16
	ldr r0, =0xff00ffff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x2C]
	add r0, sp, 0x2C
	bl AddWindow
	ldr r4, =gUnknown_030011F8
	strh r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x7
	add r1, sp, 0xC
	movs r2, 0x68
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	ldrb r0, [r4]
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_085B1E0C
	mov r8, r1
	str r1, [sp]
	movs r6, 0
	str r6, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r1, 0x7
	movs r3, 0x1
	bl box_print
	movs r0, 0x1
	mov r1, r9
	movs r2, 0x68
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	ldrb r0, [r4]
	lsls r2, 24
	lsrs r2, 24
	mov r1, r8
	str r1, [sp]
	str r6, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	ldrb r0, [r4]
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	mov r2, r10
	ldrb r1, [r2]
	lsls r0, r1, 27
	movs r2, 0xFC
	lsls r2, 24
	adds r0, r2
	adds r1, 0xD
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 24
	ldrb r4, [r5]
	lsls r5, r4, 27
	lsrs r5, 24
	adds r4, 0x4
	lsls r4, 27
	lsrs r4, 24
	lsrs r1, 8
	orrs r1, r0
	lsrs r1, 16
	movs r0, 0x40
	bl SetGpuReg
	lsls r5, 8
	orrs r5, r4
	movs r0, 0x44
	adds r1, r5, 0
	bl SetGpuReg
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81344C8

	thumb_func_start sub_8134604
sub_8134604: @ 8134604
	push {r4,lr}
	ldr r4, =gUnknown_030011F8
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strh r0, [r4]
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134604

	thumb_func_start sub_8134640
sub_8134640: @ 8134640
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8134604
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8134668
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134640

	thumb_func_start sub_8134668
sub_8134668: @ 8134668
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	ldrb r0, [r4, 0x8]
	bl sub_81344C8
	ldr r0, =sub_813425C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8134668

	thumb_func_start sub_8134690
sub_8134690: @ 8134690
	push {lr}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	str r1, [sp]
	str r2, [sp, 0x4]
	movs r1, 0xE
	str r1, [sp, 0x8]
	ldr r1, =0x0000ffff
	str r1, [sp, 0xC]
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_818D3E4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	strb r1, [r2, 0x5]
	add sp, 0x10
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8134690

	thumb_func_start sub_81346DC
sub_81346DC: @ 81346DC
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_085B1E28
	ldr r3, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r3
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r4, 0x20]
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r3
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	lsls r0, 1
	adds r2, 0x1
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r4, 0x22]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x8
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x4
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81346DC

	thumb_func_start sub_813473C
sub_813473C: @ 813473C
	push {lr}
	adds r3, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bne _08134768
	adds r0, r3, 0
	movs r1, 0x1
	bl StartSpriteAnimIfDifferent
	b _08134770
	.pool
_08134768:
	adds r0, r3, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
_08134770:
	pop {r0}
	bx r0
	thumb_func_end sub_813473C

	thumb_func_start sub_8134774
sub_8134774: @ 8134774
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x78
	ble _08134786
	subs r0, r2, 0x4
	strh r0, [r1, 0x20]
_08134786:
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0x77
	bgt _08134794
	adds r0, r2, 0x4
	strh r0, [r1, 0x20]
_08134794:
	ldrh r2, [r1, 0x22]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x40
	ble _081347A2
	subs r0, r2, 0x2
	strh r0, [r1, 0x22]
_081347A2:
	ldrh r2, [r1, 0x22]
	movs r3, 0x22
	ldrsh r0, [r1, r3]
	cmp r0, 0x3F
	bgt _081347B0
	adds r0, r2, 0x2
	strh r0, [r1, 0x22]
_081347B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8134774

	.align 2, 0 @ Don't pad with nop.
