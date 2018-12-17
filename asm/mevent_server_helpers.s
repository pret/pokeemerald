	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start sub_801D8C0
sub_801D8C0: @ 801D8C0
	push {lr}
	ldr r1, [r0, 0x20]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_801D8C0

	thumb_func_start sub_801D8CC
sub_801D8CC: @ 801D8CC
	push {lr}
	ldr r1, [r0, 0x24]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_801D8CC

	thumb_func_start sub_801D8D8
sub_801D8D8: @ 801D8D8
	movs r3, 0
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x5]
	str r3, [r0]
	strh r3, [r0, 0x12]
	strh r3, [r0, 0x14]
	strh r3, [r0, 0x10]
	strh r3, [r0, 0xA]
	strh r3, [r0, 0xC]
	strh r3, [r0, 0x8]
	str r3, [r0, 0x1C]
	str r3, [r0, 0x18]
	ldr r1, =sub_801DA5C
	str r1, [r0, 0x24]
	ldr r1, =sub_801D988
	str r1, [r0, 0x20]
	bx lr
	.pool
	thumb_func_end sub_801D8D8

	thumb_func_start sub_801D904
sub_801D904: @ 801D904
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	str r0, [r4]
	strh r1, [r4, 0xE]
	strh r0, [r4, 0x10]
	strh r0, [r4, 0x12]
	cmp r3, 0
	beq _0801D91A
	strh r3, [r4, 0x14]
	b _0801D920
_0801D91A:
	movs r0, 0x80
	lsls r0, 3
	strh r0, [r4, 0x14]
_0801D920:
	str r2, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801D904

	thumb_func_start sub_801D928
sub_801D928: @ 801D928
	movs r3, 0
	str r3, [r0]
	strh r1, [r0, 0x6]
	strh r3, [r0, 0x8]
	strh r3, [r0, 0xA]
	strh r3, [r0, 0xC]
	str r2, [r0, 0x18]
	bx lr
	thumb_func_end sub_801D928

	thumb_func_start sub_801D938
sub_801D938: @ 801D938
	push {lr}
	adds r3, r0, 0
	adds r0, r1, 0
	lsls r3, 8
	ldr r1, =gBlockRecvBuffer
	adds r3, r1
	adds r1, r3, 0
	bl memcpy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801D938

	thumb_func_start sub_801D954
sub_801D954: @ 801D954
	push {r4,lr}
	adds r4, r0, 0
	bl GetBlockReceivedStatus
	lsls r0, 24
	lsrs r0, 24
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801D96E
	movs r0, 0
	b _0801D970
_0801D96E:
	movs r0, 0x1
_0801D970:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D954

	thumb_func_start sub_801D978
sub_801D978: @ 801D978
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl ResetBlockReceivedFlag
	pop {r0}
	bx r0
	thumb_func_end sub_801D978

	thumb_func_start sub_801D988
sub_801D988: @ 801D988
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r6, [r5]
	cmp r6, 0x1
	beq _0801D9EC
	cmp r6, 0x1
	bgt _0801D99E
	cmp r6, 0
	beq _0801D9A4
	b _0801DA52
_0801D99E:
	cmp r6, 0x2
	beq _0801DA38
	b _0801DA52
_0801D9A4:
	ldrb r0, [r5, 0x5]
	bl sub_801D954
	cmp r0, 0
	beq _0801DA52
	ldrb r0, [r5, 0x5]
	mov r4, sp
	mov r1, sp
	movs r2, 0x8
	bl sub_801D938
	ldrh r1, [r4, 0x4]
	strh r1, [r5, 0xC]
	ldrh r0, [r4, 0x2]
	strh r0, [r5, 0xA]
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 19
	cmp r1, r0
	bls _0801D9D2
_0801D9CC:
	bl sub_8010198
	b _0801DA52
_0801D9D2:
	mov r1, sp
	ldrh r0, [r5, 0x6]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0801D9CC
	strh r6, [r5, 0x8]
	ldrb r0, [r5, 0x5]
	bl sub_801D978
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
	b _0801DA52
_0801D9EC:
	ldrb r0, [r5, 0x5]
	bl sub_801D954
	cmp r0, 0
	beq _0801DA52
	ldrh r0, [r5, 0x8]
	lsls r1, r0, 6
	subs r1, r0
	lsls r3, r1, 2
	ldrh r0, [r5, 0xC]
	subs r2, r0, r3
	cmp r2, 0xFC
	bhi _0801DA1E
	ldrb r0, [r5, 0x5]
	ldr r1, [r5, 0x18]
	adds r1, r3
	bl sub_801D938
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
	b _0801DA30
_0801DA1E:
	ldrb r0, [r5, 0x5]
	ldr r1, [r5, 0x18]
	adds r1, r3
	movs r2, 0xFC
	bl sub_801D938
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_0801DA30:
	ldrb r0, [r5, 0x5]
	bl sub_801D978
	b _0801DA52
_0801DA38:
	ldr r0, [r5, 0x18]
	ldrh r1, [r5, 0xC]
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r5, 0xA]
	cmp r0, r1
	bne _0801D9CC
	movs r0, 0
	str r0, [r5]
	movs r0, 0x1
	b _0801DA54
_0801DA52:
	movs r0, 0
_0801DA54:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801D988

	thumb_func_start sub_801DA5C
sub_801DA5C: @ 801DA5C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r5, [r4]
	cmp r5, 0x1
	beq _0801DAC8
	cmp r5, 0x1
	bgt _0801DA72
	cmp r5, 0
	beq _0801DA7C
	b _0801DB5E
_0801DA72:
	cmp r5, 0x2
	beq _0801DB1C
	cmp r5, 0x3
	beq _0801DB46
	b _0801DB5E
_0801DA7C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801DB5E
	ldrh r1, [r4, 0xE]
	ldr r2, =0xffff0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, 0x14]
	ldr r0, [sp, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4, 0x1C]
	bl CalcCRC16WithTable
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	lsrs r1, 16
	strh r1, [r4, 0x12]
	strh r5, [r4, 0x10]
	movs r0, 0
	mov r1, sp
	movs r2, 0x8
	bl SendBlock
	b _0801DB3E
	.pool
_0801DAC8:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801DB5E
	ldrb r0, [r4, 0x4]
	bl sub_801D954
	cmp r0, 0
	beq _0801DB5E
	ldrb r0, [r4, 0x4]
	bl sub_801D978
	ldrh r1, [r4, 0x10]
	lsls r0, r1, 6
	subs r0, r1
	lsls r3, r0, 2
	ldrh r0, [r4, 0x14]
	subs r0, r3
	cmp r0, 0xFC
	bhi _0801DB08
	ldr r1, [r4, 0x1C]
	adds r1, r3
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	bl SendBlock
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	b _0801DB3E
_0801DB08:
	ldr r1, [r4, 0x1C]
	adds r1, r3
	movs r0, 0
	movs r2, 0xFC
	bl SendBlock
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	b _0801DB5E
_0801DB1C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _0801DB5E
	ldr r0, [r4, 0x1C]
	ldrh r1, [r4, 0x14]
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r4, 0x12]
	cmp r0, r1
	beq _0801DB3E
	bl sub_8010198
	b _0801DB5E
_0801DB3E:
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	b _0801DB5E
_0801DB46:
	ldrb r0, [r4, 0x4]
	bl sub_801D954
	cmp r0, 0
	beq _0801DB5E
	ldrb r0, [r4, 0x4]
	bl sub_801D978
	movs r0, 0
	str r0, [r4]
	movs r0, 0x1
	b _0801DB60
_0801DB5E:
	movs r0, 0
_0801DB60:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801DA5C

	.align 2, 0 @ don't pad with nop
