	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81562C4
sub_81562C4: @ 81562C4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	movs r1, 0
	movs r2, 0x44
	bl memset
	movs r1, 0
	movs r3, 0x64
	adds r2, r4, 0
_081562DE:
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	adds r0, 0x5
	adds r0, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, 0x3
	ble _081562DE
	ldr r0, [r2]
	ldr r0, [r0, 0xC]
	adds r0, 0x41
	movs r1, 0
	strb r5, [r0]
	ldr r0, [r2]
	ldr r0, [r0, 0xC]
	adds r0, 0x40
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, [r0, 0xC]
	ldr r1, =gUnknown_02039E00
	adds r0, r2, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2, 0x14]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81562C4

	thumb_func_start sub_8156324
sub_8156324: @ 8156324
	push {r4-r6,lr}
	ldr r1, =gUnknown_02039F34
	ldr r0, [r1]
	ldr r0, [r0, 0xC]
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _0815636A
	adds r4, r1, 0
	movs r5, 0
_08156336:
	ldr r0, [r4]
	ldr r2, [r0, 0xC]
	ldr r0, [r2, 0x14]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0815634A
	strb r5, [r2]
	bl sub_81563B0
_0815634A:
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldr r0, [r1, 0x14]
	lsrs r0, 1
	str r0, [r1, 0x14]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	strb r5, [r0, 0x4]
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	ldr r0, [r0, 0x14]
	cmp r0, 0
	bne _08156336
_0815636A:
	movs r6, 0x3
_0815636C:
	bl Random
	adds r5, r0, 0
	ands r5, r6
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	adds r0, r1, 0x5
	adds r0, r5
	ldrb r3, [r0]
	movs r2, 0
	ldrb r1, [r1, 0x5]
	cmp r3, r1
	bcc _0815639E
	adds r1, r4, 0
_0815638A:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0815639E
	ldr r0, [r1]
	ldr r0, [r0, 0xC]
	adds r0, 0x5
	adds r0, r2
	ldrb r0, [r0]
	cmp r3, r0
	bcs _0815638A
_0815639E:
	cmp r2, 0x4
	bne _0815636C
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8156324

	thumb_func_start sub_81563B0
sub_81563B0: @ 81563B0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	ldrb r0, [r0]
	adds r4, r5, 0
	cmp r0, 0x2
	beq _081564A0
	adds r7, r5, 0
	ldr r6, =gAIScriptPtr
	ldr r0, =gUnknown_02039E1E
	mov r8, r0
_081563CC:
	ldr r0, [r7]
	ldr r2, [r0, 0xC]
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08156426
	cmp r0, 0x1
	bgt _08156496
	cmp r0, 0
	bne _08156496
	ldr r1, =gContestAIs
	ldrb r0, [r2, 0x10]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r6]
	ldrb r1, [r2, 0x4]
	lsls r1, 1
	adds r0, r2, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	add r1, r8
	ldrh r1, [r1]
	adds r0, r1, 0
	cmp r0, 0
	bne _08156418
	strh r0, [r2, 0x2]
	b _0815641A
	.pool
_08156418:
	strh r1, [r2, 0x2]
_0815641A:
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08156496
_08156426:
	ldrh r1, [r2, 0x2]
	cmp r1, 0
	beq _08156444
	ldr r1, =gUnknown_085CDD00
	ldr r0, [r6]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	b _08156458
	.pool
_08156444:
	adds r0, r2, 0x5
	ldrb r2, [r2, 0x4]
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r7]
	ldr r2, [r0, 0xC]
	ldrb r1, [r2, 0x9]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
_08156458:
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r3, [r0, 0xC]
	ldrb r1, [r3, 0x9]
	movs r0, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _08156496
	ldrb r0, [r3, 0x4]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r3, 0x4]
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldrb r0, [r1, 0x4]
	cmp r0, 0x3
	bhi _08156484
	strb r2, [r1]
	b _0815648A
	.pool
_08156484:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_0815648A:
	ldr r0, [r4]
	ldr r2, [r0, 0xC]
	ldrb r1, [r2, 0x9]
	movs r0, 0xFE
	ands r0, r1
	strb r0, [r2, 0x9]
_08156496:
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081563CC
_081564A0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81563B0

	thumb_func_start sub_81564AC
sub_81564AC: @ 81564AC
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_02039F34
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	b _081564CC
	.pool
_081564C0:
	adds r1, 0x1
	cmp r1, 0x3
	bgt _081564D2
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	adds r0, r1
_081564CC:
	ldrb r0, [r0]
	cmp r0, r2
	bne _081564C0
_081564D2:
	lsls r0, r1, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81564AC

	thumb_func_start sub_81564DC
sub_81564DC: @ 81564DC
	push {r4,lr}
	ldr r3, =gUnknown_02039F34
	ldr r0, [r3]
	ldr r0, [r0, 0xC]
	adds r1, r0, 0x5
	ldrb r0, [r0, 0x4]
	adds r1, r0
	ldr r2, =gAIScriptPtr
	ldr r0, [r2]
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _08156510
	movs r4, 0xFF
	b _08156516
	.pool
_08156510:
	cmp r0, 0
	bge _08156516
	movs r4, 0
_08156516:
	ldr r0, [r3]
	ldr r1, [r0, 0xC]
	adds r0, r1, 0x5
	ldrb r1, [r1, 0x4]
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, 0x2
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81564DC

	thumb_func_start sub_8156530
sub_8156530: @ 8156530
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	strh r0, [r1, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156530

	thumb_func_start sub_8156550
sub_8156550: @ 8156550
	push {lr}
	bl sub_8156530
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _0815658C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156590
	.pool
_0815658C:
	adds r0, r2, 0x5
	str r0, [r3]
_08156590:
	pop {r0}
	bx r0
	thumb_func_end sub_8156550

	thumb_func_start sub_8156594
sub_8156594: @ 8156594
	push {lr}
	bl sub_8156530
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _081565D0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081565D4
	.pool
_081565D0:
	adds r0, r2, 0x5
	str r0, [r3]
_081565D4:
	pop {r0}
	bx r0
	thumb_func_end sub_8156594

	thumb_func_start sub_81565D8
sub_81565D8: @ 81565D8
	push {lr}
	bl sub_8156530
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08156614
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156618
	.pool
_08156614:
	adds r0, r2, 0x5
	str r0, [r3]
_08156618:
	pop {r0}
	bx r0
	thumb_func_end sub_81565D8

	thumb_func_start sub_815661C
sub_815661C: @ 815661C
	push {lr}
	bl sub_8156530
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08156658
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815665C
	.pool
_08156658:
	adds r0, r2, 0x5
	str r0, [r3]
_0815665C:
	pop {r0}
	bx r0
	thumb_func_end sub_815661C

	thumb_func_start sub_8156660
sub_8156660: @ 8156660
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156660

	thumb_func_start sub_8156684
sub_8156684: @ 8156684
	push {lr}
	bl sub_8156660
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _081566C0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081566C4
	.pool
_081566C0:
	adds r0, r2, 0x5
	str r0, [r3]
_081566C4:
	pop {r0}
	bx r0
	thumb_func_end sub_8156684

	thumb_func_start sub_81566C8
sub_81566C8: @ 81566C8
	push {lr}
	bl sub_8156660
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _08156704
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156708
	.pool
_08156704:
	adds r0, r2, 0x5
	str r0, [r3]
_08156708:
	pop {r0}
	bx r0
	thumb_func_end sub_81566C8

	thumb_func_start sub_815670C
sub_815670C: @ 815670C
	push {lr}
	bl sub_8156660
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08156748
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815674C
	.pool
_08156748:
	adds r0, r2, 0x5
	str r0, [r3]
_0815674C:
	pop {r0}
	bx r0
	thumb_func_end sub_815670C

	thumb_func_start sub_8156750
sub_8156750: @ 8156750
	push {lr}
	bl sub_8156660
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _0815678C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156790
	.pool
_0815678C:
	adds r0, r2, 0x5
	str r0, [r3]
_08156790:
	pop {r0}
	bx r0
	thumb_func_end sub_8156750

	thumb_func_start sub_8156794
sub_8156794: @ 8156794
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r0, [r0, 0x8]
	adds r1, r2, 0
	adds r1, 0x41
	ldrb r1, [r1]
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156794

	thumb_func_start sub_81567BC
sub_81567BC: @ 81567BC
	push {lr}
	bl sub_8156794
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _081567F8
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081567FC
	.pool
_081567F8:
	adds r0, r2, 0x5
	str r0, [r3]
_081567FC:
	pop {r0}
	bx r0
	thumb_func_end sub_81567BC

	thumb_func_start sub_8156800
sub_8156800: @ 8156800
	push {lr}
	bl sub_8156794
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _0815683C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156840
	.pool
_0815683C:
	adds r0, r2, 0x5
	str r0, [r3]
_08156840:
	pop {r0}
	bx r0
	thumb_func_end sub_8156800

	thumb_func_start sub_8156844
sub_8156844: @ 8156844
	push {lr}
	bl sub_8156794
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08156880
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156884
	.pool
_08156880:
	adds r0, r2, 0x5
	str r0, [r3]
_08156884:
	pop {r0}
	bx r0
	thumb_func_end sub_8156844

	thumb_func_start sub_8156888
sub_8156888: @ 8156888
	push {lr}
	bl sub_8156794
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _081568C4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081568C8
	.pool
_081568C4:
	adds r0, r2, 0x5
	str r0, [r3]
_081568C8:
	pop {r0}
	bx r0
	thumb_func_end sub_8156888

	thumb_func_start sub_81568CC
sub_81568CC: @ 81568CC
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r4, [r0, 0xC]
	adds r1, r4, 0
	adds r1, 0x41
	ldrb r1, [r1]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xD]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	asrs r0, 24
	strh r0, [r4, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81568CC

	thumb_func_start sub_815690C
sub_815690C: @ 815690C
	push {lr}
	bl sub_81568CC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _08156948
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815694C
	.pool
_08156948:
	adds r0, r2, 0x5
	str r0, [r3]
_0815694C:
	pop {r0}
	bx r0
	thumb_func_end sub_815690C

	thumb_func_start sub_8156950
sub_8156950: @ 8156950
	push {lr}
	bl sub_81568CC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _0815698C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156990
	.pool
_0815698C:
	adds r0, r2, 0x5
	str r0, [r3]
_08156990:
	pop {r0}
	bx r0
	thumb_func_end sub_8156950

	thumb_func_start sub_8156994
sub_8156994: @ 8156994
	push {lr}
	bl sub_81568CC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _081569D0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081569D4
	.pool
_081569D0:
	adds r0, r2, 0x5
	str r0, [r3]
_081569D4:
	pop {r0}
	bx r0
	thumb_func_end sub_8156994

	thumb_func_start sub_81569D8
sub_81569D8: @ 81569D8
	push {lr}
	bl sub_81568CC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08156A14
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156A18
	.pool
_08156A14:
	adds r0, r2, 0x5
	str r0, [r3]
_08156A18:
	pop {r0}
	bx r0
	thumb_func_end sub_81569D8

	thumb_func_start sub_8156A1C
sub_8156A1C: @ 8156A1C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r3, [r0, 0xC]
	adds r1, r3, 0
	adds r1, 0x41
	ldrb r1, [r1]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x4]
	strh r0, [r3, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156A1C

	thumb_func_start sub_8156A48
sub_8156A48: @ 8156A48
	push {r4,r5,lr}
	bl sub_8156A1C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bge _08156A8C
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156A90
	.pool
_08156A8C:
	adds r0, r3, 0x6
	str r0, [r4]
_08156A90:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156A48

	thumb_func_start sub_8156A98
sub_8156A98: @ 8156A98
	push {r4,r5,lr}
	bl sub_8156A1C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	ble _08156ADC
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156AE0
	.pool
_08156ADC:
	adds r0, r3, 0x6
	str r0, [r4]
_08156AE0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156A98

	thumb_func_start sub_8156AE8
sub_8156AE8: @ 8156AE8
	push {r4,r5,lr}
	bl sub_8156A1C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bne _08156B2C
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156B30
	.pool
_08156B2C:
	adds r0, r3, 0x6
	str r0, [r4]
_08156B30:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156AE8

	thumb_func_start sub_8156B38
sub_8156B38: @ 8156B38
	push {r4,r5,lr}
	bl sub_8156A1C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	beq _08156B7C
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156B80
	.pool
_08156B7C:
	adds r0, r3, 0x6
	str r0, [r4]
_08156B80:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156B38

	thumb_func_start sub_8156B88
sub_8156B88: @ 8156B88
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r1, =gUnknown_02039F00
	adds r0, r2, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156B88

	thumb_func_start sub_8156BB4
sub_8156BB4: @ 8156BB4
	push {r4,r5,lr}
	bl sub_8156B88
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bge _08156BF8
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156BFC
	.pool
_08156BF8:
	adds r0, r3, 0x6
	str r0, [r4]
_08156BFC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156BB4

	thumb_func_start sub_8156C04
sub_8156C04: @ 8156C04
	push {r4,r5,lr}
	bl sub_8156B88
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	ble _08156C48
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156C4C
	.pool
_08156C48:
	adds r0, r3, 0x6
	str r0, [r4]
_08156C4C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156C04

	thumb_func_start sub_8156C54
sub_8156C54: @ 8156C54
	push {r4,r5,lr}
	bl sub_8156B88
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	bne _08156C98
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156C9C
	.pool
_08156C98:
	adds r0, r3, 0x6
	str r0, [r4]
_08156C9C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156C54

	thumb_func_start sub_8156CA4
sub_8156CA4: @ 8156CA4
	push {r4,r5,lr}
	bl sub_8156B88
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3]
	ldrb r0, [r3, 0x1]
	lsls r0, 8
	orrs r1, r0
	movs r5, 0x18
	ldrsh r0, [r2, r5]
	lsls r1, 16
	asrs r1, 16
	cmp r0, r1
	beq _08156CE8
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08156CEC
	.pool
_08156CE8:
	adds r0, r3, 0x6
	str r0, [r4]
_08156CEC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8156CA4

	thumb_func_start sub_8156CF4
sub_8156CF4: @ 8156CF4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r0, =gScriptContestCategory
	ldrh r0, [r0]
	strh r0, [r1, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156CF4

	thumb_func_start sub_8156D18
sub_8156D18: @ 8156D18
	push {lr}
	bl sub_8156CF4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08156D54
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156D58
	.pool
_08156D54:
	adds r0, r2, 0x5
	str r0, [r3]
_08156D58:
	pop {r0}
	bx r0
	thumb_func_end sub_8156D18

	thumb_func_start sub_8156D5C
sub_8156D5C: @ 8156D5C
	push {lr}
	bl sub_8156CF4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08156D98
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156D9C
	.pool
_08156D98:
	adds r0, r2, 0x5
	str r0, [r3]
_08156D9C:
	pop {r0}
	bx r0
	thumb_func_end sub_8156D5C

	thumb_func_start sub_8156DA0
sub_8156DA0: @ 8156DA0
	push {r4,lr}
	ldr r2, =gUnknown_02039E00
	ldr r4, =gUnknown_02039F34
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	ldrb r1, [r0, 0x4]
	lsls r1, 1
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	bl sub_80DD9F0
	ldr r1, [r4]
	ldr r1, [r1, 0xC]
	lsls r0, 24
	asrs r0, 24
	strh r0, [r1, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8156DA0

	thumb_func_start sub_8156DE4
sub_8156DE4: @ 8156DE4
	push {r4,lr}
	bl sub_8156DA0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	movs r4, 0x18
	ldrsh r1, [r0, r4]
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bge _08156E20
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156E24
	.pool
_08156E20:
	adds r0, r2, 0x5
	str r0, [r3]
_08156E24:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8156DE4

	thumb_func_start sub_8156E2C
sub_8156E2C: @ 8156E2C
	push {r4,lr}
	bl sub_8156DA0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	movs r4, 0x18
	ldrsh r1, [r0, r4]
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	ble _08156E68
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156E6C
	.pool
_08156E68:
	adds r0, r2, 0x5
	str r0, [r3]
_08156E6C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8156E2C

	thumb_func_start sub_8156E74
sub_8156E74: @ 8156E74
	push {r4,lr}
	bl sub_8156DA0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	movs r4, 0x18
	ldrsh r1, [r0, r4]
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _08156EB0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156EB4
	.pool
_08156EB0:
	adds r0, r2, 0x5
	str r0, [r3]
_08156EB4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8156E74

	thumb_func_start sub_8156EBC
sub_8156EBC: @ 8156EBC
	push {r4,lr}
	bl sub_8156DA0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	movs r4, 0x18
	ldrsh r1, [r0, r4]
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	beq _08156EF8
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156EFC
	.pool
_08156EF8:
	adds r0, r2, 0x5
	str r0, [r3]
_08156EFC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8156EBC

	thumb_func_start sub_8156F04
sub_8156F04: @ 8156F04
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r3, [r0, 0xC]
	ldrb r1, [r3, 0x4]
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r3, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156F04

	thumb_func_start sub_8156F44
sub_8156F44: @ 8156F44
	push {lr}
	bl sub_8156F04
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08156F80
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156F84
	.pool
_08156F80:
	adds r0, r2, 0x5
	str r0, [r3]
_08156F84:
	pop {r0}
	bx r0
	thumb_func_end sub_8156F44

	thumb_func_start sub_8156F88
sub_8156F88: @ 8156F88
	push {lr}
	bl sub_8156F04
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08156FC4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08156FC8
	.pool
_08156FC4:
	adds r0, r2, 0x5
	str r0, [r3]
_08156FC8:
	pop {r0}
	bx r0
	thumb_func_end sub_8156F88

	thumb_func_start sub_8156FCC
sub_8156FCC: @ 8156FCC
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r3, [r0, 0xC]
	ldrb r1, [r3, 0x4]
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	ldr r2, =gContestEffects
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r3, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8156FCC

	thumb_func_start sub_8157018
sub_8157018: @ 8157018
	push {lr}
	bl sub_8156FCC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08157054
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157058
	.pool
_08157054:
	adds r0, r2, 0x5
	str r0, [r3]
_08157058:
	pop {r0}
	bx r0
	thumb_func_end sub_8157018

	thumb_func_start sub_815705C
sub_815705C: @ 815705C
	push {lr}
	bl sub_8156FCC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08157098
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815709C
	.pool
_08157098:
	adds r0, r2, 0x5
	str r0, [r3]
_0815709C:
	pop {r0}
	bx r0
	thumb_func_end sub_815705C

	thumb_func_start sub_81570A0
sub_81570A0: @ 81570A0
	push {r4-r7,lr}
	ldr r2, =gUnknown_02039E00
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r1, 0x41
	ldrb r1, [r1]
	lsls r1, 6
	adds r0, r1
	adds r2, 0x1E
	adds r0, r2
	ldrh r0, [r0]
	ldr r3, =gContestEffects
	ldr r4, =gContestMoves
	lsls r0, 3
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldrb r7, [r0, 0x1]
	movs r6, 0
	ldr r0, =gAIScriptPtr
	mov r12, r0
	adds r1, r2
_081570D4:
	ldrh r0, [r1]
	cmp r0, 0
	beq _081570EA
	lsls r0, 3
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	cmp r7, r0
	bcc _081570F2
_081570EA:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _081570D4
_081570F2:
	cmp r6, 0x4
	bne _08157114
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	movs r0, 0x1
	b _0815711A
	.pool
_08157114:
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	movs r0, 0
_0815711A:
	strh r0, [r1, 0x18]
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81570A0

	thumb_func_start sub_815712C
sub_815712C: @ 815712C
	push {lr}
	bl sub_81570A0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157164
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815716C
	.pool
_08157164:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_0815716C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815712C

	thumb_func_start sub_8157174
sub_8157174: @ 8157174
	push {r4-r7,lr}
	ldr r2, =gUnknown_02039E00
	ldr r5, =gUnknown_02039F34
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r1, 0x41
	ldrb r1, [r1]
	lsls r1, 6
	adds r0, r1
	adds r2, 0x1E
	adds r0, r2
	ldrh r0, [r0]
	ldr r3, =gContestEffects
	ldr r4, =gContestMoves
	lsls r0, 3
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldrb r7, [r0, 0x2]
	movs r6, 0
	ldr r0, =gAIScriptPtr
	mov r12, r0
	adds r1, r2
_081571A8:
	ldrh r0, [r1]
	cmp r0, 0
	beq _081571BE
	lsls r0, 3
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	cmp r7, r0
	bcc _081571C6
_081571BE:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _081571A8
_081571C6:
	cmp r6, 0x4
	bne _081571E8
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	movs r0, 0x1
	b _081571EE
	.pool
_081571E8:
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	movs r0, 0
_081571EE:
	strh r0, [r1, 0x18]
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8157174

	thumb_func_start sub_8157200
sub_8157200: @ 8157200
	push {lr}
	bl sub_8157174
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157238
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157240
	.pool
_08157238:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08157240:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157200

	thumb_func_start sub_8157248
sub_8157248: @ 8157248
	push {r4,lr}
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r4, [r0, 0xC]
	ldrb r1, [r4, 0x4]
	lsls r1, 1
	adds r0, r4, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	ldr r2, =gContestEffects
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157248

	thumb_func_start sub_81572A4
sub_81572A4: @ 81572A4
	push {lr}
	bl sub_8157248
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _081572E0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081572E4
	.pool
_081572E0:
	adds r0, r2, 0x5
	str r0, [r3]
_081572E4:
	pop {r0}
	bx r0
	thumb_func_end sub_81572A4

	thumb_func_start sub_81572E8
sub_81572E8: @ 81572E8
	push {lr}
	bl sub_8157248
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _08157324
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157328
	.pool
_08157324:
	adds r0, r2, 0x5
	str r0, [r3]
_08157328:
	pop {r0}
	bx r0
	thumb_func_end sub_81572E8

	thumb_func_start sub_815732C
sub_815732C: @ 815732C
	push {lr}
	bl sub_8157248
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08157368
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815736C
	.pool
_08157368:
	adds r0, r2, 0x5
	str r0, [r3]
_0815736C:
	pop {r0}
	bx r0
	thumb_func_end sub_815732C

	thumb_func_start sub_8157370
sub_8157370: @ 8157370
	push {lr}
	bl sub_8157248
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _081573AC
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081573B0
	.pool
_081573AC:
	adds r0, r2, 0x5
	str r0, [r3]
_081573B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8157370

	thumb_func_start sub_81573B4
sub_81573B4: @ 81573B4
	push {r4,lr}
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r4, [r0, 0xC]
	ldrb r1, [r4, 0x4]
	lsls r1, 1
	adds r0, r4, 0
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r0, [r1]
	ldr r2, =gContestEffects
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81573B4

	thumb_func_start sub_8157410
sub_8157410: @ 8157410
	push {lr}
	bl sub_81573B4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _0815744C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157450
	.pool
_0815744C:
	adds r0, r2, 0x5
	str r0, [r3]
_08157450:
	pop {r0}
	bx r0
	thumb_func_end sub_8157410

	thumb_func_start sub_8157454
sub_8157454: @ 8157454
	push {lr}
	bl sub_81573B4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _08157490
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157494
	.pool
_08157490:
	adds r0, r2, 0x5
	str r0, [r3]
_08157494:
	pop {r0}
	bx r0
	thumb_func_end sub_8157454

	thumb_func_start sub_8157498
sub_8157498: @ 8157498
	push {lr}
	bl sub_81573B4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _081574D4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081574D8
	.pool
_081574D4:
	adds r0, r2, 0x5
	str r0, [r3]
_081574D8:
	pop {r0}
	bx r0
	thumb_func_end sub_8157498

	thumb_func_start sub_81574DC
sub_81574DC: @ 81574DC
	push {lr}
	bl sub_81573B4
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08157518
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815751C
	.pool
_08157518:
	adds r0, r2, 0x5
	str r0, [r3]
_0815751C:
	pop {r0}
	bx r0
	thumb_func_end sub_81574DC

	thumb_func_start sub_8157520
sub_8157520: @ 8157520
	push {r4,r5,lr}
	ldr r3, =gUnknown_02039E00
	ldr r5, =gUnknown_02039F34
	ldr r4, [r5]
	ldr r1, [r4, 0xC]
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r1, 0x41
	ldrb r2, [r1]
	lsls r1, r2, 6
	adds r0, r1
	adds r3, 0x1E
	adds r0, r3
	ldrh r3, [r0]
	ldr r1, [r4, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x8]
	cmp r3, r1
	beq _08157558
	movs r1, 0
	b _08157560
	.pool
_08157558:
	ldrb r0, [r0, 0xB]
	lsls r0, 25
	lsrs r0, 29
	adds r1, r0, 0x1
_08157560:
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	strh r1, [r0, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157520

	thumb_func_start sub_8157578
sub_8157578: @ 8157578
	push {lr}
	bl sub_8157520
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _081575B4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081575B8
	.pool
_081575B4:
	adds r0, r2, 0x5
	str r0, [r3]
_081575B8:
	pop {r0}
	bx r0
	thumb_func_end sub_8157578

	thumb_func_start sub_81575BC
sub_81575BC: @ 81575BC
	push {lr}
	bl sub_8157520
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _081575F8
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081575FC
	.pool
_081575F8:
	adds r0, r2, 0x5
	str r0, [r3]
_081575FC:
	pop {r0}
	bx r0
	thumb_func_end sub_81575BC

	thumb_func_start sub_8157600
sub_8157600: @ 8157600
	push {lr}
	bl sub_8157520
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _0815763C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157640
	.pool
_0815763C:
	adds r0, r2, 0x5
	str r0, [r3]
_08157640:
	pop {r0}
	bx r0
	thumb_func_end sub_8157600

	thumb_func_start sub_8157644
sub_8157644: @ 8157644
	push {lr}
	bl sub_8157520
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08157680
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157684
	.pool
_08157680:
	adds r0, r2, 0x5
	str r0, [r3]
_08157684:
	pop {r0}
	bx r0
	thumb_func_end sub_8157644

	thumb_func_start sub_8157688
sub_8157688: @ 8157688
	push {r4-r6,lr}
	movs r3, 0
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	ldrb r1, [r0, 0x4]
	lsls r1, 1
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r5, [r1]
	movs r4, 0
	adds r6, r2, 0
_081576AA:
	lsls r1, r4, 1
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r1, r6
	ldrh r0, [r1]
	cmp r0, 0
	beq _081576D2
	adds r1, r0, 0
	adds r0, r5, 0
	bl AreMovesContestCombo
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _081576DC
_081576D2:
	adds r4, 0x1
	cmp r4, 0x3
	ble _081576AA
	cmp r3, 0
	beq _081576DE
_081576DC:
	movs r3, 0x1
_081576DE:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	strh r3, [r0, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157688

	thumb_func_start sub_8157700
sub_8157700: @ 8157700
	push {lr}
	bl sub_8157688
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157738
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157740
	.pool
_08157738:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157740:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157700

	thumb_func_start sub_8157748
sub_8157748: @ 8157748
	push {lr}
	bl sub_8157688
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08157780
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157788
	.pool
_08157780:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157788:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157748

	thumb_func_start sub_8157790
sub_8157790: @ 8157790
	push {r4-r6,lr}
	movs r3, 0
	ldr r2, =gUnknown_02039E00
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	ldrb r1, [r0, 0x4]
	lsls r1, 1
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r2, 0x1E
	adds r1, r2
	ldrh r5, [r1]
	movs r4, 0
	adds r6, r2, 0
_081577B2:
	lsls r1, r4, 1
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r1, r6
	ldrh r0, [r1]
	cmp r0, 0
	beq _081577D8
	adds r1, r5, 0
	bl AreMovesContestCombo
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _081577E2
_081577D8:
	adds r4, 0x1
	cmp r4, 0x3
	ble _081577B2
	cmp r3, 0
	beq _081577E4
_081577E2:
	movs r3, 0x1
_081577E4:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	strh r3, [r0, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157790

	thumb_func_start sub_8157808
sub_8157808: @ 8157808
	push {lr}
	bl sub_8157790
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157840
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157848
	.pool
_08157840:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157848:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157808

	thumb_func_start sub_8157850
sub_8157850: @ 8157850
	push {lr}
	bl sub_8157790
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08157888
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157890
	.pool
_08157888:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157890:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157850

	thumb_func_start sub_8157898
sub_8157898: @ 8157898
	push {r4-r6,lr}
	movs r5, 0
	ldr r3, =gUnknown_02039E00
	ldr r6, =gUnknown_02039F34
	ldr r4, [r6]
	ldr r1, [r4, 0xC]
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r1, 0x41
	ldrb r2, [r1]
	lsls r1, r2, 6
	adds r0, r1
	adds r3, 0x1E
	adds r0, r3
	ldrh r3, [r0]
	ldr r1, [r4, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	beq _081578D0
	adds r1, r3, 0
	bl AreMovesContestCombo
	lsls r0, 24
	lsrs r5, r0, 24
_081578D0:
	cmp r5, 0
	beq _081578D6
	movs r5, 0x1
_081578D6:
	ldr r0, [r6]
	ldr r0, [r0, 0xC]
	strh r5, [r0, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157898

	thumb_func_start sub_81578F8
sub_81578F8: @ 81578F8
	push {lr}
	bl sub_8157898
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157930
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157938
	.pool
_08157930:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157938:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81578F8

	thumb_func_start sub_8157940
sub_8157940: @ 8157940
	push {lr}
	bl sub_8157898
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08157978
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157980
	.pool
_08157978:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157980:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157940

	thumb_func_start sub_8157988
sub_8157988: @ 8157988
	push {r4,r5,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r5, [r1, 0xC]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0xD
	ldrsb r0, [r1, r0]
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	asrs r0, 24
	strh r0, [r5, 0x18]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157988

	thumb_func_start sub_81579CC
sub_81579CC: @ 81579CC
	push {lr}
	bl sub_8157988
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _08157A08
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157A0C
	.pool
_08157A08:
	adds r0, r2, 0x5
	str r0, [r3]
_08157A0C:
	pop {r0}
	bx r0
	thumb_func_end sub_81579CC

	thumb_func_start sub_8157A10
sub_8157A10: @ 8157A10
	push {lr}
	bl sub_8157988
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _08157A4C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157A50
	.pool
_08157A4C:
	adds r0, r2, 0x5
	str r0, [r3]
_08157A50:
	pop {r0}
	bx r0
	thumb_func_end sub_8157A10

	thumb_func_start sub_8157A54
sub_8157A54: @ 8157A54
	push {lr}
	bl sub_8157988
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08157A90
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157A94
	.pool
_08157A90:
	adds r0, r2, 0x5
	str r0, [r3]
_08157A94:
	pop {r0}
	bx r0
	thumb_func_end sub_8157A54

	thumb_func_start sub_8157A98
sub_8157A98: @ 8157A98
	push {lr}
	bl sub_8157988
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08157AD4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157AD8
	.pool
_08157AD4:
	adds r0, r2, 0x5
	str r0, [r3]
_08157AD8:
	pop {r0}
	bx r0
	thumb_func_end sub_8157A98

	thumb_func_start sub_8157ADC
sub_8157ADC: @ 8157ADC
	push {r4-r6,lr}
	movs r6, 0
	ldr r5, =gAIScriptPtr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80DE1E8
	lsls r0, 24
	cmp r0, 0
	beq _08157B18
	ldr r2, =gContestMoves
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x8]
	lsls r0, 3
	adds r0, r2
	ldrb r1, [r0, 0x2]
	negs r0, r1
	orrs r0, r1
	lsrs r6, r0, 31
_08157B18:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	strh r6, [r0, 0x18]
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157ADC

	thumb_func_start sub_8157B38
sub_8157B38: @ 8157B38
	push {lr}
	bl sub_8157ADC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _08157B74
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157B78
	.pool
_08157B74:
	adds r0, r2, 0x5
	str r0, [r3]
_08157B78:
	pop {r0}
	bx r0
	thumb_func_end sub_8157B38

	thumb_func_start sub_8157B7C
sub_8157B7C: @ 8157B7C
	push {lr}
	bl sub_8157ADC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _08157BB8
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157BBC
	.pool
_08157BB8:
	adds r0, r2, 0x5
	str r0, [r3]
_08157BBC:
	pop {r0}
	bx r0
	thumb_func_end sub_8157B7C

	thumb_func_start sub_8157BC0
sub_8157BC0: @ 8157BC0
	push {lr}
	bl sub_8157ADC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08157BFC
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157C00
	.pool
_08157BFC:
	adds r0, r2, 0x5
	str r0, [r3]
_08157C00:
	pop {r0}
	bx r0
	thumb_func_end sub_8157BC0

	thumb_func_start sub_8157C04
sub_8157C04: @ 8157C04
	push {lr}
	bl sub_8157ADC
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08157C40
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157C44
	.pool
_08157C40:
	adds r0, r2, 0x5
	str r0, [r3]
_08157C44:
	pop {r0}
	bx r0
	thumb_func_end sub_8157C04

	thumb_func_start sub_8157C48
sub_8157C48: @ 8157C48
	push {lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	lsrs r0, 24
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	beq _08157C74
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	movs r0, 0
	b _08157C7C
	.pool
_08157C74:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	movs r0, 0x1
_08157C7C:
	strh r0, [r1, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157C48

	thumb_func_start sub_8157C94
sub_8157C94: @ 8157C94
	push {lr}
	bl sub_8157C48
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157CCC
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157CD4
	.pool
_08157CCC:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157CD4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157C94

	thumb_func_start sub_8157CDC
sub_8157CDC: @ 8157CDC
	push {lr}
	bl sub_8157C48
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08157D14
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157D1C
	.pool
_08157D14:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157D1C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157CDC

	thumb_func_start sub_8157D24
sub_8157D24: @ 8157D24
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r3, [r1, 0xC]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x15]
	lsls r0, 28
	lsrs r0, 31
	strh r0, [r3, 0x18]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157D24

	thumb_func_start sub_8157D60
sub_8157D60: @ 8157D60
	push {lr}
	bl sub_8157D24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157D98
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157DA0
	.pool
_08157D98:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157DA0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157D60

	thumb_func_start sub_8157DA8
sub_8157DA8: @ 8157DA8
	push {lr}
	bl sub_8157D24
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08157DE0
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157DE8
	.pool
_08157DE0:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157DE8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157DA8

	thumb_func_start sub_8157DF0
sub_8157DF0: @ 8157DF0
	push {r4,r5,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r5, [r1, 0xC]
	ldr r3, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r3
	adds r0, r5, 0
	adds r0, 0x41
	ldrb r2, [r0]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r1, 0x4]
	ldrh r0, [r0, 0x4]
	subs r1, r0
	strh r1, [r5, 0x18]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157DF0

	thumb_func_start sub_8157E3C
sub_8157E3C: @ 8157E3C
	push {lr}
	bl sub_8157DF0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _08157E74
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157E7C
	.pool
_08157E74:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157E7C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157E3C

	thumb_func_start sub_8157E84
sub_8157E84: @ 8157E84
	push {lr}
	bl sub_8157DF0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _08157EBC
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157EC4
	.pool
_08157EBC:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157EC4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157E84

	thumb_func_start sub_8157ECC
sub_8157ECC: @ 8157ECC
	push {lr}
	bl sub_8157DF0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08157F04
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157F0C
	.pool
_08157F04:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157F0C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157ECC

	thumb_func_start sub_8157F14
sub_8157F14: @ 8157F14
	push {lr}
	bl sub_8157DF0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08157F4C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157F54
	.pool
_08157F4C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157F54:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157F14

	thumb_func_start sub_8157F5C
sub_8157F5C: @ 8157F5C
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r3, [r1, 0xC]
	ldr r2, =gUnknown_02039F00
	lsrs r0, 23
	adds r0, r2
	adds r1, r3, 0
	adds r1, 0x41
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r3, 0x18]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157F5C

	thumb_func_start sub_8157FA0
sub_8157FA0: @ 8157FA0
	push {lr}
	bl sub_8157F5C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _08157FD8
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08157FE0
	.pool
_08157FD8:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08157FE0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157FA0

	thumb_func_start sub_8157FE8
sub_8157FE8: @ 8157FE8
	push {lr}
	bl sub_8157F5C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _08158020
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158028
	.pool
_08158020:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08158028:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8157FE8

	thumb_func_start sub_8158030
sub_8158030: @ 8158030
	push {lr}
	bl sub_8157F5C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158068
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158070
	.pool
_08158068:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08158070:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158030

	thumb_func_start sub_8158078
sub_8158078: @ 8158078
	push {lr}
	bl sub_8157F5C
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081580B0
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081580B8
	.pool
_081580B0:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_081580B8:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158078

	thumb_func_start sub_81580C0
sub_81580C0: @ 81580C0
	push {r4,r5,lr}
	ldr r5, =gAIScriptPtr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldr r1, =gUnknown_02039F34
	ldr r4, [r1]
	ldr r1, [r4]
	lsrs r0, 23
	lsls r2, 3
	adds r0, r2
	adds r1, 0x1C
	adds r1, r0
	ldrh r0, [r1]
	ldr r2, [r4, 0xC]
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2, 0x18]
	adds r3, 0x3
	str r3, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81580C0

	thumb_func_start sub_8158108
sub_8158108: @ 8158108
	push {lr}
	bl sub_81580C0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _08158144
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158148
	.pool
_08158144:
	adds r0, r2, 0x5
	str r0, [r3]
_08158148:
	pop {r0}
	bx r0
	thumb_func_end sub_8158108

	thumb_func_start sub_815814C
sub_815814C: @ 815814C
	push {lr}
	bl sub_81580C0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _08158188
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815818C
	.pool
_08158188:
	adds r0, r2, 0x5
	str r0, [r3]
_0815818C:
	pop {r0}
	bx r0
	thumb_func_end sub_815814C

	thumb_func_start sub_8158190
sub_8158190: @ 8158190
	push {lr}
	bl sub_81580C0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _081581CC
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081581D0
	.pool
_081581CC:
	adds r0, r2, 0x5
	str r0, [r3]
_081581D0:
	pop {r0}
	bx r0
	thumb_func_end sub_8158190

	thumb_func_start sub_81581D4
sub_81581D4: @ 81581D4
	push {lr}
	bl sub_81580C0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08158210
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158214
	.pool
_08158210:
	adds r0, r2, 0x5
	str r0, [r3]
_08158214:
	pop {r0}
	bx r0
	thumb_func_end sub_81581D4

	thumb_func_start sub_8158218
sub_8158218: @ 8158218
	push {r4,r5,lr}
	ldr r5, =gAIScriptPtr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldr r1, =gUnknown_02039F34
	ldr r4, [r1]
	ldr r1, [r4]
	lsls r2, 2
	adds r0, r2
	adds r1, 0x44
	adds r1, r0
	ldr r2, [r4, 0xC]
	movs r0, 0
	ldrsb r0, [r1, r0]
	strh r0, [r2, 0x18]
	adds r3, 0x3
	str r3, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158218

	thumb_func_start sub_8158254
sub_8158254: @ 8158254
	push {lr}
	bl sub_8158218
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bge _08158290
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158294
	.pool
_08158290:
	adds r0, r2, 0x5
	str r0, [r3]
_08158294:
	pop {r0}
	bx r0
	thumb_func_end sub_8158254

	thumb_func_start sub_8158298
sub_8158298: @ 8158298
	push {lr}
	bl sub_8158218
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	ble _081582D4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081582D8
	.pool
_081582D4:
	adds r0, r2, 0x5
	str r0, [r3]
_081582D8:
	pop {r0}
	bx r0
	thumb_func_end sub_8158298

	thumb_func_start sub_81582DC
sub_81582DC: @ 81582DC
	push {lr}
	bl sub_8158218
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _08158318
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815831C
	.pool
_08158318:
	adds r0, r2, 0x5
	str r0, [r3]
_0815831C:
	pop {r0}
	bx r0
	thumb_func_end sub_81582DC

	thumb_func_start sub_8158320
sub_8158320: @ 8158320
	push {lr}
	bl sub_8158218
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _0815835C
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158360
	.pool
_0815835C:
	adds r0, r2, 0x5
	str r0, [r3]
_08158360:
	pop {r0}
	bx r0
	thumb_func_end sub_8158320

	thumb_func_start sub_8158364
sub_8158364: @ 8158364
	push {r4,r5,lr}
	ldr r5, =gAIScriptPtr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl sub_81564AC
	lsls r0, 24
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldr r1, =gUnknown_02039F34
	ldr r4, [r1]
	ldr r1, [r4]
	lsrs r0, 23
	lsls r2, 3
	adds r0, r2
	adds r1, 0x1C
	adds r1, r0
	ldrh r0, [r1]
	ldr r4, [r4, 0xC]
	ldr r2, =gContestEffects
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r4, 0x18]
	adds r3, 0x3
	str r3, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158364

	thumb_func_start sub_81583B8
sub_81583B8: @ 81583B8
	push {lr}
	bl sub_8158364
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	bne _081583F4
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081583F8
	.pool
_081583F4:
	adds r0, r2, 0x5
	str r0, [r3]
_081583F8:
	pop {r0}
	bx r0
	thumb_func_end sub_81583B8

	thumb_func_start sub_81583FC
sub_81583FC: @ 81583FC
	push {lr}
	bl sub_8158364
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	cmp r0, r1
	beq _08158438
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0815843C
	.pool
_08158438:
	adds r0, r2, 0x5
	str r0, [r3]
_0815843C:
	pop {r0}
	bx r0
	thumb_func_end sub_81583FC

	thumb_func_start sub_8158440
sub_8158440: @ 8158440
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r3, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	lsls r0, 1
	adds r1, r3, 0
	adds r1, 0x1A
	adds r1, r0
	ldrh r0, [r3, 0x18]
	strh r0, [r1]
	adds r2, 0x2
	str r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158440

	thumb_func_start sub_815846C
sub_815846C: @ 815846C
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r3, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	lsls r0, 1
	adds r3, 0x1A
	adds r3, r0
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r3]
	adds r2, 0x4
	str r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815846C

	thumb_func_start sub_815849C
sub_815849C: @ 815849C
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r2, 0x1A
	adds r2, r0
	movs r1, 0x2
	ldrsb r1, [r3, r1]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrh r0, [r2]
	adds r1, r0
	strh r1, [r2]
	adds r3, 0x4
	str r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_815849C

	thumb_func_start sub_81584D4
sub_81584D4: @ 81584D4
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	lsls r1, 1
	adds r2, 0x1A
	adds r1, r2, r1
	ldrb r0, [r3, 0x2]
	lsls r0, 1
	adds r2, r0
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	adds r3, 0x3
	str r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81584D4

	thumb_func_start sub_8158508
sub_8158508: @ 8158508
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	lsls r1, 1
	adds r2, 0x1A
	adds r1, r2, r1
	ldrb r0, [r3, 0x2]
	lsls r0, 1
	adds r2, r0
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	adds r3, 0x3
	str r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158508

	thumb_func_start sub_815853C
sub_815853C: @ 815853C
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r1, 0x1A
	adds r1, r0
	movs r0, 0
	ldrsh r2, [r1, r0]
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	cmp r2, r1
	bge _08158580
	ldrb r1, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08158586
	.pool
_08158580:
	adds r0, r3, 0
	adds r0, 0x8
	str r0, [r4]
_08158586:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815853C

	thumb_func_start sub_815858C
sub_815858C: @ 815858C
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r1, 0x1A
	adds r1, r0
	movs r0, 0
	ldrsh r2, [r1, r0]
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	cmp r2, r1
	ble _081585D0
	ldrb r1, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _081585D6
	.pool
_081585D0:
	adds r0, r3, 0
	adds r0, 0x8
	str r0, [r4]
_081585D6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815858C

	thumb_func_start sub_81585DC
sub_81585DC: @ 81585DC
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r1, 0x1A
	adds r1, r0
	movs r0, 0
	ldrsh r2, [r1, r0]
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	cmp r2, r1
	bne _08158620
	ldrb r1, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08158626
	.pool
_08158620:
	adds r0, r3, 0
	adds r0, 0x8
	str r0, [r4]
_08158626:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81585DC

	thumb_func_start sub_815862C
sub_815862C: @ 815862C
	push {r4,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r1, 0x1A
	adds r1, r0
	movs r0, 0
	ldrsh r2, [r1, r0]
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	cmp r2, r1
	beq _08158670
	ldrb r1, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08158676
	.pool
_08158670:
	adds r0, r3, 0
	adds r0, 0x8
	str r0, [r4]
_08158676:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_815862C

	thumb_func_start sub_815867C
sub_815867C: @ 815867C
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	lsls r1, 1
	adds r2, 0x1A
	adds r1, r2, r1
	ldrb r0, [r3, 0x2]
	lsls r0, 1
	adds r2, r0
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bge _081586C4
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _081586C8
	.pool
_081586C4:
	adds r0, r3, 0x7
	str r0, [r4]
_081586C8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815867C

	thumb_func_start sub_81586D0
sub_81586D0: @ 81586D0
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	lsls r1, 1
	adds r2, 0x1A
	adds r1, r2, r1
	ldrb r0, [r3, 0x2]
	lsls r0, 1
	adds r2, r0
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	ble _08158718
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0815871C
	.pool
_08158718:
	adds r0, r3, 0x7
	str r0, [r4]
_0815871C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81586D0

	thumb_func_start sub_8158724
sub_8158724: @ 8158724
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	lsls r1, 1
	adds r2, 0x1A
	adds r1, r2, r1
	ldrb r0, [r3, 0x2]
	lsls r0, 1
	adds r2, r0
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _0815876C
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08158770
	.pool
_0815876C:
	adds r0, r3, 0x7
	str r0, [r4]
_08158770:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8158724

	thumb_func_start sub_8158778
sub_8158778: @ 8158778
	push {r4,r5,lr}
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	lsls r1, 1
	adds r2, 0x1A
	adds r1, r2, r1
	ldrb r0, [r3, 0x2]
	lsls r0, 1
	adds r2, r0
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	beq _081587C0
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _081587C4
	.pool
_081587C0:
	adds r0, r3, 0x7
	str r0, [r4]
_081587C4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8158778

	thumb_func_start sub_81587CC
sub_81587CC: @ 81587CC
	push {r4,r5,lr}
	bl Random
	movs r2, 0xFF
	ands r2, r0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r1, 0x1A
	adds r1, r0
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r2, r0
	bge _08158810
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08158814
	.pool
_08158810:
	adds r0, r3, 0x6
	str r0, [r4]
_08158814:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81587CC

	thumb_func_start sub_815881C
sub_815881C: @ 815881C
	push {r4,r5,lr}
	bl Random
	movs r2, 0xFF
	ands r2, r0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r1, [r0, 0xC]
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	lsls r0, 1
	adds r1, 0x1A
	adds r1, r0
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r2, r0
	ble _08158860
	ldrb r1, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08158864
	.pool
_08158860:
	adds r0, r3, 0x6
	str r0, [r4]
_08158864:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_815881C

	thumb_func_start sub_815886C
sub_815886C: @ 815886C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	bx lr
	.pool
	thumb_func_end sub_815886C

	thumb_func_start dp15_call
dp15_call: @ 815888C
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	adds r0, 0x5
	bl sub_81588E0
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_call

	thumb_func_start sub_81588BC
sub_81588BC: @ 81588BC
	push {lr}
	bl sub_8158908
	lsls r0, 24
	cmp r0, 0
	bne _081588D6
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	ldrb r1, [r2, 0x9]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
_081588D6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81588BC

	thumb_func_start sub_81588E0
sub_81588E0: @ 81588E0
	push {r4,lr}
	ldr r1, =gUnknown_02039F34
	ldr r1, [r1]
	ldr r3, [r1, 0xC]
	adds r4, r3, 0
	adds r4, 0x40
	ldrb r1, [r4]
	adds r2, r1, 0x1
	strb r2, [r4]
	lsls r1, 24
	lsrs r1, 22
	adds r3, 0x20
	adds r3, r1
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81588E0

	thumb_func_start sub_8158908
sub_8158908: @ 8158908
	push {lr}
	ldr r3, =gUnknown_02039F34
	ldr r0, [r3]
	ldr r0, [r0, 0xC]
	adds r1, r0, 0
	adds r1, 0x40
	ldrb r0, [r1]
	cmp r0, 0
	bne _08158924
	movs r0, 0
	b _08158940
	.pool
_08158924:
	subs r0, 0x1
	strb r0, [r1]
	ldr r2, =gAIScriptPtr
	ldr r0, [r3]
	ldr r1, [r0, 0xC]
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	movs r0, 0x1
_08158940:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8158908

	thumb_func_start sub_8158948
sub_8158948: @ 8158948
	push {r4-r6,lr}
	movs r5, 0
	movs r4, 0
	ldr r6, =gUnknown_02039E1E
_08158950:
	lsls r1, r4, 1
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	adds r1, r6
	ldrh r0, [r1]
	cmp r0, 0
	beq _08158980
	bl sub_80DD9F0
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	bne _08158980
	movs r5, 0x1
	b _08158986
	.pool
_08158980:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08158950
_08158986:
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	strh r5, [r0, 0x18]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158948

	thumb_func_start sub_81589A4
sub_81589A4: @ 81589A4
	push {lr}
	bl sub_8158948
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _081589DC
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081589E4
	.pool
_081589DC:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_081589E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81589A4

	thumb_func_start sub_81589EC
sub_81589EC: @ 81589EC
	push {lr}
	bl sub_8158948
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158A24
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158A2C
	.pool
_08158A24:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08158A2C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81589EC

	thumb_func_start sub_8158A34
sub_8158A34: @ 8158A34
	push {r4-r6,lr}
	movs r6, 0
	ldr r3, =gAIScriptPtr
	ldr r0, [r3]
	ldrb r5, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r5, r0
	movs r4, 0
	ldr r0, =gUnknown_02039E00
	mov r12, r0
	ldr r2, =gUnknown_02039F34
	ldr r0, [r2]
	ldr r0, [r0, 0xC]
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	mov r1, r12
	adds r1, 0x1E
	adds r0, r1
	ldrh r0, [r0]
	b _08158A88
	.pool
_08158A6C:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08158A8E
	lsls r1, r4, 1
	ldr r0, [r2]
	ldr r0, [r0, 0xC]
	adds r0, 0x41
	ldrb r0, [r0]
	lsls r0, 6
	adds r1, r0
	mov r0, r12
	adds r0, 0x1E
	adds r1, r0
	ldrh r0, [r1]
_08158A88:
	cmp r0, r5
	bne _08158A6C
	movs r6, 0x1
_08158A8E:
	ldr r0, [r2]
	ldr r0, [r0, 0xC]
	strh r6, [r0, 0x18]
	ldr r0, [r3]
	adds r0, 0x3
	str r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8158A34

	thumb_func_start sub_8158AA0
sub_8158AA0: @ 8158AA0
	push {lr}
	bl sub_8158A34
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _08158AD8
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158AE0
	.pool
_08158AD8:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08158AE0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158AA0

	thumb_func_start sub_8158AE8
sub_8158AE8: @ 8158AE8
	push {lr}
	bl sub_8158A34
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08158B20
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08158B28
	.pool
_08158B20:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x4
	str r0, [r1]
_08158B28:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8158AE8

	.align 2, 0 @ Don't pad with nop.
