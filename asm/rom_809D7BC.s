	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_809D7BC
sub_809D7BC: @ 809D7BC
	push {lr}
	movs r0, 0x1
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7BC

	thumb_func_start sub_809D7C8
sub_809D7C8: @ 809D7C8
	push {lr}
	movs r0, 0x2
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7C8

	thumb_func_start sub_809D7D4
sub_809D7D4: @ 809D7D4
	push {lr}
	movs r0, 0x3
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7D4

	thumb_func_start sub_809D7E0
sub_809D7E0: @ 809D7E0
	push {lr}
	movs r0, 0x4
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7E0

	thumb_func_start sub_809D7EC
sub_809D7EC: @ 809D7EC
	push {lr}
	movs r0, 0x5
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7EC

	thumb_func_start sub_809D7F8
sub_809D7F8: @ 809D7F8
	push {lr}
	movs r0, 0x6
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D7F8

	thumb_func_start sub_809D804
sub_809D804: @ 809D804
	push {lr}
	movs r0, 0x9
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D804

	thumb_func_start sub_809D810
sub_809D810: @ 809D810
	push {lr}
	movs r0, 0x7
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D810

	thumb_func_start sub_809D81C
sub_809D81C: @ 809D81C
	push {lr}
	movs r0, 0x8
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D81C

	thumb_func_start sub_809D828
sub_809D828: @ 809D828
	push {lr}
	movs r0, 0xB
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D828

	thumb_func_start sub_809D834
sub_809D834: @ 809D834
	push {lr}
	movs r0, 0xC
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D834

	thumb_func_start sub_809D840
sub_809D840: @ 809D840
	push {lr}
	movs r0, 0x14
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D840

	thumb_func_start sub_809D84C
sub_809D84C: @ 809D84C
	push {lr}
	movs r0, 0x15
	bl sub_80AEDF0
	pop {r0}
	bx r0
	thumb_func_end sub_809D84C

	thumb_func_start trigger_activate_weather
trigger_activate_weather: @ 809D858
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r2, 0
	ldr r3, =gUnknown_085102E0
_0809D862:
	lsls r1, r2, 3
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r4
	bne _0809D87C
	adds r0, r3, 0x4
	adds r0, r1, r0
	ldr r0, [r0]
	bl _call_via_r0
	b _0809D886
	.pool
_0809D87C:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xC
	bls _0809D862
_0809D886:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end trigger_activate_weather

	thumb_func_start task_per_step_callback_manager
task_per_step_callback_manager: @ 809D88C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	ldr r2, =gUnknown_08510348
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end task_per_step_callback_manager

	thumb_func_start sub_809D8B8
sub_809D8B8: @ 809D8B8
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0809D8CA
	cmp r0, 0x1
	beq _0809D8E8
	b _0809D8FC
_0809D8CA:
	ldr r0, =gUnknown_030022C0
	ldr r0, [r0, 0x20]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	beq _0809D8FC
	bl sub_809E7B0
	ldrh r0, [r4]
	adds r0, 0x1
	b _0809D8FA
	.pool
_0809D8E8:
	ldr r0, =gUnknown_030022C0
	ldr r0, [r0, 0x20]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _0809D8FC
	ldrh r0, [r4]
	subs r0, 0x1
_0809D8FA:
	strh r0, [r4]
_0809D8FC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D8B8

	thumb_func_start sub_809D908
sub_809D908: @ 809D908
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	bl script_env_2_is_enabled
	lsls r0, 24
	cmp r0, 0
	bne _0809D930
	adds r0, r4, 0
	bl sub_809D8B8
	adds r0, r4, 0x2
	adds r1, r4, 0x4
	bl wild_encounter_related
_0809D930:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809D908

	thumb_func_start overworld_ensure_per_step_coros_running
overworld_ensure_per_step_coros_running: @ 809D93C
	push {r4,r5,lr}
	ldr r5, =task_per_step_callback_manager
	adds r0, r5, 0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0809D966
	adds r0, r5, 0
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
_0809D966:
	ldr r4, =sub_809E638
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0809D97C
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
_0809D97C:
	ldr r4, =sub_809D908
	adds r0, r4, 0
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0809D992
	adds r0, r4, 0
	movs r1, 0x50
	bl CreateTask
_0809D992:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end overworld_ensure_per_step_coros_running

	thumb_func_start activate_per_step_callback
activate_per_step_callback: @ 809D9A8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =task_per_step_callback_manager
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _0809D9EA
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r1, r0, r1
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x1E
_0809D9CC:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _0809D9CC
	cmp r4, 0x7
	bls _0809D9E8
	movs r0, 0
	strh r0, [r1]
	b _0809D9EA
	.pool
_0809D9E8:
	strh r4, [r1]
_0809D9EA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end activate_per_step_callback

	thumb_func_start wild_encounter_reset_coro_args
wild_encounter_reset_coro_args: @ 809D9F0
	push {lr}
	ldr r0, =task_per_step_callback_manager
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =sub_809D908
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _0809DA1A
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
_0809DA1A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end wild_encounter_reset_coro_args

	thumb_func_start nullsub_34
nullsub_34: @ 809DA2C
	bx lr
	thumb_func_end nullsub_34

	thumb_func_start sub_809DA30
sub_809DA30: @ 809DA30
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	adds r0, r4, 0
	bl sub_8089764
	lsls r0, 24
	cmp r0, 0
	beq _0809DA48
	adds r0, r5, 0
	b _0809DA80
_0809DA48:
	adds r0, r4, 0
	bl sub_8089778
	lsls r0, 24
	cmp r0, 0
	beq _0809DA5A
	adds r0, r5, 0
	adds r0, 0x8
	b _0809DA80
_0809DA5A:
	adds r0, r4, 0
	bl sub_808978C
	lsls r0, 24
	cmp r0, 0
	beq _0809DA6C
	adds r0, r5, 0
	adds r0, 0x10
	b _0809DA80
_0809DA6C:
	adds r0, r4, 0
	bl sub_80897A0
	lsls r0, 24
	cmp r0, 0
	bne _0809DA7C
	movs r0, 0
	b _0809DA80
_0809DA7C:
	adds r0, r5, 0
	adds r0, 0x18
_0809DA80:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809DA30

	thumb_func_start sub_809DA88
sub_809DA88: @ 809DA88
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r3
	lsls r1, 16
	asrs r6, r1, 16
	lsls r2, 16
	asrs r7, r2, 16
	adds r0, r6, 0
	adds r1, r7, 0
	bl MapGridGetMetatileBehaviorAt
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_809DA30
	adds r4, r0, 0
	adds r5, r4, 0
	cmp r4, 0
	beq _0809DB06
	movs r0, 0
	ldrsb r0, [r4, r0]
	adds r0, r6, r0
	movs r1, 0x1
	ldrsb r1, [r4, r1]
	adds r1, r7, r1
	ldrh r2, [r4, 0x2]
	bl MapGridSetMetatileIdAt
	mov r0, r8
	cmp r0, 0
	beq _0809DADE
	movs r0, 0
	ldrsb r0, [r4, r0]
	adds r0, r6, r0
	movs r1, 0x1
	ldrsb r1, [r4, r1]
	adds r1, r7, r1
	bl CurrentMapDrawMetatileAt
_0809DADE:
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	adds r0, r6, r0
	movs r1, 0x5
	ldrsb r1, [r5, r1]
	adds r1, r7, r1
	ldrh r2, [r5, 0x6]
	bl MapGridSetMetatileIdAt
	mov r0, r8
	cmp r0, 0
	beq _0809DB06
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	adds r0, r6, r0
	movs r1, 0x5
	ldrsb r1, [r5, r1]
	adds r1, r7, r1
	bl CurrentMapDrawMetatileAt
_0809DB06:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809DA88

	thumb_func_start sub_809DB10
sub_809DB10: @ 809DB10
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldr r0, =gUnknown_08510368
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_809DA88
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809DB10

	thumb_func_start sub_809DB34
sub_809DB34: @ 809DB34
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldr r0, =gUnknown_08510388
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_809DA88
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809DB34

	thumb_func_start sub_809DB58
sub_809DB58: @ 809DB58
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldr r0, =gUnknown_085103A8
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_809DA88
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809DB58

	thumb_func_start sub_809DB7C
sub_809DB7C: @ 809DB7C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	mov r10, r8
	lsls r1, 16
	lsrs r7, r1, 16
	mov r9, r7
	lsls r2, 16
	asrs r6, r2, 16
	lsls r3, 16
	asrs r5, r3, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8089764
	lsls r0, 24
	cmp r0, 0
	beq _0809DBC0
	lsls r0, r7, 16
	asrs r0, 16
	cmp r0, r5
	ble _0809DC06
_0809DBBC:
	movs r0, 0
	b _0809DC08
_0809DBC0:
	adds r0, r4, 0
	bl sub_8089778
	lsls r0, 24
	cmp r0, 0
	beq _0809DBD8
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r5
	bge _0809DC06
	b _0809DBBC
_0809DBD8:
	adds r0, r4, 0
	bl sub_808978C
	lsls r0, 24
	cmp r0, 0
	beq _0809DBF0
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r6
	ble _0809DC06
	b _0809DBBC
_0809DBF0:
	adds r0, r4, 0
	bl sub_80897A0
	lsls r0, 24
	cmp r0, 0
	beq _0809DC06
	mov r1, r10
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, r6
	blt _0809DBBC
_0809DC06:
	movs r0, 0x1
_0809DC08:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809DB7C

	thumb_func_start sub_809DC18
sub_809DC18: @ 809DC18
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	mov r10, r8
	lsls r3, 16
	lsrs r7, r3, 16
	mov r9, r7
	lsls r0, 16
	asrs r6, r0, 16
	lsls r1, 16
	asrs r5, r1, 16
	adds r0, r6, 0
	adds r1, r5, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8089764
	lsls r0, 24
	cmp r0, 0
	beq _0809DC5C
	lsls r0, r7, 16
	asrs r0, 16
	cmp r5, r0
	bge _0809DCA2
_0809DC58:
	movs r0, 0
	b _0809DCA4
_0809DC5C:
	adds r0, r4, 0
	bl sub_8089778
	lsls r0, 24
	cmp r0, 0
	beq _0809DC74
	mov r1, r9
	lsls r0, r1, 16
	asrs r0, 16
	cmp r5, r0
	ble _0809DCA2
	b _0809DC58
_0809DC74:
	adds r0, r4, 0
	bl sub_808978C
	lsls r0, 24
	cmp r0, 0
	beq _0809DC8C
	mov r1, r8
	lsls r0, r1, 16
	asrs r0, 16
	cmp r6, r0
	bge _0809DCA2
	b _0809DC58
_0809DC8C:
	adds r0, r4, 0
	bl sub_80897A0
	lsls r0, 24
	cmp r0, 0
	beq _0809DCA2
	mov r1, r10
	lsls r0, r1, 16
	asrs r0, 16
	cmp r6, r0
	bgt _0809DC58
_0809DCA2:
	movs r0, 0x1
_0809DCA4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809DC18

	thumb_func_start sub_809DCB4
sub_809DCB4: @ 809DCB4
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	mov r5, sp
	adds r5, 0x2
	mov r0, sp
	adds r1, r5, 0
	bl PlayerGetDestCoords
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r6, r5, 0
	cmp r0, 0x1
	beq _0809DD0E
	cmp r0, 0x1
	bgt _0809DCEC
	cmp r0, 0
	beq _0809DCF2
	b _0809DE1E
	.pool
_0809DCEC:
	cmp r0, 0x2
	beq _0809DDDC
	b _0809DE1E
_0809DCF2:
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x4]
	ldrh r0, [r5]
	strh r0, [r4, 0x6]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r3, 0
	ldrsh r1, [r5, r3]
	movs r2, 0x1
	bl sub_809DB34
	b _0809DE1A
_0809DD0E:
	mov r0, sp
	movs r7, 0
	ldrsh r1, [r0, r7]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0809DD28
	movs r3, 0
	ldrsh r1, [r5, r3]
	movs r7, 0x6
	ldrsh r0, [r4, r7]
	cmp r1, r0
	beq _0809DE1E
_0809DD28:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r5, 0x6
	ldrsh r3, [r4, r5]
	bl sub_809DB7C
	cmp r0, 0
	beq _0809DD70
	movs r7, 0x4
	ldrsh r0, [r4, r7]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	movs r2, 0x1
	bl sub_809DB10
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	movs r5, 0x6
	ldrsh r1, [r4, r5]
	movs r2, 0
	bl sub_809DB58
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r4, 0xA]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	movs r0, 0x8
	strh r0, [r4, 0xC]
	b _0809DD7A
_0809DD70:
	movs r7, 0x1
	negs r7, r7
	adds r0, r7, 0
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
_0809DD7A:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r5, r6, 0
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	movs r7, 0x6
	ldrsh r3, [r4, r7]
	bl sub_809DC18
	cmp r0, 0
	beq _0809DDAE
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r2, 0x1
	bl sub_809DB10
	movs r0, 0x2
	strh r0, [r4, 0x2]
	movs r0, 0x8
	strh r0, [r4, 0xC]
_0809DDAE:
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x4]
	ldrh r0, [r6]
	strh r0, [r4, 0x6]
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r5, 0
	ldrsh r1, [r6, r5]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsPacifidlogLog
	lsls r0, 24
	cmp r0, 0
	beq _0809DE1E
	movs r0, 0x46
	bl audio_play
	b _0809DE1E
_0809DDDC:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _0809DE1E
	mov r0, sp
	movs r7, 0
	ldrsh r0, [r0, r7]
	movs r2, 0
	ldrsh r1, [r5, r2]
	movs r2, 0x1
	bl sub_809DB34
	movs r3, 0x8
	ldrsh r0, [r4, r3]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _0809DE1A
	movs r5, 0xA
	ldrsh r0, [r4, r5]
	cmp r0, r1
	beq _0809DE1A
	movs r7, 0x8
	ldrsh r0, [r4, r7]
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r2, 0x1
	bl sub_809DB58
_0809DE1A:
	movs r0, 0x1
	strh r0, [r4, 0x2]
_0809DE1E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809DCB4

	thumb_func_start sub_809DE28
sub_809DE28: @ 809DE28
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	bl PlayerGetZCoord
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809DE82
	lsls r0, r4, 16
	asrs r4, r0, 16
	lsls r0, r5, 16
	asrs r5, r0, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x0000024e
	cmp r1, r0
	beq _0809DE68
	adds r0, 0x8
	cmp r1, r0
	beq _0809DE78
	b _0809DE82
	.pool
_0809DE68:
	ldr r2, =0x0000024f
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _0809DE82
	.pool
_0809DE78:
	ldr r2, =0x00000257
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_0809DE82:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809DE28

	thumb_func_start sub_809DE8C
sub_809DE8C: @ 809DE8C
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	bl PlayerGetZCoord
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809DEE6
	lsls r0, r4, 16
	asrs r4, r0, 16
	lsls r0, r5, 16
	asrs r5, r0, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridGetMetatileIdAt
	adds r1, r0, 0
	ldr r0, =0x0000024f
	cmp r1, r0
	beq _0809DECC
	adds r0, 0x8
	cmp r1, r0
	beq _0809DEDC
	b _0809DEE6
	.pool
_0809DECC:
	ldr r2, =0x0000024e
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
	b _0809DEE6
	.pool
_0809DEDC:
	ldr r2, =0x00000256
	adds r0, r4, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_0809DEE6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809DE8C

	thumb_func_start sub_809DEF0
sub_809DEF0: @ 809DEF0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r6, r1, r0
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	movs r0, 0x2
	ldrsh r5, [r6, r0]
	mov r9, r4
	cmp r5, 0x1
	beq _0809DF84
	cmp r5, 0x1
	bgt _0809DF30
	cmp r5, 0
	beq _0809DF38
	b _0809E0F6
	.pool
_0809DF30:
	cmp r5, 0x2
	bne _0809DF36
	b _0809E064
_0809DF36:
	b _0809E0F6
_0809DF38:
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6, 0x4]
	mov r1, r9
	ldrh r0, [r1]
	strh r0, [r6, 0x6]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r3, 0
	ldrsh r1, [r1, r3]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsFortreeBridge
	lsls r0, 24
	cmp r0, 0
	bne _0809DF62
	b _0809E0F2
_0809DF62:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r2, r9
	movs r3, 0
	ldrsh r1, [r2, r3]
	bl sub_809DE28
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r2, r9
	movs r3, 0
	ldrsh r1, [r2, r3]
	bl CurrentMapDrawMetatileAt
	b _0809E0F2
_0809DF84:
	ldrh r0, [r6, 0x6]
	mov r8, r0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6, 0x4]
	mov r10, r2
	movs r3, 0x4
	ldrsh r7, [r6, r3]
	cmp r0, r7
	bne _0809DFAC
	mov r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r3, r8
	lsls r0, r3, 16
	asrs r0, 16
	cmp r1, r0
	bne _0809DFAC
	b _0809E0F6
_0809DFAC:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r2, r9
	movs r3, 0
	ldrsh r1, [r2, r3]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsFortreeBridge
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	mov r0, r8
	lsls r4, r0, 16
	asrs r1, r4, 16
	adds r0, r7, 0
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsFortreeBridge
	lsls r0, 24
	lsrs r7, r0, 24
	bl PlayerGetZCoord
	movs r1, 0
	ands r5, r0
	lsls r0, r5, 24
	adds r5, r4, 0
	cmp r0, 0
	bne _0809DFF4
	movs r1, 0x1
_0809DFF4:
	cmp r1, 0
	beq _0809E008
	ldr r1, [sp, 0x4]
	cmp r1, 0x1
	beq _0809E002
	cmp r7, 0x1
	bne _0809E008
_0809E002:
	movs r0, 0x47
	bl audio_play
_0809E008:
	cmp r7, 0
	beq _0809E044
	mov r2, r10
	lsls r4, r2, 16
	asrs r4, 16
	asrs r5, 16
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_809DE8C
	adds r0, r4, 0
	adds r1, r5, 0
	bl CurrentMapDrawMetatileAt
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	mov r2, r9
	movs r3, 0
	ldrsh r1, [r2, r3]
	bl sub_809DE28
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r2, r9
	movs r3, 0
	ldrsh r1, [r2, r3]
	bl CurrentMapDrawMetatileAt
_0809E044:
	mov r0, r10
	strh r0, [r6, 0x8]
	mov r1, r8
	strh r1, [r6, 0xA]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6, 0x4]
	mov r2, r9
	ldrh r0, [r2]
	strh r0, [r6, 0x6]
	cmp r7, 0
	beq _0809E0F6
	movs r0, 0x10
	strh r0, [r6, 0xC]
	movs r0, 0x2
	strh r0, [r6, 0x2]
_0809E064:
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	ldrh r3, [r6, 0x8]
	mov r10, r3
	ldrh r0, [r6, 0xA]
	mov r8, r0
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	movs r1, 0x7
	bl __modsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _0809E0EA
	lsls r0, 2
	ldr r1, =_0809E094
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0809E094:
	.4byte _0809E0B4
	.4byte _0809E0EA
	.4byte _0809E0EA
	.4byte _0809E0EA
	.4byte _0809E0C6
	.4byte _0809E0EA
	.4byte _0809E0EA
	.4byte _0809E0EA
_0809E0B4:
	mov r2, r10
	lsls r0, r2, 16
	asrs r0, 16
	mov r3, r8
	lsls r1, r3, 16
	asrs r1, 16
	bl CurrentMapDrawMetatileAt
	b _0809E0EA
_0809E0C6:
	mov r0, r10
	lsls r5, r0, 16
	asrs r5, 16
	mov r1, r8
	lsls r4, r1, 16
	asrs r4, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_809DE28
	adds r0, r5, 0
	adds r1, r4, 0
	bl CurrentMapDrawMetatileAt
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_809DE8C
_0809E0EA:
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0809E0F6
_0809E0F2:
	movs r0, 0x1
	strh r0, [r6, 0x2]
_0809E0F6:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809DEF0

	thumb_func_start sub_809E108
sub_809E108: @ 809E108
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	lsls r0, 16
	ldr r2, =0xfffd0000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0xA
	bhi _0809E144
	lsls r0, r1, 16
	asrs r1, r0, 16
	ldr r2, =0xfffa0000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0xD
	bhi _0809E144
	ldr r0, =gUnknown_085103C8
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _0809E144
	movs r0, 0x1
	b _0809E146
	.pool
_0809E144:
	movs r0, 0
_0809E146:
	pop {r1}
	bx r1
	thumb_func_end sub_809E108

	thumb_func_start sub_809E14C
sub_809E14C: @ 809E14C
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_809E108
	cmp r0, 0
	beq _0809E17A
	ldr r1, =gUnknown_085103C8
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	bl GetVarPointer
	subs r2, r5, 0x3
	movs r1, 0x1
	lsls r1, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
_0809E17A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E14C

	thumb_func_start sub_809E184
sub_809E184: @ 809E184
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_809E108
	cmp r0, 0
	beq _0809E1B6
	ldr r1, =gUnknown_085103C8
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	bl VarGet
	lsls r0, 16
	subs r2, r5, 0x3
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r2
	ands r1, r0
	cmp r1, 0
	bne _0809E1C0
_0809E1B6:
	movs r0, 0
	b _0809E1C2
	.pool
_0809E1C0:
	movs r0, 0x1
_0809E1C2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809E184

	thumb_func_start sub_809E1C8
sub_809E1C8: @ 809E1C8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gUnknown_02037318
	ldr r0, [r0]
	ldr r1, [r0]
	mov r9, r1
	ldr r7, [r0, 0x4]
	movs r5, 0
	cmp r5, r9
	bge _0809E210
_0809E1E0:
	movs r4, 0
	adds r0, r5, 0x1
	mov r8, r0
	cmp r4, r7
	bge _0809E20A
	lsls r6, r5, 16
_0809E1EC:
	lsls r1, r4, 16
	asrs r1, 16
	asrs r0, r6, 16
	bl sub_809E184
	cmp r0, 0x1
	bne _0809E204
	adds r1, r4, 0x7
	adds r0, r5, 0x7
	ldr r2, =0x0000020e
	bl MapGridSetMetatileIdAt
_0809E204:
	adds r4, 0x1
	cmp r4, r7
	blt _0809E1EC
_0809E20A:
	mov r5, r8
	cmp r5, r9
	blt _0809E1E0
_0809E210:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E1C8

	thumb_func_start sub_809E224
sub_809E224: @ 809E224
	push {r4-r7,lr}
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
	beq _0809E270
	cmp r0, 0x1
	bgt _0809E24C
	cmp r0, 0
	beq _0809E258
	b _0809E3A6
	.pool
_0809E24C:
	cmp r0, 0x2
	beq _0809E306
	cmp r0, 0x3
	bne _0809E256
	b _0809E360
_0809E256:
	b _0809E3A6
_0809E258:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, 0x4]
	ldrh r0, [r4]
	strh r0, [r5, 0x6]
	b _0809E3A2
_0809E270:
	mov r7, sp
	adds r7, 0x2
	mov r0, sp
	adds r1, r7, 0
	bl PlayerGetDestCoords
	mov r0, sp
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _0809E29A
	movs r0, 0
	ldrsh r1, [r7, r0]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _0809E29A
	b _0809E3A6
_0809E29A:
	strh r2, [r5, 0x4]
	ldrh r0, [r7]
	strh r0, [r5, 0x6]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r7, r2]
	bl MapGridGetMetatileBehaviorAt
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x00004022
	bl GetVarPointer
	adds r6, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8089604
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809E2E0
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r0, 0x2
	b _0809E2F8
	.pool
_0809E2E0:
	adds r0, r4, 0
	bl sub_8089618
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809E3A6
	movs r0, 0
	strh r0, [r6]
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r0, 0x3
_0809E2F8:
	strh r0, [r5, 0x2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, 0x8]
	ldrh r0, [r7]
	strh r0, [r5, 0xA]
	b _0809E3A6
_0809E306:
	ldrh r1, [r5, 0xC]
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	cmp r0, 0
	bne _0809E36A
	mov r1, sp
	ldrh r0, [r5, 0x8]
	strh r0, [r1]
	mov r4, sp
	adds r4, 0x2
	ldrh r0, [r5, 0xA]
	strh r0, [r4]
	movs r0, 0x2A
	bl audio_play
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	ldr r2, =0x0000020e
	bl MapGridSetMetatileIdAt
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x7
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r4]
	subs r1, 0x7
	lsls r1, 16
	asrs r1, 16
	bl sub_809E14C
	b _0809E3A2
	.pool
_0809E360:
	ldrh r1, [r5, 0xC]
	movs r3, 0xC
	ldrsh r0, [r5, r3]
	cmp r0, 0
	beq _0809E370
_0809E36A:
	subs r0, r1, 0x1
	strh r0, [r5, 0xC]
	b _0809E3A6
_0809E370:
	mov r1, sp
	ldrh r0, [r5, 0x8]
	strh r0, [r1]
	mov r4, sp
	adds r4, 0x2
	ldrh r0, [r5, 0xA]
	strh r0, [r4]
	movs r0, 0x29
	bl audio_play
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	ldr r2, =0x00000206
	bl MapGridSetMetatileIdAt
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl CurrentMapDrawMetatileAt
_0809E3A2:
	movs r0, 0x1
	strh r0, [r5, 0x2]
_0809E3A6:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E224

	thumb_func_start sub_809E3B4
sub_809E3B4: @ 809E3B4
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _0809E3EE
	movs r0, 0
	ldrsh r1, [r4, r0]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r1, r0
	beq _0809E47A
_0809E3EE:
	strh r2, [r5, 0x2]
	ldrh r0, [r4]
	strh r0, [r5, 0x4]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsAsh
	lsls r0, 24
	cmp r0, 0
	beq _0809E47A
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileIdAt
	ldr r1, =0x0000020a
	cmp r0, r1
	bne _0809E444
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r4, r2]
	ldr r2, =0x00000212
	movs r3, 0x4
	bl ash
	b _0809E456
	.pool
_0809E444:
	mov r0, sp
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r2, 0
	ldrsh r1, [r4, r2]
	ldr r2, =0x00000206
	movs r3, 0x4
	bl ash
_0809E456:
	movs r0, 0x87
	lsls r0, 1
	movs r1, 0x1
	bl sub_80D6724
	lsls r0, 24
	cmp r0, 0
	beq _0809E47A
	ldr r0, =0x00004048
	bl GetVarPointer
	adds r2, r0, 0
	ldrh r1, [r2]
	ldr r0, =0x0000270e
	cmp r1, r0
	bhi _0809E47A
	adds r0, r1, 0x1
	strh r0, [r2]
_0809E47A:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E3B4

	thumb_func_start sub_809E490
sub_809E490: @ 809E490
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridGetMetatileIdAt
	ldr r1, =0x0000022f
	ldr r2, =0x00000237
	cmp r0, r1
	bne _0809E4AC
	subs r2, 0x31
_0809E4AC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0
	adds r1, r4, 0
	bl CurrentMapDrawMetatileAt
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E490

	thumb_func_start sub_809E4CC
sub_809E4CC: @ 809E4CC
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 16
	lsrs r6, r0, 16
	ldrh r1, [r5, 0x8]
	movs r3, 0x8
	ldrsh r0, [r5, r3]
	adds r7, r4, 0
	cmp r0, 0
	beq _0809E51E
	subs r0, r1, 0x1
	strh r0, [r5, 0x8]
	lsls r0, 16
	cmp r0, 0
	bne _0809E51E
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	bl sub_809E490
_0809E51E:
	ldrh r1, [r5, 0xE]
	movs r3, 0xE
	ldrsh r0, [r5, r3]
	cmp r0, 0
	beq _0809E53E
	subs r0, r1, 0x1
	strh r0, [r5, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _0809E53E
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_809E490
_0809E53E:
	lsls r0, r6, 24
	lsrs r6, r0, 24
	adds r0, r6, 0
	bl sub_8089918
	lsls r0, 24
	cmp r0, 0
	beq _0809E556
	ldr r0, =0x00004022
	movs r1, 0
	bl VarSet
_0809E556:
	mov r0, sp
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _0809E572
	movs r0, 0
	ldrsh r1, [r7, r0]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r1, r0
	beq _0809E5D2
_0809E572:
	strh r2, [r5, 0x4]
	adds r4, r7, 0
	ldrh r0, [r4]
	strh r0, [r5, 0x6]
	adds r0, r6, 0
	bl sub_808992C
	lsls r0, 24
	cmp r0, 0
	beq _0809E5D2
	bl sub_811A138
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	beq _0809E59A
	ldr r0, =0x00004022
	movs r1, 0
	bl VarSet
_0809E59A:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _0809E5BC
	movs r0, 0x3
	strh r0, [r5, 0x8]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, 0xA]
	ldrh r0, [r4]
	strh r0, [r5, 0xC]
	b _0809E5D2
	.pool
_0809E5BC:
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r0, 0
	bne _0809E5D2
	movs r0, 0x3
	strh r0, [r5, 0xE]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, 0x10]
	ldrh r0, [r7]
	strh r0, [r5, 0x12]
_0809E5D2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809E4CC

	thumb_func_start sub_809E5DC
sub_809E5DC: @ 809E5DC
	push {r4,r5,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	ldrh r0, [r3]
	subs r0, 0x1
	strh r0, [r3]
	lsls r0, 16
	cmp r0, 0
	bne _0809E5F8
	movs r2, 0xE8
	b _0809E60C
_0809E5F8:
	ldr r1, =gUnknown_085103FC
	movs r2, 0
	ldrsh r0, [r3, r2]
	cmp r0, 0
	bge _0809E604
	adds r0, 0x7
_0809E604:
	asrs r0, 3
	lsls r0, 1
	adds r0, r1
	ldrh r2, [r0]
_0809E60C:
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl MapGridSetMetatileIdAt
	adds r0, r5, 0
	adds r1, r4, 0
	bl CurrentMapDrawMetatileAt
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0xE8
	bl MapGridSetMetatileIdAt
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E5DC

	thumb_func_start sub_809E638
sub_809E638: @ 809E638
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	mov r5, sp
	adds r5, 0x2
	mov r0, sp
	adds r1, r5, 0
	bl PlayerGetDestCoords
	ldr r0, =gUnknown_03005D8C
	ldr r0, [r0]
	movs r1, 0x4
	ldrsb r1, [r0, r1]
	lsls r1, 8
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	orrs r0, r1
	lsls r0, 16
	lsrs r7, r0, 16
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	mov r8, r5
	cmp r1, 0
	beq _0809E688
	cmp r1, 0x1
	beq _0809E6B4
	b _0809E708
	.pool
_0809E688:
	strh r7, [r4]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0x4]
	ldrh r0, [r5]
	strh r0, [r4, 0x6]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	strh r1, [r4, 0x8]
	strh r1, [r4, 0xE]
	strh r1, [r4, 0x14]
	strh r1, [r4, 0x1A]
	b _0809E708
_0809E6A2:
	movs r0, 0x20
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r1, 0x2]
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r1, 0x4]
	b _0809E708
_0809E6B4:
	mov r0, sp
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _0809E6D0
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r3, 0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	beq _0809E708
_0809E6D0:
	strh r2, [r4, 0x4]
	ldrh r0, [r5]
	strh r0, [r4, 0x6]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsMuddySlope
	lsls r0, 24
	cmp r0, 0
	beq _0809E708
	movs r6, 0x4
	adds r1, r4, 0
	adds r1, 0x8
_0809E6F8:
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0809E6A2
	adds r1, 0x6
	adds r6, 0x3
	cmp r6, 0xD
	ble _0809E6F8
_0809E708:
	ldr r2, =gUnknown_02037334
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809E728
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r7, r0
	beq _0809E728
	strh r7, [r4]
	ldrh r0, [r2, 0x4]
	ldrh r1, [r2, 0x8]
	b _0809E72C
	.pool
_0809E728:
	movs r0, 0
	movs r1, 0
_0809E72C:
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	lsls r0, r1, 16
	asrs r7, r0, 16
	adds r5, r4, 0
	adds r5, 0x8
	adds r4, r5, 0
	movs r6, 0x9
_0809E73E:
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0809E762
	ldrh r0, [r4, 0x2]
	mov r3, r8
	subs r0, r3
	strh r0, [r4, 0x2]
	ldrh r0, [r4, 0x4]
	subs r0, r7
	strh r0, [r4, 0x4]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	adds r0, r5, 0
	bl sub_809E5DC
_0809E762:
	adds r4, 0x6
	adds r5, 0x6
	subs r6, 0x3
	cmp r6, 0
	bge _0809E73E
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809E638

	thumb_func_start sub_809E778
sub_809E778: @ 809E778
	push {lr}
	ldr r0, =0x00000895
	bl FlagSet
	bl GameFreakRTC_CalcLocalDateTime
	ldr r0, =gUnknown_03005D90
	ldr r2, [r0]
	adds r2, 0xA0
	ldr r3, =gUnknown_03005CF8
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =0x00004040
	ldrh r1, [r3]
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E778

	thumb_func_start sub_809E7B0
sub_809E7B0: @ 809E7B0
	push {r4,lr}
	ldr r0, =0x00000895
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809E7DA
	bl sub_813B9C0
	lsls r0, 24
	cmp r0, 0
	bne _0809E7DA
	bl GameFreakRTC_CalcLocalDateTime
	ldr r4, =gUnknown_03005CF8
	adds r0, r4, 0
	bl sub_809E7E8
	adds r0, r4, 0
	bl sub_809E858
_0809E7DA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E7B0

	thumb_func_start sub_809E7E8
sub_809E7E8: @ 809E7E8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =0x00004040
	bl GetVarPointer
	adds r6, r0, 0
	ldrh r0, [r6]
	movs r2, 0
	ldrsh r1, [r5, r2]
	cmp r0, r1
	beq _0809E84E
	cmp r0, r1
	bgt _0809E84E
	ldrh r4, [r5]
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	bl sub_809D3A0
	adds r0, r4, 0
	bl sub_8122580
	adds r0, r4, 0
	bl sub_80ED888
	adds r0, r4, 0
	bl sub_80AEFBC
	adds r0, r4, 0
	bl sub_806DE44
	adds r0, r4, 0
	bl sub_8137904
	adds r0, r4, 0
	bl sub_8137A20
	adds r0, r4, 0
	bl sub_8139EF4
	adds r0, r4, 0
	bl sub_813A7F4
	adds r0, r4, 0
	bl sub_813945C
	adds r0, r4, 0
	bl sub_8177584
	ldrh r0, [r5]
	strh r0, [r6]
_0809E84E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E7E8

	thumb_func_start sub_809E858
sub_809E858: @ 809E858
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	mov r4, sp
	ldr r6, =gUnknown_03005D90
	ldr r1, [r6]
	adds r1, 0xA0
	mov r0, sp
	adds r2, r5, 0
	bl GameFreakRTC_GetDelta
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	movs r2, 0x2
	ldrsb r2, [r4, r2]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 2
	adds r1, r0
	movs r0, 0x3
	ldrsb r0, [r4, r0]
	adds r0, r1, r0
	cmp r0, 0
	beq _0809E8A8
	cmp r0, 0
	blt _0809E8A8
	bl BerryTreeTimeUpdate
	ldr r2, [r6]
	adds r2, 0xA0
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
_0809E8A8:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E858

	thumb_func_start sub_809E8B4
sub_809E8B4: @ 809E8B4
	push {lr}
	bl sub_809E778
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E8B4

	thumb_func_start Special_StartWallClock
Special_StartWallClock: @ 809E8C8
	push {lr}
	ldr r0, =Cb2_StartWallClock
	bl SetMainCallback2
	ldr r1, =gUnknown_030022C0
	ldr r0, =sub_809E8B4
	str r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end Special_StartWallClock

	.align 2, 0 @ Don't pad with nop.
