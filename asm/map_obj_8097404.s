	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8097BB4
sub_8097BB4: @ 8097BB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_8097B2C
	adds r1, r0, 0
	cmp r1, 0x40
	beq _08097C3E
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r5, 0
	bl GetFieldObjectGraphicsInfo
	ldrh r3, [r4, 0x4]
	lsls r3, 22
	ldr r1, [r0, 0x10]
	ldr r2, [r1, 0x4]
	ldr r1, [r1]
	str r1, [r4]
	str r2, [r4, 0x4]
	lsrs r3, 22
	ldrh r2, [r4, 0x4]
	ldr r1, =0xfffffc00
	ands r1, r2
	orrs r1, r3
	strh r1, [r4, 0x4]
	ldrb r2, [r0, 0xC]
	lsls r2, 28
	lsrs r2, 24
	ldrb r3, [r4, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r2
	strb r1, [r4, 0x5]
	ldr r1, [r0, 0x1C]
	str r1, [r4, 0xC]
	ldr r1, [r0, 0x14]
	cmp r1, 0
	bne _08097C20
	str r1, [r4, 0x18]
	adds r0, r4, 0
	adds r0, 0x42
	strb r1, [r0]
	b _08097C36
	.pool
_08097C20:
	adds r0, r4, 0
	bl SetSubspriteTables
	adds r2, r4, 0
	adds r2, 0x42
	ldrb r0, [r2]
	movs r1, 0x3F
	ands r1, r0
	movs r0, 0x80
	orrs r1, r0
	strb r1, [r2]
_08097C36:
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAnim
_08097C3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8097BB4

	thumb_func_start sub_8097C44
sub_8097C44: @ 8097C44
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	cmp r2, 0x40
	beq _08097C80
	cmp r4, 0
	beq _08097C74
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x32]
	b _08097C80
	.pool
_08097C74:
	ldr r1, =gSprites
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strh r4, [r0, 0x32]
_08097C80:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097C44

	thumb_func_start sub_8097C8C
sub_8097C8C: @ 8097C8C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	bne _08097CA2
	movs r0, 0
	b _08097CBA
_08097CA2:
	movs r3, 0
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r2, 0x32
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _08097CB8
	movs r3, 0x1
_08097CB8:
	adds r0, r3, 0
_08097CBA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8097C8C

	thumb_func_start sub_8097CC4
sub_8097CC4: @ 8097CC4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08097CEA
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r0, 0
	strh r4, [r1, 0x34]
	strh r0, [r1, 0x36]
_08097CEA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097CC4

	thumb_func_start sub_8097CF4
sub_8097CF4: @ 8097CF4
	push {lr}
	adds r2, r0, 0
	movs r1, 0x36
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _08097D06
	cmp r0, 0x1
	beq _08097D0E
	b _08097D2C
_08097D06:
	strh r0, [r2, 0x26]
	ldrh r0, [r2, 0x36]
	adds r0, 0x1
	strh r0, [r2, 0x36]
_08097D0E:
	ldrh r0, [r2, 0x26]
	subs r0, 0x8
	movs r3, 0
	strh r0, [r2, 0x26]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xA0
	negs r1, r1
	cmp r0, r1
	bne _08097D2C
	strh r3, [r2, 0x26]
	movs r0, 0x1
	strh r0, [r2, 0x32]
	strh r3, [r2, 0x34]
	strh r3, [r2, 0x36]
_08097D2C:
	pop {r0}
	bx r0
	thumb_func_end sub_8097CF4

	thumb_func_start sub_8097D30
sub_8097D30: @ 8097D30
	push {lr}
	adds r1, r0, 0
	movs r2, 0x36
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08097D42
	cmp r0, 0x1
	beq _08097D4C
	b _08097D5E
_08097D42:
	ldr r0, =0x0000ff60
	strh r0, [r1, 0x26]
	ldrh r0, [r1, 0x36]
	adds r0, 0x1
	strh r0, [r1, 0x36]
_08097D4C:
	ldrh r0, [r1, 0x26]
	adds r0, 0x8
	strh r0, [r1, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bne _08097D5E
	strh r0, [r1, 0x34]
	strh r0, [r1, 0x36]
_08097D5E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8097D30

	thumb_func_start sub_8097D68
sub_8097D68: @ 8097D68
	push {lr}
	adds r1, r0, 0
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _08097D84
	cmp r0, 0x1
	bgt _08097D7E
	cmp r0, 0
	beq _08097D98
	b _08097D94
_08097D7E:
	cmp r0, 0x2
	beq _08097D8C
	b _08097D94
_08097D84:
	adds r0, r1, 0
	bl sub_8097D30
	b _08097D98
_08097D8C:
	adds r0, r1, 0
	bl sub_8097CF4
	b _08097D98
_08097D94:
	movs r0, 0
	strh r0, [r1, 0x34]
_08097D98:
	pop {r0}
	bx r0
	thumb_func_end sub_8097D68

	thumb_func_start sub_8097D9C
sub_8097D9C: @ 8097D9C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8097B2C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _08097DC0
	ldr r0, =gSprites
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08097DC8
_08097DC0:
	movs r0, 0
	b _08097DCA
	.pool
_08097DC8:
	movs r0, 0x1
_08097DCA:
	pop {r1}
	bx r1
	thumb_func_end sub_8097D9C

	thumb_func_start oe_exec_and_other_stuff
oe_exec_and_other_stuff: @ 8097DD0
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gFieldEffectArguments
	adds r2, r1, 0x4
	adds r3, r1, 0
	adds r3, 0x8
	bl FieldObjectGetLocalIdAndMap
	adds r0, r4, 0
	bl FieldEffectStart
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oe_exec_and_other_stuff

	thumb_func_start DoShadowFieldEffect
DoShadowFieldEffect: @ 8097DF8
	push {lr}
	adds r1, r0, 0
	ldrb r2, [r1, 0x2]
	lsls r0, r2, 25
	cmp r0, 0
	blt _08097E10
	movs r0, 0x40
	orrs r0, r2
	strb r0, [r1, 0x2]
	movs r0, 0x3
	bl oe_exec_and_other_stuff
_08097E10:
	pop {r0}
	bx r0
	thumb_func_end DoShadowFieldEffect

	thumb_func_start DoRippleFieldEffect
@ void DoRippleFieldEffect(struct npc_state *fieldObject, struct obj *object)
DoRippleFieldEffect: @ 8097E14
	push {r4,lr}
	adds r4, r1, 0
	ldrb r0, [r0, 0x5]
	bl GetFieldObjectGraphicsInfo
	ldr r2, =gFieldEffectArguments
	movs r3, 0x20
	ldrsh r1, [r4, r3]
	str r1, [r2]
	movs r3, 0x22
	ldrsh r1, [r4, r3]
	ldrh r0, [r0, 0xA]
	lsls r0, 16
	asrs r0, 17
	adds r1, r0
	subs r1, 0x2
	str r1, [r2, 0x4]
	movs r0, 0x97
	str r0, [r2, 0x8]
	movs r0, 0x3
	str r0, [r2, 0xC]
	movs r0, 0x5
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoRippleFieldEffect

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
