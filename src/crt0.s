	.include "constants/gba_constants.inc"

	.syntax unified

	.global Start

	.text

	.arm

Start: @ 8000000
	b Init

	.include "asm/rom_header.inc"

@ 80000C0
	.word 0

	.global GPIOPortData
GPIOPortData: @ 80000C4
	.2byte 0

	.global GPIOPortDirection
GPIOPortDirection: @ 80000C6
	.2byte 0

	.global GPIOPortReadEnable
GPIOPortReadEnable: @ 80000C8
	.2byte 0

@ 80000CA
	.2byte 0

@ 80000CC
	.space 0x34

	.4byte 3
	.4byte 2

	.ascii "pokemon emerald version"
	.space 9

	.4byte gMonFrontPicTable
	.4byte gMonBackPicTable
	.4byte gMonPaletteTable
	.4byte gMonShinyPaletteTable
	.4byte gMonIconTable
	.4byte gMonIconPaletteIndices
	.4byte gMonIconPaletteTable
	.4byte gSpeciesNames
	.4byte gMoveNames
	.4byte gDecorations

	.4byte 0x00001270, 0x0000139c, 0x00000018, 0x00000988
	.4byte 0x00003b24, 0x00000046, 0x000008e4, 0x000008ac
	.4byte 0x00000182

	.byte 0x07, 0x0a, 0x0a, 0x0a, 0x0c, 0x0c, 0x06, 0x0c
	.byte 0x06, 0x10, 0x12, 0x0c, 0x0f, 0x0b, 0x01, 0x08

	.4byte 0x0000000c, 0x00000f2c, 0x00003d88, 0x00000234
	.4byte 0x00000238, 0x00000009, 0x0000000a, 0x00000000
	.4byte 0x00000008, 0x00000ca8, 0x00000ca8, 0x000031c7
	.4byte 0x000031b3, 0x00000000

	.4byte gBaseStats
	.4byte gAbilityNames
	.4byte gAbilityDescriptionPointers
	.4byte gItems
	.4byte gBattleMoves
	.4byte gBallSpriteSheets
	.4byte gBallSpritePalettes

	.4byte 0x000000a8, 0x00000864, 0x0000089b

	.byte 0x1e, 0x1e, 0x10, 0x40

	.4byte 0x0000322e, 0x00000498, 0x000031a8, 0x000031f8
	.4byte 0x00000034, 0x00000000, 0x00000000

	.arm
	.align 2, 0
	.global Init
Init: @ 8000204
	mov r0, #PSR_IRQ_MODE
	msr cpsr_cf, r0
	ldr sp, sp_irq
	mov r0, #PSR_SYS_MODE
	msr cpsr_cf, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	adr r0, IntrMain
	str r0, [r1]
	.if MODERN
	mov r0, #255 @ RESET_ALL
	svc #1 << 16
	.endif @ MODERN
	ldr r1, =AgbMain + 1
	mov lr, pc
	bx r1
	b Init

	.align 2, 0
sp_sys: .word IWRAM_END - 0x1c0
sp_irq: .word IWRAM_END - 0x60

	.pool

	.arm
	.align 2, 0
	.global IntrMain
IntrMain: @ 8000248
	mov r3, #REG_BASE
	add r3, r3, #OFFSET_REG_IE
	ldr r2, [r3]
	ldrh r1, [r3, #OFFSET_REG_IME - 0x200]
	mrs r0, spsr
	stmfd sp!, {r0-r3,lr}
	mov r0, #0
	strh r0, [r3, #OFFSET_REG_IME - 0x200]
	and r1, r2, r2, lsr #16
	mov r12, #0
	ands r0, r1, #INTR_FLAG_VCOUNT
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	mov r0, 0x1
	strh r0, [r3, #OFFSET_REG_IME - 0x200]
	ands r0, r1, #INTR_FLAG_SERIAL
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_TIMER3
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_HBLANK
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_VBLANK
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_TIMER0
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_TIMER1
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_TIMER2
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_DMA0
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_DMA1
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_DMA2
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_DMA3
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_KEYPAD
	bne IntrMain_FoundIntr
	add r12, r12, 0x4
	ands r0, r1, #INTR_FLAG_GAMEPAK
	strbne r0, [r3, #REG_SOUNDCNT_X - REG_IE]
	bne . @ spin
IntrMain_FoundIntr:
	strh r0, [r3, #OFFSET_REG_IF - 0x200]
	bic r2, r2, r0
	ldr r0, =gSTWIStatus
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	mov r1, 0x8
	lsl r0, r1, r0
	orr r0, r0, #INTR_FLAG_GAMEPAK
	orr r1, r0, #INTR_FLAG_SERIAL | INTR_FLAG_TIMER3 | INTR_FLAG_VCOUNT | INTR_FLAG_HBLANK
	and r1, r1, r2
	strh r1, [r3, #OFFSET_REG_IE - 0x200]
	mrs r3, cpsr
	bic r3, r3, #PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, #PSR_SYS_MODE
	msr cpsr_cf, r3
	ldr r1, =gIntrTable
	add r1, r1, r12
	ldr r0, [r1]
	stmfd sp!, {lr}
	adr lr, IntrMain_RetAddr
	bx r0
IntrMain_RetAddr:
	ldmfd sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, #PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, #PSR_I_BIT | PSR_IRQ_MODE
	msr cpsr_cf, r3
	ldmia sp!, {r0-r3,lr}
	strh r2, [r3, #OFFSET_REG_IE - 0x200]
	strh r1, [r3, #OFFSET_REG_IME - 0x200]
	msr spsr_cf, r0
	bx lr

	.pool

	.align 2, 0 @ Don't pad with nop.
