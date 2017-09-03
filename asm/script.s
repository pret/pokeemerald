	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start script_env_init
@ void script_env_init(script_env *env, int a2, int a3)
script_env_init: @ 8098CB8
	push {lr}
	adds r3, r0, 0
	movs r0, 0
	strb r0, [r3, 0x1]
	str r0, [r3, 0x8]
	strb r0, [r3]
	str r0, [r3, 0x4]
	str r1, [r3, 0x5C]
	str r2, [r3, 0x60]
	movs r2, 0
	movs r1, 0x3
	adds r0, r3, 0
	adds r0, 0x70
_08098CD2:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _08098CD2
	adds r1, r3, 0
	adds r1, 0xC
	movs r2, 0
	adds r0, r3, 0
	adds r0, 0x58
_08098CE6:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _08098CE6
	pop {r0}
	bx r0
	thumb_func_end script_env_init

	thumb_func_start script_setup_bytecode_script
@ int script_setup_bytecode_script(script_env *env, void *script_ptr)
script_setup_bytecode_script: @ 8098CF4
	str r1, [r0, 0x8]
	movs r1, 0x1
	strb r1, [r0, 0x1]
	movs r0, 0x1
	bx lr
	thumb_func_end script_setup_bytecode_script

	thumb_func_start script_setup_asm_script
script_setup_asm_script: @ 8098D00
	movs r2, 0x2
	strb r2, [r0, 0x1]
	str r1, [r0, 0x4]
	bx lr
	thumb_func_end script_setup_asm_script

	thumb_func_start script_stop
@ void script_stop(script_env *env)
script_stop: @ 8098D08
	movs r1, 0
	strb r1, [r0, 0x1]
	str r1, [r0, 0x8]
	bx lr
	thumb_func_end script_stop

	thumb_func_start script_main_handler
@ int script_main_handler(script_env *env)
script_main_handler: @ 8098D10
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _08098D1E
_08098D1A:
	movs r0, 0
	b _08098D90
_08098D1E:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	beq _08098D56
	cmp r0, 0x1
	bgt _08098D2E
	cmp r0, 0
	beq _08098D1A
	b _08098D8E
_08098D2E:
	cmp r0, 0x2
	bne _08098D8E
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08098D52
	bl _call_via_r0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08098D8E
	strb r0, [r4, 0x1]
	b _08098D8E
_08098D48:
	strb r2, [r4, 0x1]
	b _08098D1A
_08098D4C:
	movs r0, 0
	strb r0, [r4, 0x1]
	b _08098D90
_08098D52:
	movs r0, 0x1
	strb r0, [r4, 0x1]
_08098D56:
	ldr r2, [r4, 0x8]
	cmp r2, 0
	beq _08098D48
	ldr r0, =gUnknown_085102BC
	ldr r0, [r0]
	cmp r2, r0
	bne _08098D6C
_08098D64:
	swi 0x2
	b _08098D64
	.pool
_08098D6C:
	ldrb r1, [r2]
	adds r0, r2, 0x1
	str r0, [r4, 0x8]
	lsls r1, 2
	ldr r0, [r4, 0x5C]
	adds r1, r0, r1
	ldr r0, [r4, 0x60]
	cmp r1, r0
	bcs _08098D4C
	ldr r1, [r1]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08098D56
_08098D8E:
	movs r0, 0x1
_08098D90:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end script_main_handler

	thumb_func_start script_stack_push
@ int script_stack_push(script_env *env, int value)
script_stack_push: @ 8098D98
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldrb r1, [r2]
	adds r0, r1, 0x1
	cmp r0, 0x13
	bgt _08098DBA
	lsls r0, r1, 2
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	str r3, [r1]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	movs r0, 0
	b _08098DBC
_08098DBA:
	movs r0, 0x1
_08098DBC:
	pop {r1}
	bx r1
	thumb_func_end script_stack_push

	thumb_func_start script_stack_pop
@ int script_stack_pop(script_env *env)
script_stack_pop: @ 8098DC0
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0
	beq _08098DDC
	subs r0, 0x1
	strb r0, [r2]
	ldrb r1, [r2]
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1
	ldr r0, [r0]
	b _08098DDE
_08098DDC:
	movs r0, 0
_08098DDE:
	pop {r1}
	bx r1
	thumb_func_end script_stack_pop

	thumb_func_start script_jump
@ void script_jump(script_env *env, int address)
script_jump: @ 8098DE4
	str r1, [r0, 0x8]
	bx lr
	thumb_func_end script_jump

	thumb_func_start script_call
@ void script_call(script_env *env, int address)
script_call: @ 8098DE8
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [r4, 0x8]
	bl script_stack_push
	str r5, [r4, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end script_call

	thumb_func_start script_return
@ void script_return(script_env *env)
script_return: @ 8098DFC
	push {r4,lr}
	adds r4, r0, 0
	bl script_stack_pop
	str r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end script_return

	thumb_func_start script_read_halfword
@ int script_read_halfword(script_env *env)
script_read_halfword: @ 8098E0C
	adds r3, r0, 0
	ldr r2, [r3, 0x8]
	ldrb r0, [r2]
	adds r2, 0x1
	str r2, [r3, 0x8]
	ldrb r1, [r2]
	lsls r1, 8
	orrs r0, r1
	adds r2, 0x1
	str r2, [r3, 0x8]
	bx lr
	thumb_func_end script_read_halfword

	thumb_func_start script_read_word
@ int script_read_word(script_env *env)
script_read_word: @ 8098E24
	push {r4-r6,lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x8]
	ldrb r6, [r0]
	adds r0, 0x1
	str r0, [r3, 0x8]
	ldrb r5, [r0]
	adds r2, r0, 0x1
	str r2, [r3, 0x8]
	ldrb r4, [r0, 0x1]
	adds r1, r2, 0x1
	str r1, [r3, 0x8]
	ldrb r0, [r2, 0x1]
	adds r1, 0x1
	str r1, [r3, 0x8]
	lsls r0, 8
	adds r0, r4
	lsls r0, 8
	adds r0, r5
	lsls r0, 8
	adds r0, r6
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end script_read_word

	thumb_func_start script_env_2_enable
script_env_2_enable: @ 8098E54
	ldr r1, =gUnknown_03000F2C
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end script_env_2_enable

	thumb_func_start script_env_2_disable
@ void script_env_2_disable()
script_env_2_disable: @ 8098E60
	ldr r1, =gUnknown_03000F2C
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end script_env_2_disable

	thumb_func_start script_env_2_is_enabled
@ int script_env_2_is_enabled()
script_env_2_is_enabled: @ 8098E6C
	ldr r0, =gUnknown_03000F2C
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end script_env_2_is_enabled

	thumb_func_start script_env_context_is_running
@ int script_env_context_is_running()
script_env_context_is_running: @ 8098E78
	push {lr}
	ldr r0, =gUnknown_03000E38
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098E8C
	movs r0, 0
	b _08098E8E
	.pool
_08098E8C:
	movs r0, 0x1
_08098E8E:
	pop {r1}
	bx r1
	thumb_func_end script_env_context_is_running

	thumb_func_start script_env_1_init
script_env_1_init: @ 8098E94
	push {lr}
	ldr r0, =gUnknown_03000E40
	ldr r1, =gEventScriptCommandFunctionTable
	ldr r2, =gUnknown_081DBA08
	bl script_env_init
	ldr r1, =gUnknown_03000E38
	movs r0, 0x2
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end script_env_1_init

	thumb_func_start script_env_2_run_current_script
script_env_2_run_current_script: @ 8098EBC
	push {r4,lr}
	ldr r4, =gUnknown_03000E38
	ldrb r0, [r4]
	cmp r0, 0x2
	beq _08098EF0
	cmp r0, 0x1
	beq _08098EF0
	bl script_env_2_enable
	ldr r0, =gUnknown_03000E40
	bl script_main_handler
	lsls r0, 24
	cmp r0, 0
	beq _08098EE8
	movs r0, 0x1
	b _08098EF2
	.pool
_08098EE8:
	movs r0, 0x2
	strb r0, [r4]
	bl script_env_2_disable
_08098EF0:
	movs r0, 0
_08098EF2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end script_env_2_run_current_script

	thumb_func_start script_env_1_execute_new_script
script_env_1_execute_new_script: @ 8098EF8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_03000E40
	ldr r1, =gEventScriptCommandFunctionTable
	ldr r2, =gUnknown_081DBA08
	adds r0, r4, 0
	bl script_env_init
	adds r0, r4, 0
	adds r1, r5, 0
	bl script_setup_bytecode_script
	bl script_env_2_enable
	ldr r1, =gUnknown_03000E38
	movs r0, 0
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end script_env_1_execute_new_script

	thumb_func_start script_env_2_set_ctx_paused
script_env_2_set_ctx_paused: @ 8098F30
	ldr r1, =gUnknown_03000E38
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end script_env_2_set_ctx_paused

	thumb_func_start script_env_2_enable_and_set_ctx_running
script_env_2_enable_and_set_ctx_running: @ 8098F3C
	push {lr}
	ldr r1, =gUnknown_03000E38
	movs r0, 0
	strb r0, [r1]
	bl script_env_2_enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end script_env_2_enable_and_set_ctx_running

	thumb_func_start ScriptContext2_RunNewScript
@ void ScriptContext2_RunNewScript(void *script_ptr)
ScriptContext2_RunNewScript: @ 8098F50
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, =gUnknown_03000EB8
	ldr r1, =gEventScriptCommandFunctionTable
	ldr r2, =gUnknown_081DBA08
	adds r0, r4, 0
	bl script_env_init
	adds r0, r4, 0
	adds r1, r5, 0
	bl script_setup_bytecode_script
_08098F68:
	ldr r0, =gUnknown_03000EB8
	bl script_main_handler
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08098F68
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ScriptContext2_RunNewScript

	thumb_func_start mapheader_get_tagged_pointer
mapheader_get_tagged_pointer: @ 8098F88
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gUnknown_02037318
	ldr r2, [r0, 0x8]
	cmp r2, 0
	beq _08098F9C
_08098F96:
	ldrb r0, [r2]
	cmp r0, 0
	bne _08098FA4
_08098F9C:
	movs r0, 0
	b _08098FC2
	.pool
_08098FA4:
	cmp r0, r1
	beq _08098FAC
	adds r2, 0x5
	b _08098F96
_08098FAC:
	adds r2, 0x1
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	ldrb r1, [r2, 0x2]
	lsls r1, 16
	adds r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 24
	adds r0, r1
_08098FC2:
	pop {r1}
	bx r1
	thumb_func_end mapheader_get_tagged_pointer

	thumb_func_start mapheader_run_script_by_tag
mapheader_run_script_by_tag: @ 8098FC8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl mapheader_get_tagged_pointer
	cmp r0, 0
	beq _08098FDA
	bl ScriptContext2_RunNewScript
_08098FDA:
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_script_by_tag

	thumb_func_start mapheader_get_first_match_from_tagged_ptr_list
@ int mapheader_get_first_match_from_tagged_ptr_list(int tag)
mapheader_get_first_match_from_tagged_ptr_list: @ 8098FE0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	bl mapheader_get_tagged_pointer
	adds r6, r0, 0
	cmp r6, 0
	beq _08098FFC
_08098FF0:
	ldrb r1, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r1, r0
	cmp r1, 0
	bne _08099000
_08098FFC:
	movs r0, 0
	b _0809903A
_08099000:
	adds r6, 0x2
	ldrb r5, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r5, r0
	adds r6, 0x2
	adds r0, r1, 0
	bl VarGet
	adds r4, r0, 0
	adds r0, r5, 0
	bl VarGet
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	beq _08099026
	adds r6, 0x4
	b _08098FF0
_08099026:
	ldrb r0, [r6]
	ldrb r1, [r6, 0x1]
	lsls r1, 8
	adds r0, r1
	ldrb r1, [r6, 0x2]
	lsls r1, 16
	adds r0, r1
	ldrb r1, [r6, 0x3]
	lsls r1, 24
	adds r0, r1
_0809903A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end mapheader_get_first_match_from_tagged_ptr_list

	thumb_func_start mapheader_run_script_with_tag_x1
mapheader_run_script_with_tag_x1: @ 8099040
	push {lr}
	movs r0, 0x1
	bl mapheader_run_script_by_tag
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_script_with_tag_x1

	thumb_func_start mapheader_run_script_with_tag_x3
mapheader_run_script_with_tag_x3: @ 809904C
	push {lr}
	movs r0, 0x3
	bl mapheader_run_script_by_tag
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_script_with_tag_x3

	thumb_func_start mapheader_run_script_with_tag_x5
mapheader_run_script_with_tag_x5: @ 8099058
	push {lr}
	movs r0, 0x5
	bl mapheader_run_script_by_tag
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_script_with_tag_x5

	thumb_func_start mapheader_run_script_with_tag_x7
mapheader_run_script_with_tag_x7: @ 8099064
	push {lr}
	movs r0, 0x7
	bl mapheader_run_script_by_tag
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_script_with_tag_x7

	thumb_func_start mapheader_run_script_with_tag_x6
mapheader_run_script_with_tag_x6: @ 8099070
	push {lr}
	movs r0, 0x6
	bl mapheader_run_script_by_tag
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_script_with_tag_x6

	thumb_func_start mapheader_run_first_tag2_script_list_match
@ int mapheader_run_first_tag2_script_list_match()
mapheader_run_first_tag2_script_list_match: @ 809907C
	push {lr}
	movs r0, 0x2
	bl mapheader_get_first_match_from_tagged_ptr_list
	cmp r0, 0
	beq _08099090
	bl script_env_1_execute_new_script
	movs r0, 0x1
	b _08099092
_08099090:
	movs r0, 0
_08099092:
	pop {r1}
	bx r1
	thumb_func_end mapheader_run_first_tag2_script_list_match

	thumb_func_start mapheader_run_first_tag4_script_list_match
@ void mapheader_run_first_tag4_script_list_match()
mapheader_run_first_tag4_script_list_match: @ 8099098
	push {lr}
	movs r0, 0x4
	bl mapheader_get_first_match_from_tagged_ptr_list
	cmp r0, 0
	beq _080990A8
	bl ScriptContext2_RunNewScript
_080990A8:
	pop {r0}
	bx r0
	thumb_func_end mapheader_run_first_tag4_script_list_match

	thumb_func_start sub_80990AC
sub_80990AC: @ 80990AC
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000372c
	adds r0, r1
	movs r1, 0xFA
	lsls r1, 2
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80990AC

	thumb_func_start killram
killram: @ 80990D0
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003728
	adds r1, r0
	ldr r2, =0x050000fb
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end killram

	thumb_func_start sub_80990FC
sub_80990FC: @ 80990FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	ldr r0, [sp, 0x24]
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gSaveBlock1Ptr
	mov r10, r0
	ldr r5, [r0]
	ldr r1, =0x0000372c
	adds r4, r5, r1
	bl killram
	ldr r0, =0x000003e3
	cmp r8, r0
	bhi _08099174
	movs r0, 0x33
	strb r0, [r4]
	mov r2, r9
	strb r2, [r4, 0x1]
	strb r7, [r4, 0x2]
	strb r6, [r4, 0x3]
	ldr r1, =0x00003730
	adds r0, r5, r1
	ldr r1, [sp]
	mov r2, r8
	bl memcpy
	bl sub_80990AC
	mov r2, r10
	ldr r1, [r2]
	ldr r2, =0x00003728
	adds r1, r2
	str r0, [r1]
	movs r0, 0x1
	b _08099176
	.pool
_08099174:
	movs r0, 0
_08099176:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80990FC

	thumb_func_start sub_8099188
@ u32 sub_8099188(u8 a1, u32 script)
sub_8099188: @ 8099188
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r6, =gSaveBlock1Ptr
	ldr r5, [r6]
	ldr r0, =0x0000372c
	adds r2, r5, r0
	ldr r7, =gUnknown_020375C0
	movs r0, 0
	str r0, [r7]
	ldrb r0, [r2]
	cmp r0, 0x33
	bne _080991F0
	ldrb r1, [r2, 0x1]
	movs r0, 0x4
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bne _080991F0
	ldrb r1, [r2, 0x2]
	movs r0, 0x5
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bne _080991F0
	ldrb r0, [r2, 0x3]
	cmp r0, r3
	bne _080991F0
	bl sub_80990AC
	ldr r1, [r6]
	ldr r2, =0x00003728
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _080991EC
	str r4, [r7]
	ldr r1, =0x00003730
	adds r0, r5, r1
	b _080991F2
	.pool
_080991EC:
	bl killram
_080991F0:
	adds r0, r4, 0
_080991F2:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8099188

	thumb_func_start sub_80991F8
sub_80991F8: @ 80991F8
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r2, =0x0000372c
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x33
	bne _0809923C
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	bne _0809923C
	ldrb r0, [r1, 0x2]
	cmp r0, 0xFF
	bne _0809923C
	ldrb r0, [r1, 0x3]
	cmp r0, 0xFF
	bne _0809923C
	bl sub_80990AC
	ldr r1, [r4]
	ldr r2, =0x00003728
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _0809923C
	movs r0, 0x1
	b _0809923E
	.pool
_0809923C:
	movs r0, 0
_0809923E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80991F8

	thumb_func_start sub_8099244
sub_8099244: @ 8099244
	push {r4-r6,lr}
	ldr r6, =gSaveBlock1Ptr
	ldr r5, [r6]
	ldr r0, =0x0000372c
	adds r4, r5, r0
	bl sub_801B27C
	cmp r0, 0
	beq _08099298
	ldrb r0, [r4]
	cmp r0, 0x33
	bne _08099298
	ldrb r0, [r4, 0x1]
	cmp r0, 0xFF
	bne _08099298
	ldrb r0, [r4, 0x2]
	cmp r0, 0xFF
	bne _08099298
	ldrb r0, [r4, 0x3]
	cmp r0, 0xFF
	bne _08099298
	bl sub_80990AC
	ldr r1, [r6]
	ldr r2, =0x00003728
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _08099294
	ldr r1, =0x00003730
	adds r0, r5, r1
	b _0809929A
	.pool
_08099294:
	bl killram
_08099298:
	movs r0, 0
_0809929A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8099244

	thumb_func_start sub_80992A0
sub_80992A0: @ 80992A0
	push {lr}
	sub sp, 0x4
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =0x000003e3
	cmp r1, r0
	bls _080992B2
	adds r1, r0, 0
_080992B2:
	movs r0, 0xFF
	str r0, [sp]
	adds r0, r2, 0
	movs r2, 0xFF
	movs r3, 0xFF
	bl sub_80990FC
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80992A0

	.align 2, 0 @ Don't pad with nop.
