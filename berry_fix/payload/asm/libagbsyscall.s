	.include "asm/macros/function.inc"
	.include "constants/gba_constants.inc"

	.syntax unified

	.text

	thumb_func_start CpuSet
CpuSet: @ 81E3B64
	swi 0xB
	bx lr
	thumb_func_end CpuSet

	thumb_func_start Div
Div: @ 81E3B68
	swi 0x6
	bx lr
	thumb_func_end Div

	thumb_func_start Mod
Mod:
	swi 0x6
	adds r0, r1, 0
	bx lr
	thumb_func_end Mod

	thumb_func_start LZ77UnCompVram
LZ77UnCompVram: @ 81E3B6C
	swi 0x12
	bx lr
	thumb_func_end LZ77UnCompVram

	thumb_func_start RegisterRamReset
RegisterRamReset: @ 81E3B80
	swi 0x1
	bx lr
	thumb_func_end RegisterRamReset

	thumb_func_start VBlankIntrWait
VBlankIntrWait: @ 81E3BA0
	movs r2, 0
	swi 0x5
	bx lr
	thumb_func_end VBlankIntrWait

	.align 2, 0 @ Don't pad with nop.
