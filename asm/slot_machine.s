	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_812A4DC
sub_812A4DC: @ 812A4DC
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _0812A500
	cmp r1, 0x1
	beq _0812A518
	b _0812A530
	.pool
_0812A500:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0812A530
_0812A518:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812A530
	ldr r0, =sub_812A588
	bl SetMainCallback2
	adds r0, r5, 0
	bl DestroyTask
_0812A530:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A4DC

	thumb_func_start PlaySlotMachine
PlaySlotMachine: @ 812A540
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_0203AB34
	movs r0, 0x68
	bl AllocZeroed
	str r0, [r5]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_812A6D4
	ldr r0, =sub_812A4DC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x8]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlaySlotMachine

	thumb_func_start sub_812A588
sub_812A588: @ 812A588
	push {lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xB
	bhi _0812A666
	lsls r0, 2
	ldr r1, =_0812A5AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812A5AC:
	.4byte _0812A5DC
	.4byte _0812A5E6
	.4byte _0812A5EC
	.4byte _0812A5F6
	.4byte _0812A5FC
	.4byte _0812A602
	.4byte _0812A608
	.4byte _0812A60E
	.4byte _0812A638
	.4byte _0812A63E
	.4byte _0812A644
	.4byte _0812A660
_0812A5DC:
	bl sub_812A750
	bl sub_812A8C4
	b _0812A64C
_0812A5E6:
	bl sub_812A7BC
	b _0812A64C
_0812A5EC:
	bl sub_812A810
	bl sub_812A834
	b _0812A64C
_0812A5F6:
	bl sub_812A9AC
	b _0812A64C
_0812A5FC:
	bl sub_812A9CC
	b _0812A64C
_0812A602:
	bl sub_812AA48
	b _0812A64C
_0812A608:
	bl sub_812A79C
	b _0812A64C
_0812A60E:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	b _0812A64C
_0812A638:
	bl sub_812FBC4
	b _0812A64C
_0812A63E:
	bl sub_812FB14
	b _0812A64C
_0812A644:
	bl sub_812AA78
	bl sub_812AA90
_0812A64C:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0812A666
	.pool
_0812A660:
	ldr r0, =sub_812A670
	bl SetMainCallback2
_0812A666:
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A588

	thumb_func_start sub_812A670
sub_812A670: @ 812A670
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_812A670

	thumb_func_start sub_812A688
sub_812A688: @ 812A688
	push {r4,lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	adds r0, 0x58
	ldrh r1, [r0]
	movs r0, 0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0x5A
	ldrh r1, [r0]
	movs r0, 0x44
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0x5C
	ldrh r1, [r0]
	movs r0, 0x48
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, 0x5E
	ldrh r1, [r0]
	movs r0, 0x4A
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A688

	thumb_func_start sub_812A6D4
sub_812A6D4: @ 812A6D4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =TaskDummy9
	movs r1, 0xFF
	bl CreateTask
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	strh r4, [r0, 0x8]
	adds r0, 0xA
	adds r1, r5, 0
	bl StoreWordInTwoHalfwords
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A6D4

	thumb_func_start sub_812A710
sub_812A710: @ 812A710
	push {lr}
	ldr r0, =TaskDummy9
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	ldr r0, =gTasks
	adds r2, r0
	ldr r3, =gUnknown_0203AB34
	ldr r1, [r3]
	ldrh r0, [r2, 0x8]
	strb r0, [r1, 0x1]
	adds r2, 0xA
	ldr r1, [r3]
	adds r1, 0x64
	adds r0, r2, 0
	bl LoadWordFromTwoHalfwords
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A710

	thumb_func_start TaskDummy9
TaskDummy9: @ 812A74C
	bx lr
	thumb_func_end TaskDummy9

	thumb_func_start sub_812A750
sub_812A750: @ 812A750
	push {lr}
	sub sp, 0x4
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	str r0, [sp]
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, =0x05006000
	mov r0, sp
	bl CpuSet
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085A7424
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085A7434
	bl InitWindows
	bl DeactivateAllTextPrinters
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A750

	thumb_func_start sub_812A79C
sub_812A79C: @ 812A79C
	push {lr}
	ldr r0, =sub_812A688
	bl SetVBlankCallback
	movs r0, 0x1
	bl EnableInterrupts
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A79C

	thumb_func_start sub_812A7BC
sub_812A7BC: @ 812A7BC
	push {r4-r7,lr}
	sub sp, 0x4
	movs r2, 0xC0
	lsls r2, 19
	movs r3, 0x80
	lsls r3, 9
	mov r4, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_0812A7DA:
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r5
	subs r3, r5
	cmp r3, r5
	bhi _0812A7DA
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A7BC

	thumb_func_start sub_812A810
sub_812A810: @ 812A810
	sub sp, 0x4
	movs r2, 0xE0
	lsls r2, 19
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r0, =0x040000d4
	str r1, [r0]
	str r2, [r0, 0x4]
	ldr r1, =0x81000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	add sp, 0x4
	bx lr
	.pool
	thumb_func_end sub_812A810

	thumb_func_start sub_812A834
sub_812A834: @ 812A834
	push {lr}
	movs r0, 0x8
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xA
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xC
	movs r1, 0
	bl SetGpuReg
	movs r0, 0xE
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
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3F
	bl SetGpuReg
	ldr r1, =0x00001048
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000809
	movs r0, 0x52
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A834

	thumb_func_start sub_812A8C4
sub_812A8C4: @ 812A8C4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_812A710
	ldr r5, =gUnknown_0203AB34
	ldr r0, [r5]
	movs r4, 0
	strb r4, [r0]
	ldr r0, [r5]
	strb r4, [r0, 0x2]
	bl Random
	ldr r2, [r5]
	movs r1, 0x1
	ands r1, r0
	strb r1, [r2, 0x3]
	ldr r0, [r5]
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	movs r1, 0
	strh r4, [r0, 0x8]
	strb r1, [r0, 0xA]
	ldr r0, [r5]
	strb r1, [r0, 0xB]
	bl GetCoins
	ldr r2, [r5]
	strh r0, [r2, 0xC]
	strh r4, [r2, 0xE]
	strh r4, [r2, 0x10]
	strh r4, [r2, 0x12]
	strh r4, [r2, 0x18]
	movs r0, 0x8
	strh r0, [r2, 0x1A]
	adds r1, r2, 0
	adds r1, 0x58
	movs r0, 0xF0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0xA0
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x5C
	movs r1, 0x3F
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	bl GetCurrentMapMusic
	ldr r1, [r5]
	adds r1, 0x60
	strh r0, [r1]
	movs r7, 0
	ldr r0, =gUnknown_085A76B4
	mov r8, r0
_0812A934:
	ldr r0, =gUnknown_0203AB34
	ldr r4, [r0]
	lsls r6, r7, 1
	adds r0, r4, 0
	adds r0, 0x22
	adds r0, r6
	movs r1, 0
	strh r1, [r0]
	adds r5, r4, 0
	adds r5, 0x28
	adds r5, r6
	ldrb r0, [r4, 0x3]
	lsls r0, 1
	lsls r1, r7, 2
	adds r0, r1
	add r0, r8
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x15
	bl __modsi3
	strh r0, [r5]
	adds r4, 0x1C
	adds r4, r6
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	movs r2, 0xFC
	lsls r2, 1
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r2, 0
	bl __modsi3
	strh r0, [r4]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x2
	bls _0812A934
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	bl sub_80EDE70
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A8C4

	thumb_func_start sub_812A9AC
sub_812A9AC: @ 812A9AC
	push {lr}
	bl ResetPaletteFade
	bl ResetSpriteData
	ldr r1, =gOamLimit
	movs r0, 0x80
	strb r0, [r1]
	bl FreeAllSpritePalettes
	bl ResetTasks
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A9AC

	thumb_func_start sub_812A9CC
sub_812A9CC: @ 812A9CC
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203AACC
	movs r0, 0x8
	bl Alloc
	str r0, [r4]
	ldr r4, =gUnknown_0203AAD0
	movs r0, 0xE
	bl AllocZeroed
	str r0, [r4]
	ldr r5, =gUnknown_0203AADC
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r5]
	ldr r1, [r4]
	ldr r2, =0x00002051
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, [r4]
	ldr r2, =0x00002851
	adds r0, r2, 0
	strh r0, [r1, 0x2]
	ldr r2, =0x00002061
	adds r0, r2, 0
	strh r0, [r1, 0x4]
	ldr r2, =0x00002861
	adds r0, r2, 0
	strh r0, [r1, 0x6]
	ldr r2, =0x000020be
	adds r0, r2, 0
	strh r0, [r1, 0x8]
	ldr r2, =0x000028be
	adds r0, r2, 0
	strh r0, [r1, 0xA]
	ldr r2, =0x000020bf
	adds r0, r2, 0
	strh r0, [r1, 0xC]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812A9CC

	thumb_func_start sub_812AA48
sub_812AA48: @ 812AA48
	push {lr}
	bl sub_812F908
	bl sub_812F958
	bl sub_812F7E4
	movs r1, 0x80
	lsls r1, 2
	movs r0, 0
	movs r2, 0xF0
	bl LoadMessageBoxGfx
	movs r1, 0x85
	lsls r1, 2
	movs r0, 0
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	movs r0, 0
	bl PutWindowTilemap
	pop {r0}
	bx r0
	thumb_func_end sub_812AA48

	thumb_func_start sub_812AA78
sub_812AA78: @ 812AA78
	push {lr}
	bl sub_812E0E4
	bl sub_812E1C8
	bl sub_812CEF4
	bl sub_812E300
	pop {r0}
	bx r0
	thumb_func_end sub_812AA78

	thumb_func_start sub_812AA90
sub_812AA90: @ 812AA90
	push {lr}
	bl sub_812D188
	bl sub_812BE5C
	bl sub_812DE94
	bl sub_812AAA8
	pop {r0}
	bx r0
	thumb_func_end sub_812AA90

	thumb_func_start sub_812AAA8
sub_812AAA8: @ 812AAA8
	push {r4,lr}
	ldr r4, =sub_812AAC8
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812AAA8

	thumb_func_start sub_812AAC8
sub_812AAC8: @ 812AAC8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_085A7450
	lsls r1, r0, 2
	adds r1, r0
	lsls r4, r1, 3
	ldr r5, =gTasks
_0812AAD8:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	adds r0, r4, r5
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0812AAD8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812AAC8

	thumb_func_start sub_812AB04
sub_812AB04: @ 812AB04
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	bl sub_812D3B4
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AB04

	thumb_func_start sub_812AB38
sub_812AB38: @ 812AB38
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812AB50
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0812AB50:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AB38

	thumb_func_start sub_812AB60
sub_812AB60: @ 812AB60
	push {lr}
	ldr r3, =gUnknown_0203AB34
	ldr r1, [r3]
	movs r0, 0
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x12]
	strh r0, [r1, 0x18]
	ldrb r2, [r1, 0x4]
	movs r0, 0xC0
	ands r0, r2
	strb r0, [r1, 0x4]
	ldr r1, [r3]
	movs r0, 0x4
	strb r0, [r1]
	ldr r3, [r3]
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bgt _0812AB90
	movs r0, 0x19
	strb r0, [r3]
	b _0812ABA0
	.pool
_0812AB90:
	ldrb r0, [r3, 0xA]
	cmp r0, 0
	beq _0812ABA0
	movs r0, 0x3
	strb r0, [r3]
	movs r0, 0x4
	bl sub_812DEE4
_0812ABA0:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_812AB60

	thumb_func_start sub_812ABA8
sub_812ABA8: @ 812ABA8
	push {lr}
	bl sub_812E054
	lsls r0, 24
	cmp r0, 0
	beq _0812ABBC
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x4
	strb r0, [r1]
_0812ABBC:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812ABA8

	thumb_func_start sub_812ABC8
sub_812ABC8: @ 812ABC8
	push {lr}
	movs r0, 0
	bl sub_812DEE4
	ldr r2, =gUnknown_0203AB34
	ldr r1, [r2]
	movs r0, 0x5
	strb r0, [r1]
	ldr r2, [r2]
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	ldr r0, =0x0000270e
	cmp r1, r0
	ble _0812ABE8
	movs r0, 0x17
	strb r0, [r2]
_0812ABE8:
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812ABC8

	thumb_func_start sub_812ABF8
sub_812ABF8: @ 812ABF8
	push {r4,r5,lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0812AC1C
	movs r0, 0
	bl sub_812DC80
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x8
	b _0812ACE2
	.pool
_0812AC1C:
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0812AC82
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	movs r1, 0xC
	ldrsh r0, [r2, r1]
	subs r0, 0x3
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	adds r0, r1
	cmp r0, 0
	blt _0812AC7C
	ldrh r4, [r2, 0x12]
	adds r0, r1, 0
	cmp r0, 0x2
	bgt _0812AC5A
_0812AC42:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_812CE7C
	lsls r0, r4, 16
	movs r2, 0x80
	lsls r2, 9
	adds r0, r2
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0812AC42
_0812AC5A:
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	ldrh r0, [r1, 0xC]
	subs r0, 0x3
	ldrh r3, [r1, 0x12]
	adds r0, r3
	strh r0, [r1, 0xC]
	movs r0, 0x3
	strh r0, [r1, 0x12]
	movs r0, 0x9
	strb r0, [r1]
	movs r0, 0x5F
	bl PlaySE
	b _0812ACE4
	.pool
_0812AC7C:
	movs r0, 0x6
	strb r0, [r2]
	b _0812ACE4
_0812AC82:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812ACB2
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0812ACB2
	movs r0, 0x5F
	bl PlaySE
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl sub_812CE7C
	ldr r1, [r4]
	ldrh r0, [r1, 0xC]
	subs r0, 0x1
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
_0812ACB2:
	ldr r0, =gUnknown_0203AB34
	ldr r3, [r0]
	movs r1, 0x12
	ldrsh r2, [r3, r1]
	ldr r4, =gMain
	adds r5, r0, 0
	cmp r2, 0x2
	bgt _0812ACD0
	cmp r2, 0
	beq _0812ACD4
	ldrh r1, [r4, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0812ACD4
_0812ACD0:
	movs r0, 0x9
	strb r0, [r3]
_0812ACD4:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0812ACE4
	ldr r1, [r5]
	movs r0, 0x15
_0812ACE2:
	strb r0, [r1]
_0812ACE4:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812ABF8

	thumb_func_start sub_812ACF4
sub_812ACF4: @ 812ACF4
	push {lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_YouDontHaveThreeCoins
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x7
	strb r0, [r1]
	movs r0, 0
	add sp, 0xC
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812ACF4

	thumb_func_start sub_812AD34
sub_812AD34: @ 812AD34
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0812AD52
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x5
	strb r0, [r1]
_0812AD52:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AD34

	thumb_func_start sub_812AD60
sub_812AD60: @ 812AD60
	push {lr}
	bl sub_812DCB4
	lsls r0, 24
	cmp r0, 0
	beq _0812AD74
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x5
	strb r0, [r1]
_0812AD74:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AD60

	thumb_func_start sub_812AD80
sub_812AD80: @ 812AD80
	push {r4,lr}
	adds r4, r0, 0
	bl sub_812B4EC
	bl sub_812DFDC
	movs r0, 0
	bl sub_812BEA4
	movs r0, 0x1
	bl sub_812BEA4
	movs r0, 0x2
	bl sub_812BEA4
	bl sub_80EEC80
	movs r0, 0
	strh r0, [r4, 0x8]
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	ldrb r1, [r0, 0x4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812ADC4
	bl sub_812D4AC
	ldr r1, [r4]
	movs r0, 0xA
	b _0812ADCE
	.pool
_0812ADC4:
	movs r0, 0x1
	bl sub_812DEE4
	ldr r1, [r4]
	movs r0, 0xB
_0812ADCE:
	strb r0, [r1]
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	movs r1, 0x8
	strh r1, [r0, 0x1A]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _0812ADE6
	bl dp15_jump_random_unknown
	ldr r1, [r4]
	strh r0, [r1, 0x1A]
_0812ADE6:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AD80

	thumb_func_start sub_812ADF4
sub_812ADF4: @ 812ADF4
	push {lr}
	bl sub_812D4CC
	lsls r0, 24
	cmp r0, 0
	beq _0812AE18
	movs r0, 0x1
	bl sub_812DEE4
	ldr r3, =gUnknown_0203AB34
	ldr r2, [r3]
	ldrb r1, [r2, 0x4]
	movs r0, 0xDF
	ands r0, r1
	strb r0, [r2, 0x4]
	ldr r1, [r3]
	movs r0, 0xB
	strb r0, [r1]
_0812AE18:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812ADF4

	thumb_func_start sub_812AE24
sub_812AE24: @ 812AE24
	push {lr}
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x1D
	ble _0812AE40
	bl sub_812B55C
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0xC
	strb r0, [r1]
_0812AE40:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AE24

	thumb_func_start sub_812AE4C
sub_812AE4C: @ 812AE4C
	push {r4,lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0812AE78
	movs r0, 0x18
	bl PlaySE
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	ldrb r0, [r0, 0x18]
	bl sub_812BEDC
	ldr r0, [r4]
	ldrb r0, [r0, 0x18]
	bl sub_812CD40
	ldr r1, [r4]
	movs r0, 0xD
	strb r0, [r1]
_0812AE78:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AE4C

	thumb_func_start sub_812AE88
sub_812AE88: @ 812AE88
	push {r4,lr}
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	ldrb r0, [r0, 0x18]
	bl sub_812BF04
	lsls r0, 24
	cmp r0, 0
	bne _0812AEBC
	ldr r1, [r4]
	ldrh r0, [r1, 0x18]
	adds r0, 0x1
	strh r0, [r1, 0x18]
	movs r0, 0xC
	strb r0, [r1]
	ldr r1, [r4]
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0x2
	ble _0812AEB4
	movs r0, 0xE
	strb r0, [r1]
_0812AEB4:
	movs r0, 0x1
	b _0812AEBE
	.pool
_0812AEBC:
	movs r0, 0
_0812AEBE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812AE88

	thumb_func_start sub_812AEC4
sub_812AEC4: @ 812AEC4
	push {r4,lr}
	ldr r4, =gUnknown_0203AB34
	ldr r2, [r4]
	ldrb r1, [r2, 0x4]
	movs r0, 0xC0
	ands r0, r1
	strb r0, [r2, 0x4]
	bl sub_812B828
	ldr r1, [r4]
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	beq _0812AEEA
	subs r0, 0x1
	strb r0, [r1, 0xA]
	ldr r1, [r4]
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
	strb r0, [r1, 0xB]
_0812AEEA:
	ldr r1, [r4]
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	beq _0812AFCC
	movs r0, 0xF
	strb r0, [r1]
	bl sub_812BABC
	bl sub_812D0B0
	ldr r2, [r4]
	ldrh r0, [r2, 0x10]
	ldrh r1, [r2, 0xE]
	subs r0, r1
	strh r0, [r2, 0x10]
	lsls r0, 16
	cmp r0, 0
	bge _0812AF12
	movs r0, 0
	strh r0, [r2, 0x10]
_0812AF12:
	ldr r0, [r4]
	ldrh r1, [r0, 0x8]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0812AF38
	ldr r0, =0x00000185
	bl PlayFanfare
	movs r0, 0x6
	bl sub_812DEE4
	b _0812AF62
	.pool
_0812AF38:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0812AF54
	ldr r0, =0x00000185
	bl PlayFanfare
	movs r0, 0x5
	bl sub_812DEE4
	b _0812AF62
	.pool
_0812AF54:
	movs r0, 0xC3
	lsls r0, 1
	bl PlayFanfare
	movs r0, 0x2
	bl sub_812DEE4
_0812AF62:
	ldr r2, =gUnknown_0203AB34
	ldr r3, [r2]
	ldrh r1, [r3, 0x8]
	movs r0, 0xE0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0812AFA6
	ldrb r1, [r3, 0x4]
	movs r0, 0x3F
	ands r0, r1
	movs r4, 0
	strb r0, [r3, 0x4]
	ldr r3, [r2]
	ldrh r1, [r3, 0x8]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0812AFA6
	strb r4, [r3, 0xA]
	ldr r0, [r2]
	strb r4, [r0, 0xB]
	ldr r0, [r2]
	strb r4, [r0, 0x3]
	ldr r3, [r2]
	ldrh r1, [r3, 0x8]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0812AFA6
	movs r0, 0x1
	strb r0, [r3, 0x3]
_0812AFA6:
	ldr r3, [r2]
	ldrh r1, [r3, 0x8]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812AFEE
	ldrb r0, [r3, 0x2]
	cmp r0, 0xF
	bhi _0812AFEE
	adds r0, 0x1
	strb r0, [r3, 0x2]
	ldr r0, [r2]
	ldrb r0, [r0, 0x2]
	bl sub_812D1A8
	b _0812AFEE
	.pool
_0812AFCC:
	movs r0, 0x3
	bl sub_812DEE4
	ldr r1, [r4]
	movs r0, 0x14
	strb r0, [r1]
	ldr r1, [r4]
	ldrh r0, [r1, 0x12]
	ldrh r2, [r1, 0x10]
	adds r0, r2
	strh r0, [r1, 0x10]
	lsls r0, 16
	asrs r0, 16
	ldr r2, =0x0000270f
	cmp r0, r2
	ble _0812AFEE
	strh r2, [r1, 0x10]
_0812AFEE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AEC4

	thumb_func_start sub_812AFFC
sub_812AFFC: @ 812AFFC
	push {lr}
	bl sub_812BADC
	lsls r0, 24
	cmp r0, 0
	beq _0812B010
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x10
	strb r0, [r1]
_0812B010:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812AFFC

	thumb_func_start sub_812B01C
sub_812B01C: @ 812B01C
	push {r4,lr}
	bl sub_812D0E0
	lsls r0, 24
	cmp r0, 0
	beq _0812B088
	ldr r4, =gUnknown_0203AB34
	ldr r1, [r4]
	movs r0, 0x13
	strb r0, [r1]
	ldr r0, [r4]
	ldrh r1, [r0, 0x8]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _0812B044
	movs r0, 0x1C
	bl IncrementGameStat
_0812B044:
	ldr r2, [r4]
	ldrh r1, [r2, 0x8]
	movs r3, 0x4
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0812B05A
	movs r0, 0
	strh r0, [r2, 0x18]
	movs r0, 0x9
	strb r0, [r2]
_0812B05A:
	ldr r2, [r4]
	ldrh r1, [r2, 0x8]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812B06A
	movs r0, 0x11
	strb r0, [r2]
_0812B06A:
	ldr r1, [r4]
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	beq _0812B088
	ldrh r1, [r1, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0812B088
	movs r0, 0x4
	bl sub_812DEE4
	ldr r1, [r4]
	movs r0, 0x12
	strb r0, [r1]
_0812B088:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B01C

	thumb_func_start sub_812B094
sub_812B094: @ 812B094
	push {r4,lr}
	bl sub_812D20C
	lsls r0, 24
	cmp r0, 0
	bne _0812B0CC
	ldr r4, =gUnknown_0203AB34
	ldr r1, [r4]
	movs r0, 0x13
	strb r0, [r1]
	ldr r2, [r4]
	ldrh r1, [r2, 0x8]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0812B0CC
	movs r0, 0x9
	strb r0, [r2]
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _0812B0CC
	movs r0, 0x4
	bl sub_812DEE4
	ldr r1, [r4]
	movs r0, 0x12
	strb r0, [r1]
_0812B0CC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B094

	thumb_func_start sub_812B0D8
sub_812B0D8: @ 812B0D8
	push {lr}
	bl sub_812E054
	lsls r0, 24
	cmp r0, 0
	beq _0812B0FC
	ldr r2, =gUnknown_0203AB34
	ldr r1, [r2]
	movs r0, 0x13
	strb r0, [r1]
	ldr r2, [r2]
	ldrh r1, [r2, 0x8]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0812B0FC
	movs r0, 0x9
	strb r0, [r2]
_0812B0FC:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B0D8

	thumb_func_start sub_812B108
sub_812B108: @ 812B108
	push {lr}
	movs r0, 0
	bl sub_812CEB8
	movs r0, 0x1
	bl sub_812CEB8
	movs r0, 0x2
	bl sub_812CEB8
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B108

	thumb_func_start sub_812B130
sub_812B130: @ 812B130
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x40
	ble _0812B14E
	movs r0, 0
	strh r0, [r1, 0xA]
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x13
	strb r0, [r1]
_0812B14E:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B130

	thumb_func_start sub_812B158
sub_812B158: @ 812B158
	push {lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_QuitTheGame
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r2, 0x85
	lsls r2, 2
	movs r3, 0xC0
	lsls r3, 1
	movs r0, 0xE
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0x15
	movs r1, 0x7
	bl sub_80323CC
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x16
	strb r0, [r1]
	movs r0, 0
	add sp, 0xC
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B158

	thumb_func_start sub_812B1B0
sub_812B1B0: @ 812B1B0
	push {lr}
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	bne _0812B1EC
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	movs r0, 0
	bl sub_812CEB8
	movs r0, 0x1
	bl sub_812CEB8
	movs r0, 0x2
	bl sub_812CEB8
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	ldrh r0, [r1, 0x12]
	ldrh r2, [r1, 0xC]
	adds r0, r2
	strh r0, [r1, 0xC]
	movs r0, 0x1B
	b _0812B206
	.pool
_0812B1EC:
	cmp r1, 0x1
	beq _0812B1F8
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0812B208
_0812B1F8:
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x5
_0812B206:
	strb r0, [r1]
_0812B208:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B1B0

	thumb_func_start sub_812B214
sub_812B214: @ 812B214
	push {lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_YouveGot9999Coins
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x18
	strb r0, [r1]
	movs r0, 0
	add sp, 0xC
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B214

	thumb_func_start sub_812B254
sub_812B254: @ 812B254
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0812B272
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x5
	strb r0, [r1]
_0812B272:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B254

	thumb_func_start sub_812B280
sub_812B280: @ 812B280
	push {lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl NewMenuHelpers_DrawDialogueFrame
	ldr r2, =gText_YouveRunOutOfCoins
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x1A
	strb r0, [r1]
	movs r0, 0
	add sp, 0xC
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B280

	thumb_func_start sub_812B2C0
sub_812B2C0: @ 812B2C0
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0812B2DE
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x1B
	strb r0, [r1]
_0812B2DE:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B2C0

	thumb_func_start sub_812B2EC
sub_812B2EC: @ 812B2EC
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	ldrh r0, [r0, 0xC]
	bl SetCoins
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	bl sub_80EDD78
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B2EC

	thumb_func_start sub_812B32C
sub_812B32C: @ 812B32C
	push {r4-r6,lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0812B340
	b _0812B470
_0812B340:
	ldr r6, =gUnknown_0203AB34
	ldr r0, [r6]
	ldr r0, [r0, 0x64]
	bl SetMainCallback2
	ldr r4, =gUnknown_0203AAF4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAF8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAFC
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB00
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB04
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB08
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB0C
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB10
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB14
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB18
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB1C
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB20
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB24
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB28
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAE4
	ldr r0, [r4]
	cmp r0, 0
	beq _0812B3E4
	bl Free
	str r5, [r4]
_0812B3E4:
	ldr r4, =gUnknown_0203AAE8
	ldr r0, [r4]
	cmp r0, 0
	beq _0812B3F2
	bl Free
	str r5, [r4]
_0812B3F2:
	ldr r4, =gUnknown_0203AAEC
	ldr r0, [r4]
	cmp r0, 0
	beq _0812B400
	bl Free
	str r5, [r4]
_0812B400:
	ldr r4, =gUnknown_0203AAF0
	ldr r0, [r4]
	cmp r0, 0
	beq _0812B40E
	bl Free
	str r5, [r4]
_0812B40E:
	ldr r4, =gUnknown_0203AAC8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AACC
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAD0
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAD4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAD8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AADC
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AAE0
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB2C
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0203AB30
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, [r6]
	bl Free
	str r5, [r6]
_0812B470:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B32C

	thumb_func_start sub_812B4EC
sub_812B4EC: @ 812B4EC
	push {r4,lr}
	ldr r4, =gUnknown_0203AB34
	ldr r1, [r4]
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	bne _0812B54A
	ldrb r1, [r1, 0x4]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	bne _0812B54A
	bl sub_812B5B0
	lsls r0, 24
	cmp r0, 0
	beq _0812B52C
	bl sub_812B5EC
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	beq _0812B52C
	ldr r2, [r4]
	ldr r1, =gUnknown_085A77FE
	lsls r0, r3, 1
	adds r0, r1
	ldrb r1, [r0]
	ldrb r0, [r2, 0x4]
	orrs r0, r1
	strb r0, [r2, 0x4]
	cmp r3, 0x1
	bne _0812B54A
_0812B52C:
	bl sub_812B634
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x5
	beq _0812B54A
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldr r1, =gUnknown_085A7804
	lsls r0, r3, 1
	adds r0, r1
	ldrb r1, [r0]
	ldrb r0, [r2, 0x4]
	orrs r0, r1
	strb r0, [r2, 0x4]
_0812B54A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B4EC

	thumb_func_start sub_812B55C
sub_812B55C: @ 812B55C
	push {lr}
	ldr r2, =gUnknown_0203AB34
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x6]
	ldr r2, [r2]
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	beq _0812B572
	movs r0, 0x1
	strb r0, [r2, 0x6]
_0812B572:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B55C

	thumb_func_start sub_812B57C
sub_812B57C: @ 812B57C
	push {r4,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0
	movs r3, 0x1
	ldr r4, =gUnknown_085A77F6
_0812B588:
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _0812B59C
	adds r0, r2, r4
	ldrb r0, [r0]
	b _0812B5AA
	.pool
_0812B59C:
	lsrs r1, 1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _0812B588
	movs r0, 0
_0812B5AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812B57C

	thumb_func_start sub_812B5B0
sub_812B5B0: @ 812B5B0
	push {r4,lr}
	bl Random
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_085A76C0
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	movs r3, 0x12
	ldrsh r2, [r1, r3]
	ldrb r3, [r1, 0x1]
	lsls r1, r3, 1
	adds r1, r3
	subs r1, 0x1
	adds r2, r1
	adds r2, r4
	ldrb r1, [r2]
	cmp r1, r0
	bhi _0812B5E4
	movs r0, 0
	b _0812B5E6
	.pool
_0812B5E4:
	movs r0, 0x1
_0812B5E6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812B5B0

	thumb_func_start sub_812B5EC
sub_812B5EC: @ 812B5EC
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_085A76D2
_0812B5F2:
	bl Random
	movs r2, 0xFF
	ldr r1, =gUnknown_0203AB34
	ldr r3, [r1]
	lsls r1, r5, 16
	asrs r4, r1, 16
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 1
	ldrb r3, [r3, 0x1]
	adds r1, r3
	adds r1, r6
	ldrb r1, [r1]
	ands r2, r0
	cmp r1, r2
	bgt _0812B620
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0812B5F2
_0812B620:
	lsls r0, r5, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B5EC

	thumb_func_start sub_812B634
sub_812B634: @ 812B634
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, =gUnknown_085A76E4
	mov r8, r0
	movs r7, 0x80
	lsls r7, 17
_0812B644:
	bl Random
	movs r5, 0xFF
	ands r5, r0
	ldr r0, =gUnknown_0203AB34
	ldr r4, [r0]
	lsls r2, r6, 16
	asrs r1, r2, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	ldrb r3, [r4, 0x1]
	adds r0, r3
	add r0, r8
	ldrb r3, [r0]
	cmp r1, 0
	bne _0812B680
	ldrb r0, [r4, 0x3]
	cmp r0, 0x1
	bne _0812B680
	adds r3, 0xA
	asrs r0, r7, 16
	cmp r3, r0
	ble _0812B69E
	adds r3, r0, 0
	b _0812B69E
	.pool
_0812B680:
	asrs r0, r2, 16
	cmp r0, 0x4
	bne _0812B69E
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0x1
	bne _0812B69E
	lsls r0, r3, 16
	ldr r1, =0xfff60000
	adds r0, r1
	lsrs r3, r0, 16
	cmp r0, 0
	bge _0812B69E
	movs r3, 0
_0812B69E:
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, r5
	bgt _0812B6B4
	movs r3, 0x80
	lsls r3, 9
	adds r0, r2, r3
	lsrs r6, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812B644
_0812B6B4:
	lsls r0, r6, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B634

	thumb_func_start sub_812B6CC
sub_812B6CC: @ 812B6CC
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldrb r0, [r2, 0x3]
	cmp r0, 0
	beq _0812B6E8
	ldr r0, =gUnknown_085A7768
	b _0812B6EA
	.pool
_0812B6E8:
	ldr r0, =gUnknown_085A7702
_0812B6EA:
	lsls r1, r3, 4
	adds r1, r3
	ldrb r2, [r2, 0x2]
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812B6CC

	thumb_func_start sub_812B700
sub_812B700: @ 812B700
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x5]
	bl Random
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	bl sub_812B6CC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _0812B754
	movs r6, 0x5
	b _0812B72E
	.pool
_0812B728:
	subs r0, r5, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_0812B72E:
	lsls r0, r6, 16
	asrs r5, r0, 16
	cmp r5, 0
	ble _0812B74E
	bl Random
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_812B6CC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcs _0812B728
_0812B74E:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	strb r6, [r0, 0x5]
_0812B754:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B700

	thumb_func_start sub_812B760
sub_812B760: @ 812B760
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl Random
	movs r1, 0xFF
	ands r1, r0
	ldr r0, =gUnknown_085A77CE
	lsls r4, 1
	adds r4, r0
	ldrh r4, [r4]
	cmp r1, r4
	bcc _0812B784
	movs r0, 0
	b _0812B786
	.pool
_0812B784:
	movs r0, 0x1
_0812B786:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812B760

	thumb_func_start dp15_jump_random_unknown
dp15_jump_random_unknown: @ 812B78C
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	ldr r0, =0x0000012b
	cmp r1, r0
	ble _0812B7AC
	movs r4, 0x4
	b _0812B7C2
	.pool
_0812B7AC:
	cmp r1, 0xF9
	ble _0812B7B4
	movs r4, 0x3
	b _0812B7C2
_0812B7B4:
	cmp r1, 0xC7
	ble _0812B7BC
	movs r4, 0x2
	b _0812B7C2
_0812B7BC:
	cmp r1, 0x95
	ble _0812B7C2
	movs r4, 0x1
_0812B7C2:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r5, =gUnknown_085A77D8
	lsls r4, 2
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0812B7E8
	movs r0, 0x4
	b _0812B822
	.pool
_0812B7E8:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	adds r2, r5, 0x2
	adds r2, r4, r2
	ldr r3, =gUnknown_085A77EC
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	ldrb r1, [r1, 0xB]
	lsls r1, 1
	adds r1, r3
	ldrb r1, [r1]
	ldrb r2, [r2]
	adds r1, r2
	lsls r1, 24
	cmp r0, r1
	bcc _0812B820
	movs r0, 0x8
	b _0812B822
	.pool
_0812B820:
	movs r0, 0x2
_0812B822:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end dp15_jump_random_unknown

	thumb_func_start sub_812B828
sub_812B828: @ 812B828
	push {r4,lr}
	ldr r4, =gUnknown_0203AB34
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0x8]
	bl sub_812B85C
	ldr r0, [r4]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	ble _0812B844
	bl sub_812B8D0
_0812B844:
	ldr r0, [r4]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	ble _0812B852
	bl sub_812B9A0
_0812B852:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B828

	thumb_func_start sub_812B85C
sub_812B85C: @ 812B85C
	push {r4,r5,lr}
	movs r0, 0
	movs r1, 0x2
	bl sub_812BC44
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x1
	movs r1, 0x2
	bl sub_812BC44
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	movs r1, 0x2
	bl sub_812BC44
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_812BA6C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	beq _0812B8BC
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldr r0, =gUnknown_085A7828
	lsls r1, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r3, [r2, 0xE]
	adds r0, r3
	strh r0, [r2, 0xE]
	ldr r0, =gUnknown_085A7816
	adds r1, r0
	ldrh r0, [r2, 0x8]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2, 0x8]
	movs r0, 0
	bl sub_812CF34
_0812B8BC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B85C

	thumb_func_start sub_812B8D0
sub_812B8D0: @ 812B8D0
	push {r4,r5,lr}
	movs r0, 0
	movs r1, 0x1
	bl sub_812BC44
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x1
	movs r1, 0x1
	bl sub_812BC44
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	movs r1, 0x1
	bl sub_812BC44
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_812BA6C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	beq _0812B930
	cmp r1, 0
	bne _0812B90C
	movs r1, 0x1
_0812B90C:
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldr r0, =gUnknown_085A7828
	lsls r1, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r3, [r2, 0xE]
	adds r0, r3
	strh r0, [r2, 0xE]
	ldr r0, =gUnknown_085A7816
	adds r1, r0
	ldrh r0, [r2, 0x8]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2, 0x8]
	movs r0, 0x1
	bl sub_812CF34
_0812B930:
	movs r0, 0
	movs r1, 0x3
	bl sub_812BC44
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x1
	movs r1, 0x3
	bl sub_812BC44
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	movs r1, 0x3
	bl sub_812BC44
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_812BA6C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	beq _0812B98E
	cmp r1, 0
	bne _0812B96A
	movs r1, 0x1
_0812B96A:
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldr r0, =gUnknown_085A7828
	lsls r1, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r3, [r2, 0xE]
	adds r0, r3
	strh r0, [r2, 0xE]
	ldr r0, =gUnknown_085A7816
	adds r1, r0
	ldrh r0, [r2, 0x8]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2, 0x8]
	movs r0, 0x2
	bl sub_812CF34
_0812B98E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B8D0

	thumb_func_start sub_812B9A0
sub_812B9A0: @ 812B9A0
	push {r4,r5,lr}
	movs r0, 0
	movs r1, 0x1
	bl sub_812BC44
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x1
	movs r1, 0x2
	bl sub_812BC44
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	movs r1, 0x3
	bl sub_812BC44
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_812BA6C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	beq _0812B9FE
	cmp r1, 0
	beq _0812B9F8
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldr r0, =gUnknown_085A7828
	lsls r1, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r3, [r2, 0xE]
	adds r0, r3
	strh r0, [r2, 0xE]
	ldr r0, =gUnknown_085A7816
	adds r1, r0
	ldrh r0, [r2, 0x8]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2, 0x8]
_0812B9F8:
	movs r0, 0x3
	bl sub_812CF34
_0812B9FE:
	movs r0, 0
	movs r1, 0x3
	bl sub_812BC44
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x1
	movs r1, 0x2
	bl sub_812BC44
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	movs r1, 0x1
	bl sub_812BC44
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_812BA6C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	beq _0812BA5A
	cmp r1, 0
	beq _0812BA54
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldr r0, =gUnknown_085A7828
	lsls r1, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r3, [r2, 0xE]
	adds r0, r3
	strh r0, [r2, 0xE]
	ldr r0, =gUnknown_085A7816
	adds r1, r0
	ldrh r0, [r2, 0x8]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2, 0x8]
_0812BA54:
	movs r0, 0x4
	bl sub_812CF34
_0812BA5A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812B9A0

	thumb_func_start sub_812BA6C
sub_812BA6C: @ 812BA6C
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	cmp r3, r1
	bne _0812BA90
	cmp r3, r2
	bne _0812BA90
	ldr r0, =gUnknown_085A780E
	adds r0, r3, r0
	ldrb r0, [r0]
	b _0812BAB6
	.pool
_0812BA90:
	cmp r3, 0
	bne _0812BA9C
	cmp r1, 0
	bne _0812BA9C
	cmp r2, 0x1
	beq _0812BAA8
_0812BA9C:
	cmp r3, 0x1
	bne _0812BAAC
	cmp r1, 0x1
	bne _0812BAAC
	cmp r2, 0
	bne _0812BAAC
_0812BAA8:
	movs r0, 0x6
	b _0812BAB6
_0812BAAC:
	cmp r3, 0x4
	beq _0812BAB4
	movs r0, 0x9
	b _0812BAB6
_0812BAB4:
	movs r0, 0
_0812BAB6:
	pop {r1}
	bx r1
	thumb_func_end sub_812BA6C

	thumb_func_start sub_812BABC
sub_812BABC: @ 812BABC
	push {r4,lr}
	ldr r4, =sub_812BAFC
	adds r0, r4, 0
	movs r1, 0x4
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BABC

	thumb_func_start sub_812BADC
sub_812BADC: @ 812BADC
	push {lr}
	ldr r0, =sub_812BAFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0812BAF4
	movs r0, 0
	b _0812BAF6
	.pool
_0812BAF4:
	movs r0, 0x1
_0812BAF6:
	pop {r1}
	bx r1
	thumb_func_end sub_812BADC

	thumb_func_start sub_812BAFC
sub_812BAFC: @ 812BAFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085A74C4
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0812BB0E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0812BB0E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BAFC

	thumb_func_start sub_812BB34
sub_812BB34: @ 812BB34
	push {r4,lr}
	adds r4, r0, 0
	bl sub_812CF6C
	lsls r0, 24
	cmp r0, 0
	beq _0812BB60
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0812BB60
	movs r0, 0x2
	strh r0, [r4, 0x8]
	movs r0, 0x1
	b _0812BB62
	.pool
_0812BB60:
	movs r0, 0
_0812BB62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812BB34

	thumb_func_start sub_812BB68
sub_812BB68: @ 812BB68
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0812BBBC
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _0812BB8E
	movs r0, 0x15
	bl PlaySE
_0812BB8E:
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldrh r0, [r2, 0xE]
	subs r0, 0x1
	strh r0, [r2, 0xE]
	ldrh r3, [r2, 0xC]
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	ldr r0, =0x0000270e
	cmp r1, r0
	bgt _0812BBA8
	adds r0, r3, 0x1
	strh r0, [r2, 0xC]
_0812BBA8:
	movs r0, 0x8
	strh r0, [r4, 0xA]
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0812BBBC
	movs r0, 0x4
	strh r0, [r4, 0xA]
_0812BBBC:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _0812BBF6
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0812BBF6
	movs r0, 0x15
	bl PlaySE
	ldr r1, =gUnknown_0203AB34
	ldr r2, [r1]
	ldrh r0, [r2, 0xE]
	ldrh r3, [r2, 0xC]
	adds r0, r3
	strh r0, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	ldr r3, =0x0000270f
	cmp r0, r3
	ble _0812BBF0
	strh r3, [r2, 0xC]
_0812BBF0:
	ldr r1, [r1]
	movs r0, 0
	strh r0, [r1, 0xE]
_0812BBF6:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0812BC08
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0812BC08:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BB68

	thumb_func_start sub_812BC20
sub_812BC20: @ 812BC20
	push {lr}
	bl sub_812CFB8
	lsls r0, 24
	cmp r0, 0
	beq _0812BC3A
	ldr r0, =sub_812BAFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0812BC3A:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BC20

	thumb_func_start sub_812BC44
sub_812BC44: @ 812BC44
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	lsls r2, r4, 1
	adds r0, 0x28
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r1, 16
	asrs r1, 16
	adds r0, r1
	movs r1, 0x15
	bl __modsi3
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0812BC76
	adds r0, 0x15
	lsls r0, 16
	lsrs r1, r0, 16
_0812BC76:
	ldr r2, =gUnknown_085A766E
	lsls r1, 16
	asrs r1, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
	adds r0, r4
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BC44

	thumb_func_start sub_812BC98
sub_812BC98: @ 812BC98
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r6, 0
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x1C
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	beq _0812BCC2
	ldr r6, =0x0000ffff
_0812BCC2:
	lsls r1, r5, 16
	asrs r1, 16
	lsls r0, r6, 16
	asrs r0, 16
	adds r1, r0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_812BC44
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BC98

	thumb_func_start sub_812BCE8
sub_812BCE8: @ 812BCE8
	push {lr}
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	movs r2, 0x16
	ldrsh r1, [r1, r2]
	lsls r0, 16
	asrs r0, 16
	adds r1, r0
	adds r0, r1, 0
	movs r1, 0x6
	bl __modsi3
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0812BD10
	adds r0, 0x6
	lsls r0, 16
	lsrs r1, r0, 16
_0812BD10:
	ldr r0, =gUnknown_085A76AD
	lsls r1, 16
	asrs r1, 16
	adds r1, r0
	ldrb r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BCE8

	thumb_func_start sub_812BD28
sub_812BD28: @ 812BD28
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r5, 24
	ldr r0, =gUnknown_0203AB34
	ldr r6, [r0]
	lsrs r5, 23
	adds r4, r6, 0
	adds r4, 0x1C
	adds r4, r5
	lsls r1, 16
	asrs r1, 16
	ldrh r0, [r4]
	adds r1, r0
	strh r1, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0xFC
	lsls r1, 1
	bl __modsi3
	strh r0, [r4]
	adds r6, 0x28
	adds r6, r5
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x18
	bl __divsi3
	movs r1, 0x15
	subs r1, r0
	strh r1, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BD28

	thumb_func_start sub_812BD70
sub_812BD70: @ 812BD70
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r7, =gUnknown_0203AB34
	ldr r0, [r7]
	lsls r6, r5, 1
	adds r0, 0x1C
	adds r0, r6
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 16
	asrs r1, r2, 16
	cmp r1, 0
	beq _0812BDC4
	lsls r0, r4, 16
	asrs r0, 16
	cmp r1, r0
	bge _0812BDA6
	lsrs r4, r2, 16
_0812BDA6:
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r5, 0
	bl sub_812BD28
	ldr r0, [r7]
	adds r0, 0x1C
	adds r0, r6
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
_0812BDC4:
	lsls r0, 16
	asrs r0, 16
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BD70

	thumb_func_start sub_812BDD4
sub_812BDD4: @ 812BDD4
	push {r4,lr}
	ldr r1, =gUnknown_0203AB34
	ldr r4, [r1]
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r4, 0x14]
	adds r0, r1
	strh r0, [r4, 0x14]
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	movs r1, 0x78
	bl __modsi3
	strh r0, [r4, 0x14]
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	movs r1, 0x14
	bl __divsi3
	movs r1, 0x6
	subs r1, r0
	strh r1, [r4, 0x16]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BDD4

	thumb_func_start sub_812BE0C
sub_812BE0C: @ 812BE0C
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r5, =gUnknown_0203AB34
	ldr r0, [r5]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	movs r1, 0x14
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 16
	asrs r1, r2, 16
	cmp r1, 0
	beq _0812BE4E
	lsls r0, r4, 16
	asrs r0, 16
	cmp r1, r0
	bge _0812BE36
	lsrs r4, r2, 16
_0812BE36:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_812BDD4
	ldr r0, [r5]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	movs r1, 0x14
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
_0812BE4E:
	lsls r0, 16
	asrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BE0C

	thumb_func_start sub_812BE5C
sub_812BE5C: @ 812BE5C
	push {r4-r6,lr}
	movs r4, 0
	ldr r5, =sub_812BF2C
	ldr r6, =gTasks
_0812BE64:
	adds r0, r5, 0
	movs r1, 0x2
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r6
	strh r4, [r1, 0x26]
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x3A
	adds r1, r4
	strb r0, [r1]
	bl _call_via_r5
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _0812BE64
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BE5C

	thumb_func_start sub_812BEA4
sub_812BEA4: @ 812BEA4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	ldr r1, =gUnknown_0203AB34
	ldr r2, [r1]
	adds r2, 0x3A
	adds r2, r0
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r3, 0x1
	strh r3, [r0, 0x8]
	ldrb r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	strh r3, [r0, 0x24]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BEA4

	thumb_func_start sub_812BEDC
sub_812BEDC: @ 812BEDC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x3A
	adds r1, r0
	ldrb r1, [r1]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x2
	strh r1, [r0, 0x8]
	bx lr
	.pool
	thumb_func_end sub_812BEDC

	thumb_func_start sub_812BF04
sub_812BF04: @ 812BF04
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x3A
	adds r1, r0
	ldrb r1, [r1]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0x24]
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_812BF04

	thumb_func_start sub_812BF2C
sub_812BF2C: @ 812BF2C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085A74D0
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0812BF3E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0812BF3E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812BF2C

	thumb_func_start sub_812BF64
sub_812BF64: @ 812BF64
	movs r0, 0
	bx lr
	thumb_func_end sub_812BF64

	thumb_func_start sub_812BF68
sub_812BF68: @ 812BF68
	push {lr}
	ldrh r0, [r0, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	movs r2, 0x1A
	ldrsh r1, [r1, r2]
	bl sub_812BD28
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BF68

	thumb_func_start sub_812BF88
sub_812BF88: @ 812BF88
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_0203AB34
	ldr r3, [r0]
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x34
	adds r0, r1
	strh r2, [r0]
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x2E
	adds r0, r1
	strh r2, [r0]
	ldrb r0, [r3, 0xA]
	cmp r0, 0
	bne _0812BFF4
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	beq _0812BFDC
	ldrb r0, [r3, 0x6]
	cmp r0, 0
	beq _0812BFDC
	ldr r1, =gUnknown_085A74E4
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	cmp r0, 0
	bne _0812BFF4
_0812BFDC:
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x6]
	ldr r1, =gUnknown_085A74F0
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0812BFF4:
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r1, 0x2E
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r4, 0xA]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812BF88

	thumb_func_start sub_812C01C
sub_812C01C: @ 812C01C
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r1, =gUnknown_085A74FC
	mov r0, sp
	movs r2, 0xA
	bl memcpy
	ldr r7, =gUnknown_0203AB34
	ldr r5, [r7]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	lsls r6, r0, 1
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r6
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0x18
	bl __modsi3
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r0, 0
	beq _0812C068
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r6, 0x1A
	ldrsh r1, [r5, r6]
	bl sub_812BD70
	b _0812C0A0
	.pool
_0812C068:
	adds r0, r5, 0
	adds r0, 0x2E
	adds r1, r0, r6
	ldrh r3, [r1]
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0
	beq _0812C0A4
	subs r0, r3, 0x1
	strh r0, [r1]
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x1A
	ldrsh r1, [r5, r2]
	bl sub_812BD28
	ldr r1, [r7]
	movs r6, 0x26
	ldrsh r0, [r4, r6]
	lsls r0, 1
	adds r1, 0x1C
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r1, 0x18
	bl __modsi3
_0812C0A0:
	lsls r0, 16
	lsrs r2, r0, 16
_0812C0A4:
	cmp r2, 0
	bne _0812C0D2
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r6, 0x26
	ldrsh r0, [r4, r6]
	lsls r0, 1
	adds r1, 0x2E
	adds r1, r0
	movs r0, 0
	ldrsh r1, [r1, r0]
	cmp r1, 0
	bne _0812C0D2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0xA]
	strh r1, [r4, 0xC]
_0812C0D2:
	movs r0, 0
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812C01C

	thumb_func_start sub_812C0E0
sub_812C0E0: @ 812C0E0
	push {r4,lr}
	adds r2, r0, 0
	ldr r4, =gUnknown_0203AB34
	ldr r1, [r4]
	movs r3, 0x26
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r1, 0x22
	adds r1, r0
	ldrh r0, [r2, 0xA]
	strh r0, [r1]
	ldrh r0, [r2, 0xA]
	negs r3, r0
	strh r3, [r2, 0xA]
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0812C110
	lsls r0, r3, 16
	asrs r0, 17
	strh r0, [r2, 0xA]
_0812C110:
	movs r0, 0xA
	ldrsh r3, [r2, r0]
	cmp r3, 0
	bne _0812C12A
	strh r3, [r2, 0x8]
	strh r3, [r2, 0x24]
	ldr r1, [r4]
	movs r4, 0x26
	ldrsh r0, [r2, r4]
	lsls r0, 1
	adds r1, 0x22
	adds r1, r0
	strh r3, [r1]
_0812C12A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812C0E0

	thumb_func_start sub_812C138
sub_812C138: @ 812C138
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl sub_812B57C
	lsls r0, 24
	lsrs r3, r0, 24
	adds r5, r3, 0
	ldr r4, [r4]
	ldrb r1, [r4, 0x4]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0812C15A
	movs r5, 0
	movs r3, 0x1
_0812C15A:
	ldr r1, =gUnknown_085A7508
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r3, 0
	bl _call_via_r2
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812C138

	thumb_func_start sub_812C184
sub_812C184: @ 812C184
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 16
	asrs r3, 16
	movs r0, 0
	adds r1, r3, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, r4
	beq _0812C1AC
	cmp r0, r5
	bne _0812C1BC
_0812C1AC:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	strb r1, [r0, 0x7]
	movs r0, 0x1
	b _0812C1BE
	.pool
_0812C1BC:
	movs r0, 0
_0812C1BE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_812C184

	thumb_func_start sub_812C1C4
sub_812C1C4: @ 812C1C4
	push {r4,lr}
	movs r1, 0x1
	lsls r0, 16
	asrs r4, r0, 16
	subs r1, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _0812C20C
	movs r1, 0x2
	subs r1, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _0812C20C
	movs r1, 0x3
	subs r1, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _0812C210
_0812C20C:
	movs r0, 0x1
	b _0812C212
_0812C210:
	movs r0, 0
_0812C212:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812C1C4

	thumb_func_start sub_812C218
sub_812C218: @ 812C218
	push {lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	ldrb r1, [r0, 0x4]
	movs r0, 0xC2
	ands r0, r1
	cmp r0, 0
	bne _0812C230
	movs r0, 0
	b _0812C232
	.pool
_0812C230:
	movs r0, 0x1
_0812C232:
	pop {r1}
	bx r1
	thumb_func_end sub_812C218

	thumb_func_start sub_812C238
sub_812C238: @ 812C238
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	movs r5, 0
	movs r0, 0x2
	mov r8, r0
_0812C24C:
	lsls r0, r5, 16
	asrs r4, r0, 16
	mov r1, r8
	subs r0, r1, r4
	lsls r0, 16
	asrs r0, 16
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_812C184
	lsls r0, 24
	cmp r0, 0
	beq _0812C278
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x34]
	strh r5, [r1, 0x2E]
	movs r0, 0x1
	b _0812C286
	.pool
_0812C278:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C24C
	movs r0, 0
_0812C286:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812C238

	thumb_func_start sub_812C290
sub_812C290: @ 812C290
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	bl sub_812C218
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0812C2BE
	movs r0, 0
	bl sub_812C1C4
	lsls r0, 24
	cmp r0, 0
	bne _0812C2F4
_0812C2BE:
	movs r7, 0x1
	movs r6, 0
_0812C2C2:
	lsls r0, r7, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	mov r1, r9
	mov r2, r8
	bl sub_812C184
	lsls r0, 24
	cmp r0, 0
	beq _0812C2E8
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	strh r7, [r0, 0x34]
	strh r6, [r0, 0x2E]
	movs r0, 0x1
	b _0812C390
	.pool
_0812C2E8:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0812C2C2
_0812C2F4:
	movs r7, 0x1
	adds r6, r5, 0
	ldr r0, =gUnknown_0203AB34
	mov r10, r0
_0812C2FC:
	lsls r5, r7, 16
	cmp r6, 0
	bne _0812C30E
	asrs r0, r5, 16
	bl sub_812C1C4
	lsls r0, 24
	cmp r0, 0
	bne _0812C380
_0812C30E:
	movs r0, 0x1
	asrs r4, r5, 16
	subs r0, r4
	lsls r0, 16
	asrs r0, 16
	mov r1, r9
	mov r2, r8
	bl sub_812C184
	lsls r0, 24
	cmp r0, 0
	beq _0812C380
	cmp r4, 0x1
	bne _0812C34C
	cmp r6, 0
	bne _0812C33A
	movs r0, 0x3
	bl sub_812C1C4
	lsls r0, 24
	cmp r0, 0
	bne _0812C34C
_0812C33A:
	mov r0, r10
	ldr r1, [r0]
	movs r0, 0x3
	strh r0, [r1, 0x34]
	strh r0, [r1, 0x2E]
	movs r0, 0x1
	b _0812C390
	.pool
_0812C34C:
	asrs r0, r5, 16
	cmp r0, 0x3
	bgt _0812C374
	adds r4, r0, 0x1
	cmp r6, 0
	bne _0812C366
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_812C1C4
	lsls r0, 24
	cmp r0, 0
	bne _0812C374
_0812C366:
	mov r0, r10
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x34]
	strh r4, [r1, 0x2E]
	movs r0, 0x1
	b _0812C390
_0812C374:
	mov r0, r10
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x34]
	strh r7, [r1, 0x2E]
	b _0812C390
_0812C380:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r5, r1
	lsrs r7, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C2FC
	movs r0, 0
_0812C390:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812C290

	thumb_func_start sub_812C3A0
sub_812C3A0: @ 812C3A0
	push {lr}
	ldr r1, =gUnknown_085A7514
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r2, 0x12
	ldrsh r0, [r0, r2]
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812C3A0

	thumb_func_start sub_812C3C8
sub_812C3C8: @ 812C3C8
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r5, 0
	ldrh r7, [r0, 0x34]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
_0812C3D6:
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r6, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r1, 0x7]
	cmp r0, r2
	bne _0812C400
	strh r7, [r1, 0x36]
	strh r5, [r1, 0x30]
	movs r0, 0x1
	b _0812C40E
	.pool
_0812C400:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C3D6
	movs r0, 0
_0812C40E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812C3C8

	thumb_func_start sub_812C414
sub_812C414: @ 812C414
	push {r4-r6,lr}
	bl sub_812C3C8
	lsls r0, 24
	cmp r0, 0
	beq _0812C476
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0x2
	beq _0812C472
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	ble _0812C472
	cmp r0, 0x4
	beq _0812C472
	movs r5, 0
	movs r6, 0x2
_0812C43C:
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r6, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r1, 0x7]
	cmp r0, r2
	beq _0812C46C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C43C
	b _0812C472
	.pool
_0812C46C:
	movs r0, 0x2
	strh r0, [r1, 0x36]
	strh r5, [r1, 0x30]
_0812C472:
	movs r0, 0x1
	b _0812C4B2
_0812C476:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r1, 0x34
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	beq _0812C4B0
	movs r5, 0
	movs r6, 0x2
_0812C486:
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r6, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r1, 0x7]
	cmp r0, r2
	beq _0812C46C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C486
_0812C4B0:
	movs r0, 0
_0812C4B2:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812C414

	thumb_func_start sub_812C4BC
sub_812C4BC: @ 812C4BC
	push {r4,lr}
	ldr r2, =gUnknown_0203AB34
	ldr r0, [r2]
	ldrb r3, [r0, 0x7]
	adds r4, r3, 0
	ldrb r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0812C4D8
	movs r3, 0
	cmp r4, 0
	bne _0812C4D8
	movs r3, 0x1
_0812C4D8:
	ldr r1, =gUnknown_085A7520
	ldr r0, [r2]
	movs r2, 0x12
	ldrsh r0, [r0, r2]
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r3, 0
	bl _call_via_r1
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812C4BC

	thumb_func_start sub_812C500
sub_812C500: @ 812C500
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r5, 0
	ldrh r1, [r0, 0x36]
	mov r8, r1
	movs r1, 0x36
	ldrsh r6, [r0, r1]
_0812C518:
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r6, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r7
	bne _0812C544
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	mov r1, r8
	strh r1, [r0, 0x38]
	strh r5, [r0, 0x32]
	movs r0, 0x1
	b _0812C552
	.pool
_0812C544:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C518
	movs r0, 0
_0812C552:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812C500

	thumb_func_start sub_812C55C
sub_812C55C: @ 812C55C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r2, 0x34
	ldrsh r1, [r0, r2]
	movs r2, 0x36
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0812C59C
	adds r0, r6, 0
	bl sub_812C500
	lsls r0, 24
	lsrs r0, 24
	b _0812C5D2
	.pool
_0812C588:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	strh r5, [r0, 0x32]
	mov r1, r8
	strh r1, [r0, 0x38]
	movs r0, 0x1
	b _0812C5D2
	.pool
_0812C59C:
	movs r2, 0x1
	mov r8, r2
	cmp r1, 0x1
	bne _0812C5A8
	movs r0, 0x3
	mov r8, r0
_0812C5A8:
	movs r5, 0
	mov r7, r8
_0812C5AC:
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r7, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r6
	beq _0812C588
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C5AC
	movs r0, 0
_0812C5D2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_812C55C

	thumb_func_start sub_812C5DC
sub_812C5DC: @ 812C5DC
	push {r4,r5,lr}
	movs r5, 0
	b _0812C5E8
_0812C5E2:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0812C5E8:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_812C1C4
	lsls r0, 24
	cmp r0, 0
	bne _0812C5E2
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	strh r5, [r0, 0x2E]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812C5DC

	thumb_func_start sub_812C608
sub_812C608: @ 812C608
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0
	bne _0812C616
	movs r0, 0x1
	b _0812C620
_0812C616:
	cmp r0, 0x1
	beq _0812C61E
	movs r0, 0
	b _0812C624
_0812C61E:
	movs r0, 0
_0812C620:
	strb r0, [r1]
	movs r0, 0x1
_0812C624:
	pop {r1}
	bx r1
	thumb_func_end sub_812C608

	thumb_func_start sub_812C628
sub_812C628: @ 812C628
	push {lr}
	ldr r1, =gUnknown_085A752C
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r2, 0x12
	ldrsh r0, [r0, r2]
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812C628

	thumb_func_start sub_812C64C
sub_812C64C: @ 812C64C
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	movs r1, 0x34
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0812C6C4
	ldrb r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812C6C4
	ldrh r0, [r2, 0x2E]
	movs r1, 0x2
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	mov r1, sp
	strb r0, [r1]
	mov r0, sp
	bl sub_812C608
	lsls r0, 24
	cmp r0, 0
	beq _0812C6C4
	movs r5, 0
	mov r6, sp
	movs r7, 0x2
_0812C68C:
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r7, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	ldrb r1, [r6]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0812C6B8
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	movs r0, 0x2
	strh r0, [r1, 0x36]
	strh r5, [r1, 0x30]
	b _0812C6C4
	.pool
_0812C6B8:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C68C
_0812C6C4:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_812C64C

	thumb_func_start j5_08111E84
j5_08111E84: @ 812C6CC
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203AB34
	ldr r2, [r4]
	ldrh r3, [r2, 0x34]
	movs r1, 0x34
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0812C744
	ldrb r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812C744
	ldrh r1, [r2, 0x2E]
	subs r1, r3, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	mov r1, sp
	strb r0, [r1]
	mov r0, sp
	bl sub_812C608
	lsls r0, 24
	cmp r0, 0
	beq _0812C744
	movs r5, 0
	mov r7, sp
	adds r6, r4, 0
_0812C70C:
	ldr r0, [r6]
	ldrh r1, [r0, 0x34]
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	ldrb r1, [r7]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0812C738
	ldr r0, [r6]
	ldrh r1, [r0, 0x34]
	strh r1, [r0, 0x36]
	strh r5, [r0, 0x30]
	b _0812C744
	.pool
_0812C738:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C70C
_0812C744:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end j5_08111E84

	thumb_func_start sub_812C74C
sub_812C74C: @ 812C74C
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r6, =gUnknown_0203AB34
	ldr r2, [r6]
	ldrh r4, [r2, 0x34]
	movs r0, 0x34
	ldrsh r3, [r2, r0]
	cmp r3, 0
	beq _0812C84A
	ldrb r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812C84A
	cmp r3, 0x2
	bne _0812C796
	bl j5_08111E84
	b _0812C84A
	.pool
_0812C778:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r1, 0
	strh r5, [r0, 0x36]
	strh r1, [r0, 0x30]
	b _0812C84A
	.pool
_0812C788:
	movs r0, 0x2
	strh r0, [r1, 0x36]
	adds r0, r4, 0x1
	strh r0, [r1, 0x30]
	b _0812C84A
_0812C792:
	movs r0, 0x3
	b _0812C824
_0812C796:
	ldrh r1, [r2, 0x2E]
	subs r1, r4, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	mov r1, sp
	strb r0, [r1]
	mov r0, sp
	bl sub_812C608
	lsls r0, 24
	cmp r0, 0
	beq _0812C84A
	movs r5, 0x2
	ldr r0, [r6]
	movs r1, 0x34
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	bne _0812C7C2
	movs r5, 0x3
_0812C7C2:
	movs r6, 0
	mov r7, sp
_0812C7C6:
	lsls r0, r5, 16
	asrs r4, r0, 16
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_812BC98
	ldrb r1, [r7]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	beq _0812C778
	lsls r1, r6, 16
	movs r2, 0x80
	lsls r2, 9
	adds r1, r2
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	lsrs r6, r1, 16
	asrs r1, 16
	cmp r1, 0x1
	ble _0812C7C6
	movs r5, 0x1
	mov r7, sp
	ldr r6, =gUnknown_0203AB34
_0812C7F8:
	ldr r0, [r6]
	ldrh r1, [r0, 0x34]
	lsls r0, r5, 16
	asrs r4, r0, 16
	subs r1, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	ldrb r1, [r7]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0812C83E
	ldr r1, [r6]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _0812C830
	cmp r4, 0x2
	ble _0812C788
_0812C824:
	strh r0, [r1, 0x36]
	strh r5, [r1, 0x30]
	b _0812C84A
	.pool
_0812C830:
	cmp r4, 0x2
	ble _0812C792
	movs r0, 0x2
	strh r0, [r1, 0x36]
	subs r0, r4, 0x1
	strh r0, [r1, 0x30]
	b _0812C84A
_0812C83E:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C7F8
_0812C84A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_812C74C

	thumb_func_start sub_812C854
sub_812C854: @ 812C854
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r0, 0
	bne _0812C868
	cmp r1, 0x1
	beq _0812C870
_0812C868:
	cmp r0, 0x1
	bne _0812C874
	cmp r2, 0
	bne _0812C874
_0812C870:
	movs r0, 0x1
	b _0812C876
_0812C874:
	movs r0, 0
_0812C876:
	pop {r1}
	bx r1
	thumb_func_end sub_812C854

	thumb_func_start sub_812C87C
sub_812C87C: @ 812C87C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	cmp r0, 0
	bne _0812C896
	cmp r1, 0x1
	bne _0812C896
	cmp r2, 0
	beq _0812C8A2
_0812C896:
	cmp r0, 0x1
	bne _0812C8A6
	cmp r1, 0
	bne _0812C8A6
	cmp r2, 0x1
	bne _0812C8A6
_0812C8A2:
	movs r0, 0x1
	b _0812C8A8
_0812C8A6:
	movs r0, 0
_0812C8A8:
	pop {r1}
	bx r1
	thumb_func_end sub_812C87C

	thumb_func_start sub_812C8AC
sub_812C8AC: @ 812C8AC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	cmp r0, 0
	bne _0812C8C6
	cmp r1, 0x1
	bne _0812C8C6
	cmp r2, 0
	beq _0812C8F2
_0812C8C6:
	cmp r0, 0x1
	bne _0812C8D2
	cmp r1, 0
	bne _0812C8D2
	cmp r2, 0x1
	beq _0812C8F2
_0812C8D2:
	cmp r0, 0
	bne _0812C8DE
	cmp r1, 0
	bne _0812C8DE
	cmp r2, 0x1
	beq _0812C8F2
_0812C8DE:
	cmp r0, 0x1
	bne _0812C8EA
	cmp r1, 0x1
	bne _0812C8EA
	cmp r2, 0
	beq _0812C8F2
_0812C8EA:
	cmp r0, r1
	bne _0812C8F6
	cmp r0, r2
	bne _0812C8F6
_0812C8F2:
	movs r0, 0
	b _0812C8F8
_0812C8F6:
	movs r0, 0x1
_0812C8F8:
	pop {r1}
	bx r1
	thumb_func_end sub_812C8AC

	thumb_func_start sub_812C8FC
sub_812C8FC: @ 812C8FC
	push {lr}
	ldr r1, =gUnknown_085A7538
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	movs r2, 0x12
	ldrsh r0, [r0, r2]
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812C8FC

	thumb_func_start sub_812C920
sub_812C920: @ 812C920
	push {r4-r7,lr}
	movs r6, 0
	ldr r7, =gUnknown_0203AB34
	ldr r0, [r7]
	ldrh r1, [r0, 0x2E]
	movs r4, 0x2
	subs r1, r4, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r7]
	ldrh r0, [r0, 0x30]
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r5, r1
	bne _0812C994
	movs r4, 0x2
	b _0812C96A
	.pool
_0812C960:
	lsls r0, r6, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r6, r0, 16
_0812C96A:
	lsls r1, r6, 16
	asrs r1, 16
	subs r1, r4, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _0812C960
	cmp r5, 0
	bne _0812C98A
	cmp r0, 0x1
	beq _0812C960
_0812C98A:
	cmp r5, 0x1
	bne _0812C9F6
	cmp r0, 0
	beq _0812C960
	b _0812C9F6
_0812C994:
	adds r0, r5, 0
	bl sub_812C854
	lsls r0, 24
	cmp r0, 0
	beq _0812C9F6
	ldr r0, [r7]
	ldrb r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812C9D2
	movs r7, 0x2
_0812C9AE:
	lsls r0, r6, 16
	asrs r4, r0, 16
	subs r1, r7, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _0812C9F6
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812C9AE
_0812C9D2:
	movs r6, 0
	movs r7, 0x2
	b _0812C9DE
_0812C9D8:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_0812C9DE:
	lsls r0, r6, 16
	asrs r4, r0, 16
	subs r1, r7, r4
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	beq _0812C9D8
_0812C9F6:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	strh r6, [r0, 0x32]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812C920

	thumb_func_start sub_812CA08
sub_812CA08: @ 812CA08
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, =gUnknown_0203AB34
	ldr r2, [r4]
	movs r5, 0x36
	ldrsh r1, [r2, r5]
	cmp r1, 0
	beq _0812CAA4
	ldrh r3, [r2, 0x34]
	movs r5, 0x34
	ldrsh r0, [r2, r5]
	cmp r0, r1
	bne _0812CAA4
	ldrb r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812CAA4
	ldrh r1, [r2, 0x2E]
	subs r1, r3, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, [r4]
	ldrh r1, [r0, 0x36]
	ldrh r0, [r0, 0x30]
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_812C854
	lsls r0, 24
	cmp r0, 0
	beq _0812CAA4
	movs r5, 0
	b _0812CA7E
	.pool
_0812CA78:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0812CA7E:
	lsls r6, r5, 16
	asrs r5, r6, 16
	cmp r5, 0x4
	bgt _0812CAA4
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	ldrh r1, [r0, 0x36]
	subs r1, r5
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r7, r4
	bne _0812CA78
	lsrs r6, 16
	str r6, [sp]
_0812CAA4:
	ldr r0, =gUnknown_0203AB34
	mov r9, r0
_0812CAA8:
	movs r5, 0x1
	movs r1, 0
	mov r8, r1
	ldr r2, [sp]
	lsls r2, 16
	mov r10, r2
_0812CAB4:
	mov r1, r9
	ldr r0, [r1]
	ldrh r1, [r0, 0x2E]
	lsls r5, 16
	asrs r4, r5, 16
	subs r1, r4, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r7, r0, 24
	mov r2, r9
	ldr r0, [r2]
	ldrh r1, [r0, 0x30]
	subs r1, r4, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	lsls r0, 24
	lsrs r6, r0, 24
	mov r1, r10
	asrs r0, r1, 16
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_812C8AC
	lsls r0, 24
	cmp r0, 0
	bne _0812CB3C
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_812C87C
	lsls r0, 24
	cmp r0, 0
	beq _0812CB28
	mov r2, r9
	ldr r0, [r2]
	ldrb r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812CB3C
_0812CB28:
	mov r5, r8
	lsls r0, r5, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r0, 16
	mov r8, r0
	b _0812CB4A
	.pool
_0812CB3C:
	movs r2, 0x80
	lsls r2, 9
	adds r0, r5, r2
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0812CAB4
_0812CB4A:
	mov r5, r8
	cmp r5, 0
	beq _0812CB60
	ldr r1, [sp]
	lsls r0, r1, 16
	movs r2, 0x80
	lsls r2, 9
	adds r0, r2
	lsrs r0, 16
	str r0, [sp]
	b _0812CAA8
_0812CB60:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r0, 0x32]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CA08

	thumb_func_start sub_812CB80
sub_812CB80: @ 812CB80
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_812CA08
	ldr r4, =gUnknown_0203AB34
	ldr r2, [r4]
	movs r0, 0x36
	ldrsh r1, [r2, r0]
	cmp r1, 0
	beq _0812CC34
	ldrh r3, [r2, 0x34]
	movs r5, 0x34
	ldrsh r0, [r2, r5]
	cmp r0, r1
	beq _0812CC34
	ldrb r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0812CC34
	ldrh r1, [r2, 0x2E]
	subs r1, r3, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [r4]
	ldrh r1, [r0, 0x36]
	ldrh r0, [r0, 0x30]
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_812C854
	lsls r0, 24
	cmp r0, 0
	beq _0812CC34
	movs r1, 0x1
	ldr r0, [r4]
	movs r2, 0x34
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	bne _0812CBEE
	movs r1, 0x3
_0812CBEE:
	movs r3, 0
	lsls r1, 16
	mov r8, r1
	adds r7, r4, 0
_0812CBF6:
	ldr r0, [r7]
	ldrh r2, [r0, 0x32]
	lsls r0, r3, 16
	asrs r5, r0, 16
	adds r2, r5, r2
	mov r0, r8
	asrs r1, r0, 16
	subs r1, r2
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r6, r4
	bne _0812CC28
	ldr r1, [r7]
	ldrh r0, [r1, 0x32]
	adds r0, r5, r0
	strh r0, [r1, 0x32]
	b _0812CC34
	.pool
_0812CC28:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _0812CBF6
_0812CC34:
	ldr r7, =gUnknown_0203AB34
_0812CC36:
	ldr r0, [r7]
	ldrh r0, [r0, 0x2E]
	movs r1, 0x1
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [r7]
	ldrh r0, [r0, 0x30]
	movs r1, 0x2
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r7]
	ldrh r0, [r0, 0x32]
	movs r1, 0x3
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_812C8AC
	lsls r0, 24
	cmp r0, 0
	bne _0812CCB4
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_812C87C
	lsls r0, 24
	cmp r0, 0
	beq _0812CCA4
	ldr r0, [r7]
	ldrb r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812CCB4
_0812CCA4:
	ldr r1, [r7]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	b _0812CC36
	.pool
_0812CCB4:
	ldr r7, =gUnknown_0203AB34
_0812CCB6:
	ldr r0, [r7]
	ldrh r0, [r0, 0x2E]
	movs r1, 0x3
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl sub_812BC98
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, [r7]
	ldrh r0, [r0, 0x30]
	movs r1, 0x2
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x1
	bl sub_812BC98
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r7]
	ldrh r0, [r0, 0x32]
	movs r1, 0x1
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	movs r0, 0x2
	bl sub_812BC98
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_812C8AC
	lsls r0, 24
	cmp r0, 0
	bne _0812CD34
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_812C87C
	lsls r0, 24
	cmp r0, 0
	beq _0812CD24
	ldr r0, [r7]
	ldrb r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812CD34
_0812CD24:
	ldr r1, [r7]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	b _0812CCB6
	.pool
_0812CD34:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_812CB80

	thumb_func_start sub_812CD40
sub_812CD40: @ 812CD40
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =sub_812CD74
	adds r0, r5, 0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x26]
	bl _call_via_r5
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CD40

	thumb_func_start sub_812CD74
sub_812CD74: @ 812CD74
	push {r4,lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_085A7544
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r4, 0x8
	ldrsh r2, [r0, r4]
	lsls r2, 2
	adds r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CD74

	thumb_func_start sub_812CDA4
sub_812CDA4: @ 812CDA4
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_085A7550
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x73
	str r1, [sp]
	movs r1, 0x62
	movs r2, 0x63
	movs r3, 0x72
	bl sub_812FA78
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CDA4

	thumb_func_start sub_812CDD8
sub_812CDD8: @ 812CDD8
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	ble _0812CDF0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
_0812CDF0:
	pop {r0}
	bx r0
	thumb_func_end sub_812CDD8

	thumb_func_start sub_812CDF4
sub_812CDF4: @ 812CDF4
	push {r4,lr}
	sub sp, 0x4
	lsls r4, r1, 24
	lsrs r4, 24
	ldr r1, =gUnknown_085A7550
	movs r2, 0x26
	ldrsh r0, [r0, r2]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x53
	str r1, [sp]
	movs r1, 0x42
	movs r2, 0x43
	movs r3, 0x52
	bl sub_812FA78
	adds r0, r4, 0
	bl DestroyTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CDF4

	thumb_func_start sub_812CE2C
sub_812CE2C: @ 812CE2C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_085A8408
	lsls r1, r0, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, =gUnknown_085A8430
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r2, 0
	movs r2, 0x2
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CE2C

	thumb_func_start sub_812CE54
sub_812CE54: @ 812CE54
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_085A841C
	lsls r1, r0, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, =gUnknown_085A8430
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r2, 0
	movs r2, 0x2
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CE54

	thumb_func_start sub_812CE7C
sub_812CE7C: @ 812CE7C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	ldr r0, =gUnknown_085A843B
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r4, r0
	bcs _0812CEA8
	ldr r7, =gUnknown_085A8435
	adds r6, r0, 0
	lsls r5, r1, 1
_0812CE94:
	adds r0, r4, r5
	adds r0, r7
	ldrb r0, [r0]
	bl sub_812CE2C
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _0812CE94
_0812CEA8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CE7C

	thumb_func_start sub_812CEB8
sub_812CEB8: @ 812CEB8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	ldr r0, =gUnknown_085A843B
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r4, r0
	bcs _0812CEE4
	ldr r7, =gUnknown_085A8435
	adds r6, r0, 0
	lsls r5, r1, 1
_0812CED0:
	adds r0, r4, r5
	adds r0, r7
	ldrb r0, [r0]
	bl sub_812CE54
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _0812CED0
_0812CEE4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CEB8

	thumb_func_start sub_812CEF4
sub_812CEF4: @ 812CEF4
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gSprites
_0812CEFA:
	ldr r0, =sub_812D024
	bl CreateInvisibleSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	strh r4, [r1, 0x2E]
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x44
	adds r1, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _0812CEFA
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812CEF4

	thumb_func_start sub_812CF34
sub_812CF34: @ 812CF34
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x44
	adds r1, r0
	ldrb r1, [r1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strh r1, [r0, 0x30]
	movs r1, 0x4
	strh r1, [r0, 0x32]
	strh r2, [r0, 0x34]
	strh r2, [r0, 0x36]
	movs r1, 0x2
	strh r1, [r0, 0x38]
	strh r2, [r0, 0x3C]
	bx lr
	.pool
	thumb_func_end sub_812CF34

	thumb_func_start sub_812CF6C
sub_812CF6C: @ 812CF6C
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r3, r0, 0
	adds r3, 0x44
	ldr r4, =gSprites
_0812CF7A:
	adds r0, r3, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	movs r5, 0x30
	ldrsh r0, [r1, r5]
	cmp r0, 0
	beq _0812CFA4
	movs r5, 0x32
	ldrsh r0, [r1, r5]
	cmp r0, 0
	beq _0812CFA4
	movs r0, 0
	b _0812CFB0
	.pool
_0812CFA4:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x4
	bls _0812CF7A
	movs r0, 0x1
_0812CFB0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_812CF6C

	thumb_func_start sub_812CFB8
sub_812CFB8: @ 812CFB8
	push {r4,lr}
	movs r4, 0
_0812CFBC:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x44
	adds r0, r4
	ldrb r0, [r0]
	bl sub_812CFEC
	lsls r0, 24
	cmp r0, 0
	bne _0812CFD8
	movs r0, 0
	b _0812CFE4
	.pool
_0812CFD8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _0812CFBC
	movs r0, 0x1
_0812CFE4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_812CFB8

	thumb_func_start sub_812CFEC
sub_812CFEC: @ 812CFEC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0812D00C
	movs r0, 0x1
	b _0812D01E
	.pool
_0812D00C:
	ldrh r2, [r1, 0x3C]
	movs r3, 0x3C
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0812D01A
	movs r0, 0
	strh r0, [r1, 0x30]
_0812D01A:
	lsls r0, r2, 24
	lsrs r0, 24
_0812D01E:
	pop {r1}
	bx r1
	thumb_func_end sub_812CFEC

	thumb_func_start sub_812D024
sub_812D024: @ 812D024
	push {r4-r7,lr}
	adds r2, r0, 0
	movs r1, 0x30
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0812D0A6
	ldrh r0, [r2, 0x34]
	subs r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0812D08E
	movs r0, 0
	strh r0, [r2, 0x3C]
	movs r6, 0x1
	strh r6, [r2, 0x34]
	ldrh r1, [r2, 0x38]
	ldrh r3, [r2, 0x36]
	adds r0, r1, r3
	strh r0, [r2, 0x36]
	movs r4, 0x4
	ldrh r5, [r2, 0x32]
	movs r7, 0x32
	ldrsh r3, [r2, r7]
	cmp r3, 0
	beq _0812D060
	movs r4, 0x8
_0812D060:
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bgt _0812D078
	strh r6, [r2, 0x3C]
	negs r0, r1
	strh r0, [r2, 0x38]
	cmp r3, 0
	beq _0812D08E
	subs r0, r5, 0x1
	strh r0, [r2, 0x32]
	b _0812D080
_0812D078:
	cmp r0, r4
	blt _0812D080
	negs r0, r1
	strh r0, [r2, 0x38]
_0812D080:
	movs r1, 0x32
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0812D08E
	ldrh r0, [r2, 0x34]
	lsls r0, 1
	strh r0, [r2, 0x34]
_0812D08E:
	ldr r1, =gUnknown_085A8430
	movs r3, 0x2E
	ldrsh r0, [r2, r3]
	adds r0, r1
	ldrb r0, [r0]
	ldrh r3, [r2, 0x36]
	lsls r3, 24
	lsrs r3, 24
	adds r1, r3, 0
	adds r2, r3, 0
	bl MultiplyPaletteRGBComponents
_0812D0A6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D024

	thumb_func_start sub_812D0B0
sub_812D0B0: @ 812D0B0
	push {r4,lr}
	ldr r4, =sub_812D128
	adds r0, r4, 0
	movs r1, 0x6
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x1
	strh r2, [r1, 0xE]
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D0B0

	thumb_func_start sub_812D0E0
sub_812D0E0: @ 812D0E0
	push {lr}
	ldr r0, =sub_812D128
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0812D10C
	movs r0, 0
	b _0812D120
	.pool
_0812D10C:
	adds r0, r2, 0
	bl DestroyTask
	ldr r0, =gUnknown_085A84AC
	ldr r0, [r0]
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x1
_0812D120:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812D0E0

	thumb_func_start sub_812D128
sub_812D128: @ 812D128
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r2, r1, r0
	ldrh r0, [r2, 0xA]
	subs r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0812D166
	movs r0, 0x4
	strh r0, [r2, 0xA]
	ldrh r1, [r2, 0xE]
	ldrh r3, [r2, 0xC]
	adds r0, r1, r3
	strh r0, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _0812D162
	cmp r0, 0x2
	bne _0812D166
_0812D162:
	negs r0, r1
	strh r0, [r2, 0xE]
_0812D166:
	ldr r0, =gUnknown_085A84A0
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D128

	thumb_func_start sub_812D188
sub_812D188: @ 812D188
	push {lr}
	ldr r0, =sub_812D230
	movs r1, 0x8
	bl CreateTask
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x3E
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D188

	thumb_func_start sub_812D1A8
sub_812D1A8: @ 812D1A8
	push {r4,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r4, 0
	bl sub_812D394
	movs r1, 0x1
	strh r1, [r4, 0x8]
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	strh r1, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D1A8

	thumb_func_start sub_812D1DC
sub_812D1DC: @ 812D1DC
	push {r4,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r4, 0
	bl sub_812D394
	movs r0, 0x3
	strh r0, [r4, 0x8]
	movs r0, 0x1
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D1DC

	thumb_func_start sub_812D20C
sub_812D20C: @ 812D20C
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0x26]
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_812D20C

	thumb_func_start sub_812D230
sub_812D230: @ 812D230
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_085A7558
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D230

	thumb_func_start nullsub_50
nullsub_50: @ 812D260
	bx lr
	thumb_func_end nullsub_50

	thumb_func_start sub_812D264
sub_812D264: @ 812D264
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	lsls r0, 19
	movs r1, 0xA0
	lsls r1, 13
	adds r0, r1
	asrs r0, 16
	movs r1, 0x14
	bl sub_812EF00
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D264

	thumb_func_start sub_812D28C
sub_812D28C: @ 812D28C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, =gSprites
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3C
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0812D2FC
	ldrh r1, [r4, 0xA]
	adds r0, r1, 0x2
	lsls r0, 16
	lsrs r5, r0, 16
	movs r3, 0
	movs r2, 0
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x1
	bne _0812D2C4
	movs r3, 0x1
	movs r2, 0x1
	b _0812D2CC
	.pool
_0812D2C4:
	cmp r1, 0x10
	bne _0812D2CC
	movs r3, 0x2
	movs r2, 0x2
_0812D2CC:
	ldr r0, =gUnknown_0203AACC
	ldr r0, [r0]
	lsls r1, r2, 1
	adds r1, r0
	ldr r2, =gUnknown_085A7568
	lsls r0, r3, 2
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r3, r5, 16
	movs r0, 0x80
	lsls r0, 15
	adds r3, r0
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	ldrb r0, [r4, 0xC]
	bl sub_812EF6C
	movs r0, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x26]
_0812D2FC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D28C

	thumb_func_start sub_812D30C
sub_812D30C: @ 812D30C
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0xA]
	adds r0, r1, 0x2
	lsls r0, 16
	lsrs r5, r0, 16
	movs r3, 0
	movs r2, 0x3
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x1
	bne _0812D32A
	movs r3, 0x1
	movs r2, 0x1
	b _0812D332
_0812D32A:
	cmp r1, 0x10
	bne _0812D332
	movs r3, 0x2
	movs r2, 0x2
_0812D332:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0812D366
	ldr r0, =gUnknown_0203AACC
	ldr r0, [r0]
	lsls r1, r2, 1
	adds r1, r0
	ldr r0, =gUnknown_085A7568
	lsls r2, r3, 2
	adds r0, 0x2
	adds r2, r0
	ldrh r0, [r2]
	strh r0, [r1]
	lsls r3, r5, 16
	movs r0, 0x80
	lsls r0, 15
	adds r3, r0
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
_0812D366:
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0812D378
	movs r0, 0
	strh r0, [r4, 0xC]
_0812D378:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0812D384
	strh r0, [r4, 0x8]
	strh r0, [r4, 0x26]
_0812D384:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D30C

	thumb_func_start sub_812D394
sub_812D394: @ 812D394
	push {lr}
	movs r1, 0x2
	adds r2, r0, 0
	adds r2, 0x8
	movs r3, 0
_0812D39E:
	lsls r0, r1, 1
	adds r0, r2, r0
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _0812D39E
	pop {r0}
	bx r0
	thumb_func_end sub_812D394

	thumb_func_start sub_812D3B4
sub_812D3B4: @ 812D3B4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0x3
	movs r5, 0
	cmp r5, r6
	bge _0812D41E
	ldr r7, =gUnknown_085A7568
_0812D3C4:
	movs r3, 0
	movs r1, 0
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0
	bne _0812D3DC
	movs r3, 0x1
	movs r1, 0x1
	b _0812D3E4
	.pool
_0812D3DC:
	cmp r0, 0xF
	bne _0812D3E4
	movs r3, 0x2
	movs r1, 0x2
_0812D3E4:
	ldr r0, =gUnknown_0203AACC
	ldr r0, [r0]
	lsls r1, 1
	adds r1, r0
	lsls r0, r3, 2
	adds r0, r7
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r3, r4, 16
	asrs r4, r3, 16
	movs r0, 0x80
	lsls r0, 15
	adds r3, r0
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	lsls r0, r5, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	adds r4, 0x1
	lsls r4, 16
	lsrs r4, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, r6
	blt _0812D3C4
_0812D41E:
	lsls r2, r5, 16
	asrs r0, r2, 16
	cmp r0, 0xF
	bgt _0812D484
	ldr r7, =gUnknown_085A756A
_0812D428:
	movs r3, 0
	movs r1, 0x3
	asrs r0, r2, 16
	cmp r0, 0
	bne _0812D440
	movs r3, 0x1
	movs r1, 0x1
	b _0812D448
	.pool
_0812D440:
	cmp r0, 0xF
	bne _0812D448
	movs r3, 0x2
	movs r1, 0x2
_0812D448:
	ldr r0, =gUnknown_0203AACC
	ldr r0, [r0]
	lsls r1, 1
	adds r1, r0
	lsls r0, r3, 2
	adds r0, r7
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r3, r4, 16
	asrs r4, r3, 16
	movs r0, 0x80
	lsls r0, 15
	adds r3, r0
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	lsls r0, r5, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r5, r0, 16
	adds r4, 0x1
	lsls r4, 16
	lsrs r4, 16
	lsls r2, r5, 16
	asrs r0, r2, 16
	cmp r0, 0xF
	ble _0812D428
_0812D484:
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r6, [r0, 0xA]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D3B4

	thumb_func_start sub_812D4AC
sub_812D4AC: @ 812D4AC
	push {r4,lr}
	ldr r4, =sub_812D4EC
	adds r0, r4, 0
	movs r1, 0x7
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D4AC

	thumb_func_start sub_812D4CC
sub_812D4CC: @ 812D4CC
	push {lr}
	ldr r0, =sub_812D4EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0812D4E4
	movs r0, 0
	b _0812D4E6
	.pool
_0812D4E4:
	movs r0, 0x1
_0812D4E6:
	pop {r1}
	bx r1
	thumb_func_end sub_812D4CC

	thumb_func_start sub_812D4EC
sub_812D4EC: @ 812D4EC
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_085A7574
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D4EC

	thumb_func_start sub_812D51C
sub_812D51C: @ 812D51C
	push {lr}
	ldr r3, =gUnknown_0203AB34
	ldr r1, [r3]
	movs r2, 0
	strb r2, [r1, 0xA]
	ldr r1, [r3]
	strh r2, [r1, 0x14]
	strh r2, [r1, 0x16]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	strh r2, [r0, 0xA]
	movs r1, 0x1E
	strh r1, [r0, 0xC]
	movs r1, 0xA0
	lsls r1, 3
	strh r1, [r0, 0x10]
	ldr r0, =gSpriteCoordOffsetX
	strh r2, [r0]
	ldr r0, =gSpriteCoordOffsetY
	strh r2, [r0]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl sub_812DC08
	bl sub_812E474
	bl sub_812E33C
	bl sub_812E650
	bl sub_812E70C
	bl sub_812E7CC
	bl sub_812B700
	bl StopMapMusic
	movs r0, 0xC4
	lsls r0, 1
	bl PlayNewMapMusic
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D51C

	thumb_func_start sub_812D594
sub_812D594: @ 812D594
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r1, =gSpriteCoordOffsetX
	ldrh r0, [r1]
	subs r0, 0x8
	strh r0, [r1]
	ldrh r1, [r4, 0xA]
	adds r1, 0x8
	strh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r0, 0xF0
	movs r2, 0xFF
	ands r0, r2
	lsrs r5, r0, 3
	ldr r0, =0x000001ff
	ands r1, r0
	movs r0, 0x14
	bl SetGpuReg
	adds r2, r5, 0
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r2, r0
	beq _0812D5E2
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0x12
	bgt _0812D5E2
	strh r5, [r4, 0xC]
	ldrh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 19
	strh r0, [r4, 0xE]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	adds r0, r2, 0
	bl sub_812DC08
_0812D5E2:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0xC7
	ble _0812D5F4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x8]
	strh r1, [r4, 0xE]
_0812D5F4:
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D594

	thumb_func_start sub_812D60C
sub_812D60C: @ 812D60C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3B
	ble _0812D636
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	bl sub_812E934
	bl sub_812EAB0
_0812D636:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D60C

	thumb_func_start sub_812D63C
sub_812D63C: @ 812D63C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r7, r0, 0
	ldr r1, =gUnknown_085A75C0
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	add r0, sp, 0x4
	mov r8, r0
	ldr r1, =gUnknown_085A75C4
	movs r2, 0x8
	bl memcpy
	add r6, sp, 0xC
	ldr r1, =gUnknown_085A75CC
	adds r0, r6, 0
	movs r2, 0x8
	bl memcpy
	ldrh r0, [r7, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	ldrh r0, [r7, 0x10]
	subs r0, 0x4
	strh r0, [r7, 0x10]
	lsls r0, 16
	asrs r0, 24
	movs r5, 0x4
	subs r5, r0
	lsls r4, r5, 1
	add r8, r4
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_812EA44
	adds r6, r4
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl sub_812EBAC
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	mov r2, sp
	adds r1, r2, r5
	ldrb r1, [r1]
	bl StartSpriteAnimIfDifferent
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	lsls r1, 1
	cmp r0, r1
	bgt _0812D6CC
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
	strh r1, [r7, 0x10]
	movs r0, 0
	strh r0, [r7, 0x12]
_0812D6CC:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D63C

	thumb_func_start sub_812D6EC
sub_812D6EC: @ 812D6EC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4F
	ble _0812D730
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0x12]
	movs r0, 0x2
	bl sub_812EBAC
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x3
	bl StartSpriteAnimIfDifferent
_0812D730:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D6EC

	thumb_func_start sub_812D740
sub_812D740: @ 812D740
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	ldrb r0, [r4, 0x10]
	adds r0, 0x80
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4F
	ble _0812D76C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0x12]
_0812D76C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D740

	thumb_func_start sub_812D774
sub_812D774: @ 812D774
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	ldrb r0, [r4, 0x10]
	adds r0, 0x40
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _0812D7DC
	movs r0, 0
	strh r0, [r4, 0x12]
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	beq _0812D7B8
	ldrb r1, [r1, 0xA]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _0812D7D6
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	b _0812D7D4
	.pool
_0812D7B8:
	movs r1, 0x14
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _0812D7C6
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	b _0812D7D4
_0812D7C6:
	ldrh r0, [r4, 0x14]
	bl sub_812B760
	lsls r0, 24
	cmp r0, 0
	beq _0812D7D6
	movs r0, 0xE
_0812D7D4:
	strh r0, [r4, 0x8]
_0812D7D6:
	ldrh r0, [r4, 0x14]
	adds r0, 0x1
	strh r0, [r4, 0x14]
_0812D7DC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D774

	thumb_func_start sub_812D7E4
sub_812D7E4: @ 812D7E4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, =gUnknown_0203AB34
	ldr r0, [r6]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	movs r1, 0x14
	bl __modsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r0, 0
	beq _0812D810
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BE0C
	b _0812D838
	.pool
_0812D810:
	movs r0, 0x1
	bl sub_812BCE8
	ldr r1, [r6]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1, 0x5]
	cmp r0, r1
	beq _0812D842
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 24
	bl sub_812BDD4
	ldr r0, [r6]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	movs r1, 0x14
	bl __modsi3
_0812D838:
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r0, [r4, 0x10]
	adds r0, 0x40
	strh r0, [r4, 0x10]
_0812D842:
	lsls r0, r5, 16
	asrs r5, r0, 16
	cmp r5, 0
	bne _0812D866
	movs r0, 0x1
	bl sub_812BCE8
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1, 0x5]
	cmp r0, r1
	bne _0812D866
	strh r5, [r4, 0x10]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0812D866:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D7E4

	thumb_func_start sub_812D870
sub_812D870: @ 812D870
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	movs r6, 0
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3B
	ble _0812D914
	bl StopMapMusic
	bl sub_812EA7C
	bl sub_812EBCC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r5, =gUnknown_0203AB34
	ldr r1, [r5]
	ldrb r0, [r1, 0x5]
	cmp r0, 0
	bne _0812D8D0
	movs r0, 0xA0
	strh r0, [r4, 0x10]
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x5
	bl StartSpriteAnimIfDifferent
	ldr r0, =0x00000187
	bl PlayFanfare
	b _0812D914
	.pool
_0812D8D0:
	movs r0, 0xC0
	strh r0, [r4, 0x10]
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	movs r1, 0x4
	bl StartSpriteAnimIfDifferent
	ldr r0, [r5]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x2B
	strb r6, [r0]
	ldr r0, [r5]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0812D90C
	bl sub_812D1DC
	ldr r0, [r5]
	strb r6, [r0, 0x2]
_0812D90C:
	movs r0, 0xC3
	lsls r0, 1
	bl PlayFanfare
_0812D914:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812D870

	thumb_func_start sub_812D920
sub_812D920: @ 812D920
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x10]
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0812D938
	subs r0, r1, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	cmp r0, 0
	bne _0812D948
_0812D938:
	bl sub_812D20C
	lsls r0, 24
	cmp r0, 0
	bne _0812D948
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0812D948:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812D920

	thumb_func_start sub_812D950
sub_812D950: @ 812D950
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r1, =gSpriteCoordOffsetX
	ldrh r0, [r1]
	subs r0, 0x8
	strh r0, [r1]
	ldrh r1, [r4, 0xA]
	adds r1, 0x8
	strh r1, [r4, 0xA]
	ldrh r0, [r4, 0xE]
	adds r0, 0x8
	strh r0, [r4, 0xE]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	subs r0, 0x8
	movs r2, 0xFF
	ands r0, r2
	lsrs r5, r0, 3
	ldr r0, =0x000001ff
	ands r1, r0
	movs r0, 0x14
	bl SetGpuReg
	ldrh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 19
	cmp r0, 0x19
	bgt _0812D998
	adds r0, r5, 0
	bl sub_812DC50
	b _0812D99E
	.pool
_0812D998:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0812D99E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_812D950

	thumb_func_start sub_812D9A4
sub_812D9A4: @ 812D9A4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_0203AB34
	ldr r0, [r4]
	movs r6, 0
	strb r6, [r0, 0xB]
	ldr r1, [r4]
	ldrb r0, [r1, 0x5]
	strb r0, [r1, 0xA]
	ldr r0, =gSpriteCoordOffsetX
	strh r6, [r0]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldr r1, [r4]
	movs r0, 0x8
	strh r0, [r1, 0x1A]
	bl sub_812E3E8
	bl sub_812E82C
	bl sub_812E8C4
	ldr r0, [r4]
	adds r0, 0x60
	ldrh r0, [r0]
	bl PlayNewMapMusic
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	bne _0812DA04
	ldr r0, =sub_812D4EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _0812DA1A
	.pool
_0812DA04:
	movs r0, 0x4
	bl sub_812DEE4
	bl dp15_jump_random_unknown
	strh r0, [r5, 0xA]
	strh r6, [r5, 0xC]
	strh r6, [r5, 0xE]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_0812DA1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_812D9A4

	thumb_func_start sub_812DA20
sub_812DA20: @ 812DA20
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB34
	ldr r5, [r0]
	movs r0, 0x1A
	ldrsh r1, [r5, r0]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0812DA40
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0812DA66
	.pool
_0812DA40:
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	movs r1, 0x18
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0812DA66
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0812DA66
	ldrh r0, [r5, 0x1A]
	lsls r0, 16
	asrs r0, 17
	strh r0, [r5, 0x1A]
_0812DA66:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_812DA20

	thumb_func_start sub_812DA6C
sub_812DA6C: @ 812DA6C
	push {lr}
	bl sub_812E054
	lsls r0, 24
	cmp r0, 0
	beq _0812DA86
	ldr r0, =sub_812D4EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0812DA86:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DA6C

	thumb_func_start sub_812DA90
sub_812DA90: @ 812DA90
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_812E82C
	bl sub_812EA7C
	bl sub_812EBCC
	bl sub_812EC20
	ldr r5, =gSprites
	ldr r3, =gUnknown_0203AB34
	ldr r0, [r3]
	adds r0, 0x4E
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
	ldr r0, [r3]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x5
	bl StartSpriteAnimIfDifferent
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x8]
	movs r0, 0x4
	strh r0, [r4, 0x10]
	strh r1, [r4, 0x12]
	bl StopMapMusic
	ldr r0, =0x00000187
	bl PlayFanfare
	movs r0, 0xB2
	bl PlaySE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DA90

	thumb_func_start sub_812DB04
sub_812DB04: @ 812DB04
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r1, =gSpriteCoordOffsetY
	ldrh r0, [r4, 0x10]
	strh r0, [r1]
	ldrh r1, [r4, 0x10]
	movs r0, 0x16
	bl SetGpuReg
	ldrh r1, [r4, 0x12]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0812DB26
	ldrh r0, [r4, 0x10]
	negs r0, r0
	strh r0, [r4, 0x10]
_0812DB26:
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	movs r1, 0x1F
	ands r0, r1
	cmp r0, 0
	bne _0812DB3C
	ldrh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 17
	strh r0, [r4, 0x10]
_0812DB3C:
	movs r0, 0x10
	ldrsh r5, [r4, r0]
	cmp r5, 0
	bne _0812DB7A
	bl sub_812EC70
	bl sub_812EC94
	bl sub_812E5A8
	bl sub_812EDC0
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x4E
	ldrb r1, [r0]
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
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	strh r5, [r4, 0x12]
_0812DB7A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DB04

	thumb_func_start sub_812DB8C
sub_812DB8C: @ 812DB8C
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, =gSpriteCoordOffsetY
	movs r0, 0
	strh r0, [r1]
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	bl sub_812EEA8
	lsls r0, 24
	cmp r0, 0
	beq _0812DBB2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	bl sub_812EECC
_0812DBB2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DB8C

	thumb_func_start sub_812DBBC
sub_812DBBC: @ 812DBBC
	push {lr}
	ldr r1, =gSpriteCoordOffsetX
	movs r0, 0
	strh r0, [r1]
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x60
	ldrh r0, [r0]
	bl PlayNewMapMusic
	bl sub_812E3E8
	bl sub_812E8F8
	bl sub_812E8C4
	bl sub_812ED8C
	ldr r0, =sub_812D4EC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DBBC

	thumb_func_start sub_812DC08
sub_812DC08: @ 812DC08
	push {r4-r6,lr}
	movs r2, 0x4
	lsls r1, 16
	asrs r6, r1, 16
	lsls r0, 16
	asrs r5, r0, 16
_0812DC14:
	lsls r4, r2, 16
	asrs r4, 16
	subs r0, r4, 0x4
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6, r1
	lsls r1, 1
	ldr r0, =gUnknown_085A96E0
	adds r1, r0
	lsls r3, r4, 5
	adds r3, r5, r3
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x1
	movs r2, 0x2
	bl LoadBgTilemap
	adds r4, 0x1
	lsls r4, 16
	lsrs r2, r4, 16
	asrs r4, 16
	cmp r4, 0xE
	ble _0812DC14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DC08

	thumb_func_start sub_812DC50
sub_812DC50: @ 812DC50
	push {r4,r5,lr}
	movs r4, 0x4
	lsls r0, 16
	asrs r5, r0, 16
_0812DC58:
	lsls r3, r4, 5
	adds r3, r5, r3
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x1
	ldr r1, =gUnknown_085A9898
	movs r2, 0x2
	bl LoadBgTilemap
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xE
	bls _0812DC58
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DC50

	thumb_func_start sub_812DC80
sub_812DC80: @ 812DC80
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =sub_812DCD4
	adds r0, r5, 0
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xA]
	bl _call_via_r5
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DC80

	thumb_func_start sub_812DCB4
sub_812DCB4: @ 812DCB4
	push {lr}
	ldr r0, =sub_812DCD4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0812DCCC
	movs r0, 0
	b _0812DCCE
	.pool
_0812DCCC:
	movs r0, 0x1
_0812DCCE:
	pop {r1}
	bx r1
	thumb_func_end sub_812DCB4

	thumb_func_start sub_812DCD4
sub_812DCD4: @ 812DCD4
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_085A75D4
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DCD4

	thumb_func_start sub_812DD04
sub_812DD04: @ 812DD04
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812DD04

	thumb_func_start sub_812DD28
sub_812DD28: @ 812DD28
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0812DD3E
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_0812DD3E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DD28

	thumb_func_start sub_812DD48
sub_812DD48: @ 812DD48
	push {r4,lr}
	adds r4, r0, 0
	bl sub_812DFDC
	bl sub_812FAF4
	ldr r0, =gUnknown_085A7444
	bl AddWindow
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DD48

	thumb_func_start sub_812DD78
sub_812DD78: @ 812DD78
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	ldr r0, =gUnknown_085A744C
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r0, =gText_ReelTimeHelp
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x5
	bl box_print
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DD78

	thumb_func_start sub_812DDC4
sub_812DDC4: @ 812DDC4
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	beq _0812DE08
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x1
	bl ClearWindowTilemap
	movs r0, 0x1
	movs r1, 0x1
	bl CopyWindowToVram
	movs r0, 0x1
	bl RemoveWindow
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0812DE08:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DDC4

	thumb_func_start sub_812DE14
sub_812DE14: @ 812DE14
	push {r4,lr}
	adds r4, r0, 0
	bl sub_812F968
	movs r0, 0x3
	bl ShowBg
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812DE14

	thumb_func_start sub_812DE30
sub_812DE30: @ 812DE30
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl sub_812DEE4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812DE30

	thumb_func_start sub_812DE48
sub_812DE48: @ 812DE48
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	bl sub_812D3B4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DE48

	thumb_func_start sub_812DE7C
sub_812DE7C: @ 812DE7C
	push {lr}
	ldr r0, =sub_812DCD4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DE7C

	thumb_func_start sub_812DE94
sub_812DE94: @ 812DE94
	push {lr}
	ldr r0, =sub_812E0B0
	movs r1, 0x3
	bl CreateTask
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3D
	strb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0xA]
	movs r1, 0x4
	adds r2, r0, 0
	adds r2, 0x8
	movs r3, 0x40
_0812DEC0:
	lsls r0, r1, 1
	adds r0, r2, r0
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _0812DEC0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DE94

	thumb_func_start sub_812DEE4
sub_812DEE4: @ 812DEE4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_812DFDC
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3D
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r7, r0, r1
	strh r4, [r7, 0xA]
	movs r6, 0
	ldr r1, =gUnknown_085A7A04
	lsls r5, r4, 2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _0812DF52
	mov r8, r1
_0812DF1A:
	mov r0, r8
	adds r4, r5, r0
	ldr r0, [r4]
	lsls r2, r6, 2
	adds r2, r0
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	bl sub_812EF98
	lsls r0, 24
	lsrs r0, 24
	adds r2, r6, 0x4
	lsls r2, 1
	adds r1, r7, 0
	adds r1, 0x8
	adds r1, r2
	strh r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, [r4]
	lsls r0, r6, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0812DF1A
_0812DF52:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DEE4

	thumb_func_start sub_812DF68
sub_812DF68: @ 812DF68
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r1
	ldr r4, [sp, 0x1C]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3D
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	mov r12, r0
	movs r5, 0x4
	lsls r4, 16
	asrs r6, r4, 16
	lsls r2, 16
	lsls r3, 16
_0812DF96:
	lsls r0, r5, 1
	mov r1, r12
	adds r1, 0x8
	adds r4, r1, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	bne _0812DFC4
	str r6, [sp]
	adds r0, r7, 0
	mov r1, r8
	asrs r2, 16
	asrs r3, 16
	bl sub_812EFDC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	b _0812DFCE
	.pool
_0812DFC4:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _0812DF96
_0812DFCE:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_812DF68

	thumb_func_start sub_812DFDC
sub_812DFDC: @ 812DFDC
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3D
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _0812E008
	ldr r0, =gUnknown_085A7A20
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_0812E008:
	movs r5, 0x4
	adds r6, r4, 0
	adds r6, 0x8
_0812E00E:
	lsls r0, r5, 1
	adds r4, r6, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	beq _0812E02E
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r0, 0x40
	strh r0, [r4]
_0812E02E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _0812E00E
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812DFDC

	thumb_func_start sub_812E054
sub_812E054: @ 812E054
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3D
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	movs r2, 0x4
	adds r3, r0, 0
	adds r3, 0x8
	ldr r4, =gSprites
_0812E070:
	lsls r0, r2, 1
	adds r1, r3, r0
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0x40
	beq _0812E09C
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	movs r5, 0x3C
	ldrsh r0, [r1, r5]
	cmp r0, 0
	beq _0812E09C
	movs r0, 0
	b _0812E0A8
	.pool
_0812E09C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _0812E070
	movs r0, 0x1
_0812E0A8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_812E054

	thumb_func_start sub_812E0B0
sub_812E0B0: @ 812E0B0
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_085A7610
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E0B0

	thumb_func_start nullsub_51
nullsub_51: @ 812E0E0
	bx lr
	thumb_func_end nullsub_51

	thumb_func_start sub_812E0E4
sub_812E0E4: @ 812E0E4
	push {r4-r7,lr}
	movs r6, 0
	movs r0, 0x30
_0812E0EA:
	movs r4, 0
	lsls r5, r0, 16
	lsls r7, r6, 16
_0812E0F0:
	ldr r0, =gUnknown_085A7CE0
	asrs r1, r5, 16
	movs r2, 0
	movs r3, 0xE
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	ldrb r0, [r1, 0x5]
	movs r2, 0xC
	orrs r0, r2
	strb r0, [r1, 0x5]
	strh r6, [r1, 0x2E]
	strh r4, [r1, 0x30]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x34]
	lsls r0, r4, 16
	movs r1, 0xC0
	lsls r1, 13
	adds r0, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x77
	ble _0812E0F0
	movs r2, 0x80
	lsls r2, 9
	adds r1, r7, r2
	movs r2, 0xA0
	lsls r2, 14
	adds r0, r5, r2
	lsrs r0, 16
	lsrs r6, r1, 16
	asrs r1, 16
	cmp r1, 0x2
	ble _0812E0EA
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E0E4

	thumb_func_start sub_812E154
sub_812E154: @ 812E154
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_0203AB34
	ldr r4, [r0]
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x1C
	adds r1, r0
	ldrh r0, [r5, 0x30]
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r5, 0x32]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	movs r1, 0x78
	bl __modsi3
	strh r0, [r5, 0x32]
	movs r2, 0x2E
	ldrsh r1, [r5, r2]
	lsls r1, 1
	adds r4, 0x22
	adds r4, r1
	ldrh r1, [r4]
	adds r1, 0x1C
	adds r0, r1
	strh r0, [r5, 0x22]
	ldrh r4, [r5, 0x2E]
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x32
	ldrsh r0, [r5, r1]
	movs r1, 0x18
	bl __divsi3
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_812BC44
	lsls r0, 24
	lsrs r0, 24
	bl GetSpriteTileStartByTag
	adds r1, r5, 0
	adds r1, 0x40
	strh r0, [r1]
	adds r0, r5, 0
	bl SetSpriteSheetFrameTileNum
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E154

	thumb_func_start sub_812E1C8
sub_812E1C8: @ 812E1C8
	push {r4-r6,lr}
	movs r4, 0xCB
	movs r5, 0x1
	ldr r6, =0x0000270f
_0812E1D0:
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r0, r4, 0
	movs r1, 0x17
	movs r2, 0
	adds r3, r5, 0
	bl sub_812E230
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 17
	subs r4, 0x7
	lsls r4, 16
	lsrs r4, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, r6
	ble _0812E1D0
	movs r4, 0xEB
	movs r5, 0x1
	ldr r6, =0x0000270f
_0812E1FE:
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r0, r4, 0
	movs r1, 0x17
	movs r2, 0x1
	adds r3, r5, 0
	bl sub_812E230
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 17
	subs r4, 0x7
	lsls r4, 16
	lsrs r4, 16
	lsrs r5, r0, 16
	asrs r0, 16
	cmp r0, r6
	ble _0812E1FE
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E1C8

	thumb_func_start sub_812E230
sub_812E230: @ 812E230
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =gUnknown_085A7CF8
	lsls r5, 16
	asrs r5, 16
	lsls r6, 16
	asrs r6, 16
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0xD
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	ldrb r1, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x5]
	mov r0, r8
	strh r0, [r2, 0x2E]
	strh r4, [r2, 0x30]
	lsls r4, 16
	asrs r4, 16
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 1
	strh r0, [r2, 0x32]
	ldr r0, =0x0000ffff
	strh r0, [r2, 0x34]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E230

	thumb_func_start sub_812E2A8
sub_812E2A8: @ 812E2A8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	ldrh r2, [r1, 0xC]
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0812E2BC
	ldrh r2, [r1, 0xE]
_0812E2BC:
	movs r1, 0x34
	ldrsh r0, [r4, r1]
	cmp r0, r2
	beq _0812E2F6
	strh r2, [r4, 0x34]
	ldrh r1, [r4, 0x32]
	adds r0, r2, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r1, [r4, 0x30]
	adds r0, r2, 0
	bl __udivsi3
	lsls r0, 16
	movs r3, 0xE0
	lsls r3, 11
	adds r0, r3
	lsrs r2, r0, 16
	adds r0, r2, 0
	bl GetSpriteTileStartByTag
	adds r1, r4, 0
	adds r1, 0x40
	strh r0, [r1]
	adds r0, r4, 0
	bl SetSpriteSheetFrameTileNum
_0812E2F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E2A8

	thumb_func_start sub_812E300
sub_812E300: @ 812E300
	push {lr}
	ldr r0, =gUnknown_085A7D10
	movs r1, 0x58
	movs r2, 0x48
	movs r3, 0xF
	bl CreateSprite
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, =gUnknown_085A7FC0
	bl SetSubspriteTables
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E300

	thumb_func_start sub_812E33C
sub_812E33C: @ 812E33C
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r4, =gUnknown_0203AAE4
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E350
	movs r0, 0x28
	bl AllocZeroed
	str r0, [r4]
_0812E350:
	ldr r2, [r4]
	ldr r0, =gUnknown_0203AAD8
	ldr r1, [r0]
	str r1, [r2]
	movs r3, 0x80
	lsls r3, 4
	strh r3, [r2, 0x4]
	adds r0, r1, r3
	str r0, [r2, 0x8]
	strh r3, [r2, 0xC]
	movs r4, 0x80
	lsls r4, 5
	adds r0, r1, r4
	str r0, [r2, 0x10]
	strh r3, [r2, 0x14]
	movs r5, 0xC0
	lsls r5, 5
	adds r0, r1, r5
	str r0, [r2, 0x18]
	strh r3, [r2, 0x1C]
	movs r0, 0x80
	lsls r0, 6
	adds r1, r0
	str r1, [r2, 0x20]
	strh r3, [r2, 0x24]
	mov r1, sp
	ldr r0, =gUnknown_085A7D28
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	str r2, [sp, 0xC]
	movs r1, 0x8C
	lsls r1, 1
	mov r0, sp
	movs r2, 0x50
	movs r3, 0x1
	bl CreateSprite
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
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x2
	orrs r1, r3
	strb r1, [r2]
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x3F
	strb r0, [r1]
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E33C

	thumb_func_start sub_812E3E8
sub_812E3E8: @ 812E3E8
	push {r4,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r4, =gUnknown_0203AAE4
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E410
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E410:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E3E8

	thumb_func_start sub_812E424
sub_812E424: @ 812E424
	push {lr}
	adds r2, r0, 0
	movs r0, 0
	strh r0, [r2, 0x24]
	strh r0, [r2, 0x26]
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0812E46A
	movs r0, 0x8
	strh r0, [r2, 0x24]
	strh r0, [r2, 0x26]
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0812E458
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _0812E466
	b _0812E46A
_0812E458:
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	bne _0812E46A
_0812E466:
	ldr r0, =0x0000fff8
	strh r0, [r2, 0x26]
_0812E46A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E424

	thumb_func_start sub_812E474
sub_812E474: @ 812E474
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	ldr r4, =gUnknown_0203AAE8
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E490
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
_0812E490:
	ldr r2, [r4]
	ldr r0, =gUnknown_0203AAD8
	mov r10, r0
	ldr r0, [r0]
	movs r1, 0xA0
	lsls r1, 6
	adds r0, r1
	str r0, [r2]
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_085A7D40
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	str r2, [sp, 0xC]
	mov r0, sp
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0x34
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r5, =gSprites
	mov r9, r5
	adds r2, r0, r5
	ldrb r1, [r2, 0x5]
	movs r7, 0xD
	negs r7, r7
	mov r8, r7
	mov r0, r8
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r6, 0x2
	orrs r0, r6
	strb r0, [r1]
	ldr r1, =gUnknown_085A7FE0
	adds r0, r2, 0
	bl SetSubspriteTables
	ldr r5, =gUnknown_0203AB34
	ldr r0, [r5]
	adds r0, 0x49
	strb r4, [r0]
	ldr r4, =gUnknown_0203AAEC
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E510
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
_0812E510:
	ldr r2, [r4]
	mov r3, r10
	ldr r0, [r3]
	movs r4, 0xAC
	lsls r4, 6
	adds r0, r4
	str r0, [r2]
	movs r0, 0xA0
	lsls r0, 3
	strh r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_085A7D58
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	ldm r0!, {r3,r4,r7}
	stm r1!, {r3,r4,r7}
	str r2, [sp, 0xC]
	mov r0, sp
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0x54
	movs r3, 0x7
	bl CreateSprite
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	mov r7, r9
	adds r2, r0, r7
	ldrb r1, [r2, 0x5]
	mov r0, r8
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	ldr r1, =gUnknown_085A7FF4
	adds r0, r2, 0
	bl SetSubspriteTables
	ldr r0, [r5]
	adds r0, 0x4A
	strb r4, [r0]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E474

	thumb_func_start sub_812E5A8
sub_812E5A8: @ 812E5A8
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r4, =gUnknown_0203AAF0
	ldr r0, [r4]
	cmp r0, 0
	bne _0812E5BC
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
_0812E5BC:
	ldr r2, [r4]
	ldr r0, =gUnknown_0203AAD8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	str r0, [r2]
	movs r0, 0xC0
	lsls r0, 3
	strh r0, [r2, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_085A7D70
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	str r2, [sp, 0xC]
	ldr r0, =gSpriteCoordOffsetX
	ldrh r0, [r0]
	movs r1, 0xA8
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	movs r2, 0x50
	movs r3, 0x7
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	ldr r1, =gUnknown_085A8010
	bl SetSubspriteTables
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x42
	strb r4, [r0]
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E5A8

	thumb_func_start sub_812E650
sub_812E650: @ 812E650
	push {r4-r6,lr}
	movs r4, 0
	movs r5, 0
_0812E656:
	ldr r0, =gUnknown_085A7D88
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0
	movs r3, 0xA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	ldr r1, =gSprites
	adds r3, r1
	ldrb r2, [r3, 0x5]
	movs r6, 0xD
	negs r6, r6
	adds r1, r6, 0
	ands r2, r1
	movs r1, 0x4
	orrs r2, r1
	strb r2, [r3, 0x5]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r1, [r1]
	movs r2, 0x2
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	strh r5, [r3, 0x3C]
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x4B
	adds r1, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r5, 16
	movs r6, 0xA0
	lsls r6, 13
	adds r0, r6
	lsrs r5, r0, 16
	cmp r4, 0x2
	bls _0812E656
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E650

	thumb_func_start sub_812E6C4
sub_812E6C4: @ 812E6C4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203AB34
	ldr r1, [r0]
	ldrh r0, [r4, 0x3C]
	ldrh r1, [r1, 0x14]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x28
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	adds r1, 0x3B
	strh r1, [r4, 0x22]
	movs r1, 0x14
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	bl sub_812BCE8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnimIfDifferent
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E6C4

	thumb_func_start sub_812E70C
sub_812E70C: @ 812E70C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r1, 0xB8
	lsls r1, 1
	ldr r0, =gUnknown_085A7DA0
	movs r2, 0x64
	movs r3, 0x9
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r7, =gSprites
	adds r2, r0, r7
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r3, 0x2
	mov r10, r3
	mov r3, r10
	orrs r0, r3
	strb r0, [r1]
	ldrb r1, [r2, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	movs r1, 0x4
	mov r8, r1
	mov r3, r8
	orrs r0, r3
	strb r0, [r2, 0x5]
	ldr r0, =gUnknown_085A8028
	mov r9, r0
	adds r0, r2, 0
	mov r1, r9
	bl SetSubspriteTables
	ldr r6, =gUnknown_0203AB34
	ldr r0, [r6]
	adds r0, 0x4E
	strb r4, [r0]
	movs r1, 0x90
	lsls r1, 1
	ldr r0, =gUnknown_085A7DA0
	movs r2, 0x68
	movs r3, 0x4
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r2, r0, r7
	adds r1, r2, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	mov r3, r10
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, 0x5]
	ands r5, r0
	mov r0, r8
	orrs r5, r0
	strb r5, [r2, 0x5]
	adds r0, r2, 0
	mov r1, r9
	bl SetSubspriteTables
	ldr r0, [r6]
	adds r0, 0x4F
	strb r4, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E70C

	thumb_func_start sub_812E7CC
sub_812E7CC: @ 812E7CC
	push {r4,lr}
	ldr r0, =gUnknown_085A7DB8
	movs r1, 0xB8
	lsls r1, 1
	movs r2, 0x4C
	movs r3, 0xB
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r1, =gUnknown_085A803C
	bl SetSubspriteTables
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x40
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E7CC

	thumb_func_start sub_812E82C
sub_812E82C: @ 812E82C
	push {r4,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r4, 0
_0812E846:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x49
	adds r0, r4
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
	cmp r4, 0x1
	bls _0812E846
	ldr r4, =gUnknown_0203AAE8
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E878
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E878:
	ldr r4, =gUnknown_0203AAEC
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E888
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E888:
	movs r4, 0
_0812E88A:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x4B
	adds r0, r4
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
	cmp r4, 0x2
	bls _0812E88A
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E82C

	thumb_func_start sub_812E8C4
sub_812E8C4: @ 812E8C4
	push {r4,lr}
	movs r4, 0
_0812E8C8:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x4E
	adds r0, r4
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
	cmp r4, 0x1
	bls _0812E8C8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E8C4

	thumb_func_start sub_812E8F8
sub_812E8F8: @ 812E8F8
	push {r4,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x42
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r4, =gUnknown_0203AAF0
	ldr r0, [r4]
	cmp r0, 0
	beq _0812E920
	bl Free
	movs r0, 0
	str r0, [r4]
_0812E920:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E8F8

	thumb_func_start sub_812E934
sub_812E934: @ 812E934
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	ldr r0, =gUnknown_085A7DD0
	mov r10, r0
	movs r1, 0x98
	movs r2, 0x20
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r2, =gSprites
	mov r9, r2
	adds r3, r1, r2
	ldrb r2, [r3, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r1, r4, 0
	ands r1, r2
	movs r2, 0x4
	mov r8, r2
	mov r2, r8
	orrs r1, r2
	strb r1, [r3, 0x5]
	adds r5, r3, 0
	adds r5, 0x3F
	ldrb r1, [r5]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r5]
	ldr r6, =gUnknown_0203AB34
	ldr r1, [r6]
	adds r1, 0x50
	strb r0, [r1]
	movs r0, 0x8
	strh r0, [r3, 0x2E]
	ldr r0, =0x0000ffff
	strh r0, [r3, 0x30]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r3, 0x32]
	movs r5, 0x20
	strh r5, [r3, 0x3C]
	mov r0, r10
	movs r1, 0xB8
	movs r2, 0x20
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	mov r2, r9
	adds r3, r1, r2
	ldrb r1, [r3, 0x5]
	ands r4, r1
	mov r1, r8
	orrs r4, r1
	strb r4, [r3, 0x5]
	ldr r1, [r6]
	adds r1, 0x51
	strb r0, [r1]
	movs r0, 0x1
	strh r0, [r3, 0x30]
	subs r0, 0x2
	strh r0, [r3, 0x32]
	strh r5, [r3, 0x3C]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812E934

	thumb_func_start sub_812E9E8
sub_812E9E8: @ 812E9E8
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x2E]
	movs r1, 0x2E
	ldrsh r4, [r2, r1]
	cmp r4, 0
	beq _0812EA0C
	subs r0, 0x1
	movs r1, 0
	strh r0, [r2, 0x2E]
	strh r1, [r2, 0x24]
	strh r1, [r2, 0x26]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	b _0812EA3E
_0812EA0C:
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x30]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	ldrh r0, [r2, 0x32]
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x34]
	adds r0, 0x1
	strh r0, [r2, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0812EA3E
	ldrh r0, [r2, 0x3C]
	strh r0, [r2, 0x2E]
	strh r4, [r2, 0x34]
_0812EA3E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812E9E8

	thumb_func_start sub_812EA44
sub_812EA44: @ 812EA44
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gSprites
	ldr r1, =gUnknown_0203AB34
	ldr r3, [r1]
	adds r1, r3, 0
	adds r1, 0x50
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x3C]
	adds r3, 0x51
	ldrb r2, [r3]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r4
	strh r0, [r1, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EA44

	thumb_func_start sub_812EA7C
sub_812EA7C: @ 812EA7C
	push {r4,lr}
	movs r4, 0
_0812EA80:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x50
	adds r0, r4
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
	cmp r4, 0x1
	bls _0812EA80
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EA7C

	thumb_func_start sub_812EAB0
sub_812EAB0: @ 812EAB0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r0, =gUnknown_085A7DE8
	mov r8, r0
	movs r1, 0x48
	movs r2, 0x50
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	mov r9, r1
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	add r2, r9
	ldrb r3, [r2, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r1, r4, 0
	ands r1, r3
	movs r6, 0x4
	orrs r1, r6
	strb r1, [r2, 0x5]
	movs r3, 0
	movs r1, 0x1
	strh r1, [r2, 0x2E]
	strh r3, [r2, 0x38]
	movs r1, 0x10
	strh r1, [r2, 0x3A]
	movs r1, 0x8
	strh r1, [r2, 0x3C]
	ldr r5, =gUnknown_0203AB34
	ldr r1, [r5]
	adds r1, 0x52
	strb r0, [r1]
	mov r0, r8
	movs r1, 0x68
	movs r2, 0x50
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x5]
	ands r4, r2
	orrs r4, r6
	strb r4, [r1, 0x5]
	adds r1, 0x3F
	ldrb r2, [r1]
	movs r3, 0x1
	orrs r2, r3
	strb r2, [r1]
	ldr r1, [r5]
	adds r1, 0x53
	strb r0, [r1]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EAB0

	thumb_func_start sub_812EB48
sub_812EB48: @ 812EB48
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =gUnknown_085A7614
	mov r0, sp
	movs r2, 0x2
	bl memcpy
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0812EB9A
	ldrh r0, [r4, 0x3A]
	subs r0, 0x1
	strh r0, [r4, 0x3A]
	lsls r0, 16
	cmp r0, 0
	bgt _0812EB9A
	movs r0, 0x7
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r2, =0x01030000
	adds r0, r2
	lsrs r0, 16
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	add r1, sp
	ldrb r3, [r1]
	adds r1, r3, 0
	adds r2, r3, 0
	bl MultiplyInvertedPaletteRGBComponents
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r1, 0x1
	ands r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3C]
	strh r0, [r4, 0x3A]
_0812EB9A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EB48

	thumb_func_start sub_812EBAC
sub_812EBAC: @ 812EBAC
	ldr r3, =gSprites
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x52
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	strh r0, [r1, 0x3C]
	bx lr
	.pool
	thumb_func_end sub_812EBAC

	thumb_func_start sub_812EBCC
sub_812EBCC: @ 812EBCC
	push {r4,lr}
	movs r0, 0x7
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r1, =0x01030000
	adds r0, r1
	lsrs r0, 16
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl MultiplyInvertedPaletteRGBComponents
	movs r4, 0
_0812EBEA:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x52
	adds r0, r4
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
	cmp r4, 0x1
	bls _0812EBEA
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EBCC

	thumb_func_start sub_812EC20
sub_812EC20: @ 812EC20
	push {lr}
	ldr r0, =gUnknown_085A7E00
	movs r1, 0xA8
	movs r2, 0x50
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r3, [r1, 0x5]
	movs r2, 0xD
	negs r2, r2
	ands r2, r3
	movs r3, 0x4
	orrs r2, r3
	strb r2, [r1, 0x5]
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x41
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EC20

	thumb_func_start sub_812EC64
sub_812EC64: @ 812EC64
	ldr r1, =gSpriteCoordOffsetY
	ldrh r1, [r1]
	strh r1, [r0, 0x26]
	bx lr
	.pool
	thumb_func_end sub_812EC64

	thumb_func_start sub_812EC70
sub_812EC70: @ 812EC70
	push {lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x41
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EC70

	thumb_func_start sub_812EC94
sub_812EC94: @ 812EC94
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r1, =gUnknown_085A7616
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	movs r4, 0
_0812ECA4:
	ldr r0, =gSpriteCoordOffsetX
	ldrh r0, [r0]
	movs r1, 0x50
	subs r1, r0
	lsls r1, 16
	asrs r1, 16
	ldr r0, =gUnknown_085A7E18
	movs r2, 0x44
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	ldr r1, =gSprites
	adds r3, r1
	ldrb r2, [r3, 0x5]
	movs r5, 0xD
	negs r5, r5
	adds r1, r5, 0
	ands r2, r1
	movs r1, 0x4
	orrs r2, r1
	strb r2, [r3, 0x5]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	ldrb r1, [r1]
	movs r2, 0x2
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	lsls r1, r4, 1
	add r1, sp
	ldrh r1, [r1]
	strh r1, [r3, 0x2E]
	ldr r1, =gUnknown_0203AB34
	ldr r1, [r1]
	adds r1, 0x54
	adds r1, r4
	strb r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0812ECA4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EC94

	thumb_func_start sub_812ED20
sub_812ED20: @ 812ED20
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x2E]
	subs r0, 0x2
	movs r4, 0
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r1, 0x14
	bl Cos
	strh r0, [r5, 0x24]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	movs r1, 0x6
	bl Sin
	strh r0, [r5, 0x26]
	adds r1, r5, 0
	adds r1, 0x43
	strb r4, [r1]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0x7F
	ble _0812ED5A
	movs r0, 0x2
	strb r0, [r1]
_0812ED5A:
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0812ED84
	adds r3, r5, 0
	adds r3, 0x3F
	ldrb r2, [r3]
	lsls r0, r2, 31
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0
	strh r0, [r5, 0x30]
_0812ED84:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_812ED20

	thumb_func_start sub_812ED8C
sub_812ED8C: @ 812ED8C
	push {r4,lr}
	movs r4, 0
_0812ED90:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x54
	adds r0, r4
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
	cmp r4, 0x3
	bls _0812ED90
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812ED8C

	thumb_func_start sub_812EDC0
sub_812EDC0: @ 812EDC0
	push {r4,lr}
	ldr r0, =gUnknown_085A7E30
	movs r1, 0xA8
	movs r2, 0x3C
	movs r3, 0x8
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	bl InitSpriteAffineAnim
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x43
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EDC0

	thumb_func_start sub_812EE14
sub_812EE14: @ 812EE14
	push {lr}
	adds r3, r0, 0
	ldrh r2, [r3, 0x2E]
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0
	bne _0812EE36
	adds r0, r3, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812EE90
	adds r0, r2, 0x1
	strh r0, [r3, 0x2E]
	b _0812EE90
_0812EE36:
	cmp r0, 0x1
	bne _0812EE72
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	ble _0812EE90
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	movs r0, 0
	strh r0, [r3, 0x32]
	b _0812EE90
_0812EE72:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0812EE90
	movs r0, 0x1
	strh r0, [r3, 0x3C]
_0812EE90:
	ldrh r0, [r3, 0x30]
	movs r1, 0xFF
	ands r1, r0
	adds r1, 0x10
	strh r1, [r3, 0x30]
	lsrs r1, 8
	ldrh r0, [r3, 0x26]
	subs r0, r1
	strh r0, [r3, 0x26]
	pop {r0}
	bx r0
	thumb_func_end sub_812EE14

	thumb_func_start sub_812EEA8
sub_812EEA8: @ 812EEA8
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x43
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_812EEA8

	thumb_func_start sub_812EECC
sub_812EECC: @ 812EECC
	push {r4,lr}
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	adds r0, 0x43
	ldrb r0, [r0]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EECC

	thumb_func_start sub_812EF00
sub_812EF00: @ 812EF00
	push {r4,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gUnknown_085A7F98
	lsls r3, 16
	asrs r3, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r3, 0
	movs r3, 0xC
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	bl InitSpriteAffineAnim
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812EF00

	thumb_func_start sub_812EF54
sub_812EF54: @ 812EF54
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0812EF68
	movs r0, 0x1
	strh r0, [r2, 0x3C]
_0812EF68:
	pop {r0}
	bx r0
	thumb_func_end sub_812EF54

	thumb_func_start sub_812EF6C
sub_812EF6C: @ 812EF6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812EF6C

	thumb_func_start sub_812EF98
sub_812EF98: @ 812EF98
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gUnknown_085A78C8
	lsrs r1, 22
	adds r3, r1, r3
	ldr r5, [r3]
	ldr r3, =gUnknown_085A783A
	adds r4, r1, r3
	movs r6, 0
	ldrsh r4, [r4, r6]
	adds r3, 0x2
	adds r1, r3
	movs r6, 0
	ldrsh r3, [r1, r6]
	lsls r2, 16
	asrs r2, 16
	str r2, [sp]
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_812EFDC
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812EF98

	thumb_func_start sub_812EFDC
sub_812EFDC: @ 812EFDC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	adds r4, r0, 0
	mov r8, r1
	adds r1, r2, 0
	adds r2, r3, 0
	ldr r5, [sp, 0x34]
	lsls r4, 24
	lsls r5, 16
	lsrs r5, 16
	mov r9, r5
	ldr r0, =gUnknown_085A8264
	lsrs r4, 22
	adds r0, r4, r0
	mov r3, sp
	ldr r0, [r0]
	ldm r0!, {r5-r7}
	stm r3!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r3!, {r5-r7}
	ldr r0, =gUnknown_03001188
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r3, 0x10
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	lsls r0, r7, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	ldrb r0, [r2, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r2, 0x5]
	mov r0, r8
	str r0, [r2, 0x1C]
	mov r5, r9
	strh r5, [r2, 0x3A]
	movs r0, 0x1
	strh r0, [r2, 0x3C]
	ldr r0, =gUnknown_085A82CC
	adds r4, r0
	ldr r1, [r4]
	cmp r1, 0
	beq _0812F056
	adds r0, r2, 0
	bl SetSubspriteTables
_0812F056:
	adds r0, r7, 0
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_812EFDC

	thumb_func_start sub_812F078
sub_812F078: @ 812F078
	movs r1, 0
	strh r1, [r0, 0x3C]
	bx lr
	thumb_func_end sub_812F078

	thumb_func_start sub_812F080
sub_812F080: @ 812F080
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r1, =gUnknown_085A761E
	mov r0, sp
	movs r2, 0x8
	bl memcpy
	add r5, sp, 0x8
	ldr r1, =gUnknown_085A7626
	adds r0, r5, 0
	movs r2, 0x8
	bl memcpy
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF
	ble _0812F0C6
	adds r3, r4, 0
	adds r3, 0x42
	ldrb r2, [r3]
	lsls r0, r2, 26
	lsrs r0, 26
	movs r1, 0x1
	eors r1, r0
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0
	strh r0, [r4, 0x30]
_0812F0C6:
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x42
	ldrb r1, [r0]
	movs r0, 0x3F
	ands r0, r1
	cmp r0, 0
	beq _0812F0F2
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r4, 0x26]
_0812F0F2:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F080

	thumb_func_start sub_812F104
sub_812F104: @ 812F104
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3F
	ldrb r1, [r3]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r3]
	bl sub_812F080
	pop {r0}
	bx r0
	thumb_func_end sub_812F104

	thumb_func_start sub_812F11C
sub_812F11C: @ 812F11C
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3F
	ldrb r1, [r3]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	bl sub_812F080
	pop {r0}
	bx r0
	thumb_func_end sub_812F11C

	thumb_func_start sub_812F134
sub_812F134: @ 812F134
	push {lr}
	adds r3, r0, 0
	adds r3, 0x3F
	ldrb r1, [r3]
	movs r2, 0x1
	orrs r1, r2
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r3]
	bl sub_812F080
	pop {r0}
	bx r0
	thumb_func_end sub_812F134

	thumb_func_start sub_812F150
sub_812F150: @ 812F150
	push {lr}
	adds r2, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _0812F184
	cmp r0, 0x1
	bgt _0812F166
	cmp r0, 0
	beq _0812F170
	b _0812F1B4
_0812F166:
	cmp r0, 0x2
	beq _0812F194
	cmp r0, 0x3
	beq _0812F1B0
	b _0812F1B4
_0812F170:
	ldrh r0, [r2, 0x20]
	adds r0, 0x4
	strh r0, [r2, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xCF
	ble _0812F1B4
	movs r0, 0xD0
	strh r0, [r2, 0x20]
	b _0812F1A2
_0812F184:
	ldrh r0, [r2, 0x30]
	adds r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	ble _0812F1B4
	b _0812F1A2
_0812F194:
	ldrh r0, [r2, 0x20]
	adds r0, 0x4
	strh r0, [r2, 0x20]
	lsls r0, 16
	ldr r1, =0x010f0000
	cmp r0, r1
	ble _0812F1B4
_0812F1A2:
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	b _0812F1B4
	.pool
_0812F1B0:
	movs r0, 0
	strh r0, [r2, 0x3C]
_0812F1B4:
	pop {r0}
	bx r0
	thumb_func_end sub_812F150

	thumb_func_start sub_812F1B8
sub_812F1B8: @ 812F1B8
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0812F1EC
	cmp r0, 0x1
	bgt _0812F1CE
	cmp r0, 0
	beq _0812F1D8
	b _0812F216
_0812F1CE:
	cmp r0, 0x2
	beq _0812F1FC
	cmp r0, 0x3
	beq _0812F212
	b _0812F216
_0812F1D8:
	ldrh r0, [r1, 0x20]
	subs r0, 0x4
	strh r0, [r1, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD0
	bgt _0812F216
	movs r0, 0xD0
	strh r0, [r1, 0x20]
	b _0812F20A
_0812F1EC:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	ble _0812F216
	b _0812F20A
_0812F1FC:
	ldrh r0, [r1, 0x20]
	subs r0, 0x4
	strh r0, [r1, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x90
	bgt _0812F216
_0812F20A:
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _0812F216
_0812F212:
	movs r0, 0
	strh r0, [r1, 0x3C]
_0812F216:
	pop {r0}
	bx r0
	thumb_func_end sub_812F1B8

	thumb_func_start sub_812F21C
sub_812F21C: @ 812F21C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x5
	bhi _0812F2C6
	lsls r0, 2
	ldr r1, =_0812F238
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812F238:
	.4byte _0812F250
	.4byte _0812F268
	.4byte _0812F288
	.4byte _0812F29C
	.4byte _0812F2AC
	.4byte _0812F2C2
_0812F250:
	ldr r0, =gUnknown_0203AB34
	ldr r0, [r0]
	ldrb r1, [r0, 0xA]
	subs r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0812F268:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0812F2C6
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0
	strh r0, [r4, 0x30]
	b _0812F2C6
	.pool
_0812F288:
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xCF
	ble _0812F2C6
	movs r0, 0xD0
	strh r0, [r4, 0x20]
	b _0812F2BA
_0812F29C:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x5A
	ble _0812F2C6
	b _0812F2BA
_0812F2AC:
	ldrh r0, [r4, 0x20]
	adds r0, 0x4
	strh r0, [r4, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xF7
	ble _0812F2C6
_0812F2BA:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0812F2C6
_0812F2C2:
	movs r0, 0
	strh r0, [r4, 0x3C]
_0812F2C6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812F21C

	thumb_func_start sub_812F2CC
sub_812F2CC: @ 812F2CC
	push {lr}
	adds r3, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0x1
	beq _0812F2FA
	cmp r0, 0x1
	bgt _0812F2E2
	cmp r0, 0
	beq _0812F2E8
	b _0812F368
_0812F2E2:
	cmp r0, 0x2
	beq _0812F318
	b _0812F368
_0812F2E8:
	adds r2, r3, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
_0812F2FA:
	ldrh r0, [r3, 0x22]
	adds r0, 0x8
	strh r0, [r3, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6F
	ble _0812F368
	movs r0, 0x70
	strh r0, [r3, 0x22]
	movs r0, 0x10
	strh r0, [r3, 0x30]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	b _0812F368
_0812F318:
	movs r0, 0x32
	ldrsh r2, [r3, r0]
	cmp r2, 0
	bne _0812F35E
	ldrh r0, [r3, 0x22]
	ldrh r1, [r3, 0x30]
	subs r0, r1
	strh r0, [r3, 0x22]
	negs r1, r1
	strh r1, [r3, 0x30]
	ldrh r0, [r3, 0x34]
	adds r0, 0x1
	strh r0, [r3, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _0812F35E
	lsls r0, r1, 16
	asrs r0, 18
	strh r0, [r3, 0x30]
	strh r2, [r3, 0x34]
	adds r1, r0, 0
	cmp r1, 0
	bne _0812F35E
	ldrh r0, [r3, 0x2E]
	adds r0, 0x1
	strh r0, [r3, 0x2E]
	strh r1, [r3, 0x3C]
	adds r2, r3, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_0812F35E:
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	strh r0, [r3, 0x32]
_0812F368:
	pop {r0}
	bx r0
	thumb_func_end sub_812F2CC

	thumb_func_start sub_812F36C
sub_812F36C: @ 812F36C
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0812F37E
	cmp r0, 0x1
	beq _0812F394
	b _0812F3B0
_0812F37E:
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x8
	ble _0812F3B0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	b _0812F3B0
_0812F394:
	ldrh r0, [r1, 0x22]
	adds r0, 0x2
	strh r0, [r1, 0x22]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2F
	ble _0812F3B0
	movs r0, 0x30
	strh r0, [r1, 0x22]
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	movs r0, 0
	strh r0, [r1, 0x3C]
_0812F3B0:
	pop {r0}
	bx r0
	thumb_func_end sub_812F36C

	thumb_func_start sub_812F3B4
sub_812F3B4: @ 812F3B4
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0812F3C6
	cmp r0, 0x1
	beq _0812F416
	b _0812F468
_0812F3C6:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x20
	ble _0812F468
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x5
	strh r0, [r4, 0x30]
	ldrb r0, [r4, 0x1]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
	ldrh r0, [r4, 0x30]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	b _0812F468
_0812F416:
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r4, 0x30]
	subs r0, r1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bge _0812F42C
	movs r0, 0
	strh r0, [r4, 0x30]
_0812F42C:
	ldrh r0, [r4, 0x30]
	lsls r1, r0, 4
	orrs r1, r0
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x4C
	bl SetGpuReg
	ldrh r1, [r4, 0x32]
	movs r0, 0xFF
	ands r0, r1
	adds r0, 0x80
	strh r0, [r4, 0x32]
	movs r0, 0x30
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _0812F468
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	strh r1, [r4, 0x3C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
_0812F468:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_812F3B4

	thumb_func_start sub_812F470
sub_812F470: @ 812F470
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x2
	bgt _0812F4C0
	ldr r1, =gUnknown_085A8510
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3
	ble _0812F4FC
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	movs r0, 0
	strh r0, [r5, 0x32]
	b _0812F4FC
	.pool
_0812F4C0:
	ldr r1, =gUnknown_085A8510
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x18
	ble _0812F4FC
	strh r1, [r5, 0x30]
	strh r1, [r5, 0x32]
_0812F4FC:
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnimIfDifferent
	movs r0, 0
	strh r0, [r5, 0x3C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F470

	thumb_func_start sub_812F514
sub_812F514: @ 812F514
	push {r4-r6,lr}
	sub sp, 0x30
	adds r4, r0, 0
	ldr r1, =gUnknown_085A762E
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	add r6, sp, 0x10
	ldr r1, =gUnknown_085A763E
	adds r0, r6, 0
	movs r2, 0x10
	bl memcpy
	add r5, sp, 0x20
	ldr r1, =gUnknown_085A764E
	adds r0, r5, 0
	movs r2, 0x10
	bl memcpy
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0812F58C
	cmp r0, 0x1
	bgt _0812F55C
	cmp r0, 0
	beq _0812F562
	b _0812F5D8
	.pool
_0812F55C:
	cmp r0, 0x2
	beq _0812F5A0
	b _0812F5D8
_0812F562:
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	adds r0, r6, r0
	ldrh r0, [r0]
	strh r0, [r4, 0x26]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0812F58C:
	ldrh r0, [r4, 0x30]
	subs r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0812F5D8
	b _0812F5D2
_0812F5A0:
	ldrh r0, [r4, 0x24]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	cmp r1, 0
	ble _0812F5AE
	subs r0, 0x4
	b _0812F5B4
_0812F5AE:
	cmp r1, 0
	bge _0812F5B6
	adds r0, 0x4
_0812F5B4:
	strh r0, [r4, 0x24]
_0812F5B6:
	ldrh r0, [r4, 0x26]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	cmp r1, 0
	ble _0812F5C4
	subs r0, 0x4
	b _0812F5CA
_0812F5C4:
	cmp r1, 0
	bge _0812F5CC
	adds r0, 0x4
_0812F5CA:
	strh r0, [r4, 0x26]
_0812F5CC:
	ldr r0, [r4, 0x24]
	cmp r0, 0
	bne _0812F5D8
_0812F5D2:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_0812F5D8:
	add sp, 0x30
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_812F514

	thumb_func_start sub_812F5E0
sub_812F5E0: @ 812F5E0
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r1, =gUnknown_085A765E
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _0812F602
	adds r0, r1, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0xC
	strh r0, [r4, 0x30]
_0812F602:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	lsls r0, 1
	add r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0812F63C
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
_0812F63C:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F5E0

	thumb_func_start sub_812F648
sub_812F648: @ 812F648
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _0812F694
	cmp r0, 0x1
	bgt _0812F660
	cmp r0, 0
	beq _0812F66A
	b _0812F76C
_0812F660:
	cmp r0, 0x2
	beq _0812F6E0
	cmp r0, 0x3
	beq _0812F71C
	b _0812F76C
_0812F66A:
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x5C
	movs r0, 0x2F
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x3F
	strh r0, [r1]
	subs r1, 0x4
	ldr r0, =0x00002088
	strh r0, [r1]
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0812F694:
	ldrh r0, [r5, 0x30]
	adds r2, r0, 0x2
	strh r2, [r5, 0x30]
	adds r0, 0xB2
	strh r0, [r5, 0x32]
	movs r1, 0xF0
	subs r1, r2
	strh r1, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD0
	ble _0812F6B0
	movs r0, 0xD0
	strh r0, [r5, 0x32]
_0812F6B0:
	movs r1, 0x34
	ldrsh r0, [r5, r1]
	cmp r0, 0xCF
	bgt _0812F6BC
	movs r0, 0xD0
	strh r0, [r5, 0x34]
_0812F6BC:
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldrh r0, [r5, 0x32]
	lsls r0, 8
	ldrh r1, [r5, 0x34]
	orrs r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x33
	ble _0812F76C
	b _0812F75E
	.pool
_0812F6E0:
	ldr r6, =gUnknown_0203AB34
	ldr r0, [r6]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0812F76C
	ldr r1, =SpriteCallbackDummy
	movs r4, 0
	str r4, [sp]
	movs r0, 0x5
	movs r2, 0xD0
	movs r3, 0x74
	bl sub_812DF68
	ldr r2, [r6]
	adds r1, r2, 0
	adds r1, 0x58
	ldr r0, =0x0000c0e0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0xD1
	lsls r0, 7
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x2F
	strh r0, [r1]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	strh r4, [r5, 0x30]
_0812F71C:
	ldrh r0, [r5, 0x30]
	adds r2, r0, 0x2
	strh r2, [r5, 0x30]
	adds r0, 0xC2
	strh r0, [r5, 0x32]
	movs r1, 0xE0
	subs r1, r2
	strh r1, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD0
	ble _0812F738
	movs r0, 0xD0
	strh r0, [r5, 0x32]
_0812F738:
	movs r1, 0x34
	ldrsh r0, [r5, r1]
	cmp r0, 0xCF
	bgt _0812F744
	movs r0, 0xD0
	strh r0, [r5, 0x34]
_0812F744:
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	ldrh r0, [r5, 0x32]
	lsls r0, 8
	ldrh r1, [r5, 0x34]
	orrs r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	strh r0, [r1]
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0xF
	ble _0812F76C
_0812F75E:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	adds r1, r2, 0
	adds r1, 0x5C
	movs r0, 0x3F
	strh r0, [r1]
_0812F76C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F648

	thumb_func_start nullsub_101
nullsub_101: @ 812F780
	bx lr
	thumb_func_end nullsub_101

	thumb_func_start sub_812F784
sub_812F784: @ 812F784
	push {lr}
	movs r0, 0x4C
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_812F784

	thumb_func_start sub_812F794
sub_812F794: @ 812F794
	push {r4,lr}
	ldr r0, =gUnknown_085A8520
	ldr r4, [r0]
	movs r0, 0x6
	bl IndexOfSpritePaletteTag
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 17
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F794

	thumb_func_start sub_812F7C0
sub_812F7C0: @ 812F7C0
	ldr r0, =gUnknown_0203AB34
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x58
	movs r0, 0xF0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0xA0
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x5C
	movs r1, 0x3F
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_812F7C0

	thumb_func_start sub_812F7E4
sub_812F7E4: @ 812F7E4
	push {r4-r6,lr}
	bl sub_812F8A0
	ldr r4, =gUnknown_0203AAD4
	movs r0, 0xC8
	lsls r0, 6
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gSlotMachineReelTime_Gfx
	bl LZDecompressWram
	ldr r4, =gUnknown_0203AAD8
	movs r0, 0xD8
	lsls r0, 6
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gUnknown_085A858C
	bl LZDecompressWram
	ldr r4, =gUnknown_0203AB30
	movs r0, 0xB0
	bl AllocZeroed
	str r0, [r4]
	movs r3, 0
	ldr r5, =gUnknown_085A8334
	adds r6, r4, 0
_0812F822:
	ldr r2, [r4]
	lsls r1, r3, 3
	adds r2, r1, r2
	adds r1, r5
	ldr r0, [r1]
	str r0, [r2]
	ldrh r0, [r1, 0x4]
	strh r0, [r2, 0x4]
	ldrh r0, [r1, 0x6]
	strh r0, [r2, 0x6]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x15
	bls _0812F822
	ldr r3, [r6]
	adds r2, r3, 0
	adds r2, 0x88
	ldr r0, =gUnknown_0203AAD4
	ldr r1, [r0]
	movs r4, 0xA0
	lsls r4, 4
	adds r0, r1, r4
	str r0, [r2]
	adds r2, 0x8
	movs r4, 0xA0
	lsls r4, 5
	adds r0, r1, r4
	str r0, [r2]
	adds r2, 0x8
	movs r4, 0xB0
	lsls r4, 5
	adds r0, r1, r4
	str r0, [r2]
	adds r0, r3, 0
	adds r0, 0xA0
	movs r2, 0xC8
	lsls r2, 5
	adds r1, r2
	str r1, [r0]
	adds r0, r3, 0
	bl LoadSpriteSheets
	ldr r0, =gUnknown_085A8544
	bl LoadSpritePalettes
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F7E4

	thumb_func_start sub_812F8A0
sub_812F8A0: @ 812F8A0
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203AB2C
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r5]
	ldr r4, =gUnknown_0203AAE0
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	adds r3, r0, 0
	movs r1, 0
	adds r6, r4, 0
	ldr r0, =gUnknown_085A83E4
	ldr r4, [r0]
_0812F8C2:
	movs r2, 0
	adds r1, 0x1
_0812F8C6:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, 0x1
	cmp r2, 0x1F
	bls _0812F8C6
	lsls r0, r1, 24
	lsrs r1, r0, 24
	cmp r1, 0x3F
	bls _0812F8C2
	ldr r0, [r5]
	ldr r1, [r6]
	str r1, [r0]
	movs r1, 0x80
	lsls r1, 4
	strh r1, [r0, 0x4]
	movs r1, 0x11
	strh r1, [r0, 0x6]
	bl LoadSpriteSheet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F8A0

	thumb_func_start sub_812F908
sub_812F908: @ 812F908
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203AAC8
	movs r5, 0x88
	lsls r5, 6
	adds r0, r5, 0
	bl Alloc
	adds r1, r0, 0
	str r1, [r4]
	ldr r0, =gSlotMachineMenu_Gfx
	bl LZDecompressWram
	ldr r1, [r4]
	movs r0, 0x2
	adds r2, r5, 0
	movs r3, 0
	bl LoadBgTiles
	ldr r0, =gSlotMachineMenu_Pal
	movs r1, 0
	movs r2, 0xA0
	bl LoadPalette
	ldr r0, =gUnknown_085A8524
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F908

	thumb_func_start sub_812F958
sub_812F958: @ 812F958
	push {lr}
	bl sub_812F968
	bl sub_812F980
	pop {r0}
	bx r0
	thumb_func_end sub_812F958

	thumb_func_start sub_812F968
sub_812F968: @ 812F968
	push {lr}
	ldr r1, =gSlotMachineMenu_Tilemap
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F968

	thumb_func_start sub_812F980
sub_812F980: @ 812F980
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r1, 0x4
	ldr r0, =gUnknown_0203AAD0
	mov r8, r0
_0812F98E:
	movs r0, 0
	lsls r1, 16
	mov r9, r1
_0812F994:
	mov r2, r8
	ldr r1, [r2]
	mov r2, r9
	asrs r6, r2, 16
	lsls r4, r0, 16
	asrs r4, 16
	adds r5, r6, r4
	adds r3, r5, 0
	adds r3, 0xA0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0x2
	movs r2, 0xD0
	lsls r2, 1
	adds r3, r5, r2
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0x4
	adds r3, r5, 0
	adds r3, 0xC0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r2, r8
	ldr r1, [r2]
	adds r1, 0x6
	movs r0, 0xC0
	lsls r0, 1
	adds r7, r0, 0
	adds r3, r5, r7
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	adds r4, 0x1
	lsls r4, 16
	lsrs r0, r4, 16
	asrs r4, 16
	cmp r4, 0x3
	ble _0812F994
	mov r2, r8
	ldr r1, [r2]
	adds r1, 0x8
	adds r3, r6, 0
	adds r3, 0xC0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0xA
	adds r3, r6, r7
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	movs r0, 0x7
_0812FA32:
	mov r2, r8
	ldr r1, [r2]
	adds r1, 0xC
	lsls r4, r0, 16
	asrs r4, 16
	lsls r3, r4, 5
	mov r0, r9
	asrs r5, r0, 16
	adds r3, r5, r3
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x3
	movs r2, 0x2
	bl LoadBgTilemap
	adds r4, 0x1
	lsls r4, 16
	lsrs r0, r4, 16
	asrs r4, 16
	cmp r4, 0xB
	ble _0812FA32
	adds r0, r5, 0x5
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x11
	ble _0812F98E
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812F980

	thumb_func_start sub_812FA78
sub_812FA78: @ 812FA78
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, [sp, 0x10]
	ldr r6, =gUnknown_0203AADC
	ldr r0, [r6]
	strh r1, [r0]
	ldr r1, [r6]
	strh r2, [r1, 0x2]
	strh r3, [r1, 0x4]
	strh r5, [r1, 0x6]
	lsls r4, 16
	asrs r5, r4, 16
	movs r0, 0xF0
	lsls r0, 17
	adds r4, r0
	lsrs r4, 16
	movs r0, 0x2
	movs r2, 0x2
	adds r3, r4, 0
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, 0x2
	ldr r0, =0x000001e1
	adds r3, r5, r0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, 0x4
	movs r0, 0x80
	lsls r0, 2
	adds r3, r5, r0
	lsls r3, 16
	lsrs r3, 16
	movs r0, 0x2
	movs r2, 0x2
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, 0x6
	ldr r0, =0x00000201
	adds r5, r0
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0x2
	movs r2, 0x2
	adds r3, r5, 0
	bl LoadBgTilemap
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FA78

	thumb_func_start sub_812FAF4
sub_812FAF4: @ 812FAF4
	push {lr}
	ldr r1, =gUnknown_08DCEC70
	movs r2, 0xA0
	lsls r2, 3
	movs r0, 0x2
	movs r3, 0
	bl LoadBgTilemap
	movs r0, 0x3
	bl HideBg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FAF4

	thumb_func_start sub_812FB14
sub_812FB14: @ 812FB14
	ldr r1, =gUnknown_03001188
	ldr r0, =gUnknown_0203AAF4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, =gUnknown_0203AAF8
	ldr r0, [r0]
	str r0, [r1, 0x4]
	ldr r0, =gUnknown_0203AAFC
	ldr r0, [r0]
	str r0, [r1, 0x8]
	ldr r0, =gUnknown_0203AB04
	ldr r0, [r0]
	str r0, [r1, 0xC]
	ldr r0, =gUnknown_0203AB08
	ldr r0, [r0]
	str r0, [r1, 0x10]
	ldr r0, =gUnknown_0203AB18
	ldr r0, [r0]
	str r0, [r1, 0x14]
	ldr r0, =gUnknown_0203AB1C
	ldr r0, [r0]
	str r0, [r1, 0x18]
	ldr r0, =gUnknown_0203AB20
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	ldr r0, =gUnknown_0203AB24
	ldr r0, [r0]
	str r0, [r1, 0x20]
	ldr r0, =gUnknown_0203AB28
	ldr r0, [r0]
	str r0, [r1, 0x24]
	ldr r0, =gUnknown_0203AB00
	ldr r0, [r0]
	str r0, [r1, 0x28]
	str r0, [r1, 0x2C]
	str r0, [r1, 0x30]
	str r0, [r1, 0x34]
	ldr r0, =gUnknown_0203AB0C
	ldr r0, [r0]
	str r0, [r1, 0x38]
	str r0, [r1, 0x3C]
	str r0, [r1, 0x40]
	str r0, [r1, 0x44]
	str r0, [r1, 0x48]
	ldr r0, =gUnknown_0203AB10
	ldr r0, [r0]
	str r0, [r1, 0x4C]
	str r0, [r1, 0x50]
	str r0, [r1, 0x54]
	ldr r0, =gUnknown_0203AB14
	ldr r0, [r0]
	str r0, [r1, 0x58]
	str r0, [r1, 0x5C]
	str r0, [r1, 0x60]
	movs r0, 0
	str r0, [r1, 0x64]
	bx lr
	.pool
	thumb_func_end sub_812FB14

	thumb_func_start sub_812FBC4
sub_812FBC4: @ 812FBC4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r4, =gUnknown_0203AAF4
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r6, =gUnknown_0203AAD4
	ldr r1, [r6]
	str r1, [r0]
	movs r5, 0xC0
	lsls r5, 3
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AAF8
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	adds r1, r5
	str r1, [r0]
	movs r1, 0x80
	lsls r1, 2
	mov r8, r1
	mov r2, r8
	strh r2, [r0, 0x4]
	ldr r4, =gUnknown_0203AAFC
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, 0x80
	lsls r3, 4
	adds r1, r3
	str r1, [r0]
	mov r4, r8
	strh r4, [r0, 0x4]
	ldr r4, =gUnknown_0203AB00
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, 0xA0
	lsls r2, 4
	adds r1, r2
	str r1, [r0]
	mov r3, r8
	strh r3, [r0, 0x4]
	ldr r4, =gUnknown_0203AB04
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, 0xC0
	lsls r4, 4
	adds r1, r4
	str r1, [r0]
	movs r5, 0xC0
	lsls r5, 2
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AB08
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	str r1, [r0]
	movs r1, 0x80
	lsls r1, 3
	strh r1, [r0, 0x4]
	ldr r4, =gUnknown_0203AB0C
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, 0xA0
	lsls r3, 5
	adds r1, r3
	str r1, [r0]
	mov r4, r8
	strh r4, [r0, 0x4]
	ldr r4, =gUnknown_0203AB10
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, 0xB0
	lsls r2, 5
	adds r1, r2
	str r1, [r0]
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AB14
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, 0xC8
	lsls r3, 5
	adds r1, r3
	str r1, [r0]
	strh r5, [r0, 0x4]
	ldr r4, =gUnknown_0203AB18
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, 0xE0
	lsls r4, 5
	adds r2, r1, r4
	str r2, [r0]
	mov r2, r8
	strh r2, [r0, 0x4]
	movs r3, 0xF0
	lsls r3, 5
	adds r1, r3
	str r1, [r0, 0x8]
	strh r2, [r0, 0xC]
	ldr r4, =gUnknown_0203AB1C
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, 0x80
	lsls r4, 6
	adds r1, r4
	str r1, [r0]
	movs r1, 0xA0
	lsls r1, 2
	strh r1, [r0, 0x4]
	ldr r4, =gUnknown_0203AB20
	movs r0, 0x28
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, 0x8A
	lsls r3, 6
	adds r1, r2, r3
	str r1, [r0]
	movs r3, 0x80
	strh r3, [r0, 0x4]
	movs r4, 0x8C
	lsls r4, 6
	adds r1, r2, r4
	str r1, [r0, 0x8]
	strh r3, [r0, 0xC]
	adds r4, 0x80
	adds r1, r2, r4
	str r1, [r0, 0x10]
	strh r3, [r0, 0x14]
	adds r4, 0x80
	adds r1, r2, r4
	str r1, [r0, 0x18]
	strh r3, [r0, 0x1C]
	movs r1, 0x92
	lsls r1, 6
	adds r2, r1
	str r2, [r0, 0x20]
	strh r3, [r0, 0x24]
	ldr r4, =gUnknown_0203AB24
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, 0x98
	lsls r3, 6
	adds r1, r2, r3
	str r1, [r0]
	movs r1, 0x90
	lsls r1, 3
	strh r1, [r0, 0x4]
	movs r4, 0xAA
	lsls r4, 6
	adds r2, r4
	str r2, [r0, 0x8]
	strh r1, [r0, 0xC]
	ldr r4, =gUnknown_0203AB28
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, 0xBC
	lsls r3, 6
	adds r1, r2, r3
	str r1, [r0]
	movs r1, 0xC0
	lsls r1, 1
	strh r1, [r0, 0x4]
	movs r4, 0xC2
	lsls r4, 6
	adds r2, r4
	str r2, [r0, 0x8]
	strh r1, [r0, 0xC]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_812FBC4

	.align 2, 0 @ Don't pad with nop.
