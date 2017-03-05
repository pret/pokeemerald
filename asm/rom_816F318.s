	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_816F318
sub_816F318: @ 816F318
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0xBF
	ble _0816F394
	ldrh r1, [r4, 0x34]
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0816F336
	subs r0, r1, 0x1
	strh r0, [r4, 0x34]
	b _0816F39A
_0816F336:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x32]
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 5
	subs r0, r1
	movs r1, 0x64
	bl __divsi3
	strh r0, [r4, 0x32]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	adds r0, r1, 0
	subs r0, 0xC0
	cmp r0, 0
	bge _0816F378
	adds r0, 0x7F
_0816F378:
	asrs r0, 7
	adds r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xF
	bls _0816F386
	movs r0, 0xF
_0816F386:
	lsls r2, r0, 4
	ldrb r1, [r4, 0x5]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x5]
	b _0816F39A
_0816F394:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_0816F39A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816F318

	thumb_func_start sub_816F3A4
sub_816F3A4: @ 816F3A4
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_02020630
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r3, 0x3C
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0816F420
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartObjectImageAnim
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 3
	strh r0, [r4, 0x34]
	ldr r0, =sub_816F318
	str r0, [r4, 0x1C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x2
	bl CalcVecFromObjectCenterToObjectUpperLeft
	b _0816F44C
	.pool
_0816F420:
	ldrh r0, [r1, 0x24]
	strh r0, [r4, 0x24]
	movs r0, 0x3C
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x26]
	strh r0, [r4, 0x26]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x20]
	strh r0, [r4, 0x20]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x22]
	strh r0, [r4, 0x22]
_0816F44C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816F3A4

	thumb_func_start sub_816F454
sub_816F454: @ 816F454
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0816F464
	ldr r0, =sub_816F46C
	str r0, [r1, 0x1C]
_0816F464:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F454

	thumb_func_start sub_816F46C
sub_816F46C: @ 816F46C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r7, r0, 0
	ldrh r4, [r7, 0x20]
	movs r1, 0x20
	ldrsh r0, [r7, r1]
	cmp r0, 0x74
	bgt _0816F4AC
	ldrh r0, [r7, 0x26]
	ldrh r1, [r7, 0x22]
	adds r0, r1
	movs r1, 0
	strh r0, [r7, 0x22]
	strh r1, [r7, 0x26]
	adds r0, r4, 0x4
	strh r0, [r7, 0x20]
	ldr r0, =0x0000fffc
	strh r0, [r7, 0x24]
	movs r0, 0x80
	strh r0, [r7, 0x36]
	ldr r0, =sub_816F5B4
	str r0, [r7, 0x1C]
	b _0816F59E
	.pool
_0816F4AC:
	ldrh r1, [r7, 0x36]
	ldr r5, =gUnknown_08329F40
	lsls r0, r1, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r2, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r3, [r0]
	adds r1, 0x2
	strh r1, [r7, 0x36]
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, 0
	bge _0816F4D2
	adds r0, 0x1F
_0816F4D2:
	asrs r0, 5
	strh r0, [r7, 0x26]
	subs r0, r4, 0x1
	strh r0, [r7, 0x20]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0816F4E8
	ldrh r0, [r7, 0x22]
	adds r0, 0x1
	strh r0, [r7, 0x22]
_0816F4E8:
	lsls r0, r3, 16
	asrs r0, 16
	negs r0, r0
	cmp r0, 0
	bge _0816F4F4
	adds r0, 0xF
_0816F4F4:
	lsls r1, r0, 12
	lsrs r1, 16
	ldrh r4, [r7, 0x32]
	ldrh r3, [r7, 0x34]
	adds r0, r1, 0
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r2, [r0]
	adds r1, 0x30
	lsls r1, 24
	lsrs r1, 23
	adds r1, r5
	movs r0, 0
	ldrsh r1, [r1, r0]
	adds r0, r1, 0
	muls r0, r4
	cmp r0, 0
	bge _0816F51E
	adds r0, 0xFF
_0816F51E:
	lsls r0, 8
	lsrs r0, 16
	mov r8, r0
	lsls r0, r2, 16
	asrs r2, r0, 16
	negs r0, r2
	muls r0, r3
	cmp r0, 0
	bge _0816F532
	adds r0, 0xFF
_0816F532:
	lsls r0, 8
	lsrs r0, 16
	mov r10, r0
	adds r0, r2, 0
	muls r0, r4
	cmp r0, 0
	bge _0816F542
	adds r0, 0xFF
_0816F542:
	lsls r0, 8
	lsrs r5, r0, 16
	adds r0, r1, 0
	muls r0, r3
	cmp r0, 0
	bge _0816F550
	adds r0, 0xFF
_0816F550:
	lsls r6, r0, 8
	lsrs r6, 16
	ldrh r0, [r7, 0x30]
	lsls r0, 24
	lsrs r0, 24
	str r3, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	ldrh r0, [r7, 0x30]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r5
	mov r1, r10
	lsls r5, r1, 16
	lsrs r3, r5, 16
	lsls r4, r6, 16
	str r6, [sp]
	mov r1, r8
	mov r2, r9
	bl SetSpriteTransformationMatrix
	ldrh r0, [r7, 0x30]
	adds r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	lsls r5, 1
	lsrs r5, 16
	lsls r4, 1
	lsrs r4, 16
	str r4, [sp]
	mov r1, r8
	mov r2, r9
	adds r3, r5, 0
	bl SetSpriteTransformationMatrix
_0816F59E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F46C

	thumb_func_start sub_816F5B4
sub_816F5B4: @ 816F5B4
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	adds r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	adds r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x3A]
	adds r1, 0x40
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	ldrh r1, [r4, 0x36]
	movs r2, 0x36
	ldrsh r0, [r4, r2]
	cmp r0, 0x40
	beq _0816F64C
	adds r0, r1, 0
	subs r0, 0x8
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x36]
	adds r1, r0, 0
	ldr r2, =gUnknown_08329F40
	adds r0, 0x40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bge _0816F62E
	adds r0, 0x3F
_0816F62E:
	asrs r0, 6
	strh r0, [r4, 0x24]
	lsls r0, r1, 24
	lsrs r0, 23
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _0816F642
	adds r0, 0x3F
_0816F642:
	asrs r0, 6
	strh r0, [r4, 0x26]
	b _0816F654
	.pool
_0816F64C:
	movs r0, 0
	strh r0, [r4, 0x36]
	ldr r0, =sub_816F660
	str r0, [r4, 0x1C]
_0816F654:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F5B4

	thumb_func_start sub_816F660
sub_816F660: @ 816F660
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x2
	beq _0816F6C0
	ldrh r0, [r1, 0x36]
	adds r0, 0x8
	strh r0, [r1, 0x36]
	ldr r3, =gUnknown_08329F40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	bge _0816F684
	adds r0, 0xF
_0816F684:
	asrs r0, 4
	adds r0, 0x40
	lsls r0, 16
	lsrs r2, r0, 16
	adds r0, r2, 0
	adds r0, 0x40
	lsls r0, 24
	lsrs r0, 23
	adds r0, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	bge _0816F6A0
	adds r0, 0x3F
_0816F6A0:
	asrs r0, 6
	strh r0, [r1, 0x24]
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _0816F6B4
	adds r0, 0x3F
_0816F6B4:
	asrs r0, 6
	strh r0, [r1, 0x26]
	b _0816F6C4
	.pool
_0816F6C0:
	ldr r0, =sub_816F6D0
	str r0, [r1, 0x1C]
_0816F6C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F660

	thumb_func_start sub_816F6D0
sub_816F6D0: @ 816F6D0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x22]
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _0816F6E8
	adds r0, r2, 0x4
	strh r0, [r4, 0x22]
	b _0816F744
_0816F6E8:
	movs r0, 0x1
	strh r0, [r4, 0x3C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartObjectImageAnim
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 3
	strh r0, [r4, 0x34]
	ldr r0, =sub_816F318
	str r0, [r4, 0x1C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x2
	bl CalcVecFromObjectCenterToObjectUpperLeft
_0816F744:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F6D0

	thumb_func_start sub_816F750
sub_816F750: @ 816F750
	push {r4,lr}
	adds r4, r0, 0
	ldrh r2, [r4, 0x22]
	movs r0, 0x22
	ldrsh r1, [r4, r0]
	movs r3, 0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge _0816F768
	adds r0, r2, 0x4
	strh r0, [r4, 0x22]
	b _0816F7C4
_0816F768:
	movs r0, 0x1
	strh r0, [r4, 0x3C]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r3, [r4, 0x22]
	adds r0, r3
	strh r0, [r4, 0x22]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartObjectImageAnim
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x32]
	ldrh r1, [r4, 0x30]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 3
	strh r0, [r4, 0x34]
	ldr r0, =sub_816F318
	str r0, [r4, 0x1C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x2
	bl CalcVecFromObjectCenterToObjectUpperLeft
_0816F7C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816F750

	thumb_func_start sub_816F7D0
sub_816F7D0: @ 816F7D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r6, [sp, 0x34]
	ldr r0, [sp, 0x38]
	mov r8, r0
	lsls r4, 16
	lsls r5, 16
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x8]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0xC]
	lsls r6, 16
	lsrs r6, 16
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r0, =gUnknown_085E4D64
	lsrs r2, r4, 16
	mov r10, r2
	asrs r4, 16
	lsrs r1, r5, 16
	str r1, [sp, 0x4]
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl AddObjectToFront
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gUnknown_02020630
	mov r9, r2
	lsls r0, r7, 4
	adds r0, r7
	lsls r5, r0, 2
	adds r4, r5, r2
	movs r0, 0
	strh r0, [r4, 0x2E]
	strh r0, [r4, 0x3C]
	mov r0, sp
	ldrh r0, [r0, 0xC]
	strh r0, [r4, 0x30]
	mov r1, sp
	ldrh r1, [r1, 0x8]
	strh r1, [r4, 0x32]
	mov r2, sp
	ldrh r2, [r2, 0x8]
	strh r2, [r4, 0x34]
	strh r6, [r4, 0x38]
	mov r0, sp
	ldrh r0, [r0, 0x8]
	strh r0, [r4, 0x3A]
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r0, 0x1F
	ldr r1, [sp, 0xC]
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl CalcVecFromObjectCenterToObjectUpperLeft
	adds r0, r4, 0
	movs r1, 0x2
	bl StartObjectImageAnim
	mov r1, r8
	cmp r1, 0
	bne _0816F898
	mov r0, r9
	adds r0, 0x1C
	adds r0, r5, r0
	ldr r1, =sub_816F454
	b _0816F8A0
	.pool
_0816F898:
	mov r0, r9
	adds r0, 0x1C
	adds r0, r5, r0
	ldr r1, =sub_816F750
_0816F8A0:
	str r1, [r0]
	str r7, [sp, 0x10]
	mov r2, r10
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	ldr r0, [sp, 0x4]
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, =gUnknown_085E4D64
	mov r1, r10
	mov r2, r8
	movs r3, 0x1
	bl AddObjectToFront
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gUnknown_02020630
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	adds r0, r4, r5
	mov r1, sp
	ldrh r1, [r1, 0x10]
	strh r1, [r0, 0x3C]
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	mov r9, r2
	strh r2, [r0, 0x30]
	ldrb r1, [r0, 0x1]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r2, r9
	movs r1, 0x1F
	ands r2, r1
	lsls r2, 1
	ldrb r3, [r0, 0x3]
	movs r6, 0x3F
	negs r6, r6
	adds r1, r6, 0
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x3]
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl CalcVecFromObjectCenterToObjectUpperLeft
	ldr r2, =gUnknown_0202064C
	adds r4, r2
	ldr r0, =sub_816F3A4
	str r0, [r4]
	ldr r0, =gUnknown_085E4D64
	mov r1, r10
	mov r2, r8
	movs r3, 0x1
	bl AddObjectToFront
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	adds r5, r4, r5
	mov r1, sp
	ldrh r1, [r1, 0x10]
	strh r1, [r5, 0x3C]
	ldr r2, [sp, 0xC]
	adds r2, 0x2
	mov r8, r2
	strh r2, [r5, 0x30]
	adds r0, r5, 0
	movs r1, 0x1
	bl StartObjectImageAnim
	ldrb r0, [r5, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r5, 0x1]
	mov r0, r8
	movs r2, 0x1F
	ands r0, r2
	lsls r0, 1
	ldrb r1, [r5, 0x3]
	ands r6, r1
	orrs r6, r0
	strb r6, [r5, 0x3]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x2
	movs r3, 0x2
	bl CalcVecFromObjectCenterToObjectUpperLeft
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r1, =sub_816F3A4
	str r1, [r4]
	ldr r2, [sp, 0xC]
	lsls r0, r2, 24
	lsrs r0, 24
	ldr r5, [sp, 0x8]
	adds r5, 0x20
	lsls r4, r5, 16
	lsrs r4, 16
	str r4, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	str r4, [sp]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r5, 17
	lsrs r5, 16
	str r5, [sp]
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	ldr r0, [sp, 0x10]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816F7D0

	thumb_func_start sub_816F9D4
sub_816F9D4: @ 816F9D4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bhi _0816FA62
	lsls r0, 2
	ldr r1, =_0816F9F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816F9F0:
	.4byte _0816FA04
	.4byte _0816FA12
	.4byte _0816FA30
	.4byte _0816FA62
	.4byte _0816FA50
_0816FA04:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	ldrh r0, [r4, 0x20]
	subs r0, 0x1
	b _0816FA60
_0816FA12:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0816FAAA
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	b _0816FA60
	.pool
_0816FA30:
	ldrh r2, [r4, 0x20]
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0x78
	ble _0816FA46
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0816FA6E
_0816FA46:
	adds r0, r2, 0x1
	b _0816FA60
	.pool
_0816FA50:
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _0816FA62
	subs r0, r2, 0x2
_0816FA60:
	strh r0, [r4, 0x20]
_0816FA62:
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0816FAAA
_0816FA6E:
	movs r1, 0x26
	ldrsh r5, [r4, r1]
	cmp r5, 0
	beq _0816FA80
	movs r0, 0
	strh r0, [r4, 0x26]
	b _0816FAAA
	.pool
_0816FA80:
	bl GenerateRandomNumber
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x1
	beq _0816FAA8
	cmp r1, 0x1
	bgt _0816FA96
	cmp r1, 0
	beq _0816FA9E
	b _0816FAAA
_0816FA96:
	cmp r1, 0x3
	bgt _0816FAAA
	strh r5, [r4, 0x26]
	b _0816FAAA
_0816FA9E:
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x26]
	b _0816FAAA
	.pool
_0816FAA8:
	strh r1, [r4, 0x26]
_0816FAAA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_816F9D4

	thumb_func_start sub_816FAB0
sub_816FAB0: @ 816FAB0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816FACA
	cmp r0, 0x1
	ble _0816FB12
	cmp r0, 0x2
	beq _0816FAEA
	cmp r0, 0x3
	beq _0816FB04
	b _0816FB12
_0816FACA:
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	adds r0, r1
	ldr r1, =0x0000012f
	cmp r0, r1
	bgt _0816FAE4
	ldrh r0, [r4, 0x24]
	adds r0, 0x8
	b _0816FB10
	.pool
_0816FAE4:
	movs r0, 0x2
	strh r0, [r4, 0x2E]
	b _0816FB12
_0816FAEA:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	adds r0, r1
	cmp r0, 0x78
	ble _0816FAFE
	ldrh r0, [r4, 0x24]
	subs r0, 0x1
	b _0816FB10
_0816FAFE:
	movs r0, 0x3
	strh r0, [r4, 0x2E]
	b _0816FB12
_0816FB04:
	ldrh r1, [r4, 0x24]
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0816FB12
	subs r0, r1, 0x2
_0816FB10:
	strh r0, [r4, 0x24]
_0816FB12:
	ldrh r0, [r4, 0x30]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x8
	bl sine
	ldr r1, =gUnknown_0203BCCC
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x4
	strh r0, [r4, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816FAB0

	thumb_func_start sub_816FB38
sub_816FB38: @ 816FB38
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r6, r1]
	cmp r0, 0x5
	bls _0816FB46
	b _0816FD38
_0816FB46:
	lsls r0, 2
	ldr r1, =_0816FB54
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0816FB54:
	.4byte _0816FB6C
	.4byte _0816FB94
	.4byte _0816FBB4
	.4byte _0816FC5C
	.4byte _0816FCC4
	.4byte _0816FCF4
_0816FB6C:
	ldrh r1, [r6, 0x30]
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _0816FB7C
	subs r0, r1, 0x1
	strh r0, [r6, 0x30]
	b _0816FD38
_0816FB7C:
	adds r2, r6, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	adds r0, r6, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	b _0816FCE6
_0816FB94:
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	cmp r0, 0x90
	beq _0816FB9E
	b _0816FD38
_0816FB9E:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
	movs r0, 0x9
	strh r0, [r6, 0x30]
	movs r0, 0x2
	strh r0, [r6, 0x34]
	b _0816FD38
	.pool
_0816FBB4:
	ldrh r1, [r6, 0x34]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _0816FC66
	movs r0, 0x2
	strh r0, [r6, 0x34]
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0816FC14
	lsls r0, 1
	ldr r4, =gUnknown_08D85C50
	adds r0, r4
	ldr r5, =gPlttBufferFaded + 0x23E
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r1
	adds r1, r5, 0
	subs r1, 0x16
	movs r2, 0x1
	bl CpuSet
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r4, 0x40
	adds r0, r4
	subs r5, 0xA
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r6, 0x30]
	subs r0, 0x1
	strh r0, [r6, 0x30]
	b _0816FD38
	.pool
_0816FC14:
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	ldr r4, =gUnknown_08D85C50
	adds r0, r4
	ldr r5, =gPlttBufferFaded + 0x23E
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r1
	adds r1, r5, 0
	subs r1, 0x16
	movs r2, 0x1
	bl CpuSet
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r4, 0x40
	adds r0, r4
	subs r5, 0xA
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	b _0816FCE6
	.pool
_0816FC5C:
	ldrh r1, [r6, 0x34]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _0816FC6C
_0816FC66:
	subs r0, r1, 0x1
	strh r0, [r6, 0x34]
	b _0816FD38
_0816FC6C:
	movs r0, 0x2
	strh r0, [r6, 0x34]
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	cmp r0, 0x9
	bgt _0816FCE6
	lsls r0, 1
	ldr r4, =gUnknown_08D85C50
	adds r0, r4
	ldr r5, =gPlttBufferFaded + 0x23E
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	movs r1, 0x30
	ldrsh r0, [r6, r1]
	lsls r0, 1
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r1
	adds r1, r5, 0
	subs r1, 0x16
	movs r2, 0x1
	bl CpuSet
	movs r2, 0x30
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r4, 0x40
	adds r0, r4
	subs r5, 0xA
	adds r1, r5, 0
	movs r2, 0x1
	bl CpuSet
	ldrh r0, [r6, 0x30]
	adds r0, 0x1
	strh r0, [r6, 0x30]
	b _0816FD38
	.pool
_0816FCC4:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bne _0816FD38
	adds r0, r6, 0
	movs r1, 0x2
	bl StartObjectRotScalAnim
	ldrb r1, [r6, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6, 0x1]
_0816FCE6:
	ldrh r0, [r6, 0x2E]
	adds r0, 0x1
	strh r0, [r6, 0x2E]
	b _0816FD38
	.pool
_0816FCF4:
	ldr r1, =gUnknown_085E4F48
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, 0x34]
	adds r0, r1
	strh r0, [r6, 0x34]
	movs r2, 0x34
	ldrsh r0, [r6, r2]
	movs r1, 0xFF
	lsls r1, 8
	ands r0, r1
	asrs r0, 8
	strh r0, [r6, 0x24]
	movs r1, 0x32
	ldrsh r0, [r6, r1]
	cmp r0, 0x3
	bgt _0816FD24
	movs r2, 0x24
	ldrsh r0, [r6, r2]
	negs r0, r0
	strh r0, [r6, 0x24]
_0816FD24:
	adds r0, r6, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0816FD38
	adds r0, r6, 0
	bl RemoveObjectAndFreeTiles
_0816FD38:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_816FB38

	thumb_func_start sub_816FD44
sub_816FD44: @ 816FD44
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0816FD7C
	cmp r0, 0x1
	bgt _0816FD5A
	cmp r0, 0
	beq _0816FD60
	b _0816FDB0
_0816FD5A:
	cmp r0, 0x2
	beq _0816FD9C
	b _0816FDB0
_0816FD60:
	ldr r0, =gUnknown_030062A0
	ldr r0, [r0]
	cmp r0, 0x80
	bne _0816FDB0
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r2]
	b _0816FD90
	.pool
_0816FD7C:
	ldr r0, =gUnknown_030062A0
	ldr r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	cmp r1, r0
	bne _0816FDB0
	adds r0, r4, 0
	movs r1, 0x3
	bl StartObjectRotScalAnim
_0816FD90:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _0816FDB0
	.pool
_0816FD9C:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0816FDB0
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_0816FDB0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_816FD44

	thumb_func_start sub_816FDB8
sub_816FDB8: @ 816FDB8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0x4]
	movs r7, 0
_0816FDD2:
	lsls r5, r7, 2
	ldr r0, =gUnknown_085E4E94
	adds r0, 0x2
	adds r0, r5, r0
	ldr r2, [sp]
	lsls r1, r2, 16
	asrs r1, 16
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	asrs r1, 16
	ldr r3, [sp, 0x4]
	lsls r2, r3, 16
	asrs r0, r2, 16
	str r0, [sp, 0x8]
	ldr r3, =0xfffc0000
	adds r2, r3
	ldr r0, =gUnknown_085E4F5C
	asrs r2, 16
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r4, r0
	movs r1, 0
	strh r1, [r4, 0x2E]
	ldr r0, =gUnknown_085E4FA4
	adds r0, r7, r0
	ldrb r0, [r0]
	strh r0, [r4, 0x30]
	strh r7, [r4, 0x32]
	adds r1, r4, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	mov r10, r2
	mov r3, r10
	orrs r0, r3
	strb r0, [r1]
	adds r1, r7, 0
	adds r1, 0xC
	movs r0, 0x1F
	mov r9, r0
	mov r2, r9
	ands r1, r2
	lsls r1, 1
	ldrb r0, [r4, 0x3]
	movs r3, 0x3F
	negs r3, r3
	mov r8, r3
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldr r3, =gUnknown_085E4E94
	adds r5, r3
	ldrb r1, [r5]
	adds r0, r4, 0
	bl StartObjectImageAnim
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectRotScalAnim
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x8
	bls _0816FDD2
	ldr r0, =gUnknown_085E4F8C
	ldr r2, [sp, 0x8]
	subs r2, 0x6
	lsls r2, 16
	asrs r2, 16
	movs r1, 0x78
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	movs r2, 0
	strh r2, [r0, 0x2E]
	adds r2, r0, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	mov r3, r10
	orrs r1, r3
	strb r1, [r2]
	adds r2, r7, 0
	adds r2, 0xC
	mov r1, r9
	ands r2, r1
	lsls r2, 1
	ldrb r1, [r0, 0x3]
	mov r3, r8
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, 0x3]
	movs r1, 0x1
	bl StartObjectRotScalAnim
	adds r0, r6, 0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_816FDB8

	thumb_func_start sub_816FEDC
sub_816FEDC: @ 816FEDC
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0816FF48
	ldr r2, =gUnknown_08329F40
	ldrh r1, [r4, 0x32]
	lsls r0, r1, 24
	lsrs r0, 23
	adds r0, r2
	ldrh r3, [r0]
	adds r1, 0x40
	lsls r1, 24
	lsrs r1, 23
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r1, 0x30
	ldrsh r2, [r4, r1]
	adds r1, r0, 0
	muls r1, r2
	adds r0, r1, 0
	cmp r1, 0
	bge _0816FF18
	adds r0, 0xFF
_0816FF18:
	lsls r0, 8
	lsrs r6, r0, 16
	lsls r0, r3, 16
	asrs r3, r0, 16
	negs r0, r3
	muls r0, r2
	cmp r0, 0
	bge _0816FF2A
	adds r0, 0xFF
_0816FF2A:
	lsls r0, 8
	lsrs r5, r0, 16
	adds r0, r3, 0
	muls r0, r2
	cmp r0, 0
	bge _0816FF38
	adds r0, 0xFF
_0816FF38:
	lsls r0, 8
	lsrs r2, r0, 16
	adds r1, r6, 0
	adds r3, r5, 0
	str r1, [sp]
	movs r0, 0x1
	bl SetSpriteTransformationMatrix
_0816FF48:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _0816FF9C
	cmp r0, 0x1
	ble _0816FF58
	cmp r0, 0x2
	beq _0816FFFE
_0816FF58:
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x3
	movs r3, 0x3
	bl CalcVecFromObjectCenterToObjectUpperLeft
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r1, 0
	movs r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x80
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x32]
	strh r1, [r4, 0x34]
	b _08170038
	.pool
_0816FF9C:
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x8C
	bl sine
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x78
	bl sine
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x7
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x34]
	adds r0, 0x3
	strh r0, [r4, 0x34]
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x10
	negs r1, r1
	cmp r0, r1
	bgt _08170038
	ldrb r0, [r4, 0x5]
	movs r1, 0xC
	orrs r0, r1
	strb r0, [r4, 0x5]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x14
	strh r0, [r4, 0x20]
	movs r0, 0x28
	strh r0, [r4, 0x22]
	movs r0, 0x80
	lsls r0, 2
	strh r0, [r4, 0x30]
	movs r0, 0
	strh r0, [r4, 0x32]
	movs r0, 0x10
	b _08170036
_0816FFFE:
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x22
	bl sine
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3C
	bl cosine
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	strh r0, [r4, 0x30]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	movs r1, 0x5
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _08170038
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
_08170036:
	strh r0, [r4, 0x34]
_08170038:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_816FEDC

	thumb_func_start sub_8170040
sub_8170040: @ 8170040
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08170056
	adds r4, r5, 0
	adds r4, 0x3E
	cmp r0, 0x1
	beq _0817008E
_08170056:
	adds r4, r5, 0
	adds r4, 0x3E
	ldrb r1, [r4]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r4]
	ldrb r0, [r5, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldrb r1, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x24
	orrs r0, r1
	strb r0, [r5, 0x3]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x3
	movs r3, 0x3
	bl CalcVecFromObjectCenterToObjectUpperLeft
	movs r0, 0
	strh r0, [r5, 0x30]
	movs r0, 0x1
	strh r0, [r5, 0x2E]
_0817008E:
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081700A6
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	b _081700BE
_081700A6:
	ldrb r0, [r4]
	movs r1, 0x5
	negs r1, r1
	ands r1, r0
	strb r1, [r4]
	ldrh r1, [r5, 0x30]
	movs r2, 0x30
	ldrsh r0, [r5, r2]
	cmp r0, 0x3F
	bgt _081700BE
	adds r0, r1, 0x1
	strh r0, [r5, 0x30]
_081700BE:
	ldr r1, =gUnknown_08329F40
	ldrh r0, [r5, 0x30]
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0x12
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170040

	thumb_func_start sub_81700F8
sub_81700F8: @ 81700F8
	push {r4,r5,lr}
	ldr r5, =0x04000208
	ldrh r4, [r5]
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x1
	bl RegisterRamReset
	movs r0, 0
	movs r1, 0x80
	bl ClearGpuRegBits
	strh r4, [r5]
	ldr r1, =gUnknown_030022C0
	ldr r0, =0x00000439
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl sub_815355C
	lsls r0, 16
	lsrs r0, 16
	bl InitSaveBlockPointersWithRandomOffset
	bl sub_808447C
	bl sub_8152680
	movs r0, 0
	bl sub_81534D0
	ldr r0, =gUnknown_03006210
	ldrh r0, [r0]
	cmp r0, 0
	beq _08170148
	cmp r0, 0x2
	bne _0817014C
_08170148:
	bl init_sav2
_0817014C:
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsls r0, 31
	lsrs r0, 31
	bl SetPokemonCryStereo
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
	ldr r0, =sub_8086230
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81700F8

	thumb_func_start sub_817018C
sub_817018C: @ 817018C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0
	bl SetVBlankCallback
	ldr r4, =gUnknown_0203BCD0
	movs r0, 0x89
	lsls r0, 4
	bl Alloc
	str r0, [r4]
	ldr r1, =0x0000088c
	adds r2, r0, r1
	movs r1, 0
	strh r1, [r2]
	str r5, [r0]
	ldr r0, =sub_81701C4
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817018C

	thumb_func_start sub_81701C4
sub_81701C4: @ 81701C4
	push {lr}
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E5068
	movs r0, 0x1
	movs r2, 0x2
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_085E5070
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x27
	movs r2, 0xD0
	bl sub_809882C
	bl clear_scheduled_bg_copies_to_vram
	ldr r0, =sub_8170274
	bl SetMainCallback2
	ldr r0, =sub_8170260
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81701C4

	thumb_func_start sub_8170260
sub_8170260: @ 8170260
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8170260

	thumb_func_start sub_8170274
sub_8170274: @ 8170274
	push {lr}
	bl sub_8170290
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
	bl UpdatePaletteFade
	bl do_scheduled_bg_tilemap_copies_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_8170274

	thumb_func_start sub_8170290
sub_8170290: @ 8170290
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =gUnknown_0203BCD0
	ldr r0, [r1]
	ldr r2, =0x0000088c
	adds r0, r2
	ldrh r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x6
	bls _081702A6
	b _08170416
_081702A6:
	lsls r0, 2
	ldr r1, =_081702BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081702BC:
	.4byte _081702D8
	.4byte _08170300
	.4byte _08170358
	.4byte _08170380
	.4byte _08170394
	.4byte _081703C0
	.4byte _081703E8
_081702D8:
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	bl sub_8122CDC
	movs r0, 0
	movs r1, 0
	bl sub_8124288
	movs r0, 0x1
	movs r1, 0x1
	bl sub_81240D4
	ldr r1, [r4]
	ldr r0, =0x0000088c
	adds r1, r0
	b _081703D8
	.pool
_08170300:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x27
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r5, =gUnknown_085EE8F1
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl Print
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0
	movs r2, 0x27
	movs r3, 0xD
	bl SetWindowBorderStyle
	bl sub_8170428
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	b _081703CC
	.pool
_08170358:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuRegBits
	movs r0, 0
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =gUnknown_0203BCD0
	ldr r1, [r0]
	ldr r0, =0x0000088c
	adds r1, r0
	b _081703D8
	.pool
_08170380:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08170416
	ldr r1, [r4]
	b _081703D4
	.pool
_08170394:
	bl sub_81230AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _081703A6
	bl sub_8170428
	b _08170416
_081703A6:
	cmp r0, 0x3
	blt _08170416
	cmp r0, 0x5
	bgt _08170416
	ldr r0, =gUnknown_0203BCD0
	ldr r1, [r0]
	ldr r0, =0x0000088c
	adds r1, r0
	b _081703D8
	.pool
_081703C0:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
_081703CC:
	bl BeginNormalPaletteFade
	ldr r0, =gUnknown_0203BCD0
	ldr r1, [r0]
_081703D4:
	ldr r2, =0x0000088c
	adds r1, r2
_081703D8:
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _08170416
	.pool
_081703E8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08170416
	bl sub_812305C
	ldr r4, =gUnknown_0203BCD0
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	ldr r0, [r4]
	cmp r0, 0
	beq _08170412
	bl Free
	str r5, [r4]
_08170412:
	bl FreeAllWindowBuffers
_08170416:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170290

	thumb_func_start sub_8170428
sub_8170428: @ 8170428
	push {r4,lr}
	sub sp, 0xC
	ldr r4, =gUnknown_0203BCD0
	ldr r0, [r4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08170460
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, [r4]
	adds r2, 0xC
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl Print
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	b _08170470
	.pool
_08170460:
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08170470:
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8170428

	thumb_func_start sub_8170478
sub_8170478: @ 8170478
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	ldr r0, =gUnknown_02038436
	ldrb r4, [r0]
	ldr r0, =gUnknown_02022E24
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E26
	strh r1, [r0]
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r1, =0x00003f3d
	movs r0, 0x4A
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 8
	movs r0, 0
	bl SetGpuRegBits
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0x80
	lsls r1, 5
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x1
	movs r1, 0x4
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	bl lcd_bg_operations
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0x1
	bl lcd_bg_operations
	ldr r0, =gUnknown_03005D70
	adds r4, r0
	ldrb r0, [r4]
	ldr r1, =gUnknown_02020630
	mov r9, r1
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	add r4, r9
	ldrb r7, [r4, 0x6]
	ldrh r6, [r4, 0x38]
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =DummyObjectCallback
	bl object_new_hidden_with_callback
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	ldr r0, =DummyObjectCallback
	bl object_new_hidden_with_callback
	mov r10, r0
	mov r2, r10
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	ldrb r1, [r4, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x4
	mov r8, r1
	mov r2, r8
	orrs r0, r2
	strb r0, [r4, 0x5]
	lsls r5, r7, 4
	adds r5, r7
	lsls r5, 2
	add r5, r9
	ldrb r1, [r5, 0x5]
	adds r0, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	add r1, r9
	ldrb r2, [r1, 0x5]
	adds r0, r3, 0
	ands r0, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [sp, 0x14]
	lsls r6, r0, 4
	adds r6, r0
	lsls r6, 2
	mov r1, r9
	adds r7, r6, r1
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x44
	str r3, [sp, 0x18]
	bl memcpy
	mov r2, r10
	lsls r4, r2, 4
	add r4, r10
	lsls r4, 2
	adds r0, r4, 0
	add r0, r9
	mov r8, r0
	adds r1, r5, 0
	movs r2, 0x44
	bl memcpy
	ldrb r1, [r7, 0x1]
	ldr r3, [sp, 0x18]
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r7, 0x1]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	ands r3, r0
	orrs r3, r1
	strb r3, [r2, 0x1]
	movs r0, 0x1C
	add r9, r0
	add r6, r9
	ldr r1, =DummyObjectCallback
	str r1, [r6]
	add r4, r9
	str r1, [r4]
	mov r0, sp
	bl sub_80A6B30
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2EA9C
	bl sub_80A6D48
	mov r0, sp
	ldrb r0, [r0, 0x9]
	ldr r1, =gUnknown_08C2EA50
	mov r2, sp
	ldrh r2, [r2, 0xA]
	bl sub_80A6CC0
	ldr r0, =gUnknown_08C2DDA4
	mov r1, sp
	ldrb r1, [r1, 0x8]
	lsls r1, 4
	movs r2, 0x20
	bl LoadCompressedPalette
	ldr r1, =gUnknown_02022E18
	ldrh r0, [r7, 0x20]
	negs r0, r0
	adds r0, 0x20
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1A
	ldrh r0, [r7, 0x22]
	negs r0, r0
	subs r0, 0x20
	strh r0, [r1]
	ldr r1, =gTasks
	ldr r2, [sp, 0x10]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r1, 0xA0
	lsls r1, 2
	strh r1, [r0, 0xA]
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0, 0x8]
	mov r2, r10
	strh r2, [r0, 0xC]
	ldr r1, =sub_8170660
	str r1, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170478

	thumb_func_start sub_8170660
sub_8170660: @ 8170660
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r5, r0, r1
	ldrh r1, [r5, 0xA]
	ldrh r0, [r5, 0x22]
	adds r1, r0
	movs r3, 0
	strh r1, [r5, 0x22]
	ldr r2, =gUnknown_02022E1A
	lsls r0, r1, 16
	lsrs r0, 24
	ldrh r4, [r2]
	adds r0, r4
	strh r0, [r2]
	movs r0, 0xFF
	ands r1, r0
	strh r1, [r5, 0x22]
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081706F0
	cmp r0, 0x1
	bgt _081706B4
	cmp r0, 0
	beq _081706BA
	b _08170814
	.pool
_081706B4:
	cmp r0, 0x2
	beq _08170708
	b _08170814
_081706BA:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _081706CA
	b _08170814
_081706CA:
	strh r3, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	adds r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r2, 0x20
	ldrsh r0, [r5, r2]
	cmp r0, 0x8
	beq _081706EE
	b _08170814
_081706EE:
	b _08170700
_081706F0:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	beq _08170700
	b _08170814
_08170700:
	ldrh r0, [r5, 0x26]
	adds r0, 0x1
	strh r0, [r5, 0x26]
	b _08170814
_08170708:
	ldrh r0, [r5, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r5, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08170814
	strh r3, [r5, 0x1E]
	ldrh r1, [r5, 0x20]
	subs r1, 0x1
	strh r1, [r5, 0x20]
	movs r0, 0x10
	subs r0, r1
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x20
	ldrsh r4, [r5, r0]
	cmp r4, 0
	bne _08170814
	movs r0, 0
	bl sub_80A477C
	ldr r0, =gUnknown_02022E24
	strh r4, [r0]
	ldr r0, =gUnknown_02022E26
	strh r4, [r0]
	ldr r4, =0x00003f3f
	movs r0, 0x48
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r4, 0
	bl SetGpuReg
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0817076C
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl lcd_bg_operations
_0817076C:
	movs r0, 0
	bl GetGpuReg
	adds r1, r0, 0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	eors r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r4, 0x8
	ldrsh r1, [r5, r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r6, =gUnknown_02020630
	adds r0, r6
	bl RemoveObjectAndFreeTiles
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl RemoveObjectAndFreeTiles
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl lcd_bg_operations
	ldr r0, =gUnknown_03005D70
	add r0, r8
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x6]
	mov r8, r2
	ldrh r4, [r1, 0x38]
	lsls r4, 24
	lsrs r4, 24
	ldrb r3, [r1, 0x5]
	movs r2, 0xD
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	movs r5, 0x4
	orrs r0, r5
	strb r0, [r1, 0x5]
	mov r0, r8
	lsls r1, r0, 4
	add r1, r8
	lsls r1, 2
	adds r1, r6
	ldrb r3, [r1, 0x5]
	adds r0, r2, 0
	ands r0, r3
	orrs r0, r5
	strb r0, [r1, 0x5]
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0, 0x5]
	ands r2, r1
	orrs r2, r5
	strb r2, [r0, 0x5]
	adds r0, r7, 0
	bl move_anim_task_del
_08170814:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170660

	thumb_func_start sub_8170834
sub_8170834: @ 8170834
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_03005D70
	adds r2, r0
	ldrb r0, [r2]
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r0, =gUnknown_02020630
	adds r5, r0
	ldrb r1, [r5, 0x6]
	mov r10, r1
	ldrh r4, [r5, 0x38]
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000d709
	bl AllocObjectPalette
	mov r2, r9
	strb r0, [r2]
	ldr r0, =0x0000d70a
	bl AllocObjectPalette
	strb r0, [r7]
	ldrb r0, [r5, 0x5]
	lsrs r0, 4
	lsls r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r3, r1, 0
	orrs r0, r3
	lsls r6, r4, 4
	adds r6, r4
	lsls r6, 2
	ldr r2, =gUnknown_02020630
	adds r6, r2
	ldrb r4, [r6, 0x5]
	lsrs r4, 4
	lsls r4, 4
	orrs r4, r3
	lsls r0, 1
	ldr r1, =gPlttBufferUnfaded
	mov r8, r1
	add r0, r8
	mov r2, r9
	ldrb r1, [r2]
	lsls r1, 4
	adds r1, r3, r1
	movs r2, 0x20
	str r3, [sp]
	bl LoadPalette
	lsls r4, 1
	add r4, r8
	ldrb r0, [r7]
	lsls r0, 4
	ldr r3, [sp]
	adds r3, r0
	adds r0, r4, 0
	adds r1, r3, 0
	movs r2, 0x20
	bl LoadPalette
	mov r0, r9
	ldrb r1, [r0]
	lsls r1, 4
	ldrb r2, [r5, 0x5]
	movs r3, 0xF
	adds r0, r3, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	mov r2, r10
	lsls r1, r2, 4
	add r1, r10
	lsls r1, 2
	ldr r0, =gUnknown_02020630
	adds r1, r0
	mov r0, r9
	ldrb r2, [r0]
	lsls r2, 4
	ldrb r4, [r1, 0x5]
	adds r0, r3, 0
	ands r0, r4
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldrb r0, [r7]
	lsls r0, 4
	ldrb r1, [r6, 0x5]
	ands r3, r1
	orrs r3, r0
	strb r3, [r6, 0x5]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170834

	thumb_func_start sub_8170920
sub_8170920: @ 8170920
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, sp
	adds r1, 0x1
	ldr r0, =gUnknown_02038436
	ldrb r2, [r0]
	mov r0, sp
	bl sub_8170834
	adds r0, r4, 0
	bl move_anim_task_del
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170920

	thumb_func_start sub_817094C
sub_817094C: @ 817094C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_03005D70
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gUnknown_02020630
	mov r8, r1
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	add r5, r8
	ldrb r0, [r5, 0x6]
	mov r9, r0
	ldrh r6, [r5, 0x38]
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =0x0000d709
	bl FreeObjectPaletteByTag
	ldr r0, =0x0000d70a
	bl FreeObjectPaletteByTag
	ldr r0, =0x0000d6ff
	bl IndexOfObjectPaletteTag
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x0000d704
	bl IndexOfObjectPaletteTag
	lsls r0, 24
	lsls r4, 4
	ldrb r2, [r5, 0x5]
	movs r3, 0xF
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r4
	strb r1, [r5, 0x5]
	mov r1, r9
	lsls r2, r1, 4
	add r2, r9
	lsls r2, 2
	add r2, r8
	ldrb r5, [r2, 0x5]
	adds r1, r3, 0
	ands r1, r5
	orrs r1, r4
	strb r1, [r2, 0x5]
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	add r1, r8
	lsrs r0, 20
	ldrb r2, [r1, 0x5]
	ands r3, r2
	orrs r3, r0
	strb r3, [r1, 0x5]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817094C

	thumb_func_start sub_81709EC
sub_81709EC: @ 81709EC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl sub_817094C
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81709EC

	thumb_func_start sub_8170A0C
sub_8170A0C: @ 8170A0C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =gUnknown_0203841E
	ldrh r0, [r2]
	strh r0, [r1, 0x1C]
	ldrh r0, [r2, 0x2]
	strh r0, [r1, 0x1E]
	ldr r0, =sub_8170A38
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8170A0C

	thumb_func_start sub_8170A38
sub_8170A38: @ 8170A38
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r6, 0
	adds r1, r0, 0x1
	strh r1, [r4, 0x8]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08170AF8
	strh r6, [r4, 0x8]
	ldr r0, =0x0000d709
	bl IndexOfObjectPaletteTag
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0x1C
	ldrsh r0, [r4, r3]
	movs r1, 0x2
	cmp r0, 0
	bne _08170A76
	movs r1, 0x6
_08170A76:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _08170A8C
	cmp r0, 0x1
	beq _08170AC8
	b _08170AF8
	.pool
_08170A8C:
	ldrh r0, [r4, 0xC]
	adds r0, 0x2
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08170A9E
	movs r0, 0x10
	strh r0, [r4, 0xC]
_08170A9E:
	lsls r0, r2, 4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	orrs r0, r1
	ldrb r2, [r4, 0xC]
	ldr r3, =0x00007f74
	movs r1, 0x1
	bl BlendPalette
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0x10
	bne _08170AF8
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	b _08170AF8
	.pool
_08170AC8:
	ldrh r0, [r4, 0xC]
	subs r0, 0x2
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bge _08170AD6
	strh r6, [r4, 0xC]
_08170AD6:
	lsls r0, r2, 4
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2
	orrs r0, r1
	ldrb r2, [r4, 0xC]
	ldr r3, =0x00007f74
	movs r1, 0x1
	bl BlendPalette
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0
	bne _08170AF8
	adds r0, r5, 0
	bl move_anim_task_del
_08170AF8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170A38

	thumb_func_start sub_8170B04
sub_8170B04: @ 8170B04
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gUnknown_020241E4
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r5, [r0]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08170B52
	cmp r0, 0x1
	bgt _08170B3C
	cmp r0, 0
	beq _08170B42
	b _08170BA4
	.pool
_08170B3C:
	cmp r0, 0x2
	beq _08170B84
	b _08170BA4
_08170B42:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x1C]
	b _08170B76
_08170B52:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x30
	strh r0, [r4, 0x1C]
	movs r0, 0x1C
	ldrsh r2, [r4, r0]
	adds r0, r5, 0
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	adds r0, r5, 0
	bl sub_80A7E6C
	movs r0, 0x1C
	ldrsh r1, [r4, r0]
	ldr r0, =0x000002cf
	cmp r1, r0
	ble _08170BA4
_08170B76:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08170BA4
	.pool
_08170B84:
	adds r0, r5, 0
	bl sub_80A7344
	ldr r1, =gUnknown_02020630
	lsls r0, r5, 4
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, 0
	bl move_anim_task_del
_08170BA4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170B04

	thumb_func_start sub_8170BB0
sub_8170BB0: @ 8170BB0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gUnknown_020241E4
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	adds r1, r0, r1
	ldrb r1, [r1]
	mov r9, r1
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	bne _08170BF8
	ldr r1, =gUnknown_0202406E
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_020244EC
	b _08170C08
	.pool
_08170BF8:
	ldr r1, =gUnknown_0202406E
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gUnknown_02024744
_08170C08:
	adds r0, r1
	movs r1, 0x26
	bl pokemon_getattr
	lsls r0, 16
	lsrs r0, 16
	bl ball_number_to_ball_processing_index
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r6, r0, r2
	movs r0, 0x8
	ldrsh r7, [r6, r0]
	cmp r7, 0
	beq _08170C44
	cmp r7, 0x1
	beq _08170CC4
	b _08170CEE
	.pool
_08170C44:
	ldr r5, =gUnknown_02038436
	ldrb r0, [r5]
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_80A5C6C
	adds r1, r0, 0
	lsls r1, 24
	ldr r2, =gUnknown_02020630
	mov r3, r9
	lsls r0, r3, 4
	add r0, r9
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x5]
	lsls r2, 28
	lsrs r2, 30
	adds r0, 0x43
	ldrb r3, [r0]
	movs r0, 0x80
	lsls r0, 22
	adds r1, r0
	lsrs r1, 24
	mov r0, r8
	str r0, [sp]
	adds r0, r4, 0
	bl sub_8171D98
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x1C]
	str r7, [sp]
	str r7, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A75AC
	adds r2, r0, 0
	ldrb r1, [r5]
	movs r0, 0
	mov r3, r8
	bl sub_81729E8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x1E]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _08170CEE
	.pool
_08170CC4:
	movs r1, 0x1C
	ldrsh r0, [r6, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08170CEE
	movs r3, 0x1E
	ldrsh r0, [r6, r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08170CEE
	adds r0, r5, 0
	bl move_anim_task_del
_08170CEE:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8170BB0

	thumb_func_start sub_8170CFC
sub_8170CFC: @ 8170CFC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02024208
	ldrh r0, [r0]
	bl ball_number_to_ball_processing_index
	lsls r0, 24
	lsrs r0, 24
	bl sub_8076A78
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170CFC

	thumb_func_start sub_8170D24
sub_8170D24: @ 8170D24
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_02024208
	ldrh r0, [r0]
	bl ball_number_to_ball_processing_index
	lsls r0, 24
	lsrs r0, 24
	bl sub_8076AE8
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170D24

	thumb_func_start sub_8170D4C
sub_8170D4C: @ 8170D4C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x5
	bne _08170D70
	ldr r1, =gUnknown_0203841E
	ldr r0, =0x0000ffff
	b _08170D74
	.pool
_08170D70:
	ldr r1, =gUnknown_0203841E
	movs r0, 0
_08170D74:
	strh r0, [r1, 0xE]
	adds r0, r2, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170D4C

	thumb_func_start ball_number_to_ball_processing_index
ball_number_to_ball_processing_index: @ 8170D84
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	subs r0, 0x1
	cmp r0, 0xB
	bhi _08170DFC
	lsls r0, 2
	ldr r1, =_08170DA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08170DA0:
	.4byte _08170DD0
	.4byte _08170DD4
	.4byte _08170DD8
	.4byte _08170DFC
	.4byte _08170DDC
	.4byte _08170DE0
	.4byte _08170DE4
	.4byte _08170DE8
	.4byte _08170DEC
	.4byte _08170DF0
	.4byte _08170DF4
	.4byte _08170DF8
_08170DD0:
	movs r0, 0x4
	b _08170DFE
_08170DD4:
	movs r0, 0x3
	b _08170DFE
_08170DD8:
	movs r0, 0x1
	b _08170DFE
_08170DDC:
	movs r0, 0x2
	b _08170DFE
_08170DE0:
	movs r0, 0x5
	b _08170DFE
_08170DE4:
	movs r0, 0x6
	b _08170DFE
_08170DE8:
	movs r0, 0x7
	b _08170DFE
_08170DEC:
	movs r0, 0x8
	b _08170DFE
_08170DF0:
	movs r0, 0x9
	b _08170DFE
_08170DF4:
	movs r0, 0xA
	b _08170DFE
_08170DF8:
	movs r0, 0xB
	b _08170DFE
_08170DFC:
	movs r0, 0
_08170DFE:
	pop {r1}
	bx r1
	thumb_func_end ball_number_to_ball_processing_index

	thumb_func_start sub_8170E04
sub_8170E04: @ 8170E04
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	mov r10, r0
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, =gUnknown_02024208
	ldrh r0, [r0]
	bl ball_number_to_ball_processing_index
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	ldr r1, =gUnknown_0832C588
	adds r0, r1
	movs r1, 0x20
	movs r2, 0x50
	movs r3, 0x1D
	bl AddObjectToFront
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r1, =gUnknown_02020630
	mov r9, r1
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r6, r4, r1
	movs r0, 0x22
	strh r0, [r6, 0x2E]
	ldr r2, =gUnknown_02038437
	mov r8, r2
	ldrb r0, [r2]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x30]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x10
	strh r0, [r6, 0x32]
	mov r0, r9
	adds r0, 0x1C
	adds r4, r0
	ldr r0, =sub_8171104
	str r0, [r4]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r3, [r0, 0x8]
	ldr r1, =gUnknown_020241E4
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	lsls r1, 1
	ldrb r2, [r3, 0x9]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x9]
	ldr r1, =gTasks
	mov r2, r10
	lsls r0, r2, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	ldr r1, =sub_8170EF0
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170E04

	thumb_func_start sub_8170EF0
sub_8170EF0: @ 8170EF0
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x8]
	ldr r2, =gUnknown_02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x2E]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08170F1A
	adds r0, r3, 0
	bl move_anim_task_del
_08170F1A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170EF0

	thumb_func_start sub_8170F2C
sub_8170F2C: @ 8170F2C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _08170F50
	movs r6, 0x20
	movs r5, 0xB
	b _08170F54
	.pool
_08170F50:
	movs r6, 0x17
	movs r5, 0x5
_08170F54:
	ldr r0, =gUnknown_02024208
	ldrh r0, [r0]
	bl ball_number_to_ball_processing_index
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl battle_get_side_with_given_state
	lsls r0, 24
	lsrs r0, 24
	bl sub_80A82E4
	adds r3, r0, 0
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r1, =gUnknown_0832C588
	adds r0, r1
	adds r1, r6, 0
	adds r1, 0x20
	movs r2, 0x50
	orrs r5, r2
	adds r2, r5, 0
	bl AddObjectToFront
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_02020630
	mov r9, r0
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	adds r6, r4, r0
	movs r0, 0x22
	strh r0, [r6, 0x2E]
	ldr r1, =gUnknown_02038437
	mov r8, r1
	ldrb r0, [r1]
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x30]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x10
	strh r0, [r6, 0x32]
	movs r0, 0x1C
	add r9, r0
	add r4, r9
	ldr r0, =DummyObjectCallback
	str r0, [r4]
	movs r0, 0
	bl battle_get_side_with_given_state
	ldr r1, =gUnknown_020241E4
	lsls r0, 24
	lsrs r0, 24
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	ldr r1, =sub_8039E84
	str r1, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r5, [r0, 0x8]
	ldr r1, =sub_8171030
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170F2C

	thumb_func_start sub_8171030
sub_8171030: @ 8171030
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gUnknown_02020630
	movs r0, 0
	bl battle_get_side_with_given_state
	ldr r1, =gUnknown_020241E4
	lsls r0, 24
	lsrs r0, 24
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0817108A
	movs r0, 0x3D
	movs r1, 0
	bl audio_play_and_stuff
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_8171104
	str r1, [r0]
	ldr r0, =sub_81710A8
	movs r1, 0xA
	bl CreateTask
	ldr r0, =sub_8170EF0
	str r0, [r4]
_0817108A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171030

	thumb_func_start sub_81710A8
sub_81710A8: @ 81710A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gUnknown_02020630
	movs r0, 0
	bl battle_get_side_with_given_state
	ldr r4, =gUnknown_020241E4
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _081710F4
	movs r0, 0
	bl battle_get_side_with_given_state
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0
	bl StartObjectImageAnim
	adds r0, r5, 0
	bl DestroyTask
_081710F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81710A8

	thumb_func_start sub_8171104
sub_8171104: @ 8171104
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	ldrh r2, [r4, 0x32]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x30]
	strh r1, [r4, 0x32]
	ldrh r0, [r4, 0x22]
	strh r0, [r4, 0x34]
	strh r2, [r4, 0x36]
	ldr r0, =0x0000ffd8
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r0, =sub_8171134
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171104

	thumb_func_start sub_8171134
sub_8171134: @ 8171134
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _081711D2
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x5
	bne _08171160
	ldr r0, =sub_8171CAC
	str r0, [r4, 0x1C]
	b _081711D2
	.pool
_08171160:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectImageAnim
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x26]
	adds r1, r4, 0
	adds r1, 0x2E
	movs r2, 0
	adds r0, r4, 0
	adds r0, 0x3C
_08171188:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _08171188
	movs r0, 0
	strh r0, [r4, 0x38]
	ldr r0, =sub_81711E8
	str r0, [r4, 0x1C]
	ldr r0, =gUnknown_02024208
	ldrh r0, [r0]
	bl ball_number_to_ball_processing_index
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xB
	bgt _081711D2
	cmp r5, 0
	blt _081711D2
	ldrh r0, [r4, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	str r5, [sp]
	movs r2, 0x1
	movs r3, 0x1C
	bl sub_8171D98
	ldr r0, =gUnknown_02038437
	ldrb r1, [r0]
	movs r0, 0
	movs r2, 0xE
	adds r3, r5, 0
	bl sub_81729E8
_081711D2:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171134

	thumb_func_start sub_81711E8
sub_81711E8: @ 81711E8
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08171224
	ldr r0, =TaskDummy
	movs r1, 0x32
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x38]
	ldr r0, =sub_8171240
	str r0, [r4, 0x1C]
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x30]
_08171224:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81711E8

	thumb_func_start sub_8171240
sub_8171240: @ 8171240
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r1, =gUnknown_020241E4
	ldr r0, =gUnknown_02038437
	ldrb r0, [r0]
	adds r0, r1
	ldrb r4, [r0]
	ldrh r0, [r7, 0x38]
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r5, r0, r1
	ldrh r0, [r5, 0xA]
	adds r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xB
	bne _08171272
	movs r0, 0x3C
	bl audio_play
_08171272:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _081712E8
	cmp r0, 0x1
	bgt _08171290
	cmp r0, 0
	beq _08171296
	b _08171354
	.pool
_08171290:
	cmp r0, 0x2
	beq _0817132C
	b _08171354
_08171296:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A7270
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r5, 0x1C]
	ldr r1, =gUnknown_030062DC
	movs r0, 0x1C
	str r0, [r1]
	ldr r2, =gUnknown_030062E4
	ldr r1, =gUnknown_02020630
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x26]
	ldrh r0, [r0, 0x22]
	adds r1, r0
	ldrh r0, [r7, 0x26]
	ldrh r7, [r7, 0x22]
	adds r0, r7
	subs r1, r0
	strh r1, [r2]
	ldr r4, =gUnknown_030062E0
	ldrh r0, [r2]
	lsls r0, 8
	movs r1, 0x1C
	bl __udivsi3
	strh r0, [r4]
	strh r0, [r5, 0xC]
	b _08171346
	.pool
_081712E8:
	ldrh r0, [r5, 0x1C]
	adds r0, 0x20
	strh r0, [r5, 0x1C]
	movs r0, 0x1C
	ldrsh r2, [r5, r0]
	adds r0, r4, 0
	adds r1, r2, 0
	movs r3, 0
	bl obj_id_set_rotscale
	ldrh r0, [r5, 0xC]
	ldrh r1, [r5, 0xE]
	adds r0, r1
	strh r0, [r5, 0xE]
	ldr r0, =gUnknown_02020630
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	negs r0, r0
	asrs r0, 8
	strh r0, [r1, 0x26]
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	ldr r0, =0x0000047f
	cmp r1, r0
	ble _0817137C
	b _08171346
	.pool
_0817132C:
	adds r0, r4, 0
	bl sub_80A7344
	ldr r1, =gUnknown_02020630
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_08171346:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _0817137C
	.pool
_08171354:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0xA
	ble _0817137C
	adds r0, r6, 0
	bl DestroyTask
	adds r0, r7, 0
	movs r1, 0x2
	bl StartObjectImageAnim
	movs r0, 0
	strh r0, [r7, 0x38]
	ldr r0, =sub_817138C
	str r0, [r7, 0x1C]
_0817137C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171240

	thumb_func_start sub_817138C
sub_817138C: @ 817138C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081713C6
	movs r1, 0
	strh r1, [r4, 0x34]
	movs r0, 0x28
	strh r0, [r4, 0x36]
	strh r1, [r4, 0x38]
	movs r0, 0
	movs r1, 0x28
	bl cosine
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	movs r0, 0x36
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl cosine
	negs r0, r0
	strh r0, [r4, 0x26]
	ldr r0, =sub_81713D0
	str r0, [r4, 0x1C]
_081713C6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817138C

	thumb_func_start sub_81713D0
sub_81713D0: @ 81713D0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0
	beq _081713E6
	cmp r1, 0x1
	beq _0817145A
	b _08171486
_081713E6:
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl cosine
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	adds r1, 0x4
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 24
	adds r1, r0
	strh r1, [r4, 0x38]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x3F
	ble _08171486
	ldrh r0, [r4, 0x36]
	subs r0, 0xA
	strh r0, [r4, 0x36]
	ldr r1, =0x00000101
	adds r0, r2, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 24
	cmp r0, 0x4
	bne _08171422
	movs r5, 0x1
_08171422:
	cmp r0, 0x2
	beq _08171442
	cmp r0, 0x2
	bgt _08171434
	cmp r0, 0x1
	beq _0817143A
	b _08171452
	.pool
_08171434:
	cmp r0, 0x3
	beq _0817144A
	b _08171452
_0817143A:
	movs r0, 0x38
	bl audio_play
	b _08171486
_08171442:
	movs r0, 0x39
	bl audio_play
	b _08171486
_0817144A:
	movs r0, 0x3A
	bl audio_play
	b _08171486
_08171452:
	movs r0, 0x3B
	bl audio_play
	b _08171486
_0817145A:
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	movs r2, 0x36
	ldrsh r1, [r4, r2]
	bl cosine
	negs r0, r0
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x38]
	subs r1, 0x4
	ldrh r2, [r4, 0x34]
	lsls r0, r2, 16
	asrs r0, 24
	subs r1, r0
	strh r1, [r4, 0x38]
	lsls r1, 16
	cmp r1, 0
	bgt _08171486
	strh r5, [r4, 0x38]
	ldr r0, =0xffffff00
	ands r0, r2
	strh r0, [r4, 0x34]
_08171486:
	cmp r5, 0
	beq _081714CA
	movs r5, 0
	strh r5, [r4, 0x34]
	movs r0, 0x40
	movs r1, 0x28
	bl cosine
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
	strh r5, [r4, 0x26]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _081714C0
	strh r5, [r4, 0x38]
	ldr r0, =sub_81717B4
	str r0, [r4, 0x1C]
	b _081714CA
	.pool
_081714C0:
	ldr r0, =sub_81714D4
	str r0, [r4, 0x1C]
	movs r0, 0x1
	strh r0, [r4, 0x36]
	strh r5, [r4, 0x38]
_081714CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81713D0

	thumb_func_start sub_81714D4
sub_81714D4: @ 81714D4
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	movs r5, 0
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _08171510
	strh r5, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strh r5, [r0, 0xC]
	ldr r0, =sub_8171520
	str r0, [r4, 0x1C]
	movs r0, 0x17
	bl audio_play
_08171510:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81714D4

	thumb_func_start sub_8171520
sub_8171520: @ 8171520
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x34]
	movs r1, 0xFF
	ands r1, r0
	cmp r1, 0x6
	bls _08171530
	b _08171768
_08171530:
	lsls r0, r1, 2
	ldr r1, =_08171540
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08171540:
	.4byte _0817155C
	.4byte _081715AE
	.4byte _081715F4
	.4byte _08171654
	.4byte _081716A4
	.4byte _08171708
	.4byte _08171768
_0817155C:
	ldr r1, =gUnknown_020244D0
	ldr r5, [r1]
	ldr r2, [r5, 0x8]
	ldrh r3, [r2, 0xC]
	movs r6, 0xC
	ldrsh r0, [r2, r6]
	adds r6, r1, 0
	cmp r0, 0xFF
	ble _08171584
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldr r1, [r5, 0x8]
	ldrb r0, [r1, 0xC]
	strh r0, [r1, 0xC]
	b _0817158A
	.pool
_08171584:
	adds r0, r3, 0
	adds r0, 0xB0
	strh r0, [r2, 0xC]
_0817158A:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0x7
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xE
	bhi _081715AC
	b _081717AE
_081715AC:
	b _08171644
_081715AE:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _08171660
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bge _081715EA
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80082B8
	b _081717AE
_081715EA:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80082B8
	b _081717AE
_081715F4:
	ldr r1, =gUnknown_020244D0
	ldr r5, [r1]
	ldr r2, [r5, 0x8]
	ldrh r3, [r2, 0xC]
	movs r6, 0xC
	ldrsh r0, [r2, r6]
	adds r6, r1, 0
	cmp r0, 0xFF
	ble _0817161C
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldr r1, [r5, 0x8]
	ldrb r0, [r1, 0xC]
	strh r0, [r1, 0xC]
	b _08171622
	.pool
_0817161C:
	adds r0, r3, 0
	adds r0, 0xB0
	strh r0, [r2, 0xC]
_08171622:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0xC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x18
	bhi _08171644
	b _081717AE
_08171644:
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	strh r3, [r0, 0xC]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	strh r3, [r4, 0x38]
	b _081717AE
_08171654:
	ldrh r0, [r4, 0x38]
	adds r1, r0, 0x1
	strh r1, [r4, 0x38]
	lsls r0, 16
	cmp r0, 0
	bge _0817166E
_08171660:
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	b _081717AE
_0817166E:
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bge _0817169C
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_80082B8
	b _081716A4
_0817169C:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80082B8
_081716A4:
	ldr r1, =gUnknown_020244D0
	ldr r5, [r1]
	ldr r2, [r5, 0x8]
	ldrh r3, [r2, 0xC]
	movs r6, 0xC
	ldrsh r0, [r2, r6]
	adds r6, r1, 0
	cmp r0, 0xFF
	ble _081716CC
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x24]
	adds r0, r1
	strh r0, [r4, 0x24]
	ldr r1, [r5, 0x8]
	ldrb r0, [r1, 0xC]
	strh r0, [r1, 0xC]
	b _081716D2
	.pool
_081716CC:
	adds r0, r3, 0
	adds r0, 0xB0
	strh r0, [r2, 0xC]
_081716D2:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r4, 0x38]
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, 0x38]
	adds r0, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	bls _081717AE
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	strh r3, [r0, 0xC]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	strh r3, [r4, 0x38]
	ldrh r0, [r4, 0x36]
	negs r0, r0
	strh r0, [r4, 0x36]
	b _081717AE
_08171708:
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6, 0
	ldrh r1, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r1, r0, 24
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r1, r0
	bne _08171740
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_81717B4
	str r0, [r4, 0x1C]
	b _081717AE
	.pool
_08171740:
	cmp r0, 0x4
	bne _08171754
	cmp r1, 0x3
	bne _08171754
	ldr r0, =sub_81717D8
	str r0, [r4, 0x1C]
	b _0817175A
	.pool
_08171754:
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
_0817175A:
	adds r2, r4, 0
	adds r2, 0x2C
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	b _081717AE
_08171768:
	ldrh r0, [r4, 0x38]
	adds r0, 0x1
	strh r0, [r4, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _081717AE
	movs r0, 0
	strh r0, [r4, 0x38]
	ldrh r1, [r4, 0x34]
	ldr r0, =0xffffff00
	ands r0, r1
	strh r0, [r4, 0x34]
	adds r0, r4, 0
	movs r1, 0x3
	bl StartObjectRotScalAnim
	movs r6, 0x36
	ldrsh r0, [r4, r6]
	cmp r0, 0
	bge _081717A0
	adds r0, r4, 0
	movs r1, 0x2
	bl StartObjectRotScalAnim
	b _081717A8
	.pool
_081717A0:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
_081717A8:
	movs r0, 0x17
	bl audio_play
_081717AE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8171520

	thumb_func_start sub_81717B4
sub_81717B4: @ 81717B4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x38]
	adds r0, 0x1
	strh r0, [r1, 0x38]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1F
	bne _081717CE
	movs r0, 0
	strh r0, [r1, 0x38]
	ldr r0, =sub_8171AE4
	str r0, [r1, 0x1C]
_081717CE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81717B4

	thumb_func_start sub_81717D8
sub_81717D8: @ 81717D8
	adds r3, r0, 0
	adds r3, 0x2C
	ldrb r1, [r3]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r3]
	ldr r1, =sub_81717F8
	str r1, [r0, 0x1C]
	movs r1, 0
	strh r1, [r0, 0x34]
	strh r1, [r0, 0x36]
	strh r1, [r0, 0x38]
	bx lr
	.pool
	thumb_func_end sub_81717D8

	thumb_func_start sub_81717F8
sub_81717F8: @ 81717F8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r7, =gUnknown_02038437
	ldrh r0, [r6, 0x36]
	adds r0, 0x1
	movs r1, 0
	mov r8, r1
	strh r0, [r6, 0x36]
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0x28
	bne _0817183C
	movs r0, 0xFE
	bl audio_play
	ldrb r1, [r6, 0x5]
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r1
	movs r1, 0x6
	movs r2, 0
	bl BlendPalettes
	adds r0, r6, 0
	bl sub_81719EC
	b _081718BC
	.pool
_0817183C:
	cmp r1, 0x3C
	bne _0817185A
	ldrb r1, [r6, 0x5]
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r1
	mov r1, r8
	str r1, [sp]
	movs r1, 0x2
	movs r2, 0x6
	movs r3, 0
	bl BeginNormalPaletteFade
	b _081718BC
_0817185A:
	cmp r1, 0x5F
	bne _08171880
	ldr r0, =gUnknown_020244B9
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	bl sub_8072A88
	bl m4aMPlayAllStop
	ldr r0, =0x00000213
	bl audio_play
	b _081718BC
	.pool
_08171880:
	ldr r0, =0x0000013b
	cmp r1, r0
	bne _081718BC
	ldr r5, =gUnknown_02020630
	ldr r4, =gUnknown_020241E4
	ldrb r0, [r7]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	ldrb r0, [r7]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl RemoveObjectAndFreeTiles
	mov r0, r8
	strh r0, [r6, 0x2E]
	ldr r0, =sub_81718D8
	str r0, [r6, 0x1C]
_081718BC:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81717F8

	thumb_func_start sub_81718D8
sub_81718D8: @ 81718D8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08171944
	cmp r0, 0x1
	bgt _081718F0
	cmp r0, 0
	beq _081718F6
	b _0817198A
_081718F0:
	cmp r0, 0x2
	beq _08171976
	b _0817198A
_081718F6:
	strh r0, [r4, 0x30]
	strh r0, [r4, 0x32]
	ldrb r1, [r4, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x1]
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, [r4, 0x14]
	ldrh r0, [r0, 0x2]
	bl IndexOfObjectPaletteTag
	lsls r0, 24
	lsrs r0, 24
	adds r0, 0x10
	movs r1, 0x1
	lsls r1, r0
	ldr r0, =0x00007fff
	str r0, [sp]
	adds r0, r1, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08171982
	.pool
_08171944:
	ldrh r0, [r4, 0x30]
	adds r1, r0, 0x1
	strh r1, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	ble _081719B0
	movs r0, 0
	strh r0, [r4, 0x30]
	ldrh r2, [r4, 0x32]
	adds r2, 0x1
	strh r2, [r4, 0x32]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _081719B0
	b _08171982
_08171976:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08171982:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081719B0
_0817198A:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _081719B0
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	strh r5, [r4, 0x2E]
	ldr r0, =sub_81719C0
	str r0, [r4, 0x1C]
_081719B0:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81718D8

	thumb_func_start sub_81719C0
sub_81719C0: @ 81719C0
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x2E]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _081719D8
	ldr r0, =0x0000ffff
	strh r0, [r4, 0x2E]
	b _081719E4
	.pool
_081719D8:
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_081719E4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81719C0

	thumb_func_start sub_81719EC
sub_81719EC: @ 81719EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	adds r1, r6, 0
	adds r1, 0x43
	ldrb r0, [r1]
	cmp r0, 0
	beq _08171A0C
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	b _08171A14
_08171A0C:
	movs r0, 0
	mov r8, r0
	movs r0, 0x1
	strb r0, [r1]
_08171A14:
	movs r0, 0x4
	bl sub_8171D60
	movs r7, 0
	ldr r2, =gUnknown_02020630
	mov r9, r2
	movs r0, 0x1C
	add r0, r9
	mov r10, r0
_08171A26:
	movs r2, 0x20
	ldrsh r1, [r6, r2]
	movs r0, 0x22
	ldrsh r2, [r6, r0]
	ldr r0, =gUnknown_085E5250
	mov r3, r8
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _08171A82
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	mov r2, r9
	adds r5, r4, r2
	movs r0, 0x18
	strh r0, [r5, 0x2E]
	ldr r0, =gUnknown_085E5088
	lsls r1, r7, 2
	adds r1, r0
	movs r0, 0
	ldrsb r0, [r1, r0]
	ldrh r2, [r6, 0x20]
	adds r0, r2
	strh r0, [r5, 0x32]
	movs r0, 0x1
	ldrsb r0, [r1, r0]
	ldrh r2, [r6, 0x22]
	adds r0, r2
	strh r0, [r5, 0x36]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	strh r0, [r5, 0x38]
	adds r0, r5, 0
	bl sub_80A68D4
	add r4, r10
	ldr r0, =sub_8171AAC
	str r0, [r4]
	ldr r0, =gUnknown_085E51B4
	ldrb r1, [r0, 0x4]
	adds r0, r5, 0
	bl StartObjectImageAnim
_08171A82:
	adds r7, 0x1
	cmp r7, 0x2
	bls _08171A26
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81719EC

	thumb_func_start sub_8171AAC
sub_8171AAC: @ 8171AAC
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsrs r1, r2, 2
	movs r0, 0x1
	eors r1, r0
	ands r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _08171ADC
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_08171ADC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8171AAC

	thumb_func_start sub_8171AE4
sub_8171AE4: @ 8171AE4
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0x1
	bl StartObjectImageAnim
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectRotScalAnim
	ldr r0, =sub_8171BAC
	str r0, [r4, 0x1C]
	ldr r0, =gUnknown_02024208
	ldrh r0, [r0]
	bl ball_number_to_ball_processing_index
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xB
	bgt _08171B36
	cmp r5, 0
	blt _08171B36
	ldrh r0, [r4, 0x20]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r4, 0x22]
	subs r1, 0x5
	lsls r1, 24
	lsrs r1, 24
	str r5, [sp]
	movs r2, 0x1
	movs r3, 0x1C
	bl sub_8171D98
	ldr r0, =gUnknown_02038437
	ldrb r1, [r0]
	movs r0, 0x1
	movs r2, 0xE
	adds r3, r5, 0
	bl sub_81729E8
_08171B36:
	ldr r6, =gUnknown_02020630
	ldr r5, =gUnknown_020241E4
	ldr r4, =gUnknown_02038437
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x1
	bl StartObjectRotScalAnim
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl AnimateObject
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x80
	lsls r1, 5
	strh r1, [r0, 0x30]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171AE4

	thumb_func_start sub_8171BAC
sub_8171BAC: @ 8171BAC
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08171BCA
	adds r2, r7, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08171BCA:
	ldr r4, =gUnknown_02020630
	ldr r3, =gUnknown_020241E4
	ldr r2, =gUnknown_02038437
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r4
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _08171C04
	adds r0, r1, 0
	movs r1, 0
	bl StartObjectRotScalAnim
	movs r5, 0x1
	b _08171C24
	.pool
_08171C04:
	ldr r6, =0xfffffee0
	adds r0, r6, 0
	ldrh r6, [r1, 0x30]
	adds r0, r6
	strh r0, [r1, 0x30]
	ldrb r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r1, 0x26]
_08171C24:
	adds r0, r7, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08171C8A
	cmp r5, 0
	beq _08171C8A
	ldr r4, =gUnknown_02020630
	ldr r3, =gUnknown_020241E4
	ldr r2, =gUnknown_02038437
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r6, 0
	movs r5, 0
	strh r5, [r0, 0x26]
	ldrb r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x9]
	lsls r1, 30
	adds r2, 0x3E
	lsrs r1, 31
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	strh r5, [r7, 0x2E]
	ldr r0, =sub_81719C0
	str r0, [r7, 0x1C]
	ldr r0, =gUnknown_020244B9
	strb r6, [r0]
	movs r0, 0x1
	bl sub_8072A88
_08171C8A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171BAC

	thumb_func_start sub_8171CAC
sub_8171CAC: @ 8171CAC
	push {r4,lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x24]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r2, 0x20]
	ldrh r0, [r2, 0x26]
	ldrh r3, [r2, 0x22]
	adds r0, r3
	strh r0, [r2, 0x22]
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	ldr r4, =sub_8171CE8
	movs r3, 0
	movs r1, 0x5
	adds r0, r2, 0
	adds r0, 0x38
_08171CD0:
	strh r3, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08171CD0
	str r4, [r2, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171CAC

	thumb_func_start sub_8171CE8
sub_8171CE8: @ 8171CE8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 4
	adds r2, r0, 0
	ldrh r1, [r4, 0x2E]
	adds r2, r1
	movs r0, 0xD0
	lsls r0, 3
	adds r3, r0, 0
	ldrh r1, [r4, 0x30]
	adds r3, r1
	lsls r1, r3, 16
	asrs r1, 24
	ldrh r0, [r4, 0x24]
	subs r0, r1
	strh r0, [r4, 0x24]
	lsls r0, r2, 16
	asrs r0, 24
	ldrh r1, [r4, 0x26]
	adds r0, r1
	strh r0, [r4, 0x26]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r4, 0x2E]
	ands r3, r0
	strh r3, [r4, 0x30]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	adds r0, r1
	cmp r0, 0xA0
	bgt _08171D3E
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	movs r2, 0x24
	ldrsh r1, [r4, r2]
	adds r0, r1
	movs r1, 0x8
	negs r1, r1
	cmp r0, r1
	bge _08171D52
_08171D3E:
	movs r0, 0
	strh r0, [r4, 0x2E]
	ldr r0, =sub_81719C0
	str r0, [r4, 0x1C]
	ldr r1, =gUnknown_020244B9
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	bl sub_8072A88
_08171D52:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171CE8

	thumb_func_start sub_8171D60
sub_8171D60: @ 8171D60
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, =gUnknown_085E5094
	lsrs r5, r0, 21
	adds r4, r5, r1
	ldrh r0, [r4, 0x6]
	bl GetObjectTileRangeStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _08171D86
	adds r0, r4, 0
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_085E50F4
	adds r0, r5, r0
	bl LoadCompressedObjectPaletteUsingHeap
_08171D86:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171D60

	thumb_func_start sub_8171D98
sub_8171D98: @ 8171D98
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	mov r8, r1
	mov r9, r2
	mov r10, r3
	ldr r5, [sp, 0x1C]
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl sub_8171D60
	ldr r1, =gUnknown_085E51C0
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x5
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	strh r6, [r0, 0xA]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	mov r1, r10
	strh r1, [r0, 0x10]
	strh r5, [r0, 0x26]
	movs r0, 0xF
	bl audio_play
	adds r0, r4, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8171D98

	thumb_func_start sub_8171E20
sub_8171E20: @ 8171E20
	push {lr}
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08171E3E
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	ldrb r0, [r1, 0xA]
	adds r0, 0x1
	strb r0, [r1, 0xA]
_08171E3E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171E20

	thumb_func_start sub_8171E50
sub_8171E50: @ 8171E50
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r6, r0, r1
	ldrh r0, [r6, 0x26]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r2, 0x8
	ldrsh r0, [r6, r2]
	adds r2, r1, 0
	cmp r0, 0xF
	bgt _08171F48
	ldrb r1, [r6, 0xA]
	ldrb r2, [r6, 0xC]
	ldrb r4, [r6, 0xE]
	mov r9, r4
	ldrb r3, [r6, 0x10]
	ldr r4, [sp]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r4, =gUnknown_085E51F0
	adds r0, r4
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0x40
	beq _08171EEC
	bl sub_8171E20
	mov r0, r10
	lsls r4, r0, 4
	add r4, r10
	lsls r4, 2
	ldr r5, =gUnknown_02020630
	adds r7, r4, r5
	ldr r0, =gUnknown_085E51B4
	ldr r1, [sp]
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r7, 0
	bl StartObjectImageAnim
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_8171F68
	str r0, [r4]
	movs r0, 0x3
	mov r2, r9
	ands r2, r0
	lsls r2, 2
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r7, 0x5]
	ldrb r0, [r6, 0x8]
	cmp r0, 0x7
	bls _08171EE8
	subs r0, 0x8
	lsls r0, 24
	lsrs r0, 24
_08171EE8:
	lsls r0, 5
	strh r0, [r7, 0x2E]
_08171EEC:
	ldr r0, =gTasks
	mov r4, r8
	lsls r1, r4, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	adds r2, r0, 0
	cmp r1, 0xF
	bne _08171F48
	ldr r0, =gUnknown_030022C0
	ldr r4, =0x00000439
	adds r0, r4
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08171F22
	ldr r0, =gUnknown_02020630
	mov r2, r10
	lsls r1, r2, 4
	add r1, r10
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08171F22:
	mov r0, r8
	bl DestroyTask
	b _08171F58
	.pool
_08171F48:
	mov r4, r8
	lsls r0, r4, 2
	add r0, r8
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
_08171F58:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8171E50

	thumb_func_start sub_8171F68
sub_8171F68: @ 8171F68
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x30]
	movs r3, 0x30
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _08171F80
	ldr r0, =sub_8171F88
	str r0, [r1, 0x1C]
	b _08171F84
	.pool
_08171F80:
	subs r0, r2, 0x1
	strh r0, [r1, 0x30]
_08171F84:
	pop {r0}
	bx r0
	thumb_func_end sub_8171F68

	thumb_func_start sub_8171F88
sub_8171F88: @ 8171F88
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl sine
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl cosine
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0x2
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x32
	bne _08171FBC
	adds r0, r4, 0
	bl sub_8172944
_08171FBC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8171F88

	thumb_func_start sub_8171FC4
sub_8171FC4: @ 8171FC4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x4]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0x8]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0xC]
	movs r7, 0
	ldr r3, =gUnknown_02020630
	mov r10, r3
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 3
	str r0, [sp, 0x10]
_0817200A:
	ldr r0, =gUnknown_085E51F0
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817206A
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r3, r10
	adds r5, r4, r3
	ldr r0, =gUnknown_085E51B4
	add r0, r8
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0xA
	strh r0, [r5, 0x36]
	movs r0, 0x2
	strh r0, [r5, 0x38]
	movs r0, 0x1
	strh r0, [r5, 0x3A]
_0817206A:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _0817200A
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172092
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172092:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8171FC4

	thumb_func_start sub_81720C8
sub_81720C8: @ 81720C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x4]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0x8]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0xC]
	movs r7, 0
	ldr r3, =gUnknown_02020630
	mov r10, r3
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 3
	str r0, [sp, 0x10]
_0817210E:
	ldr r0, =gUnknown_085E51F0
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817216E
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r3, r10
	adds r5, r4, r3
	ldr r0, =gUnknown_085E51B4
	add r0, r8
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0xA
	strh r0, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	movs r0, 0x2
	strh r0, [r5, 0x3A]
_0817216E:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _0817210E
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172196
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172196:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81720C8

	thumb_func_start sub_81721CC
sub_81721CC: @ 81721CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r0, 0xA]
	str r2, [sp]
	ldrb r3, [r0, 0xC]
	str r3, [sp, 0x4]
	ldrb r2, [r0, 0xE]
	str r2, [sp, 0x8]
	ldrb r0, [r0, 0x10]
	str r0, [sp, 0xC]
	movs r7, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	str r0, [sp, 0x10]
	ldr r3, =gUnknown_02020630
	mov r8, r3
	ldr r0, =gUnknown_085E51B4
	adds r1, r0
	mov r10, r1
_08172212:
	ldr r0, =gUnknown_085E51F0
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817226E
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r2, r8
	adds r5, r4, r2
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0x4
	strh r0, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	strh r0, [r5, 0x3A]
_0817226E:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _08172212
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172296
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172296:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81721CC

	thumb_func_start sub_81722CC
sub_81722CC: @ 81722CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x4]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0x8]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0xC]
	movs r7, 0
	ldr r3, =gUnknown_02020630
	mov r10, r3
	mov r1, r8
	lsls r0, r1, 1
	add r0, r8
	lsls r0, 3
	str r0, [sp, 0x10]
_08172312:
	ldr r0, =gUnknown_085E51F0
	ldr r2, [sp, 0x10]
	adds r0, r2, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08172376
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r3, r10
	adds r5, r4, r3
	ldr r0, =gUnknown_085E51B4
	add r0, r8
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 3
	adds r0, r7
	strh r0, [r5, 0x2E]
	movs r0, 0x5
	strh r0, [r5, 0x36]
	movs r0, 0x1
	strh r0, [r5, 0x38]
	strh r0, [r5, 0x3A]
_08172376:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x9
	bls _08172312
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0817239E
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_0817239E:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81722CC

	thumb_func_start sub_81723D4
sub_81723D4: @ 81723D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r0, r2, r0
	lsls r0, 3
	adds r3, r0, r1
	ldrh r1, [r3, 0x16]
	movs r4, 0x16
	ldrsh r0, [r3, r4]
	cmp r0, 0
	beq _08172404
	subs r0, r1, 0x1
	strh r0, [r3, 0x16]
	b _081724D6
	.pool
_08172404:
	ldrh r0, [r3, 0x26]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r3, 0xA]
	str r1, [sp]
	ldrb r4, [r3, 0xC]
	str r4, [sp, 0x4]
	ldrb r1, [r3, 0xE]
	str r1, [sp, 0x8]
	ldrb r3, [r3, 0x10]
	str r3, [sp, 0xC]
	movs r7, 0
	str r2, [sp, 0x14]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	str r1, [sp, 0x10]
	ldr r3, =gUnknown_02020630
	mov r9, r3
	ldr r1, =gUnknown_085E51B4
	adds r0, r1
	mov r10, r0
_08172430:
	ldr r0, =gUnknown_085E51F0
	ldr r4, [sp, 0x10]
	adds r0, r4, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _0817248C
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r0, r9
	adds r5, r4, r0
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0x8
	strh r0, [r5, 0x36]
	movs r0, 0x2
	strh r0, [r5, 0x38]
	strh r0, [r5, 0x3A]
_0817248C:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _08172430
	ldr r0, =gTasks
	ldr r1, [sp, 0x14]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	movs r0, 0x8
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0x2
	bne _081724D6
	ldr r0, =gUnknown_030022C0
	ldr r4, =0x00000439
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _081724D0
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_081724D0:
	mov r0, r8
	bl DestroyTask
_081724D6:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81723D4

	thumb_func_start sub_8172508
sub_8172508: @ 8172508
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x30
	ldrsh r1, [r4, r2]
	bl sine
	strh r0, [r4, 0x24]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	movs r2, 0x32
	ldrsh r1, [r4, r2]
	bl cosine
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x36]
	ldrh r1, [r4, 0x2E]
	adds r0, r1
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x2E]
	ldrh r0, [r4, 0x38]
	ldrh r2, [r4, 0x30]
	adds r0, r2
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x32]
	adds r0, r1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x34]
	adds r0, 0x1
	strh r0, [r4, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _08172558
	adds r0, r4, 0
	bl sub_8172944
_08172558:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8172508

	thumb_func_start sub_8172560
sub_8172560: @ 8172560
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r0, 0xA]
	str r2, [sp]
	ldrb r3, [r0, 0xC]
	str r3, [sp, 0x4]
	ldrb r2, [r0, 0xE]
	str r2, [sp, 0x8]
	ldrb r0, [r0, 0x10]
	str r0, [sp, 0xC]
	movs r7, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	str r0, [sp, 0x10]
	ldr r3, =gUnknown_02020630
	mov r8, r3
	ldr r0, =gUnknown_085E51B4
	adds r1, r0
	mov r10, r1
_081725A6:
	ldr r0, =gUnknown_085E51F0
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _081725FE
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r2, r8
	adds r5, r4, r2
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_817265C
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 2
	adds r0, r7
	strh r0, [r5, 0x2E]
_081725FE:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xB
	bls _081725A6
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172626
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_08172626:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172560

	thumb_func_start sub_817265C
sub_817265C: @ 817265C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	bl sine
	strh r0, [r5, 0x24]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	adds r0, r4, 0
	bl sine
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl cosine
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x6
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _081726B4
	adds r0, r5, 0
	bl sub_8172944
_081726B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817265C

	thumb_func_start sub_81726BC
sub_81726BC: @ 81726BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	ldr r0, =gTasks
	ldr r2, [sp]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldrb r3, [r1, 0xA]
	str r3, [sp, 0x4]
	ldrb r0, [r1, 0xC]
	str r0, [sp, 0x8]
	ldrb r2, [r1, 0xE]
	str r2, [sp, 0xC]
	ldrb r1, [r1, 0x10]
	str r1, [sp, 0x10]
	movs r3, 0
	mov r8, r3
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 3
	str r0, [sp, 0x14]
_08172700:
	movs r7, 0
	movs r2, 0x1
	add r2, r8
	mov r10, r2
_08172708:
	ldr r0, =gUnknown_085E51F0
	ldr r3, [sp, 0x14]
	adds r0, r3, r0
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08172790
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	ldr r0, =gUnknown_02020630
	adds r5, r4, r0
	ldr r0, =gUnknown_085E51B4
	add r0, r9
	ldrb r1, [r0]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r1, =gUnknown_0202064C
	adds r4, r1
	ldr r0, =sub_8172508
	str r0, [r4]
	movs r0, 0x3
	ldr r1, [sp, 0xC]
	ands r1, r0
	lsls r1, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r2, r3, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
	movs r0, 0x8
	strh r0, [r5, 0x36]
	mov r0, r8
	cmp r0, 0
	bne _08172788
	movs r0, 0x2
	strh r0, [r5, 0x38]
	movs r0, 0x1
	b _0817278E
	.pool
_08172788:
	movs r0, 0x1
	strh r0, [r5, 0x38]
	movs r0, 0x2
_0817278E:
	strh r0, [r5, 0x3A]
_08172790:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _08172708
	mov r1, r10
	lsls r0, r1, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x1
	bls _08172700
	ldr r0, =gUnknown_030022C0
	ldr r2, =0x00000439
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081727C4
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_081727C4:
	ldr r0, [sp]
	bl DestroyTask
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81726BC

	thumb_func_start sub_81727E8
sub_81727E8: @ 81727E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x26]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r0, 0xA]
	str r2, [sp]
	ldrb r3, [r0, 0xC]
	str r3, [sp, 0x4]
	ldrb r2, [r0, 0xE]
	str r2, [sp, 0x8]
	ldrb r0, [r0, 0x10]
	str r0, [sp, 0xC]
	movs r7, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	str r0, [sp, 0x10]
	ldr r3, =gUnknown_02020630
	mov r8, r3
	ldr r0, =gUnknown_085E51B4
	adds r1, r0
	mov r10, r1
_0817282E:
	ldr r0, =gUnknown_085E51F0
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r1, [sp]
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0xC]
	bl AddObjectToFront
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x40
	beq _08172880
	bl sub_8171E20
	lsls r4, r6, 4
	adds r4, r6
	lsls r4, 2
	mov r2, r8
	adds r5, r4, r2
	mov r3, r10
	ldrb r1, [r3]
	adds r0, r5, 0
	bl StartObjectImageAnim
	ldr r0, =gUnknown_0202064C
	adds r4, r0
	ldr r0, =sub_81728E0
	str r0, [r4]
	movs r0, 0x3
	ldr r2, [sp, 0x8]
	ands r2, r0
	lsls r2, 2
	ldrb r0, [r5, 0x5]
	movs r3, 0xD
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	lsls r0, r7, 5
	strh r0, [r5, 0x2E]
_08172880:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x7
	bls _0817282E
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081728A8
	ldr r0, =gUnknown_02020630
	lsls r1, r6, 4
	adds r1, r6
	lsls r1, 2
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x3C]
_081728A8:
	mov r0, r9
	bl DestroyTask
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81727E8

	thumb_func_start sub_81728E0
sub_81728E0: @ 81728E0
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r5, r1]
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	bl sine
	strh r0, [r5, 0x24]
	movs r0, 0x2E
	ldrsh r4, [r5, r0]
	ldrh r1, [r5, 0x2E]
	movs r0, 0x3F
	ands r0, r1
	movs r2, 0x32
	ldrsh r1, [r5, r2]
	bl sine
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl cosine
	strh r0, [r5, 0x26]
	ldrh r0, [r5, 0x2E]
	adds r0, 0xA
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r5, 0x2E]
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	ldrh r0, [r5, 0x32]
	adds r0, 0x1
	strh r0, [r5, 0x32]
	ldrh r0, [r5, 0x34]
	adds r0, 0x1
	strh r0, [r5, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x33
	bne _0817293C
	adds r0, r5, 0
	bl sub_8172944
_0817293C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81728E0

	thumb_func_start sub_8172944
sub_8172944: @ 8172944
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r0, =gUnknown_030022C0
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08172970
	movs r1, 0x3C
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	bne _081729CA
	adds r0, r7, 0
	bl RemoveObjectAndFreeResources
	b _081729E2
	.pool
_08172970:
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r1, [r0, 0x8]
	ldrb r0, [r1, 0xA]
	subs r0, 0x1
	strb r0, [r1, 0xA]
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	bne _081729DC
	movs r4, 0
	ldr r5, =gUnknown_085E51C0
	b _08172998
	.pool
_08172994:
	adds r5, 0x4
	adds r4, 0x1
_08172998:
	cmp r4, 0xB
	bgt _081729AA
	ldr r0, [r5]
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08172994
_081729AA:
	cmp r4, 0xC
	bne _081729CA
	movs r6, 0
	ldr r5, =gUnknown_085E5094
	ldr r4, =gUnknown_085E50F4
_081729B4:
	ldrh r0, [r5, 0x6]
	bl FreeObjectTilesByTag
	ldrh r0, [r4, 0x4]
	bl FreeObjectPaletteByTag
	adds r5, 0x8
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0xB
	ble _081729B4
_081729CA:
	adds r0, r7, 0
	bl RemoveObjectAndFreeTiles
	b _081729E2
	.pool
_081729DC:
	adds r0, r7, 0
	bl RemoveObjectAndFreeTiles
_081729E2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8172944

	thumb_func_start sub_81729E8
sub_81729E8: @ 81729E8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	mov r9, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r3, 24
	lsrs r7, r3, 24
	ldr r0, =sub_8172AB0
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r5, r0, r1
	strh r7, [r5, 0x26]
	strh r6, [r5, 0xE]
	mov r0, r9
	strh r0, [r5, 0x1C]
	mov r1, r9
	lsrs r0, r1, 16
	strh r0, [r5, 0x1E]
	cmp r4, 0
	bne _08172A58
	lsls r0, r6, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 16
	ldr r2, =gUnknown_085E5310
	lsls r1, r7, 1
	adds r1, r2
	ldrh r3, [r1]
	movs r1, 0x10
	movs r2, 0
	bl BlendPalette
	movs r0, 0x1
	strh r0, [r5, 0xA]
	b _08172A7E
	.pool
_08172A58:
	lsls r0, r6, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	ldr r2, =gUnknown_085E5310
	lsls r1, r7, 1
	adds r1, r2
	ldrh r3, [r1]
	movs r1, 0x10
	movs r2, 0x10
	bl BlendPalette
	movs r0, 0x10
	strh r0, [r5, 0x8]
	ldr r0, =0x0000ffff
	strh r0, [r5, 0xA]
	ldr r0, =sub_8172B40
	str r0, [r5]
_08172A7E:
	ldr r0, =0x00007fff
	str r0, [sp]
	mov r0, r9
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	mov r0, r8
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81729E8

	thumb_func_start sub_8172AB0
sub_8172AB0: @ 8172AB0
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x10
	bgt _08172B08
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r0, 16
	ldrb r2, [r4, 0x8]
	ldr r3, =gUnknown_085E5310
	lsls r1, 1
	adds r1, r3
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	b _08172B30
	.pool
_08172B08:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08172B30
	ldrh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	lsls r1, 16
	orrs r0, r1
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	adds r0, r5, 0
	bl DestroyTask
_08172B30:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172AB0

	thumb_func_start sub_8172B40
sub_8172B40: @ 8172B40
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08172B78
	ldr r0, =gTasks
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 3
	adds r4, r0
	ldrh r0, [r4, 0x1C]
	ldrh r1, [r4, 0x1E]
	lsls r1, 16
	orrs r0, r1
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =sub_8172B90
	str r0, [r4]
_08172B78:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172B40

	thumb_func_start sub_8172B90
sub_8172B90: @ 8172B90
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x26]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0x10
	bgt _08172BE4
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 20
	movs r3, 0x80
	lsls r3, 17
	adds r0, r3
	lsrs r0, 16
	ldrb r2, [r4, 0x8]
	ldr r3, =gUnknown_085E5310
	lsls r1, 1
	adds r1, r3
	ldrh r3, [r1]
	movs r1, 0x10
	bl BlendPalette
	ldrh r0, [r4, 0xA]
	ldrh r1, [r4, 0x8]
	adds r0, r1
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	b _08172BEA
	.pool
_08172BE4:
	adds r0, r2, 0
	bl DestroyTask
_08172BEA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8172B90

	thumb_func_start sub_8172BF0
sub_8172BF0: @ 8172BF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r0, =gUnknown_020241E4
	ldr r3, =gUnknown_02038436
	ldrb r2, [r3]
	adds r0, r2, r0
	ldrb r6, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r5, r0, r1
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _08172CC8
	cmp r0, 0x1
	bgt _08172C30
	cmp r0, 0
	beq _08172C36
	b _08172D8A
	.pool
_08172C30:
	cmp r0, 0x2
	beq _08172CDA
	b _08172D8A
_08172C36:
	ldr r0, =gUnknown_0203841E
	ldrh r0, [r0]
	strh r0, [r5, 0x1E]
	movs r2, 0xA0
	lsls r2, 3
	adds r0, r2, 0
	ldrh r4, [r5, 0x8]
	adds r0, r4
	strh r0, [r5, 0x8]
	ldrb r0, [r3]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	beq _08172C78
	ldr r2, =gUnknown_02020630
	lsls r3, r6, 4
	adds r1, r3, r6
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 24
	ldrh r4, [r1, 0x24]
	adds r0, r4
	strh r0, [r1, 0x24]
	adds r4, r3, 0
	b _08172C90
	.pool
_08172C78:
	ldr r3, =gUnknown_02020630
	lsls r4, r6, 4
	adds r2, r4, r6
	lsls r2, 2
	adds r2, r3
	ldrh r1, [r5, 0x8]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r2, r3, 0
_08172C90:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r3, r0, r1
	ldrb r0, [r3, 0x8]
	strh r0, [r3, 0x8]
	adds r0, r4, r6
	lsls r0, 2
	adds r0, r2
	movs r2, 0x20
	ldrsh r1, [r0, r2]
	movs r4, 0x24
	ldrsh r0, [r0, r4]
	adds r1, r0
	adds r1, 0x20
	movs r0, 0x98
	lsls r0, 1
	cmp r1, r0
	bls _08172D8A
	ldrh r0, [r3, 0x1C]
	adds r0, 0x1
	strh r0, [r3, 0x1C]
	b _08172D8A
	.pool
_08172CC8:
	ldrb r1, [r5, 0x1E]
	adds r0, r2, 0
	adds r2, r6, 0
	bl refresh_graphics_maybe
	ldrh r0, [r5, 0x1C]
	adds r0, 0x1
	strh r0, [r5, 0x1C]
	b _08172D8A
_08172CDA:
	movs r1, 0xA0
	lsls r1, 3
	adds r0, r1, 0
	ldrh r2, [r5, 0x8]
	adds r0, r2
	strh r0, [r5, 0x8]
	ldrb r0, [r3]
	bl battle_side_get_owner
	lsls r0, 24
	cmp r0, 0
	beq _08172D10
	ldr r0, =gUnknown_02020630
	lsls r3, r6, 4
	adds r2, r3, r6
	lsls r2, 2
	adds r2, r0
	ldrh r1, [r5, 0x8]
	lsls r1, 16
	asrs r1, 24
	ldrh r0, [r2, 0x24]
	subs r0, r1
	strh r0, [r2, 0x24]
	adds r4, r3, 0
	b _08172D28
	.pool
_08172D10:
	ldr r0, =gUnknown_02020630
	lsls r2, r6, 4
	adds r1, r2, r6
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r5, 0x8]
	lsls r0, 16
	asrs r0, 24
	ldrh r3, [r1, 0x24]
	adds r0, r3
	strh r0, [r1, 0x24]
	adds r4, r2, 0
_08172D28:
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x8]
	strh r1, [r0, 0x8]
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl battle_side_get_owner
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08172D68
	ldr r0, =gUnknown_02020630
	adds r1, r4, r6
	lsls r1, 2
	adds r1, r0
	movs r4, 0x24
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bgt _08172D7E
	movs r0, 0
	strh r0, [r1, 0x24]
	b _08172D84
	.pool
_08172D68:
	ldr r0, =gUnknown_02020630
	adds r1, r4, r6
	lsls r1, 2
	adds r1, r0
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _08172D7E
	strh r2, [r1, 0x24]
	movs r4, 0x1
	mov r8, r4
_08172D7E:
	mov r0, r8
	cmp r0, 0
	beq _08172D8A
_08172D84:
	adds r0, r7, 0
	bl move_anim_task_del
_08172D8A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172BF0

	thumb_func_start sub_8172D98
sub_8172D98: @ 8172D98
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08172E14
	cmp r0, 0x1
	bgt _08172DC0
	cmp r0, 0
	beq _08172DC6
	b _08172E84
	.pool
_08172DC0:
	cmp r0, 0x2
	beq _08172E4E
	b _08172E84
_08172DC6:
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	bl battle_get_per_side_status_permutated
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08172DE8
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	b _08172DF0
	.pool
_08172DE8:
	ldr r1, =0x00003f44
	movs r0, 0x50
	bl SetGpuReg
_08172DF0:
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _08172E84
	.pool
_08172E14:
	ldrh r0, [r4, 0xA]
	adds r1, r0, 0x1
	strh r1, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _08172E84
	movs r0, 0
	strh r0, [r4, 0xA]
	ldrh r2, [r4, 0x8]
	adds r2, 0x1
	strh r2, [r4, 0x8]
	lsls r1, r2, 8
	movs r0, 0x10
	subs r0, r2
	orrs r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x10
	bne _08172E84
	ldrh r0, [r4, 0x26]
	adds r0, 0x1
	strh r0, [r4, 0x26]
	b _08172E84
_08172E4E:
	ldr r1, =gUnknown_020241E4
	ldr r4, =gUnknown_02038436
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gUnknown_02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r0, =0x06010000
	adds r1, r0
	movs r2, 0x80
	lsls r2, 4
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	ldrb r0, [r4]
	bl sub_805E974
	adds r0, r5, 0
	bl move_anim_task_del
_08172E84:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172D98

	thumb_func_start sub_8172E9C
sub_8172E9C: @ 8172E9C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_0203841E
	ldr r1, =gUnknown_020244D0
	ldr r2, [r1]
	ldr r1, =gUnknown_02038436
	ldrb r1, [r1]
	ldr r2, [r2]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	lsls r1, 29
	lsrs r1, 31
	strh r1, [r3, 0xE]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172E9C

	thumb_func_start sub_8172ED0
sub_8172ED0: @ 8172ED0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02038437
	ldr r1, =gUnknown_0202420E
	ldrb r1, [r1]
	strb r1, [r2]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172ED0

	thumb_func_start sub_8172EF0
sub_8172EF0: @ 8172EF0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	mov r8, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0x1
	bl pokemon_getattr
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl pokemon_getattr
	adds r4, r0, 0
	adds r0, r6, 0
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	beq _08172FC8
	lsrs r0, r5, 16
	ldr r7, =0x0000ffff
	ands r5, r7
	eors r0, r5
	lsrs r1, r4, 16
	eors r0, r1
	ands r4, r7
	eors r0, r4
	cmp r0, 0x7
	bhi _08172F4E
	movs r0, 0x1
	mov r8, r0
_08172F4E:
	mov r0, r8
	cmp r0, 0
	beq _08172FC8
	ldr r0, =0x000027f9
	bl GetObjectTileRangeStartByTag
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r7
	bne _08172F6E
	ldr r0, =gUnknown_0852528C
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_08525B94
	bl LoadCompressedObjectPaletteUsingHeap
_08172F6E:
	ldr r5, =sub_8172FEC
	adds r0, r5, 0
	movs r1, 0xA
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gTasks
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	adds r2, r3
	movs r4, 0
	strh r6, [r2, 0x8]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	strh r6, [r1, 0x8]
	strh r4, [r2, 0xA]
	movs r0, 0x1
	strh r0, [r1, 0xA]
	b _08172FDE
	.pool
_08172FC8:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x1]
_08172FDE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172EF0

	thumb_func_start sub_8172FEC
sub_8172FEC: @ 8172FEC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r4, r0, r1
	ldrh r1, [r4, 0x22]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0x3B
	bgt _08173018
	adds r0, r1, 0x1
	strh r0, [r4, 0x22]
	b _08173190
	.pool
_08173018:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08173026
	b _08173190
_08173026:
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	beq _0817303A
	b _08173190
_0817303A:
	ldrb r0, [r4, 0x8]
	mov r8, r0
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r8
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08173074
	ldr r0, =gUnknown_085CE388
	adds r1, r5, 0
	movs r3, 0x5
	bl AddObjectToFront
	lsls r0, 24
	lsrs r5, r0, 24
	b _081730D6
	.pool
_08173074:
	cmp r0, 0
	blt _081730A8
	cmp r0, 0x3
	bgt _081730A8
	ldr r0, =gUnknown_085CE3A0
	adds r1, r5, 0
	movs r3, 0x5
	bl AddObjectToFront
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02020630
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	adds r2, r0
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x4
	b _081730C8
	.pool
_081730A8:
	ldr r0, =gUnknown_085CE3A0
	adds r1, r5, 0
	movs r3, 0x5
	bl AddObjectToFront
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_02020630
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	adds r2, r0
	ldrh r3, [r2, 0x4]
	lsls r1, r3, 22
	lsrs r1, 22
	adds r1, 0x5
_081730C8:
	ldr r4, =0x000003ff
	adds r0, r4, 0
	ands r1, r0
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, 0x4]
_081730D6:
	ldr r2, =gTasks
	lsls r1, r7, 2
	adds r0, r1, r7
	lsls r0, 3
	adds r6, r0, r2
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	mov r9, r1
	cmp r0, 0
	bne _08173118
	ldr r1, =gUnknown_02020630
	lsls r2, r5, 4
	adds r0, r2, r5
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81731FC
	str r1, [r0]
	adds r4, r2, 0
	b _08173160
	.pool
_08173118:
	ldr r3, =gUnknown_02020630
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x1C
	adds r0, r1, r0
	ldr r2, =sub_8173250
	str r2, [r0]
	adds r1, r3
	ldr r0, =0x0000ffe0
	strh r0, [r1, 0x24]
	movs r0, 0x20
	strh r0, [r1, 0x26]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	movs r1, 0x1E
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08173160
	mov r0, r8
	bl battle_side_get_owner
	lsls r0, 24
	movs r1, 0x3F
	cmp r0, 0
	bne _08173156
	movs r1, 0xC0
_08173156:
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x66
	bl audio_play_and_stuff
_08173160:
	ldr r1, =gUnknown_02020630
	adds r0, r4, r5
	lsls r0, 2
	adds r0, r1
	strh r7, [r0, 0x2E]
	ldr r1, =gTasks
	mov r2, r9
	adds r0, r2, r7
	lsls r0, 3
	adds r1, r0, r1
	ldrh r0, [r1, 0x1E]
	adds r0, 0x1
	strh r0, [r1, 0x1E]
	cmp r5, 0x40
	beq _08173184
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
_08173184:
	movs r4, 0x1E
	ldrsh r0, [r1, r4]
	cmp r0, 0x5
	bne _08173190
	ldr r0, =sub_81731B0
	str r0, [r1]
_08173190:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8172FEC

	thumb_func_start sub_81731B0
sub_81731B0: @ 81731B0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r1, r0, r1
	movs r2, 0x20
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _081731F0
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _081731EA
	ldrb r1, [r1, 0x8]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x1]
_081731EA:
	adds r0, r3, 0
	bl DestroyTask
_081731F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81731B0

	thumb_func_start sub_81731FC
sub_81731FC: @ 81731FC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x18
	bl sine
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x18
	bl cosine
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x30]
	adds r0, 0xC
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _08173246
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_08173246:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81731FC

	thumb_func_start sub_8173250
sub_8173250: @ 8173250
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	bgt _08173264
	adds r0, r1, 0x1
	strh r0, [r4, 0x30]
	b _081732A6
_08173264:
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldrh r1, [r4, 0x24]
	adds r1, 0x5
	strh r1, [r4, 0x24]
	ldrh r0, [r4, 0x26]
	subs r0, 0x5
	strh r0, [r4, 0x26]
	lsls r1, 16
	asrs r1, 16
	cmp r1, 0x20
	ble _081732A6
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x20]
	subs r1, 0x1
	strh r1, [r0, 0x20]
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_081732A6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173250

	thumb_func_start sub_81732B0
sub_81732B0: @ 81732B0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_085253AC
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_08525CB4
	bl LoadCompressedObjectPaletteUsingHeap
	ldr r0, =0x0000281d
	bl IndexOfObjectPaletteTag
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81732B0

	thumb_func_start sub_81732E4
sub_81732E4: @ 81732E4
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =0x0000281d
	adds r0, r5, 0
	bl FreeObjectTilesByTag
	adds r0, r5, 0
	bl FreeObjectPaletteByTag
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81732E4

	thumb_func_start sub_817330C
sub_817330C: @ 817330C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0
	bl sub_80A69CC
	movs r0, 0x1E
	strh r0, [r4, 0x2E]
	movs r0, 0x1
	bl battle_get_side_with_given_state
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_80A5C6C
	lsls r0, 24
	ldr r5, =gUnknown_0203841E
	lsrs r0, 24
	ldrh r1, [r5, 0x4]
	adds r0, r1
	strh r0, [r4, 0x32]
	movs r0, 0x1
	bl battle_get_side_with_given_state
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_80A5C6C
	lsls r0, 24
	lsrs r0, 24
	ldrh r5, [r5, 0x6]
	adds r0, r5
	strh r0, [r4, 0x36]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x38]
	adds r0, r4, 0
	bl sub_80A68D4
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039E84
	str r1, [r0]
	ldr r0, =sub_817339C
	str r0, [r4, 0x1C]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817330C

	thumb_func_start sub_817339C
sub_817339C: @ 817339C
	push {lr}
	adds r3, r0, 0
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gUnknown_02038436
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081733C0
	ldr r0, =sub_81733D4
	str r0, [r3, 0x1C]
_081733C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817339C

	thumb_func_start sub_81733D4
sub_81733D4: @ 81733D4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80A6900
	lsls r0, 24
	cmp r0, 0
	beq _081733F6
	movs r0, 0
	strh r0, [r4, 0x2E]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =sub_8173400
	str r0, [r4, 0x1C]
_081733F6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81733D4

	thumb_func_start sub_8173400
sub_8173400: @ 8173400
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, =gUnknown_02020630
	ldr r3, =gUnknown_020241E4
	ldr r2, =gUnknown_02038436
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 27
	cmp r0, 0
	bge _08173448
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	lsls r0, 16
	cmp r0, 0
	ble _08173448
	ldrb r0, [r2]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0
	bl StartObjectImageAnim
	adds r0, r4, 0
	bl move_anim_8072740
_08173448:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173400

	thumb_func_start sub_817345C
sub_817345C: @ 817345C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203841E
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08173478
	cmp r0, 0x1
	beq _0817348C
	b _081734A0
	.pool
_08173478:
	movs r0, 0
	bl battle_get_side_with_given_state
	ldr r1, =gUnknown_02038436
	strb r0, [r1]
	movs r0, 0x1
	b _08173498
	.pool
_0817348C:
	movs r0, 0x1
	bl battle_get_side_with_given_state
	ldr r1, =gUnknown_02038436
	strb r0, [r1]
	movs r0, 0
_08173498:
	bl battle_get_side_with_given_state
	ldr r1, =gUnknown_02038437
	strb r0, [r1]
_081734A0:
	adds r0, r4, 0
	bl move_anim_task_del
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817345C

	thumb_func_start sub_81734B4
sub_81734B4: @ 81734B4
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrh r1, [r0]
	cmp r1, 0x53
	bne _081734D4
	ldr r1, =gUnknown_0203841E
	movs r0, 0x1
	b _0817350C
	.pool
_081734D4:
	cmp r1, 0xFA
	bne _081734E4
	ldr r1, =gUnknown_0203841E
	movs r0, 0x2
	b _0817350C
	.pool
_081734E4:
	cmp r1, 0x80
	bne _081734F4
	ldr r1, =gUnknown_0203841E
	movs r0, 0x3
	b _0817350C
	.pool
_081734F4:
	movs r0, 0xA4
	lsls r0, 1
	cmp r1, r0
	bne _08173508
	ldr r1, =gUnknown_0203841E
	movs r0, 0x4
	b _0817350C
	.pool
_08173508:
	ldr r1, =gUnknown_0203841E
	movs r0, 0
_0817350C:
	strh r0, [r1]
	adds r0, r2, 0
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81734B4

	thumb_func_start sub_817351C
sub_817351C: @ 817351C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_02038436
	ldr r1, =gUnknown_020244D0
	ldr r2, [r1]
	ldr r1, [r2, 0x8]
	ldrh r1, [r1]
	strb r1, [r3]
	ldr r3, =gUnknown_02038437
	ldr r1, [r2, 0x8]
	ldrh r1, [r1]
	lsrs r1, 8
	strb r1, [r3]
	bl move_anim_task_del
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817351C

	thumb_func_start sub_817354C
sub_817354C: @ 817354C
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_817354C

	thumb_func_start sub_8173560
sub_8173560: @ 8173560
	push {lr}
	bl RunTasks
	bl RunTextPrinters
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_8173560

	thumb_func_start sub_817357C
sub_817357C: @ 817357C
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_030022C0
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	bls _08173590
	b _08173688
_08173590:
	lsls r0, 2
	ldr r1, =_081735A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081735A4:
	.4byte _081735B8
	.4byte _081735E8
	.4byte _081735EE
	.4byte _08173620
	.4byte _0817365C
_081735B8:
	movs r0, 0
	bl SetVBlankCallback
	bl sub_8174EC4
	ldr r4, =gUnknown_0203BCDC
	ldr r0, =0x00002014
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gUnknown_030022C0
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	b _08173688
	.pool
_081735E8:
	bl sub_8174F70
	b _08173642
_081735EE:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0xE2
	lsls r1, 3
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	bl sub_8174FAC
	ldr r0, =gUnknown_0203BCDC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1]
	b _08173642
	.pool
_08173620:
	bl sub_8175024
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08173688
	ldr r0, =sub_817354C
	bl SetVBlankCallback
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_08173642:
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08173688
	.pool
_0817365C:
	bl UpdatePaletteFade
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08173688
	ldr r0, =sub_8173560
	bl SetMainCallback2
	movs r0, 0xDA
	lsls r0, 1
	bl song_play_for_text
	movs r0, 0
	b _0817368A
	.pool
_08173688:
	movs r0, 0x1
_0817368A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_817357C

	thumb_func_start sub_8173694
sub_8173694: @ 8173694
	push {r4,lr}
	bl sub_817357C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081736C4
	ldr r0, =sub_817371C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	ldr r4, =gUnknown_0203BCD8
	movs r0, 0x78
	bl AllocZeroed
	str r0, [r4]
_081736C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173694

	thumb_func_start sub_81736D8
sub_81736D8: @ 81736D8
	push {r4,lr}
	bl sub_817357C
	lsls r0, 24
	cmp r0, 0
	bne _08173708
	ldr r0, =sub_817371C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	ldr r4, =gUnknown_0203BCD8
	movs r0, 0x78
	bl AllocZeroed
	str r0, [r4]
_08173708:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81736D8

	thumb_func_start sub_817371C
sub_817371C: @ 817371C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0xC]
	movs r7, 0
	ldr r0, =gUnknown_0203BCD8
	mov r9, r0
_08173740:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gUnknown_020244EC
	adds r6, r1, r0
	adds r0, r6, 0
	movs r1, 0xB
	bl pokemon_getattr
	adds r5, r0, 0
	cmp r5, 0
	beq _0817380C
	adds r0, r6, 0
	movs r1, 0x41
	bl pokemon_getattr
	mov r1, r9
	ldr r3, [r1]
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 2
	adds r3, r4
	ldr r2, =0x000001ff
	adds r1, r2, 0
	ands r0, r1
	ldrh r1, [r3, 0x8]
	ldr r5, =0xfffffe00
	adds r2, r5, 0
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x8]
	adds r0, r6, 0
	movs r1, 0x1
	bl pokemon_getattr
	mov r2, r9
	ldr r1, [r2]
	adds r1, r4
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0
	bl pokemon_getattr
	mov r5, r9
	ldr r1, [r5]
	adds r1, 0x4
	adds r1, r4
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0x38
	bl pokemon_getattr
	ldr r2, [r5]
	adds r2, r4
	lsls r0, 1
	ldrb r3, [r2, 0x9]
	movs r1, 0x1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x9]
	adds r0, r6, 0
	movs r1, 0x2
	mov r2, sp
	bl pokemon_getattr
	movs r2, 0
	mov r6, r8
	lsls r5, r6, 2
	ldr r3, =gUnknown_0203BCD8
_081737CA:
	ldr r0, [r3]
	adds r1, r2, r4
	adds r0, 0xA
	adds r0, r1
	mov r6, sp
	adds r1, r6, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9
	bls _081737CA
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r5, r2
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	b _08173840
	.pool
_0817380C:
	mov r6, r9
	ldr r3, [r6]
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 2
	adds r4, r3, r2
	ldrh r0, [r4, 0x8]
	ldr r6, =0xfffffe00
	adds r1, r6, 0
	ands r0, r1
	strh r0, [r4, 0x8]
	str r5, [r4]
	adds r3, 0x4
	adds r3, r2
	str r5, [r3]
	ldrb r1, [r4, 0x9]
	movs r0, 0x1
	ands r0, r1
	strb r0, [r4, 0x9]
	mov r1, r9
	ldr r0, [r1]
	adds r0, r2
	movs r1, 0xFF
	strb r1, [r0, 0xA]
	mov r2, r8
	lsls r5, r2, 2
_08173840:
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bhi _0817384C
	b _08173740
_0817384C:
	ldr r0, =gUnknown_0203BCD4
	movs r3, 0
	str r3, [r0]
	ldr r4, =gTasks
	mov r6, r8
	adds r1, r5, r6
	lsls r1, 3
	adds r2, r1, r4
	strh r3, [r2, 0xA]
	movs r0, 0xFF
	strh r0, [r2, 0x10]
	movs r7, 0
	adds r3, r4, 0
	adds r3, 0x8
	movs r2, 0xFF
_0817386A:
	adds r0, r7, 0x5
	lsls r0, 1
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _0817386A
	mov r1, r8
	adds r0, r5, r1
	lsls r0, 3
	adds r1, r0, r4
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _081738A4
	ldr r0, =sub_8173A8C
	b _081738A6
	.pool
_081738A4:
	ldr r0, =sub_81738BC
_081738A6:
	str r0, [r1]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817371C

	thumb_func_start sub_81738BC
sub_81738BC: @ 81738BC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r7, =0x0201c000
	ldr r0, =gUnknown_0203BCE4
	ldrb r0, [r0]
	cmp r0, 0
	bne _081738EC
	movs r2, 0x80
	lsls r2, 6
	adds r0, r7, 0
	movs r1, 0
	bl memset
	b _08173906
	.pool
_081738EC:
	movs r0, 0x3
	bl sub_81534D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08173906
	movs r2, 0x80
	lsls r2, 6
	adds r0, r7, 0
	movs r1, 0
	bl memset
_08173906:
	movs r5, 0
	ldrh r1, [r7, 0x8]
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r0, r1
	mov r1, r9
	lsls r1, 2
	mov r8, r1
	cmp r0, 0
	beq _08173930
_0817391A:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r7, 0x78
	cmp r5, 0x31
	bhi _08173934
	ldrh r1, [r7, 0x8]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0817391A
_08173930:
	cmp r5, 0x31
	bls _08173956
_08173934:
	ldr r4, =0x0201c000
	adds r6, r4, 0
	adds r4, 0x78
	movs r5, 0
	subs r7, 0x78
_0817393E:
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x78
	bl memcpy
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, 0x78
	adds r4, 0x78
	cmp r5, 0x30
	bls _0817393E
_08173956:
	ldr r0, =gUnknown_0203BCD8
	ldr r1, [r0]
	adds r0, r7, 0
	movs r2, 0x78
	bl memcpy
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gUnknown_082C8959
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	mov r0, r8
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81739C4
	str r1, [r0]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81738BC

	thumb_func_start sub_81739C4
sub_81739C4: @ 81739C4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_03006214
	ldr r0, =sub_81736D8
	str r0, [r1]
	movs r0, 0x3
	bl save_game_when_memory_present
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08173A34
	ldr r0, =gUnknown_030061FC
	ldr r0, [r0]
	cmp r0, 0
	beq _08173A34
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	bl FreeAllWindowBuffers
	ldr r5, =gUnknown_0203BCDC
	ldr r0, [r5]
	cmp r0, 0
	beq _08173A06
	bl Free
	movs r0, 0
	str r0, [r5]
_08173A06:
	ldr r5, =gUnknown_0203BCD8
	ldr r0, [r5]
	cmp r0, 0
	beq _08173A16
	bl Free
	movs r0, 0
	str r0, [r5]
_08173A16:
	adds r0, r4, 0
	bl DestroyTask
	b _08173A4C
	.pool
_08173A34:
	movs r0, 0x37
	bl audio_play
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8173A5C
	str r1, [r0]
	movs r1, 0x20
	strh r1, [r0, 0xE]
_08173A4C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81739C4

	thumb_func_start sub_8173A5C
sub_8173A5C: @ 8173A5C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08173A80
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	b _08173A84
	.pool
_08173A80:
	ldr r0, =sub_8173A8C
	str r0, [r1]
_08173A84:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173A5C

	thumb_func_start sub_8173A8C
sub_8173A8C: @ 8173A8C
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_8173AA8
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8173A8C

	thumb_func_start sub_8173AA8
sub_8173AA8: @ 8173AA8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldrh r6, [r1, 0xA]
	ldr r2, =gUnknown_0203BCD8
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 2
	ldr r2, [r2]
	adds r7, r2, r0
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0x3
	ble _08173AEC
	ldr r1, =gUnknown_085E53B4
	b _08173AEE
	.pool
_08173AEC:
	ldr r1, =gUnknown_085E53E4
_08173AEE:
	lsls r2, r6, 3
	adds r0, r2, r1
	ldrh r3, [r0]
	adds r0, r1, 0x2
	adds r0, r2, r0
	ldrh r4, [r0]
	adds r0, r1, 0x4
	adds r0, r2, r0
	ldrh r0, [r0]
	mov r9, r0
	adds r1, 0x6
	adds r2, r1
	ldrh r5, [r2]
	ldrh r2, [r7, 0x8]
	ldr r0, =0x000001ff
	ands r0, r2
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _08173B20
	lsls r0, r5, 16
	movs r1, 0xA0
	lsls r1, 12
	adds r0, r1
	lsrs r5, r0, 16
_08173B20:
	lsls r0, r2, 23
	lsrs r0, 23
	ldr r1, [r7]
	ldr r2, [r7, 0x4]
	lsls r3, 16
	asrs r3, 16
	str r3, [sp]
	lsls r3, r4, 16
	asrs r3, 16
	str r3, [sp, 0x4]
	lsls r3, r6, 24
	lsrs r3, 24
	str r3, [sp, 0x8]
	ldr r3, =0x0000ffff
	str r3, [sp, 0xC]
	movs r3, 0x1
	bl sub_818D3E4
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_02020630
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r3, r2, r4
	movs r1, 0
	mov r12, r1
	mov r1, r9
	strh r1, [r3, 0x30]
	strh r5, [r3, 0x32]
	mov r1, r12
	strh r1, [r3, 0x2E]
	ldrh r1, [r7, 0x8]
	lsls r1, 23
	lsrs r1, 23
	strh r1, [r3, 0x3C]
	adds r4, 0x1C
	adds r2, r4
	ldr r1, =sub_8175120
	str r1, [r2]
	ldr r5, =gTasks
	adds r1, r6, 0x5
	lsls r1, 1
	mov r2, r8
	lsls r4, r2, 2
	add r4, r8
	lsls r4, 3
	adds r1, r4
	adds r2, r5, 0
	adds r2, 0x8
	adds r1, r2
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x1
	bl sub_8197434
	adds r4, r5
	ldr r0, =sub_8173BC0
	str r0, [r4]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173AA8

	thumb_func_start sub_8173BC0
sub_8173BC0: @ 8173BC0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 3
	adds r5, r3, r4
	ldrh r0, [r5, 0xA]
	ldr r2, =gUnknown_0203BCD8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, [r2]
	adds r2, r1
	adds r0, 0x5
	lsls r0, 1
	adds r0, r3
	adds r4, 0x8
	adds r0, r4
	movs r3, 0
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r3, r0, r1
	ldr r1, [r3, 0x1C]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08173C1A
	ldrb r1, [r3, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x1]
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0xE
	bl sub_8174A88
	movs r0, 0x78
	strh r0, [r5, 0xE]
	ldr r0, =sub_8173C34
	str r0, [r5]
_08173C1A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173BC0

	thumb_func_start sub_8173C34
sub_8173C34: @ 8173C34
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r6, r0, 3
	adds r4, r6, r2
	ldrh r3, [r4, 0xA]
	ldr r1, =gUnknown_0203BCD8
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	mov r9, r1
	ldrh r1, [r4, 0xE]
	movs r7, 0xE
	ldrsh r0, [r4, r7]
	mov r12, r2
	cmp r0, 0
	beq _08173C78
	subs r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _08173D10
	.pool
_08173C78:
	ldr r2, =gUnknown_0203BCD4
	ldr r0, =gUnknown_02020630
	mov r8, r0
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r6
	mov r1, r12
	adds r1, 0x8
	adds r6, r0, r1
	movs r7, 0
	ldrsh r1, [r6, r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	movs r1, 0x80
	lsls r1, 9
	lsls r1, r0
	ldr r3, [r2]
	orrs r3, r1
	str r3, [r2]
	ldrh r2, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x4
	bgt _08173D04
	mov r7, r9
	ldrh r1, [r7, 0x1C]
	ldr r0, =0x000001ff
	ands r0, r1
	cmp r0, 0
	beq _08173D04
	adds r0, r2, 0x1
	strh r0, [r4, 0xA]
	ldr r0, =0x000063b0
	str r0, [sp]
	adds r0, r3, 0
	movs r1, 0
	movs r2, 0xC
	movs r3, 0xC
	bl BeginNormalPaletteFade
	movs r0, 0
	ldrsh r1, [r6, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x5]
	ldr r0, =sub_8173AA8
	str r0, [r4]
	b _08173D10
	.pool
_08173D04:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	add r0, r12
	ldr r1, =sub_8173D24
	str r1, [r0]
_08173D10:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173C34

	thumb_func_start sub_8173D24
sub_8173D24: @ 8173D24
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =0xffff0000
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r3, 0
	lsls r1, r4, 2
	adds r0, r1, r4
	lsls r5, r0, 3
	ldr r0, =gTasks + 0x8
	mov r12, r0
	mov r8, r1
	ldr r6, =gUnknown_02020630
	movs r7, 0xD
	negs r7, r7
_08173D52:
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r5
	mov r2, r12
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xFF
	beq _08173D74
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r2, [r1, 0x5]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1, 0x5]
_08173D74:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _08173D52
	movs r0, 0
	movs r1, 0xF
	bl sub_8174A38
	movs r0, 0x69
	bl audio_play
	ldr r1, =gTasks
	mov r2, r8
	adds r0, r2, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0xC8
	lsls r1, 1
	strh r1, [r0, 0xE]
	ldr r1, =sub_8173DC0
	str r1, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173D24

	thumb_func_start sub_8173DC0
sub_8173DC0: @ 8173DC0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gTasks
	lsls r4, r6, 2
	adds r0, r4, r6
	lsls r5, r0, 3
	adds r1, r5, r7
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08173E04
	subs r2, 0x1
	strh r2, [r1, 0xE]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0
	bne _08173E7E
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x6E
	ble _08173E7E
	bl sub_81751FC
	b _08173E7E
	.pool
_08173E04:
	movs r3, 0
	mov r9, r4
	ldr r0, =gUnknown_0203BCD4
	mov r10, r0
	adds r4, r5, 0
	adds r7, 0x8
	mov r8, r7
	ldr r7, =gUnknown_02020630
	movs r1, 0xD
	negs r1, r1
	mov r12, r1
	movs r5, 0x4
_08173E1C:
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r4
	mov r2, r8
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xFF
	beq _08173E40
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	mov r0, r12
	ands r0, r2
	orrs r0, r5
	strb r0, [r1, 0x5]
_08173E40:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _08173E1C
	mov r3, r10
	ldr r0, [r3]
	ldr r1, =0x000063b0
	str r1, [sp]
	movs r1, 0
	movs r2, 0xC
	movs r3, 0xC
	bl BeginNormalPaletteFade
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	mov r2, r9
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1
	movs r1, 0x7
	strh r1, [r0, 0xE]
	ldr r1, =sub_8173EA4
	str r1, [r0]
_08173E7E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173DC0

	thumb_func_start sub_8173EA4
sub_8173EA4: @ 8173EA4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0xF
	ble _08173ECC
	ldr r0, =sub_8173EE4
	str r0, [r1]
	b _08173EDE
	.pool
_08173ECC:
	adds r0, r2, 0x1
	strh r0, [r1, 0xE]
	movs r0, 0xE
	ldrsh r1, [r1, r0]
	lsls r1, 24
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
_08173EDE:
	pop {r0}
	bx r0
	thumb_func_end sub_8173EA4

	thumb_func_start sub_8173EE4
sub_8173EE4: @ 8173EE4
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r6, =gUnknown_03005D90
	ldr r0, [r6]
	ldrb r0, [r0, 0x8]
	movs r1, 0x1
	bl sub_818D97C
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	str r1, [sp]
	ldr r1, =0x0000ffff
	str r1, [sp, 0x4]
	movs r1, 0x1
	movs r2, 0x78
	movs r3, 0x48
	bl sub_818D8AC
	ldr r1, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r1
	strh r0, [r4, 0x10]
	ldr r0, =gUnknown_085E5380
	bl AddWindow
	ldr r0, [r6]
	ldrb r1, [r0, 0x14]
	lsrs r1, 3
	ldr r2, =0x0000021d
	movs r0, 0x1
	movs r3, 0xD0
	bl sub_80987D4
	movs r0, 0x1
	bl stdpal_get
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x78
	strh r0, [r4, 0xE]
	ldr r0, =sub_8173F84
	str r0, [r4]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173EE4

	thumb_func_start sub_8173F84
sub_8173F84: @ 8173F84
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0xE]
	movs r1, 0xE
	ldrsh r5, [r4, r1]
	cmp r5, 0
	beq _08173FAC
	subs r0, 0x1
	strh r0, [r4, 0xE]
	b _08174018
	.pool
_08173FAC:
	ldr r2, =gUnknown_02020630
	movs r3, 0x10
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrh r2, [r1, 0x20]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	cmp r0, 0xC0
	beq _08173FD0
	adds r0, r2, 0x1
	strh r0, [r1, 0x20]
	b _08174018
	.pool
_08173FD0:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	movs r1, 0x2
	bl sub_8174C98
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gUnknown_085E8C14
	str r5, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =sub_8174028
	str r0, [r4]
_08174018:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8173F84

	thumb_func_start sub_8174028
sub_8174028: @ 8174028
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0817404E
	movs r0, 0x4
	bl play_sound_effect
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8174060
	str r0, [r1]
_0817404E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174028

	thumb_func_start sub_8174060
sub_8174060: @ 8174060
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPlttBufferFaded
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 2
	bl CpuSet
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81740B0
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174060

	thumb_func_start sub_81740B0
sub_81740B0: @ 81740B0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08174164
	lsls r0, r7, 2
	mov r8, r0
	ldr r1, =gTasks
	adds r0, r7
	lsls r0, 3
	adds r1, 0x12
	adds r5, r0, r1
	ldr r2, =gUnknown_02020630
	mov r9, r2
	movs r6, 0x5
_081740DC:
	ldrb r4, [r5]
	cmp r4, 0xFF
	beq _081740FA
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	add r0, r9
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	adds r0, r4, 0
	bl sub_818D820
_081740FA:
	adds r5, 0x2
	subs r6, 0x1
	cmp r6, 0
	bge _081740DC
	ldr r0, =gTasks
	mov r2, r8
	adds r1, r2, r7
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x10]
	bl sub_818D8F0
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x3
	bl HideBg
	bl FreeAllWindowBuffers
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	adds r0, r7, 0
	bl DestroyTask
	ldr r4, =gUnknown_0203BCDC
	ldr r0, [r4]
	cmp r0, 0
	beq _08174150
	bl Free
	movs r0, 0
	str r0, [r4]
_08174150:
	ldr r4, =gUnknown_0203BCD8
	ldr r0, [r4]
	cmp r0, 0
	beq _08174160
	bl Free
	movs r0, 0
	str r0, [r4]
_08174160:
	bl sub_8174184
_08174164:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81740B0

	thumb_func_start sub_8174184
sub_8174184: @ 8174184
	push {lr}
	ldr r0, =sub_8175620
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174184

	thumb_func_start sub_8174194
sub_8174194: @ 8174194
	push {r4,lr}
	ldr r0, =gUnknown_030022C0
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _081741D0
	lsls r0, 2
	ldr r1, =_081741B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081741B8:
	.4byte _081741D0
	.4byte _08174200
	.4byte _08174214
	.4byte _08174240
	.4byte _08174280
	.4byte _081742B0
_081741D0:
	movs r0, 0
	bl SetVBlankCallback
	bl sub_8174EC4
	ldr r4, =gUnknown_0203BCDC
	ldr r0, =0x00002014
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =gUnknown_030022C0
	movs r2, 0x87
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _08174308
	.pool
_08174200:
	bl sub_8174F70
	ldr r1, =gUnknown_030022C0
	movs r3, 0x87
	lsls r3, 3
	adds r1, r3
	b _081742A2
	.pool
_08174214:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	bl sub_8174FAC
	ldr r1, =gUnknown_030022C0
	movs r4, 0x87
	lsls r4, 3
	adds r1, r4
	b _081742A2
	.pool
_08174240:
	bl sub_8175024
	lsls r0, 24
	cmp r0, 0
	bne _08174308
	ldr r1, =0x0201c000
	ldr r0, =gUnknown_085E56D4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_80F9BCC
	ldr r0, =sub_817354C
	bl SetVBlankCallback
	ldr r1, =gUnknown_030022C0
	movs r4, 0x87
	lsls r4, 3
	adds r1, r4
	b _081742A2
	.pool
_08174280:
	bl RunTasks
	bl CallObjectCallbacks
	bl PrepareSpritesForOamLoad
	bl UpdatePaletteFade
	bl sub_80F9C1C
	lsls r0, 24
	cmp r0, 0
	bne _08174308
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
_081742A2:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08174308
	.pool
_081742B0:
	ldr r1, =0x00003f42
	movs r0, 0x50
	bl SetGpuReg
	movs r1, 0xE2
	lsls r1, 3
	movs r0, 0x52
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	ldr r0, =sub_8174324
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r4, =gTasks + 0x8
	movs r3, 0xFF
_081742E2:
	adds r0, r2, 0x5
	lsls r0, 1
	adds r0, r1
	adds r0, r4
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bls _081742E2
	ldr r4, =gUnknown_0203BCD8
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	ldr r0, =sub_8173560
	bl SetMainCallback2
_08174308:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174194

	thumb_func_start sub_8174324
sub_8174324: @ 8174324
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =0x00000226
	str r0, [sp]
	movs r0, 0
	movs r1, 0x1E
	movs r2, 0
	movs r3, 0xC
	bl sub_81980F0
	movs r0, 0x3
	bl sub_81534D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08174364
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81749A0
	b _081743DA
	.pool
_08174364:
	ldr r0, =0x0201c000
	ldr r4, =gUnknown_0203BCD8
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 5
	bl CpuSet
	ldr r4, [r4]
	movs r2, 0
	ldrh r1, [r4, 0x8]
	ldr r3, =0x000001ff
	adds r0, r3, 0
	ands r0, r1
	lsls r5, r6, 2
	cmp r0, 0
	beq _0817439A
_08174384:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	adds r4, 0x78
	cmp r2, 0x31
	bhi _081743BC
	ldrh r1, [r4, 0x8]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08174384
_0817439A:
	cmp r2, 0x31
	bhi _081743BC
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	subs r0, r2, 0x1
	b _081743C6
	.pool
_081743BC:
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	movs r0, 0x31
_081743C6:
	strh r0, [r1, 0x8]
	movs r0, 0xA
	bl sub_80847F8
	ldr r2, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r2
	strh r0, [r1, 0xA]
	ldr r0, =sub_81743EC
_081743DA:
	str r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174324

	thumb_func_start sub_81743EC
sub_81743EC: @ 81743EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203BCD8
	ldr r3, [r0]
	movs r5, 0
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	adds r4, r1, 0
	ldr r2, =gUnknown_0203BCD4
	cmp r5, r0
	bge _0817442A
	adds r1, r0, 0
_0817441E:
	adds r3, 0x78
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r1
	blt _0817441E
_0817442A:
	adds r6, r3, 0
	movs r0, 0
	str r0, [r2]
	mov r5, r8
	lsls r2, r5, 2
	adds r1, r2, r5
	lsls r1, 3
	adds r1, r4
	strh r0, [r1, 0xC]
	strh r0, [r1, 0x10]
	movs r5, 0
	str r2, [sp, 0x14]
	ldr r4, =0x000001ff
	adds r2, r1, 0
_08174446:
	ldrh r1, [r6, 0x8]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08174456
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	strh r0, [r2, 0x10]
_08174456:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, 0x14
	cmp r5, 0x5
	bls _08174446
	adds r6, r3, 0
	movs r5, 0
	ldr r1, =gTasks
	ldr r0, [sp, 0x14]
	add r0, r8
	lsls r0, 3
	mov r9, r0
	adds r0, r1
	str r0, [sp, 0x10]
	ldr r1, =0x000001ff
	mov r10, r1
_08174478:
	ldrh r0, [r6, 0x8]
	mov r1, r10
	ands r1, r0
	adds r7, r0, 0
	cmp r1, 0
	beq _08174540
	ldr r2, [sp, 0x10]
	movs r4, 0x10
	ldrsh r0, [r2, r4]
	cmp r0, 0x3
	ble _081744B8
	lsls r1, r5, 3
	ldr r0, =gUnknown_085E53B4
	adds r0, 0x4
	adds r0, r1, r0
	ldrh r3, [r0]
	ldr r0, =gUnknown_085E53BA
	adds r1, r0
	ldrh r4, [r1]
	b _081744C8
	.pool
_081744B8:
	ldr r0, =gUnknown_085E53E4
	lsls r2, r5, 3
	adds r1, r0, 0x4
	adds r1, r2, r1
	ldrh r3, [r1]
	adds r0, 0x6
	adds r2, r0
	ldrh r4, [r2]
_081744C8:
	mov r1, r10
	ands r1, r7
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bne _081744DE
	lsls r0, r4, 16
	movs r1, 0xA0
	lsls r1, 12
	adds r0, r1
	lsrs r4, r0, 16
_081744DE:
	lsls r0, r7, 23
	lsrs r0, 23
	ldr r1, [r6]
	ldr r2, [r6, 0x4]
	lsls r3, 16
	asrs r3, 16
	str r3, [sp]
	lsls r3, r4, 16
	asrs r3, 16
	str r3, [sp, 0x4]
	lsls r3, r5, 24
	lsrs r3, 24
	str r3, [sp, 0x8]
	ldr r3, =0x0000ffff
	str r3, [sp, 0xC]
	movs r3, 0x1
	bl sub_818D7D8
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gUnknown_02020630
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r3, [r1, 0x5]
	movs r4, 0xD
	negs r4, r4
	adds r2, r4, 0
	ands r3, r2
	movs r2, 0x4
	orrs r3, r2
	strb r3, [r1, 0x5]
	adds r1, r5, 0x5
	lsls r1, 1
	add r1, r9
	ldr r2, =gTasks + 0x8
	adds r1, r2
	strh r0, [r1]
	b _0817454E
	.pool
_08174540:
	adds r0, r5, 0x5
	lsls r0, 1
	add r0, r9
	ldr r4, =gTasks + 0x8
	adds r0, r4
	movs r1, 0xFF
	strh r1, [r0]
_0817454E:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, 0x14
	cmp r5, 0x5
	bls _08174478
	ldr r0, =0xffff0000
	ldr r2, =0x000063b0
	movs r1, 0xC
	bl BlendPalettes
	ldr r0, =gUnknown_02021CC4
	ldr r1, =gTasks
	ldr r4, [sp, 0x14]
	add r4, r8
	lsls r4, 3
	adds r4, r1
	movs r5, 0xA
	ldrsh r1, [r4, r5]
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalString
	ldr r5, =gUnknown_02021FC4
	ldr r1, =gUnknown_085E8C00
	adds r0, r5, 0
	bl ExpandStringRefs
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _081745C0
	ldr r1, =gUnknown_085E8574
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_8198204
	b _081745D0
	.pool
_081745C0:
	ldr r1, =gUnknown_085E855C
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_8198204
_081745D0:
	ldr r0, =gTasks
	ldr r1, [sp, 0x14]
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81745FC
	str r0, [r1]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81743EC

	thumb_func_start sub_81745FC
sub_81745FC: @ 81745FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203BCD8
	ldr r5, [r0]
	movs r3, 0
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	cmp r3, r0
	bge _08174630
	adds r1, r0, 0
_08174624:
	adds r5, 0x78
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r1
	blt _08174624
_08174630:
	movs r3, 0
	lsls r7, r4, 2
	adds r0, r7, r4
	lsls r6, r0, 3
	ldr r0, =gTasks + 0x8
	mov r10, r0
	ldr r1, =gUnknown_02020630
	mov r8, r1
	movs r2, 0xD
	negs r2, r2
	mov r9, r2
	movs r0, 0x4
	mov r12, r0
_0817464A:
	adds r0, r3, 0x5
	lsls r0, 1
	adds r0, r6
	add r0, r10
	ldrh r1, [r0]
	cmp r1, 0xFF
	beq _0817466C
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r2, [r0, 0x5]
	mov r1, r9
	ands r1, r2
	mov r2, r12
	orrs r1, r2
	strb r1, [r0, 0x5]
_0817466C:
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x5
	bls _0817464A
	adds r1, r7, r4
	lsls r1, 3
	ldr r0, =gTasks
	adds r6, r1, r0
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, 0x5
	lsls r0, 1
	adds r0, r1
	ldr r1, =gTasks
	adds r1, 0x8
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	strb r1, [r0, 0x5]
	lsrs r1, 4
	movs r0, 0x80
	lsls r0, 9
	lsls r0, r1
	ldr r1, =0xffff0000
	eors r0, r1
	ldr r2, =gUnknown_0203BCD4
	str r0, [r2]
	ldr r2, =0x000063b0
	movs r1, 0xC
	bl BlendPalettesUnfaded
	movs r0, 0xC
	ldrsh r1, [r6, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r4, r5, r0
	ldrh r1, [r4, 0x8]
	ldr r0, =0x000001ff
	ands r0, r1
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _081746E6
	bl sub_80A369C
	ldrh r0, [r4, 0x8]
	lsls r0, 23
	lsrs r0, 23
	movs r1, 0
	bl cry_related
_081746E6:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0xE
	bl sub_8174A88
	ldr r0, =sub_8174728
	str r0, [r6]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81745FC

	thumb_func_start sub_8174728
sub_8174728: @ 8174728
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gUnknown_030022C0
	ldrh r2, [r1, 0x2E]
	movs r0, 0x1
	ands r0, r2
	adds r3, r1, 0
	cmp r0, 0
	beq _081747E4
	ldr r0, =gTasks
	mov r12, r0
	lsls r0, r6, 2
	adds r1, r0, r6
	lsls r3, r1, 3
	mov r1, r12
	adds r4, r3, r1
	ldrh r2, [r4, 0x8]
	movs r5, 0x8
	ldrsh r1, [r4, r5]
	mov r9, r0
	cmp r1, 0
	beq _081747B8
	subs r0, r2, 0x1
	strh r0, [r4, 0x8]
	movs r5, 0
	adds r7, r3, 0
	movs r0, 0x8
	add r0, r12
	mov r8, r0
_0817476A:
	adds r0, r5, 0x5
	lsls r0, 1
	adds r0, r7
	mov r1, r8
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08174782
	bl sub_818D820
	movs r0, 0xFF
	strh r0, [r4]
_08174782:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x5
	bls _0817476A
	ldr r0, =gTasks
	mov r2, r9
	adds r1, r2, r6
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _081747A4
	subs r0, r2, 0x1
	strh r0, [r1, 0xA]
_081747A4:
	ldr r0, =sub_81743EC
	str r0, [r1]
	b _08174884
	.pool
_081747B8:
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	beq _081747D2
	bl sub_80A369C
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_081747D2:
	ldr r0, =sub_8174898
	str r0, [r4]
	b _08174884
	.pool
_081747E4:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _08174828
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	beq _08174806
	bl sub_80A369C
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_08174806:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8174898
	str r0, [r1]
	b _08174884
	.pool
_08174828:
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08174858
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldrh r2, [r1, 0xC]
	movs r4, 0xC
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08174858
	subs r0, r2, 0x1
	strh r0, [r1, 0xC]
	ldr r0, =sub_81745FC
	str r0, [r1]
	b _08174884
	.pool
_08174858:
	ldrh r1, [r3, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08174884
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r2, r0, r1
	movs r5, 0xC
	ldrsh r1, [r2, r5]
	movs r3, 0x10
	ldrsh r0, [r2, r3]
	subs r0, 0x1
	cmp r1, r0
	bge _08174884
	ldrh r0, [r2, 0xC]
	adds r0, 0x1
	strh r0, [r2, 0xC]
	ldr r0, =sub_81745FC
	str r0, [r2]
_08174884:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174728

	thumb_func_start sub_8174898
sub_8174898: @ 8174898
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gPlttBufferFaded
	ldr r1, =gPlttBufferUnfaded
	movs r2, 0x80
	lsls r2, 2
	bl CpuSet
	ldr r1, =0x0201c000
	ldr r0, =gUnknown_085E56D4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl sub_80F9BF4
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81748F0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174898

	thumb_func_start sub_81748F0
sub_81748F0: @ 81748F0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_80F9C30
	lsls r0, 24
	cmp r0, 0
	bne _08174988
	movs r5, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
_08174910:
	adds r0, r5, 0x5
	lsls r0, 1
	adds r0, r7
	mov r1, r8
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, 0xFF
	beq _08174928
	bl sub_818D820
	movs r0, 0xFF
	strh r0, [r4]
_08174928:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08174910
	movs r0, 0
	bl HideBg
	movs r0, 0x1
	bl HideBg
	movs r0, 0x3
	bl HideBg
	bl sub_8198314
	bl FreeAllWindowBuffers
	movs r0, 0x1
	bl UnsetBgTilemapBuffer
	movs r0, 0x3
	bl UnsetBgTilemapBuffer
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	adds r0, r6, 0
	bl DestroyTask
	ldr r4, =gUnknown_0203BCDC
	ldr r0, [r4]
	cmp r0, 0
	beq _08174974
	bl Free
	movs r0, 0
	str r0, [r4]
_08174974:
	ldr r4, =gUnknown_0203BCD8
	ldr r0, [r4]
	cmp r0, 0
	beq _08174984
	bl Free
	movs r0, 0
	str r0, [r4]
_08174984:
	bl sub_8137C3C
_08174988:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81748F0

	thumb_func_start sub_81749A0
sub_81749A0: @ 81749A0
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_085E8588
	movs r1, 0x8
	movs r2, 0x1
	bl sub_8198180
	movs r0, 0
	movs r1, 0
	bl sub_81973C4
	ldr r2, =gUnknown_085E8BDC
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParametrized
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8174A08
	str r1, [r0]
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81749A0

	thumb_func_start sub_8174A08
sub_8174A08: @ 8174A08
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08174A28
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8174898
	str r0, [r1]
_08174A28:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174A08

	thumb_func_start sub_8174A38
sub_8174A38: @ 8174A38
	push {r4,lr}
	sub sp, 0xC
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	ldr r4, =gUnknown_085E8B3E
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174A38

	thumb_func_start sub_8174A88
sub_8174A88: @ 8174A88
	push {r4-r7,lr}
	sub sp, 0x2C
	adds r7, r0, 0
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl PutWindowTilemap
	ldrh r0, [r7, 0x8]
	ldr r1, =0x000001ff
	ands r1, r0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _08174B30
	ldr r1, =gUnknown_085E8C36
	add r0, sp, 0xC
	bl CopyString
	adds r6, r0, 0
	ldrh r0, [r7, 0x8]
	lsls r0, 23
	lsrs r0, 23
	bl sub_806E3C0
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _08174B04
	adds r0, r4, 0
	movs r1, 0x64
	bl __divsi3
	subs r0, 0x5F
	strb r0, [r6]
	adds r6, 0x1
	adds r0, r4, 0
	movs r1, 0x64
	bl __modsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __divsi3
	subs r0, 0x5F
	strb r0, [r6]
	adds r6, 0x1
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	subs r0, 0x5F
	b _08174B0E
	.pool
_08174B04:
	movs r0, 0xAC
	strb r0, [r6]
	adds r6, 0x1
	strb r0, [r6]
	adds r6, 0x1
_08174B0E:
	strb r0, [r6]
	adds r6, 0x1
	movs r0, 0xFF
	strb r0, [r6]
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0x1
	bl box_print
_08174B30:
	adds r1, r7, 0
	adds r1, 0xA
	add r0, sp, 0xC
	movs r2, 0xA
	bl memcpy
	add r1, sp, 0xC
	movs r0, 0xFF
	strb r0, [r1, 0xA]
	ldrh r1, [r7, 0x8]
	ldr r4, =0x000001ff
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _08174B8C
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0xD0
	bl GetStringCenterAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	b _08174C82
	.pool
_08174B8C:
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x80
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E5388
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	add r1, sp, 0xC
	movs r0, 0xBA
	strb r0, [r1]
	mov r0, sp
	adds r0, 0xD
	ldrh r1, [r7, 0x8]
	lsls r1, 23
	lsrs r1, 23
	movs r2, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl CopyString
	adds r6, r0, 0
	ldrh r1, [r7, 0x8]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x20
	beq _08174C0A
	cmp r0, 0x1D
	beq _08174C0A
	lsls r0, r1, 23
	lsrs r0, 23
	ldr r1, [r7, 0x4]
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08174C00
	cmp r0, 0xFE
	beq _08174C04
	b _08174C0A
	.pool
_08174C00:
	movs r0, 0xB5
	b _08174C06
_08174C04:
	movs r0, 0xB6
_08174C06:
	strb r0, [r6]
	adds r6, 0x1
_08174C0A:
	movs r0, 0xFF
	strb r0, [r6]
	ldr r5, =gUnknown_085E5388
	str r5, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x80
	movs r3, 0x1
	bl box_print
	ldr r1, =gUnknown_085E8C3B
	add r0, sp, 0xC
	bl CopyString
	adds r6, r0, 0
	ldrb r1, [r7, 0x9]
	lsrs r1, 1
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalString
	str r5, [sp]
	str r4, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x24
	movs r3, 0x11
	bl box_print
	ldr r1, =gUnknown_085E8C4D
	add r0, sp, 0xC
	bl CopyString
	adds r6, r0, 0
	ldrh r1, [r7]
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalString
	str r5, [sp]
	str r4, [sp, 0x4]
	add r0, sp, 0xC
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x68
	movs r3, 0x11
	bl box_print
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
_08174C82:
	add sp, 0x2C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174A88

	thumb_func_start sub_8174C98
sub_8174C98: @ 8174C98
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x1
	bl PutWindowTilemap
	ldr r2, =0x0000021d
	movs r0, 0x1
	movs r1, 0
	movs r3, 0xD
	bl SetWindowBorderStyle
	ldr r0, =gUnknown_085E538C
	mov r8, r0
	str r0, [sp]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_085E8C48
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1
	bl box_print
	ldr r0, =gUnknown_03005D90
	mov r10, r0
	ldr r1, [r0]
	movs r0, 0x1
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	mov r1, r8
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	mov r1, r10
	ldr r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x1
	bl box_print
	mov r1, r10
	ldr r0, [r1]
	ldrb r4, [r0, 0xA]
	ldrb r0, [r0, 0xB]
	lsls r0, 8
	orrs r4, r0
	mov r0, r8
	str r0, [sp]
	movs r7, 0
	str r7, [sp, 0x4]
	ldr r0, =gUnknown_085E8C4D
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x11
	bl box_print
	add r6, sp, 0xC
	ldr r1, =0x000186a0
	adds r0, r4, 0
	bl __modsi3
	ldr r5, =0x00002710
	adds r1, r5, 0
	bl __divsi3
	subs r0, 0x5F
	strb r0, [r6]
	add r6, sp, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r5, 0xFA
	lsls r5, 2
	adds r1, r5, 0
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r6, 0x1]
	add r6, sp, 0xC
	adds r0, r4, 0
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r6, 0x2]
	add r5, sp, 0xC
	adds r0, r4, 0
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x3]
	add r5, sp, 0xC
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x4]
	add r1, sp, 0xC
	movs r0, 0xFF
	strb r0, [r1, 0x5]
	movs r0, 0x1
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	mov r1, r8
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x11
	bl box_print
	mov r0, r8
	str r0, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	ldr r0, =gUnknown_085E84CE
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x21
	bl box_print
	add r5, sp, 0xC
	mov r0, r10
	ldr r4, [r0]
	ldrh r0, [r4, 0xE]
	movs r1, 0x64
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5]
	add r5, sp, 0xC
	ldrh r0, [r4, 0xE]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r5, 0x1]
	add r5, sp, 0xC
	ldrh r0, [r4, 0xE]
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r5, 0x2]
	add r0, sp, 0xC
	ldrb r0, [r0]
	cmp r0, 0xA1
	bne _08174E1E
	add r0, sp, 0xC
	strb r7, [r0]
_08174E1E:
	add r0, sp, 0xC
	ldrb r1, [r0]
	cmp r1, 0
	bne _08174E30
	ldrb r0, [r0, 0x1]
	cmp r0, 0xA1
	bne _08174E30
	add r0, sp, 0xC
	strb r1, [r0, 0x8]
_08174E30:
	add r1, sp, 0xC
	movs r0, 0xF0
	strb r0, [r1, 0x3]
	adds r4, r1, 0
	ldr r0, =gUnknown_03005D90
	ldr r5, [r0]
	ldrb r0, [r5, 0x10]
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xA
	bl __udivsi3
	adds r0, 0xA1
	strb r0, [r4, 0x4]
	add r4, sp, 0xC
	ldrb r0, [r5, 0x10]
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0xA1
	strb r0, [r4, 0x5]
	add r1, sp, 0xC
	movs r0, 0xFF
	strb r0, [r1, 0x6]
	movs r0, 0x1
	movs r2, 0x70
	bl GetStringRightAlignXOffset
	lsls r2, r0, 24
	lsrs r2, 24
	ldr r0, =gUnknown_085E538C
	str r0, [sp]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x4]
	add r1, sp, 0xC
	str r1, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0x21
	bl box_print
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174C98

	thumb_func_start sub_8174EC4
sub_8174EC4: @ 8174EC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0xC0
	lsls r3, 19
	movs r4, 0xC0
	lsls r4, 9
	add r0, sp, 0x4
	mov r8, r0
	mov r2, sp
	movs r6, 0
	ldr r1, =0x040000d4
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_08174EEA:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _08174EEA
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, 0x4]
	lsrs r0, r4, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0xE0
	lsls r0, 19
	movs r3, 0x80
	lsls r3, 3
	movs r4, 0
	str r4, [sp, 0x4]
	ldr r2, =0x040000d4
	mov r1, r8
	str r1, [r2]
	str r0, [r2, 0x4]
	lsrs r0, r3, 2
	movs r1, 0x85
	lsls r1, 24
	orrs r0, r1
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x8]
	movs r1, 0xA0
	lsls r1, 19
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	lsrs r3, 1
	movs r0, 0x81
	lsls r0, 24
	orrs r3, r0
	str r3, [r2, 0x8]
	ldr r0, [r2, 0x8]
	bl ResetPaletteFade
	ldr r0, =gUnknown_085E54E8
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174EC4

	thumb_func_start sub_8174F70
sub_8174F70: @ 8174F70
	push {lr}
	bl remove_some_task
	bl ResetTasks
	bl ResetAllObjectData
	bl reset_temp_tile_data_buffers
	bl dp13_810BB8C
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gUnknown_085E5394
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E53A4
	bl LoadCompressedObjectPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174F70

	thumb_func_start sub_8174FAC
sub_8174FAC: @ 8174FAC
	push {r4,lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E5374
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203BCDC
	ldr r1, [r4]
	adds r1, 0x12
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, =0x00001012
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8174FAC

	thumb_func_start sub_8175024
sub_8175024: @ 8175024
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203BCDC
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _08175108
	lsls r0, 2
	ldr r1, =_08175044
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08175044:
	.4byte _08175058
	.4byte _08175070
	.4byte _0817507C
	.4byte _081750D2
	.4byte _081750DC
_08175058:
	ldr r1, =gUnknown_085E5508
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _08175108
	.pool
_08175070:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _08175108
	b _08175112
_0817507C:
	movs r4, 0x20
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r0, 0xB
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x3
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	movs r3, 0xE
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0x2
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _08175108
_081750D2:
	bl sub_81971D0
	bl sub_8197200
	b _08175108
_081750DC:
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	ldr r0, =gUnknown_0203BCDC
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1]
	b _08175114
	.pool
_08175108:
	ldr r0, =gUnknown_0203BCDC
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_08175112:
	movs r0, 0x1
_08175114:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8175024

	thumb_func_start sub_8175120
sub_8175120: @ 8175120
	push {r4,lr}
	adds r2, r0, 0
	ldr r1, [r2, 0x20]
	ldr r0, [r2, 0x30]
	cmp r1, r0
	beq _08175176
	ldrh r3, [r2, 0x20]
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	movs r4, 0x30
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bge _08175140
	adds r0, r3, 0
	adds r0, 0xF
	strh r0, [r2, 0x20]
_08175140:
	ldrh r3, [r2, 0x20]
	movs r4, 0x20
	ldrsh r0, [r2, r4]
	cmp r0, r1
	ble _08175150
	adds r0, r3, 0
	subs r0, 0xF
	strh r0, [r2, 0x20]
_08175150:
	ldrh r3, [r2, 0x22]
	movs r1, 0x22
	ldrsh r0, [r2, r1]
	movs r4, 0x32
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bge _08175164
	adds r0, r3, 0
	adds r0, 0xA
	strh r0, [r2, 0x22]
_08175164:
	ldrh r3, [r2, 0x22]
	movs r4, 0x22
	ldrsh r0, [r2, r4]
	cmp r0, r1
	ble _0817519C
	adds r0, r3, 0
	subs r0, 0xA
	strh r0, [r2, 0x22]
	b _0817519C
_08175176:
	ldrh r0, [r2, 0x3C]
	lsls r1, r0, 16
	movs r0, 0xCE
	lsls r0, 17
	cmp r1, r0
	bne _08175190
	lsrs r1, 16
	adds r0, r2, 0
	movs r2, 0x1
	movs r3, 0x3
	bl sub_806ED40
	b _0817519C
_08175190:
	lsrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x3
	bl sub_806ED40
_0817519C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8175120

	thumb_func_start sub_81751A4
sub_81751A4: @ 81751A4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0x26]
	movs r2, 0x26
	ldrsh r0, [r5, r2]
	cmp r0, 0x78
	ble _081751BA
	adds r0, r5, 0
	bl RemoveObjectAndFreeTiles
	b _081751F2
_081751BA:
	adds r0, r1, 0x1
	ldrh r1, [r5, 0x30]
	adds r0, r1
	strh r0, [r5, 0x26]
	ldrh r4, [r5, 0x2E]
	lsls r4, 24
	lsrs r4, 24
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r0, 0x8
	ldr r1, =gUnknown_08329F40
	lsls r4, 1
	adds r4, r1
	movs r2, 0
	ldrsh r1, [r4, r2]
	muls r0, r1
	cmp r0, 0
	bge _081751E8
	adds r0, 0xFF
_081751E8:
	asrs r0, 8
	strh r0, [r5, 0x24]
	ldrh r0, [r5, 0x2E]
	adds r0, 0x4
	strh r0, [r5, 0x2E]
_081751F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81751A4

	thumb_func_start sub_81751FC
sub_81751FC: @ 81751FC
	push {r4,lr}
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl GenerateRandomNumber
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x7
	ands r2, r0
	negs r2, r2
	ldr r0, =gUnknown_085E54D0
	lsls r4, 16
	asrs r4, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r4, 0
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02020630
	adds r4, r1, r0
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartObjectImageAnim
	bl GenerateRandomNumber
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	beq _08175274
	movs r0, 0
	b _08175276
	.pool
_08175274:
	movs r0, 0x1
_08175276:
	strh r0, [r4, 0x30]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81751FC

	thumb_func_start sub_8175280
sub_8175280: @ 8175280
	push {r4,lr}
	ldr r4, =gUnknown_020375E0
	movs r0, 0xB4
	strh r0, [r4]
	ldr r0, =sub_8175364
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _081752AA
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r4]
	strh r1, [r0, 0xA]
	ldr r0, =gUnknown_020375E2
	strh r2, [r0]
_081752AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175280

	thumb_func_start sub_81752C0
sub_81752C0: @ 81752C0
	push {r4,lr}
	ldr r0, =sub_8175364
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _081752D4
	bl DestroyTask
_081752D4:
	bl sub_8152254
	ldr r4, =0x000003e9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81752C0

	thumb_func_start sub_81752F4
sub_81752F4: @ 81752F4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0xE]
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r0, 0x6E
	ble _08175324
	ldr r2, =gTasks
	movs r0, 0x28
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r0, 0x26]
	subs r1, 0x1
	strh r1, [r0, 0x26]
	ldrb r0, [r5, 0x16]
	bl sub_81525D0
	b _08175358
	.pool
_08175324:
	adds r0, r1, 0x1
	ldrh r1, [r5, 0x1C]
	adds r0, r1
	strh r0, [r5, 0xE]
	ldrb r4, [r5, 0x1A]
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	ands r0, r1
	adds r0, 0x8
	ldr r1, =gUnknown_08329F40
	lsls r4, 1
	adds r4, r1
	movs r2, 0
	ldrsh r1, [r4, r2]
	muls r0, r1
	cmp r0, 0
	bge _0817534E
	adds r0, 0xFF
_0817534E:
	asrs r0, 8
	strh r0, [r5, 0xC]
	ldrh r0, [r5, 0x1A]
	adds r0, 0x4
	strh r0, [r5, 0x1A]
_08175358:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81752F4

	thumb_func_start sub_8175364
sub_8175364: @ 8175364
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	movs r7, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldrh r0, [r6]
	cmp r0, 0x1
	beq _081753E0
	cmp r0, 0x1
	bgt _08175394
	cmp r0, 0
	beq _0817539C
	b _081754B0
	.pool
_08175394:
	cmp r0, 0xFF
	bne _0817539A
	b _081754A0
_0817539A:
	b _081754B0
_0817539C:
	movs r0, 0x40
	bl sub_81521C0
	cmp r0, 0
	bne _081753B8
	adds r0, r4, 0
	bl DestroyTask
	ldr r0, =gUnknown_020375E0
	strh r7, [r0]
	ldr r1, =gUnknown_020375E2
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_081753B8:
	ldr r0, =gUnknown_085E5394
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085E53A4
	bl LoadCompressedObjectPalette
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	b _081754B0
	.pool
_081753E0:
	ldrh r0, [r6, 0x2]
	cmp r0, 0
	beq _08175478
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08175478
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF0
	bl __umodsi3
	adds r5, r0, 0
	lsls r5, 16
	asrs r5, 16
	bl GenerateRandomNumber
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x7
	ands r4, r0
	negs r4, r4
	lsls r4, 16
	asrs r4, 16
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x11
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_085E53FC
	ldr r2, =0x000003e9
	str r4, [sp]
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	adds r0, r1, 0
	adds r1, r2, 0
	adds r3, r5, 0
	bl sub_81524C4
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0xFF
	beq _08175478
	adds r4, r7, 0
	ldr r1, =sub_81752F4
	adds r0, r4, 0
	bl sub_8152438
	bl GenerateRandomNumber
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0
	bne _08175468
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8152474
_08175468:
	adds r0, r4, 0
	movs r1, 0x7
	mov r2, r8
	bl sub_8152474
	ldrh r0, [r6, 0x1E]
	adds r0, 0x1
	strh r0, [r6, 0x1E]
_08175478:
	bl sub_81522D4
	ldrh r0, [r6, 0x2]
	cmp r0, 0
	beq _08175494
	subs r0, 0x1
	strh r0, [r6, 0x2]
	b _081754B0
	.pool
_08175494:
	ldrh r0, [r6, 0x1E]
	cmp r0, 0
	bne _081754B0
	movs r0, 0xFF
	strh r0, [r6]
	b _081754B0
_081754A0:
	bl sub_81752C0
	ldr r0, =gUnknown_020375E0
	strh r7, [r0]
	ldr r1, =gUnknown_020375E2
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
_081754B0:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175364

	thumb_func_start sub_81754C8
sub_81754C8: @ 81754C8
	push {lr}
	bl LoadOamFromSprites
	bl ProcessObjectCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81754C8

	thumb_func_start sub_81754DC
sub_81754DC: @ 81754DC
	push {lr}
	bl RunTasks
	bl CallObjectCallbacks
	ldr r0, =gUnknown_030022C0
	ldrh r1, [r0, 0x2C]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08175522
	ldr r0, =gUnknown_0203BCE4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08175522
	ldr r2, =gTasks
	ldr r0, =gUnknown_0203BCE2
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =sub_8175774
	cmp r1, r0
	bne _08175522
	bl sub_81754C8
	bl RunTasks
	bl CallObjectCallbacks
	ldr r1, =gUnknown_0203BCE5
	movs r0, 0x1
	strb r0, [r1]
_08175522:
	bl PrepareSpritesForOamLoad
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81754DC

	thumb_func_start sub_8175548
sub_8175548: @ 8175548
	push {lr}
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_085E6F68
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	movs r0, 0x80
	lsls r0, 4
	bl AllocZeroed
	adds r1, r0, 0
	movs r0, 0
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_085E56F0
	movs r1, 0x80
	movs r2, 0x40
	bl LoadPalette
	ldr r0, =gUnknown_085E6F6C
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	movs r0, 0
	bl ShowBg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175548

	thumb_func_start sub_81755A4
sub_81755A4: @ 81755A4
	push {lr}
	bl FreeAllWindowBuffers
	movs r0, 0
	bl GetBgTilemapBuffer
	cmp r0, 0
	beq _081755B8
	bl Free
_081755B8:
	pop {r0}
	bx r0
	thumb_func_end sub_81755A4

	thumb_func_start sub_81755BC
sub_81755BC: @ 81755BC
	push {r4,r5,lr}
	sub sp, 0x18
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	add r1, sp, 0x14
	movs r0, 0
	strb r0, [r1]
	cmp r2, 0x1
	bne _081755DC
	movs r0, 0x3
	strb r0, [r1, 0x1]
	movs r0, 0x4
	b _081755E4
_081755DC:
	add r1, sp, 0x14
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
_081755E4:
	strb r0, [r1, 0x2]
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xF0
	movs r3, 0x1
	bl GetStringCenterAlignXOffsetWithLetterSpacing
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x14
	str r0, [sp, 0x8]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0xC]
	str r4, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	adds r3, r5, 0
	bl AddTextPrinterParametrized2
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81755BC

	thumb_func_start sub_8175620
sub_8175620: @ 8175620
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	bl sub_8175CE4
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
	bl ResetPaletteFade
	bl ResetTasks
	bl sub_8175548
	ldr r0, =sub_8175744
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x16]
	strh r1, [r0, 0x1E]
	movs r1, 0x1
	strh r1, [r0, 0x22]
_0817566A:
	movs r0, 0
	adds r1, r7, 0
	bl sub_8176AB0
	lsls r0, 24
	cmp r0, 0
	beq _0817566A
	ldr r5, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r5
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0
	mov r8, r1
	movs r6, 0
	movs r1, 0x28
	strh r1, [r0, 0x8]
	ldr r1, =0x0000fffc
	movs r0, 0x12
	bl SetGpuReg
	ldr r0, =sub_8175DA0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	strh r7, [r1, 0xA]
	strh r0, [r4, 0x26]
	movs r0, 0x1
	negs r0, r0
	str r6, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_81754C8
	bl SetVBlankCallback
	ldr r0, =0x000001c7
	bl m4aSongNumStart
	ldr r0, =sub_81754DC
	bl SetMainCallback2
	ldr r0, =gUnknown_0203BCE5
	mov r1, r8
	strb r1, [r0]
	ldr r4, =gUnknown_0203BCE8
	movs r0, 0xEB
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	bl sub_8177388
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8E
	strh r6, [r0]
	adds r0, 0x2
	strh r6, [r0]
	adds r0, 0x2
	strh r6, [r0]
	ldr r0, =gUnknown_0203BCE2
	strh r7, [r0]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175620

	thumb_func_start sub_8175744
sub_8175744: @ 8175744
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175764
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8175774
	str r0, [r1]
_08175764:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175744

	thumb_func_start sub_8175774
sub_8175774: @ 8175774
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _081757B0
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x1E
	strh r1, [r0, 0x8]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r4, 0x20]
	ldr r0, =sub_8175A9C
	b _081757FA
	.pool
_081757B0:
	ldr r0, =gUnknown_0203BCE0
	strh r1, [r0]
	ldrh r2, [r4, 0x1E]
	movs r3, 0x1E
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	bne _081757E0
	strh r2, [r4, 0x22]
	strh r1, [r4, 0x1E]
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175808
	b _081757FA
	.pool
_081757E0:
	cmp r0, 0x2
	bne _081757FC
	strh r2, [r4, 0x22]
	strh r1, [r4, 0x1E]
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_81758A4
_081757FA:
	str r0, [r4]
_081757FC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175774

	thumb_func_start sub_8175808
sub_8175808: @ 8175808
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175836
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_8176CA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =c2_080C9BFC
	str r0, [r1]
_08175836:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175808

	thumb_func_start c2_080C9BFC
c2_080C9BFC: @ 8175848
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl SetVBlankCallback
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r5, r0, r1
	ldrb r0, [r5, 0x16]
	adds r1, r4, 0
	bl sub_8176AB0
	lsls r0, 24
	cmp r0, 0
	beq _08175890
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	bl EnableInterrupts
	ldr r0, =sub_81754C8
	bl SetVBlankCallback
	ldr r0, =sub_8175744
	str r0, [r5]
_08175890:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_080C9BFC

	thumb_func_start sub_81758A4
sub_81758A4: @ 81758A4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081758D2
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	adds r0, r4, 0
	bl sub_8176CA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81758E4
	str r0, [r1]
_081758D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81758A4

	thumb_func_start sub_81758E4
sub_81758E4: @ 81758E4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_030022C0
	movs r1, 0x87
	lsls r1, 3
	adds r1, r0
	mov r8, r1
	ldrb r7, [r1]
	cmp r7, 0
	beq _08175906
	cmp r7, 0x1
	beq _081759F0
_08175906:
	bl ResetAllObjectData
	bl dp13_810BB8C
	bl ResetObjectPaletteAllocator
	ldr r1, =gUnknown_0300301C
	movs r0, 0x8
	strb r0, [r1]
	ldr r0, =gUnknown_085B0E04
	movs r1, 0xC0
	lsls r1, 19
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0C0C
	ldr r1, =0x06003800
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085B0A02
	movs r1, 0x1
	movs r2, 0x3E
	bl LoadPalette
	movs r1, 0
	ldr r4, =0x0201c000
	movs r3, 0x11
	ldr r2, =0x000007ff
_0817593C:
	adds r0, r1, r4
	strb r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bls _0817593C
	movs r1, 0
	ldr r2, =0x0201d800
	ldr r6, =gUnknown_085E701C
	ldr r0, =0xfffff000
	adds r5, r2, r0
	movs r4, 0x22
	ldr r3, =0x000007ff
_08175958:
	adds r0, r1, r5
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r3
	bls _08175958
	movs r1, 0
	ldr r5, =0x0201d000
	movs r4, 0x33
	ldr r3, =0x000007ff
_0817596E:
	adds r0, r1, r5
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r3
	bls _0817596E
	movs r0, 0
	strh r0, [r2]
	ldr r1, =0x000053ff
	adds r0, r1, 0
	strh r0, [r2, 0x2]
	ldr r1, =0x0000529f
	adds r0, r1, 0
	strh r0, [r2, 0x4]
	ldr r1, =0x00007e94
	adds r0, r1, 0
	strh r0, [r2, 0x6]
	adds r0, r6, 0
	bl LoadObjectPic
	ldr r0, =gUnknown_085E702C
	bl LoadTaggedObjectPalette
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08175A7A
	.pool
_081759F0:
	ldr r0, =sub_81760FC
	movs r1, 0
	bl CreateTask
	ldr r2, =gTasks
	lsls r4, r6, 2
	adds r4, r6
	lsls r4, 3
	adds r4, r2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	mov r9, r1
	movs r5, 0
	strh r0, [r4, 0xE]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r7, [r0, 0x8]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	strh r6, [r0, 0xA]
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrh r1, [r4, 0x16]
	strh r1, [r0, 0xC]
	movs r0, 0x1
	negs r0, r0
	str r5, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0x20
	bl SetGpuReg
	ldr r1, =0x00000703
	movs r0, 0xE
	bl SetGpuReg
	movs r1, 0xCA
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	mov r0, r9
	mov r1, r8
	strb r0, [r1]
	ldr r0, =gUnknown_0203BD28
	strh r5, [r0]
	ldr r0, =sub_8175744
	str r0, [r4]
_08175A7A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81758E4

	thumb_func_start sub_8175A9C
sub_8175A9C: @ 8175A9C
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x20]
	movs r2, 0x20
	ldrsh r1, [r4, r2]
	cmp r1, 0
	beq _08175AC4
	subs r0, 0x1
	strh r0, [r4, 0x20]
	b _08175AD8
	.pool
_08175AC4:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0xC
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175AE4
	str r0, [r4]
_08175AD8:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175A9C

	thumb_func_start sub_8175AE4
sub_8175AE4: @ 8175AE4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175B0A
	adds r0, r4, 0
	bl sub_8176CA0
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8175B1C
	str r0, [r1]
_08175B0A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175AE4

	thumb_func_start sub_8175B1C
sub_8175B1C: @ 8175B1C
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8175CE4
	bl ResetPaletteFade
	movs r1, 0xE0
	lsls r1, 6
	movs r0, 0
	movs r2, 0
	bl sub_8176D1C
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x8
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r1, 0xE0
	lsls r1, 3
	movs r0, 0x8
	bl SetGpuReg
	movs r0, 0x1
	bl EnableInterrupts
	movs r1, 0xA0
	lsls r1, 1
	movs r0, 0
	bl SetGpuReg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0xEB
	strh r1, [r0, 0x8]
	ldr r1, =sub_8175B90
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175B1C

	thumb_func_start sub_8175B90
sub_8175B90: @ 8175B90
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r0, [r4, 0x8]
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	cmp r1, 0
	beq _08175BB8
	subs r0, 0x1
	strh r0, [r4, 0x8]
	b _08175BCC
	.pool
_08175BB8:
	movs r0, 0x1
	negs r0, r0
	str r1, [sp]
	movs r1, 0x6
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175BD8
	str r0, [r4]
_08175BCC:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175B90

	thumb_func_start sub_8175BD8
sub_8175BD8: @ 8175BD8
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08175C1E
	movs r0, 0xE0
	lsls r0, 6
	movs r1, 0
	bl sub_8176E40
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0xE1
	lsls r1, 5
	strh r1, [r0, 0x8]
	ldr r1, =sub_8175C34
	str r1, [r0]
_08175C1E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175BD8

	thumb_func_start sub_8175C34
sub_8175C34: @ 8175C34
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175CB8
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _08175C62
	ldr r0, =gUnknown_030022C0
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	beq _08175C94
_08175C62:
	movs r0, 0x4
	bl play_sound_effect
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x8
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_8175CC8
	str r0, [r4]
	b _08175CB8
	.pool
_08175C94:
	ldr r0, =0x00001be8
	cmp r1, r0
	bne _08175CA0
	movs r0, 0x8
	bl play_sound_effect
_08175CA0:
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	ldr r0, =0x00001ab8
	cmp r1, r0
	bne _08175CB2
	movs r0, 0xE4
	lsls r0, 1
	bl m4aSongNumStart
_08175CB2:
	ldrh r0, [r4, 0x8]
	subs r0, 0x1
	strh r0, [r4, 0x8]
_08175CB8:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175C34

	thumb_func_start sub_8175CC8
sub_8175CC8: @ 8175CC8
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08175CDC
	movs r0, 0xFF
	bl SoftReset
_08175CDC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175CC8

	thumb_func_start sub_8175CE4
sub_8175CE4: @ 8175CE4
	push {lr}
	sub sp, 0x8
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x10
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x54
	movs r1, 0
	bl SetGpuReg
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	movs r0, 0xC0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x8100c000
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0
	str r2, [sp, 0x4]
	add r0, sp, 0x4
	str r0, [r1]
	movs r0, 0xE0
	lsls r0, 19
	str r0, [r1, 0x4]
	ldr r0, =0x85000100
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	mov r0, sp
	strh r2, [r0]
	str r0, [r1]
	ldr r0, =0x05000002
	str r0, [r1, 0x4]
	ldr r0, =0x810001ff
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175CE4

	thumb_func_start sub_8175DA0
sub_8175DA0: @ 8175DA0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r5, r1, 0
	cmp r0, 0xA
	bhi _08175E00
	lsls r0, 2
	ldr r1, =_08175DD4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08175DD4:
	.4byte _08175E00
	.4byte _08175E40
	.4byte _08175E60
	.4byte _08175F38
	.4byte _08175F5C
	.4byte _08175FC8
	.4byte _08175E00
	.4byte _08175E00
	.4byte _08175E00
	.4byte _08175E00
	.4byte _08175FFC
_08175E00:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08175E12
	b _0817602A
_08175E12:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r1, 0x1
	strh r1, [r0, 0x8]
	movs r1, 0x48
	strh r1, [r0, 0xE]
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	strh r2, [r0, 0x24]
	ldr r0, =gUnknown_0203BCE0
	strh r2, [r0]
	b _0817602A
	.pool
_08175E40:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r5
	ldrh r2, [r1, 0xE]
	movs r3, 0xE
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08175E58
	subs r0, r2, 0x1
	strh r0, [r1, 0xE]
	b _0817602A
_08175E58:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _0817602A
_08175E60:
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r3, r0, r5
	movs r0, 0xA
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r5, r0, r5
	ldr r1, [r5]
	ldr r0, =sub_8175774
	mov r9, r2
	cmp r1, r0
	bne _08175F32
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	cmp r0, 0x38
	bgt _08175F2C
	movs r5, 0
	ldr r2, =gUnknown_085E6AF4
	mov r8, r2
	adds r7, r3, 0
	movs r6, 0xA0
	lsls r6, 19
_08175E92:
	movs r3, 0xC
	ldrsh r1, [r7, r3]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r5
	lsls r0, 2
	add r0, r8
	ldr r2, [r0]
	ldr r0, [r2, 0x4]
	lsrs r1, r6, 24
	ldrb r2, [r2, 0x1]
	bl sub_81755BC
	movs r0, 0x80
	lsls r0, 21
	adds r6, r0
	adds r5, 0x1
	cmp r5, 0x4
	ble _08175E92
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r3, =gTasks
	mov r2, r9
	adds r1, r2, r4
	lsls r1, 3
	adds r1, r3
	ldrh r0, [r1, 0xC]
	adds r0, 0x1
	strh r0, [r1, 0xC]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0xA
	ldrsh r2, [r1, r0]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r3
	movs r2, 0x1
	strh r2, [r0, 0x24]
	movs r2, 0xA
	ldrsh r1, [r1, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r3
	movs r3, 0x22
	ldrsh r0, [r0, r3]
	cmp r0, 0x1
	bne _08175F14
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x0000328d
	b _08175F1A
	.pool
_08175F14:
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x00001967
_08175F1A:
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	b _0817602A
	.pool
_08175F2C:
	movs r0, 0xA
	strh r0, [r3, 0x8]
	b _0817602A
_08175F32:
	movs r0, 0
	strh r0, [r5, 0x24]
	b _0817602A
_08175F38:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817602A
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r1, 0x73
	strh r1, [r0, 0xE]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	b _0817602A
	.pool
_08175F5C:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r4, r0, r5
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08175F74
	subs r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _0817602A
_08175F74:
	ldrb r0, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	bl sub_817603C
	lsls r0, 24
	cmp r0, 0
	beq _08175F8A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0817602A
_08175F8A:
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _08175FB0
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x0000328d
	b _08175FB6
	.pool
_08175FB0:
	movs r0, 0xC0
	lsls r0, 2
	ldr r1, =0x00001967
_08175FB6:
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0817602A
	.pool
_08175FC8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817602A
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x2
	strh r0, [r1, 0x8]
	b _0817602A
	.pool
_08175FFC:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r5
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r5
	movs r5, 0
	movs r1, 0x1
	strh r1, [r0, 0x10]
	adds r0, r4, 0
	bl DestroyTask
	bl sub_81755A4
	ldr r4, =gUnknown_0203BCE8
	ldr r0, [r4]
	bl Free
	str r5, [r4]
_0817602A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8175DA0

	thumb_func_start sub_817603C
sub_817603C: @ 817603C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	lsls r1, 24
	lsrs r2, r1, 24
	adds r5, r2, 0
	ldr r4, =gTasks
	cmp r3, 0x6
	bne _0817605C
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_0817605C:
	cmp r3, 0xC
	bne _0817606E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0, 0x16]
	strh r1, [r0, 0x1E]
_0817606E:
	cmp r3, 0x12
	bne _0817607E
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_0817607E:
	cmp r3, 0x18
	bne _08176092
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x16]
	movs r1, 0x1
	strh r1, [r0, 0x1E]
_08176092:
	cmp r3, 0x1E
	bne _081760A2
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_081760A2:
	cmp r3, 0x24
	bne _081760B6
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x3
	strh r1, [r0, 0x16]
	movs r1, 0x1
	strh r1, [r0, 0x1E]
_081760B6:
	cmp r3, 0x2A
	bne _081760C6
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x1E]
_081760C6:
	cmp r6, 0x30
	bne _081760DA
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r4
	movs r1, 0x4
	strh r1, [r0, 0x16]
	movs r1, 0x1
	strh r1, [r0, 0x1E]
_081760DA:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r4
	movs r1, 0x1E
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _081760F4
	movs r0, 0
	b _081760F6
	.pool
_081760F4:
	movs r0, 0x1
_081760F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_817603C

	thumb_func_start sub_81760FC
sub_81760FC: @ 81760FC
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r4
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	beq _0817612C
	cmp r0, 0x1
	bgt _0817611A
	b _08176244
_0817611A:
	cmp r0, 0x2
	beq _08176158
	cmp r0, 0x3
	bne _08176124
	b _08176230
_08176124:
	b _08176244
	.pool
_0817612C:
	ldr r0, =gUnknown_0203BCE8
	ldr r0, [r0]
	adds r0, 0x90
	ldrh r0, [r0]
	cmp r0, 0
	bne _0817614E
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0817614E
	b _08176244
_0817614E:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	b _08176242
	.pool
_08176158:
	ldr r6, =gUnknown_0203BCE8
	ldr r3, [r6]
	adds r0, r3, 0
	adds r0, 0x8E
	ldrh r0, [r0]
	cmp r0, 0x47
	beq _08176244
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, [r0]
	ldr r0, =sub_8175774
	cmp r1, r0
	bne _08176244
	adds r0, r3, 0
	adds r0, 0x92
	ldrh r0, [r0]
	lsls r0, 1
	adds r0, r3, r0
	ldrh r0, [r0]
	ldr r4, =gUnknown_085E6F7C
	adds r1, r3, 0
	adds r1, 0x90
	ldrh r3, [r1]
	lsls r2, r3, 1
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, 0x1
	adds r2, r4
	ldrb r2, [r2]
	bl sub_8177224
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, [r6]
	adds r1, r0, 0
	adds r1, 0x92
	ldrh r3, [r1]
	adds r0, 0x94
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r3, r0
	bge _081761D8
	adds r0, r3, 0x1
	strh r0, [r1]
	ldr r1, =gUnknown_02020630
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x32
	b _081761EA
	.pool
_081761D8:
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02020630
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x80
	lsls r1, 2
_081761EA:
	strh r1, [r0, 0x34]
	ldr r0, =gUnknown_0203BCE8
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x8E
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x90
	ldrh r0, [r1]
	cmp r0, 0x2
	bne _08176210
	movs r0, 0
	b _08176212
	.pool
_08176210:
	adds r0, 0x1
_08176212:
	strh r0, [r1]
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0x32
	strh r0, [r1, 0xE]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08176244
	.pool
_08176230:
	ldrh r1, [r2, 0xE]
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r0, 0
	beq _08176240
	subs r0, r1, 0x1
	strh r0, [r2, 0xE]
	b _08176244
_08176240:
	movs r0, 0x1
_08176242:
	strh r0, [r2, 0x8]
_08176244:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81760FC

	thumb_func_start sub_817624C
sub_817624C: @ 817624C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	adds r6, r1, 0
	cmp r0, 0x32
	bls _08176268
	b _08176514
_08176268:
	lsls r0, 2
	ldr r1, =_0817627C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0817627C:
	.4byte _08176348
	.4byte _0817636C
	.4byte _081763C0
	.4byte _081763D8
	.4byte _08176414
	.4byte _08176438
	.4byte _08176484
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176490
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _081764B0
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _081764D4
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176514
	.4byte _08176508
_08176348:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r6
	ldrh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 17
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0xC
	bl sine
	ldr r1, =gUnknown_0203BD26
	strh r0, [r1]
	b _08176390
	.pool
_0817636C:
	ldr r7, =gUnknown_0203BD26
	movs r3, 0
	ldrsh r4, [r7, r3]
	cmp r4, 0
	beq _0817639C
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r6
	ldrh r0, [r4, 0x12]
	lsls r0, 16
	asrs r0, 17
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0xC
	bl sine
	strh r0, [r7]
_08176390:
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
	b _08176514
	.pool
_0817639C:
	ldr r3, =gUnknown_02020630
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r2, 0x2
	strh r2, [r0, 0x2E]
	strh r4, [r1, 0x12]
	b _08176430
	.pool
_081763C0:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r6
	ldrh r2, [r1, 0x12]
	movs r3, 0x12
	ldrsh r0, [r1, r3]
	cmp r0, 0x3F
	bgt _08176430
	adds r0, r2, 0x1
	strh r0, [r1, 0x12]
	b _0817644E
_081763D8:
	ldr r3, =gUnknown_02020630
	lsls r2, r5, 2
	adds r2, r5
	lsls r2, 3
	adds r2, r6
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x3
	strh r1, [r0, 0x2E]
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	movs r0, 0x78
	strh r0, [r2, 0x10]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	b _08176514
	.pool
_08176414:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r1, r0, r6
	ldrh r2, [r1, 0x10]
	movs r3, 0x10
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0817642C
	subs r0, r2, 0x1
	strh r0, [r1, 0x10]
	b _08176514
_0817642C:
	movs r0, 0x40
	strh r0, [r1, 0x12]
_08176430:
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	b _08176514
_08176438:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r6
	ldrh r1, [r4, 0x12]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _08176464
	subs r0, r1, 0x1
	strh r0, [r4, 0x12]
_0817644E:
	movs r1, 0x7F
	ands r0, r1
	movs r1, 0x14
	bl sine
	ldr r1, =gUnknown_0203BD26
	strh r0, [r1]
	b _08176514
	.pool
_08176464:
	ldr r2, =gUnknown_02020630
	movs r3, 0xC
	ldrsh r1, [r4, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _08176514
	.pool
_08176484:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r6
	movs r1, 0x32
	b _08176512
_08176490:
	ldr r3, =gUnknown_02020630
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r2, 0x2
	b _081764C8
	.pool
_081764B0:
	ldr r3, =gUnknown_02020630
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	movs r2, 0x4
_081764C8:
	strh r2, [r0, 0x2E]
	movs r0, 0x32
	strh r0, [r1, 0x8]
	b _08176514
	.pool
_081764D4:
	ldr r3, =gUnknown_02020630
	lsls r2, r5, 2
	adds r2, r5
	lsls r2, 3
	adds r2, r6
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x5
	strh r1, [r0, 0x2E]
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0x3
	strh r1, [r0, 0x2E]
	movs r0, 0x32
	strh r0, [r2, 0x8]
	b _08176514
	.pool
_08176508:
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r6
	movs r1, 0
_08176512:
	strh r1, [r0, 0x8]
_08176514:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_817624C

	thumb_func_start sub_817651C
sub_817651C: @ 817651C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	movs r3, 0x8
	ldrsh r0, [r0, r3]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0817655C
	lsls r0, 2
	ldr r1, =_08176548
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08176548:
	.4byte _0817655C
	.4byte _081765A0
	.4byte _081765AC
	.4byte _081765F4
	.4byte _08176640
_0817655C:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r2, r0, r4
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	ldr r5, =0x00007fff
	cmp r0, r5
	beq _081765A0
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r3, r0, r4
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	bne _081765A0
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	movs r0, 0x14
	strh r0, [r1, 0x8]
	strh r5, [r2, 0xA]
_081765A0:
	movs r0, 0
	bl sub_817B540
	b _08176646
	.pool
_081765AC:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r2, r0, r4
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	ldr r5, =0x00007fff
	cmp r0, r5
	beq _08176638
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r3, r0, r4
	ldrh r1, [r3, 0x12]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	movs r1, 0xA0
	lsls r1, 2
	cmp r0, r1
	bne _08176638
	movs r0, 0x1
	strh r0, [r3, 0x8]
	strh r5, [r2, 0xA]
	b _08176638
	.pool
_081765F4:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r2, r0, r4
	ldrh r3, [r2, 0xA]
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	ldr r5, =0x00007fff
	cmp r1, r5
	beq _08176638
	movs r0, 0x92
	lsls r0, 2
	cmp r1, r0
	bne _08176634
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	movs r1, 0xA
	strh r1, [r0, 0x8]
	strh r5, [r2, 0xA]
	b _08176638
	.pool
_08176634:
	adds r0, r3, 0x1
	strh r0, [r2, 0xA]
_08176638:
	movs r0, 0x1
	bl sub_817B540
	b _08176646
_08176640:
	movs r0, 0x2
	bl sub_817B540
_08176646:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817651C

	thumb_func_start sub_817664C
sub_817664C: @ 817664C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r0, 0x4
	bls _08176662
	b _081769E0
_08176662:
	lsls r0, 2
	ldr r1, =_08176670
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08176670:
	.4byte _08176684
	.4byte _0817672C
	.4byte _081767D8
	.4byte _08176884
	.4byte _08176934
_08176684:
	ldr r5, =gUnknown_02020630
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r2, 0x88
	lsls r2, 1
	strh r2, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	movs r2, 0x20
	b _081769D4
	.pool
_0817672C:
	ldr r5, =gUnknown_02020630
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r0, 0
	movs r2, 0x20
	b _081769D4
	.pool
_081767D8:
	ldr r5, =gUnknown_02020630
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x88
	lsls r1, 1
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x1
	b _081769D4
	.pool
_08176884:
	ldr r5, =gUnknown_02020630
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x78
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffe0
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x1
	b _081769D4
	.pool
_08176934:
	ldr r5, =gUnknown_02020630
	ldr r0, =gTasks
	lsls r4, r7, 2
	adds r4, r7
	lsls r4, 3
	adds r4, r0
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r1]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r3, 0
	movs r1, 0x58
	strh r1, [r0, 0x20]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x98
	strh r1, [r0, 0x20]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r2, 0x2E
	strh r2, [r0, 0x22]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	movs r0, 0x12
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r0, 0x14
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r3, [r0, 0x2E]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x2
_081769D4:
	movs r3, 0x8
	bl sub_817B3DC
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x8]
_081769E0:
	ldr r0, =sub_817651C
	movs r1, 0
	bl CreateTask
	ldr r6, =gTasks
	lsls r1, r7, 2
	adds r1, r7
	lsls r1, 3
	adds r5, r1, r6
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0
	strh r0, [r5, 0xC]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	mov r1, r8
	strh r1, [r0, 0x8]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r4, [r0, 0xA]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r7, [r0, 0xC]
	ldr r0, =sub_817624C
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r4, [r0, 0x8]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r7, [r0, 0xA]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldrh r1, [r5, 0x12]
	strh r1, [r0, 0xC]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	ldrh r1, [r5, 0x14]
	strh r1, [r0, 0xE]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r6
	strh r4, [r0, 0x10]
	mov r1, r8
	cmp r1, 0x2
	bne _08176A94
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r6
	movs r0, 0x45
	strh r0, [r1, 0x12]
_08176A94:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817664C

	thumb_func_start sub_8176AB0
sub_8176AB0: @ 8176AB0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_030022C0
	movs r1, 0x87
	lsls r1, 3
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _08176B30
	cmp r0, 0x1
	ble _08176AD6
	cmp r0, 0x2
	beq _08176B54
	cmp r0, 0x3
	bne _08176AD6
	b _08176C80
_08176AD6:
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1C
	movs r1, 0x8
	bl SetGpuReg
	movs r0, 0x1E
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x18
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x1A
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x14
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x16
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	bl ResetAllObjectData
	bl ResetObjectPaletteAllocator
	movs r0, 0x1
	strb r0, [r6]
	b _08176C96
	.pool
_08176B30:
	ldr r1, =gUnknown_0203BD24
	movs r0, 0x22
	strh r0, [r1]
	ldr r1, =gUnknown_0203BD26
	movs r0, 0
	strh r0, [r1]
	adds r0, r4, 0
	bl sub_817B1C8
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _08176C96
	.pool
_08176B54:
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _08176BD8
	ldr r0, =gUnknown_085F5334
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F53BC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5354
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5384
	bl LoadTaggedObjectPalettes
	movs r0, 0x78
	movs r1, 0x2E
	bl sub_817B834
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	strh r2, [r4, 0x12]
	ldr r6, =gUnknown_02020630
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r6, 0
	adds r5, 0x1C
	adds r2, r0, r5
	ldr r1, =sub_8176EE8
	str r1, [r2]
	adds r6, 0x8
	adds r0, r6
	ldr r1, =gUnknown_085E6FD0
	str r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x2E
	bl sub_817B88C
	b _08176C2C
	.pool
_08176BD8:
	ldr r0, =gUnknown_085F5344
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F53AC
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5354
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_085F5384
	bl LoadTaggedObjectPalettes
	movs r0, 0x78
	movs r1, 0x2E
	bl sub_817B88C
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	strh r2, [r4, 0x12]
	ldr r6, =gUnknown_02020630
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r6, 0
	adds r5, 0x1C
	adds r2, r0, r5
	ldr r1, =sub_8176EE8
	str r1, [r2]
	adds r6, 0x8
	adds r0, r6
	ldr r1, =gUnknown_085E6FD0
	str r1, [r0]
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x2E
	bl sub_817B834
_08176C2C:
	lsls r0, 24
	lsrs r2, r0, 24
	strh r2, [r4, 0x14]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r5, r0, r5
	ldr r1, =sub_8176F90
	str r1, [r5]
	adds r0, r6
	ldr r1, =gUnknown_085E7010
	str r1, [r0]
	ldr r1, =gUnknown_030022C0
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08176C96
	.pool
_08176C80:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_817664C
	adds r0, r4, 0
	bl sub_817B3A8
	movs r0, 0
	strb r0, [r6]
	movs r0, 0x1
	b _08176C98
_08176C96:
	movs r0, 0
_08176C98:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8176AB0

	thumb_func_start sub_8176CA0
sub_8176CA0: @ 8176CA0
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0x8]
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176CC6
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0x8]
_08176CC6:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176CDC
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0xA]
_08176CDC:
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176CF2
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0xC]
_08176CF2:
	ldrh r1, [r4, 0xE]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08176D08
	lsls r0, r1, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	strh r0, [r4, 0xE]
_08176D08:
	ldr r1, =gUnknown_0203BD28
	movs r0, 0x1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8176CA0

	thumb_func_start sub_8176D1C
sub_8176D1C: @ 8176D1C
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r4, 16
	lsrs r5, r4, 16
	ldr r0, =gUnknown_085E5770
	movs r6, 0xC0
	lsls r6, 19
	adds r3, r6
	adds r1, r3, 0
	bl LZ77UnCompVram
	ldr r0, =gIntroCopyright_Pal
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadPalette
	lsrs r4, 20
	lsls r4, 28
	lsrs r4, 16
	movs r1, 0
	adds r4, 0x1
	ldr r2, =0x000003ff
_08176D52:
	lsls r0, r1, 1
	adds r0, r7
	adds r0, r6
	strh r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r2
	bls _08176D52
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8176D1C

	thumb_func_start sub_8176D78
sub_8176D78: @ 8176D78
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, r2, 0
	movs r0, 0x3F
	ands r0, r2
	adds r1, r0, 0
	adds r1, 0x50
	cmp r2, 0xFF
	bne _08176D90
	movs r0, 0x1
	b _08176DB6
_08176D90:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _08176DA0
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r1, r0
_08176DA0:
	movs r0, 0x40
	ands r3, r0
	cmp r3, 0
	beq _08176DB4
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2, 0
	orrs r1, r0
	lsls r0, r1, 16
	lsrs r1, r0, 16
_08176DB4:
	adds r0, r1, 0
_08176DB6:
	pop {r1}
	bx r1
	thumb_func_end sub_8176D78

	thumb_func_start sub_8176DBC
sub_8176DBC: @ 8176DBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp]
	ldr r0, [sp, 0x2C]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x4]
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp, 0x8]
	lsls r0, 16
	lsrs r0, 20
	lsls r0, 28
	lsrs r0, 16
	mov r9, r0
	movs r5, 0
_08176DEA:
	movs r4, 0
	lsls r7, r5, 1
	ldr r1, [sp, 0x4]
	adds r0, r1, r5
	adds r2, r5, 0x1
	mov r8, r2
	lsls r0, 6
	ldr r1, [sp, 0x8]
	adds r6, r0, r1
_08176DFC:
	adds r0, r7, r5
	adds r0, r4
	ldr r2, [sp]
	adds r0, r2, r0
	ldrb r0, [r0]
	bl sub_8176D78
	mov r2, r10
	adds r1, r2, r4
	lsls r1, 1
	adds r1, r6
	movs r2, 0xC0
	lsls r2, 19
	adds r1, r2
	add r0, r9
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _08176DFC
	mov r1, r8
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _08176DEA
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8176DBC

	thumb_func_start sub_8176E40
sub_8176E40: @ 8176E40
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsrs r1, 20
	lsls r1, 28
	lsrs r1, 16
	movs r2, 0
	ldr r7, =gUnknown_085E5BAC
	movs r4, 0xC0
	lsls r4, 19
	adds r1, 0x1
	ldr r3, =0x000003ff
_08176E5E:
	lsls r0, r2, 1
	adds r0, r5
	adds r0, r4
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	bls _08176E5E
	str r6, [sp]
	adds r0, r7, 0
	movs r1, 0x3
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r0, =gUnknown_085E5BBB
	str r6, [sp]
	movs r1, 0x7
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r4, =gUnknown_085E5BCA
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0x10
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r0, =gUnknown_085E5BD9
	str r6, [sp]
	movs r1, 0x14
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	ldr r0, =gUnknown_085E5BE8
	str r6, [sp]
	movs r1, 0x18
	movs r2, 0x7
	adds r3, r5, 0
	bl sub_8176DBC
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8176E40

	thumb_func_start sub_8176EE8
sub_8176EE8: @ 8176EE8
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08176F04
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
	b _08176F88
	.pool
_08176F04:
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0x5
	bhi _08176F88
	lsls r0, 2
	ldr r1, =_08176F1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08176F1C:
	.4byte _08176F34
	.4byte _08176F3E
	.4byte _08176F44
	.4byte _08176F4E
	.4byte _08176F58
	.4byte _08176F6E
_08176F34:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	b _08176F88
_08176F3E:
	adds r0, r4, 0
	movs r1, 0x1
	b _08176F72
_08176F44:
	adds r0, r4, 0
	movs r1, 0x2
	bl StartObjectImageAnimIfDifferent
	b _08176F88
_08176F4E:
	adds r0, r4, 0
	movs r1, 0x3
	bl StartObjectImageAnimIfDifferent
	b _08176F88
_08176F58:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	ldrh r1, [r4, 0x20]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	cmp r0, 0x78
	ble _08176F88
	subs r0, r1, 0x1
	b _08176F86
_08176F6E:
	adds r0, r4, 0
	movs r1, 0
_08176F72:
	bl StartObjectImageAnimIfDifferent
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _08176F88
	subs r0, r2, 0x1
_08176F86:
	strh r0, [r4, 0x20]
_08176F88:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8176EE8

	thumb_func_start sub_8176F90
sub_8176F90: @ 8176F90
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08176FAC
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
	b _08177048
	.pool
_08176FAC:
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _08176FD4
	cmp r0, 0x1
	bgt _08176FBE
	cmp r0, 0
	beq _08176FC8
	b _08177048
_08176FBE:
	cmp r0, 0x2
	beq _08177010
	cmp r0, 0x3
	beq _0817702E
	b _08177048
_08176FC8:
	strh r0, [r4, 0x26]
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	b _08177048
_08176FD4:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0xC8
	ble _08176FE6
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectImageAnimIfDifferent
	b _08176FEE
_08176FE6:
	adds r0, r4, 0
	movs r1, 0x2
	bl StartObjectImageAnimIfDifferent
_08176FEE:
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _08177000
	subs r0, r2, 0x2
	strh r0, [r4, 0x20]
_08177000:
	ldr r0, =gUnknown_0203BD26
	ldrh r0, [r0]
	negs r0, r0
	strh r0, [r4, 0x26]
	b _08177048
	.pool
_08177010:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	ldrh r1, [r4, 0x3C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08177048
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	b _08177046
_0817702E:
	adds r0, r4, 0
	movs r1, 0
	bl StartObjectImageAnimIfDifferent
	ldrh r2, [r4, 0x20]
	movs r0, 0x20
	ldrsh r1, [r4, r0]
	movs r0, 0x20
	negs r0, r0
	cmp r1, r0
	ble _08177048
	subs r0, r2, 0x1
_08177046:
	strh r0, [r4, 0x20]
_08177048:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8176F90

	thumb_func_start sub_8177050
sub_8177050: @ 8177050
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r0, =gUnknown_0203BD28
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0817706C
	ldrh r0, [r5, 0x3A]
	bl sub_818D820
	b _0817721C
	.pool
_0817706C:
	ldrh r0, [r5, 0x3C]
	adds r0, 0x1
	strh r0, [r5, 0x3C]
	movs r2, 0x2E
	ldrsh r0, [r5, r2]
	cmp r0, 0xA
	bhi _081770B4
	lsls r0, 2
	ldr r1, =_08177088
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08177088:
	.4byte _081770B4
	.4byte _0817710E
	.4byte _08177190
	.4byte _081771C6
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081770B4
	.4byte _081771FE
	.4byte _08177206
_081770B4:
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r5, 0x1]
	movs r0, 0x30
	ldrsh r1, [r5, r0]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r5, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x3]
	movs r0, 0x10
	strh r0, [r5, 0x32]
	ldrh r4, [r5, 0x30]
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x80
	lsls r0, 9
	movs r1, 0x10
	bl __divsi3
	adds r1, r0, 0
	str r1, [sp]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x1
	strh r0, [r5, 0x2E]
	b _0817721C
_0817710E:
	ldrh r1, [r5, 0x32]
	movs r2, 0x32
	ldrsh r0, [r5, r2]
	cmp r0, 0xFF
	bgt _08177144
	adds r0, r1, 0
	adds r0, 0x8
	strh r0, [r5, 0x32]
	ldrh r4, [r5, 0x30]
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x32
	ldrsh r1, [r5, r0]
	movs r0, 0x80
	lsls r0, 9
	bl __divsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	b _0817714A
_08177144:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
_0817714A:
	movs r2, 0x30
	ldrsh r1, [r5, r2]
	cmp r1, 0x2
	beq _0817721C
	cmp r1, 0x2
	bgt _0817715C
	cmp r1, 0x1
	beq _08177162
	b _0817721C
_0817715C:
	cmp r1, 0x3
	beq _0817717A
	b _0817721C
_08177162:
	ldrh r1, [r5, 0x3C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08177172
	ldrh r0, [r5, 0x22]
	adds r0, 0x1
	strh r0, [r5, 0x22]
_08177172:
	ldrh r0, [r5, 0x20]
	subs r0, 0x2
	strh r0, [r5, 0x20]
	b _0817721C
_0817717A:
	ldrh r0, [r5, 0x3C]
	ands r1, r0
	cmp r1, 0
	bne _08177188
	ldrh r0, [r5, 0x22]
	adds r0, 0x1
	strh r0, [r5, 0x22]
_08177188:
	ldrh r0, [r5, 0x20]
	adds r0, 0x2
	strh r0, [r5, 0x20]
	b _0817721C
_08177190:
	ldrh r1, [r5, 0x34]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _081771A0
	subs r0, r1, 0x1
	strh r0, [r5, 0x34]
	b _0817721C
_081771A0:
	movs r1, 0xF4
	lsls r1, 4
	movs r0, 0x50
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0x10
	bl SetGpuReg
	ldrb r1, [r5, 0x1]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x1]
	movs r0, 0x10
	strh r0, [r5, 0x34]
	b _081771FE
_081771C6:
	ldrh r1, [r5, 0x34]
	movs r2, 0x34
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _081771EC
	subs r1, 0x1
	strh r1, [r5, 0x34]
	movs r0, 0x34
	ldrsh r2, [r5, r0]
	movs r0, 0x10
	subs r0, r2
	lsls r0, 8
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x52
	bl SetGpuReg
	b _0817721C
_081771EC:
	adds r2, r5, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x9
	strh r0, [r5, 0x2E]
	b _0817721C
_081771FE:
	ldrh r0, [r5, 0x2E]
	adds r0, 0x1
	strh r0, [r5, 0x2E]
	b _0817721C
_08177206:
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	ldrh r0, [r5, 0x3A]
	bl sub_818D820
_0817721C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8177050

	thumb_func_start sub_8177224
sub_8177224: @ 8177224
	push {r4-r7,lr}
	adds r5, r3, 0
	lsls r0, 16
	lsrs r0, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r3, r5, 0
	bl sub_80C0E9C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gUnknown_02020630
	lsls r1, r4, 4
	adds r1, r4
	lsls r1, 2
	adds r2, r1, r6
	ldrb r3, [r2, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r3
	movs r3, 0x4
	orrs r0, r3
	strb r0, [r2, 0x5]
	adds r0, r5, 0x1
	strh r0, [r2, 0x30]
	movs r0, 0x3E
	adds r0, r2
	mov r12, r0
	ldrb r0, [r0]
	orrs r0, r3
	mov r3, r12
	strb r0, [r3]
	adds r0, r6, 0
	adds r0, 0x1C
	adds r1, r0
	ldr r0, =sub_8177050
	str r0, [r1]
	strh r4, [r2, 0x3A]
	ldr r0, =gUnknown_085E7068
	movs r7, 0x20
	ldrsh r1, [r2, r7]
	movs r3, 0x22
	ldrsh r2, [r2, r3]
	movs r3, 0x1
	bl AddObjectToFront
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	strh r4, [r0, 0x2E]
	lsls r5, 24
	lsrs r5, 24
	adds r1, r5, 0
	bl StartObjectImageAnimIfDifferent
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8177224

	thumb_func_start sub_81772B8
sub_81772B8: @ 81772B8
	push {r4,lr}
	adds r3, r0, 0
	ldr r4, =gUnknown_02020630
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0xA
	beq _081772DC
	ldr r0, =gUnknown_0203BD28
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _081772EC
_081772DC:
	adds r0, r3, 0
	bl RemoveObjectAndFreeTiles
	b _08177380
	.pool
_081772EC:
	adds r0, r1, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	movs r1, 0x3E
	adds r1, r3
	mov r12, r1
	movs r1, 0x4
	ands r1, r0
	mov r0, r12
	ldrb r2, [r0]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r0, 0xC
	ands r0, r1
	ldrb r2, [r3, 0x1]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	movs r0, 0x2E
	ldrsh r2, [r3, r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r2, 0x4
	negs r2, r2
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	movs r2, 0x2E
	ldrsh r1, [r3, r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	movs r1, 0x3E
	ands r1, r0
	ldrb r2, [r3, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x20]
	strh r0, [r3, 0x20]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x22]
	strh r0, [r3, 0x22]
_08177380:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81772B8

	thumb_func_start sub_8177388
sub_8177388: @ 8177388
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =0x00004023
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	bl sub_8133EDC
	lsls r0, 16
	lsrs r0, 16
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	movs r4, 0x1
	movs r6, 0
	ldr r5, =0x00000181
_081773B4:
	adds r0, r4, 0
	movs r1, 0x1
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	beq _081773D4
	ldr r0, =gUnknown_0203BCE8
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0x96
	adds r0, r1
	strh r4, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_081773D4:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r5
	bls _081773B4
	adds r4, r6, 0
	ldr r0, =0x00000181
	ldr r1, =gUnknown_0203BCE8
	mov r8, r1
	lsls r7, r4, 16
	cmp r4, r0
	bhi _08177406
	mov r5, r8
	movs r3, 0
	adds r2, r0, 0
_081773F2:
	ldr r0, [r5]
	lsls r1, r4, 1
	adds r0, 0x96
	adds r0, r1
	strh r3, [r0]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r2
	bls _081773F2
_08177406:
	mov r2, r8
	ldr r1, [r2]
	ldr r2, =0x0000039a
	adds r0, r1, r2
	strh r6, [r0]
	lsrs r0, r7, 16
	cmp r0, 0x46
	bhi _08177430
	adds r0, r1, 0
	adds r0, 0x94
	strh r6, [r0]
	b _08177436
	.pool
_08177430:
	adds r1, 0x94
	movs r0, 0x47
	strh r0, [r1]
_08177436:
	movs r6, 0
	ldr r0, =gUnknown_0203BCE8
	mov r9, r0
	ldr r1, =0x0000039a
	mov r8, r1
	movs r7, 0
	b _08177450
	.pool
_0817744C:
	cmp r6, 0x46
	bhi _081774AC
_08177450:
	bl GenerateRandomNumber
	mov r2, r9
	ldr r4, [r2]
	mov r1, r8
	adds r5, r4, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r5]
	bl __umodsi3
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, r6, 1
	adds r1, r4, r1
	lsls r0, r3, 1
	adds r4, 0x96
	adds r2, r4, r0
	ldrh r0, [r2]
	strh r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	strh r7, [r2]
	ldrh r0, [r5]
	subs r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r3, r0
	beq _081774A0
	ldrh r0, [r5]
	lsls r0, 1
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldrh r0, [r5]
	lsls r0, 1
	adds r0, r4, r0
	strh r7, [r0]
_081774A0:
	mov r2, r9
	ldr r0, [r2]
	add r0, r8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0817744C
_081774AC:
	ldr r1, =gUnknown_0203BCE8
	ldr r2, [r1]
	adds r3, r2, 0
	adds r3, 0x94
	ldrh r0, [r3]
	mov r8, r1
	cmp r0, 0x46
	bhi _081774F8
	adds r6, r0, 0
	movs r3, 0
	cmp r6, 0x46
	bhi _081774EE
	mov r4, r8
_081774C6:
	ldr r2, [r4]
	lsls r1, r6, 1
	adds r1, r2, r1
	lsls r0, r3, 1
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	adds r2, 0x94
	ldrh r2, [r2]
	cmp r3, r2
	bne _081774E4
	movs r3, 0
_081774E4:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x46
	bls _081774C6
_081774EE:
	mov r1, r8
	ldr r0, [r1]
	b _08177538
	.pool
_081774F8:
	movs r4, 0
	ldrh r0, [r2]
	cmp r0, r10
	beq _08177516
	adds r1, r2, 0
_08177502:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r0, r4, 1
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, r10
	beq _08177516
	cmp r4, 0x46
	bls _08177502
_08177516:
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x94
	ldrh r0, [r0]
	subs r0, 0x1
	cmp r4, r0
	bge _08177536
	lsls r0, r4, 1
	adds r0, r2, r0
	adds r2, 0x8C
	ldrh r1, [r2]
	strh r1, [r0]
	mov r1, r10
	strh r1, [r2]
	b _0817753E
_08177536:
	adds r0, r2, 0
_08177538:
	adds r0, 0x8C
	mov r2, r10
	strh r2, [r0]
_0817753E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x94
	movs r1, 0x47
	strh r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8177388

	.align 2, 0 @ Don't pad with nop.
