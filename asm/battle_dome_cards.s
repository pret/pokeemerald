	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_818D97C
sub_818D97C: @ 818D97C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	bne _0818D9A2
	cmp r0, 0
	beq _0818D99C
	ldr r0, =gUnknown_0831F578
	adds r0, 0x3F
	ldrb r0, [r0]
	b _0818D9A2
	.pool
_0818D99C:
	ldr r0, =gUnknown_0831F578
	adds r0, 0x3C
	ldrb r0, [r0]
_0818D9A2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D97C

	.align 2, 0 @ Don't pad with nop.
