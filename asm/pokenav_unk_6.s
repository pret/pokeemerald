	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(0xB)

	thumb_func_start sub_81CCFD8
sub_81CCFD8: @ 81CCFD8
	push {r4,lr}
	ldr r1, =0x0000678c
	movs r0, 0xB
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CD01C
	ldr r1, =0x00006428
	adds r0, r4, r1
	bl sub_81D1ED4
	bl sub_81CD970
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r0, 0x1
	b _081CD01E
	.pool
_081CD01C:
	movs r0, 0
_081CD01E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CCFD8

	thumb_func_start sub_81CD024
sub_81CD024: @ 81CD024
	push {r4,lr}
	ldr r1, =0x0000678c
	movs r0, 0xB
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081CD068
	ldr r1, =0x00006428
	adds r0, r4, r1
	bl sub_81D1ED4
	bl sub_81CD9F8
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0x14
	strh r0, [r1]
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r0, 0x1
	b _081CD06A
	.pool
_081CD068:
	movs r0, 0
_081CD06A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD024

	thumb_func_start sub_81CD070
sub_81CD070: @ 81CD070
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	ldr r2, =0x00006304
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD070

	thumb_func_start sub_81CD08C
sub_81CD08C: @ 81CD08C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r5, r0, 0
	adds r0, r4, 0
	bl sub_81CD1E4
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _081CD100
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081CD0D0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081CD100
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CD0F0
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bne _081CD100
_081CD0D0:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD19C
	str r0, [r1]
	movs r2, 0x2
	b _081CD100
	.pool
_081CD0F0:
	movs r0, 0x5
	bl PlaySE
	movs r2, 0x5
	ldr r0, =0x00006304
	adds r1, r4, r0
	ldr r0, =sub_81CD110
	str r0, [r1]
_081CD100:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD08C

	thumb_func_start sub_81CD110
sub_81CD110: @ 81CD110
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	movs r4, 0
	bl sub_811FBA4
	lsls r0, 24
	cmp r0, 0
	bne _081CD18A
	bl sub_81CEF14
	ldr r1, =0x00006786
	adds r5, r6, r1
	movs r1, 0
	ldrsb r1, [r5, r1]
	ldr r2, =0x00006783
	adds r4, r6, r2
	adds r1, r4, r1
	strb r0, [r1]
	movs r0, 0x12
	bl GetSubstructPtr
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	ldrb r3, [r0, 0x5]
	movs r0, 0
	ldrsb r0, [r5, r0]
	adds r4, r0
	ldrb r1, [r4]
	mov r0, sp
	strb r1, [r0]
	cmp r2, 0xE
	bne _081CD174
	movs r0, 0x64
	muls r0, r3
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x8
	mov r2, sp
	bl SetMonData
	b _081CD180
	.pool
_081CD174:
	adds r0, r2, 0
	adds r1, r3, 0
	movs r2, 0x8
	mov r3, sp
	bl SetBoxMonDataAt
_081CD180:
	ldr r0, =0x00006304
	adds r1, r6, r0
	ldr r0, =sub_81CD08C
	str r0, [r1]
	movs r4, 0x6
_081CD18A:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD110

	thumb_func_start sub_81CD19C
sub_81CD19C: @ 81CD19C
	push {lr}
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD1B4
	ldr r0, =0x000186aa
	b _081CD1B6
	.pool
_081CD1B4:
	ldr r0, =0x000186a2
_081CD1B6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD19C

	thumb_func_start sub_81CD1C0
sub_81CD1C0: @ 81CD1C0
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081CD1DA
	movs r0, 0x12
	bl FreePokenavSubstruct
_081CD1DA:
	movs r0, 0xB
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_81CD1C0

	thumb_func_start sub_81CD1E4
sub_81CD1E4: @ 81CD1E4
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r2, r0, 0
	movs r3, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2C]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081CD220
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD210
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	beq _081CD24E
_081CD210:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	b _081CD246
	.pool
_081CD220:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081CD24E
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081CD23E
	ldrh r1, [r2, 0x2]
	ldrh r0, [r2]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD24E
_081CD23E:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
_081CD246:
	bl sub_81CD258
	lsls r0, 24
	lsrs r3, r0, 24
_081CD24E:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD1E4

	thumb_func_start sub_81CD258
sub_81CD258: @ 81CD258
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0xB
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r5, r0, 0
	mov r0, r8
	cmp r0, 0
	beq _081CD284
	ldr r1, =0x00006788
	adds r0, r4, r1
	b _081CD288
	.pool
_081CD284:
	ldr r2, =0x00006787
	adds r0, r4, r2
_081CD288:
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 16
	lsrs r0, 16
	adds r7, r0, 0
	ldr r1, =0x00006428
	adds r0, r4, r1
	ldr r2, =0x00006786
	adds r1, r4, r2
	movs r2, 0
	ldrsb r2, [r1, r2]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	ldr r3, =0x0000643c
	adds r1, r3
	adds r1, r4, r1
	lsls r2, r7, 2
	adds r2, r7
	lsls r2, 2
	adds r2, r3
	adds r2, r4, r2
	bl sub_81D1F84
	ldrh r6, [r5, 0x2]
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD2D8
	ldrh r1, [r5]
	b _081CD2DC
	.pool
_081CD2D8:
	ldrh r1, [r5]
	subs r1, 0x1
_081CD2DC:
	eors r1, r6
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	adds r6, r0, 0
	mov r0, r8
	cmp r0, 0
	beq _081CD332
	ldr r1, =0x00006787
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r1, 0x1
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, =0x00006786
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, =0x00006789
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r0, [r5, 0x2]
	cmp r0, 0
	bne _081CD312
	ldrh r0, [r5]
_081CD312:
	subs r1, r0, 0x1
	strh r1, [r5, 0x2]
	lsls r0, r1, 16
	cmp r0, 0
	beq _081CD32C
	subs r1, 0x1
	b _081CD384
	.pool
_081CD32C:
	ldrh r0, [r5]
	subs r1, r0, 0x1
	b _081CD384
_081CD332:
	ldr r0, =0x00006788
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r1, =0x00006787
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, =0x00006786
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, =0x00006789
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD370
	adds r0, r1, 0x1
	b _081CD372
	.pool
_081CD370:
	movs r0, 0
_081CD372:
	strh r0, [r5, 0x2]
	ldrh r1, [r5, 0x2]
	ldrh r0, [r5]
	subs r0, 0x1
	cmp r1, r0
	bge _081CD382
	adds r1, 0x1
	b _081CD384
_081CD382:
	movs r1, 0
_081CD384:
	ldr r2, =0x00006302
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r4, [r5, 0x2]
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD39C
	ldrh r1, [r5]
	b _081CD3A0
	.pool
_081CD39C:
	ldrh r1, [r5]
	subs r1, 0x1
_081CD3A0:
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	cmp r6, 0
	bne _081CD3B0
	movs r0, 0x3
	b _081CD3BA
_081CD3B0:
	cmp r0, 0
	beq _081CD3B8
	movs r0, 0x1
	b _081CD3BA
_081CD3B8:
	movs r0, 0x4
_081CD3BA:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD258

	thumb_func_start sub_81CD3C4
sub_81CD3C4: @ 81CD3C4
	push {r4,lr}
	movs r0, 0xB
	bl GetSubstructPtr
	adds r4, r0, 0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r2, r0, 0
	ldr r1, =0x0000678a
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0x9
	bls _081CD3E2
	b _081CD530
_081CD3E2:
	lsls r0, 2
	ldr r1, =_081CD3F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081CD3F4:
	.4byte _081CD41C
	.4byte _081CD428
	.4byte _081CD434
	.4byte _081CD440
	.4byte _081CD490
	.4byte _081CD4A8
	.4byte _081CD4C0
	.4byte _081CD4D8
	.4byte _081CD4F0
	.4byte _081CD508
_081CD41C:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CD824
	b _081CD530
_081CD428:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CDA1C
	b _081CD530
_081CD434:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	movs r1, 0
	bl sub_81CDB98
	b _081CD530
_081CD440:
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _081CD468
	ldr r2, =0x00006786
	adds r0, r4, r2
	movs r1, 0
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, 0x1
	b _081CD53C
	.pool
_081CD468:
	ldr r0, =0x00006786
	adds r1, r4, r0
	movs r0, 0
	strb r0, [r1]
	ldr r2, =0x00006787
	adds r1, r4, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =0x00006788
	adds r1, r4, r0
	movs r0, 0x2
	strb r0, [r1]
	b _081CD530
	.pool
_081CD490:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD49C
	movs r0, 0
_081CD49C:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CD824
	b _081CD530
_081CD4A8:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD4B4
	movs r0, 0
_081CD4B4:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CDA1C
	b _081CD530
_081CD4C0:
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CD4CC
	movs r0, 0
_081CD4CC:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_81CDB98
	b _081CD530
_081CD4D8:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD4E4
	ldrh r0, [r2]
	subs r0, 0x1
_081CD4E4:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CD824
	b _081CD530
_081CD4F0:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD4FC
	ldrh r0, [r2]
	subs r0, 0x1
_081CD4FC:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CDA1C
	b _081CD530
_081CD508:
	ldrh r0, [r2, 0x2]
	subs r0, 0x1
	cmp r0, 0
	bge _081CD514
	ldrh r0, [r2]
	subs r0, 0x1
_081CD514:
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x2
	bl sub_81CDB98
	ldr r2, =0x0000678a
	adds r1, r4, r2
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	b _081CD53C
	.pool
_081CD530:
	ldr r0, =0x0000678a
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0
_081CD53C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD3C4

	thumb_func_start sub_81CD548
sub_81CD548: @ 81CD548
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r0, 0xB
	bl GetSubstructPtr
	adds r1, r0, 0
	cmp r4, 0x1
	beq _081CD588
	cmp r4, 0x1
	bgt _081CD566
	cmp r4, 0
	beq _081CD56C
	b _081CD5C4
_081CD566:
	cmp r5, 0x2
	beq _081CD5A4
	b _081CD5C4
_081CD56C:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CD824
	b _081CD5C4
	.pool
_081CD588:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CDA1C
	b _081CD5C4
	.pool
_081CD5A4:
	ldr r2, =0x00006302
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r2, =0x00006789
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81CDB98
	movs r0, 0x1
	b _081CD5C6
	.pool
_081CD5C4:
	movs r0, 0
_081CD5C6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81CD548

	thumb_func_start sub_81CD5CC
sub_81CD5CC: @ 81CD5CC
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	b _081CD5E4
_081CD5D6:
	strb r3, [r4]
	adds r1, 0x1
	adds r4, 0x1
	lsls r0, r2, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
_081CD5E4:
	ldrb r3, [r1]
	adds r0, r3, 0
	cmp r0, 0xFF
	bne _081CD5D6
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	ble _081CD612
	movs r3, 0
_081CD5FE:
	strb r3, [r4]
	adds r4, 0x1
	adds r1, r2, 0
	lsls r0, r1, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r2, r0, 16
	lsls r1, 16
	cmp r1, 0
	bgt _081CD5FE
_081CD612:
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD5CC

	thumb_func_start sub_81CD624
sub_81CD624: @ 81CD624
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r0, 0x12
	bl GetSubstructPtr
	lsls r4, 2
	adds r0, r4
	ldrb r4, [r0, 0x4]
	mov r8, r4
	ldrb r6, [r0, 0x5]
	mov r9, r6
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
	bl GetBoxOrPartyMonData
	cmp r0, 0
	beq _081CD690
	ldr r1, =gText_EggNickname
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0xC
	bl StringCopyPadded
	b _081CD80E
	.pool
_081CD690:
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	adds r3, r5, 0
	bl GetBoxOrPartyMonData
	adds r0, r5, 0
	bl StringGetEnd10
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xB
	movs r3, 0
	bl GetBoxOrPartyMonData
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r4, 0xE
	bne _081CD6E0
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
	b _081CD6FE
	.pool
_081CD6E0:
	mov r0, r8
	mov r1, r9
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
_081CD6FE:
	cmp r7, 0x1D
	beq _081CD706
	cmp r7, 0x20
	bne _081CD71C
_081CD706:
	movs r0, 0xB
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gSpeciesNames
	adds r1, r0
	adds r0, r5, 0
	bl StringCompare
	cmp r0, 0
	bne _081CD71C
	movs r6, 0xFF
_081CD71C:
	adds r3, r5, 0
	b _081CD726
	.pool
_081CD724:
	adds r3, 0x1
_081CD726:
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _081CD724
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
	beq _081CD74A
	cmp r6, 0xFE
	beq _081CD76E
	movs r0, 0x77
	b _081CD790
_081CD74A:
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
	b _081CD790
_081CD76E:
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
_081CD790:
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
	movs r5, 0
	strb r5, [r3]
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
	adds r4, r3, 0
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r3, r0, 0
	subs r4, r3, r4
	lsls r4, 16
	lsrs r4, 16
	strb r5, [r3]
	adds r3, 0x1
	mov r0, r10
	cmp r0, 0
	bne _081CD808
	movs r0, 0x3
	subs r0, r4
	lsls r0, 16
	ldr r1, =0xffff0000
	adds r0, r1
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _081CD808
	movs r2, 0
	adds r1, r0, 0
_081CD7FA:
	strb r2, [r3]
	adds r3, 0x1
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r1
	bne _081CD7FA
_081CD808:
	movs r0, 0xFF
	strb r0, [r3]
	adds r0, r3, 0
_081CD80E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CD624

	thumb_func_start sub_81CD824
sub_81CD824: @ 81CD824
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r0, 0xB
	bl GetSubstructPtr
	adds r5, r0, 0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r7, r0, 0
	mov r1, r8
	lsls r0, r1, 16
	asrs r4, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CD85A
	ldrh r2, [r7]
	cmp r4, r2
	bne _081CD862
	b _081CD900
_081CD85A:
	ldrh r0, [r7]
	subs r0, 0x1
	cmp r4, r0
	beq _081CD900
_081CD862:
	lsls r0, r6, 6
	ldr r1, =0x00006368
	adds r0, r1
	adds r0, r5, r0
	mov r2, r8
	lsls r4, r2, 16
	lsrs r1, r4, 16
	movs r2, 0
	bl sub_81CD624
	asrs r4, 14
	adds r4, r7, r4
	ldrb r3, [r4, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r4, r0, 3
	ldr r1, =0x00006320
	adds r0, r5, r1
	adds r0, r4
	movs r2, 0
	movs r1, 0xFC
	strb r1, [r0]
	ldr r1, =0x00006321
	adds r0, r5, r1
	adds r0, r4
	movs r1, 0x4
	strb r1, [r0]
	ldr r1, =0x00006322
	adds r0, r5, r1
	adds r0, r4
	movs r1, 0x8
	strb r1, [r0]
	ldr r1, =0x00006323
	adds r0, r5, r1
	adds r0, r4
	strb r2, [r0]
	ldr r2, =0x00006324
	adds r0, r5, r2
	adds r0, r4
	movs r1, 0x9
	strb r1, [r0]
	cmp r3, 0xE
	bne _081CD8E4
	adds r0, r4, r5
	ldr r1, =0x00006325
	adds r0, r1
	ldr r1, =gText_InParty
	b _081CD8F4
	.pool
_081CD8E4:
	adds r4, r5
	ldr r2, =0x00006325
	adds r4, r2
	adds r0, r3, 0
	bl GetBoxNamePtr
	adds r1, r0, 0
	adds r0, r4, 0
_081CD8F4:
	movs r2, 0x8
	bl sub_81CD5CC
	b _081CD95C
	.pool
_081CD900:
	movs r1, 0
	lsls r4, r6, 6
	lsls r0, r6, 1
	mov r8, r0
	adds r3, r4, 0
	ldr r0, =0x00006368
	adds r2, r5, r0
	movs r7, 0
_081CD910:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r7, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xB
	bls _081CD910
	adds r1, r4
	ldr r2, =0x00006368
	adds r0, r5, r2
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r1, 0
	mov r2, r8
	adds r0, r2, r6
	lsls r3, r0, 3
	ldr r0, =0x00006320
	adds r2, r5, r0
	movs r4, 0
_081CD93A:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r4, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bls _081CD93A
	mov r2, r8
	adds r0, r2, r6
	lsls r0, 3
	adds r0, r1, r0
	ldr r2, =0x00006320
	adds r1, r5, r2
	adds r1, r0
	movs r0, 0xFF
	strb r0, [r1]
_081CD95C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD824

	thumb_func_start sub_81CD970
sub_81CD970: @ 81CD970
	push {r4-r7,lr}
	movs r0, 0xB
	bl GetSubstructPtr
	adds r7, r0, 0
	ldr r1, =0x000006ac
	movs r0, 0x12
	bl AllocSubstruct
	adds r6, r0, 0
	movs r0, 0xC6
	lsls r0, 7
	adds r1, r7, r0
	movs r0, 0
	strb r0, [r1]
	movs r4, 0
	movs r5, 0
	b _081CD9C4
	.pool
_081CD998:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r2, r0, 0
	cmp r2, 0
	bne _081CD9BE
	lsls r1, r5, 2
	adds r1, r6, r1
	movs r0, 0xE
	strb r0, [r1, 0x4]
	strb r4, [r1, 0x5]
	strh r2, [r1, 0x6]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_081CD9BE:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_081CD9C4:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bcc _081CD998
	lsls r0, r5, 2
	adds r0, r6, r0
	movs r1, 0
	strb r1, [r0, 0x4]
	strb r1, [r0, 0x5]
	movs r2, 0
	strh r1, [r0, 0x6]
	strh r1, [r6, 0x2]
	adds r0, r5, 0x1
	strh r0, [r6]
	ldr r1, =0x0000678a
	adds r0, r7, r1
	strb r2, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD970

	thumb_func_start sub_81CD9F8
sub_81CD9F8: @ 81CD9F8
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	movs r1, 0xC6
	lsls r1, 7
	adds r2, r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r2]
	ldr r1, =0x0000678a
	adds r0, r1
	strb r3, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CD9F8

	thumb_func_start sub_81CDA1C
sub_81CDA1C: @ 81CDA1C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0xB
	bl GetSubstructPtr
	mov r8, r0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r4, r0, 0
	lsls r0, r6, 16
	asrs r5, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CDA52
	ldrh r0, [r4]
	cmp r5, r0
	bne _081CDA5A
	b _081CDB48
_081CDA52:
	ldrh r0, [r4]
	subs r0, 0x1
	cmp r5, r0
	beq _081CDB48
_081CDA5A:
	lsls r0, r6, 16
	asrs r0, 14
	adds r0, r4, r0
	ldrb r6, [r0, 0x4]
	ldrb r7, [r0, 0x5]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x16
	movs r3, 0
	bl GetBoxOrPartyMonData
	mov r1, r9
	lsls r5, r1, 2
	adds r4, r5, r1
	ldr r1, =0x00006428
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x2F
	movs r3, 0
	bl GetBoxOrPartyMonData
	ldr r1, =0x00006429
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x21
	movs r3, 0
	bl GetBoxOrPartyMonData
	ldr r1, =0x0000642a
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x18
	movs r3, 0
	bl GetBoxOrPartyMonData
	ldr r1, =0x0000642b
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x17
	movs r3, 0
	bl GetBoxOrPartyMonData
	ldr r1, =0x0000642c
	add r1, r8
	adds r1, r4
	strb r0, [r1]
	movs r0, 0xCF
	lsls r0, 7
	add r0, r8
	mov r2, r9
	adds r4, r0, r2
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x30
	movs r3, 0
	bl GetBoxOrPartyMonData
	cmp r0, 0xFF
	beq _081CDB10
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x30
	movs r3, 0
	bl GetBoxOrPartyMonData
	movs r1, 0x1D
	bl __udivsi3
	b _081CDB12
	.pool
_081CDB10:
	movs r0, 0x9
_081CDB12:
	strb r0, [r4]
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0x8
	movs r3, 0
	bl GetBoxOrPartyMonData
	ldr r1, =0x00006783
	add r1, r8
	add r1, r9
	strb r0, [r1]
	mov r0, r9
	adds r1, r5, r0
	ldr r2, =0x00006428
	adds r0, r1, r2
	add r0, r8
	lsls r1, 2
	adds r2, 0x14
	adds r1, r2
	add r1, r8
	bl sub_81D2754
	b _081CDB80
	.pool
_081CDB48:
	movs r2, 0
	mov r0, r9
	lsls r5, r0, 2
	add r5, r9
	ldr r4, =0x00006428
	add r4, r8
	lsls r3, r5, 2
	mov r9, r2
	ldr r7, =0x0000643c
	movs r6, 0x9B
_081CDB5C:
	adds r0, r2, r5
	adds r0, r4, r0
	mov r1, r9
	strb r1, [r0]
	lsls r0, r2, 2
	adds r0, r3
	add r0, r8
	adds r1, r0, r7
	strh r6, [r1]
	ldr r1, =0x0000643e
	adds r0, r1
	movs r1, 0x5B
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x4
	bls _081CDB5C
_081CDB80:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDA1C

	thumb_func_start sub_81CDB98
sub_81CDB98: @ 81CDB98
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0xB
	bl GetSubstructPtr
	adds r7, r0, 0
	movs r0, 0x12
	bl GetSubstructPtr
	adds r4, r0, 0
	lsls r0, r6, 16
	asrs r5, r0, 16
	bl sub_81CDD5C
	cmp r0, 0
	beq _081CDBCC
	ldrh r0, [r4]
	b _081CDBD0
_081CDBCC:
	ldrh r0, [r4]
	subs r0, 0x1
_081CDBD0:
	cmp r5, r0
	beq _081CDC3E
	lsls r0, r6, 16
	asrs r0, 14
	adds r0, r4, r0
	ldrb r5, [r0, 0x4]
	ldrb r6, [r0, 0x5]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x41
	movs r3, 0
	bl GetBoxOrPartyMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl GetBoxOrPartyMonData
	mov r8, r0
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl GetBoxOrPartyMonData
	adds r5, r0, 0
	lsls r0, r4, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	mov r2, r9
	lsls r1, r2, 13
	movs r2, 0xC0
	lsls r2, 2
	adds r1, r2
	adds r1, r7, r1
	movs r2, 0x1
	str r2, [sp]
	adds r2, r4, 0
	adds r3, r5, 0
	bl LoadSpecialPokePic
	adds r0, r4, 0
	mov r1, r8
	adds r2, r5, 0
	bl GetFrontSpritePalFromSpeciesAndPersonality
	mov r2, r9
	lsls r1, r2, 7
	adds r1, r7, r1
	bl LZ77UnCompWram
_081CDC3E:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81CDB98

	thumb_func_start sub_81CDC50
sub_81CDC50: @ 81CDC50
	push {lr}
	movs r0, 0x12
	bl GetSubstructPtr
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDC50

	thumb_func_start sub_81CDC60
sub_81CDC60: @ 81CDC60
	push {lr}
	movs r0, 0x12
	bl GetSubstructPtr
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDC60

	thumb_func_start sub_81CDC70
sub_81CDC70: @ 81CDC70
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	ldr r1, =0x00006428
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC70

	thumb_func_start sub_81CDC84
sub_81CDC84: @ 81CDC84
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	ldr r1, =0x00006786
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC84

	thumb_func_start sub_81CDC9C
sub_81CDC9C: @ 81CDC9C
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	ldr r1, =0x00006302
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDC9C

	thumb_func_start sub_81CDCB4
sub_81CDCB4: @ 81CDCB4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl GetSubstructPtr
	lsls r4, 13
	movs r1, 0xC0
	lsls r1, 2
	adds r4, r1
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDCB4

	thumb_func_start sub_81CDCD4
sub_81CDCD4: @ 81CDCD4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl GetSubstructPtr
	lsls r4, 7
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81CDCD4

	thumb_func_start sub_81CDCEC
sub_81CDCEC: @ 81CDCEC
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	ldr r1, =0x00006789
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDCEC

	thumb_func_start sub_81CDD04
sub_81CDD04: @ 81CDD04
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl GetSubstructPtr
	lsls r4, 6
	ldr r1, =0x00006368
	adds r4, r1
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD04

	thumb_func_start sub_81CDD24
sub_81CDD24: @ 81CDD24
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xB
	bl GetSubstructPtr
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	ldr r2, =0x00006320
	adds r1, r2
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD24

	thumb_func_start sub_81CDD48
sub_81CDD48: @ 81CDD48
	push {lr}
	movs r0, 0x12
	bl GetSubstructPtr
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	pop {r1}
	bx r1
	thumb_func_end sub_81CDD48

	thumb_func_start sub_81CDD5C
sub_81CDD5C: @ 81CDD5C
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CDD74
	movs r0, 0
	b _081CDD76
_081CDD74:
	movs r0, 0x1
_081CDD76:
	pop {r1}
	bx r1
	thumb_func_end sub_81CDD5C

	thumb_func_start sub_81CDD7C
sub_81CDD7C: @ 81CDD7C
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	adds r2, r0, 0
	movs r1, 0xC6
	lsls r1, 7
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081CDD96
	movs r0, 0
	b _081CDDA6
_081CDD96:
	ldr r3, =0x00006786
	adds r0, r2, r3
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r3, 0x3
	adds r0, r2, r3
	adds r0, r1
	ldrb r0, [r0]
_081CDDA6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDD7C

	thumb_func_start sub_81CDDB0
sub_81CDDB0: @ 81CDDB0
	push {lr}
	movs r0, 0xB
	bl GetSubstructPtr
	ldr r2, =0x00006786
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r2, 0x6
	adds r0, r2
	adds r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81CDDB0

	.align 2, 0 @ Don't pad with nop.
