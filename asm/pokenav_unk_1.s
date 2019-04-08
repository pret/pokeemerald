	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

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
