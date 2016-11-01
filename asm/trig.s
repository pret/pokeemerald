	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sine
@ s16 sine(s16 t, s16 amplitude)
sine: @ 806F534
	lsls r1, 16
	asrs r1, 16
	ldr r2, =gUnknown_08329F40
	lsls r0, 16
	asrs r0, 15
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r0, r1
	lsls r0, 8
	asrs r0, 16
	bx lr
	.pool
	thumb_func_end sine

	thumb_func_start cosine
@ s16 cosine(s16 t, s16 amplitude)
cosine: @ 806F550
	lsls r1, 16
	asrs r1, 16
	ldr r2, =gUnknown_08329F40
	lsls r0, 16
	asrs r0, 15
	adds r0, 0x80
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r0, r1
	lsls r0, 8
	asrs r0, 16
	bx lr
	.pool
	thumb_func_end cosine

	thumb_func_start sine2
@ s16 sine2(u16 angle)
sine2: @ 806F570
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r5, 0
	movs r1, 0xB4
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0xB4
	bl __udivsi3
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_0832A1C0
	lsls r4, 1
	adds r4, r1
	ldrh r1, [r4]
	cmp r0, 0
	bne _0806F5A8
	lsls r0, r1, 16
	b _0806F5AC
	.pool
_0806F5A8:
	lsls r0, r1, 16
	negs r0, r0
_0806F5AC:
	asrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sine2

	thumb_func_start cosine2
@ s16 cosine2(u16 angle)
cosine2: @ 806F5B4
	push {lr}
	lsls r0, 16
	movs r1, 0xB4
	lsls r1, 15
	adds r0, r1
	lsrs r0, 16
	bl sine2
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end cosine2

	.align 2, 0 @ Don't pad with nop.
