	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start tai01_unk
tai01_unk: @ 81311B8
	push {lr}
	bl Random
	lsls r0, 16
	movs r1, 0xFF
	lsls r1, 16
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ands r1, r0
	lsrs r1, 16
	ldrb r0, [r2, 0x1]
	cmp r1, r0
	bls _081311F0
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081311F4
	.pool
_081311F0:
	adds r0, r2, 0x6
	str r0, [r3]
_081311F4:
	pop {r0}
	bx r0
	thumb_func_end tai01_unk

	thumb_func_start tai02_unk
tai02_unk: @ 81311F8
	push {lr}
	bl Random
	lsls r0, 16
	movs r1, 0xFF
	lsls r1, 16
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ands r1, r0
	lsrs r1, 16
	ldrb r0, [r2, 0x1]
	cmp r1, r0
	bne _08131230
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131234
	.pool
_08131230:
	adds r0, r2, 0x6
	str r0, [r3]
_08131234:
	pop {r0}
	bx r0
	thumb_func_end tai02_unk

	thumb_func_start tai03_unk
tai03_unk: @ 8131238
	push {lr}
	bl Random
	lsls r0, 16
	movs r1, 0xFF
	lsls r1, 16
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ands r1, r0
	lsrs r1, 16
	ldrb r0, [r2, 0x1]
	cmp r1, r0
	beq _08131270
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131274
	.pool
_08131270:
	adds r0, r2, 0x6
	str r0, [r3]
_08131274:
	pop {r0}
	bx r0
	thumb_func_end tai03_unk

	thumb_func_start tai04_unk
tai04_unk: @ 8131278
	push {r4,lr}
	ldr r2, =gUnknown_020244A8
	ldr r0, [r2]
	ldr r0, [r0, 0x14]
	adds r1, r0, 0x4
	ldrb r0, [r0, 0x1]
	adds r1, r0
	ldr r3, =gAIScriptPtr
	ldr r0, [r3]
	ldrb r0, [r0, 0x1]
	ldrb r4, [r1]
	adds r0, r4
	strb r0, [r1]
	ldr r0, [r2]
	ldr r1, [r0, 0x14]
	adds r0, r1, 0x4
	ldrb r1, [r1, 0x1]
	adds r1, r0, r1
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bge _081312A8
	movs r0, 0
	strb r0, [r1]
_081312A8:
	ldr r0, [r3]
	adds r0, 0x2
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai04_unk

	thumb_func_start tai05_unk
tai05_unk: @ 81312BC
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _081312D8
	ldr r0, =gUnknown_0203AB3C
	b _081312DA
	.pool
_081312D8:
	ldr r0, =gUnknown_0202420C
_081312DA:
	ldrb r1, [r0]
	ldr r2, =gBattleMons
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r2, [r1, 0x28]
	movs r0, 0x64
	muls r0, r2
	ldrh r1, [r1, 0x2C]
	bl __divsi3
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	cmp r0, r1
	bcs _08131318
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0813131C
	.pool
_08131318:
	adds r0, r2, 0x7
	str r0, [r4]
_0813131C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai05_unk

	thumb_func_start tai06_unk
tai06_unk: @ 8131324
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08131340
	ldr r0, =gUnknown_0203AB3C
	b _08131342
	.pool
_08131340:
	ldr r0, =gUnknown_0202420C
_08131342:
	ldrb r1, [r0]
	ldr r2, =gBattleMons
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r2, [r1, 0x28]
	movs r0, 0x64
	muls r0, r2
	ldrh r1, [r1, 0x2C]
	bl __divsi3
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	cmp r0, r1
	bls _08131380
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08131384
	.pool
_08131380:
	adds r0, r2, 0x7
	str r0, [r4]
_08131384:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai06_unk

	thumb_func_start tai07_unk
tai07_unk: @ 813138C
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _081313A8
	ldr r0, =gUnknown_0203AB3C
	b _081313AA
	.pool
_081313A8:
	ldr r0, =gUnknown_0202420C
_081313AA:
	ldrb r1, [r0]
	ldr r2, =gBattleMons
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r2, [r1, 0x28]
	movs r0, 0x64
	muls r0, r2
	ldrh r1, [r1, 0x2C]
	bl __divsi3
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	cmp r0, r1
	bne _081313E8
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _081313EC
	.pool
_081313E8:
	adds r0, r2, 0x7
	str r0, [r4]
_081313EC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai07_unk

	thumb_func_start tai08_unk
tai08_unk: @ 81313F4
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08131410
	ldr r0, =gUnknown_0203AB3C
	b _08131412
	.pool
_08131410:
	ldr r0, =gUnknown_0202420C
_08131412:
	ldrb r1, [r0]
	ldr r2, =gBattleMons
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r2, [r1, 0x28]
	movs r0, 0x64
	muls r0, r2
	ldrh r1, [r1, 0x2C]
	bl __divsi3
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	cmp r0, r1
	beq _08131450
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08131454
	.pool
_08131450:
	adds r0, r2, 0x7
	str r0, [r4]
_08131454:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai08_unk

	thumb_func_start tai09_unk
tai09_unk: @ 813145C
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _08131478
	ldr r0, =gUnknown_0203AB3C
	b _0813147A
	.pool
_08131478:
	ldr r0, =gUnknown_0202420C
_0813147A:
	ldrb r4, [r0]
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r2, r0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	beq _081314C4
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _081314CA
	.pool
_081314C4:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r5]
_081314CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai09_unk

	thumb_func_start tai0A_unk
tai0A_unk: @ 81314D0
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _081314EC
	ldr r0, =gUnknown_0203AB3C
	b _081314EE
	.pool
_081314EC:
	ldr r0, =gUnknown_0202420C
_081314EE:
	ldrb r4, [r0]
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r2, r0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	bne _08131538
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _0813153E
	.pool
_08131538:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r5]
_0813153E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai0A_unk

	thumb_func_start tai0B_unk
tai0B_unk: @ 8131544
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _08131560
	ldr r0, =gUnknown_0203AB3C
	b _08131562
	.pool
_08131560:
	ldr r0, =gUnknown_0202420C
_08131562:
	ldrb r4, [r0]
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r2, r0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	beq _081315AC
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _081315B2
	.pool
_081315AC:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r5]
_081315B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai0B_unk

	thumb_func_start tai0C_unk
tai0C_unk: @ 81315B8
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _081315D4
	ldr r0, =gUnknown_0203AB3C
	b _081315D6
	.pool
_081315D4:
	ldr r0, =gUnknown_0202420C
_081315D6:
	ldrb r4, [r0]
	ldr r3, [r5]
	ldrb r2, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r3, 0x5]
	lsls r0, 24
	orrs r2, r0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	bne _08131620
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _08131626
	.pool
_08131620:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r5]
_08131626:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai0C_unk

	thumb_func_start tai0D_unk
tai0D_unk: @ 813162C
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _08131648
	ldr r0, =gUnknown_0203AB3C
	b _0813164A
	.pool
_08131648:
	ldr r0, =gUnknown_0202420C
_0813164A:
	ldrb r4, [r0]
	ldr r3, [r5]
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
	ldr r2, =gUnknown_020242AC
	lsls r0, r4, 2
	adds r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _08131690
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _08131696
	.pool
_08131690:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r5]
_08131696:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai0D_unk

	thumb_func_start tai0E_unk
tai0E_unk: @ 813169C
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _081316B8
	ldr r0, =gUnknown_0203AB3C
	b _081316BA
	.pool
_081316B8:
	ldr r0, =gUnknown_0202420C
_081316BA:
	ldrb r4, [r0]
	ldr r3, [r5]
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
	ldr r2, =gUnknown_020242AC
	lsls r0, r4, 2
	adds r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	bne _08131700
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _08131706
	.pool
_08131700:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r5]
_08131706:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai0E_unk

	thumb_func_start tai0F_unk
tai0F_unk: @ 813170C
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _08131724
	ldr r0, =gUnknown_0203AB3C
	b _08131726
	.pool
_08131724:
	ldr r0, =gUnknown_0202420C
_08131726:
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r2, 0x1
	ands r2, r0
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
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
	ldr r0, =gUnknown_0202428E
	lsls r2, 1
	adds r2, r0
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _0813177C
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08131782
	.pool
_0813177C:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r4]
_08131782:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai0F_unk

	thumb_func_start tai10_unk
tai10_unk: @ 8131788
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081317A0
	ldr r0, =gUnknown_0203AB3C
	b _081317A2
	.pool
_081317A0:
	ldr r0, =gUnknown_0202420C
_081317A2:
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r2, 0x1
	ands r2, r0
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
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
	ldr r0, =gUnknown_0202428E
	lsls r2, 1
	adds r2, r0
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _081317F8
	ldrb r1, [r3, 0x6]
	ldrb r0, [r3, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r3, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _081317FE
	.pool
_081317F8:
	adds r0, r3, 0
	adds r0, 0xA
	str r0, [r4]
_081317FE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai10_unk

	thumb_func_start tai11_unk
tai11_unk: @ 8131804
	push {lr}
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldr r0, [r0, 0x8]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bcs _08131838
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0813183C
	.pool
_08131838:
	adds r0, r2, 0x6
	str r0, [r3]
_0813183C:
	pop {r0}
	bx r0
	thumb_func_end tai11_unk

	thumb_func_start tai12_unk
tai12_unk: @ 8131840
	push {lr}
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldr r0, [r0, 0x8]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bls _08131874
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131878
	.pool
_08131874:
	adds r0, r2, 0x6
	str r0, [r3]
_08131878:
	pop {r0}
	bx r0
	thumb_func_end tai12_unk

	thumb_func_start tai13_unk
tai13_unk: @ 813187C
	push {lr}
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldr r0, [r0, 0x8]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _081318B0
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081318B4
	.pool
_081318B0:
	adds r0, r2, 0x6
	str r0, [r3]
_081318B4:
	pop {r0}
	bx r0
	thumb_func_end tai13_unk

	thumb_func_start tai14_unk
tai14_unk: @ 81318B8
	push {lr}
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldr r0, [r0, 0x8]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	beq _081318EC
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081318F0
	.pool
_081318EC:
	adds r0, r2, 0x6
	str r0, [r3]
_081318F0:
	pop {r0}
	bx r0
	thumb_func_end tai14_unk

	thumb_func_start tai15_unk
tai15_unk: @ 81318F4
	push {lr}
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
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _0813193C
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131942
	.pool
_0813193C:
	adds r0, r2, 0
	adds r0, 0x9
	str r0, [r3]
_08131942:
	pop {r0}
	bx r0
	thumb_func_end tai15_unk

	thumb_func_start tai16_unk
tai16_unk: @ 8131948
	push {lr}
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
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08131990
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131996
	.pool
_08131990:
	adds r0, r2, 0
	adds r0, 0x9
	str r0, [r3]
_08131996:
	pop {r0}
	bx r0
	thumb_func_end tai16_unk

	thumb_func_start tai17_unk
tai17_unk: @ 813199C
	push {lr}
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
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	bne _081319E4
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081319EA
	.pool
_081319E4:
	adds r0, r2, 0
	adds r0, 0x9
	str r0, [r3]
_081319EA:
	pop {r0}
	bx r0
	thumb_func_end tai17_unk

	thumb_func_start tai18_unk
tai18_unk: @ 81319F0
	push {lr}
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
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0x8]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08131A38
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131A3E
	.pool
_08131A38:
	adds r0, r2, 0
	adds r0, 0x9
	str r0, [r3]
_08131A3E:
	pop {r0}
	bx r0
	thumb_func_end tai18_unk

	thumb_func_start tai19_unk
tai19_unk: @ 8131A44
	push {lr}
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	cmp r0, r1
	bne _08131A80
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131A84
	.pool
_08131A80:
	adds r0, r2, 0x7
	str r0, [r3]
_08131A84:
	pop {r0}
	bx r0
	thumb_func_end tai19_unk

	thumb_func_start tai1A_unk
tai1A_unk: @ 8131A88
	push {lr}
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	cmp r0, r1
	beq _08131AC4
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08131AC8
	.pool
_08131AC4:
	adds r0, r2, 0x7
	str r0, [r3]
_08131AC8:
	pop {r0}
	bx r0
	thumb_func_end tai1A_unk

	thumb_func_start tai1B_unk
tai1B_unk: @ 8131ACC
	push {r4,lr}
	ldr r2, =gAIScriptPtr
	ldr r1, [r2]
	ldrb r3, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r3, r0
	ldrb r0, [r3]
	cmp r0, 0xFF
	beq _08131B28
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r1, [r0, 0x8]
	adds r4, r2, 0
_08131AF6:
	ldrb r0, [r3]
	cmp r1, r0
	bne _08131B20
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08131B2E
	.pool
_08131B20:
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _08131AF6
_08131B28:
	ldr r0, [r2]
	adds r0, 0x9
	str r0, [r2]
_08131B2E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai1B_unk

	thumb_func_start tai1C_unk
tai1C_unk: @ 8131B34
	push {r4,lr}
	ldr r2, =gAIScriptPtr
	ldr r1, [r2]
	ldrb r3, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r3, r0
	ldrb r0, [r3]
	adds r4, r2, 0
	cmp r0, 0xFF
	beq _08131B80
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r2, [r0, 0x8]
	adds r1, r4, 0
_08131B60:
	ldrb r0, [r3]
	cmp r2, r0
	bne _08131B78
	ldr r0, [r1]
	adds r0, 0x9
	str r0, [r1]
	b _08131B98
	.pool
_08131B78:
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0xFF
	bne _08131B60
_08131B80:
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
_08131B98:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai1C_unk

	thumb_func_start tai1D_unk
tai1D_unk: @ 8131BA0
	push {r4,r5,lr}
	ldr r2, =gAIScriptPtr
	ldr r1, [r2]
	ldrb r3, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r3, r0
	ldrh r0, [r3]
	ldr r5, =0x0000ffff
	cmp r0, r5
	beq _08131C00
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r1, [r0, 0x8]
	adds r4, r2, 0
_08131BCC:
	ldrh r0, [r3]
	cmp r1, r0
	bne _08131BF8
	ldr r2, [r4]
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08131C06
	.pool
_08131BF8:
	adds r3, 0x2
	ldrh r0, [r3]
	cmp r0, r5
	bne _08131BCC
_08131C00:
	ldr r0, [r2]
	adds r0, 0x9
	str r0, [r2]
_08131C06:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai1D_unk

	thumb_func_start tai1E_unk
tai1E_unk: @ 8131C0C
	push {r4,r5,lr}
	ldr r2, =gAIScriptPtr
	ldr r1, [r2]
	ldrb r3, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r3, r0
	ldrh r0, [r3]
	ldr r4, =0x0000ffff
	adds r5, r2, 0
	cmp r0, r4
	beq _08131C5C
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r2, [r0, 0x8]
	adds r1, r5, 0
_08131C3A:
	ldrh r0, [r3]
	cmp r2, r0
	bne _08131C54
	ldr r0, [r1]
	adds r0, 0x9
	str r0, [r1]
	b _08131C74
	.pool
_08131C54:
	adds r3, 0x2
	ldrh r0, [r3]
	cmp r0, r4
	bne _08131C3A
_08131C5C:
	ldr r2, [r5]
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
_08131C74:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai1E_unk

	thumb_func_start tai1F_unk
tai1F_unk: @ 8131C7C
	push {r4,r5,lr}
	movs r3, 0
	ldr r4, =gAIScriptPtr
	ldr r1, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r2, [r0]
	ldr r5, =gBattleMoves
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r2, r0, r1
_08131C92:
	ldrh r0, [r2]
	cmp r0, 0
	beq _08131CA6
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _08131CAE
_08131CA6:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _08131C92
_08131CAE:
	cmp r3, 0x4
	bne _08131CCC
	ldr r0, [r4]
	adds r0, 0x5
	str r0, [r4]
	b _08131CE4
	.pool
_08131CCC:
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
_08131CE4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai1F_unk

	thumb_func_start tai20_unk
tai20_unk: @ 8131CEC
	push {r4,r5,lr}
	movs r3, 0
	ldr r4, =gAIScriptPtr
	ldr r1, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r2, [r0]
	ldr r5, =gBattleMoves
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r2, r0, r1
_08131D02:
	ldrh r0, [r2]
	cmp r0, 0
	beq _08131D16
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _08131D1E
_08131D16:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _08131D02
_08131D1E:
	cmp r3, 0x4
	beq _08131D3C
	ldr r0, [r4]
	adds r0, 0x5
	str r0, [r4]
	b _08131D54
	.pool
_08131D3C:
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
_08131D54:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai20_unk

	thumb_func_start tai21_unk
tai21_unk: @ 8131D5C
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	ldr r0, =gUnknown_03005D10
	ldrb r0, [r0, 0x13]
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end tai21_unk

	thumb_func_start dp15_get_some_type
dp15_get_some_type: @ 8131D80
	push {r4,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _08131E5A
	lsls r0, 2
	ldr r1, =_08131DA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08131DA0:
	.4byte _08131DD8
	.4byte _08131DB4
	.4byte _08131E20
	.4byte _08131DFC
	.4byte _08131E44
_08131DB4:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x21
	ldrb r0, [r0]
	b _08131E58
	.pool
_08131DD8:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMons
	ldr r0, =gUnknown_0202420C
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x21
	ldrb r0, [r0]
	b _08131E58
	.pool
_08131DFC:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x22
	ldrb r0, [r0]
	b _08131E58
	.pool
_08131E20:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMons
	ldr r0, =gUnknown_0202420C
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x22
	ldrb r0, [r0]
	b _08131E58
	.pool
_08131E44:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldrh r1, [r3, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
_08131E58:
	str r0, [r3, 0x8]
_08131E5A:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_some_type

	thumb_func_start sub_8131E70
sub_8131E70: @ 8131E70
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08131E84
	ldr r0, =gUnknown_0203AB3C
	ldrb r0, [r0]
	b _08131EAC
	.pool
_08131E84:
	cmp r0, 0x1
	ble _08131E90
	cmp r0, 0x2
	beq _08131EA4
	cmp r0, 0x3
	beq _08131E9C
_08131E90:
	ldr r0, =gUnknown_0202420C
	ldrb r0, [r0]
	b _08131EAC
	.pool
_08131E9C:
	ldr r0, =gUnknown_0203AB3C
	b _08131EA6
	.pool
_08131EA4:
	ldr r0, =gUnknown_0202420C
_08131EA6:
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
_08131EAC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8131E70

	thumb_func_start tai5F_unk
tai5F_unk: @ 8131EB4
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_8131E70
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r0, r1
	adds r3, r0, r2
	adds r1, r3, 0
	adds r1, 0x21
	ldr r0, [r4]
	ldrb r1, [r1]
	ldrb r2, [r0, 0x2]
	cmp r1, r2
	beq _08131EE4
	adds r0, r3, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r2
	bne _08131EFC
_08131EE4:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x1
	b _08131F04
	.pool
_08131EFC:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0
_08131F04:
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x3
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5F_unk

	thumb_func_start dp15_move_get_power__2_8
dp15_move_get_power__2_8: @ 8131F1C
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldrh r1, [r3, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_power__2_8

	thumb_func_start dp15_is_most_powerful_move__8
dp15_is_most_powerful_move__8: @ 8131F48
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r3, 0
	ldr r0, =gUnknown_085B09C8
	ldrh r1, [r0]
	ldr r5, =0x0000ffff
	ldr r6, =gBattleMoves
	ldr r2, =gUnknown_020244A8
	cmp r1, r5
	beq _08131F86
	ldr r0, [r2]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r4, [r0]
	ldr r1, =gUnknown_085B09C8
_08131F76:
	ldrh r0, [r1]
	cmp r4, r0
	beq _08131F86
	adds r1, 0x2
	adds r3, 0x1
	ldrh r0, [r1]
	cmp r0, r5
	bne _08131F76
_08131F86:
	ldr r0, [r2]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bhi _08131F9C
	b _08132126
_08131F9C:
	lsls r0, r3, 1
	ldr r1, =gUnknown_085B09C8
	adds r0, r1
	ldrh r3, [r0]
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _08131FAC
	b _08132126
_08131FAC:
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	movs r6, 0
	mov r9, r3
	ldr r2, =gUnknown_085B09C8
	ldrh r2, [r2]
	str r2, [sp, 0x10]
_08131FD0:
	movs r3, 0
	ldr r5, =gBattleMons
	lsls r4, r6, 1
	ldr r7, =gUnknown_0203AB3C
	lsls r0, r6, 2
	mov r8, r0
	adds r1, r6, 0x1
	mov r10, r1
	ldr r2, [sp, 0x10]
	cmp r2, r9
	beq _08132014
	ldr r2, =gBattleMoves
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	adds r0, r4, r0
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0]
	ldr r1, =gUnknown_085B09C8
_08132004:
	ldrh r0, [r1]
	cmp r2, r0
	beq _08132014
	adds r1, 0x2
	adds r3, 0x1
	ldrh r0, [r1]
	cmp r0, r9
	bne _08132004
_08132014:
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	adds r0, r4, r0
	adds r1, r5, 0
	adds r1, 0xC
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	beq _081320C0
	lsls r0, r3, 1
	ldr r2, =gUnknown_085B09C8
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r9
	bne _081320C0
	ldr r0, =gBattleMoves
	ldrh r2, [r1]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0x1
	bls _081320C0
	ldr r5, =gUnknown_020241EA
	strh r2, [r5]
	ldrb r0, [r7]
	ldr r4, =gUnknown_0202420C
	ldrb r1, [r4]
	bl sub_8046E7C
	ldrh r0, [r5]
	ldrb r1, [r7]
	ldrb r2, [r4]
	bl move_effectiveness_something
	mov r4, sp
	add r4, r8
	ldr r2, =gUnknown_020241F0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	adds r0, 0x18
	adds r0, r6
	ldrb r1, [r0]
	ldr r0, [r2]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _081320C8
	movs r0, 0x1
	str r0, [r4]
	b _081320C8
	.pool
_081320C0:
	mov r1, sp
	add r1, r8
	movs r0, 0
	str r0, [r1]
_081320C8:
	mov r6, r10
	cmp r6, 0x3
	bgt _081320D0
	b _08131FD0
_081320D0:
	movs r6, 0
	ldr r2, =gUnknown_020244A8
	ldr r0, [r2]
	ldr r0, [r0, 0x14]
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	add r0, sp
	ldr r1, [sp]
	ldr r0, [r0]
	ldr r5, =gAIScriptPtr
	cmp r1, r0
	bgt _08132106
	adds r4, r2, 0
	mov r3, sp
_081320EC:
	adds r3, 0x4
	adds r6, 0x1
	cmp r6, 0x3
	bgt _08132106
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	add r0, sp
	ldr r1, [r3]
	ldr r0, [r0]
	cmp r1, r0
	ble _081320EC
_08132106:
	cmp r6, 0x4
	bne _0813211C
	ldr r0, [r2]
	ldr r1, [r0, 0x14]
	movs r0, 0x2
	str r0, [r1, 0x8]
	b _08132130
	.pool
_0813211C:
	ldr r0, [r2]
	ldr r1, [r0, 0x14]
	movs r0, 0x1
	str r0, [r1, 0x8]
	b _08132130
_08132126:
	ldr r0, [r2]
	ldr r1, [r0, 0x14]
	movs r0, 0
	str r0, [r1, 0x8]
	ldr r5, =gAIScriptPtr
_08132130:
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_is_most_powerful_move__8

	thumb_func_start dp15_get_move_to_execute_B
dp15_get_move_to_execute_B: @ 813214C
	push {lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _08132178
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_02024248
	ldr r0, =gUnknown_0203AB3C
	b _08132182
	.pool
_08132178:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_02024248
	ldr r0, =gUnknown_0202420C
_08132182:
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	str r0, [r2, 0x8]
	ldr r0, [r3]
	adds r0, 0x2
	str r0, [r3]
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_move_to_execute_B

	thumb_func_start tai26_unk
tai26_unk: @ 81321A4
	push {lr}
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0x8]
	cmp r1, r0
	bne _081321D8
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081321DC
	.pool
_081321D8:
	adds r0, r2, 0x6
	str r0, [r3]
_081321DC:
	pop {r0}
	bx r0
	thumb_func_end tai26_unk

	thumb_func_start tai27_unk
tai27_unk: @ 81321E0
	push {lr}
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldr r0, [r0, 0x8]
	cmp r1, r0
	beq _08132214
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132218
	.pool
_08132214:
	adds r0, r2, 0x6
	str r0, [r3]
_08132218:
	pop {r0}
	bx r0
	thumb_func_end tai27_unk

	thumb_func_start tai28_unk
tai28_unk: @ 813221C
	push {lr}
	ldr r0, =gUnknown_0203AB3C
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202420C
	ldrb r1, [r1]
	movs r2, 0x1
	bl b_first_side
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _08132260
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132264
	.pool
_08132260:
	adds r0, r2, 0x6
	str r0, [r3]
_08132264:
	pop {r0}
	bx r0
	thumb_func_end tai28_unk

	thumb_func_start tai29_unk
tai29_unk: @ 8132268
	push {lr}
	ldr r0, =gUnknown_0203AB3C
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202420C
	ldrb r1, [r1]
	movs r2, 0x1
	bl b_first_side
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	beq _081322AC
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081322B0
	.pool
_081322AC:
	adds r0, r2, 0x6
	str r0, [r3]
_081322B0:
	pop {r0}
	bx r0
	thumb_func_end tai29_unk

	thumb_func_start nullsub_102
nullsub_102: @ 81322B4
	bx lr
	thumb_func_end nullsub_102

	thumb_func_start nullsub_103
nullsub_103: @ 81322B8
	bx lr
	thumb_func_end nullsub_103

	thumb_func_start tai2C_unk
tai2C_unk: @ 81322BC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0
	str r0, [r1, 0x8]
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081322E8
	ldr r0, =gUnknown_0203AB3C
	b _081322EA
	.pool
_081322E8:
	ldr r0, =gUnknown_0202420C
_081322EA:
	ldrb r5, [r0]
	adds r0, r5, 0
	bl battle_side_get_owner
	lsls r0, 24
	ldr r1, =gUnknown_02024744
	mov r8, r1
	cmp r0, 0
	bne _08132300
	ldr r0, =gUnknown_020244EC
	mov r8, r0
_08132300:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08132344
	ldr r4, =gUnknown_0202406E
	lsls r0, r5, 1
	adds r0, r4
	ldrb r7, [r0]
	adds r0, r5, 0
	bl battle_get_per_side_status
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl battle_get_side_with_given_state
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrb r6, [r0]
	b _0813234E
	.pool
_08132344:
	ldr r1, =gUnknown_0202406E
	lsls r0, r5, 1
	adds r0, r1
	ldrb r6, [r0]
	adds r7, r6, 0
_0813234E:
	movs r5, 0
_08132350:
	cmp r5, r7
	beq _08132394
	cmp r5, r6
	beq _08132394
	movs r0, 0x64
	muls r0, r5
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl pokemon_getattr
	cmp r0, 0
	beq _08132394
	adds r0, r4, 0
	movs r1, 0x41
	bl pokemon_getattr
	cmp r0, 0
	beq _08132394
	adds r0, r4, 0
	movs r1, 0x41
	bl pokemon_getattr
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08132394
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	ldr r0, [r1, 0x8]
	adds r0, 0x1
	str r0, [r1, 0x8]
_08132394:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08132350
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai2C_unk

	thumb_func_start dp15_get_move_id__8
dp15_get_move_id__8: @ 81323B8
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	ldrh r0, [r1, 0x2]
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_get_move_id__8

	thumb_func_start dp15_move_get_move_script_id
dp15_move_get_move_script_id: @ 81323D4
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldrh r1, [r3, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_move_script_id

	thumb_func_start tai2F_unk
tai2F_unk: @ 8132400
	push {r4-r7,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	mov r12, r0
	cmp r1, 0x1
	bne _0813241C
	ldr r0, =gUnknown_0203AB3C
	b _0813241E
	.pool
_0813241C:
	ldr r0, =gUnknown_0202420C
_0813241E:
	ldrb r3, [r0]
	ldr r0, =gUnknown_02024064
	ldrb r0, [r0]
	cmp r0, r3
	beq _081324F0
	ldr r7, =gUnknown_020244A8
	ldr r5, [r7]
	ldr r0, [r5, 0x18]
	adds r0, 0x40
	adds r2, r0, r3
	ldrb r0, [r2]
	adds r6, r7, 0
	cmp r0, 0
	beq _0813244C
	ldr r1, [r5, 0x14]
	str r0, [r1, 0x8]
	b _08132504
	.pool
_0813244C:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x17
	beq _08132468
	cmp r0, 0x2A
	beq _08132468
	cmp r0, 0x47
	bne _08132480
_08132468:
	ldr r0, [r6]
	ldr r1, [r0, 0x14]
	movs r0, 0x58
	muls r0, r3
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	str r0, [r1, 0x8]
	b _08132504
	.pool
_08132480:
	ldr r6, =gBaseStats
	ldrh r0, [r4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r6
	ldrb r0, [r2, 0x16]
	cmp r0, 0
	beq _081324E8
	ldrb r0, [r2, 0x17]
	cmp r0, 0
	beq _081324E0
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _081324C4
	ldr r0, [r7]
	ldr r2, [r0, 0x14]
	ldrh r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x16]
	str r0, [r2, 0x8]
	ldr r0, =gAIScriptPtr
	mov r12, r0
	b _08132504
	.pool
_081324C4:
	ldr r0, [r7]
	ldr r2, [r0, 0x14]
	ldrh r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x17]
	str r0, [r2, 0x8]
	ldr r1, =gAIScriptPtr
	mov r12, r1
	b _08132504
	.pool
_081324E0:
	ldr r1, [r5, 0x14]
	ldrb r0, [r2, 0x16]
	str r0, [r1, 0x8]
	b _08132504
_081324E8:
	ldr r1, [r5, 0x14]
	ldrb r0, [r2, 0x17]
	str r0, [r1, 0x8]
	b _08132504
_081324F0:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	str r0, [r2, 0x8]
_08132504:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai2F_unk

	thumb_func_start tai60_unk
tai60_unk: @ 813251C
	push {r4-r6,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_8131E70
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [r4]
	ldrb r3, [r0, 0x2]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _0813253A
	cmp r0, 0x2
	bne _081325BC
_0813253A:
	ldr r0, =gUnknown_020244A8
	ldr r4, [r0]
	ldr r1, [r4, 0x18]
	adds r1, 0x40
	adds r2, r1, r5
	ldrb r1, [r2]
	adds r6, r0, 0
	cmp r1, 0
	beq _0813255C
	adds r3, r1, 0
	ldr r0, [r4, 0x14]
	str r3, [r0, 0x8]
	b _081325CA
	.pool
_0813255C:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r5
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x17
	beq _08132576
	cmp r0, 0x2A
	beq _08132576
	cmp r0, 0x47
	bne _08132588
_08132576:
	movs r0, 0x58
	muls r0, r5
	adds r0, r1
	adds r0, 0x20
	ldrb r3, [r0]
	b _081325CA
	.pool
_08132588:
	ldr r2, =gBaseStats
	ldrh r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrb r4, [r1, 0x16]
	cmp r4, 0
	beq _081325B8
	ldrb r2, [r1, 0x17]
	cmp r2, 0
	beq _081325B4
	adds r0, r3, 0
	cmp r4, r0
	beq _081325CE
	cmp r2, r0
	beq _081325CE
	adds r3, r4, 0
	b _081325CA
	.pool
_081325B4:
	ldrb r3, [r1, 0x16]
	b _081325CA
_081325B8:
	ldrb r3, [r1, 0x17]
	b _081325CA
_081325BC:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r5
	adds r0, r1
	adds r0, 0x20
	ldrb r3, [r0]
	ldr r6, =gUnknown_020244A8
_081325CA:
	cmp r3, 0
	bne _081325E8
_081325CE:
	ldr r0, [r6]
	ldr r1, [r0, 0x14]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r2, =gAIScriptPtr
	b _08132608
	.pool
_081325E8:
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	adds r2, r0, 0
	ldrb r1, [r1, 0x2]
	cmp r3, r1
	bne _08132600
	ldr r0, [r6]
	ldr r1, [r0, 0x14]
	movs r0, 0x1
	b _08132606
	.pool
_08132600:
	ldr r0, [r6]
	ldr r1, [r0, 0x14]
	movs r0, 0
_08132606:
	str r0, [r1, 0x8]
_08132608:
	ldr r0, [r2]
	adds r0, 0x3
	str r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end tai60_unk

	thumb_func_start tai30_unk
tai30_unk: @ 8132614
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r3, 0
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	str r3, [r0, 0x8]
	movs r5, 0
	ldr r4, =gUnknown_020241F0
	ldr r7, =gUnknown_020241EA
	ldr r0, =gUnknown_02024090
	mov r8, r0
	ldr r6, =gUnknown_0203AB3C
_0813264A:
	movs r0, 0x28
	str r0, [r4]
	lsls r1, r5, 1
	ldrb r2, [r6]
	movs r0, 0x58
	muls r0, r2
	adds r1, r0
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r7]
	lsls r0, 16
	cmp r0, 0
	beq _081326B8
	ldrh r0, [r7]
	ldrb r1, [r6]
	ldr r2, =gUnknown_0202420C
	ldrb r2, [r2]
	bl move_effectiveness_something
	ldr r0, [r4]
	cmp r0, 0x78
	bne _0813267A
	movs r0, 0x50
	str r0, [r4]
_0813267A:
	ldr r0, [r4]
	cmp r0, 0xF0
	bne _08132684
	movs r0, 0xA0
	str r0, [r4]
_08132684:
	ldr r0, [r4]
	cmp r0, 0x1E
	bne _0813268E
	movs r0, 0x14
	str r0, [r4]
_0813268E:
	ldr r0, [r4]
	cmp r0, 0xF
	bne _08132698
	movs r0, 0xA
	str r0, [r4]
_08132698:
	ldr r0, =gUnknown_0202427C
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081326A8
	movs r0, 0
	str r0, [r4]
_081326A8:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r0, [r2, 0x8]
	ldr r1, [r4]
	cmp r0, r1
	bcs _081326B8
	str r1, [r2, 0x8]
_081326B8:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0813264A
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai30_unk

	thumb_func_start dp15_simulate_damage_bonus_jump_if_eq
dp15_simulate_damage_bonus_jump_if_eq: @ 8132700
	push {r4,r5,lr}
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r5, =gUnknown_0202427C
	strb r1, [r5]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	ldr r4, =gUnknown_020241F0
	movs r0, 0x28
	str r0, [r4]
	ldr r1, =gUnknown_020241EA
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r1, =gUnknown_0203AB3C
	ldrb r1, [r1]
	ldr r2, =gUnknown_0202420C
	ldrb r2, [r2]
	bl move_effectiveness_something
	ldr r0, [r4]
	cmp r0, 0x78
	bne _08132746
	movs r0, 0x50
	str r0, [r4]
_08132746:
	ldr r0, [r4]
	cmp r0, 0xF0
	bne _08132750
	movs r0, 0xA0
	str r0, [r4]
_08132750:
	ldr r0, [r4]
	cmp r0, 0x1E
	bne _0813275A
	movs r0, 0x14
	str r0, [r4]
_0813275A:
	ldr r0, [r4]
	cmp r0, 0xF
	bne _08132764
	movs r0, 0xA
	str r0, [r4]
_08132764:
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08132772
	movs r0, 0
	str r0, [r4]
_08132772:
	ldrb r0, [r4]
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _081327C4
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _081327C8
	.pool
_081327C4:
	adds r0, r2, 0x6
	str r0, [r3]
_081327C8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp15_simulate_damage_bonus_jump_if_eq

	thumb_func_start nullsub_104
nullsub_104: @ 81327D0
	bx lr
	thumb_func_end nullsub_104

	thumb_func_start nullsub_105
nullsub_105: @ 81327D4
	bx lr
	thumb_func_end nullsub_105

	thumb_func_start tai34_unk
tai34_unk: @ 81327D8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _08132818
	ldr r0, =gUnknown_0203AB3C
	b _0813281A
	.pool
_081327F8:
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x6]
	ldrb r0, [r2, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _0813289A
	.pool
_08132818:
	ldr r0, =gUnknown_0202420C
_0813281A:
	ldrb r0, [r0]
	bl battle_side_get_owner
	lsls r0, 24
	ldr r1, =gUnknown_02024744
	mov r9, r1
	cmp r0, 0
	bne _0813282E
	ldr r0, =gUnknown_020244EC
	mov r9, r0
_0813282E:
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r7, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	orrs r7, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	orrs r7, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	orrs r7, r0
	movs r1, 0
	mov r8, r1
	movs r0, 0xCE
	lsls r0, 1
	mov r10, r0
_08132850:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	add r4, r9
	adds r0, r4, 0
	movs r1, 0xB
	bl pokemon_getattr
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl pokemon_getattr
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl pokemon_getattr
	cmp r5, 0
	beq _08132888
	cmp r5, r10
	beq _08132888
	cmp r6, 0
	beq _08132888
	cmp r0, r7
	beq _081327F8
_08132888:
	movs r1, 0x1
	add r8, r1
	mov r0, r8
	cmp r0, 0x5
	ble _08132850
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
_0813289A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai34_unk

	thumb_func_start tai35_unk
tai35_unk: @ 81328B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081328D8
	ldr r0, =gUnknown_0203AB3C
	b _081328DA
	.pool
_081328D8:
	ldr r0, =gUnknown_0202420C
_081328DA:
	ldrb r0, [r0]
	bl battle_side_get_owner
	lsls r0, 24
	ldr r1, =gUnknown_02024744
	mov r10, r1
	cmp r0, 0
	bne _081328EE
	ldr r0, =gUnknown_020244EC
	mov r10, r0
_081328EE:
	ldr r2, =gAIScriptPtr
	ldr r1, [r2]
	ldrb r7, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	orrs r7, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	orrs r7, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	orrs r7, r0
	movs r1, 0
	mov r8, r1
	mov r9, r2
_0813290C:
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	add r4, r10
	adds r0, r4, 0
	movs r1, 0xB
	bl pokemon_getattr
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x39
	bl pokemon_getattr
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r4, 0
	movs r1, 0x37
	bl pokemon_getattr
	cmp r5, 0
	beq _08132950
	movs r1, 0xCE
	lsls r1, 1
	cmp r5, r1
	beq _08132950
	cmp r6, 0
	beq _08132950
	cmp r0, r7
	bne _08132950
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
_08132950:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x5
	ble _0813290C
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r1, [r2, 0x6]
	ldrb r0, [r2, 0x7]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x9]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai35_unk

	thumb_func_start dp15_get_weather__8
dp15_get_weather__8: @ 8132994
	push {lr}
	ldr r2, =gUnknown_020243CC
	ldrh r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _081329AC
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x1
	str r0, [r1, 0x8]
_081329AC:
	ldrh r1, [r2]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _081329C0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x2
	str r0, [r1, 0x8]
_081329C0:
	ldrh r1, [r2]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _081329D4
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0
	str r0, [r1, 0x8]
_081329D4:
	ldrh r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081329E8
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x14]
	movs r0, 0x3
	str r0, [r1, 0x8]
_081329E8:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_weather__8

	thumb_func_start tai37_unk
tai37_unk: @ 8132A00
	push {lr}
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r0, [r0]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _08132A44
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132A48
	.pool
_08132A44:
	adds r0, r2, 0x6
	str r0, [r3]
_08132A48:
	pop {r0}
	bx r0
	thumb_func_end tai37_unk

	thumb_func_start tai38_unk
tai38_unk: @ 8132A4C
	push {lr}
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r3, =gAIScriptPtr
	ldr r2, [r3]
	ldrb r0, [r0]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	beq _08132A90
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
	b _08132A94
	.pool
_08132A90:
	adds r0, r2, 0x6
	str r0, [r3]
_08132A94:
	pop {r0}
	bx r0
	thumb_func_end tai38_unk

	thumb_func_start tai39_unk
tai39_unk: @ 8132A98
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132AB4
	ldr r0, =gUnknown_0203AB3C
	b _08132AB6
	.pool
_08132AB4:
	ldr r0, =gUnknown_0202420C
_08132AB6:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	bge _08132AF4
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132AFA
	.pool
_08132AF4:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132AFA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai39_unk

	thumb_func_start tai3A_unk
tai3A_unk: @ 8132B00
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132B1C
	ldr r0, =gUnknown_0203AB3C
	b _08132B1E
	.pool
_08132B1C:
	ldr r0, =gUnknown_0202420C
_08132B1E:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	ble _08132B5C
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132B62
	.pool
_08132B5C:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132B62:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai3A_unk

	thumb_func_start tai3B_unk
tai3B_unk: @ 8132B68
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132B84
	ldr r0, =gUnknown_0203AB3C
	b _08132B86
	.pool
_08132B84:
	ldr r0, =gUnknown_0202420C
_08132B86:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	bne _08132BC4
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132BCA
	.pool
_08132BC4:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132BCA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai3B_unk

	thumb_func_start tai3C_unk
tai3C_unk: @ 8132BD0
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08132BEC
	ldr r0, =gUnknown_0203AB3C
	b _08132BEE
	.pool
_08132BEC:
	ldr r0, =gUnknown_0202420C
_08132BEE:
	ldrb r3, [r0]
	ldr r1, =gBattleMons
	ldr r2, [r4]
	movs r0, 0x58
	muls r0, r3
	ldrb r3, [r2, 0x2]
	adds r0, r3
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	ldrb r1, [r2, 0x3]
	cmp r0, r1
	beq _08132C2C
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08132C32
	.pool
_08132C2C:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_08132C32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai3C_unk

	thumb_func_start tai3D_unk
tai3D_unk: @ 8132C38
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r2, =gBattleMoves
	ldr r0, =gUnknown_020244A8
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bls _08132D1C
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r7, 0x1
	strb r7, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r7, [r0]
	ldr r5, =gUnknown_020241EA
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	strh r0, [r5]
	ldr r4, =gUnknown_0203AB3C
	ldrb r0, [r4]
	ldr r6, =gUnknown_0202420C
	ldrb r1, [r6]
	bl sub_8046E7C
	ldrh r0, [r5]
	ldrb r1, [r4]
	ldrb r2, [r6]
	bl move_effectiveness_something
	ldr r4, =gUnknown_020241F0
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, 0x14]
	adds r0, r1, 0
	adds r0, 0x18
	ldrb r1, [r1, 0x1]
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, [r4]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08132CB8
	str r7, [r4]
_08132CB8:
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0, 0x28]
	ldr r0, [r4]
	cmp r1, r0
	bgt _08132D1C
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
	b _08132D24
	.pool
_08132D1C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08132D24:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai3D_unk

	thumb_func_start dp15_determine_move_damage_jump_if_not_fatal
dp15_determine_move_damage_jump_if_not_fatal: @ 8132D34
	push {r4-r7,lr}
	ldr r2, =gBattleMoves
	ldr r7, =gUnknown_020244A8
	ldr r0, [r7]
	ldr r0, [r0, 0x14]
	ldrh r1, [r0, 0x2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bls _08132E04
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r0, =gUnknown_0202427C
	strb r1, [r0]
	ldr r0, =gUnknown_02024211
	strb r2, [r0]
	ldr r6, =gUnknown_020241EA
	ldr r0, [r7]
	ldr r0, [r0, 0x14]
	ldrh r0, [r0, 0x2]
	strh r0, [r6]
	ldr r4, =gUnknown_0203AB3C
	ldrb r0, [r4]
	ldr r5, =gUnknown_0202420C
	ldrb r1, [r5]
	bl sub_8046E7C
	ldrh r0, [r6]
	ldrb r1, [r4]
	ldrb r2, [r5]
	bl move_effectiveness_something
	ldr r4, =gUnknown_020241F0
	ldr r0, [r7]
	ldr r1, [r0, 0x14]
	adds r0, r1, 0
	adds r0, 0x18
	ldrb r1, [r1, 0x1]
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, [r4]
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	ldr r3, =gBattleMons
	ldrb r2, [r5]
	movs r1, 0x58
	muls r1, r2
	adds r1, r3
	ldrh r1, [r1, 0x28]
	cmp r1, r0
	ble _08132E04
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
	b _08132E0C
	.pool
_08132E04:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08132E0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_determine_move_damage_jump_if_not_fatal

	thumb_func_start tai3F_unk
tai3F_unk: @ 8132E18
	push {r4-r7,lr}
	ldr r0, =gAIScriptPtr
	ldr r5, [r0]
	adds r7, r5, 0x2
	ldrb r1, [r5, 0x1]
	adds r6, r0, 0
	cmp r1, 0x1
	beq _08132E42
	cmp r1, 0x1
	bgt _08132E38
	cmp r1, 0
	beq _08132EDC
	b _08132F40
	.pool
_08132E38:
	cmp r1, 0x2
	beq _08132EDC
	cmp r1, 0x3
	beq _08132E84
	b _08132F40
_08132E42:
	movs r4, 0
	ldr r3, =gBattleMons
	ldr r2, =gUnknown_0203AB3C
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	adds r3, 0xC
	adds r0, r3
	ldrh r0, [r0]
	ldrh r5, [r5, 0x2]
	cmp r0, r5
	beq _08132E74
	movs r5, 0x58
_08132E5C:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08132E74
	lsls r1, r4, 1
	ldrb r0, [r2]
	muls r0, r5
	adds r1, r0
	adds r1, r3
	ldrh r0, [r1]
	ldrh r1, [r7]
	cmp r0, r1
	bne _08132E5C
_08132E74:
	cmp r4, 0x4
	beq _08132F18
	b _08132F28
	.pool
_08132E84:
	ldr r3, =gBattleMons
	ldr r2, =gUnknown_0203AB3C
	ldrb r1, [r2]
	movs r0, 0x2
	eors r0, r1
	movs r1, 0x58
	muls r1, r0
	adds r0, r1, r3
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08132EA8
	adds r0, r5, 0
	b _08132F1A
	.pool
_08132EA8:
	movs r4, 0
	adds r3, 0xC
	adds r0, r1, r3
	ldrh r0, [r0]
	ldrh r5, [r5, 0x2]
	cmp r0, r5
	beq _08132E74
	mov r12, r3
	adds r5, r2, 0
	movs r3, 0x2
_08132EBC:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08132E74
	lsls r1, r4, 1
	ldrb r0, [r5]
	adds r2, r3, 0
	eors r2, r0
	movs r0, 0x58
	muls r0, r2
	adds r1, r0
	add r1, r12
	ldrh r0, [r1]
	ldrh r1, [r7]
	cmp r0, r1
	bne _08132EBC
	b _08132E74
_08132EDC:
	movs r4, 0
	ldr r3, =gUnknown_020244A8
	ldr r0, [r3]
	ldr r1, [r0, 0x18]
	ldr r2, =gUnknown_0202420C
	ldrb r0, [r2]
	lsls r0, 4
	adds r1, r0
	ldrh r0, [r1]
	ldrh r1, [r7]
	cmp r0, r1
	beq _08132F14
	adds r7, r3, 0
	adds r5, r2, 0
	adds r3, r1, 0
_08132EFA:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08132F14
	ldr r0, [r7]
	ldr r2, [r0, 0x18]
	lsls r1, r4, 1
	ldrb r0, [r5]
	lsls r0, 4
	adds r1, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, r3
	bne _08132EFA
_08132F14:
	cmp r4, 0x4
	bne _08132F28
_08132F18:
	ldr r0, [r6]
_08132F1A:
	adds r0, 0x8
	str r0, [r6]
	b _08132F40
	.pool
_08132F28:
	ldr r2, [r6]
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r6]
_08132F40:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end tai3F_unk

	thumb_func_start tai40_unk
tai40_unk: @ 8132F48
	push {r4-r7,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r6, r0, 0x2
	ldrb r0, [r0, 0x1]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _08132F70
	cmp r0, 0x1
	bgt _08132F68
	cmp r0, 0
	beq _08132FB4
	b _08133018
	.pool
_08132F68:
	cmp r0, 0x2
	beq _08132FB4
	cmp r0, 0x3
	bne _08133018
_08132F70:
	movs r3, 0
	ldr r2, =gBattleMons
	ldr r4, =gUnknown_0203AB3C
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r2, 0xC
	adds r0, r2
	ldrh r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08132FA6
	adds r7, r4, 0
	movs r6, 0x58
	adds r4, r2, 0
	adds r2, r1, 0
_08132F90:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08132FA6
	lsls r1, r3, 1
	ldrb r0, [r7]
	muls r0, r6
	adds r1, r0
	adds r1, r4
	ldrh r0, [r1]
	cmp r0, r2
	bne _08132F90
_08132FA6:
	cmp r3, 0x4
	bne _08132FF0
	b _08133000
	.pool
_08132FB4:
	movs r3, 0
	ldr r4, =gUnknown_020244A8
	ldr r0, [r4]
	ldr r1, [r0, 0x18]
	ldr r2, =gUnknown_0202420C
	ldrb r0, [r2]
	lsls r0, 4
	adds r1, r0
	ldrh r0, [r1]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08132FEC
	adds r7, r4, 0
	adds r6, r2, 0
	adds r4, r1, 0
_08132FD2:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08132FEC
	ldr r0, [r7]
	ldr r2, [r0, 0x18]
	lsls r1, r3, 1
	ldrb r0, [r6]
	lsls r0, 4
	adds r1, r0
	adds r2, r1
	ldrh r0, [r2]
	cmp r0, r4
	bne _08132FD2
_08132FEC:
	cmp r3, 0x4
	beq _08133000
_08132FF0:
	ldr r0, [r5]
	adds r0, 0x8
	str r0, [r5]
	b _08133018
	.pool
_08133000:
	ldr r2, [r5]
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
_08133018:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end tai40_unk

	thumb_func_start tai41_unk
tai41_unk: @ 8133020
	push {r4-r7,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	adds r5, r1, 0
	cmp r0, 0x1
	beq _08133044
	cmp r0, 0x1
	bgt _0813303C
	cmp r0, 0
	beq _08133090
	b _08133110
	.pool
_0813303C:
	cmp r0, 0x2
	beq _08133090
	cmp r0, 0x3
	bne _08133110
_08133044:
	movs r3, 0
	ldr r1, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r2, [r0]
	ldr r6, =gBattleMoves
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r2, r0, r1
	ldr r4, =gAIScriptPtr
_08133058:
	ldrh r0, [r2]
	cmp r0, 0
	beq _08133072
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r1, [r4]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _0813307A
_08133072:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _08133058
_0813307A:
	cmp r3, 0x4
	beq _081330DC
	b _081330F8
	.pool
_08133090:
	movs r3, 0
	ldr r1, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r2, [r0]
	ldr r0, =gBattleMoves
	mov r12, r0
	ldr r7, =gUnknown_020244A8
	ldr r6, =gUnknown_0202420C
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r4, r0, r1
_081330A8:
	lsls r2, r3, 1
	ldrh r0, [r4]
	cmp r0, 0
	beq _081330D0
	ldr r0, [r7]
	ldr r1, [r0, 0x18]
	ldrb r0, [r6]
	lsls r0, 4
	adds r0, r2, r0
	adds r1, r0
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldr r1, [r5]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _081330D8
_081330D0:
	adds r4, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _081330A8
_081330D8:
	cmp r3, 0x4
	bne _081330F8
_081330DC:
	ldr r0, [r5]
	adds r0, 0x7
	str r0, [r5]
	b _08133110
	.pool
_081330F8:
	ldr r2, [r5]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
_08133110:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end tai41_unk

	thumb_func_start tai42_unk
tai42_unk: @ 8133118
	push {r4-r6,lr}
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	adds r4, r1, 0
	cmp r0, 0x1
	beq _0813313C
	cmp r0, 0x1
	bgt _08133134
	cmp r0, 0
	beq _08133188
	b _081331F4
	.pool
_08133134:
	cmp r0, 0x2
	beq _08133188
	cmp r0, 0x3
	bne _081331F4
_0813313C:
	movs r3, 0
	ldr r1, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r2, [r0]
	ldr r6, =gBattleMoves
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r2, r0, r1
	ldr r5, =gAIScriptPtr
_08133150:
	ldrh r0, [r2]
	cmp r0, 0
	beq _0813316A
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r1, [r5]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _08133172
_0813316A:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _08133150
_08133172:
	cmp r3, 0x4
	bne _081331C2
	b _081331DC
	.pool
_08133188:
	movs r3, 0
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r1, [r0, 0x18]
	ldr r0, =gUnknown_0202420C
	ldrb r0, [r0]
	ldr r6, =gBattleMoves
	lsls r0, 4
	adds r2, r0, r1
	ldr r5, =gAIScriptPtr
_0813319C:
	ldrh r0, [r2]
	cmp r0, 0
	beq _081331B6
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r1, [r5]
	ldrb r0, [r0]
	ldrb r1, [r1, 0x2]
	cmp r0, r1
	beq _081331BE
_081331B6:
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _0813319C
_081331BE:
	cmp r3, 0x4
	beq _081331DC
_081331C2:
	ldr r0, [r4]
	adds r0, 0x7
	str r0, [r4]
	b _081331F4
	.pool
_081331DC:
	ldr r2, [r4]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
_081331F4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end tai42_unk

	thumb_func_start tai43_unk
tai43_unk: @ 81331FC
	push {r4,r5,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x1
	bne _08133218
	ldr r0, =gUnknown_0203AB3C
	b _0813321A
	.pool
_08133218:
	ldr r0, =gUnknown_0202420C
_0813321A:
	ldrb r3, [r0]
	adds r4, r5, 0
	ldr r2, [r4]
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _08133240
	ldr r0, =gUnknown_020242BC
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x4]
	cmp r0, 0
	beq _08133244
	b _0813325A
	.pool
_08133240:
	cmp r0, 0x1
	beq _0813324A
_08133244:
	adds r0, r2, 0x7
	str r0, [r4]
	b _0813327C
_0813324A:
	ldr r0, =gUnknown_020242BC
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	cmp r0, 0
	beq _08133278
_0813325A:
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0813327C
	.pool
_08133278:
	adds r0, r2, 0x7
	str r0, [r5]
_0813327C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end tai43_unk

	thumb_func_start tai44_unk
tai44_unk: @ 8133284
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r3, [r4]
	ldrb r0, [r3, 0x1]
	cmp r0, 0
	beq _0813329C
	cmp r0, 0x1
	beq _081332C8
	b _08133308
	.pool
_0813329C:
	ldr r2, =gUnknown_020242BC
	ldr r0, =gUnknown_02024064
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x14]
	ldrh r0, [r0, 0x4]
	ldrh r1, [r1, 0x2]
	cmp r0, r1
	beq _081332E4
	b _08133308
	.pool
_081332C8:
	ldr r2, =gUnknown_020242BC
	ldr r0, =gUnknown_02024064
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x14]
	ldrh r0, [r0, 0x6]
	ldrh r1, [r1, 0x2]
	cmp r0, r1
	bne _08133308
_081332E4:
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
	b _0813330C
	.pool
_08133308:
	adds r0, r3, 0x6
	str r0, [r4]
_0813330C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai44_unk

	thumb_func_start tai45_unk
tai45_unk: @ 8133314
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldrb r1, [r2, 0x10]
	movs r0, 0xB
	orrs r0, r1
	strb r0, [r2, 0x10]
	bx lr
	.pool
	thumb_func_end tai45_unk

	thumb_func_start tai46_unk
tai46_unk: @ 8133328
	push {r4,lr}
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0x7B
	ldrb r0, [r0]
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	bcs _08133374
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
	b _0813337C
	.pool
_08133374:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0813337C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai46_unk

	thumb_func_start dp15_end_with_move_5
dp15_end_with_move_5: @ 8133388
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldrb r1, [r2, 0x10]
	movs r0, 0xD
	orrs r0, r1
	strb r0, [r2, 0x10]
	bx lr
	.pool
	thumb_func_end dp15_end_with_move_5

	thumb_func_start dp15_get_held_item_x12__8
dp15_get_held_item_x12__8: @ 813339C
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081333B4
	ldr r0, =gUnknown_0203AB3C
	b _081333B6
	.pool
_081333B4:
	ldr r0, =gUnknown_0202420C
_081333B6:
	ldrb r2, [r0]
	ldr r0, =gUnknown_02024064
	ldrb r0, [r0]
	cmp r0, r2
	beq _081333E0
	ldr r4, =gUnknown_020244A8
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	adds r0, 0x44
	adds r0, r2
	ldrb r0, [r0]
	bl itemid_get_x12
	ldr r1, [r4]
	b _081333F2
	.pool
_081333E0:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	bl itemid_get_x12
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
_081333F2:
	ldr r1, [r1, 0x14]
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_held_item_x12__8

	thumb_func_start tai62_unk
tai62_unk: @ 8133414
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl sub_8131E70
	lsls r0, 24
	lsrs r3, r0, 24
	movs r0, 0x1
	ldr r1, =gUnknown_0203AB3C
	ldrb r2, [r1]
	adds r1, r3, 0
	ands r1, r0
	ands r0, r2
	cmp r1, r0
	bne _0813344C
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r0, r1
	ldrh r3, [r0, 0x2E]
	b _08133458
	.pool
_0813344C:
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	adds r0, 0x44
	adds r0, r3
	ldrb r3, [r0]
_08133458:
	ldr r4, =gAIScriptPtr
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	orrs r0, r1
	cmp r0, r3
	bne _08133488
	ldrb r1, [r2, 0x4]
	ldrb r0, [r2, 0x5]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _0813348E
	.pool
_08133488:
	adds r0, r2, 0
	adds r0, 0x8
	str r0, [r4]
_0813348E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai62_unk

	thumb_func_start tai49_unk
tai49_unk: @ 8133494
	push {lr}
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x1
	bne _081334AC
	ldr r0, =gUnknown_0203AB3C
	b _081334AE
	.pool
_081334AC:
	ldr r0, =gUnknown_0202420C
_081334AE:
	ldrb r1, [r0]
	ldr r2, =gBattleMons
	movs r0, 0x58
	muls r1, r0
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r2, 0x48
	adds r1, r2
	ldr r1, [r1]
	bl pokemon_species_get_gender_info
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x14]
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai49_unk

	thumb_func_start dp15_enter_battle_countdown_get_state
dp15_enter_battle_countdown_get_state: @ 81334EC
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08133508
	ldr r0, =gUnknown_0203AB3C
	b _0813350A
	.pool
_08133508:
	ldr r0, =gUnknown_0202420C
_0813350A:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_020242BC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_enter_battle_countdown_get_state

	thumb_func_start dp15_stockpile_get_num_uses
dp15_stockpile_get_num_uses: @ 8133538
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08133554
	ldr r0, =gUnknown_0203AB3C
	b _08133556
	.pool
_08133554:
	ldr r0, =gUnknown_0202420C
_08133556:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_020242BC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x9]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_stockpile_get_num_uses

	thumb_func_start dp15_is_double_battle
dp15_is_double_battle: @ 8133584
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	str r0, [r2, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_is_double_battle

	thumb_func_start dp15_get_dp08_item__8
dp15_get_dp08_item__8: @ 81335AC
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _081335C8
	ldr r0, =gUnknown_0203AB3C
	b _081335CA
	.pool
_081335C8:
	ldr r0, =gUnknown_0202420C
_081335CA:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	lsls r0, r3, 1
	adds r0, r1
	adds r0, 0xB8
	ldrb r0, [r0]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_dp08_item__8

	thumb_func_start dp15_move_get_type__8
dp15_move_get_type__8: @ 81335F8
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldr r1, [r3, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_type__8

	thumb_func_start dp15_move_get_power__8_8
dp15_move_get_power__8_8: @ 8133624
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldr r1, [r3, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_power__8_8

	thumb_func_start dp15_move_get_move_script_id__8
dp15_move_get_move_script_id__8: @ 8133650
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r3, [r0, 0x14]
	ldr r2, =gBattleMoves
	ldr r1, [r3, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	str r0, [r3, 0x8]
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end dp15_move_get_move_script_id__8

	thumb_func_start dp15_get_protect_endure_activity
dp15_get_protect_endure_activity: @ 813367C
	push {r4,lr}
	ldr r0, =gAIScriptPtr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _08133698
	ldr r0, =gUnknown_0203AB3C
	b _0813369A
	.pool
_08133698:
	ldr r0, =gUnknown_0202420C
_0813369A:
	ldrb r3, [r0]
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldr r1, =gUnknown_020242BC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
	str r0, [r2, 0x8]
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_get_protect_endure_activity

	thumb_func_start nullsub_106
nullsub_106: @ 81336C8
	bx lr
	thumb_func_end nullsub_106

	thumb_func_start nullsub_107
nullsub_107: @ 81336CC
	bx lr
	thumb_func_end nullsub_107

	thumb_func_start nullsub_108
nullsub_108: @ 81336D0
	bx lr
	thumb_func_end nullsub_108

	thumb_func_start nullsub_109
nullsub_109: @ 81336D4
	bx lr
	thumb_func_end nullsub_109

	thumb_func_start nullsub_110
nullsub_110: @ 81336D8
	bx lr
	thumb_func_end nullsub_110

	thumb_func_start nullsub_111
nullsub_111: @ 81336DC
	bx lr
	thumb_func_end nullsub_111

	thumb_func_start tai58_unk
tai58_unk: @ 81336E0
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	adds r0, 0x5
	bl b_mc_stack_push
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
	thumb_func_end tai58_unk

	thumb_func_start dp15_jump
dp15_jump: @ 8133710
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
	thumb_func_end dp15_jump

	thumb_func_start dp15_return
dp15_return: @ 8133730
	push {lr}
	bl b_mc_stack_pop_cursor
	lsls r0, 24
	cmp r0, 0
	bne _0813374A
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x14]
	ldrb r1, [r2, 0x10]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x10]
_0813374A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp15_return

	thumb_func_start dp15_compare_attacker_defender_levels
dp15_compare_attacker_defender_levels: @ 8133754
	push {r4,r5,lr}
	ldr r5, =gAIScriptPtr
	ldr r4, [r5]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x1
	beq _081337A8
	cmp r0, 0x1
	bgt _08133770
	cmp r0, 0
	beq _08133776
	b _08133824
	.pool
_08133770:
	cmp r0, 0x2
	beq _081337D8
	b _08133824
_08133776:
	ldr r3, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gUnknown_0202420C
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhi _081337FA
	b _08133820
	.pool
_081337A8:
	ldr r3, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gUnknown_0202420C
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _081337FA
	b _08133820
	.pool
_081337D8:
	ldr r3, =gBattleMons
	ldr r0, =gUnknown_0203AB3C
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gUnknown_0202420C
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08133820
_081337FA:
	ldrb r1, [r4, 0x2]
	ldrb r0, [r4, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r4, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r4, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r5]
	b _08133824
	.pool
_08133820:
	adds r0, r4, 0x6
	str r0, [r5]
_08133824:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp15_compare_attacker_defender_levels

	thumb_func_start tai5C_unk
tai5C_unk: @ 813382C
	push {lr}
	ldr r2, =gUnknown_020242BC
	ldr r0, =gUnknown_0202420C
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	lsls r0, 28
	cmp r0, 0
	beq _0813386C
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
	b _08133874
	.pool
_0813386C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08133874:
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5C_unk

	thumb_func_start tai5D_unk
tai5D_unk: @ 813387C
	push {lr}
	ldr r2, =gUnknown_020242BC
	ldr r0, =gUnknown_0202420C
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	lsls r0, 28
	cmp r0, 0
	bne _081338BC
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
	b _081338C4
	.pool
_081338BC:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_081338C4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5D_unk

	thumb_func_start tai5E_unk
tai5E_unk: @ 81338CC
	push {lr}
	ldr r0, =gUnknown_0203AB3C
	ldrb r3, [r0]
	movs r0, 0x1
	ldr r1, =gUnknown_0202420C
	ldrb r2, [r1]
	adds r1, r0, 0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _0813390C
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
	b _08133914
	.pool
_0813390C:
	ldr r1, =gAIScriptPtr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08133914:
	pop {r0}
	bx r0
	.pool
	thumb_func_end tai5E_unk

	thumb_func_start tai61_unk
tai61_unk: @ 813391C
	push {r4,lr}
	ldr r4, =gAIScriptPtr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl sub_8131E70
	lsls r0, 24
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	lsrs r0, 22
	adds r1, r0
	ldr r0, [r1]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08133960
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r1, r0
	str r1, [r4]
	b _08133966
	.pool
_08133960:
	ldr r0, [r4]
	adds r0, 0x6
	str r0, [r4]
_08133966:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end tai61_unk

	thumb_func_start b_mc_stack_push
b_mc_stack_push: @ 813396C
	push {r4,lr}
	ldr r1, =gUnknown_020244A8
	ldr r1, [r1]
	ldr r3, [r1, 0x1C]
	adds r4, r3, 0
	adds r4, 0x20
	ldrb r1, [r4]
	adds r2, r1, 0x1
	strb r2, [r4]
	lsls r1, 24
	lsrs r1, 22
	adds r3, r1
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_mc_stack_push

	thumb_func_start b_mc_stack_push_cursor
b_mc_stack_push_cursor: @ 8133990
	ldr r0, =gUnknown_020244A8
	ldr r0, [r0]
	ldr r2, [r0, 0x1C]
	adds r3, r2, 0
	adds r3, 0x20
	ldrb r0, [r3]
	adds r1, r0, 0x1
	strb r1, [r3]
	lsls r0, 24
	lsrs r0, 22
	adds r2, r0
	ldr r0, =gAIScriptPtr
	ldr r0, [r0]
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end b_mc_stack_push_cursor

	thumb_func_start b_mc_stack_pop_cursor
b_mc_stack_pop_cursor: @ 81339B8
	push {lr}
	ldr r3, =gUnknown_020244A8
	ldr r0, [r3]
	ldr r0, [r0, 0x1C]
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _081339D4
	movs r0, 0
	b _081339EE
	.pool
_081339D4:
	subs r0, 0x1
	strb r0, [r1]
	ldr r2, =gAIScriptPtr
	ldr r0, [r3]
	ldr r1, [r0, 0x1C]
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	movs r0, 0x1
_081339EE:
	pop {r1}
	bx r1
	.pool
	thumb_func_end b_mc_stack_pop_cursor

	.align 2, 0 @ Don't pad with nop.
