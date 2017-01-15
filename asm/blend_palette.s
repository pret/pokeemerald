	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start BlendPalette
BlendPalette: @ 806F98C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 24
	lsrs r7, r2, 24
	mov r0, sp
	strh r3, [r0]
	movs r6, 0
	cmp r6, r12
	bcs _0806FA12
	ldr r0, =gUnknown_02037714
	mov r10, r0
	ldr r1, =gUnknown_02037B14
	mov r9, r1
_0806F9BA:
	mov r0, r8
	adds r5, r6, r0
	lsls r5, 16
	lsrs r5, 15
	mov r1, r10
	adds r0, r5, r1
	ldr r3, [r0]
	lsls r4, r3, 27
	lsls r2, r3, 22
	lsls r3, 17
	add r5, r9
	lsrs r4, 27
	ldr r1, [sp]
	lsls r0, r1, 27
	lsrs r0, 27
	subs r0, r4
	muls r0, r7
	asrs r0, 4
	adds r4, r0
	lsrs r2, 27
	lsls r0, r1, 22
	lsrs r0, 27
	subs r0, r2
	muls r0, r7
	asrs r0, 4
	adds r2, r0
	lsls r2, 5
	orrs r4, r2
	lsrs r3, 27
	lsls r1, 17
	lsrs r1, 27
	subs r1, r3
	adds r0, r1, 0
	muls r0, r7
	asrs r0, 4
	adds r3, r0
	lsls r3, 10
	orrs r4, r3
	strh r4, [r5]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r12
	bcc _0806F9BA
_0806FA12:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BlendPalette

	.align 2, 0 @ Don't pad with nop.
