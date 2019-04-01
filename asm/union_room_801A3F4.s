	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_801A3F4
sub_801A3F4: @ 801A3F4
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0801A414
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801A414:
	pop {r0}
	bx r0
	thumb_func_end sub_801A3F4

	thumb_func_start sub_801A418
sub_801A418: @ 801A418
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_801A418

	thumb_func_start sub_801A42C
sub_801A42C: @ 801A42C
	push {lr}
	ldr r0, =sub_801A43C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A42C

	thumb_func_start sub_801A43C
sub_801A43C: @ 801A43C
	push {r4,r5,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r5, =gUnknown_03000DAC
	movs r0, 0x6C
	bl AllocZeroed
	str r0, [r5]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0D34
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	adds r0, r4, 0
	bl Alloc
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r1, =gWirelessInfoScreenGfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r1, =gWirelessInfoScreenTilemap
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_082F0D3C
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	bl ScanlineEffect_Stop
	bl m4aSoundVSyncOn
	ldr r0, =sub_801A418
	bl SetVBlankCallback
	ldr r0, =sub_801A6C0
	movs r1, 0
	bl CreateTask
	ldr r1, [r5]
	adds r1, 0x60
	strb r0, [r1]
	bl sub_8013C40
	ldr r1, [r5]
	adds r1, 0x61
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x1C]
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
	ldr r0, =gWirelessInfoScreenPal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0xF0
	bl Menu_LoadStdPalAt
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	ldr r0, =sub_801A3F4
	bl SetMainCallback2
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A43C

	thumb_func_start sub_801A584
sub_801A584: @ 801A584
	push {r4,lr}
	bl FreeAllWindowBuffers
	movs r4, 0
_0801A58C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBgTilemapBuffer
	bl Free
	adds r4, 0x1
	cmp r4, 0x1
	ble _0801A58C
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	bl Free
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A584

	thumb_func_start sub_801A5BC
sub_801A5BC: @ 801A5BC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5
	ble _0801A5E4
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bne _0801A5E0
	movs r0, 0
	strh r0, [r1]
_0801A5E0:
	movs r0, 0
	strh r0, [r2]
_0801A5E4:
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x2
	lsls r0, 5
	ldr r1, =gWirelessInfoScreenPal
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A5BC

	thumb_func_start sub_801A600
sub_801A600: @ 801A600
	push {r4,r5,lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r5, =gUnknown_082F0D5C
	ldr r4, [r5]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xC0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_801A8B0
	movs r1, 0
_0801A644:
	adds r4, r1, 0x1
	lsls r0, r4, 2
	adds r0, r5
	ldr r2, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 25
	movs r1, 0x80
	lsls r1, 20
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r1, 0x1
	movs r3, 0
	bl sub_801A8B0
	adds r1, r4, 0
	cmp r4, 0x2
	ble _0801A644
	ldr r1, =gUnknown_082F0D5C
	adds r0, r4, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 25
	movs r1, 0x80
	lsls r1, 20
	adds r0, r1
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl sub_801A8B0
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A600

	thumb_func_start sub_801A6C0
sub_801A6C0: @ 801A6C0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x5
	bls _0801A6E2
	b _0801A89C
_0801A6E2:
	lsls r0, 2
	ldr r1, =_0801A6F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A6F4:
	.4byte _0801A70C
	.4byte _0801A728
	.4byte _0801A74C
	.4byte _0801A768
	.4byte _0801A85C
	.4byte _0801A884
_0801A70C:
	bl sub_801A600
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0801A89C
	.pool
_0801A728:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl ShowBg
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl ShowBg
	b _0801A86C
_0801A74C:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0801A75A
	b _0801A89C
_0801A75A:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r2
	b _0801A876
	.pool
_0801A768:
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x10
	adds r2, r0, 0
	adds r2, 0x20
	adds r3, r0, 0
	adds r3, 0x61
	ldrb r3, [r3]
	bl sub_801AA30
	lsls r1, r5, 2
	mov r8, r1
	cmp r0, 0
	beq _0801A7F8
	movs r0, 0x2
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r4, 0
	ldr r6, =gStringVar4
	movs r7, 0x80
	lsls r7, 20
_0801A796:
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	cmp r4, 0x3
	beq _0801A7CC
	lsrs r0, r7, 24
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_801A8B0
	b _0801A7DE
	.pool
_0801A7CC:
	movs r0, 0x62
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r1, 0x1
	adds r2, r6, 0
	movs r3, 0xC
	bl sub_801A8B0
_0801A7DE:
	movs r2, 0xF0
	lsls r2, 21
	adds r7, r2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801A796
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0x3
	bl CopyWindowToVram
_0801A7F8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801A80C
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801A836
_0801A80C:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gTasks
	ldr r0, =gUnknown_03000DAC
	ldr r0, [r0]
	adds r0, 0x61
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0xFF
	strh r1, [r0, 0x26]
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 3
	adds r1, r2
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0801A836:
	mov r2, r8
	adds r1, r2, r5
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	adds r0, r1, 0
	adds r0, 0xE
	adds r1, 0x10
	bl sub_801A5BC
	b _0801A89C
	.pool
_0801A85C:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0801A86C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
_0801A876:
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0801A89C
	.pool
_0801A884:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0801A89C
	ldr r0, =sub_801A584
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_0801A89C:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801A6C0

	thumb_func_start sub_801A8B0
sub_801A8B0: @ 801A8B0
	push {r4-r7,lr}
	sub sp, 0x18
	mov r12, r2
	ldr r2, [sp, 0x2C]
	ldr r4, [sp, 0x30]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r2, 24
	lsrs r3, r2, 24
	lsls r4, 24
	lsrs r0, r4, 24
	cmp r0, 0x4
	bhi _0801A93A
	lsls r0, 2
	ldr r1, =_0801A8E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801A8E0:
	.4byte _0801A8F4
	.4byte _0801A902
	.4byte _0801A910
	.4byte _0801A91E
	.4byte _0801A92C
_0801A8F4:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	movs r0, 0x3
	b _0801A938
_0801A902:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x3
	b _0801A938
_0801A910:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x5
	b _0801A938
_0801A91E:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	movs r0, 0x6
	b _0801A938
_0801A92C:
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
_0801A938:
	strb r0, [r1, 0x2]
_0801A93A:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	mov r0, r12
	str r0, [sp, 0x10]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl AddTextPrinterParameterized4
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801A8B0

	thumb_func_start sub_801A960
sub_801A960: @ 801A960
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r12, r0
	adds r7, r1, 0
	ldrb r0, [r0, 0xA]
	lsls r0, 25
	lsrs r0, 25
	mov r8, r0
	movs r4, 0
	ldr r0, =gUnknown_082F0D70
	mov r9, r0
	movs r1, 0x1
	add r1, r9
	mov r10, r1
	mov r3, r12
	adds r3, 0x4
	str r3, [sp]
_0801A98A:
	lsls r0, r4, 1
	adds r2, r0, r4
	mov r3, r9
	adds r1, r2, r3
	adds r5, r0, 0
	adds r6, r4, 0x1
	ldrb r1, [r1]
	cmp r8, r1
	bne _0801A9EE
	mov r0, r12
	ldrb r1, [r0, 0x1A]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801A9EE
	mov r0, r9
	adds r0, 0x2
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, 0
	bne _0801A9DC
	movs r2, 0
	movs r1, 0
	ldr r3, [sp]
_0801A9BA:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801A9C4
	adds r2, 0x1
_0801A9C4:
	adds r1, 0x1
	cmp r1, 0x3
	ble _0801A9BA
	adds r2, 0x1
	adds r0, r5, r4
	add r0, r10
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r7
	b _0801A9E8
	.pool
_0801A9DC:
	mov r1, r10
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r3]
_0801A9E8:
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
_0801A9EE:
	adds r4, r6, 0
	cmp r4, 0x1E
	bls _0801A98A
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801A960

	thumb_func_start sub_801AA08
sub_801AA08: @ 801AA08
	push {r4,lr}
	movs r4, 0
	adds r3, r1, 0
	adds r2, r0, 0
_0801AA10:
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _0801AA1C
	movs r0, 0x1
	b _0801AA28
_0801AA1C:
	adds r3, 0x4
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, 0x3
	ble _0801AA10
	movs r0, 0
_0801AA28:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801AA08

	thumb_func_start sub_801AA30
sub_801AA30: @ 801AA30
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	adds r6, r0, 0
	mov r9, r1
	adds r5, r2, 0
	lsls r4, r3, 24
	lsrs r4, 24
	movs r0, 0
	mov r8, r0
	mov r0, sp
	movs r1, 0
	movs r2, 0x10
	bl memset
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r4, 0
_0801AA5E:
	lsls r1, r4, 5
	ldr r0, [r7]
	adds r0, r1
	mov r1, sp
	bl sub_801A960
	adds r1, r0, 0
	ldr r0, [r5]
	cmp r1, r0
	beq _0801AA78
	str r1, [r5]
	movs r2, 0x1
	mov r8, r2
_0801AA78:
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _0801AA5E
	mov r0, sp
	mov r1, r9
	bl sub_801AA08
	cmp r0, 0
	bne _0801AA9C
	mov r3, r8
	cmp r3, 0x1
	beq _0801AAC4
	movs r0, 0
	b _0801AAC6
	.pool
_0801AA9C:
	adds r1, r6, 0
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r9
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	adds r0, r1
	ldr r1, [r6, 0x8]
	adds r0, r1
	ldr r1, [r6, 0xC]
	adds r0, r1
	str r0, [r6, 0xC]
_0801AAC4:
	movs r0, 0x1
_0801AAC6:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801AA30

	thumb_func_start sub_801AAD4
sub_801AAD4: @ 801AAD4
	push {r4-r7,lr}
	movs r0, 0xA
	bl sub_8014210
	movs r4, 0
	movs r7, 0x64
	ldr r6, =gPlayerParty
	ldr r5, =gEnemyParty
_0801AAE4:
	ldr r0, =gSelectedOrderFromParty
	adds r0, r4, r0
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r0, 0
	muls r1, r7
	adds r1, r6
	adds r0, r5, 0
	movs r2, 0x64
	bl memcpy
	adds r5, 0x64
	adds r4, 0x1
	cmp r4, 0x1
	ble _0801AAE4
	ldr r4, =gPlayerParty
	movs r0, 0xFA
	lsls r0, 1
	adds r5, r4, r0
_0801AB0A:
	adds r0, r4, 0
	bl ZeroMonData
	adds r4, 0x64
	cmp r4, r5
	ble _0801AB0A
	ldr r4, =gPlayerParty
	movs r5, 0
	adds r6, r4, 0
	adds r6, 0x64
_0801AB1E:
	ldr r1, =gEnemyParty
	adds r1, r5, r1
	adds r0, r4, 0
	movs r2, 0x64
	bl memcpy
	adds r4, 0x64
	adds r5, 0x64
	cmp r4, r6
	ble _0801AB1E
	movs r0, 0x32
	bl IncrementGameStat
	bl CalculatePlayerPartyCount
	ldr r0, =gTrainerBattleOpponent_A
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =CB2_InitBattle
	bl SetMainCallback2
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AAD4

	thumb_func_start sub_801AB68
sub_801AB68: @ 801AB68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r7, r1, 0
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
	mov r10, r1
	ldr r0, =gUnknown_082F0DE4
	mov r8, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	str r3, [sp, 0x14]
	bl FillWindowPixelBuffer
	mov r1, r9
	str r1, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r7, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r6, 0
	ldr r3, [sp, 0x14]
	bl AddTextPrinterParameterized4
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AB68

	thumb_func_start sub_801ABDC
sub_801ABDC: @ 801ABDC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0801ABF4
	cmp r0, 0x1
	beq _0801AC22
	b _0801AC36
_0801ABF4:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD
	bl DrawTextBorderOuter
	str r5, [sp]
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_801AB68
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0801AC36
_0801AC22:
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _0801AC36
	strh r0, [r4]
	movs r0, 0x1
	b _0801AC38
_0801AC36:
	movs r0, 0
_0801AC38:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801ABDC

	thumb_func_start sub_801AC40
sub_801AC40: @ 801AC40
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_801AC40

	thumb_func_start sub_801AC54
sub_801AC54: @ 801AC54
	push {r4,lr}
	sub sp, 0xC
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x33
	bls _0801AC6A
	b _0801AFAE
_0801AC6A:
	lsls r0, 2
	ldr r1, =_0801AC7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801AC7C:
	.4byte _0801AD4C
	.4byte _0801ADFC
	.4byte _0801AE24
	.4byte _0801AE48
	.4byte _0801AE98
	.4byte _0801AFAE
	.4byte _0801AF7C
	.4byte _0801AF58
	.4byte _0801AF7C
	.4byte _0801AF98
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AFAE
	.4byte _0801AF24
	.4byte _0801AF40
_0801AD4C:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	ldr r4, =gUnknown_02022C6C
	movs r0, 0x4
	bl AllocZeroed
	str r0, [r4]
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F0DD0
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	bl reset_temp_tile_data_buffers
	ldr r0, =gUnknown_082F0DD4
	bl InitWindows
	lsls r0, 16
	cmp r0, 0
	bne _0801AD8C
	b _0801AFC2
_0801AD8C:
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl ClearWindowTilemap
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	bl sub_819789C
	ldr r0, =sub_801AC40
	bl SetVBlankCallback
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0801AF8A
	.pool
_0801ADFC:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_CommStandbyAwaitingOtherPlayer
	movs r2, 0
	bl sub_801ABDC
	cmp r0, 0
	bne _0801AE0E
	b _0801AFAE
_0801AE0E:
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AE24:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	b _0801AF8A
	.pool
_0801AE48:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	beq _0801AE54
	b _0801AFAE
_0801AE54:
	ldr r4, =gBlockSendBuffer
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x20
	bl memset
	ldr r0, =gSelectedOrderFromParty
	ldrb r1, [r0]
	ldrb r0, [r0, 0x1]
	cmn r1, r0
	bne _0801AE78
	movs r0, 0x52
	b _0801AE7A
	.pool
_0801AE78:
	movs r0, 0x51
_0801AE7A:
	strb r0, [r4]
	ldr r1, =gBlockSendBuffer
	movs r0, 0
	movs r2, 0x20
	bl SendBlock
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AE98:
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _0801AEA6
	b _0801AFAE
_0801AEA6:
	ldr r1, =gBlockRecvBuffer
	ldrh r0, [r1]
	cmp r0, 0x51
	bne _0801AEE0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x51
	bne _0801AEE0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x32
	b _0801AF16
	.pool
_0801AEE0:
	bl sub_800AC34
	ldr r4, =gBlockRecvBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 16
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x52
	bne _0801AF0C
	ldr r0, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x6
	b _0801AF16
	.pool
_0801AF0C:
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x8
_0801AF16:
	strb r1, [r0]
	bl ResetBlockReceivedFlags
	b _0801AFAE
	.pool
_0801AF24:
	bl UpdatePaletteFade
	lsls r0, 24
	cmp r0, 0
	bne _0801AFAE
	bl sub_800ADF8
	ldr r1, =gMain
	movs r2, 0x87
	lsls r2, 3
	adds r1, r2
	b _0801AF8A
	.pool
_0801AF40:
	bl IsLinkTaskFinished
	lsls r0, 24
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =sub_801AAD4
	bl SetMainCallback2
	b _0801AFAE
	.pool
_0801AF58:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_RefusedBattle
	movs r2, 0x1
	bl sub_801ABDC
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	b _0801AFAE
	.pool
_0801AF7C:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0801AFAE
	movs r0, 0x87
	lsls r0, 3
	adds r1, r2, r0
_0801AF8A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0801AFAE
	.pool
_0801AF98:
	ldr r0, =gUnknown_02022C6C
	ldr r0, [r0]
	ldr r1, =gText_BattleWasRefused
	movs r2, 0x1
	bl sub_801ABDC
	cmp r0, 0
	beq _0801AFAE
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
_0801AFAE:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801AFC2:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AC54
