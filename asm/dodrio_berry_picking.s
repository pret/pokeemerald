	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8026988
sub_8026988: @ 8026988
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x44
	adds r0, 0x48
	ldrb r0, [r0]
	mov r8, r0
	ldrb r6, [r1]
	cmp r6, r8
	bcs _08026A7A
	ldr r0, =gUnknown_082F449C
	mov r9, r0
_080269A8:
	ldr r0, =gUnknown_02022C98
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0x28
	ldrb r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	ldr r2, =0x000031a0
	adds r0, r2
	adds r7, r3, r0
	movs r0, 0xB
	adds r2, r1, 0
	muls r2, r0
	adds r2, r6, r2
	adds r3, 0x24
	ldrb r1, [r3]
	subs r1, 0x1
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 3
	subs r0, r1
	adds r2, r0
	add r2, r9
	ldrb r4, [r2]
	adds r0, r7, 0
	adds r0, 0x1F
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080269FC
	adds r0, r6, 0
	movs r1, 0
	bl sub_8028BF8
	b _08026A04
	.pool
_080269FC:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8028BF8
_08026A04:
	adds r0, r7, 0
	adds r0, 0x1F
	adds r5, r0, r4
	ldrb r0, [r5]
	cmp r0, 0x9
	bls _08026A30
	adds r0, r7, 0
	adds r0, 0x14
	adds r0, r4
	ldrb r1, [r0]
	adds r1, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8028CA4
	ldrb r1, [r5]
	lsls r1, 25
	movs r0, 0xFF
	lsls r0, 24
	adds r1, r0
	b _08026A52
_08026A30:
	adds r0, r7, 0
	adds r0, 0x14
	adds r3, r0, r4
	ldrb r0, [r3]
	cmp r0, 0x3
	bne _08026A5C
	movs r0, 0x7
	strb r0, [r5]
	adds r0, r6, 0
	movs r1, 0x6
	bl sub_8028CA4
	ldrb r1, [r5]
	lsls r1, 25
	movs r2, 0xFF
	lsls r2, 24
	adds r1, r2
_08026A52:
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8028C7C
	b _08026A70
_08026A5C:
	ldrb r1, [r3]
	adds r0, r6, 0
	bl sub_8028CA4
	ldrb r1, [r5]
	lsls r1, 25
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8028C7C
_08026A70:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r8
	bcc _080269A8
_08026A7A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8026988

	thumb_func_start sub_8026A88
sub_8026A88: @ 8026A88
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0
	cmp r4, r5
	bcs _08026ABA
	adds r6, r1, 0
_08026A9A:
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 2
	ldr r1, [r6]
	adds r0, r1
	ldr r1, =0x000031cc
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_80286B4
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026A9A
_08026ABA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026A88

	thumb_func_start sub_8026AC8
sub_8026AC8: @ 8026AC8
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0
	cmp r4, r5
	bcs _08026AEA
_08026AD8:
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_80286B4
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026AD8
_08026AEA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026AC8

	thumb_func_start sub_8026AF4
sub_8026AF4: @ 8026AF4
	push {lr}
	bl sub_8026988
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _08026B10
	bl sub_8026AC8
	b _08026B14
	.pool
_08026B10:
	bl sub_8026A88
_08026B14:
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	bl sub_80288D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026AF4

	thumb_func_start sub_8026B28
sub_8026B28: @ 8026B28
	push {lr}
	bl sub_8026988
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _08026B44
	bl sub_8026AC8
	b _08026B48
	.pool
_08026B44:
	bl sub_8026A88
_08026B48:
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x40
	ldrb r0, [r0]
	bl sub_80288D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026B28

	thumb_func_start sub_8026B5C
sub_8026B5C: @ 8026B5C
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	cmp r0, 0x4
	bhi _08026BB4
	lsls r0, 2
	ldr r1, =_08026B78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08026B78:
	.4byte _08026B8C
	.4byte _08026B94
	.4byte _08026B9C
	.4byte _08026BA4
	.4byte _08026BAC
_08026B8C:
	movs r0, 0x4
	strb r0, [r3]
	movs r0, 0x7
	b _08026BB2
_08026B94:
	movs r0, 0x3
	strb r0, [r3]
	movs r0, 0x8
	b _08026BB2
_08026B9C:
	movs r0, 0x2
	strb r0, [r3]
	movs r0, 0x9
	b _08026BB2
_08026BA4:
	movs r0, 0x1
	strb r0, [r3]
	movs r0, 0xA
	b _08026BB2
_08026BAC:
	movs r0, 0
	strb r0, [r3]
	movs r0, 0xB
_08026BB2:
	strb r0, [r2]
_08026BB4:
	pop {r0}
	bx r0
	thumb_func_end sub_8026B5C

	thumb_func_start sub_8026BB8
sub_8026BB8: @ 8026BB8
	push {r4-r6,lr}
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0x1
	cmp r4, r5
	bcs _08026C1E
	adds r6, r1, 0
_08026BCA:
	ldr r0, [r6]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026BEC
	adds r0, r4, 0
	bl sub_8027DFC
	ldr r1, [r6]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
_08026BEC:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026BCA
	cmp r4, r5
	bcs _08026C1E
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r0, r2
_08026C04:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026C14
	movs r0, 0
	b _08026C20
	.pool
_08026C14:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026C04
_08026C1E:
	movs r0, 0x1
_08026C20:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8026BB8

	thumb_func_start sub_8026C28
sub_8026C28: @ 8026C28
	push {r4,lr}
	movs r1, 0
	ldr r4, =gUnknown_02022C98
	movs r3, 0xAC
	lsls r3, 1
	movs r2, 0
_08026C34:
	ldr r0, [r4]
	adds r0, r3
	adds r0, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bls _08026C34
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026C28

	thumb_func_start sub_8026C50
sub_8026C50: @ 8026C50
	push {r4,lr}
	ldr r3, =gUnknown_02022C98
	ldr r1, [r3]
	adds r2, r1, 0
	adds r2, 0x40
	ldrb r0, [r2]
	cmp r0, 0x9
	bls _08026C88
	movs r4, 0x90
	lsls r4, 1
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, 0
	bne _08026C88
	movs r0, 0xA
	strb r0, [r2]
	ldr r0, [r3]
	movs r1, 0x96
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _08026C88
	movs r0, 0x1
	b _08026C8A
	.pool
_08026C88:
	movs r0, 0
_08026C8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026C50

	thumb_func_start sub_8026C90
sub_8026C90: @ 8026C90
	push {r4-r6,lr}
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0x40
	ldrb r0, [r2]
	cmp r0, 0x9
	bls _08026D14
	adds r0, r1, 0
	adds r0, 0x44
	ldrb r3, [r0]
	adds r0, 0x4
	ldrb r5, [r0]
	movs r0, 0xA
	strb r0, [r2]
	ldr r4, [r4]
	mov r12, r4
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	beq _08026D14
	adds r4, r3, 0
	cmp r4, r5
	bcs _08026D04
	mov r0, r12
	adds r0, 0x28
	ldrb r3, [r0]
	lsls r1, r3, 4
	subs r1, r3
	lsls r1, 2
	ldr r6, =gUnknown_082F449C
	subs r0, 0x4
	ldrb r2, [r0]
	subs r2, 0x1
	add r1, r12
	movs r0, 0xB
	muls r3, r0
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 3
	subs r2, r0, r2
	ldr r0, =0x000031bf
	adds r1, r0
_08026CEA:
	adds r0, r4, r3
	adds r0, r2
	adds r0, r6
	ldrb r0, [r0]
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _08026D14
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08026CEA
_08026D04:
	movs r0, 0x1
	b _08026D16
	.pool
_08026D14:
	movs r0, 0
_08026D16:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8026C90

	thumb_func_start sub_8026D1C
sub_8026D1C: @ 8026D1C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_082F7A9C
	mov r8, r0
	ldr r0, =gUnknown_02022C98
	ldr r6, [r0]
	adds r0, r6, 0
	adds r0, 0x90
	adds r0, r5
	mov r9, r0
	ldrb r7, [r0]
	adds r0, r7, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	add r4, r8
	adds r0, r7, 0
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	muls r0, r1
	ldrb r4, [r4]
	adds r0, r4
	lsls r0, 24
	lsls r5, 1
	adds r6, 0x86
	adds r6, r5
	ldrh r1, [r6]
	lsrs r0, 24
	cmp r1, r0
	bcc _08026D76
	adds r0, r7, 0x1
	mov r1, r9
	strb r0, [r1]
_08026D76:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8026D1C

	thumb_func_start sub_8026D8C
sub_8026D8C: @ 8026D8C
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gUnknown_082F449C+0x1AC
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	adds r1, 0x24
	ldrb r1, [r1]
	subs r1, 0x1
	movs r2, 0xB
	muls r1, r2
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8026D8C

	thumb_func_start sub_8026DB0
sub_8026DB0: @ 8026DB0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, =gUnknown_02022C98
	ldr r1, [r4]
	adds r1, 0x24
	ldrb r2, [r1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =gUnknown_082F449C+0x15E
	lsls r1, r0, 1
	adds r1, r0
	lsls r0, r2, 4
	subs r0, r2
	adds r1, r0
	adds r0, r1, r3
	ldrb r0, [r0]
	mov r12, r0
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r7, [r0]
	adds r3, 0x2
	adds r1, r3
	ldrb r1, [r1]
	mov r8, r1
	movs r3, 0
	ldr r1, =gUnknown_082F449C+0x1E3
	lsls r0, r2, 2
	adds r2, r0, r2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08026E18
	adds r6, r1, 0
_08026DFE:
	adds r0, r3, r2
	adds r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	beq _08026E3C
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r0, r3, r2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026DFE
_08026E18:
	ldr r0, [r4]
	adds r0, 0x90
	mov r1, r12
	adds r2, r0, r1
	adds r1, r0, r7
	ldrb r0, [r2]
	ldrb r3, [r1]
	cmp r0, r3
	bls _08026E46
	adds r1, r0, 0
	b _08026E48
	.pool
_08026E3C:
	ldr r0, [r4]
	adds r0, 0x90
	adds r0, r7
	ldrb r0, [r0]
	b _08026E5A
_08026E46:
	ldrb r1, [r1]
_08026E48:
	ldr r0, [r4]
	adds r0, 0x90
	mov r2, r8
	adds r4, r0, r2
	ldrb r0, [r4]
	cmp r0, r1
	bls _08026E58
	adds r1, r0, 0
_08026E58:
	adds r0, r1, 0
_08026E5A:
	adds r1, r5, 0
	bl sub_8026E70
	lsls r0, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8026DB0

	thumb_func_start sub_8026E70
sub_8026E70: @ 8026E70
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022C98
	ldr r2, [r2]
	adds r2, 0xE8
	adds r2, r1
	ldrb r4, [r2]
	movs r1, 0x7
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bhi _08026EDE
	lsls r0, 2
	ldr r1, =_08026EA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08026EA4:
	.4byte _08026EDE
	.4byte _08026ED6
	.4byte _08026EE2
	.4byte _08026EC0
	.4byte _08026EC6
	.4byte _08026ECC
	.4byte _08026ED2
_08026EC0:
	cmp r4, 0
	beq _08026ED6
	b _08026EDE
_08026EC6:
	cmp r4, 0
	beq _08026EE2
	b _08026EDE
_08026ECC:
	cmp r4, 0x2
	beq _08026ED6
	b _08026EE2
_08026ED2:
	cmp r4, 0
	bne _08026EDA
_08026ED6:
	movs r0, 0x1
	b _08026EE4
_08026EDA:
	cmp r4, 0x1
	beq _08026EE2
_08026EDE:
	movs r0, 0
	b _08026EE4
_08026EE2:
	movs r0, 0x2
_08026EE4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026E70

	thumb_func_start sub_8026EEC
sub_8026EEC: @ 8026EEC
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	adds r4, r0, 0
	b _08026EFE
_08026EF6:
	ldrh r0, [r4, 0x6]
	adds r6, r0
	adds r4, 0xC
	adds r5, 0x1
_08026EFE:
	bl GetLinkPlayerCount
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	blt _08026EF6
	cmp r6, 0xA
	bgt _08026F12
	movs r0, 0
	b _08026F14
_08026F12:
	movs r0, 0x1
_08026F14:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8026EEC

	thumb_func_start sub_8026F1C
sub_8026F1C: @ 8026F1C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r6, =gUnknown_02022C98
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x24
	ldrb r5, [r0]
	cmp r3, 0
	bge _08026F3A
	b _0802722C
_08026F3A:
	cmp r3, 0x2
	ble _08026F48
	cmp r3, 0x3
	beq _08026F78
	b _0802722C
	.pool
_08026F48:
	ldr r3, =0x000031b4
	adds r0, r1, r3
	adds r0, r4
	ldrb r4, [r0]
	lsls r4, 1
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0
	adds r0, r1, 0
	adds r0, 0x4A
	adds r0, r4
	ldrh r0, [r0]
	ldr r1, =0x00004e20
	bl sub_8027A28
	ldr r1, [r6]
	adds r1, 0x4A
	adds r1, r4
	b _0802722A
	.pool
_08026F78:
	adds r0, r1, 0
	adds r0, 0x4A
	bl sub_8026EEC
	cmp r0, 0
	beq _08026F86
	b _0802722C
_08026F86:
	cmp r5, 0x3
	bne _08026F8C
	b _08027154
_08026F8C:
	cmp r5, 0x3
	bgt _08026F98
	cmp r5, 0x2
	bne _08026F96
	b _080271E8
_08026F96:
	b _0802722C
_08026F98:
	cmp r5, 0x4
	bne _08026F9E
	b _08027090
_08026F9E:
	cmp r5, 0x5
	beq _08026FA4
	b _0802722C
_08026FA4:
	cmp r4, 0x9
	bls _08026FAA
	b _0802722C
_08026FAA:
	lsls r0, r4, 2
	ldr r1, =_08026FB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08026FB8:
	.4byte _08026FE0
	.4byte _08026FF8
	.4byte _08027004
	.4byte _0802701C
	.4byte _08027028
	.4byte _08027040
	.4byte _0802704C
	.4byte _08027060
	.4byte _0802706C
	.4byte _08027084
_08026FE0:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x68
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x74
	b _08027226
	.pool
_08026FF8:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x74
	b _08027226
	.pool
_08027004:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x74
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x80
	b _08027226
	.pool
_0802701C:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x80
	b _08027226
	.pool
_08027028:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x80
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x50
	b _08027226
	.pool
_08027040:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x50
	b _08027226
	.pool
_0802704C:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
	.pool
_08027060:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08027224
	.pool
_0802706C:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x5C
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x68
	b _08027226
	.pool
_08027084:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x68
	b _08027226
	.pool
_08027090:
	subs r0, r4, 0x1
	cmp r0, 0x7
	bls _08027098
	b _0802722C
_08027098:
	lsls r0, 2
	ldr r1, =_080270A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080270A8:
	.4byte _080270C8
	.4byte _080270E0
	.4byte _080270EC
	.4byte _08027104
	.4byte _08027110
	.4byte _08027124
	.4byte _08027130
	.4byte _08027148
_080270C8:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x68
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x74
	b _08027226
	.pool
_080270E0:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x74
	b _08027226
	.pool
_080270EC:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x74
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x50
	b _08027226
	.pool
_08027104:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x50
	b _08027226
	.pool
_08027110:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
	.pool
_08027124:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08027224
	.pool
_08027130:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x5C
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x68
	b _08027226
	.pool
_08027148:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x68
	b _08027226
	.pool
_08027154:
	subs r0, r4, 0x2
	cmp r0, 0x5
	bhi _0802722C
	lsls r0, 2
	ldr r1, =_08027168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08027168:
	.4byte _08027180
	.4byte _08027198
	.4byte _080271A4
	.4byte _080271BC
	.4byte _080271C8
	.4byte _080271DC
_08027180:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x5C
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x68
	b _08027226
	.pool
_08027198:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x68
	b _08027226
	.pool
_080271A4:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x68
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	adds r1, 0x50
	b _08027226
	.pool
_080271BC:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x50
	b _08027226
	.pool
_080271C8:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
	.pool
_080271DC:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	b _08027224
	.pool
_080271E8:
	cmp r4, 0x4
	beq _0802720E
	cmp r4, 0x4
	bgt _080271F6
	cmp r4, 0x3
	beq _08027200
	b _0802722C
_080271F6:
	cmp r4, 0x5
	beq _08027214
	cmp r4, 0x6
	beq _08027222
	b _0802722C
_08027200:
	ldr r1, [r6]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
_0802720E:
	ldr r1, [r6]
	adds r1, 0x50
	b _08027226
_08027214:
	ldr r1, [r6]
	adds r2, r1, 0
	adds r2, 0x50
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _08027224
_08027222:
	ldr r1, [r6]
_08027224:
	adds r1, 0x5C
_08027226:
	ldrh r0, [r1]
	adds r0, 0x1
_0802722A:
	strh r0, [r1]
_0802722C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8026F1C

	thumb_func_start sub_8027234
sub_8027234: @ 8027234
	push {r4,r5,lr}
	adds r1, r0, 0
	ldr r4, =gUnknown_02022C98
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0802729E
	cmp r1, 0x1
	bne _08027280
	movs r5, 0x89
	lsls r5, 1
	adds r1, r3, r5
	ldrh r0, [r1]
	adds r2, r0, 0x1
	strh r2, [r1]
	movs r0, 0x8A
	lsls r0, 1
	adds r1, r3, r0
	lsls r0, r2, 16
	lsrs r0, 16
	ldrh r3, [r1]
	cmp r0, r3
	bls _08027268
	strh r2, [r1]
_08027268:
	ldr r0, [r4]
	adds r2, r0, r5
	ldrh r0, [r2]
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0802729E
	strh r1, [r2]
	b _0802729E
	.pool
_08027280:
	movs r2, 0x89
	lsls r2, 1
	adds r0, r3, r2
	movs r5, 0x8A
	lsls r5, 1
	adds r1, r3, r5
	ldrh r0, [r0]
	ldrh r3, [r1]
	cmp r0, r3
	bls _08027296
	strh r0, [r1]
_08027296:
	ldr r0, [r4]
	adds r0, r2
	movs r1, 0
	strh r1, [r0]
_0802729E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8027234

	thumb_func_start sub_80272A4
sub_80272A4: @ 80272A4
	push {r4,r5,lr}
	movs r3, 0
	ldr r2, =gUnknown_02022C98
	ldr r0, [r2]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r3, r0
	bcs _080272DC
	adds r5, r2, 0
	movs r4, 0x8A
	lsls r4, 1
_080272BA:
	ldr r2, [r5]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r1, r2, 0
	adds r1, 0x54
	adds r1, r0
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	adds r2, 0x24
	ldrb r2, [r2]
	cmp r3, r2
	bcc _080272BA
_080272DC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80272A4

	thumb_func_start sub_80272E8
sub_80272E8: @ 80272E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	ldr r7, =gUnknown_02022C98
	movs r4, 0
	ldr r0, =0x000031bf
	mov r10, r0
_080272FC:
	movs r2, 0
	lsls r6, r5, 4
	lsls r1, r5, 1
	mov r8, r1
	lsls r0, r5, 3
	mov r12, r0
	adds r1, r5, 0x1
	mov r9, r1
	subs r0, r6, r5
	lsls r3, r0, 2
_08027310:
	ldr r0, [r7]
	adds r1, r2, r3
	add r0, r10
	adds r0, r1
	strb r4, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xA
	bls _08027310
	ldr r0, [r7]
	subs r1, r6, r5
	lsls r1, 2
	adds r0, r1
	ldr r2, =0x000031cc
	adds r0, r2
	strb r4, [r0]
	ldr r0, [r7]
	adds r0, r1
	ldr r1, =0x000031d0
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r7]
	adds r0, 0x90
	adds r0, r5
	strb r4, [r0]
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x86
	add r0, r8
	strh r4, [r0]
	add r1, r12
	ldr r2, =0x00003308
	adds r1, r2
	strb r4, [r1]
	ldr r2, [r7]
	ldr r1, =0x0000330c
	adds r0, r2, r1
	add r0, r12
	str r4, [r0]
	mov r0, r8
	adds r1, r0, r5
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x4A
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x4E
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x50
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x52
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	adds r0, 0x54
	adds r0, r1
	strh r4, [r0]
	mov r1, r9
	lsls r0, r1, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bls _080272FC
	ldr r2, =gUnknown_02022C98
	ldr r0, [r2]
	movs r1, 0xAA
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	strb r2, [r0]
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	movs r1, 0x89
	lsls r1, 1
	adds r3, r0, r1
	movs r1, 0
	strh r2, [r3]
	adds r0, 0x40
	strb r1, [r0]
	bl sub_8026A88
	bl sub_8026988
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80272E8

	thumb_func_start sub_80273F0
sub_80273F0: @ 80273F0
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0802740C
	cmp r0, 0x5
	beq _08027410
	b _08027412
	.pool
_0802740C:
	movs r4, 0x1
	b _08027412
_08027410:
	movs r4, 0x2
_08027412:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	lsls r1, r4, 2
	ldr r5, =gUnknown_02022C98
	ldr r2, =gUnknown_082F7AA4
	adds r1, r4
	lsls r1, 1
	adds r0, r1
	adds r0, r2
	ldrb r2, [r0]
_08027436:
	ldr r1, [r5]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r1, 0x52
	adds r1, r0
	strh r2, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x4
	bls _08027436
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80273F0

	thumb_func_start sub_802745C
sub_802745C: @ 802745C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r2, [r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x4A
	adds r0, r1
	ldrh r3, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1
	ldrh r0, [r0]
	adds r2, 0x4E
	adds r2, r1
	adds r3, r0
	ldrh r2, [r2]
	adds r0, r3, r2
	ldr r1, =0x0000270f
	cmp r0, r1
	bls _0802748E
	adds r0, r1, 0
_0802748E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802745C

	thumb_func_start sub_802749C
sub_802749C: @ 802749C
	push {r4-r6,lr}
	ldr r5, =gUnknown_02022C98
	ldr r0, [r5]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_802745C
	ldr r1, =0x0000270f
	bl sub_8027A38
	adds r4, r0, 0
	ldr r0, [r5]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_80276C0
	ldr r1, =0x000f4236
	bl sub_8027A38
	adds r2, r0, 0
	ldr r3, =gSaveBlock2Ptr
	ldr r0, [r3]
	movs r6, 0x83
	lsls r6, 2
	adds r1, r0, r6
	ldr r0, [r1]
	cmp r0, r2
	bcs _080274D6
	str r2, [r1]
_080274D6:
	ldr r0, [r3]
	movs r2, 0x84
	lsls r2, 2
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, r4
	bcs _080274E6
	strh r4, [r1]
_080274E6:
	ldr r0, [r3]
	ldr r6, =0x00000212
	adds r2, r0, r6
	ldr r0, [r5]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	ldrh r1, [r0]
	ldrh r0, [r2]
	cmp r0, r1
	bcs _080274FE
	strh r1, [r2]
_080274FE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802749C

	thumb_func_start sub_8027518
sub_8027518: @ 8027518
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r0, [r1]
	adds r0, 0x9B
	ldrb r6, [r0]
	movs r3, 0x3
	adds r5, r1, 0
	adds r4, r5, 0
_0802752C:
	ldr r0, [r4]
	adds r0, 0x98
	adds r2, r0, r3
	subs r1, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, 24
	lsrs r3, r1, 24
	cmp r3, 0
	bne _0802752C
	ldr r0, [r5]
	adds r0, 0x98
	strb r7, [r0]
	adds r0, r6, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8027518

	thumb_func_start sub_8027554
sub_8027554: @ 8027554
	push {r4,lr}
	ldr r4, =gUnknown_02022C98
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0x28
	ldrb r1, [r0]
	adds r0, 0x88
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, 0
	bne _080275FC
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08027594
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	movs r1, 0x2
	b _080275CA
	.pool
_08027594:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _080275B0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	movs r1, 0x3
	b _080275CA
	.pool
_080275B0:
	movs r0, 0x10
	ands r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _080275E8
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	movs r1, 0x1
_080275CA:
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x28
	adds r0, 0xB0
	ldrb r1, [r1]
	adds r0, r1
	movs r1, 0x6
	strb r1, [r0]
	movs r0, 0xD4
	bl PlaySE
	b _08027600
	.pool
_080275E8:
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3, r0
	ldr r1, =0x000031cc
	adds r0, r1
	strb r2, [r0]
	b _08027600
	.pool
_080275FC:
	subs r0, 0x1
	strb r0, [r2]
_08027600:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027554

	thumb_func_start sub_8027608
sub_8027608: @ 8027608
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldrb r2, [r0]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 2
	adds r1, r0
	ldr r0, =0x000031cc
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8027608

	thumb_func_start sub_802762C
sub_802762C: @ 802762C
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldrb r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, 0x52
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x85
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_802762C

	thumb_func_start sub_8027650
sub_8027650: @ 8027650
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_8027650

	thumb_func_start sub_8027660
sub_8027660: @ 8027660
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802768C
	ldr r0, =gUnknown_02022C98
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 2
	ldr r2, =0x000031a0
	adds r1, r2
	ldr r0, [r0]
	b _08027694
	.pool
_0802768C:
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	ldr r1, =gLinkPlayers + 8
_08027694:
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8027660

	thumb_func_start sub_80276A0
sub_80276A0: @ 80276A0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r2, =gUnknown_02022C98
	ldr r3, [r2]
	lsrs r1, 23
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r3, 0x4A
	adds r3, r1
	ldrh r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_80276A0

	thumb_func_start sub_80276C0
sub_80276C0: @ 80276C0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	movs r3, 0
	ldr r0, =gUnknown_02022C98
	mov r9, r0
	ldr r2, =gUnknown_082F7B24
	mov r10, r2
	ldr r2, [r0]
	lsls r1, r4, 1
	adds r0, r1, r4
	lsls r0, 2
	str r0, [sp]
	adds r6, r2, 0
	adds r6, 0x4A
	mov r12, r1
	mov r8, r10
_080276EE:
	lsls r1, r3, 1
	ldr r7, [sp]
	adds r0, r1, r7
	adds r0, r6, r0
	ldrh r2, [r0]
	add r1, r8
	movs r7, 0
	ldrsh r0, [r1, r7]
	muls r0, r2
	adds r5, r0
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _080276EE
	mov r0, r9
	ldr r1, [r0]
	mov r2, r12
	adds r0, r2, r4
	lsls r0, 2
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	mov r3, r10
	movs r7, 0x6
	ldrsh r0, [r3, r7]
	muls r0, r1
	cmp r5, r0
	bls _08027734
	subs r0, r5, r0
	b _08027736
	.pool
_08027734:
	movs r0, 0
_08027736:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80276C0

	thumb_func_start sub_8027748
sub_8027748: @ 8027748
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r6, [r0]
	movs r0, 0
	bl sub_80276C0
	adds r5, r0, 0
	movs r4, 0x1
	cmp r4, r6
	bcs _08027776
_08027760:
	adds r0, r4, 0
	bl sub_80276C0
	cmp r0, r5
	bls _0802776C
	adds r5, r0, 0
_0802776C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _08027760
_08027776:
	ldr r1, =0x000f4236
	adds r0, r5, 0
	bl sub_8027A38
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8027748

	thumb_func_start sub_802778C
sub_802778C: @ 802778C
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r2, [r1]
	adds r1, r2, 0
	adds r1, 0x24
	ldrb r5, [r1]
	lsrs r4, r0, 23
	adds r2, 0x4A
	adds r0, r2, r4
	ldrh r3, [r0]
	movs r1, 0
	cmp r1, r5
	bcs _080277C4
_080277A8:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, r3
	bls _080277BA
	adds r3, r0, 0
_080277BA:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r5
	bcc _080277A8
_080277C4:
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802778C

	thumb_func_start sub_80277D0
sub_80277D0: @ 80277D0
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0x1
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	movs r4, 0
	cmp r4, r5
	bcs _080277FE
_080277E8:
	adds r0, r4, 0
	bl sub_80276C0
	lsls r1, r4, 2
	add r1, sp
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _080277E8
_080277FE:
	lsls r7, 2
	mov r12, r7
	cmp r6, 0
	beq _08027838
	subs r7, r5, 0x1
_08027808:
	movs r6, 0
	movs r4, 0
	cmp r6, r7
	bge _08027834
	adds r5, r7, 0
_08027812:
	lsls r0, r4, 2
	mov r2, sp
	adds r1, r2, r0
	adds r4, 0x1
	lsls r0, r4, 2
	adds r3, r2, r0
	ldr r0, [r1]
	ldr r2, [r3]
	cmp r0, r2
	bcs _0802782C
	str r2, [r1]
	str r0, [r3]
	movs r6, 0x1
_0802782C:
	lsls r0, r4, 24
	lsrs r4, r0, 24
	cmp r4, r5
	blt _08027812
_08027834:
	cmp r6, 0
	bne _08027808
_08027838:
	mov r0, sp
	add r0, r12
	ldr r0, [r0]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80277D0

	thumb_func_start sub_802784C
sub_802784C: @ 802784C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	mov r8, r0
	mov r9, r0
	ldr r6, =gUnknown_02022C98
	ldr r0, [r6]
	adds r0, 0x24
	ldrb r5, [r0]
	bl sub_8027748
	bl sub_8027748
	cmp r0, 0
	bne _080278A0
	movs r4, 0
	cmp r9, r5
	bcs _080278A0
	adds r2, r6, 0
	ldr r1, =0x00003308
	mov r12, r1
	movs r7, 0
	movs r6, 0x4
	ldr r3, =0x0000330c
_08027884:
	ldr r0, [r2]
	lsls r1, r4, 3
	adds r0, r1
	add r0, r12
	strb r6, [r0]
	ldr r0, [r2]
	adds r0, r3
	adds r0, r1
	str r7, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08027884
_080278A0:
	movs r4, 0
	cmp r4, r5
	bcs _080278CA
_080278A6:
	adds r0, r4, 0
	bl sub_80276C0
	ldr r1, =0x000f4236
	bl sub_8027A38
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	lsls r2, r4, 3
	ldr r3, =0x0000330c
	adds r1, r3
	adds r1, r2
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _080278A6
_080278CA:
	mov r0, r10
	bl sub_80277D0
	adds r6, r0, 0
	mov r3, r8
	movs r4, 0
	cmp r4, r5
	bcs _08027916
	ldr r7, =gUnknown_02022C98
	mov r10, r7
_080278DE:
	mov r0, r10
	ldr r2, [r0]
	lsls r1, r4, 3
	ldr r7, =0x0000330c
	adds r0, r2, r7
	adds r0, r1
	ldr r0, [r0]
	cmp r6, r0
	bne _0802790C
	adds r0, r2, r1
	ldr r1, =0x00003308
	adds r0, r1
	strb r3, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0802790C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _080278DE
_08027916:
	mov r10, r8
	cmp r9, r5
	bcc _080278CA
	movs r0, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802784C

	thumb_func_start sub_802793C
sub_802793C: @ 802793C
	lsls r1, 24
	ldr r2, =gUnknown_02022C98
	ldr r2, [r2]
	lsrs r1, 21
	ldr r3, =0x00003308
	adds r2, r3
	adds r2, r1
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	.pool
	thumb_func_end sub_802793C

	thumb_func_start sub_802795C
sub_802795C: @ 802795C
	push {r4-r7,lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r6, r0, 24
	movs r7, 0
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r5, [r0]
	mov r0, sp
	movs r1, 0
	movs r2, 0x14
	bl memset
	movs r4, 0
	cmp r7, r5
	bcs _08027994
_0802797E:
	adds r0, r4, 0
	bl sub_80276C0
	lsls r1, r4, 2
	add r1, sp
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0802797E
_08027994:
	lsls r0, r6, 2
	add r0, sp
	ldr r1, [r0]
	movs r4, 0
_0802799C:
	cmp r4, r6
	beq _080279B0
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	cmp r1, r0
	bcs _080279B0
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_080279B0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _0802799C
	adds r0, r7, 0
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802795C

	thumb_func_start sub_80279C8
sub_80279C8: @ 80279C8
	push {r4-r6,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x28
	ldrb r4, [r0]
	bl sub_802762C
	lsls r0, 16
	lsrs r5, r0, 16
	adds r6, r5, 0
	adds r0, r4, 0
	bl sub_80276C0
	adds r4, r0, 0
	bl sub_8027748
	cmp r4, r0
	beq _080279F4
	movs r0, 0x3
	b _08027A22
	.pool
_080279F4:
	adds r0, r5, 0
	movs r1, 0x1
	bl CheckBagHasSpace
	lsls r0, 24
	cmp r0, 0
	bne _08027A06
	movs r0, 0x2
	b _08027A22
_08027A06:
	adds r0, r6, 0
	movs r1, 0x1
	bl AddBagItem
	adds r0, r6, 0
	movs r1, 0x1
	bl CheckBagHasSpace
	lsls r0, 24
	cmp r0, 0
	beq _08027A20
	movs r0, 0
	b _08027A22
_08027A20:
	movs r0, 0x1
_08027A22:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80279C8

	thumb_func_start sub_8027A28
sub_8027A28: @ 8027A28
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	cmp r2, r0
	bcs _08027A34
	adds r0, r2, 0x1
_08027A34:
	pop {r1}
	bx r1
	thumb_func_end sub_8027A28

	thumb_func_start sub_8027A38
sub_8027A38: @ 8027A38
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	cmp r2, r0
	bcs _08027A44
	adds r0, r2, 0
_08027A44:
	pop {r1}
	bx r1
	thumb_func_end sub_8027A38

	thumb_func_start sub_8027A48
sub_8027A48: @ 8027A48
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	adds r1, 0x34
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8027A48

	thumb_func_start sub_8027A5C
sub_8027A5C: @ 8027A5C
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gSpecialVar_Result
_08027A62:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _08027A94
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0x55
	bne _08027A94
	movs r0, 0x1
	strh r0, [r6]
	b _08027AA0
	.pool
_08027A94:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08027A62
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
_08027AA0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027A5C

	thumb_func_start sub_8027AAC
sub_8027AAC: @ 8027AAC
	push {r4,lr}
	ldr r4, =sub_8027ACC
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027AAC

	thumb_func_start sub_8027ACC
sub_8027ACC: @ 8027ACC
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	beq _08027B94
	cmp r0, 0x1
	bgt _08027AF4
	cmp r0, 0
	beq _08027AFE
	b _08027BE2
	.pool
_08027AF4:
	cmp r0, 0x2
	beq _08027BA0
	cmp r0, 0x3
	beq _08027BC8
	b _08027BE2
_08027AFE:
	ldr r0, =gUnknown_082F7B2C
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r1, =gText_BerryPickingRecords
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0
	movs r6, 0
	ldr r5, =gUnknown_082F7B34
_08027B18:
	ldr r1, [r5]
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r0, 0x32
	cmp r0, r4
	ble _08027B2A
	adds r4, r0, 0
_08027B2A:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x2
	bls _08027B18
	adds r0, r4, 0x7
	cmp r0, 0
	bge _08027B3A
	adds r0, 0x7
_08027B3A:
	asrs r4, r0, 3
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08027B46
	adds r4, 0x1
_08027B46:
	movs r1, 0x1E
	subs r1, r4
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	lsls r1, 24
	lsrs r1, 16
	ldr r2, =0xffff00ff
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r4, 24
	ldr r1, =0x00ffffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	strh r0, [r7, 0x2]
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_8027BEC
	ldrb r0, [r7, 0x2]
	movs r1, 0x3
	b _08027BB6
	.pool
_08027B94:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08027BE2
	b _08027BBA
_08027BA0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08027BE2
	ldrb r0, [r7, 0x2]
	bl rbox_fill_rectangle
	ldrb r0, [r7, 0x2]
	movs r1, 0x1
_08027BB6:
	bl CopyWindowToVram
_08027BBA:
	ldrh r0, [r7]
	adds r0, 0x1
	strh r0, [r7]
	b _08027BE2
	.pool
_08027BC8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08027BE2
	ldrb r0, [r7, 0x2]
	bl RemoveWindow
	adds r0, r4, 0
	bl DestroyTask
	bl EnableBothScriptContexts
_08027BE2:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8027ACC

	thumb_func_start sub_8027BEC
sub_8027BEC: @ 8027BEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r1, [sp, 0x18]
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r2, 0x84
	lsls r2, 2
	adds r0, r1, r2
	ldrh r0, [r0]
	str r0, [sp, 0xC]
	subs r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [sp, 0x10]
	ldr r0, =0x00000212
	adds r1, r0
	ldrh r0, [r1]
	str r0, [sp, 0x14]
	ldr r4, =0x0000021d
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0xD0
	bl LoadUserWindowBorderGfx_
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0xD
	bl DrawTextBorderOuter
	adds r0, r7, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r4, =gText_BerryPickingRecords
	ldr r0, [sp, 0x18]
	lsls r2, r0, 3
	movs r0, 0x1
	adds r1, r4, 0
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized
	movs r6, 0
	ldr r2, =gStringVar1
	mov r8, r2
	movs r0, 0xFF
	mov r10, r0
	mov r9, r6
	mov r2, sp
	adds r2, 0xC
	str r2, [sp, 0x1C]
_08027C76:
	lsls r4, r6, 2
	ldr r0, [sp, 0x1C]
	ldm r0!, {r1}
	str r0, [sp, 0x1C]
	ldr r0, =gUnknown_082F7B40
	adds r0, r6, r0
	ldrb r3, [r0]
	mov r0, r8
	movs r2, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	mov r1, r8
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r5, r0, 0
	ldr r0, =gUnknown_082F7B34
	adds r4, r0
	ldr r2, [r4]
	ldr r0, =gUnknown_082F7B44
	lsls r4, r6, 1
	adds r0, r4, r0
	ldrb r0, [r0]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r2, [sp, 0x18]
	lsls r3, r2, 3
	subs r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_082F7B4A
	adds r4, r0
	ldrb r0, [r4]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r8
	bl AddTextPrinterParameterized
	adds r6, 0x1
	cmp r6, 0x2
	ble _08027C76
	adds r0, r7, 0
	bl PutWindowTilemap
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027BEC

	thumb_func_start sub_8027D20
sub_8027D20: @ 8027D20
	push {lr}
	bl GetLinkPlayerCount
	ldr r1, =gUnknown_02022C98
	ldr r1, [r1]
	adds r1, 0x24
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027D20

	thumb_func_start sub_8027D38
sub_8027D38: @ 8027D38
	push {r4-r7,lr}
	ldr r0, =gUnknown_02022C98
	ldr r0, [r0]
	adds r0, 0x24
	ldrb r4, [r0]
	cmp r4, 0x4
	bhi _08027D66
	ldr r5, =gUnknown_082F7B90
_08027D48:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r1, =gLinkPlayers + 8
	adds r0, r1
	lsls r1, r4, 2
	adds r1, r5
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _08027D48
_08027D66:
	ldr r0, =gUnknown_02022C98
	ldr r1, [r0]
	adds r1, 0x24
	movs r2, 0x5
	strb r2, [r1]
	movs r1, 0
	mov r12, r0
_08027D74:
	movs r4, 0
	mov r2, r12
	ldr r0, [r2]
	adds r0, 0x24
	adds r5, r1, 0x1
	ldrb r0, [r0]
	cmp r4, r0
	bcs _08027DB2
	ldr r7, =gUnknown_02022C98
	lsls r3, r1, 1
	ldr r6, =gUnknown_082F7B50
_08027D8A:
	ldr r2, [r7]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r3, r0
	adds r1, r2, 0
	adds r1, 0x4A
	adds r1, r0
	lsls r0, r4, 3
	adds r0, r3, r0
	adds r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r2, 0x24
	ldrb r2, [r2]
	cmp r4, r2
	bcc _08027D8A
_08027DB2:
	lsls r0, r5, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _08027D74
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027D38

	thumb_func_start sub_8027DD0
sub_8027DD0: @ 8027DD0
	push {lr}
	sub sp, 0x8
	ldr r3, =0xffffff00
	ldr r1, [sp]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	str r1, [sp]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp, 0x4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8027DD0

	thumb_func_start sub_8027DFC
sub_8027DFC: @ 8027DFC
	push {lr}
	adds r2, r0, 0
	ldr r3, =gRecvCmds
	ldrh r0, [r3]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _08027E1E
	lsls r0, r2, 4
	adds r1, r3, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08027E28
_08027E1E:
	movs r0, 0
	b _08027E2A
	.pool
_08027E28:
	ldrb r0, [r1, 0x4]
_08027E2A:
	pop {r1}
	bx r1
	thumb_func_end sub_8027DFC

	thumb_func_start sub_8027E30
sub_8027E30: @ 8027E30
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x48]
	lsls r4, 24
	str r4, [sp, 0x1C]
	movs r4, 0x14
	adds r4, r0
	mov r9, r4
	mov r5, sp
	movs r4, 0x2
	strb r4, [r5]
	mov r10, sp
	mov r5, r9
	ldrb r4, [r5, 0xB]
	movs r7, 0xF
	adds r5, r7, 0
	ands r5, r4
	mov r6, r10
	ldrb r6, [r6, 0x1]
	mov r8, r6
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x1]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0xC]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x1]
	ldrb r5, [r6, 0xD]
	movs r6, 0xF
	ands r5, r6
	mov r4, r10
	ldrb r4, [r4, 0x2]
	mov r8, r4
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x2]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0xE]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x2]
	ldrb r5, [r6, 0xF]
	movs r6, 0xF
	ands r5, r6
	mov r4, r10
	ldrb r4, [r4, 0x3]
	mov r8, r4
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x3]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0x10]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x3]
	ldrb r5, [r6, 0x11]
	movs r6, 0xF
	ands r5, r6
	mov r4, r10
	ldrb r4, [r4, 0x4]
	mov r8, r4
	movs r4, 0x10
	negs r4, r4
	mov r6, r8
	ands r4, r6
	orrs r4, r5
	mov r5, r10
	strb r4, [r5, 0x4]
	mov r8, sp
	mov r6, r9
	ldrb r5, [r6, 0x12]
	lsls r5, 4
	ands r4, r7
	orrs r4, r5
	mov r5, r8
	strb r4, [r5, 0x4]
	ldrb r4, [r6, 0x13]
	movs r6, 0xF
	ands r4, r6
	mov r6, r8
	ldrb r5, [r6, 0x5]
	movs r6, 0x10
	negs r6, r6
	ands r6, r5
	orrs r6, r4
	str r6, [sp, 0xC]
	mov r4, r8
	strb r6, [r4, 0x5]
	mov r5, sp
	mov r6, r9
	ldrb r4, [r6, 0x14]
	lsls r4, 4
	ldr r6, [sp, 0xC]
	ands r6, r7
	orrs r6, r4
	strb r6, [r5, 0x5]
	mov r7, sp
	movs r4, 0x3
	mov r8, r4
	ldrb r0, [r0, 0x14]
	mov r5, r8
	ands r0, r5
	ldrb r5, [r7, 0x6]
	movs r6, 0x4
	negs r6, r6
	mov r10, r6
	mov r4, r10
	ands r4, r5
	orrs r4, r0
	strb r4, [r7, 0x6]
	mov r5, r9
	ldrb r0, [r5, 0x1]
	mov r6, r8
	ands r0, r6
	lsls r0, 2
	movs r5, 0xD
	negs r5, r5
	ands r5, r4
	orrs r5, r0
	strb r5, [r7, 0x6]
	mov r0, r9
	ldrb r4, [r0, 0x2]
	ands r4, r6
	lsls r4, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r5
	orrs r0, r4
	strb r0, [r7, 0x6]
	mov r5, sp
	mov r6, r9
	ldrb r4, [r6, 0x3]
	lsls r4, 6
	movs r6, 0x3F
	ands r0, r6
	orrs r0, r4
	strb r0, [r5, 0x6]
	mov r4, r9
	ldrb r0, [r4, 0x4]
	mov r5, r8
	ands r0, r5
	ldrb r5, [r7, 0x7]
	mov r4, r10
	ands r4, r5
	orrs r4, r0
	strb r4, [r7, 0x7]
	mov r6, r9
	ldrb r0, [r6, 0x5]
	mov r5, r8
	ands r0, r5
	lsls r0, 2
	movs r5, 0xD
	negs r5, r5
	ands r5, r4
	orrs r5, r0
	strb r5, [r7, 0x7]
	ldrb r4, [r6, 0x6]
	mov r6, r8
	ands r4, r6
	lsls r4, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r5
	orrs r0, r4
	strb r0, [r7, 0x7]
	mov r5, sp
	mov r6, r9
	ldrb r4, [r6, 0x7]
	lsls r4, 6
	movs r6, 0x3F
	ands r0, r6
	orrs r0, r4
	strb r0, [r5, 0x7]
	mov r8, sp
	mov r0, r9
	ldrb r4, [r0, 0x8]
	movs r7, 0x3
	adds r0, r7, 0
	ands r0, r4
	mov r4, r8
	ldrb r5, [r4, 0x8]
	mov r4, r10
	ands r4, r5
	orrs r4, r0
	mov r5, r8
	strb r4, [r5, 0x8]
	mov r6, r9
	ldrb r5, [r6, 0x9]
	adds r0, r7, 0
	ands r0, r5
	lsls r0, 2
	movs r5, 0xD
	negs r5, r5
	ands r5, r4
	orrs r5, r0
	mov r0, r8
	strb r5, [r0, 0x8]
	ldrb r0, [r1]
	adds r4, r7, 0
	ands r4, r0
	lsls r4, 4
	movs r0, 0x31
	negs r0, r0
	ands r0, r5
	orrs r0, r4
	mov r4, r8
	strb r0, [r4, 0x8]
	mov r5, sp
	ldrb r4, [r2]
	lsls r4, 6
	movs r6, 0x3F
	ands r0, r6
	orrs r0, r4
	strb r0, [r5, 0x8]
	ldrb r4, [r3]
	adds r0, r7, 0
	ands r0, r4
	ldrb r4, [r5, 0x9]
	mov r6, r10
	ands r6, r4
	orrs r6, r0
	mov r10, r6
	strb r6, [r5, 0x9]
	ldr r0, [sp, 0x40]
	ldrb r4, [r0]
	adds r0, r7, 0
	ands r0, r4
	lsls r0, 2
	movs r4, 0xD
	negs r4, r4
	ands r6, r4
	orrs r6, r0
	str r6, [sp, 0x10]
	strb r6, [r5, 0x9]
	mov r4, sp
	ldr r5, [sp, 0x44]
	ldrb r0, [r5]
	adds r6, r7, 0
	ands r6, r0
	lsls r0, r6, 4
	subs r7, 0x34
	ldr r5, [sp, 0x10]
	ands r7, r5
	orrs r7, r0
	strb r7, [r4, 0x9]
	mov r5, sp
	ldrb r0, [r1, 0x4]
	movs r6, 0x1
	mov r12, r6
	mov r4, r12
	ands r4, r0
	lsls r4, 6
	movs r0, 0x41
	negs r0, r0
	mov r10, r0
	ands r0, r7
	orrs r0, r4
	strb r0, [r5, 0x9]
	ldrb r4, [r2, 0x4]
	lsls r4, 7
	movs r5, 0x7F
	ands r0, r5
	orrs r0, r4
	mov r4, r8
	strb r0, [r4, 0x9]
	ldrb r4, [r3, 0x4]
	mov r0, r12
	ands r0, r4
	mov r5, r8
	ldrb r4, [r5, 0xA]
	movs r7, 0x2
	negs r7, r7
	adds r5, r7, 0
	ands r5, r4
	orrs r5, r0
	mov r6, r8
	strb r5, [r6, 0xA]
	mov r9, sp
	ldr r4, [sp, 0x40]
	ldrb r0, [r4, 0x4]
	mov r4, r12
	ands r4, r0
	lsls r4, 1
	movs r6, 0x3
	negs r6, r6
	mov r8, r6
	mov r0, r8
	ands r0, r5
	orrs r0, r4
	mov r4, r9
	strb r0, [r4, 0xA]
	ldr r6, [sp, 0x44]
	ldrb r5, [r6, 0x4]
	mov r4, r12
	ands r4, r5
	lsls r4, 2
	movs r5, 0x5
	negs r5, r5
	ands r0, r5
	orrs r0, r4
	mov r4, r9
	strb r0, [r4, 0xA]
	mov r4, sp
	ldrb r1, [r1, 0x8]
	mov r0, r12
	ands r0, r1
	lsls r0, 2
	ldrb r1, [r4, 0xB]
	ands r5, r1
	orrs r5, r0
	strb r5, [r4, 0xB]
	ldrb r1, [r2, 0x8]
	mov r0, r12
	ands r0, r1
	lsls r0, 3
	movs r1, 0x9
	negs r1, r1
	ands r1, r5
	orrs r1, r0
	strb r1, [r4, 0xB]
	ldrb r2, [r3, 0x8]
	mov r0, r12
	ands r0, r2
	lsls r0, 4
	movs r2, 0x11
	negs r2, r2
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, 0xB]
	mov r3, sp
	ldr r5, [sp, 0x40]
	ldrb r0, [r5, 0x8]
	mov r1, r12
	ands r1, r0
	lsls r1, 5
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0xB]
	mov r2, sp
	ldrb r1, [r6, 0x8]
	mov r6, r12
	ands r6, r1
	lsls r1, r6, 6
	mov r3, r10
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0xB]
	ldr r4, [sp, 0x1C]
	lsrs r3, r4, 21
	ldrb r1, [r2, 0xA]
	movs r0, 0x7
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, 0xA]
	mov r1, sp
	ldr r5, [sp, 0x4C]
	movs r6, 0x1
	ands r5, r6
	lsls r2, r5, 1
	ldrb r0, [r1, 0xB]
	mov r3, r8
	ands r3, r0
	orrs r3, r2
	mov r8, r3
	strb r3, [r1, 0xB]
	mov r0, sp
	ldr r4, [sp, 0x50]
	ands r4, r6
	mov r5, r8
	ands r5, r7
	orrs r5, r4
	strb r5, [r0, 0xB]
	bl sub_800FE50
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8027E30

	thumb_func_start sub_8028164
sub_8028164: @ 8028164
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r0, [sp, 0x1C]
	mov r12, r0
	ldr r1, [sp, 0x20]
	mov r8, r1
	ldr r0, [sp, 0x24]
	mov r9, r0
	adds r2, r7, 0
	adds r2, 0x14
	ldr r4, =gRecvCmds
	ldrh r0, [r4]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _0802819C
	adds r3, r4, 0x2
	ldrb r0, [r4, 0x2]
	cmp r0, 0x2
	beq _080281A4
_0802819C:
	movs r0, 0
	b _080282DE
	.pool
_080281A4:
	ldrb r0, [r3, 0x1]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0xB]
	ldrb r0, [r3, 0x1]
	lsrs r0, 4
	strb r0, [r2, 0xC]
	ldrb r0, [r3, 0x2]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0xD]
	ldrb r0, [r3, 0x2]
	lsrs r0, 4
	strb r0, [r2, 0xE]
	ldrb r0, [r3, 0x3]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0xF]
	ldrb r0, [r3, 0x3]
	lsrs r0, 4
	strb r0, [r2, 0x10]
	ldrb r0, [r3, 0x4]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0x11]
	ldrb r0, [r3, 0x4]
	lsrs r0, 4
	strb r0, [r2, 0x12]
	ldrb r0, [r3, 0x5]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0x13]
	ldrb r0, [r3, 0x5]
	lsrs r0, 4
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r2, 0x15]
	ldrb r0, [r3, 0x6]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r7, 0x14]
	ldrb r0, [r3, 0x6]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r2, 0x1]
	ldrb r0, [r3, 0x6]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r2, 0x2]
	ldrb r0, [r3, 0x6]
	lsrs r0, 6
	strb r0, [r2, 0x3]
	ldrb r0, [r3, 0x7]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r2, 0x4]
	ldrb r0, [r3, 0x7]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r2, 0x5]
	ldrb r0, [r3, 0x7]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r2, 0x6]
	ldrb r0, [r3, 0x7]
	lsrs r0, 6
	strb r0, [r2, 0x7]
	ldrb r0, [r3, 0x8]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r2, 0x8]
	ldrb r0, [r3, 0x8]
	lsls r0, 28
	lsrs r0, 30
	strb r0, [r2, 0x9]
	ldrb r0, [r3, 0x6]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r2, 0xA]
	ldrb r0, [r3, 0x8]
	lsls r0, 26
	lsrs r0, 30
	strb r0, [r5]
	ldrb r0, [r3, 0x9]
	lsls r0, 25
	lsrs r0, 31
	strb r0, [r5, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 29
	lsrs r0, 31
	strb r0, [r5, 0x8]
	ldrb r0, [r3, 0x8]
	lsrs r0, 6
	strb r0, [r6]
	ldrb r0, [r3, 0x9]
	lsrs r0, 7
	strb r0, [r6, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 28
	lsrs r0, 31
	strb r0, [r6, 0x8]
	ldrb r0, [r3, 0x9]
	lsls r0, 30
	lsrs r0, 30
	mov r1, r12
	strb r0, [r1]
	ldrb r0, [r3, 0xA]
	lsls r0, 31
	lsrs r0, 31
	strb r0, [r1, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 27
	lsrs r0, 31
	strb r0, [r1, 0x8]
	ldrb r0, [r3, 0x9]
	lsls r0, 28
	lsrs r0, 30
	mov r1, r8
	strb r0, [r1]
	ldrb r0, [r3, 0xA]
	lsls r0, 30
	lsrs r0, 31
	strb r0, [r1, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 26
	lsrs r0, 31
	strb r0, [r1, 0x8]
	ldrb r0, [r3, 0x9]
	lsls r0, 26
	lsrs r0, 30
	mov r1, r9
	strb r0, [r1]
	ldrb r0, [r3, 0xA]
	lsls r0, 29
	lsrs r0, 31
	strb r0, [r1, 0x4]
	ldrb r0, [r3, 0xB]
	lsls r0, 25
	lsrs r0, 31
	strb r0, [r1, 0x8]
	ldrb r0, [r3, 0xA]
	lsrs r0, 3
	ldr r1, [sp, 0x28]
	strb r0, [r1]
	ldrb r0, [r3, 0xB]
	lsls r0, 30
	lsrs r0, 31
	ldr r1, [sp, 0x2C]
	str r0, [r1]
	ldrb r0, [r3, 0xB]
	lsls r0, 31
	lsrs r0, 31
	ldr r1, [sp, 0x30]
	str r0, [r1]
	movs r0, 0x1
_080282DE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8028164

	thumb_func_start sub_80282EC
sub_80282EC: @ 80282EC
	push {lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0xffffff00
	ldr r1, [sp]
	ands r1, r3
	movs r2, 0x3
	orrs r1, r2
	str r1, [sp]
	ldr r1, [sp, 0x4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80282EC

	thumb_func_start sub_8028318
sub_8028318: @ 8028318
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldr r3, =gRecvCmds
	ldrh r0, [r3]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _0802833C
	lsls r0, r2, 4
	adds r1, r3, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08028344
_0802833C:
	movs r0, 0
	b _0802834A
	.pool
_08028344:
	ldrb r0, [r1, 0x4]
	strb r0, [r4]
	movs r0, 0x1
_0802834A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8028318

	thumb_func_start sub_8028350
sub_8028350: @ 8028350
	push {lr}
	sub sp, 0x8
	ldr r2, =0xffffff00
	ldr r1, [sp]
	ands r1, r2
	movs r2, 0x4
	orrs r1, r2
	str r1, [sp]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800FE50
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028350

	thumb_func_start sub_8028374
sub_8028374: @ 8028374
	push {lr}
	adds r2, r0, 0
	ldr r3, =gRecvCmds
	ldrh r0, [r3]
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r0
	movs r0, 0xBC
	lsls r0, 6
	cmp r1, r0
	bne _08028396
	lsls r0, r2, 4
	adds r1, r3, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _080283A0
_08028396:
	movs r0, 0
	b _080283A2
	.pool
_080283A0:
	ldr r0, [r1, 0x4]
_080283A2:
	pop {r1}
	bx r1
	thumb_func_end sub_8028374

	thumb_func_start sub_80283A8
sub_80283A8: @ 80283A8
	push {r4,r5,lr}
	sub sp, 0x18
	movs r5, 0xC0
	lsls r5, 6
	adds r0, r5, 0
	bl AllocZeroed
	adds r4, r0, 0
	ldr r0, =gUnknown_082FB2D8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gUnknown_082FB2E0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, =gDodrioBerryPkmnGfx
	adds r1, r4, 0
	bl LZ77UnCompWram
	cmp r4, 0
	beq _080283E8
	str r4, [sp]
	str r5, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r4, 0
	bl Free
_080283E8:
	add r0, sp, 0x8
	bl LoadSpritePalette
	add r0, sp, 0x10
	bl LoadSpritePalette
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80283A8

	thumb_func_start sub_8028408
sub_8028408: @ 8028408
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x30
	adds r6, r1, 0
	mov r8, r2
	adds r5, r3, 0
	lsls r6, 24
	lsrs r6, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r5, 24
	lsrs r5, 24
	add r1, sp, 0x18
	movs r3, 0
	strh r3, [r1]
	ldrb r2, [r0]
	mov r0, sp
	adds r0, 0x1A
	strh r2, [r0]
	ldr r0, =gUnknown_082FB1E0
	str r0, [sp, 0x1C]
	ldr r0, =gUnknown_082FB228
	str r0, [sp, 0x20]
	str r3, [sp, 0x24]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [sp, 0x28]
	ldr r0, =sub_80284A8
	str r0, [sp, 0x2C]
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	movs r0, 0x4
	bl AllocZeroed
	ldr r1, =gUnknown_02022C9C
	mov r2, r8
	lsls r4, r2, 2
	adds r4, r1
	str r0, [r4]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8028F14
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	movs r2, 0x88
	movs r3, 0x3
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	movs r0, 0x1
	mov r1, r8
	bl sub_8028654
	add sp, 0x30
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028408

	thumb_func_start sub_80284A8
sub_80284A8: @ 80284A8
	push {lr}
	movs r2, 0x2E
	ldrsh r1, [r0, r2]
	cmp r1, 0x1
	beq _080284BC
	cmp r1, 0x1
	ble _080284C6
	cmp r1, 0x2
	beq _080284C2
	b _080284C6
_080284BC:
	bl sub_802853C
	b _080284C6
_080284C2:
	bl sub_80285AC
_080284C6:
	pop {r0}
	bx r0
	thumb_func_end sub_80284A8

	thumb_func_start sub_80284CC
sub_80284CC: @ 80284CC
	push {lr}
	bl GetMultiplayerId
	ldr r1, =gUnknown_02022C9C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x32]
	strh r2, [r0, 0x34]
	strh r2, [r0, 0x36]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80284CC

	thumb_func_start sub_8028504
sub_8028504: @ 8028504
	push {lr}
	bl GetMultiplayerId
	ldr r1, =gUnknown_02022C9C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r2, 0
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	strh r2, [r0, 0x30]
	strh r2, [r0, 0x32]
	strh r2, [r0, 0x34]
	strh r2, [r0, 0x36]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028504

	thumb_func_start sub_802853C
sub_802853C: @ 802853C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r2, r0, 16
	lsrs r0, 31
	adds r0, r2, r0
	asrs r1, r0, 1
	adds r0, r1, 0
	cmp r1, 0
	bge _08028558
	adds r0, r1, 0x3
_08028558:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 24
	lsrs r0, 24
	cmp r2, 0x2
	ble _080285A2
	cmp r0, 0x2
	bgt _0802856E
	cmp r0, 0x1
	bge _08028572
_0802856E:
	movs r0, 0x1
	b _08028574
_08028572:
	movs r0, 0xFF
_08028574:
	lsls r0, 24
	asrs r0, 24
	ldrh r1, [r4, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _080285A2
	movs r0, 0
	strh r0, [r4, 0x2E]
	bl sub_8027650
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_8028F14
	strh r0, [r4, 0x20]
_080285A2:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802853C

	thumb_func_start sub_80285AC
sub_80285AC: @ 80285AC
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x30]
	adds r0, 0x1
	strh r0, [r5, 0x30]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0xD
	bl __divsi3
	lsls r0, 16
	asrs r1, r0, 16
	adds r0, r1, 0
	cmp r1, 0
	bge _080285CC
	adds r0, r1, 0x3
_080285CC:
	asrs r0, 2
	lsls r0, 2
	subs r0, r1, r0
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	movs r1, 0xD
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _080285F0
	cmp r4, 0
	beq _080285F0
	movs r0, 0xD4
	bl PlaySE
_080285F0:
	movs r1, 0x30
	ldrsh r0, [r5, r1]
	cmp r0, 0x67
	ble _080285FE
	movs r0, 0
	strh r0, [r5, 0x2E]
	movs r4, 0
_080285FE:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_80286B4
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80285AC

	thumb_func_start sub_8028614
sub_8028614: @ 8028614
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	cmp r4, r5
	bcs _08028646
	ldr r6, =gUnknown_02022C9C
_08028622:
	lsls r0, r4, 2
	adds r0, r6
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _0802863C
	bl DestroySpriteAndFreeResources
_0802863C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _08028622
_08028646:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028614

	thumb_func_start sub_8028654
sub_8028654: @ 8028654
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_02022C9C
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	ldrh r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r3
	adds r2, 0x3E
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	ldrb r3, [r2]
	movs r1, 0x5
	negs r1, r1
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end sub_8028654

	thumb_func_start sub_802868C
sub_802868C: @ 802868C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r4, 0
	cmp r4, r5
	bcs _080286AE
_0802869C:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8028654
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0802869C
_080286AE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802868C

	thumb_func_start sub_80286B4
sub_80286B4: @ 80286B4
	push {lr}
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022C9C
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80286B4

	thumb_func_start nullsub_15
nullsub_15: @ 80286E0
	bx lr
	thumb_func_end nullsub_15

	thumb_func_start sub_80286E4
sub_80286E4: @ 80286E4
	push {r4-r7,lr}
	movs r4, 0
	ldr r0, =gSprites
	mov r12, r0
	movs r6, 0
	ldr r5, =gUnknown_02022CF4
_080286F0:
	ldr r3, [r5]
	lsls r1, r4, 1
	adds r0, r3, 0
	adds r0, 0x2A
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r12
	lsls r0, r4, 4
	adds r0, 0x30
	strh r0, [r1, 0x20]
	lsls r2, r4, 3
	movs r7, 0x8
	negs r7, r7
	adds r0, r7, 0
	subs r0, r2
	strh r0, [r1, 0x22]
	adds r3, 0xC
	adds r3, r4
	strb r6, [r3]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080286F0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80286E4

	thumb_func_start sub_8028734
sub_8028734: @ 8028734
	push {r4-r6,lr}
	sub sp, 0x28
	movs r4, 0xC0
	lsls r4, 1
	adds r0, r4, 0
	bl AllocZeroed
	adds r6, r0, 0
	ldr r0, =gUnknown_082FB2E8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, =gDodrioBerryStatusGfx
	adds r1, r6, 0
	bl LZ77UnCompWram
	cmp r6, 0
	beq _080287C4
	str r6, [sp, 0x18]
	add r5, sp, 0x18
	movs r0, 0x80
	lsls r0, 9
	orrs r0, r4
	str r0, [r5, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_082FB2F0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r4, =gUnknown_02022CF4
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4]
	adds r0, r5, 0
	bl LoadSpriteSheet
	add r0, sp, 0x20
	bl LoadSpritePalette
	movs r4, 0
_0802878A:
	lsls r1, r4, 20
	movs r0, 0xC0
	lsls r0, 14
	adds r1, r0
	asrs r1, 16
	lsls r0, r4, 3
	movs r3, 0x8
	negs r3, r3
	adds r2, r3, 0
	subs r2, r0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r3, 0
	bl CreateSprite
	ldr r1, =gUnknown_02022CF4
	ldr r1, [r1]
	lsls r2, r4, 1
	adds r1, 0x2A
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _0802878A
_080287C4:
	adds r0, r6, 0
	bl Free
	add sp, 0x28
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028734

	thumb_func_start sub_80287E4
sub_80287E4: @ 80287E4
	push {r4,r5,lr}
	movs r4, 0
_080287E8:
	ldr r5, =gUnknown_02022CF4
	ldr r0, [r5]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028806
	bl DestroySpriteAndFreeResources
_08028806:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080287E8
	ldr r0, [r5]
	bl Free
	movs r0, 0
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80287E4

	thumb_func_start sub_8028828
sub_8028828: @ 8028828
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r3, 0
	movs r6, 0
	ldr r0, =gUnknown_02022CF4
	mov r9, r0
_0802883A:
	mov r7, r9
	ldr r2, [r7]
	lsls r5, r6, 1
	adds r0, r2, 0
	adds r0, 0x2A
	adds r0, r5
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r2, 0
	adds r0, 0x16
	adds r0, r5
	movs r1, 0x2
	strh r1, [r0]
	adds r0, r2, 0
	adds r0, 0xC
	adds r2, r0, r6
	ldrb r1, [r2]
	cmp r1, 0
	beq _08028870
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	cmp r0, 0x8
	beq _080288A6
_08028870:
	movs r3, 0x1
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	cmp r0, 0x8
	bne _08028896
	cmp r1, 0
	bne _080288A6
	strb r3, [r2]
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0x16
	adds r0, r5
	ldr r1, =0x0000fff0
	strh r1, [r0]
	movs r0, 0x24
	str r3, [sp]
	bl PlaySE
	ldr r3, [sp]
_08028896:
	mov r7, r9
	ldr r0, [r7]
	adds r0, 0x16
	adds r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, 0x22]
	adds r0, r1
	strh r0, [r4, 0x22]
_080288A6:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x9
	bls _0802883A
	cmp r3, 0
	bne _080288C4
	movs r0, 0x1
	b _080288C6
	.pool
_080288C4:
	movs r0, 0
_080288C6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8028828

	thumb_func_start sub_80288D4
sub_80288D4: @ 80288D4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08028910
	movs r4, 0
_080288E0:
	ldr r0, =gUnknown_02022CF4
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080288E0
	b _080289DA
	.pool
_08028910:
	movs r4, 0
	movs r0, 0xA
	subs r0, r5
	cmp r4, r0
	bge _080289D6
	ldr r6, =gSprites
_0802891C:
	cmp r5, 0x6
	bls _08028984
	ldr r0, =gUnknown_02022CF4
	ldr r2, [r0]
	ldr r1, =0x0000fffa
	adds r0, r1, 0
	ldrh r1, [r2, 0x3E]
	adds r0, r1
	adds r0, r5
	movs r1, 0
	strh r0, [r2, 0x3E]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _0802894C
	strh r1, [r2, 0x3E]
	b _0802899E
	.pool
_0802894C:
	cmp r0, 0xA
	bls _0802896A
	lsls r1, r4, 1
	adds r0, r2, 0
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x2
	bl StartSpriteAnim
	b _0802899E
_0802896A:
	lsls r1, r4, 1
	adds r0, r2, 0
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0
	bl StartSpriteAnim
	b _0802899E
_08028984:
	ldr r0, =gUnknown_02022CF4
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0
	bl StartSpriteAnim
_0802899E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0xA
	subs r0, r5
	cmp r4, r0
	blt _0802891C
	b _080289D6
	.pool
_080289B4:
	ldr r0, =gUnknown_02022CF4
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080289D6:
	cmp r4, 0x9
	bls _080289B4
_080289DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80288D4

	thumb_func_start sub_80289E8
sub_80289E8: @ 80289E8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r7, =gSprites
	movs r1, 0x1
	ands r0, r1
	lsls r4, r0, 2
	movs r6, 0x5
	negs r6, r6
	ldr r5, =gUnknown_02022CF4
_080289FE:
	ldr r0, [r5]
	lsls r1, r3, 1
	adds r0, 0x2A
	adds r0, r1
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x9
	bls _080289FE
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80289E8

	thumb_func_start sub_8028A34
sub_8028A34: @ 8028A34
	push {r4,r5,lr}
	sub sp, 0x10
	movs r5, 0x90
	lsls r5, 3
	adds r0, r5, 0
	bl AllocZeroed
	adds r4, r0, 0
	ldr r0, =gUnknown_082FB314
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r0, =gDodrioBerrySpritesGfx
	adds r1, r4, 0
	bl LZ77UnCompWram
	cmp r4, 0
	beq _08028A6A
	str r4, [sp]
	movs r0, 0x80
	lsls r0, 10
	orrs r0, r5
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
_08028A6A:
	add r0, sp, 0x8
	bl LoadSpritePalette
	adds r0, r4, 0
	bl Free
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028A34

	thumb_func_start sub_8028A88
sub_8028A88: @ 8028A88
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x30
	mov r1, sp
	ldr r0, =gUnknown_082FB324
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	add r2, sp, 0x18
	adds r1, r2, 0
	ldr r0, =gUnknown_082FB33C
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	movs r5, 0
	mov r9, r2
_08028AB0:
	movs r0, 0x4
	bl AllocZeroed
	ldr r1, =gUnknown_02022CB8
	lsls r4, r5, 2
	adds r4, r1
	str r0, [r4]
	lsls r0, r5, 3
	lsls r1, r5, 4
	adds r1, r0
	mov r0, sp
	movs r2, 0x8
	movs r3, 0x1
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8028BF8
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08028AB0
	movs r5, 0
	ldr r7, =gUnknown_02022CE4
	ldr r4, =gUnknown_082FB31C
	mov r8, r4
_08028AF0:
	movs r0, 0x4
	bl AllocZeroed
	lsls r1, r5, 2
	adds r4, r1, r7
	str r0, [r4]
	adds r6, r1, 0
	cmp r5, 0x3
	bne _08028B2C
	mov r0, r8
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	mov r0, r9
	movs r2, 0x31
	movs r3, 0
	bl CreateSprite
	ldr r1, [r7, 0xC]
	b _08028B40
	.pool
_08028B2C:
	lsls r0, r5, 1
	add r0, r8
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r0, r9
	movs r2, 0x34
	movs r3, 0
	bl CreateSprite
	ldr r1, [r4]
_08028B40:
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r6, r7
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r1, r5, 0
	bl StartSpriteAnim
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08028AF0
	movs r0, 0x1
	bl sub_8028C30
	add sp, 0x30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028A88

	thumb_func_start sub_8028B80
sub_8028B80: @ 8028B80
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_02022CB8
_08028B86:
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028BA0
	bl DestroySprite
_08028BA0:
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xA
	bls _08028B86
	movs r5, 0
	ldr r6, =gUnknown_02022CE4
_08028BB8:
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028BD2
	bl DestroySprite
_08028BD2:
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _08028BB8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028B80

	thumb_func_start sub_8028BF8
sub_8028BF8: @ 8028BF8
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_02022CB8
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	adds r2, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8028BF8

	thumb_func_start sub_8028C30
sub_8028C30: @ 8028C30
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r7, =gSprites
	ldr r6, =gUnknown_02022CE4
	movs r1, 0x1
	ands r0, r1
	lsls r4, r0, 2
	movs r5, 0x5
	negs r5, r5
_08028C46:
	lsls r0, r3, 2
	adds r0, r6
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3
	bls _08028C46
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028C30

	thumb_func_start sub_8028C7C
sub_8028C7C: @ 8028C7C
	lsls r0, 24
	lsls r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_02022CB8
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	lsrs r1, 21
	strh r1, [r0, 0x22]
	bx lr
	.pool
	thumb_func_end sub_8028C7C

	thumb_func_start sub_8028CA4
sub_8028CA4: @ 8028CA4
	push {lr}
	lsls r0, 16
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02022CB8
	lsrs r0, 14
	adds r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028CA4

	thumb_func_start sub_8028CD0
sub_8028CD0: @ 8028CD0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x32
	strh r1, [r2, 0x20]
	movs r0, 0x32
	strh r0, [r2, 0x22]
	bx lr
	.pool
	thumb_func_end sub_8028CD0

	thumb_func_start sub_8028CF4
sub_8028CF4: @ 8028CF4
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r0, 0x42
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _08028D36
	movs r3, 0
	ldr r7, =gUnknown_082FB354
	ldr r6, =gUnknown_02022CB0
	movs r5, 0
_08028D0A:
	lsls r0, r3, 2
	adds r2, r0, r6
	ldr r1, [r2]
	ldrh r0, [r1, 0x2]
	adds r0, 0x1
	strh r0, [r1, 0x2]
	adds r1, r3, r7
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r1]
	cmp r0, r1
	bls _08028D2C
	ldrh r0, [r4, 0x20]
	subs r0, 0x1
	strh r0, [r4, 0x20]
	ldr r0, [r2]
	strh r5, [r0, 0x2]
_08028D2C:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08028D0A
_08028D36:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028CF4

	thumb_func_start sub_8028D44
sub_8028D44: @ 8028D44
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x28
	movs r4, 0x80
	lsls r4, 3
	adds r0, r4, 0
	bl AllocZeroed
	adds r6, r0, 0
	ldr r0, =gUnknown_082FB360
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, =gDodrioBerryPlatformGfx
	adds r1, r6, 0
	bl LZ77UnCompWram
	cmp r6, 0
	beq _08028DD2
	str r6, [sp, 0x18]
	add r0, sp, 0x18
	movs r1, 0xA0
	lsls r1, 11
	orrs r1, r4
	str r1, [r0, 0x4]
	mov r2, sp
	ldr r1, =gUnknown_082FB368
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	bl LoadSpriteSheet
	add r0, sp, 0x20
	bl LoadSpritePalette
	movs r5, 0
	ldr r7, =gUnknown_082FB356
	adds r0, r7, 0x2
	mov r9, r0
	ldr r1, =gUnknown_02022CB0
	mov r8, r1
_08028D9E:
	movs r0, 0x4
	bl AllocZeroed
	lsls r2, r5, 2
	mov r3, r8
	adds r4, r2, r3
	str r0, [r4]
	adds r0, r2, r7
	movs r3, 0
	ldrsh r1, [r0, r3]
	add r2, r9
	movs r0, 0
	ldrsh r2, [r2, r0]
	mov r0, sp
	movs r3, 0x4
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _08028D9E
_08028DD2:
	adds r0, r6, 0
	bl Free
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028D44

	thumb_func_start sub_8028DFC
sub_8028DFC: @ 8028DFC
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gUnknown_02022CB0
	mov r12, r0
	ldr r4, =gUnknown_082FB356
	adds r7, r4, 0x2
	ldr r6, =gSprites
	movs r5, 0x1
_08028E0C:
	lsls r2, r3, 2
	mov r1, r12
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r0, r1, 0
	adds r0, 0x42
	strh r5, [r0]
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1, 0x20]
	adds r2, r7
	ldrh r0, [r2]
	strh r0, [r1, 0x22]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08028E0C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028DFC

	thumb_func_start sub_8028E4C
sub_8028E4C: @ 8028E4C
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gUnknown_02022CB0
	ldr r4, =gSprites
	movs r3, 0
_08028E56:
	lsls r0, r2, 2
	adds r0, r5
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x42
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1
	bls _08028E56
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028E4C

	thumb_func_start sub_8028E84
sub_8028E84: @ 8028E84
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, =gUnknown_02022CB0
_08028E8A:
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	cmp r0, 0
	beq _08028EA4
	bl DestroySprite
_08028EA4:
	ldr r0, [r4]
	bl Free
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x1
	bls _08028E8A
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028E84

	thumb_func_start sub_8028EC8
sub_8028EC8: @ 8028EC8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r7, =gSprites
	ldr r6, =gUnknown_02022CB0
	movs r1, 0x1
	ands r0, r1
	lsls r4, r0, 2
	movs r5, 0x5
	negs r5, r5
_08028EDE:
	lsls r0, r3, 2
	adds r0, r6
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1
	bls _08028EDE
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8028EC8

	thumb_func_start sub_8028F14
sub_8028F14: @ 8028F14
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r3, 0
	subs r0, r1, 0x1
	cmp r0, 0x4
	bhi _08028FC6
	lsls r0, 2
	ldr r1, =_08028F34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08028F34:
	.4byte _08028FB4
	.4byte _08028F48
	.4byte _08028F52
	.4byte _08028F66
	.4byte _08028F8E
_08028F48:
	cmp r2, 0
	beq _08028F7E
	cmp r2, 0x1
	bne _08028FC6
	b _08028F82
_08028F52:
	cmp r2, 0x1
	beq _08028FB8
	cmp r2, 0x1
	bgt _08028F60
	cmp r2, 0
	beq _08028FB4
	b _08028FC6
_08028F60:
	cmp r2, 0x2
	bne _08028FC6
	b _08028FC4
_08028F66:
	cmp r2, 0x1
	beq _08028F82
	cmp r2, 0x1
	bgt _08028F74
	cmp r2, 0
	beq _08028F7E
	b _08028FC6
_08028F74:
	cmp r2, 0x2
	beq _08028F86
	cmp r2, 0x3
	beq _08028F8A
	b _08028FC6
_08028F7E:
	movs r3, 0xC
	b _08028FC6
_08028F82:
	movs r3, 0x12
	b _08028FC6
_08028F86:
	movs r3, 0x18
	b _08028FC6
_08028F8A:
	movs r3, 0x6
	b _08028FC6
_08028F8E:
	cmp r2, 0x4
	bhi _08028FC6
	lsls r0, r2, 2
	ldr r1, =_08028FA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08028FA0:
	.4byte _08028FB4
	.4byte _08028FB8
	.4byte _08028FBC
	.4byte _08028FC0
	.4byte _08028FC4
_08028FB4:
	movs r3, 0xF
	b _08028FC6
_08028FB8:
	movs r3, 0x15
	b _08028FC6
_08028FBC:
	movs r3, 0x1B
	b _08028FC6
_08028FC0:
	movs r3, 0x3
	b _08028FC6
_08028FC4:
	movs r3, 0x9
_08028FC6:
	lsls r0, r3, 3
	pop {r1}
	bx r1
	thumb_func_end sub_8028F14

	thumb_func_start sub_8028FCC
sub_8028FCC: @ 8028FCC
	push {r4,lr}
	movs r4, 0
_08028FD0:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8028BF8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8028C7C
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xA
	bls _08028FD0
	movs r0, 0
	bl sub_80289E8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8028FCC

	thumb_func_start sub_8028FF8
sub_8028FF8: @ 8028FF8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl GetWindowFrameTilesPal
	ldr r1, [r0]
	movs r2, 0x90
	lsls r2, 1
	movs r0, 0
	movs r3, 0x1
	bl LoadBgTiles
	adds r0, r4, 0
	bl GetWindowFrameTilesPal
	ldr r0, [r0, 0x4]
	movs r1, 0xA0
	movs r2, 0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8028FF8

	thumb_func_start sub_802902C
sub_802902C: @ 802902C
	push {lr}
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xB0
	bl LoadUserWindowBorderGfx_
	pop {r0}
	bx r0
	thumb_func_end sub_802902C

	thumb_func_start sub_802903C
sub_802903C: @ 802903C
	ldr r3, =gUnknown_02022CF8
	ldr r0, [r3]
	movs r2, 0xC0
	lsls r2, 6
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r1, =0x00003014
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x8
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	bx lr
	.pool
	thumb_func_end sub_802903C

	thumb_func_start sub_8029074
sub_8029074: @ 8029074
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r6, 0xA
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x2
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x3
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x4
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x6
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x7
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x8
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r4, [r4, 0x2]
	adds r3, r4
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x9
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8029074

	thumb_func_start sub_8029174
sub_8029174: @ 8029174
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r6, 0xB
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r5, 0x1
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xA
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xB
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xC
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xD
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x2]
	str r5, [sp]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0xF
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x10
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x1]
	ldrb r3, [r4, 0x4]
	ldrb r0, [r4, 0x2]
	adds r3, r0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x3]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x11
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x1]
	adds r2, r0
	lsls r2, 24
	lsrs r2, 24
	ldrb r3, [r4, 0x4]
	ldrb r4, [r4, 0x2]
	adds r3, r4
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	movs r1, 0x12
	bl FillBgTilemapBufferRect
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8029174

	thumb_func_start sub_8029274
sub_8029274: @ 8029274
	push {r4,lr}
	ldr r4, =gUnknown_02022CF8
	str r0, [r4]
	movs r2, 0xC0
	lsls r2, 6
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r3, =0x00003014
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, =0x00003018
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, 0xC
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0xC
	adds r0, r1
	strb r2, [r0]
	ldr r0, =sub_8029314
	movs r1, 0x3
	bl CreateTask
	ldr r1, [r4]
	ldr r2, =0x00003004
	adds r1, r2
	strb r0, [r1]
	ldr r0, =sub_8029338
	bl sub_802A72C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8029274

	thumb_func_start sub_80292D4
sub_80292D4: @ 80292D4
	push {lr}
	bl FreeAllWindowBuffers
	pop {r0}
	bx r0
	thumb_func_end sub_80292D4

	thumb_func_start sub_80292E0
sub_80292E0: @ 80292E0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r5, =gUnknown_082FB40C
	adds r7, r5, 0x4
_080292EC:
	lsls r1, r4, 3
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, r6
	bne _080292FE
	adds r0, r1, r7
	ldr r0, [r0]
	bl sub_802A72C
_080292FE:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _080292EC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80292E0

	thumb_func_start sub_8029314
sub_8029314: @ 8029314
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0802932E
	bl sub_802A75C
	bl _call_via_r0
_0802932E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8029314

	thumb_func_start sub_8029338
sub_8029338: @ 8029338
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _08029430
	lsls r0, 2
	ldr r1, =_08029360
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08029360:
	.4byte _08029374
	.4byte _0802937A
	.4byte _08029394
	.4byte _080293D8
	.4byte _08029404
_08029374:
	bl sub_802A7A8
	b _08029414
_0802937A:
	bl sub_802A8E8
	cmp r0, 0x1
	bne _0802943A
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802941C
	.pool
_08029394:
	ldr r1, =gDodrioBerryBgTilemap1
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gDodrioBerryBgTilemap2Left
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r1, =gDodrioBerryBgTilemap2Right
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	b _08029414
	.pool
_080293D8:
	movs r0, 0
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802941C
	.pool
_08029404:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x14]
	lsrs r0, 3
	bl sub_8028FF8
	bl sub_802902C
_08029414:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
_0802941C:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802943A
	.pool
_08029430:
	movs r2, 0xC0
	lsls r2, 6
	adds r1, r2
	movs r0, 0x1
	str r0, [r1]
_0802943A:
	pop {r0}
	bx r0
	thumb_func_end sub_8029338

	thumb_func_start sub_8029440
sub_8029440: @ 8029440
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r2, =0x00003014
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08029488
	cmp r0, 0x1
	bne _08029460
	b _080295EC
_08029460:
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB4
	bhi _0802946E
	b _0802968E
_0802946E:
	bl sub_8027650
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	cmp r6, r7
	bcc _0802947E
	b _08029666
_0802947E:
	b _08029640
	.pool
_08029488:
	bl sub_8027650
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gUnknown_082FB3C8
	subs r0, r7, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	ldr r2, =0xffffff00
	ldr r0, [sp, 0xC]
	ands r0, r2
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0xE0
	lsls r1, 19
	orrs r0, r1
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x10]
	ands r0, r2
	movs r1, 0x2
	orrs r0, r1
	ldr r1, =0xffff00ff
	ands r0, r1
	movs r1, 0xD0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x98
	lsls r1, 13
	orrs r0, r1
	str r0, [sp, 0x10]
	movs r6, 0
	cmp r6, r7
	bcs _080295B8
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x18]
	mov r10, r4
	ldr r0, =0x00003008
	mov r9, r0
_080294DC:
	movs r1, 0
	mov r8, r1
	adds r0, r6, 0
	bl sub_8027A48
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sub_8027660
	adds r1, r0, 0
	movs r0, 0x1
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	movs r1, 0x38
	subs r1, r0
	lsrs r1, 1
	str r1, [sp, 0x14]
	ldrb r0, [r5]
	lsls r0, 8
	ldr r2, =0xffff00ff
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
	ldrb r2, [r5, 0x1]
	lsls r2, 16
	ldr r0, =0xff00ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	bl AddWindow
	mov r2, r10
	ldr r1, [r2]
	add r1, r9
	adds r1, r6
	strb r0, [r1]
	ldr r0, [r2]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	mov r3, r10
	ldr r0, [r3]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0802955A
	movs r0, 0x2
	mov r8, r0
_0802955A:
	adds r0, r4, 0
	bl sub_8027660
	adds r4, r0, 0
	mov r1, r10
	ldr r0, [r1]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	ldr r3, [sp, 0x14]
	lsls r2, r3, 24
	lsrs r2, 24
	mov r3, r8
	lsls r1, r3, 1
	add r1, r8
	ldr r3, =gUnknown_082FB380
	adds r1, r3
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x1
	bl AddTextPrinterParameterized3
	mov r2, r10
	ldr r0, [r2]
	add r0, r9
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r3, [sp, 0x18]
	ldrh r0, [r3, 0x6]
	adds r0, 0xE
	strh r0, [r3, 0x6]
	add r0, sp, 0xC
	bl sub_8029174
	adds r5, 0x4
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _080294DC
_080295B8:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802962A
	.pool
_080295EC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802968E
	bl sub_8027650
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	cmp r6, r7
	bcs _0802961C
_08029604:
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	adds r0, r6
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _08029604
_0802961C:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r2, =0x00003014
	adds r1, r2
_0802962A:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802968E
	.pool
_08029640:
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003008
	adds r0, r4
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	adds r0, r6
	ldrb r0, [r0]
	bl RemoveWindow
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r7
	bcc _08029640
_08029666:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r3, 0xC0
	lsls r3, 6
	adds r0, r3
	movs r1, 0x1
	str r1, [r0]
_0802968E:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8029440

	thumb_func_start sub_80296A8
sub_80296A8: @ 80296A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x6C
	lsls r0, 24
	movs r1, 0
	mov r8, r1
	movs r6, 0
	lsrs r7, r0, 24
	add r4, sp, 0x2C
	ldr r1, =gUnknown_082FB45C
	adds r0, r4, 0
	movs r2, 0x5
	bl memcpy
	movs r5, 0
	cmp r5, r7
	bcs _080296F8
	add r4, sp, 0x34
_080296D2:
	mov r0, sp
	adds r0, r5
	adds r0, 0x2C
	strb r5, [r0]
	add r0, sp, 0x5C
	adds r1, r5, 0
	bl sub_802793C
	lsls r2, r5, 3
	adds r2, r4, r2
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x60]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _080296D2
_080296F8:
	bl sub_8027748
	cmp r0, 0
	beq _0802972E
_08029700:
	movs r5, 0
	cmp r5, r7
	bcs _08029728
	add r2, sp, 0x34
	add r1, sp, 0x2C
_0802970A:
	lsls r0, r5, 3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r8
	bne _0802971E
	adds r0, r1, r6
	strb r5, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0802971E:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0802970A
_08029728:
	mov r8, r6
	cmp r6, r7
	bcc _08029700
_0802972E:
	movs r5, 0
	ldr r4, =gText_SpacePoints
	cmp r5, r7
	bcs _08029754
	add r1, sp, 0x34
	add r6, sp, 0x38
	subs r3, r7, 0x1
_0802973C:
	lsls r2, r5, 3
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0802974A
	adds r0, r1, r2
	strb r3, [r0]
_0802974A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0802973C
_08029754:
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	movs r1, 0xD8
	subs r1, r0
	str r1, [sp, 0x64]
	movs r5, 0
	cmp r5, r7
	bcs _08029860
	mov r2, sp
	adds r2, 0x34
	str r2, [sp, 0x68]
	ldr r3, =0x00003009
	mov r10, r3
_08029774:
	movs r0, 0
	mov r8, r0
	mov r0, sp
	adds r0, r5
	adds r0, 0x2C
	ldrb r0, [r0]
	adds r4, r0, 0
	lsls r1, r4, 3
	add r0, sp, 0x38
	adds r0, r1
	ldr r0, [r0]
	mov r9, r0
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gUnknown_082FB3DC
	ldr r3, [sp, 0x68]
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r3, =gUnknown_082FB402
	lsls r1, r5, 1
	adds r1, r3
	ldrb r6, [r1]
	str r6, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	mov r3, r8
	str r3, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080297CC
	movs r0, 0x2
	mov r8, r0
_080297CC:
	adds r0, r4, 0
	bl sub_8027660
	adds r3, r0, 0
	ldr r1, =gUnknown_02022CF8
	ldr r0, [r1]
	add r0, r10
	ldrb r0, [r0]
	mov r2, r8
	lsls r1, r2, 1
	add r1, r8
	ldr r2, =gUnknown_082FB380
	adds r1, r2
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0x1C
	adds r3, r6, 0
	bl AddTextPrinterParameterized3
	add r0, sp, 0xC
	mov r1, r9
	movs r2, 0
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	add r1, sp, 0xC
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r3, r0, 0
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r1, [sp, 0x64]
	subs r3, r1, r3
	lsls r3, 24
	lsrs r3, 24
	str r6, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	ldr r2, =gUnknown_02022CF8
	ldr r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	ldr r1, [sp, 0x64]
	lsls r3, r1, 24
	str r6, [sp]
	movs r2, 0xFF
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gText_SpacePoints
	lsrs r3, 24
	bl AddTextPrinterParameterized
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _08029774
_08029860:
	add sp, 0x6C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80296A8

	thumb_func_start sub_802988C
sub_802988C: @ 802988C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	bl sub_8027650
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	ldr r6, =gUnknown_02022CF8
	ldr r1, [r6]
	ldr r2, =0x00003014
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xB
	bls _080298B2
	b _08029FA8
_080298B2:
	lsls r0, 2
	ldr r1, =_080298C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080298C8:
	.4byte _080298F8
	.4byte _08029914
	.4byte _0802996C
	.4byte _08029B6C
	.4byte _08029BB8
	.4byte _08029BFC
	.4byte _08029C60
	.4byte _08029C9C
	.4byte _08029CE0
	.4byte _08029DA0
	.4byte _08029F08
	.4byte _08029F5C
_080298F8:
	bl sub_802784C
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x0000301c
	adds r2, r1, r0
	movs r0, 0
	strh r0, [r2]
	b _08029F8A
	.pool
_08029914:
	ldr r6, =gUnknown_082F7BBC
	adds r0, r6, 0
	bl AddWindow
	ldr r4, =gUnknown_02022CF8
	ldr r1, [r4]
	ldr r2, =0x00003008
	mov r8, r2
	add r1, r8
	strb r0, [r1]
	movs r0, 0x8
	adds r0, r6
	mov r9, r0
	bl AddWindow
	ldr r1, [r4]
	ldr r5, =0x00003009
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, 0
	bl sub_8029174
	mov r0, r9
	bl sub_8029174
	b _08029F88
	.pool
_0802996C:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r5, =0x00003008
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	mov r9, r1
	add r0, r9
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gText_BerryPickingResults
	mov r8, r2
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	mov r1, r8
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r6, 0xFF
	str r6, [sp, 0x4]
	movs r5, 0
	str r5, [sp, 0x8]
	mov r2, r8
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	add r0, r9
	ldrb r0, [r0]
	ldr r2, =gText_10P30P50P50P
	movs r1, 0x11
	str r1, [sp]
	str r6, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x44
	bl AddTextPrinterParameterized
	mov r9, r5
	ldr r0, [sp, 0xC]
	cmp r9, r0
	bcc _080299E2
	b _08029B2A
_080299E2:
	movs r4, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	cmp r9, r0
	bne _080299F2
	movs r4, 0x2
_080299F2:
	mov r0, r9
	bl sub_8027660
	adds r6, r0, 0
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	mov r2, r9
	lsls r5, r2, 1
	ldr r2, =gUnknown_082FB3F8
	adds r1, r5, r2
	ldrb r3, [r1]
	lsls r1, r4, 1
	adds r1, r4
	ldr r2, =gUnknown_082FB380
	adds r1, r2
	str r1, [sp]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	movs r2, 0
	bl AddTextPrinterParameterized3
	movs r7, 0
	mov r8, r5
	mov r0, r9
	adds r0, 0x1
	str r0, [sp, 0x10]
	ldr r1, =gStringVar4
	mov r10, r1
_08029A36:
	mov r0, r9
	adds r1, r7, 0
	bl sub_80276A0
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x0000270f
	bl sub_8027A38
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	bl sub_802778C
	ldr r1, =0x0000270f
	bl sub_8027A38
	lsls r0, 16
	lsrs r6, r0, 16
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	mov r1, r10
	movs r2, 0x1
	negs r2, r2
	bl GetStringWidth
	adds r5, r0, 0
	cmp r6, r4
	bne _08029AE0
	cmp r6, 0
	beq _08029AE0
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	lsls r1, r7, 1
	ldr r2, =gUnknown_082FB3F0
	adds r1, r2
	ldrb r2, [r1]
	subs r2, r5
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gUnknown_082FB3F8
	add r1, r8
	ldrb r3, [r1]
	ldr r1, =gUnknown_082FB383
	str r1, [sp]
	movs r1, 0x1
	negs r1, r1
	str r1, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	movs r1, 0x1
	bl AddTextPrinterParameterized3
	b _08029B10
	.pool
_08029AE0:
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	lsls r1, r7, 1
	ldr r2, =gUnknown_082FB3F0
	adds r1, r2
	ldrb r3, [r1]
	subs r3, r5
	lsls r3, 24
	lsrs r3, 24
	ldr r1, =gUnknown_082FB3F8
	add r1, r8
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	ldr r2, =gStringVar4
	bl AddTextPrinterParameterized
_08029B10:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _08029A36
	ldr r1, [sp, 0x10]
	lsls r0, r1, 24
	lsrs r0, 24
	mov r9, r0
	ldr r2, [sp, 0xC]
	cmp r9, r2
	bcs _08029B2A
	b _080299E2
_08029B2A:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029B6C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029B90
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029B90:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	bl sub_8028C30
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029BB8:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08029BD0
	b _08029FF8
_08029BD0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08029BDE
	b _08029FF8
_08029BDE:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	bl sub_8028C30
	b _08029F88
	.pool
_08029BFC:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r5, =0x00003008
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r6, =gText_AnnouncingRankings
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r6, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x1
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	adds r2, r6, 0
	bl AddTextPrinterParameterized
	b _08029F88
	.pool
_08029C60:
	ldr r0, [sp, 0xC]
	bl sub_80296A8
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029C9C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029CC0
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029CC0:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029CE0:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bhi _08029CF8
	b _08029FF8
_08029CF8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08029D06
	b _08029FF8
_08029D06:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
	bl sub_8027748
	ldr r1, =0x00000bb7
	cmp r0, r1
	bhi _08029D3C
	ldr r0, [r4]
	ldr r2, =0x00003014
	adds r0, r2
	movs r1, 0x7F
	strb r1, [r0]
	b _08029D4C
	.pool
_08029D3C:
	bl StopMapMusic
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08029D4C:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x5
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003009
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r6, =gUnknown_082F7BCC
	adds r0, r6, 0
	bl AddWindow
	ldr r1, [r5]
	adds r1, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, 0
	bl sub_8029174
	b _08029FF8
	.pool
_08029DA0:
	ldr r0, =0x0000016f
	bl PlayNewMapMusic
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r6, =0x00003008
	adds r0, r6
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, =0x00003009
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_AnnouncingPrizes
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x1
	adds r1, r5, 0
	bl GetStringWidth
	adds r1, r0, 0
	movs r0, 0xE0
	subs r0, r1
	lsrs r3, r0, 1
	ldr r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	lsls r3, 24
	lsrs r3, 24
	movs r2, 0x1
	mov r9, r2
	str r2, [sp]
	movs r1, 0xFF
	mov r8, r1
	str r1, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_802762C
	lsls r0, 16
	lsrs r0, 16
	ldr r5, =gStringVar1
	adds r1, r5, 0
	bl CopyItemName
	movs r0, 0
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r7, =gStringVar4
	ldr r1, =gText_FirstPlacePrize
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r4]
	add r0, r10
	ldrb r0, [r0]
	mov r2, r9
	str r2, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r7, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	bl sub_80279C8
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	cmp r4, 0
	beq _08029EC8
	cmp r4, 0x3
	beq _08029EC8
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_802762C
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl CopyItemName
	movs r0, 0
	adds r1, r5, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r4, 0x2
	bne _08029E9C
	ldr r1, =gText_CantHoldAnyMore
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08029EA8
	.pool
_08029E9C:
	cmp r6, 0x1
	bne _08029EA8
	ldr r1, =gText_FilledStorageSpace
	adds r0, r7, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
_08029EA8:
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	ldr r2, =gStringVar4
	movs r1, 0x29
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
_08029EC8:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029F08:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _08029F2C
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029F2C:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =0x0000020b
	movs r1, 0x14
	movs r2, 0xA
	bl FadeOutAndFadeInNewMapMusic
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003014
	adds r1, r0
	b _08029F8E
	.pool
_08029F5C:
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x0000301c
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bls _08029FF8
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08029FF8
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x5
	bl PlaySE
_08029F88:
	ldr r1, [r4]
_08029F8A:
	ldr r2, =0x00003014
	adds r1, r2
_08029F8E:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08029FF8
	.pool
_08029FA8:
	ldr r5, =0x00003008
	adds r0, r1, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, =0x00003009
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_08029FF8:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802988C

	thumb_func_start sub_802A010
sub_802A010: @ 802A010
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r1, =gUnknown_02022CF8
	ldr r2, [r1]
	ldr r3, =0x00003014
	adds r0, r2, r3
	ldrb r6, [r0]
	adds r7, r1, 0
	cmp r6, 0x1
	beq _0802A0CC
	cmp r6, 0x1
	bgt _0802A040
	cmp r6, 0
	beq _0802A04E
	b _0802A2FC
	.pool
_0802A040:
	cmp r6, 0x2
	bne _0802A046
	b _0802A194
_0802A046:
	cmp r6, 0x3
	bne _0802A04C
	b _0802A1D0
_0802A04C:
	b _0802A2FC
_0802A04E:
	ldr r0, =gUnknown_082F7BD4
	mov r9, r0
	bl AddWindow
	ldr r1, [r7]
	ldr r4, =0x00003008
	adds r1, r4
	strb r0, [r1]
	movs r1, 0x8
	add r1, r9
	mov r8, r1
	mov r0, r8
	bl AddWindow
	ldr r1, [r7]
	ldr r2, =0x00003009
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	ldr r3, =0x00003009
	adds r0, r3
	ldrb r0, [r0]
	bl ClearWindowTilemap
	mov r0, r9
	bl sub_8029174
	mov r0, r8
	bl sub_8029074
	ldr r1, [r7]
	ldr r0, =0x00003014
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r1, =0x00003020
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r7]
	ldr r2, =0x00003024
	adds r0, r2
	strb r6, [r0]
	b _0802A35E
	.pool
_0802A0CC:
	ldr r3, =0x00003008
	mov r8, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	ldr r1, =0x00003009
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_WantToPlayAgain
	movs r1, 0x5
	str r1, [sp]
	movs r3, 0xFF
	mov r9, r3
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_Yes
	str r6, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	ldr r2, =gText_SelectorArrow2
	str r6, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r0, [r7]
	add r0, r10
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r7]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A2EA
	.pool
_0802A194:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A1B6
	ldr r0, [r7]
	ldr r3, =0x00003008
	adds r0, r3
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r7]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A1B6:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r7]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A2EA
	.pool
_0802A1D0:
	ldr r3, =0x00003020
	adds r0, r2, r3
	ldrb r5, [r0]
	cmp r5, 0
	bne _0802A1DC
	movs r5, 0x1
_0802A1DC:
	ldr r0, =0x00003009
	mov r8, r0
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_Yes
	movs r1, 0x1
	str r1, [sp]
	movs r3, 0xFF
	mov r10, r3
	str r3, [sp, 0x4]
	movs r1, 0
	mov r9, r1
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_No
	movs r1, 0x11
	str r1, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0x8
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, =gText_SelectorArrow2
	subs r1, r5, 0x1
	lsls r1, 4
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	mov r3, r10
	str r3, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r5, 0x1
	movs r2, 0x1
	ands r2, r1
	cmp r2, 0
	beq _0802A294
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r3, =0x00003020
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, 0
	bne _0802A2E4
	strb r5, [r1]
	b _0802A2E4
	.pool
_0802A294:
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0802A2CC
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r2, =0x00003020
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0802A2C2
	cmp r0, 0x1
	bgt _0802A2BC
	cmp r0, 0
	beq _0802A2C2
	b _0802A35E
	.pool
_0802A2BC:
	cmp r0, 0x2
	beq _0802A2C8
	b _0802A35E
_0802A2C2:
	movs r0, 0x2
	strb r0, [r1]
	b _0802A35E
_0802A2C8:
	strb r5, [r1]
	b _0802A35E
_0802A2CC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0802A35E
	movs r0, 0x5
	bl PlaySE
	ldr r0, [r7]
	ldr r3, =0x00003020
	adds r0, r3
	movs r1, 0x2
	strb r1, [r0]
_0802A2E4:
	ldr r1, [r7]
	ldr r0, =0x00003014
	adds r1, r0
_0802A2EA:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A35E
	.pool
_0802A2FC:
	ldr r0, [r7]
	ldr r2, =0x00003020
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, =0x00003024
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r7]
	ldr r6, =0x00003008
	adds r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	ldr r1, =0x00003009
	adds r0, r1
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r7]
	adds r0, r6
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r7]
	ldr r2, =0x00003009
	adds r0, r2
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r7]
	movs r3, 0xC0
	lsls r3, 6
	adds r0, r3
	movs r1, 0x1
	str r1, [r0]
_0802A35E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A010

	thumb_func_start sub_802A380
sub_802A380: @ 802A380
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r6, =0x00003014
	adds r0, r6
	ldrb r4, [r0]
	cmp r4, 0x1
	beq _0802A3D8
	cmp r4, 0x1
	bgt _0802A3A4
	cmp r4, 0
	beq _0802A3AE
	b _0802A420
	.pool
_0802A3A4:
	cmp r4, 0x2
	beq _0802A3EC
	cmp r4, 0x3
	beq _0802A404
	b _0802A420
_0802A3AE:
	movs r0, 0
	movs r1, 0
	bl DrawDialogueFrame
	ldr r2, =gText_SavingDontTurnOffPower
	str r4, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized2
	b _0802A410
	.pool
_0802A3D8:
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802A414
	.pool
_0802A3EC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A448
	ldr r0, =sub_8153688
	movs r1, 0
	bl CreateTask
	b _0802A410
	.pool
_0802A404:
	ldr r0, =sub_8153688
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _0802A448
_0802A410:
	ldr r1, [r5]
	adds r1, r6
_0802A414:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A448
	.pool
_0802A420:
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_0802A448:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A380

	thumb_func_start sub_802A454
sub_802A454: @ 802A454
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r1, =gUnknown_02022CF8
	ldr r2, [r1]
	ldr r6, =0x00003014
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _0802A4AC
	cmp r0, 0x1
	bgt _0802A47C
	cmp r0, 0
	beq _0802A482
	b _0802A520
	.pool
_0802A47C:
	cmp r0, 0x2
	beq _0802A4F4
	b _0802A520
_0802A482:
	ldr r4, =gUnknown_082F7BEC
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r5]
	ldr r2, =0x00003008
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl sub_8029174
	b _0802A510
	.pool
_0802A4AC:
	ldr r4, =0x00003008
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	ldr r2, =gText_CommunicationStandby3
	movs r1, 0x5
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, =0x00003014
	adds r1, r0
	b _0802A514
	.pool
_0802A4F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A50A
	ldr r0, [r5]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A50A:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
_0802A510:
	ldr r1, [r5]
	adds r1, r6
_0802A514:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A52C
	.pool
_0802A520:
	ldr r0, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
_0802A52C:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_802A454

	thumb_func_start sub_802A534
sub_802A534: @ 802A534
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, =gUnknown_02022CF8
	ldr r0, [r5]
	ldr r4, =0x00003008
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r5]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A534

	thumb_func_start sub_802A588
sub_802A588: @ 802A588
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r7, =0x00003014
	adds r2, r1, r7
	ldrb r5, [r2]
	adds r6, r0, 0
	cmp r5, 0x1
	beq _0802A610
	cmp r5, 0x1
	bgt _0802A5B0
	cmp r5, 0
	beq _0802A5BA
	b _0802A6A4
	.pool
_0802A5B0:
	cmp r5, 0x2
	beq _0802A658
	cmp r5, 0x3
	beq _0802A684
	b _0802A6A4
_0802A5BA:
	ldr r4, =gUnknown_082F7BE4
	adds r0, r4, 0
	bl AddWindow
	ldr r1, [r6]
	ldr r2, =0x00003008
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, 0
	bl sub_8029174
	ldr r1, [r6]
	adds r1, r7
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, =0x0000301c
	adds r1, r0, r2
	movs r2, 0
	strh r5, [r1]
	ldr r1, =0x00003020
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, 0x4
	adds r0, r1
	strb r2, [r0]
	b _0802A6EA
	.pool
_0802A610:
	ldr r4, =0x00003008
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	ldr r2, =gText_SomeoneDroppedOut
	movs r1, 0x5
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r2, =0x00003014
	adds r1, r2
	b _0802A678
	.pool
_0802A658:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0802A66E
	ldr r0, [r6]
	ldr r1, =0x00003008
	adds r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A66E:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r6]
	adds r1, r7
_0802A678:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0802A6EA
	.pool
_0802A684:
	ldr r0, =0x0000301c
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x77
	bls _0802A6EA
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _0802A6EA
	.pool
_0802A6A4:
	ldr r0, [r6]
	ldr r1, =0x00003024
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, =0x00003008
	adds r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r2, 0xC0
	lsls r2, 6
	adds r0, r2
	movs r1, 0x1
	str r1, [r0]
_0802A6EA:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A588

	thumb_func_start unused_0
unused_0: @ 802A6FC
	push {r4,lr}
	ldr r4, =gUnknown_02022CF8
	ldr r0, [r4]
	ldr r1, =0x00003004
	adds r0, r1
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end unused_0

	thumb_func_start nullsub_16
nullsub_16: @ 802A728
	bx lr
	thumb_func_end nullsub_16

	thumb_func_start sub_802A72C
sub_802A72C: @ 802A72C
	push {r4,lr}
	ldr r2, =gUnknown_02022CF8
	ldr r1, [r2]
	ldr r3, =0x00003014
	adds r1, r3
	movs r3, 0
	strb r3, [r1]
	ldr r1, [r2]
	movs r4, 0xC0
	lsls r4, 6
	adds r2, r1, r4
	str r3, [r2]
	ldr r2, =0x00003028
	adds r1, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A72C

	thumb_func_start sub_802A75C
sub_802A75C: @ 802A75C
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003028
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802A75C

	thumb_func_start sub_802A770
sub_802A770: @ 802A770
	push {lr}
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 6
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0802A78C
	movs r0, 0x1
	b _0802A78E
	.pool
_0802A78C:
	movs r0, 0
_0802A78E:
	pop {r1}
	bx r1
	thumb_func_end sub_802A770

	thumb_func_start sub_802A794
sub_802A794: @ 802A794
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r1, =0x00003024
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_802A794

	thumb_func_start sub_802A7A8
sub_802A7A8: @ 802A7A8
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
_0802A7CE:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r3, r5
	subs r4, r5
	cmp r4, r5
	bhi _0802A7CE
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
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_082F7BA4
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
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
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
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
	bl InitStandardTextBoxWindows
	bl sub_8197200
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	ldr r4, =gUnknown_02022CF8
	ldr r1, [r4]
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 6
	adds r1, r0
	movs r0, 0x2
	bl SetBgTilemapBuffer
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_802A7A8

	thumb_func_start sub_802A8E8
sub_802A8E8: @ 802A8E8
	push {lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02022CF8
	ldr r0, [r0]
	ldr r2, =0x00003018
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x5
	bhi _0802A982
	lsls r0, 2
	ldr r1, =_0802A910
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0802A910:
	.4byte _0802A928
	.4byte _0802A938
	.4byte _0802A93E
	.4byte _0802A94C
	.4byte _0802A964
	.4byte _0802A972
_0802A928:
	ldr r0, =gDodrioBerryBgPal1
	movs r1, 0
	movs r2, 0x40
	bl LoadPalette
	b _0802A98A
	.pool
_0802A938:
	bl reset_temp_tile_data_buffers
	b _0802A98A
_0802A93E:
	ldr r1, =gDodrioBerryBgGfx1
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	b _0802A954
	.pool
_0802A94C:
	ldr r1, =gDodrioBerryBgGfx2
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
_0802A954:
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _0802A98A
	.pool
_0802A964:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802A98A
	b _0802A998
_0802A972:
	movs r0, 0x3
	bl stdpal_get
	movs r1, 0xD0
	movs r2, 0x20
	bl LoadPalette
	b _0802A98A
_0802A982:
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _0802A99A
_0802A98A:
	ldr r0, =gUnknown_02022CF8
	ldr r1, [r0]
	ldr r0, =0x00003018
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0802A998:
	movs r0, 0
_0802A99A:
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_802A8E8

	.align 2, 0 @ don't pad with nop
