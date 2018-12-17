	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text



	thumb_func_start sub_801DB68
sub_801DB68: @ 801DB68
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_801B044
	adds r5, r0, 0
	movs r0, 0x3
	adds r1, r4, 0
	ands r1, r0
	ldrb r2, [r5]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	cmp r4, 0x2
	bhi _0801DB8E
	cmp r4, 0x1
	bcs _0801DB94
	b _0801DBB8
_0801DB8E:
	cmp r4, 0x3
	beq _0801DBA6
	b _0801DBB8
_0801DB94:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	bl __umodsi3
	adds r0, 0x10
	b _0801DBB6
_0801DBA6:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	bl __umodsi3
	adds r0, 0x1
_0801DBB6:
	strb r0, [r5, 0x1]
_0801DBB8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801DB68

	thumb_func_start sub_801DBC0
sub_801DBC0: @ 801DBC0
	push {lr}
	bl sub_801B044
	movs r1, 0
	strb r1, [r0]
	strb r1, [r0, 0x1]
	ldr r0, =0x0000402e
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DBC0

	thumb_func_start sub_801DBDC
sub_801DBDC: @ 801DBDC
	push {r4,lr}
	ldr r0, =0x0000402e
	bl GetVarPointer
	adds r4, r0, 0
	bl sub_801B044
	adds r2, r0, 0
	ldr r0, [r2]
	lsls r0, 24
	lsrs r0, 29
	cmp r0, 0x4
	bls _0801DC10
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	ldr r1, =0x01f30000
	cmp r0, r1
	bls _0801DC10
	ldrb r0, [r2]
	movs r1, 0x1F
	ands r1, r0
	strb r1, [r2]
	movs r0, 0
	strh r0, [r4]
_0801DC10:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801DBDC

	thumb_func_start sub_801DC20
sub_801DC20: @ 801DC20
	push {r4-r6,lr}
	ldr r6, =gSpecialVar_Result
	bl sub_801B044
	adds r4, r0, 0
	bl IsMysteryEventEnabled
	cmp r0, 0
	beq _0801DC3A
	bl sub_801B0CC
	cmp r0, 0
	bne _0801DC44
_0801DC3A:
	movs r0, 0
	b _0801DCA6
	.pool
_0801DC44:
	adds r0, r4, 0
	bl sub_801DD44
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x6
	bhi _0801DCA4
	lsls r0, r5, 2
	ldr r1, =_0801DC60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801DC60:
	.4byte _0801DCA4
	.4byte _0801DC7C
	.4byte _0801DC7C
	.4byte _0801DCA4
	.4byte _0801DC86
	.4byte _0801DC96
	.4byte _0801DCA4
_0801DC7C:
	adds r0, r4, 0
	bl sub_801DCAC
	strh r0, [r6]
	b _0801DCA4
_0801DC86:
	adds r0, r4, 0
	bl sub_801DCAC
	strh r0, [r6]
	adds r0, r4, 0
	bl sub_801DCD8
	b _0801DCA4
_0801DC96:
	adds r0, r4, 0
	bl sub_801DCAC
	strh r0, [r6]
	adds r0, r4, 0
	bl sub_801DCCC
_0801DCA4:
	adds r0, r5, 0
_0801DCA6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801DC20

	thumb_func_start sub_801DCAC
sub_801DCAC: @ 801DCAC
	push {r4,lr}
	ldrb r2, [r0]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r4, [r0, 0x1]
	adds r4, 0x84
	movs r1, 0
	strb r1, [r0, 0x1]
	bl sub_801DD10
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801DCAC

	thumb_func_start sub_801DCCC
sub_801DCCC: @ 801DCCC
	ldrb r2, [r0]
	movs r1, 0x1D
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_801DCCC

	thumb_func_start sub_801DCD8
sub_801DCD8: @ 801DCD8
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, [r3]
	lsls r0, 27
	lsrs r0, 29
	adds r0, 0x1
	movs r1, 0x7
	ands r0, r1
	lsls r0, 2
	ldrb r1, [r3]
	movs r4, 0x1D
	negs r4, r4
	adds r2, r4, 0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3]
	ldr r0, [r3]
	lsls r0, 27
	lsrs r0, 29
	cmp r0, 0x4
	bls _0801DD0A
	ands r2, r4
	movs r0, 0x10
	orrs r2, r0
	strb r2, [r3]
_0801DD0A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801DCD8

	thumb_func_start sub_801DD10
sub_801DD10: @ 801DD10
	push {r4,lr}
	adds r3, r0, 0
	ldr r0, [r3]
	lsls r0, 24
	lsrs r0, 29
	adds r0, 0x1
	lsls r0, 5
	ldrb r1, [r3]
	movs r4, 0x1F
	adds r2, r4, 0
	ands r2, r1
	orrs r2, r0
	strb r2, [r3]
	ldr r0, [r3]
	lsls r0, 24
	lsrs r0, 29
	cmp r0, 0x5
	bls _0801DD3C
	ands r2, r4
	movs r0, 0xA0
	orrs r2, r0
	strb r2, [r3]
_0801DD3C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801DD10

	thumb_func_start sub_801DD44
sub_801DD44: @ 801DD44
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2]
	movs r0, 0xE0
	ands r0, r1
	cmp r0, 0xA0
	bne _0801DD56
	movs r0, 0x6
	b _0801DD92
_0801DD56:
	ldr r1, [r2]
	lsls r0, r1, 30
	lsrs r0, 30
	cmp r0, 0x1
	beq _0801DD78
	cmp r0, 0x1
	bgt _0801DD6A
	cmp r0, 0
	beq _0801DD74
	b _0801DD90
_0801DD6A:
	cmp r0, 0x2
	beq _0801DD7C
	cmp r0, 0x3
	beq _0801DD80
	b _0801DD90
_0801DD74:
	movs r0, 0x3
	b _0801DD92
_0801DD78:
	movs r0, 0x1
	b _0801DD92
_0801DD7C:
	movs r0, 0x2
	b _0801DD92
_0801DD80:
	lsls r0, r1, 27
	lsrs r0, 29
	cmp r0, 0x2
	bhi _0801DD8C
	movs r0, 0x4
	b _0801DD92
_0801DD8C:
	movs r0, 0x5
	b _0801DD92
_0801DD90:
	movs r0, 0
_0801DD92:
	pop {r1}
	bx r1
	thumb_func_end sub_801DD44

	.align 2, 0 @ don't pad with nop
