	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_808A400
sub_808A400: @ 808A400
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2, 0x3]
	cmp r0, 0x2
	bne _0808A420
	ldrh r1, [r1, 0x2]
	ldr r0, [r2, 0x4]
	adds r0, r1
	ldr r1, =0x06007e00
	movs r2, 0x80
	bl CpuFastSet
	b _0808A42E
	.pool
_0808A420:
	ldrh r1, [r1, 0x2]
	ldr r0, [r2, 0x4]
	adds r0, r1
	ldr r1, =0x06007f00
	movs r2, 0x40
	bl CpuFastSet
_0808A42E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A400

	thumb_func_start door_build_blockdef
door_build_blockdef: @ 808A438
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
	adds r1, r6, 0
_0808A444:
	ldrb r0, [r2]
	lsls r0, 28
	lsrs r3, r0, 16
	adds r2, 0x1
	adds r0, r5, r4
	orrs r3, r0
	strh r3, [r1]
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _0808A444
	cmp r4, 0x7
	bgt _0808A472
	lsls r0, r4, 1
	adds r1, r0, r6
_0808A462:
	ldrb r0, [r2]
	lsls r3, r0, 12
	adds r2, 0x1
	strh r3, [r1]
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x7
	ble _0808A462
_0808A472:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end door_build_blockdef

	thumb_func_start door_patch_tilemap
door_patch_tilemap: @ 808A478
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x30
	adds r7, r1, 0
	mov r9, r2
	adds r5, r3, 0
	ldrb r0, [r0, 0x3]
	cmp r0, 0x2
	bne _0808A4F4
	add r4, sp, 0x10
	movs r1, 0xFC
	lsls r1, 2
	adds r0, r4, 0
	adds r2, r5, 0
	bl door_build_blockdef
	mov r6, r9
	subs r6, 0x1
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl DrawDoorMetatileAt
	movs r1, 0xFD
	lsls r1, 2
	adds r0, r5, 0x4
	mov r8, r0
	adds r0, r4, 0
	mov r2, r8
	bl door_build_blockdef
	adds r0, r7, 0
	mov r1, r9
	adds r2, r4, 0
	bl DrawDoorMetatileAt
	movs r1, 0xFE
	lsls r1, 2
	adds r0, r4, 0
	adds r2, r5, 0
	bl door_build_blockdef
	adds r5, r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl DrawDoorMetatileAt
	movs r1, 0xFF
	lsls r1, 2
	adds r0, r4, 0
	mov r2, r8
	bl door_build_blockdef
	adds r0, r5, 0
	mov r1, r9
	adds r2, r4, 0
	bl DrawDoorMetatileAt
	b _0808A522
_0808A4F4:
	movs r1, 0xFE
	lsls r1, 2
	mov r0, sp
	adds r2, r5, 0
	bl door_build_blockdef
	mov r1, r9
	subs r1, 0x1
	adds r0, r7, 0
	mov r2, sp
	bl DrawDoorMetatileAt
	movs r1, 0xFF
	lsls r1, 2
	adds r2, r5, 0x4
	mov r0, sp
	bl door_build_blockdef
	adds r0, r7, 0
	mov r1, r9
	mov r2, sp
	bl DrawDoorMetatileAt
_0808A522:
	add sp, 0x30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end door_patch_tilemap

	thumb_func_start sub_808A530
sub_808A530: @ 808A530
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	subs r7, r6, 0x1
	adds r0, r5, 0
	adds r1, r7, 0
	bl CurrentMapDrawMetatileAt
	adds r0, r5, 0
	adds r1, r6, 0
	bl CurrentMapDrawMetatileAt
	ldrb r0, [r4, 0x3]
	cmp r0, 0x2
	bne _0808A562
	adds r4, r5, 0x1
	adds r0, r4, 0
	adds r1, r7, 0
	bl CurrentMapDrawMetatileAt
	adds r0, r4, 0
	adds r1, r6, 0
	bl CurrentMapDrawMetatileAt
_0808A562:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808A530

	thumb_func_start sub_808A568
sub_808A568: @ 808A568
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldrh r1, [r5, 0x2]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0808A5B0
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_808A530
	bl sub_808A964
	lsls r0, 24
	cmp r0, 0
	beq _0808A5E2
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	adds r1, 0x7
	ldr r0, =gSpecialVar_0x8005
	ldrh r2, [r0]
	adds r2, 0x7
	adds r0, r4, 0
	bl sub_808A530
	b _0808A5E2
	.pool
_0808A5B0:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808A400
	ldr r3, [r4, 0x8]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl door_patch_tilemap
	bl sub_808A964
	lsls r0, 24
	cmp r0, 0
	beq _0808A5E2
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	adds r1, 0x7
	ldr r0, =gSpecialVar_0x8005
	ldrh r2, [r0]
	adds r2, 0x7
	ldr r3, [r4, 0x8]
	adds r0, r4, 0
	bl door_patch_tilemap
_0808A5E2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A568

	thumb_func_start sub_808A5F0
sub_808A5F0: @ 808A5F0
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0808A616
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	lsls r1, 2
	adds r1, r5, r1
	movs r0, 0xC
	ldrsh r2, [r4, r0]
	movs r0, 0xE
	ldrsh r3, [r4, r0]
	adds r0, r6, 0
	bl sub_808A568
_0808A616:
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0]
	cmp r1, r0
	bne _0808A644
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0808A64A
	movs r0, 0
	b _0808A64C
_0808A644:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
_0808A64A:
	movs r0, 0x1
_0808A64C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808A5F0

	thumb_func_start task50_overworld_door
task50_overworld_door: @ 808A654
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldrh r1, [r2]
	lsls r1, 16
	ldrh r0, [r2, 0x2]
	orrs r1, r0
	ldrh r0, [r2, 0x4]
	lsls r0, 16
	ldrh r3, [r2, 0x6]
	orrs r0, r3
	bl sub_808A5F0
	cmp r0, 0
	bne _0808A682
	adds r0, r4, 0
	bl DestroyTask
_0808A682:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task50_overworld_door

	thumb_func_start door_frame_last
door_frame_last: @ 808A68C
	push {lr}
	adds r1, r0, 0
	b _0808A694
_0808A692:
	adds r1, 0x4
_0808A694:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0808A692
	subs r0, r1, 0x4
	pop {r1}
	bx r1
	thumb_func_end door_frame_last

	thumb_func_start door_find
door_find: @ 808A6A0
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	b _0808A6B6
_0808A6AA:
	ldrh r0, [r2]
	cmp r0, r1
	bne _0808A6B4
	adds r0, r2, 0
	b _0808A6BE
_0808A6B4:
	adds r2, 0xC
_0808A6B6:
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _0808A6AA
	movs r0, 0
_0808A6BE:
	pop {r1}
	bx r1
	thumb_func_end door_find

	thumb_func_start task_overworld_door_add_if_inactive
task_overworld_door_add_if_inactive: @ 808A6C4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	mov r8, r3
	ldr r4, =task50_overworld_door
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0808A718
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r2, =gTasks + 0x8
	adds r1, r2
	strh r7, [r1, 0xC]
	mov r2, r8
	strh r2, [r1, 0xE]
	strh r5, [r1, 0x2]
	lsrs r2, r5, 16
	strh r2, [r1]
	strh r6, [r1, 0x6]
	lsrs r2, r6, 16
	strh r2, [r1, 0x4]
	lsls r0, 24
	asrs r0, 24
	b _0808A71C
	.pool
_0808A718:
	movs r0, 0x1
	negs r0, r0
_0808A71C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end task_overworld_door_add_if_inactive

	thumb_func_start sub_808A728
sub_808A728: @ 808A728
	push {lr}
	bl sub_808A530
	pop {r0}
	bx r0
	thumb_func_end sub_808A728

	thumb_func_start sub_808A734
sub_808A734: @ 808A734
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl door_find
	adds r4, r0, 0
	cmp r4, 0
	beq _0808A76A
	ldr r1, =gUnknown_08496F8C
	adds r0, r1, 0
	bl door_frame_last
	adds r1, r0, 0
	adds r0, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_808A568
_0808A76A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A734

	thumb_func_start task_overworld_door_add_for_opening_door_at
@ s32 task_overworld_door_add_for_opening_door_at(void *a1, s32 x, s32 y)
task_overworld_door_add_for_opening_door_at: @ 808A774
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl door_find
	adds r2, r0, 0
	adds r4, r2, 0
	cmp r2, 0
	bne _0808A79E
	movs r0, 0x1
	negs r0, r0
	b _0808A7C0
_0808A79E:
	ldrb r0, [r2, 0x3]
	cmp r0, 0x2
	beq _0808A7B0
	ldr r1, =gUnknown_08496F8C
	adds r0, r2, 0
	b _0808A7B4
	.pool
_0808A7B0:
	ldr r1, =gUnknown_08496FB4
	adds r0, r4, 0
_0808A7B4:
	adds r2, r5, 0
	adds r3, r6, 0
	bl task_overworld_door_add_if_inactive
	lsls r0, 24
	asrs r0, 24
_0808A7C0:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end task_overworld_door_add_for_opening_door_at

	thumb_func_start sub_808A7CC
sub_808A7CC: @ 808A7CC
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0
	adds r1, r6, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl door_find
	cmp r0, 0
	beq _0808A800
	ldr r1, =gUnknown_08496FA0
	adds r2, r5, 0
	adds r3, r6, 0
	bl task_overworld_door_add_if_inactive
	lsls r0, 24
	asrs r0, 24
	b _0808A804
	.pool
_0808A800:
	movs r0, 0x1
	negs r0, r0
_0808A804:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808A7CC

	thumb_func_start cur_mapdata_get_door_x2_at
cur_mapdata_get_door_x2_at: @ 808A80C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl door_find
	cmp r0, 0
	beq _0808A830
	ldrb r0, [r0, 0x2]
	lsls r0, 24
	asrs r0, 24
	b _0808A834
_0808A830:
	movs r0, 0x1
	negs r0, r0
_0808A834:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end cur_mapdata_get_door_x2_at

	thumb_func_start sub_808A83C
sub_808A83C: @ 808A83C
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gUnknown_08497174
	adds r1, r3, 0
	bl task_overworld_door_add_for_opening_door_at
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A83C

	thumb_func_start sub_808A854
sub_808A854: @ 808A854
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsDoor
	lsls r0, 24
	cmp r0, 0
	beq _0808A876
	ldr r0, =gUnknown_08497174
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_808A734
_0808A876:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A854

	thumb_func_start sub_808A880
sub_808A880: @ 808A880
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsDoor
	lsls r0, 24
	cmp r0, 0
	beq _0808A8A2
	ldr r0, =gUnknown_08497174
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_808A728
_0808A8A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_808A880

	thumb_func_start sub_808A8AC
sub_808A8AC: @ 808A8AC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsDoor
	lsls r0, 24
	cmp r0, 0
	beq _0808A8D8
	ldr r0, =gUnknown_08497174
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_808A7CC
	lsls r0, 24
	asrs r0, 24
	b _0808A8DC
	.pool
_0808A8D8:
	movs r0, 0x1
	negs r0, r0
_0808A8DC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808A8AC

	thumb_func_start task_overworld_door_add_if_role_69_for_opening_door_at
task_overworld_door_add_if_role_69_for_opening_door_at: @ 808A8E4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsDoor
	lsls r0, 24
	cmp r0, 0
	beq _0808A910
	ldr r0, =gUnknown_08497174
	adds r1, r4, 0
	adds r2, r5, 0
	bl task_overworld_door_add_for_opening_door_at
	lsls r0, 24
	asrs r0, 24
	b _0808A914
	.pool
_0808A910:
	movs r0, 0x1
	negs r0, r0
_0808A914:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end task_overworld_door_add_if_role_69_for_opening_door_at

	thumb_func_start sub_808A91C
sub_808A91C: @ 808A91C
	push {lr}
	ldr r0, =task50_overworld_door
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_808A91C

	thumb_func_start cur_mapdata_get_door_sound_at
cur_mapdata_get_door_sound_at: @ 808A930
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gUnknown_08497174
	adds r1, r3, 0
	bl cur_mapdata_get_door_x2_at
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _0808A958
	cmp r0, 0x1
	bne _0808A954
	movs r0, 0x12
	b _0808A95E
	.pool
_0808A954:
	cmp r0, 0x2
	beq _0808A95C
_0808A958:
	movs r0, 0x8
	b _0808A95E
_0808A95C:
	movs r0, 0x2F
_0808A95E:
	pop {r1}
	bx r1
	thumb_func_end cur_mapdata_get_door_sound_at

	thumb_func_start sub_808A964
sub_808A964: @ 808A964
	push {lr}
	ldr r0, =0x00004002
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0808A990
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000101a
	cmp r1, r0
	bne _0808A990
	movs r0, 0x1
	b _0808A992
	.pool
_0808A990:
	movs r0, 0
_0808A992:
	pop {r1}
	bx r1
	thumb_func_end sub_808A964

	.align 2, 0 @ Don't pad with nop.
