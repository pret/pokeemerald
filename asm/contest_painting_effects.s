	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start sub_8126058
sub_8126058: @ 8126058
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldrb r1, [r0, 0x1D]
	lsrs r5, r1, 3
	ldrb r1, [r0, 0x1E]
	lsrs r1, 3
	str r1, [sp, 0x8]
	ldr r1, [r0, 0x4]
	str r1, [sp]
	ldr r2, [r0, 0x10]
	str r2, [sp, 0x4]
	ldrh r0, [r0, 0x16]
	cmp r0, 0x2
	bne _08126108
	movs r1, 0
	ldr r0, [sp, 0x8]
	cmp r1, r0
	bcc _08126086
	b _08126194
_08126086:
	movs r0, 0
	adds r2, r1, 0x1
	mov r10, r2
	cmp r0, r5
	bcs _081260FA
	adds r2, r1, 0
	muls r2, r5
	mov r9, r2
	lsls r1, 3
	mov r8, r1
_0812609A:
	movs r4, 0
	lsls r6, r0, 4
	adds r7, r0, 0x1
	add r0, r9
	lsls r0, 6
	ldr r1, [sp, 0x4]
	adds r1, r0
	mov r12, r1
_081260AA:
	lsls r0, r4, 3
	mov r2, r12
	adds r3, r2, r0
	mov r1, r8
	adds r0, r1, r4
	lsls r0, 3
	muls r0, r5
	lsls r0, 1
	ldr r2, [sp]
	adds r0, r2, r0
	adds r2, r0, r6
	ldrh r0, [r2, 0x2]
	lsls r0, 8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2, 0x6]
	lsls r0, 8
	ldrh r1, [r2, 0x4]
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldrh r0, [r2, 0xA]
	lsls r0, 8
	ldrh r1, [r2, 0x8]
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r2, 0xE]
	lsls r0, 8
	ldrh r1, [r2, 0xC]
	orrs r0, r1
	strh r0, [r3, 0x6]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x7
	bls _081260AA
	lsls r0, r7, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _0812609A
_081260FA:
	mov r1, r10
	lsls r0, r1, 16
	lsrs r1, r0, 16
	ldr r2, [sp, 0x8]
	cmp r1, r2
	bcc _08126086
	b _08126194
_08126108:
	movs r1, 0
	ldr r0, [sp, 0x8]
	cmp r1, r0
	bcs _08126194
_08126110:
	movs r0, 0
	adds r2, r1, 0x1
	mov r10, r2
	cmp r0, r5
	bcs _08126188
	adds r2, r1, 0
	muls r2, r5
	mov r9, r2
	lsls r1, 3
	mov r8, r1
_08126124:
	movs r4, 0
	lsls r6, r0, 4
	adds r7, r0, 0x1
	add r0, r9
	lsls r0, 5
	ldr r1, [sp, 0x4]
	adds r1, r0
	mov r12, r1
_08126134:
	lsls r0, r4, 2
	mov r2, r12
	adds r3, r2, r0
	mov r1, r8
	adds r0, r1, r4
	lsls r0, 3
	muls r0, r5
	lsls r0, 1
	ldr r2, [sp]
	adds r0, r2, r0
	adds r2, r0, r6
	ldrh r1, [r2, 0x2]
	lsls r1, 4
	ldrh r0, [r2]
	orrs r1, r0
	ldrh r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrh r0, [r2, 0x6]
	lsls r0, 12
	orrs r1, r0
	strh r1, [r3]
	ldrh r1, [r2, 0xA]
	lsls r1, 4
	ldrh r0, [r2, 0x8]
	orrs r1, r0
	ldrh r0, [r2, 0xC]
	lsls r0, 8
	orrs r1, r0
	ldrh r0, [r2, 0xE]
	lsls r0, 12
	orrs r1, r0
	strh r1, [r3, 0x2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x7
	bls _08126134
	lsls r0, r7, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _08126124
_08126188:
	mov r1, r10
	lsls r0, r1, 16
	lsrs r1, r0, 16
	ldr r2, [sp, 0x8]
	cmp r1, r2
	bcc _08126110
_08126194:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8126058

	thumb_func_start sub_81261A4
sub_81261A4: @ 81261A4
	push {lr}
	ldr r2, =gUnknown_03006188
	ldrb r1, [r0, 0x18]
	lsls r1, 4
	strh r1, [r2]
	ldr r3, =gUnknown_03006184
	ldrh r2, [r2]
	lsls r2, 1
	ldr r1, [r0, 0x8]
	adds r1, r2
	str r1, [r3]
	ldr r2, =gUnknown_03006168
	ldr r1, [r0, 0x4]
	str r1, [r2]
	ldr r2, =gUnknown_03006164
	ldrb r1, [r0, 0x19]
	strb r1, [r2]
	ldr r2, =gUnknown_03006178
	ldrb r1, [r0, 0x1A]
	strb r1, [r2]
	ldr r2, =gUnknown_03006174
	ldrb r1, [r0, 0x1B]
	strb r1, [r2]
	ldr r2, =gUnknown_0300616C
	ldrb r1, [r0, 0x1C]
	strb r1, [r2]
	ldr r2, =gUnknown_03006180
	ldrb r1, [r0, 0x1D]
	strb r1, [r2]
	ldr r2, =gUnknown_03006170
	ldrb r1, [r0, 0x1E]
	strb r1, [r2]
	ldrh r0, [r0, 0x14]
	cmp r0, 0x5
	bhi _0812626A
	lsls r0, 2
	ldr r1, =_0812621C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812621C:
	.4byte _08126234
	.4byte _0812623C
	.4byte _08126244
	.4byte _0812624E
	.4byte _08126258
	.4byte _08126262
_08126234:
	movs r0, 0
	bl sub_81263A4
	b _0812626A
_0812623C:
	movs r0, 0x1
	bl sub_81263A4
	b _0812626A
_08126244:
	bl sub_8126270
	bl sub_8126714
	b _0812626A
_0812624E:
	bl sub_8126370
	bl sub_8126664
	b _0812626A
_08126258:
	bl sub_8126334
	bl sub_81265B4
	b _0812626A
_08126262:
	bl sub_8126318
	bl sub_81264FC
_0812626A:
	pop {r0}
	bx r0
	thumb_func_end sub_81261A4

	thumb_func_start sub_8126270
sub_8126270: @ 8126270
	ldr r2, =gUnknown_03006184
	ldr r1, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r0, [r2]
	ldr r2, =0x000018c6
	adds r1, r2, 0
	strh r1, [r0, 0x2]
	ldr r2, =0x000077bd
	adds r1, r2, 0
	strh r1, [r0, 0x4]
	ldr r2, =0x00002d6b
	adds r1, r2, 0
	strh r1, [r0, 0x6]
	ldr r2, =0x000018dd
	adds r1, r2, 0
	strh r1, [r0, 0x8]
	ldr r2, =0x00001ba6
	adds r1, r2, 0
	strh r1, [r0, 0xA]
	ldr r2, =0x000074c6
	adds r1, r2, 0
	strh r1, [r0, 0xC]
	ldr r2, =0x00001bbd
	adds r1, r2, 0
	strh r1, [r0, 0xE]
	ldr r2, =0x000074dd
	adds r1, r2, 0
	strh r1, [r0, 0x10]
	ldr r2, =0x000077a6
	adds r1, r2, 0
	strh r1, [r0, 0x12]
	ldr r2, =0x0000197d
	adds r1, r2, 0
	strh r1, [r0, 0x14]
	ldr r2, =0x00001bab
	adds r1, r2, 0
	strh r1, [r0, 0x16]
	ldr r2, =0x00007566
	adds r1, r2, 0
	strh r1, [r0, 0x18]
	ldr r2, =0x00002cdd
	adds r1, r2, 0
	strh r1, [r0, 0x1A]
	ldr r2, =0x00002fa6
	adds r1, r2, 0
	strh r1, [r0, 0x1C]
	ldr r2, =0x000074cb
	adds r1, r2, 0
	strh r1, [r0, 0x1E]
	bx lr
	.pool
	thumb_func_end sub_8126270

	thumb_func_start sub_8126318
sub_8126318: @ 8126318
	ldr r2, =gUnknown_03006184
	ldr r0, [r2]
	movs r1, 0
	strh r1, [r0]
	ldr r2, [r2]
	strh r1, [r2, 0x2]
	ldr r1, =0x00007fff
	adds r0, r1, 0
	strh r0, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end sub_8126318

	thumb_func_start sub_8126334
sub_8126334: @ 8126334
	push {r4,r5,lr}
	ldr r1, =gUnknown_03006184
	ldr r0, [r1]
	movs r2, 0
	strh r2, [r0]
	ldr r0, [r1]
	strh r2, [r0, 0x2]
	movs r4, 0
	adds r5, r1, 0
_08126346:
	ldr r0, [r5]
	lsls r2, r4, 1
	adds r2, r0
	adds r0, r4, 0x2
	lsls r3, r0, 1
	lsls r1, r0, 11
	lsls r0, 6
	orrs r1, r0
	orrs r1, r3
	strh r1, [r2, 0x4]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xD
	bls _08126346
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126334

	thumb_func_start sub_8126370
sub_8126370: @ 8126370
	push {r4,lr}
	ldr r2, =gUnknown_03006184
	ldr r1, [r2]
	movs r0, 0
	strh r0, [r1]
	movs r3, 0
	adds r4, r2, 0
_0812637E:
	ldr r0, [r4]
	lsls r2, r3, 1
	adds r2, r0
	lsls r0, r3, 10
	lsls r1, r3, 5
	orrs r0, r1
	orrs r0, r3
	strh r0, [r2, 0x2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1F
	bls _0812637E
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126370

	thumb_func_start sub_81263A4
sub_81263A4: @ 81263A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	movs r1, 0xDF
	mov r9, r1
	cmp r0, 0
	bne _081263BC
	movs r2, 0xFF
	mov r9, r2
_081263BC:
	movs r6, 0
	ldr r3, =gUnknown_03006184
	mov r12, r3
	mov r0, r9
	lsls r4, r0, 1
	ldr r5, =gUnknown_0300616C
	cmp r6, r9
	bcs _081263E0
	movs r2, 0
_081263CE:
	ldr r0, [r3]
	lsls r1, r6, 1
	adds r1, r0
	strh r2, [r1]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r9
	bcc _081263CE
_081263E0:
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4, r0
	ldr r2, =0x00003def
	adds r1, r2, 0
	strh r1, [r0]
	movs r3, 0
	ldrb r5, [r5]
	cmp r3, r5
	bcs _081264E4
_081263F4:
	ldr r2, =gUnknown_03006168
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r3
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	ldr r1, [r2]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r6, 0
	ldr r0, =gUnknown_03006174
	adds r2, r0, 0
	adds r3, 0x1
	mov r10, r3
	ldrb r3, [r2]
	cmp r6, r3
	bcs _081264D6
	ldr r0, =gUnknown_03006188
	mov r8, r0
_08126424:
	ldrh r0, [r4]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08126464
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r4]
	adds r6, 0x1
	adds r7, r4, 0x2
	b _081264CA
	.pool
_08126464:
	adds r0, r4, 0
	bl sub_81267C4
	lsls r0, 16
	lsrs r5, r0, 16
	movs r3, 0x1
	adds r6, 0x1
	adds r7, r4, 0x2
	cmp r3, r9
	bcs _081264C0
	ldr r0, =gUnknown_03006184
	ldr r2, [r0]
	ldrh r1, [r2, 0x2]
	mov r12, r0
	cmp r1, 0
	bne _08126494
	strh r5, [r2, 0x2]
	mov r2, r8
	ldrh r0, [r2]
	adds r0, 0x1
	b _081264BE
	.pool
_08126494:
	mov r2, r12
	ldr r1, [r2]
	lsls r0, r3, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	beq _081264B8
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r9
	bcs _081264C0
	lsls r0, r3, 1
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	bne _08126494
	strh r5, [r1]
_081264B8:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r3
_081264BE:
	strh r0, [r4]
_081264C0:
	ldr r2, =gUnknown_03006174
	cmp r3, r9
	bne _081264CA
	mov r3, r9
	strh r3, [r4]
_081264CA:
	lsls r0, r6, 24
	lsrs r6, r0, 24
	adds r4, r7, 0
	ldrb r0, [r2]
	cmp r6, r0
	bcc _08126424
_081264D6:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r3, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r3, r0
	bcc _081263F4
_081264E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81263A4

	thumb_func_start sub_81264FC
sub_81264FC: @ 81264FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081265A0
	ldr r0, =gUnknown_03006168
	mov r8, r0
_08126510:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r6, 0
	ldr r0, =gUnknown_03006174
	adds r3, r0, 0
	adds r7, r2, 0x1
	ldrb r0, [r3]
	cmp r6, r0
	bcs _08126594
	ldr r5, =gUnknown_03006188
_0812653C:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0812656C
	ldrh r0, [r5]
	strh r0, [r4]
	b _08126586
	.pool
_0812656C:
	adds r0, r4, 0
	bl ConvertToBlackOrWhite
	lsls r0, 16
	cmp r0, 0
	bne _0812657E
	ldrh r0, [r5]
	adds r0, 0x1
	b _08126582
_0812657E:
	ldrh r0, [r5]
	adds r0, 0x2
_08126582:
	strh r0, [r4]
	ldr r3, =gUnknown_03006174
_08126586:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, 0x2
	ldrb r0, [r3]
	cmp r6, r0
	bcc _0812653C
_08126594:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08126510
_081265A0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81264FC

	thumb_func_start sub_81265B4
sub_81265B4: @ 81265B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08126650
	ldr r0, =gUnknown_03006168
	mov r8, r0
_081265CA:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	ldr r0, =gUnknown_03006174
	adds r7, r2, 0x1
	ldrb r0, [r0]
	cmp r5, r0
	bcs _08126644
	ldr r6, =gUnknown_03006188
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_081265FA:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	beq _08126624
	ldrh r0, [r6]
	strh r0, [r4]
	b _08126634
	.pool
_08126624:
	adds r0, r4, 0
	str r2, [sp]
	bl sub_8126908
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r4]
	ldr r2, [sp]
_08126634:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r5, r0
	bcc _081265FA
_08126644:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _081265CA
_08126650:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81265B4

	thumb_func_start sub_8126664
sub_8126664: @ 8126664
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08126700
	ldr r0, =gUnknown_03006168
	mov r8, r0
_0812667A:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	ldr r0, =gUnknown_03006174
	adds r7, r2, 0x1
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081266F4
	ldr r6, =gUnknown_03006188
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_081266AA:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	beq _081266D4
	ldrh r0, [r6]
	strh r0, [r4]
	b _081266E4
	.pool
_081266D4:
	adds r0, r4, 0
	str r2, [sp]
	bl sub_812693C
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r4]
	ldr r2, [sp]
_081266E4:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r5, r0
	bcc _081266AA
_081266F4:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0812667A
_08126700:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126664

	thumb_func_start sub_8126714
sub_8126714: @ 8126714
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081267B0
	ldr r0, =gUnknown_03006168
	mov r8, r0
_0812672A:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	ldr r0, =gUnknown_03006174
	adds r7, r2, 0x1
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081267A4
	ldr r6, =gUnknown_03006188
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_0812675A:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	beq _08126784
	ldrh r0, [r6]
	strh r0, [r4]
	b _08126794
	.pool
_08126784:
	adds r0, r4, 0
	str r2, [sp]
	bl sub_8126838
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r4]
	ldr r2, [sp]
_08126794:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r5, r0
	bcc _0812675A
_081267A4:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0812672A
_081267B0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126714

	thumb_func_start sub_81267C4
sub_81267C4: @ 81267C4
	push {r4,lr}
	ldrh r0, [r0]
	movs r1, 0x1F
	movs r4, 0x1F
	ands r4, r0
	lsls r0, 16
	lsrs r3, r0, 21
	ands r3, r1
	lsrs r2, r0, 26
	ands r2, r1
	movs r1, 0x3
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _081267E8
	movs r0, 0x1C
	ands r0, r4
	adds r4, r0, 0x4
_081267E8:
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _081267F6
	movs r0, 0x1C
	ands r0, r3
	adds r3, r0, 0x4
_081267F6:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08126804
	movs r0, 0x1C
	ands r0, r2
	adds r2, r0, 0x4
_08126804:
	cmp r4, 0x5
	bhi _0812680A
	movs r4, 0x6
_0812680A:
	cmp r4, 0x1E
	bls _08126810
	movs r4, 0x1E
_08126810:
	cmp r3, 0x5
	bhi _08126816
	movs r3, 0x6
_08126816:
	cmp r3, 0x1E
	bls _0812681C
	movs r3, 0x1E
_0812681C:
	cmp r2, 0x5
	bhi _08126822
	movs r2, 0x6
_08126822:
	cmp r2, 0x1E
	bls _08126828
	movs r2, 0x1E
_08126828:
	lsls r0, r2, 10
	lsls r1, r3, 5
	orrs r0, r1
	orrs r4, r0
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81267C4

	thumb_func_start sub_8126838
sub_8126838: @ 8126838
	push {lr}
	ldrh r0, [r0]
	movs r1, 0x1F
	movs r3, 0x1F
	ands r3, r0
	lsls r0, 16
	lsrs r2, r0, 21
	ands r2, r1
	lsrs r0, 26
	ands r0, r1
	cmp r3, 0xB
	bhi _0812685C
	cmp r2, 0xA
	bhi _0812685C
	cmp r0, 0xA
	bhi _0812685C
	movs r0, 0x1
	b _08126902
_0812685C:
	cmp r3, 0x13
	bls _08126880
	cmp r2, 0x13
	bls _08126868
	cmp r0, 0x13
	bhi _0812688C
_08126868:
	cmp r3, 0x13
	bls _08126880
	cmp r2, 0x13
	bls _08126876
	cmp r0, 0xE
	bhi _0812688C
	b _081268C4
_08126876:
	cmp r0, 0x13
	bls _08126880
	cmp r2, 0xE
	bhi _0812688C
	b _081268A0
_08126880:
	cmp r2, 0x13
	bls _08126890
	cmp r0, 0x13
	bls _08126890
	cmp r3, 0xE
	bls _081268E8
_0812688C:
	movs r0, 0x2
	b _08126902
_08126890:
	cmp r3, 0x13
	bls _081268B4
	cmp r2, 0xB
	bls _081268A8
	cmp r0, 0xB
	bls _081268A4
	cmp r2, r0
	bcs _081268C4
_081268A0:
	movs r0, 0x8
	b _08126902
_081268A4:
	movs r0, 0xA
	b _08126902
_081268A8:
	cmp r0, 0xB
	bls _081268B0
	movs r0, 0xD
	b _08126902
_081268B0:
	movs r0, 0x4
	b _08126902
_081268B4:
	cmp r2, 0x13
	bls _081268D8
	cmp r3, 0xB
	bls _081268CC
	cmp r0, 0xB
	bls _081268C8
	cmp r3, r0
	bcc _081268E8
_081268C4:
	movs r0, 0x7
	b _08126902
_081268C8:
	movs r0, 0xB
	b _08126902
_081268CC:
	cmp r0, 0xB
	bls _081268D4
	movs r0, 0xE
	b _08126902
_081268D4:
	movs r0, 0x5
	b _08126902
_081268D8:
	cmp r0, 0x13
	bls _08126900
	cmp r3, 0xB
	bls _081268EC
	cmp r2, 0xB
	bls _081268F4
	cmp r3, r2
	bcs _081268A0
_081268E8:
	movs r0, 0x9
	b _08126902
_081268EC:
	cmp r2, 0xB
	bls _081268F4
	movs r0, 0xC
	b _08126902
_081268F4:
	cmp r0, 0xB
	bls _081268FC
	movs r0, 0xF
	b _08126902
_081268FC:
	movs r0, 0x6
	b _08126902
_08126900:
	movs r0, 0x3
_08126902:
	pop {r1}
	bx r1
	thumb_func_end sub_8126838

	thumb_func_start sub_8126908
sub_8126908: @ 8126908
	push {lr}
	ldrh r1, [r0]
	movs r3, 0x1F
	movs r0, 0x1F
	ands r0, r1
	lsls r1, 16
	lsrs r2, r1, 21
	ands r2, r3
	lsrs r1, 26
	ands r1, r3
	adds r0, r2
	adds r0, r1
	movs r1, 0x3
	bl __divsi3
	movs r1, 0x1E
	ands r0, r1
	lsls r0, 16
	cmp r0, 0
	beq _08126934
	lsrs r0, 17
	b _08126936
_08126934:
	movs r0, 0x1
_08126936:
	pop {r1}
	bx r1
	thumb_func_end sub_8126908

	thumb_func_start sub_812693C
sub_812693C: @ 812693C
	push {lr}
	ldrh r1, [r0]
	movs r3, 0x1F
	movs r0, 0x1F
	ands r0, r1
	lsls r1, 16
	lsrs r2, r1, 21
	ands r2, r3
	lsrs r1, 26
	ands r1, r3
	adds r0, r2
	adds r0, r1
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_812693C

	.align 2, 0 @ Don't pad with nop.
