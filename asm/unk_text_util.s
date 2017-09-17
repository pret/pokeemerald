	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81AFBF0
sub_81AFBF0: @ 81AFBF0
	push {lr}
	ldr r1, =gUnknown_0203CE9C
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x1C
_081AFBFA:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _081AFBFA
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AFBF0

	thumb_func_start sub_81AFC0C
sub_81AFC0C: @ 81AFC0C
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x7
	bhi _081AFC20
	ldr r1, =gUnknown_0203CE9C
	lsls r0, 2
	adds r0, r1
	str r2, [r0]
_081AFC20:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AFC0C

	thumb_func_start sub_81AFC28
sub_81AFC28: @ 81AFC28
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	beq _081AFC68
	ldr r5, =gUnknown_0203CE9C
_081AFC38:
	cmp r1, 0xF7
	beq _081AFC48
	strb r1, [r2]
	adds r4, 0x1
	adds r2, 0x1
	b _081AFC60
	.pool
_081AFC48:
	adds r4, 0x1
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	cmp r1, 0
	beq _081AFC5E
	adds r0, r2, 0
	bl StringCopy
	adds r2, r0, 0
_081AFC5E:
	adds r4, 0x1
_081AFC60:
	ldrb r1, [r4]
	adds r0, r1, 0
	cmp r0, 0xFF
	bne _081AFC38
_081AFC68:
	movs r0, 0xFF
	strb r0, [r2]
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81AFC28

	thumb_func_start sub_81AFC74
sub_81AFC74: @ 81AFC74
	lsls r0, 24
	ldr r1, =gUnknown_0203CE9C
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81AFC74

	.align 2, 0 @ Don't pad with nop.
