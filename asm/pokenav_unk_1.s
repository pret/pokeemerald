	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

@ File centered around AllocSubstruct(1)

	thumb_func_start sub_81C9268
sub_81C9268: @ 81C9268
	push {r4,lr}
	movs r4, 0
	movs r0, 0x98
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081C928A
	movs r4, 0x1
	ldr r0, =0x0000089b
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _081C928A
	movs r4, 0x2
_081C928A:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C9268

	thumb_func_start sub_81C9298
sub_81C9298: @ 81C9298
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081C92C4
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4]
	strh r1, [r4, 0x2]
	strh r1, [r4, 0x4]
	strh r1, [r4, 0x6]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C92C6
_081C92C4:
	movs r0, 0
_081C92C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9298

	thumb_func_start sub_81C92CC
sub_81C92CC: @ 81C92CC
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081C92FA
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	strh r0, [r4]
	movs r0, 0x2
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r1, [r4, 0x6]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C92FC
_081C92FA:
	movs r0, 0
_081C92FC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C92CC

	thumb_func_start sub_81C9304
sub_81C9304: @ 81C9304
	push {r4,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081C932E
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0x3
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9330
_081C932E:
	movs r0, 0
_081C9330:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9304

	thumb_func_start sub_81C9338
sub_81C9338: @ 81C9338
	push {lr}
	movs r0, 0x1
	movs r1, 0x10
	bl AllocSubstruct
	adds r2, r0, 0
	cmp r2, 0
	beq _081C9360
	movs r0, 0
	movs r1, 0x3
	strh r1, [r2]
	strh r0, [r2, 0x2]
	movs r1, 0x5
	strh r1, [r2, 0x4]
	strh r0, [r2, 0x6]
	adds r0, r2, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9362
_081C9360:
	movs r0, 0
_081C9362:
	pop {r1}
	bx r1
	thumb_func_end sub_81C9338

	thumb_func_start sub_81C9368
sub_81C9368: @ 81C9368
	push {r4,r5,lr}
	movs r0, 0x1
	movs r1, 0x10
	bl AllocSubstruct
	adds r5, r0, 0
	cmp r5, 0
	beq _081C9394
	movs r4, 0
	movs r0, 0x4
	strh r0, [r5]
	bl sub_81C76AC
	strh r0, [r5, 0x2]
	adds r0, 0x8
	strh r0, [r5, 0x4]
	strh r4, [r5, 0x6]
	adds r0, r5, 0
	bl sub_81C939C
	movs r0, 0x1
	b _081C9396
_081C9394:
	movs r0, 0
_081C9396:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9368

	thumb_func_start sub_81C939C
sub_81C939C: @ 81C939C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4]
	cmp r0, 0x4
	bhi _081C93E0
	lsls r0, 2
	ldr r1, =_081C93B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C93B4:
	.4byte _081C93C8
	.4byte _081C93CE
	.4byte _081C93CE
	.4byte _081C93D4
	.4byte _081C93DC
_081C93C8:
	movs r0, 0
	bl SetPokenavMode
_081C93CE:
	bl sub_81C93EC
	b _081C93DE
_081C93D4:
	ldr r0, =sub_81C963C
	b _081C93DE
	.pool
_081C93DC:
	ldr r0, =sub_81C96FC
_081C93DE:
	str r0, [r4, 0xC]
_081C93E0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C939C

	thumb_func_start sub_81C93EC
sub_81C93EC: @ 81C93EC
	push {lr}
	bl GetPokenavMode
	cmp r0, 0x1
	beq _081C9408
	cmp r0, 0x1
	bcc _081C93FE
	cmp r0, 0x2
	beq _081C9410
_081C93FE:
	ldr r0, =sub_81C943C
	b _081C9412
	.pool
_081C9408:
	ldr r0, =sub_81C9520
	b _081C9412
	.pool
_081C9410:
	ldr r0, =c2_pre_battle_1
_081C9412:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C93EC

	thumb_func_start sub_81C941C
sub_81C941C: @ 81C941C
	push {lr}
	movs r0, 0x1
	bl GetSubstructPtr
	ldr r1, [r0, 0xC]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81C941C

	thumb_func_start sub_81C9430
sub_81C9430: @ 81C9430
	push {lr}
	movs r0, 0x1
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_81C9430

	thumb_func_start sub_81C943C
sub_81C943C: @ 81C943C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C944C
	movs r0, 0x1
	b _081C951A
_081C944C:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	beq _081C9508
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x4
	bhi _081C9508
	lsls r0, 2
	ldr r1, =_081C9488
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C9488:
	.4byte _081C949C
	.4byte _081C94BC
	.4byte _081C94D4
	.4byte _081C94E0
	.4byte _081C9516
_081C949C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r1, [r0, 0x15]
	movs r0, 0x8
	ands r0, r1
	movs r1, 0x1
	cmp r0, 0
	beq _081C94AE
	movs r1, 0x2
_081C94AE:
	strh r1, [r4, 0x6]
	ldr r1, =0x000186a6
	b _081C94EE
	.pool
_081C94BC:
	movs r1, 0
	movs r0, 0x3
	strh r0, [r4]
	strh r1, [r4, 0x2]
	ldrb r0, [r3, 0x12]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C963C
	str r0, [r4, 0xC]
	movs r0, 0x2
	b _081C951A
	.pool
_081C94D4:
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	b _081C94EE
	.pool
_081C94E0:
	bl CanViewRibbonsMenu
	cmp r0, 0
	beq _081C94FC
	movs r0, 0x9
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ac
_081C94EE:
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C951A
	.pool
_081C94FC:
	ldr r0, =sub_81C9600
	str r0, [r4, 0xC]
	movs r0, 0x6
	b _081C951A
	.pool
_081C9508:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081C9516
	movs r0, 0
	b _081C951A
_081C9516:
	movs r0, 0x1
	negs r0, r0
_081C951A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C943C

	thumb_func_start sub_81C9520
sub_81C9520: @ 81C9520
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9530
	movs r0, 0x1
	b _081C9580
_081C9530:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C9570
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _081C9578
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C9580
	.pool
_081C9570:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C957E
_081C9578:
	movs r0, 0x20
	bl PlaySE
_081C957E:
	movs r0, 0
_081C9580:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9520

	thumb_func_start c2_pre_battle_1
c2_pre_battle_1: @ 81C9588
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9598
	movs r0, 0x1
	b _081C95F8
_081C9598:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C95E8
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _081C95D4
	cmp r0, 0x4
	beq _081C95F4
	movs r0, 0x20
	bl PlaySE
	movs r0, 0
	b _081C95F8
	.pool
_081C95D4:
	movs r0, 0x6
	strh r0, [r4, 0x6]
	ldr r1, =0x000186ab
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C95F8
	.pool
_081C95E8:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081C95F4
	movs r0, 0
	b _081C95F8
_081C95F4:
	movs r0, 0x1
	negs r0, r0
_081C95F8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end c2_pre_battle_1

	thumb_func_start sub_81C9600
sub_81C9600: @ 81C9600
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C9616
	bl sub_81C93EC
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C9634
_081C9616:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081C962C
	movs r0, 0
	b _081C9634
	.pool
_081C962C:
	bl sub_81C93EC
	str r0, [r4, 0xC]
	movs r0, 0x7
_081C9634:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9600

	thumb_func_start sub_81C963C
sub_81C963C: @ 81C963C
	push {r4-r6,lr}
	adds r4, r0, 0
	bl sub_81C9814
	adds r3, r0, 0
	cmp r3, 0
	beq _081C964E
	movs r0, 0x1
	b _081C96F6
_081C964E:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _081C96B8
	ldr r5, =gUnknown_0861FC59
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	ldrh r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 1
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _081C968E
	cmp r0, 0x6
	bgt _081C9688
	cmp r0, 0x5
	beq _081C96A4
	b _081C96B8
	.pool
_081C9688:
	cmp r0, 0x7
	beq _081C96E4
	b _081C96B8
_081C968E:
	movs r0, 0x4
	strh r0, [r4]
	strh r3, [r4, 0x2]
	ldrb r0, [r5, 0x18]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C96FC
	str r0, [r4, 0xC]
	movs r0, 0x4
	b _081C96F6
	.pool
_081C96A4:
	strh r3, [r4, 0x6]
	ldr r1, =0x000186a7
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x8
	b _081C96F6
	.pool
_081C96B8:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C96F4
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_0861FC54
	ldrh r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C96E4
	strh r0, [r4, 0x2]
	ldr r0, =sub_81C9798
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C96F6
	.pool
_081C96E4:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81C97C0
	movs r0, 0x3
	b _081C96F6
_081C96F4:
	movs r0, 0
_081C96F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C963C

	thumb_func_start sub_81C96FC
sub_81C96FC: @ 81C96FC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9814
	cmp r0, 0
	beq _081C970C
	movs r0, 0x1
	b _081C9792
_081C970C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C9754
	ldr r3, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrh r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	adds r1, r0
	adds r1, r3
	ldrb r0, [r1]
	cmp r0, 0xD
	beq _081C9780
	subs r0, 0x8
	bl sub_81C7694
	ldr r1, =0x000186a8
	adds r0, r4, 0
	bl sub_81C97B0
	movs r0, 0x3
	strh r0, [r4, 0x6]
	movs r0, 0x8
	b _081C9792
	.pool
_081C9754:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C9790
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r1, =gUnknown_0861FC54
	ldrh r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C9780
	strh r0, [r4, 0x2]
	ldr r0, =sub_81C97A4
	str r0, [r4, 0xC]
	movs r0, 0x1
	b _081C9792
	.pool
_081C9780:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81C97F8
	movs r0, 0x5
	b _081C9792
_081C9790:
	movs r0, 0
_081C9792:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C96FC

	thumb_func_start sub_81C9798
sub_81C9798: @ 81C9798
	push {lr}
	bl sub_81C97C0
	movs r0, 0x3
	pop {r1}
	bx r1
	thumb_func_end sub_81C9798

	thumb_func_start sub_81C97A4
sub_81C97A4: @ 81C97A4
	push {lr}
	bl sub_81C97F8
	movs r0, 0x5
	pop {r1}
	bx r1
	thumb_func_end sub_81C97A4

	thumb_func_start sub_81C97B0
sub_81C97B0: @ 81C97B0
	str r1, [r0, 0x8]
	ldr r1, =sub_81C97BC
	str r1, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C97B0

	thumb_func_start sub_81C97BC
sub_81C97BC: @ 81C97BC
	ldr r0, [r0, 0x8]
	bx lr
	thumb_func_end sub_81C97BC

	thumb_func_start sub_81C97C0
sub_81C97C0: @ 81C97C0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_81C9268
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	ldr r2, =gUnknown_0861FC59
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 1
	adds r0, 0x1
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r4, 0x4]
	ldr r0, =sub_81C943C
	str r0, [r4, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C97C0

	thumb_func_start sub_81C97F8
sub_81C97F8: @ 81C97F8
	movs r1, 0x3
	strh r1, [r0]
	movs r1, 0x1
	strh r1, [r0, 0x2]
	ldr r1, =gUnknown_0861FC59
	ldrb r1, [r1, 0x13]
	strh r1, [r0, 0x4]
	ldr r1, =sub_81C963C
	str r1, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_81C97F8

	thumb_func_start sub_81C9814
sub_81C9814: @ 81C9814
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C9848
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	ldrh r3, [r4]
	cmp r0, 0
	bge _081C986A
	ldr r0, =gUnknown_0861FC54
	adds r0, r3, r0
	ldrb r0, [r0]
	strh r0, [r4, 0x2]
	b _081C986A
	.pool
_081C9848:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C988C
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r0, =gUnknown_0861FC54
	ldrh r1, [r4]
	adds r0, r1, r0
	adds r3, r1, 0
	ldrb r0, [r0]
	cmp r2, r0
	ble _081C986A
	strh r5, [r4, 0x2]
_081C986A:
	ldr r2, =gUnknown_0861FC59
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 1
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	strh r0, [r4, 0x4]
	movs r0, 0x1
	b _081C988E
	.pool
_081C988C:
	movs r0, 0
_081C988E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81C9814
    
	thumb_func_start sub_81C9894
sub_81C9894: @ 81C9894
	push {lr}
	movs r0, 0x1
	bl GetSubstructPtr
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81C9894

	thumb_func_start sub_81C98A4
sub_81C98A4: @ 81C98A4
	push {lr}
	movs r0, 0x1
	bl GetSubstructPtr
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98A4

	thumb_func_start sub_81C98B4
sub_81C98B4: @ 81C98B4
	push {lr}
	movs r0, 0x1
	bl GetSubstructPtr
	ldrh r0, [r0, 0x4]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98B4

	thumb_func_start sub_81C98C4
sub_81C98C4: @ 81C98C4
	push {lr}
	movs r0, 0x1
	bl GetSubstructPtr
	ldrh r0, [r0, 0x6]
	pop {r1}
	bx r1
	thumb_func_end sub_81C98C4

	.align 2, 0 @ Don't pad with nop.
