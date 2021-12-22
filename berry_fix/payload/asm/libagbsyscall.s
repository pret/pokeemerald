	.include "asm/macros/function.inc"
	.include "constants/gba_constants.inc"

	.syntax unified

	.text

	thumb_func_start CpuSet
CpuSet:
	svc 0xB
	bx lr
	thumb_func_end CpuSet

	thumb_func_start Div
Div:
	svc 0x6
	bx lr
	thumb_func_end Div

	thumb_func_start Mod
Mod:
	svc 0x6
	adds r0, r1, 0
	bx lr
	thumb_func_end Mod

	thumb_func_start LZ77UnCompVram
LZ77UnCompVram:
	svc 0x12
	bx lr
	thumb_func_end LZ77UnCompVram

	thumb_func_start RegisterRamReset
RegisterRamReset:
	svc 0x1
	bx lr
	thumb_func_end RegisterRamReset

	thumb_func_start VBlankIntrWait
VBlankIntrWait:
	movs r2, 0
	svc 0x5
	bx lr
	thumb_func_end VBlankIntrWait

	.align 2, 0 @ Don't pad with nop.
