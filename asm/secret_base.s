	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80E9878
sub_80E9878: @ 80E9878
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r2, r1
	ldr r0, =0x00001a9d
	adds r2, r0
	ldrb r0, [r2]
	lsrs r0, 6
	cmp r0, 0
	bne _080E98A4
	movs r0, 0
	b _080E98A6
	.pool
_080E98A4:
	movs r0, 0x1
_080E98A6:
	pop {r1}
	bx r1
	thumb_func_end sub_80E9878

	thumb_func_start sub_80E98AC
sub_80E98AC: @ 80E98AC
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x1A
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1B
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1C
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1D
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1E
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1F
	bl GetMonData
	adds r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E98AC

	thumb_func_start sub_80E9914
sub_80E9914: @ 80E9914
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	movs r0, 0
	mov r10, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x00001ad0
	adds r2, r1, r2
	str r2, [sp]
	ldr r3, =0x00001a9c
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080E993A
	b _080E9A60
_080E993A:
	movs r6, 0
	ldr r7, =0x00001ae8
	adds r7, r1, r7
	str r7, [sp, 0x14]
	ldr r0, =0x00001b18
	adds r0, r1, r0
	str r0, [sp, 0xC]
	ldr r2, =0x00001b24
	adds r2, r1, r2
	str r2, [sp, 0x10]
	adds r3, 0x94
	adds r3, r1, r3
	str r3, [sp, 0x18]
	ldr r7, =0x00001b36
	adds r7, r1, r7
	str r7, [sp, 0x1C]
	mov r9, r6
_080E995C:
	movs r4, 0
	lsls r5, r6, 2
	lsls r3, r6, 1
	ldr r0, =gPlayerParty
	mov r8, r0
	adds r1, r6, 0x1
	str r1, [sp, 0x4]
	adds r2, r5, 0
	ldr r1, [sp, 0x14]
_080E996E:
	adds r0, r2, r4
	lsls r0, 1
	adds r0, r1, r0
	mov r7, r9
	strh r7, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x3
	bls _080E996E
	ldr r1, [sp, 0xC]
	adds r0, r1, r3
	mov r2, r9
	strh r2, [r0]
	ldr r7, [sp, 0x10]
	adds r0, r7, r3
	strh r2, [r0]
	ldr r1, [sp, 0x18]
	adds r0, r1, r6
	mov r2, r9
	strb r2, [r0]
	ldr r3, [sp]
	adds r0, r3, r5
	mov r7, r9
	str r7, [r0]
	ldr r1, [sp, 0x1C]
	adds r0, r1, r6
	strb r7, [r0]
	movs r2, 0x64
	adds r5, r6, 0
	muls r5, r2
	mov r3, r8
	adds r4, r5, r3
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _080E9A54
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _080E9A54
	movs r4, 0
	mov r7, r10
	lsls r7, 2
	mov r8, r7
	mov r0, r10
	lsls r7, r0, 1
	adds r0, 0x1
	str r0, [sp, 0x8]
	ldr r2, =gPlayerParty
_080E99DA:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r5, r2
	str r2, [sp, 0x20]
	bl GetMonData
	mov r3, r8
	adds r1, r3, r4
	lsls r1, 1
	ldr r3, [sp, 0x14]
	adds r1, r3, r1
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r2, [sp, 0x20]
	cmp r4, 0x3
	bls _080E99DA
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldr r2, [sp, 0xC]
	adds r1, r2, r7
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	ldr r3, [sp, 0x10]
	adds r1, r3, r7
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x18]
	add r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	ldr r1, [sp]
	add r1, r8
	str r0, [r1]
	adds r0, r4, 0
	bl sub_80E98AC
	ldr r1, [sp, 0x1C]
	add r1, r10
	strb r0, [r1]
	ldr r7, [sp, 0x8]
	lsls r0, r7, 16
	lsrs r0, 16
	mov r10, r0
_080E9A54:
	ldr r1, [sp, 0x4]
	lsls r0, r1, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bhi _080E9A60
	b _080E995C
_080E9A60:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9914

	thumb_func_start sub_80E9A90
sub_80E9A90: @ 80E9A90
	push {r4-r6,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x00001aaa
	adds r1, r0, r4
	ldrh r6, [r1]
	ldr r1, =0x00001a9c
	adds r0, r1
	bl sub_80E8AF0
	ldr r0, [r5]
	adds r0, r4
	strh r6, [r0]
	bl sub_80E9728
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9A90

	thumb_func_start sub_80E9AC0
sub_80E9AC0: @ 80E9AC0
	push {lr}
	movs r0, 0x14
	bl IncrementGameStat
	bl sub_80E9A90
	pop {r0}
	bx r0
	thumb_func_end sub_80E9AC0

	thumb_func_start sub_80E9AD0
sub_80E9AD0: @ 80E9AD0
	push {r4-r7,lr}
	ldr r0, =gMapHeader
	ldr r4, [r0, 0x4]
	movs r6, 0
	b _080E9B62
	.pool
_080E9AE0:
	ldr r2, [r4, 0x10]
	lsls r1, r6, 1
	adds r0, r1, r6
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x5]
	adds r7, r1, 0
	cmp r0, 0x8
	bne _080E9B5C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, [r2, 0x8]
	cmp r1, r0
	bne _080E9B5C
	ldrh r0, [r2]
	adds r0, 0x7
	ldrh r1, [r2, 0x2]
	adds r1, 0x7
	bl MapGridGetMetatileIdAt
	movs r1, 0
	ldr r5, =gUnknown_0858CFCC
	lsls r0, 16
	asrs r2, r0, 16
_080E9B16:
	lsls r0, r1, 2
	adds r3, r0, r5
	ldrh r0, [r3, 0x2]
	cmp r0, r2
	beq _080E9B3C
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x6
	bls _080E9B16
_080E9B2A:
	bl DrawWholeMapView
	b _080E9B68
	.pool
_080E9B3C:
	ldr r0, [r4, 0x10]
	adds r1, r7, r6
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x7
	ldrh r1, [r1, 0x2]
	adds r1, 0x7
	ldrh r3, [r3]
	movs r4, 0xC0
	lsls r4, 4
	adds r2, r4, 0
	orrs r2, r3
	bl MapGridSetMetatileIdAt
	b _080E9B2A
_080E9B5C:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_080E9B62:
	ldrb r0, [r4, 0x3]
	cmp r6, r0
	bcc _080E9AE0
_080E9B68:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E9AD0

	thumb_func_start sub_80E9B70
sub_80E9B70: @ 80E9B70
	push {r4-r6,lr}
	bl sub_80E9AD0
	movs r0, 0x14
	bl IncrementGameStat
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x00001aaa
	adds r1, r0, r4
	ldrh r6, [r1]
	ldr r1, =0x00001a9c
	adds r0, r1
	bl sub_80E8AF0
	ldr r0, [r5]
	adds r0, r4
	strh r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9B70

	thumb_func_start sub_80E9BA8
sub_80E9BA8: @ 80E9BA8
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0x1
_080E9BAE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80E9878
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080E9BC4
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080E9BC4:
	lsls r0, r4, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080E9BAE
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E9BA8

	thumb_func_start sub_80E9BDC
sub_80E9BDC: @ 80E9BDC
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_80E9878
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _080E9C04
	ldr r0, =gScriptResult
	strh r1, [r0]
	b _080E9C22
	.pool
_080E9C04:
	bl sub_80E9BA8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bls _080E9C1C
	ldr r1, =gScriptResult
	movs r0, 0x2
	b _080E9C20
	.pool
_080E9C1C:
	ldr r1, =gScriptResult
	movs r0, 0
_080E9C20:
	strh r0, [r1]
_080E9C22:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9BDC

	thumb_func_start sub_80E9C2C
sub_80E9C2C: @ 80E9C2C
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r2, r1
	ldr r0, =0x00001a9d
	adds r2, r0
	ldrb r3, [r2]
	lsrs r1, r3, 6
	movs r0, 0x1
	eors r1, r0
	lsls r1, 6
	movs r0, 0x3F
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x86
	lsls r0, 1
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C2C

	thumb_func_start sub_80E9C74
sub_80E9C74: @ 80E9C74
	push {lr}
	ldr r0, =sub_8126AD8
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C74

	thumb_func_start sub_80E9C88
sub_80E9C88: @ 80E9C88
	push {lr}
	ldr r0, =sub_80E9C9C
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C88

	thumb_func_start sub_80E9C9C
sub_80E9C9C: @ 80E9C9C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r5, r7, r0
	bl ScriptContext2_Enable
	bl sub_80E9BA8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	cmp r0, 0
	beq _080E9D10
	movs r0, 0
	strh r0, [r5, 0x2]
	strh r0, [r5, 0x4]
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldr r4, =gUnknown_0203A020
	movs r0, 0xDC
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gUnknown_0858D06C
	bl AddWindow
	strh r0, [r5, 0xC]
	adds r0, r6, 0
	bl game_continue
	adds r0, r6, 0
	bl sub_80E9E00
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_80E9E90
	str r1, [r0]
	b _080E9D1A
	.pool
_080E9D10:
	ldr r1, =gText_NoRegistry
	ldr r2, =task_pc_turn_off
	adds r0, r6, 0
	bl DisplayItemMessageOnField
_080E9D1A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9C9C

	thumb_func_start game_continue
game_continue: @ 80E9D2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r7, r1, r0
	movs r6, 0
	movs r5, 0x1
	ldr r0, =gUnknown_0203A020
	mov r8, r0
_080E9D48:
	adds r0, r5, 0
	bl sub_80E9878
	lsls r0, 24
	cmp r0, 0
	beq _080E9D7C
	lsls r4, r6, 5
	adds r4, 0x58
	mov r1, r8
	ldr r0, [r1]
	adds r0, r4
	adds r1, r5, 0
	bl sub_80E9780
	mov r3, r8
	ldr r0, [r3]
	lsls r2, r6, 3
	adds r1, r0, r2
	adds r4, r0, r4
	str r4, [r1]
	adds r0, 0x4
	adds r0, r2
	str r5, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080E9D7C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080E9D48
	ldr r4, =gUnknown_0203A020
	ldr r1, [r4]
	lsls r3, r6, 3
	adds r2, r1, r3
	ldr r0, =gText_Cancel
	str r0, [r2]
	adds r1, 0x4
	adds r1, r3
	movs r0, 0x2
	negs r0, r0
	str r0, [r1]
	adds r2, r6, 0x1
	strh r2, [r7]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x7
	bgt _080E9DB8
	strh r2, [r7, 0x6]
	b _080E9DBC
	.pool
_080E9DB8:
	movs r0, 0x8
	strh r0, [r7, 0x6]
_080E9DBC:
	ldr r2, =gUnknown_03006310
	adds r1, r2, 0
	ldr r0, =gUnknown_0858D07C
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldrh r0, [r7, 0xC]
	strb r0, [r2, 0x10]
	ldrh r0, [r7]
	strh r0, [r2, 0xC]
	ldr r0, [r4]
	str r0, [r2]
	ldrh r0, [r7, 0x6]
	strh r0, [r2, 0xE]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end game_continue

	thumb_func_start sub_80E9DEC
sub_80E9DEC: @ 80E9DEC
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _080E9DFC
	movs r0, 0x5
	bl PlaySE
_080E9DFC:
	pop {r0}
	bx r0
	thumb_func_end sub_80E9DEC

	thumb_func_start sub_80E9E00
sub_80E9E00: @ 80E9E00
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldr r0, =gUnknown_03006310
	ldrh r1, [r4, 0x4]
	ldrh r2, [r4, 0x2]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	adds r0, r5, 0
	bl sub_80E9E44
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9E00

	thumb_func_start sub_80E9E44
sub_80E9E44: @ 80E9E44
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x000013f8
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0x4
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xBC
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x10]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9E44

	thumb_func_start sub_80E9E90
sub_80E9E90: @ 80E9E90
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	bl ListMenuHandleInput
	adds r5, r0, 0
	ldrb r0, [r4, 0xA]
	adds r1, r4, 0x4
	adds r2, r4, 0x2
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	beq _080E9EC8
	adds r0, 0x1
	cmp r5, r0
	bne _080E9F0C
	b _080E9F1A
	.pool
_080E9EC8:
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0xA]
	movs r1, 0
	movs r2, 0
	bl sub_81AE6C8
	ldrb r0, [r4, 0x10]
	bl RemoveScrollIndicatorArrowPair
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4, 0xC]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0xC]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gUnknown_0203A020
	ldr r0, [r0]
	bl Free
	adds r0, r6, 0
	bl task_pc_turn_off
	b _080E9F1A
	.pool
_080E9F0C:
	movs r0, 0x5
	bl PlaySE
	strh r5, [r4, 0x8]
	adds r0, r6, 0
	bl sub_80E9F20
_080E9F1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E9E90

	thumb_func_start sub_80E9F20
sub_80E9F20: @ 80E9F20
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	ldrb r0, [r5, 0x10]
	bl RemoveScrollIndicatorArrowPair
	ldr r0, =gUnknown_0858D06C
	ldr r1, [r0, 0xC]
	ldr r0, [r0, 0x8]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_0858D048
	mov r8, r0
	movs r1, 0x2
	bl GetMaxWidthInMenuTable
	lsls r0, 24
	ldr r2, =0x00ffffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r5, 0xE]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl SetStandardWindowBorderStyle
	ldrb r0, [r5, 0xE]
	movs r1, 0x2
	mov r2, r8
	bl PrintMenuTable
	ldrb r0, [r5, 0xE]
	movs r1, 0x2
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_80E9FB0
	str r0, [r4]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9F20

	thumb_func_start sub_80E9FB0
sub_80E9FB0: @ 80E9FB0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _080E9FF2
	adds r0, 0x1
	cmp r4, r0
	bne _080E9FDC
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_80EA18C
	b _080E9FF2
_080E9FDC:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0858D048
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r6, 0
	bl _call_via_r1
_080E9FF2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9FB0

	thumb_func_start sub_80E9FFC
sub_80E9FFC: @ 80E9FFC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldrb r0, [r4, 0xC]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4, 0xE]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r4, 0xC]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0xE]
	bl ClearWindowTilemap
	ldrb r0, [r4, 0xE]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gStringVar1
	ldrb r1, [r4, 0x8]
	bl sub_80E9780
	ldr r4, =gStringVar4
	ldr r1, =gText_OkayToDeleteFromRegistry
	adds r0, r4, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_80EA06C
	adds r0, r5, 0
	adds r1, r4, 0
	bl DisplayItemMessageOnField
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E9FFC

	thumb_func_start sub_80EA06C
sub_80EA06C: @ 80EA06C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8197930
	ldr r1, =gUnknown_0858D058
	adds r0, r4, 0
	bl sub_8121F68
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA06C

	thumb_func_start sub_80EA08C
sub_80EA08C: @ 80EA08C
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r6, r5, r0
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldrb r0, [r6, 0xA]
	adds r1, r6, 0x4
	mov r9, r1
	adds r1, r6, 0x2
	mov r10, r1
	mov r1, r9
	mov r2, r10
	bl sub_81AE6C8
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r0, 0x8
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r2, r0
	ldr r1, =0x00001a9d
	adds r2, r1
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	bl game_continue
	ldrb r2, [r6, 0x6]
	ldrb r3, [r6]
	mov r0, r9
	mov r1, r10
	bl sub_812225C
	adds r0, r4, 0
	bl sub_80E9E00
	movs r0, 0x8
	negs r0, r0
	add r8, r0
	add r5, r8
	ldr r0, =sub_80E9E90
	str r0, [r5]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA08C

	thumb_func_start sub_80EA120
sub_80EA120: @ 80EA120
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gText_RegisteredDataDeleted
	ldr r2, =sub_80EA08C
	bl DisplayItemMessageOnField
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA120

	thumb_func_start sub_80EA13C
sub_80EA13C: @ 80EA13C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r6, r4, r0
	movs r0, 0
	movs r1, 0
	bl sub_8197434
	ldrb r0, [r6, 0xA]
	adds r1, r6, 0x4
	adds r6, 0x2
	adds r2, r6, 0
	bl sub_81AE6C8
	adds r0, r5, 0
	bl sub_80E9E00
	movs r0, 0x8
	negs r0, r0
	add r8, r0
	add r4, r8
	ldr r0, =sub_80E9E90
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA13C

	thumb_func_start sub_80EA18C
sub_80EA18C: @ 80EA18C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	bl sub_80E9E44
	ldrb r0, [r5, 0xE]
	movs r1, 0
	bl sub_819746C
	ldrb r0, [r5, 0xE]
	bl ClearWindowTilemap
	ldrb r0, [r5, 0xE]
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	subs r6, 0x8
	adds r4, r6
	ldr r0, =sub_80E9E90
	str r0, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA18C

	thumb_func_start task_pc_turn_off
task_pc_turn_off: @ 80EA1D0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	bne _080EA1F4
	ldr r0, =gUnknown_0823B4E8
	bl ScriptContext1_SetupScript
	b _080EA1FA
	.pool
_080EA1F4:
	ldr r0, =gUnknown_0823B5E9
	bl ScriptContext1_SetupScript
_080EA1FA:
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_pc_turn_off

	thumb_func_start sub_80EA20C
sub_80EA20C: @ 80EA20C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r4, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r4, r1
	ldr r1, =0x00001aa5
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, 0x5
	bl __umodsi3
	ldr r1, =0x00001a9d
	adds r4, r1
	ldrb r2, [r4]
	lsls r2, 27
	lsrs r2, 31
	lsls r1, r2, 2
	adds r1, r2
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80EA20C

	thumb_func_start sub_80EA250
sub_80EA250: @ 80EA250
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_80EA20C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0
	bne _080EA278
	ldr r0, =gUnknown_08274966
	b _080EA2DA
	.pool
_080EA278:
	cmp r0, 0x1
	bne _080EA284
	ldr r0, =gUnknown_08274D13
	b _080EA2DA
	.pool
_080EA284:
	cmp r0, 0x2
	bne _080EA290
	ldr r0, =gUnknown_08274FFE
	b _080EA2DA
	.pool
_080EA290:
	cmp r0, 0x3
	bne _080EA29C
	ldr r0, =gUnknown_08275367
	b _080EA2DA
	.pool
_080EA29C:
	cmp r0, 0x4
	bne _080EA2A8
	ldr r0, =gUnknown_082756C7
	b _080EA2DA
	.pool
_080EA2A8:
	cmp r0, 0x5
	bne _080EA2B4
	ldr r0, =gUnknown_08274B24
	b _080EA2DA
	.pool
_080EA2B4:
	cmp r0, 0x6
	bne _080EA2C0
	ldr r0, =gUnknown_08274E75
	b _080EA2DA
	.pool
_080EA2C0:
	cmp r0, 0x7
	bne _080EA2CC
	ldr r0, =gUnknown_082751E1
	b _080EA2DA
	.pool
_080EA2CC:
	cmp r1, 0x8
	beq _080EA2D8
	ldr r0, =gUnknown_082758CC
	b _080EA2DA
	.pool
_080EA2D8:
	ldr r0, =gUnknown_082754F6
_080EA2DA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80EA250

	thumb_func_start sub_80EA2E4
sub_80EA2E4: @ 80EA2E4
	push {lr}
	movs r0, 0x1
	bl sub_813BADC
	ldr r1, =gTrainerBattleOpponent_A
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattleTypeFlags
	ldr r0, =0x08000008
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA2E4

	thumb_func_start sub_80EA30C
sub_80EA30C: @ 80EA30C
	push {lr}
	ldr r0, =0x00004054
	bl VarGet
	ldr r1, =gSaveBlock1Ptr
	ldr r3, [r1]
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	adds r3, r1
	ldr r0, =gScriptResult
	ldrb r0, [r0]
	ldr r1, =0x00001a9d
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 5
	ldrb r2, [r3]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA30C

	thumb_func_start sub_80EA354
sub_80EA354: @ 80EA354
	push {r4-r7,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x00000922
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080EA39A
	movs r3, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r4, =0x00001a9d
	movs r6, 0x21
	negs r6, r6
_080EA376:
	ldr r1, [r7]
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 5
	adds r1, r0
	adds r1, r4
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x13
	bls _080EA376
	ldr r0, =0x00000922
	bl FlagSet
_080EA39A:
	ldr r4, =gSpecialVar_0x8004
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80EA20C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r2, =gScriptResult
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	adds r1, r0
	ldr r0, =0x00001a9d
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 26
	lsrs r0, 31
	strh r0, [r2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA354

	thumb_func_start sub_80EA3E4
sub_80EA3E4: @ 80EA3E4
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080EA448
	cmp r0, 0x1
	bgt _080EA40C
	cmp r0, 0
	beq _080EA414
	b _080EA820
	.pool
_080EA40C:
	cmp r0, 0x2
	bne _080EA412
	b _080EA810
_080EA412:
	b _080EA820
_080EA414:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _080EA434
	ldr r1, =gUnknown_0203A01D
	movs r0, 0x1
	strb r0, [r1]
	b _080EA438
	.pool
_080EA434:
	ldr r0, =gUnknown_0203A01D
	strb r1, [r0]
_080EA438:
	adds r0, r5, 0x4
	adds r1, r5, 0x6
	bl PlayerGetDestCoords
	b _080EA81C
	.pool
_080EA448:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	adds r6, r4, 0
	cmp r1, r0
	bne _080EA474
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080EA474
	b _080EA820
_080EA474:
	strh r2, [r5, 0x4]
	ldrh r0, [r6]
	strh r0, [r5, 0x6]
	ldr r4, =0x000040ec
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x8D
	lsls r0, 2
	cmp r4, r0
	beq _080EA4C2
	adds r0, 0x8
	cmp r4, r0
	bne _080EA4E8
_080EA4C2:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA4CC
	b _080EA820
_080EA4CC:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x20
	b _080EA7FA
	.pool
_080EA4E8:
	ldr r3, =0xfffffd48
	adds r0, r4, r3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080EA51A
	movs r0, 0xB0
	lsls r0, 2
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x6
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	beq _080EA51A
	adds r0, 0x1
	cmp r4, r0
	bne _080EA540
_080EA51A:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA524
	b _080EA820
_080EA524:
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x1
	b _080EA7FA
	.pool
_080EA540:
	ldr r0, =0x00000239
	cmp r4, r0
	beq _080EA558
	adds r0, 0x8
	cmp r4, r0
	beq _080EA558
	adds r0, 0x10
	cmp r4, r0
	beq _080EA558
	adds r0, 0x8
	cmp r4, r0
	bne _080EA57C
_080EA558:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA562
	b _080EA820
_080EA562:
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x4
	b _080EA7FA
	.pool
_080EA57C:
	cmp r5, 0x34
	bne _080EA586
	ldr r0, =0x0000026d
	cmp r4, r0
	beq _080EA59E
_080EA586:
	cmp r5, 0x35
	bne _080EA5CC
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0x0000026a
	cmp r0, r1
	bne _080EA5CC
_080EA59E:
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA5A8
	b _080EA820
_080EA5A8:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA5CC:
	cmp r5, 0xC1
	bne _080EA618
	ldr r0, =0x0000023d
	cmp r4, r0
	bne _080EA618
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA5E0
	b _080EA820
_080EA5E0:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA618:
	cmp r5, 0x47
	bne _080EA668
	ldr r0, =0x0000023e
	cmp r4, r0
	bne _080EA668
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA62C
	b _080EA820
_080EA62C:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	eors r1, r0
	b _080EA7FC
	.pool
_080EA668:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseGlitterMat
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA698
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA680
	b _080EA820
_080EA680:
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x80
	b _080EA7FA
	.pool
_080EA698:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseBalloon
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA72C
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	lsls r0, 16
	asrs r0, 16
	mov r1, sp
	movs r3, 0
	ldrsh r1, [r1, r3]
	movs r3, 0
	ldrsh r2, [r6, r3]
	bl sub_80FA5E4
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080EA6D0
	b _080EA820
_080EA6D0:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	movs r0, 0xCE
	lsls r0, 2
	cmp r1, r0
	beq _080EA70C
	cmp r1, r0
	bgt _080EA6FC
	movs r0, 0x8A
	lsls r0, 2
	cmp r1, r0
	beq _080EA714
	b _080EA820
	.pool
_080EA6FC:
	movs r0, 0xCF
	lsls r0, 2
	cmp r1, r0
	beq _080EA70C
	adds r0, 0x4
	cmp r1, r0
	beq _080EA70C
	b _080EA820
_080EA70C:
	ldr r4, =0x000040ee
	b _080EA7F0
	.pool
_080EA714:
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA72C:
	adds r0, r5, 0
	bl MetatileBehavior_IsMB_BE
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA778
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA75E
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EA75E:
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r6, r2]
	bl sub_80FA794
	b _080EA820
	.pool
_080EA778:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseSoundMat
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA7A8
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA820
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	b _080EA7FA
	.pool
_080EA7A8:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseJumpMat
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA7D8
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA820
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	b _080EA7FA
	.pool
_080EA7D8:
	adds r0, r5, 0
	bl MetatileBehavior_IsSecretBaseSpinMat
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EA820
	ldr r0, =gUnknown_0203A01D
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080EA820
	ldr r4, =0x000040ef
_080EA7F0:
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x2
_080EA7FA:
	orrs r1, r0
_080EA7FC:
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EA820
	.pool
_080EA810:
	ldrb r0, [r5, 0x8]
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080EA820
_080EA81C:
	movs r0, 0x1
	strh r0, [r5, 0x2]
_080EA820:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EA3E4

	thumb_func_start sub_80EA828
sub_80EA828: @ 80EA828
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r2, 0
	mov r8, r3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	lsls r2, r5, 2
	adds r2, r5
	lsls r4, r2, 5
	adds r0, r4
	ldr r2, =0x00001a9c
	mov r9, r2
	add r0, r9
	movs r2, 0xA0
	bl memcpy
	ldr r2, [r6]
	adds r2, r4
	ldr r0, =0x00001a9d
	adds r2, r0
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	subs r0, r7, 0x1
	cmp r0, 0x1
	bhi _080EA876
	ldr r0, [r6]
	adds r0, r4
	ldr r1, =0x00001aa9
	adds r0, r1
	movs r1, 0x2
	strb r1, [r0]
_080EA876:
	cmp r7, 0x3
	bne _080EA8B8
	mov r2, r8
	cmp r2, 0x1
	bne _080EA8B8
	mov r1, r9
	adds r0, r4, r1
	ldr r1, [r6]
	adds r1, r0
	adds r2, r1, 0x2
	movs r3, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0xFF
	beq _080EA8A0
_080EA892:
	adds r3, 0x1
	cmp r3, 0x6
	bgt _080EA8A0
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EA892
_080EA8A0:
	cmp r3, 0x5
	ble _080EA8B8
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	adds r1, r0
	ldr r2, =0x00001aa9
	adds r1, r2
	movs r0, 0x2
	strb r0, [r1]
_080EA8B8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EA828

	thumb_func_start sub_80EA8D4
sub_80EA8D4: @ 80EA8D4
	push {r4,lr}
	movs r2, 0
	adds r4, r0, 0
	adds r4, 0x9
	adds r3, r1, 0
	adds r3, 0x9
_080EA8E0:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080EA8F0
	movs r0, 0
	b _080EA8FC
_080EA8F0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080EA8E0
	movs r0, 0x1
_080EA8FC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA8D4

	thumb_func_start sub_80EA904
sub_80EA904: @ 80EA904
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r3, 0
	ldrb r0, [r6, 0x2]
	cmp r0, 0xFF
	bne _080EA918
	ldrb r0, [r5, 0x2]
	cmp r0, 0xFF
	beq _080EA946
_080EA918:
	adds r2, r6, 0x2
	adds r0, r2, r3
	adds r4, r5, 0x2
	adds r1, r4, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080EA92C
	movs r0, 0
	b _080EA948
_080EA92C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x6
	bhi _080EA946
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EA918
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EA918
_080EA946:
	movs r0, 0x1
_080EA948:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA904

	thumb_func_start sub_80EA950
sub_80EA950: @ 80EA950
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r2, [r4, 0x1]
	movs r0, 0x10
	adds r1, r0, 0
	ands r1, r2
	ldrb r2, [r5, 0x1]
	ands r0, r2
	cmp r1, r0
	bne _080EA986
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80EA8D4
	lsls r0, 24
	cmp r0, 0
	beq _080EA986
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80EA904
	lsls r0, 24
	cmp r0, 0
	beq _080EA986
	movs r0, 0x1
	b _080EA988
_080EA986:
	movs r0, 0
_080EA988:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA950

	thumb_func_start sub_80EA990
sub_80EA990: @ 80EA990
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r4, =0x00001a9c
_080EA99E:
	lsls r0, r1, 16
	asrs r1, r0, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r0, r2, r0
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, r3
	bne _080EA9C0
	adds r0, r1, 0
	b _080EA9D0
	.pool
_080EA9C0:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080EA99E
	movs r0, 0x1
	negs r0, r0
_080EA9D0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA990

	thumb_func_start sub_80EA9D8
sub_80EA9D8: @ 80EA9D8
	push {r4,lr}
	movs r2, 0x1
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r4, =0x00001a9c
_080EA9E2:
	lsls r0, r2, 16
	asrs r1, r0, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r0, r3, r0
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080EAA04
	lsls r0, r2, 24
	lsrs r0, 24
	b _080EAA12
	.pool
_080EAA04:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080EA9E2
	movs r0, 0
_080EAA12:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EA9D8

	thumb_func_start sub_80EAA18
sub_80EAA18: @ 80EAA18
	push {r4,lr}
	movs r3, 0x1
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
_080EAA20:
	lsls r2, r3, 16
	asrs r1, r2, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 5
	adds r0, r4, r0
	ldr r1, =0x00001a9d
	adds r0, r1
	ldrb r1, [r0]
	lsrs r0, r1, 6
	cmp r0, 0
	bne _080EAA4C
	lsls r0, r1, 28
	cmp r0, 0
	bne _080EAA4C
	lsls r0, r3, 24
	lsrs r0, 24
	b _080EAA5C
	.pool
_080EAA4C:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r2, r1
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _080EAA20
	movs r0, 0
_080EAA5C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80EAA18

	thumb_func_start sub_80EAA64
sub_80EAA64: @ 80EAA64
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080EAAEC
	ldrb r0, [r5]
	bl sub_80EA990
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	beq _080EAAEC
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080EAAC4
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 5
	adds r1, r0
	ldr r0, =0x00001a9d
	adds r1, r0
	ldrb r1, [r1]
	lsls r0, r1, 28
	lsrs r0, 28
	cmp r0, 0x1
	beq _080EAAEC
	lsrs r0, r1, 6
	cmp r0, 0x2
	bne _080EAAB4
	ldrb r1, [r5, 0x1]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _080EAAEC
_080EAAB4:
	lsls r4, 24
	lsrs r4, 24
	b _080EAADC
	.pool
_080EAAC4:
	bl sub_80EA9D8
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080EAADC
	bl sub_80EAA18
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080EAAEC
_080EAADC:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	adds r3, r7, 0
	bl sub_80EA828
	adds r0, r4, 0
	b _080EAAEE
_080EAAEC:
	movs r0, 0
_080EAAEE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80EAA64

	thumb_func_start sub_80EAAF4
sub_80EAAF4: @ 80EAAF4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xA0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r7, r0, r1
	movs r2, 0x1
_080EAB08:
	adds r1, r2, 0x1
	lsls r0, r1, 24
	lsrs r5, r0, 24
	mov r9, r1
	cmp r5, 0x13
	bhi _080EAB84
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 5
	adds r6, r0, r7
	movs r0, 0xC0
	mov r8, r0
_080EAB20:
	ldrb r0, [r6, 0x1]
	mov r3, r8
	ands r3, r0
	cmp r3, 0
	bne _080EAB3E
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 5
	adds r0, r7
	ldrb r1, [r0, 0x1]
	mov r0, r8
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0x40
	beq _080EAB56
_080EAB3E:
	cmp r3, 0x80
	bne _080EAB7A
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 5
	adds r0, r7
	ldrb r1, [r0, 0x1]
	mov r0, r8
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0x80
	beq _080EAB7A
_080EAB56:
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0xA0
	bl memcpy
	adds r4, r5
	lsls r4, 5
	adds r4, r7
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0xA0
	bl memcpy
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0xA0
	bl memcpy
_080EAB7A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAB20
_080EAB84:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r2, r0, 24
	cmp r2, 0x12
	bls _080EAB08
	add sp, 0xA0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EAAF4

	thumb_func_start sub_80EABA4
sub_80EABA4: @ 80EABA4
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r4, 0x1
_080EABAE:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 5
	adds r3, r1, r0
	ldrb r0, [r3, 0x1]
	lsrs r0, 6
	cmp r0, r6
	bne _080EABCA
	ldr r1, [r5, 0x4]
	ldr r2, [r5, 0x8]
	adds r0, r3, 0
	bl sub_80EAA64
_080EABCA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _080EABAE
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EABA4

	thumb_func_start sub_80EABDC
sub_80EABDC: @ 80EABDC
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080EABF8
	ldrb r0, [r5, 0x1]
	lsls r0, 27
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	lsrs r0, 31
	adds r6, r1, 0
	ldrb r1, [r3, 0x8]
	cmp r0, r1
	beq _080EAC00
_080EABF8:
	movs r0, 0
	b _080EAC56
	.pool
_080EAC00:
	movs r2, 0
	adds r4, r5, 0
	adds r4, 0x9
	adds r3, 0xA
_080EAC08:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080EABF8
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _080EAC08
	movs r2, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0xFF
	bne _080EAC2A
	ldr r0, [r6]
	b _080EAC4E
_080EAC2A:
	adds r3, r5, 0x2
	adds r0, r3, r2
	ldr r4, [r6]
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080EABF8
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x6
	bhi _080EAC54
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EAC2A
	adds r0, r4, r2
_080EAC4E:
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080EAC2A
_080EAC54:
	movs r0, 0x1
_080EAC56:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80EABDC

	thumb_func_start sub_80EAC5C
sub_80EAC5C: @ 80EAC5C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	mov r9, r1
	mov r8, r2
	movs r5, 0
	movs r6, 0
_080EAC70:
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	bne _080EAC9A
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 5
	mov r1, r10
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80EABDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EAC9A
	adds r0, r4, 0
	bl sub_80E8AF0
	movs r0, 0x1
	orrs r5, r0
_080EAC9A:
	movs r7, 0x2
	movs r0, 0x2
	ands r0, r5
	cmp r0, 0
	bne _080EACC8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 5
	mov r1, r9
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80EABDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EACC8
	adds r0, r4, 0
	bl sub_80E8AF0
	orrs r5, r7
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080EACC8:
	movs r7, 0x4
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	bne _080EACF6
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 5
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	bl sub_80EABDC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EACF6
	adds r0, r4, 0
	bl sub_80E8AF0
	orrs r5, r7
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080EACF6:
	cmp r5, 0x7
	beq _080EAD04
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x13
	bls _080EAC70
_080EAD04:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAC5C

	thumb_func_start sub_80EAD14
sub_80EAD14: @ 80EAD14
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r7, r2, 24
	movs r5, 0
_080EAD24:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	mov r1, r8
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080EAD7E
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80EA950
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080EAD7E
	cmp r7, 0
	bne _080EAD50
	adds r0, r4, 0
	bl sub_80E8AF0
	b _080EAD88
_080EAD50:
	ldrh r0, [r6, 0xE]
	ldrh r3, [r4, 0xE]
	cmp r0, r3
	bls _080EAD60
	adds r0, r4, 0
	bl sub_80E8AF0
	b _080EAD88
_080EAD60:
	ldrb r0, [r6, 0x1]
	lsls r0, 28
	lsrs r0, 28
	ldrb r1, [r4, 0x1]
	movs r3, 0x10
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, 0x1]
	adds r0, r6, 0
	bl sub_80E8AF0
	movs r0, 0x1
	b _080EAD8A
_080EAD7E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAD24
_080EAD88:
	movs r0, 0
_080EAD8A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80EAD14

	thumb_func_start sub_80EAD94
sub_80EAD94: @ 80EAD94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	adds r7, r1, 0
	mov r8, r2
	adds r6, r3, 0
	movs r5, 0x1
_080EADA6:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	mov r1, r9
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080EADF8
	ldrb r1, [r4, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	bne _080EADCE
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
_080EADCE:
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_80EAD14
	lsls r0, 24
	cmp r0, 0
	bne _080EADF8
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_80EAD14
	lsls r0, 24
	cmp r0, 0
	bne _080EADF8
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80EAD14
_080EADF8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EADA6
	movs r5, 0
_080EAE04:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 5
	adds r4, r0, r7
	ldrb r0, [r4]
	cmp r0, 0
	beq _080EAE38
	ldrb r0, [r4, 0x1]
	movs r2, 0x21
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_80EAD14
	lsls r0, 24
	cmp r0, 0
	bne _080EAE38
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80EAD14
_080EAE38:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAE04
	movs r5, 0
	movs r0, 0x21
	negs r0, r0
	adds r7, r0, 0
_080EAE4A:
	lsls r0, r5, 2
	adds r0, r5
	lsls r4, r0, 5
	mov r2, r8
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080EAE6A
	ldrb r0, [r1, 0x1]
	ands r0, r7
	strb r0, [r1, 0x1]
	adds r0, r1, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80EAD14
_080EAE6A:
	adds r1, r4, r6
	ldrb r0, [r1]
	cmp r0, 0
	beq _080EAE78
	ldrb r0, [r1, 0x1]
	ands r0, r7
	strb r0, [r1, 0x1]
_080EAE78:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x13
	bls _080EAE4A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAD94

	thumb_func_start sub_80EAE90
sub_80EAE90: @ 80EAE90
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	ldrb r1, [r4, 0x1]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _080EAEAE
	adds r0, r4, 0
	adds r1, r3, 0
	bl sub_80EAA64
	adds r0, r4, 0
	bl sub_80E8AF0
_080EAEAE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAE90

	thumb_func_start sub_80EAEB4
sub_80EAEB4: @ 80EAEB4
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
_080EAEBA:
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 5
	ldr r0, [r5]
	adds r0, r4
	ldr r1, [r5, 0x4]
	ldr r2, [r5, 0x8]
	bl sub_80EAE90
	ldr r0, [r5, 0xC]
	adds r0, r4
	ldr r1, [r5, 0x10]
	ldr r2, [r5, 0x14]
	bl sub_80EAE90
	ldr r0, [r5, 0x18]
	adds r0, r4
	ldr r1, [r5, 0x1C]
	ldr r2, [r5, 0x20]
	bl sub_80EAE90
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x13
	bls _080EAEBA
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80EAEB4

	thumb_func_start sub_80EAEF4
sub_80EAEF4: @ 80EAEF4
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	ldr r1, [r4, 0xC]
	ldr r2, [r4, 0x18]
	bl sub_80EAC5C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00001a9c
	adds r0, r1
	ldr r1, [r4]
	ldr r2, [r4, 0xC]
	ldr r3, [r4, 0x18]
	bl sub_80EAD94
	adds r0, r4, 0
	bl sub_80EAEB4
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	bl sub_80EAA64
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x10]
	ldr r2, [r4, 0x14]
	bl sub_80EAA64
	ldr r0, [r4, 0x18]
	ldr r1, [r4, 0x1C]
	ldr r2, [r4, 0x20]
	bl sub_80EAA64
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80EABA4
	adds r6, r4, 0
	adds r6, 0xC
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80EABA4
	adds r5, r4, 0
	adds r5, 0x18
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80EABA4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80EABA4
	adds r0, r6, 0
	movs r1, 0
	bl sub_80EABA4
	adds r0, r5, 0
	movs r1, 0
	bl sub_80EABA4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EAEF4

	thumb_func_start sub_80EAF80
sub_80EAF80: @ 80EAF80
	push {r4-r7,lr}
	sub sp, 0x24
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	movs r0, 0x60
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _080EAF9A
	b _080EB16A
_080EAF9A:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080EAFAC
	cmp r0, 0x3
	beq _080EAFC8
	b _080EAFD6
_080EAFAC:
	lsls r4, r5, 1
	adds r0, r6, r4
	movs r1, 0
	adds r2, r5, 0
	bl memset
	adds r4, r5
	adds r4, r6, r4
	adds r0, r4, 0
	movs r1, 0
	adds r2, r5, 0
	bl memset
	b _080EAFD6
_080EAFC8:
	lsls r0, r5, 1
	adds r0, r5
	adds r0, r6, r0
	movs r1, 0
	adds r2, r5, 0
	bl memset
_080EAFD6:
	cmp r7, 0x1
	beq _080EB030
	cmp r7, 0x1
	bgt _080EAFE4
	cmp r7, 0
	beq _080EAFEE
	b _080EB0D4
_080EAFE4:
	cmp r7, 0x2
	beq _080EB074
	cmp r7, 0x3
	beq _080EB0A8
	b _080EB0D4
_080EAFEE:
	adds r0, r6, r5
	str r0, [sp]
	ldr r4, =gLinkPlayers
	movs r3, 0xFF
	ldrb r0, [r4, 0x1C]
	str r0, [sp, 0x4]
	ldrh r0, [r4, 0x36]
	str r0, [sp, 0x8]
	lsls r1, r5, 1
	adds r0, r6, r1
	str r0, [sp, 0xC]
	ldrh r2, [r4, 0x38]
	adds r0, r3, 0
	ands r0, r2
	str r0, [sp, 0x10]
	adds r0, r4, 0
	adds r0, 0x52
	ldrh r0, [r0]
	str r0, [sp, 0x14]
	adds r1, r5
	adds r1, r6, r1
	str r1, [sp, 0x18]
	adds r0, r4, 0
	adds r0, 0x54
	ldrh r0, [r0]
	ands r3, r0
	str r3, [sp, 0x1C]
	adds r0, r4, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	b _080EB0D2
	.pool
_080EB030:
	lsls r2, r5, 1
	adds r0, r6, r2
	str r0, [sp]
	ldr r4, =gLinkPlayers
	ldrh r3, [r4, 0x38]
	movs r1, 0xFF
	adds r0, r1, 0
	ands r0, r3
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r0, 0x52
	ldrh r0, [r0]
	str r0, [sp, 0x8]
	adds r2, r5
	adds r2, r6, r2
	str r2, [sp, 0xC]
	adds r0, r4, 0
	adds r0, 0x54
	ldrh r2, [r0]
	adds r0, r1, 0
	ands r0, r2
	str r0, [sp, 0x10]
	adds r0, r4, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	str r0, [sp, 0x14]
	str r6, [sp, 0x18]
	ldrh r0, [r4]
	ands r1, r0
	str r1, [sp, 0x1C]
	ldrh r0, [r4, 0x1A]
	b _080EB0D2
	.pool
_080EB074:
	lsls r0, r5, 1
	adds r0, r5
	adds r0, r6, r0
	str r0, [sp]
	ldr r1, =gLinkPlayers
	adds r0, r1, 0
	adds r0, 0x54
	ldrb r0, [r0]
	str r0, [sp, 0x4]
	adds r0, r1, 0
	adds r0, 0x6E
	ldrh r0, [r0]
	str r0, [sp, 0x8]
	str r6, [sp, 0xC]
	ldrb r0, [r1]
	str r0, [sp, 0x10]
	ldrh r0, [r1, 0x1A]
	str r0, [sp, 0x14]
	adds r0, r6, r5
	str r0, [sp, 0x18]
	ldrb r0, [r1, 0x1C]
	str r0, [sp, 0x1C]
	ldrh r0, [r1, 0x36]
	b _080EB0D2
	.pool
_080EB0A8:
	str r6, [sp]
	ldr r1, =gLinkPlayers
	ldrb r0, [r1]
	str r0, [sp, 0x4]
	ldrh r0, [r1, 0x1A]
	str r0, [sp, 0x8]
	adds r0, r6, r5
	str r0, [sp, 0xC]
	movs r2, 0xFF
	ldrb r0, [r1, 0x1C]
	str r0, [sp, 0x10]
	ldrh r0, [r1, 0x36]
	str r0, [sp, 0x14]
	lsls r0, r5, 1
	adds r0, r6, r0
	str r0, [sp, 0x18]
	ldrh r0, [r1, 0x38]
	ands r2, r0
	str r2, [sp, 0x1C]
	adds r1, 0x52
	ldrh r0, [r1]
_080EB0D2:
	str r0, [sp, 0x20]
_080EB0D4:
	mov r0, sp
	bl sub_80EAEF4
	movs r3, 0x1
	ldr r6, =gSaveBlock1Ptr
	movs r7, 0x10
	negs r7, r7
_080EB0E2:
	ldr r0, [r6]
	lsls r1, r3, 2
	adds r1, r3
	lsls r4, r1, 5
	adds r0, r4
	ldr r5, =0x00001a9d
	adds r2, r0, r5
	ldrb r1, [r2]
	lsls r0, r1, 28
	lsrs r0, 28
	cmp r0, 0x1
	bne _080EB112
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r6]
	adds r1, r4
	adds r1, r5
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
_080EB112:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _080EB0E2
	bl sub_80EAAF4
	movs r3, 0x1
	ldr r7, =gSaveBlock1Ptr
	adds r6, r7, 0
	adds r4, r5, 0
	movs r5, 0x3F
_080EB12A:
	ldr r0, [r6]
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 5
	adds r0, r1
	adds r2, r0, r4
	ldrb r1, [r2]
	lsrs r0, r1, 6
	cmp r0, 0x2
	bne _080EB144
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
_080EB144:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _080EB12A
	ldr r1, [r7]
	ldr r2, =0x00001a9c
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080EB16A
	ldr r0, =0x00001aaa
	adds r2, r1, r0
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080EB16A
	adds r0, r1, 0x1
	strh r0, [r2]
_080EB16A:
	add sp, 0x24
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EAF80

	thumb_func_start sub_80EB18C
sub_80EB18C: @ 80EB18C
	push {r4,r5,lr}
	movs r5, 0
	adds r4, r0, 0
_080EB192:
	ldrb r0, [r4, 0xD]
	cmp r0, 0x1
	bne _080EB19E
	adds r0, r4, 0
	bl sub_80E8AF0
_080EB19E:
	adds r4, 0xA0
	adds r5, 0x1
	cmp r5, 0x13
	bls _080EB192
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80EB18C

	thumb_func_start sub_80EB1AC
sub_80EB1AC: @ 80EB1AC
	push {lr}
	ldr r0, =0x000040ec
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ed
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ee
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ef
	movs r1, 0
	bl VarSet
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB1FC
	ldr r0, =0x000040f0
	movs r1, 0x1
	bl VarSet
	b _080EB204
	.pool
_080EB1FC:
	ldr r0, =0x000040f0
	movs r1, 0
	bl VarSet
_080EB204:
	ldr r1, =gUnknown_0203A01D
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB1AC

	thumb_func_start sub_80EB218
sub_80EB218: @ 80EB218
	push {r4-r6,lr}
	ldr r5, =0x000040f0
	adds r0, r5, 0
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB272
	ldr r6, =gUnknown_0203A01D
	ldrb r0, [r6]
	cmp r0, 0x1
	bne _080EB272
	bl CurrentMapIsSecretBase
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080EB272
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
	strb r4, [r6]
	bl sub_80EEA70
	ldr r0, =0x000040ec
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ed
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ee
	movs r1, 0
	bl VarSet
	ldr r0, =0x000040ef
	movs r1, 0
	bl VarSet
	adds r0, r5, 0
	movs r1, 0
	bl VarSet
_080EB272:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB218

	thumb_func_start sub_80EB290
sub_80EB290: @ 80EB290
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB2BA
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB2BA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB290

	thumb_func_start sub_80EB2C8
sub_80EB2C8: @ 80EB2C8
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB2F2
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB2F2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB2C8

	thumb_func_start sub_80EB300
sub_80EB300: @ 80EB300
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB34C
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB34C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB300

	thumb_func_start sub_80EB368
sub_80EB368: @ 80EB368
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB3B4
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB3B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB368

	thumb_func_start sub_80EB3D0
sub_80EB3D0: @ 80EB3D0
	push {r4,r5,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB41C
	ldr r5, =0x000040ee
	adds r0, r5, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r5, 0
	bl VarSet
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r5, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl VarSet
_080EB41C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB3D0

	thumb_func_start sub_80EB438
sub_80EB438: @ 80EB438
	push {r4,lr}
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB480
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000c7ff
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r4, 0x1
	adds r0, r4, 0
	bl VarGet
	ldr r1, =0x0000fffe
	ands r1, r0
	adds r0, r4, 0
	bl VarSet
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x1
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB480:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB438

	thumb_func_start sub_80EB498
sub_80EB498: @ 80EB498
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffce4
	adds r0, r1
	cmp r0, 0x18
	bhi _080EB55C
	lsls r0, 2
	ldr r1, =_080EB4D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EB4D0:
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB55C
	.4byte _080EB55C
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
	.4byte _080EB534
_080EB534:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB55C
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB55C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB498

	thumb_func_start sub_80EB56C
sub_80EB56C: @ 80EB56C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffdd4
	adds r0, r1
	cmp r0, 0xCF
	bls _080EB594
	b _080EB9D0
_080EB594:
	lsls r0, 2
	ldr r1, =_080EB5A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EB5A8:
	.4byte _080EB930
	.4byte _080EB97C
	.4byte _080EB97C
	.4byte _080EB97C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB930
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB954
	.4byte _080EB954
	.4byte _080EB8E8
	.4byte _080EB8E8
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9AC
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB9D0
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
	.4byte _080EB90C
_080EB8E8:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x40
	b _080EB994
	.pool
_080EB90C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ee
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EB994
	.pool
_080EB930:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x40
	b _080EB994
	.pool
_080EB954:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	b _080EB994
	.pool
_080EB97C:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
_080EB994:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EB9D0
	.pool
_080EB9AC:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EB9D0
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EB9D0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB56C

	thumb_func_start sub_80EB9E0
sub_80EB9E0: @ 80EB9E0
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffd6f
	adds r0, r1
	cmp r0, 0x35
	bls _080EBA08
	b _080EBB18
_080EBA08:
	lsls r0, 2
	ldr r1, =_080EBA1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBA1C:
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
	.4byte _080EBB18
	.4byte _080EBB18
	.4byte _080EBAF4
_080EBAF4:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBB18
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBB18:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EB9E0

	thumb_func_start sub_80EBB28
sub_80EBB28: @ 80EBB28
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0xfffffddb
	adds r0, r1
	cmp r0, 0xA2
	bls _080EBB50
	b _080EBE6C
_080EBB50:
	lsls r0, 2
	ldr r1, =_080EBB64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080EBB64:
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE48
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE14
	.4byte _080EBE14
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBE6C
	.4byte _080EBDF0
	.4byte _080EBDF0
	.4byte _080EBE6C
	.4byte _080EBDF0
_080EBDF0:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x8
	b _080EBE30
	.pool
_080EBE14:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
_080EBE30:
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
	b _080EBE6C
	.pool
_080EBE48:
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBE6C
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x10
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBE6C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBB28

	thumb_func_start sub_80EBE7C
sub_80EBE7C: @ 80EBE7C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x0000028e
	cmp r1, r0
	bgt _080EBECC
	subs r0, 0x1
	cmp r1, r0
	blt _080EBECC
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	cmp r0, 0
	beq _080EBECC
	ldr r4, =0x000040ef
	adds r0, r4, 0
	bl VarGet
	adds r1, r0, 0
	movs r0, 0x4
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl VarSet
_080EBECC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80EBE7C

	.align 2, 0 @ Don't pad with nop.
