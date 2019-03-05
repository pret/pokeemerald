
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81D1ED4
sub_81D1ED4: @ 81D1ED4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r3, r0, 0
	movs r6, 0
	movs r7, 0
_081D1EE6:
	movs r2, 0
	lsls r5, r6, 2
	adds r0, r6, 0x1
	mov r10, r0
	adds r4, r5, 0
_081D1EF0:
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r0, r4, r0
	adds r0, r3, r0
	adds r1, r0, 0
	adds r1, 0x64
	strh r7, [r1]
	adds r0, 0x66
	strh r7, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9
	bls _081D1EF0
	movs r2, 0
	mov r9, r2
	str r5, [sp]
	movs r1, 0x9B
	mov r8, r1
	movs r4, 0x5B
	mov r12, r4
_081D1F1C:
	lsls r0, r2, 2
	adds r0, r2
	adds r1, r6, r0
	adds r1, r3, r1
	mov r4, r9
	strb r4, [r1]
	lsls r0, 2
	ldr r1, [sp]
	adds r0, r1, r0
	adds r0, r3, r0
	mov r4, r8
	strh r4, [r0, 0x14]
	mov r1, r12
	strh r1, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3
	bls _081D1F1C
	adds r1, r3, r5
	movs r2, 0x96
	lsls r2, 1
	adds r0, r1, r2
	strh r7, [r0]
	movs r4, 0x97
	lsls r4, 1
	adds r0, r1, r4
	strh r7, [r0]
	mov r1, r10
	lsls r0, r1, 24
	lsrs r6, r0, 24
	cmp r6, 0x4
	bls _081D1EE6
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r3, r2
	movs r1, 0
	strb r1, [r0]
	ldr r4, =0x00000352
	adds r0, r3, r4
	strh r1, [r0]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1ED4

	thumb_func_start sub_81D1F84
sub_81D1F84: @ 81D1F84
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	str r1, [sp]
	mov r9, r2
	movs r7, 0
_081D1F98:
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r4, r1
	ldrh r1, [r0]
	lsls r5, r1, 8
	mov r2, r9
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	adds r7, 0x1
	mov r10, r7
	mov r12, r4
_081D1FBC:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	add r0, r12
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	movs r7, 0x1
	ands r1, r7
	adds r2, r1
	adds r0, 0x64
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D1FBC
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r1, r9
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r0, 0x64
	strh r1, [r0]
	ldr r7, [sp]
	adds r0, r4, r7
	ldrh r1, [r0, 0x2]
	lsls r5, r1, 8
	ldrh r0, [r2, 0x2]
	subs r0, r1
	lsls r0, 8
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	movs r3, 0
	str r4, [sp, 0x4]
	movs r0, 0x1
	mov r12, r0
_081D2012:
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	ldr r1, [sp, 0x4]
	adds r0, r1, r0
	add r0, r8
	asrs r2, r5, 8
	asrs r1, r5, 7
	mov r7, r12
	ands r1, r7
	adds r2, r1
	adds r0, 0x66
	strh r2, [r0]
	adds r5, r6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _081D2012
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4, r0
	add r0, r8
	mov r2, r9
	adds r1, r4, r2
	ldrh r1, [r1, 0x2]
	adds r0, 0x66
	strh r1, [r0]
	mov r7, r10
	lsls r0, r7, 16
	lsrs r7, r0, 16
	cmp r7, 0x4
	bls _081D1F98
	ldr r1, =0x00000352
	add r1, r8
	movs r0, 0
	strh r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D1F84

	thumb_func_start sub_81D2074
sub_81D2074: @ 81D2074
	push {r4,lr}
	adds r1, r0, 0
	ldr r0, =0x00000352
	adds r4, r1, r0
	ldrh r0, [r4]
	cmp r0, 0x9
	bls _081D208C
	movs r0, 0
	b _081D20A6
	.pool
_081D208C:
	adds r0, r1, 0
	bl sub_81D2230
	ldrh r1, [r4]
	adds r1, 0x1
	strh r1, [r4]
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0xA
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_081D20A6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2074

	thumb_func_start sub_81D20AC
sub_81D20AC: @ 81D20AC
	ldr r1, =0x00000355
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81D20AC

	thumb_func_start sub_81D20BC
sub_81D20BC: @ 81D20BC
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, =0x00000355
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _081D20D4
	cmp r0, 0x1
	beq _081D20E2
	b _081D20FA
	.pool
_081D20D4:
	bl ScanlineEffect_Clear
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	b _081D20FC
_081D20E2:
	mov r0, sp
	ldr r1, =gUnknown_08625404
	ldm r1!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	bl ScanlineEffect_SetParams
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
_081D20FA:
	movs r0, 0
_081D20FC:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D20BC

	thumb_func_start sub_81D2108
sub_81D2108: @ 81D2108
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	movs r1, 0xD5
	lsls r1, 2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D21BE
	adds r0, r6, 0
	bl sub_81D24A4
	adds r0, r6, 0
	bl sub_81D2634
	movs r7, 0
	ldr r5, =gScanlineEffectRegBuffers
	mov r12, r5
	movs r0, 0xF0
	lsls r0, 3
	add r0, r12
	mov r9, r0
	movs r1, 0xA0
	lsls r1, 1
	adds r1, r6, r1
	str r1, [sp]
	ldr r5, =0x0000ffff
	mov r8, r5
	movs r0, 0xA1
	lsls r0, 1
	adds r0, r6, r0
	str r0, [sp, 0x4]
	movs r1, 0x92
	lsls r1, 2
	adds r1, r6, r1
	str r1, [sp, 0x8]
	ldr r5, =0x0000024a
	adds r5, r6
	mov r10, r5
_081D215E:
	adds r2, r7, 0
	adds r2, 0x37
	lsls r3, r2, 2
	mov r0, r9
	adds r0, r3, r0
	str r0, [sp, 0xC]
	add r3, r12
	lsls r4, r7, 2
	ldr r1, [sp]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	ldr r5, [sp, 0x4]
	adds r1, r5, r4
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r3]
	mov r1, r8
	ands r0, r1
	ldr r5, [sp, 0xC]
	strh r0, [r5]
	lsls r2, 1
	adds r2, 0x1
	lsls r2, 1
	mov r0, r9
	adds r3, r2, r0
	add r2, r12
	ldr r1, [sp, 0x8]
	adds r0, r1, r4
	ldrh r0, [r0]
	lsls r0, 8
	add r4, r10
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r2]
	mov r5, r8
	ands r0, r5
	strh r0, [r3]
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x41
	bls _081D215E
	movs r0, 0xD5
	lsls r0, 2
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_081D21BE:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2108

	thumb_func_start sub_81D21DC
sub_81D21DC: @ 81D21DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D21E8
	movs r1, 0
_081D21E8:
	movs r0, 0x1
	lsls r0, r1
	movs r5, 0x1F
	bics r5, r0
	movs r0, 0x40
	movs r1, 0xF0
	bl SetGpuReg
	movs r0, 0x42
	movs r1, 0x9B
	bl SetGpuReg
	ldr r4, =0x00003879
	movs r0, 0x44
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x46
	adds r1, r4, 0
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	movs r0, 0x4A
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D21DC

	thumb_func_start sub_81D2230
sub_81D2230: @ 81D2230
	push {r4-r7,lr}
	mov r12, r0
	movs r4, 0
	movs r7, 0x96
	lsls r7, 1
	add r7, r12
	ldr r6, =0x00000352
	add r6, r12
	mov r5, r12
	adds r5, 0x64
_081D2244:
	lsls r2, r4, 2
	adds r3, r7, r2
	ldrh r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	adds r2, r5, r2
	ldr r0, [r2]
	str r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _081D2244
	movs r1, 0xD5
	lsls r1, 2
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2230

	thumb_func_start sub_81D2278
sub_81D2278: @ 81D2278
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	adds r6, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x38]
	ldr r7, [sp, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	str r0, [sp, 0xC]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r3, 0x2]
	cmp r0, r1
	bcs _081D22B2
	adds r2, r0, 0
	mov r10, r2
	ldrh r0, [r3, 0x2]
	ldrh r1, [r5]
	lsls r4, r1, 10
	ldrh r3, [r3]
	str r3, [sp, 0x8]
	b _081D22C6
_081D22B2:
	ldrh r0, [r5, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r1, [r1, 0x2]
	mov r10, r1
	ldr r2, [sp, 0x4]
	ldrh r1, [r2]
	lsls r4, r1, 10
	ldrh r3, [r5]
	str r3, [sp, 0x8]
	mov r2, r10
_081D22C6:
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0
	beq _081D22DE
	subs r0, r3, r1
	lsls r0, 10
	mov r1, r8
	bl __divsi3
	str r0, [sp, 0xC]
_081D22DE:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r7, 0
	bne _081D2328
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r7, r8
	bcs _081D23B6
	movs r7, 0x1
_081D2308:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r1, [sp, 0xC]
	adds r4, r1
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2308
	b _081D23B6
_081D2328:
	ldr r2, [sp, 0xC]
	cmp r2, 0
	ble _081D23C0
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	movs r5, 0
	mov r3, r9
	lsls r3, 1
	mov r12, r3
	ldr r0, [sp, 0x8]
	add r0, r9
	str r0, [sp, 0x10]
	cmp r5, r8
	bcs _081D237A
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D237A
	mov r1, r12
	str r1, [sp, 0x14]
_081D2352:
	ldr r3, [sp, 0x14]
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r3, 0x1
	ands r0, r3
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D237A
	ldr r1, =0x00026bff
	cmp r4, r1
	ble _081D2352
_081D237A:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	cmp r5, r8
	bcs _081D23B6
	mov r3, r12
	movs r7, 0x1
_081D2398:
	adds r2, r3, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r7
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D2398
_081D23B6:
	subs r0, r6, 0x4
	b _081D248C
	.pool
_081D23C0:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	bge _081D2464
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	movs r5, 0
	mov r2, r9
	lsls r2, 1
	mov r12, r2
	ldr r3, [sp, 0x8]
	add r3, r9
	str r3, [sp, 0x10]
	cmp r5, r8
	bcs _081D241E
	adds r3, r2, r6
	asrs r1, r4, 10
	asrs r0, r4, 9
	movs r2, 0x1
	ands r0, r2
	adds r1, r0
	add r1, r9
	strh r1, [r3]
	b _081D2414
_081D23F2:
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r6, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcs _081D241E
	mov r1, r12
	adds r3, r1, r6
	asrs r2, r4, 10
	asrs r0, r4, 9
	movs r1, 0x1
	ands r0, r1
	adds r2, r0
	add r2, r9
	strh r2, [r3]
_081D2414:
	ldr r0, =0x00026bff
	cmp r4, r0
	bgt _081D23F2
	movs r0, 0x9B
	strh r0, [r3]
_081D241E:
	mov r2, r10
	adds r1, r2, r5
	ldr r3, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r3, r2
	strh r1, [r0]
	ldrh r0, [r0]
	subs r0, 0x38
	lsls r0, 2
	adds r7, r0
	cmp r5, r8
	bcs _081D245A
	mov r3, r12
	movs r6, 0x1
_081D243C:
	adds r2, r3, r7
	asrs r1, r4, 10
	asrs r0, r4, 9
	ands r0, r6
	adds r1, r0
	add r1, r9
	strh r1, [r2]
	ldr r0, [sp, 0xC]
	adds r4, r0
	adds r7, 0x4
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r8
	bcc _081D243C
_081D245A:
	subs r0, r7, 0x4
	b _081D248C
	.pool
_081D2464:
	ldr r1, [sp]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r1, r2
	mov r3, r10
	strh r3, [r0]
	mov r0, r10
	subs r0, 0x38
	lsls r0, 2
	adds r6, r0
	adds r7, r0
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r6, 0x2]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1]
	strh r0, [r7]
	movs r0, 0x9B
	strh r0, [r7, 0x2]
	b _081D2494
_081D248C:
	add r0, r12
	mov r2, sp
	ldrh r2, [r2, 0x10]
	strh r2, [r0]
_081D2494:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2278

	thumb_func_start sub_81D24A4
sub_81D24A4: @ 81D24A4
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x99
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bcs _081D24E0
	adds r7, r0, 0
	movs r0, 0xA0
	lsls r0, 1
	adds r1, r4, r0
	movs r3, 0x96
	lsls r3, 1
	adds r2, r4, r3
	subs r0, 0x10
	adds r3, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2500
_081D24E0:
	ldrh r7, [r1]
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x96
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2500:
	movs r1, 0xA0
	lsls r1, 1
	adds r5, r4, r1
	movs r3, 0x98
	lsls r3, 1
	adds r2, r4, r3
	movs r0, 0x9A
	lsls r0, 1
	adds r6, r4, r0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_81D2278
	movs r2, 0
	movs r1, 0x9B
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0x9D
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D253C
	movs r2, 0x1
_081D253C:
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	str r2, [sp]
	movs r1, 0x92
	lsls r1, 2
	adds r0, r4, r1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_81D2278
	movs r2, 0x38
	cmp r2, r7
	bcs _081D257E
	adds r6, r5, 0
	movs r3, 0
	movs r0, 0xA1
	lsls r0, 1
	adds r5, r4, r0
_081D2566:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r7
	bcc _081D2566
_081D257E:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r1, [r0]
	cmp r2, r1
	bhi _081D25B2
	movs r1, 0xA0
	lsls r1, 1
	adds r3, r4, r1
	movs r5, 0x9B
	adds r1, r0, 0
_081D259C:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r0, r3, r0
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldrh r0, [r1]
	cmp r2, r0
	bls _081D259C
_081D25B2:
	movs r2, 0x9B
	lsls r2, 1
	adds r1, r4, r2
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _081D25C8
	adds r0, r1, 0
_081D25C8:
	adds r0, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bhi _081D25F8
	movs r0, 0xA0
	lsls r0, 1
	adds r6, r4, r0
	movs r3, 0
	movs r1, 0xA1
	lsls r1, 1
	adds r5, r4, r1
_081D25E0:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r0, 2
	adds r1, r6, r0
	strh r3, [r1]
	adds r0, r5, r0
	strh r3, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D25E0
_081D25F8:
	movs r2, 0x38
	movs r3, 0xA0
	lsls r3, 1
	adds r5, r4, r3
	movs r0, 0xA1
	lsls r0, 1
	adds r4, r0
	movs r6, 0x9B
_081D2608:
	adds r0, r2, 0
	subs r0, 0x38
	lsls r1, r0, 2
	adds r3, r5, r1
	ldrh r0, [r3]
	cmp r0, 0
	bne _081D2620
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081D2620
	strh r6, [r3]
_081D2620:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x79
	bls _081D2608
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D24A4

	thumb_func_start sub_81D2634
sub_81D2634: @ 81D2634
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x97
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x9F
	lsls r3, 1
	adds r1, r4, r3
	ldrh r0, [r2]
	ldrh r5, [r1]
	cmp r0, r5
	bcs _081D266E
	adds r6, r0, 0
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	subs r3, 0x12
	adds r2, r4, r3
	movs r5, 0x9E
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
	b _081D2690
_081D266E:
	ldrh r6, [r1]
	movs r0, 0x92
	lsls r0, 2
	adds r1, r4, r0
	movs r3, 0x9E
	lsls r3, 1
	adds r2, r4, r3
	movs r5, 0x96
	lsls r5, 1
	adds r3, r4, r5
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_81D2278
_081D2690:
	movs r0, 0x92
	lsls r0, 2
	adds r5, r4, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r2, r4, r1
	movs r0, 0x9C
	lsls r0, 1
	adds r3, r4, r0
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81D2278
	cmp r6, 0x38
	ble _081D26C8
	movs r0, 0
	adds r1, r5, 0
	adds r2, r6, 0
	subs r2, 0x38
_081D26BC:
	strh r0, [r1]
	strh r0, [r1, 0x2]
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _081D26BC
_081D26C8:
	movs r1, 0x97
	lsls r1, 1
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, 0xD4
	lsls r3, 2
	adds r0, r4, r3
	ldrh r5, [r0]
	cmp r2, r5
	bgt _081D26F6
	movs r3, 0x9B
	adds r1, r0, 0
	lsls r0, r2, 2
	movs r5, 0xB5
	lsls r5, 1
	adds r0, r5
	adds r0, r4
_081D26EA:
	strh r3, [r0]
	adds r0, 0x4
	adds r2, 0x1
	ldrh r5, [r1]
	cmp r2, r5
	ble _081D26EA
_081D26F6:
	movs r1, 0x9D
	lsls r1, 1
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r0, 0x1
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _081D270E
	adds r0, r1, 0
_081D270E:
	adds r2, r0, 0
	cmp r2, 0x79
	bgt _081D272C
	movs r1, 0
	lsls r0, r2, 2
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3
	adds r0, r4
_081D2720:
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	adds r2, 0x1
	cmp r2, 0x79
	ble _081D2720
_081D272C:
	movs r3, 0
	movs r5, 0x92
	lsls r5, 2
	adds r1, r4, r5
	movs r2, 0x41
_081D2736:
	ldrh r0, [r1]
	ldrh r4, [r1, 0x2]
	cmp r0, r4
	bcc _081D2742
	strh r3, [r1, 0x2]
	strh r3, [r1]
_081D2742:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _081D2736
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2634

	thumb_func_start sub_81D2754
sub_81D2754: @ 81D2754
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r1, =gUnknown_08625410
	ldrb r0, [r6]
	adds r0, r1
	ldrb r2, [r0]
	adds r6, 0x1
	movs r0, 0x9B
	mov r3, r8
	strh r0, [r3]
	movs r0, 0x5B
	subs r0, r2
	strh r0, [r3, 0x2]
	movs r7, 0x40
	movs r0, 0
	mov r12, r0
	movs r2, 0x1
	mov r9, r2
	ldr r3, =gSineTable
	mov r10, r3
_081D2786:
	adds r0, r7, 0
	adds r0, 0x33
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, r12
	lsls r0, r1, 24
	movs r2, 0xFF
	lsls r2, 24
	adds r0, r2
	lsrs r3, r0, 24
	mov r12, r3
	cmp r0, 0
	bge _081D27A4
	movs r0, 0x4
	mov r12, r0
_081D27A4:
	mov r1, r12
	lsls r0, r1, 24
	asrs r4, r0, 24
	cmp r4, 0x2
	bne _081D27B4
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_081D27B4:
	ldrb r0, [r6]
	ldr r2, =gUnknown_08625410
	adds r0, r2
	ldrb r2, [r0]
	adds r6, 0x1
	lsls r0, r4, 2
	mov r1, r8
	adds r3, r0, r1
	adds r0, r7, 0
	adds r0, 0x40
	lsls r0, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r2
	asrs r5, r0, 8
	adds r0, r5, 0
	adds r0, 0x9B
	strh r0, [r3]
	lsls r0, r7, 1
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r1, r2, 0
	muls r1, r0
	asrs r1, 8
	movs r0, 0x5B
	subs r0, r1
	strh r0, [r3, 0x2]
	cmp r4, 0x2
	bgt _081D2800
	cmp r2, 0x20
	bne _081D27FA
	cmp r4, 0x2
	beq _081D2800
_081D27FA:
	adds r0, r5, 0
	adds r0, 0x9C
	strh r0, [r3]
_081D2800:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0x4
	bls _081D2786
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D2754

	thumb_func_start InitMoveRelearnerWindows
InitMoveRelearnerWindows: @ 81D2824
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gMoveRelearnerWindowTemplates
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081D284A:
	adds r0, r4, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081D284A
	cmp r5, 0
	bne _081D287C
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	b _081D288E
	.pool
_081D287C:
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
_081D288E:
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x3
	bl PutWindowTilemap
	movs r0, 0x2
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x3
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	bl nullsub_79
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end InitMoveRelearnerWindows

	thumb_func_start nullsub_79
nullsub_79: @ 81D28C4
	bx lr
	thumb_func_end nullsub_79

	thumb_func_start LoadMoveRelearnerMovesList
LoadMoveRelearnerMovesList: @ 81D28C8
	push {r4-r7,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gMultiuseListMenuTemplate
	adds r2, r3, 0
	ldr r1, =gMoveRelearnerMovesListTemplate
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	strh r4, [r3, 0xC]
	str r0, [r3]
	cmp r4, 0x5
	bhi _081D28F0
	strh r4, [r3, 0xE]
	b _081D28F4
	.pool
_081D28F0:
	movs r0, 0x6
	strh r0, [r3, 0xE]
_081D28F4:
	ldrb r0, [r3, 0xE]
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end LoadMoveRelearnerMovesList

	thumb_func_start MoveRelearnerLoadBattleMoveDescription
MoveRelearnerLoadBattleMoveDescription: @ 81D28FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	movs r0, 0
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_BattleMoves2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	mov r8, r0
	str r0, [sp, 0x4]
	movs r7, 0
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_PPSlash
	movs r1, 0x29
	mov r10, r1
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r5, =gText_PowerSlash
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	movs r1, 0x19
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_AccuracySlash
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x6A
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	lsls r3, r4, 24
	lsrs r3, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	negs r0, r0
	cmp r9, r0
	bne _081D29C4
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2AB6
	.pool
_081D29C4:
	mov r1, r9
	lsls r0, r1, 1
	add r0, r9
	lsls r0, 2
	ldr r1, =gBattleMoves
	adds r6, r0, r1
	ldrb r1, [r6, 0x2]
	lsls r0, r1, 3
	subs r0, r1
	ldr r1, =gTypeNames
	adds r5, r0, r1
	movs r0, 0x19
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r1, =gText_PPSlash
	movs r0, 0x1
	movs r2, 0
	bl GetStringWidth
	adds r4, r0, 0x4
	ldrb r1, [r6, 0x4]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	lsls r3, r4, 24
	lsrs r3, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0xC
	bl AddTextPrinterParameterized
	ldrb r0, [r6, 0x1]
	cmp r0, 0x1
	bhi _081D2A3C
	ldr r5, =gText_ThreeDashes
	b _081D2A4A
	.pool
_081D2A3C:
	ldrb r1, [r6, 0x1]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A4A:
	movs r0, 0x19
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl AddTextPrinterParameterized
	ldrb r0, [r6, 0x3]
	cmp r0, 0
	bne _081D2A70
	ldr r5, =gText_ThreeDashes
	b _081D2A7E
	.pool
_081D2A70:
	ldrb r1, [r6, 0x3]
	add r0, sp, 0xC
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	add r5, sp, 0xC
_081D2A7E:
	movs r0, 0x29
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r4, 0
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x6A
	bl AddTextPrinterParameterized
	ldr r1, =gMoveDescriptionPointers
	mov r0, r9
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r0, 0
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
_081D2AB6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MoveRelearnerLoadBattleMoveDescription

	thumb_func_start MoveRelearnerMenuLoadContestMoveDescription
MoveRelearnerMenuLoadContestMoveDescription: @ 81D2ACC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r4, r0, 0
	bl MoveRelearnerShowHideHearts
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r5, =gText_ContestMoves2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x80
	bl GetStringCenterAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r7, 0xFF
	str r7, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_Appeal2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x19
	mov r8, r0
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	ldr r5, =gText_Jam2
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x5C
	bl GetStringRightAlignXOffset
	lsls r3, r0, 24
	lsrs r3, 24
	movs r0, 0x29
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	bl AddTextPrinterParameterized
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	bne _081D2B6C
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
	b _081D2BB8
	.pool
_081D2B6C:
	lsls r4, 3
	ldr r0, =gContestMoves
	adds r4, r0
	ldr r1, =gContestMoveTypeTextPointers
	ldrb r0, [r4, 0x1]
	lsls r0, 29
	lsrs r0, 27
	adds r0, r1
	ldr r5, [r0]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r5, 0
	movs r3, 0x4
	bl AddTextPrinterParameterized
	ldr r1, =gContestEffectDescriptionPointers
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r5, [r0]
	movs r0, 0x41
	str r0, [sp]
	str r7, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x7
	adds r2, r5, 0
	movs r3, 0
	bl AddTextPrinterParameterized
	movs r0, 0x1
	movs r1, 0x2
	bl CopyWindowToVram
_081D2BB8:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MoveRelearnerMenuLoadContestMoveDescription

	thumb_func_start MoveRelearnerCursorCallback
MoveRelearnerCursorCallback: @ 81D2BD0
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081D2BE2
	movs r0, 0x5
	bl PlaySE
_081D2BE2:
	adds r0, r4, 0
	bl MoveRelearnerLoadBattleMoveDescription
	adds r0, r4, 0
	bl MoveRelearnerMenuLoadContestMoveDescription
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end MoveRelearnerCursorCallback

	thumb_func_start MoveRelearnerPrintText
MoveRelearnerPrintText: @ 81D2BF4
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r0, 0x3
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, =gTextFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	bl GetPlayerTextSpeedDelay
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r1, 0x1
	adds r2, r4, 0
	bl AddTextPrinterParameterized2
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MoveRelearnerPrintText

	thumb_func_start MoveRelearnerRunTextPrinters
MoveRelearnerRunTextPrinters: @ 81D2C3C
	push {lr}
	bl RunTextPrinters
	movs r0, 0x3
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end MoveRelearnerRunTextPrinters

	thumb_func_start MoveRelearnerCreateYesNoMenu
MoveRelearnerCreateYesNoMenu: @ 81D2C50
	push {lr}
	ldr r0, =gMoveRelearnerYesNoMenuTemplate
	movs r1, 0x1
	movs r2, 0xE
	movs r3, 0
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end MoveRelearnerCreateYesNoMenu

	thumb_func_start sub_81D2C68
sub_81D2C68: @ 81D2C68
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	cmp r0, 0xE
	bne _081D2CA8
	cmp r2, 0x2
	beq _081D2C7E
	cmp r2, 0x7
	bne _081D2C94
_081D2C7E:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	adds r2, r3, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2C94:
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	bl GetMonData
	b _081D2CCA
	.pool
_081D2CA8:
	cmp r2, 0x2
	beq _081D2CB0
	cmp r2, 0x7
	bne _081D2CBE
_081D2CB0:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl GetAndCopyBoxMonDataAt
	b _081D2CCA
_081D2CBE:
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	bl GetBoxMonDataAt
_081D2CCA:
	pop {r1}
	bx r1
	thumb_func_end sub_81D2C68

	thumb_func_start sub_81D2CD0
sub_81D2CD0: @ 81D2CD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	movs r0, 0xFC
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x4
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x8
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x9
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2D
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0
	beq _081D2D20
	ldr r1, =gText_EggNickname
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081D2E70
	.pool
_081D2D20:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_81D2C68
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81D2C68
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081D2D70
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	bl GetMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	b _081D2D92
	.pool
_081D2D70:
	lsls r0, r4, 24
	lsrs r0, 24
	lsls r1, r6, 24
	lsrs r1, 24
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_081D2D92:
	cmp r7, 0x1D
	beq _081D2D9A
	cmp r7, 0x20
	bne _081D2DB0
_081D2D9A:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081D2DB0
	movs r6, 0xFF
_081D2DB0:
	adds r3, r5, 0
	b _081D2DBA
	.pool
_081D2DB8:
	adds r3, 0x1
_081D2DBA:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081D2DB8
	movs r1, 0xFC
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x12
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x3C
	strb r0, [r3]
	adds r3, 0x1
	cmp r6, 0
	beq _081D2DDE
	cmp r6, 0xFE
	beq _081D2E02
	movs r0, 0
	b _081D2E24
_081D2DDE:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB5
	b _081D2E24
_081D2E02:
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x1
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x6
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r3]
	adds r3, 0x1
	movs r0, 0x3
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x7
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xB6
_081D2E24:
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xFC
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x4
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x8
	strb r0, [r3]
	adds r3, 0x1
	movs r4, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0x9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xBA
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0xF9
	strb r0, [r3]
	adds r3, 0x1
	movs r0, 0x5
	strb r0, [r3]
	adds r3, 0x1
	adds r0, r3, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	strb r4, [r3]
	adds r3, 0x1
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081D2E70:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81D2CD0

	thumb_func_start sub_81D2E7C
sub_81D2E7C: @ 81D2E7C
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081D2E94
_081D2E86:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081D2E94:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081D2E86
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081D2EC2
	movs r3, 0
_081D2EAE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081D2EAE
_081D2EC2:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D2E7C

	thumb_func_start sub_81D2ED4
sub_81D2ED4: @ 81D2ED4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D2EFC
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2EFC:
	cmp r2, r0
	beq _081D2F42
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r3, 0
	bl sub_81D2CD0
	movs r0, 0xFC
	strb r0, [r5]
	movs r0, 0x4
	strb r0, [r5, 0x1]
	movs r0, 0x8
	strb r0, [r5, 0x2]
	movs r0, 0
	strb r0, [r5, 0x3]
	movs r0, 0x9
	strb r0, [r5, 0x4]
	cmp r7, 0xE
	bne _081D2F2C
	adds r0, r5, 0x5
	ldr r1, =gText_InParty
	b _081D2F3A
	.pool
_081D2F2C:
	adds r4, r5, 0x5
	lsls r0, r7, 24
	lsrs r0, 24
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
_081D2F3A:
	movs r2, 0x8
	bl sub_81D2E7C
	b _081D2F72
_081D2F42:
	movs r1, 0
	movs r2, 0
_081D2F46:
	adds r0, r6, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081D2F46
	adds r1, r6, r1
	movs r0, 0xFF
	strb r0, [r1]
	movs r1, 0
	movs r2, 0
_081D2F5E:
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081D2F5E
	adds r1, r5, r1
	movs r0, 0xFF
	strb r0, [r1]
_081D2F72:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2ED4

	thumb_func_start sub_81D2F78
sub_81D2F78: @ 81D2F78
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r0, r4, 16
	lsls r5, 24
	cmp r5, 0
	bne _081D2FB0
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D2FB0:
	cmp r2, r0
	beq _081D305C
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x16
	movs r3, 0
	bl sub_81D2C68
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	mov r2, r8
	adds r1, r2, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x2F
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x1
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x21
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x2
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x18
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x3
	adds r1, r4
	strb r0, [r1]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x17
	movs r3, 0
	bl sub_81D2C68
	mov r1, r8
	adds r1, 0x4
	adds r1, r4
	strb r0, [r1]
	mov r4, r10
	add r4, r9
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	cmp r0, 0xFF
	beq _081D3044
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x30
	movs r3, 0
	bl sub_81D2C68
	movs r1, 0x1D
	bl __udivsi3
	b _081D3046
_081D3044:
	movs r0, 0x9
_081D3046:
	strb r0, [r4]
	mov r0, r9
	adds r1, r5, r0
	mov r2, r8
	adds r0, r2, r1
	lsls r1, 2
	adds r1, 0x14
	add r1, r8
	bl sub_81D2754
	b _081D3086
_081D305C:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	adds r1, r5, r0
	movs r6, 0
	lsls r3, r1, 2
	movs r5, 0x9B
	movs r4, 0x5B
_081D306C:
	adds r0, r2, r1
	add r0, r8
	strb r6, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	strh r5, [r0, 0x14]
	strh r4, [r0, 0x16]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081D306C
_081D3086:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D2F78

	thumb_func_start sub_81D3094
sub_81D3094: @ 81D3094
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	mov r9, r1
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 16
	lsrs r0, r1, 16
	lsls r4, 24
	cmp r4, 0
	bne _081D30C4
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
_081D30C4:
	cmp r2, r0
	beq _081D311A
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x41
	movs r3, 0
	bl sub_81D2C68
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_81D2C68
	adds r6, r0, 0
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_81D2C68
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0x1
	str r1, [sp]
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl LoadSpecialPokePic
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GetFrontSpritePalFromSpeciesAndPersonality
	mov r1, r9
	bl LZ77UnCompWram
_081D311A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3094

	thumb_func_start sub_81D312C
sub_81D312C: @ 81D312C
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	adds r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	ble _081D3140
	movs r0, 0
	strh r0, [r1]
_081D3140:
	movs r0, 0
	ldrsh r1, [r1, r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D312C

	thumb_func_start sub_81D3150
sub_81D3150: @ 81D3150
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1]
	subs r0, 0x18
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x50
	negs r2, r2
	cmp r0, r2
	bge _081D3168
	strh r2, [r1]
_081D3168:
	movs r0, 0
	ldrsh r1, [r1, r0]
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r1}
	bx r1
	thumb_func_end sub_81D3150

	thumb_func_start sub_81D3178
sub_81D3178: @ 81D3178
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D312C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D319A
	cmp r0, 0
	beq _081D319C
_081D319A:
	movs r1, 0x1
_081D319C:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D3178

	thumb_func_start sub_81D31A4
sub_81D31A4: @ 81D31A4
	push {r4,r5,lr}
	adds r5, r1, 0
	bl sub_81D2074
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_81D3150
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r4, 0
	bne _081D31C6
	cmp r0, 0
	beq _081D31C8
_081D31C6:
	movs r1, 0x1
_081D31C8:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D31A4

	thumb_func_start sub_81D31D0
sub_81D31D0: @ 81D31D0
	push {r4-r7,lr}
	sub sp, 0x20
	ldr r3, =gUnknown_08625A48
	ldr r4, [r3]
	ldr r5, [r3, 0x4]
	str r4, [sp, 0x18]
	str r5, [sp, 0x1C]
	mov r4, sp
	ldr r3, =gUnknown_08625A50
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r3!, {r5-r7}
	stm r4!, {r5-r7}
	ldr r3, =gUnknown_08625A68
	ldr r4, [r3, 0x4]
	ldr r3, [r3]
	ldr r5, [sp, 0x18]
	ldr r6, [sp, 0x1C]
	str r5, [r0]
	str r6, [r0, 0x4]
	mov r0, sp
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	str r3, [r2]
	str r4, [r2, 0x4]
	add sp, 0x20
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D31D0

	thumb_func_start sub_81D321C
sub_81D321C: @ 81D321C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x50
	adds r5, r0, 0
	mov r12, r1
	mov r8, r2
	mov r1, sp
	ldr r0, =gUnknown_08625A70
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	add r3, sp, 0x20
	adds r1, r3, 0
	ldr r0, =gUnknown_08625A90
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	add r2, sp, 0x38
	adds r1, r2, 0
	ldr r0, =gUnknown_08625AA8
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	movs r4, 0
_081D3258:
	lsls r0, r4, 3
	add r0, sp
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081D3258
	mov r1, r12
	adds r0, r2, 0
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	movs r4, 0
_081D327A:
	lsls r0, r4, 3
	adds r0, r3, r0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	mov r5, r8
	adds r5, 0x8
	mov r8, r5
	subs r5, 0x8
	stm r5!, {r0,r1}
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _081D327A
	add sp, 0x50
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D321C

	thumb_func_start sub_81D32B0
sub_81D32B0: @ 81D32B0
	push {r4,r5,lr}
	ldr r2, =gUnknown_08625AC0
	ldr r4, [r2]
	ldr r5, [r2, 0x4]
	ldr r2, =gUnknown_08625AC8
	ldr r3, [r2, 0x4]
	ldr r2, [r2]
	str r4, [r0]
	str r5, [r0, 0x4]
	str r2, [r1]
	str r3, [r1, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32B0

	thumb_func_start sub_81D32D4
sub_81D32D4: @ 81D32D4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	adds r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3C
	ble _081D32F0
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r0, r1, 0
	bl sub_81D3408
_081D32F0:
	pop {r0}
	bx r0
	thumb_func_end sub_81D32D4

	thumb_func_start sub_81D32F4
sub_81D32F4: @ 81D32F4
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D330C
	movs r0, 0
	strh r0, [r2, 0x30]
	ldr r0, =sub_81D32D4
	str r0, [r2, 0x1C]
_081D330C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D32F4

	thumb_func_start sub_81D3314
sub_81D3314: @ 81D3314
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x36
	ldrsh r0, [r4, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r3, r1, r0
	cmp r3, 0
	beq _081D3360
	ldrh r1, [r3, 0x24]
	ldrh r2, [r3, 0x20]
	adds r1, r2
	ldr r2, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r1, [r3, 0x26]
	ldrh r3, [r3, 0x22]
	adds r1, r3
	movs r3, 0x2E
	ldrsh r0, [r4, r3]
	lsls r0, 2
	adds r2, 0x2
	adds r0, r2
	ldrh r0, [r0]
	adds r0, r1
	b _081D337E
	.pool
_081D3360:
	ldr r1, =gUnknown_08625B2C
	movs r5, 0x2E
	ldrsh r0, [r4, r5]
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x28
	strh r0, [r4, 0x20]
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r1, 0x2
	adds r0, r1
	ldrh r0, [r0]
	adds r0, 0x68
_081D337E:
	strh r0, [r4, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3314

	thumb_func_start sub_81D338C
sub_81D338C: @ 81D338C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	movs r5, 0
_081D339E:
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq _081D33F0
	strh r5, [r0, 0x2E]
	ldr r1, [r4]
	lsls r0, r5, 4
	adds r0, 0x1
	strh r0, [r1, 0x30]
	ldr r0, [r4]
	strh r6, [r0, 0x32]
	ldr r0, [r4]
	strh r5, [r0, 0x34]
	cmp r7, 0
	beq _081D33C4
	cmp r6, 0x9
	beq _081D33D0
_081D33C4:
	ldr r1, [r4]
	ldr r0, =sub_81D3564
	str r0, [r1, 0x1C]
	b _081D33F0
	.pool
_081D33D0:
	ldr r0, [r4]
	bl sub_81D3314
	ldr r0, [r4]
	bl sub_81D35E8
	ldr r2, [r4]
	ldr r0, =sub_81D32F4
	str r0, [r2, 0x1C]
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r3, 0x5
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2]
_081D33F0:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0x9
	bls _081D339E
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D338C

	thumb_func_start sub_81D3408
sub_81D3408: @ 81D3408
	push {r4-r7,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	movs r3, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	bge _081D3454
	ldr r5, =gSprites
	movs r7, 0x1C
	adds r7, r5
	mov r12, r7
	ldr r6, =sub_81D3564
_081D3428:
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r5
	movs r7, 0x2E
	ldrsh r0, [r2, r7]
	lsls r0, 4
	adds r0, 0x1
	strh r0, [r2, 0x30]
	add r1, r12
	str r6, [r1]
	ldrh r0, [r2, 0x38]
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	cmp r3, r0
	blt _081D3428
_081D3454:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3408

	thumb_func_start sub_81D3464
sub_81D3464: @ 81D3464
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	movs r3, 0
_081D346C:
	lsls r0, r1, 2
	adds r0, r2
	str r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _081D346C
	pop {r0}
	bx r0
	thumb_func_end sub_81D3464

	thumb_func_start sub_81D3480
sub_81D3480: @ 81D3480
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	movs r0, 0
	mov r9, r0
	lsrs r7, r2, 24
	movs r5, 0
	adds r0, r7, 0x1
	cmp r9, r0
	bge _081D34FE
_081D34A2:
	ldr r0, =gUnknown_08625B14
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r3, r0, 24
	adds r6, r3, 0
	cmp r3, 0x40
	beq _081D34FE
	lsls r0, r5, 2
	mov r1, r8
	adds r4, r0, r1
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r4]
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	mov r1, r10
	strh r1, [r0, 0x36]
	cmp r5, 0
	beq _081D34F0
	subs r0, r4, 0x4
	ldr r0, [r0]
	strh r3, [r0, 0x38]
	b _081D34F2
	.pool
_081D34F0:
	mov r9, r6
_081D34F2:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r7, 0x1
	cmp r5, r0
	blt _081D34A2
_081D34FE:
	lsls r0, r7, 2
	add r0, r8
	ldr r0, [r0]
	mov r1, r9
	strh r1, [r0, 0x38]
	adds r0, r7, 0
	movs r1, 0x1
	mov r2, r8
	bl sub_81D338C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3480

	thumb_func_start sub_81D3520
sub_81D3520: @ 81D3520
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
_081D3526:
	cmp r5, 0x9
	bhi _081D3544
	lsls r0, r5, 2
	adds r4, r0, r6
	ldr r0, [r4]
	cmp r0, 0
	beq _081D3544
	bl DestroySprite
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	b _081D3526
_081D3544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81D3520

	thumb_func_start sub_81D354C
sub_81D354C: @ 81D354C
	push {lr}
	bl sub_81D3520
	movs r0, 0x68
	bl FreeSpriteTilesByTag
	movs r0, 0x68
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	thumb_func_end sub_81D354C

	thumb_func_start sub_81D3564
sub_81D3564: @ 81D3564
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _081D3592
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _081D35DC
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081D3592:
	adds r0, r4, 0
	bl sub_81D3314
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D35DC
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081D35D8
	cmp r1, 0x9
	bne _081D35D0
	adds r0, r4, 0
	bl sub_81D35E8
	ldr r0, =sub_81D32F4
	b _081D35DA
	.pool
_081D35D0:
	ldr r0, =sub_81D32D4
	b _081D35DA
	.pool
_081D35D8:
	ldr r0, =SpriteCallbackDummy
_081D35DA:
	str r0, [r4, 0x1C]
_081D35DC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D3564

	thumb_func_start sub_81D35E8
sub_81D35E8: @ 81D35E8
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r0, [r6, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	movs r5, 0
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	bge _081D3636
	movs r0, 0x5
	negs r0, r0
	adds r7, r0, 0
_081D3604:
	lsls r4, r1, 4
	adds r4, r1
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0
	bl SeekSpriteAnim
	adds r1, r4, 0
	adds r1, 0x3E
	ldrb r0, [r1]
	ands r0, r7
	strb r0, [r1]
	ldrh r0, [r4, 0x38]
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x32
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r5, r0
	blt _081D3604
_081D3636:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D35E8

	thumb_func_start DrawLevelUpWindowPg1
DrawLevelUpWindowPg1: @ 81D3640
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	ldr r3, [sp, 0x4C]
	ldr r0, [sp, 0x50]
	mov r9, r0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r3, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r2, sp, 0xC
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r1
	strh r0, [r2]
	ldrh r0, [r5, 0x2]
	ldrh r1, [r6, 0x2]
	subs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r6, 0x4]
	subs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r5, 0x8]
	ldrh r1, [r6, 0x8]
	subs r0, r1
	strh r0, [r2, 0x6]
	ldrh r0, [r5, 0xA]
	ldrh r1, [r6, 0xA]
	subs r0, r1
	strh r0, [r2, 0x8]
	ldrh r0, [r5, 0x6]
	ldrh r1, [r6, 0x6]
	subs r0, r1
	strh r0, [r2, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	ldr r3, [sp, 0x28]
	strb r3, [r0, 0x1]
	mov r1, r9
	strb r1, [r0, 0x2]
	movs r7, 0
	mov r10, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	add r6, sp, 0x18
_081D36CA:
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	lsls r0, r7, 1
	mov r4, sp
	adds r4, r0
	adds r4, 0xC
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r1, =gText_Dash
	cmp r0, 0
	blt _081D3704
	ldr r1, =gText_UnkCtrlF904
_081D3704:
	adds r0, r6, 0
	bl StringCopy
	mov r0, r10
	str r0, [sp]
	mov r1, r9
	str r1, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	movs r2, 0x38
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _081D372C
	negs r0, r1
_081D372C:
	movs r4, 0xC
	cmp r0, 0x9
	bgt _081D3734
	movs r4, 0x12
_081D3734:
	cmp r1, 0
	bge _081D373A
	negs r1, r1
_081D373A:
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r2, r4, 0
	adds r2, 0x38
	mov r1, r10
	str r1, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	str r6, [sp, 0x8]
	mov r0, r8
	movs r1, 0x1
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _081D36CA
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawLevelUpWindowPg1

	thumb_func_start DrawLevelUpWindowPg2
DrawLevelUpWindowPg2: @ 81D3784
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	ldr r2, [sp, 0x4C]
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r4, 4
	orrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	str r2, [sp, 0x28]
	bl FillWindowPixelBuffer
	add r1, sp, 0xC
	ldrh r0, [r5]
	strh r0, [r1]
	ldrh r0, [r5, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r5, 0x4]
	strh r0, [r1, 0x4]
	ldrh r0, [r5, 0x8]
	strh r0, [r1, 0x6]
	ldrh r0, [r5, 0xA]
	strh r0, [r1, 0x8]
	ldrh r0, [r5, 0x6]
	strh r0, [r1, 0xA]
	add r0, sp, 0x24
	strb r4, [r0]
	strb r6, [r0, 0x1]
	ldr r2, [sp, 0x28]
	strb r2, [r0, 0x2]
	movs r6, 0
	add r1, sp, 0x18
	mov r9, r1
	mov r7, r8
	mov r10, r0
	movs r2, 0x1
	negs r2, r2
	mov r8, r2
_081D37EE:
	lsls r1, r6, 1
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r4, 0x3
	cmp r0, 0x63
	bgt _081D3808
	movs r4, 0x1
	cmp r0, 0x9
	ble _081D3808
	movs r4, 0x2
_081D3808:
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r0, r9
	movs r2, 0
	adds r3, r4, 0
	bl ConvertIntToDecimalStringN
	movs r0, 0x4
	subs r0, r4
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 17
	lsrs r4, 16
	lsls r5, r6, 4
	subs r5, r6
	lsls r5, 24
	lsrs r5, 24
	mov r0, r10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	ldr r1, =gUnknown_08625B54
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	movs r2, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r4, 0x38
	lsls r4, 24
	lsrs r4, 24
	mov r2, r10
	str r2, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r1, r9
	str r1, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0x1
	adds r2, r4, 0
	adds r3, r5, 0
	bl AddTextPrinterParameterized3
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x5
	bls _081D37EE
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawLevelUpWindowPg2

	thumb_func_start GetMonLevelUpWindowStats
GetMonLevelUpWindowStats: @ 81D388C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0x3A @ MON_DATA_MAX_HP
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x3B @ MON_DATA_ATK
	bl GetMonData
	strh r0, [r5, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C @ MON_DATA_DEF
	bl GetMonData
	strh r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D @ MON_DATA_SPEED
	bl GetMonData
	strh r0, [r5, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E @ MON_DATA_SPATK
	bl GetMonData
	strh r0, [r5, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F @ MON_DATA_SPDEF
	bl GetMonData
	strh r0, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetMonLevelUpWindowStats

    .align 2, 0 @ Don't pad with nop.
