	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81339F8
sub_81339F8: @ 81339F8
	push {r4-r6,lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002e28
	adds r5, r1, r0
	movs r2, 0
	movs r0, 0x2
	strb r0, [r5]
	ldr r0, =0x00002e59
	adds r1, r0
	strb r2, [r1]
	movs r4, 0
	ldr r6, =gUnknown_085B09E4
_08133A12:
	movs r0, 0xB
	muls r0, r4
	adds r0, 0x5
	adds r0, r5, r0
	lsls r1, r4, 2
	adds r1, r6
	ldr r1, [r1]
	bl StringCopy
	adds r1, r5, 0x1
	adds r1, r4
	ldr r0, =gUnknown_085B09F4
	adds r0, r4, r0
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x32
	adds r0, r4
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _08133A12
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81339F8

	thumb_func_start sub_8133A60
sub_8133A60: @ 8133A60
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e59
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8133A60

	thumb_func_start sub_8133A78
sub_8133A78: @ 8133A78
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r7, r1, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	ldr r0, =0x00002e28
	adds r0, r4
	mov r9, r0
	ldr r0, =gUnknown_085B09F8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	ldr r1, =gText_Exit
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r6, r0, 0
	ldr r1, =gText_FiveMarks
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	mov r8, r0
	movs r5, 0
	ldr r0, =0x00002e29
	adds r4, r0
_08133AC2:
	mov r0, r9
	adds r0, 0x1
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0x78
	bls _08133AF0
	mov r0, r8
	b _08133B00
	.pool
_08133AF0:
	ldrb r1, [r1]
	lsls r1, 5
	ldr r0, =gUnknown_085A5C09
	adds r1, r0
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
_08133B00:
	cmp r0, r6
	ble _08133B06
	adds r6, r0, 0
_08133B06:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08133AC2
	adds r0, r6, 0
	bl convert_pixel_width_to_tile_width
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
	add r0, sp, 0xC
	bl AddWindow
	strh r0, [r7, 0x6]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x85
	lsls r2, 2
	movs r1, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r5, 0
_08133B3C:
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, 0x78
	bls _08133B70
	ldrb r0, [r7, 0x6]
	lsls r1, r5, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gText_FiveMarks
	movs r3, 0x8
	bl PrintTextOnWindow
	b _08133B94
	.pool
_08133B70:
	ldrb r0, [r7, 0x6]
	ldrb r2, [r1]
	lsls r2, 5
	ldr r1, =gUnknown_085A5C09
	adds r2, r1
	lsls r1, r5, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
_08133B94:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08133B3C
	ldrb r0, [r7, 0x6]
	ldr r2, =gText_Exit
	lsls r1, r5, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl PrintTextOnWindow
	ldrb r0, [r7, 0x6]
	movs r1, 0x5
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133A78

	thumb_func_start sub_8133BE4
sub_8133BE4: @ 8133BE4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	cmp r2, 0x78
	bls _08133C14
	ldr r1, =gSpecialVar_0x8004
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
	b _08133C18
	.pool
_08133C14:
	ldr r0, =gSpecialVar_0x8004
	strh r2, [r0]
_08133C18:
	ldrb r0, [r4, 0x6]
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4, 0x6]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0x6]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133BE4

	thumb_func_start sub_8133C48
sub_8133C48: @ 8133C48
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002e28
	adds r6, r0, r1
	bl ProcessMenuInput
	lsls r0, 24
	lsrs r4, r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08133C80
	cmp r1, r0
	bgt _08133C7C
	subs r0, 0x1
	cmp r1, r0
	beq _08133CCA
	b _08133C90
	.pool
_08133C7C:
	cmp r1, 0x4
	bne _08133C90
_08133C80:
	movs r0, 0x5
	bl PlaySE
	adds r0, r7, 0
	movs r1, 0
	bl sub_8133BE4
	b _08133CCA
_08133C90:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gSpecialVar_0x8005
	lsls r4, 24
	asrs r4, 24
	strh r4, [r0]
	ldr r5, =gStringVar1
	movs r0, 0xB
	adds r1, r4, 0
	muls r1, r0
	adds r1, 0x5
	adds r1, r6, r1
	adds r0, r5, 0
	bl StringCopy
	adds r0, r6, 0
	adds r0, 0x32
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r5, 0
	bl ConvertInternationalString
	adds r0, r6, 0x1
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8133BE4
_08133CCA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133C48

	thumb_func_start sub_8133CD8
sub_8133CD8: @ 8133CD8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =gScriptResult
	ldr r2, =0x00002e59
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8133CD8

	thumb_func_start sub_8133CF4
sub_8133CF4: @ 8133CF4
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gScriptResult
_08133CFA:
	adds r0, r4, 0
	bl sub_8161AD0
	lsls r0, 24
	cmp r0, 0
	beq _08133D10
	movs r0, 0
	strh r0, [r5]
	b _08133D20
	.pool
_08133D10:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _08133CFA
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
_08133D20:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133CF4

	thumb_func_start sub_8133D2C
sub_8133D2C: @ 8133D2C
	push {r4-r6,lr}
	ldr r6, =gScriptResult
	movs r0, 0
	strh r0, [r6]
	ldr r4, =gDecorations
	ldr r5, =gSpecialVar_0x8004
	ldrh r0, [r5]
	lsls r0, 5
	adds r2, r0, r4
	ldr r0, =gSpecialVar_0x8006
	ldrh r0, [r0]
	lsls r0, 5
	adds r0, r4
	ldrb r1, [r2, 0x13]
	ldrb r0, [r0, 0x13]
	cmp r1, r0
	beq _08133D72
	adds r0, r1, 0
	bl sub_81618D0
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08133D72
	ldr r0, =gStringVar2
	ldrh r1, [r5]
	lsls r1, 5
	adds r1, r4
	ldrb r1, [r1, 0x13]
	bl sub_8127250
	movs r0, 0x1
	strh r0, [r6]
_08133D72:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133D2C

	thumb_func_start sub_8133D8C
sub_8133D8C: @ 8133D8C
	push {lr}
	ldr r0, =sub_8127208
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133D8C

	thumb_func_start sub_8133DA0
sub_8133DA0: @ 8133DA0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81279C4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08133DFC
	ldr r5, =gSpecialVar_0x8006
	ldr r0, =gUnknown_0203A172
	ldrb r1, [r0]
	ldr r0, =gUnknown_0203A14C
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r5]
	ldr r0, =gStringVar3
	ldr r1, =gSpecialVar_0x8004
	ldrh r1, [r1]
	lsls r1, 5
	ldr r4, =gUnknown_085A5C09
	adds r1, r4
	bl StringCopy
	ldr r0, =gStringVar2
	ldrh r1, [r5]
	lsls r1, 5
	adds r1, r4
	bl StringCopy
	b _08133E04
	.pool
_08133DFC:
	ldr r1, =gSpecialVar_0x8006
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_08133E04:
	adds r0, r6, 0
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133DA0

	thumb_func_start sub_8133E1C
sub_8133E1C: @ 8133E1C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSpecialVar_0x8006
	movs r1, 0
	strh r1, [r2]
	bl DestroyTask
	bl EnableBothScriptContexts
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133E1C

	thumb_func_start sub_8133E38
sub_8133E38: @ 8133E38
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gSaveBlock1Ptr
	ldr r6, [r0]
	ldr r0, =0x00002e28
	adds r5, r6, r0
	ldr r1, =gSpecialVar_0x8006
	mov r8, r1
	ldrb r0, [r1]
	bl DecorationRemove
	ldr r0, =gSpecialVar_0x8004
	ldrb r0, [r0]
	bl DecorationAdd
	ldr r4, =gSpecialVar_0x8005
	ldrh r1, [r4]
	movs r0, 0xB
	muls r0, r1
	adds r0, 0x5
	adds r5, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy
	ldr r2, =0x00002e29
	adds r0, r6, r2
	ldrh r1, [r4]
	adds r0, r1
	mov r2, r8
	ldrh r1, [r2]
	strb r1, [r0]
	ldr r1, =0x00002e5a
	adds r0, r6, r1
	ldrh r4, [r4]
	adds r0, r4
	movs r1, 0x2
	strb r1, [r0]
	ldr r2, =0x00002e59
	adds r6, r2
	movs r0, 0x1
	strb r0, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133E38

	thumb_func_start sub_8133EC0
sub_8133EC0: @ 8133EC0
	push {lr}
	ldr r0, =sub_8133C48
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl sub_8133A78
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8133EC0

	.align 2, 0 @ Don't pad with nop.
