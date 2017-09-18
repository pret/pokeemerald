	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start exec_movement
exec_movement: @ 80D32E8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r3, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	beq _080D330A
	movs r0, 0x1
	b _080D3332
_080D330A:
	ldr r0, =sub_80D3660
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080D331C
	movs r0, 0x32
	bl sub_80D33AC
_080D331C:
	bl sub_80D33F4
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	ldrb r1, [r1]
	adds r2, r4, 0
	bl sub_80D3408
	lsls r0, 24
	lsrs r0, 24
_080D3332:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end exec_movement

	thumb_func_start sub_80D3340
sub_80D3340: @ 80D3340
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _080D3382
	bl sub_80D33F4
	lsls r0, 24
	lsrs r4, r0, 24
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_80D3474
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x10
	beq _080D3382
	adds r0, r4, 0
	bl sub_80D3584
	lsls r0, 24
	lsrs r0, 24
	b _080D3384
_080D3382:
	movs r0, 0x1
_080D3384:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D3340

	thumb_func_start sub_80D338C
sub_80D338C: @ 80D338C
	push {r4,lr}
	bl sub_80D33F4
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _080D33A6
	adds r0, r4, 0
	bl sub_80D361C
	adds r0, r4, 0
	bl DestroyTask
_080D33A6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80D338C

	thumb_func_start sub_80D33AC
sub_80D33AC: @ 80D33AC
	push {r4,r5,lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =sub_80D3660
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x1
	lsls r1, r0, 2
	adds r1, r0
	lsls r3, r1, 3
	ldr r5, =gTasks + 0x8
	ldr r0, =0x0000ffff
	adds r4, r0, 0
_080D33CC:
	lsls r0, r2, 1
	adds r0, r3
	adds r0, r5
	ldrh r1, [r0]
	orrs r1, r4
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080D33CC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D33AC

	thumb_func_start sub_80D33F4
sub_80D33F4: @ 80D33F4
	push {lr}
	ldr r0, =sub_80D3660
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D33F4

	thumb_func_start sub_80D3408
sub_80D3408: @ 80D3408
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	lsls r1, 24
	lsrs r6, r1, 24
	mov r8, r6
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80D3474
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x10
	beq _080D3444
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80D3584
	lsls r0, 24
	cmp r0, 0
	beq _080D3464
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	b _080D345A
_080D3444:
	adds r0, r7, 0
	movs r1, 0xFF
	bl sub_80D3474
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x10
	beq _080D3464
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r8
_080D345A:
	mov r3, r9
	bl sub_80D35DC
	movs r0, 0
	b _080D3466
_080D3464:
	movs r0, 0x1
_080D3466:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D3408

	thumb_func_start sub_80D3474
sub_80D3474: @ 80D3474
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	adds r1, 0x2
	movs r2, 0
_080D348C:
	ldrb r0, [r1]
	cmp r0, r3
	bne _080D349C
	adds r0, r2, 0
	b _080D34AA
	.pool
_080D349C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r1, 0x1
	cmp r2, 0xF
	bls _080D348C
	movs r0, 0x10
_080D34AA:
	pop {r1}
	bx r1
	thumb_func_end sub_80D3474

	thumb_func_start sub_80D34B0
sub_80D34B0: @ 80D34B0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	adds r1, 0x2
	str r1, [r2]
	movs r0, 0
	cmp r0, r3
	bcs _080D34DC
_080D34CE:
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	adds r1, 0x1
	cmp r0, r3
	bcc _080D34CE
	str r1, [r2]
_080D34DC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D34B0

	thumb_func_start sub_80D34E4
sub_80D34E4: @ 80D34E4
	push {r4,lr}
	sub sp, 0x4
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 24
	lsrs r4, 24
	mov r2, sp
	bl sub_80D34B0
	ldr r0, [sp]
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80D34E4

	thumb_func_start sub_80D3508
sub_80D3508: @ 80D3508
	push {r4,lr}
	sub sp, 0x4
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r2, sp
	bl sub_80D34B0
	ldr r0, [sp]
	ldrb r0, [r0]
	strb r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80D3508

	thumb_func_start sub_80D352C
sub_80D352C: @ 80D352C
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r2, =gBitTable
	lsrs r1, 22
	adds r1, r2
	ldr r2, [r1]
	mvns r2, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r3, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	ldrh r0, [r1, 0x8]
	ands r2, r0
	strh r2, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end sub_80D352C

	thumb_func_start sub_80D355C
sub_80D355C: @ 80D355C
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	ldr r0, =gBitTable
	lsrs r1, 22
	adds r1, r0
	ldr r0, [r1]
	ldrh r1, [r2, 0x8]
	orrs r0, r1
	strh r0, [r2, 0x8]
	bx lr
	.pool
	thumb_func_end sub_80D355C

	thumb_func_start sub_80D3584
sub_80D3584: @ 80D3584
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	ldr r0, =gBitTable
	lsrs r1, 22
	adds r1, r0
	ldr r0, [r1]
	ldrh r1, [r2, 0x8]
	ands r0, r1
	cmp r0, 0
	bne _080D35B4
	movs r0, 0
	b _080D35B6
	.pool
_080D35B4:
	movs r0, 0x1
_080D35B6:
	pop {r1}
	bx r1
	thumb_func_end sub_80D3584

	thumb_func_start npc_obj_offscreen_culling_and_flag_update
npc_obj_offscreen_culling_and_flag_update: @ 80D35BC
	lsls r0, 24
	ldr r2, =gUnknown_02039D90
	lsrs r0, 22
	adds r0, r2
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end npc_obj_offscreen_culling_and_flag_update

	thumb_func_start sub_80D35CC
sub_80D35CC: @ 80D35CC
	lsls r0, 24
	ldr r1, =gUnknown_02039D90
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80D35CC

	thumb_func_start sub_80D35DC
sub_80D35DC: @ 80D35DC
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80D352C
	adds r0, r4, 0
	mov r1, r8
	bl npc_obj_offscreen_culling_and_flag_update
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_80D34E4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80D35DC

	thumb_func_start sub_80D361C
sub_80D361C: @ 80D361C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r1, r0
	adds r4, r1, 0x2
	movs r5, 0
_080D3630:
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _080D3646
	adds r1, r0, 0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r0, r1
	bl npc_sync_anim_pause_bits
_080D3646:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x1
	cmp r5, 0xF
	bls _080D3630
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D361C

	thumb_func_start sub_80D3660
sub_80D3660: @ 80D3660
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	movs r5, 0
	mov r6, sp
_080D366C:
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_80D3508
	ldrb r0, [r6]
	cmp r0, 0xFF
	beq _080D3690
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_80D35CC
	adds r3, r0, 0
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80D36A4
_080D3690:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xF
	bls _080D366C
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D3660

	thumb_func_start sub_80D36A4
sub_80D36A4: @ 80D36A4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r3, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	mov r8, r6
	lsls r2, 24
	lsrs r2, 24
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r1, =gMapObjects
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080D36DC
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080D370E
_080D36DC:
	ldrb r1, [r5]
	cmp r1, 0xFE
	bne _080D36F8
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80D355C
	adds r0, r4, 0
	bl sub_8097404
	b _080D370E
	.pool
_080D36F8:
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	lsls r0, 24
	cmp r0, 0
	bne _080D370E
	adds r5, 0x1
	mov r0, r8
	adds r1, r5, 0
	bl npc_obj_offscreen_culling_and_flag_update
_080D370E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80D36A4

	.align 2, 0 @ Don't pad with nop.
