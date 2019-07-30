	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(2)

	thumb_func_start sub_81CA3B4
sub_81CA3B4: @ 81CA3B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	movs r0, 0x2
	bl GetSubstructPtr
	adds r7, r0, 0
	movs r5, 0
	mov r8, r5
_081CA3C8:
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r1, r0
	movs r0, 0x4
	orrs r1, r0
	strb r1, [r2, 0x1]
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r1, [r4]
	ldr r0, =sub_81CA4AC
	str r0, [r1, 0x1C]
	movs r6, 0x8
	strh r6, [r1, 0x2E]
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, 0x30]
	ldr r0, [r4]
	strh r5, [r0, 0x3C]
	ldr r0, [r4]
	bl InitSpriteAffineAnim
	ldm r4!, {r0}
	movs r1, 0
	bl StartSpriteAffineAnim
	adds r5, 0x1
	cmp r5, 0x3
	ble _081CA3C8
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =sub_81CA580
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0x8]
	ldrb r0, [r7, 0xC]
	adds r0, 0x1
	strb r0, [r7, 0xC]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA3B4

	thumb_func_start sub_81CA448
sub_81CA448: @ 81CA448
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r0, 0x1
	ands r1, r0
	lsls r4, r1, 2
	movs r6, 0x5
	negs r6, r6
	movs r3, 0x3
_081CA458:
	ldm r5!, {r0}
	adds r0, 0x3E
	ldrb r2, [r0]
	adds r1, r6, 0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	subs r3, 0x1
	cmp r3, 0
	bge _081CA458
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA448

	thumb_func_start sub_81CA474
sub_81CA474: @ 81CA474
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	subs r0, 0x1
	strh r0, [r2, 0x2E]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081CA49A
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x32]
	adds r0, r1
	strh r0, [r2, 0x32]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r2, 0x20]
	b _081CA4A2
_081CA49A:
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x20]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
_081CA4A2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA474

	thumb_func_start sub_81CA4AC
sub_81CA4AC: @ 81CA4AC
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081CA574
	movs r0, 0x30
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _081CA4E2
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	strh r5, [r4, 0x24]
	b _081CA578
_081CA4E2:
	ldrh r0, [r4, 0x32]
	adds r0, 0x10
	strh r0, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	asrs r1, r0, 3
	adds r0, r1, 0
	subs r0, 0x20
	lsrs r1, r0, 31
	adds r0, r1
	asrs r1, r0, 1
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _081CA518
	cmp r0, 0x1
	bgt _081CA50A
	cmp r0, 0
	beq _081CA514
	b _081CA526
_081CA50A:
	cmp r0, 0x2
	beq _081CA51C
	cmp r0, 0x3
	beq _081CA520
	b _081CA526
_081CA514:
	negs r1, r1
	b _081CA520
_081CA518:
	negs r0, r1
	b _081CA524
_081CA51C:
	strh r1, [r4, 0x24]
	b _081CA526
_081CA520:
	lsls r0, r1, 1
	adds r0, r1
_081CA524:
	strh r0, [r4, 0x24]
_081CA526:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081CA578
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	lsrs r1, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	adds r0, r4, 0
	movs r3, 0
	bl CalcCenterToCornerVec
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0xD
	negs r1, r1
	ands r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
	b _081CA578
	.pool
_081CA574:
	subs r0, r1, 0x1
	strh r0, [r4, 0x2E]
_081CA578:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA4AC

	thumb_func_start sub_81CA580
sub_81CA580: @ 81CA580
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	movs r1, 0
	ldrsh r2, [r4, r1]
	cmp r2, 0
	bne _081CA634
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _081CA5AC
	cmp r1, 0x1
	beq _081CA5CC
	b _081CA638
	.pool
_081CA5AC:
	movs r0, 0x10
	strh r0, [r4, 0x4]
	strh r2, [r4, 0x6]
	movs r1, 0xFC
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _081CA638
_081CA5CC:
	ldrh r0, [r4, 0x8]
	ands r1, r0
	cmp r1, 0
	beq _081CA5E4
	ldrh r0, [r4, 0x4]
	subs r0, 0x3
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	bge _081CA5F6
	strh r2, [r4, 0x4]
	b _081CA5F6
_081CA5E4:
	ldrh r0, [r4, 0x6]
	adds r0, 0x3
	strh r0, [r4, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _081CA5F6
	movs r0, 0x10
	strh r0, [r4, 0x6]
_081CA5F6:
	ldrh r1, [r4, 0x6]
	lsls r1, 8
	ldrh r0, [r4, 0x4]
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bne _081CA638
	movs r0, 0x2
	bl GetSubstructPtr
	ldrb r1, [r0, 0xC]
	subs r1, 0x1
	strb r1, [r0, 0xC]
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	adds r0, r5, 0
	bl DestroyTask
	b _081CA638
_081CA634:
	subs r0, 0x1
	strh r0, [r4]
_081CA638:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA580

	thumb_func_start sub_81CA640
sub_81CA640: @ 81CA640
	push {r4,lr}
	movs r0, 0x2
	bl GetSubstructPtr
	adds r4, r0, 0
	ldr r0, =gUnknown_0862036C
	movs r1, 0x10
	movs r2, 0x60
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r4, 0x28]
	bl sub_81C98D4
	cmp r0, 0
	beq _081CA684
	ldr r1, [r4, 0x28]
	ldr r0, =sub_81CA6AC
	str r0, [r1, 0x1C]
	b _081CA690
	.pool
_081CA684:
	ldr r0, [r4, 0x28]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_081CA690:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81CA640

	thumb_func_start sub_81CA698
sub_81CA698: @ 81CA698
	push {lr}
	movs r0, 0x2
	bl GetSubstructPtr
	ldr r0, [r0, 0x28]
	bl DestroySprite
	pop {r0}
	bx r0
	thumb_func_end sub_81CA698

	thumb_func_start sub_81CA6AC
sub_81CA6AC: @ 81CA6AC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _081CA6DA
	movs r0, 0
	strh r0, [r3, 0x2E]
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
_081CA6DA:
	pop {r0}
	bx r0
	thumb_func_end sub_81CA6AC

	thumb_func_start sub_81CA6E0
sub_81CA6E0: @ 81CA6E0
	push {r4,lr}
	movs r0, 0x2
	bl GetSubstructPtr
	adds r4, r0, 0
	ldr r0, =gUnknown_086202CC
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	ldrb r0, [r4, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r4, 0x8]
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA6E0

	thumb_func_start sub_81CA714
sub_81CA714: @ 81CA714
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x2
	bl GetSubstructPtr
	adds r5, r0, 0
	bl sub_81C98B4
	ldr r1, =gUnknown_086202D4
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	movs r2, 0xC0
	subs r2, r4
	lsrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0862030C
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA714

	thumb_func_start sub_81CA770
sub_81CA770: @ 81CA770
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x2
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r6, =gText_NoRibbonWinners
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r4, r0, 0
	ldrb r0, [r5, 0x8]
	movs r1, 0x66
	bl FillWindowPixelBuffer
	ldrb r0, [r5, 0x8]
	movs r2, 0xC0
	subs r2, r4
	lsrs r2, 1
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_0862030F
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA770

	thumb_func_start sub_81CA7C4
sub_81CA7C4: @ 81CA7C4
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81CA7C4

	thumb_func_start sub_81CA7D4
sub_81CA7D4: @ 81CA7D4
	push {r4,lr}
	movs r0, 0x2
	bl GetSubstructPtr
	adds r4, r0, 0
	ldr r0, =sub_81CA808
	movs r1, 0x2
	bl CreateTask
	strb r0, [r4, 0xA]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA7D4

	thumb_func_start sub_81CA7F4
sub_81CA7F4: @ 81CA7F4
	push {lr}
	movs r0, 0x2
	bl GetSubstructPtr
	ldrb r0, [r0, 0xA]
	bl DestroyTask
	pop {r0}
	bx r0
	thumb_func_end sub_81CA7F4

	thumb_func_start sub_81CA808
sub_81CA808: @ 81CA808
	push {lr}
	movs r0, 0x3
	movs r1, 0x80
	movs r2, 0x1
	bl ChangeBgX
	pop {r0}
	bx r0
	thumb_func_end sub_81CA808

	thumb_func_start sub_81CA818
sub_81CA818: @ 81CA818
	push {r4,r5,lr}
	ldr r0, =sub_81CA8B0
	movs r1, 0x3
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0861FC78 + 2
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	adds r5, 0xC
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetWordTaskArg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA818

	thumb_func_start sub_81CA850
sub_81CA850: @ 81CA850
	push {lr}
	ldr r0, =gUnknown_0861FC78 + 0xE
	movs r1, 0x31
	movs r2, 0x4
	bl CopyPaletteIntoBufferUnfaded
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA850

	thumb_func_start sub_81CA864
sub_81CA864: @ 81CA864
	push {r4,r5,lr}
	ldr r0, =sub_81CA8B0
	movs r1, 0x3
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0861FC78 + 0xE
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	subs r5, 0xC
	adds r0, r4, 0
	movs r1, 0x3
	adds r2, r5, 0
	bl SetWordTaskArg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA864

	thumb_func_start sub_81CA89C
sub_81CA89C: @ 81CA89C
	push {lr}
	ldr r0, =sub_81CA8B0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CA89C

	thumb_func_start sub_81CA8B0
sub_81CA8B0: @ 81CA8B0
	push {r4-r6,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	adds r0, r6, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r5, r0, 0
	adds r0, r6, 0
	movs r1, 0x3
	bl GetWordTaskArg
	adds r1, r0, 0
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x2
	movs r3, 0xC
	bl sub_81C79BC
	add r0, sp, 0x8
	movs r1, 0x31
	movs r2, 0x4
	bl LoadPalette
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xC
	bne _081CA908
	adds r0, r6, 0
	bl DestroyTask
_081CA908:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA8B0

	thumb_func_start sub_81CA914
sub_81CA914: @ 81CA914
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r0}
	bx r0
	thumb_func_end sub_81CA914

	thumb_func_start titlescreen_0
titlescreen_0: @ 81CA92C
	push {lr}
	movs r0, 0x50
	movs r1, 0x90
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuRegBits
	movs r0, 0x4A
	movs r1, 0x1F
	bl SetGpuRegBits
	movs r0, 0x44
	movs r1, 0xA0
	bl SetGpuRegBits
	bl ScanlineEffect_Stop
	bl sub_81CAA3C
	ldr r2, =gUnknown_08620384
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl ScanlineEffect_SetParams
	ldr r0, =sub_81CA914
	bl SetVBlankCallback_
	ldr r0, =sub_81CA9EC
	movs r1, 0x3
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end titlescreen_0

	thumb_func_start sub_81CA994
sub_81CA994: @ 81CA994
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	bl ClearGpuRegBits
	bl ScanlineEffect_Stop
	ldr r0, =sub_81CA9EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	bl SetPokenavVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA994

	thumb_func_start sub_81CA9C8
sub_81CA9C8: @ 81CA9C8
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81CA9C8

	thumb_func_start sub_81CA9D8
sub_81CA9D8: @ 81CA9D8
	push {lr}
	bl sub_81CAA3C
	movs r0, 0x50
	movs r1, 0x90
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_81CA9D8

	thumb_func_start sub_81CA9EC
sub_81CA9EC: @ 81CA9EC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	ble _081CAA30
	movs r0, 0
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	adds r0, 0x3
	movs r1, 0x7F
	ands r0, r1
	strh r0, [r2, 0x2]
	ldr r1, =gSineTable
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r1, 16
	asrs r1, 21
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x54
	bl SetGpuReg
_081CAA30:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CA9EC

	thumb_func_start sub_81CAA3C
sub_81CAA3C: @ 81CAA3C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	bl sub_81C9894
	adds r4, r0, 0
	bl sub_81C98A4
	ldr r2, =gUnknown_08620240
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x2]
	adds r4, r2, 0
	muls r4, r0
	ldrh r1, [r1]
	adds r4, r1
	subs r4, 0x8
	mov r0, sp
	movs r6, 0
	strh r6, [r0]
	ldr r5, =gScanlineEffectRegBuffers
	ldr r0, =0x010000a0
	mov r8, r0
	mov r0, sp
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	strh r6, [r0]
	movs r1, 0xF0
	lsls r1, 3
	adds r1, r5
	mov r9, r1
	mov r2, r8
	bl CpuSet
	add r0, sp, 0x4
	ldr r1, =0x000072f0
	adds r6, r1, 0
	strh r6, [r0]
	lsls r4, 1
	adds r5, r4, r5
	ldr r1, =0x01000010
	mov r8, r1
	adds r1, r5, 0
	mov r2, r8
	bl CpuSet
	mov r0, sp
	adds r0, 0x6
	strh r6, [r0]
	add r4, r9
	adds r1, r4, 0
	mov r2, r8
	bl CpuSet
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CAA3C

	thumb_func_start sub_81CAADC
sub_81CAADC: @ 81CAADC
	push {lr}
	bl sub_81CA9C8
	pop {r0}
	bx r0
	thumb_func_end sub_81CAADC

	.align 2, 0 @ Don't pad with nop.
