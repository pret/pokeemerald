	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.set SIO_ERROR,      0x0040
	.set SIO_MULTI_BUSY, 0x0080

	.set EWRAM_ORIG, 0x02000000
	.set EXEC_ORIG,  0x02010000
	.set PROG_ORIG,  0x00008000

	.syntax unified

	.text

	arm_func_start _start
_start: @ 0
	b _entry
	arm_func_end _start

	.include "asm/berry_fix_header.inc"

@ C0
	.word 0

	.global _GPIOPortData
_GPIOPortData: @ C4
	.2byte 0

	.global _GPIOPortDirection
_GPIOPortDirection: @ C6
	.2byte 0

	.global _GPIOPortReadEnable
_GPIOPortReadEnable: @ C8
	.2byte 0

@ CA
	.2byte 0

@ CC
	.space 0x34

	arm_func_start _entry
_entry: @ 100
	b _send
	arm_func_end _entry

	.space 0x1C

	arm_func_start _recv
_recv:
	@ Waits until link cable is no longer busy.
	@ Returns nz if an error has occurred
	@ Otherwise, returns the received short in r1.
	@ Preserves r0
_120:
	ldrh r1, [r0, 0x8] @ SIOCNT
	tst r1, SIO_MULTI_BUSY
	beq _120
_12c:
	ldrh r1, [r0, 0x8] @ SIOCNT
	tst r1, SIO_MULTI_BUSY
	bne _12c
	ldrh r1, [r0, 0x8] @ SIOCNT
	tst r1, SIO_ERROR
	bxne lr
	ldrh r1, [r0] @ SIOMULTI0
	bx lr
	arm_func_end _recv

	arm_func_start _send
_send: @ 14c
	ldr r0, =REG_SIOMULTI0
_150:
	bl _recv
	bne _150
	mov r2, 0
	strh r2, [r0, 0xa] @ SIOMLT_SEND
	cmp r1, 0
	bne _150
	mov r2, 0x8000
_16c:
	mov r1, 0
_170:
	strh r1, [r0, 0xa] @ SIOMLT_SEND
	bl _recv
	bne _150
	cmp r1, r2
	bne _16c
	lsr r2, 5
	cmp r1, 0
	bne _170
	ldr r3, =BerryFixMBHeaderGameCode - PROG_ORIG + EWRAM_ORIG
	ldrh r2, [r3]
	strh r2, [r0, 0xa] @ SIOMLT_SEND
	bl _recv
_1a0:
	bne _1a0
	cmp r1, r2
	bne _1a0
	ldrh r2, [r3, 0x2]
	strh r2, [r0, 0xa] @ SIOMLT_SEND
	bl _recv
	bne _1a0
	cmp r1, r2
	bne _1a0
	mov r1, 0
	strh r1, [r0, 0xa] @ SIOMLT_SEND
	ldr r0, =_data_2f0 - PROG_ORIG + EWRAM_ORIG
	ldr r1, =EXEC_ORIG
	swi 0x11 << 16
	ldr lr, =EXEC_ORIG
	bx lr
	.pool
	arm_func_end _send
	@ 1f0

	.align 2, 0 @ don't pad with nop

	@ The program is loaded into EWRAM.
	@ This is a small memory buffer.
	.space 0x100

_data_2f0:
	.incbin "data/berry_fix_program.mb.lz"
