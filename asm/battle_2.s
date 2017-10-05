	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sub_803EE48
sub_803EE48: @ 803EE48
	push {r4-r6,lr}
	ldr r4, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r5, =gCurrentTurnActionNumber
	ldrb r0, [r5]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0803EF0C
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	strb r1, [r5]
	ldr r2, =gActiveBank
	movs r0, 0
	strb r0, [r2]
	lsls r1, 24
	cmp r1, 0
	beq _0803EEE0
	adds r4, r2, 0
	ldr r6, =gActionForBanks
	ldr r5, =gBattleOutcome
_0803EE7C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803EEBC
	ldrb r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0803EECE
	ldrb r0, [r5]
	movs r1, 0x2
	b _0803EECA
	.pool
_0803EEBC:
	ldrb r0, [r4]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0803EECE
	ldrb r0, [r5]
	movs r1, 0x1
_0803EECA:
	orrs r0, r1
	strb r0, [r5]
_0803EECE:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0803EE7C
_0803EEE0:
	ldr r2, =gBattleOutcome
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r0, =0x00000ca9
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x8
	orrs r0, r2
	b _0803EF96
	.pool
_0803EF0C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0803EF4C
	ldrb r0, [r4]
	bl TryRunFromBattle
	lsls r0, 24
	cmp r0, 0
	bne _0803EF98
	ldrb r0, [r4]
	bl ClearFuryCutterDestinyBondGrudge
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAB02
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	b _0803EF96
	.pool
_0803EF4C:
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0400e000
	ands r0, r1
	cmp r0, 0
	beq _0803EF8C
	ldr r1, =gBattleCommunication
	movs r0, 0x4
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAB02
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	b _0803EF96
	.pool
_0803EF8C:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r1, =gBattleOutcome
	movs r0, 0x6
_0803EF96:
	strb r0, [r1]
_0803EF98:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803EE48

	thumb_func_start sub_803EFA8
sub_803EFA8: @ 803EFA8
	ldr r2, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r0, =gCurrentTurnActionNumber
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_803EFA8

	thumb_func_start bs5_8016AC0
bs5_8016AC0: @ 803EFF0
	ldr r2, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r0, =gCurrentTurnActionNumber
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r1, =gNumSafariBalls
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	ldr r1, =gLastUsedItem
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gBattlescriptsForBallThrow
	ldr r0, [r0, 0x14]
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end bs5_8016AC0

	thumb_func_start sub_803F050
sub_803F050: @ 803F050
	push {r4-r6,lr}
	ldr r3, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r0, =gCurrentTurnActionNumber
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r6, =gBattleCommunication
	ldr r2, =gBattleBufferB
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x1
	strb r0, [r6, 0x5]
	ldr r1, =gLastUsedItem
	ldrb r0, [r3]
	lsls r0, 9
	adds r2, 0x2
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x1F]
	cmp r0, 0xFE
	bhi _0803F096
	adds r0, 0x1
	strb r0, [r1, 0x1F]
_0803F096:
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	adds r1, r0, 0
	adds r1, 0x7A
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _0803F0A8
	adds r0, 0x1
	strb r0, [r1]
_0803F0A8:
	ldr r0, [r2]
	adds r3, r0, 0
	adds r3, 0x7B
	ldrb r5, [r3]
	adds r4, r5, 0
	cmp r4, 0x1
	bls _0803F100
	ldr r2, =gUnknown_0831BCE0
	adds r0, 0x7A
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	ldrb r6, [r6, 0x5]
	adds r0, r6
	adds r0, r2
	ldrb r0, [r0]
	cmp r4, r0
	bcs _0803F0FC
	movs r0, 0x1
	b _0803F0FE
	.pool
_0803F0FC:
	subs r0, r5, r0
_0803F0FE:
	strb r0, [r3]
_0803F100:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0, 0x8]
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	strb r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F050

	thumb_func_start sub_803F120
sub_803F120: @ 803F120
	push {r4,lr}
	ldr r2, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r0, =gCurrentTurnActionNumber
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gBattle_BG0_X
	movs r4, 0
	strh r4, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r4, [r0]
	ldr r3, =gBattleStruct
	ldr r0, [r3]
	adds r2, r0, 0
	adds r2, 0x7C
	ldr r1, =gUnknown_0831BCEF
	adds r0, 0x79
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x7C
	ldrb r0, [r1]
	cmp r0, 0x14
	bls _0803F162
	movs r0, 0x14
	strb r0, [r1]
_0803F162:
	ldr r0, [r3]
	adds r2, r0, 0
	adds r2, 0x7B
	ldr r1, =gUnknown_0831BCF3
	adds r0, 0x79
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x7B
	ldrb r0, [r1]
	cmp r0, 0x14
	bls _0803F188
	movs r0, 0x14
	strb r0, [r1]
_0803F188:
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0x79
	ldrb r0, [r1]
	cmp r0, 0x2
	bhi _0803F1C4
	adds r0, 0x1
	strb r0, [r1]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	b _0803F1CA
	.pool
_0803F1C4:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
_0803F1CA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0, 0x4]
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F120

	thumb_func_start bs8_exit_by_flight
bs8_exit_by_flight: @ 803F1F0
	push {r4,lr}
	ldr r2, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r4, =gCurrentTurnActionNumber
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0x11
	bl PlaySE
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, =gBattleOutcome
	movs r0, 0x4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bs8_exit_by_flight

	thumb_func_start bs9_8016C9C
bs9_8016C9C: @ 803F22C
	ldr r3, =gBankAttacker
	ldr r1, =gBanksByTurnOrder
	ldr r0, =gCurrentTurnActionNumber
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	strb r2, [r3]
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattle_BG0_Y
	strh r1, [r0]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	strb r2, [r1, 0x2]
	ldr r2, =gBattlePartyID
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DBD58
	ldr r0, [r0, 0xC]
	str r0, [r1]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xA
	strb r0, [r1]
	ldr r1, =gActionsByTurnOrder
	movs r0, 0xC
	strb r0, [r1, 0x1]
	bx lr
	.pool
	thumb_func_end bs9_8016C9C

	thumb_func_start bsB_exit_by_move
bsB_exit_by_move: @ 803F2A4
	push {lr}
	bl sub_8041728
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0803F2C0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4D
	strb r1, [r0]
	ldr r1, =gCurrentActionFuncId
	movs r0, 0xC
	strb r0, [r1]
_0803F2C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bsB_exit_by_move

	thumb_func_start bsD_proceed
bsD_proceed: @ 803F2CC
	ldr r1, =gCurrentTurnActionNumber
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r3, =gCurrentActionFuncId
	ldr r2, =gActionsByTurnOrder
	ldrb r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xf1e892af
	ands r0, r1
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end bsD_proceed

	thumb_func_start bsC_8016D70
bsC_8016D70: @ 803F300
	push {r4-r6,lr}
	ldr r1, =gBanksByTurnOrder
	ldr r2, =gCurrentTurnActionNumber
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	ldr r6, =gBattleStruct
	ldr r1, [r6]
	adds r0, r1
	adds r0, 0x5C
	movs r1, 0x6
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldr r3, =gCurrentActionFuncId
	ldr r1, =gActionsByTurnOrder
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	bl SpecialStatusesClear
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xf1e892af
	ands r0, r1
	str r0, [r2]
	ldr r0, =gCurrentMove
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattleMoveDamage
	movs r4, 0
	str r4, [r0]
	ldr r0, =gBattleMoveFlags
	strb r1, [r0]
	ldr r5, =gBattleScripting
	strb r1, [r5, 0x18]
	strb r1, [r5, 0x19]
	ldr r2, =gUnknown_02024250
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	strh r4, [r0]
	ldr r2, =gUnknown_02024258
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	strh r4, [r0]
	ldr r0, [r6]
	strb r1, [r0, 0x13]
	ldr r0, =gDynamicBasePower
	strh r4, [r0]
	strb r1, [r5, 0x14]
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x3]
	strb r1, [r0, 0x4]
	strb r1, [r5, 0x16]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0x20
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bsC_8016D70

	thumb_func_start GetBattleBank
GetBattleBank: @ 803F3CC
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0
	cmp r1, 0xE
	bhi _0803F47A
	lsls r0, r1, 2
	ldr r1, =_0803F3E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0803F3E8:
	.4byte _0803F424
	.4byte _0803F430
	.4byte _0803F43C
	.4byte _0803F458
	.4byte _0803F464
	.4byte _0803F458
	.4byte _0803F464
	.4byte _0803F448
	.4byte _0803F464
	.4byte _0803F464
	.4byte _0803F44C
	.4byte _0803F464
	.4byte _0803F468
	.4byte _0803F46C
	.4byte _0803F470
_0803F424:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F430:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F43C:
	ldr r0, =gEffectBank
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F448:
	movs r0, 0
	b _0803F47A
_0803F44C:
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x17]
	b _0803F47A
	.pool
_0803F458:
	ldr r0, =gBank1
	ldrb r0, [r0]
	b _0803F47A
	.pool
_0803F464:
	movs r0, 0
	b _0803F472
_0803F468:
	movs r0, 0x1
	b _0803F472
_0803F46C:
	movs r0, 0x2
	b _0803F472
_0803F470:
	movs r0, 0x3
_0803F472:
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r0, 24
_0803F47A:
	pop {r1}
	bx r1
	thumb_func_end GetBattleBank

	thumb_func_start PressurePPLose
PressurePPLose: @ 803F480
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 16
	lsrs r2, 16
	ldr r1, =gBattleMons
	movs r4, 0x58
	muls r0, r4
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	mov r12, r1
	cmp r0, 0x2E
	bne _0803F532
	movs r3, 0
	adds r0, r5, 0
	muls r0, r4
	adds r1, 0xC
	adds r1, r0, r1
	b _0803F4BC
	.pool
_0803F4B4:
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	bgt _0803F4C2
_0803F4BC:
	ldrh r0, [r1]
	cmp r0, r2
	bne _0803F4B4
_0803F4C2:
	cmp r3, 0x4
	beq _0803F532
	movs r7, 0x58
	adds r2, r5, 0
	muls r2, r7
	adds r0, r3, r2
	mov r6, r12
	adds r6, 0x24
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803F4DE
	subs r0, 0x1
	strb r0, [r1]
_0803F4DE:
	mov r0, r12
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0803F532
	ldr r1, =gDisableStructs
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803F532
	ldr r4, =gActiveBank
	strb r5, [r4]
	adds r1, r3, 0
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r4]
	muls r0, r7
	adds r0, r6
	adds r0, r3
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_0803F532:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PressurePPLose

	thumb_func_start PressurePPLoseOnUsingImprision
PressurePPLoseOnUsingImprision: @ 803F548
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x4
	mov r8, r0
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bge _0803F5F0
	ldr r1, =gBattleMons
	movs r0, 0x58
	adds r7, r5, 0
	muls r7, r0
	adds r1, 0xC
	mov r10, r1
_0803F57E:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	adds r6, r4, 0x1
	cmp r9, r0
	beq _0803F5E6
	ldr r0, =gBattleMons
	movs r3, 0x58
	adds r1, r4, 0
	muls r1, r3
	adds r1, r0
	adds r1, 0x20
	ldrb r1, [r1]
	adds r4, r0, 0
	cmp r1, 0x2E
	bne _0803F5E6
	movs r2, 0
	adds r0, r5, 0
	muls r0, r3
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x8F
	lsls r1, 1
	cmp r0, r1
	beq _0803F5CE
	adds r3, r1, 0
	mov r0, r10
	adds r1, r7, r0
_0803F5C0:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0803F5CE
	ldrh r0, [r1]
	cmp r0, r3
	bne _0803F5C0
_0803F5CE:
	cmp r2, 0x4
	beq _0803F5E6
	mov r8, r2
	adds r1, r2, r7
	adds r0, r4, 0
	adds r0, 0x24
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803F5E6
	subs r0, 0x1
	strb r0, [r1]
_0803F5E6:
	adds r4, r6, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803F57E
_0803F5F0:
	mov r1, r8
	cmp r1, 0x4
	beq _0803F658
	ldr r6, =gBattleMons
	movs r3, 0x58
	adds r0, r5, 0
	muls r0, r3
	adds r1, r6, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0803F658
	ldr r1, =gDisableStructs
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	mov r4, r8
	lsls r0, r4, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803F658
	ldr r4, =gActiveBank
	strb r5, [r4]
	mov r1, r8
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r4]
	muls r0, r3
	adds r2, r6, 0
	adds r2, 0x24
	adds r0, r2
	add r0, r8
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_0803F658:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PressurePPLoseOnUsingImprision

	thumb_func_start PressurePPLoseOnUsingPerishSong
PressurePPLoseOnUsingPerishSong: @ 803F67C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r3, r0, 24
	movs r6, 0x4
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	mov r8, r0
	ldrb r0, [r0]
	cmp r1, r0
	bge _0803F6FE
	ldr r7, =gBattleMons
	movs r2, 0x58
	mov r12, r2
	mov r5, r12
	muls r5, r3
	adds r0, r7, 0
	adds r0, 0xC
	adds r2, r5, r0
	mov r10, r2
	mov r9, r5
_0803F6AE:
	mov r0, r12
	muls r0, r1
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	adds r4, r1, 0x1
	cmp r0, 0x2E
	bne _0803F6F4
	cmp r1, r3
	beq _0803F6F4
	movs r2, 0
	mov r1, r10
	ldrh r0, [r1]
	cmp r0, 0xC3
	beq _0803F6DE
	ldr r1, =gBattleMons + 0xC
	add r1, r9
_0803F6D0:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0803F6DE
	ldrh r0, [r1]
	cmp r0, 0xC3
	bne _0803F6D0
_0803F6DE:
	cmp r2, 0x4
	beq _0803F6F4
	adds r6, r2, 0
	adds r0, r6, r5
	ldr r2, =gBattleMons + 0x24
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _0803F6F4
	subs r0, 0x1
	strb r0, [r1]
_0803F6F4:
	adds r1, r4, 0
	mov r0, r8
	ldrb r0, [r0]
	cmp r1, r0
	blt _0803F6AE
_0803F6FE:
	cmp r6, 0x4
	beq _0803F762
	ldr r7, =gBattleMons
	movs r5, 0x58
	adds r0, r3, 0
	muls r0, r5
	adds r1, r7, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0803F762
	ldr r1, =gDisableStructs
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r6, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0803F762
	ldr r4, =gActiveBank
	strb r3, [r4]
	adds r1, r6, 0
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r4]
	muls r0, r5
	adds r2, r7, 0
	adds r2, 0x24
	adds r0, r2
	adds r0, r6
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl EmitSetMonData
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_0803F762:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PressurePPLoseOnUsingPerishSong

	thumb_func_start sub_803F790
sub_803F790: @ 803F790
	push {r4,r5,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803F7D0
	movs r2, 0
	ldr r4, =gNoOfAllBanks
	ldrb r0, [r4]
	cmp r2, r0
	bge _0803F7EE
	ldr r3, =gBattleExecBuffer
	ldr r5, =gBitTable
_0803F7AC:
	ldm r5!, {r1}
	lsls r1, 28
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r2, 0x1
	ldrb r0, [r4]
	cmp r2, r0
	blt _0803F7AC
	b _0803F7EE
	.pool
_0803F7D0:
	movs r2, 0
	ldr r4, =gNoOfAllBanks
	ldrb r0, [r4]
	cmp r2, r0
	bge _0803F7EE
	ldr r3, =gBattleExecBuffer
	ldr r5, =gBitTable
_0803F7DE:
	ldr r0, [r3]
	ldm r5!, {r1}
	orrs r0, r1
	str r0, [r3]
	adds r2, 0x1
	ldrb r0, [r4]
	cmp r2, r0
	blt _0803F7DE
_0803F7EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F790

	thumb_func_start MarkBufferBankForExecution
MarkBufferBankForExecution: @ 803F800
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0803F834
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _0803F844
	.pool
_0803F834:
	ldr r2, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r2]
_0803F844:
	pop {r0}
	bx r0
	.pool
	thumb_func_end MarkBufferBankForExecution

	thumb_func_start sub_803F850
sub_803F850: @ 803F850
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0
	ldr r5, =gBattleExecBuffer
	ldr r1, =gBitTable
	lsls r0, r7, 2
	adds r6, r0, r1
	b _0803F87A
	.pool
_0803F86C:
	lsls r0, r4, 2
	ldr r1, [r6]
	lsls r1, r0
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r4, 0x1
_0803F87A:
	bl sub_8009FCC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	blt _0803F86C
	ldr r2, =gBattleExecBuffer
	movs r1, 0x80
	lsls r1, 21
	lsls r1, r7
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F850

	thumb_func_start CancelMultiTurnMoves
CancelMultiTurnMoves: @ 803F8A0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gBattleMons
	movs r2, 0x58
	adds r3, r0, 0
	muls r3, r2
	adds r1, 0x50
	adds r3, r1
	ldr r1, [r3]
	ldr r2, =0xffffefff
	ands r1, r2
	ldr r2, =0xfffff3ff
	ands r1, r2
	movs r2, 0x71
	negs r2, r2
	ands r1, r2
	ldr r2, =0xfffffcff
	ands r1, r2
	str r1, [r3]
	ldr r1, =gStatuses3
	lsls r2, r0, 2
	adds r2, r1
	ldr r1, [r2]
	ldr r3, =0xfffbff3f
	ands r1, r3
	str r1, [r2]
	ldr r2, =gDisableStructs
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x11]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x11]
	movs r0, 0
	strb r0, [r1, 0x10]
	bx lr
	.pool
	thumb_func_end CancelMultiTurnMoves

	thumb_func_start HasMoveFailed
HasMoveFailed: @ 803F90C
	push {lr}
	lsls r0, 24
	ldr r1, =gProtectStructs
	lsrs r0, 20
	adds r1, r0, r1
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	bne _0803F952
	ldrb r2, [r1, 0x1]
	lsls r0, r2, 30
	cmp r0, 0
	blt _0803F952
	lsls r0, r2, 26
	cmp r0, 0
	blt _0803F952
	lsls r0, r2, 25
	cmp r0, 0
	blt _0803F952
	lsrs r0, r2, 7
	cmp r0, 0
	bne _0803F952
	ldrb r1, [r1, 0x2]
	lsls r0, r1, 31
	cmp r0, 0
	bne _0803F952
	lsls r0, r1, 30
	cmp r0, 0
	blt _0803F952
	lsls r0, r1, 29
	cmp r0, 0
	blt _0803F952
	lsls r0, r2, 31
	cmp r0, 0
	beq _0803F95C
_0803F952:
	movs r0, 0x1
	b _0803F95E
	.pool
_0803F95C:
	movs r0, 0
_0803F95E:
	pop {r1}
	bx r1
	thumb_func_end HasMoveFailed

	thumb_func_start PrepareStringBattle
PrepareStringBattle: @ 803F964
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	ldr r4, =gActiveBank
	strb r1, [r4]
	movs r0, 0
	adds r1, r2, 0
	bl dp01_build_cmdbuf_x10_TODO
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PrepareStringBattle

	thumb_func_start ResetSentPokesToOpponentValue
ResetSentPokesToOpponentValue: @ 803F988
	push {r4-r6,lr}
	movs r3, 0
	ldr r0, =gSentPokesToOpponent
	strb r3, [r0]
	strb r3, [r0, 0x1]
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	adds r6, r0, 0
	cmp r1, r2
	bge _0803F9B6
	ldr r5, =gBitTable
	adds r4, r2, 0
	ldr r2, =gBattlePartyID
_0803F9A4:
	ldrh r0, [r2]
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	orrs r3, r0
	adds r2, 0x4
	adds r1, 0x2
	cmp r1, r4
	blt _0803F9A4
_0803F9B6:
	movs r1, 0x1
	adds r2, r6, 0
	ldrb r0, [r2]
	cmp r1, r0
	bge _0803F9D6
	ldr r5, =gSentPokesToOpponent
	movs r4, 0x2
_0803F9C4:
	adds r0, r1, 0
	ands r0, r4
	asrs r0, 1
	adds r0, r5
	strb r3, [r0]
	adds r1, 0x2
	ldrb r0, [r2]
	cmp r1, r0
	blt _0803F9C4
_0803F9D6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetSentPokesToOpponentValue

	thumb_func_start sub_803F9EC
sub_803F9EC: @ 803F9EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803FA50
	movs r0, 0x2
	ands r0, r5
	lsls r0, 24
	lsrs r0, 25
	mov r12, r0
	ldr r1, =gSentPokesToOpponent
	adds r0, r1
	strb r4, [r0]
	adds r5, r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	mov r8, r1
	cmp r4, r2
	bge _0803FA4A
	ldr r0, =gAbsentBankFlags
	ldrb r7, [r0]
	ldr r1, =gBitTable
	adds r6, r2, 0
	ldr r3, =gBattlePartyID
	adds r2, r1, 0
_0803FA2E:
	ldr r0, [r2]
	ands r0, r7
	cmp r0, 0
	bne _0803FA40
	ldrh r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	orrs r4, r0
_0803FA40:
	adds r3, 0x4
	adds r2, 0x8
	adds r5, 0x2
	cmp r5, r6
	blt _0803FA2E
_0803FA4A:
	mov r0, r12
	add r0, r8
	strb r4, [r0]
_0803FA50:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803F9EC

	thumb_func_start sub_803FA70
sub_803FA70: @ 803FA70
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0803FA8C
	adds r0, r4, 0
	bl sub_803F9EC
	b _0803FAC2
_0803FA8C:
	movs r3, 0x1
	ldr r5, =gNoOfAllBanks
	ldrb r0, [r5]
	cmp r3, r0
	bge _0803FAC2
	ldr r0, =gSentPokesToOpponent
	mov r12, r0
	movs r7, 0x2
	ldr r6, =gBitTable
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r4, r0, r1
_0803FAA4:
	adds r2, r3, 0
	ands r2, r7
	asrs r2, 1
	add r2, r12
	ldrh r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r3, 0x1
	ldrb r0, [r5]
	cmp r3, r0
	blt _0803FAA4
_0803FAC2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_803FA70
    
    .align 2, 0 @ Don't pad with nop.
    