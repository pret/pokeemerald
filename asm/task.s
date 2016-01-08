	thumb_func_start clear_tasks
; void clear_tasks()
clear_tasks: ; 80A8F50
	push {r4-r7,lr}
	movs r4, 0
	ldr r6, =0x03005e00
	adds r7, r6, 0
	adds r7, 0x8
_080A8F5A:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r6
	movs r1, 0
	strb r1, [r2, 0x4]
	ldr r1, =nullsub_4
	str r1, [r2]
	strb r4, [r2, 0x5]
	adds r4, 0x1
	strb r4, [r2, 0x6]
	movs r1, 0x1
	negs r1, r1
	adds r5, r1, 0
	movs r1, 0xFF
	strb r1, [r2, 0x7]
	adds r0, r7
	movs r1, 0
	movs r2, 0x20
	bl memset
	lsls r4, 24
	lsrs r4, 24
	cmp r4, 0xF
	bls _080A8F5A
	ldr r0, =0x03005e00
	movs r1, 0xFE
	strb r1, [r0, 0x5]
	ldr r1, =0x0000025e
	adds r0, r1
	ldrb r1, [r0]
	orrs r1, r5
	strb r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end clear_tasks

	thumb_func_start AddTask
; int AddTask(void ( *func)(int task_id), u8 priority)
AddTask: ; 80A8FB0
	push {r4-r7,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r6, 0
	ldr r7, =0x03005e00
_080A8FBC:
	lsls r0, r6, 2
	adds r0, r6
	lsls r5, r0, 3
	adds r4, r5, r7
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _080A8FF0
	str r2, [r4]
	strb r1, [r4, 0x7]
	adds r0, r6, 0
	bl insert_task_in_order_by_priority
	adds r0, r7, 0
	adds r0, 0x8
	adds r0, r5, r0
	movs r1, 0
	movs r2, 0x20
	bl memset
	movs r0, 0x1
	strb r0, [r4, 0x4]
	adds r0, r6, 0
	b _080A8FFC
	.pool
_080A8FF0:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xF
	bls _080A8FBC
	movs r0, 0
_080A8FFC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AddTask

	thumb_func_start insert_task_in_order_by_priority
; void insert_task_in_order_by_priority(int task_id)
insert_task_in_order_by_priority: ; 80A9004
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	bl get_first_active_task
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x10
	bne _080A9034
	ldr r1, =0x03005e00
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0xFE
	strb r1, [r0, 0x5]
	movs r1, 0xFF
	strb r1, [r0, 0x6]
	b _080A9090
	.pool
_080A9034:
	ldr r6, =0x03005e00
	lsls r0, r4, 2
	mov r12, r0
	mov r8, r6
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r6
_080A9042:
	lsls r0, r1, 2
	adds r0, r1
	lsls r5, r0, 3
	mov r7, r8
	adds r3, r5, r7
	ldrb r0, [r2, 0x7]
	ldrb r7, [r3, 0x7]
	cmp r0, r7
	bcs _080A9074
	ldrb r0, [r3, 0x5]
	strb r0, [r2, 0x5]
	strb r1, [r2, 0x6]
	ldrb r0, [r3, 0x5]
	cmp r0, 0xFE
	beq _080A906C
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	add r0, r8
	strb r4, [r0, 0x6]
_080A906C:
	strb r4, [r3, 0x5]
	b _080A9090
	.pool
_080A9074:
	ldrb r0, [r3, 0x6]
	cmp r0, 0xFF
	beq _080A907E
	adds r1, r0, 0
	b _080A9042
_080A907E:
	mov r2, r12
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r6
	strb r1, [r0, 0x5]
	adds r2, r5, r6
	ldrb r1, [r2, 0x6]
	strb r1, [r0, 0x6]
	strb r4, [r2, 0x6]
_080A9090:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end insert_task_in_order_by_priority

	thumb_func_start remove_task
; void remove_task(int task_id)
remove_task: ; 80A909C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r2, r1, r4
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	beq _080A9106
	movs r0, 0
	strb r0, [r2, 0x4]
	ldrb r3, [r2, 0x5]
	cmp r3, 0xFE
	bne _080A90D4
	ldrb r0, [r2, 0x6]
	cmp r0, 0xFF
	beq _080A9106
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	strb r3, [r0, 0x5]
	b _080A9106
	.pool
_080A90D4:
	ldrb r3, [r2, 0x6]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _080A90EC
	ldrb r0, [r2, 0x5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0xFF
	strb r0, [r1, 0x6]
	b _080A9106
_080A90EC:
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	strb r3, [r0, 0x6]
	ldrb r1, [r2, 0x6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldrb r1, [r2, 0x5]
	strb r1, [r0, 0x5]
_080A9106:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end remove_task

	thumb_func_start RunActiveTasks
; void RunActiveTasks()
RunActiveTasks: ; 80A910C
	push {r4,r5,lr}
	bl get_first_active_task
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _080A9130
	ldr r5, =0x03005e00
_080A911C:
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r5
	ldr r1, [r4]
	bl _call_via_r1
	ldrb r0, [r4, 0x6]
	cmp r0, 0xFF
	bne _080A911C
_080A9130:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RunActiveTasks

	thumb_func_start get_first_active_task
; int get_first_active_task()
get_first_active_task: ; 80A913C
	push {lr}
	movs r2, 0
	ldr r0, =0x03005e00
	ldrb r1, [r0, 0x4]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _080A9150
	ldrb r0, [r3, 0x5]
	cmp r0, 0xFE
	beq _080A916E
_080A9150:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bhi _080A916E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r3
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	bne _080A9150
	ldrb r0, [r1, 0x5]
	cmp r0, 0xFE
	bne _080A9150
_080A916E:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end get_first_active_task

	thumb_func_start nullsub_4
nullsub_4: ; 80A9178
	bx lr
	thumb_func_end nullsub_4

	thumb_func_start set_task_function_and_args_14_15
set_task_function_and_args_14_15: ; 80A917C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =0x03005e00
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 3
	adds r0, r3, 0
	adds r0, 0x1C
	adds r4, r5, 0
	adds r4, 0x8
	adds r0, r4
	strh r2, [r0]
	adds r0, r3, 0
	adds r0, 0x1E
	adds r0, r4
	lsrs r2, 16
	strh r2, [r0]
	adds r3, r5
	str r1, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_task_function_and_args_14_15

	thumb_func_start set_task_function_to_args_14_15
set_task_function_to_args_14_15: ; 80A91B0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0x03005e00
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r3
	adds r0, r1, 0
	adds r0, 0x1C
	adds r3, 0x8
	adds r0, r3
	ldrh r2, [r0]
	adds r1, 0x1E
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	lsls r0, 16
	orrs r2, r0
	str r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_task_function_to_args_14_15

	thumb_func_start is_function_an_active_task
; int is_function_an_active_task(void ( *func)(int task_id))
is_function_an_active_task: ; 80A91E4
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r4, =0x03005e00
_080A91EC:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r4
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	bne _080A9208
	ldr r0, [r1]
	cmp r0, r3
	bne _080A9208
	movs r0, 0x1
	b _080A9214
	.pool
_080A9208:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _080A91EC
	movs r0, 0
_080A9214:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end is_function_an_active_task

	thumb_func_start get_task_id_by_function
; int get_task_id_by_function(void ( *func)(int task_id))
get_task_id_by_function: ; 80A921C
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r1, =0x03005e00
_080A9224:
	ldrb r0, [r1, 0x4]
	cmp r0, 0x1
	bne _080A923C
	ldr r0, [r1]
	cmp r0, r3
	bne _080A923C
	lsls r0, r2, 24
	lsrs r0, 24
	b _080A9246
	.pool
_080A923C:
	adds r1, 0x28
	adds r2, 0x1
	cmp r2, 0xF
	ble _080A9224
	movs r0, 0xFF
_080A9246:
	pop {r1}
	bx r1
	thumb_func_end get_task_id_by_function

	thumb_func_start sub_80A924C
sub_80A924C: ; 80A924C
	push {lr}
	movs r2, 0
	movs r1, 0
	ldr r3, =0x03005e00
_080A9254:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x4]
	cmp r0, 0x1
	bne _080A9268
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
_080A9268:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _080A9254
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80A924C

	thumb_func_start set_word_task_arg
set_word_task_arg: ; 80A927C
	push {r4,r5,lr}
	adds r5, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	cmp r3, 0xE
	bhi _080A92AA
	ldr r2, =0x03005e00
	lsls r0, r3, 1
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r0, r1
	adds r2, 0x8
	adds r0, r2
	strh r5, [r0]
	adds r0, r3, 0x1
	lsls r0, 1
	adds r0, r1
	adds r0, r2
	lsrs r1, r5, 16
	strh r1, [r0]
_080A92AA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end set_word_task_arg

	thumb_func_start get_word_task_arg
get_word_task_arg: ; 80A92B4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0xE
	bls _080A92C6
	movs r0, 0
	b _080A92E8
_080A92C6:
	ldr r3, =0x03005e00
	lsls r0, r1, 1
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	adds r0, r2
	adds r3, 0x8
	adds r0, r3
	ldrh r0, [r0]
	adds r1, 0x1
	lsls r1, 1
	adds r1, r2
	adds r1, r3
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 16
	orrs r0, r1
_080A92E8:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end get_word_task_arg
