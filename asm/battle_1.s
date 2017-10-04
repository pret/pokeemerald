	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8034C54
sub_8034C54: @ 8034C54
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02022E10
	ldr r0, [r5]
	cmp r0, 0
	beq _08034C64
	bl sub_8034CC8
_08034C64:
	movs r0, 0x8
	bl Alloc
	str r0, [r5]
	cmp r0, 0
	bne _08034C78
	movs r0, 0
	b _08034CC0
	.pool
_08034C78:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	bl Alloc
	ldr r1, [r5]
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _08034C94
	adds r0, r1, 0
	bl Free
	movs r0, 0
	b _08034CC0
_08034C94:
	str r4, [r1]
	movs r3, 0
	cmp r3, r4
	bcs _08034CBE
	movs r7, 0
	movs r6, 0xFF
	movs r2, 0
_08034CA2:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r2, r0
	strb r7, [r0]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r2, r1
	ldrb r0, [r1, 0x1]
	orrs r0, r6
	strb r0, [r1, 0x1]
	adds r2, 0x1C
	adds r3, 0x1
	cmp r3, r4
	bcc _08034CA2
_08034CBE:
	movs r0, 0x1
_08034CC0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8034C54

	thumb_func_start sub_8034CC8
sub_8034CC8: @ 8034CC8
	push {r4,r5,lr}
	ldr r2, =gUnknown_02022E10
	ldr r1, [r2]
	cmp r1, 0
	beq _08034D08
	ldr r0, [r1, 0x4]
	cmp r0, 0
	beq _08034CFC
	movs r4, 0
	ldr r0, [r1]
	cmp r4, r0
	bcs _08034CF2
	adds r5, r2, 0
_08034CE2:
	adds r0, r4, 0
	bl sub_80353DC
	adds r4, 0x1
	ldr r0, [r5]
	ldr r0, [r0]
	cmp r4, r0
	bcc _08034CE2
_08034CF2:
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl Free
_08034CFC:
	ldr r4, =gUnknown_02022E10
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
_08034D08:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034CC8

	thumb_func_start sub_8034D14
sub_8034D14: @ 8034D14
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	mov r10, r1
	adds r5, r2, 0
	ldr r6, =gUnknown_02022E10
	ldr r0, [r6]
	cmp r0, 0
	beq _08034DD4
	ldr r1, [r0, 0x4]
	mov r0, r8
	lsls r2, r0, 3
	subs r0, r2, r0
	lsls r4, r0, 2
	adds r1, r4, r1
	ldrb r0, [r1]
	mov r9, r2
	cmp r0, 0
	bne _08034DD4
	ldrb r0, [r5, 0x1]
	bl sub_8035518
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	adds r1, r4, r1
	strb r0, [r1, 0x1]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	ldrb r0, [r0, 0x1]
	cmp r0, 0xFF
	beq _08034DD4
	ldr r0, [r5, 0x8]
	ldrh r0, [r0, 0x6]
	bl GetSpriteTileStartByTag
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r1, r4, r1
	strh r0, [r1, 0xA]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldrh r1, [r0, 0xA]
	ldr r7, =0xffff0000
	lsrs r0, r7, 16
	cmp r1, r0
	bne _08034DE0
	ldr r2, [r5, 0x8]
	ldrh r0, [r2, 0x4]
	adds r1, r2, 0
	cmp r0, 0
	beq _08034D94
	adds r0, r1, 0
	bl LoadSpriteSheet
	b _08034DB4
	.pool
_08034D94:
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	bl sub_8034974
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, 0x4]
	mov r0, sp
	bl LoadCompressedObjectPic
_08034DB4:
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	adds r1, r4, r1
	strh r0, [r1, 0xA]
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	mov r2, r9
	mov r3, r8
	subs r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0xA]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08034DE0
_08034DD4:
	movs r0, 0
	b _08034EE8
	.pool
_08034DE0:
	ldr r0, [r5, 0xC]
	ldrh r0, [r0, 0x4]
	bl IndexOfSpritePaletteTag
	ldr r6, =gUnknown_02022E10
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	mov r4, r9
	mov r3, r8
	subs r2, r4, r3
	lsls r4, r2, 2
	adds r1, r4, r1
	strb r0, [r1, 0x4]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	ldrb r0, [r0, 0x4]
	cmp r0, 0xFF
	bne _08034E14
	ldr r0, [r5, 0xC]
	bl LoadSpritePalette
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	adds r1, r4, r1
	strb r0, [r1, 0x4]
_08034E14:
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r1, 0x2]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	ldrb r1, [r5, 0x1]
	strb r1, [r0, 0x3]
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldrh r1, [r5, 0x4]
	strh r1, [r0, 0xC]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldrh r1, [r5, 0x6]
	strh r1, [r0, 0xE]
	ldr r1, [r2, 0x4]
	adds r1, r4, r1
	ldrb r0, [r5]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r1, 0x6]
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r5]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r1, 0x5]
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r5]
	lsrs r0, 6
	strb r0, [r1, 0x7]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	ldrb r1, [r5, 0x2]
	strb r1, [r0, 0x8]
	ldrb r1, [r5]
	lsls r0, r1, 28
	lsrs r0, 30
	lsls r1, 26
	lsrs r1, 30
	bl sub_80355F8
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	adds r1, r4, r1
	strb r0, [r1, 0x9]
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldr r1, [r5, 0x8]
	ldrh r1, [r1, 0x6]
	strh r1, [r0, 0x10]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldr r1, [r5, 0xC]
	ldrh r1, [r1, 0x4]
	strh r1, [r0, 0x12]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	str r1, [r0, 0x14]
	movs r3, 0x1
	ldrb r0, [r5, 0x1]
	cmp r3, r0
	bcs _08034ECA
_08034EB2:
	ldr r0, [r6]
	ldr r2, [r0, 0x4]
	adds r2, r4, r2
	ldr r1, [r2, 0x14]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	str r0, [r2, 0x14]
	adds r3, 0x1
	ldrb r2, [r5, 0x1]
	cmp r3, r2
	bcc _08034EB2
_08034ECA:
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	mov r3, r9
	mov r4, r8
	subs r1, r3, r4
	lsls r1, 2
	ldr r0, [r0, 0x4]
	adds r0, r1
	bl sub_8034EFC
	mov r0, r8
	mov r1, r10
	bl sub_8035044
	movs r0, 0x1
_08034EE8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8034D14

	thumb_func_start sub_8034EFC
sub_8034EFC: @ 8034EFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	ldrb r5, [r4, 0x1]
	movs r0, 0xC
	ldrsh r7, [r4, r0]
	ldrb r0, [r4, 0x3]
	adds r0, 0x1
	mov r8, r0
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	lsls r1, r5, 3
	ldr r2, =gUnknown_030022F8
	mov r9, r2
	add r1, r9
	mov r0, r8
	lsls r2, r0, 2
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	bl CpuSet
	movs r6, 0
	ldrb r5, [r4, 0x1]
	cmp r6, r8
	bcs _08034FCE
	movs r1, 0x3F
	mov r10, r1
	movs r2, 0xD
	negs r2, r2
	mov r9, r2
_08034F46:
	lsls r0, r5, 3
	ldr r1, =gMain
	adds r3, r0, r1
	ldrh r1, [r4, 0xE]
	adds r0, r3, 0
	adds r0, 0x38
	strb r1, [r0]
	ldr r2, =0x000001ff
	adds r0, r2, 0
	adds r1, r7, 0
	ands r1, r0
	ldrh r2, [r3, 0x3A]
	ldr r0, =0xfffffe00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x3A]
	ldrb r1, [r4, 0x6]
	movs r0, 0x39
	adds r0, r3
	mov r12, r0
	lsls r1, 6
	ldrb r2, [r0]
	mov r0, r10
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrb r1, [r4, 0x5]
	movs r2, 0x3B
	adds r2, r3
	mov r12, r2
	lsls r1, 6
	ldrb r2, [r2]
	mov r0, r10
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	ldrh r0, [r4, 0xA]
	ldr r1, =0x000003ff
	ands r1, r0
	ldrh r2, [r3, 0x3C]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x3C]
	adds r3, 0x3D
	movs r0, 0x3
	ldrb r1, [r4, 0x7]
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r3]
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r2, [r4, 0x4]
	lsls r2, 4
	movs r1, 0xF
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r0, [r4, 0x8]
	adds r7, r0
	adds r6, 0x1
	adds r5, 0x1
	cmp r6, r8
	bcc _08034F46
_08034FCE:
	subs r5, 0x1
	ldr r0, =gMain
	lsls r3, r5, 3
	adds r3, r0
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	ldrb r0, [r4, 0x8]
	subs r1, r0
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x3A]
	ldr r0, =0xfffffe00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x3A]
	adds r2, r3, 0
	adds r2, 0x39
	ldrb r1, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, 0x9]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	ldrh r4, [r4, 0xA]
	adds r1, r4
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x3C]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x3C]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8034EFC

	thumb_func_start sub_8035044
sub_8035044: @ 8035044
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldr r0, =gUnknown_02022E10
	ldr r1, [r0]
	adds r6, r0, 0
	cmp r1, 0
	beq _080350A8
	ldr r2, [r1, 0x4]
	lsls r1, r3, 3
	subs r0, r1, r3
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2]
	adds r5, r1, 0
	cmp r0, 0
	beq _080350A8
	str r4, [r2, 0x18]
	cmp r4, 0
	bge _08035078
	movs r2, 0x1
	negs r4, r4
	b _0803507A
	.pool
_08035078:
	movs r2, 0
_0803507A:
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	subs r0, r5, r3
	lsls r0, 2
	adds r0, r1
	ldrb r3, [r0, 0x2]
	cmp r3, 0x1
	beq _0803509A
	cmp r3, 0x1
	ble _08035092
	cmp r3, 0x2
	beq _080350A2
_08035092:
	adds r1, r4, 0
	bl sub_80350B0
	b _080350A8
_0803509A:
	adds r1, r4, 0
	bl sub_8035164
	b _080350A8
_080350A2:
	adds r1, r4, 0
	bl sub_80352C0
_080350A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8035044

	thumb_func_start sub_80350B0
sub_80350B0: @ 80350B0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	mov r9, r1
	str r2, [sp]
	ldr r5, [r0, 0x14]
	ldrb r7, [r0, 0x1]
	ldr r0, =gMain
	mov r10, r0
	cmp r5, 0
	beq _0803511A
	lsls r0, r7, 3
	adds r0, 0x3C
	mov r1, r10
	adds r6, r0, r1
_080350D6:
	mov r0, r9
	adds r1, r5, 0
	bl __udivsi3
	adds r4, r0, 0
	adds r0, r4, 0
	muls r0, r5
	mov r2, r9
	subs r2, r0
	mov r9, r2
	adds r0, r5, 0
	movs r1, 0xA
	bl __udivsi3
	adds r5, r0, 0
	mov r1, r8
	ldrb r0, [r1, 0x9]
	adds r1, r4, 0
	muls r1, r0
	mov r2, r8
	ldrh r2, [r2, 0xA]
	adds r1, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r0, [r6]
	ldr r2, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6]
	adds r6, 0x8
	adds r7, 0x1
	cmp r5, 0
	bne _080350D6
_0803511A:
	ldr r0, [sp]
	cmp r0, 0
	beq _08035140
	lsls r0, r7, 3
	add r0, r10
	adds r0, 0x39
	ldrb r2, [r0]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	b _08035154
	.pool
_08035140:
	lsls r2, r7, 3
	add r2, r10
	adds r2, 0x39
	ldrb r1, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
_08035154:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80350B0

	thumb_func_start sub_8035164
sub_8035164: @ 8035164
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	str r2, [sp]
	ldr r5, [r6, 0x14]
	ldr r3, =gUnknown_03000DD4
	ldrb r0, [r6, 0x1]
	str r0, [r3]
	ldr r2, =gUnknown_03000DD8
	movs r0, 0
	str r0, [r2]
	ldr r1, =gUnknown_03000DDC
	subs r0, 0x1
	str r0, [r1]
	adds r7, r3, 0
	mov r10, r1
	ldr r0, =gMain
	mov r9, r0
	cmp r5, 0
	beq _0803524C
_08035196:
	mov r0, r8
	adds r1, r5, 0
	bl __udivsi3
	adds r4, r0, 0
	adds r0, r4, 0
	muls r0, r5
	mov r1, r8
	subs r1, r0
	mov r8, r1
	adds r0, r5, 0
	movs r1, 0xA
	bl __udivsi3
	adds r5, r0, 0
	cmp r4, 0
	bne _080351C8
	mov r2, r10
	ldr r1, [r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080351C8
	cmp r5, 0
	bne _08035224
_080351C8:
	ldr r2, [r7]
	lsls r2, 3
	add r2, r9
	ldrb r0, [r6, 0x9]
	adds r3, r4, 0
	muls r3, r0
	ldrh r4, [r6, 0xA]
	adds r3, r4
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r3, r0
	ldrh r0, [r2, 0x3C]
	ldr r4, =0xfffffc00
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r3
	strh r0, [r2, 0x3C]
	adds r2, 0x39
	ldrb r0, [r2]
	movs r1, 0x4
	negs r1, r1
	ands r0, r1
	strb r0, [r2]
	mov r2, r10
	ldr r1, [r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0803523A
	ldr r4, =gUnknown_03000DD8
	ldr r0, [r4]
	str r0, [r2]
	b _0803523A
	.pool
_08035224:
	ldr r0, [r7]
	lsls r0, 3
	add r0, r9
	adds r0, 0x39
	ldrb r1, [r0]
	movs r2, 0x4
	negs r2, r2
	ands r1, r2
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_0803523A:
	ldr r0, [r7]
	adds r0, 0x1
	str r0, [r7]
	ldr r4, =gUnknown_03000DD8
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	cmp r5, 0
	bne _08035196
_0803524C:
	ldr r0, [sp]
	cmp r0, 0
	beq _08035298
	ldr r1, [r7]
	lsls r1, 3
	add r1, r9
	adds r1, 0x39
	ldrb r2, [r1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r3, [r7]
	lsls r3, 3
	add r3, r9
	movs r1, 0xC
	ldrsh r2, [r6, r1]
	mov r4, r10
	ldr r0, [r4]
	subs r0, 0x1
	ldrb r1, [r6, 0x8]
	muls r0, r1
	adds r2, r0
	ldr r1, =0x000001ff
	adds r0, r1, 0
	ands r2, r0
	ldrh r1, [r3, 0x3A]
	ldr r0, =0xfffffe00
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x3A]
	b _080352AE
	.pool
_08035298:
	ldr r0, [r7]
	lsls r0, 3
	add r0, r9
	adds r0, 0x39
	ldrb r2, [r0]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_080352AE:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8035164

	thumb_func_start sub_80352C0
sub_80352C0: @ 80352C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	mov r10, r1
	str r2, [sp]
	ldr r5, [r0, 0x14]
	ldrb r3, [r0, 0x1]
	movs r0, 0
	str r0, [sp, 0x4]
	mov r9, r0
	cmp r5, 0
	beq _0803535A
_080352E0:
	lsls r0, r3, 3
	adds r1, r0, 0
	adds r1, 0x39
	ldr r2, =gMain
	adds r7, r1, r2
	adds r0, 0x3C
	adds r6, r0, r2
_080352EE:
	mov r0, r10
	adds r1, r5, 0
	str r3, [sp, 0x8]
	bl __udivsi3
	adds r4, r0, 0
	adds r0, r4, 0
	muls r0, r5
	mov r1, r10
	subs r1, r0
	mov r10, r1
	adds r0, r5, 0
	movs r1, 0xA
	bl __udivsi3
	adds r5, r0, 0
	ldr r3, [sp, 0x8]
	cmp r4, 0
	bne _0803531E
	ldr r2, [sp, 0x4]
	cmp r2, 0
	bne _0803531E
	cmp r5, 0
	bne _080352E0
_0803531E:
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r1, r8
	ldrb r0, [r1, 0x9]
	adds r2, r4, 0
	muls r2, r0
	ldrh r4, [r1, 0xA]
	adds r2, r4
	ldr r1, =0x000003ff
	adds r0, r1, 0
	ands r2, r0
	ldrh r0, [r6]
	ldr r4, =0xfffffc00
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r6]
	ldrb r0, [r7]
	movs r2, 0x4
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	strb r0, [r7]
	adds r7, 0x8
	adds r6, 0x8
	adds r3, 0x1
	movs r4, 0x1
	add r9, r4
	cmp r5, 0
	bne _080352EE
_0803535A:
	mov r0, r8
	ldrb r0, [r0, 0x3]
	cmp r9, r0
	bge _0803538A
	ldr r1, =gMain
	movs r5, 0x4
	negs r5, r5
	movs r4, 0x2
	lsls r0, r3, 3
	adds r0, 0x39
	adds r2, r0, r1
_08035370:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	orrs r0, r4
	strb r0, [r2]
	adds r2, 0x8
	adds r3, 0x1
	movs r1, 0x1
	add r9, r1
	mov r0, r8
	ldrb r0, [r0, 0x3]
	cmp r9, r0
	blt _08035370
_0803538A:
	ldr r1, [sp]
	cmp r1, 0
	beq _080353B0
	lsls r0, r3, 3
	ldr r2, =gMain
	adds r0, r2
	adds r0, 0x39
	ldrb r2, [r0]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	b _080353C6
	.pool
_080353B0:
	lsls r2, r3, 3
	ldr r4, =gMain
	adds r2, r4
	adds r2, 0x39
	ldrb r1, [r2]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
_080353C6:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80352C0

	thumb_func_start sub_80353DC
sub_80353DC: @ 80353DC
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	cmp r0, 0
	beq _0803546E
	ldr r2, [r0, 0x4]
	lsls r1, r4, 3
	subs r0, r1, r4
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2]
	adds r5, r1, 0
	cmp r0, 0
	beq _0803546E
	ldrb r3, [r2, 0x3]
	adds r0, r3, 0x1
	ldrb r2, [r2, 0x1]
	cmp r0, 0
	beq _08035426
	ldr r1, =gMain
	movs r7, 0x4
	negs r7, r7
	movs r6, 0x2
	adds r3, r0, 0
	lsls r0, r2, 3
	adds r0, 0x39
	adds r2, r0, r1
_08035414:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	orrs r0, r6
	strb r0, [r2]
	subs r3, 0x1
	adds r2, 0x8
	cmp r3, 0
	bne _08035414
_08035426:
	adds r0, r4, 0
	bl sub_8035570
	cmp r0, 0
	bne _08035442
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r5, r4
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x10]
	bl FreeSpriteTilesByTag
_08035442:
	adds r0, r4, 0
	bl sub_80355B4
	cmp r0, 0
	bne _0803545E
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r5, r4
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x12]
	bl FreeSpritePaletteByTag
_0803545E:
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r5, r4
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_0803546E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80353DC

	thumb_func_start sub_803547C
sub_803547C: @ 803547C
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, =gUnknown_02022E10
	ldr r1, [r0]
	adds r7, r0, 0
	cmp r1, 0
	beq _0803550C
	ldr r2, [r1, 0x4]
	lsls r1, r4, 3
	subs r0, r1, r4
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2]
	adds r6, r1, 0
	cmp r0, 0
	beq _0803550C
	ldrb r3, [r2, 0x3]
	adds r1, r3, 0x1
	ldrb r0, [r2, 0x1]
	cmp r5, 0
	beq _080354D8
	cmp r1, 0
	beq _0803550C
	ldr r1, =gMain
	movs r5, 0x4
	negs r5, r5
	movs r4, 0x2
	adds r3, 0x1
	lsls r0, 3
	adds r0, 0x39
	adds r2, r0, r1
_080354BC:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	orrs r0, r4
	strb r0, [r2]
	subs r3, 0x1
	adds r2, 0x8
	cmp r3, 0
	bne _080354BC
	b _0803550C
	.pool
_080354D8:
	cmp r1, 0
	beq _080354FA
	ldr r1, =gMain
	movs r5, 0x4
	negs r5, r5
	adds r3, 0x1
	lsls r0, 3
	adds r0, 0x39
	adds r2, r0, r1
_080354EA:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
	subs r3, 0x1
	adds r2, 0x8
	cmp r3, 0
	bne _080354EA
_080354FA:
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	subs r0, r6, r4
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	bl sub_8035044
_0803550C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803547C

	thumb_func_start sub_8035518
sub_8035518: @ 8035518
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0x40
	movs r3, 0
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r2, [r0]
	cmp r3, r2
	bcs _0803555A
	ldr r1, [r0, 0x4]
_0803552E:
	ldrb r0, [r1]
	cmp r0, 0
	bne _08035548
	ldrb r0, [r1, 0x1]
	cmp r0, 0xFF
	beq _08035552
	ldrb r0, [r1, 0x3]
	cmp r0, r4
	bhi _08035552
	ldrb r0, [r1, 0x1]
	b _0803556A
	.pool
_08035548:
	adds r0, r5, 0x1
	ldrb r5, [r1, 0x3]
	adds r0, r5
	lsls r0, 16
	lsrs r5, r0, 16
_08035552:
	adds r1, 0x1C
	adds r3, 0x1
	cmp r3, r2
	bcc _0803552E
_0803555A:
	adds r0, r5, r4
	adds r0, 0x1
	cmp r0, 0x80
	bgt _08035568
	lsls r0, r5, 24
	lsrs r0, 24
	b _0803556A
_08035568:
	movs r0, 0xFF
_0803556A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8035518

	thumb_func_start sub_8035570
sub_8035570: @ 8035570
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r4, [r0]
	cmp r2, r4
	bcs _080355AC
	ldr r1, [r0, 0x4]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r5, r0, r1
_0803558A:
	ldrb r0, [r1]
	cmp r0, 0
	beq _080355A4
	cmp r2, r3
	beq _080355A4
	ldrh r0, [r1, 0x10]
	ldrh r6, [r5, 0x10]
	cmp r0, r6
	bne _080355A4
	movs r0, 0x1
	b _080355AE
	.pool
_080355A4:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, r4
	bcc _0803558A
_080355AC:
	movs r0, 0
_080355AE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8035570

	thumb_func_start sub_80355B4
sub_80355B4: @ 80355B4
	push {r4-r6,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, =gUnknown_02022E10
	ldr r0, [r0]
	ldr r4, [r0]
	cmp r2, r4
	bcs _080355F0
	ldr r1, [r0, 0x4]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r5, r0, r1
_080355CE:
	ldrb r0, [r1]
	cmp r0, 0
	beq _080355E8
	cmp r2, r3
	beq _080355E8
	ldrh r0, [r1, 0x12]
	ldrh r6, [r5, 0x12]
	cmp r0, r6
	bne _080355E8
	movs r0, 0x1
	b _080355F2
	.pool
_080355E8:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, r4
	bcc _080355CE
_080355F0:
	movs r0, 0
_080355F2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80355B4

	thumb_func_start sub_80355F8
sub_80355F8: @ 80355F8
	ldr r2, =gUnknown_082FF1C8
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80355F8

	thumb_func_start sub_8035608
sub_8035608: @ 8035608
	push {lr}
	bl ResetSpriteData
	ldr r0, =gUnknown_0831AC88
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =sub_8035648
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8035608

	thumb_func_start sub_8035648
sub_8035648: @ 8035648
	push {lr}
	bl AnimateSprites
	bl BuildOamBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8035648

	thumb_func_start trs_config
trs_config: @ 8035658
	push {r4,lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0831AA08
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 11
	ands r1, r0
	cmp r1, 0
	beq _080356A4
	ldr r0, =gBattleScripting
	adds r0, 0x24
	movs r1, 0x1
	strb r1, [r0]
	ldr r4, =gUnknown_02023060
	ldr r1, [r4]
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, 0x2
	bl SetBgTilemapBuffer
	b _080356AA
	.pool
_080356A4:
	ldr r0, =gBattleScripting
	adds r0, 0x24
	strb r1, [r0]
_080356AA:
	ldr r1, =gUnknown_0831ABA0
	ldr r0, =gBattleScripting
	adds r0, 0x24
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl InitWindows
	bl DeactivateAllTextPrinters
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end trs_config

	thumb_func_start c2_berry_program_update_menu
c2_berry_program_update_menu: @ 80356D0
	push {lr}
	movs r0, 0x2
	bl DisableInterrupts
	movs r0, 0xC5
	bl EnableInterrupts
	bl trs_config
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r1, =0x0000b040
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_berry_program_update_menu

	thumb_func_start sub_803570C
sub_803570C: @ 803570C
	push {lr}
	movs r0, 0x2
	movs r1, 0x12
	movs r2, 0x10
	bl sub_809882C
	movs r0, 0x2
	movs r1, 0x22
	movs r2, 0x10
	bl sub_809882C
	ldr r0, =gUnknown_08D85600
	movs r1, 0x50
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0803575A
	movs r0, 0x70
	bl sub_81978B0
	movs r0, 0
	movs r1, 0x30
	movs r2, 0x70
	bl copy_textbox_border_tile_patterns_to_vram
	ldr r0, =gPlttBufferUnfaded
	adds r0, 0xEC
	movs r1, 0
	strh r1, [r0]
	ldr r1, =gPlttBufferFaded + 0xEC
	movs r2, 0x1
	bl CpuSet
_0803575A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803570C

	thumb_func_start load_battle_oval_graphics
load_battle_oval_graphics: @ 8035770
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x023f0902
	ands r0, r1
	cmp r0, 0
	beq _080357B0
	ldr r0, =gUnknown_08D7C440
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7CA28
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7C9EC
	b _08035A52
	.pool
_080357B0:
	movs r0, 0x80
	lsls r0, 21
	ands r0, r1
	cmp r0, 0
	beq _080357E4
	ldr r0, =gUnknown_08D7BB14
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7C154
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7DF30
	b _08035A52
	.pool
_080357E4:
	movs r0, 0x80
	lsls r0, 22
	ands r0, r1
	cmp r0, 0
	beq _08035818
	ldr r0, =gUnknown_08D7A108
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7A720
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7DEF4
	b _08035A52
	.pool
_08035818:
	movs r0, 0x80
	lsls r0, 23
	ands r0, r1
	cmp r0, 0
	beq _0803584C
	ldr r0, =gUnknown_08D7D590
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7DC04
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E234
	b _08035A52
	.pool
_0803584C:
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _080358C4
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x20
	bne _08035898
	ldr r0, =gUnknown_08D7C440
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7CA28
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7DFC4
	b _08035A52
	.pool
_08035898:
	cmp r0, 0x26
	bne _080358C4
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E1F8
	b _08035A52
	.pool
_080358C4:
	bl sav1_map_get_battletype
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bhi _08035904
	lsls r0, 2
	ldr r1, =_080358E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080358E0:
	.4byte _08035904
	.4byte _08035950
	.4byte _08035978
	.4byte _080359A0
	.4byte _080359C8
	.4byte _080359F0
	.4byte _08035A18
	.4byte _08035A40
	.4byte _08035A70
_08035904:
	ldr r4, =gBattleTerrainTable
	ldr r5, =gBattleTerrain
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r4, 0x10
	adds r0, r4
	ldr r0, [r0]
	b _08035A52
	.pool
_08035950:
	ldr r0, =gUnknown_08D7C440
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7CA28
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7DF88
	b _08035A52
	.pool
_08035978:
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E060
	b _08035A52
	.pool
_080359A0:
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E000
	b _08035A52
	.pool
_080359C8:
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E0CC
	b _08035A52
	.pool
_080359F0:
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E11C
	b _08035A52
	.pool
_08035A18:
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E164
	b _08035A52
	.pool
_08035A40:
	ldr r0, =gUnknown_08D7CCD8
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7D2E0
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7E1A8
_08035A52:
	movs r1, 0x20
	movs r2, 0x60
	bl LoadCompressedPalette
	b _08035A8A
	.pool
_08035A70:
	ldr r0, =gUnknown_08D7C440
	ldr r1, =0x06008000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7CA28
	ldr r1, =0x0600d000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7C9EC
	movs r1, 0x20
	movs r2, 0x60
	bl LoadCompressedPalette
_08035A8A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end load_battle_oval_graphics

	thumb_func_start sub_8035AA4
sub_8035AA4: @ 8035AA4
	push {lr}
	ldr r0, =gUnknown_08C00000
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	ldr r1, =gUnknown_08C00524
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_08C004E0
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	bl sub_803570C
	bl load_battle_oval_graphics
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8035AA4

	thumb_func_start sub_8035AE4
sub_8035AE4: @ 8035AE4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	ldr r4, [sp, 0x34]
	lsls r0, 24
	lsrs r6, r0, 24
	adds r7, r6, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r3, 24
	mov r12, r3
	lsls r4, 24
	lsrs r4, 24
	mov r9, r4
	movs r4, 0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08035BCC
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r2, 0x12
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08035B56
	cmp r5, 0x1
	beq _08035B7E
	cmp r5, 0x1
	bgt _08035B44
	cmp r5, 0
	beq _08035B4E
	b _08035B88
	.pool
_08035B44:
	cmp r5, 0x2
	beq _08035B52
	cmp r5, 0x3
	beq _08035B72
	b _08035B88
_08035B4E:
	ldrh r0, [r1, 0xE]
	b _08035B74
_08035B52:
	ldrh r1, [r1, 0xE]
	b _08035B80
_08035B56:
	cmp r5, 0x1
	beq _08035B72
	cmp r5, 0x1
	bgt _08035B64
	cmp r5, 0
	beq _08035B6E
	b _08035B88
_08035B64:
	cmp r5, 0x2
	beq _08035B7A
	cmp r5, 0x3
	beq _08035B7E
	b _08035B88
_08035B6E:
	ldrh r0, [r1, 0xE]
	b _08035B74
_08035B72:
	ldrh r0, [r1, 0x10]
_08035B74:
	movs r4, 0x3F
	ands r4, r0
	b _08035B88
_08035B7A:
	ldrh r1, [r1, 0xE]
	b _08035B80
_08035B7E:
	ldrh r1, [r1, 0x10]
_08035B80:
	movs r0, 0xFC
	lsls r0, 4
	ands r0, r1
	lsrs r4, r0, 6
_08035B88:
	movs r2, 0
	movs r6, 0x3
	ldr r0, =0x00006001
	adds r5, r0, 0
	add r3, sp, 0xC
_08035B92:
	lsls r1, r2, 1
	adds r0, r6, 0
	lsls r0, r1
	ands r0, r4
	asrs r0, r1
	adds r0, r5
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x1
	cmp r2, 0x2
	ble _08035B92
	movs r0, 0x3
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	mov r0, r8
	add r1, sp, 0xC
	mov r2, r12
	mov r3, r9
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r0, r8
	bl CopyBgTilemapBufferToVram
	b _08035C36
	.pool
_08035BCC:
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r0, [r0]
	cmp r5, r0
	bne _08035BEC
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldrh r4, [r0, 0xE]
	b _08035BF8
	.pool
_08035BEC:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrh r4, [r0, 0x10]
_08035BF8:
	movs r2, 0
	movs r6, 0x3
	ldr r0, =0x00006001
	adds r5, r0, 0
	add r3, sp, 0xC
_08035C02:
	lsls r1, r2, 1
	adds r0, r6, 0
	lsls r0, r1
	ands r0, r4
	asrs r0, r1
	adds r0, r5
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x1
	cmp r2, 0x5
	ble _08035C02
	movs r0, 0x6
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	mov r0, r8
	add r1, sp, 0xC
	mov r2, r12
	mov r3, r9
	bl CopyToBgTilemapBufferRect_ChangePalette
	mov r0, r8
	bl CopyBgTilemapBufferToVram
_08035C36:
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8035AE4

	thumb_func_start sub_8035C4C
sub_8035C4C: @ 8035C4C
	push {lr}
	ldr r0, =gBattleOutcome
	ldrb r2, [r0]
	cmp r2, 0x3
	bne _08035C68
	ldr r0, =gText_Draw
	movs r1, 0x15
	bl sub_814F9EC
	b _08035D68
	.pool
_08035C68:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08035CE2
	cmp r2, 0x1
	bne _08035CAE
	ldr r2, =gLinkPlayers
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x1
	beq _08035CFC
	cmp r0, 0x1
	bgt _08035CA4
	cmp r0, 0
	beq _08035D36
	b _08035D68
	.pool
_08035CA4:
	cmp r0, 0x2
	beq _08035D36
	cmp r0, 0x3
	bne _08035D68
	b _08035CFC
_08035CAE:
	ldr r2, =gLinkPlayers
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x1
	beq _08035D36
	cmp r0, 0x1
	bgt _08035CD8
	cmp r0, 0
	beq _08035CFC
	b _08035D68
	.pool
_08035CD8:
	cmp r0, 0x2
	beq _08035CFC
	cmp r0, 0x3
	bne _08035D68
	b _08035D36
_08035CE2:
	cmp r2, 0x1
	bne _08035D20
	ldr r2, =gLinkPlayers
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0
	beq _08035D36
_08035CFC:
	ldr r0, =gText_Win
	movs r1, 0x17
	bl sub_814F9EC
	ldr r0, =gText_Loss
	movs r1, 0x16
	bl sub_814F9EC
	b _08035D68
	.pool
_08035D20:
	ldr r2, =gLinkPlayers
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0
	beq _08035D58
_08035D36:
	ldr r0, =gText_Win
	movs r1, 0x16
	bl sub_814F9EC
	ldr r0, =gText_Loss
	movs r1, 0x17
	bl sub_814F9EC
	b _08035D68
	.pool
_08035D58:
	ldr r0, =gText_Win
	movs r1, 0x17
	bl sub_814F9EC
	ldr r0, =gText_Loss
	movs r1, 0x16
	bl sub_814F9EC
_08035D68:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8035C4C

	thumb_func_start task00_0800F6FC
task00_0800F6FC: @ 8035D74
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	mov r8, r0
	adds r0, r7
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08035D96
	b _08035EC4
_08035D96:
	cmp r0, 0x1
	bgt _08035DA4
	cmp r0, 0
	beq _08035DAC
	b _08036138
	.pool
_08035DA4:
	cmp r0, 0x2
	bne _08035DAA
	b _08035F64
_08035DAA:
	b _08036138
_08035DAC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08035E44
	movs r5, 0
	movs r6, 0x3
_08035DBC:
	ldr r0, =gLinkPlayers + 8
	adds r1, r5, r0
	subs r0, 0x8
	adds r4, r5, r0
	ldrh r0, [r4, 0x18]
	cmp r0, 0x1
	beq _08035DF4
	cmp r0, 0x1
	bgt _08035DDC
	cmp r0, 0
	beq _08035DE6
	b _08035E3A
	.pool
_08035DDC:
	cmp r0, 0x2
	beq _08035E08
	cmp r0, 0x3
	beq _08035E22
	b _08035E3A
_08035DE6:
	adds r0, r1, 0
	movs r1, 0x11
	bl sub_814F9EC
	ldrb r1, [r4, 0x18]
	movs r0, 0x4
	b _08035E14
_08035DF4:
	adds r0, r1, 0
	movs r1, 0x12
	bl sub_814F9EC
	ldrb r1, [r4, 0x18]
	movs r0, 0x4
	str r0, [sp]
	adds r0, r7, 0
	movs r2, 0x2
	b _08035E1A
_08035E08:
	adds r0, r1, 0
	movs r1, 0x13
	bl sub_814F9EC
	ldrb r1, [r4, 0x18]
	movs r0, 0x8
_08035E14:
	str r0, [sp]
	adds r0, r7, 0
	movs r2, 0x1
_08035E1A:
	movs r3, 0x2
	bl sub_8035AE4
	b _08035E3A
_08035E22:
	adds r0, r1, 0
	movs r1, 0x14
	bl sub_814F9EC
	ldrb r1, [r4, 0x18]
	movs r0, 0x8
	str r0, [sp]
	adds r0, r7, 0
	movs r2, 0x2
	movs r3, 0x2
	bl sub_8035AE4
_08035E3A:
	adds r5, 0x1C
	subs r6, 0x1
	cmp r6, 0
	bge _08035DBC
	b _08035EA6
_08035E44:
	ldr r0, =gBattleScripting
	adds r0, 0x25
	ldrb r5, [r0]
	movs r0, 0x1
	adds r6, r5, 0
	eors r6, r0
	adds r1, r6, 0
	ldr r4, =gLinkPlayers
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x18]
	cmp r0, 0
	beq _08035E66
	adds r6, r5, 0
	adds r5, r1, 0
_08035E66:
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r4, 0x8
	adds r1, r0, r4
	adds r0, r1, 0
	movs r1, 0xF
	bl sub_814F9EC
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 2
	adds r1, r0, r4
	adds r0, r1, 0
	movs r1, 0x10
	bl sub_814F9EC
	movs r4, 0x7
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x2
	bl sub_8035AE4
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl sub_8035AE4
_08035EA6:
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08036138
	.pool
_08035EC4:
	ldr r0, =0x00002710
	bl AllocSpritePalette
	lsls r0, 24
	ldr r2, =gPlttBufferUnfaded
	lsrs r0, 19
	ldr r3, =0x0000021e
	adds r0, r3
	adds r2, r0, r2
	ldr r1, =gPlttBufferFaded
	adds r0, r1
	ldr r1, =0x00007fff
	strh r1, [r0]
	strh r1, [r2]
	ldr r0, =gUnknown_0831A9D0
	movs r1, 0x6F
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r4, =gBattleStruct
	ldr r1, [r4]
	adds r1, 0x7D
	strb r0, [r1]
	ldr r0, =gUnknown_0831A9E8
	movs r1, 0x81
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, 0x7E
	strb r0, [r1]
	ldr r3, =gSprites
	ldr r0, [r4]
	adds r0, 0x7D
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x7E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _08036138
	.pool
_08035F64:
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08035FCC
	ldr r4, =gBattle_BG1_X
	ldrh r0, [r5, 0xA]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08035F7E
	adds r0, 0x1F
_08035F7E:
	asrs r1, r0, 5
	movs r2, 0x14
	negs r2, r2
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gBattle_BG2_X
	ldrh r0, [r5, 0xC]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08035F9C
	adds r0, 0x1F
_08035F9C:
	asrs r1, r0, 5
	movs r3, 0x8C
	negs r3, r3
	adds r0, r3, 0
	subs r0, r1
	strh r0, [r4]
	ldr r0, =gBattle_BG1_Y
	ldr r2, =0x0000ffdc
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	b _08036038
	.pool
_08035FCC:
	ldr r4, =gBattle_BG1_X
	ldrh r0, [r5, 0xA]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08035FDE
	adds r0, 0x1F
_08035FDE:
	asrs r1, r0, 5
	movs r3, 0x14
	negs r3, r3
	adds r0, r3, 0
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gBattle_BG1_Y
	ldrh r0, [r5, 0xA]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08035FFC
	adds r0, 0x1F
_08035FFC:
	asrs r0, 5
	subs r0, 0xA4
	strh r0, [r4]
	ldr r4, =gBattle_BG2_X
	ldrh r0, [r5, 0xC]
	bl Sin2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08036014
	adds r0, 0x1F
_08036014:
	asrs r1, r0, 5
	movs r2, 0x8C
	negs r2, r2
	adds r0, r2, 0
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gBattle_BG2_Y
	ldrh r0, [r5, 0xC]
	bl Cos2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _08036032
	adds r0, 0x1F
_08036032:
	asrs r0, 5
	subs r0, 0xA4
	strh r0, [r4]
_08036038:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0xC]
	movs r2, 0xC
	ldrsh r3, [r1, r2]
	mov r8, r3
	cmp r3, 0
	beq _08036070
	subs r0, 0x2
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0xA]
	adds r0, 0x2
	strh r0, [r1, 0xA]
	b _08036138
	.pool
_08036070:
	movs r3, 0x12
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0803607C
	bl sub_8035C4C
_0803607C:
	movs r0, 0x78
	bl PlaySE
	adds r0, r7, 0
	bl DestroyTask
	ldr r4, =gSprites
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, 0x7D
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, 0x7E
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	ldr r5, [r5]
	adds r6, r5, 0
	adds r6, 0x7E
	ldrb r0, [r6]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x40
	ldr r7, =0x000003ff
	adds r0, r7, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
	adds r5, 0x7D
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r8
	strh r1, [r0, 0x2E]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x20]
	strh r1, [r0, 0x30]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x20]
	strh r1, [r0, 0x30]
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r2, r8
	strh r2, [r0, 0x32]
	ldrb r1, [r6]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x32]
_08036138:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_0800F6FC

	thumb_func_start sub_8036154
sub_8036154: @ 8036154
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08036208
	ldr r0, =gUnknown_08D778F0
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D77B0C
	ldr r1, =0x06010000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D77AE4
	movs r1, 0x60
	movs r2, 0x20
	bl LoadCompressedPalette
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl SetBgAttribute
	ldr r1, =0x00005c04
	movs r0, 0xA
	bl SetGpuReg
	ldr r4, =gUnknown_08D779D8
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x2
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	movs r0, 0x48
	movs r1, 0x36
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x36
	bl SetGpuReg
	ldr r0, =gBattle_BG1_Y
	ldr r2, =0x0000ff5c
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG2_Y
	strh r1, [r0]
	ldr r0, =gUnknown_0831AA00
	bl LoadCompressedObjectPicUsingHeap
	b _080363AC
	.pool
_08036208:
	ldr r0, =0x023f0902
	ands r0, r1
	cmp r0, 0
	beq _0803628C
	movs r0, 0x80
	lsls r0, 15
	ands r1, r0
	cmp r1, 0
	beq _08036224
	ldr r0, =gPartnerTrainerId
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _08036248
_08036224:
	ldr r0, =gUnknown_08D820D4
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D824E4
	b _08036382
	.pool
_08036248:
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x1
	movs r2, 0x2
	bl SetBgAttribute
	ldr r1, =gUnknown_08D857A8
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gUnknown_08D85A1C
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _080363AC
	.pool
_0803628C:
	movs r0, 0x80
	lsls r0, 21
	ands r0, r1
	cmp r0, 0
	beq _080362B0
	ldr r0, =gUnknown_08D81610
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D81E2C
	b _08036382
	.pool
_080362B0:
	movs r0, 0x80
	lsls r0, 22
	ands r0, r1
	cmp r0, 0
	beq _080362D4
	ldr r0, =gUnknown_08D7F9F8
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D7FEC4
	b _08036382
	.pool
_080362D4:
	movs r0, 0x80
	lsls r0, 23
	ands r0, r1
	cmp r0, 0
	beq _080362F8
	ldr r0, =gUnknown_08D82608
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D82C70
	b _08036382
	.pool
_080362F8:
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _08036350
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x20
	bne _08036334
	ldr r0, =gUnknown_08D820D4
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D824E4
	b _08036382
	.pool
_08036334:
	cmp r0, 0x26
	bne _08036350
	ldr r0, =gUnknown_08D820D4
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D824E4
	b _08036382
	.pool
_08036350:
	bl sav1_map_get_battletype
	lsls r0, 24
	cmp r0, 0
	bne _0803639C
	ldr r4, =gBattleTerrainTable
	ldr r5, =gBattleTerrain
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r4, 0xC
	adds r0, r4
	ldr r0, [r0]
_08036382:
	ldr r1, =0x0600e000
	bl LZDecompressVram
	b _080363AC
	.pool
_0803639C:
	ldr r0, =gUnknown_08D820D4
	ldr r1, =0x06004000
	bl LZDecompressVram
	ldr r0, =gUnknown_08D824E4
	ldr r1, =0x0600e000
	bl LZDecompressVram
_080363AC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8036154

	thumb_func_start sub_80363C4
sub_80363C4: @ 80363C4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0
	cmp r0, 0x6
	bls _080363D2
	b _08036756
_080363D2:
	lsls r0, 2
	ldr r1, =_080363E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080363E0:
	.4byte _080363FC
	.4byte _0803640C
	.4byte _08036424
	.4byte _08036434
	.4byte _0803652C
	.4byte _08036638
	.4byte _08036750
_080363FC:
	ldr r0, =gUnknown_08C00000
	movs r1, 0xC0
	lsls r1, 19
	bl LZDecompressVram
	b _08036758
	.pool
_0803640C:
	ldr r1, =gUnknown_08C00524
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	b _08036758
	.pool
_08036424:
	ldr r0, =gUnknown_08C004E0
	movs r1, 0
	movs r2, 0x40
	bl LoadCompressedPalette
	b _08036758
	.pool
_08036434:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x023f0902
	ands r0, r1
	cmp r0, 0
	bne _08036518
	movs r0, 0x80
	lsls r0, 21
	ands r0, r1
	cmp r0, 0
	beq _0803645C
	ldr r0, =gUnknown_08D7BB14
	b _0803651A
	.pool
_0803645C:
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _0803648C
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x20
	beq _08036518
	cmp r0, 0x26
	bne _0803648C
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_0803648C:
	bl sav1_map_get_battletype
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bhi _080364CC
	lsls r0, 2
	ldr r1, =_080364A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080364A8:
	.4byte _080364CC
	.4byte _08036518
	.4byte _080364E8
	.4byte _080364F0
	.4byte _080364F8
	.4byte _08036500
	.4byte _08036508
	.4byte _08036510
	.4byte _08036518
_080364CC:
	ldr r2, =gBattleTerrainTable
	ldr r0, =gBattleTerrain
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	b _0803651A
	.pool
_080364E8:
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_080364F0:
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_080364F8:
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_08036500:
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_08036508:
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_08036510:
	ldr r0, =gUnknown_08D7CCD8
	b _0803651A
	.pool
_08036518:
	ldr r0, =gUnknown_08D7C440
_0803651A:
	ldr r1, =0x06008000
	bl LZDecompressVram
	b _08036758
	.pool
_0803652C:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x023f0902
	ands r0, r1
	cmp r0, 0
	beq _0803653A
	b _08036624
_0803653A:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	beq _08036568
	ldr r0, =gGameVersion
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08036560
	ldr r0, =gUnknown_08D7C154
	b _08036626
	.pool
_08036560:
	ldr r0, =gUnknown_08D7A720
	b _08036626
	.pool
_08036568:
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _08036598
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x20
	beq _08036624
	cmp r0, 0x26
	bne _08036598
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_08036598:
	bl sav1_map_get_battletype
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bhi _080365D8
	lsls r0, 2
	ldr r1, =_080365B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080365B4:
	.4byte _080365D8
	.4byte _08036624
	.4byte _080365F4
	.4byte _080365FC
	.4byte _08036604
	.4byte _0803660C
	.4byte _08036614
	.4byte _0803661C
	.4byte _08036624
_080365D8:
	ldr r2, =gBattleTerrainTable
	ldr r0, =gBattleTerrain
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	b _08036626
	.pool
_080365F4:
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_080365FC:
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_08036604:
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_0803660C:
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_08036614:
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_0803661C:
	ldr r0, =gUnknown_08D7D2E0
	b _08036626
	.pool
_08036624:
	ldr r0, =gUnknown_08D7CA28
_08036626:
	ldr r1, =0x0600d000
	bl LZDecompressVram
	b _08036758
	.pool
_08036638:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x023f0902
	ands r0, r1
	cmp r0, 0
	beq _08036646
	b _08036740
_08036646:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	beq _08036674
	ldr r0, =gGameVersion
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0803666C
	ldr r0, =gUnknown_08D7DF30
	b _08036742
	.pool
_0803666C:
	ldr r0, =gUnknown_08D7DEF4
	b _08036742
	.pool
_08036674:
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _080366AC
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x20
	bne _080366A0
	ldr r0, =gUnknown_08D7DFC4
	b _08036742
	.pool
_080366A0:
	cmp r0, 0x26
	bne _080366AC
	ldr r0, =gUnknown_08D7E1F8
	b _08036742
	.pool
_080366AC:
	bl sav1_map_get_battletype
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x8
	bhi _080366EC
	lsls r0, 2
	ldr r1, =_080366C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080366C8:
	.4byte _080366EC
	.4byte _08036708
	.4byte _08036710
	.4byte _08036718
	.4byte _08036720
	.4byte _08036728
	.4byte _08036730
	.4byte _08036738
	.4byte _08036740
_080366EC:
	ldr r2, =gBattleTerrainTable
	ldr r0, =gBattleTerrain
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x10
	adds r0, r2
	ldr r0, [r0]
	b _08036742
	.pool
_08036708:
	ldr r0, =gUnknown_08D7DF88
	b _08036742
	.pool
_08036710:
	ldr r0, =gUnknown_08D7E060
	b _08036742
	.pool
_08036718:
	ldr r0, =gUnknown_08D7E000
	b _08036742
	.pool
_08036720:
	ldr r0, =gUnknown_08D7E0CC
	b _08036742
	.pool
_08036728:
	ldr r0, =gUnknown_08D7E11C
	b _08036742
	.pool
_08036730:
	ldr r0, =gUnknown_08D7E164
	b _08036742
	.pool
_08036738:
	ldr r0, =gUnknown_08D7E1A8
	b _08036742
	.pool
_08036740:
	ldr r0, =gUnknown_08D7C9EC
_08036742:
	movs r1, 0x20
	movs r2, 0x60
	bl LoadCompressedPalette
	b _08036758
	.pool
_08036750:
	bl sub_803570C
	b _08036758
_08036756:
	movs r4, 0x1
_08036758:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80363C4

	.align 2, 0 @ Don't pad with nop.
