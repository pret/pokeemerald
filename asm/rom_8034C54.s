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
	ldr r2, =gMain+0x38
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

	.align 2, 0 @ Don't pad with nop.
