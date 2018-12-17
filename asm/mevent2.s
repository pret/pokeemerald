	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text






	thumb_func_start sub_801AFD8
sub_801AFD8: @ 801AFD8
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x0000322c
	adds r1, r0
	ldr r2, =0x050000db
	mov r0, sp
	bl CpuSet
	bl sub_801B180
	bl sub_811F8BC
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801AFD8

	thumb_func_start sub_801B00C
sub_801B00C: @ 801B00C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003230
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801B00C

	thumb_func_start sav1_get_mevent_buffer_1
sav1_get_mevent_buffer_1: @ 801B020
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sav1_get_mevent_buffer_1

	thumb_func_start sav1_get_mevent_buffer_2
sav1_get_mevent_buffer_2: @ 801B034
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sav1_get_mevent_buffer_2

	thumb_func_start sub_801B044
sub_801B044: @ 801B044
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000356c
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801B044

	thumb_func_start sub_801B058
sub_801B058: @ 801B058
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003564
	adds r0, r1
	bx lr
	.pool
	thumb_func_end sub_801B058

	thumb_func_start sub_801B06C
sub_801B06C: @ 801B06C
	push {lr}
	bl sub_801B14C
	pop {r0}
	bx r0
	thumb_func_end sub_801B06C

	thumb_func_start sub_801B078
sub_801B078: @ 801B078
	push {r4-r7,lr}
	adds r7, r0, 0
	bl sub_801B114
	cmp r0, 0
	beq _0801B0C4
	bl sub_801B14C
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x00003230
	adds r0, r5
	movs r6, 0xDE
	lsls r6, 1
	adds r1, r7, 0
	adds r2, r6, 0
	bl memcpy
	ldr r0, [r4]
	adds r0, r5
	adds r1, r6, 0
	bl CalcCRC16WithTable
	ldr r1, [r4]
	ldr r2, =0x0000322c
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	str r0, [r1]
	movs r0, 0x1
	b _0801B0C6
	.pool
_0801B0C4:
	movs r0, 0
_0801B0C6:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801B078

	thumb_func_start sub_801B0CC
sub_801B0CC: @ 801B0CC
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x00003230
	adds r0, r1
	movs r1, 0xDE
	lsls r1, 1
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldr r4, [r4]
	ldr r2, =0x0000322c
	adds r1, r4, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _0801B10C
	ldr r1, =0x00003230
	adds r0, r4, r1
	bl sub_801B114
	cmp r0, 0
	beq _0801B10C
	movs r0, 0x1
	b _0801B10E
	.pool
_0801B10C:
	movs r0, 0
_0801B10E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B0CC

	thumb_func_start sub_801B114
sub_801B114: @ 801B114
	push {lr}
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801B120
	movs r0, 0x1
	b _0801B122
_0801B120:
	movs r0, 0
_0801B122:
	pop {r1}
	bx r1
	thumb_func_end sub_801B114

	thumb_func_start sub_801B128
sub_801B128: @ 801B128
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003230
	adds r0, r1
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0801B144
	movs r0, 0x1
	b _0801B146
	.pool
_0801B144:
	movs r0, 0
_0801B146:
	pop {r1}
	bx r1
	thumb_func_end sub_801B128

	thumb_func_start sub_801B14C
sub_801B14C: @ 801B14C
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0
	str r4, [sp]
	bl sub_801B00C
	adds r1, r0, 0
	ldr r2, =0x0500006f
	mov r0, sp
	bl CpuSet
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000322c
	adds r0, r1
	str r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B14C

	thumb_func_start sub_801B180
sub_801B180: @ 801B180
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801B044
	adds r1, r0, 0
	ldr r2, =0x05000001
	mov r0, sp
	bl CpuSet
	bl sub_801DBC0
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B180

	thumb_func_start sub_801B1A4
sub_801B1A4: @ 801B1A4
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003230
	adds r4, r0, r1
	bl sub_801B0CC
	cmp r0, 0
	bne _0801B1C4
_0801B1B8:
	movs r0, 0
	b _0801B1DC
	.pool
_0801B1C4:
	movs r2, 0
	ldr r3, =0x000001bb
_0801B1C8:
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0801B1B8
	adds r2, 0x1
	cmp r2, r3
	bls _0801B1C8
	movs r0, 0x1
_0801B1DC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801B1A4

	thumb_func_start sub_801B1E8
sub_801B1E8: @ 801B1E8
	push {lr}
	bl sub_801B330
	bl sub_801B368
	bl sub_801B9F8
	bl ClearRamScript
	bl sub_809D4D8
	bl sub_809D570
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000bec
	adds r0, r1
	bl ClearEReaderTrainer
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B1E8

	thumb_func_start sub_801B21C
sub_801B21C: @ 801B21C
	push {r4-r7,lr}
	adds r7, r0, 0
	bl sub_801B2CC
	cmp r0, 0
	beq _0801B274
	bl sub_801B1E8
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r5, =0x000033f0
	adds r0, r5
	movs r6, 0xA6
	lsls r6, 1
	adds r1, r7, 0
	adds r2, r6, 0
	bl memcpy
	ldr r0, [r4]
	adds r0, r5
	adds r1, r6, 0
	bl CalcCRC16WithTable
	ldr r1, [r4]
	ldr r3, =0x000033ec
	adds r2, r1, r3
	lsls r0, 16
	lsrs r0, 16
	str r0, [r2]
	movs r0, 0xD5
	lsls r0, 6
	adds r2, r1, r0
	adds r1, r5
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x6]
	movs r0, 0x1
	b _0801B276
	.pool
_0801B274:
	movs r0, 0
_0801B276:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801B21C

	thumb_func_start sub_801B27C
sub_801B27C: @ 801B27C
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r1, =0x000033ec
	adds r4, r0, r1
	adds r1, 0x4
	adds r0, r1
	movs r1, 0xA6
	lsls r1, 1
	bl CalcCRC16WithTable
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4]
	cmp r1, r0
	bne _0801B2C4
	ldr r0, [r5]
	ldr r1, =0x000033f0
	adds r0, r1
	bl sub_801B2CC
	cmp r0, 0
	beq _0801B2C4
	bl sub_80991F8
	cmp r0, 0
	beq _0801B2C4
	movs r0, 0x1
	b _0801B2C6
	.pool
_0801B2C4:
	movs r0, 0
_0801B2C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801B27C

	thumb_func_start sub_801B2CC
sub_801B2CC: @ 801B2CC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2]
	cmp r0, 0
	beq _0801B302
	ldrb r1, [r2, 0x8]
	lsls r0, r1, 30
	lsrs r0, 30
	cmp r0, 0x2
	bhi _0801B302
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0801B2F0
	cmp r0, 0x40
	beq _0801B2F0
	cmp r0, 0x80
	bne _0801B302
_0801B2F0:
	lsls r0, r1, 26
	lsrs r0, 28
	cmp r0, 0x7
	bhi _0801B302
	ldrb r0, [r2, 0x9]
	cmp r0, 0x7
	bhi _0801B302
	movs r0, 0x1
	b _0801B304
_0801B302:
	movs r0, 0
_0801B304:
	pop {r1}
	bx r1
	thumb_func_end sub_801B2CC

	thumb_func_start sub_801B308
sub_801B308: @ 801B308
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _0801B328
	movs r0, 0x1
	b _0801B32A
	.pool
_0801B328:
	movs r0, 0
_0801B32A:
	pop {r1}
	bx r1
	thumb_func_end sub_801B308

	thumb_func_start sub_801B330
sub_801B330: @ 801B330
	push {r4,r5,lr}
	sub sp, 0x4
	movs r5, 0
	str r5, [sp]
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	ldr r0, =0x000033f0
	adds r1, r0
	ldr r2, =0x05000053
	mov r0, sp
	bl CpuSet
	ldr r0, [r4]
	ldr r1, =0x000033ec
	adds r0, r1
	str r5, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B330

	thumb_func_start sub_801B368
sub_801B368: @ 801B368
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0
	str r4, [sp]
	bl sav1_get_mevent_buffer_2
	adds r1, r0, 0
	ldr r2, =0x05000009
	mov r0, sp
	bl CpuSet
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x0000353c
	adds r0, r1
	str r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B368

	thumb_func_start sub_801B39C
sub_801B39C: @ 801B39C
	push {lr}
	bl sub_801B27C
	cmp r0, 0
	bne _0801B3AA
	movs r0, 0
	b _0801B3B4
_0801B3AA:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrh r0, [r0]
_0801B3B4:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801B39C

	thumb_func_start sub_801B3C0
sub_801B3C0: @ 801B3C0
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2, 0x8]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	bne _0801B3D4
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x8]
_0801B3D4:
	pop {r0}
	bx r0
	thumb_func_end sub_801B3C0

	thumb_func_start sub_801B3D8
sub_801B3D8: @ 801B3D8
	push {lr}
	lsls r0, 16
	ldr r1, =0xfc180000
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x13
	bls _0801B3F0
	movs r0, 0
	b _0801B3F2
	.pool
_0801B3F0:
	movs r0, 0x1
_0801B3F2:
	pop {r1}
	bx r1
	thumb_func_end sub_801B3D8

	thumb_func_start sub_801B3F8
sub_801B3F8: @ 801B3F8
	push {r4,lr}
	bl sub_801B39C
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl sub_801B3D8
	cmp r0, 0
	beq _0801B430
	ldr r1, =gUnknown_082F0DE8
	ldr r2, =0xfffffc18
	adds r0, r4, r2
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0801B430
	movs r0, 0x1
	b _0801B432
	.pool
_0801B430:
	movs r0, 0
_0801B432:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B3F8

	thumb_func_start sub_801B438
sub_801B438: @ 801B438
	push {lr}
	movs r3, 0
	cmp r3, r1
	bge _0801B45A
	adds r2, r0, 0
	adds r2, 0x8
_0801B444:
	ldrh r0, [r2, 0xE]
	cmp r0, 0
	beq _0801B452
	ldrh r0, [r2]
	cmp r0, 0
	beq _0801B452
	adds r3, 0x1
_0801B452:
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _0801B444
_0801B45A:
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end sub_801B438

	thumb_func_start sub_801B460
sub_801B460: @ 801B460
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r2
	bge _0801B49A
	ldrh r6, [r4, 0x2]
	movs r0, 0x16
	adds r0, r5
	mov r12, r0
_0801B474:
	lsls r3, r1, 1
	mov r7, r12
	ldrh r0, [r7]
	cmp r0, r6
	beq _0801B48C
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r3
	ldrh r0, [r0]
	ldrh r3, [r4]
	cmp r0, r3
	bne _0801B490
_0801B48C:
	movs r0, 0x1
	b _0801B49C
_0801B490:
	movs r7, 0x2
	add r12, r7
	adds r1, 0x1
	cmp r1, r2
	blt _0801B474
_0801B49A:
	movs r0, 0
_0801B49C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801B460

	thumb_func_start sub_801B4A4
sub_801B4A4: @ 801B4A4
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _0801B4C4
	ldrh r1, [r1]
	cmp r1, 0
	beq _0801B4C4
	ldr r0, =0x0000019b
	cmp r1, r0
	bhi _0801B4C4
	movs r0, 0x1
	b _0801B4C6
	.pool
_0801B4C4:
	movs r0, 0
_0801B4C6:
	pop {r1}
	bx r1
	thumb_func_end sub_801B4A4

	thumb_func_start sub_801B4CC
sub_801B4CC: @ 801B4CC
	push {lr}
	bl sub_801B27C
	cmp r0, 0
	beq _0801B500
	ldr r0, =gSaveBlock1Ptr
	ldr r3, [r0]
	ldr r0, =0x000033f0
	adds r2, r3, r0
	ldrb r1, [r2, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801B500
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r3, r1
	ldrb r1, [r2, 0x9]
	bl sub_801B438
	b _0801B502
	.pool
_0801B500:
	movs r0, 0
_0801B502:
	pop {r1}
	bx r1
	thumb_func_end sub_801B4CC

	thumb_func_start sub_801B508
sub_801B508: @ 801B508
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gSaveBlock1Ptr
	ldr r0, [r6]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r4, [r0, 0x9]
	adds r0, r5, 0
	bl sub_801B4A4
	cmp r0, 0
	beq _0801B572
	ldr r0, [r6]
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r1
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_801B460
	cmp r0, 0
	beq _0801B54C
	b _0801B572
	.pool
_0801B540:
	ldrh r0, [r5, 0x2]
	strh r0, [r1]
	ldrh r0, [r5]
	strh r0, [r2]
	movs r0, 0x1
	b _0801B574
_0801B54C:
	movs r3, 0
	cmp r3, r4
	bge _0801B572
	ldr r0, [r6]
	ldr r6, =0x00003548
	adds r2, r0, r6
	adds r6, 0xE
	adds r1, r0, r6
_0801B55C:
	ldrh r0, [r2, 0xE]
	cmp r0, 0
	bne _0801B568
	ldrh r0, [r2]
	cmp r0, 0
	beq _0801B540
_0801B568:
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, r4
	blt _0801B55C
_0801B572:
	movs r0, 0
_0801B574:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_801B508

	thumb_func_start sub_801B580
sub_801B580: @ 801B580
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [sp]
	ldr r2, =0x05000019
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	ldr r0, =0x00000101
	str r0, [r5]
	movs r0, 0x1
	strh r0, [r5, 0x4]
	str r0, [r5, 0x8]
	cmp r4, 0
	beq _0801B5C0
	movs r0, 0x5
	strh r0, [r5, 0xC]
	ldr r0, =0x00000201
	b _0801B5C8
	.pool
_0801B5C0:
	movs r0, 0x4
	strh r0, [r5, 0xC]
	movs r0, 0x80
	lsls r0, 2
_0801B5C8:
	str r0, [r5, 0x10]
	bl sub_801B27C
	cmp r0, 0
	beq _0801B5FC
	bl sav1_get_mevent_buffer_1
	ldrh r0, [r0]
	strh r0, [r5, 0x14]
	bl sav1_get_mevent_buffer_2
	adds r1, r5, 0
	adds r1, 0x20
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sav1_get_mevent_buffer_1
	ldrb r1, [r0, 0x9]
	adds r0, r5, 0
	adds r0, 0x44
	strb r1, [r0]
	b _0801B5FE
_0801B5FC:
	strh r0, [r5, 0x14]
_0801B5FE:
	adds r4, r5, 0
	adds r4, 0x4C
	ldr r0, =gSaveBlock2Ptr
	mov r8, r0
	adds r6, r5, 0
	adds r6, 0x45
	adds r7, r5, 0
	adds r7, 0x50
	movs r1, 0x5C
	adds r1, r5
	mov r9, r1
	movs r2, 0x60
	adds r2, r5
	mov r10, r2
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003564
	adds r2, r0, r3
	adds r1, r5, 0
	adds r1, 0x16
	movs r3, 0x3
_0801B628:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0801B628
	mov r0, r8
	ldr r1, [r0]
	adds r1, 0xA
	adds r0, r4, 0
	bl CopyTrainerId
	mov r2, r8
	ldr r1, [r2]
	adds r0, r6, 0
	bl StringCopy
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00002bb0
	adds r2, r0, r3
	adds r1, r7, 0
	movs r3, 0x5
_0801B658:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _0801B658
	ldr r1, =RomHeaderGameCode
	mov r0, r9
	movs r2, 0x4
	bl memcpy
	ldr r0, =RomHeaderSoftwareVersion
	ldrb r0, [r0]
	mov r4, r10
	strb r0, [r4]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B580

	thumb_func_start sub_801B6A0
sub_801B6A0: @ 801B6A0
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldr r1, [r2]
	ldr r0, =0x00000101
	cmp r1, r0
	bne _0801B6DC
	ldrh r1, [r2, 0x4]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0801B6DC
	ldr r0, [r2, 0x8]
	ands r0, r3
	cmp r0, 0
	beq _0801B6DC
	cmp r4, 0
	bne _0801B6E4
	ldrh r1, [r2, 0xC]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0801B6DC
	ldr r0, [r2, 0x10]
	movs r1, 0xE0
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	bne _0801B6E4
_0801B6DC:
	movs r0, 0
	b _0801B6E6
	.pool
_0801B6E4:
	movs r0, 0x1
_0801B6E6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B6A0

	thumb_func_start sub_801B6EC
sub_801B6EC: @ 801B6EC
	push {lr}
	ldrh r1, [r1, 0x14]
	cmp r1, 0
	bne _0801B6F8
	movs r0, 0
	b _0801B704
_0801B6F8:
	ldrh r0, [r0]
	cmp r0, r1
	beq _0801B702
	movs r0, 0x2
	b _0801B704
_0801B702:
	movs r0, 0x1
_0801B704:
	pop {r1}
	bx r1
	thumb_func_end sub_801B6EC

	thumb_func_start sub_801B708
sub_801B708: @ 801B708
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r4, 0
	adds r5, 0x20
	adds r4, 0x44
	ldrb r1, [r4]
	adds r0, r5, 0
	bl sub_801B438
	ldrb r2, [r4]
	subs r4, r2, r0
	cmp r4, 0
	bne _0801B728
	movs r0, 0x1
	b _0801B742
_0801B728:
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_801B460
	cmp r0, 0
	beq _0801B738
	movs r0, 0x3
	b _0801B742
_0801B738:
	cmp r4, 0x1
	beq _0801B740
	movs r0, 0x2
	b _0801B742
_0801B740:
	movs r0, 0x4
_0801B742:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801B708

	thumb_func_start sub_801B748
sub_801B748: @ 801B748
	push {r4,lr}
	movs r3, 0
	adds r2, r0, 0
	adds r2, 0x16
_0801B750:
	ldrh r0, [r2]
	ldrh r4, [r1]
	cmp r0, r4
	beq _0801B75C
	movs r0, 0
	b _0801B768
_0801B75C:
	adds r1, 0x2
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _0801B750
	movs r0, 0x1
_0801B768:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801B748

	thumb_func_start sub_801B770
sub_801B770: @ 801B770
	push {lr}
	adds r2, r0, 0
	adds r2, 0x20
	adds r0, 0x44
	ldrb r1, [r0]
	adds r0, r2, 0
	bl sub_801B438
	pop {r1}
	bx r1
	thumb_func_end sub_801B770

	thumb_func_start sub_801B784
sub_801B784: @ 801B784
	push {lr}
	adds r2, r0, 0
	cmp r1, 0x4
	bhi _0801B7D0
	lsls r0, r1, 2
	ldr r1, =_0801B79C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801B79C:
	.4byte _0801B7B0
	.4byte _0801B7B4
	.4byte _0801B7B8
	.4byte _0801B7BC
	.4byte _0801B7C8
_0801B7B0:
	ldrh r0, [r2, 0x20]
	b _0801B7D2
_0801B7B4:
	ldrh r0, [r2, 0x22]
	b _0801B7D2
_0801B7B8:
	ldrh r0, [r2, 0x24]
	b _0801B7D2
_0801B7BC:
	adds r0, r2, 0
	bl sub_801B770
	lsls r0, 16
	lsrs r0, 16
	b _0801B7D2
_0801B7C8:
	adds r0, r2, 0
	adds r0, 0x44
	ldrb r0, [r0]
	b _0801B7D2
_0801B7D0:
	movs r0, 0
_0801B7D2:
	pop {r1}
	bx r1
	thumb_func_end sub_801B784

	thumb_func_start sub_801B7D8
sub_801B7D8: @ 801B7D8
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gSaveBlock1Ptr
	ldr r0, [r2]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	adds r3, r2, 0
	cmp r0, 0x2
	bne _0801B850
	movs r2, 0
	cmp r4, 0x4
	bhi _0801B83A
	lsls r0, r4, 2
	ldr r1, =_0801B80C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801B80C:
	.4byte _0801B820
	.4byte _0801B828
	.4byte _0801B834
	.4byte _0801B83A
	.4byte _0801B83A
_0801B820:
	ldr r0, [r3]
	movs r1, 0xD5
	lsls r1, 6
	b _0801B838
_0801B828:
	ldr r0, [r3]
	ldr r1, =0x00003542
	b _0801B838
	.pool
_0801B834:
	ldr r0, [r3]
	ldr r1, =0x00003544
_0801B838:
	adds r2, r0, r1
_0801B83A:
	cmp r2, 0
	beq _0801B850
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x000003e7
	cmp r0, r1
	bls _0801B850
	strh r1, [r2]
_0801B850:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B7D8

	thumb_func_start mevent_081445C0
mevent_081445C0: @ 801B860
	push {lr}
	cmp r0, 0x4
	bhi _0801B938
	lsls r0, 2
	ldr r1, =_0801B874
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0801B874:
	.4byte _0801B888
	.4byte _0801B8AC
	.4byte _0801B8D0
	.4byte _0801B8F4
	.4byte _0801B918
_0801B888:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x000033f0
	adds r0, r2, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0801B938
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r2, r1
	ldrh r0, [r0]
	b _0801B93A
	.pool
_0801B8AC:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x000033f0
	adds r0, r2, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0801B938
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r2, r1
	ldrh r0, [r0, 0x2]
	b _0801B93A
	.pool
_0801B8D0:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r1, =0x000033f0
	adds r0, r2, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0801B938
	movs r1, 0xD5
	lsls r1, 6
	adds r0, r2, r1
	ldrh r0, [r0, 0x4]
	b _0801B93A
	.pool
_0801B8F4:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801B938
	bl sub_801B4CC
	lsls r0, 16
	lsrs r0, 16
	b _0801B93A
	.pool
_0801B918:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r2, r0, r1
	ldrb r1, [r2, 0x8]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0801B938
	ldrb r0, [r2, 0x9]
	b _0801B93A
	.pool
_0801B938:
	movs r0, 0
_0801B93A:
	pop {r1}
	bx r1
	thumb_func_end mevent_081445C0

	thumb_func_start sub_801B940
sub_801B940: @ 801B940
	ldr r1, =gUnknown_02022C70
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_801B940

	thumb_func_start sub_801B94C
sub_801B94C: @ 801B94C
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	adds r4, r0, 0
	ldr r5, =gUnknown_02022C70
	movs r0, 0
	str r0, [r5]
	cmp r4, 0
	beq _0801B98A
	bl sub_801B27C
	cmp r0, 0
	beq _0801B988
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000033f0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r4
	bne _0801B988
	movs r0, 0x1
	str r0, [r5]
	b _0801B98A
	.pool
_0801B988:
	movs r0, 0
_0801B98A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801B94C

	thumb_func_start sub_801B990
sub_801B990: @ 801B990
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02022C70
	ldr r0, [r0]
	cmp r0, 0
	beq _0801B9EC
	cmp r2, 0x1
	beq _0801B9DC
	cmp r2, 0x1
	bcc _0801B9C0
	cmp r2, 0x2
	bne _0801B9EC
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00003584
	adds r2, r0
	movs r0, 0x2
	b _0801B9CA
	.pool
_0801B9C0:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00003570
	adds r2, r0
	movs r0, 0
_0801B9CA:
	movs r3, 0x5
	bl sub_801BA8C
	b _0801B9EC
	.pool
_0801B9DC:
	ldr r0, =gSaveBlock1Ptr
	ldr r2, [r0]
	ldr r0, =0x00003570
	adds r2, r0
	movs r0, 0x1
	movs r3, 0x5
	bl sub_801BA8C
_0801B9EC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B990

	thumb_func_start sub_801B9F8
sub_801B9F8: @ 801B9F8
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00003570
	adds r1, r0
	ldr r2, =0x0500000a
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_801B9F8

	thumb_func_start sub_801BA24
sub_801BA24: @ 801BA24
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r2
	bge _0801BA46
	ldr r0, [r4]
	cmp r0, r5
	beq _0801BA46
	adds r3, r4, 0
_0801BA38:
	adds r3, 0x4
	adds r1, 0x1
	cmp r1, r2
	bge _0801BA46
	ldr r0, [r3]
	cmp r0, r5
	bne _0801BA38
_0801BA46:
	cmp r1, r2
	bne _0801BA68
	subs r3, r1, 0x1
	cmp r3, 0
	ble _0801BA62
	lsls r0, r3, 2
	subs r0, 0x4
	adds r2, r0, r4
_0801BA56:
	ldr r0, [r2]
	str r0, [r2, 0x4]
	subs r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bgt _0801BA56
_0801BA62:
	str r5, [r4]
	movs r0, 0x1
	b _0801BA84
_0801BA68:
	adds r3, r1, 0
	cmp r3, 0
	ble _0801BA80
	lsls r0, r3, 2
	subs r0, 0x4
	adds r2, r0, r4
_0801BA74:
	ldr r0, [r2]
	str r0, [r2, 0x4]
	subs r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bgt _0801BA74
_0801BA80:
	str r5, [r4]
	movs r0, 0
_0801BA84:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801BA24

	thumb_func_start sub_801BA8C
sub_801BA8C: @ 801BA8C
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	bl sub_801BA24
	cmp r0, 0
	beq _0801BAA4
	adds r0, r4, 0
	bl sub_801B7D8
_0801BAA4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BA8C

	.align 2, 0 @ don't pad with nop
