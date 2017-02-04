	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start c2_clear_save_data_screen_2
c2_clear_save_data_screen_2: @ 817ACC8
	push {lr}
	bl sub_817AE00
	lsls r0, 24
	cmp r0, 0
	beq _0817ACDC
	ldr r0, =sub_817ACE4
	movs r1, 0
	bl CreateTask
_0817ACDC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_clear_save_data_screen_2

	thumb_func_start sub_817ACE4
sub_817ACE4: @ 817ACE4
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldr r2, =gUnknown_085EFA8F
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	ldr r0, =gUnknown_085F06D8
	movs r1, 0x2
	movs r2, 0xE
	movs r3, 0x1
	bl CreateYesNoMenu
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_817AD40
	str r1, [r0]
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817ACE4

	thumb_func_start sub_817AD40
sub_817AD40: @ 817AD40
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8198C58
	lsls r0, 24
	asrs r4, r0, 24
	cmp r4, 0
	beq _0817AD68
	cmp r4, 0
	bgt _0817AD62
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0817ADA0
	b _0817ADB2
_0817AD62:
	cmp r4, 0x1
	beq _0817ADA0
	b _0817ADB2
_0817AD68:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gUnknown_085EFAAA
	movs r0, 0x1
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl Print
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_817ADC0
	str r1, [r0]
	b _0817ADB2
	.pool
_0817ADA0:
	movs r0, 0x5
	bl audio_play
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =sub_817AFD4
	bl SetMainCallback2
_0817ADB2:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817AD40

	thumb_func_start sub_817ADC0
sub_817ADC0: @ 817ADC0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl calls_flash_erase_block
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =sub_817AFD4
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817ADC0

	thumb_func_start sub_817ADE4
sub_817ADE4: @ 817ADE4
	push {lr}
	bl RunTasks
	bl fade_and_return_progress_probably
	pop {r0}
	bx r0
	thumb_func_end sub_817ADE4

	thumb_func_start sub_817ADF4
sub_817ADF4: @ 817ADF4
	push {lr}
	bl copy_pal_bg_faded_to_pal_ram
	pop {r0}
	bx r0
	thumb_func_end sub_817ADF4

	thumb_func_start sub_817AE00
sub_817AE00: @ 817AE00
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0817AE18
	cmp r0, 0x1
	bne _0817AE18
	b _0817AFA4
_0817AE18:
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
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
	add r0, sp, 0x4
	movs r4, 0
	strh r4, [r0]
	ldr r1, =0x040000d4
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0
	str r2, [sp, 0x8]
	add r0, sp, 0x8
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add r0, sp, 0x4
	strh r2, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl sub_80A1A74
	ldr r2, =gUnknown_02037714
	ldr r0, =0x00007fff
	strh r0, [r2]
	ldr r1, =gUnknown_02037B14
	strh r0, [r1]
	ldr r0, =0x00003945
	strh r0, [r2, 0x2]
	strh r0, [r1, 0x2]
	movs r1, 0
	ldr r3, =0x06000020
	ldr r0, =0x00001111
	adds r2, r0, 0
_0817AED4:
	lsls r0, r1, 1
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xF
	bls _0817AED4
	movs r1, 0
	ldr r4, =0x0600f000
	movs r3, 0x1
	ldr r2, =0x000003ff
_0817AEEC:
	lsls r0, r1, 1
	adds r0, r4
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bls _0817AEEC
	bl ResetTasks
	bl ResetAllObjectData
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085F06C0
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	bl sub_817B02C
	ldr r0, =0x0000ffff
	str r0, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl pal_fade_maybe
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_817ADF4
	bl SetVBlankCallback
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _0817AFC8
	.pool
_0817AFA4:
	bl fade_and_return_progress_probably
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817AFC8
	ldr r0, =sub_817ADE4
	bl SetMainCallback2
	movs r0, 0x1
	b _0817AFCA
	.pool
_0817AFC8:
	movs r0, 0
_0817AFCA:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_817AE00

	thumb_func_start sub_817AFD4
sub_817AFD4: @ 817AFD4
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _0817AFEA
	cmp r0, 0x1
	beq _0817B008
_0817AFEA:
	ldr r0, =0x0000ffff
	str r0, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	movs r0, 0x1
	strb r0, [r4]
	b _0817B020
	.pool
_0817B008:
	bl fade_and_return_progress_probably
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817B020
	bl FreeAllWindowBuffers
	bl DoSoftReset
_0817B020:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817AFD4

	thumb_func_start sub_817B02C
sub_817B02C: @ 817B02C
	push {lr}
	ldr r0, =gUnknown_085F06C8
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0xE0
	bl sub_80987D4
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817B02C

	.align 2, 0 @ Don't pad with nop.
