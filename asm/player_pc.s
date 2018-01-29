	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start NewGameInitPCItems
NewGameInitPCItems: @ 816ADF4
	push {r4-r6,lr}
	movs r4, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	movs r1, 0x32
	bl ClearItemSlots
	ldr r1, =gUnknown_085DFEFC
	ldrh r0, [r1]
	cmp r0, 0
	beq _0816AE48
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _0816AE48
	adds r5, r1, 0
	adds r6, r5, 0x2
_0816AE1A:
	lsls r1, r4, 2
	adds r0, r1, r5
	ldrh r0, [r0]
	adds r1, r6
	ldrh r1, [r1]
	bl AddPCItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816AE48
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, r4, 2
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, 0
	beq _0816AE48
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, 0
	bne _0816AE1A
_0816AE48:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end NewGameInitPCItems

	thumb_func_start sub_816AE58
sub_816AE58: @ 816AE58
	push {lr}
	ldr r1, =gUnknown_0203BCB0
	ldr r0, =gUnknown_085DFED4
	str r0, [r1]
	ldr r1, =gUnknown_0203BCB4
	movs r0, 0x4
	strb r0, [r1]
	ldr r0, =TaskDummy
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gText_WhatWouldYouLike
	ldr r2, =sub_816AED8
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AE58

	thumb_func_start sub_816AE98
sub_816AE98: @ 816AE98
	push {lr}
	ldr r1, =gUnknown_0203BCB0
	ldr r0, =gUnknown_085DFED8
	str r0, [r1]
	ldr r1, =gUnknown_0203BCB4
	movs r0, 0x3
	strb r0, [r1]
	ldr r0, =TaskDummy
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gText_WhatWouldYouLike
	ldr r2, =sub_816AED8
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AE98

	thumb_func_start sub_816AED8
sub_816AED8: @ 816AED8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r0, =gUnknown_0203BCB4
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, 0x3
	bne _0816AF0C
	ldr r0, =gUnknown_085DFF24
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	b _0816AF12
	.pool
_0816AF0C:
	ldr r0, =gUnknown_085DFF24
	ldr r1, [r0, 0xC]
	ldr r0, [r0, 0x8]
_0816AF12:
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r5, =gUnknown_085DFEB4
	ldr r4, =gUnknown_0203BCB0
	ldr r1, [r4]
	mov r0, r8
	ldrb r2, [r0]
	adds r0, r5, 0
	bl sub_81DB3D8
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r6, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r6, 0x8]
	mov r2, r8
	ldrb r1, [r2]
	ldr r3, [r4]
	adds r2, r5, 0
	bl sub_81995E4
	ldrb r0, [r6, 0x8]
	mov r2, r8
	ldrb r1, [r2]
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816AF98
	str r1, [r0]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AED8

	thumb_func_start sub_816AF98
sub_816AF98: @ 816AF98
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gUnknown_0203BCB4
	ldrb r0, [r0]
	cmp r0, 0x3
	bls _0816AFC0
	bl ProcessMenuInput
	b _0816AFC4
	.pool
_0816AFC0:
	bl ProcessMenuInputNoWrapAround
_0816AFC4:
	lsls r0, 24
	lsrs r0, 24
	lsls r0, 24
	asrs r5, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _0816B04C
	adds r0, 0x1
	cmp r5, r0
	bne _0816B014
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x8]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4, 0x8]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816B148
	str r1, [r0]
	b _0816B04C
	.pool
_0816B014:
	ldrb r0, [r4, 0x8]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4, 0x8]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r2, =gUnknown_085DFEB4
	ldr r0, =gUnknown_0203BCB0
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 3
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
_0816B04C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816AF98

	thumb_func_start sub_816B060
sub_816B060: @ 816B060
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gText_WhatWouldYouLike
	ldr r2, =sub_816AED8
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B060

	thumb_func_start task_pc_itemstorage
task_pc_itemstorage: @ 816B07C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_816B190
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816B248
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_pc_itemstorage

	thumb_func_start sub_816B0A8
sub_816B0A8: @ 816B0A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	bl sub_816B510
	ldr r5, =gUnknown_0203BCB8
	movs r1, 0
	strb r0, [r5, 0x5]
	lsls r0, 24
	cmp r0, 0
	bne _0816B0D8
	ldr r1, =gText_NoMailHere
	ldr r2, =sub_816B060
	adds r0, r4, 0
	bl DisplayItemMessageOnField
	b _0816B12A
	.pool
_0816B0D8:
	strh r1, [r5]
	strh r1, [r5, 0x2]
	movs r0, 0xFF
	strb r0, [r5, 0x9]
	bl sub_816B54C
	adds r0, r4, 0
	bl sub_816B4C0
	ldrb r0, [r5, 0x5]
	bl sub_81D1C44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816B120
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_816B5F8
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_816B674
	str r0, [r1]
	b _0816B12A
	.pool
_0816B120:
	ldr r1, =gText_NoMailHere
	ldr r2, =sub_816B060
	adds r0, r6, 0
	bl DisplayItemMessageOnField
_0816B12A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B0A8

	thumb_func_start sub_816B138
sub_816B138: @ 816B138
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8126B2C
	pop {r0}
	bx r0
	thumb_func_end sub_816B138

	thumb_func_start sub_816B148
sub_816B148: @ 816B148
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203BCB4
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0816B180
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0816B174
	ldr r0, =LittlerootTown_BrendansHouse_2F_EventScript_1F863F
	bl ScriptContext1_SetupScript
	b _0816B184
	.pool
_0816B174:
	ldr r0, =LittlerootTown_MaysHouse_2F_EventScript_1F958F
	bl ScriptContext1_SetupScript
	b _0816B184
	.pool
_0816B180:
	bl EnableBothScriptContexts
_0816B184:
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816B148

	thumb_func_start sub_816B190
sub_816B190: @ 816B190
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gUnknown_085DFF24
	ldr r1, [r0, 0x14]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r6, =gUnknown_085DFEDC
	adds r0, r6, 0
	movs r1, 0x4
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r4, 0x8]
	movs r1, 0x4
	adds r2, r6, 0
	bl PrintMenuTable
	ldrb r0, [r4, 0x8]
	movs r1, 0x4
	adds r2, r5, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_085DFEA4
	lsls r5, 2
	adds r5, r0
	ldr r0, [r5]
	bl sub_816B21C
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B190

	thumb_func_start sub_816B21C
sub_816B21C: @ 816B21C
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816B21C

	thumb_func_start sub_816B248
sub_816B248: @ 816B248
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r5, r0, 24
	bl ProcessMenuInput
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r4, 24
	asrs r4, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0816B298
	adds r0, 0x1
	cmp r4, r0
	beq _0816B2B4
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_085DFEDC
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r6, 0
	bl _call_via_r1
	b _0816B2C0
	.pool
_0816B298:
	lsls r1, r5, 24
	lsls r0, r2, 24
	asrs r2, r0, 24
	cmp r1, r0
	beq _0816B2C0
	ldr r0, =gUnknown_085DFEA4
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	bl sub_816B21C
	b _0816B2C0
	.pool
_0816B2B4:
	movs r0, 0x5
	bl PlaySE
	adds r0, r6, 0
	bl sub_816B4A4
_0816B2C0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_816B248

	thumb_func_start sub_816B2C8
sub_816B2C8: @ 816B2C8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_816B2F0
	str r0, [r1]
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B2C8

	thumb_func_start sub_816B2F0
sub_816B2F0: @ 816B2F0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816B310
	bl overworld_free_bg_tilemaps
	bl sub_81AAC14
	adds r0, r4, 0
	bl DestroyTask
_0816B310:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B2F0

	thumb_func_start sub_816B31C
sub_816B31C: @ 816B31C
	push {lr}
	ldr r0, =gFieldCallback
	ldr r1, =mapldr_080EBC0C
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B31C

	thumb_func_start mapldr_080EBC0C
mapldr_080EBC0C: @ 816B33C
	push {lr}
	bl sub_81973A4
	movs r0, 0
	movs r1, 0x1
	bl sub_81973C4
	ldr r0, =sub_816B368
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_816B190
	bl pal_fill_black
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_080EBC0C

	thumb_func_start sub_816B368
sub_816B368: @ 816B368
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816B388
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_816B248
	str r0, [r1]
_0816B388:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B368

	thumb_func_start sub_816B398
sub_816B398: @ 816B398
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_80D6CE4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2]
	cmp r0, 0
	beq _0816B3C4
	adds r0, r5, 0
	movs r1, 0
	bl sub_816B430
	b _0816B3D4
	.pool
_0816B3C4:
	adds r0, r5, 0
	bl sub_816B4DC
	ldr r1, =gText_NoItems
	ldr r2, =task_pc_itemstorage
	adds r0, r5, 0
	bl DisplayItemMessageOnField
_0816B3D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B398

	thumb_func_start sub_816B3E4
sub_816B3E4: @ 816B3E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_80D6CE4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x2]
	cmp r0, 0
	beq _0816B410
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_816B430
	b _0816B420
	.pool
_0816B410:
	adds r0, r5, 0
	bl sub_816B4DC
	ldr r1, =gText_NoItems
	ldr r2, =task_pc_itemstorage
	adds r0, r5, 0
	bl DisplayItemMessageOnField
_0816B420:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B3E4

	thumb_func_start sub_816B430
sub_816B430: @ 816B430
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	ldr r6, =gTasks + 0x8
	adds r0, r5, r6
	strh r1, [r0, 0x6]
	adds r0, r4, 0
	bl sub_816B4DC
	ldr r1, =gUnknown_0203BCB8
	movs r0, 0
	strh r0, [r1]
	strh r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	adds r0, r4, 0
	bl sub_816B4C0
	bl sub_816BC14
	bl gpu_pal_allocator_reset__manage_upper_four
	bl LoadListMenuArrowsGfx
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	bl sub_8122344
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	subs r6, 0x8
	adds r5, r6
	ldr r0, =sub_816C158
	str r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B430

	thumb_func_start sub_816B4A4
sub_816B4A4: @ 816B4A4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_816B4DC
	adds r0, r4, 0
	bl sub_816B060
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816B4A4

	thumb_func_start sub_816B4C0
sub_816B4C0: @ 816B4C0
	push {lr}
	ldr r1, =gUnknown_0203BCB8
	ldrb r0, [r1, 0x5]
	cmp r0, 0x7
	bls _0816B4D4
	movs r0, 0x8
	b _0816B4D6
	.pool
_0816B4D4:
	adds r0, 0x1
_0816B4D6:
	strb r0, [r1, 0x4]
	pop {r0}
	bx r0
	thumb_func_end sub_816B4C0

	thumb_func_start sub_816B4DC
sub_816B4DC: @ 816B4DC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0x8]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4, 0x8]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B4DC

	thumb_func_start sub_816B510
sub_816B510: @ 816B510
	push {r4,lr}
	movs r2, 0
	movs r1, 0x6
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	movs r4, 0xB0
	lsls r4, 6
_0816B51E:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r3, r0
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0
	beq _0816B534
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_0816B534:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _0816B51E
	adds r0, r2, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816B510

	thumb_func_start sub_816B54C
sub_816B54C: @ 816B54C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	movs r2, 0x6
_0816B55A:
	adds r1, r2, 0x1
	lsls r0, r1, 24
	lsrs r4, r0, 24
	mov r8, r1
	cmp r4, 0xF
	bhi _0816B5D4
	ldr r0, =gSaveBlock1Ptr
	mov r10, r0
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	mov r12, r0
	ldr r6, =0x00002be0
_0816B574:
	mov r1, r10
	ldr r1, [r1]
	mov r9, r1
	mov r2, r9
	add r2, r12
	movs r3, 0xB0
	lsls r3, 6
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, 0
	bne _0816B5CA
	adds r2, r6
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	lsls r3, r4, 3
	adds r3, r4
	lsls r3, 2
	mov r5, r9
	adds r0, r5, r3
	adds r0, r6
	ldm r0!, {r1,r5,r7}
	stm r2!, {r1,r5,r7}
	ldm r0!, {r1,r5,r7}
	stm r2!, {r1,r5,r7}
	ldm r0!, {r1,r5,r7}
	stm r2!, {r1,r5,r7}
	mov r7, r10
	ldr r1, [r7]
	adds r1, r3
	adds r1, r6
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
_0816B5CA:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _0816B574
_0816B5D4:
	mov r3, r8
	lsls r0, r3, 24
	lsrs r2, r0, 24
	cmp r2, 0xE
	bls _0816B55A
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B54C

	thumb_func_start sub_816B5F8
sub_816B5F8: @ 816B5F8
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0
	bl sub_81D1C84
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_81D1C84
	ldr r6, =gText_Mailbox
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0x40
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r6, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r4, =gUnknown_0203BCB8
	adds r0, r4, 0
	bl sub_81D1DC0
	ldr r2, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x12]
	adds r0, r4, 0
	bl sub_81D1E90
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B5F8

	thumb_func_start sub_816B674
sub_816B674: @ 816B674
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	mov r9, r0
	ldr r0, =gTasks + 0x8
	mov r10, r0
	mov r4, r9
	add r4, r10
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816B71E
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r4, 0xA]
	ldr r7, =gUnknown_0203BCBA
	subs r1, r7, 0x2
	mov r8, r1
	adds r1, r7, 0
	mov r2, r8
	bl sub_81AE860
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _0816B6D4
	adds r0, 0x1
	cmp r6, r0
	bne _0816B6EA
	b _0816B71E
	.pool
_0816B6D4:
	movs r0, 0x5
	bl PlaySE
	mov r1, r8
	ldrb r0, [r1, 0x9]
	bl RemoveScrollIndicatorArrowPair
	adds r0, r5, 0
	bl sub_816B798
	b _0816B71E
_0816B6EA:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81D1D04
	movs r0, 0x1
	bl sub_81D1D04
	ldrb r0, [r4, 0xA]
	adds r1, r7, 0
	mov r2, r8
	bl sub_81AE6C8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	mov r1, r8
	ldrb r0, [r1, 0x9]
	bl RemoveScrollIndicatorArrowPair
	mov r0, r10
	subs r0, 0x8
	add r0, r9
	ldr r1, =sub_816B730
	str r1, [r0]
_0816B71E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B674

	thumb_func_start sub_816B730
sub_816B730: @ 816B730
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gStringVar1
	ldr r2, =gSaveBlock1Ptr
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1]
	adds r0, 0x6
	ldrh r1, [r1, 0x2]
	adds r0, r1
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r1, r0
	ldr r0, =0x00002bf2
	adds r1, r0
	adds r0, r5, 0
	bl StringCopy
	adds r0, r5, 0
	movs r1, 0
	bl sub_81DB554
	ldr r5, =gStringVar4
	ldr r1, =gText_WhatToDoWithVar1sMail
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_816B7DC
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B730

	thumb_func_start sub_816B798
sub_816B798: @ 816B798
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0
	bl sub_81D1D04
	movs r0, 0x1
	bl sub_81D1D04
	ldrb r0, [r4, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	bl sub_81D1EC0
	adds r0, r5, 0
	bl sub_816B060
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B798

	thumb_func_start sub_816B7DC
sub_816B7DC: @ 816B7DC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r0, 0x2
	bl sub_81D1C84
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r2, =gUnknown_085DFF04
	adds r0, r4, 0
	movs r1, 0x4
	bl PrintMenuTable
	adds r0, r4, 0
	movs r1, 0x4
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816B82C
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B7DC

	thumb_func_start sub_816B82C
sub_816B82C: @ 816B82C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl ProcessMenuInput_other
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0816B86E
	adds r0, 0x1
	cmp r4, r0
	bne _0816B858
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816BBD4
	b _0816B86E
_0816B858:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_085DFF04
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r6, 0
	bl _call_via_r1
_0816B86E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B82C

	thumb_func_start sub_816B878
sub_816B878: @ 816B878
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816B8A4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B878

	thumb_func_start sub_816B8A4
sub_816B8A4: @ 816B8A4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816B8E6
	bl sub_81D1EC0
	bl overworld_free_bg_tilemaps
	ldr r2, =gSaveBlock1Ptr
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1]
	adds r0, 0x6
	ldrh r1, [r1, 0x2]
	adds r0, r1
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =0x00002be0
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r1, =sub_816B900
	movs r2, 0x1
	bl ReadMail
	adds r0, r4, 0
	bl DestroyTask
_0816B8E6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B8A4

	thumb_func_start sub_816B900
sub_816B900: @ 816B900
	push {lr}
	ldr r0, =gFieldCallback
	ldr r1, =pal_fill_for_maplights_or_black
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B900

	thumb_func_start pal_fill_for_maplights_or_black
pal_fill_for_maplights_or_black: @ 816B920
	push {r4,lr}
	bl sub_81973A4
	ldr r0, =task00_080EBBDC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203BCB8
	ldrb r0, [r0, 0x5]
	bl sub_81D1C44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816B954
	adds r0, r4, 0
	bl sub_816B5F8
	b _0816B95A
	.pool
_0816B954:
	adds r0, r4, 0
	bl DestroyTask
_0816B95A:
	bl pal_fill_black
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pal_fill_for_maplights_or_black

	thumb_func_start task00_080EBBDC
task00_080EBBDC: @ 816B964
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80ABDFC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816B984
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_816B674
	str r0, [r1]
_0816B984:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_080EBBDC

	thumb_func_start sub_816B994
sub_816B994: @ 816B994
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gText_MessageWillBeLost
	ldr r2, =sub_816B9B0
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B994

	thumb_func_start sub_816B9B0
sub_816B9B0: @ 816B9B0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816B9D8
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816B9B0

	thumb_func_start sub_816B9D8
sub_816B9D8: @ 816B9D8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl ProcessMenuInputNoWrap_
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _0816BA04
	cmp r0, r1
	ble _0816BA10
	cmp r0, 0
	beq _0816B9FC
	cmp r0, 0x1
	beq _0816BA0A
	b _0816BA10
_0816B9FC:
	adds r0, r4, 0
	bl sub_816BA18
	b _0816BA10
_0816BA04:
	movs r0, 0x5
	bl PlaySE
_0816BA0A:
	adds r0, r4, 0
	bl sub_816BAAC
_0816BA10:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816B9D8

	thumb_func_start sub_816BA18
sub_816BA18: @ 816BA18
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSaveBlock1Ptr
	ldr r4, =gUnknown_0203BCB8
	ldrh r1, [r4]
	adds r1, 0x6
	ldrh r0, [r4, 0x2]
	adds r1, r0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x00002be0
	adds r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldrh r0, [r5, 0x20]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	bne _0816BA68
	ldr r1, =gText_BagIsFull
	ldr r2, =sub_816BBD4
	adds r0, r6, 0
	bl DisplayItemMessageOnField
	b _0816BA9C
	.pool
_0816BA68:
	ldr r1, =gText_MailToBagMessageErased
	ldr r2, =sub_816BBD4
	adds r0, r6, 0
	bl DisplayItemMessageOnField
	adds r0, r5, 0
	bl ClearMailStruct
	bl sub_816B54C
	ldrb r0, [r4, 0x5]
	subs r0, 0x1
	strb r0, [r4, 0x5]
	ldrb r1, [r4, 0x5]
	ldrb r0, [r4, 0x4]
	ldrh r2, [r4, 0x2]
	adds r0, r2
	cmp r1, r0
	bge _0816BA96
	cmp r2, 0
	beq _0816BA96
	subs r0, r2, 0x1
	strh r0, [r4, 0x2]
_0816BA96:
	adds r0, r6, 0
	bl sub_816B4C0
_0816BA9C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BA18

	thumb_func_start sub_816BAAC
sub_816BAAC: @ 816BAAC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_816BBD4
	pop {r0}
	bx r0
	thumb_func_end sub_816BAAC

	thumb_func_start sub_816BABC
sub_816BABC: @ 816BABC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl CalculatePlayerPartyCount
	lsls r0, 24
	cmp r0, 0
	bne _0816BAD4
	adds r0, r4, 0
	bl sub_816BBB8
	b _0816BAEA
_0816BAD4:
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_816BAF8
	str r0, [r1]
_0816BAEA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BABC

	thumb_func_start sub_816BAF8
sub_816BAF8: @ 816BAF8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0816BB1C
	bl sub_81D1EC0
	bl overworld_free_bg_tilemaps
	bl sub_81B8448
	adds r0, r4, 0
	bl DestroyTask
_0816BB1C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BAF8

	thumb_func_start sub_816BB28
sub_816BB28: @ 816BB28
	push {lr}
	ldr r0, =gFieldCallback
	ldr r1, =sub_816BB48
	str r1, [r0]
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BB28

	thumb_func_start sub_816BB48
sub_816BB48: @ 816BB48
	push {r4-r6,lr}
	ldr r0, =task00_080EBBDC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gUnknown_0203BCB8
	ldrb r4, [r5, 0x5]
	bl sub_816B510
	strb r0, [r5, 0x5]
	bl sub_816B54C
	ldrb r0, [r5, 0x5]
	cmp r4, r0
	beq _0816BB7E
	ldrb r1, [r5, 0x5]
	ldrb r0, [r5, 0x4]
	ldrh r2, [r5, 0x2]
	adds r0, r2
	cmp r1, r0
	bge _0816BB7E
	cmp r2, 0
	beq _0816BB7E
	subs r0, r2, 0x1
	strh r0, [r5, 0x2]
_0816BB7E:
	adds r0, r6, 0
	bl sub_816B4C0
	bl sub_81973A4
	ldr r0, =gUnknown_0203BCB8
	ldrb r0, [r0, 0x5]
	bl sub_81D1C44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816BBA8
	adds r0, r6, 0
	bl sub_816B5F8
	b _0816BBAE
	.pool
_0816BBA8:
	adds r0, r6, 0
	bl DestroyTask
_0816BBAE:
	bl pal_fill_black
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_816BB48

	thumb_func_start sub_816BBB8
sub_816BBB8: @ 816BBB8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gText_NoPokemon
	ldr r2, =sub_816BBD4
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BBB8

	thumb_func_start sub_816BBD4
sub_816BBD4: @ 816BBD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	bl sub_81D1D04
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	adds r0, r4, 0
	bl sub_816B5F8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816B674
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BBD4

	thumb_func_start sub_816BC14
sub_816BC14: @ 816BC14
	push {r4,lr}
	ldr r4, =gUnknown_0203BCC4
	movs r0, 0xCE
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4]
	movs r1, 0xCC
	lsls r1, 3
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0x6
	bl memset
	ldr r0, [r4]
	ldr r1, =0x00000666
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, =0x00000667
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BC14

	thumb_func_start sub_816BC58
sub_816BC58: @ 816BC58
	push {r4,lr}
	movs r4, 0
_0816BC5C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_816BCC4
	adds r4, 0x1
	cmp r4, 0x5
	bls _0816BC5C
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	bl Free
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BC58

	thumb_func_start sub_816BC7C
sub_816BC7C: @ 816BC7C
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203BCC4
	movs r3, 0xCC
	lsls r3, 3
	adds r1, r2, r3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _0816BCB4
	lsls r0, r2, 3
	ldr r1, =gUnknown_085DFF5C
	adds r0, r1
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r2, 0x85
	lsls r2, 2
	movs r1, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
_0816BCB4:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816BC7C

	thumb_func_start sub_816BCC4
sub_816BCC4: @ 816BCC4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203BCC4
	movs r2, 0xCC
	lsls r2, 3
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _0816BCF8
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
_0816BCF8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BCC4

	thumb_func_start sub_816BD04
sub_816BD04: @ 816BD04
	push {r4-r6,lr}
	movs r6, 0
	ldr r0, =gUnknown_0203BCB8
	ldrb r0, [r0, 0x5]
	subs r0, 0x1
	cmp r6, r0
	bge _0816BD58
	ldr r5, =gUnknown_0203BCC4
_0816BD14:
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	movs r0, 0xCC
	lsls r0, 1
	adds r4, r0
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsls r2, r6, 2
	adds r1, r2
	movs r2, 0x93
	lsls r2, 3
	adds r1, r2
	ldrh r1, [r1]
	bl sub_816BDC8
	ldr r0, [r5]
	lsls r2, r6, 3
	adds r1, r0, r2
	adds r4, r0, r4
	str r4, [r1]
	adds r0, 0x4
	adds r0, r2
	str r6, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_0203BCB8
	ldrb r0, [r0, 0x5]
	subs r0, 0x1
	cmp r6, r0
	blt _0816BD14
_0816BD58:
	ldr r5, =gUnknown_0203BCC4
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	movs r3, 0xCC
	lsls r3, 1
	adds r4, r3
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gText_Cancel2
	bl StringCopy
	ldr r0, [r5]
	lsls r2, r6, 3
	adds r1, r0, r2
	adds r4, r0, r4
	str r4, [r1]
	adds r0, 0x4
	adds r0, r2
	movs r1, 0x2
	negs r1, r1
	str r1, [r0]
	ldr r4, =gMultiuseListMenuTemplate
	adds r1, r4, 0
	ldr r0, =gUnknown_085DFF44
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	movs r0, 0
	bl sub_816BC7C
	strb r0, [r4, 0x10]
	ldr r1, =gUnknown_0203BCB8
	ldrb r0, [r1, 0x5]
	strh r0, [r4, 0xC]
	ldr r0, [r5]
	str r0, [r4]
	ldrb r0, [r1, 0x4]
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BD04

	thumb_func_start sub_816BDC8
sub_816BDC8: @ 816BDC8
	push {lr}
	adds r2, r0, 0
	lsls r0, r1, 16
	lsrs r0, 16
	adds r1, r2, 0
	bl CopyItemName
	pop {r0}
	bx r0
	thumb_func_end sub_816BDC8

	thumb_func_start sub_816BDDC
sub_816BDDC: @ 816BDDC
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _0816BDEE
	movs r0, 0x5
	bl PlaySE
_0816BDEE:
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000666
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0816BE38
	bl sub_816C0C8
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0816BE2C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r0, r1
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	bl sub_816C060
	b _0816BE32
	.pool
_0816BE2C:
	ldr r0, =0x0000ffff
	bl sub_816C060
_0816BE32:
	adds r0, r4, 0
	bl sub_816BEF0
_0816BE38:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BDDC

	thumb_func_start fish4_goto_x5_or_x6
fish4_goto_x5_or_x6: @ 816BE44
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _0816BED4
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000666
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _0816BE8E
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0816BE84
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xFF
	bl sub_816BFE0
	b _0816BE8E
	.pool
_0816BE84:
	adds r0, r5, 0
	movs r1, 0xFF
	movs r2, 0xFF
	bl sub_816BFE0
_0816BE8E:
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsls r2, r4, 2
	adds r1, r2
	ldr r2, =0x0000049a
	adds r1, r2
	ldrh r1, [r1]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x68
	bl GetStringRightAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x7
	adds r2, r4, 0
	bl PrintTextOnWindow
_0816BED4:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end fish4_goto_x5_or_x6

	thumb_func_start sub_816BEF0
sub_816BEF0: @ 816BEF0
	push {r4,r5,lr}
	sub sp, 0xC
	adds r1, r0, 0
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r2, =0x00000661
	adds r0, r2
	ldrb r5, [r0]
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _0816BF2C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	bl ItemId_GetDescription
	b _0816BF32
	.pool
_0816BF2C:
	ldr r0, =0x0000ffff
	bl sub_816C228
_0816BF32:
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BEF0

	thumb_func_start sub_816BF60
sub_816BF60: @ 816BF60
	push {r4,lr}
	sub sp, 0x10
	ldr r4, =gUnknown_0203BCB8
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _0816BF8C
	ldrb r0, [r4, 0x5]
	ldrb r1, [r4, 0x4]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x000013f8
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xB0
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	strb r0, [r4, 0x9]
_0816BF8C:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BF60

	thumb_func_start sub_816BF9C
sub_816BF9C: @ 816BF9C
	push {r4,lr}
	ldr r4, =gUnknown_0203BCB8
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	beq _0816BFAE
	bl RemoveScrollIndicatorArrowPair
	movs r0, 0xFF
	strb r0, [r4, 0x9]
_0816BFAE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BF9C

	thumb_func_start sub_816BFB8
sub_816BFB8: @ 816BFB8
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_816BFE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_816BFB8

	thumb_func_start sub_816BFE0
sub_816BFE0: @ 816BFE0
	push {r4-r6,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r3, 0xCC
	lsls r3, 3
	adds r0, r3
	ldrb r5, [r0]
	cmp r1, 0xFF
	bne _0816C030
	movs r0, 0x1
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0x11
	movs r2, 0
	adds r3, r6, 0
	bl FillWindowPixelRect
	b _0816C050
	.pool
_0816C030:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_085DFF8C
	str r0, [sp, 0x8]
	lsls r0, r2, 24
	asrs r0, 24
	str r0, [sp, 0xC]
	ldr r0, =gText_SelectorArrow2
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0
	adds r3, r6, 0
	bl AddTextPrinterParameterized2
_0816C050:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816BFE0

	thumb_func_start sub_816C060
sub_816C060: @ 816C060
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000667
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _0816C0B2
	ldr r4, =0x000013f6
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl AddItemIconObject
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0816C0B2
	strb r2, [r5]
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	movs r0, 0x18
	strh r0, [r1, 0x24]
	movs r0, 0x50
	strh r0, [r1, 0x26]
_0816C0B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C060

	thumb_func_start sub_816C0C8
sub_816C0C8: @ 816C0C8
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000667
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _0816C0FA
	ldr r4, =0x000013f6
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	movs r0, 0xFF
	strb r0, [r5]
_0816C0FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C0C8

	thumb_func_start sub_816C110
sub_816C110: @ 816C110
	push {lr}
	sub sp, 0x4
	bl sub_80D6E84
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldr r2, =gUnknown_0203BCBC
	adds r3, r2, 0x1
	movs r1, 0x8
	str r1, [sp]
	movs r1, 0x32
	bl sub_812220C
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C110

	thumb_func_start sub_816C140
sub_816C140: @ 816C140
	push {lr}
	ldr r0, =gUnknown_0203BCBA
	subs r1, r0, 0x2
	ldrb r2, [r1, 0x4]
	ldrb r3, [r1, 0x5]
	bl sub_812225C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C140

	thumb_func_start sub_816C158
sub_816C158: @ 816C158
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r4, 0
_0816C16C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_816BC7C
	adds r4, 0x1
	cmp r4, 0x3
	bls _0816C16C
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	ldr r5, =gText_TossItem
	cmp r0, 0
	bne _0816C186
	ldr r5, =gText_WithdrawItem
_0816C186:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x68
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	ldr r4, =gUnknown_0203BCC4
	ldr r0, [r4]
	ldr r1, =0x00000663
	adds r0, r1
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0
	str r1, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl PrintTextOnWindow
	ldr r0, [r4]
	ldr r1, =0x00000662
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	bl sub_816C110
	bl sub_816C140
	bl sub_816BD04
	ldr r0, =gMultiuseListMenuTemplate
	ldr r2, =gUnknown_0203BCB8
	ldrh r1, [r2, 0x2]
	ldrh r2, [r2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r7, 0xA]
	bl sub_816BF60
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C30C
	str r1, [r0]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C158

	thumb_func_start sub_816C228
sub_816C228: @ 816C228
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xffff0009
	adds r0, r1, r2
	cmp r0, 0x8
	bhi _0816C2B4
	lsls r0, 2
	ldr r1, =_0816C248
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816C248:
	.4byte _0816C2AC
	.4byte _0816C2A4
	.4byte _0816C29C
	.4byte _0816C294
	.4byte _0816C28C
	.4byte _0816C284
	.4byte _0816C27C
	.4byte _0816C274
	.4byte _0816C26C
_0816C26C:
	ldr r0, =gText_GoBackPrevMenu
	b _0816C2BA
	.pool
_0816C274:
	ldr r0, =gText_WithdrawHowManyItems
	b _0816C2BA
	.pool
_0816C27C:
	ldr r0, =gText_WithdrawXItems
	b _0816C2BA
	.pool
_0816C284:
	ldr r0, =gText_TossHowManyVar1s
	b _0816C2BA
	.pool
_0816C28C:
	ldr r0, =gText_ThrewAwayVar2Var1s
	b _0816C2BA
	.pool
_0816C294:
	ldr r0, =gText_NoRoomInBag
	b _0816C2BA
	.pool
_0816C29C:
	ldr r0, =gText_TooImportantToToss
	b _0816C2BA
	.pool
_0816C2A4:
	ldr r0, =gText_ConfirmTossItems
	b _0816C2BA
	.pool
_0816C2AC:
	ldr r0, =gText_MoveVar1Where
	b _0816C2BA
	.pool
_0816C2B4:
	adds r0, r1, 0
	bl ItemId_GetDescription
_0816C2BA:
	pop {r1}
	bx r1
	thumb_func_end sub_816C228

	thumb_func_start sub_816C2C0
sub_816C2C0: @ 816C2C0
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	ldr r1, =0x00000661
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gStringVar4
	adds r0, r4, 0
	adds r1, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C2C0

	thumb_func_start sub_816C30C
sub_816C30C: @ 816C30C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0816C35C
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r4, r1, 0x2
	adds r2, r4, 0
	bl sub_81AE860
	ldrh r1, [r4, 0x2]
	ldrh r0, [r4]
	adds r1, r0
	ldrb r0, [r4, 0x5]
	subs r0, 0x1
	cmp r1, r0
	beq _0816C39E
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816C450
	b _0816C39E
	.pool
_0816C35C:
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r2, r1, 0x2
	bl sub_81AE860
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _0816C384
	adds r0, 0x1
	cmp r6, r0
	bne _0816C392
	b _0816C39E
	.pool
_0816C384:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816C400
	b _0816C39E
_0816C392:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_816C71C
_0816C39E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_816C30C

	thumb_func_start bx_battle_menu_t3
bx_battle_menu_t3: @ 816C3A4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0816C3F2
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0816C3DC
	adds r0, r4, 0
	movs r1, 0
	bl sub_816B190
	b _0816C3E4
	.pool
_0816C3DC:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_816B190
_0816C3E4:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_816B248
	str r0, [r1]
_0816C3F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_battle_menu_t3

	thumb_func_start sub_816C400
sub_816C400: @ 816C400
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	bl sub_816C0C8
	bl sub_816BF9C
	ldrb r0, [r5, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	bl sub_81223B0
	bl sub_816BC58
	subs r6, 0x8
	adds r4, r6
	ldr r0, =bx_battle_menu_t3
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C400

	thumb_func_start sub_816C450
sub_816C450: @ 816C450
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r1, r4, 0
	add r1, r8
	mov r9, r1
	ldrb r0, [r1, 0xA]
	movs r1, 0x10
	movs r2, 0x1
	bl sub_81AF15C
	ldr r6, =gUnknown_0203BCC4
	ldr r2, [r6]
	ldr r1, =gUnknown_0203BCB8
	ldrb r0, [r1]
	ldrb r1, [r1, 0x2]
	adds r0, r1
	ldr r5, =0x00000666
	adds r2, r5
	strb r0, [r2]
	mov r1, r9
	ldrb r0, [r1, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_816BFB8
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_816C690
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	movs r0, 0x93
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =0x0000fff7
	bl sub_816C228
	bl sub_816C2C0
	movs r1, 0x8
	negs r1, r1
	add r8, r1
	add r4, r8
	ldr r0, =sub_816C4FC
	str r0, [r4]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C450

	thumb_func_start sub_816C4FC
sub_816C4FC: @ 816C4FC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r7, =gMain
	ldrh r1, [r7, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0816C530
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r2, r1, 0x2
	bl sub_81AE860
	b _0816C57E
	.pool
_0816C530:
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInputGetItemId
	adds r6, r0, 0
	ldrb r0, [r4, 0xA]
	ldr r1, =gUnknown_0203BCBA
	subs r4, r1, 0x2
	adds r2, r4, 0
	bl sub_81AE860
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	movs r2, 0
	bl sub_81223FC
	ldrb r0, [r4]
	bl sub_816C690
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _0816C574
	adds r0, 0x1
	cmp r6, r0
	bne _0816C592
	b _0816C59A
	.pool
_0816C574:
	ldrh r1, [r7, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816C588
_0816C57E:
	adds r0, r5, 0
	movs r1, 0
	bl sub_816C5A0
	b _0816C59A
_0816C588:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_816C5A0
	b _0816C59A
_0816C592:
	adds r0, r5, 0
	movs r1, 0
	bl sub_816C5A0
_0816C59A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816C4FC

	thumb_func_start sub_816C5A0
sub_816C5A0: @ 816C5A0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	mov r8, r0
	ldr r4, =gUnknown_0203BCB8
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0x5
	bl PlaySE
	mov r2, r8
	ldrb r0, [r2, 0xA]
	adds r1, r4, 0x2
	adds r2, r4, 0
	bl sub_81AE6C8
	cmp r5, 0
	bne _0816C60A
	ldr r1, =gUnknown_0203BCC4
	ldr r0, [r1]
	ldr r2, =0x00000666
	adds r0, r2
	ldrb r2, [r0]
	adds r4, r1, 0
	cmp r2, r6
	beq _0816C622
	subs r0, r6, 0x1
	cmp r2, r0
	beq _0816C60A
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	adds r1, r2, 0
	adds r2, r6, 0
	bl sub_80D702C
	bl sub_816BD04
_0816C60A:
	ldr r0, =gUnknown_0203BCC4
	ldr r1, [r0]
	ldr r2, =0x00000666
	adds r1, r2
	ldrb r1, [r1]
	adds r4, r0, 0
	cmp r1, r6
	bcs _0816C622
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_0816C622:
	ldr r0, [r4]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	movs r1, 0x7
	movs r2, 0x1
	bl sub_81223FC
	ldr r0, [r4]
	ldr r2, =0x00000666
	adds r0, r2
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, =gMultiuseListMenuTemplate
	ldr r2, =gUnknown_0203BCB8
	ldrh r1, [r2, 0x2]
	ldrh r2, [r2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	strh r0, [r1, 0xA]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C30C
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C5A0

	thumb_func_start sub_816C690
sub_816C690: @ 816C690
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	ldr r0, =gUnknown_0203BCC4
	ldr r0, [r0]
	movs r1, 0xCD
	lsls r1, 3
	adds r0, r1
	lsrs r3, 4
	movs r1, 0x80
	lsls r1, 13
	adds r3, r1
	lsrs r3, 16
	movs r1, 0x7
	movs r2, 0x80
	bl sub_8122448
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C690

	thumb_func_start sub_816C6BC
sub_816C6BC: @ 816C6BC
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r0, 0
	ldr r5, [sp, 0x1C]
	ldr r3, [sp, 0x20]
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gStringVar1
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x30
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C6BC

	thumb_func_start sub_816C71C
sub_816C71C: @ 816C71C
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	bl sub_816BF9C
	movs r0, 0x1
	strh r0, [r6, 0x4]
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0816C798
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r1, r0
	ldr r2, =0x0000049a
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0816C774
	adds r0, r5, 0
	bl sub_816C8FC
	b _0816C7FE
	.pool
_0816C774:
	movs r2, 0x93
	lsls r2, 3
	adds r0, r1, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =0x0000fffe
	bl sub_816C228
	bl sub_816C2C0
	b _0816C7D4
	.pool
_0816C798:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r4, 2
	adds r1, r0
	ldr r2, =0x0000049a
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x1
	bne _0816C7BC
	adds r0, r5, 0
	bl sub_816C9B8
	b _0816C7FE
	.pool
_0816C7BC:
	movs r2, 0x93
	lsls r2, 3
	adds r0, r1, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =0x0000fffc
	bl sub_816C228
	bl sub_816C2C0
_0816C7D4:
	movs r0, 0x4
	bl sub_816BC7C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0x3
	str r2, [sp, 0x4]
	movs r2, 0x2
	movs r3, 0x8
	bl sub_816C6BC
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C818
	str r1, [r0]
_0816C7FE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C71C

	thumb_func_start sub_816C818
sub_816C818: @ 816C818
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	mov r9, r5
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldr r0, =gUnknown_0203BCB8
	ldrh r2, [r0, 0x2]
	ldrh r0, [r0]
	adds r2, r0
	lsls r2, 16
	adds r0, r6, 0x4
	ldr r1, =gSaveBlock1Ptr
	mov r8, r1
	ldr r1, [r1]
	lsrs r7, r2, 14
	adds r1, r7
	ldr r2, =0x0000049a
	adds r1, r2
	ldrh r1, [r1]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0816C888
	movs r0, 0x4
	bl sub_816BC7C
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r6, 0x4]
	str r4, [sp]
	movs r2, 0x3
	str r2, [sp, 0x4]
	movs r2, 0x2
	movs r3, 0x8
	bl sub_816C6BC
	b _0816C8EC
	.pool
_0816C888:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816C8BC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
	bl sub_816BCC4
	movs r3, 0x6
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _0816C8B4
	adds r0, r5, 0
	bl sub_816C8FC
	b _0816C8EC
	.pool
_0816C8B4:
	adds r0, r5, 0
	bl sub_816C9B8
	b _0816C8EC
_0816C8BC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0816C8EC
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x4
	bl sub_816BCC4
	mov r1, r8
	ldr r0, [r1]
	adds r0, r7
	movs r2, 0x93
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r9
	bl sub_816CBC0
_0816C8EC:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_816C818

	thumb_func_start sub_816C8FC
sub_816C8FC: @ 816C8FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r6, r1, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r4, r6, r0
	ldr r0, =gUnknown_0203BCB8
	ldrh r1, [r0, 0x2]
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	ldr r7, =gSaveBlock1Ptr
	ldr r0, [r7]
	lsrs r5, r1, 14
	adds r0, r5
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, 0x4]
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0816C98C
	ldr r0, [r7]
	adds r0, r5
	movs r2, 0x93
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =0x0000fffd
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r8
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_816CB04
	b _0816C9A2
	.pool
_0816C98C:
	movs r0, 0
	strh r0, [r4, 0x4]
	ldr r0, =0x0000fffa
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r8
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_816CB74
_0816C9A2:
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C8FC

	thumb_func_start sub_816C9B8
sub_816C9B8: @ 816C9B8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	mov r8, r0
	ldr r0, =gTasks + 0x8
	mov r9, r0
	mov r7, r8
	add r7, r9
	ldr r0, =gUnknown_0203BCB8
	ldrh r1, [r0, 0x2]
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	lsrs r4, r1, 14
	adds r0, r4
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _0816CA64
	ldr r0, [r6]
	adds r0, r4
	movs r2, 0x93
	lsls r2, 3
	adds r0, r2
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, =0x0000fff8
	bl sub_816C228
	bl sub_816C2C0
	ldr r1, =gUnknown_085DFF84
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x85
	lsls r0, 2
	str r0, [sp, 0x4]
	movs r0, 0xE
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_085DFF3C
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	b _0816CA7C
	.pool
_0816CA64:
	movs r0, 0
	strh r0, [r7, 0x4]
	ldr r0, =0x0000fff9
	bl sub_816C228
	bl sub_816C2C0
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_816CB74
	str r1, [r0]
_0816CA7C:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816C9B8

	thumb_func_start sub_816CA94
sub_816CA94: @ 816CA94
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000fffb
	bl sub_816C228
	bl sub_816C2C0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816CB04
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CA94

	thumb_func_start sub_816CAC8
sub_816CAC8: @ 816CAC8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	movs r0, 0x93
	lsls r0, 3
	adds r2, r0
	ldrh r0, [r2]
	bl sub_816C228
	bl sub_816C2C0
	adds r0, r4, 0
	bl sub_816CBC0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CAC8

	thumb_func_start sub_816CB04
sub_816CB04: @ 816CB04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0816CB5E
	ldr r4, =gUnknown_0203BCB8
	ldrb r0, [r4, 0x2]
	ldrb r1, [r4]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x4]
	bl sub_80D6E48
	ldrb r0, [r5, 0xA]
	adds r1, r4, 0x2
	adds r2, r4, 0
	bl sub_81AE6C8
	bl sub_816C110
	bl sub_816C140
	bl sub_816BD04
	ldr r0, =gMultiuseListMenuTemplate
	ldrh r1, [r4, 0x2]
	ldrh r2, [r4]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	adds r0, r6, 0
	bl sub_816CBC0
_0816CB5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CB04

	thumb_func_start sub_816CB74
sub_816CB74: @ 816CB74
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0816CBAC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =gUnknown_0203BCB8
	ldrh r0, [r1, 0x2]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	movs r0, 0x93
	lsls r0, 3
	adds r2, r0
	ldrh r0, [r2]
	bl sub_816C228
	bl sub_816C2C0
	adds r0, r4, 0
	bl sub_816CBC0
_0816CBAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CB74

	thumb_func_start sub_816CBC0
sub_816CBC0: @ 816CBC0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_816BF60
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_816C30C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816CBC0

	.align 2, 0 @ Don't pad with nop.
