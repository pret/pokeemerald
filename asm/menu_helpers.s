	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




	thumb_func_start sub_8122344
sub_8122344: @ 8122344
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r5, 0
	cmp r5, r6
	bcs _0812239C
	ldr r7, =gSprites
_08122358:
	lsls r1, r5, 4
	ldr r0, =gUnknown_0859F524
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	mov r1, r8
	adds r4, r1, r5
	strb r0, [r4]
	cmp r5, 0
	beq _0812237E
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0x1
	bl StartSpriteAnim
_0812237E:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r6
	bcc _08122358
_0812239C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8122344

	thumb_func_start sub_81223B0
sub_81223B0: @ 81223B0
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	cmp r4, r5
	bcs _081223F6
	ldr r7, =gSprites
_081223C0:
	subs r0, r5, 0x1
	cmp r4, r0
	bne _081223DC
	adds r0, r6, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl DestroySpriteAndFreeResources
	b _081223EC
	.pool
_081223DC:
	adds r0, r6, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	bl DestroySprite
_081223EC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _081223C0
_081223F6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81223B0

	thumb_func_start sub_81223FC
sub_81223FC: @ 81223FC
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r0, r2, 24
	movs r3, 0
	cmp r3, r4
	bcs _0812243E
	ldr r1, =gSprites
	mov r12, r1
	movs r1, 0x1
	ands r0, r1
	lsls r5, r0, 2
	movs r7, 0x5
	negs r7, r7
_0812241C:
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r12
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	orrs r0, r5
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcc _0812241C
_0812243E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81223FC

	thumb_func_start sub_8122448
@ void sub_8122448(int a1, u8 a2, u16 x, u16 y)
sub_8122448: @ 8122448
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r3, 16
	mov r9, r3
	movs r0, 0x80
	ands r0, r4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x7F
	ands r4, r0
	movs r3, 0
	cmp r3, r4
	bcs _081224C8
	ldr r5, =gSprites
	lsls r0, r7, 16
	asrs r0, 16
	subs r0, 0x8
	mov r12, r0
_0812247E:
	subs r0, r4, 0x1
	cmp r3, r0
	bne _081224A0
	mov r0, r8
	cmp r0, 0
	beq _081224A0
	adds r2, r6, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r12
	strh r1, [r0, 0x24]
	b _081224AE
	.pool
_081224A0:
	adds r2, r6, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r7, [r0, 0x24]
_081224AE:
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r9
	adds r1, 0x1
	strh r1, [r0, 0x22]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r4
	bcc _0812247E
_081224C8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8122448

	.align 2, 0 @ Don't pad with nop.
