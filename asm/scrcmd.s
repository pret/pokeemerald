	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start s00_nop
s00_nop: @ 80992CC
	movs r0, 0
	bx lr
	thumb_func_end s00_nop

	thumb_func_start s01_nop
s01_nop: @ 80992D0
	movs r0, 0
	bx lr
	thumb_func_end s01_nop

	thumb_func_start s02_end
s02_end: @ 80992D4
	push {lr}
	bl script_stop
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s02_end

	thumb_func_start s24_execute_ASM_2
s24_execute_ASM_2: @ 80992E0
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r1, r0, 0
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s24_execute_ASM_2

	thumb_func_start s25_extended_cmd
s25_extended_cmd: @ 80992F8
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	ldr r1, =gUnknown_081DBA64
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s25_extended_cmd

	thumb_func_start s26_extended_cmd_setvar
s26_extended_cmd_setvar: @ 8099318
	push {r4-r6,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r6, r0, 0
	ldr r4, =gUnknown_081DBA64
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 14
	adds r0, r4
	ldr r0, [r0]
	bl _call_via_r0
	strh r0, [r6]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s26_extended_cmd_setvar

	thumb_func_start s23_execute_ASM
s23_execute_ASM: @ 809934C
	push {lr}
	bl script_read_word
	bl _call_via_r0
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s23_execute_ASM

	thumb_func_start s27_set_to_waitstate
s27_set_to_waitstate: @ 809935C
	push {lr}
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end s27_set_to_waitstate

	thumb_func_start s05_goto
s05_goto: @ 8099368
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r1, r0, 0
	adds r0, r4, 0
	bl script_jump
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s05_goto

	thumb_func_start s03_return
s03_return: @ 8099380
	push {lr}
	bl script_return
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s03_return

	thumb_func_start s04_call
s04_call: @ 809938C
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r1, r0, 0
	adds r0, r4, 0
	bl script_call
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s04_call

	thumb_func_start s06_if_jump
@ int s06_if_jump(script_env *env)
s06_if_jump: @ 80993A4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_word
	adds r2, r0, 0
	ldr r1, =gUnknown_085102C0
	lsls r0, r4, 1
	adds r0, r4
	ldrb r3, [r5, 0x2]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080993D2
	adds r0, r5, 0
	adds r1, r2, 0
	bl script_jump
_080993D2:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s06_if_jump

	thumb_func_start s07_if_call
s07_if_call: @ 80993E0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_word
	adds r2, r0, 0
	ldr r1, =gUnknown_085102C0
	lsls r0, r4, 1
	adds r0, r4
	ldrb r3, [r5, 0x2]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0809940E
	adds r0, r5, 0
	adds r1, r2, 0
	bl script_call
_0809940E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s07_if_call

	thumb_func_start sB8_set_virtual_address
@ int sB8_set_virtual_address(script_env *env)
sB8_set_virtual_address: @ 809941C
	push {r4,lr}
	ldr r4, [r0, 0x8]
	subs r4, 0x1
	bl script_read_word
	ldr r1, =gUnknown_020375C4
	subs r0, r4
	str r0, [r1]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sB8_set_virtual_address

	thumb_func_start sB9_virtual_jump
@ int sB9_virtual_jump(script_env *env)
sB9_virtual_jump: @ 8099438
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r1, r0, 0
	ldr r0, =gUnknown_020375C4
	ldr r0, [r0]
	subs r1, r0
	adds r0, r4, 0
	bl script_jump
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sB9_virtual_jump

	thumb_func_start sBA_virtual_call
sBA_virtual_call: @ 809945C
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r1, r0, 0
	ldr r0, =gUnknown_020375C4
	ldr r0, [r0]
	subs r1, r0
	adds r0, r4, 0
	bl script_call
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sBA_virtual_call

	thumb_func_start sBB_virtual_if_jump
sBB_virtual_if_jump: @ 8099480
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_word
	ldr r1, =gUnknown_020375C4
	ldr r1, [r1]
	subs r2, r0, r1
	ldr r1, =gUnknown_085102C0
	lsls r0, r4, 1
	adds r0, r4
	ldrb r3, [r5, 0x2]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080994B2
	adds r0, r5, 0
	adds r1, r2, 0
	bl script_jump
_080994B2:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sBB_virtual_if_jump

	thumb_func_start sBC_virtual_if_call
sBC_virtual_if_call: @ 80994C4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_word
	ldr r1, =gUnknown_020375C4
	ldr r1, [r1]
	subs r2, r0, r1
	ldr r1, =gUnknown_085102C0
	lsls r0, r4, 1
	adds r0, r4
	ldrb r3, [r5, 0x2]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080994F6
	adds r0, r5, 0
	adds r1, r2, 0
	bl script_call
_080994F6:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sBC_virtual_if_call

	thumb_func_start s08_jumpstd
s08_jumpstd: @ 8099508
	push {lr}
	adds r2, r0, 0
	ldr r0, [r2, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r2, 0x8]
	lsls r1, 2
	ldr r0, =gUnknown_081DC2A0
	adds r1, r0
	ldr r0, =gUnknown_081DC2CC
	cmp r1, r0
	bcs _08099528
	ldr r1, [r1]
	adds r0, r2, 0
	bl script_jump
_08099528:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s08_jumpstd

	thumb_func_start s09_callstd
s09_callstd: @ 8099538
	push {lr}
	adds r2, r0, 0
	ldr r0, [r2, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r2, 0x8]
	lsls r1, 2
	ldr r0, =gUnknown_081DC2A0
	adds r1, r0
	ldr r0, =gUnknown_081DC2CC
	cmp r1, r0
	bcs _08099558
	ldr r1, [r1]
	adds r0, r2, 0
	bl script_call
_08099558:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s09_callstd

	thumb_func_start s0A_jumpstd_if
s0A_jumpstd_if: @ 8099568
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x8]
	ldrb r2, [r0]
	adds r0, 0x1
	str r0, [r3, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r3, 0x8]
	ldr r1, =gUnknown_085102C0
	lsls r0, r2, 1
	adds r0, r2
	ldrb r2, [r3, 0x2]
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080995A0
	lsls r0, r4, 2
	ldr r1, =gUnknown_081DC2A0
	adds r1, r0, r1
	ldr r0, =gUnknown_081DC2CC
	cmp r1, r0
	bcs _080995A0
	ldr r1, [r1]
	adds r0, r3, 0
	bl script_jump
_080995A0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s0A_jumpstd_if

	thumb_func_start s0B_callstd_if
s0B_callstd_if: @ 80995B4
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x8]
	ldrb r2, [r0]
	adds r0, 0x1
	str r0, [r3, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r3, 0x8]
	ldr r1, =gUnknown_085102C0
	lsls r0, r2, 1
	adds r0, r2
	ldrb r2, [r3, 0x2]
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080995EC
	lsls r0, r4, 2
	ldr r1, =gUnknown_081DC2A0
	adds r1, r0, r1
	ldr r0, =gUnknown_081DC2CC
	cmp r1, r0
	bcs _080995EC
	ldr r1, [r1]
	adds r0, r3, 0
	bl script_call
_080995EC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s0B_callstd_if

	thumb_func_start s0C_restore_execution_after_sCF
s0C_restore_execution_after_sCF: @ 8099600
	push {lr}
	ldr r1, =gUnknown_020375C0
	ldr r1, [r1]
	bl script_jump
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s0C_restore_execution_after_sCF

	thumb_func_start s0D_endscript_killram
s0D_endscript_killram: @ 8099614
	push {r4,lr}
	adds r4, r0, 0
	bl killram
	adds r0, r4, 0
	bl script_stop
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s0D_endscript_killram

	thumb_func_start s0E_set_byte
s0E_set_byte: @ 809962C
	push {lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	adds r0, r2, 0
	bl sub_81538C4
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s0E_set_byte

	thumb_func_start s0F_u32_var_to_const
@ int s0F_u32_var_to_const(script_env *env)
s0F_u32_var_to_const: @ 8099644
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r5, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_word
	lsls r5, 2
	adds r4, 0x64
	adds r4, r5
	str r0, [r4]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s0F_u32_var_to_const

	thumb_func_start s12_u32_var_to_ptr
@ int s12_u32_var_to_ptr(script_env *env)
s12_u32_var_to_ptr: @ 8099668
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r5, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_word
	lsls r5, 2
	adds r4, 0x64
	adds r4, r5
	ldrb r0, [r0]
	str r0, [r4]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s12_u32_var_to_ptr

	thumb_func_start s11_u8_ptr_to_const
@ int s11_u8_ptr_to_const(script_env *env)
s11_u8_ptr_to_const: @ 809968C
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_word
	strb r4, [r0]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s11_u8_ptr_to_const

	thumb_func_start s10_u8_var_to_const
@ int s10_u8_var_to_const(script_env *env)
s10_u8_var_to_const: @ 80996A4
	ldr r1, [r0, 0x8]
	ldrb r3, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	lsls r3, 2
	adds r2, r0, 0
	adds r2, 0x64
	adds r2, r3
	ldrb r3, [r1]
	str r3, [r2]
	adds r1, 0x1
	str r1, [r0, 0x8]
	movs r0, 0
	bx lr
	thumb_func_end s10_u8_var_to_const

	thumb_func_start s13_u8_var_to_ptr
@ int s13_u8_var_to_ptr(script_env *env)
s13_u8_var_to_ptr: @ 80996C0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r5, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_word
	lsls r5, 2
	adds r4, 0x64
	adds r4, r5
	ldr r1, [r4]
	strb r1, [r0]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s13_u8_var_to_ptr

	thumb_func_start s14_u32_var_to_var
s14_u32_var_to_var: @ 80996E4
	ldr r1, [r0, 0x8]
	ldrb r3, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	lsls r3, 2
	adds r0, 0x64
	adds r3, r0, r3
	lsls r2, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [r3]
	movs r0, 0
	bx lr
	thumb_func_end s14_u32_var_to_var

	thumb_func_start s15_u8_ptr_to_ptr
s15_u8_ptr_to_ptr: @ 8099704
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r5, r0, 0
	adds r0, r4, 0
	bl script_read_word
	ldrb r0, [r0]
	strb r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s15_u8_ptr_to_ptr

	thumb_func_start s16_u16_gvar_to_const
s16_u16_gvar_to_const: @ 8099720
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r4, r0, 0
	adds r0, r5, 0
	bl script_read_halfword
	strh r0, [r4]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s16_u16_gvar_to_const

	thumb_func_start s19_u16_gvar_gvar
s19_u16_gvar_gvar: @ 8099744
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r5, r0, 0
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s19_u16_gvar_gvar

	thumb_func_start s1A_u16_gvar_gvar
s1A_u16_gvar_gvar: @ 8099770
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r5, r0, 0
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s1A_u16_gvar_gvar

	thumb_func_start compare_012
compare_012: @ 809979C
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r0, r1
	bcs _080997AE
	movs r0, 0
	b _080997B8
_080997AE:
	cmp r0, r1
	beq _080997B6
	movs r0, 0x2
	b _080997B8
_080997B6:
	movs r0, 0x1
_080997B8:
	pop {r1}
	bx r1
	thumb_func_end compare_012

	thumb_func_start s1B_cmp_u8_var_var
s1B_cmp_u8_var_var: @ 80997BC
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, [r4, 0x8]
	ldrb r0, [r2]
	lsls r0, 2
	adds r3, r4, 0
	adds r3, 0x64
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r2, 0x1
	str r2, [r4, 0x8]
	ldrb r1, [r2]
	lsls r1, 2
	adds r3, r1
	ldrb r1, [r3]
	adds r2, 0x1
	str r2, [r4, 0x8]
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s1B_cmp_u8_var_var

	thumb_func_start s1C_cmp_u8_var_const
s1C_cmp_u8_var_const: @ 80997EC
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, [r4, 0x8]
	ldrb r1, [r2]
	lsls r1, 2
	adds r0, 0x64
	adds r0, r1
	ldrb r0, [r0]
	adds r2, 0x1
	str r2, [r4, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s1C_cmp_u8_var_const

	thumb_func_start s1D_cmp_u8_var_ptr
s1D_cmp_u8_var_ptr: @ 8099814
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, [r4, 0x8]
	ldrb r1, [r2]
	lsls r1, 2
	adds r0, 0x64
	adds r0, r1
	ldrb r5, [r0]
	adds r2, 0x1
	str r2, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_word
	ldrb r1, [r0]
	adds r0, r5, 0
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s1D_cmp_u8_var_ptr

	thumb_func_start s1E_cmp_u8_ptr_var
s1E_cmp_u8_ptr_var: @ 8099840
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	ldrb r0, [r0]
	ldr r3, [r4, 0x8]
	ldrb r2, [r3]
	lsls r2, 2
	adds r1, r4, 0
	adds r1, 0x64
	adds r1, r2
	ldrb r1, [r1]
	adds r3, 0x1
	str r3, [r4, 0x8]
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s1E_cmp_u8_ptr_var

	thumb_func_start s1F_cmp_u8_ptr_const
s1F_cmp_u8_ptr_const: @ 809986C
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	ldrb r0, [r0]
	ldr r2, [r4, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s1F_cmp_u8_ptr_const

	thumb_func_start s20_cmp_u8_ptr_ptr
s20_cmp_u8_ptr_ptr: @ 809988C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_word
	ldrb r5, [r0]
	adds r0, r4, 0
	bl script_read_word
	ldrb r1, [r0]
	adds r0, r5, 0
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s20_cmp_u8_ptr_ptr

	thumb_func_start s21_cmp_u16_gvar_const
s21_cmp_u16_gvar_const: @ 80998B0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	ldrh r5, [r0]
	adds r0, r4, 0
	bl script_read_halfword
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s21_cmp_u16_gvar_const

	thumb_func_start s22_cmp_u16_gvar_gvar
s22_cmp_u16_gvar_gvar: @ 80998E0
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r5, r0, 0
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	ldrh r2, [r5]
	ldrh r1, [r0]
	adds r0, r2, 0
	bl compare_012
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s22_cmp_u16_gvar_gvar

	thumb_func_start s17_u16_gvar_add_const
s17_u16_gvar_add_const: @ 8099914
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r4, r0, 0
	adds r0, r5, 0
	bl script_read_halfword
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r4]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s17_u16_gvar_add_const

	thumb_func_start sub_809993C
sub_809993C: @ 809993C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r5, r0, 0
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldrh r1, [r5]
	subs r1, r0
	strh r1, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809993C

	thumb_func_start s8F_get_random_val
s8F_get_random_val: @ 809996C
	push {r4,r5,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r5, =gScriptResult
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __umodsi3
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s8F_get_random_val

	thumb_func_start sub_80999A0
sub_80999A0: @ 80999A0
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	ldr r5, =gScriptResult
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl AddBagItem
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80999A0

	thumb_func_start sub_80999E4
sub_80999E4: @ 80999E4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	ldr r5, =gScriptResult
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl RemoveBagItem
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80999E4

	thumb_func_start sub_8099A28
sub_8099A28: @ 8099A28
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	ldr r5, =gScriptResult
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl CheckBagHasSpace
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099A28

	thumb_func_start sub_8099A6C
sub_8099A6C: @ 8099A6C
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	ldr r5, =gScriptResult
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl CheckBagHasItem
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099A6C

	thumb_func_start s48_get_item_type
s48_get_item_type: @ 8099AB0
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gScriptResult
	bl GetPocketByItemId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s48_get_item_type

	thumb_func_start sub_8099ADC
sub_8099ADC: @ 8099ADC
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r5, =gScriptResult
	adds r0, r4, 0
	bl sub_80D6D70
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099ADC

	thumb_func_start sub_8099B20
sub_8099B20: @ 8099B20
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r5, =gScriptResult
	adds r0, r4, 0
	bl sub_80D6D1C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099B20

	thumb_func_start sub_8099B64
sub_8099B64: @ 8099B64
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r4, =gScriptResult
	lsls r0, 24
	lsrs r0, 24
	bl DecorationAdd
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099B64

	thumb_func_start sub_8099B90
sub_8099B90: @ 8099B90
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r4, =gScriptResult
	lsls r0, 24
	lsrs r0, 24
	bl DecorationRemove
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099B90

	thumb_func_start sub_8099BBC
sub_8099BBC: @ 8099BBC
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r4, =gScriptResult
	lsls r0, 24
	lsrs r0, 24
	bl DecorationCheckSpace
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099BBC

	thumb_func_start sub_8099BE8
sub_8099BE8: @ 8099BE8
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r4, =gScriptResult
	lsls r0, 24
	lsrs r0, 24
	bl sub_8161918
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099BE8

	thumb_func_start s29_flag_set
@ int s29_flag_set(script_env *env)
s29_flag_set: @ 8099C14
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl FlagSet
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s29_flag_set

	thumb_func_start s2A_flag_clear
@ int s2A_flag_clear(script_env *env)
s2A_flag_clear: @ 8099C28
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl FlagReset
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s2A_flag_clear

	thumb_func_start s2B_flag_check
@ int s2B_flag_check(script_env *env)
s2B_flag_check: @ 8099C3C
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl FlagGet
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s2B_flag_check

	thumb_func_start sC3_unknown
@ int sC3_unknown(script_env *env)
sC3_unknown: @ 8099C58
	push {lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	adds r0, r2, 0
	bl IncrementGameStat
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sC3_unknown

	thumb_func_start s9A_unknown
@ int s9A_unknown(script_env *env)
s9A_unknown: @ 8099C70
	push {lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	adds r0, r2, 0
	bl sub_80B009C
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end s9A_unknown

	thumb_func_start s99_unknown
@ int s99_unknown(script_env *env)
s99_unknown: @ 8099C8C
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl sub_80854EC
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s99_unknown

	thumb_func_start sub_8099CA8
sub_8099CA8: @ 8099CA8
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08099CC0
	movs r0, 0
	b _08099CC2
	.pool
_08099CC0:
	movs r0, 0x1
_08099CC2:
	pop {r1}
	bx r1
	thumb_func_end sub_8099CA8

	thumb_func_start s97_screen_special_effect
@ int s97_screen_special_effect(script_env *env)
s97_screen_special_effect: @ 8099CC8
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4, 0x8]
	ldrb r0, [r1]
	adds r1, 0x1
	str r1, [r4, 0x8]
	movs r1, 0
	bl fade_screen
	ldr r1, =sub_8099CA8
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s97_screen_special_effect

	thumb_func_start s98_refade_with_timer
@ int s98_refade_with_timer(script_env *env)
s98_refade_with_timer: @ 8099CF0
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, [r4, 0x8]
	ldrb r0, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	lsls r1, 24
	asrs r1, 24
	bl fade_screen
	ldr r1, =sub_8099CA8
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s98_refade_with_timer

	thumb_func_start sub_8099D20
@ int sub_8099D20(script_env *env)
sub_8099D20: @ 8099D20
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	cmp r4, 0x1
	beq _08099D3E
	cmp r4, 0x1
	bgt _08099D3A
	cmp r4, 0
	beq _08099D60
	b _08099D3E
_08099D3A:
	cmp r4, 0x2
	beq _08099D60
_08099D3E:
	ldr r0, =gPlttBufferUnfaded
	ldr r1, =gPaletteDecompressionBuffer
	ldr r2, =0x04000100
	bl CpuSet
	adds r0, r4, 0
	movs r1, 0
	bl fade_screen
	b _08099D72
	.pool
_08099D60:
	ldr r0, =gPaletteDecompressionBuffer
	ldr r1, =gPlttBufferUnfaded
	ldr r2, =0x04000100
	bl CpuSet
	adds r0, r4, 0
	movs r1, 0
	bl fade_screen
_08099D72:
	ldr r1, =sub_8099CA8
	adds r0, r5, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8099D20

	thumb_func_start s28_pause_asm
s28_pause_asm: @ 8099D94
	push {lr}
	ldr r1, =gUnknown_020375C8
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	beq _08099DAC
	movs r0, 0
	b _08099DAE
	.pool
_08099DAC:
	movs r0, 0x1
_08099DAE:
	pop {r1}
	bx r1
	thumb_func_end s28_pause_asm

	thumb_func_start s28_pause
@ int s28_pause(script_env *env)
s28_pause: @ 8099DB4
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	ldr r1, =gUnknown_020375C8
	strh r0, [r1]
	ldr r1, =s28_pause_asm
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s28_pause

	thumb_func_start s2C_unknown
@ int s2C_unknown(script_env *env)
s2C_unknown: @ 8099DD8
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl RtcInitLocalTimeOffset
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s2C_unknown

	thumb_func_start s2D_unknown
@ int s2D_unknown(script_env *env)
s2D_unknown: @ 8099E10
	push {lr}
	bl sub_809E7B0
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s2D_unknown

	thumb_func_start s2E_unknown
@ int s2E_unknown(script_env *env)
s2E_unknown: @ 8099E1C
	push {lr}
	bl RtcCalcLocalTime
	ldr r2, =gSpecialVar_0x8000
	ldr r1, =gLocalTime
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	strh r0, [r2]
	ldr r2, =gSpecialVar_0x8001
	movs r0, 0x3
	ldrsb r0, [r1, r0]
	strh r0, [r2]
	ldr r2, =gSpecialVar_0x8002
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	strh r0, [r2]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s2E_unknown

	thumb_func_start sA4_set_weather_data
@ int sA4_set_weather_data(script_env *env)
sA4_set_weather_data: @ 8099E54
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl sub_80AED7C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sA4_set_weather_data

	thumb_func_start sA3_set_standard_weather_data
@ int sA3_set_standard_weather_data(script_env *env)
sA3_set_standard_weather_data: @ 8099E70
	push {lr}
	bl sub_80AEDBC
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sA3_set_standard_weather_data

	thumb_func_start sub_8099E7C
@ int sub_8099E7C(script_env *env)
sub_8099E7C: @ 8099E7C
	push {lr}
	bl sub_80AEE20
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8099E7C

	thumb_func_start sA6_activate_per_step_callback_eg_ash
@ int sA6_activate_per_step_callback_eg_ash(script_env *env)
sA6_activate_per_step_callback_eg_ash: @ 8099E88
	push {lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	adds r0, r2, 0
	bl activate_per_step_callback
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sA6_activate_per_step_callback_eg_ash

	thumb_func_start sA7_set_new_map_footer
@ int sA7_set_new_map_footer(script_env *env)
sA7_set_new_map_footer: @ 8099EA0
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl sub_8085524
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sA7_set_new_map_footer

	thumb_func_start s39_warp_sfx
@ int s39_warp_sfx(script_env *env)
s39_warp_sfx: @ 8099EBC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl sub_80AF734
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s39_warp_sfx

	thumb_func_start s3A_warp_new_music
@ int s3A_warp_new_music(script_env *env)
s3A_warp_new_music: @ 8099F44
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl sp13E_warp_to_last_warp
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s3A_warp_new_music

	thumb_func_start s3B_warp_keep_music
@ int s3B_warp_keep_music(script_env *env)
s3B_warp_keep_music: @ 8099FCC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl sub_80AF7D0
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s3B_warp_keep_music

	thumb_func_start sub_809A054
sub_809A054: @ 809A054
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r1, [r0, 0x8]
	ldrb r6, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	mov r4, sp
	adds r4, 0x6
	add r0, sp, 0x4
	adds r1, r4, 0
	bl PlayerGetDestCoords
	cmp r6, 0xFF
	bne _0809A092
	cmp r5, 0xFF
	bne _0809A092
	add r0, sp, 0x4
	ldrh r0, [r0]
	subs r0, 0x7
	lsls r0, 16
	asrs r0, 16
	ldrh r1, [r4]
	subs r1, 0x7
	lsls r1, 16
	asrs r1, 16
	bl sub_8084EBC
	b _0809A0B6
_0809A092:
	lsls r0, r6, 24
	asrs r0, 24
	lsls r1, r5, 24
	asrs r1, 24
	movs r2, 0x1
	negs r2, r2
	add r3, sp, 0x4
	ldrb r3, [r3]
	subs r3, 0x7
	lsls r3, 24
	asrs r3, 24
	ldrb r4, [r4]
	subs r4, 0x7
	lsls r4, 24
	asrs r4, 24
	str r4, [sp]
	bl warp1_set
_0809A0B6:
	bl sp13F_fall_to_last_warp
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809A054

	thumb_func_start s3D_warp_v4
s3D_warp_v4: @ 809A0C8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl sub_80AF848
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s3D_warp_v4

	thumb_func_start sub_809A150
sub_809A150: @ 809A150
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl sub_80AF87C
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809A150

	thumb_func_start s3E_set_new_map
s3E_set_new_map: @ 809A1D8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s3E_set_new_map

	thumb_func_start s3F_set_new_map_DMA
s3F_set_new_map_DMA: @ 809A258
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	str r4, [sp]
	lsls r0, 24
	asrs r0, 24
	str r0, [sp, 0x4]
	movs r0, 0
	mov r1, r9
	mov r2, r8
	adds r3, r6, 0
	bl saved_warp2_set_2
	movs r0, 0
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s3F_set_new_map_DMA

	thumb_func_start sub_809A2DC
sub_809A2DC: @ 809A2DC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_8084E2C
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809A2DC

	thumb_func_start sub_809A35C
sub_809A35C: @ 809A35C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_8084E80
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809A35C

	thumb_func_start sC4_unknown
sC4_unknown: @ 809A3DC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_8084DD4
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sC4_unknown

	thumb_func_start s42_get_map_camera_pos
@ int s42_get_map_camera_pos(script_env *env)
s42_get_map_camera_pos: @ 809A45C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r5, r0, 0
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	ldr r2, =gSaveBlock1Ptr
	ldr r1, [r2]
	ldrh r1, [r1]
	strh r1, [r5]
	ldr r1, [r2]
	ldrh r1, [r1, 0x2]
	strh r1, [r0]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s42_get_map_camera_pos

	thumb_func_start s43_get_player_party_count
s43_get_player_party_count: @ 809A498
	push {r4,lr}
	ldr r4, =gScriptResult
	bl calc_player_party_count
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s43_get_player_party_count

	thumb_func_start s2F_music_play
s2F_music_play: @ 809A4B4
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl PlaySE
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s2F_music_play

	thumb_func_start s30_music_check_asm
s30_music_check_asm: @ 809A4C8
	push {lr}
	bl IsSEPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0809A4D8
	movs r0, 0
	b _0809A4DA
_0809A4D8:
	movs r0, 0x1
_0809A4DA:
	pop {r1}
	bx r1
	thumb_func_end s30_music_check_asm

	thumb_func_start s30_music_check
s30_music_check: @ 809A4E0
	push {lr}
	ldr r1, =s30_music_check_asm
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end s30_music_check

	thumb_func_start s31_PlayFanfare
s31_PlayFanfare: @ 809A4F4
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl PlayFanfare
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s31_PlayFanfare

	thumb_func_start s32_fanfare_wait_asm
s32_fanfare_wait_asm: @ 809A508
	push {lr}
	bl IsFanfareTaskInactive
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end s32_fanfare_wait_asm

	thumb_func_start s32_fanfare_wait
s32_fanfare_wait: @ 809A518
	push {lr}
	ldr r1, =s32_fanfare_wait_asm
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end s32_fanfare_wait

	thumb_func_start s33_play_music
@ int s33_play_music(script_env *env)
s33_play_music: @ 809A52C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r2, r0, 16
	adds r5, r2, 0
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	cmp r1, 0x1
	bne _0809A54C
	adds r0, r2, 0
	bl sav1_set_battle_music_maybe
_0809A54C:
	adds r0, r5, 0
	bl PlayNewMapMusic
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s33_play_music

	thumb_func_start s34_unknown
s34_unknown: @ 809A55C
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl sav1_set_battle_music_maybe
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s34_unknown

	thumb_func_start s35_fade_to_default
s35_fade_to_default: @ 809A570
	push {lr}
	bl sub_8085898
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s35_fade_to_default

	thumb_func_start s36_fade_to_music
s36_fade_to_music: @ 809A57C
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl sub_80858C4
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s36_fade_to_music

	thumb_func_start s37_fadeout
s37_fadeout: @ 809A590
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	cmp r1, 0
	beq _0809A5AA
	lsls r0, r1, 26
	lsrs r0, 24
	bl FadeOutBGMTemporarily
	b _0809A5B0
_0809A5AA:
	movs r0, 0x4
	bl FadeOutBGMTemporarily
_0809A5B0:
	ldr r1, =IsBGMPausedOrStopped
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s37_fadeout

	thumb_func_start s38_fadein
s38_fadein: @ 809A5C4
	push {lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	cmp r2, 0
	beq _0809A5DC
	lsls r0, r2, 26
	lsrs r0, 24
	bl FadeInBGM
	b _0809A5E2
_0809A5DC:
	movs r0, 0x4
	bl FadeInBGM
_0809A5E2:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s38_fadein

	thumb_func_start s4F_execute_movement
s4F_execute_movement: @ 809A5E8
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_word
	adds r3, r0, 0
	lsls r0, r4, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl exec_movement
	ldr r0, =gUnknown_020375CA
	strh r4, [r0]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s4F_execute_movement

	thumb_func_start s50_execute_movement_remote
s50_execute_movement_remote: @ 809A62C
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_word
	adds r3, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r2, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	lsls r0, r4, 24
	lsrs r0, 24
	bl exec_movement
	ldr r0, =gUnknown_020375CA
	strh r4, [r0]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s50_execute_movement_remote

	thumb_func_start s51a_0806B288
s51a_0806B288: @ 809A670
	push {lr}
	ldr r0, =gUnknown_020375CA
	ldrb r0, [r0]
	ldr r1, =gUnknown_020375CE
	ldrb r1, [r1]
	ldr r2, =gUnknown_020375CC
	ldrb r2, [r2]
	bl sub_80D3340
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end s51a_0806B288

	thumb_func_start s51_waitmove
s51_waitmove: @ 809A698
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0809A6B4
	ldr r0, =gUnknown_020375CA
	strh r1, [r0]
_0809A6B4:
	ldr r1, =gUnknown_020375CC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	movs r0, 0x4
	ldrsb r0, [r2, r0]
	strh r0, [r1]
	ldr r1, =gUnknown_020375CE
	movs r0, 0x5
	ldrsb r0, [r2, r0]
	strh r0, [r1]
	ldr r1, =s51a_0806B288
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s51_waitmove

	thumb_func_start s52_waitmove_remote
s52_waitmove_remote: @ 809A6EC
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0809A708
	ldr r0, =gUnknown_020375CA
	strh r1, [r0]
_0809A708:
	ldr r0, [r4, 0x8]
	ldrb r2, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	ldr r0, =gUnknown_020375CC
	strh r2, [r0]
	ldr r0, =gUnknown_020375CE
	strh r1, [r0]
	ldr r1, =s51a_0806B288
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s52_waitmove_remote

	thumb_func_start s53_hide_sprite
s53_hide_sprite: @ 809A740
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl RemoveFieldObjectByLocalIdAndMap
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s53_hide_sprite

	thumb_func_start s54_hide_sprite_set_coords
s54_hide_sprite_set_coords: @ 809A768
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r3, [r4, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	ldrb r1, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl RemoveFieldObjectByLocalIdAndMap
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s54_hide_sprite_set_coords

	thumb_func_start s55_show_sprite
s55_show_sprite: @ 809A798
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl show_sprite
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s55_show_sprite

	thumb_func_start s56_show_sprite_set_coords
s56_show_sprite_set_coords: @ 809A7C0
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r3, [r4, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	ldrb r1, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl show_sprite
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s56_show_sprite_set_coords

	thumb_func_start s57_move_sprites
s57_move_sprites: @ 809A7F0
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r6, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	lsls r4, 16
	asrs r4, 16
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	adds r0, r5, 0
	adds r3, r4, 0
	bl sub_808EBA8
	movs r0, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s57_move_sprites

	thumb_func_start s63_new_sprite_location_permanent
s63_new_sprite_location_permanent: @ 809A858
	push {r4-r6,lr}
	adds r6, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r6, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r2, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 16
	asrs r4, 16
	lsls r2, 16
	asrs r2, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl update_saveblock1_field_object_coords
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end s63_new_sprite_location_permanent

	thumb_func_start s64_set_sprite_top_left_corner
s64_set_sprite_top_left_corner: @ 809A8B0
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl sub_808F254
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s64_set_sprite_top_left_corner

	thumb_func_start s58_npc_f1_clear_x20
s58_npc_f1_clear_x20: @ 809A8D8
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r3, [r4, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	ldrb r1, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	bl npc_by_local_id_and_map_set_field_1_bit_x20
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s58_npc_f1_clear_x20

	thumb_func_start s59_npc_f1_set_x20
s59_npc_f1_set_x20: @ 809A908
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r3, [r4, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	ldrb r1, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0x1
	bl npc_by_local_id_and_map_set_field_1_bit_x20
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s59_npc_f1_set_x20

	thumb_func_start sA8_unknown
sA8_unknown: @ 809A938
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r3, [r5, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r5, 0x8]
	ldrb r1, [r3]
	adds r4, r3, 0x1
	str r4, [r5, 0x8]
	ldrb r3, [r3, 0x1]
	adds r4, 0x1
	str r4, [r5, 0x8]
	lsls r0, 24
	lsrs r0, 24
	adds r3, 0x53
	lsls r3, 24
	lsrs r3, 24
	bl sub_808E78C
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sA8_unknown

	thumb_func_start sA9_unknown
sA9_unknown: @ 809A974
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r3, [r4, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	ldrb r1, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl sub_808E7E4
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sA9_unknown

	thumb_func_start s5A_face_player
s5A_face_player: @ 809A9A4
	push {r4,lr}
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	ldrb r0, [r4]
	lsls r0, 31
	cmp r0, 0
	beq _0809A9CC
	bl player_get_direction_lower_nybble
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectFaceOppositeDirection
_0809A9CC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s5A_face_player

	thumb_func_start s5B_npc_set_direction
s5B_npc_set_direction: @ 809A9DC
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r1, [r4, 0x8]
	ldrb r3, [r1]
	adds r1, 0x1
	str r1, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl FieldObjectTurnByLocalIdAndMap
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s5B_npc_set_direction

	thumb_func_start s65_set_sprite_behaviour
s65_set_sprite_behaviour: @ 809AA10
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r2, [r4, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r4, 0x8]
	lsls r0, 24
	lsrs r0, 24
	bl update_saveblock1_field_object_movement_behavior
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s65_set_sprite_behaviour

	thumb_func_start sAA_create_new_sprite
sAA_create_new_sprite: @ 809AA38
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r6, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r3, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r2, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	lsls r4, 16
	asrs r4, 16
	lsls r3, 16
	asrs r3, 16
	str r2, [sp]
	str r1, [sp, 0x4]
	mov r0, r8
	adds r1, r6, 0
	adds r2, r4, 0
	bl sprite_new
	movs r0, 0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sAA_create_new_sprite

	thumb_func_start sAB_unknown
sAB_unknown: @ 809AAA8
	push {lr}
	ldr r2, [r0, 0x8]
	ldrb r3, [r2]
	adds r2, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r0, 0x8]
	adds r0, r3, 0
	bl sub_8097B78
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sAB_unknown

	thumb_func_start sub_809AAC4
sub_809AAC4: @ 809AAC4
	push {r4,lr}
	adds r4, r0, 0
	bl is_c1_link_related_active
	cmp r0, 0
	bne _0809AAE4
	bl sub_80983E8
	ldr r1, =sub_80983C4
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	b _0809AAE6
	.pool
_0809AAE4:
	movs r0, 0
_0809AAE6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AAC4

	thumb_func_start sub_809AAEC
sub_809AAEC: @ 809AAEC
	push {r4,lr}
	adds r4, r0, 0
	bl is_c1_link_related_active
	cmp r0, 0
	beq _0809AAFC
	movs r0, 0
	b _0809AB3A
_0809AAFC:
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _0809AB2C
	bl sub_80984A0
	ldr r1, =sub_809847C
	adds r0, r4, 0
	bl script_setup_asm_script
	b _0809AB38
	.pool
_0809AB2C:
	bl sub_80983E8
	ldr r1, =sub_80983C4
	adds r0, r4, 0
	bl script_setup_asm_script
_0809AB38:
	movs r0, 0x1
_0809AB3A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809AAEC

	thumb_func_start s6B_release
s6B_release: @ 809AB44
	push {lr}
	bl textbox_close
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimFinished
	bl sub_80D338C
	bl sub_809757C
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s6B_release

	thumb_func_start s6C_release_2
s6C_release_2: @ 809AB7C
	push {r4,lr}
	bl textbox_close
	ldr r4, =gUnknown_02037350
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _0809AB9E
	adds r0, r1, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
_0809AB9E:
	movs r0, 0xFF
	movs r1, 0
	movs r2, 0
	bl GetFieldObjectIdByLocalIdAndMap
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl FieldObjectClearAnimIfSpecialAnimFinished
	bl sub_80D338C
	bl sub_809757C
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s6C_release_2

	thumb_func_start s67_execute_box
s67_execute_box: @ 809ABD4
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	cmp r0, 0
	bne _0809ABE2
	ldr r0, [r4, 0x64]
_0809ABE2:
	bl box_related_two__2
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s67_execute_box

	thumb_func_start sub_809ABF0
sub_809ABF0: @ 809ABF0
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	cmp r0, 0
	bne _0809ABFE
	ldr r0, [r4, 0x64]
_0809ABFE:
	bl sub_8098238
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809ABF0

	thumb_func_start s9B_unknown
s9B_unknown: @ 809AC0C
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r3, r0, 0
	cmp r3, 0
	bne _0809AC1C
	ldr r3, [r4, 0x64]
_0809AC1C:
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, 0
	bl box_related_two__3
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s9B_unknown

	thumb_func_start sub_809AC3C
sub_809AC3C: @ 809AC3C
	push {r4,r5,lr}
	sub sp, 0xC
	adds r5, r0, 0
	bl script_read_word
	adds r4, r0, 0
	cmp r4, 0
	bne _0809AC4E
	ldr r4, [r5, 0x64]
_0809AC4E:
	bl sub_81973A4
	movs r0, 0
	movs r1, 0x1
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
	movs r0, 0
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809AC3C

	thumb_func_start sub_809AC78
sub_809AC78: @ 809AC78
	push {lr}
	ldr r1, =sub_809833C
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809AC78

	thumb_func_start s68_close_box
s68_close_box: @ 809AC8C
	push {lr}
	bl textbox_close
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s68_close_box

	thumb_func_start sub_809AC98
sub_809AC98: @ 809AC98
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809ACB8
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0809ACB8
	movs r0, 0
	b _0809ACBA
	.pool
_0809ACB8:
	movs r0, 0x1
_0809ACBA:
	pop {r1}
	bx r1
	thumb_func_end sub_809AC98

	thumb_func_start sub_809ACC0
sub_809ACC0: @ 809ACC0
	push {lr}
	ldr r1, =sub_809AC98
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809ACC0

	thumb_func_start s6E_yes_no
s6E_yes_no: @ 809ACD4
	push {lr}
	ldr r2, [r0, 0x8]
	ldrb r3, [r2]
	adds r2, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r2]
	adds r2, 0x1
	str r2, [r0, 0x8]
	adds r0, r3, 0
	bl yes_no_box
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809ACF6
	movs r0, 0
	b _0809ACFC
_0809ACF6:
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
_0809ACFC:
	pop {r1}
	bx r1
	thumb_func_end s6E_yes_no

	thumb_func_start s6F_multichoice
s6F_multichoice: @ 809AD00
	push {r4,r5,lr}
	ldr r2, [r0, 0x8]
	ldrb r5, [r2]
	adds r2, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r2]
	adds r3, r2, 0x1
	str r3, [r0, 0x8]
	ldrb r2, [r2, 0x1]
	adds r4, r3, 0x1
	str r4, [r0, 0x8]
	ldrb r3, [r3, 0x1]
	adds r4, 0x1
	str r4, [r0, 0x8]
	adds r0, r5, 0
	bl Multichoice
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809AD2E
	movs r0, 0
	b _0809AD34
_0809AD2E:
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
_0809AD34:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s6F_multichoice

	thumb_func_start sub_809AD3C
sub_809AD3C: @ 809AD3C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	ldr r2, [r0, 0x8]
	ldrb r1, [r2]
	mov r8, r1
	adds r2, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r2]
	adds r3, r2, 0x1
	str r3, [r0, 0x8]
	ldrb r2, [r2, 0x1]
	adds r5, r3, 0x1
	str r5, [r0, 0x8]
	ldrb r6, [r3, 0x1]
	adds r4, r5, 0x1
	str r4, [r0, 0x8]
	ldrb r3, [r5, 0x1]
	adds r4, 0x1
	str r4, [r0, 0x8]
	str r6, [sp]
	mov r0, r8
	bl sub_80E1E58
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809AD7A
	movs r0, 0
	b _0809AD80
_0809AD7A:
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
_0809AD80:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AD3C

	thumb_func_start sub_809AD8C
sub_809AD8C: @ 809AD8C
	movs r0, 0
	bx lr
	thumb_func_end sub_809AD8C

	thumb_func_start sub_809AD90
sub_809AD90: @ 809AD90
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	ldr r2, [r0, 0x8]
	ldrb r1, [r2]
	mov r8, r1
	adds r2, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r2]
	adds r3, r2, 0x1
	str r3, [r0, 0x8]
	ldrb r2, [r2, 0x1]
	adds r5, r3, 0x1
	str r5, [r0, 0x8]
	ldrb r6, [r3, 0x1]
	adds r4, r5, 0x1
	str r4, [r0, 0x8]
	ldrb r3, [r5, 0x1]
	adds r4, 0x1
	str r4, [r0, 0x8]
	str r6, [sp]
	mov r0, r8
	bl sub_80E21D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0809ADCE
	movs r0, 0
	b _0809ADD4
_0809ADCE:
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
_0809ADD4:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AD90

	thumb_func_start s73_nop_skip_word
s73_nop_skip_word: @ 809ADE0
	ldr r1, [r0, 0x8]
	adds r1, 0x4
	str r1, [r0, 0x8]
	movs r0, 0
	bx lr
	thumb_func_end s73_nop_skip_word

	thumb_func_start sub_809ADEC
sub_809ADEC: @ 809ADEC
	ldr r1, [r0, 0x8]
	adds r1, 0x4
	str r1, [r0, 0x8]
	movs r0, 0
	bx lr
	thumb_func_end sub_809ADEC

	thumb_func_start sub_809ADF8
sub_809ADF8: @ 809ADF8
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r3, [r4, 0x8]
	ldrb r1, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	ldrb r2, [r3]
	adds r3, 0x1
	str r3, [r4, 0x8]
	bl sub_80E2900
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809ADF8

	thumb_func_start s76_close_picture_box
s76_close_picture_box: @ 809AE28
	push {r4,lr}
	adds r4, r0, 0
	bl picbox_close
	adds r1, r0, 0
	cmp r1, 0
	beq _0809AE40
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	b _0809AE42
_0809AE40:
	movs r0, 0
_0809AE42:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s76_close_picture_box

	thumb_func_start sub_809AE48
sub_809AE48: @ 809AE48
	push {lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	cmp r2, 0
	beq _0809AE5C
	adds r0, r2, 0
	bl sub_812FDA8
_0809AE5C:
	bl sub_80F8ADC
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_809AE48

	thumb_func_start sub_809AE6C
sub_809AE6C: @ 809AE6C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	bl script_read_word
	adds r1, r0, 0
	ldr r4, =gStringVar4
	adds r1, 0x6
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x6
	adds r1, r4, 0
	bl GetStringWidth
	lsrs r0, 3
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x1C
	bls _0809AE9C
	movs r7, 0x1C
_0809AE9C:
	movs r5, 0x4
	ldrb r0, [r4]
	adds r2, r7, 0x2
	add r1, sp, 0x18
	mov r8, r1
	cmp r0, 0xFF
	beq _0809AEC0
	adds r1, r4, 0
_0809AEAC:
	ldrb r0, [r1]
	adds r1, 0x1
	cmp r0, 0xFE
	bne _0809AEBA
	adds r0, r5, 0x3
	lsls r0, 24
	lsrs r5, r0, 24
_0809AEBA:
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _0809AEAC
_0809AEC0:
	cmp r5, 0x12
	bls _0809AEC6
	movs r5, 0x12
_0809AEC6:
	lsls r0, r2, 24
	lsrs r0, 24
	movs r2, 0x1E
	subs r2, r0
	lsrs r0, r2, 31
	adds r2, r0
	asrs r2, 1
	lsls r2, 24
	adds r0, r5, 0x2
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0x14
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	lsls r4, 24
	lsrs r6, r2, 24
	movs r0, 0x80
	lsls r0, 17
	adds r2, r0
	lsrs r2, 24
	lsrs r3, r4, 24
	movs r1, 0x80
	lsls r1, 18
	adds r4, r1
	lsrs r4, 24
	subs r6, r2, r6
	subs r6, 0x1
	lsls r6, 3
	adds r6, 0x3
	lsls r6, 24
	lsrs r6, 24
	subs r4, r3
	subs r4, 0x1
	lsls r4, 27
	lsrs r4, 24
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r7, [sp]
	str r5, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0x1
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	movs r1, 0
	bl sub_8198A50
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x14]
	str r0, [sp, 0x18]
	str r1, [sp, 0x1C]
	ldr r5, =gUnknown_03000F30
	mov r0, r8
	bl AddWindow
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, 0x85
	lsls r1, 2
	movs r2, 0xE0
	bl sub_809882C
	ldrb r0, [r5]
	movs r1, 0
	bl sub_81973FC
	ldrb r0, [r5]
	bl PutWindowTilemap
	ldrb r0, [r5]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5]
	ldr r2, =gStringVar4
	str r4, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x6
	adds r3, r6, 0
	bl PrintTextOnWindow
	ldrb r0, [r5]
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809AE6C

	thumb_func_start sub_809AF94
sub_809AF94: @ 809AF94
	push {lr}
	bl sub_809BDB4
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_809AF94

	thumb_func_start sBD_virtual_message
sBD_virtual_message: @ 809AFA0
	push {lr}
	bl script_read_word
	ldr r1, =gUnknown_020375C4
	ldr r1, [r1]
	subs r0, r1
	bl box_related_two__2
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sBD_virtual_message

	thumb_func_start s7D_load_pokename
s7D_load_pokename: @ 809AFBC
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r2, [r4]
	movs r1, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r2, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s7D_load_pokename

	thumb_func_start s7E_load_first_pokenames
s7E_load_first_pokenames: @ 809AFFC
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldr r0, =gUnknown_085102D4
	lsls r2, 2
	adds r2, r0
	ldr r4, [r2]
	bl sub_8139688
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	movs r1, 0xB
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s7E_load_first_pokenames

	thumb_func_start s7F_load_pokename_team
s7F_load_pokename_team: @ 809B048
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r4, [r4]
	movs r1, 0x2
	adds r2, r4, 0
	bl GetMonData
	adds r0, r4, 0
	bl StringGetEnd10
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s7F_load_pokename_team

	thumb_func_start s80_load_item_name
s80_load_item_name: @ 809B090
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	bl CopyItemName
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s80_load_item_name

	thumb_func_start sub_809B0C4
sub_809B0C4: @ 809B0C4
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r6, [r0]
	adds r0, 0x1
	str r0, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	ldr r0, =gUnknown_085102D4
	lsls r6, 2
	adds r6, r0
	ldr r1, [r6]
	adds r0, r4, 0
	bl CopyItemNameHandlePlural
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B0C4

	thumb_func_start sub_809B114
sub_809B114: @ 809B114
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	ldr r0, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	lsrs r1, 11
	ldr r2, =gUnknown_085A5C09
	adds r1, r2
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B114

	thumb_func_start s82_load_item_name
s82_load_item_name: @ 809B150
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r2, [r4]
	movs r1, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r2, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s82_load_item_name

	thumb_func_start s83_load_textvar_var
s83_load_textvar_var: @ 809B190
	push {r4,r5,lr}
	ldr r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r4, 0
	bl sub_80EF370
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_085102D4
	lsls r5, 2
	adds r5, r0
	ldr r0, [r5]
	adds r1, r4, 0
	movs r2, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s83_load_textvar_var

	thumb_func_start s84_load_textvar_std_expression
s84_load_textvar_std_expression: @ 809B1D4
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r2, [r4]
	ldr r1, =gUnknown_0858BAF0
	lsrs r0, 14
	adds r0, r1
	ldr r1, [r0]
	adds r0, r2, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s84_load_textvar_std_expression

	thumb_func_start sub_809B214
sub_809B214: @ 809B214
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	ldr r0, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	lsls r1, 24
	lsrs r1, 24
	bl sub_818E868
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B214

	thumb_func_start s85_load_textvar_pointer
s85_load_textvar_pointer: @ 809B248
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_word
	adds r1, r0, 0
	ldr r0, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s85_load_textvar_pointer

	thumb_func_start sBE_virtual_load_text
sBE_virtual_load_text: @ 809B270
	push {lr}
	bl script_read_word
	adds r1, r0, 0
	ldr r0, =gUnknown_020375C4
	ldr r0, [r0]
	subs r1, r0
	ldr r0, =gStringVar4
	bl StringExpandPlaceholders
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sBE_virtual_load_text

	thumb_func_start sBF_virtual_load_textbuffer
sBF_virtual_load_textbuffer: @ 809B294
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_word
	adds r1, r0, 0
	ldr r0, =gUnknown_020375C4
	ldr r0, [r0]
	subs r1, r0
	ldr r0, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sBF_virtual_load_textbuffer

	thumb_func_start sC6_load_textvar_box_label
sC6_load_textvar_box_label: @ 809B2C8
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r4, [r4]
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sC6_load_textvar_box_label

	thumb_func_start s79_give_pokemon
s79_give_pokemon: @ 809B304
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r6, r0, 0
	lsls r6, 16
	lsrs r6, 16
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	bl script_read_word
	mov r8, r0
	adds r0, r4, 0
	bl script_read_word
	ldr r1, [r4, 0x8]
	ldrb r2, [r1]
	adds r1, 0x1
	str r1, [r4, 0x8]
	ldr r4, =gScriptResult
	str r0, [sp]
	str r2, [sp, 0x4]
	adds r0, r6, 0
	mov r1, r9
	adds r2, r5, 0
	mov r3, r8
	bl sub_80F9244
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s79_give_pokemon

	thumb_func_start s7A_create_egg
s7A_create_egg: @ 809B384
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gScriptResult
	bl sub_80F92C8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s7A_create_egg

	thumb_func_start s7B_change_pokedata_AP
s7B_change_pokedata_AP: @ 809B3B0
	push {r4,r5,lr}
	ldr r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_80F9400
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end s7B_change_pokedata_AP

	thumb_func_start sub_809B3DC
sub_809B3DC: @ 809B3DC
	push {r4-r7,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r1, =gScriptResult
	movs r0, 0x6
	strh r0, [r1]
	movs r6, 0
	b _0809B42A
	.pool
_0809B3F4:
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0809B424
	adds r0, r4, 0
	adds r1, r7, 0
	bl pokemon_has_move
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809B424
	ldr r0, =gScriptResult
	strh r6, [r0]
	ldr r0, =gSpecialVar_0x8004
	strh r5, [r0]
	b _0809B44A
	.pool
_0809B424:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0809B42A:
	cmp r6, 0x5
	bhi _0809B44A
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	bne _0809B3F4
_0809B44A:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B3DC

	thumb_func_start s90_add_money
@ int s90_add_money(script_env *env)
s90_add_money: @ 809B458
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r2, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	cmp r1, 0
	bne _0809B47E
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	adds r1, r2, 0
	bl add_money
_0809B47E:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s90_add_money

	thumb_func_start s91_subtract_money
@ int s91_subtract_money(script_env *env)
s91_subtract_money: @ 809B48C
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r2, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	cmp r1, 0
	bne _0809B4B2
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	adds r1, r2, 0
	bl subtract_money
_0809B4B2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s91_subtract_money

	thumb_func_start s92_check_money
@ int s92_check_money(script_env *env)
s92_check_money: @ 809B4C0
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_word
	adds r2, r0, 0
	ldr r0, [r4, 0x8]
	ldrb r1, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	cmp r1, 0
	bne _0809B4EE
	ldr r4, =gScriptResult
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	adds r1, r2, 0
	bl IsEnoughMoney
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
_0809B4EE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s92_check_money

	thumb_func_start s93_display_money
@ int s93_display_money(script_env *env)
s93_display_money: @ 809B500
	push {r4,r5,lr}
	ldr r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r2, r1, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r1, 0x1]
	adds r2, 0x1
	str r2, [r0, 0x8]
	cmp r1, 0
	bne _0809B530
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	bl DecryptMoney
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80E52EC
_0809B530:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s93_display_money

	thumb_func_start s94_hide_money
s94_hide_money: @ 809B53C
	push {lr}
	bl sub_80E5384
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s94_hide_money

	thumb_func_start s95_update_money
@ int s95_update_money(script_env *env)
s95_update_money: @ 809B548
	push {lr}
	ldr r1, [r0, 0x8]
	adds r1, 0x1
	adds r2, r1, 0x1
	str r2, [r0, 0x8]
	ldrb r1, [r1, 0x1]
	adds r2, 0x1
	str r2, [r0, 0x8]
	cmp r1, 0
	bne _0809B56E
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	bl DecryptMoney
	bl sub_80E52D4
_0809B56E:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s95_update_money

	thumb_func_start sub_809B578
sub_809B578: @ 809B578
	push {r4,r5,lr}
	ldr r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	adds r2, r4, 0
	bl ShowCoinsWindow
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809B578

	thumb_func_start sC1_hide_coins
sC1_hide_coins: @ 809B5A0
	push {lr}
	ldr r1, [r0, 0x8]
	adds r1, 0x2
	str r1, [r0, 0x8]
	bl HideCoinsWindow
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sC1_hide_coins

	thumb_func_start sC2_update_coins
sC2_update_coins: @ 809B5B4
	push {lr}
	ldr r1, [r0, 0x8]
	adds r1, 0x2
	str r1, [r0, 0x8]
	bl GetCoins
	lsls r0, 16
	lsrs r0, 16
	bl PrintCoinsString
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sC2_update_coins

	thumb_func_start s5C_trainer_battle_configure_and_start
s5C_trainer_battle_configure_and_start: @ 809B5D0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	bl TrainerBattleConfigure
	str r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s5C_trainer_battle_configure_and_start

	thumb_func_start sub_809B5E4
sub_809B5E4: @ 809B5E4
	push {lr}
	bl sub_80B17E0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_809B5E4

	thumb_func_start sub_809B5F0
sub_809B5F0: @ 809B5F0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B1AF8
	str r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809B5F0

	thumb_func_start sub_809B604
@ bool8 sub_809B604(struct script_env *env)
sub_809B604: @ 809B604
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B1B10
	str r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809B604

	thumb_func_start s60_check_trainer_flag
s60_check_trainer_flag: @ 809B618
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl trainer_flag_check
	strb r0, [r4, 0x2]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end s60_check_trainer_flag

	thumb_func_start s61_set_trainer_flag
s61_set_trainer_flag: @ 809B63C
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl trainer_flag_set
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s61_set_trainer_flag

	thumb_func_start s62_unset_trainer_flag
s62_unset_trainer_flag: @ 809B658
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl trainer_flag_clear
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s62_unset_trainer_flag

	thumb_func_start sB6_load_battle
sB6_load_battle: @ 809B674
	push {r4-r6,lr}
	adds r4, r0, 0
	bl script_read_halfword
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	ldr r0, [r4, 0x8]
	ldrb r6, [r0]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_halfword
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80F93A0
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sB6_load_battle

	thumb_func_start sub_809B6A8
sub_809B6A8: @ 809B6A8
	push {lr}
	bl sub_80B08A8
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_809B6A8

	thumb_func_start s86_pokemart
s86_pokemart: @ 809B6B8
	push {lr}
	bl script_read_word
	bl CreatePokemartMenu
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end s86_pokemart

	thumb_func_start s87_pokemartdecor
s87_pokemartdecor: @ 809B6CC
	push {lr}
	bl script_read_word
	bl CreateDecorationShop1Menu
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end s87_pokemartdecor

	thumb_func_start s88_pokemartbp
s88_pokemartbp: @ 809B6E0
	push {lr}
	bl script_read_word
	bl CreateDecorationShop2Menu
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end s88_pokemartbp

	thumb_func_start s89_open_casino_game1
s89_open_casino_game1: @ 809B6F4
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl sub_812A540
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end s89_open_casino_game1

	thumb_func_start berry_script_cmd
@ bool8 berry_script_cmd(struct script_env *env)
berry_script_cmd: @ 809B71C
	push {r4,r5,lr}
	ldr r1, [r0, 0x8]
	ldrb r5, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldrb r3, [r1]
	adds r2, r1, 0x1
	str r2, [r0, 0x8]
	ldrb r4, [r1, 0x1]
	adds r2, 0x1
	str r2, [r0, 0x8]
	cmp r3, 0
	bne _0809B744
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	movs r3, 0
	bl PlantBerryTree
	b _0809B750
_0809B744:
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r4, 0
	movs r3, 0
	bl PlantBerryTree
_0809B750:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end berry_script_cmd

	thumb_func_start sub_809B758
sub_809B758: @ 809B758
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r4, =gScriptResult
	lsls r0, 24
	lsrs r0, 24
	bl GetPriceReduction
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B758

	thumb_func_start sub_809B784
sub_809B784: @ 809B784
	push {lr}
	bl sub_81B9404
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_809B784

	thumb_func_start sub_809B794
sub_809B794: @ 809B794
	push {lr}
	bl sub_80F840C
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_809B794

	thumb_func_start sub_809B7A4
sub_809B7A4: @ 809B7A4
	push {lr}
	bl sub_80F8484
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_809B7A4

	thumb_func_start sub_809B7B4
sub_809B7B4: @ 809B7B4
	push {lr}
	ldr r0, =gUnknown_02039F2C
	ldrb r0, [r0]
	bl sub_80F84C4
	bl script_env_2_set_ctx_paused
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B7B4

	thumb_func_start s9C_execute_HM
s9C_execute_HM: @ 809B7CC
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_020375D0
	strh r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	bl FieldEffectStart
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end s9C_execute_HM

	thumb_func_start s9D_set_HM_animation_data
s9D_set_HM_animation_data: @ 809B7F4
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r1, =gUnknown_02038C08
	lsls r4, 2
	adds r4, r1
	lsls r0, 16
	asrs r0, 16
	str r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s9D_set_HM_animation_data

	thumb_func_start sub_809B824
sub_809B824: @ 809B824
	push {lr}
	ldr r0, =gUnknown_020375D0
	ldrb r0, [r0]
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	beq _0809B83C
	movs r0, 0
	b _0809B83E
	.pool
_0809B83C:
	movs r0, 0x1
_0809B83E:
	pop {r1}
	bx r1
	thumb_func_end sub_809B824

	thumb_func_start s9E_checkarray_HM_animation
s9E_checkarray_HM_animation: @ 809B844
	push {r4,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	ldr r1, =gUnknown_020375D0
	strh r0, [r1]
	ldr r1, =sub_809B824
	adds r0, r4, 0
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end s9E_checkarray_HM_animation

	thumb_func_start s9F_changeposition_fly
s9F_changeposition_fly: @ 809B870
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_8084D1C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end s9F_changeposition_fly

	thumb_func_start sA0_check_gender
sA0_check_gender: @ 809B88C
	ldr r1, =gScriptResult
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	strh r0, [r1]
	movs r0, 0
	bx lr
	.pool
	thumb_func_end sA0_check_gender

	thumb_func_start sA1_play_cry
sA1_play_cry: @ 809B8A4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl PlayCry5
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sA1_play_cry

	thumb_func_start sub_809B8DC
sub_809B8DC: @ 809B8DC
	push {lr}
	ldr r1, =IsCryFinished
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809B8DC

	thumb_func_start sA2_setmaptile
sA2_setmaptile: @ 809B8F0
	push {r4-r7,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	adds r1, r6, 0x7
	lsls r1, 16
	lsrs r6, r1, 16
	adds r1, r5, 0x7
	lsls r1, 16
	lsrs r5, r1, 16
	cmp r0, 0
	bne _0809B954
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r7, 0
	bl MapGridSetMetatileIdAt
	b _0809B966
_0809B954:
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1, 0
	adds r2, r7, 0
	orrs r2, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl MapGridSetMetatileIdAt
_0809B966:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sA2_setmaptile

	thumb_func_start sAC_open_door
sAC_open_door: @ 809B970
	push {r4,r5,lr}
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	adds r5, 0x7
	lsls r5, 16
	lsrs r5, 16
	movs r0, 0xE0
	lsls r0, 11
	adds r4, r0
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl cur_mapdata_get_door_sound_at
	lsls r0, 16
	lsrs r0, 16
	bl PlaySE
	adds r0, r5, 0
	adds r1, r4, 0
	bl task_overworld_door_add_if_role_69_for_opening_door_at
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sAC_open_door

	thumb_func_start sub_809B9C8
sub_809B9C8: @ 809B9C8
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	adds r4, 0x7
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xE0
	lsls r0, 11
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_808A8AC
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809B9C8

	thumb_func_start sub_809BA0C
sub_809BA0C: @ 809BA0C
	push {lr}
	bl sub_808A91C
	lsls r0, 24
	cmp r0, 0
	beq _0809BA1C
	movs r0, 0
	b _0809BA1E
_0809BA1C:
	movs r0, 0x1
_0809BA1E:
	pop {r1}
	bx r1
	thumb_func_end sub_809BA0C

	thumb_func_start sub_809BA24
sub_809BA24: @ 809BA24
	push {lr}
	ldr r1, =sub_809BA0C
	bl script_setup_asm_script
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BA24

	thumb_func_start sub_809BA38
sub_809BA38: @ 809BA38
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	adds r4, 0x7
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xE0
	lsls r0, 11
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_808A854
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809BA38

	thumb_func_start sub_809BA7C
sub_809BA7C: @ 809BA7C
	push {r4,r5,lr}
	adds r5, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r1, r0, 0
	lsls r1, 16
	adds r4, 0x7
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xE0
	lsls r0, 11
	adds r1, r0
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_808A880
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809BA7C

	thumb_func_start sub_809BAC0
sub_809BAC0: @ 809BAC0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x8]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r0, r4, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809BAC0

	thumb_func_start sub_809BAFC
sub_809BAFC: @ 809BAFC
	movs r0, 0
	bx lr
	thumb_func_end sub_809BAFC

	thumb_func_start sB3_get_coin_amount
sB3_get_coin_amount: @ 809BB00
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl GetVarPointer
	adds r4, r0, 0
	bl GetCoins
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sB3_get_coin_amount

	thumb_func_start sub_809BB20
sub_809BB20: @ 809BB20
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl AddCoins
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809BB48
	ldr r1, =gScriptResult
	movs r0, 0
	b _0809BB4C
	.pool
_0809BB48:
	ldr r1, =gScriptResult
	movs r0, 0x1
_0809BB4C:
	strh r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BB20

	thumb_func_start sub_809BB58
sub_809BB58: @ 809BB58
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl SubtractCoins
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809BB80
	ldr r1, =gScriptResult
	movs r0, 0
	b _0809BB84
	.pool
_0809BB80:
	ldr r1, =gScriptResult
	movs r0, 0x1
_0809BB84:
	strh r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BB58

	thumb_func_start sub_809BB90
sub_809BB90: @ 809BB90
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_81A89A0
	ldr r1, =gUnknown_020375CA
	strh r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BB90

	thumb_func_start sub_809BBB4
sub_809BBB4: @ 809BBB4
	push {lr}
	bl sub_81A8AF8
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_809BBB4

	thumb_func_start ScrCmd_MossdeepGymSwitch
ScrCmd_MossdeepGymSwitch: @ 809BBC0
	push {lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sub_81A8934
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end ScrCmd_MossdeepGymSwitch

	thumb_func_start sub_809BBDC
sub_809BBDC: @ 809BBDC
	push {lr}
	bl sub_81A895C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_809BBDC

	thumb_func_start sub_809BBE8
sub_809BBE8: @ 809BBE8
	push {lr}
	bl sub_80B47BC
	ldr r1, =gUnknown_03005DF0
	strb r0, [r1]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BBE8

	thumb_func_start sub_809BBFC
sub_809BBFC: @ 809BBFC
	push {r4,lr}
	adds r4, r0, 0
	bl is_c1_link_related_active
	cmp r0, 0
	beq _0809BC0C
	movs r0, 0
	b _0809BC30
_0809BC0C:
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_03005DF0
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _0809BC2E
	bl sub_8098630
	ldr r1, =sub_8098734
	adds r0, r4, 0
	bl script_setup_asm_script
_0809BC2E:
	movs r0, 0x1
_0809BC30:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BBFC

	thumb_func_start sCD_set_obedient_bit
sCD_set_obedient_bit: @ 809BC44
	push {lr}
	sub sp, 0x4
	movs r2, 0x1
	mov r1, sp
	strb r2, [r1]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x50
	mov r2, sp
	bl SetMonData
	movs r0, 0
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sCD_set_obedient_bit

	thumb_func_start sCE_check_obedient_bit
sCE_check_obedient_bit: @ 809BC7C
	push {r4,lr}
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =gScriptResult
	movs r1, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x50
	movs r2, 0
	bl GetMonData
	strh r0, [r4]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sCE_check_obedient_bit

	thumb_func_start sCF_execute_RAM_script_DMA
sCF_execute_RAM_script_DMA: @ 809BCB4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8099244
	adds r2, r0, 0
	cmp r2, 0
	beq _0809BCD0
	ldr r1, =gUnknown_020375C0
	ldr r0, [r4, 0x8]
	str r0, [r1]
	adds r0, r4, 0
	adds r1, r2, 0
	bl script_jump
_0809BCD0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sCF_execute_RAM_script_DMA

	thumb_func_start sD1_warp_v5
sD1_warp_v5: @ 809BCDC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl sub_808D074
	bl sub_80B0244
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sD1_warp_v5

	thumb_func_start sub_809BD70
sub_809BD70: @ 809BD70
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, [r4, 0x8]
	ldrb r2, [r0]
	mov r1, sp
	strb r2, [r1]
	adds r0, 0x1
	str r0, [r4, 0x8]
	cmp r3, 0x5
	bhi _0809BDA6
	movs r0, 0x64
	muls r0, r3
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x23
	mov r2, sp
	bl SetMonData
_0809BDA6:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BD70

	thumb_func_start sub_809BDB4
sub_809BDB4: @ 809BDB4
	push {r4,lr}
	ldr r4, =gUnknown_03000F30
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_819746C
	ldrb r0, [r4]
	bl RemoveWindow
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809BDB4

	thumb_func_start sub_809BDD0
sub_809BDD0: @ 809BDD0
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r4, [r4]
	bl sub_806F07C
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BDD0

	thumb_func_start sub_809BE0C
sub_809BE0C: @ 809BE0C
	push {r4,lr}
	ldr r1, [r0, 0x8]
	ldrb r4, [r1]
	adds r1, 0x1
	str r1, [r0, 0x8]
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gUnknown_085102D4
	lsls r4, 2
	adds r4, r1
	ldr r4, [r4]
	bl sub_806F0B0
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_809BE0C

	thumb_func_start sub_809BE48
sub_809BE48: @ 809BE48
	ldr r1, =gUnknown_020375CA
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_809BE48

	thumb_func_start sub_809BE54
sub_809BE54: @ 809BE54
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r9, r1
	adds r0, 0x1
	str r0, [r5, 0x8]
	ldrb r1, [r0]
	mov r8, r1
	adds r1, r0, 0x1
	str r1, [r5, 0x8]
	ldrb r6, [r0, 0x1]
	adds r1, 0x1
	str r1, [r5, 0x8]
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl script_read_halfword
	lsls r0, 16
	lsrs r0, 16
	bl VarGet
	mov r1, r9
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	mov r1, r8
	lsls r1, 24
	asrs r1, 24
	mov r8, r1
	lsls r6, 24
	asrs r6, 24
	lsls r4, 24
	asrs r4, 24
	lsls r0, 24
	asrs r0, 24
	str r0, [sp]
	mov r0, r9
	adds r2, r6, 0
	adds r3, r4, 0
	bl warp1_set
	bl sub_80AF79C
	bl player_avatar_init_params_reset
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809BE54

	.align 2, 0 @ Don't pad with nop.
