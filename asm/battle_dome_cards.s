	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_818D6CC
sub_818D6CC: @ 818D6CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x18]
	str r2, [sp, 0x1C]
	ldr r1, [sp, 0x44]
	ldr r2, [sp, 0x48]
	ldr r4, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	ldr r6, [sp, 0x54]
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x20]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x80
	lsls r0, 6
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	beq _0818D762
	str r6, [sp]
	mov r0, r9
	ldr r1, [sp, 0x1C]
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_818D09C
	lsls r0, 16
	cmp r0, 0
	bne _0818D762
	movs r0, 0x40
	str r0, [sp]
	str r0, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r1, r8
	str r1, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow
	str r6, [sp]
	mov r0, r9
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	ldr r3, [sp, 0x20]
	bl sub_818D180
	adds r0, r4, 0
	bl Free
	movs r0, 0
	b _0818D764
_0818D762:
	ldr r0, =0x0000ffff
_0818D764:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818D6CC

	thumb_func_start sub_818D778
sub_818D778: @ 818D778
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	ldr r6, [sp, 0x3C]
	ldr r7, [sp, 0x40]
	mov r8, r7
	ldr r7, [sp, 0x44]
	mov r9, r7
	lsls r0, 16
	lsrs r0, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r6, 24
	lsrs r6, 24
	mov r7, r8
	lsls r7, 16
	lsrs r7, 16
	mov r8, r7
	mov r7, r9
	lsls r7, 24
	lsrs r7, 24
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r4, r8
	str r4, [sp, 0xC]
	movs r4, 0
	str r4, [sp, 0x10]
	str r7, [sp, 0x14]
	bl oamt_spawn_poke_or_trainer_picture
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D778

	thumb_func_start sub_818D7D8
sub_818D7D8: @ 818D7D8
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
	lsls r6, 24
	lsrs r6, 24
	lsls r7, 16
	lsrs r7, 16
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r4, 0
	str r4, [sp, 0x10]
	bl sub_818D778
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_818D7D8

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
