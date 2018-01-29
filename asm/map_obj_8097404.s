	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8097E50
sub_8097E50: @ 8097E50
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	mov r8, r1
	movs r0, 0
	mov r12, r0
	ldr r0, =gUnknown_020375B8
	ldr r1, [r0]
	adds r6, r0, 0
	cmp r1, 0
	bne _08097E80
	movs r0, 0x14
	bl AllocZeroed
	str r0, [r6]
	ldrb r1, [r4, 0x8]
	strb r1, [r0]
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0x10]
	b _08097ECC
	.pool
_08097E80:
	movs r2, 0x10
	movs r5, 0
	movs r1, 0
	adds r3, r6, 0
	b _08097E90
_08097E8A:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
_08097E90:
	cmp r1, 0xF
	bhi _08097EB2
	cmp r2, 0x10
	bne _08097EA4
	ldr r0, [r3]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08097EA4
	adds r2, r1, 0
_08097EA4:
	ldr r0, [r3]
	adds r0, r1
	ldrb r0, [r0]
	ldrb r7, [r4, 0x8]
	cmp r0, r7
	bne _08097E8A
	movs r5, 0x1
_08097EB2:
	cmp r5, 0
	bne _08097ECE
	cmp r2, 0x10
	beq _08097ECE
	ldr r0, [r6]
	adds r0, r2
	ldrb r1, [r4, 0x8]
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	movs r0, 0x1
_08097ECC:
	mov r12, r0
_08097ECE:
	mov r1, r12
	cmp r1, 0x1
	bne _08097EE0
	ldrb r0, [r4, 0x1]
	movs r1, 0x10
	orrs r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1]
_08097EE0:
	movs r0, 0x1
	mov r7, r8
	strh r0, [r7, 0x32]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8097E50

	thumb_func_start sub_8097EF0
sub_8097EF0: @ 8097EF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	movs r0, 0x1
	strh r0, [r1, 0x32]
	ldr r5, =gUnknown_020375B8
	ldr r0, [r5]
	cmp r0, 0
	beq _08097F68
	movs r7, 0
	adds r0, r6, 0
	bl sub_8097F78
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x10
	beq _08097F28
	ldr r0, [r5]
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	subs r0, 0x1
	strb r0, [r1, 0x10]
	movs r7, 0x1
_08097F28:
	ldr r0, [r5]
	ldrb r4, [r0, 0x10]
	cmp r4, 0
	bne _08097F36
	bl Free
	str r4, [r5]
_08097F36:
	cmp r7, 0x1
	bne _08097F68
	ldrb r0, [r6, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldrb r1, [r0, 0xC]
	lsls r1, 25
	lsrs r1, 31
	lsls r1, 4
	ldrb r2, [r6, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	movs r1, 0x3
	negs r1, r1
	ands r0, r1
	strb r0, [r6, 0x1]
	mov r2, r8
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_08097F68:
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8097EF0

	thumb_func_start sub_8097F78
@ signed int sub_8097F78(npc_state *a1)
sub_8097F78: @ 8097F78
	push {lr}
	movs r2, 0
	ldr r1, =gUnknown_020375B8
	ldr r1, [r1]
	ldrb r3, [r0, 0x8]
_08097F82:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r3
	bne _08097F94
	adds r0, r2, 0
	b _08097FA0
	.pool
_08097F94:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _08097F82
	movs r0, 0x10
_08097FA0:
	pop {r1}
	bx r1
	thumb_func_end sub_8097F78

	thumb_func_start sub_8097FA4
sub_8097FA4: @ 8097FA4
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, =sub_8097FE4
	movs r1, 0xFF
	bl CreateTask
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r4, 0
	adds r0, 0x8
	adds r1, r6, 0
	bl StoreWordInTwoHalfwords
	strb r5, [r6, 0x1B]
	ldr r0, =0x0000ffff
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097FA4

	thumb_func_start sub_8097FE4
sub_8097FE4: @ 8097FE4
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	adds r0, r4, 0
	adds r0, 0x8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	ldrh r1, [r4, 0xC]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08098020
	ldrh r0, [r4, 0xE]
	ldrh r1, [r2, 0x26]
	adds r0, r1
	strh r0, [r2, 0x26]
_08098020:
	ldrh r1, [r4, 0xC]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _08098030
	ldrh r0, [r4, 0xE]
	negs r0, r0
	strh r0, [r4, 0xE]
_08098030:
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097FE4

	thumb_func_start sub_8098044
sub_8098044: @ 8098044
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks
	adds r0, r1
	adds r0, 0x8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	adds r0, r4, 0
	bl DestroyTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098044

	thumb_func_start sub_8098074
sub_8098074: @ 8098074
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	ldr r7, =gMapObjects
_08098082:
	cmp r4, r6
	beq _080980A8
	cmp r4, r5
	beq _080980A8
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	adds r1, r0, r7
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _080980A8
	ldr r0, =gPlayerAvatar
	ldrb r0, [r0, 0x5]
	cmp r4, r0
	beq _080980A8
	adds r0, r1, 0
	bl FreezeMapObject
_080980A8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _08098082
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8098074

	thumb_func_start sub_80980C0
sub_80980C0: @ 80980C0
	movs r0, 0
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0
	bx lr
	thumb_func_end sub_80980C0

	thumb_func_start sub_80980D0
sub_80980D0: @ 80980D0
	push {lr}
	adds r2, r1, 0
	ldrh r0, [r2, 0x26]
	subs r0, 0x8
	strh r0, [r2, 0x26]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA0
	negs r1, r1
	cmp r0, r1
	bne _080980EC
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	strh r0, [r2, 0x32]
_080980EC:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80980D0

	thumb_func_start sub_80980F4
sub_80980F4: @ 80980F4
	ldr r0, =0x0000ff60
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
	movs r0, 0
	bx lr
	.pool
	thumb_func_end sub_80980F4

	thumb_func_start sub_8098108
sub_8098108: @ 8098108
	push {lr}
	ldrh r0, [r1, 0x26]
	adds r0, 0x8
	strh r0, [r1, 0x26]
	lsls r0, 16
	cmp r0, 0
	bne _0809811C
	ldrh r0, [r1, 0x32]
	adds r0, 0x1
	strh r0, [r1, 0x32]
_0809811C:
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8098108

	thumb_func_start sub_8098124
sub_8098124: @ 8098124
	movs r0, 0x1
	bx lr
	thumb_func_end sub_8098124

	.align 2, 0 @ Don't pad with nop.
