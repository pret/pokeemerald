	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

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
	ldr r2, =gSineTable
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
	bl SetOamMatrix
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
	bl CalcCenterToCornerVec
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
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x78
	bl Sin
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
	bl Sin
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x34]
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3C
	bl Cos
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
	bl CalcCenterToCornerVec
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
	ldr r1, =gSineTable
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
	bl SetOamMatrix
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8170040

	.align 2, 0 @ Don't pad with nop.
