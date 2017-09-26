	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start IsTwoTurnsMove
IsTwoTurnsMove: @ 8052F48
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1]
	cmp r0, 0x91
	beq _08052F72
	cmp r0, 0x27
	beq _08052F72
	cmp r0, 0x4B
	beq _08052F72
	cmp r0, 0x97
	beq _08052F72
	cmp r0, 0x9B
	beq _08052F72
	cmp r0, 0x1A
	bne _08052F7C
_08052F72:
	movs r0, 0x1
	b _08052F7E
	.pool
_08052F7C:
	movs r0, 0
_08052F7E:
	pop {r1}
	bx r1
	thumb_func_end IsTwoTurnsMove

	thumb_func_start sub_8052F84
sub_8052F84: @ 8052F84
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _08052FA2
	cmp r1, 0xD6
	beq _08052FA2
	movs r0, 0x89
	lsls r0, 1
	cmp r1, r0
	beq _08052FA2
	cmp r1, 0x77
	beq _08052FA2
	cmp r1, 0x76
	bne _08052FA6
_08052FA2:
	movs r0, 0x1
	b _08052FA8
_08052FA6:
	movs r0, 0
_08052FA8:
	pop {r1}
	bx r1
	thumb_func_end sub_8052F84

	thumb_func_start AttacksThisTurn
AttacksThisTurn: @ 8052FAC
	push {lr}
	lsls r1, 16
	lsrs r2, r1, 16
	ldr r1, =gBattleMoves
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x97
	bne _08052FD0
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	bne _08053010
_08052FD0:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x91
	beq _08052FF2
	cmp r0, 0x27
	beq _08052FF2
	cmp r0, 0x4B
	beq _08052FF2
	cmp r0, 0x97
	beq _08052FF2
	cmp r0, 0x9B
	beq _08052FF2
	cmp r0, 0x1A
	bne _08053010
_08052FF2:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 20
	ands r0, r1
	cmp r0, 0
	beq _08053010
	movs r0, 0x1
	b _08053012
	.pool
_08053010:
	movs r0, 0x2
_08053012:
	pop {r1}
	bx r1
	thumb_func_end AttacksThisTurn

	thumb_func_start atkA9_sleeptalk_choose_move
atkA9_sleeptalk_choose_move: @ 8053018
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r6, 0
	movs r5, 0
	ldr r0, =gBankAttacker
	mov r9, r0
	movs r1, 0x58
	mov r8, r1
	ldr r7, =gBattleMons + 0xC
	movs r0, 0x84
	lsls r0, 1
	mov r10, r0
_08053036:
	lsls r4, r5, 1
	mov r1, r9
	ldrb r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r4, r0
	adds r0, r7
	ldrh r0, [r0]
	bl sub_8052F84
	lsls r0, 24
	cmp r0, 0
	bne _08053076
	mov r1, r9
	ldrb r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r4, r0
	adds r0, r7
	ldrh r1, [r0]
	cmp r1, r10
	beq _08053076
	cmp r1, 0xFD
	beq _08053076
	adds r0, r1, 0
	bl IsTwoTurnsMove
	lsls r0, 24
	cmp r0, 0
	beq _08053084
_08053076:
	ldr r1, =gBitTable
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r6, r0
	lsls r0, r6, 24
	lsrs r6, r0, 24
_08053084:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08053036
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	adds r1, r6, 0
	movs r2, 0xFD
	bl CheckMoveLimitations
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0xF
	bne _080530B8
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _0805311C
	.pool
_080530B8:
	movs r7, 0x3
	ldr r4, =gBitTable
_080530BC:
	bl Random
	adds r5, r7, 0
	ands r5, r0
	lsls r0, r5, 2
	adds r0, r4
	ldr r0, [r0]
	ands r0, r6
	cmp r0, 0
	bne _080530BC
	ldr r4, =gRandomMove
	ldr r2, =gBattleMons
	lsls r1, r5, 1
	ldr r0, =gBankAttacker
	ldrb r3, [r0]
	movs r0, 0x58
	muls r0, r3
	adds r1, r0
	adds r2, 0xC
	adds r1, r2
	ldrh r0, [r1]
	strh r0, [r4]
	ldr r0, =gCurrMovePos
	strb r5, [r0]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	ldrh r0, [r4]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r3, =gBattlescriptCurrInstr
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
_0805311C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA9_sleeptalk_choose_move

	thumb_func_start atkAA_set_destinybond
atkAA_set_destinybond: @ 8053150
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 18
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atkAA_set_destinybond

	thumb_func_start DestinyBondFlagUpdate
DestinyBondFlagUpdate: @ 8053180
	push {r4,r5,lr}
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _080531CA
	cmp r5, r3
	beq _080531CA
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 17
	ands r0, r1
	cmp r0, 0
	bne _080531CA
	movs r0, 0x40
	orrs r1, r0
	str r1, [r2]
_080531CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DestinyBondFlagUpdate

	thumb_func_start atkAB_DestinyBondFlagUpdate
atkAB_DestinyBondFlagUpdate: @ 80531E0
	push {lr}
	bl DestinyBondFlagUpdate
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkAB_DestinyBondFlagUpdate

	thumb_func_start atkAC_remaininghptopower
atkAC_remaininghptopower: @ 80531F8
	push {lr}
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	movs r2, 0x2C
	ldrsh r1, [r1, r2]
	movs r2, 0x30
	bl sub_8075034
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0
	ldr r0, =gUnknown_0831C408
	ldrb r2, [r0]
	cmp r1, r2
	ble _08053232
	adds r2, r0, 0
_08053224:
	adds r3, 0x2
	cmp r3, 0xB
	bgt _08053232
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r1, r0
	bgt _08053224
_08053232:
	ldr r2, =gDynamicBasePower
	ldr r1, =gUnknown_0831C408
	adds r0, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkAC_remaininghptopower

	thumb_func_start atkAD_spite_ppreduce
atkAD_spite_ppreduce: @ 8053260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, =gLastUsedMovesByBanks
	ldr r1, =gBankTarget
	ldrb r3, [r1]
	lsls r0, r3, 1
	adds r0, r4
	ldrh r2, [r0]
	mov r8, r1
	cmp r2, 0
	bne _08053280
	b _08053408
_08053280:
	ldr r0, =0x0000ffff
	cmp r2, r0
	bne _08053288
	b _08053408
_08053288:
	movs r7, 0
	ldr r0, =gBattleMons
	movs r1, 0x58
	muls r1, r3
	adds r3, r0, 0
	adds r3, 0xC
	adds r1, r3
	ldrh r1, [r1]
	cmp r2, r1
	beq _080532C0
	adds r6, r4, 0
	mov r5, r8
	adds r4, r3, 0
	movs r3, 0x58
_080532A4:
	adds r7, 0x1
	cmp r7, 0x3
	bgt _080532C0
	ldrb r0, [r5]
	lsls r2, r0, 1
	adds r2, r6
	lsls r1, r7, 1
	muls r0, r3
	adds r1, r0
	adds r1, r4
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080532A4
_080532C0:
	cmp r7, 0x4
	bne _080532C6
	b _08053408
_080532C6:
	mov r4, r8
	ldrb r0, [r4]
	movs r1, 0x58
	mov r9, r1
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	adds r0, r7, r0
	ldr r1, =gBattleMons
	adds r1, 0x24
	mov r10, r1
	add r0, r10
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _080532E6
	b _08053408
_080532E6:
	bl Random
	movs r1, 0x3
	ands r1, r0
	adds r6, r1, 0x2
	ldrb r0, [r4]
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	adds r0, r7, r0
	add r0, r10
	ldrb r0, [r0]
	cmp r0, r6
	bge _08053304
	adds r6, r0, 0
_08053304:
	ldr r1, =gBattleTextBuff1
	movs r5, 0xFD
	strb r5, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	ldr r2, =gLastUsedMovesByBanks
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x2]
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r4, =gBattleTextBuff2
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	strb r5, [r4]
	movs r0, 0x1
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	strb r6, [r4, 0x4]
	subs r0, 0x2
	strb r0, [r4, 0x5]
	mov r1, r8
	ldrb r0, [r1]
	mov r1, r9
	muls r1, r0
	adds r1, r7, r1
	add r1, r10
	ldrb r0, [r1]
	subs r0, r6
	strb r0, [r1]
	ldr r4, =gActiveBank
	mov r3, r8
	ldrb r0, [r3]
	strb r0, [r4]
	ldr r1, =gDisableStructs
	ldrb r3, [r4]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r7, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _080533B8
	mov r2, r9
	muls r2, r3
	ldr r0, =gBattleMons
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _080533B8
	adds r1, r7, 0
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	mov r3, r10
	adds r0, r2, r3
	adds r0, r7
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_080533B8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	ldr r1, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r7, r0
	adds r1, 0x24
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08053422
	adds r0, r2, 0
	bl CancelMultiTurnMoves
	b _08053422
	.pool
_08053408:
	ldr r3, =gBattlescriptCurrInstr
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
_08053422:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkAD_spite_ppreduce

	thumb_func_start atkAE_heal_party_status
atkAE_heal_party_status: @ 8053438
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r4, 0
	str r4, [sp, 0x4]
	mov r8, r4
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xD7
	beq _08053454
	b _0805363E
_08053454:
	ldr r6, =gBattleCommunication
	mov r0, r8
	strb r0, [r6, 0x5]
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r10, r1
	cmp r0, 0
	bne _08053470
	ldr r2, =gPlayerParty
	mov r10, r2
_08053470:
	ldr r4, =gBattleMons
	ldrb r3, [r5]
	movs r7, 0x58
	adds r2, r3, 0
	muls r2, r7
	adds r0, r2, r4
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0x2B
	beq _080534C4
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r2, r0
	mov r1, r8
	str r1, [r0]
	ldrb r0, [r5]
	adds r2, r0, 0
	muls r2, r7
	adds r0, r4, 0
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	b _080534D4
	.pool
_080534C4:
	ldrb r1, [r1]
	adds r0, r3, 0
	bl RecordAbilityBattle
	ldrb r0, [r6, 0x5]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r6, 0x5]
_080534D4:
	ldr r7, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r2, 0x2
	mov r9, r2
	mov r1, r9
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
	ldr r1, =gBattleScripting
	strb r0, [r1, 0x17]
	strb r0, [r7]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805357A
	ldr r0, =gAbsentBankFlags
	ldrb r2, [r0]
	ldr r1, =gBitTable
	ldrb r3, [r7]
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	bne _0805357A
	ldr r5, =gBattleMons
	movs r6, 0x58
	adds r4, r3, 0
	muls r4, r6
	adds r0, r4, r5
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0x2B
	beq _08053568
	adds r0, r5, 0
	adds r0, 0x4C
	adds r0, r4, r0
	str r2, [r0]
	ldrb r0, [r7]
	adds r2, r0, 0
	muls r2, r6
	adds r0, r5, 0
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	b _0805357A
	.pool
_08053568:
	ldrb r1, [r1]
	adds r0, r3, 0
	bl RecordAbilityBattle
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x5]
	mov r2, r9
	orrs r0, r2
	strb r0, [r1, 0x5]
_0805357A:
	movs r6, 0
	ldr r7, =gBattleMons
_0805357E:
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	add r4, r10
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r5, 0
	beq _08053636
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	beq _08053636
	ldr r2, =gBattlePartyID
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _080535D0
	movs r0, 0x58
	muls r0, r1
	b _08053600
	.pool
_080535D0:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08053618
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _08053618
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08053618
	movs r0, 0x58
	muls r0, r3
_08053600:
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	b _08053624
	.pool
_08053618:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetAbilityBySpecies
	lsls r0, 24
	lsrs r0, 24
_08053624:
	cmp r0, 0x2B
	beq _08053636
	movs r0, 0x1
	lsls r0, r6
	mov r1, r8
	orrs r1, r0
	lsls r0, r1, 24
	lsrs r0, 24
	mov r8, r0
_08053636:
	adds r6, 0x1
	cmp r6, 0x5
	ble _0805357E
	b _080536BC
_0805363E:
	ldr r1, =gBattleCommunication
	movs r0, 0x4
	strb r0, [r1, 0x5]
	movs r2, 0x3F
	mov r8, r2
	ldr r3, =gBattleMons
	ldr r2, =gBankAttacker
	ldrb r0, [r2]
	movs r5, 0x58
	muls r0, r5
	movs r1, 0x4C
	adds r1, r3
	mov r9, r1
	add r0, r9
	str r4, [r0]
	ldrb r0, [r2]
	adds r1, r0, 0
	muls r1, r5
	adds r7, r3, 0
	adds r7, 0x50
	adds r1, r7
	ldr r0, [r1]
	ldr r6, =0xf7ffffff
	ands r0, r6
	str r0, [r1]
	ldrb r0, [r2]
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080536BC
	ldr r0, =gAbsentBankFlags
	ldrb r2, [r0]
	ldr r1, =gBitTable
	ldrb r3, [r4]
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	bne _080536BC
	adds r0, r3, 0
	muls r0, r5
	add r0, r9
	str r2, [r0]
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r7
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
_080536BC:
	mov r2, r8
	cmp r2, 0
	beq _080536DE
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r4]
	add r0, sp, 0x4
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r3, 0x4
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_080536DE:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkAE_heal_party_status

	thumb_func_start atkAF_cursetarget
atkAF_cursetarget: @ 805371C
	push {r4,r5,lr}
	ldr r5, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	movs r4, 0x58
	adds r1, r0, 0
	muls r1, r4
	adds r0, r5, 0
	adds r0, 0x50
	adds r1, r0
	ldr r2, [r1]
	movs r3, 0x80
	lsls r3, 21
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _08053768
	ldr r3, =gBattlescriptCurrInstr
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
	b _0805378C
	.pool
_08053768:
	orrs r2, r3
	str r2, [r1]
	ldr r1, =gBattleMoveDamage
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	muls r0, r4
	adds r0, r5
	ldrh r0, [r0, 0x2C]
	lsrs r0, 1
	str r0, [r1]
	cmp r0, 0
	bne _08053784
	movs r0, 0x1
	str r0, [r1]
_08053784:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0805378C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkAF_cursetarget

	thumb_func_start atkB0_set_spikes
atkB0_set_spikes: @ 80537A0
	push {r4,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSideTimers
	lsls r2, r0, 1
	adds r0, r2, r0
	lsls r0, 2
	adds r3, r0, r1
	ldrb r0, [r3, 0xA]
	cmp r0, 0x3
	bne _08053804
	ldr r2, =gSpecialStatuses
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r3, =gBattlescriptCurrInstr
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
	b _0805381E
	.pool
_08053804:
	ldr r1, =gSideAffecting
	adds r1, r2, r1
	ldrh r2, [r1]
	movs r0, 0x10
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3, 0xA]
	adds r0, 0x1
	strb r0, [r3, 0xA]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0805381E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB0_set_spikes

	thumb_func_start atkB1_set_foresight
atkB1_set_foresight: @ 805382C
	ldr r1, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r2, [r0]
	movs r0, 0x58
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 22
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atkB1_set_foresight

	thumb_func_start atkB2_setperishsong
atkB2_setperishsong: @ 805385C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r6, 0
	movs r3, 0
	ldr r0, =gNoOfAllBanks
	adds r7, r0, 0
	ldr r0, =gBankAttacker
	mov r8, r0
	ldrb r1, [r7]
	cmp r6, r1
	bge _080538C8
	movs r5, 0x20
	ldr r0, =gBattleMons
	mov r12, r0
	ldr r0, =gDisableStructs
	adds r4, r0, 0
	adds r4, 0xF
	ldr r2, =gStatuses3
_08053884:
	ldr r1, [r2]
	adds r0, r1, 0
	ands r0, r5
	cmp r0, 0
	bne _0805389C
	movs r0, 0x58
	muls r0, r3
	add r0, r12
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x2B
	bne _080538B4
_0805389C:
	adds r6, 0x1
	b _080538BC
	.pool
_080538B4:
	orrs r1, r5
	str r1, [r2]
	movs r0, 0x33
	strb r0, [r4]
_080538BC:
	adds r4, 0x1C
	adds r2, 0x4
	adds r3, 0x1
	ldrb r0, [r7]
	cmp r3, r0
	blt _08053884
_080538C8:
	mov r1, r8
	ldrb r0, [r1]
	bl sub_803F67C
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	bne _080538FC
	ldr r3, =gBattlescriptCurrInstr
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
	b _08053904
	.pool
_080538FC:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08053904:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB2_setperishsong

	thumb_func_start atkB3_rolloutdamagecalculation
atkB3_rolloutdamagecalculation: @ 8053914
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08053948
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl CancelMultiTurnMoves
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D8A60
	str r0, [r1]
	b _08053A60
	.pool
_08053948:
	ldr r2, =gBattleMons
	ldr r1, =gBankAttacker
	ldrb r3, [r1]
	movs r5, 0x58
	adds r0, r3, 0
	muls r0, r5
	adds r4, r2, 0
	adds r4, 0x50
	adds r0, r4
	ldr r0, [r0]
	movs r7, 0x80
	lsls r7, 5
	ands r0, r7
	adds r6, r1, 0
	mov r9, r2
	ldr r1, =gDisableStructs
	mov r12, r1
	ldr r2, =gCurrentMove
	mov r8, r2
	cmp r0, 0
	bne _080539BA
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	add r0, r12
	ldrb r2, [r0, 0x11]
	movs r1, 0x10
	negs r1, r1
	ands r1, r2
	movs r2, 0x5
	orrs r1, r2
	strb r1, [r0, 0x11]
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r2, [r0, 0x11]
	movs r1, 0xF
	ands r1, r2
	movs r2, 0x50
	orrs r1, r2
	strb r1, [r0, 0x11]
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r4
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r1, =gLockedMoves
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r1
	mov r2, r8
	ldrh r1, [r2]
	strh r1, [r0]
_080539BA:
	ldrb r0, [r6]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	add r2, r12
	ldrb r3, [r2, 0x11]
	lsls r1, r3, 28
	lsrs r1, 28
	subs r1, 0x1
	movs r0, 0xF
	ands r1, r0
	movs r0, 0x10
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x11]
	cmp r1, 0
	bne _080539EE
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r4
	ldr r0, [r1]
	ldr r2, =0xffffefff
	ands r0, r2
	str r0, [r1]
_080539EE:
	ldr r3, =gDynamicBasePower
	ldr r2, =gBattleMoves
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	strh r0, [r3]
	movs r2, 0x1
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r1, r12
	adds r4, r0, r1
	ldrb r0, [r4, 0x11]
	lsls r0, 28
	lsrs r0, 28
	movs r1, 0x5
	subs r1, r0
	ldr r7, =gBattlescriptCurrInstr
	adds r5, r3, 0
	cmp r2, r1
	bge _08053A3C
	adds r1, r5, 0
	adds r3, r4, 0
	movs r4, 0x5
_08053A28:
	ldrh r0, [r1]
	lsls r0, 1
	strh r0, [r1]
	adds r2, 0x1
	ldrb r0, [r3, 0x11]
	lsls r0, 28
	lsrs r0, 28
	subs r0, r4, r0
	cmp r2, r0
	blt _08053A28
_08053A3C:
	ldrb r1, [r6]
	movs r0, 0x58
	muls r0, r1
	mov r1, r9
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 23
	ands r0, r1
	cmp r0, 0
	beq _08053A5A
	ldrh r0, [r5]
	lsls r0, 1
	strh r0, [r5]
_08053A5A:
	ldr r0, [r7]
	adds r0, 0x1
	str r0, [r7]
_08053A60:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB3_rolloutdamagecalculation

	thumb_func_start atkB4_jumpifconfusedandstatmaxed
atkB4_jumpifconfusedandstatmaxed: @ 8053A90
	push {r4,r5,lr}
	ldr r5, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	adds r3, r1, 0
	muls r3, r0
	adds r0, r5, 0
	adds r0, 0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	ldr r4, =gBattlescriptCurrInstr
	cmp r0, 0
	beq _08053AEC
	ldr r2, [r4]
	ldrb r0, [r2, 0x1]
	adds r0, r3
	adds r1, r5, 0
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xC
	bne _08053AEC
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
	b _08053AF2
	.pool
_08053AEC:
	ldr r0, [r4]
	adds r0, 0x6
	str r0, [r4]
_08053AF2:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end atkB4_jumpifconfusedandstatmaxed

	thumb_func_start atkB5_furycuttercalc
atkB5_furycuttercalc: @ 8053AF8
	push {r4,r5,lr}
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08053B34
	ldr r2, =gDisableStructs
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x10]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D8A60
	str r0, [r1]
	b _08053B8C
	.pool
_08053B34:
	ldr r5, =gDisableStructs
	ldr r4, =gBankAttacker
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1, 0x10]
	cmp r0, 0x5
	beq _08053B4C
	adds r0, 0x1
	strb r0, [r1, 0x10]
_08053B4C:
	ldr r3, =gDynamicBasePower
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	strh r0, [r3]
	movs r2, 0x1
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r4, =gBattlescriptCurrInstr
	ldrb r1, [r0, 0x10]
	cmp r2, r1
	bge _08053B86
	adds r1, r3, 0
	adds r3, r0, 0
_08053B78:
	ldrh r0, [r1]
	lsls r0, 1
	strh r0, [r1]
	adds r2, 0x1
	ldrb r0, [r3, 0x10]
	cmp r2, r0
	blt _08053B78
_08053B86:
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
_08053B8C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB5_furycuttercalc

	thumb_func_start atkB6_happinesstodamagecalculation
atkB6_happinesstodamagecalculation: @ 8053BAC
	push {r4,lr}
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x79
	bne _08053BEC
	ldr r4, =gDynamicBasePower
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2B
	ldrb r1, [r0]
	b _08053C02
	.pool
_08053BEC:
	ldr r4, =gDynamicBasePower
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2B
	ldrb r0, [r0]
	movs r1, 0xFF
	subs r1, r0
_08053C02:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	movs r1, 0x19
	bl __divsi3
	strh r0, [r4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB6_happinesstodamagecalculation

	thumb_func_start atkB7_presentdamagecalculation
atkB7_presentdamagecalculation: @ 8053C30
	push {r4,lr}
	bl Random
	movs r4, 0xFF
	ands r4, r0
	cmp r4, 0x65
	bgt _08053C4C
	ldr r1, =gDynamicBasePower
	movs r0, 0x28
	strh r0, [r1]
	b _08053C8E
	.pool
_08053C4C:
	cmp r4, 0xB1
	bgt _08053C5C
	ldr r1, =gDynamicBasePower
	movs r0, 0x50
	strh r0, [r1]
	b _08053C8E
	.pool
_08053C5C:
	cmp r4, 0xCB
	bgt _08053C6C
	ldr r1, =gDynamicBasePower
	movs r0, 0x78
	strh r0, [r1]
	b _08053C8E
	.pool
_08053C6C:
	ldr r3, =gBattleMoveDamage
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x2C]
	lsrs r0, 2
	str r0, [r3]
	cmp r0, 0
	bne _08053C88
	movs r0, 0x1
	str r0, [r3]
_08053C88:
	ldr r0, [r3]
	negs r0, r0
	str r0, [r3]
_08053C8E:
	cmp r4, 0xCB
	bgt _08053CAC
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D8A30
	b _08053CE6
	.pool
_08053CAC:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0, 0x2C]
	ldrh r0, [r0, 0x28]
	cmp r1, r0
	bne _08053CD8
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D9EFB
	b _08053CE6
	.pool
_08053CD8:
	ldr r2, =gBattleMoveFlags
	ldrb r1, [r2]
	movs r0, 0xF7
	ands r0, r1
	strb r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D9EE1
_08053CE6:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB7_presentdamagecalculation

	thumb_func_start atkB8_set_safeguard
atkB8_set_safeguard: @ 8053CFC
	push {r4-r7,lr}
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	bl GetBankIdentity
	ldr r4, =gSideAffecting
	movs r6, 0x1
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r1, [r1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08053D40
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	b _08053D88
	.pool
_08053D40:
	ldrb r0, [r7]
	bl GetBankIdentity
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r1]
	movs r2, 0x20
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r7]
	bl GetBankIdentity
	ldr r5, =gSideTimers
	adds r1, r6, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r4, 0x5
	strb r4, [r0, 0x6]
	ldrb r0, [r7]
	bl GetBankIdentity
	adds r1, r6, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r7]
	strb r1, [r0, 0x7]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
_08053D88:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB8_set_safeguard

	thumb_func_start atkB9_magnitudedamagecalculation
atkB9_magnitudedamagecalculation: @ 8053DA4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x4
	bgt _08053DD0
	ldr r1, =gDynamicBasePower
	movs r0, 0xA
	strh r0, [r1]
	movs r3, 0x4
	b _08053E3C
	.pool
_08053DD0:
	cmp r3, 0xE
	bgt _08053DE4
	ldr r1, =gDynamicBasePower
	movs r0, 0x1E
	strh r0, [r1]
	movs r3, 0x5
	b _08053E3C
	.pool
_08053DE4:
	cmp r3, 0x22
	bgt _08053DF8
	ldr r1, =gDynamicBasePower
	movs r0, 0x32
	strh r0, [r1]
	movs r3, 0x6
	b _08053E3C
	.pool
_08053DF8:
	cmp r3, 0x40
	bgt _08053E0C
	ldr r1, =gDynamicBasePower
	movs r0, 0x46
	strh r0, [r1]
	movs r3, 0x7
	b _08053E3C
	.pool
_08053E0C:
	cmp r3, 0x54
	bgt _08053E20
	ldr r1, =gDynamicBasePower
	movs r0, 0x5A
	strh r0, [r1]
	movs r3, 0x8
	b _08053E3C
	.pool
_08053E20:
	cmp r3, 0x5E
	bgt _08053E34
	ldr r1, =gDynamicBasePower
	movs r0, 0x6E
	strh r0, [r1]
	movs r3, 0x9
	b _08053E3C
	.pool
_08053E34:
	ldr r1, =gDynamicBasePower
	movs r0, 0x96
	strh r0, [r1]
	movs r3, 0xA
_08053E3C:
	ldr r1, =gBattleTextBuff1
	movs r2, 0
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	movs r0, 0x2
	strb r0, [r1, 0x3]
	strb r3, [r1, 0x4]
	movs r0, 0xFF
	strb r0, [r1, 0x5]
	ldr r1, =gBankTarget
	strb r2, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r3, [r0]
	adds r6, r1, 0
	ldr r0, =gBattlescriptCurrInstr
	mov r8, r0
	cmp r2, r3
	bcs _08053E94
	adds r4, r6, 0
	ldr r0, =gBankAttacker
	ldrb r5, [r0]
	ldr r1, =gBitTable
	mov r12, r1
	ldr r7, =gAbsentBankFlags
_08053E72:
	ldrb r2, [r4]
	cmp r2, r5
	beq _08053E88
	ldrb r0, [r7]
	ldrb r1, [r6]
	lsls r1, 2
	add r1, r12
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	beq _08053E94
_08053E88:
	adds r0, r2, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r3
	bcc _08053E72
_08053E94:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkB9_magnitudedamagecalculation

	thumb_func_start atkBA_jumpifnopursuitswitchdmg
atkBA_jumpifnopursuitswitchdmg: @ 8053EC8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gMultiHitCounter
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08053EF8
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08053EF4
	movs r0, 0x1
	b _08053F12
	.pool
_08053EF4:
	movs r0, 0
	b _08053F12
_08053EF8:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08053F10
	movs r0, 0x3
	b _08053F12
	.pool
_08053F10:
	movs r0, 0x2
_08053F12:
	bl GetBankByIdentity
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r0, =gUnknown_0202421C
	ldr r1, =gBankTarget
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08053F2A
	b _08054030
_08053F2A:
	ldr r5, =gBankAttacker
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, r3, r1
	ldrb r2, [r5]
	ldrb r1, [r1, 0xC]
	cmp r2, r1
	bne _08054030
	ldr r4, =gBattleMons
	movs r2, 0x58
	adds r0, r3, 0
	muls r0, r2
	adds r1, r4, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x27
	ands r0, r1
	cmp r0, 0
	bne _08054030
	ldrb r0, [r5]
	muls r0, r2
	adds r0, r4
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08054030
	ldr r0, =gDisableStructs
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x18]
	lsls r0, 31
	cmp r0, 0
	bne _08054030
	ldr r0, =gChosenMovesByBanks
	lsls r1, r3, 1
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0xE4
	bne _08054030
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	ldr r2, =gCurrentMove
	mov r8, r2
	ldr r7, =gCurrMovePos
	mov r10, r7
	ldr r2, =gUnknown_020241E9
	mov r9, r2
	ldr r7, =gHitMarker
	mov r12, r7
	ldrb r2, [r0]
	cmp r1, r2
	bge _08053FB6
	ldr r6, =gTurnOrder
	ldr r5, =gBankTarget
	ldr r4, =gUnknown_0202407A
	movs r3, 0xB
	adds r2, r0, 0
_08053FA0:
	adds r0, r1, r6
	ldrb r0, [r0]
	ldrb r7, [r5]
	cmp r0, r7
	bne _08053FAE
	adds r0, r1, r4
	strb r3, [r0]
_08053FAE:
	adds r1, 0x1
	ldrb r0, [r2]
	cmp r1, r0
	blt _08053FA0
_08053FB6:
	movs r0, 0xE4
	mov r1, r8
	strh r0, [r1]
	ldr r2, =gBankTarget
	ldrb r0, [r2]
	ldr r7, =gBattleStruct
	ldr r1, [r7]
	adds r0, r1
	adds r0, 0x80
	ldrb r0, [r0]
	mov r1, r9
	strb r0, [r1]
	mov r2, r10
	strb r0, [r2]
	ldr r7, =gBattlescriptCurrInstr
	ldr r0, [r7]
	adds r0, 0x5
	str r0, [r7]
	movs r0, 0x1
	ldr r1, =gBattleScripting
	strb r0, [r1, 0x18]
	mov r2, r12
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	b _0805404A
	.pool
_08054030:
	ldr r3, =gBattlescriptCurrInstr
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
_0805404A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkBA_jumpifnopursuitswitchdmg

	thumb_func_start atkBB_setsunny
atkBB_setsunny: @ 805405C
	push {lr}
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08054088
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _0805409A
	.pool
_08054088:
	movs r0, 0x20
	strh r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x4
	strb r0, [r1, 0x5]
	ldr r0, =gWishFutureKnock
	adds r0, 0x28
	movs r1, 0x5
	strb r1, [r0]
_0805409A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkBB_setsunny

	thumb_func_start atkBC_maxattackhalvehp
atkBC_maxattackhalvehp: @ 80540B4
	push {r4,r5,lr}
	ldr r5, =gBattleMons
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	movs r3, 0x58
	muls r0, r3
	adds r2, r0, r5
	ldrh r0, [r2, 0x2C]
	lsrs r1, r0, 1
	cmp r1, 0
	bne _080540CC
	movs r1, 0x1
_080540CC:
	movs r0, 0x19
	ldrsb r0, [r2, r0]
	cmp r0, 0xB
	bgt _08054110
	ldrh r0, [r2, 0x28]
	cmp r0, r1
	bls _08054110
	movs r0, 0xC
	strb r0, [r2, 0x19]
	ldr r1, =gBattleMoveDamage
	ldrb r0, [r4]
	muls r0, r3
	adds r0, r5
	ldrh r0, [r0, 0x2C]
	lsrs r0, 1
	str r0, [r1]
	cmp r0, 0
	bne _080540F4
	movs r0, 0x1
	str r0, [r1]
_080540F4:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _0805412A
	.pool
_08054110:
	ldr r3, =gBattlescriptCurrInstr
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
_0805412A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkBC_maxattackhalvehp

	thumb_func_start atkBD_copyfoestats
atkBD_copyfoestats: @ 8054134
	push {r4-r7,lr}
	movs r2, 0
	ldr r7, =gBattlescriptCurrInstr
	ldr r6, =gBankAttacker
	movs r4, 0x58
	ldr r3, =gBattleMons + 0x18
	ldr r5, =gBankTarget
_08054142:
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r4
	adds r1, r2, r1
	adds r1, r3
	ldrb r0, [r5]
	muls r0, r4
	adds r0, r2, r0
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x7
	ble _08054142
	ldr r0, [r7]
	adds r0, 0x5
	str r0, [r7]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkBD_copyfoestats

	thumb_func_start atkBE_breakfree
atkBE_breakfree: @ 805417C
	push {r4-r6,lr}
	ldr r1, =gBattleMons
	ldr r5, =gBankAttacker
	ldrb r2, [r5]
	movs r6, 0x58
	adds r0, r2, 0
	muls r0, r6
	adds r4, r1, 0
	adds r4, 0x50
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0xE0
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _08054210
	ldr r1, =gBattleScripting
	ldr r3, =gBankTarget
	ldrb r0, [r3]
	strb r0, [r1, 0x17]
	ldrb r0, [r5]
	adds r1, r0, 0
	muls r1, r6
	adds r1, r4
	ldr r0, [r1]
	ldr r2, =0xffff1fff
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r5]
	ldr r1, =gBattleStruct
	ldr r2, [r1]
	adds r0, r2
	ldrb r0, [r0, 0x14]
	strb r0, [r3]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0, 0x4]
	strb r0, [r1, 0x2]
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0, 0x5]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	bl BattleScriptPushCursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAFC5
	b _080542BA
	.pool
_08054210:
	ldr r4, =gStatuses3
	lsls r0, r2, 2
	adds r3, r0, r4
	ldr r1, [r3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08054250
	movs r0, 0x5
	negs r0, r0
	ands r1, r0
	str r1, [r3]
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r4
	ldr r0, [r1]
	movs r2, 0x4
	negs r2, r2
	ands r0, r2
	str r0, [r1]
	bl BattleScriptPushCursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAFD6
	b _080542BA
	.pool
_08054250:
	adds r0, r2, 0
	bl GetBankSide
	ldr r4, =gSideAffecting
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080542B4
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r2, [r0]
	ldr r1, =0x0000ffef
	ands r1, r2
	movs r4, 0
	strh r1, [r0]
	ldrb r0, [r5]
	bl GetBankSide
	ldr r2, =gSideTimers
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	strb r4, [r1, 0xA]
	bl BattleScriptPushCursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAFDD
	b _080542BA
	.pool
_080542B4:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
_080542BA:
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkBE_breakfree

	thumb_func_start atkBF_set_defense_curl
atkBF_set_defense_curl: @ 80542C8
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 23
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atkBF_set_defense_curl

	thumb_func_start atkC0_recoverbasedonsunlight
atkC0_recoverbasedonsunlight: @ 80542F8
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r1, =gBankTarget
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	strb r0, [r1]
	ldr r7, =gBattleMons
	ldrb r0, [r5]
	movs r6, 0x58
	muls r0, r6
	adds r0, r7
	ldrh r1, [r0, 0x28]
	ldrh r0, [r0, 0x2C]
	cmp r1, r0
	beq _080543D8
	ldr r4, =gBattleWeather
	ldrh r0, [r4]
	cmp r0, 0
	beq _0805434A
	movs r0, 0
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805434A
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _08054378
_0805434A:
	ldr r3, =gBattleMoveDamage
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x2C]
	lsrs r0, 1
	str r0, [r3]
	adds r1, r3, 0
	b _080543B2
	.pool
_08054378:
	ldrh r1, [r4]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _080543A4
	ldr r4, =gBattleMoveDamage
	ldrb r0, [r5]
	muls r0, r6
	adds r0, r7
	ldrh r1, [r0, 0x2C]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	movs r1, 0x1E
	bl __divsi3
	str r0, [r4]
	adds r1, r4, 0
	b _080543B2
	.pool
_080543A4:
	ldr r1, =gBattleMoveDamage
	ldrb r0, [r5]
	muls r0, r6
	adds r0, r7
	ldrh r0, [r0, 0x2C]
	lsrs r0, 2
	str r0, [r1]
_080543B2:
	adds r2, r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080543BE
	movs r0, 0x1
	str r0, [r2]
_080543BE:
	ldr r0, [r1]
	negs r0, r0
	str r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _080543F2
	.pool
_080543D8:
	ldr r3, =gBattlescriptCurrInstr
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
_080543F2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC0_recoverbasedonsunlight

	thumb_func_start atkC1_hidden_power
atkC1_hidden_power: @ 8054400
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	adds r4, r1, 0
	muls r4, r0
	adds r4, r2
	ldrb r0, [r4, 0x14]
	mov r10, r0
	mov r7, r10
	lsls r7, 27
	adds r0, r7, 0
	lsrs r0, 27
	mov r10, r0
	movs r1, 0x2
	mov r2, r10
	ands r2, r1
	asrs r2, 1
	ldrh r7, [r4, 0x14]
	mov r9, r7
	mov r0, r9
	lsls r0, 22
	mov r9, r0
	lsrs r3, r0, 27
	adds r0, r1, 0
	ands r0, r3
	orrs r2, r0
	ldrb r7, [r4, 0x15]
	mov r8, r7
	mov r0, r8
	lsls r0, 25
	mov r8, r0
	lsrs r3, r0, 27
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 1
	orrs r2, r0
	ldr r6, [r4, 0x14]
	lsls r6, 12
	lsrs r3, r6, 27
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrh r5, [r4, 0x16]
	lsls r5, 23
	lsrs r3, r5, 27
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 3
	orrs r2, r0
	ldrb r3, [r4, 0x17]
	lsls r3, 26
	lsrs r0, r3, 27
	ands r1, r0
	lsls r1, 4
	orrs r2, r1
	movs r1, 0x1
	adds r4, r1, 0
	mov r7, r10
	ands r4, r7
	mov r0, r9
	lsrs r0, 27
	mov r9, r0
	adds r0, r1, 0
	mov r7, r9
	ands r0, r7
	lsls r0, 1
	orrs r4, r0
	mov r0, r8
	lsrs r0, 27
	mov r8, r0
	adds r0, r1, 0
	mov r7, r8
	ands r0, r7
	lsls r0, 2
	orrs r4, r0
	lsrs r6, 27
	adds r0, r1, 0
	ands r0, r6
	lsls r0, 3
	orrs r4, r0
	lsrs r5, 27
	adds r0, r1, 0
	ands r0, r5
	lsls r0, 4
	orrs r4, r0
	lsrs r3, 27
	ands r1, r3
	lsls r1, 5
	orrs r4, r1
	ldr r5, =gDynamicBasePower
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	movs r1, 0x3F
	bl __divsi3
	adds r0, 0x1E
	strh r0, [r5]
	ldr r6, =gBattleStruct
	ldr r5, [r6]
	lsls r0, r4, 4
	subs r0, r4
	movs r1, 0x3F
	bl __divsi3
	adds r0, 0x1
	strb r0, [r5, 0x13]
	ldr r1, [r6]
	ldrb r0, [r1, 0x13]
	cmp r0, 0x8
	bls _080544F0
	adds r0, 0x1
	strb r0, [r1, 0x13]
_080544F0:
	ldr r2, [r6]
	ldrb r0, [r2, 0x13]
	movs r1, 0xC0
	orrs r0, r1
	strb r0, [r2, 0x13]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC1_hidden_power

	thumb_func_start atkC2_selectnexttarget
atkC2_selectnexttarget: @ 8054524
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBankTarget
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gNoOfAllBanks
	ldrb r1, [r1]
	adds r6, r0, 0
	ldr r0, =gBattlescriptCurrInstr
	mov r8, r0
	cmp r1, 0
	beq _0805456E
	adds r3, r6, 0
	ldr r0, =gBankAttacker
	ldrb r5, [r0]
	ldr r0, =gBitTable
	mov r12, r0
	adds r4, r1, 0
	ldr r7, =gAbsentBankFlags
_0805454C:
	ldrb r2, [r3]
	cmp r2, r5
	beq _08054562
	ldrb r0, [r7]
	ldrb r1, [r6]
	lsls r1, 2
	add r1, r12
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	beq _0805456E
_08054562:
	adds r0, r2, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	bcc _0805454C
_0805456E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC2_selectnexttarget

	thumb_func_start atkC3_setfutureattack
atkC3_setfutureattack: @ 8054598
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r0, =gWishFutureKnock
	mov r8, r0
	ldr r6, =gBankTarget
	ldrb r1, [r6]
	adds r0, r1, r0
	ldrb r7, [r0]
	cmp r7, 0
	beq _080545DC
	ldr r3, =gBattlescriptCurrInstr
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
	b _080546CC
	.pool
_080545DC:
	adds r0, r1, 0
	bl GetBankIdentity
	ldr r4, =gSideAffecting
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	mov r10, r1
	ands r0, r1
	lsls r0, 1
	adds r0, r4
	ldrh r2, [r0]
	movs r1, 0x40
	movs r5, 0
	mov r3, sp
	strh r5, [r3, 0x10]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r6]
	lsls r0, 1
	mov r1, r8
	adds r1, 0x18
	adds r0, r1
	ldr r1, =gCurrentMove
	mov r9, r1
	ldrh r1, [r1]
	strh r1, [r0]
	mov r0, r8
	adds r0, 0x4
	ldrb r2, [r6]
	adds r0, r2
	ldr r5, =gBankAttacker
	ldrb r1, [r5]
	strb r1, [r0]
	ldrb r0, [r6]
	add r0, r8
	movs r1, 0x3
	strb r1, [r0]
	ldrb r0, [r6]
	bl GetBankIdentity
	mov r1, r10
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r3, [r1]
	ldrb r0, [r5]
	movs r4, 0x58
	muls r0, r4
	ldr r2, =gBattleMons
	adds r0, r2
	ldrb r1, [r6]
	muls r1, r4
	adds r1, r2
	mov r4, r9
	ldrh r2, [r4]
	str r7, [sp]
	str r7, [sp, 0x4]
	ldrb r4, [r5]
	str r4, [sp, 0x8]
	ldrb r4, [r6]
	str r4, [sp, 0xC]
	bl CalculateBaseDamage
	ldrb r1, [r6]
	lsls r1, 2
	mov r2, r8
	adds r2, 0x8
	adds r1, r2
	str r0, [r1]
	ldr r1, =gProtectStructs
	ldrb r0, [r5]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 28
	cmp r0, 0
	bge _0805468C
	ldrb r4, [r6]
	lsls r4, 2
	adds r4, r2
	ldr r1, [r4]
	lsls r0, r1, 4
	subs r0, r1
	movs r1, 0xA
	bl __divsi3
	str r0, [r4]
_0805468C:
	mov r5, r9
	ldrh r1, [r5]
	ldr r0, =0x00000161
	cmp r1, r0
	bne _080546BC
	ldr r0, =gBattleCommunication
	mov r1, r10
	strb r1, [r0, 0x5]
	b _080546C4
	.pool
_080546BC:
	ldr r0, =gBattleCommunication
	mov r2, sp
	ldrb r2, [r2, 0x10]
	strb r2, [r0, 0x5]
_080546C4:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080546CC:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC3_setfutureattack

	thumb_func_start atkC4_beat_up
atkC4_beat_up: @ 80546E4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r7, =gEnemyParty
	cmp r0, 0
	bne _080546FE
	ldr r7, =gPlayerParty
_080546FE:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08054740
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	b _080548DC
	.pool
_08054740:
	ldr r6, =gBattleCommunication
	ldrb r0, [r6]
	mov r8, r0
	cmp r0, 0x5
	bls _0805474C
	b _080548A8
_0805474C:
	adds r4, r6, 0
	movs r5, 0x64
_08054750:
	ldrb r0, [r4]
	muls r0, r5
	adds r0, r7, r0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08054794
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r7, r0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08054794
	ldrb r0, [r4]
	muls r0, r5
	adds r0, r7, r0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08054794
	ldrb r0, [r4]
	muls r0, r5
	adds r0, r7, r0
	movs r1, 0x37
	bl GetMonData
	cmp r0, 0
	beq _080547A4
_08054794:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	adds r6, r4, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _08054750
_080547A4:
	ldr r1, =gBattleCommunication
	mov r9, r1
	ldrb r2, [r1]
	cmp r2, 0x5
	bhi _080548A8
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	strb r0, [r1, 0x2]
	strb r2, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x9
	str r0, [r1]
	ldr r2, =gBattleMoveDamage
	mov r8, r2
	ldr r5, =gBaseStats
	mov r1, r9
	ldrb r0, [r1]
	movs r4, 0x64
	muls r0, r4
	adds r0, r7, r0
	movs r1, 0xB
	bl GetMonData
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r3, [r1, 0x1]
	mov r2, r8
	str r3, [r2]
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	muls r0, r3
	mov r1, r8
	str r0, [r1]
	mov r2, r9
	ldrb r0, [r2]
	muls r0, r4
	adds r0, r7, r0
	movs r1, 0x38
	bl GetMonData
	lsls r0, 1
	movs r1, 0x5
	bl __udivsi3
	adds r0, 0x2
	mov r2, r8
	ldr r1, [r2]
	muls r0, r1
	str r0, [r2]
	ldr r3, =gBattleMons
	ldr r1, =gBankTarget
	ldrb r2, [r1]
	movs r1, 0x58
	muls r1, r2
	adds r1, r3
	ldrh r2, [r1]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r5
	ldrb r1, [r1, 0x2]
	bl __divsi3
	mov r1, r8
	str r0, [r1]
	movs r1, 0x32
	bl __divsi3
	adds r2, r0, 0x2
	mov r0, r8
	str r2, [r0]
	ldr r1, =gProtectStructs
	ldrb r0, [r6]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 28
	cmp r0, 0
	bge _08054870
	lsls r0, r2, 4
	subs r0, r2
	movs r1, 0xA
	bl __divsi3
	mov r1, r8
	str r0, [r1]
_08054870:
	mov r2, r9
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	b _080548E2
	.pool
_080548A8:
	mov r0, r8
	cmp r0, 0
	beq _080548C8
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x4]
	b _080548DC
	.pool
_080548C8:
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r1, r0
	ldrb r0, [r2, 0x8]
_080548DC:
	lsls r0, 24
	orrs r1, r0
	str r1, [r3]
_080548E2:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC4_beat_up

	thumb_func_start atkC5_hidepreattack
atkC5_hidepreattack: @ 80548F4
	push {lr}
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	cmp r1, 0x5B
	beq _08054934
	cmp r1, 0x5B
	bgt _0805490C
	cmp r1, 0x13
	beq _08054918
	b _08054960
	.pool
_0805490C:
	ldr r0, =0x00000123
	cmp r1, r0
	beq _0805494C
	adds r0, 0x31
	cmp r1, r0
	bne _08054960
_08054918:
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x40
	b _0805495C
	.pool
_08054934:
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x80
	b _0805495C
	.pool
_0805494C:
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 11
_0805495C:
	orrs r0, r2
	str r0, [r1]
_08054960:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC5_hidepreattack

	thumb_func_start atkC6_unhidepostattack
atkC6_unhidepostattack: @ 8054978
	push {lr}
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	cmp r1, 0x5B
	beq _080549BC
	cmp r1, 0x5B
	bgt _08054990
	cmp r1, 0x13
	beq _0805499C
	b _080549EA
	.pool
_08054990:
	ldr r0, =0x00000123
	cmp r1, r0
	beq _080549D8
	adds r0, 0x31
	cmp r1, r0
	bne _080549EA
_0805499C:
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x41
	negs r2, r2
	b _080549E6
	.pool
_080549BC:
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x81
	negs r2, r2
	b _080549E6
	.pool
_080549D8:
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	ldr r2, =0xfffbffff
_080549E6:
	ands r0, r2
	str r0, [r1]
_080549EA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC6_unhidepostattack

	thumb_func_start atkC7_setminimize
atkC7_setminimize: @ 8054A08
	push {lr}
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _08054A2C
	ldr r2, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 1
	orrs r0, r2
	str r0, [r1]
_08054A2C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC7_setminimize

	thumb_func_start atkC8_sethail
atkC8_sethail: @ 8054A48
	push {lr}
	ldr r3, =gBattleWeather
	ldrh r1, [r3]
	movs r2, 0x80
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08054A78
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _08054A86
	.pool
_08054A78:
	strh r2, [r3]
	ldr r0, =gBattleCommunication
	movs r1, 0x5
	strb r1, [r0, 0x5]
	ldr r0, =gWishFutureKnock
	adds r0, 0x28
	strb r1, [r0]
_08054A86:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC8_sethail

	thumb_func_start atkC9_jumpifattackandspecialattackcannotfall
atkC9_jumpifattackandspecialattackcannotfall: @ 8054AA0
	push {r4,lr}
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r1, r0, r2
	movs r0, 0x19
	ldrsb r0, [r1, r0]
	adds r3, r2, 0
	cmp r0, 0
	bne _08054AF4
	movs r0, 0x1C
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bne _08054AF4
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x6]
	cmp r0, 0x1
	beq _08054AF4
	ldr r3, =gBattlescriptCurrInstr
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
	b _08054B20
	.pool
_08054AF4:
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r2, =gBattleMoveDamage
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r0, r3
	ldrh r0, [r0, 0x28]
	str r0, [r2]
	ldr r1, =0x00007fff
	movs r0, 0
	bl EmitHealthBarUpdate
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08054B20:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkC9_jumpifattackandspecialattackcannotfall

	thumb_func_start atkCA_setforcedtarget
atkCA_setforcedtarget: @ 8054B3C
	push {r4,r5,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	ldr r5, =gSideTimers
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r0, 0x1
	strb r0, [r1, 0x8]
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r4]
	strb r0, [r1, 0x9]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkCA_setforcedtarget

	thumb_func_start atkCB_setcharge
atkCB_setcharge: @ 8054B88
	push {r4,lr}
	ldr r0, =gStatuses3
	ldr r3, =gBankAttacker
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 2
	orrs r0, r2
	str r0, [r1]
	ldr r4, =gDisableStructs
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r2, [r0, 0x12]
	movs r1, 0x10
	negs r1, r1
	ands r1, r2
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0, 0x12]
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r2, [r0, 0x12]
	movs r1, 0xF
	ands r1, r2
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x12]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkCB_setcharge

	thumb_func_start atkCC_callterrainattack
atkCC_callterrainattack: @ 8054BEC
	push {r4,lr}
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	ldr r4, =gCurrentMove
	ldr r1, =gUnknown_0831C414
	ldr r0, =gUnknown_02022FF0
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r3, =gBattleScriptsForMoveEffects
	ldr r2, =gBattleMoves
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	bl BattleScriptPush
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkCC_callterrainattack

	thumb_func_start atkCD_cureifburnedparalysedorpoisoned
atkCD_cureifburnedparalysedorpoisoned: @ 8054C60
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r1, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	movs r6, 0x58
	muls r0, r6
	adds r5, r1, 0
	adds r5, 0x4C
	adds r2, r0, r5
	ldr r0, [r2]
	movs r1, 0xD8
	ands r0, r1
	cmp r0, 0
	beq _08054CBC
	movs r0, 0
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	ldr r4, =gActiveBank
	ldrb r0, [r3]
	strb r0, [r4]
	ldrb r0, [r4]
	muls r0, r6
	adds r0, r5
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
	b _08054CD6
	.pool
_08054CBC:
	ldr r3, =gBattlescriptCurrInstr
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
_08054CD6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkCD_cureifburnedparalysedorpoisoned

	thumb_func_start atkCE_settorment
atkCE_settorment: @ 8054CE4
	push {lr}
	ldr r1, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 24
	cmp r1, 0
	bge _08054D28
	ldr r3, =gBattlescriptCurrInstr
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
	b _08054D34
	.pool
_08054D28:
	orrs r1, r2
	str r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08054D34:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkCE_settorment

	thumb_func_start atkCF_jumpifnodamage
atkCF_jumpifnodamage: @ 8054D3C
	push {lr}
	ldr r2, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08054D5C
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _08054D74
_08054D5C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08054D8E
	.pool
_08054D74:
	ldr r3, =gBattlescriptCurrInstr
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
_08054D8E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkCF_jumpifnodamage

	thumb_func_start atkD0_settaunt
atkD0_settaunt: @ 8054D98
	push {r4,lr}
	ldr r4, =gDisableStructs
	ldr r3, =gBankTarget
	ldrb r0, [r3]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r4
	ldrb r1, [r2, 0x13]
	lsls r0, r1, 28
	cmp r0, 0
	bne _08054DE8
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x13]
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r2, [r0, 0x13]
	movs r1, 0xF
	ands r1, r2
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x13]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08054E02
	.pool
_08054DE8:
	ldr r3, =gBattlescriptCurrInstr
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
_08054E02:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD0_settaunt

	thumb_func_start atkD1_set_helpinghand
atkD1_set_helpinghand: @ 8054E0C
	push {r4,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
	ldr r3, =gBankTarget
	strb r0, [r3]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08054E90
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r3, [r3]
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08054E90
	ldr r1, =gProtectStructs
	ldrb r0, [r4]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 28
	cmp r0, 0
	blt _08054E90
	lsls r0, r3, 4
	adds r2, r0, r1
	ldrb r1, [r2]
	lsls r0, r1, 28
	cmp r0, 0
	blt _08054E90
	movs r0, 0x8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08054EAA
	.pool
_08054E90:
	ldr r3, =gBattlescriptCurrInstr
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
_08054EAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD1_set_helpinghand

	thumb_func_start atkD2_swap_items
atkD2_swap_items: @ 8054EB4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 19
	ands r0, r1
	cmp r0, 0
	bne _08054F9A
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08054EE8
	ldr r0, [r4]
	ldr r1, =0x0a3f0902
	ands r0, r1
	cmp r0, 0
	beq _08054F9A
_08054EE8:
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r7, =gBankTarget
	ldrb r0, [r7]
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x0a3f0902
	ands r0, r1
	cmp r0, 0
	bne _08054F46
	ldr r0, =gWishFutureKnock
	adds r2, r0, 0
	adds r2, 0x29
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r4, =gBitTable
	ldr r3, =gBattlePartyID
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08054F9A
	adds r0, r5, r2
	ldrb r1, [r0]
	ldrb r0, [r7]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08054F9A
_08054F46:
	ldr r0, =gBattleMons
	mov r8, r0
	ldr r1, =gBankAttacker
	ldrb r4, [r1]
	movs r5, 0x58
	adds r0, r4, 0
	muls r0, r5
	add r0, r8
	mov r9, r0
	ldrh r3, [r0, 0x2E]
	adds r1, r3, 0
	cmp r1, 0
	bne _08054F6E
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	muls r0, r5
	add r0, r8
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	beq _08054F9A
_08054F6E:
	cmp r1, 0xAF
	beq _08054F9A
	ldr r7, =gBankTarget
	ldrb r0, [r7]
	muls r0, r5
	mov r2, r8
	adds r1, r0, r2
	ldrh r2, [r1, 0x2E]
	cmp r2, 0xAF
	beq _08054F9A
	adds r0, r3, 0
	subs r0, 0x79
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bls _08054F9A
	adds r0, r2, 0
	subs r0, 0x79
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bhi _08054FDC
_08054F9A:
	ldr r3, =gBattlescriptCurrInstr
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
	b _08055132
	.pool
_08054FDC:
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x3C
	bne _08055010
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =BattleScript_StickyHoldOnKnockOff
	str r0, [r1]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r7]
	muls r0, r5
	add r0, r8
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08055132
	.pool
_08055010:
	ldr r3, =gBattleStruct
	mov r10, r3
	lsls r0, r4, 1
	adds r0, 0xD0
	ldr r1, [r3]
	adds r6, r1, r0
	mov r0, r9
	ldrh r0, [r0, 0x2E]
	mov r9, r0
	strh r2, [r6]
	ldr r1, =gBankAttacker
	ldrb r0, [r1]
	muls r0, r5
	add r0, r8
	movs r1, 0
	strh r1, [r0, 0x2E]
	ldrb r0, [r7]
	muls r0, r5
	add r0, r8
	mov r2, r9
	strh r2, [r0, 0x2E]
	ldr r4, =gActiveBank
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	strb r0, [r4]
	str r6, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x2
	bl EmitSetMonData
	ldr r1, =gBankAttacker
	ldrb r0, [r1]
	bl MarkBufferBankForExecution
	ldrb r0, [r7]
	strb r0, [r4]
	ldrb r0, [r7]
	muls r0, r5
	mov r1, r8
	adds r1, 0x2E
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x2
	bl EmitSetMonData
	ldrb r0, [r7]
	bl MarkBufferBankForExecution
	ldrb r0, [r7]
	mov r2, r10
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC8
	movs r3, 0
	strb r3, [r0]
	ldrb r0, [r7]
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC9
	strb r3, [r0]
	ldr r1, =gBankAttacker
	ldrb r0, [r1]
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC8
	strb r3, [r0]
	ldr r2, =gBankAttacker
	ldrb r0, [r2]
	mov r3, r10
	ldr r1, [r3]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC9
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	ldr r1, =gBattleTextBuff1
	movs r3, 0xFD
	strb r3, [r1]
	movs r2, 0xA
	strb r2, [r1, 0x1]
	ldrh r0, [r6]
	strb r0, [r1, 0x2]
	ldrh r0, [r6]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattleTextBuff2
	strb r3, [r1]
	strb r2, [r1, 0x1]
	mov r2, r9
	strb r2, [r1, 0x2]
	mov r3, r9
	lsrs r0, r3, 8
	strb r0, [r1, 0x3]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x4]
	cmp r3, 0
	beq _08055118
	ldrh r0, [r6]
	cmp r0, 0
	beq _0805512C
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	b _08055130
	.pool
_08055118:
	ldrh r0, [r6]
	cmp r0, 0
	beq _0805512C
	ldr r0, =gBattleCommunication
	movs r1, 0
	strb r1, [r0, 0x5]
	b _08055132
	.pool
_0805512C:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
_08055130:
	strb r0, [r1, 0x5]
_08055132:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD2_swap_items

	thumb_func_start atkD3_copy_ability
atkD3_copy_ability: @ 8055148
	push {r4,lr}
	ldr r3, =gBattleMons
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	movs r2, 0x58
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r1, 0
	cmp r0, 0
	beq _0805519C
	cmp r0, 0x19
	beq _0805519C
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	strb r1, [r0]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r4]
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _080551B6
	.pool
_0805519C:
	ldr r3, =gBattlescriptCurrInstr
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
_080551B6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD3_copy_ability

	thumb_func_start atkD4_wish_effect
atkD4_wish_effect: @ 80551C0
	push {r4-r7,lr}
	ldr r7, =gBattlescriptCurrInstr
	ldr r2, [r7]
	ldrb r3, [r2, 0x1]
	cmp r3, 0
	beq _080551D8
	cmp r3, 0x1
	beq _08055210
	b _0805528C
	.pool
_080551D8:
	ldr r1, =gWishFutureKnock
	ldr r4, =gBankAttacker
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r5, [r4]
	adds r3, r0, r5
	ldrb r0, [r3]
	cmp r0, 0
	bne _0805525C
	movs r0, 0x2
	strb r0, [r3]
	ldrb r0, [r4]
	adds r1, 0x24
	adds r1, r0, r1
	ldr r2, =gBattlePartyID
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x6
	b _0805528A
	.pool
_08055210:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	strb r0, [r1, 0x2]
	ldr r0, =gWishFutureKnock
	adds r0, 0x24
	ldrb r5, [r4]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattleMoveDamage
	ldr r6, =gBattleMons
	ldrb r0, [r4]
	movs r5, 0x58
	muls r0, r5
	adds r0, r6
	ldrh r0, [r0, 0x2C]
	lsrs r0, 1
	str r0, [r1]
	cmp r0, 0
	bne _08055248
	str r3, [r1]
_08055248:
	ldr r0, [r1]
	negs r0, r0
	str r0, [r1]
	ldrb r0, [r4]
	muls r0, r5
	adds r0, r6
	ldrh r1, [r0, 0x28]
	ldrh r0, [r0, 0x2C]
	cmp r1, r0
	bne _08055288
_0805525C:
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
	str r1, [r7]
	b _0805528C
	.pool
_08055288:
	adds r0, r2, 0x6
_0805528A:
	str r0, [r7]
_0805528C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atkD4_wish_effect

	thumb_func_start atkD5_setroots
atkD5_setroots: @ 8055294
	push {lr}
	ldr r1, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, 0x80
	lsls r3, 3
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _080552D8
	ldr r3, =gBattlescriptCurrInstr
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
	b _080552E4
	.pool
_080552D8:
	orrs r1, r3
	str r1, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080552E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD5_setroots

	thumb_func_start atkD6_doubledamagedealtifdamaged
atkD6_doubledamagedealtifdamaged: @ 80552EC
	push {lr}
	ldr r3, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r0, r3, 0x4
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _0805530C
	adds r0, r2, r3
	ldr r1, =gBankTarget
	ldrb r0, [r0, 0xC]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08055324
_0805530C:
	adds r0, r3, 0
	adds r0, 0x8
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _0805532A
	adds r0, r2, r3
	ldr r1, =gBankTarget
	ldrb r0, [r0, 0xD]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805532A
_08055324:
	ldr r1, =gBattleScripting
	movs r0, 0x2
	strb r0, [r1, 0xE]
_0805532A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD6_doubledamagedealtifdamaged

	thumb_func_start atkD7_setyawn
atkD7_setyawn: @ 805534C
	push {r4,lr}
	ldr r1, =gStatuses3
	ldr r0, =gBankTarget
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r4, r0, r1
	ldr r2, [r4]
	movs r0, 0xC0
	lsls r0, 5
	ands r0, r2
	cmp r0, 0
	bne _08055374
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r1, 0x4C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080553A0
_08055374:
	ldr r3, =gBattlescriptCurrInstr
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
	b _080553B0
	.pool
_080553A0:
	movs r0, 0x80
	lsls r0, 5
	orrs r2, r0
	str r2, [r4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080553B0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD7_setyawn

	thumb_func_start atkD8_setdamagetohealthdifference
atkD8_setdamagetohealthdifference: @ 80553BC
	push {lr}
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	movs r1, 0x58
	muls r0, r1
	adds r3, r0, r2
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	muls r0, r1
	adds r1, r0, r2
	ldrh r0, [r3, 0x28]
	ldrh r2, [r1, 0x28]
	cmp r0, r2
	bhi _08055408
	ldr r3, =gBattlescriptCurrInstr
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
	b _0805541A
	.pool
_08055408:
	ldr r2, =gBattleMoveDamage
	ldrh r0, [r3, 0x28]
	ldrh r1, [r1, 0x28]
	subs r0, r1
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0805541A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD8_setdamagetohealthdifference

	thumb_func_start atkD9_scaledamagebyhealthratio
atkD9_scaledamagebyhealthratio: @ 8055428
	push {r4,lr}
	ldr r4, =gDynamicBasePower
	ldrh r0, [r4]
	cmp r0, 0
	bne _08055464
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r3, [r0, 0x1]
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r0, [r1, 0x28]
	muls r0, r3
	ldrh r1, [r1, 0x2C]
	bl __divsi3
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	bne _08055464
	movs r0, 0x1
	strh r0, [r4]
_08055464:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkD9_scaledamagebyhealthratio

	thumb_func_start atkDA_abilityswap
atkDA_abilityswap: @ 805548C
	push {r4-r6,lr}
	ldr r5, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	movs r4, 0x58
	muls r0, r4
	adds r0, r5
	adds r2, r0, 0
	adds r2, 0x20
	ldrb r1, [r2]
	cmp r1, 0
	bne _080554B4
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	muls r0, r4
	adds r0, r5
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080554D4
_080554B4:
	cmp r1, 0x19
	beq _080554D4
	ldr r6, =gBankTarget
	ldrb r0, [r6]
	muls r0, r4
	adds r0, r5
	adds r0, 0x20
	ldrb r3, [r0]
	cmp r3, 0x19
	beq _080554D4
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08055504
_080554D4:
	ldr r3, =gBattlescriptCurrInstr
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
	b _0805551A
	.pool
_08055504:
	ldrb r1, [r2]
	strb r3, [r2]
	ldrb r0, [r6]
	muls r0, r4
	adds r0, r5
	adds r0, 0x20
	strb r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0805551A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkDA_abilityswap

	thumb_func_start atkDB_imprisoneffect
atkDB_imprisoneffect: @ 8055524
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r1, =gStatuses3
	ldr r4, =gBankAttacker
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	beq _08055574
	b _080555F6
	.pool
_0805554C:
	ldr r0, =gStatuses3
	mov r2, r9
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 6
	orrs r0, r2
	str r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _080555EE
	.pool
_08055574:
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrb r0, [r4]
	bl sub_803F548
	movs r6, 0
	b _080555E6
_0805558A:
	adds r0, r6, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r8, r0
	beq _080555E0
	movs r4, 0
	ldr r7, =gBankAttacker
	mov r9, r7
	ldr r0, =gBattleMons
	mov r12, r0
	mov r1, r9
	ldrb r0, [r1]
	mov r2, r12
	adds r2, 0xC
	movs r1, 0x58
	muls r0, r1
	adds r3, r0, r2
	adds r5, r6, 0
	muls r5, r1
_080555B4:
	movs r2, 0
	ldrh r1, [r3]
	mov r0, r12
	adds r0, 0xC
	adds r0, r5, r0
_080555BE:
	ldrh r7, [r0]
	cmp r1, r7
	bne _080555C8
	cmp r1, 0
	bne _080555D0
_080555C8:
	adds r0, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	ble _080555BE
_080555D0:
	cmp r2, 0x4
	bne _080555DC
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	ble _080555B4
_080555DC:
	cmp r4, 0x4
	bne _0805554C
_080555E0:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080555E6:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	bcc _0805558A
_080555EE:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	bne _08055610
_080555F6:
	ldr r3, =gBattlescriptCurrInstr
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
_08055610:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkDB_imprisoneffect

	thumb_func_start atkDC_setgrudge
atkDC_setgrudge: @ 805562C
	push {lr}
	ldr r1, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, 0x80
	lsls r3, 7
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _08055670
	ldr r3, =gBattlescriptCurrInstr
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
	b _0805567C
	.pool
_08055670:
	orrs r1, r3
	str r1, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0805567C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkDC_setgrudge

	thumb_func_start atkDD_weightdamagecalculation
atkDD_weightdamagecalculation: @ 8055684
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	ldr r2, =gUnknown_0831C428
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _080556FC
	adds r6, r2, 0
	ldr r0, =gBattleMons
	mov r8, r0
	adds r7, r1, 0
	adds r4, r6, 0
_080556A0:
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	add r0, r8
	ldrh r0, [r0]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetPokedexHeightWeight
	ldrh r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bhi _080556CE
	adds r4, 0x4
	adds r5, 0x2
	ldrh r0, [r4]
	cmp r0, r7
	bne _080556A0
_080556CE:
	lsls r0, r5, 1
	adds r0, r6
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _080556FC
	ldr r0, =gDynamicBasePower
	adds r1, r5, 0x1
	lsls r1, 1
	adds r1, r6
	ldrh r1, [r1]
	strh r1, [r0]
	b _08055702
	.pool
_080556FC:
	ldr r1, =gDynamicBasePower
	movs r0, 0x78
	strh r0, [r1]
_08055702:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkDD_weightdamagecalculation

	thumb_func_start atkDE_asistattackselect
atkDE_asistattackselect: @ 805571C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r0, 0
	mov r10, r0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x18
	str r0, [sp, 0x4]
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r1, 0x1
	ands r1, r0
	ldr r0, =gPlayerParty
	str r0, [sp]
	cmp r1, 0
	beq _0805574C
	ldr r1, =gEnemyParty
	str r1, [sp]
_0805574C:
	movs r2, 0
_0805574E:
	ldr r1, =gBattlePartyID
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	adds r1, r2, 0x1
	str r1, [sp, 0x8]
	ldrh r0, [r0]
	cmp r2, r0
	beq _080557F4
	movs r0, 0x64
	adds r6, r2, 0
	muls r6, r0
	ldr r0, [sp]
	adds r4, r0, r6
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _080557F4
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _080557F4
	movs r5, 0
	ldr r1, =0x0000ffff
	mov r8, r1
	mov r9, r6
	mov r1, r10
	lsls r0, r1, 1
	ldr r1, [sp, 0x4]
	adds r6, r0, r1
_08055798:
	movs r7, 0
	adds r1, r5, 0
	adds r1, 0xD
	ldr r0, [sp]
	add r0, r9
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8052F84
	lsls r0, 24
	adds r1, r5, 0x1
	cmp r0, 0
	bne _080557EE
	ldr r0, =gMovesForbiddenToCopy
	ldrh r2, [r0]
	adds r3, r0, 0
	cmp r2, r8
	beq _080557E2
	cmp r4, r2
	beq _080557D8
	ldr r5, =0x0000ffff
	adds r2, r3, 0
_080557CA:
	adds r2, 0x2
	adds r7, 0x1
	ldrh r0, [r2]
	cmp r0, r5
	beq _080557E2
	cmp r4, r0
	bne _080557CA
_080557D8:
	lsls r0, r7, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r8
	bne _080557EE
_080557E2:
	cmp r4, 0
	beq _080557EE
	strh r4, [r6]
	adds r6, 0x2
	movs r0, 0x1
	add r10, r0
_080557EE:
	adds r5, r1, 0
	cmp r5, 0x3
	ble _08055798
_080557F4:
	ldr r2, [sp, 0x8]
	cmp r2, 0x5
	ble _0805574E
	mov r1, r10
	cmp r1, 0
	beq _0805586C
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	ldr r4, =gRandomMove
	bl Random
	movs r1, 0xFF
	ands r1, r0
	mov r0, r10
	muls r0, r1
	asrs r0, 8
	lsls r0, 1
	ldr r1, [sp, 0x4]
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08055886
	.pool
_0805586C:
	ldr r3, =gBattlescriptCurrInstr
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
_08055886:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkDE_asistattackselect

	thumb_func_start atkDF_setmagiccoat
atkDF_setmagiccoat: @ 805589C
	push {lr}
	ldr r1, =gBankTarget
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, =gSpecialStatuses
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gCurrentMoveTurn
	ldrb r1, [r0]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _080558FC
	ldr r3, =gBattlescriptCurrInstr
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
	b _08055914
	.pool
_080558FC:
	ldr r0, =gProtectStructs
	ldrb r1, [r3]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08055914:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkDF_setmagiccoat

	thumb_func_start atkE0_setstealstatchange
atkE0_setstealstatchange: @ 8055920
	push {lr}
	ldr r2, =gSpecialStatuses
	ldr r3, =gBankAttacker
	ldrb r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gCurrentMoveTurn
	ldrb r1, [r0]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _08055978
	ldr r3, =gBattlescriptCurrInstr
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
	b _0805598E
	.pool
_08055978:
	ldr r0, =gProtectStructs
	ldrb r1, [r3]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0805598E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE0_setstealstatchange

	thumb_func_start atkE1_intimidate_string_loader
atkE1_intimidate_string_loader: @ 805599C
	push {r4-r6,lr}
	ldr r4, =gBattleScripting
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xD8
	ldrb r0, [r0]
	strb r0, [r4, 0x17]
	ldrb r0, [r4, 0x17]
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r2]
	movs r0, 0x9
	strb r0, [r2, 0x1]
	ldr r3, =gBattleMons
	ldrb r1, [r4, 0x17]
	movs r0, 0x58
	muls r0, r1
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r2, 0x2]
	movs r0, 0xFF
	strb r0, [r2, 0x3]
	ldr r2, =gBankTarget
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08055A22
	adds r4, r2, 0
	ldr r6, =gBitTable
_080559E2:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	beq _08055A04
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ands r1, r0
	ldr r2, =gNoOfAllBanks
	cmp r1, 0
	beq _08055A18
_08055A04:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	adds r2, r1, 0
	ldrb r1, [r2]
	cmp r0, r1
	bcc _080559E2
_08055A18:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	ldrb r2, [r2]
	cmp r0, r2
	bcc _08055A64
_08055A22:
	ldr r3, =gBattlescriptCurrInstr
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
	b _08055A6C
	.pool
_08055A64:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08055A6C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE1_intimidate_string_loader

	thumb_func_start atkE2_switchout_abilities
atkE2_switchout_abilities: @ 8055A78
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl GetBattleBank
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r3, =gBattleMons
	ldrb r0, [r4]
	movs r6, 0x58
	adds r1, r0, 0
	muls r1, r6
	adds r0, r1, r3
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1E
	bne _08055AD2
	adds r3, 0x4C
	adds r1, r3
	movs r0, 0
	str r0, [r1]
	ldr r2, =gBitTable
	ldrb r1, [r4]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, r1, r0
	adds r0, 0x58
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0]
	adds r0, r1, 0
	muls r0, r6
	adds r0, r3
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r3, 0x4
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_08055AD2:
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE2_switchout_abilities

	thumb_func_start atkE3_jumpiffainted
atkE3_jumpiffainted: @ 8055AF4
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl GetBattleBank
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldr r2, =gBattleMons
	ldrb r1, [r1]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08055B3C
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
	b _08055B42
	.pool
_08055B3C:
	ldr r0, [r4]
	adds r0, 0x6
	str r0, [r4]
_08055B42:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end atkE3_jumpiffainted

	thumb_func_start atkE4_getsecretpowereffect
atkE4_getsecretpowereffect: @ 8055B48
	push {lr}
	ldr r0, =gUnknown_02022FF0
	ldrb r0, [r0]
	cmp r0, 0x7
	bhi _08055BE4
	lsls r0, 2
	ldr r1, =_08055B64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08055B64:
	.4byte _08055B84
	.4byte _08055B90
	.4byte _08055B9C
	.4byte _08055BA8
	.4byte _08055BB4
	.4byte _08055BC0
	.4byte _08055BCC
	.4byte _08055BD8
_08055B84:
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	b _08055BE8
	.pool
_08055B90:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	b _08055BE8
	.pool
_08055B9C:
	ldr r1, =gBattleCommunication
	movs r0, 0x1B
	b _08055BE8
	.pool
_08055BA8:
	ldr r1, =gBattleCommunication
	movs r0, 0x17
	b _08055BE8
	.pool
_08055BB4:
	ldr r1, =gBattleCommunication
	movs r0, 0x16
	b _08055BE8
	.pool
_08055BC0:
	ldr r1, =gBattleCommunication
	movs r0, 0x18
	b _08055BE8
	.pool
_08055BCC:
	ldr r1, =gBattleCommunication
	movs r0, 0x7
	b _08055BE8
	.pool
_08055BD8:
	ldr r1, =gBattleCommunication
	movs r0, 0x8
	b _08055BE8
	.pool
_08055BE4:
	ldr r1, =gBattleCommunication
	movs r0, 0x5
_08055BE8:
	strb r0, [r1, 0x3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE4_getsecretpowereffect

	thumb_func_start atkE5_pickup
atkE5_pickup: @ 8055C00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	bl InBattlePike
	lsls r0, 24
	cmp r0, 0
	beq _08055C18
	b _08055DD8
_08055C18:
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _08055CC4
	movs r6, 0
	mov r7, sp
	ldr r0, =gBaseStats
	mov r8, r0
_08055C2A:
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	strh r0, [r7]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	cmp r0, 0
	beq _08055C6C
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x17]
	b _08055C76
	.pool
_08055C6C:
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x16]
_08055C76:
	cmp r0, 0x35
	bne _08055CB6
	cmp r5, 0
	beq _08055CB6
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	beq _08055CB6
	ldrh r0, [r7]
	cmp r0, 0
	bne _08055CB6
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08055CB6
	bl CalculateBattlePyramidPickupItemId
	strh r0, [r7]
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
_08055CB6:
	adds r6, 0x1
	cmp r6, 0x5
	ble _08055C2A
	b _08055DD8
	.pool
_08055CC4:
	movs r6, 0
	movs r1, 0x64
	mov r8, r1
	ldr r7, =gPlayerParty
	mov r10, sp
_08055CCE:
	mov r4, r8
	muls r4, r6
	adds r4, r7
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, r10
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	cmp r0, 0
	beq _08055D30
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	ldr r1, =gBaseStats
	adds r0, r1
	ldrb r0, [r0, 0x17]
	b _08055D3C
	.pool
_08055D10:
	mov r0, r8
	muls r0, r6
	adds r0, r7
	adds r2, r1, 0
	adds r2, 0x63
	subs r2, r4
	lsls r2, 1
	ldr r1, =gRarePickupItems
	adds r2, r1
	movs r1, 0xC
	bl SetMonData
	b _08055DD0
	.pool
_08055D30:
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	ldr r1, =gBaseStats
	adds r0, r1
	ldrb r0, [r0, 0x16]
_08055D3C:
	adds r1, r6, 0x1
	mov r9, r1
	cmp r0, 0x35
	bne _08055DD0
	cmp r5, 0
	beq _08055DD0
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	beq _08055DD0
	mov r1, r10
	ldrh r0, [r1]
	cmp r0, 0
	bne _08055DD0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08055DD0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	mov r0, r8
	muls r0, r6
	adds r0, r7
	movs r1, 0x38
	bl GetMonData
	subs r0, 0x1
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x9
	bls _08055D9C
	movs r1, 0x9
_08055D9C:
	movs r2, 0
	b _08055DAE
	.pool
_08055DA4:
	adds r0, r4, 0
	subs r0, 0x62
	cmp r0, 0x1
	bls _08055D10
	adds r2, 0x1
_08055DAE:
	cmp r2, 0x8
	bgt _08055DD0
	ldr r0, =gPickupProbabilities
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r4
	ble _08055DA4
	mov r0, r8
	muls r0, r6
	adds r0, r7
	adds r2, r1, r2
	lsls r2, 1
	ldr r1, =gPickupItems
	adds r2, r1
	movs r1, 0xC
	bl SetMonData
_08055DD0:
	mov r6, r9
	cmp r6, 0x5
	bgt _08055DD8
	b _08055CCE
_08055DD8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE5_pickup

	thumb_func_start atkE6_castform_change_animation
atkE6_castform_change_animation: @ 8055DFC
	push {r4,lr}
	ldr r4, =gActiveBank
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	strb r0, [r4]
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	ldr r3, =gBattleStruct
	cmp r0, 0
	beq _08055E2C
	ldr r0, [r3]
	adds r0, 0x7F
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
_08055E2C:
	ldr r0, [r3]
	adds r0, 0x7F
	ldrb r2, [r0]
	movs r0, 0
	movs r1, 0
	bl EmitBattleAnimation
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE6_castform_change_animation

	thumb_func_start atkE7_castform_data_change
atkE7_castform_data_change: @ 8055E64
	push {r4,lr}
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	bl CastformDataTypeChange
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08055E8E
	ldr r0, =BattleScript_CastformChange
	bl b_push_move_exec
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x7F
	subs r1, r4, 0x1
	strb r1, [r0]
_08055E8E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE7_castform_data_change

	thumb_func_start atkE8_settypebasedhalvers
atkE8_settypebasedhalvers: @ 8055EA4
	push {r4,lr}
	movs r4, 0
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xC9
	bne _08055EF4
	ldr r1, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, 0x80
	lsls r3, 9
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	bne _08055F18
	orrs r1, r3
	str r1, [r2]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	b _08055F1C
	.pool
_08055EF4:
	ldr r1, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, 0x80
	lsls r3, 10
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	bne _08055F18
	orrs r1, r3
	str r1, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	movs r4, 0x1
_08055F18:
	cmp r4, 0
	beq _08055F38
_08055F1C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08055F52
	.pool
_08055F38:
	ldr r3, =gBattlescriptCurrInstr
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
_08055F52:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE8_settypebasedhalvers

	thumb_func_start atkE9_setweatherballtype
atkE9_setweatherballtype: @ 8055F5C
	push {lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08055FFC
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08055FFC
	ldr r2, =gBattleWeather
	ldrb r0, [r2]
	cmp r0, 0
	beq _08055F9A
	ldr r1, =gBattleScripting
	movs r0, 0x2
	strb r0, [r1, 0xE]
_08055F9A:
	ldrh r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08055FB8
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	movs r0, 0x8B
	b _08055FFA
	.pool
_08055FB8:
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _08055FCC
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	movs r0, 0x85
	b _08055FFA
	.pool
_08055FCC:
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08055FE0
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	movs r0, 0x8A
	b _08055FFA
	.pool
_08055FE0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08055FF4
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	movs r0, 0x8F
	b _08055FFA
	.pool
_08055FF4:
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	movs r0, 0x80
_08055FFA:
	strb r0, [r1, 0x13]
_08055FFC:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE9_setweatherballtype

	thumb_func_start atkEA_recycleitem
atkEA_recycleitem: @ 8056014
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r7, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r7]
	ldr r1, =gBattleStruct
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, 0xB8
	ldr r1, [r1]
	adds r6, r1, r0
	ldrh r5, [r6]
	cmp r5, 0
	beq _08056094
	ldr r4, =gBattleMons
	movs r3, 0x58
	adds r0, r2, 0
	muls r0, r3
	adds r0, r4
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	bne _08056094
	ldr r1, =gLastUsedItem
	strh r5, [r1]
	strh r0, [r6]
	ldrb r0, [r7]
	muls r0, r3
	adds r0, r4
	ldrh r1, [r1]
	strh r1, [r0, 0x2E]
	ldrb r0, [r7]
	muls r0, r3
	adds r1, r4, 0
	adds r1, 0x2E
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x2
	bl EmitSetMonData
	ldrb r0, [r7]
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _080560AE
	.pool
_08056094:
	ldr r3, =gBattlescriptCurrInstr
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
_080560AE:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkEA_recycleitem

	thumb_func_start atkEB_settypetoterrain
atkEB_settypetoterrain: @ 80560BC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBattleMons
	mov r8, r0
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	movs r6, 0x58
	muls r0, r6
	mov r1, r8
	adds r3, r0, r1
	movs r0, 0x21
	adds r0, r3
	mov r12, r0
	ldr r5, =sTerrainToType
	ldr r4, =gUnknown_02022FF0
	ldrb r0, [r4]
	adds r0, r5
	ldrb r2, [r0]
	mov r1, r12
	ldrb r0, [r1]
	adds r1, r2, 0
	cmp r0, r1
	beq _08056144
	adds r0, r3, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r1
	beq _08056144
	mov r0, r12
	strb r2, [r0]
	ldrb r0, [r7]
	adds r1, r0, 0
	muls r1, r6
	add r1, r8
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	adds r1, 0x22
	strb r0, [r1]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x3
	strb r0, [r1, 0x1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _0805615E
	.pool
_08056144:
	ldr r3, =gBattlescriptCurrInstr
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
_0805615E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkEB_settypetoterrain

	thumb_func_start atkEC_pursuit_sth
atkEC_pursuit_sth: @ 805616C
	push {r4-r6,lr}
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r6, 0x1
	ands r0, r6
	cmp r0, 0
	beq _0805620C
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r3, [r4]
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0805620C
	ldr r0, =gUnknown_0202421C
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805620C
	ldr r1, =gChosenMovesByBanks
	lsls r0, r3, 1
	adds r0, r1
	ldrh r2, [r0]
	cmp r2, 0xE4
	bne _0805620C
	ldr r0, =gUnknown_0202407A
	adds r0, r3, r0
	movs r1, 0xB
	strb r1, [r0]
	ldr r0, =gCurrentMove
	strh r2, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	ldr r0, =gBattleScripting
	strb r6, [r0, 0x18]
	ldrb r1, [r5]
	adds r0, 0x20
	strb r1, [r0]
	ldrb r0, [r4]
	strb r0, [r5]
	b _08056226
	.pool
_0805620C:
	ldr r3, =gBattlescriptCurrInstr
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
_08056226:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkEC_pursuit_sth

	thumb_func_start atkED_802B4B4
atkED_802B4B4: @ 8056230
	push {r4,lr}
	ldr r1, =gEffectBank
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, =gBankTarget
	lsls r0, 24
	lsrs r0, 24
	adds r4, r1, 0
	ldrb r1, [r2]
	cmp r0, r1
	bne _08056264
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x17]
	strb r0, [r2]
	strb r0, [r3]
	b _0805626A
	.pool
_08056264:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x17]
	strb r0, [r2]
_0805626A:
	ldrb r0, [r4]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkED_802B4B4

	thumb_func_start atkEE_removelightscreenreflect
atkEE_removelightscreenreflect: @ 8056284
	push {r4,lr}
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSideTimers
	lsls r3, r0, 1
	adds r0, r3, r0
	lsls r0, 2
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	bne _080562AC
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	beq _080562E4
_080562AC:
	ldr r2, =gSideAffecting
	adds r2, r3, r2
	ldrh r1, [r2]
	ldr r0, =0x0000fffe
	ands r0, r1
	movs r3, 0
	ldr r1, =0x0000fffd
	ands r0, r1
	strh r0, [r2]
	strb r3, [r4]
	strb r3, [r4, 0x2]
	ldr r1, =gBattleScripting
	movs r0, 0x1
	strb r0, [r1, 0x18]
	strb r0, [r1, 0x19]
	b _080562EA
	.pool
_080562E4:
	ldr r0, =gBattleScripting
	strb r1, [r0, 0x18]
	strb r1, [r0, 0x19]
_080562EA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkEE_removelightscreenreflect

	thumb_func_start atkEF_pokeball_catch_calculation
atkEF_pokeball_catch_calculation: @ 8056300
	push {r4-r6,lr}
	movs r4, 0
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0805630E
	b _08056696
_0805630E:
	ldr r5, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r6, =gBankTarget
	movs r1, 0x1
	eors r0, r1
	strb r0, [r6]
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0805635C
	movs r0, 0
	movs r1, 0x5
	bl dp01_build_cmdbuf_x0D_a
	ldrb r0, [r5]
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBE02
	b _08056694
	.pool
_0805635C:
	movs r0, 0x80
	lsls r0, 2
	ands r1, r0
	cmp r1, 0
	beq _08056384
	movs r0, 0
	movs r1, 0x4
	bl dp01_build_cmdbuf_x0D_a
	ldrb r0, [r5]
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBDCA
	b _08056694
	.pool
_08056384:
	ldr r0, =gLastUsedItem
	ldrh r0, [r0]
	cmp r0, 0x5
	bne _080563B0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x7C
	ldrb r0, [r0]
	lsls r1, r0, 2
	adds r1, r0
	lsls r0, r1, 8
	subs r0, r1
	movs r1, 0x64
	bl __divsi3
	lsls r0, 24
	lsrs r5, r0, 24
	b _080563C8
	.pool
_080563B0:
	ldr r3, =gBaseStats
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r5, [r0, 0x8]
_080563C8:
	ldr r2, =gLastUsedItem
	ldrh r0, [r2]
	cmp r0, 0x5
	bhi _080563D2
	b _080564C8
_080563D2:
	subs r0, 0x6
	cmp r0, 0x6
	bls _080563DA
	b _080564D2
_080563DA:
	lsls r0, 2
	ldr r1, =_080563F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080563F4:
	.4byte _08056410
	.4byte _08056440
	.4byte _08056452
	.4byte _08056480
	.4byte _080564B0
	.4byte _08056472
	.4byte _08056472
_08056410:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x21
	ldrb r1, [r1]
	cmp r1, 0xB
	beq _080564A4
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0xB
	beq _080564A4
	cmp r1, 0x6
	beq _080564A4
	cmp r0, 0x6
	beq _080564A4
	b _08056472
	.pool
_08056440:
	bl sav1_map_get_light_level
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0xA
	cmp r0, 0x5
	bne _080564D2
	movs r4, 0x23
	b _080564D2
_08056452:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2A
	ldrb r1, [r0]
	cmp r1, 0x27
	bhi _08056472
	movs r0, 0x28
	subs r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bhi _080564D2
_08056472:
	movs r4, 0xA
	b _080564D2
	.pool
_08056480:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	movs r4, 0xA
	cmp r0, 0
	beq _080564D2
_080564A4:
	movs r4, 0x1E
	b _080564D2
	.pool
_080564B0:
	ldr r0, =gBattleResults
	ldrb r0, [r0, 0x13]
	adds r0, 0xA
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x28
	bls _080564D2
	movs r4, 0x28
	b _080564D2
	.pool
_080564C8:
	ldr r1, =sBallCatchBonuses
	ldrh r0, [r2]
	subs r0, 0x2
	adds r0, r1
	ldrb r4, [r0]
_080564D2:
	adds r0, r5, 0
	muls r0, r4
	movs r1, 0xA
	bl __divsi3
	ldr r5, =gBattleMons
	ldr r1, =gBankTarget
	ldrb r2, [r1]
	movs r1, 0x58
	adds r4, r2, 0
	muls r4, r1
	adds r3, r4, r5
	ldrh r2, [r3, 0x2C]
	lsls r1, r2, 1
	adds r1, r2
	ldrh r2, [r3, 0x28]
	lsls r2, 1
	subs r2, r1, r2
	muls r0, r2
	bl __divsi3
	adds r6, r0, 0
	adds r5, 0x4C
	adds r4, r5
	ldr r4, [r4]
	movs r0, 0x27
	ands r0, r4
	cmp r0, 0
	beq _0805650E
	lsls r6, 1
_0805650E:
	movs r0, 0xD8
	ands r4, r0
	cmp r4, 0
	beq _08056522
	lsls r0, r6, 4
	subs r0, r6
	movs r1, 0xA
	bl __udivsi3
	adds r6, r0, 0
_08056522:
	ldr r1, =gLastUsedItem
	ldrh r0, [r1]
	cmp r0, 0x5
	beq _08056564
	cmp r0, 0x1
	bne _08056550
	ldr r0, =gBattleResults
	ldrb r1, [r0, 0x5]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0, 0x5]
	b _08056564
	.pool
_08056550:
	ldr r0, =gBattleResults
	ldrh r1, [r1]
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x34
	ldrb r0, [r1]
	cmp r0, 0xFE
	bhi _08056564
	adds r0, 0x1
	strb r0, [r1]
_08056564:
	cmp r6, 0xFE
	bls _080565C8
	movs r0, 0
	movs r1, 0x4
	bl dp01_build_cmdbuf_x0D_a
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD84
	str r0, [r1]
	ldr r1, =gBattlePartyID
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r2, =gLastUsedItem
	movs r1, 0x26
	bl SetMonData
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _08056656
	b _08056680
	.pool
_080565C8:
	movs r0, 0xFF
	lsls r0, 16
	adds r1, r6, 0
	bl __udivsi3
	bl Sqrt
	lsls r0, 16
	lsrs r0, 16
	bl Sqrt
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x000ffff0
	adds r1, r6, 0
	bl __udivsi3
	adds r6, r0, 0
	movs r4, 0
	b _080565FA
	.pool
_080565F4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080565FA:
	cmp r4, 0x3
	bhi _0805660A
	bl Random
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r6
	bcc _080565F4
_0805660A:
	ldr r5, =gLastUsedItem
	ldrh r0, [r5]
	cmp r0, 0x1
	bne _08056614
	movs r4, 0x4
_08056614:
	movs r0, 0
	adds r1, r4, 0
	bl dp01_build_cmdbuf_x0D_a
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl MarkBufferBankForExecution
	cmp r4, 0x4
	bne _0805668C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD84
	str r0, [r1]
	ldr r1, =gBattlePartyID
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	adds r2, r5, 0
	bl SetMonData
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08056680
_08056656:
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	b _08056696
	.pool
_08056680:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _08056696
	.pool
_0805668C:
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBDD4
_08056694:
	str r0, [r1]
_08056696:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkEF_pokeball_catch_calculation

	thumb_func_start atkF0_copy_caught_poke
atkF0_copy_caught_poke: @ 80566A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gBattlePartyID
	mov r9, r0
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	movs r6, 0x1
	eors r0, r6
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	movs r7, 0x64
	muls r0, r7
	ldr r1, =gEnemyParty
	mov r8, r1
	add r0, r8
	bl GiveMonToPlayer
	lsls r0, 24
	cmp r0, 0
	beq _08056792
	bl sub_813B21C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08056734
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
	ldr r4, =gStringVar1
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrb r0, [r5]
	eors r0, r6
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	muls r0, r7
	add r0, r8
	ldr r2, =gStringVar2
	movs r1, 0x2
	bl GetMonData
	b _0805677E
	.pool
_08056734:
	ldr r4, =gStringVar1
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldrb r0, [r5]
	eors r0, r6
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	muls r0, r7
	add r0, r8
	ldr r2, =gStringVar2
	movs r1, 0x2
	bl GetMonData
	ldr r4, =gStringVar3
	bl get_unknown_box_id
	lsls r0, 24
	lsrs r0, 24
	bl sav3_get_box_name
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
_0805677E:
	ldr r0, =0x000008ab
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08056792
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x5]
	adds r0, 0x1
	strb r0, [r1, 0x5]
_08056792:
	ldr r0, =gBattlePartyID
	mov r10, r0
	ldr r1, =gBankAttacker
	mov r9, r1
	ldrb r0, [r1]
	movs r4, 0x1
	eors r0, r4
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	movs r1, 0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r6, =gEnemyParty
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r5, =gBattleResults
	strh r0, [r5, 0x28]
	mov r1, r9
	ldrb r0, [r1]
	eors r0, r4
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	adds r2, r5, 0
	adds r2, 0x2A
	movs r1, 0x2
	bl GetMonData
	mov r1, r9
	ldrb r0, [r1]
	eors r4, r0
	lsls r4, 1
	add r4, r10
	ldrh r0, [r4]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	movs r1, 0x26
	movs r2, 0
	bl GetMonData
	movs r1, 0xF
	ands r0, r1
	lsls r0, 2
	ldrb r2, [r5, 0x5]
	movs r1, 0x3D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkF0_copy_caught_poke

	thumb_func_start atkF1_setpoke_as_caught
atkF1_setpoke_as_caught: @ 8056850
	push {r4,r5,lr}
	ldr r4, =gEnemyParty
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	adds r0, r5, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _080568A8
	ldr r3, =gBattlescriptCurrInstr
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
	b _080568C2
	.pool
_080568A8:
	adds r0, r5, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	adds r2, r4, 0
	bl HandleSetPokedexFlag
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080568C2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkF1_setpoke_as_caught

	thumb_func_start atkF2_display_dex_info
atkF2_display_dex_info: @ 80568CC
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gEnemyParty
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gBattleCommunication
	ldrb r0, [r0]
	cmp r0, 0x5
	bls _080568E8
	b _08056A2C
_080568E8:
	lsls r0, 2
	ldr r1, =_08056900
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08056900:
	.4byte _08056918
	.4byte _0805692A
	.4byte _08056978
	.4byte _080569C8
	.4byte _080569E0
	.4byte _08056A18
_08056918:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _08056A06
_0805692A:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08056938
	b _08056A2C
_08056938:
	bl FreeAllWindowBuffers
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	ldr r3, =gBattleMons
	ldr r1, =gBankTarget
	ldrb r2, [r1]
	movs r1, 0x58
	muls r2, r1
	adds r1, r3, 0
	adds r1, 0x54
	adds r1, r2, r1
	ldr r1, [r1]
	adds r3, 0x48
	adds r2, r3
	ldr r2, [r2]
	bl sub_80BFDF4
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x1]
	b _08056A08
	.pool
_08056978:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08056A2C
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =BattleMainCB2
	cmp r1, r0
	bne _08056A2C
	ldr r2, =gTasks
	ldr r4, =gBattleCommunication
	ldrb r1, [r4, 0x1]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08056A2C
	ldr r0, =vblank_cb_08078BB4
	bl SetVBlankCallback
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _08056A2C
	.pool
_080569C8:
	bl c2_berry_program_update_menu
	bl sub_8035AA4
	ldr r1, =gUnknown_02022E20
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	b _08056A06
	.pool
_080569E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08056A2C
	ldr r0, =0x0000ffff
	str r1, [sp]
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0
	bl ShowBg
	movs r0, 0x3
	bl ShowBg
_08056A06:
	ldr r1, =gBattleCommunication
_08056A08:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08056A2C
	.pool
_08056A18:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08056A2C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08056A2C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkF2_display_dex_info

	thumb_func_start sub_8056A3C
sub_8056A3C: @ 8056A3C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	ldr r4, [sp, 0x40]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x10]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	movs r1, 0
	add r0, sp, 0xC
	strh r1, [r0]
	ldr r6, [sp, 0x10]
	cmp r6, r3
	ble _08056A76
	b _08056B62
_08056A76:
	mov r4, r8
	adds r0, r6, 0x1
	str r0, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	cmp r4, r2
	bgt _08056B58
	add r5, sp, 0xC
	lsls r7, r6, 24
	mov r9, r7
_08056A88:
	ldr r0, [sp, 0x10]
	cmp r6, r0
	bne _08056AB4
	cmp r4, r8
	bne _08056A9C
	ldr r0, =0x00001022
	b _08056AFE
	.pool
_08056A9C:
	ldr r2, [sp, 0x1C]
	cmp r4, r2
	bne _08056AAC
	ldr r0, =0x00001024
	b _08056AFE
	.pool
_08056AAC:
	ldr r0, =0x00001023
	b _08056AFE
	.pool
_08056AB4:
	ldr r7, [sp, 0x14]
	cmp r6, r7
	bne _08056AE0
	cmp r4, r8
	bne _08056AC8
	ldr r0, =0x00001028
	b _08056AFE
	.pool
_08056AC8:
	ldr r0, [sp, 0x1C]
	cmp r4, r0
	bne _08056AD8
	ldr r0, =0x0000102a
	b _08056AFE
	.pool
_08056AD8:
	ldr r0, =0x00001029
	b _08056AFE
	.pool
_08056AE0:
	cmp r4, r8
	bne _08056AEC
	ldr r0, =0x00001025
	b _08056AFE
	.pool
_08056AEC:
	ldr r2, [sp, 0x1C]
	cmp r4, r2
	bne _08056AFC
	ldr r0, =0x00001027
	b _08056AFE
	.pool
_08056AFC:
	ldr r0, =0x00001026
_08056AFE:
	strh r0, [r5]
	movs r1, 0x1
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	beq _08056B0E
	movs r0, 0
	strh r0, [r5]
_08056B0E:
	movs r0, 0x80
	mov r7, r10
	ands r0, r7
	cmp r0, 0
	beq _08056B38
	lsls r2, r4, 24
	lsrs r2, 24
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0x1
	add r1, sp, 0xC
	mov r7, r9
	lsrs r3, r7, 24
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _08056B50
	.pool
_08056B38:
	lsls r2, r4, 24
	lsrs r2, 24
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	mov r7, r9
	lsrs r3, r7, 24
	bl CopyToBgTilemapBufferRect_ChangePalette
_08056B50:
	adds r4, 0x1
	ldr r0, [sp, 0x1C]
	cmp r4, r0
	ble _08056A88
_08056B58:
	ldr r6, [sp, 0x18]
	ldr r2, [sp, 0x14]
	cmp r6, r2
	bgt _08056B62
	b _08056A76
_08056B62:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8056A3C

	thumb_func_start BattleCreateCursorAt
BattleCreateCursorAt: @ 8056B74
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	add r0, sp, 0xC
	movs r2, 0x1
	strh r2, [r0]
	movs r1, 0x2
	strh r1, [r0, 0x2]
	lsls r3, 25
	movs r0, 0x90
	lsls r0, 20
	adds r3, r0
	lsrs r3, 24
	str r2, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	movs r2, 0x19
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	thumb_func_end BattleCreateCursorAt

	thumb_func_start BattleDestroyCursorAt
BattleDestroyCursorAt: @ 8056BAC
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	add r0, sp, 0xC
	ldr r1, =0x00001016
	strh r1, [r0]
	strh r1, [r0, 0x2]
	lsls r3, 25
	movs r0, 0x90
	lsls r0, 20
	adds r3, r0
	lsrs r3, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	movs r2, 0x19
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end BattleDestroyCursorAt

	thumb_func_start atkF3_nickname_caught_poke
atkF3_nickname_caught_poke: @ 8056BEC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gBattleCommunication
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x4
	bls _08056C04
	b _08056E62
_08056C04:
	lsls r0, r1, 2
	ldr r1, =_08056C18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08056C18:
	.4byte _08056C2C
	.4byte _08056C60
	.4byte _08056CFC
	.4byte _08056DD4
	.4byte _08056E2C
_08056C2C:
	movs r4, 0
	str r4, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gText_BattleYesNoChoice
	movs r1, 0xC
	bl sub_814F9EC
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	strb r4, [r1, 0x1]
	movs r0, 0
	bl BattleCreateCursorAt
	b _08056E62
	.pool
_08056C60:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08056C86
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08056C86
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl BattleDestroyCursorAt
	movs r0, 0
	strb r0, [r4, 0x1]
	bl BattleCreateCursorAt
_08056C86:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08056CAE
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _08056CAE
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl BattleDestroyCursorAt
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl BattleCreateCursorAt
_08056CAE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08056CE0
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _08056CF2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r0, 0x3
	bl BeginFastPaletteFade
	b _08056E62
	.pool
_08056CE0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08056CEA
	b _08056E62
_08056CEA:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gBattleCommunication
_08056CF2:
	movs r0, 0x4
	strb r0, [r1]
	b _08056E62
	.pool
_08056CFC:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08056D0A
	b _08056E62
_08056D0A:
	ldr r7, =gBattlePartyID
	ldr r0, =gBankAttacker
	mov r10, r0
	ldrb r0, [r0]
	movs r4, 0x1
	eors r0, r4
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r1, 0x64
	mov r9, r1
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	ldr r1, =gEnemyParty
	mov r8, r1
	add r0, r8
	ldr r1, =gBattleStruct
	ldr r2, [r1]
	adds r2, 0x6D
	movs r1, 0x2
	bl GetMonData
	bl FreeAllWindowBuffers
	mov r2, r10
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	add r0, r8
	movs r1, 0xB
	bl GetMonData
	adds r6, r0, 0
	lsls r6, 16
	lsrs r6, 16
	mov r2, r10
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	add r0, r8
	bl GetMonGender
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r2, r10
	ldrb r0, [r2]
	eors r4, r0
	lsls r4, 1
	adds r4, r7
	ldrh r0, [r4]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	add r0, r8
	movs r1, 0
	movs r2, 0
	bl GetMonData
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0x6D
	str r0, [sp]
	ldr r0, =BattleMainCB2
	str r0, [sp, 0x4]
	movs r0, 0x2
	adds r2, r6, 0
	adds r3, r5, 0
	bl DoNamingScreen
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08056E62
	.pool
_08056DD4:
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =BattleMainCB2
	cmp r1, r0
	bne _08056E62
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08056E62
	ldr r2, =gBattlePartyID
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r1, =gBattleStruct
	ldr r2, [r1]
	adds r2, 0x6D
	movs r1, 0x2
	bl SetMonData
	b _08056E48
	.pool
_08056E2C:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08056E48
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08056E62
	.pool
_08056E48:
	ldr r3, =gBattlescriptCurrInstr
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
_08056E62:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkF3_nickname_caught_poke

	thumb_func_start atkF4_802BEF0
atkF4_802BEF0: @ 8056E78
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldr r0, =gBattleMoveDamage
	ldr r2, [r0]
	ldrh r0, [r1, 0x28]
	subs r0, r2
	strh r0, [r1, 0x28]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atkF4_802BEF0

	thumb_func_start atkF5_removeattackerstatus1
atkF5_removeattackerstatus1: @ 8056EA8
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atkF5_removeattackerstatus1

	thumb_func_start atkF6_802BF48
atkF6_802BF48: @ 8056ED0
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end atkF6_802BF48

	thumb_func_start atkF7_802BF54
atkF7_802BF54: @ 8056EDC
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	strb r0, [r1]
	ldr r1, =gCurrentMoveTurn
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end atkF7_802BF54

	thumb_func_start sub_8056EF8
sub_8056EF8: @ 8056EF8
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl GetBankByIdentity
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x09_9_9_9
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8056EF8

    
	.align 2, 0 @ Don't pad with nop.
