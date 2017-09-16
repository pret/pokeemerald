	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81754C8
sub_81754C8: @ 81754C8
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81754C8

	thumb_func_start sub_81754DC
sub_81754DC: @ 81754DC
	push {lr}
	bl RunTasks
	bl AnimateSprites
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08175522
	ldr r0, =gUnknown_0203BCE4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08175522
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203BCE2
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =sub_8175774
	cmp r1, r0
	bne _08175522
	bl sub_81754C8
	bl RunTasks
	bl AnimateSprites
	ldr r1, =gUnknown_0203BCE5
	movs r0, 0x1
	strb r0, [r1]
_08175522:
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81754DC

	thumb_func_start sub_8175548
sub_8175548: @ 8175548
	push {lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E6F68
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_085E56F0
	movs r1, 0x80
	movs r2, 0x40
	bl LoadPalette
	ldr r0, =gUnknown_085E6F6C
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl ShowBg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175548

	thumb_func_start sub_81755A4
sub_81755A4: @ 81755A4
	push {lr}
	bl FreeAllWindowBuffers
	movs r0, 0
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _081755B8
	bl Free
_081755B8:
	pop {r0}
	bx r0
	thumb_func_end sub_81755A4

	thumb_func_start sub_81755BC
sub_81755BC: @ 81755BC
	push {r4,r5,lr}
	sub sp, 0x18
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	cmp r2, 0x1
	bne _081755DC
	movs r0, 0x3
	strb r0, [r1, 0x1]
	movs r0, 0x4
	b _081755E4
_081755DC:
	add r1, sp, 0x14
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
_081755E4:
	strb r0, [r1, 0x2]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xF0
	movs r3, 0x1
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	adds r3, r5, 0
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81755BC

	thumb_func_start sub_8175620
sub_8175620: @ 8175620
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	bl sub_8175CE4
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
	bl ResetPaletteFade
	bl ResetTasks
	bl sub_8175548
	ldr r0, =sub_8175744
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x16]
	strh r1, [r0, 0x1E]
	movs r1, 0x1
	strh r1, [r0, 0x22]
_0817566A:
	movs r0, 0
	adds r1, r7, 0
	bl sub_8176AB0
	lsls r0, 24
	cmp r0, 0
	beq _0817566A
	ldr r5, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r5
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0
	mov r8, r1
	movs r6, 0
	movs r1, 0x28
	strh r1, [r0, 0x8]
	ldr r1, =0x0000fffc
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =sub_8175DA0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	strh r7, [r1, 0xA]
	strh r0, [r4, 0x26]
	movs r0, 0x1
	negs r0, r0
	str r6, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_81754C8
	bl SetVBlankCallback
	ldr r0, =0x000001c7
	bl m4aSongNumStart
	ldr r0, =sub_81754DC
	bl SetMainCallback2
	ldr r0, =gUnknown_0203BCE5
	mov r1, r8
	strb r1, [r0]
	ldr r4, =gUnknown_0203BCE8
	movs r0, 0xEB
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	bl sub_8177388
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8E
	strh r6, [r0]
	adds r0, 0x2
	strh r6, [r0]
	adds r0, 0x2
	strh r6, [r0]
	ldr r0, =gUnknown_0203BCE2
	strh r7, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175620

	thumb_func_start sub_8175744
sub_8175744: @ 8175744
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175764
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8175774
	str r0, [r1]
_08175764:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175744

	thumb_func_start sub_8175774
sub_8175774: @ 8175774
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _081757B0
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x1E
	strh r1, [r0, 0x8]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x20]
	ldr r0, =sub_8175A9C
	b _081757FA
	.pool
_081757B0:
	ldr r0, =gUnknown_0203BCE0
	strh r1, [r0]
	ldrh r2, [r4, 0x1E]
	movs r3, 0x1E
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _081757E0
	strh r2, [r4, 0x22]
	strh r1, [r4, 0x1E]
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175808
	b _081757FA
	.pool
_081757E0:
	cmp r0, 0x2
	bne _081757FC
	strh r2, [r4, 0x22]
	strh r1, [r4, 0x1E]
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_81758A4
_081757FA:
	str r0, [r4]
_081757FC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175774

	thumb_func_start sub_8175808
sub_8175808: @ 8175808
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175836
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_8176CA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =c2_080C9BFC
	str r0, [r1]
_08175836:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175808

	thumb_func_start c2_080C9BFC
c2_080C9BFC: @ 8175848
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl SetVBlankCallback
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrb r0, [r5, 0x16]
	adds r1, r4, 0
	bl sub_8176AB0
	lsls r0, 24
	cmp r0, 0
	beq _08175890
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_81754C8
	bl SetVBlankCallback
	ldr r0, =sub_8175744
	str r0, [r5]
_08175890:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_080C9BFC

	thumb_func_start sub_81758A4
sub_81758A4: @ 81758A4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081758D2
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_8176CA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81758E4
	str r0, [r1]
_081758D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81758A4

	thumb_func_start sub_81758E4
sub_81758E4: @ 81758E4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r1, r0
	mov r8, r1
	ldrb r7, [r1]
	cmp r7, 0
	beq _08175906
	cmp r7, 0x1
	beq _081759F0
_08175906:
	bl ResetSpriteData
	bl dp13_810BB8C
	bl FreeAllSpritePalettes
	ldr r1, =gReservedSpritePaletteCount
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gUnknown_085B0E04
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0C0C
	ldr r1, =0x06003800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0A02
	movs r1, 0x1
	movs r2, 0x3E
	bl LoadPalette
	movs r1, 0
	ldr r4, =0x0201c000
	movs r3, 0x11
	ldr r2, =0x000007ff
_0817593C:
	adds r0, r1, r4
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bls _0817593C
	movs r1, 0
	ldr r2, =0x0201d800
	ldr r6, =gUnknown_085E701C
	ldr r0, =0xfffff000
	adds r5, r2, r0
	movs r4, 0x22
	ldr r3, =0x000007ff
_08175958:
	adds r0, r1, r5
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r3
	bls _08175958
	movs r1, 0
	ldr r5, =0x0201d000
	movs r4, 0x33
	ldr r3, =0x000007ff
_0817596E:
	adds r0, r1, r5
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r3
	bls _0817596E
	movs r0, 0
	strh r0, [r2]
	ldr r1, =0x000053ff
	adds r0, r1, 0
	strh r0, [r2, 0x2]
	ldr r1, =0x0000529f
	adds r0, r1, 0
	strh r0, [r2, 0x4]
	ldr r1, =0x00007e94
	adds r0, r1, 0
	strh r0, [r2, 0x6]
	adds r0, r6, 0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_085E702C
	bl LoadSpritePalette
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08175A7A
	.pool
_081759F0:
	ldr r0, =sub_81760FC
	movs r1, 0
	bl CreateTask
	ldr r2, =gTasks
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	mov r9, r1
	movs r5, 0
	strh r0, [r4, 0xE]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r7, [r0, 0x8]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r6, [r0, 0xA]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r4, 0x16]
	strh r1, [r0, 0xC]
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0x20
	bl SetGpuReg
	ldr r1, =0x00000703
	movs r0, 0xE
	bl SetGpuReg
	movs r1, 0xCA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	mov r0, r9
	mov r1, r8
	strb r0, [r1]
	ldr r0, =gUnknown_0203BD28
	strh r5, [r0]
	ldr r0, =sub_8175744
	str r0, [r4]
_08175A7A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81758E4

	thumb_func_start sub_8175A9C
sub_8175A9C: @ 8175A9C
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x20]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	cmp r1, 0
	beq _08175AC4
	subs r0, 0x1
	strh r0, [r4, 0x20]
	b _08175AD8
	.pool
_08175AC4:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0xC
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175AE4
	str r0, [r4]
_08175AD8:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175A9C

	thumb_func_start sub_8175AE4
sub_8175AE4: @ 8175AE4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175B0A
	adds r0, r4, 0
	bl sub_8176CA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8175B1C
	str r0, [r1]
_08175B0A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175AE4

	thumb_func_start sub_8175B1C
sub_8175B1C: @ 8175B1C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8175CE4
	bl ResetPaletteFade
	movs r1, 0xE0
	lsls r1, 6
	movs r0, 0
	movs r2, 0
	bl sub_8176D1C
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x8
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r1, 0xE0
	lsls r1, 3
	movs r0, 0x8
	bl SetGpuReg
	movs r0, 0x1
	bl EnableInterrupts
	movs r1, 0xA0
	lsls r1, 1
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0xEB
	strh r1, [r0, 0x8]
	ldr r1, =sub_8175B90
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175B1C

	thumb_func_start sub_8175B90
sub_8175B90: @ 8175B90
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	cmp r1, 0
	beq _08175BB8
	subs r0, 0x1
	strh r0, [r4, 0x8]
	b _08175BCC
	.pool
_08175BB8:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0x6
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175BD8
	str r0, [r4]
_08175BCC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175B90

	thumb_func_start sub_8175BD8
sub_8175BD8: @ 8175BD8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08175C1E
	movs r0, 0xE0
	lsls r0, 6
	movs r1, 0
	bl sub_8176E40
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0xE1
	lsls r1, 5
	strh r1, [r0, 0x8]
	ldr r1, =sub_8175C34
	str r1, [r0]
_08175C1E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175BD8

	thumb_func_start sub_8175C34
sub_8175C34: @ 8175C34
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175CB8
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _08175C62
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	beq _08175C94
_08175C62:
	movs r0, 0x4
	bl FadeOutBGM
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175CC8
	str r0, [r4]
	b _08175CB8
	.pool
_08175C94:
	ldr r0, =0x00001be8
	cmp r1, r0
	bne _08175CA0
	movs r0, 0x8
	bl FadeOutBGM
_08175CA0:
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	ldr r0, =0x00001ab8
	cmp r1, r0
	bne _08175CB2
	movs r0, 0xE4
	lsls r0, 1
	bl m4aSongNumStart
_08175CB2:
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
_08175CB8:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175C34

	thumb_func_start sub_8175CC8
sub_8175CC8: @ 8175CC8
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175CDC
	movs r0, 0xFF
	bl SoftReset
_08175CDC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175CC8

	thumb_func_start sub_8175CE4
sub_8175CE4: @ 8175CE4
	push {lr}
	sub sp, 0x8
	movs r0, 0
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
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0
	str r2, [sp, 0x4]
	add r0, sp, 0x4
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, sp
	strh r2, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175CE4

	thumb_func_start sub_8175DA0
sub_8175DA0: @ 8175DA0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r5, r1, 0
	cmp r0, 0xA
	bhi _08175E00
	lsls r0, 2
	ldr r1, =_08175DD4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08175DD4:
	.4byte _08175E00
	.4byte _08175E40
	.4byte _08175E60
	.4byte _08175F38
	.4byte _08175F5C
	.4byte _08175FC8
	.4byte _08175E00
	.4byte _08175E00
	.4byte _08175E00
	.4byte _08175E00
	.4byte _08175FFC
_08175E00:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08175E12
	b _0817602A
_08175E12:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0, 0x8]
	movs r1, 0x48
	strh r1, [r0, 0xE]
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0x24]
	ldr r0, =gUnknown_0203BCE0
	strh r2, [r0]
	b _0817602A
	.pool
_08175E40:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r5
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08175E58
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	b _0817602A
_08175E58:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0817602A
_08175E60:
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r3, r0, r5
	movs r0, 0xA
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r5, r0, r5
	ldr r1, [r5]
	ldr r0, =sub_8175774
	mov r9, r2
	cmp r1, r0
	bne _08175F32
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	cmp r0, 0x38
	bgt _08175F2C
	movs r5, 0
	ldr r2, =gUnknown_085E6AF4
	mov r8, r2
	adds r7, r3, 0
	movs r6, 0xA0
	lsls r6, 19
_08175E92:
	movs r3, 0xC
	ldrsh r1, [r7, r3]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r5
	lsls r0, 2
	add r0, r8
	ldr r2, [r0]
	ldr r0, [r2, 0x4]
	lsrs r1, r6, 24
	ldrb r2, [r2, 0x1]
	bl sub_81755BC
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r5, 0x1
	cmp r5, 0x4
	ble _08175E92
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r3, =gTasks
	mov r2, r9
	adds r1, r2, r4
	lsls r1, 3
	adds r1, r3
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xA
	ldrsh r2, [r1, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r3
	movs r2, 0x1
	strh r2, [r0, 0x24]
	movs r2, 0xA
	ldrsh r1, [r1, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r3
	movs r3, 0x22
	ldrsh r0, [r0, r3]
	cmp r0, 0x1
	bne _08175F14
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x0000328d
	b _08175F1A
	.pool
_08175F14:
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x00001967
_08175F1A:
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0817602A
	.pool
_08175F2C:
	movs r0, 0xA
	strh r0, [r3, 0x8]
	b _0817602A
_08175F32:
	movs r0, 0
	strh r0, [r5, 0x24]
	b _0817602A
_08175F38:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817602A
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r1, 0x73
	strh r1, [r0, 0xE]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0817602A
	.pool
_08175F5C:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r5
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08175F74
	subs r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _0817602A
_08175F74:
	ldrb r0, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	bl sub_817603C
	lsls r0, 24
	cmp r0, 0
	beq _08175F8A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0817602A
_08175F8A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _08175FB0
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x0000328d
	b _08175FB6
	.pool
_08175FB0:
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x00001967
_08175FB6:
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0817602A
	.pool
_08175FC8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817602A
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	strh r0, [r1, 0x8]
	b _0817602A
	.pool
_08175FFC:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r5, 0
	movs r1, 0x1
	strh r1, [r0, 0x10]
	adds r0, r4, 0
	bl DestroyTask
	bl sub_81755A4
	ldr r4, =gUnknown_0203BCE8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
_0817602A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175DA0

	thumb_func_start sub_817603C
sub_817603C: @ 817603C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	lsls r1, 24
	lsrs r2, r1, 24
	adds r5, r2, 0
	ldr r4, =gTasks
	cmp r3, 0x6
	bne _0817605C
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_0817605C:
	cmp r3, 0xC
	bne _0817606E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0, 0x16]
	strh r1, [r0, 0x1E]
_0817606E:
	cmp r3, 0x12
	bne _0817607E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_0817607E:
	cmp r3, 0x18
	bne _08176092
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x16]
	movs r1, 0x1
	strh r1, [r0, 0x1E]
_08176092:
	cmp r3, 0x1E
	bne _081760A2
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_081760A2:
	cmp r3, 0x24
	bne _081760B6
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x3
	strh r1, [r0, 0x16]
	movs r1, 0x1
	strh r1, [r0, 0x1E]
_081760B6:
	cmp r3, 0x2A
	bne _081760C6
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_081760C6:
	cmp r6, 0x30
	bne _081760DA
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x4
	strh r1, [r0, 0x16]
	movs r1, 0x1
	strh r1, [r0, 0x1E]
_081760DA:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r4
	movs r1, 0x1E
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081760F4
	movs r0, 0
	b _081760F6
	.pool
_081760F4:
	movs r0, 0x1
_081760F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_817603C

	thumb_func_start sub_81760FC
sub_81760FC: @ 81760FC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r4
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _0817612C
	cmp r0, 0x1
	bgt _0817611A
	b _08176244
_0817611A:
	cmp r0, 0x2
	beq _08176158
	cmp r0, 0x3
	bne _08176124
	b _08176230
_08176124:
	b _08176244
	.pool
_0817612C:
	ldr r0, =gUnknown_0203BCE8
	ldr r0, [r0]
	adds r0, 0x90
	ldrh r0, [r0]
	cmp r0, 0
	bne _0817614E
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0817614E
	b _08176244
_0817614E:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	b _08176242
	.pool
_08176158:
	ldr r6, =gUnknown_0203BCE8
	ldr r3, [r6]
	adds r0, r3, 0
	adds r0, 0x8E
	ldrh r0, [r0]
	cmp r0, 0x47
	beq _08176244
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, [r0]
	ldr r0, =sub_8175774
	cmp r1, r0
	bne _08176244
	adds r0, r3, 0
	adds r0, 0x92
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r3, r0
	ldrh r0, [r0]
	ldr r4, =gUnknown_085E6F7C
	adds r1, r3, 0
	adds r1, 0x90
	ldrh r3, [r1]
	lsls r2, r3, 1
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, 0x1
	adds r2, r4
	ldrb r2, [r2]
	bl sub_8177224
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r6]
	adds r1, r0, 0
	adds r1, 0x92
	ldrh r3, [r1]
	adds r0, 0x94
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r3, r0
	bge _081761D8
	adds r0, r3, 0x1
	strh r0, [r1]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x32
	b _081761EA
	.pool
_081761D8:
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x80
	lsls r1, 2
_081761EA:
	strh r1, [r0, 0x34]
	ldr r0, =gUnknown_0203BCE8
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x8E
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x90
	ldrh r0, [r1]
	cmp r0, 0x2
	bne _08176210
	movs r0, 0
	b _08176212
	.pool
_08176210:
	adds r0, 0x1
_08176212:
	strh r0, [r1]
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0x32
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08176244
	.pool
_08176230:
	ldrh r1, [r2, 0xE]
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08176240
	subs r0, r1, 0x1
	strh r0, [r2, 0xE]
	b _08176244
_08176240:
	movs r0, 0x1
_08176242:
	strh r0, [r2, 0x8]
_08176244:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81760FC

	thumb_func_start sub_817624C
sub_817624C: @ 817624C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r6, r1, 0
	cmp r0, 0x32
	bls _08176268
	b _08176514
_08176268:
	lsls r0, 2
	ldr r1, =_0817627C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0817627C:
	.4byte _08176348
	.4byte _0817636C
	.4byte _081763C0
	.4byte _081763D8
	.4byte _08176414
	.4byte _08176438
	.4byte _08176484
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176490
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _081764B0
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _081764D4
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176508
_08176348:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r6
	ldrh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 17
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0xC
	bl Sin
	ldr r1, =gUnknown_0203BD26
	strh r0, [r1]
	b _08176390
	.pool
_0817636C:
	ldr r7, =gUnknown_0203BD26
	movs r3, 0
	ldrsh r4, [r7, r3]
	cmp r4, 0
	beq _0817639C
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r6
	ldrh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 17
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0xC
	bl Sin
	strh r0, [r7]
_08176390:
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	b _08176514
	.pool
_0817639C:
	ldr r3, =gSprites
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r2, 0x2
	strh r2, [r0, 0x2E]
	strh r4, [r1, 0x12]
	b _08176430
	.pool
_081763C0:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r6
	ldrh r2, [r1, 0x12]
	movs r3, 0x12
	ldrsh r0, [r1, r3]
	cmp r0, 0x3F
	bgt _08176430
	adds r0, r2, 0x1
	strh r0, [r1, 0x12]
	b _0817644E
_081763D8:
	ldr r3, =gSprites
	lsls r2, r5, 2
	adds r2, r5
	lsls r2, 3
	adds r2, r6
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x3
	strh r1, [r0, 0x2E]
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	movs r0, 0x78
	strh r0, [r2, 0x10]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _08176514
	.pool
_08176414:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r6
	ldrh r2, [r1, 0x10]
	movs r3, 0x10
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0817642C
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	b _08176514
_0817642C:
	movs r0, 0x40
	strh r0, [r1, 0x12]
_08176430:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08176514
_08176438:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r6
	ldrh r1, [r4, 0x12]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08176464
	subs r0, r1, 0x1
	strh r0, [r4, 0x12]
_0817644E:
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0x14
	bl Sin
	ldr r1, =gUnknown_0203BD26
	strh r0, [r1]
	b _08176514
	.pool
_08176464:
	ldr r2, =gSprites
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08176514
	.pool
_08176484:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r6
	movs r1, 0x32
	b _08176512
_08176490:
	ldr r3, =gSprites
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r2, 0x2
	b _081764C8
	.pool
_081764B0:
	ldr r3, =gSprites
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r2, 0x4
_081764C8:
	strh r2, [r0, 0x2E]
	movs r0, 0x32
	strh r0, [r1, 0x8]
	b _08176514
	.pool
_081764D4:
	ldr r3, =gSprites
	lsls r2, r5, 2
	adds r2, r5
	lsls r2, 3
	adds r2, r6
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x5
	strh r1, [r0, 0x2E]
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x3
	strh r1, [r0, 0x2E]
	movs r0, 0x32
	strh r0, [r2, 0x8]
	b _08176514
	.pool
_08176508:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r6
	movs r1, 0
_08176512:
	strh r1, [r0, 0x8]
_08176514:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_817624C

	thumb_func_start sub_817651C
sub_817651C: @ 817651C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r3, 0x8
	ldrsh r0, [r0, r3]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0817655C
	lsls r0, 2
	ldr r1, =_08176548
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08176548:
	.4byte _0817655C
	.4byte _081765A0
	.4byte _081765AC
	.4byte _081765F4
	.4byte _08176640
_0817655C:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r2, r0, r4
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	ldr r5, =0x00007fff
	cmp r0, r5
	beq _081765A0
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r3, r0, r4
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	bne _081765A0
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x14
	strh r0, [r1, 0x8]
	strh r5, [r2, 0xA]
_081765A0:
	movs r0, 0
	bl sub_817B540
	b _08176646
	.pool
_081765AC:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r2, r0, r4
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	ldr r5, =0x00007fff
	cmp r0, r5
	beq _08176638
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r3, r0, r4
	ldrh r1, [r3, 0x12]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	movs r1, 0xA0
	lsls r1, 2
	cmp r0, r1
	bne _08176638
	movs r0, 0x1
	strh r0, [r3, 0x8]
	strh r5, [r2, 0xA]
	b _08176638
	.pool
_081765F4:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r2, r0, r4
	ldrh r3, [r2, 0xA]
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	ldr r5, =0x00007fff
	cmp r1, r5
	beq _08176638
	movs r0, 0x92
	lsls r0, 2
	cmp r1, r0
	bne _08176634
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r1, 0xA
	strh r1, [r0, 0x8]
	strh r5, [r2, 0xA]
	b _08176638
	.pool
_08176634:
	adds r0, r3, 0x1
	strh r0, [r2, 0xA]
_08176638:
	movs r0, 0x1
	bl sub_817B540
	b _08176646
_08176640:
	movs r0, 0x2
	bl sub_817B540
_08176646:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817651C

	thumb_func_start sub_817664C
sub_817664C: @ 817664C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r0, 0x4
	bls _08176662
	b _081769E0
_08176662:
	lsls r0, 2
	ldr r1, =_08176670
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08176670:
	.4byte _08176684
	.4byte _0817672C
	.4byte _081767D8
	.4byte _08176884
	.4byte _08176934
_08176684:
	ldr r5, =gSprites
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r2, 0x88
	lsls r2, 1
	strh r2, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	movs r2, 0x20
	b _081769D4
	.pool
_0817672C:
	ldr r5, =gSprites
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	movs r2, 0x20
	b _081769D4
	.pool
_081767D8:
	ldr r5, =gSprites
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x1
	b _081769D4
	.pool
_08176884:
	ldr r5, =gSprites
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x1
	b _081769D4
	.pool
_08176934:
	ldr r5, =gSprites
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x58
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x98
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x2
_081769D4:
	movs r3, 0x8
	bl sub_817B3DC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x8]
_081769E0:
	ldr r0, =sub_817651C
	movs r1, 0
	bl CreateTask
	ldr r6, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r5, r1, r6
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0
	strh r0, [r5, 0xC]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	mov r1, r8
	strh r1, [r0, 0x8]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r4, [r0, 0xA]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r7, [r0, 0xC]
	ldr r0, =sub_817624C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r4, [r0, 0x8]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r7, [r0, 0xA]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldrh r1, [r5, 0x12]
	strh r1, [r0, 0xC]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldrh r1, [r5, 0x14]
	strh r1, [r0, 0xE]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r4, [r0, 0x10]
	mov r1, r8
	cmp r1, 0x2
	bne _08176A94
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r6
	movs r0, 0x45
	strh r0, [r1, 0x12]
_08176A94:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817664C

	thumb_func_start sub_8176AB0
sub_8176AB0: @ 8176AB0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _08176B30
	cmp r0, 0x1
	ble _08176AD6
	cmp r0, 0x2
	beq _08176B54
	cmp r0, 0x3
	bne _08176AD6
	b _08176C80
_08176AD6:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0x8
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
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	movs r0, 0x1
	strb r0, [r6]
	b _08176C96
	.pool
_08176B30:
	ldr r1, =gUnknown_0203BD24
	movs r0, 0x22
	strh r0, [r1]
	ldr r1, =gUnknown_0203BD26
	movs r0, 0
	strh r0, [r1]
	adds r0, r4, 0
	bl sub_817B1C8
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _08176C96
	.pool
_08176B54:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08176BD8
	ldr r0, =gUnknown_085F5334
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F53BC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5354
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5384
	bl LoadSpritePalettes
	movs r0, 0x78
	movs r1, 0x2E
	bl sub_817B834
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	strh r2, [r4, 0x12]
	ldr r6, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r6, 0
	adds r5, 0x1C
	adds r2, r0, r5
	ldr r1, =sub_8176EE8
	str r1, [r2]
	adds r6, 0x8
	adds r0, r6
	ldr r1, =gUnknown_085E6FD0
	str r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x2E
	bl sub_817B88C
	b _08176C2C
	.pool
_08176BD8:
	ldr r0, =gUnknown_085F5344
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F53AC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5354
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5384
	bl LoadSpritePalettes
	movs r0, 0x78
	movs r1, 0x2E
	bl sub_817B88C
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	strh r2, [r4, 0x12]
	ldr r6, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r6, 0
	adds r5, 0x1C
	adds r2, r0, r5
	ldr r1, =sub_8176EE8
	str r1, [r2]
	adds r6, 0x8
	adds r0, r6
	ldr r1, =gUnknown_085E6FD0
	str r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x2E
	bl sub_817B834
_08176C2C:
	lsls r0, 24
	lsrs r2, r0, 24
	strh r2, [r4, 0x14]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r5
	ldr r1, =sub_8176F90
	str r1, [r5]
	adds r0, r6
	ldr r1, =gUnknown_085E7010
	str r1, [r0]
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08176C96
	.pool
_08176C80:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_817664C
	adds r0, r4, 0
	bl sub_817B3A8
	movs r0, 0
	strb r0, [r6]
	movs r0, 0x1
	b _08176C98
_08176C96:
	movs r0, 0
_08176C98:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8176AB0

	thumb_func_start sub_8176CA0
sub_8176CA0: @ 8176CA0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176CC6
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0x8]
_08176CC6:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176CDC
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0xA]
_08176CDC:
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176CF2
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0xC]
_08176CF2:
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176D08
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0xE]
_08176D08:
	ldr r1, =gUnknown_0203BD28
	movs r0, 0x1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8176CA0

	thumb_func_start sub_8176D1C
sub_8176D1C: @ 8176D1C
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r4, 16
	lsrs r5, r4, 16
	ldr r0, =gUnknown_085E5770
	movs r6, 0xC0
	lsls r6, 19
	adds r3, r6
	adds r1, r3, 0
	bl LZ77UnCompVram
	ldr r0, =gIntroCopyright_Pal
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	lsrs r4, 20
	lsls r4, 28
	lsrs r4, 16
	movs r1, 0
	adds r4, 0x1
	ldr r2, =0x000003ff
_08176D52:
	lsls r0, r1, 1
	adds r0, r7
	adds r0, r6
	strh r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bls _08176D52
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8176D1C

	thumb_func_start sub_8176D78
sub_8176D78: @ 8176D78
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	movs r0, 0x3F
	ands r0, r2
	adds r1, r0, 0
	adds r1, 0x50
	cmp r2, 0xFF
	bne _08176D90
	movs r0, 0x1
	b _08176DB6
_08176D90:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _08176DA0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
_08176DA0:
	movs r0, 0x40
	ands r3, r0
	cmp r3, 0
	beq _08176DB4
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r0, r1, 16
	lsrs r1, r0, 16
_08176DB4:
	adds r0, r1, 0
_08176DB6:
	pop {r1}
	bx r1
	thumb_func_end sub_8176D78

	thumb_func_start sub_8176DBC
sub_8176DBC: @ 8176DBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp]
	ldr r0, [sp, 0x2C]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x4]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x8]
	lsls r0, 16
	lsrs r0, 20
	lsls r0, 28
	lsrs r0, 16
	mov r9, r0
	movs r5, 0
_08176DEA:
	movs r4, 0
	lsls r7, r5, 1
	ldr r1, [sp, 0x4]
	adds r0, r1, r5
	adds r2, r5, 0x1
	mov r8, r2
	lsls r0, 6
	ldr r1, [sp, 0x8]
	adds r6, r0, r1
_08176DFC:
	adds r0, r7, r5
	adds r0, r4
	ldr r2, [sp]
	adds r0, r2, r0
	ldrb r0, [r0]
	bl sub_8176D78
	mov r2, r10
	adds r1, r2, r4
	lsls r1, 1
	adds r1, r6
	movs r2, 0xC0
	lsls r2, 19
	adds r1, r2
	add r0, r9
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _08176DFC
	mov r1, r8
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _08176DEA
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8176DBC

	thumb_func_start sub_8176E40
sub_8176E40: @ 8176E40
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsrs r1, 20
	lsls r1, 28
	lsrs r1, 16
	movs r2, 0
	ldr r7, =gUnknown_085E5BAC
	movs r4, 0xC0
	lsls r4, 19
	adds r1, 0x1
	ldr r3, =0x000003ff
_08176E5E:
	lsls r0, r2, 1
	adds r0, r5
	adds r0, r4
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	bls _08176E5E
	str r6, [sp]
	adds r0, r7, 0
	movs r1, 0x3
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r0, =gUnknown_085E5BBB
	str r6, [sp]
	movs r1, 0x7
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r4, =gUnknown_085E5BCA
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r0, =gUnknown_085E5BD9
	str r6, [sp]
	movs r1, 0x14
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r0, =gUnknown_085E5BE8
	str r6, [sp]
	movs r1, 0x18
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8176E40

	thumb_func_start sub_8176EE8
sub_8176EE8: @ 8176EE8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08176F04
	adds r0, r4, 0
	bl DestroySprite
	b _08176F88
	.pool
_08176F04:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x5
	bhi _08176F88
	lsls r0, 2
	ldr r1, =_08176F1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08176F1C:
	.4byte _08176F34
	.4byte _08176F3E
	.4byte _08176F44
	.4byte _08176F4E
	.4byte _08176F58
	.4byte _08176F6E
_08176F34:
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	b _08176F88
_08176F3E:
	adds r0, r4, 0
	movs r1, 0x1
	b _08176F72
_08176F44:
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnimIfDifferent
	b _08176F88
_08176F4E:
	adds r0, r4, 0
	movs r1, 0x3
	bl StartSpriteAnimIfDifferent
	b _08176F88
_08176F58:
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x78
	ble _08176F88
	subs r0, r1, 0x1
	b _08176F86
_08176F6E:
	adds r0, r4, 0
	movs r1, 0
_08176F72:
	bl StartSpriteAnimIfDifferent
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _08176F88
	subs r0, r2, 0x1
_08176F86:
	strh r0, [r4, 0x20]
_08176F88:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8176EE8

	thumb_func_start sub_8176F90
sub_8176F90: @ 8176F90
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08176FAC
	adds r0, r4, 0
	bl DestroySprite
	b _08177048
	.pool
_08176FAC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08176FD4
	cmp r0, 0x1
	bgt _08176FBE
	cmp r0, 0
	beq _08176FC8
	b _08177048
_08176FBE:
	cmp r0, 0x2
	beq _08177010
	cmp r0, 0x3
	beq _0817702E
	b _08177048
_08176FC8:
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	b _08177048
_08176FD4:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0xC8
	ble _08176FE6
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnimIfDifferent
	b _08176FEE
_08176FE6:
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnimIfDifferent
_08176FEE:
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _08177000
	subs r0, r2, 0x2
	strh r0, [r4, 0x20]
_08177000:
	ldr r0, =gUnknown_0203BD26
	ldrh r0, [r0]
	negs r0, r0
	strh r0, [r4, 0x26]
	b _08177048
	.pool
_08177010:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	ldrh r1, [r4, 0x3C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08177048
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	b _08177046
_0817702E:
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnimIfDifferent
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _08177048
	subs r0, r2, 0x1
_08177046:
	strh r0, [r4, 0x20]
_08177048:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8176F90

	thumb_func_start sub_8177050
sub_8177050: @ 8177050
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0817706C
	ldrh r0, [r5, 0x3A]
	bl sub_818D820
	b _0817721C
	.pool
_0817706C:
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0xA
	bhi _081770B4
	lsls r0, 2
	ldr r1, =_08177088
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08177088:
	.4byte _081770B4
	.4byte _0817710E
	.4byte _08177190
	.4byte _081771C6
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081771FE
	.4byte _08177206
_081770B4:
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r5, 0x1]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x3]
	movs r0, 0x10
	strh r0, [r5, 0x32]
	ldrh r4, [r5, 0x30]
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x80
	lsls r0, 9
	movs r1, 0x10
	bl __divsi3
	adds r1, r0, 0
	str r1, [sp]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	b _0817721C
_0817710E:
	ldrh r1, [r5, 0x32]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	cmp r0, 0xFF
	bgt _08177144
	adds r0, r1, 0
	adds r0, 0x8
	strh r0, [r5, 0x32]
	ldrh r4, [r5, 0x30]
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x32
	ldrsh r1, [r5, r0]
	movs r0, 0x80
	lsls r0, 9
	bl __divsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	b _0817714A
_08177144:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0817714A:
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	cmp r1, 0x2
	beq _0817721C
	cmp r1, 0x2
	bgt _0817715C
	cmp r1, 0x1
	beq _08177162
	b _0817721C
_0817715C:
	cmp r1, 0x3
	beq _0817717A
	b _0817721C
_08177162:
	ldrh r1, [r5, 0x3C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08177172
	ldrh r0, [r5, 0x22]
	adds r0, 0x1
	strh r0, [r5, 0x22]
_08177172:
	ldrh r0, [r5, 0x20]
	subs r0, 0x2
	strh r0, [r5, 0x20]
	b _0817721C
_0817717A:
	ldrh r0, [r5, 0x3C]
	ands r1, r0
	cmp r1, 0
	bne _08177188
	ldrh r0, [r5, 0x22]
	adds r0, 0x1
	strh r0, [r5, 0x22]
_08177188:
	ldrh r0, [r5, 0x20]
	adds r0, 0x2
	strh r0, [r5, 0x20]
	b _0817721C
_08177190:
	ldrh r1, [r5, 0x34]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _081771A0
	subs r0, r1, 0x1
	strh r0, [r5, 0x34]
	b _0817721C
_081771A0:
	movs r1, 0xF4
	lsls r1, 4
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldrb r1, [r5, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x1]
	movs r0, 0x10
	strh r0, [r5, 0x34]
	b _081771FE
_081771C6:
	ldrh r1, [r5, 0x34]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _081771EC
	subs r1, 0x1
	strh r1, [r5, 0x34]
	movs r0, 0x34
	ldrsh r2, [r5, r0]
	movs r0, 0x10
	subs r0, r2
	lsls r0, 8
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	b _0817721C
_081771EC:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x9
	strh r0, [r5, 0x2E]
	b _0817721C
_081771FE:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0817721C
_08177206:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	ldrh r0, [r5, 0x3A]
	bl sub_818D820
_0817721C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8177050

	thumb_func_start sub_8177224
sub_8177224: @ 8177224
	push {r4-r7,lr}
	adds r5, r3, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r3, r5, 0
	bl sub_80C0E9C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gSprites
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r2, r1, r6
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r2, 0x5]
	adds r0, r5, 0x1
	strh r0, [r2, 0x30]
	movs r0, 0x3E
	adds r0, r2
	mov r12, r0
	ldrb r0, [r0]
	orrs r0, r3
	mov r3, r12
	strb r0, [r3]
	adds r0, r6, 0
	adds r0, 0x1C
	adds r1, r0
	ldr r0, =sub_8177050
	str r0, [r1]
	strh r4, [r2, 0x3A]
	ldr r0, =gUnknown_085E7068
	movs r7, 0x20
	ldrsh r1, [r2, r7]
	movs r3, 0x22
	ldrsh r2, [r2, r3]
	movs r3, 0x1
	bl CreateSprite
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r4, [r0, 0x2E]
	lsls r5, 24
	lsrs r5, 24
	adds r1, r5, 0
	bl StartSpriteAnimIfDifferent
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8177224

	thumb_func_start sub_81772B8
sub_81772B8: @ 81772B8
	push {r4,lr}
	adds r3, r0, 0
	ldr r4, =gSprites
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0xA
	beq _081772DC
	ldr r0, =gUnknown_0203BD28
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _081772EC
_081772DC:
	adds r0, r3, 0
	bl DestroySprite
	b _08177380
	.pool
_081772EC:
	adds r0, r1, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	movs r1, 0x4
	ands r1, r0
	mov r0, r12
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r0, 0xC
	ands r0, r1
	ldrb r2, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	movs r0, 0x2E
	ldrsh r2, [r3, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r2, 0x4
	negs r2, r2
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	movs r1, 0x3E
	ands r1, r0
	ldrb r2, [r3, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x20]
	strh r0, [r3, 0x20]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x22]
	strh r0, [r3, 0x22]
_08177380:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81772B8

	thumb_func_start sub_8177388
sub_8177388: @ 8177388
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =0x00004023
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl sub_8133EDC
	lsls r0, 16
	lsrs r0, 16
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	movs r4, 0x1
	movs r6, 0
	ldr r5, =0x00000181
_081773B4:
	adds r0, r4, 0
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _081773D4
	ldr r0, =gUnknown_0203BCE8
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0x96
	adds r0, r1
	strh r4, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_081773D4:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r5
	bls _081773B4
	adds r4, r6, 0
	ldr r0, =0x00000181
	ldr r1, =gUnknown_0203BCE8
	mov r8, r1
	lsls r7, r4, 16
	cmp r4, r0
	bhi _08177406
	mov r5, r8
	movs r3, 0
	adds r2, r0, 0
_081773F2:
	ldr r0, [r5]
	lsls r1, r4, 1
	adds r0, 0x96
	adds r0, r1
	strh r3, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r2
	bls _081773F2
_08177406:
	mov r2, r8
	ldr r1, [r2]
	ldr r2, =0x0000039a
	adds r0, r1, r2
	strh r6, [r0]
	lsrs r0, r7, 16
	cmp r0, 0x46
	bhi _08177430
	adds r0, r1, 0
	adds r0, 0x94
	strh r6, [r0]
	b _08177436
	.pool
_08177430:
	adds r1, 0x94
	movs r0, 0x47
	strh r0, [r1]
_08177436:
	movs r6, 0
	ldr r0, =gUnknown_0203BCE8
	mov r9, r0
	ldr r1, =0x0000039a
	mov r8, r1
	movs r7, 0
	b _08177450
	.pool
_0817744C:
	cmp r6, 0x46
	bhi _081774AC
_08177450:
	bl Random
	mov r2, r9
	ldr r4, [r2]
	mov r1, r8
	adds r5, r4, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r5]
	bl __umodsi3
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, r6, 1
	adds r1, r4, r1
	lsls r0, r3, 1
	adds r4, 0x96
	adds r2, r4, r0
	ldrh r0, [r2]
	strh r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	strh r7, [r2]
	ldrh r0, [r5]
	subs r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r3, r0
	beq _081774A0
	ldrh r0, [r5]
	lsls r0, 1
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldrh r0, [r5]
	lsls r0, 1
	adds r0, r4, r0
	strh r7, [r0]
_081774A0:
	mov r2, r9
	ldr r0, [r2]
	add r0, r8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0817744C
_081774AC:
	ldr r1, =gUnknown_0203BCE8
	ldr r2, [r1]
	adds r3, r2, 0
	adds r3, 0x94
	ldrh r0, [r3]
	mov r8, r1
	cmp r0, 0x46
	bhi _081774F8
	adds r6, r0, 0
	movs r3, 0
	cmp r6, 0x46
	bhi _081774EE
	mov r4, r8
_081774C6:
	ldr r2, [r4]
	lsls r1, r6, 1
	adds r1, r2, r1
	lsls r0, r3, 1
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r2, 0x94
	ldrh r2, [r2]
	cmp r3, r2
	bne _081774E4
	movs r3, 0
_081774E4:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x46
	bls _081774C6
_081774EE:
	mov r1, r8
	ldr r0, [r1]
	b _08177538
	.pool
_081774F8:
	movs r4, 0
	ldrh r0, [r2]
	cmp r0, r10
	beq _08177516
	adds r1, r2, 0
_08177502:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r0, r4, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, r10
	beq _08177516
	cmp r4, 0x46
	bls _08177502
_08177516:
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x94
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r4, r0
	bge _08177536
	lsls r0, r4, 1
	adds r0, r2, r0
	adds r2, 0x8C
	ldrh r1, [r2]
	strh r1, [r0]
	mov r1, r10
	strh r1, [r2]
	b _0817753E
_08177536:
	adds r0, r2, 0
_08177538:
	adds r0, 0x8C
	mov r2, r10
	strh r2, [r0]
_0817753E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x94
	movs r1, 0x47
	strh r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8177388

	.align 2, 0 @ Don't pad with nop.
