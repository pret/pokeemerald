	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start DecorationRemove
DecorationRemove: @ 81619DC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	cmp r5, 0
	bne _081619F8
	b _08161A26
_081619EA:
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	bl sub_8161A38
	movs r0, 0x1
	b _08161A28
_081619F8:
	ldr r2, =gDecorationInventories
	ldr r1, =gDecorations
	lsls r0, r5, 5
	adds r0, r1
	ldrb r4, [r0, 0x13]
	lsls r0, r4, 3
	adds r0, r2
	ldrb r1, [r0, 0x4]
	cmp r3, r1
	bcs _08161A26
	adds r6, r4, 0
	adds r4, r0, 0
	adds r2, r1, 0
_08161A12:
	ldr r0, [r4]
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, r5
	beq _081619EA
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r2
	bcc _08161A12
_08161A26:
	movs r0, 0
_08161A28:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end DecorationRemove

	thumb_func_start sub_8161A38
sub_8161A38: @ 8161A38
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	movs r6, 0
	ldr r2, =gDecorationInventories
	lsrs r0, 21
	adds r1, r0, r2
	ldrb r3, [r1, 0x4]
	cmp r6, r3
	bcs _08161ABC
	adds r7, r0, 0
	mov r10, r1
	mov r0, r10
	str r0, [sp]
_08161A5C:
	adds r1, r6, 0x1
	lsls r0, r1, 24
	lsrs r3, r0, 24
	adds r2, r7, 0
	mov r12, r1
	mov r1, r10
	ldrb r1, [r1, 0x4]
	cmp r3, r1
	bcs _08161AAE
	ldr r0, =gDecorationInventories
	mov r9, r0
	adds r1, r0, 0
	mov r8, r1
_08161A76:
	mov r0, r9
	adds r5, r2, r0
	ldr r1, [r5]
	adds r0, r1, r3
	ldrb r4, [r0]
	adds r2, r4, 0
	cmp r2, 0
	beq _08161A9C
	adds r0, r1, r6
	ldrb r1, [r0]
	cmp r1, 0
	beq _08161A92
	cmp r1, r2
	bls _08161A9C
_08161A92:
	ldrb r1, [r0]
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, r3
	strb r1, [r0]
_08161A9C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, r7, 0
	mov r1, r8
	adds r0, r2, r1
	ldrb r0, [r0, 0x4]
	cmp r3, r0
	bcc _08161A76
_08161AAE:
	mov r3, r12
	lsls r0, r3, 24
	lsrs r6, r0, 24
	ldr r0, [sp]
	ldrb r0, [r0, 0x4]
	cmp r6, r0
	bcc _08161A5C
_08161ABC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161A38

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
