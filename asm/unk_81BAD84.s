	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81BAD84
sub_81BAD84: @ 81BAD84
	push {r4-r6,lr}
	movs r6, 0x80
	lsls r6, 19
	movs r2, 0
	strh r2, [r6]
	ldr r1, =0x04000010
	strh r2, [r1]
	adds r1, 0x2
	strh r2, [r1]
	adds r1, 0x3E
	strh r2, [r1]
	ldr r5, =gUnknown_08617128
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r0, r4, r5
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	adds r0, r5, 0x4
	adds r0, r4, r0
	ldr r0, [r0]
	ldr r1, =0x0600f800
	bl LZ77UnCompVram
	adds r5, 0x8
	adds r4, r5
	ldr r0, [r4]
	movs r1, 0xA0
	lsls r1, 19
	movs r4, 0x80
	lsls r4, 1
	adds r2, r4, 0
	bl CpuSet
	ldr r1, =0x04000008
	movs r2, 0xF8
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	strh r4, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BAD84


	.align 2, 0 @ Don't pad with nop.
