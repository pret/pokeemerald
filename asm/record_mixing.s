	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80E8110
sub_80E8110: @ 80E8110
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp]
	mov r10, r1
	adds r1, r0, 0
	adds r1, 0x38
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, [sp]
	adds r1, 0x7C
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	ldr r0, [sp]
	mov r1, r10
	movs r2, 0x44
	bl memcpy
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0
	str r1, [sp, 0xC]
	movs r2, 0
	str r2, [sp, 0x4]
	mov r8, r2
	movs r7, 0
	ldr r0, =gSaveBlock2Ptr
	mov r9, r0
_080E8150:
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xB2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	adds r0, r7, r0
	movs r1, 0x3
	bl __modsi3
	adds r6, r0, 0x1
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	mov r2, r10
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x38
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080E81B8
	adds r5, r1, 0
	adds r5, 0x34
	adds r0, r5, 0
	bl ReadUnalignedWord
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xA
	bl ReadUnalignedWord
	cmp r4, r0
	beq _080E819A
	movs r2, 0x1
	add r8, r2
	str r6, [sp, 0x4]
_080E819A:
	adds r0, r5, 0
	bl ReadUnalignedWord
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xA
	bl ReadUnalignedWord
	cmp r4, r0
	bne _080E81B8
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	str r2, [sp, 0xC]
	str r6, [sp, 0x8]
_080E81B8:
	adds r7, 0x1
	cmp r7, 0x1
	ble _080E8150
	mov r0, r8
	cmp r0, 0
	bne _080E81D0
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _080E81D0
	mov r8, r1
	ldr r2, [sp, 0x8]
	str r2, [sp, 0x4]
_080E81D0:
	mov r0, r8
	cmp r0, 0x1
	beq _080E81E0
	cmp r0, 0x2
	beq _080E81EC
	b _080E824C
	.pool
_080E81E0:
	ldr r2, [sp, 0x4]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r10
	b _080E820E
_080E81EC:
	bl Random2
	lsls r0, 16
	ldr r1, =0x33330000
	cmp r0, r1
	bls _080E8224
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xB2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r10
	adds r1, 0x44
_080E820E:
	ldr r0, [sp]
	adds r0, 0x44
	movs r2, 0x44
	bl memcpy
	b _080E824C
	.pool
_080E8224:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xB2
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 30
	adds r0, 0x1
	movs r1, 0x3
	bl __modsi3
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	add r1, r10
	adds r1, 0x44
	ldr r0, [sp]
	adds r0, 0x44
	movs r2, 0x44
	bl memcpy
_080E824C:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8110

	thumb_func_start sub_80E8260
sub_80E8260: @ 80E8260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	movs r6, 0
	ldr r0, =gSaveBlock2Ptr
	mov r10, r0
_080E8274:
	movs r7, 0
	lsls r0, r6, 5
	adds r6, 0x1
	mov r9, r6
	mov r1, r8
	adds r4, r0, r1
	adds r0, 0x6
	adds r6, r1, r0
	adds r5, r4, 0
_080E8286:
	mov r2, r10
	ldr r1, [r2]
	adds r1, 0xA
	adds r0, r5, 0
	bl CopyUnalignedWord
	movs r0, 0x2
	strb r0, [r4, 0xE]
	mov r0, r10
	ldr r1, [r0]
	adds r0, r6, 0
	bl StringCopy
	adds r4, 0x10
	adds r6, 0x10
	adds r5, 0x10
	adds r7, 0x1
	cmp r7, 0x1
	ble _080E8286
	mov r6, r9
	cmp r6, 0x8
	ble _080E8274
	ldr r1, =gSaveBlock2Ptr
	mov r10, r1
	ldr r2, =0x00000ee1
	str r2, [sp, 0x4]
	movs r4, 0x99
	lsls r4, 1
	add r4, r8
	movs r0, 0x95
	lsls r0, 1
	add r0, r8
	mov r9, r0
	ldr r1, =0x00000ef1
	str r1, [sp, 0x8]
	movs r6, 0x92
	lsls r6, 1
	add r6, r8
	movs r5, 0x90
	lsls r5, 1
	add r5, r8
	movs r7, 0x1
_080E82DA:
	movs r0, 0x2
	strb r0, [r4, 0x8]
	mov r2, r10
	ldr r1, [r2]
	adds r1, 0xA
	adds r0, r5, 0
	bl CopyUnalignedWord
	mov r0, r10
	ldr r1, [r0]
	ldr r2, [sp, 0x8]
	adds r1, r2
	adds r0, r6, 0
	bl CopyUnalignedWord
	mov r0, r10
	ldr r1, [r0]
	mov r0, r9
	bl StringCopy
	mov r2, r10
	ldr r1, [r2]
	ldr r0, [sp, 0x4]
	adds r1, r0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, [sp, 0x4]
	adds r1, 0x8
	str r1, [sp, 0x4]
	adds r4, 0x1C
	movs r2, 0x1C
	add r9, r2
	ldr r0, [sp, 0x8]
	adds r0, 0x4
	str r0, [sp, 0x8]
	adds r6, 0x1C
	adds r5, 0x1C
	subs r7, 0x1
	cmp r7, 0
	bge _080E82DA
	movs r6, 0
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	mov r4, r8
	movs r1, 0xC4
	adds r1, r4
	mov r9, r1
	movs r2, 0x84
	adds r2, r4
	mov r8, r2
	movs r0, 0x44
	adds r0, r4
	mov r12, r0
	adds r7, r4, 0x4
	movs r1, 0xCF
	lsls r1, 4
	adds r1, r3, r1
	str r1, [sp]
	mov r10, r4
	ldr r2, =0x00000cf4
	adds r5, r3, r2
_080E8356:
	lsls r2, r6, 1
	ldr r1, [sp]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r0, [r5]
	strh r0, [r7, 0x20]
	ldrh r0, [r5, 0x4]
	mov r1, r12
	strh r0, [r1]
	ldr r1, =0x00000d14
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1, 0x20]
	movs r1, 0xDD
	lsls r1, 4
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r1, =0x00000dde
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1, 0x20]
	ldr r1, =0x00000dea
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r9
	strh r0, [r1]
	ldr r1, =0x00000e08
	adds r0, r3, r1
	adds r0, r2
	ldrh r0, [r0]
	mov r1, r9
	strh r0, [r1, 0x20]
	ldr r1, =0x00000e1e
	adds r0, r3, r1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x82
	lsls r0, 1
	add r0, r10
	strh r1, [r0]
	ldr r1, =0x00000cfc
	adds r0, r3, r1
	adds r0, r2
	ldrh r1, [r0]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r4, r2
	strh r1, [r0]
	adds r4, 0x1C
	movs r0, 0x10
	add r9, r0
	add r8, r0
	add r12, r0
	adds r7, 0x10
	ldr r1, [sp]
	adds r1, 0x2
	str r1, [sp]
	add r10, r0
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x1
	ble _080E8356
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8260

	thumb_func_start sub_80E841C
sub_80E841C: @ 80E841C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	adds r6, r1, 0
	adds r6, 0x34
	adds r5, r1, 0
_080E842E:
	adds r0, r7, 0
	adds r0, 0x34
	bl ReadUnalignedWord
	adds r4, r0, 0
	adds r0, r6, 0
	bl ReadUnalignedWord
	cmp r4, r0
	bne _080E844E
	ldrb r0, [r7, 0x2]
	ldrb r1, [r5, 0x2]
	cmp r0, r1
	bne _080E844E
	movs r0, 0x1
	b _080E845E
_080E844E:
	adds r6, 0x44
	adds r5, 0x44
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	ble _080E842E
	movs r0, 0
_080E845E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80E841C

	thumb_func_start sub_80E8468
sub_80E8468: @ 80E8468
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r0, sp
	bl sub_80E7830
	lsls r4, 2
	mov r1, sp
	adds r0, r1, r4
	ldr r0, [r0]
	muls r0, r5
	adds r3, r6, r0
	movs r7, 0
	movs r2, 0
	mov r8, r2
	movs r5, 0
	adds r6, r3, 0
	adds r6, 0x38
	adds r4, r3, 0
_080E8496:
	ldrb r0, [r6]
	cmp r0, 0xFF
	beq _080E84B4
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r1, 0xDC
	adds r0, r4, 0
	str r3, [sp, 0x10]
	bl sub_80E841C
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bne _080E84B4
	adds r7, 0x1
	mov r8, r5
_080E84B4:
	adds r6, 0x44
	adds r4, 0x44
	adds r5, 0x1
	cmp r5, 0x1
	ble _080E8496
	cmp r7, 0x1
	beq _080E84CC
	cmp r7, 0x2
	beq _080E8508
	b _080E8566
	.pool
_080E84CC:
	ldr r4, =gSaveBlock2Ptr
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xB2
	ldrb r1, [r1]
	lsls r1, 27
	lsrs r1, 30
	adds r2, r1, 0x1
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r0, r1
	adds r0, 0xDC
	mov r2, r8
	lsls r1, r2, 4
	add r1, r8
	lsls r1, 2
	adds r1, r3
	movs r2, 0x44
	bl memcpy
	ldr r4, [r4]
	adds r4, 0xB2
	ldrb r5, [r4]
	lsls r0, r5, 27
	lsrs r0, 30
	adds r0, 0x1
	b _080E8550
	.pool
_080E8508:
	movs r5, 0
	adds r6, r3, 0
_080E850C:
	movs r0, 0x1
	eors r0, r5
	ldr r7, =gSaveBlock2Ptr
	ldr r4, [r7]
	adds r1, r4, 0
	adds r1, 0xB2
	ldrb r1, [r1]
	lsls r1, 27
	lsrs r1, 30
	adds r0, r1
	movs r1, 0x3
	bl __modsi3
	adds r2, r0, 0x1
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r4, r0
	adds r4, 0xDC
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x44
	bl memcpy
	adds r6, 0x44
	adds r5, 0x1
	cmp r5, 0x1
	ble _080E850C
	ldr r4, [r7]
	adds r4, 0xB2
	ldrb r5, [r4]
	lsls r0, r5, 27
	lsrs r0, 30
	adds r0, 0x2
_080E8550:
	movs r1, 0x3
	bl __modsi3
	movs r1, 0x3
	ands r0, r1
	lsls r0, 3
	movs r1, 0x19
	negs r1, r1
	ands r1, r5
	orrs r1, r0
	strb r1, [r4]
_080E8566:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8468

	thumb_func_start sub_80E8578
sub_80E8578: @ 80E8578
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x54
	str r0, [sp]
	ldr r0, [sp, 0x74]
	movs r4, 0
	mov r8, r4
	movs r5, 0
	str r5, [sp, 0x4]
	ldr r4, =gUnknown_03001168
	b _080E85A0
	.pool
_080E8598:
	adds r1, r2
	ldr r6, [sp, 0x4]
	adds r6, 0x1
	str r6, [sp, 0x4]
_080E85A0:
	ldr r5, [sp, 0x4]
	cmp r5, r0
	bge _080E85B6
	cmp r5, r3
	beq _080E85B0
	stm r4!, {r1}
	movs r6, 0x1
	add r8, r6
_080E85B0:
	mov r5, r8
	cmp r5, 0x3
	bne _080E8598
_080E85B6:
	movs r6, 0
	str r6, [sp, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x24]
_080E85BE:
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r1, [sp, 0x4]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r2, [sp, 0x4]
	lsls r2, 1
	str r2, [sp, 0x34]
	ldr r3, [sp, 0x4]
	adds r3, r2, r3
	str r3, [sp, 0x10]
	movs r4, 0
	str r4, [sp, 0x44]
	movs r5, 0
	str r5, [sp, 0x48]
_080E85DC:
	movs r6, 0
	mov r8, r6
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, [sp, 0x10]
	lsls r0, r2, 5
	ldr r3, [sp, 0x48]
	adds r0, r3, r0
	adds r3, r0, r1
	lsls r0, r2, 6
	ldr r4, [sp, 0x44]
	adds r0, r4, r0
	ldr r5, [sp]
	adds r2, r0, r5
_080E85F8:
	adds r0, r2, 0
	movs r6, 0x87
	lsls r6, 2
	adds r1, r3, r6
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r1]
	str r1, [r0]
	adds r3, 0x10
	adds r2, 0x10
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x2
	ble _080E85F8
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0x24]
	cmp r8, r3
	bge _080E86DC
	ldr r4, [sp, 0x4]
	lsls r4, 5
	mov r9, r4
	ldr r5, [sp, 0x8]
	lsls r7, r5, 4
	ldr r6, [sp, 0x34]
	ldr r1, [sp, 0x4]
	adds r0, r6, r1
	lsls r0, 6
	str r0, [sp, 0x14]
	ldr r2, [sp]
	adds r0, r2, r0
	ldr r3, [sp, 0x44]
	str r3, [sp, 0x18]
	adds r0, r3
	str r0, [sp, 0x1C]
	ldr r4, [sp, 0x14]
	adds r0, r3, r4
	adds r0, r2
	adds r0, 0x30
	mov r10, r0
_080E864A:
	movs r5, 0
	str r5, [sp, 0xC]
	movs r3, 0
	mov r6, r8
	lsls r6, 2
	str r6, [sp, 0x38]
	ldr r1, [sp, 0x18]
	ldr r2, [sp, 0x14]
	adds r0, r1, r2
	ldr r4, [sp]
	adds r5, r0, r4
	ldr r0, =gUnknown_03001168
	adds r0, r6, r0
	str r0, [sp, 0x50]
_080E8666:
	lsls r0, r3, 4
	ldr r6, [sp, 0x1C]
	adds r0, r6, r0
	str r3, [sp, 0x4C]
	bl ReadUnalignedWord
	adds r4, r0, 0
	ldr r1, [sp, 0x50]
	ldr r0, [r1]
	add r0, r9
	adds r0, r7
	bl ReadUnalignedWord
	ldr r3, [sp, 0x4C]
	cmp r4, r0
	bne _080E86A8
	ldr r2, [sp, 0xC]
	adds r2, 0x1
	str r2, [sp, 0xC]
	ldr r4, [sp, 0x50]
	ldr r0, [r4]
	mov r6, r9
	adds r1, r7, r6
	adds r1, r0, r1
	ldrh r0, [r5, 0x4]
	ldrh r2, [r1, 0x4]
	cmp r0, r2
	bcs _080E86A8
	adds r0, r5, 0
	ldm r1!, {r2,r4,r6}
	stm r0!, {r2,r4,r6}
	ldr r1, [r1]
	str r1, [r0]
_080E86A8:
	adds r5, 0x10
	adds r3, 0x1
	cmp r3, 0x2
	ble _080E8666
	ldr r3, [sp, 0xC]
	cmp r3, 0
	bne _080E86CE
	ldr r0, =gUnknown_03001168
	ldr r4, [sp, 0x38]
	adds r0, r4, r0
	ldr r0, [r0]
	mov r5, r9
	adds r2, r7, r5
	mov r1, r10
	adds r0, r2
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
_080E86CE:
	movs r4, 0x10
	add r10, r4
	movs r5, 0x1
	add r8, r5
	ldr r6, [sp, 0x24]
	cmp r8, r6
	blt _080E864A
_080E86DC:
	ldr r0, [sp, 0x44]
	adds r0, 0x60
	str r0, [sp, 0x44]
	ldr r1, [sp, 0x48]
	adds r1, 0x30
	str r1, [sp, 0x48]
	ldr r2, [sp, 0x8]
	adds r2, 0x1
	str r2, [sp, 0x8]
	cmp r2, 0x1
	bgt _080E86F4
	b _080E85DC
_080E86F4:
	ldr r3, [sp, 0x28]
	str r3, [sp, 0x4]
	cmp r3, 0x8
	bgt _080E86FE
	b _080E85BE
_080E86FE:
	movs r4, 0
	str r4, [sp, 0x8]
_080E8702:
	ldr r5, [sp, 0x8]
	adds r5, 0x1
	str r5, [sp, 0x2C]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	movs r0, 0x54
	ldr r6, [sp, 0x8]
	muls r0, r6
	adds r3, r0, r1
	movs r0, 0xA8
	muls r0, r6
	ldr r1, [sp]
	adds r2, r0, r1
	movs r4, 0x2
	mov r8, r4
_080E8720:
	movs r5, 0xD8
	lsls r5, 3
	adds r0, r2, r5
	ldr r6, =0x0000057c
	adds r1, r3, r6
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r1]
	str r1, [r0]
	adds r3, 0x1C
	adds r2, 0x1C
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, 0
	bge _080E8720
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0x24]
	cmp r8, r3
	blt _080E8752
	b _080E885A
_080E8752:
	ldr r4, [sp, 0x8]
	lsls r1, r4, 3
	movs r0, 0xA8
	adds r5, r4, 0
	muls r5, r0
	str r5, [sp, 0x20]
	str r5, [sp, 0x3C]
	subs r1, r4
	lsls r1, 2
	mov r10, r1
_080E8766:
	movs r6, 0
	str r6, [sp, 0xC]
	mov r0, r8
	lsls r0, 2
	str r0, [sp, 0x38]
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x30]
	ldr r0, =gUnknown_03001168
	ldr r2, [sp, 0x38]
	adds r2, r0
	mov r9, r2
	ldr r3, [sp]
	movs r4, 0xD8
	lsls r4, 3
	adds r0, r3, r4
	ldr r5, [sp, 0x3C]
	adds r7, r5, r0
	str r6, [sp, 0x40]
	movs r3, 0x2
_080E878E:
	ldr r1, [sp, 0x20]
	movs r2, 0xD8
	lsls r2, 3
	adds r0, r1, r2
	ldr r4, [sp]
	adds r0, r4, r0
	ldr r6, [sp, 0x40]
	adds r5, r0, r6
	adds r0, r5, 0
	str r3, [sp, 0x4C]
	bl ReadUnalignedWord
	adds r4, r0, 0
	movs r6, 0x90
	lsls r6, 1
	add r6, r10
	mov r1, r9
	ldr r0, [r1]
	adds r0, r6
	bl ReadUnalignedWord
	ldr r3, [sp, 0x4C]
	cmp r4, r0
	bne _080E8808
	adds r0, r5, 0x4
	bl ReadUnalignedWord
	adds r4, r0, 0
	mov r2, r9
	ldr r0, [r2]
	adds r0, r6
	adds r0, 0x4
	bl ReadUnalignedWord
	ldr r3, [sp, 0x4C]
	cmp r4, r0
	bne _080E8808
	ldr r4, [sp, 0xC]
	adds r4, 0x1
	str r4, [sp, 0xC]
	mov r5, r9
	ldr r0, [r5]
	mov r6, r10
	adds r2, r0, r6
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	ldrh r0, [r7, 0x8]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _080E8808
	adds r0, r7, 0
	movs r4, 0x90
	lsls r4, 1
	adds r1, r2, r4
	ldm r1!, {r2,r5,r6}
	stm r0!, {r2,r5,r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r1, [r1]
	str r1, [r0]
_080E8808:
	adds r7, 0x1C
	ldr r0, [sp, 0x40]
	adds r0, 0x1C
	str r0, [sp, 0x40]
	subs r3, 0x1
	cmp r3, 0
	bge _080E878E
	ldr r1, [sp, 0xC]
	cmp r1, 0
	bne _080E8850
	mov r0, r8
	adds r0, 0x3
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r2, [sp, 0x20]
	adds r1, r2
	ldr r3, [sp]
	adds r1, r3, r1
	ldr r0, =gUnknown_03001168
	ldr r4, [sp, 0x38]
	adds r0, r4, r0
	ldr r0, [r0]
	add r0, r10
	movs r5, 0xD8
	lsls r5, 3
	adds r1, r5
	movs r6, 0x90
	lsls r6, 1
	adds r0, r6
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
_080E8850:
	ldr r3, [sp, 0x30]
	mov r8, r3
	ldr r4, [sp, 0x24]
	cmp r8, r4
	blt _080E8766
_080E885A:
	ldr r5, [sp, 0x2C]
	str r5, [sp, 0x8]
	cmp r5, 0x1
	bgt _080E8864
	b _080E8702
_080E8864:
	add sp, 0x54
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8578

	thumb_func_start sub_80E8880
sub_80E8880: @ 80E8880
	push {r4-r7,lr}
	mov r12, r0
	adds r7, r1, 0
	movs r5, 0
_080E8888:
	movs r2, 0
	movs r4, 0x1
	negs r4, r4
	movs r1, 0
	adds r6, r5, 0x1
	adds r3, r7, 0
_080E8894:
	ldrh r0, [r3, 0x4]
	cmp r0, r2
	ble _080E889E
	adds r4, r1, 0
	adds r2, r0, 0
_080E889E:
	adds r3, 0x10
	adds r1, 0x1
	cmp r1, 0x5
	ble _080E8894
	cmp r4, 0
	blt _080E88C0
	lsls r1, r5, 4
	lsls r2, r4, 4
	adds r2, r7
	add r1, r12
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	strh r0, [r2, 0x4]
_080E88C0:
	adds r5, r6, 0
	cmp r5, 0x2
	ble _080E8888
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8880

	thumb_func_start sub_80E88CC
sub_80E88CC: @ 80E88CC
	push {r4-r7,lr}
	mov r12, r0
	adds r6, r1, 0
	movs r5, 0
_080E88D4:
	movs r3, 0
	movs r4, 0x1
	negs r4, r4
	movs r2, 0
	adds r7, r5, 0x1
	adds r1, r6, 0
_080E88E0:
	ldrh r0, [r1, 0x8]
	cmp r0, r3
	ble _080E88EA
	adds r4, r2, 0
	adds r3, r0, 0
_080E88EA:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x5
	ble _080E88E0
	cmp r4, 0
	blt _080E8918
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	lsls r2, r4, 3
	subs r2, r4
	lsls r2, 2
	adds r2, r6
	add r1, r12
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	strh r0, [r2, 0x8]
_080E8918:
	adds r5, r7, 0
	cmp r5, 0x2
	ble _080E88D4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E88CC

	thumb_func_start sub_80E8924
sub_80E8924: @ 80E8924
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	movs r0, 0
	ldr r1, =gSaveBlock2Ptr
	mov r10, r1
_080E8936:
	lsls r1, r0, 1
	adds r2, r0, 0x1
	mov r8, r2
	adds r1, r0
	lsls r0, r1, 5
	movs r2, 0x87
	lsls r2, 2
	adds r7, r0, r2
	lsls r1, 6
	mov r0, r9
	adds r4, r0, r1
	movs r6, 0
	movs r5, 0x1
_080E8950:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r7
	adds r0, r6
	adds r1, r4, 0
	bl sub_80E8880
	adds r4, 0x60
	adds r6, 0x30
	subs r5, 0x1
	cmp r5, 0
	bge _080E8950
	mov r0, r8
	cmp r0, 0x8
	ble _080E8936
	movs r5, 0
	ldr r4, =gSaveBlock2Ptr
_080E8972:
	movs r0, 0x54
	adds r1, r5, 0
	muls r1, r0
	ldr r2, =0x0000057c
	adds r1, r2
	ldr r0, [r4]
	adds r0, r1
	movs r1, 0xA8
	muls r1, r5
	movs r2, 0xD8
	lsls r2, 3
	adds r1, r2
	add r1, r9
	bl sub_80E88CC
	adds r5, 0x1
	cmp r5, 0x1
	ble _080E8972
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E8924

	thumb_func_start sub_80E89AC
sub_80E89AC: @ 80E89AC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	mov r9, r2
	bl GetLinkPlayerCount
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x81
	lsls r0, 4
	bl AllocZeroed
	adds r5, r0, 0
	str r4, [sp]
	adds r1, r6, 0
	mov r2, r8
	mov r3, r9
	bl sub_80E8578
	adds r0, r5, 0
	bl sub_80E8924
	adds r0, r5, 0
	bl Free
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80E89AC

	thumb_func_start sub_80E89F8
sub_80E89F8: @ 80E89F8
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r5, =gUnknown_02039F9C
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	movs r0, 0xC2
	lsls r0, 6
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0x38
	bl memcpy
	ldr r1, [r4]
	ldr r0, =0x0000310c
	adds r1, r0
	adds r0, r5, 0
	adds r0, 0x38
	movs r2, 0x38
	bl memcpy
	ldr r0, [r4]
	ldr r1, =0x00003030
	adds r0, r1
	adds r1, r5, 0
	bl sub_806FA9C
	ldr r0, =gUnknown_03001148
	ldr r1, [r0]
	adds r0, r6, 0
	movs r2, 0x78
	bl memcpy
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E89F8

	thumb_func_start sub_80E8A54
sub_80E8A54: @ 80E8A54
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r0, 0
	mov r9, r0
	ldr r0, [r5, 0x70]
	cmp r9, r0
	bcs _080E8AAE
	adds r4, r5, 0
	adds r4, 0x2C
	movs r0, 0x24
	adds r0, r5
	mov r8, r0
	adds r7, r5, 0
	adds r7, 0x37
	adds r6, r5, 0
_080E8A78:
	ldrh r0, [r6, 0x20]
	cmp r0, 0
	beq _080E8A9A
	ldrb r1, [r4, 0xB]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	beq _080E8A90
	mov r0, r8
	movs r1, 0xFC
	bl sub_81DB4DC
_080E8A90:
	ldrb r1, [r7]
	lsrs r1, 4
	adds r0, r4, 0
	bl ConvertInternationalString
_080E8A9A:
	adds r4, 0x38
	movs r0, 0x38
	add r8, r0
	adds r7, 0x38
	adds r6, 0x38
	movs r0, 0x1
	add r9, r0
	ldr r0, [r5, 0x70]
	cmp r9, r0
	bcc _080E8A78
_080E8AAE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8A54

	thumb_func_start TaskDummy4
TaskDummy4: @ 80E8ABC
	bx lr
	thumb_func_end TaskDummy4

	thumb_func_start sub_80E8AC0
sub_80E8AC0: @ 80E8AC0
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
_080E8AC6:
	movs r0, 0x2C
	muls r0, r4
	adds r0, 0x34
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080E8ADC
	adds r0, r1, 0
	adds r0, 0x20
	bl StripExtCtrlCodes
_080E8ADC:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080E8AC6
	adds r0, r5, 0
	bl sub_8164F70
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80E8AC0

	.align 2, 0 @ Don't pad with nop.
