	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8122C5C
sub_8122C5C: @ 8122C5C
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r1, 16
	movs r3, 0
	ldr r2, =gUnknown_0859F53C
_08122C6A:
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, r4
	bne _08122C84
	movs r0, 0x1
	ldrsb r0, [r2, r0]
	cmp r0, r1
	bne _08122C84
	adds r0, r3, 0x1
	b _08122C8E
	.pool
_08122C84:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x15
	bls _08122C6A
	movs r0, 0
_08122C8E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8122C5C

	thumb_func_start sub_8122C94
sub_8122C94: @ 8122C94
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_8122C5C
	cmp r0, 0
	beq _08122CB4
	lsls r0, 3
	ldr r1, =gUnknown_0859F534
	adds r0, r1
	b _08122CB6
	.pool
_08122CB4:
	movs r0, 0
_08122CB6:
	pop {r1}
	bx r1
	thumb_func_end sub_8122C94

	thumb_func_start sub_8122CBC
@ warpdata *sub_8122CBC(int a1)
sub_8122CBC: @ 8122CBC
	push {lr}
	cmp r0, 0
	beq _08122CD4
	cmp r0, 0x16
	bhi _08122CD4
	lsls r0, 3
	ldr r1, =gUnknown_0859F534
	adds r0, r1
	b _08122CD6
	.pool
_08122CD4:
	movs r0, 0
_08122CD6:
	pop {r1}
	bx r1
	thumb_func_end sub_8122CBC

	.align 2, 0 @ Don't pad with nop.
