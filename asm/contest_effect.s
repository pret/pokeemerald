	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AreMovesContestCombo
@ u8 AreMovesContestCombo(u16 moveId1, u16 moveId2)
AreMovesContestCombo: @ 80E5414
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 16
	lsls r1, 16
	ldr r2, =gContestMoves
	lsrs r0, 13
	adds r0, r2
	ldrb r4, [r0, 0x2]
	mov r3, sp
	lsrs r1, 13
	adds r1, r2
	ldrb r0, [r1, 0x3]
	strb r0, [r3]
	mov r2, sp
	ldrb r0, [r1, 0x4]
	strb r0, [r2, 0x1]
	ldrb r0, [r1, 0x5]
	strb r0, [r2, 0x2]
	mov r0, sp
	ldrb r1, [r1, 0x6]
	strb r1, [r0, 0x3]
	cmp r4, 0
	beq _080E5470
	mov r0, sp
	ldrb r0, [r0]
	cmp r4, r0
	beq _080E545E
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r4, r0
	beq _080E545E
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r4, r0
	beq _080E545E
	cmp r4, r1
	bne _080E5470
_080E545E:
	ldr r0, =gComboStarterLookupTable
	adds r0, r4, r0
	ldrb r0, [r0]
	b _080E5472
	.pool
_080E5470:
	movs r0, 0
_080E5472:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end AreMovesContestCombo

	thumb_func_start ContestEffectFunc_080E547C
ContestEffectFunc_080E547C: @ 80E547C
	bx lr
	thumb_func_end ContestEffectFunc_080E547C

	thumb_func_start ContestEffectFunc_080E5480
ContestEffectFunc_080E5480: @ 80E5480
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x10]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x10]
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5480

	thumb_func_start ContestEffectFunc_080E54B0
ContestEffectFunc_080E54B0: @ 80E54B0
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x11]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x11]
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E54B0

	thumb_func_start ContestEffectFunc_080E54E0
ContestEffectFunc_080E54E0: @ 80E54E0
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x10]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x10]
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x15]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0xB]
	movs r0, 0x71
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xB]
	bx lr
	.pool
	thumb_func_end ContestEffectFunc_080E54E0

	thumb_func_start ContestEffectFunc_080E5534
ContestEffectFunc_080E5534: @ 80E5534
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0, 0x12]
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x2
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5534

	thumb_func_start ContestEffectFunc_080E5560
ContestEffectFunc_080E5560: @ 80E5560
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x10]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0, 0x10]
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x3
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5560

	thumb_func_start ContestEffectFunc_080E5590
ContestEffectFunc_080E5590: @ 80E5590
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x14
	strb r1, [r0, 0xF]
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x4
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5590

	thumb_func_start ContestEffectFunc_080E55BC
ContestEffectFunc_080E55BC: @ 80E55BC
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x10]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x10]
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x5
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E55BC

	thumb_func_start ContestEffectFunc_080E55EC
ContestEffectFunc_080E55EC: @ 80E55EC
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	ldrb r4, [r1, 0x11]
	adds r3, r1, r4
	ldrb r0, [r3]
	cmp r0, 0
	beq _080E563A
	subs r0, 0x1
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E5622
	adds r3, r5, 0
_080E560A:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080E5622
	ldr r0, [r3]
	ldr r1, [r0, 0x8]
	adds r0, r1, r4
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	bne _080E560A
_080E5622:
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	strb r2, [r0, 0x8]
	ldr r0, [r1]
	ldr r1, [r0, 0x8]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	bl sub_80E6A2C
	lsls r0, 24
	lsrs r2, r0, 24
_080E563A:
	cmp r2, 0
	bne _080E564C
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E564C:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E55EC

	thumb_func_start ContestEffectFunc_080E5664
ContestEffectFunc_080E5664: @ 80E5664
	push {r4-r6,lr}
	movs r1, 0
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	ldrb r5, [r0, 0x11]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E56B4
	movs r3, 0
	movs r4, 0
	adds r6, r2, 0
_080E567E:
	ldr r0, [r6]
	ldr r2, [r0, 0x8]
	adds r0, r2, r5
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080E5698
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r4
	strb r3, [r0]
	adds r4, 0x1
_080E5698:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080E567E
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
	bl sub_80E6A2C
	lsls r0, 24
	lsrs r1, r0, 24
_080E56B4:
	cmp r1, 0
	bne _080E56C6
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E56C6:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5664

	thumb_func_start ContestEffectFunc_080E56E0
ContestEffectFunc_080E56E0: @ 80E56E0
	push {lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x14
	cmp r0, 0x1
	bls _080E5702
	movs r1, 0x3C
	cmp r0, 0x7
	bhi _080E5702
	movs r1, 0x28
_080E5702:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strh r1, [r0, 0x4]
	bl ContestEffectFunc_080E55EC
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E56E0

	thumb_func_start ContestEffectFunc_080E5718
ContestEffectFunc_080E5718: @ 80E5718
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r5, [r0, 0x11]
	adds r0, r5
	ldrb r0, [r0]
	mov r8, r1
	cmp r0, 0
	beq _080E579E
	movs r4, 0
	mov r6, r8
_080E5736:
	ldr r0, [r6]
	ldr r2, [r0, 0x8]
	adds r0, r2, r5
	adds r1, r2, r4
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080E5798
	strb r4, [r2, 0x8]
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	cmp r0, 0
	beq _080E5782
	movs r1, 0xA
	cmp r0, 0x2
	bls _080E5782
	movs r1, 0x14
	cmp r0, 0x4
	bls _080E5782
	movs r1, 0x1E
	cmp r0, 0x6
	bls _080E5782
	movs r1, 0x3C
	cmp r0, 0x8
	bhi _080E5782
	movs r1, 0x28
_080E5782:
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	strh r1, [r0, 0x4]
	bl sub_80E6A2C
	lsls r0, 24
	cmp r0, 0
	beq _080E5798
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_080E5798:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080E5736
_080E579E:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	cmp r7, 0
	bne _080E57BE
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E57BE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5718

	thumb_func_start ContestEffectFunc_080E57CC
ContestEffectFunc_080E57CC: @ 80E57CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r9, r0
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r2, [r0, 0x11]
	mov r8, r2
	add r0, r8
	ldrb r0, [r0]
	mov r10, r1
	cmp r0, 0
	beq _080E5858
	movs r6, 0
	mov r7, r10
	movs r5, 0
_080E57F4:
	ldr r2, [r7]
	ldr r0, [r2, 0x8]
	mov r3, r8
	adds r1, r0, r3
	adds r0, r6
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls _080E5850
	ldr r0, [r2, 0x4]
	adds r0, r5, r0
	ldrb r1, [r0, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080E5850
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80E69C8
	lsls r0, 24
	cmp r0, 0
	beq _080E5850
	ldr r0, [r7]
	ldr r2, [r0, 0x4]
	adds r2, r5, r2
	ldrb r0, [r2, 0x15]
	movs r3, 0x11
	negs r3, r3
	adds r1, r3, 0
	ands r0, r1
	strb r0, [r2, 0x15]
	ldr r0, [r7]
	ldr r2, [r0, 0x4]
	adds r2, r5, r2
	ldrb r0, [r2, 0x15]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x15]
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_80DD3D4
	movs r0, 0x1
	mov r9, r0
_080E5850:
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _080E57F4
_080E5858:
	mov r1, r10
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x7
	bl sub_80DD3D4
	mov r2, r9
	cmp r2, 0
	bne _080E587A
	mov r3, r10
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E587A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E57CC

	thumb_func_start ContestEffectFunc_080E588C
ContestEffectFunc_080E588C: @ 80E588C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	mov r9, r0
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r7, [r0, 0x11]
	adds r0, r7
	ldrb r0, [r0]
	adds r4, r1, 0
	cmp r0, 0
	beq _080E590A
	movs r5, 0
	movs r6, 0
	mov r8, r4
_080E58B0:
	ldr r3, [r4]
	ldr r2, [r3, 0x8]
	adds r0, r2, r7
	adds r1, r2, r5
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080E5900
	ldr r0, [r3, 0x4]
	adds r0, r6, r0
	ldrb r1, [r0, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080E58D8
	movs r0, 0x32
	b _080E58DA
	.pool
_080E58D8:
	movs r0, 0xA
_080E58DA:
	strh r0, [r2, 0x4]
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	strb r5, [r0, 0x8]
	ldr r0, [r1]
	ldr r1, [r0, 0x8]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	bl sub_80E6A2C
	lsls r0, 24
	cmp r0, 0
	beq _080E5900
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080E5900:
	adds r6, 0x1C
	adds r5, 0x1
	ldr r4, =gContestResources
	cmp r5, 0x3
	ble _080E58B0
_080E590A:
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	mov r0, r9
	cmp r0, 0
	bne _080E5928
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E5928:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E588C

	thumb_func_start ContestEffectFunc_080E5938
ContestEffectFunc_080E5938: @ 80E5938
	push {r4,lr}
	ldr r4, =gContestResources
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x11]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0, 0x11]
	bl ContestEffectFunc_080E5664
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5938

	thumb_func_start ContestEffectFunc_080E5970
ContestEffectFunc_080E5970: @ 80E5970
	push {r4,lr}
	ldr r4, =gContestResources
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 29
	bl sub_80E6934
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5970

	thumb_func_start ContestEffectFunc_080E59B0
ContestEffectFunc_080E59B0: @ 80E59B0
	push {lr}
	movs r0, 0
	bl sub_80E6934
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E59B0

	thumb_func_start ContestEffectFunc_080E59D0
ContestEffectFunc_080E59D0: @ 80E59D0
	push {lr}
	movs r0, 0x1
	bl sub_80E6934
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E59D0

	thumb_func_start ContestEffectFunc_080E59F0
ContestEffectFunc_080E59F0: @ 80E59F0
	push {lr}
	movs r0, 0x2
	bl sub_80E6934
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E59F0

	thumb_func_start ContestEffectFunc_080E5A10
ContestEffectFunc_080E5A10: @ 80E5A10
	push {lr}
	movs r0, 0x3
	bl sub_80E6934
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5A10

	thumb_func_start ContestEffectFunc_080E5A30
ContestEffectFunc_080E5A30: @ 80E5A30
	push {lr}
	movs r0, 0x4
	bl sub_80E6934
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5A30

	thumb_func_start ContestEffectFunc_080E5A50
ContestEffectFunc_080E5A50: @ 80E5A50
	push {r4-r6,lr}
	movs r4, 0
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x11]
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r2, 0
	cmp r0, 0x3
	beq _080E5AB0
	movs r5, 0
_080E5A68:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	ldrb r0, [r1, 0x11]
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r0, 0x1
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	bne _080E5AAA
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80E69C8
	lsls r0, 24
	cmp r0, 0
	beq _080E5AA0
	adds r0, r4, 0
	bl sub_80DD560
	adds r0, r4, 0
	movs r1, 0xA
	b _080E5AA4
	.pool
_080E5AA0:
	adds r0, r4, 0
	movs r1, 0x3C
_080E5AA4:
	bl sub_80DD3D4
	movs r4, 0x1
_080E5AAA:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080E5A68
_080E5AB0:
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x9
	bl sub_80DD3D4
	cmp r4, 0
	bne _080E5ACC
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E5ACC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E5A50

	thumb_func_start ContestEffectFunc_080E5AD4
ContestEffectFunc_080E5AD4: @ 80E5AD4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	movs r0, 0
	mov r9, r0
	movs r1, 0
	str r1, [sp, 0x18]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0x5
	bl memset
	movs r5, 0
	movs r4, 0
	add r2, sp, 0x10
	mov r8, r2
	add r3, sp, 0x8
	mov r10, r3
	movs r6, 0
_080E5B00:
	ldr r0, =gContestResources
	ldr r2, [r0]
	ldr r1, [r2, 0x8]
	ldrb r0, [r1, 0x11]
	adds r0, r1, r0
	adds r1, r5
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080E5B38
	ldr r0, [r2, 0x4]
	adds r0, r6, r0
	ldrb r1, [r0, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080E5B38
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80DBCA8
	lsls r0, 24
	cmp r0, 0
	bne _080E5B38
	mov r1, sp
	adds r0, r1, r4
	strb r5, [r0]
	adds r4, 0x1
_080E5B38:
	adds r6, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080E5B00
	cmp r4, 0x1
	bne _080E5B50
	movs r0, 0x3C
	mov r2, r8
	strh r0, [r2]
	b _080E5B7E
	.pool
_080E5B50:
	cmp r4, 0x2
	bne _080E5B5E
	movs r0, 0x1E
	mov r3, r8
	strh r0, [r3]
	strh r0, [r3, 0x2]
	b _080E5B7E
_080E5B5E:
	cmp r4, 0x3
	bne _080E5B6E
	movs r0, 0x14
	mov r6, r8
	strh r0, [r6]
	strh r0, [r6, 0x2]
	strh r0, [r6, 0x4]
	b _080E5B7E
_080E5B6E:
	mov r1, r8
	movs r2, 0
	mov r0, r8
	adds r0, 0x6
_080E5B76:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080E5B76
_080E5B7E:
	movs r5, 0
	ldr r7, =gContestResources
	movs r6, 0
	mov r4, r10
_080E5B86:
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r1, [r0, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080E5BD0
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80DE1E8
	lsls r0, 24
	cmp r0, 0
	beq _080E5BD0
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrh r0, [r0, 0x8]
	lsls r0, 3
	ldr r1, =gContestMoves
	adds r0, r1
	ldrb r0, [r0, 0x2]
	ldr r2, =gComboStarterLookupTable
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	b _080E5BD2
	.pool
_080E5BD0:
	movs r0, 0
_080E5BD2:
	strh r0, [r4]
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r0, [r0, 0xD]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0xA
	bl __divsi3
	lsls r0, 24
	asrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	ldrh r0, [r4]
	subs r0, r1
	strh r0, [r4]
	adds r6, 0x1C
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080E5B86
	mov r3, r8
	movs r6, 0
	ldrsh r0, [r3, r6]
	cmp r0, 0
	beq _080E5CA0
	movs r5, 0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _080E5CA0
	mov r4, sp
_080E5C16:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r5, 1
	add r1, r8
	movs r3, 0
	ldrsh r2, [r1, r3]
	ldrb r3, [r4]
	lsls r1, r3, 1
	add r1, r10
	movs r6, 0
	ldrsh r1, [r1, r6]
	adds r2, r1
	cmp r0, r2
	bge _080E5C66
	adds r0, r3, 0
	bl sub_80E69C8
	lsls r0, 24
	cmp r0, 0
	beq _080E5C70
	ldrb r0, [r4]
	bl sub_80DD560
	ldrb r0, [r4]
	movs r1, 0xA
	bl sub_80DD3D4
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	b _080E5C6A
_080E5C66:
	movs r0, 0x1
	str r0, [sp, 0x18]
_080E5C6A:
	ldr r1, [sp, 0x18]
	cmp r1, 0
	beq _080E5C86
_080E5C70:
	movs r2, 0
	str r2, [sp, 0x18]
	ldrb r0, [r4]
	movs r1, 0x3C
	bl sub_80DD3D4
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080E5C86:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0xD
	ldrb r3, [r4]
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	adds r4, 0x1
	adds r5, 0x1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _080E5C16
_080E5CA0:
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0xB
	bl sub_80DD3D4
	mov r0, r9
	cmp r0, 0
	bne _080E5CC0
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E5CC0:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5AD4

	thumb_func_start ContestEffectFunc_080E5CD4
ContestEffectFunc_080E5CD4: @ 80E5CD4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	movs r6, 0
	ldr r7, =gContestResources
	movs r5, 0
_080E5CE4:
	ldr r2, [r7]
	ldr r0, [r2, 0x8]
	ldrb r1, [r0, 0x11]
	adds r1, r0, r1
	adds r0, r6
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls _080E5D46
	ldr r0, [r2, 0x4]
	adds r0, r5, r0
	ldrb r0, [r0, 0xD]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _080E5D46
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_80E69C8
	lsls r0, 24
	cmp r0, 0
	beq _080E5D46
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r0, r5, r0
	movs r1, 0
	strb r1, [r0, 0xD]
	ldr r0, [r7]
	ldr r2, [r0, 0x4]
	adds r2, r5, r2
	ldrb r1, [r2, 0x10]
	movs r3, 0x31
	negs r3, r3
	adds r0, r3, 0
	ands r1, r0
	movs r0, 0x20
	orrs r1, r0
	strb r1, [r2, 0x10]
	adds r0, r4, 0
	movs r1, 0xD
	bl sub_80DD3D4
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_080E5D46:
	adds r5, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _080E5CE4
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0xC
	bl sub_80DD3D4
	mov r0, r8
	cmp r0, 0
	bne _080E5D6E
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x39
	bl sub_80DD3F0
_080E5D6E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5CD4

	thumb_func_start ContestEffectFunc_080E5D7C
ContestEffectFunc_080E5D7C: @ 80E5D7C
	push {r4-r7,lr}
	movs r7, 0
	movs r4, 0
	ldr r5, =gContestResources
	movs r6, 0
_080E5D86:
	ldr r3, [r5]
	ldr r2, [r3, 0x8]
	ldrb r0, [r2, 0x11]
	adds r0, r2, r0
	adds r1, r2, r4
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080E5DD2
	ldr r0, [r3, 0x4]
	adds r0, r6, r0
	ldrb r0, [r0, 0xD]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _080E5DB0
	movs r0, 0x28
	b _080E5DB2
	.pool
_080E5DB0:
	movs r0, 0xA
_080E5DB2:
	strh r0, [r2, 0x4]
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	strb r4, [r0, 0x8]
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	bl sub_80E6A2C
	lsls r0, 24
	cmp r0, 0
	beq _080E5DD2
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_080E5DD2:
	adds r6, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080E5D86
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0xE
	bl sub_80DD3D4
	cmp r7, 0
	bne _080E5DF8
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x39
	bl sub_80DD3F0
_080E5DF8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5D7C

	thumb_func_start ContestEffectFunc_080E5E04
ContestEffectFunc_080E5E04: @ 80E5E04
	push {r4,lr}
	ldr r1, =gUnknown_02039F26
	ldr r0, =gContestResources
	ldr r4, [r0]
	ldr r0, [r4, 0x8]
	ldrb r2, [r0, 0x11]
	adds r1, r2, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _080E5E46
	ldr r0, [r4, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	ldr r3, =gContestEffects
	ldr r2, =gContestMoves
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	ldrh r2, [r1, 0x2]
	adds r0, r2
	strh r0, [r1, 0x2]
	ldr r0, [r4, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0xF
	bl sub_80DD3D4
_080E5E46:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5E04

	thumb_func_start ContestEffectFunc_080E5E5C
ContestEffectFunc_080E5E5C: @ 80E5E5C
	push {r4,lr}
	ldr r1, =gUnknown_02039F26
	ldr r0, =gContestResources
	ldr r4, [r0]
	ldr r0, [r4, 0x8]
	ldrb r2, [r0, 0x11]
	adds r1, r2, r1
	ldrb r0, [r1]
	cmp r0, 0x3
	bne _080E5E9E
	ldr r0, [r4, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	ldr r3, =gContestEffects
	ldr r2, =gContestMoves
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	ldrh r2, [r1, 0x2]
	adds r0, r2
	strh r0, [r1, 0x2]
	ldr r0, [r4, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x10
	bl sub_80DD3D4
_080E5E9E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5E5C

	thumb_func_start ContestEffectFunc_080E5EB4
ContestEffectFunc_080E5EB4: @ 80E5EB4
	push {r4-r7,lr}
	movs r1, 0
	movs r5, 0
	ldr r0, =gContestResources
	ldr r4, [r0]
	ldr r2, [r4, 0x8]
	ldrb r0, [r2, 0x11]
	adds r0, r2, r0
	ldrb r6, [r0]
	movs r3, 0
_080E5EC8:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r6, r0
	bls _080E5EDA
	ldr r0, [r4, 0x4]
	adds r0, r3, r0
	movs r7, 0x2
	ldrsh r0, [r0, r7]
	adds r5, r0
_080E5EDA:
	adds r3, 0x1C
	adds r1, 0x1
	cmp r1, 0x3
	ble _080E5EC8
	cmp r5, 0
	bge _080E5EE8
	movs r5, 0
_080E5EE8:
	ldr r0, =gContestResources
	ldr r3, [r0]
	ldr r0, [r3, 0x8]
	ldrb r2, [r0, 0x11]
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E5EFC
	cmp r5, 0
	bne _080E5F0C
_080E5EFC:
	adds r0, r2, 0
	movs r1, 0x12
	bl sub_80DD3D4
	b _080E5F2C
	.pool
_080E5F0C:
	ldr r0, [r3, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r0, 1
	ldrh r2, [r1, 0x2]
	adds r0, r2
	strh r0, [r1, 0x2]
	ldr r0, [r3, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x11
	bl sub_80DD3D4
_080E5F2C:
	ldr r4, =gContestResources
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	movs r7, 0x2
	ldrsh r0, [r0, r7]
	bl sub_80E6B70
	ldr r2, [r4]
	ldr r1, [r2, 0x8]
	ldrb r3, [r1, 0x11]
	ldr r2, [r2, 0x4]
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r2
	strh r0, [r1, 0x2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E5EB4

	thumb_func_start ContestEffectFunc_080E5F64
ContestEffectFunc_080E5F64: @ 80E5F64
	push {r4-r7,lr}
	movs r6, 0
	ldr r0, =gContestResources
	ldr r4, [r0]
	ldr r2, [r4, 0x8]
	ldrb r1, [r2, 0x11]
	adds r3, r2, r1
	ldrb r1, [r3]
	adds r7, r0, 0
	cmp r1, 0
	beq _080E5FB2
	movs r1, 0
	adds r5, r4, 0
	adds r4, r2, 0
	ldrb r0, [r3]
	subs r3, r0, 0x1
	movs r2, 0
_080E5F86:
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r3, r0
	bne _080E5F94
	ldr r0, [r5, 0x4]
	adds r0, r2, r0
	ldrh r6, [r0, 0x2]
_080E5F94:
	adds r2, 0x1C
	adds r1, 0x1
	cmp r1, 0x3
	ble _080E5F86
	ldr r3, [r7]
	ldr r0, [r3, 0x8]
	ldrb r2, [r0, 0x11]
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E5FB2
	lsls r0, r6, 16
	asrs r4, r0, 16
	cmp r4, 0
	bgt _080E5FC4
_080E5FB2:
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x14
	bl sub_80DD3D4
	b _080E5FDE
	.pool
_080E5FC4:
	ldr r1, [r3, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0, 0x2]
	adds r1, r4, r1
	strh r1, [r0, 0x2]
	ldr r0, [r3, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x13
	bl sub_80DD3D4
_080E5FDE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E5F64

	thumb_func_start ContestEffectFunc_080E5FE4
ContestEffectFunc_080E5FE4: @ 80E5FE4
	push {r4,r5,lr}
	ldr r1, =gContestResources
	ldr r3, [r1]
	ldr r0, [r3, 0x8]
	ldrb r2, [r0, 0x11]
	adds r0, r2
	ldrb r4, [r0]
	adds r5, r1, 0
	cmp r4, 0
	bne _080E600C
	ldr r0, [r3, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	movs r0, 0xA
	b _080E601C
	.pool
_080E600C:
	ldr r0, [r3, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 2
_080E601C:
	strh r0, [r1, 0x2]
	cmp r4, 0
	bne _080E6030
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x15
	bl sub_80DD3D4
	b _080E6060
_080E6030:
	cmp r4, 0x1
	bne _080E6042
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x16
	bl sub_80DD3D4
	b _080E6060
_080E6042:
	cmp r4, 0x2
	bne _080E6054
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x17
	bl sub_80DD3D4
	b _080E6060
_080E6054:
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x18
	bl sub_80DD3D4
_080E6060:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E5FE4

	thumb_func_start ContestEffectFunc_080E6068
ContestEffectFunc_080E6068: @ 80E6068
	push {r4,lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x2
	bhi _080E6098
	movs r4, 0xA
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1A
	bl sub_80DD3D4
	b _080E60FC
	.pool
_080E6098:
	cmp r0, 0x5
	bhi _080E60B4
	movs r4, 0x14
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1B
	bl sub_80DD3D4
	b _080E60FC
	.pool
_080E60B4:
	cmp r0, 0x7
	bhi _080E60D0
	movs r4, 0x28
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1C
	bl sub_80DD3D4
	b _080E60FC
	.pool
_080E60D0:
	cmp r1, 0x8
	bhi _080E60EC
	movs r4, 0x3C
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1D
	bl sub_80DD3D4
	b _080E60FC
	.pool
_080E60EC:
	movs r4, 0x50
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1E
	bl sub_80DD3D4
_080E60FC:
	ldr r0, =gContestResources
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	strh r4, [r0, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E6068

	thumb_func_start ContestEffectFunc_080E611C
ContestEffectFunc_080E611C: @ 80E611C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r3, [r0, 0x8]
	ldrb r0, [r3, 0x11]
	adds r0, r3, r0
	movs r1, 0
	ldrsb r1, [r0, r1]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r2
	cmp r1, 0
	beq _080E61F8
	mov r7, r8
	ldrb r6, [r3]
_080E6140:
	movs r2, 0
	lsls r0, r4, 24
	asrs r1, r0, 24
	adds r5, r0, 0
	cmp r6, r1
	beq _080E616A
	ldr r4, =gContestResources
_080E614E:
	lsls r0, r2, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r2, r0, 24
	asrs r3, r0, 24
	cmp r3, 0x3
	bgt _080E616A
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, r1
	bne _080E614E
_080E616A:
	ldr r0, [r7]
	lsls r3, r2, 24
	asrs r1, r3, 24
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r2, r0, r2
	ldrb r1, [r2, 0xB]
	movs r0, 0x80
	ands r0, r1
	mov r12, r3
	cmp r0, 0
	bne _080E6190
	ldrb r1, [r2, 0xC]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _080E61A4
_080E6190:
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r5, r1
	lsrs r4, r0, 24
	cmp r0, 0
	blt _080E61F8
	b _080E6140
	.pool
_080E61A4:
	mov r2, r8
	ldr r6, [r2]
	ldr r0, [r6, 0x8]
	ldrb r1, [r0, 0x11]
	ldr r4, [r6, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r5, r0, r4
	ldrh r0, [r5, 0x6]
	ldr r3, =gContestMoves
	lsls r0, 3
	adds r7, r0, r3
	ldrb r2, [r7, 0x1]
	lsls r2, 29
	mov r0, r12
	asrs r1, r0, 24
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x6]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	cmp r2, r0
	bne _080E61F8
	ldr r1, =gContestEffects
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	ldrh r1, [r5, 0x2]
	adds r0, r1
	strh r0, [r5, 0x2]
	ldr r0, [r6, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1F
	bl sub_80DD3D4
_080E61F8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E611C

	thumb_func_start ContestEffectFunc_080E620C
ContestEffectFunc_080E620C: @ 80E620C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gContestResources
	ldr r3, [r0]
	ldr r1, [r3, 0x8]
	ldrb r2, [r1, 0x11]
	adds r1, r2
	ldrb r1, [r1]
	mov r9, r0
	cmp r1, 0
	beq _080E62AC
	ldr r1, [r3, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	mov r8, r0
	movs r6, 0
	ldr r0, =gContestMoves
	mov r12, r0
	movs r7, 0
_080E623C:
	mov r1, r9
	ldr r4, [r1]
	ldr r0, [r4, 0x8]
	ldrb r2, [r0, 0x11]
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r1, 0x1
	adds r0, r6
	ldrb r0, [r0]
	cmp r1, r0
	bne _080E62A4
	mov r1, r8
	lsls r0, r1, 3
	mov r1, r12
	adds r5, r0, r1
	ldrb r1, [r5, 0x1]
	lsls r1, 29
	ldr r3, [r4, 0x4]
	adds r0, r7, r3
	ldrh r0, [r0, 0x6]
	lsls r0, 3
	add r0, r12
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	cmp r1, r0
	beq _080E62A4
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r3
	ldr r2, =gContestEffects
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	ldrh r2, [r1, 0x2]
	adds r0, r2
	strh r0, [r1, 0x2]
	ldr r0, [r4, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x20
	bl sub_80DD3D4
	b _080E62AC
	.pool
_080E62A4:
	adds r7, 0x1C
	adds r6, 0x1
	cmp r6, 0x3
	ble _080E623C
_080E62AC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E620C

	thumb_func_start ContestEffectFunc_080E62B8
ContestEffectFunc_080E62B8: @ 80E62B8
	push {r4-r7,lr}
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x11]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E632E
	movs r5, 0
	movs r6, 0
_080E62CE:
	ldr r0, =gContestResources
	ldr r4, [r0]
	ldr r1, [r4, 0x8]
	ldrb r2, [r1, 0x11]
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, 0x1
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	bne _080E6326
	ldr r1, [r4, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r3, r0, r1
	adds r1, r6, r1
	movs r0, 0x2
	ldrsh r2, [r3, r0]
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r2, r0
	ble _080E6314
	adds r0, r2, 0
	lsls r0, 1
	strh r0, [r3, 0x2]
	ldr r0, [r4, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x21
	bl sub_80DD3D4
	b _080E6326
	.pool
_080E6314:
	cmp r2, r0
	bge _080E6326
	movs r0, 0
	strh r0, [r3, 0x2]
	ldr r0, [r4, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x22
	bl sub_80DD3D4
_080E6326:
	adds r6, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080E62CE
_080E632E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E62B8

	thumb_func_start ContestEffectFunc_080E6334
ContestEffectFunc_080E6334: @ 80E6334
	push {r4,lr}
	ldr r4, =gContestResources
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r1, r0, r1
	ldrb r3, [r1, 0xD]
	movs r0, 0xD
	ldrsb r0, [r1, r0]
	cmp r0, 0x1D
	bgt _080E6388
	adds r0, r3, 0
	adds r0, 0xA
	strb r0, [r1, 0xD]
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x10]
	movs r1, 0x31
	negs r1, r1
	ands r1, r2
	movs r2, 0x10
	orrs r1, r2
	strb r1, [r0, 0x10]
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x23
	bl sub_80DD3D4
	b _080E6390
	.pool
_080E6388:
	adds r0, r2, 0
	movs r1, 0x3A
	bl sub_80DD3D4
_080E6390:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E6334

	thumb_func_start ContestEffectFunc_080E6398
ContestEffectFunc_080E6398: @ 80E6398
	push {lr}
	ldr r3, =gContestResources
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x11]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x11]
	ldr r1, [r3]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0xD]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _080E63DC
	adds r0, r2, 0
	movs r1, 0x24
	bl sub_80DD3D4
	b _080E63E4
	.pool
_080E63DC:
	adds r0, r2, 0
	movs r1, 0x3B
	bl sub_80DD3D4
_080E63E4:
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E6398

	thumb_func_start ContestEffectFunc_080E63E8
ContestEffectFunc_080E63E8: @ 80E63E8
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gContestResources
	ldr r2, [r0]
	ldr r1, [r2]
	ldrb r1, [r1, 0x1]
	mov r12, r0
	cmp r1, 0x4
	bne _080E63FC
	b _080E6518
_080E63FC:
	movs r6, 0
	adds r4, r2, 0
_080E6400:
	lsls r1, r6, 24
	asrs r1, 24
	mov r0, sp
	adds r3, r0, r1
	ldr r2, [r4, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x19]
	strb r0, [r3]
	adds r1, 0x1
	lsls r1, 24
	lsrs r6, r1, 24
	asrs r1, 24
	cmp r1, 0x3
	ble _080E6400
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0xFF
	strb r0, [r1]
	movs r6, 0
	mov r3, r12
	ldr r7, [r3]
_080E6438:
	movs r5, 0
_080E643A:
	lsls r0, r5, 24
	asrs r2, r0, 24
	ldr r0, [r7, 0x8]
	ldrb r0, [r0, 0x11]
	cmp r2, r0
	beq _080E6474
	lsls r0, r6, 24
	asrs r3, r0, 24
	mov r0, sp
	adds r4, r0, r2
	ldrb r1, [r4]
	cmp r3, r1
	bne _080E6474
	ldr r0, [r7, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	lsls r0, r3, 24
	lsrs r0, 24
	ldrb r1, [r1, 0x19]
	cmp r0, r1
	bne _080E6474
	adds r0, r3, 0x1
	strb r0, [r4]
	b _080E6484
	.pool
_080E6474:
	lsls r0, r5, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r5, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _080E643A
_080E6484:
	cmp r5, 0x4
	beq _080E6498
	lsls r0, r6, 24
	movs r3, 0x80
	lsls r3, 17
	adds r0, r3
	lsrs r6, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _080E6438
_080E6498:
	mov r4, r12
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	mov r3, sp
	adds r2, r3, r0
	movs r0, 0
	strb r0, [r2]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x10]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0, 0x10]
	movs r6, 0
	mov r3, r12
_080E64C6:
	ldr r0, [r3]
	lsls r1, r6, 24
	asrs r1, 24
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	mov r4, sp
	adds r2, r4, r1
	ldrb r2, [r2]
	strb r2, [r0, 0x19]
	adds r1, 0x1
	lsls r1, 24
	lsrs r6, r1, 24
	asrs r1, 24
	cmp r1, 0x3
	ble _080E64C6
	mov r0, r12
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x11]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x11]
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x25
	bl sub_80DD3D4
_080E6518:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E63E8

	thumb_func_start ContestEffectFunc_080E6520
ContestEffectFunc_080E6520: @ 80E6520
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r0, =gContestResources
	ldr r2, [r0]
	ldr r1, [r2]
	ldrb r1, [r1, 0x1]
	mov r12, r0
	cmp r1, 0x4
	bne _080E6538
	b _080E6658
_080E6538:
	movs r6, 0
	adds r4, r2, 0
_080E653C:
	lsls r1, r6, 24
	asrs r1, 24
	mov r0, sp
	adds r3, r0, r1
	ldr r2, [r4, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x19]
	strb r0, [r3]
	adds r1, 0x1
	lsls r1, 24
	lsrs r6, r1, 24
	asrs r1, 24
	cmp r1, 0x3
	ble _080E653C
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0xFF
	strb r0, [r1]
	movs r6, 0x3
	mov r3, r12
	ldr r7, [r3]
	movs r4, 0x1
	negs r4, r4
	mov r8, r4
_080E657A:
	movs r5, 0
_080E657C:
	lsls r0, r5, 24
	asrs r2, r0, 24
	ldr r0, [r7, 0x8]
	ldrb r0, [r0, 0x11]
	cmp r2, r0
	beq _080E65B4
	lsls r0, r6, 24
	asrs r3, r0, 24
	mov r0, sp
	adds r4, r0, r2
	ldrb r1, [r4]
	cmp r3, r1
	bne _080E65B4
	ldr r0, [r7, 0x4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	lsls r0, r3, 24
	lsrs r0, 24
	ldrb r1, [r1, 0x19]
	cmp r0, r1
	bne _080E65B4
	subs r0, r3, 0x1
	strb r0, [r4]
	b _080E65C4
	.pool
_080E65B4:
	lsls r0, r5, 24
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r5, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _080E657C
_080E65C4:
	cmp r5, 0x4
	beq _080E65D8
	lsls r0, r6, 24
	movs r3, 0xFF
	lsls r3, 24
	adds r0, r3
	lsrs r6, r0, 24
	asrs r0, 24
	cmp r0, r8
	bgt _080E657A
_080E65D8:
	mov r4, r12
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	mov r3, sp
	adds r2, r3, r0
	movs r0, 0x3
	strb r0, [r2]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x10]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0, 0x10]
	movs r6, 0
	mov r3, r12
_080E6606:
	ldr r0, [r3]
	lsls r1, r6, 24
	asrs r1, 24
	ldr r2, [r0, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	mov r4, sp
	adds r2, r4, r1
	ldrb r2, [r2]
	strb r2, [r0, 0x19]
	adds r1, 0x1
	lsls r1, 24
	lsrs r6, r1, 24
	asrs r1, 24
	cmp r1, 0x3
	ble _080E6606
	mov r0, r12
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x11]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0, 0x11]
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x26
	bl sub_80DD3D4
_080E6658:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ContestEffectFunc_080E6520

	thumb_func_start ContestEffectFunc_080E6664
ContestEffectFunc_080E6664: @ 80E6664
	bx lr
	thumb_func_end ContestEffectFunc_080E6664

	thumb_func_start ContestEffectFunc_080E6668
ContestEffectFunc_080E6668: @ 80E6668
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r0, =gContestResources
	ldr r1, [r0]
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	beq _080E676C
	movs r6, 0
	add r5, sp, 0x4
	adds r4, r1, 0
	adds r7, r5, 0
_080E6680:
	lsls r1, r6, 24
	asrs r1, 24
	mov r0, sp
	adds r3, r0, r1
	ldr r2, [r4, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x19]
	strb r0, [r3]
	adds r0, r7, r1
	strb r6, [r0]
	adds r1, 0x1
	lsls r1, 24
	lsrs r6, r1, 24
	asrs r1, 24
	cmp r1, 0x3
	ble _080E6680
	movs r6, 0
	adds r7, r5, 0
_080E66AA:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r6, 24
	asrs r2, 24
	movs r1, 0x4
	subs r1, r2
	bl __modsi3
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0
_080E66C4:
	lsls r0, r1, 24
	asrs r2, r0, 24
	adds r3, r7, r2
	ldrb r1, [r3]
	adds r5, r0, 0
	cmp r1, 0xFF
	beq _080E66EE
	cmp r4, 0
	bne _080E66E8
	mov r1, sp
	adds r0, r1, r2
	strb r6, [r0]
	movs r0, 0xFF
	strb r0, [r3]
	b _080E66FC
	.pool
_080E66E8:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080E66EE:
	movs r1, 0x80
	lsls r1, 17
	adds r0, r5, r1
	lsrs r1, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _080E66C4
_080E66FC:
	lsls r0, r6, 24
	movs r6, 0x80
	lsls r6, 17
	adds r0, r6
	lsrs r6, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _080E66AA
	movs r6, 0
	ldr r5, =gContestResources
	adds r4, r5, 0
_080E6712:
	ldr r0, [r4]
	lsls r3, r6, 24
	asrs r3, 24
	ldr r1, [r0, 0x4]
	lsls r2, r3, 3
	subs r2, r3
	lsls r2, 2
	adds r1, r2, r1
	mov r6, sp
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r1, 0x19]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r2, r0
	ldrb r1, [r2, 0x10]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x10]
	adds r3, 0x1
	lsls r3, 24
	lsrs r6, r3, 24
	asrs r3, 24
	cmp r3, 0x3
	ble _080E6712
	ldr r1, [r5]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x11]
	movs r2, 0x3
	orrs r1, r2
	strb r1, [r0, 0x11]
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x27
	bl sub_80DD3D4
_080E676C:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E6668

	thumb_func_start ContestEffectFunc_080E6778
ContestEffectFunc_080E6778: @ 80E6778
	push {lr}
	ldr r3, =gContestMoves
	ldr r0, =gContestResources
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r2, r0, r1
	ldrh r0, [r2, 0x6]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	ldr r1, =gSpecialVar_ContestCategory
	lsrs r0, 29
	ldrh r1, [r1]
	cmp r0, r1
	beq _080E67AA
	ldrb r0, [r2, 0x11]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x11]
_080E67AA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E6778

	thumb_func_start ContestEffectFunc_080E67BC
ContestEffectFunc_080E67BC: @ 80E67BC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	movs r4, 0
	ldr r5, =gContestResources
	movs r6, 0
_080E67CC:
	ldr r3, [r5]
	ldr r2, [r3, 0x8]
	ldrb r0, [r2, 0x11]
	adds r0, r2, r0
	adds r1, r2, r4
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080E682E
	ldr r0, [r3, 0x4]
	adds r1, r6, r0
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, 0
	ble _080E6808
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r2, 0x4]
	ldr r0, [r3, 0x8]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl sub_80E6BB4
	ldr r1, [r5]
	ldr r1, [r1, 0x8]
	strh r0, [r1, 0x4]
	b _080E680C
	.pool
_080E6808:
	movs r0, 0xA
	strh r0, [r2, 0x4]
_080E680C:
	ldr r0, [r5]
	ldr r0, [r0, 0x8]
	strb r4, [r0, 0x8]
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	bl sub_80E6A2C
	lsls r0, 24
	cmp r0, 0
	beq _080E682E
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_080E682E:
	adds r6, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080E67CC
	mov r7, r8
	cmp r7, 0
	bne _080E684A
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E684A:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x30
	bl sub_80DD3D4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E67BC

	thumb_func_start ContestEffectFunc_080E6868
ContestEffectFunc_080E6868: @ 80E6868
	push {r4,lr}
	ldr r0, =gContestResources
	ldr r1, [r0]
	ldr r0, [r1]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bne _080E688C
	movs r4, 0xA
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1A
	bl sub_80DD3D4
	b _080E68CE
	.pool
_080E688C:
	cmp r0, 0x1
	bne _080E689E
	movs r4, 0x14
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1B
	bl sub_80DD3D4
	b _080E68CE
_080E689E:
	cmp r0, 0x2
	bne _080E68B0
	movs r4, 0x1E
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1C
	bl sub_80DD3D4
	b _080E68CE
_080E68B0:
	cmp r0, 0x3
	bne _080E68C2
	movs r4, 0x32
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1D
	bl sub_80DD3D4
	b _080E68CE
_080E68C2:
	movs r4, 0x3C
	ldr r0, [r1, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x1E
	bl sub_80DD3D4
_080E68CE:
	ldr r0, =gContestResources
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	strh r4, [r0, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E6868

	thumb_func_start ContestEffectFunc_080E68EC
ContestEffectFunc_080E68EC: @ 80E68EC
	push {r4,lr}
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080E692A
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r0, [r4]
	ldr r3, [r0, 0x10]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x7
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r3, 0x1]
	movs r0, 0xF
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x3D
	bl sub_80DD3D4
_080E692A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContestEffectFunc_080E68EC

	thumb_func_start sub_80E6934
sub_80E6934: @ 80E6934
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	movs r4, 0
	ldr r6, =gContestResources
	ldr r0, =gContestMoves
	mov r9, r0
	movs r5, 0
_080E694E:
	ldr r3, [r6]
	ldr r2, [r3, 0x8]
	ldrb r0, [r2, 0x11]
	adds r0, r2, r0
	adds r1, r2, r4
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080E699E
	ldr r0, [r3, 0x4]
	adds r0, r5, r0
	ldrh r0, [r0, 0x6]
	lsls r0, 3
	add r0, r9
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 29
	cmp r8, r0
	bne _080E6980
	movs r0, 0x28
	b _080E6982
	.pool
_080E6980:
	movs r0, 0xA
_080E6982:
	strh r0, [r2, 0x4]
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	strb r4, [r0, 0x8]
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	movs r0, 0xFF
	strb r0, [r1, 0x9]
	bl sub_80E6A2C
	lsls r0, 24
	cmp r0, 0
	beq _080E699E
	adds r7, 0x1
_080E699E:
	adds r5, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080E694E
	cmp r7, 0
	bne _080E69B8
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x11]
	movs r1, 0x36
	bl sub_80DD3F0
_080E69B8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E6934

	thumb_func_start sub_80E69C8
sub_80E69C8: @ 80E69C8
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	adds r0, 0xD
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x10]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080E69FC
	adds r0, r3, 0
	movs r1, 0x2D
	b _080E6A22
	.pool
_080E69FC:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	bne _080E6A1A
	ldrb r1, [r2, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E6A26
	ldrb r1, [r2, 0xC]
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	bne _080E6A26
	movs r0, 0x1
	b _080E6A28
_080E6A1A:
	subs r0, 0x1
	strb r0, [r2, 0x12]
	adds r0, r3, 0
	movs r1, 0x2C
_080E6A22:
	bl sub_80DD3D4
_080E6A26:
	movs r0, 0
_080E6A28:
	pop {r1}
	bx r1
	thumb_func_end sub_80E69C8

	thumb_func_start sub_80E6A2C
sub_80E6A2C: @ 80E6A2C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r0, sp
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r7, 0
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrb r0, [r0, 0x8]
	cmp r0, 0xFF
	beq _080E6B10
	mov r8, r4
_080E6A4E:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	adds r0, r7
	ldrb r5, [r0]
	adds r6, r5, 0
	adds r0, r5, 0
	bl sub_80E69C8
	lsls r0, 24
	cmp r0, 0
	beq _080E6AFE
	ldr r2, [r4]
	ldr r1, [r2, 0x8]
	ldrh r0, [r1, 0x4]
	strh r0, [r1, 0x6]
	ldr r1, [r2, 0x4]
	lsls r0, r5, 3
	subs r0, r5
	lsls r4, r0, 2
	adds r1, r4, r1
	ldrb r1, [r1, 0x10]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080E6A8E
	ldr r1, [r2, 0x8]
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	lsls r0, 1
	strh r0, [r1, 0x6]
_080E6A8E:
	mov r0, r8
	ldr r3, [r0]
	ldr r0, [r3, 0x4]
	adds r1, r4, r0
	ldrb r0, [r1, 0x10]
	movs r4, 0x1
	ands r4, r0
	cmp r4, 0
	beq _080E6AB4
	ldr r1, [r3, 0x8]
	movs r0, 0xA
	strh r0, [r1, 0x6]
	adds r0, r5, 0
	movs r1, 0x2F
	bl sub_80DD3D4
	b _080E6AFE
	.pool
_080E6AB4:
	ldr r2, [r3, 0x8]
	ldrb r1, [r1, 0xF]
	ldrh r0, [r2, 0x6]
	subs r0, r1
	strh r0, [r2, 0x6]
	ldr r2, [r3, 0x8]
	ldrh r1, [r2, 0x6]
	movs r3, 0x6
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bgt _080E6AD6
	strh r4, [r2, 0x6]
	adds r0, r5, 0
	movs r1, 0x2E
	bl sub_80DD3D4
	b _080E6AFE
_080E6AD6:
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_80E6B3C
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	ldrb r1, [r0, 0x6]
	adds r0, r6, 0
	bl sub_80DD40C
	lsls r0, r6, 1
	mov r2, sp
	adds r1, r2, r0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	ldrh r0, [r0, 0x6]
	strh r0, [r1]
_080E6AFE:
	adds r7, 0x1
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	adds r0, 0x8
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080E6A4E
_080E6B10:
	movs r7, 0
	mov r1, sp
_080E6B14:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080E6B24
	movs r0, 0x1
	b _080E6B2E
	.pool
_080E6B24:
	adds r1, 0x2
	adds r7, 0x1
	cmp r7, 0x3
	ble _080E6B14
	movs r0, 0
_080E6B2E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80E6A2C

	thumb_func_start sub_80E6B3C
sub_80E6B3C: @ 80E6B3C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gContestResources
	ldr r4, [r2]
	ldr r3, [r4, 0x4]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r3, r2, r3
	ldrh r0, [r3, 0x2]
	subs r0, r1
	strh r0, [r3, 0x2]
	ldr r0, [r4, 0x4]
	adds r2, r0
	ldrb r0, [r2, 0xE]
	adds r1, r0
	strb r1, [r2, 0xE]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E6B3C

	thumb_func_start sub_80E6B70
sub_80E6B70: @ 80E6B70
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	cmp r4, 0
	bge _080E6B80
	negs r0, r4
_080E6B80:
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r4, 0
	bge _080E6B9E
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	beq _080E6BA8
	adds r0, r4, 0
	subs r0, 0xA
	adds r0, r1, r0
	b _080E6BA4
_080E6B9E:
	lsls r0, 16
	asrs r0, 16
	subs r0, r4, r0
_080E6BA4:
	lsls r0, 16
	lsrs r5, r0, 16
_080E6BA8:
	lsls r0, r5, 16
	asrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E6B70

	thumb_func_start sub_80E6BB4
sub_80E6BB4: @ 80E6BB4
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	cmp r4, 0
	bge _080E6BC4
	negs r0, r4
_080E6BC4:
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	beq _080E6BDC
	adds r0, r4, 0
	adds r0, 0xA
	subs r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
_080E6BDC:
	lsls r0, r5, 16
	asrs r0, 16
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80E6BB4

	.align 2, 0 @ Don't pad with nop.
