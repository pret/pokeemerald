	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sub_8161AD0
sub_8161AD0: @ 8161AD0
	push {r4,r5,lr}
	lsls r0, 24
	movs r4, 0
	movs r3, 0
	ldr r2, =gDecorationInventories
	lsrs r1, r0, 21
	adds r0, r1, r2
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bcs _08161B04
	adds r5, r2, 0
_08161AE6:
	adds r2, r1, r5
	ldr r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08161AF8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_08161AF8:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r2, [r2, 0x4]
	cmp r3, r2
	bcc _08161AE6
_08161B04:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8161AD0

	thumb_func_start sub_8161B10
sub_8161B10: @ 8161B10
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_08161B16:
	adds r0, r4, 0
	bl sub_8161AD0
	adds r0, r5, r0
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _08161B16
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8161B10

	.align 2, 0 @ Don't pad with nop.
