RomBase: @ 8000000
	b Init

	.include "asm/rom_header.s"

@ 80000C0
	.4byte 0

GPIOPortData: @ 80000C4
	.2byte 0

GPIOPortDirection: @ 80000C6
	.2byte 0

GPIOPortReadWrite: @ 80000C8
	.2byte 0

	.incbin "base_emerald.gba", 0xCA, 0x204 - 0xCA

	arm_func_start Init
Init: @ 8000204
	mov r0, PSR_IRQ_MODE
	msr cpsr_cf, r0
	ldr sp, sp_irq
	mov r0, PSR_SYS_MODE
	msr cpsr_cf, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	adr r0, InterruptMain
	str r0, [r1]
	ldr r1, =Main + 1
	mov lr, pc
	bx r1
	b Init

	.align 2, 0
sp_sys: .4byte IWRAM_END - 0x1c0
sp_irq: .4byte IWRAM_END - 0x60

	.pool

	arm_func_end Init

	arm_func_start InterruptMain
InterruptMain: @ 8000248
	mov r3, REG_BASE
	add r3, r3, 0x200
	ldr r2, [r3, OFFSET_REG_IE - 0x200]
	ldrh r1, [r3, OFFSET_REG_IME - 0x200]
	mrs r0, spsr
	stmdb sp!, {r0-r3,lr}
	mov r0, 0
	strh r0, [r3, OFFSET_REG_IME - 0x200]
	and r1, r2, r2, lsr 16
	mov r12, 0
	ands r0, r1, INTR_FLAG_VCOUNT
	bne $foundInterrupt
	add r12, r12, 0x4
	mov r0, 0x1
	strh r0, [r3, OFFSET_REG_IME - 0x200]
	ands r0, r1, INTR_FLAG_SERIAL
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER3
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_HBLANK
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_VBLANK
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER0
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER1
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_TIMER2
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA0
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA1
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA2
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_DMA3
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_KEYPAD
	bne $foundInterrupt
	add r12, r12, 0x4
	ands r0, r1, INTR_FLAG_GAMEPAK
	strbne r0, [r3, OFFSET_REG_SOUNDCNT_X - 0x200]
$loop:
	bne $loop
$foundInterrupt:
	strh r0, [r3, OFFSET_REG_IF - 0x200]
	bic r2, r2, r0
	ldr r0, =0x03007868
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	mov r1, 0x8
	mov r0, r1, lsl r0
	orr r0, r0, INTR_FLAG_GAMEPAK
	orr r1, r0, INTR_FLAG_SERIAL | INTR_FLAG_TIMER3 | INTR_FLAG_VCOUNT | INTR_FLAG_HBLANK
	and r1, r1, r2
	strh r1, [r3, OFFSET_REG_IE - 0x200]
	mrs r3, cpsr
	bic r3, r3, PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, PSR_SYS_MODE
	msr cpsr_cf, r3
	ldr r1, =0x03002710
	add r1, r1, r12
	ldr r0, [r1]
	stmdb sp!, {lr}
	add lr, pc, 0
	bx r0
	ldmia sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, PSR_I_BIT | PSR_IRQ_MODE
	msr cpsr_cf, r3
	ldmia sp!, {r0-r3,lr}
	strh r2, [r3, OFFSET_REG_IE - 0x200]
	strh r1, [r3, OFFSET_REG_IME - 0x200]
	msr spsr_cf, r0
	bx lr

	.pool

	arm_func_end InterruptMain
