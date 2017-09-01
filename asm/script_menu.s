	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start Multichoice
@ bool8 Multichoice(u8 x, u8 y, u8 menuId, bool8 noCancelling)
Multichoice: @ 80E1E08
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r4, r3, 24
	ldr r0, =sub_80E2058
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E1E4C
	ldr r0, =gUnknown_020375F0
	movs r1, 0xFF
	strh r1, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl DoMultichoice
	movs r0, 0x1
	b _080E1E4E
	.pool
_080E1E4C:
	movs r0, 0
_080E1E4E:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end Multichoice

	thumb_func_start sub_80E1E58
sub_80E1E58: @ 80E1E58
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r4, [sp, 0x1C]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80E2058
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E1EA8
	ldr r1, =gUnknown_020375F0
	movs r0, 0xFF
	strh r0, [r1]
	str r4, [sp]
	mov r0, r8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl DoMultichoice
	movs r0, 0x1
	b _080E1EAA
	.pool
_080E1EA8:
	movs r0, 0
_080E1EAA:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80E1E58

	thumb_func_start sub_80E1EB8
sub_80E1EB8: @ 80E1EB8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	b _080E1EEC
_080E1EC0:
	cmp r1, 0xFD
	bne _080E1EE4
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _080E1EEC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	bl StringLength
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x1
	b _080E1EEC
	.pool
_080E1EE4:
	adds r4, 0x1
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_080E1EEC:
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _080E1EC0
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E1EB8

	thumb_func_start DoMultichoice
@ void DoMultichoice(u8 x, u8 y, u8 menuId, bool8 noCancelling)
DoMultichoice: @ 80E1EFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r4, [sp, 0x28]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp]
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	ldr r1, =gUnknown_0858B760
	lsls r0, r2, 3
	adds r0, r1
	ldrb r6, [r0, 0x4]
	ldr r0, [r0]
	mov r8, r0
	movs r1, 0
	cmp r1, r6
	bge _080E1F4C
	mov r5, r8
	adds r4, r6, 0
_080E1F3C:
	ldr r0, [r5]
	bl display_text_and_get_width
	adds r1, r0, 0
	adds r5, 0x8
	subs r4, 0x1
	cmp r4, 0
	bne _080E1F3C
_080E1F4C:
	adds r0, r1, 0
	bl convert_pixel_width_to_tile_width
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80E2D5C
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r3, r6, 25
	lsrs r3, 24
	adds r0, r7, 0
	mov r1, r9
	adds r2, r4, 0
	bl CreateWindowFromRect
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r8
	bl PrintMenuTable
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, [sp, 0x4]
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, [sp]
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r10
	bl sub_80E1FBC
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoMultichoice

	thumb_func_start sub_80E1FBC
sub_80E1FBC: @ 80E1FBC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r4, r3, 24
	ldr r1, =gUnknown_02039F90
	movs r0, 0x2
	strb r0, [r1]
	movs r2, 0
	ldr r6, =sub_80E2058
	ldr r5, =gUnknown_0858BB68
	movs r3, 0xC
_080E1FE6:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _080E1FF0
	strb r3, [r1]
_080E1FF0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bls _080E1FE6
	adds r0, r6, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	mov r0, r8
	strh r0, [r1, 0x10]
	cmp r7, 0x3
	bls _080E202C
	movs r0, 0x1
	b _080E202E
	.pool
_080E202C:
	movs r0, 0
_080E202E:
	strh r0, [r1, 0x12]
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	mov r1, r9
	strh r1, [r0, 0x14]
	strh r4, [r0, 0x16]
	adds r0, r4, 0
	bl sub_80E2A94
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E1FBC

	thumb_func_start sub_80E2058
sub_80E2058: @ 80E2058
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E20FC
	ldr r1, =gUnknown_02039F90
	ldrb r0, [r1]
	cmp r0, 0
	beq _080E2090
	subs r0, 0x1
	strb r0, [r1]
	b _080E20FC
	.pool
_080E2090:
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080E209E
	bl ProcessMenuInputNoWrapAround
	b _080E20A2
_080E209E:
	bl ProcessMenuInput
_080E20A2:
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _080E20B8
	ldrb r0, [r5, 0xE]
	bl sub_80E2A94
_080E20B8:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _080E20FC
	adds r0, 0x1
	cmp r1, r0
	bne _080E20E8
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080E20FC
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020375F0
	movs r0, 0x7F
	strh r0, [r1]
	b _080E20EC
	.pool
_080E20E8:
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
_080E20EC:
	ldrb r0, [r5, 0xC]
	bl sub_80E2A78
	adds r0, r6, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_080E20FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2058

	thumb_func_start yes_no_box
yes_no_box: @ 80E2108
	push {r4,lr}
	ldr r4, =task_yes_no_maybe
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E2138
	ldr r1, =gUnknown_020375F0
	movs r0, 0xFF
	strh r0, [r1]
	bl sub_8197930
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	movs r0, 0x1
	b _080E213A
	.pool
_080E2138:
	movs r0, 0
_080E213A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end yes_no_box

	thumb_func_start sub_80E2140
sub_80E2140: @ 80E2140
	push {lr}
	ldr r0, =gUnknown_020375F0
	ldrh r0, [r0]
	cmp r0, 0xFF
	beq _080E2154
	movs r0, 0x1
	b _080E2156
	.pool
_080E2154:
	movs r0, 0
_080E2156:
	pop {r1}
	bx r1
	thumb_func_end sub_80E2140

	thumb_func_start task_yes_no_maybe
task_yes_no_maybe: @ 80E215C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0x4
	bgt _080E2180
	adds r0, r2, 0x1
	strh r0, [r1, 0xC]
	b _080E21C4
	.pool
_080E2180:
	bl sub_8198C58
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080E21A4
	cmp r1, r0
	bgt _080E219C
	subs r0, 0x1
	cmp r1, r0
	beq _080E21C4
	b _080E21BA
_080E219C:
	cmp r1, 0
	beq _080E21B4
	cmp r1, 0x1
	bne _080E21BA
_080E21A4:
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020375F0
	movs r0, 0
	b _080E21B8
	.pool
_080E21B4:
	ldr r1, =gUnknown_020375F0
	movs r0, 0x1
_080E21B8:
	strh r0, [r1]
_080E21BA:
	adds r0, r4, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_080E21C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_yes_no_maybe

	thumb_func_start sub_80E21D0
sub_80E21D0: @ 80E21D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r4, [sp, 0x30]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	lsls r2, 24
	lsrs r5, r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x8]
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	ldr r0, =sub_80E2308
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E2210
	movs r0, 0
	b _080E22E8
	.pool
_080E2210:
	ldr r0, =gUnknown_020375F0
	movs r1, 0xFF
	strh r1, [r0]
	movs r2, 0
	movs r6, 0
	ldr r1, =gUnknown_0858B760
	lsls r5, 3
	adds r0, r5, r1
	str r5, [sp, 0xC]
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bge _080E2246
	mov r8, r1
_080E222A:
	mov r0, r8
	adds r4, r5, r0
	ldr r1, [r4]
	lsls r0, r6, 3
	adds r0, r1
	ldr r0, [r0]
	adds r1, r2, 0
	bl display_text_and_get_width
	adds r2, r0, 0
	adds r6, 0x1
	ldrb r4, [r4, 0x4]
	cmp r6, r4
	blt _080E222A
_080E2246:
	adds r0, r2, 0
	bl convert_pixel_width_to_tile_width
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r1, r10
	muls r1, r5
	mov r8, r1
	adds r0, r7, 0
	bl sub_80E2D5C
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gUnknown_0858B760
	mov r9, r2
	ldr r0, [sp, 0xC]
	add r9, r0
	mov r1, r9
	ldrb r0, [r1, 0x4]
	mov r1, r10
	bl __udivsi3
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =sub_80E2308
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	mov r2, sp
	ldrh r2, [r2, 0x8]
	strh r2, [r4, 0x10]
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r3, r6, 25
	lsrs r3, 24
	adds r0, r7, 0
	ldr r1, [sp, 0x4]
	mov r2, r8
	bl CreateWindowFromRect
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r4, 0x14]
	lsls r5, 27
	lsrs r5, 24
	mov r2, r9
	ldr r1, [r2]
	str r1, [sp]
	adds r1, r5, 0
	mov r2, r10
	adds r3, r6, 0
	bl sub_81997AC
	ldrb r0, [r4, 0x14]
	movs r1, 0
	str r1, [sp]
	adds r1, r5, 0
	mov r2, r10
	adds r3, r6, 0
	bl sub_8199944
	ldrb r0, [r4, 0x14]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0x1
_080E22E8:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80E21D0

	thumb_func_start sub_80E2308
sub_80E2308: @ 80E2308
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	bl sub_8199334
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _080E2360
	adds r0, 0x1
	cmp r1, r0
	bne _080E234C
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080E2360
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020375F0
	movs r0, 0x7F
	strh r0, [r1]
	b _080E2350
	.pool
_080E234C:
	ldr r0, =gUnknown_020375F0
	strh r1, [r0]
_080E2350:
	ldrb r0, [r5, 0xC]
	bl sub_80E2A78
	adds r0, r4, 0
	bl DestroyTask
	bl script_env_2_enable_and_set_ctx_running
_080E2360:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2308

	thumb_func_start sp109_CreatePCMenu
@ bool sp109_CreatePCMenu()
sp109_CreatePCMenu: @ 80E236C
	push {lr}
	ldr r0, =sub_80E2058
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E2394
	ldr r1, =gUnknown_020375F0
	movs r0, 0xFF
	strh r0, [r1]
	bl CreatePCMenu
	movs r0, 0x1
	b _080E2396
	.pool
_080E2394:
	movs r0, 0
_080E2396:
	pop {r1}
	bx r1
	thumb_func_end sp109_CreatePCMenu

	thumb_func_start CreatePCMenu
CreatePCMenu: @ 80E239C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	movs r7, 0x8
	movs r5, 0
	movs r4, 0
	ldr r6, =gUnknown_0858BB70
_080E23AC:
	ldm r6!, {r0}
	adds r1, r5, 0
	bl display_text_and_get_width
	adds r5, r0, 0
	adds r4, 0x1
	cmp r4, 0x3
	bls _080E23AC
	ldr r6, =0x00000864
	adds r0, r6, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _080E23D4
	ldr r0, =gUnknown_085EB18B
	adds r1, r5, 0
	bl display_text_and_get_width
	adds r5, r0, 0
_080E23D4:
	adds r0, r5, 0
	bl convert_pixel_width_to_tile_width
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r6, 0
	bl FlagGet
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _080E2448
	movs r0, 0x4
	mov r8, r0
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0x8
	bl CreateWindowFromRect
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r2, =gUnknown_085EB18B
	movs r0, 0x21
	str r0, [sp]
	movs r5, 0xFF
	str r5, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r3, r7, 0
	bl Print
	ldr r2, =gUnknown_085EB198
	movs r0, 0x31
	str r0, [sp]
	str r5, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r3, r7, 0
	bl Print
	b _080E247A
	.pool
_080E2448:
	movs r0, 0x3
	mov r8, r0
	movs r0, 0
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0x6
	bl CreateWindowFromRect
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r2, =gUnknown_085EB198
	movs r0, 0x21
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r3, r7, 0
	bl Print
_080E247A:
	ldr r0, =0x000008ab
	bl FlagGet
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080E24B0
	ldr r2, =gUnknown_085EB176
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r3, r7, 0
	bl Print
	b _080E24C6
	.pool
_080E24B0:
	ldr r2, =gUnknown_085EB169
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r3, r7, 0
	bl Print
_080E24C6:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EB183
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r7, 0
	movs r3, 0x11
	bl sub_819A024
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	adds r0, r6, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	mov r1, r8
	adds r2, r6, 0
	movs r3, 0x1
	bl sub_80E1FBC
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreatePCMenu

	thumb_func_start sub_80E2514
sub_80E2514: @ 80E2514
	push {lr}
	sub sp, 0x10
	movs r0, 0
	movs r1, 0x1
	bl sub_819786C
	ldr r2, =gUnknown_0827266F
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2514

	thumb_func_start sub_80E2548
sub_80E2548: @ 80E2548
	push {lr}
	ldr r0, =sub_80E2058
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E2570
	ldr r1, =gUnknown_020375F0
	movs r0, 0xFF
	strh r0, [r1]
	bl sub_80E2578
	movs r0, 0x1
	b _080E2572
	.pool
_080E2570:
	movs r0, 0
_080E2572:
	pop {r1}
	bx r1
	thumb_func_end sub_80E2548

	thumb_func_start sub_80E2578
sub_80E2578: @ 80E2578
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	movs r5, 0
	movs r4, 0
	ldr r3, =gUnknown_03001124
	movs r2, 0xFF
_080E258A:
	adds r0, r4, r3
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080E258A
	movs r0, 0x1
	movs r1, 0
	bl GetFontAttribute
	ldr r0, =gUnknown_020375E0
	ldrh r1, [r0]
	cmp r1, 0
	bne _080E25D2
	ldr r4, =gUnknown_03001124
	adds r0, r5, r4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0xE8
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _080E25D2
	adds r0, r5, r4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E25D2:
	ldr r0, =0x00000113
	movs r1, 0x1
	bl sub_80D6724
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E2630
	ldr r0, =0x000008b3
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E2630
	ldr r2, =gUnknown_020375E0
	ldrh r0, [r2]
	cmp r0, 0
	bne _080E2606
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E2606:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080E2630
	movs r4, 0xD7
	lsls r4, 1
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080E2630
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl FlagSet
_080E2630:
	movs r0, 0xB9
	lsls r0, 1
	movs r1, 0x1
	bl sub_80D6724
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E2690
	movs r0, 0x8E
	lsls r0, 4
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E2690
	ldr r2, =gUnknown_020375E0
	ldrh r0, [r2]
	cmp r0, 0
	bne _080E2668
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x3
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E2668:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080E2690
	ldr r4, =0x000001db
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080E2690
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x3
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl FlagSet
_080E2690:
	ldr r0, =0x00000173
	movs r1, 0x1
	bl sub_80D6724
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E26EC
	ldr r0, =0x000008d5
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E26EC
	ldr r2, =gUnknown_020375E0
	ldrh r0, [r2]
	cmp r0, 0
	bne _080E26C4
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E26C4:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080E26EC
	ldr r4, =0x000001af
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080E26EC
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl FlagSet
_080E26EC:
	movs r0, 0xBC
	lsls r0, 1
	movs r1, 0x1
	bl sub_80D6724
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E274C
	ldr r0, =0x000008d6
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E274C
	ldr r2, =gUnknown_020375E0
	ldrh r0, [r2]
	cmp r0, 0
	bne _080E2722
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x5
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E2722:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080E274C
	movs r4, 0xD8
	lsls r4, 1
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080E274C
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x5
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	bl FlagSet
_080E274C:
	ldr r0, =gUnknown_03001124
	adds r0, r5, r0
	movs r1, 0x6
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_020375E0
	ldrh r0, [r0]
	cmp r0, 0
	bne _080E276E
	movs r0, 0xE8
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
_080E276E:
	adds r7, r5, 0
	cmp r7, 0x7
	bne _080E27A4
	ldr r1, =gUnknown_020375E0
	movs r0, 0xB
	strh r0, [r1]
	bl sub_813A128
	b _080E2860
	.pool
_080E27A4:
	movs r1, 0
	movs r4, 0
	lsls r6, r7, 25
	subs r0, r7, 0x1
	mov r9, r0
	ldr r5, =gUnknown_0858BB80
_080E27B0:
	ldr r0, =gUnknown_03001124
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080E27C6
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	bl display_text_and_get_width
	adds r1, r0, 0
_080E27C6:
	adds r4, 0x1
	cmp r4, 0x6
	bls _080E27B0
	adds r0, r1, 0
	bl convert_pixel_width_to_tile_width
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1C
	subs r0, r2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x6
	subs r1, r7
	lsls r1, 25
	lsrs r1, 24
	lsrs r3, r6, 24
	bl CreateWindowFromRect
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	movs r5, 0
	movs r4, 0
	ldr r0, =gUnknown_0858BB80
	mov r8, r0
_080E2802:
	ldr r0, =gUnknown_03001124
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _080E2834
	lsls r0, 2
	add r0, r8
	ldr r2, [r0]
	lsls r0, r5, 4
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E2834:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _080E2802
	mov r0, r9
	lsls r2, r0, 24
	lsrs r2, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	adds r0, r6, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	adds r1, r7, 0
	adds r2, r6, 0
	movs r3, 0x8
	bl sub_80E1FBC
_080E2860:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2578

	thumb_func_start sub_80E2878
sub_80E2878: @ 80E2878
	push {lr}
	ldr r2, =gUnknown_020375F0
	ldrh r0, [r2]
	cmp r0, 0x7F
	beq _080E288C
	ldr r0, =gUnknown_03001124
	ldrh r1, [r2]
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r2]
_080E288C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2878

	thumb_func_start task_picbox
task_picbox: @ 80E2898
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080E28F8
	cmp r0, 0x1
	bgt _080E28C0
	cmp r0, 0
	beq _080E28DE
	b _080E28F8
	.pool
_080E28C0:
	cmp r0, 0x2
	beq _080E28CA
	cmp r0, 0x3
	beq _080E28EC
	b _080E28F8
_080E28CA:
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r1, [r4, 0xC]
	bl sub_80B6070
_080E28DE:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _080E28F8
	.pool
_080E28EC:
	ldrb r0, [r4, 0x12]
	bl sub_80E2A78
	adds r0, r5, 0
	bl DestroyTask
_080E28F8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end task_picbox

	thumb_func_start sub_80E2900
sub_80E2900: @ 80E2900
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r4, =task_picbox
	adds r0, r4, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080E29B8
	lsls r1, r7, 19
	movs r0, 0xA0
	lsls r0, 14
	adds r1, r0
	asrs r1, 16
	lsls r2, r6, 19
	adds r2, r0
	asrs r2, 16
	mov r0, r8
	movs r3, 0
	bl sub_80B5F84
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x8
	movs r3, 0x8
	bl CreateWindowFromRect
	ldr r1, =gTasks
	lsls r3, r4, 2
	adds r3, r4
	lsls r3, 3
	adds r3, r1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r3, 0x12]
	strh r1, [r3, 0x8]
	mov r0, r8
	strh r0, [r3, 0xA]
	strh r5, [r3, 0xC]
	ldr r4, =gSprites
	lsls r1, r5, 4
	adds r1, r5
	lsls r1, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =SpriteCallbackDummy
	str r2, [r0]
	adds r1, r4
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r0, [r3, 0x12]
	movs r1, 0x1
	bl SetStandardWindowBorderStyle
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	b _080E29BA
	.pool
_080E29B8:
	movs r0, 0
_080E29BA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80E2900

	thumb_func_start picbox_close
picbox_close: @ 80E29C4
	push {lr}
	ldr r0, =task_picbox
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080E29F4
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	ldr r0, =sub_80E29FC
	b _080E29F6
	.pool
_080E29F4:
	movs r0, 0
_080E29F6:
	pop {r1}
	bx r1
	thumb_func_end picbox_close

	thumb_func_start sub_80E29FC
sub_80E29FC: @ 80E29FC
	push {lr}
	ldr r0, =task_picbox
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _080E2A14
	movs r0, 0
	b _080E2A16
	.pool
_080E2A14:
	movs r0, 0x1
_080E2A16:
	pop {r1}
	bx r1
	thumb_func_end sub_80E29FC

	thumb_func_start CreateWindowFromRect
CreateWindowFromRect: @ 80E2A1C
	push {r4,r5,lr}
	sub sp, 0x20
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsls r5, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x80
	lsls r0, 17
	adds r4, r0
	lsrs r4, 24
	adds r5, r0
	lsrs r5, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x64
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_8198A50
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	add r0, sp, 0x18
	bl AddWindow
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	adds r0, r4, 0
	add sp, 0x20
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CreateWindowFromRect

	thumb_func_start sub_80E2A78
sub_80E2A78: @ 80E2A78
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8198070
	adds r0, r4, 0
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80E2A78

	thumb_func_start sub_80E2A94
sub_80E2A94: @ 80E2A94
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x4A
	cmp r0, 0x5
	bhi _080E2B70
	lsls r0, 2
	ldr r1, =_080E2AB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E2AB0:
	.4byte _080E2B40
	.4byte _080E2B08
	.4byte _080E2AD8
	.4byte _080E2AC8
	.4byte _080E2AE8
	.4byte _080E2AF8
_080E2AC8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBAC
	b _080E2B12
	.pool
_080E2AD8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BB9C
	b _080E2B12
	.pool
_080E2AE8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBBC
	b _080E2B12
	.pool
_080E2AF8:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBCC
	b _080E2B12
	.pool
_080E2B08:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBEC
_080E2B12:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	b _080E2B70
	.pool
_080E2B40:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gUnknown_0858BBE0
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
_080E2B70:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2A94

	thumb_func_start sp106_CreateStartMenu
sp106_CreateStartMenu: @ 80E2B7C
	push {lr}
	ldr r0, =sub_80E2058
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080E2BA4
	ldr r1, =gUnknown_020375F0
	movs r0, 0xFF
	strh r0, [r1]
	bl CreateStartMenu
	movs r0, 0x1
	b _080E2BA6
	.pool
_080E2BA4:
	movs r0, 0
_080E2BA6:
	pop {r1}
	bx r1
	thumb_func_end sp106_CreateStartMenu

	thumb_func_start CreateStartMenu
CreateStartMenu: @ 80E2BAC
	push {r4-r6,lr}
	sub sp, 0xC
	movs r0, 0x15
	movs r1, 0
	movs r2, 0x7
	movs r3, 0x12
	bl CreateWindowFromRect
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r2, =gUnknown_085EB25C
	movs r0, 0x9
	str r0, [sp]
	movs r5, 0xFF
	str r5, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r2, =gUnknown_085EB264
	movs r0, 0x19
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r2, =gUnknown_085EB26C
	movs r0, 0x29
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r2, =gUnknown_085EB270
	movs r0, 0x39
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	movs r0, 0x49
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r2, =gUnknown_085EB279
	movs r0, 0x59
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r2, =gUnknown_085EB27E
	movs r0, 0x69
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	ldr r2, =gUnknown_085EB285
	movs r0, 0x79
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x8
	bl Print
	movs r0, 0x10
	str r0, [sp]
	movs r0, 0x8
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x9
	bl sub_81983AC
	movs r0, 0
	movs r1, 0x8
	adds r2, r4, 0
	movs r3, 0x56
	bl sub_80E2CC4
	adds r0, r4, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateStartMenu

	thumb_func_start sub_80E2CC4
sub_80E2CC4: @ 80E2CC4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r1, =gUnknown_02039F90
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, =sub_80E2058
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r4, [r1, 0x10]
	strh r0, [r1, 0x12]
	strh r5, [r1, 0x14]
	strh r6, [r1, 0x16]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E2CC4

	thumb_func_start display_text_and_get_width_internal
display_text_and_get_width_internal: @ 80E2D10
	push {lr}
	sub sp, 0x40
	adds r1, r0, 0
	mov r0, sp
	bl StringExpandPlaceholders
	movs r0, 0x1
	mov r1, sp
	movs r2, 0
	bl GetStringWidth
	add sp, 0x40
	pop {r1}
	bx r1
	thumb_func_end display_text_and_get_width_internal

	thumb_func_start display_text_and_get_width
display_text_and_get_width: @ 80E2D2C
	push {r4,lr}
	adds r4, r1, 0
	bl display_text_and_get_width_internal
	cmp r0, r4
	bge _080E2D3A
	adds r0, r4, 0
_080E2D3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end display_text_and_get_width

	thumb_func_start convert_pixel_width_to_tile_width
convert_pixel_width_to_tile_width: @ 80E2D40
	push {lr}
	adds r1, r0, 0
	adds r0, 0x9
	cmp r0, 0
	bge _080E2D4C
	adds r0, 0x7
_080E2D4C:
	asrs r0, 3
	adds r0, 0x1
	cmp r0, 0x1C
	ble _080E2D56
	movs r0, 0x1C
_080E2D56:
	pop {r1}
	bx r1
	thumb_func_end convert_pixel_width_to_tile_width

	thumb_func_start sub_80E2D5C
sub_80E2D5C: @ 80E2D5C
	push {lr}
	adds r2, r0, 0
	adds r0, r2, r1
	cmp r0, 0x1C
	ble _080E2D70
	movs r0, 0x1C
	subs r2, r0, r1
	cmp r2, 0
	bge _080E2D70
	movs r2, 0
_080E2D70:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80E2D5C

	.align 2, 0 @ Don't pad with nop.
