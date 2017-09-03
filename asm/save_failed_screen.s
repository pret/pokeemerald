	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8178F44
sub_8178F44: @ 8178F44
	push {r4,r5,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r2, 0
	lsls r3, 24
	add r0, sp, 0x14
	movs r2, 0
	strb r2, [r0]
	adds r1, r0, 0
	movs r0, 0xF
	strb r0, [r1, 0x1]
	movs r0, 0x3
	strb r0, [r1, 0x2]
	ldr r0, =gUnknown_0203BD0E
	ldrb r0, [r0]
	lsls r4, 27
	lsrs r4, 24
	lsrs r3, 21
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r2, [sp]
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	str r5, [sp, 0x10]
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178F44

	thumb_func_start DoSaveFailedScreen
DoSaveFailedScreen: @ 8178F90
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_8178FDC
	bl SetMainCallback2
	ldr r0, =gUnknown_0203BCFC
	strh r4, [r0]
	ldr r1, =gUnknown_0203BCFE
	movs r2, 0
	movs r0, 0
	strh r0, [r1]
	strh r0, [r1, 0x2]
	ldr r0, =gUnknown_0203BD0E
	strb r2, [r0]
	strb r2, [r0, 0x1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoSaveFailedScreen

	thumb_func_start sub_8178FC8
sub_8178FC8: @ 8178FC8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8178FC8

	thumb_func_start sub_8178FDC
sub_8178FDC: @ 8178FDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r7, r0, r1
	ldrb r0, [r7]
	cmp r0, 0
	beq _08178FF8
	cmp r0, 0x1
	bne _08178FF8
	b _0817925C
_08178FF8:
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
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
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
	movs r3, 0
	mov r8, r3
	str r3, [sp, 0x8]
	add r4, sp, 0x8
	str r4, [r2]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r2, 0x4]
	ldr r0, =0x85000100
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	add r0, sp, 0x4
	mov r3, r8
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
	ldr r1, =0x06007000
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0C0C
	ldr r1, =0x06007800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085EFDE4
	ldr r1, =0x06010020
	bl LZ77UnCompVram
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085EFD88
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r5, =0x0201e000
	movs r0, 0
	adds r1, r5, 0
	bl SetBgTilemapBuffer
	mov r0, r8
	str r0, [sp, 0x8]
	ldr r2, =0x05000200
	adds r0, r4, 0
	adds r1, r5, 0
	bl CpuSet
	ldr r1, =gUnknown_0850E87C
	movs r2, 0x90
	lsls r2, 1
	movs r6, 0x85
	lsls r6, 2
	movs r0, 0
	adds r3, r6, 0
	bl LoadBgTiles
	ldr r0, =gUnknown_085EFD94
	bl InitWindows
	ldr r0, =gUnknown_085EFD9C
	bl AddWindowWithoutTileMap
	ldr r4, =gUnknown_0203BD0E
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0x80
	lsls r1, 4
	adds r2, r5, r1
	movs r1, 0x7
	bl SetWindowAttribute
	ldr r0, =gUnknown_085EFDA4
	bl AddWindowWithoutTileMap
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x1]
	movs r3, 0xE8
	lsls r3, 5
	adds r5, r3
	movs r1, 0x7
	adds r2, r5, 0
	bl SetWindowAttribute
	bl DeactivateAllTextPrinters
	bl ResetSpriteData
	bl ResetTasks
	bl ResetPaletteFade
	ldr r0, =gUnknown_085B0A00
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	ldr r0, =gUnknown_085EFDC4
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0850FEFC
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldrb r0, [r4]
	movs r1, 0
	adds r2, r6, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldrb r0, [r4, 0x1]
	movs r1, 0
	adds r2, r6, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldrb r0, [r4, 0x1]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x1]
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r4]
	movs r1, 0x1
	bl CopyWindowToVram
	ldr r0, =gUnknown_085EC816
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
	movs r0, 0x1
	negs r0, r0
	mov r1, r8
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_8178FC8
	bl SetVBlankCallback
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldrb r0, [r7]
	adds r0, 0x1
	strb r0, [r7]
	b _08179272
	.pool
_0817925C:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _08179272
	ldr r0, =sub_8179288
	bl SetMainCallback2
	ldr r0, =sub_8179454
	bl SetVBlankCallback
_08179272:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178FDC

	thumb_func_start sub_8179288
sub_8179288: @ 8179288
	push {r4-r6,lr}
	movs r5, 0
	ldr r0, =gUnknown_0203BCFE
	movs r1, 0x1
	strh r1, [r0]
	ldr r1, =gDamagedSaveSectors
	ldr r0, [r1]
	cmp r0, 0
	beq _081792EC
	adds r6, r1, 0
_0817929C:
	ldr r0, [r6]
	bl sub_81795AC
	lsls r0, 24
	cmp r0, 0
	bne _08179348
	ldr r4, =gUnknown_0203BD0E
	ldrb r0, [r4]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_085EC917
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
	ldr r0, =gUnknown_0203BCFC
	ldrb r0, [r0]
	bl HandleSavingData
	ldr r0, [r6]
	cmp r0, 0
	beq _081792DC
	ldrb r0, [r4]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_085EC816
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
_081792DC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r6]
	cmp r0, 0
	beq _081792EC
	cmp r5, 0x2
	bls _0817929C
_081792EC:
	cmp r5, 0x3
	bne _0817931C
	ldr r0, =gUnknown_0203BD0E
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_085EC86F
	b _08179330
	.pool
_0817931C:
	ldr r0, =gUnknown_0203BD0E
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gGameContinueCallback
	ldr r0, [r0]
	cmp r0, 0
	bne _08179370
	ldr r0, =gUnknown_085EC94F
_08179330:
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
	b _0817937A
	.pool
_08179348:
	ldr r0, =gUnknown_0203BD0E
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_085EC86F
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
	ldr r0, =sub_8179390
	bl SetMainCallback2
	b _08179380
	.pool
_08179370:
	ldr r0, =gUnknown_085EC9A2
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
_0817937A:
	ldr r0, =sub_81793E0
	bl SetMainCallback2
_08179380:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179288

	thumb_func_start sub_8179390
sub_8179390: @ 8179390
	push {lr}
	ldr r1, =gUnknown_0203BCFE
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081793C4
	ldr r0, =gUnknown_0203BD0E
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_085EC8D4
	movs r1, 0x1
	movs r2, 0
	bl sub_8178F44
	ldr r0, =sub_8178FC8
	bl SetVBlankCallback
	ldr r0, =sub_81793E0
	bl SetMainCallback2
_081793C4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179390

	thumb_func_start sub_81793E0
sub_81793E0: @ 81793E0
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0203BCFE
	movs r2, 0
	strh r2, [r0]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08179410
	movs r0, 0x1
	negs r0, r0
	str r2, [sp]
	movs r1, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8178FC8
	bl SetVBlankCallback
	ldr r0, =sub_8179428
	bl SetMainCallback2
_08179410:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81793E0

	thumb_func_start sub_8179428
sub_8179428: @ 8179428
	push {r4,r5,lr}
	bl UpdatePaletteFade
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0817944E
	ldr r5, =gGameContinueCallback
	ldr r0, [r5]
	cmp r0, 0
	bne _08179448
	bl DoSoftReset
	b _0817944E
	.pool
_08179448:
	bl SetMainCallback2
	str r4, [r5]
_0817944E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8179428

	thumb_func_start sub_8179454
sub_8179454: @ 8179454
	push {r4,r5,lr}
	ldr r5, =gMain
	ldr r0, [r5, 0x24]
	lsrs r4, r0, 3
	movs r0, 0x7
	ands r4, r0
	ldr r0, =gUnknown_085EFD80
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r5, 0x38]
	str r1, [r5, 0x3C]
	ldrh r1, [r5, 0x3A]
	ldr r0, =0xfffffe00
	ands r0, r1
	movs r1, 0x70
	orrs r0, r1
	strh r0, [r5, 0x3A]
	adds r1, r5, 0
	adds r1, 0x38
	movs r0, 0x48
	strb r0, [r1]
	ldr r0, =gUnknown_0203BCFE
	ldrh r0, [r0]
	cmp r0, 0
	beq _081794DC
	ldr r3, =gUnknown_085EFDAC
	lsls r2, r4, 1
	adds r2, r4
	adds r0, r2, r3
	ldrb r4, [r0]
	ldrh r1, [r5, 0x3C]
	ldr r0, =0xfffffc00
	ands r0, r1
	orrs r0, r4
	strh r0, [r5, 0x3C]
	adds r0, r3, 0x2
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r1, 4
	adds r3, 0x1
	adds r2, r3
	ldrb r0, [r2]
	lsls r0, 3
	orrs r1, r0
	adds r3, r5, 0
	adds r3, 0x3B
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _081794E8
	.pool
_081794DC:
	ldrh r0, [r5, 0x3C]
	ldr r1, =0xfffffc00
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r5, 0x3C]
_081794E8:
	ldr r0, =gUnknown_030022F8
	movs r1, 0xE0
	lsls r1, 19
	movs r2, 0x1
	bl CpuFastSet
	ldr r1, =gUnknown_0203BCFE
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _08179500
	subs r0, 0x1
	strh r0, [r1, 0x2]
_08179500:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8179454

	thumb_func_start sub_8179514
sub_8179514: @ 8179514
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gSaveDataBuffer
	movs r3, 0x80
	lsls r3, 5
	movs r1, 0
	adds r2, r4, 0
	bl ReadFlash
	movs r1, 0
	ldr r2, =0x000003ff
_0817952C:
	ldr r0, [r4]
	cmp r0, 0
	beq _08179540
	movs r0, 0x1
	b _0817954E
	.pool
_08179540:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	adds r4, 0x4
	cmp r1, r2
	bls _0817952C
	movs r0, 0
_0817954E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8179514

	thumb_func_start sub_8179554
sub_8179554: @ 8179554
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0
	ldr r1, =0x00000fff
	mov r8, r1
	ldr r7, =ProgramFlashByte
_08179566:
	movs r4, 0
	adds r5, r0, 0x1
_0817956A:
	ldr r3, [r7]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	bl _call_via_r3
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r8
	bls _0817956A
	adds r0, r6, 0
	bl sub_8179514
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r5, 16
	lsrs r0, 16
	cmp r1, 0
	beq _08179596
	cmp r0, 0x81
	bls _08179566
_08179596:
	adds r0, r1, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8179554

	thumb_func_start sub_81795AC
sub_81795AC: @ 81795AC
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
_081795B2:
	movs r4, 0x1
	lsls r4, r6
	adds r0, r5, 0
	ands r0, r4
	cmp r0, 0
	beq _081795CC
	adds r0, r6, 0
	bl sub_8179554
	lsls r0, 24
	cmp r0, 0
	bne _081795CC
	bics r5, r4
_081795CC:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1F
	bls _081795B2
	cmp r5, 0
	beq _081795DE
	movs r0, 0x1
	b _081795E0
_081795DE:
	movs r0, 0
_081795E0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81795AC

	.align 2, 0 @ Don't pad with nop.
