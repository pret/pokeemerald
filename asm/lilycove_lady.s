	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_818E604
sub_818E604: @ 818E604
	push {r4,lr}
	ldr r4, =gUnknown_0203CD6C
	ldr r1, [r4]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x2]
	ldr r0, [r4]
	strb r1, [r0, 0x3]
	ldr r0, [r4]
	strb r1, [r0, 0xC]
	bl Random
	ldr r4, [r4]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	strb r0, [r4, 0xD]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E604

	thumb_func_start SetLilycoveContestLady
SetLilycoveContestLady: @ 818E638
	push {r4,lr}
	ldr r4, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r4]
	movs r2, 0
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r4]
	strb r2, [r0, 0x1]
	bl sub_818E604
	ldr r1, [r4]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r1, 0xE]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetLilycoveContestLady

	thumb_func_start sub_818E674
sub_818E674: @ 818E674
	push {lr}
	ldr r2, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	str r0, [r2]
	movs r3, 0
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r2]
	strb r3, [r0, 0x1]
	ldr r2, [r2]
	ldrb r0, [r2, 0x2]
	cmp r0, 0x5
	beq _0818E69A
	ldrb r0, [r2, 0x3]
	cmp r0, 0x5
	bne _0818E69E
_0818E69A:
	bl sub_818E604
_0818E69E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E674

	thumb_func_start sub_818E6B0
sub_818E6B0: @ 818E6B0
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r4, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003b58
	adds r1, r0, r3
	str r1, [r4]
	ldrb r0, [r1, 0xC]
	cmp r0, r2
	bhi _0818E6EA
	strb r2, [r1, 0xC]
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0xFF
	movs r2, 0x8
	bl memset
	ldr r1, [r4]
	ldr r0, =gSaveBlock2Ptr
	adds r1, 0x4
	ldr r0, [r0]
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	ldr r1, [r4]
	ldr r0, =gGameLanguage
	ldrb r0, [r0]
	strb r0, [r1, 0xE]
_0818E6EA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E6B0

	thumb_func_start sub_818E704
sub_818E704: @ 818E704
	push {r4,r5,lr}
	adds r2, r0, 0
	movs r3, 0
	movs r4, 0
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r5, =0x00003b58
	adds r0, r5
	str r0, [r1]
	ldrb r0, [r0, 0xD]
	adds r5, r1, 0
	cmp r0, 0x4
	bhi _0818E76A
	lsls r0, 2
	ldr r1, =_0818E73C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0818E73C:
	.4byte _0818E750
	.4byte _0818E754
	.4byte _0818E758
	.4byte _0818E75C
	.4byte _0818E760
_0818E750:
	ldrb r0, [r2, 0x1]
	b _0818E762
_0818E754:
	ldrb r0, [r2, 0x2]
	b _0818E762
_0818E758:
	ldrb r0, [r2, 0x3]
	b _0818E762
_0818E75C:
	ldrb r0, [r2, 0x4]
	b _0818E762
_0818E760:
	ldrb r0, [r2, 0x5]
_0818E762:
	cmp r0, 0
	beq _0818E76A
	adds r3, r0, 0
	movs r4, 0x1
_0818E76A:
	cmp r4, 0x1
	bne _0818E784
	adds r0, r3, 0
	bl sub_818E6B0
	ldr r0, =gUnknown_0203CD6C
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	adds r0, 0x1
	strb r0, [r1, 0x2]
	b _0818E78C
	.pool
_0818E784:
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
_0818E78C:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_818E704

	thumb_func_start sub_818E794
sub_818E794: @ 818E794
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r2, =0x00003b58
	adds r1, r2
	str r1, [r4]
	ldr r2, =gUnknown_0860B324
	ldrb r1, [r1, 0xD]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r1, =gUnknown_0860B310
	ldr r0, [r4]
	ldrb r0, [r0, 0xD]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl StringCopy10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E794

	thumb_func_start sub_818E7E0
sub_818E7E0: @ 818E7E0
	push {r4,lr}
	adds r3, r1, 0
	ldr r2, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r4, =0x00003b58
	adds r1, r4
	str r1, [r2]
	ldrb r2, [r1, 0xD]
	strb r2, [r0]
	ldr r2, =gUnknown_0860B310
	ldrb r0, [r1, 0xD]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	adds r0, r3, 0
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E7E0

	thumb_func_start sub_818E81C
sub_818E81C: @ 818E81C
	push {r4,lr}
	ldr r3, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r4, =0x00003b58
	adds r2, r1, r4
	str r2, [r3]
	ldr r2, =0x00003b5c
	adds r1, r2
	bl StringCopy
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E81C

	thumb_func_start sub_818E848
sub_818E848: @ 818E848
	ldr r2, =gUnknown_0203CD6C
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	ldr r3, =0x00003b58
	adds r1, r3
	str r1, [r2]
	ldrb r1, [r1, 0xE]
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_818E848

	thumb_func_start sub_818E868
sub_818E868: @ 818E868
	push {lr}
	lsls r1, 24
	ldr r2, =gUnknown_0860B338
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E868

	thumb_func_start sub_818E880
sub_818E880: @ 818E880
	push {lr}
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x4
	bls _0818E8A4
	movs r0, 0x1
	b _0818E8AE
	.pool
_0818E8A4:
	cmp r0, 0
	beq _0818E8AC
	movs r0, 0
	b _0818E8AE
_0818E8AC:
	movs r0, 0x2
_0818E8AE:
	pop {r1}
	bx r1
	thumb_func_end sub_818E880

	thumb_func_start sub_818E8B4
sub_818E8B4: @ 818E8B4
	push {lr}
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	beq _0818E8D8
	movs r0, 0
	b _0818E8DA
	.pool
_0818E8D8:
	movs r0, 0x1
_0818E8DA:
	pop {r1}
	bx r1
	thumb_func_end sub_818E8B4

	thumb_func_start sub_818E8E0
sub_818E8E0: @ 818E8E0
	push {r4,lr}
	movs r3, 0
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r4, =0x00003b58
	adds r2, r0, r4
	str r2, [r1]
	ldrb r0, [r2, 0x2]
	cmp r0, 0x4
	bhi _0818E8FC
	ldrb r0, [r2, 0x3]
	cmp r0, 0x4
	bls _0818E8FE
_0818E8FC:
	movs r3, 0x1
_0818E8FE:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_818E8E0

	thumb_func_start sub_818E914
sub_818E914: @ 818E914
	push {lr}
	ldr r0, =gStringVar2
	ldr r1, =gStringVar1
	bl sub_818E794
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E914

	thumb_func_start sub_818E92C
sub_818E92C: @ 818E92C
	push {lr}
	ldr r1, =c2_exit_to_overworld_2_switch
	movs r0, 0x3
	bl sub_81357FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_818E92C

	thumb_func_start sub_818E940
sub_818E940: @ 818E940
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	movs r1, 0x1
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end sub_818E940

	thumb_func_start sub_818E960
sub_818E960: @ 818E960
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldr r2, =gSpecialVar_0x8005
	ldr r1, =gUnknown_0860B34C
	ldrb r0, [r0, 0xD]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_818E960

	thumb_func_start sub_818E990
sub_818E990: @ 818E990
	ldr r1, =gUnknown_0203CD6C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003b58
	adds r0, r2
	str r0, [r1]
	ldrb r0, [r0, 0xD]
	bx lr
	.pool
	thumb_func_end sub_818E990


.align 2, 0 @ Don't pad with nop.
