	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

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
