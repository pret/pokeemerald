	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_817F21C
sub_817F21C: @ 817F21C
	push {r4-r7,lr}
	adds r6, r1, 0
	mov r12, r2
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gBattleMoves
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _0817F286
	movs r4, 0
	ldr r5, =gUnknown_0860A4AC
	ldr r7, =0x0000ffff
	adds r3, r5, 0
	adds r1, r5, 0
_0817F240:
	ldrh r0, [r1]
	cmp r2, r0
	beq _0817F252
	adds r3, 0x2
	adds r1, 0x2
	adds r4, 0x1
	ldrh r0, [r3]
	cmp r0, r7
	bne _0817F240
_0817F252:
	lsls r0, r4, 1
	adds r0, r5
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _0817F270
	movs r0, 0
	str r0, [r6]
	b _0817F2A0
	.pool
_0817F270:
	cmp r2, 0x95
	bne _0817F294
	ldr r2, =gBattleMons
	ldr r0, =gBattlerAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2A
	ldrb r0, [r0]
	asrs r0, 1
_0817F286:
	str r0, [r6]
	movs r0, 0
	b _0817F2A0
	.pool
_0817F294:
	cmp r2, 0xDE
	bne _0817F29E
	movs r0, 0xA
	mov r1, r12
	strh r0, [r1]
_0817F29E:
	movs r0, 0x1
_0817F2A0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_817F21C

	thumb_func_start sub_817F2A8
sub_817F2A8: @ 817F2A8
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0817F324
	ldr r0, =gBattleStruct
	ldr r3, [r0]
	ldr r0, =0x0000025b
	adds r4, r3, r0
	ldrb r2, [r4]
	subs r1, 0x21
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4]
	ldr r0, =0x00000267
	adds r2, r3, r0
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	ldrb r5, [r4]
	movs r1, 0x1F
	adds r0, r1, 0
	ands r0, r5
	strb r0, [r4]
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	movs r0, 0x97
	lsls r0, 2
	adds r4, r3, r0
	ldrb r2, [r4]
	movs r1, 0x39
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4]
	movs r0, 0x9A
	lsls r0, 2
	adds r3, r0
	ldrb r0, [r3]
	ands r1, r0
	strb r1, [r3]
	ldrb r2, [r4]
	movs r1, 0x7
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4]
	ldrb r0, [r3]
	ands r1, r0
	strb r1, [r3]
	ldrb r2, [r4]
	movs r1, 0x2
	negs r1, r1
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r4]
	ldrb r0, [r3]
	ands r1, r0
	strb r1, [r3]
_0817F324:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817F2A8

	thumb_func_start GetBattlerMoveSlotId
GetBattlerMoveSlotId: @ 817F33C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r5, 0
	bl GetBattlerSide
	lsls r0, 24
	ldr r6, =gEnemyParty
	cmp r0, 0
	bne _0817F356
	ldr r6, =gPlayerParty
_0817F356:
	movs r4, 0
	ldr r1, =gBattlerPartyIndexes
	lsls r0, r5, 1
	adds r5, r0, r1
	b _0817F36E
	.pool
_0817F36C:
	adds r4, 0x1
_0817F36E:
	cmp r4, 0x3
	bgt _0817F388
	ldrh r1, [r5]
	movs r0, 0x64
	muls r0, r1
	adds r0, r6, r0
	adds r1, r4, 0
	adds r1, 0xD
	movs r2, 0
	bl GetMonData
	cmp r0, r7
	bne _0817F36C
_0817F388:
	lsls r0, r4, 24
	lsrs r0, 24
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetBattlerMoveSlotId

	thumb_func_start sub_817F394
sub_817F394: @ 817F394
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	adds r4, r3, 0
	lsls r1, 16
	lsrs r1, 16
	adds r6, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r5, r2, 0
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	beq _0817F3B4
	movs r0, 0x3
	b _0817F3CA
_0817F3B4:
	movs r0, 0x60
	ands r0, r3
	cmp r0, 0
	beq _0817F3C0
	movs r0, 0x4
	b _0817F3CA
_0817F3C0:
	movs r0, 0x18
	ands r0, r3
	cmp r0, 0
	beq _0817F3D2
	movs r0, 0x5
_0817F3CA:
	movs r3, 0
	bl sub_817E684
	b _0817F3E6
_0817F3D2:
	movs r0, 0x80
	ands r4, r0
	cmp r4, 0
	beq _0817F3E6
	movs r0, 0x6
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_817E684
_0817F3E6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_817F394

	.align 2, 0 @ Don't pad with nop.
