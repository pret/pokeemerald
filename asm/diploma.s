	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8177874
sub_8177874: @ 8177874
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl copy_pal_bg_faded_to_pal_ram
	pop {r0}
	bx r0
	thumb_func_end sub_8177874

	thumb_func_start sub_8177888
sub_8177888: @ 8177888
	push {r4,r5,lr}
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
	ldr r1, =0x040000d4
	add r0, sp, 0x4
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r5, 0
	str r5, [sp, 0x8]
	add r0, sp, 0x8
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add r0, sp, 0x4
	strh r5, [r0]
	str r0, [r1]
	movs r0, 0xA0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x81000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	bl remove_some_task
	bl ResetTasks
	bl ResetAllObjectData
	bl sub_80A1A74
	bl ResetObjectPaletteAllocator
	ldr r0, =gUnknown_085E7088
	movs r1, 0
	movs r2, 0x40
	bl gpu_pal_apply
	ldr r4, =gUnknown_0203BCF0
	movs r0, 0x80
	lsls r0, 5
	bl Alloc
	str r0, [r4]
	bl sub_8177B44
	bl sub_8177B9C
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_085E7804
	str r5, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
_0817797C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0817797C
	ldr r0, =gUnknown_085E70C8
	ldr r1, =gUnknown_0203BCF0
	ldr r1, [r1]
	bl LZDecompressWram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	bl pokedex_diploma_something
	movs r4, 0x1
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0
	bl sub_80A2A20
	str r5, [sp]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl pal_fade_maybe
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_8177874
	bl SetVBlankCallback
	ldr r0, =sub_8177A08
	bl SetMainCallback2
	ldr r0, =sub_8177A20
	movs r1, 0
	bl CreateTask
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177888

	thumb_func_start sub_8177A08
sub_8177A08: @ 8177A08
	push {lr}
	bl RunTasks
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
	bl fade_and_return_progress_probably
	pop {r0}
	bx r0
	thumb_func_end sub_8177A08

	thumb_func_start sub_8177A20
sub_8177A20: @ 8177A20
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08177A40
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8177A50
	str r0, [r1]
_08177A40:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177A20

	thumb_func_start sub_8177A50
sub_8177A50: @ 8177A50
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08177A82
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl pal_fade_maybe
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8177A98
	str r1, [r0]
_08177A82:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177A50

	thumb_func_start sub_8177A98
sub_8177A98: @ 8177A98
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_02037FD4
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08177AC2
	ldr r0, =gUnknown_0203BCF0
	ldr r0, [r0]
	bl Free
	bl FreeAllWindowBuffers
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =sub_80861E8
	bl SetMainCallback2
_08177AC2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177A98

	thumb_func_start pokedex_diploma_something
pokedex_diploma_something: @ 8177AD4
	push {r4,lr}
	bl sub_80C0944
	lsls r0, 16
	cmp r0, 0
	beq _08177AFC
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0x14
	bl SetGpuReg
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EE855
	bl StringCopy
	b _08177B0C
	.pool
_08177AFC:
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	ldr r0, =gStringVar1
	ldr r1, =gUnknown_085EE84F
	bl StringCopy
_08177B0C:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EE85E
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	bl sub_8177BCC
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokedex_diploma_something

	thumb_func_start sub_8177B44
sub_8177B44: @ 8177B44
	push {lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E81FC
	movs r0, 0
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0203BCF0
	ldr r1, [r0]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177B44

	thumb_func_start sub_8177B9C
sub_8177B9C: @ 8177B9C
	push {lr}
	ldr r0, =gUnknown_085E8204
	bl InitWindows
	bl DeactivateAllTextPrinters
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl gpu_pal_apply
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177B9C

	thumb_func_start sub_8177BCC
sub_8177BCC: @ 8177BCC
	push {r4-r6,lr}
	sub sp, 0x18
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gUnknown_085E8214
	add r0, sp, 0x14
	movs r2, 0x3
	bl memcpy
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177BCC

	.align 2, 0 @ Don't pad with nop.
