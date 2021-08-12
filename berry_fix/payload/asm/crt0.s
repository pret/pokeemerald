    .include "asm/macros/function.inc"
	.include "constants/gba_constants.inc"

	.syntax unified

	.text

	.arm
	.align 2, 0
	.global Init
Init:
	mov r0, #PSR_IRQ_MODE
	msr cpsr_cf, r0
	ldr sp, sp_irq
	mov r0, #PSR_SYS_MODE
	msr cpsr_cf, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	ldr r0, =IntrMain
	str r0, [r1]
	ldr r1, =AgbMain + 1
	mov lr, pc
	bx r1
	b Init

	.align 2, 0
sp_sys: .word IWRAM_END - 0x100
sp_irq: .word IWRAM_END - 0x60

	.pool
	.size Init, .-Init

	.arm
	.align 2, 0
	.global IntrMain
IntrMain: @ 0x2010048
	mov ip, #REG_BASE
	add r3, ip, #OFFSET_REG_IE
	ldr r2, [r3]
	and r1, r2, r2, lsr #16
	mov r2, #0
	ands r0, r1, #0x2000
	strbne r0, [r3, #-0x17c]
_02010064:
	bne _02010064
	ands r0, r1, #0xc0
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #1
	strhne r0, [ip, #-8]
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #2
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #4
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #0x100
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #0x200
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #0x400
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #0x800
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #0x1000
	bne _020100DC
	add r2, r2, #4
	ands r0, r1, #8
_020100DC:
	strh r0, [r3, #2]
	ldr r1, =gIntrTable
	add r1, r1, r2
	ldr r0, [r1]
	bx r0
	.pool
	.size IntrMain, .-IntrMain
