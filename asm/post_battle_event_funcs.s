	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sp0C8_whiteout_maybe
sp0C8_whiteout_maybe: @ 813787C
	push {lr}
	ldr r0, =CB2_WhiteOut
	bl SetMainCallback2
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sp0C8_whiteout_maybe
