	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_813C5A0
sub_813C5A0: @ 813C5A0
	push {r4,lr}
	ldr r4, =gResultsWindowId
	ldrb r0, [r4]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C5A0

	thumb_func_start sub_813C5BC
sub_813C5BC: @ 813C5BC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0813C5DC
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_813C5EC
	str r0, [r1]
_0813C5DC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C5BC

	thumb_func_start sub_813C5EC
sub_813C5EC: @ 813C5EC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0813C610
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0813C61A
_0813C610:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =sub_813C62C
	str r0, [r4]
_0813C61A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C5EC

	thumb_func_start sub_813C62C
sub_813C62C: @ 813C62C
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
	ldr r1, =sub_813C664
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C62C

	thumb_func_start sub_813C664
sub_813C664: @ 813C664
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0813C694
	ldr r0, =CB2_ReturnToFieldContinueScript
	bl SetMainCallback2
	ldr r0, =gUnknown_0203AB78
	ldr r0, [r0]
	bl Free
	movs r0, 0
	bl sub_813C6A8
	bl FreeAllWindowBuffers
	adds r0, r4, 0
	bl DestroyTask
_0813C694:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C664

	thumb_func_start sub_813C6A8
sub_813C6A8: @ 813C6A8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0
	bl ClearWindowTilemap
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	adds r0, r4, 0
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_813C6A8

	thumb_func_start sub_813C6D4
sub_813C6D4: @ 813C6D4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x4
	mov r8, r0
	mov r2, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_0813C6FA:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _0813C6FA
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x40
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x44
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x48
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C6D4

	thumb_func_start sub_813C80C
sub_813C80C: @ 813C80C
	push {lr}
	bl ScanlineEffect_Stop
	bl ResetTasks
	bl ResetSpriteData
	bl ResetPaletteFade
	bl FreeAllSpritePalettes
	pop {r0}
	bx r0
	thumb_func_end sub_813C80C

	thumb_func_start sub_813C828
sub_813C828: @ 813C828
	push {lr}
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
	pop {r0}
	bx r0
	thumb_func_end sub_813C828

	thumb_func_start sub_813C880
sub_813C880: @ 813C880
	push {lr}
	movs r1, 0x94
	lsls r1, 4
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_813C880

	thumb_func_start sub_813C890
sub_813C890: @ 813C890
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gUnknown_085B3484
	adds r0, r4, 0
	movs r2, 0xC0
	movs r3, 0
	bl LoadBgTiles
	ldr r1, =gUnknown_085B3564
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBufferRect
	ldr r0, =gUnknown_085B3544
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C890

	thumb_func_start sub_813C8D8
sub_813C8D8: @ 813C8D8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_813C8D8

	thumb_func_start sub_813C8EC
sub_813C8EC: @ 813C8EC
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_813C8EC

	thumb_func_start sub_813C904
sub_813C904: @ 813C904
	push {lr}
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_813C91C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C904

	thumb_func_start sub_813C91C
sub_813C91C: @ 813C91C
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _0813C930
	b _0813CA3C
_0813C930:
	lsls r0, 2
	ldr r1, =_0813C944
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0813C944:
	.4byte _0813C964
	.4byte _0813C970
	.4byte _0813C976
	.4byte _0813C9A8
	.4byte _0813C9BE
	.4byte _0813C9DE
	.4byte _0813C9F0
	.4byte _0813CA14
_0813C964:
	movs r0, 0
	bl SetVBlankCallback
	bl sub_813C6D4
	b _0813CA00
_0813C970:
	bl sub_813C80C
	b _0813CA00
_0813C976:
	ldr r4, =gUnknown_0203AB78
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085B3D64
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r1, [r4]
	movs r0, 0x3
	bl SetBgTilemapBuffer
	bl sub_813C828
	b _0813CA00
	.pool
_0813C9A8:
	movs r0, 0x3
	bl sub_813C890
	movs r0, 0
	bl stdpal_get
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	b _0813CA00
_0813C9BE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0813CA3C
	movs r0, 0
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0813CA00
_0813C9DE:
	ldr r0, =gUnknown_085B3D6C
	bl InitWindows
	bl DeactivateAllTextPrinters
	b _0813CA00
	.pool
_0813C9F0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_0813CA00:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0813CA3C
	.pool
_0813CA14:
	bl sub_813C880
	ldr r0, =sub_813C8D8
	bl SetVBlankCallback
	bl sub_81D5C8C
	ldr r0, =sub_813C5BC
	movs r1, 0x8
	bl CreateTask
	ldr r0, =sub_813C8EC
	bl SetMainCallback2
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_0813CA3C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_813C91C

	.align 2, 0 @ Don't pad with nop.
