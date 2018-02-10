	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start sub_806F47C
sub_806F47C: @ 806F47C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_020249B4
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _0806F4F0
	ldrb r0, [r4, 0x2]
	cmp r0, 0xA3
	beq _0806F4A8
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	b _0806F4F0
	.pool
_0806F4A8:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806F4B6
	bl Free
	movs r0, 0
	str r0, [r4, 0x10]
_0806F4B6:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F4C4
	bl Free
	movs r0, 0
	str r0, [r4, 0xC]
_0806F4C4:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F4D2
	bl Free
	movs r0, 0
	str r0, [r4, 0x8]
_0806F4D2:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0806F4E0
	bl Free
	movs r0, 0
	str r0, [r4, 0x4]
_0806F4E0:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	adds r0, r4, 0
	bl Free
_0806F4F0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806F47C

	thumb_func_start sub_806F4F8
sub_806F4F8: @ 806F4F8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r2, =gUnknown_020249B4
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	cmp r0, 0xA3
	beq _0806F51C
	movs r0, 0
	b _0806F530
	.pool
_0806F51C:
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F528
	movs r3, 0
_0806F528:
	ldr r0, [r1, 0x8]
	lsls r1, r3, 2
	adds r1, r0
	ldr r0, [r1]
_0806F530:
	pop {r1}
	bx r1
	thumb_func_end sub_806F4F8

	.align 2, 0 @ Don't pad with nop.
