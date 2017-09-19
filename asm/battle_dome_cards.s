	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_818D820
sub_818D820: @ 818D820
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_818D5B0
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_818D820

	thumb_func_start sub_818D834
sub_818D834: @ 818D834
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r4, [sp, 0x18]
	ldr r5, [sp, 0x1C]
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	bl sub_818D65C
	lsls r0, 16
	lsrs r0, 16
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818D834

	thumb_func_start sub_818D864
sub_818D864: @ 818D864
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r7, [sp, 0x38]
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	lsls r7, 24
	lsrs r7, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r4, 0
	str r4, [sp, 0x10]
	bl sub_818D6CC
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D864

	thumb_func_start sub_818D8AC
sub_818D8AC: @ 818D8AC
	push {r4,r5,lr}
	sub sp, 0x14
	adds r5, r1, 0
	ldr r1, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r0, 16
	lsrs r0, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r2, 16
	asrs r2, 16
	str r2, [sp]
	lsls r3, 16
	asrs r3, 16
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x1
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_818D384
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818D8AC

	thumb_func_start sub_818D8F0
sub_818D8F0: @ 818D8F0
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_818D5B0
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_818D8F0

	thumb_func_start sub_818D904
sub_818D904: @ 818D904
	push {r4,lr}
	sub sp, 0xC
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	movs r1, 0x1
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0
	adds r3, r4, 0
	bl sub_818D65C
	lsls r0, 16
	lsrs r0, 16
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_818D904

	thumb_func_start sub_818D938
sub_818D938: @ 818D938
	push {r4,r5,lr}
	sub sp, 0x14
	adds r5, r1, 0
	ldr r1, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r0, 16
	lsrs r0, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r1, 24
	lsrs r1, 24
	lsls r4, 24
	lsrs r4, 24
	str r2, [sp]
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x1
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_818D6CC
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818D938

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
