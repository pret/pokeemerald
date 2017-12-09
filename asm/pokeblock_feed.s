	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	


	thumb_func_start sub_817A5CC
sub_817A5CC: @ 817A5CC
	push {r4-r7,lr}
	ldr r0, =sPokeblockFeed
	ldr r1, [r0]
	ldr r0, =0x00001056
	adds r3, r1, r0
	movs r0, 0x1
	strh r0, [r3]
	ldr r2, =gUnknown_085EFEBC
	ldr r7, =0x0000105a
	adds r1, r7
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r2
	ldrb r2, [r0]
	movs r4, 0
	ldr r5, =gUnknown_085EFF00
	adds r6, r5, 0
	subs r6, 0xA
_0817A5F0:
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r0, r1, r6
	ldrh r0, [r0]
	ldrh r7, [r3]
	adds r0, r7
	strh r0, [r3]
	adds r1, r5
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0x1
	beq _0817A61A
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0x7
	bls _0817A5F0
_0817A61A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A5CC

	thumb_func_start sub_817A634
sub_817A634: @ 817A634
	push {r4,lr}
	ldr r0, =sPokeblockFeed
	ldr r4, [r0]
	ldr r1, =0x00001050
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0x5A
	bls _0817A646
	b _0817A90E
_0817A646:
	lsls r0, 2
	ldr r1, =_0817A65C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0817A65C:
	.4byte _0817A7C8
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A818
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A858
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A8A2
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A8FC
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
	.4byte _0817A90E
_0817A7C8:
	ldr r1, =gUnknown_085EFEBC
	ldr r2, =0x0000105a
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrb r1, [r0]
	ldr r3, =0x00001051
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, =0x0000105b
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	adds r0, r4, 0
	stm r0!, {r1}
	movs r2, 0x44
	bl memcpy
	ldr r2, =0x00001050
	adds r1, r4, r2
	movs r0, 0xA
	strb r0, [r1]
	b _0817A90E
	.pool
_0817A818:
	bl sub_817A91C
	ldr r1, =gUnknown_085EFEBC
	ldr r3, =0x0000105a
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0817A850
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x3]
	ldr r0, [r4]
	ldr r1, =gUnknown_085F04FC
	str r1, [r0, 0x10]
	bl InitSpriteAffineAnim
_0817A850:
	ldr r0, =0x00001050
	adds r1, r4, r0
	movs r0, 0x32
	strb r0, [r1]
_0817A858:
	ldr r1, =gUnknown_085EFEBC
	ldr r2, =0x0000105a
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x1
	adds r2, r0, r1
	ldrb r1, [r2]
	cmp r1, 0
	beq _0817A8C8
	ldr r3, =0x00001053
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0817A898
	ldr r0, [r4]
	adds r1, 0xA
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAffineAnim
	b _0817A8C8
	.pool
_0817A898:
	ldr r0, [r4]
	ldrb r1, [r2]
	bl StartSpriteAffineAnim
	b _0817A8C8
_0817A8A2:
	bl sub_817A9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0817A90E
	ldr r1, =0x00001072
	adds r0, r4, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _0817A8E0
	ldr r3, =0x00001051
	adds r1, r4, r3
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	bl sub_817A91C
_0817A8C8:
	ldr r0, =0x00001050
	adds r1, r4, r0
	movs r0, 0x3C
	strb r0, [r1]
	b _0817A90E
	.pool
_0817A8E0:
	ldr r0, [r4]
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldr r2, =0x00001050
	adds r1, r4, r2
	movs r0, 0x46
	strb r0, [r1]
	b _0817A90E
	.pool
_0817A8FC:
	bl sub_817AA3C
	ldr r3, =0x00001051
	adds r0, r4, r3
	movs r1, 0
	strb r1, [r0]
	ldr r2, =0x00001050
	adds r0, r4, r2
	strb r1, [r0]
_0817A90E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817A634

	thumb_func_start sub_817A91C
sub_817A91C: @ 817A91C
	push {r4-r7,lr}
	ldr r0, =sPokeblockFeed
	ldr r5, [r0]
	movs r4, 0
	movs r0, 0x83
	lsls r0, 5
	adds r7, r5, r0
	ldr r1, =gUnknown_085EFEEE
	mov r12, r1
	ldr r2, =0x00001051
	adds r6, r5, r2
_0817A932:
	lsls r2, r4, 1
	adds r3, r7, r2
	ldrb r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	add r2, r12
	ldrh r0, [r2]
	strh r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _0817A932
	ldr r0, =0x00001068
	adds r6, r5, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0817A9DC
	movs r2, 0x83
	lsls r2, 5
	adds r4, r5, r2
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r2, 0x4
	adds r1, r5, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl Sin
	ldr r2, =0x00001074
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, 0
	ldrsh r0, [r4, r1]
	subs r2, 0xE
	adds r1, r5, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl Cos
	ldr r2, =0x00001076
	adds r1, r5, r2
	strh r0, [r1]
	ldrh r0, [r6]
	ldr r1, =0x00001078
	adds r4, r5, r1
	strh r0, [r4]
	ldr r0, [r5]
	ldrh r1, [r0, 0x24]
	adds r2, 0x4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, [r5]
	ldrh r1, [r0, 0x26]
	adds r2, 0x2
	adds r0, r5, r2
	strh r1, [r0]
	bl sub_817AB68
	ldrh r0, [r4]
	strh r0, [r6]
	bl sub_817AA54
	ldrh r0, [r4]
	strh r0, [r6]
	movs r0, 0
	b _0817A9DE
	.pool
_0817A9DC:
	movs r0, 0x1
_0817A9DE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_817A91C

	thumb_func_start sub_817A9E4
sub_817A9E4: @ 817A9E4
	push {r4,r5,lr}
	ldr r0, =sPokeblockFeed
	ldr r2, [r0]
	ldr r1, =0x00001078
	adds r0, r2, r1
	ldr r5, =0x00001068
	adds r4, r2, r5
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r0
	lsls r1, 16
	ldr r3, [r2]
	lsrs r1, 15
	movs r5, 0x85
	lsls r5, 4
	adds r0, r2, r5
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3, 0x24]
	ldr r3, [r2]
	movs r0, 0xC5
	lsls r0, 4
	adds r2, r0
	adds r2, r1
	ldrh r0, [r2]
	strh r0, [r3, 0x26]
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	beq _0817AA34
	movs r0, 0
	b _0817AA36
	.pool
_0817AA34:
	movs r0, 0x1
_0817AA36:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_817A9E4

	thumb_func_start sub_817AA3C
sub_817AA3C: @ 817AA3C
	push {lr}
	ldr r0, =sPokeblockFeed
	ldr r0, [r0]
	ldr r0, [r0]
	bl FreeSpriteOamMatrix
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817AA3C

	thumb_func_start sub_817AA54
sub_817AA54: @ 817AA54
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r0, =sPokeblockFeed
	ldr r7, [r0]
	ldr r1, =0x00001070
	adds r0, r7, r1
	ldrh r0, [r0]
	mov r9, r0
	ldr r2, =0x00001078
	adds r0, r7, r2
	ldrh r0, [r0]
	mov r3, r9
	subs r0, r3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r4, =0x0000107a
	adds r1, r7, r4
	subs r2, 0xC
	adds r0, r7, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	ldr r3, =0x0000107c
	adds r1, r7, r3
	subs r4, 0xC
	adds r0, r7, r4
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	movs r5, 0
	mov r0, r8
	subs r0, 0x1
	cmp r5, r0
	bge _0817AB20
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r0, 16
	str r0, [sp, 0x8]
	ldr r2, [sp, 0x4]
	lsls r0, r2, 16
	asrs r0, 16
	mov r10, r0
_0817AABE:
	mov r3, r9
	adds r0, r3, r5
	lsls r0, 1
	movs r4, 0x85
	lsls r4, 4
	adds r2, r7, r4
	adds r2, r0
	ldrh r6, [r2]
	ldr r3, [sp, 0x8]
	subs r1, r6, r3
	movs r4, 0xC5
	lsls r4, 4
	adds r3, r7, r4
	adds r3, r0
	ldrh r4, [r3]
	mov r0, r10
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r5, 0x1
	adds r0, r1, 0
	muls r0, r5
	mov r1, r8
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	bl __divsi3
	subs r6, r0
	ldr r2, [sp, 0xC]
	strh r6, [r2]
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	muls r0, r5
	mov r1, r8
	bl __divsi3
	ldr r3, [sp, 0x10]
	ldrh r1, [r3]
	subs r1, r0
	strh r1, [r3]
	lsls r5, 16
	lsrs r5, 16
	mov r0, r8
	subs r0, 0x1
	cmp r5, r0
	blt _0817AABE
_0817AB20:
	mov r0, r9
	add r0, r8
	subs r0, 0x1
	lsls r0, 1
	movs r2, 0x85
	lsls r2, 4
	adds r1, r7, r2
	adds r1, r0
	mov r3, sp
	ldrh r3, [r3]
	strh r3, [r1]
	movs r4, 0xC5
	lsls r4, 4
	adds r1, r7, r4
	adds r1, r0
	mov r0, sp
	ldrh r0, [r0, 0x4]
	strh r0, [r1]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817AA54

	thumb_func_start sub_817AB68
sub_817AB68: @ 817AB68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =sPokeblockFeed
	ldr r6, [r0]
	movs r0, 0
	str r0, [sp]
	ldr r1, =0x0000107a
	adds r0, r6, r1
	ldr r2, =0x00001074
	adds r1, r6, r2
	ldrh r2, [r0]
	ldrh r0, [r1]
	subs r2, r0
	ldr r3, =0x0000107c
	adds r0, r6, r3
	ldr r1, =0x00001076
	adds r3, r6, r1
	ldrh r1, [r0]
	ldrh r0, [r3]
	subs r1, r0
	ldr r3, =0x00001068
	adds r3, r6
	mov r9, r3
	movs r0, 0x83
	lsls r0, 5
	adds r0, r6
	mov r8, r0
	lsls r2, 16
	asrs r2, 16
	str r2, [sp, 0x4]
	lsls r1, 16
	asrs r1, 16
	mov r10, r1
_0817ABB2:
	ldr r1, =0x0000106a
	adds r0, r6, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _0817ABC0
	negs r0, r0
_0817ABC0:
	lsls r0, 16
	ldr r3, =0x00001066
	adds r7, r6, r3
	lsrs r0, 16
	ldrh r1, [r7]
	adds r0, r1
	lsls r4, r0, 16
	strh r0, [r7]
	ldr r2, =0x00001064
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bge _0817ABE2
	movs r0, 0x1
	str r0, [sp]
_0817ABE2:
	ldr r1, =0x00001078
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r3, r9
	ldrh r1, [r3]
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r1, 0
	beq _0817ACB8
	ldr r0, [sp]
	cmp r0, 0
	bne _0817AC54
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	lsrs r4, 24
	adds r1, r2, r4
	lsls r1, 16
	asrs r1, 16
	bl Sin
	lsls r5, 1
	movs r2, 0x85
	lsls r2, 4
	adds r1, r6, r2
	adds r1, r5
	ldr r3, [sp, 0x4]
	adds r0, r3, r0
	strh r0, [r1]
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldrh r1, [r7]
	adds r1, r4
	b _0817AC80
	.pool
_0817AC54:
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	lsrs r4, 24
	subs r1, r2, r4
	lsls r1, 16
	asrs r1, 16
	bl Sin
	lsls r5, 1
	movs r2, 0x85
	lsls r2, 4
	adds r1, r6, r2
	adds r1, r5
	ldr r3, [sp, 0x4]
	adds r0, r3, r0
	strh r0, [r1]
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldrh r1, [r7]
	subs r1, r4
_0817AC80:
	lsls r1, 16
	asrs r1, 16
	bl Cos
	movs r3, 0xC5
	lsls r3, 4
	adds r1, r6, r3
	adds r1, r5
	add r0, r10
	strh r0, [r1]
	ldr r1, =0x00001062
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r2, r8
	ldrh r2, [r2]
	adds r0, r2
	movs r1, 0xFF
	ands r0, r1
	mov r3, r8
	strh r0, [r3]
	mov r1, r9
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	b _0817ABB2
	.pool
_0817ACB8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_817AB68

	.align 2, 0 @ Don't pad with nop.
