	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_81D9CDC
sub_81D9CDC: @ 81D9CDC
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r3, r2, 24
	lsls r0, r3, 4
	orrs r3, r0
	lsls r0, r3, 24
	lsrs r3, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _081D9D04
_081D9CF4:
	adds r2, r6, r4
	ldrb r1, [r2]
	adds r0, r3, 0
	eors r0, r1
	strb r0, [r2]
	adds r4, 0x1
	cmp r4, r5
	bcc _081D9CF4
_081D9D04:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9CDC

	thumb_func_start sub_81D9D0C
sub_81D9D0C: @ 81D9D0C
	push {lr}
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	adds r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _081D9D24
	movs r0, 0x1
_081D9D24:
	pop {r1}
	bx r1
	thumb_func_end sub_81D9D0C

	thumb_func_start sub_81D9D28
sub_81D9D28: @ 81D9D28
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	lsls r1, 24
	lsrs r1, 24
	adds r0, r3
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_81D9D28

	thumb_func_start sub_81D9D40
sub_81D9D40: @ 81D9D40
	lsrs r3, r1, 3
	movs r2, 0x7
	ands r2, r1
	movs r1, 0x80
	asrs r1, r2
	mvns r1, r1
	lsls r1, 24
	lsrs r1, 24
	adds r0, r3
	ldrb r2, [r0]
	ands r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_81D9D40

	thumb_func_start sub_81D9D5C
sub_81D9D5C: @ 81D9D5C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r1
	adds r1, r2, 0
	mov r8, r3
	ldr r7, [sp, 0x1C]
	movs r5, 0
	cmp r5, r7
	bcs _081D9DA0
	adds r4, r1, 0
_081D9D76:
	mov r0, r8
	adds r1, r0, r5
	mov r0, r9
	bl sub_81D9D0C
	lsls r0, 24
	cmp r0, 0
	beq _081D9D90
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D9D28
	b _081D9D98
_081D9D90:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81D9D40
_081D9D98:
	adds r4, 0x1
	adds r5, 0x1
	cmp r5, r7
	bcc _081D9D76
_081D9DA0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D9D5C

	thumb_func_start sub_81D9DAC
sub_81D9DAC: @ 81D9DAC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r4, 0
	movs r5, 0
	cmp r4, r6
	bcs _081D9DD6
_081D9DC0:
	lsls r4, 1
	adds r1, r7, r5
	mov r0, r8
	bl sub_81D9D0C
	lsls r0, 24
	lsrs r0, 24
	orrs r4, r0
	adds r5, 0x1
	cmp r5, r6
	bcc _081D9DC0
_081D9DD6:
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D9DAC

	.align 2, 0 @ Don't pad with nop.
