	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81BF2B8
sub_81BF2B8: @ 81BF2B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r0, [sp]
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x28]
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	mov r8, r0
	lsrs r7, r0, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r10
	adds r1, r7, 0
	bl __divsi3
	adds r5, r0, 0
	lsls r5, 24
	lsrs r4, r5, 24
	ldr r3, =gUnknown_030012A8
	strh r4, [r3]
	mov r0, r10
	adds r1, r7, 0
	str r3, [sp, 0x4]
	bl __modsi3
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r3, [sp, 0x4]
	strh r2, [r3, 0x2]
	movs r1, 0x7
	ands r4, r1
	ands r2, r1
	strh r4, [r3, 0x4]
	strh r2, [r3, 0x6]
	lsrs r0, 27
	lsrs r5, 27
	strh r0, [r3, 0x8]
	strh r5, [r3, 0xA]
	mov r1, r8
	lsrs r1, 27
	lsls r1, 6
	mov r8, r1
	mov r1, r8
	muls r1, r5
	lsls r0, 6
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	strh r1, [r3, 0xC]
	lsls r4, 3
	adds r4, r2
	adds r1, r4
	lsls r4, r1, 16
	lsrs r4, 17
	strh r1, [r3, 0xE]
	movs r1, 0x1
	mov r0, r10
	ands r1, r0
	movs r2, 0x1
	eors r1, r2
	lsls r0, r1, 2
	lsls r6, r0
	eors r1, r2
	lsls r1, 2
	movs r0, 0xF
	lsls r0, r1
	orrs r6, r0
	lsls r6, 24
	lsrs r6, 24
	mov r1, r9
	lsls r1, 5
	mov r9, r1
	add r9, r4
	ldr r1, [sp]
	add r1, r9
	ldrb r0, [r1]
	ands r6, r0
	strb r6, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81BF2B8

	.align 2, 0 @ Don't pad with nop.
