	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8178944
sub_8178944: @ 8178944
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8178944

	thumb_func_start sub_8178958
sub_8178958: @ 8178958
	push {lr}
	movs r2, 0
	ldr r1, =gUnknown_020229E8
	ldrh r0, [r1, 0x1A]
	ldrh r1, [r1, 0x36]
	cmp r0, r1
	bne _08178968
	movs r2, 0x1
_08178968:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8178958

	thumb_func_start sub_8178974
sub_8178974: @ 8178974
	push {r4,lr}
	sub sp, 0x8
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	ldr r0, =sub_8178944
	bl SetVBlankCallback
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085EFD64
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085EFD68
	bl InitWindows
	lsls r0, 16
	cmp r0, 0
	beq _08178A22
	bl DeactivateAllTextPrinters
	movs r4, 0
_081789AC:
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r4, 0x1
	cmp r4, 0x1
	ble _081789AC
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl sub_809882C
	movs r0, 0xE0
	bl sub_81978B0
	movs r1, 0xA0
	lsls r1, 1
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	ldr r0, =sub_8009404
	movs r1, 0
	bl CreateTask
	bl StopMapMusic
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	bl FillPalette
	ldr r0, =sub_8178A78
	bl SetMainCallback2
_08178A22:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178974

	thumb_func_start sub_8178A40
sub_8178A40: @ 8178A40
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r5, 0x1
	cmp r4, 0
	bne _08178A54
	ldr r1, =gUnknown_085EE80A
	bl StringCopy
	movs r5, 0
_08178A54:
	cmp r4, 0x2
	bne _08178A5A
	movs r5, 0
_08178A5A:
	cmp r4, 0x1
	bne _08178A66
	ldr r1, =gUnknown_085EE827
	adds r0, r6, 0
	bl StringCopy
_08178A66:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8178A40

	thumb_func_start sub_8178A78
sub_8178A78: @ 8178A78
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _08178A8E
	b _08178E58
_08178A8E:
	lsls r0, 2
	ldr r1, =_08178AA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08178AA0:
	.4byte _08178AE4
	.4byte _08178B12
	.4byte _08178B48
	.4byte _08178B80
	.4byte _08178BCC
	.4byte _08178BDC
	.4byte _08178C54
	.4byte _08178D28
	.4byte _08178D38
	.4byte _08178D58
	.4byte _08178D60
	.4byte _08178D74
	.4byte _08178DBC
	.4byte _08178DE0
	.4byte _08178E0C
	.4byte _08178E24
	.4byte _08178E48
_08178AE4:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0xD
	bl SetWindowBorderStyle
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	b _08178E30
_08178B12:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08178B20
	b _08178E58
_08178B20:
	ldr r1, =gUnknown_085EE765
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08178E3C
	.pool
_08178B48:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _08178B56
	b _08178E58
_08178B56:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gUnknown_020229C6
	ldr r2, =0x00005501
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_8009734
	b _08178E58
	.pool
_08178B80:
	ldr r0, =gUnknown_030030E0
	ldr r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08178B8E
	b _08178D00
_08178B8E:
	movs r0, 0x1C
	ands r1, r0
	cmp r1, 0x4
	bhi _08178B98
	b _08178D00
_08178B98:
	movs r0, 0x15
	bl PlaySE
	ldr r1, =gUnknown_085EE788
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08178D00
	.pool
_08178BCC:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _08178BDA
	b _08178E58
_08178BDA:
	b _08178E34
_08178BDC:
	bl sub_800ABAC
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bne _08178CD0
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08178C38
	movs r0, 0x5
	bl PlaySE
	bl sub_800A620
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r1, =gUnknown_085EE7BF
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	movs r2, 0x87
	lsls r2, 3
	adds r1, r4, r2
	b _08178E3C
	.pool
_08178C38:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08178C42
	b _08178E58
_08178C42:
	movs r0, 0x5
	bl PlaySE
	bl sub_80097E8
	movs r0, 0x87
	lsls r0, 3
	adds r1, r4, r0
	b _08178D1E
_08178C54:
	bl sub_800B320
	lsls r0, 24
	cmp r0, 0
	beq _08178D00
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08178C68
	b _08178E58
_08178C68:
	movs r0, 0x2
	movs r1, 0x2
	bl sub_800A0C8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _08178CAC
	bl sub_800AC34
	ldr r4, =gStringVar4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8178A40
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	b _08178CF2
	.pool
_08178CAC:
	bl sub_8178958
	lsls r0, 24
	cmp r0, 0
	beq _08178CCC
	ldr r1, =gUnknown_085EE7CE
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	b _08178E34
	.pool
_08178CCC:
	bl sub_80097E8
_08178CD0:
	ldr r4, =gStringVar4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8178A40
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
_08178CF2:
	movs r1, 0xD
	strb r1, [r0]
	b _08178E58
	.pool
_08178D00:
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08178D0E
	b _08178E58
_08178D0E:
	movs r0, 0x5
	bl PlaySE
	bl sub_80097E8
	movs r2, 0x87
	lsls r2, 3
	adds r1, r4, r2
_08178D1E:
	movs r0, 0xF
	strb r0, [r1]
	b _08178E58
	.pool
_08178D28:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	beq _08178D36
	b _08178E58
_08178D36:
	b _08178E34
_08178D38:
	bl sub_800A550
	lsls r0, 24
	cmp r0, 0
	bne _08178D44
	b _08178E58
_08178D44:
	bl sub_800A5B4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08178E3C
	.pool
_08178D58:
	movs r0, 0x87
	lsls r0, 3
	adds r1, r4, r0
	b _08178E3C
_08178D60:
	bl sub_800AC34
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08178E3C
	.pool
_08178D74:
	ldr r0, =gUnknown_03003124
	ldrb r6, [r0]
	cmp r6, 0
	bne _08178E58
	ldr r5, =0x0201c000
	adds r0, r5, 0
	bl sub_81538A0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	str r6, [sp, 0x4]
	ldr r2, =0x050001f5
	add r0, sp, 0x4
	adds r1, r5, 0
	bl CpuSet
	ldr r0, =gStringVar4
	adds r1, r4, 0
	bl sub_8178A40
	lsls r0, 24
	cmp r0, 0
	bne _08178E34
	movs r0, 0
	bl save_game_when_memory_present
	b _08178E34
	.pool
_08178DBC:
	ldr r1, =gStringVar4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _08178E3C
	.pool
_08178DE0:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	bne _08178E58
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, =gUnknown_0203BCF8
	strb r2, [r0]
	b _08178E58
	.pool
_08178E0C:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08178E58
	movs r0, 0x5
	bl PlaySE
	movs r2, 0x87
	lsls r2, 3
	adds r1, r4, r2
	b _08178E3C
_08178E24:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
_08178E30:
	bl BeginNormalPaletteFade
_08178E34:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_08178E3C:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08178E58
	.pool
_08178E48:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08178E58
	bl DoSoftReset
_08178E58:
	ldr r0, =gUnknown_030030E0
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08178E98
	bl sub_800ABBC
	lsls r0, 24
	cmp r0, 0
	bne _08178E98
	bl sub_80097E8
	ldr r4, =gStringVar4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8178A40
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8178EC4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0xD
	strb r1, [r0]
_08178E98:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl RunTextPrinters
	bl UpdatePaletteFade
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178A78

	thumb_func_start sub_8178EC4
sub_8178EC4: @ 8178EC4
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x1C
	adds r5, r0, 0
	mov r10, r1
	adds r6, r2, 0
	ldr r4, [sp, 0x38]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0x1
	mov r8, r1
	add r0, sp, 0x14
	mov r1, r8
	strb r1, [r0]
	adds r1, r0, 0
	movs r0, 0x2
	strb r0, [r1, 0x1]
	movs r0, 0x3
	strb r0, [r1, 0x2]
	adds r0, r1, 0
	ldrb r0, [r0]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	str r3, [sp, 0x18]
	bl FillWindowPixelBuffer
	mov r0, r9
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	mov r1, r10
	str r1, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	ldr r3, [sp, 0x18]
	bl AddTextPrinterParametrized2
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8178EC4

	.align 2, 0 @ Don't pad with nop.
